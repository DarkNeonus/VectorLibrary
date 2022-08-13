#pragma once

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include<string>
#include <iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;

#include"Vector2Angle.h"
#include"Vector3Angle.h"
struct Vector2Angle;
struct Vector3Angle;

struct Vector3;

struct Vector2 {
public:
	float x;
	float y;

	Vector2();

	Vector2(float x);
	Vector2(int x);
	Vector2(double x);


	Vector2(float x, float y); 
	Vector2(int x, int y);
	Vector2(int x, float y);
	Vector2(int x, double y);
	Vector2(float x, int y);
	Vector2(float x, double y);
	Vector2(double x, int y);
	Vector2(double x, float y);
	Vector2(double x, double y);

	Vector2(Vector2Angle v);

	static Vector2 zero;

	static Vector2 right;
	static Vector2 left;
	static Vector2 up;
	static Vector2 down;

	static Vector2 right_up;
	static Vector2 right_down;
	static Vector2 left_up;
	static Vector2 left_down;

	/*
	!!! Vector2::zero, Vector2::right, ... not allowed outside class or methods !!!
	*/

	static Vector2 fourDir[4];
	static Vector2 eightDir[8];
	static Vector2 rectDir[9];

	float Length();

	void IncreaseLength(float a);
	void IncreaseLength(int a);
	void IncreaseLength(double a);

	void SetLength(float a);
	void SetLength(int a);
	void SetLength(double a);

	void MultiplyLength(float a);
	void MultiplyLength(int a);
	void MultiplyLength(double a);


	string ToString();
	string ToString(bool is_marked);

	void Rotate(int angle);
	void Rotate(float angle);
	void Rotate(double angle);

	void SetAngle(float angle);
	void SetAngle(int angle);
	void SetAngle(double angle);


	void RotateAround(Vector2 v, double angle);
	void RotateAround(Vector2Angle v, double angle);
	void RotateAround(float v_x, float v_y, double angle); 
	void RotateAround(int v_x, int v_y, double angle);
	void RotateAround(int v_x, float v_y, double angle);
	void RotateAround(int v_x, double v_y, double angle);
	void RotateAround(float v_x, int v_y, double angle);
	void RotateAround(float v_x, double v_y, double angle);
	void RotateAround(double v_x, int v_y, double angle);
	void RotateAround(double v_x, float v_y, double angle);
	void RotateAround(double v_x, double v_y, double angle);

	static Vector2 UnitCircle(double angle);

	float Angle();

	Vector2 operator+ (Vector2 v);
	Vector2 operator+ (Vector2Angle v);
	Vector2 operator+ (float a);
	Vector2 operator+ (int a);
	Vector2 operator+ (double a);

	Vector2 operator- (Vector2 v);
	Vector2 operator- (Vector2Angle v);
	Vector2 operator- (float a);
	Vector2 operator- (int a);
	Vector2 operator- (double a);

	Vector2 operator* (Vector2 v);
	Vector2 operator* (Vector2Angle v);
	Vector2 operator* (float a);
	Vector2 operator* (int a);
	Vector2 operator* (double a);

	Vector2 operator/ (Vector2 v);
	Vector2 operator/ (Vector2Angle v);
	Vector2 operator/ (float a);
	Vector2 operator/ (int a);
	Vector2 operator/ (double a);

	void operator+= (Vector2 v);
	void operator+= (Vector2Angle v);
	void operator+= (float a);
	void operator+= (int a);
	void operator+= (double a);

	void operator-= (Vector2 v);
	void operator-= (Vector2Angle v);
	void operator-= (float a);
	void operator-= (int a);
	void operator-= (double a);

	void operator*= (Vector2 v);
	void operator*= (Vector2Angle v);
	void operator*= (float a);
	void operator*= (int a);
	void operator*= (double a);

	void operator/= (Vector2 v);
	void operator/= (Vector2Angle v);
	void operator/= (float a);
	void operator/= (int a);
	void operator/= (double a);

	bool operator== (Vector2 v);
	bool operator== (Vector2Angle v);
	bool operator== (float v);
	bool operator== (int v);
	bool operator== (double v);


	bool operator!= (Vector2 v);
	bool operator!= (Vector2Angle v);
	bool operator!= (float v);
	bool operator!= (int v);
	bool operator!= (double v);


	bool operator> (Vector2 v);
	bool operator> (Vector2Angle v);
	bool operator> (float v);
	bool operator> (int v);
	bool operator> (double v);


	bool operator< (Vector2 v);
	bool operator< (Vector2Angle v);
	bool operator< (float v);
	bool operator< (int v);
	bool operator< (double v);


	bool operator>= (Vector2 v);
	bool operator>= (Vector2Angle v);
	bool operator>= (float v);
	bool operator>= (int v);
	bool operator>= (double v);


	bool operator<= (Vector2 v);
	bool operator<= (Vector2Angle v);
	bool operator<= (float v);
	bool operator<= (int v);
	bool operator<= (double v);


	void operator++ (int a);
	void operator-- (int a);
};

double DegToRad(float deg);
double DegToRad(int deg);
double DegToRad(double deg); 

float RadToDeg(float rad);
float RadToDeg(int rad);
float RadToDeg(double rad);

Vector2 GetRotated(Vector2 v, float angle);
Vector2 GetRotated(Vector2 v, int angle);
Vector2 GetRotated(Vector2 v, double angle);

// double AngleForTrigonometric(float angle);
// double AngleForTrigonometric(int angle);
// double AngleForTrigonometric(double angle);

float GetAngleVector2(Vector2 v);

template <typename T>
T signum(T num) {
	if (num > T(0)) { return T(1); }
	else if (num < T(0)) { return T(-1); }
	return T(0);
}

#endif