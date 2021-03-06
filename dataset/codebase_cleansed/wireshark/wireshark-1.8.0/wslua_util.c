WSLUA_API gboolean wslua_optbool(lua_State* L, int n, gboolean def) {
gboolean val = FALSE;
if ( lua_isboolean(L,n) ) {
val = lua_toboolean(L,n);
} else if ( lua_isnil(L,n) || lua_gettop(L) < n ){
val = def;
} else {
luaL_argerror(L,n,"must be a boolean");
}
return val;
}
WSLUA_API const gchar* lua_shiftstring(lua_State* L, int i) {
const gchar* p = luaL_checkstring(L, i);
if (p) {
lua_remove(L,i);
return p;
} else {
return NULL;
}
}
WSLUA_FUNCTION wslua_get_version(lua_State* L) {
gchar* str = VERSION;
lua_pushstring(L,str);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_format_date(lua_State* LS) {
#define WSLUA_ARG_format_date_TIMESTAMP 1
lua_Number timestamp = luaL_checknumber(LS,WSLUA_ARG_format_date_TIMESTAMP);
nstime_t then;
gchar* str;
then.secs = (guint32)floor(timestamp);
then.nsecs = (guint32) ( (timestamp-(double)(then.secs))*1000000000);
str = abs_time_to_str(&then, ABSOLUTE_TIME_LOCAL, TRUE);
lua_pushstring(LS,str);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_format_time(lua_State* LS) {
#define WSLUA_ARG_format_time_TIMESTAMP 1
lua_Number timestamp = luaL_checknumber(LS,WSLUA_ARG_format_time_TIMESTAMP);
nstime_t then;
gchar* str;
then.secs = (guint32)floor(timestamp);
then.nsecs = (guint32) ( (timestamp-(double)(then.secs))*1000000000);
str = rel_time_to_str(&then);
lua_pushstring(LS,str);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_report_failure(lua_State* LS) {
#define WSLUA_ARG_report_failure_TEXT 1
const gchar* s = luaL_checkstring(LS,WSLUA_ARG_report_failure_TEXT);
report_failure("%s",s);
return 0;
}
static int wslua_log(lua_State* L, GLogLevelFlags log_level) {
GString* str = g_string_new("");
int n = lua_gettop(L);
int i;
lua_getglobal(L, "tostring");
for (i=1; i<=n; i++) {
const char *s;
lua_pushvalue(L, -1);
lua_pushvalue(L, i);
lua_call(L, 1, 1);
s = lua_tostring(L, -1);
if (s == NULL)
return luaL_error(L, "`tostring' must return a string");
if (i>1) g_string_append(str,"\t");
g_string_append(str,s);
lua_pop(L, 1);
}
g_log(LOG_DOMAIN_LUA, log_level, "%s\n", str->str);
g_string_free(str,TRUE);
return 0;
}
WSLUA_FUNCTION wslua_critical( lua_State* L ) {
wslua_log(L,G_LOG_LEVEL_CRITICAL);
return 0;
}
WSLUA_FUNCTION wslua_warn( lua_State* L ) {
wslua_log(L,G_LOG_LEVEL_WARNING);
return 0;
}
WSLUA_FUNCTION wslua_message( lua_State* L ) {
wslua_log(L,G_LOG_LEVEL_MESSAGE);
return 0;
}
WSLUA_FUNCTION wslua_info( lua_State* L ) {
wslua_log(L,G_LOG_LEVEL_INFO);
return 0;
}
WSLUA_FUNCTION wslua_debug( lua_State* L ) {
wslua_log(L,G_LOG_LEVEL_DEBUG);
return 0;
}
static char* wslua_get_actual_filename(const char* fname) {
char fname_clean[256];
char* f;
char* filename;
g_strlcpy(fname_clean,fname,255);
fname_clean[255] = '\0';
for(f = fname_clean; *f; f++) {
switch(*f) {
case '/': case '\\':
*f = *(G_DIR_SEPARATOR_S);
break;
default:
break;
}
}
if ( file_exists(fname_clean) ) {
return g_strdup(fname_clean);
}
filename = get_persconffile_path(fname_clean,FALSE,FALSE);
if ( file_exists(filename) ) {
return filename;
}
g_free(filename);
filename = get_datafile_path(fname_clean);
if ( file_exists(filename) ) {
return filename;
}
g_free(filename);
return NULL;
}
WSLUA_FUNCTION wslua_loadfile(lua_State* L) {
#define WSLUA_ARG_loadfile_FILENAME 1
const char *given_fname = luaL_checkstring(L, WSLUA_ARG_loadfile_FILENAME);
char* filename;
filename = wslua_get_actual_filename(given_fname);
if (!filename) WSLUA_ARG_ERROR(loadfile,FILENAME,"file does not exist");
if (luaL_loadfile(L, filename) == 0) {
g_free(filename);
return 1;
} else {
g_free(filename);
lua_pushnil(L);
lua_insert(L, -2);
return 2;
}
}
WSLUA_FUNCTION wslua_dofile(lua_State* L) {
#define WSLUA_ARG_dofile_FILENAME 1
const char *given_fname = luaL_checkstring(L, WSLUA_ARG_dofile_FILENAME);
char* filename;
int n;
if (!given_fname) WSLUA_ARG_ERROR(dofile,FILENAME,"must be a string");
filename = wslua_get_actual_filename(given_fname);
if (!filename) WSLUA_ARG_ERROR(dofile,FILENAME,"file does not exist");
n = lua_gettop(L);
if (luaL_loadfile(L, filename) != 0) lua_error(L);
g_free(filename);
lua_call(L, 0, LUA_MULTRET);
return lua_gettop(L) - n;
}
WSLUA_FUNCTION wslua_persconffile_path(lua_State* L) {
#define WSLUA_OPTARG_persconffile_path_FILENAME 1
const char *fname = luaL_optstring(L, WSLUA_OPTARG_persconffile_path_FILENAME,"");
char* filename = get_persconffile_path(fname,FALSE,FALSE);
lua_pushstring(L,filename);
g_free(filename);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_datafile_path(lua_State* L) {
#define WSLUA_OPTARG_datafile_path_FILENAME 1
const char *fname = luaL_optstring(L, WSLUA_OPTARG_datafile_path_FILENAME,"");
char* filename = get_datafile_path(fname);
lua_pushstring(L,filename);
g_free(filename);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_open(lua_State* L) {
#define WSLUA_ARG_Dir_open_PATHNAME 1
#define WSLUA_OPTARG_Dir_open_EXTENSION 2
const char* dirname = luaL_checkstring(L,WSLUA_ARG_Dir_open_PATHNAME);
const char* extension = luaL_optstring(L,WSLUA_OPTARG_Dir_open_EXTENSION,NULL);
Dir dir;
char* dirname_clean;
if (!dirname) WSLUA_ARG_ERROR(Dir_open,PATHNAME,"must be a string");
dirname_clean = wslua_get_actual_filename(dirname);
if (!dirname_clean) WSLUA_ARG_ERROR(Dir_open,PATHNAME,"directory does not exist");
if (!test_for_directory(dirname_clean)) {
g_free(dirname_clean);
WSLUA_ARG_ERROR(Dir_open,PATHNAME, "must be a directory");
}
dir = g_malloc(sizeof(struct _wslua_dir));
dir->dir = OPENDIR_OP(dirname_clean);
g_free(dirname_clean);
dir->ext = extension ? g_strdup(extension) : NULL;
dir->dummy = g_malloc(sizeof(GError *));
*(dir->dummy) = NULL;
if (dir->dir == NULL) {
g_free(dir->dummy);
g_free(dir);
WSLUA_ARG_ERROR(Dir_open,PATHNAME,"could not open directory");
}
pushDir(L,dir);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Dir__call(lua_State* L) {
Dir dir = checkDir(L,1);
const FILE_T* file;
const gchar* filename;
const char* ext;
if (!dir) {
luaL_argerror(L,1,"must be a Dir");
return 0;
}
if (!dir->dir) {
return 0;
}
if ( ! ( file = DIRGETNEXT_OP(dir->dir ) )) {
CLOSEDIR_OP(dir->dir);
dir->dir = NULL;
return 0;
}
if ( ! dir->ext ) {
filename = GETFNAME_OP(file);
lua_pushstring(L,filename);
return 1;
}
do {
filename = GETFNAME_OP(file);
if ( ( ext = strstr(filename,dir->ext)) && g_str_equal(ext,dir->ext) ) {
lua_pushstring(L,filename);
return 1;
}
} while(( file = DIRGETNEXT_OP(dir->dir) ));
CLOSEDIR_OP(dir->dir);
dir->dir = NULL;
return 0;
}
WSLUA_METHOD Dir_close(lua_State* L) {
Dir dir = checkDir(L,1);
if (dir->dir) {
CLOSEDIR_OP(dir->dir);
dir->dir = NULL;
}
return 0;
}
static int wslua_Dir__gc(lua_State* L) {
Dir dir = checkDir(L,1);
if (dir->dir) {
CLOSEDIR_OP(dir->dir);
}
g_free(dir->dummy);
if (dir->ext) g_free(dir->ext);
g_free(dir);
return 0;
}
int Dir_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Dir);
return 1;
}
static int statcmd_init_cb_error_handler(lua_State* L) {
(void)L;
return 0;
}
static void statcmd_init(const char *optarg, void* userdata) {
statcmd_t* sc = userdata;
lua_State* L = sc->L;
lua_settop(L,0);
lua_pushcfunction(L,statcmd_init_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, sc->func_ref);
lua_pushstring(L,optarg);
switch ( lua_pcall(L,1,0,1) ) {
case 0:
break;
case LUA_ERRRUN:
g_warning("Runtime error while calling statcmd callback");
break;
case LUA_ERRMEM:
g_warning("Memory alloc error while calling statcmd callback");
break;
default:
g_assert_not_reached();
break;
}
}
WSLUA_FUNCTION wslua_register_stat_cmd_arg(lua_State* L) {
#define WSLUA_ARG_register_stat_cmd_arg_ARGUMENT 1
#define WSLUA_OPTARG_register_stat_cmd_arg_ACTION 2
const char* arg = luaL_checkstring(L,WSLUA_ARG_register_stat_cmd_arg_ARGUMENT);
statcmd_t* sc = g_malloc0(sizeof(statcmd_t));
sc->L = L;
lua_pushvalue(L, WSLUA_OPTARG_register_stat_cmd_arg_ACTION);
sc->func_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_remove(L,1);
register_stat_cmd_arg(arg, statcmd_init, sc);
return 0;
}
