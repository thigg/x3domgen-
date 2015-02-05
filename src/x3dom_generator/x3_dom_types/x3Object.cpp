/*
 * x3Object.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: thilo@ati.ttu.ee
 */
#include "../../x3dom_generator/x3_dom_types/x3Object.hpp"

#include <sstream>

int x3Object::counter = 0;

x3Object::x3Object() {
	counter++;
	id = counter;
	text="";
	default_color="0.5 0.5 0.5";
}


/**
 * generates the string of all the classes(x3dom objects) which may highlight this object
 *
 */
std::string x3Object::getClassesString(){
	std::stringstream s;
	for(unsigned int i = 0; i< highlighted_from.size(); i++){
		x3Object* obj = highlighted_from.at(i);
		s << obj->getId()<<" ";
	}

	return s.str();
}

x3Object::~x3Object(){

}

