class YASSInterpreter{

  private :
    unordered_map<string, ZPECoreFunction*> built_in_functions;

  void SetupCore(){
    built_in_functions["print"] = new YASSPrintFunction();
  }

  ZPEValue* RunFunction(string name){
    ZPECoreFunction* z = built_in_functions[name];
    return z->Execute("Hello this is the " + name + " function.");
  }

  public :

  string Interpret(string program, bool case_insensitive){

    SetupCore();

    YASSCompiler comp;

    ZenAST* app = comp.Compile(program, case_insensitive);

    ZPEValue* value = app->getValue();

    if(value != NULL){
      stdOut(value->getValue());
    }

    TraverseAST(app);

    string output = "";

    return output;
  }

  /*
    Traverse from the root down
  */
  void TraverseAST(ZenAST* root){

    ZenAST* current = root->right;

    while(current != NULL){

      if(current->getType() == YASSByteCodes::ASSIGN){
        //VariableAssignment(current);
      }
      if(current->getType() == YASSByteCodes::NAME){
        RunFunction(current->getID());
      }

      current = current->right;
    }

  }
};
