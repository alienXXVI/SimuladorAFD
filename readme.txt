Equipe:
Maryanne de Oliveira Gomes
Aliana Wakassugui de Paula e Silva

Este programa é um simulador de Autômato Finito Determinístico.
Faz a leitura de um arquivo contendo as especificações do mesmo, permite fazer a impressão das informações e o teste de palavras.

-- INSTRUÇÕES --
Iniciando o programa, será exibido um menu de escolhas:

1 - Carregar um arquivo contendo especificacoes de um AFD
2 - Imprimir especificacoes do AFD carregado
3 - Testar palavras
4 - Resetar memoria
0 - Encerrar programa
> 

Para carregar um Autômato de um arquivo texto na memória, escolha 1 e digite o nome do arquivo.extensão.
Caso o autômato não seja determinístico, o programa vai apresentar erro.
O arquivo deve estar no seguinte formato:

alfabeto={a,b,c,0,1,2}
estados={q0,q1,q2,q3,q4,q5}
finais={q2,q5}
(q0,a)= q1
(q1,a)= q2
(q1,b)= q1
(q1,0)= q4
(q2,c)= q3
(q3,b)= q2
(q3,0)= q5
(q4,0)= q2
(q4,1)= q5
(q5,2)= q4

Para imprimir as informações do Autômato carregado, digite 2. Serão exibidos o alfabeto, os estados e estados
finais existentes, além das transições de cada estado, assim:

Alfabeto: a b c 0 1 2
Estados: q0 q1 q2 q3 q4 q5
Finais: q2 q5
Transicoes:
q0 -> {q1, a}
q1 -> {q2, a} {q1, b} {q4, 0}
q2 -> {q3, c}
q3 -> {q2, b} {q5, 0}
q4 -> {q2, 0} {q5, 1}
q5 -> {q4, 2}

Para testar palavras no autômato carregado, digite 3, e as seguintes escolhas serão apresentadas:

1 - Digitar a palavra
0 - Voltar
> 

Para entrar com uma palavra, digite 1, tecle "Enter", e em seguida, digite a palavra desejada. Repita para vários testes.
Para voltar ao menu principal, digite 0.

Para resetar a memória e carregar outro arquivo de um AFD, digite 4.
Recomenda-se não imprimir logo após esse processo.

Para encerrar o programa, digite 0.