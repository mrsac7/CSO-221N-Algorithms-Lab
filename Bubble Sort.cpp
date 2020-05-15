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
	for (int i = 0; i<n; i++){
		int check = 0;
		for (int j = 1; j<n-i; j++){
			if (arr[j]<arr[j-1]) {swap(arr[j],arr[j-1]); check=1;}
		}
		if (check == 0) break;
		cout<< "List content after Pass "<<i+1<<": ";
		for (int j = 0; j<n; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}