#include<iostream>
using namespace std;

int main(){
	// int arr[] = {9,4,3,2,7,5,10,15,1};
	// int n = sizeof(arr)/sizeof (arr[0]);
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++){
		cin>>arr[i];
	}
	//after ith pass list is sorted upto ith element
	int gap = n/2;
	int p = 1;
	while(gap>0){
		for (int i = gap; i<n; i++){
			int j = i;
			while (j>=gap && arr[j]<arr[j-gap]){
				swap(arr[j],arr[j-gap]);
				j-=gap;
			}
			cout<< "List content after Pass "<<p<<": ";
			for (int j = 0; j<n; j++){
				cout<<arr[j]<<" ";
			}
			cout<<endl;
			p++;
		}
		gap/=2;
	}
}