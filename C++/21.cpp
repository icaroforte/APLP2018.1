#include <stdio.h>
#include <stdlib.h>
#include <iostream>//evolução da stdio.h - Substitui completamente
#include <random>
#include <string>
#include <iterator>
#include <stdlib.h>




using  namespace std;

/*
Funções
*/
int escolheDificuldade();
void iniciarPartida();
bool jogadaDaIA(int dificuldade);
int somaPontuacao(string baralhoASomar[][2]);
void puxarDoBaralho(string jogador[][2]);
void puxarDoMonte(string jogadorAtual[][2]);
void puxarCarta(string jogadorAtual[][2]);
void descartarCarta(string jogadorAtual[][2]);
void trocarJogador();
int exibeBaralho(string baralhoAExibir[][2]);
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
string humano = "jogadorHumano";
//Baralho do jogador Maquina
string jogadorMaquina [52][2];
string maquina = "jogadorMaquina";
//Monte onde fica as cartas descartadas
string monte [52][2];
//Jogador da vez
string jogadorAtual = humano;
//Pontuação do jogador Humano
int pontuacaoJogadorHumano = 0;
//Pontuação do jogador Máquina
int pontuacaoJogadorMaquina = 0;

int main(){
int dificuldade = escolheDificuldade();
iniciarPartida();

while(pontuacaoJogadorHumano != 21 & pontuacaoJogadorMaquina != 21){
    if(jogadorAtual.compare(humano) == 0){
        puxarCarta(jogadorHumano);
        descartarCarta(jogadorHumano);
        trocarJogador();
    }else{
        jogadaDaIA(dificuldade);
        trocarJogador();
    }

    cout << "\n" << endl;
    exibeBaralho(jogadorHumano);
    cout <<"Valor de pontos do jogador humano é: " << pontuacaoJogadorHumano << endl;

    cout <<"---------------------------------------------------" << endl;

    exibeBaralho(jogadorMaquina);
    cout <<"Valor de pontos do jogador máquina é: " << pontuacaoJogadorMaquina << endl;
}

//exibeBaralho(baralho);

//prints
//cout << jogadorHumano[1][0] << endl;
//cout << jogadorHumano[2][0] << endl;
//cout << jogadorHumano[3][0] << endl;

}

int escolheDificuldade(){
    cout << "   Bem vindo ao jogo 21! \n " << endl;
    cout << "Escolha a dificuldade da partida: \n1 - Fácil \n2 - Médio \n3 - Difícil " << endl;

    string escolhaMenu;

    cout << "Por favor escolha 1, 2 ou 3: \n";
    cin >> escolhaMenu;

    //Loop para forçar uma escolha válida do menu
    while (escolhaMenu != "1" & escolhaMenu != "2" & escolhaMenu != "3"){
        cout << "Opção inválida, por favor escolha 1, 2 ou 3: \n";
        cin >> escolhaMenu;
    }

    //Transformando a string dificuldade em um valor int
    int dificuldade = atoi(escolhaMenu.c_str());

    switch (dificuldade){
        case 1:
            cout <<"\nDificuldade escolhida é: Fácil\n" << endl;
            break;

        case 2:
            cout <<"\nDificuldade escolhida é: Médio" << endl;
            break;

        case 3:
            cout <<"\nDificuldade escolhida é: Difícil" << endl;
            break;
    }
    return dificuldade;
}

void iniciarPartida(){
    //Adicionando 3 cartas ao jogador humano
    puxarDoBaralho(jogadorHumano);
    puxarDoBaralho(jogadorHumano);
    puxarDoBaralho(jogadorHumano);

    //Adicionando 3 cartas ao jogador maquina
    puxarDoBaralho(jogadorMaquina);
    puxarDoBaralho(jogadorMaquina);
    puxarDoBaralho(jogadorMaquina);

    //Atribuindo o resultado da função somaPontuacao a variável pontuação do jogador humano e máquina
    pontuacaoJogadorHumano = somaPontuacao(jogadorHumano);
    pontuacaoJogadorMaquina = somaPontuacao(jogadorMaquina);

    exibeBaralho(jogadorHumano);
    cout <<"Valor de pontos do jogador humano é: " << pontuacaoJogadorHumano << endl;

    cout <<"---------------------------------------------------" << endl;

    exibeBaralho(jogadorMaquina);
    cout <<"Valor de pontos do jogador máquina é: " << pontuacaoJogadorMaquina << endl;
}

bool jogadaDaIA(int dificuldade){
    //estratégia para o random ficar melhor
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

    //gerando um valor aleatório de [0,100]
    int random = (rand() % 100) + 1;
    //cout << "valor random " << random << endl;

    switch(dificuldade){
        /*
            Caso 1 - Fácil, independente do valor na mão da máquina, ela sempre vai ter 50% de chance de puxar uma carta.
        */
        case 1:
            if(random >= 0 & random <= 50){
                return 1;
            }else{
                return 0;
            }

            /*
            Caso 2 - Médio, tenta simular um humano jogando, onde
                tem 95% de chance de puxar uma carta se seus pontos forem menores que 13,
                tem 60% de chance caso sua pontuação esteja entre 13 e 16 pontos,
                tem 15% de chance caso sua pontuação esteja entre 17 e 18,
                tem 5% de chance caso sua pontuação seja 19,
                tem 0% de chance caso sua pontuação seja 20 ou 21.
            */
        case 2:
            if(pontuacaoJogadorMaquina <= 13 & random >= 5){
                return 1;
            }else if(pontuacaoJogadorMaquina > 13 & pontuacaoJogadorMaquina <=16 & random >= 40 ){
                return 1;
            }else if(pontuacaoJogadorMaquina > 16 & pontuacaoJogadorMaquina <=18 & random >= 85 ){
                return 1;
            }else if(pontuacaoJogadorMaquina == 19 & random >= 95 ){
                return 1;
            }else if(pontuacaoJogadorMaquina == 20 || pontuacaoJogadorMaquina == 21 ){
                return 0;
            }else{
                return 0;
            }

            /*
            Caso 3 - Difícil, a máquina tem conhecimento das suas cartas e caso ela tenha menos pontos
            que o jogador humano, ela joga.
            */
        case 3:
            if(pontuacaoJogadorMaquina <= pontuacaoJogadorHumano & pontuacaoJogadorMaquina != 21){
                return 1;
            }else{
                return 0;
            }
    }

}


void trocarJogador(){
    if(jogadorAtual.compare(humano) == 0){
        jogadorAtual = maquina;
    }else{
        jogadorAtual = humano;
    }
}

//Função para que o jogador pegue uma carta do baralho ou do monte
void puxarCarta(string jogadorAtual[][2]){
    int resposta;
    //cout << sizeof(monte) / sizeof(monte[0])<< endl;(tamanho do array)
    cout <<"\nPara puxar carta do baralho digite 1, para puxar do monte, digite 2" << endl;
    cin >> resposta;

    while(resposta != 1 & resposta != 2){
        cout <<"\nOpção inválida. Para puxar carta do baralho digite 1, para puxar do monte, digite 2" << endl;
        cin >> resposta;
    }

    if(resposta == 2 & monte[0][1].compare("") == 0){
        cout <<"\nMonte vazio, puxando automaticamente do baralho\n" << endl;
        resposta = 1;
    }

    if(resposta == 1){
        puxarDoBaralho(jogadorAtual);
        exibeBaralho(jogadorAtual);
    }else{
        puxarDoMonte(jogadorAtual);
        exibeBaralho(jogadorAtual);

    }
}

//função para descartar carta no monte
void descartarCarta(string jogadorAtual[][2]){
    //Verifica as cartas que tem na mão e escolhe a que quer descartar
    int respostaDescarte;
    cout <<"\nDeseja descartar uma carta? Digite 1 para sim, 2 para não." << endl;
    cin >> respostaDescarte;

    while(respostaDescarte != 1 & respostaDescarte != 2){
        cout <<"Opção inválida. Deseja descartar uma carta? Digite 1 para sim, 2 para não." << endl;
        cin >> respostaDescarte;
    }

    if(respostaDescarte == 1){
        int resposta;
        int lastCardNumber = exibeBaralho(jogadorAtual);

        cout <<"\nDigite o número da carta que deseja descartar:" << endl;
        cin >> resposta;

        while(resposta < 1 | resposta > lastCardNumber){
            cout <<"Opção inválida. Digite o número da carta que deseja descartar: " << endl;
            cin >> resposta;
        }

        string nomeCarta;
        string valorCarta;
        //Recebe o nome e o valor da carta do monte;
        nomeCarta = jogadorAtual[resposta-1][0];
        valorCarta = jogadorAtual[resposta-1][1];

        /*Este FOR serve para atribuir o nome e o valor da carta do baralho a primeira posição vazia encontrada no
        baralho do jogador. Ao mesmo tempo, "deleta" a carta do baralho principal para que não possa ser usada mais de uma vez.
        */
        for (int i=0; i<=51; i++){
            if(monte[i][0] == "" & monte[i][1] == ""){
                monte[i][0] = nomeCarta;
                monte[i][1] = valorCarta;
                //"deletando" a carta do baralho principal já que ele agora pertence ao jogador
                jogadorAtual[resposta-1][0] = "";
                jogadorAtual[resposta-1][1] = "";
                return;
            }
        }
    }


}

//Função que recebe um array bidimensional baralho e soma os valores das cartas no seu baralho
int somaPontuacao(string baralhoASomar[][2]){
    int totalPontos = 0;
    for(int i=0; i<=51; i++){
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

void puxarDoMonte(string jogador[][2]){
//a variável i será para procurar no monte qual a carta que está em cima (a que será puxada)
    int cartaSuperior = sizeof monte;
    while(baralho[cartaSuperior][0] == ""){
        cartaSuperior--;
    }

    string nomeCarta;
    string valorCarta;
    //Recebe o nome e o valor da carta do monte;
    nomeCarta = monte[cartaSuperior][0];
    valorCarta = monte[cartaSuperior][1];

    /*Este FOR serve para atribuir o nome e o valor da carta do baralho a primeira posição vazia encontrada no
    baralho do jogador. Ao mesmo tempo, "deleta" a carta do baralho principal para que não possa ser usada mais de uma vez.
    */
    for (int i=0; i<=51; i++){
        if(jogador[i][0] == "" & jogador[i][1] == ""){
            jogador[i][0] = nomeCarta;
            jogador[i][1] = valorCarta;
            //"deletando" a carta do baralho principal já que ele agora pertence ao jogador
            monte[cartaSuperior][0] = "";
            monte[cartaSuperior][1] = "";
            return;
        }
    }

}

//Função que adiciona carta ao baralho de um jogador sem repetição
void puxarDoBaralho(string jogador[][2]){
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
    for (int i=0; i<=51; i++){
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
int exibeBaralho(string baralhoAExibir[][2]){
    int lastCardNumber;
    for(int i=0; i<=51; i++){
        if(baralhoAExibir[i][0] != "" & baralhoAExibir[i][1] !=""){
            cout << i + 1 << " - " << baralhoAExibir[i][0] << " - " << baralhoAExibir[i][1] << endl;
            lastCardNumber = i+1;
        }
    }
    return lastCardNumber;

}
