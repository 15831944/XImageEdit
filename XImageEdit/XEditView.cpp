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
}

XEditView::~XEditView()
{
}
