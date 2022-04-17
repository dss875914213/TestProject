#include "TestEvent1.h"
#include <iostream>
using namespace std;

TestClass::TestClass()
{
	// �����¼�
	m_event.myEvent.associate(this, &TestClass::executeCb1);
	m_event.myEvent.associate(this, &TestClass::executeCb2);
}

// �¼���Ӧ����
bool TestClass::executeCb1(int result)
{
	cout << "executeCb1 result = " << result << endl;
	return true;
}

// �¼���Ӧ����
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
	// ɾ���¼���������
	m_event.myEvent.disAssociate(this, &TestClass::executeCb1);
}

void TestEvent::test()
{
	myEvent.sendEvent(100);
	myEvent.sendEvent(200);
}
