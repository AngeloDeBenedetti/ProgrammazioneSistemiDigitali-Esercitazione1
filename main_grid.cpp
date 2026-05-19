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

void ShowAllPolygons(Shape* shapes[], int* nShape);
void ModifyPolygon(Shape* shapes[], int* nShape);
void MovePolygon(Shape* shapes[], int* nShape);
void DeletePolygon(Shape* shapes[], int* nShape);
void CreatePolygon (Shape* shapes[], int* nShape);
void DeleteAllPoly (Shape* shapes[], int* nShape);

int main()
{
    Shape* shapes[MAX_SHAPES] = {NULL}; //array di puntatori a shape//
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
            return 0;
        }

        switch(opt){
            case 1:
            ShowAllPolygons(shapes, &nShapes);
            break;
            case 2:
            ModifyPolygon(shapes, &nShapes);
            break;
            case 3:
            MovePolygon(shapes, &nShapes);
            break;
            case 4:
            CreatePolygon(shapes, &nShapes);
            break;
            case 5:
            DeletePolygon(shapes, &nShapes);
            break;
            case 6:
            DeleteAllPoly (shapes, &nShapes);
            break;
            default:
            cout <<"The selection isn't valid. Please enter a valid selection" << endl;
            }
        
        opt = 0;
    }

}

void ShowAllPolygons(Shape* shapes[], int* nShape)
{
    int nShapes = (*nShape);
    for(int i = 0; i < MAX_SHAPES; i++)
    {
    if(shapes[i] != NULL)
        {
        cout << endl << "Polygon [" << i << "]" << endl;
        shapes[i]->Info();
        }
    }
}
void ModifyPolygon(Shape* shapes[], int* nShape)
{
    while(true)
    {    
        int nShapes = (*nShape);
        int sel = 0;
        float nh = 0;
        float nw = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= MAX_SHAPES || shapes[sel] == NULL)
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

void MovePolygon(Shape* shapes[], int* nShape)
{
    while(true)
    {    
        int nShapes = (*nShape);
        int sel = 0;
        float nx = 0;
        float ny = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= MAX_SHAPES || shapes[sel]== NULL)
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

void DeletePolygon(Shape* shapes[], int* nShape)
{
while(true)
    {    
        int nShapes = (*nShape);
        int sel = 0;
        int ok = 0;
        cout <<"Please enter the Polygon's number or -1 to go back" << endl;
        cin >> sel;
        if (sel == -1)
        {
            return;
        }
        else if (sel < 0 || sel >= MAX_SHAPES)
        {
            cout << "The selection isn't valid. Please enter a valid selection"<< endl;
            sel = 0;
            continue;
        }
        else
        {
            if(shapes[sel] == NULL)
            {
                cout <<"the polygon does not exist"<< endl;
                continue;
            }
            
            cout << "Selected object:" << endl;
            shapes[sel]->Info();
            cout <<"Enter 1 to confirm or -1 to cancel"<< endl;
            cin >> ok;
            switch(ok){
            case 1:
            delete shapes[sel];
            shapes[sel] = NULL;
            (*nShape)--;
            return;
            case -1:
            continue;
            break;
            default:
            ok = 0;
            }
        }
    }
}

void CreatePolygon (Shape* shapes[], int* nShape)
    {
        if (*nShape == (MAX_SHAPES - 1))
        {
            cout << "No more space available." << endl;
            return;
        }
        float x= 0.0,y=0.0,w=0.0,h = 0.0; int sel = 0;
        for(int i=0; i < MAX_SHAPES; i++)
        {
            if(shapes[i] == NULL)
            {
                cout <<"Please select the type of object to be created:"<< endl <<"1- Rectangle" << endl << "2- Rhombus"<< endl << "3- Isosceles Triangle"<< endl;
                cin >> sel;
                if(sel != 1 && sel!= 2 && sel!= 3)
                {
                    cout <<"invalid selection."<< endl;
                    return;
                }
                cout <<"please enter new object's x and y position" << endl;
                cin >> x >> y;
                cout << "please enter new object's width and height" << endl;
                cin >> w >> h; 
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
                    break;
                   
                }
                (*nShape)++;
                sel=0;
                if(shapes[i]== NULL)
                {
                    cout << "Error. The polygon was not created" << endl;
                }
                return;
            }
        }
    }

void DeleteAllPoly (Shape* shapes[], int* nShape)
{   
    int nShapes = (*nShape);
    int ok = 0;
    cout <<"Are you sure you want to delete ALL polygons?" << endl << "1 -YES" << "-1 - NO" << endl;
    cin >> ok;
    if(ok != 1 && ok != -1)
    {
        cout << "invalid input."<< endl;
    }
    else if(ok == 1)
    {
        for (int i = 0; i < MAX_SHAPES; i++) 
        {
        
            if(shapes[i] != NULL)
                {cout << endl << "Figura [" << i << "]" << endl;
                delete shapes[i];
                shapes[i] = NULL;
                (*nShape)--;
            }
        }
    }
    else if( ok == -1)
    {
        cout << "operation canceled" << endl;
    }
}