#include "Struct.h"
#include "Player.h"
#include "Struct.h"
#include "Player.h"

int Level3Wave = 0;
bool waveTextActive = false;
int waveTextTimer = 0;
int finalWaveDelay = 0;
int playerHP = 9;
int playerMaxHP = 9;
int regenCooldown = 0;
bool playerHealedOnce = false;
int regenTimer = 0;
bool level3Win = false;
bool level3Fail = false;
extern bool level3SoundOn;
extern int level3MusicState;
bool level3Finished = false;
int endScreenTimer = 0;

struct Minion {
	int x, y;
	int hp;
	bool alive;
	bool attacking;
};
Minion groundMinions[3];
Minion elevatedMinions[3];

bool bossSpawned = false;
bool bossDead = false;
bool bossAttacking = false;
int bossHP = 7;
int bossMaxHP = 7;

int playerAttackFrame = 0;
int playerAttackDelay = 0;
int playerDeathFrame = 0;
int playerDeathDelay = 0;
bool playerAttacking = false;
char walkFrames[5][30] = {
	"Sprout//smove1.bmp",
	"Sprout//smove2.bmp",
	"Sprout//smove3.bmp",
	"Sprout//smove4.bmp",
	"Sprout//smove5.bmp"
};

// Minions
int minionAttackFrame[3] = { 0, 0, 0 };
int minionAttackDelay[3] = { 0, 0, 0 };
int minionDeathFrame[3] = { 0, 0, 0 };
int minionDeathDelay[3] = { 0, 0, 0 };
int minionWalkFrame[3] = { 0, 0, 0 };
int minionWalkDelay[3] = { 0, 0, 0 };

// Boss
int bossAttackFrame = 0, bossAttackDelay = 0;
int bossDeathFrame = 0, bossDeathDelay = 0;

int Ladder;

extern bool level3;
void obsticals()
{
	iShowBMP2(1000, 370, "O5.bmp", 16777215);
	iShowBMP2(40, 370, "O5.bmp", 16777215);
	iShowBMP2(970, 650, "O6.bmp", 16777215);
	iShowBMP2(970, 750, "O8.bmp", 16777215);
	iShowBMP2(1000, 720, "O8.bmp", 16777215);
	iShowBMP2(1030, 720, "O7.bmp", 16777215);
	iShowBMP2(1080, 740, "O7.bmp", 16777215);
	iShowBMP2(100, 740, "O3.bmp", 16777215);
	iShowBMP2(86, 740, "O3.bmp", 16777215);
	iShowBMP2(10, 720, "O6.bmp", 16777215);

}

char background[20] = { "L3.bmp" };
void Ladderr()
{
	iShowImage(250, 460, 50, 110, Ladder);
	iShowImage(370, 270, 50, 110, Ladder);
	iShowImage(700, 340, 50, 110, Ladder);
	iShowImage(920, 550, 50, 110, Ladder);
}

restrictedArea areas3[220] = { { 302 - 10, 15, 477 - 10, 70 }, { 460 - 10, 15, 200 - 10, 150 }, { 100 - 10, 80 + 10, 50 - 10, 30 }, { 1015 - 10, 40 + 10, 50 - 10, 30 },
{ 50 - 10, 378 + 10, 90 - 10, 90 - 20 }, { 1015 - 10, 380 + 10, 90 - 10, 90 - 20 }, { 10, 720 + 10, 150 - 10, 150 - 20 }, { 950 - 10, 720, 210 - 10, 150 }, { 970 - 10, 670, 90 - 10, 150 },
{ 720 - 10, 685, 120 - 10, 80 }, { 702 - 10, 760, 160 - 10, 80 }, { 700 - 10, 600, 50 - 10, 30 }, { 400 - 10, 600, 50 - 10, 30 }, { 110, 510, 50, 30 }, { 1060 - 10, 250 + 10, 90, 90 - 20 },
{ 880 - 10, 300, 70, 30 }, { 1150 - 10, 720, 80 - 10, 80 - 20 }, { 1080 - 10, 690, 80 - 10, 80 }, { 1040, 650, 80, 80 }, { 1000 - 10, 600 + 20, 40 - 10, 80 }, { 960 - 10, 570, 40, 60 },
{ 800 - 10, 570, 40, 60 }, { 840 - 20, 535, 80, 60 }, { 680 - 20, 535, 120, 60 }, { 640 - 10, 570, 40, 60 }, { 520 - 10, 650, 40 - 10, 60 }, { 440 - 10, 695, 40, 50 }, { 480, 760, 40, 50 - 20 },
{ 560 - 10, 620, 80, 60 }, { 400 - 10, 620, 80 - 20, 60 }, { 360 - 10, 570, 40 - 10, 50 }, { 320 + 15, 530, 40, 50 }, { 280 + 10, 490, 40, 50 }, { 150, 490, 90, 60 }, { 80, 490, 90, 60 }, { 40, 460, 40, 50 },
{ 0, 420, 40, 50 }, { 120, 420, 40, 80 }, { 160, 370, 40, 60 }, { 200, 330, 40, 60 }, { 240, 290, 40, 60 }, { 280, 260, 40, 60 }, { 320, 260, 40, 60 }, { 350, 290, 5, 50 }, { 400, 310, 40, 40 }, { 440, 340, 40, 50 },
{ 480, 380, 40, 50 }, { 420, 530, 40, 50 }, { 460, 500, 40, 50 }, { 490, 470, 40, 50 }, { 540, 420, 40, 50 }, { 580, 380, 40, 50 }, { 610 - 15, 340, 90, 60 }, { 730, 370, 40, 50 }, { 780, 340, 40, 50 }, { 820, 310, 40, 50 }, { 860, 270, 40, 50 },
{ 900, 230, 40, 50 }, { 940, 270, 40, 50 }, { 980, 250, 80, 50 }, { 1060, 330, 100, 50 }, { 1120, 340, 40, 50 }, { 1160, 420, 40, 50 }, { 320, 530, 40, 60 } };
int collisionCount3 = sizeof(areas3) / sizeof(areas3[0]);

int devil_flower_X = 0;
int devil_flower_Y = 0;

char Noraml[30] = { "F1.bmp" };
char Devil_Flower_1[30] = { "F2.bmp" };
char Devil_Flower_2[30] = { "F3.bmp" };

bool devil_grow = true;
int Frame = 0;

void toggle() {
	if (devil_grow) {
		Frame = (Frame + 1) % 3;
	}
}

void devilEffect()
{
	if (devil_grow) {
		if (Frame == 0)
			iShowBMP2(400 + 15, 600, Noraml, 16777215);
		else if ((Frame == 1))
			iShowBMP2(400, 600, Devil_Flower_1, 16777215);
		else if (Frame == 2)
			iShowBMP2(400 - 10, 600, Devil_Flower_2, 16777215);
		else
			iShowBMP2(400 + 15, 600, Noraml, 16777215);
	}
	else {
		iShowBMP2(400 + 15, 600, Noraml, 16777215);
	}

}

void devilEffect_1()
{
	if (devil_grow) {
		if (Frame == 0)
			iShowBMP2(100 + 15, 520, Noraml, 16777215);
		else if ((Frame == 1))
			iShowBMP2(100, 520, Devil_Flower_1, 16777215);
		else if (Frame == 2)
			iShowBMP2(100 - 10, 520, Devil_Flower_2, 16777215);
		else
			iShowBMP2(100 + 15, 520, Noraml, 16777215);
	}
	else {
		iShowBMP2(100 + 15, 520, Noraml, 16777215);
	}

}

char Noraml_1[30] = { "b0.bmp" };
char Devil_Eye_1[30] = { "b1.bmp" };
char Devil_Eye_2[30] = { "b2.bmp" };

void devilEffect_Eye()
{
	if (devil_grow) {
		if (Frame == 0)
			iShowBMP2(890 + 15, 300, Noraml_1, 16777215);
		else if ((Frame == 1))
			iShowBMP2(890, 300, Devil_Eye_1, 16777215);
		else if (Frame == 2)
			iShowBMP2(890 - 10, 300, Devil_Eye_2, 16777215);
		else
			iShowBMP2(890 + 15, 300, Noraml_1, 16777215);
	}
	else {
		iShowBMP2(890 + 15, 300, Noraml_1, 16777215);
	}

}

void devilEffect_Eye_1()
{
	if (devil_grow) {
		if (Frame == 0)
			iShowBMP2(700 + 15, 600, Noraml_1, 16777215);
		else if ((Frame == 1))
			iShowBMP2(700, 600, Devil_Eye_2, 16777215);
		else if (Frame == 2)
			iShowBMP2(700 - 10, 600, Devil_Eye_1, 16777215);
		else
			iShowBMP2(700 + 15, 600, Noraml_1, 16777215);
	}
	else {
		iShowBMP2(700 + 15, 600, Noraml_1, 16777215);
	}

}

char Noraml_2[30] = { "ff1.bmp" };
char Stranger_1[30] = { "ff1.1.bmp" };

void Stranger_danger()
{
	if (devil_grow) {
		if (Frame == 0)
			iShowBMP2(1050 - 15, 250, Noraml_2, 16777215);
		else if ((Frame == 1))
			iShowBMP2(1050, 250, Stranger_1, 16777215);
		else if (Frame == 2)
			iShowBMP2(1050 - 10, 250, Noraml_2, 16777215);
		else
			iShowBMP2(1050 - 10, 250, Stranger_1, 16777215);
	}
	else {
		iShowBMP2(1050 + 15, 250, Noraml_2, 16777215);
	}

}



/////////////////////////////////////////////////////


int attackFrame = 0;
int attackDelay = 0;

void drawPlayerLevel3() {

	char fileName[100];
	if (playerHP <= 0) {

		playerDead = true;
		/*if (front)
		sprintf_s(fileName, "Image/D_F_%d.bmp", playerDeathFrame + 1);
		else if (left)
		sprintf_s(fileName, "Image/D_L_%d.bmp", playerDeathFrame + 1);
		else if (right)
		sprintf_s(fileName, "Image/D_R_%d.bmp", playerDeathFrame + 1);
		iShowBMP2(player_x, player_y, fileName, 0);

		playerDeathDelay++;
		if (playerDeathDelay >= 8) {
		playerDeathFrame++;
		playerDeathDelay = 0;
		}
		if (playerDeathFrame >= 4) playerDeathFrame = 3;
		return;*/
		playerDeadAnimation();
	}

	if (attack == 1) {
		/*if (left)
		sprintf_s(fileName, "Image/L_%d.bmp", attackFrame + 1);
		else if (right)
		sprintf_s(fileName, "Image/R_%d.bmp", attackFrame + 1);

		iShowBMP2(player_x, player_y, fileName, 0);
		attackDelay++;
		if (attackDelay >= 5) {
		attackFrame++;
		attackDelay = 0;
		}
		if (attackFrame >= 6) {
		attackFrame = 0;
		playerAttacking = false;
		}*/
		playerAttacking = true;
		playerHitSword();

		attackDelay++;
		if (attackDelay >= 8) {
			attackDelay = 0;
			attack = 0;
			playerAttacking = false;
		}
	}
	else if (attack == 0){
		playerAttacking = false;
		if (!Player_Stand) {
			if (front)
				iShowBMP2(player_x, player_y, swordFront[j], 0);
			else if (back)
				iShowBMP2(player_x, player_y, swordBack[j], 0);
			else if (left)
				iShowBMP2(player_x, player_y, swordLeft[j], 0);
			else if (right)
				iShowBMP2(player_x, player_y, swordRight[j], 0);

			standCounter++;
			if (standCounter >= 30) {
				standCounter = 0;
				player_walking = 0;
				Player_Stand = true;
			}
		}
		else {
			if (front) iShowBMP2(player_x, player_y, swordFront[0], 0);
			else if (back) iShowBMP2(player_x, player_y, swordBack[0], 0);
			else if (left) iShowBMP2(player_x, player_y, swordLeft[0], 0);
			else if (right) iShowBMP2(player_x, player_y, swordRight[0], 0);
		}
	}
	if (playerHP > 0) {
		char hpFile[50];
		sprintf_s(hpFile, "hp/m_hp%d.bmp", playerHP);
		iShowBMP2(10, 740, hpFile, 0);
	}
}
int groundSpawnIndex = 0;
int elevatedSpawnIndex = 0;
void drawMinion(Minion &m, int idx) {
	if (!m.alive) return;

	char fileName[50];

	if (m.hp <= 0) {
		sprintf_s(fileName, "Sprout/sdeath%d.bmp", minionDeathFrame[idx] + 1);
		iShowBMP2(m.x, m.y, fileName, 0);

		minionDeathDelay[idx]++;
		if (minionDeathDelay[idx] >= 5) {
			minionDeathFrame[idx]++;
			minionDeathDelay[idx] = 0;
		}
		if (minionDeathFrame[idx] >= 6) {
			m.alive = false;
		}
		return;
	}

	if (m.attacking) {
		sprintf_s(fileName, "Sprout/sattack%d.bmp", minionAttackFrame[idx] + 1);
		iShowBMP2(m.x, m.y, fileName, 0);

		minionAttackDelay[idx]++;
		if (minionAttackDelay[idx] >= 6) {
			minionAttackFrame[idx]++;
			minionAttackDelay[idx] = 0;
		}
		if (minionAttackFrame[idx] >= 4) minionAttackFrame[idx] = 0;
	}
	else {
		sprintf_s(fileName, "Sprout/smove%d.bmp", minionWalkFrame[idx] + 1);
		iShowBMP2(m.x, m.y, fileName, 0);

		minionWalkDelay[idx]++;
		if (minionWalkDelay[idx] >= 6) {
			minionWalkFrame[idx]++;
			minionWalkDelay[idx] = 0;
		}
		if (minionWalkFrame[idx] >= 5) minionWalkFrame[idx] = 0;
	}

	iSetColor(0, 255, 0);
	iFilledRectangle(m.x, m.y + 60, 20 * m.hp / 3, 5);
}
bool checkCollision(int x1, int y1, int w1, int h1,
	int x2, int y2, int w2, int h2) {
	return !(x2 > x1 + w1 ||
		x2 + w2 < x1 ||
		y2 > y1 + h1 ||
		y2 + h2 < y1);
}
void moveMinionsSequential(Minion m[], int count, int *spawnIndex, int speed) {
	for (int i = 0; i < count; i++) {
		if (i > *spawnIndex) continue;

		if (i == *spawnIndex && !m[i].alive) {
			m[i].alive = true;
			m[i].x = 1200 + i * 100;
		}

		if (m[i].alive) {

			if (!checkCollision(m[i].x, m[i].y, 50, 50, player_x, player_y, 50, 50)) {
				m[i].x -= speed;
			}
			else {
				m[i].attacking = true;
			}

			if (!m[i].attacking) {
				minionWalkDelay[i]++;
				if (minionWalkDelay[i] >= 5) {
					minionWalkFrame[i]++;
					minionWalkDelay[i] = 0;
				}
				if (minionWalkFrame[i] >= 5) minionWalkFrame[i] = 0;
			}

			if (m[i].x < -50 || m[i].hp <= 0) {
				m[i].alive = false;
				if (*spawnIndex < count - 1)
					(*spawnIndex)++;
			}
		}
	}
}

int attackCooldown[3] = { 0, 0, 0 };
void updateMinionAttack(Minion &m, int idx) {
	if (!m.alive) return;

	if (checkCollision(m.x, m.y, 50, 50, player_x, player_y, 50, 50)) {
		m.attacking = true;
		attackCooldown[idx]++;
		if (attackCooldown[idx] >= 40) {
			playerHP--;
			if (playerHP < 0) playerHP = 0;
			attackCooldown[idx] = 0;
		}
	}
	else {
		m.attacking = false;
		attackCooldown[idx] = 0;
	}

}
int minionDamageCooldown[3] = { 0, 0, 0 };

void updateMinionDamage(Minion &m, int idx) {
	if (!m.alive) return;

	int playerW = 80;
	int playerH = 80;
	int minionW = 50, minionH = 50;

	if (playerAttacking && checkCollision(player_x, player_y, playerW, playerH, m.x, m.y, minionW, minionH)) {
		if (minionDamageCooldown[idx] == 0) {
			m.hp--;
			if (m.hp <= 0) {
				m.hp = 0;
				m.alive = false;
			}
			minionDamageCooldown[idx] = 20;
		}
	}

	if (minionDamageCooldown[idx] > 0) {
		minionDamageCooldown[idx]--;
	}
}

bool isCollidingWithPlayer(int bx, int by) {
	int bossSize = 96;
	int playerSize = 50;

	if (bx + bossSize > player_x && bx < player_x + playerSize &&
		by + bossSize > player_y && by < player_y + playerSize) {
		return true;
	}
	return false;
}



int bossX = 1100;
int bossY = 700;
int bossLeftBound = 50;
int bossRightBound = 300;
int bossDir = 1;
int bossSpeed = 2;
int idleFrame = 0, idleDelay = 0;
void drawBoss() {
	if (!bossSpawned) return;

	char fileName[50];
	if (bossDead) {
		sprintf_s(fileName, "Sprout/death%d.bmp", bossDeathFrame + 1);
		iShowBMP2(bossX, bossY, fileName, 0);
		bossDeathDelay++;
		if (bossDeathDelay >= 5) {
			bossDeathFrame++;
			bossDeathDelay = 0;
		}
		if (bossDeathFrame >= 7) bossDeathFrame = 6;
	}
	else if (bossAttacking) {
		sprintf_s(fileName, "Sprout/attack%d.bmp", bossAttackFrame + 1);
		iShowBMP2(bossX, bossY, fileName, 0);
		bossAttackDelay++;
		if (bossAttackDelay >= 5) {
			bossAttackFrame++;
			bossAttackDelay = 0;
		}
		if (bossAttackFrame >= 6) bossAttackFrame = 0;
	}
	else {

		sprintf_s(fileName, "Sprout/idle%d.bmp", idleFrame + 1);
		iShowBMP2(bossX, bossY, fileName, 0);
		idleDelay++;
		if (idleDelay >= 8) {
			idleFrame = (idleFrame + 1) % 4;
			idleDelay = 0;
		}
	}

	if (!bossDead) {
		char hpFile[50];
		int clampedBossHP = (bossHP > 0) ? bossHP : 0;
		if (clampedBossHP > 0){
			sprintf_s(hpFile, "hp/b_hp%d.bmp", clampedBossHP);
			iShowBMP2(1000, 740, hpFile, 0);
		}
	}
	if (bossDead && bossDeathFrame >= 6) {
		bossSpawned = false;
	}
}
int bossAttackCooldown = 0;
int bossDamageCooldown = 0;

void updateBossCollision() {
	if (!bossSpawned || bossDead) return;

	int swordX = player_x;
	int swordY = player_y;
	int swordW = 80;
	int swordH = 80;

	// Extend sword hitbox depending on direction
	if (right) {
		swordX = player_x + 20;
		swordW = 100;  // bigger range
	}
	else if (left) {
		swordX = player_x - 60;
		swordW = 100;
	}
	else if (front) {
		swordY = player_y - 40;
		swordH = 100;
	}
	else if (back) {
		swordY = player_y + 40;
		swordH = 100;
	}

	int playerW = 60, playerH = 80;
	int bossW = 120, bossH = 120; // bigger hitbox for boss

	// --- PLAYER ATTACK DAMAGES BOSS ---
	if (playerAttacking && checkCollision(swordX, swordY, swordW, swordH, bossX, bossY, bossW, bossH)) {
		if (bossDamageCooldown == 0) {
			bossHP--;
			if (bossHP <= 0) {
				bossHP = 0;
				bossDead = true;
			}
			bossDamageCooldown = 15; // shorter cooldown so multiple hits register
		}
	}

	if (bossDamageCooldown > 0) bossDamageCooldown--;

	// --- BOSS DAMAGES PLAYER ---
	if (checkCollision(player_x, player_y, playerW, playerH, bossX, bossY, bossW, bossH)) {
		bossAttacking = true;
		bossAttackCooldown++;
		if (bossAttackCooldown >= 40) { // slower attack speed
			playerHP -= 2;
			if (playerHP < 0) playerHP = 0;
			bossAttackCooldown = 0;
		}
	}
	else {
		bossAttacking = false;
		bossAttackCooldown = 0;
	}
}


void drawWaveText() {
	if (!waveTextActive) return;
	iSetColor(255, 255, 255);
	iText(600, 400,
		(Level3Wave == 1) ? "Wave 1" :
		(Level3Wave == 2) ? "Wave 2" : "FINAL WAVE",
		GLUT_BITMAP_TIMES_ROMAN_24);
}
int waveDelayTimer = 0;

void updateWave() {
	if (Level3Wave == 0) {
		Level3Wave = 1;
		for (int i = 0; i < 3; i++) {
			groundMinions[i] = { 1200 + i * 100, 190, 3, true, false };
		}
		waveTextActive = true; waveTextTimer = 100;
	}
	else if (Level3Wave == 1) {
		bool allDead = true;
		for (int i = 0; i < 3; i++) if (groundMinions[i].alive) allDead = false;
		if (allDead && waveDelayTimer == 0) {
			waveDelayTimer = 480;
		}
		if (waveDelayTimer > 0) {
			waveDelayTimer--;
			if (waveDelayTimer == 0) {
				Level3Wave = 2;
				for (int i = 0; i < 3; i++) {
					elevatedMinions[i] = { 1200 + i * 100, 490, 3, true, false };
				}
				waveTextActive = true; waveTextTimer = 100;
			}
		}
	}
	else if (Level3Wave == 2) {
		bool allDead = true;
		for (int i = 0; i < 3; i++) if (elevatedMinions[i].alive) allDead = false;
		if (allDead) {
			if (finalWaveDelay == 0) {
				finalWaveDelay = 480;
			}
			else {
				finalWaveDelay--;
				if (finalWaveDelay <= 0) {
					Level3Wave = 3;
					bossSpawned = true;
					bossHP = bossMaxHP;
					bossX = 50;
					bossY = 650;
					bossDir = 1;
					bossAttackFrame = bossAttackDelay = 0;
					bossDeathFrame = bossDeathDelay = 0;
					waveTextActive = true;
					waveTextTimer = 100;
				}
			}
		}
	}
}

void updateBoss() {
	if (!bossSpawned || bossDead) return;

	bossX += bossDir * bossSpeed;
	if (bossX <= bossLeftBound) {
		bossX = bossLeftBound;
		bossDir = 1;
	}
	else if (bossX >= bossRightBound) {
		bossX = bossRightBound;
		bossDir = -1;
	}

}

void updateWaveText() {
	if (waveTextActive) {
		waveTextTimer--;
		if (waveTextTimer <= 0) waveTextActive = false;
	}
}

void updateLevel() {
	if (Level3Wave == 1)
		moveMinionsSequential(groundMinions, 3, &groundSpawnIndex, 4);
	if (Level3Wave == 2)
		moveMinionsSequential(elevatedMinions, 3, &elevatedSpawnIndex, 4);

	for (int i = 0; i < 3; i++) {
		if (Level3Wave == 1){
			updateMinionAttack(groundMinions[i], i);
			updateMinionDamage(groundMinions[i], i);
		}
		if (Level3Wave == 2){
			updateMinionAttack(elevatedMinions[i], i);
			updateMinionDamage(elevatedMinions[i], i);
		}
	}

	for (int i = 0; i < 3; i++) {
		if (Level3Wave == 1) drawMinion(groundMinions[i], i);
		if (Level3Wave == 2) drawMinion(elevatedMinions[i], i);
	}
	updateBoss();
	if (bossSpawned && !bossDead){
		updateBossCollision();
	}
	if (!playerDead && playerHP > 0 && playerHP < playerMaxHP && !playerAttacking  && !playerHealedOnce) {
		regenTimer++;
		if (regenTimer >= 60) {
			playerHP++;
			if (playerHP > playerMaxHP) playerHP = playerMaxHP;
			playerHealedOnce = true;
		}
	}
	if (playerHP <= 0 && !level3Win) {
		level3Fail = true;
		//level3 = false;
	}

	if (Level3Wave == 3 && bossDead && !level3Fail) {
		level3Win = true;
	}
	if (playerHP <= 0 && !level3Win) {
		level3Fail = true;
	}
}

void level3Draw() {
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 1200, 800);
	iShowBMP(0, 0, background);
	Ladderr();
	obsticals();

	devilEffect();
	devilEffect_1();
	devilEffect_Eye();
	devilEffect_Eye_1();
	Stranger_danger();

	if (!level3) return;
	if (level3SoundOn){
		iShowBMP2(1030, 735, "images\\soundoff.bmp", 0);
	}
	else{
		iShowBMP2(970, 734, "images\\soundon.bmp", 0);
	}
	if (level3SoundOn && level3MusicState == 0){
		PlaySound("level3bgm.wav", NULL, SND_ASYNC | SND_LOOP);
		level3MusicState = 1;
	}
	updateWave();
	updateWaveText();

	updateLevel();

	drawPlayerLevel3();

	if (Level3Wave == 3)
		drawBoss();
	if (bossSpawned && !bossDead) {

		if (!isCollidingWithPlayer(bossX, bossY)) {
			bossAttacking = true;
		}
	}
	if (bossDead && Level3Wave) {
		level3Win = true;
	}


	drawWaveText();

	if (level3Win) iShowBMP(250, 200, "Image\\game_won.bmp");
	if (level3Fail) iShowBMP(250, 200, "Image\\game_over.bmp");



}

