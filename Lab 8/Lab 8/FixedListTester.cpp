#include "FixedList.hpp"
using namespace std;

int main() {

	FixedList<int, 5> testList3;

	//check capacity method is correct
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
	testList3.get(7);

	testList3.getFirstIndex(1);
	testList3.size();

	testList3.remove(2);
	testList3.get(0);
	testList3.get(1);
	testList3.get(2);
	testList3.get(3);
	testList3.get(4);
	testList3.get(5);
	testList3.get(6);
 
	cout << "value at index 6: " << testList3[6] << endl;;
	cout << "value at index 2: " <<testList3[2] << endl;

	cout << "Test with T = string" << "------------------------" <<endl;
	FixedList<string, 5> testList4;

	testList4.capacity();

	testList4.add("Chris");
	testList4.add("Albert");
	testList4.add("D'arcy");

	testList4.get(0);
	testList4.get(4);

	testList4.getFirstIndex("Chris");
	testList4.size();

	testList4.remove("Albert");
	testList4.get(0);
	testList4.get(1);
	testList4.get(2);
	
	cin.get();
}

