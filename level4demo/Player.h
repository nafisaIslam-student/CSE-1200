#ifndef PLAYER_H
#define PLAYER_H

extern int player_x;
extern int player_y;
extern int j;
extern bool front;
extern bool back;
extern bool left;
extern bool right;
extern bool stand;
extern bool frontSword;
extern int standCounter;
extern char idle[20];
extern bool game_over;
extern bool playerDead;
bool Player_Stand = true;
int player_walking = 0;//j for me
int standCounter = 0;
bool start = false;
bool isMoving = false;
int d_animationDelay = 0;
extern int d_frame = 10;

int j_hit = 0;
int j_death = 0;



char playerStand[8][30] = {"idle.bmp"};

char moveFront[3][20] = {
	"Image\\front1.bmp",
	"Image\\front2.bmp",
	"Image\\front3.bmp"
};
char moveLeft[3][20] = {
	"Image\\left1.bmp",
	"Image\\left2.bmp",
	"Image\\left3.bmp"
	
};
char moveRight[3][20] = {
	"Image\\r81.bmp",
	"Image\\r82.bmp",
	"Image\\r83.bmp"
	
};
char moveBack[3][25] = {
	"Image\\back_walk1.bmp",
	"Image\\back_walk2.bmp",
	"Image\\back_walk3.bmp"
};
char runBack[8][20] = {
	"Image\\back1.bmp",
	"Image\\back2.bmp",
	"Image\\back3.bmp",
	"Image\\back4.bmp",
	"Image\\back5.bmp",
	"Image\\back6.bmp",
	"Image\\back7.bmp",
	"Image\\back8.bmp"
	
};
char runFront[6][20] = {

	"Image\\run1.bmp",
	"Image\\run2.bmp",
	"Image\\run3.bmp",
	"Image\\run4.bmp",
	"Image\\run5.bmp",
	"Image\\run6.bmp"

};

char runLeft[8][20] = {
	"Image2\\left1.bmp",
	"Image2\\left2.bmp",
	"Image2\\left3.bmp",
	"Image2\\left4.bmp",
	"Image2\\left5.bmp",
	"Image2\\left6.bmp",
	"Image2\\left7.bmp",
	"Image2\\left8.bmp"
};
char runRight[8][20] = {
	"Image2\\r81.bmp",
	"Image2\\r82.bmp",
	"Image2\\r83.bmp",
	"Image2\\r84.bmp",
	"Image2\\r85.bmp",
	"Image2\\r86.bmp",
	"Image2\\r87.bmp",
	"Image2\\r88.bmp"
	
};

char hitFront[6][20] = {
	"Image\\sword1.bmp",
	"Image\\sword2.bmp",
	"Image\\sword3.bmp",
	"Image\\sword4.bmp",
	"Image\\sword5.bmp",
	"Image\\sword6.bmp"
};
char swordLeft[3][20] = {
	"Image\\WS_L_1.bmp",
	"Image\\WS_L_2.bmp",
	"Image\\WS_L_3.bmp"
};
char swordRight[3][20] = {
	"Image\\WS_R_1.bmp",
	"Image\\WS_R_2.bmp",
	"Image\\WS_R_3.bmp"
};
char swordFront[3][20] = {
	"Image\\WS_F_1.bmp",
	"Image\\WS_F_2.bmp",
	"Image\\WS_F_3.bmp"
};
char swordBack[3][20] = {
	"Image\\WS_B_1.bmp",
	"Image\\WS_B_2.bmp",
	"Image\\WS_B_3.bmp"
};
char hitLeft[6][15] = {
	"Image\\L_1.bmp",
	"Image\\L_2.bmp",
	"Image\\L_3.bmp",
	"Image\\L_4.bmp",
	"Image\\L_5.bmp",
	"Image\\L_6.bmp"
};
char hitRight[6][15] = {
	"Image\\R_1.bmp",
	"Image\\R_2.bmp",
	"Image\\R_3.bmp",
	"Image\\R_4.bmp",
	"Image\\R_5.bmp",
	"Image\\R_6.bmp"
	
};
char deathLeft[4][20] = {
	"Image\\D_L_1.bmp",
	"Image\\D_L_2.bmp",
	"Image\\D_L_3.bmp",
	"Image\\D_L_4.bmp"
	
};
char deathRight[4][20] = {
	"Image\\D_R_1.bmp",
	"Image\\D_R_2.bmp",
	"Image\\D_R_3.bmp",
	"Image\\D_R_4.bmp"
	
};
char deathFront[4][20] = {
	"Image\\D_F_1.bmp",
	"Image\\D_F_2.bmp",
	"Image\\D_F_3.bmp",
	"Image\\D_F_4.bmp"
	
};

void playerMovement() {
	if (!Player_Stand){
		if (front) 
			iShowBMP2(player_x, player_y, moveFront[j], 0);

		
		else if (back) 
			iShowBMP2(player_x, player_y, moveBack[j], 0);

		
		else if (left) 
			iShowBMP2(player_x, player_y, moveLeft[j], 0);

		
		else if (right) 
			iShowBMP2(player_x, player_y, moveRight[j], 0);

		
		standCounter++;
		if (standCounter >= 30)
		{
			standCounter = 0;
			player_walking = 0;
			Player_Stand = true;
		}
	}
	
		else { iShowBMP2(player_x, player_y, playerStand[0], 0); }
	}



void playerMoveSword(){
	if (front){
		iShowBMP2(player_x,player_y,swordFront[j],0);
	}
	else if (back) {
		iShowBMP2(player_x, player_y, swordBack[j], 0);

	}
	else if (left) {
		iShowBMP2(player_x, player_y, swordLeft[j], 0);

	}
	else if (right) {
		iShowBMP2(player_x, player_y, swordRight[j], 0);

	}
}
void playerHitSword(){
	if (front){
		iShowBMP2(player_x, player_y, hitFront[j_hit], 0);
	}
	else if (back) {
		iShowBMP2(player_x, player_y, hitFront[j_hit], 0);

	}
	else if (left) {
		iShowBMP2(player_x, player_y, hitLeft[j_hit], 0);

	}
	else if (right) {
		iShowBMP2(player_x, player_y, hitRight[j_hit], 0);

	}
}
void playerDeath(){
	if (front){
		iShowBMP2(player_x, player_y, deathFront[j_death], 0);
		
	}
	else if (back) {
		iShowBMP2(player_x, player_y, deathFront[j_death], 0);
		

	}
	else if (left) {
		iShowBMP2(player_x, player_y, deathLeft[j_death], 0);
		
	}
	else if (right) {
		iShowBMP2(player_x, player_y, deathRight[j_death], 0);
		
	}
}
void playerDeadAnimation(){
	if (d_animationDelay >= d_frame) {
		j_death++;
		d_animationDelay = 0;
	}
	else d_animationDelay++;

	if (j_death < 4) {
		playerDeath();
	}
	else {

		playerDead = false;
		game_over = true;
	}
}
#endif