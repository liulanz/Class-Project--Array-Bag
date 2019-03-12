/**
// @file BagTest.cpp
// BagTest class implementation
// Project1C
//
// Created by Liu Lan Zheng on 2/17/2019
*/
#include"BagTest.hpp"
//#include"CourseMember.hpp"
#include<string>
#include<cstring>
#include<fstream>

using namespace std;
/**
	@post this function asks the user for an input file name.
	It extracts the information necessary to create a CourseMember object
	from each line in the input file, and it adds the corresponding
	CourseMember object to bag_.
	@return returns the populated bag_
	**/
ArrayBag<CourseMember> BagTest::testCourseMemberBag()
{	
	ArrayBag<CourseMember> populated_bag;
	string file_name;
	cout <<"Enter a csv input file name.. "<<endl;
	cin >> file_name;
	populated_bag = createBagFromInput(file_name);
	return populated_bag;
	
}

/**
	@post prints to the standard output all CourseMember
	objects found in bag_, one per line if the format:
	id first_name last_name
	**/
void BagTest::displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag)
{
	vector<CourseMember> bag_vector = a_bag.toVector(); //bag_vector has same contents as items_ in a_bag
	cout << "ID\t" << "First Name\t\t" << "Last Name" << endl;
	cout << endl;
	for(int i =0 ; i < a_bag.getCurrentSize(); i++)
	{
		cout << bag_vector[i].getID() << "\t" << bag_vector[i].getFirstName() << "\t\t\t"
		<< bag_vector[i].getLastName() << endl;
	}
}

/**
	@param member to be removed from bag_
	@post removes one occurrence of member if found in bag_
	@return returns the bag_ after removal if any
	**/
ArrayBag<CourseMember> BagTest::removeCourseMemberFromBag(const CourseMember& member)
{

	ArrayBag<CourseMember> remove_bag = testCourseMemberBag();
	vector<CourseMember> remove_vector = remove_bag.toVector();
	for(int i = 0; i < remove_bag.getCurrentSize(); i++)
	{
		if(remove_vector[i] == member)
		{
			remove_bag.remove(remove_vector[i]);
			return remove_bag;
		}
	}
	return remove_bag;
}

/**
	@post asks the user for a last name and removes ONE CourseMember
	with that last name if it finds one
	@return returns the bag_ after removal if any
	**/
ArrayBag<CourseMember> BagTest::removeCourseMemberFromBag()
{
	string remove_last;
	cout << "Enter a last name to be removed..";
	cin >> remove_last;
	vector<CourseMember> bag_vector = bag_.toVector();
	for(int i = 0; i < bag_.getCurrentSize(); i++)
	{
		if(bag_vector[i].getLastName() == remove_last)
		{
			bag_.remove(bag_vector[i]);
			return bag_;
		}
	}
	return bag_;
}

//private:
/** @return returns a new ArrayBag after reading a csv file*/
ArrayBag<CourseMember> BagTest::createBagFromInput(std::string input_file)
{
	ifstream file(input_file);
	string first, last, title, str_id;
	int id;
	if(file.fail()) //if file doesn't open, print error message
	{
		cout << "error" << endl;
		exit(0);
	}
	while(!file.eof())//while it's not the end of file
	{
		getline(file, str_id, ',');
		getline(file, first, ',');
		getline(file, last, ',');
		getline(file, title);
		id = atoi(str_id.c_str());//change str_id from string to int (id)
		CourseMember person(id, first, last); 
		bag_.add(person); //add person to the bag
	}
	file.close(); 
	
	return bag_;
}






	
