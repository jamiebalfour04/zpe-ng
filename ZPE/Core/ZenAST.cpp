class ZenAST{

  private :

  int type;
  string id;
  ZPEValue* value;

  public :

  ZenAST* left;
  ZenAST* middle;
  ZenAST* right;



  void setValue(ZPEValue* v){
    value = v;
  }

  void setID(string v){
    id = v;
  }

  void setType(int t){
    type = t;
  }

  ZPEValue* getValue(){
    return value;
  }

  string getID(){
    return id;
  }

  int getType(){
    return type;
  }

  void out(){
    stdOut("id : " + this->getID());
    stdOut(Concatenate((string)"type : ", this->getType()));

    if(this->right != NULL){
      this->right->out();
    }
  }



};
