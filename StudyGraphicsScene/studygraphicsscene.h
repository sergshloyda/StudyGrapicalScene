#ifndef STUDYGRAPHICSSCENE_H
#define STUDYGRAPHICSSCENE_H

#include <QtWidgets/QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include<QGraphicsEllipseItem>
#include<QGraphicsRectItem>
#include<QList>
#include "gridscene.h"
#include "ui_studygraphicsscene.h"

class StudyGraphicsScene : public QMainWindow
{
	Q_OBJECT

public:
	StudyGraphicsScene(QWidget *parent = 0);
	~StudyGraphicsScene();

private:
	Ui::StudyGraphicsSceneClass ui;
	GridScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rect;
    QGraphicsLineItem* line;
    QTimer *timer;      /* ���������� ������ ��� ���������� ���������� ��������
                            * ����������� �����
                             * */
  
    private:
        /* �������������� ������� ��������� ������� ����
         * ��� ��������� �������� ����������� �����
         * */
        void resizeEvent(QResizeEvent * event);
	
	private slots:
		// ������ ��� ��������� �������� ����� ��� ��������� �������� ���� ����������
		void slotTimer();
};

#endif // STUDYGRAPHICSSCENE_H
