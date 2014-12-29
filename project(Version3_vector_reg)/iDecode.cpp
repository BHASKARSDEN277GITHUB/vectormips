//Instruction Decode
#include"iDecode.h"
#include<stdlib.h>
#include<fstream>
#include<iostream>

void iDecode :: doitD(void) {
	sc_uint<4> a,b, temp_operation;
	
	int i,j,count=2;
	/*
	for(i=0;i<8;i++) {

		a[i] =i+1;
	}
	for(i=0;i<8;i++) {
		b[i]=a[i]+i;
	}
	*/

	wait();

//	while(true) {
    
		temp_operation = operation.read();

		cout<<"-> Instruction Decode reached (Cycle 2) :"<<temp_operation<<endl;
		for(j=0;j<8;j++) {
			a=r1.read();
			b=r2.read();
//			cout<<"Value of a: "<<a<<" Value of b: "<<b<<endl;
			count++;
			out1.write(a);//from vector1
			out2.write(b);//from vector2
			out_operation.write(temp_operation);
			out_cycle.write(count);
			//cout << "cycle 2 \n";
			wait();
		}
//	}
}


