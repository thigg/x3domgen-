/*
 * Cube.hpp
 * Class represents a cube in the x3dom doc
 *  Created on: Nov 17, 2014
 *      Author: thilo@ati.ttu.ee
 */

#ifndef EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_CUBE_HPP_
#define EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_CUBE_HPP_

#include <ostream>
#include "../../x3dom_generator/x3_dom_types/x3Object.hpp"

class Cube: public x3Object {
public:
	int x, y, z;

	Cube(int x1, int y1, int z1);
	std::ostream& visit(std::ostream &);
	std::string getId();
};



#endif /* EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_CUBE_HPP_ */
