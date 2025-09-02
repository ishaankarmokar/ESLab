//WAP to send logic high and logic 0 to the port pins p1.15 to p1.23
//Johnson Counter
#include<LPC17xx.h>
int main(){
	int i,x;
	LPC_PINCON -> PINSEL2 &= 0x3FFFFFFF;
	LPC_PINCON -> PINSEL3 &= 0xFFFF0000;
	LPC_GPIO1 -> FIODIR = 0x00FF8000;
	while(1){
		x = 0x00008000;
		for(i=0;i<9;i++){
			LPC_GPIO1 -> FIOSET = x;
			x = x<<1;
		}
		x=0x00008000;
		for(i=0;i<9;i++){
			LPC_GPIO1 -> FIOCLR = x;
			x = x<<1;
		}
	}
	return 0;
}
	 