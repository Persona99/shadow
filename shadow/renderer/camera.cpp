#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Shadow {


Camera::Camera(float left, float right, float bottom, float top)
    : mProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),
      mViewMatrix(1.0f),
      mPosition(0.0f)
{
    mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
}

void Camera::SetProjection(float left, float right, float bottom, float top) {
    mProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
    Recalculate();
}

void Camera::Recalculate() {
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), mPosition) *
                          glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), glm::vec3(0, 0, 1));

    mViewMatrix = glm::inverse(transform);
    mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
}
}