
%{
#include <ctype.h>    
#include<string.h>
 #include<iostream>
 #include<string>
#include <iomanip>
using namespace std;
#include "y.tab.h"


#define LIST     strcat(buf,yytext);

#define TYPEINT 1
#define TYPESTRING 2
#define TYPEREAL 3
#define TYPEBOOL 4
#define TYPEPROGRAM 5
#define TYPEPROCEDURE 6
#define TYPEARRAY 7
#define token(t) {LIST; }//cout<<"<" <<t <<">"<< "\n";
#define tokenReal(t,f) {LIST; cout<<fixed <<setprecision(6)<< "<"<<t <<" "<< f<<">\n";}
#define tokenInteger(t,i) {LIST;}
#define tokenString(t,s) {LIST; cout<< "<" <<t<<" "<<s <<">\n" ;;}

#define MAX_LINE_LENG 256

string temp = "";

int linenum = 1;
char buf[MAX_LINE_LENG]= {0};
string str ="";


char *strupr(char *str)
{
   char *ptr = str;

   while (*ptr != '\0') {
       if (islower(*ptr)) 
            *ptr = toupper(*ptr);
       ptr++;
   }

   return str;
}

%}
%x STRING
%x COMMENT


comma ","
colon ":"
period "\."
semicolon [;]
leftParenthese [(]
rightParenthese [)]
leftSquareBracket [\[]
rightSquareBracket \]
arithmetic "+"|"-"|"*"|"/"|"%"
remainder "%"
relational1 "<="|">="|"/="
relational2 ">"|"="|"<"

and [aA][nN][dD]
or [oO][rR]
not [nN][oO][tT]

assignment ":="


begin [bB][eE][gG][iI][nN]

boolean [bB][oO][oO][lL][eE][aA][nN]
break [bB][rR][eE][aA][kK]
character [cC][hH][aA][rR][aA][cC][tT][eE][rR]
case [cC][aA][sS][eE]
continue [cC][oO][nN][tT][iI][nN][uU][eE]
constant [cC][oO][nN][sS][tT][aA][nN][tT]
declare [dD][eE][cC][lL][aA][rR][eE]
do [dD][oO]
else [eE][lL][sS][eE]
end [eE][nN][dD]
exit [eE][xX][iI][tT]
float [fF][lL][oO][aA][tT]
false [fF][aA][lL][sS][eE]
for [fF][oO][rR]
if [iI][fF]
in [iI][nN]
integer [iI][nN][tT][eE][gG][eE][rR]
loop [lL][oO][oO][pP]
print [pP][rR][iI][nN][tT]
println [pP][rR][iI][nN][tT][lL][nN]
procedure [pP][rR][oO][cC][eE][dD][uU][rR][eE]
program [pP][rR][oO][gG][rR][aA][mM]
return [rR][eE][tT][uU][rR][nN]
string [sS][tT][rR][iI][nN][gG]
true [tT][rR][uU][eE]
then [tT][hH][eE][nN]
while [wW][hH][iI][lL][eE]
read [rR][eE][aA][dD]
real [rR][eE][aA][lL]

keyword {begin}|{boolean}|{break}|{character}|{case}|{continue}|{constant}|{declare}|{do}|{else}|{end}|{exit}|{float}|{for}|{if}|{in}|{integer}|{loop}|{print}|{println}|{procedure}|{program}|{return}|{string}|{then}|{while}

sign (+|-)?
digit [0-9]
letter [A-Za-z]
digits {digit}+

realConstant  {digits}"."{digits}([Ee][+-]{digits})?

integerConstants  {digit}+
booleanConstants {true}|{false}
 
stringConstant \"

singleLineComment --(.)*
multiLineComment \{
identifiers {letter}({letter}|{digit})*
%%


{and} {token(strupr(yytext)); return AND;}
{not} {token(strupr(yytext)); return NOT;}
{or} {token(strupr(yytext)); return OR;}
{realConstant} {  tokenReal("Real",(atof(yytext))); yylval.Token.realVal = atof(yytext); return REALCONSTANT;}
{comma} {token("\',\'"); return COMMA;}
{colon} {token("\':\'"); return COLON;}
{period}  {token("\'.\'"); return PERIOD;}
{semicolon} {token("\';\'"); return SEMICOLON;}
{read} {return READ;}
{arithmetic} {temp = *yytext; token("\'"+ temp+"\'"); return temp[0];}

[<][=] { token("\'<=\'"); return LESSEQUAL;}
[>][=] {token("\'>=\'"); return GREATEQUAL;}
[/][=] {token("\'/=\'"); return NOTEQUAL;}
{relational2} {temp = *yytext; token("\'"+ temp+"\'"); return temp[0];}
{assignment} {token("\':=\'"); return ASSIGNMENT;}
{booleanConstants} {tokenString("boolean: ", yytext); yytext[0]=='f'? yylval.Token.boolVal = false : yylval.Token.boolVal = true; return BOOLEANCONSTANTS;}
{begin} {token(strupr(yytext));  return BEGINTOKEN;}
{boolean} {token(strupr(yytext));  return BOOLEAN;}
{break} {token(strupr(yytext));  return BREAK;}
{character} {token(strupr(yytext));  return CHARACTER;}
{case} {token(strupr(yytext));  return CASE;}
{continue} {token(strupr(yytext));  return CONTINUE;}
{constant} {token(strupr(yytext));  return CONSTANT;}
{declare} {token(strupr(yytext));  return DECLARE;}
{do} {token(strupr(yytext));  return DO;}
{else} {token(strupr(yytext));  return ELSE;}
{end} {token(strupr(yytext));  return END;}
{exit} {token(strupr(yytext));  return EXIT;}
{float} {token(strupr(yytext));  return FLOAT;}
{real} {token(strupr(yytext));  return FLOAT;}
{for} {token(strupr(yytext));  return FOR;}
{if} {token(strupr(yytext));  return IF;}
{in} {token(strupr(yytext));  return IN;}
{integer} {token(strupr(yytext));  return INTEGER;}
{loop} {token(strupr(yytext));  return LOOP;}
{print} {token(strupr(yytext));  return PRINT;}
{println} {token(strupr(yytext));  return PRINTLN;}
{procedure} {token(strupr(yytext));  return PROCEDURE;}
{program} {token(strupr(yytext));  return PROGRAM;}
{return} {token(strupr(yytext));  return RETURN;}
{string} {token(strupr(yytext));  return STR;}
{then} {token(strupr(yytext));  return THEN;}
{while} {token(strupr(yytext));  return WHILE;}

{remainder} {token("%");  return REMAINDER;}
{stringConstant}  {LIST; BEGIN STRING;  }

{integerConstants} { sscanf(yytext, "%d", &yylval.Token.intVal); cout<< yylval.Token.intVal; yylval.Token.realVal = atof(yytext); tokenInteger("integer",yylval);   return INTEGERCONSTANT;}

<STRING>\"\" {LIST;str.push_back('\"');}
<STRING>\" {tokenString("String: ",str);  yylval.Token.strVal = new string(str); str = "";   BEGIN 0;  return STRINGCONSTANT;}
<STRING>.   {LIST;str.push_back(*yytext);}

{singleLineComment} {LIST; }
{multiLineComment} {LIST; BEGIN COMMENT; }
<COMMENT>\n {LIST;printf("%d: %s", linenum, buf); linenum++; buf[0] = '\0';}
<COMMENT>\} {LIST; BEGIN 0;}
<COMMENT>. {LIST;}
{identifiers}  {  tokenString("id: ",yytext);  
                yylval.Token.name = new string(yytext);
                return IDENTIFIER;}

{leftSquareBracket}  {token("\'\[\'"); return LEFTSQUAREBRACKET;}
{rightSquareBracket}  {token("\']\'"); return RIGHTSQUAREBRACKET;}
{leftParenthese}  {token("\'\(\'");  return LEFTPARENTHESE;}
\n {
    LIST;
    if(buf)printf("%d: %s", linenum, buf);
    linenum++;
    buf[0] = '\0';
   
}
[\t]* {LIST; }

{rightParenthese}  {token("\')\'"); return RIGHTPARENTHESE;}
\r {LIST;}
[ ] {LIST;}
.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }

%%



int yywrap()
{
    int i;
   
  
  
  
    return(1);
}
