#include <stdio.h>
int linearsearch(int [],int,int);
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
    pos = linearsearch(a,key,n);
    if(pos>0){
       printf("element found at %d position",pos);
     }
     else{
       printf("element not found");
     }
     return 0;
}
int linearsearch(int a[],int key,int n){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==key){
          return i;
          }
          }
          return -1;
          }
          
      
    
