#include "carousel.h"
#include "ui_carousel.h"

#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QDesktopServices>

Carousel::Carousel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Carousel)
{
    ui->setupUi(this);

    setFixedSize(576, 324);

    ui->btnLeft->setStyleSheet("background-color:rgba(0,0,0,80);");
    ui->btnRight->setStyleSheet("background-color:rgba(0,0,0,80);");
    ui->btnRight->hide();
    ui->btnLeft->hide();

    nextTimer = new QTimer(this);
    connect(nextTimer, &QTimer::timeout, [this](){
        left = false;
        nextIndex = (curIndex + 1) % imgArr.size();
        animation->start();
    });

    connect(ui->btnLeft,&QPushButton::clicked,[this]() {
        nextTimer->stop();
        left = true;
        nextIndex = (curIndex - 1 + imgArr.size()) % imgArr.size();
        animation->start();
    });

    connect(ui->btnRight,&QPushButton::clicked,[this]() {
        nextTimer->stop();
        left = false;
        nextIndex = (curIndex + 1) % imgArr.size();
        animation->start();
    });


    imgArr.append(QImage(":/resource/image/bg1.jpg"));
    imgArr.append(QImage(":/resource/image/bg2.jpg"));
    imgArr.append(QImage(":/resource/image/bg3.jpg"));

    urls.append("https://infinitynikki.nuanpaper.com/news/324");
    urls.append("https://infinitynikki.nuanpaper.com/news/332");
    urls.append("https://infinitynikki.nuanpaper.com/news/341");

    // 轮播图效果
    animation = new QPropertyAnimation(this, "offset");
    animation->setStartValue(0.f);
    animation->setEndValue(1.f);
    animation->setDuration(400);
    animation->setEasingCurve(QEasingCurve::OutCurve); // 缓出效果

    left = false;
    curIndex = 0;
    nextIndex = 1;
    offset = 0.0;
    connect(animation, &QPropertyAnimation::finished, this, [this]() {
        curIndex = nextIndex;
        offset = 0.0;
        nextTimer->start(4000);
    });

    nextTimer->start(4000);
}

Carousel::~Carousel()
{
    delete ui;
}

qreal Carousel::getOffset()
{
    return offset;
}

void Carousel::setOffset(qreal Inoffset)
{
    this->offset = Inoffset;
    update();
}

void Carousel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    if(!left)
    {
        painter.drawImage(QRect(-width() * offset, 0, width(), height()), imgArr.at(curIndex).scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
        // 绘制下一张图片
        painter.drawImage(QRect(width() * (1 - offset), 0, width(), height()), imgArr.at(nextIndex).scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else
    {
        painter.drawImage(QRect(width() * offset, 0, width(), height()), imgArr.at(curIndex).scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
        // 绘制下一张图片
        painter.drawImage(QRect(-width() * (1 - offset), 0, width(), height()), imgArr.at(nextIndex).scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
}

void Carousel::enterEvent(QEvent *event)
{
    Q_UNUSED(event)

    ui->btnLeft->show();
    ui->btnRight->show();
    this->setCursor(Qt::PointingHandCursor);
}

void Carousel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)

    ui->btnLeft->hide();
    ui->btnRight->hide();
}

// 打开链接
void Carousel::mousePressEvent(QMouseEvent *event)
{
    if(urls.empty()) return;

    if(event->button() == Qt::LeftButton)
    {
        QDesktopServices::openUrl(QUrl(urls.at(curIndex)));
    }
}
