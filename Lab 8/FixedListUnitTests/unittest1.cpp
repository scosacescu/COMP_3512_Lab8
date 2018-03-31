#include "CppUnitTest.h"
#include "../Lab 8/FixedList.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace FixedListUnitTests
{		
	TEST_CLASS(Add)
	{
	public:
		
		TEST_METHOD(AddInts)
		{
			//Arrange
			FixedList<int, 3> l1;
			//Act
			l1.add(10);
			//Assert
			Assert::AreEqual(10, l1[0]);
		}

		TEST_METHOD(AddIntsToFull)
		{
			FixedList<int, 1> l2;
			l2.add(0);
			bool result = l2.add(1);
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(AddStringToFull)
		{
			FixedList<string, 1> l4;
			l4.add("Steph");
			bool result = l4.add("Hello");
			Assert::AreEqual(result, false);
		}

	};

	TEST_CLASS(Remove)
	{
	public:

		TEST_METHOD(RemoveInts)
		{
			//Arrange
			FixedList<int, 3> list;
			//Act
			list.add(10);
			int result = list.remove(10);
			//Assert
			Assert::AreEqual(result, 10);
		}

		TEST_METHOD(RemoveString)
		{
			////Arrange
			//FixedList<string, 3> list;
			////Act
			//list.add("10");
			//string result = list.remove("10");
			////Assert
			//Assert::AreEqual(result, "10");
		}

	};


}