#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <QWidget>

namespace Ui {
class Multiply;
}

class Multiply : public QWidget
{
    Q_OBJECT

public:
    explicit Multiply(QWidget *parent = nullptr);
    ~Multiply();

signals:
    void display(int number);

private slots:
    void on_btnClear_clicked();

    void on_btnBack_clicked();

    void on_btnCalculator_clicked();

private:
    Ui::Multiply *ui;
};

#endif // MULTIPLY_H
