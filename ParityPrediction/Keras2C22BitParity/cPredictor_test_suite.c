#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_1_input_input_array[22] = {
+1.26663185e+00f,-4.16095482e-01f,-1.48697582e+00f,-3.65514668e-01f,-5.53448855e-01f,
-1.71465078e+00f,-1.50190779e+00f,+3.79277999e-01f,+4.64978425e-01f,-8.74260152e-01f,
-8.95036248e-01f,-1.48686011e+00f,-7.42412619e-01f,+2.91680727e-01f,+6.61787991e-01f,
+1.13946902e+00f,-1.30269914e+00f,-4.54091008e-01f,-8.44433637e-01f,-9.00269573e-01f,
-4.30149057e-01f,-2.25696528e-01f,}; 
k2c_tensor test1_dense_1_input_input = {&test1_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test1_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test1 = {&keras_dense_3_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test1_array[1] = {0}; 
k2c_tensor c_dense_3_test1 = {&c_dense_3_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_1_input_input_array[22] = {
-9.45457760e-01f,+1.43544560e+00f,+1.41357746e+00f,+1.42733692e-01f,+1.94407745e+00f,
-8.89103446e-01f,+1.47656993e+00f,-1.00782071e+00f,+1.68932672e+00f,+7.62075863e-01f,
-4.41581523e-01f,-5.72684571e-01f,+1.15813789e+00f,+1.68674606e+00f,+4.93122259e-01f,
-3.11865095e-02f,-1.05431313e+00f,-1.24712731e-01f,-1.81215792e+00f,-1.49523762e+00f,
-1.94973068e+00f,+1.51582480e+00f,}; 
k2c_tensor test2_dense_1_input_input = {&test2_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test2_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test2 = {&keras_dense_3_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test2_array[1] = {0}; 
k2c_tensor c_dense_3_test2 = {&c_dense_3_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_1_input_input_array[22] = {
-5.70583565e-01f,+5.75487798e-01f,-1.11485211e+00f,-1.86406365e+00f,+1.52984532e+00f,
+7.27597875e-01f,+1.14942972e+00f,-3.47286850e-01f,+2.15222728e-01f,-4.59398017e-01f,
-6.45403707e-01f,-4.42077515e-02f,+1.02447170e+00f,-1.00972781e+00f,-2.94768835e-01f,
+1.73209113e+00f,+6.98549291e-01f,+1.77757646e+00f,-1.32853207e-01f,+1.65945290e+00f,
-1.44175801e-01f,+1.74499442e+00f,}; 
k2c_tensor test3_dense_1_input_input = {&test3_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test3_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test3 = {&keras_dense_3_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test3_array[1] = {0}; 
k2c_tensor c_dense_3_test3 = {&c_dense_3_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_1_input_input_array[22] = {
-1.45005931e+00f,+1.27250229e+00f,+8.36682374e-01f,-1.11678052e+00f,+1.34225633e+00f,
-7.34726116e-01f,+3.53758058e-01f,-1.28883354e+00f,-5.64418817e-01f,-9.46760771e-01f,
-2.64769718e-01f,-1.33342027e+00f,-3.93362739e-01f,-7.69057538e-01f,+7.82272522e-01f,
+3.50023254e-01f,-1.71807768e-01f,+1.34232667e+00f,+1.04131122e+00f,+1.55487060e+00f,
+9.48376980e-01f,+1.23799873e+00f,}; 
k2c_tensor test4_dense_1_input_input = {&test4_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test4_array[1] = {
+9.89946537e-04f,}; 
k2c_tensor keras_dense_3_test4 = {&keras_dense_3_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test4_array[1] = {0}; 
k2c_tensor c_dense_3_test4 = {&c_dense_3_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_1_input_input_array[22] = {
-1.29226803e+00f,-1.93672862e+00f,-4.07762647e-01f,-1.15836310e+00f,+1.94321326e+00f,
+1.59164208e+00f,-1.64606752e+00f,-2.69595212e-01f,+1.54477363e-01f,+6.89734085e-01f,
+1.64015041e-01f,-9.48039523e-01f,-1.23890132e+00f,-1.36751966e+00f,-1.49689213e+00f,
-1.34438653e-01f,-1.35979308e+00f,+1.23706998e-01f,-4.55129393e-01f,-1.48522256e+00f,
+2.82192429e-01f,+6.01822191e-01f,}; 
k2c_tensor test5_dense_1_input_input = {&test5_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test5_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test5 = {&keras_dense_3_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test5_array[1] = {0}; 
k2c_tensor c_dense_3_test5 = {&c_dense_3_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_1_input_input_array[22] = {
+3.18118542e-01f,+1.43727971e+00f,-1.10339881e+00f,+1.79314696e+00f,-4.99923993e-01f,
+1.12502776e+00f,+1.58792618e+00f,-2.71066236e-01f,+3.71857293e-01f,-1.76380409e+00f,
+6.32716017e-01f,+1.79865357e+00f,-1.31602226e+00f,-1.44822581e+00f,+1.21879841e+00f,
-2.46377278e-02f,-1.05918505e+00f,-6.02645505e-01f,-1.89681307e+00f,-1.02591151e-01f,
-1.11365040e+00f,+1.27283582e+00f,}; 
k2c_tensor test6_dense_1_input_input = {&test6_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test6_array[1] = {
+2.30198372e-02f,}; 
k2c_tensor keras_dense_3_test6 = {&keras_dense_3_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test6_array[1] = {0}; 
k2c_tensor c_dense_3_test6 = {&c_dense_3_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_1_input_input_array[22] = {
+1.21435216e+00f,-1.77607912e+00f,+1.59921744e+00f,+7.05250233e-01f,+9.91833130e-01f,
-2.38428782e-01f,-3.45980469e-01f,-4.68027856e-01f,+1.02509221e-01f,-1.50384084e+00f,
-9.29177277e-01f,-1.80917494e+00f,-2.76965152e-01f,-1.75543279e+00f,-1.71296716e+00f,
-5.90042109e-01f,-9.01120535e-02f,+1.87708864e+00f,+6.52930112e-01f,-1.12456189e+00f,
+1.42124325e+00f,+6.06345526e-03f,}; 
k2c_tensor test7_dense_1_input_input = {&test7_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test7_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test7 = {&keras_dense_3_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test7_array[1] = {0}; 
k2c_tensor c_dense_3_test7 = {&c_dense_3_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_1_input_input_array[22] = {
-1.45393850e+00f,+1.14359448e+00f,+5.08297023e-01f,-1.28936323e+00f,+1.95168405e+00f,
-1.11812625e+00f,+3.30471822e-01f,-1.96813249e+00f,-1.94714526e+00f,+1.56312717e+00f,
-8.33142967e-01f,-1.34355503e-03f,-5.18220165e-01f,-4.32184450e-01f,-7.78698445e-01f,
+1.55606598e+00f,-5.24488133e-01f,+1.19622915e+00f,+1.97843934e-01f,-1.75449242e+00f,
-1.26922811e+00f,+2.28728131e-01f,}; 
k2c_tensor test8_dense_1_input_input = {&test8_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test8_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_3_test8 = {&keras_dense_3_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test8_array[1] = {0}; 
k2c_tensor c_dense_3_test8 = {&c_dense_3_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_1_input_input_array[22] = {
-1.57477963e+00f,-8.30633277e-01f,+1.46265550e+00f,+1.63698936e+00f,+1.40746850e+00f,
+1.55195827e+00f,+1.37683910e+00f,-1.21395103e+00f,+1.77150215e+00f,-2.03307450e-01f,
-1.66097877e+00f,-1.48956224e+00f,+1.89321045e+00f,+3.04842011e-01f,-1.37634463e+00f,
+4.87744188e-01f,+1.97822600e+00f,-8.92151645e-01f,-9.14453628e-02f,+1.04082589e+00f,
-1.57825505e+00f,-9.24045593e-01f,}; 
k2c_tensor test9_dense_1_input_input = {&test9_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test9_array[1] = {
+9.99999940e-01f,}; 
k2c_tensor keras_dense_3_test9 = {&keras_dense_3_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test9_array[1] = {0}; 
k2c_tensor c_dense_3_test9 = {&c_dense_3_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_1_input_input_array[22] = {
+1.98504437e+00f,+1.05131722e+00f,-3.59667215e-01f,+3.07148891e-01f,-1.01737861e+00f,
-1.06672517e+00f,-1.52458848e+00f,+1.80396396e+00f,+1.00042251e+00f,-9.31831934e-01f,
+6.22636622e-01f,-2.35796689e-01f,-1.96333877e+00f,-1.17614934e+00f,+1.24440297e+00f,
-1.20236293e-01f,-3.34941751e-01f,+7.82120637e-01f,-9.53837379e-01f,+6.75876988e-01f,
-1.11428369e+00f,+9.76382912e-01f,}; 
k2c_tensor test10_dense_1_input_input = {&test10_dense_1_input_input_array[0],1,22,{22, 1, 1, 1, 1}}; 
float keras_dense_3_test10_array[1] = {
+3.57338308e-07f,}; 
k2c_tensor keras_dense_3_test10 = {&keras_dense_3_test10_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_3_test10_array[1] = {0}; 
k2c_tensor c_dense_3_test10 = {&c_dense_3_test10_array[0],1,1,{1,1,1,1,1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
cPredictor_initialize(); 
clock_t t0 = clock(); 
cPredictor(&test1_dense_1_input_input,&c_dense_3_test1); 
cPredictor(&test2_dense_1_input_input,&c_dense_3_test2); 
cPredictor(&test3_dense_1_input_input,&c_dense_3_test3); 
cPredictor(&test4_dense_1_input_input,&c_dense_3_test4); 
cPredictor(&test5_dense_1_input_input,&c_dense_3_test5); 
cPredictor(&test6_dense_1_input_input,&c_dense_3_test6); 
cPredictor(&test7_dense_1_input_input,&c_dense_3_test7); 
cPredictor(&test8_dense_1_input_input,&c_dense_3_test8); 
cPredictor(&test9_dense_1_input_input,&c_dense_3_test9); 
cPredictor(&test10_dense_1_input_input,&c_dense_3_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_dense_3_test1,&c_dense_3_test1); 
errors[1] = maxabs(&keras_dense_3_test2,&c_dense_3_test2); 
errors[2] = maxabs(&keras_dense_3_test3,&c_dense_3_test3); 
errors[3] = maxabs(&keras_dense_3_test4,&c_dense_3_test4); 
errors[4] = maxabs(&keras_dense_3_test5,&c_dense_3_test5); 
errors[5] = maxabs(&keras_dense_3_test6,&c_dense_3_test6); 
errors[6] = maxabs(&keras_dense_3_test7,&c_dense_3_test7); 
errors[7] = maxabs(&keras_dense_3_test8,&c_dense_3_test8); 
errors[8] = maxabs(&keras_dense_3_test9,&c_dense_3_test9); 
errors[9] = maxabs(&keras_dense_3_test10,&c_dense_3_test10); 
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

