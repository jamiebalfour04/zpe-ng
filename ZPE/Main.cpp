#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <regex>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

#include "HelperFunctions.cpp"

#include "Core/ZPEValue.cpp"
#include "Core/ZenAST.cpp"
#include "Core/ZPETokeniser.cpp"
#include "Core/ZPEParser.cpp"
#include "Core/ZPEFunction.cpp"
#include "Core/ZPECoreFunction.cpp"

#include "DataTypes/ZPEList.cpp"

#include "YASS/YASSByteCodes.cpp"
#include "YASS/YASSCompiler.cpp"
#include "YASS/YASSCoreFunctions.cpp"
#include "YASS/YASSInterpreter.cpp"


int argument_count;
char** argvector;


void Interpret(char file[]){

  ifstream myReadFile;
  string output = "";

  myReadFile.open(file);
  while (!myReadFile.eof()) {
    string t;
    getline(myReadFile,t);
    output += t;
  }

  myReadFile.close();
  YASSInterpreter i;
  stdOut(i.Interpret(output, true));

}

void GenerateTree(char file[]){

  ifstream myReadFile;
  string program = "";

  myReadFile.open(file);
  while (!myReadFile.eof()) {
    string t;
    getline(myReadFile,t);
    program += t;
  }

  myReadFile.close();

  YASSCompiler comp;

  ZenAST* app = comp.Compile(program, true);

  ZPEValue* value = app->getValue();

  if(value != NULL){
    stdOut(value->getValue());
  }

  app->out();

}

void RunMode(){

}

void InputMode(){
  string s;
  YASSInterpreter i;
  print("> ");
  while(getline(cin, s)) {
    if(s.compare("exit") == 0){
      stdOut("Exiting.");
      exit(0);
    }
    i.Interpret(s, true);
    print("> ");
  }
}

int ProcessZAC(char *zac){
  if(strcmp(zac, "-r") == 0){
    InputMode();
  }
  if(strcmp(zac, "-i") == 0){
    if(argument_count >= 3){
      Interpret(argvector[2]);
    } else{
      stdOut("You need to provide a file to interpret.");
      exit(1);
    }
  }
  if(strcmp(zac, "-t") == 0){
    stdOut("Tree mode.");
    if(argument_count >= 3){
      GenerateTree(argvector[2]);
    } else{
      stdOut("You need to provide a file to generate a fAST tree for.");
      exit(1);
    }
  }


  return 0;
}


string GetCurrentVersion(){
  return "2.0.0";
}

string GetCurrentVersionDate(){
  return "November 2017";
}


int main(int argc, char *argv[]) {

  stdOut("");
  stdOut("");
  stdOut("Zenith Parsing Engine (ZPE) " + GetCurrentVersion() + " (" + GetCurrentVersionDate() + ")");
  stdOut("ZPE Parser version " + ZPEParser::GetVersion() + " copyright (c) Jamie Balfour 2011 - 2017");
  stdOut("Uses portions of other libraries.");
  stdOut("Other contributions and information can be found at:");
  stdOut("https://www.jamiebalfour.com/projects/zpe/");
  stdOut("For a command list, insert the '-h commands' line.");
  stdOut("");
  stdOut("");

  ZPEValue* v = new ZPEValue();

  ZPEList* l = new ZPEList();

  argument_count = argc;
  argvector = argv;


  if(argument_count == 1){
    stdOut("You need to provide a ZAC as an argument.");
    stdOut("");
    return 1;
  }

  ProcessZAC(argv[1]);

  stdOut("");
  return 0;
}
