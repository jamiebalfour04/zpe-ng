
class YASSByteCodes : public ZPETokeniser {
  //A C++ version of the YASS byte-code list

  private :

  regex variable_name;
  regex general_name;

  public :

  YASSByteCodes(){
    variable_name = regex("\\$(_?[A-z][A-z0-9_]*)");
    general_name = regex("(_?[A-z][A-z0-9_]*)");
  }

  short int StringToByteCode(string w){
    if(regex_match(w, variable_name)){
      return VAR;
    }
    if(regex_match(w, general_name)){
      return NAME;
    }
    if(w.compare("=") == 0){
      return EQUAL;
    }
    if(w.compare("if") == 0){
      return IF;
    }
    if(w.compare("(") == 0){
      return LBRA;
    }
    if(w.compare(")") == 0){
      return RBRA;
    }
    if(w.compare("end") == 0){
      return END;
    }

    return EXECUTION_FAILED;
  }

  string SymbolToString(short int symb){
    return "Hello";
  }

  /*vector<string> SpecialWords(){
    return {"S"};
  }*/

  static const short int EXECUTION_FAILED = -2;
  static const short int RESERVED = -1;

  static const short int PRIVATE = 0;
  static const short int PUBLIC = 1;
  static const short int FRIENDLY = 2;

  static const short int NAME = 3;
  static const short int VAR = 4;
  static const short int INT = 5;
  static const short int DOUBLE = 6;
  static const short int BOOLEAN = 7;
  static const short int STRING = 8;
  static const short int CHAR = 9;
  static const short int DATE = 10;
  static const short int IMAGE = 11;
  static const short int OBJECT = 12;
  static const short int LIST = 13;
  static const short int ASSOCIATION = 14;
  static const short int FUNCTION = 15;

  static const short int ASSIGN = 16;
  static const short int END = 17;
  static const short int LBRA = 18;
  static const short int RBRA = 19;
  static const short int COMMA = 20;


  static const short int IF = 21;
	static const short int ELSE = 22;
	static const short int ELSEIF = 23;
	static const short int WHEN = 24;
	static const short int IS = 25;

  static const short int EQUAL = 30;



};
