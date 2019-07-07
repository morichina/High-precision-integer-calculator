#ifndef DIVIDE_H
#define DIVIDE_H

#include <QWidget>

namespace Ui {
class Divide;
}

class Divide : public QWidget
{
    Q_OBJECT

public:
    explicit Divide(QWidget *parent = nullptr);
    ~Divide();

signals:
    void display(int number);

private slots:
    void on_btnClear_clicked();

    void on_btnBack_clicked();

    void on_btnCalculator_clicked();

private:
    Ui::Divide *ui;
};

#endif // DIVIDE_H
