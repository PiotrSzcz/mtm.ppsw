#include "led.h"
#include "keybord.h"

void Delay(int iIloscIteracji){
	
	int Couter;
	
	for(Couter = 0; Couter != (iIloscIteracji * 1100); Couter++ ){ }
}

int main() {
	while(1){
		LedStepLeft();
		Delay(100);
	}
}
