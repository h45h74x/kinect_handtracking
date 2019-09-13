#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QPainter>
#include <QWidget>
#include <QtGui>
#include "libfreenect2/libfreenect2.hpp"
#include "tracker.h"

class ViewPort : public QWidget {
 public:
  ViewPort(QWidget *widget);
  void init(Tracker *tracker);
  void nextFrame();
  void setFrame(libfreenect2::Frame *frame);

  int MINDEPTH = 250;
  int MAXDEPTH = 750;
  int DIFFDEPTH = 0;
  int setTreshold(int min, int max);

 protected:
  void paintEvent(QPaintEvent *);

 private:
  Tracker *tracker;
  libfreenect2::Frame *frame;
  bool refresh = false;

  float SCALE = 1;

  QColor determineFgColor(float value);
};

#endif  // VIEWPORT_H
