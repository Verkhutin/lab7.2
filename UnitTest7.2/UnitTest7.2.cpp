#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2/lab7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			const int r = 2, c = 2;
			int** T = new int* [r];
			for (int i = 0; i < r; i++)
				T[i] = new int[c];

			T[0][0] = 1; T[0][1] = 2; T[1][0] = 3; T[1][1] = 4;

			int t = SumMinInRow(T, r, c);
			Assert::AreEqual(t, 4);
		}
	};
}
