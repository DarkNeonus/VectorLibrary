
#include<string>
#include <iostream>
#define _USE_MATH_DEFINES

#include<math.h>

using namespace std;

#include"Vector2.h"
#include"Vector3.h"


Vector3::Vector3() { x = 0; y = 0; }

Vector3::Vector3(float x) {
	this->x = x;
	this->y = x;
	this->z = x;
}
Vector3::Vector3(int x) : Vector3(float(x)) {}
Vector3::Vector3(double x) : Vector3(float(x)) {}

Vector3::Vector3(float x, float y) {
	this->x = x;
	this->y = y;
	this->z = 0;
}
Vector3::Vector3(int x, int y) : Vector3(float(x), float(y)) {}
Vector3::Vector3(int x, float y) : Vector3(float(x), y) {}
Vector3::Vector3(int x, double y) : Vector3(float(x), float(y)) {}
Vector3::Vector3(float x, int y) : Vector3(x, float(y)) {}
Vector3::Vector3(float x, double y) : Vector3(x, float(y)) {}
Vector3::Vector3(double x, int y) : Vector3(float(x), float(y)) {}
Vector3::Vector3(double x, float y) : Vector3(float(x), y) {}
Vector3::Vector3(double x, double y) : Vector3(float(x), float(y)) {}



Vector3::Vector3(Vector3Angle v) {
	this->x = v.X();
	this->y = v.Y();
	this->z = v.Z();
}
Vector3::Vector3(Vector2Angle v) {
	this->x = v.X();
	this->y = v.Y();
	this->z = 0;
}

Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);

Vector3 Vector3::right = Vector3(1.0f, 0.0f, 0.0f);
Vector3 Vector3::left = Vector3(-1.0f, 0.0f, 0.0f);
Vector3 Vector3::up = Vector3(0.0f, 1.0f, 0.0f);
Vector3 Vector3::down = Vector3(0.0f, -1.0f, 0.0f);
Vector3 Vector3::forward = Vector3(0.0f, 0.0f, 1.0f);
Vector3 Vector3::back = Vector3(0.0f, 0.0f, -1.0f);

Vector3 Vector3::left_down_back = Vector3(-1.0f, -1.0f, -1.0f);
Vector3 Vector3::left_down_center = Vector3(-1.0f, -1.0f, 0.0f);
Vector3 Vector3::left_down_forward = Vector3(-1.0f, -1.0f, 1.0f);
Vector3 Vector3::left_center_back = Vector3(-1.0f, 0.0f, -1.0f);
Vector3 Vector3::left_center_forward = Vector3(-1.0f, 0.0f, 1.0f);
Vector3 Vector3::left_up_back = Vector3(-1.0f, 1.0f, -1.0f);
Vector3 Vector3::left_up_center = Vector3(-1.0f, 1.0f, 0.0f);
Vector3 Vector3::left_up_forward = Vector3(-1.0f, 1.0f, 1.0f);

Vector3 Vector3::center_down_back = Vector3(0.0f, -1.0f, -1.0f);
Vector3 Vector3::center_down_forward = Vector3(0.0f, -1.0f, 1.0f);
Vector3 Vector3::center_up_back = Vector3(0.0f, 1.0f, -1.0f);
Vector3 Vector3::center_up_forward = Vector3(0.0f, 1.0f, 1.0f);

Vector3 Vector3::right_down_back = Vector3(1.0f, -1.0f, -1.0f);
Vector3 Vector3::right_down_center = Vector3(1.0f, -1.0f, 0.0f);
Vector3 Vector3::right_down_forward = Vector3(1.0f, -1.0f, 1.0f);
Vector3 Vector3::right_center_back = Vector3(1.0f, 0.0f, -1.0f);
Vector3 Vector3::right_center_forward = Vector3(1.0f, 0.0f, 1.0f);
Vector3 Vector3::right_up_back = Vector3(1.0f, 1.0f, -1.0f);
Vector3 Vector3::right_up_center = Vector3(1.0f, 1.0f, 0.0f);
Vector3 Vector3::right_up_forward = Vector3(1.0f, 1.0f, 1.0f);

Vector3 Vector3::fourDir[4] = { right, up, left, down };
Vector3 Vector3::eightDir[8] = { right, Vector3(1.0f, 1.0f, 0.0f), up, Vector3(-1.0f, 1.0f, 0.0f), left, Vector3(-1.0f, -1.0f, 0.0f), down, Vector3(1.0f, -1.0f, 0.0f) };
Vector3 Vector3::noralsDir[6] = { right, up, left, down, forward, back };
Vector3 Vector3::cubeDir[9] = { zero, right, Vector3(1.0f, 1.0f, 0.0f), up, Vector3(-1.0f, 1.0f, 0.0f), left, Vector3(-1.0f, -1.0f, 0.0f), down, Vector3(1.0f, -1.0f, 0.0f) };

float Vector3::Length() {
	return sqrt(x * x + y * y + z * z);
}

void Vector3::IncreaseLength(float a) {
	float len = Length();
	Vector3 ang = Angle();
	x = (len + a) * float(cos(DegToRad(ang.x)));
	y = (len + a) * float(cos(DegToRad(ang.y)));
	z = (len + a) * float(cos(DegToRad(ang.z)));
};
void Vector3::IncreaseLength(int a) { IncreaseLength(float(a)); };
void Vector3::IncreaseLength(double a) { IncreaseLength(float(a)); };

void Vector3::SetLength(float new_len) 
{ 
	IncreaseLength(new_len - Length()); 
};
void Vector3::SetLength(int new_len) { SetLength(float(new_len)); };
void Vector3::SetLength(double new_len) { SetLength(float(new_len)); };

void Vector3::MultiplyLength(float a) {
	x *= a;
	y *= a;
	z *= a;
};
void Vector3::MultiplyLength(int a) { MultiplyLength(float(a)); };
void Vector3::MultiplyLength(double a) { MultiplyLength(float(a)); };


string Vector3::ToString() { return to_string(x) + " " + to_string(y) + " " + to_string(z); }
string Vector3::ToString(bool is_marked) { return (is_marked ? "x: " : "") + to_string(x) + (is_marked ? " y: " : " ") + to_string(y) + (is_marked ? " z: " : " ") + to_string(z); }

void Vector3::Rotate(Vector3 angle) {
	Vector3 ang = Angle();
	float old_x = x;
	float old_y = y;
	float old_z = z;
	x = sqrt(old_x * old_x + old_y * old_y) * float(cos(DegToRad(ang.x + angle.x)));
	y = sqrt(old_y * old_y + old_z * old_z) * float(cos(DegToRad(ang.y + angle.y)));
	z = sqrt(old_z * old_z + old_x * old_x) * float(cos(DegToRad(ang.z + angle.z)));
}
void Vector3::Rotate(Vector2 angle) {
	Vector3 ang = Angle();
	float old_x = x;
	float old_y = y;
	x = sqrt(old_x * old_x + old_y * old_y) * float(cos(DegToRad(ang.x + angle.x)));
	y = sqrt(old_y * old_y + z * z) * float(cos(DegToRad(ang.y + angle.y)));
}

void Vector3::SetAngle(Vector3 angle) {
	Rotate(angle - Angle());
}
void Vector3::SetAngle(Vector2 angle) {
	Rotate(Vector3(angle) - Angle());
}

void Vector3::RotateAround(Vector3 v, Vector3 angle) {
	Vector3 rel_v = *this - v;
	rel_v.Rotate(angle);
	x = v.x + rel_v.x;
	y = v.y + rel_v.y;
	z = v.z + rel_v.z;
}
void Vector3::RotateAround(Vector2 v, Vector3 angle) {
	Vector3 rel_v = *this - v;
	rel_v.Rotate(angle);
	x = v.x + rel_v.x;
	y = v.y + rel_v.y;
	z = rel_v.z;
}
void Vector3::RotateAround(Vector3Angle v, Vector3 angle) { RotateAround(Vector3(v), angle); }
void Vector3::RotateAround(Vector2Angle v, Vector3 angle) { RotateAround(Vector3(v), angle); }
void Vector3::RotateAround(float v_x, float v_y, float v_z, Vector3 angle) {
	Vector3 rel_v = Vector3(x - v_x, y - v_y, z - v_z);
	rel_v.Rotate(v_x, v_y, v_z);
	x = v_x + rel_v.x;
	y = v_y + rel_v.y;
	z = v_z + rel_v.z;
}

Vector3 Vector3::UnitCircle(Vector3 angle) {
	return Vector3(cos(DegToRad(angle.x)), cos(DegToRad(angle.y)), cos(DegToRad(angle.z)));
}

Vector3 Vector3::Angle() {
	float len = Length();
	return Vector3(RadToDeg(acos(x / len)), RadToDeg(acos(y / len)), RadToDeg(acos(z / len)));
}

// Operators Init Start __________________________________________________________

#define operatorInit \
Vector3 Vector3::operator op (Vector3 v) { return Vector3(x op v.x, y op v.y, z op v.z); } \
Vector3 Vector3::operator op (Vector2 v) { return Vector3(x op v.x, y op v.y, z); } \
Vector3 Vector3::operator op (Vector3Angle v) { return Vector3(*this op v.Coordinates()); } \
Vector3 Vector3::operator op (Vector2Angle v) { return Vector3(*this op v.Coordinates()); } \
Vector3 Vector3::operator op (float a) { return Vector3(x op a, y op a, z op a); } \
Vector3 Vector3::operator op (int a) { return *this op float(a); } \
Vector3 Vector3::operator op (double a) { return *this op float(a); } \
\
void Vector3::operator op= (Vector3 v) { x op= v.x; y op= v.y; z op= v.z; } \
void Vector3::operator op= (Vector2 v) { x op= v.x; y op= v.y; } \
void Vector3::operator op= (Vector3Angle v) { x op= v.X(); y op= v.Y(); z op= v.Z(); } \
void Vector3::operator op= (Vector2Angle v) { x op= v.X(); y op= v.Y(); } \
void Vector3::operator op= (float a) { x op= a; y op= a; z op= a; } \
void Vector3::operator op= (int a) { *this op= float(a); } \
void Vector3::operator op= (double a) { *this op= float(a); }

#define op +
operatorInit;
#undef op
#define op -
operatorInit;
#undef op
#define op *
operatorInit;
#undef op
#define op /
operatorInit;
#undef op

#undef operatorInit


bool Vector3::operator== (Vector3 v) { return x == v.x && y == v.y && z == v.z; }
bool Vector3::operator== (Vector2 v) { return x == v.x && y == v.y && z == 0; }
bool Vector3::operator== (Vector3Angle v) { return x == v.X() && y == v.Y() && z == v.Z(); }
bool Vector3::operator== (Vector2Angle v) { return x == v.X() && y == v.Y() && z == 0; }
bool Vector3::operator== (float a) { return x == a && y == a; }
bool Vector3::operator== (int a) { return *this == float(a); }
bool Vector3::operator== (double a) { return *this == float(a); }

bool Vector3::operator!= (Vector3 v) { return x != v.x || y != v.y; }
bool Vector3::operator!= (Vector3Angle v) { return x != v.X() || y != v.Y(); }
bool Vector3::operator!= (float a) { return x != a || y != a; }
bool Vector3::operator!= (int a) { return *this != float(a); }
bool Vector3::operator!= (double a) { return *this != float(a); }


#define operatorInit \
bool Vector3::operator op (Vector3 v) { return x op v.x && y op v.y; } \
bool Vector3::operator op (Vector3Angle v) { return x op v.X() && y op v.Y(); } \
bool Vector3::operator op (float a) { return x op a && y op a; } \
bool Vector3::operator op (int a) { return *this op float(a); } \
bool Vector3::operator op (double a) { return *this op float(a); } \
\
bool Vector3::operator op= (Vector3 v) { return x op= v.x && y op= v.y; } \
bool Vector3::operator op= (Vector3Angle v) { return x op= v.X() && y op= v.Y(); } \
bool Vector3::operator op= (float a) { return x op= a && y op= a; } \
bool Vector3::operator op= (int a) { return *this op= float(a); } \
bool Vector3::operator op= (double a) { return *this op= float(a); } 


#define op <
operatorInit;
#undef op

#define op >
operatorInit;
#undef op

#undef operatorInit

void Vector3::operator++ (int a) { x++; y++; z++; }
void Vector3::operator-- (int a) { x--; y--; z--; }

// Operators Init End __________________________________________________________

Vector3 GetRotated(Vector3 v, Vector3 angle) { 
	Vector3 v_t = Vector3(v);
	v_t.Rotate(angle);
	return v_t; 
}
Vector3 GetRotated(Vector3 v, float angl_x, float angl_y, float angl_z) {
	Vector3 v_t = Vector3(v);
	v_t.Rotate(angl_x, angl_y, angl_z);
	return v_t;
}

Vector3 GetAngleVector3(Vector3 v) { return v.Angle(); }



