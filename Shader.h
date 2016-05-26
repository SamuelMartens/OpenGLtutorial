#pragma once 

#include "gl_core_4_3.h"

#include <string>

class Shader
{
public:
	class enum Type
	{
		None
		, Vertex
		, Fragment
	}
	
	Shader():
		  id(-1)
		, type(Type::None)
		, compiled(false)
		{};
	Shader(Type t):
		  id(-1)
		, type(t)
		, compiled(false)
	{};
	Shader(Type t, std::string&& filePath):
		  type(t)
		, compiled(false)
	{
		ParseAndCompile(filePath);
	};
	~Shader()=default;
	
	GLuint id;
	Type type;
	
	void ParseAndCompile(const std::string&& filePath)
	{
		Compile(ParseSourceFile(filePath));
	};
	bool isCompiled() const noexcept{ return compiled; };
	
private:
	std::string ParseSourceFile(const std::string&&  filePath) const;
	void Compile(std::string&& shaderSource);

	bool compiled;
	
}