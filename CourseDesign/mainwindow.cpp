#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"
#include <QStackedLayout>
#include <QPushButton>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add = new Add;
    subtract = new Subtract;
    multiply = new Multiply;
    divide = new Divide;
    stackLayout = new QStackedLayout;
    stackLayout->addWidget(this);
    stackLayout->addWidget(add);
    stackLayout->addWidget(subtract);
    stackLayout->addWidget(multiply);
    stackLayout->addWidget(divide);
    stackLayout->addWidget(this);
    connect(this, &MainWindow::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(add, &Add::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(subtract, &Subtract::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(multiply, &Multiply::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(divide, &Divide::display, stackLayout, &QStackedLayout::setCurrentIndex);
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackLayout);
    setLayout(mainLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    emit display(1);
}

void MainWindow::on_btnSubtract_clicked()
{
    emit display(2);
}

void MainWindow::on_btnMultiply_clicked()
{
    emit display(3);
}

void MainWindow::on_btnDivide_clicked()
{
    emit display(4);
}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}
