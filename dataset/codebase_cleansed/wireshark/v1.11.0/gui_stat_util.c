void
init_main_stat_window(GtkWidget *window, GtkWidget *mainbox, const char *title, const char *filter)
{
GtkWidget *main_label;
GtkWidget *filter_label;
char *filter_string;
gtk_window_set_title(GTK_WINDOW(window), title);
gtk_container_add(GTK_CONTAINER(window), mainbox);
gtk_container_set_border_width(GTK_CONTAINER(mainbox), 10);
gtk_widget_show(mainbox);
main_label = gtk_label_new(title);
gtk_box_pack_start(GTK_BOX(mainbox), main_label, FALSE, FALSE, 0);
gtk_widget_show(main_label);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
filter_label = gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(filter_label), TRUE);
gtk_box_pack_start(GTK_BOX(mainbox), filter_label, FALSE, FALSE, 0);
gtk_widget_show(filter_label);
}
GtkTreeView *
create_stat_table(GtkWidget *scrolled_window, GtkWidget *vbox, int columns, const stat_column *headers)
{
GtkTreeView *table;
GtkListStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
GtkCellRenderer *renderer;
GType *types;
int i;
if (columns <= 0)
return NULL;
types = (GType *)g_malloc(columns *sizeof(GType));
for (i = 0; i < columns; i++)
types[i] = headers[i].type;
store = gtk_list_store_newv (columns, types);
g_free(types);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
table = GTK_TREE_VIEW(tree);
g_object_unref (G_OBJECT (store));
for (i = 0; i < columns; i++) {
renderer = gtk_cell_renderer_text_new ();
if (headers[i].align == RIGHT) {
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
}
g_object_set(renderer, "ypad", 0, NULL);
column = gtk_tree_view_column_new_with_attributes (headers[i].title, renderer, "text",
i, NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_append_column (table, column);
}
gtk_container_add(GTK_CONTAINER(scrolled_window), GTK_WIDGET (table));
gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);
gtk_tree_view_set_rules_hint(table, FALSE);
gtk_tree_view_set_headers_clickable(table, FALSE);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
gtk_widget_show(scrolled_window);
return table;
}
