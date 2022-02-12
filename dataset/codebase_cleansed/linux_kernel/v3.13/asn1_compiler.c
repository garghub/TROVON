static int directive_compare(const void *_key, const void *_pdir)
{
const struct token *token = _key;
const char *const *pdir = _pdir, *dir = *pdir;
size_t dlen, clen;
int val;
dlen = strlen(dir);
clen = (dlen < token->size) ? dlen : token->size;
val = memcmp(token->value, dir, clen);
if (val != 0) {
return val;
}
if (dlen == token->size) {
return 0;
}
return dlen - token->size;
}
static void tokenise(char *buffer, char *end)
{
struct token *tokens;
char *line, *nl, *p, *q;
unsigned tix, lineno;
token_list = tokens = calloc((end - buffer) / 2, sizeof(struct token));
if (!tokens) {
perror(NULL);
exit(1);
}
tix = 0;
lineno = 0;
while (buffer < end) {
lineno++;
line = buffer;
nl = memchr(line, '\n', end - buffer);
if (!nl) {
buffer = nl = end;
} else {
buffer = nl + 1;
*nl = '\0';
}
p = line;
next_comment:
while ((p = memchr(p, '-', nl - p))) {
if (p[1] == '-') {
q = p + 2;
while ((q = memchr(q, '-', nl - q))) {
if (q[1] == '-') {
q += 2;
memmove(p, q, nl - q);
goto next_comment;
}
q++;
}
*p = '\0';
nl = p;
break;
} else {
p++;
}
}
p = line;
while (p < nl) {
while (p < nl && isspace(*p))
*(p++) = 0;
if (p >= nl)
break;
tokens[tix].line = lineno;
tokens[tix].value = p;
if (isalpha(*p)) {
const char **dir;
q = p + 1;
while (q < nl && (isalnum(*q) || *q == '-' || *q == '_'))
q++;
tokens[tix].size = q - p;
p = q;
if (islower(tokens[tix].value[0])) {
tokens[tix++].token_type = TOKEN_ELEMENT_NAME;
continue;
}
dir = bsearch(&tokens[tix], directives,
sizeof(directives) / sizeof(directives[1]),
sizeof(directives[1]),
directive_compare);
if (dir) {
tokens[tix++].token_type = dir - directives;
continue;
}
tokens[tix++].token_type = TOKEN_TYPE_NAME;
continue;
}
if (isdigit(*p)) {
q = p + 1;
while (q < nl && (isdigit(*q)))
q++;
tokens[tix].size = q - p;
p = q;
tokens[tix++].token_type = TOKEN_NUMBER;
continue;
}
if (nl - p >= 3) {
if (memcmp(p, "::=", 3) == 0) {
p += 3;
tokens[tix].size = 3;
tokens[tix++].token_type = TOKEN_ASSIGNMENT;
continue;
}
}
if (nl - p >= 2) {
if (memcmp(p, "({", 2) == 0) {
p += 2;
tokens[tix].size = 2;
tokens[tix++].token_type = TOKEN_OPEN_ACTION;
continue;
}
if (memcmp(p, "})", 2) == 0) {
p += 2;
tokens[tix].size = 2;
tokens[tix++].token_type = TOKEN_CLOSE_ACTION;
continue;
}
}
if (nl - p >= 1) {
tokens[tix].size = 1;
switch (*p) {
case '{':
p += 1;
tokens[tix++].token_type = TOKEN_OPEN_CURLY;
continue;
case '}':
p += 1;
tokens[tix++].token_type = TOKEN_CLOSE_CURLY;
continue;
case '[':
p += 1;
tokens[tix++].token_type = TOKEN_OPEN_SQUARE;
continue;
case ']':
p += 1;
tokens[tix++].token_type = TOKEN_CLOSE_SQUARE;
continue;
case ',':
p += 1;
tokens[tix++].token_type = TOKEN_COMMA;
continue;
default:
break;
}
}
fprintf(stderr, "%s:%u: Unknown character in grammar: '%c'\n",
filename, lineno, *p);
exit(1);
}
}
nr_tokens = tix;
printf("Extracted %u tokens\n", nr_tokens);
#if 0
{
int n;
for (n = 0; n < nr_tokens; n++)
printf("Token %3u: '%*.*s'\n",
n,
(int)token_list[n].size, (int)token_list[n].size,
token_list[n].value);
}
#endif
}
int main(int argc, char **argv)
{
struct stat st;
ssize_t readlen;
FILE *out, *hdr;
char *buffer, *p;
int fd;
if (argc != 4) {
fprintf(stderr, "Format: %s <grammar-file> <c-file> <hdr-file>\n",
argv[0]);
exit(2);
}
filename = argv[1];
outputname = argv[2];
headername = argv[3];
fd = open(filename, O_RDONLY);
if (fd < 0) {
perror(filename);
exit(1);
}
if (fstat(fd, &st) < 0) {
perror(filename);
exit(1);
}
if (!(buffer = malloc(st.st_size + 1))) {
perror(NULL);
exit(1);
}
if ((readlen = read(fd, buffer, st.st_size)) < 0) {
perror(filename);
exit(1);
}
if (close(fd) < 0) {
perror(filename);
exit(1);
}
if (readlen != st.st_size) {
fprintf(stderr, "%s: Short read\n", filename);
exit(1);
}
p = strrchr(argv[1], '/');
p = p ? p + 1 : argv[1];
grammar_name = strdup(p);
if (!p) {
perror(NULL);
exit(1);
}
p = strchr(grammar_name, '.');
if (p)
*p = '\0';
buffer[readlen] = 0;
tokenise(buffer, buffer + readlen);
build_type_list();
parse();
out = fopen(outputname, "w");
if (!out) {
perror(outputname);
exit(1);
}
hdr = fopen(headername, "w");
if (!out) {
perror(headername);
exit(1);
}
render(out, hdr);
if (fclose(out) < 0) {
perror(outputname);
exit(1);
}
if (fclose(hdr) < 0) {
perror(headername);
exit(1);
}
return 0;
}
static int type_index_compare(const void *_a, const void *_b)
{
const struct type *const *a = _a, *const *b = _b;
if ((*a)->name->size != (*b)->name->size)
return (*a)->name->size - (*b)->name->size;
else
return memcmp((*a)->name->value, (*b)->name->value,
(*a)->name->size);
}
static int type_finder(const void *_key, const void *_ti)
{
const struct token *token = _key;
const struct type *const *ti = _ti;
const struct type *type = *ti;
if (token->size != type->name->size)
return token->size - type->name->size;
else
return memcmp(token->value, type->name->value,
token->size);
}
static void build_type_list(void)
{
struct type *types;
unsigned nr, t, n;
nr = 0;
for (n = 0; n < nr_tokens - 1; n++)
if (token_list[n + 0].token_type == TOKEN_TYPE_NAME &&
token_list[n + 1].token_type == TOKEN_ASSIGNMENT)
nr++;
if (nr == 0) {
fprintf(stderr, "%s: No defined types\n", filename);
exit(1);
}
nr_types = nr;
types = type_list = calloc(nr + 1, sizeof(type_list[0]));
if (!type_list) {
perror(NULL);
exit(1);
}
type_index = calloc(nr, sizeof(type_index[0]));
if (!type_index) {
perror(NULL);
exit(1);
}
t = 0;
types[t].flags |= TYPE_BEGIN;
for (n = 0; n < nr_tokens - 1; n++) {
if (token_list[n + 0].token_type == TOKEN_TYPE_NAME &&
token_list[n + 1].token_type == TOKEN_ASSIGNMENT) {
types[t].name = &token_list[n];
type_index[t] = &types[t];
t++;
}
}
types[t].name = &token_list[n + 1];
types[t].flags |= TYPE_STOP_MARKER;
qsort(type_index, nr, sizeof(type_index[0]), type_index_compare);
printf("Extracted %u types\n", nr_types);
#if 0
for (n = 0; n < nr_types; n++) {
struct type *type = type_index[n];
printf("- %*.*s\n",
(int)type->name->size,
(int)type->name->size,
type->name->value);
}
#endif
}
static void parse(void)
{
struct token *cursor;
struct type *type;
type = type_list;
do {
cursor = type->name;
if (cursor[0].token_type != TOKEN_TYPE_NAME ||
cursor[1].token_type != TOKEN_ASSIGNMENT)
abort();
cursor += 2;
type->element = parse_type(&cursor, type[1].name, NULL);
type->element->type_def = type;
if (cursor != type[1].name) {
fprintf(stderr, "%s:%d: Parse error at token '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
} while (type++, !(type->flags & TYPE_STOP_MARKER));
printf("Extracted %u actions\n", nr_actions);
}
static struct element *alloc_elem(struct token *type)
{
struct element *e = calloc(1, sizeof(*e));
if (!e) {
perror(NULL);
exit(1);
}
e->list_next = element_list;
element_list = e;
return e;
}
static struct element *parse_type(struct token **_cursor, struct token *end,
struct token *name)
{
struct element *top, *element;
struct action *action, **ppaction;
struct token *cursor = *_cursor;
struct type **ref;
char *p;
int labelled = 0, implicit = 0;
top = element = alloc_elem(cursor);
element->class = ASN1_UNIV;
element->method = ASN1_PRIM;
element->tag = token_to_tag[cursor->token_type];
element->name = name;
if (cursor->token_type == TOKEN_OPEN_SQUARE) {
cursor++;
if (cursor >= end)
goto overrun_error;
switch (cursor->token_type) {
case DIRECTIVE_UNIVERSAL:
element->class = ASN1_UNIV;
cursor++;
break;
case DIRECTIVE_APPLICATION:
element->class = ASN1_APPL;
cursor++;
break;
case TOKEN_NUMBER:
element->class = ASN1_CONT;
break;
case DIRECTIVE_PRIVATE:
element->class = ASN1_PRIV;
cursor++;
break;
default:
fprintf(stderr, "%s:%d: Unrecognised tag class token '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != TOKEN_NUMBER) {
fprintf(stderr, "%s:%d: Missing tag number '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
element->tag &= ~0x1f;
element->tag |= strtoul(cursor->value, &p, 10);
if (p - cursor->value != cursor->size)
abort();
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != TOKEN_CLOSE_SQUARE) {
fprintf(stderr, "%s:%d: Missing closing square bracket '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
cursor++;
if (cursor >= end)
goto overrun_error;
labelled = 1;
}
if (cursor->token_type == DIRECTIVE_IMPLICIT) {
element->flags |= ELEMENT_IMPLICIT;
implicit = 1;
cursor++;
if (cursor >= end)
goto overrun_error;
} else if (cursor->token_type == DIRECTIVE_EXPLICIT) {
element->flags |= ELEMENT_EXPLICIT;
cursor++;
if (cursor >= end)
goto overrun_error;
}
if (labelled) {
if (!implicit)
element->method |= ASN1_CONS;
element->compound = implicit ? TAG_OVERRIDE : SEQUENCE;
element->children = alloc_elem(cursor);
element = element->children;
element->class = ASN1_UNIV;
element->method = ASN1_PRIM;
element->tag = token_to_tag[cursor->token_type];
element->name = name;
}
element->type = cursor;
switch (cursor->token_type) {
case DIRECTIVE_ANY:
element->compound = ANY;
cursor++;
break;
case DIRECTIVE_NULL:
case DIRECTIVE_BOOLEAN:
case DIRECTIVE_ENUMERATED:
case DIRECTIVE_INTEGER:
element->compound = NOT_COMPOUND;
cursor++;
break;
case DIRECTIVE_EXTERNAL:
element->method = ASN1_CONS;
case DIRECTIVE_BMPString:
case DIRECTIVE_GeneralString:
case DIRECTIVE_GraphicString:
case DIRECTIVE_IA5String:
case DIRECTIVE_ISO646String:
case DIRECTIVE_NumericString:
case DIRECTIVE_PrintableString:
case DIRECTIVE_T61String:
case DIRECTIVE_TeletexString:
case DIRECTIVE_UniversalString:
case DIRECTIVE_UTF8String:
case DIRECTIVE_VideotexString:
case DIRECTIVE_VisibleString:
case DIRECTIVE_ObjectDescriptor:
case DIRECTIVE_GeneralizedTime:
case DIRECTIVE_UTCTime:
element->compound = NOT_COMPOUND;
cursor++;
break;
case DIRECTIVE_BIT:
case DIRECTIVE_OCTET:
element->compound = NOT_COMPOUND;
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != DIRECTIVE_STRING)
goto parse_error;
cursor++;
break;
case DIRECTIVE_OBJECT:
element->compound = NOT_COMPOUND;
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != DIRECTIVE_IDENTIFIER)
goto parse_error;
cursor++;
break;
case TOKEN_TYPE_NAME:
element->compound = TYPE_REF;
ref = bsearch(cursor, type_index, nr_types, sizeof(type_index[0]),
type_finder);
if (!ref) {
fprintf(stderr, "%s:%d: Type '%*.*s' undefined\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
cursor->type = *ref;
(*ref)->ref_count++;
cursor++;
break;
case DIRECTIVE_CHOICE:
element->compound = CHOICE;
cursor++;
element->children = parse_compound(&cursor, end, 1);
break;
case DIRECTIVE_SEQUENCE:
element->compound = SEQUENCE;
element->method = ASN1_CONS;
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type == DIRECTIVE_OF) {
element->compound = SEQUENCE_OF;
cursor++;
if (cursor >= end)
goto overrun_error;
element->children = parse_type(&cursor, end, NULL);
} else {
element->children = parse_compound(&cursor, end, 0);
}
break;
case DIRECTIVE_SET:
element->compound = SET;
element->method = ASN1_CONS;
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type == DIRECTIVE_OF) {
element->compound = SET_OF;
cursor++;
if (cursor >= end)
goto parse_error;
element->children = parse_type(&cursor, end, NULL);
} else {
element->children = parse_compound(&cursor, end, 1);
}
break;
default:
fprintf(stderr, "%s:%d: Token '%*.*s' does not introduce a type\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
if (cursor < end && (cursor->token_type == DIRECTIVE_OPTIONAL ||
cursor->token_type == DIRECTIVE_DEFAULT)
) {
cursor++;
top->flags |= ELEMENT_SKIPPABLE;
}
if (cursor < end && cursor->token_type == TOKEN_OPEN_ACTION) {
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != TOKEN_ELEMENT_NAME) {
fprintf(stderr, "%s:%d: Token '%*.*s' is not an action function name\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
action = malloc(sizeof(struct action) + cursor->size + 1);
if (!action) {
perror(NULL);
exit(1);
}
action->index = 0;
memcpy(action->name, cursor->value, cursor->size);
action->name[cursor->size] = 0;
for (ppaction = &action_list;
*ppaction;
ppaction = &(*ppaction)->next
) {
int cmp = strcmp(action->name, (*ppaction)->name);
if (cmp == 0) {
free(action);
action = *ppaction;
goto found;
}
if (cmp < 0) {
action->next = *ppaction;
*ppaction = action;
nr_actions++;
goto found;
}
}
action->next = NULL;
*ppaction = action;
nr_actions++;
found:
element->action = action;
cursor->action = action;
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != TOKEN_CLOSE_ACTION) {
fprintf(stderr, "%s:%d: Missing close action, got '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
cursor++;
}
*_cursor = cursor;
return top;
parse_error:
fprintf(stderr, "%s:%d: Unexpected token '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
overrun_error:
fprintf(stderr, "%s: Unexpectedly hit EOF\n", filename);
exit(1);
}
static struct element *parse_compound(struct token **_cursor, struct token *end,
int alternates)
{
struct element *children, **child_p = &children, *element;
struct token *cursor = *_cursor, *name;
if (cursor->token_type != TOKEN_OPEN_CURLY) {
fprintf(stderr, "%s:%d: Expected compound to start with brace not '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
cursor++;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type == TOKEN_OPEN_CURLY) {
fprintf(stderr, "%s:%d: Empty compound\n",
filename, cursor->line);
exit(1);
}
for (;;) {
name = NULL;
if (cursor->token_type == TOKEN_ELEMENT_NAME) {
name = cursor;
cursor++;
if (cursor >= end)
goto overrun_error;
}
element = parse_type(&cursor, end, name);
if (alternates)
element->flags |= ELEMENT_SKIPPABLE | ELEMENT_CONDITIONAL;
*child_p = element;
child_p = &element->next;
if (cursor >= end)
goto overrun_error;
if (cursor->token_type != TOKEN_COMMA)
break;
cursor++;
if (cursor >= end)
goto overrun_error;
}
children->flags &= ~ELEMENT_CONDITIONAL;
if (cursor->token_type != TOKEN_CLOSE_CURLY) {
fprintf(stderr, "%s:%d: Expected compound closure, got '%*.*s'\n",
filename, cursor->line,
(int)cursor->size, (int)cursor->size, cursor->value);
exit(1);
}
cursor++;
*_cursor = cursor;
return children;
overrun_error:
fprintf(stderr, "%s: Unexpectedly hit EOF\n", filename);
exit(1);
}
static void render_opcode(FILE *out, const char *fmt, ...)
{
va_list va;
if (out) {
fprintf(out, "\t[%4d] =%*s", nr_entries, render_depth, "");
va_start(va, fmt);
vfprintf(out, fmt, va);
va_end(va);
}
nr_entries++;
}
static void render_more(FILE *out, const char *fmt, ...)
{
va_list va;
if (out) {
va_start(va, fmt);
vfprintf(out, fmt, va);
va_end(va);
}
}
static void render(FILE *out, FILE *hdr)
{
struct element *e;
struct action *action;
struct type *root;
int index;
fprintf(hdr, "/*\n");
fprintf(hdr, " * Automatically generated by asn1_compiler. Do not edit\n");
fprintf(hdr, " *\n");
fprintf(hdr, " * ASN.1 parser for %s\n", grammar_name);
fprintf(hdr, " */\n");
fprintf(hdr, "#include <linux/asn1_decoder.h>\n");
fprintf(hdr, "\n");
fprintf(hdr, "extern const struct asn1_decoder %s_decoder;\n", grammar_name);
if (ferror(hdr)) {
perror(headername);
exit(1);
}
fprintf(out, "/*\n");
fprintf(out, " * Automatically generated by asn1_compiler. Do not edit\n");
fprintf(out, " *\n");
fprintf(out, " * ASN.1 parser for %s\n", grammar_name);
fprintf(out, " */\n");
fprintf(out, "#include <linux/asn1_ber_bytecode.h>\n");
fprintf(out, "#include \"%s-asn1.h\"\n", grammar_name);
fprintf(out, "\n");
if (ferror(out)) {
perror(outputname);
exit(1);
}
fprintf(hdr, "\n");
index = 0;
for (action = action_list; action; action = action->next) {
action->index = index++;
fprintf(hdr,
"extern int %s(void *, size_t, unsigned char,"
" const void *, size_t);\n",
action->name);
}
fprintf(hdr, "\n");
fprintf(out, "enum %s_actions {\n", grammar_name);
for (action = action_list; action; action = action->next)
fprintf(out, "\tACT_%s = %u,\n",
action->name, action->index);
fprintf(out, "\tNR__%s_actions = %u\n", grammar_name, nr_actions);
fprintf(out, "};\n");
fprintf(out, "\n");
fprintf(out, "static const asn1_action_t %s_action_table[NR__%s_actions] = {\n",
grammar_name, grammar_name);
for (action = action_list; action; action = action->next)
fprintf(out, "\t[%4u] = %s,\n", action->index, action->name);
fprintf(out, "};\n");
if (ferror(out)) {
perror(outputname);
exit(1);
}
printf("Pass 1\n");
nr_entries = 0;
root = &type_list[0];
render_element(NULL, root->element, NULL);
render_opcode(NULL, "ASN1_OP_COMPLETE,\n");
render_out_of_line_list(NULL);
for (e = element_list; e; e = e->list_next)
e->flags &= ~ELEMENT_RENDERED;
printf("Pass 2\n");
fprintf(out, "\n");
fprintf(out, "static const unsigned char %s_machine[] = {\n",
grammar_name);
nr_entries = 0;
root = &type_list[0];
render_element(out, root->element, NULL);
render_opcode(out, "ASN1_OP_COMPLETE,\n");
render_out_of_line_list(out);
fprintf(out, "};\n");
fprintf(out, "\n");
fprintf(out, "const struct asn1_decoder %s_decoder = {\n", grammar_name);
fprintf(out, "\t.machine = %s_machine,\n", grammar_name);
fprintf(out, "\t.machlen = sizeof(%s_machine),\n", grammar_name);
fprintf(out, "\t.actions = %s_action_table,\n", grammar_name);
fprintf(out, "};\n");
}
static void render_out_of_line_list(FILE *out)
{
struct element *e, *ce;
const char *act;
int entry;
while ((e = render_list)) {
render_list = e->render_next;
if (!render_list)
render_list_p = &render_list;
render_more(out, "\n");
e->entry_index = entry = nr_entries;
render_depth++;
for (ce = e->children; ce; ce = ce->next)
render_element(out, ce, NULL);
render_depth--;
act = e->action ? "_ACT" : "";
switch (e->compound) {
case SEQUENCE:
render_opcode(out, "ASN1_OP_END_SEQ%s,\n", act);
break;
case SEQUENCE_OF:
render_opcode(out, "ASN1_OP_END_SEQ_OF%s,\n", act);
render_opcode(out, "_jump_target(%u),\n", entry);
break;
case SET:
render_opcode(out, "ASN1_OP_END_SET%s,\n", act);
break;
case SET_OF:
render_opcode(out, "ASN1_OP_END_SET_OF%s,\n", act);
render_opcode(out, "_jump_target(%u),\n", entry);
break;
default:
break;
}
if (e->action)
render_opcode(out, "_action(ACT_%s),\n",
e->action->name);
render_opcode(out, "ASN1_OP_RETURN,\n");
}
}
static void render_element(FILE *out, struct element *e, struct element *tag)
{
struct element *ec;
const char *cond, *act;
int entry, skippable = 0, outofline = 0;
if (e->flags & ELEMENT_SKIPPABLE ||
(tag && tag->flags & ELEMENT_SKIPPABLE))
skippable = 1;
if ((e->type_def && e->type_def->ref_count > 1) ||
skippable)
outofline = 1;
if (e->type_def && out) {
render_more(out, "\t// %*.*s\n",
(int)e->type_def->name->size, (int)e->type_def->name->size,
e->type_def->name->value);
}
cond = (e->flags & ELEMENT_CONDITIONAL ||
(tag && tag->flags & ELEMENT_CONDITIONAL)) ? "COND_" : "";
act = e->action ? "_ACT" : "";
switch (e->compound) {
case ANY:
render_opcode(out, "ASN1_OP_%sMATCH_ANY%s,", cond, act);
if (e->name)
render_more(out, "\t\t// %*.*s",
(int)e->name->size, (int)e->name->size,
e->name->value);
render_more(out, "\n");
goto dont_render_tag;
case TAG_OVERRIDE:
render_element(out, e->children, e);
return;
case SEQUENCE:
case SEQUENCE_OF:
case SET:
case SET_OF:
render_opcode(out, "ASN1_OP_%sMATCH%s%s,",
cond,
outofline ? "_JUMP" : "",
skippable ? "_OR_SKIP" : "");
break;
case CHOICE:
goto dont_render_tag;
case TYPE_REF:
if (e->class == ASN1_UNIV && e->method == ASN1_PRIM && e->tag == 0)
goto dont_render_tag;
default:
render_opcode(out, "ASN1_OP_%sMATCH%s%s,",
cond, act,
skippable ? "_OR_SKIP" : "");
break;
}
if (e->name)
render_more(out, "\t\t// %*.*s",
(int)e->name->size, (int)e->name->size,
e->name->value);
render_more(out, "\n");
if (!tag)
tag = e;
if (tag->class == ASN1_UNIV &&
tag->tag != 14 &&
tag->tag != 15 &&
tag->tag != 31)
render_opcode(out, "_tag(%s, %s, %s),\n",
asn1_classes[tag->class],
asn1_methods[tag->method | e->method],
asn1_universal_tags[tag->tag]);
else
render_opcode(out, "_tagn(%s, %s, %2u),\n",
asn1_classes[tag->class],
asn1_methods[tag->method | e->method],
tag->tag);
tag = NULL;
dont_render_tag:
switch (e->compound) {
case TYPE_REF:
render_element(out, e->type->type->element, tag);
if (e->action)
render_opcode(out, "ASN1_OP_ACT,\n");
break;
case SEQUENCE:
if (outofline) {
render_opcode(out, "_jump_target(%u),", e->entry_index);
if (e->type_def && e->type_def->name)
render_more(out, "\t\t// --> %*.*s",
(int)e->type_def->name->size,
(int)e->type_def->name->size,
e->type_def->name->value);
render_more(out, "\n");
if (!(e->flags & ELEMENT_RENDERED)) {
e->flags |= ELEMENT_RENDERED;
*render_list_p = e;
render_list_p = &e->render_next;
}
return;
} else {
render_depth++;
for (ec = e->children; ec; ec = ec->next)
render_element(out, ec, NULL);
render_depth--;
render_opcode(out, "ASN1_OP_END_SEQ%s,\n", act);
}
break;
case SEQUENCE_OF:
case SET_OF:
if (outofline) {
render_opcode(out, "_jump_target(%u),", e->entry_index);
if (e->type_def && e->type_def->name)
render_more(out, "\t\t// --> %*.*s",
(int)e->type_def->name->size,
(int)e->type_def->name->size,
e->type_def->name->value);
render_more(out, "\n");
if (!(e->flags & ELEMENT_RENDERED)) {
e->flags |= ELEMENT_RENDERED;
*render_list_p = e;
render_list_p = &e->render_next;
}
return;
} else {
entry = nr_entries;
render_depth++;
render_element(out, e->children, NULL);
render_depth--;
if (e->compound == SEQUENCE_OF)
render_opcode(out, "ASN1_OP_END_SEQ_OF%s,\n", act);
else
render_opcode(out, "ASN1_OP_END_SET_OF%s,\n", act);
render_opcode(out, "_jump_target(%u),\n", entry);
}
break;
case SET:
fprintf(stderr, "The ASN.1 SET type is not currently supported.\n");
exit(1);
case CHOICE:
for (ec = e->children; ec; ec = ec->next)
render_element(out, ec, NULL);
if (!skippable)
render_opcode(out, "ASN1_OP_COND_FAIL,\n");
if (e->action)
render_opcode(out, "ASN1_OP_ACT,\n");
break;
default:
break;
}
if (e->action)
render_opcode(out, "_action(ACT_%s),\n", e->action->name);
}
