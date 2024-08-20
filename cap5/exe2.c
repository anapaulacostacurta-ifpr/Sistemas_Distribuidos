#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{
int x = 0 ;
clock_t t; //variável para armazenar tempo
t = clock(); //armazena tempo
printf("fork1: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
fork () ;
printf("1º x++: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
x++ ;
printf ("1º Valor de x: %d\n", x) ;
printf("sleep1: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
sleep (5) ;
printf("wait1: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
wait (0) ;
printf("fork2: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
fork () ;
printf("wait2: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
wait (0) ;
printf("sleep2: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
sleep (5) ;
printf("2º x++: %lf\n", ((double)clock())/((CLOCKS_PER_SEC/1000))); //conversão para double
x++ ;
printf ("2º Valor de x: %d\n", x) ;
t = clock() - t; //tempo final - tempo inicial
printf("Tempo: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
}
