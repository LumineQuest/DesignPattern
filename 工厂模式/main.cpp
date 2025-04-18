#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle::draw() method.\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Inside Square::draw() method.\n";
    }
};

class Circle : public Shape {
public: 
    void draw() override {
        std::cout << "Inside Circle::draw() method.\n";
    }
};

class ShapeFactore {
public:
    // 通过类型获取实例
    Shape* getShape(const std::string &shapeType) {
        if (shapeType.empty()) {
            return nullptr;
        }
        if ("RECTANGLE" == shapeType) {
            return new Rectangle();

        } else if ("SQUARE") {
            return new Square();
        } else if ("CIRCLE" == shapeType) {
            return new Circle();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactore shapeFactore;
    Shape *circle = shapeFactore.getShape("CIRCLE");
    if (circle != nullptr){
        circle->draw();
    }
    Shape *rectangle = shapeFactore.getShape("RECTANGLE");
    if (rectangle != nullptr) {
        rectangle->draw();
    }
    Shape *square = shapeFactore.getShape("SQUARE");
    if (square != nullptr) {
        circle->draw();
    }
}