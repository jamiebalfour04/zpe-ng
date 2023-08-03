/*
  This is an interpreted code function. This function only runs when
  called in code.
*/

class ZPEFunction{
  map<string, shared_ptr<ZPEValue*> > varlist;

  void Run(){

  }

  //A variable assignment node.
  void VariableAssignment(ZenAST* current){
    StoreVariable(current->getID(), current->getValue());
  }

  void StoreVariable(string name, ZPEValue* value){
    stdOut(name);
    shared_ptr<ZPEValue> x(value);
    //shared_ptr pointer = make_shared<ZPEValue>(value);
    //varlist[name] = make_shared<ZPEValue>(value);
  }

  ZPEValue* GetVariable(string name){

    //return varlist.at(name);
    return NULL;
  }
};
