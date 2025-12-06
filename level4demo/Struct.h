#ifndef STRUCT_H
#define STRUCT_H
////////////////Here all the structures will be declared so they can be used in other header files//////////////
struct Mirror {
	int x, y, w, h;
	char image[30];
	bool picked;
	bool showText;
};

extern Mirror mirrors[10];
extern int mirrorCount;

struct objectBox {
	int x, y, w, h;
	char image[30];
	bool picked;
	bool showText;
	char text[50];
};
extern objectBox boxs[10];
extern int boxCount;

struct restrictedArea{
	int x, y, w, h;
};
extern restrictedArea areas[4];
extern restrictedArea areas2[40];
extern restrictedArea areas3[220];
extern restrictedArea areas4[50];
bool isColliding(int newX, int newY);

struct Box {
	int x, y, w, h;
	char image[30];
	bool picked;
	bool showText;
};
extern int Count;
extern Box box[7];

struct Box_1 {
	int x, y, w, h;
	char image[30];
	bool picked;
	bool showText;
	bool correct_box;
};

extern Box_1 box_0[2];
extern Box_1 box_1[2];
extern Box_1 box_2[2];
extern Box_1 box_3[2];
extern Box_1 box_4[2];
extern Box_1 box_5[2];
extern Box_1 box_6[2];

extern int count_1;

#endif


