#pragma once
#include "ElementStatus.h"

class Element
{
public:
	virtual ~Element() {}

	virtual ElementStatus GetStatus() const = 0;

	virtual int GetValue() const = 0;
	virtual char GetValueStr() const = 0;
	virtual void IncrementValue() = 0;

	virtual bool WasChecked() const = 0;
	virtual void Check() = 0;
};

