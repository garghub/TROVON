static int
ssl_queue_packet_data(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_, const void *ssl)
{
follow_info_t* follow_info = tapdata;
SslDecryptedRecord* rec;
SslDataInfo* appl_data;
gint total_len;
guchar *p;
int proto_ssl = (long) ssl;
SslPacketInfo* pi = p_get_proto_data(pinfo->fd, proto_ssl);
if (!pi || !pi->appl_data)
return 0;
total_len = 0;
appl_data = pi->appl_data;
do {
total_len += appl_data->plain_data.data_len;
appl_data = appl_data->next;
} while (appl_data);
rec = g_malloc(sizeof(SslDecryptedRecord) + total_len);
if (follow_info->client_port == 0) {
follow_info->client_port = pinfo->srcport;
COPY_ADDRESS(&follow_info->client_ip, &pinfo->src);
}
if (ADDRESSES_EQUAL(&follow_info->client_ip, &pinfo->src) &&
follow_info->client_port == pinfo->srcport)
rec->is_server = 0;
else
rec->is_server = 1;
follow_info->bytes_written[rec->is_server] += total_len;
rec->data.data = (guchar*)(rec + 1);
rec->data.data_len = total_len;
appl_data = pi->appl_data;
p = rec->data.data;
do {
memcpy(p, appl_data->plain_data.data, appl_data->plain_data.data_len);
p += appl_data->plain_data.data_len;
appl_data = appl_data->next;
} while (appl_data);
follow_info->payload = g_list_append(
follow_info->payload,rec);
return 0;
}
void
follow_ssl_stream_cb(GtkWidget * w _U_, gpointer data _U_)
{
GtkWidget *filter_te, *filter_cm;
gchar *follow_filter;
const gchar *previous_filter;
int filter_out_filter_len, previous_filter_len;
const char *hostname0, *hostname1;
char *port0, *port1;
gchar *server_to_client_string = NULL;
gchar *client_to_server_string = NULL;
gchar *both_directions_string = NULL;
follow_stats_t stats;
follow_info_t *follow_info;
GString* msg;
if (!packet_is_ssl(cfile.edt)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error following stream. Please make\n"
"sure you have an SSL packet selected.");
return;
}
follow_info = g_new0(follow_info_t, 1);
follow_info->follow_type = FOLLOW_SSL;
reset_tcp_reassembly();
follow_filter = build_follow_filter(&cfile.edt->pi);
if (!follow_filter)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error creating filter for this stream.\n"
"A network layer header is needed");
g_free(follow_info);
return;
}
filter_cm = g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
follow_info->filter_te = filter_te;
previous_filter =
(const gchar *)gtk_entry_get_text(GTK_ENTRY(filter_te));
previous_filter_len = previous_filter?(int)strlen(previous_filter):0;
filter_out_filter_len = (int)strlen(follow_filter) + previous_filter_len + 16;
follow_info->filter_out_filter = (gchar *)g_malloc(filter_out_filter_len);
if(previous_filter_len) {
g_snprintf(follow_info->filter_out_filter, filter_out_filter_len,
"%s and !(%s)", previous_filter, follow_filter);
} else {
g_snprintf(follow_info->filter_out_filter, filter_out_filter_len,
"!(%s)", follow_filter);
}
msg = register_tap_listener("ssl", follow_info, follow_filter, 0,
NULL, ssl_queue_packet_data, NULL);
if (msg)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't register ssl tap: %s\n",msg->str);
g_free(follow_info->filter_out_filter);
g_free(follow_info);
g_free(follow_filter);
return;
}
gtk_entry_set_text(GTK_ENTRY(filter_te), follow_filter);
main_filter_packets(&cfile, follow_filter, TRUE);
g_free(follow_filter);
remove_tap_listener(follow_info);
follow_stats(&stats);
if (stats.is_ipv6) {
struct e_in6_addr ipaddr;
memcpy(&ipaddr, stats.ip_address[0], 16);
hostname0 = get_hostname6(&ipaddr);
memcpy(&ipaddr, stats.ip_address[0], 16);
hostname1 = get_hostname6(&ipaddr);
} else {
guint32 ipaddr;
memcpy(&ipaddr, stats.ip_address[0], 4);
hostname0 = get_hostname(ipaddr);
memcpy(&ipaddr, stats.ip_address[1], 4);
hostname1 = get_hostname(ipaddr);
}
port0 = get_tcp_port(stats.port[0]);
port1 = get_tcp_port(stats.port[1]);
follow_info->is_ipv6 = stats.is_ipv6;
both_directions_string = g_strdup_printf("Entire conversation (%u bytes)", follow_info->bytes_written[0] + follow_info->bytes_written[1]);
if(follow_info->client_port == stats.port[0]) {
server_to_client_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname0, port0,
hostname1, port1,
follow_info->bytes_written[0]);
client_to_server_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname1, port1,
hostname0, port0,
follow_info->bytes_written[1]);
} else {
server_to_client_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname1, port1,
hostname0, port0,
follow_info->bytes_written[0]);
client_to_server_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname0, port0,
hostname1, port1,
follow_info->bytes_written[1]);
}
follow_stream("Follow SSL Stream", follow_info, both_directions_string,
server_to_client_string, client_to_server_string);
g_free(both_directions_string);
g_free(server_to_client_string);
g_free(client_to_server_string);
}
frs_return_t
follow_read_ssl_stream(follow_info_t *follow_info,
gboolean (*print_line_fcn_p)(char *, size_t, gboolean, void *),
void *arg)
{
guint32 global_client_pos = 0, global_server_pos = 0;
guint32 server_packet_count = 0;
guint32 client_packet_count = 0;
guint32 *global_pos;
gboolean skip;
GList* cur;
frs_return_t frs_return;
for (cur = follow_info->payload; cur; cur = g_list_next(cur)) {
SslDecryptedRecord* rec = cur->data;
skip = FALSE;
if (!rec->is_server) {
global_pos = &global_client_pos;
if (follow_info->show_stream == FROM_SERVER) {
skip = TRUE;
}
} else {
global_pos = &global_server_pos;
if (follow_info->show_stream == FROM_CLIENT) {
skip = TRUE;
}
}
if (!skip) {
size_t nchars = rec->data.data_len;
gchar *buffer = g_memdup(rec->data.data, (guint) nchars);
frs_return = follow_show(follow_info, print_line_fcn_p, buffer, nchars,
rec->is_server, arg, global_pos,
&server_packet_count, &client_packet_count);
g_free(buffer);
if(frs_return == FRS_PRINT_ERROR)
return frs_return;
}
}
return FRS_OK;
}
