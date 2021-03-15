#pragma once
class QPainter;
class QImage;
class XModel;
class IGraph
{
public:
	virtual void Init(QPainter* p, QImage* s)
	{
		painter = p;
		src = s;
	}
	//����ͼԪ
	virtual void Draw(XModel* m) = 0;
protected:
	QPainter* painter = 0;
	//ԭͼ������ͼ
	QImage* src = 0;
};

