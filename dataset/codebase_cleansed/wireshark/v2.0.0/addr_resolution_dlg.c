static void
eth_hash_to_texbuff(gpointer key, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
guint8 *eth_addr = (guint8*)key;
hashether_t* tp = (hashether_t*)value;
g_snprintf(string_buff, ADDRESS_STR_MAX, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X Status: %u %s %s\n",
eth_addr[0], eth_addr[1], eth_addr[2],
eth_addr[3], eth_addr[4], eth_addr[5],
get_hash_ether_status(tp),
get_hash_ether_hexaddr(tp),
get_hash_ether_resolved_name(tp));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
manuf_hash_to_texbuff(gpointer key, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
hashmanuf_t *manuf = (hashmanuf_t*)value;
int eth_as_gint = *(int*)key;
g_snprintf(string_buff, ADDRESS_STR_MAX, "%.2X:%.2X:%.2X %s\n",eth_as_gint>>16, (eth_as_gint>>8)&0xff, eth_as_gint&0xff, get_hash_manuf_resolved_name(manuf));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
wka_hash_to_texbuff(gpointer key, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
gchar *name = (gchar *)value;
guint8 *eth_addr = (guint8*)key;
g_snprintf(string_buff, ADDRESS_STR_MAX, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X %s\n",
eth_addr[0], eth_addr[1], eth_addr[2],
eth_addr[3], eth_addr[4], eth_addr[5],
name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
serv_port_hash_to_texbuff(gpointer key, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
serv_port_t *serv_port_table = (serv_port_t *)value;
int port = *(int*)key;
g_snprintf(string_buff, ADDRESS_STR_MAX, "Port %u \n"" TCP %s\n"" UDP %s\n"" SCTP %s\n"" DCCP %s\n",
port,
serv_port_table->tcp_name,
serv_port_table->udp_name,
serv_port_table->sctp_name,
serv_port_table->dccp_name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
ipv4_hash_table_to_texbuff(gpointer key, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
hashipv4_t *ipv4_hash_table_entry = (hashipv4_t *)value;
int addr = GPOINTER_TO_UINT(key);
g_snprintf(string_buff, ADDRESS_STR_MAX, "Key:0x%x IP: %s, Name: %s\n",
addr,
ipv4_hash_table_entry->ip,
ipv4_hash_table_entry->name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
ipv4_hash_table_resolved_to_texbuff(gpointer key _U_, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
hashipv4_t *ipv4_hash_table_entry = (hashipv4_t *)value;
if((ipv4_hash_table_entry->flags & DUMMY_ADDRESS_ENTRY)== 0){
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s\t%s\n",
ipv4_hash_table_entry->ip,
ipv4_hash_table_entry->name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
}
static void
ipv6_hash_table_to_texbuff(gpointer key _U_, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
hashipv6_t *ipv6_hash_table_entry = (hashipv6_t *)value;
g_snprintf(string_buff, ADDRESS_STR_MAX, "IP: %s, Name: %s\n",
ipv6_hash_table_entry->ip6,
ipv6_hash_table_entry->name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
ipv6_hash_table_resolved_to_texbuff(gpointer key _U_, gpointer value, gpointer user_data)
{
gchar string_buff[ADDRESS_STR_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
hashipv6_t *ipv6_hash_table_entry = (hashipv6_t *)value;
if((ipv6_hash_table_entry->flags & DUMMY_ADDRESS_ENTRY)== 0){
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s\t%s\n",
ipv6_hash_table_entry->ip6,
ipv6_hash_table_entry->name);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
}
static void
addres_resolution_to_texbuff(GtkTextBuffer *buffer)
{
gchar string_buff[ADDRESS_STR_MAX];
GHashTable *manuf_hashtable;
GHashTable *wka_hashtable;
GHashTable *eth_hashtable;
GHashTable *serv_port_hashtable;
GHashTable *ipv4_hash_table;
GHashTable *ipv6_hash_table;
g_snprintf(string_buff, ADDRESS_STR_MAX, "# Hosts information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_snprintf(string_buff, ADDRESS_STR_MAX, "# Host data gathered from %s\n\n", cfile.filename);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
/* Dump the v4 addresses first, then v6 */
ipv4_hash_table = get_ipv4_hash_table();
if(ipv4_hash_table){
g_hash_table_foreach( ipv4_hash_table, ipv4_hash_table_resolved_to_texbuff, buffer);
}
ipv6_hash_table = get_ipv6_hash_table();
if(ipv6_hash_table){
g_hash_table_foreach( ipv6_hash_table, ipv6_hash_table_resolved_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# Address resolution IPv4 Hash table \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
if(ipv4_hash_table){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(ipv4_hash_table));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( ipv4_hash_table, ipv4_hash_table_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# Address resolution IPv6 Hash table \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
if(ipv6_hash_table){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(ipv6_hash_table));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( ipv6_hash_table, ipv6_hash_table_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# Port names information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
serv_port_hashtable = get_serv_port_hashtable();
if(serv_port_hashtable){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(serv_port_hashtable));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( serv_port_hashtable, serv_port_hash_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# Eth names information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
eth_hashtable = get_eth_hashtable();
if(eth_hashtable){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(eth_hashtable));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( eth_hashtable, eth_hash_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# Manuf information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
manuf_hashtable = get_manuf_hashtable();
if(manuf_hashtable){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(manuf_hashtable));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( manuf_hashtable, manuf_hash_to_texbuff, buffer);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "\n\n# wka information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
wka_hashtable = get_wka_hashtable();
if(wka_hashtable){
g_snprintf(string_buff, ADDRESS_STR_MAX, "# With %i entries\n#\n", g_hash_table_size(wka_hashtable));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( wka_hashtable, wka_hash_to_texbuff, buffer);
}
}
void
addr_resolution_dlg (GtkAction *action _U_, gpointer data _U_)
{
GtkWidget *vbox;
GtkWidget *view;
GtkWidget *scroll;
GtkWidget *bbox;
GtkWidget *ok_bt, *cancel_bt, *help_bt;
GtkTextBuffer *buffer;
addr_resolution_dlg_w = dlg_window_new ("Address Resolution");
gtk_widget_set_size_request (addr_resolution_dlg_w, 750, 350);
gtk_window_set_resizable (GTK_WINDOW (addr_resolution_dlg_w), TRUE);
gtk_container_set_border_width (GTK_CONTAINER (addr_resolution_dlg_w), DLG_OUTER_MARGIN);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add (GTK_CONTAINER (addr_resolution_dlg_w), vbox);
gtk_widget_show (vbox);
view = gtk_text_view_new ();
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(view), GTK_WRAP_WORD);
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
#if GTK_CHECK_VERSION(3, 0, 0)
gtk_widget_override_font(view, user_font_get_regular());
#else
gtk_widget_modify_font(view, user_font_get_regular());
#endif
gtk_widget_show (view);
scroll = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(scroll), view);
gtk_widget_show(scroll);
gtk_box_pack_start(GTK_BOX (vbox), scroll, TRUE, TRUE, 0);
/* Get the address list */
addres_resolution_to_texbuff(buffer);
/* Button row. */
bbox = dlg_button_row_new (GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(window_cancel_button_cb), addr_resolution_dlg_w); /* act as cxl */
gtk_widget_set_sensitive (ok_bt, TRUE);
cancel_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button (addr_resolution_dlg_w, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_HELP);
#if 0
g_signal_connect (help_bt, "clicked",/* G_CALLBACK(topic_cb)*/NULL, /*(gpointer)HELP_MANUAL_ADDR_RESOLVE_DIALOG*/NULL);
#endif
gtk_widget_set_sensitive (help_bt, FALSE);
gtk_widget_grab_default (ok_bt);
/*g_signal_connect (addr_resolution_dlg_w, "delete_event"
