#include<LPC17xx.h>
int main(){
	unsigned long i;
	LPC_PINCON -> PINSEL0 = 0;
	LPC_GPIO0 -> FIODIR = 0xFF <<4;
	while(1){
		LPC_GPIO0 -> FIOSET = 0xFF <<4;
		for(i=0;i<200000;i++);
		LPC_GPIO0 -> FIOCLR = 0xFF <<4;
		for(i=0;i<200000;i++);
	}
}
