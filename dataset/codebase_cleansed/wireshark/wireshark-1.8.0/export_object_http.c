static int
eo_http_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_,
const void *data)
{
export_object_list_t *object_list = tapdata;
const http_eo_t *eo_info = data;
export_object_entry_t *entry;
if(eo_info) {
entry = g_malloc(sizeof(export_object_entry_t));
entry->pkt_num = pinfo->fd->num;
entry->hostname = g_strdup(eo_info->hostname);
entry->content_type = g_strdup(eo_info->content_type);
entry->filename = g_strdup(g_path_get_basename(eo_info->filename));
entry->payload_len = eo_info->payload_len;
entry->payload_data = g_memdup(eo_info->payload_data,
eo_info->payload_len);
object_list->entries =
g_slist_append(object_list->entries, entry);
return 1;
} else {
return 0;
}
}
void
eo_http_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("http_eo", "HTTP", eo_http_packet, NULL);
}
