      

int main() {
    char *arg_list[] = {"ls", "-l", "/", NULL};
    /* Cria um processo filho para executar o comando "ls". */
    pid_t child_pid = fork();

    if (child_pid == 0) {
        /* Este é o processo filho. */
        execvp(arg_list[0], arg_list);
        exit(1);
    } else {
        /* Este é o processo pai. Dorme por um minuto. */
        sleep(60);
    }
    return 0;
}
