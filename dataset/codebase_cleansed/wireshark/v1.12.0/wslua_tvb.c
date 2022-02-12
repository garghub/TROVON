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
if (!s) {
WSLUA_OPTARG_ERROR(ByteArray_new,HEXBYTES,"must be a string");
return 0;
}
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
int siz = luaL_checkint(L,WSLUA_ARG_ByteArray_set_size_SIZE);
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
int idx = luaL_checkint(L,WSLUA_ARG_ByteArray_set_index_INDEX);
int v = luaL_checkint(L,WSLUA_ARG_ByteArray_set_index_VALUE);
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
int idx = luaL_checkint(L,WSLUA_ARG_ByteArray_get_index_INDEX);
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
int offset = luaL_checkint(L,WSLUA_ARG_ByteArray_set_index_OFFSET);
int len = luaL_checkint(L,WSLUA_ARG_ByteArray_set_index_LENGTH);
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
guint offset = (guint) luaL_optint(L,WSLUA_OPTARG_ByteArray_raw_OFFSET,0);
int len;
if (!ba) return 0;
if (offset > ba->len) {
WSLUA_OPTARG_ERROR(ByteArray_raw,OFFSET,"offset beyond end of byte array");
return 0;
}
len = luaL_optint(L,WSLUA_OPTARG_ByteArray_raw_LENGTH, ba->len - offset);
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
int ByteArray_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ByteArray);
return 0;
}
static void free_Tvb(Tvb tvb) {
if (!tvb) return;
if (!tvb->expired) {
tvb->expired = TRUE;
} else {
if (tvb->need_free)
tvb_free(tvb->ws_tvb);
g_free(tvb);
}
}
void clear_outstanding_Tvb(void) {
while (outstanding_Tvb->len) {
Tvb tvb = (Tvb)g_ptr_array_remove_index_fast(outstanding_Tvb,0);
free_Tvb(tvb);
}
}
static void free_TvbRange(TvbRange tvbr) {
if (!(tvbr && tvbr->tvb)) return;
if (!tvbr->tvb->expired) {
tvbr->tvb->expired = TRUE;
} else {
free_Tvb(tvbr->tvb);
g_free(tvbr);
}
}
void clear_outstanding_TvbRange(void) {
while (outstanding_TvbRange->len) {
TvbRange tvbr = (TvbRange)g_ptr_array_remove_index_fast(outstanding_TvbRange,0);
free_TvbRange(tvbr);
}
}
Tvb* push_Tvb(lua_State* L, tvbuff_t* ws_tvb) {
Tvb tvb = (Tvb)g_malloc(sizeof(struct _wslua_tvb));
tvb->ws_tvb = ws_tvb;
tvb->expired = FALSE;
tvb->need_free = FALSE;
g_ptr_array_add(outstanding_Tvb,tvb);
return pushTvb(L,tvb);
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
PUSH_TVB(L,tvb);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR TvbRange_tvb (lua_State *L) {
#define WSLUA_ARG_Tvb_new_subset_RANGE 1
TvbRange tvbr = checkTvbRange(L,WSLUA_ARG_Tvb_new_subset_RANGE);
Tvb tvb;
if (! (tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvb_offset_exists(tvbr->tvb->ws_tvb, tvbr->offset + tvbr->len -1 )) {
tvb = (Tvb)g_malloc(sizeof(struct _wslua_tvb));
tvb->expired = FALSE;
tvb->need_free = FALSE;
tvb->ws_tvb = tvb_new_subset(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len, tvbr->len);
PUSH_TVB(L, tvb);
return 1;
} else {
luaL_error(L,"Out Of Bounds");
return 0;
}
}
WSLUA_METAMETHOD Tvb__tostring(lua_State* L) {
Tvb tvb = checkTvb(L,1);
int len;
gchar* str;
len = tvb_length(tvb->ws_tvb);
str = ep_strdup_printf("TVB(%i) : %s",len,tvb_bytes_to_ep_str(tvb->ws_tvb,0,len));
lua_pushstring(L,str);
WSLUA_RETURN(1);
}
static int Tvb__gc(lua_State* L) {
Tvb tvb = toTvb(L,1);
free_Tvb(tvb);
return 0;
}
WSLUA_METHOD Tvb_reported_len(lua_State* L) {
Tvb tvb = checkTvb(L,1);
lua_pushnumber(L,tvb_reported_length(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_len(lua_State* L) {
Tvb tvb = checkTvb(L,1);
lua_pushnumber(L,tvb_length(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_reported_length_remaining(lua_State* L) {
#define Tvb_reported_length_remaining_OFFSET 2
Tvb tvb = checkTvb(L,1);
int offset = luaL_optint(L, Tvb_reported_length_remaining_OFFSET, 0);
lua_pushnumber(L,tvb_reported_length_remaining(tvb->ws_tvb, offset));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_offset(lua_State* L) {
Tvb tvb = checkTvb(L,1);
lua_pushnumber(L,tvb_raw_offset(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Tvb__call(lua_State* L) {
return 0;
}
gboolean push_TvbRange(lua_State* L, tvbuff_t* ws_tvb, int offset, int len) {
TvbRange tvbr;
if (!ws_tvb) {
luaL_error(L,"expired tvb");
return FALSE;
}
if (len == -1) {
len = tvb_length_remaining(ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_length(ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return FALSE;
}
tvbr = (TvbRange)g_malloc(sizeof(struct _wslua_tvbrange));
tvbr->tvb = (Tvb)g_malloc(sizeof(struct _wslua_tvb));
tvbr->tvb->ws_tvb = ws_tvb;
tvbr->tvb->expired = FALSE;
tvbr->tvb->need_free = FALSE;
tvbr->offset = offset;
tvbr->len = len;
PUSH_TVBRANGE(L,tvbr);
return TRUE;
}
WSLUA_METHOD Tvb_range(lua_State* L) {
#define WSLUA_OPTARG_Tvb_range_OFFSET 2
#define WSLUA_OPTARG_Tvb_range_LENGTH 3
Tvb tvb = checkTvb(L,1);
int offset = luaL_optint(L,WSLUA_OPTARG_Tvb_range_OFFSET,0);
int len = luaL_optint(L,WSLUA_OPTARG_Tvb_range_LENGTH,-1);
if (push_TvbRange(L,tvb->ws_tvb,offset,len)) {
WSLUA_RETURN(1);
}
return 0;
}
WSLUA_METHOD Tvb_raw(lua_State* L) {
#define WSLUA_OPTARG_Tvb_raw_OFFSET 2
#define WSLUA_OPTARG_Tvb_raw_LENGTH 3
Tvb tvb = checkTvb(L,1);
int offset = luaL_optint(L,WSLUA_OPTARG_Tvb_raw_OFFSET,0);
int len = luaL_optint(L,WSLUA_OPTARG_Tvb_raw_LENGTH,-1);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((guint)offset > tvb_length(tvb->ws_tvb)) {
WSLUA_OPTARG_ERROR(Tvb_raw,OFFSET,"offset beyond end of Tvb");
return 0;
}
if (len == -1) {
len = tvb_length_remaining(tvb->ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_length(tvb->ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return FALSE;
}
lua_pushlstring(L, tvb_get_ptr(tvb->ws_tvb, offset, len), len);
WSLUA_RETURN(1);
}
int Tvb_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Tvb);
return 0;
}
WSLUA_METHOD TvbRange_uint(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
lua_pushnumber(L,tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
lua_pushnumber(L,tvb_get_ntohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
lua_pushnumber(L,tvb_get_ntoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
lua_pushnumber(L,tvb_get_ntohl(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:uint() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_le_uint(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
lua_pushnumber(L,(lua_Number)(guint)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
lua_pushnumber(L,tvb_get_letohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
lua_pushnumber(L,tvb_get_letoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
lua_pushnumber(L,tvb_get_letohl(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:le_uint() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_uint64(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8: {
pushUInt64(L,tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
}
default:
luaL_error(L,"TvbRange:uint64() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_le_uint64(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8: {
pushUInt64(L,tvb_get_letoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
}
default:
luaL_error(L,"TvbRange:le_uint64() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_int(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
lua_pushnumber(L,(gchar)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
lua_pushnumber(L,(gshort)tvb_get_ntohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
lua_pushnumber(L,(gint)tvb_get_ntohl(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:int() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_le_int(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
lua_pushnumber(L,(gchar)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
lua_pushnumber(L,(gshort)tvb_get_letohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
lua_pushnumber(L,(gint)tvb_get_letohl(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:le_int() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_int64(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8: {
pushInt64(L,(gint64)tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
}
default:
luaL_error(L,"TvbRange:int64() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_le_int64(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8: {
pushInt64(L,(gint64)tvb_get_letoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
}
default:
luaL_error(L,"TvbRange:le_int64() does not handle %d byte integers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_float(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (tvbr->len) {
case 4:
lua_pushnumber(L,(double)tvb_get_ntohieee_float(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
lua_pushnumber(L,tvb_get_ntohieee_double(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:float() does not handle %d byte floating numbers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_le_float(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
switch (tvbr->len) {
case 4:
lua_pushnumber(L,tvb_get_letohieee_float(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
lua_pushnumber(L,tvb_get_letohieee_double(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
default:
luaL_error(L,"TvbRange:le_float() does not handle %d byte floating numbers",tvbr->len);
return 0;
}
}
WSLUA_METHOD TvbRange_ipv4(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
guint32* ip_addr;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 4) {
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
return 0;
}
addr = (address *)g_malloc(sizeof(address));
ip_addr = (guint32 *)g_malloc(sizeof(guint32));
*ip_addr = tvb_get_ipv4(tvbr->tvb->ws_tvb,tvbr->offset);
SET_ADDRESS(addr, AT_IPv4, 4, ip_addr);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_le_ipv4(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
guint32* ip_addr;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 4) {
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
return 0;
}
addr = (address *)g_malloc(sizeof(address));
ip_addr = (guint32 *)g_malloc(sizeof(guint32));
*ip_addr = tvb_get_ipv4(tvbr->tvb->ws_tvb,tvbr->offset);
*((guint32 *)ip_addr) = GUINT32_SWAP_LE_BE(*((guint32 *)ip_addr));
SET_ADDRESS(addr, AT_IPv4, 4, ip_addr);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_ether(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
guint8* buff;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 6) {
WSLUA_ERROR(TvbRange_ether,"The range must be 6 bytes long");
return 0;
}
addr = g_new(address,1);
buff = (guint8 *)tvb_memdup(NULL,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len);
SET_ADDRESS(addr, AT_ETHER, 6, buff);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_nstime(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_nstime_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
NSTime nstime;
const guint encoding = luaL_optint(L, WSLUA_OPTARG_TvbRange_nstime_ENCODING, 0);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
nstime = g_new(nstime_t,1);
if (encoding == 0) {
if (tvbr->len == 4) {
nstime->secs = tvb_get_ntohl(tvbr->tvb->ws_tvb, tvbr->offset);
nstime->nsecs = 0;
} else if (tvbr->len == 8) {
nstime->secs = tvb_get_ntohl(tvbr->tvb->ws_tvb, tvbr->offset);
nstime->nsecs = tvb_get_ntohl(tvbr->tvb->ws_tvb, tvbr->offset + 4);
} else {
g_free(nstime);
WSLUA_ERROR(TvbRange_nstime,"The range must be 4 or 8 bytes long");
return 0;
}
pushNSTime(L, nstime);
lua_pushinteger(L, tvbr->len);
}
else if (encoding & ~ENC_STR_TIME_MASK) {
WSLUA_OPTARG_ERROR(TvbRange_nstime, ENCODING, "invalid encoding value");
}
else {
gint endoff = 0;
nstime_t *retval = tvb_get_string_time(tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len,
encoding, nstime, &endoff);
if (!retval || endoff == 0) {
g_free(nstime);
lua_pushnil(L);
lua_pushnil(L);
}
else {
pushNSTime(L, nstime);
lua_pushinteger(L, endoff);
}
}
WSLUA_RETURN(2);
}
WSLUA_METHOD TvbRange_le_nstime(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
NSTime nstime;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
nstime = g_new(nstime_t,1);
if (tvbr->len == 4) {
nstime->secs = tvb_get_letohl(tvbr->tvb->ws_tvb, tvbr->offset);
nstime->nsecs = 0;
} else if (tvbr->len == 8) {
nstime->secs = tvb_get_letohl(tvbr->tvb->ws_tvb, tvbr->offset);
nstime->nsecs = tvb_get_letohl(tvbr->tvb->ws_tvb, tvbr->offset + 4);
} else {
g_free(nstime);
WSLUA_ERROR(TvbRange_nstime,"The range must be 4 or 8 bytes long");
return 0;
}
pushNSTime(L, nstime);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_string(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_string_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
guint encoding = (guint)luaL_optint(L,WSLUA_OPTARG_TvbRange_string_ENCODING, ENC_ASCII|ENC_NA);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushlstring(L, (gchar*)tvb_get_string_enc(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,encoding), tvbr->len);
WSLUA_RETURN(1);
}
static int TvbRange_ustring_any(lua_State* L, gboolean little_endian) {
TvbRange tvbr = checkTvbRange(L,1);
gchar * str;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
str = (gchar*)tvb_get_string_enc(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,(little_endian ? ENC_UTF_16|ENC_LITTLE_ENDIAN : ENC_UTF_16|ENC_BIG_ENDIAN));
lua_pushlstring(L, str, strlen(str));
return 1;
}
WSLUA_METHOD TvbRange_ustring(lua_State* L) {
WSLUA_RETURN(TvbRange_ustring_any(L, FALSE));
}
WSLUA_METHOD TvbRange_le_ustring(lua_State* L) {
WSLUA_RETURN(TvbRange_ustring_any(L, TRUE));
}
WSLUA_METHOD TvbRange_stringz(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_stringz_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
guint encoding = (guint)luaL_optint(L,WSLUA_OPTARG_TvbRange_stringz_ENCODING, ENC_ASCII|ENC_NA);
gint offset;
gunichar2 uchar;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_UTF_16:
case ENC_UCS_2:
offset = tvbr->offset;
do {
if (!tvb_bytes_exist (tvbr->tvb->ws_tvb, offset, 2)) {
luaL_error(L,"out of bounds");
return 0;
}
uchar = tvb_get_ntohs (tvbr->tvb->ws_tvb, offset);
offset += 2;
} while(uchar != 0);
break;
default:
if (tvb_find_guint8 (tvbr->tvb->ws_tvb, tvbr->offset, -1, 0) == -1) {
luaL_error(L,"out of bounds");
return 0;
}
break;
}
lua_pushstring(L, (gchar*)tvb_get_stringz_enc(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,NULL,encoding));
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_strsize(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_strsize_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
guint encoding = (guint)luaL_optint(L,WSLUA_OPTARG_TvbRange_strsize_ENCODING, ENC_ASCII|ENC_NA);
gint offset;
gunichar2 uchar;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_UTF_16:
case ENC_UCS_2:
offset = tvbr->offset;
do {
if (!tvb_bytes_exist (tvbr->tvb->ws_tvb, offset, 2)) {
luaL_error(L,"out of bounds");
return 0;
}
uchar = tvb_get_ntohs (tvbr->tvb->ws_tvb, offset);
offset += 2;
} while (uchar != 0);
lua_pushinteger(L, tvb_unicode_strsize(tvbr->tvb->ws_tvb, tvbr->offset));
break;
default:
if (tvb_find_guint8 (tvbr->tvb->ws_tvb, tvbr->offset, -1, 0) == -1) {
luaL_error(L,"out of bounds");
return 0;
}
lua_pushinteger(L, tvb_strsize(tvbr->tvb->ws_tvb, tvbr->offset));
break;
}
WSLUA_RETURN(1);
}
static int TvbRange_ustringz_any(lua_State* L, gboolean little_endian) {
gint count;
TvbRange tvbr = checkTvbRange(L,1);
gint offset;
gunichar2 uchar;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
offset = tvbr->offset;
do {
if (!tvb_bytes_exist (tvbr->tvb->ws_tvb, offset, 2)) {
luaL_error(L,"out of bounds");
return 0;
}
uchar = tvb_get_ntohs (tvbr->tvb->ws_tvb, offset);
offset += 2;
} while (uchar != 0);
lua_pushstring(L, (gchar*)tvb_get_stringz_enc(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,&count,
(little_endian ? ENC_UTF_16|ENC_LITTLE_ENDIAN : ENC_UTF_16|ENC_BIG_ENDIAN)) );
lua_pushinteger(L,count);
return 2;
}
WSLUA_METHOD TvbRange_ustringz(lua_State* L) {
WSLUA_RETURN(TvbRange_ustringz_any(L, FALSE));
}
WSLUA_METHOD TvbRange_le_ustringz(lua_State* L) {
WSLUA_RETURN(TvbRange_ustringz_any(L, TRUE));
}
WSLUA_METHOD TvbRange_bytes(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_bytes_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
GByteArray* ba;
const guint encoding = luaL_optint(L, WSLUA_OPTARG_TvbRange_bytes_ENCODING, 0);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
ba = g_byte_array_new();
if (encoding == 0) {
g_byte_array_append(ba,(const guint8 *)tvb_memdup(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len),tvbr->len);
pushByteArray(L,ba);
lua_pushinteger(L, tvbr->len);
}
else if ((encoding & ENC_STR_HEX) == 0) {
WSLUA_OPTARG_ERROR(TvbRange_nstime, ENCODING, "invalid encoding value");
}
else {
gint endoff = 0;
GByteArray* retval = tvb_get_string_bytes(tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len,
encoding, ba, &endoff);
if (!retval || endoff == 0) {
g_byte_array_free(ba, TRUE);
lua_pushnil(L);
lua_pushnil(L);
}
else {
pushByteArray(L,ba);
lua_pushinteger(L, endoff);
}
}
WSLUA_RETURN(2);
}
WSLUA_METHOD TvbRange_bitfield(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_bitfield_POSITION 2
#define WSLUA_OPTARG_TvbRange_bitfield_LENGTH 3
TvbRange tvbr = checkTvbRange(L,1);
int pos = luaL_optint(L,WSLUA_OPTARG_TvbRange_bitfield_POSITION,0);
int len = luaL_optint(L,WSLUA_OPTARG_TvbRange_bitfield_LENGTH,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((pos+len) > (tvbr->len<<3)) {
luaL_error(L, "Requested bitfield out of range");
return 0;
}
if (len <= 8) {
lua_pushnumber(L,(lua_Number)(guint)tvb_get_bits8(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len));
return 1;
} else if (len <= 16) {
lua_pushnumber(L,tvb_get_bits16(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE));
return 1;
} else if (len <= 32) {
lua_pushnumber(L,tvb_get_bits32(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE));
return 1;
} else if (len <= 64) {
pushUInt64(L,tvb_get_bits64(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE));
WSLUA_RETURN(1);
} else {
luaL_error(L,"TvbRange:bitfield() does not handle %d bits",len);
return 0;
}
}
WSLUA_METHOD TvbRange_range(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_range_OFFSET 2
#define WSLUA_OPTARG_TvbRange_range_LENGTH 3
TvbRange tvbr = checkTvbRange(L,1);
int offset = luaL_optint(L,WSLUA_OPTARG_TvbRange_range_OFFSET,0);
int len;
if (!(tvbr && tvbr->tvb)) return 0;
len = luaL_optint(L,WSLUA_OPTARG_TvbRange_range_LENGTH,tvbr->len-offset);
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (offset >= tvbr->len || (len + offset) > tvbr->len) {
luaL_error(L,"Range is out of bounds");
return 0;
}
if (push_TvbRange(L,tvbr->tvb->ws_tvb,tvbr->offset+offset,len)) {
WSLUA_RETURN(1);
}
return 0;
}
static int TvbRange_uncompress(lua_State* L) {
#define WSLUA_ARG_TvbRange_uncompress_NAME 2
TvbRange tvbr = checkTvbRange(L,1);
#ifdef HAVE_LIBZ
const gchar* name = luaL_optstring(L,WSLUA_ARG_TvbRange_uncompress_NAME,"Uncompressed");
tvbuff_t *uncompr_tvb;
#endif
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
#ifdef HAVE_LIBZ
uncompr_tvb = tvb_child_uncompress(tvbr->tvb->ws_tvb, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len);
if (uncompr_tvb) {
add_new_data_source (lua_pinfo, uncompr_tvb, name);
if (push_TvbRange(L,uncompr_tvb,0,tvb_length(uncompr_tvb))) {
WSLUA_RETURN(1);
}
}
#else
luaL_error(L,"Missing support for ZLIB");
#endif
return 0;
}
static int TvbRange__gc(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
free_TvbRange(tvbr);
return 0;
}
WSLUA_METHOD TvbRange_len(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,(lua_Number)tvbr->len);
return 1;
}
WSLUA_METHOD TvbRange_offset(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,(lua_Number)tvbr->offset);
return 1;
}
WSLUA_METHOD TvbRange_raw(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_raw_OFFSET 2
#define WSLUA_OPTARG_TvbRange_raw_LENGTH 3
TvbRange tvbr = checkTvbRange(L,1);
int offset = luaL_optint(L,WSLUA_OPTARG_TvbRange_raw_OFFSET,0);
int len = luaL_optint(L,WSLUA_OPTARG_TvbRange_raw_LENGTH,-1);
if (!tvbr || !tvbr->tvb) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((guint)offset > tvb_length(tvbr->tvb->ws_tvb)) {
WSLUA_OPTARG_ERROR(Tvb_raw,OFFSET,"offset beyond end of Tvb");
return 0;
}
if (len == -1) {
len = tvb_length_remaining(tvbr->tvb->ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_length(tvbr->tvb->ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return FALSE;
}
lua_pushlstring(L, tvb_get_ptr(tvbr->tvb->ws_tvb, offset, len), len);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD TvbRange__tostring(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushstring(L,tvb_bytes_to_ep_str(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len));
return 1;
}
int TvbRange_register(lua_State* L) {
outstanding_Tvb = g_ptr_array_new();
outstanding_TvbRange = g_ptr_array_new();
WSLUA_REGISTER_CLASS(TvbRange);
return 0;
}
