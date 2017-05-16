# Bouncing Ball

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
    * Declaração da classe virtual herdada pela classe ball.
5. ball.h
    * Declaração de métodos e atributos de uma instância da classe ball.
6. ball.cpp
    * Implementação de métodos declarados em ball.h.

**Diagrama de Classes**

![graph0](https://github.com/TheKipmaster/test_ball/blob/master/Bouncing-Ball-UML.png "Bouncing-Ball-UML")

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
![graph1](https://github.com/TheKipmaster/test_ball/blob/master/results.png "Gráfico 1")


# Spring-Mass

O Sistema simula a trajetória de um conjunto de massas ligadas por molas

Para compilar o programa, basta fazer uso do Makefile incluído nesse repositório; digite "make test-springmass" no terminal.

**Arquivos**

1. Makefile
    * Automatiza o processo de compilação.
2. .gitignore
    * Dita tudo que deve ser ignorado pelo git em uma cópia local desse repositório.
3. test-springmass.cpp
    * Contém função main().
4. simulation.h
    * Declaração da classe virtual herdada pela classe springmass.
5. springmass.h
    * Declaração de métodos e atributos de uma instância das classes mass, spring e springmass.
6. springmass.cpp
    * Implementação de métodos declarados em springmass.h.

**Resultados Esperados**

   m1x      m1y        m2x     m2y

-0.499165 -0.500483 0.499165 -0.00131748

-0.496681 -0.50194 0.496681 -0.00525973

-0.492605 -0.504403 0.492605 -0.0117973

-0.487034 -0.507917 0.487034 -0.0208831

-0.480093 -0.512546 0.480093 -0.0324537

-0.471939 -0.51837 0.471939 -0.0464303

-0.462758 -0.525479 0.462758 -0.0627211

-0.452754 -0.533977 0.452754 -0.0812228

-0.442153 -0.543977 0.442153 -0.101823

-0.431191 -0.555596 0.431191 -0.124404

(parte dos resultados foram omitidos)
(formatação alterada para facilitar leitura)

*Gráfico correspondente:*
![graph2](https://github.com/TheKipmaster/test_ball/blob/master/results2.png "Gráfico 2")

# Graphics

A mais nova versão do projeto agora inclui a implementação de ferramentas que permitem manipular a placa gráfica da máquina
para produzir simulações em 2D em tempo real.

Para esse fim, o projeto faz uso das bibliotecas gráficas Open GL e Glut, cujas documentações podem ser encontradas
[aqui](https://www.opengl.org/ "Site Oficial da OpenGL"). Para um guia de instalação de Glut e OpenGL, visite
[este site](http://www.prinmath.com/csci5229/misc/install.html "Guia de Instalação")

Para compilar as versões dos programas que utilizam as bibliotecas gráficas, é necessário executar os seguintes comandos em
ordem:

1. c++ graphics.cpp -std=c++11 -lglut -lGL -lGLU -c

2. c++ springmass.cpp -std=c++11 -lglut -lGL -lGLU -c

3. c++ test-springmass-graphics.cpp springmass.o graphics.o -std=c++11 -lglut -lGL -lGLU -o test-springmass-graphics

Para compilar test-ball-graphics, se faz necessária a mesma rotina, exceto trocando a palavra "springmass" por ball sempre que
ela aparecer. Também pode-se fazer uso do Makefile presente no repositório, digitando simplesmente "make test-ball-graphics" ou
"make test-springmass-graphics" no terminal.

**Arquivos**

1. Makefile
    * Automatiza o processo de compilação.
2. .gitignore
    * Dita tudo que deve ser ignorado pelo git em uma cópia local desse repositório.
3. test-springmass-graphics.cpp
    * Contém função main() para a simulação do sistema massa-mola.
4. test-ball-graphics
    * Contém função main() para a simulação da bola.
5. graphics.h
    * Declaração de métodos e atributos de uma instância das classes Figure e Drawable.
6. graphics.cpp
    * Implementação de métodos declarados em graphics.h

**Screen Shots**

*test-ball-graphics*
![graph3](https://github.com/TheKipmaster/test_ball/blob/master/ball-graphics.png "test-ball-graphics em ação")

*test-springmass-graphics*
![graph4](https://github.com/TheKipmaster/test_ball/blob/master/springmass-graphics.png "test-springmass-graphics em ação")
