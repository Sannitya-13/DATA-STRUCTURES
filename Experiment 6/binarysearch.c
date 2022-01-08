#include <stdio.h>
int binarysearch(int [],int,int,int);
int main(){
    int a[10],n,i,pos,key;
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter the elements of array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the value of key:");
    scanf("%d",&key);
    pos = binarysearch(a,0,n-1,key);
    if(pos>0){
       printf("element found at position %d",pos);
    }
    else{
        printf("element not found");
    }
    return 0;
}
int binarysearch(int a[],int l,int h,int key){
    int mid;
    while(l<=h){
         mid = (l+h)/2;
         if(key==a[mid]){
            return mid;
         }
         else if(key > a[mid]){
           l = mid+1;
          }
          else{
           h = mid-1;
           }
           }
       if(l>h){
          return -1;
          
         }
        }
    
