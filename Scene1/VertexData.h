#pragma once
#include "Constants.h"

float x_vertex = 0.5f, y_vertex = 0.5f;


float vertexData[] = {
	// front face
	-0.5,  0.5, 0.0,		1.0, 1.0, 0.0,	    0.0, 1.0,
	 0.5,  0.5, 0.0,		0.0,1.0,0.0,		1.0, 1.0, 
	 0.5, -0.5, 0.0,		0.0,1.0,1.0,        1.0, 0.0,
	 0.5, -0.5, 0.0,		0.0,1.0,1.0,        1.0, 0.0,
	-0.5, -0.5, 0.0,		1.0,0.0,1.0,        0.0, 0.0,
	-0.5,  0.5, 0.0,		1.0, 1.0, 0.0,      0.0, 1.0,

	 // right face
	 0.5,  0.5,  0.0,		0.0,1.0,0.0,       0.0, 1.0,
	 0.5,  0.5, -1.0,		0.0,0.0,0.0,       1.0, 1.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,       1.0, 0.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,       1.0, 0.0,
	 0.5, -0.5,0.0,		    0.0,1.0,1.0,       0.0, 0.0,
	 0.5,  0.5, 0.0,		0.0,1.0,0.0,       0.0, 1.0,

	 // top face
	 0.5, 0.5, 0.0,			0.0,1.0,0.0,      0.0, 1.0,
	-0.5, 0.5, 0.0,			1.0,1.0,0.0,      1.0, 1.0,
	-0.5, 0.5,-1.0,			0.0,0.0,1.0,      1.0, 0.0,
	-0.5, 0.5,-1.0,			0.0,0.0,1.0,      1.0, 0.0,
	 0.5, 0.5,-1.0,			0.0,0.0,0.0,      0.0, 0.0,
	 0.5, 0.5, 0.0,			0.0,1.0,0.0,      0.0, 1.0,

	 // bottom face
	 0.5, -0.5,0.0,			0.0,1.0,1.0,     1.0, 0.0,
	-0.5, -0.5,0.0,			1.0,0.0,1.0,     0.0, 0.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,     1.0, 1.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,     1.0, 1.0,
	-0.5, -0.5,-1.0,		1.0,1.0,1.0,     0.0, 1.0,
	-0.5, -0.5,0.0,			1.0,0.0,1.0,     0.0, 0.0,

	// left face
	-0.5, -0.5,0.0,			1.0,0.0,1.0,     0.0, 1.0,
	-0.5, -0.5,-1.0,		1.0,1.0,1.0,     1.0, 1.0,
	-0.5,  0.5,-1.0,		0.0,0.0,1.0,     1.0, 0.0,
	-0.5,  0.5,-1.0,		0.0,0.0,1.0,     1.0, 0.0,
	-0.5,  0.5,0.0,			1.0,1.0,0.0,     0.0, 0.0,
	-0.5, -0.5,0.0,			1.0,0.0,1.0,     0.0, 1.0,

	// back face
	-0.5,  0.5,-1.0,		0.0,0.0,1.0,     0.0,1.0,
	 0.5,  0.5,-1.0,		0.0,0.0,0.0,     1.0, 1.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,     1.0,0.0,
	 0.5, -0.5,-1.0,		1.0,0.0,0.0,     1.0, 0.0,
	-0.5, -0.5,-1.0,		1.0,1.0,1.0,     0.0,0.0,
	-0.5,  0.5,-1.0,		0.0,0.0,1.0,     0.0, 1.0
};

//float vertexPositionsAndColors[] = {
//	// front face
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],     
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, 0.0,			    COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, 0.0,              COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, 0.0,              COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, 0.0,              COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	// right face
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.5, 0.0, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.5, 0.0, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.5, 0.0, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.5, 0.0, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	// left face
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-0.5, 0.0, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-0.5, 0.0, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-0.5, 0.0, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-0.5, 0.0, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	// top face
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.5, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, y_vertex, 0.0,    COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.5, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.5, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.5, -0.5,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	// bottom face
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, -0.5, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, -0.5, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, -0.5, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, 0.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, -y_vertex, 0.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, -0.5, -0.5,            COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	// back face
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, -1.0,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	x_vertex, y_vertex, -1.0,   COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, -1.0,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, -1.0,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//
//	-x_vertex, -y_vertex, -1.0, COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	x_vertex, -y_vertex, -1.0,  COLOR_ROYAL_BLUE[0], COLOR_ROYAL_BLUE[1], COLOR_ROYAL_BLUE[2],
//	0.0, 0.0, -1.0,             COLOR_SKY_BLUE[0], COLOR_SKY_BLUE[1], COLOR_SKY_BLUE[2],
//};