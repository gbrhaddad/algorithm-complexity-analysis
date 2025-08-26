#include "algorithm.h"
#include "analyze.h"

void bubble_sort(int *a, int n)
{
int flag=0, i, j, tmp;
for(i=0; i<n-1; i++){
	for(j=0;j<n-1-i;j++){
		if(a[j]>a[j+1]){
		tmp=a[j]; 
		a[j]=a[j+1]; 
		a[j+1]=tmp;
		flag=1; 
			}
		}
	if(flag==0){
	break; 
		}
	}
}

void insertion_sort(int *a, int n)
{
int key,x; 
for(int i=1; i<n;i++){
	key=a[i]; 
	x=i-1; 
	while(x>=0&& a[x]>key){
		a[x+1]=a[x];
		x-=1;
		}
		a[x+1]=key;	
	}
}

void quick_sort(int* a, int n)
{
int i=0, last=0, tmp, pivot = a[n - 1];

while (i < n - 1)
{
if (pivot>a[i])
{
tmp=a[i];
a[i]=a[last];
a[last]=tmp;
last+=1;
}
i++;
}
tmp=a[last];
a[last]=a[n-1];
a[n-1]=tmp;

if (n-last-1>1)
{
quick_sort(a+last+1,n-last-1);
}

else if (last>1)
{
quick_sort(a,last);
}
}

   


bool linear_search(const int *a, int n, int v){
for(int i=0; i<n;i++){
if(a[i]==v){
	return true;
		}
	}
	return false; 
}


bool binary_search(const int *a, int n, int v)
{
	int low=0, high=n-1, mid; 
	while(low<=high){
	mid=((low+high)/2);
	if(v<a[mid]){
	high=mid-1; 
	}
	else if(v>a[mid]){
	low=mid+1;
		}

	else if(v==a[mid]){
	return true; 
	break; 
		}
	}
	return false; 
}
