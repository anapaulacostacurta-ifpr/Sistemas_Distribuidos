## Introdução a Threads em Java

### O que são threads?
Threads são fluxos de execução independentes dentro de um processo. Imagine-as como tarefas que podem ser executadas em paralelo, aumentando a performance de suas aplicações.

### Por que usar threads?
* **Paralelismo:** Execute múltiplas tarefas simultaneamente.
* **Responsividade:** Mantenha a interface do usuário responsiva enquanto tarefas em segundo plano são executadas.
* **Aproveitamento de múltiplos núcleos:** Utilize toda a capacidade de processamento do seu computador.

### Quando não usar threads?
* **Problemas simples:** Para tarefas simples e sequenciais, threads podem adicionar complexidade desnecessária.
* **Overhead:** A criação e gerenciamento de threads exigem recursos do sistema.

## Threads em Java
A classe `Thread` em Java oferece a base para a programação concorrente.
* **Criando threads:**
  * **Extendendo Thread:**
    ```java
    class MinhaThread extends Thread {
        public void run() {
            // Código da thread
        }
    }
    ```
  * **Implementando Runnable:**
    ```java
    class MinhaTarefa implements Runnable {
        public void run() {
            // Código da thread
        }
    }
    ```
  * **Iniciando threads:**
    ```java
    Thread t = new Thread(tarefa);
    t.start();

## Atividade Prática - Criando uma nova Thread em Java:
### Objetivo:
* Compreender os conceitos básicos de threads em Java;
* Implementar threads para executar tarefas em paralelo;
* Compreender o comportamento de threads em Java e o impacto do método yield().
* Analisar a saída de programas concorrentes e identificar padrões de execução.
* Identificar as diferenças entre as duas implementações.

### Tarefas:
* Execução paralela de threads: TesteConcorrente.java;
* Execução paralela de threads com yield: Teste Concorrente2.java;

### Procedimento

#### Compilação:
Salve os arquivo em seu repositório github (TesteConcorrente.java e TesteConcorrente2.java).
Utilize um compilador Java (como o javac) para compilar cada classe:
  ```bash
  javac ImprimirThread_1.java TesteConcorrente.java
  javac ImprimirThread_2.java TesteConcorrente2.java

#### Execução:
Execute cada classe principal:
   ```bash
   java TesteConcorrente
   java TesteConcorrente2

