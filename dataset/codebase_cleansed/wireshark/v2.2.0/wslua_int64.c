static gint64 getInt64(lua_State *L, int i)
{
gchar *end = NULL;
(void) end;
switch (lua_type(L,i))
{
case LUA_TNUMBER:
return wslua_checkgint64(L,i);
case LUA_TSTRING:
return g_ascii_strtoll(luaL_checkstring(L,i),&end,10);
case LUA_TUSERDATA:
if (isUInt64(L, i)) {
return (Int64) toUInt64(L, i);
}
default:
return checkInt64(L,i);
}
}
void Int64_pack(lua_State* L, luaL_Buffer *b, gint idx, gboolean asLittleEndian) {
gint64 value = checkInt64(L,idx);
gint8 buff[sizeof(gint64)];
if (asLittleEndian) {
guint i;
for (i = 0; i < sizeof(gint64); i++) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
else {
gint i;
for (i = sizeof(gint64) - 1; i >= 0; i--) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
luaL_addlstring(b, (char*)buff, sizeof(gint64));
}
WSLUA_METHOD Int64_encode(lua_State* L) {
#define WSLUA_OPTARG_Int64_encode_ENDIAN 2
luaL_Buffer b;
gboolean asLittleEndian = IS_LITTLE_ENDIAN;
if (lua_gettop(L) >= WSLUA_OPTARG_Int64_encode_ENDIAN) {
if (lua_type(L,WSLUA_OPTARG_Int64_encode_ENDIAN) == LUA_TBOOLEAN)
asLittleEndian = lua_toboolean(L,WSLUA_OPTARG_Int64_encode_ENDIAN);
}
luaL_buffinit(L, &b);
Int64_pack(L, &b, 1, asLittleEndian);
luaL_pushresult(&b);
WSLUA_RETURN(1);
}
int Int64_unpack(lua_State* L, const gchar *buff, gboolean asLittleEndian) {
gint64 value = 0;
gint i;
if (asLittleEndian) {
for (i = sizeof(gint64) - 1; i >= 0; i--) {
value <<= 8;
value |= (gint64)(guchar)buff[i];
}
}
else {
for (i = 0; i < (gint) sizeof(gint64); i++) {
value <<= 8;
value |= (gint64)(guchar)buff[i];
}
}
pushInt64(L,value);
return 1;
}
WSLUA_CONSTRUCTOR Int64_decode(lua_State* L) {
#define WSLUA_ARG_Int64_decode_STRING 1
#define WSLUA_OPTARG_Int64_decode_ENDIAN 2
gboolean asLittleEndian = IS_LITTLE_ENDIAN;
size_t len = 0;
const gchar *s = luaL_checklstring(L, WSLUA_ARG_Int64_decode_STRING, &len);
if (lua_gettop(L) >= WSLUA_OPTARG_Int64_decode_ENDIAN) {
if (lua_type(L,WSLUA_OPTARG_Int64_decode_ENDIAN) == LUA_TBOOLEAN)
asLittleEndian = lua_toboolean(L,WSLUA_OPTARG_Int64_decode_ENDIAN);
}
if (len == sizeof(gint64)) {
Int64_unpack(L, s, asLittleEndian);
} else {
lua_pushnil(L);
}
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Int64_new(lua_State* L) {
#define WSLUA_OPTARG_Int64_new_VALUE 1
#define WSLUA_OPTARG_Int64_new_HIGHVALUE 2
gint64 value = 0;
if (lua_gettop(L) >= 1) {
switch(lua_type(L, WSLUA_OPTARG_Int64_new_VALUE)) {
case LUA_TNUMBER:
value = wslua_togint64(L, WSLUA_OPTARG_Int64_new_VALUE);
if (lua_gettop(L) == 2 &&
lua_type(L, WSLUA_OPTARG_Int64_new_HIGHVALUE) == LUA_TNUMBER) {
gint64 h = wslua_togint64(L, WSLUA_OPTARG_Int64_new_HIGHVALUE);
value &= G_GUINT64_CONSTANT(0x00000000FFFFFFFF);
h <<= 32; h &= G_GUINT64_CONSTANT(0xFFFFFFFF00000000);
value += h;
}
break;
case LUA_TSTRING:
case LUA_TUSERDATA:
value = getInt64(L,WSLUA_OPTARG_Int64_new_VALUE);
break;
default:
WSLUA_OPTARG_ERROR(Int64_new,VALUE,"must be a number, UInt64, Int64, or string");
break;
}
}
pushInt64(L,value);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__call(lua_State* L) {
lua_remove(L,1);
WSLUA_RETURN(Int64_new(L));
}
WSLUA_CONSTRUCTOR Int64_max(lua_State* L) {
pushInt64(L, G_MAXINT64);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Int64_min(lua_State* L) {
pushInt64(L, G_MININT64);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_tonumber(lua_State* L) {
lua_pushnumber(L, (lua_Number)(checkInt64(L,1)));
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Int64_fromhex(lua_State* L) {
#define WSLUA_ARG_Int64_fromhex_HEX 1
guint64 result = 0;
size_t len = 0;
const gchar *s = luaL_checklstring(L,WSLUA_ARG_Int64_fromhex_HEX,&len);
if (len > 0) {
if (sscanf(s, "%" G_GINT64_MODIFIER "x", &result) != 1) {
return luaL_error(L, "Error decoding the passed-in hex string");
}
}
pushInt64(L,(gint64)result);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_tohex(lua_State* L) {
#define WSLUA_OPTARG_Int64_new_NUMBYTES 2
gint64 b = getInt64(L,1);
lua_Integer n = luaL_optinteger(L, WSLUA_OPTARG_Int64_new_NUMBYTES, 16);
const gchar *hexdigits = "0123456789abcdef";
gchar buf[16];
lua_Integer i;
if (n < 0) { n = -n; hexdigits = "0123456789ABCDEF"; }
if (n > 16) n = 16;
for (i = n-1; i >= 0; --i) { buf[i] = hexdigits[b & 15]; b >>= 4; }
lua_pushlstring(L, buf, (size_t)n);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_higher(lua_State* L) {
gint64 num = getInt64(L,1);
gint64 b = num;
lua_Number n = 0;
if (b < 0) b = -b;
b &= G_GUINT64_CONSTANT(0x7FFFFFFF00000000);
b >>= 32;
n = (lua_Number)(guint32)(b & G_GUINT64_CONSTANT(0x00000000FFFFFFFFF));
if (num < 0) n = -n;
lua_pushnumber(L,n);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_lower(lua_State* L) {
gint64 b = getInt64(L,1);
if (b < 0) b = -b;
lua_pushnumber(L,(guint32)(b & G_GUINT64_CONSTANT(0x00000000FFFFFFFFF)));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__tostring(lua_State* L) {
gint64 num = getInt64(L,1);
gchar s[LUATYPE64_STRING_SIZE];
if (g_snprintf(s, LUATYPE64_STRING_SIZE, "%" G_GINT64_MODIFIER "d", num) < 0) {
return luaL_error(L, "Error writing Int64 to a string");
}
lua_pushstring(L,s);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__unm(lua_State* L) {
pushInt64(L,-(getInt64(L,1)));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__add(lua_State* L) {
WSLUA_MATH_OP_FUNC(Int64,+);
}
WSLUA_METAMETHOD Int64__sub(lua_State* L) {
WSLUA_MATH_OP_FUNC(Int64,-);
}
WSLUA_METAMETHOD Int64__mul(lua_State* L) {
WSLUA_MATH_OP_FUNC(Int64,*);
}
WSLUA_METAMETHOD Int64__div(lua_State* L) {
Int64 num1 = getInt64(L,1);
Int64 num2 = getInt64(L,2);
if (num2 == 0) {
return luaL_error(L, "Trying to divide Int64 by zero");
}
pushInt64(L, num1 / num2);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__mod(lua_State* L) {
Int64 num1 = getInt64(L,1);
Int64 num2 = getInt64(L,2);
if (num2 == 0) {
return luaL_error(L, "Trying to modulo Int64 by zero");
}
pushInt64(L, num1 % num2);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__pow(lua_State* L) {
gint64 num1 = getInt64(L,1);
gint64 num2 = getInt64(L,2);
gint64 result;
if (num1 == 2) {
result = (num2 >= 8 * (gint64) sizeof(gint64)) ? 0 : ((gint64)1 << num2);
}
else {
for (result = 1; num2 > 0; num2 >>= 1) {
if (num2 & 1) result *= num1;
num1 *= num1;
}
}
pushInt64(L,result);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Int64__eq(lua_State* L) {
WSLUA_COMP_OP_FUNC(Int64,==);
}
WSLUA_METAMETHOD Int64__lt(lua_State* L) {
WSLUA_COMP_OP_FUNC(Int64,<);
}
WSLUA_METAMETHOD Int64__le(lua_State* L) {
WSLUA_COMP_OP_FUNC(Int64,<=);
}
WSLUA_METHOD Int64_bnot(lua_State* L) {
pushInt64(L,~(getInt64(L,1)));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_band(lua_State* L) {
WSLUA_BIT_OP_FUNC(Int64,&=);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_bor(lua_State* L) {
WSLUA_BIT_OP_FUNC(Int64,|=);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_bxor(lua_State* L) {
WSLUA_BIT_OP_FUNC(Int64,^=);
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_lshift(lua_State* L) {
#define WSLUA_ARG_Int64_lshift_NUMBITS 2
guint64 b = (guint64) getInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_Int64_lshift_NUMBITS);
pushInt64(L,(gint64)(b << n));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_rshift(lua_State* L) {
#define WSLUA_ARG_Int64_rshift_NUMBITS 2
guint64 b = (guint64) getInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_Int64_rshift_NUMBITS);
pushInt64(L,(gint64)(b >> n));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_arshift(lua_State* L) {
#define WSLUA_ARG_Int64_arshift_NUMBITS 2
gint64 b = getInt64(L,1);
gint32 n = wslua_checkgint32(L,WSLUA_ARG_Int64_arshift_NUMBITS);
pushInt64(L,(b >> n));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_rol(lua_State* L) {
#define WSLUA_ARG_Int64_rol_NUMBITS 2
guint64 b = (guint64) getInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_Int64_rol_NUMBITS);
pushInt64(L,(gint64)((b << n) | (b >> (64-n))));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_ror(lua_State* L) {
#define WSLUA_ARG_Int64_ror_NUMBITS 2
guint64 b = (guint64) getInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_Int64_ror_NUMBITS);
pushInt64(L,(gint64)((b << (64-n)) | (b >> n)));
WSLUA_RETURN(1);
}
WSLUA_METHOD Int64_bswap(lua_State* L) {
guint64 b = (guint64) getInt64(L,1);
guint64 result = 0;
size_t i;
for (i = 0; i < sizeof(gint64); i++) {
result <<= 8;
result |= (b & G_GUINT64_CONSTANT(0x00000000000000FF));
b >>= 8;
}
pushInt64(L,(gint64)result);
WSLUA_RETURN(1);
}
static int Int64__gc(lua_State* L _U_) {
return 0;
}
LUALIB_API int Int64_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Int64);
return 0;
}
static guint64 getUInt64(lua_State *L, int i)
{
gchar *end = NULL;
(void) end;
switch (lua_type(L,i))
{
case LUA_TNUMBER:
return wslua_checkguint64(L,i);
case LUA_TSTRING:
return g_ascii_strtoull(luaL_checkstring(L,i), &end, 10);
case LUA_TUSERDATA:
if (isInt64(L, i)) {
return (UInt64) toInt64(L, i);
}
default:
return checkUInt64(L,i);
}
}
void UInt64_pack(lua_State* L, luaL_Buffer *b, gint idx, gboolean asLittleEndian) {
guint64 value = checkUInt64(L,idx);
gint8 buff[sizeof(guint64)];
if (asLittleEndian) {
guint i;
for (i = 0; i < sizeof(guint64); i++) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
else {
gint i;
for (i = sizeof(guint64) - 1; i >= 0; i--) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
luaL_addlstring(b, (char*)buff, sizeof(guint64));
}
WSLUA_METHOD UInt64_encode(lua_State* L) {
#define WSLUA_OPTARG_UInt64_encode_ENDIAN 2
luaL_Buffer b;
gboolean asLittleEndian = IS_LITTLE_ENDIAN;
if (lua_gettop(L) >= 2) {
if (lua_type(L,2) == LUA_TBOOLEAN)
asLittleEndian = lua_toboolean(L,2);
}
luaL_buffinit(L, &b);
UInt64_pack(L, &b, 1, asLittleEndian);
luaL_pushresult(&b);
WSLUA_RETURN(1);
}
int UInt64_unpack(lua_State* L, const gchar *buff, gboolean asLittleEndian) {
guint64 value = 0;
gint i;
if (asLittleEndian) {
for (i = sizeof(guint64) - 1; i >= 0; i--) {
value <<= 8;
value |= (guint64)(guchar)buff[i];
}
}
else {
for (i = 0; i < (gint) sizeof(guint64); i++) {
value <<= 8;
value |= (guint64)(guchar)buff[i];
}
}
pushUInt64(L,value);
return 1;
}
WSLUA_CONSTRUCTOR UInt64_decode(lua_State* L) {
#define WSLUA_ARG_UInt64_decode_STRING 1
#define WSLUA_OPTARG_UInt64_decode_ENDIAN 2
gboolean asLittleEndian = IS_LITTLE_ENDIAN;
size_t len = 0;
const gchar *s = luaL_checklstring(L, WSLUA_ARG_UInt64_decode_STRING, &len);
if (lua_gettop(L) >= WSLUA_OPTARG_UInt64_decode_ENDIAN) {
if (lua_type(L,WSLUA_OPTARG_UInt64_decode_ENDIAN) == LUA_TBOOLEAN)
asLittleEndian = lua_toboolean(L,WSLUA_OPTARG_UInt64_decode_ENDIAN);
}
if (len == sizeof(guint64)) {
UInt64_unpack(L, s, asLittleEndian);
} else {
lua_pushnil(L);
}
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR UInt64_new(lua_State* L) {
#define WSLUA_OPTARG_UInt64_new_VALUE 1
#define WSLUA_OPTARG_UInt64_new_HIGHVALUE 2
guint64 value = 0;
if (lua_gettop(L) >= 1) {
switch(lua_type(L, WSLUA_OPTARG_UInt64_new_VALUE)) {
case LUA_TNUMBER:
value = wslua_toguint64(L, WSLUA_OPTARG_UInt64_new_VALUE);
if (lua_gettop(L) == 2 &&
lua_type(L, WSLUA_OPTARG_UInt64_new_HIGHVALUE) == LUA_TNUMBER) {
guint64 h = wslua_toguint64(L, WSLUA_OPTARG_UInt64_new_HIGHVALUE);
value &= G_GUINT64_CONSTANT(0x00000000FFFFFFFF);
h <<= 32; h &= G_GUINT64_CONSTANT(0xFFFFFFFF00000000);
value += h;
}
break;
case LUA_TSTRING:
case LUA_TUSERDATA:
value = getUInt64(L, WSLUA_OPTARG_UInt64_new_VALUE);
break;
default:
WSLUA_OPTARG_ERROR(UInt64_new,VALUE,"must be a number, UInt64, Int64, or string");
break;
}
}
pushUInt64(L,value);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__call(lua_State* L) {
lua_remove(L,1);
WSLUA_RETURN(UInt64_new(L));
}
WSLUA_CONSTRUCTOR UInt64_max(lua_State* L) {
pushUInt64(L,G_MAXUINT64);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR UInt64_min(lua_State* L) {
pushUInt64(L,0);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_tonumber(lua_State* L) {
lua_pushnumber(L,(lua_Number)(checkUInt64(L,1)));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__tostring(lua_State* L) {
guint64 num = getUInt64(L,1);
gchar s[LUATYPE64_STRING_SIZE];
if (g_snprintf(s, LUATYPE64_STRING_SIZE, "%" G_GINT64_MODIFIER "u",(guint64)num) < 0) {
return luaL_error(L, "Error writing UInt64 to a string");
}
lua_pushstring(L,s);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR UInt64_fromhex(lua_State* L) {
#define WSLUA_ARG_UInt64_fromhex_HEX 1
guint64 result = 0;
size_t len = 0;
const gchar *s = luaL_checklstring(L,WSLUA_ARG_UInt64_fromhex_HEX,&len);
if (len > 0) {
if (sscanf(s, "%" G_GINT64_MODIFIER "x", &result) != 1) {
return luaL_error(L, "Error decoding the passed-in hex string");
}
}
pushUInt64(L,result);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_tohex(lua_State* L) {
#define WSLUA_OPTARG_UInt64_new_NUMBYTES 2
guint64 b = getUInt64(L,1);
lua_Integer n = luaL_optinteger(L, WSLUA_OPTARG_UInt64_new_NUMBYTES, 16);
const gchar *hexdigits = "0123456789abcdef";
gchar buf[16];
lua_Integer i;
if (n < 0) { n = -n; hexdigits = "0123456789ABCDEF"; }
if (n > 16) n = 16;
for (i = n-1; i >= 0; --i) { buf[i] = hexdigits[b & 15]; b >>= 4; }
lua_pushlstring(L, buf, (size_t)n);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_higher(lua_State* L) {
guint64 num = getUInt64(L,1);
guint64 b = num;
lua_Number n = 0;
b &= G_GUINT64_CONSTANT(0xFFFFFFFF00000000);
b >>= 32;
n = (lua_Number)(guint32)(b & G_GUINT64_CONSTANT(0x00000000FFFFFFFFF));
lua_pushnumber(L,n);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_lower(lua_State* L) {
guint64 b = getUInt64(L,1);
lua_pushnumber(L,(guint32)(b & G_GUINT64_CONSTANT(0x00000000FFFFFFFFF)));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__unm(lua_State* L) {
pushUInt64(L,getUInt64(L,1));
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__add(lua_State* L) {
WSLUA_MATH_OP_FUNC(UInt64,+);
}
WSLUA_METAMETHOD UInt64__sub(lua_State* L) {
WSLUA_MATH_OP_FUNC(UInt64,-);
}
WSLUA_METAMETHOD UInt64__mul(lua_State* L) {
WSLUA_MATH_OP_FUNC(UInt64,*);
}
WSLUA_METAMETHOD UInt64__div(lua_State* L) {
UInt64 num1 = getUInt64(L,1);
UInt64 num2 = getUInt64(L,2);
if (num2 == 0) {
return luaL_error(L, "Trying to divide UInt64 by zero");
}
pushUInt64(L, num1 / num2);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__mod(lua_State* L) {
UInt64 num1 = getUInt64(L,1);
UInt64 num2 = getUInt64(L,2);
if (num2 == 0) {
return luaL_error(L, "Trying to modulo UInt64 by zero");
}
pushUInt64(L, num1 % num2);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__pow(lua_State* L) {
guint64 num1 = getUInt64(L,1);
guint64 num2 = getUInt64(L,2);
guint64 result;
if (num1 == 2) {
result = (num2 >= 8 * (guint64) sizeof(guint64)) ? 0 : ((guint64)1 << num2);
}
else {
for (result = 1; num2 > 0; num2 >>= 1) {
if (num2 & 1) result *= num1;
num1 *= num1;
}
}
pushUInt64(L,result);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD UInt64__eq(lua_State* L) {
WSLUA_COMP_OP_FUNC(UInt64,==);
}
WSLUA_METAMETHOD UInt64__lt(lua_State* L) {
WSLUA_COMP_OP_FUNC(UInt64,<);
}
WSLUA_METAMETHOD UInt64__le(lua_State* L) {
WSLUA_COMP_OP_FUNC(UInt64,<=);
}
WSLUA_METHOD UInt64_bnot(lua_State* L) {
pushUInt64(L,~(getUInt64(L,1)));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_band(lua_State* L) {
WSLUA_BIT_OP_FUNC(UInt64,&=);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_bor(lua_State* L) {
WSLUA_BIT_OP_FUNC(UInt64,|=);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_bxor(lua_State* L) {
WSLUA_BIT_OP_FUNC(UInt64,^=);
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_lshift(lua_State* L) {
#define WSLUA_ARG_UInt64_lshift_NUMBITS 2
guint64 b = getUInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_UInt64_lshift_NUMBITS);
pushUInt64(L,(b << n));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_rshift(lua_State* L) {
#define WSLUA_ARG_UInt64_rshift_NUMBITS 2
guint64 b = getUInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_UInt64_rshift_NUMBITS);
pushUInt64(L,(b >> n));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_arshift(lua_State* L) {
#define WSLUA_ARG_UInt64_arshift_NUMBITS 2
guint64 b = getUInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_UInt64_arshift_NUMBITS);
pushUInt64(L,(b >> n));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_rol(lua_State* L) {
#define WSLUA_ARG_UInt64_rol_NUMBITS 2
guint64 b = getUInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_UInt64_rol_NUMBITS);
pushUInt64(L,((b << n) | (b >> (64-n))));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_ror(lua_State* L) {
#define WSLUA_ARG_UInt64_ror_NUMBITS 2
guint64 b = getUInt64(L,1);
guint32 n = wslua_checkguint32(L,WSLUA_ARG_UInt64_ror_NUMBITS);
pushUInt64(L,((b << (64-n)) | (b >> n)));
WSLUA_RETURN(1);
}
WSLUA_METHOD UInt64_bswap(lua_State* L) {
guint64 b = getUInt64(L,1);
guint64 result = 0;
size_t i;
for (i = 0; i < sizeof(guint64); i++) {
result <<= 8;
result |= (b & G_GUINT64_CONSTANT(0x00000000000000FF));
b >>= 8;
}
pushUInt64(L,result);
WSLUA_RETURN(1);
}
static int UInt64__gc(lua_State* L _U_) {
return 0;
}
LUALIB_API int UInt64_register(lua_State* L) {
WSLUA_REGISTER_CLASS(UInt64);
return 0;
}
