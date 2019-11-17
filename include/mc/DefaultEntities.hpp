#pragma once

#include <memory>

#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <unordered_map>

namespace mc
{
	struct Transform
	{
		glm::vec3 position;
		glm::vec3 eulerRotation;
		glm::vec3 scale;
	};

	struct GameRegistry
	{
		std::unordered_map<std::string, ShaderProgram*> programRefs;
	};

	struct Window
	{
		std::unique_ptr<sf::Window> window;
	};
}