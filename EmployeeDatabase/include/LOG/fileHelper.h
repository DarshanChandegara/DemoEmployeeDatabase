#ifndef _FILE_HELPER_
#define _FILE_HELPER_

#include<fstream>
#include<string>

//using utility::String;

namespace logging {

	class FileHelper {
		
	public:
		FileHelper(std::string name) : fName{name} , out{name , std::ios::app} {
			//std::cout << "4 ";
		}

		void writeLine(const std::string& log) {
			//std::cout << "5 ";
			out << log;
		}

	private :
		std::string fName{ "" };
		std::ofstream out{};
	}; 
}

#endif