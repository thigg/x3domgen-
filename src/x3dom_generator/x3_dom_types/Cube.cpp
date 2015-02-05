/*
 * Cube.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: thilo@ati.ttu.ee
 */

#include "../../x3dom_generator/x3_dom_types/Cube.hpp"

#include <ostream>
#include <sstream>

std::string Cube::getId(){
	std::stringstream s;
	s << "C"<<id;
	return s.str();
}

Cube::Cube(int x1, int y1, int z1) :
			x3Object() {
		x = x1;
		y = y1;
		z = z1;
	}
std::ostream & Cube::visit(std::ostream & out){
	out << "<transform translation=\'" << (x * 2) << " " << (y * 2)
				<< " " << z * 2 << "\' id=\"" << getId() << "\"> \n"
						"		  <shape text=\"Cube(" << x << "," << y << "," << z
				<< ")\" onmouseover=\"showText(this);\" onmouseout=\"emptyText();\"> \n"
						"		     <appearance> \n"
						"			   <material class=\"" << getClassesString()
				<< "\" default_color=\'"<<default_color<<"\' diffuseColor=\'"<<default_color<<"\'></material> \n"
						"		     </appearance> \n"
						"		   <box size=\'0.5,0.5,0.5\'></box> \n"
						"		</shape> \n"
						"		</transform>\n";
	return out;
}
