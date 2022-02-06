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
	/* ������, ������� ����� ���������� � ��� ������,
	* ���� ��������� ���� ����� �� �������
	* */
	void signalDblClick();
protected:
	/* ����������� ����� ������� �����, ��� ��� ���������
	* */
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	QPointF display_coordinate;
	/* ������ ������ �����������, ������� �� ���������� �����������
	* � ������ ������������ �� QGraphicsItem
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
 
/* ����� �������� ����� � �������, ����������� �� QOBJECT,
 * */
//class MyPoint : public QObject, public QGraphicsItem
//{
//    Q\_OBJECT
//public:
//    explicit MyPoint(QObject *parent = 0);
//    ~MyPoint();
// 
//signals:
//    /* ������, ������� ����� ���������� � ��� ������,
//     * ���� ��������� ���� ����� �� �������
//     * */
//    void signal1();
// 
//protected:
//    /* ����������� ����� ������� �����, ��� ��� ���������
//     * */
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
// 
//private:
//    /* ������ ������ �����������, ������� �� ���������� �����������
//     * � ������ ������������ �� QGraphicsItem
//     * */
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//};
// 
//#endif // MYPOINT\_H