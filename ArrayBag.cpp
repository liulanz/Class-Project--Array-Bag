//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Liu Lan Zheng for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"
#include <cstddef>


/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
	}  // end if
    
	return has_room;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if
    
	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if
      
      cun_index++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same contents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);
      
   return bag_contents;
}  // end toVector



/**
	@return a new ArrayBag that contains all elements from this bag (items_)
	and as many elements from the argument a_bag as space requires. Note
	that it may contain duplicates
	*/
template<class T>
ArrayBag<T> ArrayBag<T>::bagUnion(const ArrayBag<T>& a_bag) const
{
	ArrayBag<T> combined_arrayBag;
	//1) copy all the elements in items_ to combined_arrayBag.items_
	for(int i = 0; i < item_count_; i++)
	{
		combined_arrayBag.add(items_[i]);
	}

	//2)copy elements from a_bag.items_ to combined_arrayBag.items_
	std::vector<T> a_bag_vector = a_bag.toVector();//a vector that has the same contents as items_ in a_bag
	for(int i = 0; i < a_bag.getCurrentSize(); i++)
	{
		combined_arrayBag.add(a_bag_vector[i]); 
	}
	return combined_arrayBag;
}

/**
	@return a new ArrayBag that contains the intersection of the contents
	of this bag and those of the argument a_bag. This intersection does
	not contain duplicates (e.g. every element occurring in BOTH bags will
	be found only once in the intersection, no matter how many
	occurrences in the original bags) as in set intersection A ∩ B
	*/
template<class T>
ArrayBag<T> ArrayBag<T>::bagIntersectionNoDuplicates(const ArrayBag<T>& a_bag) const
{
	ArrayBag<T> intersect_arrayBag;
	std::vector<T> a_bag_vector = a_bag.toVector();//a vector that has the same contents as items_ in a_bag
	for(int i = 0; i < a_bag.getCurrentSize(); i++)//check every element in items_ in a_bag
	{
		if(contains(a_bag_vector[i]))
			intersect_arrayBag.add(a_bag_vector[i]);
	}
	
	std::vector<T> intersect_arrayBag_vector = intersect_arrayBag.toVector();//a vector that has the same contents as items_ in intersect_arrayBag
	for(int i = 0; i < intersect_arrayBag.getCurrentSize(); i++)
	{
	//if elements in items of intersect_arrayBag has a frequency > 1, then remove it
		if (intersect_arrayBag.getFrequencyOf(intersect_arrayBag_vector[i]) > 1)
			intersect_arrayBag.remove(intersect_arrayBag_vector[i]);

	}	
	return  intersect_arrayBag;
}



/**  
	@return a new ArrayBag that contains only those items that occur in this
	bag or in a_bag but not in both,
	*/
template <class T>
ArrayBag<T> ArrayBag<T>::bagDifference(const ArrayBag<T>& a_bag) const
{
	ArrayBag<T> difference_bag;
	std::vector<T> a_bag_vector = a_bag.toVector();//a vector that has the same contents as items_ in a_arrayBag
	for(int i = 0; i < a_bag.getCurrentSize(); i++)
	{	
		if(!contains(a_bag_vector[i]))
			difference_bag.add(a_bag_vector[i]); //add elements that are not int items_ to difference_bag
	}
	for(int i = 0; i < item_count_; i++) 
	{	
		if(!a_bag.contains(items_[i]))
			difference_bag.add(items_[i]); //add elements that are not int a_bag to difference_bag
	}

	//remove duplicates
	std::vector<T> difference_vector = difference_bag.toVector();
	for(int i = 0; i < difference_bag.getCurrentSize(); i++)
	{
	//if elements in items of difference_bag has a frequency > 1, then remove it
		if (difference_bag.getFrequencyOf( difference_vector[i]) > 1)
			difference_bag.remove(difference_vector[i]);
	}	
	
	return difference_bag;	
}


/**
	@return a new ArrayBag that contains the intersection of the contents
	of this bag and those of the argument a_bag. This intersection
	may contain duplicate items (e.g. if object x occurs 5 times in
	one bag and 3 times in the other, the intersection contains 3
	occurrences of that item)
	*/
template <class T>
ArrayBag<T> ArrayBag<T>::bagIntersection(const ArrayBag<T>& a_bag) const
{
	ArrayBag<T> bagIntersection;
	int a_bag_frequency; //frequency of an entry in a_bag
	int frequency; //frequency of an entry in items_
	int times; //shared occurrence of an entry in both objects
	for(int i = 0; i < item_count_; i++)
	{
		if(a_bag.contains(items_[i]) && !bagIntersection.contains(items_[i]))
		{
			frequency = getFrequencyOf(items_[i]);
			a_bag_frequency = a_bag.getFrequencyOf(items_[i]);
			if(a_bag_frequency < frequency)
				times = a_bag_frequency;
			else 
				times = frequency;
			for(int j = 0; j < times; j++) 
			{
				bagIntersection.add(items_[i]);
			}
		}
	}
	
	return bagIntersection;
		
}

/**friend function*//*
template <class T>
void remove(ArrayBag<T> &object, std::string last)
{
	for(int i = 0; i < object.item_count_; i++)
	{
		if(object.items_[i] == last)
			object.remove(object.items_[i]);
	}
	
}
*/

// PRIVATE

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not contain the target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;
   
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      } 
      else
      {
         search_index++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
