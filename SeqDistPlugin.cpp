#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "SeqDistPlugin.h"

void SeqDistPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void SeqDistPlugin::run() {}

void SeqDistPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "SeqDist";
myCommand += " ";
myCommand += "-in";
myCommand += " ";
myCommand += parameters["fastafile"];
myCommand += " ";
myCommand += "-rin";
myCommand += " ";
myCommand += parameters["lookupfile"];
myCommand += " > ";
myCommand += file;
 system(myCommand.c_str());
}

PluginProxy<SeqDistPlugin> SeqDistPluginProxy = PluginProxy<SeqDistPlugin>("SeqDist", PluginManager::getInstance());
