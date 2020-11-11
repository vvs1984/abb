#include <stdlib.h> 		//malloc
#include <stdio.h>  		//gets
#include <string.h> 		//strtok
#include <unistd.h> 		//fork
#include <sys/wait.h>		//waitpid

char **get_input(char *); 	//декларация функции


int main() {
    char **command;
    char *input[100];
    pid_t child_pid;
    int stat_loc;

    while (1) {
	printf( "\nДемо версия shell. Для выхода нажмите Ctrl+C. Введите команду\n");
	gets(input);
	command = get_input(input);

        if (!command[0]) { //обработка пустой строки
	    gets(input);
	    command = get_input(*input);
            continue;
        }
        child_pid = fork();
        
        if (child_pid < 0){ // отработка ошибки при вызове fork
            perror("Ошибка создания процесса");
            exit(1);
        }

        if (child_pid == 0) {
            /* Never returns if the call is successful */
            if (execvp(command[0], command) < 0) {	// заменяет текущий образ процесса новым
            						// образом процесса.
            						
                perror(command[0]);			// выводит в стандартный поток ошибки
                					// сообщения, описывая ошибку
                exit(1);
            }
        } else {// не вернется в родительский процесс, 
        	//пока не произойёт выход из дочернего процесса
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }


    }

    return 0;
}

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
        perror("malloc failed");
        exit(1);
    }

    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}
