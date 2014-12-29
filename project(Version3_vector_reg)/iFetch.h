//Instruction Fetch 
#include<systemc.h>
SC_MODULE(iFetch) {
//	sc_in < bool > clock ; //clock
	sc_out < sc_uint<4> > outP;
	
	void doitF(void);
	
	//construtor for this module
	SC_CTOR(iFetch): outP("outP") {
	SC_THREAD(doitF); //calling doit method
//	sensitive << clock;
	}
};

