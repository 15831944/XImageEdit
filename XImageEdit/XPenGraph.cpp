#include "XPenGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>
void XPenGraph::Draw(XModel* m)
{
	if (!painter || !m) return;
	QPen pen; //����
	pen.setWidth(5);
	pen.setColor(QColor(200, 0, 0));
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap);//������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ
	int size = m->poss.size();
	//���ÿ����
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(pen);
	for (int i = 1; i < size; i++)
	{
		//�����ߣ���ʼ�㵽������
		painter->drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	}
}