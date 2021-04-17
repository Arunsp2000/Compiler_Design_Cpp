typedef struct symbol_table
{
  int line;
  int scope;
  char name[31];
  char type;
  char *value;
  char *datatype;
}ST;

extern int table_index;
extern ST st[10000];
extern int global_scope;



void lookup(char *token,int line,char type,char *value,char *datatype);
void search_id(char *token,int lineno);
void update(char *token,int lineno,char *value);
int get_type(char *var);
void freefromsymb();
