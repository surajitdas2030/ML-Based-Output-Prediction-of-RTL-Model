#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void cPredictor(k2c_tensor* dense_input_input, k2c_tensor* dense_1_output) { 

float dense_output_array[2] = {0}; 
k2c_tensor dense_output = {&dense_output_array[0],1,2,{2,1,1,1,1}}; 
float dense_kernel_array[4] = {
+1.90704718e-01f,+5.23172021e-01f,-5.39822519e-01f,+4.11249208e+00f,}; 
k2c_tensor dense_kernel = {&dense_kernel_array[0],2,4,{2,2,1,1,1}}; 
float dense_bias_array[2] = {
-2.07356468e-01f,-5.23395777e-01f,}; 
k2c_tensor dense_bias = {&dense_bias_array[0],1,2,{2,1,1,1,1}}; 
float dense_fwork[6] = {0}; 

 
float dense_1_kernel_array[2] = {
-3.70725691e-01f,-2.31364512e+00f,}; 
k2c_tensor dense_1_kernel = {&dense_1_kernel_array[0],2,2,{2,1,1,1,1}}; 
float dense_1_bias_array[1] = {
+4.09209108e+00f,}; 
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

