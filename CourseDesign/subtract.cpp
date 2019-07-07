#include "subtract.h"
#include "ui_subtract.h"
#include "integer.h"
#include <QString>
#include <string>

Subtract::Subtract(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Subtract)
{
    ui->setupUi(this);
    ui->num_1->setPlaceholderText("请输入被减数");
    ui->num_2->setPlaceholderText("请输入减数");
    ui->result->setPlaceholderText("此处将显示结果");
    ui->result->setReadOnly(true);
}

Subtract::~Subtract()
{
    delete ui;
}

void Subtract::on_btnClear_clicked()
{
    ui->num_1->clear();
    ui->num_2->clear();
    ui->result->clear();
    ui->warning->clear();
}

void Subtract::on_btnBack_clicked()
{
    emit display(0);
    ui->num_1->clear();
    ui->num_2->clear();
    ui->result->clear();
    ui->warning->clear();
}

void Subtract::on_btnCalculator_clicked()
{
    string num_1 = this->ui->num_1->text().toStdString();
    string num_2 = this->ui->num_2->text().toStdString();
    int a = 1, b = 1;
    int check = 0;
    Integer A;
    if(num_1[0] == '-')
    {
        a = 0;
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
        b = 0;
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
        string result = "";
        if ((a + b) != 1 && A.compare(B) == 0)
        {
            result += "0";
            QString qResult = QString::fromStdString(result);
            ui->result->setText(qResult);
        }
        else {
            if(a == 0&& b == 0)
            {
                if(A.compare(B) == 1) result += "-";
                A.subtract(B);
            }
            else if(a == 0&& b == 1)
            {
                result +=  "-";
                A.add(B);
            }
            else if(a == 1&& b == 0) A.add(B);
            else
            {
               if(A.compare(B) == -1) result += "-";
               A.subtract(B);
            }
            for(int i = 0; i < A.length; i++)
            {
                result += char(A.num[A.length - 1 - i] + 48);
            }
            QString qResult = QString::fromStdString(result);
            ui->result->setText(qResult);
        }
    }

}
