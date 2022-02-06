#include "studygraphicsscene.h"

StudyGraphicsScene::StudyGraphicsScene(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	scene=new GridScene(this);
	ui.graphicsView->setScene(scene);
	QBrush redBrush(Qt::red);

	ui.graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
	//ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
	//ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

	timer = new QTimer();       // Инициализируем таймер
	connect(timer, &QTimer::timeout, this, &StudyGraphicsScene::slotTimer);
	timer->start(100);          // Запускаем таймер
	//ellipse=scene->addEllipse(10,10,100,100,blackpen,redBrush);
	scene->drawCircle(QPoint(10,10),100);


}

StudyGraphicsScene::~StudyGraphicsScene()
{

}

void StudyGraphicsScene::resizeEvent(QResizeEvent * event)
{
	timer->start(1000/25);
	QMainWindow::resizeEvent(event);
}

void StudyGraphicsScene::slotTimer()
{
	timer->stop();
	//scene->setSceneRect(0,0, ui.graphicsView->width() - 20, ui.graphicsView->height() - 20);
scene->drawGrid();

scene->drawCircle(QPoint(10,10),50);


}
