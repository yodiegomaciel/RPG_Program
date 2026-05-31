#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "game.h"

using namespace std;

int main() {
    bool gameOn = true;
    int monstros_gerados = 0;
    srand(time(0));

    // Heróis
    vector<Personagem> listaHerois;
    listaHerois.push_back(Personagem("Guerreiro", 15, 10, 10, 50));
    listaHerois.push_back(Personagem("Mago", 25, 5, 5, 30));
    listaHerois.push_back(Personagem("Gigante", 10, 20, 1, 80));

    // Sorteando o primeiro monstro
    int vidaAleatoria = rand() % (60 - 30 + 1) + 30; 
    int ataqueAleatorio = rand() % (18 - 8 + 1) + 8;
    int defesaAleatoria = rand() % (8 - 2 + 1) + 2;
    int velAleatoria = rand() % (12 - 5 + 1) + 5;

    Monstro inimigo("Demogorgon", ataqueAleatorio, defesaAleatoria, velAleatoria, vidaAleatoria);

    // Herói "vazio" temporário só para o C++ criar a variável
    Personagem heroi("Temp", 0, 0, 0, 0); 
    bool heroiNaArena = false; // Controla se temos um herói lutando no momento

    cout << "=== BEM VINDO AO RPG ===" << endl;
    cout << "\nVoce encontrou o inimigo " << inimigo.getNome() << "!" << endl;

    // Loop principal de batalha
    while (gameOn) {
        
        // ==========================================
        // SISTEMA DE TROCA DE HERÓI
        // ==========================================
        if (!heroiNaArena) {
            // Verifica se a equipe toda morreu
            if (listaHerois.empty()) {
                cout << "\nTodos os seus herois foram derrotados..." << endl;
                cout << "=== FIM DE JOGO ===" << endl;
                gameOn = false;
                continue; // Pula para o fim do loop e encerra o jogo
            }

            cout << "\n=== ESCOLHA QUEM VAI LUTAR ===" << endl;
            // Imprime apenas os heróis que ainda estão vivos na lista
            for (size_t i = 0; i < listaHerois.size(); i++) {
                cout << i + 1 << " - " << listaHerois[i].getNome() 
                     << " (Vida: " << listaHerois[i].getVida() << ")" << endl;
            }
            cout << "> ";
            
            int escolha;
            cin >> escolha;

            // Validação
            if (escolha < 1 || escolha > listaHerois.size()) {
                cout << "Escolha invalida! Tente novamente." << endl;
                continue; // Repete o while para escolher de novo
            }

            // Coloca o herói escolhido na arena
            heroi = listaHerois[escolha - 1];
            heroiNaArena = true;

            // REMOVE o herói da lista de reservas (para não escolher de novo)
            listaHerois.erase(listaHerois.begin() + (escolha - 1));

            cout << "\n" << heroi.getNome() << " entrou na batalha!" << endl;
        }

        // ==========================================
        // SISTEMA DE COMBATE
        // ==========================================
        cout << "\n--- STATUS ---" << endl;
        heroi.exibirStatus();
        inimigo.exibirStatus();

        int acao;
        cout << "\nO que voce deseja fazer?\n1 - Atacar\n2 - Defender\n> ";
        cin >> acao;

        bool heroiAtacaPrimeiro = (heroi.getVelocidade() >= inimigo.getVelocidade());

        if (heroiAtacaPrimeiro) {
            if (acao == 1) {
                cout << "\n[RAPIDO] Voce atacou o " << inimigo.getNome() << " primeiro!" << endl;
                inimigo.receberDano(heroi.getAtaque());
            } else if (acao == 2) {
                cout << "\n[RAPIDO] Voce se preparou para defender!" << endl;
            } else {
                cout << "\nOpcao invalida, voce perdeu a vez!" << endl;
            }

            if (inimigo.getVida() > 0) {
                cout << "O " << inimigo.getNome() << " atacou em seguida!" << endl;
                heroi.receberDano(inimigo.getAtaque());
            }
        } 
        else {
            cout << "\n[RAPIDO] O " << inimigo.getNome() << " foi mais rapido e atacou primeiro!" << endl;
            heroi.receberDano(inimigo.getAtaque());

            if (heroi.getVida() > 0) {
                if (acao == 1) {
                    cout << "Voce resistiu e revidou o ataque!" << endl;
                    inimigo.receberDano(heroi.getAtaque());
                } else if (acao == 2) {
                    cout << "Voce tentou se defender do ataque!" << endl;
                } else {
                    cout << "Opcao invalida, voce perdeu a vez!" << endl;
                }
            }
        }

        // ==========================================
        // RESOLUÇÃO DO TURNO
        // ==========================================
        
        // Se o herói morreu
        if (heroi.getVida() <= 0) {
            cout << "\n--- STATUS ---" << endl;
            heroi.exibirStatus();
            cout << "\nO seu " << heroi.getNome() << " caiu em combate!" << endl;
            heroiNaArena = false; // Isso vai acionar o menu de escolha no próximo turno
        }
        // Se o monstro morreu
        else if (inimigo.getVida() <= 0) {
            monstros_gerados++;
            
            if (monstros_gerados >= 2) { 
                cout << "\nVoce derrotou a horda inimiga! PARABENS! VOCE VENCEU O JOGO!" << endl;
                gameOn = false; 
            } 
            else {
                cout << "\nVoce derrotou o inimigo! Mas outro monstro se aproxima..." << endl;
                
                int vidaAleatoria = rand() % (60 - 30 + 1) + 30; 
                int ataqueAleatorio = rand() % (18 - 8 + 1) + 8;
                int defesaAleatoria = rand() % (8 - 2 + 1) + 2;
                int velAleatoria = rand() % (12 - 5 + 1) + 5;

                inimigo = Monstro("Demogorgon", ataqueAleatorio, defesaAleatoria, velAleatoria, vidaAleatoria);
            }
        }
    }

    return 0;
}
