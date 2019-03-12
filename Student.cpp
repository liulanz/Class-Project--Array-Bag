/**
// @file Student.cpp
// Student class implementation
// Project1B
//
// Created by Liu Lan Zheng on 2/8/19
//  Copyright © 2019 Liu Lan Zheng All rights reserved.
*/

#include "Student.hpp"
#include <iostream>
#include <string>

//parameteterized constructor
Student::Student(int id, std::string first, std::string last)
	:CourseMember(id, first, last){}

std::string Student:: getMajor() const
{
	return major_;
}

double Student::getGpa() const
{
	return gpa_;
}

void Student::setMajor(const std::string major)
{
	major_ = major;
}

void Student::setGpa(const double gpa)
{
	gpa_ = gpa;
}


