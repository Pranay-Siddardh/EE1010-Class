//Code BY Pranay
//Date 7-10-26
#include <stdio.h>

int main(void){
	int a = 8;
	int b = 10;

	// When you are using the && any non zero is converted into 1 and zero is converted to 0 like a bool type cast
	// 8 in binary is 1000
	// 10 in binary is 1010
	
	int doband = 8&&10 ; // ands the type casted of 8 and 10 implies implis 1 anded with 1 which is 1  
	int singand = 8&10 ; //ands every bit of the binary implies that 1000 == 8 is the result if we and every bit of 8 and 10
	printf("The double and of 8,10 is %d\n",doband);
	printf("The single and of and and 10 is %d\n",singand);
}
