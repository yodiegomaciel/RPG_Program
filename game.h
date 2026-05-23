#include <iostream>
#include <string>

using namespace std;

class Personagem
{
public:
    Personagem(string nome, int ataque, int defesa, int velocidade, int vida);
    string setNome( string );
    int setAtaque( int );
    int setDefesa( int );
    int setVelocidade( int );
    int setVida( int );
    void atacarP( int);
    void receberDanoP( int);
    int getAtaque();
    int getDefesa();
    int getVelocidade();
    int getVida();
    int danoPersonagem();
    int vidaPersonagem();
    int ataqueRealP();
    int danoRealP();

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
    string setNome( string );
    int setAtaque( int );
    int setDefesa( int );
    int setVelocidade( int );
    int setVida( int );
    void atacarM( int );
    void receberDanoM( int );
    int getAtaque();
    int getDefesa();
    int getVelocidade();
    int getVida();
    int vidaMonstro( int );
    int danoMonstro ( int );
    int ataqueRealM (int );
    int danoRealM ( int );

private:
    string nome;
    int ataque;
    int defesa;
    int velocidade;
    int vida;
};

/*class Gerenciador
{
public:
    void Start(boolean gameOn);
    void Pause(boolean pause);

private:
    boolean gameOn;
    boolean pause;
};
*/
