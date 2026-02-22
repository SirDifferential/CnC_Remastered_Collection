#ifndef BUILDORDER
#define BUILDORDER

/**
 * Defines a build order for the AI player to follow. These
 * take priority before the normal AI build logic in HOUSE.CPP
 * and allow the AI perform a specific build on a strict leash
 * before the AI is let loose. This ensures the AI builds a
 * sensible foundation before it starts doing whatever.
 *
 * Relevant struct types:
 * 
 * STRUCT_REFINERY,
 * STRUCT_BARRACKS,
 * STRUCT_ADVANCED_POWER,
 * STRUCT_POWER,
 * STRUCT_SOVIET_TECH,
 * STRUCT_ADVANCED_TECH,
 * STRUCT_RADAR,
 * STRUCT_REPAIR,
 * STRUCT_WEAP
 */
class BuildOrder
{
public:
	BuildOrder();

	/**
	 * Adds the given building or unit to the build order.
	 */
	void addToBuildOrder(StructType item);

	/**
	 * Returns the next building or unit to build. If there is nothing left,
	 * STRUCT_NONE is returned.
	 */
	StructType getNext();

	/**
	 * If a building was successfully queued for construction, call this to
	 * remove it from the list.
	 * GEKKO TODO: Maybe use game state for this - ensure buildings exist in
	 * certain quantity instead of using this type of fixed list removal.
	 */
	void markCurrentDone();
private:
	/**
	 * This vector is the list of buildings to make in a specific order.
	 * The AI will follow this list and marks each step complete. Once
	 * the whole list is done, the build order will be forgotten.
	 */
	DynamicVectorClass <StructType> buildOrder;
	int itemsLeft;
};

#endif // #define BUILDORDER

