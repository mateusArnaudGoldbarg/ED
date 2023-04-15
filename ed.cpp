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


//--------------------------------sort algorithms---------------------------

//bubble sort
void bubbleSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int n=v.size();
	cout<<"unordered array:\n";
	printArray(v);
	for(int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if(v[j]>v[j+1]){
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			} 
		}
	}
	cout<<"ordered by bubble sort:\n";
	printArray(v);
}

//selection sort
void selectionSort(vector<int> &v){
	/*
		Parameters:
		v = input array to be ordered
	*/
	int min_idx;
	int n=v.size();
	cout<<"unordered array:\n";
	printArray(v);
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
	cout<<"ordered selection sort:\n";
	printArray(v);
}

//--------------------------------search algorithms---------------------------

//busca sequencial
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

//busca binária
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
	int mid = (R+L)/2;
	if(v[mid]==x)
		return mid;

	if(v[mid]>x)
		return binarySearch(v,L,mid-1,x);

	if(v[mid]<x)
		return binarySearch(v,mid-1,R,x);

	return -1;
}

int main(){
	vector<int> v={14,76,2,36,12,25,1,9,1992,5,98,11,23,825};
	int idx;
	
	//bubbleSort(v);
	selectionSort(v);
	
	idx = linearSearch(v,36);
	cout<<"Result of linear search: "<<idx<<endl;

	//remember to sort the vector before using binary search
	idx = binarySearch(v,0,v.size()-1,36);
	cout<<"Result of binary search: "<<idx<<endl;

	return 0;	
}

