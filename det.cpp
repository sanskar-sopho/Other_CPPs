#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int det(int **,int);
void print(int **,int);
int main()
{
  int n;
  cout<<"\nEnter the order of determinant\n";
  cin>>n;
  int **M;
  M=new int*[n];
  for(int i=0;i<n;i++)
    M[i]=new int[n];
  cout<<"\nEnter Matrix\n";
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>M[i][j];
  cout<<"\nThe Determinant is = "<<det(M,n)<<endl;
  return 0;
}

int det(int **M,int n)
{
  if(n==2)
    return M[0][0]*M[1][1]-M[0][1]*M[1][0];
  int **N;
  int sum=0;
  N=(int**)malloc((n-1)*sizeof(int*));
  for(int i=0;i<n-1;i++)
    N[i]=(int*)malloc((n-1)*sizeof(int));
  for(int k=0;k<n;k++)
    {
      for(int i=1;i<n;i++)
	{
	  int flag=0;
	  for(int j=0;j<n;j++)
	    {
	      if(j==k)
		{
		  flag=1;
		  continue;
		}
	      if(!flag)
		N[i-1][j]=M[i][j];
	      if(flag)
		N[i-1][j-1]=M[i][j];
	    }
	}
      print(N,n-1);
      sum+=M[0][k]*det(N,n-1)*pow(-1,k);
    }
  return sum;
}

void print(int **M,int n)
{
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	cout<<M[i][j]<<"   ";
      cout<<endl;
    }
  cout<<"\n************************\n";
}
