#include "MineElement.h"

MineElement::MineElement()
{
}

MineElement::~MineElement()
{
}

ElementStatus MineElement::GetStatus() const
{
	return Mine;
}

char MineElement::GetValue() const
{
	return 'M';
}

void MineElement::IncrementValue()
{
}
