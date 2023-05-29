// CODIGO DO JOGO

#include "main.hpp"

int perde(sf::RenderWindow *window) {
	bool click, keygame, keymenu;
	click = false;

	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("assets/perde.png");
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
			jogo(window);

		}

		window->clear();
		window->draw(fundo);
		window->display();
	}

	return 0;
}
int vence(sf::RenderWindow *window) {
	bool click, keygame, keymenu;
	click = false;

	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("assets/vence.png");
	fundo.setTexture(imagem);
	mouseplay.setSize(sf::Vector2f(241, 68));
	mouseplay.setPosition(665, 380);

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
			jogo(window);

		}

		window->clear();
		window->draw(fundo);
		window->display();
	}

	return 0;
}

sf::RectangleShape criaTabela(int x, int y, int width, int height) {
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::Cyan);
	rectangle.setOutlineThickness(1.0f);
	rectangle.setPosition(x, y);
	return rectangle;
}

void trataEventos(sf::RenderWindow *window, Celulas matriz[10][10],
		sf::Sound *boomSound, sf::Sound *splashSound, int dim, int *Chave,
		int *qntBombas) {

	sf::Event event;
	printf("QTND BOMBA = %d\nQTND BOMBA = %d\n", *qntBombas, *qntBombas);
	while ((*window).pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			(*window).close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			int linha = sf::Mouse::getPosition(*window).y / dim;
			int coluna = sf::Mouse::getPosition(*window).x / dim;

			//Errou
			if (matriz[linha][coluna] == AGUA) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*splashSound).play();
				}
				matriz[linha][coluna] = ERROU;

			}
			//Barco10
			if (matriz[linha][coluna] == BARCO10) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO10;

			}
			//Barco9
			if (matriz[linha][coluna] == BARCO9) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO9;

			}
			//Barco8
			if (matriz[linha][coluna] == BARCO8) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO8;

			}
			//Barco7
			if (matriz[linha][coluna] == BARCO7) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO7;

			}
			//Barco6
			if (matriz[linha][coluna] == BARCO6) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO6;

			}
			if (matriz[linha][coluna] == BARCO5) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO5;

			}
			if (matriz[linha][coluna] == BARCO4) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO4;

			}
			if (matriz[linha][coluna] == BARCO3) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO3;

			}
			if (matriz[linha][coluna] == BARCO2) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO2;

			}
			if (matriz[linha][coluna] == BARCO1) {
				(*qntBombas)--;
				if (linha < 10 && coluna < 10) {
					(*boomSound).play();
				}
				matriz[linha][coluna] = MARCADO1;

			}

			if (*Chave == 0) {
				*Chave = 1;
			}

		}

	}
}

void desenhaBlocos(sf::RenderWindow &window, sf::RectangleShape boxes[10][10],
		float x, float y, int *Chave, Celulas matriz[10][10]) {
	sf::Color cor;
	sf::Vector2f coordenada;
	sf::Vector2i leituramouse;
	int countBarco10 = 0, countBarco9 = 0, countBarco8 = 0, countBarco7 = 0,
			countBarco6 = 0;
	int countBarco5 = 0, countBarco4 = 0, countBarco3 = 0, countBarco2 = 0,
			countBarco1 = 0;

	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			if (boxes[i][c].getGlobalBounds().contains(x, y)) {
				cor = sf::Color::Red;

			}
			//BARCO10
			else if (matriz[c][i] == MARCADO10) {

				cor = sf::Color::Yellow;

				countBarco10 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO10) {
							countBarco10++;
							if (countBarco10 == 5) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			}
			//BARCO9
			else if (matriz[c][i] == MARCADO9) {

				cor = sf::Color::Yellow;

				countBarco9 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO9) {
							countBarco9++;

							if (countBarco9 == 4) {

								cor = sf::Color::Green;
							}
						}
					}
				}

				//cor = sf::Color::Green;
			}

			//Barco8
			else if (matriz[c][i] == MARCADO8) {

				cor = sf::Color::Yellow;

				countBarco8 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO8) {

							countBarco8++;

							if (countBarco8 == 4) {

								cor = sf::Color::Green;
							}
						}
					}
				}
			}
			//Barco7
			else if (matriz[c][i] == MARCADO7) {

				cor = sf::Color::Yellow;

				countBarco7 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO7) {
							countBarco7++;
							if (countBarco7 == 3) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			}
			//Barco7
			else if (matriz[c][i] == MARCADO6) {

				cor = sf::Color::Yellow;

				countBarco6 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO6) {
							countBarco6++;
							if (countBarco6 == 3) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] == MARCADO5) {

				cor = sf::Color::Yellow;

				countBarco5 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO5) {
							countBarco5++;
							if (countBarco5 == 3) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] == MARCADO4) {

				cor = sf::Color::Yellow;

				countBarco4 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO4) {
							countBarco4++;
							if (countBarco4 == 2) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] == MARCADO3) {

				cor = sf::Color::Yellow;

				countBarco3 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO3) {
							countBarco3++;
							if (countBarco3 == 2) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] == MARCADO2) {

				cor = sf::Color::Yellow;

				countBarco2 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO2) {
							countBarco2++;
							if (countBarco2 == 2) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] == MARCADO1) {

				cor = sf::Color::Yellow;

				countBarco1 = 0;

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (matriz[i][j] == MARCADO1) {
							countBarco1++;
							if (countBarco1 == 2) {

								cor = sf::Color::Green;
							}
						}
					}
				}

			} else if (matriz[c][i] != MARCADO10 || matriz[c][i] != MARCADO9
					|| matriz[c][i] != MARCADO8 || matriz[c][i] != MARCADO7
					|| matriz[c][i] != MARCADO6 || matriz[c][i] != MARCADO5
					|| matriz[c][i] != MARCADO4 || matriz[c][i] != MARCADO3
					|| matriz[c][i] != MARCADO2 || matriz[c][i] != MARCADO1) {
				cor = sf::Color::Blue;
			}

			boxes[i][c].setFillColor(cor);
			window.draw(boxes[i][c]);
		}
	}
}

void desenhaImagem(sf::RenderWindow &window, Celulas matriz[10][10], int dim,
		sf::Sprite boomImage, sf::Sprite XImage,
		sf::RectangleShape boxes[10][10], int *Chave) {

	sf::Color cor;
	float x, y;
	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			if (matriz[i][c] == BOOM || matriz[i][c] == ERROU
					|| matriz[i][c] == MARCADO10 || matriz[i][c] == MARCADO9
					|| matriz[i][c] == MARCADO8 || matriz[i][c] == MARCADO7
					|| matriz[i][c] == MARCADO6 || matriz[i][c] == MARCADO5
					|| matriz[i][c] == MARCADO4 || matriz[i][c] == MARCADO3
					|| matriz[i][c] == MARCADO2 || matriz[i][c] == MARCADO1) {

				y = i * dim;
				x = c * dim;

				XImage.setPosition(x, y);
				boomImage.setPosition(x, y);
				if (matriz[i][c] == ERROU) {
					window.draw(XImage);
				} else {
					window.draw(boomImage);
				}
			}
		}

	}
}

void defineDirecao(int *direcao) {
	int X, Y;

	X = rand() % 10;
	Y = rand() % 10;

	if (X == 9) {
		*direcao = Vertical;
	} else if (Y == 9) {
		*direcao = Horizontal;
	} else {
		*direcao = 1 + (rand() % 2);
	}
}

void barcoTamanho5(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 1 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = AGUA;
					matrizArmazem[i][j] = AGUA;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == AGUA && matriz[X + 1][Y] == AGUA
					&& matriz[X + 2][Y] == AGUA && matriz[X + 3][Y] == AGUA
					&& matriz[X + 4][Y] == AGUA) {

				if (matriz[X - 1][Y] == AGUA) {

					if (X + 5 <= 9) {
						if (matriz[X + 5][Y] == AGUA) {

							if (matriz[X - 1][Y + 1] == AGUA
									&& matriz[X][Y + 1] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 2][Y + 1] == AGUA
									&& matriz[X + 3][Y + 1] == AGUA
									&& matriz[X + 4][Y + 1] == AGUA
									&& matriz[X + 5][Y + 1] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X][Y - 1] == AGUA
										&& matriz[X + 1][Y - 1] == AGUA
										&& matriz[X + 2][Y - 1] == AGUA
										&& matriz[X + 3][Y - 1] == AGUA
										&& matriz[X + 4][Y - 1] == AGUA
										&& matriz[X + 5][Y - 1] == AGUA) {

									matrizArmazem[X][Y] = BARCO10;

									matriz[X][Y] = BARCO10;
									matriz[X + 1][Y] = BARCO10;
									matriz[X + 2][Y] = BARCO10;
									matriz[X + 3][Y] = BARCO10;
									matriz[X + 4][Y] = BARCO10;

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == AGUA && matriz[X][Y + 1] == AGUA
					&& matriz[X][Y + 2] == AGUA && matriz[X][Y + 3] == AGUA
					&& matriz[X][Y + 4] == AGUA) {

				if (matriz[X][Y - 1] == AGUA) {

					if (Y + 5 <= 9) {
						if (matriz[X][Y + 5] == AGUA) {

							if (matriz[X + 1][Y - 1] == AGUA
									&& matriz[X + 1][Y] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 1][Y + 2] == AGUA
									&& matriz[X + 1][Y + 3] == AGUA
									&& matriz[X + 1][Y + 4] == AGUA
									&& matriz[X + 1][Y + 5] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X - 1][Y] == AGUA
										&& matriz[X - 1][Y + 1] == AGUA
										&& matriz[X - 1][Y + 2] == AGUA
										&& matriz[X - 1][Y + 3] == AGUA
										&& matriz[X - 1][Y + 4] == AGUA
										&& matriz[X - 1][Y + 5] == AGUA) {

									matrizArmazem[X][Y] = BARCO10;

									matriz[X][Y] = BARCO10;
									matriz[X][Y + 1] = BARCO10;
									matriz[X][Y + 2] = BARCO10;
									matriz[X][Y + 3] = BARCO10;
									matriz[X][Y + 4] = BARCO10;

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}
void barcoTamanho4(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 2 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;
		quebraLoop++;

		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = AGUA;
					matrizArmazem[i][j] = AGUA;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == AGUA && matriz[X + 1][Y] == AGUA
					&& matriz[X + 2][Y] == AGUA && matriz[X + 3][Y] == AGUA) {

				if (matriz[X - 1][Y] == AGUA) {

					if (X + 4 <= 9) {
						if (matriz[X + 4][Y] == AGUA) {

							if (matriz[X - 1][Y + 1] == AGUA
									&& matriz[X][Y + 1] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 2][Y + 1] == AGUA
									&& matriz[X + 3][Y + 1] == AGUA
									&& matriz[X + 4][Y + 1] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X][Y - 1] == AGUA
										&& matriz[X + 1][Y - 1] == AGUA
										&& matriz[X + 2][Y - 1] == AGUA
										&& matriz[X + 3][Y - 1] == AGUA
										&& matriz[X + 4][Y - 1] == AGUA) {
									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO8;

										matriz[X][Y] = BARCO8;
										matriz[X + 1][Y] = BARCO8;
										matriz[X + 2][Y] = BARCO8;
										matriz[X + 3][Y] = BARCO8;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO9;

										matriz[X][Y] = BARCO9;
										matriz[X + 1][Y] = BARCO9;
										matriz[X + 2][Y] = BARCO9;
										matriz[X + 3][Y] = BARCO9;
										break;

									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == AGUA && matriz[X][Y + 1] == AGUA
					&& matriz[X][Y + 2] == AGUA && matriz[X][Y + 3] == AGUA) {

				if (matriz[X][Y - 1] == AGUA) {

					if (Y + 4 <= 9) {
						if (matriz[X][Y + 4] == AGUA) {

							if (matriz[X + 1][Y - 1] == AGUA
									&& matriz[X + 1][Y] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 1][Y + 2] == AGUA
									&& matriz[X + 1][Y + 3] == AGUA
									&& matriz[X + 1][Y + 4] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X - 1][Y] == AGUA
										&& matriz[X - 1][Y + 1] == AGUA
										&& matriz[X - 1][Y + 2] == AGUA
										&& matriz[X - 1][Y + 3] == AGUA
										&& matriz[X - 1][Y + 4] == AGUA) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO8;

										matriz[X][Y] = BARCO8;
										matriz[X][Y + 1] = BARCO8;
										matriz[X][Y + 2] = BARCO8;
										matriz[X][Y + 3] = BARCO8;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO9;

										matriz[X][Y] = BARCO9;
										matriz[X][Y + 1] = BARCO9;
										matriz[X][Y + 2] = BARCO9;
										matriz[X][Y + 3] = BARCO9;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

void barcoTamanho3(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 3 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		printf("quebraLoop = %d\n", quebraLoop);
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = AGUA;
					matrizArmazem[i][j] = AGUA;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == AGUA && matriz[X + 1][Y] == AGUA
					&& matriz[X + 2][Y] == AGUA) {

				if (matriz[X - 1][Y] == AGUA) {

					if (X + 3 <= 9) {
						if (matriz[X + 3][Y] == AGUA) {

							if (matriz[X - 1][Y + 1] == AGUA
									&& matriz[X][Y + 1] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 2][Y + 1] == AGUA
									&& matriz[X + 3][Y + 1] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X][Y - 1] == AGUA
										&& matriz[X + 1][Y - 1] == AGUA
										&& matriz[X + 2][Y - 1] == AGUA
										&& matriz[X + 3][Y - 1] == AGUA) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO5;

										matriz[X][Y] = BARCO5;
										matriz[X + 1][Y] = BARCO5;
										matriz[X + 2][Y] = BARCO5;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO6;

										matriz[X][Y] = BARCO6;
										matriz[X + 1][Y] = BARCO6;
										matriz[X + 2][Y] = BARCO6;
										break;

									case 2:

										matrizArmazem[X][Y] = BARCO7;

										matriz[X][Y] = BARCO7;
										matriz[X + 1][Y] = BARCO7;
										matriz[X + 2][Y] = BARCO7;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == AGUA && matriz[X][Y + 1] == AGUA
					&& matriz[X][Y + 2] == AGUA) {

				if (matriz[X][Y - 1] == AGUA) {

					if (Y + 3 <= 9) {
						if (matriz[X][Y + 3] == AGUA) {

							if (matriz[X + 1][Y - 1] == AGUA
									&& matriz[X + 1][Y] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 1][Y + 2] == AGUA
									&& matriz[X + 1][Y + 3] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X - 1][Y] == AGUA
										&& matriz[X - 1][Y + 1] == AGUA
										&& matriz[X - 1][Y + 2] == AGUA
										&& matriz[X - 1][Y + 3] == AGUA) {
									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO5;

										matriz[X][Y] = BARCO5;
										matriz[X][Y + 1] = BARCO5;
										matriz[X][Y + 2] = BARCO5;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO6;

										matriz[X][Y] = BARCO6;
										matriz[X][Y + 1] = BARCO6;
										matriz[X][Y + 2] = BARCO6;
										break;

									case 2:

										matrizArmazem[X][Y] = BARCO7;

										matriz[X][Y] = BARCO7;
										matriz[X][Y + 1] = BARCO7;
										matriz[X][Y + 2] = BARCO7;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

void barcoTamanho2(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]) {
	int X, Y;
	int count = 0;
	int quebraLoop = 0;

	while (count != 4 && quebraLoop <= 15) {

		X = rand() % 10;
		Y = rand() % 10;

		quebraLoop++;
		if (quebraLoop == 15) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = AGUA;
					matrizArmazem[i][j] = AGUA;
				}
			}
		}
		while (X == 9 && Y == 9) {

			X = rand() % 10;
			Y = rand() % 10;

		}

		defineDirecao(direcao);

		if (*direcao == 1) {

			if (matriz[X][Y] == AGUA && matriz[X + 1][Y] == AGUA) {

				if (matriz[X - 1][Y] == AGUA) {

					if (X + 2 <= 9) {
						if (matriz[X + 2][Y] == AGUA) {

							if (matriz[X - 1][Y + 1] == AGUA
									&& matriz[X][Y + 1] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 2][Y + 1] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X][Y - 1] == AGUA
										&& matriz[X + 1][Y - 1] == AGUA
										&& matriz[X + 2][Y - 1] == AGUA) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO1;

										matriz[X][Y] = BARCO1;
										matriz[X + 1][Y] = BARCO1;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO2;

										matriz[X][Y] = BARCO2;
										matriz[X + 1][Y] = BARCO2;
										break;

									case 2:

										matrizArmazem[X][Y] = BARCO3;

										matriz[X][Y] = BARCO3;
										matriz[X + 1][Y] = BARCO3;
										break;

									case 3:

										matrizArmazem[X][Y] = BARCO4;

										matriz[X][Y] = BARCO4;
										matriz[X + 1][Y] = BARCO4;
										break;
									}

									quebraLoop = 0;
									count++;

								}
							}
						}
					}
				}
			}
		}

		if (*direcao == 2) {

			if (matriz[X][Y] == AGUA && matriz[X][Y + 1] == AGUA) {

				if (matriz[X][Y - 1] == AGUA) {

					if (Y + 2 <= 9) {
						if (matriz[X][Y + 2] == AGUA) {

							if (matriz[X + 1][Y - 1] == AGUA
									&& matriz[X + 1][Y] == AGUA
									&& matriz[X + 1][Y + 1] == AGUA
									&& matriz[X + 1][Y + 2] == AGUA) {

								if (matriz[X - 1][Y - 1] == AGUA
										&& matriz[X - 1][Y] == AGUA
										&& matriz[X - 1][Y + 1] == AGUA
										&& matriz[X - 1][Y + 2] == AGUA) {

									switch (count) {

									case 0:

										matrizArmazem[X][Y] = BARCO1;

										matriz[X][Y] = BARCO1;
										matriz[X][Y + 1] = BARCO1;
										break;

									case 1:

										matrizArmazem[X][Y] = BARCO2;

										matriz[X][Y] = BARCO2;
										matriz[X][Y + 1] = BARCO2;
										break;

									case 2:

										matrizArmazem[X][Y] = BARCO3;

										matriz[X][Y] = BARCO3;
										matriz[X][Y + 1] = BARCO3;
										break;

									case 3:

										matrizArmazem[X][Y] = BARCO4;

										matriz[X][Y] = BARCO4;
										matriz[X][Y + 1] = BARCO4;
										break;
									}

									count++;
									quebraLoop = 0;

								}
							}
						}
					}
				}
			}
		}
	}
}

int jogo(sf::RenderWindow *window) {
	srand(time(NULL));
	int dim = 50;
	int direcao = 0;
	int Chave = 0;

	int qntBombas = 60;
	int barcosAcertados = 0;
	int qntBarco = 0;

	Celulas matrizArmazem[10][10];

	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	sf::RectangleShape boxes[10][10];

	Celulas matriz[10][10];
	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			boxes[i][c] = criaTabela(i * dim, c * dim, dim, dim);
			matriz[i][c] = AGUA;
			matrizArmazem[i][c] = AGUA;
		}
	}

	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	sf::Texture textureBoomImage;
	sf::Sprite boomImage;

	sf::Texture textureXImage;
	sf::Sprite XImage;

	textureFundo.loadFromFile("assets/fundo.png");

	textureBoomImage.loadFromFile("assets/boom.png");
	textureBoomImage.setSmooth(true);

	textureXImage.loadFromFile("assets/xzinho.png");
	textureXImage.setSmooth(true);

	fundoImage.setTexture(textureFundo);

	boomImage.setTextureRect(sf::IntRect(0, 0, 50, 50));
	boomImage.setTexture(textureBoomImage, true);

	XImage.setTextureRect(sf::IntRect(0, 0, 50, 50));
	XImage.setTexture(textureXImage, true);

	float escala = (float) dim / textureXImage.getSize().x;
	boomImage.setScale(escala / 6.8, escala / 5.5);
	XImage.setScale(escala, escala);

	sf::SoundBuffer boomBuffer;
	sf::Sound boomSound;
	boomBuffer.loadFromFile("assets/boom.wav");
	boomSound.setBuffer(boomBuffer);

	sf::SoundBuffer splashBuffer;
	sf::Sound splashSound;
	splashBuffer.loadFromFile("assets/splash.wav");
	splashSound.setBuffer(splashBuffer);

	printf("matriz:\n");
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%d\t", matriz[i][j]);
		}
	}
	printf("\nmatrizArmazem:\n");
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%d\t", matrizArmazem[i][j]);
		}
	}

	while (window->isOpen()) {

		while (qntBarco != 8 + 9 + 8 + 5) {
			qntBarco = 0;

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					matriz[i][j] = AGUA;
					matrizArmazem[i][j] = AGUA;
				}
			}

			barcoTamanho5(&direcao, matriz, matrizArmazem);

			barcoTamanho4(&direcao, matriz, matrizArmazem);

			barcoTamanho3(&direcao, matriz, matrizArmazem);

			barcoTamanho2(&direcao, matriz, matrizArmazem);

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (matriz[i][j] != AGUA) {

						qntBarco++;
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			printf("\n");
			for (int j = 0; j < 10; j++) {
				printf("%d\t", matriz[i][j]);
			}
		}
		printf("\n");

		window->draw(fundoImage);

		trataEventos(window, matriz, &boomSound, &splashSound, dim, &Chave,
				&qntBombas);
		float x = sf::Mouse::getPosition(*window).x;
		float y = sf::Mouse::getPosition(*window).y;

		desenhaBlocos(*window, boxes, x, y, &Chave, matriz);
		desenhaImagem(*window, matriz, dim, boomImage, XImage, boxes, &Chave);

		barcosAcertados = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matriz[i][j] == MARCADO10 || matriz[i][j] == MARCADO9
						|| matriz[i][j] == MARCADO8 || matriz[i][j] == MARCADO7
						|| matriz[i][j] == MARCADO6 || matriz[i][j] == MARCADO5
						|| matriz[i][j] == MARCADO4 || matriz[i][j] == MARCADO3
						|| matriz[i][j] == MARCADO2
						|| matriz[i][j] == MARCADO1) {
					barcosAcertados++;
				}
			}
		}

		window->display();
		window->clear();

		if (qntBombas == 0) {

			perde(window);
		}

		if (barcosAcertados == 30) {
			vence(window);
		}

	}
	return 0;
}
