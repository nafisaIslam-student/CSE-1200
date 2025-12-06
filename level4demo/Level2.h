#include "Struct.h"
extern int player_x;
extern int player_y;

int level2Time = 110;
bool level2Failed = false;
bool showLevel2FailScreen = false;
int collectedMirrors = 0;
bool level2Won = false;

extern bool level2;
extern bool showLevel2Info;
extern bool level2InfoActive;
extern bool soundOn2;
extern bool level2SoundOn;
extern int level2MusicState;
int mirror_X = 0;
int mirror_Y = 0;
char mirrorNormal[30] = { "MIII.bmp" };
char mirror_shiny_1[30] = { "MII1.bmp" };
char mirror_shiny_2[30] = { "MI2.bmp" };
bool useShiny = true;
int shinyFrame = 0;

Mirror mirror1 = { 440, 440, 60, 60, "MIII.bmp", false, false };
Mirror mirror2 = { 0, 500, 60, 60, "MIII.bmp", false, false };
Mirror mirror3 = { 900, 450, 60, 60, "MIII.bmp", false, false };
Mirror mirror4 = { 500, 700, 60, 60, "MIII.bmp", false, false };
Mirror mirror5 = { 900, 558, 60, 60, "MIII.bmp", false, false };
Mirror mirror6 = { 200, 50, 60, 60, "MIII.bmp", false, false };
Mirror mirror7 = { 920, 50, 60, 60, "MIII.bmp", false, false };
Mirror mirror8 = { 800, 700, 60, 60, "MIII.bmp", false, false };
Mirror mirror9 = { 1100, 600, 60, 60, "MIII.bmp", false, false };
Mirror mirror10 = { 160, 690, 60, 60, "MIII.bmp", false, false };
int mirrorCount = 10;
Mirror mirrors[10] = { mirror1, mirror2, mirror3, mirror4, mirror5, mirror6, mirror7,
mirror8, mirror9, mirror10 };
void showMirrors() {
	for (int i = 0; i < mirrorCount; i++) {
		Mirror m = mirrors[i];
		if (!m.picked) {
			if (useShiny) {

				if (shinyFrame == 0)
					iShowBMP2(m.x, m.y, mirror_shiny_1, 0);
				else
					iShowBMP2(m.x, m.y, mirror_shiny_2, 0);
			}
			else {
				iShowBMP2(m.x, m.y, m.image, 0);
			}
			if (player_x + 32 > m.x && player_x < m.x + m.w &&
				player_y + 32 > m.y && player_y < m.y + m.h) {
				mirrors[i].showText = true;
			}
			else {
				mirrors[i].showText = false;
			}
		}
	}
}

objectBox box1 = { 436, 436, 60, 60, "Box.bmp", false, false };
objectBox box2 = { 0, 496, 60, 60, "Box.bmp", false, false };
objectBox box3 = { 896, 446, 60, 60, "Box.bmp", false, false };
objectBox box4 = { 496, 696, 60, 60, "Box.bmp", false, false };
objectBox box5 = { 896, 554, 60, 60, "Box.bmp", false, false };
objectBox box6 = { 196, 46, 60, 60, "Box.bmp", false, false };
objectBox box7 = { 916, 46, 60, 60, "Box.bmp", false, false };
objectBox box8 = { 796, 696, 60, 60, "Box.bmp", false, false };
objectBox box9 = { 1096, 596, 60, 60, "Box.bmp", false, false };
objectBox box10 = { 156, 686, 60, 60, "Box.bmp", false, false };
int boxCount = 10;
objectBox boxs[10] = { box1, box2, box3, box4, box5, box6, box7, box8, box9, box10 };
void showBoxs() {
	for (int i = 0; i < boxCount; i++) {
		objectBox b = boxs[i];
		if (!b.picked) {
			iShowBMP2(b.x, b.y, b.image, 0);
			if (player_x + 32 > b.x && player_x < b.x + b.w &&
				player_y + 32 > b.y && player_y < b.y + b.h) {
				iText(b.x - 50, b.y - 30, " ", GLUT_BITMAP_TIMES_ROMAN_24);
				boxs[i].showText = true;
			}
			else {
				boxs[i].showText = false;
			}
		}
	}
}
restrictedArea areas2[40] = { { 0, 325, 150, 70 }, { 230, 325, 190, 70 }, { 230, 525, 190,
70 }, { 40, 525, 110, 70 }, { 440, 480, 270, 70 }, { 790, 480, 190, 70 },
{ 1070, 480, 100, 70 }, { 975, 565, 95, 70 }, { 830, 145, 60, 40 }, { 230, 655, 30, 70 },
{ 70, 655, 30, 70 }, { 831, 630, 100, 75 }, { 850, 720, 60, 10 },
{ 873, 590, 15, 55 }, { 985, 10, 190, 170 }, { 385, 10, 150, 85 }, { 146, 292, 4, 101 },
{ 217, 292, 4, 101 }, { 146, 492, 4, 101 }, { 217, 492, 4, 101 },
{ 335, 610, 4, 181 }, { 25, 610, 4, 184 }, { 777, 450, 4, 101 }, { 707, 450, 2, 101 }, {
	415, 410, 4, 135 }, { 0, 400, 70, 70 }, { 330, 410, 70, 70 }, { 560, 575, 40, 40 }, { 1050, 690, 100, 65 },
	{ 1130, 250, 60, 25 }, { 770, 0, 180, 50 }, { 50, 0, 100, 50 }, { 85, 0, 29, 90 } };

char* timeImages[7] = {
	"Image\\t1.bmp",
	"Image\\t2.bmp",
	"Image\\t3.bmp",
	"Image\\t4.bmp",
	"Image\\t5.bmp",
	"Image\\t6.bmp",
	"Image\\t7.bmp"
};

void Level2Draw(){
	iShowBMP(0, 0, "FG.bmp");
	showMirrors();
	showBoxs();
	iSetColor(255, 255, 255);
	iShowBMP2(40, 30, "images//info_icon.bmp", 0);
	if (showLevel2Info) {
		iShowBMP(400, 280, "images//intro_page.bmp");
	}
	
	iText(500, 40, "Press B to remove the box", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 20, "Press M to collect the mirrors", GLUT_BITMAP_TIMES_ROMAN_24);
	if (level2SoundOn){
		iShowBMP2(1030, 735, "images\\soundoff.bmp", 0);
	}
	else{
		iShowBMP2(970, 734, "images\\soundon.bmp", 0);
	}
	if (level2SoundOn && level2MusicState == 0){
		PlaySound("level2bgm.wav", NULL, SND_ASYNC | SND_LOOP);
		level2MusicState = 1;
	}
	if (level2 && !level2Failed) {
		int imgIndex = (int)((110 - level2Time) * 7 / 110);
		if (imgIndex > 6) imgIndex = 6;
		iShowBMP2(50, 750, timeImages[imgIndex], 0);

		iSetColor(0, 0, 0);
		iText(60, 780, "Time left", GLUT_BITMAP_HELVETICA_18);
	}
	char mirrorMsg[50];
	iShowBMP2(264, 754, "MI2.bmp", 0);
	sprintf_s(mirrorMsg, " Mirrors Collected : %d/%d", collectedMirrors, mirrorCount);
	iSetColor(0, 0, 0);
	iText(300, 762, mirrorMsg, GLUT_BITMAP_HELVETICA_18);

	if (level2Won) {
		iShowBMP(250, 200, "Image\\game_won.bmp");
	}
	else if (showLevel2FailScreen) {
		iShowBMP(250, 200, "Image\\game_over.bmp");
	}

}
