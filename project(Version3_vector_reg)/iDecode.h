//Instruction Decode
#include<systemc.h>
SC_MODULE(iDecode) {
	sc_in < bool > clock;
	sc_in < sc_uint<4> > operation;
 	sc_in < sc_uint<4> > r1;
	sc_in < sc_uint<4> > r2;

	sc_out < sc_uint<4> > out1 ; //elements of first vector one by one
	sc_out  < sc_uint<4> > out2; //elements of second vector one by one
	sc_out < sc_uint<4> > out_operation;
	sc_out < sc_uint<4> > out_cycle;

	void doitD(void);
	SC_CTOR(iDecode)
	{
		SC_THREAD(doitD);
		sensitive << clock.pos();
	}
};

