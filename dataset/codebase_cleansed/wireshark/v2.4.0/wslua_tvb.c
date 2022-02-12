int push_wsluaTvb(lua_State* L, Tvb t) {
g_ptr_array_add(outstanding_Tvb,t);
pushTvb(L,t);
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
Tvb* push_Tvb(lua_State* L, tvbuff_t* ws_tvb) {
Tvb tvb = (Tvb)g_malloc(sizeof(struct _wslua_tvb));
tvb->ws_tvb = ws_tvb;
tvb->expired = FALSE;
tvb->need_free = FALSE;
g_ptr_array_add(outstanding_Tvb,tvb);
return pushTvb(L,tvb);
}
WSLUA_METAMETHOD Tvb__tostring(lua_State* L) {
Tvb tvb = checkTvb(L,1);
int len = tvb_captured_length(tvb->ws_tvb);
char* str = tvb_bytes_to_str(NULL,tvb->ws_tvb,0,len);
lua_pushfstring(L, "TVB(%d) : %s", len, str);
wmem_free(NULL, str);
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
lua_pushnumber(L,tvb_captured_length(tvb->ws_tvb));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_reported_length_remaining(lua_State* L) {
#define Tvb_reported_length_remaining_OFFSET 2
Tvb tvb = checkTvb(L,1);
int offset = (int) luaL_optinteger(L, Tvb_reported_length_remaining_OFFSET, 0);
lua_pushnumber(L,tvb_reported_length_remaining(tvb->ws_tvb, offset));
WSLUA_RETURN(1);
}
WSLUA_METHOD Tvb_bytes(lua_State* L) {
#define WSLUA_OPTARG_Tvb_bytes_OFFSET 2
#define WSLUA_OPTARG_Tvb_bytes_LENGTH 3
Tvb tvb = checkTvb(L,1);
GByteArray* ba;
int offset = luaL_optint(L, WSLUA_OPTARG_Tvb_bytes_OFFSET, 0);
int len = luaL_optint(L,WSLUA_OPTARG_Tvb_bytes_LENGTH,-1);
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (len < 0) {
len = tvb_captured_length_remaining(tvb->ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return 0;
}
} else if ( (guint)(len + offset) > tvb_captured_length(tvb->ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return 0;
}
ba = g_byte_array_new();
g_byte_array_append(ba, tvb_get_ptr(tvb->ws_tvb, offset, len), len);
pushByteArray(L,ba);
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
WSLUA_METHOD Tvb_range(lua_State* L) {
#define WSLUA_OPTARG_Tvb_range_OFFSET 2
#define WSLUA_OPTARG_Tvb_range_LENGTH 3
Tvb tvb = checkTvb(L,1);
int offset = (int) luaL_optinteger(L,WSLUA_OPTARG_Tvb_range_OFFSET,0);
int len = (int) luaL_optinteger(L,WSLUA_OPTARG_Tvb_range_LENGTH,-1);
if (push_TvbRange(L,tvb->ws_tvb,offset,len)) {
WSLUA_RETURN(1);
}
return 0;
}
WSLUA_METHOD Tvb_raw(lua_State* L) {
#define WSLUA_OPTARG_Tvb_raw_OFFSET 2
#define WSLUA_OPTARG_Tvb_raw_LENGTH 3
Tvb tvb = checkTvb(L,1);
int offset = (int) luaL_optinteger(L,WSLUA_OPTARG_Tvb_raw_OFFSET,0);
int len = (int) luaL_optinteger(L,WSLUA_OPTARG_Tvb_raw_LENGTH,-1);
if (!tvb) return 0;
if (tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((guint)offset > tvb_captured_length(tvb->ws_tvb)) {
WSLUA_OPTARG_ERROR(Tvb_raw,OFFSET,"offset beyond end of Tvb");
return 0;
}
if (len == -1) {
len = tvb_captured_length_remaining(tvb->ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_captured_length(tvb->ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return FALSE;
}
lua_pushlstring(L, tvb_get_ptr(tvb->ws_tvb, offset, len), len);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Tvb__eq(lua_State* L) {
Tvb tvb_l = checkTvb(L,1);
Tvb tvb_r = checkTvb(L,2);
int len_l = tvb_captured_length(tvb_l->ws_tvb);
int len_r = tvb_captured_length(tvb_r->ws_tvb);
if (len_l == len_r)
{
const gchar* lp = tvb_get_ptr(tvb_l->ws_tvb, 0, len_l);
const gchar* rp = tvb_get_ptr(tvb_r->ws_tvb, 0, len_r);
int i = 0;
for (; i < len_l; ++i) {
if (lp[i] != rp[i]) {
lua_pushboolean(L,0);
return 1;
}
}
lua_pushboolean(L,1);
} else {
lua_pushboolean(L,0);
}
return 1;
}
int Tvb_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Tvb);
outstanding_Tvb = g_ptr_array_new();
return 0;
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
gboolean push_TvbRange(lua_State* L, tvbuff_t* ws_tvb, int offset, int len) {
TvbRange tvbr;
if (!ws_tvb) {
luaL_error(L,"expired tvb");
return FALSE;
}
if (len == -1) {
len = tvb_captured_length_remaining(ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_captured_length(ws_tvb)) {
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
WSLUA_METHOD TvbRange_tvb(lua_State *L) {
TvbRange tvbr = checkTvbRange(L,1);
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
tvb->ws_tvb = tvb_new_subset_length_caplen(tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len, tvbr->len);
return push_wsluaTvb(L, tvb);
} else {
luaL_error(L,"Out Of Bounds");
return 0;
}
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
pushUInt64(L,tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
pushUInt64(L,tvb_get_ntohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
pushUInt64(L,tvb_get_ntoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
pushUInt64(L,tvb_get_ntohl(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 5:
pushUInt64(L,tvb_get_ntoh40(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 6:
pushUInt64(L,tvb_get_ntoh48(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 7:
pushUInt64(L,tvb_get_ntoh56(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
pushUInt64(L,tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
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
pushUInt64(L,tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
pushUInt64(L,tvb_get_letohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
pushUInt64(L,tvb_get_letoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
pushUInt64(L,tvb_get_letohl(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 5:
pushUInt64(L,tvb_get_letoh40(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 6:
pushUInt64(L,tvb_get_letoh48(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 7:
pushUInt64(L,tvb_get_letoh56(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
pushUInt64(L,tvb_get_letoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
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
case 3:
lua_pushnumber(L,(gint)tvb_get_ntoh24(tvbr->tvb->ws_tvb,tvbr->offset));
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
case 3:
lua_pushnumber(L,(gint)tvb_get_letoh24(tvbr->tvb->ws_tvb,tvbr->offset));
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
pushInt64(L,(gint8)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
pushInt64(L,(gint16)tvb_get_ntohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
pushInt64(L,(gint)tvb_get_ntoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
pushInt64(L,(gint32)tvb_get_ntohl(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 5:
pushInt64(L,(gint64)tvb_get_ntoh40(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 6:
pushInt64(L,(gint64)tvb_get_ntoh48(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 7:
pushInt64(L,(gint64)tvb_get_ntoh56(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
pushInt64(L,(gint64)tvb_get_ntoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
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
pushInt64(L,(gint8)tvb_get_guint8(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 2:
pushInt64(L,(gint16)tvb_get_letohs(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 3:
pushInt64(L,(gint)tvb_get_letoh24(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 4:
pushInt64(L,(gint32)tvb_get_letohl(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 5:
pushInt64(L,(gint64)tvb_get_letoh40(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 6:
pushInt64(L,(gint64)tvb_get_letoh48(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 7:
pushInt64(L,(gint64)tvb_get_letoh56(tvbr->tvb->ws_tvb,tvbr->offset));
return 1;
case 8:
pushInt64(L,(gint64)tvb_get_letoh64(tvbr->tvb->ws_tvb,tvbr->offset));
WSLUA_RETURN(1);
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
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 4) {
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
return 0;
}
addr = g_new(address,1);
alloc_address_tvb(NULL,addr,AT_IPv4,sizeof(guint32),tvbr->tvb->ws_tvb,tvbr->offset);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_le_ipv4(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
guint32 ip_addr;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 4) {
WSLUA_ERROR(TvbRange_ipv4,"The range must be 4 octets long");
return 0;
}
addr = g_new(address,1);
ip_addr = GUINT32_SWAP_LE_BE(tvb_get_ipv4(tvbr->tvb->ws_tvb,tvbr->offset));
alloc_address_wmem(NULL, addr, AT_IPv4, sizeof(ip_addr), &ip_addr);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_ipv6(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (tvbr->len != 16) {
WSLUA_ERROR(TvbRange_ipv6,"The range must be 16 octets long");
return 0;
}
addr = g_new(address,1);
alloc_address_tvb(NULL,addr,AT_IPv6,16,tvbr->tvb->ws_tvb,tvbr->offset);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_ether(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
Address addr;
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
alloc_address_tvb(NULL,addr,AT_ETHER,6,tvbr->tvb->ws_tvb,tvbr->offset);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METHOD TvbRange_nstime(lua_State* L) {
#define WSLUA_OPTARG_TvbRange_nstime_ENCODING 2
TvbRange tvbr = checkTvbRange(L,1);
NSTime nstime;
const guint encoding = (guint) luaL_optinteger(L, WSLUA_OPTARG_TvbRange_nstime_ENCODING, 0);
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
guint encoding = (guint)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_string_ENCODING, ENC_ASCII|ENC_NA);
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
guint encoding = (guint)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_stringz_ENCODING, ENC_ASCII|ENC_NA);
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
guint encoding = (guint)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_strsize_ENCODING, ENC_ASCII|ENC_NA);
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
const guint encoding = (guint)luaL_optinteger(L, WSLUA_OPTARG_TvbRange_bytes_ENCODING, 0);
if ( !(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if (encoding == 0) {
ba = g_byte_array_new();
g_byte_array_append(ba,(const guint8 *)tvb_memdup(wmem_packet_scope(),tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len),tvbr->len);
pushByteArray(L,ba);
lua_pushinteger(L, tvbr->len);
}
else if ((encoding & ENC_STR_HEX) == 0) {
WSLUA_OPTARG_ERROR(TvbRange_nstime, ENCODING, "invalid encoding value");
}
else {
gint endoff = 0;
GByteArray* retval;
ba = g_byte_array_new();
retval = tvb_get_string_bytes(tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len,
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
int pos = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_bitfield_POSITION,0);
int len = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_bitfield_LENGTH,1);
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
int offset = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_range_OFFSET,0);
int len;
if (!(tvbr && tvbr->tvb)) return 0;
len = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_range_LENGTH,tvbr->len-offset);
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
WSLUA_METHOD TvbRange_uncompress(lua_State* L) {
#define WSLUA_ARG_TvbRange_uncompress_NAME 2
TvbRange tvbr = checkTvbRange(L,1);
#ifdef HAVE_ZLIB
const gchar* name = luaL_optstring(L,WSLUA_ARG_TvbRange_uncompress_NAME,"Uncompressed");
tvbuff_t *uncompr_tvb;
#endif
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
#ifdef HAVE_ZLIB
uncompr_tvb = tvb_child_uncompress(tvbr->tvb->ws_tvb, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len);
if (uncompr_tvb) {
add_new_data_source (lua_pinfo, uncompr_tvb, name);
if (push_TvbRange(L,uncompr_tvb,0,tvb_captured_length(uncompr_tvb))) {
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
int offset = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_raw_OFFSET,0);
int len = (int)luaL_optinteger(L,WSLUA_OPTARG_TvbRange_raw_LENGTH,-1);
if (!tvbr || !tvbr->tvb) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
if ((guint)offset > tvb_captured_length(tvbr->tvb->ws_tvb)) {
WSLUA_OPTARG_ERROR(TvbRange_raw,OFFSET,"offset beyond end of Tvb");
return 0;
}
if (len == -1) {
len = tvb_captured_length_remaining(tvbr->tvb->ws_tvb,offset);
if (len < 0) {
luaL_error(L,"out of bounds");
return FALSE;
}
} else if ( (guint)(len + offset) > tvb_captured_length(tvbr->tvb->ws_tvb)) {
luaL_error(L,"Range is out of bounds");
return FALSE;
}
lua_pushlstring(L, tvb_get_ptr(tvbr->tvb->ws_tvb, offset, len), len);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD TvbRange__eq(lua_State* L) {
TvbRange tvb_l = checkTvbRange(L,1);
TvbRange tvb_r = checkTvbRange(L,2);
if (tvb_l->len == tvb_r->len &&
tvb_l->len <= tvb_captured_length_remaining(tvb_l->tvb->ws_tvb, tvb_l->offset) &&
tvb_r->len <= tvb_captured_length_remaining(tvb_r->tvb->ws_tvb, tvb_r->offset))
{
const gchar* lp = tvb_get_ptr(tvb_l->tvb->ws_tvb, tvb_l->offset, tvb_l->len);
const gchar* rp = tvb_get_ptr(tvb_r->tvb->ws_tvb, tvb_r->offset, tvb_r->len);
int i = 0;
for (; i < tvb_r->len; ++i) {
if (lp[i] != rp[i]) {
lua_pushboolean(L,0);
return 1;
}
}
lua_pushboolean(L,1);
} else {
lua_pushboolean(L,0);
}
return 1;
}
WSLUA_METAMETHOD TvbRange__tostring(lua_State* L) {
TvbRange tvbr = checkTvbRange(L,1);
char* str = NULL;
if (!(tvbr && tvbr->tvb)) return 0;
if (tvbr->tvb->expired) {
luaL_error(L,"expired tvb");
return 0;
}
str = tvb_bytes_to_str(NULL,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len);
lua_pushstring(L,str);
wmem_free(NULL, str);
WSLUA_RETURN(1);
}
int TvbRange_register(lua_State* L) {
outstanding_TvbRange = g_ptr_array_new();
WSLUA_REGISTER_CLASS(TvbRange);
return 0;
}
