#include <LPC21xx.H>
#include "keybord.h"
#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

enum KeyboardState eKeyboardRead(){
	
		if(IO0SET == 0x10){
			return BUTTON_0;
		}
		if(IO0SET == 0x20){
			return BUTTON_1;
		}
		if(IO0SET == 0x40){
			return BUTTON_2;
		}
		if(IO0SET == 0x80){
			return BUTTON_3;
		}
		else{
			return RELASED;
		}
}

void KeyboardInit() {
	
		IO0DIR = IO0DIR | 0xF0;
}
