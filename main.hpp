#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <iostream>

sf::RectangleShape criaRetangulo(int x, int y, int width, int height);

enum Conceitos {
	Ok, Vertical, Horizontal
};

enum Celulas {
	AGUA,
	BOOM,
	ERROU,
	BARCO1,
	BARCO2,
	BARCO3,
	BARCO4,
	BARCO5,
	BARCO6,
	BARCO7,
	BARCO8,
	BARCO9,
	BARCO10,
	MARCADO1,
	MARCADO2,
	MARCADO3,
	MARCADO4,
	MARCADO5,
	MARCADO6,
	MARCADO7,
	MARCADO8,
	MARCADO9,
	MARCADO10,
};

void trataEventos(sf::RenderWindow *window, Celulas matriz[10][10],
		sf::Sound *boomSound, sf::Sound *splashSound, int dim, int *Ch,
		int *qntBombas);

void desenhaBlocos(sf::RenderWindow &window, sf::RectangleShape boxes[10][10],
		float x, float y);

void desenhaImagem(sf::RenderWindow &window, Celulas matriz[10][10], int dim,
		sf::Sprite boomImage, sf::Sprite XImage);

void defineDirecao(int *direcao);

void barcoTamanho5(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10], sf::RenderWindow *window);
void barcoTamanho4(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]);
void barcoTamanho3(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]);
void barcoTamanho2(int *direcao, Celulas matriz[10][10],
		Celulas matrizArmazem[10][10]);

void loopEventos(sf::RenderWindow *janela, Celulas matriz[10][10],
		sf::Sound *boomSound, sf::Sound *splashSound, int dim);

void desenhaTabela(sf::RenderWindow &janela, sf::RectangleShape tabela[10][10],
		float x, float y);

void Volume(sf::RenderWindow *window, sf::Texture *Sound, float x, float y,
		sf::RectangleShape *SoundArea, int *Ch, sf::Sound *boomSound,
		sf::Sound *splashSound, sf::Sound *FundoSound);

int jogo(sf::RenderWindow *window);
