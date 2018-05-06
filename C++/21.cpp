#include <stdio.h>
#include <stdlib.h>
#include <iostream>//evolução da stdio.h - Substitui completamente
#include <string>
#include <iterator>


using  namespace std;

int main(){

/*
criação do baralho com vetor bidimensional, armazena nome da carta em string e o respectivo valor em pontos.
Onde a primeira dimensão é o nome da carta em string, a segunda dimensão é o valor respectivo da carta.
*/
std::string baralho[53][2] = {
    {"Ás de copas","1"},
    {"Ás de espadas","1"},
    {"Ás de ouro","1"},
    {"Ás de paus","1"},
    {"Dois de copas","2"},
    {"Dois de espadas","2"},
    {"Dois de ouro","2"},
    {"Dois de paus","2"},
    {"Três de copas","3"},
    {"Três de espadas","3"},
    {"Três de ouro","3"},
    {"Três de paus","3"},
    {"Quatro de copas","4"},
    {"Quatro de espadas","4"},
    {"Quatro de ouro","4"},
    {"Quatro de paus","4"},
    {"Cinco de copas","5"},
    {"Cinco de espadas","5"},
    {"Cinco de ouro","5"},
    {"Cinco de paus","5"},
    {"Seis de copas","6"},
    {"Seis de espadas","6"},
    {"Seis de ouro","6"},
    {"Seis de paus","6"},
    {"Sete de copas","7"},
    {"Sete de espadas","7"},
    {"Sete de ouro","7"},
    {"Sete de paus","7"},
    {"Oito de copas","8"},
    {"Oito de espadas","8"},
    {"Oito de ouro","8"},
    {"Oito de paus","8"},
    {"Nove de copas","9"},
    {"Nove de espadas","9"},
    {"Nove de ouro","9"},
    {"Nove de paus","9"},
    {"Dez de copas","10"},
    {"Dez de espadas","10"},
    {"Dez de ouro","10"},
    {"Dez de paus","10"},
    {"Valete de copas","10"},
    {"Valete de espadas","10"},
    {"Valete de ouro","10"},
    {"Valete de paus","10"},
    {"Dama de copas","10"},
    {"Dama de espadas","10"},
    {"Dama de ouro","10"},
    {"Dama de paus","10"},
    {"Dama de paus","10"},
    {"Rei de copas","10"},
    {"Rei de espadas","10"},
    {"Rei de ouro","10"},
    {"Rei de paus","10"}
};

//Baralho do jogador Humano
string jogadorHumano [53][2];
//Baralho do jogador Maquina
string jogadorMaquina [53][2];

//Pontuação do jogador Humano
int pontuacaoJogadorHumano = 0;
//Pontuação do jogador Máquina
int pontuacaoJogadorMaquina = 0;

//Teste de cópia de uma carta do baralho pro baralho do jogador
//Copiando o nome da carta do baralho pro jogador -> jogadorHumano[0][0] = Baralho[0][0]
jogadorHumano[0][0] = baralho[0][0];

//Copiando o valor da carta do baralho pro jogador -> jogadorHumano[0][1] = Baralho[0][1]
jogadorHumano[0][1] = baralho[0][1];

//Atribuindo o valor da carta do baralho do jogador, a sua variável pontos. O método atoi é pra converter a string em inteiro
pontuacaoJogadorHumano += atoi(jogadorHumano[0][1].c_str());

//prints
cout << baralho[0][0] << endl;
cout << baralho[1][0] << endl;
cout << baralho[2][0] << endl;
cout << baralho[3][0] << endl;
cout << pontuacaoJogadorHumano << endl;


}

