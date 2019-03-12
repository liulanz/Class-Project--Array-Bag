
#include"CourseMember.hpp"
#include"BagTest.hpp"
#include<iostream>
using namespace std;
int main()
{
	BagTest a;
	ArrayBag<CourseMember> b = a.testCourseMemberBag();
	a.displayCourseMemberBag(b);
	
	ArrayBag<CourseMember> c = a.removeCourseMemberFromBag();
	a.displayCourseMemberBag(c);
		
		
}