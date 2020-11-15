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

int KP_FileIO::getFileContents(const string &filename,
		string &contents){
	ifstream cont_file;
	cont_file.open(contents);
	if (!cont_file) {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	contents.clear();
	string lineFeed;
	while (cont_file.peek() != EOF) {
		getline(cont_file, lineFeed);
		size_t reveal = lineFeed.find('\n');
		if (reveal != -1) {
			lineFeed.erase(reveal, 1);
		}
		contents += lineFeed;
	}
	if (contents.empty()) {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	return SUCCESS;


}

int KP_FileIO::writeVectortoFile(const string filename,
		vector<string> &myEntryVector){
	ofstream vect_file;
	vect_file.open(filename.c_str());
	if (!vect_file) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	for (string entries : myEntryVector) {
		vect_file << entries << '\n';
	}
	vect_file.close();
	return SUCCESS;
}


