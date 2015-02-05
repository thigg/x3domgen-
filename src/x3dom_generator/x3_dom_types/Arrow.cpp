/*
 * Arrow.cpp
 * Implementation of Arrow.hpp
 *  Created on: Nov 17, 2014
 *      Author: thilo@ati.ttu.ee
 */

#include "../../x3dom_generator/x3_dom_types/Arrow.hpp"

#include <sstream>
#include "../../x3dom_generator/x3_dom_types/Cube.hpp"

std::string Arrow::getId() {
	std::stringstream s;
	s << "A" << id;
	return s.str();
}

Arrow::Arrow(Cube* f, Cube* t) :
		x3Object(), from(f), to(t) {
}

std::ostream& Arrow::visit(std::ostream & out) {
#define EAST 	(from->x < to->x)
#define WEST 	(from->x > to->x)
#define NORTH 	(from->y < to->y)
#define SOUTH 	(from->y > to->y)
#define UP 		(from->z < to->z)
#define DOWN 	(from->z > to->z)
	std::string translation = "";
	std::stringstream ss;
	//if the arrow is going in this direction, we have to calculate the position relative to
	//the head of the arrow
	ss << (EAST ? 1.68 :		//east
			WEST ? -1.68 :		//west
			NORTH ? -2 :		//north
			SOUTH ? 2 : 0) + (from->x * 2);		//south
	ss << " ";
	ss << (EAST ? 2 :		//east
			WEST ? -2 :		//west
			NORTH ? 1.68 :		//north
			SOUTH ? -1.68 : 0) + (from->y * 2);		//south
	ss << " ";
	ss << (UP ? 1.68 :
	DOWN ? -1.68 : 0) + (from->z * 2);
	translation = ss.str();

	std::string rotation = "";
	//rotation scheme:
	//the first 3 numbers are bools for the axes and the 3rd number indicates how many rad
	//around this axes

	if (EAST)
		rotation = "";
	else if (WEST)
		rotation = "0 0 1 -3.1415";
	else if (NORTH)
		rotation = "0 0 1 1.55";
	else if (SOUTH)
		rotation = "0 0 1 -1.55";
	else if (UP)
		rotation = "0 1 0 1.55";
	else if (DOWN)
		rotation = "0 1 0 -1.55";
	else
		rotation = "NONE";

	out << "<transform translation='" << translation << "' rotation='"
			<< rotation << "'>\n";

	out << " <transform text='" << text
			<< "' onmouseover=\"showText(this);$('material." << getId()
			<< "').attr('diffuseColor', '1 0.25 0.25');\" onmouseout=\"emptyText();$('material."
			<< getId()
			//set attributees back to default
			<< "').each(function(index){$(this).attr('diffuseColor', $(this).attr('default_color'))});\">\n"
					"			<transform rotation=\"0 0 1 -1.6\" translation=\"-0.25,-0.125,-0.125\">\n"
					"  				 <transform  translation=\'1.68 0 0\' scale=\'1.5 1 1\' > \n"
					"				   <shape>\n"
					"					<appearance> \n"
					"						 <material default_color=\'" << default_color
			<< "\' diffuseColor=\'" << default_color

			//arrow head
			<< "\'></material> \n"
					"					   </appearance> \n"
					"					   <cone bottomRadius=\"0.125\" height=\"0.125\"></cone>\n"
					"				   </shape>\n"
					"				   <transform translation=\'0,-0.5,0\'>\n"
					"					   <shape>\n"
					"							<appearance> \n"
					"						 <material default_color=\'" << default_color
			//arrow tail
			<< "\' diffuseColor=\'" << default_color << "\'></material> \n"
					"						   </appearance> \n"
					"						   <box size=\'0.0625,0.875,0.0625\'></cone>\n"
					"					   </shape>\n"
					"					 </transform>\n"
					"				 </transform>\n"
					"			 </transform>\n"
					"	   </transform></transform>\n";
	return out;
}
