
class YASSPrintFunction : public ZPECoreFunction{
  public:
    ZPEValue* Execute(string w){
      stdOut(w);

      return NULL;
    }
};
