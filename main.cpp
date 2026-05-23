#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

#include "game.h"

int main()
{
    unsigned seed = time(0);
    srand(seed);
    cout << rand() << endl;

    std::vector<Personagem> listaHerois;
    Personagem Personagem1("Guerreiro", 5, 10, 10, 20);
    listaHerois.push_back(Personagem1);
    Personagem Personagem2("Mago", 10, 5, 5, 15);
    listaHerois.push_back(Personagem2);
    Personagem Personagem3("Gigante", 3, 30, 1, 40);
    listaHerois.push_back(Personagem3);
    Monstro Monstro(rand());

    int tamanho = listaHerois.size();
    listaHerois[0].exibirStatus();
    listaHerois.erase(listaHerois.begin() + i);

    int escolhaPersonagem;
    int escolha;

    while (true)
    {
        cout << "Menu\n 1 para Guerreiro\n 2 para Mago \n 3 para Gigante" << endl;
        cin >> escolhaPersonagem;
        
        if (escolhaPersonagem == 1)
        {
            cout << "1 para atacar\n 2 para defender";
            cin >> escolha;

            if (escolha == 1 | Personagem1.getVelocidade() > Monstro.getVelocidade())
            {
                Personagem1.atacarP();
            }
            else if
            {
                Monstro.atacarM();
            }
            else
            {
                cout << "Opcao invalida" << endl;
                break;
            }

        if (escolhaPersonagem == 2)
        {
            cout << "1 para atacar\n 2 para defender";
            cin >> escolha;

            if (escolha == 2 | Personagem2.getVelocidade() > Monstro.getVelocidade())
            {
                Personagem2.atacarP();
            }
            else if
            {
                Monstro.atacarM();
            }
            else
            {
                cout << "Opcao invalida" << endl;
                break;
            }
        }

        if (escolhaPersonagem == 3)
        {
            cout << "1 para atacar\n 2 para defender";
            cin >> escolha;

            if (escolha == 3 | Personagem1.getVelocidade() > Monstro.getVelocidade())
            {
                Personagem3.atacarP();
            }
            else if
            {
                Monstro.atacarM();
            }
            else
            {
                cout << "Opcao invalida" << endl;
                break;
            }
    }
    return 0;
}