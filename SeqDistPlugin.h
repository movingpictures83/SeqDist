#ifndef SEQDISTPLUGIN_H
#define SEQDISTPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class SeqDistPlugin : public Plugin
{
public: 
 std::string toString() {return "SeqDist";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
