#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int a[10][10]; // do thi
	int s[10][10]; // duong di
	ifstream infile;
	infile.open ("Input_1.txt");
	for(int i = 1 ; i <= 4 ; i ++){
		for(int j = 1 ; j <= 4 ; j++){
			infile >> a[i][j];
		}
	}
	for(int i = 1 ; i <= 4 ; i ++){
		for(int j = 1 ; j <= 4 ; j++){
			cout << a[i][j] << " ";
			if(a[i][j]==999) s[i][i] = 0;
			else s[i][j] = j;
		}
		cout << endl;
	}
	
	for(int i = 1 ; i <= 4 ; i ++){
		for(int j = 1 ; j <= 4 ; j++){
			for(int k = 1 ; k <= 4 ; k++){
				if((a[j][i]!=999)&&(a[j][i]+a[i][k]<a[j][k]))	{
					a[j][k] = a[j][i] + a[i][k];
					s[j][k] = s[j][i];
				}
			}
		}
	}
	for(int i = 1 ; i <= 4 ; i ++){
		for(int j = 1 ; j <= 4 ; j++){
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
	cout << "duong di ngan nhat tu " << head << " den " << tail << " la :" << endl;
	cout << head;
	while(head!=tail){
		cout << "->" << s[head][tail];
		head = s[head][tail];
	}
}



