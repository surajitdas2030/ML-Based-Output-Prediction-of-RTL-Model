#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[32] = {
+1.51584898e+00f,+2.61782212e-01f,-1.75514891e+00f,+1.27557370e-01f,+1.83573656e+00f,
-7.60788947e-01f,-1.32621607e+00f,+4.92424928e-01f,+1.40443130e+00f,-1.51803678e+00f,
-1.31004556e+00f,+1.84070299e+00f,-8.33522532e-01f,-4.96328121e-01f,-1.87041640e+00f,
-1.63452086e+00f,+1.14206312e+00f,-1.67687065e+00f,-1.64288419e+00f,-1.62002565e+00f,
-5.62340163e-01f,-3.22482244e-01f,+1.42435918e+00f,-6.83249149e-01f,-1.35937334e+00f,
+2.27579277e-01f,-5.70055200e-01f,-1.89793524e-01f,+1.32495825e+00f,-6.40912296e-01f,
-1.22715659e-01f,-1.06262328e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test1_array[16] = {
+1.00000000e+00f,+2.41197239e-20f,+3.12243336e-19f,+4.35150440e-08f,+3.32208405e-37f,
+3.32176958e-28f,+1.65324169e-03f,+8.94931616e-24f,+2.82786005e-30f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.20605932e-31f,+1.35861850e-31f,
+1.60408010e-13f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test1_array[16] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test2_dense_input_input_array[32] = {
-1.27764547e+00f,-1.77289119e+00f,-4.15039347e-01f,-1.94546039e+00f,-1.64797084e+00f,
+1.18552652e+00f,-9.26848193e-01f,+4.97169252e-01f,-9.65552155e-01f,+4.66831126e-01f,
-2.07059588e-01f,-1.16019371e+00f,+8.89007043e-01f,+7.59895274e-01f,-1.93716583e+00f,
-4.87030973e-02f,+1.67815658e+00f,-1.42655975e+00f,-4.95662267e-01f,-8.61985006e-01f,
+1.08678616e+00f,-1.57692402e+00f,-8.92153589e-01f,-8.99932305e-01f,+1.61123322e-01f,
-3.25690134e-02f,-1.45684794e+00f,+5.20290189e-01f,+1.84127154e+00f,-1.65770024e+00f,
+7.48443834e-01f,-7.40501311e-01f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test2_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+1.44842925e-05f,+1.00000000e+00f,+0.00000000e+00f,
+1.47545640e-34f,+0.00000000e+00f,+1.82188530e-24f,+0.00000000e+00f,+3.81427334e-09f,
+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test2_array[16] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test3_dense_input_input_array[32] = {
-4.06602913e-01f,-1.39287992e+00f,-1.47897388e+00f,-1.12125010e+00f,+2.58569198e-01f,
+1.90581595e+00f,+4.58775435e-01f,-9.03805156e-01f,+7.27869589e-01f,+1.67857863e+00f,
+1.86460416e+00f,-1.36869082e+00f,+1.62647638e+00f,-1.03265556e+00f,+1.70340855e+00f,
+6.72583744e-01f,-7.44681342e-01f,+1.04123729e+00f,-9.09588249e-01f,-1.69305383e+00f,
+1.01415415e+00f,-1.04128356e+00f,+1.18096058e+00f,-9.66873381e-01f,+5.70056157e-01f,
-7.58659289e-01f,+3.92297202e-01f,+6.21812769e-01f,+1.94009561e+00f,-1.94777309e+00f,
+9.19602333e-01f,-9.27537176e-01f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test3_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,
+6.05007221e-18f,+6.62081581e-34f,+1.00000000e+00f,+3.62035098e-31f,+9.32933176e-27f,
+0.00000000e+00f,+2.12602044e-18f,+0.00000000e+00f,+1.00000000e+00f,+8.29884447e-36f,
+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test3_array[16] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test4_dense_input_input_array[32] = {
+1.36363615e+00f,+1.62327598e+00f,+6.64574612e-01f,+1.27968014e+00f,+1.59855521e+00f,
+1.36265779e+00f,-1.94629127e+00f,+1.19794721e+00f,+1.14532255e+00f,-8.05585941e-01f,
-1.82930271e+00f,+1.94683824e+00f,-1.77770034e+00f,-1.69134937e+00f,+9.53558584e-01f,
+5.25128765e-01f,+1.64583169e+00f,+2.22846404e-02f,+4.29805387e-01f,-7.38970808e-01f,
+1.69091268e+00f,+1.28535406e+00f,+1.48710302e+00f,+2.89285438e-01f,-5.04761708e-01f,
-1.28959498e+00f,+1.99072016e+00f,+9.03206467e-01f,-1.02819798e+00f,+1.47893810e+00f,
+9.25253278e-01f,+7.24611243e-01f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test4_array[16] = {
+1.00000000e+00f,+2.28360500e-24f,+2.74509506e-29f,+0.00000000e+00f,+1.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+7.90877641e-17f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,+9.73704159e-01f,
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test4_array[16] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test5_dense_input_input_array[32] = {
-1.25899194e+00f,-1.22352624e+00f,-1.17294283e+00f,+1.53208215e+00f,+3.28493818e-01f,
+1.78824435e+00f,-3.05668825e-02f,+7.69629995e-02f,-1.35375289e+00f,-1.74407171e+00f,
-1.46452375e+00f,-5.24804167e-01f,-1.94906256e+00f,-3.55618016e-01f,+1.02451710e-01f,
+2.54643648e-01f,+4.48739760e-01f,-1.02750465e+00f,-1.35091213e+00f,-1.72854715e+00f,
-3.09003706e-01f,-1.07930013e+00f,-1.44637230e-01f,-9.84664185e-01f,+9.72765546e-01f,
+1.40906662e-01f,+1.14935995e+00f,+7.44318307e-01f,-1.24793661e+00f,-1.10727103e+00f,
-1.32662232e+00f,+1.38522943e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test5_array[16] = {
+7.95941830e-01f,+1.00214608e-30f,+1.00000000e+00f,+9.50857882e-13f,+3.79728844e-12f,
+0.00000000e+00f,+0.00000000e+00f,+3.51484749e-15f,+0.00000000e+00f,+0.00000000e+00f,
+2.95833761e-33f,+0.00000000e+00f,+0.00000000e+00f,+2.10433189e-14f,+7.19481374e-33f,
+2.87085677e-05f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test5_array[16] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test6_dense_input_input_array[32] = {
-1.54879346e+00f,+1.32564687e+00f,-5.52933570e-01f,+1.29125151e+00f,-1.15538271e+00f,
-8.07956962e-01f,-9.43607851e-01f,+1.09773578e+00f,+4.88959621e-01f,+8.34716508e-01f,
-4.01277588e-01f,-1.76987017e+00f,-1.08932755e+00f,-1.82278399e+00f,+8.64058317e-01f,
-1.42562347e+00f,+5.90655909e-01f,+1.20275013e+00f,+1.72008994e+00f,-4.75207293e-01f,
+7.52813022e-01f,-3.92962702e-01f,-8.29489464e-01f,+1.15721403e+00f,+5.36590123e-01f,
+1.64118785e+00f,-5.23521716e-01f,+1.69857206e-01f,+1.62754321e+00f,-8.91476235e-01f,
+1.11646349e+00f,-8.67370797e-01f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test6_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+1.86325007e-37f,+0.00000000e+00f,+6.32615867e-13f,
+1.00000000e+00f,+8.92587285e-36f,+1.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.34353889e-02f,+0.00000000e+00f,
+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test6_array[16] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test7_dense_input_input_array[32] = {
+3.77648929e-02f,+5.95012291e-01f,-1.19129252e+00f,-1.10058673e+00f,-1.94771310e+00f,
+1.50867265e+00f,+2.40634633e-01f,+5.66291197e-01f,-5.17533565e-01f,+6.60784196e-01f,
-1.91561594e+00f,-3.12008439e-02f,-1.30953752e+00f,-2.29291042e-01f,+1.73991496e+00f,
+4.23993944e-02f,-1.75224322e+00f,+1.40982519e+00f,+8.89240907e-01f,-1.00420659e+00f,
-1.46594070e+00f,-1.43457045e+00f,+1.85127724e+00f,-9.07589420e-01f,-2.84194215e-01f,
+7.21086967e-01f,-1.04872333e+00f,-1.18232821e+00f,-3.69500021e-02f,-7.68398299e-01f,
+1.39609900e+00f,-8.21716391e-01f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test7_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+5.37126362e-01f,
+0.00000000e+00f,+3.04485522e-29f,+1.06117614e-05f,+0.00000000e+00f,+2.07186033e-30f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,+1.00000000e+00f,
+2.04133585e-14f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test7_array[16] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test8_dense_input_input_array[32] = {
-1.71617880e+00f,-2.40372794e-01f,-1.29282373e+00f,-1.97481542e+00f,+1.33248987e+00f,
-5.32623269e-01f,-1.29598279e+00f,-9.29332851e-01f,-1.23427278e+00f,+1.81918358e+00f,
-1.87755653e+00f,-6.65269536e-01f,-1.18484906e+00f,+9.44032146e-01f,-3.93427057e-01f,
-1.37805639e+00f,+1.29433783e+00f,+1.04922814e+00f,+5.02314954e-01f,-1.09951767e+00f,
-1.01329170e+00f,+6.77255576e-01f,-1.20763483e+00f,-1.19265721e+00f,+1.87445456e+00f,
+5.14068526e-01f,+6.50824901e-01f,-9.11584900e-01f,-4.58672218e-02f,+1.64094322e+00f,
-9.95389780e-02f,-2.35521553e-01f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test8_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+4.76298319e-24f,
+0.00000000e+00f,+0.00000000e+00f,+9.99956131e-01f,+9.99994814e-01f,+0.00000000e+00f,
+2.63627314e-11f,+0.00000000e+00f,+0.00000000e+00f,+7.57606611e-37f,+4.51503954e-26f,
+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test8_array[16] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test9_dense_input_input_array[32] = {
+1.71012473e+00f,+1.43250095e+00f,-1.06608558e+00f,-1.38794554e+00f,+1.72625525e+00f,
+4.09859693e-02f,+1.32184455e+00f,+1.53168522e+00f,+1.90293416e+00f,-1.62739045e+00f,
+9.56803769e-01f,-1.86266544e+00f,+1.81282206e+00f,-1.43132058e+00f,+1.31074926e+00f,
+1.52988508e-01f,-9.82110166e-01f,-1.49118623e+00f,-1.25400643e+00f,+1.53934458e+00f,
+6.97575934e-01f,-8.47785533e-01f,-1.86691362e+00f,-3.81350308e-01f,-9.84164705e-01f,
-8.38000368e-01f,-1.57609684e+00f,-4.16369135e-01f,-2.84887020e-01f,-6.78655725e-01f,
+2.41121779e-01f,-6.82006542e-01f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test9_array[16] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,
+1.73138424e-12f,+8.13391309e-31f,+3.47180784e-01f,+0.00000000e+00f,+9.07585049e-28f,
+0.00000000e+00f,+1.56960687e-29f,+0.00000000e+00f,+1.00000000e+00f,+1.16261807e-12f,
+4.47442349e-25f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,16,{16, 1, 1, 1, 1}}; 
float c_dense_2_test9_array[16] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,16,{16, 1, 1, 1, 1}}; 
float test10_dense_input_input_array[32] = {
+1.34191302e+00f,-1.59234984e+00f,+1.28597097e+00f,+1.44107945e+00f,+1.82893859e+00f,
+1.18059441e-01f,-1.65807784e+00f,-3.97686588e-01f,+6.79931460e-01f,+1.89076575e+00f,
-5.75036198e-01f,-1.69631442e+00f,+1.51501953e+00f,-1.24095675e+00f,-1.88937493e+00f,
+6.10841183e-01f,-9.29033318e-01f,+1.04113436e+00f,-7.34230126e-01f,+1.20624048e+00f,
-9.83412109e-01f,-6.22885068e-01f,+8.93489117e-01f,-1.45591701e+00f,+1.12247754e+00f,
+9.35877336e-01f,-1.05795584e+00f,-1.94961073e+00f,+1.10409021e-01f,-9.25983216e-01f,
-1.51839131e-02f,+3.20849408e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test10_array[16] = {
+1.47653276e-14f,+1.00000000e+00f,+5.16436068e-29f,+1.67863027e-31f,+0.00000000e+00f,
+0.00000000e+00f,+2.85740556e-25f,+6.26432988e-33f,+1.00000000e+00f,+3.62443023e-37f,
+1.17363844e-26f,+0.00000000e+00f,+6.78835188e-35f,+1.16678526e-35f,+0.00000000e+00f,
+9.99992371e-01f,}; 
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

