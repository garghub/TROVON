static void
plugins_scan(GtkWidget *list)
{
#ifdef HAVE_PLUGINS
plugin *pt_plug;
const char *sep;
#endif
#ifdef HAVE_LUA_5_1
wslua_plugin *lua_plug;
#endif
GString *type;
#ifdef HAVE_PLUGINS
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
type = g_string_new("");
sep = "";
if (pt_plug->register_protoinfo)
{
type = g_string_append(type, "dissector");
sep = ", ";
}
if (pt_plug->register_tap_listener)
{
type = g_string_append(type, sep);
type = g_string_append(type, "tap");
sep = ", ";
}
if (pt_plug->register_wtap_module)
{
type = g_string_append(type, sep);
type = g_string_append(type, "file format");
sep = ", ";
}
if (pt_plug->register_codec_module)
{
type = g_string_append(type, sep);
type = g_string_append(type, "codec");
}
simple_list_append(list, 0, pt_plug->name, 1, pt_plug->version,
2, type->str, 3, g_module_name(pt_plug->handle), -1);
g_string_free(type, TRUE);
}
#endif
#ifdef HAVE_LUA_5_1
for (lua_plug = wslua_plugin_list; lua_plug != NULL; lua_plug = lua_plug->next)
{
type = g_string_new("");
type = g_string_append(type, "lua script");
simple_list_append(list, 0, lua_plug->name, 1, lua_plug->version, 2, type->str, 3, lua_plug->filename, -1);
g_string_free(type, TRUE);
}
#endif
}
GtkWidget *
about_plugins_page_new(void)
{
GtkWidget *scrolledwindow;
GtkWidget *plugins_list;
const gchar *titles[] = {"Name", "Version", "Type", "Path"};
scrolledwindow = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow),
GTK_SHADOW_IN);
plugins_list = simple_list_new(4, titles);
plugins_scan(plugins_list);
gtk_container_add(GTK_CONTAINER(scrolledwindow), plugins_list);
return scrolledwindow;
}
