#include "TestEvent1.h"
#include <iostream>
using namespace std;

TestClass::TestClass()
{
	// 关联事件
	m_event.myEvent.associate(this, &TestClass::executeCb1);
	m_event.myEvent.associate(this, &TestClass::executeCb2);
}

// 事件响应函数
bool TestClass::executeCb1(int result)
{
	cout << "executeCb1 result = " << result << endl;
	return true;
}

// 事件响应函数
bool TestClass::executeCb2(int result)
{
	cout << "executeCb2 result = " << result << endl;
	return true;
}

void TestClass::execute()
{
	m_event.test();
}

void TestClass::stop()
{
	// 删除事件关联函数
	m_event.myEvent.disAssociate(this, &TestClass::executeCb1);
}

void TestEvent::test()
{
	myEvent.sendEvent(100);
	myEvent.sendEvent(200);
}
