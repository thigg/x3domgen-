/*
 * Arrow.hpp
 * Class which represents an Arrow
 *  Created on: Nov 17, 2014
 *      Author: thilo@ati.ttu.ee
 */

#ifndef EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_ARROW_HPP_
#define EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_ARROW_HPP_

#include <iostream>
#include "../../x3dom_generator/x3_dom_types/Cube.hpp"
#include "../../x3dom_generator/x3_dom_types/x3Object.hpp"

class Arrow: public x3Object {
public:
	Cube* from,* to;

	Arrow(Cube *f, Cube* t);
	std::ostream & visit(std::ostream & out);
	std::string getId();
};


#endif /* EE_TTU_ATI_X3DOM_BACKEND_X3_DOM_TYPES_ARROW_HPP_ */
