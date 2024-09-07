#pragma once

template <typename T>
class IDeck
{
	virtual void shuffle() = 0;
	virtual T draw() = 0;
};