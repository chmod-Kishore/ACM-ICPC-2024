#include<stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i=low-1;
	for(int j=low;j<=high-1;++j){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
		
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}
void quick_sort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr,low,high);
		quick_sort(arr,low,pi-1);
		quick_sort(arr,pi+1,high);
	}
}
int main(){
	int arr[] = {2,4,5,2,4,5,7,7,8,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
