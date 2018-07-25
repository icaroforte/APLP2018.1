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
    BaralhoNomeCarta = ["Ás de copas", "Dois de ouro"],
    BaralhoValorCarta = [1, 2],
    % A ideia é fazer 2 baralhos, um com os nomes da carta, outro com os valores delas, então quando eu quiser a carta da posição 30, eu utilizo pegaElementoLista(30, NomeCarta, BaralhoNomeCarta) e também utilizo (30, ValorCarta, BaralhoValorCarta).
    pegaElementoLista(1, NomeCarta, BaralhoNomeCarta), %Pega o elemento 1 da lista BaralhoNomeCarta
    write(NomeCarta), write(" "),
    pegaElementoLista(1, ValorCarta, BaralhoValorCarta), %Pega o elemento 1 da lista BaralhoValorCarta
    write(ValorCarta),nl,
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


    
main:-
    executaMenu().
