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

ViewPort::ViewPort(QWidget *widget) : QWidget(widget) {}

void ViewPort::init(Tracker *tracker) {
  this->tracker = tracker;
  setTreshold(-1, -1);
}

void ViewPort::nextFrame() { refresh = true; }

int ViewPort::setTreshold(int min, int max) {
  if (min >= 0) return MINDEPTH = ((min < MAXDEPTH) ? min : MINDEPTH);
  if (max >= 0) return MAXDEPTH = ((max > MINDEPTH) ? max : MAXDEPTH);
  DIFFDEPTH = MAXDEPTH - MINDEPTH;
  return 0;
}

QColor ViewPort::determineFgColor(float value) {
  if (value <= MINDEPTH || value >= MAXDEPTH) return nullptr;
  QColor col;

  if ((int)value % 20 == 0) {
    col.setRgb(255, 255, 255);
  } else {
    col.setGreen((value / MAXDEPTH) * 255);
  }

  return col;
}

void ViewPort::paintEvent(QPaintEvent *) {
  if (refresh && tracker->active()) {
    refresh = false;

    MyFrame *frame;
    if ((frame = tracker->getFrame()) == nullptr) return;

    int framewidth = frame->getWidth();
    int frameheigth = frame->getHeight();

    setFixedSize(framewidth * SCALE, frameheigth * SCALE);
    resize(framewidth * SCALE, frameheigth * SCALE);
    updateGeometry();

    QPainter painter(this);
    painter.scale(SCALE, SCALE);

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
          painter.drawPoint(xi, yi);
        }
      }
    }
  }
}
