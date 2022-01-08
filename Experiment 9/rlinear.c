#include <stdio.h>
int rlinearsearch(int [],int,int);
int main(){
    int a[10],i,n,pos,key;
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter array elements:");
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    printf("enter the element to be searched:");
    scanf("%d",&key);
    pos = rlinearsearch(a,n,key);
    if(pos>0){
       printf("element found at %d position",pos);
     }
     else{
       printf("element not found");
     }
     return 0;
}
int rlinearsearch(int a[],int n,int key){
    int rec;
    if(n>0){
             if(a[n-1]==key){
                      return n-1;
              }
             else{
                  return rlinearsearch(a,n-1,key);
             }
             }
             return -1;
             }
