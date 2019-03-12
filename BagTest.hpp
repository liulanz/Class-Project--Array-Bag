//  Created by Liu Lan Zheng
//  Copyright (c) 2019 Liu Lan Zheng. All rights reserved

/** 
 @file BagTest.hpp 

 Project 1c
	The purpose of this class is to instantiate an
	ArrayBag that contains CourseMembers. It will read an input file, create
	CourseMember objects and add them to the bag. It will also ask the user for a last
	name and will remove the first occurrence of CourseMember with that last name that
	it finds in the bag. */

#ifndef BAG_TEST
#define BAG_TEST
#include<iostream>
#include<string>
#include"ArrayBag.hpp"
#include"CourseMember.hpp"


class BagTest
{
public:
	/**
	@pre the input file is in csv format as follows:
	“id,first_name,last_name,title\n”
	@post this function asks the user for an input file name.
	It extracts the information necessary to create a CourseMember object
	from each line in the input file, and it adds the corresponding
	CourseMember object to bag_.
	@return returns the populated bag_
	**/
	ArrayBag<CourseMember> testCourseMemberBag();
	
	
	/**
	@post asks the user for a last name and removes ONE CourseMember
	with that last name if it finds one
	@return returns the bag_ after removal if any
	**/
	ArrayBag<CourseMember> removeCourseMemberFromBag();
	
	/**
	@param member to be removed from bag_
	@post removes one occurrence of member if found in bag_
	@return returns the bag_ after removal if any
	**/
	ArrayBag<CourseMember> removeCourseMemberFromBag(const CourseMember& member); 
	
	
	/**
	@post prints to the standard output all CourseMember
	objects found in bag_, one per line if the format:
	id first_name last_name
	**/
	void displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag); 
 
	
private: 
	ArrayBag<CourseMember> bag_; 
	ArrayBag<CourseMember> createBagFromInput(std::string input_file); 
};
#endif 