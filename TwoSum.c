#include <stdio.h>
#include <stdlib.h>

int* twoSum(int*nums, int numsize, int target)
{
  int i,j ;
  int* result=(int*)malloc(2*sizeof(int));

  for(i=0;i<numsize;i++)
  {
    for(j=i+1;j<numsize;j++)
    {
      if(nums[i]+nums[j]==target)
      {
      result[0]=i+1;
      result[1]=j+1;
      return result;
      }
    }
  }  
  
 return NULL;
} 


int main()
{
  int numsize,i,target;

  printf("Enter the total nos of values:");
  scanf("%d",&numsize);

  int*nums=(int*)malloc(numsize*sizeof(int));

  for(i=0;i<numsize;i++)
  {
    printf("Enter value no %d:",i+1);
    scanf("%d",&nums[i]);
  }

  printf("Enter the Target value :");
  scanf("%d",&target);

  int*result = twoSum(nums,numsize,target);

  if (result!=NULL)
    {
      printf("Indices are [%d],[%d]",result[0],result[1]);
      free(result);
    }

  else
    {
      printf("No matches Found");
    }

free(nums);


}