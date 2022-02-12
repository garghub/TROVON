WSLUA_CONSTRUCTOR NSTime_new(lua_State *L) {
#define WSLUA_OPTARG_NSTime_new_SECONDS 1
#define WSLUA_OPTARG_NSTime_new_NSECONDS 2
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
if (!nstime) return 0;
nstime->secs = (time_t) luaL_optinteger(L,WSLUA_OPTARG_NSTime_new_SECONDS,0);
nstime->nsecs = (int) luaL_optinteger(L,WSLUA_OPTARG_NSTime_new_NSECONDS,0);
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
gchar *str;
str = wmem_strdup_printf(NULL, "%ld.%09d", (long)nstime->secs, nstime->nsecs);
lua_pushstring(L, str);
wmem_free(NULL, str);
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
