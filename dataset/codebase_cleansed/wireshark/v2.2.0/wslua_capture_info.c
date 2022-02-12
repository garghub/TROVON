CaptureInfo* push_CaptureInfo(lua_State* L, wtap *wth, const gboolean first_time) {
CaptureInfo f;
if (!wth) {
luaL_error(L, "Internal error: wth is NULL!");
return NULL;
}
f = (CaptureInfo) g_malloc0(sizeof(struct _wslua_captureinfo));
f->wth = wth;
f->wdh = NULL;
f->expired = FALSE;
if (first_time) {
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->file_tsprec = WTAP_TSPREC_UNKNOWN;
wth->snapshot_length = 0;
}
return pushCaptureInfo(L,f);
}
WSLUA_METAMETHOD CaptureInfo__tostring(lua_State* L) {
CaptureInfo fi = toCaptureInfo(L,1);
if (!fi || !fi->wth) {
lua_pushstring(L,"CaptureInfo pointer is NULL!");
} else {
wtap *wth = fi->wth;
lua_pushfstring(L, "CaptureInfo: file_type_subtype=%d, snapshot_length=%d, pkt_encap=%d, file_tsprec='%s'",
wth->file_type_subtype, wth->snapshot_length, wth->phdr.pkt_encap, wth->file_tsprec);
}
WSLUA_RETURN(1);
}
static int CaptureInfo__gc(lua_State* L) {
CaptureInfo fc = toCaptureInfo(L,1);
if (fc)
g_free(fc);
return 0;
}
static int CaptureInfo_set_hosts(lua_State* L) {
CaptureInfo fi = checkCaptureInfo(L,1);
wtap *wth = fi->wth;
const char *addr = NULL;
const char *name = NULL;
size_t addr_len = 0;
size_t name_len = 0;
guint32 v4_addr = 0;
struct e_in6_addr v6_addr = { {0} };
if (!wth->add_new_ipv4 || !wth->add_new_ipv6) {
return luaL_error(L, "CaptureInfo wtap has no IPv4 or IPv6 name resolution");
}
if (!lua_istable(L,-1)) {
return luaL_error(L, "CaptureInfo.host must be set to a table");
}
lua_getfield(L, -1, "ipv4_addresses");
if (lua_istable(L,-1)) {
lua_pushnil(L);
while (lua_next(L, -2) != 0) {
if (!lua_istable(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv4_addresses table does not contain a table");
}
lua_getfield(L, -1, "addr");
if (!lua_isstring(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv4_addresses table's table does not contain an 'addr' field");
}
addr = luaL_checklstring(L,-1,&addr_len);
if (addr_len != 4) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv4_addresses 'addr' value is not 4 bytes long");
}
memcpy(&v4_addr, addr, 4);
lua_getfield(L, -1, "name");
if (!lua_isstring(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv4_addresses table's table does not contain an 'addr' field");
}
name = luaL_checklstring(L,-1,&name_len);
wth->add_new_ipv4(v4_addr, name);
lua_pop(L, 1);
}
}
lua_pop(L,1);
lua_getfield(L, -1, "ip6_addresses");
if (lua_istable(L,-1)) {
lua_pushnil(L);
while (lua_next(L, -2) != 0) {
if (!lua_istable(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv6_addresses table does not contain a table");
}
lua_getfield(L, -1, "addr");
if (!lua_isstring(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv6_addresses table's table does not contain an 'addr' field");
}
addr = luaL_checklstring(L,-1,&addr_len);
if (addr_len != 16) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv6_addresses 'addr' value is not 16 bytes long");
}
memcpy(&v6_addr, addr, 16);
lua_getfield(L, -1, "name");
if (!lua_isstring(L,-1)) {
lua_pop(L, 3);
return luaL_error(L, "CaptureInfo.host ipv6_addresses table's table does not contain an 'addr' field");
}
name = luaL_checklstring(L,-1,&name_len);
wth->add_new_ipv6((const void *)(&v6_addr), name);
lua_pop(L, 1);
}
}
lua_pop(L,1);
return 0;
}
static int CaptureInfo_get_private_table(lua_State* L) {
CaptureInfo fi = checkCaptureInfo(L,1);
return get_wth_priv_table_ref(L, fi->wth);
}
static int CaptureInfo_set_private_table(lua_State* L) {
CaptureInfo fi = checkCaptureInfo(L,1);
return set_wth_priv_table_ref(L, fi->wth);
}
int CaptureInfo_register(lua_State* L) {
WSLUA_REGISTER_META(CaptureInfo);
WSLUA_REGISTER_ATTRIBUTES(CaptureInfo);
return 0;
}
CaptureInfoConst* push_CaptureInfoConst(lua_State* L, wtap_dumper *wdh) {
CaptureInfoConst f;
if (!wdh) {
luaL_error(L, "Internal error: wdh is NULL!");
return NULL;
}
f = (CaptureInfoConst) g_malloc0(sizeof(struct _wslua_captureinfo));
f->wth = NULL;
f->wdh = wdh;
f->expired = FALSE;
return pushCaptureInfoConst(L,f);
}
WSLUA_METAMETHOD CaptureInfoConst__tostring(lua_State* L) {
CaptureInfoConst fi = toCaptureInfoConst(L,1);
if (!fi || !fi->wdh) {
lua_pushstring(L,"CaptureInfoConst pointer is NULL!");
} else {
wtap_dumper *wdh = fi->wdh;
lua_pushfstring(L, "CaptureInfoConst: file_type_subtype=%d, snaplen=%d, encap=%d, compressed=%d, file_tsprec='%s'",
wdh->file_type_subtype, wdh->snaplen, wdh->encap, wdh->compressed, wdh->tsprecision);
}
WSLUA_RETURN(1);
}
static int CaptureInfoConst_get_hosts(lua_State* L) {
CaptureInfoConst fi = checkCaptureInfoConst(L,1);
wtap_dumper *wdh = fi->wdh;
lua_newtable(L);
lua_newtable(L);
if (wdh->addrinfo_lists && wdh->addrinfo_lists->ipv4_addr_list) {
hashipv4_t *ipv4_hash_list_entry = (hashipv4_t *)g_list_nth_data(wdh->addrinfo_lists->ipv4_addr_list, 0);
int i, j;
for (i=1, j=1; ipv4_hash_list_entry != NULL; i++) {
if ((ipv4_hash_list_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED) {
lua_pushnumber(L, j);
lua_newtable(L);
lua_pushlstring(L, (char*)(&ipv4_hash_list_entry->ip), 4);
lua_setfield(L, -2, "addr");
lua_pushstring(L, ipv4_hash_list_entry->name);
lua_setfield(L, -2, "name");
lua_settable(L, -3);
j++;
}
ipv4_hash_list_entry = (hashipv4_t *)g_list_nth_data(wdh->addrinfo_lists->ipv4_addr_list, i);
}
}
lua_setfield(L, -2, "ipv4_addresses");
lua_newtable(L);
if (wdh->addrinfo_lists && wdh->addrinfo_lists->ipv6_addr_list) {
hashipv6_t *ipv6_hash_list_entry = (hashipv6_t *)g_list_nth_data(wdh->addrinfo_lists->ipv6_addr_list, 0);
int i, j;
for (i=1, j=1; ipv6_hash_list_entry != NULL; i++) {
if ((ipv6_hash_list_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED) {
lua_pushnumber(L, j);
lua_newtable(L);
lua_pushlstring(L, (char*)(&ipv6_hash_list_entry->addr[0]), 16);
lua_setfield(L, -2, "addr");
lua_pushstring(L, ipv6_hash_list_entry->name);
lua_setfield(L, -2, "name");
lua_settable(L, -3);
j++;
}
ipv6_hash_list_entry = (hashipv6_t *)g_list_nth_data(wdh->addrinfo_lists->ipv6_addr_list, i);
}
}
lua_setfield(L, -2, "ip6_addresses");
return 1;
}
static int CaptureInfoConst_get_private_table(lua_State* L) {
CaptureInfoConst fi = checkCaptureInfoConst(L,1);
return get_wdh_priv_table_ref(L, fi->wdh);
}
static int CaptureInfoConst_set_private_table(lua_State* L) {
CaptureInfoConst fi = checkCaptureInfoConst(L,1);
return set_wdh_priv_table_ref(L, fi->wdh);
}
static int CaptureInfoConst__gc(lua_State* L) {
CaptureInfoConst fi = toCaptureInfoConst(L,1);
if (fi)
g_free(fi);
return 0;
}
int CaptureInfoConst_register(lua_State* L) {
WSLUA_REGISTER_META(CaptureInfoConst);
WSLUA_REGISTER_ATTRIBUTES(CaptureInfoConst);
return 0;
}
