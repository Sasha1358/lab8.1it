#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* str = "aabbccddee";
			Assert::AreEqual(1, Count(str));
		}
	};
}
