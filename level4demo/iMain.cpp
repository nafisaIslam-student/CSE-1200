
#include "iGraphics.h"
#include "Math.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Player.h"
#include "Struct.h"
#include "MainMenu.h"
#include "Dialogue.h"
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int masterTick = 0;

int m = -1;
int soundOn = -1;
int musicState = 0;
bool soundOn2 = false;
bool level2SoundOn = true;
int level2MusicState = 0;
bool level3SoundOn = true;
int level3MusicState = 0;

int animationDelay = 0;
int frame = 4;

///////////////////////file and name//////////////////////////////////
char playerName[50] = "";
int nameLen = 0;
bool enterName = false;
int timeTaken;
bool scoreShow = false;
void saveScore(const char* playerName, int timeTaken){

	FILE *saving = fopen("score.txt", "a");


	fprintf(saving, "%s\t\t%d\n", playerName, timeTaken);
	fclose(saving);
}
char nameSorted[100][100]; 
int scoreSorted[100]; 
int totalEntries = 0;
void loadScore()
{

	char prevName[100];
	char ch;
	int prevScore;

	FILE *loadingScore = fopen("score.txt", "r");

	int i = 0;


	
	while (fscanf(loadingScore, "%s %d", prevName, &prevScore) == 2)
	{


		strcpy(nameSorted[i], prevName);
		scoreSorted[i] = prevScore;

		i++;

	}


	totalEntries = i;
	int temp;
	// sorting the arrays in descending order
	for (int i = 0; i < totalEntries; i++)
	{
		for (int j = i; j < totalEntries; j++)
		{
			if (scoreSorted[i] > scoreSorted[j])
			{

				temp = scoreSorted[i];
				scoreSorted[i] = scoreSorted[j];
				scoreSorted[j] = temp;


				//swapping names
				char temp[100];
				strcpy(temp, nameSorted[i]);
				strcpy(nameSorted[i], nameSorted[j]);
				strcpy(nameSorted[j], temp);


			}

		}
	}


	fclose(loadingScore);
}


bool savedScore = false;
///////////////Player variables//////////////////
int player_start_x = 40;
int player_start_y = 415;
int player_x = 569;
int player_y = 296;
int player_speed = 5;
int player_health = 5;
bool front = false;
bool back = false;
bool left = false;
bool right = false;
bool stand = true;
extern bool Player_Stand;
/////////////////////General variables/////////////////////
int j = 0;
int currentLevel = 1;
bool level1 = true;
bool level2 = false;
bool level3 = false;
bool level4 = false;
///////////////////Level 1 variables////////////////////
bool frontSword = false;
int attack = 0;
int rock_start_x = 1200;
int rock_start_y = 420;
float distance = 0;
int countHit = 0;
int countAttack = 0;
bool playerDead = false;
int rock_health = 5;
bool rock_defeated = false;
bool game_over = false;
extern int rock_x;
extern int rock_y;
extern int j_rock;
extern bool showNextChar;
extern bool pickSword;
extern int j_death;
extern int j_hit;
////////////////////Level 2 variables/////////////////////
extern int mirrorCount;
extern int boxCount;
extern int level2Time;
extern bool level2Failed;
extern bool showLevel2FailScreen;
extern int collectedMirrors;
extern bool level2Won;
bool showLevel2Info = false;
bool level2InfoActive = false;
void toggleShine() {
	if (useShiny) {
		shinyFrame = 1 - shinyFrame;
	}
}
//////////////////////level3/////////////////////////////
extern int collisionCount3;

//////////////////////level4//////////////////////////////
extern int collisionCount4;
extern int timer_w;
int score = 0;
bool isAttacking = false;
bool equipSword = false;
extern bool game_over4;

extern bool timerFlash;
extern int flashCounter;
extern int flashDuration;
bool wrongChosen = false;
bool useShinyy = true;
int shinyyFrame = 0;

bool showEnd = false;
extern bool game_end;



void toggleShine_Crystal() {
	if (useShinyy) {
		shinyyFrame = shinyFrame % 4;
	}
}

int collisionCount = 4;
bool isColliding(int newX, int newY) {
	if (currentLevel == 1){
		for (int i = 0; i < collisionCount; i++) {
			restrictedArea cz = areas[i];

			if (newX + 50 > cz.x && newX < cz.x + cz.w &&
				newY + 50 > cz.y && newY < cz.y + cz.h) {
				return true;
			}
		}
		return false;
	}
	else if (currentLevel == 2){
		for (int i = 0; i < 40; i++) {
			restrictedArea cz = areas2[i];

			if (newX + 32 > cz.x && newX < cz.x + cz.w &&
				newY + 32 > cz.y && newY < cz.y + cz.h) {
				return true;
			}
		}
		return false;
	}
	else if (currentLevel == 3){
		for (int i = 0; i < collisionCount3; i++) {
			restrictedArea cz = areas3[i];

			if (newX + 32 > cz.x && newX < cz.x + cz.w &&
				newY + 32 > cz.y && newY < cz.y + cz.h) {

				return true;
			}
		}
		return false;
	}
	else if (currentLevel == 4){
		for (int i = 0; i < collisionCount4; i++) {
			restrictedArea cz = areas4[i];

			if (newX + 32 > cz.x && newX < cz.x + cz.w &&
				newY + 32 > cz.y && newY < cz.y + cz.h) {

				return true;
			}
		}
		return false;
	}

}

void playMenuMusic(){
	if (soundOn && musicState == 0 && (m == -1 || m == 0 || m == 2 || m == 3 || m == 4)){
		PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);
		musicState = 1;
	}
}

bool motivationScene = false;   // motivation dialogue first
bool hospitalTransition = false;
bool hospitalScene = false;
bool showFinalWon = false;
int currentFinalLine = 0;
int fadeValue = 255;  // for fade transition
int dialogueIndex = 0;



void showMotivationDialogue() {

	iShowImage(300, 100, 700, 120, d);


	iSetColor(255, 255, 255);
	iText(340, 182, "Dear Kris, Congratulations, You have conquered strength and confidence.  ", GLUT_BITMAP_HELVETICA_18);
	iText(340, 152, " Are you ready to enjoy your second life?  ", GLUT_BITMAP_HELVETICA_18);
	// NEXT button
	iSetColor(0, 200, 0);
	iFilledRectangle(860, 140, 80, 30);
	iSetColor(255, 255, 255);
	iText(880, 148, "NEXT", GLUT_BITMAP_HELVETICA_18);
}

char dialogues[13][200] = {
	"Kris : Wh..wher...where am i ???",
	"Nurse: Oh my God! You have waken up.",
	"Kris : Wha..what do you mean?",
	"Nurse: You dont remember anything?.",
	"Kris : No.Whats wrong with me?",
	"Nurse : You had a terrible bus accident . ",
	"Another nurse : Everyone in the bus were found dead.Only you were breathing.",
	"Kris : Then ? Then what happend? ",
	"Nurse : Just when everyone was about to loose hope, a miracle happend.",
	"Another nurse : And look you have waken up.",
	"Kris : Do i have a family. Wheres my parents?",
	"Nurse : yes i shall call your family and the doctor now."
};

void showHospitalDialogue() {
	iSetColor(255, 255, 255);
	iFilledRectangle(300, 100, 700, 120);

	iSetColor(0, 0, 0);
	iText(320, 170, dialogues[dialogueIndex], GLUT_BITMAP_HELVETICA_18);

	iSetColor(0, 200, 0);
	iFilledRectangle(900, 110, 80, 30);
	iSetColor(255, 255, 255);
	iText(920, 120, "NEXT", GLUT_BITMAP_HELVETICA_18);
}

void showHospitalTransition() {
	iShowBMP(0, 0, "h.bmp");

	if (fadeValue > 0) {
		fadeValue -= 3;
		if (fadeValue < 0) fadeValue = 0;

		iSetColor(fadeValue, fadeValue, fadeValue);
		iFilledRectangle(0, 0, 1280, 800);
	}
	else {
		hospitalScene = true;
	}
}
char finalLines[6][100] = {
	"Where...am I? Is this a hospital...?",
	"Nurse: Kris, you woke up!! Quick, call the doctor!",
	"Was I dreaming this whole time...Was any of that real?",
	"But I realized how precious my life was and how much I was missing out",
	"Maybe I was given a second chance, a chance to change my life for the better",
	"And this time, I wont waste it away."

};
//-------------------------------------------iDraw------------------------------------//
void iDraw()
{
	iClear();
	playMenuMusic();
	if (m == -1){

		iShowBMP(0, 0, "images//Start_page_resized.bmp");

		iText(530, 170, "Click here to continue", GLUT_BITMAP_9_BY_15);
		iLine(530, 160, 732, 160);
	}
	else if (m == 0){
		mainMenu();
	}
	else if (m == 5){///for name input
		iShowBMP(0, 0, "name.bmp");

		iSetColor(255, 255, 255);
		iFilledRectangle(340, 370, 500, 80);
		iSetColor(0, 0, 0);
		iFilledRectangle(350, 380, 475, 65);
		iSetColor(255, 255, 255);
		iText(360, 407, playerName, GLUT_BITMAP_TIMES_ROMAN_24);


	}
	else if (m == 10) {
		drawDialogueBox();
	}
	else if (m == 1){
		iFilledRectangle(0, 0, 1200, 800);
		iSetColor(255, 255, 255);

		if (level4){
			level4Draw();
			if (score == 7 && !savedScore){
				saveScore(playerName, timeTaken);
				savedScore = true;
				loadScore();
			}
		}
		else if (level3){
			level3Draw();
		}
		else if (level2){
			Level2Draw();
			playerMovement();
		}
		else {
			Level1Draw();
		}

		if (scoreShow){
			
			iSetColor(0, 0, 0);
			iFilledRectangle(0, 0, 1200, 800);
			iShowBMP(330, 0, "score_bg.bmp");
			iShowBMP(24, 730, "go_back.bmp");
			iSetColor(255, 255, 255);


			for (int i = 0; i < totalEntries; i++) {
				char line[100];
				sprintf(line, "%d. %s", i + 1, nameSorted[i]);
				iText(380, 687 - i * 30, line, GLUT_BITMAP_TIMES_ROMAN_24);
				char scoreLine[20];
				sprintf(scoreLine, "%d", scoreSorted[i]);
				iText(613, 687 - i * 30, scoreLine, GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		if (showEnd){

			if (fadeValue > 0) {
				fadeValue -= 3;
				if (fadeValue < 0) fadeValue = 0;

				iSetColor(fadeValue, fadeValue, fadeValue);
				iFilledRectangle(0, 0, 1280, 800);
			}
			else{
				iSetColor(0, 0, 0);
				iFilledRectangle(0, 0, 1200, 800);

				iShowBMP2(50, 130, "hospital.bmp", 255);
				iShowBMP(200, 30, "Image\\dialoguebox.bmp");
				iShowBMP2(230, 60, expressionImages[getExpressionIndexfinal(currentFinalLine)], 0);

				iSetColor(255, 255, 255);
				iText(330, 105, finalLines[currentFinalLine], GLUT_BITMAP_HELVETICA_18);

				iFilledRectangle(1020, 40, 100, 40);
				iSetColor(0, 0, 0);
				iText(1046, 55, "Next >", GLUT_BITMAP_HELVETICA_18);
			}


		}




		if (game_end){
			iShowBMP(0, 0, "game_end.bmp");
		}

	}

	if (m == 2){ menuOption(); }
	if (m == 3){ menuBackstory(); }
	if (m == 4){ menuCredit(); }


}

void resetGame() {
	j = 0;
	if (!level2 && !level3 && !level4){
		player_x = player_start_x;
		player_y = player_start_y;
		player_health = 5;
		rock_health = 5;
		countAttack = 0;
		playerDead = false;
		pickSword = false;
		game_over = false;
		rock_x = rock_start_x;
		rock_y = rock_start_y;
		rock_defeated = false;

		j_death = 0;
		j_rock = 0;
		j_hit = 0;
	}

}
void resetLevel2() {
	player_x = player_start_x;
	player_y = player_start_y;
	player_health = 5;
	level2Time = 110;
	level2Failed = false;
	showLevel2FailScreen = false;
	level2Won = false;
	collectedMirrors = 0;

	for (int i = 0; i < mirrorCount; i++) mirrors[i].picked = false;
	for (int i = 0; i < boxCount; i++) boxs[i].picked = false;
}


void resetLevel3() {
	Level3Wave = 0;
	waveTextActive = false;
	waveTextTimer = 0;
	finalWaveDelay = 0;
	waveDelayTimer = 0;

	playerHP = playerMaxHP = 9;
	playerHealedOnce = false;
	regenTimer = 0;
	regenCooldown = 0;
	playerDead = false;
	playerAttacking = false;
	playerAttackFrame = playerAttackDelay = 0;
	playerDeathFrame = playerDeathDelay = 0;

	level3Win = false;
	level3Fail = false;

	groundSpawnIndex = 0;
	elevatedSpawnIndex = 0;
	for (int i = 0; i < 3; i++) {
		groundMinions[i] = { 1200 + i * 100, 190, 3, false, false };
		elevatedMinions[i] = { 1200 + i * 100, 490, 3, false, false };
		minionAttackFrame[i] = minionAttackDelay[i] = 0;
		minionDeathFrame[i] = minionDeathDelay[i] = 0;
		minionWalkFrame[i] = minionWalkDelay[i] = 0;
		attackCooldown[i] = 0;
	}

	bossSpawned = false;
	bossDead = false;
	bossAttacking = false;
	bossHP = bossMaxHP = 7;
	bossX = 1100;
	bossY = 700;
	bossDir = 1;
	bossAttackFrame = bossAttackDelay = 0;
	bossDeathFrame = bossDeathDelay = 0;
	bossAttackCooldown = 0;

	devil_grow = true;
	Frame = 0;


}

void resetlevel4(){
	player_x = 60;
	player_y = 337;
	timer_w = 220;
	score = 0;
	Box_1* groups[] = { box_0, box_1, box_2, box_3, box_4, box_5, box_6 };
	for (int g = 0; g < 7; g++) {
		for (int i = 0; i < Count; i++) {
			groups[g][i].picked = false;

		}

	}
	for (int i = 0; i < count_1; i++) {
		Box *c = &crystal[i];
		c->picked = false;   // remove only THIS one


	}
}




/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	printf("MX=%d  MY=%d\n", mx, my);
	if (m == 0) {
		hoverStart = (mx >= 492 && mx <= 686 && my >= 440 && my <= 502);
		hoverOptions = (mx >= 492 && mx <= 690 && my >= 354 && my <= 420);
		hoverStory = (mx >= 492 && mx <= 689 && my >= 268 && my <= 332);
		hoverCredits = (mx >= 492 && mx <= 690 && my >= 184 && my <= 250);
		hoverExit = (mx >= 492 && mx <= 688 && my >= 105 && my <= 163);
	}
	if (m == 1 && playerDead){
		hoverYes = (mx >= 360 && mx <= 523 && my >= 306 && my <= 340);
		hoverQuit = (mx >= 703 && mx <= 867 && my >= 306 && my <= 340);
	}
}



void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


		if (m == -1){
			m = 0;
		}
		else if (m == 0 && mx >= 492 && mx <= 686 && my >= 440 && my <= 502) {
			m = 5;
			enterName = true;
			//m = 10;
			//resetBackstory();
			PlaySound("click_sound.wav", NULL, SND_ASYNC);
		}
		else if (m == 10 && mx >= 980 && mx <= 1100 && my >= 40 && my <= 80) {
			handleDialogueClick(m);
		}
		if (m == 1){

			if (level1 && mx >= 1043 && mx <= 1080 && my <= 781 && my >= 746){

				PlaySound(NULL, 0, 0);
			}
			if (level1 && mx >= 973 && mx <= 1015 && my <= 781 && my >= 746){

				PlaySound("level1bgm.wav", NULL, SND_ASYNC | SND_LOOP);
			}
			if (game_over && mx >= 360 && mx <= 523 && my >= 306 && my <= 340){
				resetGame();
				level1 = true;
				currentLevel = 1;
				level2 = level3 = level4 = false;
			}
			if (game_over && mx >= 703 && mx <= 867 && my >= 306 && my <= 340){ exit(0); }
			if (rock_defeated && mx >= 360 && mx <= 523 && my >= 293 && my <= 334){
				level2 = true;
				currentLevel = 2;
				player_x = 123;
				player_y = 189;
				level1 = level3 = level4 = false;
			}
			if (rock_defeated && mx >= 703 && mx <= 867 && my >= 300 && my <= 340){ exit(0); }


			if (level2 && mx >= 1030 && mx <= 1060 && my >= 734 && my <= 764){
				level2SoundOn = !level2SoundOn;
				if (!level2SoundOn){
					PlaySound(NULL, 0, 0);
					level2MusicState = 0;
				}
				else{
					PlaySound("level2bgm.wav", NULL, SND_ASYNC | SND_LOOP);
					level2MusicState = 1;
				}
			}
			if (mx >= 42 && mx <= 84 && my >= 40 && my <= 76){
				showLevel2Info = !showLevel2Info;
				level2InfoActive = false;
			}
			if (level2 && showLevel2FailScreen) {
				if (mx >= 360 && mx <= 523 && my >= 306 && my <= 340) {
					resetLevel2();

					PlaySound("level2bgm.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				if (mx >= 703 && mx <= 867 && my >= 306 && my <= 340) {
					exit(0);
				}
			}
			if (level2 && level2Won){
				if (mx >= 360 && mx <= 523 && my >= 293 && my <= 334){
					level3 = true;
					currentLevel = 3;
					level2 = level1 = level4 = false;
				}
				else if (mx >= 703 && mx <= 867 && my >= 300 && my <= 340){ exit(0); }
			}
			if (level3 && mx >= 1030 && mx <= 1060 && my >= 734 && my <= 764){
				level3SoundOn = !level3SoundOn;
				if (!level3SoundOn){
					PlaySound(NULL, 0, 0);
					level3MusicState = 0;
				}
				else{
					PlaySound("level3bgm.wav", NULL, SND_ASYNC | SND_LOOP);
					level3MusicState = 1;
				}
			}
			if (level3 && level3Win) {
				if (mx >= 360 && mx <= 523 && my >= 306 && my <= 340) {
					level4 = true;
					player_x = 100;
					player_y = 320;
					currentLevel = 4;
					level2 = level3 = level1 = false;
					PlaySound("level4_bgm.wav", NULL, SND_ASYNC | SND_LOOP);
				}

				if (mx >= 703 && mx <= 867 && my >= 306 && my <= 340) {
					exit(0);
				}
			}
			if (level3 && level3Fail) {
				if (mx >= 360 && mx <= 520 && my >= 306 && my <= 340) {
					resetLevel3();


					PlaySound("level3bgm.wav", NULL, SND_ASYNC | SND_LOOP);

				}

				if (mx >= 600 && mx <= 720 && my >= 150 && my <= 190) {
					exit(0);
				}
			}

			if (level4 && game_over4){
				if (mx >= 360 && mx <= 523 && my >= 306 && my <= 340){ resetlevel4(); }
				if (mx >= 703 && mx <= 867 && my >= 300 && my <= 340){ exit(0); }
			}
			if (level4 && score == 7){
				if (mx >= 383 && mx <= 778 && my >= 418 && my <= 450){
					
					scoreShow = true;
					
				}
				if (mx >= 510 && mx <= 650 && my >= 293 && my <= 340){
					showEnd = true;
					

					PlaySound("final.wav", NULL, SND_ASYNC | SND_LOOP);


				}
			}
			if (scoreShow){
				if (mx >= 25 && mx <= 114 && my >= 730 && my <= 778){
					scoreShow = false;
				}

			}
			if (showEnd){
				if (mx >= 980 && mx <= 1100 && my >= 40 && my <= 80) {
					currentFinalLine++;
					if (currentFinalLine >= 6){
						game_end = true;
					}
				}
			}
			if (game_end){
				if (mx >= 534 && mx <= 649 && my >= 162 && my <= 210){
					exit(0);
				}
			}


		}
		if (m == 0){

			if (mx >= 492 && mx <= 686 && my >= 440 && my <= 502){
				m = 1;
				PlaySound("click_sound.wav", NULL, SND_ASYNC);
				if (soundOn){
					PlaySound("level1bgm.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}


			if (mx >= 492 && mx <= 690 && my >= 354 && my <= 420){
				m = 2;
				PlaySound("click_sound.wav", NULL, SND_ASYNC);
				if (soundOn){
					PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}
			if (mx >= 492 && mx <= 689 && my >= 268 && my <= 332){
				m = 3;
				PlaySound("click_sound.wav", NULL, SND_ASYNC);
				if (soundOn){
					PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}
			if (mx >= 492 && mx <= 690 && my >= 184 && my <= 250){
				m = 4;
				PlaySound("click_sound.wav", NULL, SND_ASYNC);
				if (soundOn){
					PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}
			if (mx >= 492 && mx <= 688 && my >= 105 && my <= 163){

				PlaySound("click_sound.wav", NULL, SND_ASYNC);
				exit(0);
			}
		}

		if ((m == 1 || m == 2 || m == 3 || m == 4) && mx >= 1110 && mx <= 1154 && my >= 29 && my <= 89) {
			m = 0;
		}
		if (m == 2 && mx >= 889 && mx <= 932 && my >= 501 && my <= 515){
			soundOn = !soundOn;

			if (!soundOn){
				PlaySound(NULL, 0, 0);
				musicState = 0;
			}
			else{
				playMenuMusic();
			}
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (showIntro) {

			if (mx >= 550 && mx <= 550 + 80 && my >= 335 && my <= 335 + 30) {
				showIntro = false;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/



void show_attack(){ //player sword attack animation
	if (attack >= 1){
		j_hit++;
		if (j_hit >= 6){
			attack = 0;
			j_hit = 0;
		}
	}
}
bool isCollidingWithMinion(int px, int py, Minion &m) {
	int playerSize = 50;
	int minionSize = 50;

	if (!m.alive) return false;

	if (px + playerSize > m.x && px < m.x + minionSize &&
		py + playerSize > m.y && py < m.y + minionSize) {
		return true;
	}
	return false;
}
void iKeyboard(unsigned char key)
{
	if (enterName) {
		if (key == '\r') {
			enterName = false;
			m = 10;

		}
		else if (key == '\b') {
			if (nameLen > 0) {
				nameLen--;
				playerName[nameLen] = '\0';
			}
		}
		else {
			if (nameLen < 49) {
				playerName[nameLen] = key;
				nameLen++;
				playerName[nameLen] = '\0';
			}
		}
	}

	int newY = player_y;
	int newX = player_x;
	if (key == '\s')
	{

	}
	if (key == ' ')
	{
		if (attack == 0 && !level4){
			attack = 1;
			j_hit = 0;
			if (distance <= 60 && pickSword &&!game_over){

				rock_health--;
				if (rock_health <= 0){ rock_defeated = true; }

			}

		}
		if (level3  && !level4 && !level2) {
			attack = 1;

			if (Level3Wave == 1) {

				for (int i = 0; i < 3; i++) {
					if (isCollidingWithMinion(player_x, player_y, groundMinions[i])) {

						groundMinions[i].hp--;
						if (groundMinions[i].hp <= 0) {
							groundMinions[i].alive = false;
						}
					}
				}
			}
			else if (Level3Wave == 2) {

				for (int i = 0; i < 3; i++) {
					if (isCollidingWithMinion(player_x, player_y, elevatedMinions[i])) {
						elevatedMinions[i].hp--;
						if (elevatedMinions[i].hp <= 0) {
							elevatedMinions[i].alive = false;
						}
					}
				}
			}
		}

		if (level4 && equipSword) {
			attack = 1;
			for (int i = 0; i < numMonsters; i++) {
				if (monsters[i].active && !monsters[i].defeated) {
					monsters[i].defeated = true;
					printf("Monster %d defeated!\n", i);
					break; // only defeat one
				}
			}
		}



	}
	if (textSword == true && key == 'p')
	{
		pickSword = true;
	}
	if (key == '\r')
	{


	}
	if (key == 'b' || key == 'B') {
		if (level2 && !level4 && !level3){
			for (int i = 0; i < boxCount; i++) {
				objectBox *b = &boxs[i];
				if (b->showText && !b->picked) {
					b->picked = true;
					printf("Box removed %d\n", i);
				}
			}
		}
	}

	if (key == 'm' || key == 'M') {
		for (int i = 0; i < mirrorCount; i++) {
			Mirror *m = &mirrors[i];
			if (m->showText && !m->picked) {
				m->picked = true;
				collectedMirrors++;
				printf("Picked mirror %d\n", i);

				if (collectedMirrors == mirrorCount && !level2Failed){
					level2Won = true;
				}
			}
		}
	}if (key == '\b'){



		if (level4){
			Box_1* groups[] = { box_0, box_1, box_2, box_3, box_4, box_5, box_6 };

			for (int g = 0; g < 7; g++) {
				for (int i = 0; i < Count; i++) {
					if (!groups[g][i].picked) {
						if (player_x + 32 > groups[g][i].x && player_x < groups[g][i].x + groups[g][i].w &&
							player_y + 32 > groups[g][i].y && player_y < groups[g][i].y + groups[g][i].h) {

							groups[g][i].picked = true;
							if (groups[g][i].correct_box) {

								switch (g) {
								case 0: dialogueVisible_1 = false; break;
								case 1: dialogueVisible_2 = false; break;
								case 2: dialogueVisible_3 = false; break;
								case 3: dialogueVisible_4 = false; break;
								case 4: dialogueVisible_5 = false; break;
								case 5: dialogueVisible_6 = false; break;
								case 6: dialogueVisible_7 = false; break;
								}

							}
							if (!groups[g][i].correct_box){
								timer_w = timer_w - 5;
								timerFlash = true;
								flashCounter = flashDuration;
							}
							printf("Removed box_%d[%d]\n", g, i);
							return;
						}
					}
				}
			}
		}
	}


	if (key == 'e' || key == 'E'){
		if (level4 && m == 1)
			equipSword = !equipSword;

	}
	if (key == '\r'){

		if (level4){
			for (int i = 0; i < count_1; i++) {
				Box *c = &crystal[i];
				if (!c->picked) {

					if (player_x + 32 > c->x && player_x < c->x + c->w &&
						player_y + 32 > c->y && player_y < c->y + c->h) {

						c->picked = true;   // remove only THIS one
						score++;
						printf("Removed crystal %d\n", i);
						break;
					}
				}
			}
		}
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (!playerDead){

		int newX = player_x;
		int newY = player_y;

		if (key == GLUT_KEY_RIGHT)
		{

			newX += player_speed;
			if (!isColliding(newX, newY) && newX <= 1200 - 32) {
				player_x = newX;
			}
			right = true;
			front = left = back = Player_Stand = false;
			standCounter = 0;
			isMoving = true;


			if (animationDelay >= frame){
				j++;
				if (j >= 3) j = 0;
				animationDelay = 0;
			}
			else{
				animationDelay++;
			}
		}

		if (key == GLUT_KEY_LEFT)
		{
			newX -= player_speed;
			if (!isColliding(newX, newY) && newX >= 0) {
				player_x = newX;
			}
			left = true;
			front = right = back = Player_Stand = false;
			standCounter = 0;
			isMoving = true;

			if (animationDelay >= frame){
				j++;
				if (j >= 3) j = 0;
				animationDelay = 0;
			}
			else{
				animationDelay++;
			}
		}

		if (key == GLUT_KEY_UP)
		{
			newY += player_speed;
			if (!isColliding(newX, newY) && newY <= 800 - 32) {
				player_y = newY;
			}
			back = true;
			front = left = right = Player_Stand = false;
			standCounter = 0;
			isMoving = true;


			if (animationDelay >= frame){
				j++;
				if (j >= 3) j = 0;
				animationDelay = 0;
			}
			else{
				animationDelay++;
			}
		}

		if (key == GLUT_KEY_DOWN)
		{
			newY -= player_speed;
			if (!isColliding(newX, newY) && newY > 0) {
				player_y = newY;
			}
			front = true;
			right = left = back = Player_Stand = false;
			standCounter = 0;
			isMoving = true;

			if (animationDelay >= frame){
				j++;
				if (j >= 3) j = 0;
				animationDelay = 0;
			}
			else{
				animationDelay++;
			}
		}


	}

}


void level2Countdown() {
	if (level2 && !level2Failed && !level2Won) {
		level2Time--;
		if (level2Time <= 0) {
			level2Time = 0;
			if (collectedMirrors < mirrorCount){
				level2Failed = true;
				showLevel2FailScreen = true;
			}
		}
	}
}
int d;
int cr;
void masterTimer() {
	masterTick++;

	if (masterTick % 10 == 0 && !showEnd) updateBackstory();
	//if (masterTick % 10 == 0) updateLevel2Dialogue();
	if (masterTick % 80 == 0) toggleShine();
	if (masterTick % 40 == 0) level2Countdown();

}
int main()
{
	///srand((unsigned)time(NULL));s

	iSetTimer(1500, toggle);
	rockMove();

	iSetTimer(30, rockMove);
	iSetTimer(70, show_attack);
	iSetTimer(1, masterTimer);
	iSetTimer(800, decreaseTimer);
	iSetTimer(100, skel);
	iSetTimer(100, toggleShine_Crystal);

	iInitialize(1200, 800, "Project Title");
	Ladder = iLoadImage("Ladder_1.png");
	d = iLoadImage("Image/dialoguebox.bmp");
	cr = iLoadImage("Image2/Green/green_crystal_0000.png");
	if (soundOn){
		PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);
	}
	if (level4 && !level2 && !level3 && m != 10){
		PlaySound("level4_bgm.wav", NULL, SND_ASYNC | SND_LOOP);

	}

	///updated see the documentations
	iStart();
	return 0;
}