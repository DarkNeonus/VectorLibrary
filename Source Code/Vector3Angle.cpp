#include"Vector2Angle.h"
#include"Vector3Angle.h"



Vector3Angle::Vector3Angle() { length = 0; set_angle(0); }

Vector3Angle::Vector3Angle(float length) {
	if (length < 0) { throw exception("Length of vector cant be less than zero"); }
	this->length = length; set_angle(0);
}
Vector3Angle::Vector3Angle(int length) : Vector3Angle(float(length)) {}
Vector3Angle::Vector3Angle(double length) : Vector3Angle(float(length)) {}

Vector3Angle::Vector3Angle(float length, Vector3 angle) {
	if (length < 0) { throw exception("Length of vector cant be less than zero"); }
	this->length = length;
	set_angle(angle);
}
Vector3Angle::Vector3Angle(float length, float angl_x, float angl_y, float angl_z) {
	if (length < 0) { throw exception("Length of vector cant be less than zero"); }
	this->length = length;
	angle_x = angl_x;
	angle_y = angl_y;
	angle_z = angl_z;
}

Vector3Angle::Vector3Angle(int length, Vector3 angle) : Vector3Angle(float(length), angle) {};
Vector3Angle::Vector3Angle(double length, Vector3 angle) : Vector3Angle(float(length), angle) {};
Vector3Angle::Vector3Angle(Vector2 v) {
	length = v.Length();
	angle_x = v.Angle();
	angle_y = 0;
	angle_z = 0;
}
Vector3Angle::Vector3Angle(Vector2 v, float z) : Vector3Angle(Vector3(v.x, v.y, z)) {}
Vector3Angle::Vector3Angle(Vector2Angle v) {
	length = v.length;
	angle_x = v.angle;
	angle_y = 0;
	angle_z = 0;
}
Vector3Angle::Vector3Angle(Vector2Angle v, float angl_y) {
	length = v.length;
	angle_x = v.angle;
	angle_y = angl_y;
	angle_z = 0;
}


Vector3Angle::Vector3Angle(Vector3 v) {
	this->length = v.Length();
	set_angle(v.Angle());
}

Vector3 Vector3Angle::angle() { return Vector3(angle_x, angle_y, angle_z); }
void Vector3Angle::set_angle(Vector3 v) { angle_x = v.x; angle_y = v.y; angle_z = v.z; }

Vector3Angle Vector3Angle::zero = Vector3Angle(0.0f, Vector3::zero);

Vector3Angle Vector3Angle::right = Vector3Angle(1.0f, Vector3(0.0f, 0.0f, 90.0f));
Vector3Angle Vector3Angle::left = Vector3Angle(1.0f, Vector3(0.0f, 0.0f, 270.0f));
Vector3Angle Vector3Angle::up = Vector3Angle(1.0f, Vector3(90.0f, 0.0f, 0.0f));
Vector3Angle Vector3Angle::down = Vector3Angle(1.0f, Vector3(270.0f, 0.0f, 0.0f));
Vector3Angle Vector3Angle::forward = Vector3Angle(1.0f, Vector3(0.0f, 90.0f, 0.0f));
Vector3Angle Vector3Angle::back = Vector3Angle(1.0f, Vector3(0.0f, 270.0f, 0.0f));

Vector3Angle Vector3Angle::left_down_back = Vector3Angle(1.0f, Vector3(180.0f, 0.0f, 0.0f));
Vector3Angle Vector3Angle::left_down_center;
Vector3Angle Vector3Angle::left_down_forward;
Vector3Angle Vector3Angle::left_center_back;
Vector3Angle Vector3Angle::left_center_forward;
Vector3Angle Vector3Angle::left_up_back;
Vector3Angle Vector3Angle::left_up_center;
Vector3Angle Vector3Angle::left_up_forward;

Vector3Angle Vector3Angle::center_down_back;
Vector3Angle Vector3Angle::center_down_forward;
Vector3Angle Vector3Angle::center_up_back;
Vector3Angle Vector3Angle::center_up_forward;

Vector3Angle Vector3Angle::right_down_back;
Vector3Angle Vector3Angle::right_down_center;
Vector3Angle Vector3Angle::right_down_forward;
Vector3Angle Vector3Angle::right_center_back;
Vector3Angle Vector3Angle::right_center_forward;
Vector3Angle Vector3Angle::right_up_back;
Vector3Angle Vector3Angle::right_up_center;
Vector3Angle Vector3Angle::right_up_forward;

Vector3Angle Vector3Angle::fourDir[4] = { right, up, left, down };
Vector3Angle Vector3Angle::eightDir[8] = { right, right_up_center, up, left_up_center, left, left_down_center, down, right_down_center };
Vector3Angle Vector3Angle::cubeDir[9] = { zero, right, right_up_center, up, left_up_center, left, left_down_center, down, right_down_center };

Vector3 Vector3Angle::Coordinates() {
		/*
		if (abs(round(angle) - angle) < 0.001) {
			switch ((int)round(angle) % 360)
			{
			case (0):
				return Vector3(length, 0);
				break;

			case -270:
			case 90:
				return Vector3(0, length);
				break;

			case 180:
			case -180:
				return Vector3(-length, 0);
				break;

			case -90:
			case 270:
				return Vector3(0, -length);
				break;

			default:
				return Vector3(length * sin(AngleForTrigonometric(angle)), length * cos(AngleForTrigonometric(angle)));
				break;
			}
		}
		else {
			return Vector3(length * sin(AngleForTrigonometric(angle)), length * cos(AngleForTrigonometric(angle)));
		
		*/
		return Vector3(0, 0);
		
	}
float Vector3Angle::X() {
		/*if (abs(round(angle) - angle) < 0.001) {
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
				return length * float(sin(AngleForTrigonometric(angle)));
				break;
			}
		}
		else {
			return length * float(sin(AngleForTrigonometric(angle)));
		}
		*/
		return 0;
	}
float Vector3Angle::Y() {
		/*
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
				return length * float(cos(AngleForTrigonometric(angle)));
				break;
			}
		}
		else {
			return length * float(cos(AngleForTrigonometric(angle)));
		}
		*/
		return 0;
	}

string Vector3Angle::ToString() {
	return to_string(length) + " " + angle().ToString();
}
string Vector3Angle::ToString(bool is_marked) {
	return (is_marked ? "length: " : "") + to_string(length) + (is_marked ? " angle: " : " ") + angle().ToString(is_marked);
}

void Vector3Angle::RotateAround(Vector3Angle v, Vector3 angle) {
	Vector3Angle diff = *this - v;
	diff.set_angle(angle);
	*this = v + diff;
}
void Vector3Angle::RotateAround(Vector3 v, Vector3 angle) { RotateAround(Vector3Angle(v), angle); }
void Vector3Angle::RotateAround(float v_x, float v_y, float v_z, Vector3 angle) { RotateAround(Vector3(v_x, v_y, v_z), angle); }
void Vector3Angle::RotateAround(float v_x, float v_y, float v_z, float angl_x, float angl_y, float angl_z) { RotateAround(Vector3(v_x, v_y, v_z), Vector3(angl_x, angl_y, angl_z)); }
void Vector3Angle::RotateAround(int v_x, int v_y, int v_z, Vector3 angle) { RotateAround(Vector3(v_x, v_y, v_z), angle); }
void Vector3Angle::RotateAround(double v_x, double v_y, double v_z, Vector3 angle) { RotateAround(Vector3(v_x, v_y, v_z), angle); }

#define operatorInit \
Vector3Angle Vector3Angle::operator op (Vector3Angle v) { return Vector3Angle(this->Coordinates() op v.Coordinates()); } \
Vector3Angle Vector3Angle::operator op (Vector3 v) { return Vector3Angle(this->Coordinates() op v); } \
Vector3Angle Vector3Angle::operator op (float a) { return Vector3Angle(length op a, angle()); } \
Vector3Angle Vector3Angle::operator op (int a) { return *this op float(a); } \
Vector3Angle Vector3Angle::operator op (double a) { return *this op float(a); } \
\
void Vector3Angle::operator op= (Vector3Angle v) { length op= v.length; set_angle((*this + v).angle()); } \
void Vector3Angle::operator op= (Vector3 v) { length op= v.Length(); set_angle((*this + Vector3Angle(v)).angle()); } \
void Vector3Angle::operator op= (float a) { length op= a; } \
void Vector3Angle::operator op= (int a) { *this op= float(a); } \
void Vector3Angle::operator op= (double a) { *this op= float(a); }


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

bool Vector3Angle::operator== (Vector3Angle v) { return length == v.length && angle() == v.angle(); }
bool Vector3Angle::operator== (Vector3 v) { return length == v.Length() && angle() == v.Angle(); }
bool Vector3Angle::operator== (float a) { return X() == a && Y() == a; }
bool Vector3Angle::operator== (int a) { return *this == float(a); }
bool Vector3Angle::operator== (double a) { return *this == float(a); }

bool Vector3Angle::operator!= (Vector3Angle v) { return length != v.length || angle() != v.angle(); }
bool Vector3Angle::operator!= (Vector3 v) { return length != v.Length() || angle() != v.Angle(); }
bool Vector3Angle::operator!= (float a) { return X() != a || Y() != a || Z() != a; }
bool Vector3Angle::operator!= (int a) { return *this != float(a); }
bool Vector3Angle::operator!= (double a) { return *this != float(a); }

#define operatorInit \
bool Vector3Angle::operator op (Vector3Angle v) { return this->Coordinates() op v.Coordinates(); } \
bool Vector3Angle::operator op (Vector3 v) { return this->Coordinates() op v; } \
bool Vector3Angle::operator op (float a) { return X() op a && Y() op a && Z() op a; } \
bool Vector3Angle::operator op (int a) { return *this op float(a); } \
bool Vector3Angle::operator op (double a) { return *this op float(a); } \
\
bool Vector3Angle::operator op= (Vector3Angle v) { return this->Coordinates() op= v.Coordinates(); } \
bool Vector3Angle::operator op= (Vector3 v) { return this->Coordinates() op= v; } \
bool Vector3Angle::operator op= (float a) { return X() op= a && Y() op= a && Z() op= a; } \
bool Vector3Angle::operator op= (int a) { return *this op= float(a); } \
bool Vector3Angle::operator op= (double a) { return *this op= float(a); } 

#define op <
operatorInit;
#undef op

#define op >
operatorInit;
#undef op

#undef operatorInit
void Vector3Angle::operator++ (int a) { length++; }
void Vector3Angle::operator-- (int a) { length--; }

// Vector3Angle GetRotated(Vector3Angle v, float angle) { return Vector3Angle(v.length, v.angle + angle); }
Vector3Angle GetRotated(Vector3Angle v, int angle) { return GetRotated(v, float(angle)); }
Vector3Angle GetRotated(Vector3Angle v, double angle) { return GetRotated(v, float(angle)); }