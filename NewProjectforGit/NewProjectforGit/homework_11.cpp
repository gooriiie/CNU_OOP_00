#include <iostream>
#include <string>

class Animal {
protected:
	std::string name;
	int age;
public:

	// Animal ������
	Animal(std::string name, int age) : name(name), age(age) {}

	// pure virtual finction
	virtual void showInfo() = 0;
	virtual void feed() = 0;

	std::string getName() {
		return this->name;
}
};

class Dog : public Animal {
protected:
	int walkingTime;	// ��å �ð�
	int weight;	// ������
	int volume;	// ���� �Ҹ� ũ��

public:
	// Dog ������
	Dog(std::string name, int age, int walkingTime, int weight, int volume) : Animal(name, age), walkingTime(walkingTime), weight(weight), volume(volume){}

	// override
	void showInfo() override{
		std::cout << "�̸� : " << this->name << std::endl;
		std::cout << "���� : " << this->age << std::endl;
		std::cout << "��å �ð� : " << this->walkingTime << std::endl;
		std::cout << "������ : " << this->weight << std::endl;
		std::cout << "���� �Ҹ� ũ�� : " << this->volume << "\n" << std::endl;
	}

	void feed() override {
		this->walkingTime += 10;
		this->weight += 1;
		this->volume += 20;
	}


	int getWalkingTime() {
		return this->walkingTime;
	}
	int getWeight() {
		return this->weight;
	}
	int getVolume() {
		return this->volume;
	}

	// pure virtual function
	virtual void training() = 0;
	virtual Dog* operator<(Dog* dog) = 0;
};

class Poodle : public Dog {
private:
	int plusWalkingTime = 10;

public:
	Poodle(std::string name, int age, int walkingTime, int weight, int volume) : Dog(name,age,walkingTime,weight,volume) {}

	void training() override{
		this->walkingTime += plusWalkingTime;
	}

	Dog* operator<(Dog* dog) override {
		if (this->walkingTime <= dog->getWalkingTime()) {
			return dog;
		}
		else {
			return this;
		}
	}
};
class Maltese : public Dog {
private:
	int plusWeight = 1;

public:
	Maltese(std::string name, int age, int walkingTime, int weight, int volume) : Dog(name, age, walkingTime, weight, volume) {}

	void training() override {
		this->weight += plusWeight;
	}

	Dog* operator<(Dog* dog) override {
		if (this->weight <= dog->getWeight()) {
			return dog;
		}
		else {
			return this;
		}
	}
};
class Pomeranian : public Dog {
private:
	int plusVolume = 20;

public:
	Pomeranian(std::string name, int age, int walkingTime, int weight, int volume) : Dog(name, age, walkingTime, weight, volume) {}

	void training() override {
		this->volume += plusVolume;
	}

	Dog* operator<(Dog* dog) override {
		if (this->walkingTime <= dog->getVolume()) {
			return dog;
		}
		else {
			return this;
		}
	}
};

class Bird : public Animal {
protected:
	int speed;		// ���� �ӵ�
	int height;		// ���� ��
	int wingSize;	// ���� ũ��
public:
	// ������
	Bird(std::string name, int age, int speed, int height, int wingSize) : Animal(name, age), speed(speed), height(height), wingSize(wingSize){}

	// override
	void showInfo() override {
		std::cout << "�̸� : " << this->name << std::endl;
		std::cout << "���� : " << this->age << std::endl;
		std::cout << "���� �ӵ� : " << this->speed << std::endl;
		std::cout << "���� �� : " << this->height << std::endl;
		std::cout << "���� ũ�� : " << this->wingSize << "\n" << std::endl;
	}
	void feed() override {
		this->speed += 10;
		this->height += 100;
		this->wingSize += 1;
	}
	// get
	int getSpeed() {
		return this->speed;
	}
	int getHeight() {
		return this->height;
	}
	int getWingSize() {
		return this->wingSize;
	}
	//pure virtual funtion
	virtual void training() = 0;
	virtual Bird* operator<(Bird* bird) = 0;
};

class Chicken : public Bird {
private:
	int plusSpeed = 10;
public:
	Chicken(std::string name, int age, int speed, int height, int wingSize) : Bird(name, age, speed, height, wingSize){}

	void training() override {
		this->speed += plusSpeed;
	}
	Bird* operator<(Bird* bird) {
		if(this->speed < bird->getSpeed()){
			return bird;
		} else if(this->speed > bird->getSpeed()){
			return this;
		} else {
			return nullptr;
		}
	}
};

class Eagle : public Bird {
private:
	int plusHeight = 100;
public:
	Eagle(std::string name, int age, int speed, int height, int wingSize) : Bird(name, age, speed, height, wingSize){}

	void training() override {
		this->speed += plusHeight;
	}
	Bird* operator<(Bird* bird) {
		if(this->speed < bird->getHeight()){
			return bird;
		} else if(this->speed > bird->getHeight()){
			return this;
		} else {
			return nullptr;
		}
	}
};

class Parrot : public Bird {
private:
	int plusWingSize = 1;
public:
	Parrot(std::string name, int age, int speed, int height, int wingSize) : Bird(name, age, speed, height, wingSize){}

	void training() override {
		this->speed += plusWingSize;
	}
	Bird* operator<(Bird* bird) {
		if(this->speed < bird->getWingSize()){
			return bird;
		} else if(this->speed > bird->getWingSize()){
			return this;
		} else {
			return nullptr;
		}
	}
};


int main() {

	Animal** animals = new Animal * [10];

	animals[0] = new Poodle("�ѽ���", 2, 30, 10, 20);
	animals[1] = new Maltese("������", 3, 20, 15, 40);
	animals[2] = new Pomeranian("���ǿ�", 4, 10, 30, 30);

	animals[0]->showInfo();
	animals[1]->showInfo();
	animals[2]->showInfo();

	animals[0]->feed();
	Maltese* mal = dynamic_cast<Maltese*>(animals[1]);
	mal->training();

	Poodle* p0 = dynamic_cast<Poodle*>(animals[0]);
	Dog* p1 = dynamic_cast<Dog*>(animals[1]);
	Dog* result1 = *p0 < p1;
	Dog* p2 = dynamic_cast<Dog*>(animals[2]);

	std::cout << "WalkingTime Winner : " << (*result1 < p2)->getName() << std::endl;
	


	return 0;
}