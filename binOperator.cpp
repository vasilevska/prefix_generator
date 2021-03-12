#include "binOperator.h"

bool operator>(const BinOperator& b1, const BinOperator& b2)
{
	return b1.prioritet > b2.prioritet;
}
