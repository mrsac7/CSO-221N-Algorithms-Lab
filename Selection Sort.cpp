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
	for (int i = 0; i<n-1; i++){
		int mn = arr[i], id = i;
		for (int j = i+1; j<n; j++){
			if (arr[j]< mn){
				mn = arr[j];
				id = j;
			}
		}
		swap(arr[id], arr[i]);
		cout<< "List content after Pass "<<i+1<<": ";
		for (int j = 0; j<n; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}
