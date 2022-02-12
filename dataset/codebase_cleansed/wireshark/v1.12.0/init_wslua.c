static void lua_frame_end(void)
{
clear_outstanding_Tvb();
clear_outstanding_TvbRange();
clear_outstanding_Pinfo();
clear_outstanding_Column();
clear_outstanding_Columns();
clear_outstanding_PrivateTable();
clear_outstanding_TreeItem();
clear_outstanding_FieldInfo();
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
proto_tree_add_expert_format(tree, pinfo, &ei_lua_error, tvb, 0, 0, "Lua Error: %s", lua_tostring(L,-1));
} else {
if (lua_isnumber(L, -1)) {
consumed_bytes = wslua_togint(L, -1);
lua_pop(L, 1);
}
}
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_lua_error, tvb, 0, 0,
"Lua Error: did not find the %s dissector in the dissectors table", pinfo->current_proto);
}
register_frame_end_routine(pinfo, lua_frame_end);
lua_pinfo = NULL;
lua_tree = NULL;
lua_tvb = NULL;
return consumed_bytes;
}
gboolean heur_dissect_lua(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
gboolean result = FALSE;
lua_tvb = tvb;
lua_pinfo = pinfo;
if (!tvb || !pinfo || !pinfo->heur_list_name || !pinfo->current_proto) {
report_failure("internal error in heur_dissect_lua: NULL packet info");
return FALSE;
}
lua_settop(L,0);
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_heur_dissectors_table_ref);
if (!wslua_get_table(L, -1, pinfo->heur_list_name)) {
lua_settop(L,0);
report_failure("internal error in heur_dissect_lua: no %s heur list table", pinfo->heur_list_name);
return FALSE;
}
if (!wslua_get_field(L,-1,pinfo->current_proto)) {
lua_settop(L,0);
report_failure("internal error in heur_dissect_lua: no %s heuristic dissector for list %s",
pinfo->current_proto, pinfo->heur_list_name);
return FALSE;
}
lua_remove(L,1);
lua_remove(L,1);
if (!lua_isfunction(L,-1)) {
lua_settop(L,0);
report_failure("internal error in heur_dissect_lua: %s heuristic dissector is not a function", pinfo->current_proto);
return FALSE;
}
lua_tree = (struct _wslua_treeitem *)g_malloc(sizeof(struct _wslua_treeitem));
lua_tree->tree = tree;
lua_tree->item = proto_tree_add_text(tree,tvb,0,0,"lua fake item");
lua_tree->expired = FALSE;
PROTO_ITEM_SET_HIDDEN(lua_tree->item);
push_Tvb(L,tvb);
push_Pinfo(L,pinfo);
push_TreeItem(L,lua_tree);
if ( lua_pcall(L,3,1,0) ) {
report_failure(" error calling %s heuristic dissector: %s", pinfo->current_proto, lua_tostring(L,-1));
lua_settop(L,0);
} else {
if (lua_isboolean(L, -1) || lua_isnil(L, -1)) {
result = lua_toboolean(L, -1);
} else {
report_failure(" invalid return value from Lua %s heuristic dissector", pinfo->current_proto);
}
lua_pop(L, 1);
}
register_frame_end_routine(pinfo, lua_frame_end);
lua_pinfo = NULL;
lua_tree = NULL;
lua_tvb = NULL;
return result;
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
static int prefs_changed_error_handler(lua_State* LS) {
const gchar* error = lua_tostring(LS,1);
report_failure("Lua: Error During execution of prefs apply callback:\n %s",error);
return 0;
}
void wslua_prefs_changed(void) {
if (L) {
iter_table_and_call(L, WSLUA_PREFS_CHANGED,prefs_changed_error_handler);
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
static int lua_script_push_args(const int script_num) {
gchar* argname = g_strdup_printf("lua_script%d", script_num);
const gchar* argvalue = NULL;
int count = 0;
while((argvalue = ex_opt_get_next(argname))) {
lua_pushstring(L,argvalue);
count++;
}
g_free(argname);
return count;
}
static void set_file_environment(const gchar* filename, const gchar* dirname) {
const char* path;
char* personal = get_plugins_pers_dir();
lua_newtable(L);
lua_pushstring(L, filename);
lua_setfield(L, -2, FILE_NAME_KEY);
lua_pushstring(L, dirname);
lua_setfield(L, -2, DIR_NAME_KEY);
lua_pushstring(L, G_DIR_SEPARATOR_S);
lua_setfield(L, -2, DIR_SEP_NAME_KEY);
lua_newtable(L);
#if LUA_VERSION_NUM >= 502
lua_pushglobaltable(L);
#else
lua_pushvalue(L, LUA_GLOBALSINDEX);
#endif
lua_getfield(L, -1, "package");
lua_getfield(L, -1, "path");
path = luaL_checkstring(L, -1);
lua_pop(L, 1);
lua_pushfstring(L, "%s" G_DIR_SEPARATOR_S "?.lua;%s" G_DIR_SEPARATOR_S "?.lua;%s" G_DIR_SEPARATOR_S "?.lua;%s",
dirname, personal, get_plugin_dir(), path);
lua_setfield(L, -2, "path");
lua_setfield(L, -2, "package");
lua_setfield(L, -2, "__index");
lua_setmetatable(L, -2);
#if LUA_VERSION_NUM >= 502
lua_setupvalue(L, -2, 1);
#else
lua_setfenv(L, -2);
#endif
g_free(personal);
}
static gboolean lua_load_script(const gchar* filename, const gchar* dirname, const int file_count) {
FILE* file;
int error;
int numargs = 0;
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
if (dirname) {
set_file_environment(filename, dirname);
}
if (file_count > 0) {
numargs = lua_script_push_args(file_count);
}
lua_pcall(L,numargs,0,1);
fclose(file);
lua_pop(L,1);
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
static int lua_load_plugins(const char *dirname, register_cb cb, gpointer client_data,
gboolean count_only, const gboolean is_user)
{
WS_DIR *dir;
WS_DIRENT *file;
gchar *filename, *dot;
const gchar *name;
int plugins_counter = 0;
if ((dir = ws_dir_open(dirname, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
continue;
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", dirname, name);
if (test_for_directory(filename) == EISDIR) {
plugins_counter += lua_load_plugins(filename, cb, client_data, count_only, is_user);
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
if (!count_only) {
if (cb)
(*cb)(RA_LUA_PLUGINS, name, client_data);
if (lua_load_script(filename, is_user ? dirname : NULL, 0)) {
wslua_add_plugin(g_strdup(name), g_strdup(""), g_strdup(filename));
}
}
plugins_counter++;
}
g_free(filename);
}
ws_dir_close(dir);
}
return plugins_counter;
}
int wslua_count_plugins(void) {
gchar* filename;
int plugins_counter;
plugins_counter = lua_load_plugins(get_plugin_dir(), NULL, NULL, TRUE, FALSE);
filename = get_persconffile_path("init.lua", FALSE);
if ((file_exists(filename))) {
plugins_counter++;
}
g_free(filename);
filename = get_plugins_pers_dir();
plugins_counter += lua_load_plugins(filename, NULL, NULL, TRUE, TRUE);
g_free(filename);
plugins_counter += ex_opt_count("lua_script");
return plugins_counter;
}
void wslua_plugins_get_descriptions(wslua_plugin_description_callback callback, void *user_data) {
wslua_plugin *lua_plug;
for (lua_plug = wslua_plugin_list; lua_plug != NULL; lua_plug = lua_plug->next)
{
callback(lua_plug->name, lua_plug->version, "lua script",
lua_plug->filename, user_data);
}
}
static void
print_wslua_plugin_description(const char *name, const char *version,
const char *description, const char *filename,
void *user_data _U_)
{
printf("%s\t%s\t%s\t%s\n", name, version, description, filename);
}
void
wslua_plugins_dump_all(void)
{
wslua_plugins_get_descriptions(print_wslua_plugin_description, NULL);
}
expert_field*
wslua_get_expert_field(const int group, const int severity)
{
int i;
const ei_register_info *ei = ws_lua_ei;
g_assert(ei);
for (i=0; i < ws_lua_ei_len; i++, ei++) {
if (ei->eiinfo.group == group && ei->eiinfo.severity == severity)
return ei->ids;
}
return &ei_lua_error;
}
int wslua_init(register_cb cb, gpointer client_data) {
gchar* filename;
const gchar *script_filename;
const funnel_ops_t* ops = funnel_get_funnel_ops();
gboolean run_anyway = FALSE;
expert_module_t* expert_lua;
int file_count = 1;
static ei_register_info ei[] = {
{ &ei_lua_proto_checksum_comment, { "_ws.lua.proto.comment", PI_CHECKSUM, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_checksum_chat, { "_ws.lua.proto.chat", PI_CHECKSUM, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_checksum_note, { "_ws.lua.proto.note", PI_CHECKSUM, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_checksum_warn, { "_ws.lua.proto.warning", PI_CHECKSUM, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_checksum_error, { "_ws.lua.proto.error", PI_CHECKSUM, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_sequence_comment, { "_ws.lua.proto.comment", PI_SEQUENCE, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_sequence_chat, { "_ws.lua.proto.chat", PI_SEQUENCE, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_sequence_note, { "_ws.lua.proto.note", PI_SEQUENCE, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_sequence_warn, { "_ws.lua.proto.warning", PI_SEQUENCE, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_sequence_error, { "_ws.lua.proto.error", PI_SEQUENCE, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_response_comment, { "_ws.lua.proto.comment", PI_RESPONSE_CODE, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_response_chat, { "_ws.lua.proto.chat", PI_RESPONSE_CODE, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_response_note, { "_ws.lua.proto.note", PI_RESPONSE_CODE, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_response_warn, { "_ws.lua.proto.warning", PI_RESPONSE_CODE, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_response_error, { "_ws.lua.proto.error", PI_RESPONSE_CODE, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_request_comment, { "_ws.lua.proto.comment", PI_REQUEST_CODE, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_request_chat, { "_ws.lua.proto.chat", PI_REQUEST_CODE, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_request_note, { "_ws.lua.proto.note", PI_REQUEST_CODE, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_request_warn, { "_ws.lua.proto.warning", PI_REQUEST_CODE, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_request_error, { "_ws.lua.proto.error", PI_REQUEST_CODE, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_undecoded_comment, { "_ws.lua.proto.comment", PI_UNDECODED, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_undecoded_chat, { "_ws.lua.proto.chat", PI_UNDECODED, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_undecoded_note, { "_ws.lua.proto.note", PI_UNDECODED, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_undecoded_warn, { "_ws.lua.proto.warning", PI_UNDECODED, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_undecoded_error, { "_ws.lua.proto.error", PI_UNDECODED, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_reassemble_comment, { "_ws.lua.proto.comment", PI_REASSEMBLE, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_reassemble_chat, { "_ws.lua.proto.chat", PI_REASSEMBLE, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_reassemble_note, { "_ws.lua.proto.note", PI_REASSEMBLE, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_reassemble_warn, { "_ws.lua.proto.warning", PI_REASSEMBLE, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_reassemble_error, { "_ws.lua.proto.error", PI_REASSEMBLE, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_malformed_comment, { "_ws.lua.proto.comment", PI_MALFORMED, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_malformed_chat, { "_ws.lua.proto.chat", PI_MALFORMED, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_malformed_note, { "_ws.lua.proto.note", PI_MALFORMED, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_malformed_warn, { "_ws.lua.proto.warning", PI_MALFORMED, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_malformed_error, { "_ws.lua.proto.error", PI_MALFORMED, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_debug_comment, { "_ws.lua.proto.comment", PI_DEBUG, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_debug_chat, { "_ws.lua.proto.chat", PI_DEBUG, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_debug_note, { "_ws.lua.proto.note", PI_DEBUG, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_debug_warn, { "_ws.lua.proto.warning", PI_DEBUG, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_debug_error, { "_ws.lua.proto.error", PI_DEBUG, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_protocol_comment, { "_ws.lua.proto.comment", PI_PROTOCOL, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_protocol_chat, { "_ws.lua.proto.chat", PI_PROTOCOL, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_protocol_note, { "_ws.lua.proto.note", PI_PROTOCOL, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_protocol_warn, { "_ws.lua.proto.warning", PI_PROTOCOL, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_protocol_error, { "_ws.lua.proto.error", PI_PROTOCOL, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_security_comment, { "_ws.lua.proto.comment", PI_SECURITY, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_security_chat, { "_ws.lua.proto.chat", PI_SECURITY, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_security_note, { "_ws.lua.proto.note", PI_SECURITY, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_security_warn, { "_ws.lua.proto.warning", PI_SECURITY, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_security_error, { "_ws.lua.proto.error", PI_SECURITY, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_proto_comments_comment, { "_ws.lua.proto.comment", PI_COMMENTS_GROUP, PI_COMMENT ,"Protocol Comment", EXPFILL }},
{ &ei_lua_proto_comments_chat, { "_ws.lua.proto.chat", PI_COMMENTS_GROUP, PI_CHAT ,"Protocol Chat", EXPFILL }},
{ &ei_lua_proto_comments_note, { "_ws.lua.proto.note", PI_COMMENTS_GROUP, PI_NOTE ,"Protocol Note", EXPFILL }},
{ &ei_lua_proto_comments_warn, { "_ws.lua.proto.warning", PI_COMMENTS_GROUP, PI_WARN ,"Protocol Warning", EXPFILL }},
{ &ei_lua_proto_comments_error, { "_ws.lua.proto.error", PI_COMMENTS_GROUP, PI_ERROR ,"Protocol Error", EXPFILL }},
{ &ei_lua_error, { "_ws.lua.error", PI_UNDECODED, PI_ERROR ,"Lua Error", EXPFILL }},
};
ws_lua_ei = ei;
ws_lua_ei_len = array_length(ei);
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
proto_lua = proto_register_protocol("Lua Dissection", "Lua Dissection", "_ws.lua");
expert_lua = expert_register_protocol(proto_lua);
expert_register_field_array(expert_lua, ei, array_length(ei));
lua_atpanic(L,wslua_panic);
lua_newtable (L);
lua_setglobal(L, WSLUA_INIT_ROUTINES);
lua_newtable (L);
lua_dissectors_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_newtable (L);
lua_heur_dissectors_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_newtable (L);
lua_setglobal(L, WSLUA_PREFS_CHANGED);
WSLUA_REG_GLOBAL_BOOL(L,"running_superuser",started_with_special_privs());
WSLUA_REG_GLOBAL_NUMBER(L,"DESEGMENT_ONE_MORE_SEGMENT",DESEGMENT_ONE_MORE_SEGMENT);
if (running_in_build_directory()) {
filename = g_strdup_printf("%s" G_DIR_SEPARATOR_S "epan" G_DIR_SEPARATOR_S "wslua"
G_DIR_SEPARATOR_S "init.lua", get_progfile_dir());
} else {
filename = get_datafile_path("init.lua");
}
if (( file_exists(filename))) {
lua_load_script(filename, NULL, 0);
}
g_free(filename);
filename = NULL;
lua_getglobal(L,"disable_lua");
if (lua_isboolean(L,-1) && lua_toboolean(L,-1)) {
lua_close(L);
L = NULL;
return 0;
}
lua_pop(L,1);
lua_load_plugins(get_plugin_dir(), cb, client_data, FALSE, FALSE);
lua_getglobal(L,"run_user_scripts_when_superuser");
if (lua_isboolean(L,-1) && lua_toboolean(L,-1)) {
run_anyway = TRUE;
}
lua_pop(L,1);
if ( (!started_with_special_privs()) || run_anyway ) {
filename = get_persconffile_path("init.lua", FALSE);
if ((file_exists(filename))) {
if (cb)
(*cb)(RA_LUA_PLUGINS, get_basename(filename), client_data);
lua_load_script(filename, NULL, 0);
}
g_free(filename);
filename = get_plugins_pers_dir();
lua_load_plugins(filename, cb, client_data, FALSE, TRUE);
g_free(filename);
while((script_filename = ex_opt_get_next("lua_script"))) {
char* dirname = g_strdup(script_filename);
char* dname = get_dirname(dirname);
if (cb)
(*cb)(RA_LUA_PLUGINS, get_basename(script_filename), client_data);
lua_load_script(script_filename, dname ? dname : "", file_count);
file_count++;
g_free(dirname);
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
int wslua_cleanup(void) {
lua_close(L);
L = NULL;
return 0;
}
lua_State* wslua_state(void) { return L; }
