#include"Vector2Angle.h"



Vector2Angle::Vector2Angle() { length = 0; angle = 0; }

Vector2Angle::Vector2Angle(float length) {
	if (length < 0) { throw exception("Length of vector cant be less than zero"); }
	this->length = length; this->angle = 0;
}
Vector2Angle::Vector2Angle(int length) : Vector2Angle(float(length)) {}
Vector2Angle::Vector2Angle(double length) : Vector2Angle(float(length)) {}

Vector2Angle::Vector2Angle(float length, float angle) {
	if (length < 0) { throw exception("Length of vector cant be less than zero"); }
	this->length = length;
	this->angle = angle;
}
Vector2Angle::Vector2Angle(int length, int angle) : Vector2Angle(float(length), float(angle)) {}
Vector2Angle::Vector2Angle(int length, float angle) : Vector2Angle(float(length), angle) {}
Vector2Angle::Vector2Angle(int length, double angle) : Vector2Angle(float(length), float(angle)) {}
Vector2Angle::Vector2Angle(float length, int angle) : Vector2Angle(length, float(angle)) {}
Vector2Angle::Vector2Angle(float length, double angle) : Vector2Angle(length, float(angle)) {}
Vector2Angle::Vector2Angle(double length, int angle) : Vector2Angle(float(length), float(angle)) {}
Vector2Angle::Vector2Angle(double length, float angle) : Vector2Angle(float(length), angle) {}
Vector2Angle::Vector2Angle(double length, double angle) : Vector2Angle(float(length), float(angle)) {}

Vector2Angle::Vector2Angle(Vector2 v) {
	this->length = v.Length();
	this->angle = v.Angle();
}

Vector2Angle Vector2Angle::zero = Vector2Angle(0.0f, 0.0f);

Vector2Angle Vector2Angle::right = Vector2Angle(1.0f, 0.0f);
Vector2Angle Vector2Angle::left = Vector2Angle(1.0f, 180.0f);
Vector2Angle Vector2Angle::up = Vector2Angle(1.0f, 90.0f);
Vector2Angle Vector2Angle::down = Vector2Angle(1.0f, 270.0f);

Vector2Angle Vector2Angle::right_up = Vector2Angle(1.0f, 45.0f);
Vector2Angle Vector2Angle::right_down = Vector2Angle(1.0f, 315.0f);
Vector2Angle Vector2Angle::left_up = Vector2Angle(1.0f, 135.0f);
Vector2Angle Vector2Angle::left_down = Vector2Angle(1.0f, 225.0f);

Vector2Angle Vector2Angle::fourDir[4] = { right, up, left, down };
Vector2Angle Vector2Angle::eightDir[8] = { right, right_up, up, left_up, left, left_down, down, right_down };
Vector2Angle Vector2Angle::rectDir[9] = { zero, right, right_up, up, left_up, left, left_down, down, right_down };

Vector2 Vector2Angle::Coordinates() {
		if (abs(round(angle) - angle) < 0.001) {
			switch ((int)round(angle) % 360)
			{
			case (0):
				return Vector2(length, 0);
				break;

			case -270:
			case 90:
				return Vector2(0, length);
				break;

			case 180:
			case -180:
				return Vector2(-length, 0);
				break;

			case -90:
			case 270:
				return Vector2(0, -length);
				break;

			default:
				return Vector2(length * cos(DegToRad(angle)), length * sin(DegToRad(angle)));
				break;
			}
		}
		else {
			return Vector2(length * cos(DegToRad(angle)), length * sin(DegToRad(angle)));
		}
		return Vector2(0, 0);
	}
float Vector2Angle::X() {
		if (abs(round(angle) - angle) < 0.001) {
			switch ((int)round(angle) % 360)
			{
			case (0):
				return length;
				break;
			case -90:
			case 270:
			case -270:
			case 90:
				return 0;
				break;

			case 180:
			case -180:
				return -length;
				break;

			default:
				return length * float(cos(DegToRad(angle)));
				break;
			}
		}
		else {
			return length * float(cos(DegToRad(angle)));
		}
		return 0;
	}
float Vector2Angle::Y() {
		if (abs(round(angle) - angle) < 0.001) {
			switch ((int)round(angle) % 360)
			{
			case (0):
			case 180:
			case -180:
				return 0;
				break;

			case -270:
			case 90:
				return length;
				break;

			case -90:
			case 270:
				return -length;
				break;

			default:
				return length * float(sin(DegToRad(angle)));
				break;
			}
		}
		else {
			return length * float(sin(DegToRad(angle)));
		}
		return 0;
	}

string Vector2Angle::ToString() {
	return to_string(length) + " " + to_string(angle);
}
string Vector2Angle::ToString(bool is_marked) {
	return (is_marked ? "length: " : "") + to_string(length) + (is_marked ? " angle: " : " ") + to_string(angle);
}

void Vector2Angle::RotateAround(Vector2Angle v, double angle) {
	Vector2Angle diff = *this - v;
	diff.angle += float(angle);
	*this = v + diff;
}
void Vector2Angle::RotateAround(Vector2 v, double angle) { RotateAround(Vector2Angle(v), angle); }
void Vector2Angle::RotateAround(float v_x, float v_y, double angle) { RotateAround(Vector2(v_x, v_y), angle); }
void Vector2Angle::RotateAround(int v_x, int v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2Angle::RotateAround(int v_x, float v_y, double angle) { RotateAround(float(v_x), v_y, angle); }
void Vector2Angle::RotateAround(int v_x, double v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2Angle::RotateAround(float v_x, int v_y, double angle) { RotateAround(v_x, float(v_y), angle); }
void Vector2Angle::RotateAround(float v_x, double v_y, double angle) { RotateAround(v_x, float(v_y), angle); }
void Vector2Angle::RotateAround(double v_x, int v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }
void Vector2Angle::RotateAround(double v_x, float v_y, double angle) { RotateAround(float(v_x), v_y, angle); }
void Vector2Angle::RotateAround(double v_x, double v_y, double angle) { RotateAround(float(v_x), float(v_y), angle); }

Vector2Angle Vector2Angle::operator+ (Vector2Angle v) { return Vector2Angle(this->Coordinates() + v.Coordinates()); }
Vector2Angle Vector2Angle::operator+ (Vector2 v) { return Vector2Angle(this->Coordinates() + v); }
Vector2Angle Vector2Angle::operator+ (float a) { return Vector2Angle(length + a, angle); }
Vector2Angle Vector2Angle::operator+ (int a) { return *this + float(a); }
Vector2Angle Vector2Angle::operator+ (double a) { return *this + float(a); }

Vector2Angle Vector2Angle::operator- (Vector2Angle v) { return Vector2Angle(this->Coordinates() - v.Coordinates()); }
Vector2Angle Vector2Angle::operator- (Vector2 v) { return Vector2Angle(this->Coordinates() - v); }
Vector2Angle Vector2Angle::operator- (float a) { return Vector2Angle(length - a, angle); }
Vector2Angle Vector2Angle::operator- (int a) { return *this - float(a); }
Vector2Angle Vector2Angle::operator- (double a) { return *this - float(a); }

Vector2Angle Vector2Angle::operator* (Vector2Angle v) { return Vector2Angle(this->Coordinates() * v.Coordinates()); }
Vector2Angle Vector2Angle::operator* (Vector2 v) { return Vector2Angle(this->Coordinates() * v); }
Vector2Angle Vector2Angle::operator* (float a) { return Vector2Angle(length + a, angle); }
Vector2Angle Vector2Angle::operator* (int a) { return *this * float(a); }
Vector2Angle Vector2Angle::operator* (double a) { return *this * float(a); }

Vector2Angle Vector2Angle::operator/ (Vector2Angle v) { return Vector2Angle(this->Coordinates() / v.Coordinates()); }
Vector2Angle Vector2Angle::operator/ (Vector2 v) { return Vector2Angle(this->Coordinates() / v); }
Vector2Angle Vector2Angle::operator/ (float a) { return Vector2Angle(length + a, angle); }
Vector2Angle Vector2Angle::operator/ (int a) { return *this / float(a); }
Vector2Angle Vector2Angle::operator/ (double a) { return *this / float(a); }


void Vector2Angle::operator+= (Vector2Angle v) { length += v.length; angle = (*this + v).angle; }
void Vector2Angle::operator+= (Vector2 v) { length += v.Length(); angle = (*this + Vector2Angle(v)).angle;; }
void Vector2Angle::operator+= (float a) { length += a; }
void Vector2Angle::operator+= (int a) { *this += float(a); }
void Vector2Angle::operator+= (double a) { *this += float(a); }

void Vector2Angle::operator-= (Vector2Angle v) { length -= v.length; angle = (*this - v).angle; }
void Vector2Angle::operator-= (Vector2 v) { length -= v.Length(); angle = (*this - Vector2Angle(v)).angle;; }
void Vector2Angle::operator-= (float a) { length -= a; }
void Vector2Angle::operator-= (int a) { *this -= float(a); }
void Vector2Angle::operator-= (double a) { *this -= float(a); }

void Vector2Angle::operator*= (Vector2Angle v) { length *= v.length; angle = (*this * v).angle; }
void Vector2Angle::operator*= (Vector2 v) { length *= v.Length(); angle = (*this * Vector2Angle(v)).angle;; }
void Vector2Angle::operator*= (float a) { length *= a; }
void Vector2Angle::operator*= (int a) { *this *= float(a); }
void Vector2Angle::operator*= (double a) { *this *= float(a); }

void Vector2Angle::operator/= (Vector2Angle v) { length /= v.length; angle = (*this / v).angle; }
void Vector2Angle::operator/= (Vector2 v) { length /= v.Length(); angle = (*this / Vector2Angle(v)).angle;; }
void Vector2Angle::operator/= (float a) { length /= a; }
void Vector2Angle::operator/= (int a) { *this /= float(a); }
void Vector2Angle::operator/= (double a) { *this /= float(a); }



bool Vector2Angle::operator== (Vector2Angle v) { return length == v.length && angle == v.angle; }
bool Vector2Angle::operator== (Vector2 v) { return length == v.Length() && angle == v.Angle(); }
bool Vector2Angle::operator== (float a) { return X() == a && Y() == a; }
bool Vector2Angle::operator== (int a) { return *this == float(a); }
bool Vector2Angle::operator== (double a) { return *this == float(a); }

bool Vector2Angle::operator!= (Vector2Angle v) { return length != v.length || angle != v.angle; }
bool Vector2Angle::operator!= (Vector2 v) { return length != v.Length() || angle != v.Angle(); }
bool Vector2Angle::operator!= (float a) { return X() != a || Y() != a; }
bool Vector2Angle::operator!= (int a) { return *this != float(a); }
bool Vector2Angle::operator!= (double a) { return *this != float(a); }


bool Vector2Angle::operator> (Vector2Angle v) { return this->Coordinates() > v.Coordinates(); }
bool Vector2Angle::operator> (Vector2 v) { return this->Coordinates() > v; }
bool Vector2Angle::operator> (float a) { return X() > a && Y() > a; }
bool Vector2Angle::operator> (int a) { return *this > float(a); }
bool Vector2Angle::operator> (double a) { return *this > float(a); }

bool Vector2Angle::operator< (Vector2Angle v) { return this->Coordinates() < v.Coordinates(); }
bool Vector2Angle::operator< (Vector2 v) { return this->Coordinates() < v; }
bool Vector2Angle::operator< (float a) { return X() < a && Y() < a; }
bool Vector2Angle::operator< (int a) { return *this < float(a); }
bool Vector2Angle::operator< (double a) { return *this < float(a); }

bool Vector2Angle::operator>= (Vector2Angle v) { return this->Coordinates() >= v.Coordinates(); }
bool Vector2Angle::operator>= (Vector2 v) { return this->Coordinates() >= v; }
bool Vector2Angle::operator>= (float a) { return X() >= a && Y() >= a; }
bool Vector2Angle::operator>= (int a) { return *this >= float(a); }
bool Vector2Angle::operator>= (double a) { return *this >= float(a); }

bool Vector2Angle::operator<= (Vector2Angle v) { return this->Coordinates() <= v.Coordinates(); }
bool Vector2Angle::operator<= (Vector2 v) { return this->Coordinates() <= v; }
bool Vector2Angle::operator<= (float a) { return X() <= a && Y() <= a; }
bool Vector2Angle::operator<= (int a) { return *this <= float(a); }
bool Vector2Angle::operator<= (double a) { return *this <= float(a); }

void Vector2Angle::operator++ (int a) { length++; }
void Vector2Angle::operator-- (int a) { length--; }

Vector2Angle GetRotated(Vector2Angle v, float angle) { return Vector2Angle(v.length, v.angle + angle); }
Vector2Angle GetRotated(Vector2Angle v, int angle) { return GetRotated(v, float(angle)); }
Vector2Angle GetRotated(Vector2Angle v, double angle) { return GetRotated(v, float(angle)); }