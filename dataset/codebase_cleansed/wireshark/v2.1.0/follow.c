static gint
insert_sorted_by_name(gconstpointer aparam, gconstpointer bparam)
{
const register_follow_t *a = (const register_follow_t *)aparam;
const register_follow_t *b = (const register_follow_t *)bparam;
return g_ascii_strcasecmp(proto_get_protocol_short_name(find_protocol_by_id(a->proto_id)), proto_get_protocol_short_name(find_protocol_by_id(b->proto_id)));
}
void register_follow_stream(const int proto_id, const char* tap_listener,
follow_conv_filter_func conv_filter, follow_index_filter_func index_filter, follow_address_filter_func address_filter,
follow_port_to_display_func port_to_display, follow_tap_func tap_handler)
{
register_follow_t *follower;
DISSECTOR_ASSERT(tap_listener);
DISSECTOR_ASSERT(conv_filter);
DISSECTOR_ASSERT(index_filter);
DISSECTOR_ASSERT(address_filter);
DISSECTOR_ASSERT(port_to_display);
DISSECTOR_ASSERT(tap_handler);
follower = g_new(register_follow_t,1);
follower->proto_id = proto_id;
follower->tap_listen_str = tap_listener;
follower->conv_filter = conv_filter;
follower->index_filter = index_filter;
follower->address_filter = address_filter;
follower->port_to_display = port_to_display;
follower->tap_handler = tap_handler;
registered_followers = g_slist_insert_sorted(registered_followers, follower, insert_sorted_by_name);
}
int get_follow_proto_id(register_follow_t* follower)
{
if (follower == NULL)
return -1;
return follower->proto_id;
}
const char* get_follow_tap_string(register_follow_t* follower)
{
if (follower == NULL)
return "";
return follower->tap_listen_str;
}
follow_conv_filter_func get_follow_conv_func(register_follow_t* follower)
{
return follower->conv_filter;
}
follow_index_filter_func get_follow_index_func(register_follow_t* follower)
{
return follower->index_filter;
}
follow_address_filter_func get_follow_address_func(register_follow_t* follower)
{
return follower->address_filter;
}
follow_port_to_display_func get_follow_port_to_display(register_follow_t* follower)
{
return follower->port_to_display;
}
follow_tap_func get_follow_tap_handler(register_follow_t* follower)
{
return follower->tap_handler;
}
register_follow_t* get_follow_by_name(const char* proto_short_name)
{
guint i, size = g_slist_length(registered_followers);
register_follow_t *follower;
GSList *slist;
for (i = 0; i < size; i++) {
slist = g_slist_nth(registered_followers, i);
follower = (register_follow_t*)slist->data;
if (strcmp(proto_short_name, proto_get_protocol_short_name(find_protocol_by_id(follower->proto_id))) == 0)
return follower;
}
return NULL;
}
void follow_iterate_followers(GFunc func, gpointer user_data)
{
g_slist_foreach(registered_followers, func, user_data);
}
gchar* follow_get_stat_tap_string(register_follow_t* follower)
{
GString *cmd_str = g_string_new("follow,");
g_string_append(cmd_str, proto_get_protocol_filter_name(follower->proto_id));
return g_string_free(cmd_str, FALSE);
}
void
follow_reset_stream(follow_info_t* info)
{
info->bytes_written[0] = info->bytes_written[1] = 0;
info->client_port = 0;
info->server_port = 0;
info->client_ip.type = FT_NONE;
info->client_ip.len = 0;
info->server_ip.type = FT_NONE;
info->server_ip.len = 0;
}
gboolean
follow_tvb_tap_listener(void *tapdata, packet_info *pinfo,
epan_dissect_t *edt _U_, const void *data)
{
follow_record_t *follow_record;
follow_info_t *follow_info = (follow_info_t *)tapdata;
tvbuff_t *next_tvb = (tvbuff_t *)data;
follow_record = g_new(follow_record_t,1);
follow_record->data = g_byte_array_sized_new(tvb_captured_length(next_tvb));
follow_record->data = g_byte_array_append(follow_record->data,
tvb_get_ptr(next_tvb, 0, -1),
tvb_captured_length(next_tvb));
follow_record->packet_num = pinfo->fd->num;
if (follow_info->client_port == 0) {
follow_info->client_port = pinfo->srcport;
copy_address(&follow_info->client_ip, &pinfo->src);
follow_info->server_port = pinfo->destport;
copy_address(&follow_info->server_ip, &pinfo->dst);
}
if (addresses_equal(&follow_info->client_ip, &pinfo->src) && follow_info->client_port == pinfo->srcport)
follow_record->is_server = FALSE;
else
follow_record->is_server = TRUE;
follow_info->bytes_written[follow_record->is_server] += follow_record->data->len;
follow_info->payload = g_list_append(follow_info->payload, follow_record);
return FALSE;
}
