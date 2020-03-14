#include <iostream>
#include <thread>

using namespace std;
 
void prime(int from, int to){
int i = 0, num;
	for(num = from; num <= to; num++){
		for(i = 2; i <= (num/2); i++){
			if(num % i == 0){
				i = num;
				break;
			}
		}
		if(i != num){
		 cout << num << " ";
		}
	}
}

int main(){
	int n;
	cout << "Digite el valor de n: ";
	cin >> n;

    thread first(prime, 2, n/10);
		thread second(prime, n/10, n/9);
		thread third (prime, n/9, n/8);
		thread fourth(prime, n/8, n/7);
		thread fifth(prime, n/7, n/6);
    thread sixth(prime, n/6, n/5);
		thread seventh(prime, n/5, n/4);
		thread eighth(prime, n/4, n/3);
		thread nineth(prime, n/3, n/2);
		thread tenth(prime, n/2, n);

    first.join();
		second.join();
		third.join();
		fourth.join();
		fifth.join();
		sixth.join();
		seventh.join();
		eighth.join();
		nineth.join();
		tenth.join();
    		
		return 0;
}