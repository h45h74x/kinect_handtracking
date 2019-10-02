#include "viewport.h"

#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/logger.h>  // Optional
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/registration.h>  // Optional
#include <libfreenect2/libfreenect2.hpp>

#include <QPainter>
#include <QWidget>
#include "tracker.h"

#include <QDebug>

const int scalex = 2;
const int scaley = 2;

const int mywidth = 512;
const int myheight = 424;

ViewPort::ViewPort(QWidget *widget) : QWidget(widget) {}

void ViewPort::init(Tracker *tracker) {
  this->tracker = tracker;
  setTreshold(-1, -1);

  resize(mywidth * scalex, myheight * scaley);
  updateGeometry();
}

void ViewPort::nextFrame() { refresh = true; }

int ViewPort::setTreshold(int min, int max) {
  if (min >= 0) return MINDEPTH = ((min < MAXDEPTH) ? min : MINDEPTH);
  if (max >= 0) return MAXDEPTH = ((max > MINDEPTH) ? max : MAXDEPTH);
  DIFFDEPTH = MAXDEPTH - MINDEPTH;
  return 0;
}

QColor ViewPort::determineFgColor(float value) {
  QColor col;
  if (value <= MINDEPTH || value >= MAXDEPTH) {
    col.setRgb(0, 0, 0);
    return col;
    // return nullptr;
  }

  if ((int)value % 20 == 0) {
    col.setRgb(0, 255, 255);
  } else {
    col.setGreen((value / MAXDEPTH) * 255);
  }

  return col;
}

void ViewPort::drawScaledDot(QPainter *painter, int x, int y) {
  for (int xi = 0; xi < scalex; xi++) {
    for (int yi = 0; yi < scaley; yi++) {
      painter->drawPoint((x * scalex) + xi, (y * scaley) + yi);
    }
  }
}

void ViewPort::paintEvent(QPaintEvent *) {
  if (refresh && tracker->active()) {
    refresh = false;

    MyFrame *frame;
    if ((frame = tracker->getFrame()) == nullptr) return;

    int framewidth = frame->getWidth();
    int frameheigth = frame->getHeight();

    QPainter painter(this);
    QPen linepen(Qt::blue);
    linepen.setWidth(1);

    QColor color;
    for (int xi = 0; xi < framewidth; xi++) {
      for (int yi = 0; yi < frameheigth; yi++) {
        color = determineFgColor(frame->getValueAt(frame->getBackground(),
                                                   frame->getWidth(), xi, yi));
        if (color != nullptr) {
          linepen.setColor(color);
          painter.setPen(linepen);
          drawScaledDot(&painter, xi, yi);
        }
      }
    }
  }
}
