#include "io/gfx/vao.h"

void vao_create(struct VAO* vao)
{
    glGenVertexArrays(1, &vao->id);
}

void vao_bind(struct VAO* vao)
{   
    glBindVertexArray(vao->id);
}

void vao_unbind(void)
{
    glBindVertexArray(0);
}

void vao_attrib(
    struct VAO* vao, 
    struct VBO* vbo, 
    GLuint index,
    GLuint size,
    GLenum type,
    size_t stride
) {
    vbo_bind(vbo);

    glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void*) 0);
    glEnableVertexAttribArray(index);
}

void vao_destroy(struct VAO* vao)
{
    glDeleteVertexArrays(1, &vao->id);
}