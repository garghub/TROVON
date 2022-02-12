WSLUA_CONSTRUCTOR ByteArray_new(lua_State* L) {
#define WSLUA_OPTARG_ByteArray_new_HEXBYTES 1
GByteArray* ba = g_byte_array_new();
const gchar* s;
int nibble[2];
int i = 0;
gchar c;
if (lua_gettop(L) == 1) {
s = luaL_checkstring(L,WSLUA_OPTARG_ByteArray_new_HEXBYTES);
if (!s)
WSLUA_OPTARG_ERROR(ByteArray_new,HEXBYTES,"must be a string");
for (; (c = *s); s++) {
switch(c) {
case '0': case '1': case '2': case '3': case '4': case '5' : case '6' : case '7': case '8' : case '9' :
nibble[(i++)%2] = c - '0';
break;
case 'a': case 'b': case 'c': case 'd': case 'e': case 'f' :
nibble[(i++)%2] = c - 'a' + 0xa;
break;
case 'A': case 'B': case 'C': case 'D': case 'E': case 'F' :
nibble[(i++)%2] = c - 'A' + 0xa;
break;
default:
break;
}
if ( i == 2 ) {
guint8 b = (guint8)(nibble[0] * 16 + nibble[1]);
g_byte_array_append(ba,&b,1);
i = 0;
}
}
}
pushByteArray(L,ba);
WSLUA_RETURN(1);
}
static int ByteArray_gc(lua_State* L) {
ByteArray ba = checkByteArray(L,1);
if (!ba) return 0;
g_byte_array_free(ba,TRUE);
return 0;
}
WSLUA_METAMETHOD ByteArray__concat(lua_State* L) {
#define WSLUA_ARG_ByteArray__cat_FIRST 1
#define WSLUA_ARG_ByteArray__cat_SECOND 2
ByteArray ba = checkByteArray(L,WSLUA_ARG_ByteArray__cat_FIRST);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray__cat_SECOND);
if (! (ba && ba2) )
WSLUA_ERROR(ByteArray__cat,"Both arguments must be ByteArrays");
g_byte_array_append(ba,ba2->data,ba2->len);
pushByteArray(L,ba);
WSLUA_RETURN(1);
}
WSLUA_METHOD ByteArray_prepend(lua_State* L) {
#define WSLUA_ARG_ByteArray_prepend_PREPENDED 2
ByteArray ba = checkByteArray(L,1);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray_prepend_PREPENDED);
if (! (ba && ba2) )
WSLUA_ERROR(ByteArray_prepend,"Both arguments must be ByteArrays");
g_byte_array_prepend(ba,ba2->data,ba2->len);
pushByteArray(L,ba);
return 1;
}
WSLUA_METHOD ByteArray_append(lua_State* L) {
#define WSLUA_ARG_ByteArray_append_APPENDED 2
ByteArray ba = checkByteArray(L,1);
ByteArray ba2 = checkByteArray(L,WSLUA_ARG_ByteArray_append_APPENDED);
if (! (ba && ba2) )
WSLUA_ERROR(ByteArray_append,"Both arguments must be ByteArrays");
g_byte_array_append(ba,ba2->data,ba2->len);
pushByteArray(L,ba);
return 1;
}
WSLUA_METHOD ByteArray_set_size(lua_State* L) {
#define WSLUA_ARG_ByteArray_set_size_SIZE 2
ByteArray ba = checkByteArray(L,1);
int siz = luaL_checkint(L,WSLUA_ARG_ByteArray_set_size_SIZE);
guint8* padding;
if (!ba) return 0;
if (siz < 0)
WSLUA_ERROR(ByteArray_set_size,"ByteArray size must be non-negative");
if (ba->len >= (guint)siz) {
g_byte_array_set_size(ba,siz);
} else {
padding = g_malloc0(sizeof(guint8)*(siz - ba->len));
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
if (!ba) return 0;
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
if (!ba) return 0;
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
if (!ba) return 0;
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
if (!ba) return 0;
if ((offset + len) > (int)ba->len || offset < 0 || len < 1) {
luaL_error(L,"Out Of Bounds");
return 0;
}
sub = g_byte_array_new();
g_byte_array_append(sub,ba->data + offset,len);
pushByteArray(L,sub);
WSLUA_RETURN(1);
}
static int ByteArray_tostring(lua_State* L) {
static const gchar* byte_to_str[] = {
"00","01","02","03","04","05","06","07","08","09","0A","0B","0C","0D","0E","0F",
"10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F",
"20","21","22","23","24","25","26","27","28","29","2A","2B","2C","2D","2E","2F",
"30","31","32","33","34","35","36","37","38","39","3A","3B","3C","3D","3E","3F",
"40","41","42","43","44","45","46","47","48","49","4A","4B","4C","4D","4E","4F",
"50","51","52","53","54","55","56","57","58","59","5A","5B","5C","5D","5E","5F",
"60","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F",
"70","71","72","73","74","75","76","77","78","79","7A","7B","7C","7D","7E","7F",
"80","81","82","83","84","85","86","87","88","89","8A","8B","8C","8D","8E","8F",
"90","91","92","93","94","95","96","97","98","99","9A","9B","9C","9D","9E","9F",
"A0","A1","A2","A3","A4","A5","A6","A7","A8","A9","AA","AB","AC","AD","AE","AF",
"B0","B1","B2","B3","B4","B5","B6","B7","B8","B9","BA","BB","BC","BD","BE","BF",
"C0","C1","C2","C3","C4","C5","C6","C7","C8","C9","CA","CB","CC","CD","CE","CF",
"D0","D1","D2","D3","D4","D5","D6","D7","D8","D9","DA","DB","DC","DD","DE","DF",
"E0","E1","E2","E3","E4","E5","E6","E7","E8","E9","EA","EB","EC","ED","EE","EF",
"F0","F1","F2","F3","F4","F5","F6","F7","F8","F9","FA","FB","FC","FD","FE","FF"
};
ByteArray ba = checkByteArray(L,1);
int i;
GString* s;
if (!ba) return 0;
s = g_string_new("");
for (i = 0; i < (int)ba->len; i++) {
g_string_append(s,byte_to_str[(ba->data)[i]]);
}
lua_pushstring(L,s->str);
g_string_free(s,TRUE);
WSLUA_RETURN(1);
}
int ByteArray_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ByteArray);
return 1;
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
Tvb tvb = g_malloc(sizeof(struct _wslua_tvb));
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
if (!ba) return 0;
if (!lua_tvb) {
luaL_error(L,"Tvbs can only be created and used in dissectors");
return 0;
}
data = g_memdup(ba->data, ba->len);
tvb = g_malloc(sizeof(struct _wslua_tvb));
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
tvb = g_malloc(sizeof(struct _wslua_tvb));
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
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
len = tvb_length(tvb->ws_tvb);
str = ep_strdup_printf("TVB(%i) : %s",len,tvb_bytes_to_str(tvb->ws_tvb,0,len));
lua_pushstring(L,str);
WSLUA_RETURN(1);
}
static int Tvb__gc(lua_State* L) {
Tvb tvb = checkTvb(L,1);
free_Tvb(tvb);
return 0;
}
WSLUA_METHOD Tvb_reported_len(lua_State* L) {
Tvb tvb = checkTvb(L,1);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,tvb_reported_length(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_len(lua_State* L) {
Tvb tvb = checkTvb(L,1);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,tvb_length(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_reported_length_remaining(lua_State* L) {
#define Tvb_reported_length_remaining_OFFSET 2
Tvb tvb = checkTvb(L,1);
int offset = luaL_optint(L, Tvb_reported_length_remaining_OFFSET, 0);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,tvb_reported_length_remaining(tvb->ws_tvb, offset));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_offset(lua_State* L) {
Tvb tvb = checkTvb(L,1);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushnumber(L,tvb_raw_offset(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Tvb__call(lua_State* L) {
return 0;
}
WSLUA_METAMETHOD wslua__concat(lua_State* L) {
if (!luaL_callmeta(L,1,"__tostring"))
lua_pushvalue(L,1);
if (!luaL_callmeta(L,2,"__tostring"))
lua_pushvalue(L,2);
lua_concat(L,2);
return 1;
}
static TvbRange new_TvbRange(lua_State* L, tvbuff_t* ws_tvb, int offset, int len) {
TvbRange tvbr;
if (!ws_tvb) {
luaL_error(L,"expired tvb");
return 0;
}
if (len == -1) {
len = tvb_length_remaining(ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return 0;
}
} else if ( (guint)(len + offset) > tvb_length(ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return NULL;
}
tvbr = g_malloc(sizeof(struct _wslua_tvbrange));
tvbr->tvb = g_malloc(sizeof(struct _wslua_tvb));
tvbr->tvb->ws_tvb = ws_tvb;
tvbr->tvb->expired = FALSE;
tvbr->tvb->need_free = FALSE;
tvbr->offset = offset;
tvbr->len = len;
return tvbr;
}
WSLUA_METHOD Tvb_range(lua_State* L) {
#define WSLUA_OPTARG_Tvb_range_OFFSET 2
#define WSLUA_OPTARG_Tvb_range_LENGTH 3
Tvb tvb = checkTvb(L,1);
int offset = luaL_optint(L,WSLUA_OPTARG_Tvb_range_OFFSET,0);
int len = luaL_optint(L,WSLUA_OPTARG_Tvb_range_LENGTH,-1);
TvbRange tvbr;
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((tvbr = new_TvbRange(L,tvb->ws_tvb,offset,len))) {
PUSH_TVBRANGE(L,tvbr);
WSLUA_RETURN(1);
}
return 0;
}
int Tvb_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Tvb);
return 1;
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
lua_pushnumber(L,(lua_Number)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
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
UInt64 num = g_malloc(sizeof(guint64));
*num = tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset);
pushUInt64(L,num);
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
UInt64 num = g_malloc(sizeof(guint64));
*num = tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset);
pushUInt64(L,num);
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
Int64 num = g_malloc(sizeof(gint64));
*num = (gint64)tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset);
pushInt64(L,num);
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
Int64 num = g_malloc(sizeof(gint64));
*num = (gint64)tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset);
pushInt64(L,num);
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
if (tvbr->len != 4)
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
addr = g_malloc(sizeof(address));
ip_addr = g_malloc(sizeof(guint32));
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
if (tvbr->len != 4)
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
addr = g_malloc(sizeof(address));
ip_addr = g_malloc(sizeof(guint32));
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
if (tvbr->len != 6)
WSLUA_ERROR(TvbRange_ether,"The range must be 6 bytes long");
addr = g_new(address,1);
buff = tvb_memdup(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len);
SET_ADDRESS(addr, AT_ETHER, 6, buff);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_nstime(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
NSTime nstime;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
nstime = g_new(nstime_t,1);
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
WSLUA_RETURN(1);
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
TvbRange tvbr = checkTvbRange(L,1);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushlstring(L, (gchar*)tvb_get_ephemeral_string(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len), tvbr->len );
WSLUA_RETURN(1);
}
static int TvbRange_ustring_any(lua_State* L, gboolean little_endian) {
TvbRange tvbr = checkTvbRange(L,1);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushlstring(L, (gchar*)tvb_get_ephemeral_unicode_string(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,(little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN)), tvbr->len );
return 1;
}
WSLUA_METHOD TvbRange_ustring(lua_State* L) {
WSLUA_RETURN(TvbRange_ustring_any(L, FALSE));
}
WSLUA_METHOD TvbRange_le_ustring(lua_State* L) {
WSLUA_RETURN(TvbRange_ustring_any(L, TRUE));
}
WSLUA_METHOD TvbRange_stringz(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushstring(L, (gchar*)tvb_get_ephemeral_stringz(tvbr->tvb->ws_tvb,tvbr->offset,NULL) );
WSLUA_RETURN(1);
}
static int TvbRange_ustringz_any(lua_State* L, gboolean little_endian) {
gint count;
TvbRange tvbr = checkTvbRange(L,1);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushstring(L, (gchar*)tvb_get_ephemeral_unicode_stringz(tvbr->tvb->ws_tvb,tvbr->offset,&count,(little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN)) );
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
TvbRange tvbr = checkTvbRange(L,1);
GByteArray* ba;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
ba = g_byte_array_new();
g_byte_array_append(ba,ep_tvb_memdup(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len),tvbr->len);
pushByteArray(L,ba);
WSLUA_RETURN(1);
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
lua_pushnumber(L,(lua_Number)tvb_get_bits8(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len));
return 1;
} else if (len <= 16) {
lua_pushnumber(L,tvb_get_bits16(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE));
return 1;
} else if (len <= 32) {
lua_pushnumber(L,tvb_get_bits32(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE));
return 1;
} else if (len <= 64) {
UInt64 num = g_malloc(sizeof(guint64));
*num = tvb_get_bits64(tvbr->tvb->ws_tvb,tvbr->offset*8 + pos, len, FALSE);
pushUInt64(L,num);
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
if ((tvbr = new_TvbRange(L,tvbr->tvb->ws_tvb,tvbr->offset+offset,len))) {
PUSH_TVBRANGE(L,tvbr);
WSLUA_RETURN(1);
}
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
WSLUA_METAMETHOD TvbRange__tostring(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
lua_pushstring(L,tvb_bytes_to_str(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len));
return 1;
}
int TvbRange_register(lua_State* L) {
outstanding_Tvb = g_ptr_array_new();
outstanding_TvbRange = g_ptr_array_new();
WSLUA_REGISTER_CLASS(TvbRange);
return 1;
}
WSLUA_METAMETHOD Int64__tostring(lua_State* L) {
Int64 num = checkInt64(L,1);
lua_pushstring(L,ep_strdup_printf("%" G_GINT64_MODIFIER "d",(gint64)*(num)));
return 1;
}
static int Int64__gc(lua_State* L) {
Int64 num = checkInt64(L,1);
if (!num) return 0;
g_free(num);
return 0;
}
int Int64_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Int64);
return 1;
}
WSLUA_METAMETHOD UInt64__tostring(lua_State* L) {
UInt64 num = checkUInt64(L,1);
lua_pushstring(L,ep_strdup_printf("%" G_GINT64_MODIFIER "u",(guint64)*(num)));
return 1;
}
static int UInt64__gc(lua_State* L) {
UInt64 num = checkUInt64(L,1);
if (!num) return 0;
g_free(num);
return 0;
}
int UInt64_register(lua_State* L) {
WSLUA_REGISTER_CLASS(UInt64);
return 1;
}
