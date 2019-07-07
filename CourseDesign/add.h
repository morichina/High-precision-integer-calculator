#ifndef ADD_H
#define ADD_H

#include <QWidget>

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

signals:
    void display(int number);


private slots:
    void on_btnClear_clicked();

    void on_btnBack_clicked();

    void on_btnCalculator_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
