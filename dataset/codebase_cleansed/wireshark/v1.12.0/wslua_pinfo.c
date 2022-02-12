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
WSLUA_CONSTRUCTOR NSTime_new(lua_State *L) {
#define WSLUA_OPTARG_NSTime_new_SECONDS 1
#define WSLUA_OPTARG_NSTime_new_NSECONDS 2
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
if (!nstime) return 0;
nstime->secs = (time_t) luaL_optint(L,WSLUA_OPTARG_NSTime_new_SECONDS,0);
nstime->nsecs = luaL_optint(L,WSLUA_OPTARG_NSTime_new_NSECONDS,0);
pushNSTime(L,nstime);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD NSTime__call(lua_State* L) {
#define WSLUA_OPTARG_NSTime__call_SECONDS 1
#define WSLUA_OPTARG_NSTime__call_NSECONDS 2
lua_remove(L,1);
WSLUA_RETURN(NSTime_new(L));
}
WSLUA_METAMETHOD NSTime__tostring(lua_State* L) {
NSTime nstime = checkNSTime(L,1);
lua_pushstring(L,ep_strdup_printf("%ld.%09d", (long)nstime->secs, nstime->nsecs));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD NSTime__add(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
NSTime time3 = (NSTime)g_malloc (sizeof (nstime_t));
nstime_sum (time3, time1, time2);
pushNSTime (L, time3);
return 1;
}
WSLUA_METAMETHOD NSTime__sub(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
NSTime time3 = (NSTime)g_malloc (sizeof (nstime_t));
nstime_delta (time3, time1, time2);
pushNSTime (L, time3);
return 1;
}
WSLUA_METAMETHOD NSTime__unm(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = (NSTime)g_malloc (sizeof (nstime_t));
nstime_set_zero (time2);
nstime_subtract (time2, time1);
pushNSTime (L, time2);
return 1;
}
WSLUA_METAMETHOD NSTime__eq(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (nstime_cmp(time1, time2) == 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD NSTime__le(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (nstime_cmp(time1, time2) <= 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD NSTime__lt(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (nstime_cmp(time1, time2) < 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
static int NSTime__gc(lua_State* L) {
NSTime nstime = toNSTime(L,1);
if (!nstime) return 0;
g_free (nstime);
return 0;
}
int NSTime_register(lua_State* L) {
WSLUA_REGISTER_CLASS(NSTime);
WSLUA_REGISTER_ATTRIBUTES(NSTime);
return 0;
}
WSLUA_CONSTRUCTOR Address_ip(lua_State* L) {
#define WSLUA_ARG_Address_ip_HOSTNAME 1
Address addr = (Address)g_malloc(sizeof(address));
guint32* ip_addr = (guint32 *)g_malloc(sizeof(guint32));
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Address_ip_HOSTNAME);
if (! get_host_ipaddr(name, (guint32*)ip_addr)) {
*ip_addr = 0;
}
SET_ADDRESS(addr, AT_IPv4, 4, ip_addr);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Address__tostring(lua_State* L) {
Address addr = checkAddress(L,1);
lua_pushstring(L,ep_address_to_display(addr));
WSLUA_RETURN(1);
}
static int Address__gc(lua_State* L) {
Address addr = toAddress(L,1);
if (addr) {
g_free((void*)(addr->data));
g_free((void*)(addr));
}
return 0;
}
WSLUA_METAMETHOD Address__eq(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (ADDRESSES_EQUAL(addr1, addr2))
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD Address__le(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (CMP_ADDRESS(addr1, addr2) <= 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD Address__lt(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (CMP_ADDRESS(addr1, addr2) < 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
int Address_register(lua_State *L) {
WSLUA_REGISTER_CLASS(Address);
return 0;
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
if (!s) {
WSLUA_ARG_ERROR(Column_set,TEXT,"must be a string");
return 0;
}
col_add_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_append(lua_State *L) {
#define WSLUA_ARG_Column_append_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_append_TEXT);
if (!(c->cinfo))
return 0;
if (!s) {
WSLUA_ARG_ERROR(Column_append,TEXT,"must be a string");
return 0;
}
col_append_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_prepend(lua_State *L) {
#define WSLUA_ARG_Column_prepend_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_prepend_TEXT);
if (!(c->cinfo))
return 0;
if (!s) {
WSLUA_ARG_ERROR(Column_prepend,TEXT,"must be a string");
return 0;
}
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
if (!colname) return 0;
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
return 0;
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
string = (const gchar *)(g_hash_table_lookup (priv->table, (gpointer) name));
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
g_hash_table_replace (priv->table, (gpointer) ep_strdup(name), (gpointer) ep_strdup(string));
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
PUSH_COLUMNS(L,cols);
} else {
lua_settop(L,0);
PUSH_COLUMNS(L,cols);
lua_pushstring(L,colname);
return Columns__index(L);
}
return 1;
}
static int Pinfo_get_private(lua_State *L) {
PrivateTable priv = NULL;
Pinfo pinfo = checkPinfo(L,1);
const gchar* privname = luaL_optstring(L,2,NULL);
gboolean is_allocated = FALSE;
if (!pinfo->ws_pinfo->private_table) {
pinfo->ws_pinfo->private_table = g_hash_table_new(g_str_hash,g_str_equal);
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
if (CMP_ADDRESS(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) >= 0) {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->src));
} else {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->dst));
}
pushAddress(L,addr);
return 1;
}
static int Pinfo_get_lo(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Address addr;
addr = (Address)g_malloc(sizeof(address));
if (CMP_ADDRESS(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) < 0) {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->src));
} else {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->dst));
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
outstanding_Column = g_ptr_array_new();
outstanding_Columns = g_ptr_array_new();
outstanding_PrivateTable = g_ptr_array_new();
return 0;
}
