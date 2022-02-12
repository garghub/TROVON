Pinfo* push_Pinfo(lua_State* L, packet_info* ws_pinfo) {
Pinfo pinfo = NULL;
if (ws_pinfo) {
pinfo = (Pinfo)g_malloc(sizeof(struct _wslua_pinfo));
pinfo->ws_pinfo = ws_pinfo;
pinfo->expired = FALSE;
g_ptr_array_add(outstanding_Pinfo,pinfo);
}
return pushPinfo(L,pinfo);
}
WSLUA_METAMETHOD PrivateTable__tostring(lua_State* L) {
PrivateTable priv = toPrivateTable(L,1);
GString *key_string;
GList *keys, *key;
if (!priv) return 0;
key_string = g_string_new ("");
keys = g_hash_table_get_keys (priv->table);
key = g_list_first (keys);
while (key) {
key_string = g_string_append (key_string, (const gchar *)key->data);
key = g_list_next (key);
if (key) {
key_string = g_string_append_c (key_string, ',');
}
}
lua_pushstring(L,key_string->str);
g_string_free (key_string, TRUE);
g_list_free (keys);
WSLUA_RETURN(1);
}
static int PrivateTable__index(lua_State* L) {
PrivateTable priv = checkPrivateTable(L,1);
const gchar* name = luaL_checkstring(L,2);
const gchar* string;
string = (const gchar *)(g_hash_table_lookup (priv->table, name));
if (string) {
lua_pushstring(L, string);
} else {
lua_pushnil(L);
}
return 1;
}
static int PrivateTable__newindex(lua_State* L) {
PrivateTable priv = checkPrivateTable(L,1);
const gchar* name = luaL_checkstring(L,2);
const gchar* string = NULL;
if (lua_isstring(L,3)) {
string = luaL_checkstring(L,3);
} else if (lua_isboolean(L,3)) {
string = lua_toboolean(L,3) ? "" : NULL;
} else if (!lua_isnil(L,3)) {
luaL_error(L,"unsupported type: %s", lua_typename(L,3));
return 0;
}
if (string) {
g_hash_table_replace (priv->table, (gpointer) g_strdup(name), (gpointer) g_strdup(string));
} else {
g_hash_table_remove (priv->table, (gconstpointer) name);
}
return 1;
}
static int PrivateTable__gc(lua_State* L) {
PrivateTable priv = toPrivateTable(L,1);
if (!priv) return 0;
if (!priv->expired) {
priv->expired = TRUE;
} else {
if (priv->is_allocated) {
g_hash_table_destroy (priv->table);
}
g_free(priv);
}
return 0;
}
int PrivateTable_register(lua_State* L) {
WSLUA_REGISTER_META(PrivateTable);
return 0;
}
static int Pinfo__tostring(lua_State *L) { lua_pushstring(L,"a Pinfo"); return 1; }
static double
lua_nstime_to_sec(const nstime_t *nstime)
{
return (((double)nstime->secs) + (((double)nstime->nsecs) / 1000000000.0));
}
static double
lua_delta_nstime_to_sec(const Pinfo pinfo, const frame_data *fd, guint32 prev_num)
{
nstime_t del;
frame_delta_abs_time(pinfo->ws_pinfo->epan, fd, prev_num, &del);
return lua_nstime_to_sec(&del);
}
static int Pinfo_get_match(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
if (pinfo->ws_pinfo->match_string) {
lua_pushstring(L,pinfo->ws_pinfo->match_string);
} else {
lua_pushnumber(L,(lua_Number)(pinfo->ws_pinfo->match_uint));
}
return 1;
}
static int Pinfo_get_columns(lua_State *L) {
Columns cols = NULL;
Pinfo pinfo = checkPinfo(L,1);
const gchar* colname = luaL_optstring(L,2,NULL);
cols = (Columns)g_malloc(sizeof(struct _wslua_cols));
cols->cinfo = pinfo->ws_pinfo->cinfo;
cols->expired = FALSE;
if (!colname) {
Push_Columns(L,cols);
} else {
lua_settop(L,0);
Push_Columns(L,cols);
lua_pushstring(L,colname);
return get_Columns_index(L);
}
return 1;
}
static int Pinfo_get_private(lua_State *L) {
PrivateTable priv = NULL;
Pinfo pinfo = checkPinfo(L,1);
const gchar* privname = luaL_optstring(L,2,NULL);
gboolean is_allocated = FALSE;
if (!pinfo->ws_pinfo->private_table) {
pinfo->ws_pinfo->private_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
is_allocated = TRUE;
}
priv = (PrivateTable)g_malloc(sizeof(struct _wslua_private_table));
priv->table = pinfo->ws_pinfo->private_table;
priv->is_allocated = is_allocated;
priv->expired = FALSE;
if (!privname) {
PUSH_PRIVATE_TABLE(L,priv);
} else {
lua_settop(L,0);
PUSH_PRIVATE_TABLE(L,priv);
lua_pushstring(L,privname);
return PrivateTable__index(L);
}
return 1;
}
static int Pinfo_get_hi(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Address addr;
addr = (Address)g_malloc(sizeof(address));
if (cmp_address(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) >= 0) {
copy_address(addr, &(pinfo->ws_pinfo->src));
} else {
copy_address(addr, &(pinfo->ws_pinfo->dst));
}
pushAddress(L,addr);
return 1;
}
static int Pinfo_get_lo(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Address addr;
addr = (Address)g_malloc(sizeof(address));
if (cmp_address(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) < 0) {
copy_address(addr, &(pinfo->ws_pinfo->src));
} else {
copy_address(addr, &(pinfo->ws_pinfo->dst));
}
pushAddress(L,addr);
return 1;
}
static int Pinfo_set_conversation(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Proto proto = checkProto(L,2);
conversation_t *conversation;
if (!proto->handle) {
luaL_error(L,"Proto %s has no registered dissector", proto->name? proto->name:"<UKNOWN>");
return 0;
}
conversation = find_or_create_conversation(pinfo->ws_pinfo);
conversation_set_dissector(conversation,proto->handle);
return 0;
}
static int Pinfo__gc(lua_State* L) {
Pinfo pinfo = toPinfo(L,1);
if (!pinfo) return 0;
if (!pinfo->expired)
pinfo->expired = TRUE;
else
g_free(pinfo);
return 0;
}
int Pinfo_register(lua_State* L) {
WSLUA_REGISTER_META(Pinfo);
WSLUA_REGISTER_ATTRIBUTES(Pinfo);
outstanding_Pinfo = g_ptr_array_new();
outstanding_PrivateTable = g_ptr_array_new();
return 0;
}
