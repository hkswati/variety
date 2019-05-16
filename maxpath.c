// compile with: gcc -o maxpath maxpath.c -lm
// give file as a command line argument: ./maxpath filename

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define N 100
int maxPathSum(int pyramid[][N], int m, int n); 
int main(int argc, char *argv[])
{
    FILE *fptr;
	char *argfilename = argv[1];
	int num_of_lines = 1;
	char c;
	fptr = fopen(argfilename,"r");
    for (c = getc(fptr); c != EOF; c = getc(fptr)) {
        if (c == '\n') // Increment count if this character is newline 
            num_of_lines = num_of_lines + 1; 
    }
  
    // Close the file 
    fclose(fptr); 

    int pyramid[][N] = {0};
    
	fptr = fopen(argfilename,"r");
	int row = 0;
	int col = 0;
	while(!feof(fptr)) {
		
		int number; 
		fscanf(fptr,"%d\n", &number); 
		pyramid[row][col] = number;
		if(col < row){
			col++;
		}
		else if(col == row){
			row++;
			col = 0;
		}

	}

   int x = maxPathSum(pyramid,num_of_lines-1 , num_of_lines-1);
   printf("%d\n", x); 
   return 0; 

          
}
 

int is_composite(int n)
{
	int num = n;
	int is_composite = 0;
	if(n > 1){
	    double n_sqrt;
		n_sqrt = sqrt((double)num);
		int x = ceil(n_sqrt);

		for(int i= 1;i < num;i++)
		{
		  if(num%i==0) 
		  {
		  		if(i > 1) 
				{
		  			is_composite = 1;
		  			break;
				}
		  }
		}
	}

	return is_composite;
}

//  Function for finding maximum sum 
int maxPathSum(int pyramid[][N], int m, int n) 
{ 
     
	int max_sum =0;
     for (int i=m-1; i>=0; i--) 
     { 
        for (int j=0; j<=i; j++) 
        { 

	    	if(is_composite(pyramid[i][j]) == 1  || pyramid[i][j] == 1)
	    	{
	        	if( i == m -1)
	        	{
	        		if(is_composite(pyramid[i+1][j]) == 1 && is_composite(pyramid[i+1][j+1]) == 1 )
	    			{
	        	 
                		if (pyramid[i+1][j] > pyramid[i+1][j+1]) 
                			pyramid[i][j] += pyramid[i+1][j]; 
            			else
                			pyramid[i][j] += pyramid[i+1][j+1];         		
	    			}

	    			else if (is_composite(pyramid[i+1][j]) == 1 && is_composite(pyramid[i+1][j+1]) == 0 )
	    			{
	    				pyramid[i][j] += pyramid[i+1][j];
	    				
	    			}
	    			else if(is_composite(pyramid[i+1][j]) == 0 && is_composite(pyramid[i+1][j+1]) == 1 )
	    			{
	    				pyramid[i][j] += pyramid[i+1][j+1];
	    				
	    			}
	    			else{
	    				pyramid[i][j] = 0;
	    			}
	        	}
	        	else
	        	{
                	if(pyramid[i+1][j] == 0 && pyramid[i+1][j+1] == 0)
                	{
                		pyramid[i][j] = 0;
                	}
                	else if (pyramid[i+1][j] >= pyramid[i+1][j+1])
                	{
                		pyramid[i][j] += pyramid[i+1][j]; 
                	}  
            		else if (pyramid[i+1][j] < pyramid[i+1][j+1]){
                		pyramid[i][j] += pyramid[i+1][j+1]; 
            		}
	        	}
       		
	    	}
	    	else
	    	{	
	    		pyramid[i][j] = 0;
	    	}

        } 
     } 
  
     return pyramid[0][0]; 
} 
