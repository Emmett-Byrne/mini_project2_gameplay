#pragma once

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

class Entity
{
public:
	Entity();
	~Entity();

	void setRotation(vec3 t_r);
	void setLocation(vec3 t_l);
	void rotate(vec3 t_r);
	void move(vec3 t_l);
	void setID(GLint t_id);

	GLint & getID();
	mat4 getmvp();
	vec3 getLocation();

	void update(mat4 projection, mat4 view);

private:
	GLint mvpID;
	mat4 mvp,
		model;

	vec3 location;
	float	xRotation = 0,
			yRotation = 0,
			zRotation = 0;
};