#include<iostream>
#include<fstream>
using namespace std;

void create(int a[][10]){
	for(int i = 1 ; i < 6 ; i ++){
		for(int j = 1 ; j < 6 ; j++){
			cin >> a[i][j];
		}
	}
}

int main(){
	int a[10][10]; // do thi
	ifstream infile;
	infile.open ("Input.txt");
	for(int i = 1 ; i <= 5 ; i ++){
		for(int j = 1 ; j <= 5 ; j++){
			infile >> a[i][j];
		}
	}
	for(int i = 1 ; i <= 5 ; i ++){
		for(int j = 1 ; j <= 5 ; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int head;
	int tail;
	cout << "Diem bat dau : ";
	cin >> head;
	cout << endl;
	cout << "Diem cuoi : ";
	cin >> tail;
	int d[10];
	int pre[10];
	int s[10]; // mang danh dau cac dinh
	for(int i = 1 ; i <= 5 ; i++){
		d[i] = a[head][i];
		pre[i] = head;
		s[i] = 0;
	}
	pre[head] = 0;
	d[head] = 0;
	s[head] = 1;
	while(s[tail]==0){
		int min = 999;
		int u = 0;
		for(int i = 1 ; i <= 5 ; i++){
			if (( s[i] == 0 ) && ( min > d[i] )){
				u = i;
				min = d[i];
			}
		}
		s[u] = 1;
		if(s[tail]==0){
			for(int i = 1 ; i <=5 ; i++){
				if( s[i]==0 && (d[u] + a[u][i] < d[i])){
					d[i] = d[u] + a[u][i];
					pre[i] = u;
				}
			}
		}
	}
	
	cout << "Duong di ngan nhat tu " << head << " den " << tail << " la : " << endl;
	int i = pre[tail];
	cout << tail << " <- ";
	while(i!=head){
		cout << i << " <- ";
		i = pre[i];
	}
	cout << " " << head;
	cout << endl << "Do dai duong di la : " << d[tail];
	
}
//
//int d[10]; // khoang cach 
//	int p[10]; // diem
//	int s[10]; // tap cac diem den
//	int k;
//	int n; 
//	cout << "Diem bat dau: ";
//	cin >> n;
//	
//	for(int i = 1 ; i < 6 ; i++){
//		if(i!=n){
//			d[i] = a[n][i];
//			p[i] = n;
//			s[i] = 0;			
//		}
//		else d[n] = 0;
//	}
//	s[n] = 1;
//	int count = 4;
//	while(count>0){
//		int min = 999;
//		for(int i = 1 ; i < 6 ; i++){
//			if((s[i]==0)&&(d[i]<min)){
//				min = d[i];
//				k = i;
//			}
//		}
//		if(min==999){
//			cout << "Do thi khong lien thong";
//		}
//		s[k] = 1;
//		for(int i = 1 ; i < 6 ; i ++){
//			if(p[i]==0 && d[k]+a[k][i]<d[i] && a[k][i]>0 ){
//				d[i] = d[k] + a[k][i];
//				p[i] = k;
//			}
//		}
//		count--;
//	}
//	for(int i = 1 ; i < 6 ; i ++){
//		if(i!=n){
//			if(d[i]==999){
//				cout << "Khong co duong di";
//			}
//			else{
//				cout << "Duong di ngan nhat tu " << n << " den " << i << "la : ";
//				int b[10];
//				int c=0;
//				int temp = p[i];
//				while(temp!=n){
//					b[c] = temp;
//					temp = p[temp];
//					c++;
//				}
//				cout << n << "->" ;
//				for(int j = c ; j > 0 ; j-- ){
//					cout << "-> " << b[j-1];
//				} 
//				cout << i << endl;
//			}
//		}
//	}


