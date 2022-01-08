#include<stdio.h>
void insertionsort(int [],int);
int main(){
    int i,a[10],n;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter elements one by one:");
    for (i=0;i<n;i++){
         scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
     }
     return 0;
}
void insertionsort(int a[],int n){
     int i,j,index;
     for(i=1;i<n;i++){
        index = a[i];
        j = i;
        while((j>0) && (a[j-1]>index)){
               a[j] = a[j-1];
               j = j-1;
          }
        a[j] = index;
     }
  }
