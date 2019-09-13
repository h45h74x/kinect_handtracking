#ifndef TRACKER_H
#define TRACKER_H

#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/logger.h>  // Optional
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/registration.h>  // Optional
#include <libfreenect2/libfreenect2.hpp>

#include "kinect.h"

class Tracker {
 public:
  Tracker();
  void init();
  void stop();
  void shutdown();
  void start();

  void trackhands();

  bool active();
  MyFrame* getFrame();

  Kinect kinect;
};

#endif  // TRACKER_H
