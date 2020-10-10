#include<iostream>
using namespace std;

int main(){
	int i,l,n,t,a[100],p;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=0;i<n;i++){
		t=a[i];
		p=i-1;
		
		while(t<a[p] && p>=0){
			a[p+1]=a[p];
			p--;
		}
		
		a[p+1]=t;
	}
	
	for(i=0;i<n;i++){
		cout<<a[i];
	}
}


