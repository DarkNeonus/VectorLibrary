#pragma once
#ifndef VECTOR3ANGLE_H_

#define VECTOR3ANGLE_H_

#include"Vector2.h"
#include"Vector3.h"
struct Vector2;
struct Vector3;

struct Vector2Angle;

struct Vector3Angle {
	float length;

	float angle_x;
	float angle_y;
	float angle_z;

	Vector3 angle();
	void set_angle(Vector3 v);

	Vector3Angle();
	Vector3Angle(float length);
	Vector3Angle(int length);
	Vector3Angle(double length);
	Vector3Angle(float length, Vector3 angle);
	Vector3Angle(float length, float angl_x, float angl_y, float angl_z);
	Vector3Angle(int length, Vector3 angle);
	Vector3Angle(double length, Vector3 angle);
	Vector3Angle(Vector3 v);
	Vector3Angle(Vector2 v);
	Vector3Angle(Vector2 v, float z);
	Vector3Angle(Vector2Angle v);
	Vector3Angle(Vector2Angle v, float angl_z);

	static Vector3Angle zero;

	static Vector3Angle right;
	static Vector3Angle left;
	static Vector3Angle up;
	static Vector3Angle down;
	static Vector3Angle forward;
	static Vector3Angle back;

	static Vector3Angle left_down_back;
	static Vector3Angle left_down_center;
	static Vector3Angle left_down_forward;
	static Vector3Angle left_center_back;
	static Vector3Angle left_center_forward;
	static Vector3Angle left_up_back;
	static Vector3Angle left_up_center;
	static Vector3Angle left_up_forward;

	static Vector3Angle center_down_back;
	static Vector3Angle center_down_forward;
	static Vector3Angle center_up_back;
	static Vector3Angle center_up_forward;

	static Vector3Angle right_down_back;
	static Vector3Angle right_down_center;
	static Vector3Angle right_down_forward;
	static Vector3Angle right_center_back;
	static Vector3Angle right_center_forward;
	static Vector3Angle right_up_back;
	static Vector3Angle right_up_center;
	static Vector3Angle right_up_forward;

	/*
	!!! Vector3Angle::zero, Vector3Angle::right, ... not allowed outside class or methods !!!
	*/

	static Vector3Angle fourDir[4];
	static Vector3Angle eightDir[8];
	static Vector3Angle noralsDir[6];
	static Vector3Angle cubeDir[9];


	Vector3 Coordinates();
	float X();
	float Y();
	float Z();
	string ToString();
	string ToString(bool is_marked);

	void RotateAround(Vector3Angle v, Vector3 angle);
	void RotateAround(Vector3 v, Vector3 angle);
	void RotateAround(float v_x, float v_y, float v_z, Vector3 angle);
	void RotateAround(float v_x, float v_y, float v_z, float angl_x, float angl_y, float angl_z);
	void RotateAround(int v_x, int v_y, int v_z, Vector3 angle);
	void RotateAround(double v_x, double v_y, double v_z, Vector3 angle);

	Vector3Angle operator+ (Vector3Angle v);
	Vector3Angle operator+ (Vector2Angle v);
	Vector3Angle operator+ (Vector3 v);
	Vector3Angle operator+ (Vector2 v);
	Vector3Angle operator+ (float a);
	Vector3Angle operator+ (int a);
	Vector3Angle operator+ (double a);

	Vector3Angle operator- (Vector3Angle v);
	Vector3Angle operator- (Vector2Angle v);
	Vector3Angle operator- (Vector3 v);
	Vector3Angle operator- (Vector2 v);
	Vector3Angle operator- (float a);
	Vector3Angle operator- (int a);
	Vector3Angle operator- (double a);

	Vector3Angle operator* (Vector3Angle v);
	Vector3Angle operator* (Vector2Angle v);
	Vector3Angle operator* (Vector3 v);
	Vector3Angle operator* (Vector2 v);
	Vector3Angle operator* (float a);
	Vector3Angle operator* (int a);
	Vector3Angle operator* (double a);

	Vector3Angle operator/ (Vector3Angle v);
	Vector3Angle operator/ (Vector2Angle v);
	Vector3Angle operator/ (Vector3 v);
	Vector3Angle operator/ (Vector2 v);
	Vector3Angle operator/ (float a);
	Vector3Angle operator/ (int a);
	Vector3Angle operator/ (double a);

	void operator+= (Vector3Angle v);
	void operator+= (Vector2Angle v);
	void operator+= (Vector3 v);
	void operator+= (Vector2 v);
	void operator+= (float a);
	void operator+= (int a);
	void operator+= (double a);

	void operator-= (Vector3Angle v);
	void operator-= (Vector2Angle v);
	void operator-= (Vector3 v);
	void operator-= (Vector2 v);
	void operator-= (float a);
	void operator-= (int a);
	void operator-= (double a);

	void operator*= (Vector3Angle v);
	void operator*= (Vector2Angle v);
	void operator*= (Vector3 v);
	void operator*= (Vector2 v);
	void operator*= (float a);
	void operator*= (int a);
	void operator*= (double a);

	void operator/= (Vector3Angle v);
	void operator/= (Vector2Angle v);
	void operator/= (Vector3 v);
	void operator/= (Vector2 v);
	void operator/= (float a);
	void operator/= (int a);
	void operator/= (double a);


	bool operator== (Vector3Angle v);
	bool operator== (Vector2Angle v);
	bool operator== (Vector3 v);
	bool operator== (Vector2 v);
	bool operator== (float a);
	bool operator== (int a);
	bool operator== (double a);

	bool operator!= (Vector3Angle v);
	bool operator!= (Vector2Angle v);
	bool operator!= (Vector3 v);
	bool operator!= (Vector2 v);
	bool operator!= (float a);
	bool operator!= (int a);
	bool operator!= (double a);

	bool operator> (Vector3Angle v);
	bool operator> (Vector2Angle v);
	bool operator> (Vector3 v);
	bool operator> (Vector2 v);
	bool operator> (float a);
	bool operator> (int a);
	bool operator> (double a);

	bool operator< (Vector3Angle v);
	bool operator< (Vector2Angle v);
	bool operator< (Vector3 v);
	bool operator< (Vector2 v);
	bool operator< (float a);
	bool operator< (int a);
	bool operator< (double a);

	bool operator>= (Vector3Angle v);
	bool operator>= (Vector2Angle v);
	bool operator>= (Vector3 v);
	bool operator>= (Vector2 v);
	bool operator>= (float a);
	bool operator>= (int a);
	bool operator>= (double a);

	bool operator<= (Vector3Angle v);
	bool operator<= (Vector2Angle v);
	bool operator<= (Vector3 v);
	bool operator<= (Vector2 v);
	bool operator<= (float a);
	bool operator<= (int a);
	bool operator<= (double a);

	void operator++ (int a);
	void operator-- (int a);
};

Vector3Angle GetRotated(Vector3Angle v, Vector3 angle);
Vector3Angle GetRotated(Vector3Angle v, Vector3 angle);

#endif