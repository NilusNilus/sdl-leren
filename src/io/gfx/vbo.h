#pragma once
#include <glad/glad.h>

struct VBO
{
    GLuint id;
    GLuint type;
    GLuint dynamic;
};

void vbo_create(struct VBO* vbo, GLuint type, int dynamic);
void vbo_bind(struct VBO* vbo);
void vbo_data(struct VBO* vbo, size_t size, void* data);
void vbo_destroy(struct VBO* vbo);