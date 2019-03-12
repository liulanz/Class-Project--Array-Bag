/**
// @file  Student.hpp
//  Project1B
//
//  Created by Liu Lan Zheng on 2/8/19.
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#ifndef Student_hpp
#define Student_hpp
#include "CourseMember.hpp"

#include <string>

class Student: public CourseMember //	Student is a derived class of CourseMember
{
public:
	/**parameterized constructor
     @param id the student's unique identifier
     @param first the student's first name
     @param last the student's last name
     */
	Student(int id, std::string first, std::string last);
	
	 
    //********** Accessor Methods ****************
	
	/** @return returns major_;*/
	std::string getMajor() const;
	
	/** @return returns gpa_;*/
	double getGpa() const;
	
	//********** Mutator Methods ****************
	
	/** initialize student's major to major_
	 @param major the student's major*/
	void setMajor(const std::string major);
	 
	 /** initialize studen's gpa to gpa_;
	  @param gpa the student's gpa*/
	 void setGpa(const double gpa);

protected:
	std::string major_; /**student's major*/
	double gpa_; /**student's gpa*/
};
#endif /* Student_hpp */