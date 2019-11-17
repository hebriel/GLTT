#include <SFML/Window.hpp>
#include <mc/RenderEntities.hpp>
#include <mc/DefaultEntities.hpp>
#include <entt/entt.hpp>
#include <iostream>
#include <mc/RenderSystems.hpp>

namespace mc
{
	void pre_init(entt::registry& registry)
	{
		//Context creation
		sf::ContextSettings settings;

		settings.attributeFlags = sf::ContextSettings::Core;
		settings.majorVersion = 4;
		settings.minorVersion = 1;
		settings.depthBits = 24;
		settings.stencilBits = 8;

		auto eWindow = registry.create();
		auto w = std::unique_ptr<sf::Window>(new sf::Window({800, 600}, "MC", sf::Style::Default, settings));

		//TODO: temporary limit
		w->setFramerateLimit(120);

		glewExperimental = GL_TRUE;
		glewInit();

		registry.assign<Window>(eWindow, std::move(w));
		registry.assign<GameRegistry>(eWindow);
	}

	void init(entt::registry& registry)
	{
		auto chunk = registry.create();
		registry.assign<mc::DrawCallActor>(chunk);

		DrawCallActorInit& dcainit = registry.assign<DrawCallActorInit>(chunk);
		dcainit.usage = gl::kStaticDraw;
		dcainit.data = {
				//vec2 pos, vec3 color
				-0.5f,  -0.5f, 1.f, 0.f, 0.f,
				 0.5f,  -0.5f, 0.f, 1.f, 0.f,
				 0.0f,   0.5f, 0.f, 0.f, 1.f
		};

		dcainit.indices = {
				0, 1, 2
		};

		dcainit.program_name = "ShaderDefaultColor2D";

		auto shader = registry.create();

		registry.assign<ShaderProgram>(shader);
		ShaderProgramInit& spi = registry.assign<ShaderProgramInit>(shader);

		spi.name = "ShaderDefaultColor2D";
		spi.shaderPaths = {	{"../resources/shaders/ShaderDefaultColor2D.vert", gl::ShaderType::kVertexShader},
					 		{"../resources/shaders/ShaderDefaultColor2D.frag", gl::ShaderType::kFragmentShader}};

	}

	void post_init(entt::registry& registry)
	{
		gl::ClearColor(0.f, 0.5f, 1.f, 1.f);
	}


}

int main()
{
	entt::registry registry;

	mc::pre_init(registry);
	mc::init(registry);
	mc::post_init(registry);

	//GameLoop
	bool loop = true;

	mc::sLoadShaderPrograms(registry);
	mc::sLoadDCActors(registry);

	while (loop)
	{
		auto view = registry.view<mc::Window>();
		for (auto entity: view)
		{
			auto& window = view.get(entity);

			sf::Event event{};
			while (window.window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.window->close();
				}
			}

			gl::Clear().Color().Depth();

			mc::sDrawDCActors(registry);

			window.window->display();

			if (!window.window->isOpen())
				loop = false;
		}
	}


	return 0;
}