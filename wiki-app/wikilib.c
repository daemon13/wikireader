/*
 * Copyright (c) 2009 Openmoko Inc.
 *
 * Authors   Daniel Mack <daniel@caiaq.de>
 *           Holger Hans Peter Freyther <zecke@openmoko.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <inttypes.h>
#include <wikilib.h>
#include <guilib.h>
#include <glyph.h>
#include <history.h>
#include <wl-keyboard.h>
#include <input.h>
#include <msg.h>
#include <file-io.h>
#include <search.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <perf.h>
#include <profile.h>
#include <malloc-simple.h>
#include <bmf.h>
#include <lcd_buf_draw.h>
#include <lcd.h>
#include <tick.h>
#include "delay.h"
#include "search_fnd.h"
#include "restricted.h"
#include "wiki_info.h"
#include "utf8.h"
#ifndef INCLUDED_FROM_KERNEL
#include "time.h"
#else
#include <samo.h>
#include <temperature.h>
#endif
//#include <t_services.h>
//#include <kernel.h>
//#include <wl-time.h>

#define DBG_WL 0
#define LCD_Y_CALIBRATION_ADJUSTMENT (-1)

struct pos {
	unsigned int x;
	unsigned int y;
};

int last_display_mode = 0;
int display_mode = DISPLAY_MODE_INDEX;
static struct keyboard_key * pre_key= NULL;
static unsigned int article_touch_down_handled = 0;
unsigned int touch_down_on_keyboard = 0;
static unsigned int touch_down_on_list = 0;
static struct pos article_touch_down_pos;
static unsigned int touch_y_last_unreleased = 0;
static unsigned int touch_y_last = 0;
static unsigned long start_move_time = 0;
static unsigned long last_unreleased_time = 0;
int    last_index_y_pos;
int    enter_touch_y_pos = -1;
int    last_history_y_pos;
char * articleBuffer = 0;
int articleLength = 0;
unsigned char * membuffer = 0;
int membuffersize = 0;
int curBufferPos  = 0;
unsigned char *article_buf_pointer;
//int is_rendering = 0;
int last_selection = 0;
unsigned long start_search_time, last_delete_time;
int last_article_move_time,touch_y_last_article;
int article_touch_count = 0;
int touch_history = 0;
extern unsigned long time_scroll_article_last;
extern unsigned long time_scroll_article_start;
extern long saved_idx_article;
extern long saved_prev_idx_article;
bool random_press = false;
extern int stop_render_article;
int time_random_last = 0;
extern bool search_string_changed;
extern unsigned int time_search_last;
extern int b_show_scroll_bar;
extern int display_first_page;
bool press_delete_button = false;
extern bool search_string_changed_remove;
int history_touch_pos_y_last;
int touch_search = 0,search_touch_pos_y_last=0;
bool article_moved = false;
int  article_scroll_pixel = INITIAL_ARTICLE_SCROLL_THRESHOLD;
int article_moved_pixels = 0;
extern int link_to_be_inverted;
extern int link_currently_inverted;
long finger_move_speed = 0;
#ifdef OVER_SCROLL_ENABLED
extern int over_scroll_lines;
#endif
int finger_touched = 0;

void repaint_search(void)
{
	guilib_fb_lock();
	search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_KEEP_REFRESH);
	keyboard_paint();
	guilib_fb_unlock();
}

/* this is only called for the index page */
static void toggle_soft_keyboard(void)
{
	//guilib_fb_lock();
	int mode = keyboard_get_mode();

	/* Set the keyboard mode to what we want to change to. */
	if (mode == KEYBOARD_NONE || search_result_count()==0) {
		keyboard_set_mode(wiki_default_keyboard());
		if (mode == KEYBOARD_NONE)
			restore_search_list_page();
		keyboard_paint();
	} else {
		keyboard_set_mode(KEYBOARD_NONE);
		search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_KEEP_RESULT);
	}

	//guilib_fb_unlock();
}

static void print_intro()
{
	//keyboard_set_mode(KEYBOARD_CHAR);

	guilib_fb_lock();
	guilib_clear();

	//membuffer = malloc_simple(1024*1024,MEM_TAG_ARTICLE_F1);
	keyboard_paint();
	guilib_fb_unlock();
}

static unsigned int s_article_y_pos;
static uint32_t s_article_offset = 0;

void invert_selection(int old_pos, int new_pos, int start_pos, int height)
{
	guilib_fb_lock();

	if (old_pos != -1)
	{
		guilib_invert(start_pos - 2 + old_pos * height, height);
		guilib_invert_area(0, start_pos - 2 + old_pos * height, 0, start_pos - 2 + old_pos * height);
		guilib_invert_area(0, start_pos - 2 + old_pos * height + height - 1, 0, start_pos - 2 + old_pos * height + height - 1);
		guilib_invert_area(LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + old_pos * height, LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + old_pos * height);
		guilib_invert_area(LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + old_pos * height + height - 1, LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + old_pos * height + height - 1);
	}
	if (new_pos != -1)
	{
		guilib_invert(start_pos - 2 + new_pos * height, height);
		guilib_invert_area(0, start_pos - 2 + new_pos * height, 0, start_pos - 2 + new_pos * height);
		guilib_invert_area(0, start_pos - 2 + new_pos * height + height - 1, 0, start_pos - 2 + new_pos * height + height - 1);
		guilib_invert_area(LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + new_pos * height, LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + new_pos * height);
		guilib_invert_area(LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + new_pos * height + height - 1, LCD_BUF_WIDTH_PIXELS - 1, start_pos - 2 + new_pos * height + height - 1);
	}

	guilib_fb_unlock();
}
void invert_area(int start_x, int start_y, int end_x, int end_y)
{
	guilib_fb_lock();
	guilib_invert_area(start_x,start_y,end_x,end_y);
	guilib_fb_unlock();
}

int article_open(const char *article)
{
	DP(DBG_WL, ("O article_open() '%s'\n", article));
	s_article_offset = strtoul(article, 0 /* endptr */, 16 /* base */);
	s_article_y_pos = 0;
	return 0;
}


#if 0
// this is no longer used
void article_display(enum article_nav nav)
{
	unsigned int screen_height = guilib_framebuffer_height();

	DP(DBG_WL, ("O article_display() %i article_offset %u article_y_pos %u\n", nav, s_article_offset, s_article_y_pos));
	if (nav == ARTICLE_PAGE_NEXT)
		s_article_y_pos += screen_height;
	else if (nav == ARTICLE_PAGE_PREV)
		s_article_y_pos = (s_article_y_pos <= screen_height) ? 0 : s_article_y_pos - screen_height;
//	wom_draw(g_womh, s_article_offset, framebuffer, s_article_y_pos, screen_height);
}
#endif

#if 0
// this is no longer used
int article_open_pcf(const char *filename)
{

	FILE * pFile;
	long lSize;
	size_t result;

	pFile = fopen (filename , "rb" );

	if (pFile==NULL)
		return -1;

	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);

	rewind (pFile);

	// allocate memory to contain the whole file:
	articleBuffer = (char*) malloc (sizeof(char)*lSize);
	if (articleBuffer == NULL)
	{
		fclose(pFile);
		return -1;
	}

	// copy the file into the buffer:
	result = fread (articleBuffer,1,lSize,pFile);
	if (result != lSize)
	{
		fclose(pFile);
		return -1;
	}

	// terminate
	fclose (pFile);

	framebuffer_article=(char*)malloc(guilib_framebuffer_width()*nLine);
	memset(framebuffer_article,0,guilib_framebuffer_width()*nLine);

	render_article(articleBuffer,articleLength,framebuffer_article);

	return lSize;
}
#endif

void article_display_pcf(int yPixel)
{
	int pos;
	int copysize;
	int framebuffersize;

	framebuffersize  = 	guilib_framebuffer_size();

	pos = curBufferPos+((yPixel*LCD_VRAM_WIDTH_PIXELS)/8);
	if(pos<0 || pos>membuffersize)
	{
		return;
	}

	copysize = membuffersize-pos;


	if(copysize>framebuffersize)
		copysize = framebuffersize;

	else
	{
		return;
	}

	guilib_fb_lock();
	guilib_clear();

	memcpy(framebuffer,membuffer+pos,copysize);

	guilib_fb_unlock();

	curBufferPos = pos;
}

void handle_search_key(struct keyboard_key *key, unsigned long ev_time)
{
	int rc = 0;
	static unsigned long last_ev_time = 0;
	static struct keyboard_key *last_key = NULL;
	static char *last_key_utf8_char = NULL;
	struct keyboard_key *temp_last_key;
	char *temp_last_key_utf8_char;
	char keycode;

	temp_last_key = last_key;
	temp_last_key_utf8_char = last_key_utf8_char;
	last_key = NULL; // reset for phone style keyboard
	last_key_utf8_char = NULL;

	if (!key)
		return;
	keycode = *key->key;
	if (keycode == WL_KEY_NLS) {
#ifdef INCLUDED_FROM_KERNEL
		delay_us(100000);
#endif
		display_mode = DISPLAY_MODE_WIKI_SELECTION;
		keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
		keyboard_set_mode(KEYBOARD_NONE);
		wiki_selection();
		return;
	} else if (keycode == WL_KEY_BACKSPACE) {
		rc = search_remove_char(0, ev_time);
	} else if (keycode == WL_KEY_SWITCH_KEYBOARD ||
		   keycode == WL_KEY_POHONE_STYLE_KEYBOARD_DEFAULT ||
		   keycode == WL_KEY_POHONE_STYLE_KEYBOARD_ABC ||
		   keycode == WL_KEY_POHONE_STYLE_KEYBOARD_123) { // toggling keyboard will be handled at key down
		rc = -1;
	} else {
		int mode = keyboard_get_mode();
		if (wiki_keyboard_conversion_needed())
		{
			if (keycode == WL_KEY_SONANT)
			{
				rc = search_replace_japanese_sonant();
			}
			else if (keycode == WL_KEY_BACKWARD)
			{
				rc = search_replace_hiragana_backward();
			}
			else if (keycode == WL_KEY_CLEAR)
			{
				rc = clear_search_string();
				search_string_changed_remove = true;
				press_delete_button = false;
			}
			else
			{
				last_key = temp_last_key;
				last_key_utf8_char = temp_last_key_utf8_char;
				if (KEYBOARD_PHONE_STYLE < mode &&
				    key == last_key && time_diff(ev_time, last_ev_time) <= seconds_to_ticks(PHONE_STYLE_KEYIN_BEFORE_COMMIT_TIME))
				{
					last_ev_time = ev_time;
					last_key_utf8_char = next_utf8_char(last_key_utf8_char);
					if (*last_key_utf8_char == '\0')
						last_key_utf8_char = key->key;
					rc = search_replace_per_language_char(last_key_utf8_char);
				}
				else
				{
					if (strlen(key->key) > 1)
					{
						last_ev_time = ev_time;
						last_key = key;
						last_key_utf8_char = key->key;
					}
					else
					{
						last_key = NULL;
						last_key_utf8_char = NULL;
					}
					rc = search_add_per_language_char(key->key);
				}
			}
		}
		else if (is_supported_search_char(keycode))
			rc = search_add_char(tolower(keycode), ev_time);
		else // not supported char
			return;
	}

	guilib_fb_lock();
	if (!rc)
		search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_NO_POPULATE);
//
//	keyboard_paint();
	guilib_fb_unlock();
}

static int cursor_link = -1;

static void handle_cursor(struct wl_input_event *ev)
{
	DP(DBG_WL, ("O handle_cursor()\n"));
	if (display_mode == DISPLAY_MODE_ARTICLE){
		if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_UP) {
			display_article_with_pcf(-50);
		} else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_DOWN) {
			display_article_with_pcf(50);
		} else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_RIGHT) {
			if (cursor_link >= 0) {
				invert_link(cursor_link);
			}
			if (cursor_link > 0) {
				++cursor_link;
			} else {
				cursor_link = 1;
			}
			msg(MSG_INFO, "inv -> %d\n", cursor_link);
			invert_link(cursor_link);
		} else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_LEFT) {
			if (cursor_link >= 0) {
				invert_link(cursor_link);
			}
			if (cursor_link > 1) {
				--cursor_link;
				msg(MSG_INFO, "inv <- %d\n", cursor_link);
				invert_link(cursor_link);
			} else {
				cursor_link = -1;
			}
		}
	} else if (display_mode == DISPLAY_MODE_WIKI_SELECTION) {
		if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_DOWN) {
			display_article_with_pcf(50);
		} else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_UP) {
			display_article_with_pcf(-50);
		}
	} else if (display_mode == DISPLAY_MODE_INDEX) {
		if (keyboard_get_mode() == KEYBOARD_NONE) {
		if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_DOWN)
			display_article_with_pcf(50);
		else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_UP)
			display_article_with_pcf(-50);
		}
		{
			if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_RIGHT) {
				int selection = search_result_selected() + 1;
				search_set_selection(selection);
				//repaint_search();
				search_result_display();
			} else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_LEFT) {
				int selection = search_result_selected() - 1;
				if (selection < 0) {
					selection = -1;
				}
				search_set_selection(selection);
				//repaint_search();
				search_result_display();
			}
		}
	} else if (display_mode == DISPLAY_MODE_HISTORY && keyboard_get_mode() == KEYBOARD_NONE) {
		if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_DOWN)
			display_article_with_pcf(50);
		else if (ev->key_event.keycode == WL_INPUT_KEY_CURSOR_UP)
			display_article_with_pcf(-50);
	}
}

static void handle_key_release(int keycode)
{
//	static long idx_article = 0;
	static int first_time_random = 0;
	int mode;
	struct keyboard_key *key;

	finger_move_speed = 0;
	keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0); // reset invert immediately
	DP(DBG_WL, ("O handle_key_release()\n"));
	mode = keyboard_get_mode();
	if (keycode == WL_INPUT_KEY_POWER) {
#ifdef INCLUDED_FROM_KERNEL
		if (history_list_save(HISTORY_SAVE_POWER_OFF))
		{
			delay_us(200000);
		}
#endif
	} else if (keycode == WL_INPUT_KEY_SEARCH) {
		article_buf_pointer = NULL;
		/* back to search */
		if (display_mode == DISPLAY_MODE_INDEX) {
			toggle_soft_keyboard();
		} else {
			clear_article_pos_info(); // to clear the previous article positioning information for list links to work properly
			search_set_selection(-1);
			display_mode = DISPLAY_MODE_INDEX;
			keyboard_set_mode(wiki_default_keyboard());
			repaint_search();
		}
	} else if (keycode == WL_INPUT_KEY_HISTORY) {
		if (display_mode != DISPLAY_MODE_HISTORY) {
			clear_article_pos_info(); // to clear the previous article positioning information for list links to work properly
			article_buf_pointer = NULL;
			history_reload();
			display_mode = DISPLAY_MODE_HISTORY;
			keyboard_set_mode(KEYBOARD_NONE);
		} else {
			if (keyboard_get_mode() == KEYBOARD_CLEAR_HISTORY)
			{
				keyboard_set_mode(KEYBOARD_NONE);
				guilib_fb_lock();
				//keyboard_paint();
				draw_clear_history(1);
				guilib_fb_unlock();
			} else if (history_get_count() > 0 && display_first_page) {
				keyboard_set_mode(KEYBOARD_CLEAR_HISTORY);
				guilib_fb_lock();
				//keyboard_paint();
				draw_clear_history(0);
				guilib_fb_unlock();
			}
		}
	} else if (keycode == WL_INPUT_KEY_RANDOM) {
		if (first_time_random < 4)
			first_time_random++;
		if (first_time_random == 3)
		{
			first_time_random = 4;
			if (init_article_filter())
				return;
		}
		article_buf_pointer = NULL;
		display_mode = DISPLAY_MODE_ARTICLE;
		last_display_mode = DISPLAY_MODE_INDEX;
		random_article();
	} else if (display_mode == DISPLAY_MODE_INDEX) {
		article_buf_pointer = NULL;

		if (WL_KEY_RETURN == keycode) {
			int selection = search_result_selected();
			if (selection < 0) {
				selection = 0;
				search_set_selection(selection);
			}
			display_mode = DISPLAY_MODE_ARTICLE;
			last_display_mode = DISPLAY_MODE_INDEX;
			search_open_article(selection);
			cursor_link = -1;
#ifdef PROFILER_ON
		} else if (keycode == WL_KEY_HASH) {
			/* activate if you want to run performance tests */
			/* perf_test(); */
			malloc_status_simple();
			prof_print();
#endif
		} else {
			key = keyboard_locate_key((char)keycode);
			if (key)
				handle_search_key(key, get_time_ticks());
		}
	} else if (display_mode == DISPLAY_MODE_HISTORY) {
		if (keycode == 'Y' || keycode == 'y') {
			history_clear();
			msg(MSG_INFO, "History Cleared\n"); // inform test program history was cleared
		}
		clear_article_pos_info(); // to clear the previous article positioning information for list links to work properly
		article_buf_pointer = NULL;
		history_reload();
		keyboard_set_mode(KEYBOARD_NONE);
	} else if (display_mode == DISPLAY_MODE_ARTICLE) {
//		article_buf_pointer = NULL;
		if (keycode == WL_KEY_BACKSPACE) {
			if (last_display_mode == DISPLAY_MODE_INDEX) {
				display_mode = DISPLAY_MODE_INDEX;
				repaint_search();
			} else if (last_display_mode == DISPLAY_MODE_HISTORY) {
				display_mode = DISPLAY_MODE_HISTORY;
				history_reload();
			}
		} else if (keycode == WL_KEY_RETURN) {
			if (cursor_link > 0) {
				display_mode = DISPLAY_MODE_ARTICLE;
				open_article_link_with_link_number(cursor_link);
				cursor_link = -1;
			}
		}
	}
}

static void average_xy(int *average_x, int *average_y, int last_5_x[], int last_5_y[], unsigned long last_5_y_time_ticks[])
{
	int i;

	*average_y = 999; // take the toppest y
	*average_x = -1;
	for (i = 4; i >= 0; i--)
	{
		if (last_5_x[i] >= 0 && time_diff(last_5_y_time_ticks[i], last_5_y_time_ticks[0]) < seconds_to_ticks(SAME_CLICK_TIME_THRESHOLD))
		{
			if (*average_x < 0)
			{
				*average_x = last_5_x[i];
			}
			else
			{
				*average_x += last_5_x[i];
				*average_x /= 2; // the latter point got the higher weighting
			}
			if (*average_y > last_5_y[i])
				*average_y = last_5_y[i];
		}
	}
	if (0 < *average_y + LCD_Y_CALIBRATION_ADJUSTMENT && *average_y + LCD_Y_CALIBRATION_ADJUSTMENT < LCD_HEIGHT_LINES)
		*average_y = *average_y + LCD_Y_CALIBRATION_ADJUSTMENT;
}

static void handle_keyboard_en(struct wl_input_event *ev, int last_5_x[], int last_5_y[], unsigned long last_5_y_time_ticks[])
{
	int mode;
	struct keyboard_key * key;
	int i;
	int average_x, average_y;
	long time_now;

	article_buf_pointer = NULL;
	if (!touch_down_on_keyboard && !touch_down_on_list)
	{
		last_5_x[0] = ev->touch_event.x;
		last_5_y[0] = ev->touch_event.y;
		last_5_y_time_ticks[0] = ev->touch_event.ticks;
		for (i = 1; i < 5; i++)
		{
			last_5_x[i] = -1;
			last_5_y[i] = -1;
		}
	}
	else
	{
		for (i = 4; i >= 1; i--)
		{
			last_5_x[i] = last_5_x[i-1];
			last_5_y[i] = last_5_y[i-1];
			last_5_y_time_ticks[i] = last_5_y_time_ticks[i-1];
		}
		last_5_x[0] = ev->touch_event.x;
		last_5_y[0] = ev->touch_event.y;
		last_5_y_time_ticks[0] = ev->touch_event.ticks;
	}
	average_xy(&average_x, &average_y, last_5_x, last_5_y, last_5_y_time_ticks);
	key = keyboard_get_data(average_x, average_y);
	if (ev->touch_event.value == 0) {
		keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
		enter_touch_y_pos = -1;
		touch_search = 0;
		//if (pre_key && pre_key != key && keyboard_adjacent_keys(pre_key, key))
		//{
		//	touch_down_on_keyboard = 0;
		//	touch_down_on_list = 0;
		//	pre_key = NULL;
		//	goto out;
		//}

		pre_key = NULL;
		if (press_delete_button)
		{
			handle_search_key(NULL, 0); // reset pre_key for phone style keyboard
			touch_down_on_keyboard = 0;
			touch_down_on_list = 0;
			press_delete_button = false;
			goto out;
		}
		if (key) {
			if (!touch_down_on_keyboard) {
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				goto out;
			}
			handle_search_key(key, ev->touch_event.ticks);
		}
		else {
			if (!touch_down_on_list || ev->touch_event.y < RESULT_START - RESULT_HEIGHT) {
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				goto out;
			}
			if(search_result_count()==0)
				goto out;

			//search_set_selection(last_selection);
			//search_open_article(last_selection);
			if(search_result_selected()>=0)
			{
				display_mode = DISPLAY_MODE_ARTICLE;
				last_display_mode = DISPLAY_MODE_INDEX;
				search_open_article(search_result_selected());
			}
		}
		touch_down_on_keyboard = 0;
		touch_down_on_list = 0;
	} else {
		if (pre_key && (!key || strcmp(pre_key->key, key->key)))
		{
			keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
			//goto out;
		}

		if(enter_touch_y_pos<0)  //record first touch y pos
			enter_touch_y_pos = ev->touch_event.y;
		last_index_y_pos = ev->touch_event.y;
		if (!key || *key->key!=WL_KEY_BACKSPACE || !press_delete_button)
		{
			start_search_time = ev->touch_event.ticks;
			last_delete_time = start_search_time;
		}
		if (key) {
			if(*key->key==WL_KEY_BACKSPACE)//press "<" button
			{
				if (!press_delete_button)
				{
					press_delete_button = true;
					if(get_search_string_len()>0)
					{
						time_now = get_time_ticks();
						if (!search_remove_char(0, time_now))
						{
							search_string_changed_remove = true;
							search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_NO_POPULATE);
						}
						last_delete_time = time_now;
					}
				}
			}
			else
			{
				press_delete_button = false;
				if(*key->key == WL_KEY_SWITCH_KEYBOARD)
				{
					keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
					if (!touch_down_on_keyboard)
					{
						mode = keyboard_get_mode();
						if(mode == wiki_default_keyboard())
							keyboard_set_mode(KEYBOARD_NUM);
						else if(mode == KEYBOARD_NUM)
						{
							if (wiki_is_japanese() || wiki_is_korean())
								keyboard_set_mode(KEYBOARD_CHAR);
							else
								keyboard_set_mode(wiki_default_keyboard());
						} else if (mode == KEYBOARD_CHAR) { // mode != wiki_default_keyboard() && mode == KEYBOARD_CHAR
							keyboard_set_mode(wiki_default_keyboard());
						}
						guilib_fb_lock();
						keyboard_paint();
						guilib_fb_unlock();
					}
				}
			}

			if (!touch_down_on_keyboard && !touch_down_on_list)
				touch_down_on_keyboard = 1;

			if (pre_key && !strcmp(pre_key->key, key->key)) goto out;

			if (touch_down_on_keyboard) {
				keyboard_key_invert(key);
				//if (pre_key && !keyboard_adjacent_keys(pre_key, key))
				//{
				//	handle_search_key(pre_key, ev->touch_event.ticks);
				//	pre_key = NULL;
				//}
				//else
				pre_key = key;
			}
		} else {
			if (!touch_down_on_keyboard && !touch_down_on_list)
				touch_down_on_list = 1;
			keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
			pre_key = NULL;

			if (!search_result_count()) goto out;

			if(touch_search == 0)
			{
				//last_search_y_pos = ev->touch_event.y;
				touch_search = 1;
			}
			else
			{
				if(search_result_selected()>=0 && abs(ev->touch_event.y-search_touch_pos_y_last)>5)
				{
					invert_selection(search_result_selected(),-1, RESULT_START, RESULT_HEIGHT);
					search_set_selection(-1);
				}
				goto out;
			}

			int new_selection;
			if((ev->touch_event.y - RESULT_START)<0)
				new_selection = -1;
			else
				new_selection = ((unsigned int)ev->touch_event.y - RESULT_START) / RESULT_HEIGHT;

			if (new_selection == search_result_selected()) goto out;

			unsigned int avail_count = keyboard_get_mode() == KEYBOARD_NONE ?
				NUMBER_OF_FIRST_PAGE_RESULTS : NUMBER_OF_RESULTS_KEYBOARD;
			avail_count = search_result_count() > avail_count ? avail_count : search_result_count();
			if (new_selection >= avail_count) goto out;
			if (touch_down_on_keyboard) goto out;

			//invert_selection(search_result_selected(), new_selection, RESULT_START, RESULT_HEIGHT);
			invert_selection(-1, new_selection, RESULT_START, RESULT_HEIGHT);

			last_selection = new_selection ;
			search_set_selection(new_selection);
			search_touch_pos_y_last = ev->touch_event.y;
		}
	}
out:
	return;
}

static void handle_keyboard_phone_style(struct wl_input_event *ev, int last_5_x[], int last_5_y[], unsigned long last_5_y_time_ticks[])
{
	struct keyboard_key * key;
	int i;
	int average_x, average_y;
	long time_now;

	article_buf_pointer = NULL;
	if (!touch_down_on_keyboard && !touch_down_on_list)
	{
		last_5_x[0] = ev->touch_event.x;
		last_5_y[0] = ev->touch_event.y;
		last_5_y_time_ticks[0] = ev->touch_event.ticks;
		for (i = 1; i < 5; i++)
		{
			last_5_x[i] = -1;
			last_5_y[i] = -1;
		}
	}
	else
	{
		for (i = 4; i >= 1; i--)
		{
			last_5_x[i] = last_5_x[i-1];
			last_5_y[i] = last_5_y[i-1];
			last_5_y_time_ticks[i] = last_5_y_time_ticks[i-1];
		}
		last_5_x[0] = ev->touch_event.x;
		last_5_y[0] = ev->touch_event.y;
		last_5_y_time_ticks[0] = ev->touch_event.ticks;
	}
	average_xy(&average_x, &average_y, last_5_x, last_5_y, last_5_y_time_ticks);
	key = keyboard_get_data(average_x, average_y);
	if (ev->touch_event.value == 0) {
		keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
		enter_touch_y_pos = -1;
		touch_search = 0;

		pre_key = NULL;
		if (press_delete_button)
		{
			handle_search_key(NULL, 0); // reset pre_key for phone style keyboard
			touch_down_on_keyboard = 0;
			touch_down_on_list = 0;
			press_delete_button = false;
			goto out;
		}
		if (key) {
			if (!touch_down_on_keyboard) {
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				goto out;
			}
			handle_search_key(key, ev->touch_event.ticks);
		}
		else {
			if (!touch_down_on_list || ev->touch_event.y < RESULT_START - RESULT_HEIGHT) {
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				goto out;
			}
			if(search_result_count()==0)
				goto out;

			//search_set_selection(last_selection);
			//search_open_article(last_selection);
			if(search_result_selected()>=0)
			{
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
				display_mode = DISPLAY_MODE_ARTICLE;
				last_display_mode = DISPLAY_MODE_INDEX;
				search_open_article(search_result_selected());
			}
		}
		touch_down_on_keyboard = 0;
		touch_down_on_list = 0;
	} else {
		if(enter_touch_y_pos<0)  //record first touch y pos
			enter_touch_y_pos = ev->touch_event.y;
		last_index_y_pos = ev->touch_event.y;
		if (!key || *key->key!=WL_KEY_BACKSPACE || !press_delete_button)
		{
			start_search_time = ev->touch_event.ticks;
			last_delete_time = start_search_time;
		}
		if (key) {
			if(*key->key==WL_KEY_BACKSPACE)//press "<" button
			{
				if (!press_delete_button)
				{
					press_delete_button = true;
					if(get_search_string_len()>0)
					{
						time_now = get_time_ticks();
						if (!search_remove_char(0, time_now))
						{
							search_string_changed_remove = true;
							search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_NO_POPULATE);
						}
						last_delete_time = time_now;
					}
				}
			}
			else
			{
				press_delete_button = false;
				if(*key->key == WL_KEY_POHONE_STYLE_KEYBOARD_DEFAULT ||
				   *key->key == WL_KEY_POHONE_STYLE_KEYBOARD_ABC ||
				   *key->key == WL_KEY_POHONE_STYLE_KEYBOARD_123)
				{
					keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
					if (!touch_down_on_keyboard)
					{
						if (*key->key == WL_KEY_POHONE_STYLE_KEYBOARD_DEFAULT)
							keyboard_set_mode(wiki_default_keyboard());
						else if (*key->key == WL_KEY_POHONE_STYLE_KEYBOARD_ABC)
							keyboard_set_mode(KEYBOARD_PHONE_STYLE_ABC);
						else if (*key->key == WL_KEY_POHONE_STYLE_KEYBOARD_123)
							keyboard_set_mode(KEYBOARD_PHONE_STYLE_123);
						guilib_fb_lock();
						keyboard_paint();
						guilib_fb_unlock();
					}
				}
			}

			if (!touch_down_on_keyboard && !touch_down_on_list)
				touch_down_on_keyboard = 1;

			if (pre_key && !strcmp(pre_key->key, key->key)) goto out;

			if (touch_down_on_keyboard) {
				keyboard_key_invert(key);
				//if (pre_key && !keyboard_adjacent_keys(pre_key, key))
				//{
				//	handle_search_key(pre_key, ev->touch_event.ticks);
				//	pre_key = NULL;
				//}
				//else
				pre_key = key;
			}
		} else {
			if (!touch_down_on_keyboard && !touch_down_on_list)
				touch_down_on_list = 1;
			keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
			pre_key = NULL;

			if (!search_result_count()) goto out;

			if(touch_search == 0)
			{
				//last_search_y_pos = ev->touch_event.y;
				touch_search = 1;
			}
			else
			{
				if(search_result_selected()>=0 && abs(ev->touch_event.y-search_touch_pos_y_last)>5)
				{
					invert_selection(search_result_selected(),-1, RESULT_START, RESULT_HEIGHT);
					search_set_selection(-1);
				}
				goto out;
			}

			int new_selection;
			if((ev->touch_event.y - RESULT_START)<0)
				new_selection = -1;
			else
				new_selection = ((unsigned int)ev->touch_event.y - RESULT_START) / RESULT_HEIGHT;

			if (new_selection == search_result_selected()) goto out;

			unsigned int avail_count = keyboard_get_mode() == KEYBOARD_NONE ?
				NUMBER_OF_FIRST_PAGE_RESULTS : NUMBER_OF_RESULTS_KEYBOARD;
			avail_count = search_result_count() > avail_count ? avail_count : search_result_count();
			if (new_selection >= avail_count) goto out;
			if (touch_down_on_keyboard) goto out;

			//invert_selection(search_result_selected(), new_selection, RESULT_START, RESULT_HEIGHT);
			invert_selection(-1, new_selection, RESULT_START, RESULT_HEIGHT);

			last_selection = new_selection ;
			search_set_selection(new_selection);
			search_touch_pos_y_last = ev->touch_event.y;
		}
	}
out:
	return;
}

static void handle_touch(struct wl_input_event *ev)
{
	//int offset,offset_count,
	int article_link_number=-1;
	//int time_diff_search;
	int mode;
	struct keyboard_key * key;
	static int last_5_x[5];
	static int last_5_y[5];
	static unsigned long last_5_y_time_ticks[5];
	int i;
	int average_x, average_y;
	long time_now;

	DP(DBG_WL, ("%s() touch event @%d,%d val %d\n", __func__,
		    ev->touch_event.x, ev->touch_event.y, ev->touch_event.value));

	mode = keyboard_get_mode();
	if (display_mode == DISPLAY_MODE_INDEX && (KEYBOARD_NONE < mode && mode < KEYBOARD_PHONE_STYLE))
	{
		handle_keyboard_en(ev, last_5_x, last_5_y, last_5_y_time_ticks);
	}
	else if (display_mode == DISPLAY_MODE_INDEX && KEYBOARD_PHONE_STYLE < mode)
	{
		handle_keyboard_phone_style(ev, last_5_x, last_5_y, last_5_y_time_ticks);
	}
	else if (display_mode == DISPLAY_MODE_HISTORY && mode == KEYBOARD_CLEAR_HISTORY)
	{
		key = keyboard_get_data(ev->touch_event.x, ev->touch_event.y);
		if (ev->touch_event.value == 0) {
#ifdef INCLUDED_FROM_KERNEL
			delay_us(100000 * 2);
#endif
			keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
			enter_touch_y_pos = -1;
			touch_search = 0;
			pre_key = NULL;
			if (press_delete_button)
			{
				press_delete_button = false;
				goto out;
			}
			if (key) {
				if (!touch_down_on_keyboard) {
					touch_down_on_keyboard = 0;
					touch_down_on_list = 0;
					goto out;
				}
				if (*key->key == 'Y') {
					history_clear();
					keyboard_set_mode(KEYBOARD_NONE);
					history_reload();
				} else if (*key->key == 'N') {
					keyboard_set_mode(KEYBOARD_NONE);
					guilib_fb_lock();
					draw_clear_history(1);
					guilib_fb_unlock();
				}
			}
			else {
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				goto out;
			}
		} else {
			if(enter_touch_y_pos<0)  //record first touch y pos
				enter_touch_y_pos = ev->touch_event.y;
			last_index_y_pos = ev->touch_event.y;
			if (key) {
				if (!touch_down_on_keyboard)
					touch_down_on_keyboard = 1;

				if (pre_key && !strcmp(pre_key->key, key->key)) goto out;

				if (touch_down_on_keyboard) {
					keyboard_key_invert(key);
					//if (pre_key && !keyboard_adjacent_keys(pre_key, key))
					//{
					//	handle_search_key(pre_key, ev->touch_event.ticks);
					//	pre_key = NULL;
					//}
					//else
					pre_key = key;
				}
			} else {
				touch_down_on_keyboard = 0;
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
				pre_key = NULL;

			}
		}
	}
	else if (display_mode == DISPLAY_MODE_RESTRICTED)
	{
		key = keyboard_get_data(ev->touch_event.x, ev->touch_event.y);
		if (ev->touch_event.value == 0) {
			if (*key->key == 'Y' || *key->key == 'N' || *key->key == 'P')
			{
#ifdef INCLUDED_FROM_KERNEL
				delay_us(100000 * 2);
#endif
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
			}
			else
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_DELAY, ev->touch_event.ticks); // reset invert with delay
			enter_touch_y_pos = -1;
			touch_search = 0;
			//if (pre_key && pre_key != key && keyboard_adjacent_keys(pre_key, key))
			//{
			//	touch_down_on_keyboard = 0;
			//	touch_down_on_list = 0;
			//	pre_key = NULL;
			//	goto out;
			//}

			pre_key = NULL;
			if (press_delete_button)
			{
				touch_down_on_keyboard = 0;
				touch_down_on_list = 0;
				press_delete_button = false;
				goto out;
			}
			if (key) {
				if (!touch_down_on_keyboard) {
					touch_down_on_keyboard = 0;
					goto out;
				}
				handle_password_key(*key->key);
			}
			touch_down_on_keyboard = 0;
		} else {
			if (pre_key && (!key || strcmp(pre_key->key, key->key)))
			{
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
				//goto out;
			}

			if(enter_touch_y_pos<0)  //record first touch y pos
				enter_touch_y_pos = ev->touch_event.y;
			last_index_y_pos = ev->touch_event.y;
			if (!key || *key->key!=WL_KEY_BACKSPACE || !press_delete_button)
			{
				start_search_time = ev->touch_event.ticks;
				last_delete_time = start_search_time;
			}
			if (key) {
				if(*key->key==WL_KEY_BACKSPACE)//press "<" button
				{
					if (!press_delete_button)
					{
						press_delete_button = true;
						if (get_password_string_len()>0)
						{
							time_now = get_time_ticks();
							password_remove_char();
							last_delete_time = time_now;
						}
					}
				}
				else
				{
					press_delete_button = false;
					if(*key->key == WL_KEY_SWITCH_KEYBOARD)
					{
						mode = keyboard_get_mode();
						if(mode == KEYBOARD_PASSWORD_CHAR)
							keyboard_set_mode(KEYBOARD_PASSWORD_NUM);
						else if(mode == KEYBOARD_PASSWORD_NUM)
							keyboard_set_mode(KEYBOARD_PASSWORD_CHAR);
						guilib_fb_lock();
						keyboard_paint();
						guilib_fb_unlock();
					}
				}

				if (!touch_down_on_keyboard)
					touch_down_on_keyboard = 1;

				if (pre_key && !strcmp(pre_key->key, key->key)) goto out;

				if (touch_down_on_keyboard) {
					keyboard_key_invert(key);
					pre_key = key;
				}
			} else {
				keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_NOW, 0);
				pre_key = NULL;

				search_touch_pos_y_last = ev->touch_event.y;
			}
		}
	} else {
		if (ev->touch_event.value == 0) {
			unsigned long diff_ticks = 0;
			long diff_y = 0;

			finger_touched = 0;
			time_scroll_article_last = ev->touch_event.ticks;
			for (i = 4; i > 0; i--)
			{
				if (last_5_y[i] >= 0)
				{
					diff_y =  last_5_y[i] - ev->touch_event.y;
					diff_ticks = time_diff(ev->touch_event.ticks, last_5_y_time_ticks[i]);
					break;
				}
			}

			if (diff_ticks <= 0 || abs(article_moved_pixels) > SMOOTH_SCROLL_ACTIVATION_OFFSET_HIGH_THRESHOLD ||
			    abs(article_moved_pixels) < SMOOTH_SCROLL_ACTIVATION_OFFSET_LOW_THRESHOLD)
				finger_move_speed = 0;
			else
			{
				// Event timesing is not good for short period due to the events are queued without timestamp
				finger_move_speed = (float)diff_y * ((float)seconds_to_ticks(1) / (float)diff_ticks);
				if (abs(finger_move_speed) > SMOOTH_SCROLL_ACTIVATION_SPPED_THRESHOLD)
				{
					if (finger_move_speed > 0)
					{
						if (display_mode == DISPLAY_MODE_ARTICLE)
							finger_move_speed = ARTICLE_SMOOTH_SCROLL_SPEED_FACTOR *
								(finger_move_speed - SMOOTH_SCROLL_ACTIVATION_SPPED_THRESHOLD);
						else
							finger_move_speed = LIST_SMOOTH_SCROLL_SPEED_FACTOR *
								(finger_move_speed - SMOOTH_SCROLL_ACTIVATION_SPPED_THRESHOLD);
					}
					else
					{
						if (display_mode == DISPLAY_MODE_ARTICLE)
							finger_move_speed = ARTICLE_SMOOTH_SCROLL_SPEED_FACTOR *
								(finger_move_speed + SMOOTH_SCROLL_ACTIVATION_SPPED_THRESHOLD);
						else
							finger_move_speed = LIST_SMOOTH_SCROLL_SPEED_FACTOR *
								(finger_move_speed + SMOOTH_SCROLL_ACTIVATION_SPPED_THRESHOLD);
					}
				}
				else
					finger_move_speed = 0;
			}

			article_moved = false;
			if (finger_move_speed == 0 && b_show_scroll_bar)
			{
				b_show_scroll_bar = 0;
				show_scroll_bar(0); // clear scroll bar
			}
			article_scroll_pixel = INITIAL_ARTICLE_SCROLL_THRESHOLD;
			article_moved_pixels = 0;
			touch_y_last_unreleased = 0;
			start_move_time = 0;

			article_link_number = get_activated_article_link_number();
			if(article_link_number>=0)
			{
				if (link_to_be_inverted >= 0)
				{
					if (link_currently_inverted >= 0)
						invert_link(link_currently_inverted);
					invert_link(link_to_be_inverted);
				}
				if (finger_move_speed == 0)
				{
					init_invert_link();
					last_display_mode = display_mode;
					if (display_mode == DISPLAY_MODE_WIKI_SELECTION)
					{
						set_wiki(article_link_number);
						search_init();
						search_set_selection(-1);
						display_mode = DISPLAY_MODE_INDEX;
						keyboard_set_mode(wiki_default_keyboard());
						repaint_search();
					}
					else
					{
						if (display_mode == DISPLAY_MODE_ARTICLE)
						{
							saved_prev_idx_article = saved_idx_article;
							if (!(saved_prev_idx_article & 0xFF000000)) // idx_article for current wiki
							{
								saved_prev_idx_article |= get_wiki_id_from_idx(nCurrentWiki) << 24;
							}
						}
						else
							saved_prev_idx_article = 0;
						display_mode = DISPLAY_MODE_ARTICLE;
						open_article_link_with_link_number(article_link_number);
					}
				}
				else
				{
					if (link_currently_inverted >= 0)
						invert_link(link_currently_inverted);
					init_invert_link();
				}
				return;
			}

			reset_article_link_number();
			article_touch_down_handled = 0;
		} else {
			finger_touched = 1;
			finger_move_speed = 0;

			if(touch_y_last_unreleased == 0)
			{
				touch_y_last_unreleased = ev->touch_event.y;
				touch_y_last = ev->touch_event.y;
				last_unreleased_time = ev->touch_event.ticks;
				reset_article_link_number();
				article_moved_pixels = 0;
				last_5_x[0] = ev->touch_event.x;
				last_5_y[0] = ev->touch_event.y;
				last_5_y_time_ticks[0] = ev->touch_event.ticks;
				for (i = 1; i < 5; i++)
				{
					last_5_x[i] = -1;
					last_5_y[i] = -1;
				}

			}
			else
			{
				article_moved_pixels += touch_y_last - ev->touch_event.y;
				if(article_moved || abs(article_moved_pixels) > article_scroll_pixel)
				{
					if (!article_moved)
					{
						article_moved = true;
						reset_article_link_number();
						if (article_moved_pixels > 0)
							article_moved_pixels -= article_scroll_pixel;
						else
							article_moved_pixels += article_scroll_pixel;
						display_article_with_pcf(article_moved_pixels);
						article_scroll_pixel = ARTICLE_MOVING_SCROLL_THRESHOLD;
					}
					else if (finger_move_speed == 0)
					{
						display_article_with_pcf(touch_y_last - ev->touch_event.y);
					}
					for (i = 4; i >= 1; i--)
					{
						last_5_x[i] = last_5_x[i-1];
						last_5_y[i] = last_5_y[i-1];
						last_5_y_time_ticks[i] = last_5_y_time_ticks[i-1];
					}
					last_5_x[0] = ev->touch_event.x;
					last_5_y[0] = ev->touch_event.y;
					last_5_y_time_ticks[0] = ev->touch_event.ticks;
					b_show_scroll_bar = 1;
				}
				touch_y_last = ev->touch_event.y;
			}

			if (!article_moved && get_activated_article_link_number() < 0)
			{
				average_xy(&average_x, &average_y, last_5_x, last_5_y, last_5_y_time_ticks);
				article_link_number = isArticleLinkSelected(average_x, average_y);
				if (article_link_number >= 0)
					set_article_link_number(article_link_number, ev->touch_event.ticks);
			}

			if (!article_touch_down_handled) {
				article_touch_down_pos.x = ev->touch_event.x;
				article_touch_down_pos.y = ev->touch_event.y;
				article_touch_down_handled = 1;
			}
		}
	}
out:
	return;
}

int wikilib_init (void)
{
	init_lcd_draw_buf();
	init_file_buffer();
	init_wiki_info();
	return 0;
}

#ifndef INCLUDED_FROM_KERNEL
extern long idx_init_article;
#endif

int wikilib_run(void)
{
	int sleep;
	long time_now;
	struct wl_input_event ev;
	int more_events = 0;
	unsigned long last_event_time = 0;
	int rc;
	char *pMsg;


	/*
	 * test searching code...
	 */
	article_buf_pointer = NULL;
	search_init();
	history_list_init();
	malloc_status_simple();
	print_intro();
#ifndef INCLUDED_FROM_KERNEL
	if (!load_init_article(idx_init_article))
	{
		display_mode = DISPLAY_MODE_ARTICLE;
		last_display_mode = DISPLAY_MODE_INDEX;
	}
#endif
	pMsg = get_nls_text("type_a_word");
	render_string(SUBTITLE_FONT_IDX, -1, 55, pMsg, strlen(pMsg), 0);
#if defined(INCLUDED_FROM_KERNEL) && ENABLE_TEMPERATURE
		char *tMsg = Temperature_string(1);
		render_string_and_clear(SUBTITLE_FONT_IDX, 180, 10, tMsg, strlen(tMsg), 1,
					0, 0, 239, 40 );
#endif

	for (;;) {
		if (more_events)
			sleep = 0;
		else
			sleep = 1;
		if (!more_events && display_mode == DISPLAY_MODE_ARTICLE && render_article_with_pcf())
			sleep = 0;
		else if (!more_events && display_mode == DISPLAY_MODE_INDEX && render_search_result_with_pcf())
			sleep = 0;
		else if (!more_events && display_mode == DISPLAY_MODE_HISTORY && render_history_with_pcf())
			sleep = 0;
		else if (!more_events && display_mode == DISPLAY_MODE_WIKI_SELECTION && render_wiki_selection_with_pcf())
			sleep = 0;

		if (finger_move_speed && !finger_touched)
		{
			scroll_article();
			sleep = 0;
		}

		time_now = get_time_ticks();
		if(display_mode == DISPLAY_MODE_INDEX)
		{
			if (press_delete_button && get_search_string_len()>0)
			{
				int kb_mode = keyboard_get_mode();
				sleep = 0;
				if(kb_mode < KEYBOARD_PHONE_STYLE &&
				   time_diff(time_now, start_search_time) > seconds_to_ticks(2.1))
				{
					if (!clear_search_string())
					{
						search_string_changed_remove = true;
						search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_NO_POPULATE);
					}
					press_delete_button = false;
				}
				else if (time_diff(time_now, start_search_time) > seconds_to_ticks(0.3) &&
					 time_diff(time_now, last_delete_time) > seconds_to_ticks(0.1))
				{
					if (!search_remove_char(0, time_now))
					{
						search_string_changed_remove = true;
						search_to_be_reloaded(SEARCH_TO_BE_RELOADED_SET, SEARCH_RELOAD_NO_POPULATE);
					}
					last_delete_time = time_now;
				}
			}
		}
		else if (display_mode == DISPLAY_MODE_RESTRICTED)
		{
			if (press_delete_button && get_password_string_len()>0)
			{
				sleep = 0;
				time_now = get_time_ticks();
				if(time_diff(time_now, start_search_time) > seconds_to_ticks(2.1))
				{
					clear_password_string();
					press_delete_button = false;
				}
				else if (time_diff(time_now, start_search_time) > seconds_to_ticks(0.3) &&
					 time_diff(time_now, last_delete_time) > seconds_to_ticks(0.1))
				{
					password_remove_char();
					last_delete_time = time_now;
				}
			}
		}

		if (!more_events && display_mode == DISPLAY_MODE_INDEX && fetch_search_result(0, 0, 0))
		{
			sleep = 0;
		}

		if (!more_events && display_mode == DISPLAY_MODE_INDEX && !press_delete_button && !touch_down_on_keyboard && check_search_string_change())
		{
			sleep = 0;
		}

		if (keyboard_key_reset_invert(KEYBOARD_RESET_INVERT_CHECK, 0)) // check if need to reset invert
			sleep = 0;

		if (keyboard_korean_special_key()) // check if need to enable the special key
			sleep = 0;

		if (check_invert_link()) // check if need to invert link
			sleep = 0;

		if (sleep)
		{
			if (time_diff(get_time_ticks(), last_event_time) > seconds_to_ticks(5))
				rc = history_list_save(HISTORY_SAVE_POWER_OFF);
			else if (time_diff(get_time_ticks(), last_event_time) > seconds_to_ticks(2))
				rc = history_list_save(HISTORY_SAVE_NORMAL);
			else
				rc = -1;
			if (rc > 0)
			{
#ifdef INCLUDED_FROM_KERNEL
				delay_us(200000); // for some reason, save may not work if no delay
#endif
			}
			else if (rc < 0)
				sleep = 0; // waiting for last_event_time timeout to save the history
		}

		wl_input_wait(&ev, sleep);
		more_events = 1;
		switch (ev.type) {
		case WL_INPUT_EV_TYPE_CURSOR:
			handle_cursor(&ev);
			last_event_time = get_time_ticks();
			break;
		case WL_INPUT_EV_TYPE_KEYBOARD:
			if (ev.key_event.value != 0)
			{
				b_show_scroll_bar = 0;
				handle_key_release(ev.key_event.keycode);
			}
			last_event_time = get_time_ticks();
			break;
		case WL_INPUT_EV_TYPE_TOUCH:
#ifndef INCLUDED_FROM_KERNEL
			ev.touch_event.ticks = get_time_ticks();
#endif
			handle_touch(&ev);
			last_event_time = ev.touch_event.ticks;
			break;
		default:
			more_events = 0;
			break;
		}
	}

	/* never reached */
	return 0;
}

unsigned long get_time_ticks(void)
{
	long clock_ticks;

#ifdef INCLUDED_FROM_KERNEL
	clock_ticks = Tick_get();
#else
	clock_ticks = clock();
#endif
	if (clock_ticks == 0)
		clock_ticks = 1; // 0 is used for special purpose
	return clock_ticks;
}

unsigned long time_diff(unsigned long t2, unsigned long t1)
{
	unsigned long diff;

	if (t2 < t1)
		diff = (unsigned long) 0xFFFFFFFF - t1 + t2;
	else
		diff = t2 - t1;
	return diff;
}

unsigned long seconds_to_ticks(float sec)
{
	long clock_ticks;

#ifdef INCLUDED_FROM_KERNEL
	clock_ticks = sec * Tick_TicksPerSecond;
#else
	clock_ticks = sec * CLOCKS_PER_SEC;
#endif

	return clock_ticks;
}

void fatal_error(char *sError)
{
	struct wl_input_event ev;

	guilib_fb_lock();
	guilib_clear();
#ifndef INCLUDED_FROM_KERNEL
	printf("Fatal error - %s\n", sError);
	exit(-1);
#else
	render_string(SUBTITLE_FONT_IDX, -1, 94, sError, strlen(sError), 0);
	guilib_fb_unlock();
	for (;;)
		wl_input_wait(&ev, 1);
#endif
}
