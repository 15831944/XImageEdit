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
public slots:
	void Open();
protected:
	QImage src;
};
