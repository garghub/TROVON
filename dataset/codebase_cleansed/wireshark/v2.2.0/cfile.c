const char *
cap_file_get_interface_name(void *data, guint32 interface_id)
{
capture_file *cf = (capture_file *) data;
wtapng_iface_descriptions_t *idb_info;
wtap_block_t wtapng_if_descr = NULL;
char* interface_name;
idb_info = wtap_file_get_idb_info(cf->wth);
if (interface_id < idb_info->interface_data->len)
wtapng_if_descr = g_array_index(idb_info->interface_data, wtap_block_t, interface_id);
g_free(idb_info);
if (wtapng_if_descr) {
if (wtap_block_get_string_option_value(wtapng_if_descr, OPT_IDB_NAME, &interface_name) == WTAP_OPTTYPE_SUCCESS)
return interface_name;
if (wtap_block_get_string_option_value(wtapng_if_descr, OPT_IDB_DESCR, &interface_name) == WTAP_OPTTYPE_SUCCESS)
return interface_name;
}
return "unknown";
}
void
cap_file_init(capture_file *cf)
{
memset(cf, 0, sizeof(capture_file));
cf->snap = WTAP_MAX_PACKET_SIZE;
}
