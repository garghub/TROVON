static jsmntok_t *jsmn_alloc_token(jsmn_parser *parser,
jsmntok_t *tokens, size_t num_tokens)
{
jsmntok_t *tok;
if ((unsigned)parser->toknext >= num_tokens)
return NULL;
tok = &tokens[parser->toknext++];
tok->start = tok->end = -1;
tok->size = 0;
return tok;
}
static void jsmn_fill_token(jsmntok_t *token, jsmntype_t type,
int start, int end)
{
token->type = type;
token->start = start;
token->end = end;
token->size = 0;
}
static jsmnerr_t jsmn_parse_primitive(jsmn_parser *parser, const char *js,
size_t len,
jsmntok_t *tokens, size_t num_tokens)
{
jsmntok_t *token;
int start;
start = parser->pos;
for (; parser->pos < len; parser->pos++) {
switch (js[parser->pos]) {
#ifndef JSMN_STRICT
case ':':
#endif
case '\t':
case '\r':
case '\n':
case ' ':
case ',':
case ']':
case '}':
goto found;
default:
break;
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
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL) {
parser->pos = start;
return JSMN_ERROR_NOMEM;
}
jsmn_fill_token(token, JSMN_PRIMITIVE, start, parser->pos);
parser->pos--;
return JSMN_SUCCESS;
}
static jsmnerr_t jsmn_parse_string(jsmn_parser *parser, const char *js,
size_t len,
jsmntok_t *tokens, size_t num_tokens)
{
jsmntok_t *token;
int start = parser->pos;
parser->pos++;
for (; parser->pos < len; parser->pos++) {
char c = js[parser->pos];
if (c == '\"') {
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL) {
parser->pos = start;
return JSMN_ERROR_NOMEM;
}
jsmn_fill_token(token, JSMN_STRING, start+1,
parser->pos);
return JSMN_SUCCESS;
}
if (c == '\\') {
parser->pos++;
switch (js[parser->pos]) {
case '\"':
case '/':
case '\\':
case 'b':
case 'f':
case 'r':
case 'n':
case 't':
break;
case 'u':
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
jsmnerr_t jsmn_parse(jsmn_parser *parser, const char *js, size_t len,
jsmntok_t *tokens, unsigned int num_tokens)
{
jsmnerr_t r;
int i;
jsmntok_t *token;
for (; parser->pos < len; parser->pos++) {
char c;
jsmntype_t type;
c = js[parser->pos];
switch (c) {
case '{':
case '[':
token = jsmn_alloc_token(parser, tokens, num_tokens);
if (token == NULL)
return JSMN_ERROR_NOMEM;
if (parser->toksuper != -1)
tokens[parser->toksuper].size++;
token->type = (c == '{' ? JSMN_OBJECT : JSMN_ARRAY);
token->start = parser->pos;
parser->toksuper = parser->toknext - 1;
break;
case '}':
case ']':
type = (c == '}' ? JSMN_OBJECT : JSMN_ARRAY);
for (i = parser->toknext - 1; i >= 0; i--) {
token = &tokens[i];
if (token->start != -1 && token->end == -1) {
if (token->type != type)
return JSMN_ERROR_INVAL;
parser->toksuper = -1;
token->end = parser->pos + 1;
break;
}
}
if (i == -1)
return JSMN_ERROR_INVAL;
for (; i >= 0; i--) {
token = &tokens[i];
if (token->start != -1 && token->end == -1) {
parser->toksuper = i;
break;
}
}
break;
case '\"':
r = jsmn_parse_string(parser, js, len, tokens,
num_tokens);
if (r < 0)
return r;
if (parser->toksuper != -1)
tokens[parser->toksuper].size++;
break;
case '\t':
case '\r':
case '\n':
case ':':
case ',':
case ' ':
break;
#ifdef JSMN_STRICT
case '-':
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
case 't':
case 'f':
case 'n':
#else
default:
#endif
r = jsmn_parse_primitive(parser, js, len, tokens,
num_tokens);
if (r < 0)
return r;
if (parser->toksuper != -1)
tokens[parser->toksuper].size++;
break;
#ifdef JSMN_STRICT
default:
return JSMN_ERROR_INVAL;
#endif
}
}
for (i = parser->toknext - 1; i >= 0; i--) {
if (tokens[i].start != -1 && tokens[i].end == -1)
return JSMN_ERROR_PART;
}
return JSMN_SUCCESS;
}
void jsmn_init(jsmn_parser *parser)
{
parser->pos = 0;
parser->toknext = 0;
parser->toksuper = -1;
}
const char *jsmn_strerror(jsmnerr_t err)
{
switch (err) {
case JSMN_ERROR_NOMEM:
return "No enough tokens";
case JSMN_ERROR_INVAL:
return "Invalid character inside JSON string";
case JSMN_ERROR_PART:
return "The string is not a full JSON packet, more bytes expected";
case JSMN_SUCCESS:
return "Success";
default:
return "Unknown json error";
}
}
