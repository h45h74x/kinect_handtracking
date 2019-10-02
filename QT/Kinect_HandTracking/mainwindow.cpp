#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>
#include "viewport.h"

#include "kinect.h"
#include "libfreenect2/libfreenect2.hpp"

#include "tracker.h"
Tracker tracker;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  tracker.init();
  ui->canvas->init(&tracker);

  tracker.start();  // DEBUG

  ui->maxDepth->setValue(ui->canvas->MAXDEPTH);
  ui->minDepth->setValue(ui->canvas->MINDEPTH);
  ui->minlabel->setText(QString::number(ui->canvas->MINDEPTH));
  ui->maxlabel->setText(QString::number(ui->canvas->MAXDEPTH));

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(refreshFrame()));
  timer->start(100);

  ui->canvas->setFixedSize(10000, 10000);

  ui->canvas->nextFrame();
}

void MainWindow::refreshFrame() {
  ui->canvas->nextFrame();
  ui->canvas->repaint();
}

MainWindow::~MainWindow() {
  tracker.shutdown();
  delete ui;
}

void MainWindow::on_act_start_triggered() { tracker.start(); }

void MainWindow::on_act_stop_triggered() { tracker.stop(); }

void MainWindow::on_minDepth_valueChanged(int value) {
  minval = ui->canvas->setTreshold(value, -1);
  ui->minlabel->setText(QString::number(minval));
}

void MainWindow::on_maxDepth_valueChanged(int value) {
  maxval = ui->canvas->setTreshold(-1, value);
  ui->maxlabel->setText(QString::number(maxval));
}

void MainWindow::on_minDepth_sliderReleased() {
  ui->minDepth->setValue(minval);
}

void MainWindow::on_maxDepth_sliderReleased() {
  ui->maxDepth->setValue(maxval);
}
