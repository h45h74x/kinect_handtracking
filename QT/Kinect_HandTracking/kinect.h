#ifndef KINECT_H
#define KINECT_H

#include "myframe.h"

#include <libfreenect2/config.h>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/logger.h>  // Optional
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/registration.h>  // Optional
#include <libfreenect2/libfreenect2.hpp>

class Kinect {
 public:
  int dev_state =
      -1;  // -1 = not initialized, 0 = closed, 1 = stopped, 2 = running

  Kinect();
  void init();

  ulong *getDepthData();

  void start();
  void stop();
  void close();
  void shutdown();

  MyFrame *getNextFrame();
  void nextFrame();

 private:
  MyFrame *myframe;

  int deviceId = -1;
  size_t framemax = -1;
  std::string serial = "";
  size_t framecount = 0;

  libfreenect2::Freenect2 freenect2;
  libfreenect2::Freenect2Device *dev = nullptr;
  libfreenect2::PacketPipeline *pipeline = nullptr;

  libfreenect2::FrameMap frames;
  libfreenect2::Frame *frame_ir;
  libfreenect2::Frame *frame_depth;
  libfreenect2::Registration *registration;
};

#endif  // KINECT_H
