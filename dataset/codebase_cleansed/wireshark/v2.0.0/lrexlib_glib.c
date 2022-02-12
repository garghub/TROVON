static void minfo_free(TGrgx* ud) {
if (ud->match_info)
g_match_info_free (ud->match_info);
ud->match_info = NULL;
}
static void gerror_free(TGrgx* ud) {
if (ud->error)
g_error_free (ud->error);
ud->error = NULL;
}
static int getSubStartPos(TGrgx* ud, int n) {
int start_pos = -1;
g_match_info_fetch_pos (ud->match_info, n, &start_pos, NULL);
return start_pos;
}
static int getSubEndPos(TGrgx* ud, int n) {
int end_pos = -1;
g_match_info_fetch_pos (ud->match_info, n, NULL, &end_pos);
return end_pos;
}
static int getcflags (lua_State *L, int pos) {
switch (lua_type (L, pos)) {
case LUA_TNONE:
case LUA_TNIL:
return ALG_CFLAGS_DFLT;
case LUA_TNUMBER: {
int res = (int) lua_tointeger (L, pos);
if ((res & ~G_REGEX_COMPILE_MASK) != 0) {
return luaL_error (L, "GLib Regex compile flag is invalid");
}
return res;
}
case LUA_TSTRING: {
const char *s = lua_tostring (L, pos);
int res = 0, ch;
while ((ch = *s++) != '\0') {
if (ch == 'i') res |= G_REGEX_CASELESS;
else if (ch == 'm') res |= G_REGEX_MULTILINE;
else if (ch == 's') res |= G_REGEX_DOTALL;
else if (ch == 'x') res |= G_REGEX_EXTENDED;
else if (ch == 'U') res |= G_REGEX_UNGREEDY;
}
return (int)res;
}
default:
return luaL_typerror (L, pos, "number or string");
}
}
static int check_eflags(lua_State *L, const int idx, const int def) {
int eflags = (int) luaL_optinteger (L, idx, def);
if ((eflags & ~G_REGEX_MATCH_MASK) != 0) {
return luaL_error (L, "GLib Regex match flag is invalid");
}
return eflags;
}
static int generate_error (lua_State *L, const TGrgx *ud, int errcode) {
const char *key = get_flag_key (gregex_error_flags, ud->error->code);
(void) errcode;
if (key)
return luaL_error (L, "error G_REGEX_%s (%s)", key, ud->error->message);
else
return luaL_error (L, "GLib Regex error: %s (code %d)", ud->error->message, ud->error->code);
}
static int compile_regex (lua_State *L, const TArgComp *argC, TGrgx **pud) {
TGrgx *ud;
ud = (TGrgx*)lua_newuserdata (L, sizeof (TGrgx));
memset (ud, 0, sizeof (TGrgx));
lua_pushvalue (L, ALG_ENVIRONINDEX);
lua_setmetatable (L, -2);
ud->pr = g_regex_new (argC->pattern,
(GRegexCompileFlags)(argC->cflags | G_REGEX_RAW), (GRegexMatchFlags)0, &ud->error);
if (pud) *pud = ud;
if (!ud->pr)
return luaL_error (L, "%s (code: %d)", ud->error->message, ud->error->code);
return 1;
}
static void checkarg_dfa_exec (lua_State *L, TArgExec *argE, TGrgx **ud) {
*ud = check_ud (L);
argE->text = luaL_checklstring (L, 2, &argE->textlen);
argE->startoffset = get_startoffset (L, 3, argE->textlen);
argE->eflags = ALG_GETEFLAGS (L, 4);
}
static int Gregex_dfa_exec (lua_State *L)
{
TArgExec argE;
TGrgx *ud;
gboolean res;
checkarg_dfa_exec (L, &argE, &ud);
gerror_free (ud);
res = g_regex_match_all_full (ud->pr, argE.text, (int)argE.textlen,
argE.startoffset, (GRegexMatchFlags)argE.eflags, &ud->match_info, &ud->error);
if (ALG_ISMATCH (res)) {
int i, start_pos, end_pos;
int max = g_match_info_get_match_count (ud->match_info);
g_match_info_fetch_pos (ud->match_info, 0, &start_pos, NULL);
lua_pushinteger (L, start_pos + 1);
lua_newtable (L);
for (i=0; i<max; i++) {
g_match_info_fetch_pos (ud->match_info, i, NULL, &end_pos);
lua_pushinteger (L, end_pos);
lua_rawseti (L, -2, i+1);
}
lua_pushinteger (L, max);
minfo_free (ud);
return 3;
}
else if (g_match_info_is_partial_match(ud->match_info)) {
lua_pushboolean(L,1);
minfo_free (ud);
return 1;
}
else {
minfo_free (ud);
if (ALG_NOMATCH (res))
return lua_pushnil (L), 1;
else
return generate_error (L, ud, 0);
}
}
static int gmatch_exec (TUserdata *ud, TArgExec *argE, int retry) {
int eflags = retry ? (argE->eflags|G_REGEX_MATCH_NOTEMPTY|G_REGEX_MATCH_ANCHORED) : argE->eflags;
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen,
argE->startoffset, (GRegexMatchFlags)eflags, &ud->match_info, &ud->error);
}
static int gmatch_exec (TUserdata *ud, TArgExec *argE) {
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen,
argE->startoffset, (GRegexMatchFlags)argE->eflags, &ud->match_info, &ud->error);
}
static void gmatch_pushsubject (lua_State *L, TArgExec *argE) {
lua_pushlstring (L, argE->text, argE->textlen);
}
static int findmatch_exec (TGrgx *ud, TArgExec *argE) {
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen,
argE->startoffset, (GRegexMatchFlags)argE->eflags, &ud->match_info, &ud->error);
}
static int gsub_exec (TGrgx *ud, TArgExec *argE, int st, int retry) {
int eflags = retry ? (argE->eflags|G_REGEX_MATCH_NOTEMPTY|G_REGEX_MATCH_ANCHORED) : argE->eflags;
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen,
st, (GRegexMatchFlags)eflags, &ud->match_info, &ud->error);
}
static int gsub_exec (TGrgx *ud, TArgExec *argE, int st) {
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen,
st, (GRegexMatchFlags)argE->eflags, &ud->match_info, &ud->error);
}
static int split_exec (TGrgx *ud, TArgExec *argE, int offset) {
minfo_free (ud);
gerror_free (ud);
return g_regex_match_full (ud->pr, argE->text, argE->textlen, offset,
(GRegexMatchFlags)argE->eflags, &ud->match_info, &ud->error);
}
static int Gregex_gc (lua_State *L) {
TGrgx *ud = check_ud (L);
if (ud->freed == 0) {
ud->freed = 1;
if (ud->pr) g_regex_unref (ud->pr);
minfo_free (ud);
gerror_free (ud);
}
return 0;
}
static int Gregex_tostring (lua_State *L) {
TGrgx *ud = check_ud (L);
if (ud->freed == 0)
lua_pushfstring (L, "%s (%p)", REX_TYPENAME, (void*)ud);
else
lua_pushfstring (L, "%s (deleted)", REX_TYPENAME);
return 1;
}
static int Gregex_version (lua_State *L) {
lua_pushfstring (L, "%d.%d.%d", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
return 1;
}
REX_API int REX_OPENLIB (lua_State *L) {
alg_register(L, r_methods, r_functions, "GLib Regex");
return 1;
}
