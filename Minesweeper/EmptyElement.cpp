#include "EmptyElement.h"



EmptyElement::EmptyElement() : counter(0), check(false)
{
}


EmptyElement::~EmptyElement()
{
}

ElementStatus EmptyElement::GetStatus() const
{
    return ElementStatus::None;
}

int EmptyElement::GetValue() const
{
    return counter;
}

char EmptyElement::GetValueStr() const
{
    return '0' + counter;
}

void EmptyElement::IncrementValue()
{
    ++counter;
}

bool EmptyElement::WasChecked() const
{
    return check;
}

void EmptyElement::Check()
{
    check = true;
}
