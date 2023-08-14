#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[16] = {
-1.12143033e+00f,-4.70006580e-01f,-9.94877329e-01f,-1.01654146e+00f,+1.16182887e+00f,
-1.79677776e+00f,+1.51994693e+00f,-1.60035555e-01f,-2.23816805e-01f,-1.05535652e+00f,
+1.83499166e+00f,+1.81960903e+00f,+1.27288809e+00f,+1.33088652e+00f,-1.81169511e+00f,
+3.43101306e-01f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test1_array[16] = {
+1.79514755e-05f,+4.82413087e-09f,+1.05960254e-07f,+5.96485972e-10f,+1.13446252e-09f,
+2.05783593e-07f,+1.15673847e-05f,+4.22066892e-04f,+1.00170269e-06f,+2.53150517e-07f,
+7.37308570e-09f,+1.16532225e-04f,+5.79675398e-05f,+9.99998927e-01f,+7.62452254e-12f,
+4.91940700e-05f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test1_array[16] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test2_dense_input_input_array[16] = {
-1.27997477e+00f,+1.35852449e+00f,-6.11209217e-01f,+7.92306631e-01f,+1.12570741e+00f,
+1.79668862e+00f,+4.28826026e-01f,+6.30497644e-01f,+5.83879495e-01f,+1.55332213e+00f,
-1.16029463e+00f,+9.99734391e-01f,-2.55145937e-01f,-1.80557437e+00f,+5.57000823e-01f,
-1.19185653e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test2_array[16] = {
+2.37120723e-08f,+7.02988327e-05f,+2.80878274e-03f,+5.92787634e-04f,+3.56023316e-03f,
+1.49860293e-01f,+1.17672645e-02f,+1.02461830e-01f,+7.52898455e-01f,+8.66674066e-01f,
+3.71418719e-05f,+6.77050464e-03f,+4.87469770e-05f,+1.07167365e-11f,+9.74703610e-01f,
+7.36982610e-12f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test2_array[16] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test3_dense_input_input_array[16] = {
+4.33378037e-01f,+1.14257354e+00f,+1.68960733e+00f,-2.04397265e-01f,-9.78963181e-01f,
-1.90737014e+00f,+1.58128467e+00f,-2.20383036e-01f,+1.88426436e+00f,-1.09159716e+00f,
+9.28844226e-01f,-4.27496369e-01f,+1.47846908e+00f,-4.40894338e-01f,-5.55704207e-01f,
-1.71714529e+00f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test3_array[16] = {
+2.01655757e-06f,+2.08439029e-04f,+7.46966271e-06f,+1.27158473e-05f,+2.58505625e-05f,
+5.86098642e-04f,+1.75329428e-02f,+5.13013378e-02f,+9.99743760e-01f,+1.59768715e-05f,
+4.65925559e-02f,+5.87470765e-08f,+1.17272930e-03f,+2.54902170e-05f,+4.43875700e-01f,
+5.76211484e-15f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test3_array[16] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test4_dense_input_input_array[16] = {
+1.63403283e+00f,+1.63038918e+00f,+5.84225557e-01f,-1.66238738e+00f,-1.40535597e+00f,
+3.68172873e-02f,+1.46858325e-01f,-1.86288138e+00f,+9.54510018e-01f,+1.42813863e+00f,
+1.24021089e+00f,+5.87149636e-01f,-1.76033734e-01f,+7.79487810e-01f,+1.88746109e+00f,
+1.78645789e+00f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test4_array[16] = {
+3.11232827e-17f,+9.99244437e-17f,+5.42486346e-18f,+2.69782677e-12f,+2.38648629e-10f,
+2.11171147e-09f,+1.71640057e-12f,+2.19608798e-09f,+1.55878817e-30f,+3.07727802e-13f,
+9.83961499e-08f,+6.71776038e-11f,+2.30395517e-26f,+4.32527504e-26f,+1.79716082e-08f,
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test4_array[16] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test5_dense_input_input_array[16] = {
+3.17046045e-01f,-8.33868042e-01f,+1.41577493e+00f,-1.62312738e+00f,+5.12390164e-02f,
-9.54827877e-01f,-1.14571686e+00f,-1.34756750e+00f,+1.46639930e+00f,-8.84801392e-01f,
+7.21346564e-01f,+3.75095975e-01f,+6.30024993e-01f,+1.63208295e+00f,+8.45515848e-01f,
+1.04508508e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test5_array[16] = {
+2.86009652e-08f,+3.31378869e-10f,+4.55766341e-10f,+3.15170155e-07f,+2.98914347e-05f,
+1.91378331e-06f,+1.66133105e-07f,+5.77000537e-05f,+9.97045654e-13f,+7.27563452e-12f,
+5.76414152e-07f,+1.04224815e-11f,+7.53298519e-14f,+8.12633161e-08f,+1.96421340e-01f,
+9.58205223e-01f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test5_array[16] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test6_dense_input_input_array[16] = {
-5.14476437e-01f,+2.67282230e-01f,+1.12369424e+00f,+1.59138515e+00f,+1.20617710e+00f,
+1.37062388e-01f,-6.74005159e-01f,-4.50422979e-02f,-2.26993455e-01f,-5.47624347e-02f,
-1.88019556e-01f,-9.95144994e-02f,-1.20953581e+00f,-1.81350240e+00f,+1.65433257e+00f,
-1.17935575e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test6_array[16] = {
+2.11714379e-09f,+1.34360980e-05f,+3.08373188e-07f,+7.63504254e-03f,+3.48455156e-03f,
+3.20078917e-02f,+4.54345159e-03f,+7.74611458e-02f,+1.05230510e-02f,+7.43089383e-03f,
+9.57087696e-01f,+9.82205311e-05f,+7.05210575e-13f,+3.28207400e-17f,+9.99729872e-01f,
+8.82632578e-10f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test6_array[16] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test7_dense_input_input_array[16] = {
+1.46924841e+00f,-1.00469688e+00f,-3.70842230e-01f,+1.73973018e+00f,-7.72960106e-01f,
-1.34773929e+00f,-7.70235949e-01f,-5.25109627e-01f,-6.00156200e-01f,+2.70192257e-01f,
-1.39708455e+00f,+1.26538707e+00f,-1.41741409e+00f,-1.96200529e+00f,+1.80937122e-01f,
-4.75279716e-01f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test7_array[16] = {
+2.34682520e-04f,+4.64755110e-03f,+1.04176160e-03f,+1.31382868e-01f,+3.52906287e-02f,
+4.56662178e-01f,+4.68661606e-01f,+9.90424901e-02f,+2.69534886e-02f,+9.48210537e-01f,
+9.82865155e-01f,+6.63968801e-01f,+3.13383538e-07f,+4.36507079e-08f,+2.65362620e-01f,
+1.02616067e-03f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test7_array[16] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test8_dense_input_input_array[16] = {
-8.72924054e-01f,+5.82941003e-01f,+1.20569268e+00f,+5.92283982e-01f,+1.97894102e+00f,
+8.39186644e-02f,-2.06839915e-01f,-1.89758429e+00f,-8.03830522e-01f,-5.33438743e-01f,
-9.78043278e-01f,-8.99809013e-01f,+8.89935587e-01f,+1.32896308e-01f,+5.19887969e-01f,
+1.75318671e+00f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test8_array[16] = {
+4.60427358e-08f,+7.68068631e-09f,+1.48136658e-08f,+1.20196262e-06f,+2.47563858e-05f,
+5.04409854e-06f,+2.04927119e-06f,+3.62739411e-05f,+1.67367569e-15f,+7.31977252e-08f,
+1.01385136e-04f,+8.01833039e-07f,+7.12091852e-09f,+6.70509381e-09f,+3.08044861e-07f,
+9.99999821e-01f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test8_array[16] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test9_dense_input_input_array[16] = {
+1.80602830e+00f,-1.74852724e+00f,-1.30369849e+00f,+1.88115064e+00f,-1.11026560e+00f,
-1.78747582e+00f,-1.48865890e+00f,-2.28106430e-02f,+1.42473326e+00f,-4.45987673e-01f,
-2.91884878e-02f,-4.25378141e-02f,-2.89664727e-01f,-2.44134013e-02f,+1.08531565e+00f,
+1.96808525e+00f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test9_array[16] = {
+2.08157710e-11f,+1.25658303e-10f,+5.40650380e-12f,+2.66599454e-08f,+3.49518928e-07f,
+3.08760650e-06f,+3.22395941e-08f,+3.49419020e-06f,+7.56146477e-20f,+1.00367243e-08f,
+7.03761107e-05f,+2.73945784e-06f,+2.61546999e-17f,+2.12181637e-17f,+9.28933332e-07f,
+9.99999523e-01f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test9_array[16] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test10_dense_input_input_array[16] = {
+1.63212565e+00f,-7.94523407e-01f,+1.03703850e+00f,+1.00253275e+00f,-9.67071408e-01f,
+9.83733071e-01f,+1.73024474e+00f,+1.93808250e+00f,+1.80018320e+00f,-1.89404242e+00f,
-1.67217366e+00f,+8.76826635e-01f,-7.81737372e-01f,-1.76726900e+00f,+1.81369567e+00f,
-6.04912380e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 
float keras_dense_2_test10_array[16] = {
+1.08328670e-08f,+8.96106067e-05f,+3.49688235e-05f,+3.64918633e-05f,+1.18603828e-04f,
+1.47892013e-02f,+3.09166120e-04f,+3.63197029e-02f,+8.97471964e-01f,+3.35477957e-08f,
+7.89257967e-07f,+2.66570970e-02f,+2.52032187e-04f,+3.91526106e-14f,+1.00000000e+00f,
+3.93494111e-15f,}; 
k2c_tensor keras_dense_2_test10 = {&keras_dense_2_test10_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test10_array[16] = {0}; 
k2c_tensor c_dense_2_test10 = {&c_dense_2_test10_array[0],1,16,{16, 1, 1, 1, 1}}; 
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

