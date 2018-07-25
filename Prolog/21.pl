%[X,Y|Cauda] = [1,2,3].
%-pertence(X,[X|Z]).
%-insere(H, D, [H|D]).
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
    write("Dificuldade escolhida: Fácil"), nl.
    %rodadas1jogador(1,0,0).

opcao(2):-
    write("Dificuldade escolhida: Médio."), nl.
    %rodadas2jogadores(1, 0, 0).

opcao(3):-
    write("Dificuldade escolhida: Difícil."), nl.

opcao(_):-
    write("Opção inválida. Selecione outra opção: "),
    executaMenu().

main:-
    executaMenu().
