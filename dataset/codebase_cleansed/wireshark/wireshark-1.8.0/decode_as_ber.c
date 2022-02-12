static void
decode_ber(GtkWidget *notebook_pg)
{
GtkWidget *list;
gchar *syntax;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
syntax = NULL;
list = g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_LIST);
if (requested_action == E_DECODE_NO)
gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)));
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
if (gtk_tree_selection_get_selected(selection, &model, &iter) == FALSE)
{
syntax = NULL;
} else {
gtk_tree_model_get(model, &iter, E_LIST_S_PROTO_NAME, &syntax, -1);
}
if ((syntax != NULL && strcmp(syntax, "(default)") == 0) ) {
ber_decode_as(NULL);
} else {
ber_decode_as(syntax);
}
g_free(syntax);
}
static void
decode_ber_add_to_list(gpointer key, gpointer value, gpointer user_data)
{
decode_add_to_list("ASN.1", key, value, user_data);
}
static GtkWidget *
decode_add_ber_menu (GtkWidget *page, const gchar *table_name _U_)
{
GtkWidget *scrolled_window;
GtkWidget *list;
decode_list_menu_start(page, &list, &scrolled_window);
ber_decode_as_foreach(decode_ber_add_to_list, list);
decode_list_menu_finish(list);
return(scrolled_window);
}
GtkWidget *
decode_ber_add_page (packet_info *pinfo _U_)
{
GtkWidget *page_hb, *info_vb, *label, *scrolled_window;
page_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page_hb), E_PAGE_ACTION, decode_ber);
g_object_set_data(G_OBJECT(page_hb), E_PAGE_TABLE, "ASN.1");
g_object_set_data(G_OBJECT(page_hb), E_PAGE_TITLE, "ASN.1");
info_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_box_pack_start(GTK_BOX(page_hb), info_vb, TRUE, TRUE, 0);
label = gtk_label_new("Decode ASN.1 file as:");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
scrolled_window = decode_add_ber_menu(page_hb, "ber" );
gtk_box_pack_start(GTK_BOX(page_hb), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
return(page_hb);
}
