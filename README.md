### Introdução à Computação Gráfica

Autor: Danilo Santos Vieira / Matrícula 20160141328

Esse repositório foi organizado da seguinte forma: a pasta trabalhos localizada em https://github.com/Danilosvsv/ICG, contém todos os códigos desenvolvidos por trabalho, já a parte da explicação dos resultados com texto/printscreens serão desenvolvidos no decorrer desse arquivo "readme.md".

1. [Trabalho 1: Rasterização de Linhas](#introduction)
2. [Trabalho 2: Compilando e Executando um Programa OpenGL Moderno](#introduction2)


## Trabalho 1: Rasterização de Linhas <a name="introduction"></a>

Esse trabalho apresenta a fundamentação matemática para a compreensão e implementação de algoritmos para o desenho de pontos, linhas e triângulo na tela do computador. Para essa tarefa, foi necessário entender o algoritmo de Rasterização de Linhas, revisar conhecimentos fundamentais da matemática, como a equação da reta, e no âmbito computacional, foi necessário a instalação do OpenGL 3.0 e da Linguagem de Programação C.

# I) Desenhando um ponto

Para desenhar um ponto na tela foi criado uma função que pega as coordenadas (x,y) desse ponto e a cor desse ponto através dos seus respectivos valores R,G,B,A.

Algoritmo: 

```
DesenhaPonto(x,y,valor R,valor G,,valor B,valor A){
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor R;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor G;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor B;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor A;
}  
```
Obteve-se como resultado: 

![Imagem5](https://user-images.githubusercontent.com/66951092/85498909-f9edad80-b5b6-11ea-9be6-353313f7d6ba.png)

# II) Desenhando linhas

A princípio, foi fornecido o Algoritmo de Bresenham para o caso 0 < m < 1.

```
MidPointLine() {
  int dx = x1 – x0;
  int dy = y1 – x0;
  int d = 2 * dy – dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy – dx);
  int x = x0;int y = y0;
  PutPixel(x, y, color) 
  while (x < x1) {
    if (d <= 0) {
      d += incr_e;x++;
      }else {
        d += incr_ne;
        x++;
        y++;
      }
        PutPixel(x, y, color);
  }
}
```
Porém, não pode-se limitar o desenho das linhas apenas para o 1 octante, logo, é necessário generalizar esse algoritmo para os outros octantes, ou seja, realizou-se uma análise para identificar o comportamento de (x1-x0), (y1-y0), m e a relação entre as coordenadas x0,x1 e y0,y1 nos outros octantes. Dessa forma, obteve-se os seguintes resultados:


![Imagem1](https://user-images.githubusercontent.com/66951092/85497796-ed685580-b5b4-11ea-9c9b-f601a685a257.jpeg)

![Imagem2](https://user-images.githubusercontent.com/66951092/85497806-f22d0980-b5b4-11ea-984c-df3e296af453.jpeg)


# III) Interpolação de Cores: desenhando linha e triângulo


![Imagem3](https://user-images.githubusercontent.com/66951092/85497812-f3f6cd00-b5b4-11ea-9dbc-8eb6949782e0.jpeg)

![Imagem4](https://user-images.githubusercontent.com/66951092/85497816-f5c09080-b5b4-11ea-861d-40de34db9f80.jpeg)

## Trabalho 2: Compilando e Executando um Programa OpenGL Moderno <a name="introduction2"></a>

Esse trabalho consiste na verificação do ambiente de desenvolvimento em OpenGl 3.3. Assim, para essa tarefa foi fornecido o seguinte diretório no github https://github.com/capagot/icg/tree/master/hello_world_gl/modern_opengl. Dessa forma, realizou-se uma compilação inicial para observar se o resultado retornado à tela do usuário corresponde a um triângulo colorido.

![im1](https://user-images.githubusercontent.com/66951092/85546087-f11acd00-b5f2-11ea-9418-ad78f4fac454.jpg)
![im2](https://user-images.githubusercontent.com/66951092/85546094-f1b36380-b5f2-11ea-9051-a95a165f9e05.jpg)

Como observado, ainda não foi possível obter o triângulo, logo, foi feito mais alguns testes até que foi retornado a seguinte mensagem no terminal:

![im3](https://user-images.githubusercontent.com/66951092/85546099-f2e49080-b5f2-11ea-9f0a-db4315fe1d1e.jpg)

A figura 7 mostra que o OpenGL instalado na máquina é inferior a versão 3.3 do OpenGl, logo foi necessário realizar atualizações na máquina de forma a atualizar o OpenGl. Para isso foi realizado consultas na internet, de forma a achar os seguintes comandos para serem executados:

```
sudo apt-get update
sudo apt-get install freeglut3
sudo apt-get install freeglut3-dev
sudo apt-get install binutils-gold
sudo apt-get install g++ cmake
sudo apt-get install libglew-dev
sudo apt-get install g++
sudo apt-get install mesa-common-dev
sudo apt-get install mesa-common-dev
sudo apt-get install libglew1.5-dev libglm-dev
glxinfo | grep OpenGL
export MESA_GL_VERSION_OVERRIDE=3.3
```

Portanto, obteve-se os seguintes resultados

![im4](https://user-images.githubusercontent.com/66951092/85546104-f415bd80-b5f2-11ea-8bd5-cd7ea476e8be.jpg)

![im5](https://user-images.githubusercontent.com/66951092/85546107-f546ea80-b5f2-11ea-9237-ee69908a3dc3.jpg)

Referências:
https://pt.wikihow.com/Instalar-Mesa-(OpenGL)-no-Linux-Mint
https://stackoverflow.com/questions/52592309/0110-error-glsl-3-30-is-not-supported-ubuntu-18-04-c

