#include <iostream>
#include "camera.h"
#include "vector.h"
#include "point.h"

using namespace std;

void Camera::setPosition(Point position) {
    m_position = position;
}

void Camera::setDirection(Vector direction) {
    m_direction = direction;
}

void Camera::setSize(int width, int height) {
    m_width = width;
    m_height = height;
}

void Camera::setAngle(double angle) {
    m_angle = angle;
}

void Camera::printCamera() {
    cout << "Camera de position";
    m_position.printPoint();
    cout << " de taille " << m_width << "x" << m_height << endl;
}