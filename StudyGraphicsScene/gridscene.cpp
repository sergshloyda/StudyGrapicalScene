#include "gridscene.h"

GridScene::GridScene(QObject *parent)
	: QGraphicsScene(parent)
{
	bg_image_=new QImage();
	bg_image_->load("mm_paper.png");
	this->setSceneRect(0,0, bg_image_->width(), bg_image_->height());
	pixel_in_mm= bg_image_->width()/297;

}

GridScene::~GridScene()
{

}

void GridScene::drawCircle(const QPoint& center,int radius)
{
	QBrush redBrush(Qt::red);
	QBrush blueBrush(Qt::blue);
	QPen blackpen(Qt::black);
	QPen blackThinPen(Qt::black);
	blackThinPen.setWidth(1);
	blackpen.setWidth(6);
   
	addEllipse(center.x(),center.y(),radius*2,radius*2,blackpen,redBrush);

}

void GridScene::drawGrid()
{
	int width = sceneRect().width();      // определяем ширину нашего виджета
	int height =sceneRect().height();    // определяем высоту нашего виджета

	QList<QGraphicsItem*> all = items();
	for (int i = 0; i < all.size(); i++)
	{
		QGraphicsItem *gi = all[i];
		if(gi->parentItem()==NULL) {
			delete gi;
		}
	}
	// vLines.clear();
	for (int x=0; x<=width; x+=width/297)
	{
		vLines.append(addLine(x,0,x,height, QPen(Qt::red)));
	}
	for (int y=0; y<=height; y+=height/210)
		gLines.append(addLine(0,y,width,y, QPen(Qt::green)));
}

void GridScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

	myPoint=new MyPoint();
	addItem(myPoint);
	myPoint->setPos(event->scenePos().x(),event->scenePos().y() );
	
	QPointF displayCoordinate(event->scenePos().x()/pixel_in_mm,event->scenePos().y()/pixel_in_mm);
	myPoint->setDisplayCoordinate(displayCoordinate);
}
void GridScene::drawBackground( QPainter* p, const QRectF& clip )
{
	if( !bg_image_ )   // QImage* bg_image_ - предварительно загруженная картинка
	{
		QGraphicsScene::drawBackground( p, clip );
		return;
	}

	p->eraseRect( clip );

	QMatrix wm( p->worldMatrix() );

	if( wm.m11() != 1 &&
		clip.intersects( bg_image_->rect() ) )
	{
		QImage img;
		QRectF c( clip );
		if( wm.m11() > 1 )
			c.adjust( -1, -1, 1, 1 );

		qreal cx = c.x();
		qreal cy = c.y();
		qreal cw = qMax( 16., c.width() );
		qreal ch = qMax( 16., c.height() );

		if( cx < 0 )
		{
			cw += cx;
			cx = 0;
		}
		if( cy < 0 )
		{
			ch += cy;
			cy = 0;
		}

		cw = qMin( cw, bg_image_->width() - cx );
		ch = qMin( ch, bg_image_->height() - cy );
		img = bg_image_->copy( QRectF( cx, cy, cw, ch ).toRect() );
		cw = qRound( cw * wm.m11() );
		ch = qRound( ch * wm.m11() );
		img = img.scaled( (int) cw, (int) ch, Qt::IgnoreAspectRatio,
			/*wm.m11() > .8 ? Qt::SmoothTransformation :*/ Qt::FastTransformation );
		p->setWorldMatrix( QMatrix( 1, 0, 0, 1, wm.dx(), wm.dy() ) );
		p->drawImage( QPointF( cx * wm.m11(), cy * wm.m11() ), img );
		p->setWorldMatrix( wm );
	}	else
	{	
		p->drawImage( 
			QPointF( clip.x(), clip.y() ),
			*bg_image_,
			QRectF( clip.x(), clip.y(),
			qMin( clip.width(), qreal( bg_image_->width() ) ),
			qMin( clip.height(), qreal( bg_image_->height() ) ) ) );
	}
}