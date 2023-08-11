#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ann_matirx.cpp"
#include "activation.c"
 
int accuracy(int no_test_case, int * predict);

int main()
{
    FILE* ptr, *ptr2;

	double * mptr, * mptr2, * mptr3, * res_mul, *res_trans, *res_add;
	int sig_fn;
	int i,j, op;
        char str[50];
	int no_test_case=1000;
	char buff[255];
	double valid, ready; //a,b,c;
	int predicted_output[no_test_case];

// Var to store ANN information
	int no_layers=0; //2 
	int no_inputs=0; //2
	int no_neurons[20]; //2 and 1 are no of neurons in each layer, (no_neurons[0]==2), (no_neurons[1]==1)
	double wt_L1[2][4];
	double wt_L2[4][2];
	double wt_L3[2][1];
	double bias_L1[4][1];
	double bias_L2[2][1];
	double bias_L3;
	double input_m[2][1];
	double testcase[no_test_case][2];
	double output[no_test_case];
	int count=0;
	float accuracy=0;




// reading ANN starts
    ptr = fopen("ann_weight_ready_valid_96.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    //printf("content of this file are \n");
 
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#layers"))
		{
	//	printf("Inside layers\n");
		fscanf(ptr,"%d",&no_layers);
		//printf("no_layers = %d	 \n",no_layers);
		}

	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#inputs"))
		{
	//	printf("Inside inputs\n");
		fscanf(ptr,"%d",&no_inputs);
	//	printf("no_inputs = %d	 \n",no_inputs);
		}


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#neurons_L1"))
		{
	//	printf("Inside neurons_L1\n");
		fscanf(ptr,"%d",&no_neurons[0]);
	//	printf("no_neurons[0] = %d	 \n",no_neurons[0]);
		}


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#neurons_L2"))
		{
	//	printf("Inside neurons_L2\n");
		fscanf(ptr,"%d",&no_neurons[1]);
	//	printf("no_neurons[1] = %d	 \n",no_neurons[1]);
		}

	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#neurons_L3"))
		{
	//	printf("Inside neurons_L2\n");
		fscanf(ptr,"%d",&no_neurons[2]);
	//	printf("no_neurons[1] = %d	 \n",no_neurons[1]);
		}


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L1_wt"))
		{
		//printf("Inside L1_wt\n");
		fscanf(ptr,"%lf \b %lf \b %lf \b %lf",&wt_L1[0][0], &wt_L1[0][1], &wt_L1[0][2], &wt_L1[0][3]);
		fscanf(ptr,"%lf \b %lf \b %lf \b %lf",&wt_L1[1][0], &wt_L1[1][1], &wt_L1[1][2], &wt_L1[1][3]);
		//printf("%lf \t %lf \t %lf \t %lf\n",wt_L1[0][0], wt_L1[0][1],wt_L1[0][2], wt_L1[0][3]);
		//printf("%lf \t %lf \t %lf \t %lf\n",wt_L1[1][0], wt_L1[1][1],wt_L1[1][2], wt_L1[1][3]);
		}


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L1_b"))
		{
		//printf("Inside L1_b\n");
		fscanf(ptr,"%lf \b %lf \b %lf \b %lf",&bias_L1[0][0], &bias_L1[1][0], &bias_L1[2][0], &bias_L1[3][0]);
		//printf("%lf \t %lf \t %lf \t %lf\n",bias_L1[0][0], bias_L1[1][0], bias_L1[2][0], bias_L1[3][0]);
		}

	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L2_wt"))
		{
		//printf("Inside L2_wt\n");
		fscanf(ptr,"%lf \b %lf",&wt_L2[0][0], &wt_L2[0][1]);
		fscanf(ptr,"%lf \b %lf",&wt_L2[1][0], &wt_L2[1][1]);
		fscanf(ptr,"%lf \b %lf",&wt_L2[2][0], &wt_L2[2][1]);
		fscanf(ptr,"%lf \b %lf",&wt_L2[3][0], &wt_L2[3][1]);	
		//printf("%lf \t %lf\n",wt_L2[0][0], wt_L2[0][1]);
		//printf("%lf \t %lf\n",wt_L2[1][0], wt_L2[1][1]);
		//printf("%lf \t %lf\n",wt_L2[2][0], wt_L2[2][1]);
		//printf("%lf \t %lf\n",wt_L2[3][0], wt_L2[3][1]);
		}

	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L2_b"))
		{
		//printf("Inside L2_b\n");
		fscanf(ptr,"%lf \b %lf", &bias_L2[0][0], &bias_L2[1][0]);
		//printf("%lf \t %lf\n",bias_L2[0][0], bias_L2[1][0]);
	//	printf("%lf \n",bias_L2);
		}

	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L3_wt"))
		{
		//printf("Inside L3_wt\n");
		fscanf(ptr,"%lf",&wt_L3[0][0]);
		fscanf(ptr,"%lf",&wt_L3[1][0]);
		//printf("%lf \t %lf\n",wt_L3[0][0], wt_L3[1][0]);
		}


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L3_b"))
		{
		//printf("Inside L3_b\n");
		fscanf(ptr,"%lf",&bias_L3);
		//printf("%lf \n",bias_L3);
		}

    fclose(ptr);
// reading and storing ANN model is completed




// reading input
    ptr2 = fopen("2.txt", "r");
 
    if (NULL == ptr2) {
        printf("file can't be opened \n");
    }

for(i=0;i<no_test_case;i++)
{
fscanf(ptr2,"%lf %lf",&valid,&ready);
//printf("%lf \t %lf\t\t",valid,ready);
testcase[i][0]=valid;
testcase[i][1]=ready;
//printf("%lf \t %lf\n",testcase[no_test_case][0],testcase[no_test_case][1]);
}

for(i=0;i<no_test_case;i++)
{
if(i == (no_test_case-1))
	{
	output[i] = 0;
	}
else
	{
	
	if( (testcase[i][0] == 1) && (testcase[i+1][0] == 0))
		{
		output[i]=1; //falling edge predicted
		}
	else
		{
		output[i]=0; //falling edge not predicted
		}
	//if(testcase[i][0] == 0)
	//	{
	//	ouput[i]=0;
	//	}
	}
}

//print input and output
for(i=0;i<no_test_case;i++)
{
//printf("%lf \t %lf \t\t %lf\n",testcase[i][0],testcase[i][1],output[i]);
}

//prediction
for(i=0;i<no_test_case;i++)
{
double * input_p, * wt_L1_p, * wt_L1_Tp, * bias_L1_p, * wt_L2_p, * wt_L2_Tp, * bias_L2_p, * wt_L3_p, * wt_L3_Tp, * bias_L3_p;// *res_add;

//Leyer1////////////////////////////////////
//2x1 Matrix to store input
	double input_m[2][1];
	input_m[0][0] = testcase[i][0];
	input_m[1][0] = testcase[i][1];
	input_p = (double *)input_m;
//transpose of wt_L1
	wt_L1_p = (double *)wt_L1;
	wt_L1_Tp = matrix_trans(2,4, wt_L1_p);
//Multiplication
	res_mul = matrix_mul(4, 2, wt_L1_Tp, 2, 1, input_p);
//add bias
	bias_L1_p = (double *)bias_L1;
	res_add = matrix_add(4, 1, res_mul, 4, 1, bias_L1_p);

//apply Relu activation function
//and get a 4x1 Matrix as input to the next layer 
	//relud(2.7) 2x1 [0][0]=*res_add, [1][0] = *(res_add+1) 
	* (res_add ) = relud( *(res_add ) );
	* (res_add + 1 ) = relud( *(res_add + 1 ) );
	* (res_add + 2 ) = relud( *(res_add + 2 ) );
	* (res_add + 3 ) = relud( *(res_add + 3 ) );
	//print_matrix(4, 1, res_add);
	// res_add is input to next layer

//Leyer2////////////////////////////////////
//transpose of wt_L2
	wt_L2_p = (double *)wt_L2;
	wt_L2_Tp = matrix_trans(4,2, wt_L2_p);
//Multiplication
	res_mul = matrix_mul(2, 4, wt_L2_Tp, 4, 1, res_add);
//add bias
	bias_L2_p = (double *)bias_L2;
	res_add = matrix_add(2, 1, res_mul, 2, 1, bias_L2_p);

//apply Relu activation function
//and get a 2x1 Matrix as input to the next layer 
	//relud(2.7) 2x1 [0][0]=*res_add, [1][0] = *(res_add+1) 
	* (res_add ) = relud( *(res_add ) );
	* (res_add + 1 ) = relud( *(res_add + 1 ) );
	//print_matrix(2, 1, res_add);
	// res_add is input to next layer

//Leyer3//////////////////////////////
//2x1 Matrix as input from previous layer
//transpose of wt_L2
	wt_L3_p = (double *)wt_L3;
	wt_L3_Tp = matrix_trans(2,1, wt_L3_p);
//Multiplication
	res_mul = matrix_mul(1, 2, wt_L3_Tp, 2, 1, res_add);
//add bias
	//bias_L2_p = (double *)bias_L2;
	*(res_mul) = *(res_mul) + bias_L3;
	 //print_matrix(1, 1, res_mul);
//apply Sigmoid activation function

predicted_output[i] = sigmoid(*(res_mul));
printf("**********%lf sigmoid=%d",*(res_mul),predicted_output[i]);
}//End for 
fclose(ptr2);
//print input and output
for(i=0;i<no_test_case;i++)
{
printf("%lf \t %lf \t %lf \t\t %d\n",testcase[i][0],testcase[i][1],output[i],predicted_output[i]);
if((int)output[i]==predicted_output[i])
	count++;
}

accuracy=(float)count/(float)no_test_case;
//printf("Accuracy=%f\n, count=%d, no_test_case=%d",accuracy,count,no_test_case);
printf("Accuracy=%f\n",accuracy);
//accuracy(no_test_case, predicted_output);
}
//end of main

//////////////////////////////////////////////////////////
//Calculating accuracy
int accuracy(int no_test_case, int * predict)
{
FILE* ptr3;
int a,b,c,i,j;
int count=0, correct=0;
double accuracy;
// displaying input and output
    ptr3 = fopen("apb2_1slave.txt", "r");
 
    if (NULL == ptr3) {
        printf("file can't be opened \n");
    }

//pritning input and output
for(i=0;i<no_test_case;i++)
	{
	fscanf(ptr3,"%d %d %d",&a,&b,&c);
	printf("%d %d %d\n",a,b,*(predict+i));
	if(i>0 && i<(no_test_case-1))
		{
		count++;
		if( (b == *(predict+i-1)) )
			correct++;
		}	
	}
accuracy = correct/count;
//printf("count=%d, correct=%d accuracy=%lf\n",count,correct,accuracy);
printf("accuracy=%lf\n",accuracy);
}

