/**
// @file  CourseMember.hpp
//  Project1A
//
//  Created by Tiziana Ligorio on 1/14/19.
//  Modified by Liu Lan Zheng on 2/22/19
//  Copyright © 2019 Liu Lan Zheng. All rights reserved.
*/

#ifndef CourseMember_hpp
#define CourseMember_hpp

#include <string>

class CourseMember
{
public:
	/**	default constructor*/
	CourseMember();
	
    /** Parameterized constructor
     @param id the student's unique identifier
     @param first the student's first name
     @param last the student's last name
     */
    CourseMember(int id, std::string first, std::string last);
    
    
    //********** Accessor Methods ****************
    
    /** @return returns id_; */
    int getID() const;
    
    /** @return returns first_name_ */
    std::string getFirstName() const;
    
    /** @return returns last_name_ */
    std::string getLastName() const;
	
	/**friend function, overloading operator== */
	friend bool operator==(const CourseMember& a, const CourseMember& b);
    
private:
    int id_; /** the CourseMember's ID */
    std::string first_name_; /** the CourseMember's first name */
    std::string last_name_; /** the CourseMember's last name */
    
    
}; //end CourseMember

#endif /* CourseMember_hpp */
