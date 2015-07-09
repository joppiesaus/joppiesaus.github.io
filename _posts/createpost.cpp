/* jekyll post generator, another lazy programming project
made for joppiesaus.github.io blah blah

LICENSE:
You may now drive
*ahum*
I mean: do whatever you want with it. It's public domain.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>


using namespace std; // hurr durr bad practice blame blame blame but hey I don't have variables called localtime

int main(int charc, char** argv)
{
	string title, permalink;

	// Ask user
	cout << "Title of your post? ";
	getline(cin, title);
	cout << endl << "And the permalink(file name)? ";
	getline(cin, permalink);

	// Remove spaces
	replace(permalink.begin(), permalink.end(), ' ', '-');

	time_t theTime = time(nullptr);
	struct tm now;
	
	localtime_s(&now, &theTime);

	// Assigne the file name with the time
	string name =
		to_string(now.tm_year + 1900 /*years since 1900*/) +
		"-" +
		to_string(now.tm_mon + 1/*counted from 0*/) +
		"-" +
		to_string(now.tm_mday) +
		"-" +
		permalink +
		".md"
	;

	// Create file
	ofstream o(name);
	// Write layout & title
	o << "---\nlayout: post\ntitle: " << title << "\n---\n\n";
	o.close();

	return 0;
}