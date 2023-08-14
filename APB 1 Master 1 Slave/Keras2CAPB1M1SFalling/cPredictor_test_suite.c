#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[2] = {
-1.06504525e+00f,-1.50780486e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test1_array[1] = {
+9.80969727e-01f,}; 
k2c_tensor keras_dense_1_test1 = {&keras_dense_1_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test1_array[1] = {0}; 
k2c_tensor c_dense_1_test1 = {&c_dense_1_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[2] = {
+1.62148954e+00f,-3.44188799e-01f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test2_array[1] = {
+9.81754899e-01f,}; 
k2c_tensor keras_dense_1_test2 = {&keras_dense_1_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test2_array[1] = {0}; 
k2c_tensor c_dense_1_test2 = {&c_dense_1_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[2] = {
+1.78406169e+00f,+5.66422851e-01f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test3_array[1] = {
+9.57060084e-02f,}; 
k2c_tensor keras_dense_1_test3 = {&keras_dense_1_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test3_array[1] = {0}; 
k2c_tensor c_dense_1_test3 = {&c_dense_1_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[2] = {
+7.58630432e-01f,-1.98679144e+00f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test4_array[1] = {
+9.76286709e-01f,}; 
k2c_tensor keras_dense_1_test4 = {&keras_dense_1_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test4_array[1] = {0}; 
k2c_tensor c_dense_1_test4 = {&c_dense_1_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[2] = {
-5.43422520e-01f,-1.53559583e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test5_array[1] = {
+9.80161071e-01f,}; 
k2c_tensor keras_dense_1_test5 = {&keras_dense_1_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test5_array[1] = {0}; 
k2c_tensor c_dense_1_test5 = {&c_dense_1_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[2] = {
-1.93226315e+00f,+4.55094137e-02f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test6_array[1] = {
+9.83570158e-01f,}; 
k2c_tensor keras_dense_1_test6 = {&keras_dense_1_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test6_array[1] = {0}; 
k2c_tensor c_dense_1_test6 = {&c_dense_1_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[2] = {
-8.18390170e-01f,-5.69357034e-01f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test7_array[1] = {
+9.83570158e-01f,}; 
k2c_tensor keras_dense_1_test7 = {&keras_dense_1_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test7_array[1] = {0}; 
k2c_tensor c_dense_1_test7 = {&c_dense_1_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[2] = {
-5.41862543e-02f,-8.94700579e-01f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test8_array[1] = {
+9.81902897e-01f,}; 
k2c_tensor keras_dense_1_test8 = {&keras_dense_1_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test8_array[1] = {0}; 
k2c_tensor c_dense_1_test8 = {&c_dense_1_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[2] = {
-1.09771157e+00f,+1.27284130e+00f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test9_array[1] = {
+4.15558089e-03f,}; 
k2c_tensor keras_dense_1_test9 = {&keras_dense_1_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test9_array[1] = {0}; 
k2c_tensor c_dense_1_test9 = {&c_dense_1_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[2] = {
-6.36770455e-01f,+1.98346106e+00f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test10_array[1] = {
+2.76485639e-06f,}; 
k2c_tensor keras_dense_1_test10 = {&keras_dense_1_test10_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test10_array[1] = {0}; 
k2c_tensor c_dense_1_test10 = {&c_dense_1_test10_array[0],1,1,{1,1,1,1,1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
cPredictor_initialize(); 
clock_t t0 = clock(); 
cPredictor(&test1_dense_input_input,&c_dense_1_test1); 
cPredictor(&test2_dense_input_input,&c_dense_1_test2); 
cPredictor(&test3_dense_input_input,&c_dense_1_test3); 
cPredictor(&test4_dense_input_input,&c_dense_1_test4); 
cPredictor(&test5_dense_input_input,&c_dense_1_test5); 
cPredictor(&test6_dense_input_input,&c_dense_1_test6); 
cPredictor(&test7_dense_input_input,&c_dense_1_test7); 
cPredictor(&test8_dense_input_input,&c_dense_1_test8); 
cPredictor(&test9_dense_input_input,&c_dense_1_test9); 
cPredictor(&test10_dense_input_input,&c_dense_1_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_dense_1_test1,&c_dense_1_test1); 
errors[1] = maxabs(&keras_dense_1_test2,&c_dense_1_test2); 
errors[2] = maxabs(&keras_dense_1_test3,&c_dense_1_test3); 
errors[3] = maxabs(&keras_dense_1_test4,&c_dense_1_test4); 
errors[4] = maxabs(&keras_dense_1_test5,&c_dense_1_test5); 
errors[5] = maxabs(&keras_dense_1_test6,&c_dense_1_test6); 
errors[6] = maxabs(&keras_dense_1_test7,&c_dense_1_test7); 
errors[7] = maxabs(&keras_dense_1_test8,&c_dense_1_test8); 
errors[8] = maxabs(&keras_dense_1_test9,&c_dense_1_test9); 
errors[9] = maxabs(&keras_dense_1_test10,&c_dense_1_test10); 
float maxerror = errors[0]; 
for(size_t i=1; i< num_tests*num_outputs;i++){ 
if (errors[i] > maxerror) { 
maxerror = errors[i];}} 
printf("Max absolute error for 10 tests: %e \n", maxerror);
cPredictor_terminate(); 
if (maxerror > 1e-05) { 
return 1;} 
return 0;
} 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2){ 

    float x = 0; 

    float y = 0; 

    for(size_t i=0; i<tensor1->numel; i++){

    y = fabsf(tensor1->array[i]-tensor2->array[i]);
    if (y>x) {x=y;}}
    return x;}

