const char *
cap_file_get_interface_name(void *data, guint32 interface_id)
{
capture_file *cf = (capture_file *) data;
wtapng_iface_descriptions_t *idb_info;
const wtapng_if_descr_t *wtapng_if_descr = NULL;
idb_info = wtap_file_get_idb_info(cf->wth);
if (interface_id < idb_info->interface_data->len)
wtapng_if_descr = &g_array_index(idb_info->interface_data, wtapng_if_descr_t, interface_id);
g_free(idb_info);
if (wtapng_if_descr) {
if (wtapng_if_descr->if_name)
return wtapng_if_descr->if_name;
else if (wtapng_if_descr->if_description)
return wtapng_if_descr->if_description;
}
return "unknown";
}
void
cap_file_init(capture_file *cf)
{
memset(cf, 0, sizeof(capture_file));
cf->snap = WTAP_MAX_PACKET_SIZE;
}
