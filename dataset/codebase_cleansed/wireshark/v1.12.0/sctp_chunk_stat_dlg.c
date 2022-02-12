static
GtkWidget* create_list(void)
{
GtkListStore *list_store;
GtkWidget *list;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeView *list_view;
GtkTreeSelection *selection;
list_store = gtk_list_store_new(N_COLUMN,
G_TYPE_STRING,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_INT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, IP_ADDR_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("IP Address", renderer,
"text", IP_ADDR_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, IP_ADDR_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 135);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("DATA", renderer,
"text", DATA_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, DATA_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("INIT", renderer,
"text", INIT_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, INIT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("INIT-ACK", renderer,
"text", INIT_ACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, INIT_ACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("SACK", renderer,
"text", SACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, SACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("HEARTBEAT", renderer,
"text", HEARTBEAT_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, HEARTBEAT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 110);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("HEARTBEAT-ACK", renderer,
"text", HEARTBEAT_ACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, HEARTBEAT_ACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 140);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ABORT", renderer,
"text", ABORT_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ABORT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("SHUTDOWN", renderer,
"text", SHUTDOWN_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, SHUTDOWN_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 120);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("SHUTDOWN-ACK", renderer,
"text", SHUTDOWN_ACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, SHUTDOWN_ACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 150);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ERROR", renderer,
"text", ERROR_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ERROR_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("COOKIE-ECHO", renderer,
"text", COOKIE_ECHO_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, COOKIE_ECHO_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 130);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("COOKIE-ACK", renderer,
"text", COOKIE_ACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, COOKIE_ACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 130);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ECNE", renderer,
"text", ECNE_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ECNE_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("CWR", renderer,
"text", CWR_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CWR_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("SHUT-COMPLETE", renderer,
"text", SHUT_COMPLETE_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, SHUT_COMPLETE_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 150);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("AUTH", renderer,
"text", AUTH_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, AUTH_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("NR-SACK", renderer,
"text", NR_SACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, NR_SACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ASCONF-ACK", renderer,
"text", ASCONF_ACK_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ASCONF_ACK_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 120);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("PKTDROP", renderer,
"text", PKTDROP_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, PKTDROP_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("FORWARD-TSN", renderer,
"text", FORWARD_TSN_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, FORWARD_TSN_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 140);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ASCONF", renderer,
"text", ASCONF_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ASCONF_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Others", renderer,
"text", OTHERS_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, OTHERS_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(list_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list_view), TRUE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
return list;
}
static const char *
chunk_name(int type)
{
#define CASE(x) case x: s = #x; break
const char *s = "unknown";
switch (type)
{
CASE(DATA);
CASE(INIT);
CASE(INIT_ACK);
CASE(SACK);
CASE(HEARTBEAT);
CASE(HEARTBEAT_ACK);
CASE(ABORT);
CASE(SHUTDOWN);
CASE(SHUTDOWN_ACK);
CASE(SCTP_ERROR);
CASE(COOKIE_ECHO);
CASE(COOKIE_ACK);
CASE(ECNE);
CASE(CWR);
CASE(SHUT_COMPLETE);
CASE(AUTH);
CASE(NR_SACK);
CASE(ASCONF_ACK);
CASE(PKTDROP);
CASE(FORWARD_TSN);
CASE(ASCONF);
}
return s;
}
static void
chunk_dlg_destroy(GObject *object _U_, gpointer user_data)
{
struct sctp_udata *u_data = (struct sctp_udata*)user_data;
decrease_childcount(u_data->parent);
remove_child(u_data, u_data->parent);
g_free(u_data->io);
g_free(u_data);
}
static void
on_destroy(GObject *object _U_, gpointer user_data)
{
struct sctp_udata *u_data = (struct sctp_udata*)user_data;
decrease_childcount(u_data->parent);
remove_child(u_data, u_data->parent);
g_free(u_data->io);
g_free(u_data);
}
static void
add_to_clist(sctp_addr_chunk* sac)
{
GtkListStore *list_store = NULL;
GtkTreeIter iter;
gchar field[1][MAX_ADDRESS_LEN];
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (clist)));
if (sac->addr->type == AT_IPv4) {
g_snprintf(field[0], MAX_ADDRESS_LEN, "%s", ip_to_str((const guint8 *)(sac->addr->data)));
} else if (sac->addr->type == AT_IPv6) {
g_snprintf(field[0], MAX_ADDRESS_LEN, "%s", ip6_to_str((const struct e_in6_addr *)(sac->addr->data)));
} else {
g_snprintf(field[0], MAX_ADDRESS_LEN, "%s", "NONE");
}
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
IP_ADDR_COLUMN, field[0],
DATA_COLUMN, sac->addr_count[SCTP_DATA_CHUNK_ID],
INIT_COLUMN, sac->addr_count[SCTP_INIT_CHUNK_ID],
INIT_ACK_COLUMN, sac->addr_count[SCTP_INIT_ACK_CHUNK_ID],
SACK_COLUMN, sac->addr_count[SCTP_SACK_CHUNK_ID],
HEARTBEAT_COLUMN, sac->addr_count[SCTP_HEARTBEAT_CHUNK_ID],
HEARTBEAT_ACK_COLUMN, sac->addr_count[SCTP_HEARTBEAT_ACK_CHUNK_ID],
ABORT_COLUMN, sac->addr_count[SCTP_ABORT_CHUNK_ID],
SHUTDOWN_COLUMN, sac->addr_count[SCTP_SHUTDOWN_CHUNK_ID],
SHUTDOWN_ACK_COLUMN, sac->addr_count[SCTP_SHUTDOWN_ACK_CHUNK_ID],
ERROR_COLUMN, sac->addr_count[SCTP_ERROR_CHUNK_ID],
COOKIE_ECHO_COLUMN, sac->addr_count[SCTP_COOKIE_ECHO_CHUNK_ID],
COOKIE_ACK_COLUMN, sac->addr_count[SCTP_COOKIE_ACK_CHUNK_ID],
ECNE_COLUMN, sac->addr_count[SCTP_ECNE_CHUNK_ID],
CWR_COLUMN, sac->addr_count[SCTP_CWR_CHUNK_ID],
SHUT_COMPLETE_COLUMN, sac->addr_count[SCTP_SHUTDOWN_COMPLETE_CHUNK_ID],
AUTH_COLUMN, sac->addr_count[SCTP_AUTH_CHUNK_ID],
NR_SACK_COLUMN, sac->addr_count[SCTP_NR_SACK_CHUNK_ID],
ASCONF_ACK_COLUMN, sac->addr_count[SCTP_ASCONF_ACK_CHUNK_ID],
PKTDROP_COLUMN, sac->addr_count[SCTP_PKTDROP_CHUNK_ID],
FORWARD_TSN_COLUMN, sac->addr_count[SCTP_FORWARD_TSN_CHUNK_ID],
ASCONF_COLUMN, sac->addr_count[SCTP_ASCONF_CHUNK_ID],
OTHERS_COLUMN, sac->addr_count[OTHER_CHUNKS_INDEX],
-1);
}
void sctp_chunk_stat_dlg_update(struct sctp_udata* udata, unsigned int direction)
{
GList *list = NULL;
sctp_addr_chunk *sac;
if (udata->io->window != NULL)
{
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(clist))));
if (udata->assoc->addr_chunk_count != NULL)
{
list = g_list_first(udata->assoc->addr_chunk_count);
while (list)
{
sac = (sctp_addr_chunk*)(list->data);
if (sac->direction == direction)
{
add_to_clist(sac);
list = g_list_next(list);
}
else
list = g_list_next(list);
}
}
}
last_list = list;
}
static void
sctp_chunk_stat_on_close (GtkButton *button _U_, gpointer user_data)
{
struct sctp_udata *udata;
udata = (struct sctp_udata *)user_data;
gtk_grab_remove(udata->io->window);
gtk_widget_destroy(udata->io->window);
}
static void
on_close_dlg (GtkButton *button _U_, gpointer user_data)
{
struct sctp_udata *udata;
udata = (struct sctp_udata *)user_data;
gtk_grab_remove(udata->io->window);
gtk_widget_destroy(udata->io->window);
}
static void
path_window_set_title(struct sctp_udata *u_data, unsigned int direction)
{
char *display_name;
char *title;
if (!u_data->io->window) {
return;
}
display_name = cf_get_display_name(&cfile);
title = g_strdup_printf("SCTP Path Chunk Statistics for Endpoint %u: %s Port1 %u Port2 %u",direction,
display_name, u_data->assoc->port1, u_data->assoc->port2);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(u_data->io->window), title);
g_free(title);
}
static void
gtk_sctpstat_dlg(struct sctp_udata *u_data, unsigned int direction)
{
GtkWidget *vbox1;
GtkWidget *scrolledwindow1;
GtkWidget *hbuttonbox2;
GtkWidget *bt_close;
sctp_graph_t *io = (sctp_graph_t *)g_malloc(sizeof(sctp_graph_t));
io->window = NULL;
u_data->io = io;
u_data->io->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_default_size(GTK_WINDOW(u_data->io->window), 850, 200);
gtk_window_set_position (GTK_WINDOW (u_data->io->window), GTK_WIN_POS_CENTER);
path_window_set_title(u_data, direction);
g_signal_connect(u_data->io->window, "destroy", G_CALLBACK(chunk_dlg_destroy), u_data);
vbox1 = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(vbox1), 8);
gtk_container_add(GTK_CONTAINER(u_data->io->window), vbox1);
gtk_widget_show(vbox1);
scrolledwindow1 = scrolled_window_new (NULL, NULL);
gtk_widget_show (scrolledwindow1);
gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);
clist = create_list();
gtk_widget_show (clist);
gtk_container_add (GTK_CONTAINER (scrolledwindow1), clist);
gtk_widget_show(u_data->io->window);
hbuttonbox2 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(vbox1), hbuttonbox2, FALSE, FALSE, 0);
gtk_container_set_border_width(GTK_CONTAINER(hbuttonbox2), 10);
gtk_button_box_set_layout(GTK_BUTTON_BOX (hbuttonbox2), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing(GTK_BOX (hbuttonbox2), 0);
gtk_widget_show(hbuttonbox2);
bt_close = ws_gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add (GTK_CONTAINER (hbuttonbox2), bt_close);
gtk_widget_show (bt_close);
g_signal_connect(bt_close, "clicked", G_CALLBACK(sctp_chunk_stat_on_close), u_data);
cf_retap_packets(&cfile);
}
static void
chunk_window_set_title(struct sctp_udata *u_data)
{
char *display_name;
char *title;
if (!u_data->io->window) {
return;
}
display_name = cf_get_display_name(&cfile);
title = g_strdup_printf("SCTP Association Chunk Statistics: %s Port1 %u Port2 %u",
display_name, u_data->assoc->port1, u_data->assoc->port2);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(u_data->io->window), title);
g_free(title);
}
static void
sctp_chunk_dlg(struct sctp_udata *u_data)
{
GtkWidget *main_vb, *grid;
GtkWidget *label, *h_button_box;
GtkWidget *close_bt;
gchar label_txt[50];
int i, row;
sctp_graph_t *io = (sctp_graph_t *)g_malloc(sizeof(sctp_graph_t));
io->window = NULL;
u_data->io = io;
u_data->io->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_position (GTK_WINDOW (u_data->io->window), GTK_WIN_POS_CENTER);
gtk_widget_set_size_request(u_data->io->window, 500, 650);
g_signal_connect(u_data->io->window, "destroy", G_CALLBACK(on_destroy), u_data);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
gtk_container_add(GTK_CONTAINER(u_data->io->window), main_vb);
grid = ws_gtk_grid_new();
ws_gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
ws_gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
gtk_box_pack_start(GTK_BOX(main_vb), grid, TRUE, TRUE, 0);
row = 0;
label = gtk_label_new("ChunkType");
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, row, 1, 1);
label = gtk_label_new("Association");
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 1, row, 1, 1);
label = gtk_label_new("Endpoint 1");
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 2, row, 1, 1);
label = gtk_label_new("Endpoint 2");
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 3, row, 1, 1);
row ++;
label = gtk_label_new("");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, row, 1, 1);
label = gtk_label_new("");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 1, row, 1, 1);
label = gtk_label_new("");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 2, row, 1, 1);
label = gtk_label_new("");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 3, row, 1, 1);
row ++;
for (i=0; i<NUM_CHUNKS; i++)
{
if (IS_SCTP_CHUNK_TYPE(i))
{
label = gtk_label_new(chunk_name(i));
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->chunk_count[i]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 1, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->ep1_chunk_count[i]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 2, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->ep2_chunk_count[i]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 3, row, 1, 1);
row ++;
}
}
label = gtk_label_new("Others");
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->chunk_count[OTHER_CHUNKS_INDEX]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 1, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->ep1_chunk_count[OTHER_CHUNKS_INDEX]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 2, row, 1, 1);
g_snprintf(label_txt, 10, "%u", selected_stream->ep2_chunk_count[OTHER_CHUNKS_INDEX]);
label = gtk_label_new(label_txt);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 3, row, 1, 1);
h_button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(main_vb), h_button_box, FALSE, FALSE, 0);
gtk_container_set_border_width(GTK_CONTAINER(h_button_box), 10);
gtk_button_box_set_layout(GTK_BUTTON_BOX (h_button_box), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing(GTK_BOX (h_button_box), 0);
gtk_widget_show(h_button_box);
close_bt = ws_gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_box_pack_start(GTK_BOX(h_button_box), close_bt, FALSE, FALSE, 0);
gtk_widget_show(close_bt);
g_signal_connect(close_bt, "clicked", G_CALLBACK(on_close_dlg), u_data);
gtk_widget_show_all(u_data->io->window);
chunk_window_set_title(u_data);
}
void
sctp_chunk_dlg_show(struct sctp_analyse* userdata)
{
gint i;
struct sctp_udata *u_data;
u_data = (struct sctp_udata *)g_malloc(sizeof(struct sctp_udata));
u_data->assoc = (sctp_assoc_info_t *)g_malloc(sizeof(sctp_assoc_info_t));
u_data->assoc = userdata->assoc;
u_data->io = NULL;
u_data->parent = userdata;
if (selected_stream == NULL)
selected_stream = (sctp_assoc_info_t *)g_malloc(sizeof(sctp_assoc_info_t));
selected_stream = u_data->assoc;
for (i=0; i<NUM_CHUNKS; i++)
{
if (IS_SCTP_CHUNK_TYPE(i) || (i == OTHER_CHUNKS_INDEX))
selected_stream->chunk_count[i] = u_data->assoc->chunk_count[i];
}
set_child(u_data, u_data->parent);
increase_childcount(u_data->parent);
sctp_chunk_dlg(u_data);
}
void
sctp_chunk_stat_dlg_show(unsigned int direction, struct sctp_analyse* userdata)
{
struct sctp_udata *u_data;
u_data = (struct sctp_udata *)g_malloc(sizeof(struct sctp_udata));
u_data->assoc = (sctp_assoc_info_t *)g_malloc(sizeof(sctp_assoc_info_t));
u_data->assoc = userdata->assoc;
u_data->io = NULL;
u_data->parent = userdata;
if (selected_stream == NULL)
selected_stream = (sctp_assoc_info_t *)g_malloc(sizeof(sctp_assoc_info_t));
selected_stream = u_data->assoc;
selected_stream->addr_chunk_count = u_data->assoc->addr_chunk_count;
set_child(u_data, u_data->parent);
increase_childcount(u_data->parent);
gtk_sctpstat_dlg(u_data, direction);
sctp_chunk_stat_dlg_update(u_data,direction);
}
