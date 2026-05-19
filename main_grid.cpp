#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

//QUESTO MAIN CONTIENE SOLO GLI ESERCIZI PER LA SECONDA PARTE DI ESERCITAZIONE. PER LA PRIMA PARTE USARE "main_draft"//

#define MAX_SHAPES 10 //lascio questo vincolo, ma potrebbe essere modificato per gestire quante shape si desidera//
#define MAX_X 100.0
#define MAX_Y 100.0

void ShowAllPolygons(Shape* shapes[]);
void ModifyPolygon(Shape* shapes[]);
void MovePolygon(Shapes* shapes[]);
void DeletePolygon(Shape* shapes[]);
void CreatePolygon (Shape* shapes[]);
void DeleteAllPoly (Shape* shapes[]);

int main()
{
    Shape* shapes[MAX_SHAPES]; //array di puntatori a shape//
    int nShapes = 0;
    int opt = 0;
    while(true)
    {
        cout << endl << "Welcome to the Grid. Please enter a command:"<< endl;
        cout << endl << "1 - See existing Polygons" << endl;
        cout << endl << "2 - modify an existing Polygon" << endl;
        cout << endl << "3 - move an existing Polygon" << endl;
        cout << endl << "4 - Create a new Polygon" << endl;
        cout << endl << "5 - Delete an existing Polygon" << endl;
        cout << endl << "6 - Delete ALL Polygons" << endl;
        cout << endl << "-1 - Close the program" << endl; //avrei anche potuto mettere la condizione nel while, ma in questo modo so che il programma viene terminato immediatamente

        cin >> opt;

        if (opt == -1)
        {
            return;
        }

        switch(opt){
            case 1:
            ShowAllPolygons(shapes);
            break;
            case 2:
            ModifyPolygon(shapes);
            break;
            case 3:
            MovePolygon(shapes);
            break;
            case 4:
            CreatePolygon(shapes);
            break;
            case 5:
            DeletePolygon(shapes);
            break;
            case 6:
            DeleteAllPoly (shapes);
            break;
            default:
            cout <<"The selection isn't valid. Please enter a valid selection" << endl;
            }
        
        opt = 0;
    }

}

void ShowAllPolygons(Shape* shapes[])
{
    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Polygon [" << i << "]" << endl;
        shapes[i]->info();}
}

void ModifyPolygon(Shape* shapes[])
{
    while(true)
    {    
        int sel = 0;
        float nh = 0;
        float nw = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= nShapes)
        {
            cout << "The selection isn't valid. Please enter a valid selection"<< endl;
            continue;
        }
        else {
        cout << "please enter the new Polygon's height"<< endl;
        cin >> nh;
        shapes[sel]->SetHeight(nh);
        cout << "please enter the new Polygon's width"<< endl;
        cin >> nw;
        shapes[sel]->SetWidth(nw);
        return;}
    }
}

void MovePolygon(Shapes* shapes[])
{
    while(true)
    {    
        int sel = 0;
        float nx = 0;
        float ny = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= nShapes)
        {
            cout << "The selection isn't valid. Please enter a valid selection"<< endl;
            continue;
        }
        else {
        cout << "please enter the Polygon's new x position"<< endl;
        cin >> nx;
        cout << "please enter the Polygon's new y position"<< endl;
        cin >> ny;
        shapes[sel]->SetPosition(nx, ny);
        return;}
    }
}

void DeletePolygon(Shape* shapes[])
{
while(true)
    {    
        int sel = 0;
        int ok = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= nShapes)
        {
            cout << "The selection isn't valid. Please enter a valid selection"<< endl;
            sel = 0;
            continue;
        }
        else
        {
            if(shapes[sel] == NULL)
            {
                cout <<"the polygon does not exist"<< endl
                continue;
            }
            
            cout << "Selected object:" << endl;
            shapes[sel]->info();
            cout <<"Enter 1 to confirm or -1 to cancel"
            cin >> ok;
            switch(ok){
            case 1;
            shapes[sel]->~Shape();
            break;
            case -1:
            continue;
            break
            default:
            ok = 0;
            }
        }
    }
}

void CreatePolygon (Shape* shapes[])
    {
        float x,y,w,h = 0; int sel = 0;
        for(int i=0; i < MAX_SHAPES; i++)
        {
            if(shapes[i] == NULL)
            {
                cout <<"Please select the type of object to be created:"<< endl <<"1- Rectangle" << endl << "2- Rhombus"<< endl << "3- Isosceles Triangle"<< endl;
                cin >> sel >> endl;
                if(sel =! 1 || sel=! 2 || sel=! 3)
                {
                    cout <<"invalid selection."<< endl;
                    return;
                }
                cout <<"please enter new object's x and y position" << endl;
                cin >> x >> y >> endl;
                cout << "please enter new object's width and height" << endl;
                cin >> w >> h >> endl; 
                switch (sel){
                    case 1:
                    shapes[i]= new Rectangle(x, y, w, h);
                    break;
                    case 2:
                    shapes[i]= new Rhombus(x, y, w, h);
                    break;
                    case 3:
                    shapes[i]= new IsoscelesTriangle(x, y, w, h);
                    break;
                    default:
                    sel=0;
                }
                
                if(shapes[i]== NULL)
                {
                    cout << "Error. The polygon was not created" << endl;
                }
                return;
            }
        }
    }

void DeleteAllPoly (Shape* shapes[])
{
    int ok = 0;
    cout <<"Are you sure you want to delete ALL polygons?" << endl << "1 -YES" << "-1 - NO" << endl;
    cin >> ok >> endl;
    if(ok =! 1 || ok =! -1)
    {
        cout << "invalid input."<< endl;
    }
    else if(ok == 1)
    {
        for (int i = 0; i < nShapes; i++) 
        {
        
            if(shapes[i] =! NULL)
                {cout << endl << "Figura [" << i << "]" << endl;
                shapes[i]->~Shape();}
        }
    }
    else if( ok == -1)
    {
        cout << "operation canceled" << endl;
    }
}