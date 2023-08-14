#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void cPredictor(k2c_tensor* dense_input_input, k2c_tensor* dense_2_output) { 

float dense_output_array[6] = {0}; 
k2c_tensor dense_output = {&dense_output_array[0],1,6,{6,1,1,1,1}}; 
float dense_kernel_array[18] = {
+9.01413023e-01f,+7.23044634e-01f,+2.67693400e-01f,+5.82270503e-01f,+1.25352907e+00f,
-4.14479375e-02f,+1.00920737e+00f,+6.83510482e-01f,-1.83187604e-01f,+4.92129803e-01f,
+6.87204361e-01f,+4.44590896e-01f,+1.25994623e+00f,-9.52449217e-02f,-4.86628056e-01f,
-5.71051717e-01f,+1.59287095e+00f,-3.63909781e-01f,}; 
k2c_tensor dense_kernel = {&dense_kernel_array[0],2,18,{3,6,1,1,1}}; 
float dense_bias_array[6] = {
-8.94710363e-04f,-2.31882581e-03f,+0.00000000e+00f,-4.69598658e-02f,+6.45225355e-03f,
-9.36473012e-02f,}; 
k2c_tensor dense_bias = {&dense_bias_array[0],1,6,{6,1,1,1,1}}; 
float dense_fwork[21] = {0}; 

 
float dense_1_output_array[3] = {0}; 
k2c_tensor dense_1_output = {&dense_1_output_array[0],1,3,{3,1,1,1,1}}; 
float dense_1_kernel_array[18] = {
-3.16231906e-01f,+1.89181054e+00f,+3.00026059e-01f,+8.87042433e-02f,+5.69440305e-01f,
-6.66086137e-01f,+6.36769414e-01f,-2.13129103e-01f,+7.57231474e-01f,+6.73074901e-01f,
-4.42802250e-01f,-5.92034876e-01f,+1.97279409e-01f,+2.15919995e+00f,-1.44978628e-01f,
+9.76643562e-02f,+4.57860440e-01f,+3.82126212e-01f,}; 
k2c_tensor dense_1_kernel = {&dense_1_kernel_array[0],2,18,{6,3,1,1,1}}; 
float dense_1_bias_array[3] = {
-7.02133104e-02f,-4.70536239e-02f,-1.55706972e-01f,}; 
k2c_tensor dense_1_bias = {&dense_1_bias_array[0],1,3,{3,1,1,1,1}}; 
float dense_1_fwork[24] = {0}; 

 
float dense_2_kernel_array[3] = {
+1.10840571e+00f,-1.15657747e+00f,+9.42145050e-01f,}; 
k2c_tensor dense_2_kernel = {&dense_2_kernel_array[0],2,3,{3,1,1,1,1}}; 
float dense_2_bias_array[1] = {
+4.17345381e+00f,}; 
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

