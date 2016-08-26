#include "Resources.h"

#include <string>

#include "Texture.h"
#include "ShaderProgram.h"
#include "model.h"

void Resources::Init(const ShaderProgram& shaderProgram)
{
	default_texture.Load("E:\\C++\\OpenGLtutorial\\resources\\default_texture.jpg", shaderProgram);

	default_transparent_texture.Load("E:\\C++\\OpenGLtutorial\\resources\\default_texture.jpg", shaderProgram);
	default_transparent_texture.SetTransparentEdge(0);

	initialized = true;
}
