#pragma once
#include "event.h"

class TestEvent
{
public:
	void test();
public:
	Event<bool, int> myEvent;
};

class TestClass : public Object
{
public:
	TestClass();
	bool executeCb1(int result);
	bool executeCb2(int result);
	void execute();
	void stop();
private:
	TestEvent m_event;
};

