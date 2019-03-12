/**
// @file  TeachingAssistant.cpp
// TeachingAssistant class implementation
//  Project1B
//
//  Created by Liu Lan Zheng on 2/8/19.
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#include "TeachingAssistant.hpp"
#include <iostream>
TeachingAssistant:: TeachingAssistant(int id, std::string first, std::string last)
	:Student(id, first, last){}

int TeachingAssistant::getHours() const
{
	return hours_per_week_;
}

ta_role TeachingAssistant:: getRole() const
{
	return role_;
}

void TeachingAssistant:: setHours(const int hours)
{
	hours_per_week_= hours;
}

void TeachingAssistant:: setRole(const ta_role role)
{
	role_ = role;
}
