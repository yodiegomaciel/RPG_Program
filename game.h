#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

class Personagem
{
public:
    Personagem(string nome, int ataque, int defesa, int velocidade, int vida);

    // Setters
    void setNome(string);
    void setAtaque(int);
    void setDefesa(int);
    void setVelocidade(int);
    void setVida(int);
    
    // Getters
    string getNome();
    int getAtaque();
    int getDefesa();
    int getVelocidade();
    int getVida();
    
    // Ações
    void receberDano(int danoMonstro);
    void exibirStatus();

private:
    string nome;
    int ataque;
    int defesa;
    int velocidade;
    int vida;
};

class Monstro
{
public:
    Monstro(string nome, int ataque, int defesa, int velocidade, int vida);

    // Setters
    void setNome(string);
    void setAtaque(int);
    void setDefesa(int);
    void setVelocidade(int);
    void setVida(int);
    
    // Getters
    string getNome();
    int getAtaque();
    int getDefesa();
    int getVelocidade();
    int getVida();

    // Ações
    void receberDano(int danoPersonagem);
    void exibirStatus();

private:
    string nome;
    int ataque;
    int defesa;
    int velocidade;
    int vida;
};

#endif
