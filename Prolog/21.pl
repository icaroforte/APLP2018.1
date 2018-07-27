:- initialization main.

main:-
    write("----------------------------------------------------------------------"), nl,
    write("Projeto APLP - Prolog"), nl,
    write("JOGO 21 - BlackJack"), nl,
    write("Autores:"), nl,
    write("    Ícaro Forte"), nl,
    write("    Pedro Augustus"), nl,
    write("    Rafael de Paula"), nl,
    write("    Tulio Henrique"), nl,
    write("    Yago da Costa"), nl,
    write("----------------------------------------------------------------------"), nl,
    
    % Um baralho para os nomes das cartas, outro baralho para os valores delas. Qualquer operação é realizada em ambas as listas para evitar inconsistências.
    BNomes = ["As de copas", "As de espadas", "As de ouro", "As de paus", "Dois de copas","Dois de espadas", "Dois de ouro", "Dois de paus", "Tres de copas", "Tres de espadas", "Tres de ouro", "Tres de paus", "Quatro de copas", "Quatro de espadas", "Quatro de ouro", "Quatro de paus", "Cinco de copas", "Cinco de espadas", "Cinco de ouro", "Cinco de paus", "Seis de copas", "Seis de espadas", "Seis de ouro", "Seis de paus", "Sete de copas", "Sete de espadas", "Sete de ouro", "Sete de paus", "Oito de copas", "Oito de espadas", "Oito de ouro", "Oito de paus", "Nove de copas", "Nove de espadas", "Nove de ouro", "Nove de paus", "Dez de copas", "Dez de espadas", "Dez de ouro", "Dez de paus", "Valete de copas", "Valete de espadas", "Valete de ouro", "Valete de paus", "Dama de copas", "Dama de espadas", "Dama de ouro", "Dama de paus", "Rei de copas", "Rei de espadas", "Rei de ouro", "Rei de paus"],
    BValores = [1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
    
    write("======================== Inicializando o Jogo ========================"),nl,
    % --------------------------  1ª Carta Humano ----------------------------- %
    write("Humano: "),
    puxarCarta(BNomes,BValores,[],[],BNomes1,BValores1,BHumano,BHumanoVal),
    
    % --------------------------- Puxar 2ª Carta Humano ------------------------- %
    puxarCarta(BNomes1,BValores1,BHumano,BHumanoVal,BNomes2,BValores2,BHumano1,BHumanoVal1),
    
    % --------------------------- Puxar 1ª Carta Máquina ------------------------- 
    write("Maquina: "),
    puxarCarta(BNomes2,BValores2,[],[],BNomes3,BValores3,BMaquina,BMaquinaVal),

    % --------------------------- Puxar 2ª Carta Máquina ------------------------- %
    puxarCarta(BNomes3,BValores3,BMaquina,BMaquinaVal,BNomes4,BValores4,BMaquina1,BMaquinaVal1),

    nl,
    sum_list(BHumanoVal1,PontuacaoHumano),
    write("Pontuação inicial do jogador Humano: "), write(PontuacaoHumano),nl,
    sum_list(BMaquinaVal1,PontuacaoMaquina),
    write("Pontuação inicial do jogador Máquina: "), write(PontuacaoMaquina),nl,

    promptDraw(PontuacaoHumano,PontuacaoMaquina,""),
    round(BNomes4,BValores4,BHumano1,BHumanoVal1,BMaquina1,BMaquinaVal1,1).

round(BNomes,BValores,BHumano,BHumanoVal,BMaquina,BMaquinaVal,Round):-
    write("Rodada: "), write(Round),nl,
    % --------------------------- Carta Humano ------------------------- %
    write("Humano: "),
    puxarCarta(BNomes,BValores,BHumano,BHumanoVal,BNomes1,BValores1,BHumano1,BHumanoVal1),

    % --------------------------- Carta Máquina ------------------------- %
    write("Maquina: "),
    puxarCarta(BNomes1,BValores1,BMaquina,BMaquinaVal,BNomes2,BValores2,BMaquina1,BMaquinaVal1),
    
    % Calcula Resultados
    nl,
    sum_list(BHumanoVal1,PontuacaoHumano),
    write("Pontuação do jogador Humano: "), write(PontuacaoHumano),nl,
    sum_list(BMaquinaVal1,PontuacaoMaquina),
    write("Pontuação do jogador Máquina: "), write(PontuacaoMaquina),nl,

    condicaoParada(PontuacaoHumano, PontuacaoMaquina),
    NovoRound is Round + 1,
    promptDraw(PontuacaoHumano,PontuacaoMaquina,""),
    round(BNomes2,BValores2,BHumano1,BHumanoVal1,BMaquina1,BMaquinaVal1,NovoRound).

puxarCarta(BNomes, BValores, JNomes, JValores, BNomesFinal, BValoresFinal, JNomesFinal, JValoresFinal):-
    tamanhoLista(BNomes, SizeNomes), %Informa o tamanho da lista passada.
    %write("Tamanho Inicial do baralho: "), write(SizeNomes), nl,
    
    %Gerando um valor aleatório do tamanho do baralho inicial partindo de [1;52].
    random_between(1, SizeNomes, Random), nl,
    %write("Posição random: "), write(Random), nl,

    %Buscando elemento nas listas
    pegaElementoLista(Random, CNome, BNomes), %Pega o elemento 1 da lista BaralhoNomeCarta
    %write(CNome), write(" "),
    pegaElementoLista(Random, CValor, BValores), %Pega o elemento 1 da lista BaralhoValorCarta
    %write(CValor),nl,
    
    %Inserindo valores buscados acima, OBS: Tem de ficar atento ao índice que tá sendo usado, começa em 1 e incrementa, se começar de 2, 0, ou outro valor, quebra o código.
    insert_at(CNome, JNomes , 1, JNomesFinal),
    write("Baralho do jogador: "),
    write(JNomesFinal),
    insert_at(CValor, JValores, 1, JValoresFinal),
    %write(" "),
    %write(JValoresFinal),nl,
    
    %removendo a carta do baralho
    remover(CNome, BNomes, BNomesFinal),nl, 
    remover(CValor, BValores, BValoresFinal),nl.
    
    %Imprimindo o baralho
    %write(BNomesFinal),nl.

condicaoParada(BhumanoVal, BmaquinaVal):-
    BhumanoVal > 21,
    BmaquinaVal < 21,
    write("Jogador máquina venceu!"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    BmaquinaVal > 21,
    BhumanoVal < 21,
    write("Jogador humano venceu!"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    BmaquinaVal > 21,
    BhumanoVal > 21,
    write("Nenhum jogador venceu"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    BmaquinaVal = 21,
    BhumanoVal = 21,
    write("Deu empate"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    BhumanoVal = 21,
    write("Jogador humano venceu!"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    BmaquinaVal = 21,
    write("Jogador maquina venceu!"), nl,
    halt.
condicaoParada(BhumanoVal, BmaquinaVal):-
    nl.

promptDraw(P1,P2, 1) :- nl.
promptDraw(P1,P2, 2) :-
    fim(P1,P2).
promptDraw(P1,P2, _) :-
    write("Deseja puxar uma carta? 1 para Sim / 2 para Não"),nl,
    read(Input),
    promptDraw(P1,P2,Input).
    
fim(PontuacaoHumano,PontuacaoMaquina):-
    resultado(PontuacaoHumano,PontuacaoMaquina),
    halt.

%-------------- Regras Auxiliares -------------------     
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

%    (elemento,lista,inteiro,lista)
insert_at(X,L,K,R) :- 
    remove_at(X,R,K,L).

remove_at(X,[X|Xs],1,Xs).
remove_at(X,[Y|Xs],K,[Y|Ys]) :- K > 1, 
   K1 is K - 1, remove_at(X,Xs,K1,Ys).

sum_list([], 0).
sum_list([H|T], Sum) :-
   sum_list(T, Rest),
   Sum is H + Rest.

resultado(P1, P2):- P1 > P2, write("Jogador humano venceu!"), nl.
resultado(P1, P2):- P1 < P2, write("Jogador máquina venceu!"), nl.
resultado(P1, P1):- write("Empate!!!"), nl.
