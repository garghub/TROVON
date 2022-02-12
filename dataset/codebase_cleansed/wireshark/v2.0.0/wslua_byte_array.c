WSLUA_CONSTRUCTOR ByteArray_new(lua_State* L) {
#define WSLUA_OPTARG_ByteArray_new_HEXBYTES 1
#define WSLUA_OPTARG_ByteArray_new_SEPARATOR 2
GByteArray* ba = g_byte_array_new();
const gchar* s;
size_t len = 0;
const gchar* sep = " ";
gboolean ishex = TRUE;
if (lua_gettop(L) >= 1) {
s = luaL_checklstring(L,WSLUA_OPTARG_ByteArray_new_HEXBYTES,&len);
if (lua_gettop(L) >= 2) {
if (lua_type(L,2) == LUA_TBOOLEAN && lua_toboolean(L,2)) {
ishex = FALSE;
} else {
sep = luaL_optstring(L,WSLUA_OPTARG_ByteArray_new_SEPARATOR," ");
}
}
if (ishex) {
wslua_hex2bin(L, s, (guint)len, sep);
s = luaL_checklstring(L, -1, &len);
g_byte_array_append(ba,s,(guint)len);
lua_pop(L,1);
} else {
g_byte_array_append(ba,s,(guint)len);
}
}
pushByteArray(L,ba);
WSLUA_RETURN(1);
}
static int ByteArray__gc(lua_State* L) {
ByteArray ba = toByteArray(L,1);
if (!ba) return 0;
g_byte_array_free(ba,TRUE);
return 0;
}
WSLUA_METAMETHOD ByteArray__concat(lua_State* L) {
#define WSLUA_ARG_ByteArray__cat_FIRST 1
#define WSLUA_ARG_ByteArray__cat_SECOND 2
ByteArray ba1 = checkByteArray(L,WSLUA_ARG_ByteArray__cat_FIRST);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray__cat_SECOND);
ByteArray ba;
ba = g_byte_array_new();
g_byte_array_append(ba,ba1->data,ba1->len);
g_byte_array_append(ba,ba2->data,ba2->len);
pushByteArray(L,ba);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD ByteArray__eq(lua_State* L) {
#define WSLUA_ARG_ByteArray__eq_FIRST 1
#define WSLUA_ARG_ByteArray__eq_SECOND 2
ByteArray ba1 = checkByteArray(L,WSLUA_ARG_ByteArray__eq_FIRST);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray__eq_SECOND);
gboolean result = FALSE;
if (ba1->len == ba2->len) {
if (memcmp(ba1->data, ba2->data, ba1->len) == 0)
result = TRUE;
}
lua_pushboolean(L,result);
return 1;
}
WSLUA_METHOD ByteArray_prepend(lua_State* L) {
#define WSLUA_ARG_ByteArray_prepend_PREPENDED 2
ByteArray ba = checkByteArray(L,1);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray_prepend_PREPENDED);
g_byte_array_prepend(ba,ba2->data,ba2->len);
return 0;
}
WSLUA_METHOD ByteArray_append(lua_State* L) {
#define WSLUA_ARG_ByteArray_append_APPENDED 2
ByteArray ba = checkByteArray(L,1);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray_append_APPENDED);
g_byte_array_append(ba,ba2->data,ba2->len);
return 0;
}
WSLUA_METHOD ByteArray_set_size(lua_State* L) {
#define WSLUA_ARG_ByteArray_set_size_SIZE 2
ByteArray ba = checkByteArray(L,1);
int siz = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_set_size_SIZE);
guint8* padding;
if (siz < 0) {
WSLUA_ERROR(ByteArray_set_size,"ByteArray size must be non-negative");
return 0;
}
if (ba->len >= (guint)siz) {
g_byte_array_set_size(ba,siz);
} else {
padding = (guint8 *)g_malloc0(sizeof(guint8)*(siz - ba->len));
g_byte_array_append(ba,padding,siz - ba->len);
g_free(padding);
}
return 0;
}
WSLUA_METHOD ByteArray_set_index(lua_State* L) {
#define WSLUA_ARG_ByteArray_set_index_INDEX 2
#define WSLUA_ARG_ByteArray_set_index_VALUE 3
ByteArray ba = checkByteArray(L,1);
int idx = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_set_index_INDEX);
int v = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_set_index_VALUE);
if (idx == 0 && ! g_str_equal(luaL_optstring(L,2,""),"0") ) {
luaL_argerror(L,2,"bad index");
return 0;
}
if (idx < 0 || (guint)idx >= ba->len) {
luaL_argerror(L,2,"index out of range");
return 0;
}
if (v < 0 || v > 255) {
luaL_argerror(L,3,"Byte out of range");
return 0;
}
ba->data[idx] = (guint8)v;
return 0;
}
WSLUA_METHOD ByteArray_get_index(lua_State* L) {
#define WSLUA_ARG_ByteArray_get_index_INDEX 2
ByteArray ba = checkByteArray(L,1);
int idx = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_get_index_INDEX);
if (idx == 0 && ! g_str_equal(luaL_optstring(L,2,""),"0") ) {
luaL_argerror(L,2,"bad index");
return 0;
}
if (idx < 0 || (guint)idx >= ba->len) {
luaL_argerror(L,2,"index out of range");
return 0;
}
lua_pushnumber(L,ba->data[idx]);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_len(lua_State* L) {
ByteArray ba = checkByteArray(L,1);
lua_pushnumber(L,(lua_Number)ba->len);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_subset(lua_State* L) {
#define WSLUA_ARG_ByteArray_set_index_OFFSET 2
#define WSLUA_ARG_ByteArray_set_index_LENGTH 3
ByteArray ba = checkByteArray(L,1);
int offset = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_set_index_OFFSET);
int len = (int)luaL_checkinteger(L,WSLUA_ARG_ByteArray_set_index_LENGTH);
ByteArray sub;
if ((offset + len) > (int)ba->len || offset < 0 || len < 1) {
luaL_error(L,"Out Of Bounds");
return 0;
}
sub = g_byte_array_new();
g_byte_array_append(sub,ba->data + offset,len);
pushByteArray(L,sub);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_base64_decode(lua_State* L) {
ByteArray ba = checkByteArray(L,1);
ByteArray ba2;
gchar *data;
size_t len;
ba2 = g_byte_array_new();
data = (gchar*)g_malloc (ba->len + 1);
memcpy(data, ba->data, ba->len);
data[ba->len] = '\0';
len = ws_base64_decode_inplace(data);
g_byte_array_append(ba2,data,(int)len);
g_free(data);
pushByteArray(L,ba2);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_raw(lua_State* L) {
#define WSLUA_OPTARG_ByteArray_raw_OFFSET 2
#define WSLUA_OPTARG_ByteArray_raw_LENGTH 3
ByteArray ba = checkByteArray(L,1);
guint offset = (guint) luaL_optinteger(L,WSLUA_OPTARG_ByteArray_raw_OFFSET,0);
int len;
if (!ba) return 0;
if (offset > ba->len) {
WSLUA_OPTARG_ERROR(ByteArray_raw,OFFSET,"offset beyond end of byte array");
return 0;
}
len = (int) luaL_optinteger(L,WSLUA_OPTARG_ByteArray_raw_LENGTH, ba->len - offset);
if ((len < 0) || ((guint)len > (ba->len - offset)))
len = ba->len - offset;
lua_pushlstring(L, &(ba->data[offset]), len);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_tohex(lua_State* L) {
#define WSLUA_OPTARG_ByteArray_tohex_LOWERCASE 2
#define WSLUA_OPTARG_ByteArray_tohex_SEPARATOR 3
ByteArray ba = checkByteArray(L,1);
gboolean lowercase = FALSE;
const gchar* sep = NULL;
if (!ba) return 0;
lowercase = wslua_optbool(L,WSLUA_OPTARG_ByteArray_tohex_LOWERCASE,FALSE);
sep = luaL_optstring(L,WSLUA_OPTARG_ByteArray_tohex_SEPARATOR,NULL);
wslua_bin2hex(L, ba->data, ba->len, lowercase, sep);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD ByteArray__tostring(lua_State* L) {
ByteArray ba = checkByteArray(L,1);
if (!ba) return 0;
wslua_bin2hex(L, ba->data, ba->len, FALSE, NULL);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR ByteArray_tvb (lua_State *L) {
#define WSLUA_ARG_ByteArray_tvb_NAME 2
ByteArray ba = checkByteArray(L,1);
const gchar* name = luaL_optstring(L,WSLUA_ARG_ByteArray_tvb_NAME,"Unnamed") ;
guint8* data;
Tvb tvb;
if (!lua_tvb) {
luaL_error(L,"Tvbs can only be created and used in dissectors");
return 0;
}
data = (guint8 *)g_memdup(ba->data, ba->len);
tvb = (Tvb)g_malloc(sizeof(struct _wslua_tvb));
tvb->ws_tvb = tvb_new_real_data(data, ba->len,ba->len);
tvb->expired = FALSE;
tvb->need_free = TRUE;
tvb_set_free_cb(tvb->ws_tvb, g_free);
add_new_data_source(lua_pinfo, tvb->ws_tvb, name);
push_wsluaTvb(L,tvb);
WSLUA_RETURN(1);
}
int ByteArray_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ByteArray);
return 0;
}
