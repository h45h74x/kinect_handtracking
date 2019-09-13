#ifndef MYFRAME_H
#define MYFRAME_H

#include <stdlib.h>

class MyFrame {
 public:
  MyFrame(int width, int height);
  MyFrame(float *kinectgrid, int width, int height);
  ~MyFrame();

  void cloneBackground(float *src, int srcwidth, int srcheight);

  int getWidth();
  int getHeight();

  float *getBackground();
  void setBackground(float *src, int srcwidth, int srcheight);

  float *getForeground();
  void setForeground(float *src, int srcwidth, int srcheight);

  float getValueAt(float *src, int srcwidth, int x, int y);

  float getFgValueAt(int x, int y);
  float getBgValueAt(int x, int y);

  void setValueAt(float *src, int srcwidth, int srcheight, float *canvas,
                  int canvaswidth, int x0, int y0);
  void setValueAt(float value, float *canvas, int canvaswidth, int x, int y);

  void printFg();
  void printBg();

 private:
  int width;
  int height;

  float *foreground;
  float *background;
};

#endif  // MYFRAME_H
