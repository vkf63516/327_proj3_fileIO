/*
 * FileReader.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: Vishal Fenn
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const string &filename, string &contents) {
	fstream cont_file;
	cont_file.open(filename);
	if (!cont_file) {
		return (COULD_NOT_OPEN_FILE_TO_READ);
	}
	contents.clear();
	string lineFeed;
	while (cont_file.peek() != EOF) {
		getline(cont_file, lineFeed);
		size_t reveal = lineFeed.find('\n');
		if (reveal != string::npos) {
			lineFeed.erase(reveal, 1);
		}
		contents += lineFeed;
	}

	if (contents.empty()) {
		return (COULD_NOT_OPEN_FILE_TO_READ);
	}
	cont_file.close();
	return (SUCCESS);

}

int KP_FileIO::writeVectortoFile(const string filename,
        vector<string> &myEntryVector) {
	ofstream vect_file;
	vect_file.open(filename);
	if (!vect_file) {
		return (COULD_NOT_OPEN_FILE_TO_WRITE);
	}
	for (vector<string>::iterator itr = myEntryVector.begin();
	        itr != myEntryVector.end(); itr++) {
		vect_file << *itr << '\n';
	}
	vect_file.close();
	return (SUCCESS);
}

