#include<LPC17xx.h>
int main(){
	unsigned long x,count,j;
	count = 0;
	LPC_PINCON -> PINSEL0 = 0;
	LPC_PINCON -> PINSEL1 = 0;
	LPC_GPIO0 -> FIODIR = 0xFF << 4 | 0x0 << 21;
	while(1){
		x = LPC_GPIO0 -> FIOPIN  & 0x1 << 21 ;
		if(!x){
			count = (count +1)%256;
		}
		LPC_GPIO0 -> FIOPIN = count << 4;
		for(j=0;j<2500000;j++);
	}
}
	