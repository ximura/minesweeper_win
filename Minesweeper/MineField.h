#pragma once
class Element;

class MineField
{
public:
	MineField(int _mines, int _width, int _height);
	~MineField();

	void PrintField() const;

	void PrintFullField() const;

	bool IsMine(int x, int y);

private:
	void GenerateField();

	const Element* PutMine(int& x, int& y);

	Element* GetElement(int x, int y) const;
	Element* GetElement(int index) const;

	void Check(int x, int y);

private:
	Element** elements;

	int width;
	int height;
	int mines;
};

