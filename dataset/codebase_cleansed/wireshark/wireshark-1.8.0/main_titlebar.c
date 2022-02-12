void
main_set_window_name(const gchar *window_name)
{
gchar *old_window_name;
old_window_name = g_object_get_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY);
g_free(old_window_name);
g_object_set_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY, g_strdup(window_name));
main_titlebar_update();
}
void
main_titlebar_update(void)
{
gchar *window_name;
gchar *title;
window_name = g_object_get_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY);
if (window_name != NULL) {
title = create_user_window_title(window_name);
if (prefs.gui_version_in_start_page) {
gchar *old_title = title;
title = g_strdup_printf("%s [Wireshark %s %s]", title, VERSION, wireshark_svnversion);
g_free(old_title);
}
gtk_window_set_title(GTK_WINDOW(top_level), title);
g_free(title);
}
}
