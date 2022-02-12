File* push_File(lua_State* L, FILE_T ft) {
File f = (File) g_malloc(sizeof(struct _wslua_file));
f->file = ft;
f->wdh = NULL;
f->expired = FALSE;
return pushFile(L,f);
}
File* push_Wdh(lua_State* L, wtap_dumper *wdh) {
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
lua_pushnil(L);
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
ws_g_warning("Error in File read: Lua File has expired");
return 0;
}
if (!file_is_reader(f)) {
ws_g_warning("Error in File read: this File object instance is for writing only");
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
ws_g_warning("Error in File read: this File object instance is for writing only");
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
ws_g_warning("Error in File read: this File object instance is for reading only");
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
static int File__gc(lua_State* L) {
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
