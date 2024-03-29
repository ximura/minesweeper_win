#pragma once
#include <vector>
#include <memory>

class Element;

class MineField
{
public:
    MineField(int _mines, int _width, int _height);
    ~MineField();

    bool IsMine(int x, int y) const;
    void Check(int x, int y);

    void PrintField() const;
    void PrintFullField() const;

private:
    void GenerateField();

    std::shared_ptr<Element> GetElement(int x, int y) const;
    std::shared_ptr<Element> GetElement(int index) const;

    int GetElementIndex(int x, int y) const;

private:
    std::vector<std::shared_ptr<Element>> elements;

    int width;
    int height;
    int mines;
};

