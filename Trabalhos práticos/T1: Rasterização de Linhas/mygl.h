#ifndef MYGL_H
#define MYGL_H

#include "core.h"	
#include "frame_buffer.h"

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);
void PutPixel(int dx, int dy, int r, int g, int b, int a);
void DrawLine(int x0, int y0, int x1, int y1, int r, int g, int b, int a, int r1, int g1, int b1, int a1);
void DrawTriangle(int x0,int y0,int x1,int y1,int x2,int y2, int r, int g, int b, int a, int r1, int g1, int b1, int a1);


//
// >>> Declare aqui as funções que você implementar <<<
//


#endif  // MYGL_H
