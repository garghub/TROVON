static guint
circuit_hash(gconstpointer v)
{
const circuit_key *key = (const circuit_key *)v;
return key->ctype ^ key->circuit_id;
}
static gint
circuit_match(gconstpointer v, gconstpointer w)
{
const circuit_key *v1 = (const circuit_key *)v;
const circuit_key *v2 = (const circuit_key *)w;
return v1->ctype == v2->ctype && v1->circuit_id == v2->circuit_id;
}
void
circuit_cleanup(void)
{
if (circuit_hashtable != NULL)
g_hash_table_destroy(circuit_hashtable);
circuit_hashtable = NULL;
}
void
circuit_init(void)
{
g_assert(circuit_hashtable == NULL);
circuit_hashtable = g_hash_table_new(circuit_hash, circuit_match);
new_index = 0;
}
circuit_t *
circuit_new(circuit_type ctype, guint32 circuit_id, guint32 first_frame)
{
circuit_t *circuit, *old_circuit;
circuit_key *new_key;
new_key = wmem_new(wmem_file_scope(), struct circuit_key);
new_key->ctype = ctype;
new_key->circuit_id = circuit_id;
circuit = wmem_new(wmem_file_scope(), circuit_t);
circuit->next = NULL;
circuit->first_frame = first_frame;
circuit->last_frame = 0;
circuit->circuit_index = new_index;
circuit->data_list = NULL;
circuit->dissector_handle = NULL;
circuit->key_ptr = new_key;
new_index++;
old_circuit = (circuit_t *)g_hash_table_lookup(circuit_hashtable, new_key);
if (old_circuit != NULL) {
while (old_circuit->next != NULL)
old_circuit = old_circuit->next;
if (old_circuit->last_frame == 0)
old_circuit->last_frame = first_frame - 1;
old_circuit->next = circuit;
} else {
g_hash_table_insert(circuit_hashtable, new_key, circuit);
}
return circuit;
}
circuit_t *
find_circuit(circuit_type ctype, guint32 circuit_id, guint32 frame)
{
circuit_key key;
circuit_t *circuit;
key.ctype = ctype;
key.circuit_id = circuit_id;
for (circuit = (circuit_t *)g_hash_table_lookup(circuit_hashtable, &key);
circuit != NULL; circuit = circuit->next) {
if ((circuit->first_frame == 0 || circuit->first_frame <= frame)
&& (circuit->last_frame == 0 || circuit->last_frame >= frame))
break;
}
return circuit;
}
void
close_circuit(circuit_t *circuit, guint32 last_frame)
{
if (circuit->last_frame == 0)
circuit->last_frame = last_frame;
}
static gint
p_compare(gconstpointer a, gconstpointer b)
{
const circuit_proto_data *ap = (const circuit_proto_data *)a;
const circuit_proto_data *bp = (const circuit_proto_data *)b;
if (ap->proto > bp->proto)
return 1;
else if (ap->proto == bp->proto)
return 0;
else
return -1;
}
void
circuit_add_proto_data(circuit_t *conv, int proto, void *proto_data)
{
circuit_proto_data *p1 = wmem_new(wmem_file_scope(), circuit_proto_data);
p1->proto = proto;
p1->proto_data = proto_data;
conv->data_list = g_slist_insert_sorted(conv->data_list, (gpointer *)p1,
p_compare);
}
void *
circuit_get_proto_data(circuit_t *conv, int proto)
{
circuit_proto_data temp, *p1;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(conv->data_list, (gpointer *)&temp,
p_compare);
if (item != NULL) {
p1 = (circuit_proto_data *)item->data;
return p1->proto_data;
}
return NULL;
}
void
circuit_delete_proto_data(circuit_t *conv, int proto)
{
circuit_proto_data temp;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(conv->data_list, (gpointer *)&temp,
p_compare);
if (item != NULL)
conv->data_list = g_slist_remove(conv->data_list, item);
}
void
circuit_set_dissector(circuit_t *circuit, dissector_handle_t handle)
{
circuit->dissector_handle = handle;
}
dissector_handle_t
circuit_get_dissector(circuit_t *circuit)
{
return circuit->dissector_handle;
}
gboolean
try_circuit_dissector(circuit_type ctype, guint32 circuit_id, guint32 frame,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
circuit_t *circuit;
circuit = find_circuit(ctype, circuit_id, frame);
if (circuit != NULL) {
if (circuit->dissector_handle == NULL)
return FALSE;
call_dissector_with_data(circuit->dissector_handle, tvb, pinfo,
tree, data);
return TRUE;
}
return FALSE;
}
