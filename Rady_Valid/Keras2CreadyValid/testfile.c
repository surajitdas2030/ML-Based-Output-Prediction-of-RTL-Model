#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

void compute(){
    float inputArr[2], outputArr[1];

    for(int j=0;j<2;j++){
        scanf("%f",&inputArr[j]);
    }

    k2c_tensor inputTensor = {&inputArr[0], 1, 2, {2, 1, 1, 1, 1}};
    k2c_tensor outputTensor = {&outputArr[0], 1, 1, {1, 1, 1, 1, 1}};

    cPredictor_initialize(); 
    cPredictor(&inputTensor,&outputTensor); 

    printf("for the input : [");
    for(int i=0;i<2;i++){
        printf("%.0f ",round(inputArr[i]));
    }
    printf("]\n");


    printf("the output is : [");
    for(int i=0;i<1;i++){
        printf("%.0f ",round(outputArr[i]));
    }
    // printf("\n");
    printf("]\n\n");

    cPredictor_terminate(); 

    return ;
}

int main(){

    freopen("inputFile.txt","r",stdin);
    freopen("cOutput.txt","w",stdout);

    int numTests;

    scanf("%d",&numTests);
    for(int i=0;i<numTests;i++){
        printf("test case %d\n",i+1);
        compute();
    }

    return 0;
} 