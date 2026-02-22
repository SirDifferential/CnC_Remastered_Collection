#include "FUNCTION.H"
#include "VECTOR.H"
#include "TYPE.H"
#include "DEFINES.H"
#include "BUILDORDER.H"

BuildOrder::BuildOrder()
{
	itemsLeft = -1;	
}

void BuildOrder::addToBuildOrder(StructType item)
{
	buildOrder.Add(item);
	itemsLeft++;
}

StructType BuildOrder::getNext() {
	if (itemsLeft < 0) {
		return STRUCT_NONE;
	}
	return buildOrder[itemsLeft];
}

void BuildOrder::markCurrentDone() {
	itemsLeft--;
}

