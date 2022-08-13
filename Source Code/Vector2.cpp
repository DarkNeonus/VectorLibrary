
#include<string>
#include <iostream>
#define _USE_MATH_DEFINES

#include<math.h>

using namespace std;

#include"Vector2.h"


Vector2::Vector2() { x = 0; y = 0; }

Vector2::Vector2(float x) {
	this->x = x;
	this->y = x;
}
Vector2::Vector2(int x) : Vector2(float(x)) {}
Vector2::Vector2(double x) : Vector2(float(x)) {}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}
Vector2::Vector2(int x, int y) : Vector2(float(x), float(y)) {}
Vector2::Vector2(int x, float y) : Vector2(float(x), y) {}
Vector2::Vector2(int x, double y) : Vector2(float(x), float(y)) {}
Vector2::Vector2(float x, int y) : Vector2(x, float(y)) {}
Vector2::Vector2(float x, double y) : Vector2(x, float(y)) {}
Vector2::Vector2(double x, int y) : Vector2(float(x), float(y)) {}
Vector2::Vector2(double x, float y) : Vector2(float(x), y) {}
Vector2::Vector2(double x, double y) : Vector2(float(x), float(y)) {}

Vector2::Vector2(Vector2Angle v) {
	this->x = v.Coordinates().x;
	this->y = v.Coordinates().y;
}

Vector2 Vector2::zero = Vector2(0.0f, 0.0f);

Vector2 Vector2::right = Vector2(1.0f, 0.0f);
Vector2 Vector2::left = Vector2(-1.0f, 0.0f);
Vector2 Vector2::up = Vector2(0.0f, 1.0f);
Vector2 Vector2::down = Vector2(0.0f, -1.0f);

Vector2 Vector2::right_up = Vector2(1.0f, 1.0f);
Vector2 Vector2::right_down = Vector2(1.0f, -1.0f);
Vector2 Vector2::left_up = Vector2(-1.0f, 1.0f);
Vector2 Vector2::left_down = Vector2(-1.0f, -1.0f);

Vector2 Vector2::fourDir[4] = { right, up, left, down };
Vector2 Vector2::eightDir[8] = { right, right_up, up, left_up, left, left_down, down, right_down };
Vector2 Vector2::rectDir[9] = { zero, right, right_up, up, left_up, left, left_down, down, right_down };

float Vector2::Length() {
	return sqrt(x * x + y * y);
}

void Vector2::IncreaseLength(float a) {
	float len = Length();
	float ang = Angle();
	x = (len + a) * float(cos(DegToRad(ang)));
	y = (len + a) * float(sin(DegToRad(ang)));
};
void Vector2::IncreaseLength(int a) { IncreaseLength(float(a)); };
void Vector2::IncreaseLength(double a) { IncreaseLength(float(a)); };

void Vector2::SetLength(float new_len) 
{ 
	IncreaseLength(new_len - Length()); 
};
void Vector2::SetLength(int new_len) { SetLength(float(new_len)); };
void Vector2::SetLength(double new_len) { SetLength(float(new_len)); };

void Vector2::MultiplyLength(float a) {
	x *= a;
	y *= a;
};
void Vector2::MultiplyLength(int a) { MultiplyLength(float(a)); };
void Vector2::MultiplyLength(double a) { MultiplyLength(float(a)); };


string Vector2::ToString() { return to_string(x) + " " + to_string(y); }
string Vector2::ToString(bool is_marked) { return (is_marked ? "x: " : "") + to_string(x) + (is_marked ? " y: " : " ") + to_string(y); }

void Vector2::Rotate(float angle) {
	float old_x = x;
	float old_y = y;
	double angl = DegToRad(angle);
	x = old_x * float(cos(angl)) - old_y * float(sin(angl));
	y = old_x * float(sin(angl)) + old_y * float(cos(angl));
}
void Vector2::Rotate(int angle) { Rotate(float(angle)); }
void Vector2::Rotate(double angle) { Rotate(float(angle)); }

void Vector2::SetAngle(float angle) {
	Rotate(angle - Angle());
}
void Vector2::SetAngle(int angle) { SetAngle(float(angle)); }
void Vector2::SetAngle(double angle) { SetAngle(float(angle)); }

void Vector2::RotateAround(Vector2 v, double angle) {
	double angl = DegToRad(angle);
	float x_t = x;
	float y_t = y;
	x = float(cos(angl)) * (x_t - v.x) - float(sin(angl)) * (y_t - v.y) + v.x;
	y = float(sin(angl)) * (x_t - v.x) + float(cos(angl)) * (y_t - v.y) + v.y;
}
void Vector2::RotateAround(Vector2Angle v, double angle) {
	double angl = DegToRad(angle);
	float x_t = x;
	float y_t = y;
	x = float(cos(angl)) * (x_t - v.X()) - float(sin(angl)) * (y_t - v.Y()) + v.X();
	y = float(sin(angl)) * (x_t - v.X()) + float(cos(angl)) * (y_t - v.Y()) + v.Y();
}
void Vector2::RotateAround(float v_x, float v_y, double angle) {
	double angl = DegToRad(angle);
	float x_t = x;
	float y_t = y;
	x = float(cos(angl)) * (x_t - v_x) - float(sin(angl)) * (y_t - v_y) + v_x;
	y = float(sin(angl)) * (x_t - v_x) + float(cos(angl)) * (y_t - v_y) + v_y;
}
void Vector2::RotateAround(int v_x, int v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2::RotateAround(int v_x, float v_y, double angle) { RotateAround(float(v_x), v_y, angle); }
void Vector2::RotateAround(int v_x, double v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2::RotateAround(float v_x, int v_y, double angle) { RotateAround(v_x, float(v_y), angle); }
void Vector2::RotateAround(float v_x, double v_y, double angle) { RotateAround(v_x, float(v_y), angle); }
void Vector2::RotateAround(double v_x, int v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2::RotateAround(double v_x, float v_y, double angle) { RotateAround(float(v_x), v_y, angle); }
void Vector2::RotateAround(double v_x, double v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }

Vector2 Vector2::UnitCircle(double angle) {
	return Vector2(cos(DegToRad(angle)), sin(DegToRad(angle)));
}

float Vector2::Angle() {
	return round(RadToDeg(atan2(y, x)) * 10000) / 10000;
}

Vector2 Vector2::operator+ (Vector2 v) { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator+ (Vector2Angle v) { return Vector2(*this + v.Coordinates()); }
Vector2 Vector2::operator+ (float a) { return Vector2(x + a, y + a); }
Vector2 Vector2::operator+ (int a) { return *this + float(a); }
Vector2 Vector2::operator+ (double a) { return *this + float(a); }

Vector2 Vector2::operator- (Vector2 v) { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator- (Vector2Angle v) { return Vector2(*this - v.Coordinates()); }
Vector2 Vector2::operator- (float a) { return Vector2(x - a, y - a); }
Vector2 Vector2::operator- (int a) { return *this - float(a); }
Vector2 Vector2::operator- (double a) { return *this - float(a); }

Vector2 Vector2::operator* (Vector2 v) { return Vector2(x * v.x, y * v.y); }
Vector2 Vector2::operator* (Vector2Angle v) { return Vector2(*this * v.Coordinates()); }
Vector2 Vector2::operator* (float a) { return Vector2(x * a, y * a); }
Vector2 Vector2::operator* (int a) { return *this * float(a); }
Vector2 Vector2::operator* (double a) { return *this * float(a); }

Vector2 Vector2::operator/ (Vector2 v) { return Vector2(x / v.x, y / v.y); }
Vector2 Vector2::operator/ (Vector2Angle v) { return Vector2(*this / v.Coordinates()); }
Vector2 Vector2::operator/ (float a) { return Vector2(x / a, y / a); }
Vector2 Vector2::operator/ (int a) { return *this / float(a); }
Vector2 Vector2::operator/ (double a) { return *this / float(a); }


void Vector2::operator+= (Vector2 v) { x += v.x; y += v.y; }
void Vector2::operator+= (Vector2Angle v) { x += v.X(); y += v.Y(); }
void Vector2::operator+= (float a) { x += a; y += a; }
void Vector2::operator+= (int a) { *this += float(a); }
void Vector2::operator+= (double a) { *this += float(a); }

void Vector2::operator-= (Vector2 v) { x -= v.x; y -= v.y; }
void Vector2::operator-= (Vector2Angle v) { x -= v.X(); y -= v.Y(); }
void Vector2::operator-= (float a) { x -= a; y -= a; }
void Vector2::operator-= (int a) { *this -= float(a); }
void Vector2::operator-= (double a) { *this -= float(a); }

void Vector2::operator*= (Vector2 v) { x *= v.x; y *= v.y; }
void Vector2::operator*= (Vector2Angle v) { x *= v.X(); y *= v.Y(); }
void Vector2::operator*= (float a) { x *= a; y *= a; }
void Vector2::operator*= (int a) { *this *= float(a); }
void Vector2::operator*= (double a) { *this *= float(a); }

void Vector2::operator/= (Vector2 v) { x /= v.x; y /= v.y; }
void Vector2::operator/= (Vector2Angle v) { x /= v.X(); y /= v.Y(); }
void Vector2::operator/= (float a) { x /= a; y /= a; }
void Vector2::operator/= (int a) { *this /= float(a); }
void Vector2::operator/= (double a) { *this /= float(a); }

bool Vector2::operator== (Vector2 v) { return x == v.x && y == v.y; }
bool Vector2::operator== (Vector2Angle v) { return x == v.X() && y == v.Y(); }
bool Vector2::operator== (float a) { return x == a && y == a; }
bool Vector2::operator== (int a) { return *this == float(a); }
bool Vector2::operator== (double a) { return *this == float(a); }

bool Vector2::operator!= (Vector2 v) { return x != v.x || y != v.y; }
bool Vector2::operator!= (Vector2Angle v) { return x != v.X() || y != v.Y(); }
bool Vector2::operator!= (float a) { return x != a || y != a; }
bool Vector2::operator!= (int a) { return *this != float(a); }
bool Vector2::operator!= (double a) { return *this != float(a); }


bool Vector2::operator> (Vector2 v) { return x > v.x && y > v.y; }
bool Vector2::operator> (Vector2Angle v) { return x > v.X() && y > v.Y(); }
bool Vector2::operator> (float a) { return x > a && y > a; }
bool Vector2::operator> (int a) { return *this > float(a); }
bool Vector2::operator> (double a) { return *this > float(a); }

bool Vector2::operator< (Vector2 v) { return x < v.x&& y < v.y; }
bool Vector2::operator< (Vector2Angle v) { return x < v.X() && y < v.Y(); }
bool Vector2::operator< (float a) { return x < a&& y < a; }
bool Vector2::operator< (int a) { return *this < float(a); }
bool Vector2::operator< (double a) { return *this < float(a); }

bool Vector2::operator>= (Vector2 v) { return x >= v.x && y >= v.y; }
bool Vector2::operator>= (Vector2Angle v) { return x >= v.X() && y >= v.Y(); }
bool Vector2::operator>= (float a) { return x >= a && y >= a; }
bool Vector2::operator>= (int a) { return *this >= float(a); }
bool Vector2::operator>= (double a) { return *this >= float(a); }

bool Vector2::operator<= (Vector2 v) { return x <= v.x && y <= v.y; }
bool Vector2::operator<= (Vector2Angle v) { return x <= v.X() && y <= v.Y(); }
bool Vector2::operator<= (float a) { return x <= a && y <= a; }
bool Vector2::operator<= (int a) { return *this <= float(a); }
bool Vector2::operator<= (double a) { return *this <= float(a); }

void Vector2::operator++ (int a) { x++; y++; }
void Vector2::operator-- (int a) { x--; y--; }


double DegToRad(float deg) { 
	return 2 * M_PI * double(deg) / 360.0; 
}
double DegToRad(int deg) { return DegToRad(float(deg)); }
double DegToRad(double deg) { return DegToRad(float(deg)); }

float RadToDeg(float rad) { 
	return float(rad * 180.0f / M_PI);
}
float RadToDeg(int rad) { return RadToDeg(float(rad)); }
float RadToDeg(double rad) { return RadToDeg(float(rad)); }

Vector2 GetRotated(Vector2 v, float angle) { 
	double r_t = DegToRad(angle);
	return Vector2(v.x * cos(r_t) - v.y * sin(r_t), v.x * sin(r_t) + v.y * cos(r_t));
}
Vector2 GetRotated(Vector2 v, int angle) { return GetRotated(v, float(angle)); }
Vector2 GetRotated(Vector2 v, double angle) { return GetRotated(v, float(angle)); }


// double AngleForTrigonometric(float angle) { 
// 	return DegToRad(90.0f - angle);
// }
// double AngleForTrigonometric(int angle) { return AngleForTrigonometric(float(angle)); }
// double AngleForTrigonometric(double angle) { return AngleForTrigonometric(float(angle));}

float GetAngleVector2(Vector2 v) { return v.Angle(); }



