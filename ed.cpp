/*
Created by Mateus Goldbarg
Date: 04/15/2023
*/

#include <iostream>
#include <vector>

using namespace std;

//function just to print the array
void printArray(vector<int> &v){
	int n=v.size();
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

//function to swap elements
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}


//--------------------------------sort algorithms---------------------------
//+++++++++++++++++++++++merge sort++++++++++++++++++++++++++++++
void merge(vector<int> &v, int low, int high, int mid){
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
    	while (i <= mid && j <= high){
        	if (v[i] < v[j]){
            		c[k] = v[i];
            		k++;
            		i++;
        	}
        	else{
            		c[k] = v[j];
            		k++;
            		j++;
        	}
    	}
    	while (i <= mid){
        	c[k] = v[i];
        	k++;
        	i++;
    	}
    	while (j <= high){
        	c[k] = v[j];
        	k++;
        	j++;
    	}
    	for (i = low; i < k; i++){
        	v[i] = c[i];
    	}
}

void mergeSort(vector<int> &v, int low, int high){
	if(low<high){
		int mid;
		mid = (low+high)/2;
		mergeSort(v, low, mid);
		mergeSort(v, mid+1, high);
		merge(v,low,high,mid);
	}

}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++quick sort++++++++++++++++++++++++++++++
int partition(vector<int> &v, int low, int high){
	int pivot = v[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i + 1], &v[high]);
	return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
	if (low < high) { 
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//shell sort
void shellSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int n=v.size();
	for (int h=n/2; h>0;h/=2){
		for (int i=h;i<n;i+=1){
			int temp=v[i];
			int j;
			for (j=i;j>=h && v[j-h]>temp;j-=h)
				v[j]=v[j-h];
			v[j]=temp;
		}
	}
}

//insertion sort O(n²)
void insertionSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int n=v.size();
	int i,key,j;
	for(i=1;i<n;i++){
		key=v[i];
		j=i-1;
		while(j>=0&&v[j]>key){
			v[j+1]=v[j];
			j=j-1;
		}
		v[j+1]=key;
	}
}


//bubble sort O(n²)
void bubbleSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int n=v.size();
	for(int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if(v[j]>v[j+1]){
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			} 
		}
	}
}

//selection sort O(n²)
void selectionSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int min_idx;
	int n=v.size();
	for(int i=0;i<n-1;i++){
		min_idx=i;
		for(int j=i+1;j<n;j++){
			if(v[j]<v[min_idx])
				min_idx=j;
		}
		if(min_idx!=i){
			int temp=v[min_idx];
			v[min_idx]=v[i];
			v[i]=temp;
		}
	}
}

//--------------------------------search algorithms---------------------------

//busca sequencial O(n)
int linearSearch(vector<int> &v,int x){
	/*
		Parameters:
		v = input array to be ordered
		x = item to be found
		Return:
		i = index of the array if the item was found
		-1 = if the item wasn't found
	*/
	int n=v.size();
	for(int i=0;i<n;i++){
		if(v[i]==x)
			return i;		
	}
	return -1;
}

//busca binária O(log(n))
int binarySearch(vector<int> &v, int L, int R, int x){
	/*
		Parameters:
		v = input array to be ordered
		L = left limit of the array
		R = right limit of the array
		x = item to be found
		
		Return:
		mid = index of the array if the item was found
		-1 = if the item wasn't found
	*/
	int n=v.size();
	int mid = L+(R-L)/2;
	if(v[mid]==x)
		return mid;

	if(v[mid]>x)
		return binarySearch(v,L,mid-1,x);

	if(v[mid]<x)
		return binarySearch(v,mid+1,R,x);

	return -1;
}

int main(){
	vector<int> v={78,2,7,97,14,1,27,60};
	int idx;
	
	cout<<"unordered array:\n";
	printArray(v);
	
	//bubbleSort(v);
	//selectionSort(v);
	//insertionSort(v);
	//shellSort(v);
	//quickSort(v,0,v.size()-1);
	mergeSort(v,0,v.size()-1);
	
	cout<<"ordered array:\n";
	printArray(v);
	
	idx = linearSearch(v,27);
	cout<<"Result of linear search: "<<idx<<endl;

	//remember to sort the vector before using binary search
	idx = binarySearch(v,0,v.size(),27);
	cout<<"Result of binary search: "<<idx<<endl;

	return 0;	
}
