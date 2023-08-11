#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int print_matrix(int row, int col, double* m);
double * matrix_mul(int row1, int col1, double* m1, int row2, int col2, double* m2);
double* matrix_trans(int row1, int col1, double* m1);
double* matrix_add(int row1, int col1, double* m1, int row2, int col2, double* m2);


////////////////////////////////////////////////////////////////////////////////
int print_matrix(int row, int col, double* m)
{
int i,j;
int k;
k=row;
printf("\n");
for (i=0; i<row; i++)
	{
	for (j=0;j<col;j++)
		{
		
		//printf("%lf \t", *( m + i*col + j) );
		}
	printf("\n");
	}

}

////////////////////////////////////////////////////////////////////////////////
double* matrix_mul(int row1, int col1, double* m1, int row2, int col2, double* m2)
{
int i,j,k;
double sum=0;
double * mul =(double *)malloc(sizeof(double)*row1*col2);
if ( col1 != row2 )
	{
	printf("Matrix multiplication is not possible ------->> (col1 != row2):\n");
	}
else
	{
	for ( i = 0 ; i < row1 ; i++ )
 	   {
 	     for ( j = 0 ; j < col2 ; j++ )
 	     {
		sum = 0;
 	       for ( k = 0 ; k < col1 ; k++ )
 	       {
 	         //sum = sum + first[i][k]*second[k][j];
		double el1,el2;
		el1 = *(m1 + i*col1 + k);
		el2 = *(m2 + k*col2 + j);
		//printf("sum=%lf \t",sum);
		sum = sum + el1 * el2;
		//printf("%lf * %lf sum=%lf\t",el1,el2,sum);
		*(mul + i*row1 + j) = sum ;
 	       }
	//printf("\n");
         //multiply[i][j] = sum;
	 //*(mul + i*row1 + col2) = sum ;
      	  //sum = 0;
      	     }
    	   }
	}
//printf("Matrix Multiplication:\t");
//printf("(row1=%d \t col1=%d )\t (row2=%d \t col2=%d)\n", row1,col1,row2,col2);
//print_matrix(row1, col2, mul);
return mul;
}

////////////////////////////////////////////////////////////////////////////////
double* matrix_trans(int row1, int col1, double* m1)
{
int i,j,k;
double sum=0;
double * transpose =(double *)malloc(sizeof(double)*row1*col1);

	for ( i = 0 ; i < row1 ; i++ )
 	   {
 	     for ( j = 0 ; j < col1 ; j++ )
 	     {	
		//adj[j][i]=m1[i][j];
		*(transpose + j*row1 + i) = *(m1 + i*col1 +j );
		
 	      }
	
    	   }
	
//printf("Transpose of Matrix :\n");
//print_matrix(col1, row1, transpose);
return transpose;
}

////////////////////////////////////////////////////////////////////////////////
double* matrix_add(int row1, int col1, double* m1, int row2, int col2, double* m2)
{
int i,j,k;
double sum=0;
double * add =(double *)malloc(sizeof(double)*row1*col1);
if ( (col1 != col2) && (row1!=row2) )
	{
//	printf("Matrix addition is not possible ------->> (col1 != row2):\n");
	return NULL;
	}
else
	{
	for ( i = 0 ; i < row1 ; i++ )
 	   {
 	     for ( j = 0 ; j < col2 ; j++ )
 	     {
		//add[i][j] = m1[i][j] + m2[i][j];
		*(add + i*col1 + j) = *(m1 + i*col1 + j) + *(m2 + i*col1 + j) ;
	
 	      }
	
      	
    	   }
	}
//printf("Matrix addition of:\n");
//printf("(row1=%d \t col1=%d )\t (row2=%d \t col2=%d)\n", row1,col1,row2,col2);
//print_matrix(row1, col1, add);
return add;
}

