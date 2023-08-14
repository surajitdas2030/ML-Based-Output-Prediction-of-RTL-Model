#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[2] = {
+3.29062407e-01f,+1.90257284e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test1_array[1] = {
+8.76484705e-07f,}; 
k2c_tensor keras_dense_1_test1 = {&keras_dense_1_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test1_array[1] = {0}; 
k2c_tensor c_dense_1_test1 = {&c_dense_1_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[2] = {
-6.90924133e-01f,+5.34441547e-01f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test2_array[1] = {
+6.79221272e-01f,}; 
k2c_tensor keras_dense_1_test2 = {&keras_dense_1_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test2_array[1] = {0}; 
k2c_tensor c_dense_1_test2 = {&c_dense_1_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[2] = {
-1.22171490e+00f,-1.88540527e+00f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test3_array[1] = {
+9.98533964e-01f,}; 
k2c_tensor keras_dense_1_test3 = {&keras_dense_1_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test3_array[1] = {0}; 
k2c_tensor c_dense_1_test3 = {&c_dense_1_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[2] = {
-1.14905411e+00f,-9.54842192e-01f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test4_array[1] = {
+9.97314453e-01f,}; 
k2c_tensor keras_dense_1_test4 = {&keras_dense_1_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test4_array[1] = {0}; 
k2c_tensor c_dense_1_test4 = {&c_dense_1_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[2] = {
+2.29144505e-01f,-3.07032367e-01f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test5_array[1] = {
+9.86035168e-01f,}; 
k2c_tensor keras_dense_1_test5 = {&keras_dense_1_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test5_array[1] = {0}; 
k2c_tensor c_dense_1_test5 = {&c_dense_1_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[2] = {
-8.88583583e-01f,+1.16685335e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test6_array[1] = {
+4.08728560e-03f,}; 
k2c_tensor keras_dense_1_test6 = {&keras_dense_1_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test6_array[1] = {0}; 
k2c_tensor c_dense_1_test6 = {&c_dense_1_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[2] = {
+6.81485067e-01f,+1.72230948e+00f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test7_array[1] = {
+3.86996544e-06f,}; 
k2c_tensor keras_dense_1_test7 = {&keras_dense_1_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test7_array[1] = {0}; 
k2c_tensor c_dense_1_test7 = {&c_dense_1_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[2] = {
-1.47309719e+00f,-7.89361909e-01f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test8_array[1] = {
+9.97838378e-01f,}; 
k2c_tensor keras_dense_1_test8 = {&keras_dense_1_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test8_array[1] = {0}; 
k2c_tensor c_dense_1_test8 = {&c_dense_1_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[2] = {
+2.88040447e-01f,-8.36151901e-01f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test9_array[1] = {
+9.88580167e-01f,}; 
k2c_tensor keras_dense_1_test9 = {&keras_dense_1_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_1_test9_array[1] = {0}; 
k2c_tensor c_dense_1_test9 = {&c_dense_1_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[2] = {
-1.45482787e+00f,+1.43013621e+00f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_1_test10_array[1] = {
+7.26200640e-04f,}; 
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

