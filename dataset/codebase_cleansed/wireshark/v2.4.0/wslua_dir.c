WSLUA_CONSTRUCTOR Dir_make(lua_State* L) {
#define WSLUA_ARG_Dir_make_NAME 1
const char *dir_path = luaL_checkstring(L, WSLUA_ARG_Dir_make_NAME);
ws_statb64 s_buf;
int ret;
if (ws_stat64(dir_path, &s_buf) != 0 && errno == ENOENT) {
ret = ws_mkdir(dir_path, 0755);
if (ret == -1) {
lua_pushnil(L);
} else {
lua_pushboolean(L, 1);
}
} else {
lua_pushboolean(L, 0);
}
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_exists(lua_State* L) {
#define WSLUA_ARG_Dir_exists_NAME 1
const char *dir_path = luaL_checkstring(L, WSLUA_ARG_Dir_exists_NAME);
int ret;
if ((ret = test_for_directory (dir_path)) == EISDIR) {
lua_pushboolean(L, 1);
} else {
if (ret == 0) {
lua_pushboolean(L, 0);
} else {
lua_pushnil(L);
}
}
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_remove(lua_State* L) {
#define WSLUA_ARG_Dir_remove_NAME 1
const char *dir_path = luaL_checkstring(L, WSLUA_ARG_Dir_remove_NAME);
int ret;
if (test_for_directory (dir_path) == EISDIR) {
ret = ws_remove(dir_path);
if (ret != 0) {
lua_pushnil(L);
} else {
lua_pushboolean(L, 1);
}
} else {
lua_pushboolean(L, 0);
}
WSLUA_RETURN(1);
}
static int delete_directory(const char *directory) {
WS_DIR *dir;
WS_DIRENT *file;
gchar *filename;
int ret = 0;
if ((dir = ws_dir_open(directory, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
filename = g_strdup_printf ("%s%s%s", directory, G_DIR_SEPARATOR_S,
ws_dir_get_name(file));
if (test_for_directory(filename) != EISDIR) {
ret = ws_remove(filename);
} else {
ret = delete_directory (filename);
}
if (ret != 0) {
break;
}
g_free (filename);
}
ws_dir_close(dir);
}
if (ret == 0) {
ret = ws_remove(directory);
}
return ret;
}
WSLUA_CONSTRUCTOR Dir_remove_all(lua_State* L) {
#define WSLUA_ARG_Dir_remove_all_NAME 1
const char *dir_path = luaL_checkstring(L, WSLUA_ARG_Dir_remove_all_NAME);
int ret;
if (test_for_directory (dir_path) == EISDIR) {
ret = delete_directory(dir_path);
if (ret != 0) {
lua_pushnil(L);
} else {
lua_pushboolean(L, 1);
}
} else {
lua_pushboolean(L, 0);
}
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_open(lua_State* L) {
#define WSLUA_ARG_Dir_open_PATHNAME 1
#define WSLUA_OPTARG_Dir_open_EXTENSION 2
const char* dirname = luaL_checkstring(L,WSLUA_ARG_Dir_open_PATHNAME);
const char* extension = luaL_optstring(L,WSLUA_OPTARG_Dir_open_EXTENSION,NULL);
Dir dir;
char* dirname_clean;
dirname_clean = wslua_get_actual_filename(dirname);
if (!dirname_clean) {
WSLUA_ARG_ERROR(Dir_open,PATHNAME,"directory does not exist");
return 0;
}
if (!test_for_directory(dirname_clean)) {
g_free(dirname_clean);
WSLUA_ARG_ERROR(Dir_open,PATHNAME, "must be a directory");
return 0;
}
dir = (Dir)g_malloc(sizeof(struct _wslua_dir));
dir->dir = g_dir_open(dirname_clean, 0, dir->dummy);
g_free(dirname_clean);
dir->ext = extension ? g_strdup(extension) : NULL;
dir->dummy = (GError **)g_malloc(sizeof(GError *));
*(dir->dummy) = NULL;
if (dir->dir == NULL) {
g_free(dir->dummy);
g_free(dir);
WSLUA_ARG_ERROR(Dir_open,PATHNAME,"could not open directory");
return 0;
}
pushDir(L,dir);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Dir__call(lua_State* L) {
Dir dir = checkDir(L,1);
const gchar* file;
const gchar* filename;
const char* ext;
if (!dir->dir) {
return 0;
}
if ( ! ( file = g_dir_read_name(dir->dir ) )) {
g_dir_close(dir->dir);
dir->dir = NULL;
return 0;
}
if ( ! dir->ext ) {
lua_pushstring(L,file);
return 1;
}
do {
filename = file;
if ( ( ext = strstr(filename,dir->ext)) && g_str_equal(ext,dir->ext) ) {
lua_pushstring(L,filename);
return 1;
}
} while(( file = g_dir_read_name(dir->dir) ));
g_dir_close(dir->dir);
dir->dir = NULL;
return 0;
}
WSLUA_METHOD Dir_close(lua_State* L) {
Dir dir = checkDir(L,1);
if (dir->dir) {
g_dir_close(dir->dir);
dir->dir = NULL;
}
return 0;
}
WSLUA_CONSTRUCTOR Dir_personal_config_path(lua_State* L) {
#define WSLUA_OPTARG_personal_config_path_FILENAME 1
const char *fname = luaL_optstring(L, WSLUA_OPTARG_personal_config_path_FILENAME,"");
char* filename = get_persconffile_path(fname,FALSE);
lua_pushstring(L,filename);
g_free(filename);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_global_config_path(lua_State* L) {
#define WSLUA_OPTARG_global_config_path_FILENAME 1
const char *fname = luaL_optstring(L, WSLUA_OPTARG_global_config_path_FILENAME,"");
char* filename;
if (running_in_build_directory()) {
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "epan" G_DIR_SEPARATOR_S "wslua"
G_DIR_SEPARATOR_S "%s", get_datafile_dir(), fname);
if (( ! file_exists(filename))) {
g_free(filename);
filename = get_datafile_path(fname);
}
} else {
filename = get_datafile_path(fname);
}
lua_pushstring(L,filename);
g_free(filename);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_personal_plugins_path(lua_State* L) {
char* filename = get_plugins_pers_dir();
lua_pushstring(L,filename);
g_free(filename);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Dir_global_plugins_path(lua_State* L) {
lua_pushstring(L, get_plugin_dir());
WSLUA_RETURN(1);
}
static int Dir__gc(lua_State* L) {
Dir dir = toDir(L,1);
if(!dir) return 0;
if (dir->dir) {
g_dir_close(dir->dir);
}
g_free(dir->dummy);
if (dir->ext) g_free(dir->ext);
g_free(dir);
return 0;
}
int Dir_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Dir);
return 0;
}
