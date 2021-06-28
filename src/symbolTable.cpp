#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define TYPEINT 1
#define TYPESTRING 2
#define TYPEREAL 3
#define TYPEBOOL 4
#define TYPEPROGRAM 5
#define TYPEPROCEDURE 6
#define TYPEFUNCTION 7
#define TYPEARRAY 8
#define MAXARRAYNUM 255


void printType(int id){
    if(id == 1){
        cout << "INT";
    }else if (id == 2){
        cout << "STRING";
    }    else if (id == 3){
        cout << "REAL";
    }else if (id == 4){
        cout << "BOOLEAN";
    }else if (id == 5){
        cout << "PROGRAM";
    }else if (id == 6){
        cout << "PROCEDURE";
    }else if (id == 7){
        cout << "FUNCTION";
    }else if (id == 8){
        cout << "ARRAY";
    }
}
string printVariableType(int id){
    if(id == 1){
        return "int";
    }else if (id == 2){
        return "string";
    }    else if (id == 3){
        return "int";
    }else if (id == 4){
        return "int";
    }else if (id == 5){
        return "";
    }else if (id == 6){
        return "";
    }else if (id == 7){
        return "";
    }else if (id == 8){
        return "";
    }else if (id == -1){
        return "void";
    }
    return "";
}
class node {
    public:
	int id;
	int identifierType;
	string identifierName;
	struct node* next;
    int intVal;
    double realVal;
    string strVal;
    bool isGlobal;
    bool boolVal;
    bool isConstant = false;
    bool isFunction = false;
    int localVariableIndex;
    vector<int> parameterTypes;
    vector<bool> boolArray;
    vector<int> intArray;
    vector<string> strArray;
    vector<double> realArray;
    int arrayType;
    void initArray(int type, int size)
    {
            if(type == 1){
                intArray.resize(size);
        }else if (type == 2){
             strArray.resize(size);
        }    else if (type == 3){
             realArray.resize(size);
        }else if (type == 4){
            boolArray.resize(size);
        }
    }
};
class SymbolTable {
    public:
	int currentSize;
    int id;
    node * start;
	node * last;
	SymbolTable* nextTable ;
    node*  lookup(string s ){
        int flag = 0;
        for (node* temp = start; temp != NULL; temp = temp->next) {
            if (s ==  temp->identifierName)  {
                flag = 1;
                return temp;
            }
        }
        return NULL;
    }
    
    int insert(string s  , int type) {
        if(lookup(s)!= NULL) return -1;
        node *temp = new node;
        temp->identifierName = s;
        temp->identifierType = type;
        
        
        temp->next = NULL;
        if (currentSize == 0) {
            start = temp;
            last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
        return ++currentSize;
    }
    void dump() {
      
        for (node *temp = start; temp != NULL; temp = temp->next)
        {
            cout << "id: " << temp->id << "  name:" << temp->identifierName <<" constant: "<< temp->isConstant << "local index: "<< temp->localVariableIndex<< " type: ";
            printType(temp->identifierType);
            cout << " global: " << temp->isGlobal;
            cout << "\n";
            if(temp->identifierType == TYPEPROCEDURE || temp->identifierType == TYPEFUNCTION){
                
                for (int i = 0; i < temp->parameterTypes.size() - 1; i++){
                    cout << "parameter " << i << " ";
                    printType(temp->parameterTypes[i]);
                    cout << " ";

                }
                cout << "\nreturn Type: ";
                printType(temp->parameterTypes[temp->parameterTypes.size() - 1]);
                cout<< "\n";
            }else if (temp->identifierType == TYPEINT){
                cout << "val: " << temp->realVal<<"\n";
            }else if(temp->identifierType == TYPEREAL){
               // cout << "val: " << temp->realVal << "\n";
            }else if(temp->identifierType == TYPESTRING){
                // cout << "val: " << temp->strVal << "\n";
            }else if(temp->identifierType == TYPEBOOL){
               // cout << "val: " << temp->boolVal << "\n";
            }else if(temp->identifierType == TYPEARRAY){
                cout << "array type : ";
                printType(temp->arrayType);
                cout << "\n";
                cout << "array size: ";
                if(temp->arrayType == 1){
                    cout << temp->intArray.size() <<" \n";
                    for (int i = 0; i < temp->intArray.size(); i++)
                        cout <<"index: "<< i <<" val:" <<temp->intArray[i] << " ";
                }else if (temp->arrayType== 2){
                    cout << temp->strArray.size() <<" \n";
                    for (int i = 0; i < temp->strArray.size(); i++)
                        cout <<"index: "<< i <<" val:" <<temp->strArray[i] << " ";
                }  else if (temp->arrayType == 3){
                    cout << temp->realArray.size() <<" \n";
                    for (int i = 0; i < temp->realArray.size(); i++)
                        cout <<"index: "<< i <<" val:" <<temp->realArray[i] << " ";
                }else if (temp->arrayType == 4){
                    cout << temp->boolArray.size() <<" \n";
                    for (int i = 0; i < temp->boolArray.size(); i++)
                        cout <<"index: "<< i <<" val:" <<temp->boolArray[i] << " ";
                }
               
              
            }
             cout << "\n";
        }
    cout << "\n";
  
}
};
class SymbolTables {
    private:
    int symbolTableCount;
    public:
	
	SymbolTable * start;
    SymbolTables(){
        start = new SymbolTable;
        start->currentSize = 0;
        start->start = nullptr;
        start->last = nullptr;
        start->id = 0;
        start->nextTable = nullptr;
    }
    void createNewSymbolTable(){
        SymbolTable *temp = new SymbolTable;
        temp->currentSize = 0;
        temp->start = nullptr;
        temp->last = nullptr;
        temp->id = ++symbolTableCount;
        temp->nextTable = start;
        start = temp;
    }
    void popTable(){
        if(start){
            SymbolTable *temp = start;
            start = start->nextTable;
            temp->start = nullptr;
            temp->last = nullptr;
            temp->nextTable = nullptr;
            delete temp;
        }
        
        
    }
    int insert(node* data) {
        if(start->lookup(data->identifierName)!=NULL) return -1;
        node *temp = data;
        temp->next = NULL;
        if (start->currentSize == 0) {
            start->start = temp;
            start->last = temp;
        }
        else {
            start->last->next = temp;
            start->last = temp;
        }
        if (start->id == 0){
            temp->isGlobal = true;
        }else{
            temp->isGlobal = false;
        }
        return ++start->currentSize;
    }
    node* findVariable(string str){
        for (SymbolTable* temp = start; temp != NULL; temp = temp->nextTable) {
            if(temp == NULL)
                return NULL;
            node *res = temp->lookup(str);
            if (res!=NULL)
                return res;
        }
        return NULL;
    }
    node* findVariableWithType(string str, int type){
        for (SymbolTable* temp = start; temp != NULL; temp = temp->nextTable) {
            node *res = temp->lookup(str);
            if (res!=NULL && res->identifierType == type)
                return res; 
        }
        return NULL;
    }
    node* findVariableWithBasicType(string str){
        for (SymbolTable* temp = start; temp != NULL; temp = temp->nextTable) {
            node *res = temp->lookup(str);
            if (res!=NULL && (res->identifierType == TYPEINT || res->identifierType == TYPESTRING|| res->identifierType == TYPEBOOL || res->identifierType == TYPEARRAY || res->identifierType == TYPEREAL ))
                return res;
        }
        return NULL;
    }
    void dumpAllTable(){
        for (SymbolTable* temp = start; temp != NULL; temp = temp->nextTable) {
              cout << "=======================dump=================\n";
            cout << "Current Table ID: " << temp->id << "\n";
            temp->dump();
    }
    }
};

