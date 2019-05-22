#include <LPC21xx.H>
#include "led.h"
#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

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

void LedStepLeft() {
	LedStep(LEFT);
}

void LedStepRight() {
	LedStep(RIGHT);
}

