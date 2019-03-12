/**
// @file  TeachingAssistant.hpp
//  Project1B
//
//  Created by Liu Lan Zheng on 2/8/19.
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#ifndef TeachingAssistant_hpp
#define TeachingAssistant_hpp
#include "Student.hpp"
#include <string>

enum ta_role{LAB_ASSISTANT, LECTURE_ASSISTANT, BOTH};

class TeachingAssistant: public Student
{
public:
	/** parameterized constructor
	@param id the teaching assistant id
	@param first the teaching assistant's first name
	@param last the teaching assistant's second name*/
	TeachingAssistant(int id, std::string first, std::string last);
	
 //***********accessor methods**************	
 
	/**@return returns hours_per_week_;*/
	int getHours() const;
	
	/**@return returns role*/
	ta_role getRole() const;
	
 //***********mutator methods**************	
	/**
	@param hours the hours per week*/
	void setHours(const int hours);
	
	/**@param role the role of ta*/
	void setRole(const ta_role role); 
	
private:
	int hours_per_week_; //ta's working hour per week
	ta_role role_; //ta's role
	
};
#endif /*TeachingAssistant_hpp*/
