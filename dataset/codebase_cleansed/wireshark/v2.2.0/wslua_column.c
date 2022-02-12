void Push_Columns(lua_State *L, Columns c)
{
g_ptr_array_add(outstanding_Columns, c);
pushColumns(L, c);
}
static gint col_name_to_id(const gchar* name) {
const struct col_names_t* cn;
for(cn = colnames; cn->name; cn++) {
if (g_str_equal(cn->name,name)) {
return cn->id;
}
}
return 0;
}
static const gchar* col_id_to_name(gint id) {
const struct col_names_t* cn;
for(cn = colnames; cn->name; cn++) {
if ( cn->id == id ) {
return cn->name;
}
}
return NULL;
}
WSLUA_METAMETHOD Column__tostring(lua_State *L) {
Column c = checkColumn(L,1);
const gchar* text;
if (!c->cinfo) {
text = col_id_to_name(c->col);
lua_pushfstring(L, "(%s)", text ? text : "unknown");
}
else {
text = col_get_text(c->cinfo, c->col);
lua_pushstring(L, text ? text : "(nil)");
}
WSLUA_RETURN(1);
}
static int Column__gc(lua_State* L) {
Column col = toColumn(L,1);
if (!col) return 0;
if (!col->expired)
col->expired = TRUE;
else
g_free(col);
return 0;
}
WSLUA_METHOD Column_clear(lua_State *L) {
Column c = checkColumn(L,1);
if (!(c->cinfo)) return 0;
col_clear(c->cinfo, c->col);
return 0;
}
WSLUA_METHOD Column_set(lua_State *L) {
#define WSLUA_ARG_Column_set_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_set_TEXT);
if (!(c->cinfo))
return 0;
col_add_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_append(lua_State *L) {
#define WSLUA_ARG_Column_append_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_append_TEXT);
if (!(c->cinfo))
return 0;
col_append_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_prepend(lua_State *L) {
#define WSLUA_ARG_Column_prepend_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_prepend_TEXT);
if (!(c->cinfo))
return 0;
col_prepend_fstr(c->cinfo, c->col, "%s",s);
return 0;
}
WSLUA_METHOD Column_fence(lua_State *L) {
Column c = checkColumn(L,1);
if (c->cinfo)
col_set_fence(c->cinfo, c->col);
return 0;
}
WSLUA_METHOD Column_clear_fence(lua_State *L) {
Column c = checkColumn(L,1);
if (c->cinfo)
col_clear_fence(c->cinfo, c->col);
return 0;
}
int Column_register(lua_State *L) {
WSLUA_REGISTER_CLASS(Column);
outstanding_Column = g_ptr_array_new();
return 0;
}
WSLUA_METAMETHOD Columns__tostring(lua_State *L) {
lua_pushstring(L,"Columns");
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Columns__newindex(lua_State *L) {
#define WSLUA_ARG_Columns__newindex_COLUMN 2
#define WSLUA_ARG_Columns__newindex_TEXT 3
Columns cols = checkColumns(L,1);
const struct col_names_t* cn;
const char* colname;
const char* text;
if (!cols) return 0;
if (cols->expired) {
luaL_error(L,"expired column");
return 0;
}
colname = luaL_checkstring(L,WSLUA_ARG_Columns__newindex_COLUMN);
text = luaL_checkstring(L,WSLUA_ARG_Columns__newindex_TEXT);
for(cn = colnames; cn->name; cn++) {
if( g_str_equal(cn->name,colname) ) {
col_add_str(cols->cinfo, cn->id, text);
return 0;
}
}
WSLUA_ARG_ERROR(Columns__newindex,COLUMN,"the column name must be a valid column");
return 0;
}
WSLUA_METAMETHOD Columns__index(lua_State *L) {
Columns cols = checkColumns(L,1);
const struct col_names_t* cn;
const char* colname = luaL_checkstring(L,2);
if (!cols) {
Column c = (Column)g_malloc(sizeof(struct _wslua_col_info));
c->cinfo = NULL;
c->col = col_name_to_id(colname);
c->expired = FALSE;
PUSH_COLUMN(L,c);
return 1;
}
if (cols->expired) {
luaL_error(L,"expired column");
return 0;
}
for(cn = colnames; cn->name; cn++) {
if( g_str_equal(cn->name,colname) ) {
Column c = (Column)g_malloc(sizeof(struct _wslua_col_info));
c->cinfo = cols->cinfo;
c->col = col_name_to_id(colname);
c->expired = FALSE;
PUSH_COLUMN(L,c);
return 1;
}
}
return 0;
}
int get_Columns_index(lua_State *L)
{
return Columns__index(L);
}
static int Columns__gc(lua_State* L) {
Columns cols = toColumns(L,1);
if (!cols) return 0;
if (!cols->expired)
cols->expired = TRUE;
else
g_free(cols);
return 0;
}
int Columns_register(lua_State *L) {
WSLUA_REGISTER_META(Columns);
outstanding_Columns = g_ptr_array_new();
return 0;
}
