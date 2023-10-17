//Given an array of integer with size ‘n’. find the maximum sum of ‘k’ consecutive elements of sub array using sliding window technique


#include<stdio.h>
#include<conio.h>
int main ()
{
int n,k,i,maxw=0,win=0;
int arr[100];
printf("\nEnter the array limit : ");
scanf("%d",&n);
for(i=0; i<n;++i)
scanf("%d",&arr[i]);
printf("\nEnter the sub array size : ");
scanf("%d",&k);
for(i=0; i<k; ++i)
win+=arr[i];
maxw=win;
for(i=k; i<n; ++i){
win=win+arr[i]-arr[i-k];
if(win>maxw)
maxw=win;
}
printf("\nThe maximum sum of sub array is : %d",maxw);
return 0;
}
