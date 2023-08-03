class ZPETokeniser{
  public :
    ZPETokeniser(){}
    virtual short int StringToByteCode(string w){
      return 0;
    }
    virtual string SymbolToString(short int symb){
      return "";
    }
    //virtual std::vector ListOfSpecialCharacters();
};
