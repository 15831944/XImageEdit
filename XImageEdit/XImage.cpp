#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include "XEditView.h"
#include <QMouseEvent>

XImage::XImage(QWidget* p)
{
	XEditView::Get()->InitDevice(this);
}

XImage::~XImage()
{
}

void XImage::Open()
{
	qDebug() << "XImage::Open()";
	//ѡ��ͼƬ
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("��ͼƬ"),
		"", QStringLiteral("֧�ֵĸ�ʽ(*.jpg *.png *.bmp)"));
	if (filename.isEmpty()) 
	{
		qDebug() << "Open filename is empty!";
		return;
	}
	////����ͼƬ
	//if (!src.load(filename))
	if(!XEditView::Get()->InitBack(filename.toLocal8Bit()))
	{
		qDebug() << "src load image failed!";
		return;
	}
	qDebug() << "src load image success!";
	
	//ˢ����ʾ
	update();
}


//������꺯��
void  XImage::mousePressEvent(QMouseEvent* e)
{
	XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
}

//Ĭ������ƶ��¼������²Ŵ���
void  XImage::mouseMoveEvent(QMouseEvent* e)
{
	XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	update();
}

//���ػ��Ʒ��� update������
void XImage::paintEvent(QPaintEvent* e)
{
	XEditView::Get()->Paint();
	////�ڵ�ǰ���ڣ�this������
	//QPainter p(this);
	////����ͼƬ
	//p.drawImage(0, 0, src);
}