#include<iostream>
#include<vector>

#define pb push_back
using namespace std;


void merge(int a[], int l, int m, int r){
	int i1=l, i2=m;
	vector<int> aux;
	while(i1<m && i2<r){
		if (a[i1]<=a[i2]) {aux.pb(a[i1]); i1++;}
		else {aux.pb(a[i2]); i2++;}
	}
	while(i1<m) {aux.pb(a[i1]); i1++;}
	while(i2<r) {aux.pb(a[i2]); i2++;}

	for (int i=0; i<aux.size(); i++){
		a[i+l] = aux[i];
	}
}
void mergesort(int a[], int n) {
	for (int b=1; b<n; b<<=1){ //size of subarrays to merge
		for (int l=0; l<n-1; l+= 2*b){
			int m = min(l+b,n);
			int r = min(m+b,n);
			merge(a,l,m,r);
		}
	}
   
} 
int main(){
	int n; cin>>n;
	int a[n];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	mergesort(a,n);
	cout<<"AFTER SORTING: ";
	for (int i=0; i<n; i++){
		cout<<a[i]<<' ';
	}
}