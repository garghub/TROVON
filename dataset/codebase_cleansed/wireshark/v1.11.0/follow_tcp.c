static void
follow_redraw(gpointer data, gpointer user_data _U_)
{
follow_load_text((follow_info_t *)data);
}
void
follow_tcp_redraw_all(void)
{
g_list_foreach(follow_infos, follow_redraw, NULL);
}
void
follow_tcp_stream_cb(GtkWidget * w _U_, gpointer data _U_)
{
GtkWidget *filter_cm;
GtkWidget *filter_te;
int tmp_fd;
gchar *follow_filter;
const gchar *previous_filter;
int filter_out_filter_len;
const char *hostname0, *hostname1;
char *port0, *port1;
gchar *server_to_client_string = NULL;
gchar *client_to_server_string = NULL;
gchar *both_directions_string = NULL;
follow_stats_t stats;
follow_info_t *follow_info;
tcp_stream_chunk sc;
size_t nchars;
gchar *data_out_filename;
char stream_window_title[256];
if (cfile.edt->pi.ipproto != IP_PROTO_TCP) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error following stream. Please make\n"
"sure you have a TCP packet selected.");
return;
}
follow_info = g_new0(follow_info_t, 1);
follow_info->follow_type = FOLLOW_TCP;
reset_tcp_reassembly();
follow_filter = build_follow_filter(&cfile.edt->pi);
if (!follow_filter) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error creating filter for this stream.\n"
"A transport or network layer header is needed");
g_free(follow_info);
return;
}
tmp_fd = create_tempfile(&data_out_filename, "follow");
follow_info->data_out_filename = g_strdup(data_out_filename);
if (tmp_fd == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not create temporary file %s: %s",
follow_info->data_out_filename, g_strerror(errno));
g_free(follow_info->data_out_filename);
g_free(follow_info);
g_free(follow_filter);
return;
}
data_out_file = fdopen(tmp_fd, "w+b");
if (data_out_file == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not create temporary file %s: %s",
follow_info->data_out_filename, g_strerror(errno));
ws_close(tmp_fd);
ws_unlink(follow_info->data_out_filename);
g_free(follow_info->data_out_filename);
g_free(follow_info);
g_free(follow_filter);
return;
}
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
follow_info->filter_te = filter_te;
previous_filter =
(const gchar *)gtk_entry_get_text(GTK_ENTRY(filter_te));
filter_out_filter_len = (int)(strlen(follow_filter) + strlen(previous_filter) + 16);
follow_info->filter_out_filter = (gchar *)g_malloc(filter_out_filter_len);
if(strlen(previous_filter)) {
g_snprintf(follow_info->filter_out_filter, filter_out_filter_len,
"%s and !(%s)", previous_filter, follow_filter);
} else {
g_snprintf(follow_info->filter_out_filter, filter_out_filter_len,
"!(%s)", follow_filter);
}
gtk_entry_set_text(GTK_ENTRY(filter_te), follow_filter);
main_filter_packets(&cfile, follow_filter, TRUE);
if (empty_tcp_stream) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The packets in the capture file for that stream have no data.");
ws_close(tmp_fd);
ws_unlink(follow_info->data_out_filename);
g_free(follow_info->data_out_filename);
g_free(follow_info->filter_out_filter);
g_free(follow_info);
return;
}
rewind(data_out_file);
nchars=fread(&sc, 1, sizeof(sc), data_out_file);
if (nchars != sizeof(sc)) {
if (ferror(data_out_file)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not read from temporary file %s: %s",
follow_info->data_out_filename, g_strerror(errno));
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Short read from temporary file %s: expected %lu, got %lu",
follow_info->data_out_filename,
(unsigned long)sizeof(sc),
(unsigned long)nchars);
}
ws_close(tmp_fd);
ws_unlink(follow_info->data_out_filename);
g_free(follow_info->data_out_filename);
g_free(follow_info->filter_out_filter);
g_free(follow_info);
return;
}
fclose(data_out_file);
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
follow_info->is_ipv6 = stats.is_ipv6;
port0 = get_tcp_port(stats.port[0]);
port1 = get_tcp_port(stats.port[1]);
if(sc.src_port == stats.port[0]) {
server_to_client_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname0, port0,
hostname1, port1,
stats.bytes_written[0]);
} else {
server_to_client_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname1, port1,
hostname0,port0,
stats.bytes_written[0]);
}
if(sc.src_port == stats.port[1]) {
client_to_server_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname0, port0,
hostname1, port1,
stats.bytes_written[1]);
} else {
client_to_server_string =
g_strdup_printf("%s:%s " UTF8_RIGHTWARDS_ARROW " %s:%s (%u bytes)",
hostname1, port1,
hostname0, port0,
stats.bytes_written[1]);
}
both_directions_string = g_strdup_printf("Entire conversation (%u bytes)", stats.bytes_written[0] + stats.bytes_written[1]);
g_snprintf(stream_window_title, 256, "Follow TCP Stream (%s)", follow_filter);
follow_stream(stream_window_title, follow_info, both_directions_string,
server_to_client_string, client_to_server_string);
g_free(follow_filter);
g_free(both_directions_string);
g_free(server_to_client_string);
g_free(client_to_server_string);
data_out_file = NULL;
}
frs_return_t
follow_read_tcp_stream(follow_info_t *follow_info,
gboolean (*print_line_fcn_p)(char *, size_t, gboolean, void *),
void *arg)
{
tcp_stream_chunk sc;
size_t bcount;
size_t bytes_read;
int iplen;
guint8 client_addr[MAX_IPADDR_LEN];
guint16 client_port = 0;
gboolean is_server;
guint32 global_client_pos = 0, global_server_pos = 0;
guint32 server_packet_count = 0;
guint32 client_packet_count = 0;
guint32 *global_pos;
gboolean skip;
char buffer[FLT_BUF_SIZE+1];
size_t nchars;
frs_return_t frs_return;
iplen = (follow_info->is_ipv6) ? 16 : 4;
data_out_file = ws_fopen(follow_info->data_out_filename, "rb");
if (data_out_file == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open temporary file %s: %s", follow_info->data_out_filename,
g_strerror(errno));
return FRS_OPEN_ERROR;
}
while ((nchars=fread(&sc, 1, sizeof(sc), data_out_file))) {
if (nchars != sizeof(sc)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Short read from temporary file %s: expected %lu, got %lu",
follow_info->data_out_filename,
(unsigned long)sizeof(sc),
(unsigned long)nchars);
fclose(data_out_file);
data_out_file = NULL;
return FRS_READ_ERROR;
}
if (client_port == 0) {
memcpy(client_addr, sc.src_addr, iplen);
client_port = sc.src_port;
}
skip = FALSE;
if (memcmp(client_addr, sc.src_addr, iplen) == 0 &&
client_port == sc.src_port) {
is_server = FALSE;
global_pos = &global_client_pos;
if (follow_info->show_stream == FROM_SERVER) {
skip = TRUE;
}
}
else {
is_server = TRUE;
global_pos = &global_server_pos;
if (follow_info->show_stream == FROM_CLIENT) {
skip = TRUE;
}
}
bytes_read = 0;
while (bytes_read < sc.dlen) {
bcount = ((sc.dlen-bytes_read) < FLT_BUF_SIZE) ? (sc.dlen-bytes_read) : FLT_BUF_SIZE;
nchars = fread(buffer, 1, bcount, data_out_file);
if (nchars == 0)
break;
bytes_read += nchars;
if (!skip) {
frs_return = follow_show(follow_info, print_line_fcn_p, buffer,
nchars, is_server, arg, global_pos,
&server_packet_count,
&client_packet_count);
if(frs_return == FRS_PRINT_ERROR) {
fclose(data_out_file);
data_out_file = NULL;
return frs_return;
}
}
}
}
if (ferror(data_out_file)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error reading temporary file %s: %s", follow_info->data_out_filename,
g_strerror(errno));
fclose(data_out_file);
data_out_file = NULL;
return FRS_READ_ERROR;
}
fclose(data_out_file);
data_out_file = NULL;
return FRS_OK;
}
