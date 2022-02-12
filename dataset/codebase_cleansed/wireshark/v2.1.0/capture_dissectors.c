static void
destroy_capture_dissector_table(void *data)
{
struct capture_dissector_table *table = (struct capture_dissector_table *)data;
g_hash_table_destroy(table->hash_table);
g_free(data);
}
void capture_dissector_init(void)
{
capture_dissector_tables = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, destroy_capture_dissector_table);
}
void capture_dissector_cleanup(void)
{
g_hash_table_destroy(capture_dissector_tables);
}
void register_capture_dissector_table(const char *name, const char *ui_name)
{
struct capture_dissector_table* sub_dissectors;
if(g_hash_table_lookup( capture_dissector_tables, name )) {
g_error("The capture dissector table %s (%s) is already registered - are you using a buggy plugin?", name, ui_name);
}
sub_dissectors = g_new(struct capture_dissector_table, 1);
sub_dissectors->hash_table = g_hash_table_new_full( g_direct_hash, g_direct_equal, NULL, NULL );
sub_dissectors->ui_name = ui_name;
g_hash_table_insert( capture_dissector_tables, (gpointer)name, (gpointer) sub_dissectors );
}
void register_capture_dissector(const char* name, const guint32 pattern, capture_dissector_t dissector, const int proto)
{
struct capture_dissector_table* sub_dissectors;
struct capture_dissector_handle *handle;
sub_dissectors = (struct capture_dissector_table*)g_hash_table_lookup( capture_dissector_tables, name );
g_assert(sub_dissectors != NULL);
g_assert(g_hash_table_lookup(sub_dissectors->hash_table, GUINT_TO_POINTER(pattern)) == NULL);
handle = wmem_new(wmem_epan_scope(), struct capture_dissector_handle);
handle->pattern = pattern;
handle->dissector = dissector;
handle->protocol = find_protocol_by_id(proto);
g_hash_table_insert(sub_dissectors->hash_table, GUINT_TO_POINTER(pattern), (gpointer) handle);
}
gboolean try_capture_dissector(const char* name, const guint32 pattern, const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
struct capture_dissector_table* sub_dissectors;
struct capture_dissector_handle* handle;
sub_dissectors = (struct capture_dissector_table*)g_hash_table_lookup( capture_dissector_tables, name );
if (sub_dissectors == NULL)
{
return FALSE;
}
handle = (struct capture_dissector_handle *)g_hash_table_lookup(sub_dissectors->hash_table, GUINT_TO_POINTER(pattern));
if (handle == NULL)
return FALSE;
return handle->dissector(pd, offset, len, cpinfo, pseudo_header);
}
guint32 capture_dissector_get_count(packet_counts* counts, const int proto)
{
capture_dissector_count_t* hash_count = (capture_dissector_count_t*)g_hash_table_lookup(counts->counts_hash, GUINT_TO_POINTER(proto));
if (hash_count == NULL)
return 0;
return hash_count->count;
}
void capture_dissector_increment_count(capture_packet_info_t *cpinfo, const int proto)
{
capture_dissector_count_t* hash_count = (capture_dissector_count_t*)g_hash_table_lookup(cpinfo->counts, GUINT_TO_POINTER(proto));
if (hash_count == NULL)
{
hash_count = g_new0(capture_dissector_count_t, 1);
g_hash_table_insert(cpinfo->counts, GUINT_TO_POINTER(proto), (gpointer)hash_count);
}
hash_count->count++;
}
