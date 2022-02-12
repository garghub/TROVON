static File* push_File(lua_State* L, FILE_T ft) {
File f = (File) g_malloc(sizeof(struct _wslua_file));
f->file = ft;
f->wdh = NULL;
f->expired = FALSE;
return pushFile(L,f);
}
static File* push_Wdh(lua_State* L, wtap_dumper *wdh) {
File f = (File) g_malloc(sizeof(struct _wslua_file));
f->file = (FILE_T)wdh->fh;
f->wdh = wdh;
f->expired = FALSE;
return pushFile(L,f);
}
static gboolean file_is_reader(File f) {
return (f->wdh == NULL);
}
static int File_read_number (lua_State *L, FILE_T ft) {
lua_Number d;
gchar buff[WSLUA_MAXNUMBER2STR];
int buff_end = 0;
int c = -1;
int num_digits = 0;
gboolean has_decimal = FALSE;
c = file_peekc(ft);
if (c == '+' || c == '-') {
buff[buff_end++] = (gchar)c;
c = file_peekc(ft);
if (c < '0' || c > '9') {
lua_pushnil(L);
return 0;
}
file_getc(ft);
}
while((c = file_peekc(ft)) > 0 && buff_end < (WSLUA_MAXNUMBER2STR-1)) {
if (c >= '0' && c <= '9') {
buff[buff_end++] = (gchar)c;
num_digits++;
file_getc(ft);
}
else if (!has_decimal && c == '.') {
has_decimal = TRUE;
buff[buff_end++] = (gchar)c;
file_getc(ft);
}
else break;
}
buff[buff_end] = '\0';
if (buff_end > 0 && num_digits > 0 && sscanf(buff, "%lf", &d) == 1) {
lua_pushnumber(L, d);
return 1;
}
else {
lua_pushnil(L);
return 0;
}
}
static int File_read_line(lua_State *L, FILE_T ft) {
static gchar linebuff[MAX_LINE_LENGTH];
gint64 pos_before = file_tell(ft);
gint length = 0;
if (file_gets(linebuff, MAX_LINE_LENGTH, ft) == NULL) {
return 0;
}
length = (gint)(file_tell(ft) - pos_before);
if (linebuff[length-1] == '\n') {
length--;
if (length > 0 && linebuff[length - 1] == '\r') {
length--;
}
linebuff[length] = '\0';
}
lua_pushlstring(L, linebuff, length);
return 1;
}
static int File_read_chars(lua_State *L, FILE_T ft, size_t n) {
size_t rlen;
size_t nr;
int nri;
gchar buff[WSLUA_BUFFERSIZE];
luaL_Buffer b;
rlen = WSLUA_BUFFERSIZE;
luaL_buffinit(L, &b);
do {
if (rlen > n) rlen = n;
nri = file_read(buff, (unsigned int)rlen, ft);
if (nri < 1) break;
nr = (size_t) nri;
luaL_addlstring(&b, buff, nr);
n -= nr;
} while (n > 0 && nr == rlen);
luaL_pushresult(&b);
return (n == 0 || lua_rawlen(L, -1) > 0);
}
static int File_test_eof(lua_State *L, FILE_T ft) {
if (file_eof(ft)) {
lua_pushnil(L);
}
else {
lua_pushlstring(L, "", 0);
}
return 1;
}
static int pushresult (lua_State *L, int i, const char *filename) {
int en = errno;
if (i) {
lua_pushboolean(L, 1);
return 1;
}
else {
lua_pushnil(L);
if (filename)
lua_pushfstring(L, "%s: %s", filename, g_strerror(en));
else
lua_pushfstring(L, "%s", g_strerror(en));
lua_pushinteger(L, en);
return 3;
}
}
WSLUA_METHOD File_read(lua_State* L) {
File f = shiftFile(L,1);
int nargs = lua_gettop(L);
int success;
int n = 1;
FILE_T ft = NULL;
if (!f || !f->file) {
return 0;
}
if (f->expired) {
g_warning("Error in File read: Lua File has expired");
return 0;
}
if (!file_is_reader(f)) {
g_warning("Error in File read: this File object instance is for writing only");
return 0;
}
ft = f->file;
if (nargs == 0) {
success = File_read_line(L, ft);
n = 2;
}
else {
luaL_checkstack(L, nargs+LUA_MINSTACK, "too many arguments");
success = 1;
for (n = 1; nargs-- && success; n++) {
if (lua_type(L, n) == LUA_TNUMBER) {
size_t l = (size_t)lua_tointeger(L, n);
success = (l == 0) ? File_test_eof(L, ft) : File_read_chars(L, ft, l);
}
else {
const char *p = lua_tostring(L, n);
if (!p) return luaL_argerror(L, n, "invalid format argument");
luaL_argcheck(L, p[0] == '*', n, "invalid option");
switch (p[1]) {
case 'n':
success = File_read_number(L, ft);
break;
case 'l':
success = File_read_line(L, ft);
break;
case 'a':
File_read_chars(L, ft, ~((size_t)0));
success = 1;
break;
default:
return luaL_argerror(L, n, "invalid format");
}
}
}
}
if (file_error(ft, NULL))
return pushresult(L, 0, NULL);
if (!success) {
lua_pop(L, 1);
lua_pushnil(L);
}
return n - 1;
}
WSLUA_METHOD File_seek(lua_State* L) {
static const int mode[] = { SEEK_SET, SEEK_CUR, SEEK_END };
static const char *const modenames[] = {"set", "cur", "end", NULL};
File f = checkFile(L,1);
int op = luaL_checkoption(L, 2, "cur", modenames);
gint64 offset = (gint64) luaL_optlong(L, 3, 0);
int err = WTAP_ERR_INTERNAL;
if (file_is_reader(f)) {
offset = file_seek(f->file, offset, mode[op], &err);
if (offset < 0) {
lua_pushnil(L);
lua_pushstring(L, wtap_strerror(err));
return 2;
}
lua_pushnumber(L, (lua_Number)(file_tell(f->file)));
}
else {
offset = wtap_dump_file_seek(f->wdh, offset, mode[op], &err);
if (offset < 0) {
lua_pushnil(L);
lua_pushstring(L, wtap_strerror(err));
return 2;
}
offset = wtap_dump_file_tell(f->wdh, &err);
if (offset < 0) {
lua_pushnil(L);
lua_pushstring(L, wtap_strerror(err));
return 2;
}
lua_pushnumber(L, (lua_Number)(offset));
}
WSLUA_RETURN(1);
}
static int File_lines_iterator(lua_State* L) {
FILE_T ft = *(FILE_T *)lua_touserdata(L, lua_upvalueindex(1));
int success;
if (ft == NULL)
return luaL_error(L, "Error getting File handle for lines iterator");
success = File_read_line(L, ft);
return success;
}
WSLUA_METHOD File_lines(lua_State* L) {
File f = checkFile(L,1);
FILE_T ft = NULL;
if (!f->file)
return luaL_error(L, "Error getting File handle for lines");
if (!file_is_reader(f)) {
g_warning("Error in File read: this File object instance is for writing only");
return 0;
}
ft = f->file;
lua_pushlightuserdata(L, ft);
lua_pushcclosure(L, File_lines_iterator, 1);
return 1;
}
WSLUA_METHOD File_write(lua_State* L) {
File f = checkFile(L,1);
int arg = 2;
int nargs = lua_gettop(L) - 1;
int status = TRUE;
int err = 0;
if (!f->wdh) {
g_warning("Error in File read: this File object instance is for reading only");
return 0;
}
lua_pushvalue(L, 1);
for (; nargs--; arg++) {
size_t len;
const char *s = luaL_checklstring(L, arg, &len);
status = wtap_dump_file_write(f->wdh, s, len, &err);
if (!status) break;
f->wdh->bytes_dumped += len;
}
if (!status) {
lua_pop(L,1);
lua_pushnil(L);
lua_pushfstring(L, "File write error: %s", g_strerror(err));
lua_pushinteger(L, err);
return 3;
}
return 1;
}
WSLUA_METAMETHOD File__tostring(lua_State* L) {
File f = toFile(L,1);
if (!f) {
lua_pushstring(L,"File pointer is NULL!");
} else {
lua_pushfstring(L,"File expired=%s, handle=%s, is %s", f->expired? "true":"false", f->file? "<ptr>":"<NULL>",
f->wdh? "writer":"reader");
}
WSLUA_RETURN(1);
}
static int File__gc(lua_State* L _U_) {
File f = toFile(L,1);
if (f)
g_free(f);
return 0;
}
static int File_get_compressed(lua_State* L) {
File f = checkFile(L,1);
if (file_is_reader(f)) {
lua_pushboolean(L, file_iscompressed(f->file));
} else {
lua_pushboolean(L, f->wdh->compressed);
}
return 1;
}
int File_register(lua_State* L) {
WSLUA_REGISTER_CLASS(File);
WSLUA_REGISTER_ATTRIBUTES(File);
return 0;
}
static void create_wth_priv(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*)g_malloc(sizeof(file_priv_t));
if (wth->priv != NULL) {
luaL_error(L, "Cannot create wtap private data because there already is private data");
return;
}
priv->table_ref = LUA_NOREF;
wth->priv = (void*) priv;
}
static int get_wth_priv_table_ref(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return LUA_NOREF;
}
lua_rawgeti(L, LUA_REGISTRYINDEX, priv->table_ref);
return 1;
}
static int set_wth_priv_table_ref(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return 0;
}
if (lua_isnil(L, -1)){
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
priv->table_ref = LUA_NOREF;
return 0;
}
if (!lua_istable(L, -1)) {
luaL_error(L, "The private_table member can only be set to a table or nil");
return 0;
}
if (priv->table_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
priv->table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
static void remove_wth_priv(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot remove wtap private data: it is null");
return;
}
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
g_free(wth->priv);
wth->priv = NULL;
}
static void create_wdh_priv(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*)g_malloc(sizeof(file_priv_t));
if (wdh->priv != NULL) {
luaL_error(L, "Cannot create wtap_dumper private data because there already is private data");
return;
}
priv->table_ref = LUA_NOREF;
wdh->priv = (void*) priv;
}
static int get_wdh_priv_table_ref(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap_dumper private data: it is null");
return LUA_NOREF;
}
lua_rawgeti(L, LUA_REGISTRYINDEX, priv->table_ref);
return 1;
}
static int set_wdh_priv_table_ref(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return 0;
}
if (lua_isnil(L, -1)){
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
priv->table_ref = LUA_NOREF;
return 0;
}
if (!lua_istable(L, -1)) {
luaL_error(L, "The private_table member can only be set to a table or nil");
return 0;
}
if (priv->table_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
priv->table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
static void remove_wdh_priv(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot remove wtap_dumper private data: it is null");
return;
}
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
static CaptureInfo* push_CaptureInfo(lua_State* L, wtap *wth, const gboolean first_time) {
CaptureInfo f = (CaptureInfo) g_malloc0(sizeof(struct _wslua_captureinfo));
f->wth = wth;
f->wdh = NULL;
f->expired = FALSE;
if (first_time) {
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
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
lua_pushfstring(L, "CaptureInfo: file_type_subtype=%d, snapshot_length=%d, pkt_encap=%d, tsprecision='%s'",
wth->file_type_subtype, wth->snapshot_length, wth->phdr.pkt_encap, wth->tsprecision);
}
WSLUA_RETURN(1);
}
static int CaptureInfo__gc(lua_State* L _U_) {
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
static CaptureInfoConst* push_CaptureInfoConst(lua_State* L, wtap_dumper *wdh) {
CaptureInfoConst f = (CaptureInfoConst) g_malloc0(sizeof(struct _wslua_captureinfo));
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
lua_pushfstring(L, "CaptureInfoConst: file_type_subtype=%d, snaplen=%d, encap=%d, compressed=%d, tsprecision='%s'",
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
lua_pushlstring(L, (char*)(&ipv6_hash_list_entry->addr.bytes[0]), 16);
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
static int CaptureInfoConst__gc(lua_State* L _U_) {
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
static FrameInfo* push_FrameInfo(lua_State* L, struct wtap_pkthdr *phdr, Buffer* buf) {
FrameInfo f = (FrameInfo) g_malloc0(sizeof(struct _wslua_phdr));
f->phdr = phdr;
f->buf = buf;
f->expired = FALSE;
return pushFrameInfo(L,f);
}
WSLUA_METAMETHOD FrameInfo__tostring(lua_State* L) {
FrameInfo fi = toFrameInfo(L,1);
if (!fi) {
lua_pushstring(L,"FrameInfo pointer is NULL!");
} else {
if (fi->phdr)
lua_pushfstring(L, "FrameInfo: rec_type=%u, presence_flags=%d, caplen=%d, len=%d, pkt_encap=%d, opt_comment='%s'",
fi->phdr->rec_type, fi->phdr->presence_flags, fi->phdr->caplen, fi->phdr->len, fi->phdr->pkt_encap, fi->phdr->opt_comment);
else
lua_pushstring(L, "FrameInfo phdr pointer is NULL!");
}
WSLUA_RETURN(1);
}
WSLUA_METHOD FrameInfo_read_data(lua_State* L) {
#define WSLUA_ARG_FrameInfo_read_data_FILE 2
#define WSLUA_ARG_FrameInfo_read_data_LENGTH 3
FrameInfo fi = checkFrameInfo(L,1);
File fh = checkFile(L,WSLUA_ARG_FrameInfo_read_data_FILE);
guint32 len = wslua_checkguint32(L, WSLUA_ARG_FrameInfo_read_data_LENGTH);
int err = 0;
gchar *err_info = NULL;
if (!fi->buf || !fh->file) {
luaL_error(L, "FrameInfo read_data() got null buffer or file pointer internally");
return 0;
}
if (!wtap_read_packet_bytes(fh->file, fi->buf, len, &err, &err_info)) {
lua_pushboolean(L, FALSE);
if (err_info) {
lua_pushstring(L, err_info);
g_free(err_info);
}
else lua_pushnil(L);
lua_pushnumber(L, err);
return 3;
}
lua_pushboolean(L, TRUE);
WSLUA_RETURN(1);
}
static int FrameInfo__gc(lua_State* L _U_) {
FrameInfo fi = toFrameInfo(L,1);
if (fi)
g_free(fi);
return 0;
}
static int FrameInfo_set_time (lua_State* L) {
FrameInfo fi = checkFrameInfo(L,1);
NSTime nstime = checkNSTime(L,2);
if (!fi->phdr) return 0;
fi->phdr->ts.secs = nstime->secs;
fi->phdr->ts.nsecs = nstime->nsecs;
return 0;
}
static int FrameInfo_get_time (lua_State* L) {
FrameInfo fi = checkFrameInfo(L,1);
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
if (!nstime) return 0;
nstime->secs = fi->phdr->ts.secs;
nstime->nsecs = fi->phdr->ts.nsecs;
pushNSTime(L,nstime);
return 1;
}
static int FrameInfo_set_data (lua_State* L) {
FrameInfo fi = checkFrameInfo(L,1);
if (!fi->phdr) {
g_warning("Error in FrameInfo set data: NULL pointer");
return 0;
}
if (!fi->buf) {
g_warning("Error in FrameInfo set data: NULL frame_buffer pointer");
return 0;
}
if (lua_isstring(L,2)) {
size_t len = 0;
const gchar* s = luaL_checklstring(L,2,&len);
if (s) {
buffer_assure_space(fi->buf, len);
memcpy(buffer_start_ptr(fi->buf), s, len);
fi->phdr->caplen = (guint32) len;
fi->phdr->len = (guint32) len;
} else {
luaL_error(L, "FrameInfo's attribute 'data' did not get a valid Lua string");
}
}
else
luaL_error(L, "FrameInfo's attribute 'data' must be a Lua string");
return 0;
}
static int FrameInfo_get_data (lua_State* L) {
FrameInfo fi = checkFrameInfo(L,1);
if (!fi->buf) return 0;
lua_pushlstring(L, buffer_start_ptr(fi->buf), buffer_length(fi->buf));
WSLUA_RETURN(1);
}
int FrameInfo_register(lua_State* L) {
WSLUA_REGISTER_CLASS(FrameInfo);
WSLUA_REGISTER_ATTRIBUTES(FrameInfo);
return 0;
}
static FrameInfoConst* push_FrameInfoConst(lua_State* L, const struct wtap_pkthdr *phdr, const guint8 *pd) {
FrameInfoConst f = (FrameInfoConst) g_malloc(sizeof(struct _wslua_const_phdr));
f->phdr = phdr;
f->pd = pd;
f->expired = FALSE;
return pushFrameInfoConst(L,f);
}
WSLUA_METAMETHOD FrameInfoConst__tostring(lua_State* L) {
FrameInfoConst fi = toFrameInfoConst(L,1);
if (!fi) {
lua_pushstring(L,"FrameInfo pointer is NULL!");
} else {
if (fi->phdr && !fi->expired)
lua_pushfstring(L, "FrameInfo: rec_type=%u, presence_flags=%d, caplen=%d, len=%d, pkt_encap=%d, opt_comment='%s'",
fi->phdr->rec_type, fi->phdr->presence_flags, fi->phdr->caplen, fi->phdr->len, fi->phdr->pkt_encap, fi->phdr->opt_comment);
else
lua_pushfstring(L, "FrameInfo has %s", fi->phdr?"expired":"null phdr pointer");
}
WSLUA_RETURN(1);
}
WSLUA_METHOD FrameInfoConst_write_data(lua_State* L) {
#define WSLUA_ARG_FrameInfoConst_write_data_FILE 2
#define WSLUA_OPTARG_FrameInfoConst_write_data_LENGTH 3
FrameInfoConst fi = checkFrameInfoConst(L,1);
File fh = checkFile(L,WSLUA_ARG_FrameInfoConst_write_data_FILE);
guint32 len = wslua_optguint32(L, WSLUA_OPTARG_FrameInfoConst_write_data_LENGTH, fi->phdr ? fi->phdr->caplen:0);
int err = 0;
if (!fi->pd || !fi->phdr || !fh->wdh) {
luaL_error(L, "FrameInfoConst write_data() got null buffer or file pointer internally");
return 0;
}
if (len > fi->phdr->caplen)
len = fi->phdr->caplen;
if (!wtap_dump_file_write(fh->wdh, fi->pd, (size_t)(len), &err)) {
lua_pushboolean(L, FALSE);
lua_pushfstring(L, "FrameInfoConst write_data() error: %s", g_strerror(err));
lua_pushnumber(L, err);
return 3;
}
lua_pushboolean(L, TRUE);
WSLUA_RETURN(1);
}
static int FrameInfoConst__gc(lua_State* L _U_) {
FrameInfoConst fi = toFrameInfoConst(L,1);
if (fi)
g_free(fi);
return 0;
}
static int FrameInfoConst_get_time (lua_State* L) {
FrameInfoConst fi = checkFrameInfoConst(L,1);
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
if (!nstime) return 0;
nstime->secs = fi->phdr->ts.secs;
nstime->nsecs = fi->phdr->ts.nsecs;
pushNSTime(L,nstime);
return 1;
}
static int FrameInfoConst_get_data (lua_State* L) {
FrameInfoConst fi = checkFrameInfoConst(L,1);
if (!fi->pd || !fi->phdr) return 0;
lua_pushlstring(L, fi->pd, fi->phdr->caplen);
return 1;
}
int FrameInfoConst_register(lua_State* L) {
WSLUA_REGISTER_CLASS(FrameInfoConst);
WSLUA_REGISTER_ATTRIBUTES(FrameInfoConst);
return 0;
}
static int filehandler_cb_error_handler(lua_State* L) {
const gchar* error = lua_tostring(L,1);
const gchar* functype = luaL_optstring(L, lua_upvalueindex(1), "UNKNOWN");
report_failure("Lua: Error During execution of FileHandler %s callback:\n %s",functype,error);
lua_pop(L, 1);
return 0;
}
static int push_error_handler(lua_State* L, const gchar* funcname) {
lua_pushstring(L, funcname);
lua_pushcclosure(L, filehandler_cb_error_handler, 1);
return 1;
}
static int
wslua_filehandler_open(wtap *wth, int *err _U_, gchar **err_info)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
int retval = 0;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
INIT_FILEHANDLER_ROUTINE(read_open,0);
create_wth_priv(L, wth);
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, TRUE);
errno = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,2,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR_ERRINFO("read_open")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
if (retval == 1) {
if (fh->read_ref != LUA_NOREF) {
wth->subtype_read = wslua_filehandler_read;
}
else return 0;
if (fh->seek_read_ref != LUA_NOREF) {
wth->subtype_seek_read = wslua_filehandler_seek_read;
}
else return 0;
if (fh->read_close_ref != LUA_NOREF)
wth->subtype_close = wslua_filehandler_close;
else
wth->subtype_close = NULL;
if (fh->seq_read_close_ref != LUA_NOREF)
wth->subtype_sequential_close = wslua_filehandler_sequential_close;
else
wth->subtype_sequential_close = NULL;
wth->file_type_subtype = fh->file_type;
}
else {
remove_wth_priv(L, wth);
}
lua_settop(L,0);
return retval;
}
static gboolean
wslua_filehandler_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
FrameInfo *fi = NULL;
INIT_FILEHANDLER_ROUTINE(read,FALSE);
*err = errno = 0;
wth->phdr.opt_comment = NULL;
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, FALSE);
fi = push_FrameInfo(L, &wth->phdr, wth->frame_buffer);
errno = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,3,1,1) ) {
case 0:
if (lua_isnumber(L,-1)) {
*data_offset = wslua_togint64(L, -1);
retval = 1;
break;
}
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR_ERRINFO("read")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
(*fi)->expired = TRUE;
lua_settop(L,0);
return (retval == 1);
}
static gboolean
wslua_filehandler_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
FrameInfo *fi = NULL;
INIT_FILEHANDLER_ROUTINE(seek_read,FALSE);
*err = errno = 0;
phdr->opt_comment = NULL;
fp = push_File(L, wth->random_fh);
fc = push_CaptureInfo(L, wth, FALSE);
fi = push_FrameInfo(L, phdr, buf);
lua_pushnumber(L, (lua_Number)seek_off);
*err = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,4,1,1) ) {
case 0:
if (lua_isstring(L,-1)) {
size_t len = 0;
const gchar* fd = lua_tolstring(L, -1, &len);
if (len < WTAP_MAX_PACKET_SIZE)
memcpy(buffer_start_ptr(buf), fd, len);
retval = 1;
break;
}
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR_ERRINFO("seek_read")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
(*fi)->expired = TRUE;
lua_settop(L,0);
return (retval == 1);
}
static void
wslua_filehandler_close(wtap *wth)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
INIT_FILEHANDLER_ROUTINE(read_close,);
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, FALSE);
switch ( lua_pcall(L,2,1,1) ) {
case 0:
break;
CASE_ERROR("read_close")
}
END_FILEHANDLER_ROUTINE();
remove_wth_priv(L, wth);
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
lua_settop(L,0);
return;
}
static void
wslua_filehandler_sequential_close(wtap *wth)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
INIT_FILEHANDLER_ROUTINE(seq_read_close,);
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, FALSE);
switch ( lua_pcall(L,2,1,1) ) {
case 0:
break;
CASE_ERROR("seq_read_close")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
lua_settop(L,0);
return;
}
static int
wslua_dummy_can_write_encap(int encap _U_)
{
return WTAP_ERR_CHECK_WSLUA;
}
static int
wslua_filehandler_can_write_encap(int encap, void* data)
{
FileHandler fh = (FileHandler)(data);
int retval = WTAP_ERR_UNSUPPORTED_ENCAP;
lua_State* L = NULL;
INIT_FILEHANDLER_ROUTINE(can_write_encap,WTAP_ERR_INTERNAL);
lua_pushnumber(L, encap);
errno = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,1,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,WTAP_ERR_UNSUPPORTED_ENCAP);
break;
CASE_ERROR("can_write_encap")
}
END_FILEHANDLER_ROUTINE();
if (retval == 1) {
retval = 0;
} else if (retval == 0) {
retval = WTAP_ERR_UNSUPPORTED_ENCAP;
}
return retval;
}
static int
wslua_filehandler_dump_open(wtap_dumper *wdh, int *err)
{
FileHandler fh = (FileHandler)(wdh->wslua_data);
int retval = 0;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfoConst *fc = NULL;
INIT_FILEHANDLER_ROUTINE(write_open,0);
create_wdh_priv(L, wdh);
fp = push_Wdh(L, wdh);
fc = push_CaptureInfoConst(L,wdh);
*err = 0;
switch ( lua_pcall(L,2,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR("write_open")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
if (retval == 1) {
if (fh->write_ref != LUA_NOREF) {
wdh->subtype_write = wslua_filehandler_dump;
}
else {
g_warning("FileHandler was not set with a write function, even though write_open() returned true");
return 0;
}
if (fh->write_close_ref != LUA_NOREF)
wdh->subtype_close = wslua_filehandler_dump_close;
else
wdh->subtype_close = NULL;
}
else {
remove_wdh_priv(L, wdh);
}
return retval;
}
static gboolean
wslua_filehandler_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
FileHandler fh = (FileHandler)(wdh->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfoConst *fc = NULL;
FrameInfoConst *fi = NULL;
INIT_FILEHANDLER_ROUTINE(write,FALSE);
*err = errno = 0;
fp = push_Wdh(L, wdh);
fc = push_CaptureInfoConst(L,wdh);
fi = push_FrameInfoConst(L, phdr, pd);
errno = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,3,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR("write")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
(*fi)->expired = TRUE;
return (retval == 1);
}
static gboolean
wslua_filehandler_dump_close(wtap_dumper *wdh, int *err)
{
FileHandler fh = (FileHandler)(wdh->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfoConst *fc = NULL;
INIT_FILEHANDLER_ROUTINE(write_close,FALSE);
*err = errno = 0;
fp = push_Wdh(L, wdh);
fc = push_CaptureInfoConst(L,wdh);
errno = WTAP_ERR_CANT_READ;
switch ( lua_pcall(L,2,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,0);
break;
CASE_ERROR("write_close")
}
END_FILEHANDLER_ROUTINE();
remove_wdh_priv(L, wdh);
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
return (retval == 1);
}
WSLUA_CONSTRUCTOR FileHandler_new(lua_State* L) {
#define WSLUA_ARG_FileHandler_new_NAME 1
#define WSLUA_ARG_FileHandler_new_SHORTNAME 2
#define WSLUA_ARG_FileHandler_new_DESCRIPTION 3
#define WSLUA_ARG_FileHandler_new_TYPE 4
const gchar* name = luaL_checkstring(L,WSLUA_ARG_FileHandler_new_NAME);
const gchar* short_name = luaL_checkstring(L,WSLUA_ARG_FileHandler_new_SHORTNAME);
const gchar* desc = luaL_checkstring(L,WSLUA_ARG_FileHandler_new_DESCRIPTION);
const gchar* type = luaL_checkstring(L,WSLUA_ARG_FileHandler_new_TYPE);
FileHandler fh = (FileHandler) g_malloc0(sizeof(struct _wslua_filehandler));
fh->is_reader = (strchr(type,'r') != NULL) ? TRUE : FALSE;
fh->is_writer = (strchr(type,'w') != NULL) ? TRUE : FALSE;
if (fh->is_reader && wtap_has_open_info(short_name)) {
return luaL_error(L, "FileHandler.new: '%s' short name already exists for a reader!", short_name);
}
if (fh->is_writer && wtap_short_string_to_file_type_subtype(short_name) > -1) {
return luaL_error(L, "FileHandler.new: '%s' short name already exists for a writer!", short_name);
}
fh->type = g_strdup(type);
fh->finfo.name = g_strdup(name);
fh->finfo.short_name = g_strdup(short_name);
fh->finfo.default_file_extension = NULL;
fh->finfo.additional_file_extensions = NULL;
fh->finfo.writing_must_seek = FALSE;
fh->finfo.has_name_resolution = FALSE;
fh->finfo.can_write_encap = NULL;
fh->finfo.dump_open = NULL;
fh->file_type = WTAP_FILE_TYPE_SUBTYPE_UNKNOWN;
fh->description = g_strdup(desc);
fh->L = L;
fh->read_open_ref = LUA_NOREF;
fh->read_ref = LUA_NOREF;
fh->seek_read_ref = LUA_NOREF;
fh->read_close_ref = LUA_NOREF;
fh->seq_read_close_ref = LUA_NOREF;
fh->write_open_ref = LUA_NOREF;
fh->write_ref = LUA_NOREF;
fh->write_close_ref = LUA_NOREF;
fh->can_write_encap_ref = LUA_NOREF;
fh->registered = FALSE;
pushFileHandler(L,fh);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD FileHandler__tostring(lua_State* L) {
FileHandler fh = toFileHandler(L,1);
if (!fh) {
lua_pushstring(L,"FileHandler pointer is NULL!");
} else {
lua_pushfstring(L, "FileHandler(%s): short-name='%s', description='%s', read_open=%d, read=%d, write=%d",
fh->finfo.name, fh->finfo.short_name, fh->description, fh->read_open_ref, fh->read_ref, fh->write_ref);
}
WSLUA_RETURN(1);
}
static int FileHandler__gc(lua_State* L _U_) {
return 0;
}
static gboolean verify_filehandler_complete(FileHandler fh) {
return ((fh->is_reader || fh->is_writer) &&
(!fh->is_reader ||
(fh->is_reader &&
fh->read_open_ref != LUA_NOREF &&
fh->read_ref != LUA_NOREF &&
fh->seek_read_ref != LUA_NOREF)) &&
(!fh->is_writer ||
(fh->is_writer &&
fh->can_write_encap_ref != LUA_NOREF &&
fh->write_open_ref != LUA_NOREF &&
fh->write_ref != LUA_NOREF)) );
}
WSLUA_FUNCTION wslua_register_filehandler(lua_State* L) {
#define WSLUA_ARG_register_filehandler_FILEHANDLER 1
FileHandler fh = checkFileHandler(L,WSLUA_ARG_register_filehandler_FILEHANDLER);
if (in_routine)
return luaL_error(L,"a FileHAndler cannot be registered during reading/writing callback functions");
if (fh->registered)
return luaL_error(L,"this FileHandler is already registered");
if (!verify_filehandler_complete(fh))
return luaL_error(L,"this FileHandler is not complete enough to register");
if (fh->is_writer) {
fh->finfo.can_write_encap = wslua_dummy_can_write_encap;
fh->finfo.wslua_info = (wtap_wslua_file_info_t*) g_malloc0(sizeof(wtap_wslua_file_info_t));
fh->finfo.wslua_info->wslua_can_write_encap = wslua_filehandler_can_write_encap;
fh->finfo.wslua_info->wslua_data = (void*)(fh);
fh->finfo.dump_open = wslua_filehandler_dump_open;
}
fh->file_type = wtap_register_file_type_subtypes(&(fh->finfo),fh->file_type);
if (fh->is_reader) {
struct open_info oi = { NULL, OPEN_INFO_HEURISTIC, NULL, NULL, NULL, NULL };
oi.name = fh->finfo.short_name;
oi.open_routine = wslua_filehandler_open;
oi.extensions = fh->finfo.additional_file_extensions;
oi.wslua_data = (void*)(fh);
if (strchr(fh->type,'m') != NULL) {
oi.type = OPEN_INFO_MAGIC;
} else {
oi.type = OPEN_INFO_HEURISTIC;
}
wtap_register_open_info(&oi, (strchr(fh->type,'s') != NULL));
}
fh->registered = TRUE;
lua_pushnumber(L, fh->file_type);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_deregister_filehandler(lua_State* L) {
#define WSLUA_ARG_register_filehandler_FILEHANDLER 1
FileHandler fh = checkFileHandler(L,WSLUA_ARG_register_filehandler_FILEHANDLER);
if (in_routine)
return luaL_error(L,"A FileHAndler cannot be de-registered during reading/writing callback functions");
if (!fh->registered)
return 0;
fh->finfo.can_write_encap = NULL;
if (fh->finfo.wslua_info) {
fh->finfo.wslua_info->wslua_can_write_encap = NULL;
fh->finfo.wslua_info->wslua_data = NULL;
g_free(fh->finfo.wslua_info);
fh->finfo.wslua_info = NULL;
}
fh->finfo.dump_open = NULL;
if (fh->file_type != WTAP_FILE_TYPE_SUBTYPE_UNKNOWN)
wtap_deregister_file_type_subtype(fh->file_type);
if (fh->is_reader && wtap_has_open_info(fh->finfo.short_name)) {
wtap_deregister_open_info(fh->finfo.short_name);
}
fh->registered = FALSE;
return 0;
}
int FileHandler_register(lua_State* L) {
WSLUA_REGISTER_CLASS(FileHandler);
WSLUA_REGISTER_ATTRIBUTES(FileHandler);
return 0;
}
