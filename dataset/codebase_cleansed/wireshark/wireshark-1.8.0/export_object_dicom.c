static int
eo_dicom_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_,
const void *data)
{
export_object_list_t *object_list = tapdata;
const dicom_eo_t *eo_info = data;
export_object_entry_t *entry;
if (eo_info) {
entry = g_malloc(sizeof(export_object_entry_t));
entry->pkt_num = pinfo->fd->num;
entry->hostname = eo_info->hostname;
entry->content_type = eo_info->content_type;
entry->filename = g_strdup(g_path_get_basename(eo_info->filename));
entry->payload_len = eo_info->payload_len;
entry->payload_data = eo_info->payload_data;
object_list->entries = g_slist_append(object_list->entries, entry);
return 1;
} else {
return 0;
}
}
void
eo_dicom_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("dicom_eo", "DICOM", eo_dicom_packet, NULL);
}
