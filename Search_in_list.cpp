#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	cout << "Input number" << endl;
	int number = 0;
	cin >> number;
    list<int> v = {42,423,7,46,97,46,895,35,11123,0};
    auto iter = find(v.begin(),v.end(),number);
    if (iter == v.end()){
        cout << "Number not find" << endl;
    } else {
        cout << distance(v.begin(),iter) + 1;
    }
}

