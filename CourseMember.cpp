/**
// @file CourseMember.cpp
// CourseMember class implementation
// Project1A
//
// Created by Liu Lan Zheng on 1/29/19
*/
#include "CourseMember.hpp"
#include <iostream>
#include <string>

//default constructor
CourseMember::CourseMember()
{
	id_ = 0;
	first_name_ = "";
	last_name_ = "";
}


//parameterized constructor
CourseMember::CourseMember(int id, std::string first, std::string last)
{
	id_ = id;
	first_name_ = first;
	last_name_ = last;
}

//friend function, overload operator==
bool operator==(const CourseMember& a, const CourseMember& b)
{
	return( (a.getFirstName() == b.getFirstName()) && (a.getLastName() == b.getLastName()) &&
			(a.getID() == b.getID()) );
}

//access functions

int CourseMember::getID() const
{
	return id_;
}

std::string CourseMember::getFirstName() const
{
	return first_name_;
}

std::string CourseMember::getLastName() const
{
	return last_name_;
}
