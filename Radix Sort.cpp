#include<iostream>
#include<math.h>
using namespace std;

int main(){
	// int arr[] = {901,402,359,23,799,51,10,15,1};
	// //{1,2,9,3,9,1,0,5,1}
	// int n = sizeof(arr)/sizeof (arr[0]);
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int e = 1;
	while(1){
		int rad[n]; int flag=0;
		int cnt[10]={0};
		for (int i = 0; i<n; i++){
			rad[i] = (arr[i]/e)%10;
			cnt[rad[i]]++;
			if (rad[i]) flag=1;
		}
		if (flag == 0) break;

		for (int i = 1; i<10; i++) cnt[i] += cnt[i-1];

		int newarr[n];
		for (int i=n-1; i>=0; i--){
			int x = --cnt[rad[i]];
			newarr[x] = arr[i];
		}
		for (int i = 0; i<n; i++) arr[i] = newarr[i];

		cout<< "List content after Pass "<<log10(e)+1<<": ";
		for (int j = 0; j<n; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		e*=10;
	}
}