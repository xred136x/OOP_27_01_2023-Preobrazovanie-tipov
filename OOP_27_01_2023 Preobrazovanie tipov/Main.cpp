#include<iostream>
#include<string>
#include<vector>

// ���������� �����

// Static cast


class Parent {
public:
	virtual void sleep() {
		std::cout << "sleep()\n";
	}
	virtual ~Parent(){};
};

class Child: public Parent {
public:
	void sleep() override {
		std::cout << "Child sleep()\n";
	}
	void gotoScool() {
		std::cout << "gotoScool()\n";
	}

};


int main() {

	setlocale(LC_ALL, "ru");

	Parent parent;
	Child child;

	// Upcast (������� ��������������)
	Parent* pParent = &child; // stack
	Parent* pParent2 = new Child;// ����

	// downcast
	Child* pChild = (Child*)pParent;
	//C-style ���� ��������� ������ �������� ����
	// � �������:
	// 
	// const_cast
	// static_cast
	// static_cast -> const_cast
	// reinterpret_cast
	// reinterpret_cast -> const_cast
	// 
	// ���� ������ � �������� ������������ �� �����������
	// �� ����� ���������(upcast/downcast) ����� static_cast


	//downcast UB ��� ������ ������
	//Child* pChild2 = (Child*)&parent;
	
	pParent->sleep();// sleep() non-virtual child sleep ���� virtual
	pChild->sleep(); // child sleep()
	//pChild2->sleep();//UB
	delete pParent2;

	// static_cast<new_type>(exeption)
	int a = 5;
	std::cout << "a: " << a << '\n';
	double b = static_cast<double>(a);// ������: double(a)
									  // ��� (double)a
	std::cout << "b: " << b << '\n';

	int c = 6;
	const int* pC = &c;
	int* ppC = const_cast<int*>(pC);
	std::cout << "===================\n";
	std::cout << *ppC << '\n';
	*ppC = 4;
	std::cout << *ppC << ' ' << c << '\n';

	// dynamic_cast<new-type>(exeption) 

	Child* pChild3 = dynamic_cast<Child*>(& parent);//���� ���� �� ��������� ��������� ����� ��������� �� nullptr
	if (pChild3 == nullptr) {
		std::cout << "pChild3 is nullptr\n";
	}
	try {
		Child& pChild5 = dynamic_cast<Child&>(parent);
	}
	catch (std::bad_cast& e)
	{
		std::cout << "cast parent to child results in bad_cast\n";
		std::cout << e.what() << '\n';
	}
	//reintsrpred_cast 


		return 0;
}