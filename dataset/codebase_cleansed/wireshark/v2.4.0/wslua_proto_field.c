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
GArray* vs;
value_string* vs32;
if (lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
return NULL;
}
vs = g_array_new(TRUE,TRUE,sizeof(value_string));
lua_pushnil(L);
while (lua_next(L, idx) != 0) {
value_string v = {0,NULL};
if (! lua_isnumber(L,-2)) {
vs32 = (value_string *)(void *)vs->data;
while (vs32->strptr) {
g_free((gchar *)vs32->strptr);
vs32++;
}
g_array_free(vs,TRUE);
luaL_argerror(L,idx,"All keys of a table used as value_string must be integers");
return NULL;
}
if (! lua_isstring(L,-1)) {
vs32 = (value_string *)(void *)vs->data;
while (vs32->strptr) {
g_free((gchar *)vs32->strptr);
vs32++;
}
g_array_free(vs,TRUE);
luaL_argerror(L,idx,"All values of a table used as value_string must be strings");
return NULL;
}
v.value = wslua_toguint32(L,-2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
vs32 = (value_string*)(void*)vs->data;
g_array_free(vs,FALSE);
return vs32;
}
static val64_string* val64_string_from_table(lua_State* L, int idx) {
GArray* vs;
val64_string* vs64;
if (lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
return NULL;
}
vs = g_array_new(TRUE,TRUE,sizeof(val64_string));
lua_pushnil(L);
while (lua_next(L, idx) != 0) {
val64_string v = {0,NULL};
if (! lua_isnumber(L,-2)) {
vs64 = (val64_string *)(void *)vs->data;
while (vs64->strptr) {
g_free((gchar *)vs64->strptr);
vs64++;
}
g_array_free(vs,TRUE);
luaL_argerror(L,idx,"All keys of a table used as value string must be integers");
return NULL;
}
if (! lua_isstring(L,-1)) {
vs64 = (val64_string *)(void *)vs->data;
while (vs64->strptr) {
g_free((gchar *)vs64->strptr);
vs64++;
}
g_array_free(vs,TRUE);
luaL_argerror(L,idx,"All values of a table used as value string must be strings");
return NULL;
}
v.value = wslua_toguint64(L, -2);
v.strptr = g_strdup(lua_tostring(L,-1));
g_array_append_val(vs,v);
lua_pop(L, 1);
}
vs64 = (val64_string*)(void*)vs->data;
g_array_free(vs,FALSE);
return vs64;
}
static true_false_string* true_false_string_from_table(lua_State* L, int idx) {
true_false_string* tfs;
if (lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
return NULL;
}
tfs = (true_false_string *) g_malloc(sizeof(true_false_string));
tfs->true_string = g_strdup("True");
tfs->false_string = g_strdup("False");
lua_pushnil(L);
while (lua_next(L, idx)) {
if (! lua_isnumber(L,-2)) {
g_free ((gchar *)tfs->true_string);
g_free ((gchar *)tfs->false_string);
g_free (tfs);
luaL_argerror(L,idx,"All keys of a table used as true_false_string must be integers");
return NULL;
}
if (! lua_isstring(L,-1)) {
g_free ((gchar *)tfs->true_string);
g_free ((gchar *)tfs->false_string);
g_free (tfs);
luaL_argerror(L,idx,"All values of a table used as true_false_string must be strings");
return NULL;
}
switch (lua_tointeger(L,-2)) {
case 1:
g_free((gchar *)tfs->true_string);
tfs->true_string = g_strdup(lua_tostring(L,-1));
break;
case 2:
g_free((gchar *)tfs->false_string);
tfs->false_string = g_strdup(lua_tostring(L,-1));
break;
default:
g_free ((gchar *)tfs->true_string);
g_free ((gchar *)tfs->false_string);
g_free (tfs);
luaL_argerror(L,idx,"The true_false_string table can have maximum two strings with key value 1 and 2");
return NULL;
}
lua_pop(L, 1);
}
return tfs;
}
static unit_name_string* unit_name_string_from_table(lua_State* L, int idx) {
unit_name_string* units;
if (lua_isnil(L,idx)) {
return NULL;
} else if (!lua_istable(L,idx)) {
luaL_argerror(L,idx,"must be a table");
return NULL;
}
units = (unit_name_string *) g_malloc0(sizeof(unit_name_string));
lua_pushnil(L);
while (lua_next(L, idx)) {
if (! lua_isnumber(L,-2)) {
g_free(units->singular);
g_free(units->plural);
g_free(units);
luaL_argerror(L,idx,"All keys of a table used as unit name must be integers");
return NULL;
}
if (! lua_isstring(L,-1)) {
g_free(units->singular);
g_free(units->plural);
g_free(units);
luaL_argerror(L,idx,"All values of a table used as unit name must be strings");
return NULL;
}
switch (lua_tointeger(L,-2)) {
case 1:
g_free((gchar *)units->singular);
units->singular = g_strdup(lua_tostring(L,-1));
break;
case 2:
g_free((gchar *)units->plural);
units->plural = g_strdup(lua_tostring(L,-1));
break;
default:
g_free(units->singular);
g_free(units->plural);
g_free(units);
luaL_argerror(L,idx,"The unit name table can have maximum two strings with key value 1 and 2");
return NULL;
}
lua_pop(L, 1);
}
if (!units->singular) {
g_free(units->plural);
g_free(units);
luaL_argerror(L,idx,"The unit name table must have a singular entry (key value 1)");
return NULL;
}
return units;
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
unit_name_string *uns = NULL;
unsigned base;
guint32 mask = wslua_optguint32(L, WSLUA_OPTARG_ProtoField_new_MASK, 0x0);
const gchar *blob = luaL_optstring(L,WSLUA_OPTARG_ProtoField_new_DESCR,NULL);
gboolean unit_string = FALSE;
if (!name[0]) {
WSLUA_ARG_ERROR(ProtoField_new,NAME,"cannot be an empty string");
return 0;
}
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
case FT_CHAR:
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
if (type != FT_CHAR && base & BASE_UNIT_STRING) {
unit_string = TRUE;
base &= ~BASE_UNIT_STRING;
}
if (base == BASE_NONE) {
if (type == FT_CHAR)
base = BASE_OCT;
else
base = BASE_DEC;
}
if ((base != BASE_DEC) &&
(type == FT_INT8 || type == FT_INT16 || type == FT_INT24 || type == FT_INT32 || type == FT_INT64))
{
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be either base.DEC or base.UNIT_STRING");
return 0;
} else if (base < BASE_DEC || base > BASE_HEX_DEC) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be either base.DEC, base.HEX, base.OCT,"
" base.DEC_HEX, base.HEX_DEC or base.UNIT_STRING");
return 0;
}
if (nargs >= WSLUA_OPTARG_ProtoField_new_VALUESTRING) {
if (unit_string) {
uns = unit_name_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING);
} else if (type == FT_UINT64 || type == FT_INT64) {
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
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Base must be either base.LOCAL, base.UTC, or base.DOY_UTC");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"ABSOLUTE_TIME can not have a bitmask");
return 0;
}
break;
case FT_STRING:
case FT_STRINGZ:
if (base != STR_ASCII && base != STR_UNICODE) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Display must be either base.ASCII or base.UNICODE");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"This type can not have a bitmask");
return 0;
}
break;
case FT_BYTES:
case FT_UINT_BYTES:
if (base != BASE_NONE && (base < SEP_DOT || base > SEP_SPACE)) {
WSLUA_OPTARG_ERROR(ProtoField_new,BASE,"Display must be either base.NONE, base.DOT, base.DASH, base.COLON or base.SPACE");
return 0;
}
if (mask) {
WSLUA_OPTARG_ERROR(ProtoField_new,MASK,"This type can not have a bitmask");
return 0;
}
break;
case FT_FLOAT:
case FT_DOUBLE:
if (base & BASE_UNIT_STRING) {
unit_string = TRUE;
base &= ~BASE_UNIT_STRING;
}
if (nargs >= WSLUA_OPTARG_ProtoField_new_VALUESTRING) {
uns = unit_name_string_from_table(L,WSLUA_OPTARG_ProtoField_new_VALUESTRING);
}
case FT_NONE:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_ETHER:
case FT_RELATIVE_TIME:
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
case FT_IEEE_11073_SFLOAT:
case FT_IEEE_11073_FLOAT:
case FT_UINT_STRING:
case FT_AX25:
case FT_STRINGZPAD:
WSLUA_ARG_ERROR(ProtoField_new,TYPE,"Unsupported ProtoField field type");
break;
case FT_PCRE:
default:
WSLUA_ARG_ERROR(ProtoField_new,TYPE,"Invalid ProtoField field type");
break;
}
if (unit_string && !uns) {
WSLUA_OPTARG_ERROR(ProtoField_new,VALUESTRING, "Base is base.UNIT_STRING but no table is given");
return 0;
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
} else if (uns) {
f->base |= BASE_UNIT_STRING;
f->vs = uns;
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
unit_name_string* uns = NULL;
guint32 mask = wslua_optguint32(L,5,0);
const gchar* blob = luaL_optstring(L,6,NULL);
gboolean unit_string = FALSE;
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
if (base & BASE_UNIT_STRING) {
unit_string = TRUE;
base &= ~BASE_UNIT_STRING;
if (base == BASE_NONE) {
base = BASE_DEC;
}
}
if (lua_gettop(L) > 3 && !lua_isnil(L, 4)) {
if (type == FT_FRAMENUM) {
framenum_type = (enum ft_framenum_type) luaL_checkinteger(L, 4);
if (framenum_type >= FT_FRAMENUM_NUM_TYPES) {
luaL_argerror(L, 4, "Invalid frametype");
return 0;
}
} else if (unit_string) {
uns = unit_name_string_from_table(L,4);
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
} else if ((base != BASE_DEC) &&
(type == FT_INT8 || type == FT_INT16 || type == FT_INT24 || type == FT_INT32 || type == FT_INT64)) {
luaL_argerror(L, 3, "Base must be either base.DEC or base.UNIT_STRING");
return 0;
} else if (base < BASE_DEC || base > BASE_HEX_DEC) {
luaL_argerror(L, 3, "Base must be either base.DEC, base.HEX, base.OCT,"
" base.DEC_HEX, base.HEX_DEC or base.UNIT_STRING");
return 0;
}
if (unit_string && !uns) {
luaL_argerror(L, 4, "Base is base.UNIT_STRING but no table is given");
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
} else if (uns) {
f->base |= BASE_UNIT_STRING;
f->vs = uns;
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
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
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
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = (unsigned)luaL_optinteger(L,3,ABSOLUTE_TIME_LOCAL);
const gchar* blob = luaL_optstring(L,4,NULL);
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
if (type == FT_ABSOLUTE_TIME) {
if (base < ABSOLUTE_TIME_LOCAL || base > ABSOLUTE_TIME_DOY_UTC) {
luaL_argerror(L, 3, "Base must be either base.LOCAL, base.UTC, or base.DOY_UTC");
return 0;
}
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
static int ProtoField_floating(lua_State* L,enum ftenum type) {
ProtoField f;
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
unit_name_string* uns = NULL;
const gchar* blob;
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
if (lua_istable(L, 3)) {
uns = unit_name_string_from_table(L,3);
blob = luaL_optstring(L,4,NULL);
} else {
blob = luaL_optstring(L,3,NULL);
}
f = g_new(wslua_field_t,1);
f->hfid = -2;
f->ett = -1;
f->name = g_strdup(name);
f->abbrev = g_strdup(abbr);
f->type = type;
if (uns) {
f->vs = uns;
f->base = BASE_NONE | BASE_UNIT_STRING;
} else {
f->vs = NULL;
f->base = BASE_NONE;
}
f->mask = 0;
if (blob && strcmp(blob, f->name) != 0) {
f->blob = g_strdup(blob);
} else {
f->blob = NULL;
}
pushProtoField(L,f);
return 1;
}
static int ProtoField_other_display(lua_State* L,enum ftenum type) {
ProtoField f;
const gchar* abbr = check_field_name(L,1,type);
const gchar* name = luaL_optstring(L,2,abbr);
unsigned base = BASE_NONE;
const gchar* blob;
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
if (lua_isnumber(L, 3)) {
base = (unsigned)luaL_optinteger(L,3,BASE_NONE);
if (type == FT_STRING || type == FT_STRINGZ) {
if (base != STR_ASCII && base != STR_UNICODE) {
luaL_argerror(L, 3, "Display must be either base.ASCII or base.UNICODE");
return 0;
}
} else if (type == FT_BYTES || type == FT_UINT_BYTES) {
if (base != BASE_NONE && (base < SEP_DOT || base > SEP_SPACE)) {
luaL_argerror(L, 3, "Display must be either base.NONE, base.DOT, base.DASH, base.COLON or base.SPACE");
return 0;
}
}
blob = luaL_optstring(L,4,NULL);
} else {
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
if (!name[0]) {
luaL_argerror(L, 2, "cannot be an empty string");
return 0;
}
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
