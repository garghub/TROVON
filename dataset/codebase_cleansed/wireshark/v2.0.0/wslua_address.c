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
const gchar *str = address_to_display(NULL, addr);
lua_pushstring(L, str);
wmem_free(NULL, (void*) str);
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
