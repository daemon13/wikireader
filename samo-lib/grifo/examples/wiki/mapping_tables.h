/*
 * Copyright (c) 2009 Openmoko Inc.
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

#ifndef MAPPING_TABLES_H
#define MAPPING_TABLES_H

struct _english_hiragana_mapping {
	const char *english;
	const char *hiragana;
} english_hiragana_mapping[] = {
	{",",   "、"	},
	{"-",   "ー"	},
	{".",   "。"	},
	{"a",	"あ"    },
	{"ba",	"ば"   },
	{"bba", "っば" },
	{"bbe", "っべ" },
	{"bbi", "っび" },
	{"bbo", "っぼ" },
	{"bbu",	"っぶ"	},
	{"bbya","っびゃ"  },
	{"bbye","っびぇ"  },
	{"bbyi","っびぃ"  },
	{"bbyo","っびょ"  },
	{"bbyu","っびゅ"	},
	{"be",	"べ"   },
	{"bi",	"び"   },
	{"bo",	"ぼ"   },
	{"bu",	"ぶ"   },
	{"bya",	"びゃ"  },
	{"bye",	"びぇ"  },
	{"byi",	"びぃ"  },
	{"byo",	"びょ"  },
	{"byu",	"びゅ"  },
	{"ca",	"か"	},
	{"cca",	"っか"	},
	{"cce",	"っせ"	},
	{"ccha","っちゃ"  },
	{"cche","っちぇ"  },
	{"cchi","っち" },
	{"ccho","っちょ"  },
	{"cchu","っちゅ"	},
	{"cci",	"っし"	},
	{"cco",	"っこ"	},
	{"ccu",	"っく"	},
	{"ccyi","っちぃ"  },
	{"ce",	"せ"	},
	{"cha",	"ちゃ"  },
	{"che",	"ちぇ"  },
	{"chi",	"ち"  },
	{"cho",	"ちょ" },
	{"chu",	"ちゅ"  },
	{"ci",	"し"	},
	{"co",	"こ"	},
	{"cu",	"く"	},
	{"cya",	"ちゃ" },
	{"cye",	"ちぇ"  },
	{"cyi",	"ちぃ"  },
	{"cyo",	"ちょ"  },
	{"cyu",	"ちゅ"  },
	{"da",	"だ"   },
	{"dda", "っだ" },
	{"dde", "っで" },
	{"ddha","っでぁ"  },
	{"ddhe","っでぇ"  },
	{"ddhi","っでぃ"  },
	{"ddho","っでょ"  },
	{"ddhu","っでゅ"	},
	{"ddi", "っぢ" },
	{"ddo", "っど" },
	{"ddu",	"っづ"	},
	{"de",	"で"   },
	{"dha", "でゃ" },
	{"dhe", "でぇ" },
	{"dhi", "でぃ" },
	{"dho", "でょ" },
	{"dhu", "でゅ" },
	{"di",	"ぢ"  },
	{"do",	"ど"  },
	{"du",	"づ"  },
	{"dwa",	"どぁ"	},
	{"dwe",	"どぇ"	},
	{"dwi",	"どぃ"	},
	{"dwo",	"どぉ"	},
	{"dwu",	"どぅ"	},
	{"dya",	"ぢゃ"	},
	{"dye",	"ぢぇ"	},
	{"dyi",	"ぢぃ"	},
	{"dyo",	"ぢょ"	},
	{"dyu",	"ぢゅ"	},
	{"e",	"え"  },
	{"fa",	"ふぁ"   },
	{"fe",	"ふぇ"   },
	{"ffa", "っふぁ"  },
	{"ffe", "っふぇ"  },
	{"ffi", "っふぃ"  },
	{"ffo", "っふぉ"  },
	{"ffu",	"っふ"	},
	{"ffyu","っふゅ"	},
	{"fi",	"ふぃ"   },
	{"fo",	"ふぉ"   },
	{"fu",	"ふ"  },
	{"fwa",	"ふぁ"	},
	{"fwe",	"ふぇ"	},
	{"fwi",	"ふぃ"	},
	{"fwo",	"ふぉ"	},
	{"fwu",	"ふぅ"	},
	{"fya",	"ふゃ"  },
	{"fye",	"ふぇ"  },
	{"fyi",	"ふぃ"  },
	{"fyo",	"ふょ" },
	{"fyu",	"ふゅ"  },
	{"ga",	"が"  },
	{"ge",	"げ"  },
	{"gga", "っが" },
	{"gge", "っげ" },
	{"ggha","っぐぁ"  },
	{"gghe","っぐぇ"  },
	{"gghi","っぐぃ"  },
	{"ggho","っぐぉ"  },
	{"gghu","っぐぅ"	},
	{"ggi", "っぎ" },
	{"ggo", "っご" },
	{"ggu",	"っぐ"	},
	{"ggya","っぎゃ"  },
	{"ggye","っぎぇ"  },
	{"ggyi","っぎぃ"  },
	{"ggyo","っぎょ"  },
	{"ggyu","っぎゅ"	},
	{"gi",	"ぎ"  },
	{"go",	"ご"  },
	{"gu",	"ぐ"  },
	{"gwa",	"ぐぁ"	},
	{"gwe",	"ぐぇ"	},
	{"gwi",	"ぐぃ"	},
	{"gwo",	"ぐぉ"	},
	{"gwu",	"ぐぅ"	},
	{"gya",	"ぎゃ"  },
	{"gye",	"ぎぇ"  },
	{"gyi",	"ぎぃ"  },
	{"gyo",	"ぎょ"  },
	{"gyu",	"ぎゅ"  },
	{"ha",	"は"  },
	{"he",	"へ"  },
	{"hha", "っは" },
	{"hhe", "っへ" },
	{"hhi", "っひ" },
	{"hho", "っほ" },
	{"hhu", "っふ" },
	{"hhya","っひゃ"  },
	{"hhye","っひぇ"  },
	{"hhyi","っひぃ"  },
	{"hhyo","っひょ"  },
	{"hhyu","っひゅ"	},
	{"hi",	"ひ"  },
	{"ho",	"ほ"  },
	{"hu",	"ふ"  },
	{"hya",	"ひゃ"  },
	{"hye",	"ひぇ"  },
	{"hyi",	"ひぃ"  },
	{"hyo",	"ひょ"  },
	{"hyu",	"ひゅ"  },
	{"i",	"い"  },
	{"ja",	"じゃ"   },
	{"je",	"じぇ"   },
	{"ji",	"じ"  },
	{"jja", "っじゃ"  },
	{"jje", "っじぇ" },
	{"jji", "っじ" },
	{"jjo", "っじょ"  },
	{"jju",	"っじゅ"	},
	{"jjye","っじぇ"  },
	{"jjyi","っじぃ"  },
	{"jo",	"じょ"   },
	{"ju",	"じゅ"   },
	{"jya",	"じゃ"	},
	{"jye",	"じぇ"	},
	{"jyi",	"じぃ"	},
	{"jyo",	"じょ"	},
	{"jyu",	"じゅ"	},
	{"ka",	"か" },
	{"ke",	"け" },
	{"ki",	"き" },
	{"kka", "っか" },
	{"kke", "っけ" },
	{"kkha","っくぁ"  },
	{"kkhe","っくぇ"  },
	{"kkhi","っくぃ"  },
	{"kkho","っくぉ"  },
	{"kkhu","っくぅ"	},
	{"kki", "っき" },
	{"kko", "っこ" },
	{"kku",	"っく"	},
	{"kkya","っきぁ"  },
	{"kkye","っきぇ"  },
	{"kkyi","っきぃ"  },
	{"kkyo","っきょ"  },
	{"kkyu","っきゅ"	},
	{"ko",	"こ" },
	{"ku",	"く" },
	{"kwa",	"くぁ"	},
	{"kya",	"きゃ"  },
	{"kye",	"きぇ"  },
	{"kyi",	"きぃ"  },
	{"kyo",	"きょ"  },
	{"kyu",	"きゅ"  },
	{"la",	"ぁ"	},
	{"le",	"ぇ"	},
	{"li",	"ぃ"	},
	{"lka",	"か"	},
	{"lke",	"け"	},
	{"lla",	"っぁ"	},
	{"lla",	"っぁ"	},
	{"lle",	"っぇ"	},
	{"lle",	"っぇ"	},
	{"lli",	"っぃ"	},
	{"lli",	"っぃ"	},
	{"llo",	"っぉ"	},
	{"llo",	"っぉ"	},
	{"llu",	"っぅ"	},
	{"llu",	"っぅ"	},
	{"lo",	"ぉ"	},
	{"ltsu","っ"	},
	{"ltu",	"っ"	},
	{"lu",	"ぅ"	},
	{"lwa",	"ゎ"	},
	{"lya",	"ゃ"	},
	{"lye",	"ぇ"	},
	{"lyi",	"ぃ"	},
	{"lyo",	"ょ"	},
	{"lyu",	"ゅ"	},
	{"ma",	"ま" },
	{"me",	"め" },
	{"mi",	"み" },
	{"mma", "っま" },
	{"mme", "っめ" },
	{"mmi", "っみ" },
	{"mmo", "っも" },
	{"mmu",	"っむ"	},
	{"mmya","っみゃ"  },
	{"mmye","っみぇ"  },
	{"mmyi","っみぃ"  },
	{"mmyo","っみょ"  },
	{"mmyu","っみゅ"	},
	{"mo",	"も" },
	{"mu",	"む" },
	{"mya",	"みゃ"  },
	{"mye",	"みぇ"  },
	{"myi",	"みぃ"  },
	{"myo",	"みょ"  },
	{"myu",	"みゅ"  },
	{"na",	"な" },
	{"nba",	"んば"	},
	{"nbe",	"んべ"	},
	{"nbi",	"んび"	},
	{"nbo",	"んぼ"	},
	{"nbu",	"んぶ"	},
	{"nca",	"んか"	},
	{"nce",	"んせ"	},
	{"nci",	"んし"	},
	{"nco",	"んこ"	},
	{"ncu",	"んく"	},
	{"nda",	"んだ"	},
	{"nde",	"んで"	},
	{"ndi",	"んぢ"	},
	{"ndo",	"んど"	},
	{"ndu",	"んづ"	},
	{"ne",	"ね" },
	{"nfa",	"んふぁ"	},
	{"nfe",	"んふぇ"	},
	{"nfi",	"んふぃ"	},
	{"nfo",	"んふぉ"	},
	{"nfu",	"んふ"	},
	{"nga",	"んが"	},
	{"nge",	"んげ"	},
	{"ngi",	"んぎ"	},
	{"ngo",	"んご"	},
	{"ngu",	"んぐ"	},
	{"nha",	"んは"	},
	{"nhe",	"んへ"	},
	{"nhi",	"んひ"	},
	{"nho",	"んほ"	},
	{"nhu",	"んふ"	},
	{"ni",	"に" },
	{"nja",	"んじゃ"	},
	{"nje",	"んじぇ"	},
	{"nji",	"なじ"	},
	{"njo",	"んじょ"	},
	{"nju",	"んじゅ"	},
	{"nka",	"んか"	},
	{"nke",	"んけ"	},
	{"nki",	"んき"	},
	{"nko",	"んこ"	},
	{"nku",	"んく"	},
	{"nla",	"んぁ"	},
	{"nle",	"んぇ"	},
	{"nli",	"んぃ"	},
	{"nlo",	"んぉ"	},
	{"nlu",	"んぅ"	},
	{"nma",	"んま"	},
	{"nme",	"んめ"	},
	{"nmi",	"んみ"	},
	{"nmo",	"んも"	},
	{"nmu",	"んむ"	},
	{"nn",	"ん" },
	{"nna",	"んあ"	},
	{"nne",	"んえ"	},
	{"nni",	"んい"	},
	{"nno",	"んお"	},
	{"nnu",	"んう"	},
	{"no",	"の" },
	{"npa",	"んぱ"	},
	{"npe",	"んぺ"	},
	{"npi",	"んぴ"	},
	{"npo",	"んぽ"	},
	{"npu",	"んぷ"	},
	{"nqa",	"んくぁ"	},
	{"nqe",	"んくぇ"	},
	{"nqi",	"んくぃ"	},
	{"nqo",	"んくぉ"	},
	{"nqu",	"んく"	},
	{"nra",	"んら"	},
	{"nre",	"んれ"	},
	{"nri",	"んり"	},
	{"nro",	"んろ"	},
	{"nru",	"んる"	},
	{"nsa",	"んさ"	},
	{"nse",	"んせ"	},
	{"nsi",	"んし"	},
	{"nso",	"んそ"	},
	{"nsu",	"んす"	},
	{"nta",	"んた"	},
	{"nte",	"んて"	},
	{"nti",	"んち"	},
	{"nto",	"んと"	},
	{"ntu",	"んつ"	},
	{"nu",	"ぬ" },
	{"nva",	"んヴぁ"	},
	{"nve",	"んヴぇ"	},
	{"nvi",	"んヴぃ"	},
	{"nvo",	"んヴぉ"	},
	{"nvu",	"んヴ"	},
	{"nwa",	"んわ"	},
	{"nwe",	"んうぇ"	},
	{"nwi",	"んうぃ"	},
	{"nwo",	"んを"	},
	{"nwu",	"んう"	},
	{"nxa",	"んぁ"	},
	{"nxe",	"んぇ"	},
	{"nxi",	"んぃ"	},
	{"nxo",	"んぉ"	},
	{"nxu",	"んぅ"	},
	{"nya",	"にゃ"  },
	{"nye",	"にぇ"  },
	{"nyi",	"にぃ"  },
	{"nyo",	"にょ"  },
	{"nyu",	"にゅ"  },
	{"nza",	"んざ"	},
	{"nze",	"んぜ"	},
	{"nzi",	"んじ"	},
	{"nzo",	"んぞ"	},
	{"nzu",	"んず"	},
	{"o",	"お" },
	{"pa",	"ぱ" },
	{"pe",	"ぺ" },
	{"pi",	"ぴ" },
	{"po",	"ぽ" },
	{"ppa", "っぱ" },
	{"ppe", "っぺ" },
	{"ppi", "っぴ" },
	{"ppo", "っぽ" },
	{"ppu",	"っぷ"	},
	{"ppya","っぴゃ"  },
	{"ppye","っぴぇ"  },
	{"ppyi","っぴぃ"  },
	{"ppyo","っぴょ"  },
	{"ppyu","っぴゅ"	},
	{"pu",	"ぷ" },
	{"pya",	"ぴゃ"  },
	{"pye",	"ぴぇ"  },
	{"pyi",	"ぴぃ"  },
	{"pyo",	"ぴょ"  },
	{"pyu",	"ぴゅ"  },
	{"qa",	"くぁ"	},
	{"qe",	"くぇ"	},
	{"qi",	"くぃ"	},
	{"qo",	"くぉ"	},
	{"qqa",	"っくぁ"	},
	{"qqe",	"っくぇ"	},
	{"qqi",	"っくぃ"	},
	{"qqo",	"っくぉ"	},
	{"qqu",	"っく"	},
	{"qu",	"く"	},
	{"qwa",	"くぁ"	},
	{"qwe",	"くぇ"	},
	{"qwi",	"くぃ"	},
	{"qwo",	"くぉ"	},
	{"qwu",	"くぅ"	},
	{"qya",	"くゃ"	},
	{"qye",	"くぇ"	},
	{"qyi",	"くぃ"	},
	{"qyo",	"くょ"	},
	{"qyu",	"くゅ"	},
	{"ra",	"ら" },
	{"re",	"れ" },
	{"ri",	"り" },
	{"ro",	"ろ" },
	{"rra", "っら" },
	{"rre", "っれ" },
	{"rri", "っり" },
	{"rro", "っろ" },
	{"rru",	"っる"	},
	{"rrya","っりゃ"  },
	{"rrye","っりぇ"  },
	{"rryi","っりぃ"  },
	{"rryo","っりょ"  },
	{"rryu","っりゅ"	},
	{"ru",	"る" },
	{"rya",	"りゃ"  },
	{"rye",	"りぇ"  },
	{"ryi",	"りぃ"  },
	{"ryo",	"りょ"  },
	{"ryu",	"りゅ"  },
	{"sa",	"さ" },
	{"se",	"せ" },
	{"sha",	"しゃ"	},
	{"she",	"しぇ"	},
	{"shi",	"し"  },
	{"sho",	"しょ"	},
	{"shu",	"しゅ"	},
	{"si",	"し"	},
	{"so",	"そ"   },
	{"ssa", "っさ" },
	{"sse", "っせ" },
	{"ssha","っしゃ"  },
	{"sshe","っしぇ"  },
	{"sshi","っし" },
	{"ssho","っしょ"  },
	{"sshu","っしゅ"	},
	{"ssi", "っし" },
	{"sso", "っそ" },
	{"ssu",	"っす"	},
	{"ssyi","っしぃ"  },
	{"su",	"す"   },
	{"swa",	"すぁ"	},
	{"swe",	"すぇ"	},
	{"swi",	"すぃ"	},
	{"swo",	"すぉ"	},
	{"swu",	"すぅ"	},
	{"sya",	"しゃ"	},
	{"sye",	"しぇ"	},
	{"syi",	"しぃ"	},
	{"syo",	"しょ"	},
	{"syu",	"しゅ"	},
	{"ta",	"た"  },
	{"te",	"て"  },
	{"tha","てゃ"  },
	{"the","てぇ"  },
	{"thi","てぃ"  },
	{"tho","てょ"  },
	{"thu","てゅ"	},
	{"ti",	"ち"  },
	{"to",	"と"  },
	{"tsa",	"つぁ"  },
	{"tse",	"つぇ"  },
	{"tsi",	"つぃ"  },
	{"tso",	"つぉ"  },
	{"tsu",	"つ"  },
	{"tta", "った" },
	{"tte", "って" },
	{"ttha","ってゃ"  },
	{"tthe","ってぇ"  },
	{"tthi","ってぃ"  },
	{"ttho","ってょ"  },
	{"tthu","ってゅ"	},
	{"tti", "っち" },
	{"tto", "っと" },
	{"tts", "っつ"  },
	{"ttsu","っつ"	},
	{"ttu", "っつ" },
	{"tu",	"つ"	},
	{"twa",	"とぁ"	},
	{"twe",	"とぇ"	},
	{"twi",	"とぃ"	},
	{"two",	"とぉ"	},
	{"twu",	"とぅ"	},
	{"tya",	"ちゃ"	},
	{"tye",	"ちぇ"	},
	{"tyi",	"ちぃ"	},
	{"tyo",	"ちょ"	},
	{"tyu",	"ちゅ"	},
	{"u",	"う"   },
	{"va",	"ヴぁ"	},
	{"ve",	"ヴぇ"	},
	{"vi",	"ヴい"	},
	{"vo",	"ヴぉ"	},
	{"vu",	"ヴ"  },
	{"vva", "っヴぁ"  },
	{"vve", "っヴぇ"  },
	{"vvi", "っヴぃ"  },
	{"vvo", "っヴぉ"  },
	{"vvu",	"っヴ"	},
	{"vya",	"ヴゃ"	},
	{"vye",	"ヴぇ"	},
	{"vyi",	"ヴぃ"	},
	{"vyo",	"ヴょ"	},
	{"vyu",	"ヴゅ"	},
	{"wa",	"わ"   },
	{"we",	"うぇ"	},
	{"wha",	"うぁ"	},
	{"whe",	"うぇ"	},
	{"whi",	"うぃ"	},
	{"who",	"うぉ"	},
	{"whu",	"う"	},
	{"wi",	"うぃ"	},
	{"wo",	"を"   },
	{"wu",	"う"   },
	{"wwa", "っわ" },
	{"wwe",	"っうぇ"	},
	{"wwe",	"っうぇ"	},
	{"wwha","っうぁ"  },
	{"wwhe","っうぇ"  },
	{"wwho","っうぉ"  },
	{"wwi",	"っうぃ"	},
	{"wwi", "っうぃ"  },
	{"wwo",	"っを"	},
	{"wwo",	"っを"	},
	{"wwu",	"っう"	},
	{"wwu",	"っう"	},
	{"xa",	"ぁ"	},
	{"xe",	"ぇ"	},
	{"xi",	"ぃ"	},
	{"xka",	"か"	},
	{"xke",	"け"	},
	{"xna",	"んあ"	},
	{"xne",	"んえ"	},
	{"xni",	"んい"	},
	{"xno",	"んお"	},
	{"xnu",	"んう"	},
	{"xo",	"ぉ"	},
	{"xtu",	"っ"	},
	{"xu",	"ぅ"	},
	{"xwa",	"ゎ"	},
	{"xxa",	"っぁ"	},
	{"xxe",	"っぇ"	},
	{"xxi",	"っぃ"	},
	{"xxo",	"っぉ"	},
	{"xxu",	"っぅ"	},
	{"xya",	"ゃ"	},
	{"xye",	"ぇ"	},
	{"xyi",	"ぃ"	},
	{"xyo",	"ょ"	},
	{"xyu",	"ゅ"	},
	{"ya",	"や"   },
	{"ye",	"いぇ"	},
	{"yi",	"い"   },
	{"yo",	"よ"   },
	{"yu",	"ゆ"   },
	{"yya", "っや" },
	{"yye",	"っいぇ"	},
	{"yye",	"っいぇ"	},
	{"yyi",	"っい"	},
	{"yyi",	"っい"	},
	{"yyo", "っよ" },
	{"yyu",	"っゆ"	},
	{"za",	"ざ"   },
	{"ze",	"ぜ"   },
	{"zi",	"じ"   },
	{"zo",	"ぞ"   },
	{"zu",	"ず"   },
	{"zya",	"じゃ"	},
	{"zye",	"じぇ"	},
	{"zyi",	"じぃ"	},
	{"zyo",	"じょ"	},
	{"zyu",	"じゅ"	},
	{"zza",	"っざ"	},
	{"zza", "っざ" },
	{"zze", "っぜ" },
	{"zzi", "っじ" },
	{"zzo", "っぞ" },
	{"zzu",	"っず"	},
};

struct _zh_jp_english_mapping {
	const char *hiragana;
	const char *english;
} zh_jp_english_mapping[] = {
	{"å",	 "a"},
	{"æ",	 "ae"},
	{"ø",	 "o"},
	{"‧",	"."},
	{"、",	",	"},
	{"。",	"."},
	{"ぁ",	"a"},
	{"あ",	"a"},
	{"ぃ",	"i"},
	{"い",	"i"},
	{"いぇ",	"ye"},
	{"ぅ",	"u"},
	{"う",	"u"},
	{"うぁ",	"wha"},
	{"うぃ",	"whi"},
	{"うぇ",	"whe"},
	{"うぉ",	"who"},
	{"ぇ",	"e"},
	{"え",	"e"},
	{"ぉ",	"o"},
	{"お",	"o"},
	{"か",	"ka"},
	{"が",	"ga"},
	{"き",	"ki"},
	{"きぃ",	"kyi"},
	{"きぇ",	"kye"},
	{"きゃ",	"kya"},
	{"きゅ",	"kyu"},
	{"きょ",	"kyo"},
	{"ぎ",	"gi"},
	{"ぎぃ",	"gyi"},
	{"ぎぇ",	"gye"},
	{"ぎゃ",	"gya"},
	{"ぎゅ",	"gyu"},
	{"ぎょ",	"gyo"},
	{"く",	"ku"},
	{"くぁ",	"kwa"},
	{"くぁ",	"qwa"},
	{"くぃ",	"qwi"},
	{"くぅ",	"qwu"},
	{"くぇ",	"qwe"},
	{"くぉ",	"qwo"},
	{"ぐ",	"gu"},
	{"ぐぁ",	"gwa"},
	{"ぐぃ",	"gwi"},
	{"ぐぅ",	"gwu"},
	{"ぐぇ",	"gwe"},
	{"ぐぉ",	"gwo"},
	{"け",	"ke"},
	{"げ",	"ge"},
	{"こ",	"ko"},
	{"ご",	"go"},
	{"さ",	"sa"},
	{"ざ",	"za"},
	{"し",	"shi"},
	{"しぃ",	"syi"},
	{"しぇ",	"sye"},
	{"しゃ",	"sya"},
	{"しゅ",	"syu"},
	{"しょ",	"syo"},
	{"じ",	"ji"},
	{"じぃ",	"jyi"},
	{"じぇ",	"je"},
	{"じゃ",	"ja"},
	{"じゅ",	"ju"},
	{"じょ",	"jo"},
	{"す",	"su"},
	{"ず",	"zu"},
	{"せ",	"se"},
	{"ぜ",	"ze"},
	{"そ",	"so"},
	{"ぞ",	"zo"},
	{"た",	"ta"},
	{"だ",	"da"},
	{"ち",	"chi"},
	{"ちぃ",	"cyi"},
	{"ちぇ",	"che"},
	{"ちぇ",	"cye"},
	{"ちゃ",	"cya"},
	{"ちゅ",	"cyu"},
	{"ちょ",	"cyo"},
	{"ぢ",	"di"},
	{"ぢぃ",	"dyi"},
	{"ぢぇ",	"dye"},
	{"ぢゃ",	"dya"},
	{"ぢゅ",	"dyu"},
	{"ぢょ",	"dyo"},
	{"っ",	"tsu"},
	{"っ",	"tsu"},
	{"っうぁ",	"wwha"},
	{"っうぃ",	"wwi"},
	{"っうぇ",	"wwhe"},
	{"っうぉ",	"wwho"},
	{"っか",	"kka"},
	{"っが",	"gga"},
	{"っき",	"kki"},
	{"っきぁ",	"kkya"},
	{"っきぃ",	"kkyi"},
	{"っきぇ",	"kkye"},
	{"っきゅ",	"kkyu"},
	{"っきょ",	"kkyo"},
	{"っぎ",	"ggi"},
	{"っぎぃ",	"ggyi"},
	{"っぎぇ",	"ggye"},
	{"っぎゃ",	"ggya"},
	{"っぎゅ",	"ggyu"},
	{"っぎょ",	"ggyo"},
	{"っく",	"kku"},
	{"っくぁ",	"kkha"},
	{"っくぃ",	"kkhi"},
	{"っくぅ",	"kkhu"},
	{"っくぇ",	"kkhe"},
	{"っくぉ",	"kkho"},
	{"っぐ",	"ggu"},
	{"っぐぁ",	"ggha"},
	{"っぐぃ",	"gghi"},
	{"っぐぅ",	"gghu"},
	{"っぐぇ",	"gghe"},
	{"っぐぉ",	"ggho"},
	{"っけ",	"kke"},
	{"っげ",	"gge"},
	{"っこ",	"kko"},
	{"っご",	"ggo"},
	{"っさ",	"ssa"},
	{"っざ",	"zza"},
	{"っし",	"sshi"},
	{"っしぃ",	"ssyi"},
	{"っしぇ",	"sshe"},
	{"っしゃ",	"ssha"},
	{"っしゅ",	"sshu"},
	{"っしょ",	"ssho"},
	{"っじ",	"jji"},
	{"っじぃ",	"jjyi"},
	{"っじぇ",	"jjye"},
	{"っじゃ",	"jja"},
	{"っじゅ",	"jju"},
	{"っじょ",	"jjo"},
	{"っす",	"ssu"},
	{"っず",	"zzu"},
	{"っせ",	"sse"},
	{"っぜ",	"zze"},
	{"っそ",	"sso"},
	{"っぞ",	"zzo"},
	{"った",	"tta"},
	{"っだ",	"dda"},
	{"っち",	"cchi"},
	{"っちぃ",	"ccyi"},
	{"っちぇ",	"cche"},
	{"っちゃ",	"ccha"},
	{"っちゅ",	"cchu"},
	{"っちょ",	"ccho"},
	{"っつ",	"tts"},
	{"っつ",	"ttsu"},
	{"っづ",	"ddu"},
	{"って",	"tte"},
	{"ってぃ",	"tthi"},
	{"ってぇ",	"tthe"},
	{"ってゃ",	"ttha"},
	{"ってゅ",	"tthu"},
	{"ってょ",	"ttho"},
	{"っで",	"dde"},
	{"っでぁ",	"ddha"},
	{"っでぃ",	"ddhi"},
	{"っでぇ",	"ddhe"},
	{"っでゅ",	"ddhu"},
	{"っでょ",	"ddho"},
	{"っと",	"tto"},
	{"っど",	"ddo"},
	{"っは",	"hha"},
	{"っば",	"bba"},
	{"っぱ",	"ppa"},
	{"っひ",	"hhi"},
	{"っひぃ",	"hhyi"},
	{"っひぇ",	"hhye"},
	{"っひゃ",	"hhya"},
	{"っひゅ",	"hhyu"},
	{"っひょ",	"hhyo"},
	{"っび",	"bbi"},
	{"っびぃ",	"bbyi"},
	{"っびぇ",	"bbye"},
	{"っびゃ",	"bbya"},
	{"っびゅ",	"bbyu"},
	{"っびょ",	"bbyo"},
	{"っぴ",	"ppi"},
	{"っぴぃ",	"ppyi"},
	{"っぴぇ",	"ppye"},
	{"っぴゃ",	"ppya"},
	{"っぴゅ",	"ppyu"},
	{"っぴょ",	"ppyo"},
	{"っふ",	"ffu"},
	{"っふ",	"ffu"},
	{"っふぁ",	"ffa"},
	{"っふぃ",	"ffi"},
	{"っふぇ",	"ffe"},
	{"っふぉ",	"ffo"},
	{"っふゅ",	"ffyu"},
	{"っぶ",	"bbu"},
	{"っぷ",	"ppu"},
	{"っへ",	"hhe"},
	{"っべ",	"bbe"},
	{"っぺ",	"ppe"},
	{"っほ",	"hho"},
	{"っぼ",	"bbo"},
	{"っぽ",	"ppo"},
	{"っま",	"mma"},
	{"っみ",	"mmi"},
	{"っみぃ",	"mmyi"},
	{"っみぇ",	"mmye"},
	{"っみゃ",	"mmya"},
	{"っみゅ",	"mmyu"},
	{"っみょ",	"mmyo"},
	{"っむ",	"mmu"},
	{"っめ",	"mme"},
	{"っも",	"mmo"},
	{"っや",	"yya"},
	{"っゆ",	"yyu"},
	{"っよ",	"yyo"},
	{"っら",	"rra"},
	{"っり",	"rri"},
	{"っりぃ",	"rryi"},
	{"っりぇ",	"rrye"},
	{"っりゃ",	"rrya"},
	{"っりゅ",	"rryu"},
	{"っりょ",	"rryo"},
	{"っる",	"rru"},
	{"っる",	"rru"},
	{"っれ",	"rre"},
	{"っろ",	"rro"},
	{"っわ",	"wwa"},
	{"っヂ",	"ddi"},
	{"っヴ",	"vvu"},
	{"っヴぁ",	"vva"},
	{"っヴぃ",	"vvi"},
	{"っヴぇ",	"vve"},
	{"っヴぉ",	"vvo"},
	{"つ",	"tsu"},
	{"つぁ",	"tsa"},
	{"つぃ",	"tsi"},
	{"つぇ",	"tse"},
	{"つぉ",	"tso"},
	{"づ",	"du"},
	{"て",	"te"},
	{"で",	"de"},
	{"でぃ",	"dhi"},
	{"でぇ",	"dhe"},
	{"でゃ",	"dha"},
	{"でゅ",	"dhu"},
	{"でょ",	"dho"},
	{"と",	"to"},
	{"とぁ",	"twa"},
	{"とぃ",	"twi"},
	{"とぅ",	"twu"},
	{"とぇ",	"twe"},
	{"とぉ",	"two"},
	{"ど",	"do"},
	{"な",	"na"},
	{"に",	"ni"},
	{"にぃ",	"nyi"},
	{"にぇ",	"nye"},
	{"にゃ",	"nya"},
	{"にゅ",	"nyu"},
	{"にょ",	"nyo"},
	{"ぬ",	"nu"},
	{"ね",	"ne"},
	{"の",	"no"},
	{"は",	"ha"},
	{"ば",	"ba"},
	{"ぱ",	"pa"},
	{"ひ",	"hi"},
	{"ひぃ",	"hyi"},
	{"ひぇ",	"hye"},
	{"ひゃ",	"hya"},
	{"ひゅ",	"hyu"},
	{"ひょ",	"hyo"},
	{"び",	"bi"},
	{"びぃ",	"byi"},
	{"びぇ",	"bye"},
	{"びゃ",	"bya"},
	{"びゅ",	"byu"},
	{"びょ",	"byo"},
	{"ぴ",	"pi"},
	{"ぴぃ",	"pyi"},
	{"ぴぇ",	"pye"},
	{"ぴゃ",	"pya"},
	{"ぴゅ",	"pyu"},
	{"ぴょ",	"pyo"},
	{"ふ",	"fu"},
	{"ふぁ",	"fa"},
	{"ふぃ",	"fi"},
	{"ふぇ",	"fe"},
	{"ふぉ",	"fo"},
	{"ふゅ",	"fyu"},
	{"ふょ",	"fyo"},
	{"ぶ",	"bu"},
	{"ぷ",	"pu"},
	{"へ",	"he"},
	{"べ",	"be"},
	{"ぺ",	"pe"},
	{"ほ",	"ho"},
	{"ぼ",	"bo"},
	{"ぽ",	"po"},
	{"ま",	"ma"},
	{"み",	"mi"},
	{"みぃ",	"myi"},
	{"みぇ",	"mye"},
	{"みゃ",	"mya"},
	{"みゅ",	"myu"},
	{"みょ",	"myo"},
	{"む",	"mu"},
	{"め",	"me"},
	{"も",	"mo"},
	{"ゃ",	"ya"},
	{"や",	"ya"},
	{"ゅ",	"yu"},
	{"ゆ",	"yu"},
	{"ょ",	"yo"},
	{"よ",	"yo"},
	{"ら",	"ra"},
	{"り",	"ri"},
	{"りぃ",	"ryi"},
	{"りぇ",	"rye"},
	{"りゃ",	"rya"},
	{"りゅ",	"ryu"},
	{"りょ",	"ryo"},
	{"る",	"ru"},
	{"れ",	"re"},
	{"ろ",	"ro"},
	{"ゎ",	"wa"},
	{"わ",	"wa"},
	{"を",	"wo"},
	{"ん",	"nn"},
	{"ヴ",	"vu"},
	{"ー",	"-"},
	{"ㄅ",	"b"},
	{"ㄅㄧ",	"bi"},
	{"ㄅㄧㄝ",	"bie"},
	{"ㄅㄧㄠ",	"biao"},
	{"ㄅㄧㄢ",	"bian"},
	{"ㄅㄧㄣ",	"bin"},
	{"ㄅㄧㄥ",	"bing"},
	{"ㄅㄨ",	"bu"},
	{"ㄆ",	"p"},
	{"ㄆㄧ",	"pi"},
	{"ㄆㄧㄝ",	"pie"},
	{"ㄆㄧㄠ",	"piao"},
	{"ㄆㄧㄢ",	"pian"},
	{"ㄆㄧㄣ",	"pin"},
	{"ㄆㄧㄥ",	"ping"},
	{"ㄆㄨ",	"pu"},
	{"ㄇ",	"m"},
	{"ㄇㄧ",	"mi"},
	{"ㄇㄧㄝ",	"mie"},
	{"ㄇㄧㄠ",	"miao"},
	{"ㄇㄧㄡ",	"miu"},
	{"ㄇㄧㄢ",	"mian"},
	{"ㄇㄧㄣ",	"min"},
	{"ㄇㄧㄥ",	"ming"},
	{"ㄇㄨ",	"mu"},
	{"ㄈ",	"f"},
	{"ㄈㄨ",	"fu"},
	{"ㄉ",	"d"},
	{"ㄉㄧ",	"di"},
	{"ㄉㄧㄝ",	"die"},
	{"ㄉㄧㄠ",	"diao"},
	{"ㄉㄧㄡ",	"diu"},
	{"ㄉㄧㄢ",	"dian"},
	{"ㄉㄧㄤ",	"diang"},
	{"ㄉㄧㄥ",	"ding"},
	{"ㄉㄨ",	"du"},
	{"ㄉㄨㄛ",	"duo"},
	{"ㄉㄨㄟ",	"dui"},
	{"ㄉㄨㄢ",	"duan"},
	{"ㄉㄨㄣ",	"dun"},
	{"ㄉㄨㄥ",	"dong"},
	{"ㄊ",	"t"},
	{"ㄊㄧ",	"ti"},
	{"ㄊㄧㄝ",	"tie"},
	{"ㄊㄧㄠ",	"tiao"},
	{"ㄊㄧㄢ",	"tian"},
	{"ㄊㄧㄥ",	"ting"},
	{"ㄊㄨ",	"tu"},
	{"ㄊㄨㄛ",	"tuo"},
	{"ㄊㄨㄟ",	"tui"},
	{"ㄊㄨㄢ",	"tuan"},
	{"ㄊㄨㄣ",	"tun"},
	{"ㄊㄨㄥ",	"tong"},
	{"ㄋ",	"n"},
	{"ㄋㄧ",	"ni"},
	{"ㄋㄧㄚ",	"nia"},
	{"ㄋㄧㄝ",	"nie"},
	{"ㄋㄧㄠ",	"niao"},
	{"ㄋㄧㄡ",	"niu"},
	{"ㄋㄧㄢ",	"nian"},
	{"ㄋㄧㄣ",	"nin"},
	{"ㄋㄧㄤ",	"niang"},
	{"ㄋㄧㄥ",	"ning"},
	{"ㄋㄨ",	"nu"},
	{"ㄋㄨㄛ",	"nuo"},
	{"ㄋㄨㄢ",	"nuan"},
	{"ㄋㄨㄣ",	"nun"},
	{"ㄋㄨㄥ",	"nong"},
	{"ㄋㄩ",	"nv"},
	{"ㄋㄩㄝ",	"nue"},
	{"ㄌ",	"l"},
	{"ㄌㄧ",	"li"},
	{"ㄌㄧㄚ",	"lia"},
	{"ㄌㄧㄝ",	"lie"},
	{"ㄌㄧㄠ",	"liao"},
	{"ㄌㄧㄡ",	"liu"},
	{"ㄌㄧㄢ",	"lian"},
	{"ㄌㄧㄣ",	"lin"},
	{"ㄌㄧㄤ",	"liang"},
	{"ㄌㄧㄥ",	"ling"},
	{"ㄌㄨ",	"lu"},
	{"ㄌㄨㄛ",	"luo"},
	{"ㄌㄨㄢ",	"luan"},
	{"ㄌㄨㄣ",	"lun"},
	{"ㄌㄨㄥ",	"long"},
	{"ㄌㄩ",	"lv"},
	{"ㄌㄩㄝ",	"lue"},
	{"ㄌㄩㄢ",	"luan"},
	{"ㄌㄩㄣ",	"lun"},
	{"ㄍ",	"g"},
	{"ㄍㄨ",	"gu"},
	{"ㄍㄨㄚ",	"gua"},
	{"ㄍㄨㄛ",	"guo"},
	{"ㄍㄨㄞ",	"guai"},
	{"ㄍㄨㄟ",	"gui"},
	{"ㄍㄨㄢ",	"guan"},
	{"ㄍㄨㄣ",	"gun"},
	{"ㄍㄨㄤ",	"guang"},
	{"ㄍㄨㄥ",	"gong"},
	{"ㄎ",	"k"},
	{"ㄎㄨ",	"ku"},
	{"ㄎㄨㄚ",	"kua"},
	{"ㄎㄨㄛ",	"kuo"},
	{"ㄎㄨㄞ",	"kuai"},
	{"ㄎㄨㄟ",	"kui"},
	{"ㄎㄨㄢ",	"kuan"},
	{"ㄎㄨㄣ",	"kun"},
	{"ㄎㄨㄤ",	"kuang"},
	{"ㄎㄨㄥ",	"kong"},
	{"ㄏ",	"h"},
	{"ㄏㄨ",	"hu"},
	{"ㄏㄨㄚ",	"hua"},
	{"ㄏㄨㄛ",	"huo"},
	{"ㄏㄨㄞ",	"huai"},
	{"ㄏㄨㄟ",	"hui"},
	{"ㄏㄨㄢ",	"huan"},
	{"ㄏㄨㄣ",	"hun"},
	{"ㄏㄨㄤ",	"huang"},
	{"ㄏㄨㄥ",	"hong"},
	{"ㄐ",	"j"},
	{"ㄐㄧ",	"ji"},
	{"ㄐㄧㄚ",	"jia"},
	{"ㄐㄧㄝ",	"jie"},
	{"ㄐㄧㄠ",	"jiao"},
	{"ㄐㄧㄡ",	"jiu"},
	{"ㄐㄧㄢ",	"jian"},
	{"ㄐㄧㄣ",	"jin"},
	{"ㄐㄧㄤ",	"jiang"},
	{"ㄐㄧㄥ",	"jing"},
	{"ㄐㄩ",	"ju"},
	{"ㄐㄩㄝ",	"jue"},
	{"ㄐㄩㄢ",	"juan"},
	{"ㄐㄩㄣ",	"jun"},
	{"ㄐㄩㄥ",	"jiong"},
	{"ㄑ",	"q"},
	{"ㄑㄧ",	"qi"},
	{"ㄑㄧㄚ",	"qia"},
	{"ㄑㄧㄝ",	"qie"},
	{"ㄑㄧㄠ",	"qiao"},
	{"ㄑㄧㄡ",	"qiu"},
	{"ㄑㄧㄢ",	"qian"},
	{"ㄑㄧㄣ",	"qin"},
	{"ㄑㄧㄤ",	"qiang"},
	{"ㄑㄧㄥ",	"qing"},
	{"ㄑㄩ",	"qu"},
	{"ㄑㄩㄝ",	"que"},
	{"ㄑㄩㄢ",	"quan"},
	{"ㄑㄩㄣ",	"qun"},
	{"ㄑㄩㄥ",	"qiong"},
	{"ㄒ",	"x"},
	{"ㄒㄧ",	"xi"},
	{"ㄒㄧㄚ",	"xia"},
	{"ㄒㄧㄝ",	"xie"},
	{"ㄒㄧㄠ",	"xiao"},
	{"ㄒㄧㄡ",	"xiu"},
	{"ㄒㄧㄢ",	"xian"},
	{"ㄒㄧㄣ",	"xin"},
	{"ㄒㄧㄤ    ",	"xiang"},
	{"ㄒㄧㄥ",	"xing"},
	{"ㄒㄩ",	"xu"},
	{"ㄒㄩㄝ",	"xue"},
	{"ㄒㄩㄢ",	"xuan"},
	{"ㄒㄩㄣ",	"xun"},
	{"ㄒㄩㄥ",	"xiong"},
	{"ㄓ",	"zhi"},
	{"ㄓㄚ",	"zha"},
	{"ㄓㄜ",	"zhe"},
	{"ㄓㄞ",	"zhai"},
	{"ㄓㄟ",	"zhei"},
	{"ㄓㄠ",	"zhao"},
	{"ㄓㄡ",	"zhou"},
	{"ㄓㄢ",	"zhan"},
	{"ㄓㄣ",	"zhen"},
	{"ㄓㄤ",	"zhang"},
	{"ㄓㄥ",	"zheng"},
	{"ㄓㄨ",	"zhu"},
	{"ㄓㄨㄚ",	"zhua"},
	{"ㄓㄨㄛ",	"zhuo"},
	{"ㄓㄨㄞ",	"zhuai"},
	{"ㄓㄨㄟ",	"zhui"},
	{"ㄓㄨㄢ",	"zhuan"},
	{"ㄓㄨㄣ",	"zhun"},
	{"ㄓㄨㄤ",	"zhuang"},
	{"ㄓㄨㄥ",	"zhong"},
	{"ㄔ",	"chi"},
	{"ㄔㄚ",	"cha"},
	{"ㄔㄜ",	"che"},
	{"ㄔㄞ",	"chai"},
	{"ㄔㄠ",	"chao"},
	{"ㄔㄡ",	"chou"},
	{"ㄔㄢ",	"chan"},
	{"ㄔㄣ",	"chen"},
	{"ㄔㄤ",	"chang"},
	{"ㄔㄥ",	"cheng"},
	{"ㄔㄨ",	"chu"},
	{"ㄔㄨㄚ",	"chua"},
	{"ㄔㄨㄛ",	"chuo"},
	{"ㄔㄨㄞ",	"chuai"},
	{"ㄔㄨㄟ",	"chui"},
	{"ㄔㄨㄢ",	"chuan"},
	{"ㄔㄨㄣ",	"chun"},
	{"ㄔㄨㄤ",	"chuang"},
	{"ㄔㄨㄥ",	"chong"},
	{"ㄕ",	"shi"},
	{"ㄕㄚ",	"sha"},
	{"ㄕㄜ",	"she"},
	{"ㄕㄞ",	"shai"},
	{"ㄕㄟ",	"shei"},
	{"ㄕㄠ",	"shao"},
	{"ㄕㄡ",	"shou"},
	{"ㄕㄢ",	"shan"},
	{"ㄕㄣ",	"shen"},
	{"ㄕㄤ",	"shang"},
	{"ㄕㄥ",	"sheng"},
	{"ㄕㄨ",	"shu"},
	{"ㄕㄨㄚ",	"shua"},
	{"ㄕㄨㄛ",	"shuo"},
	{"ㄕㄨㄞ",	"shuai"},
	{"ㄕㄨㄟ",	"shui"},
	{"ㄕㄨㄢ",	"shuan"},
	{"ㄕㄨㄣ",	"shun"},
	{"ㄕㄨㄤ",	"shuang"},
	{"ㄕㄨㄥ",	"shong"},
	{"ㄖ",	"ri"},
	{"ㄖㄜ",	"re"},
	{"ㄖㄠ",	"rao"},
	{"ㄖㄡ",	"rou"},
	{"ㄖㄢ",	"ran"},
	{"ㄖㄣ",	"ren"},
	{"ㄖㄤ",	"rang"},
	{"ㄖㄥ",	"reng"},
	{"ㄖㄨ",	"ru"},
	{"ㄖㄨㄛ",	"ruo"},
	{"ㄖㄨㄟ",	"rui"},
	{"ㄖㄨㄢ",	"ruan"},
	{"ㄖㄨㄣ",	"run"},
	{"ㄖㄨㄥ",	"rong"},
	{"ㄗ",	"zi"},
	{"ㄗㄚ",	"za"},
	{"ㄗㄜ",	"ze"},
	{"ㄗㄞ",	"zai"},
	{"ㄗㄟ",	"zei"},
	{"ㄗㄠ",	"zao"},
	{"ㄗㄡ",	"zou"},
	{"ㄗㄢ",	"zan"},
	{"ㄗㄣ",	"zen"},
	{"ㄗㄤ",	"zang"},
	{"ㄗㄥ",	"zeng"},
	{"ㄗㄨ",	"zu"},
	{"ㄗㄨㄛ",	"zuo"},
	{"ㄗㄨㄟ",	"zui"},
	{"ㄗㄨㄢ",	"zuan"},
	{"ㄗㄨㄣ",	"zun"},
	{"ㄗㄨㄥ",	"zong"},
	{"ㄘ",	"ci"},
	{"ㄘㄚ",	"ca"},
	{"ㄘㄜ",	"ce"},
	{"ㄘㄞ",	"cai"},
	{"ㄘㄠ",	"cao"},
	{"ㄘㄡ",	"cou"},
	{"ㄘㄢ",	"can"},
	{"ㄘㄣ",	"cen"},
	{"ㄘㄤ",	"cang"},
	{"ㄘㄥ",	"ceng"},
	{"ㄘㄨ",	"cu"},
	{"ㄘㄨㄛ",	"cuo"},
	{"ㄘㄨㄟ",	"cui"},
	{"ㄘㄨㄢ",	"cuan"},
	{"ㄘㄨㄣ",	"cun"},
	{"ㄘㄨㄥ",	"cong"},
	{"ㄙ",	"s"},
	{"ㄙㄨ",	"su"},
	{"ㄙㄨㄛ",	"suo"},
	{"ㄙㄨㄟ",	"sui"},
	{"ㄙㄨㄢ",	"suan"},
	{"ㄙㄨㄣ",	"sun"},
	{"ㄙㄨㄥ",	"song"},
	{"ㄚ",	"a"},
	{"ㄛ",	"o"},
	{"ㄜ",	"e"},
	{"ㄝ",	"e"},
	{"ㄞ",	"ai"},
	{"ㄟ",	"ei"},
	{"ㄠ",	"ao"},
	{"ㄡ",	"ou"},
	{"ㄢ",	"an"},
	{"ㄣ",	"en"},
	{"ㄤ",	"ang"},
	{"ㄥ",	"eng"},
	{"ㄦ",	"er"},
	{"ㄧ",	"yi"},
	{"ㄧㄚ",	"ya"},
	{"ㄧㄝ",	"ye"},
	{"ㄧㄠ",	"yao"},
	{"ㄧㄡ",	"you"},
	{"ㄧㄢ",	"yan"},
	{"ㄧㄣ",	"yin"},
	{"ㄧㄤ",	"yang"},
	{"ㄧㄥ",	"ying"},
	{"ㄨ",	"wu"},
	{"ㄨㄚ",	"wa"},
	{"ㄨㄛ",	"wo"},
	{"ㄨㄞ",	"wai"},
	{"ㄨㄟ",	"wei"},
	{"ㄨㄢ",	"wan"},
	{"ㄨㄣ",	"wen"},
	{"ㄨㄤ",	"wang"},
	{"ㄨㄥ",	"weng"},
	{"ㄩ",	"yu"},
	{"ㄩㄝ",	"yue"},
	{"ㄩㄢ",	"yuan"},
	{"ㄩㄣ",	"yun"},
	{"ㄩㄥ",	"yong"},
	{"，",   ","},
	{"－",	"-"},
	{"ａ",	"a"},
	{"ｂ",	"b"},
	{"ｃ",	"c"},
	{"ｄ",	"d"},
	{"ｅ",	"e"},
	{"ｆ",	"f"},
	{"ｇ",	"g"},
	{"ｈ",	"h"},
	{"ｉ",	"i"},
	{"ｊ",	"j"},
	{"ｋ",	"k"},
	{"ｌ",	"l"},
	{"ｍ",	"m"},
	{"ｎ",	"n"},
	{"ｏ",	"o"},
	{"ｐ",	"p"},
	{"ｑ",	"q"},
	{"ｒ",	"r"},
	{"ｓ",	"s"},
	{"ｔ",	"t"},
	{"ｕ",	"u"},
	{"ｖ",	"v"},
	{"ｗ",	"w"},
	{"ｘ",	"x"},
	{"ｙ",	"y"},
	{"ｚ",	"z"},
};

struct _sonant_conversion {
	const char *origin;
	const char *after_conversion;
} sonant_conversion[] = {
	{"ぁ" , "あ" },
	{"あ" , "ぁ" },
	{"ぃ" , "い" },
	{"い" , "ぃ" },
	{"ぅ" , "ヴ" },
	{"う" , "ぅ" },
	{"ぇ" , "え" },
	{"え" , "ぇ" },
	{"ぉ" , "お" },
	{"お" , "ぉ" },
	{"か" , "が" },
	{"が" , "か" },
	{"き" , "ぎ" },
	{"ぎ" , "き" },
	{"く" , "ぐ" },
	{"ぐ" , "く" },
	{"け" , "げ" },
	{"げ" , "け" },
	{"こ" , "ご" },
	{"ご" , "こ" },
	{"さ" , "ざ" },
	{"ざ" , "さ" },
	{"し" , "じ" },
	{"じ" , "し" },
	{"す" , "ず" },
	{"ず" , "す" },
	{"せ" , "ぜ" },
	{"ぜ" , "せ" },
	{"そ" , "ぞ" },
	{"ぞ" , "そ" },
	{"た" , "だ" },
	{"だ" , "た" },
	{"ち" , "ぢ" },
	{"ぢ" , "ち" },
	{"っ" , "づ" },
	{"つ" , "っ" },
	{"づ" , "つ" },
	{"て" , "で" },
	{"で" , "て" },
	{"と" , "ど" },
	{"ど" , "と" },
	{"は" , "ば" },
	{"ば" , "ぱ" },
	{"ぱ" , "は" },
	{"ひ" , "び" },
	{"び" , "ぴ" },
	{"ぴ" , "ひ" },
	{"ふ" , "ぶ" },
	{"ぶ" , "ぷ" },
	{"ぷ" , "ふ" },
	{"へ" , "べ" },
	{"べ" , "ぺ" },
	{"ぺ" , "へ" },
	{"ほ" , "ぼ" },
	{"ぼ" , "ぽ" },
	{"ぽ" , "ほ" },
	{"ゃ" , "や" },
	{"や" , "ゃ" },
	{"ゅ" , "ゆ" },
	{"ゆ" , "ゅ" },
	{"ょ" , "よ" },
	{"よ" , "ょ" },
	{"ゎ" , "わ" },
	{"わ" , "ゎ" },
	{"ヴ" , "う" },
};

struct _backward_key_sequence {
	const char *origin;
	const char *after_conversion;
} backward_key_sequence[] = {
	{"!", "?" },
	{"#", "@" },
	{"$", "#" },
	{"%", "$" },
	{"&", "%" },
	{"'", ")" },
	{"(", "'" },
	{")", "(" },
	{"*", "－" },
	{"+", "=" },
	{"=", "*" },
	{"?", "。" },
	{"@", "&" },
	{"、", "!" },
	{"。", "、" },
	{"ぁ" , "お" },
	{"あ" , "ぉ" },
	{"ぃ" , "ぁ"  },
	{"い" , "あ"  },
	{"ぅ" , "ぃ"  },
	{"う" , "い"  },
	{"ぇ" , "ぅ"  },
	{"え" , "う"  },
	{"ぉ" , "ぇ"  },
	{"お" , "え"  },
	{"か" , "こ"  },
	{"き" , "か"  },
	{"く" , "き"  },
	{"け" , "く"  },
	{"こ" , "け"  },
	{"さ" , "そ"  },
	{"し" , "さ"  },
	{"す" , "し"  },
	{"せ" , "す"  },
	{"そ" , "せ"  },
	{"た" , "っ"  },
	{"ち" , "た"  },
	{"っ" , "と"  },
	{"つ" , "ち"  },
	{"て" , "つ"  },
	{"と" , "て"  },
	{"な" , "の"  },
	{"に" , "な"  },
	{"ぬ" , "に"  },
	{"ね" , "ぬ"  },
	{"の" , "ね"  },
	{"は" , "ほ"  },
	{"ひ" , "は"  },
	{"ふ" , "ひ"  },
	{"へ" , "ふ"  },
	{"ほ" , "へ"  },
	{"ま" , "も"  },
	{"み" , "ま"  },
	{"む" , "み"  },
	{"め" , "む"  },
	{"も" , "め"  },
	{"ゃ" , "よ"  },
	{"や" , "ょ"  },
	{"ゅ" , "ゃ"  },
	{"ゆ" , "や"  },
	{"ょ" , "ゅ"  },
	{"よ" , "ゆ"  },
	{"ら" , "ろ"  },
	{"り" , "ら"  },
	{"る" , "り"  },
	{"れ" , "る"  },
	{"ろ" , "れ"  },
	{"ゎ" , "ん"  },
	{"わ" , "ー"  },
	{"を" , "わ"  },
	{"ん" , "を"  },
	{"ー" , "ゎ"  },
	{"ㄅ" , "ㄈ"  },
	{"ㄆ" , "ㄅ"  },
	{"ㄇ" , "ㄆ"  },
	{"ㄈ" , "ㄇ"  },
	{"ㄉ" , "ㄌ"  },
	{"ㄊ" , "ㄉ"  },
	{"ㄋ" , "ㄊ"  },
	{"ㄌ" , "ㄋ"  },
	{"ㄍ" , "ㄏ"  },
	{"ㄎ" , "ㄍ"  },
	{"ㄏ" , "ㄎ"  },
	{"ㄐ" , "ㄒ"  },
	{"ㄑ" , "ㄐ"  },
	{"ㄒ" , "ㄑ"  },
	{"ㄓ" , "ㄖ"  },
	{"ㄔ" , "ㄓ"  },
	{"ㄕ" , "ㄔ"  },
	{"ㄖ" , "ㄕ"  },
	{"ㄗ" , "ㄙ"  },
	{"ㄘ" , "ㄗ"  },
	{"ㄙ" , "ㄘ"  },
	{"ㄚ" , "ㄝ"  },
	{"ㄛ" , "ㄚ"  },
	{"ㄜ" , "ㄛ"  },
	{"ㄝ" , "ㄜ"  },
	{"ㄞ" , "ㄡ"  },
	{"ㄟ" , "ㄞ"  },
	{"ㄠ" , "ㄟ"  },
	{"ㄡ" , "ㄠ"  },
	{"ㄢ" , "ㄦ"  },
	{"ㄣ" , "ㄢ"  },
	{"ㄤ" , "ㄣ"  },
	{"ㄥ" , "ㄤ"  },
	{"ㄦ" , "ㄥ"  },
	{"ㄧ" , "ㄩ"  },
	{"ㄨ" , "ㄧ"  },
	{"ㄩ" , "ㄨ"  },
	{"－", "+" },
	{"ａ", "ｃ" },
	{"ｂ", "ａ" },
	{"ｃ", "ｂ" },
	{"ｄ", "ｆ" },
	{"ｅ", "ｄ" },
	{"ｆ", "ｅ" },
	{"ｇ", "ｉ" },
	{"ｈ", "ｇ" },
	{"ｉ", "ｈ" },
	{"ｊ", "ｌ" },
	{"ｋ", "ｊ" },
	{"ｌ", "ｋ" },
	{"ｍ", "ｏ" },
	{"ｎ", "ｍ" },
	{"ｏ", "ｎ" },
	{"ｐ", "ｓ" },
	{"ｑ", "ｐ" },
	{"ｒ", "ｑ" },
	{"ｓ", "ｒ" },
	{"ｔ", "ｖ" },
	{"ｕ", "ｔ" },
	{"ｖ", "ｕ" },
	{"ｗ", "ｚ" },
	{"ｘ", "ｗ" },
	{"ｙ", "ｘ" },
	{"ｚ", "ｙ" },
};

struct _korean_jamo {
	const char *english;
	const char *jamo;
} korean_jamo[] = {
	{"E", "ㄸ" },
	{"O", "ㅒ" },
	{"P", "ㅖ" },
	{"Q", "ㅃ" },
	{"R", "ㄲ" },
	{"T", "ㅆ" },
	{"W", "ㅉ" },
	{"a", "ㅁ" },
	{"b", "ㅠ" },
	{"c", "ㅊ" },
	{"d", "ㅇ" },
	{"e", "ㄷ" },
	{"f", "ㄹ" },
	{"g", "ㅎ" },
	{"h", "ㅗ" },
	{"i", "ㅑ" },
	{"j", "ㅓ" },
	{"k", "ㅏ" },
	{"l", "ㅣ" },
	{"m", "ㅡ" },
	{"n", "ㅜ" },
	{"o", "ㅐ" },
	{"p", "ㅔ" },
	{"q", "ㅂ" },
	{"r", "ㄱ" },
	{"s", "ㄴ" },
	{"t", "ㅅ" },
	{"u", "ㅕ" },
	{"v", "ㅍ" },
	{"w", "ㅈ" },
	{"x", "ㅌ" },
	{"y", "ㅛ" },
	{"z", "ㅋ" },
};

struct _korean_jamo_ex {
	const char *english;
	int jamo_idx;
	const char *jamo;
	const char *phonetic;
	const char *phonetic_name;
} korean_jamo_ex[] = {
	{"E",  INITIAL_JAMO_BASE+4,   	"ㄸ", "dd" , "ssangtikeut"  },
	{"O",  MEDIAL_JAMO_BASE+3 ,		"ㅒ", "yae", "yae"          },
	{"P",  MEDIAL_JAMO_BASE+7 ,		"ㅖ", "ye" , "ye"           },
	{"Q",  INITIAL_JAMO_BASE+8,   	"ㅃ", "bb" , "ssangpieup"   },
	{"R",  FINAL_JAMO_BASE+2 ,    	"ㄲ", "gg" , "ssangkiyeok"  },
	{"R",  INITIAL_JAMO_BASE+1,   	"ㄲ", "gg" , "ssangkiyeok"  },
	{"T",  FINAL_JAMO_BASE+20,    	"ㅆ", "ss" , "ssangsios"    },
	{"T",  INITIAL_JAMO_BASE+10,   	"ㅆ", "ss" , "ssangsios"    },
	{"W",  INITIAL_JAMO_BASE+13,   	"ㅉ", "jj" , "ssangcieuc"   },
	{"a",  FINAL_JAMO_BASE+16,    	"ㅁ", "m"  , "mieum"        },
	{"a",  INITIAL_JAMO_BASE+6,     "ㅁ", "m"  , "mieum"        },
	{"b",  MEDIAL_JAMO_BASE+17,		"ㅠ", "yu" , "yu"           },
	{"c",  FINAL_JAMO_BASE+23,    	"ㅊ", "c" , "chieuch"      },
	{"c",  INITIAL_JAMO_BASE+14,    "ㅊ", "c" , "chieuch"      },
	{"d",  FINAL_JAMO_BASE+21,    	"ㅇ", "ng" , "ieung"        },
	{"d",  INITIAL_JAMO_BASE+11,    "ㅇ", ""   , "ieung"        },
	{"e",  FINAL_JAMO_BASE+7 ,    	"ㄷ", "d"  , "tikeut"       },
	{"e",  INITIAL_JAMO_BASE+3,     "ㄷ", "d"  , "tikeut"       },
	{"ee", INITIAL_JAMO_BASE+4,		"ㄸ", "dd" , "ssangtikeut"  },
	{"f",  FINAL_JAMO_BASE+8 ,    	"ㄹ", "l"  , "rieul"        },
	{"f",  INITIAL_JAMO_BASE+5,     "ㄹ", "r"  , "rieul"        },
	{"fa", FINAL_JAMO_BASE+10,    	"ㄻ", "lm" , "rieul-mieum"  },
	{"fg", FINAL_JAMO_BASE+15,    	"ㅀ", "lh" , "rieul-hieuh"  },
	{"fq", FINAL_JAMO_BASE+11,    	"ㄼ", "lb" , "rieul-pieup"  },
	{"fr", FINAL_JAMO_BASE+9 ,    	"ㄺ", "lg" , "rieul-kiyeok" },
	{"ft", FINAL_JAMO_BASE+12,    	"ㄽ", "ls" , "rieul-sios"   },
	{"fv", FINAL_JAMO_BASE+14,    	"ㄿ", "lp" , "rieul-phieuph"},
	{"fx", FINAL_JAMO_BASE+13,    	"ㄾ", "lt" , "rieul-thieuth"},
	{"g",  FINAL_JAMO_BASE+27,      "ㅎ", "h"  , "hieuh"        },
	{"g",  INITIAL_JAMO_BASE+18,    "ㅎ", "h"  , "hieuh"        },
	{"h",  MEDIAL_JAMO_BASE+8 ,		"ㅗ", "o"  , "o"            },
	{"hk", MEDIAL_JAMO_BASE+9 ,		"ㅘ", "wa" , "wa"           },
	{"hl", MEDIAL_JAMO_BASE+11,		"ㅚ", "oe" , "oe"           },
	{"ho", MEDIAL_JAMO_BASE+10,		"ㅙ", "wae", "wae"          },
	{"i",  MEDIAL_JAMO_BASE+2 ,		"ㅑ", "ya" , "ya"           },
	{"j",  MEDIAL_JAMO_BASE+4 ,		"ㅓ", "eo" , "eo"           },
	{"k",  MEDIAL_JAMO_BASE,		"ㅏ", "a"  , "a"            },
	{"l",  MEDIAL_JAMO_BASE+20,		"ㅣ", "i"  , "i"            },
	{"m",  MEDIAL_JAMO_BASE+18,		"ㅡ", "eu" , "eu"           },
	{"ml", MEDIAL_JAMO_BASE+19,		"ㅢ", "yi" , "yi"           },
	{"n",  MEDIAL_JAMO_BASE+13,		"ㅜ", "u"  , "u"            },
	{"nj", MEDIAL_JAMO_BASE+14,		"ㅝ", "weo", "weo"          },
	{"nl", MEDIAL_JAMO_BASE+16,		"ㅟ", "wi" , "wi"           },
	{"np", MEDIAL_JAMO_BASE+15,		"ㅞ", "we" , "we"           },
	{"o",  MEDIAL_JAMO_BASE+1 ,		"ㅐ", "ae" , "ae"           },
	{"oo", MEDIAL_JAMO_BASE+3,		"ㅒ", "yae", "yae"          },
	{"p",  MEDIAL_JAMO_BASE+5 ,		"ㅔ", "e"  , "e"            },
	{"pp", MEDIAL_JAMO_BASE+7,		"ㅖ", "ye" , "ye"           },
	{"q",  FINAL_JAMO_BASE+17,    	"ㅂ", "b"  , "pieup"        },
	{"q",  INITIAL_JAMO_BASE+7,     "ㅂ", "b"  , "pieup"        },
	{"qq", INITIAL_JAMO_BASE+8,		"ㅃ", "bb" , "ssangpieup"   },
	{"qt", FINAL_JAMO_BASE+18,    	"ㅄ", "bs" , "pieup-sios"   },
	{"r",  FINAL_JAMO_BASE+1 ,    	"ㄱ", "g"  , "kiyeok"       },
	{"r",  INITIAL_JAMO_BASE,     	"ㄱ", "g"  , "kiyeok"       },
	{"rr", FINAL_JAMO_BASE+2,		"ㄲ", "gg" , "ssangkiyeok"  },
	{"rr", INITIAL_JAMO_BASE+1,		"ㄲ", "gg" , "ssangkiyeok"  },
	{"rt", FINAL_JAMO_BASE+3 ,    	"ㄳ", "gs" , "kiyeok-sios"  },
	{"s",  FINAL_JAMO_BASE+4 ,    	"ㄴ", "n"  , "nieun"        },
	{"s",  INITIAL_JAMO_BASE+2,     "ㄴ", "n"  , "nieun"        },
	{"sg", FINAL_JAMO_BASE+6 ,    	"ㄶ", "nh" , "nieun-hieuh"  },
	{"sw", FINAL_JAMO_BASE+5 ,    	"ㄵ", "nj", "nieun-cieuc"  },
	{"t",  FINAL_JAMO_BASE+19,    	"ㅅ", "s"  , "sios"         },
	{"t",  INITIAL_JAMO_BASE+9,     "ㅅ", "s"  , "sios"         },
	{"tt", FINAL_JAMO_BASE+20,		"ㅆ", "ss" , "ssangsios"    },
	{"tt",  INITIAL_JAMO_BASE+10,   "ㅆ", "ss" , "ssangsios"    },
	{"u",  MEDIAL_JAMO_BASE+6 ,		"ㅕ", "yeo", "yeo"          },
	{"v",  FINAL_JAMO_BASE+26,      "ㅍ", "p"  , "phieuph"      },
	{"v",  INITIAL_JAMO_BASE+17,    "ㅍ", "p"  , "phieuph"      },
	{"w",  FINAL_JAMO_BASE+22,    	"ㅈ", "j"  , "cieuc"        },
	{"w",  INITIAL_JAMO_BASE+12,    "ㅈ", "j"  , "cieuc"        },
	{"ww", INITIAL_JAMO_BASE+13,	"ㅉ", "jj" , "ssangcieuc"   },
	{"x",  FINAL_JAMO_BASE+25,      "ㅌ", "t"  , "thieuth"      },
	{"x",  INITIAL_JAMO_BASE+16,    "ㅌ", "t"  , "thieuth"      },
	{"y",  MEDIAL_JAMO_BASE+12,		"ㅛ", "yo" , "yo"           },
	{"z",  FINAL_JAMO_BASE+24,      "ㅋ", "k"  , "khieukh"      },
	{"z",  INITIAL_JAMO_BASE+15,    "ㅋ", "k"  , "khieukh"      },
};

#endif
