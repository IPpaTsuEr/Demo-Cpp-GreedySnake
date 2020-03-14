#include "afxwin.h"
#include"Control.h"
#include"Snake.h"
#include"UI.h"


void main(){
	Control ct(200,86);
	UI ui(1);
	Snake sk(18);
	CString  ds( L"你的得分为:"), so(L"00分");
	
re:
	ct.clearScreen();
	ct.resetALL();
	sk.resetALL();

	while (true){
		ct.KeyPress();
		if (ct.getExit()){
			break;
		}
		if (!ct.getStatue()){
			ui.DrawStart();
			ct.put();
		}
		else{
			ct.clearScreen();
			ui.DrawBorder();
			ct.put();
			break;
		}
		Sleep(300);
	}
	if (ct.getExit()){return;}

	while (true){
		ct.KeyPress();
		Sleep(150);
		
		if (!ct.getStatue()){ continue; }

		if (waitEat < 1){ 
			ct.CreatFood();
		}
		sk.aniamtion();
		ct.Active();
		if (ct.getDeath())break;
		ct.put();
		
	}
	if (!ct.getExit()){
		ui.DrawEnd();
		ct.put();
		char sc[4];
		_itoa_s(getFood, sc, 10);
		CString ff(sc);
		MessageBox(NULL,ds+ff+so,L"游戏结束！", MB_OK);
		Sleep(600);
		goto re;
	}

}