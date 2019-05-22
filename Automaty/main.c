#include <LPC21xx.H>
#include "led.h"
#define BUTT0_bm 0x10
#define BUTT1_bm 0x20
#define BUTT2_bm 0x40

void Delay(int iIloscIteracji){
	
	int Couter;
	
	for(Couter = 0; Couter != (iIloscIteracji * 12000); Couter++ ){ }
}

void LedMove(){
	
	enum LedState {LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	
	while(1){
		switch (eLedState){
			case LED_LEFT:
				eLedState = LED_RIGHT;
				LedStepRight();
				break;
			case LED_RIGHT:
				eLedState = LED_LEFT;
				LedStepLeft();
				break;
		}
		Delay(1);
	}
}

/*
void WaveStep(){
	
	enum LedState {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
	enum LedState eLedState = STATE0;

	while(1){
		switch(eLedState){
			case STATE0:
				eLedState = STATE1;
				LedStepLeft();
				break;
			case STATE1:
				eLedState = STATE2;
				LedStepLeft();
				break;
			case STATE2:
				eLedState = STATE3;
				LedStepLeft();
				break;
			case STATE3:
				eLedState = STATE4;
				LedStepRight();
				break;
			case STATE4:
				eLedState = STATE5;
				LedStepRight();
				break;
			case STATE5:
				eLedState = STATE0;
				LedStepRight();
		}
		Delay(100);
	}
}
*/

void WaveStep(){
	
	enum LedState {StepLeft, StepRight};
	enum LedState eLedState = StepLeft;
	unsigned int uiStepCounter;

	while(1){
		switch(eLedState){
			case(StepLeft):
				LedStepLeft();
				uiStepCounter ++;
				if(uiStepCounter % 3 == 0){
					eLedState = StepRight;
				}
				break;
			case(StepRight):
				LedStepRight();
				uiStepCounter ++;
				if(uiStepCounter % 3 == 0){
					eLedState = StepLeft;
				}
				break;
		}
		Delay(100);
	}
}

void RightWithStop(){
	
	enum LedState {RightStep, StopStep};
	enum LedState eLedState = RightStep;
	unsigned int uiStepCounter;
	
	while(1){
		switch(eLedState){
			case(RightStep):
				LedStepRight();
				uiStepCounter ++;
				if(uiStepCounter % 3 == 0) {
					eLedState = StopStep;
				}
				break;
			case(StopStep):
				if((IO0PIN&0x10) == 0){
					eLedState = RightStep;
				}
				break;
		}
		Delay(100);
	}
}

void InfiStepRight(){
	
	enum LedState {RightStep, BreakStep};
	enum LedState eLedState = RightStep;

	while(1){
		switch(eLedState){
			case(RightStep):
				LedStepRight();
				if((IO0PIN%BUTT0_bm)==0){
					eLedState = BreakStep;
				}
				break;
			case(BreakStep):
				if((IO0PIN%BUTT1_bm)==0) {
					eLedState = RightStep;
				}
		}
		Delay(100);
	}
}

void LeftRightStep(){
	
	enum LedState {RightStep, LeftStep, BreakStep};
	enum LedState eLedState = BreakStep;

	while(1){
		switch(eLedState){
			case(RightStep):
				LedStepRight();
				if((IO0PIN&BUTT0_bm)==0){
					eLedState = BreakStep;
				}
				if((IO0PIN&BUTT1_bm)==0){
					eLedState = BreakStep;
				}
				break;
			case(LeftStep):
				LedStepLeft();
				if((IO0PIN&BUTT2_bm)==0){
					eLedState = BreakStep;
				}
				if((IO0PIN&BUTT1_bm)==0){
					eLedState = BreakStep;
				}
				break;
			case(BreakStep):
				if((IO0PIN&BUTT0_bm)==0){
					eLedState = LeftStep;
				}		
				if((IO0PIN&BUTT2_bm)==0){
					eLedState = RightStep;
				}		
		}
		Delay(10);
	}
}

int main(){
	InfiStepRight();
}
