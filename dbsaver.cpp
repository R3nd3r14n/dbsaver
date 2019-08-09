/* temp main */
#include "render.hpp"

using namespace std;
using namespace render;

int main(int argc, char **argv)
{
    info("Program starts");
    
    info("Reading configuration and setting things up");
    json j_config = ParseJsonConfig("./.dbsaver.conf.json");

    info("Dumping configuration");
    dump_json(j_config);

    info("Program ending");
}

