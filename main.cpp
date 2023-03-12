#include "UserDatabase.h"
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

const string USER_DATAFILE  = "users.txt";
const string MOVIE_DATAFILE = "movies.txt";

int main()
{
    TreeMultimap<string, int> tmm;
    if (!tmm.find("hey").is_valid()) {
        cout << "success1!" << endl;
    }
    tmm.insert("head", 4);
    if (!tmm.find("hey").is_valid()) {
        cout << "success2!" << endl;
    }
    TreeMultimap<string, int>::Iterator it = tmm.find("head");
    if (it.is_valid() && it.get_value() == 4) {
        cout << "successfully inserted new node!" << endl;
    }
    tmm.insert("head", 5);
    it = tmm.find("head");
    it.advance();
    if (it.is_valid() && it.get_value() == 5) {
        cout << "successfully appended value!" << endl;
    }
    tmm.insert("ee", 4);
    tmm.insert("d", 4);
    tmm.insert("ef", 4);
    

//    tmm.insert("head", 5);
//    tmm.insert("head", 6);
//    TreeMultimap<string, int>::Iterator it = tmm.find("head");
//    while (it.is_valid()) {
//        cout << it.get_value() << endl;
//        it.advance();
//    }
    
//	UserDatabase udb;
//	if (0&&!udb.load(USER_DATAFILE))  // In skeleton, load always return false
//	{
//		cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
//		return 1;
//	}
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
    
    // TO DO: test creating tree
}
