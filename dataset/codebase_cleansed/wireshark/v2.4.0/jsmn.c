static jsmntok_t *jsmn_alloc_token(jsmn_parser *parser,
jsmntok_t *tokens, size_t num_tokens) {
jsmntok_t *tok;
if (parser->toknext >= num_tokens) {
return NULL;
}
tok = &tokens[parser->toknext++];
tok->start = tok->end = -1;
tok->size = 0;
#ifdef JSMN_PARENT_LINKS
tok->parent = -1;
#endif
return tok;
}
static void jsmn_fill_token(jsmntok_t *token, jsmntype_t type,
int start, int end) {
token->type = type;
token->start = start;
token->end = end;
token->size = 0;
}
static int jsmn_parse_primitive(jsmn_parser *parser, const char *js,
size_t len, jsmntok_t *tokens, size_t num_tokens) {
jsmntok_t *token;
int start;
start = parser->pos;
for (; parser->pos < len && js[parser->pos] != '\0'; parser->pos++) {
switch (js[parser->pos]) {
#ifndef JSMN_STRICT
case ':':
#endif
case '\t' : case '\r' : case '\n' : case ' ' :
case ',' : case ']' : case '}' :
goto found;
}
if (js[parser->pos] < 32 || js[parser->pos] >= 127) {
parser->pos = start;
return JSMN_ERROR_INVAL;
}
}
#ifdef JSMN_STRICT
parser->pos = start;
return JSMN_ERROR_PART;
#endif
found:
if (tokens == NULL) {
parser->pos--;
return 0;
}
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL) {
parser->pos = start;
return JSMN_ERROR_NOMEM;
}
jsmn_fill_token(token, JSMN_PRIMITIVE, start, parser->pos);
#ifdef JSMN_PARENT_LINKS
token->parent = parser->toksuper;
#endif
parser->pos--;
return 0;
}
static int jsmn_parse_string(jsmn_parser *parser, const char *js,
size_t len, jsmntok_t *tokens, size_t num_tokens) {
jsmntok_t *token;
int start = parser->pos;
parser->pos++;
for (; parser->pos < len && js[parser->pos] != '\0'; parser->pos++) {
char c = js[parser->pos];
if (c == '\"') {
if (tokens == NULL) {
return 0;
}
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL) {
parser->pos = start;
return JSMN_ERROR_NOMEM;
}
jsmn_fill_token(token, JSMN_STRING, start+1, parser->pos);
#ifdef JSMN_PARENT_LINKS
token->parent = parser->toksuper;
#endif
return 0;
}
if (c == '\\' && parser->pos + 1 < len) {
int i;
parser->pos++;
switch (js[parser->pos]) {
case '\"': case '/' : case '\\' : case 'b' :
case 'f' : case 'r' : case 'n' : case 't' :
break;
case 'u':
parser->pos++;
for(i = 0; i < 4 && parser->pos < len && js[parser->pos] != '\0'; i++) {
if(!((js[parser->pos] >= 48 && js[parser->pos] <= 57) ||
(js[parser->pos] >= 65 && js[parser->pos] <= 70) ||
(js[parser->pos] >= 97 && js[parser->pos] <= 102))) {
parser->pos = start;
return JSMN_ERROR_INVAL;
}
parser->pos++;
}
parser->pos--;
break;
default:
parser->pos = start;
return JSMN_ERROR_INVAL;
}
}
}
parser->pos = start;
return JSMN_ERROR_PART;
}
int jsmn_parse(jsmn_parser *parser, const char *js, size_t len,
jsmntok_t *tokens, unsigned int num_tokens) {
int r;
int i;
jsmntok_t *token;
int count = parser->toknext;
for (; parser->pos < len && js[parser->pos] != '\0'; parser->pos++) {
char c;
jsmntype_t type;
c = js[parser->pos];
switch (c) {
case '{': case '[':
count++;
if (tokens == NULL) {
break;
}
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL)
return JSMN_ERROR_NOMEM;
if (parser->toksuper != -1) {
tokens[parser->toksuper].size++;
#ifdef JSMN_PARENT_LINKS
token->parent = parser->toksuper;
#endif
}
token->type = (c == '{' ? JSMN_OBJECT : JSMN_ARRAY);
token->start = parser->pos;
parser->toksuper = parser->toknext - 1;
break;
case '}': case ']':
if (tokens == NULL)
break;
type = (c == '}' ? JSMN_OBJECT : JSMN_ARRAY);
#ifdef JSMN_PARENT_LINKS
if (parser->toknext < 1) {
return JSMN_ERROR_INVAL;
}
token = &tokens[parser->toknext - 1];
for (;;) {
if (token->start != -1 && token->end == -1) {
if (token->type != type) {
return JSMN_ERROR_INVAL;
}
token->end = parser->pos + 1;
parser->toksuper = token->parent;
break;
}
if (token->parent == -1) {
break;
}
token = &tokens[token->parent];
}
#else
for (i = parser->toknext - 1; i >= 0; i--) {
token = &tokens[i];
if (token->start != -1 && token->end == -1) {
if (token->type != type) {
return JSMN_ERROR_INVAL;
}
parser->toksuper = -1;
token->end = parser->pos + 1;
break;
}
}
if (i == -1) return JSMN_ERROR_INVAL;
for (; i >= 0; i--) {
token = &tokens[i];
if (token->start != -1 && token->end == -1) {
parser->toksuper = i;
break;
}
}
#endif
break;
case '\"':
r = jsmn_parse_string(parser, js, len, tokens, num_tokens);
if (r < 0) return r;
count++;
if (parser->toksuper != -1 && tokens != NULL)
tokens[parser->toksuper].size++;
break;
case '\t' : case '\r' : case '\n' : case ' ':
break;
case ':':
parser->toksuper = parser->toknext - 1;
break;
case ',':
if (tokens != NULL && parser->toksuper != -1 &&
tokens[parser->toksuper].type != JSMN_ARRAY &&
tokens[parser->toksuper].type != JSMN_OBJECT) {
#ifdef JSMN_PARENT_LINKS
parser->toksuper = tokens[parser->toksuper].parent;
#else
for (i = parser->toknext - 1; i >= 0; i--) {
if (tokens[i].type == JSMN_ARRAY || tokens[i].type == JSMN_OBJECT) {
if (tokens[i].start != -1 && tokens[i].end == -1) {
parser->toksuper = i;
break;
}
}
}
#endif
}
break;
#ifdef JSMN_STRICT
case '-': case '0': case '1' : case '2': case '3' : case '4':
case '5': case '6': case '7' : case '8': case '9':
case 't': case 'f': case 'n' :
if (tokens != NULL && parser->toksuper != -1) {
jsmntok_t *t = &tokens[parser->toksuper];
if (t->type == JSMN_OBJECT ||
(t->type == JSMN_STRING && t->size != 0)) {
return JSMN_ERROR_INVAL;
}
}
#else
default:
#endif
r = jsmn_parse_primitive(parser, js, len, tokens, num_tokens);
if (r < 0) return r;
count++;
if (parser->toksuper != -1 && tokens != NULL)
tokens[parser->toksuper].size++;
break;
#ifdef JSMN_STRICT
default:
return JSMN_ERROR_INVAL;
#endif
}
}
if (tokens != NULL) {
for (i = parser->toknext - 1; i >= 0; i--) {
if (tokens[i].start != -1 && tokens[i].end == -1) {
return JSMN_ERROR_PART;
}
}
}
return count;
}
void jsmn_init(jsmn_parser *parser) {
parser->pos = 0;
parser->toknext = 0;
parser->toksuper = -1;
}
