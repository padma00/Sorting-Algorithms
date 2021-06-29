#include<bits/stdc++.h>
using namespace std;
int n;
void swap(int *p1,int *p2){
int c=*p1;
*p1=*p2;
*p2=c;
}

void printARR(vector<int>arr){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
void BubbleSort(vector<int>&arr){
	//sorting algorithm bubble sort
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
		}
	}
}
void InsertionSort(vector<int>&arr){
	//sorting algorithm insertion sort
	for(int i=1;i<n;i++){
		int j=i-1;
		int key=arr[i];
		while(j>=0 and arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void SelectionSort(vector<int>&arr){
	for(int i=0;i<n;i++){
		int mn=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[mn]){
				mn=j;
			}
		}
		swap(arr[mn],arr[i]);
	}
}

//merge sort algorithm 

void merge(int* arr,int* L,int lsize,int* R,int rsize){
	int i=0,j=0,k=0;
	while(i<lsize and j<rsize){
		if(L[i]<R[j]){
			arr[k]=L[i];
			i+=1;
		}
		else{
			arr[k]=R[j];
			j+=1;
		}
		k+=1;
	}
		while(i<lsize){
			arr[k]=L[i];
			k+=1;
			i+=1;
		}
		while(j<rsize){
			arr[k]=R[j];
			k+=1;
			j+=1;
		}
	
}
void mergesort(int * arr,int n){
	int mid,*L,*R;
	if(n<2)return;
	mid=n/2;
	L=(int*)malloc(mid*sizeof(int));
	R=(int*)malloc((n-mid)*sizeof(int));
	for(int i=0;i<mid;i++){
		L[i]=arr[i];
	}
	for(int i=mid;i<n;i++){
		R[i-mid]=arr[i];
	}
	mergesort(L,mid);
	mergesort(R,n-mid);
	merge(arr,L,mid,R,n-mid);
	free(L);
	free(R);
	
}

//Quick sort algorithm


//best and average case =>O(nlogn)
//worst case =>O(n^2)
int partition(vector<int>&a,int start,int end){
	int pivot=a[end];
	int pindex=start;
	for(int i=start;i<end;i++){
		if(a[i]<=pivot){
			swap(a[i],a[pindex]);
			pindex++;
		}
	}
	swap(a[pindex],a[end]);
	return pindex;
	
}
//in worst case to make the time complexity O(nlogn) we will apply
//randomized partition here
int Randomized_partition(vector<int>&a,int start,int end){
	int random_pv_index= rand()%(end-start+1) + start;
	swap(a[random_pv_index],a[end]);
	return partition(a,start,end);
}


void QuickSort(vector<int>&arr,int start,int end){
	if(start<end){
		int pv_index=Randomized_partition(arr,start,end);
		QuickSort(arr,start,pv_index-1);
		QuickSort(arr,pv_index+1,end);
	}
	
}


int main() {
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//BubbleSort(arr);
	//InsertionSort(arr);
	//SelectionSort(arr);
	QuickSort(arr,0,n-1);
	printARR(arr);
	int arr1[]={9,3,4,7,2,1};
	int m=6;
	mergesort(arr1,m);
	for(int i=0;i<m;i++)cout<<arr1[i]<<" ";
	return 0;
}
