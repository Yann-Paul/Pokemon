#include <iostream>
#include <string>
using namespace std;


class Attack
{
public:

	void test(){
	     cout << "Attacke wurde erstellt"<<  endl;  // Test
	}

	string name;
	string type; //types: grass, water, fire, electro, stone, wind, psycho
	int strength;
	int precision;
	int manacost;
	//Attack();
	Attack(string name, string type, int strength, int precision, int manacost){
		this->name = name;
		this->type = type;
		this->strength = strength;
		this->precision = precision;
		this->manacost = manacost;
	};
	Attack(){}
private:
};

