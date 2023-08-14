#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[16] = {
-7.22032601e-01f,+1.91460180e+00f,-9.60982266e-01f,+1.70378949e+00f,+8.44743749e-01f,
-1.48395131e+00f,+1.28710106e+00f,-1.10453445e+00f,-1.60138718e+00f,+5.82523569e-01f,
+1.30115871e+00f,+1.95886461e+00f,+9.60617941e-01f,+1.68957935e-01f,+1.25834699e-01f,
+1.05450154e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test1_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test1_array[1] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[16] = {
-1.85402707e+00f,+2.60642795e-01f,-3.34830623e-01f,-1.88268841e+00f,+7.00985379e-01f,
+2.83367052e-01f,-1.27473017e+00f,-8.72387000e-01f,-7.41327065e-01f,+1.04159256e+00f,
+1.92317875e-01f,+6.22540921e-01f,+8.14107940e-02f,+1.01629496e+00f,+1.23495784e+00f,
-1.21995316e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test2_array[1] = {
+9.99370337e-01f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test2_array[1] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[16] = {
-1.43874942e+00f,+1.91555603e-01f,+1.42657980e+00f,+1.89183152e+00f,-1.97074975e-01f,
+7.96975813e-01f,-1.10731438e+00f,-7.65442219e-01f,+7.63314103e-01f,-1.16292579e+00f,
+1.02125146e+00f,+1.14270424e+00f,-5.76357361e-01f,-1.54112238e+00f,-4.48553514e-01f,
-1.01426522e+00f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test3_array[1] = {
+6.46989644e-01f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test3_array[1] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[16] = {
+6.05736092e-01f,-1.97824212e+00f,+8.89851805e-01f,+1.24511903e+00f,-7.38478389e-01f,
-1.16369893e+00f,+1.01247920e+00f,-5.30558798e-01f,+1.14340044e+00f,+5.16086748e-01f,
+4.58368702e-01f,-6.30082165e-03f,-1.56049627e+00f,+9.99381880e-01f,-1.90536409e+00f,
-3.15401223e-01f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test4_array[1] = {
+2.07712248e-01f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test4_array[1] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[16] = {
+8.03286249e-02f,-7.65759216e-01f,-3.26775533e-01f,+1.04193408e+00f,+1.96829569e+00f,
+9.26603503e-01f,+2.87166969e-01f,+6.39832482e-01f,-1.60291074e+00f,+1.62172136e+00f,
-1.47849312e+00f,+1.45692353e+00f,-1.03220238e+00f,-1.61427179e+00f,+1.85073321e+00f,
+9.76210522e-01f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test5_array[1] = {
+9.54104125e-01f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test5_array[1] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[16] = {
-1.34367350e+00f,-5.33359765e-01f,+2.60674752e-01f,+1.78029303e-01f,+1.76236020e+00f,
-8.02289308e-02f,+1.46028850e+00f,-1.72339484e+00f,+4.28672967e-01f,-2.28159855e-01f,
+1.60306266e+00f,+1.92999138e+00f,-1.29509612e+00f,+1.75140017e+00f,+1.42986201e+00f,
+1.62773279e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test6_array[1] = {
+9.94526744e-01f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test6_array[1] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[16] = {
+4.69779617e-01f,+1.20983360e+00f,-2.70163653e-01f,-3.43479935e-01f,+6.92735113e-01f,
+1.20001359e+00f,+1.96210487e-02f,-1.90275607e+00f,-9.61674918e-01f,-3.83696927e-02f,
-1.90969190e+00f,+1.46188311e+00f,+6.78964180e-01f,+1.92651358e+00f,+7.04001535e-01f,
-1.21014046e+00f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test7_array[1] = {
+9.87580419e-01f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test7_array[1] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[16] = {
+7.57219453e-01f,+1.63194190e+00f,-4.06152246e-01f,+9.00233515e-01f,+3.26234186e-01f,
-6.88877276e-01f,-6.67426724e-02f,+1.53462223e+00f,-1.46988549e-01f,-1.45273971e+00f,
+2.17931171e-01f,+1.13128179e+00f,-9.82679985e-02f,-1.82426651e+00f,-6.01102182e-01f,
+1.54544141e+00f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test8_array[1] = {
+2.81944796e-02f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test8_array[1] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[16] = {
+1.70397707e+00f,-6.18076032e-01f,-3.55425039e-01f,+1.48726763e+00f,-3.76818300e-02f,
-5.29311951e-01f,-1.64116270e+00f,+1.37782129e+00f,+1.34836461e+00f,-3.08740240e-01f,
+1.48553498e+00f,-2.24040604e-01f,-1.98395849e+00f,-1.75421631e+00f,-4.75253460e-02f,
-1.13434136e+00f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test9_array[1] = {
+8.57583880e-01f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test9_array[1] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[16] = {
-7.43377092e-01f,-1.56066110e+00f,-1.87923562e+00f,-5.34339966e-01f,-1.27955970e-01f,
+6.07002677e-01f,-1.93473602e+00f,-5.61443516e-01f,-1.99789943e+00f,+1.97046525e+00f,
-4.68532549e-02f,+4.50055454e-01f,-1.19495238e+00f,+1.98471220e+00f,-1.91532024e+00f,
+1.30519985e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test10_array[1] = {
+1.85231052e-04f,}; 
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

