#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Add;
class Subtract;
class Multiply;
class Divide;
class QStackedLayout;
class QVBoxLayout;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void display(int number);

private slots:

    void on_btnAdd_clicked();

    void on_btnSubtract_clicked();

    void on_btnMultiply_clicked();

    void on_btnDivide_clicked();

    void on_btnClose_clicked();

private:
    Ui::MainWindow *ui;
    Add *add;
    Subtract *subtract;
    Multiply *multiply;
    Divide *divide;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;

};

#endif // MAINWINDOW_H
