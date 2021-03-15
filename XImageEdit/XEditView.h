#pragma once
#include <QImage>
#include <vector>
#include "IObserver.h"
#include "IView.h"
#include <map>
#include "IGraph.h"
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

	template<class ViewClass>
	IGraph* RegView(int type)
	{
		ViewClass *view = new ViewClass();
		views.insert(make_pair(type, view));
		return view;
	}

	~XEditView();

protected:
	XEditView();
	
	//ͼԪ����ⲿά��
	std::map<int, IGraph*> views;

	QWidget* device;
	//ԭͼ
	QImage src;

	//���ͼ
	QImage out;

	//���Ƶ�out
	QPainter* op = 0;
};

