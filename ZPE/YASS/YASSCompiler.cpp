class YASSCompiler{

  public :

  ZPEParser* zpe;


  ZenAST* Compile(string program, bool case_insensitive){
    //We create a pointer to the tokeniser and pass it to the parser.
    ZPETokeniser *tokeniser = new YASSByteCodes();

    zpe = new ZPEParser(program, tokeniser, case_insensitive);

    ZenAST* root = new ZenAST();
    root->setType(YASSByteCodes::RESERVED);

    ZenAST* _last = root;

    zpe->GetNext();
    while(zpe->HasNext()){
      string w = zpe->GetCurrentWord();

      int symb = zpe->GetCurrentSymbol();

      //Set the right of the node or FAST to be the output
      _last->right = ToNode(symb);
      //Our new current node becomes the output of the last assignment
      _last = _last->right;

      zpe->GetNext();
    }

    return root;
  }



  private :

  ZenAST* ToNode(int symb){

    switch(symb){
      case YASSByteCodes::VAR :
        return CompileVar();
      case YASSByteCodes::IF :
        return CompileIf();
      case YASSByteCodes::NAME :
        return CompileFunctionCall();

    }

    return new ZenAST();
  }

  ZenAST* CompileVar(){

    ZenAST* z = new ZenAST();

    z->setType(YASSByteCodes::VAR);

    //We need the variable name
    string w = zpe->GetCurrentWord();

    //Strip the $ at the start
    w = w.substr(1, w.length() - 1);
    z->setID(w);

    zpe->GetNext();

    //If symbol is an equals then this is assignment
    if(zpe->GetCurrentSymbol() != YASSByteCodes::EQUAL){
      CompileHalt("EQUAL");
    }

    z->setType(YASSByteCodes::ASSIGN);

    zpe->GetNext();
    //Create a new ZPEValue which contains the value
    ZPEValue* v = new ZPEValue();
    w = zpe->GetCurrentWord();
    v->setValue(w);

    z->setValue(v);

    return z;
  }

  ZenAST* CompileFunctionCall(){

    ZenAST* z = new ZenAST();

    z->setType(YASSByteCodes::NAME);

    string name = zpe->GetCurrentWord();

    zpe->GetNext();

    if(zpe->GetCurrentSymbol() != YASSByteCodes::LBRA){
      CompileHalt("LBRA");
    }

    zpe->GetNext();

    //Need to parse parameters here

    if(zpe->GetCurrentSymbol() != YASSByteCodes::RBRA){
      CompileHalt("RBRA");
    }

    z->setID(name);

    zpe->GetNext();

    return z;

  }

  ZenAST* CompileIf(){

    ZenAST* z = new ZenAST();

    z->setType(YASSByteCodes::IF);

    zpe->GetNext();

    if(zpe->GetCurrentSymbol() != YASSByteCodes::LBRA){
      CompileHalt("LBRA");
    }

    zpe->GetNext();

    //Need to parse all conditions here

    if(zpe->GetCurrentSymbol() != YASSByteCodes::RBRA){
      CompileHalt("RBRA");
    }

    if(zpe->GetCurrentSymbol() == YASSByteCodes::END){
      zpe->GetNext();
      if(zpe->GetCurrentSymbol() != YASSByteCodes::IF){
        CompileHalt("END IF");
      }
    }

    zpe->GetNext();

    return z;
  }
};
