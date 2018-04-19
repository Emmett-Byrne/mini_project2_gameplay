#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setRotation(vec3 t_r)
{
	xRotation = t_r.x;
	yRotation = t_r.y;
	zRotation = t_r.z;
}

void Entity::setLocation(vec3 t_l)
{
	location = t_l;
}

void Entity::rotate(vec3 t_r)
{
	xRotation += t_r.x;
	yRotation += t_r.y;
	zRotation += t_r.z;
}

void Entity::move(vec3 t_l)
{
	location += t_l;
}

void Entity::setID(GLint t_id)
{
	mvpID = t_id;
}

GLint & Entity::getID()
{
	return mvpID;
}

mat4 Entity::getmvp()
{
	return mvp;
}

vec3 Entity::getLocation()
{
	return location;
}

void Entity::update(mat4 projection, mat4 view)
{
	model = mat4(1.0f);

	model = translate(model, location);
	model = glm::rotate(model, xRotation, glm::vec3(1, 0, 0));
	model = glm::rotate(model, yRotation, glm::vec3(0, 1, 0));
	model = glm::rotate(model, zRotation, glm::vec3(0, 0, 1));

	mvp = projection * view * model;
}
