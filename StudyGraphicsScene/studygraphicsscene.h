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
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                            * графической сцены
                             * */
  
    private:
        /* Переопределяем событие изменения размера окна
         * для пересчёта размеров графической сцены
         * */
        void resizeEvent(QResizeEvent * event);
	
	private slots:
		// Таймер для изменения размеров сцены при изменении размеров Окна приложения
		void slotTimer();
};

#endif // STUDYGRAPHICSSCENE_H
