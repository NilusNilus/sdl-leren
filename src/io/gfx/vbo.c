#include "io/gfx/vbo.h"

void vbo_create(struct VBO* vbo, GLuint type, int dynamic)
{   
    glGenBuffers(1, &vbo->id);
    vbo->type = type;
    vbo->dynamic = dynamic;
}

void vbo_bind(struct VBO* vbo)
{
    glBindBuffer(vbo->id, vbo->type);
}   

void vbo_data(struct VBO* vbo, size_t size, void* data)
{
    vbo_bind(vbo);
    glBufferData(vbo->type, size, data, vbo->dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}

void vbo_destroy(struct VBO* vbo)
{
    glDeleteBuffers(1, &vbo->id);
}