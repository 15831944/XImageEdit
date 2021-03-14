#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>

XImage::XImage(QWidget* p)
{

}

XImage::~XImage()
{
}

void XImage::paintEvent(QPaintEvent* e)
{
	//�ڵ�ǰ���ڣ�this������
	QPainter p(this);
	//����ͼƬ
	p.drawImage(0, 0, src);
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
	//����ͼƬ
	if (!src.load(filename))
	{
		qDebug() << "src load image failed!";
		return;
	}
	qDebug() << "src load image success!";
	
	//ˢ����ʾ
	update();
}