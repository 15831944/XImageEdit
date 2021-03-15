#include "IController.h"
#include "IView.h"
#include "XModel.h"

IController* IController::Create(IMVCFactory* f)
{
	if (!f) return 0;
	IController* c = f->CreateC();
	c->f = f;
	//c->m = f->CreateM();
	c->v = f->CreateV();
	return c;
}

void IController::Init(void* device)
{
	//��ӱ���ͼ
	AddModel(XIMAGE);
	v->InitDevice(device);
}

bool IController::InitBack(const char* url)
{
	bool re = v->InitBack(url);
	//��ӱ���ͼ
	AddModel(XIMAGE);
	return re;
}

void IController::AddModel(int s)
{
	if (s < 0) s = status;
	//����ģ�ͣ���ӹ۲���
	m = f->CreateM();
	m->Attach(v);
	m->type = s;
	tasks.push_back(m);
}

void IController::Add(int x, int y)
{
	if (!m) return;
	m->Add(XPos(x, y));
	NotifyAll();
}

void IController::Paint()
{
	v->Paint();
}

void IController::NotifyAll()
{
	int size = tasks.size();
	for (int i = 0; i < size; i++) 
	{
		tasks[i]->Notify();
	}
}

IController::IController()
{
}

IController::~IController()
{
}
