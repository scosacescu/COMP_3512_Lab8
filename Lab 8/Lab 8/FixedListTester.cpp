#include "FixedList.hpp"
using namespace std;

int main() {

	//test objects
	FixedList<int, 5> testList{};
	FixedList<> testList2{};
	FixedList<int, 5> testList3;

	//make sure passing template params works
	cout << testList.maxCapacity << endl;
	cout << testList2.maxCapacity << endl;

	//check capacity method is correct
	testList.capacity();
	testList2.capacity();
	testList3.capacity();

	// check add()
	testList3.add(0);
	testList3.add(1);
	testList3.add(2);
	testList3.add(3);
	testList3.add(4);
	testList3.add(5);
	testList3.add(6);

	// test retrieval of values at specified indices
	testList3.get(0);


	


	cin.get();
}

