#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
class Items{
public:
	void SetLength(){
		cin >> length;
	}

	int GetLength(){
		return length;
	}

	void SetItem(){
		for (int i = 0; i < length; i++){
			cout << "Введите название предмета: ";
			string n;
			cin >> n;
			name.push_back(n);
			cout << "Введите цену предмета: ";
			int wh;
			cin >> wh;
			price.push_back(wh);
			cout << "Введите вес предмета: ";
			cin >> wh;
			weight.push_back(wh);
		}
	}

	int Get_price(int i){
		return price[i];
	}

	string Get_name(int i){
		return name[i];
	}

	int Get_weight(int i){
		return weight[i];
	}

	void PrintItems(){
		for (int i = 0; i < length; i++){
			cout << name[i] << price[i] << weight[i] << endl;
		}

	}

private:
	int length;
	vector<string> name;
	vector<int> weight;
	vector<int> price;

};


class Backpack{
public:
	void SetBagWeight(){
		cin >> bag_weight;
	}

	int GetBagWeight(){
		return bag_weight;
	}

	void SetResWeight(int x,int y){
		if (y == 1){
			result_weight += x;
		} else {
			result_weight = x;
		}
	}

	int GetResWeight(){
		return result_weight;
	}

	void SetResPrice(int x, int y){
		if (y == 1){
			result_price += x;
		} else {
			result_price = x;
		}
	}

	int GetResPrice(){
		return result_price;
	}

	void SetResName(string x, int y){
		if (y == 1){
			result_name += x + " ";
		} else {
			result_name = x;
		}
	}

	string GetResName(){
		return result_name;
	}

private:
	int bag_weight;
	string result_name = "";
	int result_price = 0;
	int result_weight = 0;

};

int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;

    }

    return bin;
}

void calculate(Items &items, Backpack &backpack){
	Backpack result;
	int bin;
	for (int i = 0; i < pow(2,items.GetLength());i++){
		bin = dec2bin(i);
		// cout << bin << endl;
		for (int j = 0; j < to_string(dec2bin(i)).length();j++){
			if (bin % 10 == 1){
				backpack.SetResWeight(items.Get_weight(j),1);
				backpack.SetResPrice(items.Get_price(j),1);
				backpack.SetResName(items.Get_name(j),1);
				// cout << backpack.GetResWeight() << endl << backpack.GetResPrice() << endl << backpack.GetResName() << endl;	
			}
		bin = (bin - (bin % 10)) / 10;		
		}
	if (result.GetResPrice() < backpack.GetResPrice() && backpack.GetBagWeight() > backpack.GetResWeight() && backpack.GetResWeight() != 0){
		result.SetResWeight(backpack.GetResWeight(),0);
		result.SetResPrice(backpack.GetResPrice(),0);
		result.SetResName(backpack.GetResName(),0);
	}
	backpack.SetResWeight(0,0);
	backpack.SetResPrice(0,0);
	backpack.SetResName("",0);
	}
	cout << result.GetResName() << endl << result.GetResPrice() << endl << result.GetResWeight() << endl;
}


int main(){
	setlocale(LC_ALL,"ru");
	Backpack backpack;
	cout << "Введите вместимость рюкзака: ";
	backpack.SetBagWeight();
	Items items;
	cout << "Введите количество предметов: ";
	items.SetLength();
	items.SetItem();
	calculate(items,backpack);
	// items.PrintItems();
	// for (int i = 0; i < 4; i++){
	// 	cout << dec2bin(i) << endl;
	// }

}