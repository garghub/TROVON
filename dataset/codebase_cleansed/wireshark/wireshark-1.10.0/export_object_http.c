gboolean
eo_http_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_,
const void *data)
{
export_object_list_t *object_list = (export_object_list_t *)tapdata;
const http_eo_t *eo_info = (const http_eo_t *)data;
export_object_entry_t *entry;
if(eo_info) {
entry = (export_object_entry_t *)g_malloc(sizeof(export_object_entry_t));
entry->pkt_num = pinfo->fd->num;
entry->hostname = g_strdup(eo_info->hostname);
entry->content_type = g_strdup(eo_info->content_type);
entry->filename = g_strdup(g_path_get_basename(eo_info->filename));
entry->payload_len = eo_info->payload_len;
entry->payload_data = (guint8 *)g_memdup(eo_info->payload_data,
eo_info->payload_len);
object_list_add_entry(object_list, entry);
return TRUE;
} else {
return FALSE;
}
}
