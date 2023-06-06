#include<iostream>
#include<conio.h>
#include<string.h>
class string
{
    private:
              char *str;
    public:
             string(char *s)
             {
                   int len;
                   len =strlen(s);
                   str=new char(len+1);
                   strcpy(str,s);
             }
                
             void write()
             { 
                  std::cout<<str<<"\n";    
             }
             
             ~string()
             {
                  delete str;

             }

};
int main()
{
      string s1("sai"),s2("sai c++ java python c langauge" );
      s1.write();
      s2.write();
      getch();

}