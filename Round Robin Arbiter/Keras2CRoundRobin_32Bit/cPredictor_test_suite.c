#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "cPredictor.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_dense_input_input_array[64] = {
-3.31668978e-01f,-1.07444056e+00f,+9.73248472e-01f,-7.51972446e-01f,-1.12947671e+00f,
-9.04275940e-02f,+1.83440351e+00f,-1.83177088e+00f,-2.01800715e-01f,-1.03915022e+00f,
-1.34180339e+00f,-1.48812945e+00f,-1.08858367e+00f,-1.45218796e+00f,-1.26644446e+00f,
-1.33105574e+00f,+1.85814050e+00f,+1.39609575e+00f,+4.28902090e-01f,-1.69492647e-01f,
+6.66268568e-01f,+1.27148808e+00f,+1.73914142e+00f,-1.28754326e+00f,+7.83908496e-01f,
-3.77686753e-01f,-1.23085034e-01f,+3.30875687e-01f,+1.20840463e+00f,+1.31097407e+00f,
+1.27769472e+00f,+7.26944428e-01f,+3.75330588e-01f,+4.92394595e-01f,+1.60499307e+00f,
-1.12124510e+00f,+2.44303236e-01f,+5.29807226e-01f,-1.97595247e+00f,-4.18762303e-01f,
+4.73010188e-02f,+1.15327659e+00f,+9.49359191e-01f,-1.62271205e+00f,+1.63460916e+00f,
-9.39136005e-01f,+1.16197094e+00f,-3.32170557e-01f,-1.09243498e-01f,-1.35676756e+00f,
-5.66993199e-01f,+1.71336723e+00f,+1.86788540e+00f,+3.27175811e-01f,-1.39988470e+00f,
-1.55605598e-01f,-1.80372011e+00f,-5.84442754e-01f,-6.98055400e-01f,-1.16305688e+00f,
-3.81872343e-01f,+1.29687268e+00f,-5.83521722e-02f,-1.68515115e+00f,}; 
k2c_tensor test1_dense_input_input = {&test1_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test1_array[32] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+3.94070531e-17f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+1.79630500e-37f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+9.13593878e-29f,+0.00000000e+00f,+2.17582105e-20f,
+7.56263412e-31f,+3.34049841e-29f,+1.78183065e-21f,+0.00000000e+00f,+9.93585467e-01f,
+3.26051785e-20f,+5.49232757e-26f,+0.00000000e+00f,+6.87264104e-28f,+0.00000000e+00f,
+2.30151190e-27f,+1.04472067e-25f,+2.14210916e-02f,+0.00000000e+00f,+1.00000000e+00f,
+5.70292232e-29f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test1 = {&keras_dense_2_test1_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test1_array[32] = {0}; 
k2c_tensor c_dense_2_test1 = {&c_dense_2_test1_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test2_dense_input_input_array[64] = {
-2.21137180e-01f,+1.88597823e+00f,-3.68741877e-01f,-1.49381991e+00f,-1.38969215e+00f,
+1.40090173e+00f,+1.99367167e+00f,+3.87241052e-01f,+1.17395962e+00f,-4.35481214e-01f,
+5.14181202e-01f,-3.93144553e-01f,+1.14869458e+00f,+6.47367880e-01f,+3.87905573e-01f,
-1.60790824e-01f,+1.96472901e+00f,-1.98979109e+00f,+1.57774922e+00f,+1.95056719e+00f,
-5.76471893e-01f,+8.10089144e-01f,-3.74144143e-01f,-2.77321223e-01f,-1.23128402e-01f,
+1.02331234e+00f,+1.83917360e+00f,+1.51552597e+00f,-1.77303087e+00f,+2.74457598e-01f,
+2.98681285e-01f,+8.72577395e-01f,+1.49941355e+00f,+6.91490358e-01f,-2.73923830e-01f,
-7.44581986e-01f,-1.14333094e+00f,+7.94748027e-01f,-1.34352443e+00f,+7.11052878e-01f,
-1.46032851e+00f,-1.59236024e+00f,-1.33115233e+00f,-3.85100728e-01f,+1.53743173e-02f,
+6.88374261e-01f,-6.11268902e-01f,-1.72759903e+00f,-1.24241731e+00f,+1.88795178e+00f,
+8.12765154e-01f,+1.56284965e+00f,-8.20793969e-01f,+5.30582004e-01f,+1.27681075e+00f,
+1.18802944e+00f,-4.23705069e-01f,-4.71007938e-01f,-1.67813882e-01f,+6.31196139e-01f,
+1.57821942e+00f,+6.07808711e-01f,+1.94548121e+00f,-1.46934556e+00f,}; 
k2c_tensor test2_dense_input_input = {&test2_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test2_array[32] = {
+5.06348024e-17f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+8.04784759e-35f,+1.00000000e+00f,+1.00000000e+00f,+2.93750918e-12f,+1.78161264e-29f,
+0.00000000e+00f,+0.00000000e+00f,+2.83278404e-37f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+8.60517325e-36f,
+7.46012998e-19f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test2 = {&keras_dense_2_test2_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test2_array[32] = {0}; 
k2c_tensor c_dense_2_test2 = {&c_dense_2_test2_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test3_dense_input_input_array[64] = {
+2.39490671e-01f,+1.18090877e+00f,-6.48486629e-01f,-9.46571438e-01f,+1.12757814e+00f,
-2.83261594e-01f,+5.05883782e-02f,+1.35513616e+00f,+3.63951980e-01f,+1.73074356e+00f,
-1.20879017e+00f,-1.03092349e+00f,-1.39103810e+00f,-1.43623593e+00f,-9.78467207e-01f,
+4.70241381e-01f,-1.55331191e+00f,-1.48288528e+00f,+5.65210982e-01f,-1.65491824e+00f,
-1.71615721e+00f,-3.66713196e-01f,+2.37617190e-01f,-1.73300102e+00f,+1.84057523e+00f,
-1.16246542e-01f,-1.24465067e+00f,-1.66823513e+00f,+3.02666600e-02f,+1.59616711e+00f,
-1.02943569e+00f,-1.67886715e-01f,+5.70481470e-01f,-1.66961940e+00f,-1.18365502e-01f,
-1.38385570e+00f,+1.08663007e+00f,-7.04093806e-01f,-1.42830523e+00f,-1.96094110e+00f,
+5.73416846e-01f,-2.85307733e-01f,-7.82630898e-01f,+1.09437905e+00f,+3.11984785e-01f,
-1.81970328e-01f,+8.76103877e-01f,+1.19715807e+00f,-6.89654709e-01f,-1.61426297e-01f,
+1.86116035e-01f,-8.82621082e-01f,-1.83384886e+00f,+9.78876025e-03f,-1.99378111e+00f,
+1.92416582e+00f,-3.96097682e-02f,+1.40694575e+00f,-1.81543099e+00f,-1.49857056e+00f,
+1.62027182e+00f,-1.24831023e+00f,+1.00171606e+00f,+4.46904908e-01f,}; 
k2c_tensor test3_dense_input_input = {&test3_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test3_array[32] = {
+1.28729302e-28f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,+0.00000000e+00f,
+1.34218450e-33f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+6.69334243e-34f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+1.04243763e-36f,+0.00000000e+00f,+1.00000000e+00f,+9.24091637e-10f,
+3.46090582e-17f,+0.00000000e+00f,+4.73323236e-28f,+9.50593646e-27f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test3 = {&keras_dense_2_test3_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test3_array[32] = {0}; 
k2c_tensor c_dense_2_test3 = {&c_dense_2_test3_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test4_dense_input_input_array[64] = {
-1.94008125e+00f,+9.98918807e-01f,+1.52537203e-01f,-1.36048399e+00f,-1.63108701e+00f,
-1.88088612e+00f,+1.83022197e+00f,+1.12195971e+00f,+1.95793218e+00f,+1.47175398e+00f,
+1.05598671e-01f,+4.33622172e-01f,+8.14602945e-01f,-4.21803485e-01f,-1.63953219e+00f,
-2.09334577e-01f,+1.03592505e+00f,+1.66290732e+00f,+4.30786576e-01f,-1.34056726e+00f,
-7.00983058e-01f,-1.28164547e+00f,-1.60967393e+00f,+1.36713496e-01f,+1.96915336e+00f,
+1.85701744e-01f,-1.22192102e-01f,+3.72144000e-02f,+5.19667387e-01f,-8.17612666e-01f,
-1.59864997e+00f,+1.68779210e-02f,-4.76962249e-02f,+1.06176924e+00f,+9.88375571e-01f,
-1.81520576e-02f,-3.02161873e-02f,-6.77663354e-01f,-1.35194508e+00f,-1.44296154e+00f,
+8.61003686e-01f,-1.06638116e+00f,+1.03456525e+00f,-2.07954166e-01f,+6.85660561e-01f,
+2.23128713e-01f,+1.65941555e+00f,-1.71426790e+00f,+1.18648837e+00f,-2.32310603e-01f,
-1.79819333e-01f,+3.33924079e-01f,+1.97011979e+00f,+1.06961068e+00f,-7.22956635e-01f,
-1.66916804e+00f,+1.76583890e+00f,-1.82543856e+00f,-1.66019682e+00f,+6.48525006e-01f,
-1.03877705e+00f,+1.70177980e-01f,+1.78530826e+00f,-1.82604286e+00f,}; 
k2c_tensor test4_dense_input_input = {&test4_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test4_array[32] = {
+4.55070159e-23f,+5.84217209e-22f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+1.90628598e-15f,+7.56557902e-38f,+1.49932421e-14f,+0.00000000e+00f,
+8.10297056e-32f,+3.00324475e-30f,+9.85671341e-01f,+0.00000000e+00f,+3.36905116e-28f,
+0.00000000e+00f,+5.34623390e-21f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+1.54781087e-27f,+0.00000000e+00f,+2.27288983e-16f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test4 = {&keras_dense_2_test4_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test4_array[32] = {0}; 
k2c_tensor c_dense_2_test4 = {&c_dense_2_test4_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test5_dense_input_input_array[64] = {
+1.44082957e-02f,+2.89948098e-01f,+3.34061247e-01f,-6.93107823e-01f,+4.70079074e-01f,
-1.48848432e+00f,+7.39578990e-01f,+8.51013302e-01f,-1.78191265e+00f,-9.09127307e-01f,
-1.72484102e+00f,+1.38499096e+00f,+5.88386248e-01f,-8.27922842e-01f,-7.42439654e-01f,
+1.45019173e+00f,+1.41758945e+00f,-9.41556084e-02f,-3.83767049e-01f,+9.71919636e-01f,
-1.29983215e+00f,-1.17041833e+00f,-1.53693059e+00f,-1.30738610e+00f,+1.32750478e+00f,
+1.81943628e+00f,-1.63934764e+00f,-1.35964169e+00f,-6.76352199e-01f,+5.01977493e-01f,
+7.67472231e-01f,-8.30909625e-02f,-1.26127488e+00f,+7.72244137e-01f,-7.50680705e-01f,
+1.23014437e+00f,+1.22318872e+00f,+9.04997929e-01f,-8.42213981e-02f,-4.74127580e-01f,
-8.55544096e-01f,+2.72694504e-01f,-2.15830196e-01f,-1.68350292e+00f,+5.13226273e-01f,
+1.25224013e-01f,+6.86916046e-01f,-9.85007547e-01f,+1.18680539e+00f,+8.91222956e-01f,
-1.38694475e+00f,-1.00556873e+00f,+1.98562819e+00f,-1.46651721e+00f,+6.14847944e-02f,
+7.68165970e-01f,-1.73210908e+00f,+1.58539042e+00f,+7.47802183e-02f,+7.46190042e-01f,
+1.54719145e-01f,-1.21097896e+00f,+7.10793568e-01f,+1.52958775e+00f,}; 
k2c_tensor test5_dense_input_input = {&test5_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test5_array[32] = {
+2.85404514e-21f,+2.46494953e-24f,+0.00000000e+00f,+8.32425650e-25f,+0.00000000e+00f,
+1.26521704e-32f,+3.73930330e-26f,+0.00000000e+00f,+9.10335089e-12f,+4.68354328e-17f,
+2.99247214e-30f,+0.00000000e+00f,+6.85162194e-09f,+3.38931440e-21f,+4.92536079e-13f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test5 = {&keras_dense_2_test5_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test5_array[32] = {0}; 
k2c_tensor c_dense_2_test5 = {&c_dense_2_test5_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test6_dense_input_input_array[64] = {
+1.74904102e+00f,+4.23573539e-02f,+1.43693133e-02f,+4.51610466e-01f,+1.13413990e+00f,
-7.83055141e-01f,-1.75613637e+00f,+1.12070892e+00f,+9.97050091e-01f,-1.16458982e+00f,
-1.50082316e+00f,+1.49835976e+00f,-1.89956352e+00f,+1.57100290e+00f,+2.30243106e-01f,
-1.10738646e+00f,-1.35498049e+00f,-7.78973567e-01f,-9.01485891e-01f,-1.04663929e+00f,
+1.02711780e+00f,-1.33332813e+00f,+1.97813664e+00f,+8.72719001e-01f,-1.77131267e+00f,
+1.56852900e+00f,-8.15773160e-01f,-1.38100906e+00f,-7.41138664e-02f,-1.28697054e+00f,
-5.19507177e-01f,-1.03481031e-01f,+1.90167200e+00f,-9.36642322e-01f,-1.76543385e+00f,
+2.91423608e-01f,+1.62610961e+00f,+5.05922219e-01f,-2.13265579e-01f,-5.18785093e-01f,
-1.91451312e+00f,-1.61753757e+00f,+1.29661584e+00f,+1.32026417e+00f,-1.38238807e+00f,
+4.09256843e-01f,+8.27949520e-01f,-1.27016694e-01f,-1.50457687e+00f,+2.89427584e-01f,
+1.52579380e+00f,-3.77252015e-01f,-7.45144989e-01f,+2.92618718e-01f,+1.06434206e+00f,
-1.35101548e+00f,+1.93138540e+00f,+1.69706693e+00f,+2.05383645e-01f,+8.06462356e-01f,
+1.12469732e+00f,+6.19760354e-01f,+1.27237637e+00f,-1.48060774e+00f,}; 
k2c_tensor test6_dense_input_input = {&test6_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test6_array[32] = {
+2.20999017e-22f,+3.88214390e-16f,+2.10684518e-26f,+7.60780937e-14f,+0.00000000e+00f,
+1.05271786e-32f,+0.00000000e+00f,+0.00000000e+00f,+1.51495333e-33f,+9.95579243e-01f,
+1.00258536e-31f,+0.00000000e+00f,+0.00000000e+00f,+3.95043180e-08f,+9.28582636e-22f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+1.51053027e-04f,+0.00000000e+00f,+0.00000000e+00f,+2.85914556e-28f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+9.01265312e-11f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test6 = {&keras_dense_2_test6_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test6_array[32] = {0}; 
k2c_tensor c_dense_2_test6 = {&c_dense_2_test6_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test7_dense_input_input_array[64] = {
+9.65025257e-01f,+6.84786760e-01f,+1.13897216e+00f,-1.19277844e+00f,+1.38806488e+00f,
-1.73150374e+00f,-1.80736177e+00f,+4.88163520e-01f,-1.03262954e+00f,+6.77466349e-01f,
+5.42804538e-02f,+7.72073390e-01f,-4.05747807e-01f,-7.41026421e-01f,+6.23529410e-01f,
-4.43627239e-01f,+1.25755867e+00f,+1.55375222e+00f,+3.42487294e-02f,-1.00116735e+00f,
-9.07842371e-01f,+1.38488088e-02f,-1.94550119e+00f,-1.93996006e+00f,-9.82287152e-01f,
+9.28159128e-01f,+1.88150357e-01f,+5.91811328e-01f,-1.88602912e-01f,-5.57436409e-01f,
-7.31548708e-01f,+1.91285558e-01f,+1.92847556e+00f,-6.38470621e-01f,+1.93132465e+00f,
+1.16749941e+00f,-4.17168470e-01f,+2.79278809e-01f,-1.01250241e+00f,+1.88558322e-02f,
-9.03092099e-01f,-4.16405595e-01f,+6.17632539e-02f,+8.86442565e-01f,+1.11885692e+00f,
+1.40663820e+00f,+1.24825459e+00f,+5.43504270e-01f,-1.60495232e+00f,+1.08667910e+00f,
-1.92324007e+00f,+3.63197784e-01f,-1.25789018e+00f,-1.27617173e+00f,+1.86435377e+00f,
-3.57365954e-01f,+3.83034527e-01f,-1.01325134e+00f,+7.48982624e-01f,-9.37951547e-01f,
+1.41768109e+00f,-1.76517252e+00f,+2.05457175e-01f,-4.12613598e-01f,}; 
k2c_tensor test7_dense_input_input = {&test7_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test7_array[32] = {
+8.08737952e-16f,+2.67356557e-24f,+3.31257877e-38f,+1.18051275e-05f,+0.00000000e+00f,
+9.19788403e-33f,+3.31889652e-27f,+0.00000000e+00f,+1.83405281e-17f,+1.18977681e-03f,
+4.57443351e-34f,+0.00000000e+00f,+1.34198242e-29f,+4.85096477e-23f,+1.20900160e-18f,
+9.58821678e-25f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+4.95195570e-27f,
+8.14068200e-38f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test7 = {&keras_dense_2_test7_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test7_array[32] = {0}; 
k2c_tensor c_dense_2_test7 = {&c_dense_2_test7_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test8_dense_input_input_array[64] = {
+8.79938789e-03f,-1.98874400e+00f,+9.07810313e-01f,+8.44550589e-01f,-1.43419174e+00f,
+6.85247848e-01f,+5.66065704e-01f,-8.56898564e-01f,-7.14110643e-01f,+1.59388668e+00f,
+1.37996116e+00f,+1.79381322e+00f,+1.11290068e+00f,+1.51247847e+00f,-1.70925544e+00f,
-9.89075722e-01f,+1.86881951e+00f,+1.45484235e+00f,+8.33270288e-01f,-1.96720071e+00f,
-7.17882191e-01f,-5.38719169e-01f,+4.42921201e-01f,+1.23364012e+00f,-1.92161022e-01f,
+1.87343474e+00f,+3.21223327e-01f,+7.53145303e-01f,+6.18664288e-02f,-9.79477508e-01f,
+1.41112560e+00f,+9.13271660e-01f,-7.80339278e-01f,-1.50381104e+00f,-1.42367681e+00f,
+1.71235935e+00f,+2.70466885e-01f,+1.57149264e+00f,+7.45620555e-01f,-1.94213018e+00f,
-8.51797464e-01f,+3.14479732e-01f,-9.91679336e-01f,+1.43587391e+00f,+3.44327397e-02f,
+9.56171973e-01f,+7.29523605e-03f,+6.98288373e-01f,-1.06031866e+00f,+5.83662473e-01f,
+2.11478857e-02f,-4.46812015e-01f,-5.64737836e-01f,-8.22388954e-01f,+5.01374351e-01f,
+1.85213027e+00f,-3.19200965e-01f,+1.71062505e+00f,+1.28473302e+00f,+5.49915039e-01f,
-1.40733455e+00f,+6.55843399e-01f,+1.64596011e-01f,+1.98622588e+00f,}; 
k2c_tensor test8_dense_input_input = {&test8_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test8_array[32] = {
+0.00000000e+00f,+5.68166260e-37f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+9.68249235e-18f,+0.00000000e+00f,+5.79800390e-25f,+0.00000000e+00f,
+0.00000000e+00f,+1.00000000e+00f,+2.19553722e-22f,+0.00000000e+00f,+0.00000000e+00f,
+2.67409803e-07f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+5.30953120e-35f,
+0.00000000e+00f,+2.59600938e-38f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test8 = {&keras_dense_2_test8_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test8_array[32] = {0}; 
k2c_tensor c_dense_2_test8 = {&c_dense_2_test8_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test9_dense_input_input_array[64] = {
-1.37725358e+00f,-1.09120008e+00f,-1.81227553e+00f,+1.13999683e-01f,+1.71542227e+00f,
-1.71844744e+00f,-1.32259489e+00f,-1.82757825e+00f,-9.36074610e-01f,-1.68782680e+00f,
-7.64190761e-03f,+4.58068557e-01f,-1.99202355e+00f,-1.44476436e+00f,+6.94754068e-03f,
+7.90026982e-02f,+1.92083550e+00f,-1.82687279e+00f,-4.17396605e-01f,-5.46082703e-01f,
+1.42809338e-01f,+3.26548124e-01f,-1.31050331e+00f,+9.58306191e-02f,-1.54743567e+00f,
-1.73053303e-01f,+2.22575876e-01f,+6.82767001e-01f,+2.78702847e-01f,-8.52291900e-01f,
+1.44629137e+00f,-1.54800391e+00f,+1.12366559e+00f,+2.73945485e-01f,-3.96017140e-01f,
-1.52642185e+00f,+1.14130986e+00f,+1.35696866e-01f,+6.38982112e-01f,-1.20895997e+00f,
+1.52019462e+00f,+1.04816297e+00f,-1.55396220e-01f,+1.28716121e+00f,-3.42481899e-01f,
-1.73555415e+00f,-3.69723081e-01f,+5.93537087e-01f,-1.72468991e+00f,+1.01763967e+00f,
-1.94866138e-01f,-1.22169441e+00f,+1.95365229e+00f,+6.44169072e-02f,+1.77750744e+00f,
-1.50551163e+00f,+7.84533617e-01f,-1.56009028e+00f,+4.47148652e-01f,-1.91775979e+00f,
+6.14501786e-01f,+1.96869962e-01f,+1.27055197e+00f,+1.30293194e+00f,}; 
k2c_tensor test9_dense_input_input = {&test9_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test9_array[32] = {
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.00000000e+00f,+0.00000000e+00f,
+3.17285409e-32f,+2.54836243e-31f,+0.00000000e+00f,+5.41295412e-19f,+8.32528933e-21f,
+0.00000000e+00f,+0.00000000e+00f,+6.91198605e-17f,+1.95480382e-19f,+4.50818539e-01f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+1.41038554e-05f,
+2.72979542e-30f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test9 = {&keras_dense_2_test9_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test9_array[32] = {0}; 
k2c_tensor c_dense_2_test9 = {&c_dense_2_test9_array[0],1,32,{32, 1, 1, 1, 1}}; 
float test10_dense_input_input_array[64] = {
-4.92800369e-01f,-1.52974162e+00f,-1.53418375e+00f,+1.10830297e+00f,+1.61005634e+00f,
+1.83232258e+00f,-1.70043532e+00f,+9.66740835e-01f,+1.03600244e+00f,+1.15669282e+00f,
+1.86209622e+00f,+7.19522300e-01f,-7.22706232e-01f,+4.83272865e-01f,+4.24652659e-02f,
+1.97849243e+00f,-1.46138690e+00f,-2.55014541e-01f,-1.21720940e+00f,+9.55138332e-01f,
+1.54602870e+00f,-5.41290421e-01f,+9.75864347e-01f,+1.92509436e+00f,+1.55698938e+00f,
-4.90136178e-01f,-7.61203890e-01f,+5.10853285e-02f,+1.46327319e+00f,+1.12224543e+00f,
-1.90170224e+00f,+4.23297514e-02f,+1.40769308e+00f,+2.84563710e-01f,-1.50994724e+00f,
+7.41021995e-01f,+6.93388875e-01f,+1.55651733e-01f,-5.54939513e-01f,+1.81915389e-01f,
-1.94217548e+00f,+2.19899321e-01f,+1.80010831e+00f,+1.72547179e-01f,+1.29456799e+00f,
+8.51332867e-01f,+6.31381637e-01f,+3.61020556e-01f,-3.73976039e-01f,+1.81815054e+00f,
-1.72856901e+00f,+1.29717928e+00f,+1.87989067e+00f,+1.23372115e+00f,-1.80776964e+00f,
+1.61834219e+00f,-1.93373248e+00f,+1.52991630e+00f,-5.70496607e-01f,-1.84737827e+00f,
-4.79827202e-01f,-6.21418412e-01f,+3.01944106e-01f,-5.04943582e-01f,}; 
k2c_tensor test10_dense_input_input = {&test10_dense_input_input_array[0],1,64,{64, 1, 1, 1, 1}}; 
float keras_dense_2_test10_array[32] = {
+0.00000000e+00f,+0.00000000e+00f,+2.93585902e-29f,+1.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+2.70268892e-08f,+2.40596121e-36f,+6.44959108e-24f,+1.90041975e-11f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+8.53653606e-12f,+1.03246404e-11f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+4.35587284e-34f,+1.28681646e-36f,
+2.30682566e-38f,+9.95495677e-01f,+1.15926709e-32f,+4.57719427e-14f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,+0.00000000e+00f,
+0.00000000e+00f,+0.00000000e+00f,}; 
k2c_tensor keras_dense_2_test10 = {&keras_dense_2_test10_array[0],1,32,{32, 1, 1, 1, 1}}; 
float c_dense_2_test10_array[32] = {0}; 
k2c_tensor c_dense_2_test10 = {&c_dense_2_test10_array[0],1,32,{32, 1, 1, 1, 1}}; 
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
