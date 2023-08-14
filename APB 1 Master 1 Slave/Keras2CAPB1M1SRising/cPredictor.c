#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void cPredictor(k2c_tensor* dense_input_input, k2c_tensor* dense_1_output) { 

float dense_output_array[2] = {0}; 
k2c_tensor dense_output = {&dense_output_array[0],1,2,{2,1,1,1,1}}; 
float dense_kernel_array[4] = {
-1.09127808e+00f,+2.82299966e-01f,-6.51309729e-01f,+3.35353827e+00f,}; 
k2c_tensor dense_kernel = {&dense_kernel_array[0],2,4,{2,2,1,1,1}}; 
float dense_bias_array[2] = {
+0.00000000e+00f,-2.82461196e-01f,}; 
k2c_tensor dense_bias = {&dense_bias_array[0],1,2,{2,1,1,1,1}}; 
float dense_fwork[6] = {0}; 

 
float dense_1_kernel_array[2] = {
+8.84957433e-01f,-2.94057989e+00f,}; 
k2c_tensor dense_1_kernel = {&dense_1_kernel_array[0],2,2,{2,1,1,1,1}}; 
float dense_1_bias_array[1] = {
+4.25714827e+00f,}; 
k2c_tensor dense_1_bias = {&dense_1_bias_array[0],1,1,{1,1,1,1,1}}; 
float dense_1_fwork[4] = {0}; 

 
k2c_dense(&dense_output,dense_input_input,&dense_kernel, 
	&dense_bias,k2c_relu,dense_fwork); 
k2c_dense(dense_1_output,&dense_output,&dense_1_kernel, 
	&dense_1_bias,k2c_sigmoid,dense_1_fwork); 

 } 

void cPredictor_initialize() { 

} 

void cPredictor_terminate() { 

} 

