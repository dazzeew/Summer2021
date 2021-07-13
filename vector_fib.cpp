#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int x){
	static vector <int> vec = {0,1,1};	
	if (x == vec[0]){
		return 0;
	}
	if (x == vec[1]){
		return 1;
	}
	while (vec.size() <= x){	
		vec.push_back(vec[vec.size() - 2] + vec[vec.size() - 1]);
	}
	return vec[x];
}

int main()
{
cout << fibonacci(2);
}