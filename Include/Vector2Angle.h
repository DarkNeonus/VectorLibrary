#pragma once
#ifndef VECTOR2ANGLE_H_

#define VECTOR2ANGLE_H_

#include"Vector2.h"
#include"Vector3.h"
struct Vector2;
struct Vector3;

struct Vector2Angle {
	float length;
	float angle;

	Vector2Angle();
	Vector2Angle(float length);
	Vector2Angle(int length);
	Vector2Angle(double length);
	Vector2Angle(float length, float angle);
	Vector2Angle(int length, int angle);
	Vector2Angle(int length, float angle);
	Vector2Angle(int length, double angle);
	Vector2Angle(float length, int angle);
	Vector2Angle(float length, double angle);
	Vector2Angle(double length, int angle);
	Vector2Angle(double length, float angle);
	Vector2Angle(double length, double angle);
	Vector2Angle(Vector2 v);

	static Vector2Angle zero;

	static Vector2Angle right;
	static Vector2Angle left;
	static Vector2Angle up;
	static Vector2Angle down;

	static Vector2Angle right_up;
	static Vector2Angle right_down;
	static Vector2Angle left_up;
	static Vector2Angle left_down;

	static Vector2Angle fourDir[4];
	static Vector2Angle eightDir[8];
	static Vector2Angle rectDir[9];

	/*
	!!! VectorAngle::zero, VectorAngle::right, ... not allowed outside class or methods !!!
	*/

	Vector2 Coordinates();
	float X();
	float Y();
	string ToString();
	string ToString(bool is_marked);

	void RotateAround(Vector2Angle v, double angle);
	void RotateAround(Vector2 v, double angle);
	void RotateAround(float v_x, float v_y, double angle);
	void RotateAround(int v_x, int v_y, double angle);
	void RotateAround(int v_x, float v_y, double angle);
	void RotateAround(int v_x, double v_y, double angle);
	void RotateAround(float v_x, int v_y, double angle);
	void RotateAround(float v_x, double v_y, double angle);
	void RotateAround(double v_x, int v_y, double angle);
	void RotateAround(double v_x, float v_y, double angle);
	void RotateAround(double v_x, double v_y, double angle);

	Vector2Angle operator+ (Vector2Angle v);
	Vector2Angle operator+ (Vector2 v);
	Vector2Angle operator+ (float a);
	Vector2Angle operator+ (int a);
	Vector2Angle operator+ (double a);

	Vector2Angle operator- (Vector2Angle v);
	Vector2Angle operator- (Vector2 v);
	Vector2Angle operator- (float a);
	Vector2Angle operator- (int a);
	Vector2Angle operator- (double a);

	Vector2Angle operator* (Vector2Angle v);
	Vector2Angle operator* (Vector2 v);
	Vector2Angle operator* (float a);
	Vector2Angle operator* (int a);
	Vector2Angle operator* (double a);

	Vector2Angle operator/ (Vector2Angle v);
	Vector2Angle operator/ (Vector2 v);
	Vector2Angle operator/ (float a);
	Vector2Angle operator/ (int a);
	Vector2Angle operator/ (double a);

	void operator+= (Vector2Angle v);
	void operator+= (Vector2 v);
	void operator+= (float a);
	void operator+= (int a);
	void operator+= (double a);

	void operator-= (Vector2Angle v);
	void operator-= (Vector2 v);
	void operator-= (float a);
	void operator-= (int a);
	void operator-= (double a);

	void operator*= (Vector2Angle v);
	void operator*= (Vector2 v);
	void operator*= (float a);
	void operator*= (int a);
	void operator*= (double a);

	void operator/= (Vector2Angle v);
	void operator/= (Vector2 v);
	void operator/= (float a);
	void operator/= (int a);
	void operator/= (double a);


	bool operator== (Vector2Angle v);
	bool operator== (Vector2 v);
	bool operator== (float a);
	bool operator== (int a);
	bool operator== (double a);

	bool operator!= (Vector2Angle v);
	bool operator!= (Vector2 v);
	bool operator!= (float a);
	bool operator!= (int a);
	bool operator!= (double a);

	bool operator> (Vector2Angle v);
	bool operator> (Vector2 v);
	bool operator> (float a);
	bool operator> (int a);
	bool operator> (double a);

	bool operator< (Vector2Angle v);
	bool operator< (Vector2 v);
	bool operator< (float a);
	bool operator< (int a);
	bool operator< (double a);

	bool operator>= (Vector2Angle v);
	bool operator>= (Vector2 v);
	bool operator>= (float a);
	bool operator>= (int a);
	bool operator>= (double a);

	bool operator<= (Vector2Angle v);
	bool operator<= (Vector2 v);
	bool operator<= (float a);
	bool operator<= (int a);
	bool operator<= (double a);

	void operator++ (int a);
	void operator-- (int a);
};

Vector2Angle GetRotated(Vector2Angle v, float angle);
Vector2Angle GetRotated(Vector2Angle v, int angle);
Vector2Angle GetRotated(Vector2Angle v, double angle);

#endif