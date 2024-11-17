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
            cout << "Line 삽입 완료!" << endl;
            break;
        case 2:
            shapes.push_back(new Circle());
            cout << "Circle 삽입 완료!" << endl;
            break;
        case 3:
            shapes.push_back(new Rectangle());
            cout << "Rectangle 삽입 완료!" << endl;
            break;
        default:
            cout << "잘못된 입력입니다!" << endl;
        }
    }

    void DeleteShape(int index) {
        if (index < 0 || index >= shapes.size()) {
            cout << "유효하지 않은 인덱스입니다!" << endl;
        }
        else {
            delete shapes[index];               
            shapes.erase(shapes.begin() + index);
            cout << "도형 삭제 완료!" << endl;
        }
    }

    void ShowShapes() const {
        if (shapes.empty()) {
            cout << "저장된 도형이 없습니다!" << endl;
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
            cout << "그래픽 에디터입니다." << endl;
            cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
            cin >> command;

            switch (command) {
            case 1: {
                int shapeType;
                cout << "선:1, 원:2, 사각형:3 >> ";
                cin >> shapeType;
                InsertShape(shapeType);
                break;
            }
            case 2: {
                int index;
                cout << "삭제하고자 하는 도형의 인덱스 >> ";
                cin >> index;
                DeleteShape(index);
                break;
            }
            case 3:
                ShowShapes();
                break;
            case 4:
                cout << "프로그램을 종료합니다." << endl;
                return;
            default:
                cout << "잘못된 입력입니다!" << endl;
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.Run();
    return 0;
}
