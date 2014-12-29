//Instruction Fetch
#include"vReg.h"
#include<stdlib.h>

void vReg :: doitV(void) {
	sc_uint<4> a ;
	sc_uint<4> b ;
	int i=0;
		
	wait();
	while(i<8) {
		a=i;
		b=i;
		r1.write(a);
		r2.write(b);
		i++;
		wait();
	}
	

}

