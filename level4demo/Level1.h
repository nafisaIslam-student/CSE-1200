#include "Struct.h"
#include "Player.h"
int rock_x = 1200;
int rock_y = 420;
int j_rock=0;

int r_animationDelay=0; ///////for rock
int r_speed=4;
enum Direction { FRONT, BACK, LEFT, RIGHT };
Direction rockDirection = LEFT;

enum EnemyState { IDLE, CHASE, ATTACK };
EnemyState rockState = IDLE;

extern int d_animationDelay;
extern int d_frame;

bool pickSword=false;
bool textSword = false;
bool nearSword = false;

extern bool front;
extern bool back;
extern bool left;
extern bool right;
extern int attack;
extern float distance;
extern int player_x;
extern int player_y;

extern int countAttack;
extern int countHit;
extern int player_health;
extern bool playerDead;
extern int rock_health;
extern bool rock_defeated;
extern bool game_over;
extern int j_death;
extern int d_animationDelay;
int skeleton_move = 0;

char rockLeft[10][27] = {
	"Image\\rock_left_walk1.bmp",
	"Image\\rock_left_walk2.bmp",
	"Image\\rock_left_walk3.bmp",
	"Image\\rock_left_walk4.bmp",
	"Image\\rock_left_walk5.bmp",
	"Image\\rock_left_walk6.bmp",
	"Image\\rock_left_walk7.bmp",
	"Image\\rock_left_walk8.bmp",
	"Image\\rock_left_walk9.bmp",
	"Image\\rock_left_walk10.bmp"
};
char rockRight[10][30] = {
	"Image\\00_rock_right_walk.bmp",
	"Image\\01_rock_right_walk.bmp",
	"Image\\02_rock_right_walk.bmp",
	"Image\\03_rock_right_walk.bmp",
	"Image\\04_rock_right_walk.bmp",
	"Image\\05_rock_right_walk.bmp",
	"Image\\06_rock_right_walk.bmp",
	"Image\\07_rock_right_walk.bmp",
	"Image\\08_rock_right_walk.bmp",
	"Image\\09_rock_right_walk.bmp"
};
char rockBack[10][30] = {
	"Image\\00_rock_back_walk.bmp",
	"Image\\01_rock_back_walk.bmp",
	"Image\\02_rock_back_walk.bmp",
	"Image\\03_rock_back_walk.bmp",
	"Image\\04_rock_back_walk.bmp",
	"Image\\05_rock_back_walk.bmp",
	"Image\\06_rock_back_walk.bmp",
	"Image\\07_rock_back_walk.bmp",
	"Image\\08_rock_back_walk.bmp",
	"Image\\09_rock_back_walk.bmp"
};
char rockFront[10][30] = {
	"Image\\00_rock_front_walk.bmp",
	"Image\\01_rock_front_walk.bmp",
	"Image\\02_rock_front_walk.bmp",
	"Image\\03_rock_front_walk.bmp",
	"Image\\04_rock_front_walk.bmp",
	"Image\\05_rock_front_walk.bmp",
	"Image\\06_rock_front_walk.bmp",
	"Image\\07_rock_front_walk.bmp",
	"Image\\08_rock_front_walk.bmp",
	"Image\\09_rock_front_walk.bmp"
};
char attackLeft[10][29] = {
	"Image\\rock_left_attack1.bmp",
	"Image\\rock_left_attack2.bmp",
	"Image\\rock_left_attack3.bmp",
	"Image\\rock_left_attack4.bmp",
	"Image\\rock_left_attack5.bmp",
	"Image\\rock_left_attack6.bmp",
	"Image\\rock_left_attack7.bmp",
	"Image\\rock_left_attack8.bmp",
	"Image\\rock_left_attack9.bmp",
	"Image\\rock_left_attack10.bmp"
};
char attackRight[10][35] = {
	"Image\\00_rock_right_attack.bmp",
	"Image\\01_rock_right_attack.bmp",
	"Image\\02_rock_right_attack.bmp",
	"Image\\03_rock_right_attack.bmp",
	"Image\\04_rock_right_attack.bmp",
	"Image\\05_rock_right_attack.bmp",
	"Image\\06_rock_right_attack.bmp",
	"Image\\07_rock_right_attack.bmp",
	"Image\\08_rock_right_attack.bmp",
	"Image\\09_rock_right_attack.bmp"
	
};
char attackBack[10][35] = {
	"Image\\00_rock_back_attack.bmp",
	"Image\\01_rock_back_attack.bmp",
	"Image\\02_rock_back_attack.bmp",
	"Image\\03_rock_back_attack.bmp",
	"Image\\04_rock_back_attack.bmp",
	"Image\\05_rock_back_attack.bmp",
	"Image\\06_rock_back_attack.bmp",
	"Image\\07_rock_back_attack.bmp",
	"Image\\08_rock_back_attack.bmp",
	"Image\\09_rock_back_attack.bmp"
};
char attackFront[10][35] = {
	"Image\\00_rock_front_attack.bmp",
	"Image\\01_rock_front_attack.bmp",
	"Image\\02_rock_front_attack.bmp",
	"Image\\03_rock_front_attack.bmp",
	"Image\\04_rock_front_attack.bmp",
	"Image\\05_rock_front_attack.bmp",
	"Image\\06_rock_front_attack.bmp",
	"Image\\07_rock_front_attack.bmp",
	"Image\\08_rock_front_attack.bmp",
	"Image\\09_rock_front_attack.bmp"
};


void showSword(){

	if (!pickSword)
		iShowBMP2(570, 424, "Sword.bmp", 0);
	if (player_x >= 530 && player_x <= 590 && player_y <= 460 && player_y >= 410 && !pickSword){
		iText(495, 90, "Enter P to pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		textSword = true;
	}


}

void rockMovement() {
	switch (rockDirection) {
	case FRONT:
		iShowBMP2(rock_x, rock_y, rockFront[j_rock], 0);
		break;
	case BACK:
		iShowBMP2(rock_x, rock_y, rockBack[j_rock], 0);
		break;
	case LEFT:
		iShowBMP2(rock_x, rock_y, rockLeft[j_rock], 0);
		break;
	case RIGHT:
		iShowBMP2(rock_x, rock_y, rockRight[j_rock], 0);
		break;
	}
}

void rockAttack() {
	switch (rockDirection) {
	case FRONT:
		iShowBMP2(rock_x, rock_y, attackFront[j_rock], 0);
		break;
	case BACK:
		iShowBMP2(rock_x, rock_y, attackBack[j_rock], 0);
		break;
	case LEFT:
		iShowBMP2(rock_x, rock_y, attackLeft[j_rock], 0);
		break;
	case RIGHT:
		iShowBMP2(rock_x, rock_y, attackRight[j_rock], 0);
		break;
	}
}


void player_hp(){
	if (player_health == 5){ iShowBMP2(50, 680, "Image\\00_health_bar.bmp", 0); }
	if (player_health == 4){ iShowBMP2(50, 680, "Image\\01_health_bar.bmp", 0); }
	if (player_health == 3){ iShowBMP2(50, 680, "Image\\02_health_bar.bmp", 0); }
	if (player_health == 2){ iShowBMP2(50, 680, "Image\\03_health_bar.bmp", 0); }
	if (player_health == 1){ iShowBMP2(50, 680, "Image\\04_health_bar.bmp", 0); }
	if (player_health <1){ iShowBMP2(50, 680, "Image\\05_health_bar.bmp", 0); }
}
void rock_hp(){
	if (rock_health == 5){ iShowBMP2(970, 680, "Image\\00_enemy_hp.bmp", 0); }
	if (rock_health == 4){ iShowBMP2(970, 680, "Image\\01_enemy_hp.bmp", 0); }
	if (rock_health == 3){ iShowBMP2(970, 680, "Image\\02_enemy_hp.bmp", 0); }
	if (rock_health == 2){ iShowBMP2(970, 680, "Image\\03_enemy_hp.bmp", 0); }
	if (rock_health == 1){ iShowBMP2(970, 680, "Image\\04_enemy_hp.bmp", 0); }
	if (rock_health < 1){ iShowBMP2(970, 680, "Image\\05_enemy_hp.bmp", 0); }

}

restrictedArea areas[4] = { { 0, 0, 430, 310 }, { 700, 0, 510, 300 }, { 0, 550, 440, 240 }, { 700, 565, 500, 235 } };

void rockMove() {

	if (pickSword){
		int dx = player_x - rock_x;
		int dy = player_y - rock_y;
		double distanceSquare = dx*dx + dy*dy;
		float distance2 = sqrt(distanceSquare);
		distance = distance2;
		if (abs(dx) > abs(dy)) {
			rockDirection = (dx > 0) ? RIGHT : LEFT;
		}
		else {
			rockDirection = (dy > 0) ? BACK : FRONT;
		}



		if (distance2 <= 60 && !rock_defeated) {
			rockState = ATTACK;
			countAttack++;

			if (countAttack >= 25 && attack == 0 && rock_health != 0) {
				countAttack = 0;
				player_health--;

				if (player_health == 0 && !playerDead && !game_over) {
					playerDead = true;
					j_death = 0;
					d_animationDelay = 0;
				}
			}
		}
		else {
			rockState = CHASE;

			if (distance != 0) {
				float direction_x = dx / distance2;
				float direction_y = dy / distance2;

				float newX = rock_x + direction_x * 5.0;
				float newY = rock_y + direction_y * 5.0;

				if (!isColliding((int)newX, (int)newY)) {
					rock_x = newX;
					rock_y = newY;
				}
				else {
					bool moved = false;

					if (!isColliding((int)(rock_x + direction_x * 5.0), (int)rock_y)) {
						rock_x += direction_x * 5.0;
						moved = true;
					}

					if (!isColliding((int)rock_x, (int)(rock_y + direction_y * 5.0))) {
						rock_y += direction_y * 5.0;
						moved = true;
					}

					if (!moved) {
						rock_x += direction_x * 1.0f;
						rock_y += direction_y * 1.0f;
					}


				}


			}

		}
	}
}
void Level1Draw(){
	iShowBMP(0, 0, "dark2.bmp");
	showSword();
	
	if (pickSword && attack == 0 && !game_over){ playerMoveSword(); }
	if (pickSword && attack == 1 && !game_over){ playerHitSword(); }
	if (pickSword){
		iText(467, 90, "Press Spacebar to attack", GLUT_BITMAP_TIMES_ROMAN_24);
		rock_hp();
	}
	if (pickSword){
		
		r_animationDelay++;
		if (r_animationDelay >= r_speed) {
			r_animationDelay = 0;
			j_rock++;
			if (j_rock >= 10)j_rock = 0;  // loop through 4 frames
		}
	}
	if (pickSword && !rock_defeated) {
		switch (rockState) {
		case ATTACK:
			rockAttack();
			break;
		case CHASE:
			rockMovement();
			break;

		}
	}
	player_hp();
	if (playerDead) {
		playerDeadAnimation();
	}
	else if (game_over) {
		iShowBMP(250, 200, "Image\\game_over.bmp");
	}

	if (rock_defeated){ iShowBMP(250, 200, "Image\\game_won.bmp"); }

	
	iShowBMP2(1030, 735, "images\\soundoff.bmp", 0);
	iShowBMP2(970, 734, "images\\soundon.bmp", 0);

	if (!pickSword)playerMovement();
}