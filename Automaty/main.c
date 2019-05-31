#include <LPC21xx.H>
#include "led.h"
#include "keybord.h"

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
				if(eKeyboardRead()==BUTTON_0){
					eLedState = BreakStep;
				}
				break;
			case(BreakStep):
				if(eKeyboardRead()==BUTTON_1) {
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
				if(eKeyboardRead()==BUTTON_1){
					eLedState = BreakStep;
				}
				break;
			case(LeftStep):
				LedStepLeft();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = BreakStep;
				}
				break;
			case(BreakStep):
				if(eKeyboardRead()==BUTTON_2){
					eLedState = LeftStep;
				}		
				if(eKeyboardRead()==BUTTON_0){
					eLedState = RightStep;
				}		
		}
		Delay(100);
	}
}

int main(){
	LedInite();
	LeftRightStep();


}
