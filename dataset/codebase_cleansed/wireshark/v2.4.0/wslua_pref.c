static enum_val_t* get_enum(lua_State *L, int idx)
{
double seq;
const gchar *str1, *str2;
enum_val_t *ret, last = {NULL, NULL, -1};
GArray* es = g_array_new(TRUE,TRUE,sizeof(enum_val_t));
luaL_checktype(L, idx, LUA_TTABLE);
lua_pushnil(L);
while (lua_next(L, idx)) {
enum_val_t e = {NULL, NULL, -1};
luaL_checktype(L, -1, LUA_TTABLE);
lua_pushnil(L);
lua_next(L, -2);
if (! lua_isstring(L,-1)) {
luaL_argerror(L,idx,"First value of an enum table must be string");
g_array_free(es,TRUE);
return NULL;
}
str1 = lua_tostring(L, -1);
lua_pop(L, 1);
lua_next(L, -2);
if (! lua_isstring(L,-1)) {
luaL_argerror(L,idx,"Second value of an enum table must be string");
g_array_free(es,TRUE);
return NULL;
}
str2 = lua_tostring(L, -1);
lua_pop(L, 1);
lua_next(L, -2);
if (! lua_isnumber(L,-1)) {
luaL_argerror(L,idx,"Third value of an enum table must be an integer");
g_array_free(es,TRUE);
return NULL;
}
seq = lua_tonumber(L, -1);
e.name = g_strdup(str1);
e.description = g_strdup(str2);
e.value = (guint32)seq;
g_array_append_val(es,e);
lua_pop(L, 3);
}
g_array_append_val(es,last);
ret = (enum_val_t*)(void*)es->data;
g_array_free(es,FALSE);
return ret;
}
static int new_pref(lua_State* L, pref_type_t type) {
const gchar* label = luaL_optstring(L,1,NULL);
const gchar* descr = luaL_optstring(L,3,"");
Pref pref = (wslua_pref_t *)g_malloc0(sizeof(wslua_pref_t));
pref->label = g_strdup(label);
pref->desc = g_strdup(descr);
pref->type = type;
switch(type) {
case PREF_BOOL: {
gboolean def = wslua_toboolean(L,2);
pref->value.b = def;
break;
}
case PREF_UINT: {
guint32 def = wslua_optgint32(L,2,0);
pref->value.u = def;
break;
}
case PREF_STRING: {
gchar* def = g_strdup(luaL_optstring(L,2,""));
pref->value.s = def;
pref->info.default_s = def;
break;
}
case PREF_ENUM: {
guint32 def = wslua_optgint32(L,2,0);
enum_val_t *enum_val = get_enum(L,4);
gboolean radio = wslua_toboolean(L,5);
pref->value.e = def;
pref->info.enum_info.enumvals = enum_val;
pref->info.enum_info.radio_buttons = radio;
break;
}
case PREF_RANGE: {
range_t *range = get_range(L,2,4);
guint32 max = wslua_optgint32(L,4,0);
pref->value.r = range;
pref->info.max_value = max;
break;
}
case PREF_STATIC_TEXT: {
break;
}
default:
g_assert_not_reached();
break;
}
pushPref(L,pref);
return 1;
}
WSLUA_CONSTRUCTOR Pref_bool(lua_State* L) {
#define WSLUA_ARG_Pref_bool_LABEL 1
#define WSLUA_ARG_Pref_bool_DEFAULT 2
#define WSLUA_ARG_Pref_bool_DESCR 3
return new_pref(L,PREF_BOOL);
}
WSLUA_CONSTRUCTOR Pref_uint(lua_State* L) {
#define WSLUA_ARG_Pref_uint_LABEL 1
#define WSLUA_ARG_Pref_uint_DEFAULT 2
#define WSLUA_ARG_Pref_uint_DESCR 3
return new_pref(L,PREF_UINT);
}
WSLUA_CONSTRUCTOR Pref_string(lua_State* L) {
#define WSLUA_ARG_Pref_string_LABEL 1
#define WSLUA_ARG_Pref_string_DEFAULT 2
#define WSLUA_ARG_Pref_string_DESCR 3
return new_pref(L,PREF_STRING);
}
WSLUA_CONSTRUCTOR Pref_enum(lua_State* L) {
#define WSLUA_ARG_Pref_enum_LABEL 1
#define WSLUA_ARG_Pref_enum_DEFAULT 2
#define WSLUA_ARG_Pref_enum_DESCR 3
#define WSLUA_ARG_Pref_enum_ENUM 4
#define WSLUA_ARG_Pref_enum_RADIO 5
return new_pref(L,PREF_ENUM);
}
WSLUA_CONSTRUCTOR Pref_range(lua_State* L) {
#define WSLUA_ARG_Pref_range_LABEL 1
#define WSLUA_ARG_Pref_range_DEFAULT 2
#define WSLUA_ARG_Pref_range_DESCR 3
#define WSLUA_ARG_Pref_range_MAX 4
return new_pref(L,PREF_RANGE);
}
WSLUA_CONSTRUCTOR Pref_statictext(lua_State* L) {
#define WSLUA_ARG_Pref_statictext_LABEL 1
#define WSLUA_ARG_Pref_statictext_DESCR 2
return new_pref(L,PREF_STATIC_TEXT);
}
static range_t* get_range(lua_State *L, int idx_r, int idx_m)
{
static range_t *ret = NULL;
const gchar *pattern = luaL_checkstring(L, idx_r);
switch (range_convert_str(wmem_epan_scope(), &ret, pattern, wslua_togint32(L, idx_m))) {
case CVT_NO_ERROR:
break;
case CVT_SYNTAX_ERROR:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"syntax error in default range");
return 0;
case CVT_NUMBER_TOO_BIG:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"value too large in default range");
return 0;
default:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"unknown error in default range");
return 0;
}
return ret;
}
static int Pref__gc(lua_State* L) {
Pref pref = toPref(L,1);
if (! pref->name) {
g_free(pref->label);
g_free(pref->desc);
switch (pref->type) {
case PREF_STRING:
g_free(pref->info.default_s);
break;
case PREF_ENUM: {
const enum_val_t *enum_valp = pref->info.enum_info.enumvals;
while (enum_valp->name) {
g_free((char *)enum_valp->name);
g_free((char *)enum_valp->description);
enum_valp++;
}
g_free ((enum_val_t *)pref->info.enum_info.enumvals);
break;
}
default:
break;
}
g_free(pref);
}
return 0;
}
WSLUA_REGISTER Pref_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Pref);
return 0;
}
WSLUA_METAMETHOD Prefs__newindex(lua_State* L) {
#define WSLUA_ARG_Prefs__newindex_NAME 2
#define WSLUA_ARG_Prefs__newindex_PREF 3
Pref prefs_p = checkPrefs(L,1);
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Prefs__newindex_NAME);
Pref pref = checkPref(L,WSLUA_ARG_Prefs__newindex_PREF);
Pref p;
const gchar *c;
if (! prefs_p ) return 0;
if (! pref ) {
WSLUA_ARG_ERROR(Prefs__newindex,PREF,"must be a valid Pref");
return 0;
}
if (pref->name) {
WSLUA_ARG_ERROR(Prefs__newindex,NAME,"cannot change existing preference");
return 0;
}
if (pref->proto) {
WSLUA_ARG_ERROR(Prefs__newindex,PREF,"cannot be added to more than one protocol");
return 0;
}
p = prefs_p;
do {
if ( p->name && g_str_equal(p->name,name) ) {
luaL_error(L,"a preference named %s exists already",name);
return 0;
}
for (c = name; *c != '\0'; c++) {
if (!g_ascii_islower(*c) && !g_ascii_isdigit(*c) && *c != '_' && *c != '.')
{
luaL_error(L,"illegal preference name \"%s\", only lower-case ASCII letters, "
"numbers, underscores and dots may be used", name);
return 0;
}
}
if ( ! p->next) {
p->next = pref;
pref->name = g_strdup(name);
if (!pref->label)
pref->label = g_strdup(name);
if (!prefs_p->proto->prefs_module) {
prefs_p->proto->prefs_module = prefs_register_protocol(prefs_p->proto->hfid,
wslua_prefs_changed);
}
switch(pref->type) {
case PREF_BOOL:
prefs_register_bool_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc,
&(pref->value.b));
break;
case PREF_UINT:
prefs_register_uint_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc,
10,
&(pref->value.u));
break;
case PREF_STRING:
prefs_register_string_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc,
(const char **)(&(pref->value.s)));
g_free(pref->info.default_s);
pref->info.default_s = NULL;
break;
case PREF_ENUM:
prefs_register_enum_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc,
&(pref->value.e),
pref->info.enum_info.enumvals,
pref->info.enum_info.radio_buttons);
break;
case PREF_RANGE:
prefs_register_range_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc,
&(pref->value.r),
pref->info.max_value);
break;
case PREF_STATIC_TEXT:
prefs_register_static_text_preference(prefs_p->proto->prefs_module,
pref->name,
pref->label,
pref->desc);
break;
default:
WSLUA_ERROR(Prefs__newindex,"Unknown Pref type");
break;
}
pref->proto = p->proto;
WSLUA_RETURN(0);
}
} while (( p = p->next ));
luaL_error(L,"this should not happen!");
WSLUA_RETURN(0);
}
WSLUA_METAMETHOD Prefs__index(lua_State* L) {
#define WSLUA_ARG_Prefs__index_NAME 2
Pref prefs_p = checkPrefs(L,1);
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Prefs__index_NAME);
if (! prefs_p ) return 0;
if (!prefs_p->next) {
luaL_error(L,"No preference is registered yet");
return 0;
}
prefs_p = prefs_p->next;
do {
if ( g_str_equal(prefs_p->name,name) ) {
switch (prefs_p->type) {
case PREF_BOOL: lua_pushboolean(L, prefs_p->value.b); break;
case PREF_UINT: lua_pushnumber(L,(lua_Number)prefs_p->value.u); break;
case PREF_STRING: lua_pushstring(L,prefs_p->value.s); break;
case PREF_ENUM: lua_pushnumber(L,(lua_Number)prefs_p->value.e); break;
case PREF_RANGE:
{
char *push_str = range_convert_range(NULL, prefs_p->value.r);
lua_pushstring(L, push_str);
wmem_free(NULL, push_str);
}
break;
default: WSLUA_ERROR(Prefs__index,"Unknown Pref type"); return 0;
}
WSLUA_RETURN(1);
}
} while (( prefs_p = prefs_p->next ));
WSLUA_ARG_ERROR(Prefs__index,NAME,"no preference named like this");
return 0;
}
static int Prefs__gc(lua_State* L _U_) {
return 0;
}
WSLUA_REGISTER Prefs_register(lua_State* L) {
WSLUA_REGISTER_META(Prefs);
return 0;
}
