/*A shitty variable container*/
class ZPEValue{


  private :

  int type;

  //Storage of the values
  int int_value;
  string string_value;
  char* char_value;
  void* void_value;

  public :

  int getType(){
    return type;
  }

  void setValue(int v){
    int_value = v;
    type = 1;
  }

  void setValue(string v){
    string_value = v;
    type = 2;
  }

  //E.g. list
  void setValue(void* v){
    void_value = v;
    type = 3;
  }

  int getValue(){
    return int_value;
  }

  

};
