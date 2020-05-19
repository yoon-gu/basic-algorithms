#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int factorial(int n, queue<int> &history){
	// history[n-1] = n;
	history.push(n);
	if (n==1)
		return 1;
	else
		return n * factorial(n-1, history);
}

int main(){
	int n;
	cin >> n;
	queue<int> history;
	int val = factorial(n, history);

	cout << n << "! = ";
	// for (int i = 0; i < n-1; ++i)
	// 	cout << history[i] << "*";
	// cout << history[n-1];
	while( !history.empty()){
		cout << history.front();
		history.pop();
		if (history.size() != 0)
			 cout << "*";
	}
	
	cout << " = " << val << endl;
	return -1;
}