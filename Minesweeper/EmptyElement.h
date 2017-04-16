#pragma once
#include "Element.h"
class EmptyElement : public Element
{
public:
	EmptyElement();
	virtual ~EmptyElement();

	virtual ElementStatus GetStatus() const;
	virtual char GetValue() const;

	virtual void IncrementValue();

private:
	int counter;
};

