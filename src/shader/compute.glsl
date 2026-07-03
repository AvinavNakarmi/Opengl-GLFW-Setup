#version 460 core
layout (local_size_x = 16, local_size_y = 16) in;

layout (rgba32f, binding = 0) uniform image2D destImg;

void main() {
    ivec2 coord = ivec2(gl_GlobalInvocationID.xy);
    vec4 blue = vec4(0.0, 0.0, 1.0, 1.0);
    imageStore(destImg, coord, blue);
}
