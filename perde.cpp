// CODIGO DA PERDA
#include <SFML/Graphics.hpp>

int perde2(sf::RenderWindow *window) {
	bool click, keygame, keymenu;
	click = false;

	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("perde.png");
	fundo.setTexture(imagem);
	mouseplay.setSize(sf::Vector2f(245, 68));
	mouseplay.setPosition(57, 367);

	while (window->isOpen()) {
		sf::Event event;
		leituramouse = sf::Mouse::getPosition(*window);
		cordenadatual = window->mapPixelToCoords(leituramouse);

		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && click == false) {
				click = true;
			}
		}

		if (click == true) {
			if (mouseplay.getGlobalBounds().contains(cordenadatual)) {
				keygame = true;
				keymenu = false;
			}
			click = false;
		}

		if (keymenu == true) {

		}
		if (keygame == true) {
			imagem.loadFromFile("inicial.png");

		}

		window->clear();
		window->draw(fundo);
		window->display();
	}

	return 0;
}
