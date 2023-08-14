#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[32] = {
+1.36023538e+00f,-1.10583154e+00f,-1.82846133e+00f,+1.03274929e+00f,-1.72189977e-01f,
-1.53107110e+00f,-1.43700157e+00f,+1.62335658e+00f,+1.23514622e+00f,-1.44142378e+00f,
-6.39781983e-02f,+8.24439566e-02f,+1.43425695e+00f,-1.90822989e+00f,+7.10873423e-01f,
-4.84359216e-01f,-6.42570312e-01f,-6.13952338e-01f,-1.31640286e+00f,-1.61003096e+00f,
-2.10655920e-01f,+1.97864760e+00f,+1.05737667e+00f,-1.06540150e+00f,-7.57002143e-01f,
+5.85514801e-01f,-1.61061785e+00f,-5.80962513e-01f,+2.30168722e-01f,+1.60490429e+00f,
+1.87042026e+00f,+1.70835155e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test1_array[1] = {
+2.80569020e-05f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test1_array[1] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_dense_input_input_array[32] = {
+1.60814139e+00f,-1.15418706e+00f,+1.46481698e+00f,+1.66216615e+00f,-6.72792736e-01f,
-1.97537242e+00f,+7.19002681e-01f,+2.82273218e-01f,+1.83084319e-01f,+1.69674421e+00f,
+1.34494043e+00f,-1.15465403e+00f,+1.99916326e+00f,-3.60994988e-01f,+5.51591208e-01f,
-9.09472740e-01f,+1.48737064e+00f,-1.14646331e+00f,-1.08217920e-01f,-4.70721519e-01f,
-2.69344343e-01f,-6.09065159e-03f,+3.16273516e-01f,-7.69170888e-01f,+1.83668998e+00f,
+1.50398756e+00f,+8.33288759e-01f,+9.87913997e-02f,+8.81683714e-01f,+8.24660016e-01f,
-1.23186369e+00f,-1.28772785e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test2_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test2_array[1] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_dense_input_input_array[32] = {
-9.00002276e-01f,-1.25445916e+00f,-1.69607763e+00f,+1.56852262e+00f,+1.22968167e+00f,
+8.35083277e-01f,-1.06664310e+00f,-3.01273021e-02f,-8.22341134e-01f,-7.14992001e-01f,
+4.04495393e-01f,-9.37148827e-01f,+1.58929476e+00f,-8.72501540e-01f,-1.69133431e+00f,
-1.68036707e+00f,-6.90268636e-01f,+1.95934457e+00f,+1.31838826e+00f,-1.21441076e+00f,
+1.77053651e+00f,-1.86691587e+00f,+2.75519555e-01f,-1.26222337e+00f,-1.64330667e+00f,
-1.69060846e+00f,-1.89654069e+00f,+1.03335222e+00f,+1.99268513e+00f,+1.13541631e-01f,
+1.97374055e-01f,-1.21646563e+00f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test3_array[1] = {
+9.99996364e-01f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test3_array[1] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_dense_input_input_array[32] = {
-1.88435464e+00f,-8.98999318e-01f,+5.77424619e-02f,-1.84562339e+00f,+1.31729059e+00f,
+7.70669638e-01f,+1.96002160e+00f,-7.81962085e-01f,-2.31605608e-01f,-7.83990196e-01f,
-1.14960131e+00f,-6.90957372e-01f,-1.28971653e+00f,+1.11460576e+00f,+1.77107154e+00f,
+1.13767624e+00f,+8.28324671e-01f,-1.51304448e+00f,-1.30561389e+00f,+1.09681476e+00f,
-1.73380124e+00f,-1.35158504e+00f,+7.21785432e-01f,+5.34134528e-01f,-1.00980370e+00f,
+1.93028646e+00f,+7.39511678e-01f,-1.03130170e+00f,-1.51581307e+00f,+6.81068926e-01f,
-1.17881828e+00f,-8.83789981e-01f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test4_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test4_array[1] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_dense_input_input_array[32] = {
+8.13465779e-01f,+1.77633387e+00f,-1.51210217e+00f,-1.24092677e+00f,+1.40365331e-01f,
-1.20481700e+00f,-1.88339792e-01f,+1.25457505e-01f,+5.88619934e-01f,-8.82456888e-02f,
+1.50606454e-02f,-9.43293002e-01f,-1.21837755e+00f,+1.62449156e+00f,+1.84284210e+00f,
+5.11958672e-01f,+3.40742460e-01f,+1.13731787e-01f,-6.34652428e-01f,+7.87232435e-01f,
+1.93125092e+00f,-1.97235479e+00f,-1.49770741e+00f,+3.41821396e-01f,+1.02712031e+00f,
-5.72198196e-01f,+1.63713678e+00f,-5.50118655e-01f,+1.27582685e+00f,+1.74064759e+00f,
+1.23573047e+00f,-1.90028609e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test5_array[1] = {
+9.99994218e-01f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test5_array[1] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_dense_input_input_array[32] = {
-1.82211549e+00f,-1.94177987e+00f,-1.16481259e-01f,+8.44843116e-01f,-1.37248295e+00f,
-4.33923273e-01f,+9.16665040e-01f,+1.63052886e+00f,-1.45217768e+00f,-1.50395845e+00f,
+1.66516313e+00f,+1.79826841e+00f,+1.13598233e+00f,-1.31505828e+00f,-4.67034972e-01f,
-1.80855651e+00f,+1.86619942e+00f,-5.94707499e-01f,-1.56790407e+00f,-1.45725078e+00f,
-3.42549440e-01f,+1.72462863e+00f,-6.61556803e-01f,+3.17735467e-01f,+1.09286070e-01f,
+4.74414625e-01f,-1.19925081e+00f,+3.43338839e-01f,-1.71096185e+00f,-3.07491975e-01f,
+3.02606624e-01f,+2.95327376e-01f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test6_array[1] = {
+1.00000000e+00f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test6_array[1] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_dense_input_input_array[32] = {
-4.87935174e-01f,-1.45080417e+00f,-2.30019349e-01f,+1.36842130e+00f,-7.10636068e-01f,
+4.76073789e-01f,-1.72449520e+00f,-9.75006637e-01f,-1.31999030e-01f,+1.69901356e+00f,
+1.76656854e+00f,+3.44912806e-01f,+5.99053851e-01f,+1.17562919e+00f,+1.57275709e+00f,
-8.53174603e-01f,-1.58210132e+00f,-4.66401378e-01f,-4.77868926e-01f,+1.26341317e+00f,
-1.90527108e+00f,+1.20888650e-01f,-9.26490439e-01f,+6.03810639e-01f,+1.64373856e+00f,
+1.15084953e+00f,-7.07772045e-01f,-6.53097388e-01f,-1.33858614e-01f,-1.32344218e+00f,
+4.61704584e-01f,-5.62737686e-01f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test7_array[1] = {
+9.99991894e-01f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test7_array[1] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_dense_input_input_array[32] = {
-3.42557714e-01f,+6.86471221e-01f,-2.66553788e-01f,-1.26285791e+00f,+1.28705320e+00f,
-4.05733067e-01f,+2.74429718e-01f,+6.93783858e-01f,+5.23535607e-02f,-1.26155881e+00f,
-4.95373288e-01f,-1.86632494e+00f,+1.31132328e+00f,+1.83408896e+00f,-1.78552526e+00f,
+1.56230854e+00f,-2.56143013e-01f,-1.37430609e-01f,+1.81740016e+00f,+1.83703432e+00f,
+6.78648367e-01f,+1.31946586e+00f,+4.73968149e-01f,-1.29266446e+00f,-1.04955849e+00f,
-9.60505199e-01f,-9.18528821e-01f,-1.49097320e+00f,+1.58787782e+00f,+1.73417621e+00f,
-1.57502341e+00f,+6.63489928e-01f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test8_array[1] = {
+9.99999702e-01f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test8_array[1] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_dense_input_input_array[32] = {
+2.20234300e-01f,-2.38701920e-01f,-1.35716922e+00f,+1.44331927e+00f,+1.01933338e+00f,
-2.48757101e-01f,-1.66548073e+00f,-1.10075197e+00f,-9.24606745e-01f,-9.24011669e-02f,
+1.38102112e+00f,+1.96521343e+00f,+7.37790599e-01f,-1.07988161e+00f,+1.00589083e+00f,
+8.16609103e-01f,+1.34847093e+00f,+1.56038945e+00f,+1.47967188e+00f,-1.57135460e+00f,
+7.11415094e-01f,-5.38796983e-01f,-6.54010016e-01f,+1.48915434e+00f,-1.12689706e+00f,
-1.30721791e+00f,-1.13725243e+00f,-1.64984150e+00f,-2.81876743e-01f,-5.00070888e-01f,
-5.10577365e-01f,-6.24914604e-01f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test9_array[1] = {
+6.81706674e-16f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_dense_2_test9_array[1] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_dense_input_input_array[32] = {
-5.89354258e-01f,-6.70741831e-01f,-1.20834949e+00f,+6.98624932e-01f,+1.89082136e+00f,
-1.24810456e-01f,-1.96609730e+00f,-1.01135665e+00f,-1.28407333e+00f,-8.97845479e-01f,
+1.06072331e+00f,+1.35213678e+00f,+6.21346691e-01f,+1.12011900e+00f,+1.57445576e+00f,
-1.68708438e+00f,+7.31392440e-01f,-4.14397773e-01f,+1.84793689e+00f,-1.22586413e+00f,
+5.51612042e-01f,-1.84700054e+00f,+1.98522499e+00f,-1.29223482e+00f,+5.44484530e-01f,
-6.97434909e-01f,-1.10747359e+00f,+1.76991613e-01f,+2.43618026e-01f,+9.22519169e-01f,
+2.22418555e-01f,-9.19520544e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_2_test10_array[1] = {
+1.00000000e+00f,}; 
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

