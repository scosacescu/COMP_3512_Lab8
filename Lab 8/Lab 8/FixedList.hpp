#pragma once
#include <array>
#include <iostream>
#include <string>
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
	//PRE: Specify the index of the element you want from your list
	//POST: Element stored at that index will be returned, if valid
	//Note: This will not allow access to indices to which the user has not yet 
	//      added elements, regardless of total capacity
	const T& get(unsigned int index) const
	{
		size_t ind = static_cast<size_t>(index);

		//make sure they're requesting a valid index
		if (ind < maxCapacity) {
			//make sure they're requesting an index that actually stores a value
			if (ind <= (counter - 1)) {
				cout << "The element stored at index " << ind << " is " << contents[ind] << endl;
				return contents[ind];
			}
			//if this index is "empty", then don't get whatever's stored there
			else
			{
				cout << "Sorry, there's nothing stored at index " << ind << " yet." << endl;
				return contents[ind];
			}
		}
		else
		{
			cout << "Sorry, you've requested access to an invalid index" << endl;
			return contents[ind];
		}
	}
	
	// Overload the [] operator just for funsies. This works the same as get(index) above
	T& operator[](unsigned int index)
	{
		size_t i = static_cast<size_t>(index);
		if (i <= maxCapacity) 
		{
			return contents[i];
		}
		else {
			cout << "Index out of bounds. ";
			return contents[-1];
		}
	}
	
	//PRE: Specify the element to search for in the FixedList
	//POST: The index of the first occurence of that element returned, else -1
	int getFirstIndex(const T& t) const {
		for (size_t i = 0; i < maxCapacity; i++) {
			if (contents[i] == t) {
				cout << "The value " << t << " first occured at index: " << i << endl;
				return static_cast<int>(i);
			}
		}
		return -1;
	}
	
	//PRE: a FixedList object
	//POST: The actual number of elements in the FixedList's contents[]
	size_t size()const
	{
		cout << "There are " << counter << " elements stored in your FixedList" << endl;
		return counter;
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
		if (counter < maxCapacity) {
			contents[counter] = t;
			cout << "Inserted value " << t << " at index " << counter << endl;
			++counter;
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
		//iterate through occupied indices until you find the first occurence of the element
		for (size_t i = 0; i < counter; i++) {
			if (contents[i] == t){
				T removedElement = contents[i];
				//check success of shifting before wrapping up
				if (shiftLeft(i)) {
					cout << "Element " << removedElement << " successfully removed from index " << i << endl;
					//return the removed element.
					return removedElement;
				}
				else
				{
					cout << "Unable to remove element" << endl;
					return t;
				}
			}
		}
	}

	bool shiftLeft(size_t index) {
		while (index < counter) {
			contents[index] = contents[index + 1];
			++index;
		}
		//decrement the counter to make sure we restrict access to our FixedList's contents
		counter--;
		return true;
	}

private:
	static constexpr size_t maxCapacity = N; //assign the max capacity through template params
	T contents[maxCapacity]; //this is the "fixed list" our FixedList class is built to manage
	size_t counter = 0;
};