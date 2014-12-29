//Instruction Fetch
#include"iFetch.h"
#include<stdlib.h>

void iFetch :: doitF(void) {
	/*
	Mappings for instructions
	ADD-0
	SUB-1
	MUL-2
	DIV-3
	Add more mappings here 
	*/
	int b ;	
	cout<<"Enter Instruction code"<<endl;
	cout<<"ADD-0\nSUB-1\nMUL-2\nDIV-3"<<endl;
	cin>>b;

	//variable declaration here
	sc_uint<4> a;
	cout<<"-> Instruction Fetch Reached (Cycle 1)"<<endl;
	a=b;
//	a=0; //case for ADD 
	outP.write(a);

}
/*
int sc_main(int argc , char ** argv) {
	iFetch obj("");
	obj.doit();
	return 0;
}
*/

