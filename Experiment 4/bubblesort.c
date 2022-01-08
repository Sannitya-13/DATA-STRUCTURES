#include <stdio.h>
void bubblesort(int [], int);
int main(){
	int n,a[10],i;
	printf("enter no.of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
void bubblesort(int a[],int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
