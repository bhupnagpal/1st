#include<iostream>
using namespace std;
int size = 10;
int a[7]={0};
int b[7]={0};

int hash(int n){
	const int p=7;
	int i=0;
	int l=n%p;
	while(b[l]!=0){
		l=l+(i*i);
		i++;
		if(l==7){
			l=0;
		}
	}
	return l;
}

int main(){
	int n, k, l, i;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"\nEnter key ";
		cin>>k;
		
		l=hash(k);
		b[l]=1;
		a[l]=k;
	}
	
	for(i=0;i<10;i++){
		cout<<a[i]<<endl;
	}
}


