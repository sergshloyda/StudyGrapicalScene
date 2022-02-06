#ifndef MYPOINT_H
#define MYPOINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsObject>

class MyPoint : public QGraphicsObject
{
	Q_OBJECT

public:
	MyPoint();
	~MyPoint();
signals:
	/* Сигнал, который будет посылаться в том случае,
	* если произошел клик мышью по объекту
	* */
	void signalDblClick();
protected:
	/* Перегружаем метод нажатия мышью, для его перехвата
	* */
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	QPointF display_coordinate;
	/* Данные методы виртуальные, поэтому их необходимо реализовать
	* в случае наследования от QGraphicsItem
	* */
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); 

public:
	void setDisplayCoordinate(const QPointF& coord);

};

#endif // MYPOINT_H


//#ifndef MYPOINT\_H
//#define MYPOINT\_H
// 
//#include <QObject>
//#include <QGraphicsItem>
//#include <QPainter>
 
/* Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
 * */
//class MyPoint : public QObject, public QGraphicsItem
//{
//    Q\_OBJECT
//public:
//    explicit MyPoint(QObject *parent = 0);
//    ~MyPoint();
// 
//signals:
//    /* Сигнал, который будет посылаться в том случае,
//     * если произошел клик мышью по объекту
//     * */
//    void signal1();
// 
//protected:
//    /* Перегружаем метод нажатия мышью, для его перехвата
//     * */
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
// 
//private:
//    /* Данные методы виртуальные, поэтому их необходимо реализовать
//     * в случае наследования от QGraphicsItem
//     * */
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//};
// 
//#endif // MYPOINT\_H