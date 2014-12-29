#include<systemc.h>
#include"iFetch.h"
#include"iDecode.h"
#include"alu.h"
#include"vReg.h"
#include<cstdlib>


int sc_main(int argv,char **argc) {

	//signals
	sc_clock clk("clock",20,SC_NS);
	sc_signal < sc_uint<4> > fetch_op,decode_op,decode_out1,decode_out2,decode_cycle , r1,r2;


	//creating objects
	iFetch fetch("iFetch");
	iDecode decode("iDecode");
	alu al("alu");
	vReg v("vReg");

	//connecting signals
//	fetch.clock(clk);
	fetch.outP(fetch_op);
	decode.clock(clk);
	decode.operation(fetch_op);
	decode.out1(decode_out1);
	decode.out2(decode_out2);
	decode.out_operation(decode_op);
	decode.out_cycle(decode_cycle);	
	decode.r1(r1);
	decode.r2(r2);
	al.clock(clk);
	al.operation(decode_op);	
	al.in1(decode_out1);
	al.in2(decode_out2);
	al.cycle(decode_cycle);
	v.clock(clk);
	v.r1(r1);
	v.r2(r2);

	
	
	//to get output
	sc_start(500,SC_NS);
	return 0;
}
