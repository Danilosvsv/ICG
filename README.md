# ICG

Autor: Danilo Santos Vieira / Matrícula 20160141328

<li><a href="#">1 - Rasterização de Linhas</a></li>

Esse trabalho apresenta a fundamentação matemática para a compreensão e implementação de algoritmos para o desenho de pontos, linhas e triângulo na tela do computador. Para essa tarefa, foi necessário entender o algoritmo de Rasterização de Linhas, revisar conhecimentos fundamentais da matemática, como a equação da reta, e no âmbito computacional, foi necessário a instalação do OpenGL 3.0 e da Linguagem de Programação C.

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
Porém, não pode-se limitar o desenho das linhas apenas para o 1 octante, logo, é necessário generalizar esse algoritmo para os outros octantes, ou seja, vamos realizar um estudo breve em relação a equação da reta. 

y = mx+b

![Imagem1](https://user-images.githubusercontent.com/66951092/85497796-ed685580-b5b4-11ea-9c9b-f601a685a257.jpeg)

![Imagem2](https://user-images.githubusercontent.com/66951092/85497806-f22d0980-b5b4-11ea-984c-df3e296af453.jpeg)

![Imagem3](https://user-images.githubusercontent.com/66951092/85497812-f3f6cd00-b5b4-11ea-9dbc-8eb6949782e0.jpeg)

![Imagem4](https://user-images.githubusercontent.com/66951092/85497816-f5c09080-b5b4-11ea-861d-40de34db9f80.jpeg)








