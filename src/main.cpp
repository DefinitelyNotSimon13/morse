#include <iostream>
#include <cstdlib>
#include <string>

#include <boost/log/trivial.hpp>
#include <boost/json.hpp>
#include <fstream>
#include <iostream>

#include "cat.hpp"

const std::string AUTHOR_FILE = "author.json";


namespace remove_me {
void print_author();
}


int main(int argc, char** argv) {
    pets::Cat grievous = pets::Cat("Grievous");

    std::cout << "Hello, there!" << std::endl;
    grievous.meow();

    BOOST_LOG_TRIVIAL(info) << "I was logged using Boost::log`s trivial logger!";

    remove_me::print_author();

    return EXIT_SUCCESS;
}

void remove_me::print_author() {
    std::ifstream ifs(AUTHOR_FILE);
    if(!ifs) {
        BOOST_LOG_TRIVIAL(error) << "Failed to open " << AUTHOR_FILE << "\n";
        return;
    }

    boost::system::error_code ec;
    boost::json::value jv = boost::json::parse(ifs, ec);
    if(ec) {
        BOOST_LOG_TRIVIAL(error) << "Parse error: " << ec.message() << "\n";
        return;
    }
    BOOST_LOG_TRIVIAL(info) << "Successfully parsed " << AUTHOR_FILE << "\n";

    // also note that Boost::json has no "pretty" output
    // functionality - so just printing the AUTHOR_FILE would look nicer
    std::cout << boost::json::serialize(jv) << "\n";
}
