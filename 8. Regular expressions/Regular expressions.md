### Regular Expressions
# Лабораторная работа

### Задача
Среди списка состоящего из полных путей файлов необходимо найти те пути, которые соответствуют следующему условию:
* Имя файла совпадает с именем папки, которая содержит этот файл.

Решить данную задачу используя регулярное выражени.

### Пример

Список полных путей:

```
D:\project_A\project_A.cpp
D:\project_A\project_A.h
D:\project_A\class1.cpp
D:\project_A\class1.h
D:\project_B\folder_1\project_B.cpp
D:\project_B\folder_1\project_B.h
D:\project_B\folder_1\class1.cpp
D:\project_B\folder_1\class1.h
D:\project.c\project.C\main.cpp
D:\project.c\folder\project.c.c
D:\project_D\project_D\main.cpp
D:\class1\folder_1\class1
```

Ожидаемый результат:

```
D:\project_A\project_A.cpp
D:\project_A\project_A.h
D:\project_B\folder_1\project_B.cpp
D:\project_B\folder_1\project_B.h
D:\project.c\folder\project.c.c
D:\class1\folder_1\class1
```

### Формат отчета
Регулярное выражение (с комментариями), Флаги регулярного выражения