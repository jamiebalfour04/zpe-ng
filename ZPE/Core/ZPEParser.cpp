class ZPEParser{

    private :

    string code;
    int current_symbol;
    int previous_symbol;
    string current_word;
    string previous_word;
    int program_counter;
    bool case_insensitive;
    ZPETokeniser* tokeniser;

    string FindWord(){
      string word = "";
      int len = code.length();

      //Eat any spaces
      while(program_counter < len && (code[program_counter] == ' ' || code[program_counter] == '\n')){
        program_counter++;
      }

      while(program_counter < len){
        char t = code[program_counter];
        program_counter++;
        if(t == ' '){
          return word;
        } else{
          word += t;
        }
      }

      return word;
    }

    public :

    ZPEParser(string p, ZPETokeniser* t){
        code = p;
        tokeniser = t;
    }

    ZPEParser(string p, ZPETokeniser* t, bool ignore_case){
      code = p;
      tokeniser = t;
      case_insensitive = ignore_case;
    }

    void ResetProgramCounter(){
      program_counter = 0;
    }

    bool HasNext(){
      int len = code.length();
      return program_counter < len;
    }

    string GetNext(){
      current_word = FindWord();
      return current_word;
    }

    int GetCurrentSymbol(){
      //Basic match.
      if(case_insensitive){
        return tokeniser->StringToByteCode(strtolow(current_word));
      } else{
        return tokeniser->StringToByteCode(current_word);
      }

    }

    string GetCurrentWord(){
      return current_word;
    }

    static string GetVersion(){
      return "2.0.1";
    }

};
