#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void cPredictor(k2c_tensor* dense_input_input, k2c_tensor* dense_2_output) { 

float dense_output_array[6] = {0}; 
k2c_tensor dense_output = {&dense_output_array[0],1,6,{6,1,1,1,1}}; 
float dense_kernel_array[18] = {
-3.48017454e-01f,+8.65927398e-01f,-7.66946435e-01f,-5.96756399e-01f,+4.45371807e-01f,
-3.63455921e-01f,-3.76334816e-01f,+3.77951980e-01f,+7.38771021e-01f,-3.96311462e-01f,
-1.65038466e-01f,+5.30947864e-01f,+1.02291405e-01f,-1.16573822e+00f,-5.39036453e-01f,
-3.91008914e-01f,-4.50239390e-01f,-1.93694934e-01f,}; 
k2c_tensor dense_kernel = {&dense_kernel_array[0],2,18,{3,6,1,1,1}}; 
float dense_bias_array[6] = {
+0.00000000e+00f,+2.98633516e-01f,+2.47479398e-02f,+0.00000000e+00f,+8.61575603e-02f,
+2.21752515e-03f,}; 
k2c_tensor dense_bias = {&dense_bias_array[0],1,6,{6,1,1,1,1}}; 
float dense_fwork[21] = {0}; 

 
float dense_1_output_array[3] = {0}; 
k2c_tensor dense_1_output = {&dense_1_output_array[0],1,3,{3,1,1,1,1}}; 
float dense_1_kernel_array[18] = {
+7.37571836e-01f,-4.52567011e-01f,-2.79949903e-02f,+2.76401937e-01f,-1.00377095e+00f,
+1.31510484e+00f,+9.12495315e-01f,+4.56073791e-01f,+1.31892383e-01f,-4.67321843e-01f,
+2.87226319e-01f,-2.82579601e-01f,-7.90856123e-01f,+5.57047307e-01f,+1.19323456e+00f,
+6.98071599e-01f,+9.81866047e-02f,+3.67595106e-02f,}; 
k2c_tensor dense_1_kernel = {&dense_1_kernel_array[0],2,18,{6,3,1,1,1}}; 
float dense_1_bias_array[3] = {
+2.19655223e-02f,+8.68783474e-01f,-9.67592597e-02f,}; 
k2c_tensor dense_1_bias = {&dense_1_bias_array[0],1,3,{3,1,1,1,1}}; 
float dense_1_fwork[24] = {0}; 

 
float dense_2_kernel_array[3] = {
+1.22827327e+00f,-1.63946795e+00f,+1.67823017e+00f,}; 
k2c_tensor dense_2_kernel = {&dense_2_kernel_array[0],2,3,{3,1,1,1,1}}; 
float dense_2_bias_array[1] = {
-6.21630967e-01f,}; 
k2c_tensor dense_2_bias = {&dense_2_bias_array[0],1,1,{1,1,1,1,1}}; 
float dense_2_fwork[6] = {0}; 

 
k2c_dense(&dense_output,dense_input_input,&dense_kernel, 
	&dense_bias,k2c_relu,dense_fwork); 
k2c_dense(&dense_1_output,&dense_output,&dense_1_kernel, 
	&dense_1_bias,k2c_relu,dense_1_fwork); 
k2c_dense(dense_2_output,&dense_1_output,&dense_2_kernel, 
	&dense_2_bias,k2c_sigmoid,dense_2_fwork); 

 } 

void cPredictor_initialize() { 

} 

void cPredictor_terminate() { 

} 

