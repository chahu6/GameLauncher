#include "bulletin.h"
#include "ui_bulletin.h"

Bulletin::Bulletin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Bulletin)
{
    ui->setupUi(this);

    setFixedWidth(576);
}

Bulletin::~Bulletin()
{
    delete ui;
}
