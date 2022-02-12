Pinfo* push_Pinfo(lua_State* L, packet_info* ws_pinfo) {
Pinfo pinfo = NULL;
if (ws_pinfo) {
pinfo = g_malloc(sizeof(struct _wslua_pinfo));
pinfo->ws_pinfo = ws_pinfo;
pinfo->expired = FALSE;
g_ptr_array_add(outstanding_Pinfo,pinfo);
}
return pushPinfo(L,pinfo);
}
WSLUA_CONSTRUCTOR NSTime_new(lua_State *L) {
#define WSLUA_OPTARG_NSTime_new_SECONDS 1
#define WSLUA_OPTARG_NSTime_new_NSECONDS 2
NSTime time = g_malloc(sizeof(nstime_t));
if (!time) return 0;
time->secs = (time_t) luaL_optint(L,WSLUA_OPTARG_NSTime_new_SECONDS,0);
time->nsecs = luaL_optint(L,WSLUA_OPTARG_NSTime_new_NSECONDS,0);
pushNSTime(L,time);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD NSTime__tostring(lua_State* L) {
NSTime nstime = checkNSTime(L,1);
if (!nstime) return 0;
lua_pushstring(L,ep_strdup_printf("%ld.%09d", (long)nstime->secs, nstime->nsecs));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD NSTime__add(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
NSTime time3 = g_malloc (sizeof (nstime_t));
nstime_sum (time3, time1, time2);
pushNSTime (L, time3);
return 1;
}
WSLUA_METAMETHOD NSTime__sub(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
NSTime time3 = g_malloc (sizeof (nstime_t));
nstime_delta (time3, time1, time2);
pushNSTime (L, time3);
return 1;
}
WSLUA_METAMETHOD NSTime__unm(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = g_malloc (sizeof (nstime_t));
nstime_set_zero (time2);
nstime_subtract (time2, time1);
pushNSTime (L, time2);
return 1;
}
WSLUA_METAMETHOD NSTime__eq(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (!time1 || !time2)
WSLUA_ERROR(FieldInfo__eq,"Data source must be the same for both fields");
if (nstime_cmp(time1, time2) == 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD NSTime__le(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (!time1 || !time2)
WSLUA_ERROR(FieldInfo__eq,"Data source must be the same for both fields");
if (nstime_cmp(time1, time2) <= 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD NSTime__lt(lua_State* L) {
NSTime time1 = checkNSTime(L,1);
NSTime time2 = checkNSTime(L,2);
gboolean result = FALSE;
if (!time1 || !time2)
WSLUA_ERROR(FieldInfo__eq,"Data source must be the same for both fields");
if (nstime_cmp(time1, time2) < 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
static int NSTime_get_secs(lua_State* L) {
NSTime time = toNSTime(L,1);
lua_pushnumber (L,(lua_Number)(time->secs));
return 1;
}
static int NSTime_set_secs(lua_State* L)
{
NSTime time = toNSTime(L,1);
time_t secs = luaL_checkint(L,3);
time->secs = secs;
return 0;
}
static int NSTime_get_nsecs(lua_State* L) {
NSTime time = toNSTime(L,1);
lua_pushnumber (L,(lua_Number)(time->nsecs));
return 1;
}
static int NSTime_set_nsecs(lua_State* L) {
NSTime time = toNSTime(L,1);
int nsecs = luaL_checkint(L,3);
time->nsecs = nsecs;
return 0;
}
static int NSTime__index(lua_State* L) {
NSTime time = checkNSTime(L,1);
const gchar* name = luaL_checkstring(L,2);
const nstime_actions_t* pa;
if (! (time && name) ) return 0;
for (pa = nstime_actions; pa->name; pa++) {
if ( g_str_equal(name,pa->name) ) {
if (pa->get) {
return pa->get(L);
} else {
luaL_error(L,"You cannot get the `%s' attribute of a nstime",name);
return 0;
}
}
}
luaL_error(L,"A protocol doesn't have a `%s' nstime",name);
return 0;
}
static int NSTime__newindex(lua_State* L) {
NSTime time = checkNSTime(L,1);
const gchar* name = luaL_checkstring(L,2);
const nstime_actions_t* pa;
if (! (time && name) ) return 0;
for (pa = nstime_actions; pa->name; pa++) {
if ( g_str_equal(name,pa->name) ) {
if (pa->set) {
return pa->set(L);
} else {
luaL_error(L,"You cannot set the `%s' attribute of a nstime",name);
return 0;
}
}
}
luaL_error(L,"A protocol doesn't have a `%s' nstime",name);
return 0;
}
static int NSTime__gc(lua_State* L) {
NSTime nstime = checkNSTime(L,1);
if (!nstime) return 0;
g_free (nstime);
return 0;
}
int NSTime_register(lua_State* L) {
WSLUA_REGISTER_META(NSTime);
lua_pushstring(L, "NSTime");
lua_pushcfunction(L, NSTime_new);
lua_settable(L, LUA_GLOBALSINDEX);
return 1;
}
WSLUA_CONSTRUCTOR Address_ip(lua_State* L) {
#define WSLUA_ARG_Address_ip_HOSTNAME 1
Address addr = g_malloc(sizeof(address));
guint32* ip_addr = g_malloc(sizeof(guint32));
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
lua_pushstring(L,get_addr_name(addr));
WSLUA_RETURN(1);
}
static int Address__gc(lua_State* L) {
Address addr = checkAddress(L,1);
if (addr) {
g_free((void*)addr->data);
g_free((void*)addr);
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
return 1;
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
const gchar* name;
if (!(c)) {
return 0;
}
name = col_id_to_name(c->col);
lua_pushstring(L,name ? name : "Unknown Column");
WSLUA_RETURN(1);
}
static int Column__gc(lua_State* L) {
Column col = checkColumn(L,1);
if (!col) return 0;
if (!col->expired)
col->expired = TRUE;
else
g_free(col);
return 0;
}
WSLUA_METHOD Column_clear(lua_State *L) {
Column c = checkColumn(L,1);
if (!(c && c->cinfo)) return 0;
col_clear(c->cinfo, c->col);
return 0;
}
WSLUA_METHOD Column_set(lua_State *L) {
#define WSLUA_ARG_Column_set_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_set_TEXT);
if (!(c && c->cinfo))
return 0;
if (!s) WSLUA_ARG_ERROR(Column_set,TEXT,"must be a string");
col_add_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_append(lua_State *L) {
#define WSLUA_ARG_Column_append_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_append_TEXT);
if (!(c && c->cinfo))
return 0;
if (!s) WSLUA_ARG_ERROR(Column_append,TEXT,"must be a string");
col_append_str(c->cinfo, c->col, s);
return 0;
}
WSLUA_METHOD Column_preppend(lua_State *L) {
#define WSLUA_ARG_Column_prepend_TEXT 2
Column c = checkColumn(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_Column_prepend_TEXT);
if (!(c && c->cinfo))
return 0;
if (!s) WSLUA_ARG_ERROR(Column_prepend,TEXT,"must be a string");
if (check_col(c->cinfo, c->col))
col_prepend_fstr(c->cinfo, c->col, "%s",s);
return 0;
}
int Column_register(lua_State *L) {
WSLUA_REGISTER_CLASS(Column);
return 1;
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
}
WSLUA_METAMETHOD Columns_index(lua_State *L) {
Columns cols = checkColumns(L,1);
const struct col_names_t* cn;
const char* colname = luaL_checkstring(L,2);
if (!cols) {
Column c = g_malloc(sizeof(struct _wslua_col_info));
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
Column c = g_malloc(sizeof(struct _wslua_col_info));
c->cinfo = cols->cinfo;
c->col = col_name_to_id(colname);
c->expired = FALSE;
PUSH_COLUMN(L,c);
return 1;
}
}
return 0;
}
static int Columns_gc(lua_State* L) {
Columns cols = checkColumns(L,1);
if (!cols) return 0;
if (!cols->expired)
cols->expired = TRUE;
else
g_free(cols);
return 0;
}
int Columns_register(lua_State *L) {
WSLUA_REGISTER_META(Columns);
return 1;
}
WSLUA_METAMETHOD PrivateTable__tostring(lua_State* L) {
PrivateTable priv = checkPrivateTable(L,1);
GString *key_string;
GList *keys, *key;
if (!priv) return 0;
key_string = g_string_new ("");
keys = g_hash_table_get_keys (priv->table);
key = g_list_first (keys);
while (key) {
key_string = g_string_append (key_string, key->data);
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
if (! (priv && name) ) return 0;
if (priv->expired) {
luaL_error(L,"expired private_table");
return 0;
}
string = g_hash_table_lookup (priv->table, (gpointer) name);
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
if (! (priv && name) ) return 0;
if (priv->expired) {
luaL_error(L,"expired private_table");
return 0;
}
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
g_hash_table_remove (priv->table, (gpointer) name);
}
return 1;
}
static int PrivateTable__gc(lua_State* L) {
PrivateTable priv = checkPrivateTable(L,1);
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
return 1;
}
static int Pinfo_tostring(lua_State *L) { lua_pushstring(L,"a Pinfo"); return 1; }
static int Pinfo_match(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
if (!pinfo) return 0;
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
if (pinfo->ws_pinfo->match_string) {
lua_pushstring(L,pinfo->ws_pinfo->match_string);
} else {
lua_pushnumber(L,(lua_Number)(pinfo->ws_pinfo->match_uint));
}
return 1;
}
static int Pinfo_columns(lua_State *L) {
Columns cols = NULL;
Pinfo pinfo = checkPinfo(L,1);
const gchar* colname = luaL_optstring(L,2,NULL);
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
cols = g_malloc(sizeof(struct _wslua_cols));
cols->cinfo = pinfo->ws_pinfo->cinfo;
cols->expired = FALSE;
if (!colname) {
PUSH_COLUMNS(L,cols);
} else {
lua_settop(L,0);
PUSH_COLUMNS(L,cols);
lua_pushstring(L,colname);
return Columns_index(L);
}
return 1;
}
static int Pinfo_private(lua_State *L) {
PrivateTable priv = NULL;
Pinfo pinfo = checkPinfo(L,1);
const gchar* privname = luaL_optstring(L,2,NULL);
gboolean is_allocated = FALSE;
if (!pinfo) return 0;
if (pinfo->expired) {
luaL_error(L,"expired private_table");
return 0;
}
if (!pinfo->ws_pinfo->private_table) {
pinfo->ws_pinfo->private_table = g_hash_table_new(g_str_hash,g_str_equal);
is_allocated = TRUE;
}
priv = g_malloc(sizeof(struct _wslua_private_table));
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
static int pushnil_param(lua_State* L, packet_info* pinfo _U_, pinfo_param_type_t pt _U_ ) {
lua_pushnil(L);
return 1;
}
static int Pinfo_set_addr(lua_State* L, packet_info* pinfo, pinfo_param_type_t pt) {
const address* from = checkAddress(L,1);
address* to;
if (! from ) {
luaL_error(L,"Not an OK address");
return 0;
}
if (!pinfo) {
luaL_error(L,"expired_pinfo");
return 0;
}
switch(pt) {
case PARAM_ADDR_SRC:
to = &(pinfo->src);
break;
case PARAM_ADDR_DST:
to = &(pinfo->dst);
break;
case PARAM_ADDR_DL_SRC:
to = &(pinfo->dl_src);
break;
case PARAM_ADDR_DL_DST:
to = &(pinfo->dl_dst);
break;
case PARAM_ADDR_NET_SRC:
to = &(pinfo->net_src);
break;
case PARAM_ADDR_NET_DST:
to = &(pinfo->net_dst);
break;
default:
g_assert(!"BUG: A bad parameter");
return 0;
}
COPY_ADDRESS(to,from);
return 0;
}
static int Pinfo_set_int(lua_State* L, packet_info* pinfo, pinfo_param_type_t pt) {
gint64 v = luaL_checkint(L,1);
if (!pinfo) {
luaL_error(L,"expired_pinfo");
return 0;
}
switch(pt) {
case PARAM_PORT_SRC:
pinfo->srcport = (guint32)v;
return 0;
case PARAM_PORT_DST:
pinfo->destport = (guint32)v;
return 0;
case PARAM_CIRCUIT_ID:
pinfo->circuit_id = (guint32)v;
return 0;
case PARAM_DESEGMENT_LEN:
pinfo->desegment_len = (guint32)v;
return 0;
case PARAM_DESEGMENT_OFFSET:
pinfo->desegment_offset = (int)v;
return 0;
case PARAM_ETHERTYPE:
pinfo->ethertype = (guint32)v;
return 0;
default:
g_assert(!"BUG: A bad parameter");
}
return 0;
}
static int Pinfo_hi(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Address addr;
if (!pinfo) return 0;
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
addr = g_malloc(sizeof(address));
if (CMP_ADDRESS(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) >= 0) {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->src));
} else {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->dst));
}
pushAddress(L,addr);
return 1;
}
static int Pinfo_lo(lua_State *L) {
Pinfo pinfo = checkPinfo(L,1);
Address addr;
if (!pinfo) return 0;
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
addr = g_malloc(sizeof(address));
if (CMP_ADDRESS(&(pinfo->ws_pinfo->src), &(pinfo->ws_pinfo->dst) ) < 0) {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->src));
} else {
COPY_ADDRESS(addr, &(pinfo->ws_pinfo->dst));
}
pushAddress(L,addr);
return 1;
}
static int pushnil(lua_State* L) {
lua_pushnil(L);
return 1;
}
static int Pinfo_index(lua_State* L) {
Pinfo pinfo = checkPinfo(L,1);
const gchar* name = luaL_checkstring(L,2);
lua_CFunction method = pushnil;
const pinfo_method_t* curr;
if (! (pinfo && name) ) {
lua_pushnil(L);
return 1;
}
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
for (curr = Pinfo_methods ; curr->name ; curr++) {
if (g_str_equal(curr->name,name)) {
method = curr->get;
break;
}
}
lua_settop(L,1);
return method(L);
}
static int Pinfo_setindex(lua_State* L) {
Pinfo pinfo = checkPinfo(L,1);
const gchar* name = luaL_checkstring(L,2);
int (*method)(lua_State*, packet_info* pinfo, pinfo_param_type_t) = pushnil_param;
const pinfo_method_t* curr;
pinfo_param_type_t param_type = PARAM_NONE;
if (! (pinfo && name) ) {
return 0;
}
if (pinfo->expired) {
luaL_error(L,"expired_pinfo");
return 0;
}
for (curr = Pinfo_methods ; curr->name ; curr++) {
if (g_str_equal(curr->name,name)) {
method = curr->set;
param_type = curr->param;
break;
}
}
lua_remove(L,1);
lua_remove(L,1);
return method(L,pinfo->ws_pinfo,param_type);
}
static int Pinfo_gc(lua_State* L) {
Pinfo pinfo = checkPinfo(L,1);
if (!pinfo) return 0;
if (!pinfo->expired)
pinfo->expired = TRUE;
else
g_free(pinfo);
return 0;
}
int Pinfo_register(lua_State* L) {
WSLUA_REGISTER_META(Pinfo);
outstanding_Pinfo = g_ptr_array_new();
outstanding_Column = g_ptr_array_new();
outstanding_Columns = g_ptr_array_new();
outstanding_PrivateTable = g_ptr_array_new();
return 1;
}
