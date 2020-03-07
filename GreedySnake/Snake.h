#ifndef _GLO_
	#include"GlobalVar.h"
#endif

#include "iostream"
#include "String"

class Snake{
private:
	int initLength=3;
public:
	Snake( int l =3){
		getFood = 0;
		length = l;
		initLength = l;
		direction = 3;
		
		head = new SnakeSection;
		seq = head;
		head->pre = 0;

		for (int j = 0; j<length; j++){
			seq->x = 4+j;
			seq->y = 4;
			buffer[seq->y*width + seq->x] = char(254);
			seq->next = new SnakeSection;
			seq->next->pre = seq;
			seq = seq->next;
		}

		tail = seq->pre;
		seq->pre->next = 0;
		delete seq;
	};	
	void resetALL(){

		getFood = 0;
		waitEat = 0;
		getFood = 0;
		length = initLength;
		direction = 3;

		head = new SnakeSection;
		seq = head;
		head->pre = 0;

		for (int j = 0; j<length; j++){
			seq->x = 4 + j;
			seq->y = 4;
			buffer[seq->y*width + seq->x] = char(254);
			seq->next = new SnakeSection;
			seq->next->pre = seq;
			seq = seq->next;
		}

		tail = seq->pre;
		seq->pre->next = 0;
		delete seq;
	};
	void aniamtion(){
		
		seq = new SnakeSection;
		seq->pre = 0;
		seq->x = head->x;
		seq->y = head->y;
		seq->next = head;
		head->pre = seq;

		head = seq;

		switch (direction){
		case 0:
			seq->x--;
			break;
		case 1:
			seq->x++;
			break;
		case 2:
			seq->y--;
			break;
		case 3:
			seq->y++;
			break;
		default:
			break;
		}
	};
};
