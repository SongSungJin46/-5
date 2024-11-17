#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Shape {
public:
    virtual void Draw() const = 0; 
    virtual ~Shape() {}           
};


class Line : public Shape {
public:
    void Draw() const override {
        cout << "Line" << endl;
    }
};


class Circle : public Shape {
public:
    void Draw() const override {
        cout << "Circle" << endl;
    }
};


class Rectangle : public Shape {
public:
    void Draw() const override {
        cout << "Rectangle" << endl;
    }
};


class GraphicEditor {
private:
    vector<Shape*> shapes;

public:
    ~GraphicEditor() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }

    void InsertShape(int type) {
        switch (type) {
        case 1:
            shapes.push_back(new Line());
            cout << "Line ���� �Ϸ�!" << endl;
            break;
        case 2:
            shapes.push_back(new Circle());
            cout << "Circle ���� �Ϸ�!" << endl;
            break;
        case 3:
            shapes.push_back(new Rectangle());
            cout << "Rectangle ���� �Ϸ�!" << endl;
            break;
        default:
            cout << "�߸��� �Է��Դϴ�!" << endl;
        }
    }

    void DeleteShape(int index) {
        if (index < 0 || index >= shapes.size()) {
            cout << "��ȿ���� ���� �ε����Դϴ�!" << endl;
        }
        else {
            delete shapes[index];               
            shapes.erase(shapes.begin() + index);
            cout << "���� ���� �Ϸ�!" << endl;
        }
    }

    void ShowShapes() const {
        if (shapes.empty()) {
            cout << "����� ������ �����ϴ�!" << endl;
            return;
        }
        for (size_t i = 0; i < shapes.size(); ++i) {
            cout << i << ": ";
            shapes[i]->Draw();
        }
    }

    void Run() {
        int command;
        while (true) {
            cout << "�׷��� �������Դϴ�." << endl;
            cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
            cin >> command;

            switch (command) {
            case 1: {
                int shapeType;
                cout << "��:1, ��:2, �簢��:3 >> ";
                cin >> shapeType;
                InsertShape(shapeType);
                break;
            }
            case 2: {
                int index;
                cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
                cin >> index;
                DeleteShape(index);
                break;
            }
            case 3:
                ShowShapes();
                break;
            case 4:
                cout << "���α׷��� �����մϴ�." << endl;
                return;
            default:
                cout << "�߸��� �Է��Դϴ�!" << endl;
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.Run();
    return 0;
}
