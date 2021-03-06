symbol_t *
symbol_create(char *name)
{
symbol_t *new_symbol;
new_symbol = (symbol_t *)malloc(sizeof(symbol_t));
if (new_symbol == NULL) {
perror("Unable to create new symbol");
exit(EX_SOFTWARE);
}
memset(new_symbol, 0, sizeof(*new_symbol));
new_symbol->name = strdup(name);
if (new_symbol->name == NULL)
stop("Unable to strdup symbol name", EX_SOFTWARE);
new_symbol->type = UNINITIALIZED;
new_symbol->count = 1;
return (new_symbol);
}
void
symbol_delete(symbol_t *symbol)
{
if (symtable != NULL) {
DBT key;
key.data = symbol->name;
key.size = strlen(symbol->name);
symtable->del(symtable, &key, 0);
}
switch(symbol->type) {
case SCBLOC:
case SRAMLOC:
case REGISTER:
if (symbol->info.rinfo != NULL)
free(symbol->info.rinfo);
break;
case ALIAS:
if (symbol->info.ainfo != NULL)
free(symbol->info.ainfo);
break;
case MASK:
case FIELD:
case ENUM:
case ENUM_ENTRY:
if (symbol->info.finfo != NULL) {
symlist_free(&symbol->info.finfo->symrefs);
free(symbol->info.finfo);
}
break;
case DOWNLOAD_CONST:
case CONST:
if (symbol->info.cinfo != NULL)
free(symbol->info.cinfo);
break;
case LABEL:
if (symbol->info.linfo != NULL)
free(symbol->info.linfo);
break;
case UNINITIALIZED:
default:
break;
}
free(symbol->name);
free(symbol);
}
void
symtable_open()
{
symtable = dbopen(NULL,
O_CREAT | O_NONBLOCK | O_RDWR, 0, DB_HASH,
NULL);
if (symtable == NULL) {
perror("Symbol table creation failed");
exit(EX_SOFTWARE);
}
}
void
symtable_close()
{
if (symtable != NULL) {
DBT key;
DBT data;
while (symtable->seq(symtable, &key, &data, R_FIRST) == 0) {
symbol_t *stored_ptr;
memcpy(&stored_ptr, data.data, sizeof(stored_ptr));
symbol_delete(stored_ptr);
}
symtable->close(symtable);
}
}
symbol_t *
symtable_get(char *name)
{
symbol_t *stored_ptr;
DBT key;
DBT data;
int retval;
key.data = (void *)name;
key.size = strlen(name);
if ((retval = symtable->get(symtable, &key, &data, 0)) != 0) {
if (retval == -1) {
perror("Symbol table get operation failed");
exit(EX_SOFTWARE);
} else if (retval == 1) {
symbol_t *new_symbol;
new_symbol = symbol_create(name);
data.data = &new_symbol;
data.size = sizeof(new_symbol);
if (symtable->put(symtable, &key, &data,
0) !=0) {
perror("Symtable put failed");
exit(EX_SOFTWARE);
}
return (new_symbol);
} else {
perror("Unexpected return value from db get routine");
exit(EX_SOFTWARE);
}
}
memcpy(&stored_ptr, data.data, sizeof(stored_ptr));
stored_ptr->count++;
data.data = &stored_ptr;
if (symtable->put(symtable, &key, &data, 0) !=0) {
perror("Symtable put failed");
exit(EX_SOFTWARE);
}
return (stored_ptr);
}
symbol_node_t *
symlist_search(symlist_t *symlist, char *symname)
{
symbol_node_t *curnode;
curnode = SLIST_FIRST(symlist);
while(curnode != NULL) {
if (strcmp(symname, curnode->symbol->name) == 0)
break;
curnode = SLIST_NEXT(curnode, links);
}
return (curnode);
}
void
symlist_add(symlist_t *symlist, symbol_t *symbol, int how)
{
symbol_node_t *newnode;
newnode = (symbol_node_t *)malloc(sizeof(symbol_node_t));
if (newnode == NULL) {
stop("symlist_add: Unable to malloc symbol_node", EX_SOFTWARE);
}
newnode->symbol = symbol;
if (how == SYMLIST_SORT) {
symbol_node_t *curnode;
int field;
field = FALSE;
switch(symbol->type) {
case REGISTER:
case SCBLOC:
case SRAMLOC:
break;
case FIELD:
case MASK:
case ENUM:
case ENUM_ENTRY:
field = TRUE;
break;
default:
stop("symlist_add: Invalid symbol type for sorting",
EX_SOFTWARE);
}
curnode = SLIST_FIRST(symlist);
if (curnode == NULL
|| (field
&& (curnode->symbol->type > newnode->symbol->type
|| (curnode->symbol->type == newnode->symbol->type
&& (curnode->symbol->info.finfo->value >
newnode->symbol->info.finfo->value))))
|| (!field && (curnode->symbol->info.rinfo->address >
newnode->symbol->info.rinfo->address))) {
SLIST_INSERT_HEAD(symlist, newnode, links);
return;
}
while (1) {
if (SLIST_NEXT(curnode, links) == NULL) {
SLIST_INSERT_AFTER(curnode, newnode,
links);
break;
} else {
symbol_t *cursymbol;
cursymbol = SLIST_NEXT(curnode, links)->symbol;
if ((field
&& (cursymbol->type > symbol->type
|| (cursymbol->type == symbol->type
&& (cursymbol->info.finfo->value >
symbol->info.finfo->value))))
|| (!field
&& (cursymbol->info.rinfo->address >
symbol->info.rinfo->address))) {
SLIST_INSERT_AFTER(curnode, newnode,
links);
break;
}
}
curnode = SLIST_NEXT(curnode, links);
}
} else {
SLIST_INSERT_HEAD(symlist, newnode, links);
}
}
void
symlist_free(symlist_t *symlist)
{
symbol_node_t *node1, *node2;
node1 = SLIST_FIRST(symlist);
while (node1 != NULL) {
node2 = SLIST_NEXT(node1, links);
free(node1);
node1 = node2;
}
SLIST_INIT(symlist);
}
void
symlist_merge(symlist_t *symlist_dest, symlist_t *symlist_src1,
symlist_t *symlist_src2)
{
symbol_node_t *node;
*symlist_dest = *symlist_src1;
while((node = SLIST_FIRST(symlist_src2)) != NULL) {
SLIST_REMOVE_HEAD(symlist_src2, links);
SLIST_INSERT_HEAD(symlist_dest, node, links);
}
SLIST_INIT(symlist_src1);
SLIST_INIT(symlist_src2);
}
void
aic_print_file_prologue(FILE *ofile)
{
if (ofile == NULL)
return;
fprintf(ofile,
"/*\n"
" * DO NOT EDIT - This file is automatically generated\n"
" * from the following source files:\n"
" *\n"
"%s */\n",
versions);
}
void
aic_print_include(FILE *dfile, char *include_file)
{
if (dfile == NULL)
return;
fprintf(dfile, "\n#include \"%s\"\n\n", include_file);
}
void
aic_print_reg_dump_types(FILE *ofile)
{
if (ofile == NULL)
return;
fprintf(ofile,
"typedef int (%sreg_print_t)(u_int, u_int *, u_int);\n"
"typedef struct %sreg_parse_entry {\n"
" char *name;\n"
" uint8_t value;\n"
" uint8_t mask;\n"
"} %sreg_parse_entry_t;\n"
"\n",
prefix, prefix, prefix);
}
static void
aic_print_reg_dump_start(FILE *dfile, symbol_node_t *regnode)
{
if (dfile == NULL)
return;
fprintf(dfile,
"static const %sreg_parse_entry_t %s_parse_table[] = {\n",
prefix,
regnode->symbol->name);
}
static void
aic_print_reg_dump_end(FILE *ofile, FILE *dfile,
symbol_node_t *regnode, u_int num_entries)
{
char *lower_name;
char *letter;
lower_name = strdup(regnode->symbol->name);
if (lower_name == NULL)
stop("Unable to strdup symbol name", EX_SOFTWARE);
for (letter = lower_name; *letter != '\0'; letter++)
*letter = tolower(*letter);
if (dfile != NULL) {
if (num_entries != 0)
fprintf(dfile,
"\n"
"};\n"
"\n");
fprintf(dfile,
"int\n"
"%s%s_print(u_int regvalue, u_int *cur_col, u_int wrap)\n"
"{\n"
" return (%sprint_register(%s%s, %d, \"%s\",\n"
" 0x%02x, regvalue, cur_col, wrap));\n"
"}\n"
"\n",
prefix,
lower_name,
prefix,
num_entries != 0 ? regnode->symbol->name : "NULL",
num_entries != 0 ? "_parse_table" : "",
num_entries,
regnode->symbol->name,
regnode->symbol->info.rinfo->address);
}
fprintf(ofile,
"#if AIC_DEBUG_REGISTERS\n"
"%sreg_print_t %s%s_print;\n"
"#else\n"
"#define %s%s_print(regvalue, cur_col, wrap) \\\n"
" %sprint_register(NULL, 0, \"%s\", 0x%02x, regvalue, cur_col, wrap)\n"
"#endif\n"
"\n",
prefix,
prefix,
lower_name,
prefix,
lower_name,
prefix,
regnode->symbol->name,
regnode->symbol->info.rinfo->address);
}
static void
aic_print_reg_dump_entry(FILE *dfile, symbol_node_t *curnode)
{
int num_tabs;
if (dfile == NULL)
return;
fprintf(dfile,
" { \"%s\",",
curnode->symbol->name);
num_tabs = 3 - (strlen(curnode->symbol->name) + 5) / 8;
while (num_tabs-- > 0)
fputc('\t', dfile);
fprintf(dfile, "0x%02x, 0x%02x }",
curnode->symbol->info.finfo->value,
curnode->symbol->info.finfo->mask);
}
void
symtable_dump(FILE *ofile, FILE *dfile)
{
symlist_t registers;
symlist_t masks;
symlist_t constants;
symlist_t download_constants;
symlist_t aliases;
symlist_t exported_labels;
symbol_node_t *curnode;
symbol_node_t *regnode;
DBT key;
DBT data;
int flag;
int reg_count = 0, reg_used = 0;
u_int i;
if (symtable == NULL)
return;
SLIST_INIT(&registers);
SLIST_INIT(&masks);
SLIST_INIT(&constants);
SLIST_INIT(&download_constants);
SLIST_INIT(&aliases);
SLIST_INIT(&exported_labels);
flag = R_FIRST;
while (symtable->seq(symtable, &key, &data, flag) == 0) {
symbol_t *cursym;
memcpy(&cursym, data.data, sizeof(cursym));
switch(cursym->type) {
case REGISTER:
case SCBLOC:
case SRAMLOC:
symlist_add(&registers, cursym, SYMLIST_SORT);
break;
case MASK:
case FIELD:
case ENUM:
case ENUM_ENTRY:
symlist_add(&masks, cursym, SYMLIST_SORT);
break;
case CONST:
symlist_add(&constants, cursym,
SYMLIST_INSERT_HEAD);
break;
case DOWNLOAD_CONST:
symlist_add(&download_constants, cursym,
SYMLIST_INSERT_HEAD);
break;
case ALIAS:
symlist_add(&aliases, cursym,
SYMLIST_INSERT_HEAD);
break;
case LABEL:
if (cursym->info.linfo->exported == 0)
break;
symlist_add(&exported_labels, cursym,
SYMLIST_INSERT_HEAD);
break;
default:
break;
}
flag = R_NEXT;
}
aic_print_file_prologue(ofile);
aic_print_reg_dump_types(ofile);
aic_print_file_prologue(dfile);
aic_print_include(dfile, stock_include_file);
SLIST_FOREACH(curnode, &registers, links) {
if (curnode->symbol->dont_generate_debug_code)
continue;
switch(curnode->symbol->type) {
case REGISTER:
case SCBLOC:
case SRAMLOC:
{
symlist_t *fields;
symbol_node_t *fieldnode;
int num_entries;
num_entries = 0;
reg_count++;
if (curnode->symbol->count == 1)
break;
fields = &curnode->symbol->info.rinfo->fields;
SLIST_FOREACH(fieldnode, fields, links) {
if (num_entries == 0)
aic_print_reg_dump_start(dfile,
curnode);
else if (dfile != NULL)
fputs(",\n", dfile);
num_entries++;
aic_print_reg_dump_entry(dfile, fieldnode);
}
aic_print_reg_dump_end(ofile, dfile,
curnode, num_entries);
reg_used++;
}
default:
break;
}
}
fprintf(stderr, "%s: %d of %d register definitions used\n", appname,
reg_used, reg_count);
while (SLIST_FIRST(&masks) != NULL) {
char *regname;
curnode = SLIST_FIRST(&masks);
SLIST_REMOVE_HEAD(&masks, links);
regnode = SLIST_FIRST(&curnode->symbol->info.finfo->symrefs);
regname = regnode->symbol->name;
regnode = symlist_search(&registers, regname);
SLIST_INSERT_AFTER(regnode, curnode, links);
}
while (SLIST_FIRST(&aliases) != NULL) {
char *regname;
curnode = SLIST_FIRST(&aliases);
SLIST_REMOVE_HEAD(&aliases, links);
regname = curnode->symbol->info.ainfo->parent->name;
regnode = symlist_search(&registers, regname);
SLIST_INSERT_AFTER(regnode, curnode, links);
}
while (SLIST_FIRST(&registers) != NULL) {
symbol_node_t *curnode;
u_int value;
char *tab_str;
char *tab_str2;
curnode = SLIST_FIRST(&registers);
SLIST_REMOVE_HEAD(&registers, links);
switch(curnode->symbol->type) {
case REGISTER:
case SCBLOC:
case SRAMLOC:
fprintf(ofile, "\n");
value = curnode->symbol->info.rinfo->address;
tab_str = "\t";
tab_str2 = "\t\t";
break;
case ALIAS:
{
symbol_t *parent;
parent = curnode->symbol->info.ainfo->parent;
value = parent->info.rinfo->address;
tab_str = "\t";
tab_str2 = "\t\t";
break;
}
case MASK:
case FIELD:
case ENUM:
case ENUM_ENTRY:
value = curnode->symbol->info.finfo->value;
tab_str = "\t\t";
tab_str2 = "\t";
break;
default:
value = 0;
tab_str = NULL;
tab_str2 = NULL;
stop("symtable_dump: Invalid symbol type "
"encountered", EX_SOFTWARE);
break;
}
fprintf(ofile, "#define%s%-16s%s0x%02x\n",
tab_str, curnode->symbol->name, tab_str2,
value);
free(curnode);
}
fprintf(ofile, "\n\n");
while (SLIST_FIRST(&constants) != NULL) {
symbol_node_t *curnode;
curnode = SLIST_FIRST(&constants);
SLIST_REMOVE_HEAD(&constants, links);
fprintf(ofile, "#define\t%-8s\t0x%02x\n",
curnode->symbol->name,
curnode->symbol->info.cinfo->value);
free(curnode);
}
fprintf(ofile, "\n\n/* Downloaded Constant Definitions */\n");
for (i = 0; SLIST_FIRST(&download_constants) != NULL; i++) {
symbol_node_t *curnode;
curnode = SLIST_FIRST(&download_constants);
SLIST_REMOVE_HEAD(&download_constants, links);
fprintf(ofile, "#define\t%-8s\t0x%02x\n",
curnode->symbol->name,
curnode->symbol->info.cinfo->value);
free(curnode);
}
fprintf(ofile, "#define\tDOWNLOAD_CONST_COUNT\t0x%02x\n", i);
fprintf(ofile, "\n\n/* Exported Labels */\n");
while (SLIST_FIRST(&exported_labels) != NULL) {
symbol_node_t *curnode;
curnode = SLIST_FIRST(&exported_labels);
SLIST_REMOVE_HEAD(&exported_labels, links);
fprintf(ofile, "#define\tLABEL_%-8s\t0x%02x\n",
curnode->symbol->name,
curnode->symbol->info.linfo->address);
free(curnode);
}
}
