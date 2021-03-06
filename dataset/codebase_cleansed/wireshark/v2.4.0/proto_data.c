static gint
p_compare(gconstpointer a, gconstpointer b)
{
const proto_data_t *ap = (const proto_data_t *)a;
const proto_data_t *bp = (const proto_data_t *)b;
if (ap -> proto > bp -> proto) {
return 1;
} else if (ap -> proto == bp -> proto) {
if (ap->key > bp->key){
return 1;
} else if (ap -> key == bp -> key) {
return 0;
}
return -1;
} else {
return -1;
}
}
void
p_add_proto_data(wmem_allocator_t *tmp_scope, struct _packet_info* pinfo, int proto, guint32 key, void *proto_data)
{
proto_data_t *p1;
GSList **proto_list;
wmem_allocator_t *scope;
if (tmp_scope == pinfo->pool) {
scope = tmp_scope;
proto_list = &pinfo->proto_data;
} else if (tmp_scope == wmem_file_scope()) {
scope = wmem_file_scope();
proto_list = &pinfo->fd->pfd;
} else {
DISSECTOR_ASSERT(!"invalid wmem scope");
}
p1 = (proto_data_t *)wmem_alloc(scope, sizeof(proto_data_t));
p1->proto = proto;
p1->key = key;
p1->proto_data = proto_data;
*proto_list = g_slist_prepend(*proto_list, p1);
}
void *
p_get_proto_data(wmem_allocator_t *scope, struct _packet_info* pinfo, int proto, guint32 key)
{
proto_data_t temp, *p1;
GSList *item;
temp.proto = proto;
temp.key = key;
temp.proto_data = NULL;
if (scope == pinfo->pool) {
item = g_slist_find_custom(pinfo->proto_data, &temp, p_compare);
} else if (scope == wmem_file_scope()) {
item = g_slist_find_custom(pinfo->fd->pfd, &temp, p_compare);
} else {
DISSECTOR_ASSERT(!"invalid wmem scope");
}
if (item) {
p1 = (proto_data_t *)item->data;
return p1->proto_data;
}
return NULL;
}
void
p_remove_proto_data(wmem_allocator_t *scope, struct _packet_info* pinfo, int proto, guint32 key)
{
proto_data_t temp;
GSList *item;
GSList **proto_list;
temp.proto = proto;
temp.key = key;
temp.proto_data = NULL;
if (scope == pinfo->pool) {
item = g_slist_find_custom(pinfo->fd->pfd, &temp, p_compare);
proto_list = &pinfo->proto_data;
} else if (scope == wmem_file_scope()) {
item = g_slist_find_custom(pinfo->fd->pfd, &temp, p_compare);
proto_list = &pinfo->fd->pfd;
} else {
DISSECTOR_ASSERT(!"invalid wmem scope");
}
if (item) {
*proto_list = g_slist_remove(*proto_list, item->data);
}
}
gchar *
p_get_proto_name_and_key(wmem_allocator_t *scope, struct _packet_info* pinfo, guint pfd_index){
proto_data_t *temp;
if (scope == pinfo->pool) {
temp = (proto_data_t *)g_slist_nth_data(pinfo->proto_data, pfd_index);
} else if (scope == wmem_file_scope()) {
temp = (proto_data_t *)g_slist_nth_data(pinfo->fd->pfd, pfd_index);
} else {
DISSECTOR_ASSERT(!"invalid wmem scope");
}
return wmem_strdup_printf(wmem_packet_scope(),"[%s, key %u]",proto_get_protocol_name(temp->proto), temp->key);
}
