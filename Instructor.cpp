/**
// @file Instructor.cpp
// Instructor class implementation
// Project1B
//
// Created by Liu Lan Zheng on 2/8/19
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#include "Instructor.hpp"
Instructor::Instructor(int id, std::string first, std::string last):
	CourseMember(id, first, last){}

std:: string Instructor:: getOffice() const
{
	return office_;
}

std:: string Instructor:: getContact() const
{
	return contact_;
}

void Instructor::setOffice(const std::string office)
{
	office_=office;
}

void Instructor::setContact(const std::string contact)
{
	contact_ = contact;
}