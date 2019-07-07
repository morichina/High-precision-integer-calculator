#include "divide.h"
#include "ui_divide.h"
#include "integer.h"
#include <QString>
#include <cstring>
#include <QDebug>

Divide::Divide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Divide)
{
    ui->setupUi(this);
    ui->num_1->setPlaceholderText("请输入被除数");
    ui->num_2->setPlaceholderText("请输入除数");
    ui->result->setPlaceholderText("此处将显示结果");
    ui->result->setReadOnly(true);
}

Divide::~Divide()
{
    delete ui;
}

void Divide::on_btnClear_clicked()
{
    ui->num_1->clear();
    ui->num_2->clear();
    ui->result->clear();
    ui->warning->clear();
}

void Divide::on_btnBack_clicked()
{
    ui->num_1->clear();
    ui->num_2->clear();
    ui->result->clear();
    ui->warning->clear();
    emit display(0);
}

void Divide::on_btnCalculator_clicked()
{
    string num_1 = this->ui->num_1->text().toStdString();
    string num_2 = this->ui->num_2->text().toStdString();
    int a = 1, b = 1;
    int check = 0;
    Integer A;
    if(num_1[0] == '-')
    {
        a = -1;
        num_1 = num_1.erase(0,1);
    }
    A.input(num_1);
    if(A.check() == -1)
    {
        this->ui->warning->setText("(您输入了非法字符，请输入正确的高精度整数!)");
        check = 1;
    }

    Integer B;
    if(num_2[0] == '-')
    {
        b = -1;
        num_2 = num_2.erase(0,1);
    }
    B.input(num_2);
    if(B.check() == -1)
    {
        this->ui->warning->setText("(您输入了非法字符，请输入正确的高精度整数!)");
        check = 1;
    }
    if(check == 0)
    {
        Integer C;
        string result = "";
        if (B.isZero() == 0) {
            this->ui->warning->setText("(您不能使除数为0，请输入正确的数据!)");
        }
        else if (A.isZero() == 0) {
            result += "0";
            QString qResult = QString::fromStdString(result);
            ui->result->setText(qResult);
        }
        else {
            if((a*b) > 0) C = A.divide(B);
            else
            {
                C = A.divide(B);
                if(C.isZero() != 0) result += "-";
            }
            for(int i = 0; i < C.length; i++)
            {
                result += char(C.num[C.length - 1 - i] + 48);
            }
            QString qResult = QString::fromStdString(result);
            ui->result->setText(qResult);
            qDebug() << qResult;
        }
    }
}
