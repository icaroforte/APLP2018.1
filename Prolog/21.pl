%[X,Y|Cauda] = [1,2,3].
%-pertence(X,[X|Z]).
%-insere(H, D, [H|D]).

%Lista do tipo [H|T], Onde H é a cabeça e T é o resto da lista.
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
    
    pegaElementoLista(1, NomeCarta, BaralhoNomeCarta), %Pega o elemento 1 da lista BaralhoNomeCarta
    write(NomeCarta), write(" "),
    pegaElementoLista(1, ValorCarta, BaralhoValorCarta), %Pega o elemento 1 da lista BaralhoValorCarta
    write(ValorCarta),nl,
    tamanhoLista(BaralhoNomeCarta, TamanhoBaralhoNomeCarta), %Informa o tamanho da lista passada.
    write("Tamanho Inicial do baralho: "),write(TamanhoBaralhoNomeCarta),nl,
    remover(NomeCarta, BaralhoNomeCarta, NovoBaralhoNomeCarta),nl, %removendo a carta do baralho
    write(NovoBaralhoNomeCarta),nl,
    tamanhoLista(NovoBaralhoNomeCarta, NovoTamanhoBaralhoNomeCarta),nl,
    write("Novo tamanho do baralho após remoção: "), write(NovoTamanhoBaralhoNomeCarta),nl,nl,
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

    
main:-
    executaMenu().
