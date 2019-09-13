#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "kinect.h"
#include "libfreenect2/libfreenect2.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  int minval = 0;
  int maxval = 0;

 private slots:
  void refreshFrame();

  void on_act_start_triggered();

  void on_act_stop_triggered();

  void on_minDepth_valueChanged(int value);

  void on_maxDepth_valueChanged(int value);

  void on_minDepth_sliderReleased();

  void on_maxDepth_sliderReleased();

 private:
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
