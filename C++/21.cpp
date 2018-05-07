#include <stdio.h>
#include <stdlib.h>
#include <iostream>//evolução da stdio.h - Substitui completamente
#include <string>
#include <iterator>
#include <stdlib.h>
#include <random>



using  namespace std;

/*
Variáveis globais
*/
int somaPontuacao(string baralhoASomar[][2]);
void adicionaCartaJogador(string jogador[][2]);
void exibeBaralho(string baralhoAExibir[][2]);
/*
criação do baralho com vetor bidimensional, armazena nome da carta em string e o respectivo valor em pontos.
Onde a primeira dimensão é o nome da carta em string, a segunda dimensão é o valor respectivo da carta.
Ex: baralho [0][0] - informa "Ás de copas" --------- baralho [0][1] - informa o valor 1
Obs: Sempre que o segundo índice for zero representa o nome da carta e sempre que o segundo índice for 1 representa o valor.
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

int main(){
//Teste de cópia de uma carta do baralho pro baralho do jogador
//Copiando o nome da carta do baralho pro jogador -> jogadorHumano[0][0] = Baralho[0][0]
//jogadorHumano[0][0] = baralho[0][0];
//Copiando o valor da carta do baralho pro jogador -> jogadorHumano[0][1] = Baralho[0][1]
//jogadorHumano[0][1] = baralho[0][1];
//adicionando apenas valores ao baralho do jogador humano
//jogadorHumano[1][0] = baralho[35][0];
//jogadorHumano[1][1] = baralho[35][1];
//jogadorHumano[2][0] = baralho[23][0];
//jogadorHumano[5][0] = baralho[23][0];
//jogadorHumano[5][1] = baralho[23][1];

//Atribuindo o valor da carta do baralho do jogador, a sua variável pontos. O método atoi é pra converter a string em inteiro
//pontuacaoJogadorHumano += atoi(jogadorHumano[0][1].c_str());

//cout << pontuacaoJogadorHumano << endl;

//Adicionando 3 cartas ao jogador humano

//Adicionando 3 cartas ao jogador maquina

//adicionaCartaJogador(jogadorHumano);
adicionaCartaJogador(jogadorHumano);
adicionaCartaJogador(jogadorHumano);
adicionaCartaJogador(jogadorMaquina);
adicionaCartaJogador(jogadorMaquina);
//adicionaCartaJogador(jogadorMaquina);
//adicionaCartaJogador(jogadorMaquina);


//Atribuindo o resultado da função somaPontuacao a variável pontuação do jogador humano
pontuacaoJogadorHumano = somaPontuacao(jogadorHumano);
pontuacaoJogadorMaquina = somaPontuacao(jogadorMaquina);

exibeBaralho(jogadorHumano);
cout <<"Valor de pontos do jogador humano é: " << pontuacaoJogadorHumano << endl;

cout <<"---------------------------------" << endl;

exibeBaralho(jogadorMaquina);
cout <<"Valor de pontos do jogador máquina é: " << pontuacaoJogadorMaquina << endl;

//prints
//cout << jogadorHumano[1][0] << endl;
//cout << jogadorHumano[2][0] << endl;
//cout << jogadorHumano[3][0] << endl;

}

//Função que recebe um array bidimensional baralho e soma os valores das cartas no seu baralho
int somaPontuacao(string baralhoASomar[][2]){
    int totalPontos = 0;

    for(int i=0; i<=53; i++){

        if(baralhoASomar[i][1] != ""){
            totalPontos += atoi(baralhoASomar[i][1].c_str());
        }
    }

    return totalPontos;
}

//Função incompleta que adiciona carta ao baralho de um jogador
void adicionaCartaJogador(string jogador[][2]){
//Gerando um índice aleatório
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1,53);
    auto random_integer = uni(rng);
//exibe o inteiro aleatório gerado
//cout << "Inteiro aleatório gerado: " << random_integer << endl;

    string nomeCarta[53][2];
    string valorCarta[53][2];

    nomeCarta[0][0] = baralho[random_integer][0];
    valorCarta[0][1] = baralho[random_integer][1];


//    cout << nomeCarta[0][0] << " - " << valorCarta[0][1]  << endl;

    for (int i=0; i<=53; i++){
        if(jogador[i][0] == "" & jogador[i][1] == ""){
            jogador[i][0] = nomeCarta[0][0];
            jogador[i][1] = valorCarta[0][1];
            return;
        }
    }

}

//Função que exibe as cartas e seus respectivos pontos de um baralho
void exibeBaralho(string baralhoAExibir[][2]){

    for(int i=0; i<=53; i++){
        if(baralhoAExibir[i][0] != "" && baralhoAExibir[i][1] !=""){
            cout << baralhoAExibir[i][0] << " - " << baralhoAExibir[i][1] << endl;
        }
    }

}
