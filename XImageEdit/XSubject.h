#pragma once
#include <vector>
class IObserver;
class XSubject
{
public:
	//֪ͨ�۲���
	virtual void Notify();
	
	//��ӹ۲���
	virtual void Attrach(IObserver* ob);

protected:

	//�۲��߶���
	std::vector<IObserver *> obs;
};
