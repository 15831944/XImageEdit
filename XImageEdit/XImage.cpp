#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
//#include "XEditView.h"
#include <QMouseEvent>
//#include "XModel.h"
#include "IController.h"
#include "XMVCFactory.h"
//XModel m;
XImage::XImage(QWidget* p):QWidget(p)
{
	c = IController::Create(new XMVCFactory());
	c->Init(this);

	//XEditView::Get()->InitDevice(this);
	//��ͼ�۲�ģ��
	//m.Attrach(XEditView::Get());
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
	if(!c->InitBack(filename.toLocal8Bit()))
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
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));
	c->AddModel();
	c->Add(e->x(), e->y());
	//����һ��ģ��
}

//Ĭ������ƶ��¼������²Ŵ���
void  XImage::mouseMoveEvent(QMouseEvent* e)
{
	c->Add(e->x(), e->y());
	//�޸�ģ������
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));
	update();
}

void XImage::SetPen()
{
	c->SetStatus(XPEN);
}

void XImage::SetEraser()
{
	c->SetStatus(XERASER);
}

//���ػ��Ʒ��� update������
void XImage::paintEvent(QPaintEvent* e)
{
	c->Paint();
	////�ڵ�ǰ���ڣ�this������
	//QPainter p(this);
	////����ͼƬ
	//p.drawImage(0, 0, src);
}