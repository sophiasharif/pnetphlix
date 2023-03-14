#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "Movie.h"
#include "User.h"
#include "treemm.h"
#include <iostream>
#include <string>
using namespace std;

//////////////////////////i/////////////////////////////////////////////////////
//
// You are free to do whatever you want with this file, since you won't
// be turning it in.  Presumably, you will make changes to help you test
// your classes.  For example, you might try to implement only some User
// member functions to start out with, and so replace our main routine with
// one that simply creates a User and verifies that the member functions you
// implemented work correctly.
//
//////////////////////////i/////////////////////////////////////////////////////


  // If your program is having trouble finding these files. replace the
  // string literals with full path names to the files.  Also, for test
  // purposes, you may want to create some small, simple user and movie
  // data files to makde debuggiing easier, so you can replace the string
  // literals with the names of those smaller files.

const string USER_DATAFILE  = "/Users/sophiasharif/Desktop/projects/CS32/project-4/project-4/users.txt";
const string MOVIE_DATAFILE = "/Users/sophiasharif/Desktop/projects/CS32/project-4/project-4/movies.txt";

int main()
{
    /// TREE MULTIMAP TESTING
//    TreeMultimap<int, std::string> tmm;
//    tmm.insert(1, "one");
//    tmm.insert(2, "two");
//    tmm.insert(3, "three");
//    auto it1 = tmm.find(1);
//    assert(it1.get_value() == "one");
//    auto it2 = tmm.find(2);
//    assert(it2.get_value() == "two");
//    auto it3 = tmm.find(3);
//    assert(it3.get_value() == "three");
//
//    TreeMultimap<int, std::string> tmm2;
//    tmm2.insert(1, "one");
//    tmm2.insert(2, "two");
//    tmm2.insert(1, "uno");
//    tmm2.insert(2, "dos");
//
//    auto it = tmm2.find(1);
//    assert(it.get_value() == "one");
//    it.advance();
//    assert(it.get_value() == "uno");
//    it.advance();
//    assert(!it.is_valid());
//    it = tmm2.find(2);
//    assert(it.get_value() == "two");
//    it.advance();
//    assert(it.get_value() == "dos");
//    it.advance();
//    assert(!it.is_valid());
//
//    cout << "all test cases passed! " << endl;
    
    /// USER DATABASE TESTING
//	UserDatabase udb;
//	if (!udb.load(USER_DATAFILE))  // In skeleton, load always return false
//	{
//		cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
//		return 1;
//	}
//    User* u = udb.get_user_from_email("DevNguy@gmail.com");
//    if (!u)
//        cout << "user does not exist !!" << endl;
//    else
//        u->dump();
//	for (;;)
//	{
//		cout << "Enter user email address (or quit): ";
//		string email;
//		getline(cin, email);
//		if (email == "quit")
//			return 0;
//		User* u = udb.get_user_from_email(email);
//		if (u == nullptr)
//			cout << "No user in the database has that email address." << endl;
//		else
//			cout << "Found " << u->get_full_name() << endl;
//	}
    
    MovieDatabase mdb;
    if (!mdb.load(MOVIE_DATAFILE)) 
    {
        cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
        return 1;
    }
    
    cout << "BOOM: " << endl;
    vector<Movie*> v = mdb.get_movies_with_actor("Benedict Cumberbatch");
    for (auto m : v)
        m->dump();
    

    
//    User* u = udb.get_user_from_email("DevNguy@gmail.com");
//    if (!u)
//        cout << "user does not exist !!" << endl;
//    else
//        u->dump();
    
}
