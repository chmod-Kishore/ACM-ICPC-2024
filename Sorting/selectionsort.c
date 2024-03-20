#include<stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void selection_sort(int arr[], int n){
	int i,j,min_index;
	for(int i=0;i<n-1;++i){
		min_index = i;
		for(int j=i+1;j<n;++j){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[min_index],&arr[i]);
	}
}

int main(){
	int arr[] = {2,4,5,2,4,5,7,7,8,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr,n);
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
