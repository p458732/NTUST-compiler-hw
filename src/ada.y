%{
    #include<iostream>
    #include<string>
    #include "symbolTable.cpp"
    #include <fstream>
    #define TYPEINT 1
    #define TYPESTRING 2
    #define TYPEREAL 3
    #define TYPEBOOL 4
    #define TYPEPROGRAM 5
    #define TYPEPROCEDURE 6
    #define TYPEFUNCTION 7
    #define TYPEARRAY 8
    #define TYPENONE 60
    using namespace std;
    
    #define Trace(t) if (Opt_P) printf(t)
    int yylex();
    int yyerror(string s);
    int Opt_P = 1;
    int currentType=0;
    int localIndexTemp = 0;
    bool hasDeclared = false;
    node* tempNode = new node;
    string programName ; 
    node* tempNode2 = new node;
    int returnTypeTemp = 0;
    fstream file;
    bool isGlobalDeclaration = true;
   
    // 用來保存LOOKUP後的結果
    node* res;
    SymbolTables s;
    vector<int> row;
    string tempStr;
    string tempStr2;
    string tempStr3;
    int labelCount = 0;
    int ifLabelCount = 0;
    int whileLabelCount = 0;
    int needDecreaseCount = 0;
    int tempExitLabel = 0;
    int forLabelCount = 0;
    int forLowerVal = 0;
    int forHigherVal = 0;
    int returnCount = 0;
    //參數的暫存ARRAY

    vector< vector<int>> argTypeTemp;
    vector< int > ifLabelCountTemp;
    vector< int > whileLabelCountTemp;
    vector< int > forLabelCountTemp;
%}
%union{
    struct{
    string* strVal;
    string* name;
    string* name2;
    int tokenType;
    string* typeStr;
    int intVal;
    float realVal;
    bool isVariable;
    bool boolVal;
    }Token;
};

/*val*/

/* tokens */
%token COMMA COLON PERIOD SEMICOLON  RELATIONAL ASSIGNMENT
/* keyword */
%token BEGINTOKEN BOOLEAN BREAK CHARACTER CASE CONTINUE CONSTANT  DECLARE DO READ
%token  ELSE END EXIT FLOAT FOR IF IN INTEGER  LOOP PRINT PRINTLN PROCEDURE
%token  PROGRAM RETURN STR THEN WHILE
%token  KEYWORD LOGICAL REMAINDER 
%token   STR 
%token LEFTSQUAREBRACKET RIGHTSQUAREBRACKET
%token LEFTPARENTHESE RIGHTPARENTHESE
%token CHANGELINE SPACE
%token<Token> INTEGERCONSTANT
%token<Token> STRINGCONSTANT 
%token<Token> REALCONSTANT
%token<Token> BOOLEANCONSTANTS
%token<Token> IDENTIFIER

%type<Token>  expression array_index 
%type<Token> print_expression
/*arithmetic*/
%left OR
%left AND
%nonassoc NOT
%left '>' '<' GREATEQUAL LESSEQUAL NOTEQUAL '='

%left '-' '+'
%left '*' '/' '%'
%nonassoc UMINUS
%%
program: PROGRAM {}IDENTIFIER {
                            file.open("./"+ *$3.name + ".jasm",ios::out);
                            file << "class " + *$3.name <<"\n";
                            file <<"{\n";
                            programName = *$3.name;
                            // insert program identifer
                            Trace("Read program ID\n"); 
                            
                            tempNode->identifierType = TYPEPROGRAM;
                            tempNode->identifierName = *$3.name;
                            if(s.insert( tempNode) == -1)
                            {
                                yyerror("same idenifier name in a symbolTable\n");
                            }
                            //reset tempNode
                            tempNode = new node;

                            }
                            declare   
                            {
                                isGlobalDeclaration = false;
                            }procedures  BEGINTOKEN
                            {
                                file << "   method public static void main(java.lang.String[])\n";
                                file << "   max_stack 15\n";
                                file << "   max_locals 15\n";
                                file << "   {\n" ;
                            }  statements   END SEMICOLON END IDENTIFIER 
                            { 
                                cout<<"begin: "<<*$14.name<<"\n";
                                cout<<"end: "<<s.start->start->identifierName<<"\n";
                                // check begin name and end name
                                if(*$14.name != *$3.name){
                                yyerror("program name different\n");

                                }
                                else{  
                                    s.dumpAllTable(); s.popTable();
                                    Trace("Success syntax\n");
                                file << "       return\n";
                                file << "   }\n";
                                file <<"}";

                                    } 
                            };

/* declare */
declare:  %empty{Trace("detect empty DECLARE\n");}   | DECLARE{Trace("detect DECLARE\n");}   declarations {};

declarations:  %empty | declaration {Trace("detect declaration\n");} declarations {Trace("declarations\n");};

declaration: constantDeclaration { Trace("detect constantDeclaration\n");}| variableDeclaration {Trace("detect variableDeclaration\n");} | arrayDeclaration {Trace("detect arrayDeclaration\n");};

variableDeclaration: IDENTIFIER typeWithEmpty variableDeclarationOptional  
            {   // if variable type is NONE then set default INT!
                if(tempNode->identifierType == TYPENONE)
                {
                    tempNode->identifierType = TYPEINT;
                    
                }
                tempNode->id = localIndexTemp++;
                tempNode->identifierName = *$1.name;
                
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                /*NEW*/
                if(isGlobalDeclaration){
                    file << "   field static " + printVariableType(tempNode->identifierType) + " " + tempNode->identifierName + tempStr + "\n";
                    tempStr = "";
                    tempStr2 = "";
                }else{
                    if(tempStr2 != ""){
                        // later push
                        // file << tempStr2 <<"\n";
                        file << "       istore " << to_string(tempNode->id)<<"\n";

                    }
                    
                    tempStr = "";
                    tempStr2 = "";
                }
                /*NEW*/
                tempNode = new node;
                
                //reset tempNode
                // insert variable identifer
            }  SEMICOLON{

};
constantDeclaration: IDENTIFIER  COLON  CONSTANT typeWithEmpty   ASSIGNMENT expression 
            {

                tempNode->identifierName = *$1.name;
                // set contant value = 1
                tempNode->isConstant = true;
                // check right value and left vale are consistent?
                if(($6.tokenType != tempNode->identifierType) && tempNode->identifierType != TYPENONE)
                {
                    yyerror("declare constant type inconsistent\n");
                }
                // set variavle type
                tempNode->identifierType = $6.tokenType;
                tempNode->id = localIndexTemp++;
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                /*NEW*/
                if(tempNode->identifierType == TYPEBOOL){
                            if ($6.boolVal){
                                tempNode->intVal = 1;
                            }else{
                                tempNode->intVal = 0;
                            }
                            tempStr = " = " + to_string(tempNode->intVal);
                            tempStr2 = "        sipush " +  to_string(tempNode->intVal);
                }
                else if(tempNode->identifierType != TYPESTRING){
                            tempNode->realVal = int($6.realVal);
                            tempStr = " = " + to_string(int(tempNode->realVal));
                            tempStr2 = "        sipush " +  to_string(int(tempNode->realVal));
                }else{
                            tempNode->strVal = *$6.strVal;
                            tempStr = "";
                            tempStr2 = "";
                }
                if(isGlobalDeclaration){
                    file << "   field static " + printVariableType(tempNode->identifierType) + " " + tempNode->identifierName + tempStr + "\n";
                    tempStr = "";
                    tempStr2 = "";
                }else{
                    // later push
                    // file << tempStr2 <<"\n";
                    file << "       istore " << to_string(tempNode->id)<<"\n";
                    tempStr = "";
                    tempStr2 = "";
                }
                /*NEW*/
                tempNode = new node;
                
            }
            SEMICOLON
            {
                Trace("constantDeclaration\n");
            };
arrayDeclaration: IDENTIFIER COLON type LEFTSQUAREBRACKET  INTEGERCONSTANT  RIGHTSQUAREBRACKET  
            {
                tempNode2->identifierName = *$1.name;
                tempNode2->identifierType = TYPEARRAY;
                //set array type 
                tempNode2->arrayType = tempNode2->parameterTypes[0];
                // index must >=0
                if($5.intVal < 0){
                    yyerror("array declration with size < 0\n");
                }
                tempNode2->initArray(tempNode2->arrayType, $5.intVal);
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode2) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode2 = new node;
            }
        SEMICOLON{};

variableDeclarationOptional: ASSIGNMENT expression 
                    {
                        
                        // check type inconsistent
                        if(($2.tokenType != tempNode->identifierType) && tempNode->identifierType != TYPENONE)
                        {
                            yyerror("declare  type inconsistent\n");
                        }
                        tempNode->identifierType = $2.tokenType;
                        /* NEW*/
                        if(tempNode->identifierType == TYPEBOOL){
                            // bool
                            if ($2.boolVal){
                                tempNode->intVal = 1;
                            }else{
                                tempNode->intVal = 0;
                            }
                             
                            tempStr = " = " + to_string(tempNode->intVal);
                            tempStr2 = "        sipush " +  to_string(tempNode->intVal);
                        }
                        else if(tempNode->identifierType != TYPESTRING){
                            tempNode->realVal = int($2.realVal);
                            tempStr = " = " + to_string( int(tempNode->realVal));
                            tempStr2 = "        sipush " +  to_string(int(tempNode->realVal));
                        }else{
                            tempStr = "";
                            tempStr2 = "";
                        }
                        /* NEW */
                        
                    }
                | %empty{
                        tempStr = "";
                        tempStr2 = "";
};
typeWithEmpty: COLON FLOAT{tempNode->identifierType = TYPEREAL; } 
            | COLON INTEGER {tempNode->identifierType = TYPEINT; }
            | COLON STR  {tempNode->identifierType = TYPESTRING; }
            | COLON BOOLEAN  {tempNode->identifierType = TYPEBOOL; }
            | %empty {tempNode->identifierType = TYPENONE;};


/*declare end */
/*procedure declare*/
procedures: procedure  procedures | %empty {Trace("detect empty procedure\n");};
procedure: PROCEDURE  IDENTIFIER
            {   
                localIndexTemp = 0;
                tempNode2->identifierType = TYPEPROCEDURE;
                tempNode2->identifierName = *$2.name;
                
                returnCount = 0;
                
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode2) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                } 
                cout<<"#199 create\n";
                // create new table to store arguments and variables
                s.createNewSymbolTable();

            }
            argumentss    returnType
            {
                /*NEW*/
                file << "   method public static " + printVariableType(tempNode2->parameterTypes[tempNode2->parameterTypes.size() - 1]);
                file << " " << *$2.name << "(";
                for(int i = 0; i< tempNode2->parameterTypes.size() - 1; i++){
                    if( i == tempNode2->parameterTypes.size() - 2){
                        file << printVariableType(tempNode2->parameterTypes[i]);
                        file << ")\n";
                        
                    }else{
                        file << printVariableType(tempNode2->parameterTypes[i]) << ", ";
                    }
                }
                returnTypeTemp = tempNode2->parameterTypes[tempNode2->parameterTypes.size() - 1];
                if(tempNode2->parameterTypes.size() == 1) file << ")\n";
                file << "   max_stack 15\n";
                file << "   max_locals 15\n";  
                file << "   {\n";
                /* NEW */

                    tempNode2 = new node; 
                    
            }   procedure_block  END IDENTIFIER SEMICOLON
            { 
                //check procedure begin name and end name 
                if(*$2.name != *$9.name)
                {
                    yyerror("procedure name different\n");                   
                }
                //exit scope
                s.popTable();
                /* NEW */
                if(returnCount == 0){
                    file << "       return\n";
                }
                file << "   }\n";
                /* NEW */
            };

argumentss: LEFTPARENTHESE arguments RIGHTPARENTHESE | %empty
arguments:  argument  arguments | %empty{
    Trace("detect 0 formal parameter\n");
};

argument: IDENTIFIER COLON 
            {
                 
                tempNode->identifierName = *$1.name;
                tempNode->id = localIndexTemp++;
                Trace("SEMICOLON argument\n");
            
            }type argumentSEMICOLON{};

argumentSEMICOLON: SEMICOLON | %empty{};          
type: FLOAT 
            {
                tempNode->identifierType = TYPEREAL;
                
                tempNode2->parameterTypes.push_back(TYPEREAL);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            } 
            |  INTEGER 
            {
                tempNode->identifierType = TYPEINT;
                
                cout<<"there: "<< tempNode->identifierName<<"\n";
                
                tempNode2->parameterTypes.push_back(TYPEINT);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            } 
            |STR {
                tempNode->identifierType = TYPESTRING;
                
                tempNode2->parameterTypes.push_back(TYPESTRING);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }   
                tempNode = new node;
            }
            |  BOOLEAN 
            {
                tempNode->identifierType = TYPEBOOL;
                
                tempNode2->parameterTypes.push_back(TYPEBOOL);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            }

returnType: %empty 
                {
                    // if no return means this is a procedure
                    tempNode2->isFunction = false;
                    tempNode2->parameterTypes.push_back(-1);
                }
                | RETURN type{
                    // if return means this is a function
    tempNode2->isFunction = true;
    tempNode2->identifierType = TYPEFUNCTION;
    Trace("detect RETURN\n");
};


/*procedure declare end*/
/* Statements*/
blockStatements: statement  blockStatements
                {
                    //for block one or more statement
                } | statement;
statements: statement
            { 
                // for program zero or more statement
                Trace("statements\n");
            }  statements{} 
            | %empty 
           {};
statement:  simple_statement
            | conditional
            | loop 
            | block
            |procedure_invocation {};

print_expression : LEFTPARENTHESE expression    RIGHTPARENTHESE
                    { 
                        $$.tokenType = $2.tokenType; 
                    }
                    | expression{ $$.tokenType = $1.tokenType; };

simple_statement: IDENTIFIER ASSIGNMENT expression SEMICOLON 
            {
                //check variable exist
                res = s.findVariable(*$1.name);
                if(res == NULL)
                {
                    yyerror("cannot find the IDENTIFIER: " + *$1.name);
                    
                }
                /*NEW*/
                if (res->isGlobal){
                    file << "        putstatic " << printVariableType(res->identifierType)<<" "<<  programName << "." << res->identifierName<< "\n";
                }else{
                    file << "        istore " << to_string(res->id) << "\n";
                }
                    
                /*NEW*/
                // check type consistent
                if(res->identifierType == TYPESTRING)
                {
                    if( $3.tokenType == TYPESTRING)
                    {
                       
                    }
                    else
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEBOOL)
                {
                    if( $3.tokenType == TYPEBOOL)
                    {
                       
                    }
                    else
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEINT)
                {
                    if($3.tokenType == TYPEREAL)
                    {
                        Trace("right expression coercion REAL -> INT  \n");
                    }
                    else if($3.tokenType != TYPEINT)
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEREAL)
                {
                    if($3.tokenType == TYPEINT)
                    {
                        Trace("right expression coercion INT -> REAL  \n");
                    }
                    else if($3.tokenType != TYPEREAL)
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else 
                {
                    yyerror("left operand must be int ,string, bool, real!\n");
                }
                //check constant variable
                if(res->isConstant == 1)
                {
                    yyerror("constant cannot reassignment! \n");
                }
                
                Trace("detect assignment\n");
            }
            |IDENTIFIER LEFTSQUAREBRACKET expression  RIGHTSQUAREBRACKET ASSIGNMENT expression SEMICOLON 
                {
                    // check index type
                    if($3.tokenType != TYPEINT)
                    {
                        yyerror("array index must be integer! \n");
                    }
                    // check variable exist
                    res = s.findVariable(*$1.name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER: " + *$1.name);
                        
                    }
                    if(res->identifierType != TYPEARRAY)
                    {
                        yyerror("identifier is not a array! \n");
                    }
                    // check index type
                    if(res->arrayType == TYPEINT )
                    {
                        if($6.tokenType == TYPEREAL)
                        {
                            Trace("right expression coercion REAL -> INT  \n");
                        }
                        else if ($6.tokenType != TYPEINT)
                        {
                            yyerror("type is not consistent\n");
                        }
                    }
                    else if (res->arrayType == TYPEREAL)
                    {
                        if($6.tokenType == TYPEINT)
                        {
                            Trace("right expression coercion INT -> REAL  \n");
                        }
                        else if ($6.tokenType != TYPEREAL)
                        {
                            yyerror("type is not consistent\n");
                        }
                    }
                    else if (res->arrayType != $6.tokenType)
                    {
                        yyerror("type is not consistent\n");
                    }
                    Trace("Array assignment\n");
                }
            |PRINT
            { 
                /*NEW*/
                file << "       getstatic java.io.PrintStream java.lang.System.out\n";
                /*NEW*/ 
            } print_expression 
            {
                if($3.tokenType == TYPESTRING){
                    file << "       invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                }else if($3.tokenType == TYPEBOOL){
                    file << "       invokevirtual void java.io.PrintStream.print(boolean)\n";
                }else if($3.tokenType == TYPEINT){
                    file << "       invokevirtual void java.io.PrintStream.print(int)\n";
                }
                
            }SEMICOLON
            |PRINTLN
            { 
                /*NEW*/
                file << "       getstatic java.io.PrintStream java.lang.System.out\n";
                /*NEW*/ 
            }  print_expression
            {
                if($3.tokenType == TYPESTRING){
                    file << "       invokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                }else if($3.tokenType == TYPEINT){
                    file << "       invokevirtual void java.io.PrintStream.println(int)\n";
                }else if($3.tokenType == TYPEBOOL){
                    file << "       invokevirtual void java.io.PrintStream.println(boolean)\n";
                }
            } SEMICOLON
            |READ IDENTIFIER
                {
                    res = s.findVariable(*$2.name);
                    s.dumpAllTable();
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    }
                    Trace("READ \n");
                }SEMICOLON
            |RETURN expression SEMICOLON
            {
                returnCount++;
                file <<"        ireturn\n";
            }
            |RETURN SEMICOLON
            {
                returnCount++;
                file <<"        return\n";
            }
expression:  LEFTPARENTHESE expression      RIGHTPARENTHESE
                        {
                            // check expression type
                            if($2.tokenType != TYPEINT && $2.tokenType != TYPEREAL && $2.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when '(expression)' \n");
                            }
                            //pass type
                            $$.tokenType = $2.tokenType;
                            $$.realVal = $2.realVal;
                            $$.boolVal = $2.boolVal;
                            cout<< "calculate val: "<<$$.realVal<<"\n";
                            cout<< "calculate bool  val: "<<$$.boolVal<<"\n";
                        }
            |expression '+' expression 
                        {
                            // implication type coercion and type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '+' \n");
                            }
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '+' \n");
                            }
                            else if($1.tokenType == TYPEINT && $3.tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if($1.tokenType == TYPEREAL && $3.tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if ($1.tokenType == TYPEINT && $3.tokenType == TYPEINT)
                            {
                                $$.tokenType = TYPEINT;
                            }
                            else
                            {
                                $$.tokenType = TYPEREAL;
                                
                            }
                            Trace("detect '+' \n");
                            $$.realVal = $1.realVal + $3.realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       iadd\n";
                            /*NEW*/
                            cout<< "calculate val: "<<$$.realVal<<"\n";
                        }
            |expression '-' expression
                        {
                            // implication type coercion and type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                            else if($1.tokenType == TYPEINT && $3.tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if($1.tokenType == TYPEREAL && $3.tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if ($1.tokenType == TYPEINT && $3.tokenType == TYPEINT)
                            {
                                $$.tokenType = TYPEINT;
                            }
                            else
                            {
                                $$.tokenType = TYPEREAL;
                            }
                            Trace("detect '-' \n");
                            $$.realVal = $1.realVal - $3.realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       isub\n";
                            /*NEW*/
                            cout<< "calculate val: "<<$$.realVal<<"\n";
                        } 
            |expression '*' expression 
                        {
                            // implication type coercion and type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '*' \n");
                            }
                            if($1.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '*' \n");
                            }
                            else if($1.tokenType == TYPEINT && $3.tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if($1.tokenType == TYPEREAL && $3.tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if ($1.tokenType == TYPEINT && $3.tokenType == TYPEINT)
                            {
                                $$.tokenType = TYPEINT;
                            }
                            else
                            {
                                $$.tokenType = TYPEREAL;
                            }
                            Trace("detect '*' \n");
                            $$.realVal = $1.realVal * $3.realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       imul\n";
                            /*NEW*/
                            cout<< "calculate val: "<<$$.realVal<<"\n";
                        }
            |expression  '/' expression 
                        {
                            // implication type coercion and type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '/' \n");
                            }
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '/' \n");
                            }
                            else if($1.tokenType == TYPEINT && $3.tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if($1.tokenType == TYPEREAL && $3.tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                $$.tokenType = TYPEREAL;
                            }
                            else if ($1.tokenType == TYPEINT && $3.tokenType == TYPEINT)
                            {
                                $$.tokenType = TYPEINT;
                            }
                            else
                            {
                                $$.tokenType = TYPEREAL;
                            }
                            $$.realVal = $1.realVal / $3.realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       idiv\n";
                            /*NEW*/
                            cout<< "calculate val: "<<$$.realVal<<"\n";
                            Trace("detect '/' \n");
                        }
            |expression  AND expression 
                        {
                            // type check
                            if($1.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'and' \n");
                            }
                            if($3.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'and' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.boolVal && $3.boolVal);
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       iand\n";
                            /*NEW*/
                            Trace("detect 'AND' \n");
                            cout<< "calculate AND bool val: "<<$$.boolVal<<"\n";
                        }
            |expression  OR expression 
                        {
                            // type check
                            if($1.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'or' \n");
                            }
                            if($3.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'or' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.boolVal || $3.boolVal);
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       ior\n";
                            /*NEW*/
                            cout<< "calculate OR bool val: "<<$$.boolVal<<"\n";
                            Trace("detect 'OR' \n");
                        }
            |NOT expression            
                        {
                            // type check
                            if($2.tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'not' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = !($2.boolVal);
                            
                            Trace("detect 'NOT' \n");
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       sipush 1\n";
                                file << "       ixor\n";
                            }
                                
                            /*NEW*/
                            cout<< "calculate NOT bool val: "<<$$.boolVal<<"\n";
                        }  
            |expression '<' expression  
                        {
                            // type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<' \n");
                            }
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal < $3.realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       iflt "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate bool val: "<<$$.boolVal<<"\n";
                            Trace("detect '<' \n");
                        }
            |expression '>' expression
                        {
                            // type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>' \n");
                            }
                            
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal > $3.realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifgt "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate> bool val: "<<$$.boolVal<<"\n";
                            Trace("detect '>' \n");
                        }
            |expression '=' expression 
                        {
                            // type check
                            if($1.tokenType != $3.tokenType)
                            {
                                yyerror("error type when '=' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal == $3.realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifeq "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate= bool val: "<<$$.boolVal<<"\n";;
                            Trace("detect '=' \n");
                        }
            |expression '%' expression 
                        {
                            // type check
                            if($1.tokenType != $3.tokenType)
                            {
                                yyerror("error type when '%' \n");
                            }
                            $$.tokenType = TYPEINT;
                            // $$.realVal = float((int($1.realVal) % int($3.realVal)));
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       irem\n";
                            }
                            /*NEW*/
                            cout<< "calculate= real val: "<<$$.realVal<<"\n";;
                            
                        }            
            |expression GREATEQUAL expression
                        {
                            // type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>=' \n");
                            }
                            
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>=' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal >= $3.realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifge "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            cout<< "calculate>= bool val: "<<$$.boolVal<<"\n";
                            Trace("detect '>=' \n");
                        }
            |expression  LESSEQUAL expression 
                        {
                            // type check
                            if($1.tokenType != TYPEINT && $1.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<=' \n");
                            }
                            if($3.tokenType != TYPEINT && $3.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<=' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal <= $3.realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifle "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                labelCount += 2;
                            }
                            cout<< "calculate<= bool val: " <<$$.boolVal<<"\n";
                            Trace("detect '<=' \n");
                        }
            |expression NOTEQUAL expression  
                        {
                            // type check
                            if($3.tokenType != $1.tokenType)
                            {
                                yyerror("error type when '/=' \n");
                            }
                            $$.tokenType = TYPEBOOL;
                            $$.boolVal = ($1.realVal != $3.realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifne "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            cout<< "calculate /= bool val:"  <<$$.boolVal<<"\n";
                            Trace("detect '/=' \n");
                        }
            |'-' expression %prec UMINUS     
                {
                    // type check
                    if($2.tokenType != TYPEINT && $2.tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                    $$.tokenType = $2.tokenType;
                    Trace("detect 'UMINUS ' \n");
                    $$.realVal =  -1* $2.realVal;
                    /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "      ineg\n";
                    /*NEW*/
                    cout<< "calculate val: "<<$$.realVal<<"\n";
                }
            |'+' REALCONSTANT  %prec UMINUS  
                {
                    // type check
                    $$.tokenType = TYPEREAL;
                    Trace("+ REAL\n");
                    $$.realVal =  $2.realVal;
                    cout<< "calculate val: "<<$$.realVal<<"\n";
                }   
            |'+' INTEGERCONSTANT %prec UMINUS  
                {
                    // type check
                    $$.tokenType = TYPEINT;
                    $$.realVal =  $2.realVal;
                    cout<< "calculate val: "<<$$.realVal<<"\n";
                }   
            |INTEGERCONSTANT 
                {
                    
                    $$.tokenType = TYPEINT;  
                    $$.realVal =  $1.realVal;
                    $1.intVal = $1.realVal;
                    $$.isVariable = false;
                    /*New*/
                    if(!isGlobalDeclaration)
                    file <<"        sipush " + to_string($1.intVal) <<"\n";

                    Trace("INT\n");
                    /*New*/
                }
            |STRINGCONSTANT  
                {
                    if(!isGlobalDeclaration){

                        file << "       ldc \"";

                        tempStr3 = *$1.strVal;
                        for (int i = 0; i< tempStr3.size(); i++)
                        {
                           file << tempStr3[i];
                        }
                        file <<"\""<<"\n";
                    }
                    
                    $$.tokenType = TYPESTRING;  
                    $$.isVariable = false;
                    *$$.strVal = *$1.strVal; 
                    Trace("STR\n");
                }
            |BOOLEANCONSTANTS  
                {
                    $$.tokenType = TYPEBOOL; 
                    $$.boolVal = $1.boolVal;
                    $$.isVariable = false;
                    if($1.boolVal){
                        if(!isGlobalDeclaration)
                        file <<"        iconst_1\n";
                    } else
                    {
                        if(!isGlobalDeclaration)
                        file <<"        iconst_0\n";
                    }
                    Trace("BOOL\n");
                }
            |REALCONSTANT  
                {
                    $$.tokenType = TYPEREAL; 
                    $$.realVal =  $1.realVal;  
                    $$.isVariable = false;
                    Trace("REALL\n");
                }
            |IDENTIFIER 
                {
                    // check variable exist
                    res = s.findVariable(*$1.name);
                    $$.isVariable = true;
                    if(isGlobalDeclaration){
                        cout<<"GGGGGGGGGGGGGGGGGGGG";
                        cout<< *$1.name <<res->realVal;
                        $$.realVal = res->realVal;
                        $$.tokenType = res->identifierType;
                    }
                    else{
                        if(res == NULL)
                        {
                            yyerror("cannot find the IDENTIFIER\n");
                        } 
                        else if(res->identifierType == TYPEPROCEDURE)
                        {
                            yyerror("this is a procedure, not a function!\n");
                        }else if (res->identifierType == TYPEFUNCTION)
                        {
                            // only function could return
                            $$.tokenType = res->parameterTypes[res->parameterTypes.size()-1];
                            // if enter this block means the function do not have parameters
                            file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                            file << "()\n";
                            if(res->parameterTypes.size() > 1) 
                            {
                                yyerror("the function has parameters !\n");
                            }
                        } 
                        else
                        {
                            /*New*/
                            if(res->identifierType == TYPESTRING){
                                
                                    file << "       ldc \""; 
                                    for (int i = 0; i< res->strVal.size(); i++)
                                    {
                                    file << res->strVal[i];
                                    }
                                    file  << "\"\n";
                            }else{
                                if(res->isGlobal){
                                    file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
                                }else{
                                    file << "       iload " << res->id <<"\n";
                                }
                            }
                            
                            /*New*/
                            $$.tokenType = res->identifierType;
                            Trace("ID\n"); 
                        }
                    }
                    
                } 
            |IDENTIFIER LEFTPARENTHESE   
                {
                    // create arg scope
                    argTypeTemp.push_back(row);
                }
                    comma_separated_expression RIGHTPARENTHESE 
                {
                    res = s.findVariable(*$1.name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    }
                    // compare formal parameter and actual parameter count consistent
                    if(argTypeTemp[argTypeTemp.size()-1].size() != res->parameterTypes.size() - 1 && !( argTypeTemp[argTypeTemp.size()-1].size() == 0 && res->parameterTypes.size()== 0 ) )
                    {
                        cout<< "argTypeTemp: " <<argTypeTemp[argTypeTemp.size()-1].size()<< "\n";
                        cout<< "res->parameterTypes.size() - 1 "<<res->parameterTypes.size() - 1<< "\n";
                        yyerror("parameter count is not consistent\n");
                    }
                     // compare formal parameter and actual parameter type consistent
                    for(int i = 0; i < argTypeTemp[argTypeTemp.size()-1].size(); i++)
                    {
                        
                        cout<<"formal parameter index :"<< i <<" type: " << res->parameterTypes[i]<<" \n";
                        cout<<" actual parameter index :"<< i <<" type: " << argTypeTemp[argTypeTemp.size()-1][i]<<" \n";
                        if( res->parameterTypes[i] != argTypeTemp[argTypeTemp.size()-1][i])
                        {
                            yyerror("parameter type is not consistent\n");
                        }
                        
                    }
                    cout<<'\n';
                    if(res !=NULL)
                    {
                        
                        if(!(res->identifierType == TYPEFUNCTION || res->identifierType == TYPEPROCEDURE))
                        {
                            yyerror("the identifier is not a procedure or a function\n");
                        }
                        // procedure can not be a function
                        if(!res->isFunction)
                        {
                            yyerror("this is a procedure, not a function\n");
                        }
                        cout<<"Function Name: "<< res->identifierName<<"\n";
                        
                    } 
                    else
                    {
                        yyerror("cannot find the function\n");
                    } 
                    /*NEW*/
                    file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                    file << "(";
                    for (int i = 0; i < res->parameterTypes.size() - 1; i++){
                        if(i == 0)
                        file << printVariableType(res->parameterTypes[i]);
                        else
                        file <<", "<< printVariableType(res->parameterTypes[i]);
                    }
                    file << ")\n";

                    /*NEW*/
                    $$.tokenType = res->parameterTypes[res->parameterTypes.size() - 1];
                    res = NULL;
                    // exit arg scope
                    argTypeTemp.pop_back();
                    
                    Trace("detect function calls\n");
                };
            |IDENTIFIER LEFTSQUAREBRACKET expression RIGHTSQUAREBRACKET
                {
                    res = s.findVariable(*$1.name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    } 
                    if(res->identifierType != TYPEARRAY)
                    {
                        yyerror("this is not a array!\n");
                    }

                    if($3.tokenType != TYPEINT )
                    {
                        yyerror("array index is not num\n");
                    }
                    else
                    {
                        $$.tokenType = res->arrayType;
                        Trace("array ID\n"); 
                    }
                }



comma_separated_expression: %empty
                            {
                                 
                            }
                            | expression 
                            {
                                cout<<"Aname: " <<*$1.name<<"\n";
                                argTypeTemp[argTypeTemp.size()-1].push_back($1.tokenType);
                            } 
                            | expression
                            {
                                cout<<"Bname: " <<*$1.name<<"\n";
                                argTypeTemp[argTypeTemp.size()-1].push_back($1.tokenType);
                            } COMMA comma_separated_expression {};



block: {cout<<"#826 create\n";s.createNewSymbolTable(); } declare     BEGINTOKEN   blockStatements{Trace("BLOCK STATEMENT\n");}   END {  s.dumpAllTable(); s.popTable(); } SEMICOLON {
Trace("block\n");
};

procedure_block: { s.dumpAllTable();} declare     BEGINTOKEN   blockStatements{Trace("BLOCK STATEMENT\n");}   END {  s.dumpAllTable();  } SEMICOLON 
{Trace("procedure_block\n");}

block_or_simple: block | simple_statement{
    
};

conditional:IF expression
            {
                if($2.tokenType != TYPEBOOL)
                {
                    yyerror("IF expression is not boolean expression \n");
                }
                /*NEW*/
                file << "       ifeq IFL" << to_string(ifLabelCount) << "\n";
                ifLabelCountTemp.push_back(ifLabelCount++);
                ifLabelCountTemp.push_back(ifLabelCount++);
                
                /*NEW*/

            } 
            THEN  block_or_simple conditional_optional END IF{} SEMICOLON{};

conditional_optional:       ELSE  
                            {
                                /*NEW*/
                                file << "       goto IFL" << to_string(ifLabelCountTemp.back()) << "\n";
                                file << "IFL" << to_string(ifLabelCountTemp[ifLabelCountTemp.size()-2]) << ":\n";
                                file << "nop\n";

                                /*NEW*/
                            }block_or_simple 
                            {
                                /*NEW*/
                                file << "IFL" << to_string(ifLabelCountTemp.back()) << ":\n";
                                file << "nop\n";
                                ifLabelCountTemp.pop_back();
                                ifLabelCountTemp.pop_back();
                                /*NEW*/
                            }
                            
                            | %empty{
                                /*NEW*/
                                file << "IFL" << to_string(ifLabelCountTemp[ifLabelCountTemp.size() - 2]) << ":\n";
                                file << "nop\n";
                                ifLabelCountTemp.pop_back();
                                ifLabelCountTemp.pop_back();
                                /*NEW*/
};

loop: WHILE 
            {
                /*NEW*/
                file << "WHL" << to_string(whileLabelCount)<<":\n";
                file << "nop\n";
                whileLabelCountTemp.push_back(whileLabelCount++);

                /*NEW*/
            }expression
            {
                if($3.tokenType != TYPEBOOL)
                {
                    yyerror("WHILE expression is not boolean expression \n");
                }
                /*NEW*/
                file << "       ifeq WHL" << to_string(whileLabelCount)<<"\n";
                whileLabelCountTemp.push_back(whileLabelCount++);
                /*NEW*/
            }
     LOOP  block_or_simple 
            {
                /*NEW*/
                file << "       goto WHL" << to_string(whileLabelCountTemp[whileLabelCountTemp.size() - 2])<<"\n";
                file << "WHL" << to_string(whileLabelCountTemp[whileLabelCountTemp.size() - 1]) << ":\n";
                file << "nop\n";
                whileLabelCountTemp.pop_back();
                whileLabelCountTemp.pop_back();
                /*NEW*/
            } END LOOP SEMICOLON
     |FOR LEFTPARENTHESE IDENTIFIER
     {
        
        
        // check variavle exist and for variable must be integer!
        res = s.findVariable(*$3.name);
        if(res == NULL)
        {
            yyerror("cannot find the IDENTIFIER\n");
        }else if(res->identifierType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }  
        tempNode = new node;
     } IN  expression
    {
        if($6.tokenType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }
        forLowerVal = $6.intVal;
       
        forLabelCountTemp.push_back($6.realVal);
        /*New*/
        res = s.findVariable(*$3.name);
        
        
        if(res->isGlobal){
            file << "       putstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       istore " << res->id <<"\n";
        }
        /*New*/
        
    } PERIOD PERIOD
    {
        /*New*/
        res = s.findVariable(*$3.name);
        forLabelCountTemp.push_back(forLabelCount);
        //begin
        file << "FORL" << to_string(forLabelCount++)<< ":\n";
        file << "nop\n";

        if(res->isGlobal){
            file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       iload " << res->id <<"\n";
        }
        /*New*/
    }  expression
    {
        if($11.tokenType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }
        forLabelCountTemp.push_back($11.intVal);
        
        /*NEW*/
        file << "       isub\n";
        // 20210618
        if($6.isVariable){
            res = s.findVariable(*$6.name);
        }else{
            res = NULL;
        }
        
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " <<$6.realVal <<"\n";
        }
        if($11.isVariable){
            res = s.findVariable(*$11.name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << $11.realVal <<"\n";
        }
        file << "       isub\n";
        file << "       ifle DEC" << to_string(needDecreaseCount) << "\n";
        file << "       ifge FORL" << to_string(forLabelCount) << "\n";
        file << "       goto DEC" << to_string(needDecreaseCount + 1) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        file << "       ifle FORL" << to_string(forLabelCount) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        
        
        file << "       iconst_0\n" ;
        file << "       goto FORL" << to_string(forLabelCount + 1) << "\n";
        file << "FORL" << to_string(forLabelCount) << ":\n";
        file << "       iconst_1\n";
        file << "FORL" << to_string(forLabelCount + 1) << ":\n";
        file << "nop\n";
        forLabelCount += 2;
        //exit
        forLabelCountTemp.push_back(forLabelCount);
        file << "       ifeq FORL" << to_string(forLabelCount++) << "\n";


        /*NEW*/
    } RIGHTPARENTHESE LOOP block_or_simple END LOOP SEMICOLON
     {
        /*NEW*/
        
            res = s.findVariable(*$3.name);
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            file << "      sipush 1\n";
            
        // 20210618
        if($6.isVariable){
            res = s.findVariable(*$6.name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << $6.realVal <<"\n";
        }
        if($11.isVariable){
            res = s.findVariable(*$11.name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << $11.realVal <<"\n";
        }
        file << "       isub\n";
        file << "       ifle DEC" << to_string(needDecreaseCount) << "\n";
        file << "       isub\n";
        file << "       goto DEC" << to_string(needDecreaseCount + 1) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        file << "       iadd\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";

        res = s.findVariable(*$3.name);
        if(res->isGlobal){
            file << "       putstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       istore " << res->id <<"\n";
        }
        file << "        goto FORL" << forLabelCountTemp[forLabelCountTemp.size() - 3] << "\n";
        file << "FORL" << forLabelCountTemp[forLabelCountTemp.size() - 1] << ":\n";
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        file << "nop\n";
        /*NEW*/
        tempNode = new node;
       
     };

procedure_invocation:  IDENTIFIER LEFTPARENTHESE
                {
                    argTypeTemp.push_back(row);
                }  comma_separated_expression RIGHTPARENTHESE SEMICOLON
                {
                    res = s.findVariable(*$1.name);
                    // compare formal parameter and actual parameter count consistent
                    if(argTypeTemp[argTypeTemp.size()- 1].size() != res->parameterTypes.size() - 1 && !( argTypeTemp[argTypeTemp.size()- 1].size() == 0 && res->parameterTypes.size()== 0 ) )
                    {
                        yyerror("procedure parameter count is not consistent\n");
                    }
                    // compare formal parameter and actual parameter type consistent
                    for(int i = 0; i < argTypeTemp[argTypeTemp.size()- 1].size(); i++)
                    {
                        
                        cout<<"formal parameter index :"<< i <<" type: " << res->parameterTypes[i]<<" \n";
                        cout<<" actual parameter index :"<< i <<" type: " << argTypeTemp[argTypeTemp.size()- 1][i]<<" \n";
                        if( res->parameterTypes[i] != argTypeTemp[argTypeTemp.size()- 1][i])
                        {
                            yyerror("parameter type is not consistent\n");
                        }
                        
                    }
                    cout<<'\n';
                    if(res !=NULL)
                    {
                        
                        if(!(res->identifierType == TYPEFUNCTION || res->identifierType == TYPEPROCEDURE))
                        {
                            yyerror("the identifier is not a procedure or a function\n");
                        }
                        if(res->isFunction)
                        {
                            yyerror("this is a function, not a  procedure\n");
                        }
                        cout<<"Procedure Name: "<< res->identifierName<<"\n";
                        /*NEW*/
                        file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                        file << "(";
                        for (int i = 0; i < res->parameterTypes.size() - 1; i++){
                            if(i == 0)
                            file << printVariableType(res->parameterTypes[i]);
                            else
                            file <<", "<< printVariableType(res->parameterTypes[i]);
                        }
                        file << ")\n";

                    /*NEW*/
                    } 
                    else
                    {
                        yyerror("cannot find the procedure\n");
                    } 
                    res = NULL;
                    argTypeTemp.pop_back();
                    Trace("detect procedure calls\n");
                };
                | IDENTIFIER  SEMICOLON
                    {
                        // call procedure with no arg
                        res = s.findVariable(*$1.name);
                        s.dumpAllTable();
                        if(res == NULL)
                        {
                            yyerror("cannot find the IDENTIFIER\n");
                        }
                        else if (res->isFunction == 1)
                        {
                            yyerror("this is a function, not a  procedure\n");
                        }
                        else if (res->identifierType != TYPEPROCEDURE)
                        {
                            yyerror("this is not a  procedure\n");
                        }
                        /*NEW*/
                        file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                        file << "()\n";
        
    
                        Trace("READ \n");
                        Trace("procedure invocation no parameter");
                    }




%%

int main()
{   
    yyparse();
    file.close();
}

int yyerror(string s)
{
   cout<<"ERROR: "<< s<<"\n";
    exit(-1);
    return 0;
    
}
