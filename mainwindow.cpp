#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;"); //change window background
    ui->label->setStyleSheet("QLabel { background-color : black; color : white; }"); // change label background and font color
    ui->label->setAlignment(Qt::AlignLeft); // align text left
    timer_ms = new QTimer(this); // create timer - to update the donut
    QObject::connect(timer_ms,SIGNAL(timeout()), this, SLOT(UpdateLabel())); // connect timer
    timer_ms->start(20); // 20 msec timer
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer_ms;
}

void MainWindow::UpdateLabel(){ // update the text of label
    std::string text = d.iterate(); // string from donut class
    ui->label->setText(QString::fromStdString(text)); //actual update of the label
}
