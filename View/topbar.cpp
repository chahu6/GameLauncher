#include "topbar.h"
#include "ui_topbar.h"

#include <QMouseEvent>

TopBar::TopBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TopBar)
{
    ui->setupUi(this);
    isPressed = false;

    setMaximumHeight(80);

    connect(ui->btnMinium,&QPushButton::clicked,[this]() {
        emit miniumWindow();
    });

    connect(ui->btnClose,&QPushButton::clicked,[this]() {
        emit closeWindow();
    });

    connect(ui->btnSetting,&QPushButton::clicked,[this]() {
        emit showSettingDialog();
    });
}

TopBar::~TopBar()
{
    delete ui;
}

void TopBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isPressed = true;
        curPos = event->pos();
    }
}

void TopBar::mouseMoveEvent(QMouseEvent *event)
{
    if(isPressed)
    {
        emit moveWindow(event->pos() - curPos);
    }
}

void TopBar::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    isPressed = false;
}

void TopBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

}
