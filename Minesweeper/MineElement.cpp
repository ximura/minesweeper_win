#include "MineElement.h"

MineElement::MineElement()
{
}

MineElement::~MineElement()
{
}

ElementStatus MineElement::GetStatus() const
{
	return ElementStatus::Mine;
}

int MineElement::GetValue() const
{
	return 0;
}

char MineElement::GetValueStr() const
{
	return 'M';
}

void MineElement::IncrementValue()
{
}

bool MineElement::WasChecked() const
{
	return false;
}

void MineElement::Check()
{
}
