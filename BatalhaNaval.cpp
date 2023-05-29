// CODIGO DA TELA INICIAL

#include "main.hpp"

int main() {
	bool click, keygame;
	click = false;

	sf::RenderWindow window(sf::VideoMode(960, 540), "ONE PIECE: Batalha Naval",
			sf::Style::Titlebar | sf::Style::Close);
	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("assets/menu.png");
	fundo.setTexture(imagem);
	mouseplay.setSize(sf::Vector2f(184, 68));
	mouseplay.setPosition(380, 435);
	sf::Image image = sf::Image { };

	image.loadFromFile("assets/logo.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	while (window.isOpen()) {
		sf::Event event;
		leituramouse = sf::Mouse::getPosition(window);
		cordenadatual = window.mapPixelToCoords(leituramouse);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && click == false) {
				click = true;
			}
		}

		if (click == true) {
			if (mouseplay.getGlobalBounds().contains(cordenadatual)) {
				keygame = true;

			}
			click = false;
		}

		if (keygame == true) {

			imagem.loadFromFile("assets/fundo.png");

			jogo(&window);
		}

		window.clear();
		window.draw(fundo);

		window.display();
	}

	return 0;
}
