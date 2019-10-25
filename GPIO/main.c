#include <LPC21xx.H>

#define LED0_bm 0x00040000 
#define LED1_bm 0x00080000 
#define LED2_bm 0x00100000 
#define LED3_bm 0x00200000 

#define BUTT0_bm 0x10
#define BUTT1_bm 0x20
#define BUTT2_bm 0x40
#define BUTT3_bm 0x80

void Delay(int iIloscIteracji){
	
	int Couter;
	
	for(Couter = 0; Couter != (iIloscIteracji * 12000); Couter++ ){ }
}

void LedInite (){
	
	IO1DIR = IO1DIR |(LED0_bm | LED1_bm | LED2_bm | LED3_bm); // Ustawia bez zmiany pozostalych rejestrów porty odpowadjace za diody 0,1,2,3 na wyjsciowe
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;   // W przypadku gdyby diody byly wczesniej wlaczne gasi je 
	IO1SET = LED0_bm;		// Zapala diode nr 0
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
		default:
			break;
	}
}
 //git test
enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(){
	
		if((IO0PIN&BUTT0_bm) == 0){
			return BUTTON_0;
		}
		if((IO0PIN&BUTT1_bm) == 0){ //Gdy przycisk wcisniety zwraca 0x00 a puszczony 0x20
			return BUTTON_1;
		}
		if((IO0PIN&BUTT2_bm) == 0){  //Gdy przycisk wcismiety zwraca 0x00 a puszczony zwraca 0x40
			return BUTTON_2;
		}
		if((IO0PIN&BUTT3_bm) == 0){//Gdy przycisk wcismiety zwraca 0x00 a puszczony zwraca 0x80
			return BUTTON_3;
		}
		else{
			return RELASED;
		}
}

void KeyboardInit() {
	
		IO0DIR = IO0DIR & ~(BUTT0_bm |BUTT1_bm | BUTT2_bm | BUTT3_bm);
}

//xd


enum LedDirection {LEFT, RIGHT};

void LedStep (enum LedDirection Direction){
		static unsigned int uiStepOper = 4;
	
		switch(Direction) {
			case(LEFT):
				uiStepOper ++ ;
				break;
			case(RIGHT):
				uiStepOper -- ;
		}
		LedOn(uiStepOper % 4);
	
}

void LedStepLeft() {
	LedStep(LEFT);
}

void LedStepRight() {
	LedStep(RIGHT);
}

enum stan {stan1, stan2};
enum stan ObecnyStan = stan1;

int main(){
	LedInite ();
	Delay(100);
	while(1){
		static int Counter;
		switch(ObecnyStan){
			case(stan1):
				LedStepLeft();
				Counter++;
				if((Counter&3)==0){
					ObecnyStan = stan2;
				}
				Delay(100);
				break;
			case(stan2):
				LedStepRight();
				Counter++;
				if((Counter&3)==0){
					ObecnyStan = stan1;
				}
				Delay(100);
		}
	}
}
