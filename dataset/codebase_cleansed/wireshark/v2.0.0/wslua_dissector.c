WSLUA_CONSTRUCTOR Dissector_get (lua_State *L) {
#define WSLUA_ARG_Dissector_get_NAME 1
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Dissector_get_NAME);
Dissector d;
if ((d = find_dissector(name))) {
pushDissector(L, d);
WSLUA_RETURN(1);
}
WSLUA_ARG_ERROR(Dissector_get,NAME,"No such dissector");
return 0;
}
static gint
compare_dissector_key_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
return strcmp((const char*)dissector_a, (const char*)dissector_b);
}
WSLUA_CONSTRUCTOR Dissector_list (lua_State *L) {
GList* list = get_dissector_names();
GList* elist = NULL;
int i = 1;
if (!list) return luaL_error(L,"Cannot retrieve Dissector name list");
list = g_list_sort(list, (GCompareFunc)compare_dissector_key_name);
elist = g_list_first(list);
lua_newtable(L);
for (i=1; elist; i++, elist = g_list_next(elist)) {
lua_pushstring(L,(const char *) elist->data);
lua_rawseti(L,1,i);
}
g_list_free(list);
WSLUA_RETURN(1);
}
WSLUA_METHOD Dissector_call(lua_State* L) {
#define WSLUA_ARG_Dissector_call_TVB 2
#define WSLUA_ARG_Dissector_call_PINFO 3
#define WSLUA_ARG_Dissector_call_TREE 4
Dissector volatile d = checkDissector(L,1);
Tvb tvb = checkTvb(L,WSLUA_ARG_Dissector_call_TVB);
Pinfo pinfo = checkPinfo(L,WSLUA_ARG_Dissector_call_PINFO);
TreeItem ti = checkTreeItem(L,WSLUA_ARG_Dissector_call_TREE);
const char *volatile error = NULL;
int len = 0;
if (! ( d && tvb && pinfo) ) return 0;
TRY {
len = call_dissector(d, tvb->ws_tvb, pinfo->ws_pinfo, ti->tree);
} CATCH_NONFATAL_ERRORS {
show_exception(tvb->ws_tvb, pinfo->ws_pinfo, ti->tree, EXCEPT_CODE, GET_MESSAGE);
error = "Malformed frame";
} ENDTRY;
if (error) { WSLUA_ERROR(Dissector_call,error); }
lua_pushnumber(L,(lua_Number)len);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Dissector__call(lua_State* L) {
#define WSLUA_ARG_Dissector__call_TVB 2
#define WSLUA_ARG_Dissector__call_PINFO 3
#define WSLUA_ARG_Dissector__call_TREE 4
return Dissector_call(L);
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
return 0;
}
WSLUA_CONSTRUCTOR DissectorTable_new (lua_State *L) {
#define WSLUA_ARG_DissectorTable_new_TABLENAME 1
#define WSLUA_OPTARG_DissectorTable_new_UINAME 2
#define WSLUA_OPTARG_DissectorTable_new_TYPE 3
#define WSLUA_OPTARG_DissectorTable_new_BASE 4
const gchar* name = (const gchar*)luaL_checkstring(L,WSLUA_ARG_DissectorTable_new_TABLENAME);
const gchar* ui_name = (const gchar*)luaL_optstring(L,WSLUA_OPTARG_DissectorTable_new_UINAME,name);
enum ftenum type = (enum ftenum)luaL_optinteger(L,WSLUA_OPTARG_DissectorTable_new_TYPE,FT_UINT32);
unsigned base = (unsigned)luaL_optinteger(L,WSLUA_OPTARG_DissectorTable_new_BASE,BASE_DEC);
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
dt->ui_name = ui_name;
dt->created = TRUE;
dt->expired = FALSE;
lua_rawgeti(L, LUA_REGISTRYINDEX, dissectortable_table_ref);
lua_pushstring(L, name);
pushDissectorTable(L, dt);
lua_settable(L, -3);
pushDissectorTable(L, dt);
}
WSLUA_RETURN(1);
default:
WSLUA_OPTARG_ERROR(DissectorTable_new,TYPE,"must be ftypes.UINT{8,16,24,32} or ftypes.STRING");
break;
}
return 0;
}
static void
dissector_tables_list_func(const gchar *table_name, const gchar *ui_name _U_, gpointer user_data) {
dissector_tables_foreach_table_info_t *data = (dissector_tables_foreach_table_info_t*) user_data;
lua_pushstring(data->L, table_name);
lua_rawseti(data->L, 1, data->num);
data->num = data->num + 1;
}
WSLUA_CONSTRUCTOR DissectorTable_list (lua_State *L) {
dissector_tables_foreach_table_info_t data = { 1, L };
lua_newtable(L);
dissector_all_tables_foreach_table(dissector_tables_list_func, (gpointer)&data,
(GCompareFunc)compare_dissector_key_name);
WSLUA_RETURN(1);
}
static void
heur_dissector_tables_list_func(const gchar *table_name, struct heur_dissector_list *table _U_, gpointer user_data) {
dissector_tables_foreach_table_info_t *data = (dissector_tables_foreach_table_info_t*) user_data;
lua_pushstring(data->L, table_name);
lua_rawseti(data->L, 1, data->num);
data->num = data->num + 1;
}
WSLUA_CONSTRUCTOR DissectorTable_heuristic_list (lua_State *L) {
dissector_tables_foreach_table_info_t data = { 1, L };
lua_newtable(L);
dissector_all_heur_tables_foreach_table(heur_dissector_tables_list_func, (gpointer)&data, NULL);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR DissectorTable_get (lua_State *L) {
#define WSLUA_ARG_DissectorTable_get_TABLENAME 1
const gchar* name = luaL_checkstring(L,WSLUA_ARG_DissectorTable_get_TABLENAME);
dissector_table_t table = find_dissector_table(name);
if (table) {
DissectorTable dt = (DissectorTable)g_malloc(sizeof(struct _wslua_distbl_t));
dt->table = table;
dt->name = g_strdup(name);
dt->ui_name = NULL;
dt->created = FALSE;
dt->expired = FALSE;
pushDissectorTable(L, dt);
WSLUA_RETURN(1);
}
WSLUA_ARG_ERROR(DissectorTable_get,TABLENAME,"no such dissector_table");
return 0;
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
p = checkProto(L,WSLUA_ARG_DissectorTable_add_DISSECTOR);
handle = p->handle;
if (! handle) {
WSLUA_ARG_ERROR(DissectorTable_add,DISSECTOR,"a Protocol that does not have a dissector cannot be added to a table");
return 0;
}
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_add_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_add_DISSECTOR);
} else {
WSLUA_ARG_ERROR(DissectorTable_add,DISSECTOR,"must be either Proto or Dissector");
return 0;
}
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_add_PATTERN));
dissector_add_string(dt->name, pattern,handle);
g_free (pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_add_PATTERN)) {
int port = (int)luaL_checkinteger(L, WSLUA_ARG_DissectorTable_add_PATTERN);
dissector_add_uint(dt->name, port, handle);
} else {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_add_PATTERN);
range_t *range = NULL;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR) {
dissector_add_uint_range(dt->name, range, handle);
} else {
g_free (range);
WSLUA_ARG_ERROR(DissectorTable_add,PATTERN,"invalid integer or range");
return 0;
}
g_free (range);
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
p = checkProto(L,WSLUA_ARG_DissectorTable_set_DISSECTOR);
handle = p->handle;
if (! handle) {
WSLUA_ARG_ERROR(DissectorTable_set,DISSECTOR,"a Protocol that does not have a dissector cannot be set to a table");
return 0;
}
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_set_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_set_DISSECTOR);
} else {
WSLUA_ARG_ERROR(DissectorTable_set,DISSECTOR,"must be either Proto or Dissector");
return 0;
}
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_set_PATTERN);
dissector_delete_all(dt->name, handle);
dissector_add_string(dt->name, pattern,handle);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_set_PATTERN)) {
int port = (int)luaL_checkinteger(L, WSLUA_ARG_DissectorTable_set_PATTERN);
dissector_delete_all(dt->name, handle);
dissector_add_uint(dt->name, port, handle);
} else {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_set_PATTERN);
range_t *range = NULL;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR) {
dissector_delete_all(dt->name, handle);
dissector_add_uint_range(dt->name, range, handle);
} else {
g_free (range);
WSLUA_ARG_ERROR(DissectorTable_set,PATTERN,"invalid integer or range");
return 0;
}
g_free (range);
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
p = checkProto(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR);
handle = p->handle;
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_remove_DISSECTOR);
} else {
WSLUA_ARG_ERROR(DissectorTable_remove,DISSECTOR,"must be either Proto or Dissector");
return 0;
}
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
gchar* pattern = g_strdup(luaL_checkstring(L,WSLUA_ARG_DissectorTable_remove_PATTERN));
dissector_delete_string(dt->name, pattern,handle);
g_free (pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
if (lua_isnumber(L, WSLUA_ARG_DissectorTable_remove_PATTERN)) {
int port = (int)luaL_checkinteger(L, WSLUA_ARG_DissectorTable_remove_PATTERN);
dissector_delete_uint(dt->name, port, handle);
} else {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_remove_PATTERN);
range_t *range = NULL;
if (range_convert_str(&range, pattern, G_MAXUINT32) == CVT_NO_ERROR)
dissector_delete_uint_range(dt->name, range, handle);
else {
g_free (range);
WSLUA_ARG_ERROR(DissectorTable_remove,PATTERN,"invalid integer or range");
return 0;
}
g_free (range);
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
p = checkProto(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR);
handle = p->handle;
} else if ( isDissector(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR) ) {
handle = toDissector(L,WSLUA_ARG_DissectorTable_remove_all_DISSECTOR);
} else {
WSLUA_ARG_ERROR(DissectorTable_remove_all,DISSECTOR,"must be either Proto or Dissector");
return 0;
}
dissector_delete_all (dt->name, handle);
return 0;
}
WSLUA_METHOD DissectorTable_try (lua_State *L) {
#define WSLUA_ARG_DissectorTable_try_PATTERN 2
#define WSLUA_ARG_DissectorTable_try_TVB 3
#define WSLUA_ARG_DissectorTable_try_PINFO 4
#define WSLUA_ARG_DissectorTable_try_TREE 5
DissectorTable volatile dt = checkDissectorTable(L,1);
Tvb tvb = checkTvb(L,WSLUA_ARG_DissectorTable_try_TVB);
Pinfo pinfo = checkPinfo(L,WSLUA_ARG_DissectorTable_try_PINFO);
TreeItem ti = checkTreeItem(L,WSLUA_ARG_DissectorTable_try_TREE);
ftenum_t type;
gboolean handled = FALSE;
const gchar *volatile error = NULL;
int len = 0;
if (! (dt && tvb && tvb->ws_tvb && pinfo && ti) ) return 0;
type = get_dissector_table_selector_type(dt->name);
TRY {
if (type == FT_STRING) {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_try_PATTERN);
len = dissector_try_string(dt->table,pattern,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree, NULL);
if (len > 0) {
handled = TRUE;
}
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
int port = (int)luaL_checkinteger(L, WSLUA_ARG_DissectorTable_try_PATTERN);
len = dissector_try_uint(dt->table,port,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree);
if (len > 0) {
handled = TRUE;
}
} else {
luaL_error(L,"No such type of dissector_table");
}
if (!handled) {
len = call_dissector(lua_data_handle,tvb->ws_tvb,pinfo->ws_pinfo,ti->tree);
}
} CATCH_NONFATAL_ERRORS {
show_exception(tvb->ws_tvb, pinfo->ws_pinfo, ti->tree, EXCEPT_CODE, GET_MESSAGE);
error = "Malformed frame";
} ENDTRY;
if (error) { WSLUA_ERROR(DissectorTable_try,error); }
lua_pushnumber(L,(lua_Number)len);
WSLUA_RETURN(1);
}
WSLUA_METHOD DissectorTable_get_dissector (lua_State *L) {
#define WSLUA_ARG_DissectorTable_get_dissector_PATTERN 2
DissectorTable dt = checkDissectorTable(L,1);
ftenum_t type;
dissector_handle_t handle = lua_data_handle;
if (!dt) return 0;
type = get_dissector_table_selector_type(dt->name);
if (type == FT_STRING) {
const gchar* pattern = luaL_checkstring(L,WSLUA_ARG_DissectorTable_get_dissector_PATTERN);
handle = dissector_get_string_handle(dt->table,pattern);
} else if ( type == FT_UINT32 || type == FT_UINT16 || type == FT_UINT8 || type == FT_UINT24 ) {
int port = (int)luaL_checkinteger(L, WSLUA_ARG_DissectorTable_get_dissector_PATTERN);
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
WSLUA_METHOD DissectorTable_add_for_decode_as (lua_State *L) {
#define WSLUA_ARG_DissectorTable_add_for_decode_as_PROTO 2
DissectorTable dt = checkDissectorTable(L,1);
Proto proto = checkProto(L, WSLUA_ARG_DissectorTable_add_for_decode_as_PROTO);
dissector_handle_t handle = NULL;
if (! proto->handle) {
proto->handle = new_register_dissector(proto->loname, dissect_lua, proto->hfid);
}
handle = proto->handle;
dissector_add_for_decode_as(dt->name, handle);
return 0;
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
int base = get_dissector_table_param(dt->name);
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
DissectorTable dt = toDissectorTable(L,1);
if (dt->created && !dt->expired) {
dt->expired = TRUE;
} else {
g_free((char *)dt->name);
g_free((char *)dt->ui_name);
g_free(dt);
}
return 0;
}
int DissectorTable_register(lua_State* L) {
WSLUA_REGISTER_CLASS(DissectorTable);
lua_newtable (L);
dissectortable_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
int wslua_deregister_dissector_tables(lua_State* L) {
lua_rawgeti(L, LUA_REGISTRYINDEX, dissectortable_table_ref);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
DissectorTable dt = checkDissectorTable(L, -1);
if (dt->created) {
deregister_dissector_table(dt->name);
}
}
lua_pop(L, 1);
return 0;
}
