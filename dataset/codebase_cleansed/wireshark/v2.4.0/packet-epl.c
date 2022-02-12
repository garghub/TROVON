const struct
epl_datatype *epl_type_to_hf(const char *name)
{
const struct epl_datatype *entry;
for (entry = epl_datatype; entry->name; entry++)
{
if (strcmp(name, entry->name) == 0)
return entry;
}
return NULL;
}
static guint
epl_address_hash(gconstpointer a)
{
return add_address_to_hash(0, (const address*)a);
}
static gboolean
epl_address_equal(gconstpointer a, gconstpointer b)
{
return addresses_equal((const address*)a, (const address*)b);
}
static struct object_mapping *
get_object_mappings(wmem_array_t *arr, guint *len)
{
*len = wmem_array_get_count(arr);
return (struct object_mapping*)wmem_array_get_raw(arr);
}
static int
object_mapping_cmp(const void *_a, const void *_b)
{
const struct object_mapping *a = (const struct object_mapping*)_a;
const struct object_mapping *b = (const struct object_mapping*)_b;
if (a->bit_offset < b->bit_offset) return -1;
if (a->bit_offset > b->bit_offset) return +1;
return 0;
}
static gboolean
object_mapping_eq(struct object_mapping *a, struct object_mapping *b)
{
return a->pdo.idx == b->pdo.idx
&& a->pdo.subindex == b->pdo.subindex
&& a->frame.first == b->frame.first
&& a->param.idx == b->param.idx
&& a->param.subindex == b->param.subindex;
}
static guint
add_object_mapping(wmem_array_t *arr, struct object_mapping *mapping)
{
guint i, len;
struct object_mapping *old = get_object_mappings(arr, &len);
for (i = 0; i < len; i++)
{
if (object_mapping_eq(&old[i], mapping))
return len;
if (old[i].frame.first < mapping->frame.first
&& (CHECK_OVERLAP_LENGTH(old[i].bit_offset, old[i].no_of_bits, mapping->bit_offset, mapping->no_of_bits)
|| (old[i].param.idx == mapping->param.idx && old[i].param.subindex == mapping->param.subindex
&& CHECK_OVERLAP_ENDS(old[i].frame.first, old[i].frame.last, mapping->frame.first, mapping->frame.last))))
{
old[i].frame.last = mapping->frame.first;
}
}
wmem_array_append(arr, mapping, 1);
wmem_array_sort(arr, object_mapping_cmp);
return len + 1;
}
static gboolean
profile_del_cb(wmem_allocator_t *pool _U_, wmem_cb_event_t event _U_, void *_profile)
{
struct profile *profile = (struct profile*)_profile;
if (profile->parent_map)
wmem_map_remove(profile->parent_map, profile->data);
wmem_destroy_allocator(profile->scope);
return FALSE;
}
static void
profile_del(struct profile *profile)
{
if (!profile) return;
wmem_unregister_callback(profile->parent_scope, profile->cb_id);
profile_del_cb(NULL, WMEM_CB_DESTROY_EVENT, profile);
}
static struct profile *
profile_new(wmem_allocator_t *parent_pool)
{
wmem_allocator_t *pool;
struct profile *profile;
pool = wmem_allocator_new(WMEM_ALLOCATOR_SIMPLE);
profile = wmem_new0(pool, struct profile);
profile->cb_id = wmem_register_callback(parent_pool, profile_del_cb, profile);
profile->scope = pool;
profile->parent_scope = parent_pool;
profile->parent_map = NULL;
profile->objects = wmem_map_new(pool, g_direct_hash, g_direct_equal);
profile->name = NULL;
profile->path = NULL;
profile->RPDO = wmem_array_new(pool, sizeof (struct object_mapping));
profile->TPDO = wmem_array_new(pool, sizeof (struct object_mapping));
profile->next = NULL;
return profile;
}
struct object *
epl_profile_object_add(struct profile *profile, guint16 idx)
{
struct object *object = wmem_new0(profile->scope, struct object);
object->info.idx = idx;
wmem_map_insert(profile->objects, GUINT_TO_POINTER(object->info.idx), object);
return object;
}
struct object *
epl_profile_object_lookup_or_add(struct profile *profile, guint16 idx)
{
struct object *obj = object_lookup(profile, idx);
return obj ? obj : epl_profile_object_add(profile, idx);
}
gboolean
epl_profile_object_mapping_add(struct profile *profile, guint16 idx, guint8 subindex, guint64 mapping)
{
wmem_array_t *mappings;
tvbuff_t *tvb;
guint64 mapping_le;
if (!use_xdc_mappings)
return FALSE;
if(idx == EPL_SOD_PDO_RX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
mappings = profile->RPDO;
else if (idx == EPL_SOD_PDO_TX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
mappings = profile->TPDO;
else
return FALSE;
mapping_le = GUINT64_TO_LE(mapping);
tvb = tvb_new_real_data((guint8*)&mapping_le, sizeof mapping_le, sizeof mapping_le);
return dissect_object_mapping(profile, mappings, NULL, tvb, 0, 0, idx, subindex) == EPL_OBJECT_MAPPING_SIZE;
}
gboolean
epl_profile_object_mappings_update(struct profile *profile)
{
gboolean updated_any = FALSE;
struct object_mapping *mappings;
wmem_array_t *PDOs[3], **PDO;
if (!use_xdc_mappings)
return FALSE;
PDOs[0] = profile->RPDO;
PDOs[1] = profile->TPDO;
PDOs[2] = NULL;
for (PDO = PDOs; *PDO; PDO++)
{
guint i, len;
len = wmem_array_get_count(*PDO);
mappings = (struct object_mapping*)wmem_array_get_raw(*PDO);
for (i = 0; i < len; i++)
{
struct object_mapping *map = &mappings[i];
struct object *mapping_obj;
struct subobject *mapping_subobj;
if (!(mapping_obj = object_lookup(profile, map->pdo.idx)))
continue;
map->info = &mapping_obj->info;
map->index_name = map->info->name;
updated_any = TRUE;
if (!(mapping_subobj = subobject_lookup(mapping_obj, map->pdo.subindex)))
continue;
map->info = &mapping_subobj->info;
}
}
return updated_any;
}
static struct read_req *
convo_read_req_get(struct epl_convo *convo, packet_info *pinfo, guint8 SendSequenceNumber)
{
guint i;
guint32 seq_p_key = (ETHERTYPE_EPL_V2 << 16) | convo->seq_send;
struct read_req *req = (struct read_req*)p_get_proto_data(wmem_file_scope(), pinfo, proto_epl, seq_p_key);
if (req)
return req;
for (i = 0; i < array_length(convo->read_reqs); i++)
{
if(convo->read_reqs[i].sendsequence == SendSequenceNumber)
{
req = wmem_new(wmem_file_scope(), struct read_req);
*req = convo->read_reqs[i];
p_add_proto_data(wmem_file_scope(), pinfo, proto_epl, seq_p_key, req);
return req;
}
}
return NULL;
}
static struct read_req *
convo_read_req_set(struct epl_convo *convo, guint8 SendSequenceNumber)
{
struct read_req *slot = &convo->read_reqs[convo->next_read_req++];
convo->next_read_req %= array_length(convo->read_reqs);
slot->sendsequence = SendSequenceNumber;
return slot;
}
static int
dissect_epl_pdo(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, guint offset, guint len, guint8 msgType)
{
wmem_array_t *mapping = msgType == EPL_PRES ? convo->TPDO : convo->RPDO;
tvbuff_t *payload_tvb;
guint rem_len, payload_len, payload_len_bits;
heur_dtbl_entry_t *hdtbl_entry = NULL;
proto_item *item;
guint i, maps_count;
guint off = 0;
struct object_mapping *mappings = get_object_mappings(mapping, &maps_count);
if (len <= 0)
return offset;
rem_len = tvb_captured_length_remaining(tvb, offset);
payload_tvb = tvb_new_subset_length(tvb, offset, MIN(len, rem_len));
payload_len = tvb_captured_length_remaining(payload_tvb, 0);
payload_len_bits = payload_len * 8;
if ( payload_len < len )
{
item = proto_tree_add_uint(epl_tree, hf_epl_payload_real, tvb, offset, payload_len, payload_len);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_real_length_differs );
}
if ( dissector_try_heuristic(heur_epl_data_subdissector_list, payload_tvb, pinfo, epl_tree, &hdtbl_entry, &msgType))
return offset + payload_len;
for (i = 0; i < maps_count; i++)
{
proto_tree *pdo_tree;
struct object_mapping *map = &mappings[i];
guint willbe_offset_bits = map->bit_offset + map->no_of_bits;
if (!(map->frame.first < pinfo->num && pinfo->num < map->frame.last))
continue;
if (willbe_offset_bits > payload_len_bits)
break;
item = proto_tree_add_string_format(epl_tree, hf_epl_pdo, payload_tvb, 0, 0, "", "%s", map->title);
pdo_tree = proto_item_add_subtree(item, map->ett);
item = proto_tree_add_uint_format_value(pdo_tree, hf_epl_pdo_index, payload_tvb, 0, 0, map->pdo.idx, "%04X", map->pdo.idx);
PROTO_ITEM_SET_GENERATED(item);
if (map->info)
proto_item_append_text (item, " (%s)", map->index_name);
item = proto_tree_add_uint_format_value(pdo_tree, hf_epl_pdo_subindex, payload_tvb, 0, 0, map->pdo.subindex, "%02X", map->pdo.subindex);
PROTO_ITEM_SET_GENERATED(item);
if (map->info && map->info->name != map->index_name)
proto_item_append_text (item, " (%s)", map->info->name);
if (show_pdo_meta_info)
{
proto_tree *meta_tree;
proto_item *meta_item = proto_tree_add_item(pdo_tree, hf_epl_od_meta, tvb, offset, 0, ENC_NA);
meta_tree = proto_item_add_subtree(meta_item, ett_epl_pdo_meta);
proto_tree_add_uint(meta_tree, hf_epl_od_meta_mapping_index, tvb, 0, 0, map->param.idx);
proto_tree_add_uint(meta_tree, hf_epl_od_meta_mapping_subindex, tvb, 0, 0, map->param.subindex);
proto_tree_add_uint(meta_tree, hf_epl_od_meta_lifetime_start, tvb, 0, 0, map->frame.first);
if (map->frame.last != G_MAXUINT32)
proto_tree_add_uint(meta_tree, hf_epl_od_meta_lifetime_end, tvb, 0, 0, map->frame.last);
item = proto_tree_add_uint(meta_tree, hf_epl_od_meta_offset, tvb, 0, 0, map->bit_offset);
proto_item_append_text (item, " bits");
item = proto_tree_add_uint(meta_tree, hf_epl_od_meta_length, tvb, 0, 0, map->no_of_bits);
proto_item_append_text (item, " bits");
PROTO_ITEM_SET_GENERATED(meta_item);
}
dissect_epl_payload(
pdo_tree,
tvb_new_octet_aligned(payload_tvb, map->bit_offset, map->no_of_bits),
pinfo, 0, map->no_of_bits / 8, map->info ? map->info->type : NULL, msgType
);
payload_len -= map->no_of_bits / 8;
off = willbe_offset_bits / 8;
}
if (tvb_captured_length_remaining(payload_tvb, off))
{
return dissect_epl_payload(epl_tree, payload_tvb, pinfo, off, payload_len, NULL, msgType);
}
return offset + payload_len;
}
static struct epl_convo *
epl_get_convo(packet_info *pinfo, int opts)
{
struct epl_convo *convo;
conversation_t * epan_convo;
guint32 node_port;
address *node_addr = &epl_placeholder_mac;
address *node_dl_addr = &epl_placeholder_mac;
if (opts & CONVO_FOR_REQUEST)
{
node_port = pinfo->destport;
#if 0
if (pinfo->dst.type == AT_IPv4 || pinfo->dst.type == AT_ETHER)
node_addr = &pinfo->dst;
#endif
if (pinfo->dl_dst.type == AT_ETHER)
node_dl_addr = &pinfo->dl_dst;
}
else
{
node_port = pinfo->srcport;
#if 0
if (pinfo->src.type == AT_IPv4 || pinfo->src.type == AT_ETHER)
node_addr = &pinfo->src;
#endif
if (pinfo->dl_src.type == AT_ETHER)
node_dl_addr = &pinfo->dl_src;
}
node_addr = &epl_placeholder_mac;
if ((epan_convo = find_conversation(pinfo->num, node_addr, node_addr,
pinfo->ptype, node_port, node_port, NO_ADDR_B|NO_PORT_B)))
{
if ((opts & CONVO_ALWAYS_CREATE) && epan_convo->setup_frame != pinfo->num)
goto new_convo_creation;
if (pinfo->num > epan_convo->last_frame)
epan_convo->last_frame = pinfo->num;
}
else
{
new_convo_creation:
epan_convo = conversation_new(pinfo->num, node_addr, node_addr,
pinfo->ptype, node_port, node_port, NO_ADDR2|NO_PORT2);
}
convo = (struct epl_convo*)conversation_get_proto_data(epan_convo, proto_epl);
if (convo == NULL)
{
convo = wmem_new0(wmem_file_scope(), struct epl_convo);
convo->CN = (guint8)node_port;
convo->generation = current_convo_generation;
convo->TPDO = wmem_array_new(pdo_mapping_scope, sizeof (struct object_mapping));
convo->RPDO = wmem_array_new(pdo_mapping_scope, sizeof (struct object_mapping));
convo->profile = (struct profile*)wmem_map_lookup(epl_profiles_by_address, node_dl_addr);
if (!convo->profile)
convo->profile = (struct profile*)wmem_map_lookup(epl_profiles_by_nodeid, GUINT_TO_POINTER(convo->CN));
if (!convo->profile)
convo->profile = epl_default_profile;
convo->seq_send = 0x00;
conversation_add_proto_data(epan_convo, proto_epl, (void *)convo);
}
if (convo->generation != current_convo_generation)
{
convo->TPDO = wmem_array_new(pdo_mapping_scope, sizeof (struct object_mapping));
convo->RPDO = wmem_array_new(pdo_mapping_scope, sizeof (struct object_mapping));
convo->generation = current_convo_generation;
}
return convo;
}
static gboolean
epl_update_convo_cn_profile(struct epl_convo *convo)
{
struct profile *candidate;
if ((candidate = (struct profile*)wmem_map_lookup(epl_profiles_by_device, GUINT_TO_POINTER(convo->device_type))))
{
struct profile *iter = candidate;
do {
if ((iter->vendor_id == 0 && convo->product_code == 0 && !candidate->vendor_id)
|| (iter->vendor_id == convo->vendor_id && !candidate->product_code)
|| (iter->vendor_id == convo->vendor_id && iter->product_code == convo->product_code))
{
candidate = iter;
}
} while ((iter = iter->next));
convo->profile = candidate;
if (!wmem_array_get_count(convo->RPDO))
{
wmem_array_append(convo->RPDO,
wmem_array_get_raw(candidate->RPDO),
wmem_array_get_count(candidate->RPDO)
);
}
if (!wmem_array_get_count(convo->TPDO))
{
wmem_array_append(convo->TPDO,
wmem_array_get_raw(candidate->TPDO),
wmem_array_get_count(candidate->TPDO)
);
}
return TRUE;
}
return FALSE;
}
static struct object *
object_lookup(struct profile *profile, guint16 idx)
{
if (profile == NULL)
return NULL;
return (struct object*)wmem_map_lookup(profile->objects, GUINT_TO_POINTER(idx));
}
static struct subobject *
subobject_lookup(struct object *obj, guint8 subindex)
{
if (!obj || !obj->subindices) return NULL;
return (struct subobject*)epl_wmem_iarray_find(obj->subindices, subindex);
}
static guint
epl_duplication_hash(gconstpointer k)
{
const duplication_key *key = (const duplication_key*)k;
guint hash;
hash = ((key->src)<<24) | ((key->dest)<<16)|
((key->seq_recv)<<8)|(key->seq_send);
return hash;
}
static gint
epl_duplication_equal(gconstpointer k1, gconstpointer k2)
{
const duplication_key *key1 = (const duplication_key*)k1;
const duplication_key *key2 = (const duplication_key*)k2;
gint hash;
hash = (key1->src == key2->src)&&(key1->dest == key2->dest)&&
(key1->seq_recv == key2->seq_recv)&&(key1->seq_send == key2->seq_send);
return hash;
}
static void
free_key(gpointer ptr)
{
duplication_key *key = (duplication_key *)ptr;
if(key)
g_slice_free(duplication_key, key);
}
static void
epl_duplication_remove(GHashTable* table, guint8 src, guint8 dest)
{
GHashTableIter iter;
gpointer pkey;
duplication_key *key;
g_hash_table_iter_init(&iter, table);
while(g_hash_table_iter_next(&iter, &pkey, NULL))
{
key = (duplication_key *)pkey;
if((src == key->src) && (dest == key->dest))
{
g_hash_table_iter_remove(&iter);
}
}
}
static void
epl_duplication_insert(GHashTable* table, gpointer ptr, guint32 frame)
{
duplication_data *data = NULL;
duplication_key *key = NULL;
gpointer pdata;
if(g_hash_table_lookup_extended(table, ptr, NULL, &pdata))
{
data = (duplication_data *)pdata;
data->frame = frame;
}
else
{
key = (duplication_key *)wmem_memdup(wmem_file_scope(), ptr,sizeof(duplication_key));
data = (duplication_data *)wmem_alloc0(wmem_file_scope(), sizeof(duplication_data));
data->frame = frame;
g_hash_table_insert(table,(gpointer)key, data);
}
}
static gpointer
epl_duplication_key(guint8 src, guint8 dest, guint8 seq_recv, guint8 seq_send)
{
duplication_key *key = g_slice_new(duplication_key);
key->src = src;
key->dest = dest;
key->seq_recv = seq_recv;
key->seq_send = seq_send;
return (gpointer)key;
}
static guint32
epl_duplication_get(GHashTable* table, gpointer ptr)
{
duplication_data *data = NULL;
gpointer pdata;
if(g_hash_table_lookup_extended(table, ptr, NULL, &pdata))
{
data = (duplication_data *)pdata;
if(data->frame == 0x00)
return 0x00;
}
if(data != NULL)
return data->frame;
else
return 0x00;
}
static void
setup_dissector(void)
{
epl_duplication_table = g_hash_table_new(epl_duplication_hash, epl_duplication_equal);
memset(&epl_asnd_sdo_reassembly_write, 0, sizeof(epl_sdo_reassembly));
memset(&epl_asnd_sdo_reassembly_read, 0, sizeof(epl_sdo_reassembly));
pdo_mapping_scope = wmem_allocator_new(WMEM_ALLOCATOR_SIMPLE);
}
static void
cleanup_dissector(void)
{
wmem_destroy_allocator(pdo_mapping_scope);
pdo_mapping_scope = NULL;
g_hash_table_destroy(epl_duplication_table);
count = 0;
ct = 0;
first_read = TRUE;
first_write = TRUE;
}
static guint16
epl_get_sequence_nr(packet_info *pinfo)
{
guint16 seqnum = 0x00;
gpointer data = NULL;
if ( ( data = p_get_proto_data ( wmem_file_scope(), pinfo, proto_epl, ETHERTYPE_EPL_V2 ) ) == NULL )
p_add_proto_data ( wmem_file_scope(), pinfo, proto_epl, ETHERTYPE_EPL_V2, GUINT_TO_POINTER((guint)seqnum) );
else
seqnum = GPOINTER_TO_UINT(data);
return seqnum;
}
static void
epl_set_sequence_nr(packet_info *pinfo, guint16 seqnum)
{
if ( p_get_proto_data ( wmem_file_scope(), pinfo, proto_epl, ETHERTYPE_EPL_V2 ) != NULL )
p_remove_proto_data( wmem_file_scope(), pinfo, proto_epl, ETHERTYPE_EPL_V2 );
p_add_proto_data ( wmem_file_scope(), pinfo, proto_epl, ETHERTYPE_EPL_V2, GUINT_TO_POINTER((guint)seqnum) );
}
static void
elp_version( gchar *result, guint32 version )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%d", hi_nibble(version), lo_nibble(version));
}
static int
dissect_eplpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean udpencap)
{
guint8 epl_mtyp;
const gchar *src_str, *dest_str;
proto_item *ti;
proto_tree *epl_tree = NULL, *epl_src_item, *epl_dest_item;
gint offset = 0, size = 0;
heur_dtbl_entry_t *hdtbl_entry;
struct epl_convo *convo;
if (tvb_reported_length(tvb) < 3)
{
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, udpencap ? "POWERLINK/UDP" : "POWERLINK");
epl_mtyp = tvb_get_guint8(tvb, EPL_MTYP_OFFSET) & 0x7F;
if (dissector_try_heuristic(heur_epl_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, &epl_mtyp))
return TRUE;
pinfo->ptype = PT_NONE;
if (udpencap)
{
if (pinfo->net_dst.type == AT_IPv4)
pinfo->destport = ((guint8*)pinfo->net_dst.data)[3];
if (pinfo->net_src.type == AT_IPv4)
pinfo->srcport = ((guint8*)pinfo->net_src.data)[3];
}
else
{
pinfo->destport = tvb_get_guint8(tvb, EPL_DEST_OFFSET);
pinfo->srcport = tvb_get_guint8(tvb, EPL_SRC_OFFSET);
}
epl_segmentation.dest = pinfo->destport;
dest_str = decode_epl_address(pinfo->destport);
epl_segmentation.src = pinfo->srcport;
src_str = decode_epl_address(pinfo->srcport);
col_clear(pinfo->cinfo, COL_INFO);
switch (epl_mtyp)
{
case EPL_SOC:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d SoC ", pinfo->srcport, pinfo->destport);
break;
case EPL_PREQ:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d PReq ", pinfo->srcport, pinfo->destport);
break;
case EPL_PRES:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d PRes ", pinfo->srcport, pinfo->destport);
break;
case EPL_SOA:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d SoA ", pinfo->srcport, pinfo->destport);
break;
case EPL_ASND:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d ASnd ", pinfo->srcport, pinfo->destport);
break;
case EPL_AINV:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d AInv ", pinfo->srcport, pinfo->destport);
break;
case EPL_AMNI:
col_add_fstr(pinfo->cinfo, COL_INFO, "%3d->%3d AMNI ", pinfo->srcport, pinfo->destport);
break;
default:
return FALSE;
}
if (tree)
{
ti = proto_tree_add_item(tree, proto_epl, tvb, 0, -1, ENC_NA);
epl_tree = proto_item_add_subtree(ti, ett_epl);
proto_tree_add_item(epl_tree,
hf_epl_mtyp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
if (tree && !udpencap)
{
epl_dest_item = proto_tree_add_item(epl_tree, hf_epl_node, tvb, offset, 1, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(epl_dest_item);
epl_dest_item = proto_tree_add_item(epl_tree, hf_epl_dest, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text (epl_dest_item, "%s", dest_str);
offset += 1;
epl_src_item = proto_tree_add_item(epl_tree, hf_epl_node, tvb, offset, 1, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(epl_src_item);
epl_src_item = proto_tree_add_item(epl_tree, hf_epl_src, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text (epl_src_item, "%s", src_str);
offset += 1;
}
else
{
offset += 2;
}
switch (epl_mtyp)
{
case EPL_SOC:
offset = dissect_epl_soc(epl_tree, tvb, pinfo, offset);
break;
case EPL_PREQ:
convo = epl_get_convo(pinfo, CONVO_FOR_REQUEST);
offset = dissect_epl_preq(convo, epl_tree, tvb, pinfo, offset);
break;
case EPL_PRES:
convo = epl_get_convo(pinfo, CONVO_FOR_RESPONSE);
offset = dissect_epl_pres(convo, epl_tree, tvb, pinfo, offset);
break;
case EPL_SOA:
offset = dissect_epl_soa(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND:
offset = dissect_epl_asnd(epl_tree, tvb, pinfo, offset);
break;
case EPL_AINV:
offset = dissect_epl_ainv(epl_tree, tvb, pinfo, offset);
break;
case EPL_AMNI:
size = tvb_captured_length_remaining(tvb, offset);
offset = dissect_epl_payload(epl_tree, tvb, pinfo, offset, size, NULL, EPL_AMNI);
break;
}
return offset;
}
static int
dissect_epl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_eplpdu(tvb, pinfo, tree, FALSE);
}
static int
dissect_epludp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_eplpdu(tvb, pinfo, tree, TRUE);
}
static const gchar*
decode_epl_address (guchar adr)
{
const gchar *addr_str;
addr_str = try_val_to_str(adr, addr_str_vals);
if (addr_str != NULL)
{
return addr_str;
}
else
{
if (EPL_IS_CN_NODEID(adr))
{
return addr_str_cn;
}
else
{
return addr_str_res;
}
}
}
static gint
dissect_epl_payload(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint len, const struct epl_datatype *type, guint8 msgType)
{
gint rem_len = 0, payload_len = 0;
tvbuff_t *payload_tvb = NULL;
heur_dtbl_entry_t *hdtbl_entry = NULL;
proto_item *item = NULL;
if (len <= 0)
return offset;
rem_len = tvb_captured_length_remaining(tvb, offset);
payload_tvb = tvb_new_subset_length(tvb, offset, MIN(len, rem_len));
payload_len = tvb_captured_length_remaining(payload_tvb, 0);
if ( payload_len < len )
{
item = proto_tree_add_uint(epl_tree, hf_epl_payload_real, tvb, offset, payload_len, payload_len);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_real_length_differs );
}
if (msgType != EPL_PREQ && msgType != EPL_PRES)
{
if ( dissector_try_heuristic(heur_epl_data_subdissector_list, payload_tvb, pinfo, epl_tree, &hdtbl_entry, &msgType))
return offset + payload_len;
}
if (type && (!type->len || type->len == payload_len))
{
if (*type->hf != hf_epl_od_uint)
{
proto_tree_add_item(epl_tree, *type->hf, tvb, offset, type->len, type->encoding);
}
else
{
guint64 val;
item = proto_tree_add_item_ret_uint64(epl_tree, *type->hf,
tvb, offset, type->len, type->encoding, &val);
proto_item_append_text(item, " (0x%.*" G_GINT64_MODIFIER "x)", 2*type->len, val);
}
}
else
{
if (payload_len < (int)sizeof (guint64) && interpret_untyped_as_le)
{
guint64 val;
item = proto_tree_add_item_ret_uint64(epl_tree, hf_epl_od_uint,
payload_tvb, 0, payload_len, ENC_LITTLE_ENDIAN, &val);
proto_item_append_text(item, " (0x%.*" G_GINT64_MODIFIER "x)", 2*payload_len, val);
}
else
{
call_data_dissector(payload_tvb, pinfo, epl_tree);
}
}
return offset + payload_len;
}
static gint
dissect_epl_soc(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
nstime_t nettime;
guint8 flags;
static const int * soc_flags[] = {
&hf_epl_soc_mc,
&hf_epl_soc_ps,
NULL
};
offset += 1;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(epl_tree, tvb, offset, hf_epl_soc, ett_epl_soc, soc_flags, ENC_NA);
offset += 2;
if (show_soc_flags)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "F:MC=%d,PS=%d",
((EPL_SOC_MC_MASK & flags) >> 7), ((EPL_SOC_PS_MASK & flags) >> 6));
}
nettime.secs = tvb_get_letohl(tvb, offset);
nettime.nsecs = tvb_get_letohl(tvb, offset+4);
proto_tree_add_time(epl_tree, hf_epl_soc_nettime, tvb, offset, 8, &nettime);
proto_tree_add_item(epl_tree, hf_epl_soc_relativetime, tvb, offset+8, 8, ENC_LITTLE_ENDIAN);
offset += 16;
return offset;
}
static gint
dissect_epl_preq(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint16 len;
guint8 pdoversion;
guint8 flags;
static const int * req_flags[] = {
&hf_epl_preq_ms,
&hf_epl_preq_ea,
&hf_epl_preq_rd,
NULL
};
offset += 1;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(epl_tree, tvb, offset, hf_epl_preq, ett_epl_preq, req_flags, ENC_NA);
offset += 2;
pdoversion = tvb_get_guint8(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_preq_pdov, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(epl_tree, hf_epl_preq_size, tvb, offset, 2, len);
col_append_fstr(pinfo->cinfo, COL_INFO, "[%4d] F:RD=%d V:%d.%d", len,
(EPL_PDO_RD_MASK & flags), hi_nibble(pdoversion), lo_nibble(pdoversion));
offset += 2;
offset = dissect_epl_pdo(convo, epl_tree, tvb, pinfo, offset, len, EPL_PREQ );
return offset;
}
static gint
dissect_epl_pres(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint16 len;
guint8 pdoversion;
guint8 state, flags, flags2;
static const int * res_flags[] = {
&hf_epl_pres_ms,
&hf_epl_pres_en,
&hf_epl_pres_rd,
NULL
};
state = tvb_get_guint8(tvb, offset);
if (pinfo->srcport != EPL_MN_NODEID)
{
proto_tree_add_item(epl_tree, hf_epl_pres_stat_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(epl_tree, hf_epl_pres_stat_ms, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(epl_tree, tvb, offset, hf_epl_pres, ett_epl_pres, res_flags, ENC_NA);
offset += 1;
flags2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_pres_pr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_pres_rs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
pdoversion = tvb_get_guint8(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_pres_pdov, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 2;
len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(epl_tree, hf_epl_pres_size, tvb, offset, 2, len);
col_append_fstr(pinfo->cinfo, COL_INFO, "[%4d]", len);
col_append_fstr(pinfo->cinfo, COL_INFO, " F:RD=%d,RS=%d,PR=%d V=%d.%d",
(EPL_PDO_RD_MASK & flags), (EPL_PDO_RS_MASK & flags2), (EPL_PDO_PR_MASK & flags2) >> 3,
hi_nibble(pdoversion), lo_nibble(pdoversion));
if (pinfo->srcport != EPL_MN_NODEID)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(state, epl_nmt_cs_vals, "Unknown(%d)"));
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(state, epl_nmt_ms_vals, "Unknown(%d)"));
}
offset += 2;
offset = dissect_epl_pdo(convo, epl_tree, tvb, pinfo, offset, len, EPL_PRES );
return offset;
}
static gint
dissect_epl_soa(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 svid, target;
guint8 state;
proto_item *psf_item = NULL;
proto_tree *psf_tree = NULL;
state = tvb_get_guint8(tvb, offset);
if (pinfo->srcport != EPL_MN_NODEID)
{
proto_tree_add_item(epl_tree, hf_epl_soa_stat_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(epl_tree, hf_epl_soa_stat_ms, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
svid = tvb_get_guint8(tvb, offset + 2);
if (svid == EPL_SOA_IDENTREQUEST)
{
proto_tree_add_item(epl_tree, hf_epl_soa_dna_an_lcl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(epl_tree, hf_epl_soa_dna_an_glb, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_soa_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_soa_er, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_uint(epl_tree, hf_epl_soa_svid, tvb, offset, 1, svid);
offset += 1;
target = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(epl_tree, hf_epl_soa_svtg, tvb, offset, 1, target);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s)->%3d",
rval_to_str(svid, soa_svid_id_vals, "Unknown"), target);
if (pinfo->srcport != EPL_MN_NODEID)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(state, epl_nmt_cs_vals, "Unknown(%d)"));
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(state, epl_nmt_ms_vals, "Unknown(%d)"));
}
proto_tree_add_item(epl_tree, hf_epl_soa_eplv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (svid == EPL_SOA_SYNCREQUEST)
{
offset +=1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_soa_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 0..7)");
psf_tree = proto_item_add_subtree(psf_item, ett_epl_soa_sync);
proto_tree_add_item(psf_tree, hf_epl_soa_mac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_pre_tm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_mnd_sec, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_mnd_fst, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_pre_sec, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_pre_fst, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_soa_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 8..15)");
#if 0
psf_tree = proto_item_add_subtree(psf_item, ett_epl_soa_sync);
#endif
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_soa_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 16..23)");
#if 0
psf_tree = proto_item_add_subtree(psf_item, ett_epl_soa_sync);
#endif
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_soa_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 24..31)");
psf_tree = proto_item_add_subtree(psf_item, ett_epl_soa_sync);
proto_tree_add_item(psf_tree, hf_epl_soa_pre_set, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_soa_pre_res, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(epl_tree, hf_epl_soa_pre_fst_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_soa_pre_sec_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_soa_mnd_fst_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_soa_mnd_sec_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_soa_pre_tm_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_soa_mac_end, tvb, offset, 6, ENC_NA);
offset += 6;
}
return offset;
}
static gint
dissect_epl_asnd(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 svid;
gint size, reported_len;
tvbuff_t *next_tvb;
proto_item *item;
proto_tree *subtree;
struct epl_convo *convo;
svid = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint(epl_tree, hf_epl_asnd_svid, tvb, offset, 1, svid );
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",
rval_to_str(svid, asnd_svid_id_vals, "Unknown"));
switch (svid)
{
case EPL_ASND_IDENTRESPONSE:
convo = epl_get_convo(pinfo, CONVO_FOR_RESPONSE);
offset = dissect_epl_asnd_ires(convo, epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_STATUSRESPONSE:
offset = dissect_epl_asnd_sres(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_NMTREQUEST:
offset = dissect_epl_asnd_nmtreq(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_NMTCOMMAND:
offset = dissect_epl_asnd_nmtcmd(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_SDO:
subtree = proto_item_add_subtree ( item, ett_epl_sdo );
offset = dissect_epl_asnd_sdo(subtree, tvb, pinfo, offset);
break;
case EPL_ASND_SYNCRESPONSE:
offset = dissect_epl_asnd_resp(epl_tree, tvb, pinfo, offset);
break;
default:
size = tvb_captured_length_remaining(tvb, offset);
reported_len = tvb_reported_length_remaining(tvb, offset);
next_tvb = tvb_new_subset_length_caplen(tvb, offset, size, reported_len);
if (svid >= 0xA0 && svid < 0xFF && dissector_try_uint(epl_asnd_dissector_table,
svid, next_tvb, pinfo, ( epl_tree ? epl_tree->parent : NULL ))) {
break;
}
dissect_epl_payload(epl_tree, tvb, pinfo, offset, size, NULL, EPL_ASND);
}
return offset;
}
static gint
dissect_epl_ainv(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 svid;
proto_item *item;
proto_tree *subtree;
struct epl_convo *convo;
if (pinfo->srcport != EPL_MN_NODEID)
{
proto_tree_add_item(epl_tree, hf_epl_soa_stat_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(epl_tree, hf_epl_soa_stat_ms, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(epl_tree, hf_epl_soa_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_soa_er, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
svid = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ", rval_to_str(svid, asnd_svid_id_vals, "UNKNOWN(%d)"));
item = proto_tree_add_uint(epl_tree, hf_epl_asnd_svid, tvb, offset, 1, svid );
offset += 1;
switch (svid)
{
case EPL_ASND_IDENTRESPONSE:
convo = epl_get_convo(pinfo, CONVO_FOR_RESPONSE);
offset = dissect_epl_asnd_ires(convo, epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_STATUSRESPONSE:
offset = dissect_epl_asnd_sres(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_NMTREQUEST:
offset = dissect_epl_asnd_nmtreq(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_NMTCOMMAND:
offset = dissect_epl_asnd_nmtcmd(epl_tree, tvb, pinfo, offset);
break;
case EPL_SOA_UNSPECIFIEDINVITE:
proto_tree_add_item(epl_tree, hf_epl_asnd_svtg, tvb, offset, 1, ENC_LITTLE_ENDIAN );
offset += 1;
proto_tree_add_item(epl_tree, hf_epl_soa_eplv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case EPL_ASND_SDO:
subtree = proto_item_add_subtree ( item, ett_epl_sdo );
offset = dissect_epl_asnd_sdo(subtree, tvb, pinfo, offset);
break;
}
return offset;
}
static gint
dissect_epl_asnd_nmtreq(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 rcid;
rcid = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(epl_tree, hf_epl_asnd_nmtrequest_rcid, tvb, offset, 1, rcid);
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtrequest_rct, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtrequest_rcd, tvb, offset+2, -1, ENC_NA);
offset += 2;
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(rcid, &asnd_cid_vals_ext, "Unknown (%d)"));
return offset;
}
static gint
dissect_epl_asnd_nmtdna(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
proto_item *ti_dna;
proto_tree *epl_dna_tree;
guint32 curr_node_num;
guint32 new_node_num;
guint32 lease_time;
guint32 lease_time_s;
nstime_t us;
static const int * dna_flags[] = {
&hf_epl_asnd_nmtcommand_nmtdna_ltv,
&hf_epl_asnd_nmtcommand_nmtdna_hpm,
&hf_epl_asnd_nmtcommand_nmtdna_nnn,
&hf_epl_asnd_nmtcommand_nmtdna_mac,
&hf_epl_asnd_nmtcommand_nmtdna_cnn,
NULL
};
ti_dna = proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_nmtdna, tvb, offset, EPL_SIZEOF_NMTCOMMAND_DNA, ENC_NA);
epl_dna_tree = proto_item_add_subtree(ti_dna, ett_epl_feat);
proto_tree_add_bitmask(epl_dna_tree, tvb, offset, hf_epl_asnd_nmtcommand_nmtdna_flags, ett_epl_asnd_nmt_dna, dna_flags, ENC_NA);
offset += 1;
proto_tree_add_item(epl_dna_tree, hf_epl_asnd_nmtcommand_nmtdna_currmac, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(epl_dna_tree, hf_epl_asnd_nmtcommand_nmtdna_hubenmsk, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item_ret_uint(epl_dna_tree, hf_epl_asnd_nmtcommand_nmtdna_currnn, tvb, offset, 4, ENC_LITTLE_ENDIAN, &curr_node_num);
offset += 4;
proto_tree_add_item_ret_uint (epl_dna_tree, hf_epl_asnd_nmtcommand_nmtdna_newnn, tvb, offset, 4, ENC_LITTLE_ENDIAN, &new_node_num);
offset += 4;
lease_time = tvb_get_guint32(tvb, offset, ENC_LITTLE_ENDIAN);
lease_time_s = lease_time / 1000000;
us.nsecs = (lease_time - lease_time_s * 1000000) * 1000;
us.secs = lease_time_s;
proto_tree_add_time(epl_dna_tree, hf_epl_asnd_nmtcommand_nmtdna_leasetime, tvb, offset, 4, &us);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %4d -> %4d", curr_node_num, new_node_num);
return offset;
}
static gint
dissect_epl_asnd_nmtcmd(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 epl_asnd_nmtcommand_cid;
guint16 errorcode;
epl_asnd_nmtcommand_cid = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(epl_tree, hf_epl_asnd_nmtcommand_cid, tvb, offset, 1, epl_asnd_nmtcommand_cid);
offset += 2;
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_ext(epl_asnd_nmtcommand_cid, &asnd_cid_vals_ext, "Unknown(%d)"));
switch (epl_asnd_nmtcommand_cid)
{
case EPL_ASND_NMTCOMMAND_NMTNETHOSTNAMESET:
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_nmtnethostnameset_hn, tvb, offset, 32, ENC_NA);
offset += 32;
break;
case EPL_ASND_NMTCOMMAND_NMTFLUSHARPENTRY:
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_nmtflusharpentry_nid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case EPL_ASND_NMTCOMMAND_NMTPUBLISHTIME:
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_nmtpublishtime_dt, tvb, offset, 6, ENC_NA);
offset += 6;
break;
case EPL_ASND_NMTCOMMAND_NMTDNA:
offset -= 1;
offset = dissect_epl_asnd_nmtdna(epl_tree, tvb, pinfo, offset);
break;
case EPL_ASND_NMTCOMMAND_NMTRESETNODE:
errorcode = tvb_get_letohs(tvb, offset);
if (errorcode != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str(errorcode, errorcode_vals, "Unknown Error(0x%04x"));
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_resetnode_reason, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
else
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_cdat, tvb, offset, -1, ENC_NA);
break;
default:
proto_tree_add_item(epl_tree, hf_epl_asnd_nmtcommand_cdat, tvb, offset, -1, ENC_NA);
}
return offset;
}
static gint
dissect_epl_asnd_ires(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint32 epl_asnd_identresponse_ipa, epl_asnd_identresponse_snm, epl_asnd_identresponse_gtw;
proto_item *ti_feat, *ti;
proto_tree *epl_feat_tree;
guint16 device_type;
const char *profile_name = NULL;
guint32 response_time;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_en, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_ec, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_pr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_rs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (pinfo->srcport != EPL_MN_NODEID)
{
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_stat_cs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_stat_ms, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_ever, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
ti_feat = proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_feat, tvb, offset, 4, ENC_LITTLE_ENDIAN);
epl_feat_tree = proto_item_add_subtree(ti_feat, ett_epl_feat);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit0, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit4, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit5, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit6, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit7, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit8, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit9, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitA, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitB, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitC, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitD, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitE, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bitF, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit10, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit11, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit12, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit13, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_feat_tree, hf_epl_asnd_identresponse_feat_bit14, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_mtu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_pis, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_pos, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
response_time = tvb_get_letohl(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_rst, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 6;
device_type = tvb_get_letohs(tvb, offset);
if (device_type != convo->device_type)
convo = epl_get_convo(pinfo, CONVO_FOR_RESPONSE | CONVO_ALWAYS_CREATE);
convo->response_time = response_time;
convo->device_type = device_type;
ti = proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_dt, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (!convo->profile || !convo->profile->nodeid)
epl_update_convo_cn_profile(convo);
if (convo->profile && convo->profile->name)
profile_name = convo->profile->name;
if (!profile_name)
profile_name = val_to_str_const(convo->device_type, epl_device_profiles, "Unknown Profile");
proto_item_append_text(ti, " (%s)", profile_name);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_dt_add, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
if (convo->profile && convo->profile->path)
{
ti = proto_tree_add_string(epl_tree, hf_epl_asnd_identresponse_profile_path, tvb, offset, 2, convo->profile->path);
PROTO_ITEM_SET_GENERATED(ti);
}
offset += 4;
convo->vendor_id = tvb_get_letohl(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_vid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
convo->product_code = tvb_get_letohl(tvb, offset);
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_productcode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_rno, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_sno, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_vex1, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_vcd, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_vct, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_ad, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_at, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
epl_asnd_identresponse_ipa = tvb_get_ntohl(tvb, offset);
proto_tree_add_ipv4(epl_tree , hf_epl_asnd_identresponse_ipa, tvb, offset, 4, epl_asnd_identresponse_ipa);
offset += 4;
epl_asnd_identresponse_snm = tvb_get_ntohl(tvb, offset);
proto_tree_add_ipv4(epl_tree , hf_epl_asnd_identresponse_snm, tvb, offset, 4, epl_asnd_identresponse_snm);
offset += 4;
epl_asnd_identresponse_gtw = tvb_get_ntohl(tvb, offset);
proto_tree_add_ipv4(epl_tree , hf_epl_asnd_identresponse_gtw, tvb, offset, 4, epl_asnd_identresponse_gtw);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_hn, tvb, offset, 32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(epl_tree, hf_epl_asnd_identresponse_vex2, tvb, offset, 48, ENC_NA);
offset += 48;
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(convo->device_type, epl_device_profiles, "Device Profile %d"));
return offset;
}
static gint
dissect_epl_asnd_resp(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_item *psf_item = NULL;
proto_tree *psf_tree = NULL;
offset +=2;
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 0..7)");
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sync);
proto_tree_add_item(psf_tree, hf_epl_asnd_syncResponse_sec_val, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(psf_tree, hf_epl_asnd_syncResponse_fst_val, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 8..15)");
#if 0
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sync);
#endif
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 16..23)");
#if 0
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sync);
#endif
offset += 1;
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_sync, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (Bits 24..31)");
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sync);
proto_tree_add_item(psf_tree, hf_epl_asnd_syncResponse_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_node, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_delay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_pre_fst, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(epl_tree, hf_epl_asnd_syncResponse_pre_sec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_epl_asnd_sres(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
proto_item *ti_el_entry, *ti_el_entry_type;
proto_tree *epl_seb_tree, *epl_el_tree, *epl_el_entry_tree, *epl_el_entry_type_tree;
guint number_of_entries, cnt;
guint8 nmt_state;
proto_tree_add_item(epl_tree, hf_epl_asnd_statusresponse_en, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_asnd_statusresponse_ec, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(epl_tree, hf_epl_asnd_statusresponse_pr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_tree, hf_epl_asnd_statusresponse_rs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
nmt_state = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(nmt_state, epl_nmt_cs_vals, "Unknown (%d)"));
if (pinfo->srcport != EPL_MN_NODEID)
{
proto_tree_add_uint(epl_tree, hf_epl_asnd_statusresponse_stat_cs, tvb, offset, 1, nmt_state);
}
else
{
proto_tree_add_uint(epl_tree, hf_epl_asnd_statusresponse_stat_ms, tvb, offset, 1, nmt_state);
}
offset += 4;
epl_seb_tree = proto_tree_add_subtree(epl_tree, tvb, offset, 8, ett_epl_seb, NULL, "StaticErrorBitfield");
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(epl_seb_tree, hf_epl_asnd_statusresponse_seb_devicespecific_err, tvb,offset, 6, ENC_NA);
offset += 6;
number_of_entries = (tvb_reported_length(tvb)-offset)/20;
epl_el_tree = proto_tree_add_subtree_format(epl_tree, tvb, offset, -1, ett_epl_el, NULL, "ErrorCodeList: %d entries", number_of_entries);
for (cnt = 0; cnt<number_of_entries; cnt++)
{
epl_el_entry_tree = proto_tree_add_subtree_format(epl_el_tree, tvb, offset, 20, ett_epl_el_entry, &ti_el_entry, "Entry %d", cnt+1);
ti_el_entry_type = proto_tree_add_item(ti_el_entry,
hf_epl_asnd_statusresponse_el_entry_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
epl_el_entry_type_tree = proto_item_add_subtree(ti_el_entry_type,
ett_epl_el_entry_type);
proto_tree_add_item(epl_el_entry_type_tree,
hf_epl_asnd_statusresponse_el_entry_type_profile, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_el_entry_type_tree,
hf_epl_asnd_statusresponse_el_entry_type_mode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_el_entry_type_tree,
hf_epl_asnd_statusresponse_el_entry_type_bit14, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(epl_el_entry_type_tree,
hf_epl_asnd_statusresponse_el_entry_type_bit15, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(epl_el_entry_tree, hf_epl_asnd_statusresponse_el_entry_code, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(epl_el_entry_tree, hf_epl_asnd_statusresponse_el_entry_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(epl_el_entry_tree, hf_epl_asnd_statusresponse_el_entry_add, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
return offset;
}
static gint
dissect_epl_asnd_sdo(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint16 seqnum = 0x00;
guint8 seq_read;
offset = dissect_epl_sdo_sequence(epl_tree, tvb, pinfo, offset, &seq_read);
seqnum = epl_get_sequence_nr(pinfo);
if(seqnum == 0x00 || show_cmd_layer_for_duplicated == TRUE )
{
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
offset = dissect_epl_sdo_command(epl_tree, tvb, pinfo, offset, seq_read);
}
else col_append_str(pinfo->cinfo, COL_INFO, "Empty CommandLayer");
}
return offset;
}
static gint
dissect_epl_sdo_sequence(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8* seq)
{
guint8 seq_recv = 0x00, seq_send = 0x00, rcon = 0x00, scon = 0x00;
guint32 frame = 0x00;
proto_tree *sod_seq_tree;
proto_item *item;
guint8 duplication = 0x00;
gpointer key;
guint32 saved_frame;
guint16 seqnum = 0;
seq_recv = tvb_get_guint8(tvb, offset);
rcon = seq_recv & EPL_ASND_SDO_SEQ_CON_MASK;
seq_recv = seq_recv >> EPL_ASND_SDO_SEQ_MASK;
epl_segmentation.recv = seq_recv;
seq_send = tvb_get_guint8(tvb, offset+1);
scon = seq_send & EPL_ASND_SDO_SEQ_CON_MASK;
seq_send = seq_send >> EPL_ASND_SDO_SEQ_MASK;
epl_segmentation.send = seq_send;
frame = pinfo->num;
key = epl_duplication_key(epl_segmentation.src,epl_segmentation.dest,seq_recv,seq_send);
saved_frame = epl_duplication_get(epl_duplication_table, key);
if((rcon < EPL_VALID && scon < EPL_VALID)
||(rcon == EPL_VALID && scon < EPL_VALID)
||(rcon < EPL_VALID && scon == EPL_VALID))
{
epl_duplication_remove(epl_duplication_table,epl_segmentation.src,epl_segmentation.dest);
epl_set_sequence_nr(pinfo, 0x02);
}
else if(seq_recv >= EPL_MAX_SEQUENCE || seq_send >= EPL_MAX_SEQUENCE
||rcon > EPL_RETRANSMISSION || scon > EPL_RETRANSMISSION )
{
if(seq_recv >= EPL_MAX_SEQUENCE)
{
expert_add_info(pinfo, epl_tree, &ei_recvseq_value);
}
if(seq_send >= EPL_MAX_SEQUENCE)
{
expert_add_info(pinfo, epl_tree, &ei_sendseq_value);
}
if(rcon > EPL_RETRANSMISSION)
{
expert_add_info(pinfo, epl_tree, &ei_recvcon_value);
}
if(scon > EPL_RETRANSMISSION)
{
expert_add_info(pinfo, epl_tree, &ei_sendcon_value);
}
duplication = 0x00;
epl_set_sequence_nr(pinfo, 0x00);
}
else
{
if((rcon == EPL_VALID && scon == EPL_RETRANSMISSION) || (rcon == EPL_RETRANSMISSION && scon == EPL_VALID))
{
epl_duplication_insert(epl_duplication_table, key, frame);
}
else
{
if(saved_frame == 0x00)
{
epl_duplication_insert(epl_duplication_table,key,frame);
}
else if(((frame > (saved_frame + EPL_MAX_FRAME_OFFSET))
||(saved_frame > frame)))
{
epl_duplication_insert(epl_duplication_table,key,frame);
}
else if((frame < (saved_frame + EPL_MAX_FRAME_OFFSET))
&&(frame > saved_frame))
{
duplication = 0x01;
}
}
}
seqnum = epl_get_sequence_nr(pinfo);
if((duplication == 0x01 && seqnum == 0x00)||(seqnum == 0x01))
{
seqnum = 0x01;
epl_set_sequence_nr(pinfo, seqnum);
expert_add_info_format(pinfo, epl_tree, &ei_duplicated_frame,
"Duplication of Frame: %d ReceiveSequenceNumber: %d and SendSequenceNumber: %d ",
saved_frame,seq_recv,seq_send );
}
if(seq_recv == 0x3f && seq_send <= 0x3f)
{
epl_duplication_remove(epl_duplication_table,epl_segmentation.src,epl_segmentation.dest);
}
free_key(key);
item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_seq, tvb, offset, 5, ENC_NA);
sod_seq_tree = proto_item_add_subtree(item, ett_epl_sdo_sequence_layer);
seq_recv = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sod_seq_tree, hf_epl_asnd_sdo_seq_receive_sequence_number, tvb, offset, 1, seq_recv);
proto_tree_add_uint(sod_seq_tree, hf_epl_asnd_sdo_seq_receive_con, tvb, offset, 1, seq_recv);
offset += 1;
*seq = seq_send = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sod_seq_tree, hf_epl_asnd_sdo_seq_send_sequence_number, tvb, offset, 1, seq_send);
proto_tree_add_uint(sod_seq_tree, hf_epl_asnd_sdo_seq_send_con, tvb, offset, 1, seq_send);
offset += 3;
col_append_fstr(pinfo->cinfo, COL_INFO, "Seq:%02d%s,%02d%s",
seq_recv >> EPL_ASND_SDO_SEQ_MASK, val_to_str(seq_recv & EPL_ASND_SDO_SEQ_CON_MASK, epl_sdo_init_abbr_vals, "x"),
seq_send >> EPL_ASND_SDO_SEQ_MASK, val_to_str(seq_send & EPL_ASND_SDO_SEQ_CON_MASK, epl_sdo_init_abbr_vals, "x"));
seq_recv &= EPL_ASND_SDO_SEQ_CON_MASK;
seq_send &= EPL_ASND_SDO_SEQ_CON_MASK;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ", val_to_str((seq_recv << 8) | seq_send, epl_sdo_init_con_vals, "Invalid"));
return offset;
}
static gint
dissect_epl_sdo_command(proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 seq)
{
gint payload_length;
guint8 segmented, command_id, transaction_id;
gboolean response, abort_flag;
guint32 abort_code = 0;
guint32 fragmentId = 0, remlength = 0;
guint16 segment_size = 0;
proto_tree *sdo_cmd_tree = NULL;
proto_item *item;
guint8 sendCon = 0;
guint is_response = 0;
offset += 1;
sendCon = tvb_get_guint8(tvb, 5) & EPL_ASND_SDO_SEQ_SEND_CON_ERROR_VALID_ACK_REQ;
command_id = tvb_get_guint8(tvb, offset + 2);
abort_flag = tvb_get_guint8(tvb, offset + 1) & EPL_ASND_SDO_CMD_ABORT_FILTER;
if (command_id != 0 || abort_flag)
{
item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd, tvb, offset, 0, ENC_NA);
sdo_cmd_tree = proto_item_add_subtree(item, ett_epl_sdo_command_layer);
transaction_id = tvb_get_guint8(tvb, offset);
response = tvb_get_guint8(tvb, offset + 1) & EPL_ASND_SDO_CMD_RESPONSE_FILTER;
segmented = (tvb_get_guint8(tvb, offset + 1) & EPL_ASND_SDO_CMD_SEGMENTATION_FILTER) >> 4;
segment_size = tvb_get_letohs(tvb, offset + 3);
col_append_fstr(pinfo->cinfo, COL_INFO, "Cmd:%s,TID=%02d ",
val_to_str(segmented, epl_sdo_asnd_cmd_segmentation_abbr, " Inv(%d)"), transaction_id);
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_transaction_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_response, tvb, offset, 1, ENC_LITTLE_ENDIAN, &is_response);
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_abort, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_segmentation, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (segment_size != 0)
{
offset += 1;
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_command_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_segment_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 4;
}
tvb_set_reported_length(tvb, offset + segment_size);
if (segmented == EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
if((command_id == EPL_ASND_SDO_COMMAND_WRITE_BY_INDEX) || (command_id == EPL_ASND_SDO_COMMAND_READ_BY_INDEX))
{
if (sendCon != EPL_ASND_SDO_SEQ_SEND_CON_ERROR_VALID_ACK_REQ)
{
if(command_id == EPL_ASND_SDO_COMMAND_WRITE_BY_INDEX)
ct = 0x00;
else if(command_id == EPL_ASND_SDO_COMMAND_READ_BY_INDEX)
count = 0x00;
}
payload_length = tvb_reported_length_remaining(tvb, offset);
fragmentId = (guint32)((((guint32)epl_segmentation.src)<<16)+epl_segmentation.dest);
pinfo->fragmented = TRUE;
fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, 0, payload_length, TRUE );
fragment_add_seq_offset ( &epl_reassembly_table, pinfo, fragmentId, NULL, 0 );
if (command_id == EPL_ASND_SDO_COMMAND_WRITE_BY_INDEX)
{
first_write = FALSE;
}
else
{
first_read = FALSE;
}
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
segmented = TRUE;
offset += 4;
}
else
{
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
segmented = TRUE;
offset += 4;
}
}
if (abort_flag)
{
remlength = tvb_captured_length_remaining(tvb, offset);
if (command_id == EPL_ASND_SDO_COMMAND_WRITE_MULTIPLE_PARAMETER_BY_INDEX && response)
{
while (remlength > 0)
{
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_sub_abort, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
abort_code = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_abort_code, tvb, offset, 4, abort_code);
col_append_fstr(pinfo->cinfo, COL_INFO, "Abort:0x%08X (%s)", abort_code, val_to_str_ext_const(abort_code, &sdo_cmd_abort_code_ext, "Unknown"));
offset += 4;
remlength = tvb_captured_length_remaining(tvb, offset);
}
}
else
{
abort_code = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(sdo_cmd_tree, hf_epl_asnd_sdo_cmd_abort_code, tvb, offset, 4, abort_code);
col_append_fstr(pinfo->cinfo, COL_INFO, "Abort:0x%08X (%s)", abort_code, val_to_str_ext_const(abort_code, &sdo_cmd_abort_code_ext, "Unknown"));
}
}
else
{
int opts = is_response ? CONVO_FOR_RESPONSE : CONVO_FOR_REQUEST;
struct epl_convo *convo = epl_get_convo(pinfo, opts);
convo->seq_send = seq;
switch (command_id)
{
case EPL_ASND_SDO_COMMAND_WRITE_BY_INDEX:
offset = dissect_epl_sdo_command_write_by_index(convo, sdo_cmd_tree, tvb, pinfo, offset, segmented, response, segment_size);
break;
case EPL_ASND_SDO_COMMAND_WRITE_MULTIPLE_PARAMETER_BY_INDEX:
offset = dissect_epl_sdo_command_write_multiple_by_index(convo, sdo_cmd_tree, tvb, pinfo, offset, segmented, response, segment_size);
break;
case EPL_ASND_SDO_COMMAND_READ_MULTIPLE_PARAMETER_BY_INDEX:
offset = dissect_epl_sdo_command_read_multiple_by_index(convo, sdo_cmd_tree, tvb, pinfo, offset, segmented, response, segment_size);
break;
case EPL_ASND_SDO_COMMAND_READ_BY_INDEX:
offset = dissect_epl_sdo_command_read_by_index(convo, sdo_cmd_tree, tvb, pinfo, offset, segmented, response, segment_size);
break;
default:
return FALSE;
}
}
}
return offset;
}
static gint
dissect_epl_sdo_command_write_by_index(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 segmented, gboolean response, guint16 segment_size)
{
gint size, payload_length = 0;
guint16 idx = 0x00, sod_index = 0xFF, error = 0xFF, sub_val = 0x00;
gboolean nosub = FALSE;
guint8 subindex = 0x00;
guint32 fragmentId = 0;
guint32 frame = 0;
gboolean end_segment = FALSE;
proto_item *psf_item, *cmd_payload;
proto_tree *payload_tree;
const gchar *index_str, *sub_str, *sub_index_str;
fragment_head *frag_msg = NULL;
struct object *obj = NULL;
struct subobject *subobj = NULL;
frame = pinfo->num;
if (!response)
{
if (segmented <= EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
idx = tvb_get_letohs(tvb, offset);
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
obj = object_lookup(convo->profile, idx);
if (!obj)
{
index_str = rval_to_str_const(idx, sod_cmd_str, "unknown");
sod_index = str_to_val(index_str, sod_cmd_str_val, error);
sub_index_str = val_to_str_ext_const(idx, &sod_cmd_no_sub, "unknown");
nosub = str_to_val(sub_index_str, sod_cmd_str_no_sub, 0xFF) != 0xFF;
}
offset += 2;
subindex = tvb_get_guint8(tvb, offset);
subobj = subobject_lookup(obj, subindex);
sub_str = val_to_str_ext_const(subindex, &sod_cmd_sub_str, "unknown");
sub_val = str_to_val(sub_str, sod_cmd_sub_str_val, error);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%d]: (0x%04X/%d)",
val_to_str_ext(EPL_ASND_SDO_COMMAND_WRITE_BY_INDEX, &epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size, idx, subindex);
if (obj || sod_index == error)
{
const char *name = obj ? obj->info.name : val_to_str_ext_const(((guint32)(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_item, " (%s)", name);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s", name);
if (obj) nosub = obj->info.type_class == OD_ENTRY_SCALAR;
}
else
{
proto_item_append_text(psf_item," (%s", val_to_str_ext_const(((guint32)(sod_index<<16)), &sod_index_names, "User Defined"));
proto_item_append_text(psf_item,"_%02Xh", (idx-sod_index));
if(sod_index == EPL_SOD_PDO_RX_MAPP || sod_index == EPL_SOD_PDO_TX_MAPP)
{
proto_item_append_text(psf_item,"_AU64)");
}
else
{
proto_item_append_text(psf_item,"_REC)");
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s", val_to_str_ext_const(((guint32)(sod_index << 16)), &sod_index_names, "User Defined"));
col_append_fstr(pinfo->cinfo, COL_INFO, "_%02Xh", (idx-sod_index));
if(sod_index == EPL_SOD_PDO_RX_MAPP || sod_index == EPL_SOD_PDO_TX_MAPP)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "_AU64");
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "_REC");
}
idx = sod_index;
}
if(sub_val != error)
idx = sub_val;
if (subobj)
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", subobj->info.name);
col_append_fstr(pinfo->cinfo, COL_INFO, "/%s)", subobj->info.name);
}
else if((idx == EPL_SOD_STORE_PARAM && subindex <= 0x7F && subindex >= 0x04) ||
(idx == EPL_SOD_RESTORE_PARAM && subindex <= 0x7F && subindex >= 0x04))
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ManufacturerParam_%02Xh_U32)", subindex);
col_append_fstr(pinfo->cinfo, COL_INFO, "/ManufacturerParam_%02Xh_U32)", subindex);
}
else if((idx == EPL_SOD_PDO_RX_MAPP && subindex >= 0x01 && subindex <= 0xfe) ||
(idx == EPL_SOD_PDO_TX_MAPP && subindex >= 0x01 && subindex <= 0xfe))
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ObjectMapping)");
col_append_fstr(pinfo->cinfo, COL_INFO, "/ObjectMapping)");
}
else if(nosub)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
}
else if(subindex == 0x00)
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (NumberOfEntries)");
col_append_fstr(pinfo->cinfo, COL_INFO, "/NumberOfEntries)");
}
else
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", val_to_str_ext_const((subindex | (idx << 16)), &sod_index_names, "User Defined"));
col_append_fstr(pinfo->cinfo, COL_INFO, "/%s)",val_to_str_ext_const((subindex | (idx << 16)), &sod_index_names, "User Defined"));
}
offset += 2;
}
else if((segmented == EPL_ASND_SDO_CMD_SEGMENTATION_TRANSFER_COMPLETE) ||
(segmented == EPL_ASND_SDO_CMD_SEGMENTATION_SEGMENT))
{
fragmentId = (guint32)((((guint32)epl_segmentation.src)<<16)+epl_segmentation.dest);
pinfo->fragmented = TRUE;
payload_length = tvb_reported_length_remaining(tvb, offset);
if(segmented == EPL_ASND_SDO_CMD_SEGMENTATION_TRANSFER_COMPLETE)
end_segment = TRUE;
if(epl_segmentation.send == 0x3f || epl_segmentation.send <= 0x01 )
{
memset(&epl_asnd_sdo_reassembly_write,0,sizeof(epl_sdo_reassembly));
epl_asnd_sdo_reassembly_write.frame[epl_segmentation.recv][epl_segmentation.send] = frame;
ct += 1;
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, ct, payload_length, end_segment ? FALSE : TRUE );
}
else
{
if(epl_asnd_sdo_reassembly_write.frame[epl_segmentation.recv][epl_segmentation.send] == 0x00)
{
epl_asnd_sdo_reassembly_write.frame[epl_segmentation.recv][epl_segmentation.send] = frame;
ct += 1;
if (first_write)
{
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, 0, payload_length, end_segment ? FALSE : TRUE );
fragment_add_seq_offset(&epl_reassembly_table, pinfo, fragmentId, NULL, ct);
first_write = FALSE;
}
else
{
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, ct, payload_length, end_segment ? FALSE : TRUE );
}
}
else
{
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, 0, payload_length, end_segment ? FALSE : TRUE);
epl_asnd_sdo_reassembly_write.frame[epl_segmentation.recv][epl_segmentation.send] = frame;
}
}
if(frag_msg != NULL && (epl_asnd_sdo_reassembly_write.frame[epl_segmentation.recv][epl_segmentation.send] == frame))
{
if(end_segment)
{
cmd_payload = proto_tree_add_uint_format(epl_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, offset, payload_length,0,
"Reassembled: %d bytes total (%d bytes in this frame)",frag_msg->len,payload_length);
payload_tree = proto_item_add_subtree(cmd_payload, ett_epl_asnd_sdo_data_reassembled);
process_reassembled_data(tvb, 0, pinfo, "Reassembled Message", frag_msg, &epl_frag_items, NULL, payload_tree );
proto_tree_add_uint_format_value(payload_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, 0, 0,
payload_length, "%d bytes (over all fragments)", frag_msg->len);
col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled)" );
}
else
{
cmd_payload = proto_tree_add_uint_format(epl_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, offset, payload_length,0,
"Reassembled: %d bytes total (%d bytes in this frame)",frag_msg->len,payload_length);
payload_tree = proto_item_add_subtree(cmd_payload, ett_epl_asnd_sdo_data_reassembled);
process_reassembled_data(tvb, 0, pinfo, "Reassembled Message", frag_msg, &epl_frag_items, NULL, payload_tree );
}
first_write = TRUE;
ct = 0;
}
}
size = tvb_reported_length_remaining(tvb, offset);
if((idx == EPL_SOD_PDO_TX_MAPP && subindex > 0x00) || (idx == EPL_SOD_PDO_RX_MAPP && subindex > 0x00))
{
wmem_array_t *mappings = NULL;
if (use_sdo_mappings)
mappings = idx == EPL_SOD_PDO_TX_MAPP ? convo->TPDO : convo->RPDO;
offset = dissect_object_mapping(convo->profile, mappings, epl_tree, tvb, pinfo->num, offset, idx, subindex);
}
else
{
const struct epl_datatype *type = NULL;
if (subobj)
type = subobj->info.type;
else if (obj)
type = obj->info.type;
offset = dissect_epl_payload(epl_tree, tvb, pinfo, offset, size, type, EPL_ASND);
}
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "Response");
}
return offset;
}
static gint
dissect_object_mapping(struct profile *profile, wmem_array_t *mappings, proto_tree *epl_tree, tvbuff_t *tvb, guint32 framenum, gint offset, guint16 idx, guint8 subindex)
{
proto_item *ti_obj, *ti_subobj, *psf_item;
proto_tree *psf_tree;
struct object_mapping map = OBJECT_MAPPING_INITIALIZER;
struct object *mapping_obj;
int *ett;
struct subobject *mapping_subobj;
gboolean nosub = FALSE;
if (!epl_tree && !mappings)
return offset + EPL_OBJECT_MAPPING_SIZE;
map.param.idx = idx;
map.param.subindex = subindex;
map.frame.first = framenum;
map.frame.last = G_MAXUINT32;
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_mapping, tvb, offset, 1, ENC_NA);
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sdo_cmd_data_mapping);
map.pdo.idx = tvb_get_letohs(tvb, offset);
ti_obj = proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_index, tvb, offset, 2, map.pdo.idx,"Index: 0x%04X", map.pdo.idx);
offset += 2;
map.pdo.subindex = tvb_get_guint8(tvb, offset);
ti_subobj = proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_subindex, tvb, offset, 1, map.pdo.subindex, "SubIndex: 0x%02X", map.pdo.subindex);
offset += 2;
if ((mapping_obj = object_lookup(profile, map.pdo.idx)))
{
if (!map.pdo.subindex && mapping_obj->info.type_class == OD_ENTRY_SCALAR)
nosub = TRUE;
map.info = &mapping_obj->info;
map.index_name = map.info->name;
proto_item_append_text (ti_obj, " (%s)", map.info->name);
mapping_subobj = subobject_lookup(mapping_obj, map.pdo.subindex);
if (mapping_subobj)
{
map.info = &mapping_subobj->info;
proto_item_append_text (ti_subobj, " (%s)", map.info->name);
}
else
{
PROTO_ITEM_SET_HIDDEN(ti_subobj);
}
}
map.bit_offset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_offset, tvb, offset, 2, map.bit_offset,"Offset: 0x%04X", map.bit_offset);
offset += 2;
map.no_of_bits = tvb_get_guint8(tvb, offset);
psf_item = proto_tree_add_item(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " bits");
offset += 2;
map.ett = -1;
ett = &map.ett;
proto_register_subtree_array(&ett, 1);
if (mappings)
{
if (nosub)
map.title = g_strdup_printf("PDO - %04X", map.pdo.idx);
else
map.title = g_strdup_printf("PDO - %04X:%02X", map.pdo.idx, map.pdo.subindex);
add_object_mapping(mappings, &map);
}
return offset;
}
static gint
dissect_epl_sdo_command_write_multiple_by_index(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 segmented, gboolean response, guint16 segment_size)
{
gint dataoffset;
guint8 subindex = 0x00, padding = 0x00;
guint16 idx = 0x00, error = 0xFF, sub_val = 0x00;
gboolean nosub = FALSE;
guint32 size, offsetincrement, datalength, remlength, objectcnt, abort_code = 0;
gboolean lastentry = FALSE, is_abort = FALSE;
const gchar *index_str, *sub_str, *sub_index_str;
proto_item *psf_item;
proto_tree *psf_od_tree;
struct object *obj = NULL;
struct subobject *subobj = NULL;
if (!response)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%d]:",
val_to_str_ext(EPL_ASND_SDO_COMMAND_WRITE_MULTIPLE_PARAMETER_BY_INDEX,
&epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size);
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
objectcnt = 0;
while ( !lastentry && remlength > 0 )
{
guint16 sod_index = error;
offsetincrement = tvb_get_letohl(tvb, offset);
padding = tvb_get_guint8 ( tvb, offset + 7 ) & 0x03;
datalength = offsetincrement - ( offset - EPL_SOA_EPLV_OFFSET );
if ( offsetincrement == 0 )
datalength = remlength - EPL_SOA_EPLV_OFFSET;
if ( ( datalength + EPL_SOA_EPLV_OFFSET ) > remlength )
break;
if ( offsetincrement == 0 )
{
datalength = remlength;
if ( remlength < EPL_SOA_EPLV_OFFSET )
break;
size = remlength - EPL_SOA_EPLV_OFFSET;
lastentry = TRUE;
}
else
{
if ( (guint32)( padding + 8 ) >= datalength )
break;
size = datalength - 8 - padding;
}
dataoffset = offset + 4;
psf_od_tree = proto_tree_add_subtree(epl_tree, tvb, offset+4, 4+size, 0, NULL , "OD");
if (segmented <= EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
idx = tvb_get_letohs(tvb, dataoffset);
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
obj = object_lookup(convo->profile, idx);
if (!obj)
{
index_str = rval_to_str_const(idx, sod_cmd_str, "unknown");
sod_index = str_to_val(index_str, sod_cmd_str_val, error);
sub_index_str = val_to_str_ext_const(idx, &sod_cmd_no_sub, "unknown");
nosub = str_to_val(sub_index_str, sod_cmd_str_no_sub, 0xFF) != 0xFF;
}
if(sod_index == error)
{
const char *name = obj ? obj->info.name :val_to_str_ext_const(((guint32)(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_item," (%s)", name);
}
else
{
proto_item_append_text(psf_item," (%s", val_to_str_ext_const(((guint32)(sod_index<<16)), &sod_index_names, "User Defined"));
proto_item_append_text(psf_item,"_%02Xh", (idx-sod_index));
if(sod_index == EPL_SOD_PDO_RX_MAPP || sod_index == EPL_SOD_PDO_TX_MAPP)
{
proto_item_append_text(psf_item,"_AU64)");
}
else
{
proto_item_append_text(psf_item,"_REC)");
}
}
if (objectcnt < 8)
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%04X", idx);
else
col_append_str(pinfo->cinfo, COL_INFO, ".");
if (sod_index != error)
idx = sod_index;
dataoffset += 2;
proto_item_append_text(psf_od_tree, " Idx: 0x%04X", idx);
subindex = tvb_get_guint8(tvb, dataoffset);
subobj = subobject_lookup(obj, subindex);
proto_item_append_text(psf_od_tree, " SubIdx: 0x%02X", subindex);
sub_str = val_to_str_ext_const(idx, &sod_cmd_sub_str, "unknown");
sub_val = str_to_val(sub_str, sod_cmd_sub_str_val,error);
if(sub_val != error)
idx = sub_val;
if (subobj)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", subobj->info.name);
}
else if(idx == EPL_SOD_STORE_PARAM && subindex <= 0x7F && subindex >= 0x04)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ManufacturerParam_%02Xh_U32)", subindex);
}
else if(idx == EPL_SOD_RESTORE_PARAM && subindex <= 0x7F && subindex >= 0x04)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ManufacturerParam_%02Xh_U32)", subindex);
}
else if(idx == EPL_SOD_PDO_RX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ObjectMapping)");
}
else if(idx == EPL_SOD_PDO_TX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ObjectMapping)");
}
else if(subindex == 0x00)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (NumberOfEntries)");
}
else
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", val_to_str_ext_const((subindex | (idx << 16)), &sod_index_names, "User Defined"));
}
if (objectcnt < 8)
{
if (nosub)
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
else
col_append_fstr(pinfo->cinfo, COL_INFO, "/%d)", subindex);
}
dataoffset += 1;
proto_tree_add_uint(psf_od_tree, hf_epl_asnd_sdo_cmd_data_padding, tvb, dataoffset, 1, padding);
dataoffset += 1;
objectcnt++;
}
psf_item = proto_tree_add_uint_format(psf_od_tree, hf_epl_asnd_sdo_cmd_data_size, tvb, dataoffset, size, size, "Data size: %d byte", size);
PROTO_ITEM_SET_GENERATED(psf_item);
if((idx == EPL_SOD_PDO_TX_MAPP && subindex > 0x00) ||(idx == EPL_SOD_PDO_RX_MAPP && subindex > 0x00))
{
wmem_array_t *mappings = NULL;
if (use_sdo_mappings)
mappings = idx == EPL_SOD_PDO_TX_MAPP ? convo->TPDO : convo->RPDO;
dissect_object_mapping(convo->profile, mappings, epl_tree, tvb, pinfo->num, dataoffset, idx, subindex);
}
else
{
const struct epl_datatype *type = NULL;
if (subobj)
type = subobj->info.type;
else if (obj)
type = obj->info.type;
dissect_epl_payload(psf_od_tree, tvb, pinfo, dataoffset, size, type, EPL_ASND);
}
offset += datalength;
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d)", objectcnt);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "Response %s[%d]:",
val_to_str_ext(EPL_ASND_SDO_COMMAND_READ_MULTIPLE_PARAMETER_BY_INDEX,
&epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size);
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
objectcnt = 0;
dataoffset = offset;
while ( remlength > 0 )
{
guint16 sod_index = error;
if ((tvb_get_guint8 ( tvb, offset + 3 ) & 0x80) == 0x80)
is_abort = TRUE;
psf_od_tree = proto_tree_add_subtree(epl_tree, tvb, offset, 8, 0, NULL , "OD");
if (segmented <= EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
idx = tvb_get_letohs(tvb, dataoffset);
index_str = rval_to_str_const(idx, sod_cmd_str, "unknown");
sod_index = str_to_val(index_str, sod_cmd_str_val, error);
sub_index_str = val_to_str_ext_const(idx, &sod_cmd_no_sub, "unknown");
nosub = str_to_val(sub_index_str, sod_cmd_str_no_sub,error);
if (objectcnt < 8)
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%04X", idx);
else
col_append_str(pinfo->cinfo, COL_INFO, ".");
if (sod_index != error)
idx = sod_index;
proto_tree_add_uint_format(psf_od_tree, hf_epl_asnd_sdo_cmd_data_mapping_index, tvb, dataoffset, 2, idx,"Index: 0x%04X", idx);
proto_item_append_text(psf_od_tree, " Idx: 0x%04X", idx);
dataoffset += 2;
subindex = tvb_get_guint8(tvb, dataoffset);
proto_item_append_text(psf_od_tree, " SubIdx: 0x%02X", subindex);
proto_tree_add_uint_format(psf_od_tree, hf_epl_asnd_sdo_cmd_data_mapping_subindex, tvb, dataoffset, 1, idx,"SubIndex: 0x%02X", subindex);
if (objectcnt < 8)
{
if (nosub)
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
else
col_append_fstr(pinfo->cinfo, COL_INFO, "/%d)", subindex);
}
dataoffset += 1;
proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_sub_abort, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
dataoffset += 1;
if (is_abort)
{
abort_code = tvb_get_letohl(tvb, dataoffset);
proto_item_append_text(psf_od_tree, " - %s", "Aborted");
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_sdo_multi_param_sub_abort, tvb, dataoffset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item," (%s)", val_to_str_ext_const(abort_code, &sdo_cmd_abort_code_ext, "Unknown"));
is_abort = FALSE;
}
objectcnt++;
}
offset += 8;
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d)", objectcnt);
}
return offset;
}
static gint
dissect_epl_sdo_command_read_multiple_by_index(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 segmented, gboolean response, guint16 segment_size)
{
gint dataoffset;
guint8 subindex = 0x00, padding = 0x00;
guint16 idx = 0x00, error = 0xFF, sub_val = 0x00;
gboolean nosub = FALSE;
guint32 size, offsetincrement, datalength, remlength, objectcnt, abort_code;
gboolean lastentry = FALSE, is_abort = FALSE;
const gchar *index_str, *sub_str, *sub_index_str;
proto_item *psf_item, *psf_od_item;
proto_tree *psf_tree, *psf_od_tree;
struct object *obj = NULL;
struct subobject *subobj = NULL;
const char *name;
if (response)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%d]:",
val_to_str_ext(EPL_ASND_SDO_COMMAND_READ_MULTIPLE_PARAMETER_BY_INDEX,
&epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size);
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
objectcnt = 0;
while ( !lastentry && remlength > 0 )
{
guint16 sod_index = error;
offsetincrement = tvb_get_letohl(tvb, offset);
padding = tvb_get_guint8 ( tvb, offset + 7 ) & 0x03;
if ((tvb_get_guint8 ( tvb, offset + 7 ) & 0x80) == 0x80)
is_abort = TRUE;
datalength = offsetincrement - ( offset - EPL_SOA_EPLV_OFFSET );
if ( offsetincrement == 0 )
datalength = remlength - EPL_SOA_EPLV_OFFSET;
if ( ( datalength + EPL_SOA_EPLV_OFFSET ) > remlength )
break;
if ( offsetincrement == 0 )
{
datalength = remlength;
if ( remlength < EPL_SOA_EPLV_OFFSET )
break;
size = remlength - EPL_SOA_EPLV_OFFSET;
lastentry = TRUE;
}
else
{
if ( (guint32)( padding + 8 ) >= datalength )
break;
size = datalength - 8 - padding;
}
dataoffset = offset + 4;
psf_od_tree = proto_tree_add_subtree(epl_tree, tvb, offset+4, 4+size, 0, NULL , "OD");
if (segmented <= EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
idx = tvb_get_letohs(tvb, dataoffset);
obj = object_lookup(convo->profile, idx);
if (!obj)
{
index_str = rval_to_str_const(idx, sod_cmd_str, "unknown");
sod_index = str_to_val(index_str, sod_cmd_str_val, error);
sub_index_str = val_to_str_ext_const(idx, &sod_cmd_no_sub, "unknown");
nosub = str_to_val(sub_index_str, sod_cmd_str_no_sub, 0xFF) != 0xFF;
}
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
if(obj)
{
proto_item_append_text(psf_item, " (%s)", obj->info.name);
nosub = obj->info.type_class == OD_ENTRY_SCALAR;
}
else if(sod_index == error)
{
proto_item_append_text(psf_item," (%s)", val_to_str_ext_const(((guint32)(idx<<16)), &sod_index_names, "User Defined"));
}
else
{
proto_item_append_text(psf_item," (%s", val_to_str_ext_const(((guint32)(sod_index<<16)), &sod_index_names, "User Defined"));
proto_item_append_text(psf_item,"_%02Xh", (idx-sod_index));
if(sod_index == EPL_SOD_PDO_RX_MAPP || sod_index == EPL_SOD_PDO_TX_MAPP)
{
proto_item_append_text(psf_item,"_AU64)");
}
else
{
proto_item_append_text(psf_item,"_REC)");
}
}
if (objectcnt < 8)
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%04X", idx);
else
col_append_str(pinfo->cinfo, COL_INFO, ".");
if (sod_index != error)
idx = sod_index;
proto_item_append_text(psf_od_tree, " Idx: 0x%04X", idx);
dataoffset += 2;
subindex = tvb_get_guint8(tvb, dataoffset);
subobj = subobject_lookup(obj, subindex);
proto_item_append_text(psf_od_tree, " SubIdx: 0x%02X", subindex);
sub_str = val_to_str_ext_const(idx, &sod_cmd_sub_str, "unknown");
sub_val = str_to_val(sub_str, sod_cmd_sub_str_val,error);
if(sub_val != error)
idx = sub_val;
if (subobj)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", subobj->info.name);
}
else if(idx == EPL_SOD_STORE_PARAM && subindex <= 0x7F && subindex >= 0x04)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ManufacturerParam_%02Xh_U32)", subindex);
}
else if(idx == EPL_SOD_RESTORE_PARAM && subindex <= 0x7F && subindex >= 0x04)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ManufacturerParam_%02Xh_U32)", subindex);
}
else if(idx == EPL_SOD_PDO_RX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ObjectMapping)");
}
else if(idx == EPL_SOD_PDO_TX_MAPP && subindex >= 0x01 && subindex <= 0xfe)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (ObjectMapping)");
}
else if(subindex == 0x00)
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (NumberOfEntries)");
}
else
{
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, dataoffset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item, " (%s)", val_to_str_ext_const((subindex | (idx << 16)), &sod_index_names, "User Defined"));
}
if (objectcnt < 8)
{
if (nosub)
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
else
col_append_fstr(pinfo->cinfo, COL_INFO, "/%d)", subindex);
}
dataoffset += 1;
proto_tree_add_uint(psf_od_tree, hf_epl_asnd_sdo_cmd_data_padding, tvb, dataoffset, 1, padding);
dataoffset += 1;
objectcnt++;
}
if (is_abort)
{
proto_tree_add_item(psf_od_tree, hf_epl_asnd_sdo_cmd_sub_abort, tvb, dataoffset - 1, 1, ENC_LITTLE_ENDIAN);
abort_code = tvb_get_letohl(tvb, dataoffset);
proto_item_append_text(psf_od_tree, " - %s", "Aborted");
psf_item = proto_tree_add_item(psf_od_tree, hf_epl_sdo_multi_param_sub_abort, tvb, dataoffset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(psf_item," (%s)", val_to_str_ext_const(abort_code, &sdo_cmd_abort_code_ext, "Unknown"));
is_abort = FALSE;
}
else
{
if((idx == EPL_SOD_PDO_TX_MAPP && subindex > 0x00) ||(idx == EPL_SOD_PDO_RX_MAPP && subindex > 0x00))
{
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_mapping, tvb, dataoffset, 1, ENC_NA);
psf_tree = proto_item_add_subtree(psf_item, ett_epl_asnd_sdo_cmd_data_mapping);
idx = tvb_get_letohs(tvb, dataoffset);
proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_index, tvb, dataoffset, 2, idx,"Index: 0x%04X", idx);
dataoffset += 2;
idx = tvb_get_letohs(tvb, dataoffset);
proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_subindex, tvb, dataoffset, 1, idx,"SubIndex: 0x%02X", idx);
dataoffset += 2;
idx = tvb_get_letohs(tvb, dataoffset);
proto_tree_add_uint_format(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_offset, tvb, dataoffset, 2, idx,"Offset: 0x%04X", idx);
dataoffset += 2;
proto_tree_add_item(psf_tree, hf_epl_asnd_sdo_cmd_data_mapping_length, tvb, dataoffset, 2, ENC_LITTLE_ENDIAN);
}
else
{
const struct epl_datatype *type = NULL;
if (subobj)
type = subobj->info.type;
else if (obj)
type = obj->info.type;
dissect_epl_payload ( psf_od_tree, tvb, pinfo, dataoffset, size, type, EPL_ASND);
}
}
offset += datalength;
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d)", objectcnt);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "Request %s[%d]:",
val_to_str_ext(EPL_ASND_SDO_COMMAND_READ_MULTIPLE_PARAMETER_BY_INDEX,
&epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size);
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
objectcnt = 0;
dataoffset = offset;
while ( remlength > 0 )
{
guint16 sod_index = error;
proto_tree *psf_entry;
psf_od_item = proto_tree_add_subtree(epl_tree, tvb, offset, 4, 0, NULL, "OD");
if (segmented <= EPL_ASND_SDO_CMD_SEGMENTATION_INITIATE_TRANSFER)
{
idx = tvb_get_letohs(tvb, dataoffset);
obj = object_lookup(convo->profile, idx);
if (!obj)
{
index_str = rval_to_str_const(idx, sod_cmd_str, "unknown");
sod_index = str_to_val(index_str, sod_cmd_str_val, error);
sub_index_str = val_to_str_ext_const(idx, &sod_cmd_no_sub, "unknown");
nosub = str_to_val(sub_index_str, sod_cmd_str_no_sub,0xFF) != 0xFF;
}
if (objectcnt < 8)
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%04X", idx);
else
col_append_str(pinfo->cinfo, COL_INFO, ".");
if (sod_index != error)
idx = sod_index;
proto_item_append_text(psf_od_item, " Idx: 0x%04X", idx);
psf_entry = proto_tree_add_uint_format(psf_od_item, hf_epl_asnd_sdo_cmd_data_mapping_index, tvb, dataoffset, 2, idx,"Index: 0x%04X", idx);
if(obj)
{
proto_item_append_text(psf_entry, " (%s)", obj->info.name);
nosub = obj->info.type_class == OD_ENTRY_SCALAR;
}
else if(sod_index == error)
{
name = obj ? obj->info.name :val_to_str_ext_const(((guint32)(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_entry," (%s)", name);
}
else
{
proto_item_append_text(psf_entry," (%s", val_to_str_ext_const(((guint32)(sod_index<<16)), &sod_index_names, "User Defined"));
proto_item_append_text(psf_entry,"_%02Xh", (idx-sod_index));
if(sod_index == EPL_SOD_PDO_RX_MAPP || sod_index == EPL_SOD_PDO_TX_MAPP)
{
proto_item_append_text(psf_entry,"_AU64)");
}
else
{
proto_item_append_text(psf_entry,"_REC)");
}
}
dataoffset += 2;
subindex = tvb_get_guint8(tvb, dataoffset);
proto_item_append_text(psf_od_item, " SubIdx: 0x%02X", subindex);
psf_item = proto_tree_add_uint_format(psf_od_item, hf_epl_asnd_sdo_cmd_data_mapping_subindex, tvb, dataoffset, 1, subindex,"SubIndex: 0x%02X", subindex);
subobj = subobject_lookup(obj, subindex);
name = subobj ? subobj->info.name
: val_to_str_ext_const((subindex|(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_item, " (%s)", name);
if (objectcnt < 8)
{
if (nosub)
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
else
col_append_fstr(pinfo->cinfo, COL_INFO, "/%d)", subindex);
}
dataoffset += 2;
objectcnt++;
}
offset += 4;
remlength = (guint32)tvb_reported_length_remaining(tvb, offset);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d)", objectcnt);
}
return offset;
}
static gint
dissect_epl_sdo_command_read_by_index(struct epl_convo *convo, proto_tree *epl_tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 segmented, gboolean response, guint16 segment_size)
{
gint size, payload_length;
guint16 idx = 0x00;
guint8 subindex = 0x00;
guint32 fragmentId, frame;
proto_item *psf_item, *cmd_payload;
proto_tree *payload_tree;
gboolean end_segment = FALSE;
fragment_head *frag_msg = NULL;
struct object *obj = NULL;
struct subobject *subobj = NULL;
struct read_req *req;
const struct epl_datatype *type = NULL;
frame = pinfo->num;
if (!response)
{
const char *name;
idx = tvb_get_letohs(tvb, offset);
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
obj = object_lookup(convo->profile, idx);
name = obj ? obj->info.name : val_to_str_ext_const(((guint32)(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_item," (%s)", name);
offset += 2;
subindex = tvb_get_guint8(tvb, offset);
psf_item = proto_tree_add_item(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
subobj = subobject_lookup(obj, subindex);
name = subobj ? subobj->info.name
: val_to_str_ext_const((subindex|(idx<<16)), &sod_index_names, "User Defined");
proto_item_append_text(psf_item, " (%s)", name);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%d]: (0x%04X/%d)",
val_to_str_ext(EPL_ASND_SDO_COMMAND_READ_BY_INDEX, &epl_sdo_asnd_commands_short_ext, "Command(%02X)"),
segment_size, idx, subindex);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s", val_to_str_ext_const(((guint32) (idx << 16)), &sod_index_names, "User Defined"));
col_append_fstr(pinfo->cinfo, COL_INFO, "/%s)",val_to_str_ext_const((subindex|(idx<<16)), &sod_index_names, "User Defined"));
req = convo_read_req_set(convo, convo->seq_send);
req->idx = idx;
req->subindex = subindex;
if (obj)
{
req->info = subobj ? &subobj->info : &obj->info;
req->index_name = obj->info.name;
}
else
{
req->info = NULL;
req->index_name = NULL;
}
}
else
{
if(segmented > 0x01 && segment_size != 0)
{
fragmentId = (guint32)((((guint32)epl_segmentation.src)<<16)+epl_segmentation.dest);
pinfo->fragmented = TRUE;
payload_length = tvb_reported_length_remaining(tvb, offset);
if(segmented == EPL_ASND_SDO_CMD_SEGMENTATION_TRANSFER_COMPLETE)
end_segment = TRUE;
if(epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv][epl_segmentation.send] == 0x00 ||
epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv][epl_segmentation.send] == frame)
{
if (epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv][epl_segmentation.send] == 0x00)
count += 1;
epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv][epl_segmentation.send] = frame;
if (first_read)
{
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, 0, payload_length, end_segment ? FALSE : TRUE );
fragment_add_seq_offset(&epl_reassembly_table, pinfo, fragmentId, NULL, count);
first_read = FALSE;
}
else
{
frag_msg = fragment_add_seq_check(&epl_reassembly_table, tvb, offset, pinfo,
fragmentId, NULL, count, payload_length, end_segment ? FALSE : TRUE );
}
}
if(frag_msg != NULL && (epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv][epl_segmentation.send] == frame))
{
if(end_segment || payload_length > 0)
{
cmd_payload = proto_tree_add_uint_format(epl_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, offset, payload_length,0,
"Reassembled: %d bytes total (%d bytes in this frame)",frag_msg->len,payload_length);
payload_tree = proto_item_add_subtree(cmd_payload, ett_epl_asnd_sdo_data_reassembled);
process_reassembled_data(tvb, 0, pinfo, "Reassembled Message", frag_msg, &epl_frag_items, NULL, payload_tree );
proto_tree_add_uint_format_value(payload_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, 0, 0,
payload_length, "%d bytes (over all fragments)", frag_msg->len);
if (frag_msg->reassembled_in == frame)
col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled)" );
memset(&epl_asnd_sdo_reassembly_read.frame[epl_segmentation.recv], 0, sizeof(guint32) * EPL_MAX_SEQUENCE);
}
else
{
cmd_payload = proto_tree_add_uint_format(epl_tree, hf_epl_asnd_sdo_cmd_reassembled, tvb, offset, payload_length,0,
"Reassembled: %d bytes total (%d bytes in this frame)",frag_msg->len,payload_length);
payload_tree = proto_item_add_subtree(cmd_payload, ett_epl_asnd_sdo_data_reassembled);
process_reassembled_data(tvb, 0, pinfo, "Reassembled Message", frag_msg, &epl_frag_items, NULL, payload_tree );
}
first_read = TRUE;
count = 0;
}
}
col_append_str(pinfo->cinfo, COL_INFO, "Response");
size = tvb_reported_length_remaining(tvb, offset);
if ((req = convo_read_req_get(convo, pinfo, convo->seq_send)))
{
proto_item *ti;
ti = proto_tree_add_uint_format_value(epl_tree, hf_epl_asnd_sdo_cmd_data_index, tvb, 0, 0, req->idx, "%04X", req->idx);
PROTO_ITEM_SET_GENERATED(ti);
if (req->info)
{
proto_item_append_text (ti, " (%s)", req->index_name);
type = req->info->type;
}
ti = proto_tree_add_uint_format_value(epl_tree, hf_epl_asnd_sdo_cmd_data_subindex, tvb, 0, 0, req->subindex, "%02X", req->subindex);
PROTO_ITEM_SET_GENERATED(ti);
if (req->info && req->info->name != req->index_name)
proto_item_append_text (ti, " (%s)", req->info->name);
}
offset = dissect_epl_payload(epl_tree, tvb, pinfo, offset, size, type, EPL_ASND);
}
return offset;
}
static struct profile *profile_load(wmem_allocator_t *allocator, const char *path)
{
struct profile *profile = NULL;
char *err;
if (!epl_profile_uat_fld_fileopen_check_cb(NULL, path, (unsigned)strlen(path), NULL, NULL, &err))
{
report_failure("%s", err);
g_free(err);
return NULL;
}
if (g_str_has_suffix(path, ".eds"))
{
profile = profile_new(allocator);
if (!epl_eds_load(profile, path))
profile_del(profile);
}
#if HAVE_LIBXML2
else if (g_str_has_suffix(path, ".xdd") || g_str_has_suffix(path, ".xdc"))
{
profile = profile_new(allocator);
if (!epl_xdd_load(profile, path))
profile_del(profile);
}
#endif
if (!profile)
report_failure("Profile '%s' couldn't be parsed", path);
return profile;
}
static void apply_prefs(void)
{
if (epl_default_profile_path != epl_default_profile_path_last
&& epl_default_profile_path && *epl_default_profile_path)
{
profile_del(epl_default_profile);
epl_default_profile = profile_load(wmem_epan_scope(), epl_default_profile_path);
epl_default_profile_path_last = epl_default_profile_path;
}
}
void
proto_register_epl(void)
{
static hf_register_info hf[] = {
{ &hf_epl_mtyp,
{ "MessageType", "epl.mtyp",
FT_UINT8, BASE_DEC, VALS(mtyp_vals), 0x7F, NULL, HFILL }
},
{ &hf_epl_node,
{ "Node", "epl.node",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_dest,
{ "Destination", "epl.dest",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_src,
{ "Source", "epl.src",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_payload_real,
{ "Captured Size", "epl.payload.capture_size",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soc,
{ "Flags", "epl.soc",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_soc_mc,
{ "MC (Multiplexed Cycle Completed)", "epl.soc.mc",
FT_BOOLEAN, 8, NULL, EPL_SOC_MC_MASK, NULL, HFILL }
},
{ &hf_epl_soc_ps,
{ "PS (Prescaled Slot)", "epl.soc.ps",
FT_BOOLEAN, 8, NULL, EPL_SOC_PS_MASK, NULL, HFILL }
},
{ &hf_epl_soc_nettime,
{ "NetTime", "epl.soc.nettime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_soc_relativetime,
{ "RelativeTime", "epl.soc.relativetime",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_preq,
{ "Flags", "epl.preq",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_preq_ms,
{ "MS (Multiplexed Slot)", "epl.preq.ms",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_epl_preq_ea,
{ "EA (Exception Acknowledge)", "epl.preq.ea",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_epl_preq_rd,
{ "RD (Ready)", "epl.preq.rd",
FT_BOOLEAN, 8, NULL, EPL_PDO_RD_MASK, NULL, HFILL }
},
{ &hf_epl_preq_pdov,
{ "PDOVersion", "epl.preq.pdov",
FT_UINT8, BASE_CUSTOM, CF_FUNC(elp_version), 0x00, NULL, HFILL }
},
{ &hf_epl_preq_size,
{ "Size", "epl.preq.size",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_pres_stat_ms,
{ "NMTStatus", "epl.pres.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_ms_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_pres_stat_cs,
{ "NMTStatus", "epl.pres.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_cs_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_pres,
{ "Flags", "epl.pres",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_pres_ms,
{ "MS (Multiplexed Slot)", "epl.pres.ms",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_epl_pres_en,
{ "EN (Exception New)", "epl.pres.en",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_pres_rd,
{ "RD (Ready)", "epl.pres.rd",
FT_BOOLEAN, 8, NULL, EPL_PDO_RD_MASK, NULL, HFILL }
},
{ &hf_epl_pres_pr,
{ "PR (Priority)", "epl.pres.pr",
FT_UINT8, BASE_DEC, VALS(epl_pr_vals), 0x38, NULL, HFILL }
},
{ &hf_epl_pres_rs,
{ "RS (RequestToSend)", "epl.pres.rs",
FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }
},
{ &hf_epl_pres_pdov,
{ "PDOVersion", "epl.pres.pdov",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_pres_size,
{ "Size", "epl.pres.size",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_stat_ms,
{ "NMTStatus", "epl.soa.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_ms_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_soa_stat_cs,
{ "NMTStatus", "epl.soa.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_cs_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_soa_ea,
{ "EA (Exception Acknowledge)", "epl.soa.ea",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_epl_soa_er,
{ "ER (Exception Reset)", "epl.soa.er",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }
},
{ &hf_epl_soa_svid,
{ "RequestedServiceID", "epl.soa.svid",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(soa_svid_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_soa_svtg,
{ "RequestedServiceTarget", "epl.soa.svtg",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_eplv,
{ "EPLVersion", "epl.soa.eplv",
FT_UINT8, BASE_CUSTOM, CF_FUNC(elp_version), 0x00, NULL, HFILL }
},
{ &hf_epl_soa_sync,
{ "SyncControl", "epl.soa.sync",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_mac,
{ "DestMacAddressValid", "epl.soa.adva",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_MAC_VALID, NULL, HFILL }
},
{ &hf_epl_soa_pre_tm,
{ "PResFallBackTimeoutValid", "epl.soa.tm",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_PRES_TIMEOUT, NULL, HFILL }
},
{ &hf_epl_soa_mnd_sec,
{ "SyncMNDelaySecondValid", "epl.soa.mnsc",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_MND_SECOND, NULL, HFILL }
},
{ &hf_epl_soa_mnd_fst,
{ "SyncMNDelayFirstValid", "epl.soa.mnft",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_MND_FIRST, NULL, HFILL }
},
{ &hf_epl_soa_pre_sec,
{ "PResTimeSecondValid", "epl.soa.prsc",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_PRES_SECOND, NULL, HFILL }
},
{ &hf_epl_soa_pre_fst,
{ "PResTimeFirstValid", "epl.soa.prft",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_PRES_FIRST, NULL, HFILL }
},
{ &hf_epl_soa_pre_set ,
{ "PResModeSet", "epl.soa.prmst",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_PRES_SET, NULL, HFILL }
},
{ &hf_epl_soa_pre_res,
{ "PResModeReset", "epl.soa.prmrst",
FT_BOOLEAN, 8, NULL, EPL_SOA_SYNC_PRES_RESET, NULL, HFILL }
},
{ &hf_epl_soa_mac_end,
{ "DestMacAddress", "epl.soa.adva.end",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_soa_pre_tm_end,
{ "PResFallBackTimeoutValid", "epl.soa.tm.end",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_mnd_sec_end,
{ "SyncMNDelaySecondValid", "epl.soa.mnsc.end",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_mnd_fst_end,
{ "SyncMNDelayFirstValid", "epl.soa.mnft.end",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_pre_sec_end,
{ "PResTimeSecondValid", "epl.soa.prsc.end",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_pre_fst_end,
{ "PResTimeFirstValid", "epl.soa.prft.end",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_soa_dna_an_glb,
{ "AN (Global)", "epl.soa.an.global",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_epl_soa_dna_an_lcl,
{ "AN (Local)", "epl.soa.an.local",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_asnd_svid,
{ "Requested Service ID", "epl.asnd.svid",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(asnd_svid_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_svtg,
{ "Requested Service Target", "epl.asnd.svtg",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_epl_asnd_data,
{ "Data", "epl.asnd.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_epl_asnd_identresponse_en,
{ "EN (Exception New)", "epl.asnd.ires.en",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_ec,
{ "EC (Exception Clear)", "epl.asnd.ires.ec",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_pr,
{ "PR (Priority)", "epl.asnd.ires.pr",
FT_UINT8, BASE_DEC, VALS(epl_pr_vals), 0x38, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_rs,
{ "RS (RequestToSend)", "epl.asnd.ires.rs",
FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_stat_ms,
{ "NMTStatus", "epl.asnd.ires.state",
FT_UINT8, BASE_HEX, VALS(epl_nmt_ms_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_stat_cs,
{ "NMTStatus", "epl.asnd.ires.state",
FT_UINT8, BASE_HEX, VALS(epl_nmt_cs_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_ever,
{ "EPLVersion", "epl.asnd.ires.eplver",
FT_UINT8, BASE_CUSTOM, CF_FUNC(elp_version), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat,
{ "FeatureFlags", "epl.asnd.ires.features",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit0,
{ "Isochronous", "epl.asnd.ires.features.bit0",
FT_BOOLEAN, 32, NULL, 0x0001, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit1,
{ "SDO by UDP/IP", "epl.asnd.ires.features.bit1",
FT_BOOLEAN, 32, NULL, 0x0002, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit2,
{ "SDO by ASnd", "epl.asnd.ires.features.bit2",
FT_BOOLEAN, 32, NULL, 0x0004, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit3,
{ "SDO by PDO", "epl.asnd.ires.features.bit3",
FT_BOOLEAN, 32, NULL, 0x0008, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit4,
{ "NMT Info Services", "epl.asnd.ires.features.bit4",
FT_BOOLEAN, 32, NULL, 0x0010, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit5,
{ "Ext. NMT State Commands", "epl.asnd.ires.features.bit5",
FT_BOOLEAN, 32, NULL, 0x0020, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit6,
{ "Dynamic PDO Mapping", "epl.asnd.ires.features.bit6",
FT_BOOLEAN, 32, NULL, 0x0040, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit7,
{ "NMT Service by UDP/IP", "epl.asnd.ires.features.bit7",
FT_BOOLEAN, 32, NULL, 0x0080, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit8,
{ "Configuration Manager", "epl.asnd.ires.features.bit8",
FT_BOOLEAN, 32, NULL, 0x0100, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit9,
{ "Multiplexed Access", "epl.asnd.ires.features.bit9",
FT_BOOLEAN, 32, NULL, 0x0200, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitA,
{ "NodeID setup by SW", "epl.asnd.ires.features.bitA",
FT_BOOLEAN, 32, NULL, 0x0400, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitB,
{ "MN Basic Ethernet Mode", "epl.asnd.ires.features.bitB",
FT_BOOLEAN, 32, NULL, 0x0800, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitC,
{ "Routing Type 1 Support", "epl.asnd.ires.features.bitC",
FT_BOOLEAN, 32, NULL, 0x1000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitD,
{ "Routing Type 2 Support", "epl.asnd.ires.features.bitD",
FT_BOOLEAN, 32, NULL, 0x2000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitE,
{ "SDO Read/Write All", "epl.asnd.ires.features.bitE",
FT_BOOLEAN, 32, NULL, 0x4000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bitF,
{ "SDO Read/Write Multiple", "epl.asnd.ires.features.bitF",
FT_BOOLEAN, 32, NULL, 0x8000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit10,
{ "Multiple-ASend Support", "epl.asnd.ires.features.bit10",
FT_BOOLEAN, 32, NULL, 0x10000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit11,
{ "Ring Redundancy", "epl.asnd.ires.features.bit11",
FT_BOOLEAN, 32, NULL, 0x20000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit12,
{ "PResChaining", "epl.asnd.ires.features.bit12",
FT_BOOLEAN, 32, NULL, 0x40000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit13,
{ "Multiple PReq/PRes", "epl.asnd.ires.features.bit13",
FT_BOOLEAN, 32, NULL, 0x80000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_feat_bit14,
{ "Dynamic Node Allocation", "epl.asnd.ires.features.bit14",
FT_BOOLEAN, 32, NULL, 0x100000, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_mtu,
{ "MTU", "epl.asnd.ires.mtu",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_pis,
{ "PollInSize", "epl.asnd.ires.pollinsize",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_pos,
{ "PollOutSize", "epl.asnd.ires.polloutsizes",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_rst,
{ "ResponseTime", "epl.asnd.ires.resptime",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_dt,
{ "DeviceType", "epl.asnd.ires.devicetype",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_dt_add,
{ "DeviceType additional info", "epl.asnd.ires.devicetype.add",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_profile_path,
{ "Profile Path", "epl.asnd.ires.profilepath",
FT_STRING, STR_UNICODE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_vid,
{ "VendorId", "epl.asnd.ires.vendorid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_productcode,
{ "ProductCode", "epl.asnd.ires.productcode",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_rno,
{ "RevisionNumber", "epl.asnd.ires.revisionno",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_sno,
{ "SerialNumber", "epl.asnd.ires.serialno",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_vex1,
{ "VendorSpecificExtension1", "epl.asnd.ires.vendorext1",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_vcd,
{ "VerifyConfigurationDate", "epl.asnd.ires.confdate",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_vct,
{ "VerifyConfigurationTime", "epl.asnd.ires.conftime",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_ad,
{ "ApplicationSwDate", "epl.asnd.ires.appswdate",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_at,
{ "ApplicationSwTime", "epl.asnd.ires.appswtime",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_ipa,
{ "IPAddress", "epl.asnd.ires.ip",
FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_snm,
{ "SubnetMask", "epl.asnd.ires.subnet",
FT_IPv4, BASE_NETMASK, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_gtw,
{ "DefaultGateway", "epl.asnd.ires.gateway",
FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_hn,
{ "HostName", "epl.asnd.ires.hostname",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_identresponse_vex2,
{ "VendorSpecificExtension2", "epl.asnd.ires.vendorext2",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_en,
{ "EN (Exception New)", "epl.asnd.sres.en",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_ec,
{ "EC (Exception Clear)", "epl.asnd.sres.ec",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_pr,
{ "PR (Priority)", "epl.asnd.sres.pr",
FT_UINT8, BASE_DEC, VALS(epl_pr_vals), 0x38, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_rs,
{ "RS (RequestToSend)", "epl.asnd.sres.rs",
FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_stat_ms,
{ "NMTStatus", "epl.asnd.sres.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_ms_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_stat_cs,
{ "NMTStatus", "epl.asnd.sres.stat",
FT_UINT8, BASE_HEX, VALS(epl_nmt_cs_vals), 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_sync,
{ "SyncResponse", "epl.asnd.syncresponse.sync",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_fst_val,
{ "PResTimeFirstValid", "epl.asnd.syncresponse.fst.val",
FT_BOOLEAN, 8, NULL, EPL_ASND_SYNCRESPONSE_FST_VALID, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_sec_val,
{ "PResTimeSecondValid", "epl.asnd.syncresponse.sec.val",
FT_BOOLEAN, 8, NULL, EPL_ASND_SYNCRESPONSE_SEC_VALID, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_mode,
{ "PResModeStatus", "epl.asnd.syncresponse.mode",
FT_BOOLEAN, 8, NULL, EPL_ASND_SYNCRESPONSE_MODE, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_latency,
{ "Latency", "epl.asnd.syncresponse.latency",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_node,
{ "SyncDelayStation", "epl.asnd.syncresponse.delay.station",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_delay,
{ "SyncDelay", "epl.asnd.syncresponse.delay",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_pre_fst,
{ "PResTimeFirst", "epl.asnd.syncresponse.pres.fst",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_syncResponse_pre_sec,
{ "PResTimeSecond", "epl.asnd.syncresponse.pres.sec",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_epl_asnd_statusresponse_seb,
{ "StaticErrorBitField", "epl.asnd.sres.seb",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit0,
{ "Generic error", "epl.asnd.res.seb.bit0",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit1,
{ "Current", "epl.asnd.res.seb.bit1",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit2,
{ "Voltage", "epl.asnd.res.seb.bit2",
FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit3,
{ "Temperature", "epl.asnd.res.seb.bit3",
FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit4,
{ "Communication error", "epl.asnd.res.seb.bit4",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit5,
{ "Device Profile Spec", "epl.asnd.res.seb.bit5",
FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_err_errorregister_u8_bit7,
{ "Manufacturer Spec", "epl.asnd.res.seb.bit7",
FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_seb_devicespecific_err,
{ "Device Profile Spec", "epl.asnd.res.seb.devicespecific_err",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_epl_asnd_statusresponse_el,
{ "ErrorCodesList", "epl.asnd.sres.el",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry,
{ "Entry", "epl.asnd.sres.el.entry",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_epl_asnd_statusresponse_el_entry_type,
{ "Entry Type", "epl.asnd.sres.el.entry.type",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_type_profile,
{ "Profile", "epl.asnd.sres.el.entry.type.profile",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_type_mode,
{ "Mode", "epl.asnd.sres.el.entry.type.mode",
FT_UINT16, BASE_DEC, NULL, 0x3000, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_type_bit14,
{ "Bit14", "epl.asnd.sres.el.entry.type.bit14",
FT_UINT16, BASE_DEC, NULL, 0x4000, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_type_bit15,
{ "Bit15", "epl.asnd.sres.el.entry.type.bit15",
FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_code,
{ "Error Code", "epl.asnd.sres.el.entry.code",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_time,
{ "Time Stamp", "epl.asnd.sres.el.entry.time",
FT_UINT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_statusresponse_el_entry_add,
{ "Additional Information", "epl.asnd.sres.el.entry.add",
FT_UINT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtrequest_rcid,
{ "NMTRequestedCommandID", "epl.asnd.nmtrequest.rcid",
FT_UINT8, BASE_HEX_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtrequest_rct,
{ "NMTRequestedCommandTarget", "epl.asnd.nmtrequest.rct",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtrequest_rcd,
{ "NMTRequestedCommandData", "epl.asnd.nmtrequest.rcd",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_cid,
{ "NMTCommandId", "epl.asnd.nmtcommand.cid",
FT_UINT8, BASE_HEX_DEC | BASE_EXT_STRING,
&asnd_cid_vals_ext, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_resetnode_reason,
{ "Reset Reason", "epl.asnd.nmtcommand.resetnode_reason",
FT_UINT16, BASE_HEX | BASE_EXT_STRING,
&errorcode_vals_ext, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_cdat,
{ "NMTCommandData", "epl.asnd.nmtcommand.cdat",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtnethostnameset_hn,
{ "HostName", "epl.asnd.nmtcommand.nmtnethostnameset.hn",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtflusharpentry_nid,
{ "NodeID", "epl.asnd.nmtcommand.nmtflusharpentry.nid",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtpublishtime_dt,
{ "DateTime", "epl.asnd.nmtcommand.nmtpublishtime.dt",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna,
{ "DNA", "epl.asnd.nmtcommand.dna",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_flags,
{ "Valid flags", "epl.asnd.nmtcommand.dna.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_ltv,
{ "Lease time valid", "epl.asnd.nmtcommand.dna.ltv",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_hpm,
{ "Hub port enable mask valid", "epl.asnd.nmtcommand.dna.hpm",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_nnn,
{ "Set new node number", "epl.asnd.nmtcommand.dna.nnn",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_mac,
{ "Compare current MAC ID", "epl.asnd.nmtcommand.dna.mac",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_cnn,
{ "Compare current node number", "epl.asnd.nmtcommand.dna.cnn",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_currmac,
{ "Current MAC ID", "epl.asnd.nmtcommand.dna.currmac",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_hubenmsk,
{ "Hub port enable mask", "epl.asnd.nmtcommand.dna.hubenmsk",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_currnn,
{ "Current node number", "epl.asnd.nmtcommand.dna.currnn",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_newnn,
{ "New node number", "epl.asnd.nmtcommand.dna.newnn",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_nmtcommand_nmtdna_leasetime,
{ "Lease Time", "epl.asnd.nmtcommand.dna.leasetime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_seq,
{ "Sequence Layer", "epl.asnd.sdo.seq",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_seq_receive_sequence_number,
{ "ReceiveSequenceNumber", "epl.asnd.sdo.seq.receive.sequence.number",
FT_UINT8, BASE_DEC, NULL, 0xfc, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_seq_receive_con,
{ "ReceiveCon", "epl.asnd.sdo.seq.receive.con",
FT_UINT8, BASE_DEC,
VALS(epl_sdo_receive_con_vals), 0x03, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_seq_send_sequence_number,
{ "SendSequenceNumber", "epl.asnd.sdo.seq.send.sequence.number",
FT_UINT8, BASE_DEC, NULL, 0xfc, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_seq_send_con,
{ "SendCon", "epl.asnd.sdo.seq.send.con",
FT_UINT8, BASE_DEC, VALS(epl_sdo_send_con_vals),
0x03, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_transaction_id,
{ "SDO Transaction ID", "epl.asnd.sdo.cmd.transaction.id",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_response,
{ "SDO Response", "epl.asnd.sdo.cmd.response",
FT_UINT8, BASE_DEC,
VALS(epl_sdo_asnd_cmd_response), 0x80, NULL, HFILL }
},
#if 0
{ &hf_epl_asnd_sdo_resp_in,
{ "Response frame", "epl.asnd.sdo.resp_in",
FT_FRAMENUM, BASE_NONE,
FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0,
"The frame number of the corresponding response", HFILL }
},
{ &hf_epl_asnd_sdo_no_resp,
{ "No response seen", "epl.asnd.sdo.no_resp",
FT_NONE, BASE_NONE,
NULL, 0x0,
"No corresponding response frame was seen", HFILL }
},
{ &hf_epl_asnd_sdo_resp_to,
{ "Request frame", "epl.asnd.sdo.resp_to",
FT_FRAMENUM, BASE_NONE,
FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0x0,
"The frame number of the corresponding request", HFILL }
},
#endif
{ &hf_epl_asnd_sdo_cmd,
{ "Command Layer", "epl.asnd.sdo.cmd",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_abort,
{ "SDO Abort", "epl.asnd.sdo.cmd.abort",
FT_UINT8, BASE_DEC,
VALS(epl_sdo_asnd_cmd_abort), 0x40, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_sub_abort,
{ "SDO Sub Transfer", "epl.asnd.sdo.cmd.sub.abort",
FT_UINT8, BASE_DEC,
VALS(epl_sdo_asnd_cmd_abort), 0x80, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_segmentation,
{ "SDO Segmentation", "epl.asnd.sdo.cmd.segmentation",
FT_UINT8, BASE_DEC,
VALS(epl_sdo_asnd_cmd_segmentation), 0x30, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_command_id,
{ "SDO Command ID", "epl.asnd.sdo.cmd.command.id",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&epl_sdo_asnd_commands_ext, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_segment_size,
{ "SDO Segment size", "epl.asnd.sdo.cmd.segment.size",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_size,
{ "SDO Data size", "epl.asnd.sdo.cmd.data.size",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_padding,
{ "SDO Data Padding", "epl.asnd.sdo.cmd.data.padding",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_abort_code,
{ "SDO Transfer Abort", "epl.asnd.sdo.cmd.abort.code",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&sdo_cmd_abort_code_ext, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_index,
{ "OD Index", "epl.asnd.sdo.cmd.data.index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_subindex,
{ "OD SubIndex", "epl.asnd.sdo.cmd.data.subindex",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_mapping,
{ "Mapping", "epl.asnd.sdo.cmd.data.mapping",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_mapping_index,
{ "Index", "epl.asnd.sdo.cmd.data.mapping.index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_mapping_subindex,
{ "SubIndex", "epl.asnd.sdo.cmd.data.mapping.subindex",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_mapping_offset,
{ "Offset", "epl.asnd.sdo.cmd.data.mapping.offset",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_data_mapping_length,
{ "Length", "epl.asnd.sdo.cmd.data.mapping.length",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragments,
{ "Message fragments", "epl.asnd.sdo.cmd.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment,
{ "Message fragment", "epl.asnd.sdo.cmd.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_overlap,
{ "Message fragment overlap", "epl.asnd.sdo.cmd.fragment.overlap",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"epl.asnd.sdo.cmd.fragment.overlap.conflicts",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_multiple_tails,
{ "Message has multiple tail fragments", "epl.asnd.sdo.cmd.fragment.multiple_tails",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_too_long_fragment,
{ "Message fragment too long", "epl.asnd.sdo.cmd.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_error,
{ "Message defragmentation error", "epl.asnd.sdo.cmd.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_fragment_count,
{ "Message fragment count", "epl.asnd.sdo.cmd.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_asnd_sdo_cmd_reassembled,
{ "Reassembled", "epl.asnd.sdo.cmd.reassembled",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_reassembled_in,
{ "Reassembled in", "epl.asnd.sdo.cmd.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_reassembled_length,
{ "Reassembled length", "epl.asnd.sdo.cmd.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_reassembled_data,
{ "Reassembled Data", "epl.asnd.sdo.cmd.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_sdo_multi_param_sub_abort,
{ "Sub Abort Code", "epl.asnd.sdo.od.multiparam.abort",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_pdo,
{ "PDO", "epl.pdo",
FT_STRING, STR_ASCII, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_pdo_index,
{ "Index", "epl.pdo.index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_pdo_subindex,
{ "SubIndex", "epl.pdo.subindex",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta,
{ "PDO meta info", "epl.od.meta",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_mapping_index,
{ "Mapped by index", "epl.od.meta.index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_mapping_subindex,
{ "Mapped by subindex", "epl.od.meta.subindex",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_lifetime_start,
{ "Lifetime start", "epl.od.meta.lifetime.start",
FT_FRAMENUM, FT_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_lifetime_end,
{ "Lifetime end", "epl.od.meta.lifetime.end",
FT_FRAMENUM, FT_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_offset,
{ "Offset", "epl.od.meta.offset",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_meta_length,
{ "Length", "epl.od.meta.length",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_boolean,
{ "Data", "epl.od.data.boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_int,
{ "Data", "epl.od.data.int",
FT_INT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_uint,
{ "Data", "epl.od.data.uint",
FT_UINT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_real,
{ "Data", "epl.od.data.real",
FT_FLOAT, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_string,
{ "Data", "epl.od.data.string",
FT_STRING, STR_UNICODE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_octet_string,
{ "Data", "epl.od.data.bytestring",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_mac,
{ "Data", "epl.od.data.ethaddr",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_ipv4,
{ "Data", "epl.od.data.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_epl_od_domain,
{ "Data", "epl.od.data.domain",
FT_BYTES, BASE_ALLOW_ZERO, NULL, 0x00, NULL, HFILL }
},
{ &hf_epl_od_time_difference,
{ "Data", "epl.od.data.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_epl_od_time,
{ "Data", "epl.od.data.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_epl,
&ett_epl_soc,
&ett_epl_preq,
&ett_epl_pres,
&ett_epl_feat,
&ett_epl_seb,
&ett_epl_el,
&ett_epl_el_entry,
&ett_epl_el_entry_type,
&ett_epl_sdo_entry_type,
&ett_epl_sdo,
&ett_epl_sdo_data,
&ett_epl_asnd_sdo_cmd_data_mapping,
&ett_epl_sdo_sequence_layer,
&ett_epl_sdo_command_layer,
&ett_epl_soa_sync,
&ett_epl_asnd_sync,
&ett_epl_fragment,
&ett_epl_fragments,
&ett_epl_asnd_sdo_data_reassembled,
&ett_epl_asnd_nmt_dna,
&ett_epl_pdo_meta
};
static ei_register_info ei[] = {
{ &ei_duplicated_frame,
{ "epl.asnd.sdo.duplication", PI_PROTOCOL, PI_NOTE,
"Duplicated Frame", EXPFILL }
},
{ &ei_recvseq_value,
{ "epl.error.value.receive.sequence", PI_PROTOCOL, PI_ERROR,
"Invalid Value for ReceiveSequenceNumber", EXPFILL }
},
{ &ei_sendseq_value,
{ "epl.error.value.send.sequence", PI_PROTOCOL, PI_ERROR,
"Invalid Value for SendSequenceNumber", EXPFILL }
},
{ &ei_recvcon_value,
{ "epl.error.receive.connection", PI_PROTOCOL, PI_ERROR,
"Invalid Value for ReceiveCon", EXPFILL }
},
{ &ei_sendcon_value,
{ "epl.error.send.connection", PI_PROTOCOL, PI_ERROR,
"Invalid Value for SendCon", EXPFILL }
},
{ &ei_real_length_differs,
{ "epl.error.payload.length.differs", PI_PROTOCOL, PI_ERROR,
"Captured length differs from header information", EXPFILL }
}
};
module_t *epl_module;
expert_module_t *expert_epl;
proto_epl = proto_register_protocol("Ethernet POWERLINK", "EPL", "epl");
heur_epl_subdissector_list = register_heur_dissector_list("epl", proto_epl);
heur_epl_data_subdissector_list = register_heur_dissector_list("epl_data", proto_epl);
epl_asnd_dissector_table = register_dissector_table("epl.asnd",
"Manufacturer specific ASND service", proto_epl, FT_UINT8, BASE_DEC );
epl_handle = register_dissector("epl", dissect_epl, proto_epl);
proto_register_field_array(proto_epl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_epl = expert_register_protocol ( proto_epl );
expert_register_field_array ( expert_epl, ei, array_length (ei ) );
epl_module = prefs_register_protocol(proto_epl, apply_prefs);
prefs_register_bool_preference(epl_module, "show_soc_flags", "Show flags of SoC frame in Info column",
"If you are capturing in networks with multiplexed or slow nodes, this can be useful", &show_soc_flags);
prefs_register_bool_preference(epl_module, "show_duplicated_command_layer", "Show command-layer in duplicated frames",
"For analysis purposes one might want to show the command layer even if the dissectore assumes a duplicated frame", &show_cmd_layer_for_duplicated);
prefs_register_bool_preference(epl_module, "show_pdo_meta_info", "Show life times and origin PDO Tx/Rx params for PDO entries",
"For analysis purposes one might want to see how long the current mapping has been active for and what OD write caused it", &show_pdo_meta_info);
prefs_register_bool_preference(epl_module, "use_sdo_mappings", "Use SDO ObjectMappings for PDO dissection",
"Partition PDOs according to ObjectMappings sent via SDO", &use_sdo_mappings);
#ifdef HAVE_LIBXML2
prefs_register_bool_preference(epl_module, "use_xdc_mappings", "Use XDC ObjectMappings for PDO dissection",
"If you want to parse the defaultValue (XDD) and actualValue (XDC) attributes for ObjectMappings in order to detect default PDO mappings, which may not be sent over SDO ", &use_xdc_mappings);
#endif
prefs_register_bool_preference(epl_module, "interpret_untyped_as_le", "Interpret short (<64bit) data as little endian integers",
"If a data field has untyped data under 8 byte long, interpret it as unsigned little endian integer and show decimal and hexadecimal representation thereof. Otherwise use stock data dissector", &interpret_untyped_as_le);
epl_profiles_by_device = wmem_map_new(wmem_epan_scope(), g_direct_hash, g_direct_equal);
epl_profiles_by_nodeid = wmem_map_new(wmem_epan_scope(), g_direct_hash, g_direct_equal);
epl_profiles_by_address = wmem_map_new(wmem_epan_scope(), epl_address_hash, epl_address_equal);
set_address(&epl_placeholder_mac, AT_ETHER, 6, "\xFF\xFF\xFF\xFF\xFF\xFF");
#ifdef HAVE_LIBXML2
epl_xdd_init();
#endif
epl_eds_init();
prefs_register_filename_preference(epl_module, "default_profile", "Default Profile to use if no specific profiles exist",
"If you have a capture without IdentResponse and many nodes, it's easier to set a default profile here than to add entries for all MAC address or Node IDs",
&epl_default_profile_path, FALSE);
device_profile_uat = uat_new("Device-Specific Profiles",
sizeof (struct device_profile_uat_assoc),
"epl_device_profiles",
TRUE,
&device_profile_list_uats,
&ndevice_profile_uat,
UAT_AFFECTS_DISSECTION,
NULL,
device_profile_uat_copy_cb,
device_profile_uat_update_record,
device_profile_uat_free_cb,
device_profile_parse_uat,
NULL,
device_profile_list_uats_flds);
prefs_register_uat_preference(epl_module, "device_profiles",
"Device-Specific Profiles",
"Add vendor-provided EDS" IF_LIBXML("/XDD") " profiles here",
device_profile_uat
);
nodeid_profile_uat = uat_new("NodeID-Specific Profiles",
sizeof (struct nodeid_profile_uat_assoc),
"epl_nodeid_profiles",
TRUE,
&nodeid_profile_list_uats,
&nnodeid_profile_uat,
UAT_AFFECTS_DISSECTION,
NULL,
nodeid_profile_uat_copy_cb,
nodeid_profile_uat_update_record,
nodeid_profile_uat_free_cb,
nodeid_profile_parse_uat,
NULL,
nodeid_profile_list_uats_flds);
prefs_register_uat_preference(epl_module, "nodeid_profiles",
"Node-Specific Profiles",
"Assign vendor-provided EDS" IF_LIBXML("/XDD") " profiles to CN IDs here",
nodeid_profile_uat
);
}
void
proto_reg_handoff_epl(void)
{
dissector_handle_t epl_udp_handle = create_dissector_handle(dissect_epludp, proto_epl);
dissector_add_uint("ethertype", ETHERTYPE_EPL_V2, epl_handle);
dissector_add_uint_with_preference("udp.port", UDP_PORT_EPL, epl_udp_handle);
register_init_routine( setup_dissector );
register_cleanup_routine( cleanup_dissector );
reassembly_table_register(&epl_reassembly_table, &addresses_reassembly_table_functions);
}
static gboolean
epl_uat_fld_uint16dec_check_cb(void *_record _U_, const char *str, guint len _U_, const void *chk_data _U_, const void *fld_data _U_, char **err)
{
guint16 val;
if (!ws_strtou16(str, NULL, &val))
{
*err = g_strdup("Invalid argument. Expected a decimal between [0-65535]");
return FALSE;
}
return TRUE;
}
static gboolean
epl_uat_fld_uint32hex_check_cb(void *_record _U_, const char *str, guint len _U_, const void *chk_data _U_, const void *fld_data _U_, char **err)
{
guint32 val;
if (!ws_hexstrtou32(str, NULL, &val))
{
*err = g_strdup("Invalid argument. Expected a hexadecimal between [0-ffffffff]");
return FALSE;
}
return TRUE;
}
static gboolean
epl_profile_uat_fld_fileopen_check_cb(void *record _U_, const char *path, guint len, const void *chk_data _U_, const void *fld_data _U_, char **err)
{
const char *supported = "Only" IF_LIBXML(" *.xdd, *.xdc and") " *.eds profiles supported.";
ws_statb64 st;
if (!path || !len)
{
*err = g_strdup("No filename given.");
return FALSE;
}
if (ws_stat64(path, &st) != 0)
{
*err = g_strdup_printf("File '%s' does not exist or access was denied.", path);
return FALSE;
}
if (g_str_has_suffix(path, ".eds"))
{
*err = NULL;
return TRUE;
}
if (g_str_has_suffix(path, ".xdd") || g_str_has_suffix(path, ".xdc"))
{
#ifdef HAVE_LIBXML2
*err = NULL;
return TRUE;
#else
*err = g_strdup_printf("*.xdd and *.xdc support not compiled in. %s", supported);
return FALSE;
#endif
}
*err = g_strdup(supported);
return FALSE;
}
static void
drop_profiles(void *key _U_, void *value, void *user_data _U_)
{
struct profile *head = (struct profile*)value, *curr;
while ((curr = head))
{
head = head->next;
profile_del(curr);
}
}
static void
device_profile_parse_uat(void)
{
guint i;
struct profile *profile = NULL;
wmem_map_foreach(epl_profiles_by_device, drop_profiles, NULL);
if (pdo_mapping_scope)
{
wmem_free_all(pdo_mapping_scope);
current_convo_generation++;
}
for (i = 0; i < ndevice_profile_uat; i++)
{
struct device_profile_uat_assoc *uat = &(device_profile_list_uats[i]);
profile = (struct profile*)wmem_map_lookup(epl_profiles_by_device, GUINT_TO_POINTER(uat->device_type));
if (profile)
{
struct profile *clone = wmem_new0(profile->scope, struct profile);
*clone = *profile;
profile = clone;
}
if (!profile)
profile = profile_load(wmem_epan_scope(), uat->path);
if (!profile)
continue;
struct profile *profile_head;
if ((profile_head = (struct profile*)wmem_map_lookup(epl_profiles_by_device, GUINT_TO_POINTER(profile->id))))
{
wmem_map_remove(epl_profiles_by_device, GUINT_TO_POINTER(profile_head->id));
profile->next = profile_head;
}
profile->id = uat->device_type;
profile->data = GUINT_TO_POINTER(profile->id);
profile->vendor_id = uat->vendor_id;
profile->product_code = uat->product_code;
wmem_map_insert(epl_profiles_by_device, GUINT_TO_POINTER(profile->id), profile);
profile->parent_map = epl_profiles_by_device;
g_log(NULL, G_LOG_LEVEL_INFO, "Loading %s\n", profile->path);
}
}
static gboolean
device_profile_uat_update_record(void *_record _U_, char **err _U_)
{
return TRUE;
}
static void
device_profile_uat_free_cb(void *_r)
{
struct device_profile_uat_assoc *r = (struct device_profile_uat_assoc *)_r;
g_free(r->path);
}
static void*
device_profile_uat_copy_cb(void *dst_, const void *src_, size_t len _U_)
{
const struct device_profile_uat_assoc *src = (const struct device_profile_uat_assoc *)src_;
struct device_profile_uat_assoc *dst = (struct device_profile_uat_assoc *)dst_;
dst->path = g_strdup(src->path);
dst->device_type = src->device_type;
dst->vendor_id = src->vendor_id;
dst->product_code = src->product_code;
return dst;
}
static void
nodeid_profile_parse_uat(void)
{
guint i;
struct profile *profile = NULL;
wmem_map_foreach(epl_profiles_by_nodeid, drop_profiles, NULL);
wmem_map_foreach(epl_profiles_by_address, drop_profiles, NULL);
if (pdo_mapping_scope)
{
wmem_free_all(pdo_mapping_scope);
current_convo_generation++;
}
for (i = 0; i < nnodeid_profile_uat; i++)
{
struct nodeid_profile_uat_assoc *uat = &(nodeid_profile_list_uats[i]);
profile = uat->is_nodeid ? (struct profile*)wmem_map_lookup(epl_profiles_by_nodeid, GUINT_TO_POINTER(uat->node.id))
: (struct profile*)wmem_map_lookup(epl_profiles_by_address, &uat->node.addr);
if (!profile)
profile = profile_load(wmem_epan_scope(), uat->path);
if (!profile)
continue;
if (uat->is_nodeid)
{
profile->nodeid = uat->node.id;
profile->data = GUINT_TO_POINTER(profile->nodeid);
wmem_map_insert(epl_profiles_by_nodeid, GUINT_TO_POINTER(profile->nodeid), profile);
profile->parent_map = epl_profiles_by_nodeid;
}
else
{
copy_address_wmem(profile->scope, &profile->node_addr, &uat->node.addr);
profile->data = &profile->node_addr;
wmem_map_insert(epl_profiles_by_address, &profile->node_addr, profile);
profile->parent_map = epl_profiles_by_address;
}
g_log(NULL, G_LOG_LEVEL_INFO, "Loading %s\n", profile->path);
}
}
static gboolean
nodeid_profile_uat_update_record(void *_record _U_, char **err _U_)
{
return TRUE;
}
static void
nodeid_profile_uat_free_cb(void *_r)
{
struct nodeid_profile_uat_assoc *r = (struct nodeid_profile_uat_assoc *)_r;
if (!r->is_nodeid)
free_address(&r->node.addr);
g_free(r->path);
}
static void*
nodeid_profile_uat_copy_cb(void *dst_, const void *src_, size_t len _U_)
{
const struct nodeid_profile_uat_assoc *src = (const struct nodeid_profile_uat_assoc *)src_;
struct nodeid_profile_uat_assoc *dst = (struct nodeid_profile_uat_assoc *)dst_;
dst->path = g_strdup(src->path);
dst->id_str = g_strdup(src->id_str);
if ((dst->is_nodeid = src->is_nodeid))
dst->node.id = src->node.id;
else
copy_address(&dst->node.addr, &src->node.addr);
return dst;
}
static void
nodeid_profile_list_uats_nodeid_tostr_cb(void *_rec, char **out_ptr, unsigned *out_len, const void *u1 _U_, const void *u2 _U_)
{
struct nodeid_profile_uat_assoc *rec = (struct nodeid_profile_uat_assoc*)_rec;
if (rec->id_str)
{
*out_ptr = g_strdup(rec->id_str);
*out_len = (unsigned)strlen(rec->id_str);
}
else
{
*out_ptr = g_strdup("");
*out_len = 0;
}
}
static gboolean
epl_uat_fld_cn_check_cb(void *record _U_, const char *str, guint len _U_, const void *u1 _U_, const void *u2 _U_, char **err)
{
unsigned int c;
guint8 nodeid;
if (ws_strtou8(str, NULL, &nodeid) && EPL_IS_CN_NODEID(nodeid))
return TRUE;
if (sscanf(str, "%*02x%*c%*02x%*c%*02x%*c%*02x%*c%*02x%*c%02x", &c) > 0)
return TRUE;
*err = g_strdup("Invalid argument. Expected either a CN ID [1-239] or a MAC address");
return FALSE;
}
static void
nodeid_profile_list_uats_nodeid_set_cb(void *_rec, const char *str, unsigned len, const void *set_data _U_, const void *fld_data _U_)
{
struct nodeid_profile_uat_assoc *rec = (struct nodeid_profile_uat_assoc*)_rec;
guint8 addr[6];
if (ws_strtou8(str, NULL, &addr[0]))
{
rec->is_nodeid = TRUE;
rec->node.id = addr[0];
}
else
{
unsigned i;
const char *endptr = str;
for (i = 0; i < 6; i++)
{
ws_hexstrtou8(endptr, &endptr, &addr[i]);
endptr++;
}
alloc_address_wmem(NULL, &rec->node.addr, AT_ETHER, 6, addr);
rec->is_nodeid = FALSE;
}
g_free(rec->id_str);
rec->id_str = g_strndup(str, len);
}
