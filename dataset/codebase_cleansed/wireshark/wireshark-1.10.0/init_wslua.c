static void lua_frame_end(void)
{
clear_outstanding_Tvb();
clear_outstanding_TvbRange();
clear_outstanding_Pinfo();
clear_outstanding_Column();
clear_outstanding_Columns();
clear_outstanding_PrivateTable();
clear_outstanding_TreeItem();
}
static int wslua_not_register_menu(lua_State* LS) {
luaL_error(LS,"too late to register a menu");
return 0;
}
int dissect_lua(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
int consumed_bytes = tvb_length(tvb);
lua_pinfo = pinfo;
lua_tvb = tvb;
lua_tree = (struct _wslua_treeitem *)g_malloc(sizeof(struct _wslua_treeitem));
lua_tree->tree = tree;
lua_tree->item = proto_tree_add_text(tree,tvb,0,0,"lua fake item");
lua_tree->expired = FALSE;
PROTO_ITEM_SET_HIDDEN(lua_tree->item);
lua_settop(L,0);
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_dissectors_table_ref);
lua_pushstring(L, pinfo->current_proto);
lua_gettable(L, -2);
lua_remove(L,1);
if (lua_isfunction(L,1)) {
push_Tvb(L,tvb);
push_Pinfo(L,pinfo);
push_TreeItem(L,lua_tree);
if ( lua_pcall(L,3,1,0) ) {
const gchar* error = lua_tostring(L,-1);
proto_item* pi = proto_tree_add_text(tree,tvb,0,0,"Lua Error: %s",error);
expert_add_info_format(pinfo, pi, PI_UNDECODED, PI_ERROR ,"Lua Error");
} else {
if (lua_isnumber(L, -1)) {
consumed_bytes = (int) lua_tonumber(L, -1);
lua_pop(L, 1);
}
}
} else {
proto_item* pi = proto_tree_add_text(tree,tvb,0,0,"Lua Error: did not find the %s dissector"
" in the dissectors table",pinfo->current_proto);
expert_add_info_format(pinfo, pi, PI_UNDECODED, PI_ERROR ,"Lua Error");
}
register_frame_end_routine(pinfo, lua_frame_end);
lua_pinfo = NULL;
lua_tree = NULL;
lua_tvb = NULL;
return consumed_bytes;
}
static void iter_table_and_call(lua_State* LS, const gchar* table_name, lua_CFunction error_handler) {
lua_settop(LS,0);
lua_pushcfunction(LS,error_handler);
lua_getglobal(LS, table_name);
if (!lua_istable(LS, 2)) {
report_failure("Lua: either `%s' does not exist or it is not a table!\n",table_name);
lua_close(LS);
L = NULL;
return;
}
lua_pushnil(LS);
while (lua_next(LS, 2)) {
const gchar* name = lua_tostring(L,-2);
if (lua_isfunction(LS,-1)) {
if ( lua_pcall(LS,0,0,1) ) {
lua_pop(LS,1);
}
} else {
report_failure("Lua: Something not a function got its way into the %s.%s",table_name,name);
lua_close(LS);
L = NULL;
return;
}
}
lua_settop(LS,0);
}
static int init_error_handler(lua_State* LS) {
const gchar* error = lua_tostring(LS,1);
report_failure("Lua: Error During execution of Initialization:\n %s",error);
return 0;
}
static void wslua_init_routine(void) {
static gboolean initialized = FALSE;
if ( ! initialized ) {
lua_prime_all_fields(NULL);
initialized = TRUE;
}
if (L) {
iter_table_and_call(L, WSLUA_INIT_ROUTINES,init_error_handler);
}
}
static const char *getF(lua_State *LS _U_, void *ud, size_t *size)
{
FILE *f=(FILE *)ud;
static char buff[512];
if (feof(f)) return NULL;
*size=fread(buff,1,sizeof(buff),f);
return (*size>0) ? buff : NULL;
}
static int lua_main_error_handler(lua_State* LS) {
const gchar* error = lua_tostring(LS,1);
report_failure("Lua: Error during loading:\n %s",error);
return 0;
}
static void wslua_add_plugin(gchar *name, gchar *version, gchar *filename)
{
wslua_plugin *new_plug, *lua_plug;
lua_plug = wslua_plugin_list;
new_plug = (wslua_plugin *)g_malloc(sizeof(wslua_plugin));
if (!lua_plug) {
wslua_plugin_list = new_plug;
} else {
while (lua_plug->next != NULL) {
lua_plug = lua_plug->next;
}
lua_plug->next = new_plug;
}
new_plug->name = name;
new_plug->version = version;
new_plug->filename = filename;
new_plug->next = NULL;
}
static gboolean lua_load_script(const gchar* filename) {
FILE* file;
int error;
if (! ( file = ws_fopen(filename,"r")) ) {
report_open_failure(filename,errno,FALSE);
return FALSE;
}
lua_settop(L,0);
lua_pushcfunction(L,lua_main_error_handler);
#if LUA_VERSION_NUM >= 502
error = lua_load(L,getF,file,filename,NULL);
#else
error = lua_load(L,getF,file,filename);
#endif
switch (error) {
case 0:
lua_pcall(L,0,0,1);
fclose(file);
return TRUE;
case LUA_ERRSYNTAX: {
report_failure("Lua: syntax error during precompilation of `%s':\n%s",filename,lua_tostring(L,-1));
fclose(file);
return FALSE;
}
case LUA_ERRMEM:
report_failure("Lua: memory allocation error during execution of %s",filename);
fclose(file);
return FALSE;
default:
report_failure("Lua: unknown error during execution of %s: %d",filename,error);
fclose(file);
return FALSE;
}
}
static void basic_logger(const gchar *log_domain _U_,
GLogLevelFlags log_level _U_,
const gchar *message,
gpointer user_data _U_) {
fputs(message,stderr);
}
static int wslua_panic(lua_State* LS) {
g_error("LUA PANIC: %s",lua_tostring(LS,-1));
return 0;
}
static void lua_load_plugins (const char *dirname)
{
WS_DIR *dir;
WS_DIRENT *file;
gchar *filename, *dot;
const gchar *name;
if ((dir = ws_dir_open(dirname, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
continue;
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", dirname, name);
if (test_for_directory(filename) == EISDIR) {
lua_load_plugins(filename);
g_free(filename);
continue;
}
if (name[0] == '.') {
g_free(filename);
continue;
}
dot = strrchr(name, '.');
if (dot == NULL || g_ascii_strcasecmp(dot+1, "lua") != 0) {
g_free(filename);
continue;
}
if (file_exists(filename)) {
if (lua_load_script(filename)) {
wslua_add_plugin(g_strdup(name), g_strdup(""), g_strdup(filename));
}
}
g_free(filename);
}
ws_dir_close(dir);
}
}
int wslua_init(register_cb cb, gpointer client_data) {
gchar* filename;
const funnel_ops_t* ops = funnel_get_funnel_ops();
gboolean run_anyway = FALSE;
if(cb)
(*cb)(RA_LUA_PLUGINS, NULL, client_data);
g_log_set_handler(LOG_DOMAIN_LUA, (GLogLevelFlags)(G_LOG_LEVEL_CRITICAL|
G_LOG_LEVEL_WARNING|
G_LOG_LEVEL_MESSAGE|
G_LOG_LEVEL_INFO|
G_LOG_LEVEL_DEBUG),
ops ? ops->logger : basic_logger,
NULL);
if (!L) {
L = luaL_newstate();
}
WSLUA_INIT(L);
lua_atpanic(L,wslua_panic);
lua_newtable (L);
lua_setglobal(L, WSLUA_INIT_ROUTINES);
lua_newtable (L);
lua_dissectors_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
WSLUA_REG_GLOBAL_BOOL(L,"running_superuser",started_with_special_privs());
WSLUA_REG_GLOBAL_NUMBER(L,"DESEGMENT_ONE_MORE_SEGMENT",DESEGMENT_ONE_MORE_SEGMENT);
filename = get_datafile_path("init.lua");
if (( file_exists(filename))) {
lua_load_script(filename);
}
g_free(filename);
filename = NULL;
lua_getglobal(L,"disable_lua");
if (lua_isboolean(L,-1) && lua_toboolean(L,-1)) {
lua_close(L);
L = NULL;
return 0;
}
lua_load_plugins(get_plugin_dir());
lua_getglobal(L,"run_user_scripts_when_superuser");
if (lua_isboolean(L,-1) && lua_toboolean(L,-1)) {
run_anyway = TRUE;
}
if ( (!started_with_special_privs()) || run_anyway ) {
filename = get_persconffile_path("init.lua", FALSE);
if ((file_exists(filename))) {
lua_load_script(filename);
}
g_free(filename);
filename = get_plugins_pers_dir();
lua_load_plugins(filename);
g_free(filename);
while((filename = (gchar *)ex_opt_get_next("lua_script"))) {
lua_load_script(filename);
}
}
register_init_routine(wslua_init_routine);
lua_pushcfunction(L, wslua_not_register_menu);
lua_setglobal(L, "register_menu");
lua_pinfo = NULL;
lua_tree = NULL;
lua_tvb = NULL;
lua_data_handle = find_dissector("data");
Proto_commit(L);
return 0;
}
lua_State* wslua_state(void) { return L; }
