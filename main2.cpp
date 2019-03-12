#include"ArrayBag.hpp"
#include<iostream>
using namespace std;
int main()
{
	ArrayBag<int> items;
	items.add(1);
	items.add(2);
	items.add(3);
	items.add(4);
	items.add(4);
	items.add(5);
	items.add(2);
	items.add(2);
	items.add(2);
	items.add(4);
	//const int items[10] = {1, 2, 3, 4, 4, 5, 2, 2, 2, 4};
	//const int abag[5] = {0, 2, 2, 4, 5};
	ArrayBag<int> a_bag;
	a_bag.add(0);
	a_bag.add(2);
a_bag.add(2);
a_bag.add(4);
a_bag.add(5);
	//items.bagUnion(a_bag);
	
cout<< "<123445222402245>"<<endl;
ArrayBag<int> union_result = items.bagUnion(a_bag);
vector<int> result_vector = union_result.toVector();
for(int i = 0; i < union_result.getCurrentSize(); i++)
{	
	cout<<result_vector[i]<<endl;
}



cout<< "<245>"<<endl;
ArrayBag<int> inter_result = items.bagIntersectionNoDuplicates(a_bag);
vector<int> inter_vector = inter_result.toVector();
for(int i = 0; i < inter_result.getCurrentSize(); i++)
{	
	cout<<inter_vector[i]<<endl;
}

a_bag.add(0);
/*
cout<< "<1, 2, 3, 4, 4, 5, 2, 2, 2, 4>"<<endl;
vector<int> items_vector = items.toVector();
for(int i = 0; i < items.getCurrentSize(); i++)
{	
	cout<<items_vector[i]<<"\n";
}
cout<<endl;

cout<<"<02245>"<<endl;
vector<int> a_bag_vector = a_bag.toVector();
for(int i = 0; i < a_bag.getCurrentSize(); i++)
{	
	cout<<a_bag_vector[i]<<" ";
}
cout<<endl;
*/
cout<< "<013>"<<endl;

ArrayBag<int> diff_result = items.bagDifference(a_bag);
vector<int> diff_vector = diff_result.toVector();
for(int i = 0; i < diff_result.getCurrentSize(); i++)
{	
	cout<<diff_vector[i]<<endl;
}

/*
cout<< "<1, 2, 3, 4, 4, 5, 2, 2, 2, 4>"<<endl;
vector<int> items_vector = items.toVector();
for(int i = 0; i < items.getCurrentSize(); i++)
{	
	cout<<items_vector[i]<<"\n";
}
cout<<endl;

cout<<"<02245>"<<endl;
vector<int> a_bag_vector = a_bag.toVector();
for(int i = 0; i < a_bag.getCurrentSize(); i++)
{	
	cout<<a_bag_vector[i]<<" ";
}
cout<<endl;

cout<< "<2245>"<<endl;
ArrayBag<int> bagI_result = items.bagIntersection(a_bag);
vector<int> bagI_vector = bagI_result.toVector();
for(int i = 0; i < bagI_result.getCurrentSize(); i++)
{	
	cout<<bagI_vector[i]<<endl;
}
	*/
}
