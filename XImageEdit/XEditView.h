#pragma once
#include <QImage>
#include <vector>
using namespace std;

class QWidget;
struct XPos 
{
	XPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x = 0;
	int y = 0;
};
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
	//������
	vector<XPos> poss;
protected:
	XEditView();
	QWidget* device;
	QImage src;
};

