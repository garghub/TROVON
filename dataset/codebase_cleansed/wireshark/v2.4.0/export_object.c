int
register_export_object(const int proto_id, tap_packet_cb export_packet_func, export_object_gui_reset_cb reset_cb)
{
register_eo_t *table;
DISSECTOR_ASSERT(export_packet_func);
table = wmem_new(wmem_epan_scope(), register_eo_t);
table->proto_id = proto_id;
table->tap_listen_str = wmem_strdup_printf(wmem_epan_scope(), "%s_eo", proto_get_protocol_filter_name(proto_id));
table->eo_func = export_packet_func;
table->reset_cb = reset_cb;
if (registered_eo_tables == NULL)
registered_eo_tables = wmem_tree_new(wmem_epan_scope());
wmem_tree_insert_string(registered_eo_tables, proto_get_protocol_filter_name(proto_id), table, 0);
return register_tap(table->tap_listen_str);
}
int get_eo_proto_id(register_eo_t* eo)
{
if (!eo) {
return -1;
}
return eo->proto_id;
}
const char* get_eo_tap_listener_name(register_eo_t* eo)
{
return eo->tap_listen_str;
}
tap_packet_cb get_eo_packet_func(register_eo_t* eo)
{
return eo->eo_func;
}
export_object_gui_reset_cb get_eo_reset_func(register_eo_t* eo)
{
return eo->reset_cb;
}
register_eo_t* get_eo_by_name(const char* name)
{
return (register_eo_t*)wmem_tree_lookup_string(registered_eo_tables, name, 0);
}
void eo_iterate_tables(wmem_foreach_func func, gpointer user_data)
{
wmem_tree_foreach(registered_eo_tables, func, user_data);
}
static GString *eo_rename(GString *gstr, int dupn)
{
GString *gstr_tmp;
gchar *tmp_ptr;
GString *ext_str;
gstr_tmp = g_string_new("(");
g_string_append_printf (gstr_tmp, "%d)", dupn);
if ( (tmp_ptr = strrchr(gstr->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
gstr = g_string_truncate(gstr, gstr->len - ext_str->len);
if ( gstr->len >= (EXPORT_OBJECT_MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len)) )
gstr = g_string_truncate(gstr, EXPORT_OBJECT_MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len));
gstr = g_string_append(gstr, gstr_tmp->str);
gstr = g_string_append(gstr, ext_str->str);
g_string_free(ext_str, TRUE);
}
else {
if ( gstr->len >= (EXPORT_OBJECT_MAXFILELEN - strlen(gstr_tmp->str)) )
gstr = g_string_truncate(gstr, EXPORT_OBJECT_MAXFILELEN - strlen(gstr_tmp->str));
gstr = g_string_append(gstr, gstr_tmp->str);
}
g_string_free(gstr_tmp, TRUE);
return gstr;
}
GString *
eo_massage_str(const gchar *in_str, gsize maxlen, int dupn)
{
gchar *tmp_ptr;
const gchar *reject = "<>:\"/\\|?*"
"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a"
"\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14"
"\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
GString *out_str;
GString *ext_str;
out_str = g_string_new("");
while ( (tmp_ptr = strpbrk(in_str, reject)) != NULL ) {
out_str = g_string_append_len(out_str, in_str, tmp_ptr - in_str);
g_string_append_printf(out_str, "%%%02x", *tmp_ptr);
in_str = tmp_ptr + 1;
}
out_str = g_string_append(out_str, in_str);
if ( out_str->len > maxlen ) {
if ( (tmp_ptr = strrchr(out_str->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
out_str = g_string_truncate(out_str, maxlen - ext_str->len);
out_str = g_string_append(out_str, ext_str->str);
g_string_free(ext_str, TRUE);
}
else
out_str = g_string_truncate(out_str, maxlen);
}
if ( dupn != 0 )
out_str = eo_rename(out_str, dupn);
return out_str;
}
const char *
eo_ct2ext(const char *content_type)
{
return content_type;
}
void eo_free_entry(export_object_entry_t *entry)
{
g_free(entry->hostname);
g_free(entry->content_type);
g_free(entry->filename);
g_free(entry->payload_data);
g_free(entry);
}
