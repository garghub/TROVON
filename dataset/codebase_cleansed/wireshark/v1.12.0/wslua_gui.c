static int menu_cb_error_handler(lua_State* L) {
const gchar* error = lua_tostring(L,1);
report_failure("Lua: Error During execution of Menu Callback:\n %s",error);
return 0;
}
WSLUA_FUNCTION wslua_gui_enabled(lua_State* L) {
lua_pushboolean(L,GPOINTER_TO_INT(ops && ops->add_button));
WSLUA_RETURN(1);
}
static void lua_menu_callback(gpointer data) {
struct _lua_menu_data* md = (struct _lua_menu_data *)data;
lua_State* L = md->L;
lua_settop(L,0);
lua_pushcfunction(L,menu_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, md->cb_ref);
switch ( lua_pcall(L,0,0,1) ) {
case 0:
break;
case LUA_ERRRUN:
g_warning("Runtime error while calling menu callback");
break;
case LUA_ERRMEM:
g_warning("Memory alloc error while calling menu callback");
break;
default:
g_assert_not_reached();
break;
}
return;
}
WSLUA_FUNCTION wslua_register_menu(lua_State* L) {
#define WSLUA_ARG_register_menu_NAME 1
#define WSLUA_ARG_register_menu_ACTION 2
#define WSLUA_OPTARG_register_menu_GROUP 3
const gchar* name = luaL_checkstring(L,WSLUA_ARG_register_menu_NAME);
struct _lua_menu_data* md;
gboolean retap = FALSE;
register_stat_group_t group = (register_stat_group_t)wslua_optguint(L,WSLUA_OPTARG_register_menu_GROUP,REGISTER_STAT_GROUP_GENERIC);
if ( group > REGISTER_TOOLS_GROUP_UNSORTED) {
WSLUA_OPTARG_ERROR(register_menu,GROUP,"Must be a defined MENU_* (see init.lua)");
return 0;
}
if(!name) {
WSLUA_ARG_ERROR(register_menu,NAME,"Must be a string");
return 0;
}
if (!lua_isfunction(L,WSLUA_ARG_register_menu_ACTION)) {
WSLUA_ARG_ERROR(register_menu,ACTION,"Must be a function");
return 0;
}
md = (struct _lua_menu_data *)g_malloc(sizeof(struct _lua_menu_data));
md->L = L;
lua_pushvalue(L, 2);
md->cb_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_remove(L,2);
funnel_register_menu(name,
group,
lua_menu_callback,
md,
retap);
WSLUA_RETURN(0);
}
static int dlg_cb_error_handler(lua_State* L) {
const gchar* error = lua_tostring(L,1);
report_failure("Lua: Error During execution of dialog callback:\n %s",error);
return 0;
}
static void lua_dialog_cb(gchar** user_input, void* data) {
struct _dlg_cb_data* dcbd = (struct _dlg_cb_data *)data;
int i = 0;
gchar* input;
lua_State* L = dcbd->L;
lua_settop(L,0);
lua_pushcfunction(L,dlg_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, dcbd->func_ref);
for (i = 0; (input = user_input[i]) ; i++) {
lua_pushstring(L,input);
g_free(input);
}
g_free(user_input);
switch ( lua_pcall(L,i,0,1) ) {
case 0:
break;
case LUA_ERRRUN:
g_warning("Runtime error while calling dialog callback");
break;
case LUA_ERRMEM:
g_warning("Memory alloc error while calling dialog callback");
break;
default:
g_assert_not_reached();
break;
}
}
static int text_win_close_cb_error_handler(lua_State* L) {
const gchar* error = lua_tostring(L,1);
report_failure("Lua: Error During execution of TextWindow close callback:\n %s",error);
return 0;
}
static void text_win_close_cb(void* data) {
struct _close_cb_data* cbd = (struct _close_cb_data *)data;
lua_State* L = cbd->L;
if (cbd->L) {
lua_settop(L,0);
lua_pushcfunction(L,text_win_close_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, cbd->func_ref);
switch ( lua_pcall(L,0,0,1) ) {
case 0:
break;
case LUA_ERRRUN:
g_warning("Runtime error during execution of TextWindow close callback");
break;
case LUA_ERRMEM:
g_warning("Memory alloc error during execution of TextWindow close callback");
break;
default:
break;
}
}
if (cbd->wslua_tw->expired) {
g_free(cbd->wslua_tw);
} else {
cbd->wslua_tw->expired = TRUE;
}
}
WSLUA_FUNCTION wslua_new_dialog(lua_State* L) {
#define WSLUA_ARG_new_dialog_TITLE 1
#define WSLUA_ARG_new_dialog_ACTION 2
const gchar* title;
int top = lua_gettop(L);
int i;
GPtrArray* labels;
struct _dlg_cb_data* dcbd;
if (! ops) {
luaL_error(L,"the GUI facility has to be enabled");
return 0;
}
if (!ops->new_dialog) {
WSLUA_ERROR(new_dialog,"GUI not available");
return 0;
}
if (! (title = luaL_checkstring(L,WSLUA_ARG_new_dialog_TITLE)) ) {
WSLUA_ARG_ERROR(new_dialog,TITLE,"Must be a string");
return 0;
}
if (! lua_isfunction(L,WSLUA_ARG_new_dialog_ACTION)) {
WSLUA_ARG_ERROR(new_dialog,ACTION,"Must be a function");
return 0;
}
if (top < 3) {
WSLUA_ERROR(new_dialog,"At least one field required");
return 0;
}
dcbd = (struct _dlg_cb_data *)g_malloc(sizeof(struct _dlg_cb_data));
dcbd->L = L;
lua_remove(L,1);
lua_pushvalue(L, 1);
dcbd->func_ref = luaL_ref(L, LUA_REGISTRYINDEX);
lua_remove(L,1);
labels = g_ptr_array_new();
top -= 2;
for (i = 1; i <= top; i++) {
gchar* label = g_strdup(luaL_checkstring(L,i));
if (! label) {
g_ptr_array_free(labels,TRUE);
WSLUA_ERROR(new_dialog,"All fields must be strings");
return 0;
}
g_ptr_array_add(labels,(gpointer)label);
}
g_ptr_array_add(labels,NULL);
ops->new_dialog(title, (const gchar**)(labels->pdata), lua_dialog_cb, dcbd);
g_ptr_array_free(labels,TRUE);
WSLUA_RETURN(0);
}
WSLUA_CONSTRUCTOR ProgDlg_new(lua_State* L) {
#define WSLUA_OPTARG_ProgDlg_new_TITLE 2
#define WSLUA_OPTARG_ProgDlg_new_TASK 3
ProgDlg pd = (ProgDlg)g_malloc(sizeof(struct _wslua_progdlg));
pd->title = g_strdup(luaL_optstring(L,WSLUA_OPTARG_ProgDlg_new_TITLE,"Progress"));
pd->task = g_strdup(luaL_optstring(L,WSLUA_OPTARG_ProgDlg_new_TASK,""));
pd->stopped = FALSE;
if (ops->new_progress_window) {
pd->pw = ops->new_progress_window(pd->title,pd->task,TRUE,&(pd->stopped));
} else {
WSLUA_ERROR(ProgDlg_new, "GUI not available");
return 0;
}
pushProgDlg(L,pd);
WSLUA_RETURN(1);
}
WSLUA_METHOD ProgDlg_update(lua_State* L) {
#define WSLUA_ARG_ProgDlg_update_PROGRESS 2
#define WSLUA_OPTARG_ProgDlg_update_TASK 3
ProgDlg pd = checkProgDlg(L,1);
double pr = lua_tonumber(L,WSLUA_ARG_ProgDlg_update_PROGRESS);
const gchar* task = luaL_optstring(L,WSLUA_OPTARG_ProgDlg_update_TASK,"");
if (!ops->update_progress) {
WSLUA_ERROR(ProgDlg_update,"GUI not available");
return 0;
}
g_free(pd->task);
pd->task = g_strdup(task);
if (pr >= 0.0 && pr <= 1.0) {
ops->update_progress(pd->pw, (float) pr, task);
} else {
WSLUA_ERROR(ProgDlg_update,"Progress value out of range (must be between 0.0 and 1.0)");
return 0;
}
return 0;
}
WSLUA_METHOD ProgDlg_stopped(lua_State* L) {
ProgDlg pd = checkProgDlg(L,1);
lua_pushboolean(L,pd->stopped);
WSLUA_RETURN(1);
}
WSLUA_METHOD ProgDlg_close(lua_State* L) {
ProgDlg pd = checkProgDlg(L,1);
if (!ops->destroy_progress_window) {
WSLUA_ERROR(ProgDlg_close,"GUI not available");
return 0;
}
if (pd->pw) {
ops->destroy_progress_window(pd->pw);
pd->pw = NULL;
}
return 0;
}
static int ProgDlg__tostring(lua_State* L) {
ProgDlg pd = checkProgDlg(L,1);
lua_pushstring(L,ep_strdup_printf("%sstopped",pd->stopped?"":"not "));
return 0;
}
static int ProgDlg__gc(lua_State* L) {
ProgDlg pd = toProgDlg(L,1);
if (pd) {
if (pd->pw && ops->destroy_progress_window) {
ops->destroy_progress_window(pd->pw);
}
g_free(pd);
} else {
luaL_error(L, "ProgDlg__gc has being passed something else!");
}
return 0;
}
int ProgDlg_register(lua_State* L) {
ops = funnel_get_funnel_ops();
WSLUA_REGISTER_CLASS(ProgDlg);
return 0;
}
WSLUA_CONSTRUCTOR TextWindow_new(lua_State* L) {
#define WSLUA_OPTARG_TextWindow_new_TITLE 1
const gchar* title;
TextWindow tw = NULL;
struct _close_cb_data* default_cbd;
if (!ops->new_text_window || !ops->set_close_cb) {
WSLUA_ERROR(TextWindow_new,"GUI not available");
return 0;
}
title = luaL_optstring(L,WSLUA_OPTARG_TextWindow_new_TITLE,"Untitled Window");
tw = (struct _wslua_tw *)g_malloc(sizeof(struct _wslua_tw));
tw->expired = FALSE;
tw->ws_tw = ops->new_text_window(title);
default_cbd = (struct _close_cb_data *)g_malloc(sizeof(struct _close_cb_data));
default_cbd->L = NULL;
default_cbd->func_ref = 0;
default_cbd->wslua_tw = tw;
ops->set_close_cb(tw->ws_tw,text_win_close_cb,default_cbd);
pushTextWindow(L,tw);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_set_atclose(lua_State* L) {
#define WSLUA_ARG_TextWindow_at_close_ACTION 2
TextWindow tw = checkTextWindow(L,1);
struct _close_cb_data* cbd;
if (!ops->set_close_cb) {
WSLUA_ERROR(TextWindow_set_atclose,"GUI not available");
return 0;
}
lua_settop(L,2);
if (! lua_isfunction(L,2)) {
WSLUA_ARG_ERROR(TextWindow_at_close,ACTION,"Must be a function");
return 0;
}
cbd = (struct _close_cb_data *)g_malloc(sizeof(struct _close_cb_data));
cbd->L = L;
cbd->func_ref = luaL_ref(L, LUA_REGISTRYINDEX);
cbd->wslua_tw = tw;
ops->set_close_cb(tw->ws_tw,text_win_close_cb,cbd);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_set(lua_State* L) {
#define WSLUA_ARG_TextWindow_set_TEXT 2
TextWindow tw = checkTextWindow(L,1);
const gchar* text = luaL_checkstring(L,WSLUA_ARG_TextWindow_set_TEXT);
if (!ops->set_text) {
WSLUA_ERROR(TextWindow_set,"GUI not available");
return 0;
}
if (!text) {
WSLUA_ARG_ERROR(TextWindow_set,TEXT,"Must be a string");
return 0;
}
ops->set_text(tw->ws_tw,text);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_append(lua_State* L) {
#define WSLUA_ARG_TextWindow_append_TEXT 2
TextWindow tw = checkTextWindow(L,1);
const gchar* text = luaL_checkstring(L,WSLUA_ARG_TextWindow_append_TEXT);
if (!ops->append_text) {
WSLUA_ERROR(TextWindow_append,"GUI not available");
return 0;
}
if (!text) {
WSLUA_ARG_ERROR(TextWindow_append,TEXT,"Must be a string");
return 0;
}
ops->append_text(tw->ws_tw,text);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_prepend(lua_State* L) {
#define WSLUA_ARG_TextWindow_prepend_TEXT 2
TextWindow tw = checkTextWindow(L,1);
const gchar* text = luaL_checkstring(L,WSLUA_ARG_TextWindow_prepend_TEXT);
if (!ops->prepend_text) {
WSLUA_ERROR(TextWindow_prepend,"GUI not available");
return 0;
}
if (!text) {
WSLUA_ARG_ERROR(TextWindow_prepend,TEXT,"Must be a string");
return 0;
}
ops->prepend_text(tw->ws_tw,text);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_clear(lua_State* L) {
TextWindow tw = checkTextWindow(L,1);
if (!ops->clear_text) {
WSLUA_ERROR(TextWindow_clear,"GUI not available");
return 0;
}
ops->clear_text(tw->ws_tw);
WSLUA_RETURN(1);
}
WSLUA_METHOD TextWindow_get_text(lua_State* L) {
TextWindow tw = checkTextWindow(L,1);
const gchar* text;
if (!ops->get_text) {
WSLUA_ERROR(TextWindow_get_text,"GUI not available");
return 0;
}
text = ops->get_text(tw->ws_tw);
lua_pushstring(L,text);
WSLUA_RETURN(1);
}
static int TextWindow__gc(lua_State* L) {
TextWindow tw = toTextWindow(L,1);
if (!tw)
return 0;
if (!tw->expired) {
tw->expired = TRUE;
if (ops->destroy_text_window) {
ops->destroy_text_window(tw->ws_tw);
}
} else {
g_free(tw);
}
return 0;
}
WSLUA_METHOD TextWindow_set_editable(lua_State* L) {
#define WSLUA_OPTARG_TextWindow_set_editable_EDITABLE 2
TextWindow tw = checkTextWindow(L,1);
gboolean editable = wslua_optbool(L,WSLUA_OPTARG_TextWindow_set_editable_EDITABLE,TRUE);
if (!ops->set_editable) {
WSLUA_ERROR(TextWindow_set_editable,"GUI not available");
return 0;
}
ops->set_editable(tw->ws_tw,editable);
WSLUA_RETURN(1);
}
static gboolean wslua_button_callback(funnel_text_window_t* ws_tw, void* data) {
wslua_bt_cb_t* cbd = (wslua_bt_cb_t *)data;
lua_State* L = cbd->L;
(void) ws_tw;
lua_settop(L,0);
lua_pushcfunction(L,dlg_cb_error_handler);
lua_rawgeti(L, LUA_REGISTRYINDEX, cbd->func_ref);
lua_rawgeti(L, LUA_REGISTRYINDEX, cbd->wslua_tw_ref);
switch ( lua_pcall(L,1,0,1) ) {
case 0:
break;
case LUA_ERRRUN:
g_warning("Runtime error while calling button callback");
break;
case LUA_ERRMEM:
g_warning("Memory alloc error while calling button callback");
break;
default:
g_assert_not_reached();
break;
}
return TRUE;
}
WSLUA_METHOD TextWindow_add_button(lua_State* L) {
#define WSLUA_ARG_TextWindow_add_button_LABEL 2
#define WSLUA_ARG_TextWindow_add_button_FUNCTION 3
TextWindow tw = checkTextWindow(L,1);
const gchar* label = luaL_checkstring(L,WSLUA_ARG_TextWindow_add_button_LABEL);
funnel_bt_t* fbt;
wslua_bt_cb_t* cbd;
if (!ops->add_button) {
WSLUA_ERROR(TextWindow_add_button,"GUI not available");
return 0;
}
if (! lua_isfunction(L,WSLUA_ARG_TextWindow_add_button_FUNCTION) ) {
WSLUA_ARG_ERROR(TextWindow_add_button,FUNCTION,"must be a function");
return 0;
}
lua_settop(L,3);
if (ops->add_button) {
fbt = (funnel_bt_t *)g_malloc(sizeof(funnel_bt_t));
cbd = (wslua_bt_cb_t *)g_malloc(sizeof(wslua_bt_cb_t));
fbt->tw = tw->ws_tw;
fbt->func = wslua_button_callback;
fbt->data = cbd;
fbt->free_fcn = g_free;
fbt->free_data_fcn = g_free;
cbd->L = L;
cbd->func_ref = luaL_ref(L, LUA_REGISTRYINDEX);
cbd->wslua_tw_ref = luaL_ref(L, LUA_REGISTRYINDEX);
ops->add_button(tw->ws_tw,fbt,label);
}
WSLUA_RETURN(1);
}
int TextWindow_register(lua_State* L) {
ops = funnel_get_funnel_ops();
WSLUA_REGISTER_CLASS(TextWindow);
return 0;
}
WSLUA_FUNCTION wslua_retap_packets(lua_State* L) {
if ( ops->retap_packets ) {
ops->retap_packets();
} else {
WSLUA_ERROR(wslua_retap_packets, "GUI not available");
}
return 0;
}
WSLUA_FUNCTION wslua_copy_to_clipboard(lua_State* L) {
#define WSLUA_ARG_copy_to_clipboard_TEXT 1
const char* copied_str = luaL_checkstring(L,WSLUA_ARG_copy_to_clipboard_TEXT);
GString* gstr;
if (!ops->copy_to_clipboard) {
WSLUA_ERROR(copy_to_clipboard, "GUI not available");
return 0;
}
if (!copied_str) {
WSLUA_ARG_ERROR(copy_to_clipboard,TEXT,"Must be a string");
return 0;
}
gstr = g_string_new(copied_str);
ops->copy_to_clipboard(gstr);
g_string_free(gstr,TRUE);
return 0;
}
WSLUA_FUNCTION wslua_open_capture_file(lua_State* L) {
#define WSLUA_ARG_open_capture_file_FILENAME 1
#define WSLUA_ARG_open_capture_file_FILTER 2
const char* fname = luaL_checkstring(L,WSLUA_ARG_open_capture_file_FILENAME);
const char* filter = luaL_optstring(L,WSLUA_ARG_open_capture_file_FILTER,NULL);
const char* error = NULL;
if (!ops->open_file) {
WSLUA_ERROR(open_capture_file, "GUI not available");
return 0;
}
if (!fname) {
WSLUA_ARG_ERROR(open_capture_file,FILENAME,"Must be a string");
return 0;
}
if (! ops->open_file(fname,filter,&error) ) {
lua_pushboolean(L,FALSE);
if (error)
lua_pushstring(L,error);
else
lua_pushnil(L);
return 2;
} else {
lua_pushboolean(L,TRUE);
return 1;
}
}
WSLUA_FUNCTION wslua_get_filter(lua_State* L) {
const char *filter_str = NULL;
if (!ops->get_filter) {
WSLUA_ERROR(get_filter, "GUI not available");
return 0;
}
filter_str = ops->get_filter();
lua_pushstring(L,filter_str);
return 1;
}
WSLUA_FUNCTION wslua_set_filter(lua_State* L) {
#define WSLUA_ARG_set_filter_TEXT 1
const char* filter_str = luaL_checkstring(L,WSLUA_ARG_set_filter_TEXT);
if (!ops->set_filter) {
WSLUA_ERROR(set_filter, "GUI not available");
return 0;
}
if (!filter_str) {
WSLUA_ARG_ERROR(set_filter,TEXT,"Must be a string");
return 0;
}
ops->set_filter(filter_str);
return 0;
}
WSLUA_FUNCTION wslua_set_color_filter_slot(lua_State* L) {
#define WSLUA_ARG_set_color_filter_slot_ROW 1
#define WSLUA_ARG_set_color_filter_slot_TEXT 2
guint8 row = luaL_checkint(L,WSLUA_ARG_set_color_filter_slot_ROW);
const gchar* filter_str = luaL_checkstring(L,WSLUA_ARG_set_color_filter_slot_TEXT);
if (!ops->set_color_filter_slot) {
WSLUA_ERROR(set_color_filter_slot, "GUI not available");
return 0;
}
if (!filter_str) {
WSLUA_ARG_ERROR(set_color_filter_slot,TEXT,"Must be a string");
return 0;
}
ops->set_color_filter_slot(row, filter_str);
return 0;
}
WSLUA_FUNCTION wslua_apply_filter(lua_State* L) {
if (!ops->apply_filter) {
WSLUA_ERROR(apply_filter, "GUI not available");
return 0;
}
ops->apply_filter();
return 0;
}
WSLUA_FUNCTION wslua_reload(lua_State* L) {
if (!ops->reload) {
WSLUA_ERROR(reload, "GUI not available");
return 0;
}
ops->reload();
return 0;
}
WSLUA_FUNCTION wslua_browser_open_url(lua_State* L) {
#define WSLUA_ARG_browser_open_url_URL 1
const char* url = luaL_checkstring(L,WSLUA_ARG_browser_open_url_URL);
if (!ops->browser_open_url) {
WSLUA_ERROR(browser_open_url, "GUI not available");
return 0;
}
if (!url) {
WSLUA_ARG_ERROR(browser_open_url,URL,"Must be a string");
return 0;
}
ops->browser_open_url(url);
return 0;
}
WSLUA_FUNCTION wslua_browser_open_data_file(lua_State* L) {
#define WSLUA_ARG_browser_open_data_file_FILENAME 1
const char* file = luaL_checkstring(L,WSLUA_ARG_browser_open_data_file_FILENAME);
if (!ops->browser_open_data_file) {
WSLUA_ERROR(browser_open_data_file, "GUI not available");
return 0;
}
if (!file) {
WSLUA_ARG_ERROR(browser_open_data_file,FILENAME,"Must be a string");
return 0;
}
ops->browser_open_data_file(file);
return 0;
}
