#include <LPC21xx.H>
#include "keybord.h"

#define BUTT0_bm (1<<4)
#define BUTT1_bm (1<<5)
#define BUTT2_bm (1<<6)
#define BUTT3_bm (1<<7)

enum KeyboardState eKeyboardRead(){
	
		if((IO0PIN&BUTT0_bm) == 0){
			return BUTTON_0;
		}
		if((IO0PIN&BUTT1_bm) == 0){ 
		}
		if((IO0PIN&BUTT2_bm) == 0){ 
			return BUTTON_2;
		}
		if((IO0PIN&BUTT3_bm) == 0){
			return BUTTON_3;
		}
		else{
			return RELASED;
		}
}

void KeyboardInit() {
	
		IO0DIR = IO0DIR | 0xF0;
}
