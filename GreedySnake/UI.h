#ifndef _GLO_
	#include"GlobalVar.h"
#endif
class UI{
private:
	int Gheight = 0;
	int Gwidth = 200;
	int swap = 1;
public:
	UI(int i=0){
		DrawStart();
	};
	void DrawStart();
	void DrawBorder();
	void DrawEnd();
};
void UI::DrawStart(){
	 swap++;
	Gheight=sizeof(GameStart) / sizeof(char *);
	
	for (int i = 0; i < Gheight; i++){
		char * ptr = GameStart[i];
		for (int j = 0; j < Gwidth; j++){
			if (ptr[j] == '@')buffer[i*Gwidth + j] = char(177);
			else if (i>68){
				if (swap==5)
					buffer[i*Gwidth + j] = char(178);
				else buffer[i*Gwidth + j] = ' ';
			}
			else buffer[i*Gwidth + j] = ptr[j];
			
		}
	}
	if (swap % 5 == 0)swap = 1;
}
void UI::DrawEnd(){

	Gheight = sizeof(GameOver) / sizeof(char *);
	for (int i = 0; i < Gheight;i++){
		char * ptr = GameOver[i];
		for (int j = 0; j < Gwidth;j++){
			if (ptr[j] == '@')buffer[i*Gwidth + j] = char(177);
			else buffer[i*Gwidth+j] = ptr[j];
		}
	}

}

void UI::DrawBorder(){
	
	buffer[0] = char(201);//left top
	buffer[width-1] = char(187);//right top
	buffer[(height-1)*width] = char(200);//left bottom
	buffer[width*height - 1] = char(188);//right bottom

	for (int i = 1; i < width - 1; i++){// =
		buffer[i] = char(205);
		buffer[(height - 1)*width+i] = char(205);
	}
	for (int j = 1; j < height - 1;j++){// ||
		buffer[j*width] = char(186);
		buffer[(width - 1) + j*width] = char(186);
	}
	
}
