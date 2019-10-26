/*
WARNING! All changes made in this file will be lost!
Created from 'empty' by 'codegen_emoji'

This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "emoji.h"

#include "emoji_suggestions_data.h"
#include "ui/emoji_config.h"

namespace Ui {
namespace Emoji {
namespace {

std::vector<One> Items;

struct DataStruct {
	uint32 original : 12;
	uint32 idSize : 6;
	uint32 postfixed : 1;
	uint32 variated : 1;
};

const ushort IdData[] = {
0xd83d, 0xde00, 0xd83d, 0xde03, 0xd83d, 0xde04, 0xd83d, 0xde01, 0xd83d, 0xde06, 0xd83d, 0xde05,
0xd83d, 0xde02, 0xd83e, 0xdd23, 0x263a, 0xd83d, 0xde0a, 0xd83d, 0xde07, 0xd83d, 0xde42, 0xd83d,
0xde43, 0xd83d, 0xde09, 0xd83d, 0xde0c, 0xd83d, 0xde0d, 0xd83e, 0xdd70, 0xd83d, 0xde18, 0xd83d,
0xde17, 0xd83d, 0xde19, 0xd83d, 0xde1a, 0xd83d, 0xde0b, 0xd83d, 0xde1b, 0xd83d, 0xde1d, 0xd83d,
0xde1c, 0xd83e, 0xdd2a, 0xd83e, 0xdd28, 0xd83e, 0xddd0, 0xd83e, 0xdd13, 0xd83d, 0xde0e, 0xd83e,
0xdd29, 0xd83e, 0xdd73, 0xd83d, 0xde0f, 0xd83d, 0xde12, 0xd83d, 0xde1e, 0xd83d, 0xde14, 0xd83d,
0xde1f, 0xd83d, 0xde15, 0xd83d, 0xde41, 0x2639, 0xd83d, 0xde23, 0xd83d, 0xde16, 0xd83d, 0xde2b,
0xd83d, 0xde29, 0xd83e, 0xdd7a, 0xd83d, 0xde22, 0xd83d, 0xde2d, 0xd83d, 0xde24, 0xd83d, 0xde20,
0xd83d, 0xde21, 0xd83e, 0xdd2c, 0xd83e, 0xdd2f, 0xd83d, 0xde33, 0xd83e, 0xdd75, 0xd83e, 0xdd76,
0xd83d, 0xde31, 0xd83d, 0xde28, 0xd83d, 0xde30, 0xd83d, 0xde25, 0xd83d, 0xde13, 0xd83e, 0xdd17,
0xd83e, 0xdd14, 0xd83e, 0xdd2d, 0xd83e, 0xdd2b, 0xd83e, 0xdd25, 0xd83d, 0xde36, 0xd83d, 0xde10,
0xd83d, 0xde11, 0xd83d, 0xde2c, 0xd83d, 0xde44, 0xd83d, 0xde2f, 0xd83d, 0xde26, 0xd83d, 0xde27,
0xd83d, 0xde2e, 0xd83d, 0xde32, 0xd83d, 0xde34, 0xd83e, 0xdd24, 0xd83d, 0xde2a, 0xd83d, 0xde35,
0xd83e, 0xdd10, 0xd83e, 0xdd74, 0xd83e, 0xdd22, 0xd83e, 0xdd2e, 0xd83e, 0xdd27, 0xd83d, 0xde37,
0xd83e, 0xdd12, 0xd83e, 0xdd15, 0xd83e, 0xdd11, 0xd83e, 0xdd20, 0xd83d, 0xde08, 0xd83d, 0xdc7f,
0xd83d, 0xdc79, 0xd83d, 0xdc7a, 0xd83e, 0xdd21, 0xd83d, 0xdca9, 0xd83d, 0xdc7b, 0xd83d, 0xdc80,
0x2620, 0xd83d, 0xdc7d, 0xd83d, 0xdc7e, 0xd83e, 0xdd16, 0xd83c, 0xdf83, 0xd83d, 0xde3a, 0xd83d,
0xde38, 0xd83d, 0xde39, 0xd83d, 0xde3b, 0xd83d, 0xde3c, 0xd83d, 0xde3d, 0xd83d, 0xde40, 0xd83d,
0xde3f, 0xd83d, 0xde3e, 0xd83e, 0xdd32, 0xd83e, 0xdd32, 0xd83c, 0xdffb, 0xd83e, 0xdd32, 0xd83c,
0xdffc, 0xd83e, 0xdd32, 0xd83c, 0xdffd, 0xd83e, 0xdd32, 0xd83c, 0xdffe, 0xd83e, 0xdd32, 0xd83c,
0xdfff, 0xd83d, 0xdc50, 0xd83d, 0xdc50, 0xd83c, 0xdffb, 0xd83d, 0xdc50, 0xd83c, 0xdffc, 0xd83d,
0xdc50, 0xd83c, 0xdffd, 0xd83d, 0xdc50, 0xd83c, 0xdffe, 0xd83d, 0xdc50, 0xd83c, 0xdfff, 0xd83d,
0xde4c, 0xd83d, 0xde4c, 0xd83c, 0xdffb, 0xd83d, 0xde4c, 0xd83c, 0xdffc, 0xd83d, 0xde4c, 0xd83c,
0xdffd, 0xd83d, 0xde4c, 0xd83c, 0xdffe, 0xd83d, 0xde4c, 0xd83c, 0xdfff, 0xd83d, 0xdc4f, 0xd83d,
0xdc4f, 0xd83c, 0xdffb, 0xd83d, 0xdc4f, 0xd83c, 0xdffc, 0xd83d, 0xdc4f, 0xd83c, 0xdffd, 0xd83d,
0xdc4f, 0xd83c, 0xdffe, 0xd83d, 0xdc4f, 0xd83c, 0xdfff, 0xd83e, 0xdd1d, 0xd83d, 0xdc4d, 0xd83d,
0xdc4d, 0xd83c, 0xdffb, 0xd83d, 0xdc4d, 0xd83c, 0xdffc, 0xd83d, 0xdc4d, 0xd83c, 0xdffd, 0xd83d,
0xdc4d, 0xd83c, 0xdffe, 0xd83d, 0xdc4d, 0xd83c, 0xdfff, 0xd83d, 0xdc4e, 0xd83d, 0xdc4e, 0xd83c,
0xdffb, 0xd83d, 0xdc4e, 0xd83c, 0xdffc, 0xd83d, 0xdc4e, 0xd83c, 0xdffd, 0xd83d, 0xdc4e, 0xd83c,
0xdffe, 0xd83d, 0xdc4e, 0xd83c, 0xdfff, 0xd83d, 0xdc4a, 0xd83d, 0xdc4a, 0xd83c, 0xdffb, 0xd83d,
0xdc4a, 0xd83c, 0xdffc, 0xd83d, 0xdc4a, 0xd83c, 0xdffd, 0xd83d, 0xdc4a, 0xd83c, 0xdffe, 0xd83d,
0xdc4a, 0xd83c, 0xdfff, 0x270a, 0x270a, 0xd83c, 0xdffb, 0x270a, 0xd83c, 0xdffc, 0x270a, 0xd83c,
0xdffd, 0x270a, 0xd83c, 0xdffe, 0x270a, 0xd83c, 0xdfff, 0xd83e, 0xdd1b, 0xd83e, 0xdd1b, 0xd83c,
0xdffb, 0xd83e, 0xdd1b, 0xd83c, 0xdffc, 0xd83e, 0xdd1b, 0xd83c, 0xdffd, 0xd83e, 0xdd1b, 0xd83c,
0xdffe, 0xd83e, 0xdd1b, 0xd83c, 0xdfff, 0xd83e, 0xdd1c, 0xd83e, 0xdd1c, 0xd83c, 0xdffb, 0xd83e,
0xdd1c, 0xd83c, 0xdffc, 0xd83e, 0xdd1c, 0xd83c, 0xdffd, 0xd83e, 0xdd1c, 0xd83c, 0xdffe, 0xd83e,
0xdd1c, 0xd83c, 0xdfff, 0xd83e, 0xdd1e, 0xd83e, 0xdd1e, 0xd83c, 0xdffb, 0xd83e, 0xdd1e, 0xd83c,
0xdffc, 0xd83e, 0xdd1e, 0xd83c, 0xdffd, 0xd83e, 0xdd1e, 0xd83c, 0xdffe, 0xd83e, 0xdd1e, 0xd83c,
0xdfff, 0x270c, 0x270c, 0xd83c, 0xdffb, 0x270c, 0xd83c, 0xdffc, 0x270c, 0xd83c, 0xdffd, 0x270c,
0xd83c, 0xdffe, 0x270c, 0xd83c, 0xdfff, 0xd83e, 0xdd1f, 0xd83e, 0xdd1f, 0xd83c, 0xdffb, 0xd83e,
0xdd1f, 0xd83c, 0xdffc, 0xd83e, 0xdd1f, 0xd83c, 0xdffd, 0xd83e, 0xdd1f, 0xd83c, 0xdffe, 0xd83e,
0xdd1f, 0xd83c, 0xdfff, 0xd83e, 0xdd18, 0xd83e, 0xdd18, 0xd83c, 0xdffb, 0xd83e, 0xdd18, 0xd83c,
0xdffc, 0xd83e, 0xdd18, 0xd83c, 0xdffd, 0xd83e, 0xdd18, 0xd83c, 0xdffe, 0xd83e, 0xdd18, 0xd83c,
0xdfff, 0xd83d, 0xdc4c, 0xd83d, 0xdc4c, 0xd83c, 0xdffb, 0xd83d, 0xdc4c, 0xd83c, 0xdffc, 0xd83d,
0xdc4c, 0xd83c, 0xdffd, 0xd83d, 0xdc4c, 0xd83c, 0xdffe, 0xd83d, 0xdc4c, 0xd83c, 0xdfff, 0xd83d,
0xdc48, 0xd83d, 0xdc48, 0xd83c, 0xdffb, 0xd83d, 0xdc48, 0xd83c, 0xdffc, 0xd83d, 0xdc48, 0xd83c,
0xdffd, 0xd83d, 0xdc48, 0xd83c, 0xdffe, 0xd83d, 0xdc48, 0xd83c, 0xdfff, 0xd83d, 0xdc49, 0xd83d,
0xdc49, 0xd83c, 0xdffb, 0xd83d, 0xdc49, 0xd83c, 0xdffc, 0xd83d, 0xdc49, 0xd83c, 0xdffd, 0xd83d,
0xdc49, 0xd83c, 0xdffe, 0xd83d, 0xdc49, 0xd83c, 0xdfff, 0xd83d, 0xdc46, 0xd83d, 0xdc46, 0xd83c,
0xdffb, 0xd83d, 0xdc46, 0xd83c, 0xdffc, 0xd83d, 0xdc46, 0xd83c, 0xdffd, 0xd83d, 0xdc46, 0xd83c,
0xdffe, 0xd83d, 0xdc46, 0xd83c, 0xdfff, 0xd83d, 0xdc47, 0xd83d, 0xdc47, 0xd83c, 0xdffb, 0xd83d,
0xdc47, 0xd83c, 0xdffc, 0xd83d, 0xdc47, 0xd83c, 0xdffd, 0xd83d, 0xdc47, 0xd83c, 0xdffe, 0xd83d,
0xdc47, 0xd83c, 0xdfff, 0x261d, 0x261d, 0xd83c, 0xdffb, 0x261d, 0xd83c, 0xdffc, 0x261d, 0xd83c,
0xdffd, 0x261d, 0xd83c, 0xdffe, 0x261d, 0xd83c, 0xdfff, 0x270b, 0x270b, 0xd83c, 0xdffb, 0x270b,
0xd83c, 0xdffc, 0x270b, 0xd83c, 0xdffd, 0x270b, 0xd83c, 0xdffe, 0x270b, 0xd83c, 0xdfff, 0xd83e,
0xdd1a, 0xd83e, 0xdd1a, 0xd83c, 0xdffb, 0xd83e, 0xdd1a, 0xd83c, 0xdffc, 0xd83e, 0xdd1a, 0xd83c,
0xdffd, 0xd83e, 0xdd1a, 0xd83c, 0xdffe, 0xd83e, 0xdd1a, 0xd83c, 0xdfff, 0xd83d, 0xdd90, 0xd83d,
0xdd90, 0xd83c, 0xdffb, 0xd83d, 0xdd90, 0xd83c, 0xdffc, 0xd83d, 0xdd90, 0xd83c, 0xdffd, 0xd83d,
0xdd90, 0xd83c, 0xdffe, 0xd83d, 0xdd90, 0xd83c, 0xdfff, 0xd83d, 0xdd96, 0xd83d, 0xdd96, 0xd83c,
0xdffb, 0xd83d, 0xdd96, 0xd83c, 0xdffc, 0xd83d, 0xdd96, 0xd83c, 0xdffd, 0xd83d, 0xdd96, 0xd83c,
0xdffe, 0xd83d, 0xdd96, 0xd83c, 0xdfff, 0xd83d, 0xdc4b, 0xd83d, 0xdc4b, 0xd83c, 0xdffb, 0xd83d,
0xdc4b, 0xd83c, 0xdffc, 0xd83d, 0xdc4b, 0xd83c, 0xdffd, 0xd83d, 0xdc4b, 0xd83c, 0xdffe, 0xd83d,
0xdc4b, 0xd83c, 0xdfff, 0xd83e, 0xdd19, 0xd83e, 0xdd19, 0xd83c, 0xdffb, 0xd83e, 0xdd19, 0xd83c,
0xdffc, 0xd83e, 0xdd19, 0xd83c, 0xdffd, 0xd83e, 0xdd19, 0xd83c, 0xdffe, 0xd83e, 0xdd19, 0xd83c,
0xdfff, 0xd83d, 0xdcaa, 0xd83d, 0xdcaa, 0xd83c, 0xdffb, 0xd83d, 0xdcaa, 0xd83c, 0xdffc, 0xd83d,
0xdcaa, 0xd83c, 0xdffd, 0xd83d, 0xdcaa, 0xd83c, 0xdffe, 0xd83d, 0xdcaa, 0xd83c, 0xdfff, 0xd83d,
0xdd95, 0xd83d, 0xdd95, 0xd83c, 0xdffb, 0xd83d, 0xdd95, 0xd83c, 0xdffc, 0xd83d, 0xdd95, 0xd83c,
0xdffd, 0xd83d, 0xdd95, 0xd83c, 0xdffe, 0xd83d, 0xdd95, 0xd83c, 0xdfff, 0x270d, 0x270d, 0xd83c,
0xdffb, 0x270d, 0xd83c, 0xdffc, 0x270d, 0xd83c, 0xdffd, 0x270d, 0xd83c, 0xdffe, 0x270d, 0xd83c,
0xdfff, 0xd83d, 0xde4f, 0xd83d, 0xde4f, 0xd83c, 0xdffb, 0xd83d, 0xde4f, 0xd83c, 0xdffc, 0xd83d,
0xde4f, 0xd83c, 0xdffd, 0xd83d, 0xde4f, 0xd83c, 0xdffe, 0xd83d, 0xde4f, 0xd83c, 0xdfff, 0xd83e,
0xddb6, 0xd83e, 0xddb6, 0xd83c, 0xdffb, 0xd83e, 0xddb6, 0xd83c, 0xdffc, 0xd83e, 0xddb6, 0xd83c,
0xdffd, 0xd83e, 0xddb6, 0xd83c, 0xdffe, 0xd83e, 0xddb6, 0xd83c, 0xdfff, 0xd83e, 0xddb5, 0xd83e,
0xddb5, 0xd83c, 0xdffb, 0xd83e, 0xddb5, 0xd83c, 0xdffc, 0xd83e, 0xddb5, 0xd83c, 0xdffd, 0xd83e,
0xddb5, 0xd83c, 0xdffe, 0xd83e, 0xddb5, 0xd83c, 0xdfff, 0xd83d, 0xdc84, 0xd83d, 0xdc8b, 0xd83d,
0xdc44, 0xd83e, 0xddb7, 0xd83d, 0xdc45, 0xd83d, 0xdc42, 0xd83d, 0xdc42, 0xd83c, 0xdffb, 0xd83d,
0xdc42, 0xd83c, 0xdffc, 0xd83d, 0xdc42, 0xd83c, 0xdffd, 0xd83d, 0xdc42, 0xd83c, 0xdffe, 0xd83d,
0xdc42, 0xd83c, 0xdfff, 0xd83d, 0xdc43, 0xd83d, 0xdc43, 0xd83c, 0xdffb, 0xd83d, 0xdc43, 0xd83c,
0xdffc, 0xd83d, 0xdc43, 0xd83c, 0xdffd, 0xd83d, 0xdc43, 0xd83c, 0xdffe, 0xd83d, 0xdc43, 0xd83c,
0xdfff, 0xd83d, 0xdc63, 0xd83d, 0xdc41, 0xd83d, 0xdc40, 0xd83e, 0xdde0, 0xd83d, 0xdde3, 0xd83d,
0xdc64, 0xd83d, 0xdc65, 0xd83d, 0xdc76, 0xd83d, 0xdc76, 0xd83c, 0xdffb, 0xd83d, 0xdc76, 0xd83c,
0xdffc, 0xd83d, 0xdc76, 0xd83c, 0xdffd, 0xd83d, 0xdc76, 0xd83c, 0xdffe, 0xd83d, 0xdc76, 0xd83c,
0xdfff, 0xd83d, 0xdc67, 0xd83d, 0xdc67, 0xd83c, 0xdffb, 0xd83d, 0xdc67, 0xd83c, 0xdffc, 0xd83d,
0xdc67, 0xd83c, 0xdffd, 0xd83d, 0xdc67, 0xd83c, 0xdffe, 0xd83d, 0xdc67, 0xd83c, 0xdfff, 0xd83e,
0xddd2, 0xd83e, 0xddd2, 0xd83c, 0xdffb, 0xd83e, 0xddd2, 0xd83c, 0xdffc, 0xd83e, 0xddd2, 0xd83c,
0xdffd, 0xd83e, 0xddd2, 0xd83c, 0xdffe, 0xd83e, 0xddd2, 0xd83c, 0xdfff, 0xd83d, 0xdc66, 0xd83d,
0xdc66, 0xd83c, 0xdffb, 0xd83d, 0xdc66, 0xd83c, 0xdffc, 0xd83d, 0xdc66, 0xd83c, 0xdffd, 0xd83d,
0xdc66, 0xd83c, 0xdffe, 0xd83d, 0xdc66, 0xd83c, 0xdfff, 0xd83d, 0xdc69, 0xd83d, 0xdc69, 0xd83c,
0xdffb, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0xd83d, 0xdc69, 0xd83c,
0xdffe, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0xd83e, 0xddd1, 0xd83e, 0xddd1, 0xd83c, 0xdffb, 0xd83e,
0xddd1, 0xd83c, 0xdffc, 0xd83e, 0xddd1, 0xd83c, 0xdffd, 0xd83e, 0xddd1, 0xd83c, 0xdffe, 0xd83e,
0xddd1, 0xd83c, 0xdfff, 0xd83d, 0xdc68, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0xd83d, 0xdc68, 0xd83c,
0xdfff, 0xd83d, 0xdc69, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83e,
0xddb1, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc68, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb1,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83e, 0xddb1, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb1, 0xd83d, 0xdc69, 0x200d,
0xd83e, 0xddb0, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83e, 0xddb0, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83e,
0xddb0, 0xd83d, 0xdc68, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83e,
0xddb0, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb0, 0xd83d, 0xdc71, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc71,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdc71, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc71, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc71, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdc71, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc71, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdc69, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83e,
0xddb3, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc68, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb3,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83e, 0xddb3, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb3, 0xd83d, 0xdc69, 0x200d,
0xd83e, 0xddb2, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83e, 0xddb2, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83e,
0xddb2, 0xd83d, 0xdc68, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83e,
0xddb2, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83e, 0xddb2, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83e, 0xddb2, 0xd83e, 0xddd4, 0xd83e, 0xddd4, 0xd83c, 0xdffb, 0xd83e,
0xddd4, 0xd83c, 0xdffc, 0xd83e, 0xddd4, 0xd83c, 0xdffd, 0xd83e, 0xddd4, 0xd83c, 0xdffe, 0xd83e,
0xddd4, 0xd83c, 0xdfff, 0xd83d, 0xdc75, 0xd83d, 0xdc75, 0xd83c, 0xdffb, 0xd83d, 0xdc75, 0xd83c,
0xdffc, 0xd83d, 0xdc75, 0xd83c, 0xdffd, 0xd83d, 0xdc75, 0xd83c, 0xdffe, 0xd83d, 0xdc75, 0xd83c,
0xdfff, 0xd83e, 0xddd3, 0xd83e, 0xddd3, 0xd83c, 0xdffb, 0xd83e, 0xddd3, 0xd83c, 0xdffc, 0xd83e,
0xddd3, 0xd83c, 0xdffd, 0xd83e, 0xddd3, 0xd83c, 0xdffe, 0xd83e, 0xddd3, 0xd83c, 0xdfff, 0xd83d,
0xdc74, 0xd83d, 0xdc74, 0xd83c, 0xdffb, 0xd83d, 0xdc74, 0xd83c, 0xdffc, 0xd83d, 0xdc74, 0xd83c,
0xdffd, 0xd83d, 0xdc74, 0xd83c, 0xdffe, 0xd83d, 0xdc74, 0xd83c, 0xdfff, 0xd83d, 0xdc72, 0xd83d,
0xdc72, 0xd83c, 0xdffb, 0xd83d, 0xdc72, 0xd83c, 0xdffc, 0xd83d, 0xdc72, 0xd83c, 0xdffd, 0xd83d,
0xdc72, 0xd83c, 0xdffe, 0xd83d, 0xdc72, 0xd83c, 0xdfff, 0xd83d, 0xdc73, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdc73, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc73, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdc73, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdc73, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc73, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd5, 0xd83e, 0xddd5, 0xd83c, 0xdffb, 0xd83e, 0xddd5, 0xd83c,
0xdffc, 0xd83e, 0xddd5, 0xd83c, 0xdffd, 0xd83e, 0xddd5, 0xd83c, 0xdffe, 0xd83e, 0xddd5, 0xd83c,
0xdfff, 0xd83d, 0xdc6e, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc6e,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc6e, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc6e,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xdc6e, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdc6e, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc77, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc77, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdc77, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xdc77, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc77, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc77,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc82, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc82,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdc82, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc82, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc82, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdc82, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc82, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdd75, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffb, 0xfe0f,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffc, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdd75, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffe, 0xfe0f,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdfff, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdd75, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffb, 0xfe0f, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffc, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdd75, 0xd83c,
0xdffd, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdffe, 0xfe0f, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdd75, 0xd83c, 0xdfff, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc69, 0x200d,
0x2695, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0x2695, 0xfe0f, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0x2695,
0xfe0f, 0xd83d, 0xdc68, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0x2695,
0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0x2695, 0xfe0f, 0xd83d, 0xdc69, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc69,
0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdf3e,
0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d,
0xd83c, 0xdf3e, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc68, 0x200d,
0xd83c, 0xdf3e, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdf3e, 0xd83d,
0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdf3e, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83c,
0xdf3e, 0xd83d, 0xdc69, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83c,
0xdf73, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc68, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdf73,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83c, 0xdf73, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdf73, 0xd83d, 0xdc69, 0x200d,
0xd83c, 0xdf93, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdf93, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83c,
0xdf93, 0xd83d, 0xdc68, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83c,
0xdf93, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdf93, 0xd83d, 0xdc69, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc69,
0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfa4,
0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d,
0xd83c, 0xdfa4, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc68, 0x200d,
0xd83c, 0xdfa4, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdfa4, 0xd83d,
0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdfa4, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83c,
0xdfa4, 0xd83d, 0xdc69, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83c,
0xdfeb, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc68, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfeb,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83c, 0xdfeb, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfeb, 0xd83d, 0xdc69, 0x200d,
0xd83c, 0xdfed, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdfed, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83c,
0xdfed, 0xd83d, 0xdc68, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83c,
0xdfed, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfed, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc69,
0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xdcbb,
0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d,
0xd83d, 0xdcbb, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc68, 0x200d,
0xd83d, 0xdcbb, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdcbb, 0xd83d,
0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xdcbb, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83d,
0xdcbb, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83d,
0xdcbc, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xdcbc,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83d, 0xdcbc, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83d, 0xdcbc, 0xd83d, 0xdc69, 0x200d,
0xd83d, 0xdd27, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdd27, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83d,
0xdd27, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83d,
0xdd27, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83d, 0xdd27, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc69,
0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xdd2c,
0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d,
0xd83d, 0xdd2c, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc68, 0x200d,
0xd83d, 0xdd2c, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xdd2c, 0xd83d,
0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xdd2c, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83d,
0xdd2c, 0xd83d, 0xdc69, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83c,
0xdfa8, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc68, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83c, 0xdfa8,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83c, 0xdfa8, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83c, 0xdfa8, 0xd83d, 0xdc69, 0x200d,
0xd83d, 0xde92, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xde92, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0xd83d,
0xde92, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0xd83d,
0xde92, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0xd83d, 0xde92, 0xd83d, 0xdc69, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc69,
0xd83c, 0xdffb, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0x2708, 0xfe0f,
0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d,
0x2708, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc68, 0x200d,
0x2708, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc68, 0xd83c,
0xdffc, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0x2708, 0xfe0f, 0xd83d,
0xdc68, 0xd83c, 0xdffe, 0x200d, 0x2708, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0x2708,
0xfe0f, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0xd83d,
0xde80, 0xd83d, 0xdc69, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc69, 0xd83c, 0xdffd,
0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc69, 0xd83c, 0xdffe, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc69,
0xd83c, 0xdfff, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc68,
0xd83c, 0xdffb, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0xd83d, 0xde80,
0xd83d, 0xdc68, 0xd83c, 0xdffd, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d,
0xd83d, 0xde80, 0xd83d, 0xdc68, 0xd83c, 0xdfff, 0x200d, 0xd83d, 0xde80, 0xd83d, 0xdc69, 0x200d,
0x2696, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffb, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc69, 0xd83c,
0xdffc, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdffd, 0x200d, 0x2696, 0xfe0f, 0xd83d,
0xdc69, 0xd83c, 0xdffe, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc69, 0xd83c, 0xdfff, 0x200d, 0x2696,
0xfe0f, 0xd83d, 0xdc68, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffb, 0x200d, 0x2696,
0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffc, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffd,
0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc68, 0xd83c, 0xdffe, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc68,
0xd83c, 0xdfff, 0x200d, 0x2696, 0xfe0f, 0xd83d, 0xdc70, 0xd83d, 0xdc70, 0xd83c, 0xdffb, 0xd83d,
0xdc70, 0xd83c, 0xdffc, 0xd83d, 0xdc70, 0xd83c, 0xdffd, 0xd83d, 0xdc70, 0xd83c, 0xdffe, 0xd83d,
0xdc70, 0xd83c, 0xdfff, 0xd83e, 0xdd35, 0xd83e, 0xdd35, 0xd83c, 0xdffb, 0xd83e, 0xdd35, 0xd83c,
0xdffc, 0xd83e, 0xdd35, 0xd83c, 0xdffd, 0xd83e, 0xdd35, 0xd83c, 0xdffe, 0xd83e, 0xdd35, 0xd83c,
0xdfff, 0xd83d, 0xdc78, 0xd83d, 0xdc78, 0xd83c, 0xdffb, 0xd83d, 0xdc78, 0xd83c, 0xdffc, 0xd83d,
0xdc78, 0xd83c, 0xdffd, 0xd83d, 0xdc78, 0xd83c, 0xdffe, 0xd83d, 0xdc78, 0xd83c, 0xdfff, 0xd83e,
0xdd34, 0xd83e, 0xdd34, 0xd83c, 0xdffb, 0xd83e, 0xdd34, 0xd83c, 0xdffc, 0xd83e, 0xdd34, 0xd83c,
0xdffd, 0xd83e, 0xdd34, 0xd83c, 0xdffe, 0xd83e, 0xdd34, 0xd83c, 0xdfff, 0xd83e, 0xddb8, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb8, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xddb8, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xddb8, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb8, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb8,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb9, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb9,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xddb9, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddb9, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb9, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xddb9, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddb9, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdd36, 0xd83e, 0xdd36, 0xd83c, 0xdffb, 0xd83e, 0xdd36, 0xd83c, 0xdffc, 0xd83e,
0xdd36, 0xd83c, 0xdffd, 0xd83e, 0xdd36, 0xd83c, 0xdffe, 0xd83e, 0xdd36, 0xd83c, 0xdfff, 0xd83c,
0xdf85, 0xd83c, 0xdf85, 0xd83c, 0xdffb, 0xd83c, 0xdf85, 0xd83c, 0xdffc, 0xd83c, 0xdf85, 0xd83c,
0xdffd, 0xd83c, 0xdf85, 0xd83c, 0xdffe, 0xd83c, 0xdf85, 0xd83c, 0xdfff, 0xd83e, 0xddd9, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd9, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xddd9, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xddd9, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd9, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd9,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddd,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xdddd, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddd, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddd, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xdddd, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddd, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdddb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddb,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddb,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xdddb, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xdddb, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddf, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdddf, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddde, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xddde, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddc,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xdddc, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdddc, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddc, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xdddc, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdddc, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddda, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddda,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddda, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddda,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xddda, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xddda, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc7c, 0xd83d,
0xdc7c, 0xd83c, 0xdffb, 0xd83d, 0xdc7c, 0xd83c, 0xdffc, 0xd83d, 0xdc7c, 0xd83c, 0xdffd, 0xd83d,
0xdc7c, 0xd83c, 0xdffe, 0xd83d, 0xdc7c, 0xd83c, 0xdfff, 0xd83e, 0xdd30, 0xd83e, 0xdd30, 0xd83c,
0xdffb, 0xd83e, 0xdd30, 0xd83c, 0xdffc, 0xd83e, 0xdd30, 0xd83c, 0xdffd, 0xd83e, 0xdd30, 0xd83c,
0xdffe, 0xd83e, 0xdd30, 0xd83c, 0xdfff, 0xd83e, 0xdd31, 0xd83e, 0xdd31, 0xd83c, 0xdffb, 0xd83e,
0xdd31, 0xd83c, 0xdffc, 0xd83e, 0xdd31, 0xd83c, 0xdffd, 0xd83e, 0xdd31, 0xd83c, 0xdffe, 0xd83e,
0xdd31, 0xd83c, 0xdfff, 0xd83d, 0xde47, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdffb,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde47,
0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xde47, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde47, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xde47, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdffc, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde47, 0xd83c,
0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde47, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdc81, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdc81, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc81, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc81,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc81, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xdc81, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde45, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xde45, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde45, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xde45, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xde45, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde45, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde46, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdffb,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde46,
0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xde46, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde46, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xde46, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdffc, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde46, 0xd83c,
0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde46, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xde4b, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xde4b, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4b, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4b,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4b, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xde4b, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd26, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xdd26, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd26, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xdd26, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xdd26, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd26, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd37, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdffb,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd37,
0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xdd37, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd37, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xdd37, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdffc, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd37, 0xd83c,
0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd37, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xde4e, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xde4e, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4e, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4e,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4e, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xde4e, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4d, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xde4d, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4d, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xde4d, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xde4d, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xde4d, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc87, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdffb,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc87,
0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdc87, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc87, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xdc87, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdffc, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc87, 0xd83c,
0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc87, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdc86, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdc86, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdc86, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc86,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc86, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xdc86, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd6, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xddd6, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd6, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xddd6, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xddd6, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd6, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc85, 0xd83d, 0xdc85, 0xd83c, 0xdffb, 0xd83d, 0xdc85, 0xd83c,
0xdffc, 0xd83d, 0xdc85, 0xd83c, 0xdffd, 0xd83d, 0xdc85, 0xd83c, 0xdffe, 0xd83d, 0xdc85, 0xd83c,
0xdfff, 0xd83e, 0xdd33, 0xd83e, 0xdd33, 0xd83c, 0xdffb, 0xd83e, 0xdd33, 0xd83c, 0xdffc, 0xd83e,
0xdd33, 0xd83c, 0xdffd, 0xd83e, 0xdd33, 0xd83c, 0xdffe, 0xd83e, 0xdd33, 0xd83c, 0xdfff, 0xd83d,
0xdc83, 0xd83d, 0xdc83, 0xd83c, 0xdffb, 0xd83d, 0xdc83, 0xd83c, 0xdffc, 0xd83d, 0xdc83, 0xd83c,
0xdffd, 0xd83d, 0xdc83, 0xd83c, 0xdffe, 0xd83d, 0xdc83, 0xd83c, 0xdfff, 0xd83d, 0xdd7a, 0xd83d,
0xdd7a, 0xd83c, 0xdffb, 0xd83d, 0xdd7a, 0xd83c, 0xdffc, 0xd83d, 0xdd7a, 0xd83c, 0xdffd, 0xd83d,
0xdd7a, 0xd83c, 0xdffe, 0xd83d, 0xdd7a, 0xd83c, 0xdfff, 0xd83d, 0xdc6f, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdc6f, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdd74, 0xd83d, 0xdd74, 0xd83c, 0xdffb, 0xd83d,
0xdd74, 0xd83c, 0xdffc, 0xd83d, 0xdd74, 0xd83c, 0xdffd, 0xd83d, 0xdd74, 0xd83c, 0xdffe, 0xd83d,
0xdd74, 0xd83c, 0xdfff, 0xd83d, 0xdeb6, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdffb,
0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb6,
0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdeb6, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb6, 0x200d, 0x2642, 0xfe0f,
0xd83d, 0xdeb6, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdffc, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c,
0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb6, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfc3, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83c,
0xdfc3, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc3, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc3,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc3, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83c, 0xdfc3, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdc6b, 0xd83d, 0xdc6d, 0xd83d,
0xdc6c, 0xd83d, 0xdc91, 0xd83d, 0xdc69, 0x200d, 0x2764, 0xfe0f, 0x200d, 0xd83d, 0xdc69, 0xd83d,
0xdc68, 0x200d, 0x2764, 0xfe0f, 0x200d, 0xd83d, 0xdc68, 0xd83d, 0xdc8f, 0xd83d, 0xdc69, 0x200d,
0x2764, 0xfe0f, 0x200d, 0xd83d, 0xdc8b, 0x200d, 0xd83d, 0xdc69, 0xd83d, 0xdc68, 0x200d, 0x2764,
0xfe0f, 0x200d, 0xd83d, 0xdc8b, 0x200d, 0xd83d, 0xdc68, 0xd83d, 0xdc6a, 0xd83d, 0xdc68, 0x200d,
0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d,
0xdc67, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc66,
0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67, 0x200d,
0xd83d, 0xdc67, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69,
0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc69, 0x200d,
0xd83d, 0xdc67, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d,
0xdc66, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67,
0x200d, 0xd83d, 0xdc67, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc66, 0xd83d,
0xdc68, 0x200d, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc67, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc68,
0x200d, 0xd83d, 0xdc67, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc68, 0x200d,
0xd83d, 0xdc66, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc68, 0x200d, 0xd83d,
0xdc67, 0x200d, 0xd83d, 0xdc67, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69, 0x200d,
0xd83d, 0xdc67, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69,
0x200d, 0xd83d, 0xdc66, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc69, 0x200d, 0xd83d, 0xdc67, 0x200d,
0xd83d, 0xdc67, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc67,
0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc67, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d,
0xdc66, 0x200d, 0xd83d, 0xdc66, 0xd83d, 0xdc68, 0x200d, 0xd83d, 0xdc67, 0x200d, 0xd83d, 0xdc67,
0xd83e, 0xddf6, 0xd83e, 0xddf5, 0xd83e, 0xdde5, 0xd83e, 0xdd7c, 0xd83d, 0xdc5a, 0xd83d, 0xdc55,
0xd83d, 0xdc56, 0xd83d, 0xdc54, 0xd83d, 0xdc57, 0xd83d, 0xdc59, 0xd83d, 0xdc58, 0xd83e, 0xdd7f,
0xd83d, 0xdc60, 0xd83d, 0xdc61, 0xd83d, 0xdc62, 0xd83d, 0xdc5e, 0xd83d, 0xdc5f, 0xd83e, 0xdd7e,
0xd83e, 0xdde6, 0xd83e, 0xdde4, 0xd83e, 0xdde3, 0xd83c, 0xdfa9, 0xd83e, 0xdde2, 0xd83d, 0xdc52,
0xd83c, 0xdf93, 0x26d1, 0xd83d, 0xdc51, 0xd83d, 0xdc8d, 0xd83d, 0xdc5d, 0xd83d, 0xdc5b, 0xd83d,
0xdc5c, 0xd83d, 0xdcbc, 0xd83c, 0xdf92, 0xd83e, 0xddf3, 0xd83d, 0xdc53, 0xd83d, 0xdd76, 0xd83e,
0xdd7d, 0xd83c, 0xdf02, 0xd83d, 0xdc36, 0xd83d, 0xdc31, 0xd83d, 0xdc2d, 0xd83d, 0xdc39, 0xd83d,
0xdc30, 0xd83e, 0xdd8a, 0xd83d, 0xdc3b, 0xd83d, 0xdc3c, 0xd83d, 0xdc28, 0xd83d, 0xdc2f, 0xd83e,
0xdd81, 0xd83d, 0xdc2e, 0xd83d, 0xdc37, 0xd83d, 0xdc3d, 0xd83d, 0xdc38, 0xd83d, 0xdc35, 0xd83d,
0xde48, 0xd83d, 0xde49, 0xd83d, 0xde4a, 0xd83d, 0xdc12, 0xd83d, 0xdc14, 0xd83d, 0xdc27, 0xd83d,
0xdc26, 0xd83d, 0xdc24, 0xd83d, 0xdc23, 0xd83d, 0xdc25, 0xd83e, 0xdd86, 0xd83e, 0xdd85, 0xd83e,
0xdd89, 0xd83e, 0xdd87, 0xd83d, 0xdc3a, 0xd83d, 0xdc17, 0xd83d, 0xdc34, 0xd83e, 0xdd84, 0xd83d,
0xdc1d, 0xd83d, 0xdc1b, 0xd83e, 0xdd8b, 0xd83d, 0xdc0c, 0xd83d, 0xdc1e, 0xd83d, 0xdc1c, 0xd83e,
0xdd9f, 0xd83e, 0xdd97, 0xd83d, 0xdd77, 0xd83d, 0xdd78, 0xd83e, 0xdd82, 0xd83d, 0xdc22, 0xd83d,
0xdc0d, 0xd83e, 0xdd8e, 0xd83e, 0xdd96, 0xd83e, 0xdd95, 0xd83d, 0xdc19, 0xd83e, 0xdd91, 0xd83e,
0xdd90, 0xd83e, 0xdd9e, 0xd83e, 0xdd80, 0xd83d, 0xdc21, 0xd83d, 0xdc20, 0xd83d, 0xdc1f, 0xd83d,
0xdc2c, 0xd83d, 0xdc33, 0xd83d, 0xdc0b, 0xd83e, 0xdd88, 0xd83d, 0xdc0a, 0xd83d, 0xdc05, 0xd83d,
0xdc06, 0xd83e, 0xdd93, 0xd83e, 0xdd8d, 0xd83d, 0xdc18, 0xd83e, 0xdd9b, 0xd83e, 0xdd8f, 0xd83d,
0xdc2a, 0xd83d, 0xdc2b, 0xd83e, 0xdd92, 0xd83e, 0xdd98, 0xd83d, 0xdc03, 0xd83d, 0xdc02, 0xd83d,
0xdc04, 0xd83d, 0xdc0e, 0xd83d, 0xdc16, 0xd83d, 0xdc0f, 0xd83d, 0xdc11, 0xd83e, 0xdd99, 0xd83d,
0xdc10, 0xd83e, 0xdd8c, 0xd83d, 0xdc15, 0xd83d, 0xdc29, 0xd83d, 0xdc08, 0xd83d, 0xdc13, 0xd83e,
0xdd83, 0xd83e, 0xdd9a, 0xd83e, 0xdd9c, 0xd83e, 0xdda2, 0xd83d, 0xdd4a, 0xd83d, 0xdc07, 0xd83e,
0xdd9d, 0xd83e, 0xdda1, 0xd83d, 0xdc01, 0xd83d, 0xdc00, 0xd83d, 0xdc3f, 0xd83e, 0xdd94, 0xd83d,
0xdc3e, 0xd83d, 0xdc09, 0xd83d, 0xdc32, 0xd83c, 0xdf35, 0xd83c, 0xdf84, 0xd83c, 0xdf32, 0xd83c,
0xdf33, 0xd83c, 0xdf34, 0xd83c, 0xdf31, 0xd83c, 0xdf3f, 0x2618, 0xd83c, 0xdf40, 0xd83c, 0xdf8d,
0xd83c, 0xdf8b, 0xd83c, 0xdf43, 0xd83c, 0xdf42, 0xd83c, 0xdf41, 0xd83c, 0xdf44, 0xd83d, 0xdc1a,
0xd83c, 0xdf3e, 0xd83d, 0xdc90, 0xd83c, 0xdf37, 0xd83c, 0xdf39, 0xd83e, 0xdd40, 0xd83c, 0xdf3a,
0xd83c, 0xdf38, 0xd83c, 0xdf3c, 0xd83c, 0xdf3b, 0xd83c, 0xdf1e, 0xd83c, 0xdf1d, 0xd83c, 0xdf1b,
0xd83c, 0xdf1c, 0xd83c, 0xdf1a, 0xd83c, 0xdf15, 0xd83c, 0xdf16, 0xd83c, 0xdf17, 0xd83c, 0xdf18,
0xd83c, 0xdf11, 0xd83c, 0xdf12, 0xd83c, 0xdf13, 0xd83c, 0xdf14, 0xd83c, 0xdf19, 0xd83c, 0xdf0e,
0xd83c, 0xdf0d, 0xd83c, 0xdf0f, 0xd83d, 0xdcab, 0x2b50, 0xd83c, 0xdf1f, 0x2728, 0x26a1, 0x2604,
0xd83d, 0xdca5, 0xd83d, 0xdd25, 0xd83c, 0xdf2a, 0xd83c, 0xdf08, 0x2600, 0xd83c, 0xdf24, 0x26c5,
0xd83c, 0xdf25, 0x2601, 0xd83c, 0xdf26, 0xd83c, 0xdf27, 0x26c8, 0xd83c, 0xdf29, 0xd83c, 0xdf28,
0x2744, 0x2603, 0x26c4, 0xd83c, 0xdf2c, 0xd83d, 0xdca8, 0xd83d, 0xdca7, 0xd83d, 0xdca6, 0x2614,
0x2602, 0xd83c, 0xdf0a, 0xd83c, 0xdf2b, 0xd83c, 0xdf4f, 0xd83c, 0xdf4e, 0xd83c, 0xdf50, 0xd83c,
0xdf4a, 0xd83c, 0xdf4b, 0xd83c, 0xdf4c, 0xd83c, 0xdf49, 0xd83c, 0xdf47, 0xd83c, 0xdf53, 0xd83c,
0xdf48, 0xd83c, 0xdf52, 0xd83c, 0xdf51, 0xd83e, 0xdd6d, 0xd83c, 0xdf4d, 0xd83e, 0xdd65, 0xd83e,
0xdd5d, 0xd83c, 0xdf45, 0xd83c, 0xdf46, 0xd83e, 0xdd51, 0xd83e, 0xdd66, 0xd83e, 0xdd6c, 0xd83e,
0xdd52, 0xd83c, 0xdf36, 0xd83c, 0xdf3d, 0xd83e, 0xdd55, 0xd83e, 0xdd54, 0xd83c, 0xdf60, 0xd83e,
0xdd50, 0xd83e, 0xdd6f, 0xd83c, 0xdf5e, 0xd83e, 0xdd56, 0xd83e, 0xdd68, 0xd83e, 0xddc0, 0xd83e,
0xdd5a, 0xd83c, 0xdf73, 0xd83e, 0xdd5e, 0xd83e, 0xdd53, 0xd83e, 0xdd69, 0xd83c, 0xdf57, 0xd83c,
0xdf56, 0xd83e, 0xddb4, 0xd83c, 0xdf2d, 0xd83c, 0xdf54, 0xd83c, 0xdf5f, 0xd83c, 0xdf55, 0xd83e,
0xdd6a, 0xd83e, 0xdd59, 0xd83c, 0xdf2e, 0xd83c, 0xdf2f, 0xd83e, 0xdd57, 0xd83e, 0xdd58, 0xd83e,
0xdd6b, 0xd83c, 0xdf5d, 0xd83c, 0xdf5c, 0xd83c, 0xdf72, 0xd83c, 0xdf5b, 0xd83c, 0xdf63, 0xd83c,
0xdf71, 0xd83e, 0xdd5f, 0xd83c, 0xdf64, 0xd83c, 0xdf59, 0xd83c, 0xdf5a, 0xd83c, 0xdf58, 0xd83c,
0xdf65, 0xd83e, 0xdd60, 0xd83e, 0xdd6e, 0xd83c, 0xdf62, 0xd83c, 0xdf61, 0xd83c, 0xdf67, 0xd83c,
0xdf68, 0xd83c, 0xdf66, 0xd83e, 0xdd67, 0xd83e, 0xddc1, 0xd83c, 0xdf70, 0xd83c, 0xdf82, 0xd83c,
0xdf6e, 0xd83c, 0xdf6d, 0xd83c, 0xdf6c, 0xd83c, 0xdf6b, 0xd83c, 0xdf7f, 0xd83c, 0xdf69, 0xd83c,
0xdf6a, 0xd83c, 0xdf30, 0xd83e, 0xdd5c, 0xd83c, 0xdf6f, 0xd83e, 0xdd5b, 0xd83c, 0xdf7c, 0x2615,
0xd83c, 0xdf75, 0xd83e, 0xdd64, 0xd83c, 0xdf76, 0xd83c, 0xdf7a, 0xd83c, 0xdf7b, 0xd83e, 0xdd42,
0xd83c, 0xdf77, 0xd83e, 0xdd43, 0xd83c, 0xdf78, 0xd83c, 0xdf79, 0xd83c, 0xdf7e, 0xd83e, 0xdd44,
0xd83c, 0xdf74, 0xd83c, 0xdf7d, 0xd83e, 0xdd63, 0xd83e, 0xdd61, 0xd83e, 0xdd62, 0xd83e, 0xddc2,
0x26bd, 0xd83c, 0xdfc0, 0xd83c, 0xdfc8, 0x26be, 0xd83e, 0xdd4e, 0xd83c, 0xdfbe, 0xd83c, 0xdfd0,
0xd83c, 0xdfc9, 0xd83e, 0xdd4f, 0xd83c, 0xdfb1, 0xd83c, 0xdfd3, 0xd83c, 0xdff8, 0xd83c, 0xdfd2,
0xd83c, 0xdfd1, 0xd83e, 0xdd4d, 0xd83c, 0xdfcf, 0xd83e, 0xdd45, 0x26f3, 0xd83c, 0xdff9, 0xd83c,
0xdfa3, 0xd83e, 0xdd4a, 0xd83e, 0xdd4b, 0xd83c, 0xdfbd, 0xd83d, 0xdef9, 0xd83d, 0xdef7, 0x26f8,
0xd83e, 0xdd4c, 0xd83c, 0xdfbf, 0x26f7, 0xd83c, 0xdfc2, 0xd83c, 0xdfcb, 0xfe0f, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdffb, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c,
0xdffc, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdffe, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c,
0xdfff, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcb, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfcb, 0xd83c, 0xdffb, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdffc, 0xfe0f,
0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfcb, 0xd83c, 0xdffe, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcb, 0xd83c, 0xdfff, 0xfe0f,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3c, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3c, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdd38, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd38,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd38, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd38,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xdd38, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xdd38, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0x26f9, 0xfe0f, 0x200d,
0x2640, 0xfe0f, 0x26f9, 0xd83c, 0xdffb, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0x26f9, 0xd83c, 0xdffc,
0xfe0f, 0x200d, 0x2640, 0xfe0f, 0x26f9, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0x26f9,
0xd83c, 0xdffe, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0x26f9, 0xd83c, 0xdfff, 0xfe0f, 0x200d, 0x2640,
0xfe0f, 0x26f9, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0x26f9, 0xd83c, 0xdffb, 0xfe0f, 0x200d, 0x2642,
0xfe0f, 0x26f9, 0xd83c, 0xdffc, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0x26f9, 0xd83c, 0xdffd, 0xfe0f,
0x200d, 0x2642, 0xfe0f, 0x26f9, 0xd83c, 0xdffe, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0x26f9, 0xd83c,
0xdfff, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3a, 0xd83e, 0xdd3e, 0x200d, 0x2640, 0xfe0f,
0xd83e, 0xdd3e, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdffc, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c,
0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xdd3e, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e,
0xdd3e, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdffd, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3e, 0xd83c, 0xdfff,
0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcc, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c,
0xdffb, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdffc, 0xfe0f, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c,
0xdffe, 0xfe0f, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdfff, 0xfe0f, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfcc, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdffb, 0xfe0f,
0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdffc, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfcc, 0xd83c, 0xdffd, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdffe, 0xfe0f,
0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfcc, 0xd83c, 0xdfff, 0xfe0f, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfc7, 0xd83c, 0xdfc7, 0xd83c, 0xdffb, 0xd83c, 0xdfc7, 0xd83c, 0xdffc, 0xd83c, 0xdfc7, 0xd83c,
0xdffd, 0xd83c, 0xdfc7, 0xd83c, 0xdffe, 0xd83c, 0xdfc7, 0xd83c, 0xdfff, 0xd83e, 0xddd8, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd8, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xddd8, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xddd8, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd8, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd8,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc4, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc4,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83c, 0xdfc4, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfc4, 0x200d,
0x2642, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83c,
0xdfc4, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfc4, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83c, 0xdfca, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfca,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83c, 0xdfca, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfca,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83c, 0xdfca, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83c, 0xdfca, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3d, 0x200d,
0x2640, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xdd3d, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xdd3d, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3d, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd3d,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdea3, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdea3,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdea3, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdea3, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdea3, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdea3, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdea3, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83e, 0xddd7, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffb, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffd,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd7,
0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xddd7, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd7,
0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xddd7, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdffe, 0x200d,
0x2642, 0xfe0f, 0xd83e, 0xddd7, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb5, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c,
0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d,
0xdeb5, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdfff, 0x200d, 0x2640,
0xfe0f, 0xd83d, 0xdeb5, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffb, 0x200d, 0x2642,
0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffd,
0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb5, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb5,
0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb4, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb4,
0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f,
0xd83d, 0xdeb4, 0xd83c, 0xdffd, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdffe, 0x200d,
0x2640, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdfff, 0x200d, 0x2640, 0xfe0f, 0xd83d, 0xdeb4, 0x200d,
0x2642, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdffb, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c,
0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83d,
0xdeb4, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f, 0xd83d, 0xdeb4, 0xd83c, 0xdfff, 0x200d, 0x2642,
0xfe0f, 0xd83c, 0xdfc6, 0xd83e, 0xdd47, 0xd83e, 0xdd48, 0xd83e, 0xdd49, 0xd83c, 0xdfc5, 0xd83c,
0xdf96, 0xd83c, 0xdff5, 0xd83c, 0xdf97, 0xd83c, 0xdfab, 0xd83c, 0xdf9f, 0xd83c, 0xdfaa, 0xd83e,
0xdd39, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffb, 0x200d, 0x2640, 0xfe0f, 0xd83e,
0xdd39, 0xd83c, 0xdffc, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffd, 0x200d, 0x2640,
0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffe, 0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdfff,
0x200d, 0x2640, 0xfe0f, 0xd83e, 0xdd39, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffb,
0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffc, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd39,
0xd83c, 0xdffd, 0x200d, 0x2642, 0xfe0f, 0xd83e, 0xdd39, 0xd83c, 0xdffe, 0x200d, 0x2642, 0xfe0f,
0xd83e, 0xdd39, 0xd83c, 0xdfff, 0x200d, 0x2642, 0xfe0f, 0xd83c, 0xdfad, 0xd83c, 0xdfa8, 0xd83c,
0xdfac, 0xd83c, 0xdfa4, 0xd83c, 0xdfa7, 0xd83c, 0xdfbc, 0xd83c, 0xdfb9, 0xd83e, 0xdd41, 0xd83c,
0xdfb7, 0xd83c, 0xdfba, 0xd83c, 0xdfb8, 0xd83c, 0xdfbb, 0xd83c, 0xdfb2, 0x265f, 0xd83c, 0xdfaf,
0xd83c, 0xdfb3, 0xd83c, 0xdfae, 0xd83c, 0xdfb0, 0xd83e, 0xdde9, 0xd83d, 0xde97, 0xd83d, 0xde95,
0xd83d, 0xde99, 0xd83d, 0xde8c, 0xd83d, 0xde8e, 0xd83c, 0xdfce, 0xd83d, 0xde93, 0xd83d, 0xde91,
0xd83d, 0xde92, 0xd83d, 0xde90, 0xd83d, 0xde9a, 0xd83d, 0xde9b, 0xd83d, 0xde9c, 0xd83d, 0xdef4,
0xd83d, 0xdeb2, 0xd83d, 0xdef5, 0xd83c, 0xdfcd, 0xd83d, 0xdea8, 0xd83d, 0xde94, 0xd83d, 0xde8d,
0xd83d, 0xde98, 0xd83d, 0xde96, 0xd83d, 0xdea1, 0xd83d, 0xdea0, 0xd83d, 0xde9f, 0xd83d, 0xde83,
0xd83d, 0xde8b, 0xd83d, 0xde9e, 0xd83d, 0xde9d, 0xd83d, 0xde84, 0xd83d, 0xde85, 0xd83d, 0xde88,
0xd83d, 0xde82, 0xd83d, 0xde86, 0xd83d, 0xde87, 0xd83d, 0xde8a, 0xd83d, 0xde89, 0x2708, 0xd83d,
0xdeeb, 0xd83d, 0xdeec, 0xd83d, 0xdee9, 0xd83d, 0xdcba, 0xd83d, 0xdef0, 0xd83d, 0xde80, 0xd83d,
0xdef8, 0xd83d, 0xde81, 0xd83d, 0xdef6, 0x26f5, 0xd83d, 0xdea4, 0xd83d, 0xdee5, 0xd83d, 0xdef3,
0x26f4, 0xd83d, 0xdea2, 0x2693, 0x26fd, 0xd83d, 0xdea7, 0xd83d, 0xdea6, 0xd83d, 0xdea5, 0xd83d,
0xde8f, 0xd83d, 0xddfa, 0xd83d, 0xddff, 0xd83d, 0xddfd, 0xd83d, 0xddfc, 0xd83c, 0xdff0, 0xd83c,
0xdfef, 0xd83c, 0xdfdf, 0xd83c, 0xdfa1, 0xd83c, 0xdfa2, 0xd83c, 0xdfa0, 0x26f2, 0x26f1, 0xd83c,
0xdfd6, 0xd83c, 0xdfdd, 0xd83c, 0xdfdc, 0xd83c, 0xdf0b, 0x26f0, 0xd83c, 0xdfd4, 0xd83d, 0xddfb,
0xd83c, 0xdfd5, 0x26fa, 0xd83c, 0xdfe0, 0xd83c, 0xdfe1, 0xd83c, 0xdfd8, 0xd83c, 0xdfda, 0xd83c,
0xdfd7, 0xd83c, 0xdfed, 0xd83c, 0xdfe2, 0xd83c, 0xdfec, 0xd83c, 0xdfe3, 0xd83c, 0xdfe4, 0xd83c,
0xdfe5, 0xd83c, 0xdfe6, 0xd83c, 0xdfe8, 0xd83c, 0xdfea, 0xd83c, 0xdfeb, 0xd83c, 0xdfe9, 0xd83d,
0xdc92, 0xd83c, 0xdfdb, 0x26ea, 0xd83d, 0xdd4c, 0xd83d, 0xdd4d, 0xd83d, 0xdd4b, 0x26e9, 0xd83d,
0xdee4, 0xd83d, 0xdee3, 0xd83d, 0xddfe, 0xd83c, 0xdf91, 0xd83c, 0xdfde, 0xd83c, 0xdf05, 0xd83c,
0xdf04, 0xd83c, 0xdf20, 0xd83c, 0xdf87, 0xd83c, 0xdf86, 0xd83c, 0xdf07, 0xd83c, 0xdf06, 0xd83c,
0xdfd9, 0xd83c, 0xdf03, 0xd83c, 0xdf0c, 0xd83c, 0xdf09, 0xd83c, 0xdf01, 0x231a, 0xd83d, 0xdcf1,
0xd83d, 0xdcf2, 0xd83d, 0xdcbb, 0x2328, 0xd83d, 0xdda5, 0xd83d, 0xdda8, 0xd83d, 0xddb1, 0xd83d,
0xddb2, 0xd83d, 0xdd79, 0xd83d, 0xdddc, 0xd83d, 0xdcbd, 0xd83d, 0xdcbe, 0xd83d, 0xdcbf, 0xd83d,
0xdcc0, 0xd83d, 0xdcfc, 0xd83d, 0xdcf7, 0xd83d, 0xdcf8, 0xd83d, 0xdcf9, 0xd83c, 0xdfa5, 0xd83d,
0xdcfd, 0xd83c, 0xdf9e, 0xd83d, 0xdcde, 0x260e, 0xd83d, 0xdcdf, 0xd83d, 0xdce0, 0xd83d, 0xdcfa,
0xd83d, 0xdcfb, 0xd83c, 0xdf99, 0xd83c, 0xdf9a, 0xd83c, 0xdf9b, 0xd83e, 0xdded, 0x23f1, 0x23f2,
0x23f0, 0xd83d, 0xdd70, 0x231b, 0x23f3, 0xd83d, 0xdce1, 0xd83d, 0xdd0b, 0xd83d, 0xdd0c, 0xd83d,
0xdca1, 0xd83d, 0xdd26, 0xd83d, 0xdd6f, 0xd83e, 0xddef, 0xd83d, 0xdee2, 0xd83d, 0xdcb8, 0xd83d,
0xdcb5, 0xd83d, 0xdcb4, 0xd83d, 0xdcb6, 0xd83d, 0xdcb7, 0xd83d, 0xdcb0, 0xd83d, 0xdcb3, 0xd83d,
0xdc8e, 0x2696, 0xd83e, 0xddf0, 0xd83d, 0xdd27, 0xd83d, 0xdd28, 0x2692, 0xd83d, 0xdee0, 0x26cf,
0xd83d, 0xdd29, 0x2699, 0xd83e, 0xddf1, 0x26d3, 0xd83e, 0xddf2, 0xd83d, 0xdd2b, 0xd83d, 0xdca3,
0xd83e, 0xdde8, 0xd83d, 0xdd2a, 0xd83d, 0xdde1, 0x2694, 0xd83d, 0xdee1, 0xd83d, 0xdeac, 0x26b0,
0x26b1, 0xd83c, 0xdffa, 0xd83d, 0xdd2e, 0xd83d, 0xdcff, 0xd83e, 0xddff, 0xd83d, 0xdc88, 0x2697,
0xd83d, 0xdd2d, 0xd83d, 0xdd2c, 0xd83d, 0xdd73, 0xd83d, 0xdc8a, 0xd83d, 0xdc89, 0xd83e, 0xddec,
0xd83e, 0xdda0, 0xd83e, 0xddeb, 0xd83e, 0xddea, 0xd83c, 0xdf21, 0xd83e, 0xddf9, 0xd83e, 0xddfa,
0xd83e, 0xddfb, 0xd83d, 0xdebd, 0xd83d, 0xdeb0, 0xd83d, 0xdebf, 0xd83d, 0xdec1, 0xd83d, 0xdec0,
0xd83d, 0xdec0, 0xd83c, 0xdffb, 0xd83d, 0xdec0, 0xd83c, 0xdffc, 0xd83d, 0xdec0, 0xd83c, 0xdffd,
0xd83d, 0xdec0, 0xd83c, 0xdffe, 0xd83d, 0xdec0, 0xd83c, 0xdfff, 0xd83e, 0xddfc, 0xd83e, 0xddfd,
0xd83e, 0xddf4, 0xd83d, 0xdece, 0xd83d, 0xdd11, 0xd83d, 0xdddd, 0xd83d, 0xdeaa, 0xd83d, 0xdecb,
0xd83d, 0xdecf, 0xd83d, 0xdecc, 0xd83e, 0xddf8, 0xd83d, 0xddbc, 0xd83d, 0xdecd, 0xd83d, 0xded2,
0xd83c, 0xdf81, 0xd83c, 0xdf88, 0xd83c, 0xdf8f, 0xd83c, 0xdf80, 0xd83c, 0xdf8a, 0xd83c, 0xdf89,
0xd83c, 0xdf8e, 0xd83c, 0xdfee, 0xd83c, 0xdf90, 0xd83e, 0xdde7, 0x2709, 0xd83d, 0xdce9, 0xd83d,
0xdce8, 0xd83d, 0xdce7, 0xd83d, 0xdc8c, 0xd83d, 0xdce5, 0xd83d, 0xdce4, 0xd83d, 0xdce6, 0xd83c,
0xdff7, 0xd83d, 0xdcea, 0xd83d, 0xdceb, 0xd83d, 0xdcec, 0xd83d, 0xdced, 0xd83d, 0xdcee, 0xd83d,
0xdcef, 0xd83d, 0xdcdc, 0xd83d, 0xdcc3, 0xd83d, 0xdcc4, 0xd83d, 0xdcd1, 0xd83e, 0xddfe, 0xd83d,
0xdcca, 0xd83d, 0xdcc8, 0xd83d, 0xdcc9, 0xd83d, 0xddd2, 0xd83d, 0xddd3, 0xd83d, 0xdcc6, 0xd83d,
0xdcc5, 0xd83d, 0xddd1, 0xd83d, 0xdcc7, 0xd83d, 0xddc3, 0xd83d, 0xddf3, 0xd83d, 0xddc4, 0xd83d,
0xdccb, 0xd83d, 0xdcc1, 0xd83d, 0xdcc2, 0xd83d, 0xddc2, 0xd83d, 0xddde, 0xd83d, 0xdcf0, 0xd83d,
0xdcd3, 0xd83d, 0xdcd4, 0xd83d, 0xdcd2, 0xd83d, 0xdcd5, 0xd83d, 0xdcd7, 0xd83d, 0xdcd8, 0xd83d,
0xdcd9, 0xd83d, 0xdcda, 0xd83d, 0xdcd6, 0xd83d, 0xdd16, 0xd83e, 0xddf7, 0xd83d, 0xdd17, 0xd83d,
0xdcce, 0xd83d, 0xdd87, 0xd83d, 0xdcd0, 0xd83d, 0xdccf, 0xd83e, 0xddee, 0xd83d, 0xdccc, 0xd83d,
0xdccd, 0x2702, 0xd83d, 0xdd8a, 0xd83d, 0xdd8b, 0x2712, 0xd83d, 0xdd8c, 0xd83d, 0xdd8d, 0xd83d,
0xdcdd, 0x270f, 0xd83d, 0xdd0d, 0xd83d, 0xdd0e, 0xd83d, 0xdd0f, 0xd83d, 0xdd10, 0xd83d, 0xdd12,
0xd83d, 0xdd13, 0x2764, 0xd83e, 0xdde1, 0xd83d, 0xdc9b, 0xd83d, 0xdc9a, 0xd83d, 0xdc99, 0xd83d,
0xdc9c, 0xd83d, 0xdda4, 0xd83d, 0xdc94, 0x2763, 0xd83d, 0xdc95, 0xd83d, 0xdc9e, 0xd83d, 0xdc93,
0xd83d, 0xdc97, 0xd83d, 0xdc96, 0xd83d, 0xdc98, 0xd83d, 0xdc9d, 0xd83d, 0xdc9f, 0x262e, 0x271d,
0x262a, 0xd83d, 0xdd49, 0x2638, 0x2721, 0xd83d, 0xdd2f, 0xd83d, 0xdd4e, 0x262f, 0x2626, 0xd83d,
0xded0, 0x26ce, 0x2648, 0x2649, 0x264a, 0x264b, 0x264c, 0x264d, 0x264e, 0x264f, 0x2650, 0x2651,
0x2652, 0x2653, 0xd83c, 0xdd94, 0x269b, 0xd83c, 0xde51, 0x2622, 0x2623, 0xd83d, 0xdcf4, 0xd83d,
0xdcf3, 0xd83c, 0xde36, 0xd83c, 0xde1a, 0xd83c, 0xde38, 0xd83c, 0xde3a, 0xd83c, 0xde37, 0x2734,
0xd83c, 0xdd9a, 0xd83d, 0xdcae, 0xd83c, 0xde50, 0x3299, 0x3297, 0xd83c, 0xde34, 0xd83c, 0xde35,
0xd83c, 0xde39, 0xd83c, 0xde32, 0xd83c, 0xdd70, 0xd83c, 0xdd71, 0xd83c, 0xdd8e, 0xd83c, 0xdd91,
0xd83c, 0xdd7e, 0xd83c, 0xdd98, 0x274c, 0x2b55, 0xd83d, 0xded1, 0x26d4, 0xd83d, 0xdcdb, 0xd83d,
0xdeab, 0xd83d, 0xdcaf, 0xd83d, 0xdca2, 0x2668, 0xd83d, 0xdeb7, 0xd83d, 0xdeaf, 0xd83d, 0xdeb3,
0xd83d, 0xdeb1, 0xd83d, 0xdd1e, 0xd83d, 0xdcf5, 0xd83d, 0xdead, 0x2757, 0x2755, 0x2753, 0x2754,
0x203c, 0x2049, 0xd83d, 0xdd05, 0xd83d, 0xdd06, 0x303d, 0x26a0, 0xd83d, 0xdeb8, 0xd83d, 0xdd31,
0x269c, 0xd83d, 0xdd30, 0x267b, 0x2705, 0xd83c, 0xde2f, 0xd83d, 0xdcb9, 0x2747, 0x2733, 0x274e,
0xd83c, 0xdf10, 0xd83d, 0xdca0, 0x24c2, 0xd83c, 0xdf00, 0xd83d, 0xdca4, 0xd83c, 0xdfe7, 0xd83d,
0xdebe, 0x267f, 0xd83c, 0xdd7f, 0xd83c, 0xde33, 0xd83c, 0xde02, 0xd83d, 0xdec2, 0xd83d, 0xdec3,
0xd83d, 0xdec4, 0xd83d, 0xdec5, 0xd83d, 0xdeb9, 0xd83d, 0xdeba, 0xd83d, 0xdebc, 0xd83d, 0xdebb,
0xd83d, 0xdeae, 0xd83c, 0xdfa6, 0xd83d, 0xdcf6, 0xd83c, 0xde01, 0xd83d, 0xdd23, 0x2139, 0xd83d,
0xdd24, 0xd83d, 0xdd21, 0xd83d, 0xdd20, 0xd83c, 0xdd96, 0xd83c, 0xdd97, 0xd83c, 0xdd99, 0xd83c,
0xdd92, 0xd83c, 0xdd95, 0xd83c, 0xdd93, 0x30, 0xfe0f, 0x20e3, 0x31, 0xfe0f, 0x20e3, 0x32,
0xfe0f, 0x20e3, 0x33, 0xfe0f, 0x20e3, 0x34, 0xfe0f, 0x20e3, 0x35, 0xfe0f, 0x20e3, 0x36,
0xfe0f, 0x20e3, 0x37, 0xfe0f, 0x20e3, 0x38, 0xfe0f, 0x20e3, 0x39, 0xfe0f, 0x20e3, 0xd83d,
0xdd1f, 0xd83d, 0xdd22, 0x23, 0xfe0f, 0x20e3, 0x2a, 0xfe0f, 0x20e3, 0x23cf, 0x25b6, 0x23f8,
0x23ef, 0x23f9, 0x23fa, 0x23ed, 0x23ee, 0x23e9, 0x23ea, 0x23eb, 0x23ec, 0x25c0, 0xd83d, 0xdd3c,
0xd83d, 0xdd3d, 0x27a1, 0x2b05, 0x2b06, 0x2b07, 0x2197, 0x2198, 0x2199, 0x2196, 0x2195, 0x2194,
0x21aa, 0x21a9, 0x2934, 0x2935, 0xd83d, 0xdd00, 0xd83d, 0xdd01, 0xd83d, 0xdd02, 0xd83d, 0xdd04,
0xd83d, 0xdd03, 0xd83c, 0xdfb5, 0xd83c, 0xdfb6, 0x2795, 0x2796, 0x2797, 0x2716, 0x267e, 0xd83d,
0xdcb2, 0xd83d, 0xdcb1, 0x2122, 0xa9, 0xae, 0xd83d, 0xdde8, 0xd83d, 0xdc41, 0x200d, 0xd83d,
0xdde8, 0xd83d, 0xdd1a, 0xd83d, 0xdd19, 0xd83d, 0xdd1b, 0xd83d, 0xdd1d, 0xd83d, 0xdd1c, 0x3030,
0x27b0, 0x27bf, 0x2714, 0x2611, 0xd83d, 0xdd18, 0x26aa, 0x26ab, 0xd83d, 0xdd34, 0xd83d, 0xdd35,
0xd83d, 0xdd3a, 0xd83d, 0xdd3b, 0xd83d, 0xdd38, 0xd83d, 0xdd39, 0xd83d, 0xdd36, 0xd83d, 0xdd37,
0xd83d, 0xdd33, 0xd83d, 0xdd32, 0x25aa, 0x25ab, 0x25fe, 0x25fd, 0x25fc, 0x25fb, 0x2b1b, 0x2b1c,
0xd83d, 0xdd08, 0xd83d, 0xdd07, 0xd83d, 0xdd09, 0xd83d, 0xdd0a, 0xd83d, 0xdd14, 0xd83d, 0xdd15,
0xd83d, 0xdce3, 0xd83d, 0xdce2, 0xd83d, 0xdcac, 0xd83d, 0xdcad, 0xd83d, 0xddef, 0x2660, 0x2663,
0x2665, 0x2666, 0xd83c, 0xdccf, 0xd83c, 0xdfb4, 0xd83c, 0xdc04, 0xd83d, 0xdd50, 0xd83d, 0xdd51,
0xd83d, 0xdd52, 0xd83d, 0xdd53, 0xd83d, 0xdd54, 0xd83d, 0xdd55, 0xd83d, 0xdd56, 0xd83d, 0xdd57,
0xd83d, 0xdd58, 0xd83d, 0xdd59, 0xd83d, 0xdd5a, 0xd83d, 0xdd5b, 0xd83d, 0xdd5c, 0xd83d, 0xdd5d,
0xd83d, 0xdd5e, 0xd83d, 0xdd5f, 0xd83d, 0xdd60, 0xd83d, 0xdd61, 0xd83d, 0xdd62, 0xd83d, 0xdd63,
0xd83d, 0xdd64, 0xd83d, 0xdd65, 0xd83d, 0xdd66, 0xd83d, 0xdd67, 0xd83c, 0xdff3, 0xd83c, 0xdff4,
0xd83c, 0xdff4, 0x200d, 0x2620, 0xfe0f, 0xd83c, 0xdfc1, 0xd83d, 0xdea9, 0xd83c, 0xdff3, 0xfe0f,
0x200d, 0xd83c, 0xdf08, 0xd83c, 0xddfa, 0xd83c, 0xddf3, 0xd83c, 0xdde6, 0xd83c, 0xddeb, 0xd83c,
0xdde6, 0xd83c, 0xddfd, 0xd83c, 0xdde6, 0xd83c, 0xddf1, 0xd83c, 0xdde9, 0xd83c, 0xddff, 0xd83c,
0xdde6, 0xd83c, 0xddf8, 0xd83c, 0xdde6, 0xd83c, 0xdde9, 0xd83c, 0xdde6, 0xd83c, 0xddf4, 0xd83c,
0xdde6, 0xd83c, 0xddee, 0xd83c, 0xdde6, 0xd83c, 0xddf6, 0xd83c, 0xdde6, 0xd83c, 0xddec, 0xd83c,
0xdde6, 0xd83c, 0xddf7, 0xd83c, 0xdde6, 0xd83c, 0xddf2, 0xd83c, 0xdde6, 0xd83c, 0xddfc, 0xd83c,
0xdde6, 0xd83c, 0xddfa, 0xd83c, 0xdde6, 0xd83c, 0xddf9, 0xd83c, 0xdde6, 0xd83c, 0xddff, 0xd83c,
0xdde7, 0xd83c, 0xddf8, 0xd83c, 0xdde7, 0xd83c, 0xdded, 0xd83c, 0xdde7, 0xd83c, 0xdde9, 0xd83c,
0xdde7, 0xd83c, 0xdde7, 0xd83c, 0xdde7, 0xd83c, 0xddfe, 0xd83c, 0xdde7, 0xd83c, 0xddea, 0xd83c,
0xdde7, 0xd83c, 0xddff, 0xd83c, 0xdde7, 0xd83c, 0xddef, 0xd83c, 0xdde7, 0xd83c, 0xddf2, 0xd83c,
0xdde7, 0xd83c, 0xddf9, 0xd83c, 0xdde7, 0xd83c, 0xddf4, 0xd83c, 0xdde7, 0xd83c, 0xdde6, 0xd83c,
0xdde7, 0xd83c, 0xddfc, 0xd83c, 0xdde7, 0xd83c, 0xddf7, 0xd83c, 0xddee, 0xd83c, 0xddf4, 0xd83c,
0xddfb, 0xd83c, 0xddec, 0xd83c, 0xdde7, 0xd83c, 0xddf3, 0xd83c, 0xdde7, 0xd83c, 0xddec, 0xd83c,
0xdde7, 0xd83c, 0xddeb, 0xd83c, 0xdde7, 0xd83c, 0xddee, 0xd83c, 0xddf0, 0xd83c, 0xdded, 0xd83c,
0xdde8, 0xd83c, 0xddf2, 0xd83c, 0xdde8, 0xd83c, 0xdde6, 0xd83c, 0xddee, 0xd83c, 0xdde8, 0xd83c,
0xdde8, 0xd83c, 0xddfb, 0xd83c, 0xdde7, 0xd83c, 0xddf6, 0xd83c, 0xddf0, 0xd83c, 0xddfe, 0xd83c,
0xdde8, 0xd83c, 0xddeb, 0xd83c, 0xddf9, 0xd83c, 0xdde9, 0xd83c, 0xdde8, 0xd83c, 0xddf1, 0xd83c,
0xdde8, 0xd83c, 0xddf3, 0xd83c, 0xdde8, 0xd83c, 0xddfd, 0xd83c, 0xdde8, 0xd83c, 0xdde8, 0xd83c,
0xdde8, 0xd83c, 0xddf4, 0xd83c, 0xddf0, 0xd83c, 0xddf2, 0xd83c, 0xdde8, 0xd83c, 0xddec, 0xd83c,
0xdde8, 0xd83c, 0xdde9, 0xd83c, 0xdde8, 0xd83c, 0xddf0, 0xd83c, 0xdde8, 0xd83c, 0xddf7, 0xd83c,
0xdde8, 0xd83c, 0xddee, 0xd83c, 0xdded, 0xd83c, 0xddf7, 0xd83c, 0xdde8, 0xd83c, 0xddfa, 0xd83c,
0xdde8, 0xd83c, 0xddfc, 0xd83c, 0xdde8, 0xd83c, 0xddfe, 0xd83c, 0xdde8, 0xd83c, 0xddff, 0xd83c,
0xdde9, 0xd83c, 0xddf0, 0xd83c, 0xdde9, 0xd83c, 0xddef, 0xd83c, 0xdde9, 0xd83c, 0xddf2, 0xd83c,
0xdde9, 0xd83c, 0xddf4, 0xd83c, 0xddea, 0xd83c, 0xdde8, 0xd83c, 0xddea, 0xd83c, 0xddec, 0xd83c,
0xddf8, 0xd83c, 0xddfb, 0xd83c, 0xddec, 0xd83c, 0xddf6, 0xd83c, 0xddea, 0xd83c, 0xddf7, 0xd83c,
0xddea, 0xd83c, 0xddea, 0xd83c, 0xddea, 0xd83c, 0xddf9, 0xd83c, 0xddea, 0xd83c, 0xddfa, 0xd83c,
0xddeb, 0xd83c, 0xddf0, 0xd83c, 0xddeb, 0xd83c, 0xddf4, 0xd83c, 0xddeb, 0xd83c, 0xddef, 0xd83c,
0xddeb, 0xd83c, 0xddee, 0xd83c, 0xddeb, 0xd83c, 0xddf7, 0xd83c, 0xddec, 0xd83c, 0xddeb, 0xd83c,
0xddf5, 0xd83c, 0xddeb, 0xd83c, 0xddf9, 0xd83c, 0xddeb, 0xd83c, 0xddec, 0xd83c, 0xdde6, 0xd83c,
0xddec, 0xd83c, 0xddf2, 0xd83c, 0xddec, 0xd83c, 0xddea, 0xd83c, 0xdde9, 0xd83c, 0xddea, 0xd83c,
0xddec, 0xd83c, 0xdded, 0xd83c, 0xddec, 0xd83c, 0xddee, 0xd83c, 0xddec, 0xd83c, 0xddf7, 0xd83c,
0xddec, 0xd83c, 0xddf1, 0xd83c, 0xddec, 0xd83c, 0xdde9, 0xd83c, 0xddec, 0xd83c, 0xddf5, 0xd83c,
0xddec, 0xd83c, 0xddfa, 0xd83c, 0xddec, 0xd83c, 0xddf9, 0xd83c, 0xddec, 0xd83c, 0xddec, 0xd83c,
0xddec, 0xd83c, 0xddf3, 0xd83c, 0xddec, 0xd83c, 0xddfc, 0xd83c, 0xddec, 0xd83c, 0xddfe, 0xd83c,
0xdded, 0xd83c, 0xddf9, 0xd83c, 0xdded, 0xd83c, 0xddf3, 0xd83c, 0xdded, 0xd83c, 0xddf0, 0xd83c,
0xdded, 0xd83c, 0xddfa, 0xd83c, 0xddee, 0xd83c, 0xddf8, 0xd83c, 0xddee, 0xd83c, 0xddf3, 0xd83c,
0xddee, 0xd83c, 0xdde9, 0xd83c, 0xddee, 0xd83c, 0xddf7, 0xd83c, 0xddee, 0xd83c, 0xddf6, 0xd83c,
0xddee, 0xd83c, 0xddea, 0xd83c, 0xddee, 0xd83c, 0xddf2, 0xd83c, 0xddee, 0xd83c, 0xddf1, 0xd83c,
0xddee, 0xd83c, 0xddf9, 0xd83c, 0xddef, 0xd83c, 0xddf2, 0xd83c, 0xddef, 0xd83c, 0xddf5, 0xd83c,
0xdf8c, 0xd83c, 0xddef, 0xd83c, 0xddea, 0xd83c, 0xddef, 0xd83c, 0xddf4, 0xd83c, 0xddf0, 0xd83c,
0xddff, 0xd83c, 0xddf0, 0xd83c, 0xddea, 0xd83c, 0xddf0, 0xd83c, 0xddee, 0xd83c, 0xddfd, 0xd83c,
0xddf0, 0xd83c, 0xddf0, 0xd83c, 0xddfc, 0xd83c, 0xddf0, 0xd83c, 0xddec, 0xd83c, 0xddf1, 0xd83c,
0xdde6, 0xd83c, 0xddf1, 0xd83c, 0xddfb, 0xd83c, 0xddf1, 0xd83c, 0xdde7, 0xd83c, 0xddf1, 0xd83c,
0xddf8, 0xd83c, 0xddf1, 0xd83c, 0xddf7, 0xd83c, 0xddf1, 0xd83c, 0xddfe, 0xd83c, 0xddf1, 0xd83c,
0xddee, 0xd83c, 0xddf1, 0xd83c, 0xddf9, 0xd83c, 0xddf1, 0xd83c, 0xddfa, 0xd83c, 0xddf2, 0xd83c,
0xddf4, 0xd83c, 0xddf2, 0xd83c, 0xddf0, 0xd83c, 0xddf2, 0xd83c, 0xddec, 0xd83c, 0xddf2, 0xd83c,
0xddfc, 0xd83c, 0xddf2, 0xd83c, 0xddfe, 0xd83c, 0xddf2, 0xd83c, 0xddfb, 0xd83c, 0xddf2, 0xd83c,
0xddf1, 0xd83c, 0xddf2, 0xd83c, 0xddf9, 0xd83c, 0xddf2, 0xd83c, 0xdded, 0xd83c, 0xddf2, 0xd83c,
0xddf6, 0xd83c, 0xddf2, 0xd83c, 0xddf7, 0xd83c, 0xddf2, 0xd83c, 0xddfa, 0xd83c, 0xddfe, 0xd83c,
0xddf9, 0xd83c, 0xddf2, 0xd83c, 0xddfd, 0xd83c, 0xddeb, 0xd83c, 0xddf2, 0xd83c, 0xddf2, 0xd83c,
0xdde9, 0xd83c, 0xddf2, 0xd83c, 0xdde8, 0xd83c, 0xddf2, 0xd83c, 0xddf3, 0xd83c, 0xddf2, 0xd83c,
0xddea, 0xd83c, 0xddf2, 0xd83c, 0xddf8, 0xd83c, 0xddf2, 0xd83c, 0xdde6, 0xd83c, 0xddf2, 0xd83c,
0xddff, 0xd83c, 0xddf2, 0xd83c, 0xddf2, 0xd83c, 0xddf3, 0xd83c, 0xdde6, 0xd83c, 0xddf3, 0xd83c,
0xddf7, 0xd83c, 0xddf3, 0xd83c, 0xddf5, 0xd83c, 0xddf3, 0xd83c, 0xddf1, 0xd83c, 0xddf3, 0xd83c,
0xdde8, 0xd83c, 0xddf3, 0xd83c, 0xddff, 0xd83c, 0xddf3, 0xd83c, 0xddee, 0xd83c, 0xddf3, 0xd83c,
0xddea, 0xd83c, 0xddf3, 0xd83c, 0xddec, 0xd83c, 0xddf3, 0xd83c, 0xddfa, 0xd83c, 0xddf3, 0xd83c,
0xddeb, 0xd83c, 0xddf0, 0xd83c, 0xddf5, 0xd83c, 0xddf2, 0xd83c, 0xddf5, 0xd83c, 0xddf3, 0xd83c,
0xddf4, 0xd83c, 0xddf4, 0xd83c, 0xddf2, 0xd83c, 0xddf5, 0xd83c, 0xddf0, 0xd83c, 0xddf5, 0xd83c,
0xddfc, 0xd83c, 0xddf5, 0xd83c, 0xddf8, 0xd83c, 0xddf5, 0xd83c, 0xdde6, 0xd83c, 0xddf5, 0xd83c,
0xddec, 0xd83c, 0xddf5, 0xd83c, 0xddfe, 0xd83c, 0xddf5, 0xd83c, 0xddea, 0xd83c, 0xddf5, 0xd83c,
0xdded, 0xd83c, 0xddf5, 0xd83c, 0xddf3, 0xd83c, 0xddf5, 0xd83c, 0xddf1, 0xd83c, 0xddf5, 0xd83c,
0xddf9, 0xd83c, 0xddf5, 0xd83c, 0xddf7, 0xd83c, 0xddf6, 0xd83c, 0xdde6, 0xd83c, 0xddf7, 0xd83c,
0xddea, 0xd83c, 0xddf7, 0xd83c, 0xddf4, 0xd83c, 0xddf7, 0xd83c, 0xddfa, 0xd83c, 0xddf7, 0xd83c,
0xddfc, 0xd83c, 0xddfc, 0xd83c, 0xddf8, 0xd83c, 0xddf8, 0xd83c, 0xddf2, 0xd83c, 0xddf8, 0xd83c,
0xddf9, 0xd83c, 0xddf8, 0xd83c, 0xdde6, 0xd83c, 0xddf8, 0xd83c, 0xddf3, 0xd83c, 0xddf7, 0xd83c,
0xddf8, 0xd83c, 0xddf8, 0xd83c, 0xdde8, 0xd83c, 0xddf8, 0xd83c, 0xddf1, 0xd83c, 0xddf8, 0xd83c,
0xddec, 0xd83c, 0xddf8, 0xd83c, 0xddfd, 0xd83c, 0xddf8, 0xd83c, 0xddf0, 0xd83c, 0xddf8, 0xd83c,
0xddee, 0xd83c, 0xddec, 0xd83c, 0xddf8, 0xd83c, 0xddf8, 0xd83c, 0xdde7, 0xd83c, 0xddf8, 0xd83c,
0xddf4, 0xd83c, 0xddff, 0xd83c, 0xdde6, 0xd83c, 0xddf0, 0xd83c, 0xddf7, 0xd83c, 0xddf8, 0xd83c,
0xddf8, 0xd83c, 0xddea, 0xd83c, 0xddf8, 0xd83c, 0xddf1, 0xd83c, 0xddf0, 0xd83c, 0xdde7, 0xd83c,
0xddf1, 0xd83c, 0xddf8, 0xd83c, 0xdded, 0xd83c, 0xddf0, 0xd83c, 0xddf3, 0xd83c, 0xddf1, 0xd83c,
0xdde8, 0xd83c, 0xddf5, 0xd83c, 0xddf2, 0xd83c, 0xddfb, 0xd83c, 0xdde8, 0xd83c, 0xddf8, 0xd83c,
0xdde9, 0xd83c, 0xddf8, 0xd83c, 0xddf7, 0xd83c, 0xddf8, 0xd83c, 0xddff, 0xd83c, 0xddf8, 0xd83c,
0xddea, 0xd83c, 0xdde8, 0xd83c, 0xdded, 0xd83c, 0xddf8, 0xd83c, 0xddfe, 0xd83c, 0xddf9, 0xd83c,
0xddfc, 0xd83c, 0xddf9, 0xd83c, 0xddef, 0xd83c, 0xddf9, 0xd83c, 0xddff, 0xd83c, 0xddf9, 0xd83c,
0xdded, 0xd83c, 0xddf9, 0xd83c, 0xddf1, 0xd83c, 0xddf9, 0xd83c, 0xddec, 0xd83c, 0xddf9, 0xd83c,
0xddf0, 0xd83c, 0xddf9, 0xd83c, 0xddf4, 0xd83c, 0xddf9, 0xd83c, 0xddf9, 0xd83c, 0xddf9, 0xd83c,
0xddf3, 0xd83c, 0xddf9, 0xd83c, 0xddf7, 0xd83c, 0xddf9, 0xd83c, 0xddf2, 0xd83c, 0xddf9, 0xd83c,
0xdde8, 0xd83c, 0xddf9, 0xd83c, 0xddfb, 0xd83c, 0xddfb, 0xd83c, 0xddee, 0xd83c, 0xddfa, 0xd83c,
0xddec, 0xd83c, 0xddfa, 0xd83c, 0xdde6, 0xd83c, 0xdde6, 0xd83c, 0xddea, 0xd83c, 0xddec, 0xd83c,
0xdde7, 0xd83c, 0xdff4, 0xdb40, 0xdc67, 0xdb40, 0xdc62, 0xdb40, 0xdc65, 0xdb40, 0xdc6e, 0xdb40,
0xdc67, 0xdb40, 0xdc7f, 0xd83c, 0xdff4, 0xdb40, 0xdc67, 0xdb40, 0xdc62, 0xdb40, 0xdc73, 0xdb40,
0xdc63, 0xdb40, 0xdc74, 0xdb40, 0xdc7f, 0xd83c, 0xdff4, 0xdb40, 0xdc67, 0xdb40, 0xdc62, 0xdb40,
0xdc77, 0xdb40, 0xdc6c, 0xdb40, 0xdc73, 0xdb40, 0xdc7f, 0xd83c, 0xddfa, 0xd83c, 0xddf8, 0xd83c,
0xddfa, 0xd83c, 0xddfe, 0xd83c, 0xddfa, 0xd83c, 0xddff, 0xd83c, 0xddfb, 0xd83c, 0xddfa, 0xd83c,
0xddfb, 0xd83c, 0xdde6, 0xd83c, 0xddfb, 0xd83c, 0xddea, 0xd83c, 0xddfb, 0xd83c, 0xddf3, 0xd83c,
0xddfc, 0xd83c, 0xddeb, 0xd83c, 0xddea, 0xd83c, 0xdded, 0xd83c, 0xddfe, 0xd83c, 0xddea, 0xd83c,
0xddff, 0xd83c, 0xddf2, 0xd83c, 0xddff, 0xd83c, 0xddfc };

const DataStruct Data[] = {
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(112), uint32(4), uint32(0), uint32(0) },
	{ uint32(112), uint32(4), uint32(0), uint32(0) },
	{ uint32(112), uint32(4), uint32(0), uint32(0) },
	{ uint32(112), uint32(4), uint32(0), uint32(0) },
	{ uint32(112), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(118), uint32(4), uint32(0), uint32(0) },
	{ uint32(118), uint32(4), uint32(0), uint32(0) },
	{ uint32(118), uint32(4), uint32(0), uint32(0) },
	{ uint32(118), uint32(4), uint32(0), uint32(0) },
	{ uint32(118), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(124), uint32(4), uint32(0), uint32(0) },
	{ uint32(124), uint32(4), uint32(0), uint32(0) },
	{ uint32(124), uint32(4), uint32(0), uint32(0) },
	{ uint32(124), uint32(4), uint32(0), uint32(0) },
	{ uint32(124), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(130), uint32(4), uint32(0), uint32(0) },
	{ uint32(130), uint32(4), uint32(0), uint32(0) },
	{ uint32(130), uint32(4), uint32(0), uint32(0) },
	{ uint32(130), uint32(4), uint32(0), uint32(0) },
	{ uint32(130), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(137), uint32(4), uint32(0), uint32(0) },
	{ uint32(137), uint32(4), uint32(0), uint32(0) },
	{ uint32(137), uint32(4), uint32(0), uint32(0) },
	{ uint32(137), uint32(4), uint32(0), uint32(0) },
	{ uint32(137), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(143), uint32(4), uint32(0), uint32(0) },
	{ uint32(143), uint32(4), uint32(0), uint32(0) },
	{ uint32(143), uint32(4), uint32(0), uint32(0) },
	{ uint32(143), uint32(4), uint32(0), uint32(0) },
	{ uint32(143), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(149), uint32(4), uint32(0), uint32(0) },
	{ uint32(149), uint32(4), uint32(0), uint32(0) },
	{ uint32(149), uint32(4), uint32(0), uint32(0) },
	{ uint32(149), uint32(4), uint32(0), uint32(0) },
	{ uint32(149), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(1) },
	{ uint32(155), uint32(3), uint32(0), uint32(0) },
	{ uint32(155), uint32(3), uint32(0), uint32(0) },
	{ uint32(155), uint32(3), uint32(0), uint32(0) },
	{ uint32(155), uint32(3), uint32(0), uint32(0) },
	{ uint32(155), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(161), uint32(4), uint32(0), uint32(0) },
	{ uint32(161), uint32(4), uint32(0), uint32(0) },
	{ uint32(161), uint32(4), uint32(0), uint32(0) },
	{ uint32(161), uint32(4), uint32(0), uint32(0) },
	{ uint32(161), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(167), uint32(4), uint32(0), uint32(0) },
	{ uint32(167), uint32(4), uint32(0), uint32(0) },
	{ uint32(167), uint32(4), uint32(0), uint32(0) },
	{ uint32(167), uint32(4), uint32(0), uint32(0) },
	{ uint32(167), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(173), uint32(4), uint32(0), uint32(0) },
	{ uint32(173), uint32(4), uint32(0), uint32(0) },
	{ uint32(173), uint32(4), uint32(0), uint32(0) },
	{ uint32(173), uint32(4), uint32(0), uint32(0) },
	{ uint32(173), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(1) },
	{ uint32(179), uint32(3), uint32(0), uint32(0) },
	{ uint32(179), uint32(3), uint32(0), uint32(0) },
	{ uint32(179), uint32(3), uint32(0), uint32(0) },
	{ uint32(179), uint32(3), uint32(0), uint32(0) },
	{ uint32(179), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(185), uint32(4), uint32(0), uint32(0) },
	{ uint32(185), uint32(4), uint32(0), uint32(0) },
	{ uint32(185), uint32(4), uint32(0), uint32(0) },
	{ uint32(185), uint32(4), uint32(0), uint32(0) },
	{ uint32(185), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(191), uint32(4), uint32(0), uint32(0) },
	{ uint32(191), uint32(4), uint32(0), uint32(0) },
	{ uint32(191), uint32(4), uint32(0), uint32(0) },
	{ uint32(191), uint32(4), uint32(0), uint32(0) },
	{ uint32(191), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(197), uint32(4), uint32(0), uint32(0) },
	{ uint32(197), uint32(4), uint32(0), uint32(0) },
	{ uint32(197), uint32(4), uint32(0), uint32(0) },
	{ uint32(197), uint32(4), uint32(0), uint32(0) },
	{ uint32(197), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(203), uint32(4), uint32(0), uint32(0) },
	{ uint32(203), uint32(4), uint32(0), uint32(0) },
	{ uint32(203), uint32(4), uint32(0), uint32(0) },
	{ uint32(203), uint32(4), uint32(0), uint32(0) },
	{ uint32(203), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(209), uint32(4), uint32(0), uint32(0) },
	{ uint32(209), uint32(4), uint32(0), uint32(0) },
	{ uint32(209), uint32(4), uint32(0), uint32(0) },
	{ uint32(209), uint32(4), uint32(0), uint32(0) },
	{ uint32(209), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(215), uint32(4), uint32(0), uint32(0) },
	{ uint32(215), uint32(4), uint32(0), uint32(0) },
	{ uint32(215), uint32(4), uint32(0), uint32(0) },
	{ uint32(215), uint32(4), uint32(0), uint32(0) },
	{ uint32(215), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(221), uint32(4), uint32(0), uint32(0) },
	{ uint32(221), uint32(4), uint32(0), uint32(0) },
	{ uint32(221), uint32(4), uint32(0), uint32(0) },
	{ uint32(221), uint32(4), uint32(0), uint32(0) },
	{ uint32(221), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(1) },
	{ uint32(227), uint32(3), uint32(0), uint32(0) },
	{ uint32(227), uint32(3), uint32(0), uint32(0) },
	{ uint32(227), uint32(3), uint32(0), uint32(0) },
	{ uint32(227), uint32(3), uint32(0), uint32(0) },
	{ uint32(227), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(1) },
	{ uint32(233), uint32(3), uint32(0), uint32(0) },
	{ uint32(233), uint32(3), uint32(0), uint32(0) },
	{ uint32(233), uint32(3), uint32(0), uint32(0) },
	{ uint32(233), uint32(3), uint32(0), uint32(0) },
	{ uint32(233), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(239), uint32(4), uint32(0), uint32(0) },
	{ uint32(239), uint32(4), uint32(0), uint32(0) },
	{ uint32(239), uint32(4), uint32(0), uint32(0) },
	{ uint32(239), uint32(4), uint32(0), uint32(0) },
	{ uint32(239), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(245), uint32(4), uint32(0), uint32(0) },
	{ uint32(245), uint32(4), uint32(0), uint32(0) },
	{ uint32(245), uint32(4), uint32(0), uint32(0) },
	{ uint32(245), uint32(4), uint32(0), uint32(0) },
	{ uint32(245), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(251), uint32(4), uint32(0), uint32(0) },
	{ uint32(251), uint32(4), uint32(0), uint32(0) },
	{ uint32(251), uint32(4), uint32(0), uint32(0) },
	{ uint32(251), uint32(4), uint32(0), uint32(0) },
	{ uint32(251), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(257), uint32(4), uint32(0), uint32(0) },
	{ uint32(257), uint32(4), uint32(0), uint32(0) },
	{ uint32(257), uint32(4), uint32(0), uint32(0) },
	{ uint32(257), uint32(4), uint32(0), uint32(0) },
	{ uint32(257), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(263), uint32(4), uint32(0), uint32(0) },
	{ uint32(263), uint32(4), uint32(0), uint32(0) },
	{ uint32(263), uint32(4), uint32(0), uint32(0) },
	{ uint32(263), uint32(4), uint32(0), uint32(0) },
	{ uint32(263), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(269), uint32(4), uint32(0), uint32(0) },
	{ uint32(269), uint32(4), uint32(0), uint32(0) },
	{ uint32(269), uint32(4), uint32(0), uint32(0) },
	{ uint32(269), uint32(4), uint32(0), uint32(0) },
	{ uint32(269), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(275), uint32(4), uint32(0), uint32(0) },
	{ uint32(275), uint32(4), uint32(0), uint32(0) },
	{ uint32(275), uint32(4), uint32(0), uint32(0) },
	{ uint32(275), uint32(4), uint32(0), uint32(0) },
	{ uint32(275), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(1) },
	{ uint32(281), uint32(3), uint32(0), uint32(0) },
	{ uint32(281), uint32(3), uint32(0), uint32(0) },
	{ uint32(281), uint32(3), uint32(0), uint32(0) },
	{ uint32(281), uint32(3), uint32(0), uint32(0) },
	{ uint32(281), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(287), uint32(4), uint32(0), uint32(0) },
	{ uint32(287), uint32(4), uint32(0), uint32(0) },
	{ uint32(287), uint32(4), uint32(0), uint32(0) },
	{ uint32(287), uint32(4), uint32(0), uint32(0) },
	{ uint32(287), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(293), uint32(4), uint32(0), uint32(0) },
	{ uint32(293), uint32(4), uint32(0), uint32(0) },
	{ uint32(293), uint32(4), uint32(0), uint32(0) },
	{ uint32(293), uint32(4), uint32(0), uint32(0) },
	{ uint32(293), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(299), uint32(4), uint32(0), uint32(0) },
	{ uint32(299), uint32(4), uint32(0), uint32(0) },
	{ uint32(299), uint32(4), uint32(0), uint32(0) },
	{ uint32(299), uint32(4), uint32(0), uint32(0) },
	{ uint32(299), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(310), uint32(4), uint32(0), uint32(0) },
	{ uint32(310), uint32(4), uint32(0), uint32(0) },
	{ uint32(310), uint32(4), uint32(0), uint32(0) },
	{ uint32(310), uint32(4), uint32(0), uint32(0) },
	{ uint32(310), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(316), uint32(4), uint32(0), uint32(0) },
	{ uint32(316), uint32(4), uint32(0), uint32(0) },
	{ uint32(316), uint32(4), uint32(0), uint32(0) },
	{ uint32(316), uint32(4), uint32(0), uint32(0) },
	{ uint32(316), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(329), uint32(4), uint32(0), uint32(0) },
	{ uint32(329), uint32(4), uint32(0), uint32(0) },
	{ uint32(329), uint32(4), uint32(0), uint32(0) },
	{ uint32(329), uint32(4), uint32(0), uint32(0) },
	{ uint32(329), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(335), uint32(4), uint32(0), uint32(0) },
	{ uint32(335), uint32(4), uint32(0), uint32(0) },
	{ uint32(335), uint32(4), uint32(0), uint32(0) },
	{ uint32(335), uint32(4), uint32(0), uint32(0) },
	{ uint32(335), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(341), uint32(4), uint32(0), uint32(0) },
	{ uint32(341), uint32(4), uint32(0), uint32(0) },
	{ uint32(341), uint32(4), uint32(0), uint32(0) },
	{ uint32(341), uint32(4), uint32(0), uint32(0) },
	{ uint32(341), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(347), uint32(4), uint32(0), uint32(0) },
	{ uint32(347), uint32(4), uint32(0), uint32(0) },
	{ uint32(347), uint32(4), uint32(0), uint32(0) },
	{ uint32(347), uint32(4), uint32(0), uint32(0) },
	{ uint32(347), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(353), uint32(4), uint32(0), uint32(0) },
	{ uint32(353), uint32(4), uint32(0), uint32(0) },
	{ uint32(353), uint32(4), uint32(0), uint32(0) },
	{ uint32(353), uint32(4), uint32(0), uint32(0) },
	{ uint32(353), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(359), uint32(4), uint32(0), uint32(0) },
	{ uint32(359), uint32(4), uint32(0), uint32(0) },
	{ uint32(359), uint32(4), uint32(0), uint32(0) },
	{ uint32(359), uint32(4), uint32(0), uint32(0) },
	{ uint32(359), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(365), uint32(4), uint32(0), uint32(0) },
	{ uint32(365), uint32(4), uint32(0), uint32(0) },
	{ uint32(365), uint32(4), uint32(0), uint32(0) },
	{ uint32(365), uint32(4), uint32(0), uint32(0) },
	{ uint32(365), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(371), uint32(7), uint32(0), uint32(0) },
	{ uint32(371), uint32(7), uint32(0), uint32(0) },
	{ uint32(371), uint32(7), uint32(0), uint32(0) },
	{ uint32(371), uint32(7), uint32(0), uint32(0) },
	{ uint32(371), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(377), uint32(7), uint32(0), uint32(0) },
	{ uint32(377), uint32(7), uint32(0), uint32(0) },
	{ uint32(377), uint32(7), uint32(0), uint32(0) },
	{ uint32(377), uint32(7), uint32(0), uint32(0) },
	{ uint32(377), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(383), uint32(7), uint32(0), uint32(0) },
	{ uint32(383), uint32(7), uint32(0), uint32(0) },
	{ uint32(383), uint32(7), uint32(0), uint32(0) },
	{ uint32(383), uint32(7), uint32(0), uint32(0) },
	{ uint32(383), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(389), uint32(7), uint32(0), uint32(0) },
	{ uint32(389), uint32(7), uint32(0), uint32(0) },
	{ uint32(389), uint32(7), uint32(0), uint32(0) },
	{ uint32(389), uint32(7), uint32(0), uint32(0) },
	{ uint32(389), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(395), uint32(7), uint32(0), uint32(0) },
	{ uint32(395), uint32(7), uint32(0), uint32(0) },
	{ uint32(395), uint32(7), uint32(0), uint32(0) },
	{ uint32(395), uint32(7), uint32(0), uint32(0) },
	{ uint32(395), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(401), uint32(7), uint32(0), uint32(0) },
	{ uint32(401), uint32(7), uint32(0), uint32(0) },
	{ uint32(401), uint32(7), uint32(0), uint32(0) },
	{ uint32(401), uint32(7), uint32(0), uint32(0) },
	{ uint32(401), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(407), uint32(7), uint32(0), uint32(0) },
	{ uint32(407), uint32(7), uint32(0), uint32(0) },
	{ uint32(407), uint32(7), uint32(0), uint32(0) },
	{ uint32(407), uint32(7), uint32(0), uint32(0) },
	{ uint32(407), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(413), uint32(7), uint32(0), uint32(0) },
	{ uint32(413), uint32(7), uint32(0), uint32(0) },
	{ uint32(413), uint32(7), uint32(0), uint32(0) },
	{ uint32(413), uint32(7), uint32(0), uint32(0) },
	{ uint32(413), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(419), uint32(7), uint32(0), uint32(0) },
	{ uint32(419), uint32(7), uint32(0), uint32(0) },
	{ uint32(419), uint32(7), uint32(0), uint32(0) },
	{ uint32(419), uint32(7), uint32(0), uint32(0) },
	{ uint32(419), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(425), uint32(7), uint32(0), uint32(0) },
	{ uint32(425), uint32(7), uint32(0), uint32(0) },
	{ uint32(425), uint32(7), uint32(0), uint32(0) },
	{ uint32(425), uint32(7), uint32(0), uint32(0) },
	{ uint32(425), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(431), uint32(4), uint32(0), uint32(0) },
	{ uint32(431), uint32(4), uint32(0), uint32(0) },
	{ uint32(431), uint32(4), uint32(0), uint32(0) },
	{ uint32(431), uint32(4), uint32(0), uint32(0) },
	{ uint32(431), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(437), uint32(4), uint32(0), uint32(0) },
	{ uint32(437), uint32(4), uint32(0), uint32(0) },
	{ uint32(437), uint32(4), uint32(0), uint32(0) },
	{ uint32(437), uint32(4), uint32(0), uint32(0) },
	{ uint32(437), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(443), uint32(4), uint32(0), uint32(0) },
	{ uint32(443), uint32(4), uint32(0), uint32(0) },
	{ uint32(443), uint32(4), uint32(0), uint32(0) },
	{ uint32(443), uint32(4), uint32(0), uint32(0) },
	{ uint32(443), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(449), uint32(4), uint32(0), uint32(0) },
	{ uint32(449), uint32(4), uint32(0), uint32(0) },
	{ uint32(449), uint32(4), uint32(0), uint32(0) },
	{ uint32(449), uint32(4), uint32(0), uint32(0) },
	{ uint32(449), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(455), uint32(4), uint32(0), uint32(0) },
	{ uint32(455), uint32(4), uint32(0), uint32(0) },
	{ uint32(455), uint32(4), uint32(0), uint32(0) },
	{ uint32(455), uint32(4), uint32(0), uint32(0) },
	{ uint32(455), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(461), uint32(7), uint32(0), uint32(0) },
	{ uint32(461), uint32(7), uint32(0), uint32(0) },
	{ uint32(461), uint32(7), uint32(0), uint32(0) },
	{ uint32(461), uint32(7), uint32(0), uint32(0) },
	{ uint32(461), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(467), uint32(7), uint32(0), uint32(0) },
	{ uint32(467), uint32(7), uint32(0), uint32(0) },
	{ uint32(467), uint32(7), uint32(0), uint32(0) },
	{ uint32(467), uint32(7), uint32(0), uint32(0) },
	{ uint32(467), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(473), uint32(4), uint32(0), uint32(0) },
	{ uint32(473), uint32(4), uint32(0), uint32(0) },
	{ uint32(473), uint32(4), uint32(0), uint32(0) },
	{ uint32(473), uint32(4), uint32(0), uint32(0) },
	{ uint32(473), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(479), uint32(7), uint32(0), uint32(0) },
	{ uint32(479), uint32(7), uint32(0), uint32(0) },
	{ uint32(479), uint32(7), uint32(0), uint32(0) },
	{ uint32(479), uint32(7), uint32(0), uint32(0) },
	{ uint32(479), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(485), uint32(7), uint32(0), uint32(0) },
	{ uint32(485), uint32(7), uint32(0), uint32(0) },
	{ uint32(485), uint32(7), uint32(0), uint32(0) },
	{ uint32(485), uint32(7), uint32(0), uint32(0) },
	{ uint32(485), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(491), uint32(7), uint32(0), uint32(0) },
	{ uint32(491), uint32(7), uint32(0), uint32(0) },
	{ uint32(491), uint32(7), uint32(0), uint32(0) },
	{ uint32(491), uint32(7), uint32(0), uint32(0) },
	{ uint32(491), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(497), uint32(7), uint32(0), uint32(0) },
	{ uint32(497), uint32(7), uint32(0), uint32(0) },
	{ uint32(497), uint32(7), uint32(0), uint32(0) },
	{ uint32(497), uint32(7), uint32(0), uint32(0) },
	{ uint32(497), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(503), uint32(7), uint32(0), uint32(0) },
	{ uint32(503), uint32(7), uint32(0), uint32(0) },
	{ uint32(503), uint32(7), uint32(0), uint32(0) },
	{ uint32(503), uint32(7), uint32(0), uint32(0) },
	{ uint32(503), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(509), uint32(7), uint32(0), uint32(0) },
	{ uint32(509), uint32(7), uint32(0), uint32(0) },
	{ uint32(509), uint32(7), uint32(0), uint32(0) },
	{ uint32(509), uint32(7), uint32(0), uint32(0) },
	{ uint32(509), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(515), uint32(8), uint32(0), uint32(0) },
	{ uint32(515), uint32(8), uint32(0), uint32(0) },
	{ uint32(515), uint32(8), uint32(0), uint32(0) },
	{ uint32(515), uint32(8), uint32(0), uint32(0) },
	{ uint32(515), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(521), uint32(8), uint32(0), uint32(0) },
	{ uint32(521), uint32(8), uint32(0), uint32(0) },
	{ uint32(521), uint32(8), uint32(0), uint32(0) },
	{ uint32(521), uint32(8), uint32(0), uint32(0) },
	{ uint32(521), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(527), uint32(7), uint32(0), uint32(0) },
	{ uint32(527), uint32(7), uint32(0), uint32(0) },
	{ uint32(527), uint32(7), uint32(0), uint32(0) },
	{ uint32(527), uint32(7), uint32(0), uint32(0) },
	{ uint32(527), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(533), uint32(7), uint32(0), uint32(0) },
	{ uint32(533), uint32(7), uint32(0), uint32(0) },
	{ uint32(533), uint32(7), uint32(0), uint32(0) },
	{ uint32(533), uint32(7), uint32(0), uint32(0) },
	{ uint32(533), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(539), uint32(7), uint32(0), uint32(0) },
	{ uint32(539), uint32(7), uint32(0), uint32(0) },
	{ uint32(539), uint32(7), uint32(0), uint32(0) },
	{ uint32(539), uint32(7), uint32(0), uint32(0) },
	{ uint32(539), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(545), uint32(7), uint32(0), uint32(0) },
	{ uint32(545), uint32(7), uint32(0), uint32(0) },
	{ uint32(545), uint32(7), uint32(0), uint32(0) },
	{ uint32(545), uint32(7), uint32(0), uint32(0) },
	{ uint32(545), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(551), uint32(7), uint32(0), uint32(0) },
	{ uint32(551), uint32(7), uint32(0), uint32(0) },
	{ uint32(551), uint32(7), uint32(0), uint32(0) },
	{ uint32(551), uint32(7), uint32(0), uint32(0) },
	{ uint32(551), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(557), uint32(7), uint32(0), uint32(0) },
	{ uint32(557), uint32(7), uint32(0), uint32(0) },
	{ uint32(557), uint32(7), uint32(0), uint32(0) },
	{ uint32(557), uint32(7), uint32(0), uint32(0) },
	{ uint32(557), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(563), uint32(7), uint32(0), uint32(0) },
	{ uint32(563), uint32(7), uint32(0), uint32(0) },
	{ uint32(563), uint32(7), uint32(0), uint32(0) },
	{ uint32(563), uint32(7), uint32(0), uint32(0) },
	{ uint32(563), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(569), uint32(7), uint32(0), uint32(0) },
	{ uint32(569), uint32(7), uint32(0), uint32(0) },
	{ uint32(569), uint32(7), uint32(0), uint32(0) },
	{ uint32(569), uint32(7), uint32(0), uint32(0) },
	{ uint32(569), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(575), uint32(7), uint32(0), uint32(0) },
	{ uint32(575), uint32(7), uint32(0), uint32(0) },
	{ uint32(575), uint32(7), uint32(0), uint32(0) },
	{ uint32(575), uint32(7), uint32(0), uint32(0) },
	{ uint32(575), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(581), uint32(7), uint32(0), uint32(0) },
	{ uint32(581), uint32(7), uint32(0), uint32(0) },
	{ uint32(581), uint32(7), uint32(0), uint32(0) },
	{ uint32(581), uint32(7), uint32(0), uint32(0) },
	{ uint32(581), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(587), uint32(7), uint32(0), uint32(0) },
	{ uint32(587), uint32(7), uint32(0), uint32(0) },
	{ uint32(587), uint32(7), uint32(0), uint32(0) },
	{ uint32(587), uint32(7), uint32(0), uint32(0) },
	{ uint32(587), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(593), uint32(7), uint32(0), uint32(0) },
	{ uint32(593), uint32(7), uint32(0), uint32(0) },
	{ uint32(593), uint32(7), uint32(0), uint32(0) },
	{ uint32(593), uint32(7), uint32(0), uint32(0) },
	{ uint32(593), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(599), uint32(7), uint32(0), uint32(0) },
	{ uint32(599), uint32(7), uint32(0), uint32(0) },
	{ uint32(599), uint32(7), uint32(0), uint32(0) },
	{ uint32(599), uint32(7), uint32(0), uint32(0) },
	{ uint32(599), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(605), uint32(7), uint32(0), uint32(0) },
	{ uint32(605), uint32(7), uint32(0), uint32(0) },
	{ uint32(605), uint32(7), uint32(0), uint32(0) },
	{ uint32(605), uint32(7), uint32(0), uint32(0) },
	{ uint32(605), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(611), uint32(7), uint32(0), uint32(0) },
	{ uint32(611), uint32(7), uint32(0), uint32(0) },
	{ uint32(611), uint32(7), uint32(0), uint32(0) },
	{ uint32(611), uint32(7), uint32(0), uint32(0) },
	{ uint32(611), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(617), uint32(7), uint32(0), uint32(0) },
	{ uint32(617), uint32(7), uint32(0), uint32(0) },
	{ uint32(617), uint32(7), uint32(0), uint32(0) },
	{ uint32(617), uint32(7), uint32(0), uint32(0) },
	{ uint32(617), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(623), uint32(7), uint32(0), uint32(0) },
	{ uint32(623), uint32(7), uint32(0), uint32(0) },
	{ uint32(623), uint32(7), uint32(0), uint32(0) },
	{ uint32(623), uint32(7), uint32(0), uint32(0) },
	{ uint32(623), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(629), uint32(7), uint32(0), uint32(0) },
	{ uint32(629), uint32(7), uint32(0), uint32(0) },
	{ uint32(629), uint32(7), uint32(0), uint32(0) },
	{ uint32(629), uint32(7), uint32(0), uint32(0) },
	{ uint32(629), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(635), uint32(7), uint32(0), uint32(0) },
	{ uint32(635), uint32(7), uint32(0), uint32(0) },
	{ uint32(635), uint32(7), uint32(0), uint32(0) },
	{ uint32(635), uint32(7), uint32(0), uint32(0) },
	{ uint32(635), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(641), uint32(7), uint32(0), uint32(0) },
	{ uint32(641), uint32(7), uint32(0), uint32(0) },
	{ uint32(641), uint32(7), uint32(0), uint32(0) },
	{ uint32(641), uint32(7), uint32(0), uint32(0) },
	{ uint32(641), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(647), uint32(7), uint32(0), uint32(0) },
	{ uint32(647), uint32(7), uint32(0), uint32(0) },
	{ uint32(647), uint32(7), uint32(0), uint32(0) },
	{ uint32(647), uint32(7), uint32(0), uint32(0) },
	{ uint32(647), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(653), uint32(7), uint32(0), uint32(0) },
	{ uint32(653), uint32(7), uint32(0), uint32(0) },
	{ uint32(653), uint32(7), uint32(0), uint32(0) },
	{ uint32(653), uint32(7), uint32(0), uint32(0) },
	{ uint32(653), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(659), uint32(7), uint32(0), uint32(0) },
	{ uint32(659), uint32(7), uint32(0), uint32(0) },
	{ uint32(659), uint32(7), uint32(0), uint32(0) },
	{ uint32(659), uint32(7), uint32(0), uint32(0) },
	{ uint32(659), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(665), uint32(7), uint32(0), uint32(0) },
	{ uint32(665), uint32(7), uint32(0), uint32(0) },
	{ uint32(665), uint32(7), uint32(0), uint32(0) },
	{ uint32(665), uint32(7), uint32(0), uint32(0) },
	{ uint32(665), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(671), uint32(7), uint32(0), uint32(0) },
	{ uint32(671), uint32(7), uint32(0), uint32(0) },
	{ uint32(671), uint32(7), uint32(0), uint32(0) },
	{ uint32(671), uint32(7), uint32(0), uint32(0) },
	{ uint32(671), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(677), uint32(7), uint32(0), uint32(0) },
	{ uint32(677), uint32(7), uint32(0), uint32(0) },
	{ uint32(677), uint32(7), uint32(0), uint32(0) },
	{ uint32(677), uint32(7), uint32(0), uint32(0) },
	{ uint32(677), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(683), uint32(7), uint32(0), uint32(0) },
	{ uint32(683), uint32(7), uint32(0), uint32(0) },
	{ uint32(683), uint32(7), uint32(0), uint32(0) },
	{ uint32(683), uint32(7), uint32(0), uint32(0) },
	{ uint32(683), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(689), uint32(7), uint32(0), uint32(0) },
	{ uint32(689), uint32(7), uint32(0), uint32(0) },
	{ uint32(689), uint32(7), uint32(0), uint32(0) },
	{ uint32(689), uint32(7), uint32(0), uint32(0) },
	{ uint32(689), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(695), uint32(7), uint32(0), uint32(0) },
	{ uint32(695), uint32(7), uint32(0), uint32(0) },
	{ uint32(695), uint32(7), uint32(0), uint32(0) },
	{ uint32(695), uint32(7), uint32(0), uint32(0) },
	{ uint32(695), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(701), uint32(7), uint32(0), uint32(0) },
	{ uint32(701), uint32(7), uint32(0), uint32(0) },
	{ uint32(701), uint32(7), uint32(0), uint32(0) },
	{ uint32(701), uint32(7), uint32(0), uint32(0) },
	{ uint32(701), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(707), uint32(7), uint32(0), uint32(0) },
	{ uint32(707), uint32(7), uint32(0), uint32(0) },
	{ uint32(707), uint32(7), uint32(0), uint32(0) },
	{ uint32(707), uint32(7), uint32(0), uint32(0) },
	{ uint32(707), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(713), uint32(7), uint32(0), uint32(0) },
	{ uint32(713), uint32(7), uint32(0), uint32(0) },
	{ uint32(713), uint32(7), uint32(0), uint32(0) },
	{ uint32(713), uint32(7), uint32(0), uint32(0) },
	{ uint32(713), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(719), uint32(4), uint32(0), uint32(0) },
	{ uint32(719), uint32(4), uint32(0), uint32(0) },
	{ uint32(719), uint32(4), uint32(0), uint32(0) },
	{ uint32(719), uint32(4), uint32(0), uint32(0) },
	{ uint32(719), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(725), uint32(4), uint32(0), uint32(0) },
	{ uint32(725), uint32(4), uint32(0), uint32(0) },
	{ uint32(725), uint32(4), uint32(0), uint32(0) },
	{ uint32(725), uint32(4), uint32(0), uint32(0) },
	{ uint32(725), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(731), uint32(4), uint32(0), uint32(0) },
	{ uint32(731), uint32(4), uint32(0), uint32(0) },
	{ uint32(731), uint32(4), uint32(0), uint32(0) },
	{ uint32(731), uint32(4), uint32(0), uint32(0) },
	{ uint32(731), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(737), uint32(4), uint32(0), uint32(0) },
	{ uint32(737), uint32(4), uint32(0), uint32(0) },
	{ uint32(737), uint32(4), uint32(0), uint32(0) },
	{ uint32(737), uint32(4), uint32(0), uint32(0) },
	{ uint32(737), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(743), uint32(7), uint32(0), uint32(0) },
	{ uint32(743), uint32(7), uint32(0), uint32(0) },
	{ uint32(743), uint32(7), uint32(0), uint32(0) },
	{ uint32(743), uint32(7), uint32(0), uint32(0) },
	{ uint32(743), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(749), uint32(7), uint32(0), uint32(0) },
	{ uint32(749), uint32(7), uint32(0), uint32(0) },
	{ uint32(749), uint32(7), uint32(0), uint32(0) },
	{ uint32(749), uint32(7), uint32(0), uint32(0) },
	{ uint32(749), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(755), uint32(7), uint32(0), uint32(0) },
	{ uint32(755), uint32(7), uint32(0), uint32(0) },
	{ uint32(755), uint32(7), uint32(0), uint32(0) },
	{ uint32(755), uint32(7), uint32(0), uint32(0) },
	{ uint32(755), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(761), uint32(7), uint32(0), uint32(0) },
	{ uint32(761), uint32(7), uint32(0), uint32(0) },
	{ uint32(761), uint32(7), uint32(0), uint32(0) },
	{ uint32(761), uint32(7), uint32(0), uint32(0) },
	{ uint32(761), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(767), uint32(4), uint32(0), uint32(0) },
	{ uint32(767), uint32(4), uint32(0), uint32(0) },
	{ uint32(767), uint32(4), uint32(0), uint32(0) },
	{ uint32(767), uint32(4), uint32(0), uint32(0) },
	{ uint32(767), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(773), uint32(4), uint32(0), uint32(0) },
	{ uint32(773), uint32(4), uint32(0), uint32(0) },
	{ uint32(773), uint32(4), uint32(0), uint32(0) },
	{ uint32(773), uint32(4), uint32(0), uint32(0) },
	{ uint32(773), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(779), uint32(7), uint32(0), uint32(0) },
	{ uint32(779), uint32(7), uint32(0), uint32(0) },
	{ uint32(779), uint32(7), uint32(0), uint32(0) },
	{ uint32(779), uint32(7), uint32(0), uint32(0) },
	{ uint32(779), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(785), uint32(7), uint32(0), uint32(0) },
	{ uint32(785), uint32(7), uint32(0), uint32(0) },
	{ uint32(785), uint32(7), uint32(0), uint32(0) },
	{ uint32(785), uint32(7), uint32(0), uint32(0) },
	{ uint32(785), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(791), uint32(7), uint32(0), uint32(0) },
	{ uint32(791), uint32(7), uint32(0), uint32(0) },
	{ uint32(791), uint32(7), uint32(0), uint32(0) },
	{ uint32(791), uint32(7), uint32(0), uint32(0) },
	{ uint32(791), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(797), uint32(7), uint32(0), uint32(0) },
	{ uint32(797), uint32(7), uint32(0), uint32(0) },
	{ uint32(797), uint32(7), uint32(0), uint32(0) },
	{ uint32(797), uint32(7), uint32(0), uint32(0) },
	{ uint32(797), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(803), uint32(7), uint32(0), uint32(0) },
	{ uint32(803), uint32(7), uint32(0), uint32(0) },
	{ uint32(803), uint32(7), uint32(0), uint32(0) },
	{ uint32(803), uint32(7), uint32(0), uint32(0) },
	{ uint32(803), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(809), uint32(7), uint32(0), uint32(0) },
	{ uint32(809), uint32(7), uint32(0), uint32(0) },
	{ uint32(809), uint32(7), uint32(0), uint32(0) },
	{ uint32(809), uint32(7), uint32(0), uint32(0) },
	{ uint32(809), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(819), uint32(7), uint32(0), uint32(0) },
	{ uint32(819), uint32(7), uint32(0), uint32(0) },
	{ uint32(819), uint32(7), uint32(0), uint32(0) },
	{ uint32(819), uint32(7), uint32(0), uint32(0) },
	{ uint32(819), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(825), uint32(7), uint32(0), uint32(0) },
	{ uint32(825), uint32(7), uint32(0), uint32(0) },
	{ uint32(825), uint32(7), uint32(0), uint32(0) },
	{ uint32(825), uint32(7), uint32(0), uint32(0) },
	{ uint32(825), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(831), uint32(7), uint32(0), uint32(0) },
	{ uint32(831), uint32(7), uint32(0), uint32(0) },
	{ uint32(831), uint32(7), uint32(0), uint32(0) },
	{ uint32(831), uint32(7), uint32(0), uint32(0) },
	{ uint32(831), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(837), uint32(7), uint32(0), uint32(0) },
	{ uint32(837), uint32(7), uint32(0), uint32(0) },
	{ uint32(837), uint32(7), uint32(0), uint32(0) },
	{ uint32(837), uint32(7), uint32(0), uint32(0) },
	{ uint32(837), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(843), uint32(4), uint32(0), uint32(0) },
	{ uint32(843), uint32(4), uint32(0), uint32(0) },
	{ uint32(843), uint32(4), uint32(0), uint32(0) },
	{ uint32(843), uint32(4), uint32(0), uint32(0) },
	{ uint32(843), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(849), uint32(4), uint32(0), uint32(0) },
	{ uint32(849), uint32(4), uint32(0), uint32(0) },
	{ uint32(849), uint32(4), uint32(0), uint32(0) },
	{ uint32(849), uint32(4), uint32(0), uint32(0) },
	{ uint32(849), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(855), uint32(4), uint32(0), uint32(0) },
	{ uint32(855), uint32(4), uint32(0), uint32(0) },
	{ uint32(855), uint32(4), uint32(0), uint32(0) },
	{ uint32(855), uint32(4), uint32(0), uint32(0) },
	{ uint32(855), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(861), uint32(7), uint32(0), uint32(0) },
	{ uint32(861), uint32(7), uint32(0), uint32(0) },
	{ uint32(861), uint32(7), uint32(0), uint32(0) },
	{ uint32(861), uint32(7), uint32(0), uint32(0) },
	{ uint32(861), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(867), uint32(7), uint32(0), uint32(0) },
	{ uint32(867), uint32(7), uint32(0), uint32(0) },
	{ uint32(867), uint32(7), uint32(0), uint32(0) },
	{ uint32(867), uint32(7), uint32(0), uint32(0) },
	{ uint32(867), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(873), uint32(7), uint32(0), uint32(0) },
	{ uint32(873), uint32(7), uint32(0), uint32(0) },
	{ uint32(873), uint32(7), uint32(0), uint32(0) },
	{ uint32(873), uint32(7), uint32(0), uint32(0) },
	{ uint32(873), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(879), uint32(7), uint32(0), uint32(0) },
	{ uint32(879), uint32(7), uint32(0), uint32(0) },
	{ uint32(879), uint32(7), uint32(0), uint32(0) },
	{ uint32(879), uint32(7), uint32(0), uint32(0) },
	{ uint32(879), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(885), uint32(7), uint32(0), uint32(0) },
	{ uint32(885), uint32(7), uint32(0), uint32(0) },
	{ uint32(885), uint32(7), uint32(0), uint32(0) },
	{ uint32(885), uint32(7), uint32(0), uint32(0) },
	{ uint32(885), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(891), uint32(7), uint32(0), uint32(0) },
	{ uint32(891), uint32(7), uint32(0), uint32(0) },
	{ uint32(891), uint32(7), uint32(0), uint32(0) },
	{ uint32(891), uint32(7), uint32(0), uint32(0) },
	{ uint32(891), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(897), uint32(7), uint32(0), uint32(0) },
	{ uint32(897), uint32(7), uint32(0), uint32(0) },
	{ uint32(897), uint32(7), uint32(0), uint32(0) },
	{ uint32(897), uint32(7), uint32(0), uint32(0) },
	{ uint32(897), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(903), uint32(7), uint32(0), uint32(0) },
	{ uint32(903), uint32(7), uint32(0), uint32(0) },
	{ uint32(903), uint32(7), uint32(0), uint32(0) },
	{ uint32(903), uint32(7), uint32(0), uint32(0) },
	{ uint32(903), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(909), uint32(7), uint32(0), uint32(0) },
	{ uint32(909), uint32(7), uint32(0), uint32(0) },
	{ uint32(909), uint32(7), uint32(0), uint32(0) },
	{ uint32(909), uint32(7), uint32(0), uint32(0) },
	{ uint32(909), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(915), uint32(7), uint32(0), uint32(0) },
	{ uint32(915), uint32(7), uint32(0), uint32(0) },
	{ uint32(915), uint32(7), uint32(0), uint32(0) },
	{ uint32(915), uint32(7), uint32(0), uint32(0) },
	{ uint32(915), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(921), uint32(7), uint32(0), uint32(0) },
	{ uint32(921), uint32(7), uint32(0), uint32(0) },
	{ uint32(921), uint32(7), uint32(0), uint32(0) },
	{ uint32(921), uint32(7), uint32(0), uint32(0) },
	{ uint32(921), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(927), uint32(7), uint32(0), uint32(0) },
	{ uint32(927), uint32(7), uint32(0), uint32(0) },
	{ uint32(927), uint32(7), uint32(0), uint32(0) },
	{ uint32(927), uint32(7), uint32(0), uint32(0) },
	{ uint32(927), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(933), uint32(7), uint32(0), uint32(0) },
	{ uint32(933), uint32(7), uint32(0), uint32(0) },
	{ uint32(933), uint32(7), uint32(0), uint32(0) },
	{ uint32(933), uint32(7), uint32(0), uint32(0) },
	{ uint32(933), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(939), uint32(7), uint32(0), uint32(0) },
	{ uint32(939), uint32(7), uint32(0), uint32(0) },
	{ uint32(939), uint32(7), uint32(0), uint32(0) },
	{ uint32(939), uint32(7), uint32(0), uint32(0) },
	{ uint32(939), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(945), uint32(7), uint32(0), uint32(0) },
	{ uint32(945), uint32(7), uint32(0), uint32(0) },
	{ uint32(945), uint32(7), uint32(0), uint32(0) },
	{ uint32(945), uint32(7), uint32(0), uint32(0) },
	{ uint32(945), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(951), uint32(7), uint32(0), uint32(0) },
	{ uint32(951), uint32(7), uint32(0), uint32(0) },
	{ uint32(951), uint32(7), uint32(0), uint32(0) },
	{ uint32(951), uint32(7), uint32(0), uint32(0) },
	{ uint32(951), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(957), uint32(7), uint32(0), uint32(0) },
	{ uint32(957), uint32(7), uint32(0), uint32(0) },
	{ uint32(957), uint32(7), uint32(0), uint32(0) },
	{ uint32(957), uint32(7), uint32(0), uint32(0) },
	{ uint32(957), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(963), uint32(7), uint32(0), uint32(0) },
	{ uint32(963), uint32(7), uint32(0), uint32(0) },
	{ uint32(963), uint32(7), uint32(0), uint32(0) },
	{ uint32(963), uint32(7), uint32(0), uint32(0) },
	{ uint32(963), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(969), uint32(7), uint32(0), uint32(0) },
	{ uint32(969), uint32(7), uint32(0), uint32(0) },
	{ uint32(969), uint32(7), uint32(0), uint32(0) },
	{ uint32(969), uint32(7), uint32(0), uint32(0) },
	{ uint32(969), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(975), uint32(7), uint32(0), uint32(0) },
	{ uint32(975), uint32(7), uint32(0), uint32(0) },
	{ uint32(975), uint32(7), uint32(0), uint32(0) },
	{ uint32(975), uint32(7), uint32(0), uint32(0) },
	{ uint32(975), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(981), uint32(7), uint32(0), uint32(0) },
	{ uint32(981), uint32(7), uint32(0), uint32(0) },
	{ uint32(981), uint32(7), uint32(0), uint32(0) },
	{ uint32(981), uint32(7), uint32(0), uint32(0) },
	{ uint32(981), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(987), uint32(7), uint32(0), uint32(0) },
	{ uint32(987), uint32(7), uint32(0), uint32(0) },
	{ uint32(987), uint32(7), uint32(0), uint32(0) },
	{ uint32(987), uint32(7), uint32(0), uint32(0) },
	{ uint32(987), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(993), uint32(7), uint32(0), uint32(0) },
	{ uint32(993), uint32(7), uint32(0), uint32(0) },
	{ uint32(993), uint32(7), uint32(0), uint32(0) },
	{ uint32(993), uint32(7), uint32(0), uint32(0) },
	{ uint32(993), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(999), uint32(7), uint32(0), uint32(0) },
	{ uint32(999), uint32(7), uint32(0), uint32(0) },
	{ uint32(999), uint32(7), uint32(0), uint32(0) },
	{ uint32(999), uint32(7), uint32(0), uint32(0) },
	{ uint32(999), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1005), uint32(4), uint32(0), uint32(0) },
	{ uint32(1005), uint32(4), uint32(0), uint32(0) },
	{ uint32(1005), uint32(4), uint32(0), uint32(0) },
	{ uint32(1005), uint32(4), uint32(0), uint32(0) },
	{ uint32(1005), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1011), uint32(4), uint32(0), uint32(0) },
	{ uint32(1011), uint32(4), uint32(0), uint32(0) },
	{ uint32(1011), uint32(4), uint32(0), uint32(0) },
	{ uint32(1011), uint32(4), uint32(0), uint32(0) },
	{ uint32(1011), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1017), uint32(4), uint32(0), uint32(0) },
	{ uint32(1017), uint32(4), uint32(0), uint32(0) },
	{ uint32(1017), uint32(4), uint32(0), uint32(0) },
	{ uint32(1017), uint32(4), uint32(0), uint32(0) },
	{ uint32(1017), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1023), uint32(4), uint32(0), uint32(0) },
	{ uint32(1023), uint32(4), uint32(0), uint32(0) },
	{ uint32(1023), uint32(4), uint32(0), uint32(0) },
	{ uint32(1023), uint32(4), uint32(0), uint32(0) },
	{ uint32(1023), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1031), uint32(4), uint32(0), uint32(0) },
	{ uint32(1031), uint32(4), uint32(0), uint32(0) },
	{ uint32(1031), uint32(4), uint32(0), uint32(0) },
	{ uint32(1031), uint32(4), uint32(0), uint32(0) },
	{ uint32(1031), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1037), uint32(7), uint32(0), uint32(0) },
	{ uint32(1037), uint32(7), uint32(0), uint32(0) },
	{ uint32(1037), uint32(7), uint32(0), uint32(0) },
	{ uint32(1037), uint32(7), uint32(0), uint32(0) },
	{ uint32(1037), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1043), uint32(7), uint32(0), uint32(0) },
	{ uint32(1043), uint32(7), uint32(0), uint32(0) },
	{ uint32(1043), uint32(7), uint32(0), uint32(0) },
	{ uint32(1043), uint32(7), uint32(0), uint32(0) },
	{ uint32(1043), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1049), uint32(7), uint32(0), uint32(0) },
	{ uint32(1049), uint32(7), uint32(0), uint32(0) },
	{ uint32(1049), uint32(7), uint32(0), uint32(0) },
	{ uint32(1049), uint32(7), uint32(0), uint32(0) },
	{ uint32(1049), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1055), uint32(7), uint32(0), uint32(0) },
	{ uint32(1055), uint32(7), uint32(0), uint32(0) },
	{ uint32(1055), uint32(7), uint32(0), uint32(0) },
	{ uint32(1055), uint32(7), uint32(0), uint32(0) },
	{ uint32(1055), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(11), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(1445), uint32(8), uint32(0), uint32(0) },
	{ uint32(1445), uint32(8), uint32(0), uint32(0) },
	{ uint32(1445), uint32(8), uint32(0), uint32(0) },
	{ uint32(1445), uint32(8), uint32(0), uint32(0) },
	{ uint32(1445), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(1451), uint32(8), uint32(0), uint32(0) },
	{ uint32(1451), uint32(8), uint32(0), uint32(0) },
	{ uint32(1451), uint32(8), uint32(0), uint32(0) },
	{ uint32(1451), uint32(8), uint32(0), uint32(0) },
	{ uint32(1451), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1459), uint32(7), uint32(0), uint32(0) },
	{ uint32(1459), uint32(7), uint32(0), uint32(0) },
	{ uint32(1459), uint32(7), uint32(0), uint32(0) },
	{ uint32(1459), uint32(7), uint32(0), uint32(0) },
	{ uint32(1459), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1465), uint32(7), uint32(0), uint32(0) },
	{ uint32(1465), uint32(7), uint32(0), uint32(0) },
	{ uint32(1465), uint32(7), uint32(0), uint32(0) },
	{ uint32(1465), uint32(7), uint32(0), uint32(0) },
	{ uint32(1465), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1471), uint32(7), uint32(0), uint32(0) },
	{ uint32(1471), uint32(7), uint32(0), uint32(0) },
	{ uint32(1471), uint32(7), uint32(0), uint32(0) },
	{ uint32(1471), uint32(7), uint32(0), uint32(0) },
	{ uint32(1471), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1477), uint32(7), uint32(0), uint32(0) },
	{ uint32(1477), uint32(7), uint32(0), uint32(0) },
	{ uint32(1477), uint32(7), uint32(0), uint32(0) },
	{ uint32(1477), uint32(7), uint32(0), uint32(0) },
	{ uint32(1477), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1484), uint32(7), uint32(0), uint32(0) },
	{ uint32(1484), uint32(7), uint32(0), uint32(0) },
	{ uint32(1484), uint32(7), uint32(0), uint32(0) },
	{ uint32(1484), uint32(7), uint32(0), uint32(0) },
	{ uint32(1484), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1490), uint32(7), uint32(0), uint32(0) },
	{ uint32(1490), uint32(7), uint32(0), uint32(0) },
	{ uint32(1490), uint32(7), uint32(0), uint32(0) },
	{ uint32(1490), uint32(7), uint32(0), uint32(0) },
	{ uint32(1490), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(1496), uint32(8), uint32(0), uint32(0) },
	{ uint32(1496), uint32(8), uint32(0), uint32(0) },
	{ uint32(1496), uint32(8), uint32(0), uint32(0) },
	{ uint32(1496), uint32(8), uint32(0), uint32(0) },
	{ uint32(1496), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(1) },
	{ uint32(1502), uint32(8), uint32(0), uint32(0) },
	{ uint32(1502), uint32(8), uint32(0), uint32(0) },
	{ uint32(1502), uint32(8), uint32(0), uint32(0) },
	{ uint32(1502), uint32(8), uint32(0), uint32(0) },
	{ uint32(1502), uint32(8), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1508), uint32(4), uint32(0), uint32(0) },
	{ uint32(1508), uint32(4), uint32(0), uint32(0) },
	{ uint32(1508), uint32(4), uint32(0), uint32(0) },
	{ uint32(1508), uint32(4), uint32(0), uint32(0) },
	{ uint32(1508), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1514), uint32(7), uint32(0), uint32(0) },
	{ uint32(1514), uint32(7), uint32(0), uint32(0) },
	{ uint32(1514), uint32(7), uint32(0), uint32(0) },
	{ uint32(1514), uint32(7), uint32(0), uint32(0) },
	{ uint32(1514), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1520), uint32(7), uint32(0), uint32(0) },
	{ uint32(1520), uint32(7), uint32(0), uint32(0) },
	{ uint32(1520), uint32(7), uint32(0), uint32(0) },
	{ uint32(1520), uint32(7), uint32(0), uint32(0) },
	{ uint32(1520), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1526), uint32(7), uint32(0), uint32(0) },
	{ uint32(1526), uint32(7), uint32(0), uint32(0) },
	{ uint32(1526), uint32(7), uint32(0), uint32(0) },
	{ uint32(1526), uint32(7), uint32(0), uint32(0) },
	{ uint32(1526), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1532), uint32(7), uint32(0), uint32(0) },
	{ uint32(1532), uint32(7), uint32(0), uint32(0) },
	{ uint32(1532), uint32(7), uint32(0), uint32(0) },
	{ uint32(1532), uint32(7), uint32(0), uint32(0) },
	{ uint32(1532), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1538), uint32(7), uint32(0), uint32(0) },
	{ uint32(1538), uint32(7), uint32(0), uint32(0) },
	{ uint32(1538), uint32(7), uint32(0), uint32(0) },
	{ uint32(1538), uint32(7), uint32(0), uint32(0) },
	{ uint32(1538), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1544), uint32(7), uint32(0), uint32(0) },
	{ uint32(1544), uint32(7), uint32(0), uint32(0) },
	{ uint32(1544), uint32(7), uint32(0), uint32(0) },
	{ uint32(1544), uint32(7), uint32(0), uint32(0) },
	{ uint32(1544), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1550), uint32(7), uint32(0), uint32(0) },
	{ uint32(1550), uint32(7), uint32(0), uint32(0) },
	{ uint32(1550), uint32(7), uint32(0), uint32(0) },
	{ uint32(1550), uint32(7), uint32(0), uint32(0) },
	{ uint32(1550), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1556), uint32(7), uint32(0), uint32(0) },
	{ uint32(1556), uint32(7), uint32(0), uint32(0) },
	{ uint32(1556), uint32(7), uint32(0), uint32(0) },
	{ uint32(1556), uint32(7), uint32(0), uint32(0) },
	{ uint32(1556), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1562), uint32(7), uint32(0), uint32(0) },
	{ uint32(1562), uint32(7), uint32(0), uint32(0) },
	{ uint32(1562), uint32(7), uint32(0), uint32(0) },
	{ uint32(1562), uint32(7), uint32(0), uint32(0) },
	{ uint32(1562), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1568), uint32(7), uint32(0), uint32(0) },
	{ uint32(1568), uint32(7), uint32(0), uint32(0) },
	{ uint32(1568), uint32(7), uint32(0), uint32(0) },
	{ uint32(1568), uint32(7), uint32(0), uint32(0) },
	{ uint32(1568), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1574), uint32(7), uint32(0), uint32(0) },
	{ uint32(1574), uint32(7), uint32(0), uint32(0) },
	{ uint32(1574), uint32(7), uint32(0), uint32(0) },
	{ uint32(1574), uint32(7), uint32(0), uint32(0) },
	{ uint32(1574), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1580), uint32(7), uint32(0), uint32(0) },
	{ uint32(1580), uint32(7), uint32(0), uint32(0) },
	{ uint32(1580), uint32(7), uint32(0), uint32(0) },
	{ uint32(1580), uint32(7), uint32(0), uint32(0) },
	{ uint32(1580), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1586), uint32(7), uint32(0), uint32(0) },
	{ uint32(1586), uint32(7), uint32(0), uint32(0) },
	{ uint32(1586), uint32(7), uint32(0), uint32(0) },
	{ uint32(1586), uint32(7), uint32(0), uint32(0) },
	{ uint32(1586), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1592), uint32(7), uint32(0), uint32(0) },
	{ uint32(1592), uint32(7), uint32(0), uint32(0) },
	{ uint32(1592), uint32(7), uint32(0), uint32(0) },
	{ uint32(1592), uint32(7), uint32(0), uint32(0) },
	{ uint32(1592), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1598), uint32(7), uint32(0), uint32(0) },
	{ uint32(1598), uint32(7), uint32(0), uint32(0) },
	{ uint32(1598), uint32(7), uint32(0), uint32(0) },
	{ uint32(1598), uint32(7), uint32(0), uint32(0) },
	{ uint32(1598), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1604), uint32(7), uint32(0), uint32(0) },
	{ uint32(1604), uint32(7), uint32(0), uint32(0) },
	{ uint32(1604), uint32(7), uint32(0), uint32(0) },
	{ uint32(1604), uint32(7), uint32(0), uint32(0) },
	{ uint32(1604), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1621), uint32(7), uint32(0), uint32(0) },
	{ uint32(1621), uint32(7), uint32(0), uint32(0) },
	{ uint32(1621), uint32(7), uint32(0), uint32(0) },
	{ uint32(1621), uint32(7), uint32(0), uint32(0) },
	{ uint32(1621), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(1) },
	{ uint32(1627), uint32(7), uint32(0), uint32(0) },
	{ uint32(1627), uint32(7), uint32(0), uint32(0) },
	{ uint32(1627), uint32(7), uint32(0), uint32(0) },
	{ uint32(1627), uint32(7), uint32(0), uint32(0) },
	{ uint32(1627), uint32(7), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(1) },
	{ uint32(1871), uint32(4), uint32(0), uint32(0) },
	{ uint32(1871), uint32(4), uint32(0), uint32(0) },
	{ uint32(1871), uint32(4), uint32(0), uint32(0) },
	{ uint32(1871), uint32(4), uint32(0), uint32(0) },
	{ uint32(1871), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(3), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(1), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(1), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(5), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(6), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(2), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(14), uint32(0), uint32(0) },
	{ uint32(0), uint32(14), uint32(0), uint32(0) },
	{ uint32(0), uint32(14), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
	{ uint32(0), uint32(4), uint32(0), uint32(0) },
};
const ushort SectionData[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
108, 109, 110, 111, 117, 123, 129, 135, 136, 142, 148, 154,
160, 166, 172, 178, 184, 190, 196, 202, 208, 214, 220, 226,
232, 238, 244, 250, 256, 262, 268, 274, 280, 286, 292, 298,
304, 305, 306, 307, 308, 309, 315, 321, 322, 323, 324, 325,
326, 327, 328, 334, 340, 346, 352, 358, 364, 370, 376, 382,
388, 394, 400, 406, 412, 418, 424, 430, 436, 442, 448, 454,
460, 466, 472, 478, 484, 490, 496, 502, 508, 514, 520, 526,
532, 538, 544, 550, 556, 562, 568, 574, 580, 586, 592, 598,
604, 610, 616, 622, 628, 634, 640, 646, 652, 658, 664, 670,
676, 682, 688, 694, 700, 706, 712, 718, 724, 730, 736, 742,
748, 754, 760, 766, 772, 778, 784, 790, 796, 802, 808, 814,
815, 816, 817, 818, 824, 830, 836, 842, 848, 854, 860, 866,
872, 878, 884, 890, 896, 902, 908, 914, 920, 926, 932, 938,
944, 950, 956, 962, 968, 974, 980, 986, 992, 998, 1004, 1010,
1016, 1022, 1028, 1029, 1030, 1036, 1042, 1048, 1054, 1060, 1061, 1062,
1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074,
1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098,
1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110,
1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120, 1121, 1122,
1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134,
1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145, 1146,
1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158,
1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170,
1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182,
1183, 1184, 1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194,
1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206,
1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218,
1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230,
1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242,
1243, 1244, 1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254,
1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266,
1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278,
1279, 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289, 1290,
1291, 1292, 1293, 1294, 1295, 1296, 1297, 1298, 1299, 1300, 1301, 1302,
1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311, 1312, 1313, 1314,
1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326,
1327, 1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338,
1339, 1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349, 1350,
1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361, 1362,
1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374,
1375, 1376, 1377, 1378, 1379, 1380, 1381, 1382, 1383, 1384, 1385, 1386,
1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398,
1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, 1408, 1409, 1410,
1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422,
1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434,
1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442, 1443, 1444, 1450, 1456,
1457, 1458, 1464, 1470, 1476, 1482, 1483, 1489, 1495, 1501, 1507, 1513,
1519, 1525, 1531, 1537, 1543, 1549, 1555, 1561, 1567, 1573, 1579, 1585,
1591, 1597, 1603, 1609, 1610, 1611, 1612, 1613, 1614, 1615, 1616, 1617,
1618, 1619, 1620, 1626, 1632, 1633, 1634, 1635, 1636, 1637, 1638, 1639,
1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649, 1650, 1651,
1652, 1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661, 1662, 1663,
1664, 1665, 1666, 1667, 1668, 1669, 1670, 1671, 1672, 1673, 1674, 1675,
1676, 1677, 1678, 1679, 1680, 1681, 1682, 1683, 1684, 1685, 1686, 1687,
1688, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696, 1697, 1698, 1699,
1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711,
1712, 1713, 1714, 1715, 1716, 1717, 1718, 1719, 1720, 1721, 1722, 1723,
1724, 1725, 1726, 1727, 1728, 1729, 1730, 1731, 1732, 1733, 1734, 1735,
1736, 1737, 1738, 1739, 1740, 1741, 1742, 1743, 1744, 1745, 1746, 1747,
1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759,
1760, 1761, 1762, 1763, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771,
1772, 1773, 1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783,
1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793, 1794, 1795,
1796, 1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807,
1808, 1809, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819,
1820, 1821, 1822, 1823, 1824, 1825, 1826, 1827, 1828, 1829, 1830, 1831,
1832, 1833, 1834, 1835, 1836, 1837, 1838, 1839, 1840, 1841, 1842, 1843,
1844, 1845, 1846, 1847, 1848, 1849, 1850, 1851, 1852, 1853, 1854, 1855,
1856, 1857, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866, 1867,
1868, 1869, 1870, 1876, 1877, 1878, 1879, 1880, 1881, 1882, 1883, 1884,
1885, 1886, 1887, 1888, 1889, 1890, 1891, 1892, 1893, 1894, 1895, 1896,
1897, 1898, 1899, 1900, 1901, 1902, 1903, 1904, 1905, 1906, 1907, 1908,
1909, 1910, 1911, 1912, 1913, 1914, 1915, 1916, 1917, 1918, 1919, 1920,
1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929, 1930, 1931, 1932,
1933, 1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, 1944,
1945, 1946, 1947, 1948, 1949, 1950, 1951, 1952, 1953, 1954, 1955, 1956,
1957, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968,
1969, 1970, 1971, 1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1980,
1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1991, 1992,
1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016,
2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028,
2029, 2030, 2031, 2032, 2033, 2034, 2035, 2036, 2037, 2038, 2039, 2040,
2041, 2042, 2043, 2044, 2045, 2046, 2047, 2048, 2049, 2050, 2051, 2052,
2053, 2054, 2055, 2056, 2057, 2058, 2059, 2060, 2061, 2062, 2063, 2064,
2065, 2066, 2067, 2068, 2069, 2070, 2071, 2072, 2073, 2074, 2075, 2076,
2077, 2078, 2079, 2080, 2081, 2082, 2083, 2084, 2085, 2086, 2087, 2088,
2089, 2090, 2091, 2092, 2093, 2094, 2095, 2096, 2097, 2098, 2099, 2100,
2101, 2102, 2103, 2104, 2105, 2106, 2107, 2108, 2109, 2110, 2111, 2112,
2113, 2114, 2115, 2116, 2117, 2118, 2119, 2120, 2121, 2122, 2123, 2124,
2125, 2126, 2127, 2128, 2129, 2130, 2131, 2132, 2133, 2134, 2135, 2136,
2137, 2138, 2139, 2140, 2141, 2142, 2143, 2144, 2145, 2146, 2147, 2148,
2149, 2150, 2151, 2152, 2153, 2154, 2155, 2156, 2157, 2158, 2159, 2160,
2161, 2162, 2163, 2164, 2165, 2166, 2167, 2168, 2169, 2170, 2171, 2172,
2173, 2174, 2175, 2176, 2177, 2178, 2179, 2180, 2181, 2182, 2183, 2184,
2185, 2186, 2187, 2188, 2189, 2190, 2191, 2192, 2193, 2194, 2195, 2196,
2197, 2198, 2199, 2200, 2201, 2202, 2203, 2204, 2205, 2206, 2207, 2208,
2209, 2210, 2211, 2212, 2213, 2214, 2215, 2216, 2217, 2218, 2219, 2220,
2221, 2222, 2223, 2224, 2225, 2226, 2227, 2228, 2229, 2230, 2231, 2232,
2233, 2234, 2235, 2236, 2237, 2238, 2239, 2240, 2241, 2242, 2243, 2244,
2245, 2246, 2247, 2248, 2249, 2250, 2251, 2252, 2253, 2254, 2255, 2256,
2257, 2258, 2259, 2260, 2261, 2262, 2263, 2264, 2265, 2266, 2267, 2268,
2269, 2270, 2271, 2272, 2273, 2274, 2275, 2276, 2277, 2278, 2279, 2280,
2281, 2282, 2283, 2284, 2285, 2286, 2287, 2288, 2289, 2290, 2291, 2292,
2293, 2294, 2295, 2296, 2297, 2298, 2299, 2300, 2301, 2302, 2303, 2304,
2305, 2306, 2307, 2308, 2309, 2310, 2311, 2312, 2313, 2314, 2315, 2316,
2317, 2318, 2319, 2320, 2321, 2322, 2323, 2324, 2325, 2326, 2327, 2328,
2329, 2330, 2331, 2332, 2333, 2334, 2335, 2336, 2337, 2338, 2339, 2340,
2341, 2342, 2343, 2344, 2345, 2346, 2347, 2348, 2349, 2350, 2351, 2352,
2353, 2354, 2355, 2356, 2357, 2358, 2359, 2360, 2361, 2362, 2363, 2364,
2365, 2366, 2367, 2368, 2369, 2370, 2371, 2372, 2373, 2374, 2375, 2376,
2377, 2378, 2379, 2380, 2381, 2382, 2383, 2384, 2385, 2386, 2387, 2388,
2389, 2390, 2391, 2392, 2393, 2394, 2395, 2396, 2397, 2398, 2399, 2400,
2401, 2402, 2403, 2404, 2405, 2406, 2407, 2408, 2409, 2410, 2411, 2412,
2413, 2414, 2415, 2416, 2417, 2418, 2419, 2420, 2421, 2422, 2423, 2424,
2425, 2426, 2427, 2428, 2429, 2430, 2431, 2432, 2433, 2434, 2435, 2436,
2437, 2438, 2439, 2440, 2441, 2442, 2443, 2444, 2445, 2446, 2447, 2448,
2449, 2450, 2451, 2452, 2453, 2454, 2455, 2456, 2457, 2458, 2459, 2460,
2461, 2462, 2463, 2464, 2465, 2466, 2467, 2468, 2469, 2470, 2471, 2472,
2473, 2474, 2475, 2476, 2477, 2478, 2479, 2480, 2481, 2482, 2483, 2484,
2485, 2486, 2487, 2488, 2489, 2490, 2491, 2492, 2493, 2494, 2495, 2496,
2497, 2498, 2499, 2500, 2501, 2502, 2503 };

EmojiPack FillSection(int offset, int size) {
	auto result = EmojiPack();
	result.reserve(size);
	for (auto index : gsl::make_span(SectionData + offset, size)) {
		result.push_back(&Items[index]);
	}
	return result;
}


const std::vector<std::pair<QString, int>> ReplacementPairs = {
	{ "}:)", 89 },
	{ "O:)", 10 },
	{ "B-)", 29 },
	{ ">((", 49 },
	{ ">(", 48 },
	{ "<3", 1971 },
	{ ";o", 57 },
	{ ";-P", 24 },
	{ ";-)", 13 },
	{ ":|", 66 },
	{ ":_(", 46 },
	{ ":]", 32 },
	{ ":X", 84 },
	{ ":-p", 21 },
	{ ":-D", 1 },
	{ ":-*", 20 },
	{ ":-)", 9 },
	{ ":-(", 34 },
	{ ":((", 43 },
	{ ":'(", 45 },
	{ "8|", 52 },
	{ "8o", 74 },
	{ "8-)", 15 },
	{ "3-)", 14 },
	{ "3(", 35 },
};

int FindReplaceIndex(const QChar *start, const QChar *end, int *outLength) {
	auto ch = start;

	if (ch != end) switch (ch->unicode()) {
	case 0x7d:
		++ch;
		if (ch != end && ch->unicode() == 0x3a) {
			++ch;
			if (ch != end && ch->unicode() == 0x29) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 90;
			}
		}
	break;
	case 0x4f:
		++ch;
		if (ch != end && ch->unicode() == 0x3a) {
			++ch;
			if (ch != end && ch->unicode() == 0x29) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 11;
			}
		}
	break;
	case 0x42:
		++ch;
		if (ch != end && ch->unicode() == 0x2d) {
			++ch;
			if (ch != end && ch->unicode() == 0x29) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 30;
			}
		}
	break;
	case 0x3e:
		++ch;
		if (ch != end && ch->unicode() == 0x28) {
			++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x28) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 50;
			}
			return 49;
		}
	break;
	case 0x3c:
		++ch;
		if (ch != end && ch->unicode() == 0x33) {
			++ch;
			if (outLength) *outLength = (ch - start);
			return 1972;
		}
	break;
	case 0x3b:
		++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0x6f:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 58;
		break;
		case 0x2d:
			++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0x50:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 25;
			break;
			case 0x29:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 14;
			break;
			}
		break;
		}
	break;
	case 0x3a:
		++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0x7c:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 67;
		break;
		case 0x5f:
			++ch;
			if (ch != end && ch->unicode() == 0x28) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 47;
			}
		break;
		case 0x5d:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 33;
		break;
		case 0x58:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 85;
		break;
		case 0x2d:
			++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0x70:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 22;
			break;
			case 0x44:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 2;
			break;
			case 0x2a:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 21;
			break;
			case 0x29:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 10;
			break;
			case 0x28:
				++ch;
				if (outLength) *outLength = (ch - start);
				return 35;
			break;
			}
		break;
		case 0x28:
			++ch;
			if (ch != end && ch->unicode() == 0x28) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 44;
			}
		break;
		case 0x27:
			++ch;
			if (ch != end && ch->unicode() == 0x28) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 46;
			}
		break;
		}
	break;
	case 0x38:
		++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0x7c:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 53;
		break;
		case 0x6f:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 75;
		break;
		case 0x2d:
			++ch;
			if (ch != end && ch->unicode() == 0x29) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 16;
			}
		break;
		}
	break;
	case 0x33:
		++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0x2d:
			++ch;
			if (ch != end && ch->unicode() == 0x29) {
				++ch;
				if (outLength) *outLength = (ch - start);
				return 15;
			}
		break;
		case 0x28:
			++ch;
			if (outLength) *outLength = (ch - start);
			return 36;
		break;
		}
	break;
	}

	return 0;
}

int FindIndex(const QChar *start, const QChar *end, int *outLength) {
	auto ch = start;

	if (ch != end) switch (ch->unicode()) {
	case 0xd83e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0xddff:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1851;
		break;
		case 0xddfe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1920;
		break;
		case 0xddfd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1878;
		break;
		case 0xddfc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1877;
		break;
		case 0xddfb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1866;
		break;
		case 0xddfa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1865;
		break;
		case 0xddf9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1864;
		break;
		case 0xddf8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1887;
		break;
		case 0xddf7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1949;
		break;
		case 0xddf6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1095;
		break;
		case 0xddf5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1096;
		break;
		case 0xddf4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1879;
		break;
		case 0xddf3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1128;
		break;
		case 0xddf2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1837;
		break;
		case 0xddf1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1835;
		break;
		case 0xddf0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1827;
		break;
		case 0xddef:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1816;
		break;
		case 0xddee:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1955;
		break;
		case 0xdded:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1803;
		break;
		case 0xddec:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1859;
		break;
		case 0xddeb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1861;
		break;
		case 0xddea:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1862;
		break;
		case 0xdde9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1651;
		break;
		case 0xdde8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1840;
		break;
		case 0xdde7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1900;
		break;
		case 0xdde6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1113;
		break;
		case 0xdde5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1097;
		break;
		case 0xdde4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1114;
		break;
		case 0xdde3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1115;
		break;
		case 0xdde2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1117;
		break;
		case 0xdde1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1973;
		break;
		case 0xdde0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 325;
		break;
		case 0xdddf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 816;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 815;
				break;
				}
			}
			return 816;
		break;
		case 0xddde:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 818;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 817;
				break;
				}
			}
			return 818;
		break;
		case 0xdddd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 802;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 796;
						break;
						}
					}
					return 802;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 801;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 795;
						break;
						}
					}
					return 801;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 800;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 794;
						break;
						}
					}
					return 800;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 799;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 793;
						break;
						}
					}
					return 799;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 798;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 792;
						break;
						}
					}
					return 798;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 797;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 791;
				break;
				}
			break;
			}
			return 797;
		break;
		case 0xdddc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 830;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 824;
						break;
						}
					}
					return 830;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 829;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 823;
						break;
						}
					}
					return 829;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 828;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 822;
						break;
						}
					}
					return 828;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 827;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 821;
						break;
						}
					}
					return 827;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 826;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 820;
						break;
						}
					}
					return 826;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 825;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 819;
				break;
				}
			break;
			}
			return 825;
		break;
		case 0xdddb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 814;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 808;
						break;
						}
					}
					return 808;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 813;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 807;
						break;
						}
					}
					return 807;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 812;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 806;
						break;
						}
					}
					return 806;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 811;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 805;
						break;
						}
					}
					return 805;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 810;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 804;
						break;
						}
					}
					return 804;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 809;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 803;
				break;
				}
			break;
			}
			return 803;
		break;
		case 0xddda:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 842;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 836;
						break;
						}
					}
					return 836;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 841;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 835;
						break;
						}
					}
					return 835;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 840;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 834;
						break;
						}
					}
					return 834;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 839;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 833;
						break;
						}
					}
					return 833;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 838;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 832;
						break;
						}
					}
					return 832;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 837;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 831;
				break;
				}
			break;
			}
			return 831;
		break;
		case 0xddd9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 790;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 784;
						break;
						}
					}
					return 784;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 789;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 783;
						break;
						}
					}
					return 783;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 788;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 782;
						break;
						}
					}
					return 782;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 787;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 781;
						break;
						}
					}
					return 781;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 786;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 780;
						break;
						}
					}
					return 780;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 785;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 779;
				break;
				}
			break;
			}
			return 779;
		break;
		case 0xddd8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1525;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1519;
						break;
						}
					}
					return 1519;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1524;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1518;
						break;
						}
					}
					return 1518;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1523;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1517;
						break;
						}
					}
					return 1517;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1522;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1516;
						break;
						}
					}
					return 1516;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1521;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1515;
						break;
						}
					}
					return 1515;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1520;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1514;
				break;
				}
			break;
			}
			return 1514;
		break;
		case 0xddd7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1585;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1579;
						break;
						}
					}
					return 1579;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1584;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1578;
						break;
						}
					}
					return 1578;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1583;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1577;
						break;
						}
					}
					return 1577;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1582;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1576;
						break;
						}
					}
					return 1576;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1581;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1575;
						break;
						}
					}
					return 1575;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1580;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1574;
				break;
				}
			break;
			}
			return 1574;
		break;
		case 0xddd6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1004;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 998;
						break;
						}
					}
					return 1004;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1003;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 997;
						break;
						}
					}
					return 1003;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1002;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 996;
						break;
						}
					}
					return 1002;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1001;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 995;
						break;
						}
					}
					return 1001;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1000;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 994;
						break;
						}
					}
					return 1000;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 999;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 993;
				break;
				}
			break;
			}
			return 999;
		break;
		case 0xddd5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 478;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 477;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 476;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 475;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 474;
				break;
				}
			}
			return 473;
		break;
		case 0xddd4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 436;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 435;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 434;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 433;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 432;
				break;
				}
			}
			return 431;
		break;
		case 0xddd3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 448;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 447;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 446;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 445;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 444;
				break;
				}
			}
			return 443;
		break;
		case 0xddd2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 346;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 345;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 344;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 343;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 342;
				break;
				}
			}
			return 341;
		break;
		case 0xddd1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 364;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 363;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 362;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 361;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 360;
				break;
				}
			}
			return 359;
		break;
		case 0xddd0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 28;
		break;
		case 0xddc2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1414;
		break;
		case 0xddc1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1381;
		break;
		case 0xddc0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1341;
		break;
		case 0xddb9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 766;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 760;
						break;
						}
					}
					return 760;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 765;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 759;
						break;
						}
					}
					return 759;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 764;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 758;
						break;
						}
					}
					return 758;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 763;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 757;
						break;
						}
					}
					return 757;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 762;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 756;
						break;
						}
					}
					return 756;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 761;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 755;
				break;
				}
			break;
			}
			return 755;
		break;
		case 0xddb8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 754;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 748;
						break;
						}
					}
					return 748;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 753;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 747;
						break;
						}
					}
					return 747;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 752;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 746;
						break;
						}
					}
					return 746;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 751;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 745;
						break;
						}
					}
					return 745;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 750;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 744;
						break;
						}
					}
					return 744;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 749;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 743;
				break;
				}
			break;
			}
			return 743;
		break;
		case 0xddb7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 308;
		break;
		case 0xddb6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 298;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 297;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 296;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 295;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 294;
				break;
				}
			}
			return 293;
		break;
		case 0xddb5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 304;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 303;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 302;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 301;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 300;
				break;
				}
			}
			return 299;
		break;
		case 0xddb4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1349;
		break;
		case 0xdda2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1224;
		break;
		case 0xdda1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1228;
		break;
		case 0xdda0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1860;
		break;
		case 0xdd9f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1173;
		break;
		case 0xdd9e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1186;
		break;
		case 0xdd9d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1227;
		break;
		case 0xdd9c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1223;
		break;
		case 0xdd9b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1201;
		break;
		case 0xdd9a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1222;
		break;
		case 0xdd99:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1214;
		break;
		case 0xdd98:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1206;
		break;
		case 0xdd97:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1174;
		break;
		case 0xdd96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1181;
		break;
		case 0xdd95:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1182;
		break;
		case 0xdd94:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1232;
		break;
		case 0xdd93:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1198;
		break;
		case 0xdd92:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1205;
		break;
		case 0xdd91:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1184;
		break;
		case 0xdd90:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1185;
		break;
		case 0xdd8f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1202;
		break;
		case 0xdd8e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1180;
		break;
		case 0xdd8d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1199;
		break;
		case 0xdd8c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1216;
		break;
		case 0xdd8b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1169;
		break;
		case 0xdd8a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1138;
		break;
		case 0xdd89:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1161;
		break;
		case 0xdd88:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1194;
		break;
		case 0xdd87:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1162;
		break;
		case 0xdd86:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1159;
		break;
		case 0xdd85:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1160;
		break;
		case 0xdd84:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1166;
		break;
		case 0xdd83:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1221;
		break;
		case 0xdd82:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1177;
		break;
		case 0xdd81:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1143;
		break;
		case 0xdd80:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1187;
		break;
		case 0xdd7f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1106;
		break;
		case 0xdd7e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1112;
		break;
		case 0xdd7d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1131;
		break;
		case 0xdd7c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1098;
		break;
		case 0xdd7a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 45;
		break;
		case 0xdd76:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 55;
		break;
		case 0xdd75:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 54;
		break;
		case 0xdd74:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 81;
		break;
		case 0xdd73:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 32;
		break;
		case 0xdd70:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 17;
		break;
		case 0xdd6f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1337;
		break;
		case 0xdd6e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1374;
		break;
		case 0xdd6d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1321;
		break;
		case 0xdd6c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1329;
		break;
		case 0xdd6b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1360;
		break;
		case 0xdd6a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1354;
		break;
		case 0xdd69:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1346;
		break;
		case 0xdd68:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1340;
		break;
		case 0xdd67:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1380;
		break;
		case 0xdd66:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1328;
		break;
		case 0xdd65:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1323;
		break;
		case 0xdd64:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1398;
		break;
		case 0xdd63:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1411;
		break;
		case 0xdd62:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1413;
		break;
		case 0xdd61:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1412;
		break;
		case 0xdd60:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1373;
		break;
		case 0xdd5f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1367;
		break;
		case 0xdd5e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1344;
		break;
		case 0xdd5d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1324;
		break;
		case 0xdd5c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1392;
		break;
		case 0xdd5b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1394;
		break;
		case 0xdd5a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1342;
		break;
		case 0xdd59:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1355;
		break;
		case 0xdd58:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1359;
		break;
		case 0xdd57:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1358;
		break;
		case 0xdd56:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1339;
		break;
		case 0xdd55:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1333;
		break;
		case 0xdd54:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1334;
		break;
		case 0xdd53:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1345;
		break;
		case 0xdd52:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1330;
		break;
		case 0xdd51:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1327;
		break;
		case 0xdd50:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1336;
		break;
		case 0xdd4f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1423;
		break;
		case 0xdd4e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1419;
		break;
		case 0xdd4d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1429;
		break;
		case 0xdd4c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1441;
		break;
		case 0xdd4b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1436;
		break;
		case 0xdd4a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1435;
		break;
		case 0xdd49:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1613;
		break;
		case 0xdd48:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1612;
		break;
		case 0xdd47:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1611;
		break;
		case 0xdd45:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1431;
		break;
		case 0xdd44:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1408;
		break;
		case 0xdd43:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1404;
		break;
		case 0xdd42:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1402;
		break;
		case 0xdd41:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1640;
		break;
		case 0xdd40:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1256;
		break;
		case 0xdd3e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1495;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1489;
						break;
						}
					}
					return 1489;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1494;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1488;
						break;
						}
					}
					return 1488;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1493;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1487;
						break;
						}
					}
					return 1487;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1492;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1486;
						break;
						}
					}
					return 1486;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1491;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1485;
						break;
						}
					}
					return 1485;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1490;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1484;
				break;
				}
			break;
			}
			return 1484;
		break;
		case 0xdd3d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1561;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1555;
						break;
						}
					}
					return 1561;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1560;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1554;
						break;
						}
					}
					return 1560;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1559;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1553;
						break;
						}
					}
					return 1559;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1558;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1552;
						break;
						}
					}
					return 1558;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1557;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1551;
						break;
						}
					}
					return 1557;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1556;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1550;
				break;
				}
			break;
			}
			return 1556;
		break;
		case 0xdd3c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1458;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1457;
				break;
				}
			}
			return 1457;
		break;
		case 0xdd3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1483;
		break;
		case 0xdd39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1632;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1626;
						break;
						}
					}
					return 1632;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1631;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1625;
						break;
						}
					}
					return 1631;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1630;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1624;
						break;
						}
					}
					return 1630;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1629;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1623;
						break;
						}
					}
					return 1629;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1628;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1622;
						break;
						}
					}
					return 1628;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1627;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1621;
				break;
				}
			break;
			}
			return 1627;
		break;
		case 0xdd38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1470;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1464;
						break;
						}
					}
					return 1470;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1469;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1463;
						break;
						}
					}
					return 1469;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1468;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1462;
						break;
						}
					}
					return 1468;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1467;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1461;
						break;
						}
					}
					return 1467;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1466;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1460;
						break;
						}
					}
					return 1466;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1465;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1459;
				break;
				}
			break;
			}
			return 1465;
		break;
		case 0xdd37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 944;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 938;
						break;
						}
					}
					return 938;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 943;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 937;
						break;
						}
					}
					return 937;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 942;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 936;
						break;
						}
					}
					return 936;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 941;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 935;
						break;
						}
					}
					return 935;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 940;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 934;
						break;
						}
					}
					return 934;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 939;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 933;
				break;
				}
			break;
			}
			return 933;
		break;
		case 0xdd36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 772;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 771;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 770;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 769;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 768;
				break;
				}
			}
			return 767;
		break;
		case 0xdd35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 730;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 729;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 728;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 727;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 726;
				break;
				}
			}
			return 725;
		break;
		case 0xdd34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 742;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 741;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 740;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 739;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 738;
				break;
				}
			}
			return 737;
		break;
		case 0xdd33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1016;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1015;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1014;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1013;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1012;
				break;
				}
			}
			return 1011;
		break;
		case 0xdd32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 117;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 116;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 115;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 114;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 113;
				break;
				}
			}
			return 112;
		break;
		case 0xdd31:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 860;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 859;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 858;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 857;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 856;
				break;
				}
			}
			return 855;
		break;
		case 0xdd30:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 854;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 853;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 852;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 851;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 850;
				break;
				}
			}
			return 849;
		break;
		case 0xdd2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 52;
		break;
		case 0xdd2e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 83;
		break;
		case 0xdd2d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 63;
		break;
		case 0xdd2c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 51;
		break;
		case 0xdd2b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 64;
		break;
		case 0xdd2a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 26;
		break;
		case 0xdd29:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 31;
		break;
		case 0xdd28:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 27;
		break;
		case 0xdd27:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 84;
		break;
		case 0xdd26:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 932;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 926;
						break;
						}
					}
					return 932;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 931;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 925;
						break;
						}
					}
					return 931;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 930;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 924;
						break;
						}
					}
					return 930;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 929;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 923;
						break;
						}
					}
					return 929;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 928;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 922;
						break;
						}
					}
					return 928;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 927;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 921;
				break;
				}
			break;
			}
			return 927;
		break;
		case 0xdd25:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 65;
		break;
		case 0xdd24:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 77;
		break;
		case 0xdd23:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 8;
		break;
		case 0xdd22:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 82;
		break;
		case 0xdd21:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 94;
		break;
		case 0xdd20:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 89;
		break;
		case 0xdd1f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 190;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 189;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 188;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 187;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 186;
				break;
				}
			}
			return 185;
		break;
		case 0xdd1e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 178;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 177;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 176;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 175;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 174;
				break;
				}
			}
			return 173;
		break;
		case 0xdd1d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 136;
		break;
		case 0xdd1c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 172;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 171;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 170;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 169;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 168;
				break;
				}
			}
			return 167;
		break;
		case 0xdd1b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 166;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 165;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 164;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 163;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 162;
				break;
				}
			}
			return 161;
		break;
		case 0xdd1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 244;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 243;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 242;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 241;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 240;
				break;
				}
			}
			return 239;
		break;
		case 0xdd19:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 268;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 267;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 266;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 265;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 264;
				break;
				}
			}
			return 263;
		break;
		case 0xdd18:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 196;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 195;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 194;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 193;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 192;
				break;
				}
			}
			return 191;
		break;
		case 0xdd17:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 61;
		break;
		case 0xdd16:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 101;
		break;
		case 0xdd15:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 87;
		break;
		case 0xdd14:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 62;
		break;
		case 0xdd13:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 29;
		break;
		case 0xdd12:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 86;
		break;
		case 0xdd11:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 88;
		break;
		case 0xdd10:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 80;
		break;
		}
	break;
	case 0xd83d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0xdef9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1438;
		break;
		case 0xdef8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1696;
		break;
		case 0xdef7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1439;
		break;
		case 0xdef6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1698;
		break;
		case 0xdef5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1667;
		break;
		case 0xdef4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1665;
		break;
		case 0xdef3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1702;
		break;
		case 0xdef0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1694;
		break;
		case 0xdeec:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1691;
		break;
		case 0xdeeb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1690;
		break;
		case 0xdee9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1692;
		break;
		case 0xdee5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1701;
		break;
		case 0xdee4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1755;
		break;
		case 0xdee3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1756;
		break;
		case 0xdee2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1817;
		break;
		case 0xdee1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1844;
		break;
		case 0xdee0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1831;
		break;
		case 0xded2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1890;
		break;
		case 0xded1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2043;
		break;
		case 0xded0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1999;
		break;
		case 0xdecf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1885;
		break;
		case 0xdece:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1880;
		break;
		case 0xdecd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1889;
		break;
		case 0xdecc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1886;
		break;
		case 0xdecb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1884;
		break;
		case 0xdec5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2092;
		break;
		case 0xdec4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2091;
		break;
		case 0xdec3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2090;
		break;
		case 0xdec2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2089;
		break;
		case 0xdec1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1870;
		break;
		case 0xdec0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1876;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1875;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1874;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1873;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1872;
				break;
				}
			}
			return 1871;
		break;
		case 0xdebf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1869;
		break;
		case 0xdebe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2084;
		break;
		case 0xdebd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1867;
		break;
		case 0xdebc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2095;
		break;
		case 0xdebb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2096;
		break;
		case 0xdeba:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2094;
		break;
		case 0xdeb9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2093;
		break;
		case 0xdeb8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2067;
		break;
		case 0xdeb7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2050;
		break;
		case 0xdeb6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1048;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1042;
						break;
						}
					}
					return 1048;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1047;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1041;
						break;
						}
					}
					return 1047;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1046;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1040;
						break;
						}
					}
					return 1046;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1045;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1039;
						break;
						}
					}
					return 1045;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1044;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1038;
						break;
						}
					}
					return 1044;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1043;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1037;
				break;
				}
			break;
			}
			return 1043;
		break;
		case 0xdeb5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1597;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1591;
						break;
						}
					}
					return 1597;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1596;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1590;
						break;
						}
					}
					return 1596;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1595;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1589;
						break;
						}
					}
					return 1595;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1594;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1588;
						break;
						}
					}
					return 1594;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1593;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1587;
						break;
						}
					}
					return 1593;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1592;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1586;
				break;
				}
			break;
			}
			return 1592;
		break;
		case 0xdeb4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1609;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1603;
						break;
						}
					}
					return 1609;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1608;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1602;
						break;
						}
					}
					return 1608;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1607;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1601;
						break;
						}
					}
					return 1607;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1606;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1600;
						break;
						}
					}
					return 1606;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1605;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1599;
						break;
						}
					}
					return 1605;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1604;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1598;
				break;
				}
			break;
			}
			return 1604;
		break;
		case 0xdeb3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2052;
		break;
		case 0xdeb2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1666;
		break;
		case 0xdeb1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2053;
		break;
		case 0xdeb0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1868;
		break;
		case 0xdeaf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2051;
		break;
		case 0xdeae:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2097;
		break;
		case 0xdead:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2056;
		break;
		case 0xdeac:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1845;
		break;
		case 0xdeab:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2046;
		break;
		case 0xdeaa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1883;
		break;
		case 0xdea9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2251;
		break;
		case 0xdea8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1669;
		break;
		case 0xdea7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1707;
		break;
		case 0xdea6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1708;
		break;
		case 0xdea5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1709;
		break;
		case 0xdea4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1700;
		break;
		case 0xdea3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1573;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1567;
						break;
						}
					}
					return 1573;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1572;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1566;
						break;
						}
					}
					return 1572;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1571;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1565;
						break;
						}
					}
					return 1571;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1570;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1564;
						break;
						}
					}
					return 1570;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1569;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1563;
						break;
						}
					}
					return 1569;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1568;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1562;
				break;
				}
			break;
			}
			return 1568;
		break;
		case 0xdea2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1704;
		break;
		case 0xdea1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1674;
		break;
		case 0xdea0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1675;
		break;
		case 0xde9f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1676;
		break;
		case 0xde9e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1679;
		break;
		case 0xde9d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1680;
		break;
		case 0xde9c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1664;
		break;
		case 0xde9b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1663;
		break;
		case 0xde9a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1662;
		break;
		case 0xde99:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1654;
		break;
		case 0xde98:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1672;
		break;
		case 0xde97:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1652;
		break;
		case 0xde96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1673;
		break;
		case 0xde95:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1653;
		break;
		case 0xde94:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1670;
		break;
		case 0xde93:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1658;
		break;
		case 0xde92:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1660;
		break;
		case 0xde91:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1659;
		break;
		case 0xde90:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1661;
		break;
		case 0xde8f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1710;
		break;
		case 0xde8e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1656;
		break;
		case 0xde8d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1671;
		break;
		case 0xde8c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1655;
		break;
		case 0xde8b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1678;
		break;
		case 0xde8a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1687;
		break;
		case 0xde89:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1688;
		break;
		case 0xde88:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1683;
		break;
		case 0xde87:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1686;
		break;
		case 0xde86:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1685;
		break;
		case 0xde85:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1682;
		break;
		case 0xde84:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1681;
		break;
		case 0xde83:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1677;
		break;
		case 0xde82:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1684;
		break;
		case 0xde81:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1697;
		break;
		case 0xde80:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1695;
		break;
		case 0xde4f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 292;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 291;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 290;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 289;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 288;
				break;
				}
			}
			return 287;
		break;
		case 0xde4e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 956;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 950;
						break;
						}
					}
					return 950;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 955;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 949;
						break;
						}
					}
					return 949;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 954;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 948;
						break;
						}
					}
					return 948;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 953;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 947;
						break;
						}
					}
					return 947;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 952;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 946;
						break;
						}
					}
					return 946;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 951;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 945;
				break;
				}
			break;
			}
			return 945;
		break;
		case 0xde4d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 968;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 962;
						break;
						}
					}
					return 962;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 967;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 961;
						break;
						}
					}
					return 961;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 966;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 960;
						break;
						}
					}
					return 960;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 965;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 959;
						break;
						}
					}
					return 959;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 964;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 958;
						break;
						}
					}
					return 958;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 963;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 957;
				break;
				}
			break;
			}
			return 957;
		break;
		case 0xde4c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 129;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 128;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 127;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 126;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 125;
				break;
				}
			}
			return 124;
		break;
		case 0xde4b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 920;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 914;
						break;
						}
					}
					return 914;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 919;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 913;
						break;
						}
					}
					return 913;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 918;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 912;
						break;
						}
					}
					return 912;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 917;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 911;
						break;
						}
					}
					return 911;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 916;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 910;
						break;
						}
					}
					return 910;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 915;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 909;
				break;
				}
			break;
			}
			return 909;
		break;
		case 0xde4a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1151;
		break;
		case 0xde49:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1150;
		break;
		case 0xde48:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1149;
		break;
		case 0xde47:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 872;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 866;
						break;
						}
					}
					return 872;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 871;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 865;
						break;
						}
					}
					return 871;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 870;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 864;
						break;
						}
					}
					return 870;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 869;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 863;
						break;
						}
					}
					return 869;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 868;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 862;
						break;
						}
					}
					return 868;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 867;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 861;
				break;
				}
			break;
			}
			return 867;
		break;
		case 0xde46:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 908;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 902;
						break;
						}
					}
					return 902;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 907;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 901;
						break;
						}
					}
					return 901;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 906;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 900;
						break;
						}
					}
					return 900;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 905;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 899;
						break;
						}
					}
					return 899;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 904;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 898;
						break;
						}
					}
					return 898;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 903;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 897;
				break;
				}
			break;
			}
			return 897;
		break;
		case 0xde45:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 896;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 890;
						break;
						}
					}
					return 890;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 895;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 889;
						break;
						}
					}
					return 889;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 894;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 888;
						break;
						}
					}
					return 888;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 893;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 887;
						break;
						}
					}
					return 887;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 892;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 886;
						break;
						}
					}
					return 886;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 891;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 885;
				break;
				}
			break;
			}
			return 885;
		break;
		case 0xde44:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 70;
		break;
		case 0xde43:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 13;
		break;
		case 0xde42:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 12;
		break;
		case 0xde41:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 39;
		break;
		case 0xde40:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 109;
		break;
		case 0xde3f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 110;
		break;
		case 0xde3e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 111;
		break;
		case 0xde3d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 108;
		break;
		case 0xde3c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 107;
		break;
		case 0xde3b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 106;
		break;
		case 0xde3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 103;
		break;
		case 0xde39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 105;
		break;
		case 0xde38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 104;
		break;
		case 0xde37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 85;
		break;
		case 0xde36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 66;
		break;
		case 0xde35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 79;
		break;
		case 0xde34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 76;
		break;
		case 0xde33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 53;
		break;
		case 0xde32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 75;
		break;
		case 0xde31:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 56;
		break;
		case 0xde30:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 58;
		break;
		case 0xde2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 71;
		break;
		case 0xde2e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 74;
		break;
		case 0xde2d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 47;
		break;
		case 0xde2c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 69;
		break;
		case 0xde2b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 43;
		break;
		case 0xde2a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 78;
		break;
		case 0xde29:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 44;
		break;
		case 0xde28:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 57;
		break;
		case 0xde27:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 73;
		break;
		case 0xde26:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 72;
		break;
		case 0xde25:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 59;
		break;
		case 0xde24:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 48;
		break;
		case 0xde23:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 41;
		break;
		case 0xde22:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 46;
		break;
		case 0xde21:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 50;
		break;
		case 0xde20:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 49;
		break;
		case 0xde1f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 37;
		break;
		case 0xde1e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 35;
		break;
		case 0xde1d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 24;
		break;
		case 0xde1c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 25;
		break;
		case 0xde1b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 23;
		break;
		case 0xde1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 21;
		break;
		case 0xde19:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 20;
		break;
		case 0xde18:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 18;
		break;
		case 0xde17:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 19;
		break;
		case 0xde16:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 42;
		break;
		case 0xde15:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 38;
		break;
		case 0xde14:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 36;
		break;
		case 0xde13:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 60;
		break;
		case 0xde12:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 34;
		break;
		case 0xde11:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 68;
		break;
		case 0xde10:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 67;
		break;
		case 0xde0f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 33;
		break;
		case 0xde0e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 30;
		break;
		case 0xde0d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 16;
		break;
		case 0xde0c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 15;
		break;
		case 0xde0b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 22;
		break;
		case 0xde0a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 10;
		break;
		case 0xde09:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 14;
		break;
		case 0xde08:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 90;
		break;
		case 0xde07:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 11;
		break;
		case 0xde06:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 5;
		break;
		case 0xde05:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 6;
		break;
		case 0xde04:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 3;
		break;
		case 0xde03:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2;
		break;
		case 0xde02:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 7;
		break;
		case 0xde01:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 4;
		break;
		case 0xde00:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1;
		break;
		case 0xddff:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1712;
		break;
		case 0xddfe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1757;
		break;
		case 0xddfd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1713;
		break;
		case 0xddfc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1714;
		break;
		case 0xddfb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1729;
		break;
		case 0xddfa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1711;
		break;
		case 0xddf3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1931;
		break;
		case 0xddef:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2215;
		break;
		case 0xdde8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2172;
		break;
		case 0xdde3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 326;
		break;
		case 0xdde1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1842;
		break;
		case 0xddde:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1937;
		break;
		case 0xdddd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1882;
		break;
		case 0xdddc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1782;
		break;
		case 0xddd3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1925;
		break;
		case 0xddd2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1924;
		break;
		case 0xddd1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1928;
		break;
		case 0xddc4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1932;
		break;
		case 0xddc3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1930;
		break;
		case 0xddc2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1936;
		break;
		case 0xddbc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1888;
		break;
		case 0xddb2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1780;
		break;
		case 0xddb1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1779;
		break;
		case 0xdda8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1778;
		break;
		case 0xdda5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1777;
		break;
		case 0xdda4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1978;
		break;
		case 0xdd96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 256;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 255;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 254;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 253;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 252;
				break;
				}
			}
			return 251;
		break;
		case 0xdd95:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 280;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 279;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 278;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 277;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 276;
				break;
				}
			}
			return 275;
		break;
		case 0xdd90:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 250;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 249;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 248;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 247;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 246;
				break;
				}
			}
			return 245;
		break;
		case 0xdd8d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1963;
		break;
		case 0xdd8c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1962;
		break;
		case 0xdd8b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1960;
		break;
		case 0xdd8a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1959;
		break;
		case 0xdd87:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1952;
		break;
		case 0xdd7a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1028;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1027;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1026;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1025;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1024;
				break;
				}
			}
			return 1023;
		break;
		case 0xdd79:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1781;
		break;
		case 0xdd78:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1176;
		break;
		case 0xdd77:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1175;
		break;
		case 0xdd76:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1130;
		break;
		case 0xdd75:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 526;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 520;
						break;
						}
					}
					return 526;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 525;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 519;
						break;
						}
					}
					return 525;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 524;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 518;
						break;
						}
					}
					return 524;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 523;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 517;
						break;
						}
					}
					return 523;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 522;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 516;
						break;
						}
					}
					return 522;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 521;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 515;
				break;
				}
			break;
			}
			return 521;
		break;
		case 0xdd74:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1036;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1035;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1034;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1033;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1032;
				break;
				}
			}
			return 1031;
		break;
		case 0xdd73:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1856;
		break;
		case 0xdd70:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1807;
		break;
		case 0xdd6f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1815;
		break;
		case 0xdd67:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2246;
		break;
		case 0xdd66:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2245;
		break;
		case 0xdd65:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2244;
		break;
		case 0xdd64:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2243;
		break;
		case 0xdd63:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2242;
		break;
		case 0xdd62:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2241;
		break;
		case 0xdd61:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2240;
		break;
		case 0xdd60:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2239;
		break;
		case 0xdd5f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2238;
		break;
		case 0xdd5e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2237;
		break;
		case 0xdd5d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2236;
		break;
		case 0xdd5c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2235;
		break;
		case 0xdd5b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2234;
		break;
		case 0xdd5a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2233;
		break;
		case 0xdd59:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2232;
		break;
		case 0xdd58:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2231;
		break;
		case 0xdd57:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2230;
		break;
		case 0xdd56:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2229;
		break;
		case 0xdd55:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2228;
		break;
		case 0xdd54:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2227;
		break;
		case 0xdd53:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2226;
		break;
		case 0xdd52:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2225;
		break;
		case 0xdd51:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2224;
		break;
		case 0xdd50:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2223;
		break;
		case 0xdd4e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1996;
		break;
		case 0xdd4d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1752;
		break;
		case 0xdd4c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1751;
		break;
		case 0xdd4b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1753;
		break;
		case 0xdd4a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1225;
		break;
		case 0xdd49:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1992;
		break;
		case 0xdd3d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2140;
		break;
		case 0xdd3c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2139;
		break;
		case 0xdd3b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2190;
		break;
		case 0xdd3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2189;
		break;
		case 0xdd39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2192;
		break;
		case 0xdd38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2191;
		break;
		case 0xdd37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2194;
		break;
		case 0xdd36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2193;
		break;
		case 0xdd35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2188;
		break;
		case 0xdd34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2187;
		break;
		case 0xdd33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2195;
		break;
		case 0xdd32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2196;
		break;
		case 0xdd31:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2068;
		break;
		case 0xdd30:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2070;
		break;
		case 0xdd2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1995;
		break;
		case 0xdd2e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1849;
		break;
		case 0xdd2d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1854;
		break;
		case 0xdd2c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1855;
		break;
		case 0xdd2b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1838;
		break;
		case 0xdd2a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1841;
		break;
		case 0xdd29:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1833;
		break;
		case 0xdd28:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1829;
		break;
		case 0xdd27:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1828;
		break;
		case 0xdd26:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1814;
		break;
		case 0xdd25:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1285;
		break;
		case 0xdd24:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2103;
		break;
		case 0xdd23:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2101;
		break;
		case 0xdd22:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2123;
		break;
		case 0xdd21:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2104;
		break;
		case 0xdd20:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2105;
		break;
		case 0xdd1f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2122;
		break;
		case 0xdd1e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2054;
		break;
		case 0xdd1d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2177;
		break;
		case 0xdd1c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2178;
		break;
		case 0xdd1b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2176;
		break;
		case 0xdd1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2174;
		break;
		case 0xdd19:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2175;
		break;
		case 0xdd18:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2184;
		break;
		case 0xdd17:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1950;
		break;
		case 0xdd16:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1948;
		break;
		case 0xdd15:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2210;
		break;
		case 0xdd14:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2209;
		break;
		case 0xdd13:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1971;
		break;
		case 0xdd12:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1970;
		break;
		case 0xdd11:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1881;
		break;
		case 0xdd10:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1969;
		break;
		case 0xdd0f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1968;
		break;
		case 0xdd0e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1967;
		break;
		case 0xdd0d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1966;
		break;
		case 0xdd0c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1812;
		break;
		case 0xdd0b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1811;
		break;
		case 0xdd0a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2208;
		break;
		case 0xdd09:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2207;
		break;
		case 0xdd08:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2205;
		break;
		case 0xdd07:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2206;
		break;
		case 0xdd06:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2064;
		break;
		case 0xdd05:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2063;
		break;
		case 0xdd04:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2158;
		break;
		case 0xdd03:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2159;
		break;
		case 0xdd02:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2157;
		break;
		case 0xdd01:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2156;
		break;
		case 0xdd00:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2155;
		break;
		case 0xdcff:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1850;
		break;
		case 0xdcfd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1792;
		break;
		case 0xdcfc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1787;
		break;
		case 0xdcfb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1799;
		break;
		case 0xdcfa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1798;
		break;
		case 0xdcf9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1790;
		break;
		case 0xdcf8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1789;
		break;
		case 0xdcf7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1788;
		break;
		case 0xdcf6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2099;
		break;
		case 0xdcf5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2055;
		break;
		case 0xdcf4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2018;
		break;
		case 0xdcf3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2019;
		break;
		case 0xdcf2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1774;
		break;
		case 0xdcf1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1773;
		break;
		case 0xdcf0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1938;
		break;
		case 0xdcef:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1915;
		break;
		case 0xdcee:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1914;
		break;
		case 0xdced:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1913;
		break;
		case 0xdcec:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1912;
		break;
		case 0xdceb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1911;
		break;
		case 0xdcea:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1910;
		break;
		case 0xdce9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1902;
		break;
		case 0xdce8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1903;
		break;
		case 0xdce7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1904;
		break;
		case 0xdce6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1908;
		break;
		case 0xdce5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1906;
		break;
		case 0xdce4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1907;
		break;
		case 0xdce3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2211;
		break;
		case 0xdce2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2212;
		break;
		case 0xdce1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1810;
		break;
		case 0xdce0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1797;
		break;
		case 0xdcdf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1796;
		break;
		case 0xdcde:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1794;
		break;
		case 0xdcdd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1964;
		break;
		case 0xdcdc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1916;
		break;
		case 0xdcdb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2045;
		break;
		case 0xdcda:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1946;
		break;
		case 0xdcd9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1945;
		break;
		case 0xdcd8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1944;
		break;
		case 0xdcd7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1943;
		break;
		case 0xdcd6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1947;
		break;
		case 0xdcd5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1942;
		break;
		case 0xdcd4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1940;
		break;
		case 0xdcd3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1939;
		break;
		case 0xdcd2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1941;
		break;
		case 0xdcd1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1919;
		break;
		case 0xdcd0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1953;
		break;
		case 0xdccf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1954;
		break;
		case 0xdcce:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1951;
		break;
		case 0xdccd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1957;
		break;
		case 0xdccc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1956;
		break;
		case 0xdccb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1933;
		break;
		case 0xdcca:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1921;
		break;
		case 0xdcc9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1923;
		break;
		case 0xdcc8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1922;
		break;
		case 0xdcc7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1929;
		break;
		case 0xdcc6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1926;
		break;
		case 0xdcc5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1927;
		break;
		case 0xdcc4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1918;
		break;
		case 0xdcc3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1917;
		break;
		case 0xdcc2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1935;
		break;
		case 0xdcc1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1934;
		break;
		case 0xdcc0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1786;
		break;
		case 0xdcbf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1785;
		break;
		case 0xdcbe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1784;
		break;
		case 0xdcbd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1783;
		break;
		case 0xdcbc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1126;
		break;
		case 0xdcbb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1775;
		break;
		case 0xdcba:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1693;
		break;
		case 0xdcb9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2074;
		break;
		case 0xdcb8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1818;
		break;
		case 0xdcb7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1822;
		break;
		case 0xdcb6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1821;
		break;
		case 0xdcb5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1819;
		break;
		case 0xdcb4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1820;
		break;
		case 0xdcb3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1824;
		break;
		case 0xdcb2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2167;
		break;
		case 0xdcb1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2168;
		break;
		case 0xdcb0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1823;
		break;
		case 0xdcaf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2047;
		break;
		case 0xdcae:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2027;
		break;
		case 0xdcad:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2214;
		break;
		case 0xdcac:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2213;
		break;
		case 0xdcab:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1278;
		break;
		case 0xdcaa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 274;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 273;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 272;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 271;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 270;
				break;
				}
			}
			return 269;
		break;
		case 0xdca9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 95;
		break;
		case 0xdca8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1302;
		break;
		case 0xdca7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1303;
		break;
		case 0xdca6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1304;
		break;
		case 0xdca5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1284;
		break;
		case 0xdca4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2082;
		break;
		case 0xdca3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1839;
		break;
		case 0xdca2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2048;
		break;
		case 0xdca1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1813;
		break;
		case 0xdca0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2079;
		break;
		case 0xdc9f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1988;
		break;
		case 0xdc9e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1982;
		break;
		case 0xdc9d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1987;
		break;
		case 0xdc9c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1977;
		break;
		case 0xdc9b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1974;
		break;
		case 0xdc9a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1975;
		break;
		case 0xdc99:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1976;
		break;
		case 0xdc98:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1986;
		break;
		case 0xdc97:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1984;
		break;
		case 0xdc96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1985;
		break;
		case 0xdc95:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1981;
		break;
		case 0xdc94:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1979;
		break;
		case 0xdc93:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1983;
		break;
		case 0xdc92:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1748;
		break;
		case 0xdc91:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1064;
		break;
		case 0xdc90:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1253;
		break;
		case 0xdc8f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1067;
		break;
		case 0xdc8e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1825;
		break;
		case 0xdc8d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1122;
		break;
		case 0xdc8c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1905;
		break;
		case 0xdc8b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 306;
		break;
		case 0xdc8a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1857;
		break;
		case 0xdc89:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1858;
		break;
		case 0xdc88:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1852;
		break;
		case 0xdc87:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 980;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 974;
						break;
						}
					}
					return 974;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 979;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 973;
						break;
						}
					}
					return 973;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 978;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 972;
						break;
						}
					}
					return 972;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 977;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 971;
						break;
						}
					}
					return 971;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 976;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 970;
						break;
						}
					}
					return 970;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 975;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 969;
				break;
				}
			break;
			}
			return 969;
		break;
		case 0xdc86:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 992;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 986;
						break;
						}
					}
					return 986;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 991;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 985;
						break;
						}
					}
					return 985;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 990;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 984;
						break;
						}
					}
					return 984;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 989;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 983;
						break;
						}
					}
					return 983;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 988;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 982;
						break;
						}
					}
					return 982;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 987;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 981;
				break;
				}
			break;
			}
			return 981;
		break;
		case 0xdc85:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1010;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1009;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1008;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1007;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1006;
				break;
				}
			}
			return 1005;
		break;
		case 0xdc84:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 305;
		break;
		case 0xdc83:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1022;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1021;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1020;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1019;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1018;
				break;
				}
			}
			return 1017;
		break;
		case 0xdc82:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 514;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 508;
						break;
						}
					}
					return 514;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 513;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 507;
						break;
						}
					}
					return 513;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 512;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 506;
						break;
						}
					}
					return 512;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 511;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 505;
						break;
						}
					}
					return 511;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 510;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 504;
						break;
						}
					}
					return 510;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 509;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 503;
				break;
				}
			break;
			}
			return 509;
		break;
		case 0xdc81:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 884;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 878;
						break;
						}
					}
					return 878;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 883;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 877;
						break;
						}
					}
					return 877;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 882;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 876;
						break;
						}
					}
					return 876;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 881;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 875;
						break;
						}
					}
					return 875;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 880;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 874;
						break;
						}
					}
					return 874;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 879;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 873;
				break;
				}
			break;
			}
			return 873;
		break;
		case 0xdc80:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 97;
		break;
		case 0xdc7f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 91;
		break;
		case 0xdc7e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 100;
		break;
		case 0xdc7d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 99;
		break;
		case 0xdc7c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 848;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 847;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 846;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 845;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 844;
				break;
				}
			}
			return 843;
		break;
		case 0xdc7b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 96;
		break;
		case 0xdc7a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 93;
		break;
		case 0xdc79:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 92;
		break;
		case 0xdc78:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 736;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 735;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 734;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 733;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 732;
				break;
				}
			}
			return 731;
		break;
		case 0xdc77:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 502;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 496;
						break;
						}
					}
					return 502;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 501;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 495;
						break;
						}
					}
					return 501;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 500;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 494;
						break;
						}
					}
					return 500;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 499;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 493;
						break;
						}
					}
					return 499;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 498;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 492;
						break;
						}
					}
					return 498;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 497;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 491;
				break;
				}
			break;
			}
			return 497;
		break;
		case 0xdc76:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 334;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 333;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 332;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 331;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 330;
				break;
				}
			}
			return 329;
		break;
		case 0xdc75:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 442;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 441;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 440;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 439;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 438;
				break;
				}
			}
			return 437;
		break;
		case 0xdc74:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 454;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 453;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 452;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 451;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 450;
				break;
				}
			}
			return 449;
		break;
		case 0xdc73:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 472;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 466;
						break;
						}
					}
					return 472;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 471;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 465;
						break;
						}
					}
					return 471;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 470;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 464;
						break;
						}
					}
					return 470;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 469;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 463;
						break;
						}
					}
					return 469;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 468;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 462;
						break;
						}
					}
					return 468;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 467;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 461;
				break;
				}
			break;
			}
			return 467;
		break;
		case 0xdc72:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 460;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 459;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 458;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 457;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 456;
				break;
				}
			}
			return 455;
		break;
		case 0xdc71:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 406;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 400;
						break;
						}
					}
					return 406;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 405;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 399;
						break;
						}
					}
					return 405;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 404;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 398;
						break;
						}
					}
					return 404;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 403;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 397;
						break;
						}
					}
					return 403;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 402;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 396;
						break;
						}
					}
					return 402;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 401;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 395;
				break;
				}
			break;
			}
			return 401;
		break;
		case 0xdc70:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 724;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 723;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 722;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 721;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 720;
				break;
				}
			}
			return 719;
		break;
		case 0xdc6f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1030;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1029;
				break;
				}
			}
			return 1029;
		break;
		case 0xdc6e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 490;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 484;
						break;
						}
					}
					return 490;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 489;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 483;
						break;
						}
					}
					return 489;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 488;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 482;
						break;
						}
					}
					return 488;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 487;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 481;
						break;
						}
					}
					return 487;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 486;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 480;
						break;
						}
					}
					return 486;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 485;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 479;
				break;
				}
			break;
			}
			return 485;
		break;
		case 0xdc6d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1062;
		break;
		case 0xdc6c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1063;
		break;
		case 0xdc6b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1061;
		break;
		case 0xdc6a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1070;
		break;
		case 0xdc69:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 412;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 424;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 376;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 388;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 676;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 700;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 652;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 640;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 628;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 616;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 604;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 592;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 664;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 580;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 568;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 556;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 544;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 688;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 712;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 532;
						break;
						}
					}
					return 358;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 411;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 423;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 375;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 387;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 675;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 699;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 651;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 639;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 627;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 615;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 603;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 591;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 663;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 579;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 567;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 555;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 543;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 687;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 711;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 531;
						break;
						}
					}
					return 357;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 410;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 422;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 374;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 386;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 674;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 698;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 650;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 638;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 626;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 614;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 602;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 590;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 662;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 578;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 566;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 554;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 542;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 686;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 710;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 530;
						break;
						}
					}
					return 356;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 409;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 421;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 373;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 385;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 673;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 697;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 649;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 637;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 625;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 613;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 601;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 589;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 661;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 577;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 565;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 553;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 541;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 685;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 709;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 529;
						break;
						}
					}
					return 355;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 408;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 420;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 372;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 384;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 672;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 696;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 648;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 636;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 624;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 612;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 600;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 588;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 660;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 576;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 564;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 552;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 540;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 684;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 708;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 528;
						break;
						}
					}
					return 354;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xd83e:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xddb3:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 407;
					break;
					case 0xddb2:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 419;
					break;
					case 0xddb1:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 371;
					break;
					case 0xddb0:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 383;
					break;
					}
				break;
				case 0xd83d:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xde92:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 671;
					break;
					case 0xde80:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 695;
					break;
					case 0xdd2c:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 647;
					break;
					case 0xdd27:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 635;
					break;
					case 0xdcbc:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 623;
					break;
					case 0xdcbb:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 611;
					break;
					case 0xdc69:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc67:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end) switch (ch->unicode()) {
											case 0xdc67:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1079;
											break;
											case 0xdc66:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1077;
											break;
											}
										}
									}
									return 1076;
								break;
								case 0xdc66:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdc66) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1078;
											}
										}
									}
									return 1075;
								break;
								}
							}
						}
					break;
					case 0xdc67:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc67:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1089;
								break;
								case 0xdc66:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1087;
								break;
								}
							}
						}
						return 1086;
					break;
					case 0xdc66:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end && ch->unicode() == 0xdc66) {
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1088;
								}
							}
						}
						return 1085;
					break;
					}
				break;
				case 0xd83c:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xdfed:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 599;
					break;
					case 0xdfeb:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 587;
					break;
					case 0xdfa8:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 659;
					break;
					case 0xdfa4:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 575;
					break;
					case 0xdf93:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 563;
					break;
					case 0xdf73:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 551;
					break;
					case 0xdf3e:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 539;
					break;
					}
				break;
				case 0x2764:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0xd83d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdc8b:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end && ch->unicode() == 0x200d) {
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0xd83d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xdc69) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (outLength) *outLength = (ch - start);
											return 1068;
										}
									}
								}
							break;
							case 0xdc69:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 1065;
							break;
							}
						}
					}
				break;
				case 0x2708:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 683;
				break;
				case 0x2696:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 707;
				break;
				case 0x2695:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 527;
				break;
				}
			break;
			}
			return 353;
		break;
		case 0xdc68:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 418;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 430;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 382;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 394;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 682;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 706;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 658;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 646;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 634;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 622;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 610;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 598;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 670;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 586;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 574;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 562;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 550;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 694;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 718;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 538;
						break;
						}
					}
					return 370;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 417;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 429;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 381;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 393;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 681;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 705;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 657;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 645;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 633;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 621;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 609;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 597;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 669;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 585;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 573;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 561;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 549;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 693;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 717;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 537;
						break;
						}
					}
					return 369;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 416;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 428;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 380;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 392;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 680;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 704;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 656;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 644;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 632;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 620;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 608;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 596;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 668;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 584;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 572;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 560;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 548;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 692;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 716;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 536;
						break;
						}
					}
					return 368;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 415;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 427;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 379;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 391;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 679;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 703;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 655;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 643;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 631;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 619;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 607;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 595;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 667;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 583;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 571;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 559;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 547;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 691;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 715;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 535;
						break;
						}
					}
					return 367;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0xd83e:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xddb3:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 414;
							break;
							case 0xddb2:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 426;
							break;
							case 0xddb1:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 378;
							break;
							case 0xddb0:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 390;
							break;
							}
						break;
						case 0xd83d:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xde92:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 678;
							break;
							case 0xde80:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 702;
							break;
							case 0xdd2c:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 654;
							break;
							case 0xdd27:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 642;
							break;
							case 0xdcbc:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 630;
							break;
							case 0xdcbb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 618;
							break;
							}
						break;
						case 0xd83c:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdfed:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 606;
							break;
							case 0xdfeb:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 594;
							break;
							case 0xdfa8:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 666;
							break;
							case 0xdfa4:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 582;
							break;
							case 0xdf93:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 570;
							break;
							case 0xdf73:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 558;
							break;
							case 0xdf3e:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 546;
							break;
							}
						break;
						case 0x2708:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 690;
						break;
						case 0x2696:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 714;
						break;
						case 0x2695:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 534;
						break;
						}
					}
					return 366;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xd83e:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xddb3:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 413;
					break;
					case 0xddb2:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 425;
					break;
					case 0xddb1:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 377;
					break;
					case 0xddb0:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 389;
					break;
					}
				break;
				case 0xd83d:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xde92:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 677;
					break;
					case 0xde80:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 701;
					break;
					case 0xdd2c:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 653;
					break;
					case 0xdd27:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 641;
					break;
					case 0xdcbc:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 629;
					break;
					case 0xdcbb:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 617;
					break;
					case 0xdc69:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc67:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end) switch (ch->unicode()) {
											case 0xdc67:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1074;
											break;
											case 0xdc66:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1072;
											break;
											}
										}
									}
									return 1071;
								break;
								case 0xdc66:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdc66) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1073;
											}
										}
									}
								break;
								}
							}
						}
					break;
					case 0xdc68:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc67:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end) switch (ch->unicode()) {
											case 0xdc67:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1084;
											break;
											case 0xdc66:
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1082;
											break;
											}
										}
									}
									return 1081;
								break;
								case 0xdc66:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									if (ch != end && ch->unicode() == 0x200d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xd83d) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdc66) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (outLength) *outLength = (ch - start);
												return 1083;
											}
										}
									}
									return 1080;
								break;
								}
							}
						}
					break;
					case 0xdc67:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc67:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1094;
								break;
								case 0xdc66:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1092;
								break;
								}
							}
						}
						return 1091;
					break;
					case 0xdc66:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						if (ch != end && ch->unicode() == 0x200d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xd83d) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end && ch->unicode() == 0xdc66) {
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (outLength) *outLength = (ch - start);
									return 1093;
								}
							}
						}
						return 1090;
					break;
					}
				break;
				case 0xd83c:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0xdfed:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 605;
					break;
					case 0xdfeb:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 593;
					break;
					case 0xdfa8:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 665;
					break;
					case 0xdfa4:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 581;
					break;
					case 0xdf93:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 569;
					break;
					case 0xdf73:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 557;
					break;
					case 0xdf3e:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 545;
					break;
					}
				break;
				case 0x2764:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0xd83d) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end) switch (ch->unicode()) {
							case 0xdc8b:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end && ch->unicode() == 0x200d) {
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0xd83d) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xdc68) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (outLength) *outLength = (ch - start);
											return 1069;
										}
									}
								}
							break;
							case 0xdc68:
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (outLength) *outLength = (ch - start);
								return 1066;
							break;
							}
						}
					}
				break;
				case 0x2708:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 689;
				break;
				case 0x2696:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 713;
				break;
				case 0x2695:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 533;
				break;
				}
			break;
			}
			return 365;
		break;
		case 0xdc67:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 340;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 339;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 338;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 337;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 336;
				break;
				}
			}
			return 335;
		break;
		case 0xdc66:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 352;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 351;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 350;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 349;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 348;
				break;
				}
			}
			return 347;
		break;
		case 0xdc65:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 328;
		break;
		case 0xdc64:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 327;
		break;
		case 0xdc63:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 322;
		break;
		case 0xdc62:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1109;
		break;
		case 0xdc61:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1108;
		break;
		case 0xdc60:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1107;
		break;
		case 0xdc5f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1111;
		break;
		case 0xdc5e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1110;
		break;
		case 0xdc5d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1123;
		break;
		case 0xdc5c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1125;
		break;
		case 0xdc5b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1124;
		break;
		case 0xdc5a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1099;
		break;
		case 0xdc59:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1104;
		break;
		case 0xdc58:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1105;
		break;
		case 0xdc57:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1103;
		break;
		case 0xdc56:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1101;
		break;
		case 0xdc55:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1100;
		break;
		case 0xdc54:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1102;
		break;
		case 0xdc53:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1129;
		break;
		case 0xdc52:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1118;
		break;
		case 0xdc51:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1121;
		break;
		case 0xdc50:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 123;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 122;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 121;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 120;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 119;
				break;
				}
			}
			return 118;
		break;
		case 0xdc4f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 135;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 134;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 133;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 132;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 131;
				break;
				}
			}
			return 130;
		break;
		case 0xdc4e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 148;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 147;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 146;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 145;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 144;
				break;
				}
			}
			return 143;
		break;
		case 0xdc4d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 142;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 141;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 140;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 139;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 138;
				break;
				}
			}
			return 137;
		break;
		case 0xdc4c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 202;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 201;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 200;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 199;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 198;
				break;
				}
			}
			return 197;
		break;
		case 0xdc4b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 262;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 261;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 260;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 259;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 258;
				break;
				}
			}
			return 257;
		break;
		case 0xdc4a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 154;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 153;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 152;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 151;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 150;
				break;
				}
			}
			return 149;
		break;
		case 0xdc49:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 214;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 213;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 212;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 211;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 210;
				break;
				}
			}
			return 209;
		break;
		case 0xdc48:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 208;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 207;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 206;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 205;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 204;
				break;
				}
			}
			return 203;
		break;
		case 0xdc47:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 226;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 225;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 224;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 223;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 222;
				break;
				}
			}
			return 221;
		break;
		case 0xdc46:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 220;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 219;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 218;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 217;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 216;
				break;
				}
			}
			return 215;
		break;
		case 0xdc45:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 309;
		break;
		case 0xdc44:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 307;
		break;
		case 0xdc43:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 321;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 320;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 319;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 318;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 317;
				break;
				}
			}
			return 316;
		break;
		case 0xdc42:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 315;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 314;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 313;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 312;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 311;
				break;
				}
			}
			return 310;
		break;
		case 0xdc41:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xd83d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end && ch->unicode() == 0xdde8) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 2173;
					}
				}
			}
			return 323;
		break;
		case 0xdc40:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 324;
		break;
		case 0xdc3f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1231;
		break;
		case 0xdc3e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1233;
		break;
		case 0xdc3d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1146;
		break;
		case 0xdc3c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1140;
		break;
		case 0xdc3b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1139;
		break;
		case 0xdc3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1163;
		break;
		case 0xdc39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1136;
		break;
		case 0xdc38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1147;
		break;
		case 0xdc37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1145;
		break;
		case 0xdc36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1133;
		break;
		case 0xdc35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1148;
		break;
		case 0xdc34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1165;
		break;
		case 0xdc33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1192;
		break;
		case 0xdc32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1235;
		break;
		case 0xdc31:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1134;
		break;
		case 0xdc30:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1137;
		break;
		case 0xdc2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1142;
		break;
		case 0xdc2e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1144;
		break;
		case 0xdc2d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1135;
		break;
		case 0xdc2c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1191;
		break;
		case 0xdc2b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1204;
		break;
		case 0xdc2a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1203;
		break;
		case 0xdc29:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1218;
		break;
		case 0xdc28:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1141;
		break;
		case 0xdc27:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1154;
		break;
		case 0xdc26:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1155;
		break;
		case 0xdc25:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1158;
		break;
		case 0xdc24:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1156;
		break;
		case 0xdc23:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1157;
		break;
		case 0xdc22:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1178;
		break;
		case 0xdc21:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1188;
		break;
		case 0xdc20:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1189;
		break;
		case 0xdc1f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1190;
		break;
		case 0xdc1e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1171;
		break;
		case 0xdc1d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1167;
		break;
		case 0xdc1c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1172;
		break;
		case 0xdc1b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1168;
		break;
		case 0xdc1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1251;
		break;
		case 0xdc19:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1183;
		break;
		case 0xdc18:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1200;
		break;
		case 0xdc17:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1164;
		break;
		case 0xdc16:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1211;
		break;
		case 0xdc15:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1217;
		break;
		case 0xdc14:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1153;
		break;
		case 0xdc13:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1220;
		break;
		case 0xdc12:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1152;
		break;
		case 0xdc11:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1213;
		break;
		case 0xdc10:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1215;
		break;
		case 0xdc0f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1212;
		break;
		case 0xdc0e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1210;
		break;
		case 0xdc0d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1179;
		break;
		case 0xdc0c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1170;
		break;
		case 0xdc0b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1193;
		break;
		case 0xdc0a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1195;
		break;
		case 0xdc09:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1234;
		break;
		case 0xdc08:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1219;
		break;
		case 0xdc07:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1226;
		break;
		case 0xdc06:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1197;
		break;
		case 0xdc05:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1196;
		break;
		case 0xdc04:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1209;
		break;
		case 0xdc03:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1207;
		break;
		case 0xdc02:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1208;
		break;
		case 0xdc01:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1229;
		break;
		case 0xdc00:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1230;
		break;
		}
	break;
	case 0xd83c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end) switch (ch->unicode()) {
		case 0xdffa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1848;
		break;
		case 0xdff9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1433;
		break;
		case 0xdff8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1426;
		break;
		case 0xdff7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1909;
		break;
		case 0xdff5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1616;
		break;
		case 0xdff4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xdb40:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xdc67) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end && ch->unicode() == 0xdb40) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end && ch->unicode() == 0xdc62) {
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (ch != end && ch->unicode() == 0xdb40) {
								if (++ch != end && ch->unicode() == kPostfix) ++ch;
								if (ch != end) switch (ch->unicode()) {
								case 0xdc77:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0xdb40) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xdc6c) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdb40) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (ch != end && ch->unicode() == 0xdc73) {
													if (++ch != end && ch->unicode() == kPostfix) ++ch;
													if (ch != end && ch->unicode() == 0xdb40) {
														if (++ch != end && ch->unicode() == kPostfix) ++ch;
														if (ch != end && ch->unicode() == 0xdc7f) {
															if (++ch != end && ch->unicode() == kPostfix) ++ch;
															if (outLength) *outLength = (ch - start);
															return 2492;
														}
													}
												}
											}
										}
									}
								break;
								case 0xdc73:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0xdb40) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xdc63) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdb40) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (ch != end && ch->unicode() == 0xdc74) {
													if (++ch != end && ch->unicode() == kPostfix) ++ch;
													if (ch != end && ch->unicode() == 0xdb40) {
														if (++ch != end && ch->unicode() == kPostfix) ++ch;
														if (ch != end && ch->unicode() == 0xdc7f) {
															if (++ch != end && ch->unicode() == kPostfix) ++ch;
															if (outLength) *outLength = (ch - start);
															return 2491;
														}
													}
												}
											}
										}
									}
								break;
								case 0xdc65:
									if (++ch != end && ch->unicode() == kPostfix) ++ch;
									if (ch != end && ch->unicode() == 0xdb40) {
										if (++ch != end && ch->unicode() == kPostfix) ++ch;
										if (ch != end && ch->unicode() == 0xdc6e) {
											if (++ch != end && ch->unicode() == kPostfix) ++ch;
											if (ch != end && ch->unicode() == 0xdb40) {
												if (++ch != end && ch->unicode() == kPostfix) ++ch;
												if (ch != end && ch->unicode() == 0xdc67) {
													if (++ch != end && ch->unicode() == kPostfix) ++ch;
													if (ch != end && ch->unicode() == 0xdb40) {
														if (++ch != end && ch->unicode() == kPostfix) ++ch;
														if (ch != end && ch->unicode() == 0xdc7f) {
															if (++ch != end && ch->unicode() == kPostfix) ++ch;
															if (outLength) *outLength = (ch - start);
															return 2490;
														}
													}
												}
											}
										}
									}
								break;
								}
							}
						}
					}
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0x2620) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2249;
				}
			break;
			}
			return 2248;
		break;
		case 0xdff3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0x200d) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xd83c) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end && ch->unicode() == 0xdf08) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 2252;
					}
				}
			}
			return 2247;
		break;
		case 0xdff0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1715;
		break;
		case 0xdfef:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1716;
		break;
		case 0xdfee:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1898;
		break;
		case 0xdfed:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1737;
		break;
		case 0xdfec:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1739;
		break;
		case 0xdfeb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1746;
		break;
		case 0xdfea:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1745;
		break;
		case 0xdfe9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1747;
		break;
		case 0xdfe8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1744;
		break;
		case 0xdfe7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2083;
		break;
		case 0xdfe6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1743;
		break;
		case 0xdfe5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1742;
		break;
		case 0xdfe4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1741;
		break;
		case 0xdfe3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1740;
		break;
		case 0xdfe2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1738;
		break;
		case 0xdfe1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1733;
		break;
		case 0xdfe0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1732;
		break;
		case 0xdfdf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1717;
		break;
		case 0xdfde:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1759;
		break;
		case 0xdfdd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1724;
		break;
		case 0xdfdc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1725;
		break;
		case 0xdfdb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1749;
		break;
		case 0xdfda:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1735;
		break;
		case 0xdfd9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1767;
		break;
		case 0xdfd8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1734;
		break;
		case 0xdfd7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1736;
		break;
		case 0xdfd6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1723;
		break;
		case 0xdfd5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1730;
		break;
		case 0xdfd4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1728;
		break;
		case 0xdfd3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1425;
		break;
		case 0xdfd2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1427;
		break;
		case 0xdfd1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1428;
		break;
		case 0xdfd0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1421;
		break;
		case 0xdfcf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1430;
		break;
		case 0xdfce:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1657;
		break;
		case 0xdfcd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1668;
		break;
		case 0xdfcc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1507;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1501;
						break;
						}
					}
					return 1507;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1506;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1500;
						break;
						}
					}
					return 1506;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1505;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1499;
						break;
						}
					}
					return 1505;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1504;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1498;
						break;
						}
					}
					return 1504;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1503;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1497;
						break;
						}
					}
					return 1503;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1502;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1496;
				break;
				}
			break;
			}
			return 1502;
		break;
		case 0xdfcb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1456;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1450;
						break;
						}
					}
					return 1456;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1455;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1449;
						break;
						}
					}
					return 1455;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1454;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1448;
						break;
						}
					}
					return 1454;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1453;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1447;
						break;
						}
					}
					return 1453;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1452;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1446;
						break;
						}
					}
					return 1452;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1451;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1445;
				break;
				}
			break;
			}
			return 1451;
		break;
		case 0xdfca:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1549;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1543;
						break;
						}
					}
					return 1549;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1548;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1542;
						break;
						}
					}
					return 1548;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1547;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1541;
						break;
						}
					}
					return 1547;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1546;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1540;
						break;
						}
					}
					return 1546;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1545;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1539;
						break;
						}
					}
					return 1545;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1544;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1538;
				break;
				}
			break;
			}
			return 1544;
		break;
		case 0xdfc9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1422;
		break;
		case 0xdfc8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1417;
		break;
		case 0xdfc7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1513;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1512;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1511;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1510;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1509;
				break;
				}
			}
			return 1508;
		break;
		case 0xdfc6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1610;
		break;
		case 0xdfc5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1614;
		break;
		case 0xdfc4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1537;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1531;
						break;
						}
					}
					return 1537;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1536;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1530;
						break;
						}
					}
					return 1536;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1535;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1529;
						break;
						}
					}
					return 1535;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1534;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1528;
						break;
						}
					}
					return 1534;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1533;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1527;
						break;
						}
					}
					return 1533;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1532;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1526;
				break;
				}
			break;
			}
			return 1532;
		break;
		case 0xdfc3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end) switch (ch->unicode()) {
			case 0xd83c:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1060;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1054;
						break;
						}
					}
					return 1060;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1059;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1053;
						break;
						}
					}
					return 1059;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1058;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1052;
						break;
						}
					}
					return 1058;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1057;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1051;
						break;
						}
					}
					return 1057;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					if (ch != end && ch->unicode() == 0x200d) {
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (ch != end) switch (ch->unicode()) {
						case 0x2642:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1056;
						break;
						case 0x2640:
							if (++ch != end && ch->unicode() == kPostfix) ++ch;
							if (outLength) *outLength = (ch - start);
							return 1050;
						break;
						}
					}
					return 1056;
				break;
				}
			break;
			case 0x200d:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0x2642:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1055;
				break;
				case 0x2640:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 1049;
				break;
				}
			break;
			}
			return 1055;
		break;
		case 0xdfc2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1444;
		break;
		case 0xdfc1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2250;
		break;
		case 0xdfc0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1416;
		break;
		case 0xdfbf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1442;
		break;
		case 0xdfbe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1420;
		break;
		case 0xdfbd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1437;
		break;
		case 0xdfbc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1638;
		break;
		case 0xdfbb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1644;
		break;
		case 0xdfba:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1642;
		break;
		case 0xdfb9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1639;
		break;
		case 0xdfb8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1643;
		break;
		case 0xdfb7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1641;
		break;
		case 0xdfb6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2161;
		break;
		case 0xdfb5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2160;
		break;
		case 0xdfb4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2221;
		break;
		case 0xdfb3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1648;
		break;
		case 0xdfb2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1645;
		break;
		case 0xdfb1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1424;
		break;
		case 0xdfb0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1650;
		break;
		case 0xdfaf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1647;
		break;
		case 0xdfae:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1649;
		break;
		case 0xdfad:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1633;
		break;
		case 0xdfac:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1635;
		break;
		case 0xdfab:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1618;
		break;
		case 0xdfaa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1620;
		break;
		case 0xdfa9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1116;
		break;
		case 0xdfa8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1634;
		break;
		case 0xdfa7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1637;
		break;
		case 0xdfa6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2098;
		break;
		case 0xdfa5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1791;
		break;
		case 0xdfa4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1636;
		break;
		case 0xdfa3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1434;
		break;
		case 0xdfa2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1719;
		break;
		case 0xdfa1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1718;
		break;
		case 0xdfa0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1720;
		break;
		case 0xdf9f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1619;
		break;
		case 0xdf9e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1793;
		break;
		case 0xdf9b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1802;
		break;
		case 0xdf9a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1801;
		break;
		case 0xdf99:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1800;
		break;
		case 0xdf97:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1617;
		break;
		case 0xdf96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1615;
		break;
		case 0xdf93:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1119;
		break;
		case 0xdf92:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1127;
		break;
		case 0xdf91:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1758;
		break;
		case 0xdf90:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1899;
		break;
		case 0xdf8f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1893;
		break;
		case 0xdf8e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1897;
		break;
		case 0xdf8d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1245;
		break;
		case 0xdf8c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2366;
		break;
		case 0xdf8b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1246;
		break;
		case 0xdf8a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1895;
		break;
		case 0xdf89:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1896;
		break;
		case 0xdf88:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1892;
		break;
		case 0xdf87:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1763;
		break;
		case 0xdf86:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1764;
		break;
		case 0xdf85:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xdfff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 778;
				break;
				case 0xdffe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 777;
				break;
				case 0xdffd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 776;
				break;
				case 0xdffc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 775;
				break;
				case 0xdffb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 774;
				break;
				}
			}
			return 773;
		break;
		case 0xdf84:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1237;
		break;
		case 0xdf83:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 102;
		break;
		case 0xdf82:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1383;
		break;
		case 0xdf81:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1891;
		break;
		case 0xdf80:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1894;
		break;
		case 0xdf7f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1388;
		break;
		case 0xdf7e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1407;
		break;
		case 0xdf7d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1410;
		break;
		case 0xdf7c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1395;
		break;
		case 0xdf7b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1401;
		break;
		case 0xdf7a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1400;
		break;
		case 0xdf79:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1406;
		break;
		case 0xdf78:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1405;
		break;
		case 0xdf77:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1403;
		break;
		case 0xdf76:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1399;
		break;
		case 0xdf75:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1397;
		break;
		case 0xdf74:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1409;
		break;
		case 0xdf73:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1343;
		break;
		case 0xdf72:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1363;
		break;
		case 0xdf71:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1366;
		break;
		case 0xdf70:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1382;
		break;
		case 0xdf6f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1393;
		break;
		case 0xdf6e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1384;
		break;
		case 0xdf6d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1385;
		break;
		case 0xdf6c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1386;
		break;
		case 0xdf6b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1387;
		break;
		case 0xdf6a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1390;
		break;
		case 0xdf69:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1389;
		break;
		case 0xdf68:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1378;
		break;
		case 0xdf67:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1377;
		break;
		case 0xdf66:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1379;
		break;
		case 0xdf65:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1372;
		break;
		case 0xdf64:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1368;
		break;
		case 0xdf63:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1365;
		break;
		case 0xdf62:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1375;
		break;
		case 0xdf61:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1376;
		break;
		case 0xdf60:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1335;
		break;
		case 0xdf5f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1352;
		break;
		case 0xdf5e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1338;
		break;
		case 0xdf5d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1361;
		break;
		case 0xdf5c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1362;
		break;
		case 0xdf5b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1364;
		break;
		case 0xdf5a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1370;
		break;
		case 0xdf59:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1369;
		break;
		case 0xdf58:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1371;
		break;
		case 0xdf57:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1347;
		break;
		case 0xdf56:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1348;
		break;
		case 0xdf55:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1353;
		break;
		case 0xdf54:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1351;
		break;
		case 0xdf53:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1317;
		break;
		case 0xdf52:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1319;
		break;
		case 0xdf51:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1320;
		break;
		case 0xdf50:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1311;
		break;
		case 0xdf4f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1309;
		break;
		case 0xdf4e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1310;
		break;
		case 0xdf4d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1322;
		break;
		case 0xdf4c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1314;
		break;
		case 0xdf4b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1313;
		break;
		case 0xdf4a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1312;
		break;
		case 0xdf49:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1315;
		break;
		case 0xdf48:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1318;
		break;
		case 0xdf47:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1316;
		break;
		case 0xdf46:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1326;
		break;
		case 0xdf45:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1325;
		break;
		case 0xdf44:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1250;
		break;
		case 0xdf43:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1247;
		break;
		case 0xdf42:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1248;
		break;
		case 0xdf41:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1249;
		break;
		case 0xdf40:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1244;
		break;
		case 0xdf3f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1242;
		break;
		case 0xdf3e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1252;
		break;
		case 0xdf3d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1332;
		break;
		case 0xdf3c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1259;
		break;
		case 0xdf3b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1260;
		break;
		case 0xdf3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1257;
		break;
		case 0xdf39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1255;
		break;
		case 0xdf38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1258;
		break;
		case 0xdf37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1254;
		break;
		case 0xdf36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1331;
		break;
		case 0xdf35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1236;
		break;
		case 0xdf34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1240;
		break;
		case 0xdf33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1239;
		break;
		case 0xdf32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1238;
		break;
		case 0xdf31:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1241;
		break;
		case 0xdf30:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1391;
		break;
		case 0xdf2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1357;
		break;
		case 0xdf2e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1356;
		break;
		case 0xdf2d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1350;
		break;
		case 0xdf2c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1301;
		break;
		case 0xdf2b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1308;
		break;
		case 0xdf2a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1286;
		break;
		case 0xdf29:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1296;
		break;
		case 0xdf28:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1297;
		break;
		case 0xdf27:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1294;
		break;
		case 0xdf26:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1293;
		break;
		case 0xdf25:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1291;
		break;
		case 0xdf24:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1289;
		break;
		case 0xdf21:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1863;
		break;
		case 0xdf20:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1762;
		break;
		case 0xdf1f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1280;
		break;
		case 0xdf1e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1261;
		break;
		case 0xdf1d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1262;
		break;
		case 0xdf1c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1264;
		break;
		case 0xdf1b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1263;
		break;
		case 0xdf1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1265;
		break;
		case 0xdf19:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1274;
		break;
		case 0xdf18:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1269;
		break;
		case 0xdf17:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1268;
		break;
		case 0xdf16:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1267;
		break;
		case 0xdf15:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1266;
		break;
		case 0xdf14:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1273;
		break;
		case 0xdf13:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1272;
		break;
		case 0xdf12:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1271;
		break;
		case 0xdf11:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1270;
		break;
		case 0xdf10:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2078;
		break;
		case 0xdf0f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1277;
		break;
		case 0xdf0e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1275;
		break;
		case 0xdf0d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1276;
		break;
		case 0xdf0c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1769;
		break;
		case 0xdf0b:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1726;
		break;
		case 0xdf0a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1307;
		break;
		case 0xdf09:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1770;
		break;
		case 0xdf08:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1287;
		break;
		case 0xdf07:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1765;
		break;
		case 0xdf06:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1766;
		break;
		case 0xdf05:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1760;
		break;
		case 0xdf04:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1761;
		break;
		case 0xdf03:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1768;
		break;
		case 0xdf02:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1132;
		break;
		case 0xdf01:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 1771;
		break;
		case 0xdf00:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2081;
		break;
		case 0xde51:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2015;
		break;
		case 0xde50:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2028;
		break;
		case 0xde3a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2023;
		break;
		case 0xde39:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2033;
		break;
		case 0xde38:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2022;
		break;
		case 0xde37:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2024;
		break;
		case 0xde36:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2020;
		break;
		case 0xde35:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2032;
		break;
		case 0xde34:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2031;
		break;
		case 0xde33:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2087;
		break;
		case 0xde32:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2034;
		break;
		case 0xde2f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2073;
		break;
		case 0xde1a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2021;
		break;
		case 0xde02:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2088;
		break;
		case 0xde01:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2100;
		break;
		case 0xddff:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2504;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2503;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2454;
				break;
				}
			}
		break;
		case 0xddfe:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2396;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2502;
				break;
				}
			}
		break;
		case 0xddfd:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xddf0) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2372;
				}
			}
		break;
		case 0xddfc:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2439;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2500;
				break;
				}
			}
		break;
		case 0xddfb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2496;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2499;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2485;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2285;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2498;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2464;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2497;
				break;
				}
			}
		break;
		case 0xddfa:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2495;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2494;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2493;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2253;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2486;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2487;
				break;
				}
			}
		break;
		case 0xddf9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2473;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2471;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2484;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2479;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2481;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2478;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2480;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2482;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2475;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2477;
				break;
				case 0xddef:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2472;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2474;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2476;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2334;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2298;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2483;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2460;
				break;
				}
			}
		break;
		case 0xddf8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2467;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2470;
				break;
				case 0xddfd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2448;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2321;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2441;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2456;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2466;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2453;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2443;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2440;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2446;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2449;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2450;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2460;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2447;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2468;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2465;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2445;
				break;
				case 0xdde7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2452;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2442;
				break;
				}
			}
		break;
		case 0xddf7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2438;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2437;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2444;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2436;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2435;
				break;
				}
			}
		break;
		case 0xddf6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xdde6) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2434;
				}
			}
		break;
		case 0xddf5:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2427;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2423;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2432;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2424;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2433;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2430;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2463;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2431;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2422;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2429;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2426;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2333;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2428;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2425;
				break;
				}
			}
		break;
		case 0xddf4:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end && ch->unicode() == 0xddf2) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2421;
				}
			}
		break;
		case 0xddf3:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2412;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2416;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2408;
				break;
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2409;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2420;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2410;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2413;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2415;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2417;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2414;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2411;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2407;
				break;
				}
			}
		break;
		case 0xddf2:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2405;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2388;
				break;
				case 0xddfd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2397;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2387;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2389;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2395;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2391;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2403;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2394;
				break;
				case 0xddf6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2393;
				break;
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2419;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2384;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2401;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2406;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2390;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2385;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2392;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2386;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2331;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2402;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2399;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2400;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2404;
				break;
				}
			}
		break;
		case 0xddf1:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2380;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2376;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2383;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2382;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2378;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2379;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2458;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2381;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2462;
				break;
				case 0xdde7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2377;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2375;
				break;
				}
			}
		break;
		case 0xddf0:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2369;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2296;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2373;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2455;
				break;
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2418;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2461;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2304;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2371;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2290;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2374;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2370;
				break;
				}
			}
		break;
		case 0xddef:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2365;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2368;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2364;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2367;
				break;
				}
			}
		break;
		case 0xddee:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2363;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2355;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2358;
				break;
				case 0xddf6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2359;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2284;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2356;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2361;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2362;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2360;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2357;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2293;
				break;
				}
			}
		break;
		case 0xdded:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2354;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2351;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2310;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2352;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2353;
				break;
				}
			}
		break;
		case 0xddec:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2350;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2349;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2345;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2346;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2451;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2341;
				break;
				case 0xddf6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2322;
				break;
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2344;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2348;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2336;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2342;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2340;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2339;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2347;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2332;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2337;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2343;
				break;
				case 0xdde7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2489;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2335;
				break;
				}
			}
		break;
		case 0xddeb:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2331;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2328;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2398;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2327;
				break;
				case 0xddef:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2329;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2330;
				break;
				}
			}
		break;
		case 0xddea:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2326;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2325;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2457;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2323;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2501;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2320;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2324;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2319;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2457;
				break;
				}
			}
		break;
		case 0xdde9:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2257;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2318;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2317;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2315;
				break;
				case 0xddef:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2316;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2284;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2338;
				break;
				}
			}
		break;
		case 0xdde8:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2314;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2313;
				break;
				case 0xddfd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2301;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2312;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2294;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2311;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2308;
				break;
				case 0xddf5:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2331;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2303;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2300;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2291;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2299;
				break;
				case 0xddf0:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2307;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2309;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2469;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2305;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2297;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2306;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2302;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2292;
				break;
				}
			}
		break;
		case 0xdde7:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2276;
				break;
				case 0xddfe:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2274;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2282;
				break;
				case 0xddfb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2420;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2279;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2270;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2283;
				break;
				case 0xddf6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2295;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2280;
				break;
				case 0xddf3:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2286;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2278;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2459;
				break;
				case 0xddef:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2277;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2289;
				break;
				case 0xdded:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2271;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2287;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2288;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2275;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2272;
				break;
				case 0xdde7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2273;
				break;
				case 0xdde6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2281;
				break;
				}
			}
		break;
		case 0xdde6:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end && ch->unicode() == 0xd83c) {
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (ch != end) switch (ch->unicode()) {
				case 0xddff:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2269;
				break;
				case 0xddfd:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2255;
				break;
				case 0xddfc:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2266;
				break;
				case 0xddfa:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2267;
				break;
				case 0xddf9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2268;
				break;
				case 0xddf8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2258;
				break;
				case 0xddf7:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2264;
				break;
				case 0xddf6:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2262;
				break;
				case 0xddf4:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2260;
				break;
				case 0xddf2:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2265;
				break;
				case 0xddf1:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2256;
				break;
				case 0xddee:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2261;
				break;
				case 0xddec:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2263;
				break;
				case 0xddeb:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2254;
				break;
				case 0xddea:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2488;
				break;
				case 0xdde9:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2259;
				break;
				case 0xdde8:
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (outLength) *outLength = (ch - start);
					return 2460;
				break;
				}
			}
		break;
		case 0xdd9a:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2026;
		break;
		case 0xdd99:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2108;
		break;
		case 0xdd98:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2040;
		break;
		case 0xdd97:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2107;
		break;
		case 0xdd96:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2106;
		break;
		case 0xdd95:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2110;
		break;
		case 0xdd94:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2013;
		break;
		case 0xdd93:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2111;
		break;
		case 0xdd92:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2109;
		break;
		case 0xdd91:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2038;
		break;
		case 0xdd8e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2037;
		break;
		case 0xdd7f:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2086;
		break;
		case 0xdd7e:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2039;
		break;
		case 0xdd71:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2036;
		break;
		case 0xdd70:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2035;
		break;
		case 0xdccf:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2220;
		break;
		case 0xdc04:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2222;
		break;
		}
	break;
	case 0x3299:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2029;
	break;
	case 0x3297:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2030;
	break;
	case 0x303d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2065;
	break;
	case 0x3030:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2179;
	break;
	case 0x2b55:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2042;
	break;
	case 0x2b50:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1279;
	break;
	case 0x2b1c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2204;
	break;
	case 0x2b1b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2203;
	break;
	case 0x2b07:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2144;
	break;
	case 0x2b06:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2143;
	break;
	case 0x2b05:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2142;
	break;
	case 0x2935:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2154;
	break;
	case 0x2934:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2153;
	break;
	case 0x27bf:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2181;
	break;
	case 0x27b0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2180;
	break;
	case 0x27a1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2141;
	break;
	case 0x2797:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2164;
	break;
	case 0x2796:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2163;
	break;
	case 0x2795:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2162;
	break;
	case 0x2764:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1972;
	break;
	case 0x2763:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1980;
	break;
	case 0x2757:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2057;
	break;
	case 0x2755:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2058;
	break;
	case 0x2754:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2060;
	break;
	case 0x2753:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2059;
	break;
	case 0x274e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2077;
	break;
	case 0x274c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2041;
	break;
	case 0x2747:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2075;
	break;
	case 0x2744:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1298;
	break;
	case 0x2734:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2025;
	break;
	case 0x2733:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2076;
	break;
	case 0x2728:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1281;
	break;
	case 0x2721:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1994;
	break;
	case 0x271d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1990;
	break;
	case 0x2716:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2165;
	break;
	case 0x2714:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2182;
	break;
	case 0x2712:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1961;
	break;
	case 0x270f:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1965;
	break;
	case 0x270d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end && ch->unicode() == 0xd83c) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 286;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 285;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 284;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 283;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 282;
			break;
			}
		}
		return 281;
	break;
	case 0x270c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end && ch->unicode() == 0xd83c) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 184;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 183;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 182;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 181;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 180;
			break;
			}
		}
		return 179;
	break;
	case 0x270b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end && ch->unicode() == 0xd83c) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 238;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 237;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 236;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 235;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 234;
			break;
			}
		}
		return 233;
	break;
	case 0x270a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end && ch->unicode() == 0xd83c) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 160;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 159;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 158;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 157;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 156;
			break;
			}
		}
		return 155;
	break;
	case 0x2709:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1901;
	break;
	case 0x2708:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1689;
	break;
	case 0x2705:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2072;
	break;
	case 0x2702:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1958;
	break;
	case 0x26fd:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1706;
	break;
	case 0x26fa:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1731;
	break;
	case 0x26f9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end) switch (ch->unicode()) {
		case 0xd83c:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				if (ch != end && ch->unicode() == 0x200d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0x2642:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1482;
					break;
					case 0x2640:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1476;
					break;
					}
				}
				return 1482;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				if (ch != end && ch->unicode() == 0x200d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0x2642:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1481;
					break;
					case 0x2640:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1475;
					break;
					}
				}
				return 1481;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				if (ch != end && ch->unicode() == 0x200d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0x2642:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1480;
					break;
					case 0x2640:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1474;
					break;
					}
				}
				return 1480;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				if (ch != end && ch->unicode() == 0x200d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0x2642:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1479;
					break;
					case 0x2640:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1473;
					break;
					}
				}
				return 1479;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				if (ch != end && ch->unicode() == 0x200d) {
					if (++ch != end && ch->unicode() == kPostfix) ++ch;
					if (ch != end) switch (ch->unicode()) {
					case 0x2642:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1478;
					break;
					case 0x2640:
						if (++ch != end && ch->unicode() == kPostfix) ++ch;
						if (outLength) *outLength = (ch - start);
						return 1472;
					break;
					}
				}
				return 1478;
			break;
			}
		break;
		case 0x200d:
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0x2642:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 1477;
			break;
			case 0x2640:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 1471;
			break;
			}
		break;
		}
		return 1477;
	break;
	case 0x26f8:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1440;
	break;
	case 0x26f7:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1443;
	break;
	case 0x26f5:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1699;
	break;
	case 0x26f4:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1703;
	break;
	case 0x26f3:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1432;
	break;
	case 0x26f2:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1721;
	break;
	case 0x26f1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1722;
	break;
	case 0x26f0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1727;
	break;
	case 0x26ea:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1750;
	break;
	case 0x26e9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1754;
	break;
	case 0x26d4:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2044;
	break;
	case 0x26d3:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1836;
	break;
	case 0x26d1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1120;
	break;
	case 0x26cf:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1832;
	break;
	case 0x26ce:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2000;
	break;
	case 0x26c8:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1295;
	break;
	case 0x26c5:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1290;
	break;
	case 0x26c4:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1300;
	break;
	case 0x26be:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1418;
	break;
	case 0x26bd:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1415;
	break;
	case 0x26b1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1847;
	break;
	case 0x26b0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1846;
	break;
	case 0x26ab:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2186;
	break;
	case 0x26aa:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2185;
	break;
	case 0x26a1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1282;
	break;
	case 0x26a0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2066;
	break;
	case 0x269c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2069;
	break;
	case 0x269b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2014;
	break;
	case 0x2699:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1834;
	break;
	case 0x2697:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1853;
	break;
	case 0x2696:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1826;
	break;
	case 0x2694:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1843;
	break;
	case 0x2693:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1705;
	break;
	case 0x2692:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1830;
	break;
	case 0x267f:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2085;
	break;
	case 0x267e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2166;
	break;
	case 0x267b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2071;
	break;
	case 0x2668:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2049;
	break;
	case 0x2666:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2219;
	break;
	case 0x2665:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2218;
	break;
	case 0x2663:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2217;
	break;
	case 0x2660:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2216;
	break;
	case 0x265f:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1646;
	break;
	case 0x2653:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2012;
	break;
	case 0x2652:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2011;
	break;
	case 0x2651:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2010;
	break;
	case 0x2650:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2009;
	break;
	case 0x264f:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2008;
	break;
	case 0x264e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2007;
	break;
	case 0x264d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2006;
	break;
	case 0x264c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2005;
	break;
	case 0x264b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2004;
	break;
	case 0x264a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2003;
	break;
	case 0x2649:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2002;
	break;
	case 0x2648:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2001;
	break;
	case 0x263a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 9;
	break;
	case 0x2639:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 40;
	break;
	case 0x2638:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1993;
	break;
	case 0x262f:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1997;
	break;
	case 0x262e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1989;
	break;
	case 0x262a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1991;
	break;
	case 0x2626:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1998;
	break;
	case 0x2623:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2017;
	break;
	case 0x2622:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2016;
	break;
	case 0x2620:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 98;
	break;
	case 0x261d:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		if (ch != end && ch->unicode() == 0xd83c) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (ch != end) switch (ch->unicode()) {
			case 0xdfff:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 232;
			break;
			case 0xdffe:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 231;
			break;
			case 0xdffd:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 230;
			break;
			case 0xdffc:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 229;
			break;
			case 0xdffb:
				if (++ch != end && ch->unicode() == kPostfix) ++ch;
				if (outLength) *outLength = (ch - start);
				return 228;
			break;
			}
		}
		return 227;
	break;
	case 0x2618:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1243;
	break;
	case 0x2615:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1396;
	break;
	case 0x2614:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1305;
	break;
	case 0x2611:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2183;
	break;
	case 0x260e:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1795;
	break;
	case 0x2604:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1283;
	break;
	case 0x2603:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1299;
	break;
	case 0x2602:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1306;
	break;
	case 0x2601:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1292;
	break;
	case 0x2600:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1288;
	break;
	case 0x25fe:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2199;
	break;
	case 0x25fd:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2200;
	break;
	case 0x25fc:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2201;
	break;
	case 0x25fb:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2202;
	break;
	case 0x25c0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2138;
	break;
	case 0x25b6:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2127;
	break;
	case 0x25ab:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2198;
	break;
	case 0x25aa:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2197;
	break;
	case 0x24c2:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2080;
	break;
	case 0x23fa:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2131;
	break;
	case 0x23f9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2130;
	break;
	case 0x23f8:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2128;
	break;
	case 0x23f3:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1809;
	break;
	case 0x23f2:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1805;
	break;
	case 0x23f1:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1804;
	break;
	case 0x23f0:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1806;
	break;
	case 0x23ef:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2129;
	break;
	case 0x23ee:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2133;
	break;
	case 0x23ed:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2132;
	break;
	case 0x23ec:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2137;
	break;
	case 0x23eb:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2136;
	break;
	case 0x23ea:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2135;
	break;
	case 0x23e9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2134;
	break;
	case 0x23cf:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2126;
	break;
	case 0x2328:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1776;
	break;
	case 0x231b:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1808;
	break;
	case 0x231a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 1772;
	break;
	case 0x21aa:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2151;
	break;
	case 0x21a9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2152;
	break;
	case 0x2199:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2147;
	break;
	case 0x2198:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2146;
	break;
	case 0x2197:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2145;
	break;
	case 0x2196:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2148;
	break;
	case 0x2195:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2149;
	break;
	case 0x2194:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2150;
	break;
	case 0x2139:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2102;
	break;
	case 0x2122:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if ((ch - 1)->unicode() != kPostfix) {
			return 0;
		}
		if (outLength) *outLength = (ch - start);
		return 2169;
	break;
	case 0x2049:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2062;
	break;
	case 0x203c:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (outLength) *outLength = (ch - start);
		return 2061;
	break;
	case 0xae:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if ((ch - 1)->unicode() != kPostfix) {
			return 0;
		}
		if (outLength) *outLength = (ch - start);
		return 2171;
	break;
	case 0xa9:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if ((ch - 1)->unicode() != kPostfix) {
			return 0;
		}
		if (outLength) *outLength = (ch - start);
		return 2170;
	break;
	case 0x39:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2121;
		}
	break;
	case 0x38:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2120;
		}
	break;
	case 0x37:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2119;
		}
	break;
	case 0x36:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2118;
		}
	break;
	case 0x35:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2117;
		}
	break;
	case 0x34:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2116;
		}
	break;
	case 0x33:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2115;
		}
	break;
	case 0x32:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2114;
		}
	break;
	case 0x31:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2113;
		}
	break;
	case 0x30:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2112;
		}
	break;
	case 0x2a:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2125;
		}
	break;
	case 0x23:
		if (++ch != end && ch->unicode() == kPostfix) ++ch;
		if (ch != end && ch->unicode() == 0x20e3) {
			if (++ch != end && ch->unicode() == kPostfix) ++ch;
			if (outLength) *outLength = (ch - start);
			return 2124;
		}
	break;
	}

	return 0;
}

} // namespace

namespace internal {

int FullCount() {
	return Items.size();
}

EmojiPtr ByIndex(int index) {
	return (index >= 0 && index < Items.size()) ? &Items[index] : nullptr;
}

EmojiPtr FindReplace(const QChar *start, const QChar *end, int *outLength) {
	auto index = FindReplaceIndex(start, end, outLength);
	return index ? &Items[index - 1] : nullptr;
}

const std::vector<std::pair<QString, int>> GetReplacementPairs() {
	return ReplacementPairs;
}

EmojiPtr Find(const QChar *start, const QChar *end, int *outLength) {
	auto index = FindIndex(start, end, outLength);
	return index ? &Items[index - 1] : nullptr;
}

void Init() {
	auto id = IdData;
	auto takeString = [&id](int size) {
		auto result = QString::fromRawData(reinterpret_cast<const QChar*>(id), size);
		id += size;
		return result;
	};

	Items.reserve(base::array_size(Data));
	for (auto &data : Data) {
		Items.emplace_back(
			takeString(data.idSize),
			data.original ? &Items[data.original - 1] : nullptr,
			uint32(Items.size()),
			data.postfixed ? true : false,
			data.variated ? true : false,
			One::CreationTag());
	}
	InitReplacements();
}

} // namespace internal

int GetSectionCount(Section section) {
	Expects(section != Section::Recent);

	switch (section) {
	case Section::People: return 357;
	case Section::Nature: return 176;
	case Section::Food: return 106;
	case Section::Activity: return 92;
	case Section::Travel: return 120;
	case Section::Objects: return 195;
	case Section::Symbols: return 533;
	}
	return 0;
}

EmojiPack GetSection(Section section) {
	Expects(section != Section::Recent);

	switch (section) {

	case Section::People: {
		static auto result = FillSection(0, 357);
		return result;
	} break;

	case Section::Nature: {
		static auto result = FillSection(357, 176);
		return result;
	} break;

	case Section::Food: {
		static auto result = FillSection(533, 106);
		return result;
	} break;

	case Section::Activity: {
		static auto result = FillSection(639, 92);
		return result;
	} break;

	case Section::Travel: {
		static auto result = FillSection(731, 120);
		return result;
	} break;

	case Section::Objects: {
		static auto result = FillSection(851, 195);
		return result;
	} break;

	case Section::Symbols: {
		static auto result = FillSection(1046, 533);
		return result;
	} break;
	}
	return EmojiPack();
}

} // namespace Emoji
} // namespace Ui
