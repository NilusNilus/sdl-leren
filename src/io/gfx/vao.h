#pragma once
#include <glad/glad.h>
#include "io/gfx/vbo.h"

struct VAO
{
    GLuint id;
};

void vao_create(struct VAO* vao);
void vao_bind(struct VAO* vao);
void vao_unbind(void);
void vao_attrib(struct VAO* vao, struct VBO* vbo, GLuint index, GLuint size, GLenum type, size_t stride);
void vao_destroy(struct VAO* vao);