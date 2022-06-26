#include "MineField.h"
#include "Element.h"
#include "MineElement.h"
#include "EmptyElement.h"

#include <random>
#include <cstdlib>
#include <stdio.h>

MineField::MineField(int _mines, int _width, int _height) : width(_width), height(_height), mines(_mines)
{
    elements = new Element*[_width * _height];
    for (int i = 0; i < height * width; ++i)
    {
        elements[i] = 0;
    }

    GenerateField();
}

MineField::~MineField()
{
    for (int i = 0; i < height * width; ++i)
    {
        delete elements[i];
    }

    delete[] elements;
}

void MineField::PrintFullField() const
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            const Element* element = GetElement(j, i);
            printf("%c ", element->GetValueStr());
        }
        printf("\n");
    }
}

void MineField::PrintField() const
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            const Element* element = GetElement(j, i);
            printf("%c ", element->WasChecked() ? element->GetValueStr() : '?');
        }
        printf("\n");
    }
}

bool MineField::IsMine(int x, int y)
{
    Element* element = GetElement(x, y);

    if (ElementStatus::Mine == element->GetStatus())
        return true;

    Check(x, y);

    return false;
}

void MineField::GenerateField()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> x_distrib(0, width - 1);
    std::uniform_int_distribution<> y_distrib(0, height - 1);

    for (size_t i = 0; i < width * height; ++i)
    {
        Element* element = elements[i];
        elements[i] = new EmptyElement();
    }

    int closeTiles[] = { 1, 0, -1 };

    int mineCounter = 0;
    while (mineCounter < mines)
    {
        int x = x_distrib(gen);
        int y = y_distrib(gen);

        Element* element = GetElement(x, y);
        if (ElementStatus::None == element->GetStatus())
        {
            delete element;
            int index = GetElementIndex(x, y);
            elements[index] = new  MineElement();
            // mine was added increment  counter
            // we can generate mine with same index so we need to repeat this iteration
            ++mineCounter;

            //increment counter for neighbours
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    int new_x = x + closeTiles[k];
                    int new_y = y + closeTiles[j];
                    Element* element = GetElement(new_x, new_y);
                    if (element)
                        element->IncrementValue();
                }
            }
        }
    }
}

Element* MineField::GetElement(int x, int y) const
{
    if (x < 0 || x > width)
        return nullptr;

    if (y < 0 || y > height)
        return nullptr;

    int index = GetElementIndex(x, y);

    return GetElement(index);
}

Element* MineField::GetElement(int index) const
{
    if (index >= width * height)
        return nullptr;

    if (index < 0)
        return nullptr;

    return elements[index];
}

void MineField::Check(int x, int y)
{
    Element* element = GetElement(x, y);

    if (!element)
        return;

    if (element->WasChecked()) return;

    element->Check();

    if (element->GetValue() > 0) return;

    Check(x + 1, y);
    Check(x - 1, y);

    Check(x + 1, y + 1);
    Check(x, y + 1);
    Check(x - 1, y + 1);

    Check(x + 1, y - 1);
    Check(x, y - 1);
    Check(x - 1, y - 1);
}

const Element* MineField::PutMine(int& x, int& y)
{
    x = std::rand() % width;
    y = std::rand() % height;

    int index = GetElementIndex(x, y);
    Element* element = elements[index];
    if (ElementStatus::Mine == element->GetStatus())
        return nullptr;

    delete element;
    elements[index] = new  MineElement();
    return elements[index];
}

int MineField::GetElementIndex(int x, int y) const
{
    return (y * width) + x;
}
