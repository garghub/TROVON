extern GList * ext_menubar_get_entries(void)
{
return menubar_entries;
}
extern ext_menu_t * ext_menubar_register_menu(int proto_id, const gchar * menulabel,
gboolean is_plugin)
{
ext_menubar_t * entry = NULL;
gchar * name = NULL;
g_assert(menulabel != NULL && strlen ( menulabel ) > 0 );
g_assert(find_protocol_by_id(proto_id) != NULL);
name = g_strconcat(proto_get_protocol_filter_name(proto_id), "Menu", NULL);
g_assert(g_list_find(menubar_menunames, name) == NULL);
entry = (ext_menubar_t *)g_malloc0(sizeof(ext_menubar_t));
entry->type = EXT_MENUBAR_MENU;
entry->proto = proto_id;
entry->is_plugin = is_plugin;
entry->parent_menu = 0;
entry->name = name;
entry->label = g_strdup(menulabel);
entry->tooltip = g_strdup(menulabel);
entry->submenu_cnt = 0;
entry->item_cnt = 0;
menubar_entries = g_list_append(menubar_entries, entry);
menubar_menunames = g_list_append(menubar_menunames, name);
return entry;
}
extern ext_menu_t * ext_menubar_set_parentmenu(ext_menu_t * menu, const gchar * parentmenu)
{
g_assert(menu != NULL && menu->parent == NULL);
g_assert(parentmenu != 0);
menu->parent_menu = g_strdup(parentmenu);
return menu;
}
extern ext_menu_t * ext_menubar_add_submenu(ext_menu_t * parent, const gchar *menulabel)
{
ext_menubar_t * entry = NULL;
g_assert(menulabel != NULL && strlen ( menulabel ) > 0 );
g_assert(parent != NULL && parent->type == EXT_MENUBAR_MENU);
parent->submenu_cnt++;
entry = (ext_menubar_t *)g_malloc0(sizeof(ext_menubar_t));
entry->type = EXT_MENUBAR_MENU;
entry->parent = parent;
entry->proto = parent->proto;
entry->is_plugin = parent->is_plugin;
entry->name = g_strdup_printf("%sS%02d", parent->name, parent->submenu_cnt);
entry->label = g_strdup(menulabel);
entry->tooltip = g_strdup(menulabel);
parent->children = g_list_append(parent->children, entry);
return entry;
}
static void ext_menubar_add_generic_entry (
ext_menubar_entry_t type, ext_menu_t * parent, const gchar * label,
const gchar * tooltip, ext_menubar_action_cb callback, gpointer user_data )
{
ext_menubar_t * entry = NULL;
g_assert(parent != NULL && parent->type == EXT_MENUBAR_MENU);
g_assert(label != NULL && strlen ( label ) > 0 );
parent->item_cnt++;
entry = (ext_menubar_t*)g_malloc0(sizeof(ext_menubar_t));
entry->type = type;
entry->name = g_strdup_printf("%sI%02d", parent->name, parent->item_cnt);
entry->label = g_strdup(label);
if ( tooltip != NULL && strlen(tooltip) > 0 )
entry->tooltip = g_strdup(tooltip);
entry->callback = callback;
entry->user_data = user_data;
parent->children = g_list_append(parent->children, entry);
}
extern void ext_menubar_add_entry(ext_menu_t * parent, const gchar *label,
const gchar *tooltip, ext_menubar_action_cb callback, gpointer user_data)
{
g_assert(callback != NULL);
ext_menubar_add_generic_entry ( EXT_MENUBAR_ITEM, parent, label, tooltip, callback, user_data );
}
extern void ext_menubar_add_website(ext_menu_t * parent, const gchar *label,
const gchar *tooltip, const gchar *url)
{
g_assert(url != NULL && strlen ( url ) > 0 );
ext_menubar_add_generic_entry ( EXT_MENUBAR_URL, parent, label, tooltip, NULL, (gpointer) g_strdup(url) );
}
extern void ext_menubar_add_separator(ext_menu_t *parent)
{
ext_menubar_add_generic_entry ( EXT_MENUBAR_SEPARATOR, parent, g_strdup("-"), NULL, NULL, NULL );
}
static void
plugin_if_init_hashtable(void)
{
if ( plugin_if_callback_functions == 0 )
plugin_if_callback_functions = g_hash_table_new(g_int_hash, g_int_equal);
}
static void plugin_if_call_gui_cb(plugin_if_callback_t actionType, GHashTable * dataSet)
{
plugin_if_gui_cb action;
gint * key = 0;
key = (gint *)g_malloc0(sizeof(gint));
*key = (gint) actionType;
plugin_if_init_hashtable();
if ( g_hash_table_size(plugin_if_callback_functions) != 0 )
{
if ( g_hash_table_lookup_extended(plugin_if_callback_functions, key, NULL, (gpointer*)&action) )
{
if ( action != NULL )
action(dataSet);
}
}
}
extern void plugin_if_apply_filter(const char * filter_string, gboolean force)
{
plugin_if_callback_t actionType;
GHashTable * dataSet = NULL;
actionType = ( force == TRUE ) ? PLUGIN_IF_FILTER_ACTION_APPLY : PLUGIN_IF_FILTER_ACTION_PREPARE;
dataSet = g_hash_table_new(g_str_hash, g_str_equal);
g_hash_table_insert( dataSet, g_strdup("action_type"), (gpointer) &actionType );
g_hash_table_insert( dataSet, g_strdup("filter_string"), g_strdup(filter_string) );
g_hash_table_insert( dataSet, g_strdup("force"), (gpointer) &force );
plugin_if_call_gui_cb(actionType, dataSet);
}
extern void plugin_if_goto_frame(guint32 framenr)
{
GHashTable * dataSet = NULL;
dataSet = g_hash_table_new(g_str_hash, g_str_equal);
g_hash_table_insert( dataSet, g_strdup("frame_nr"), GUINT_TO_POINTER(framenr) );
plugin_if_call_gui_cb(PLUGIN_IF_GOTO_FRAME, dataSet);
}
extern void plugin_if_save_preference(const char * pref_module, const char * pref_key, const char * pref_value)
{
GHashTable * dataSet = NULL;
dataSet = g_hash_table_new(g_str_hash, g_str_equal);
g_hash_table_insert( dataSet, g_strdup("pref_module"), g_strdup(pref_module) );
g_hash_table_insert( dataSet, g_strdup("pref_key"), g_strdup(pref_key) );
g_hash_table_insert( dataSet, g_strdup("pref_value"), g_strdup(pref_value) );
plugin_if_call_gui_cb(PLUGIN_IF_PREFERENCE_SAVE, dataSet);
}
extern void plugin_if_register_gui_cb(plugin_if_callback_t actionType, plugin_if_gui_cb callback)
{
gint * key = 0;
key = (gint *)g_malloc0(sizeof(gint));
*key = actionType;
plugin_if_init_hashtable();
if ( ! g_hash_table_lookup_extended(plugin_if_callback_functions, key, NULL, NULL ) )
g_hash_table_insert(plugin_if_callback_functions, key, callback);
}
