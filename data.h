//This header files contains multiple variable declarations that are shared across more than one
//.c file between lex, parser, and vm. If a variable is only needed in one .c file, it is locally or globally defined there.
//If it needs to be shared across more than one .c file, it is declared here instead.

//used in parser.c
#define MAX_SYMBOL_TABLE_SIZE 1000
#define CODE_SIZE 1000
#define MAX_LEXI_LEVELS 3
#define MAX_STACK_HEIGHT 2000

extern int lexoutput;
extern int codegenoutput;
extern int vmoutput;

extern int errorCount;

typedef enum {
    nulsym = 1, identsym, numbersym, plussym, minussym,
    multsym,  slashsym, oddsym, eqsym, neqsym, lessym, leqsym,
    gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
    periodsym, becomessym, beginsym, endsym, ifsym, thensym,
    whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
    readsym , elsesym
} token_type;


/*
char token_type_name[100][50] = {" ",
                            "nulsym",
                            "identsym",
                            "numbersym",
                            "plussym",
                            "minussym",
                            "multsym",
                            "slashsym",
                            "oddsym",
                            "eqsym",
                            "lessym",
                            "leqsym",
                            "gtrsym",
                            "geqsym",
                            "lparentsym",
                            "rparentsym",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            "",
                            };
*/
//struct used to contain all tokens details
typedef struct {
    token_type tokenID;
    int numberValue;
    char name[12];
}tokenStruct;

extern tokenStruct lexList[5000];
extern int lexListIndex;

//for connecting parser to vm, add "extern instruction code[CODE_SIZE];
//as well as instruction struct below

 typedef struct {
     int op; //Opcode
     int l;  //L
     int m;  //M
 } instruction;

extern instruction code[CODE_SIZE];


/**functions**/

//Only functions that need to be shared throughout the 3 .c files need to be declared here. Any function only used within it's respective .c file can be declared at the top of the .c file with the function prototypes.

//Called by main
//void compile(char*);
void compile(void);

//called inside main. These are the 3 functions (aka the .c files) that will be called during execution.
//void lex(char*);
void lex(void);
void parse(void);
void vm(void);
