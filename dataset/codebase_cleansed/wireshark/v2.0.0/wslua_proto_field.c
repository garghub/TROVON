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
const struct field_display_string_t* b;
for (b=base_displays;b->str;b++) {
if ( base == b->base)
return b->str;
}
return NULL;
}
static unsigned string_to_base(const gchar* str) {
const struct field_display_string_t* b;
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
v.value = wslua_toguint32(L,-2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
ret = (value_string*)(void*)vs->data;
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
v.value = wslua_toguint64(L, -2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
ret = (val64_string*)(void*)vs->data;
g_array_free(vs,FALSE);
return ret;
}
static true_false_string* true_false_string_from_table(lua_State* L, int idx) {
GArray* tfs = g_array_new(TRUE,TRUE,sizeof(true_false_string));
true_false_string* ret;
true_false_string tf = { g_strdup("True"), g_strdup("False") };
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
if (lua_tointeger(L,-2) == 1) {
g_free((gchar *)tf.true_string);
tf.true_string = g_strdup(lua_tostring(L,-1));
}
if (lua_tointeger(L,-2) == 2) {
g_free((gchar *)tf.false_string);
tf.false_string = g_strdup(lua_tostring(L,-1));
}
lua_pop(L, 1);
}
g_array_append_val(tfs,tf);
ret = (true_false_string*)(void*)tfs->data;
g_array_free(tfs,FALSE);
return ret;
}
static const gchar* check_field_name(lua_State* L, const int abbr_idx, const enum ftenum type) {
const gchar* abbr = luaL_checkstring(L,abbr_idx);
const header_field_info* hfinfo = NULL;
if (!abbr[0]) {
luaL_argerror(L, abbr_idx, "Empty field name abbreviation");
return NULL;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L, abbr_idx, "Invalid char in abbrev");
return NULL;
}
hfinfo = proto_registrar_get_byname(abbr);
if (hfinfo && !ftype_similar_types(type, hfinfo->type)) {
luaL_argerror(L, abbr_idx, "A field of an incompatible ftype with this abbrev already exists");
return NULL;
}
return abbr;
}
WSLUA_CONSTRUCTOR ProtoField_new(lua_State* L) {
#define WSLUA_ARG_ProtoField_new_NAME 1
#define WSLUA_ARG_ProtoField_new_ABBR 2
#define WSLUA_ARG_ProtoField_new_TYPE 3
#define WSLUA_OPTARG_ProtoField_new_VALUESTRING 4
#define WSLUA_OPTARG_ProtoField_new_BASE 5
#define WSLUA_OPTARG_ProtoField_new_MASK 6
#define WSLUA_OPTARG_ProtoField_new_DESCR 7
ProtoField f;
int nargs = lua_gettop(L);
const gchar* name = luaL_checkstring(L,WSLUA_ARG_ProtoField_new_NAME);
const gchar* abbr = NULL;
enum ftenum type;
enum ft_framenum_type framenum_type = FT_FRAMENUM_NONE;
value_string *vs32 = NULL;
val64_string *vs64 = NULL;
true_false_string *tfs = NULL;
unsigned base;
guint32 mask = wslua_optguint32(L, WSLUA_OPTARG_ProtoField_new_MASK, 0x0);
const gchar *blob = luaL_optstring(L,WSLUA_OPTARG_ProtoField_new_DESCR,NULL);
if (lua_isnumber(L,WSLUA_ARG_ProtoField_new_TYPE)) {
type = (enum ftenum)luaL_checkinteger(L,WSLUA_ARG_ProtoField_new_TYPE);
} else {
type = get_ftenum(luaL_checkstring(L,WSLUA_ARG_ProtoField_new_TYPE));
}
abbr = check_field_name(L,WSLUA_ARG_ProtoField_new_ABBR,type);
if (lua_isnumber(L, WSLUA_OPTARG_ProtoField_new_BASE)) {
base = (unsigned)luaL_optinteger(L, WSLUA_OPTARG_ProtoField_new_BASE, BASE_NONE);
} else {
base = string_to_base(luaL_optstring(L, WSLUA_OPTARG_ProtoField_new_BASE, "BASE_NONE"));
}
switch (type) {
case FT_FRAMENUM:
if (base != BASE_NONE) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"FRAMENUM must use base.NONE");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"FRAMENUM can not have a bitmask");
return 0;
}
if (nargs >= WSLUA_OPTARG_ProtoField_new_VALUESTRING && !lua_isnil(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING)) {
framenum_type = (enum ft_framenum_type) luaL_checkinteger(L, 4);
if (framenum_type >= FT_FRAMENUM_NUM_TYPES) {
WSLUA_OPTARG_ERROR(ProtoField_new,VALUESTRING,"Invalid frametype");
return 0;
}
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
if (base == BASE_NONE) {
base = BASE_DEC;
} else if (base < BASE_DEC || base > BASE_HEX_DEC) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be either base.DEC, base.HEX, base.OCT,"
" base.DEC_HEX, base.DEC_HEX or base.HEX_DEC");
return 0;
}
if ((base == BASE_HEX || base == BASE_OCT) &&
(type == FT_INT8 || type == FT_INT16 || type == FT_INT24 || type == FT_INT32 || type == FT_INT64))
{
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"This type does not display as hexadecimal");
return 0;
}
if (nargs >= WSLUA_OPTARG_ProtoField_new_VALUESTRING && !lua_isnil(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING)) {
if (type == FT_UINT64 || type == FT_INT64) {
vs64 = val64_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING);
} else {
vs32 = value_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING);
}
}
break;
case FT_BOOLEAN:
if (mask == 0x0 && base != BASE_NONE) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be base.NONE if bitmask is zero.");
return 0;
}
if (mask != 0x0 && (base < 1 || base > 64)) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be between 1 and 64 if bitmask is non-zero.");
return 0;
}
if (nargs >= WSLUA_OPTARG_ProtoField_new_VALUESTRING && !lua_isnil(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING)) {
tfs = true_false_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING);
}
break;
case FT_ABSOLUTE_TIME:
if (base == BASE_NONE) {
base = ABSOLUTE_TIME_LOCAL;
} else if (base < ABSOLUTE_TIME_LOCAL || base > ABSOLUTE_TIME_DOY_UTC) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be either LOCAL, UTC, or DOY_UTC");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"ABSOLUTE_TIME can not have a bitmask");
return 0;
}
break;
case FT_NONE:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_ETHER:
case FT_FLOAT:
case FT_DOUBLE:
case FT_RELATIVE_TIME:
case FT_STRING:
case FT_STRINGZ:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_GUID:
case FT_OID:
case FT_PROTOCOL:
case FT_SYSTEM_ID:
case FT_REL_OID:
case FT_EUI64:
case FT_VINES:
case FT_FCWWN:
if (base != BASE_NONE) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be base.NONE");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"This type can not have a bitmask");
return 0;
}
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_UINT_STRING:
case FT_PCRE:
case FT_AX25:
case FT_STRINGZPAD:
default:
WSLUA_ARG_ERROR(ProtoField_new,TYPE,"Invalid ProtoField field type");
break;
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
f->type = type;
f->base = base;
if (tfs) {
f->vs = TFS(tfs);
} else if (vs32) {
f->vs = VALS(vs32);
} else if (vs64) {
f->base |= BASE_VAL64_STRING;
f->vs = VALS(vs64);
} else if (framenum_type) {
f->vs = FRAMENUM_TYPE(framenum_type);
} else {
f->vs = NULL;
}
f->mask = mask;
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
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned default_base = (type == FT_FRAMENUM) ? BASE_NONE : BASE_DEC;
unsigned base = (unsigned)luaL_optinteger(L, 3, default_base);
enum ft_framenum_type framenum_type = FT_FRAMENUM_NONE;
value_string* vs32 = NULL;
val64_string* vs64 = NULL;
guint32 mask = wslua_optguint32(L,5,0);
const gchar* blob = luaL_optstring(L,6,NULL);
if (lua_gettop(L) > 3 && !lua_isnil(L, 4)) {
if (type == FT_FRAMENUM) {
framenum_type = (enum ft_framenum_type) luaL_checkinteger(L, 4);
if (framenum_type >= FT_FRAMENUM_NUM_TYPES) {
luaL_argerror(L, 4, "Invalid frametype");
return 0;
}
} else if (type == FT_UINT64 || type == FT_INT64) {
vs64 = val64_string_from_table(L,4);
} else {
vs32 = value_string_from_table(L,4);
}
}
if (type == FT_FRAMENUM) {
if (base != BASE_NONE)
luaL_argerror(L, 3, "FRAMENUM must use base.NONE");
else if (mask)
luaL_argerror(L, 5, "FRAMENUM can not have a bitmask");
} else if (base < BASE_DEC || base > BASE_HEX_DEC) {
luaL_argerror(L, 3, "Base must be either base.DEC, base.HEX, base.OCT,"
" base.DEC_HEX, base.DEC_HEX or base.HEX_DEC");
return 0;
} else if ((base == BASE_HEX || base == BASE_OCT) &&
(type == FT_INT8 || type == FT_INT16 || type == FT_INT24 || type == FT_INT32 || type == FT_INT64)) {
luaL_argerror(L, 3, "This type does not display as hexadecimal");
return 0;
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
f->type = type;
f->base = base;
if (vs64) {
f->base |= BASE_VAL64_STRING;
f->vs = VALS(vs64);
} else if (vs32) {
f->vs = VALS(vs32);
} else if (framenum_type) {
f->vs = FRAMENUM_TYPE(framenum_type);
} else {
f->vs = NULL;
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
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = (unsigned)luaL_optinteger(L, 3, BASE_NONE);
true_false_string* tfs = NULL;
guint32 mask = wslua_optguint32(L,5,0);
const gchar* blob = luaL_optstring(L,6,NULL);
if (mask == 0x0 && base != BASE_NONE) {
luaL_argerror(L,3,"Fieldbase (fielddisplay) must be base.NONE"
" if bitmask is zero.");
return 0;
}
if (mask != 0x0 && (base < 1 || base > 64)) {
luaL_argerror(L,3,"Fieldbase (fielddisplay) must be between 1 and 64"
" if bitmask is non-zero.");
return 0;
}
if (lua_gettop(L) > 3 && !lua_isnil(L,4)) {
tfs = true_false_string_from_table(L,4);
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
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
const gchar* abbr = NULL;
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = (unsigned)luaL_optinteger(L,3,ABSOLUTE_TIME_LOCAL);
const gchar* blob = NULL;
if (type == FT_ABSOLUTE_TIME) {
abbr = check_field_name(L,1,type);
blob = luaL_optstring(L,4,NULL);
if (base < ABSOLUTE_TIME_LOCAL || base > ABSOLUTE_TIME_DOY_UTC) {
luaL_argerror(L, 3, "Base must be either LOCAL, UTC, or DOY_UTC");
return 0;
}
} else {
abbr = check_field_name(L,1,type);
blob = luaL_optstring(L,3,NULL);
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
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
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
const gchar* blob = luaL_optstring(L,3,NULL);
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
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
gchar* s = g_strdup_printf("ProtoField(%i): %s %s %s %s %p %.8x %s",
f->hfid,f->name,f->abbrev,
ftenum_to_string(f->type),
base_to_string(f->base),
f->vs,f->mask,f->blob);
lua_pushstring(L,s);
g_free(s);
return 1;
}
static int ProtoField__gc(lua_State* L) {
ProtoField f = toProtoField(L,1);
if (f->hfid == -2) {
g_free(f);
}
return 0;
}
int ProtoField_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ProtoField);
return 0;
}
