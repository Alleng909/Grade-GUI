#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>

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
    int results = 0;
    double hwAverage = (ui->hw1->value() + ui->hw2->value() + ui->hw3->value() + ui->hw4->value()
            + ui->hw5->value() + ui->hw6->value() + ui->hw7->value() + ui->hw8->value())/8;
    if (ui->OptionA->isChecked()) {
        results = .25*hwAverage + .2*ui->mt1->value() + .2*ui->mt2->value() + .35*ui->fe->value();
    } else {
        results = .25*hwAverage + .3*std::max(ui->mt1->value(),ui->mt2->value()) + .44*ui->fe->value();
    }

    ui->redo1->setText(QString::number(results));
    ui->redo2->setValue(results);
}
