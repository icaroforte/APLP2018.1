#include <stdio.h>
#include <stdlib.h>
#include <iostream>//evolução da stdio.h - Substitui completamente
#include <string>
#include <iterator>
#include <stdlib.h>
#include <random>



using  namespace std;

/*
Funções
*/
int somaPontuacao(string baralhoASomar[][2]);
void adicionaCartaJogador(string jogador[][2]);
void exibeBaralho(string baralhoAExibir[][2]);
int geraValorAleatorio();

/*
Variáveis globais
*/
/*
criação do baralho com vetor bidimensional, armazena nome da carta em string e o respectivo valor em pontos.
Onde a primeira dimensão é o nome da carta em string, a segunda dimensão é o valor respectivo da carta.
Ex: baralho [0][0] - informa "Ás de copas" --------- baralho [0][1] - informa o valor 1
Obs: Sempre que o segundo índice for zero representa o nome da carta e sempre que o segundo índice for 1 representa o valor.
*/
std::string baralho[52][2] = {
    {"Ás de copas","1"},//0
    {"Ás de espadas","1"},//1
    {"Ás de ouro","1"},//2
    {"Ás de paus","1"},//3
    {"Dois de copas","2"},//4
    {"Dois de espadas","2"},//5
    {"Dois de ouro","2"},//6
    {"Dois de paus","2"},//7
    {"Três de copas","3"},//8
    {"Três de espadas","3"},//9
    {"Três de ouro","3"},//10
    {"Três de paus","3"},//11
    {"Quatro de copas","4"},//12
    {"Quatro de espadas","4"},//13
    {"Quatro de ouro","4"},//14
    {"Quatro de paus","4"},//15
    {"Cinco de copas","5"},//16
    {"Cinco de espadas","5"},//17
    {"Cinco de ouro","5"},//18
    {"Cinco de paus","5"},//19
    {"Seis de copas","6"},//20
    {"Seis de espadas","6"},//21
    {"Seis de ouro","6"},//22
    {"Seis de paus","6"},//23
    {"Sete de copas","7"},//24
    {"Sete de espadas","7"},//25
    {"Sete de ouro","7"},//26
    {"Sete de paus","7"},//27
    {"Oito de copas","8"},//28
    {"Oito de espadas","8"},//29
    {"Oito de ouro","8"},//30
    {"Oito de paus","8"},//31
    {"Nove de copas","9"},//32
    {"Nove de espadas","9"},//33
    {"Nove de ouro","9"},//34
    {"Nove de paus","9"},//35
    {"Dez de copas","10"},//36
    {"Dez de espadas","10"},//37
    {"Dez de ouro","10"},//38
    {"Dez de paus","10"},//39
    {"Valete de copas","10"},//40
    {"Valete de espadas","10"},//41
    {"Valete de ouro","10"},//42
    {"Valete de paus","10"},//43
    {"Dama de copas","10"},//44
    {"Dama de espadas","10"},//45
    {"Dama de ouro","10"},//46
    {"Dama de paus","10"},//47
    {"Rei de copas","10"},//48
    {"Rei de espadas","10"},//49
    {"Rei de ouro","10"},//50
    {"Rei de paus","10"}//51
};

//Baralho do jogador Humano
string jogadorHumano [52][2];
//Baralho do jogador Maquina
string jogadorMaquina [52][2];
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
adicionaCartaJogador(jogadorHumano);
adicionaCartaJogador(jogadorHumano);
adicionaCartaJogador(jogadorHumano);

//Adicionando 3 cartas ao jogador maquina
adicionaCartaJogador(jogadorMaquina);
adicionaCartaJogador(jogadorMaquina);
adicionaCartaJogador(jogadorMaquina);


//Atribuindo o resultado da função somaPontuacao a variável pontuação do jogador humano e máquina
pontuacaoJogadorHumano = somaPontuacao(jogadorHumano);
pontuacaoJogadorMaquina = somaPontuacao(jogadorMaquina);

exibeBaralho(jogadorHumano);
cout <<"Valor de pontos do jogador humano é: " << pontuacaoJogadorHumano << endl;

cout <<"---------------------------------------------------" << endl;

exibeBaralho(jogadorMaquina);
cout <<"Valor de pontos do jogador máquina é: " << pontuacaoJogadorMaquina << endl;



//exibeBaralho(baralho);

//prints
//cout << jogadorHumano[1][0] << endl;
//cout << jogadorHumano[2][0] << endl;
//cout << jogadorHumano[3][0] << endl;

}

//Função que recebe um array bidimensional baralho e soma os valores das cartas no seu baralho
int somaPontuacao(string baralhoASomar[][2]){
    int totalPontos = 0;

    for(int i=0; i<=52; i++){

        if(baralhoASomar[i][1] != ""){
            totalPontos += atoi(baralhoASomar[i][1].c_str());
        }
    }

    return totalPontos;
}

//Função que retorna um valor aleatório entre [0,51]
int geraValorAleatorio(){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,51);
    auto random_integer = uni(rng);
    return random_integer;
}


//Função que adiciona carta ao baralho de um jogador sem repetição
void adicionaCartaJogador(string jogador[][2]){

//Gerando um índice aleatório
    int valorAleatorio = geraValorAleatorio();
//Este WHILE serve para que se a posição random no baralho principal esteja vazia (já tenha sido usada), ele gera um novo número random.
    while(baralho[valorAleatorio][0] == ""){
        valorAleatorio = geraValorAleatorio();
    }
//cout << "Inteiro aleatório gerado: " << valorAleatorio << endl;

    string nomeCarta;
    string valorCarta;
//Recebe o nome e o valor da carta do baralho principal;
    nomeCarta = baralho[valorAleatorio][0];
    valorCarta = baralho[valorAleatorio][1];
/*Este FOR serve para atribuir o nome e o valor da carta do baralho a primeira posição vazia encontrada no
baralho do jogador. Ao mesmo tempo, "deleta" a carta do baralho principal para que não possa ser usada mais de uma vez.
*/
    for (int i=1; i<=52; i++){
        if(jogador[i][0] == "" & jogador[i][1] == ""){
            jogador[i][0] = nomeCarta;
            jogador[i][1] = valorCarta;
            //"deletando" a carta do baralho principal já que ele agora pertence ao jogador
            baralho[valorAleatorio][0] = "";
            baralho[valorAleatorio][1] = "";
            return;
        }
    }

}

//Função que exibe as cartas e seus respectivos pontos de um baralho
void exibeBaralho(string baralhoAExibir[][2]){

    for(int i=0; i<=52; i++){
        if(baralhoAExibir[i][0] != "" && baralhoAExibir[i][1] !=""){
            cout << baralhoAExibir[i][0] << " - " << baralhoAExibir[i][1] << endl;
        }
    }

}
