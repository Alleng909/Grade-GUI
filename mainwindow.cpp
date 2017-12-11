#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//Info box for grading schemes
{
    QMessageBox::information(this, "Grading Schemes",
        "A: 25% HW + 20% Midterm 1 + 20% Midterm 2 + 35% Final Exam \nB: 25% HW + 30% Highest Midterm + 44% Final Exam");
}

void MainWindow::on_pushButton_2_clicked() // Button to recalculate grades.
{
    int test = 99;
    ui->redo1->setText(QString::number(test));
    ui->redo2->setValue(test);
}
