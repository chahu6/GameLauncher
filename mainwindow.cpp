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
    this->setAttribute(Qt::WA_TranslucentBackground); //设置窗口背景透明

    this->setFixedSize(1920, 1080); // 固定大小

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
    // 创建圆角路径
    QPainterPath path;
    const int radius = 10;  // 圆角半径
    path.addRoundedRect(rect(), radius, radius);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿
    painter.setClipPath(path);  // 设置裁剪区域为圆角

    // 绘制背景色
    painter.fillPath(path, QColor(46, 46, 54));

    // 绘制背景图
    painter.drawPixmap(rect(), QPixmap(":/resource/image/background.jpg"), QRect());
}
