

## Создание docker-а для Flask  web оболочки для обработки запросов БД imdb


### Внимание! Для развертывания БД требуется 65Мб свободного места

### Описание файлов


- create_run_docker_local_db.sh Скрипт автоматизированного создания контейнера и запуска контейнера **для случая, когда контейнер с  БД находится на том же сервере**.


- create_run_docker_remote_db.sh Скрипт автоматизированного создания контейнера и запуска контейнера **для случая, когда контейнер с БД находится на внешнем сервере**. В случае, если изменён порт на сервере - замените **5430**:5430 на порт, который используется в докер файле БД.


- Dockerfile. Конфигурационный файл для создания контейнера.
В качестве основы для контейнера выбран python:3.7


- imdb.py. Файл с тестом программы.


- requirements.txt Перечень необходимых библиотек, которые будут доустановлены при создании контейнера для корректной работы сервиса


- config.ini. Конфигурационный файл с параметрами сортировки и ограничения по количеству выдаваемых индексов фильмов в ответе сервиса.


- tamplates. Папка с html страницами для отработки некоторых http ответов (в данном случае - страницы 404).




#### TODO


1.


