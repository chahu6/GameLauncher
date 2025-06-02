#ifndef CAROUSEL_H
#define CAROUSEL_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class Carousel;
}

class Carousel : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal offset READ getOffset WRITE setOffset) //添加新属性，用于属性动画

public:
    explicit Carousel(QWidget *parent = nullptr);
    ~Carousel();

    qreal getOffset();
    void setOffset(qreal Inoffset);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Carousel *ui;

    QTimer * nextTimer;
    QVector<QImage>imgArr;
    QVector<QString>urls;
    int curIndex;
    int nextIndex;
    bool left;
    qreal offset;
    QPropertyAnimation* animation;
};

#endif // CAROUSEL_H
