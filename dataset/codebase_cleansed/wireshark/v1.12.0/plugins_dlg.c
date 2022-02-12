static gboolean
about_plugins_callback(GtkWidget *widget, GdkEventButton *event, gint id _U_)
{
GtkTreeSelection *tree_selection;
GtkTreeModel *model;
GtkTreeIter iter;
gchar *type;
gchar *file;
tree_selection = gtk_tree_view_get_selection (GTK_TREE_VIEW(widget));
if (gtk_tree_selection_count_selected_rows (tree_selection) == 0)
return FALSE;
if (event->type != GDK_2BUTTON_PRESS)
return FALSE;
if (gtk_tree_selection_get_selected (tree_selection, &model, &iter)) {
gtk_tree_model_get (model, &iter, 2, &type, -1);
if (strcmp (type, "lua script") == 0) {
gtk_tree_model_get (model, &iter, 3, &file, -1);
browser_open_data_file (file);
g_free (file);
}
g_free (type);
}
return TRUE;
}
static void
plugins_add_description(const char *name, const char *version,
const char *types, const char *filename,
void *user_data)
{
GtkWidget *list = (GtkWidget *)user_data;
simple_list_append(list, 0, name, 1, version,
2, types, 3, filename, -1);
}
static void
plugins_scan(GtkWidget *list)
{
#ifdef HAVE_PLUGINS
plugins_get_descriptions(plugins_add_description, list);
#endif
#ifdef HAVE_LUA
wslua_plugins_get_descriptions(plugins_add_description, list);
#endif
}
GtkWidget *
about_plugins_page_new(void)
{
GtkWidget *scrolledwindow;
GtkWidget *plugins_list;
static const gchar *titles[] = {"Name", "Version", "Type", "Path"};
scrolledwindow = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow),
GTK_SHADOW_IN);
plugins_list = simple_list_new(4, titles);
plugins_scan(plugins_list);
g_signal_connect(plugins_list, "button_press_event",
G_CALLBACK(about_plugins_callback), NULL);
gtk_container_add(GTK_CONTAINER(scrolledwindow), plugins_list);
return scrolledwindow;
}
