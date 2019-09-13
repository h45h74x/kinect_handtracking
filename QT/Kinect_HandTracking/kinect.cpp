/*
 * API Reference:
 * https://openkinect.github.io/libfreenect2/
 */

#include "kinect.h"
#include "myframe.h"

#include <libfreenect2/config.h>
#include <libfreenect2/packet_pipeline.h>
#include <QDebug>

libfreenect2::Frame undistorted(512, 424, 4), registered(512, 424, 4);

libfreenect2::SyncMultiFrameListener listener(libfreenect2::Frame::Ir |
                                              libfreenect2::Frame::Depth);
// App Vars

void Kinect::start() {
  if (dev_state == 0) {
    dev_state = 2;
    dev->start();
  }
}
void Kinect::stop() {
  if (dev_state == 2) {
    dev_state = 1;
    dev->stop();
  }
}
void Kinect::close() {
  if (dev_state >= 0) {
    dev_state = 0;
    dev->close();
  }
}
void Kinect::shutdown() {
  if (dev_state == 2) {
    dev_state = 0;
  } else {
    stop();
    close();
  }
}

Kinect::Kinect() {}

void Kinect::init() {
  if (dev && dev_state > 0) {
    dev->stop();
    dev->close();
  }

  // Get Kinect Devices
  int i = freenect2.enumerateDevices();
  if (i == 0) {
    return;
  }
  serial = freenect2.getDefaultDeviceSerialNumber();

  pipeline = new libfreenect2::OpenGLPacketPipeline;
  dev = freenect2.openDevice(serial, pipeline);

  // Set up Frame Listeners
  dev->setIrAndDepthFrameListener(&listener);

  // Start Frame Streams
  if (!dev->startStreams(false, true)) {
    return;
  }

  registration = new libfreenect2::Registration(dev->getIrCameraParams(),
                                                dev->getColorCameraParams());

  qDebug() << "device serial: "
           << QString::fromStdString(dev->getFirmwareVersion());
  qDebug() << "device firmware: "
           << QString::fromStdString(dev->getFirmwareVersion());

  dev_state = 0;
}

MyFrame *Kinect::getNextFrame() {
  nextFrame();
  return myframe;
}

void Kinect::nextFrame() {
  if (!listener.waitForNewFrame(frames, 10 * 1000))  // 10 seconds
  {
    qDebug() << "Timeout!";
  }

  frame_depth = frames[libfreenect2::Frame::Depth];
  float *frame_data = (float *)frame_depth->data;

  if (frame_data) {
    int x = 0;
    int y = 900;

    for (int i = 0; i < x; i++) {
      float value = frame_data[x * frame_depth->width + y];
    }

    if (!myframe) {
      myframe = new MyFrame(frame_depth->width, frame_depth->height);
    }

    myframe->cloneBackground(frame_data, frame_depth->width,
                             frame_depth->height);
  }

  listener.release(frames);
}
