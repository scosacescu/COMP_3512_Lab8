#pragma once
#include <iostream>
#include <array>


template<class T = string, size_t N = 10>
class FixedList {
public:
	FixedList()
	{
		std::cout << "made a list class" << endl;
		
	}
	
	~FixedList() 
	{
		//no dynamic memory so don't do anything here
	}

	const T& get(unsigned int index) const
	{
	
	}
	T& operator[](unsigned int index)
	{
		//int iter = thisList.begin();
		//std::advance(iter, index);
		//int x = *iter;
		//return *iter;
	}
	int getFirstIndex(const T& t) const {

	}
	size_t size()const
	{

	}
	size_t capacity() const {


	}
	bool add(const T& t)
	{

	}
	T remove(const T& t)
	{

	}

	//keep public for testing
	T contents[N];

private:
	//private variables here
	
	

	//void shiftLeft(T& startIndex)
};
