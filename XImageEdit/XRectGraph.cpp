#include "XRectGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>
void XRectGraph::Draw(XModel* m)
{
	if (!painter || !m) return;
	QPen pen; //����
	pen.setWidth(m->GetPara("size"));
	pen.setColor(QColor(200, 0, 0));
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap);//������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ
	//���ÿ����
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(pen);
	int size = m->poss.size();
	if (size < 2) return;
	//����ʼ�㵽��β������
	int x = m->poss[0].x;
	int y = m->poss[0].y;
	int w = m->poss[size - 1].x - x;
	int h = m->poss[size - 1].y - y;
	painter->drawRect(x, y, w, h);

}
