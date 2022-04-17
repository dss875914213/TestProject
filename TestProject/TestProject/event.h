#pragma once
#include <windows.h>

// ��Ӧ�¼�����������Ǵ� object ��������
class Object
{

};

template<typename rtnType, typename argsType>
class Event
{
	// �������ĺ�������
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

	// �����ص���Ա����
	template<class funcType>
	void associate(Object* obj, funcType func)
	{
		m_obj = obj;
		m_func[m_totalFunc] = static_cast<pMemFunc>(func);
		m_totalFunc++;
	}

	// ɾ���¼������ص���Ա����
	template <class funcType>
	void disAssociate(Object* obj, funcType func)
	{
		bool isFind = false;
		int i = 0;
		if (obj != m_obj)
			return;

		// ����
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
			// ɾ��
			for (i; i < m_totalFunc - 1; i++)
				m_func[i] = m_func[i + 1];

			m_func[i] = NULL;
			m_totalFunc--;
		}
	}

	// ִ��������Ļص�����
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


