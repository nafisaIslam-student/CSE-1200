#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <string.h>
bool game_end = false;
int currentLine = 0;
int charIndex = 0;
bool typewriterOn = true;
char displayLine[300] = "";

int totalLines = 6;

char* backstoryLines[] = {
	"My name is Kris... silence and loneliness defined my life.",
	"One night, darkness took me. I fell into a long coma.",
	"Now I wander a forest... unreal, yet alive in every shadow.",
	"A silent figure follows... familiar, but unknown.",
	"A sword calls to me, its weight heavy in my soul.",
	"Something inhuman watches. I must fight... and somehow wake up."
};



char* expressionImages[] = {
	"Image\\sad.bmp",
	"Image\\normal.bmp",
	"Image\\happy.bmp",
	"Image\\talk.bmp",
	"Image\\black.bmp"
};

int getExpressionIndex(int line) {
	if (line == 0) return 0;
	if (line == 1) return 0;
	if (line == 2) return 1;
	if (line == 3) return 3;
	if (line == 4) return 1;
	if (line == 5) return 0;
	return 1;
}
int getExpressionIndexfinal(int line) {
	if (line == 0) return 0;
	if (line == 1) return 4;
	if (line == 2) return 0;
	if (line == 3) return 1;
	if (line == 4) return 2;
	if (line == 5) return 2;
	return 1;
}

void updateBackstory() {
	if (typewriterOn && currentLine < totalLines) {
		const char* line = backstoryLines[currentLine];
		if (line[charIndex] != '\0') {
			displayLine[charIndex] = line[charIndex];
			charIndex++;
			displayLine[charIndex] = '\0';
		}
	}
}

/*void updateFinal() {
	if (typewriterOn && currentLine < totalLines) {
		const char* line = finalLines[currentLine];
		if (line[charIndex] != '\0') {
			displayLine[charIndex] = line[charIndex];
			charIndex++;
			displayLine[charIndex] = '\0';
		}
	}
}*/


void resetBackstory() {
	currentLine = 0;
	charIndex = 0;
	displayLine[0] = '\0';
	typewriterOn = true;
}


void drawDialogueBox() {
	iShowBMP(0, 0, "dark2.bmp");

	iShowBMP(200, 30, "Image\\dialoguebox.bmp");
	iShowBMP2(230, 60, expressionImages[getExpressionIndex(currentLine)], 0);

	iSetColor(255, 255, 255);
	iText(330, 105, displayLine, GLUT_BITMAP_HELVETICA_18);

	iFilledRectangle(1020, 40, 100, 40);
	iSetColor(0, 0, 0);
	iText(1046, 55, "Next >", GLUT_BITMAP_HELVETICA_18);
}

void handleDialogueClick(int& m) {
	const char* line = backstoryLines[currentLine];
	int len = strlen(line);

	if (typewriterOn && charIndex < len) {
		for (int i = 0; i < len; i++) {
			displayLine[i] = line[i];
		}
		displayLine[len] = '\0';
		charIndex = len;
		typewriterOn = false;
	}
	else {
		currentLine++;
		if (currentLine < totalLines) {
			charIndex = 0;
			displayLine[0] = '\0';
			typewriterOn = true;
		}
		else {
			m = 1;
			if (soundOn){
				PlaySound("level1bgm.wav", NULL, SND_ASYNC | SND_LOOP);
			}
		}
	}
}


#endif