#include <stdio.h> 
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <klee/klee.h>
#include <string.h>

char* laststate;
FILE* dumpfile;
int dummyinput;

int fstate = 0;

void set_input(int i) {
	dummyinput = i;
}

void state_e(char *string, int err) {
	char* statebuff = malloc(strlen(laststate) + 1024);
	if (!err) {
		if (fstate)
			sprintf(statebuff, "%s;%s", laststate, string);
		else
			sprintf(statebuff, "%s", string);
	}
	else {
		sprintf(statebuff, "%s", laststate);
	}
	fstate = 1;
	char buff[2 * strlen(laststate) + 1024];
	sprintf(buff, "%s %d %s %s", laststate, dummyinput, statebuff, string);
	fprintf(dumpfile, "%s\n", buff);
	laststate = statebuff;
}

void state(char *string) {
	state_e(string, 0);
}

void state_i(char *string, int i) {
	char buff[strlen(string) + 256];
	sprintf(buff, "%s%d", string, i);
	state_e(buff, 1);
}

void __VERIFIER_error(int i) {
	fprintf(stderr, "error_%d ", i);
	state_i("Error_", i);
	assert(0);
}

	// inputs
	int inputs[] = {2,5,1,3,4};

	void errorCheck();
	void calculate_output(int);
	void calculate_outputm1(int);
	void calculate_outputm2(int);
	void calculate_outputm3(int);
	void calculate_outputm4(int);
	void calculate_outputm5(int);
	void calculate_outputm6(int);
	void calculate_outputm7(int);
	void calculate_outputm8(int);
	void calculate_outputm9(int);
	void calculate_outputm10(int);
	void calculate_outputm11(int);
	void calculate_outputm12(int);
	void calculate_outputm13(int);
	void calculate_outputm14(int);

	 int a43  = 32;
	 int a56 = 6;
	 int a159  = 36;
	 int a136  = 34;
	 int a152 = 7;
	 int a193  = 34;
	 int a8 = 10;
	 int cf = 1;


	void errorCheck() {

	}
 void calculate_outputm1(int input) {
    if((a56 == 4 && (a193 == 33 && (a193 == 33 && (a56 == 4 && ((( cf==1  && (input == 5)) && a193 == 33) && a56 == 4)))))) {
    	cf = 0;
    	a56 = 6;
    	a43 = 34 ;
    	a193 = 34 ;
    	a152 = 7; 
    	 state("25"); 
    } 
}
 void calculate_outputm2(int input) {
    if((((a56 == 4 && ( cf==1  && (input == 4))) && a56 == 4) && (a193 == 33 && ((a193 == 33 && a193 == 33) && a56 == 4)))) {
    	cf = 0;
    	a152 = 6;
    	a193 = 34 ;
    	a56 = 6;
    	a8 = 6; 
    	 state("21"); 
    } 
}
 void calculate_outputm3(int input) {
    if(((a193 == 33 && ((a56 == 4 && (a193 == 33 && a193 == 33)) && a193 == 33)) && (( cf==1  && (input == 1)) && a56 == 4))) {
    	cf = 0;
    	a43 = 36 ;
    	a152 = 8; 
    	 state("25"); 
    } 
}
 void calculate_outputm4(int input) {
    if(((a193 == 32 && (a56 == 5 && (a193 == 32 && ((input == 4) &&  cf==1 )))) && ((a56 == 5 && a56 == 5) && a193 == 32))) {
    	cf = 0;
    	a56 = 4;
    	a193 = 33 ;
    	a159 = 32 ;
    	a152 = 4; 
    	 state("23"); 
    } 
    if((((a56 == 5 && ((input == 3) &&  cf==1 )) && a193 == 32) && (a56 == 5 && (a56 == 5 && (a193 == 32 && a56 == 5))))) {
    	cf = 0;
    	a43 = 35 ;
    	a56 = 4;
    	a193 = 33 ;
    	a152 = 8; 
    	 state("23"); 
    } 
}
 void calculate_outputm5(int input) {
    if(((a193 == 32 && (a56 == 5 && (a56 == 5 && (a193 == 32 && a56 == 5)))) && (a56 == 5 && ( cf==1  && (input == 3))))) {
    	cf = 0;
    	a193 = 33 ;
    	a56 = 4;
    	a43 = 32 ;
    	a152 = 8; 
    	 state("26"); 
    } 
}
 void calculate_outputm6(int input) {
    if((((a56 == 6 && ((a193 == 34 && a193 == 34) && a56 == 6)) && a193 == 34) && (a56 == 6 && ((input == 3) &&  cf==1 )))) {
    	cf = 0;
    	a193 = 33 ;
    	a159 = 35 ;
    	a56 = 4;
    	a152 = 4; 
    	 state("23"); 
    } 
}
 void calculate_outputm7(int input) {
    if(((a193 == 34 && ( cf==1  && (input == 1))) && ((((a193 == 34 && a193 == 34) && a193 == 34) && a193 == 34) && a193 == 34))) {
    	cf = 0;
    	a193 = 33 ;
    	a136 = 36 ;
    	a56 = 4;
    	a152 = 9; 
    	 state("23"); 
    } 
    if(((a193 == 34 && (a56 == 6 && (( cf==1  && (input == 4)) && a56 == 6))) && (a193 == 34 && (a56 == 6 && a193 == 34)))) {
    	cf = 0;
    	a56 = 4;
    	a193 = 33 ;
    	a136 = 36 ;
    	a152 = 9; 
    	 state("23"); 
    } 
}
 void calculate_outputm8(int input) {
    if((((a193 == 34 && (((input == 2) &&  cf==1 ) && a193 == 34)) && a193 == 34) && ((a193 == 34 && a56 == 6) && a193 == 34))) {
    	cf = 0;
    	a43 = 34 ; 
    	 state("25"); 
    } 
    if((((a193 == 34 && (a56 == 6 && (a56 == 6 && ((input == 4) &&  cf==1 )))) && a193 == 34) && (a193 == 34 && a56 == 6))) {
    	cf = 0;
    	a159 = 36 ;
    	a56 = 5;
    	a193 = 32 ;
    	a152 = 11; 
    	 state("19"); 
    } 
}
 void calculate_outputm9(int input) {
    if(((a193 == 34 && a56 == 6) && (a56 == 6 && (((a56 == 6 && ((input == 3) &&  cf==1 )) && a56 == 6) && a193 == 34)))) {
    	cf = 0;
    	a152 = 6;
    	a8 = 5; 
    	 state("26"); 
    } 
}
 void calculate_outputm10(int input) {
    if(((a56 == 4 && (a56 == 4 && a193 == 33)) && ((a193 == 33 && (((input == 4) &&  cf==1 ) && a193 == 33)) && a193 == 33))) {
    	cf = 0;
    	a136 = 36 ;
    	a152 = 9; 
    	 state("23"); 
    } 
    if(((((a193 == 33 && a193 == 33) && a56 == 4) && a56 == 4) && ((a56 == 4 && ( cf==1  && (input == 3))) && a56 == 4))) {
    	cf = 0;
    	a159 = 34 ;
    	a152 = 4; 
    	 state("24"); 
    } 
}
 void calculate_outputm11(int input) {
    if((((((input == 5) &&  cf==1 ) && a56 == 4) && a56 == 4) && (((a193 == 33 && a56 == 4) && a193 == 33) && a56 == 4))) {
    	cf = 0;
    	a43 = 34 ;
    	a193 = 34 ;
    	a56 = 6;
    	a152 = 7; 
    	 state("25"); 
    } 
}
 void calculate_outputm12(int input) {
    if(((a56 == 4 && ((a56 == 4 && a193 == 33) && a56 == 4)) && (a56 == 4 && (a193 == 33 && ( cf==1  && (input == 4)))))) {
    	cf = 0;
    	a43 = 34 ;
    	a193 = 32 ;
    	a56 = 5;
    	a152 = 5; 
    	 state("25"); 
    } 
}
 void calculate_outputm13(int input) {
    if(((a193 == 33 && (((a56 == 4 && a193 == 33) && a56 == 4) && a56 == 4)) && (((input == 3) &&  cf==1 ) && a56 == 4))) {
    	cf = 0;
    	a43 = 36 ;
    	a56 = 5;
    	a193 = 32 ;
    	a152 = 5; 
    	 state("25"); 
    } 
    if((((a193 == 33 && (a56 == 4 && a193 == 33)) && a56 == 4) && ((((input == 4) &&  cf==1 ) && a193 == 33) && a56 == 4))) {
    	cf = 0;
    	a43 = 36 ;
    	a56 = 5;
    	a193 = 32 ;
    	a152 = 5; 
    	 state("25"); 
    } 
    if((((((a193 == 33 && (a56 == 4 && ((input == 5) &&  cf==1 ))) && a193 == 33) && a56 == 4) && a193 == 33) && a193 == 33)) {
    	cf = 0;
    	a43 = 36 ;
    	a193 = 32 ;
    	a56 = 5;
    	a152 = 5; 
    	 state("25"); 
    } 
}
 void calculate_outputm14(int input) {
    if(((a193 == 32 && ((((input == 1) &&  cf==1 ) && a193 == 32) && a193 == 32)) && (a193 == 32 && (a56 == 5 && a56 == 5)))) {
    	cf = 0;
    	a43 = 36 ;
    	a152 = 5; 
    	 state("25"); 
    } 
}

 void calculate_output(int input) {
        cf = 1;

    if(((a56 == 4 && (a56 == 4 && a193 == 33)) && (a56 == 4 && (a56 == 4 && ((a152 == 4 &&  cf==1 ) && a56 == 4))))) {
    	if((((a159 == 32 &&  cf==1 ) && a193 == 33) && (a56 == 4 && (((a193 == 33 && a193 == 33) && a56 == 4) && a193 == 33)))) {
    		calculate_outputm1(input);
    	} 
    	if(((a193 == 33 && ((a56 == 4 && (a56 == 4 && a193 == 33)) && a193 == 33)) && (a193 == 33 && ( cf==1  && a159 == 34)))) {
    		calculate_outputm2(input);
    	} 
    	if(((a193 == 33 && (( cf==1  && a159 == 35) && a193 == 33)) && (a56 == 4 && (a56 == 4 && (a193 == 33 && a56 == 4))))) {
    		calculate_outputm3(input);
    	} 
    } 
    if(((a56 == 5 && ( cf==1  && a152 == 5)) && ((a193 == 32 && ((a56 == 5 && a193 == 32) && a56 == 5)) && a56 == 5))) {
    	if((((a193 == 32 && a193 == 32) && a56 == 5) && ((a193 == 32 && (( cf==1  && a43 == 34) && a193 == 32)) && a193 == 32))) {
    		calculate_outputm4(input);
    	} 
    	if(((((a193 == 32 && ( cf==1  && a43 == 36)) && a193 == 32) && a193 == 32) && ((a56 == 5 && a193 == 32) && a56 == 5))) {
    		calculate_outputm5(input);
    	} 
    } 
    if(((a56 == 6 && (a193 == 34 && ((a56 == 6 && a193 == 34) && a56 == 6))) && ((a152 == 6 &&  cf==1 ) && a56 == 6))) {
    	if(((a193 == 34 && (a56 == 6 && a193 == 34)) && (a193 == 34 && ((( cf==1  && a8 == 5) && a193 == 34) && a56 == 6)))) {
    		calculate_outputm6(input);
    	} 
    	if(((a56 == 6 && (a193 == 34 && ( cf==1  && a8 == 6))) && (a193 == 34 && (a56 == 6 && (a56 == 6 && a56 == 6))))) {
    		calculate_outputm7(input);
    	} 
    } 
    if(((a56 == 6 && ( cf==1  && a152 == 7)) && (a56 == 6 && (a193 == 34 && (a193 == 34 && (a56 == 6 && a193 == 34)))))) {
    	if(((((a56 == 6 && (a193 == 34 && a193 == 34)) && a56 == 6) && a193 == 34) && (a56 == 6 && (a43 == 32 &&  cf==1 )))) {
    		calculate_outputm8(input);
    	} 
    	if(((a56 == 6 && (a193 == 34 && (a56 == 6 && a56 == 6))) && (((a43 == 34 &&  cf==1 ) && a56 == 6) && a193 == 34))) {
    		calculate_outputm9(input);
    	} 
    } 
    if((((a193 == 33 && a193 == 33) && a56 == 4) && ((a193 == 33 && (a193 == 33 && ( cf==1  && a152 == 8))) && a193 == 33))) {
    	if((((a193 == 33 && ((a56 == 4 && ( cf==1  && a43 == 32)) && a56 == 4)) && a56 == 4) && (a193 == 33 && a193 == 33))) {
    		calculate_outputm10(input);
    	} 
    	if(((a56 == 4 && (a193 == 33 && (a43 == 35 &&  cf==1 ))) && ((a56 == 4 && (a56 == 4 && a193 == 33)) && a56 == 4))) {
    		calculate_outputm11(input);
    	} 
    	if((((a43 == 36 &&  cf==1 ) && a193 == 33) && (((a193 == 33 && (a193 == 33 && a56 == 4)) && a193 == 33) && a56 == 4))) {
    		calculate_outputm12(input);
    	} 
    } 
    if(((a56 == 4 && a56 == 4) && (a56 == 4 && ((a193 == 33 && (( cf==1  && a152 == 9) && a193 == 33)) && a56 == 4)))) {
    	if((((a193 == 33 && (a56 == 4 && a193 == 33)) && a193 == 33) && (a193 == 33 && (( cf==1  && a136 == 36) && a193 == 33)))) {
    		calculate_outputm13(input);
    	} 
    } 
    if(((a193 == 32 && (a193 == 32 && (( cf==1  && a152 == 11) && a193 == 32))) && (a56 == 5 && (a193 == 32 && a56 == 5)))) {
    	if((a193 == 32 && (a193 == 32 && (a56 == 5 && ((((a159 == 36 &&  cf==1 ) && a56 == 5) && a56 == 5) && a193 == 32))))) {
    		calculate_outputm14(input);
    	} 
    } 
    errorCheck();
	if (cf == 1) {
		fprintf(stderr, "Invalid input: %d\n", input);
		state_i("Invalid_input_", input);
	}
 }

 int main()
 {

	 int length = 20;
	 int program[length];
	 klee_make_symbolic(program, sizeof(program), "program");
	 dumpfile = fopen("statedump", "a");
	 laststate = "";
	 // main i/o-loop
	 for (int i = 0; i < length; ++i) {
		 // read input
		 int input = program[i];
		 set_input(input);
		 // read input 
		 // operate eca engine
        if((input != 2) && (input != 5) && (input != 1) && (input != 3) && (input != 4))
          return 0;
        calculate_output(input);
    }
}
