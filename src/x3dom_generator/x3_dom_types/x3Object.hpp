#pragma once
#ifndef _x3_x3_x3Object_HPP
#define _x3_x3_x3Object_HPP

/**
 * the super type for x3objects
 * has methods for code generation and relations to other objects
 * @author thilo@ati.ttu.ee
 */
#include <vector>
#include <string>
#include <ostream>

class x3Object {
public:

	/**
	 * the default color of the object
	 */
	std::string default_color;

	/**
	 * text information for this object
	 */
	std::string text;

	/**
	 * this is the list of the elements which are highlighting me when hovered
	 */
	std::vector<x3Object*> highlighted_from;

	/**
	 * the object counter, with this counter gets each obj a uniqe id
	 */
	static int counter;

	/**
	 * the uniqe id of the object
	 */
	int id;

	/**
	 * default constructor, handles the id
	 */
	x3Object();

	virtual ~x3Object();


	/**
	 * visits this object and prints the object translation to the stream
	 */
	virtual std::ostream& visit(std::ostream & out)=0;

	/**
	 * this string is used as class of the objects which are highlighted by this element
	 * the id should be uniqe
	 */
	virtual std::string getId()=0;


	/**
	 * creates the string of the onhover classes
	 * concats all ids of the objects in the highlighted_from vector
	 */
	virtual std::string getClassesString();

};

#endif
