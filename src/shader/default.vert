#version 330 core
layout(location=0)in vec3 aPos;
layout(location=1)in vec3 aColor;
out vec3 color;
uniform mat4 u_modal;
uniform mat4 u_projection;
uniform mat4 u_view;

void main()
{
    gl_Position=u_projection*u_view*u_modal*vec4(aPos,1.);
    color=aColor;
}