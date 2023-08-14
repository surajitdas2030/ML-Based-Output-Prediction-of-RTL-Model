#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[3] = {
+2.26608791e-01f,+9.70076796e-01f,+1.06100627e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test1_array[1] = {
+2.31312515e-04f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test1_array[1] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[3] = {
+1.49936437e+00f,+1.30935555e+00f,-1.49575964e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test2_array[1] = {
+9.67944324e-01f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test2_array[1] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[3] = {
+6.70345962e-02f,-9.42050962e-01f,-5.27286886e-01f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test3_array[1] = {
+9.89884079e-01f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test3_array[1] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[3] = {
+1.88754868e+00f,-1.23289231e+00f,+1.48376707e+00f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test4_array[1] = {
+2.00271188e-05f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test4_array[1] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[3] = {
+1.48271580e+00f,-1.79834155e+00f,-7.37147492e-01f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test5_array[1] = {
+9.96147633e-01f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test5_array[1] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[3] = {
+1.82571480e+00f,-7.02071898e-01f,+1.65457273e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test6_array[1] = {
+8.84486951e-07f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test6_array[1] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[3] = {
+1.67866040e+00f,+1.42811290e+00f,+1.62281832e+00f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test7_array[1] = {
+3.67636449e-10f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test7_array[1] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[3] = {
+1.42690172e+00f,+1.23242170e+00f,+7.70912216e-01f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test8_array[1] = {
+1.49330901e-06f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test8_array[1] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[3] = {
-9.24607828e-01f,+1.21352839e+00f,-8.22434921e-02f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test9_array[1] = {
+9.62628603e-01f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test9_array[1] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[3] = {
+8.66171164e-01f,+7.57345442e-01f,-1.47330495e+00f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test10_array[1] = {
+9.97510135e-01f,}; 
k2c_tensor keras_dense_2_test10 = {&keras_dense_2_test10_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test10_array[1] = {0}; 
k2c_tensor c_dense_2_test10 = {&c_dense_2_test10_array[0],1,1,{1,1,1,1,1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
cPredictor_initialize(); 
clock_t t0 = clock(); 
cPredictor(&test1_dense_input_input,&c_dense_2_test1); 
cPredictor(&test2_dense_input_input,&c_dense_2_test2); 
cPredictor(&test3_dense_input_input,&c_dense_2_test3); 
cPredictor(&test4_dense_input_input,&c_dense_2_test4); 
cPredictor(&test5_dense_input_input,&c_dense_2_test5); 
cPredictor(&test6_dense_input_input,&c_dense_2_test6); 
cPredictor(&test7_dense_input_input,&c_dense_2_test7); 
cPredictor(&test8_dense_input_input,&c_dense_2_test8); 
cPredictor(&test9_dense_input_input,&c_dense_2_test9); 
cPredictor(&test10_dense_input_input,&c_dense_2_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_dense_2_test1,&c_dense_2_test1); 
errors[1] = maxabs(&keras_dense_2_test2,&c_dense_2_test2); 
errors[2] = maxabs(&keras_dense_2_test3,&c_dense_2_test3); 
errors[3] = maxabs(&keras_dense_2_test4,&c_dense_2_test4); 
errors[4] = maxabs(&keras_dense_2_test5,&c_dense_2_test5); 
errors[5] = maxabs(&keras_dense_2_test6,&c_dense_2_test6); 
errors[6] = maxabs(&keras_dense_2_test7,&c_dense_2_test7); 
errors[7] = maxabs(&keras_dense_2_test8,&c_dense_2_test8); 
errors[8] = maxabs(&keras_dense_2_test9,&c_dense_2_test9); 
errors[9] = maxabs(&keras_dense_2_test10,&c_dense_2_test10); 
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

