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
ret = (enum_val_t*)es->data;
g_array_free(es,FALSE);
return ret;
}
static int new_pref(lua_State* L, pref_type_t type) {
const gchar* label = luaL_optstring(L,1,NULL);
const gchar* descr = luaL_optstring(L,3,"");
Pref pref = (wslua_pref_t *)g_malloc(sizeof(wslua_pref_t));
pref->name = NULL;
pref->label = label ? g_strdup(label) : NULL;
pref->desc = g_strdup(descr);
pref->type = type;
pref->next = NULL;
pref->proto = NULL;
switch(type) {
case PREF_BOOL: {
gboolean def = lua_toboolean(L,2);
pref->value.b = def;
break;
}
case PREF_UINT: {
guint32 def = (guint32)luaL_optnumber(L,2,0);
pref->value.u = def;
break;
}
case PREF_STRING: {
gchar* def = g_strdup(luaL_optstring(L,2,""));
pref->value.s = def;
break;
}
case PREF_ENUM: {
guint32 def = (guint32)luaL_optnumber(L,2,0);
enum_val_t *enum_val = get_enum(L,4);
gboolean radio = lua_toboolean(L,5);
pref->value.e = def;
pref->info.enum_info.enumvals = enum_val;
pref->info.enum_info.radio_buttons = radio;
break;
}
case PREF_RANGE: {
range_t *range = get_range(L,2,4);
guint32 max = (guint32)luaL_optnumber(L,4,0);
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
gchar *pattern = g_strdup(luaL_checkstring(L, idx_r));
switch (range_convert_str(&ret, pattern, (guint32)lua_tonumber(L, idx_m))) {
case CVT_NO_ERROR:
break;
case CVT_SYNTAX_ERROR:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"syntax error in default range");
break;
case CVT_NUMBER_TOO_BIG:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"value too large in default range");
break;
default:
WSLUA_ARG_ERROR(Pref_range,DEFAULT,"unknown error in default range");
break;
}
g_free (pattern);
return ret;
}
static int Pref__gc(lua_State* L) {
Pref pref = checkPref(L,1);
if (pref && ! pref->name) {
g_free(pref->label);
g_free(pref->desc);
if (pref->type == PREF_STRING)
g_free((void*)pref->value.s);
g_free(pref);
}
return 0;
}
WSLUA_REGISTER Pref_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Pref);
return 1;
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
if (! name )
WSLUA_ARG_ERROR(Prefs__newindex,NAME,"must be a string");
if (! pref )
WSLUA_ARG_ERROR(Prefs__newindex,PREF,"must be a valid Pref");
if (pref->name)
WSLUA_ARG_ERROR(Prefs__newindex,NAME,"cannot change existing preference");
if (pref->proto)
WSLUA_ARG_ERROR(Prefs__newindex,PREF,"cannot be added to more than one protocol");
p = prefs_p;
do {
if ( p->name && g_str_equal(p->name,name) ) {
luaL_error(L,"a preference named %s exists already",name);
return 0;
}
for (c = name; *c != '\0'; c++) {
if (!isascii((guchar)*c) ||
(!islower((guchar)*c) && !isdigit((guchar)*c) && *c != '_' && *c != '.'))
{
luaL_error(L,"illegal preference name \"%s\", only lower-case ASCII letters, numbers, underscores and dots may be used",name);
return 0;
}
}
if ( ! p->next) {
p->next = pref;
pref->name = g_strdup(name);
if (!pref->label)
pref->label = g_strdup(name);
if (!prefs_p->proto->prefs_module) {
prefs_p->proto->prefs_module = prefs_register_protocol(prefs_p->proto->hfid, wslua_prefs_changed);
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
&(pref->value.s));
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
WSLUA_ERROR(Prefs__newindex,"Unknow Pref type");
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
if (! ( name && prefs_p ) ) return 0;
prefs_p = prefs_p->next;
do {
if ( g_str_equal(prefs_p->name,name) ) {
switch (prefs_p->type) {
case PREF_BOOL: lua_pushboolean(L, prefs_p->value.b); break;
case PREF_UINT: lua_pushnumber(L,(lua_Number)prefs_p->value.u); break;
case PREF_STRING: lua_pushstring(L,prefs_p->value.s); break;
case PREF_ENUM: lua_pushnumber(L,(lua_Number)prefs_p->value.e); break;
case PREF_RANGE: lua_pushstring(L,range_convert_range(prefs_p->value.r)); break;
default: WSLUA_ERROR(Prefs__index,"Unknow Pref type");
}
WSLUA_RETURN(1);
}
} while (( prefs_p = prefs_p->next ));
WSLUA_ARG_ERROR(Prefs__index,NAME,"no preference named like this");
}
static int Prefs__gc(lua_State* L _U_) {
return 0;
}
WSLUA_REGISTER Prefs_register(lua_State* L) {
WSLUA_REGISTER_META(Prefs);
return 1;
}
static enum ftenum get_ftenum(const gchar* type) {
const wslua_ft_types_t* ts;
for (ts = ftenums; ts->str; ts++) {
if ( g_str_equal(ts->str,type) ) {
return ts->id;
}
}
return FT_NONE;
}
static const gchar* ftenum_to_string(enum ftenum ft) {
const wslua_ft_types_t* ts;
for (ts = ftenums; ts->str; ts++) {
if ( ts->id == ft ) {
return ts->str;
}
}
return NULL;
}
static const gchar* base_to_string(unsigned base) {
const struct base_display_string_t* b;
for (b=base_displays;b->str;b++) {
if ( base == b->base)
return b->str;
}
return NULL;
}
static unsigned string_to_base(const gchar* str) {
const struct base_display_string_t* b;
for (b=base_displays;b->str;b++) {
if ( g_str_equal(str,b->str))
return b->base;
}
return BASE_NONE;
}
static value_string* value_string_from_table(lua_State* L, int idx) {
GArray* vs = g_array_new(TRUE,TRUE,sizeof(value_string));
value_string* ret;
if(lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
g_array_free(vs,TRUE);
return NULL;
}
lua_pushnil(L);
while (lua_next(L, idx) != 0) {
value_string v = {0,NULL};
if (! lua_isnumber(L,-2)) {
luaL_argerror(L,idx,"All keys of a table used as value_string must be integers");
g_array_free(vs,TRUE);
return NULL;
}
if (! lua_isstring(L,-1)) {
luaL_argerror(L,idx,"All values of a table used as value_string must be strings");
g_array_free(vs,TRUE);
return NULL;
}
v.value = (guint32)lua_tonumber(L,-2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
ret = (value_string*)vs->data;
g_array_free(vs,FALSE);
return ret;
}
static val64_string* val64_string_from_table(lua_State* L, int idx) {
GArray* vs = g_array_new(TRUE,TRUE,sizeof(val64_string));
val64_string* ret;
if(lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
g_array_free(vs,TRUE);
return NULL;
}
lua_pushnil(L);
while (lua_next(L, idx) != 0) {
val64_string v = {0,NULL};
if (! lua_isnumber(L,-2)) {
luaL_argerror(L,idx,"All keys of a table used as value string must be integers");
g_array_free(vs,TRUE);
return NULL;
}
if (! lua_isstring(L,-1)) {
luaL_argerror(L,idx,"All values of a table used as value string must be strings");
g_array_free(vs,TRUE);
return NULL;
}
v.value = (guint64)lua_tonumber(L, -2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
ret = (val64_string*)vs->data;
g_array_free(vs,FALSE);
return ret;
}
static true_false_string* true_false_string_from_table(lua_State* L, int idx) {
GArray* tfs = g_array_new(TRUE,TRUE,sizeof(true_false_string));
true_false_string* ret;
true_false_string tf = { "True", "False" };
if (lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
g_array_free(tfs,TRUE);
return NULL;
}
lua_pushnil(L);
while (lua_next(L, idx)) {
if (! lua_isnumber(L,-2)) {
luaL_argerror(L,idx,"All keys of a table used as true_false_string must be integers");
g_array_free(tfs,TRUE);
return NULL;
}
if (! lua_isstring(L,-1)) {
luaL_argerror(L,idx,"All values of a table used as true_false_string must be strings");
g_array_free(tfs,TRUE);
return NULL;
}
if ((guint32)lua_tonumber(L,-2) == 1)
tf.true_string = g_strdup(lua_tostring(L,-1));
if ((guint32)lua_tonumber(L,-2) == 2)
tf.false_string = g_strdup(lua_tostring(L,-1));
lua_pop(L, 1);
}
g_array_append_val(tfs,tf);
ret = (true_false_string*)tfs->data;
g_array_free(tfs,FALSE);
return ret;
}
WSLUA_CONSTRUCTOR ProtoField_new(lua_State* L) {
#define WSLUA_ARG_ProtoField_new_NAME 1
#define WSLUA_ARG_ProtoField_new_ABBR 2
#define WSLUA_ARG_ProtoField_new_TYPE 3
#define WSLUA_OPTARG_ProtoField_new_VOIDSTRING 4
#define WSLUA_OPTARG_ProtoField_new_BASE 5
#define WSLUA_OPTARG_ProtoField_new_MASK 6
#define WSLUA_OPTARG_ProtoField_new_DESCR 7
ProtoField f = (wslua_field_t *)g_malloc(sizeof(wslua_field_t));
value_string *vs32 = NULL;
val64_string *vs64 = NULL;
true_false_string *tfs = NULL;
const gchar *blob;
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(luaL_checkstring(L,WSLUA_ARG_ProtoField_new_NAME));
f->abbr = g_strdup(luaL_checkstring(L,WSLUA_ARG_ProtoField_new_ABBR));
f->type = get_ftenum(luaL_checkstring(L,WSLUA_ARG_ProtoField_new_TYPE));
if (f->type == FT_NONE) {
g_free(f->name);
g_free(f->abbr);
g_free(f);
WSLUA_ARG_ERROR(ProtoField_new,TYPE,"invalid ftypes");
}
if (!f->abbr || !f->abbr[0]) {
WSLUA_ARG_ERROR(ProtoField_new,ABBR,"Missing abbrev");
}
if (proto_check_field_name(f->abbr)) {
g_free(f->name);
g_free(f->abbr);
g_free(f);
WSLUA_ARG_ERROR(ProtoField_new,ABBR,"Invalid char in abbrev");
}
if (! lua_isnil(L,WSLUA_OPTARG_ProtoField_new_VOIDSTRING) ) {
if (f->type == FT_BOOLEAN) {
tfs = true_false_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VOIDSTRING);
}
else if (f->type == FT_UINT64 || f->type == FT_INT64) {
vs64 = val64_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VOIDSTRING);
}
else {
vs32 = value_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VOIDSTRING);
}
if (vs32) {
f->vs = VALS(vs32);
} else if (tfs) {
f->vs = TFS(tfs);
} else if (vs64) {
f->vs = VALS(vs64);
} else {
g_free(f->name);
g_free(f->abbr);
g_free(f);
return 0;
}
} else {
f->vs = NULL;
}
f->base = string_to_base(luaL_optstring(L, WSLUA_OPTARG_ProtoField_new_BASE, "BASE_NONE"));
if (vs64) {
f->base |= BASE_VAL64_STRING;
}
f->mask = (guint32)luaL_optnumber(L, WSLUA_OPTARG_ProtoField_new_MASK, 0x0);
blob = luaL_optstring(L,WSLUA_OPTARG_ProtoField_new_DESCR,NULL);
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
WSLUA_RETURN(1);
}
static int ProtoField_integer(lua_State* L, enum ftenum type) {
ProtoField f;
const gchar* abbr = luaL_checkstring(L,1);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = luaL_optint(L, 3, BASE_DEC);
value_string* vs32 = NULL;
val64_string* vs64 = NULL;
guint32 mask = (guint32)luaL_optnumber(L,5,0);
const gchar* blob = luaL_optstring(L,6,NULL);
if (lua_gettop(L) > 3) {
if (type == FT_UINT64 || type == FT_INT64) {
vs64 = val64_string_from_table(L,4);
} else {
vs32 = value_string_from_table(L,4);
}
}
if (type == FT_FRAMENUM) {
if (base != BASE_NONE)
luaL_argerror(L, 3, "ftypes.FRAMENUMs must use base.NONE");
else if (mask)
luaL_argerror(L, 3, "ftypes.FRAMENUMs can not have a bitmask");
} else if (base < BASE_DEC || base > BASE_HEX_DEC) {
luaL_argerror(L, 3, "Base must be either base.DEC, base.HEX, base.OCT,"
" base.DEC_HEX, base.DEC_HEX or base.HEX_DEC");
return 0;
} else if ((base == BASE_HEX || base == BASE_OCT) &&
(type == FT_INT8 || type == FT_INT16 || type == FT_INT24 || type == FT_INT32 || type == FT_INT64)) {
luaL_argerror(L, 3, "This type does not display as hexadecimal");
return 0;
}
if (!abbr || !abbr[0]) {
luaL_argerror(L, 1, "Missing abbrev");
return 0;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L, 1, "Invalid char in abbrev");
return 0;
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbr = g_strdup(abbr);
f->type = type;
f->base = base;
if (vs64) {
f->base |= BASE_VAL64_STRING;
f->vs = VALS(vs64);
} else {
f->vs = VALS(vs32);
}
f->mask = mask;
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
return 1;
}
static int ProtoField_boolean(lua_State* L, enum ftenum type) {
ProtoField f;
const gchar* abbr = luaL_checkstring(L,1);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = luaL_optint(L, 3, BASE_NONE);
true_false_string* tfs = (lua_gettop(L) > 3) ? true_false_string_from_table(L,4) : NULL;
guint32 mask = (guint32)luaL_optnumber(L,5,0);
const gchar* blob = luaL_optstring(L,6,NULL);
if (mask == 0x0 && base != BASE_NONE) {
luaL_argerror(L,2,"Fieldbase (fielddisplay) must be base.NONE"
" if bitmask is zero.");
return 0;
}
if (mask != 0x0 && (base < 1 || base > 64)) {
luaL_argerror(L,2,"Fieldbase (fielddisplay) must be between 1 and 64"
" if bitmask is non-zero.");
return 0;
}
if (!abbr || !abbr[0]) {
luaL_argerror(L,1,"Missing abbrev");
return 0;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L,1,"Invalid char in abbrev");
return 0;
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbr = g_strdup(abbr);
f->type = type;
f->vs = TFS(tfs);
f->base = base;
f->mask = mask;
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
return 1;
}
static int ProtoField_time(lua_State* L,enum ftenum type) {
ProtoField f;
const gchar* abbr = luaL_checkstring(L,1);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = luaL_optint(L,3,ABSOLUTE_TIME_LOCAL);
const gchar* blob = luaL_optstring(L,4,NULL);
if (!abbr || !abbr[0]) {
luaL_argerror(L,1,"Missing abbrev");
return 0;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L,1,"Invalid char in abbrev");
return 0;
}
if (type == FT_ABSOLUTE_TIME) {
if (base < ABSOLUTE_TIME_LOCAL || base > ABSOLUTE_TIME_DOY_UTC) {
luaL_argerror(L, 3, "Base must be either LOCAL, UTC, or DOY_UTC");
return 0;
}
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbr = g_strdup(abbr);
f->type = type;
f->vs = NULL;
f->base = base;
f->mask = 0;
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
return 1;
}
static int ProtoField_other(lua_State* L,enum ftenum type) {
ProtoField f;
const gchar* abbr = luaL_checkstring(L,1);
const gchar* name = luaL_optstring(L,2,abbr);
const gchar* blob = luaL_optstring(L,3,NULL);
if (!abbr || !abbr[0]) {
luaL_argerror(L,1,"Missing abbrev");
return 0;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L,1,"Invalid char in abbrev");
return 0;
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbr = g_strdup(abbr);
f->type = type;
f->vs = NULL;
f->base = BASE_NONE;
f->mask = 0;
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
return 1;
}
WSLUA_METAMETHOD ProtoField__tostring(lua_State* L) {
ProtoField f = checkProtoField(L,1);
gchar* s = (gchar *)ep_strdup_printf("ProtoField(%i): %s %s %s %s %p %.8x %s",f->hfid,f->name,f->abbr,ftenum_to_string(f->type),base_to_string(f->base),f->vs,f->mask,f->blob);
lua_pushstring(L,s);
return 1;
}
static int ProtoField__gc(lua_State* L) {
ProtoField f = checkProtoField(L,1);
if (!f) {
luaL_argerror(L,1,"BUG: ProtoField_gc called for something not ProtoField");
} else if (f->hfid == -2) {
g_free(f->name);
g_free(f->abbr);
g_free(f->blob);
g_free(f);
}
return 0;
}
int ProtoField_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ProtoField);
return 1;
}
WSLUA_CONSTRUCTOR Proto_new(lua_State* L) {
#define WSLUA_ARG_Proto_new_NAME 1
#define WSLUA_ARG_Proto_new_DESC 2
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Proto_new_NAME);
const gchar* desc = luaL_checkstring(L,WSLUA_ARG_Proto_new_DESC);
if ( name ) {
gchar* loname_a;
int proto_id;
loname_a = g_ascii_strdown(name, -1);
proto_id = proto_get_id_by_filter_name(loname_a);
g_free(loname_a);
if ( proto_id > 0 ) {
WSLUA_ARG_ERROR(Proto_new,NAME,"there cannot be two protocols with the same name");
} else {
Proto proto = (wslua_proto_t *)g_malloc(sizeof(wslua_proto_t));
gchar* loname = g_ascii_strdown(name, -1);
gchar* hiname = g_ascii_strup(name, -1);
proto->name = hiname;
proto->desc = g_strdup(desc);
proto->hfid = proto_register_protocol(proto->desc,hiname,loname);
proto->ett = -1;
proto->is_postdissector = FALSE;
lua_newtable (L);
proto->fields = luaL_ref(L, LUA_REGISTRYINDEX);
proto->prefs.name = NULL;
proto->prefs.label = NULL;
proto->prefs.desc = NULL;
proto->prefs.value.u = 0;
proto->prefs.next = NULL;
proto->prefs.proto = proto;
proto->prefs_module = NULL;
proto->handle = NULL;
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
lua_pushstring(L,loname);
pushProto(L,proto);
lua_settable(L, -3);
pushProto(L,proto);
WSLUA_RETURN(1);
}
} else
WSLUA_ARG_ERROR(Proto_new,NAME,"must be a string");
return 0;
}
static int Proto_tostring(lua_State* L) {
Proto proto = checkProto(L,1);
gchar* s;
if (!proto) return 0;
s = ep_strdup_printf("Proto: %s",proto->name);
lua_pushstring(L,s);
return 1;
}
WSLUA_FUNCTION wslua_register_postdissector(lua_State* L) {
#define WSLUA_ARG_register_postdissector_PROTO 1
Proto proto = checkProto(L,WSLUA_ARG_register_postdissector_PROTO);
if (!proto) return 0;
if(!proto->is_postdissector) {
if (! proto->handle) {
proto->handle = new_create_dissector_handle(dissect_lua, proto->hfid);
}
register_postdissector(proto->handle);
} else {
luaL_argerror(L,1,"this protocol is already registered as postdissector");
}
return 0;
}
static int Proto_get_dissector(lua_State* L) {
Proto proto = toProto(L,1);
if (proto->handle) {
pushDissector(L,proto->handle);
return 1;
} else {
luaL_error(L,"The protocol hasn't been registered yet");
return 0;
}
}
static int Proto_set_dissector(lua_State* L) {
Proto proto = toProto(L,1);
if (lua_isfunction(L,3)) {
gchar* loname = g_ascii_strdown(proto->name, -1);
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_dissectors_table_ref);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_replace(L, 2);
lua_settable(L,1);
proto->handle = new_create_dissector_handle(dissect_lua, proto->hfid);
new_register_dissector(loname, dissect_lua, proto->hfid);
return 0;
} else {
luaL_argerror(L,3,"The dissector of a protocol must be a function");
return 0;
}
}
static int Proto_get_prefs(lua_State* L) {
Proto proto = toProto(L,1);
pushPrefs(L,&proto->prefs);
return 1;
}
static int Proto_set_prefs_changed(lua_State* L) {
Proto proto = toProto(L,1);
if (lua_isfunction(L,3)) {
lua_getglobal(L, WSLUA_PREFS_CHANGED);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_replace(L, 2);
lua_settable(L,1);
} else {
luaL_argerror(L,3,"The prefs of a protocol must be a function");
}
return 0;
}
static int Proto_set_init(lua_State* L) {
Proto proto = toProto(L,1);
if (lua_isfunction(L,3)) {
lua_getglobal(L, WSLUA_INIT_ROUTINES);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_replace(L, 2);
lua_settable(L,1);
return 0;
} else {
luaL_argerror(L,3,"The initializer of a protocol must be a function");
return 0;
}
}
static int Proto_get_name(lua_State* L) {
Proto proto = toProto(L,1);
lua_pushstring(L,proto->name);
return 1;
}
static int Proto_get_description(lua_State* L) {
Proto proto = toProto(L,1);
lua_pushstring(L,proto->desc);
return 1;
}
static int Proto_get_fields(lua_State* L) {
Proto proto = toProto(L,1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
return 1;
}
void wslua_print_stack(char* s, lua_State* L) {
int i;
for (i=1;i<=lua_gettop(L);i++) {
printf("%s-%i: %s\n",s,i,lua_typename (L,lua_type(L, i)));
}
printf("\n");
}
static int Proto_set_fields(lua_State* L) {
Proto proto = toProto(L,1);
#define FIELDS_TABLE 2
#define NEW_TABLE 3
#define NEW_FIELD 3
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
lua_replace(L,FIELDS_TABLE);
if( lua_istable(L,NEW_TABLE)) {
for (lua_pushnil(L); lua_next(L, NEW_TABLE); ) {
if (isProtoField(L,5)) {
luaL_ref(L,FIELDS_TABLE);
} else if (! lua_isnil(L,5) ) {
return luaL_error(L,"only ProtoFields should be in the table");
}
}
} else if (isProtoField(L,NEW_FIELD)){
lua_pushvalue(L, NEW_FIELD);
luaL_ref(L,FIELDS_TABLE);
} else {
return luaL_error(L,"either a ProtoField or an array of protofields");
}
lua_pushvalue(L, 3);
return 1;
}
static int Proto_index(lua_State* L) {
Proto proto = checkProto(L,1);
const gchar* name = luaL_checkstring(L,2);
const proto_actions_t* pa;
if (! (proto && name) ) return 0;
for (pa = proto_actions; pa->name; pa++) {
if ( g_str_equal(name,pa->name) ) {
if (pa->get) {
return pa->get(L);
} else {
luaL_error(L,"You cannot get the `%s' attribute of a protocol",name);
return 0;
}
}
}
luaL_error(L,"A protocol doesn't have a `%s' attribute",name);
return 0;
}
static int Proto_newindex(lua_State* L) {
Proto proto = checkProto(L,1);
const gchar* name = luaL_checkstring(L,2);
const proto_actions_t* pa;
if (! (proto && name) ) return 0;
for (pa = proto_actions; pa->name; pa++) {
if ( g_str_equal(name,pa->name) ) {
if (pa->set) {
return pa->set(L);
} else {
luaL_error(L,"You cannot set the `%s' attribute of a protocol",name);
return 0;
}
}
}
luaL_error(L,"A protocol doesn't have a `%s' attribute",name);
return 0;
}
static int Proto__gc(lua_State* L _U_) {
return 0;
}
int Proto_register(lua_State* L) {
WSLUA_REGISTER_META(Proto);
lua_newtable(L);
protocols_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_pushcfunction(L, Proto_new);
lua_setglobal(L, "Proto");
return 1;
}
int Proto_commit(lua_State* L) {
lua_settop(L,0);
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
for (lua_pushnil(L); lua_next(L, 1); lua_pop(L, 2)) {
GArray* hfa = g_array_new(TRUE,TRUE,sizeof(hf_register_info));
GArray* etta = g_array_new(TRUE,TRUE,sizeof(gint*));
Proto proto;
proto = checkProto(L,3);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
for (lua_pushnil(L); lua_next(L, 4); lua_pop(L, 1)) {
ProtoField f = checkProtoField(L,6);
hf_register_info hfri = { &(f->hfid), {f->name,f->abbr,f->type,f->base,VALS(f->vs),f->mask,f->blob,HFILL}};
gint* ettp = &(f->ett);
if (f->hfid != -2) {
return luaL_error(L,"fields can be registered only once");
}
f->hfid = -1;
g_array_append_val(hfa,hfri);
g_array_append_val(etta,ettp);
}
proto_register_field_array(proto->hfid,(hf_register_info*)hfa->data,hfa->len);
proto_register_subtree_array((gint**)etta->data,etta->len);
g_array_free(hfa,FALSE);
g_array_free(etta,FALSE);
}
return 0;
}
WSLUA_CONSTRUCTOR Dissector_get (lua_State *L) {
#define WSLUA_ARG_Dissector_get_NAME 1
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Dissector_get_NAME);
Dissector d;
if (!name)
WSLUA_ARG_ERROR(Dissector_get,NAME,"must be a string");
if ((d = find_dissector(name))) {
pushDissector(L, d);
WSLUA_RETURN(1);
} else
WSLUA_ARG_ERROR(Dissector_get,NAME,"No such dissector");
}
WSLUA_METHOD Dissector_call(lua_State* L) {
#define WSLUA_ARG_Dissector_call_TVB 2
#define WSLUA_ARG_Dissector_call_PINFO 3
#define WSLUA_ARG_Dissector_call_TREE 4
Dissector d = checkDissector(L,1);
Tvb tvb = checkTvb(L,WSLUA_ARG_Dissector_call_TVB);
Pinfo pinfo = checkPinfo(L,WSLUA_ARG_Dissector_call_PINFO);
TreeItem ti = checkTreeItem(L,WSLUA_ARG_Dissector_call_TREE);
const char *volatile error = NULL;
if (! ( d && tvb && pinfo) ) return 0;
TRY {
call_dissector(d, tvb->ws_tvb, pinfo->ws_pinfo, ti->tree);
} CATCH_NONFATAL_ERRORS {
show_exception(tvb->ws_tvb, pinfo->ws_pinfo, ti->tree, EXCEPT_CODE, GET_MESSAGE);
error = "Malformed frame";
} ENDTRY;
if (error) { WSLUA_ERROR(Dissector_call,error); }
return 0;
}
WSLUA_METAMETHOD Dissector__tostring(lua_State* L) {
Dissector d = checkDissector(L,1);
if (!d) return 0;
lua_pushstring(L,dissector_handle_get_short_name(d));
WSLUA_RETURN(1);
}
static int Dissector__gc(lua_State* L _U_) {
return 0;
}
int Dissector_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Dissector);
return 1;
}
WSLUA_CONSTRUCTOR DissectorTable_new (lua_State *L) {
#define WSLUA_ARG_DissectorTable_new_TABLENAME 1
#define WSLUA_OPTARG_DissectorTable_new_UINAME 2
#define WSLUA_OPTARG_DissectorTable_new_TYPE 3
#define WSLUA_OPTARG_DissectorTable_new_BASE 4
const gchar* name = (const gchar*)luaL_checkstring(L,WSLUA_ARG_DissectorTable_new_TABLENAME);
const gchar* ui_name = (const gchar*)luaL_optstring(L,WSLUA_OPTARG_DissectorTable_new_UINAME,name);
enum ftenum type = (enum ftenum)luaL_optint(L,WSLUA_OPTARG_DissectorTable_new_TYPE,FT_UINT32);
unsigned base = (unsigned)luaL_optint(L,WSLUA_OPTARG_DissectorTable_new_BASE,BASE_DEC);
if(!(name && ui_name)) return 0;
switch(type) {
case FT_STRING:
base = BASE_NONE;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
{
DissectorTable dt = (DissectorTable)g_malloc(sizeof(struct _wslua_distbl_t));
name = g_strdup(name);
ui_name = g_strdup(ui_name);
dt->table = register_dissector_table(name, ui_name, type, base);
dt->name = name;
pushDissectorTable(L, dt);
}
WSLUA_RETURN(1);
default:
WSLUA_OPTARG_ERROR(DissectorTable_new,TYPE,"must be ftypes.UINT{8,16,24,32} or ftypes.STRING");
}
return 0;
}
WSLUA_CONSTRUCTOR DissectorTable_get (lua_State *L) {
#define WSLUA_ARG_DissectorTable_get_TABLENAME 1
const gchar* name = luaL_checkstring(L,WSLUA_ARG_DissectorTable_get_TABLENAME);
dissector_table_t table;
if(!name) return 0;
table = find_dissector_table(name);
if (table) {
DissectorTable dt = (DissectorTable)g_malloc(sizeof(struct _wslua_distbl_t));
dt->table = table;
dt->name = g_strdup(name);
pushDissectorTable(L, dt);
WSLUA_RETURN(1);
} else
WSLUA_ARG_ERROR(DissectorTable_get,TABLENAME,"no such dissector_table");
}
WSLUA_METHOD DissectorTable_add (lua_State *L) {
#define WSLUA_ARG_DissectorTable_add_PATTERN 2
#define WSLUA_ARG_DissectorTable_add_DISSECTOR 3
DissectorTable dt = checkDissectorTable(L,1);
ftenum_t type;
Dissector handle;
if (!dt) return 0;
if( isProto(L,WSLUA_ARG_DissectorTable_add_DISSECTOR) ) {
Proto p;
p = toProto(L,WSLUA_ARG_DissectorTable_add_DISSECTOR);
handle = p->handle;
if (! handle)
WSLUA_ARG_ERROR(DissectorTable_add,DISSECTOR,"a Protocol that does not have a dissector cannot be added to a table");
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_add_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_add_DISSECTOR);
} else
WSLUA_ARG_ERROR(DissectorTable_add,DISSECTOR,"must be either Proto or Dissector");
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_add_PATTERN));
dissector_add_string(dt->name, pattern,handle);
g_free (pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_add_PATTERN)) {
int port = luaL_checkint(L, WSLUA_ARG_DissectorTable_add_PATTERN);
dissector_add_uint(dt->name, port, handle);
} else {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_add_PATTERN));
range_t *range;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR)
dissector_add_uint_range(dt->name, range, handle);
else
WSLUA_ARG_ERROR(DissectorTable_add,PATTERN,"invalid integer or range");
g_free (pattern);
}
} else {
luaL_error(L,"Strange type %d for a DissectorTable",type);
}
return 0;
}
WSLUA_METHOD DissectorTable_set (lua_State *L) {
#define WSLUA_ARG_DissectorTable_set_PATTERN 2
#define WSLUA_ARG_DissectorTable_set_DISSECTOR 3
DissectorTable dt = checkDissectorTable(L,1);
ftenum_t type;
Dissector handle;
if (!dt) return 0;
if( isProto(L,WSLUA_ARG_DissectorTable_set_DISSECTOR) ) {
Proto p;
p = toProto(L,WSLUA_ARG_DissectorTable_set_DISSECTOR);
handle = p->handle;
if (! handle)
WSLUA_ARG_ERROR(DissectorTable_set,DISSECTOR,"a Protocol that does not have a dissector cannot be set to a table");
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_set_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_set_DISSECTOR);
} else
WSLUA_ARG_ERROR(DissectorTable_set,DISSECTOR,"must be either Proto or Dissector");
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_set_PATTERN));
dissector_delete_all(dt->name, handle);
dissector_add_string(dt->name, pattern,handle);
g_free (pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_set_PATTERN)) {
int port = luaL_checkint(L, WSLUA_ARG_DissectorTable_set_PATTERN);
dissector_delete_all(dt->name, handle);
dissector_add_uint(dt->name, port, handle);
} else {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_set_PATTERN));
range_t *range;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR) {
dissector_delete_all(dt->name, handle);
dissector_add_uint_range(dt->name, range, handle);
} else {
WSLUA_ARG_ERROR(DissectorTable_set,PATTERN,"invalid integer or range");
}
g_free (pattern);
}
} else {
luaL_error(L,"Strange type %d for a DissectorTable",type);
}
return 0;
}
WSLUA_METHOD DissectorTable_remove (lua_State *L) {
#define WSLUA_ARG_DissectorTable_remove_PATTERN 2
#define WSLUA_ARG_DissectorTable_remove_DISSECTOR 3
DissectorTable dt = checkDissectorTable(L,1);
ftenum_t type;
Dissector handle;
if (!dt) return 0;
if( isProto(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR) ) {
Proto p;
p = toProto(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR);
handle = p->handle;
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR);
} else
WSLUA_ARG_ERROR(DissectorTable_remove,DISSECTOR,"must be either Proto or Dissector");
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_remove_PATTERN));
dissector_delete_string(dt->name, pattern,handle);
g_free (pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_remove_PATTERN)) {
int port = luaL_checkint(L, WSLUA_ARG_DissectorTable_remove_PATTERN);
dissector_delete_uint(dt->name, port, handle);
} else {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_remove_PATTERN));
range_t *range;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR)
dissector_delete_uint_range(dt->name, range, handle);
else
WSLUA_ARG_ERROR(DissectorTable_remove,PATTERN,"invalid integer or range");
g_free (pattern);
}
}
return 0;
}
WSLUA_METHOD DissectorTable_remove_all (lua_State *L) {
#define WSLUA_ARG_DissectorTable_remove_all_DISSECTOR 2
DissectorTable dt = checkDissectorTable(L,1);
Dissector handle;
if (!dt) return 0;
if( isProto(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR) ) {
Proto p;
p = toProto(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR);
handle = p->handle;
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR);
} else
WSLUA_ARG_ERROR(DissectorTable_remove_all,DISSECTOR,"must be either Proto or Dissector");
dissector_delete_all (dt->name, handle);
return 0;
}
WSLUA_METHOD DissectorTable_try (lua_State *L) {
#define WSLUA_ARG_DissectorTable_try_PATTERN 2
#define WSLUA_ARG_DissectorTable_try_TVB 3
#define WSLUA_ARG_DissectorTable_try_PINFO 4
#define WSLUA_ARG_DissectorTable_try_TREE 5
DissectorTable dt = checkDissectorTable(L,1);
Tvb tvb = checkTvb(L,WSLUA_ARG_DissectorTable_try_TVB);
Pinfo pinfo = checkPinfo(L,WSLUA_ARG_DissectorTable_try_PINFO);
TreeItem ti = checkTreeItem(L,WSLUA_ARG_DissectorTable_try_TREE);
ftenum_t type;
gboolean handled = FALSE;
const gchar *volatile error = NULL;
if (! (dt && tvb && tvb->ws_tvb && pinfo && ti) ) return 0;
type = get_dissector_table_selector_type(dt->name);
TRY {
if (type == FT_STRING) {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_try_PATTERN);
if (!pattern)
handled = TRUE;
else if (dissector_try_string(dt->table,pattern,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree))
handled = TRUE;
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
int port = luaL_checkint(L, WSLUA_ARG_DissectorTable_try_PATTERN);
if (dissector_try_uint(dt->table,port,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree))
handled = TRUE;
} else {
luaL_error(L,"No such type of dissector_table");
}
if (!handled)
call_dissector(lua_data_handle,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree);
} CATCH_NONFATAL_ERRORS {
show_exception(tvb->ws_tvb, pinfo->ws_pinfo, ti->tree, EXCEPT_CODE, GET_MESSAGE);
error = "Malformed frame";
} ENDTRY;
if (error) { WSLUA_ERROR(DissectorTable_try,error); }
return 0;
}
WSLUA_METHOD DissectorTable_get_dissector (lua_State *L) {
#define WSLUA_ARG_DissectorTable_try_PATTERN 2
DissectorTable dt = checkDissectorTable(L,1);
ftenum_t type;
dissector_handle_t handle = lua_data_handle;
if (!dt) return 0;
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_try_PATTERN);
if (!pattern) WSLUA_ARG_ERROR(DissectorTable_try,PATTERN,"must be a string");
handle = dissector_get_string_handle(dt->table,pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
int port = luaL_checkint(L, WSLUA_ARG_DissectorTable_try_PATTERN);
handle = dissector_get_uint_handle(dt->table,port);
}
if (handle) {
pushDissector(L,handle);
WSLUA_RETURN(1);
} else {
lua_pushnil(L);
WSLUA_RETURN(1);
}
}
WSLUA_METAMETHOD DissectorTable__tostring(lua_State* L) {
DissectorTable dt = checkDissectorTable(L,1);
GString* s;
ftenum_t type;
if (!dt) return 0;
type = get_dissector_table_selector_type(dt->name);
s = g_string_new("DissectorTable ");
switch(type) {
case FT_STRING:
{
g_string_append_printf(s,"%s String:\n",dt->name);
break;
}
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
{
int base = get_dissector_table_base(dt->name);
g_string_append_printf(s,"%s Integer(%i):\n",dt->name,base);
break;
}
default:
luaL_error(L,"Strange table type");
}
lua_pushstring(L,s->str);
g_string_free(s,TRUE);
WSLUA_RETURN(1);
}
static int DissectorTable__gc(lua_State* L _U_) {
return 0;
}
int DissectorTable_register(lua_State* L) {
WSLUA_REGISTER_CLASS(DissectorTable);
return 1;
}
