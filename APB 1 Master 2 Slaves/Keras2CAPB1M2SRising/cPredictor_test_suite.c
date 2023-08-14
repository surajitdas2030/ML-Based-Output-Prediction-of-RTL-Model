#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[3] = {
+1.98651363e+00f,+1.13092094e+00f,+1.17281644e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test1_array[1] = {
+9.05079663e-01f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test1_array[1] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[3] = {
-8.29605809e-01f,-1.89660104e+00f,-1.63513608e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test2_array[1] = {
+5.77946126e-01f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test2_array[1] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[3] = {
-1.66362850e+00f,+2.83653707e-01f,-5.23569270e-01f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test3_array[1] = {
+2.32190356e-01f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test3_array[1] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[3] = {
+1.90842559e+00f,-4.79959588e-01f,-1.58204196e+00f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test4_array[1] = {
+9.99976337e-01f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test4_array[1] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[3] = {
-6.61713567e-01f,+1.18787229e+00f,-1.08212487e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test5_array[1] = {
+9.95164812e-01f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test5_array[1] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[3] = {
+3.70062365e-01f,-6.23894368e-01f,-1.78729971e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test6_array[1] = {
+9.98758852e-01f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test6_array[1] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[3] = {
+7.66876864e-01f,+5.11219830e-01f,+1.71459544e+00f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test7_array[1] = {
+1.17223069e-01f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test7_array[1] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[3] = {
+1.57908478e+00f,-1.13941598e+00f,-1.56817808e+00f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test8_array[1] = {
+9.99907732e-01f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test8_array[1] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[3] = {
-3.87112849e-01f,-9.40910293e-01f,-1.81921964e+00f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test9_array[1] = {
+9.83148158e-01f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test9_array[1] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[3] = {
-9.35891118e-01f,-1.56566188e+00f,+1.75045413e+00f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,3,{3,1,1,1,1}}; 
float keras_dense_2_test10_array[1] = {
+3.24543178e-01f,}; 
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

