#pragma once
#include <QImage>
#include <vector>
#include "IObserver.h"
#include "IView.h"
using namespace std;

class QWidget;

class XEditView: public IView
{
public:
	//����ģʽ
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//ˢ�µ�out��
	virtual void Update(XSubject* data);

	//��ʾĿ��
	virtual void InitDevice(void* d);

	//���뱳��ͼ
	virtual bool InitBack(const char* url);

	//����out���
	virtual void Paint();
	~XEditView();

protected:
	XEditView();
	QWidget* device;
	//ԭͼ
	QImage src;

	//���ͼ
	QImage out;
};

