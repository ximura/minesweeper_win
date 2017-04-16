#include "EmptyElement.h"



EmptyElement::EmptyElement() : counter(0)
{
}


EmptyElement::~EmptyElement()
{
}

ElementStatus EmptyElement::GetStatus() const
{
	return None;
}

char EmptyElement::GetValue() const
{
	return '0' + counter;
}

void EmptyElement::IncrementValue()
{
	++counter;
}
