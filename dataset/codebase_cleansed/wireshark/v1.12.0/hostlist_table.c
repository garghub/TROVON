static char *
hostlist_port_to_str(int port_type_val, guint32 port)
{
static int i=0;
static gchar *strp, str[4][12];
gchar *bp;
switch(port_type_val){
case PT_TCP:
case PT_UDP:
case PT_SCTP:
i = (i+1)%4;
strp=str[i];
bp = &strp[11];
*bp = 0;
do {
*--bp = (port % 10) +'0';
} while ((port /= 10) != 0 && bp > strp);
return bp;
}
return NULL;
}
static const char *
hostlist_get_filter_name(address *addr, int specific_addr_type_val, int port_type_val, int name_type_val)
{
switch(name_type_val){
case FN_ANY_ADDRESS:
switch(addr->type){
case AT_ETHER:
switch(specific_addr_type_val){
case SAT_ETHER:
return "eth.addr";
case SAT_WLAN:
return "wlan.addr";
case SAT_FDDI:
return "fddi.addr";
case SAT_TOKENRING:
return "tr.addr";
default:
break;
}
break;
case AT_IPv4:
return "ip.addr";
case AT_IPv6:
return "ipv6.addr";
case AT_IPX:
return "ipx.addr";
case AT_FC:
return "fc.id";
case AT_URI:
switch(specific_addr_type_val){
case SAT_JXTA:
return "jxta.message.address";
default:
break;
}
break;
case AT_USB:
return "usb.addr";
default:
break;
}
break;
case FN_ANY_PORT:
switch(port_type_val){
case PT_TCP:
return "tcp.port";
case PT_UDP:
return "udp.port";
case PT_SCTP:
return "sctp.port";
}
break;
}
g_assert_not_reached();
return NULL;
}
static void
reset_hostlist_table_data(hostlist_table *hosts)
{
guint32 i;
char *display_name;
char title[256];
GString *error_string;
const char *filter;
GtkListStore *store;
if (hosts->use_dfilter) {
filter = gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
} else {
filter = hosts->filter;
}
error_string = set_tap_dfilter (hosts, filter);
if (error_string) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
return;
}
if(hosts->page_lb) {
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Endpoints: %s", display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(hosts->win), title);
g_snprintf(title, sizeof(title), "%s", hosts->name);
gtk_label_set_text(GTK_LABEL(hosts->page_lb), title);
gtk_widget_set_sensitive(hosts->page_lb, FALSE);
if (hosts->use_dfilter) {
if (filter && strlen(filter)) {
g_snprintf(title, sizeof(title), "%s Endpoints - Filter: %s", hosts->name, filter);
} else {
g_snprintf(title, sizeof(title), "%s Endpoints - No Filter", hosts->name);
}
} else {
g_snprintf(title, sizeof(title), "%s Endpoints", hosts->name);
}
gtk_label_set_text(GTK_LABEL(hosts->name_lb), title);
} else {
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "%s Endpoints: %s", hosts->name, display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(hosts->win), title);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(hosts->table)));
gtk_list_store_clear(store);
for(i=0;i<hosts->num_hosts;i++){
hostlist_talker_t *host = &g_array_index(hosts->hosts, hostlist_talker_t, i);
g_free((gpointer)host->myaddress.data);
}
if (hosts->hosts)
g_array_free(hosts->hosts, TRUE);
if (hosts->hashtable != NULL)
g_hash_table_destroy(hosts->hashtable);
hosts->hosts=NULL;
hosts->hashtable=NULL;
hosts->num_hosts=0;
}
static void
reset_hostlist_table_data_cb(void *arg)
{
reset_hostlist_table_data((hostlist_table *)arg);
}
static void
hostlist_win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
hostlist_table *hosts=(hostlist_table *)data;
remove_tap_listener(hosts);
reset_hostlist_table_data(hosts);
g_free(hosts);
}
static gint
hostlist_sort_column(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
guint32 idx1, idx2;
gint data_column = GPOINTER_TO_INT(user_data);
hostlist_table *hl = (hostlist_table *)g_object_get_data(G_OBJECT(model), HOST_PTR_KEY);
hostlist_talker_t *host1 = NULL;
hostlist_talker_t *host2 = NULL;
gtk_tree_model_get(model, a, INDEX_COLUMN, &idx1, -1);
gtk_tree_model_get(model, b, INDEX_COLUMN, &idx2, -1);
if (!hl || idx1 >= hl->num_hosts || idx2 >= hl->num_hosts)
return 0;
host1 = &g_array_index(hl->hosts, hostlist_talker_t, idx1);
host2 = &g_array_index(hl->hosts, hostlist_talker_t, idx2);
switch(data_column){
case 0:
return(CMP_ADDRESS(&host1->myaddress, &host2->myaddress));
case 1:
CMP_INT(host1->port, host2->port);
#ifdef HAVE_GEOIP
default:
{
gchar *text1, *text2;
double loc1 = 0, loc2 = 0;
gtk_tree_model_get(model, a, data_column, &text1, -1);
gtk_tree_model_get(model, b, data_column, &text2, -1);
if (text1) {
loc1 = atof(text1);
g_free(text1);
}
if (text2) {
loc2 = atof(text2);
g_free(text2);
}
CMP_INT(loc1, loc2);
}
break;
#endif
}
g_assert_not_reached();
return 0;
}
static void
hostlist_select_filter_cb(GtkWidget *widget _U_, gpointer callback_data, guint callback_action)
{
guint idx;
hostlist_table *hl=(hostlist_table *)callback_data;
char *str = NULL;
char *sport;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
hostlist_talker_t *host = NULL;
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(hl->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get (model, &iter,
INDEX_COLUMN, &idx,
-1);
if(idx>= hl->num_hosts){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No hostlist selected");
return;
}
host = &g_array_index(hl->hosts, hostlist_talker_t, idx);
sport=hostlist_port_to_str(host->port_type, host->port);
str = g_strdup_printf("%s==%s%s%s%s%s",
hostlist_get_filter_name(&host->myaddress, host->sat, host->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&host->myaddress),
sport?" && ":"",
sport?hostlist_get_filter_name(&host->myaddress, host->sat, host->port_type, FN_ANY_PORT):"",
sport?"==":"",
sport?sport:"");
apply_selected_filter (callback_action, str);
g_free (str);
}
static gboolean
hostlist_show_popup_menu_cb(void *widg _U_, GdkEvent *event, hostlist_table *et)
{
GdkEventButton *bevent = (GdkEventButton *)event;
if(event->type==GDK_BUTTON_PRESS && bevent->button==3){
gtk_menu_popup(GTK_MENU(et->menu), NULL, NULL, NULL, NULL,
bevent->button, bevent->time);
}
return FALSE;
}
static void
apply_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_SELECTED, 0));
}
static void
apply_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, 0));
}
static void
apply_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, 0));
}
static void
apply_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, 0));
}
static void
apply_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
apply_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
prep_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, 0));
}
static void
prep_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, 0));
}
static void
prep_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, 0));
}
static void
prep_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, 0));
}
static void
prep_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
prep_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
find_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, 0));
}
static void
find_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_NOT_SELECTED, 0));
}
static void
find_prev_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_SELECTED, 0));
}
static void
find_prev_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_NOT_SELECTED, 0));
}
static void
find_next_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_SELECTED, 0));
}
static void
find_next_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, 0));
}
static void
color_selected_cb(GtkWidget *widget, gpointer user_data)
{
hostlist_select_filter_cb( widget , user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, 0));
}
static void
hostlist_create_popup_menu(hostlist_table *hl)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
action_group = gtk_action_group_new ("HostlistTablePopupActionGroup");
gtk_action_group_add_actions (action_group,
service_resp_t_popup_entries,
G_N_ELEMENTS(service_resp_t_popup_entries),
hl);
ui_manager = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager,
action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager,ui_desc_hostlist_table_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building hostlist table filter popup failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
hl->menu = gtk_ui_manager_get_widget(ui_manager, "/HostlistTableFilterPopup");
g_signal_connect(hl->table, "button_press_event", G_CALLBACK(hostlist_show_popup_menu_cb), hl);
}
static void
get_hostlist_table_address(hostlist_table *hl, hostlist_talker_t *host, const char **entries)
{
char *port;
guint32 pt;
if (!hl->resolve_names)
entries[0] = ep_address_to_str(&host->myaddress);
else
entries[0] = (char *)ep_address_to_display(&host->myaddress);
pt = host->port_type;
if(!hl->resolve_names) pt = PT_NONE;
switch(pt) {
case(PT_TCP):
entries[1] = ep_tcp_port_to_display(host->port);
break;
case(PT_UDP):
entries[1] = ep_udp_port_to_display(host->port);
break;
case(PT_SCTP):
entries[1] = ep_sctp_port_to_display(host->port);
break;
default:
port=hostlist_port_to_str(host->port_type, host->port);
entries[1] = port?port:"";
}
}
static void
draw_hostlist_table_addresses(hostlist_table *hl)
{
guint32 i;
const char *entries[2];
GtkListStore *store;
store = GTK_LIST_STORE(gtk_tree_view_get_model(hl->table));
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(hl->table), NULL);
for(i=0;i<hl->num_hosts;i++){
hostlist_talker_t *host = &g_array_index(hl->hosts, hostlist_talker_t, i);
get_hostlist_table_address(hl, host, entries);
gtk_list_store_set (store, &host->iter,
ADR_COLUMN, entries[0],
PORT_COLUMN, entries[1],
-1);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(hl->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
static void
draw_hostlist_table_data(hostlist_table *hl)
{
guint32 i;
char title[256];
GtkListStore *store;
gboolean first = TRUE;
if (hl->page_lb) {
if(hl->num_hosts) {
g_snprintf(title, sizeof(title), "%s: %u", hl->name, hl->num_hosts);
} else {
g_snprintf(title, sizeof(title), "%s", hl->name);
}
gtk_label_set_text(GTK_LABEL(hl->page_lb), title);
gtk_widget_set_sensitive(hl->page_lb, hl->num_hosts);
} else {
if(hl->num_hosts) {
g_snprintf(title, sizeof(title), "%s Endpoints: %u", hl->name, hl->num_hosts);
} else {
g_snprintf(title, sizeof(title), "%s Endpoints", hl->name);
}
gtk_label_set_text(GTK_LABEL(hl->name_lb), title);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(hl->table));
for(i=0;i<hl->num_hosts;i++){
hostlist_talker_t *host = &g_array_index(hl->hosts, hostlist_talker_t, i);
if (!host->modified)
continue;
if (first) {
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(hl->table), NULL);
first = FALSE;
}
host->modified = FALSE;
if (!host->iter_valid) {
const char *entries[2];
#ifdef HAVE_GEOIP
char *geoip[NUM_GEOIP_COLS];
guint j;
if ((host->myaddress.type == AT_IPv4 || host->myaddress.type == AT_IPv6) && !hl->geoip_visible) {
GList *columns, *list;
GtkTreeViewColumn *column;
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(hl->table));
list = columns;
while(columns) {
const gchar *title_p;
gint id;
column = (GtkTreeViewColumn *)columns->data;
title_p = gtk_tree_view_column_get_title(column);
id = gtk_tree_view_column_get_sort_column_id(column);
if (title_p[0] != 0 && id >= GEOIP1_COLUMN) {
gtk_tree_view_column_set_visible(column, TRUE);
}
columns = g_list_next(columns);
}
g_list_free(list);
hl->geoip_visible = TRUE;
}
for (j = 0; j < NUM_GEOIP_COLS; j++) {
if (host->myaddress.type == AT_IPv4 && j < geoip_db_num_dbs()) {
const guchar *name = geoip_db_lookup_ipv4(j, pntoh32(host->myaddress.data), "-");
geoip[j] = g_strdup(name);
} else if (host->myaddress.type == AT_IPv6 && j < geoip_db_num_dbs()) {
const guchar *name;
const struct e_in6_addr *addr = (const struct e_in6_addr *) host->myaddress.data;
name = geoip_db_lookup_ipv6(j, *addr, "-");
geoip[j] = g_strdup(name);
} else {
geoip[j] = NULL;
}
}
#endif
get_hostlist_table_address(hl, host, entries);
host->iter_valid = TRUE;
gtk_list_store_insert_with_values( store , &host->iter, G_MAXINT,
ADR_COLUMN, entries[0],
PORT_COLUMN, entries[1],
PACKETS_COLUMN, host->tx_frames+host->rx_frames,
BYTES_COLUMN, host->tx_bytes+host->rx_bytes,
PKT_AB_COLUMN, host->tx_frames,
BYTES_AB_COLUMN, host->tx_bytes,
PKT_BA_COLUMN, host->rx_frames,
BYTES_BA_COLUMN, host->rx_bytes,
#ifdef HAVE_GEOIP
GEOIP1_COLUMN, geoip[0],
GEOIP2_COLUMN, geoip[1],
GEOIP3_COLUMN, geoip[2],
GEOIP4_COLUMN, geoip[3],
GEOIP5_COLUMN, geoip[4],
GEOIP6_COLUMN, geoip[5],
GEOIP7_COLUMN, geoip[6],
GEOIP8_COLUMN, geoip[7],
GEOIP9_COLUMN, geoip[8],
GEOIP10_COLUMN, geoip[9],
GEOIP11_COLUMN, geoip[10],
GEOIP12_COLUMN, geoip[11],
GEOIP13_COLUMN, geoip[12],
#endif
INDEX_COLUMN, i,
-1);
#ifdef HAVE_GEOIP
for (j = 0; j < NUM_GEOIP_COLS; j++)
g_free(geoip[j]);
#endif
}
else {
gtk_list_store_set (store, &host->iter,
PACKETS_COLUMN, host->tx_frames+host->rx_frames,
BYTES_COLUMN, host->tx_bytes+host->rx_bytes,
PKT_AB_COLUMN, host->tx_frames,
BYTES_AB_COLUMN, host->tx_bytes,
PKT_BA_COLUMN, host->rx_frames,
BYTES_BA_COLUMN, host->rx_bytes,
-1);
}
}
if (!first) {
if (!hl->fixed_col && hl->num_hosts >= 1000) {
hl->fixed_col = TRUE;
switch_to_fixed_col(hl->table);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(hl->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
static void
draw_hostlist_table_data_cb(void *arg)
{
draw_hostlist_table_data((hostlist_table *)arg);
}
static gboolean
csv_handle(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer data)
{
csv_t *csv = (csv_t *)data;
gchar *table_text;
int i;
guint idx;
guint64 value;
gtk_tree_model_get(model, iter, INDEX_COLUMN, &idx, -1);
for (i=0; i< csv->nb_cols; i++) {
if (i)
g_string_append(csv->CSV_str, ",");
switch(csv->columns_order[i]) {
case ADR_COLUMN:
case PORT_COLUMN:
gtk_tree_model_get(model, iter, csv->columns_order[i], &table_text, -1);
if (table_text) {
g_string_append_printf(csv->CSV_str, "\"%s\"", table_text);
g_free(table_text);
}
break;
case PACKETS_COLUMN:
case BYTES_COLUMN:
case PKT_AB_COLUMN:
case BYTES_AB_COLUMN:
case PKT_BA_COLUMN:
case BYTES_BA_COLUMN:
gtk_tree_model_get(model, iter, csv->columns_order[i], &value, -1);
g_string_append_printf(csv->CSV_str, "\"%" G_GINT64_MODIFIER "u\"", value);
break;
default:
gtk_tree_model_get(model, iter, csv->columns_order[i], &table_text, -1);
if (table_text) {
g_string_append_printf(csv->CSV_str, "\"%s\"", table_text);
g_free(table_text);
}
break;
}
}
g_string_append(csv->CSV_str,"\n");
return FALSE;
}
static void
copy_as_csv_cb(GtkWindow *copy_bt, gpointer data _U_)
{
GtkClipboard *cb;
char *savelocale;
GList *columns, *list;
GtkTreeViewColumn *column;
GtkListStore *store;
csv_t csv;
csv.talkers=(hostlist_table *)g_object_get_data(G_OBJECT(copy_bt), HOST_PTR_KEY);
if (!csv.talkers)
return;
savelocale = g_strdup(setlocale(LC_NUMERIC, NULL));
setlocale(LC_NUMERIC, "C");
csv.CSV_str = g_string_new("");
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(csv.talkers->table));
list = columns;
csv.nb_cols = 0;
while(columns) {
column = (GtkTreeViewColumn *)columns->data;
if (gtk_tree_view_column_get_visible(column)) {
csv.columns_order[csv.nb_cols] = gtk_tree_view_column_get_sort_column_id(column);
if (csv.nb_cols)
g_string_append(csv.CSV_str, ",");
g_string_append_printf(csv.CSV_str, "\"%s\"", gtk_tree_view_column_get_title(column));
csv.nb_cols++;
}
columns = g_list_next(columns);
}
g_list_free(list);
g_string_append(csv.CSV_str,"\n");
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(csv.talkers->table)));
gtk_tree_model_foreach(GTK_TREE_MODEL(store), csv_handle, &csv);
cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
gtk_clipboard_set_text(cb, csv.CSV_str->str, -1);
setlocale(LC_NUMERIC, savelocale);
g_free(savelocale);
g_string_free(csv.CSV_str, TRUE);
}
static void
map_init(void)
{
map_endpoint_opener = "{\n";
}
static gboolean
map_handle(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer data)
{
map_t *map = (map_t *)data;
gchar *table_entry, *esc_entry;
guint64 value;
gtk_tree_model_get(model, iter, map->col_lat, &table_entry, -1);
if (strcmp(table_entry, "-") == 0) {
g_free(table_entry);
return FALSE;
}
gtk_tree_model_get(model, iter, map->col_lon, &table_entry, -1);
if (strcmp(table_entry, "-") == 0) {
g_free(table_entry);
return FALSE;
}
fputs(map_endpoint_opener, map->out_file);
fputs(" 'type': 'Feature', 'geometry': { 'type': 'Point', 'coordinates': [", map->out_file);
gtk_tree_model_get(model, iter, map->col_lon, &table_entry, -1);
fputs(table_entry, map->out_file);
g_free(table_entry);
fputs(", ", map->out_file);
gtk_tree_model_get(model, iter, map->col_lat, &table_entry, -1);
fputs(table_entry, map->out_file);
g_free(table_entry);
fputs("] },\n", map->out_file);
fputs(" 'properties': { 'title': '", map->out_file);
gtk_tree_model_get(model, iter, map->col_ip, &table_entry, -1);
esc_entry = string_replace(table_entry, "'", "&#39;");
fputs(esc_entry, map->out_file);
g_free(table_entry);
g_free(esc_entry);
fputs("', 'description': '", map->out_file);
if (map->col_as_num >= 0) {
gtk_tree_model_get(model, iter, map->col_as_num, &table_entry, -1);
fputs("AS: ", map->out_file);
esc_entry = string_replace(table_entry, "'", "&#39;");
fputs(esc_entry, map->out_file);
g_free(table_entry);
g_free(esc_entry);
fputs("<br/>", map->out_file);
}
if (map->col_country >= 0) {
gtk_tree_model_get(model, iter, map->col_country, &table_entry, -1);
fputs("Country: ", map->out_file);
esc_entry = string_replace(table_entry, "'", "&#39;");
fputs(esc_entry, map->out_file);
g_free(table_entry);
g_free(esc_entry);
fputs("<br/>", map->out_file);
}
if (map->col_country >= 0) {
gtk_tree_model_get(model, iter, map->col_city, &table_entry, -1);
fputs("City: ", map->out_file);
esc_entry = string_replace(table_entry, "'", "&#39;");
fputs(esc_entry, map->out_file);
g_free(table_entry);
g_free(esc_entry);
fputs("<br/>", map->out_file);
}
gtk_tree_model_get(model, iter, map->col_packets, &value, -1);
fprintf(map->out_file, "Packets: %" G_GINT64_MODIFIER "u<br/>", value);
gtk_tree_model_get(model, iter, map->col_bytes, &value, -1);
fprintf(map->out_file, "Bytes: %" G_GINT64_MODIFIER "u", value);
fputs("' }\n", map->out_file);
fputs("}", map->out_file);
map_endpoint_opener = ",\n{\n";
map->hosts_written = TRUE;
return FALSE;
}
static void
open_as_map_cb(GtkWindow *copy_bt, gpointer data _U_)
{
guint32 i;
gchar *file_uri;
gboolean uri_open;
char *map_path, *map_filename;
char *tpl_filename;
char *tpl_line;
GList *columns, *list;
GtkTreeViewColumn *column;
GtkListStore *store;
map_t map;
FILE *tpl_file;
map.talkers = (hostlist_table *)g_object_get_data(G_OBJECT(copy_bt), HOST_PTR_KEY);
if (!map.talkers)
return;
map.col_lat = map.col_lon = map.col_country = map.col_city = map.col_as_num = map.col_ip = map.col_packets = map.col_bytes = -1;
map.hosts_written = FALSE;
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(map.talkers->table));
list = columns;
map.nb_cols = 0;
while(columns) {
column = (GtkTreeViewColumn *)columns->data;
i = gtk_tree_view_column_get_sort_column_id(column);
if(strcmp(map.talkers->default_titles[i], "Latitude") == 0) {
map.col_lat = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "Longitude") == 0) {
map.col_lon = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "Country") == 0) {
map.col_country = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "City") == 0) {
map.col_city = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "AS Number") == 0) {
map.col_as_num = i;
}
if(strcmp(map.talkers->default_titles[i], "Address") == 0) {
map.col_ip = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "Packets") == 0) {
map.col_packets = i;
map.nb_cols++;
}
if(strcmp(map.talkers->default_titles[i], "Bytes") == 0) {
map.col_bytes = i;
map.nb_cols++;
}
columns = g_list_next(columns);
}
g_list_free(list);
if(map.col_lat == -1 || map.col_lon == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Latitude/Longitude data not available (GeoIP installed?)");
return;
}
tpl_filename = get_datafile_path("ipmap.html");
tpl_file = ws_fopen(tpl_filename, "r");
if(tpl_file == NULL) {
open_failure_alert_box(tpl_filename, errno, FALSE);
g_free(tpl_filename);
return;
}
g_free(tpl_filename);
if (! create_tempdir(&map_path, "Wireshark IP Map ")) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not create temporary directory\n%s",
map_path);
fclose(tpl_file);
return;
}
map_filename = g_strdup_printf("%s%cipmap.html", map_path, G_DIR_SEPARATOR);
map.out_file = ws_fopen(map_filename, "w");
if(map.out_file == NULL) {
open_failure_alert_box(map_filename, errno, TRUE);
g_free(map_filename);
fclose(tpl_file);
return;
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(map.talkers->table)));
tpl_line = (char *)g_malloc(MAX_TPL_LINE_LEN);
while (fgets(tpl_line, MAX_TPL_LINE_LEN, tpl_file) != NULL) {
fputs(tpl_line, map.out_file);
if (strstr(tpl_line, "// Start endpoint list")) {
map_init();
gtk_tree_model_foreach(GTK_TREE_MODEL(store), map_handle, &map);
}
}
g_free(tpl_line);
fclose(tpl_file);
fclose(map.out_file);
if(!map.hosts_written) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No latitude/longitude data found");
g_free(map_filename);
return;
}
file_uri = g_filename_to_uri(map_filename, NULL, NULL);
g_free(map_filename);
uri_open = browser_open_url (file_uri);
if(!uri_open) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Couldn't open the file: \"%s\" in your web browser", file_uri);
g_free(file_uri);
return;
}
g_free(file_uri);
}
static void
init_default_col_size(GtkWidget *view)
{
default_col_size[ADR_COLUMN] = get_default_col_size(view, "00000000.000000000000");
default_col_size[PORT_COLUMN] = get_default_col_size(view, "000000");
default_col_size[PACKETS_COLUMN] = get_default_col_size(view, "00 000 000");
default_col_size[BYTES_COLUMN] = get_default_col_size(view, "0 000 000 000");
default_col_size[PKT_AB_COLUMN] = default_col_size[PACKETS_COLUMN];
default_col_size[PKT_BA_COLUMN] = default_col_size[PACKETS_COLUMN];
default_col_size[BYTES_AB_COLUMN] = default_col_size[BYTES_COLUMN];
default_col_size[BYTES_BA_COLUMN] = default_col_size[BYTES_COLUMN];
#ifdef HAVE_GEOIP
default_col_size[GEOIP1_COLUMN] = default_col_size[ADR_COLUMN];
default_col_size[GEOIP2_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP3_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP4_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP5_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP6_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP7_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP8_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP9_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP10_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP11_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP12_COLUMN] = default_col_size[GEOIP1_COLUMN];
default_col_size[GEOIP13_COLUMN] = default_col_size[GEOIP1_COLUMN];
#endif
}
static gboolean
init_hostlist_table_page(hostlist_table *hosttable, GtkWidget *vbox, gboolean hide_ports, const char *table_name, const char *tap_name,
const char *filter, tap_packet_cb packet_func)
{
guint i;
GString *error_string;
char title[256];
GtkListStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeSelection *sel;
static gboolean col_size = FALSE;
hosttable->default_titles[0] = "Address";
hosttable->default_titles[1] = "Port";
hosttable->default_titles[2] = "Packets";
hosttable->default_titles[3] = "Bytes";
hosttable->default_titles[4] = "Tx Packets";
hosttable->default_titles[5] = "Tx Bytes";
hosttable->default_titles[6] = "Rx Packets";
hosttable->default_titles[7] = "Rx Bytes";
#ifdef HAVE_GEOIP
for (i = 0; i < NUM_GEOIP_COLS; i++) {
if (i < geoip_db_num_dbs()) {
hosttable->default_titles[NUM_BUILTIN_COLS + i] = geoip_db_name(i);
} else {
hosttable->default_titles[NUM_BUILTIN_COLS + i] = "";
}
}
#endif
if (strcmp(table_name, "NCP")==0) {
hosttable->default_titles[1] = "Connection";
}
hosttable->has_ports=!hide_ports;
hosttable->num_hosts = 0;
hosttable->resolve_names=TRUE;
hosttable->page_lb = NULL;
hosttable->fixed_col = FALSE;
hosttable->geoip_visible = FALSE;
g_snprintf(title, sizeof(title), "%s Endpoints", table_name);
hosttable->name_lb = gtk_label_new(title);
gtk_box_pack_start(GTK_BOX(vbox), hosttable->name_lb, FALSE, FALSE, 0);
store = gtk_list_store_new (N_COLUMNS,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
#ifdef HAVE_GEOIP
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
#endif
G_TYPE_UINT);
hosttable->scrolled_window=scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), hosttable->scrolled_window, TRUE, TRUE, 0);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
hosttable->table = GTK_TREE_VIEW(tree);
sortable = GTK_TREE_SORTABLE(store);
g_object_unref (G_OBJECT (store));
if (!col_size) {
col_size = TRUE;
init_default_col_size(GTK_WIDGET(hosttable->table));
}
g_object_set_data(G_OBJECT(store), HOST_PTR_KEY, hosttable);
g_object_set_data(G_OBJECT(hosttable->table), HOST_PTR_KEY, hosttable);
for (i = 0; i < N_COLUMNS -1; i++) {
renderer = gtk_cell_renderer_text_new ();
g_object_set(renderer, "ypad", 0, NULL);
switch(i) {
case 0:
case 1:
column = gtk_tree_view_column_new_with_attributes (hosttable->default_titles[i], renderer, "text",
i, NULL);
if(hide_ports && i == 1){
gtk_tree_view_column_set_visible(column, FALSE);
}
gtk_tree_sortable_set_sort_func(sortable, i, hostlist_sort_column, GINT_TO_POINTER(i), NULL);
break;
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
column = gtk_tree_view_column_new_with_attributes (hosttable->default_titles[i], renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, u64_data_func, GINT_TO_POINTER(i), NULL);
break;
default:
column = gtk_tree_view_column_new_with_attributes (hosttable->default_titles[i], renderer, "text",
i, NULL);
gtk_tree_view_column_set_visible(column, FALSE);
#ifdef HAVE_GEOIP
if (i >= NUM_BUILTIN_COLS && i - NUM_BUILTIN_COLS < geoip_db_num_dbs()) {
int goip_type = geoip_db_type(i - NUM_BUILTIN_COLS);
if (goip_type == WS_LON_FAKE_EDITION || goip_type == WS_LAT_FAKE_EDITION) {
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
gtk_tree_sortable_set_sort_func(sortable, i, hostlist_sort_column, GINT_TO_POINTER(i), NULL);
}
}
#endif
break;
}
gtk_tree_view_column_set_sort_column_id(column, i);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
gtk_tree_view_column_set_min_width(column, 40);
gtk_tree_view_column_set_fixed_width(column, default_col_size[i]);
gtk_tree_view_append_column (hosttable->table, column);
#if 0
if (i == PACKETS_COLUMN) {
gtk_tree_view_column_clicked(column);
}
#endif
}
gtk_container_add(GTK_CONTAINER(hosttable->scrolled_window), (GtkWidget *)hosttable->table);
hosttable->num_hosts=0;
hosttable->hosts=NULL;
hosttable->hashtable=NULL;
gtk_tree_view_set_rules_hint(hosttable->table, TRUE);
gtk_tree_view_set_headers_clickable(hosttable->table, TRUE);
gtk_tree_view_set_reorderable (hosttable->table, TRUE);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hosttable->table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
hostlist_create_popup_menu(hosttable);
error_string=register_tap_listener(tap_name, hosttable, filter, 0, reset_hostlist_table_data_cb, packet_func, draw_hostlist_table_data_cb);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(hosttable);
return FALSE;
}
return TRUE;
}
void
init_hostlist_table(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter, tap_packet_cb packet_func)
{
hostlist_table *hosttable;
char *display_name;
char title[256];
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
gboolean ret;
GtkWidget *copy_bt;
#ifdef HAVE_GEOIP
GtkWidget *map_bt;
#endif
window_geometry_t tl_geom;
hosttable=g_new(hostlist_table,1);
hosttable->name=table_name;
hosttable->filter=filter;
hosttable->use_dfilter=FALSE;
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "%s Endpoints: %s", table_name, display_name);
g_free(display_name);
hosttable->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(hosttable->win), TRUE);
window_get_geometry(top_level, &tl_geom);
gtk_window_set_default_size(GTK_WINDOW(hosttable->win), tl_geom.width * 8 / 10, HL_DLG_HEIGHT);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_add(GTK_CONTAINER(hosttable->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), DLG_OUTER_MARGIN);
ret = init_hostlist_table_page(hosttable, vbox, hide_ports, table_name, tap_name, filter, packet_func);
if(ret == FALSE) {
g_free(hosttable);
return;
}
#ifdef HAVE_GEOIP
if( strstr(table_name, "IPv4") || strstr(table_name, "IPv6") ) {
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, WIRESHARK_STOCK_MAP, GTK_STOCK_HELP, NULL);
} else {
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, GTK_STOCK_HELP, NULL);
}
#else
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, GTK_STOCK_HELP, NULL);
#endif
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(hosttable->win, close_bt, window_cancel_button_cb);
copy_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_object_set_data(G_OBJECT(copy_bt), HOST_PTR_KEY, hosttable);
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
#ifdef HAVE_GEOIP
map_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_MAP);
if(map_bt != NULL) {
gtk_widget_set_tooltip_text(map_bt, "Show a map of the IP addresses (internet connection required).");
g_object_set_data(G_OBJECT(map_bt), HOST_PTR_KEY, hosttable);
g_signal_connect(map_bt, "clicked", G_CALLBACK(open_as_map_cb), NULL);
}
#endif
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_ENDPOINTS_DIALOG);
g_signal_connect(hosttable->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(hosttable->win, "destroy", G_CALLBACK(hostlist_win_destroy_cb), hosttable);
gtk_widget_show_all(hosttable->win);
window_present(hosttable->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(hosttable->win));
}
static void
ct_nb_switch_page_cb(GtkNotebook *nb, gpointer *pg _U_, guint page, gpointer data)
{
GtkWidget *copy_bt = (GtkWidget *) data;
void ** pages = (void **)g_object_get_data(G_OBJECT(nb), NB_PAGES_KEY);
page++;
if (pages && page > 0 && (int) page <= GPOINTER_TO_INT(pages[0]) && copy_bt) {
g_object_set_data(G_OBJECT(copy_bt), HOST_PTR_KEY, pages[page]);
}
}
static void
ct_nb_map_switch_page_cb(GtkNotebook *nb, gpointer *pg _U_, guint page, gpointer data)
{
GtkWidget *map_bt = (GtkWidget *) data;
void ** pages = (void **)g_object_get_data(G_OBJECT(nb), NB_PAGES_KEY);
page++;
if (pages && page > 0 && (int) page <= GPOINTER_TO_INT(pages[0]) && map_bt) {
g_object_set_data(G_OBJECT(map_bt), HOST_PTR_KEY, pages[page]);
if( strstr(((hostlist_table *)pages[page])->name, "IPv4") ||
strstr(((hostlist_table *)pages[page])->name, "IPv6") ) {
gtk_widget_set_sensitive(map_bt, TRUE);
} else {
gtk_widget_set_sensitive(map_bt, FALSE);
}
}
}
static void
hostlist_win_destroy_notebook_cb(GtkWindow *win _U_, gpointer data)
{
void ** pages = (void **)data;
int page;
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
hostlist_win_destroy_cb(NULL, pages[page]);
}
g_free(pages);
}
static hostlist_table *
init_hostlist_notebook_page_cb(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter,
tap_packet_cb packet_func)
{
gboolean ret;
GtkWidget *page_vbox;
hostlist_table *hosttable;
hosttable=g_new(hostlist_table,1);
hosttable->name=table_name;
hosttable->filter=filter;
hosttable->use_dfilter=FALSE;
page_vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
hosttable->win = page_vbox;
gtk_container_set_border_width(GTK_CONTAINER(page_vbox), 6);
ret = init_hostlist_table_page(hosttable, page_vbox, hide_ports, table_name, tap_name, filter, packet_func);
if(ret == FALSE) {
g_free(hosttable);
return NULL;
}
return hosttable;
}
void
register_hostlist_table(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter, tap_packet_cb packet_func)
{
register_hostlist_t *table;
table = g_new(register_hostlist_t,1);
table->hide_ports = hide_ports;
table->table_name = table_name;
table->tap_name = tap_name;
table->filter = filter;
table->packet_func = packet_func;
registered_hostlist_tables = g_slist_append(registered_hostlist_tables, table);
}
static void
hostlist_resolve_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = (void **)data;
gboolean resolve_names;
hostlist_table *hosttable;
resolve_names = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
hosttable = (hostlist_table *)pages[page];
hosttable->resolve_names = resolve_names;
draw_hostlist_table_addresses(hosttable);
}
}
static void
hostlist_filter_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = (void **)data;
gboolean use_filter;
hostlist_table *hosttable = NULL;
use_filter = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
hosttable = (hostlist_table *)pages[page];
hosttable->use_dfilter = use_filter;
reset_hostlist_table_data(hosttable);
}
cf_retap_packets(&cfile);
if (hosttable) {
gdk_window_raise(gtk_widget_get_window(hosttable->win));
}
}
void
init_hostlist_notebook_cb(GtkWidget *w _U_, gpointer d _U_)
{
hostlist_table *hosttable;
char *display_name;
char title[256];
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
GtkWidget *win;
GtkWidget *resolv_cb;
GtkWidget *filter_cb;
int page;
void ** pages;
GtkWidget *nb;
GtkWidget *page_lb;
GSList *current_table;
register_hostlist_t *registered;
GtkWidget *copy_bt;
#ifdef HAVE_GEOIP
GtkWidget *map_bt;
#endif
window_geometry_t tl_geom;
pages = (void **)g_malloc(sizeof(void *) * (g_slist_length(registered_hostlist_tables) + 1));
win = dlg_window_new("hostlist");
gtk_window_set_destroy_with_parent (GTK_WINDOW(win), TRUE);
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Endpoints: %s", display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(win), title);
window_get_geometry(top_level, &tl_geom);
gtk_window_set_default_size(GTK_WINDOW(win), tl_geom.width * 8 / 10, HL_DLG_HEIGHT);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_add(GTK_CONTAINER(win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), DLG_OUTER_MARGIN);
nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(vbox), nb, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(nb), NB_PAGES_KEY, pages);
page = 0;
current_table = registered_hostlist_tables;
while(current_table) {
registered = (register_hostlist_t *)current_table->data;
page_lb = gtk_label_new("");
hosttable = init_hostlist_notebook_page_cb(registered->hide_ports, registered->table_name, registered->tap_name,
registered->filter, registered->packet_func);
g_object_set_data(G_OBJECT(hosttable->win), HOST_PTR_KEY, hosttable);
gtk_notebook_append_page(GTK_NOTEBOOK(nb), hosttable->win, page_lb);
hosttable->win = win;
hosttable->page_lb = page_lb;
pages[++page] = hosttable;
current_table = g_slist_next(current_table);
}
pages[0] = GINT_TO_POINTER(page);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_UNRELATED_SPACING, FALSE);
gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
resolv_cb = gtk_check_button_new_with_mnemonic("Name resolution");
gtk_box_pack_start(GTK_BOX(hbox), resolv_cb, FALSE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(resolv_cb), TRUE);
gtk_widget_set_tooltip_text(resolv_cb,
"Show results of name resolutions rather than the \"raw\" values. Please note: The corresponding name resolution must be enabled.");
g_signal_connect(resolv_cb, "toggled", G_CALLBACK(hostlist_resolve_toggle_dest), pages);
filter_cb = gtk_check_button_new_with_mnemonic("Limit to display filter");
gtk_box_pack_start(GTK_BOX(hbox), filter_cb, FALSE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(filter_cb), FALSE);
gtk_widget_set_tooltip_text(filter_cb, "Limit the list to endpoints matching the current display filter.");
g_signal_connect(filter_cb, "toggled", G_CALLBACK(hostlist_filter_toggle_dest), pages);
#ifdef HAVE_GEOIP
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, WIRESHARK_STOCK_MAP, GTK_STOCK_HELP, NULL);
#else
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, GTK_STOCK_HELP, NULL);
#endif
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(win, close_bt, window_cancel_button_cb);
copy_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
g_object_set_data(G_OBJECT(copy_bt), HOST_PTR_KEY, pages[page]);
#ifdef HAVE_GEOIP
map_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_MAP);
gtk_widget_set_tooltip_text(map_bt, "Show a map of the IP addresses (internet connection required).");
g_object_set_data(G_OBJECT(map_bt), HOST_PTR_KEY, pages[page]);
g_signal_connect(map_bt, "clicked", G_CALLBACK(open_as_map_cb), NULL);
g_signal_connect(nb, "switch-page", G_CALLBACK(ct_nb_map_switch_page_cb), map_bt);
gtk_widget_set_sensitive(map_bt, FALSE);
#endif
g_signal_connect(nb, "switch-page", G_CALLBACK(ct_nb_switch_page_cb), copy_bt);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_ENDPOINTS_DIALOG);
g_signal_connect(win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(win, "destroy", G_CALLBACK(hostlist_win_destroy_notebook_cb), pages);
gtk_widget_show_all(win);
window_present(win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(win));
}
static guint
host_hash(gconstpointer v)
{
const host_key_t *key = (const host_key_t *)v;
guint hash_val;
hash_val = 0;
ADD_ADDRESS_TO_HASH(hash_val, &key->myaddress);
hash_val += key->port;
return hash_val;
}
static gint
host_match(gconstpointer v, gconstpointer w)
{
const host_key_t *v1 = (const host_key_t *)v;
const host_key_t *v2 = (const host_key_t *)w;
if (v1->port == v2->port &&
ADDRESSES_EQUAL(&v1->myaddress, &v2->myaddress)) {
return 1;
}
return 0;
}
void
add_hostlist_table_data(hostlist_table *hl, const address *addr, guint32 port, gboolean sender, int num_frames, int num_bytes, SAT_E sat, int port_type_val)
{
hostlist_talker_t *talker=NULL;
int talker_idx=0;
if(hl->hosts==NULL){
hl->hosts=g_array_sized_new(FALSE, FALSE, sizeof(hostlist_talker_t), 10000);
hl->hashtable = g_hash_table_new_full(host_hash,
host_match,
g_free,
NULL);
}
else {
host_key_t existing_key;
existing_key.myaddress = *addr;
existing_key.port = port;
talker_idx = GPOINTER_TO_UINT(g_hash_table_lookup(hl->hashtable, &existing_key));
if (talker_idx) {
talker_idx--;
talker=&g_array_index(hl->hosts, hostlist_talker_t, talker_idx);
}
}
if(talker==NULL){
host_key_t *new_key;
hostlist_talker_t host;
COPY_ADDRESS(&host.myaddress, addr);
host.sat=sat;
host.port_type=port_type_val;
host.port=port;
host.rx_frames=0;
host.tx_frames=0;
host.rx_bytes=0;
host.tx_bytes=0;
host.iter_valid = FALSE;
host.modified = TRUE;
g_array_append_val(hl->hosts, host);
talker_idx= hl->num_hosts;
talker=&g_array_index(hl->hosts, hostlist_talker_t, talker_idx);
new_key = g_new(host_key_t,1);
SET_ADDRESS(&new_key->myaddress, talker->myaddress.type, talker->myaddress.len, talker->myaddress.data);
new_key->port = port;
g_hash_table_insert(hl->hashtable, new_key, GUINT_TO_POINTER(talker_idx +1));
hl->num_hosts++;
}
talker->modified = TRUE;
if( sender ){
talker->tx_frames+=num_frames;
talker->tx_bytes+=num_bytes;
} else {
talker->rx_frames+=num_frames;
talker->rx_bytes+=num_bytes;
}
}
