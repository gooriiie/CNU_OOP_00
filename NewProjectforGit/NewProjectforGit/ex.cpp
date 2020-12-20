#include<iostream>

int& func(int& a) {
	return a;
}

class Animal {
public:
	Animal() {
		leg = 4;
	}
	Animal(int leg) {
		this->leg = leg;
	}
	int getLeg() {
		return this->leg;
	}
private:
	int leg;
};

int main() {
	int num = 1024;
	int* p = &num;
	int& ref = num;

	
	std::cout << ref++ << std::endl;
	std::cout << p << std::endl;

	std::cout << p++ << std::endl;
	std::cout << p << std::endl;

	const int& reff = 4;

	int arr[2] = { 1,2 };
	int(&rref)[2] = arr;

	int x = 1;
	std::cout << func(x)++ << std::endl;
	std::cout << x << std::endl;


	int c = 1;

	Animal ani;
	Animal animal = Animal();


	std::cout << ani.getLeg() << std::endl;
	std::cout << animal.getLeg() << std::endl;


	char* ss = "hello";
	char p[] = "hello";
	p[0] = 'a';
	ss[0] = 'a';
	p.size();


	return 0;
}