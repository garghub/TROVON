FrameInfo* push_FrameInfo(lua_State* L, struct wtap_pkthdr *phdr, Buffer* buf) {
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
ws_buffer_assure_space(fi->buf, len);
memcpy(ws_buffer_start_ptr(fi->buf), s, len);
fi->phdr->caplen = (guint32) len;
fi->phdr->len = (guint32) len;
}
else
luaL_error(L, "FrameInfo's attribute 'data' must be a Lua string");
return 0;
}
static int FrameInfo_get_data (lua_State* L) {
FrameInfo fi = checkFrameInfo(L,1);
if (!fi->buf) return 0;
lua_pushlstring(L, ws_buffer_start_ptr(fi->buf), ws_buffer_length(fi->buf));
WSLUA_RETURN(1);
}
int FrameInfo_register(lua_State* L) {
WSLUA_REGISTER_CLASS(FrameInfo);
WSLUA_REGISTER_ATTRIBUTES(FrameInfo);
return 0;
}
FrameInfoConst* push_FrameInfoConst(lua_State* L, const struct wtap_pkthdr *phdr, const guint8 *pd) {
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
