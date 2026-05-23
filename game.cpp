#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "game.h"

Personagem::Personagem(string nome,int ataque, int defesa, int velocidade, int vida)
{
    setNome ( nome );
    setAtaque ( ataque );
    setDefesa ( defesa );
    setVelocidade ( velocidade );
    setVida ( vida );
}

int Personagem::setAtaque(int ataque)
{
    this->ataque = ataque;
}

int Personagem::setDefesa(int defesa)
{
    this->defesa = defesa;
}

int Personagem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

int Personagem::setVida(int vida)
{
    this->vida = vida;
}

void Personagem::receberDanoP(int danoMonstro)
{
    int danoRealP = danoMonstro - this->defesa;
    
    if (danoRealP < 0)
        danoRealP = 0;
    this->vida;
}

void Personagem::atacarP(int vidaMonstro)
{
    int ataqueRealP = vidaMonstro - this->ataque;
}

int Personagem::getAtaque()
{
    return ataque;
}

int Personagem::getDefesa()
{
    return defesa;
}

int Personagem::getVelocidade()
{
    return velocidade;
}

int Personagem::getVida()
{
    return vida;
}

Monstro::Monstro(string nome,int ataque, int defesa, int velocidade, int vida)
{
    setNome ( nome );
    setAtaque ( ataque );
    setDefesa ( defesa );
    setVelocidade ( velocidade );
    setVida ( vida );
}

int Monstro::setAtaque(int ataque)
{
    this->ataque = ataque;
}

int Monstro::setDefesa(int defesa)
{
    this->defesa = defesa;
}

int Monstro::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

int Monstro::setVida(int vida)
{
    this->vida = vida;
}

void Monstro::receberDanoM(int danoPersonagem)
{
    int danoRealM = danoPersonagem - this->defesa;
    
    if (danoRealM < 0)
        danoRealM = 0;
    this->vida;
}

void Monstro::atacarM(int vidaPersonagem)
{
    int ataqueRealM = vidaPersonagem - this->ataque;
}

int Monstro::getAtaque()
{
    return ataque;
}

int Monstro::getDefesa()
{
    return defesa;
}

int Monstro::getVelocidade()
{
    return velocidade;
}

int Monstro::getVida()
{
    return vida;
}
