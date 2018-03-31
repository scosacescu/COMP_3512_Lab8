#pragma once
#include <iostream>
#include <array>
#include <typeinfo>


template<class T = string, size_t N = 10>
class FixedList {
public:
	// Zero Param constructor. Type and size to be specified via template params
	FixedList()
	{
		std::cout << "made a FixedList class with type = " << typeid(T).name() << " and size = "<< maxCapacity << endl;
	}
	
	~FixedList() {}

	//Access to elements stored in your FixedList 
	//PRE: Specify the index of the element you want in your list
	//POST: Element stored at that index will be returned, if valid
	const T& get(unsigned int index) const
	{
		cout << "The element stored at index " << index << " is " << contents[index] << endl;
		return contents[index];
	}
	
	// Overload the [] operator just for funsies. This works the same as get(index) above
	T& operator[](unsigned int index)
	{

	}
	
	//PRE: Specify the element to search for in the FixedList
	//POST: The index of the first occurence of that element returned, else -1
	int getFirstIndex(const T& t) const {
		for (size_t i = 0; i < maxCapacity; i++) {
			if (contents[i] == t) {
				cout << "The value " << t << " first occured at index: " << i << endl;
				return i;
			}
		}
		return -1;
	}
	
	//PRE: a FixedList object
	//POST: The actual number of elements in the FixedList's contents[]
	size_t size()const
	{
		return 1;

	}

	//PRE: a FixedList object
	//POST: The maximum number of elements in the FixedList's container[]
	size_t capacity() const {
		cout << "The maximum capacity of your FixedList is: " << maxCapacity << endl;
		return maxCapacity;
	}

	//PRE:  Add the specified element to the FixedLists' contents[], space permitting
	//POST: True on success, else false
	bool add(const T& t)
	{
		if (counter <= static_cast<int>(maxCapacity)) {
			contents[counter] = t;
			cout << "Inserted value " << t << " at index " << counter << endl;
			counter++;
			return true;
		}
		else
		{
			cout << "Sorry, list full! Unable to insert value " << t << endl;
			return false;
		}
	}

	//PRE: Remove the first occurence of the specified element from the FixedList's contents[]
	//POST: If found, the element will be returned and all following elements will be shifted one left. 
	T remove(const T& t)
	{
		for (size_t i = 0; i < 10; i++) {
			if (contents[i] == t){
				//remove
				//shiftLeft(i);
				break;
			}
			else {
				return -1;
			}
		}

	}


	static constexpr size_t maxCapacity = N; //assign the max capacity through template params
	T contents[maxCapacity]; //this is the "fixed list" our FixedList class is built to manage
	int counter = 0;

private:
	
	
	

	//void shiftLeft(T startIndex)
};