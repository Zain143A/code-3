/*
 * "streamable kanji code filter and converter"
 * Copyright (c) 1998-2002 HappySize, Inc. All rights reserved.
 *
 * LICENSE NOTICES
 *
 * This file is part of "streamable kanji code filter and converter",
 * which is distributed under the terms of GNU Lesser General Public
 * License (version 2) as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with "streamable kanji code filter and converter";
 * if not, write to the Free Software Foundation, Inc., 59 Temple Place,
 * Suite 330, Boston, MA  02111-1307  USA
 *
 * The author of this file: Moriyoshi Koizumi <koizumi@gree.co.jp>
 *
 */

#ifndef TRANSLIT_KANA_JISX0201_JISX0208_H
#define TRANSLIT_KANA_JISX0201_JISX0208_H

/* "Zen" is 全, or "full"; "Han" is 半, or "half"
 * This refers to "fullwidth" or "halfwidth" variants of characters used for writing Japanese */
#define MBFL_HAN2ZEN_ALL       0x00001
#define MBFL_HAN2ZEN_ALPHA     0x00002
#define MBFL_HAN2ZEN_NUMERIC   0x00004
#define MBFL_HAN2ZEN_SPACE     0x00008
#define MBFL_HAN2ZEN_KATAKANA  0x00010
#define MBFL_HAN2ZEN_HIRAGANA  0x00020
#define MBFL_HAN2ZEN_SPECIAL   0x00040
#define MBFL_ZENKAKU_HIRA2KATA 0x00080

#define MBFL_ZEN2HAN_ALL       0x00100
#define MBFL_ZEN2HAN_ALPHA     0x00200
#define MBFL_ZEN2HAN_NUMERIC   0x00400
#define MBFL_ZEN2HAN_SPACE     0x00800
#define MBFL_ZEN2HAN_KATAKANA  0x01000
#define MBFL_ZEN2HAN_HIRAGANA  0x02000
#define MBFL_ZEN2HAN_SPECIAL   0x04000
#define MBFL_ZENKAKU_KATA2HIRA 0x08000

#define MBFL_HAN2ZEN_GLUE      0x10000

static const unsigned char hankana2zenkana_table[64] = {
	0x00,0x02,0x0C,0x0D,0x01,0xFB,0xF2,0xA1,0xA3,0xA5,
	0xA7,0xA9,0xE3,0xE5,0xE7,0xC3,0xFC,0xA2,0xA4,0xA6,
	0xA8,0xAA,0xAB,0xAD,0xAF,0xB1,0xB3,0xB5,0xB7,0xB9,
	0xBB,0xBD,0xBF,0xC1,0xC4,0xC6,0xC8,0xCA,0xCB,0xCC,
	0xCD,0xCE,0xCF,0xD2,0xD5,0xD8,0xDB,0xDE,0xDF,0xE0,
	0xE1,0xE2,0xE4,0xE6,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,
	0xEF,0xF3,0x9B,0x9C
};

static const unsigned char hankana2zenhira_table[64] = {
	0x00,0x02,0x0C,0x0D,0x01,0xFB,0x92,0x41,0x43,0x45,
	0x47,0x49,0x83,0x85,0x87,0x63,0xFC,0x42,0x44,0x46,
	0x48,0x4A,0x4B,0x4D,0x4F,0x51,0x53,0x55,0x57,0x59,
	0x5B,0x5D,0x5F,0x61,0x64,0x66,0x68,0x6A,0x6B,0x6C,
	0x6D,0x6E,0x6F,0x72,0x75,0x78,0x7B,0x7E,0x7F,0x80,
	0x81,0x82,0x84,0x86,0x88,0x89,0x8A,0x8B,0x8C,0x8D,
	0x8F,0x93,0x9B,0x9C
};
static const unsigned char zenkana2hankana_table[84][2] = {
	{0x67,0x00},{0x71,0x00},{0x68,0x00},{0x72,0x00},{0x69,0x00},
	{0x73,0x00},{0x6A,0x00},{0x74,0x00},{0x6B,0x00},{0x75,0x00},
	{0x76,0x00},{0x76,0x9E},{0x77,0x00},{0x77,0x9E},{0x78,0x00},
	{0x78,0x9E},{0x79,0x00},{0x79,0x9E},{0x7A,0x00},{0x7A,0x9E},
	{0x7B,0x00},{0x7B,0x9E},{0x7C,0x00},{0x7C,0x9E},{0x7D,0x00},
	{0x7D,0x9E},{0x7E,0x00},{0x7E,0x9E},{0x7F,0x00},{0x7F,0x9E},
	{0x80,0x00},{0x80,0x9E},{0x81,0x00},{0x81,0x9E},{0x6F,0x00},
	{0x82,0x00},{0x82,0x9E},{0x83,0x00},{0x83,0x9E},{0x84,0x00},
	{0x84,0x9E},{0x85,0x00},{0x86,0x00},{0x87,0x00},{0x88,0x00},
	{0x89,0x00},{0x8A,0x00},{0x8A,0x9E},{0x8A,0x9F},{0x8B,0x00},
	{0x8B,0x9E},{0x8B,0x9F},{0x8C,0x00},{0x8C,0x9E},{0x8C,0x9F},
	{0x8D,0x00},{0x8D,0x9E},{0x8D,0x9F},{0x8E,0x00},{0x8E,0x9E},
	{0x8E,0x9F},{0x8F,0x00},{0x90,0x00},{0x91,0x00},{0x92,0x00},
	{0x93,0x00},{0x6C,0x00},{0x94,0x00},{0x6D,0x00},{0x95,0x00},
	{0x6E,0x00},{0x96,0x00},{0x97,0x00},{0x98,0x00},{0x99,0x00},
	{0x9A,0x00},{0x9B,0x00},{0x9C,0x00},{0x9C,0x00},{0x72,0x00},
	{0x74,0x00},{0x66,0x00},{0x9D,0x00},{0x73,0x9E}
};

#endif /* TRANSLIT_KANA_JISX0201_JISX0208_H */
