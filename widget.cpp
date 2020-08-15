#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QString"
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    change_button_status();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int diff){
    money += diff;
    change_button_status();
    ui->lcdNumber->display(money);
}

void Widget::change_button_status(){
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    } else if(money < 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    } else if(money < 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }
}

void Widget::on_pb10_clicked()
{
    change_money(10);
}

void Widget::on_pb50_clicked()
{
    change_money(50);
}

void Widget::on_pb100_clicked()
{
    change_money(100);
}

void Widget::on_pb500_clicked()
{
    change_money(500);
}

void Widget::on_pbCoffee_clicked()
{
    change_money(-100);
}

void Widget::on_pbTea_clicked()
{
    change_money(-150);
}

void Widget::on_pbMilk_clicked()
{
    change_money(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString str = "500: ";
    str += QString::number(money / 500);
    str += ", 100: ";
    str += QString::number(money % 500 / 100);
    str += ", 50: ";
    str += QString::number(money % 100 / 50);
    str += ", 10: ";
    str += QString::number(money % 50 / 10);


    msg.information(nullptr,"Exchange", str);
}
