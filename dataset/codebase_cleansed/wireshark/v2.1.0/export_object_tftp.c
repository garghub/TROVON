gboolean
eo_tftp_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_,
const void *data)
{
export_object_list_t *object_list = (export_object_list_t *)tapdata;
const tftp_eo_t *eo_info = (const tftp_eo_t *)data;
export_object_entry_t *entry;
GSList *block_iterator;
guint payload_data_offset = 0;
eo_info_dynamic_t *dynamic_info;
entry = (export_object_entry_t*)g_malloc(sizeof(export_object_entry_t));
entry->pkt_num = pinfo->num;
entry->filename = g_strdup(g_path_get_basename(eo_info->filename));
entry->payload_len = eo_info->payload_len;
entry->payload_data = (guint8 *)g_try_malloc((gsize)entry->payload_len);
for (block_iterator = eo_info->block_list; block_iterator; block_iterator = block_iterator->next) {
file_block_t *block = (file_block_t*)block_iterator->data;
memcpy(entry->payload_data + payload_data_offset,
block->data,
block->length);
payload_data_offset += block->length;
}
entry->hostname = NULL;
entry->content_type = NULL;
dynamic_info = (eo_info_dynamic_t*)g_malloc(sizeof(eo_info_dynamic_t));
dynamic_info->filename = eo_info->filename;
dynamic_info->block_list = eo_info->block_list;
s_dynamic_info_list = g_slist_append(s_dynamic_info_list, (eo_info_dynamic_t*)dynamic_info);
object_list_add_entry(object_list, entry);
return TRUE;
}
static void cleanup_tftp_eo(eo_info_dynamic_t *dynamic_info)
{
GSList *block_iterator;
g_free(dynamic_info->filename);
for (block_iterator = dynamic_info->block_list; block_iterator; block_iterator = block_iterator->next) {
file_block_t *block = (file_block_t*)(block_iterator->data);
wmem_free(NULL, block->data);
g_free(block);
}
}
void eo_tftp_cleanup(void)
{
GSList *dynamic_iterator;
for (dynamic_iterator = s_dynamic_info_list; dynamic_iterator; dynamic_iterator = dynamic_iterator->next) {
eo_info_dynamic_t *dynamic_info = (eo_info_dynamic_t*)dynamic_iterator->data;
cleanup_tftp_eo(dynamic_info);
}
s_dynamic_info_list = NULL;
}
