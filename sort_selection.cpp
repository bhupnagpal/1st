#include<iostream>
using namespace std;

int min(int a[], int s, int n){
	int p, m=a[s];
	for(int i=s;i<n;i++){
		if(a[i]<m){
			m=a[i];
			p=i;
		}
	}
	return p;
}

int main(){
	int i,l,n,t,a[100];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=0;i<n-1;i++){
		l=min(a,i,n);
		t=a[i];
		a[i]=a[l];
		a[l]=t;
	}
	
	for(i=0;i<n;i++){
		cout<<a[i];
	}
}


