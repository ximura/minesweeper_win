#include "MineField.h"
#include "Element.h"
#include "MineElement.h"
#include "EmptyElement.h"

#include <cstdlib>
#include <ctime>
#include <stdio.h>

MineField::MineField(int _mines, int _width, int _height): width(_width), height(_height), mines(_mines)
{
	elements = new Element*[_width*_height];
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

void MineField::PrintField() const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			const Element* element = GetElement(j, i);
			printf("%c ", element->GetValue());
		}
		printf("\n");
	}
}

bool MineField::IsMine(int x, int y)
{
	const Element* element = GetElement(x, y);

	if (Mine == element->GetStatus())
		return true;

	return false;
}

void MineField::GenerateField()
{
	std::srand(std::time(0)); // use current time as seed for random generator
	
	for (size_t i = 0; i < width * height; ++i)
	{
		Element* element = elements[i];
		elements[i] = new EmptyElement();
	}

	int closeTiles[] = { 1, 0, -1 };

	for (int i = 0; i < mines; ++i)
	{
		int x = 0;
		int y = 0;

		while (PutMine(x, y) == 0);

		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				int new_x = x + closeTiles[k];
				if (new_x < 0 || new_x >= width)
					continue;

				int index = ((y + closeTiles[j]) * width) + new_x;
				Element* element = GetElement(index);
				if (element)
					element->IncrementValue();
			}
		}
	}
}

const Element* MineField::GetElement(int x, int y) const
{
	int index = (y * width) + x;

	const Element* element = GetElement(index);
	return element;
}

Element * MineField::GetElement(int index) const
{
	if (index >= width * height)
		return 0;

	if (index < 0)
		return 0;

	return elements[index];
}

const Element* MineField::PutMine(int& x, int& y)
{
	x = std::rand() % width;
	y = std::rand() % height;

	int index = (y * width) + x;
	Element* element = elements[index];
	if (element->GetStatus() == Mine)
		return 0;

	delete element;
	elements[index] = new  MineElement();
	return elements[index];
}
