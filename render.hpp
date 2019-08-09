/*
    Render helpings functions

__________                   .___            
\______   \ ____   ____    __| _/___________ 
 |       _// __ \ /    \  / __ |/ __ \_  __ \
 |    |   \  ___/|   |  \/ /_/ \  ___/|  | \/
 |____|_  /\___  >___|  /\____ |\___  >__|   
        \/     \/     \/      \/    \/       

*/

#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#define RENDER_JSON_VERSION_MAJOR 0
#define RENDER_JSON_VERSION_MINOR 0
#define RENDER_JSON_VERSION_PATCH 1

#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <string>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

namespace render
{
    /* namespace variables */
    json j_configuration, *p_j_configuration;

    struct R_locations  /* structure for table of locations record row */
    {
        std::uint64_t l_id;       /* first column - ID - primary key */
        std::string l_name;       /* unique name for location identification */
        std::string l_description; /* need to comment it ? :) */
        bool l_active;       /* is location used in project ? */
    };

    struct R_sensors    /* structure for sensor informations */
    {
        std::uint64_t s_id;
        std::string s_name;
        std::uint64_t l_id; /* value corresponds with location value in table locations */
        std::string s_type;     /* type info for sensor */
        std::string s_unit;     /* units for sensor values */
        bool s_active;
    };

    struct R_values     /* values from sensors */
    {
        std::uint64_t v_id;
        std::uint64_t s_id;     /* corresponds with s_id from table sensors */
        double v_double;
        std::string v_string;
        std::int64_t v_int;
    };

    struct MQTT_uri     /* uri for representation of mqtt struct. Like: value:://[root]/sensors/temperature/s1/s1_val */
    {
    };

    /* namespace functions */
	json ParseJsonConfig(string filename)   /* Parse configuration from json config file */
	{
    	string line;
	    ifstream cfile(filename);
	    stringstream buffer;
	    if(cfile.is_open()) {
    	    buffer << cfile.rdbuf();
	    }
    	json j_complete = json::parse(buffer.str());
	    return j_complete;
	};

	const std::string dtime()       /* returns string with actual time in readable format */
	{
		std::time_t now = time(0);
		struct tm tstruct;
		char buff[80];
		tstruct = *localtime(&now);
		strftime(buff, sizeof(buff), "%d-%m-%Y %X", &tstruct);
		return buff;
	};

	void info(const std::string msg)    /* print information on stdout */
	{
    	std::cout << std::endl << dtime() << " * [Info] * " << msg << " ...";
	};

	void chyba(const std::string msg)   /* print error on stderr */
	{
    	std::cerr << std::endl << dtime() << " * [Error] * " << msg << " !!!";
	};

    void dump_json(const json djson)    /* json dumping functioning */
    {
        std::cout << std::endl << std::setw(4) << djson << "\n\n";
    };

/* end of render's lib */
};
#endif
