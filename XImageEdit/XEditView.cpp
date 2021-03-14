#include "XEditView.h"
#include <QPainter>
#include <QWidget>
#include "XModel.h"

XEditView::XEditView()
{
	//��ʼ��ͼ��δ��ͼ��ֱ�ӻ�ͼ
	out = QImage(1280, 720, QImage::Format_RGB888);
	src = QImage(1280, 720, QImage::Format_RGB888);
}

void XEditView::Update(XSubject* data)
{
	if (!data) return;
	//XModel
	XModel* m = static_cast<XModel*>(data);
	int size = m->poss.size();
	QPainter p(&out);
	for (int i = 1; i < size; i++)
	{
		//�����ߣ���ʼ�㵽������
		p.drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	}
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
	out = src.copy();
	return true;
}

//���ƽ��
void XEditView::Paint()
{
	//��device���ڻ���
	QPainter p(device);
	p.drawImage(0, 0, out);
	////����ͼƬ
	//p.drawImage(0, 0, src);
	////�������������
	////��1��ʼ������Ҫ������
	//int size = poss.size();
	//for (int i = 1; i < size; i++)
	//{
	//	//�����ߣ���ʼ�㵽������
	//	p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y, poss[i].x, poss[i].y));
	//}
}

XEditView::~XEditView()
{
}
