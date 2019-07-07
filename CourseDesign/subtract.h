#ifndef SUBTRACT_H
#define SUBTRACT_H

#include <QWidget>

namespace Ui {
class Subtract;
}

class Subtract : public QWidget
{
    Q_OBJECT

public:
    explicit Subtract(QWidget *parent = nullptr);
    ~Subtract();

signals:
    void display(int number);

private slots:
    void on_btnClear_clicked();

    void on_btnBack_clicked();

    void on_btnCalculator_clicked();

private:
    Ui::Subtract *ui;
};

#endif // SUBTRACT_H
