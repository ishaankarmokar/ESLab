//port pins p1.15 to p1.22
//Johnson Counter
#include<LPC17xx.h>
int main(){
	int i,x,j;
	LPC_PINCON -> PINSEL0 &= 0;
	LPC_PINCON -> PINSEL1 &= 0;
	LPC_GPIO0 -> FIODIR = 0xFF<<15;
	while(1){
		x = 0x1 <<15;
		for(i=0;i<9;i++){
			LPC_GPIO0 -> FIOSET = x;
			for(j=0;j<2500000;j++);
			x = x<<1;
		}
		x=0x1 <<15;
		for(i=0;i<9;i++){
			LPC_GPIO0 -> FIOCLR = x;
			for(j=0;j<2500000;j++);
			x = x<<1;
		}
	}
	return 0;
}
	 