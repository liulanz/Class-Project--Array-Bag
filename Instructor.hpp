/**
// @file Instructor.hpp
//  Project1B
//
//  Created by Liu Lan Zheng on 2/8/19.
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#ifndef Instructor_hpp
#define Instructor_hpp
#include "CourseMember.hpp"

#include <string>

class Instructor: public CourseMember
{
public: 
	/**parameterized constructor
	@param id the instructor's id
	@param first the instructor's first name
	@param last the instructor's last name*/
	Instructor(int id, std::string first, std::string last);

//****************accessor methods*************
	/**@return returns office_;*/
	std::string getOffice() const;
	
	/**@return returns contact_;*/
	std::string getContact() const;
	
//******************mutator methods****************
	/**
	@param office the instructor's office
		set office_ be office*/
	void setOffice(const std::string office);
	
	/**
	@param contact the instructor's contact
		set contact_ be contact*/
	void setContact(const std::string contact);
	
private:
	std::string office_;
	std::string contact_;
};







#endif /*Instructor_hpp*/