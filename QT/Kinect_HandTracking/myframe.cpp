#include "myframe.h"

#include <QDebug>
#include <QString>

MyFrame::MyFrame(int width, int height) {
  this->width = width;
  this->height = height;

  size_t gridsize = sizeof(float) * width * height;
  foreground = (float *)malloc(gridsize);
  background = (float *)malloc(gridsize);
}

MyFrame::~MyFrame() {
  free(foreground);
  free(background);
}

void MyFrame::cloneBackground(float *src, int srcwidth, int srcheight) {
  int rxi = 0, ryi = 0;

  for (int xi = 0; xi < srcwidth; xi++) {
    for (int yi = 0; yi < srcheight; yi++) {
      float value = src[(yi * srcwidth) + xi];
      background[(yi * width) + xi] = value;
      ryi++;
    }
    rxi++;
  }
}

void MyFrame::printFg() {
  qDebug() << "## Foreground";

  QString s = "";
  for (int xi = 0; xi < width; xi++) {
    for (int yi = 0; yi < height; yi++) {
      s += "[" + QString::number(getFgValueAt(xi, yi)) + "] ";
    }
    qDebug() << s;
    s = "";
  }

  qDebug() << "##";
}

void MyFrame::printBg() {
  qDebug() << "## Foreground";

  QString s = "";
  for (int xi = 0; xi < width; xi++) {
    for (int yi = 0; yi < height; yi++) {
      s += "[" + QString::number(getBgValueAt(xi, yi)) + "] ";
    }
    qDebug() << s;
    s = "";
  }

  qDebug() << "## Foreground";
}

float MyFrame::getValueAt(float *src, int srcwidth, int x, int y) {
  int index = (y * srcwidth) + x;
  return src[index];
}

float MyFrame::getFgValueAt(int x, int y) {
  return getValueAt(foreground, width, x, y);
}

float MyFrame::getBgValueAt(int x, int y) {
  return getValueAt(background, width, x, y);
}

void MyFrame::setValueAt(float *src, int srcwidth, int srcheight, float *canvas,
                         int canvaswidth, int x0, int y0) {
  int src_xi = 0;
  int src_yi = 0;

  for (int xi = x0; xi < srcwidth; xi++) {
    for (int yi = y0; yi < srcheight; yi++) {
      float value = getValueAt(src, srcwidth, src_xi++, src_yi);
      setValueAt(value, canvas, canvaswidth, xi, yi);
    }
    src_yi++;
  }
}
void MyFrame::setValueAt(float value, float *canvas, int canvaswidth, int x,
                         int y) {
  canvas[(y * canvaswidth) + x] = value;
}

int MyFrame::getWidth() { return width; }
int MyFrame::getHeight() { return height; }

float *MyFrame::getBackground() { return background; }
void MyFrame::setBackground(float *src, int srcwidth, int srcheight) {
  setValueAt(src, srcwidth, srcheight, background, width, 0, 0);
}

float *MyFrame::getForeground() { return foreground; }
void MyFrame::setForeground(float *src, int srcwidth, int srcheight) {
  setValueAt(src, srcwidth, srcheight, foreground, width, 0, 0);
}
