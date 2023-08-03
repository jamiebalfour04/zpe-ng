/*
  A bunch of useful helper functions to assist with complex C things
*/

static string Concatenate(string str1, int int1){
  stringstream ss;
  ss << str1 << int1;

  return ss.str();
}

static string Concatenate(int int1, string str1){
  stringstream ss;
  ss << int1 << str1;

  return ss.str();
}

static string Concatenate(char *str1, int int1){
  stringstream ss;
  ss << int1 << str1;

  return ss.str();
}

static void stdOut(string s){
    cout << s << endl;
}

//An output for int
static void stdOut(int s){
    cout << s << endl;
}

//An output for double
static void stdOut(double s){
    cout << s << endl;
}

//An output for char
static void stdOut(char s){
    cout << s << endl;
}

static void print(string s){
  cout << s;
}

static void print(int s){
  cout << s;
}

static void print(double s){
  cout << s;
}

static void print(char s){
  cout << s;
}

static string strtolow(string s){
  for(unsigned int i = 0; i < s.length(); ++i) {
    s[i] = tolower(s[i]);
  }
  return s;
}

static void CompileHalt(string expected){
  stdOut("Compiler halt. Found an incorrect symbol when it expected " + expected + ". The compiler will shutdown.");
  exit(1);
}
