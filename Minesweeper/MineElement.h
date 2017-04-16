#pragma once
#include "Element.h"

class MineElement : public Element
{
public:
	MineElement();
	virtual ~MineElement();
	
	virtual ElementStatus GetStatus() const;
	virtual char GetValue() const;
	virtual void IncrementValue();
};

