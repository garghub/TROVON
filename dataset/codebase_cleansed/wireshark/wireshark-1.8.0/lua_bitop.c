static UBits barg(lua_State *L, int idx)
{
BitNum bn;
UBits b;
bn.n = lua_tonumber(L, idx);
#if defined(LUA_NUMBER_DOUBLE)
bn.n += 6755399441055744.0;
#ifdef SWAPPED_DOUBLE
b = (UBits)(bn.b >> 32);
#else
b = (UBits)bn.b;
#endif
#elif defined(LUA_NUMBER_INT) || defined(LUA_NUMBER_LONG) || \
defined(LUA_NUMBER_LONGLONG) || defined(LUA_NUMBER_LONG_LONG) || \
defined(LUA_NUMBER_LLONG)
if (sizeof(UBits) == sizeof(lua_Number))
b = bn.b;
else
b = (UBits)(SBits)bn.n;
#elif defined(LUA_NUMBER_FLOAT)
#error "A 'float' lua_Number type is incompatible with this library"
#else
#error "Unknown number type, check LUA_NUMBER_* in luaconf.h"
#endif
if (b == 0 && !lua_isnumber(L, idx))
luaL_typerror(L, idx, "number");
return b;
}
static int bit_tobit(lua_State *L) { BRET(barg(L, 1)) }
static int bit_bnot(lua_State *L) { BRET(~barg(L, 1)) }
static int bit_bswap(lua_State *L)
{
UBits b = barg(L, 1);
b = (b >> 24) | ((b >> 8) & 0xff00) | ((b & 0xff00) << 8) | (b << 24);
BRET(b)
}
static int bit_tohex(lua_State *L)
{
UBits b = barg(L, 1);
SBits n = lua_isnone(L, 2) ? 8 : (SBits)barg(L, 2);
const char *hexdigits = "0123456789abcdef";
char buf[8];
int i;
if (n < 0) { n = -n; hexdigits = "0123456789ABCDEF"; }
if (n > 8) n = 8;
for (i = (int)n; --i >= 0; ) { buf[i] = hexdigits[b & 15]; b >>= 4; }
lua_pushlstring(L, buf, (size_t)n);
return 1;
}
LUALIB_API int luaopen_bit(lua_State *L)
{
UBits b;
lua_pushnumber(L, (lua_Number)1437217655L);
b = barg(L, -1);
if (b != (UBits)1437217655L || BAD_SAR) {
const char *msg = "compiled with incompatible luaconf.h";
#ifdef LUA_NUMBER_DOUBLE
#ifdef _WIN32
if (b == (UBits)1610612736L)
msg = "use D3DCREATE_FPU_PRESERVE with DirectX";
#endif
if (b == (UBits)1127743488L)
msg = "not compiled with SWAPPED_DOUBLE";
#endif
if (BAD_SAR)
msg = "arithmetic right-shift broken";
luaL_error(L, "bit library self-test failed (%s)", msg);
}
luaL_register(L, "bit", bit_funcs);
return 1;
}
