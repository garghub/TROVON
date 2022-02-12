static int getnum (const gchar **fmt, int df) {
if (!isdigit(**fmt))
return df;
else {
int a = 0;
do {
a = a*10 + *((*fmt)++) - '0';
} while (isdigit(**fmt));
return a;
}
}
static size_t optsize (lua_State *L, gchar opt, const gchar **fmt) {
switch (opt) {
case 'B': case 'b': return sizeof(gchar);
case 'H': case 'h': return sizeof(gshort);
case 'L': case 'l': return sizeof(glong);
case 'E': case 'e': return sizeof(gint64);
case 'T': return sizeof(size_t);
case 'f': return sizeof(gfloat);
case 'd': return sizeof(gdouble);
case 'x': return getnum(fmt, 1);
case 'X': return getnum(fmt, MAXALIGN);
case 'c': return getnum(fmt, 1);
case 'i': case 'I': {
int sz = getnum(fmt, sizeof(int));
if (sz > MAXINTSIZE)
luaL_error(L, "integral size %d is larger than limit of %d",
sz, MAXINTSIZE);
return sz;
}
case 's': case ' ':
case '<': case '>':
case '(': case ')':
case '!': case '=':
return 0;
default: {
const gchar *msg = lua_pushfstring(L, "invalid format option [%c]", opt);
return luaL_argerror(L, 1, msg);
}
}
}
static int gettoalign (size_t len, Header *h, int opt, size_t size) {
if (size == 0 || opt == 'c' || opt == 's') return 0;
if (size > (size_t)h->align)
size = h->align;
return (int)((size - (len & (size - 1))) & (size - 1));
}
static void controloptions (lua_State *L, int opt, const gchar **fmt,
Header *h) {
switch (opt) {
case ' ': return;
case '>': h->endian = BIG; return;
case '<': h->endian = LITTLE; return;
case '(': h->noassign = TRUE; return;
case ')': h->noassign = FALSE; return;
case '!': {
int a = getnum(fmt, MAXALIGN);
if (!isp2(a))
luaL_error(L, "alignment %d is not a power of 2", a);
h->align = a;
return;
}
default: {
const char *msg = lua_pushfstring(L, "invalid format option '%c'", opt);
luaL_argerror(L, 1, msg);
}
}
}
static void putinteger (lua_State *L, luaL_Buffer *b, int arg, int endian,
int size) {
lua_Number n = luaL_checknumber(L, arg);
gint64 value;
gchar buff[MAXINTSIZE];
if (n < 0)
value = (guint64)(gint64)n;
else
value = (guint64)n;
if (endian == LITTLE) {
int i;
for (i = 0; i < size; i++) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
else {
int i;
for (i = size - 1; i >= 0; i--) {
buff[i] = (value & 0xff);
value >>= 8;
}
}
luaL_addlstring(b, buff, size);
}
static void correctbytes (gchar *b, int size, int endian) {
if (endian != native.endian) {
int i = 0;
while (i < --size) {
gchar temp = b[i];
b[i++] = b[size];
b[size] = temp;
}
}
}
WSLUA_CONSTRUCTOR Struct_pack (lua_State *L) {
#define WSLUA_ARG_Struct_pack_FORMAT 1
#define WSLUA_ARG_Struct_pack_VALUE 2
luaL_Buffer b;
const char *fmt = wslua_checkstring_only(L, WSLUA_ARG_Struct_pack_FORMAT);
Header h;
int poscnt = 0;
int posBuf[10];
int arg = 2;
size_t totalsize = 0;
defaultoptions(&h);
lua_pushnil(L);
luaL_buffinit(L, &b);
while (*fmt != '\0') {
int opt = *fmt++;
size_t size = optsize(L, opt, &fmt);
int toalign = gettoalign(totalsize, &h, opt, size);
totalsize += toalign;
while (toalign-- > 0) luaL_addchar(&b, '\0');
if (opt == 'X') size = 0;
if (h.noassign && size) opt = 'x';
switch (opt) {
case 'b': case 'B': case 'h': case 'H':
case 'l': case 'L': case 'T': case 'i': case 'I': {
putinteger(L, &b, arg++, h.endian, (int)size);
break;
}
case 'e': {
Int64_pack(L, &b, arg++, h.endian == LITTLE);
break;
}
case 'E': {
UInt64_pack(L, &b, arg++, h.endian == LITTLE);
break;
}
case 'x': case 'X': {
size_t len = size;
while (len-- > 0)
luaL_addchar(&b, '\0');
break;
}
case 'f': {
gfloat f = (gfloat)luaL_checknumber(L, arg++);
correctbytes((gchar *)&f, (int)size, h.endian);
luaL_addlstring(&b, (gchar *)&f, size);
break;
}
case 'd': {
gdouble d = luaL_checknumber(L, arg++);
correctbytes((gchar *)&d, (int)size, h.endian);
luaL_addlstring(&b, (gchar *)&d, size);
break;
}
case 'c': case 's': {
size_t l;
const gchar *s = luaL_checklstring(L, arg++, &l);
if (size == 0) size = l;
luaL_argcheck(L, l >= (size_t)size, arg, "string too short");
luaL_addlstring(&b, s, size);
if (opt == 's') {
luaL_addchar(&b, '\0');
size++;
}
break;
}
case '=': {
if (poscnt < (int)(sizeof(posBuf)/sizeof(posBuf[0])))
posBuf[poscnt++] = (int)totalsize + 1;
break;
}
default: controloptions(L, opt, &fmt, &h);
}
totalsize += size;
}
luaL_pushresult(&b);
for (arg = 0; arg < poscnt; arg++)
lua_pushinteger(L, posBuf[arg]);
WSLUA_RETURN(poscnt + 1);
}
static lua_Number getinteger (const gchar *buff, int endian,
int issigned, int size) {
Uinttype l = 0;
int i;
if (endian == BIG) {
for (i = 0; i < size; i++) {
l <<= 8;
l |= (Uinttype)(guchar)buff[i];
}
}
else {
for (i = size - 1; i >= 0; i--) {
l <<= 8;
l |= (Uinttype)(guchar)buff[i];
}
}
if (!issigned)
return (lua_Number)l;
else {
Uinttype mask = (Uinttype)(~((Uinttype)0)) << (size*8 - 1);
if (l & mask)
l |= mask;
return (lua_Number)(Inttype)l;
}
}
WSLUA_CONSTRUCTOR Struct_unpack (lua_State *L) {
#define WSLUA_ARG_Struct_unpack_FORMAT 1
#define WSLUA_ARG_Struct_unpack_STRUCT 2
#define WSLUA_OPTARG_Struct_unpack_BEGIN 3
Header h;
const char *fmt = wslua_checkstring_only(L, WSLUA_ARG_Struct_unpack_FORMAT);
size_t ld;
const char *data = wslua_checklstring_only(L, WSLUA_ARG_Struct_unpack_STRUCT, &ld);
size_t pos = luaL_optinteger(L, WSLUA_OPTARG_Struct_unpack_BEGIN, 1) - 1;
defaultoptions(&h);
lua_settop(L, 2);
while (*fmt) {
int opt = *fmt++;
size_t size = optsize(L, opt, &fmt);
pos += gettoalign(pos, &h, opt, size);
luaL_argcheck(L, pos+size <= ld, 2, "data string too short");
if (opt == 'X') size = 0;
if (h.noassign && size > 0) {
pos += size;
continue;
}
luaL_checkstack(L, 1, "too many results");
switch (opt) {
case 'b': case 'B': case 'h': case 'H':
case 'l': case 'L': case 'T': case 'i': case 'I': {
int issigned = islower(opt);
lua_Number res = getinteger(data+pos, h.endian, issigned, (int)size);
lua_pushnumber(L, res);
break;
}
case 'e': {
Int64_unpack(L, data+pos, h.endian == LITTLE);
break;
}
case 'E': {
UInt64_unpack(L, data+pos, h.endian == LITTLE);
break;
}
case 'x': case 'X': {
break;
}
case 'f': {
gfloat f;
memcpy(&f, data+pos, size);
correctbytes((gchar *)&f, sizeof(f), h.endian);
lua_pushnumber(L, f);
break;
}
case 'd': {
gdouble d;
memcpy(&d, data+pos, size);
correctbytes((gchar *)&d, sizeof(d), h.endian);
lua_pushnumber(L, d);
break;
}
case 'c': {
if (size == 0) {
if (!lua_isnumber(L, -1))
luaL_error(L, "format `c0' needs a previous size");
size = wslua_toguint32(L, -1);
lua_pop(L, 1);
luaL_argcheck(L, pos+size <= ld, 2, "data string too short");
}
if (!h.noassign)
lua_pushlstring(L, data+pos, size);
break;
}
case 's': {
const gchar *e = (const char *)memchr(data+pos, '\0', ld - pos);
if (e == NULL)
luaL_error(L, "unfinished string in data");
size = (e - (data+pos)) + 1;
if (!h.noassign)
lua_pushlstring(L, data+pos, size - 1);
break;
}
case '=': {
lua_pushinteger(L, pos + 1);
break;
}
default: controloptions(L, opt, &fmt, &h);
}
pos += size;
}
lua_pushinteger(L, pos + 1);
WSLUA_RETURN(lua_gettop(L) - 2);
}
WSLUA_CONSTRUCTOR Struct_size (lua_State *L) {
#define WSLUA_ARG_Struct_size_FORMAT 1
Header h;
const gchar *fmt = wslua_checkstring_only(L, WSLUA_ARG_Struct_size_FORMAT);
size_t pos = 0;
defaultoptions(&h);
while (*fmt) {
int opt = *fmt++;
size_t size = optsize(L, opt, &fmt);
pos += gettoalign(pos, &h, opt, size);
if (opt == 's')
luaL_argerror(L, 1, "option 's' has no fixed size");
else if (opt == 'c' && size == 0)
luaL_argerror(L, 1, "option 'c0' has no fixed size");
if (!isalnum(opt))
controloptions(L, opt, &fmt, &h);
pos += size;
}
lua_pushinteger(L, pos);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Struct_values (lua_State *L) {
#define WSLUA_ARG_Struct_values_FORMAT 1
Header h;
const gchar *fmt = wslua_checkstring_only(L, WSLUA_ARG_Struct_values_FORMAT);
size_t vals = 0;
defaultoptions(&h);
while (*fmt) {
int opt = *fmt++;
size_t size = optsize(L, opt, &fmt);
switch (opt) {
case 's': case 'c':
size = 1;
break;
case 'x': case 'X':
size = 0;
break;
default:
break;
}
if (!isalnum(opt))
controloptions(L, opt, &fmt, &h);
else if (size && !h.noassign)
vals++;
}
lua_pushinteger(L, vals);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Struct_tohex (lua_State *L) {
#define WSLUA_ARG_Struct_tohex_BYTESTRING 1
#define WSLUA_OPTARG_Struct_tohex_LOWERCASE 2
#define WSLUA_OPTARG_Struct_tohex_SEPARATOR 3
const gchar* s = NULL;
size_t len = 0;
gboolean lowercase = FALSE;
const gchar* sep = NULL;
s = luaL_checklstring(L, WSLUA_ARG_Struct_tohex_BYTESTRING, &len);
if (!s) {
WSLUA_ARG_ERROR(Struct_tohex,BYTESTRING,"must be a Lua string");
return 0;
}
lowercase = wslua_optbool(L,WSLUA_OPTARG_Struct_tohex_LOWERCASE,FALSE);
sep = luaL_optstring(L,WSLUA_OPTARG_Struct_tohex_SEPARATOR,NULL);
wslua_bin2hex(L, s, (guint)len, lowercase, sep);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Struct_fromhex (lua_State *L) {
#define WSLUA_ARG_Struct_fromhex_HEXBYTES 1
#define WSLUA_OPTARG_Struct_fromhex_SEPARATOR 2
const gchar* s = NULL;
size_t len = 0;
const gchar* sep = NULL;
s = wslua_checklstring_only(L, WSLUA_ARG_Struct_fromhex_HEXBYTES, &len);
if (!s) {
WSLUA_ARG_ERROR(Struct_fromhex,HEXBYTES,"must be a Lua string");
return 0;
}
sep = luaL_optstring(L,WSLUA_OPTARG_Struct_fromhex_SEPARATOR,NULL);
wslua_hex2bin(L, s, (guint)len, sep);
WSLUA_RETURN(1);
}
static int Struct__gc(lua_State* L _U_) {
return 0;
}
LUALIB_API int Struct_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Struct);
return 0;
}
