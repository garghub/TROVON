static void
dhcp_free_hash( gpointer key _U_ , gpointer value, gpointer user_data _U_ )
{
g_free(value);
}
static void
dhcp_reset_hash(gchar *key _U_ , dhcp_message_type_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
dhcp_draw_message_type(gchar *key _U_, dhcp_message_type_t *data, gchar * unused _U_ )
{
char string_buff[256];
if ((data==NULL) || (data->packets==0))
return;
if (data->widget==NULL){
GtkWidget *tmp;
int x = 2*((data->sp->index) % 2);
int y = (data->sp->index) /2;
tmp = gtk_label_new( data->name );
gtk_table_attach_defaults(GTK_TABLE(data->sp->table_message_type), tmp, x, x+1, y, y+1);
gtk_label_set_justify(GTK_LABEL(tmp), GTK_JUSTIFY_LEFT);
gtk_widget_show(tmp);
g_snprintf( string_buff, sizeof(string_buff), "%9d", data->packets );
data->widget = gtk_label_new( string_buff );
gtk_table_attach_defaults(GTK_TABLE(data->sp->table_message_type), data->widget, x+1, x+2, y, y+1);
gtk_label_set_justify(GTK_LABEL(data->widget), GTK_JUSTIFY_LEFT);
gtk_widget_show( data->widget );
data->sp->index++;
} else {
g_snprintf( string_buff, sizeof(string_buff), "%9d", data->packets );
gtk_label_set_text( GTK_LABEL(data->widget), string_buff);
}
}
static void
dhcpstat_reset(void *psp)
{
dhcpstat_t *sp=psp;
g_hash_table_foreach( sp->hash, (GHFunc)dhcp_reset_hash, NULL);
}
static int
dhcpstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
dhcpstat_t *sp=psp;
const bootp_info_value_t value=pri;
dhcp_message_type_t *sc;
if (sp==NULL)
return 0;
sc = g_hash_table_lookup(
sp->hash,
value);
if (!sc) {
sc = g_malloc( sizeof(dhcp_message_type_t) );
sc -> packets = 1;
sc -> name = value;
sc -> widget=NULL;
sc -> sp = sp;
g_hash_table_insert(
sp->hash,
(gpointer) value,
sc);
} else {
sc->packets++;
}
return 1;
}
static void
dhcpstat_draw(void *psp)
{
dhcpstat_t *sp=psp;
guint idx;
idx=sp->index;
g_hash_table_foreach( sp->hash, (GHFunc) dhcp_draw_message_type, NULL );
if (idx != sp->index){
gtk_table_resize ( GTK_TABLE(sp->table_message_type), sp->index % 2 , 4);
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
dhcpstat_t *sp=(dhcpstat_t *)data;
protect_thread_critical_region();
remove_tap_listener(sp);
unprotect_thread_critical_region();
g_free(sp->filter);
g_hash_table_foreach( sp->hash, (GHFunc)dhcp_free_hash, NULL);
g_hash_table_destroy( sp->hash);
g_free(sp);
}
static void
dhcpstat_init(const char *optarg, void *userdata _U_)
{
dhcpstat_t *sp;
const char *filter=NULL;
char *title=NULL;
GString *error_string;
GtkWidget *message_type_fr;
GtkWidget *vbox;
GtkWidget *bt_close;
GtkWidget *bbox;
if (strncmp (optarg, "bootp,stat,", 11) == 0){
filter=optarg+11;
} else {
filter=NULL;
}
sp = g_malloc( sizeof(dhcpstat_t) );
sp->hash = g_hash_table_new( g_str_hash, g_str_equal);
if(filter){
sp->filter=g_strdup(filter);
title=g_strdup_printf("DHCP statistics with filter: %s", filter);
} else {
sp->filter=NULL;
title=g_strdup("DHCP statistics");
}
sp->win= dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(sp->win), TRUE);
g_free(title);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(sp->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
message_type_fr = gtk_frame_new("DHCP Message Type");
gtk_container_add(GTK_CONTAINER(vbox), message_type_fr);
gtk_widget_show(message_type_fr);
sp->table_message_type = gtk_table_new( 0, 4, FALSE);
gtk_table_set_col_spacings( GTK_TABLE(sp->table_message_type), 10);
gtk_container_add( GTK_CONTAINER( message_type_fr), sp->table_message_type);
gtk_container_set_border_width( GTK_CONTAINER(sp->table_message_type) , 10);
sp->index = 0;
error_string = register_tap_listener(
"bootp",
sp,
filter,
0,
dhcpstat_reset,
dhcpstat_packet,
dhcpstat_draw);
if (error_string){
simple_dialog( ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str );
g_free(sp->filter);
g_free(sp);
g_string_free(error_string, TRUE);
return ;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
bt_close = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(sp->win, bt_close, window_cancel_button_cb);
g_signal_connect(sp->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(sp->win, "destroy", G_CALLBACK(win_destroy_cb), sp);
gtk_widget_show_all(sp->win);
window_present(sp->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(sp->win));
}
void
register_tap_listener_gtkdhcpstat(void)
{
register_dfilter_stat(&dhcp_stat_dlg, "BOOTP-DHCP",
REGISTER_STAT_GROUP_UNSORTED);
}
void bootp_dhcp_stat_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &dhcp_stat_dlg);
}
