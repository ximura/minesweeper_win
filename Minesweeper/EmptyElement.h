#pragma once
#include "Element.h"
class EmptyElement : public Element
{
public:
	EmptyElement();
	virtual ~EmptyElement();

	virtual ElementStatus GetStatus() const;
	virtual int GetValue() const;
	virtual char GetValueStr() const;

	virtual void IncrementValue();

	virtual bool WasChecked() const;
	virtual void Check();

private:
	int counter;
	bool check;
};

