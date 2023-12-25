#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pen
{
public:
    string color;
    int thickness;
    string type;

    void Draw()
    {
        cout << "Drawing with: " << color << " pen, thickness: " << thickness << ", type: " << type;
        cout << "\n";
    }
};

class Brush
{
public:
    string color;

    void Fill()
    {
        cout << "Color of filling brush: " << color;
        cout << "\n";
    }
};

class SolidBrush : public Brush
{

};

class GradientBrush : public Brush
{
public:
    vector<string> colors;

    void Fill() {
        cout << "Filling with gradient brush of colors: ";
        for (auto color : colors)
        {
            cout << color << " ";
        }
        cout << "\n";
    }
};

class HatchBrush : public Brush
{
public:
    string secondColor;
    string type;

    void Fill()
    {
        cout << "Filling with hatch brush of type " << type << " and second color " << secondColor;
        cout << "\n";
    }
};

class TextureBrush : public Brush
{
public:
    string image;

    void Fill()
    {
        cout << "Filling with texture brush from image " << image;
        cout << "\n";
    }
};

class LinearGradientBrush : public GradientBrush
{

};

class RadialGradientBrush : public GradientBrush
{

};

class Geometry
{
public:
    Pen pen;
    Brush* brush;
};

class Rectangle : public Geometry
{

};

class Ellipse : public Geometry
{

};

class Polyline : public Geometry
{

};

class Font
{
public:
    int size;
    string style;
    string color;
};

class Button : public Rectangle
{
public:
    string text;
    Font font;

    void Display()
    {
        cout << "Button: " << text << " \nFont: " << font.style << ", " << font.size << ", " << font.color;
        cout << "\n";
    }
};

int main()
{
    Pen pen;
    pen.color = "brown";
    pen.thickness = 3;
    pen.type = "sketch pencil";
    pen.Draw();

    SolidBrush solidBrush;
    solidBrush.color = "white";
    solidBrush.Fill();

    GradientBrush gradientBrush;
    gradientBrush.colors = { "purple,", "pink,", "blue" };
    gradientBrush.Fill();

    Button button;
    button.text = "Click me ;)";
    button.font.style = "Times New Roman";
    button.font.size = 12;
    button.font.color = "pink";
    button.Display();

    return 0;
}