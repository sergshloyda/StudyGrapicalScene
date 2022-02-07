#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "mypoint.h"

class GridScene : public QGraphicsScene
{
	Q_OBJECT

public:
	GridScene(QObject *parent);
	~GridScene();
	void drawCircle(const QPoint& center,int radius);
	void drawGrid();
	void drawPixmap();

private:
	MyPoint* myPoint;
	 QList<QGraphicsLineItem*> vLines,gLines;
	QImage* bg_image_ ;
	int pixel_in_mm;
protected:
	// Для рисования используем события мыши
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void	drawBackground(QPainter * painter, const QRectF & rect);
	
};

#endif // GRIDSCENE_H
