#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[32] = {
-1.40238009e+00f,-1.65857351e+00f,-1.17048434e+00f,+3.28271532e-02f,+1.08513131e+00f,
-1.21783810e+00f,+1.50464406e-01f,+1.32705716e+00f,+4.49382403e-01f,+8.09756549e-01f,
+1.59895359e+00f,+1.56178289e+00f,+6.47065428e-01f,-1.58524980e+00f,+1.87199151e+00f,
+1.17532846e+00f,+1.06568600e+00f,+2.31850412e-01f,+6.84248126e-01f,+1.92062913e+00f,
+1.12070216e+00f,+5.08545389e-01f,+1.44825176e+00f,+1.42324539e+00f,-1.19576841e+00f,
+1.32041357e+00f,-9.32603735e-01f,-1.06950354e+00f,-1.91911446e+00f,+1.40163563e+00f,
-1.78103975e-01f,+1.40240207e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test1_array[32] = {
+1.74586694e-22f,+1.66008103e-15f,+4.11371818e-27f,+3.52144984e-23f,+2.82365267e-25f,
+1.50280623e-21f,+3.96441150e-15f,+1.56102198e-27f,+1.09333160e-15f,+1.41618087e-18f,
+1.19445442e-13f,+1.69984503e-29f,+5.01315072e-22f,+2.28110439e-18f,+4.59952178e-28f,
+1.34512079e-19f,+3.63491821e-26f,+1.48210007e-36f,+3.03338177e-34f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+5.20720278e-06f,+9.32085431e-22f,
+3.44507633e-15f,+2.06620027e-31f,+0.00000000e+00f,+0.00000000e+00f,+4.71195902e-27f,
+2.12789032e-22f,+1.15049001e-08f,}; 
k2c_tensor keras_dense_5_test1 = {&keras_dense_5_test1_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test1_array[32] = {0}; 
k2c_tensor c_dense_5_test1 = {&c_dense_5_test1_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test2_dense_input_input_array[32] = {
+1.52436644e+00f,+1.72050812e+00f,-1.95078932e+00f,+1.41655824e-01f,+6.05997971e-01f,
-1.45262522e+00f,+1.96944093e+00f,+6.42474237e-01f,-1.38057495e+00f,+6.59953734e-01f,
-1.58926314e+00f,+8.16110122e-01f,-1.29678946e+00f,+1.23272480e+00f,+8.96890164e-01f,
+1.59414464e+00f,-3.07421375e-01f,+4.23828036e-01f,+1.12371529e+00f,-6.46693546e-01f,
-1.02972323e+00f,-6.84947744e-01f,-1.45708429e+00f,+3.30610866e-01f,-1.99361994e+00f,
-5.84367935e-01f,+1.68118571e+00f,+4.11911277e-01f,+3.21500076e-02f,+1.78290959e+00f,
-1.68291508e+00f,+5.79444771e-02f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test2_array[32] = {
+9.01252088e-25f,+1.97624098e-18f,+5.26850840e-22f,+6.36791621e-23f,+4.94274182e-21f,
+3.58850844e-15f,+2.41192086e-17f,+4.05289872e-24f,+7.27485629e-16f,+7.16375558e-26f,
+2.30012157e-15f,+3.26896922e-23f,+1.79669916e-18f,+1.79121181e-17f,+1.03381463e-17f,
+3.36070365e-23f,+1.58309032e-12f,+9.27233754e-15f,+1.33168882e-18f,+3.98994756e-29f,
+0.00000000e+00f,+9.38092123e-15f,+9.72084343e-01f,+6.61518826e-11f,+2.74640038e-13f,
+7.69939903e-36f,+0.00000000e+00f,+1.08596077e-32f,+3.87107950e-25f,+5.64840483e-03f,
+2.13854953e-23f,+6.48146664e-36f,}; 
k2c_tensor keras_dense_5_test2 = {&keras_dense_5_test2_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test2_array[32] = {0}; 
k2c_tensor c_dense_5_test2 = {&c_dense_5_test2_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test3_dense_input_input_array[32] = {
-5.14286044e-01f,+7.76948285e-01f,-1.00916191e+00f,+6.33226402e-01f,-1.73275921e+00f,
+5.65848500e-01f,-1.76623912e-01f,+1.84098747e+00f,+7.12287654e-01f,+1.84394446e-01f,
+1.44219536e+00f,+1.35017762e+00f,+2.04220809e-01f,-1.65124612e+00f,-1.08915167e+00f,
+1.60767644e+00f,-1.60596141e+00f,+1.14760187e+00f,-3.21914892e-02f,+2.75589590e-02f,
+4.29722355e-01f,+3.51704437e-01f,-7.73799416e-01f,+1.66724082e+00f,-3.26269857e-01f,
-1.42572250e+00f,+5.73252887e-01f,-1.34975216e+00f,-9.27436923e-01f,+5.31099466e-01f,
-1.69782468e+00f,+1.52748730e+00f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test3_array[32] = {
+1.37065653e-20f,+8.94774371e-17f,+4.02292619e-23f,+2.64522951e-14f,+5.70153728e-19f,
+5.77145265e-19f,+5.42905666e-14f,+2.86819583e-17f,+1.01596649e-19f,+1.09802543e-15f,
+1.99439638e-16f,+3.16837413e-20f,+1.88168517e-15f,+8.13996148e-17f,+9.73843928e-23f,
+3.51650350e-19f,+1.51387407e-13f,+2.97462172e-18f,+1.58428483e-14f,+7.80569887e-10f,
+6.22863370e-26f,+0.00000000e+00f,+6.56134125e-15f,+5.76307648e-04f,+9.24537182e-01f,
+9.35584219e-28f,+5.34686072e-23f,+8.59061086e-36f,+4.50528561e-33f,+5.61551627e-28f,
+1.68932551e-24f,+6.23408047e-10f,}; 
k2c_tensor keras_dense_5_test3 = {&keras_dense_5_test3_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test3_array[32] = {0}; 
k2c_tensor c_dense_5_test3 = {&c_dense_5_test3_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test4_dense_input_input_array[32] = {
+1.31139832e+00f,-1.36289575e+00f,-1.39671816e+00f,-1.67079733e+00f,+1.90810928e-02f,
-1.29310337e+00f,-5.27704245e-01f,-1.88085985e+00f,-1.49394665e+00f,-1.40222595e+00f,
+5.75096601e-01f,+1.21877783e+00f,-4.86068763e-01f,-1.69148507e+00f,-1.87747142e-01f,
+5.35432474e-01f,-1.17650686e+00f,-5.08984865e-01f,-1.85031640e+00f,+1.75798683e-01f,
-1.16060692e-04f,-1.56161032e-01f,-5.96168158e-01f,-3.47333297e-01f,+1.14384659e+00f,
-2.67070081e-01f,+1.15163911e+00f,-5.33537276e-01f,+8.84573974e-01f,+1.11781060e+00f,
-6.99196241e-01f,-3.16275668e-01f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test4_array[32] = {
+5.01655109e-24f,+3.28785235e-16f,+2.24911475e-20f,+8.04532302e-22f,+2.45562439e-21f,
+5.49944400e-15f,+5.83844670e-16f,+3.05578645e-26f,+1.18074192e-12f,+3.97809346e-29f,
+1.34794864e-15f,+3.95215199e-22f,+8.62878901e-14f,+2.57816473e-13f,+7.78415418e-14f,
+4.33569111e-22f,+1.46959511e-11f,+1.48979217e-21f,+1.69936535e-29f,+0.00000000e+00f,
+0.00000000e+00f,+6.58440892e-15f,+8.21642220e-14f,+1.87567306e-22f,+2.43072218e-13f,
+5.43798130e-17f,+0.00000000e+00f,+5.35650325e-28f,+1.83917386e-25f,+1.00000000e+00f,
+1.45735698e-16f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_5_test4 = {&keras_dense_5_test4_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test4_array[32] = {0}; 
k2c_tensor c_dense_5_test4 = {&c_dense_5_test4_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test5_dense_input_input_array[32] = {
+1.75773313e+00f,-1.62001350e+00f,-7.34838379e-01f,+1.54976352e+00f,+1.96592934e+00f,
+2.43807262e-01f,-1.16251977e+00f,-1.68230491e+00f,+8.17373134e-01f,-8.54068124e-01f,
-6.18865370e-01f,+2.07822911e-01f,+1.60945049e+00f,-5.78049974e-01f,+7.49095614e-01f,
+1.65736600e+00f,+8.21323396e-01f,-7.23413221e-01f,-1.26978851e-01f,-6.52511325e-01f,
-7.32243422e-01f,+1.83126773e+00f,+8.34990580e-01f,-5.83154374e-01f,-9.75476209e-01f,
+7.62664821e-01f,-7.54912314e-01f,-3.32358217e-01f,+1.49361573e+00f,-1.55555798e-01f,
-1.26429815e+00f,-1.69102036e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test5_array[32] = {
+0.00000000e+00f,+4.42862170e-34f,+1.14908024e-30f,+0.00000000e+00f,+0.00000000e+00f,
+5.77292024e-29f,+1.26392429e-32f,+0.00000000e+00f,+8.13763706e-31f,+0.00000000e+00f,
+5.05092008e-25f,+0.00000000e+00f,+2.47233386e-38f,+2.30278652e-26f,+4.78566034e-23f,
+0.00000000e+00f,+3.12806990e-28f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+8.96731861e-18f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+2.70571969e-32f,+0.00000000e+00f,+2.84128984e-30f,+5.25973634e-28f,+1.00000000e+00f,
+9.04222568e-28f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_5_test5 = {&keras_dense_5_test5_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test5_array[32] = {0}; 
k2c_tensor c_dense_5_test5 = {&c_dense_5_test5_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test6_dense_input_input_array[32] = {
+1.62521666e+00f,-9.90439884e-01f,+7.27115288e-01f,-1.62447765e+00f,-3.18645374e-02f,
+1.65492308e+00f,-1.83088070e+00f,+1.14661452e+00f,-1.39293232e+00f,+4.74921965e-01f,
+4.43361552e-01f,+1.73569737e+00f,-1.25071204e+00f,-1.90015126e+00f,-5.44548681e-01f,
-1.42497117e+00f,+1.04169595e+00f,+1.19991870e+00f,+6.20447267e-01f,-1.89312040e+00f,
-1.09476069e+00f,-1.54243212e+00f,-6.57219484e-01f,+1.88128580e+00f,-9.55112100e-01f,
+1.05035008e+00f,+2.85586520e-02f,+1.43123394e+00f,-1.01215861e+00f,+1.65147939e+00f,
-1.41606456e+00f,+2.40191489e-01f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test6_array[32] = {
+1.32888588e-28f,+9.48206264e-21f,+1.40869801e-24f,+3.77726260e-28f,+1.47894015e-25f,
+1.37149472e-18f,+7.17231197e-19f,+2.31130739e-32f,+6.37885226e-17f,+4.44916854e-31f,
+1.12646266e-17f,+3.33381675e-28f,+3.42152280e-18f,+3.84695471e-16f,+6.59135666e-19f,
+1.23030978e-26f,+4.61327164e-17f,+1.17704807e-30f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+7.59229871e-29f,+2.15283967e-24f,+7.70720573e-16f,+5.69292373e-29f,
+3.18570337e-21f,+0.00000000e+00f,+2.58108374e-27f,+2.00224797e-31f,+1.00000000e+00f,
+9.04825225e-23f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_5_test6 = {&keras_dense_5_test6_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test6_array[32] = {0}; 
k2c_tensor c_dense_5_test6 = {&c_dense_5_test6_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test7_dense_input_input_array[32] = {
-1.69275415e-01f,+1.75009729e+00f,+2.06401181e-01f,-3.92824435e-01f,-4.46922269e-01f,
-2.85071178e-01f,+1.29708635e-01f,+7.46100600e-01f,-1.93146273e-01f,+3.85755884e-01f,
-1.08919933e+00f,-5.53706242e-01f,+9.46718111e-01f,-1.60253361e+00f,-1.26472336e+00f,
-5.73500624e-01f,+1.32127115e+00f,+1.15626520e+00f,-9.29441536e-01f,-1.10690033e+00f,
+1.16788118e+00f,-1.92083354e+00f,+7.46690685e-01f,+9.37663008e-01f,+1.83762196e+00f,
+1.43844095e+00f,+1.27372517e+00f,+1.28381633e+00f,+1.77013338e+00f,-1.47071701e+00f,
-1.32439194e+00f,+1.29066792e+00f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test7_array[32] = {
+1.46659026e-34f,+3.61048429e-34f,+1.48133140e-36f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+5.93790920e-37f,+7.22685570e-34f,+0.00000000e+00f,+1.10956238e-30f,
+1.12363815e-33f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+4.97410659e-27f,+3.32910003e-14f,+3.89615343e-06f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+4.96961506e-33f,+0.00000000e+00f,
+1.63417521e-38f,+5.48916432e-06f,}; 
k2c_tensor keras_dense_5_test7 = {&keras_dense_5_test7_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test7_array[32] = {0}; 
k2c_tensor c_dense_5_test7 = {&c_dense_5_test7_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test8_dense_input_input_array[32] = {
-1.84395257e+00f,+1.32267068e+00f,+1.39456525e+00f,-1.05458200e+00f,+1.59659540e+00f,
+1.22622789e+00f,-2.12715436e-01f,+9.52779027e-01f,+8.94203158e-01f,+8.72564895e-01f,
+9.35778820e-01f,+1.33369542e+00f,+5.62179211e-01f,-1.21691287e+00f,-4.92671845e-02f,
-1.45150781e+00f,+1.37737094e+00f,-1.78121555e+00f,+1.02630346e+00f,-1.39023597e+00f,
-3.41927014e-01f,-4.41321245e-01f,+6.23935857e-01f,+1.53063189e-01f,-1.85893605e-01f,
-4.47219049e-01f,-1.93702194e-01f,+9.15693859e-01f,+3.99592190e-01f,+1.65884604e+00f,
+8.35341384e-01f,-2.83930891e-02f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test8_array[32] = {
+1.04390020e-17f,+1.47848009e-14f,+9.11117442e-18f,+3.14323166e-24f,+2.82415520e-20f,
+3.03899076e-17f,+2.32409890e-11f,+2.63011031e-30f,+2.18543806e-19f,+1.04957107e-23f,
+1.92811506e-13f,+2.83692080e-33f,+9.71081201e-21f,+3.91690183e-19f,+7.81687085e-18f,
+5.11471422e-16f,+1.82676964e-25f,+6.94140033e-38f,+1.14237331e-34f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+9.90823033e-37f,+0.00000000e+00f,+1.74290611e-29f,+1.22176065e-18f,+6.65171173e-12f,
+1.00000000e+00f,+1.87669936e-19f,}; 
k2c_tensor keras_dense_5_test8 = {&keras_dense_5_test8_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test8_array[32] = {0}; 
k2c_tensor c_dense_5_test8 = {&c_dense_5_test8_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test9_dense_input_input_array[32] = {
+5.67441617e-01f,+1.37955878e+00f,+4.62646464e-01f,+1.24559318e+00f,+4.63289697e-01f,
+9.31201219e-01f,+9.38381467e-02f,+1.15181774e+00f,-9.51799582e-01f,+1.60885292e+00f,
+1.74333079e+00f,+1.86503859e+00f,-1.46403166e+00f,-4.50952928e-01f,+3.90665427e-01f,
+8.58183516e-01f,-1.97535553e+00f,-1.47516856e+00f,+1.16892295e+00f,+1.90893173e-01f,
-1.06133404e+00f,-7.78202629e-01f,-1.68680369e+00f,+4.01183167e-01f,+3.17510189e-01f,
-1.26873066e+00f,+1.49783172e+00f,-1.98425740e+00f,-1.94611648e+00f,+2.75979224e-01f,
-1.13540262e+00f,+1.88053682e-01f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test9_array[32] = {
+5.79437303e-34f,+1.85785354e-32f,+7.81738952e-30f,+7.45923648e-22f,+1.88001654e-27f,
+3.67322103e-27f,+4.21359665e-22f,+1.45096496e-26f,+1.87577022e-25f,+1.76175624e-22f,
+3.99155856e-23f,+2.51403535e-32f,+1.61470851e-19f,+2.16901774e-27f,+2.56777622e-20f,
+1.45651301e-30f,+2.52459092e-22f,+1.39820762e-20f,+1.03004981e-20f,+7.49163506e-21f,
+2.10951099e-15f,+7.10721075e-36f,+0.00000000e+00f,+1.27527002e-27f,+8.16949844e-01f,
+1.15885371e-28f,+3.94336246e-02f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+7.06180018e-31f,+1.20010512e-34f,}; 
k2c_tensor keras_dense_5_test9 = {&keras_dense_5_test9_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test9_array[32] = {0}; 
k2c_tensor c_dense_5_test9 = {&c_dense_5_test9_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test10_dense_input_input_array[32] = {
-1.70575333e+00f,-1.72223242e+00f,-1.46206646e+00f,-1.59033930e+00f,+1.00556736e+00f,
-1.89608325e+00f,+7.42766765e-01f,-1.37524345e+00f,-1.17276051e+00f,+1.22844512e+00f,
+9.24296439e-01f,-1.42119491e+00f,+1.39818691e+00f,+1.22952878e+00f,-5.87180730e-01f,
+1.13151405e+00f,+1.81662621e+00f,+8.26849202e-01f,-1.26259278e+00f,+1.24503911e+00f,
-1.44086119e+00f,-1.60289525e+00f,+8.29711876e-02f,+5.78457951e-01f,+7.93809219e-01f,
-1.70546993e+00f,+5.10835291e-01f,+1.39883907e+00f,+1.47832258e+00f,+1.01490402e+00f,
+1.74964179e+00f,+7.02410352e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,32,{32, 1, 1, 1, 1}}; 
float keras_dense_5_test10_array[32] = {
+9.04629155e-14f,+7.19526131e-12f,+2.52997942e-15f,+7.79913853e-28f,+2.68649199e-21f,
+1.00387122e-16f,+2.94936749e-11f,+1.30168382e-26f,+5.98687821e-22f,+1.49099977e-18f,
+2.21590216e-12f,+1.84205448e-38f,+9.82584960e-27f,+1.26540633e-23f,+2.11685729e-20f,
+9.60981918e-14f,+3.75935789e-32f,+3.90224852e-38f,+2.07964042e-26f,+3.38730268e-33f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+2.03268006e-36f,+3.38388049e-18f,+1.58360648e-31f,
+1.00000000e+00f,+2.36790089e-04f,}; 
k2c_tensor keras_dense_5_test10 = {&keras_dense_5_test10_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_5_test10_array[32] = {0}; 
k2c_tensor c_dense_5_test10 = {&c_dense_5_test10_array[0],1,32,{32, 1, 1, 1, 1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
cPredictor_initialize(); 
clock_t t0 = clock(); 
cPredictor(&test1_dense_input_input,&c_dense_5_test1); 
cPredictor(&test2_dense_input_input,&c_dense_5_test2); 
cPredictor(&test3_dense_input_input,&c_dense_5_test3); 
cPredictor(&test4_dense_input_input,&c_dense_5_test4); 
cPredictor(&test5_dense_input_input,&c_dense_5_test5); 
cPredictor(&test6_dense_input_input,&c_dense_5_test6); 
cPredictor(&test7_dense_input_input,&c_dense_5_test7); 
cPredictor(&test8_dense_input_input,&c_dense_5_test8); 
cPredictor(&test9_dense_input_input,&c_dense_5_test9); 
cPredictor(&test10_dense_input_input,&c_dense_5_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_dense_5_test1,&c_dense_5_test1); 
errors[1] = maxabs(&keras_dense_5_test2,&c_dense_5_test2); 
errors[2] = maxabs(&keras_dense_5_test3,&c_dense_5_test3); 
errors[3] = maxabs(&keras_dense_5_test4,&c_dense_5_test4); 
errors[4] = maxabs(&keras_dense_5_test5,&c_dense_5_test5); 
errors[5] = maxabs(&keras_dense_5_test6,&c_dense_5_test6); 
errors[6] = maxabs(&keras_dense_5_test7,&c_dense_5_test7); 
errors[7] = maxabs(&keras_dense_5_test8,&c_dense_5_test8); 
errors[8] = maxabs(&keras_dense_5_test9,&c_dense_5_test9); 
errors[9] = maxabs(&keras_dense_5_test10,&c_dense_5_test10); 
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
