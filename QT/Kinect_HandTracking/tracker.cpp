#include "tracker.h"
#include "kinect.h"

Tracker::Tracker() {}

bool initialized = false;

void Tracker::init() {
  if (!initialized) {
    kinect.init();
    initialized = true;
  }
}

bool Tracker::active() { return initialized && kinect.dev_state == 2; }

void Tracker::stop() { kinect.stop(); }

void Tracker::shutdown() {
  initialized = false;
  kinect.shutdown();
}

void Tracker::start() {
  init();

  kinect.start();
  // kinect.startFrameLoop();
}

MyFrame* Tracker::getFrame() {
  if (active())
    return kinect.getNextFrame();
  else
    return nullptr;
}

void Tracker::trackhands() {}
