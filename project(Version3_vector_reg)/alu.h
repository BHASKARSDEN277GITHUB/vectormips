//ALU
#include<systemc.h>
SC_MODULE(alu) {
	sc_in < bool > clock;
	sc_in < sc_uint<4> > operation;
	sc_in < sc_uint<4> > in1;
	sc_in < sc_uint<4> > in2;
	sc_in < sc_uint<4> > cycle;


	void doitA(void);

	SC_CTOR(alu) {
		SC_THREAD(doitA);
		sensitive << clock.neg();
	}
};

