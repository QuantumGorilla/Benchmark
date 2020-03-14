#define debug(x) std::cout << #x << " = " << x << std::endl;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v)
{
	os << "[";
	if( !v.empty() )
	{
		auto iter = std::begin(v);
		os << *iter;
		iter++;
		while( iter != std::end(v) )
		{
			os << ", " << *iter;
			iter++;
		}
	}
	os << "]";
	return os;
}

int main(int argc, char* argv[])
{
	int n; // number of digits to calculate AFTER the decimal dot
	cout << "Digite el número de decimales que quiere mostrar: ";
	cin >> n;
	n++;

	std::string digits;

	std::vector<int> v(10*n/3 + 10);
	std::fill(std::begin(v), std::end(v), 2);
	
	for(int iteration = 0; iteration < n; iteration++)
	{
		std::for_each(std::begin(v), std::end(v), [](int& d){ d *= 10; });
		for(int i = v.size()-1; i > 0; i--)
		{
			const int numerator = i;
			const int denominator = 2*(i+1)-1;

			const int quotient = v.at(i) / denominator;
			const int remainder = v.at(i) % denominator;

			v.at(i) = remainder;
			v.at(i-1) += numerator*quotient;
		}

		v.at(0) %= 100;
		const int digit = v.at(0)/10;
		v.at(0) %= 10;

		digits.push_back('0' + digit);
	}

	std::cout << digits << std::endl;

	return 0;
}