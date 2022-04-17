// https://www.cnblogs.com/bastard/archive/2012/01/10/2318417.html

#include "TestEvent1.h"
int main()
{
	TestClass testObj;

	testObj.execute();
	testObj.stop();
	testObj.execute();
	return 0;
}