# Intersection-of-segments

## Реализация алгоритма нахождения точки пересечения отрезков в 3D пространстве

* Программа разработана на языке C++ стандарта C++17 с использованием компилятора g++ (на "Ubuntu 22.04.3 LTS");
* Код находится в папке src;
* Присутствует полное покрытие unit-тестами функций библиотек c помощью библиотеки GTest;
* Предусмотрен Makefile.

## Описание целей в Makefile

Основные цели:
1. all: Сборка всех библиотек, тестов и отчётов покрытия.
2. clean: Удаление всех промежуточных и выходных файлов.
3. test: Запуск тестов.
4. gcov_report: Запуск тестов и генерация HTML-отчёта покрытия кода с использованием gcovr.