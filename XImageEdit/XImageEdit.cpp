#include "XImageEdit.h"

XImageEdit::XImageEdit(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	//����¼��������ͼƬ
	connect(ui.openB, SIGNAL(clicked()), ui.image, SLOT(Open()));


}
