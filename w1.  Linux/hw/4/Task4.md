#### Упражнение 4

Создайте файл file.txt в каталоге abc и получите доступ к этому файлу из каталога xyz через $ link <source> _some_file.txt

  - Проследить все ссылки на file.txt: $ find <path> –inum inodenumber
  - Удалить все ссылки to file.txt $ find <path> –inum inodenumber -exec rm {} \;
  - Сохранить вывод всего в файл ex4.txt. Загрузите историю в github. 

#### Отчёт о выполнении


Для выполнения первой задания последовательно были выполнены следующие команды:

```
mkdir abc xyz
touch ./abc/file.txt
link ./abc/file.txt ./xyz/file2.txt
find ./ -iname 'file*.txt' -type f -exec ls -i {} \;
find ./ -iname 'file*.txt' -type f -exec rm {} \;

```

Лог выполнения  команд содержится ex4.log (получен с помощью метода scrypt).


