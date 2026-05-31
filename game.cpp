#include "game.h"

// ================= CLASSE PERSONAGEM =================
Personagem::Personagem(string nome,int ataque, int defesa, int velocidade, int vida)
{
    setNome ( nome );
    setAtaque ( ataque );
    setDefesa ( defesa );
    setVelocidade ( velocidade );
    setVida ( vida );
}

void Personagem::setNome(string nome) { this->nome = nome; }
void Personagem::setAtaque(int ataque) { this->ataque = ataque; }
void Personagem::setDefesa(int defesa) { this->defesa = defesa; }
void Personagem::setVelocidade(int velocidade) { this->velocidade = velocidade; }
void Personagem::setVida(int vida) { this->vida = vida; }

string Personagem::getNome() { return nome; }
int Personagem::getAtaque() { return ataque; }
int Personagem::getDefesa() { return defesa; }
int Personagem::getVelocidade() { return velocidade; }
int Personagem::getVida() { return vida; }

void Personagem::receberDano(int danoMonstro) {
    int danoReal = danoMonstro - this->defesa;
    
    if (danoReal < 0) {
        danoReal = 0; // A defesa absorveu tudo
    }
    
    this->vida -= danoReal; // Subtrai a vida
    
    if (this->vida < 0) {
        this->vida = 0; // Impede vida negativa
    }
}

void Personagem::exibirStatus() {
    cout << "[" << nome << "] Vida: " << vida << " | Ataque: " << ataque 
         << " | Defesa: " << defesa << " | Velocidade: " << velocidade << endl;
}

// ================= CLASSE MONSTRO =================

Monstro::Monstro(string nome, int ataque, int defesa, int velocidade, int vida) {
    setNome(nome);
    setAtaque(ataque);
    setDefesa(defesa);
    setVelocidade(velocidade);
    setVida(vida);
}

void Monstro::setNome(string nome) { this->nome = nome; }
void Monstro::setAtaque(int ataque) { this->ataque = ataque; }
void Monstro::setDefesa(int defesa) { this->defesa = defesa; }
void Monstro::setVelocidade(int velocidade) { this->velocidade = velocidade; }
void Monstro::setVida(int vida) { this->vida = vida; }

string Monstro::getNome() { return nome; }
int Monstro::getAtaque() { return ataque; }
int Monstro::getDefesa() { return defesa; }
int Monstro::getVelocidade() { return velocidade; }
int Monstro::getVida() { return vida; }

void Monstro::receberDano(int danoPersonagem) {
    int danoReal = danoPersonagem - this->defesa;
    
    if (danoReal < 0) {
        danoReal = 0;
    }
    
    this->vida -= danoReal;
    
    if (this->vida < 0) {
        this->vida = 0;
    }
}

void Monstro::exibirStatus() {
    cout << "[" << nome << "] Vida: " << vida << " | Ataque: " << ataque << endl;
}
