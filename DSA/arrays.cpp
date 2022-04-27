#include <iostream>
#include <cstring>

using namespace std;

class Array {
private:
	int Len;
	int Capacity;
	int arr[16];
public:
	Array() {
		Len = 16;
	}

	Array(int Capacity) {
		Len = 16;
		this->Capacity = Capacity;
		//int arr[Len];
		
	}

	int size() {
		return Len;
	}

	bool isEmpty() {
		return size() == 0;
	}

	void S_name(string ) {
		
	}
};