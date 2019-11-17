// Copyright (c) Tamas Csala

#ifndef OGLWRAP_ENUMS_COLOR_BUFFER_H_
#define OGLWRAP_ENUMS_COLOR_BUFFER_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class ColorBuffer : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  kNone = GL_NONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  kFrontLeft = GL_FRONT_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  kFrontRight = GL_FRONT_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  kBackLeft = GL_BACK_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  kBackRight = GL_BACK_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  kFront = GL_FRONT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  kBack = GL_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  kLeft = GL_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  kRight = GL_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  kFrontAndBack = GL_FRONT_AND_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  kColorAttachment0 = GL_COLOR_ATTACHMENT0,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  kColorAttachment1 = GL_COLOR_ATTACHMENT1,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  kColorAttachment2 = GL_COLOR_ATTACHMENT2,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  kColorAttachment3 = GL_COLOR_ATTACHMENT3,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  kColorAttachment4 = GL_COLOR_ATTACHMENT4,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  kColorAttachment5 = GL_COLOR_ATTACHMENT5,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  kColorAttachment6 = GL_COLOR_ATTACHMENT6,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  kColorAttachment7 = GL_COLOR_ATTACHMENT7,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  kColorAttachment8 = GL_COLOR_ATTACHMENT8,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  kColorAttachment9 = GL_COLOR_ATTACHMENT9,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  kColorAttachment10 = GL_COLOR_ATTACHMENT10,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  kColorAttachment11 = GL_COLOR_ATTACHMENT11,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  kColorAttachment12 = GL_COLOR_ATTACHMENT12,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  kColorAttachment13 = GL_COLOR_ATTACHMENT13,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  kColorAttachment14 = GL_COLOR_ATTACHMENT14,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  kColorAttachment15 = GL_COLOR_ATTACHMENT15,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
