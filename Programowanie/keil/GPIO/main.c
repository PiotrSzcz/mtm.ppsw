#include <LPC21xx.H>
#define LED0_bm 0x10000 
#define LED1_bm 0x20000 
#define LED2_bm 0x40000 
#define LED3_bm 0x80000 

void Delay(int iIloscIteracji){
	
	int Couter;
	
	for(Couter = 0; Couter != (iIloscIteracji * 12000); Couter++ ){ }
}

void LedInite (){
	
	IO1DIR = IO1DIR |(LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	int iPrzesun;
	
	iPrzesun = 0x10000 << ucLedIndeks;
	IO1CLR = 0xFF0000;
	IO1DIR = iPrzesun;
	IO1SET = iPrzesun;
}
/*
void ReadButton1(){
	if((IO1SET & 0x8) == 0){
		IO1CLR = LED0_bm;
		IO1SET = LED1_bm ;
	}
	if((IO1SET & 0x8) == 8){
		IO1CLR = LED1_bm;
		IO1SET = LED0_bm ;
	}
}
*/
/*
enum ButtonState {RELASED, PRESSED};
enum ButtonState ReadButton1(){
    IO0DIR = IO0DIR |(0x10 | 0x20 | 0x40 | 0x80);
		
		if((IO0SET & 0x8) == 8){
			return RELASED;
		}
		else{
			return PRESSED;
	}
}
*/
enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(){
	
		if((IO0SET&0x10) == 0){
			return BUTTON_0;
		}
		if((IO0SET&0x20) == 0){
			return BUTTON_1;
		}
		if((IO0SET&0x40) == 0){
			return BUTTON_2;
		}
		if((IO0SET&0x80) == 0){
			return BUTTON_3;
		}
		else{
			return RELASED;
		}
}

void KeyboardInit() {
	
		IO0DIR = IO0DIR | 0xF0;
}
/*
void StepLeft() {
	IO1DIR = IO1DIR |(LED0_bm | LED1_bm | LED2_bm | LED3_bm);
		uiStepOper ++ ;
		LedOn(uiStepOper % 4);
}

void StepRight() {
    IO1DIR = IO1DIR |(LED0_bm | LED1_bm | LED2_bm | LED3_bm);
		uiStepOper -- ;
		LedOn(uiStepOper % 4);
}
*/


enum LedDirection {LEFT, RIGHT};

void LedStep (enum LedDirection Direction){
		static unsigned int uiStepOper = 4;
	
		switch(Direction) {
			case(LEFT):
				uiStepOper ++ ;
				LedOn(uiStepOper % 4);
				break;
			case(RIGHT):
				uiStepOper -- ;
				LedOn(uiStepOper % 4);
		}
	
}

void ButtonToLed(int iButton){
		static unsigned int uiStepOper = 4;
	
		if (iButton == BUTTON_1) {
			while (iButton == BUTTON_1){
				uiStepOper ++ ;
				LedOn(uiStepOper % 4);
		}
		if (iButton == BUTTON_2){
			while (iButton == BUTTON_2){
				uiStepOper -- ;
				LedOn(uiStepOper % 4);
		}
		if (iButton == RELASED) {
			while (iButton == RELASED){
				LedOn(uiStepOper);
			}
		}
		else {}
		}
	}
}

void LedStepLeft() {
	LedStep(LEFT);
}

void LedStepRight() {
	LedStep(RIGHT);
}

int main(){
	while(1){
	LedStepRight();
	}
	/*
	while(1){
		LedStepRight() ;
	}
	*/
	/*
	IO1DIR = 0x10000;
	IO1SET = 0x10000;
	IO1CLR = 0x10000;
	while(1){
	}
	*/
	/*
	while(1){
		IO1DIR = 0x10000;
		IO1SET = 0x10000;
		IO1CLR = 0x10000;
	}
	*/
	/*
	while(1){
		IO1DIR = LED0_bm;
		IO1SET = LED0_bm;
		Delay(1000);
		IO1CLR = LED0_bm;
		Delay(1000);
	}
	*/
	/*
	while(1){
		IO1DIR = LED3_bm;
		IO1SET = LED3_bm;
		Delay(1000);
		IO1CLR = LED3_bm;
		Delay(1000);
	}
	*/
	/*
	IO1DIR = LED0_bm;
	IO1DIR = LED1_bm;
	IO1DIR = LED2_bm;
	IO1DIR = LED3_bm;
	IO1SET = LED0_bm;
	IO1SET = LED1_bm;
	IO1SET = LED2_bm;
	IO1SET = LED3_bm;
	*/
	/*
	IO1DIR = LED0_bm;
	IO1DIR = LED1_bm;
	IO1DIR = LED2_bm;
	IO1DIR = LED3_bm;
	IO1SET = LED0_bm;
	Delay(250);
	IO1CLR = LED0_bm;
	IO1SET = LED1_bm;
	Delay(250);
	IO1CLR = LED1_bm;
	IO1SET = LED2_bm;
	Delay(250);
	IO1CLR = LED2_bm;
	IO1SET = LED3_bm;
	Delay(250);
	IO1CLR = LED3_bm;
	*/
  /*
	Ledline();
	Delay(250);
	IO1CLR = LED0_bm;
	IO1SET = LED1_bm;
	Delay(250);
	IO1CLR = LED1_bm;
	IO1SET = LED2_bm;
	Delay(250);
	IO1CLR = LED2_bm;
	IO1SET = LED3_bm;
	Delay(250);
	IO1CLR = LED3_bm;	
	*/
	/*
	Ledline();
	Delay(250);
	LedOn(1);
	Delay(250);
	LedOn(2);
	Delay(250);
	LedOn(3);
	*/
	/*
	switch(ReadButton1()){
		case RELASED:
			IO1SET = LED0_bm;
		break;
		
		case PRESSED:
			IO1SET = LED1_bm;
		break;
	}
	*/
	/*
	switch (eKeyboardRead()){
		case BUTTON_0:
			IO1SET = LED0_bm;
		case BUTTON_1:
			IO1SET = LED1_bm;
		case BUTTON_2:
			IO1SET = LED2_bm;
		case BUTTON_3:
			IO1SET = LED3_bm;
		default:
			IO1SET = 0x0;
	}
	*/
	
}
