#include "sequence1.h"
#include <cassert>

namespace main_savitch_3
{
	sequence::sequence()
	{
	//     Postcondition: The sequence has been initialized as an empty sequence.

		current_index = 0;
		used = 0;
	}

	void sequence::start()
	{
	//     Postcondition: The first item on the sequence becomes the current item
	//     (but if the sequence is empty, then there is no current item).
		
		current_index = 0;
	}

	void sequence::advance()
	{
	//     Precondition: is_item returns true.
	//     Postcondition: If the current item was already the last item in the
	//     sequence, then there is no longer any current item. Otherwise, the new
	//     current item is the item immediately after the original current item.
		assert(is_item());
		current_index++;
		
	}

	void sequence::insert(const value_type& entry)
	{
	//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence
	//     before the current item. If there was no current item, then the new entry 
	//     has been inserted at the front of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.
		//assert(size() < CAPACITY);
		/*for (int i = used; i > current_index; i--)
		{
			data[i] = data[i - 1];
			data[current_index] = entry;
			used++;
		}*/
		
		int i;
		assert(size() < CAPACITY);
		if (is_item() == false)
		{
			current_index = 0;
		}
		for (i = used; i > current_index; i--) 
		{
			data[i] = data[i - 1];
		}
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
	//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence after
	//     the current item. If there was no current item, then the new entry has 
	//     been attached to the end of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.
		
		assert(size() < CAPACITY);

		for (int i = used; i > current_index; i--)
		{
			
			data[i] = data[i + 1];
			
		}
		data[current_index] = entry;
		used++;
		
	}

	void sequence::remove_current()
	{
	//     Precondition: is_item returns true.
	//     Postcondition: The current item has been removed from the sequence, and the
	//     item after this (if there is one) is now the new current item.
		int i;
		assert(is_item());
		const int old_used = used; 
		for (i = current_index + 1; i < used - 1; i++)
		{
			data[i] = data[i + 1];
			used--;
		}
		assert(used == old_used - 1);
		
	}

	sequence::size_type sequence::size() const 
	{
	//     Postcondition: The return value is the number of items in the sequence.
		return used;
	}

	bool sequence::is_item() const
	{
	//     Postcondition: A true return value indicates that there is a valid
	//     "current" item that may be retrieved by activating the current
	//     member function (listed below). A false return value indicates that
	//     there is no valid current item.
		return current_index < used;
		
	}

	sequence::value_type sequence::current() const
	{
	//     Precondition: is_item( ) returns true.
	//     Postcondition: The item returned is the current item in the sequence.
		return data[current_index];

	}
}