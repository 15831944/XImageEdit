#pragma once
#include <QImage>
class QWidget;
class XEditView
{
public:
	//����ģʽ
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//��ʾĿ��
	virtual void InitDevice(void* d);

	//���뱳��ͼ
	virtual bool InitBack(const char* url);


	//���ƽ��
	virtual void Paint();
	~XEditView();
protected:
	XEditView();
	QWidget* device;
	QImage src;
};

