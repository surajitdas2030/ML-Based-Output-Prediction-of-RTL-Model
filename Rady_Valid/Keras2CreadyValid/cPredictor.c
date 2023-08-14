#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void cPredictor(k2c_tensor* dense_6_input_input, k2c_tensor* dense_8_output) { 

float dense_6_output_array[4] = {0}; 
k2c_tensor dense_6_output = {&dense_6_output_array[0],1,4,{4,1,1,1,1}}; 
float dense_6_kernel_array[8] = {
-9.27543402e-01f,-5.42030752e-01f,-1.02453804e+00f,+7.26630449e-01f,+1.90439761e-01f,
+2.98037708e-01f,+4.82645929e-01f,-1.51376224e+00f,}; 
k2c_tensor dense_6_kernel = {&dense_6_kernel_array[0],2,8,{2,4,1,1,1}}; 
float dense_6_bias_array[4] = {
-2.02917397e-01f,+2.18833223e-01f,+5.25130630e-01f,+7.59753108e-01f,}; 
k2c_tensor dense_6_bias = {&dense_6_bias_array[0],1,4,{4,1,1,1,1}}; 
float dense_6_fwork[10] = {0}; 

 
float dense_7_output_array[2] = {0}; 
k2c_tensor dense_7_output = {&dense_7_output_array[0],1,2,{2,1,1,1,1}}; 
float dense_7_kernel_array[8] = {
-7.12091684e-01f,-1.89361483e-01f,-8.13766718e-01f,+9.12455022e-01f,-1.91303492e-01f,
+2.84442568e+00f,-4.57549334e-01f,+2.29871988e+00f,}; 
k2c_tensor dense_7_kernel = {&dense_7_kernel_array[0],2,8,{4,2,1,1,1}}; 
float dense_7_bias_array[2] = {
+0.00000000e+00f,-1.49719603e-02f,}; 
k2c_tensor dense_7_bias = {&dense_7_bias_array[0],1,2,{2,1,1,1,1}}; 
float dense_7_fwork[12] = {0}; 

 
float dense_8_kernel_array[2] = {
+9.77416039e-02f,-2.48737097e+00f,}; 
k2c_tensor dense_8_kernel = {&dense_8_kernel_array[0],2,2,{2,1,1,1,1}}; 
float dense_8_bias_array[1] = {
+2.07747388e+00f,}; 
k2c_tensor dense_8_bias = {&dense_8_bias_array[0],1,1,{1,1,1,1,1}}; 
float dense_8_fwork[4] = {0}; 

 
k2c_dense(&dense_6_output,dense_6_input_input,&dense_6_kernel, 
	&dense_6_bias,k2c_relu,dense_6_fwork); 
k2c_dense(&dense_7_output,&dense_6_output,&dense_7_kernel, 
	&dense_7_bias,k2c_relu,dense_7_fwork); 
k2c_dense(dense_8_output,&dense_7_output,&dense_8_kernel, 
	&dense_8_bias,k2c_sigmoid,dense_8_fwork); 

 } 

void cPredictor_initialize() { 

} 

void cPredictor_terminate() { 

} 

