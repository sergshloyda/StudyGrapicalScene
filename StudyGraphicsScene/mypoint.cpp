#include "mypoint.h"

MyPoint::MyPoint()
	: QGraphicsObject()
{
setDisplayCoordinate(QPoint(0,0));

}

MyPoint::~MyPoint()
{

}

void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalDblClick();
	// Вызываем родительскую функцию события нажатия кнопки мыши
	QGraphicsItem::mousePressEvent(event);
}

QRectF MyPoint::boundingRect() const
{
 return QRectF(-7,-7,80,14);
}

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	
	painter->setBrush(Qt::NoBrush);
	painter->drawEllipse(QPoint(0,0),5,5);
	painter->drawLine(0,-7,0,7);
	painter->drawLine(-7,0,7,0);
	QString coordinate=QString("(%1,%2)").arg(display_coordinate.x(),0,'f',1).arg(display_coordinate.y(),0,'f',1);
	painter->drawText(5,5, coordinate);

}

void MyPoint::setDisplayCoordinate(const QPointF& coord)
{
	display_coordinate=coord;
}
