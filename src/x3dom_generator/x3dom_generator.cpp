/*
 * The Generator implementation
 *
 *  Created on: Nov 14, 2014
 *      Author: thilo@ati.ttu.ee
 */
#include "../x3dom_generator/x3dom_generator.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "../x3dom_generator/x3_dom_types/x3Object.hpp"

/**
 * prints the header of the html site
 * @param out the stream to write to
 * @param title title of the website
 * @param description description of this x3dom, placed in front of the canvas
 */
void x3DomGenerator::printHeader(std::ostream &out, std::string title,
		std::string description) {
	out << "<!DOCTYPE html> \n"
			"<html> \n"
			"   <head>\n"
			"    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"/> \n"
			"     <title>" << title
			<< "</title> \n"
					"     <script type=\'text/javascript\' src=\'http://www.x3dom.org/download/x3dom.js\'> </script> \n"
					"     <link rel=\'stylesheet\' type=\'text/css\' href=\'http://www.x3dom.org/download/x3dom.css\'></link> \n"
					"	 <script>\n"
					"		function showText(ele){\n"
					"    		$(\'#showSelectedPos\').html(ele.getAttribute(\"text\"));\n"
					"		}\n"
					"		function emptyText(){\n"
					"		$(\'#showSelectedPos\').html(\"none\");\n"
					"		}\n"
					"\n"
					"</script>\n"
					"  <style>\n"
					"        #x3_scene {\n"
					"            width: 100%;\n"
					"            height: 450px\n" //may find a better solution to fit the remaining screen
					"        }\n"
					"    </style>"
					"<script src=\"http://code.jquery.com/jquery-latest.js\"></script>\n"
					"   </head> \n"
					"   <body> \n" << description
			<< "<br/>Item info:<p id='showSelectedPos'></p>\n"
					"	 <x3d id='x3_scene'> \n"
					"	   <scene>\n";
}
/**
 * prints the bottom of the website
 */
void x3DomGenerator::printBottom(std::ostream &out) {
	out << "	   </scene> \n"
			"	</x3d> \n"
			"   </body> \n"
			"</html>";
}

/**
 * prints the objects
 */
void x3DomGenerator::printObjects(std::ostream & out) {

	for (auto o : objects) {
		o->visit(out);
	}

}

/**
 * generates to the given out stream
 */
void x3DomGenerator::generate(std::ostream & out) {
	printHeader(out, title, description);
	printObjects(out);
	printBottom(out);
}

/**
 * generates to the given file
 */
void x3DomGenerator::generate(std::string & filename) {
	std::ofstream stream;
	stream.open(filename.c_str());
	generate(stream);
	stream.close();
}
