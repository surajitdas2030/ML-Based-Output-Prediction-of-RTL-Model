#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ann_matirx.cpp"
#include "activation.c"
 
//int accuracy(int no_test_case, int * predict);

int main()
{
    FILE* ptr, *ptr2;

	double * mptr, * mptr2, * mptr3, * res_mul, *res_trans, *res_add;
	int sig_fn;
	int i,j,k,op; 
	double d1,d2,d3,d4,d5,d6,d7,d8,e,f;
        char str[50], str1[8];
	int no_test_case=100;
	char buff[1000];
	double a,b,c;
	int predicted_output[no_test_case][8];
	int input[no_test_case][10];
	int count1=0, correct1=0,macthing;
	float accuracy1=0;

// Var to store ANN information
	int no_layers=0; //2 
	int no_inputs=0; //2
	int no_neurons[20]; //2 and 1 are no of neurons in each layer, (no_neurons[0]==2), (no_neurons[1]==1)
	double wt_L1[10][10];
	double wt_L2[10][10];
	double wt_L3[10][8];
	double bias_L1[10][1];
	double bias_L2[10][1];
	double bias_L3[8][1];

//inputs for shift reg
	double input_m[10][1];
	double input_m1[10][1];
	double input_m2[10][1];
	

	


// reading ANN starts
    ptr = fopen("ann_weight_shift8.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    //printf("content of this file are \n");
 
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#layers"))
		{
		//printf("Inside layers\n");
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
	//	printf("Inside neurons_L3\n");
		fscanf(ptr,"%d",&no_neurons[2]);
	//	printf("no_neurons[1] = %d	 \n",no_neurons[1]);
		}



	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L1_wt"))
		{
		for(i=0;i<10;i++)
			{
			
			fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&wt_L1[i][0], &wt_L1[i][1],&wt_L1[i][2], &wt_L1[i][3],&wt_L1[i][4], &wt_L1[i][5],&wt_L1[i][6], &wt_L1[i][7],&wt_L1[i][8], &wt_L1[i][9]);
			}
	printf("Weight1 *************\n");
	for(i=0;i<10;i++)
			{
			printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf\n",wt_L1[i][0], wt_L1[i][1],wt_L1[i][2], wt_L1[i][3],wt_L1[i][4], wt_L1[i][5],wt_L1[i][6], wt_L1[i][7],wt_L1[i][8], wt_L1[i][9]);
			}



		} //if


	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L1_b"))
		{
	//	printf("Inside L1_b\n");
	//	fscanf(ptr,"%lf \b %lf",&bias_L1[0][0], &bias_L1[1][0]);
	//	printf("%lf \t %lf\n",bias_L1[0][0], bias_L1[1][0]);
		fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&bias_L1[0][0], &bias_L1[1][0], &bias_L1[2][0], &bias_L1[3][0], &bias_L1[4][0], &bias_L1[5][0], &bias_L1[6][0], &bias_L1[7][0], &bias_L1[8][0], &bias_L1[9][0]);
		}

	printf("Bias1 *************\n");
printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",bias_L1[0][0], bias_L1[1][0], bias_L1[2][0], bias_L1[3][0], bias_L1[4][0], bias_L1[5][0], bias_L1[6][0], bias_L1[7][0], bias_L1[8][0], bias_L1[9][0]);
printf("\nBias1 *************\n");

printf("\nWeight L2 *************\n");
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L2_wt"))
		{
	//	printf("Inside L2_wt\n");
	//	fscanf(ptr,"%lf \b %lf",&wt_L2[0][0], &wt_L2[1][0]);
	//	printf("%lf \t %lf\n",wt_L2[0][0], wt_L2[1][0]);
	for(i=0;i<10;i++)
			{
			
			fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&wt_L2[i][0], &wt_L2[i][1],&wt_L2[i][2], &wt_L2[i][3],&wt_L2[i][4], &wt_L2[i][5],&wt_L2[i][6], &wt_L2[i][7],&wt_L2[i][8], &wt_L2[i][9]);
			}
		}
	
for(i=0;i<10;i++)
			{
			printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf\n",wt_L2[i][0], wt_L2[i][1],wt_L2[i][2], wt_L2[i][3],wt_L2[i][4], wt_L2[i][5],wt_L2[i][6], wt_L2[i][7],wt_L2[i][8], wt_L2[i][9]);
			}
printf("Weight L2 End*************\n");


printf("Bias2 *************\n");
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L2_b"))
		{
	//	printf("Inside L2_b\n");
	//	fscanf(ptr,"%lf",&bias_L2);
	//	printf("%lf \n",bias_L2);
fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&bias_L2[0][0], &bias_L2[1][0], &bias_L2[2][0], &bias_L2[3][0], &bias_L2[4][0], &bias_L2[5][0], &bias_L2[6][0], &bias_L2[7][0], &bias_L2[8][0], &bias_L2[9][0]);
		}

printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",bias_L2[0][0], bias_L2[1][0], bias_L2[2][0], bias_L2[3][0], bias_L2[4][0], bias_L2[5][0], bias_L2[6][0], bias_L2[7][0], bias_L2[8][0], bias_L2[9][0]);
printf("\n Bias L2 End*************\n");
	

printf("\nWeight L3 *************\n");
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L3_wt"))
		{
	//	printf("Inside L2_wt\n");
	//	fscanf(ptr,"%lf \b %lf",&wt_L2[0][0], &wt_L2[1][0]);
	//	printf("%lf \t %lf\n",wt_L2[0][0], wt_L2[1][0]);
	for(i=0;i<10;i++)
			{
			
			fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&wt_L3[i][0], &wt_L3[i][1],&wt_L3[i][2], &wt_L3[i][3],&wt_L3[i][4], &wt_L3[i][5],&wt_L3[i][6], &wt_L3[i][7]);
			}
		}
	
for(i=0;i<10;i++)
			{
			printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf\n",wt_L3[i][0], wt_L3[i][1],wt_L3[i][2], wt_L3[i][3],wt_L3[i][4], wt_L3[i][5],wt_L3[i][6], wt_L3[i][7]);
			}
printf("Weight L3 End*************\n");


printf("Bias3 *************\n");
	fscanf(ptr,"%s",str);
	//printf("%s\n",str);
	if(!strcmp(str,"#L3_b"))
		{
	//	printf("Inside L2_b\n");
	//	fscanf(ptr,"%lf",&bias_L2);
	//	printf("%lf \n",bias_L2);
fscanf(ptr,"%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",&bias_L3[0][0], &bias_L3[1][0], &bias_L3[2][0], &bias_L3[3][0], &bias_L3[4][0], &bias_L3[5][0], &bias_L3[6][0], &bias_L3[7][0]);
		}

printf("%lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf \b %lf",bias_L3[0][0], bias_L3[1][0], bias_L3[2][0], bias_L3[3][0], bias_L3[4][0], bias_L3[5][0], bias_L3[6][0], bias_L3[7][0]);
printf("\n Bias L3 End*************\n");

    fclose(ptr);

// reading and storing ANN model is completed



/*
	int no_layers=0; //2 
	int no_inputs=0; //2
	int no_neurons[20]; //2 and 1 are no of neurons in each layer, (no_neurons[0]==2), (no_neurons[1]==1)
	double wt_L1[2][2];
	double wt_L2[2][1];
	double bias_L1[2][1];
	double bias_L2;
*/

// reading input
    ptr2 = fopen("shift.txt", "r");
	//ptr2 = fopen("shift_1.txt", "r");
 
    if (NULL == ptr2) {
        printf("file can't be opened \n");
    }
 for(i=0;i<no_test_case;i++)
	{
	double * input_p, * wt_L1_p, * wt_L1_Tp, * bias_L1_p, * wt_L2_p, * wt_L2_Tp, * bias_L2_p, * wt_L3_p, * wt_L3_Tp, * bias_L3_p;
	//10x1 matrix to store input
	//double input_m1[10][1];
	//double input_m2[10][1];
	//double input_m[10][1];
	fscanf(ptr2,"%lf %lf %s",&e,&f,str1);
	input_m2[0][0] = e;
	input_m2[1][0] = f;
	d1=str1[0];
	d1= d1-48;
	input_m2[2][0] = d1;
	d2=str1[1];
	d2= d2-48;
	input_m2[3][0] = d2;
	d3=str1[2];
	d3= d3-48;
	input_m2[4][0] = d3;
	d4=str1[3];
	d4= d4-48;
	input_m2[5][0] = d4;
	d5=str1[4];
	d5= d5-48;
	input_m2[6][0] = d5;
	d6=str1[5];
	d6= d6-48;
	input_m2[7][0] = d6;
	d7=str1[6];
	d7= d7-48;
	input_m2[8][0] = d7;
	d8=str1[7];
	d8= d8-48;
	input_m2[9][0] = d8;
	if(i>=1)
		{
		input_m[0][0] = e;
		input_m[1][0] = f;
		input[i][0] = (int)e;
		input[i][1] = (int)f;
		for(j=2;j<10;j++)
			{
			input_m[j][0] = input_m1[j][0]; 
			input[i][j] = (int)input_m1[j][0]; 
			}
		printf("Input is \n");
		for(j=0;j<10;j++)
			{
			printf("%lf \t",input_m[j][0]);
			}
		printf("\n");		
		//Perform Prediction using trained model: for input_m[10][1]
		
// #######Layer 1
printf("\n#######Layer 1###############################################################################################################\n");
		input_p = (double *)input_m;
	//transpose of wt_L1
		wt_L1_p = (double *)wt_L1;
		wt_L1_Tp = matrix_trans(10,10, wt_L1_p);
	//Multiplication
		print_matrix(10, 1, input_p);
		res_mul = matrix_mul(10, 10, wt_L1_Tp, 10, 1, input_p);

	//add bias
		bias_L1_p = (double *)bias_L1;
		printf("\nAdd Bias: bias_L1");
		print_matrix(10, 1, bias_L1_p);
		res_add = matrix_add(10, 1, res_mul, 10, 1, bias_L1_p);
	//apply Relu activation function
	//and get a 10x1 Matrix as input to the next layer
		for(k=0;k<10;k++)
			{
			* (res_add + k ) = relud( *(res_add + k ) );
			} 
		print_matrix(10, 1, res_add);


printf("\n#######Layer 2###############################################################################################################\n");
// #######Layer 2
	//10x1 Matrix as input from previous layer
	//transpose of wt_L2
		wt_L2_p = (double *)wt_L2;
		wt_L2_Tp = matrix_trans(10,10, wt_L2_p);
	//Multiplication
		print_matrix(10, 1, res_add);
		res_mul = matrix_mul(10, 10, wt_L2_Tp, 10, 1, res_add);
	//add bias
		bias_L2_p = (double *)bias_L2;
		printf("\nAdd Bias: bias_L2");
		print_matrix(10, 1, bias_L2_p);
		res_add = matrix_add(10, 1, res_mul, 10, 1, bias_L2_p);
	//apply Relu activation function
	//and get a 10x1 Matrix as input to the next layer
		for(k=0;k<10;k++)
			{
			* (res_add + k ) = relud( *(res_add + k ) );
			} 
		print_matrix(10, 1, res_add);


printf("\n#######Layer 3###############################################################################################################\n");
// #######Layer 3
	//10x1 Matrix as input from previous layer
	//transpose of wt_L2 
		wt_L3_p = (double *)wt_L3;
		wt_L3_Tp = matrix_trans(10,8, wt_L3_p);
	//Multiplication
		print_matrix(10, 1, res_add);
		res_mul = matrix_mul(8, 10, wt_L3_Tp, 10, 1, res_add);
	//add bias
		bias_L3_p = (double *)bias_L3;
		printf("\n Bias L3: bias_L3");
		print_matrix(8, 1, bias_L3_p);
		res_add = matrix_add(8, 1, res_mul, 8, 1, bias_L3_p);
	//apply Sigmoid activation function
	//and get a 8x1 Matrix as output
	//sigmoid(*(res_mul));
		for(k=0;k<8;k++)
			{
			//* (res_add + k ) = sigmoid( *(res_add + k ) );
			predicted_output[i][k]= sigmoid( *(res_add + k ) );
			} 
		//print_matrix(8, 1, res_add);

		//Prediction ends
		} //if(i>=1)
	
		for( j=0;j<10;j++)
		{
		input_m1[j][0] = input_m2[j][0];
		}

		
	printf("Print output **********\n");
		for( j=1;j<no_test_case;j++)
		{
			for(k=0;k<10;k++)
				{
				printf("%d ",input[j][k]);
				}
			printf("\t");
				for(k=0;k<8;k++)
				{
				printf("%d ",input[j+1][k+2]);
				}
			printf("\t");
				for(k=0;k<8;k++)
				{
				printf("%d ",predicted_output[j][k]);
				}

			//accuracy
			
			for(k=0;k<8;k++)
				{
				macthing=1;
				if(input[j+1][k+2] != predicted_output[j][k])
					{
					macthing=0;
					break;
					}
				}

		count1++;
		if(macthing==1)
			{
			correct1++;
			}

		printf("\n");
		}
	//printf("\nTotal  accurate_cases=%d cases=%d \n",accurate_cases,cases);
	//accuracy = accurate_cases/cases;
	//printf("\n accuracy=%lf\n",accuracy);
	//printf("\n%f\n",accuracy1);
	accuracy1 = (float)correct1/(float)count1;
	
	printf("count=%d, correct=%d accuracy=%f\n",count1,correct1,accuracy1);
	//printf("accuracy=%lf\n",accuracy1);


	//printf("%lf %lf %s\n",e,f,str1);
	//printf("%lf %lf %lf %lf %lf %lf %lf %lf\n",d1,d2,d3,d4,d5,d6,d7,d8);

	}
//Prediction for #no_test_case
fclose(ptr2);

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

