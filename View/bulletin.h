#ifndef BULLETIN_H
#define BULLETIN_H

#include <QWidget>

namespace Ui {
class Bulletin;
}

class Bulletin : public QWidget
{
    Q_OBJECT

public:
    explicit Bulletin(QWidget *parent = nullptr);
    ~Bulletin();

private:
    Ui::Bulletin *ui;
};

#endif // BULLETIN_H
