extern int m;
extern int soundOn;

int hoverStart = 0;
int hoverOptions = 0;
int hoverStory = 0;
int hoverCredits = 0;
int hoverExit = 0;

int hoverYes = 0;
int hoverQuit = 0;
void mainMenu(){
	if (m == 0){
		iShowBMP(0, 0, "images//main_menu_resized.bmp");
		iShowBMP2(470, 530, "images//new_menu_bg.bmp", 0);
		if (hoverStart){
			iShowBMP2(483, 430, "images//start_hover.bmp", 0);
		}
		else{
			iShowBMP2(483, 430, "images//start_button.bmp", 0);
		}
		if (hoverOptions){
			iShowBMP2(483, 347, "images//options_hover.bmp", 0);
		}
		else{
			iShowBMP2(483, 347, "images//options_button.bmp", 0);
		}
		if (hoverStory){
			iShowBMP2(483, 262, "images//back_story_hover.bmp", 0);
		}
		else{
			iShowBMP2(483, 262, "images//back_story_button.bmp", 0);
		}
		if (hoverCredits){
			iShowBMP2(483, 176, "images//credits_hover.bmp", 0);
		}
		else{
			iShowBMP2(483, 176, "images//credits_button.bmp", 0);

		}
		if (hoverExit){
			iShowBMP2(483, 90, "images//quit_hover.bmp", 0);
		}
		else{
			iShowBMP2(483, 90, "images//quit_button.bmp", 0);
		}

	}
	/*if (m == 1){
		if (hoverYes){
			iShowBMP(523, 306, "Image//hover_yes.bmp");
		}
		if (hoverQuit){ iShowBMP(703, 306, "Image//hover_quit.bmp"); }
	}*/
}
void menuOption(){
	iClear();
	iShowBMP(0, 0, "images//bg_resized.bmp");
	iShowBMP2(400, 600, "images//options.bmp", 0);
	iShowBMP(150, 490, "images//settings.bmp");
	iText(200, 500, "Controls :", GLUT_BITMAP_TIMES_ROMAN_24);
	iLine(200, 490, 285, 490);
	iShowBMP(170, 420, "images//up.bmp");
	iText(235, 438, "Press to move up", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170, 342, "images//down.bmp");
	iText(235, 362, "Press to move down", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170, 270, "images//left.bmp");
	iText(235, 284, "Press to move left", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170, 190, "images//right.bmp");
	iText(235, 207, "Press to move right", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(170, 127, "images//space_bar.bmp");
	iText(235, 132, " Press for special attack", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(750, 490, "images//music_note.bmp");
	iText(800, 500, "Sound :", GLUT_BITMAP_TIMES_ROMAN_24);
	iLine(800, 490, 868, 490);

	if (soundOn){
		iShowBMP2(885, 495, "images//on_button.bmp", 0);
	}
	else{
		iShowBMP2(885, 495, "images//off_button.bmp", 0);
	}
	iShowBMP(1110, 25, "images//new_back.bmp");
}

void menuBackstory() {

	iShowBMP(0, 0, "images//bg_resized.bmp");
	iShowBMP2(400, 600, "images//back_story.bmp", 0);
	iSetColor(255, 255, 255);
	int x = 250;
	int y = 500;

	iText(x, y, "Kris lived a life of silence... and sadness.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 30, "No family. No friends. Only shadows and routine.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 60, "Then one day — everything faded to black.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 90, "He had been in a coma... for three long years.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 120, "Inside his mind, he finds himself on a bus...", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 150, "...traveling to a strange, dark forest.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 180, "A silent, shadowy guide leads the way.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 210, "Each step forward brings him face to face...", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 240, "...with the fear, regret, and trauma of his past.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 270, "Only by confronting these inner demons...", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 300, "...can Kris earn a golden ticket...", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x, y - 330, "...and take the return bus home — back to life.", GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(1110, 25, "images//new_back.bmp");
}


void menuCredit(){
	iClear();
	iShowBMP(0, 0, "images//bg_resized.bmp");
	iShowBMP2(400, 600, "images//credits.bmp", 0);
	iShowBMP(90, 120, "images//1.bmp");
	iShowBMP(635, 120, "images//3.bmp");
	iShowBMP(370, 350, "images//2.bmp");
	iShowBMP(1110, 25, "images//new_back.bmp");
}

	


	
