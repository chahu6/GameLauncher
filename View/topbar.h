#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>

namespace Ui {
class TopBar;
}

class TopBar : public QWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget *parent = nullptr);
    ~TopBar();

protected:
    virtual void mousePressEvent(QMouseEvent*event) override;
    virtual void mouseMoveEvent(QMouseEvent*event) override;
    virtual void mouseReleaseEvent(QMouseEvent*event) override;

    virtual void paintEvent(QPaintEvent *event) override;

signals:
    void moveWindow(QPoint pos);
    void miniumWindow();
    void closeWindow();
    void showSettingDialog();

private:
    Ui::TopBar *ui;

    bool isPressed;
    QPoint curPos;
};

#endif // TOPBAR_H
