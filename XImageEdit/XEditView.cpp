#include "XEditView.h"
#include <QPainter>
#include <QWidget>

XEditView::XEditView()
{
}

//��ʾĿ��
void XEditView::InitDevice(void* d)
{
	this->device = (QWidget*)d;
}

//���뱳��ͼ
bool XEditView::InitBack(const char* url)
{
	//����ͼƬ
	if (!src.load(QString::fromLocal8Bit(url))) return false;
	return true;
}

//���ƽ��
void XEditView::Paint()
{
	//��device���ڻ���
	QPainter p(device);
	
	//����ͼƬ
	p.drawImage(0, 0, src);
	//�������������
	//��1��ʼ������Ҫ������
	int size = poss.size();
	for (int i = 1; i < size; i++)
	{
		//�����ߣ���ʼ�㵽������
		p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y, poss[i].x, poss[i].y));
	}
}

XEditView::~XEditView()
{
}
