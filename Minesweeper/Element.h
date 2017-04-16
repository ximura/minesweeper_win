#pragma once
#include "ElementStatus.h"

class Element
{
public:
	virtual ~Element() {}

	virtual ElementStatus GetStatus() const = 0;
	virtual char GetValue() const = 0;
	virtual void IncrementValue() = 0;
};

