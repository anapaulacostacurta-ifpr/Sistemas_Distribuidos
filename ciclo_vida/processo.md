# CICLO DE VIDA DE PROCESSOS
Em sistemas operacionais baseados em Linux, a criação de um novo processo é realizada por meio da chamada de sistema fork. Esta operação cria uma cópia exata do processo pai, conhecida como processo filho. A fork retorna o PID do filho recém-criado para o pai e 0 para o filho.
Após a criação, o processo filho pode assumir um papel diferente usando a família de funções exec, que substitui o programa em execução no processo por um novo programa. Esse mecanismo permite que o processo continue a partir do ponto onde fork foi chamado, mas agora executando um programa diferente.
O gerenciamento de processos envolve a inicialização e finalização de processos. O processo init desempenha um papel crucial ao assumir a responsabilidade de processos órfãos e realizando chamadas wait para reconhecer a expiração de processos filhos.

## Criando um Processo em C
1) Existem duas formas comuns de criar um novo processo:
o	system: Uma função da biblioteca padrão do C que cria um subprocesso, executa um comando no shell e retorna o código de saída.
o	fork e exec: Utiliza-se fork para criar um processo filho e exec para substituir o programa em execução no processo filho.
2) Usando fork e exec
o	fork: Cria um processo filho que é uma cópia exata do processo pai.
o	exec: Substitui o programa em execução no processo por outro programa. A família de funções exec possui variações como execl, execv, execlp, execvp, que diferem na forma de passar argumentos e variáveis de ambiente.
3) Observações importantes:
* Usa fork() para criar um novo processo e execvp() para substituir o processo filho com um novo programa. O processo pai continua a execução e pode retornar o PID do processo filho.
o	Para manejo dos erros o execvp() só retorna se houver um erro, e o programa imprime uma mensagem de erro e aborta se execvp() falhar.
* fork() cria um novo processo que é uma cópia do processo pai. execvp() substitui o processo filho com o novo programa. fork() e execvp() são funções de baixo nível e fornecem controle detalhado sobre o processo.
* Requer a manipulação direta de IDs de processo e chamada de funções de sistema. A lista de argumentos deve ser manipulada manualmente e passada para execvp().
* O processo filho substitui o processo atual, e o código continua no processo pai. É necessário garantir que recursos sejam liberados corretamente.

## Criando processo em Java
Usa ProcessBuilder para criar e iniciar um novo processo. O método command() define o comando e os argumentos. start() inicia o processo, e waitFor() faz o processo principal esperar até que o processo filho termine.
1) Observações importantes: 
o	ProcessBuilder oferece uma interface de mais alto nível para criar e gerenciar processos. Abstrai os detalhes da criação e gerenciamento de processos, oferecendo uma API mais segura e fácil de usar.
o	A sintaxe é mais abstrata e gerenciada pela JVM. O ProcessBuilder lida com a configuração e inicialização do processo, e a lista de argumentos é mais intuitiva com o uso de strings.
o	ProcessBuilder cuida da criação do processo e o código principal pode continuar após o processo filho ser iniciado. O processo pode ser sincronizado com waitFor().
o	Usa IOException para capturar erros na execução do processo e InterruptedException para interrupções. Mensagens de erro são impressas para ajudar na depuração.

## Comparação C com Java:
1. Funcionalidades
* C:
**Utiliza fork() para criar um novo processo e execvp() para substituir a imagem do processo filho pelo novo programa.
** Permite controle mais detalhado sobre a criação e execução de processos.
**A abordagem requer manejo explícito de erros e controle de fluxo.
*Java:
** Utiliza ProcessBuilder para criar e gerenciar processos de forma mais abstrata.
** Abstrai a complexidade das chamadas de sistema e facilita o gerenciamento de processos.
** ProcessBuilder não oferece controle direto sobre o processo filho, mas fornece métodos para manipulação de entradas, saídas e erros.
2. Sintaxe:
* C:
** A sintaxe é mais próxima do sistema operacional, refletindo diretamente as chamadas de sistema.
** Requer gerenciamento manual de erros e lógica de controle.
** Exemplo de uso é mais detalhado e específico.
* Java:
** A sintaxe é mais simples e orientada a objetos.
** ProcessBuilder oferece uma interface mais intuitiva para gerenciamento de processos.
** Menos código é necessário para realizar a mesma tarefa comparado ao C.
3. Facilidade de Uso:
* C:
** A criação e gerenciamento de processos são mais explícitos, o que pode levar a uma maior complexidade no código.
** Requer conhecimento detalhado sobre chamadas de sistema e gerenciamento de erros.
* Java:
** A abstração proporcionada pelo ProcessBuilder simplifica a criação e o controle de processos.
**Menos propenso a erros de baixo nível, já que o gerenciamento de processos é encapsulado na API.
4. Vantagens e Desvantagens:
* C:
** Vantagens:
** Controle detalhado e direto sobre processos.
** Adequado para sistemas e aplicações que requerem alta performance e gerenciamento fino de recursos.
** Desvantagens:
** Mais complexo e propenso a erros.
** Requer gerenciamento explícito de erros e controle de fluxo.
** Java:
** Vantagens:
** Interface de alto nível que abstrai a complexidade do gerenciamento de processos.
** Maior segurança e portabilidade entre diferentes sistemas.
** Desvantagens:
** Menos controle sobre detalhes de baixo nível.
** A abstração pode não ser adequada para todos os tipos de aplicações que requerem controle preciso de processos.

## Utilização em Sistemas Distribuídos:
Em sistemas distribuídos, o gerenciamento de processos e a comunicação entre processos são fundamentais para garantir que diferentes partes do sistema funcionem corretamente em conjunto. Java, com sua capacidade de gerenciar subprocessos e interagir com o sistema operacional, pode desempenhar um papel importante em tais ambientes. Abaixo estão alguns exemplos práticos de utilização de gerenciamento de processos em sistemas distribuídos com Java:
* Execução de Serviços e Daemons : Em um sistema distribuído, pode ser necessário iniciar e gerenciar serviços ou daemons que executam em diferentes nós da rede. Java pode ser usado para automatizar a execução e monitoramento desses serviços.
Comunicação entre Componentes Distribuídos: Em um sistema distribuído, diferentes componentes podem precisar se comunicar entre si. Java pode ser usado para iniciar e gerenciar processos que se comunicam por meio de sockets ou arquivos compartilhados.
* Sincronização e Coordenação de Tarefas: Em sistemas distribuídos, tarefas podem precisar ser coordenadas e sincronizadas entre vários processos. Java pode ser usado para iniciar e coordenar esses processos, garantindo que eles sejam executados na ordem correta.
* Distribuição e Balanceamento de Carga: Em um ambiente distribuído, pode ser necessário distribuir a carga entre diferentes servidores ou nós. Java pode ser usado para iniciar processos que se conectam a diferentes servidores e distribuem as tarefas.

# ATIVIDADES PRÁTICAS
a)	Execução de fork.c e fork-exe.c:
* Compile e execute os programas
* Explique o que acontece quando o processo filho chama execlp e por que o programa ls é executado.
* Compare o comportamento dos dois programas (fork.c e fork-exec.c).
* Poste a resposta da pergunta abaixo juntamente com os prints de execução em um arquivo texto: 
* O que acontece no processo pai enquanto o processo filho executa um novo programa com exec?
b)	Execução dos programas ProcessExample.java e ProcessSpawn.java:
* Comente sobre as diferenças dos programas C e Java.

## REFERENCIAS: 
BREVE, Fabricio. 04 – Linux – Processos. pp. 11-40. Disponível em: https://www.fabriciobreve.com/material/so2/04%20-%20Linux%20-%20Processos.pdf. Acesso em: 03 ago. 2024.
MAZIERO, Carlos. O Conceito de tarefas. Disponível em: https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=socm:socm-04.pdf. Acesso em: 03 ago.2024.

