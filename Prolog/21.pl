:- initialization main.


executaMenu():-
    write("---------------------"), nl,
    write("Projeto APLP - Prolog"), nl,
    write("JOGO 21 - BlackJack"), nl,
    write("---------------------"), nl,
    write("Escolha uma dificuldade:"), nl,
    write("1 - Fácil"), nl,
    write("2 - Médio"), nl,
    write("3 - Difícil"), nl,
    write("4 - Sair"), nl,
    read(OPCAO),
    opcao(OPCAO).

 
    
opcao(1):-
    write("Dificuldade escolhida: Fácil"), nl,
    
    BaralhoNomeCarta = ["As de copas", "As de espadas", "As de ouro", "As de paus", "Dois de copas","Dois de espadas", "Dois de ouro", "Dois de paus", "Tres de copas", "Tres de espadas", "Tres de ouro", "Tres de paus", "Quatro de copas", "Quatro de espadas", "Quatro de ouro", "Quatro de paus", "Cinco de copas", "Cinco de espadas", "Cinco de ouro", "Cinco de paus", "Seis de copas", "Seis de espadas", "Seis de ouro", "Seis de paus", "Sete de copas", "Sete de espadas", "Sete de ouro", "Sete de paus", "Oito de copas", "Oito de espadas", "Oito de ouro", "Oito de paus", "Nove de copas", "Nove de espadas", "Nove de ouro", "Nove de paus", "Dez de copas", "Dez de espadas", "Dez de ouro", "Dez de paus", "Valete de copas", "Valete de espadas", "Valete de ouro", "Valete de paus", "Dama de copas", "Dama de espadas", "Dama de ouro", "Dama de paus", "Rei de copas", "Rei de espadas", "Rei de ouro", "Rei de paus"],
    BaralhoValorCarta = [1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
    
    % A ideia é fazer 2 baralhos, um com os nomes da carta, outro com os valores delas, então quando eu quiser a carta da posição 30, eu utilizo pegaElementoLista(30, NomeCarta, BaralhoNomeCarta) e também utilizo (30, ValorCarta, BaralhoValorCarta).   
    
    % -------------------------- 1° Carta Humano ----------------------------- %
    
    %Pegando o tamanho do baralho inicial.
    tamanhoLista(BaralhoNomeCarta, TamanhoBaralhoNomeCarta), %Informa o tamanho da lista passada.
    write("Tamanho Inicial do baralho: "), write(TamanhoBaralhoNomeCarta), nl,
    
    %Gerando um valor aleatório do tamanho do baralho inicial partindo de [1;52].
    random_between(1, TamanhoBaralhoNomeCarta, Random), nl,
    write("Posição random: "), write(Random), nl,

    %Buscando elemento nas listas
    pegaElementoLista(Random, NomeCarta, BaralhoNomeCarta), %Pega o elemento 1 da lista BaralhoNomeCarta
    write(NomeCarta), write(" "),
    pegaElementoLista(Random, ValorCarta, BaralhoValorCarta), %Pega o elemento 1 da lista BaralhoValorCarta
    write(ValorCarta),nl,
    
    %Inserindo valores buscados acima, OBS: Tem de ficar atento ao índice que tá sendo usado, começa em 1 e incrementa, se começar de 2, 0, ou outro valor, quebra o código.
    insert_at(NomeCarta, [] , 1, BaralhoHumano),
    write("Baralho Humano: "),
    write(BaralhoHumano),
    insert_at(ValorCarta, [], 1, BaralhoHumanoValor),
    write(" "),
    write(BaralhoHumanoValor),nl,
    
    %removendo a carta do baralho
    remover(NomeCarta, BaralhoNomeCarta, BaralhoNomeCarta1),nl, 
    remover(ValorCarta, BaralhoValorCarta, BaralhoValorCarta1),nl, 
    
    %Imprimindo o baralho
    write(BaralhoNomeCarta1),nl,
    
    % --------------------------- 2° Carta Humano ------------------------- %
    
    
    write("------------------------------------------------------------"),nl,
    

    %Pega o tamanho do baralho
    tamanhoLista(BaralhoNomeCarta1, TamanhoBaralhoNomeCarta1),nl,
    write("Novo tamanho do baralho após remoção: "), write(TamanhoBaralhoNomeCarta1),nl,
    
    %Gerando um valor aleatório do tamanho do baralho.
    random_between(1, TamanhoBaralhoNomeCarta1, Random1), nl,
    write("Posição random: "), write(Random1), nl,
    
    %Buscando elemento nas listas
    pegaElementoLista(Random1, NomeCarta1, BaralhoNomeCarta1), %Pega o elemento 1 da lista BaralhoNomeCarta
    write(NomeCarta1), write(" "),
    pegaElementoLista(Random1, ValorCarta1, BaralhoValorCarta1), %Pega o elemento 1 da lista BaralhoValorCarta
    write(ValorCarta1),nl,
    
    %Inserindo valores buscados acima, OBS: Tem de ficar atento ao índice que tá sendo usado, começa em 1 e incrementa, se começar de 2, 0, ou outro valor, quebra o código.
    insert_at(NomeCarta1, BaralhoHumano , 2, BaralhoHumano1),
    write("Baralho Humano: "),
    write(BaralhoHumano1),
    insert_at(ValorCarta1, BaralhoHumanoValor, 2, BaralhoHumanoValor1),
    write(" "),
    write(BaralhoHumanoValor1),nl,
    
    %removendo a carta do baralho
    remover(NomeCarta1, BaralhoNomeCarta1, BaralhoNomeCarta2),nl, 
    remover(ValorCarta1, BaralhoValorCarta1, BaralhoValorCarta2),nl, 
    
    %Imprimindo o baralho
    write(BaralhoNomeCarta2),nl,nl,
    
    
    sum_list(BaralhoHumanoValor1,PontuacaoJogadorHumano),
    write("Pontuação do jogodor humano: "), write(PontuacaoJogadorHumano),nl,
    
    
    %Aqui é só colocar depois o resultado da soma da lista da pontuação do jogador máquina para comparação.
    resultado(PontuacaoJogadorHumano,10),
    write("-------------------------------------------------------"),
    
    % --------------------------- 1° Carta Máquina ------------------------- %
    
    
    %OBS: Quando for fazer o jogador máquina USAR O BARALHO DE ONDE PAROU, OU SEJA, BaralhoNomeCarta2 e BaralhoValorCarta2!!!
    %
    %Pronto, agora só falta adicionar 2 cartas iniciais para cada jogador... Jogador Humano já feito! Falta a máquina
    %Precisa modificar o nome das variáveis que tá um pouco confuso e ruim pra ler
    %Precisa criar métodos para organizar as coisas
    %Precisa criar o jogador máquina similar ao jogador humano criado
    
    
    %Aqui deve ser alterado passando como parâmetros os dados acima, o baralho novo, a pontuação, essas coisas...
    iniciarPartida().

opcao(2):-
    write("Dificuldade escolhida: Médio."), nl.

opcao(3):-
    write("Dificuldade escolhida: Difícil."), nl.

opcao(_):-
    write("Opção inválida. Selecione outra opção: "),
    executaMenu().
    
iniciarPartida():-
    write("Início da partida").

    
%-------------- Funções para usar -------------------     
pegaElementoLista(1, X, [X | _]).
pegaElementoLista(N, X, [_ | Y]) :-
    pegaElementoLista(M, X, Y),
    N is M+1.    

tamanhoLista([], 0).
tamanhoLista([_ | R], N) :-
tamanhoLista(R, N1),
N is N1+1.

remover(X, [X | C], C).
remover(X, [Y | C], [Y | D]) :-
remover(X, C, D).

%    (element,list,integer,list)
insert_at(X,L,K,R) :- 
    remove_at(X,R,K,L).

remove_at(X,[X|Xs],1,Xs).
remove_at(X,[Y|Xs],K,[Y|Ys]) :- K > 1, 
   K1 is K - 1, remove_at(X,Xs,K1,Ys).

sum_list([], 0).
sum_list([H|T], Sum) :-
   sum_list(T, Rest),
   Sum is H + Rest.

resultado(P1, P2):- P1 > P2, write("Jogador humano venceu"), nl.
resultado(P1, P2):- P1 < P2, write("Jogador máquina venceu"), nl.
resultado(P1, P1):- write("Empate!!!"), nl.
   
main:-
    executaMenu().
