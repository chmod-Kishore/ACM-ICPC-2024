#include<stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int arr[], int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n-i-1;++j){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
int main(){
	int arr[] = {2,4,5,2,4,5,7,7,8,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,n);
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
