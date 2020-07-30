### Introdução à Computação Gráfica

Autor: Danilo Santos Vieira / Matrícula 20160141328

Esse repositório foi organizado da seguinte forma: a pasta trabalhos localizada em https://github.com/Danilosvsv/ICG, contém todos os códigos desenvolvidos por trabalho, já a parte da explicação dos resultados com texto/printscreens serão desenvolvidos no decorrer desse arquivo "readme.md".

1. [Trabalho 1: Rasterização de Linhas](#introduction)
2. [Trabalho 2: Compilando e Executando um Programa OpenGL Moderno](#introduction2)
3. [Trabalho 3: Pipeline Gráfico](#introduction3)


## Trabalho 1: Rasterização de Linhas <a name="introduction"></a>

Esse trabalho apresenta a fundamentação matemática para a compreensão e implementação de algoritmos para o desenho de pontos, linhas e triângulo na tela do computador. Para essa tarefa, foi necessário entender o algoritmo de Rasterização de Linhas, revisar conhecimentos fundamentais da matemática, como a equação da reta, e no âmbito computacional, foi necessário a instalação do OpenGL 3.0 e da Linguagem de Programação C.

# I) Desenhando um ponto

Para desenhar um ponto na tela foi criado uma função que pega as coordenadas (x,y) e a cor desse ponto através dos seus respectivos valores R,G,B,A e rasteriza esse ponto na memória de vídeo atravès de um framework fornecido em: https://github.com/capagot/icg/tree/master/mygl_framework.

Algoritmo: 

```
DesenhaPonto(x,y,valor R,valor G,,valor B,valor A){
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor R;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor G;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor B;
  fb_ptr[4*x+ 4*y*IMAGE_WIDTH + 0]  = valor A;
}  
```
Após a aplicação do algoritmo acima, obteve-se o seguinte resultado: 

![Figura 1 - Desenhando um ponto](https://user-images.githubusercontent.com/66951092/85498909-f9edad80-b5b6-11ea-9be6-353313f7d6ba.png)
*Figura 1 - Desenhando um ponto*

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


![Figura 2 - Teste inicial: Desenho de linhas](https://user-images.githubusercontent.com/66951092/85497796-ed685580-b5b4-11ea-9c9b-f601a685a257.jpeg)
*Figura 2 - Teste inicial: Desenho de linhas*

![Figura 3 - Teste final: Desenho de linhas](https://user-images.githubusercontent.com/66951092/85497806-f22d0980-b5b4-11ea-984c-df3e296af453.jpeg)
*Figura 3 - Teste final: Desenho de linhas*



# III) Interpolação de Cores: desenhando linha e triângulo

Por fim, foi feito uma interpolação das cores para o desenho da linha e triângulo. Previamente haviamos definido a cor do "objeto" a ser desenhado através dos seus parâmetros (r,g,b,a), agora define-se mais quatro parâmetros (r1,g1,b1,a1) para a segunda cor, logo a relação da interpolação das cores a ser calculada antes da chamada da função de desenho é dada pelo seguinte trecho de código: 

```
	float dr = (r1-r)/dx;
	float dg = (g1-g)/dx;
	float db = (b1-b)/dx;
	float da = (a1-a)/dx;	
```
Assim, obteve-se os seguintes resultados:

![Figura 4 - Interpolação de cores: linha](https://user-images.githubusercontent.com/66951092/85497812-f3f6cd00-b5b4-11ea-9dbc-8eb6949782e0.jpeg)
*Figura 4 - Interpolação de cores: linha*

![Figura 5 - Interpolação de cores: triângulo](https://user-images.githubusercontent.com/66951092/85497816-f5c09080-b5b4-11ea-861d-40de34db9f80.jpeg)
*Figura 5 - Interpolação de cores: triângulo*

# IV) Dificuldades e possíveis melhoras

Para a execução desse trabalho, houve uma dificuldade considerável para generalizar o Algoritmo de Bresenham e para desenvolver a interpolação de cores. Uma possível melhoria pro trabalho seria a otimização do código com estruturas ou funções.

# V) Referências

Notas de Aula da disciplina de Introdução à Computação Gráfica.

## Trabalho 2: Compilando e Executando um Programa OpenGL Moderno <a name="introduction2"></a>

O teste pode ser visualizado através do vídeo no link: https://youtu.be/6ezLbbMFD6w

Esse trabalho consiste na verificação do ambiente de desenvolvimento em OpenGl 3.3. Assim, para essa tarefa foi fornecido o seguinte diretório no github https://github.com/capagot/icg/tree/master/hello_world_gl/modern_opengl. Dessa forma, realizou-se uma compilação inicial para observar se o resultado retornado à tela do usuário corresponde a um triângulo colorido.

![Figura 1: Mensagem de retorno](https://user-images.githubusercontent.com/66951092/85546087-f11acd00-b5f2-11ea-9418-ad78f4fac454.jpg)
*Figura 1: Mensagem de retorno*

![Figura 2: Mensagem de retorno](https://user-images.githubusercontent.com/66951092/85546094-f1b36380-b5f2-11ea-9051-a95a165f9e05.jpg)
*Figura 2: Mensagem de retorno*

Como observado, ainda não foi possível obter o triângulo, logo, foi feito mais alguns testes até que foi retornado a seguinte mensagem no terminal:

![Figura 3: Mensagem de retorno](https://user-images.githubusercontent.com/66951092/85546099-f2e49080-b5f2-11ea-9f0a-db4315fe1d1e.jpg)
*Figura 3: Versão OpenGl*

A figura 3 mostra que o OpenGL instalado na máquina é inferior a versão 3.3 do OpenGl, logo foi necessário realizar atualizações na máquina de forma a atualizar o OpenGl. Para isso foi realizado consultas na internet, de forma a achar os seguintes comandos para serem executados:

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

Portanto, obteve-se o seguinte resultado

![Figura 4: Triângulo Colorido](https://user-images.githubusercontent.com/66951092/85546104-f415bd80-b5f2-11ea-8bd5-cd7ea476e8be.jpg)
*Figura 4: Triângulo Colorido*

# Referências:

https://pt.wikihow.com/Instalar-Mesa-(OpenGL)-no-Linux-Mint

https://stackoverflow.com/questions/52592309/0110-error-glsl-3-30-is-not-supported-ubuntu-18-04-c

## Trabalho 3: Pipeline Gáfico <a name="introduction3"></a>

Esse trabalho consiste em aplicar conceitos de transformações geométricas através do OpenGL, GLM, Glew e C++. Onde o código foi fornecido pelo professor da disciplina através do repositório: https://github.com/capagot/icg. Com o código pronto para compilação, foram realizadas alterações nas matrizes 'model, 'view' e 'projection' de forma a gerar as imagens solicitadas na descrição do projeto. A seguir apresenta-se os resultados obtidos para cada transformação geométrica:

Exercício 1: Escala - No espaço bidimensional, essa transformação consiste em pegar as coordenadas x, y e z e modificar a largura e altura da figura original através da matriz model.

![p1](https://user-images.githubusercontent.com/66951092/88800401-7b1ffd80-d17e-11ea-940e-5b02261d21a8.jpg)
![p2](https://user-images.githubusercontent.com/66951092/88800453-8d9a3700-d17e-11ea-9edc-fe776997719e.jpg)

Exercício 2:  Translação - Essa transformação move um elemento de sua posição atual de acordo com as coordenadas da matriz model.

![p3](https://user-images.githubusercontent.com/66951092/88800455-8f63fa80-d17e-11ea-8f2e-21bcc8feb4dd.jpg)
![p4](https://user-images.githubusercontent.com/66951092/88800457-90952780-d17e-11ea-95b2-96464e2f6fc6.jpg)

 Exercício 3: Projeção Perspectiva - Usada para tornas os objetos realísticos, onde a sua modelagem é caracterizada por: 
 
Primeiramente, temos:
 
 ![proj1](https://user-images.githubusercontent.com/66951092/88867360-9cff9b80-d1e3-11ea-840b-467f66567f77.png)
 
 "As coordenadas (x,y), da projeção perspectiva P'' de qualquer ponto P de coordenadas (x,y,z), colocado do lado oposto de CP, em relação ao plano de projeção PI, é obtido criando-se uma linha L de P até CP e calculando-se a intersecção desta com o plano PI. A figura 2 exemplifica o cálculo de P".
 
 ![proj2](https://user-images.githubusercontent.com/66951092/88867355-98d37e00-d1e3-11ea-85d4-2755531d9163.png)

Assim, é possível calcular P'' e por fim obter por semelhança de triângulo o valor da distância focal. Uma vez que obtida a expressão da distância focal, obteve-se através das notas de aula a matriz de projeção apresentada no código.

![p5](https://user-images.githubusercontent.com/66951092/88800458-91c65480-d17e-11ea-8155-6895cb42fe73.jpg)
![p6](https://user-images.githubusercontent.com/66951092/88800459-93901800-d17e-11ea-81ce-bc1c6fdf2abf.jpg)

Exercício 4: Posição da Câmera -  é uma transformação de um objeto e de sua área circundante que difere significativamente da aparência do objeto com uma distância focal normal , devido à escala relativa de características próximas e distantes.

![p7](https://user-images.githubusercontent.com/66951092/88800463-94c14500-d17e-11ea-9548-ebc387ac874b.jpg)
![p8](https://user-images.githubusercontent.com/66951092/88800467-97239f00-d17e-11ea-819c-effed861cbc1.jpg)

Exercício 5: Transformações Livres - nessa transformações mudou-se os valores da matrizes 'model, 'view' e 'projection' simultaneamente.

![p9](https://user-images.githubusercontent.com/66951092/88800469-9854cc00-d17e-11ea-9672-cbcd4faaad46.jpg)
![p10a](https://user-images.githubusercontent.com/66951092/88800470-9985f900-d17e-11ea-82ee-3a06c2e0b3e5.jpg)
![p10b](https://user-images.githubusercontent.com/66951092/88800473-9ab72600-d17e-11ea-99f6-c1be01dbe534.jpg)
![p10c](https://user-images.githubusercontent.com/66951092/88800475-9be85300-d17e-11ea-9d8d-5dbd9b00f62c.jpg)

Conclusão: O trabalho foi relevante para a obtenção de conhecimentos matemáticos e computacionais na área de computação gráfica. Uma possível melhoria para o trabalho seria um estudo mais aprofundado no tópico de distorção perspectiva.


Referências:

1. https://www.inf.pucrs.br/~pinho/CG/Aulas/Vis3d/Vis3d.htm#:~:text=A%20modelagem%20matem%C3%A1tica%20da%20proje%C3%A7%C3%A3o,Centro%20de%20Proje%C3%A7%C3%A3o(CP).
2. https://en.wikipedia.org/wiki/Perspective_distortion_(photography)


