//ALU
#include"alu.h"
#include<stdlib.h>

void alu :: doitA(void) {
	sc_uint<4> temp_operation, temp_in1, temp_in2, temp_cycle;
	sc_uint<8> temp;
	sc_uint<8> v3[8]; //for memory write

	wait();
	//index=0;
	int index=0;
	int previous=500;

	while(true) {

		temp_in1 = in1.read();
		temp_in2 = in2.read();
		temp_operation = operation.read();
		temp_cycle = cycle.read();
		
		if(temp_cycle>=5) {
			 cout<<"-> ALU reached (Cycle"<<temp_cycle<<")"<<"       ";
			 cout<<"v3["<<index-2<<"] = "<<v3[index-2]<<" Written in cycle "<<temp_cycle<<endl;
		} else {
			 cout<<"-> ALU reached (Cycle"<<temp_cycle<<")"<<endl;
		}
//		cout<<temp_in1<<temp_in2<<temp_operation<<temp_cycle<<endl;
	
	
		if(temp_operation == 0&&index<=7) {
			temp = temp_in1 + temp_in2;
			v3[index]=temp;
			previous=temp;
			cout<<"v1["<<index<<"] +"<<"v2["<<index<<"] = "<<temp<<"	"<<endl;
	
	//		cout<<"v3["<<index<<"] = "<<previous<<" Written in cycle endl;

			index++;
			if(temp_cycle==10) {
				temp_cycle++;
				int k;
				for(k=6;k<8;k++) {
					 cout<<"                               ";
					cout<<"v3["<<index-2<<"] = "<<v3[index-2]<<" Written in cycle "<<temp_cycle<<endl;
					index++;
					temp_cycle++;
				}
				break;
			}

		}else if(temp_operation==1&&index<=7) { //subtract case
			temp = temp_in1 - temp_in2;
                        v3[index]=temp;
                        previous=temp;
                        cout<<"v1["<<index<<"] +"<<"v2["<<index<<"] = "<<temp<<"        "<<endl;

        //              cout<<"v3["<<index<<"] = "<<previous<<" Written in cycle endl;

                        index++;
                        if(temp_cycle==10) {
                                temp_cycle++;
                                int k;
                                for(k=6;k<8;k++) {
                                         cout<<"                               ";
                                        cout<<"v3["<<index-2<<"] = "<<v3[index-2]<<" Written in cycle "<<temp_cycle<<endl;
                                        index++;
                                        temp_cycle++;
                                }
                                break;

                        }

		} else if(temp_operation==2&&index<=7) { //subtract case
                        temp = temp_in1 * temp_in2;
                        v3[index]=temp;
                        previous=temp;
                        cout<<"v1["<<index<<"] +"<<"v2["<<index<<"] = "<<temp<<"        "<<endl;

        //              cout<<"v3["<<index<<"] = "<<previous<<" Written in cycle endl;

                        index++;
                        if(temp_cycle==10) {
                                temp_cycle++;
                                int k;
                                for(k=6;k<8;k++) {
                                         cout<<"                               ";
                                        cout<<"v3["<<index-2<<"] = "<<v3[index-2]<<" Written in cycle "<<temp_cycle<<endl;
                                        index++;
                                        temp_cycle++;
                                }
                                break;

                        }

                } else if(temp_operation==3&&index<=7) { //subtract case
                        temp = temp_in1 / temp_in2;
                        v3[index]=temp;
                        previous=temp;
                        cout<<"v1["<<index<<"] +"<<"v2["<<index<<"] = "<<temp<<"        "<<endl;

        //              cout<<"v3["<<index<<"] = "<<previous<<" Written in cycle endl;

                        index++;
                        if(temp_cycle==10) {
                                temp_cycle++;
                                int k;
                                for(k=6;k<8;k++) {
                                         cout<<"                               ";
                                        cout<<"v3["<<index-2<<"] = "<<v3[index-2]<<" Written in cycle "<<temp_cycle<<endl;
                                        index++;
                                        temp_cycle++;
                                }
                                break;

                        }

                } else {
			cout<<"Instruction was not decoded properly"<<endl;
			break;
		}
		wait();
	}
   
}
/*
//sc_main method
int sc_main(int argc, char* argv[]) {
	return(0);
}
*/

