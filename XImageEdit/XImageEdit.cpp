#include "XImageEdit.h"
#include <QColorDialog>
XImageEdit::XImageEdit(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	//����¼��������ͼƬ
	connect(ui.openB, SIGNAL(clicked()), ui.image, SLOT(Open()));
	connect(ui.penButton, SIGNAL(clicked()), ui.image, SLOT(SetPen()));
	connect(ui.eraserButton, SIGNAL(clicked()), ui.image, SLOT(SetEraser()));
	connect(ui.rectButton, SIGNAL(clicked()), ui.image, SLOT(SetRect()));
	connect(ui.undoButton, SIGNAL(clicked()), ui.image, SLOT(Undo()));
	connect(ui.redoButton, SIGNAL(clicked()), ui.image, SLOT(Redo()));
	connect(ui.penSizeSlider, SIGNAL(valueChanged(int)), ui.image, SLOT(SetPenSize(int)));
}

void XImageEdit::SetColor()
{
	QColor col = QColorDialog::getColor(Qt::red, this);
	//background-color: rgba(255, 0, 0, 200);
	QString sty = QString("background-color: rgba(%1, %2, %3, %4)")
		.arg(col.red()).arg(col.green()).arg(col.blue()).arg(col.alpha());
	ui.colorButton->setStyleSheet(sty);
	ui.image->SetPenColor(col.red(), col.green(),col.blue(),col.alpha());
}