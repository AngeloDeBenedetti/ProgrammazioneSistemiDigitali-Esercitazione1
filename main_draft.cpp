#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new IsoscelesTriangle(3, 4, 5, 8);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("Triangolo Isoscele");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    //4.Scala
    cout << endl << "===== MODIFICA DI SCALA =====" << endl;

    cout << endl << "=SCALA X3 =" << endl;
    for (int i = 0; i < nShapes; i++) {
        shapes[i]->Scale(3.0);
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();}
    
    cout << endl << "=SCALA NEGATIVA =" << endl;
    for (int i = 0; i < nShapes; i++) {
        shapes[i]->Scale(-1);
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();}
    
    cout << endl << "=SCALA x0.5 =" << endl;
    for (int i = 0; i < nShapes; i++) {
        shapes[i]->Scale(0.5);
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();}


    
    //5. Distruttore 
    cout << endl << "===== DISTRUZIONE SHAPE DA ARRAY =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->~Shape();
    }
    
    return 0;
}