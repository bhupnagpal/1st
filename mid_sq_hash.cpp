#include<iostream>
using namespace std;

int a[100]={0};

int hash(int n){

	int l=((n*n)/1000)%100;
	return l;
}

int main(){
	int n, k, l, i;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"\nEnter key ";
		cin>>k;
		
		l=hash(k);
		a[l]=k;
	}
	
	for(i=0;i<100;i++){
		cout<<a[i]<<" "<<i<<endl;
	}
}


