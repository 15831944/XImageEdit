#pragma once
#include "IMVCFactory.h"
#include <vector>
enum XSTATUS
{
	XPEN,
	XERASER
};

class IController
{
public:
	static IController* Create(IMVCFactory *f);
	virtual void Init(void* device);
	//���뱳��ͼ
	virtual bool InitBack(const char* url);
	//���ģ�Ͷ���
	virtual void AddModel();
	//����ǰģ���������
	virtual void Add(int x, int y);
	virtual void Paint();
	IController();
	~IController();
protected:
	IView* v = 0;
	XModel* m = 0;
	IMVCFactory* f = 0;
	//�������
	std::vector<XModel*> tasks;
};

