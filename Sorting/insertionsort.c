#include<stdio.h>

void insertion_sort(int arr[], int n){
	int i,j,key;
	for(int i=1;i<n;++i){
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
int main(){
	int arr[] = {2,4,5,2,4,5,7,7,8,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,n);
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
