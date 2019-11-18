#pragma once

#include <mc/RenderEntities.hpp>
#include <mc/DefaultEntities.hpp>
#include <entt/entt.hpp>

namespace mc
{
	void sLoadDCActors(entt::registry &registry)
	{
		auto view = registry.view<DrawCallActor, DrawCallActorInit>();
		auto regView = registry.view<RendererRegistry>();

		RendererRegistry *gameRegistry = nullptr;

		for (auto entity : regView)
			gameRegistry = &regView.get(entity);

		for (auto entity : view) {
			DrawCallActor &dca = view.get<DrawCallActor>(entity);
			DrawCallActorInit &dcinit = view.get<DrawCallActorInit>(entity);

			dca.program = gameRegistry->programRefs[dcinit.program_name];

			gl::Bind(dca.vao);
			gl::Bind(dca.vbo);
			gl::Bind(dca.ebo);
			gl::Use(dca.program->program);

			dca.vbo.data(dcinit.data, dcinit.usage);
			dca.ebo.data(dcinit.indices, dcinit.usage);

			unsigned int offsetPointer{0};
			unsigned int index = 0;
			unsigned int stride{0};

			for (const auto& attrib : dcinit.attributes)
			{
				//todo: add sizeof(...) for types other than float
				stride += attrib.dimension * sizeof(float);
			}

			while(!dcinit.attributes.empty())
			{
				gl::VertexAttrib glAttrib(index++);
				PAttribute& attrib = dcinit.attributes.front();

				//reinterpret_cast<> is used to avoid compiler warnings, static_cast would work but C++ doesn't really like
				//casting from object data to pointer data
				glAttrib.pointer(attrib.dimension, attrib.type, false, stride, reinterpret_cast<void*&>(offsetPointer));

				//todo: add sizeof(...) for types other than float
				offsetPointer += attrib.dimension * sizeof(float);

				glAttrib.enable();
				dcinit.attributes.pop_front();
			}

			dca.vertexCount = dcinit.indices.size();

			registry.remove<DrawCallActorInit>(entity);
		}
	}

	void sDrawDCActors(entt::registry &registry)
	{
		auto view = registry.view<DrawCallActor>();
		for (auto entity : view)
		{
			DrawCallActor &dca = view.get(entity);
			gl::Bind(dca.vao);
			gl::Bind(dca.vbo);
			gl::Bind(dca.ebo);
			gl::Use(dca.program->program);

			gl::DrawElements(gl::PrimitiveType::kTriangles, dca.vertexCount,(GLuint*)nullptr);
		}

	}

	void sLoadShaderPrograms(entt::registry &registry)
	{
		auto view = registry.view<ShaderProgramInit, ShaderProgram>();
		auto regView = registry.view<RendererRegistry>();

		RendererRegistry *gameRegistry = nullptr;

		for (auto entity : regView)
			gameRegistry = &regView.get(entity);

		for (auto entity : view) {
			ShaderProgramInit &spi = view.get<ShaderProgramInit>(entity);
			ShaderProgram &program = view.get<ShaderProgram>(entity);

			std::vector<gl::Shader> shaders;

			for (const auto &file : spi.shaderPaths) {
				gl::ShaderSource src;
				src.loadFromFile(file.first);

				shaders.emplace_back(gl::Shader(file.second, src));

				gl::Shader &shader = *(shaders.end() - 1);

				program.program.attachShader(shader);

				//TODO: necessary for shader compile errors ?
				if (shader.state() == gl::Shader::kCompileFailure)
					exit(-6);
			}

			program.program.link();

			if (program.program.state() == gl::Program::kLinkFailure)
				exit(-7);

			gameRegistry->programRefs[spi.name] = &program;
		}
	}
}

