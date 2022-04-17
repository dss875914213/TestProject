#pragma once
#include <windows.h>

// 响应事件函数类必须是从 object 派生下来
class Object
{

};

template<typename rtnType, typename argsType>
class Event
{
	// 最多关联的函数个数
#define EVENT_LIST_MAX_NUM (10)
	typedef rtnType(Object::* pMemFunc)(argsType arg);
public:
	Event()
	{
		m_totalFunc = 0;
		m_obj = NULL;
		for (int i = 0; i < EVENT_LIST_MAX_NUM; i++)
			m_func[i] = NULL;
	}

	// 关联回调成员函数
	template<class funcType>
	void associate(Object* obj, funcType func)
	{
		m_obj = obj;
		m_func[m_totalFunc] = static_cast<pMemFunc>(func);
		m_totalFunc++;
	}

	// 删除事件关联回调成员函数
	template <class funcType>
	void disAssociate(Object* obj, funcType func)
	{
		bool isFind = false;
		int i = 0;
		if (obj != m_obj)
			return;

		// 查找
		for (i = 0; i < m_totalFunc; i++)
		{
			if (m_func[i] == func)
			{
				isFind = true;
				break;
			}		
		}

		if (isFind)
		{
			// 删除
			for (i; i < m_totalFunc - 1; i++)
				m_func[i] = m_func[i + 1];

			m_func[i] = NULL;
			m_totalFunc--;
		}
	}

	// 执行相关联的回调函数
	void sendEvent(argsType arg)
	{
		for (int i = 0; i < m_totalFunc; i++)
		{
			if (m_func[i] != NULL)
				((m_obj->*pMemFunc(m_func[i])))(arg);
		}
	}

private:
	Object* m_obj;
	pMemFunc m_func[EVENT_LIST_MAX_NUM];
	int m_totalFunc;
};


