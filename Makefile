# Makefile: Compilação dos testes

all:        tests/insertOptions_test.exe

insertOptions_test.exe:        insertOptions_test.c
        gcc -o tests/insertOptions_test tests/insertOptions_test.c tests/Unity/unity.c tests/testFunctions/insertOptions.c
	tests/insertOptions_test.exe