// Copyright 2022 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Camera.h"
#include "Renderer.h"
#include "World.h"
// helium
#include "helium/BaseFrame.h"
// std
#include <vector>

namespace cycles {

struct Frame : public helium::BaseFrame {
  Frame(CyclesGlobalState *s);
  ~Frame() override;

  bool isValid() const override;

  CyclesGlobalState *deviceState() const;

  bool getProperty(const std::string_view &name,
                   ANARIDataType type,
                   void *ptr,
                   uint32_t flags) override;

  void commit();

  void renderFrame() override;

  void *map(std::string_view channel,
            uint32_t *width,
            uint32_t *height,
            ANARIDataType *pixelType) override;
  void unmap(std::string_view channel) override;
  int frameReady(ANARIWaitMask m) override;
  void discard() override;

  bool ready() const;
  void wait() const;

 private:
  bool resetAccumulationNextFrame() const;
  bool shouldUpdateCyclesScene() const;

  friend struct FrameOutputDriver;

  //// Data ////

  bool m_valid{false};
  bool m_ready{true};
  int m_perPixelBytes{1};

  struct FrameData {
    uint2 size;
  } m_frameData;

  anari::DataType m_colorType{ANARI_UNKNOWN};
  anari::DataType m_depthType{ANARI_UNKNOWN};

  std::vector<uint8_t> m_pixelBuffer;
  std::vector<float> m_depthBuffer;

  helium::IntrusivePtr<Renderer> m_renderer;
  helium::IntrusivePtr<Camera> m_camera;
  helium::IntrusivePtr<World> m_world;

  float m_duration{0.f};

  bool m_frameChanged{false};
  helium::TimeStamp m_cameraLastChanged{0};
  helium::TimeStamp m_rendererLastChanged{0};
  helium::TimeStamp m_worldLastChanged{0};
  helium::TimeStamp m_lastCommitOccured{0};
};

}  // namespace cycles

CYCLES_ANARI_TYPEFOR_SPECIALIZATION(cycles::Frame *, ANARI_FRAME);
