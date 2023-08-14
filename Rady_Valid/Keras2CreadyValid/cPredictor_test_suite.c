#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_6_input_input_array[2] = {
+1.60158739e+00f,+1.59985698e+00f,}; 
k2c_tensor test1_dense_6_input_input = {&test1_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test1_array[1] = {
+8.88694465e-01f,}; 
k2c_tensor keras_dense_8_test1 = {&keras_dense_8_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test1_array[1] = {0}; 
k2c_tensor c_dense_8_test1 = {&c_dense_8_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_6_input_input_array[2] = {
+1.52409361e+00f,+1.65751046e+00f,}; 
k2c_tensor test2_dense_6_input_input = {&test2_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test2_array[1] = {
+8.88694465e-01f,}; 
k2c_tensor keras_dense_8_test2 = {&keras_dense_8_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test2_array[1] = {0}; 
k2c_tensor c_dense_8_test2 = {&c_dense_8_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_6_input_input_array[2] = {
-1.49806828e+00f,-1.98083923e+00f,}; 
k2c_tensor test3_dense_6_input_input = {&test3_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test3_array[1] = {
+4.24968449e-10f,}; 
k2c_tensor keras_dense_8_test3 = {&keras_dense_8_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test3_array[1] = {0}; 
k2c_tensor c_dense_8_test3 = {&c_dense_8_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_6_input_input_array[2] = {
+1.41651045e-01f,+2.71336177e-01f,}; 
k2c_tensor test4_dense_6_input_input = {&test4_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test4_array[1] = {
+1.00461170e-02f,}; 
k2c_tensor keras_dense_8_test4 = {&keras_dense_8_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test4_array[1] = {0}; 
k2c_tensor c_dense_8_test4 = {&c_dense_8_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_6_input_input_array[2] = {
+1.03881168e+00f,-7.80268300e-02f,}; 
k2c_tensor test5_dense_6_input_input = {&test5_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test5_array[1] = {
+7.30768254e-04f,}; 
k2c_tensor keras_dense_8_test5 = {&keras_dense_8_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test5_array[1] = {0}; 
k2c_tensor c_dense_8_test5 = {&c_dense_8_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_6_input_input_array[2] = {
-1.87750094e+00f,-3.63232521e-01f,}; 
k2c_tensor test6_dense_6_input_input = {&test6_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test6_array[1] = {
+1.32271325e-07f,}; 
k2c_tensor keras_dense_8_test6 = {&keras_dense_8_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test6_array[1] = {0}; 
k2c_tensor c_dense_8_test6 = {&c_dense_8_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_6_input_input_array[2] = {
-1.81710499e+00f,-6.16711376e-01f,}; 
k2c_tensor test7_dense_6_input_input = {&test7_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test7_array[1] = {
+7.02779204e-08f,}; 
k2c_tensor keras_dense_8_test7 = {&keras_dense_8_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test7_array[1] = {0}; 
k2c_tensor c_dense_8_test7 = {&c_dense_8_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_6_input_input_array[2] = {
-1.04650580e+00f,+1.53211035e+00f,}; 
k2c_tensor test8_dense_6_input_input = {&test8_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test8_array[1] = {
+5.37059357e-08f,}; 
k2c_tensor keras_dense_8_test8 = {&keras_dense_8_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test8_array[1] = {0}; 
k2c_tensor c_dense_8_test8 = {&c_dense_8_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_6_input_input_array[2] = {
+1.69672517e+00f,+1.45304332e+00f,}; 
k2c_tensor test9_dense_6_input_input = {&test9_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test9_array[1] = {
+8.88694465e-01f,}; 
k2c_tensor keras_dense_8_test9 = {&keras_dense_8_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test9_array[1] = {0}; 
k2c_tensor c_dense_8_test9 = {&c_dense_8_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_6_input_input_array[2] = {
+1.48805102e+00f,-1.09465711e+00f,}; 
k2c_tensor test10_dense_6_input_input = {&test10_dense_6_input_input_array[0],1,2,{2,1,1,1,1}}; 
float keras_dense_8_test10_array[1] = {
+1.70618115e-08f,}; 
k2c_tensor keras_dense_8_test10 = {&keras_dense_8_test10_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_8_test10_array[1] = {0}; 
k2c_tensor c_dense_8_test10 = {&c_dense_8_test10_array[0],1,1,{1,1,1,1,1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
cPredictor_initialize(); 
clock_t t0 = clock(); 
cPredictor(&test1_dense_6_input_input,&c_dense_8_test1); 
cPredictor(&test2_dense_6_input_input,&c_dense_8_test2); 
cPredictor(&test3_dense_6_input_input,&c_dense_8_test3); 
cPredictor(&test4_dense_6_input_input,&c_dense_8_test4); 
cPredictor(&test5_dense_6_input_input,&c_dense_8_test5); 
cPredictor(&test6_dense_6_input_input,&c_dense_8_test6); 
cPredictor(&test7_dense_6_input_input,&c_dense_8_test7); 
cPredictor(&test8_dense_6_input_input,&c_dense_8_test8); 
cPredictor(&test9_dense_6_input_input,&c_dense_8_test9); 
cPredictor(&test10_dense_6_input_input,&c_dense_8_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_dense_8_test1,&c_dense_8_test1); 
errors[1] = maxabs(&keras_dense_8_test2,&c_dense_8_test2); 
errors[2] = maxabs(&keras_dense_8_test3,&c_dense_8_test3); 
errors[3] = maxabs(&keras_dense_8_test4,&c_dense_8_test4); 
errors[4] = maxabs(&keras_dense_8_test5,&c_dense_8_test5); 
errors[5] = maxabs(&keras_dense_8_test6,&c_dense_8_test6); 
errors[6] = maxabs(&keras_dense_8_test7,&c_dense_8_test7); 
errors[7] = maxabs(&keras_dense_8_test8,&c_dense_8_test8); 
errors[8] = maxabs(&keras_dense_8_test9,&c_dense_8_test9); 
errors[9] = maxabs(&keras_dense_8_test10,&c_dense_8_test10); 
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

