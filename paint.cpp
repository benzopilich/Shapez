#include "paint.h"
#include "ui_paint.h"
#include <QColorDialog>
#include "mas.h"
#include "paintscene.h"

Paint::Paint(QWidget *parent) :
    QMainWindow(parent),
    color(Qt::green),
    ui(new Ui::Paint)
{
    ui->setupUi(this);
    scene = new paintScene(parent, color);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);

}

Paint::~Paint()
{
    delete ui;
}

void Paint::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Paint::on_action_5_triggered()
{
    scene->setTypeFigure(paintScene::SquareType);
}

void Paint::on_action_6_triggered()
{
    scene->setTypeFigure(paintScene::OvalType);
}

void Paint::on_action_7_triggered()
{
    scene->setTypeFigure(paintScene::RombType);
}

void Paint::on_action_9_triggered()
{
    color = QColorDialog::getColor(Qt::black, this);
    scene->c = color;
}



