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
static wtap_open_return_val
wslua_filehandler_open(wtap *wth, int *err, gchar **err_info)
{
FileHandler fh = (FileHandler)(wth->wslua_data);
wtap_open_return_val retval = WTAP_OPEN_NOT_MINE;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfo *fc = NULL;
INIT_FILEHANDLER_ROUTINE(read_open,WTAP_OPEN_NOT_MINE);
create_wth_priv(L, wth);
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, TRUE);
errno = WTAP_ERR_CANT_OPEN;
switch ( lua_pcall(L,2,1,1) ) {
case 0:
retval = (wtap_open_return_val)wslua_optboolint(L,-1,0);
break;
CASE_ERROR_ERRINFO("read_open")
}
END_FILEHANDLER_ROUTINE();
(*fp)->expired = TRUE;
(*fc)->expired = TRUE;
if (retval == WTAP_OPEN_MINE) {
if (fh->read_ref != LUA_NOREF) {
wth->subtype_read = wslua_filehandler_read;
}
else {
ws_g_warning("Lua file format module lacks a read routine");
return WTAP_OPEN_NOT_MINE;
}
if (fh->seek_read_ref != LUA_NOREF) {
wth->subtype_seek_read = wslua_filehandler_seek_read;
}
else {
ws_g_warning("Lua file format module lacks a seek-read routine");
return WTAP_OPEN_NOT_MINE;
}
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
else if (retval == WTAP_OPEN_ERROR) {
if (err) {
*err = WTAP_ERR_CANT_OPEN;
}
}
else if (retval == WTAP_OPEN_NOT_MINE) {
remove_wth_priv(L, wth);
}
else {
ws_g_warning("FileHandler read_open routine returned %d", retval);
if (err) {
*err = WTAP_ERR_INTERNAL;
}
retval = WTAP_OPEN_ERROR;
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
if (err) {
*err = errno = 0;
}
wth->phdr.opt_comment = NULL;
fp = push_File(L, wth->fh);
fc = push_CaptureInfo(L, wth, FALSE);
fi = push_FrameInfo(L, &wth->phdr, wth->frame_buffer);
switch ( lua_pcall(L,3,1,1) ) {
case 0:
if (lua_type(L, -1) == LUA_TNUMBER) {
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
if (err) {
*err = errno = 0;
}
phdr->opt_comment = NULL;
fp = push_File(L, wth->random_fh);
fc = push_CaptureInfo(L, wth, FALSE);
fi = push_FrameInfo(L, phdr, buf);
lua_pushnumber(L, (lua_Number)seek_off);
switch ( lua_pcall(L,4,1,1) ) {
case 0:
retval = lua_toboolean(L, -1);
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
int retval = WTAP_ERR_UNWRITABLE_ENCAP;
lua_State* L = NULL;
INIT_FILEHANDLER_ROUTINE(can_write_encap,WTAP_ERR_INTERNAL);
lua_pushnumber(L, encap);
switch ( lua_pcall(L,1,1,1) ) {
case 0:
retval = wslua_optboolint(L,-1,WTAP_ERR_UNWRITABLE_ENCAP);
break;
CASE_ERROR("can_write_encap")
}
END_FILEHANDLER_ROUTINE();
if (retval == 1) {
retval = 0;
} else if (retval == 0) {
retval = WTAP_ERR_UNWRITABLE_ENCAP;
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
if (err) {
*err = 0;
}
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
ws_g_warning("FileHandler was not set with a write function, even though write_open() returned true");
return 0;
}
if (fh->write_close_ref != LUA_NOREF)
wdh->subtype_finish = wslua_filehandler_dump_finish;
else
wdh->subtype_finish = NULL;
}
else {
remove_wdh_priv(L, wdh);
}
return retval;
}
static gboolean
wslua_filehandler_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
FileHandler fh = (FileHandler)(wdh->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfoConst *fc = NULL;
FrameInfoConst *fi = NULL;
INIT_FILEHANDLER_ROUTINE(write,FALSE);
if (err) {
*err = errno = 0;
}
fp = push_Wdh(L, wdh);
fc = push_CaptureInfoConst(L,wdh);
fi = push_FrameInfoConst(L, phdr, pd);
errno = WTAP_ERR_CANT_WRITE;
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
wslua_filehandler_dump_finish(wtap_dumper *wdh, int *err)
{
FileHandler fh = (FileHandler)(wdh->wslua_data);
int retval = -1;
lua_State* L = NULL;
File *fp = NULL;
CaptureInfoConst *fc = NULL;
INIT_FILEHANDLER_ROUTINE(write_close,FALSE);
if (err) {
*err = errno = 0;
}
fp = push_Wdh(L, wdh);
fc = push_CaptureInfoConst(L,wdh);
errno = WTAP_ERR_CANT_CLOSE;
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
return luaL_error(L,"a FileHandler cannot be registered during reading/writing callback functions");
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
return luaL_error(L,"A FileHandler cannot be deregistered during reading/writing callback functions");
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
int wslua_deregister_filehandlers(lua_State* L _U_) {
return 0;
}
