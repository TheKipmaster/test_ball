# Test Ball

O projeto tem como objetivo reforçar conceitos de programação orientada a objeto por meio da implementação de um aplicativo em C++.

Para compilar e rodar o aplicativo corretamente se faz necessária a instalação das bibliotecas "lglut" e "lGL", e o versão de C++ usado é o de 2011.

Esse repositório inclui um arquivo Makefile, afim de facilitar o processo de compilar e recompilar o aplicativo.

**Arquivos**

1. Makefile
    * Automatiza o processo de compilação.
2. .gitignore
    * Dita tudo que deve ser ignorado pelo git em uma cópia local desse repositório.
3. test-ball.cpp
    * Contém função main().
4. simulation.h
    * Declaração da classe virtual herdadas pela classe ball.
5. ball.h
    * Declaração de métodos e atributos de uma instância da classe ball.
6. ball.cpp
    * Implementação de métodos declarados em ball.h.
    

**Resultados Esperados**

*No terminal:*

0.01 - 0.00877778

0.02 - 0.0284444

0.03 - 0.059

0.04 - 0.100444

0.05 - 0.152778

0.06 - 0.216

0.07 - 0.290111

0.08 - 0.375111

0.09 - 0.471

0.01 - 0.577778

(parte dos resultados foram omitidos)

*Gráfico correspondente:*
![graph](https://github.com/TheKipmaster/test_ball/blob/master/results.png "Gráfico 1")
