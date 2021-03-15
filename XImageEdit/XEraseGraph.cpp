#include "XEraseGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>
void XEraseGraph::Draw(XModel* m)
{
	if (!painter || !m) return;
	QPen pen; //����
	pen.setWidth(5);
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap);//������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ
	//��ԭͼ��ˢ��
	pen.setBrush(*src);
	//���ÿ����
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(pen);
	int size = m->poss.size();
	for (int i = 1; i < size; i++)
	{
		//�����ߣ���ʼ�㵽������
		painter->drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	}
}