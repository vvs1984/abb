### Упражнение 3*.

Выясните, что происходит с файлами, открытыми в процессе, когда данный процесс вызывает системный вызов fork()?


### Ответ


Для исследования этого вопроса была создана программа, листинг которой приведён  ниже.

```
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
int main(void) {
 
        int fd_in,  fd_out;
        char buf[1024];
 
        memset(buf,  0,  1024); /* пустой буфер*/
        fd_in = open("/tmp/infile",  O_RDONLY);
        fd_out = open("/tmp/outfile",  O_WRONLY|O_CREAT);
 
        fork(); /* Потомок против родителя значения не имеет */
 
        while (read(fd_in,  buf,  2) > 0) { /* Цикл через infile */
                printf("%d: %s",  getpid(),  buf);
                /* Написать строку */
                sprintf(buf,  "%d Hello,  world!\n\r",  getpid());
                write(fd_out,  buf,  strlen(buf));
                sleep(1);
                memset(buf,  0,  1024); /* пустой буфер*/
        }
        sleep(10);
}
 
sunbox$ gcc fdtest1.c -o fdtest1
sunbox$ ./fdtest1
2875: 1
2874: 2
2875: 3
2874: 4
2875: 5
2874: 6
2874: 7
sunbox$ cat /tmp/outfile
2875 Hello, world!
2874 Hello, world!
2875 Hello, world!
2874 Hello, world!
2875 Hello, world!
2874 Hello, world!
2874 Hello, world!
```


По работе программы видно, что процесс чтения файла одним процессом производит сдвиг указателя файла для всех процессов, которы в данный момент работают с ним. Это связано с тем, что ядро ОС отслеживает и синхронизирует информацию об отткрытом файле для всех. Так же происходит и при записи в файл. Каждый процесс проихводит сдвиг указателя файла для всех процессов, которые в данный момент работают с этим файлом - запись в файл из разных процессов будет происходить последовательно в конец файла.

>Ответ на этот вопрос найден https://www.ibm.com/developerworks/ru/library/au-unixprocess/

