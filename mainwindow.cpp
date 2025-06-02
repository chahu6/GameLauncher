#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QScreen>

#include "topbar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 无边框窗口
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    this->resize(1920, 1080);

    connect(ui->topBar,&TopBar::miniumWindow,[this]() {
        this->showMinimized();
    });
    connect(ui->topBar, &TopBar::closeWindow, [this](){
        this->close();
    });

    connect(ui->topBar, &TopBar::moveWindow, [this](QPoint pos){
        this->move(pos + this->pos());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    // 绘制背景图
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(46, 46, 54)));
    painter.drawPixmap(rect(), QPixmap(":/resource/image/background.jpg"), QRect());
}
