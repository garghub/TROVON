static void
main_set_window_name(const gchar *window_name)
{
gchar *old_window_name;
old_window_name = (gchar *)g_object_get_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY);
g_free(old_window_name);
g_object_set_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY, g_strdup(window_name));
main_titlebar_update();
}
void
main_titlebar_update(void)
{
gchar *window_name;
gchar *title;
window_name = (gchar *)g_object_get_data(G_OBJECT(top_level), MAIN_WINDOW_NAME_KEY);
if (window_name != NULL) {
title = create_user_window_title(window_name);
if ((prefs.gui_version_placement == version_title_only) ||
(prefs.gui_version_placement == version_both)) {
gchar *old_title = title;
title = g_strdup_printf("%s [Wireshark %s]", title, get_ws_vcs_version_info());
g_free(old_title);
}
gtk_window_set_title(GTK_WINDOW(top_level), title);
g_free(title);
}
}
void
set_titlebar_for_capture_file(capture_file *cf)
{
gchar *display_name;
gchar *window_name;
if (cf && cf->filename) {
display_name = cf_get_display_name(cf);
window_name = g_strdup_printf("%s%s", cf_has_unsaved_data(cf) ? "*" : "",
display_name);
g_free(display_name);
main_set_window_name(window_name);
g_free(window_name);
} else {
main_set_window_name("The Wireshark Network Analyzer");
}
}
void
set_titlebar_for_capture_in_progress(capture_file *cf)
{
gchar *window_name;
window_name = g_strdup_printf("Capturing from %s ", cf_get_tempfile_source(cf));
main_set_window_name(window_name);
g_free(window_name);
}
