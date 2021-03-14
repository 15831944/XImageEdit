#pragma once
#include <QWidget>
#include <QImage>

class XImage :public QWidget
{
	Q_OBJECT

public:
	XImage(QWidget* p = 0);
	~XImage();
	
	//���ػ��Ʒ��� update������
	void paintEvent(QPaintEvent *e);

	//������꺯��
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);



public slots:
	void Open();
protected:
	QImage src;
};
