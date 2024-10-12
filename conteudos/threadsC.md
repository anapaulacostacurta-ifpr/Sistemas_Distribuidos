# Threads vs. Processos
## As threads, também conhecidas como "processos leves", oferecem uma forma eficiente de realizar múltiplas tarefas dentro de um mesmo processo. Ao contrário dos processos, que possuem seu próprio espaço de endereço e recursos, as threads compartilham a maior parte dos recursos do processo pai, como memória e descritores de arquivos.

# Criação e Execução de Threads
## Em sistemas Linux, a criação e gerenciamento de threads é realizada através da biblioteca POSIX Threads (pthreads). A função pthread_create é a principal responsável por criar uma nova thread, especificando a função que a nova thread irá executar e qualquer argumento necessário.

# Exemplo Prático: 
## O código [thread-create.c](../threads/thread-create.c) demonstra a criação de duas threads dentro de um mesmo processo:
### Thread 1: Imprime continuamente o caractere 'x' no fluxo de erro padrão (stderr).
### Thread Principal: Imprime continuamente o caractere 'o' no fluxo de erro padrão.
## Ambas as threads executam em paralelo, intercalando a impressão dos caracteres na tela.

# Finalização das Threads
## Tanto a thread principal quanto a thread criada entram em loops while(1), o que significa que ambas continuarão executando indefinidamente, imprimindo caracteres no terminal, a menos que sejam interrompidas externamente. Ademais, um sinal externo pode ser enviado ao processo para interromper sua execução como um SIGINT ou SIGTERM.

# Atividade Prática
### 1. Compilação e Execução [thread-create.c](../threads/thread-create.c):
#### •	Compile o código: Utilize o comando abaixo para compilar o código e gerar o executável thread-create: gcc -o thread-create thread-create.c -lpthread 
#### •	Execute o programa: Rode o programa usando o comando: ./thread-create. 
### 2. Observe e Análise a saída na tela:
#### •	Verifique como os caracteres 'x' e 'o' são intercalados na saída. O que isso indica sobre a execução das threads?
#### •	Como qual as formas que você pode encerrar a execução do programa?
### 3. Modificações no Código:
#### •	Aumento do número de threads: Modifique o código para criar mais threads, cada uma imprimindo um caractere diferente. Observe o impacto no desempenho e na organização da saída.
### 4. Compilação e Execução [thread-create2.c](../threads/thread-create2.c):
#### •	Compile o código: Utilize o comando abaixo para compilar o código e gerar o executável thread-create2: gcc -o thread-create2 thread-create2.c -lpthread 
#### •	Execute o programa, rode o programa usando o comando:  ./thread-create2
### 5. Observe e análise a saída na tela. Reponda as perguntas abaixo:
#### •	Qual foi a diferença na execução da thread-create.c?
#### •	Como qual foi a forma de encerramento utilizada no programa thread-create2.c?

# REFERENCIAS:
BREVE, Neves. Sistemas Operacionais II - Threads – Parte 1. pp 3 – 11. Disponível em: https://www.fabriciobreve.com/material/so2/06%20-%20Linux%20-%20Threads.pdf. Acesso em 13 ago. 2023.
