#ifndef _GLO_
	#include"GlobalVar.h"
#endif

#include "sstream"
#include"time.h"

class Control{
private:
	HANDLE OutPut;
	bool exit, start,death;
public:
	Control(int w = 126, int h = 48 ){
		exit = false;
		start = false;
		death = false;

		width = w;
		height = h;
		waitEat = 0;

		buffer = new char[width*height];
		memset(buffer, ' ', width*height*sizeof(char));

		HMODULE hKernel32 = GetModuleHandle(L"kernel32");
		SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32, "SetConsoleFont");

		SetConsoleOutputCP(437);

		std::ostringstream sst;
		std::string str = "";
		sst << "mode con cols=" << width << " lines=" << height;
		str = sst.str();
		system(str.c_str());
		
		system("Color F0");

		OutPut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cci;
		cci.bVisible = 0;
		cci.dwSize = 1;

		SetConsoleCursorInfo(OutPut, &cci);
		SetConsoleFont(OutPut, 0);
	};
	bool CheckDeath();
	bool CheckFood();
	void CreatFood();
	void KeyPress();
	void Active();
	void put(){
		DWORD dw;
		COORD coord = { 0, 0 };
		WriteConsoleOutputCharacterA(OutPut, buffer, width*height, coord, &dw);
	};
	void get(){
		DWORD dw;
		COORD coord = { 0, 0 };
		ReadConsoleOutputCharacterA(OutPut, buffer, width*height, coord, &dw);
	}
	void clearScreen(){
		memset(buffer, ' ', width*height*sizeof(char));
		system("cls");
	}
	bool getStatue(){ return start; };
	bool getDeath(){ return death; };
	bool getExit(){ return exit; };
	void resetALL(){
		start = false;
		exit = false;
		death = false;
	};
};
bool Control::CheckDeath(){
	if (buffer[head->y*width + head->x] == char(186)){ return true; }
	else if (buffer[head->y*width + head->x] == char(187)){ return true; }
	else if (buffer[head->y*width + head->x] == char(188)){ return true; }
	else if (buffer[head->y*width + head->x] == char(200)){ return true; }
	else if (buffer[head->y*width + head->x] == char(201)){ return true; }
	else if (buffer[head->y*width + head->x] == char(205)){ return true; }
	else if (buffer[head->y*width + head->x] == char(254)){ return true; }
	else { return false; }
	
}
bool Control::CheckFood(){
	if (buffer[head->y*width + head->x]==char(233))return true;
	else return false;
}
void Control::CreatFood(){
	int x = 0;
	int y = 0;

	do{
		srand((int)time(0));
		x= rand() % width;
		y= rand() % height;
	} while (buffer[y*width + x] != ' ');

	buffer[y*width + x] =char(233);
	waitEat++;
}
void Control::KeyPress(){
	if (GetAsyncKeyState(VK_DOWN) && 0X8000){
		if (direction != 2)direction = Down;
	}
	if (GetAsyncKeyState(VK_UP) && 0X8000){
		if (direction != 3)direction = Up;
	}
	if (GetAsyncKeyState(VK_LEFT) && 0X8000){
		if (direction != 1)direction = Left;
	}
	if (GetAsyncKeyState(VK_RIGHT) && 0X8000){
		if (direction != 0)direction = Right;
	}
	if (GetAsyncKeyState(VK_ESCAPE) && 0X8000){
		exit = true;
	}
	if (GetAsyncKeyState(VK_SPACE) && 0X8000){
		start =!start;
	}
};
void Control::Active(){
	if (!CheckFood()){
		tail = tail->pre;
		buffer[tail->next->y*width + tail->next->x] = ' ';
		delete tail->next;
		tail->next = 0;
	}
	else{
		getFood += 1;
		waitEat--;
		length++;
	}
	if (CheckDeath()|| exit){ death = true;return; }
	else
	{
		for (int i = 0; i<length; i++){
				if (seq->x<0 || seq->y<0 || seq->x>width || seq->y>height)break;
				buffer[seq->y*width + seq->x] = char(254);
				seq = seq->next;
			}
	}
	
}