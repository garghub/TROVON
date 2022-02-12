static int
ssl_queue_packet_data(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_, const void *ssl)
{
follow_info_t * follow_info = (follow_info_t*) tapdata;
SslDecryptedRecord * rec = NULL;
SslDataInfo * appl_data = NULL;
int proto_ssl = GPOINTER_TO_INT(ssl);
SslPacketInfo * pi = NULL;
show_stream_t from = FROM_CLIENT;
pi = (SslPacketInfo*) p_get_proto_data(wmem_file_scope(), pinfo, proto_ssl, 0);
if (!pi || !pi->appl_data) return 0;
if (follow_info->client_port == 0) {
follow_info->client_port = pinfo->srcport;
COPY_ADDRESS(&follow_info->client_ip, &pinfo->src);
}
if (ADDRESSES_EQUAL(&follow_info->client_ip, &pinfo->src) &&
follow_info->client_port == pinfo->srcport) {
from = FROM_CLIENT;
} else {
from = FROM_SERVER;
}
for (appl_data = pi->appl_data; appl_data != NULL; appl_data = appl_data->next) {
if (appl_data->seq < follow_info->bytes_written[from]) continue;
rec = (SslDecryptedRecord*) g_malloc(sizeof(SslDecryptedRecord) + appl_data->plain_data.data_len);
rec->is_from_server = from == FROM_SERVER;
rec->data.data = (guchar*) (rec + 1);
rec->data.data_len = appl_data->plain_data.data_len;
memcpy(rec->data.data, appl_data->plain_data.data, appl_data->plain_data.data_len);
follow_info->payload = g_list_append(follow_info->payload, rec);
follow_info->bytes_written[from] += rec->data.data_len;
}
return 0;
}
void
follow_ssl_stream_cb(GtkWidget * w _U_, gpointer data _U_)
{
GtkWidget * filter_te;
GtkWidget * filter_cm;
gchar * follow_filter;
const gchar * previous_filter;
int filter_out_filter_len;
int previous_filter_len;
const char * hostname0;
const char * hostname1;
const char * port0;
const char * port1;
const char * client_hostname;
const char * server_hostname;
const char * client_port;
const char * server_port;
gchar * server_to_client_string = NULL;
gchar * client_to_server_string = NULL;
gchar * both_directions_string = NULL;
const gchar * single_direction_format = NULL;
follow_stats_t stats;
follow_info_t * follow_info;
GString * msg;
if (!epan_dissect_packet_contains_field(cfile.edt, "ssl")) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error following stream. Please make\n"
"sure you have an SSL packet selected.");
return;
}
follow_info = g_new0(follow_info_t, 1);
follow_info->follow_type = FOLLOW_SSL;
reset_tcp_reassembly();
follow_filter = build_follow_conv_filter(&cfile.edt->pi);
if (!follow_filter)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error creating filter for this stream.\n"
"A network layer header is needed");
g_free(follow_info);
return;
}
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
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
memcpy(&ipaddr, stats.ip_address[1], 16);
hostname1 = get_hostname6(&ipaddr);
} else {
guint32 ipaddr;
memcpy(&ipaddr, stats.ip_address[0], 4);
hostname0 = get_hostname(ipaddr);
memcpy(&ipaddr, stats.ip_address[1], 4);
hostname1 = get_hostname(ipaddr);
}
port0 = ep_tcp_port_to_display(stats.port[0]);
port1 = ep_tcp_port_to_display(stats.port[1]);
follow_info->is_ipv6 = stats.is_ipv6;
both_directions_string = g_strdup_printf("Entire conversation (%u bytes)", follow_info->bytes_written[0] + follow_info->bytes_written[1]);
if ((follow_info->client_port == stats.port[0]) &&
((stats.is_ipv6 && (memcmp(follow_info->client_ip.data, stats.ip_address[0], 16) == 0)) ||
(!stats.is_ipv6 && (memcmp(follow_info->client_ip.data, stats.ip_address[0], 4) == 0)))) {
server_hostname = hostname0;
server_port = port0;
client_hostname = hostname1;
client_port = port1;
} else {
server_hostname = hostname1;
server_port = port1;
client_hostname = hostname0;
client_port = port0;
}
single_direction_format = "%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)";
server_to_client_string = g_strdup_printf(single_direction_format,
server_hostname, server_port,
client_hostname, client_port,
follow_info->bytes_written[0]);
client_to_server_string = g_strdup_printf(single_direction_format,
client_hostname, client_port,
server_hostname, server_port,
follow_info->bytes_written[1]);
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
guint32 * global_pos;
GList * cur;
frs_return_t frs_return;
for (cur = follow_info->payload; cur; cur = g_list_next(cur)) {
SslDecryptedRecord * rec = (SslDecryptedRecord*) cur->data;
gboolean include_rec = FALSE;
if (rec->is_from_server) {
global_pos = &global_server_pos;
include_rec = (follow_info->show_stream == BOTH_HOSTS) ||
(follow_info->show_stream == FROM_SERVER);
} else {
global_pos = &global_client_pos;
include_rec = (follow_info->show_stream == BOTH_HOSTS) ||
(follow_info->show_stream == FROM_CLIENT);
}
if (include_rec) {
size_t nchars = rec->data.data_len;
gchar *buffer = (gchar *)g_memdup(rec->data.data, (guint) nchars);
frs_return = follow_show(follow_info, print_line_fcn_p, buffer, nchars,
rec->is_from_server, arg, global_pos,
&server_packet_count, &client_packet_count);
g_free(buffer);
if (frs_return == FRS_PRINT_ERROR)
return frs_return;
}
}
return FRS_OK;
}
