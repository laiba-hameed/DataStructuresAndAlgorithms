#include <iostream>
#include <string>
using namespace std;

class Person {

private:
	string name;
	int age;
	int CNIC;

public:
	Person(string name, int age, int CNIC) {
		this->name = name;
		this->age = age;
		this->CNIC = CNIC;
	}

	void Print() {
		cout << "Name: " << name;
		cout << "\nAge: " << age;
		cout << "\nCNIC: " << CNIC;
	}
};

int main() {

	//Person p = new Person("lilia", 20, 342242244);
	return 0;
}