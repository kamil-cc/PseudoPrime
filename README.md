# PseudoPrime
Mój najstarszy "poważny" projekt napisany w C++ [2008], Program ma jedynie wartość sentymentalną :-)
Program do znajdowania dużych liczb pseudopierwszych (100-150 cyfr).
Współpracuje z biblioteką The GNU Multiple Precision Arithmetic Library https://gmplib.org/
Został stworzony do działania z wersją 4.3.1 jednak bez problemu kompiluje się przy użyciu nowszych wersji, np.: 6.0.0a
Polecenie użyte do kompilacji (linkowanie statyczne):
g++ main.cpp dane.cpp ekran.cpp ppalg.cpp wynik.cpp -lgmpxx -lgmp -o generator

Sposób otrzymywania liczb pseudopierwszych użyty w programie jest autorstwa M. Cipolla i został zaczerpnięty z książki "Mała księga wielkich liczb pierwszych", Paulo Ribenboim, WNT, str. 99 Program umożliwia podanie zakresu danych wejściowych [dla podstawy (a) i wykładnika (p)], na podstawie których będą generowane liczby pseudopierwsze.
W celu oceny poprawności wyników wygenerowanych przez mój program, stworzyłem prosty program sprawdzający o nazwie "test". Weryfikuje on, czy wygenerowane liczby są pseudopierwsze podstawiając je do wzoru x^(y-1)=1(mod y). Więcej informacji: https://gist.github.com/kamil-cc/40d6d022225382b2c647
