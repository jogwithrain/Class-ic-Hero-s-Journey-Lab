#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
void quest(class Hero &person);


class Hero {
	int strength;
	int courage;
	string name;
public:
	Hero(string z) { //constructor for setting a name
		strength = rand() % 50;
		courage = rand() % 50;
		name = z;
		//cout << &strength << " " << &courage <<" " << &name<< " " << endl;
	}

	Hero() { //defualt constructor
		strength = rand() % 50;
		courage = rand() % 50;
		name = "Unknown";
	//	cout << &strength << " " << &courage << " " << &name << " " << endl;
	}
	void setCourage(int x) {
		if (x <= 0) { // Courage shouldn't be negative
			cout << "Courage is less than 0" << endl;
			courage = 0;
		}
		else {
			courage =  x;
		//	cout << "I'm here" << endl;
		}	
	}
	int getStrength() {
		return strength;
	}
	int getCourage() {
		return courage;
	}
	string getName() {
		return name;
	}
	void attendTraining(int time) {
		strength = strength + time;
	//	cout << &strength << endl;
	}
	void attendTherapy() {
		courage = courage + rand() % 10;
	//	cout << &courage << endl;
	}
	
};

int main() {
	srand(time(0)); // This sets the numbers to be different each time it runs.
	Hero r = Hero("Paprica");
//	cout << r.getStrength() << " " << r.getCourage() << " " << r.getName() << endl;
	Hero b = Hero();
//	cout << b.getStrength() << " " << b.getCourage() << " " << b.getName() << endl;
	r.attendTraining(4);
//	cout << r.getStrength() << " " << r.getCourage() << " " << r.getName() << endl;
	b.attendTherapy();
//	cout << b.getStrength() << " " << b.getCourage() << " " << b.getName() << endl;
	quest(r);
	quest(b);
	Hero g = Hero("Spiderman");
	r.attendTherapy();
	r.attendTherapy();
	b.attendTherapy();
	b.attendTraining(30);
	r.attendTraining(15);
	g.attendTraining(45);
	quest(r);
	quest(b);
	quest(g);
//	cout << r.getStrength() << " " << r.getCourage() << " " << r.getName() << endl;
//	cout << b.getStrength() << " " << b.getCourage() << " " << b.getName() << endl;
}

void quest(class Hero &person) {
	int temp;
	int a = rand() % 100;
		if (person.getStrength() > a) {
			cout << person.getStrength() << ">" << a << endl;
			cout << person.getName() << " has Success" << endl;
		}
		else if (person.getStrength() < a) {
			cout << person.getStrength() << "<" << a << endl;
			cout << person.getName() << " has Failure" << endl;
	
			if ((a - person.getStrength()) > 15) {
			 temp = person.getCourage() - 25;
				person.setCourage(temp);
			}
			else {
				temp = person.getCourage() - 5;
				person.setCourage(temp);
			}
		}
		else {
			cout << person.getStrength() << "=" << a << endl;
			cout << person.getName() << " has Tie" << endl;
		
		}
		// It's not returing, only modifiy meaning void and not return type function.
}
