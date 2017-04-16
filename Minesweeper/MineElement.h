#pragma once
#include "Element.h"

class MineElement : public Element
{
public:
	MineElement();
	virtual ~MineElement();
	
	virtual ElementStatus GetStatus() const;
	virtual int GetValue() const;
	virtual char GetValueStr() const;
	virtual void IncrementValue();

	virtual bool WasChecked() const;
	virtual void Check();
};

