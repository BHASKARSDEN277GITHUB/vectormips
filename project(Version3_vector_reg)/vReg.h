//Vector Register File
#include<systemc.h>
SC_MODULE(vReg) {
	sc_in < bool > clock ; //clock
	sc_out < sc_uint<4> > r1 ;
	sc_out < sc_uint<4> > r2 ;

	void doitV(void);
	
	//construtor for this module
	SC_CTOR(vReg): r1("r1"),r2("r2") {
	SC_THREAD(doitV); //calling doit method
	sensitive << clock.neg();
	}
};

