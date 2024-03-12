#include "environment.h"

Environment::Environment()
{

}

QString Environment::getBaseUrl()
{
    return "http://localhost:3000";
    //return "http://ipv4.fiddler:3000";
}
