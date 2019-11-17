#pragma once

#include <GL/glew.h>
#include <GL.hpp>
#include <oglwrap/oglwrap.h>
#include <glm/glm.hpp>

namespace mc
{
	struct ShaderProgram
	{
		gl::Program program;
	};

	struct ShaderProgramInit
	{
		std::string name;
		std::vector<std::pair<std::string, gl::ShaderType>> shaderPaths;
	};

	struct DrawCallActorInit
	{
		std::vector<float> data;
		std::vector<unsigned int> indices;
		gl::BufferUsage usage;
		std::string program_name;
	};

	struct DrawCallActor
	{
		gl::VertexArray vao;
		gl::ArrayBuffer vbo;
		gl::IndexBuffer ebo;
		ShaderProgram* program;

		unsigned int vertexCount;
	};
}