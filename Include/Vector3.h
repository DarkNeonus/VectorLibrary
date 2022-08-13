#pragma once

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include<string>
#include <iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;

#include"Vector2Angle.h"
#include"Vector3Angle.h"
struct Vector2;

struct Vector2Angle;
struct Vector3Angle;

struct Vector3 {
public:
	float x;
	float y;
	float z;

	Vector3();

	Vector3(float x);
	Vector3(int x);
	Vector3(double x);


	Vector3(float x, float y); 
	Vector3(int x, int y);
	Vector3(int x, float y);
	Vector3(int x, double y);
	Vector3(float x, int y);
	Vector3(float x, double y);
	Vector3(double x, int y);
	Vector3(double x, float y);
	Vector3(double x, double y);

	Vector3(float x, float y, float z);
	Vector3(int x, int y, float z);
	Vector3(int x, float y, float z);
	Vector3(int x, double y, float z);
	Vector3(float x, int y, float z);
	Vector3(float x, double y, float z);
	Vector3(double x, int y, float z);
	Vector3(double x, float y, float z);
	Vector3(double x, double y, float z);

	Vector3(float x, float y, int z);
	Vector3(int x, int y, int z);
	Vector3(int x, float y, int z);
	Vector3(int x, double y, int z);
	Vector3(float x, int y, int z);
	Vector3(float x, double y, int z);
	Vector3(double x, int y, int z);
	Vector3(double x, float y, int z);
	Vector3(double x, double y, int z);

	Vector3(float x, float y, double z);
	Vector3(int x, int y, double z);
	Vector3(int x, float y, double z);
	Vector3(int x, double y, double z);
	Vector3(float x, int y, double z);
	Vector3(float x, double y, double z);
	Vector3(double x, int y, double z);
	Vector3(double x, float y, double z);
	Vector3(double x, double y, double z);

	Vector3(Vector3Angle v);

	Vector3(Vector2Angle v);
	Vector3(Vector2Angle v, float z_coord);

	Vector3(Vector2 v);
	Vector3(Vector2 v, float z);

	static Vector3 zero;

	static Vector3 right;
	static Vector3 left;
	static Vector3 up;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 back;

	static Vector3 left_down_back;
	static Vector3 left_down_center;
	static Vector3 left_down_forward;
	static Vector3 left_center_back;
	static Vector3 left_center_forward;
	static Vector3 left_up_back;
	static Vector3 left_up_center;
	static Vector3 left_up_forward;

	static Vector3 center_down_back;
	static Vector3 center_down_forward;
	static Vector3 center_up_back;
	static Vector3 center_up_forward;
	
	static Vector3 right_down_back;
	static Vector3 right_down_center;
	static Vector3 right_down_forward;
	static Vector3 right_center_back;
	static Vector3 right_center_forward;
	static Vector3 right_up_back;
	static Vector3 right_up_center;
	static Vector3 right_up_forward;

	/*
	!!! Vector3::zero, Vector3::right, ... not allowed outside class or methods !!!
	*/

	static Vector3 fourDir[4];
	static Vector3 eightDir[8];
	static Vector3 noralsDir[6];
	static Vector3 cubeDir[9];

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

	void Rotate(Vector2 angle);
	void Rotate(Vector3 angle);
	void Rotate(Vector2Angle angle);
	void Rotate(Vector3Angle angle);
	void Rotate(float x_angle, float y_angle, float z_angle);
	void Rotate(int x_angle, int y_angle, int z_angle);
	void Rotate(double x_angle, double y_angle, double z_angle);

	void SetAngle(Vector2 angle);
	void SetAngle(Vector3 angle);
	void SetAngle(Vector2Angle angle);
	void SetAngle(Vector3Angle angle);
	void SetAngle(float x_angle, float y_angle, float z_angle);
	void SetAngle(int x_angle, int y_angle, int z_angle);
	void SetAngle(double x_angle, double y_angle, double z_angle);


	void RotateAround(Vector3 v, Vector3 angle);
	void RotateAround(Vector2 v, Vector3 angle);
	void RotateAround(Vector3Angle v, Vector3 angle);
	void RotateAround(Vector2Angle v, Vector3 angle);
	void RotateAround(float v_x, float v_y, float v_z, Vector3 angle);
	void RotateAround(float v_x, float v_y, float v_z, float x_angl, float y_angl, float z_angl);

	void RotateAround(int v_x, int v_y, int v_z, Vector3 angle);
	void RotateAround(double v_x, double v_y, double v_z, Vector3 angle);

	static Vector3 UnitCircle(Vector3 angle);

	Vector3 Angle();


	Vector3 operator + (Vector3 v);
	Vector3 operator + (Vector2 v);
	Vector3 operator + (Vector3Angle v);
	Vector3 operator + (Vector2Angle v);
	Vector3 operator + (float a);
	Vector3 operator + (int a);
	Vector3 operator + (double a);

	Vector3 operator - (Vector3 v);
	Vector3 operator - (Vector2 v);
	Vector3 operator - (Vector3Angle v);
	Vector3 operator - (Vector2Angle v);
	Vector3 operator - (float a);
	Vector3 operator - (int a);
	Vector3 operator - (double a);

	Vector3 operator * (Vector3 v);
	Vector3 operator * (Vector2 v);
	Vector3 operator * (Vector3Angle v);
	Vector3 operator * (Vector2Angle v);
	Vector3 operator * (float a);
	Vector3 operator * (int a);
	Vector3 operator * (double a);

	Vector3 operator / (Vector3 v);
	Vector3 operator / (Vector2 v);
	Vector3 operator / (Vector3Angle v);
	Vector3 operator / (Vector2Angle v);
	Vector3 operator / (float a);
	Vector3 operator / (int a);
	Vector3 operator / (double a);


	void operator += (Vector3 v); 
	void operator += (Vector2 v); 
	void operator += (Vector3Angle v); 
	void operator += (Vector2Angle v); 
	void operator += (float a); 
	void operator += (int a); 
	void operator += (double a);

	void operator -= (Vector3 v);
	void operator -= (Vector2 v);
	void operator -= (Vector3Angle v);
	void operator -= (Vector2Angle v);
	void operator -= (float a);
	void operator -= (int a);
	void operator -= (double a);

	void operator *= (Vector3 v);
	void operator *= (Vector2 v);
	void operator *= (Vector3Angle v);
	void operator *= (Vector2Angle v);
	void operator *= (float a);
	void operator *= (int a);
	void operator *= (double a);

	void operator /= (Vector3 v);
	void operator /= (Vector2 v);
	void operator /= (Vector3Angle v);
	void operator /= (Vector2Angle v);
	void operator /= (float a);
	void operator /= (int a);
	void operator /= (double a);

	bool operator == (Vector3 v);
	bool operator == (Vector2 v);
	bool operator == (Vector3Angle v);
	bool operator == (Vector2Angle v);
	bool operator == (float a);
	bool operator == (int a);
	bool operator == (double a);

	bool operator != (Vector3 v);
	bool operator != (Vector2 v);
	bool operator != (Vector3Angle v);
	bool operator != (Vector2Angle v);
	bool operator != (float a);
	bool operator != (int a);
	bool operator != (double a);

	bool operator < (Vector3 v);
	bool operator < (Vector2 v);
	bool operator < (Vector3Angle v);
	bool operator < (Vector2Angle v);
	bool operator < (float a);
	bool operator < (int a);
	bool operator < (double a);

	bool operator > (Vector3 v);
	bool operator > (Vector2 v);
	bool operator > (Vector3Angle v);
	bool operator > (Vector2Angle v);
	bool operator > (float a);
	bool operator > (int a);
	bool operator > (double a);

	bool operator <= (Vector3 v);
	bool operator <= (Vector2 v);
	bool operator <= (Vector3Angle v);
	bool operator <= (Vector2Angle v);
	bool operator <= (float a);
	bool operator <= (int a);
	bool operator <= (double a);

	bool operator >= (Vector3 v);
	bool operator >= (Vector2 v);
	bool operator >= (Vector3Angle v);
	bool operator >= (Vector2Angle v);
	bool operator >= (float a);
	bool operator >= (int a);
	bool operator >= (double a);


	void operator++ (int a);
	void operator-- (int a);
};

Vector3 GetRotated(Vector3 v, Vector3 angle);
Vector3 GetRotated(Vector3 v, float angl_x, float angl_y, float angl_z);

Vector3 GetAngleVector3(Vector3 v);

#endif