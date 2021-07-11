#include <iostream>
#include <list>

using namespace std;

int main(){
	int mass[9] = {1,43,34,875,956,2,46,0,64};
	cout << "Input number search" << endl;
	int a;
	cin >> a;
	for (int i = 0; i < sizeof(mass); i++){
		if (a == mass[i]){
			cout << i;
			break;
		}
	}
}