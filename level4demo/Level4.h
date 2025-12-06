#include "Player.h"
extern int score;
extern int player_x;
extern int player_y;
extern bool equipSword;
extern int attack;
extern bool isAttacking;
extern bool wrongChosen;
extern int timeTaken;

bool game_over4 = false;


bool timerFlash = false; ///timer when decrease
int flashCounter = 0;
int flashDuration = 7; 

bool skelUndefeated = false;
extern int d;
extern int cr;

bool showIntro = true;

void showIntroDialogue() {
	iShowImage(400, 300, 400, 250, d);

	iSetColor(255, 255, 255);
	iText(430, 500, "Welcome to Level 4!", GLUT_BITMAP_HELVETICA_18);
	iText(430, 485, "Short instruction : ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 467, "Press backspace to remove the boxes ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 455, "Press Enter to collect the boxes ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 443, "Press 'E' to equip sword, press again to remove it", GLUT_BITMAP_HELVETICA_12);
	iText(430, 423, "Warning : ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 410, "               Your Time will decrease if -  ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 395, "1. You choose the boxes with wrong symbols ", GLUT_BITMAP_HELVETICA_12);
	iText(430, 380, "2. You fail to defeat the ghost which will appear suddenly ", GLUT_BITMAP_HELVETICA_12);

	//Ok button
	iSetColor(0, 200, 0);
	iFilledRectangle(550, 335, 80, 30); // x, y, w, h
	iSetColor(255, 255, 255);
	iText(576, 344, "OK", GLUT_BITMAP_HELVETICA_18);
}
char skeleton[10][20] = {
	"00_mintskeleton.bmp",
	"01_mintskeleton.bmp",
	"02_mintskeleton.bmp",
	"03_mintskeleton.bmp",
	"04_mintskeleton.bmp",
	"05_mintskeleton.bmp",
	"06_mintskeleton.bmp",
	"07_mintskeleton.bmp",
	"08_mintskeleton.bmp",
	"09_mintskeleton.bmp"
};
char statue[6][20] = {
	"anim0.bmp",
	"anim1.bmp",
	"anim2.bmp",
	"anim3.bmp",
	"anim4.bmp",
	"anim5.bmp"
};

struct Monster {
	int spawnTime;     
	bool active;       
	bool defeated;     
};

Monster monsters[5] = {
	{ 210, false, false },
	{ 170, false, false },
	{ 130, false, false },
	{ 90, false, false },
	{ 40, false, false }
};

int numMonsters = 5;

extern int skeleton_move;
int statue_move = 0;
int animDelay = 0;
int animSpeed = 4;
int timer_w = 220;


void skel(){
	
		animDelay++;
		if (animDelay >= animSpeed) {
			animDelay = 0;

			skeleton_move++;
			if (skeleton_move >= 10){ skeleton_move = 0; }
	}

	}
void decreaseTimer(){
if (!showIntro && score!=7)
	{
		timer_w--;

		for (int i = 0; i < numMonsters; i++) {
			if (monsters[i].active && !monsters[i].defeated) {
				
				if (timer_w <= monsters[i].spawnTime - 4 && timer_w >= monsters[i].spawnTime - 7) {
					timer_w -= 15;
					timerFlash = true;
					flashCounter = flashDuration;
					monsters[i].defeated = true; 
				}
			}
		}

		if (timer_w < 0) timer_w = 0;
	}
}

void skelAppear() {
	for (int i = 0; i < numMonsters; i++) {
		if (!monsters[i].defeated) { 
			if (timer_w <= monsters[i].spawnTime && timer_w >= monsters[i].spawnTime - 7) {
				monsters[i].active = true;
				iShowBMP2(player_x + 20, player_y + 20, skeleton[skeleton_move], 0);
				skel(); 
			}
			else {
				monsters[i].active = false; 
			}
		}
	}
}


restrictedArea areas4[50] = { { 0, 0, 429, 134 }, { 0, 633, 102, 85 }, { 492, 674, 92, 66 }, { 1002, 266, 6, 295 }, {694, 0,140, 170},
{ 923, 122, 60, 70 }, { 895, 0, 305, 50 }, { 977, 10, 10, 50 }, { 470, 260, 93, 73 }, { 612, 263, 70, 70 }, { 426, 333, 20, 80 },
{ 0, 424, 30, 87 }, { 149, 516, 51, 82 }, { 215, 530, 130, 65 }, { 242, 610, 71, 40 }, { 320, 651, 8, 136 }, { 1105, 700, 95, 100 }, { 1127, 387, 73, 76 }, {242, 610, 71,40},
{ 722, 656, 60, 131 }, { 788, 620, 33, 66 }, { 914, 553, 29, 71 }, { 945, 541, 52, 60 }, { 827, 524, 6, 81 }, { 827, 524, 6, 81 }, { 895, 524, 3, 51 }, {549, 444, 47, 72},
{ 751, 386, 99, 39 }, { 784, 351, 29, 10 }, { 771, 435, 48, 31 }, { 961, 199, 6, 17 }, { 977, 229, 10, 17 }, { 878, 151, 42, 28 }, { 696, 326, 20, 67 }, {617, 509, 48, 10},
{ 716, 414, 10, 48 }, { 422, 416, 10, 40 }, { 500, 509, 40, 10 }, { 124, 456, 10, 56 }, { 279, 651, 38, 50 }, { 55, 450, 23, 50 }, { 454, 478, 10, 20 }, { 677, 487, 10, 15 }, {875, 40,15,100}
};
int collisionCount4 = sizeof(areas4) / sizeof(areas4[0]);

bool dialogueVisible_1 = true;
bool dialogueVisible_2 = true;
bool dialogueVisible_3 = true;
bool dialogueVisible_4 = true;
bool dialogueVisible_5 = true;
bool dialogueVisible_6 = true;
bool dialogueVisible_7 = true;

Box_1 b1 = { 580, 610, 60, 60, "img3/22.bmp", false, false, true };
Box_1 b2 = { 640, 610, 60, 60, "img3/33.bmp", false, false, false };

Box_1 b3 = { 540, 350, 60, 60, "img3/11.bmp", false, false, false }; 
Box_1 b4 = { 480, 350, 60, 60, "img3/44.bmp", false, false, true }; 

Box_1 b5 = { 860, 350, 60, 60, "img3/55.bmp", false, false, false };
Box_1 b6 = { 920, 350, 60, 60, "img3/66.bmp", false, false, true };

Box_1 b7 = { 1020, 630, 60, 60, "img3/77.bmp", false, false, false };
Box_1 b8 = { 960, 630, 60, 60, "img3/88.bmp", false, false, true };

Box_1 b9 = { 120, 630, 60, 60, "img3/11.bmp", false, false, true }; 
Box_1 b10 = { 180, 630, 60, 60, "img3/44.bmp", false, false, false }; 

Box_1 b11 = { 430, 60, 60, 60, "img3/77.bmp", false, false, false };
Box_1 b12 = { 490, 60, 60, 60, "img3/22.bmp", false, false, true };

Box_1 b13 = { 1000, 80, 60, 60, "img3/33.bmp", false, false, true };
Box_1 b14 = { 1060, 80, 60, 60, "img3/88.bmp", false, false, false };

int Count = 2;
Box_1 box_0[2] = { b1, b2 };
Box_1 box_1[2] = { b3, b4 };
Box_1 box_2[2] = { b5, b6 };
Box_1 box_3[2] = { b7, b8 };
Box_1 box_4[2] = { b9, b10 };
Box_1 box_5[2] = { b11, b12 };
Box_1 box_6[2] = { b13, b14 };

void showDialogue() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Diamond shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_1() {
	for (int i = 0; i < Count; i++) {
		if (!box_0[i].picked) {
			iShowBMP2(box_0[i].x, box_0[i].y, box_0[i].image, 0);

			if (dialogueVisible_1) {
				if (player_x + 32 > box_0[i].x && player_x < box_0[i].x + box_0[i].w &&
					player_y + 32 > box_0[i].y && player_y < box_0[i].y + box_0[i].h) {
					showDialogue();
				}
			}
		}
	}
}

void showDialogue_1() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Greek cross shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_2() {
	for (int i = 0; i < Count; i++) {
		if (!box_1[i].picked) {
			iShowBMP2(box_1[i].x, box_1[i].y, box_1[i].image, 0);

			if (dialogueVisible_2) {
				if (player_x + 32 > box_1[i].x && player_x < box_1[i].x + box_1[i].w &&
					player_y + 32 > box_1[i].y && player_y < box_1[i].y + box_1[i].h) {
					showDialogue_1();
				}
			}
		}
	}
}

void showDialogue_2() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Right Angle shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_3() {
	for (int i = 0; i < Count; i++) {
		if (!box_2[i].picked) {
			iShowBMP2(box_2[i].x, box_2[i].y, box_2[i].image, 0);

			if (dialogueVisible_3) {
				if (player_x + 32 > box_2[i].x && player_x < box_2[i].x + box_2[i].w &&
					player_y + 32 > box_2[i].y && player_y < box_2[i].y + box_2[i].h) {
					showDialogue_2();
				}
			}
		}
	}
}

void showDialogue_3() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Tetrahedron shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_4() {
	for (int i = 0; i < Count; i++) {
		if (!box_3[i].picked) {
			iShowBMP2(box_3[i].x, box_3[i].y, box_3[i].image, 0);

			if (dialogueVisible_4) {
				if (player_x + 32 > box_3[i].x && player_x < box_3[i].x + box_3[i].w &&
					player_y + 32 > box_3[i].y && player_y < box_3[i].y + box_3[i].h) {
					showDialogue_3();
				}
			}
		}
	}
}

void showDialogue_4() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Pentagon shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_5() {
	for (int i = 0; i < Count; i++) {
		if (!box_4[i].picked) {
			iShowBMP2(box_4[i].x, box_4[i].y, box_4[i].image, 0);

			if (dialogueVisible_5) {
				if (player_x + 32 > box_4[i].x && player_x < box_4[i].x + box_4[i].w &&
					player_y + 32 > box_4[i].y && player_y < box_4[i].y + box_4[i].h) {
					showDialogue_4();
				}
			}
		}
	}
}

void showDialogue_5() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Kite shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_6() {
	for (int i = 0; i < Count; i++) {
		if (!box_5[i].picked) {
			iShowBMP2(box_5[i].x, box_5[i].y, box_5[i].image, 0);

			if (dialogueVisible_6) {
				if (player_x + 32 > box_5[i].x && player_x < box_5[i].x + box_5[i].w &&
					player_y + 32 > box_5[i].y && player_y < box_5[i].y + box_5[i].h) {
					showDialogue_5();
				}
			}
		}
	}
}

void showDialogue_6() {

	iShowImage(345, 160, 300, 60, d);


	iSetColor(255, 255, 255);
	iText(365, 190, "Choose the Trapezium shape  ", GLUT_BITMAP_HELVETICA_18);
}

void showBoxes_7() {
	for (int i = 0; i < Count; i++) {
		if (!box_6[i].picked) {
			iShowBMP2(box_6[i].x, box_6[i].y, box_6[i].image, 0);

			if (dialogueVisible_7) {
				if (player_x + 32 > box_6[i].x && player_x < box_6[i].x + box_6[i].w &&
					player_y + 32 > box_6[i].y && player_y < box_6[i].y + box_6[i].h) {
					showDialogue_6();
				}

			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////

char normal[30] = { "Image2/Green/1.bmp" };
char shiny_1[30] = { "Image2/Green/2.bmp" };
char shiny_2[30] = { "Image2/Green/3.bmp" };
char shiny_3[30] = { "Image2/Green/4.bmp" };

extern bool useShinyy;
extern int shinyyFrame;


Box c1 = { 610, 645, 40, 40, "Image2/Green/1.bmp", false, false }; //b1 
Box c2 = { 518, 393, 40, 40, "Image2/Green/1.bmp", false, false }; // b4
Box c3 = { 950, 386, 40, 40, "Image2/Green/1.bmp", false, false }; //b6
Box c4 = { 985, 668, 40, 40, "Image2/Green/1.bmp", false, false }; //b8
Box c5 = { 150, 670, 40, 40, "Image2/Green/1.bmp", false, false }; //b9
Box c6 = { 520, 100, 40, 40, "Image2/Green/1.bmp", false, false }; //b12
Box c7 = { 1030, 118, 40, 40, "Image2/Green/1.bmp", false, false }; //b13

int count_1 = 7;
Box crystal[7] = { c1, c2, c3, c4, c5, c6, c7 };

void showCrystal() {
	for (int i = 0; i < count_1; i++) {
		Box c = crystal[i];
		if (!c.picked) {
			if (useShinyy) {

				if (shinyyFrame == 0)
					iShowBMP2(c.x, c.y, shiny_1, 0);
				else if (shinyyFrame == 1)
					iShowBMP2(c.x, c.y, shiny_2, 0);
				else if (shinyyFrame == 2)
					iShowBMP2(c.x, c.y, shiny_3, 0);
				else if (shinyyFrame == 3)
					iShowBMP2(c.x, c.y, normal, 0);
			}
			else {
				iShowBMP2(c.x, c.y, c.image, 0);
			}

			if (player_x + 32 > c.x && player_x < c.x + c.w &&
				player_y + 32 > c.y && player_y < c.y + c.h) {
			}
		}
	}
}





void level4Draw(){
	iShowBMP(0, 0, "level4_map.bmp");
	if (showIntro) {
		showIntroDialogue();
	}
	else {
		
		iSetColor(0, 0, 0);
		iFilledRectangle(13, 753, 230, 30);

		if (timerFlash) {
			iSetColor(139, 0, 0); 
			flashCounter--;
			if (flashCounter <= 0) {
				timerFlash = false;
			}
		}
		else {
			iSetColor(80, 200, 120); 
		}
		iFilledRectangle(16, 757, timer_w, 25);
		animDelay++;
		if (animDelay >= animSpeed) {
			animDelay = 0;
			statue_move++;
			if (statue_move >= 6) statue_move = 0;  
		}
		iShowBMP2(520, 390, statue[statue_move], 0);

		showCrystal();
		showBoxes_1();
		showBoxes_2();
		showBoxes_3();
		showBoxes_4();
		showBoxes_5();
		showBoxes_6();
		showBoxes_7();

		char str[200];
		sprintf_s(str, "Crystal Collected: %d/7", score);
		iSetColor(255, 255, 255);
		iText(400, 760, str, GLUT_BITMAP_HELVETICA_18);

		if (!equipSword){ playerMovement(); }
		if (equipSword && attack==0){ playerMoveSword(); }
		if (attack > 0 && equipSword){ playerHitSword(); }
		

		skelAppear();
		
		
		
		if (timer_w == 0 && score < 7){
			game_over4 = true;
			iShowBMP(250, 200, "Image\\game_over.bmp");
		}
		if (score == 7){
			iShowBMP(140, 132, "final_won2.bmp");
		}
		
		if (score == 7){ timeTaken = 220-timer_w; }
		
	}
}
