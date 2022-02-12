WSLUA_CONSTRUCTOR Address_ip(lua_State* L) {
#define WSLUA_ARG_Address_ip_HOSTNAME 1
Address addr = (Address)g_malloc(sizeof(address));
guint32 ip_addr;
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Address_ip_HOSTNAME);
if (! get_host_ipaddr(name, &ip_addr)) {
ip_addr = 0;
}
alloc_address_wmem(NULL, addr, AT_IPv4, 4, &ip_addr);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Address_ipv6(lua_State* L) {
#define WSLUA_ARG_Address_ipv6_HOSTNAME 1
Address addr = (Address)g_malloc(sizeof(address));
struct e_in6_addr ip_addr;
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Address_ipv6_HOSTNAME);
if (!get_host_ipaddr6(name, &ip_addr)) {
memset(&ip_addr, 0, sizeof(ip_addr));
}
alloc_address_wmem(NULL, addr, AT_IPv6, sizeof(ip_addr.bytes), &ip_addr.bytes);
pushAddress(L,addr);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Address__tostring(lua_State* L) {
Address addr = checkAddress(L,1);
gchar *str = address_to_display(NULL, addr);
lua_pushstring(L, str);
wmem_free(NULL, str);
WSLUA_RETURN(1);
}
static int Address__gc(lua_State* L) {
Address addr = toAddress(L,1);
if (addr) {
free_address(addr);
g_free(addr);
}
return 0;
}
WSLUA_METAMETHOD Address__eq(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (addresses_equal(addr1, addr2))
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD Address__le(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (cmp_address(addr1, addr2) <= 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
WSLUA_METAMETHOD Address__lt(lua_State* L) {
Address addr1 = checkAddress(L,1);
Address addr2 = checkAddress(L,2);
gboolean result = FALSE;
if (cmp_address(addr1, addr2) < 0)
result = TRUE;
lua_pushboolean(L,result);
return 1;
}
int Address_register(lua_State *L) {
WSLUA_REGISTER_CLASS(Address);
return 0;
}
