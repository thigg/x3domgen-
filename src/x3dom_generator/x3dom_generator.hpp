/**
 *
 * The Generator class.
 *
 * Usage:
 * - Set a title and a description of the website.
 * - You may set the default colors.
 * - Add your X3Dom-Objects to objects.
 * - Call generate
 *
 *  Created on: Nov 14, 2014
 *      Author: thilo@ati.ttu.ee
 */
#pragma once
#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <string>
#include <vector>
#include <ostream>

#include "../x3dom_generator/x3_dom_types/x3Object.hpp"

class x3DomGenerator {
public:
	/**
	 * title of the HTML Page
	 */
	std::string title;
	/**
	 * short description on top of the page
	 */
	std::string description;

	//default color
	std::string color_default;
	//color on hover
	std::string color_hover;
	//the objects, handled by this generator
	std::vector<x3Object*> objects;
public:

	x3DomGenerator() {

	}
	~x3DomGenerator() {
		for (auto o : objects)
			delete o;
	}

	/**
	 * generates to the given out stream
	 */
	void generate(std::ostream & out);

	/**
	 * generates to the given file
	 */
	void generate(std::string & filename);
private:
	void printObjects(std::ostream & out);
	void printHeader(std::ostream &out, std::string title,
			std::string description);
	void printBottom(std::ostream &out);
};

#endif /* INTERFACE_H_ */
