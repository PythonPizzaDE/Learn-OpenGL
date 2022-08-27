#version 330 core

out vec4 FragColor;

in vec3 Color;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    /* FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2); */
    FragColor = mix(mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2), vec4(Color, 1.0), 0.2);
}
