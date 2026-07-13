#include <cmath>
#include "formulas.hpp"

float time_of_the_flight(float v0, float angle) {
    return (2 * v0 * sin(angle)) / 9.81f;
}

float max_height(float v0, float angle) {
    return (v0 * v0 * sin(angle) * sin(angle)) / (2 * 9.81f);
}

float distance_of_the_flight(float v0, float angle) {
    return (v0 * v0 * sin(2 * angle)) / 9.81f;
}

float v_diff(float v0, float t) {
    return v0 + 9.81f * t;
}

float x_diff(float x0, float v0, float a, float t) {
    return x0 + v0 * t + a * t * t / 2;
}

float horizontal_speed(float v0, float angle) {
    return v0 * cos(angle);
}

float vertical_speed(float v0, float angle, float t) {
    return v0 * sin(angle) - 9.81f * t;
}

float acceleration_up(float F, float m) {
    return F / m - 9.81f;
}

float v_up(float v0, float a, float t) {
    return v0 + a * t;
}

float h_up(float h0, float a, float t) {
    return h0 - a * t * t / 2;
}

float acceleration_down(float F, float m) {
    return -9.81f;
}

float v_down(float v, float a, float t) {
    return v - 9.81f * t;
}
 
float h_down(float h, float v, float t) {
    return h - v * t - 9.81f * t * t / 2;
}