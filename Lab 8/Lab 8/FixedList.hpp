#pragma once
#include <iostream>
#include <list>


using namespace std;

template<class T, size_t N>
class FixedList {
public:
	FixedList();
	~FixedList();
	const T& get(unsigned int index) const;
	T& operator[] (unsignes int index);
	int getFirstIndex(const T& t) const;
	size_t size()const;
	size_t capacity() const;
	bool add(const T& t);
	T remove(const T& t);
private:
	//private variables here
};
