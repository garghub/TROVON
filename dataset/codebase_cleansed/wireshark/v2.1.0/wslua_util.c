WSLUA_FUNCTION wslua_get_version(lua_State* L) {
const gchar* str = VERSION;
lua_pushstring(L,str);
WSLUA_RETURN(1);
}
const gchar* get_current_plugin_version(void) {
return current_plugin_version ? current_plugin_version : "";
}
void clear_current_plugin_version(void) {
if (current_plugin_version != NULL) {
g_free(current_plugin_version);
current_plugin_version = NULL;
}
}
WSLUA_FUNCTION wslua_set_plugin_info(lua_State* L) {
#define WSLUA_ARG_set_plugin_info_TABLE 1
if ( lua_istable(L,WSLUA_ARG_set_plugin_info_TABLE) ) {
int top;
lua_getfield(L, WSLUA_ARG_set_plugin_info_TABLE, "version");
top = lua_gettop(L);
if (lua_isstring(L, top)) {
clear_current_plugin_version();
current_plugin_version = g_strdup( luaL_checkstring(L, top) );
lua_pop(L, 1);
}
else {
return luaL_error(L,"the Lua table must have a 'version' key entry with a string value");
}
} else {
return luaL_error(L,"a Lua table with at least a 'version' string entry");
}
return 0;
}
WSLUA_FUNCTION wslua_format_date(lua_State* LS) {
#define WSLUA_ARG_format_date_TIMESTAMP 1
lua_Number timestamp = luaL_checknumber(LS,WSLUA_ARG_format_date_TIMESTAMP);
nstime_t then;
gchar* str;
then.secs = (guint32)(floor(timestamp));
then.nsecs = (guint32) ( (timestamp-(double)(then.secs))*1000000000);
str = abs_time_to_str(NULL, &then, ABSOLUTE_TIME_LOCAL, TRUE);
lua_pushstring(LS,str);
wmem_free(NULL, str);
WSLUA_RETURN(1);
}
WSLUA_FUNCTION wslua_format_time(lua_State* LS) {
#define WSLUA_ARG_format_time_TIMESTAMP 1
lua_Number timestamp = luaL_checknumber(LS,WSLUA_ARG_format_time_TIMESTAMP);
nstime_t then;
gchar* str;
then.secs = (guint32)(floor(timestamp));
then.nsecs = (guint32) ( (timestamp-(double)(then.secs))*1000000000);
str = rel_time_to_str(NULL, &then);
lua_pushstring(LS,str);
wmem_free(NULL, str);
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
char* wslua_get_actual_filename(const char* fname) {
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
filename = get_persconffile_path(fname_clean,FALSE);
if ( file_exists(filename) ) {
return filename;
}
g_free(filename);
filename = get_datafile_path(fname_clean);
if ( file_exists(filename) ) {
return filename;
}
g_free(filename);
if (running_in_build_directory()) {
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "epan" G_DIR_SEPARATOR_S "wslua"
G_DIR_SEPARATOR_S "%s", get_datafile_dir(), fname_clean);
if (( ! file_exists(filename))) {
g_free(filename);
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_progfile_dir(), fname_clean);
}
if ( file_exists(filename) ) {
return filename;
}
g_free(filename);
}
return NULL;
}
WSLUA_FUNCTION wslua_loadfile(lua_State* L) {
#define WSLUA_ARG_loadfile_FILENAME 1
const char *given_fname = luaL_checkstring(L, WSLUA_ARG_loadfile_FILENAME);
char* filename;
filename = wslua_get_actual_filename(given_fname);
if (!filename) {
WSLUA_ARG_ERROR(loadfile,FILENAME,"file does not exist");
return 0;
}
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
char* filename = wslua_get_actual_filename(given_fname);
int n;
if (!filename) {
WSLUA_ARG_ERROR(dofile,FILENAME,"file does not exist");
return 0;
}
n = lua_gettop(L);
if (luaL_loadfile(L, filename) != 0) lua_error(L);
g_free(filename);
lua_call(L, 0, LUA_MULTRET);
return lua_gettop(L) - n;
}
static int statcmd_init_cb_error_handler(lua_State* L _U_) {
return 0;
}
static void statcmd_init(const char *opt_arg, void* userdata) {
statcmd_t* sc = (statcmd_t *)userdata;
lua_State* L = sc->L;
lua_settop(L,0);
lua_pushcfunction(L,statcmd_init_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, sc->func_ref);
lua_pushstring(L,opt_arg);
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
statcmd_t* sc = (statcmd_t *)g_malloc0(sizeof(statcmd_t));
stat_tap_ui ui_info;
sc->L = L;
lua_pushvalue(L, WSLUA_OPTARG_register_stat_cmd_arg_ACTION);
sc->func_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_remove(L,1);
ui_info.group = REGISTER_STAT_GROUP_UNSORTED;
ui_info.title = NULL;
ui_info.cli_string = arg;
ui_info.tap_init_cb = statcmd_init;
ui_info.nparams = 0;
ui_info.params = NULL;
register_stat_tap_ui(&ui_info, sc);
return 0;
}
