#pragma once

#include <GL/glew.h>
#include <GL.hpp>
#include <oglwrap/oglwrap.h>
#include <glm/glm.hpp>
#include <queue>

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

	//NOT A COMPONENT
	struct PAttribute
	{
		unsigned int dimension;
		gl::DataType type = gl::DataType::kFloat;
	};

	struct DrawCallActorInit
	{
		std::vector<float> data;
		std::vector<unsigned int> indices;
		std::deque<PAttribute> attributes;
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