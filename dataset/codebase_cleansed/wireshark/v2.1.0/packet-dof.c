static guint oap_1_alias_hash_func(gconstpointer ptr)
{
const oap_1_alias_key *key = (const oap_1_alias_key *)ptr;
return g_int_hash(&key->session) + g_int_hash(&key->sender) + g_int_hash(&key->alias);
}
static int oap_1_alias_equal_func(gconstpointer ptr1, gconstpointer ptr2)
{
const oap_1_alias_key *key1 = (const oap_1_alias_key *)ptr1;
const oap_1_alias_key *key2 = (const oap_1_alias_key *)ptr2;
if (key1->session != key2->session)
return 0;
if (key1->sender != key2->sender)
return 0;
if (key1->alias != key2->alias)
return 0;
return 1;
}
static int oap_1_tree_add_alias(dof_api_data *api_data, oap_1_packet_data *oap_packet _U_, dof_packet_data *packet, proto_tree *tree, tvbuff_t *tvb, gint offset, guint8 alias_length, guint8 resolve)
{
dof_session_data *session = api_data->session;
proto_item *ti;
proto_tree *options_tree;
if (alias_length == 0)
return offset;
if (session == NULL)
return offset;
ti = proto_tree_add_item(tree, hf_oap_1_alias, tvb, offset, alias_length, ENC_BIG_ENDIAN);
if (resolve)
{
oap_1_binding *binding = NULL;
oap_1_alias_key key;
int i;
guint32 alias;
alias = 0;
for (i = 0; i < alias_length; i++)
alias = (alias << 8) | tvb_get_guint8(tvb, offset + i);
key.session = session->session_id;
key.sender = packet->sender_id;
key.alias = alias;
binding = oap_1_resolve_alias(&key);
if (binding)
{
options_tree = proto_item_add_subtree(ti, ett_oap_1_alias);
ti = proto_tree_add_bytes_format_value(tree, hf_oap_1_interfaceid, tvb, offset, alias_length, binding->iid, "%s", dof_iid_create_standard_string(binding->iid_length, binding->iid));
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_bytes_format_value(tree, hf_oap_1_objectid, tvb, offset, alias_length, binding->oid, "%s", dof_oid_create_standard_string(binding->oid_length, binding->oid));
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_uint_format(options_tree, hf_oap_1_alias_frame,
tvb, 0, 0, binding->frame,
"This alias is defined in frame %u",
binding->frame);
}
}
return offset + alias_length;
}
static int oap_1_tree_add_interface(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 registry;
guint8 len;
registry = tvb_get_guint8(tvb, offset);
len = registry & 0x03;
if (len == 0)
len = 16;
else
len = 1 << (len - 1);
proto_tree_add_item(tree, hf_oap_1_interfaceid, tvb, offset, 1 + len, ENC_NA);
return offset + 1 + len;
}
static int oap_1_tree_add_binding(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
guint8 len;
len = tvb_get_guint8(tvb, offset);
len = len & 0x03;
if (len == 0)
len = 16;
else
len = 1 << (len - 1);
proto_tree_add_item(tree, hf_oap_1_interfaceid, tvb, offset, 1 + len, ENC_NA);
offset += 1 + len;
#if 0
cl = tvb_get_guint8(tvb, offset);
if (cl & 0x80)
len = tvb_get_guint8(tvb, offset + 2);
else
len = tvb_get_guint8(tvb, offset + 1);
#endif
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, tree,
offset, hf_oap_1_objectid, ett_oap_1_objectid, NULL);
return offset;
}
static int oap_1_tree_add_cmdcontrol(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
proto_tree *opinfo_tree;
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_bitmask(tree, tvb, offset, hf_oap_1_cmdcontrol, ett_oap_1_cmdcontrol_flags, bitmask_oap_1_cmdcontrol_flags, ENC_NA);
opinfo_tree = proto_item_add_subtree(ti, ett_oap_1_cmdcontrol);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_cache_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_verbosity_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_noexecute_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_ack_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_delay_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_heuristic_flag, tvb, offset, 1, ENC_NA);
offset += 1;
if (flags & 0x01)
{
gint heur_len;
guint16 heur;
proto_item *pi;
read_c2(tvb, offset, &heur, &heur_len);
pi = proto_tree_add_uint_format(opinfo_tree, hf_oap_1_cmdcontrol_heuristic, tvb, offset, heur_len, heur, "Heuristic Value: %hu", heur);
validate_c2(pinfo, pi, heur, heur_len);
offset += heur_len;
}
if (flags & 0x04)
{
guint8 ackcnt;
guint8 i;
ackcnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(opinfo_tree, hf_oap_1_cmdcontrol_ackcnt, tvb, offset, 1, ENC_NA);
offset += 1;
for (i = 0; i < ackcnt; i++)
{
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, opinfo_tree,
offset, hf_oap_1_cmdcontrol_ack, ett_oap_1_cmdcontrol_ack, NULL);
}
}
if (flags & 0x40)
{
gint cache_len;
guint16 cache;
proto_item *pi;
read_c2(tvb, offset, &cache, &cache_len);
pi = proto_tree_add_uint_format(opinfo_tree, hf_oap_1_cmdcontrol_cache, tvb, offset, cache_len, cache, "Cache Delay: %hu", cache);
validate_c2(pinfo, pi, cache, cache_len);
offset += cache_len;
}
return offset;
}
static void oap_1_define_alias(dof_api_data *api_data, guint32 alias, oap_1_binding *binding)
{
dof_session_data *session = api_data->session;
dof_packet_data *packet = (dof_packet_data *)api_data->packet;
guint32 session_id;
guint32 sender_id;
oap_1_alias_key key;
if (!session)
return;
session_id = session->session_id;
sender_id = packet->sender_id;
if (!binding)
return;
key.session = session_id;
key.sender = sender_id;
key.alias = alias;
if (!g_hash_table_lookup(oap_1_alias_to_binding, &key))
{
oap_1_alias_key *alias_ptr = (oap_1_alias_key *)wmem_alloc0(wmem_file_scope(), sizeof(oap_1_alias_key));
memcpy(alias_ptr, &key, sizeof(oap_1_alias_key));
g_hash_table_insert(oap_1_alias_to_binding, alias_ptr, binding);
}
}
static oap_1_binding* oap_1_resolve_alias(oap_1_alias_key *key)
{
return (oap_1_binding *)g_hash_table_lookup(oap_1_alias_to_binding, key);
}
static guint sender_key_hash_fn(gconstpointer key)
{
const node_key_to_sid_id_key *sid_key_ptr = (const node_key_to_sid_id_key *)key;
guint result = 0;
result += g_int_hash(&(sid_key_ptr->transport_id));
result += g_int_hash(&(sid_key_ptr->transport_node_id));
result += g_int_hash(&(sid_key_ptr->dof_id));
result += g_int_hash(&(sid_key_ptr->dof_node_id));
result += g_int_hash(&(sid_key_ptr->dof_session_id));
return result;
}
static guint sid_buffer_hash_fn(gconstpointer key)
{
guint hash = 5381;
const guint8 *str = (const guint8 *)key;
guint8 i;
for (i = 0; i <= str[0]; i++)
hash = ((hash << 5) + hash) + str[i];
return hash;
}
static gboolean sender_key_equal_fn(gconstpointer key1, gconstpointer key2)
{
const node_key_to_sid_id_key *sid_key_ptr1 = (const node_key_to_sid_id_key *)key1;
const node_key_to_sid_id_key *sid_key_ptr2 = (const node_key_to_sid_id_key *)key2;
if (sid_key_ptr1->transport_id != sid_key_ptr2->transport_id)
return FALSE;
if (sid_key_ptr1->transport_node_id != sid_key_ptr2->transport_node_id)
return FALSE;
if (sid_key_ptr1->dof_id != sid_key_ptr2->dof_id)
return FALSE;
if (sid_key_ptr1->dof_node_id != sid_key_ptr2->dof_node_id)
return FALSE;
if (sid_key_ptr1->dof_session_id != sid_key_ptr2->dof_session_id)
return FALSE;
return TRUE;
}
static gboolean sid_buffer_equal_fn(gconstpointer key1, gconstpointer key2)
{
const guint8 *sb1 = (const guint8 *)key1;
const guint8 *sb2 = (const guint8 *)key2;
if (sb1[0] != sb2[0])
return FALSE;
return memcmp(sb1 + 1, sb2 + 1, sb1[0]) == 0;
}
static void dpp_reset_sid_support(void)
{
dpp_next_sid_id = 1;
if (node_key_to_sid_id != NULL)
{
g_hash_table_destroy(node_key_to_sid_id);
node_key_to_sid_id = NULL;
}
if (sid_buffer_to_sid_id != NULL)
{
g_hash_table_destroy(sid_buffer_to_sid_id);
sid_buffer_to_sid_id = NULL;
}
if (sid_id_to_sid_buffer != NULL)
{
g_hash_table_destroy(sid_id_to_sid_buffer);
sid_id_to_sid_buffer = NULL;
}
node_key_to_sid_id = g_hash_table_new_full(sender_key_hash_fn, sender_key_equal_fn, g_free, NULL);
sid_buffer_to_sid_id = g_hash_table_new_full(sid_buffer_hash_fn, sid_buffer_equal_fn, g_free, NULL);
sid_id_to_sid_buffer = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, NULL);
}
static guint dpp_opid_hash_fn(gconstpointer opid)
{
const dof_2009_1_pdu_20_opid *ptr = (const dof_2009_1_pdu_20_opid *)opid;
return g_int_hash(&ptr->op_sid_id) + g_int_hash(&ptr->op_cnt);
}
static gboolean dpp_opid_equal_fn(gconstpointer opid1, gconstpointer opid2)
{
const dof_2009_1_pdu_20_opid *ptr1 = (const dof_2009_1_pdu_20_opid *)opid1;
const dof_2009_1_pdu_20_opid *ptr2 = (const dof_2009_1_pdu_20_opid *)opid2;
if (ptr1->op_cnt != ptr2->op_cnt)
return FALSE;
if (ptr1->op_sid_id != ptr2->op_sid_id)
return FALSE;
return TRUE;
}
static void dpp_reset_opid_support(void)
{
if (dpp_opid_to_packet_data != NULL)
{
g_hash_table_destroy(dpp_opid_to_packet_data);
dpp_opid_to_packet_data = NULL;
}
dpp_opid_to_packet_data = g_hash_table_new_full(dpp_opid_hash_fn, dpp_opid_equal_fn, NULL, NULL);
}
static dof_session_data* dof_ns_session_retrieve(guint transport_session_id, guint client, guint server)
{
dof_ns_session_key lookup_key;
dof_session_data *value;
lookup_key.transport_session_id = transport_session_id;
lookup_key.client = client;
lookup_key.server = server;
value = (dof_session_data *)g_hash_table_lookup(dof_ns_session_lookup, &lookup_key);
if (value)
{
return value;
}
return NULL;
}
static void dof_ns_session_define(guint transport_session_id, guint client, guint server, dof_session_data *session_data)
{
dof_ns_session_key *key;
key = g_new0(dof_ns_session_key, 1);
key->transport_session_id = transport_session_id;
key->client = client;
key->server = server;
g_hash_table_insert(dof_ns_session_lookup, key, session_data);
}
static int dissect_2008_1_dsp_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *parent = proto_tree_get_parent(tree);
guint8 attribute_code = tvb_get_guint8(tvb, 0);
guint16 attribute_data = tvb_get_ntohs(tvb, 1);
guint8 option_length = tvb_get_guint8(tvb, 3);
proto_tree_add_item(tree, hf_2008_1_dsp_attribute_code, tvb, 0, 1, ENC_NA);
proto_tree_add_item(tree, hf_2008_1_dsp_attribute_data, tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_2008_1_dsp_value_length, tvb, 3, 1, ENC_NA);
proto_item_append_text(parent, " (Code=%s/Data=0x%04x)", val_to_str(attribute_code, strings_2008_1_dsp_attribute_codes, "%u"), attribute_data);
if (option_length)
{
proto_tree_add_item(tree, hf_2008_1_dsp_value_data, tvb, 4, option_length, ENC_NA);
tvb_set_reported_length(tvb, option_length + 4);
dissector_try_uint(dsp_option_dissectors, (attribute_code << 16) | attribute_data, tvb, pinfo, tree);
}
return option_length + 4;
}
static int dissect_2008_16_security_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gboolean has_length;
guint16 length;
{
gint start = offset;
guint16 value;
gint val_len;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &val_len);
has_length = (gboolean)(value % 2);
pi = proto_tree_add_uint(tree, hf_security_1_permission_type, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, val_len);
}
if (!has_length)
return offset;
{
gint start = offset;
guint16 value;
gint value_len;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &value_len);
length = value;
pi = proto_tree_add_uint(tree, hf_security_1_length, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, value_len);
}
proto_tree_add_item(tree, hf_security_1_data, tvb, offset, length, ENC_NA);
offset += length;
return offset;
}
static int dissect_2008_16_security_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint16 count;
{
gint start = offset;
guint16 value;
gint length;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &length);
count = value;
pi = proto_tree_add_uint(tree, hf_security_2_count, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, length);
}
while (count--)
{
proto_item *ti = proto_tree_add_item(tree, hf_security_2_permission, tvb, offset, -1, ENC_NA);
proto_tree *subtree = proto_item_add_subtree(ti, ett_security_2_permission);
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, -1, -1);
gint len = dissect_2008_16_security_1(next_tvb, pinfo, subtree, NULL);
proto_item_set_len(ti, len);
offset += len;
}
return offset;
}
static int dissect_2008_16_security_3_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
guint8 stage;
proto_item *ti;
dof_2008_16_security_3_1 *return_data = (dof_2008_16_security_3_1 *)data;
{
gint start = offset;
guint16 value;
gint length;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &length);
pi = proto_tree_add_uint(tree, hf_security_3_1_credential_type, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, length);
}
stage = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, hf_security_3_1_stage, tvb, offset, 1, ENC_NA);
offset += 1;
if (stage != 0)
expert_add_info(pinfo, ti, &ei_security_3_1_invalid_stage);
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_3_1_security_node_identifier, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_3_1_security_node_identifier);
block_length = dissect_2008_16_security_8(start, pinfo, subtree, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
tvb_set_reported_length(start, block_length);
if (return_data)
return_data->identity = start;
}
return offset;
}
int dissect_2008_16_security_3_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint16 length;
{
gint start = offset;
guint16 value;
gint val_len;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &val_len);
pi = proto_tree_add_uint(tree, hf_security_3_2_credential_type, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, val_len);
}
proto_tree_add_item(tree, hf_security_3_2_stage, tvb, offset, 1, ENC_NA);
offset += 1;
{
gint start = offset;
guint16 value;
gint value_len;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &value_len);
length = value;
pi = proto_tree_add_uint(tree, hf_security_3_2_length, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, value_len);
}
proto_tree_add_item(tree, hf_security_3_2_public_data, tvb, offset, length, ENC_NA);
offset += length;
return offset;
}
static int dissect_2008_16_security_4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
guint8 flag;
dof_2008_16_security_4 *return_data = (dof_2008_16_security_4 *)data;
flag = tvb_get_guint8(tvb, offset);
if (flag & 0x30)
expert_add_info(pinfo, tree, &ei_security_4_invalid_bit);
proto_tree_add_item(tree, hf_security_4_l, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_security_4_f, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_security_4_ln, tvb, offset, 1, ENC_NA);
offset += 1;
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
dof_2008_16_security_3_1 return_3_1;
ti = proto_tree_add_item(tree, hf_security_4_identity, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_4_identity);
block_length = dissect_2008_16_security_3_1(start, pinfo, subtree, &return_3_1);
proto_item_set_len(ti, block_length);
offset += block_length;
if (return_data)
{
return_data->identity = return_3_1.identity;
}
}
{
tvbuff_t *start = tvb_new_subset(tvb, offset, (flag & 0x0F) + 1, (flag & 0x0F) + 1);
if (return_data)
return_data->nonce = start;
proto_tree_add_item(tree, hf_security_4_nonce, start, 0, (flag & 0x0F) + 1, ENC_NA);
offset += (flag & 0x0F) + 1;
}
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_4_permission_set, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_4_permission_set);
block_length = dissect_2008_16_security_2(start, pinfo, subtree, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
}
return offset;
}
static int dissect_2008_16_security_5(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_tree_add_item(tree, hf_security_5_mac, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_security_5_key, tvb, offset, 32, ENC_NA);
offset += 32;
return offset;
}
static int dissect_2008_16_security_6_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
dof_2008_16_security_6_1 *return_data = (dof_2008_16_security_6_1 *)data;
proto_tree_add_item(tree, hf_security_6_1_desired_duration, tvb, offset, 1, ENC_NA);
offset += 1;
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_1_desired_security_mode, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_1_desired_security_mode);
block_length = dissect_2008_16_security_13(start, pinfo, subtree, NULL);
offset += block_length;
tvb_set_reported_length(start, block_length);
proto_item_set_len(ti, block_length);
if (return_data)
{
return_data->security_mode = tvb_get_ntohs(start, 1);
return_data->security_mode_data_length = block_length - 4;
return_data->security_mode_data = (guint8 *)tvb_memdup(wmem_file_scope(), start, 4, block_length - 4);
}
}
{
int block_length;
dof_2008_16_security_4 output;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_1_initiator_request, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_1_initiator_request);
block_length = dissect_2008_16_security_4(start, pinfo, subtree, &output);
proto_item_set_len(ti, block_length);
offset += block_length;
if (return_data)
{
return_data->i_identity = output.identity;
return_data->i_nonce = output.nonce;
}
}
return offset;
}
static int dissect_2008_16_security_6_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
dof_2008_16_security_6_2 *return_data = (dof_2008_16_security_6_2 *)data;
{
int block_length;
dof_2008_16_security_4 output;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_2_responder_request, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_2_responder_request);
block_length = dissect_2008_16_security_4(start, pinfo, subtree, &output);
proto_item_set_len(ti, block_length);
offset += block_length;
if (return_data)
{
return_data->r_identity = output.identity;
return_data->r_nonce = output.nonce;
}
}
return offset;
}
static int dissect_2008_16_security_6_3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_tree_add_item(tree, hf_security_6_3_granted_duration, tvb, offset, 1, ENC_NA);
offset += 1;
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_3_session_security_scope, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_3_session_security_scope);
block_length = dissect_2008_16_security_10(start, pinfo, subtree, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
}
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_3_initiator_validation, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_3_initiator_validation);
block_length = dissect_2008_16_security_11(start, pinfo, subtree, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
}
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_security_6_3_responder_validation, tvb, offset, 0, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_security_6_3_responder_validation);
block_length = dissect_2008_16_security_11(start, pinfo, subtree, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
}
return offset;
}
static int dissect_2008_16_security_7(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint block_length;
block_length = dissect_2009_11_type_4(tvb, pinfo, tree, NULL);
return block_length;
}
static int dissect_2008_16_security_8(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint block_length;
block_length = dissect_2009_11_type_4(tvb, pinfo, tree, NULL);
return block_length;
}
static int dissect_2008_16_security_9(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint16 length;
{
gint start = offset;
guint16 value;
gint value_len;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &value_len);
length = value;
pi = proto_tree_add_uint(tree, hf_security_9_length, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, value_len);
}
if (length > 0)
{
proto_tree_add_item(tree, hf_security_9_initial_state, tvb, offset, length, ENC_NA);
offset += length;
}
return offset;
}
static int dissect_2008_16_security_10(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint16 count;
{
gint start = offset;
guint16 value;
gint length;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &length);
count = value;
pi = proto_tree_add_uint(tree, hf_security_10_count, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, length);
}
while (count--)
{
const char *def = "";
gint start = offset;
guint32 value;
gint length;
proto_item *pi;
offset = read_c4(tvb, offset, &value, &length);
switch (value)
{
case 0x3FFFFFFF:
def = " (all scopes)";
break;
case 0x3FFFFFFE:
def = " (doesn't mask)";
break;
case 0x3FFFFFFD:
def = " (session scope)";
break;
}
pi = proto_tree_add_uint_format_value(tree, hf_security_10_permission_group_identifier, tvb, start, offset - start, value, "%u%s", value, def);
validate_c4(pinfo, pi, value, length);
}
return offset;
}
static int dissect_2008_16_security_11(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint16 count;
{
gint start = offset;
guint16 value;
gint length;
proto_item *pi;
offset = read_c2(tvb, offset, &value, &length);
count = value;
pi = proto_tree_add_uint(tree, hf_security_11_count, tvb, start, offset - start, value);
validate_c2(pinfo, pi, value, length);
}
while (count--)
{
proto_item *ti = proto_tree_add_item(tree, hf_security_11_permission_security_scope, tvb, offset, -1, ENC_NA);
proto_tree *subtree = proto_item_add_subtree(ti, ett_security_11_permission_security_scope);
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, -1, -1);
gint len;
len = dissect_2008_16_security_12(next_tvb, pinfo, subtree, NULL);
proto_item_set_len(ti, len);
offset += len;
}
return offset;
}
static int dissect_2008_16_security_12(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint8 m = tvb_get_guint8(tvb, offset) >> 6;
guint16 count = tvb_get_guint8(tvb, offset) & 0x3F;
proto_item *pi;
proto_tree_add_item(tree, hf_security_12_m, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_security_12_count, tvb, offset, 1, ENC_NA);
offset += 1;
if (m == 0)
return offset;
while (count--)
{
const char *def = "";
gint start = offset;
guint32 value;
gint length;
offset = read_c4(tvb, offset, &value, &length);
switch (value)
{
case 0x3FFFFFFF:
def = " (all scopes)";
break;
case 0x3FFFFFFE:
def = " (doesn't mask)";
break;
case 0x3FFFFFFD:
def = " (session scope)";
break;
}
pi = proto_tree_add_uint_format_value(tree, hf_security_12_permission_group_identifier, tvb, start, offset - start, value, "%u%s", value, def);
validate_c4(pinfo, pi, value, length);
}
return offset;
}
static int dissect_2008_16_security_13(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint block_length;
guint16 attribute_data;
attribute_data = tvb_get_ntohs(tvb, 1);
if (attribute_data < 0x6000 || attribute_data >= 0x7000)
expert_add_info(pinfo, tree, &ei_security_13_out_of_range);
block_length = dissect_2008_1_dsp_1(tvb, pinfo, tree);
return block_length;
}
static gint dissect_2009_11_type_4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
gint start_offset = 0;
gint offset = 0;
guint32 oid_class;
gint oid_class_len;
guint8 oid_len_byte;
proto_tree *oid_tree = tree;
proto_tree *header_tree;
if (tree)
{
ti = proto_tree_get_parent(tree);
proto_item_set_text(ti, "Object ID: %s", dof_oid_create_standard_string(tvb_reported_length(tvb), tvb_get_ptr(tvb, 0, tvb_reported_length(tvb))));
}
offset = read_c4(tvb, offset, &oid_class, &oid_class_len);
ti = proto_tree_add_uint_format(oid_tree, hf_oid_class, tvb, start_offset, offset - start_offset, oid_class, "Class: %u", oid_class);
validate_c4(pinfo, ti, oid_class, oid_class_len);
oid_len_byte = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint_format(oid_tree, hf_oid_header, tvb,
offset, 1, oid_len_byte, "Header: 0x%02x (%sLength=%d)", oid_len_byte, oid_len_byte & 0x80 ? "Attribute, " : "", oid_len_byte & 0x3F);
header_tree = proto_item_add_subtree(ti, ett_oid_header);
proto_tree_add_item(header_tree, hf_oid_attribute, tvb, offset, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_oid_length, tvb, offset, 1, ENC_NA);
offset += 1;
if (oid_len_byte & 0x40)
{
expert_add_info(pinfo, ti, &ei_type_4_header_zero);
}
if ((oid_len_byte & 0x3F) > 0)
{
proto_tree_add_item(oid_tree, hf_oid_data, tvb, offset, oid_len_byte & 0x3F, ENC_NA);
offset += oid_len_byte & 0x3F;
}
if (oid_len_byte & 0x80)
{
guint8 flag;
do
{
tvbuff_t *packet = tvb_new_subset(tvb, offset, -1, -1);
proto_tree *attribute_tree;
gint attribute_length;
ti = proto_tree_add_item(tree, hf_oid_all_attribute_data, tvb, offset, -1, ENC_NA);
attribute_tree = proto_item_add_subtree(ti, ett_oid_attribute);
flag = tvb_get_guint8(tvb, offset);
attribute_length = dissect_2009_11_type_5(packet, pinfo, attribute_tree);
proto_item_set_len(ti, (const gint)attribute_length);
offset += attribute_length;
}
while (flag & 0x80);
}
if (tree)
{
ti = proto_tree_get_parent(tree);
proto_item_set_len(ti, offset - start_offset);
}
return offset;
}
static int dissect_2009_11_type_5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
gint offset = 0;
guint8 attribute_id_byte;
guint8 attribute_length_byte;
proto_tree *oid_tree = tree;
proto_tree *header_tree;
attribute_id_byte = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint_format(oid_tree, hf_oid_attribute_header, tvb,
offset, 1, attribute_id_byte, "Header: 0x%02x (%sLength=%d)", attribute_id_byte, attribute_id_byte & 0x80 ? "Attribute, " : "", attribute_id_byte & 0x3F);
header_tree = proto_item_add_subtree(ti, ett_oid_attribute_header);
proto_tree_add_item(header_tree, hf_oid_attribute_attribute, tvb, offset, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_oid_attribute_id, tvb, offset, 1, ENC_NA);
offset += 1;
attribute_length_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(oid_tree, hf_oid_attribute_length, tvb, offset, 1, ENC_NA);
offset += 1;
switch (attribute_id_byte & 0x7F)
{
case 1:
proto_tree_add_item(oid_tree, hf_oid_attribute_data, tvb, offset, attribute_length_byte, ENC_NA);
offset += attribute_length_byte;
break;
case 0:
case 2:
{
tvbuff_t *packet = tvb_new_subset(tvb, offset, attribute_length_byte, attribute_length_byte);
proto_tree *attribute_tree;
ti = proto_tree_add_item(tree, hf_oid_attribute_oid, tvb, offset, -1, ENC_NA);
attribute_tree = proto_item_add_subtree(ti, ett_oid_attribute_oid);
offset += dissect_2009_11_type_4(packet, pinfo, attribute_tree, NULL);
}
break;
default:
proto_tree_add_item(oid_tree, hf_oid_attribute_data, tvb, offset, attribute_length_byte, ENC_NA);
offset += attribute_length_byte;
}
return offset;
}
static void secmode_list_post_update_cb(void)
{
}
static void secmode_list_update_cb(void *r, const char **err)
{
secmode_field_t *rec = (secmode_field_t *)r;
guint32 size;
*err = NULL;
size = (guint32)strlen(rec->domain);
if (!VALIDHEX(rec->domain[0]) && !dof_oid_create_internal(rec->domain, &size, NULL))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid domain [must be valid OID].");
return;
}
else if (!count_hex_bytes(rec->domain))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid domain [must be valid OID].");
return;
}
size = (guint32)strlen(rec->identity);
if (!VALIDHEX(rec->identity[0]) && !dof_oid_create_internal(rec->identity, &size, NULL))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid identity [must be valid OID].");
return;
}
else if (!count_hex_bytes(rec->identity))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid identity [must be valid OID].");
return;
}
if (count_hex_bytes(rec->kek) != 32)
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid KEK [must be 32 byte key].");
return;
}
}
static void* secmode_list_copy_cb(void *n, const void *o, unsigned siz _U_)
{
secmode_field_t *new_rec = (secmode_field_t *)n;
const secmode_field_t *old_rec = (const secmode_field_t *)o;
if (old_rec->domain)
{
new_rec->domain = g_strdup(old_rec->domain);
}
else
{
new_rec->domain = NULL;
}
if (old_rec->identity)
{
new_rec->identity = g_strdup(old_rec->identity);
}
else
{
new_rec->identity = NULL;
}
if (old_rec->kek)
{
new_rec->kek = g_strdup(old_rec->kek);
}
else
{
new_rec->kek = NULL;
}
return new_rec;
}
static void secmode_list_free_cb(void *r)
{
secmode_field_t *rec = (secmode_field_t *)r;
if (rec->domain)
g_free(rec->domain);
if (rec->identity)
g_free(rec->identity);
if (rec->kek)
g_free(rec->kek);
}
static void seckey_list_post_update_cb(void)
{
}
static void seckey_list_update_cb(void *r, const char **err)
{
seckey_field_t *rec = (seckey_field_t *)r;
*err = NULL;
if (count_hex_bytes(rec->key) != 32)
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid secret [must be 32 bytes].");
return;
}
}
static void* seckey_list_copy_cb(void *n, const void *o, unsigned siz _U_)
{
seckey_field_t *new_rec = (seckey_field_t *)n;
const seckey_field_t *old_rec = (const seckey_field_t *)o;
if (old_rec->key)
{
new_rec->key = g_strdup(old_rec->key);
}
else
{
new_rec->key = NULL;
}
return new_rec;
}
static void seckey_list_free_cb(void *r)
{
seckey_field_t *rec = (seckey_field_t *)r;
if (rec->key)
g_free(rec->key);
}
static void identsecret_list_post_update_cb(void)
{
}
static void identsecret_list_update_cb(void *r, const char **err)
{
identsecret_field_t *rec = (identsecret_field_t *)r;
guint32 size;
*err = NULL;
size = (guint32)strlen(rec->domain);
if (!VALIDHEX(rec->domain[0]))
{
if (dof_oid_create_internal(rec->domain, &size, NULL))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid domain [must be valid OID].");
return;
}
}
else if (!count_hex_bytes(rec->domain))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid domain [must be valid OID].");
return;
}
size = (guint32)strlen(rec->identity);
if (!VALIDHEX(rec->identity[0]))
{
if (dof_oid_create_internal(rec->identity, &size, NULL))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid identity [must be valid OID].");
return;
}
}
else if (!count_hex_bytes(rec->identity))
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid identity [must be valid OID].");
return;
}
if (count_hex_bytes(rec->secret) != 32)
{
*err = wmem_strdup(wmem_packet_scope(), "Invalid secret [must be 32 byte key].");
return;
}
}
static void* identsecret_list_copy_cb(void *n, const void *o, unsigned siz _U_)
{
identsecret_field_t *new_rec = (identsecret_field_t *)n;
const identsecret_field_t *old_rec = (const identsecret_field_t *)o;
if (old_rec->domain)
{
new_rec->domain = g_strdup(old_rec->domain);
}
else
{
new_rec->domain = NULL;
}
if (old_rec->identity)
{
new_rec->identity = g_strdup(old_rec->identity);
}
else
{
new_rec->identity = NULL;
}
if (old_rec->secret)
{
new_rec->secret = g_strdup(old_rec->secret);
}
else
{
new_rec->secret = NULL;
}
return new_rec;
}
static void identsecret_list_free_cb(void *r)
{
identsecret_field_t *rec = (identsecret_field_t *)r;
if (rec->domain)
g_free(rec->domain);
if (rec->identity)
g_free(rec->identity);
if (rec->secret)
g_free(rec->secret);
}
static guint addr_port_key_hash_fn(gconstpointer key)
{
const addr_port_key *addr_key = (const addr_port_key *)key;
guint result = 0;
guint port_as_int = addr_key->port;
guint type_as_int = addr_key->addr.type;
result += g_int_hash(&port_as_int);
result += g_int_hash(&type_as_int);
{
guint hash = 5381;
const guint8 *str = (const guint8 *)addr_key->addr.data;
guint8 i;
for (i = 0; i < addr_key->addr.len; i++)
hash = ((hash << 5) + hash) + str[i];
result += hash;
}
return result;
}
static gboolean addr_port_key_equal_fn(gconstpointer key1, gconstpointer key2)
{
const addr_port_key *addr_key_ptr1 = (const addr_port_key *)key1;
const addr_port_key *addr_key_ptr2 = (const addr_port_key *)key2;
if (addr_key_ptr1->port != addr_key_ptr2->port)
return FALSE;
return addresses_equal(&addr_key_ptr1->addr, &addr_key_ptr2->addr);
}
static void addr_port_key_free_fn(gpointer key)
{
addr_port_key *addr_port = (addr_port_key *)key;
g_free(addr_port->addr.priv);
g_free(addr_port);
}
static void init_addr_port_tables(void)
{
if (addr_port_to_id != NULL)
{
g_hash_table_destroy(addr_port_to_id);
addr_port_to_id = NULL;
}
addr_port_to_id = g_hash_table_new_full(addr_port_key_hash_fn, addr_port_key_equal_fn, addr_port_key_free_fn, NULL);
}
static guint assign_addr_port_id(address *addr, guint16 port)
{
addr_port_key lookup_key;
addr_port_key *key;
guint value;
EP_COPY_ADDRESS(&lookup_key.addr, addr);
lookup_key.port = port;
value = GPOINTER_TO_UINT(g_hash_table_lookup(addr_port_to_id, &lookup_key));
if (value)
{
return value;
}
key = g_new0(addr_port_key, 1);
copy_address(&key->addr, addr);
key->port = port;
g_hash_table_insert(addr_port_to_id, key, GUINT_TO_POINTER(next_addr_port_id));
return next_addr_port_id++;
}
static gboolean identsecret_chk_cb(void *r _U_, const char *p _U_, unsigned len _U_, const void *u1 _U_, const void *u2 _U_, char **err _U_)
{
#if 0
gchar** protos;
gchar* line = ep_strndup(p, len);
guint num_protos, i;
g_strstrip(line);
ascii_strdown_inplace(line);
protos = ep_strsplit(line, ":", 0);
for (num_protos = 0; protos[num_protos]; num_protos++)
g_strstrip(protos[num_protos]);
if (!num_protos)
{
*err = wmem_strdup(wmem_packet_scope(), "No protocols given");
return FALSE;
}
for (i = 0; i < num_protos; i++)
{
if (!find_dissector(protos[i]))
{
*err = wmem_strdup_printf(wmem_packet_scope(), "Could not find dissector for: '%s'", protos[i]);
return FALSE;
}
}
#endif
return TRUE;
}
static guint8 count_hex_bytes(gchar *str)
{
guint8 total = 0;
while (str != NULL && *str != '\0' && *str != '#')
{
if (!g_ascii_isxdigit(*str))
{
str += 1;
continue;
}
if (!g_ascii_isxdigit(str[1]))
return 0;
total += 1;
str += 2;
}
return total;
}
static void parse_hex_string(gchar *str, guint8 **ptr, guint8 *len)
{
guint8 j = 0;
*len = count_hex_bytes(str);
*ptr = (guint8 *)g_malloc0(*len);
while (j < *len)
{
int high, low;
if (!g_ascii_isxdigit(*str))
{
str += 1;
continue;
}
high = ws_xton(str[0]);
low = ws_xton(str[1]);
(*ptr)[j++] = (high << 4) | low;
str += 2;
}
}
static guint32 OALMarshal_UncompressValue(guint8 maxSize, guint32 *bufLength, const guint8 *buffer)
{
guint32 value = 0;
guint8 used = 0;
guint8 size = maxSize;
guint8 mask;
switch (buffer[0] >> 6)
{
case 0x02:
if (maxSize > 2)
mask = 0x3F;
else
mask = 0x7F;
size = 2;
break;
case 0x03:
if (maxSize > 2)
mask = 0x3F;
else
mask = 0x7F;
break;
default:
size = 1;
mask = 0x7F;
break;
}
value = buffer[used++] & mask;
while (used < size)
value = (value << 8) | buffer[used++];
*bufLength = used;
return (value);
}
static guint32 DOFObjectID_GetClassSize_Bytes(const guint8 *pBytes)
{
guint32 size = 4;
(void)OALMarshal_UncompressValue(DOFOBJECTID_MAX_CLASS_SIZE, &size, pBytes);
return size;
}
static guint32 DOFObjectID_GetClassSize(DOFObjectID self)
{
return DOFObjectID_GetClassSize_Bytes(self->oid);
}
static guint32 DOFObjectID_GetDataSize(const DOFObjectID self)
{
return ((*((const guint8 *)self->oid + DOFObjectID_GetClassSize(self))) & OID_DATA_LEN_MASK);
}
static guint32 ObjectID_DataToString(const guint8 *data, guint32 dataSize, char *pBuf)
{
guint32 len = 0, i, nonprintable, escaped;
for (i = 0, nonprintable = 0, escaped = 0; i < dataSize; i++)
{
if (!IS_PRINTABLE(data[i]))
nonprintable++;
else if (IS_ESCAPED(data[i]))
escaped++;
}
if (nonprintable == 0)
{
if (pBuf)
{
for (i = 0; i < dataSize; i++)
{
if (IS_ESCAPED(data[i]))
{
pBuf[len++] = '\\';
pBuf[len++] = data[i];
}
else
pBuf[len++] = data[i];
}
}
else
{
len = dataSize + escaped;
}
}
else
{
if (pBuf)
{
pBuf[len++] = '{';
for (i = 0; i < dataSize; i++)
{
pBuf[len++] = OALString_HexDigitToChar((data[i] >> 4) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((data[i]) & 0x0F);
}
pBuf[len++] = '}';
}
else
{
len = dataSize * 2 + 2;
}
}
return len;
}
static const guint8* DOFObjectID_GetData(const DOFObjectID self)
{
if (DOFObjectID_GetDataSize(self) > 0)
return (const guint8 *)self->oid + DOFObjectID_GetClassSize(self) + 1;
return NULL;
}
static guint32 DOFObjectID_GetIDClass(const DOFObjectID self)
{
guint32 size = 4;
return OALMarshal_UncompressValue(DOFOBJECTID_MAX_CLASS_SIZE, &size, self->oid);
}
static gboolean DOFObjectID_HasAttributes(const DOFObjectID self)
{
if (!self)
return FALSE;
return (gboolean)(((*(const guint8 *)((const guint8 *)(self->oid) + DOFObjectID_GetClassSize(self))) & 0x80) != 0);
}
static guint8 DOFObjectID_GetBaseSize(const DOFObjectID oid)
{
return DOFObjectID_GetClassSize(oid) + 1 + DOFObjectID_GetDataSize(oid);
}
static guint8 DOFObjectID_GetAttributeCount(const DOFObjectID self)
{
guint8 retVal = 0;
if (self && DOFObjectID_HasAttributes(self))
{
const guint8 *pNextAttribute = (const guint8 *)self->oid + DOFObjectID_GetBaseSize(self);
++retVal;
while (*pNextAttribute & 0x80)
{
++retVal;
pNextAttribute += (2 + *((const guint8 *)pNextAttribute + 1));
}
}
return retVal;
}
static DOFObjectIDAttribute DOFObjectID_GetAttributeAtIndex(const DOFObjectID self, guint8 attribute_index)
{
DOFObjectIDAttribute retAttributeDescriptor = { DOFOBJECTIDATTRIBUTE_INVALID, 0, NULL };
if (self && attribute_index < DOFOBJECTIDATTRIBUTE_INVALID)
{
if (DOFObjectID_HasAttributes(self))
{
guint8 count = 0;
const guint8 *pNextAttribute = (const guint8 *)self->oid + DOFObjectID_GetBaseSize(self);
while (1)
{
if (attribute_index == count++)
{
retAttributeDescriptor.id = *pNextAttribute & 0x7F;
retAttributeDescriptor.dataSize = (DOFObjectIDAttributeDataSize) * ((const guint8 *)pNextAttribute + 1);
retAttributeDescriptor.data = (const guint8 *)pNextAttribute + 2;
break;
}
if (!(*pNextAttribute & 0x80))
break;
pNextAttribute += (2 + *((const guint8 *)pNextAttribute + 1));
}
}
}
return retAttributeDescriptor;
}
static void DOFObjectID_Destroy(DOFObjectID self _U_)
{
}
static void DOFObjectID_InitStruct(DOFObjectID newObjID, guint32 dataLen)
{
newObjID->refCount = 1;
newObjID->len = dataLen;
}
static DOFObjectID DOFObjectID_Create_Unmarshal(guint32 *length, const guint8 *buffer)
{
guint32 len = *length;
if (buffer && len >= 2)
{
guint32 classSize = len;
guint32 classv = OALMarshal_UncompressValue(DOFOBJECTID_MAX_CLASS_SIZE, &classSize, buffer);
if (1)
{
guint32 computedSize;
computedSize = classSize + 1;
if (len >= computedSize)
{
guint8 lenByte = buffer[classSize];
if (!(lenByte & 0x40))
{
gboolean hasAttr;
guint8 dataLen = lenByte & OID_DATA_LEN_MASK;
if ((classv == 0) && (dataLen > 0))
goto notvalid;
computedSize += dataLen;
hasAttr = lenByte & 0x80;
while (hasAttr)
{
if (len >= computedSize + 2)
{
hasAttr = buffer[computedSize] & 0x80;
computedSize += (2 + buffer[computedSize + 1]);
}
else
goto notvalid;
}
if (len >= computedSize)
{
DOFObjectID newObjID = (DOFObjectID)wmem_alloc0(wmem_packet_scope(), DOFOBJECTID_HEADER_SIZE + computedSize + 1);
*length = computedSize;
if (newObjID)
{
DOFObjectID_InitStruct(newObjID, computedSize);
memcpy(newObjID->oid, buffer, computedSize);
newObjID->oid[computedSize] = 0;
return newObjID;
}
goto allocErrorOut;
}
}
}
}
}
notvalid:
allocErrorOut :
*length = 0;
return NULL;
}
static DOFObjectID DOFObjectID_Create_Bytes(guint32 bufferSize, const guint8 *pOIDBuffer)
{
guint32 len = bufferSize;
DOFObjectID rval = DOFObjectID_Create_Unmarshal(&len, pOIDBuffer);
if (rval)
{
if (len != bufferSize)
{
DOFObjectID_Destroy(rval);
rval = NULL;
}
}
return rval;
}
static guint32 ObjectID_ToStringLength(const DOFObjectID oid)
{
guint32 len = 0;
len = 7 + ObjectID_DataToStringLength(DOFObjectID_GetData(oid),
DOFObjectID_GetDataSize(oid));
if (DOFObjectID_GetIDClass(oid) & 0xFF000000)
len += 6;
else if (DOFObjectID_GetIDClass(oid) & 0xFF0000)
len += 4;
else if (DOFObjectID_GetIDClass(oid) & 0xFF00)
len += 2;
if (DOFObjectID_HasAttributes(oid))
{
guint8 i;
guint8 attributeCount = DOFObjectID_GetAttributeCount(oid);
len += 2;
for (i = 0; i < attributeCount; i++)
{
DOFObjectID embedOID;
DOFObjectIDAttribute avpDescriptor = DOFObjectID_GetAttributeAtIndex(oid, i);
if (!DOFObjectIDAttribute_IsValid(avpDescriptor))
break;
if (i)
len++;
len += 5;
embedOID = DOFObjectID_Create_Bytes(DOFObjectIDAttribute_GetValueSize(avpDescriptor),
DOFObjectIDAttribute_GetValue(avpDescriptor));
if (embedOID)
{
len += ObjectID_ToStringLength(embedOID);
DOFObjectID_Destroy(embedOID);
}
else
{
len += ObjectID_DataToStringLength(DOFObjectIDAttribute_GetValue(avpDescriptor),
DOFObjectIDAttribute_GetValueSize(avpDescriptor));
}
}
}
return len;
}
static guint32 InterfaceID_ToString(const guint8 *iid, char *pBuf)
{
guint32 len = 0;
guint iid_len = iid[0] & 0x03;
guint i;
if (iid_len == 3)
iid_len = 4;
pBuf[len++] = '[';
pBuf[len++] = '{';
pBuf[len++] = OALString_HexDigitToChar((iid[0] >> 6) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((iid[0] >> 2) & 0x0F);
pBuf[len++] = '}';
pBuf[len++] = ':';
pBuf[len++] = '{';
for (i = 0; i < iid_len; i++)
{
pBuf[len++] = OALString_HexDigitToChar((iid[i + 1] >> 4) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar(iid[i + 1] & 0x0F);
}
pBuf[len++] = '}';
pBuf[len++] = ']';
return len;
}
static guint32 ObjectID_ToString(const DOFObjectID oid, char *pBuf)
{
DOFObjectIDClass oidClass;
guint32 len = 0;
pBuf[len++] = '[';
pBuf[len++] = '{';
oidClass = DOFObjectID_GetIDClass(oid);
if (oidClass & 0xFF000000)
{
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 28) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 24) & 0x0F);
}
if (oidClass & 0xFFFF0000)
{
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 20) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 16) & 0x0F);
}
if (oidClass & 0xFFFFFF00)
{
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 12) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 8) & 0x0F);
}
pBuf[len++] = OALString_HexDigitToChar((oidClass >> 4) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((oidClass) & 0x0F);
pBuf[len++] = '}';
pBuf[len++] = ':';
len += ObjectID_DataToString(DOFObjectID_GetData(oid), DOFObjectID_GetDataSize(oid), &pBuf[len]);
if (DOFObjectID_HasAttributes(oid))
{
guint8 i;
guint8 attributeCount = DOFObjectID_GetAttributeCount(oid);
pBuf[len++] = '(';
for (i = 0; i < attributeCount; i++)
{
DOFObjectID embedOID;
DOFObjectIDAttribute avpDescriptor = DOFObjectID_GetAttributeAtIndex(oid, i);
if (!DOFObjectIDAttribute_IsValid(avpDescriptor))
break;
if (i)
pBuf[len++] = '|';
pBuf[len++] = '{';
pBuf[len++] = OALString_HexDigitToChar((DOFObjectIDAttribute_GetType(avpDescriptor) >> 4) & 0x0F);
pBuf[len++] = OALString_HexDigitToChar((DOFObjectIDAttribute_GetType(avpDescriptor)) & 0x0F);
pBuf[len++] = '}';
pBuf[len++] = ':';
embedOID = DOFObjectID_Create_Bytes(DOFObjectIDAttribute_GetValueSize(avpDescriptor),
DOFObjectIDAttribute_GetValue(avpDescriptor));
if (embedOID)
{
len += ObjectID_ToString(embedOID, &pBuf[len]);
DOFObjectID_Destroy(embedOID);
}
else
{
len += ObjectID_DataToString(DOFObjectIDAttribute_GetValue(avpDescriptor),
DOFObjectIDAttribute_GetValueSize(avpDescriptor), &pBuf[len]);
}
}
pBuf[len++] = ')';
}
pBuf[len++] = ']';
return len;
}
static const gchar* dof_iid_create_standard_string(guint32 bufferSize, const guint8 *pIIDBuffer)
{
gchar *pRetval;
guint len = 9 + (bufferSize - 1) * 2;
pRetval = (gchar *)wmem_alloc(wmem_packet_scope(), len + 1);
if (pRetval)
{
InterfaceID_ToString(pIIDBuffer, pRetval);
pRetval[len] = 0;
}
return pRetval;
}
static const gchar* dof_oid_create_standard_string(guint32 bufferSize, const guint8 *pOIDBuffer)
{
DOFObjectID oid;
gchar *pRetval;
guint32 len = bufferSize;
oid = DOFObjectID_Create_Unmarshal(&len, pOIDBuffer);
if (!oid)
return "Illegal OID";
len = ObjectID_ToStringLength(oid);
pRetval = (gchar *)wmem_alloc(wmem_packet_scope(), len + 1);
if (pRetval)
{
ObjectID_ToString(oid, pRetval);
pRetval[len] = 0;
}
return pRetval;
}
static guint8 parseHexField(struct parseCtx *ctx)
{
if (PARSECTX_READ_CHAR_OID(ctx) == '{' && PARSECTX_PEEK_CHAR_OID(ctx) != '}')
{
while (PARSECTX_PEEK_CHAR_OID(ctx) != '}')
{
if (VALIDHEXBYTE(PARSECTX_GET_CURRENT_POS_OID(ctx)))
{
if (PARSECTX_CHECK_LEN(ctx, 1) == 0)
{
PARSECTX_WRITE_BUF(ctx, HEX2VALUE(PARSECTX_PEEK_CHAR_OID(ctx)) << 4 | HEX2VALUE(PARSECTX_PEEK_NEXT_CHAR_OID(ctx)));
PARSECTX_STEP_OID(ctx, 2);
if (VALIDHEXSEP(PARSECTX_PEEK_CHAR_OID(ctx)))
{
if (PARSECTX_PEEK_NEXT_CHAR_OID(ctx) == '}')
{
return 1;
}
PARSECTX_STEP_OID(ctx, 1);
}
}
else
{
return 1;
}
}
else
{
return 1;
}
}
PARSECTX_STEP_OID(ctx, 1);
return 0;
}
return 1;
}
static guint8 parseStringField(struct parseCtx *ctx)
{
while (ctx->currOidPos < (ctx->oidLen - 1))
{
char curr = PARSECTX_PEEK_CHAR_OID(ctx);
if (curr == ']' || curr == '(')
{
break;
}
else if (curr == '\\')
{
PARSECTX_STEP_OID(ctx, 1);
if (!IS_ESCAPED(PARSECTX_PEEK_CHAR_OID(ctx)) || PARSECTX_CHECK_LEN(ctx, 1) != 0)
return 1;
PARSECTX_WRITE_BUF_FROM_OID(ctx);
}
else
{
if (VALIDASCIICHAR(curr) && PARSECTX_CHECK_LEN(ctx, 1) == 0)
PARSECTX_WRITE_BUF_FROM_OID(ctx);
else
return 1;
}
}
return 0;
}
static guint8 OALMarshal_GetCompressedValueSize(guint8 maxSize, guint32 value)
{
guint8 lenbytes = (1 + (value > 0x7F) + (value > 0x3FFF));
if (lenbytes > 2)
return (maxSize);
return (lenbytes);
}
static guint32 OALMarshal_CompressValue(guint8 maxSize, guint32 value, guint32 bufLength, guint8 *buffer)
{
guint8 lenSize = OALMarshal_GetCompressedValueSize(maxSize, value);
if (bufLength < lenSize)
return 0;
switch (lenSize)
{
case 4:
*(buffer++) = (guint8)((value >> 24) & 0x3F) | 0xC0;
*(buffer++) = (guint8)((value >> 16) & 0xFF);
*(buffer++) = (guint8)((value >> 8) & 0xFF);
*(buffer++) = (guint8)(value & 0xFF);
break;
case 3:
*(buffer++) = (guint8)((value >> 16) & 0x3F) | 0xC0;
*(buffer++) = (guint8)((value >> 8) & 0xFF);
*(buffer++) = (guint8)(value & 0xFF);
break;
case 2:
if (maxSize == 2)
{
*(buffer++) = (guint8)((value >> 8) & 0x7F) | 0x80;
}
else
{
*(buffer++) = (guint8)((value >> 8) & 0x3F) | 0x80;
}
*(buffer++) = (guint8)(value & 0xFF);
break;
case 1:
*(buffer++) = (guint8)(value & 0x7F);
break;
default:
break;
}
return (lenSize);
}
static guint8 parseOIDClass(struct parseCtx *ctx)
{
if (PARSECTX_PEEK_CHAR_OID(ctx) == '{' && PARSECTX_PEEK_NEXT_CHAR_OID(ctx) != '}')
{
guint8 classSize = 0;
guint32 oidClass = 0;
PARSECTX_STEP_OID(ctx, 1);
while (PARSECTX_PEEK_CHAR_OID(ctx) != '}')
{
if (VALIDHEXBYTE(PARSECTX_GET_CURRENT_POS_OID(ctx)))
{
oidClass <<= 8;
oidClass += (HEX2VALUE(PARSECTX_PEEK_CHAR_OID(ctx)) << 4 | HEX2VALUE(PARSECTX_PEEK_NEXT_CHAR_OID(ctx)));
PARSECTX_STEP_OID(ctx, 2);
if (VALIDHEXSEP(PARSECTX_PEEK_CHAR_OID(ctx)))
{
if (PARSECTX_PEEK_NEXT_CHAR_OID(ctx) == '}')
{
return 1;
}
PARSECTX_STEP_OID(ctx, 1);
}
}
else
{
return 1;
}
}
PARSECTX_STEP_OID(ctx, 1);
classSize = OALMarshal_GetCompressedValueSize(4, oidClass);
if (PARSECTX_CHECK_LEN(ctx, classSize) == 0)
{
if (PARSECTX_GET_CURRENT_POS_BUF(ctx))
classSize = OALMarshal_CompressValue(4, oidClass, classSize, PARSECTX_GET_CURRENT_POS_BUF(ctx));
PARSECTX_STEP_BUF(ctx, classSize);
}
return 0;
}
else
{
guint8 classSize = 0;
guint32 oidClass = 0;
while (IS_DIGIT(PARSECTX_PEEK_CHAR_OID(ctx)))
{
oidClass *= 10;
oidClass += DIGIT2VALUE(PARSECTX_PEEK_CHAR_OID(ctx));
PARSECTX_STEP_OID(ctx, 1);
}
classSize = OALMarshal_GetCompressedValueSize(4, oidClass);
if (PARSECTX_CHECK_LEN(ctx, classSize) == 0)
{
if (PARSECTX_GET_CURRENT_POS_BUF(ctx))
classSize = OALMarshal_CompressValue(4, oidClass, classSize, PARSECTX_GET_CURRENT_POS_BUF(ctx));
PARSECTX_STEP_BUF(ctx, classSize);
}
return 0;
}
}
static guint8 parseAttributeID(struct parseCtx *ctx)
{
if (PARSECTX_PEEK_CHAR_OID(ctx) == '{')
{
return parseHexField(ctx);
}
else
{
guint8 avpid = 0;
while (IS_DIGIT(PARSECTX_PEEK_CHAR_OID(ctx)))
{
avpid *= 10;
avpid += DIGIT2VALUE(PARSECTX_PEEK_CHAR_OID(ctx));
PARSECTX_STEP_OID(ctx, 1);
}
if (PARSECTX_CHECK_LEN(ctx, 1) == 0)
{
PARSECTX_WRITE_BUF(ctx, avpid);
return 0;
}
}
return 1;
}
static guint8 parseAttributeData(struct parseCtx *ctx)
{
if (PARSECTX_PEEK_CHAR_OID(ctx) == '[')
{
return parseFormatOID(ctx);
}
else if (PARSECTX_PEEK_CHAR_OID(ctx) == '{')
{
return parseHexField(ctx);
}
else
{
return parseStringField(ctx);
}
}
static guint8 parseAttribute(struct parseCtx *ctx)
{
if (parseAttributeID(ctx) == 0)
{
if (PARSECTX_READ_CHAR_OID(ctx) == ':' && PARSECTX_CHECK_LEN(ctx, 1) == 0)
{
guint8 *length = PARSECTX_GET_CURRENT_POS_BUF(ctx);
if (length == NULL)
return 0;
PARSECTX_STEP_BUF(ctx, 1);
if (parseAttributeData(ctx) == 0)
{
PARSECTX_WRITE_AT_POS_BUF(ctx, length, (guint8)(PARSECTX_GET_CURRENT_POS_BUF(ctx) - (length + 1)));
return 0;
}
}
}
return 1;
}
static guint8 parseAttributes(struct parseCtx *ctx)
{
if (PARSECTX_READ_CHAR_OID(ctx) == '(' && PARSECTX_PEEK_CHAR_OID(ctx) != ')')
{
while (PARSECTX_PEEK_CHAR_OID(ctx) != ')')
{
guint8 *avpID = PARSECTX_GET_CURRENT_POS_BUF(ctx);
if (avpID == NULL)
return 0;
if (parseAttribute(ctx) != 0)
return 1;
if (PARSECTX_PEEK_CHAR_OID(ctx) == '|' && PARSECTX_PEEK_NEXT_CHAR_OID(ctx) != ')')
{
PARSECTX_OR_AT_POS_BUF(ctx, avpID, 0x80);
PARSECTX_STEP_OID(ctx, 1);
}
}
PARSECTX_STEP_OID(ctx, 1);
return 0;
}
return 1;
}
static guint8 parseFormatOID(struct parseCtx *ctx)
{
if (PARSECTX_PEEK_CHAR_OID(ctx) == '[')
{
PARSECTX_STEP_OID(ctx, 1);
if (parseOIDClass(ctx) == 0)
{
if (PARSECTX_READ_CHAR_OID(ctx) == ':' && PARSECTX_CHECK_LEN(ctx, 1) == 0)
{
guint8 *length = PARSECTX_GET_CURRENT_POS_BUF(ctx);
PARSECTX_STEP_BUF(ctx, 1);
if (PARSECTX_PEEK_CHAR_OID(ctx) == '{')
{
if (parseHexField(ctx) != 0)
return 1;
}
else
{
if (parseStringField(ctx) != 0)
return 1;
}
if (length == NULL)
return 0;
PARSECTX_WRITE_AT_POS_BUF(ctx, length, (guint8)(PARSECTX_GET_CURRENT_POS_BUF(ctx) - (length + 1)));
if (PARSECTX_PEEK_CHAR_OID(ctx) == '(')
{
PARSECTX_OR_AT_POS_BUF(ctx, length, 0x80);
if (parseAttributes(ctx) != 0)
return 1;
}
if (PARSECTX_READ_CHAR_OID(ctx) == ']')
{
return 0;
}
}
}
}
return 1;
}
static guint8 dof_oid_create_internal(const char *oid, guint32 *size, guint8 *buffer)
{
struct parseCtx ctx;
ctx.oid = oid;
ctx.buffer = buffer;
ctx.currOidPos = 0;
ctx.currBufferPos = 0;
if (oid)
{
if (size)
{
ctx.buffLen = (*size);
ctx.oidLen = (guint32)strlen(oid);
if (PARSECTX_PEEK_CHAR_OID(&ctx) == '[')
{
if (parseFormatOID(&ctx) == 0)
{
(*size) = ctx.currBufferPos;
return 0;
}
}
else if (PARSECTX_PEEK_CHAR_OID(&ctx) == '{')
{
if (parseHexField(&ctx) == 0)
{
(*size) = ctx.currBufferPos;
return 0;
}
}
(*size) = 0;
}
}
return 1;
}
static void dof_oid_new_standard_string(const char *data, guint32 *rsize, guint8 **oid)
{
if (data)
{
guint8 err;
guint32 size = 0;
err = dof_oid_create_internal(data, &size, NULL);
if (err == 0)
{
*oid = (guint8 *)g_malloc(size + 1);
if (*oid)
{
err = dof_oid_create_internal(data, &size, *oid);
if (err == 0)
{
*rsize = size;
return;
}
g_free(*oid);
}
}
}
*rsize = 0;
*oid = NULL;
}
static gint read_c4(tvbuff_t *tvb, gint offset, guint32 *v, gint *L)
{
guint32 val = 0;
guint8 len = 0;
guint8 b = tvb_get_guint8(tvb, offset++);
int i;
if ((b & 0x80) == 0)
{
len = 1;
b = b & 0x7F;
}
else if ((b & 0x40) == 0)
{
len = 2;
b = b & 0x3F;
}
else
{
len = 4;
b = b & 0x3F;
}
val = b;
for (i = 1; i < len; i++)
val = (val << 8) | tvb_get_guint8(tvb, offset++);
if (L)
*L = len;
if (v)
*v = val;
return offset;
}
static void validate_c4(packet_info *pinfo, proto_item *pi, guint32 val, gint len)
{
if (len > 1 && val < 0x80)
{
expert_add_info_format(pinfo, pi, &ei_c2_c3_c4_format, "DOF Violation: Type.3.1: Compressed 32-bit Compression Manditory.");
}
if (len > 2 && val < 0x4000)
{
expert_add_info_format(pinfo, pi, &ei_c2_c3_c4_format, "DOF Violation: Type.3.1: Compressed 32-bit Compression Manditory.");
}
}
static gint read_c3(tvbuff_t *tvb, gint offset, guint32 *v, gint *L)
{
guint32 val = 0;
guint8 len = 0;
guint8 b = tvb_get_guint8(tvb, offset++);
int i;
if ((b & 0x80) == 0)
{
len = 1;
b = b & 0x7F;
}
else if ((b & 0x40) == 0)
{
len = 2;
b = b & 0x3F;
}
else
{
len = 3;
b = b & 0x3F;
}
val = b;
for (i = 1; i < len; i++)
val = (val << 8) | tvb_get_guint8(tvb, offset++);
if (L)
*L = len;
if (v)
*v = val;
return offset;
}
static void validate_c3(packet_info *pinfo, proto_item *pi, guint32 val, gint len)
{
if (len > 1 && val < 0x80)
{
expert_add_info_format(pinfo, pi, &ei_c2_c3_c4_format, "DOF Violation: Type.2.1: Compressed 24-bit Compression Manditory." );
}
if (len > 2 && val < 0x4000)
{
expert_add_info_format(pinfo, pi, &ei_c2_c3_c4_format, "DOF Violation: Type.2.1: Compressed 24-bit Compression Manditory.");
}
}
static gint read_c2(tvbuff_t *tvb, gint offset, guint16 *v, gint *L)
{
guint16 val = 0;
guint8 b = tvb_get_guint8(tvb, offset++);
if (b & 0x80)
{
b = b & 0x7F;
val = (b << 8) | tvb_get_guint8(tvb, offset++);
if (L)
*L = 2;
}
else
{
val = b;
if (L)
*L = 1;
}
if (v)
*v = val;
return offset;
}
static void validate_c2(packet_info *pinfo, proto_item *pi, guint16 val, gint len)
{
if (len > 1 && val < 0x80)
{
expert_add_info_format(pinfo, pi, &ei_c2_c3_c4_format, "DOF Violation: Type.1.1: Compressed 16-bit Compression Manditory." );
}
}
static void assign_sid_id(dof_api_data *api_data)
{
node_key_to_sid_id_key lookup_key;
node_key_to_sid_id_key *key;
dof_session_data *session;
dof_packet_data *packet;
guint value;
if (!api_data || !api_data->packet || !api_data->session)
return;
session = api_data->session;
packet = (dof_packet_data *)api_data->packet;
if (!packet->sender_sid_id)
{
lookup_key.transport_id = api_data->transport_session->transport_id;
lookup_key.transport_node_id = api_data->transport_packet->sender_id;
lookup_key.dof_id = session->dof_id;
lookup_key.dof_node_id = packet->sender_id;
lookup_key.dof_session_id = session->session_id;
value = GPOINTER_TO_UINT(g_hash_table_lookup(node_key_to_sid_id, &lookup_key));
if (value)
{
gpointer sid_id_key = GUINT_TO_POINTER(value);
gpointer sid_buffer;
packet->sender_sid_id = value;
sid_buffer = g_hash_table_lookup(sid_id_to_sid_buffer, sid_id_key);
if (sid_buffer)
{
packet->sender_sid = (dof_2009_1_pdu_19_sid)sid_buffer;
}
}
else
{
key = g_new0(node_key_to_sid_id_key, 1);
memcpy(key, &lookup_key, sizeof(node_key_to_sid_id_key));
g_hash_table_insert(node_key_to_sid_id, key, GUINT_TO_POINTER(dpp_next_sid_id));
packet->sender_sid_id = dpp_next_sid_id++;
}
}
if (!packet->receiver_sid_id)
{
lookup_key.transport_id = api_data->transport_session->transport_id;
lookup_key.transport_node_id = api_data->transport_packet->receiver_id;
lookup_key.dof_id = session->dof_id;
lookup_key.dof_node_id = packet->receiver_id;
lookup_key.dof_session_id = session->session_id;
value = GPOINTER_TO_UINT(g_hash_table_lookup(node_key_to_sid_id, &lookup_key));
if (value)
{
gpointer sid_id_key = GUINT_TO_POINTER(value);
gpointer sid_buffer;
packet->receiver_sid_id = value;
sid_buffer = g_hash_table_lookup(sid_id_to_sid_buffer, sid_id_key);
if (sid_buffer)
{
packet->receiver_sid = (dof_2009_1_pdu_19_sid)sid_buffer;
}
}
else
{
key = g_new0(node_key_to_sid_id_key, 1);
memcpy(key, &lookup_key, sizeof(node_key_to_sid_id_key));
g_hash_table_insert(node_key_to_sid_id, key, GUINT_TO_POINTER(dpp_next_sid_id));
packet->receiver_sid_id = dpp_next_sid_id++;
}
}
}
static void learn_sender_sid(dof_api_data *api_data, guint8 length, const guint8 *sid)
{
dof_packet_data *packet;
guint8 lookup_key[256];
guint8 *key;
gpointer value;
if (!api_data)
{
return;
}
if (!api_data->packet)
{
return;
}
packet = (dof_packet_data *)api_data->packet;
if (!packet->sender_sid_id)
return;
if (packet->sender_sid)
return;
lookup_key[0] = length;
memcpy(lookup_key + 1, sid, length);
if (g_hash_table_lookup_extended(sid_buffer_to_sid_id, &lookup_key, (gpointer *)&key, &value))
{
guint sid_id = GPOINTER_TO_UINT(value);
if (packet->sender_sid_id == sid_id)
{
packet->sender_sid = key;
return;
}
else
{
guint sid_id_correct = sid_id;
guint sid_id_incorrect = packet->sender_sid_id;
dof_packet_data *ptr = globals.dof_packet_head;
while (ptr)
{
if (ptr->sender_sid_id == sid_id_incorrect)
ptr->sender_sid_id = sid_id_correct;
if (ptr->receiver_sid_id == sid_id_incorrect)
ptr->receiver_sid_id = sid_id_correct;
if (ptr->op.op_sid_id == sid_id_incorrect)
ptr->op.op_sid_id = sid_id_correct;
if (ptr->ref_op.op_sid_id == sid_id_incorrect)
ptr->ref_op.op_sid_id = sid_id_correct;
ptr = ptr->next;
}
}
return;
}
key = (dof_2009_1_pdu_19_sid)g_malloc0(length + 1);
memcpy(key, lookup_key, length + 1);
g_hash_table_insert(sid_buffer_to_sid_id, key, GUINT_TO_POINTER(packet->sender_sid_id));
g_hash_table_insert(sid_id_to_sid_buffer, GUINT_TO_POINTER(packet->sender_sid_id), key);
packet->sender_sid = (dof_2009_1_pdu_19_sid)key;
{
dof_packet_data *ptr = globals.dof_packet_head;
while (ptr)
{
if (ptr->sender_sid_id == packet->sender_sid_id)
ptr->sender_sid = key;
if (ptr->receiver_sid_id == packet->sender_sid_id)
ptr->receiver_sid = key;
ptr = ptr->next;
}
}
}
static void learn_operation_sid(dof_2009_1_pdu_20_opid *opid, guint8 length, const guint8 *sid)
{
guint8 lookup_key[256];
guint8 *key;
gpointer value;
if (opid->op_sid)
return;
lookup_key[0] = length;
memcpy(lookup_key + 1, sid, length);
if (g_hash_table_lookup_extended(sid_buffer_to_sid_id, &lookup_key, (gpointer *)&key, &value))
{
guint sid_id = GPOINTER_TO_UINT(value);
opid->op_sid_id = sid_id;
opid->op_sid = key;
return;
}
key = (dof_2009_1_pdu_19_sid)g_malloc0(length + 1);
memcpy(key, lookup_key, length + 1);
opid->op_sid_id = dpp_next_sid_id++;
g_hash_table_insert(sid_buffer_to_sid_id, key, GUINT_TO_POINTER(opid->op_sid_id));
g_hash_table_insert(sid_id_to_sid_buffer, GUINT_TO_POINTER(opid->op_sid_id), key);
opid->op_sid = (dof_2009_1_pdu_19_sid)key;
}
static void encryptInPlace(guint protocol_id, void *cipher_state, guint8 *ptct, guint8 ptct_len)
{
switch (protocol_id)
{
case DOF_PROTOCOL_CCM:
{
rijndael_ctx *ctx = (rijndael_ctx *)cipher_state;
guint8 ct[16];
if (ptct_len != 16)
{
memset(ptct, 0, ptct_len);
return;
}
rijndael_encrypt(ctx, ptct, ct);
memcpy(ptct, ct, sizeof(ct));
}
break;
case DOF_PROTOCOL_TEP:
{
rijndael_ctx *ctx = (rijndael_ctx *)cipher_state;
guint8 ct[16];
if (ptct_len != 16)
{
memset(ptct, 0, ptct_len);
return;
}
rijndael_encrypt(ctx, ptct, ct);
memcpy(ptct, ct, sizeof(ct));
}
break;
default:
memset(ptct, 0, ptct_len);
return;
}
}
static void generateMac(guint protocol_id, void *cipher_state, guint8 *nonce, const guint8 *epp, gint a_len, guint8 *data, gint len, guint8 *mac, gint mac_len)
{
guint16 i;
guint16 cnt;
mac[0] = 0x43 | (((mac_len - 2) / 2) << 3);
memcpy(mac + 1, nonce, 11);
memset(mac + 12, 0, 4);
mac[14] = len >> 8;
mac[15] = len & 0xFF;
encryptInPlace(protocol_id, cipher_state, mac, 16);
mac[0] ^= (a_len >> 8);
mac[1] ^= (a_len);
i = 2;
for (cnt = 0; cnt < a_len; cnt++, i++)
{
if (i % 16 == 0)
encryptInPlace(protocol_id, cipher_state, mac, 16);
mac[i % 16] ^= epp[cnt];
}
i = 0;
for (cnt = 0; cnt < len; cnt++, i++)
{
if (i % 16 == 0)
encryptInPlace(protocol_id, cipher_state, mac, 16);
mac[i % 16] ^= data[cnt];
}
encryptInPlace(protocol_id, cipher_state, mac, 16);
}
static int decrypt(ccm_session_data *session, ccm_packet_data *pdata, guint8 *nonce, const guint8 *epp, gint a_len, guint8 *data, gint len)
{
unsigned short i;
unsigned char ctr[16];
unsigned char encrypted_ctr[16];
unsigned char mac[16];
unsigned char computed_mac[16];
unsigned int skip;
guint8 *ekey;
if (data == NULL || len == 0)
return 0;
if (session->mac_len < 4 || session->mac_len > 16)
return 0;
if (pdata->period == 0)
ekey = (guint8 *)session->cipher_data;
else
ekey = (guint8 *)g_hash_table_lookup(session->cipher_data_table, GUINT_TO_POINTER(pdata->period));
if (!ekey)
return 0;
#if 0
skip = a_len + 2;
skip /= 16;
if ((a_len + 2) % 16)
skip += 1;
#endif
skip = 0;
ctr[0] = 0x03;
memcpy(ctr + 1, nonce, 11);
ctr[12] = 0;
ctr[13] = 0;
ctr[14] = 0;
ctr[15] = skip;
for (i = 0; i < len - session->mac_len; i++)
{
if (i % 16 == 0)
{
if (ctr[15] == 255)
ctr[14] += 1;
ctr[15] += 1;
memcpy(encrypted_ctr, ctr, 16);
encryptInPlace(session->protocol_id, session->cipher_data, encrypted_ctr, 16);
}
data[i] ^= encrypted_ctr[i % 16];
}
memcpy(mac, data + i, session->mac_len);
ctr[12] = 0;
ctr[13] = 0;
ctr[14] = 0;
ctr[15] = 0;
memcpy(encrypted_ctr, ctr, 16);
encryptInPlace(session->protocol_id, session->cipher_data, encrypted_ctr, 16);
for (i = 0; i < session->mac_len; i++)
mac[i] ^= encrypted_ctr[i];
generateMac(session->protocol_id, session->cipher_data, nonce, epp, a_len, data, (gint)(len - session->mac_len), computed_mac, session->mac_len);
if (!memcmp(mac, computed_mac, session->mac_len))
return 1;
return 0;
}
static int dissect_app_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
col_clear(pinfo->cinfo, COL_INFO);
{
guint16 app;
gint app_len;
read_c2(tvb, 0, &app, &app_len);
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "APP(%u)", app);
if (dissector_try_uint_new(app_dissectors, app, tvb, pinfo, tree, TRUE, data))
{
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_reported_length(tvb);
}
else
{
proto_tree_add_protocol_format(tree, proto_2008_1_app, tvb, 0, app_len,
DOF_APPLICATION_PROTOCOL ", Version: %u", app);
}
}
return 0;
}
static int dof_dissect_dpp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
guint offset = 0;
DISSECTOR_ASSERT(api_data != NULL);
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 header = tvb_get_guint8(tvb, offset);
guint8 dpp_version = header & 0x7F;
guint8 dpp_flags_included = header & 0x80;
proto_item *hi;
proto_tree * dpp_root,*dpp_tree;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "DPPv%u", dpp_version);
hi = proto_tree_add_protocol_format(tree, proto_2008_1_dpp, tvb, offset, 0,
DOF_PRESENTATION_PROTOCOL " Version %u, Flags: %s", dpp_version, dpp_flags_included ? "Included" : "Default");
dpp_root = proto_item_add_subtree(hi, ett_2008_1_dpp);
dpp_tree = proto_tree_add_subtree(dpp_root, tvb, offset, 1, ett_2008_1_dpp_1_header, NULL, "Header");
proto_tree_add_item(dpp_tree, hf_2008_1_dpp_1_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dpp_tree, hf_2008_1_dpp_1_version, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset == tvb_reported_length(tvb))
{
proto_item_set_len(hi, offset);
if (!api_data)
return offset;
if (api_data->transport_session->is_streaming)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "DNP/DPP Negotiation");
if (pinfo->fd->flags.visited &&
api_data->transport_session->negotiation_required &&
((api_data->transport_session->negotiation_complete_at == 0) || (api_data->transport_session->negotiation_complete_at_ts.secs - api_data->transport_session->session_start_ts.secs > 10)))
{
expert_add_info(pinfo, hi, &ei_dof_6_timeout);
}
return offset;
}
}
if (dissector_try_uint_new(dof_dpp_dissectors, dpp_version, tvb, pinfo, dpp_root, FALSE, data))
{
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_reported_length(tvb);
}
}
return 0;
}
static int dof_dissect_dnp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, dof_api_data *api_data, gint offset)
{
guint8 header = tvb_get_guint8(tvb, offset);
guint8 dnp_version = header & 0x7F;
guint8 dnp_flags_included = header & 0x80;
proto_item *main_ti;
proto_tree * dnp_root,*dnp_tree;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "DNPv%u", dnp_version);
main_ti = proto_tree_add_protocol_format(tree, proto_2008_1_dnp, tvb, offset, 0,
DOF_NETWORK_PROTOCOL " Version %u, Flags: %s", dnp_version, dnp_flags_included ? "Included" : "Default");
dnp_root = proto_item_add_subtree(main_ti, ett_2008_1_dnp);
dnp_tree = proto_tree_add_subtree(dnp_root, tvb, offset, 1, ett_2008_1_dnp_header, NULL, "Header");
proto_tree_add_item(dnp_tree, hf_2008_1_dnp_1_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dnp_tree, hf_2008_1_dnp_1_version, tvb, offset, 1, ENC_NA);
if (dissector_try_uint_new(dnp_dissectors, dnp_version, tvb, pinfo, dnp_root, FALSE, api_data))
{
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
}
else
{
proto_item_set_end(main_ti, tvb, 1);
if (((header & 0x80) == 0) && api_data->transport_session->negotiation_required && ((pinfo->fd->num < api_data->transport_session->negotiation_complete_at) || (api_data->transport_session->negotiation_complete_at == 0)))
{
offset += dof_dissect_dpp_common(tvb_new_subset_remaining(tvb, offset + 1), pinfo, tree, api_data);
}
}
if (dnp_flags_included && !api_data->transport_session->negotiation_complete_at)
{
api_data->transport_session->negotiation_complete_at = pinfo->fd->num;
api_data->transport_session->negotiation_complete_at_ts = pinfo->fd->abs_ts;
}
return offset;
}
static int dissect_dof_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
proto_tree *dof_root;
dof_packet_data *packet;
DISSECTOR_ASSERT(api_data != NULL);
DISSECTOR_ASSERT(api_data->transport_session != NULL);
DISSECTOR_ASSERT(api_data->transport_packet != NULL);
packet = (dof_packet_data *)api_data->packet;
if (packet == NULL)
{
api_data->packet = packet = create_packet_data(pinfo);
DISSECTOR_ASSERT(packet != NULL);
packet->is_sent_by_initiator = api_data->transport_packet->is_sent_by_client;
}
if (api_data->transport_session->transport_session_id == 0)
api_data->transport_session->transport_session_id = globals.next_transport_session++;
{
proto_item *ti;
ti = proto_tree_add_protocol_format(tree, proto_2008_1_dof, tvb, 0, tvb_reported_length(tvb), DOF_PROTOCOL_STACK);
dof_root = proto_item_add_subtree(ti, ett_2008_1_dof);
{
ti = proto_tree_add_uint(dof_root, hf_2008_1_dof_session_transport, tvb, 0, 0, api_data->transport_session->transport_session_id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(dof_root, hf_2008_1_dof_is_2_node, tvb, 0, 0, api_data->transport_session->is_2_node);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(dof_root, hf_2008_1_dof_is_streaming, tvb, 0, 0, api_data->transport_session->is_streaming);
PROTO_ITEM_SET_GENERATED(ti);
if (api_data->session)
{
ti = proto_tree_add_uint(dof_root, hf_2008_1_dof_session, tvb, 0, 0, api_data->session->session_id);
PROTO_ITEM_SET_GENERATED(ti);
}
if (api_data->secure_session)
{
ti = proto_tree_add_uint_format(dof_root, hf_2008_1_dof_session, tvb, 0, 0, api_data->secure_session->original_session_id, "DPS Session (Non-secure): %d", api_data->secure_session->original_session_id);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(dof_root, hf_2008_1_dof_frame, tvb, 0, 0, packet->dof_frame);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(dof_root, hf_2008_1_dof_is_from_client, tvb, 0, 0, api_data->transport_packet->is_sent_by_client);
PROTO_ITEM_SET_GENERATED(ti);
}
}
dof_dissect_dnp_common(tvb, pinfo, tree, api_data, 0);
packet->processed = TRUE;
return tvb_reported_length(tvb);
}
static int dissect_tunnel_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dof_packet_ref *ref = (tcp_dof_packet_ref *)data;
gint offset = 0;
offset = 0;
{
guint8 version = tvb_get_guint8(tvb, offset);
guint8 opcode;
proto_item *ti;
proto_tree *app_root;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "TUNv%u", version);
ti = proto_tree_add_protocol_format(tree, proto_2012_1_tunnel, tvb, offset, 0,
"DOF Tunnel Protocol, Version: %u", version);
app_root = proto_item_add_subtree(ti, ett_2012_1_tunnel);
proto_tree_add_item(app_root, hf_2012_1_tunnel_1_version, tvb, offset, 1, ENC_NA);
proto_tree_add_item(app_root, hf_2012_1_tunnel_1_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
opcode = tvb_get_guint8(tvb, offset + 3);
if (opcode == 3)
{
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset + 5, -1, -1);
dissect_dof_common(next_tvb, pinfo, tree, &ref->api_data);
}
}
return tvb_captured_length(tvb);
}
static int dissect_tun_app_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
col_clear(pinfo->cinfo, COL_INFO);
{
guint16 app;
gint app_len;
app = tvb_get_guint8(tvb, 0);
app_len = 1;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "APP(%u)", app);
if (dissector_try_uint(dof_tun_app_dissectors, app, tvb, pinfo, tree))
{
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_captured_length(tvb);
}
else
{
proto_tree_add_protocol_format(tree, proto_2012_1_tunnel, tvb, 0, app_len,
DOF_APPLICATION_PROTOCOL ", Version: %u", app);
}
}
return 0;
}
static udp_session_data* create_udp_session_data(packet_info *pinfo, conversation_t *conversation _U_)
{
udp_session_data *packet = wmem_new0(wmem_file_scope(), udp_session_data);
copy_address_wmem(wmem_file_scope(), &packet->server.addr, &pinfo->dst);
packet->server.port = pinfo->destport;
packet->common.transport_id = proto_2008_1_dof_udp;
{
const guint8 *addr = (const guint8 *)packet->server.addr.data;
if ((packet->server.addr.type == AT_IPv4) && (addr != NULL) && (addr[0] != 224))
packet->common.is_2_node = TRUE;
else
packet->common.is_2_node = FALSE;
}
packet->common.is_streaming = FALSE;
packet->common.session_start_ts = pinfo->fd->abs_ts;
packet->common.negotiation_required = FALSE;
packet->common.negotiation_complete_at = 0;
return packet;
}
static tcp_session_data* create_tcp_session_data(packet_info *pinfo, conversation_t *conversation)
{
tcp_session_data *packet = wmem_new0(wmem_file_scope(), tcp_session_data);
copy_address_wmem(wmem_file_scope(), &packet->client.addr, &conversation->key_ptr->addr1);
packet->client.port = conversation->key_ptr->port1;
copy_address_wmem(wmem_file_scope(), &packet->server.addr, &conversation->key_ptr->addr2);
packet->server.port = conversation->key_ptr->port2;
packet->not_dps = FALSE;
packet->common.transport_id = proto_2008_1_dof_tcp;
packet->common.is_2_node = TRUE;
packet->common.is_streaming = TRUE;
packet->common.session_start_ts = pinfo->fd->abs_ts;
packet->common.negotiation_required = TRUE;
packet->common.negotiation_complete_at = 0;
return packet;
}
static dof_packet_data* create_packet_data(packet_info *pinfo)
{
dof_packet_data *packet = wmem_new0(wmem_file_scope(), dof_packet_data);
packet->frame = pinfo->fd->num;
packet->dof_frame = next_dof_frame++;
if (!globals.dof_packet_head)
{
globals.dof_packet_head = packet;
globals.dof_packet_tail = packet;
}
else
{
globals.dof_packet_tail->next = packet;
globals.dof_packet_tail = packet;
}
return packet;
}
static int dissect_dof_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dof_api_data *api_data = (dof_api_data *)p_get_proto_data(NULL, pinfo, proto_2008_1_dof_udp, 0);
if (api_data == NULL)
{
conversation_t *conversation;
udp_session_data *transport_session;
dof_transport_packet *transport_packet;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, NO_ADDR_B | NO_PORT_B);
if (!conversation)
{
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, NO_ADDR_B | NO_PORT_B);
conversation_set_dissector(conversation, dof_udp_handle);
}
conversation = find_conversation(pinfo->fd->num, &pinfo->dst, &pinfo->src, PT_UDP, pinfo->destport, pinfo->srcport, NO_ADDR_B | NO_PORT_B);
if (conversation)
{
}
if (!conversation)
conversation = conversation_new(pinfo->fd->num, &pinfo->dst, &pinfo->src, PT_UDP, pinfo->destport, pinfo->srcport, NO_ADDR2 | NO_PORT2 | CONVERSATION_TEMPLATE);
transport_session = (udp_session_data *)conversation_get_proto_data(conversation, proto_2008_1_dof_udp);
if (transport_session == NULL)
{
transport_session = create_udp_session_data(pinfo, conversation);
conversation_add_proto_data(conversation, proto_2008_1_dof_udp, transport_session);
}
api_data = wmem_new0(wmem_file_scope(), dof_api_data);
if (api_data == NULL)
return 0;
transport_packet = wmem_new0(wmem_file_scope(), dof_transport_packet);
if (transport_packet == NULL)
return 0;
transport_packet->is_sent_by_client = TRUE;
if (addresses_equal(&transport_session->server.addr, &pinfo->src) && (transport_session->server.port == pinfo->srcport))
transport_packet->is_sent_by_client = FALSE;
transport_packet->sender_id = assign_addr_port_id(&pinfo->src, pinfo->srcport);
transport_packet->receiver_id = assign_addr_port_id(&pinfo->dst, pinfo->destport);
api_data->transport_session = &transport_session->common;
api_data->transport_packet = transport_packet;
p_add_proto_data(NULL, pinfo, proto_2008_1_dof_udp, 0, api_data);
}
return dissect_dof_common(tvb, pinfo, tree, api_data);
}
static gboolean is_retransmission(packet_info *pinfo, tcp_session_data *session, tcp_packet_data *packet, struct tcpinfo *tcpinfo)
{
{
tcp_ignore_data *id;
guint32 sequence = tcpinfo->seq;
if (addresses_equal(&pinfo->src, &session->client.addr) && (pinfo->srcport == session->client.port))
{
id = packet->from_client_ignore_list;
}
else
{
id = packet->from_server_ignore_list;
}
while (id != NULL && id->sequence != sequence)
{
id = id->next;
}
if (id == NULL)
return FALSE;
return id->ignore;
}
return FALSE;
}
static void remember_offset(packet_info *pinfo, tcp_session_data *session, tcp_packet_data *packet, struct tcpinfo *tcpinfo)
{
gboolean ignore = FALSE;
{
tcp_ignore_data **last;
tcp_ignore_data *id;
guint32 sequence;
guint32 *seqptr = NULL;
if (addresses_equal(&pinfo->src, &session->client.addr) && (pinfo->srcport == session->client.port))
{
last = &(packet->from_client_ignore_list);
id = packet->from_client_ignore_list;
sequence = tcpinfo->seq;
seqptr = &session->from_client_seq;
if (LE_SEQ(tcpinfo->seq, session->from_client_seq))
ignore = TRUE;
}
else
{
last = &(packet->from_server_ignore_list);
id = packet->from_server_ignore_list;
sequence = tcpinfo->seq;
seqptr = &session->from_server_seq;
if (LE_SEQ(tcpinfo->seq, session->from_server_seq))
ignore = TRUE;
}
while (id != NULL && id->sequence != tcpinfo->seq)
{
last = &(id->next);
id = id->next;
}
*seqptr = sequence;
if (id == NULL)
{
*last = (tcp_ignore_data *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_ignore_data));
id = *last;
id->ignore = ignore;
id->sequence = tcpinfo->seq;
}
}
}
static int dissect_dof_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation;
tcp_session_data *session;
tcp_packet_data *packet;
struct tcpinfo *tcpinfo = (struct tcpinfo *)data;
guint8 header;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
{
DISSECTOR_ASSERT(conversation != NULL);
}
session = (tcp_session_data *)conversation_get_proto_data(conversation, proto_2008_1_dof_tcp);
if (session == NULL)
{
session = create_tcp_session_data(pinfo, conversation);
if (!session)
{
fprintf(stderr, "! session");
return 0;
}
conversation_add_proto_data(conversation, proto_2008_1_dof_tcp, session);
}
if (session->not_dps)
return 0;
packet = (tcp_packet_data *)p_get_proto_data(NULL, pinfo, proto_2008_1_dof_tcp, 0);
if (packet == NULL)
{
packet = (tcp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_packet_data));
if (!packet)
{
fprintf(stderr, "! packet");
return 0;
}
p_add_proto_data(NULL, pinfo, proto_2008_1_dof_tcp, 0, packet);
}
if (is_retransmission(pinfo, session, packet, tcpinfo))
return 0;
{
gint offset = 0;
while (offset < (gint)tvb_reported_length(tvb))
{
gint available = tvb_ensure_captured_length_remaining(tvb, offset);
int packet_length;
header = tvb_get_guint8(tvb, offset);
if (((header & 0x80) == 0) && session->common.negotiation_required && ((pinfo->fd->num < session->common.negotiation_complete_at) || (session->common.negotiation_complete_at == 0)))
{
packet_length = 2;
if (header > DNP_MAX_VERSION)
{
session->not_dps = TRUE;
return 0;
}
}
else
{
packet_length = dof_dissect_dnp_length(tvb, pinfo, header & 0x7F, &offset);
if (packet_length < 0)
{
session->not_dps = TRUE;
return offset;
}
}
if (packet_length == 0)
{
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return offset;
}
if (available < packet_length)
{
pinfo->desegment_offset = offset;
pinfo->desegment_len = packet_length - available;
return offset;
}
remember_offset(pinfo, session, packet, tcpinfo);
if (is_retransmission(pinfo, session, packet, tcpinfo))
return 0;
{
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, packet_length, packet_length);
tcp_dof_packet_ref *ref;
gint raw_offset = tvb_raw_offset(tvb) + offset;
gboolean ref_is_new = FALSE;
if (packet->dof_packets == NULL)
{
ref_is_new = TRUE;
ref = (tcp_dof_packet_ref *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_dof_packet_ref));
ref->transport_packet.sender_id = assign_addr_port_id(&pinfo->src, pinfo->srcport);
ref->transport_packet.receiver_id = assign_addr_port_id(&pinfo->dst, pinfo->destport);
packet->dof_packets = ref;
ref->start_offset = raw_offset;
}
else
ref = packet->dof_packets;
while (ref->start_offset != raw_offset)
{
if (ref->next)
{
ref = ref->next;
continue;
}
{
tcp_dof_packet_ref *last = ref;
ref_is_new = TRUE;
ref = wmem_new0(wmem_file_scope(), tcp_dof_packet_ref);
if (!ref)
{
fprintf(stderr, "! ref");
return offset;
}
ref->transport_packet.sender_id = last->transport_packet.sender_id;
ref->transport_packet.receiver_id = last->transport_packet.receiver_id;
ref->start_offset = raw_offset;
last->next = ref;
}
}
if (ref_is_new)
{
dof_transport_packet *tp = &(ref->transport_packet);
tp->is_sent_by_client = FALSE;
if (addresses_equal(&session->client.addr, &pinfo->src) &&
(session->client.port == pinfo->srcport))
tp->is_sent_by_client = TRUE;
ref->api_data.transport_session = (dof_transport_session *)&(session->common);
ref->api_data.transport_packet = tp;
}
dissect_dof_common(next_tvb, pinfo, tree, &ref->api_data);
}
offset += packet_length;
}
return offset;
}
}
static int dissect_tunnel_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation;
tcp_session_data *session;
tcp_packet_data *packet;
struct tcpinfo *tcpinfo = (struct tcpinfo *)data;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
{
DISSECTOR_ASSERT(conversation != NULL);
}
session = (tcp_session_data *)conversation_get_proto_data(conversation, proto_2012_1_tunnel);
if (session == NULL)
{
session = create_tcp_session_data(pinfo, conversation);
if (!session)
{
fprintf(stderr, "! session");
return 0;
}
conversation_add_proto_data(conversation, proto_2012_1_tunnel, session);
}
packet = (tcp_packet_data *)p_get_proto_data(NULL, pinfo, proto_2012_1_tunnel, 0);
if (packet == NULL)
{
packet = (tcp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_packet_data));
if (!packet)
{
fprintf(stderr, "! packet");
return 0;
}
p_add_proto_data(NULL, pinfo, proto_2012_1_tunnel, 0, packet);
}
if (is_retransmission(pinfo, session, packet, tcpinfo))
return 0;
{
gint offset = 0;
while (offset < (gint)tvb_reported_length(tvb))
{
gint available = tvb_reported_length_remaining(tvb, offset);
int packet_length;
int header_length;
int i;
if (available < 3)
{
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return offset + available;
}
packet_length = 0;
header_length = 3;
for (i = 0; i < 2; i++)
packet_length = packet_length * 256 + tvb_get_guint8(tvb, offset + 1 + i);
packet_length += header_length;
if (available < packet_length)
{
pinfo->desegment_offset = offset;
pinfo->desegment_len = packet_length - available;
return offset + available;
}
{
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, packet_length, packet_length);
tcp_dof_packet_ref *ref;
gint raw_offset = tvb_raw_offset(tvb) + offset;
gboolean ref_is_new = FALSE;
if (packet->dof_packets == NULL)
{
ref_is_new = TRUE;
ref = (tcp_dof_packet_ref *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_dof_packet_ref));
ref->transport_packet.sender_id = assign_addr_port_id(&pinfo->src, pinfo->srcport);
ref->transport_packet.receiver_id = assign_addr_port_id(&pinfo->dst, pinfo->destport);
packet->dof_packets = ref;
ref->start_offset = raw_offset;
}
else
ref = packet->dof_packets;
while (ref->start_offset != raw_offset)
{
if (ref->next)
{
ref = ref->next;
continue;
}
{
tcp_dof_packet_ref *last = ref;
ref_is_new = TRUE;
ref = (tcp_dof_packet_ref *)wmem_alloc0(wmem_file_scope(), sizeof(tcp_dof_packet_ref));
if (!ref)
{
fprintf(stderr, "! ref");
return offset;
}
ref->transport_packet.sender_id = last->transport_packet.sender_id;
ref->transport_packet.receiver_id = last->transport_packet.receiver_id;
ref->start_offset = raw_offset;
last->next = ref;
}
}
if (ref_is_new)
{
dof_transport_packet *tp = &(ref->transport_packet);
tp->is_sent_by_client = FALSE;
if (addresses_equal(&session->client.addr, &pinfo->src) &&
(session->client.port == pinfo->srcport))
tp->is_sent_by_client = TRUE;
ref->api_data.transport_session = (dof_transport_session *)&(session->common);
ref->api_data.transport_packet = tp;
}
{
dissect_tunnel_common(next_tvb, pinfo, tree, ref);
}
}
offset += packet_length;
}
return tvb_captured_length(tvb);
}
}
static int dissect_dnp_0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint offset = 0;
guint8 dnp_flags_included = 0;
offset = 0;
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 header = tvb_get_guint8(tvb, offset);
dnp_flags_included = (header & 0x80) != 0;
offset += 1;
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DNPv0 ");
if (dnp_flags_included)
{
}
if (tvb_reported_length(tvb) == offset)
col_set_str(pinfo->cinfo, COL_INFO, "Query");
else
{
guint8 first = tvb_get_guint8(tvb, offset);
if (first == 0)
{
col_set_str(pinfo->cinfo, COL_INFO, "Query");
proto_tree_add_item(tree, hf_2008_1_dnp_0_1_1_padding, tvb, offset, -1, ENC_NA);
}
else
{
col_set_str(pinfo->cinfo, COL_INFO, "Query Response");
while (first)
{
proto_tree_add_item(tree, hf_2008_1_dnp_0_1_1_version, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset == tvb_reported_length(tvb))
break;
first = tvb_get_guint8(tvb, offset);
}
if (offset < tvb_reported_length(tvb))
proto_tree_add_item(tree, hf_2008_1_dnp_0_1_1_padding, tvb, offset, -1, ENC_NA);
}
}
}
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_reported_length(tvb);
}
static int determine_packet_length_1(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
gint offset = *((gint *)data);
{
gint available = tvb_ensure_captured_length_remaining(tvb, offset);
guint8 header, flags;
guint8 size;
guint8 i;
gint data_len, header_len;
if (available < 2)
return 0;
header = tvb_get_guint8(tvb, offset);
data_len = 0;
if ((header & 0x80) == 0)
{
data_len = 0;
header_len = 2;
size = 0;
}
else
{
flags = tvb_get_guint8(tvb, offset + 1);
size = flags & 0x03;
header_len = 2 + size;
}
if (available < header_len)
return 0;
for (i = 0; i < size; i++)
data_len = data_len * 256 + tvb_get_guint8(tvb, offset + 2 + i);
return header_len + data_len;
}
}
static int dissect_dnp_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet;
gint8 dnp_version = -1;
guint8 dnp_flags_included = 0;
guint8 dnp_length_length = 0;
guint32 dnp_flags = 0;
guint length = 0;
guint encapsulated_length = 0;
int i;
proto_tree *dnp_tree = tree;
if (!api_data)
{
return 0;
}
if (!api_data->packet)
{
return 0;
}
packet = api_data->packet;
offset = 0;
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 header = tvb_get_guint8(tvb, offset);
guint32 dnp_src_port = 0;
guint32 dnp_dst_port = 0;
dnp_version = header & 0x7F;
dnp_flags_included = (header & 0x80) != 0;
offset += 1;
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DNPv1 ");
if (dnp_flags_included)
{
dnp_flags = tvb_get_guint8(tvb, offset);
if ((dnp_flags & 0xF0) != 0)
expert_add_info(pinfo, NULL, &ei_dof_10_flags_zero);
proto_tree_add_bitmask(dnp_tree, tvb, offset, hf_2009_9_dnp_1_flags, ett_2009_9_dnp_1_flags, bitmask_2009_9_dnp_1_flags, ENC_BIG_ENDIAN);
offset += 1;
}
else
dnp_flags = DNP_V1_DEFAULT_FLAGS;
dnp_length_length = dnp_flags & 0x03;
if (dnp_length_length)
proto_tree_add_item(dnp_tree, hf_2009_9_dnp_1_length, tvb, offset, dnp_length_length, ENC_BIG_ENDIAN);
length = 0;
for (i = 0; i < dnp_length_length; i++)
length = (length << 8) | tvb_get_guint8(tvb, offset + i);
#if 0
if ( (length == 0) && packet->negotiated && session && ! session->connectionless )
{
expert_add_info( pinfo, NULL, &ei_dof_13_length_specified );
}
#endif
offset += dnp_length_length;
if (dnp_length_length == 0)
length = tvb_reported_length(tvb) - offset;
encapsulated_length = length;
if (dnp_flags & 0x04)
{
gint s_offset = offset;
proto_item *item;
gint dnp_src_port_len;
offset = read_c3(tvb, offset, &dnp_src_port, &dnp_src_port_len);
item = proto_tree_add_uint_format(dnp_tree, hf_2009_9_dnp_1_srcport, tvb, s_offset, offset - s_offset, dnp_src_port, "Source Address: %u", dnp_src_port);
validate_c3(pinfo, item, dnp_src_port, dnp_src_port_len);
encapsulated_length -= (offset - s_offset);
}
else
{
proto_item *item = proto_tree_add_uint_format(dnp_tree, hf_2009_9_dnp_1_srcport, tvb, 0, 0, 0, "Source Address: %u", 0);
PROTO_ITEM_SET_GENERATED(item);
}
if (dnp_flags & 0x08)
{
gint s_offset = offset;
gint dnp_dst_port_len;
proto_item *item;
offset = read_c3(tvb, offset, &dnp_dst_port, &dnp_dst_port_len);
item = proto_tree_add_uint_format(dnp_tree, hf_2009_9_dnp_1_dstport, tvb, s_offset, offset - s_offset, dnp_dst_port, "Destination Address: %u", dnp_dst_port);
validate_c3(pinfo, item, dnp_dst_port, dnp_dst_port_len);
encapsulated_length -= (offset - s_offset);
}
else
{
proto_item *item = proto_tree_add_uint_format(dnp_tree, hf_2009_9_dnp_1_dstport, tvb, 0, 0, 0, "Destination Address: %u", 0);
PROTO_ITEM_SET_GENERATED(item);
}
}
proto_item_set_end(tree, tvb, offset);
if (api_data->session == NULL)
{
guint32 client;
guint32 server;
if (api_data->transport_packet->is_sent_by_client)
{
client = dnp_src_port;
server = dnp_dst_port;
}
else
{
client = dnp_dst_port;
server = dnp_src_port;
}
api_data->session = dof_ns_session_retrieve(api_data->transport_session->transport_session_id, client, server);
if (api_data->session == NULL)
{
dof_session_data *sdata = (dof_session_data *)wmem_alloc0(wmem_file_scope(), sizeof(dof_session_data));
dof_ns_session_define(api_data->transport_session->transport_session_id, client, server, sdata);
sdata->session_id = globals.next_session++;
sdata->dof_id = dnp_version;
api_data->session = sdata;
}
}
packet->sender_id = dnp_src_port;
packet->receiver_id = dnp_dst_port;
{
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, encapsulated_length, tvb_reported_length(tvb) - offset);
offset += dof_dissect_dpp_common(next_tvb, pinfo, proto_item_get_parent(tree), data);
}
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return offset;
}
static int dissect_dpp_0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint offset = 0;
guint8 dpp_flags_included = 0;
offset = 0;
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 header = tvb_get_guint8(tvb, offset);
dpp_flags_included = (header & 0x80) != 0;
offset += 1;
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DPPv0 ");
if (dpp_flags_included)
{
}
if (tvb_reported_length(tvb) == offset)
col_set_str(pinfo->cinfo, COL_INFO, "Query");
else
{
guint8 first = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO, "Query Response");
while (first)
{
proto_tree_add_item(tree, hf_2008_1_dpp_0_1_1_version, tvb, offset, 1, ENC_NA);
offset += 1;
if (offset == tvb_reported_length(tvb))
break;
first = tvb_get_guint8(tvb, offset);
}
}
}
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_reported_length(tvb);
}
static int dissect_dpp_v2_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
gint offset = 0;
guint8 opcode;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *dpps_tree;
proto_tree *opid_tree;
if (api_data == NULL)
{
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DPPs ");
offset = 0;
ti = proto_tree_add_item(tree, proto_2009_12_dpp_common, tvb, offset, -1, ENC_NA);
dpps_tree = proto_item_add_subtree(ti, ett_2009_12_dpp_common);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(dpps_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
opcode = tvb_get_guint8(tvb, offset);
if (!packet_data->is_command)
opcode |= OP_2009_12_RESPONSE_FLAG;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, strings_2009_12_dpp_common_opcodes, "Unknown Opcode (%d)"));
proto_tree_add_uint_format(dpps_tree, hf_2009_12_dpp_2_14_opcode, tvb, offset, 1, opcode & 0x3F, "Opcode: %s (%u)", val_to_str(opcode, strings_2009_12_dpp_common_opcodes, "Unknown Opcode (%d)"), opcode & 0x3F);
offset += 1;
switch (opcode)
{
case OP_2009_12_SOURCE_LOST_CMD:
case OP_2009_12_SOURCE_FOUND_CMD:
case OP_2009_12_RENAME_CMD:
packet_data->has_referenced_opid = TRUE;
case OP_2009_12_CANCEL_ALL_CMD:
case OP_2009_12_NODE_DOWN_CMD:
case OP_2009_12_QUERY_RSP:
{
proto_tree *oid_tree;
gint opid_len;
tvbuff_t *next_tvb;
if (packet_data->has_referenced_opid)
{
opid_tree = proto_tree_add_subtree(dpps_tree, tvb, offset, 0, ett_2009_12_dpp_2_opid, NULL, "Operation Identifier");
}
else
{
opid_tree = dpps_tree;
}
oid_tree = proto_tree_add_subtree(opid_tree, tvb, offset, 0, ett_2009_12_dpp_2_opid, NULL, "Source Identifier");
next_tvb = tvb_new_subset(tvb, offset, -1, tvb_reported_length(tvb) - offset);
opid_len = call_dissector_only(dof_oid_handle, next_tvb, pinfo, oid_tree, NULL);
learn_sender_sid(api_data, opid_len, tvb_get_ptr(next_tvb, 0, opid_len));
if (packet_data->has_referenced_opid)
learn_operation_sid(&packet_data->ref_op, opid_len, tvb_get_ptr(next_tvb, 0, opid_len));
offset += opid_len;
}
if (packet_data->has_referenced_opid)
{
guint32 opcnt;
gint opcnt_len;
proto_item *pi;
read_c4(tvb, offset, &opcnt, &opcnt_len);
pi = proto_tree_add_uint_format(opid_tree, hf_2009_12_dpp_2_1_opcnt, tvb, offset, opcnt_len, opcnt, "Operation Count: %u", opcnt);
validate_c4(pinfo, pi, opcnt, opcnt_len);
offset += opcnt_len;
packet_data->ref_op.op_cnt = opcnt;
}
break;
}
return offset;
}
static int dissect_dpp_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
proto_item *ti = NULL;
proto_item *tf = NULL;
proto_item *opid = NULL;
gint opid_start = -1;
guint8 dpp_flags_included = 0;
guint32 dpp_flags = 0;
guint8 dpp_opid_keytype = 0;
proto_tree *dpp_flags_tree;
proto_tree *opid_tree = NULL;
gint offset = 0;
proto_tree *dpp_tree = tree;
if (api_data == NULL)
{
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
return 0;
}
assign_sid_id(api_data);
offset = 0;
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 header = tvb_get_guint8(tvb, offset);
dpp_flags_included = (header & 0x80) != 0;
offset += 1;
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DPPv2 ");
ti = proto_tree_add_uint_format(tree, hf_2008_1_dpp_sid_num, tvb,
0, 0, packet_data->sender_sid_id, "SID ID: %d", packet_data->sender_sid_id);
PROTO_ITEM_SET_GENERATED(ti);
if (packet_data->sender_sid)
{
const gchar *SID = dof_oid_create_standard_string(packet_data->sender_sid[0], packet_data->sender_sid + 1);
ti = proto_tree_add_bytes_format_value(tree, hf_2008_1_dpp_sid_str, tvb, 0, 0, packet_data->sender_sid, "%s", SID);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint_format(tree, hf_2008_1_dpp_rid_num, tvb,
0, 0, packet_data->receiver_sid_id, "RID ID: %d", packet_data->receiver_sid_id);
PROTO_ITEM_SET_GENERATED(ti);
if (packet_data->receiver_sid)
{
const gchar *SID = dof_oid_create_standard_string(packet_data->receiver_sid[0], packet_data->receiver_sid + 1);
ti = proto_tree_add_bytes_format_value(tree, hf_2008_1_dpp_rid_str, tvb, 0, 0, packet_data->receiver_sid, "%s", SID);
PROTO_ITEM_SET_GENERATED(ti);
}
if (dpp_flags_included)
{
dpp_flags = tvb_get_guint8(tvb, offset);
if (((dpp_flags & 0x10) != 0) && ((dpp_flags & 0x0F) != 0))
expert_add_info(pinfo, NULL, &ei_dpp2_dof_10_flags_zero);
if (((dpp_flags & 0x10) == 0) && ((dpp_flags & 0x09) != 0))
expert_add_info(pinfo, NULL, &ei_dpp2_dof_10_flags_zero);
tf = proto_tree_add_uint_format(dpp_tree, hf_2009_12_dpp_2_1_flags, tvb,
offset, 1, dpp_flags, "Flags: 0x%02x", dpp_flags);
dpp_flags_tree = proto_item_add_subtree(tf, ett_2009_12_dpp_2_1_flags);
if (dpp_flags == DPP_V2_DEFAULT_FLAGS)
expert_add_info(pinfo, dpp_flags_tree, &ei_dpp_default_flags);
proto_tree_add_item(dpp_flags_tree, hf_2009_12_dpp_2_1_flag_security, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dpp_flags_tree, hf_2009_12_dpp_2_1_flag_opid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dpp_flags_tree, hf_2009_12_dpp_2_1_flag_cmdrsp, tvb, offset, 1, ENC_NA);
if ((dpp_flags & 0x10) == 0)
{
proto_tree_add_item(dpp_flags_tree, hf_2009_12_dpp_2_1_flag_seq, tvb, offset, 1, ENC_NA);
proto_tree_add_item(dpp_flags_tree, hf_2009_12_dpp_2_1_flag_retry, tvb, offset, 1, ENC_NA);
}
offset += 1;
}
else
dpp_flags = DPP_V2_DEFAULT_FLAGS;
packet_data->is_command = (dpp_flags & 0x10) == 0;
dpp_opid_keytype = (dpp_flags & 0x60) >> 5;
switch (dpp_opid_keytype)
{
case 0:
packet_data->has_opid = FALSE;
break;
case 1:
packet_data->has_opid = TRUE;
packet_data->op.op_sid_id = packet_data->sender_sid_id;
packet_data->op.op_sid = packet_data->sender_sid;
break;
case 2:
packet_data->has_opid = TRUE;
packet_data->op.op_sid_id = packet_data->receiver_sid_id;
packet_data->op.op_sid = packet_data->receiver_sid;
break;
case 3:
packet_data->has_opid = TRUE;
break;
}
if (dpp_opid_keytype != 0)
{
opid_start = offset;
opid_tree = proto_tree_add_subtree(dpp_tree, tvb, offset, 0, ett_2009_12_dpp_2_opid, NULL, "Operation Identifier");
}
switch (dpp_opid_keytype)
{
case 0:
break;
case 3:
{
proto_tree *oid_tree;
tvbuff_t *next_tvb;
gint opid_len;
oid_tree = proto_tree_add_subtree(opid_tree, tvb, offset, 0, ett_2009_12_dpp_2_opid, NULL, "Source Identifier");
next_tvb = tvb_new_subset(tvb, offset, -1, tvb_reported_length(tvb) - offset);
opid_len = call_dissector_only(dof_oid_handle, next_tvb, pinfo, oid_tree, NULL);
proto_item_set_len(oid_tree, opid_len);
learn_operation_sid(&packet_data->op, opid_len, tvb_get_ptr(next_tvb, 0, opid_len));
if (packet_data->op.op_sid_id == packet_data->sender_sid_id)
expert_add_info(pinfo, ti, &ei_dpp_explicit_sender_sid_included);
if (packet_data->op.op_sid_id == packet_data->receiver_sid_id)
expert_add_info(pinfo, ti, &ei_dpp_explicit_receiver_sid_included);
offset += opid_len;
}
case 1:
case 2:
{
guint32 opcnt;
gint opcnt_len;
proto_item *pi;
if ((dpp_opid_keytype != 3) && packet_data->op.op_sid)
{
proto_tree *oid_tree;
tvbuff_t *next_tvb = tvb_new_child_real_data(tvb, packet_data->op.op_sid + 1, packet_data->op.op_sid[0], packet_data->op.op_sid[0]);
oid_tree = proto_tree_add_subtree(opid_tree, tvb, 0, 0, ett_2009_12_dpp_2_opid, NULL, "Source Identifier");
call_dissector_only(dof_oid_handle, next_tvb, pinfo, oid_tree, NULL);
PROTO_ITEM_SET_GENERATED(ti);
}
read_c4(tvb, offset, &opcnt, &opcnt_len);
pi = proto_tree_add_uint_format(opid_tree, hf_2009_12_dpp_2_1_opcnt, tvb, offset, opcnt_len, opcnt, "Operation Count: %u", opcnt);
validate_c4(pinfo, pi, opcnt, opcnt_len);
offset += opcnt_len;
proto_item_set_len(opid, offset - opid_start);
packet_data->op.op_cnt = opcnt;
if (packet_data->has_opid && !packet_data->opid_first)
{
dof_packet_data *first = (dof_packet_data *)g_hash_table_lookup(dpp_opid_to_packet_data, (gconstpointer) & packet_data->op);
if (first == NULL)
{
g_hash_table_insert(dpp_opid_to_packet_data, (gpointer) & packet_data->op, (gpointer)packet_data);
packet_data->opid_first = packet_data;
packet_data->opid_last = packet_data;
}
else
{
packet_data->opid_first = first;
first->opid_last->opid_next = packet_data;
first->opid_last = packet_data;
if (!packet_data->is_command)
{
if (!first->opid_first_response)
{
first->opid_first_response = packet_data;
first->opid_last_response = packet_data;
}
else
{
first->opid_last_response->opid_next_response = packet_data;
first->opid_last_response = packet_data;
}
}
}
}
if (globals.track_operations && tree)
{
proto_tree *ophistory_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_2009_12_dpp_2_opid_history, NULL, "Operation History");
dof_packet_data *ptr = packet_data->opid_first;
if (ptr)
proto_tree_add_uint_format(ophistory_tree, hf_2008_1_dpp_first_command,
tvb, 0, 0, ptr->frame,
"First Operation: %u",
ptr->frame);
if (ptr->opid_last && ptr->opid_last != ptr)
proto_tree_add_uint_format(ophistory_tree, hf_2008_1_dpp_last_command,
tvb, 0, 0, ptr->opid_last->frame,
"Last Operation: %u",
ptr->opid_last->frame);
if (ptr->opid_first_response)
proto_tree_add_uint_format(ophistory_tree, hf_2008_1_dpp_first_response,
tvb, 0, 0, ptr->opid_first_response->frame,
"First Response: %u",
ptr->opid_first_response->frame);
if (ptr->opid_last_response && ptr->opid_last_response != ptr->opid_first_response)
proto_tree_add_uint_format(ophistory_tree, hf_2008_1_dpp_last_response,
tvb, 0, 0, ptr->opid_last_response->frame,
"Last Response: %u",
ptr->opid_last_response->frame);
{
dof_packet_data *start = packet_data->opid_first;
guint diff = 0;
while (ptr)
{
if (ptr == packet_data)
break;
ptr = ptr->opid_next;
diff += 1;
if (diff > globals.track_operations_window)
{
start = start->opid_next;
diff -= 1;
}
}
ptr = start;
diff = 0;
while (ptr)
{
const char *THIS = "";
if (ptr == packet_data)
{
THIS = "this ";
diff = globals.track_operations_window + 1;
}
proto_tree_add_uint_format(ophistory_tree, hf_2008_1_dpp_related_frame,
tvb, 0, 0, ptr->frame,
"%u[ws %u]: %u->%u: %s%s",
ptr->dof_frame, ptr->frame,
ptr->sender_sid_id, ptr->receiver_sid_id,
THIS,
ptr->summary ? ptr->summary : "");
ptr = ptr->opid_next;
if (diff && !--diff)
break;
}
}
}
}
break;
}
proto_item_set_len(opid_tree, offset - opid_start);
{
if ((dpp_flags & 0x10) == 0)
{
guint8 dpp_seq = 0;
guint8 dpp_retry = 0;
guint16 dpp_delay = 0;
if (dpp_flags & 0x04)
{
dpp_seq = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(dpp_tree, hf_2009_12_dpp_2_1_seq, tvb, offset, 1, dpp_seq, "Sequence: %u", dpp_seq);
offset += 1;
}
if (dpp_flags & 0x02)
{
dpp_retry = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(dpp_tree, hf_2009_12_dpp_2_1_retry, tvb, offset, 1, dpp_retry, "Retry: %u", dpp_retry);
offset += 1;
}
{
dpp_delay = tvb_get_guint8(tvb, offset);
if (dpp_delay > 128)
dpp_delay = 128 + ((dpp_delay - 128) * 32);
proto_tree_add_uint_format(dpp_tree, hf_2009_12_dpp_2_1_delay, tvb, offset, 1, dpp_delay, "Delay: %u seconds", dpp_delay);
offset += 1;
}
packet_data->summary = wmem_strdup_printf(wmem_file_scope(), "command seq %u, retry %u, delay %u", dpp_seq, dpp_retry, dpp_delay);
}
else
packet_data->summary = "response";
}
if (dpp_flags & 0x80)
{
guint32 sec_offset = offset;
guint8 sh_flags;
guint32 ssid;
proto_tree *security_tree;
proto_tree *sec_flags_tree;
proto_item *item;
security_tree = proto_tree_add_subtree(dpp_tree, tvb, offset, -1, ett_2009_12_dpp_2_3_security, NULL, "Security Header");
sh_flags = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint_format(security_tree, hf_2009_12_dpp_2_3_sec_flags, tvb,
offset, 1, sh_flags, "Flags: 0x%02x", sh_flags);
sec_flags_tree = proto_item_add_subtree(item, ett_2009_12_dpp_2_3_sec_flags);
proto_tree_add_item(sec_flags_tree, hf_2009_12_dpp_2_3_sec_flag_secure, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sec_flags_tree, hf_2009_12_dpp_2_3_sec_flag_rdid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sec_flags_tree, hf_2009_12_dpp_2_3_sec_flag_partition, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sec_flags_tree, hf_2009_12_dpp_2_3_sec_flag_as, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sec_flags_tree, hf_2009_12_dpp_2_3_sec_flag_ssid, tvb, offset, 1, ENC_NA);
offset += 1;
ssid = 0;
if (sh_flags & DPP_V2_SEC_FLAG_S)
{
gint s_offset = offset;
gint ssid_len;
proto_item *pi;
offset = read_c4(tvb, offset, &ssid, &ssid_len);
pi = proto_tree_add_uint_format(security_tree, hf_2009_12_dpp_2_3_sec_ssid, tvb, s_offset, offset - s_offset, ssid, "Security State Identifier: %u (0x%x)", ssid, ssid);
validate_c4(pinfo, pi, ssid, ssid_len);
}
if (sh_flags & DPP_V2_SEC_FLAG_A)
ssid |= AS_ASSIGNED_SSID;
if (api_data->session && !api_data->secure_session)
{
dof_secure_session_data *search = api_data->session->secure_sessions;
while (search)
{
if (ssid == search->ssid)
break;
search = search->next;
}
if (search)
{
api_data->session = search->parent;
api_data->secure_session = search;
}
}
if (sh_flags & DPP_V2_SEC_FLAG_D)
{
gint s_offset = offset;
guint32 rdid;
gint rdid_len;
proto_item *pi;
offset = read_c4(tvb, offset, &rdid, &rdid_len);
pi = proto_tree_add_uint_format(security_tree, hf_2009_12_dpp_2_3_sec_rdid, tvb, s_offset, offset - s_offset, rdid, "Remote Domain Identifier: %u (0x%x)", rdid, rdid);
validate_c4(pinfo, pi, rdid, rdid_len);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_10, tvb, pinfo, security_tree,
offset, hf_2009_12_dpp_2_3_sec_remote_partition, ett_2009_12_dpp_2_3_sec_remote_partition, NULL);
}
if (sh_flags & DPP_V2_SEC_FLAG_P)
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_10, tvb, pinfo, security_tree,
offset, hf_2009_12_dpp_2_3_sec_partition, ett_2009_12_dpp_2_3_sec_partition, NULL);
}
if (sh_flags & DPP_V2_SEC_FLAG_E)
{
if (packet_data->security_session_error)
{
col_set_str(pinfo->cinfo, COL_INFO, packet_data->security_session_error);
proto_item_set_end(tree, tvb, offset);
expert_add_info(pinfo, security_tree, &ei_dpp_no_security_context);
{
tvbuff_t *data_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(undissected_data_handle, data_tvb, pinfo, tree);
}
proto_item_set_len(security_tree, offset - sec_offset);
return offset;
}
if (!api_data->secure_session)
{
packet_data->security_session_error = "[Encrypted - No Session Available]";
proto_item_set_len(security_tree, offset - sec_offset);
return offset;
}
{
dissector_table_t sec_header = find_dissector_table("dof.secmode");
dissector_handle_t dp = dissector_get_uint_handle(sec_header, 0x6001);
if (dp)
{
dof_secmode_api_data sdata;
sdata.context = HEADER;
sdata.security_mode_offset = offset;
sdata.dof_api = api_data;
sdata.secure_session = api_data->secure_session;
sdata.session_key_data = NULL;
offset += call_dissector_only(dp, tvb, pinfo, security_tree, &sdata);
if (!packet_data->decrypted_buffer)
{
proto_item_set_end(tree, tvb, offset);
proto_item_set_len(security_tree, offset - sec_offset);
return offset;
}
}
}
}
proto_item_set_len(security_tree, offset - sec_offset);
}
proto_item_set_end(tree, tvb, offset);
}
if (packet_data->decrypted_tvb)
{
tvb = packet_data->decrypted_tvb;
offset = packet_data->decrypted_offset;
}
{
guint16 app;
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, -1, tvb_reported_length(tvb) - offset);
read_c2(tvb, offset, &app, NULL);
if (app == 0x7FFF)
{
offset += dissect_dpp_v2_common(next_tvb, pinfo, proto_item_get_parent(tree), data);
}
else
{
offset += dissect_app_common(next_tvb, pinfo, proto_item_get_parent(tree), data);
}
}
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
return offset;
}
static int dissect_options(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
while (offset < (gint)tvb_captured_length(tvb))
{
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_2008_1_dsp_12_option, NULL, "Option");
tvbuff_t *next_tvb = tvb_new_subset(tvb, offset, -1, -1);
gint len = dissect_2008_1_dsp_1(next_tvb, pinfo, subtree);
proto_item_set_len(proto_tree_get_parent(subtree), len);
offset += len;
}
return offset;
}
static int dissect_dsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
guint offset = 0;
guint8 opcode;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *dsp_tree;
proto_tree *options_tree;
if (api_data == NULL)
{
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DSPv2 ");
offset = 0;
ti = proto_tree_add_item(tree, proto_2008_1_dsp, tvb, offset, -1, ENC_NA);
dsp_tree = proto_item_add_subtree(ti, ett_2008_1_dsp_12);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(dsp_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
#if 0
if (!packet->is_streaming)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DSPv2 ");
if (tvb_captured_length(tvb) == offset)
col_set_str(pinfo->cinfo, COL_INFO, "Query");
else
{
col_set_str(pinfo->cinfo, COL_INFO, "Query Response");
while (offset < tvb_captured_length(tvb))
{
guint16 app;
gint start = offset;
offset = read_c2(tvb, offset, &app, NULL);
proto_tree_add_uint(dsp_tree, hf_2008_1_app_version, tvb, start, offset - start, app);
}
}
return offset;
}
#endif
if (offset == tvb_captured_length(tvb))
{
col_append_str(pinfo->cinfo, COL_INFO, "DSP [nop]");
expert_add_info(pinfo, dsp_tree, &ei_implicit_no_op);
return offset;
}
opcode = tvb_get_guint8(tvb, offset);
if (!packet_data->is_command)
opcode |= OP_2008_1_RSP;
proto_tree_add_uint_format(dsp_tree, hf_2008_1_dsp_12_opcode, tvb, offset, 1, opcode, "Opcode: %s (%u)", val_to_str(opcode, strings_2008_1_dsp_opcodes, "Unknown Opcode (%d)"), opcode & 0x7F);
offset += 1;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, "/", "%s", val_to_str(opcode, strings_2008_1_dsp_opcodes, "Unknown Opcode (%d)"));
switch (opcode)
{
case OP_2008_1_OPEN_CMD:
break;
case OP_2008_1_OPEN_RSP:
case OP_2008_1_OPEN_SECURE_RSP:
{
while (offset < tvb_captured_length(tvb))
{
guint16 ap;
gint length;
proto_item *pi;
gint start = offset;
offset = read_c2(tvb, offset, &ap, &length);
pi = proto_tree_add_uint(dsp_tree, hf_2008_1_app_version, tvb, start, offset - start, ap);
validate_c2(pinfo, pi, ap, length);
}
}
break;
case OP_2008_1_QUERY_CMD:
break;
case OP_2008_1_QUERY_RSP:
break;
case OP_2008_1_CONFIG_ACK:
break;
case OP_2008_1_CONFIG_REQ:
case OP_2008_1_CONFIG_NAK:
{
gint length = tvb_captured_length(tvb) - offset;
options_tree = proto_tree_add_subtree_format(dsp_tree, tvb, offset, length, ett_2008_1_dsp_12_options, NULL,
"DSP Options: (%d byte%s)", length, plurality(length, "", "s"));
offset = dissect_options(tvb, offset, pinfo, options_tree, NULL);
}
break;
case OP_2008_1_CONFIG_REJ:
break;
case OP_2008_1_TERMINATE_CMD:
case OP_2008_1_TERMINATE_RSP:
break;
}
return offset;
}
static int dissect_ccm_dsp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_item *parent = proto_tree_get_parent(tree);
guint8 len, strength_count, i;
proto_item *ti;
proto_tree *ccm_tree;
proto_item_append_text(parent, " (CCM)");
offset += 3;
len = tvb_get_guint8(tvb, offset++);
ti = proto_tree_add_item(tree, hf_ccm_dsp_option, tvb, offset, len, ENC_NA);
ccm_tree = proto_item_add_subtree(ti, ett_ccm_dsp_option);
strength_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ccm_tree, hf_ccm_dsp_strength_count, tvb, offset++, 1, ENC_NA);
for (i = 0; i < strength_count; i++)
proto_tree_add_item(ccm_tree, hf_ccm_dsp_strength, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(ccm_tree, hf_ccm_dsp_e_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_tree, hf_ccm_dsp_m_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_tree, hf_ccm_dsp_tmax, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_tree, hf_ccm_dsp_tmin, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static int dissect_ccm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_secmode_api_data *secmode_api_data;
dof_session_key_exchange_data *key_data;
secmode_api_data = (dof_secmode_api_data *)data;
if (secmode_api_data == NULL)
{
fprintf(stderr, "secmode_api_data == NULL");
return 0;
}
key_data = secmode_api_data->session_key_data;
switch (secmode_api_data->context)
{
case INITIALIZE:
{
ccm_session_data *ccm_data = (ccm_session_data *)key_data->security_mode_key_data;
gint offset = 0;
guint8 header;
guint16 length;
if (!ccm_data)
{
ccm_data = (ccm_session_data *)wmem_alloc0(wmem_file_scope(), sizeof(ccm_session_data));
if (!ccm_data)
return 0;
key_data->security_mode_key_data = ccm_data;
if (!key_data->security_mode_data || key_data->security_mode_data_length < 3)
return 0;
ccm_data->protocol_id = DOF_PROTOCOL_CCM;
ccm_data->cipher = key_data->security_mode_data[1];
ccm_data->encrypted = key_data->security_mode_data[key_data->security_mode_data_length - 1] & 0x80;
ccm_data->mac_len = (key_data->security_mode_data[key_data->security_mode_data_length - 1] & 0x07) * 2 + 2;
ccm_data->client_datagram_number = 0;
ccm_data->server_datagram_number = 0;
switch (ccm_data->protocol_id)
{
case DOF_PROTOCOL_CCM:
ccm_data->cipher_data = wmem_alloc0(wmem_file_scope(), sizeof(rijndael_ctx));
break;
default:
return 0;
}
}
if (secmode_api_data->dof_api->transport_session->is_2_node)
{
switch (ccm_data->protocol_id)
{
case DOF_PROTOCOL_CCM:
rijndael_set_key((rijndael_ctx *)ccm_data->cipher_data, key_data->session_key, 256);
break;
default:
return 0;
}
return 2;
}
offset = read_c2(tvb, offset, &length, NULL);
header = tvb_get_guint8(tvb, offset);
offset += 1;
{
guint8 period = (header & 0x70) >> 4;
if (ccm_data->cipher_data_table == NULL)
{
guint8 *ekey = (guint8 *)wmem_alloc0(wmem_file_scope(), sizeof(rijndael_ctx));
ccm_data->cipher_data_table = g_hash_table_new(g_direct_hash, g_direct_equal);
ccm_data->period = 1;
ccm_data->periods[period] = ccm_data->period;
switch (ccm_data->protocol_id)
{
case DOF_PROTOCOL_CCM:
rijndael_set_key((rijndael_ctx *)ekey, key_data->session_key, 256);
break;
default:
return 0;
}
g_hash_table_insert(ccm_data->cipher_data_table, GUINT_TO_POINTER(ccm_data->period), ekey);
}
else
{
guint32 lookup = ccm_data->periods[period];
if (!lookup)
{
guint8 *ekey = (guint8 *)wmem_alloc0(wmem_file_scope(), sizeof(rijndael_ctx));
switch (ccm_data->protocol_id)
{
case DOF_PROTOCOL_CCM:
rijndael_set_key((rijndael_ctx *)ekey, key_data->session_key, 256);
break;
default:
return 0;
}
ccm_data->period += 1;
ccm_data->periods[period] = ccm_data->period;
g_hash_table_insert(ccm_data->cipher_data_table, GUINT_TO_POINTER(ccm_data->period), ekey);
}
else
{
guint8 *in_table = (guint8 *)g_hash_table_lookup(ccm_data->cipher_data_table, GUINT_TO_POINTER(lookup));
if (memcmp(key_data->session_key, in_table, 32) != 0)
{
guint8 *ekey = (guint8 *)wmem_alloc0(wmem_file_scope(), sizeof(rijndael_ctx));
switch (ccm_data->protocol_id)
{
case DOF_PROTOCOL_CCM:
rijndael_set_key((rijndael_ctx *)ekey, key_data->session_key, 256);
break;
default:
return 0;
}
ccm_data->period += 1;
ccm_data->periods[period] = ccm_data->period;
g_hash_table_insert(ccm_data->cipher_data_table, GUINT_TO_POINTER(ccm_data->period), ekey);
}
}
}
}
return offset + length - 1;
}
case HEADER:
{
ccm_session_data *session;
dof_transport_session *transport_session = (dof_transport_session *)secmode_api_data->dof_api->transport_session;
dof_secure_session_data *secure_session = secmode_api_data->secure_session;
dof_session_key_exchange_data *security_data = NULL;
dof_packet_data *dof_packet = secmode_api_data->dof_api->packet;
guint8 ccm_flags;
guint32 nid;
guint16 slot = 0;
guint32 pn = 0;
gboolean pn_present = FALSE;
guint32 tnid;
guint32 nnid;
proto_tree *ccm_flags_tree;
proto_tree *header_tree;
proto_item * item,*header;
ccm_packet_data *pdata;
gint offset = 0;
if (!dof_packet->security_session)
{
if (transport_session->is_streaming)
{
security_data = secure_session->session_security_data;
while (security_data)
{
if (dof_packet->is_sent_by_initiator && (dof_packet->dof_frame > security_data->i_valid))
break;
if (!dof_packet->is_sent_by_initiator && (dof_packet->dof_frame > security_data->r_valid))
break;
security_data = security_data->next;
}
if (security_data)
dof_packet->security_session = security_data;
else
{
dof_packet->security_session_error = "[Encrypted - No Session Available]";
return offset;
}
}
else
{
dof_packet->security_session = secure_session->session_security_data;
security_data = dof_packet->security_session;
}
}
else
{
security_data = dof_packet->security_session;
}
if (!security_data || !security_data->session_key || !security_data->security_mode_key_data)
{
dof_packet->security_session_error = "[Encrypted - No Session Available]";
return offset;
}
session = (ccm_session_data *)security_data->security_mode_key_data;
offset = secmode_api_data->security_mode_offset;
header = proto_tree_add_protocol_format(tree, proto_ccm, tvb, offset, 0,
"CCM Security Mode, Version: 1");
header_tree = proto_item_add_subtree(header, ett_header);
tree = header_tree;
ccm_flags = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_flags, tvb,
offset, 1, ccm_flags, "Flags: 0x%02x", ccm_flags);
ccm_flags_tree = proto_item_add_subtree(item, ett_epp_v1_ccm_flags);
proto_tree_add_item(ccm_flags_tree, hf_epp_v1_ccm_flags_manager, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_flags_tree, hf_epp_v1_ccm_flags_period, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_flags_tree, hf_epp_v1_ccm_flags_target, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_flags_tree, hf_epp_v1_ccm_flags_next_nid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ccm_flags_tree, hf_epp_v1_ccm_flags_packet, tvb, offset, 1, ENC_NA);
offset += 1;
if (ccm_flags & 0x01)
pn_present = TRUE;
pdata = (ccm_packet_data *)dof_packet->security_packet;
if (!pdata)
{
pdata = (ccm_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(ccm_packet_data));
if (pdata)
{
dof_packet->security_packet = pdata;
if (transport_session->is_2_node)
{
if (dof_packet->is_sent_by_initiator)
{
pdata->nid = 0;
if (pn_present == FALSE)
pdata->dn = ++session->client_datagram_number;
else
pdata->dn = pn;
}
else
{
pdata->nid = 1;
if (pn_present == 0)
pdata->dn = ++session->server_datagram_number;
else
pdata->dn = pn;
}
}
else
{
guint8 packet_period = (ccm_flags & 0x70) >> 4;
pdata->period = session->periods[packet_period];
}
}
}
if (!pdata)
return offset - secmode_api_data->security_mode_offset;
if (!secure_session->is_2_node)
{
gint nid_len;
proto_item *pi;
read_c4(tvb, offset, &nid, &nid_len);
nid /= 2;
pdata->nid = nid;
pi = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_nid, tvb, offset, nid_len, nid, "Node ID: %u", nid);
validate_c4(pinfo, pi, nid, nid_len);
offset += nid_len;
}
else
{
item = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_nid, tvb, 0, 0, pdata->nid, "Node ID: %u", pdata->nid);
PROTO_ITEM_SET_GENERATED(item);
}
if (!secure_session->is_2_node)
{
gint slot_len;
proto_item *pi;
read_c2(tvb, offset, &slot, &slot_len);
pi = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_slot, tvb, offset, slot_len, slot, "Slot: %hu", slot);
validate_c2(pinfo, pi, slot, slot_len);
offset += slot_len;
}
else
{
item = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_slot, tvb, 0, 0, 0, "Slot: %u", 0);
PROTO_ITEM_SET_GENERATED(item);
}
if (ccm_flags & 0x01)
{
gint pn_len;
proto_item *pi;
read_c4(tvb, offset, &pn, &pn_len);
pi = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_pn, tvb, offset, pn_len, pn, "Packet Number: %u", pn);
validate_c4(pinfo, pi, pn, pn_len);
pdata->dn = pn;
offset += pn_len;
}
else
{
item = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_pn, tvb, 0, 0, pdata->dn, "Packet Number: %u", pdata->dn);
PROTO_ITEM_SET_GENERATED(item);
}
if (ccm_flags & 0x08)
{
gint tnid_len;
proto_item *pi;
read_c4(tvb, offset, &tnid, &tnid_len);
pi = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_tnid, tvb, offset, tnid_len, tnid, "Target Node ID: %u", tnid);
validate_c4(pinfo, pi, tnid, tnid_len);
offset += tnid_len;
}
if (ccm_flags & 0x02)
{
gint nnid_len;
proto_item *pi;
read_c4(tvb, offset, &nnid, &nnid_len);
pi = proto_tree_add_uint_format(tree, hf_epp_v1_ccm_nnid, tvb, offset, nnid_len, nnid, "Next Node ID: %u", nnid);
validate_c4(pinfo, pi, nnid, nnid_len);
offset += nnid_len;
}
proto_item_set_len(header, offset - secmode_api_data->security_mode_offset);
if (dof_packet->decrypted_buffer_error)
{
col_set_str(pinfo->cinfo, COL_INFO, dof_packet->decrypted_buffer_error);
expert_add_info(pinfo, tree, &ei_decode_failure);
return offset - secmode_api_data->security_mode_offset;
}
{
gint e_len = tvb_captured_length(tvb) - offset;
const guint8 *epp_buf = tvb_get_ptr(tvb, 0, -1);
guint a_len = offset;
guint16 e_off;
guint8 *buf = (guint8 *)g_malloc(e_len);
tvbuff_t *app;
guint8 nonce[] = { 0x00, 0x00, 0x00, 0x00,
0x00, 0x00,
0x00,
0x00, 0x00, 0x00, 0x00 };
nonce[0] = (pdata->nid) >> 24;
nonce[1] = (pdata->nid) >> 16;
nonce[2] = (pdata->nid) >> 8;
nonce[3] = (guint8)(pdata->nid);
nonce[4] = slot >> 8;
nonce[5] = (guint8)slot;
nonce[7] = (pdata->dn) >> 24;
nonce[8] = (pdata->dn) >> 16;
nonce[9] = (pdata->dn) >> 8;
nonce[10] = (guint8)(pdata->dn);
for (e_off = 0; e_off < e_len; e_off++)
buf[e_off] = tvb_get_guint8(tvb, offset + e_off);
app = NULL;
proto_item_set_end(tree, tvb, offset);
if (!session->encrypted)
{
g_free(buf);
app = tvb_new_subset(tvb, offset, e_len - session->mac_len, e_len - session->mac_len);
dof_packet->decrypted_tvb = app;
dof_packet->decrypted_offset = 0;
}
else
{
if (dof_packet->decrypted_buffer)
{
app = tvb_new_real_data((const guint8 *)dof_packet->decrypted_buffer, e_len - session->mac_len, e_len - session->mac_len);
tvb_set_child_real_data_tvbuff(tvb, app);
add_new_data_source(pinfo, app, "Decrypted DOF");
dof_packet->decrypted_tvb = app;
dof_packet->decrypted_offset = 0;
}
else
{
if (decrypt(session, pdata, nonce, epp_buf, a_len, buf, e_len))
{
guint8 *cache = (guint8 *)wmem_alloc0(wmem_file_scope(), e_len - session->mac_len);
memcpy(cache, buf, e_len - session->mac_len);
app = tvb_new_real_data(cache, e_len - session->mac_len, e_len - session->mac_len);
tvb_set_child_real_data_tvbuff(tvb, app);
add_new_data_source(pinfo, app, "Decrypted DOF");
dof_packet->decrypted_buffer = cache;
dof_packet->decrypted_offset = 0;
dof_packet->decrypted_tvb = app;
g_free(buf);
}
else
{
dof_packet->decrypted_buffer_error = "[Encrypted packet - decryption failure]";
g_free(buf);
}
}
}
}
return offset - secmode_api_data->security_mode_offset;
}
break;
case TRAILER:
break;
}
return 0;
}
static int dissect_ccm_app(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint8 opcode = 0;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *ccm_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CCM ");
offset = 0;
ti = proto_tree_add_item(tree, proto_ccm_app, tvb, offset, -1, ENC_NA);
ccm_tree = proto_item_add_subtree(ti, ett_ccm);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(ccm_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
opcode = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, ccm_opcode_strings, "Unknown Opcode (%d)"));
if (tree)
{
proto_tree_add_item(ccm_tree, hf_ccm_opcode, tvb, offset, 1, ENC_NA);
#if 0
offset += 1;
switch (opcode)
{
case CCM_PDU_PROBE:
{
}
break;
}
#endif
}
return 1;
}
static int dissect_oap_dsp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint offset = 0;
if (!tree)
return 0;
offset += 4;
proto_tree_add_item(tree, hf_oap_1_dsp_option, tvb, 0, -1, ENC_NA);
return offset;
}
static int dissect_oap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
gint offset = 0;
guint8 opcode = 0;
guint8 flags = 0;
guint16 item_id = 0;
guint16 app;
guint app_len;
oap_1_packet_data *oap_packet = NULL;
proto_item *ti;
proto_tree *oap_tree;
if (api_data == NULL)
{
fprintf(stderr, "api_data == NULL");
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
fprintf(stderr, "packet_data == NULL");
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OAPv1 ");
offset = 0;
ti = proto_tree_add_item(tree, proto_oap_1, tvb, offset, -1, ENC_NA);
oap_tree = proto_item_add_subtree(ti, ett_oap_1);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(oap_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
if (app_len == tvb_captured_length(tvb))
{
col_append_str(pinfo->cinfo, COL_INFO, "OAP [nop]");
expert_add_info(pinfo, oap_tree, &ei_implicit_no_op);
return app_len;
}
oap_packet = (oap_1_packet_data *)dof_packet_get_proto_data(packet_data, proto_oap_1);
if (!oap_packet)
{
oap_packet = (oap_1_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(oap_1_packet_data));
dof_packet_add_proto_data(packet_data, proto_oap_1, oap_packet);
}
opcode = tvb_get_guint8(tvb, offset) & 0x1F;
if (!packet_data->is_command)
opcode |= OAP_1_RESPONSE;
flags = tvb_get_guint8(tvb, offset) & 0xE0;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, oap_opcode_strings, "Unknown Opcode (%d)"));
{
guint8 mask = 0x10;
char str[20];
guint8 no_of_bits = 5;
guint8 i;
guint8 bit = 3;
g_strlcpy(str, "...", 20);
for (i = 0; i < no_of_bits; i++)
{
if (bit && (!(bit % 4)))
g_strlcat(str, " ", 20);
bit++;
if (opcode & mask)
g_strlcat(str, "1", 20);
else
g_strlcat(str, "0", 20);
mask = mask >> 1;
}
proto_tree_add_uint_format(oap_tree, hf_oap_1_opcode, tvb, offset, 1, opcode & 0x1F, "%s = Opcode: %s (%u)", str, val_to_str(opcode, oap_opcode_strings, "Unknown Opcode (%d)"), opcode & 0x1F);
}
switch (opcode)
{
case OAP_1_CMD_ACTIVATE:
case OAP_1_CMD_CONNECT:
case OAP_1_CMD_FULL_CONNECT:
case OAP_1_CMD_GET:
case OAP_1_CMD_INVOKE:
case OAP_1_CMD_REGISTER:
case OAP_1_CMD_SET:
case OAP_1_CMD_SUBSCRIBE:
case OAP_1_CMD_WATCH:
proto_tree_add_item(oap_tree, hf_oap_1_alias_size, tvb, offset, 1, ENC_NA);
proto_tree_add_item(oap_tree, hf_oap_1_flags, tvb, offset, 1, ENC_NA);
if (flags & 0x20)
{
offset += 1;
offset = oap_1_tree_add_cmdcontrol(pinfo, oap_tree, tvb, offset);
}
else
offset += 1;
break;
case OAP_1_CMD_ADVERTISE:
proto_tree_add_item(oap_tree, hf_oap_1_flags, tvb, offset, 1, ENC_NA);
if (flags & 0x20)
{
offset = oap_1_tree_add_cmdcontrol(pinfo, oap_tree, tvb, ENC_BIG_ENDIAN);
}
else
offset += 1;
break;
case OAP_1_RSP_GET:
case OAP_1_RSP_INVOKE:
case OAP_1_RSP_REGISTER:
case OAP_1_RSP_SET:
case OAP_1_RSP_SUBSCRIBE:
proto_tree_add_item(oap_tree, hf_oap_1_flags, tvb, offset, 1, ENC_NA);
if (flags & 0x20)
{
offset += 1;
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, oap_tree,
offset, hf_oap_1_providerid, ett_oap_1_1_providerid, NULL);
}
else
offset += 1;
if ((opcode == OAP_1_RSP_GET) || (opcode == OAP_1_RSP_INVOKE))
{
proto_tree_add_item(oap_tree, hf_oap_1_value_list, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
case OAP_1_CMD_CHANGE:
case OAP_1_CMD_OPEN:
case OAP_1_CMD_PROVIDE:
case OAP_1_CMD_SIGNAL:
proto_tree_add_item(oap_tree, hf_oap_1_alias_size, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case OAP_1_RSP_EXCEPTION:
proto_tree_add_item(oap_tree, hf_oap_1_exception_internal_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(oap_tree, hf_oap_1_exception_final_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(oap_tree, hf_oap_1_exception_provider_flag, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case OAP_1_CMD_DEFINE:
case OAP_1_RSP_DEFINE:
case OAP_1_RSP_OPEN:
offset += 1;
break;
default:
return offset;
}
switch (opcode)
{
case OAP_1_CMD_SUBSCRIBE:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
{
gint item_id_len;
proto_item *pi;
read_c2(tvb, offset, &item_id, &item_id_len);
pi = proto_tree_add_uint_format(oap_tree, hf_oap_1_itemid, tvb, offset, item_id_len, item_id, "Item ID: %u", item_id);
validate_c2(pinfo, pi, item_id, item_id_len);
offset += item_id_len;
}
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
{
gint delta_len;
guint16 delta;
proto_item *pi;
read_c2(tvb, offset, &delta, &delta_len);
pi = proto_tree_add_uint_format(oap_tree, hf_oap_1_subscription_delta, tvb, offset, delta_len, delta, "Minimum Delta: %u", delta);
validate_c2(pinfo, pi, delta, delta_len);
offset += delta_len;
}
}
break;
case OAP_1_CMD_REGISTER:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
{
gint item_id_len;
proto_item *pi;
read_c2(tvb, offset, &item_id, &item_id_len);
pi = proto_tree_add_uint_format(oap_tree, hf_oap_1_itemid, tvb, offset, item_id_len, item_id, "Item ID: %u", item_id);
validate_c2(pinfo, pi, item_id, item_id_len);
offset += item_id_len;
}
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
}
break;
case OAP_1_RSP_REGISTER:
{
if (flags & 0x20)
{
}
proto_tree_add_item(oap_tree, hf_oap_1_update_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case OAP_1_CMD_WATCH:
case OAP_1_CMD_ACTIVATE:
case OAP_1_CMD_CONNECT:
case OAP_1_CMD_FULL_CONNECT:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
}
break;
case OAP_1_CMD_ADVERTISE:
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
break;
case OAP_1_CMD_GET:
case OAP_1_CMD_INVOKE:
case OAP_1_CMD_SET:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
{
gint item_id_len;
proto_item *pi;
read_c2(tvb, offset, &item_id, &item_id_len);
pi = proto_tree_add_uint_format(oap_tree, hf_oap_1_itemid, tvb, offset, item_id_len, item_id, "Item ID: %u", item_id);
validate_c2(pinfo, pi, item_id, item_id_len);
offset += item_id_len;
}
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
if ((opcode == OAP_1_CMD_SET) || (opcode == OAP_1_CMD_INVOKE))
{
proto_tree_add_item(oap_tree, hf_oap_1_value_list, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
}
break;
case OAP_1_CMD_OPEN:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
offset = oap_1_tree_add_interface(oap_tree, tvb, offset);
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, oap_tree,
offset, hf_oap_1_objectid, ett_oap_1_objectid, NULL);
}
break;
case OAP_1_CMD_PROVIDE:
{
guint8 alias_length = flags >> 6;
gint alias_offset;
gint iid_offset;
gint oid_offset;
if (alias_length == 3)
alias_length = 4;
alias_offset = offset;
if (alias_length == 0)
{
expert_add_info_format(pinfo, ti, &ei_malformed, "alias_length == 0");
return offset;
}
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_length, FALSE);
iid_offset = offset;
offset = oap_1_tree_add_interface(oap_tree, tvb, offset);
oid_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, oap_tree,
offset, hf_oap_1_objectid, ett_oap_1_objectid, NULL);
if (alias_length && !packet_data->processed)
{
guint32 alias;
oap_1_binding *binding = (oap_1_binding *)wmem_alloc0(wmem_file_scope(), sizeof(oap_1_binding));
int i;
alias = 0;
for (i = 0; i < alias_length; i++)
alias = (alias << 8) | tvb_get_guint8(tvb, alias_offset + i);
binding->iid_length = oid_offset - iid_offset;
binding->iid = (guint8 *)wmem_alloc0(wmem_file_scope(), binding->iid_length);
tvb_memcpy(tvb, binding->iid, iid_offset, binding->iid_length);
binding->oid_length = offset - oid_offset;
binding->oid = (guint8 *)wmem_alloc0(wmem_file_scope(), binding->oid_length);
tvb_memcpy(tvb, binding->oid, oid_offset, binding->oid_length);
binding->frame = pinfo->fd->num;
oap_1_define_alias(api_data, alias, binding);
}
}
break;
case OAP_1_CMD_CHANGE:
case OAP_1_CMD_SIGNAL:
{
guint8 alias_len = (flags & 0xC0) >> 6;
if (alias_len == 3)
alias_len = 4;
{
gint item_id_len;
proto_item *pi;
read_c2(tvb, offset, &item_id, &item_id_len);
pi = proto_tree_add_uint_format(oap_tree, hf_oap_1_itemid, tvb, offset, item_id_len, item_id, "Item ID: %u", item_id);
validate_c2(pinfo, pi, item_id, item_id_len);
offset += item_id_len;
}
if (alias_len > 0)
{
if (api_data->session == NULL)
{
expert_add_info(pinfo, ti, &ei_oap_no_session);
return offset;
}
offset = oap_1_tree_add_alias(api_data, oap_packet, packet_data, oap_tree, tvb, offset, alias_len, TRUE);
}
else
offset = oap_1_tree_add_binding(oap_tree, pinfo, tvb, offset);
proto_tree_add_item(oap_tree, hf_oap_1_update_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oap_tree, hf_oap_1_value_list, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
case OAP_1_RSP_EXCEPTION:
{
if (flags & 0x20)
{
}
{
gint rsp_len;
guint16 rsp;
read_c2(tvb, offset, &rsp, &rsp_len);
offset += rsp_len;
}
proto_tree_add_item(oap_tree, hf_oap_1_value_list, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
break;
default:
break;
}
return offset;
}
static int dissect_sgmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
guint offset = 0;
guint8 opcode;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *sgmp_tree;
if (api_data == NULL)
{
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SGMPv1 ");
offset = 0;
ti = proto_tree_add_item(tree, proto_sgmp, tvb, offset, -1, ENC_NA);
sgmp_tree = proto_item_add_subtree(ti, ett_sgmp);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(sgmp_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
if (offset == tvb_captured_length(tvb))
{
col_append_str(pinfo->cinfo, COL_INFO, "SGMP [nop]");
expert_add_info(pinfo, sgmp_tree, &ei_implicit_no_op);
return offset;
}
opcode = tvb_get_guint8(tvb, offset);
if (!packet_data->is_command)
opcode |= SGMP_RESPONSE;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, sgmp_opcode_strings, "Unknown Opcode (%d)"));
proto_tree_add_item(sgmp_tree, hf_opcode, tvb, offset, 1, ENC_NA);
offset += 1;
switch (opcode)
{
case SGMP_CMD_EPOCH_CHANGED:
{
{
proto_tree_add_item(sgmp_tree, hf_sgmp_tmin, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
{
proto_tree_add_item(sgmp_tree, hf_sgmp_epoch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
break;
case SGMP_CMD_HEARTBEAT:
{
gint start_offset;
{
guint16 version;
gint length;
proto_item *pi;
start_offset = offset;
offset = read_c2(tvb, offset, &version, &length);
pi = proto_tree_add_uint(sgmp_tree, hf_latest_version, tvb, start_offset, offset - start_offset, version);
validate_c2(pinfo, pi, version, length);
}
{
proto_tree_add_item(sgmp_tree, hf_desire, tvb, offset, 1, ENC_NA);
offset += 1;
}
{
proto_tree_add_item(sgmp_tree, hf_tie_breaker, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case SGMP_CMD_REKEY:
case SGMP_CMD_REKEY_EPOCH:
case SGMP_CMD_REKEY_MERGE:
{
#if 0
gint start_offset;
tvbuff_t *initial_state;
#endif
guint8 key[32];
if (opcode != SGMP_CMD_REKEY_MERGE)
{
proto_tree_add_item(sgmp_tree, hf_delay, tvb, offset, 1, ENC_NA);
offset += 1;
}
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_9, tvb, pinfo, sgmp_tree,
offset, hf_initial_state, ett_initial_state, NULL);
#if 0
initial_state = tvb_new_subset(tvb, start_offset, offset - start_offset, offset - start_offset);
#endif
}
if (opcode == SGMP_CMD_REKEY_EPOCH)
{
proto_tree_add_item(sgmp_tree, hf_sgmp_epoch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
{
proto_tree_add_item(sgmp_tree, hf_key, tvb, offset, 32, ENC_NA);
tvb_memcpy(tvb, key, offset, 32);
offset += 32;
}
if (!packet_data->processed && api_data->session)
{
dissector_table_t field_dissector = find_dissector_table("dof.secmode");
if (field_dissector != NULL)
{
#if 0
dissector_handle_t field_handle = dissector_get_port_handle(field_dissector, packet_data->security_mode);
if (field_handle != NULL)
{
void *saved_private = pinfo->private_data;
dof_secmode_api_data setup_data;
gint block_length;
setup_data.version = DOF_API_VERSION;
setup_data.context = INITIALIZE;
setup_data.dof_api = api_data;
setup_data.secure_session = rekey_data->security_session;
pinfo->private_data = &setup_data;
block_length = call_dissector_only(field_handle, NULL, pinfo, NULL);
pinfo->private_data = saved_private;
}
#endif
}
}
}
break;
case SGMP_CMD_REQUEST_GROUP:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
guint I_offset = offset;
sgmp_packet_data *sgmp_data = NULL;
guint16 epoch;
{
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, sgmp_tree,
offset, hf_sgmp_domain, ett_sgmp_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
}
{
epoch = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(sgmp_tree, hf_sgmp_epoch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
{
{
dof_2008_16_security_4 response;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_4, tvb, pinfo, sgmp_tree,
offset, hf_initiator_block, ett_initiator_block, &response);
if (!packet_data->processed)
{
tvbuff_t *identity = response.identity;
guint8 identity_length = tvb_reported_length(identity);
guint8 *identity_buf = (guint8 *)wmem_alloc0(wmem_file_scope(), identity_length);
tvb_memcpy(identity, identity_buf, 0, identity_length);
{
sgmp_data = (sgmp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(sgmp_packet_data));
dof_packet_add_proto_data(packet_data, proto_sgmp, sgmp_data);
sgmp_data->domain_length = domain_length;
sgmp_data->domain = (guint8 *)wmem_alloc0(wmem_file_scope(), domain_length);
memcpy(sgmp_data->domain, domain_buf, domain_length);
sgmp_data->group_length = identity_length;
sgmp_data->group = (guint8 *)wmem_alloc0(wmem_file_scope(), identity_length);
memcpy(sgmp_data->group, identity_buf, identity_length);
sgmp_data->epoch = epoch;
sgmp_data->request_session = api_data->session;
}
}
}
}
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_10, tvb, pinfo, sgmp_tree,
offset, hf_sgmp_security_scope, ett_sgmp_security_scope, NULL);
}
if (sgmp_data && !sgmp_data->I)
{
sgmp_data->I_length = offset - I_offset;
sgmp_data->I = (guint8 *)wmem_alloc0(wmem_file_scope(), sgmp_data->I_length);
tvb_memcpy(tvb, sgmp_data->I, I_offset, sgmp_data->I_length);
}
}
break;
case SGMP_RSP_REQUEST_GROUP:
{
gint start_offset;
#if 0
guint A_offset;
tvbuff_t *initial_state;
guint A_end;
#endif
{
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_9, tvb, pinfo, sgmp_tree,
offset, hf_initial_state, ett_initial_state, NULL);
#if 0
initial_state = tvb_new_subset(tvb, start_offset, offset - start_offset, offset - start_offset);
#endif
}
{
guint16 version;
gint length;
proto_item *pi;
start_offset = offset;
offset = read_c2(tvb, offset, &version, &length);
pi = proto_tree_add_uint(sgmp_tree, hf_latest_version, tvb, start_offset, offset - start_offset, version);
validate_c2(pinfo, pi, version, length);
}
{
proto_tree_add_item(sgmp_tree, hf_desire, tvb, offset, 1, ENC_NA);
offset += 1;
}
}
#if 0
A_end = offset;
#endif
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, sgmp_tree,
offset, hf_ticket, ett_ticket, NULL);
}
if (packet_data->opid_first && !api_data->secure_session)
{
#if 0
sgmp_packet_data* cmd_data = (sgmp_packet_data*)dof_packet_get_proto_data(packet_data->opid_first, proto_sgmp);
extern struct BlockCipher BlockCipher_AES_256;
struct BlockCipher* cipher = &BlockCipher_AES_256;
guint8* ekey = (guint8*)ep_alloc(cipher->keyStateSize);
if (cmd_data && !cmd_data->A)
{
cmd_data->A_length = A_end - A_offset;
cmd_data->A = (guint8*)wmem_alloc0(wmem_file_scope(), cmd_data->A_length);
tvb_memcpy(tvb, cmd_data->A, A_offset, cmd_data->A_length);
}
{
dof_learned_group_data* group = globals.learned_group_data;
struct list;
struct list
{ dof_learned_group_data *group;
struct list *next; };
struct list *to_try = NULL;
guint8 confirmation[32];
guint8* discovered_kek = NULL;
dof_learned_group_auth_data *auth = NULL;
tvb_memcpy(tvb, confirmation, start_offset, 32);
while (group)
{
if ((cmd_data->domain_length == group->domain_length) &&
(memcmp(cmd_data->domain, group->domain, group->domain_length) == 0) &&
(cmd_data->group_length == group->group_length) &&
(memcmp(cmd_data->group, group->group, group->group_length) == 0))
{
struct list *n = (struct list *) ep_alloc0(sizeof(struct list));
n->group = group;
n->next = to_try;
to_try = n;
}
group = group->next;
}
while (to_try && !discovered_kek)
{
group = to_try->group;
auth = group->keys;
while (auth && !discovered_kek)
{
guint8 mac[32];
guint8 key[32];
int j;
if (auth->epoch == cmd_data->epoch)
{
tvb_memcpy(tvb, mac, start_offset, 32);
tvb_memcpy(tvb, key, start_offset + 32, 32);
if (cipher != NULL)
{
cipher->GenerateKeyState(ekey, auth->kek);
cipher->Encrypt(ekey, mac);
cipher->Encrypt(ekey, mac + 16);
}
for (j = 0; j < 32; j++)
key[j] ^= mac[j];
if (sgmp_validate_session_key(cmd_data, confirmation, auth->kek, key))
{
discovered_kek = (guint8*)se_alloc0(32);
memcpy(discovered_kek, key, 32);
break;
}
}
auth = auth->next;
}
to_try = to_try->next;
}
if (discovered_kek)
{
dissector_table_t field_dissector;
dissector_handle_t field_handle;
dof_session_key_exchange_data *key_exchange = NULL;
dof_secure_session_data *dof_secure_session = cmd_data->request_session->secure_sessions;
while (dof_secure_session)
{
if ((dof_secure_session->ssid == group->ssid) &&
(dof_secure_session->domain_length == group->domain_length) &&
(memcmp(dof_secure_session->domain, group->domain, group->domain_length) == 0))
break;
dof_secure_session = dof_secure_session->next;
}
if (!dof_secure_session)
{
dof_session_data *dof_session = wmem_alloc0(wmem_file_scope(), sizeof(dof_session_data));
dof_session->session_id = globals.next_session++;
dof_session->dof_id = api_data->session->dof_id;
dof_secure_session = wmem_alloc0(wmem_file_scope(), sizeof(dof_secure_session_data));
dof_secure_session->ssid = group->ssid;
dof_secure_session->domain_length = group->domain_length;
dof_secure_session->domain = group->domain;
dof_secure_session->original_session_id = cmd_data->request_session->session_id;
dof_secure_session->parent = dof_session;
dof_secure_session->is_2_node = FALSE;
dof_secure_session->next = cmd_data->request_session->secure_sessions;
cmd_data->request_session->secure_sessions = dof_secure_session;
}
{
key_exchange = wmem_alloc0(wmem_file_scope(), sizeof(dof_session_key_exchange_data));
if (!key_exchange)
return offset;
key_exchange->i_valid = packet_data->opid_first->dof_frame;
key_exchange->r_valid = packet_data->dof_frame;
key_exchange->security_mode = auth->security_mode;
key_exchange->security_mode_data = auth->mode;
key_exchange->security_mode_data_length = auth->mode_length;
key_exchange->session_key = discovered_kek;
if (!dof_secure_session->session_security_data_last)
dof_secure_session->session_security_data = key_exchange;
else
dof_secure_session->session_security_data_last->next = key_exchange;
dof_secure_session->session_security_data_last = key_exchange;
}
field_dissector = find_dissector_table("dps.secmode");
if (field_dissector != NULL)
{
field_handle = dissector_get_uint_handle(field_dissector, auth->security_mode);
if (field_handle != NULL)
{
dof_secmode_api_data setup_data;
gint block_length;
tvbuff_t *ntvb = tvb_new_subset(tvb, A_offset, -1, -1);
setup_data.context = INITIALIZE;
setup_data.security_mode_offset = 0;
setup_data.dof_api = api_data;
setup_data.secure_session = dof_secure_session;
setup_data.session_key_data = key_exchange;
block_length = call_dissector_only(field_handle, ntvb, pinfo, tree, &setup_data);
}
}
}
}
#endif
}
}
break;
default:
break;
}
return offset;
}
static gboolean validate_session_key(tep_rekey_data *rekey, guint S_length, guint8 *S, guint8 *confirmation, guint8 *key)
{
guint8 pad[16];
gcry_mac_hd_t hmac;
gcry_error_t result;
memset(pad, 0, sizeof(pad));
result = gcry_mac_open(&hmac, GCRY_MAC_HMAC_SHA256, 0, NULL);
if (result != 0)
return FALSE;
gcry_mac_setkey(hmac, key, 32);
gcry_mac_write(hmac, pad, 16 - rekey->i_nonce_length);
gcry_mac_write(hmac, rekey->i_nonce, rekey->i_nonce_length);
gcry_mac_write(hmac, pad, 16 - rekey->r_nonce_length);
gcry_mac_write(hmac, rekey->r_nonce, rekey->r_nonce_length);
gcry_mac_write(hmac, S, S_length);
gcry_mac_write(hmac, rekey->r_identity, rekey->r_identity_length);
result = gcry_mac_verify(hmac, confirmation, 32);
return result == 0;
}
static gboolean validate_session_key(tep_rekey_data *rekey _U_, guint S_length _U_, guint8 *S _U_, guint8 *confirmation _U_, guint8 *key _U_)
{
return FALSE;
}
static int dissect_tep_dsp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint offset = 0;
if (!tree)
return 0;
offset += 4;
proto_tree_add_item(tree, hf_dsp_option, tvb, 0, -1, ENC_NA);
return offset;
}
static int dissect_2008_4_tep_2_2_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 *ssid, void *data)
{
gint offset = 0;
proto_item *ti;
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
if (api_data == NULL)
{
return 0;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
return 0;
}
if (packet_data->decrypted_buffer == NULL)
{
proto_item *pi;
gint ssid_len;
gint start = offset;
offset = read_c4(tvb, offset, ssid, &ssid_len);
pi = proto_tree_add_uint(tree, hf_tep_2_2_1_state_identifier, tvb, start, offset - start, *ssid);
validate_c4(pinfo, pi, *ssid, ssid_len);
}
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
ti = proto_tree_add_item(tree, hf_tep_2_2_1_initial_state, tvb, offset, 0, ENC_NA);
ti = proto_item_add_subtree(ti, ett_tep_2_2_1_initial_state);
block_length = dof_dissect_pdu(dissect_2008_16_security_9, start, pinfo, ti, NULL);
proto_item_set_len(ti, block_length);
offset += block_length;
}
return offset;
}
static int dissect_tep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet;
tep_rekey_data *rekey_data;
guint offset = 0;
guint8 operation;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *tep_tree, *operation_tree;
if (api_data == NULL)
{
return 0;
}
packet = api_data->packet;
if (packet == NULL)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TEPv1 ");
offset = 0;
ti = proto_tree_add_item(tree, proto_tep, tvb, offset, -1, ENC_NA);
tep_tree = proto_item_add_subtree(ti, ett_tep);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(tep_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo,ti, app, app_len);
if (offset == tvb_captured_length(tvb))
{
col_append_str(pinfo->cinfo, COL_INFO, "TEP [nop]");
expert_add_info(pinfo, tep_tree, &ei_implicit_no_op);
return offset;
}
operation = tvb_get_guint8(tvb, offset);
if (!packet->is_command)
operation |= TEP_OPCODE_RSP;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(operation, tep_opcode_strings, "Unknown Opcode (%d)"));
ti = proto_tree_add_uint_format(tep_tree, hf_tep_operation, tvb, offset, 1, operation, "Operation: %s (%u)", val_to_str(operation, tep_opcode_strings, "Unknown Opcode (%d)"), operation);
operation_tree = proto_item_add_subtree(ti, ett_tep_operation);
ti = proto_tree_add_boolean(operation_tree, hf_tep_operation_type, tvb, offset, 0, operation);
PROTO_ITEM_SET_GENERATED(ti);
if ((operation & 0x8F) == 0x01)
{
proto_tree_add_item(operation_tree, hf_tep_c, tvb, offset, 1, ENC_NA);
proto_tree_add_item(operation_tree, hf_tep_k, tvb, offset, 1, ENC_NA);
}
proto_tree_add_item(operation_tree, hf_tep_opcode, tvb, offset, 1, ENC_NA);
offset += 1;
switch (operation)
{
case TEP_PDU_REQUEST_KEY:
rekey_data = (tep_rekey_data *)packet->opid_data;
if (!rekey_data)
{
packet->opid_data = rekey_data = (tep_rekey_data *)wmem_alloc0(wmem_file_scope(), sizeof(tep_rekey_data));
}
rekey_data->key_data = (dof_session_key_exchange_data *)wmem_alloc0(wmem_file_scope(), sizeof(dof_session_key_exchange_data));
rekey_data->is_rekey = TRUE;
if (packet->decrypted_buffer == NULL)
{
gint start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, tep_tree,
offset, hf_tep_2_1_domain, ett_tep_2_1_domain, NULL);
if (!rekey_data->domain)
{
rekey_data->domain_length = offset - start_offset;
rekey_data->domain = (guint8 *)wmem_alloc0(wmem_file_scope(), rekey_data->domain_length);
tvb_memcpy(tvb, rekey_data->domain, start_offset, rekey_data->domain_length);
}
}
else
{
if (!rekey_data->domain)
{
rekey_data->domain_length = api_data->secure_session->domain_length;
rekey_data->domain = api_data->secure_session->domain;
}
}
case TEP_PDU_REQUEST:
rekey_data = (tep_rekey_data *)packet->opid_data;
if (!rekey_data)
{
if (api_data->secure_session == NULL)
{
return 0;
}
packet->opid_data = rekey_data = (tep_rekey_data *)wmem_alloc0(wmem_file_scope(), sizeof(tep_rekey_data));
rekey_data->domain_length = api_data->secure_session->domain_length;
rekey_data->domain = api_data->secure_session->domain;
}
{
dof_2008_16_security_6_1 response;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_1, tvb, pinfo, tep_tree,
offset, hf_tep_2_1_initiator_block, ett_tep_2_1_initiator_block, &response);
if (!packet->processed)
{
tvbuff_t *inonce = response.i_nonce;
tvbuff_t *iidentity = response.i_identity;
rekey_data->i_nonce_length = tvb_reported_length(inonce);
rekey_data->i_nonce = (guint8 *)wmem_alloc0(wmem_file_scope(), rekey_data->i_nonce_length);
tvb_memcpy(inonce, rekey_data->i_nonce, 0, rekey_data->i_nonce_length);
rekey_data->i_identity_length = tvb_reported_length(iidentity);
rekey_data->i_identity = (guint8 *)wmem_alloc0(wmem_file_scope(), rekey_data->i_identity_length);
tvb_memcpy(iidentity, rekey_data->i_identity, 0, rekey_data->i_identity_length);
rekey_data->security_mode = response.security_mode;
rekey_data->security_mode_data_length = response.security_mode_data_length;
rekey_data->security_mode_data = response.security_mode_data;
}
}
break;
case TEP_PDU_ACCEPT:
{
guint32 ssid = 0;
guint8 *S = NULL;
guint8 S_length = 0;
guint8 confirmation[32];
typedef struct identity_key
{
guint8 *session_key;
struct identity_key *next;
} identity_key;
identity_key *identity_key_list = NULL;
dof_secure_session_data *dof_secure_session = NULL;
if (!packet->opid_first)
{
return 0;
}
rekey_data = (tep_rekey_data *)packet->opid_first->opid_data;
if (!rekey_data)
return tvb_captured_length(tvb);
{
gint start_offset;
guint8 ticket[64];
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, tep_tree,
offset, hf_tep_2_2_initiator_ticket, ett_tep_2_2_initiator_ticket, NULL);
if (!packet->processed && rekey_data)
{
rijndael_ctx cipher_state;
int i;
for (i = 0; i < globals.global_security->identity_data_count; i++)
{
dof_identity_data *identity = globals.global_security->identity_data + i;
int j;
if (identity->domain_length != rekey_data->domain_length)
continue;
if (memcmp(identity->domain, rekey_data->domain, identity->domain_length) != 0)
continue;
if (identity->identity_length != rekey_data->i_identity_length)
continue;
if (memcmp(identity->identity, rekey_data->i_identity, identity->identity_length) != 0)
continue;
tvb_memcpy(tvb, ticket, start_offset, 64);
rijndael_set_key(&cipher_state, identity->secret, 256);
encryptInPlace(DOF_PROTOCOL_TEP, &cipher_state, ticket, 16);
encryptInPlace(DOF_PROTOCOL_TEP, &cipher_state, ticket + 16, 16);
for (j = 0; j < 32; j++)
ticket[j + 32] = ticket[j + 32] ^ ticket[j];
{
identity_key *key = (identity_key *)wmem_alloc0(wmem_file_scope(), sizeof(*key));
key->session_key = (guint8 *)wmem_alloc0(wmem_file_scope(), 32);
memcpy(key->session_key, ticket + 32, 32);
key->next = identity_key_list;
identity_key_list = key;
}
}
}
}
{
if (!packet->processed)
tvb_memcpy(tvb, confirmation, offset, sizeof(confirmation));
proto_tree_add_item(tep_tree, hf_tep_2_2_ticket_confirmation, tvb, offset, 32, ENC_NA);
offset += 32;
}
if (rekey_data->key_data && rekey_data->key_data->session_key && tep_tree)
{
const gchar *SID = bytestring_to_str(NULL, rekey_data->key_data->session_key, 32, ':');
ti = proto_tree_add_bytes_format_value(tree, hf_tep_session_key, tvb, 0, 0, rekey_data->key_data->session_key, "%s", SID);
PROTO_ITEM_SET_GENERATED(ti);
}
{
if (rekey_data && rekey_data->is_rekey)
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
ti = proto_tree_add_item(tep_tree, hf_tep_2_2_responder_initialization, tvb, offset, 0, ENC_NA);
ti = proto_item_add_subtree(ti, ett_tep_2_2_responder_initialization);
block_length = dissect_2008_4_tep_2_2_1(start, pinfo, ti, &ssid, data);
proto_item_set_len(ti, block_length);
offset += block_length;
if (!packet->processed)
{
S_length = block_length;
S = (guint8 *)wmem_alloc0(wmem_file_scope(), S_length);
tvb_memcpy(start, S, 0, S_length);
}
if (packet->decrypted_buffer == NULL && !packet->processed)
{
#if 0
if (api_data->session)
tep_session = (tep_session_data*)dof_session_get_proto_data((dof_session_data*)api_data->session, proto_tep);
if (!tep_session && api_data->session)
{
tep_session = (tep_session_data*)se_alloc0(sizeof(*tep_session));
dof_session_add_proto_data((dof_session_data*)api_data->session, proto_tep, tep_session);
}
tep_session->pending_rekey = cmd;
tep_session->pending_confirm = packet;
#endif
}
}
}
{
dof_2008_16_security_6_2 response;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_2, tvb, pinfo, tep_tree,
offset, hf_tep_2_2_responder_block, ett_tep_2_2_responder_block, &response);
if (!packet->processed)
{
tvbuff_t *rnonce = response.r_nonce;
tvbuff_t *ridentity = response.r_identity;
rekey_data->r_nonce_length = tvb_reported_length(rnonce);
rekey_data->r_nonce = (guint8 *)wmem_alloc0(wmem_file_scope(), rekey_data->r_nonce_length);
tvb_memcpy(rnonce, rekey_data->r_nonce, 0, rekey_data->r_nonce_length);
rekey_data->r_identity_length = tvb_reported_length(ridentity);
rekey_data->r_identity = (guint8 *)wmem_alloc0(wmem_file_scope(), rekey_data->r_identity_length);
tvb_memcpy(ridentity, rekey_data->r_identity, 0, rekey_data->r_identity_length);
}
}
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_3, tvb, pinfo, tep_tree,
offset, hf_tep_2_2_authenticator_initialization, ett_tep_2_2_authenticator_initialization, NULL);
}
if (packet->decrypted_buffer == NULL)
{
{
dof_session_data *dof_session = api_data->session;
dof_secure_session = dof_session->secure_sessions;
while (dof_secure_session != NULL)
{
if ((dof_secure_session->ssid == ssid) &&
(dof_secure_session->domain_length == rekey_data->domain_length) &&
(memcmp(dof_secure_session->domain, rekey_data->domain, rekey_data->domain_length) == 0))
break;
dof_secure_session = dof_secure_session->next;
}
if (!dof_secure_session)
{
dof_session = (dof_session_data *)wmem_alloc0(wmem_file_scope(), sizeof(dof_session_data));
dof_session->session_id = globals.next_session++;
dof_session->dof_id = api_data->session->dof_id;
dof_secure_session = (dof_secure_session_data *)wmem_alloc0(wmem_file_scope(), sizeof(dof_secure_session_data));
dof_secure_session->ssid = ssid;
dof_secure_session->domain_length = rekey_data->domain_length;
dof_secure_session->domain = rekey_data->domain;
dof_secure_session->original_session_id = api_data->session->session_id;
dof_secure_session->parent = dof_session;
dof_secure_session->is_2_node = TRUE;
dof_secure_session->next = api_data->session->secure_sessions;
api_data->session->secure_sessions = dof_secure_session;
if (!dof_secure_session->session_security_data_last)
dof_secure_session->session_security_data = rekey_data->key_data;
else
dof_secure_session->session_security_data_last->next = rekey_data->key_data;
dof_secure_session->session_security_data_last = rekey_data->key_data;
}
}
}
if (!packet->processed && rekey_data->is_rekey)
{
int i;
guint8 *session_key = NULL;
while (session_key == NULL && identity_key_list)
{
if (validate_session_key(rekey_data, S_length, S, confirmation, identity_key_list->session_key))
{
session_key = (guint8 *)wmem_alloc0(wmem_file_scope(), 32);
memcpy(session_key, identity_key_list->session_key, 32);
}
identity_key_list = identity_key_list->next;
}
for (i = 0; session_key == NULL && i < globals.global_security->session_key_count; i++)
{
if (validate_session_key(rekey_data, S_length, S, confirmation, globals.global_security->session_key[i].session_key))
session_key = globals.global_security->session_key[i].session_key;
}
{
rekey_data->key_data->r_valid = packet->dof_frame;
rekey_data->key_data->i_valid = G_MAXUINT32;
rekey_data->key_data->session_key = session_key;
rekey_data->key_data->security_mode = rekey_data->security_mode;
rekey_data->key_data->security_mode_data_length = rekey_data->security_mode_data_length;
rekey_data->key_data->security_mode_data = rekey_data->security_mode_data;
if (session_key && dof_secure_session)
{
dissector_table_t field_dissector = find_dissector_table("dof.secmode");
if (field_dissector != NULL)
{
dissector_handle_t field_handle = dissector_get_uint_handle(field_dissector, rekey_data->key_data->security_mode);
if (field_handle != NULL)
{
dof_secmode_api_data setup_data;
setup_data.context = INITIALIZE;
setup_data.security_mode_offset = 0;
setup_data.dof_api = api_data;
setup_data.secure_session = dof_secure_session;
setup_data.session_key_data = rekey_data->key_data;
call_dissector_only(field_handle, NULL, pinfo, NULL, &setup_data);
}
}
}
}
}
}
break;
case TEP_PDU_CONFIRM:
{
proto_tree_add_item(tep_tree, hf_tep_2_1_ticket_confirmation, tvb, offset, 32, ENC_NA);
offset += 32;
if (!packet->processed && api_data->session && packet->opid_first && packet->opid_first->opid_data)
{
dof_session_key_exchange_data *sk_data;
rekey_data = (tep_rekey_data *)packet->opid_first->opid_data;
sk_data = rekey_data->key_data;
if (sk_data)
sk_data->i_valid = packet->dof_frame;
}
}
break;
case TEP_PDU_END_SESSION:
case TEP_PDU_SESSION_ENDING:
break;
case TEP_PDU_REJECT:
{
proto_tree_add_item(tep_tree, hf_tep_reject_code, tvb, offset, 1, ENC_NA);
offset += 1;
if (tvb_captured_length(tvb) > offset)
proto_tree_add_item(tep_tree, hf_tep_reject_data, tvb, offset, -1, ENC_NA);
}
break;
default:
break;
}
return offset;
}
static int dissect_trp_dsp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint offset = 0;
if (!tree)
return 0;
offset += 4;
proto_tree_add_item(tree, hf_trp_dsp_option, tvb, 0, -1, ENC_NA);
return offset;
}
static int dissect_trp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dof_api_data *api_data = (dof_api_data *)data;
dof_packet_data *packet_data;
guint offset = 0;
guint8 opcode;
guint16 app;
gint app_len;
proto_item *ti;
proto_tree *trp_tree;
trp_packet_data *trp_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TRP ");
offset = 0;
ti = proto_tree_add_item(tree, proto_trp, tvb, offset, -1, ENC_NA);
trp_tree = proto_item_add_subtree(ti, ett_trp);
offset = read_c2(tvb, offset, &app, &app_len);
ti = proto_tree_add_uint(trp_tree, hf_2008_1_app_version, tvb, 0, app_len, app);
validate_c2(pinfo, ti, app, app_len);
if (api_data == NULL)
{
expert_add_info_format(pinfo, ti, &ei_malformed, "api_data == NULL");
return offset;
}
packet_data = api_data->packet;
if (packet_data == NULL)
{
expert_add_info_format(pinfo, ti, &ei_malformed, "api_data == NULL");
return offset;
}
trp_data = (trp_packet_data *)dof_packet_get_proto_data(packet_data, proto_trp);
if (offset == tvb_captured_length(tvb))
{
col_append_str(pinfo->cinfo, COL_INFO, "TRP [nop]");
expert_add_info(pinfo, trp_tree, &ei_implicit_no_op);
return offset;
}
opcode = tvb_get_guint8(tvb, offset);
if (!packet_data->is_command)
opcode |= TRP_RESPONSE;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, trp_opcode_strings, "Unknown Opcode (%d)"));
ti = proto_tree_add_uint_format(trp_tree, hf_trp_opcode, tvb, offset, 1, opcode & 0x7F, "Opcode: %s (%u)", val_to_str(opcode, trp_opcode_strings, "Unknown Opcode (%d)"), opcode & 0x7F);
offset += 1;
switch (opcode)
{
case TRP_RSP_REJECT:
{
proto_tree_add_item(trp_tree, hf_trp_errorcode, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
case TRP_CMD_REQUEST_KEK:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
if (trp_data && trp_data->identity_length)
{
expert_add_info(pinfo, ti, &ei_trp_initiator_id_known);
}
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree, offset, hf_domain, ett_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_file_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
{
dof_2008_16_security_4 response;
trp_packet_data *trp_pkt_data = NULL;
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_4, tvb, pinfo, trp_tree,
offset, hf_initiator_request, ett_initiator_request, &response);
if (!packet_data->processed)
{
tvbuff_t *identity = response.identity;
guint8 identity_length = tvb_reported_length(identity);
guint8 *identity_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), identity_length);
int i;
tvb_memcpy(identity, identity_buf, 0, identity_length);
for (i = 0; i < globals.global_security->identity_data_count; i++)
{
dof_identity_data *gidentity = globals.global_security->identity_data + i;
if (domain_length != gidentity->domain_length ||
memcmp(domain_buf, gidentity->domain, domain_length) != 0)
continue;
if (identity_length == gidentity->identity_length &&
memcmp(identity_buf, gidentity->identity, identity_length) == 0)
{
trp_pkt_data = (trp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(trp_packet_data));
dof_packet_add_proto_data(packet_data, proto_trp, trp_pkt_data);
trp_pkt_data->domain_length = domain_length;
trp_pkt_data->domain = (guint8 *)wmem_alloc0(wmem_file_scope(), domain_length);
memcpy(trp_pkt_data->domain, domain_buf, domain_length);
trp_pkt_data->identity_length = identity_length;
trp_pkt_data->identity = (guint8 *)wmem_alloc0(wmem_file_scope(), identity_length);
memcpy(trp_pkt_data->identity, identity_buf, identity_length);
trp_pkt_data->secret = gidentity->secret;
}
}
}
{
gint gid_start = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_8, tvb, pinfo, trp_tree,
offset, hf_group_identifier, ett_group_identifier, NULL);
if (trp_pkt_data)
{
trp_pkt_data->group_length = offset - gid_start;
trp_pkt_data->group = (guint8 *)wmem_alloc0(wmem_file_scope(), trp_pkt_data->group_length);
tvb_memcpy(tvb, trp_pkt_data->group, gid_start, trp_pkt_data->group_length);
}
}
if (trp_pkt_data)
{
trp_pkt_data->block_I_length = offset - start_offset;
trp_pkt_data->block_I = (guint8 *)wmem_alloc0(wmem_file_scope(), trp_pkt_data->block_I_length);
tvb_memcpy(tvb, trp_pkt_data->block_I, start_offset, trp_pkt_data->block_I_length);
}
}
}
break;
case TRP_RSP_REQUEST_KEK:
{
gint start_offset;
guint32 ssid;
guint8 *mode;
guint8 mode_length;
guint8 *block_A;
guint8 block_A_length;
if (trp_data && trp_data->kek_known)
{
expert_add_info(pinfo, ti, &ei_trp_kek_discovered);
}
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, trp_tree,
offset, hf_initiator_ticket, ett_initiator_ticket, NULL);
{
start_offset = offset;
{
proto_tree_add_item(trp_tree, hf_thb, tvb, offset, 1, ENC_NA);
offset += 1;
}
{
proto_tree_add_item(trp_tree, hf_tmin, tvb, offset, 1, ENC_NA);
offset += 1;
}
{
proto_tree_add_item(trp_tree, hf_tmax, tvb, offset, 1, ENC_NA);
offset += 1;
}
{
proto_tree_add_item(trp_tree, hf_trp_epoch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
{
offset = dof_dissect_pdu_as_field(dissect_2009_11_type_4, tvb, pinfo, trp_tree,
offset, hf_sidg, ett_sidg, NULL);
}
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_10, tvb, pinfo, trp_tree,
offset, hf_security_scope, ett_security_scope, NULL);
}
{
gint mode_start = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_13, tvb, pinfo, trp_tree,
offset, hf_security_mode, ett_security_mode, NULL);
if (!packet_data->processed)
{
mode_length = offset - mode_start;
mode = (guint8 *)wmem_alloc0(wmem_packet_scope(), mode_length);
tvb_memcpy(tvb, mode, mode_start, mode_length);
}
}
{
gint s_offset = offset;
gint ssid_len;
proto_item *pi;
offset = read_c4(tvb, offset, &ssid, &ssid_len);
ssid |= AS_ASSIGNED_SSID;
pi = proto_tree_add_uint_format(trp_tree, hf_ssid, tvb, s_offset, offset - s_offset, ssid, "SSID: %u", ssid);
validate_c4(pinfo, pi, ssid, ssid_len);
}
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_2, tvb, pinfo, trp_tree,
offset, hf_responder_pg, ett_responder_pg, NULL);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_11, tvb, pinfo, trp_tree,
offset, hf_responder_validation, ett_responder_validation, NULL);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_11, tvb, pinfo, trp_tree,
offset, hf_initiator_validation, ett_initiator_validation, NULL);
block_A_length = offset - start_offset;
block_A = (guint8 *)wmem_alloc0(wmem_packet_scope(), block_A_length);
tvb_memcpy(tvb, block_A, start_offset, block_A_length);
}
if (packet_data->opid_first && !packet_data->processed)
{
#if 0
trp_packet_data* cmd_data = (trp_packet_data*)dof_packet_get_proto_data(packet_data->opid_first, proto_trp);
guint8 mac[32];
extern struct BlockCipher BlockCipher_AES_256;
struct BlockCipher* cipher = &BlockCipher_AES_256;
guint8* ekey = (guint8*)ep_alloc(cipher->keyStateSize);
int i;
if (cmd_data)
{
guint8 kek[32];
tvb_memcpy(tvb, mac, mac_offset, 32);
tvb_memcpy(tvb, kek, mac_offset + 32, 32);
if (cipher != NULL)
{
cipher->GenerateKeyState(ekey, cmd_data->secret);
cipher->Encrypt(ekey, mac);
cipher->Encrypt(ekey, mac + 16);
}
for (i = 0; i < 32; i++)
kek[i] ^= mac[i];
{
OALSecureHMACContext ctx;
OALSecureHMACDigest digest;
OALSecureHMAC_Start(&ctx, cmd_data->secret);
OALSecureHMAC_Digest(&ctx, cmd_data->domain_length, cmd_data->domain);
OALSecureHMAC_Digest(&ctx, cmd_data->block_I_length, cmd_data->block_I);
OALSecureHMAC_Digest(&ctx, block_A_length, block_A);
OALSecureHMAC_Digest(&ctx, 32, kek);
OALSecureHMAC_Finish(&ctx, digest);
tvb_memcpy(tvb, mac, mac_offset, 32);
if (memcmp(mac, digest, 32) == 0)
{
dof_learned_group_data* group = globals.learned_group_data;
dof_learned_group_auth_data *auth = NULL;
if (!trp_data)
{
trp_data = wmem_alloc0(wmem_file_scope(), sizeof(trp_packet_data));
dof_packet_add_proto_data(packet_data, proto_trp, trp_data);
}
trp_data->kek_known = TRUE;
while (group)
{
if ((cmd_data->domain_length == group->domain_length) &&
(memcmp(cmd_data->domain, group->domain, group->domain_length) == 0) &&
(cmd_data->group_length == group->group_length) &&
(memcmp(cmd_data->group, group->group, group->group_length) == 0) &&
(ssid == group->ssid))
break;
group = group->next;
}
if (group == NULL)
{
group = wmem_alloc0(wmem_file_scope, sizeof(dof_learned_group_data));
group->domain_length = cmd_data->domain_length;
group->domain = cmd_data->domain;
group->group_length = cmd_data->group_length;
group->group = cmd_data->group;
group->ssid = ssid;
group->next = globals.learned_group_data;
globals.learned_group_data = group;
}
auth = group->keys;
while (auth)
{
if (epoch == auth->epoch)
break;
auth = auth->next;
}
if (auth == NULL)
{
auth = wmem_alloc0(wmem_file_scope(), sizeof(dof_learned_group_auth_data));
auth->epoch = epoch;
auth->next = group->keys;
group->keys = auth;
auth->kek = (guint8*)wmem_alloc0(wmem_file_scope(), 32);
memcpy(auth->kek, kek, 32);
auth->mode_length = mode_length;
auth->mode = (guint8*)wmem_alloc0(wmem_file_scope(), mode_length);
memcpy(auth->mode, mode, mode_length);
auth->security_mode = (mode[1] * 256) | mode[2];
auth->parent = group;
}
}
}
}
#endif
}
}
break;
case TRP_CMD_REQUEST_RANDOM:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
if (trp_data && trp_data->identity_length)
{
expert_add_info(pinfo, ti, &ei_trp_initiator_id_known);
}
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree,
offset, hf_domain, ett_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
{
dof_2008_16_security_4 response;
trp_packet_data *trp_pkt_data = NULL;
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_4, tvb, pinfo, trp_tree,
offset, hf_initiator_request, ett_initiator_request, &response);
if (!packet_data->processed)
{
tvbuff_t *identity = response.identity;
guint8 identity_length = tvb_reported_length(identity);
guint8 *identity_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), identity_length);
int i;
tvb_memcpy(identity, identity_buf, 0, identity_length);
for (i = 0; i < globals.global_security->identity_data_count; i++)
{
dof_identity_data *gidentity = globals.global_security->identity_data + i;
if (domain_length != gidentity->domain_length ||
memcmp(domain_buf, gidentity->domain, domain_length) != 0)
continue;
if (identity_length == gidentity->identity_length &&
memcmp(identity_buf, gidentity->identity, identity_length) == 0)
{
trp_pkt_data = (trp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(trp_packet_data));
dof_packet_add_proto_data(packet_data, proto_trp, trp_pkt_data);
trp_pkt_data->domain_length = domain_length;
trp_pkt_data->domain = (guint8 *)wmem_alloc0(wmem_file_scope(), domain_length);
memcpy(trp_pkt_data->domain, domain_buf, domain_length);
trp_pkt_data->identity_length = identity_length;
trp_pkt_data->identity = (guint8 *)wmem_alloc0(wmem_file_scope(), identity_length);
memcpy(trp_pkt_data->identity, identity_buf, identity_length);
trp_pkt_data->secret = gidentity->secret;
}
}
}
if (trp_pkt_data)
{
trp_pkt_data->block_I_length = offset - start_offset;
trp_pkt_data->block_I = (guint8 *)wmem_alloc0(wmem_file_scope(), trp_pkt_data->block_I_length);
tvb_memcpy(tvb, trp_pkt_data->block_I, start_offset, trp_pkt_data->block_I_length);
}
}
}
break;
case TRP_RSP_REQUEST_RANDOM:
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, trp_tree,
offset, hf_initiator_ticket, ett_initiator_ticket, NULL);
}
break;
case TRP_CMD_REQUEST_SECURITY_SCOPES:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
if (trp_data && trp_data->identity_length)
{
expert_add_info(pinfo, ti, &ei_trp_initiator_id_known);
}
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree,
offset, hf_domain, ett_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
{
dof_2008_16_security_4 response;
trp_packet_data *trp_pk_data = NULL;
start_offset = offset;
proto_tree_add_item(trp_tree, hf_trp_duration, tvb, offset, 1, ENC_NA);
offset += 1;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_4, tvb, pinfo, trp_tree,
offset, hf_initiator_request, ett_initiator_request, &response);
if (!packet_data->processed)
{
tvbuff_t *identity = response.identity;
guint8 identity_length = tvb_reported_length(identity);
guint8 *identity_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), identity_length);
int i;
tvb_memcpy(identity, identity_buf, 0, identity_length);
for (i = 0; i < globals.global_security->identity_data_count; i++)
{
dof_identity_data *gidentity = globals.global_security->identity_data + i;
if (domain_length != gidentity->domain_length ||
memcmp(domain_buf, gidentity->domain, domain_length) != 0)
continue;
if (identity_length == gidentity->identity_length &&
memcmp(identity_buf, gidentity->identity, identity_length) == 0)
{
trp_pk_data = (trp_packet_data *)wmem_alloc0(wmem_file_scope(), sizeof(trp_packet_data));
dof_packet_add_proto_data(packet_data, proto_trp, trp_pk_data);
trp_pk_data->domain_length = domain_length;
trp_pk_data->domain = (guint8 *)wmem_alloc0(wmem_file_scope(), domain_length);
memcpy(trp_pk_data->domain, domain_buf, domain_length);
trp_pk_data->identity_length = identity_length;
trp_pk_data->identity = (guint8 *)wmem_alloc0(wmem_file_scope(), identity_length);
memcpy(trp_pk_data->identity, identity_buf, identity_length);
trp_pk_data->secret = gidentity->secret;
}
}
}
{
gint gid_start = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_8, tvb, pinfo, trp_tree,
offset, hf_node_identifier, ett_node_identifier, NULL);
if (trp_pk_data)
{
trp_pk_data->group_length = offset - gid_start;
trp_pk_data->group = (guint8 *)wmem_alloc0(wmem_file_scope(), trp_pk_data->group_length);
tvb_memcpy(tvb, trp_pk_data->group, gid_start, trp_pk_data->group_length);
}
}
if (trp_pk_data)
{
trp_pk_data->block_I_length = offset - start_offset;
trp_pk_data->block_I = (guint8 *)wmem_alloc0(wmem_file_scope(), trp_pk_data->block_I_length);
tvb_memcpy(tvb, trp_pk_data->block_I, start_offset, trp_pk_data->block_I_length);
}
}
}
break;
case TRP_RSP_REQUEST_SECURITY_SCOPES:
{
gint start_offset;
guint8 *block_A;
guint8 block_A_length;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, trp_tree,
offset, hf_initiator_ticket, ett_initiator_ticket, NULL);
{
start_offset = offset;
proto_tree_add_item(trp_tree, hf_trp_duration, tvb, offset, 1, ENC_NA);
offset += 1;
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_10, tvb, pinfo, trp_tree,
offset, hf_security_scope, ett_security_scope, NULL);
}
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_11, tvb, pinfo, trp_tree,
offset, hf_initiator_validation, ett_initiator_validation, NULL);
block_A_length = offset - start_offset;
block_A = (guint8 *)wmem_alloc0(wmem_packet_scope(), block_A_length);
tvb_memcpy(tvb, block_A, start_offset, block_A_length);
}
}
break;
case TRP_CMD_RESOLVE_CREDENTIAL:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree,
offset, hf_domain, ett_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_3_2, tvb, pinfo, trp_tree,
offset, hf_identity_resolution, ett_identity_resolution, NULL);
}
break;
case TRP_RSP_RESOLVE_CREDENTIAL:
{
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_3_2, tvb, pinfo, trp_tree,
offset, hf_identity_resolution, ett_identity_resolution, NULL);
}
break;
case TRP_CMD_REQUEST_SESSION:
{
guint8 *domain_buf = NULL;
guint8 domain_length = 0;
gint start_offset;
if (trp_data && trp_data->identity_length)
{
expert_add_info(pinfo, ti, &ei_trp_initiator_id_known);
}
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree,
offset, hf_domain, ett_domain, NULL);
if (!packet_data->processed)
{
domain_length = offset - start_offset;
domain_buf = (guint8 *)wmem_alloc0(wmem_packet_scope(), domain_length);
tvb_memcpy(tvb, domain_buf, start_offset, domain_length);
}
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_2, tvb, pinfo, trp_tree,
offset, hf_responder_request, ett_responder_request, NULL);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_1, tvb, pinfo, trp_tree,
offset, hf_initiator_request, ett_initiator_request, NULL);
}
break;
case TRP_RSP_REQUEST_SESSION:
{
gint start_offset;
guint8 *block_A;
guint8 block_A_length;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, trp_tree,
offset, hf_responder_ticket, ett_responder_ticket, NULL);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_5, tvb, pinfo, trp_tree,
offset, hf_initiator_ticket, ett_initiator_ticket, NULL);
{
start_offset = offset;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_6_3, tvb, pinfo, trp_tree,
offset, hf_authentication_block, ett_authentication_block, NULL);
block_A_length = offset - start_offset;
block_A = (guint8 *)wmem_alloc0(wmem_packet_scope(), block_A_length);
tvb_memcpy(tvb, block_A, start_offset, block_A_length);
}
}
break;
case TRP_CMD_VALIDATE_CREDENTIAL:
{
tvbuff_t *data_tvb;
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_7, tvb, pinfo, trp_tree,
offset, hf_domain, ett_domain, NULL);
offset = dof_dissect_pdu_as_field(dissect_2008_16_security_3_1, tvb, pinfo, trp_tree,
offset, hf_identity_resolution, ett_identity_resolution, NULL);
data_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(undissected_data_handle, data_tvb, pinfo, trp_tree);
}
break;
case TRP_RSP_VALIDATE_CREDENTIAL:
{
tvbuff_t *data_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(undissected_data_handle, data_tvb, pinfo, trp_tree);
}
break;
}
return offset;
}
static void dof_tun_register(void)
{
static hf_register_info hf[] =
{
{ &hf_2012_1_tunnel_1_version,
{ "Version", "dof.2012_1.tunnel_1.version", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_2012_1_tunnel_1_length,
{ "Length", "dof.2012_1.tunnel_1.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_2012_1_tunnel,
};
proto_2012_1_tunnel = proto_register_protocol(TUNNEL_PROTOCOL_STACK, "DTPS", "dtps");
proto_register_field_array(proto_2008_1_app, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(TUNNEL_PROTOCOL_STACK, dissect_tunnel_common, proto_2012_1_tunnel);
dof_tun_app_dissectors = register_dissector_table("dof.tunnel.app", "DOF Tunnel Version", proto_2012_1_tunnel, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
static void dof_tun_reset(void)
{
}
static void dof_tun_cleanup(void)
{
}
static void dof_tun_handoff(void)
{
static dissector_handle_t tcp_handle;
register_dissector(TUNNEL_APPLICATION_PROTOCOL, dissect_tun_app_common, proto_2008_1_app);
tcp_handle = create_dissector_handle(dissect_tunnel_tcp, proto_2012_1_tunnel);
dissector_add_uint("tcp.port", DOF_TUN_NON_SEC_TCP_PORT, tcp_handle);
}
static void dof_reset(void)
{
globals.next_session = 1;
globals.next_transport_session = 1;
globals.dof_packet_head = globals.dof_packet_tail = NULL;
globals.global_security = &global_security;
globals.learned_group_data = NULL;
globals.decrypt_all_packets = decrypt_all_packets;
globals.track_operations = track_operations;
globals.track_operations_window = track_operations_window;
init_addr_port_tables();
next_dof_frame = 1;
{
secmode_field_t *list = secmode_list;
guint i;
global_security.group_data = g_new0(dof_group_data, num_secmode_list);
global_security.group_data_count = num_secmode_list;
for (i = 0; i < num_secmode_list; i++)
{
guint8 kek_len;
dof_group_data *group_data = global_security.group_data + i;
parse_hex_string(list[i].domain, &(group_data->domain), &(group_data->domain_length));
parse_hex_string(list[i].identity, &(group_data->identity), &(group_data->identity_length));
parse_hex_string(list[i].kek, &(group_data->kek), &kek_len);
}
}
{
seckey_field_t *list = seckey_list;
guint i;
for (i = 0; i < global_security.session_key_count; i++)
{
dof_session_key_data *session_data = &global_security.session_key[i];
g_free(session_data->session_key);
}
g_free(global_security.session_key);
global_security.session_key = NULL;
global_security.session_key_count = 0;
global_security.session_key = g_new0(dof_session_key_data, num_seckey_list);
global_security.session_key_count = num_seckey_list;
for (i = 0; i < num_seckey_list; i++)
{
guint8 key_len;
dof_session_key_data *session_data = global_security.session_key + i;
parse_hex_string(list[i].key, &(session_data->session_key), &key_len);
}
}
{
identsecret_field_t *list = identsecret_list;
guint i;
for (i = 0; i < global_security.identity_data_count; i++)
{
dof_identity_data *identity_data = &global_security.identity_data[i];
g_free(identity_data->domain);
g_free(identity_data->identity);
g_free(identity_data->secret);
}
g_free(global_security.identity_data);
global_security.identity_data = NULL;
global_security.identity_data_count = 0;
global_security.identity_data = g_new0(dof_identity_data, num_identsecret_list);
global_security.identity_data_count = num_identsecret_list;
for (i = 0; i < num_identsecret_list; i++)
{
guint8 key_len;
guint32 size;
dof_identity_data *identity_data = global_security.identity_data + i;
if (VALIDHEX(list[i].domain[0]))
{
parse_hex_string(list[i].domain, &(identity_data->domain), &(identity_data->domain_length));
}
else
{
size = (guint32)strlen(list[i].domain);
dof_oid_new_standard_string(list[i].domain, &size, &(identity_data->domain));
identity_data->domain_length = size;
}
if (VALIDHEX(list[i].identity[0]))
{
parse_hex_string(list[i].identity, &(identity_data->identity), &(identity_data->identity_length));
}
else
{
size = (guint32)strlen(list[i].identity);
dof_oid_new_standard_string(list[i].identity, &size, &(identity_data->identity));
identity_data->identity_length = size;
}
parse_hex_string(list[i].secret, &(identity_data->secret), &key_len);
}
}
}
static void dof_cleanup(void)
{
guint i;
for (i = 0; i < global_security.group_data_count; i++)
{
dof_group_data *group_data = &global_security.group_data[i];
g_free(group_data->domain);
g_free(group_data->identity);
g_free(group_data->kek);
}
g_free(global_security.group_data);
global_security.group_data = NULL;
global_security.group_data_count = 0;
}
static void dof_register(void)
{
static hf_register_info hf[] =
{
{ &hf_security_1_permission_type,
{ "Permission Type", "dof.2008.16.security.1.desired-duration", FT_UINT16, BASE_DEC, VALS(dof_2008_16_permission_type), 0, NULL, HFILL } },
{ &hf_security_1_length,
{ "Length", "dof.2008.16.security.1.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_1_data,
{ "Data", "dof.2008.16.security.1.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_2_count,
{ "Count", "dof.2008.16.security.2.count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_2_permission,
{ "Permission", "dof.2008.16.security.2.permission", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_3_1_credential_type,
{ "Credential Type", "dof.2008.16.security.3.1.credential_type", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_3_1_stage,
{ "Stage", "dof.2008.16.security.3.1.stage", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_3_1_security_node_identifier,
{ "Security Node Identifier", "dof.2008.16.security.3.1.security_node_identifier", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_3_2_credential_type,
{ "Credential Type", "dof.2008.16.security.3.2.credential_type", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_3_2_stage,
{ "Stage", "dof.2008.16.security.3.2.stage", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_3_2_length,
{ "Length", "dof.2008.16.security.3.2.length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_3_2_public_data,
{ "Public Data", "dof.2008.16.security.3.2.public_data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_4_l,
{ "L", "dof.2008.16.security.4.l", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL } },
{ &hf_security_4_f,
{ "F", "dof.2008.16.security.4.f", FT_UINT8, BASE_DEC, NULL, 0x40, NULL, HFILL } },
{ &hf_security_4_ln,
{ "Ln", "dof.2008.16.security.4.ln", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL } },
{ &hf_security_4_identity,
{ "Identity", "dof.2008.16.security.4.identity", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_4_nonce,
{ "Nonce", "dof.2008.16.security.4.nonce", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_4_permission_set,
{ "Permission Set", "dof.2008.16.security.4.permission_set", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_5_mac,
{ "MAC", "dof.2008.16.security.5.mac", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_5_key,
{ "KEY", "dof.2008.16.security.5.key", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_1_desired_duration,
{ "Desired Duration", "dof.2008.16.security.6.1.desired_duration", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_6_1_desired_security_mode,
{ "Desired Security Mode", "dof.2008.16.security.6.1.desired_security_mode", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_1_initiator_request,
{ "Initiator Request", "dof.2008.16.security.6.1.initiator_request", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_2_responder_request,
{ "Responder Request", "dof.2008.16.security.6.2.responder_request", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_3_granted_duration,
{ "Granted Duration", "dof.2008.16.security.6.3.granted_duration", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_6_3_session_security_scope,
{ "Session Security Scope", "dof.2008.16.security.6.3.session_security_scope", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_3_initiator_validation,
{ "Initiator Validation", "dof.2008.16.security.6.3.initiator_validation", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_6_3_responder_validation,
{ "Responder Validation", "dof.2008.16.security.6.3.responder_validation", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_9_length,
{ "Length", "dof.2008.16.security.9.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_9_initial_state,
{ "Initial State", "dof.2008.16.security.9.initial_state", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_10_count,
{ "Count", "dof.2008.16.security.10.count", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_security_10_permission_group_identifier,
{ "Permission Group Identifier", "dof.2008.16.security.10.permission_group_identifier", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_security_11_count,
{ "Count", "dof.2008.16.security.11.count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_security_11_permission_security_scope,
{ "Permission Security Scope", "dof.2008.16.security.11.permission_security_scope", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_security_12_m,
{ "M", "dof.2008.16.security.12.m", FT_UINT8, BASE_DEC, VALS(dof_2008_16_security_12_m), 0xC0, NULL, HFILL } },
{ &hf_security_12_count,
{ "Count", "dof.2008.16.security.12.count", FT_UINT8, BASE_DEC, NULL, 0x3F, NULL, HFILL } },
{ &hf_security_12_permission_group_identifier,
{ "Permission Group Identifier", "dof.2008.16.security.12.permission_group_identifier", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_2008_1_dof_session_transport,
{ "Transport Session", "dof.transport_session", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_2008_1_dof_session,
{ "DPS Session", "dof.session", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_2008_1_dof_frame,
{ "DPS Frame", "dof.frame", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_2008_1_dof_is_2_node,
{ "DPS Is 2 Node", "dof.is_2_node", FT_BOOLEAN, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_2008_1_dof_is_streaming,
{ "DPS Is Streaming", "dof.is_streaming", FT_BOOLEAN, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_2008_1_dof_is_from_client,
{ "DPS Is From Client", "dof.is_from_client", FT_BOOLEAN, BASE_DEC, NULL, 0x00, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_security_2_permission,
&ett_security_3_1_security_node_identifier,
&ett_security_11_permission_security_scope,
&ett_security_6_1_desired_security_mode,
&ett_security_6_1_initiator_request,
&ett_security_6_2_responder_request,
&ett_security_6_3_session_security_scope,
&ett_security_6_3_initiator_validation,
&ett_security_6_3_responder_validation,
&ett_security_4_identity,
&ett_security_4_permission_set,
&ett_2008_1_dof,
};
static ei_register_info ei[] =
{
#if 0
{ &ei_undecoded, { "dof.undecoded", PI_UNDECODED, PI_WARN, "DOF: Some protocol octets were not decoded", EXPFILL } },
#endif
{ &ei_malformed, { "dof.malformed", PI_MALFORMED, PI_ERROR, "Malformed:", EXPFILL } },
{ &ei_implicit_no_op, { "dof.implicit_no_op", PI_PROTOCOL, PI_COMMENT, "Implicit No-op", EXPFILL } },
{ &ei_c2_c3_c4_format, { "dof.c2_c3_c4_format", PI_MALFORMED, PI_WARN, "DOF: Cx IE format", EXPFILL } },
{ &ei_security_3_1_invalid_stage, { "dof.security.3.1.invalid_stage", PI_MALFORMED, PI_ERROR, "DPS: Security.3.1: Stage invalid.", EXPFILL } },
{ &ei_security_4_invalid_bit, { "dof.security.4.invalid_bit", PI_MALFORMED, PI_WARN, "DPS: Security.4: Reserved bit set.", EXPFILL } },
{ &ei_security_13_out_of_range, { "dof.security.13.out_of_range", PI_MALFORMED, PI_ERROR, "DPS: Security.13: Attribute Data out of range.", EXPFILL } },
};
static uat_field_t secmode_uat_fields[] = {
UAT_FLD_CSTRING(secmode_list, domain, "Domain", "The domain, coded as hex digits of PDU Security.7."),
UAT_FLD_CSTRING(secmode_list, identity, "Group ID", "The group identifer, coded as hex digits of PDU Security.8."),
UAT_FLD_CSTRING(secmode_list, kek, "KEK", "The KEK, coded as hex digits representing the KEK (256-bit)."),
UAT_END_FIELDS
};
static uat_field_t seckey_uat_fields[] = {
UAT_FLD_CSTRING(seckey_list, key, "Session Key", "The session key to try to use, coded as hex digits representing the key (256-bit)."),
UAT_END_FIELDS
};
static uat_field_t identsecret_uat_fields[] = {
UAT_FLD_CSTRING(identsecret_list, domain, "Domain", "The domain, coded as hex digits of PDU Security.7."),
UAT_FLD_CSTRING(identsecret_list, identity, "Identity", "The group identifer, coded as hex digits of PDU Security.8."),
UAT_FLD_CSTRING_OTHER(identsecret_list, secret, "Secret", identsecret_chk_cb, "The resolved secret for a given identity, coded as hex digits representing the secret (256-bit)."),
UAT_END_FIELDS
};
module_t *dof_module;
uat_t *secmode_uat;
uat_t *seckey_uat;
uat_t *identsecret_uat;
char *uat_load_err;
expert_module_t *expert_security;
dsp_option_dissectors = register_dissector_table("dof.dsp.options", "DSP Protocol Options", proto_2008_1_dsp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
dof_sec_dissectors = register_dissector_table("dof.secmode", "DOF Security Mode of Operation", proto_2008_1_dof, FT_UINT16, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_dissector_table("dof.2008.1", "DOF Common PDU", proto_2008_1_dof, FT_STRING, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
proto_2008_1_dof = proto_register_protocol(DOF_PROTOCOL_STACK, "DOF", "dof");
proto_2008_1_dof_tcp = proto_register_protocol(DOF_PROTOCOL_STACK" TCP", "DOF-TCP", "dof-tcp");
proto_2008_1_dof_udp = proto_register_protocol(DOF_PROTOCOL_STACK" UDP", "DOF-UDP", "dof-udp");
proto_register_field_array(proto_2008_1_dof, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_security = expert_register_protocol(proto_2008_1_dof);
expert_register_field_array(expert_security, ei, array_length(ei));
dof_module = prefs_register_protocol(proto_2008_1_dof, dof_reset);
secmode_uat = uat_new((const char *)"DPS Security Mode Templates",
(size_t)sizeof(secmode_field_t),
(const char *)"custom_dof_secmode_list",
(gboolean)TRUE,
(void **)&secmode_list,
(guint *)&num_secmode_list,
(guint)(UAT_AFFECTS_DISSECTION | UAT_AFFECTS_FIELDS),
(const char *)NULL,
(uat_copy_cb_t)secmode_list_copy_cb,
(uat_update_cb_t)secmode_list_update_cb,
(uat_free_cb_t)secmode_list_free_cb,
(uat_post_update_cb_t)secmode_list_post_update_cb,
(uat_field_t *)secmode_uat_fields
);
seckey_uat = uat_new((const char *)"DPS Session Keys",
(size_t)sizeof(seckey_field_t),
(const char *)"custom_dof_seckey_list",
(gboolean)TRUE,
(void **)&seckey_list,
(guint *)&num_seckey_list,
(guint)(UAT_AFFECTS_DISSECTION | UAT_AFFECTS_FIELDS),
(const char *)NULL,
(uat_copy_cb_t)seckey_list_copy_cb,
(uat_update_cb_t)seckey_list_update_cb,
(uat_free_cb_t)seckey_list_free_cb,
(uat_post_update_cb_t)seckey_list_post_update_cb,
(uat_field_t *)seckey_uat_fields
);
identsecret_uat = uat_new((const char *)"DPS Identity Secrets",
(size_t)sizeof(identsecret_field_t),
(const char *)"custom_dof_identsecret_list",
(gboolean)TRUE,
(void **)&identsecret_list,
(guint *)&num_identsecret_list,
(guint)(UAT_AFFECTS_DISSECTION | UAT_AFFECTS_FIELDS),
(const char *)NULL,
(uat_copy_cb_t)identsecret_list_copy_cb,
(uat_update_cb_t)identsecret_list_update_cb,
(uat_free_cb_t)identsecret_list_free_cb,
(uat_post_update_cb_t)identsecret_list_post_update_cb,
(uat_field_t *)identsecret_uat_fields
);
prefs_register_bool_preference(dof_module, "custom_dof_decrypt_all",
"Attempt to decrypt all packets",
"Specifies that decryption should be attempted on all packets, even if the session initialization wasn't captured.",
&decrypt_all_packets);
prefs_register_bool_preference(dof_module, "custom_dof_track_operations",
"Track DPS operations",
"Specifies that operations should be tracked across multiple packets, providing summary lists. This takes time and memory.",
&track_operations);
prefs_register_uint_preference(dof_module, "custom_dof_track_operations_window",
"Track DPS window",
"Limits the number of operations shown before and after the current operations",
10, &track_operations_window);
prefs_register_static_text_preference(dof_module, "name4567", "The following are tables not preferences.", "These tables are not controlled by OK, Apply, and Cancel of this dialog.");
prefs_register_uat_preference(dof_module, "custom_dof_secmode_list", "DPS Security Mode Templates",
"A table of security modes and initialization data that will be tried if no security mode is found.",
secmode_uat);
prefs_register_uat_preference(dof_module, "custom_dof_seckey_list", "DPS Session Keys",
"A table of session keys to attempt if none is known.",
seckey_uat);
prefs_register_uat_preference(dof_module, "custom_dof_identsecret_list", "DPS Identity Secrets",
"A table of secrets for different identities.",
identsecret_uat);
uat_load(secmode_uat, &uat_load_err);
uat_load(seckey_uat, &uat_load_err);
uat_load(identsecret_uat, &uat_load_err);
}
static void dof_handoff(void)
{
static dissector_handle_t tcp_handle;
dof_oid_handle = register_dissector(DOF_OBJECT_IDENTIFIER, dissect_2009_11_type_4, oid_proto);
tcp_handle = create_dissector_handle(dissect_dof_tcp, proto_2008_1_dof);
dof_udp_handle = create_dissector_handle(dissect_dof_udp, proto_2008_1_dof);
undissected_data_handle = find_dissector("data");
dissector_add_uint("tcp.port", DOF_P2P_NEG_SEC_TCP_PORT, tcp_handle);
dissector_add_uint("udp.port", DOF_P2P_NEG_SEC_UDP_PORT, dof_udp_handle);
dissector_add_uint("udp.port", DOF_MCAST_NEG_SEC_UDP_PORT, dof_udp_handle);
}
static void oid_reset(void)
{
}
static void oid_cleanup(void)
{
}
static void oid_register(void)
{
static hf_register_info hf[] = {
{ &hf_oid_class,
{ "Class", "dof.oid.class", FT_UINT32, BASE_DEC, NULL, 0, "DPS Object Identifier Class", HFILL }
},
{ &hf_oid_header,
{ "Header", "dof.oid.header", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_oid_attribute,
{ "Attribute", "dof.oid.attribute", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }
},
{ &hf_oid_length,
{ "Length", "dof.oid.length", FT_UINT8, BASE_DEC, NULL, 0x3F, NULL, HFILL }
},
{ &hf_oid_data,
{ "Data", "dof.oid.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_oid_all_attribute_data,
{ "Attribute Data", "dof.oid.attribute-data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_oid_attribute_header,
{ "Header", "dof.attribute.header", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_oid_attribute_attribute,
{ "Attribute", "dof.attribute.attribute", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }
},
{ &hf_oid_attribute_id,
{ "ID", "dof.attribute.id", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }
},
{ &hf_oid_attribute_length,
{ "Length", "dof.attribute.length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_oid_attribute_data,
{ "Data", "dof.attribute.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_oid_attribute_oid,
{ "OID", "dof.attribute.oid", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_oid,
&ett_oid_header,
&ett_oid_attribute,
&ett_oid_attribute_header,
&ett_oid_attribute_oid,
};
static ei_register_info ei[] =
{
{ &ei_type_4_header_zero, { "dof.oid.header_zero", PI_MALFORMED, PI_ERROR, "DOF Violation: Type.4: Header bit mandated 0.", EXPFILL } },
};
if (oid_proto == -1)
{
expert_module_t *expert_oid;
oid_proto = proto_register_protocol(DOF_OBJECT_IDENTIFIER, "DPS.OID", "dof.oid");
proto_register_field_array(oid_proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_oid = expert_register_protocol(oid_proto);
expert_register_field_array(expert_oid, ei, array_length(ei));
}
}
static void oid_handoff(void)
{
}
static guint dof_ns_session_key_hash_fn(gconstpointer key)
{
const dof_ns_session_key *session_key = (const dof_ns_session_key *)key;
guint result = 0;
result += g_int_hash(&session_key->transport_session_id);
result += g_int_hash(&session_key->client);
result += g_int_hash(&session_key->server);
return result;
}
static gboolean dof_ns_session_key_equal_fn(gconstpointer key1, gconstpointer key2)
{
const dof_ns_session_key *session_key_ptr1 = (const dof_ns_session_key *)key1;
const dof_ns_session_key *session_key_ptr2 = (const dof_ns_session_key *)key2;
if (session_key_ptr1->transport_session_id != session_key_ptr2->transport_session_id)
return FALSE;
if (session_key_ptr1->client != session_key_ptr2->client)
return FALSE;
if (session_key_ptr1->server != session_key_ptr2->server)
return FALSE;
return TRUE;
}
static void dof_dnp_reset(void)
{
dof_ns_session_lookup = g_hash_table_new_full(dof_ns_session_key_hash_fn, dof_ns_session_key_equal_fn, g_free, NULL);
}
static void dof_dnp_cleanup(void)
{
g_hash_table_destroy(dof_ns_session_lookup);
dof_ns_session_lookup = NULL;
}
static void dof_register_dnp_0(void)
{
static hf_register_info hf[] =
{
{ &hf_2008_1_dnp_0_1_1_padding,
{ "Padding", "dof.dnp.v0.padding", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_2008_1_dnp_0_1_1_version,
{ "Version", "dof.dnp.v0.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
if (proto_2008_1_dnp_0 == -1)
{
proto_2008_1_dnp_0 = proto_register_protocol(DOF_NETWORK_PROTOCOL " V0", "DPS.DNP.V0", "dof.dnp.v0");
proto_register_field_array(proto_2008_1_dnp_0, hf, array_length(hf));
}
}
static void dof_reg_handoff_dnp_0(void)
{
dissector_handle_t dnp_handle;
dnp_handle = create_dissector_handle(dissect_dnp_0, proto_2008_1_dnp_0);
dissector_add_uint("dof.dnp", 0, dnp_handle);
}
static void dof_register_dnp_1(void)
{
expert_module_t *expert_dnp;
static hf_register_info hf[] =
{
{ &hf_2009_9_dnp_1_flags,
{ "Flags", "dof.2009_9.dnp_1.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_flag_length,
{ "Length Size", "dof.2009_9.dnp_1.flags.lengthsize", FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_flag_srcport,
{ "Source Port", "dof.2009_9.dnp_1.flags.srcport", FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_flag_dstport,
{ "Destination Port", "dof.2009_9.dnp_1.flags.dstport", FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_length,
{ "Length", "dof.2009_9.dnp_1.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_srcport,
{ "Source Port", "dof.2009_9.dnp_1.srcport", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_2009_9_dnp_1_dstport,
{ "Destination Port", "dof.2009_9.dnp_1.dstport", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] =
{
&ett_2009_9_dnp_1_flags,
};
static ei_register_info ei[] =
{
{ &ei_dof_10_flags_zero, { "dof.dnp.v1.flags_zero", PI_UNDECODED, PI_ERROR, "DPS-10: Reserved flag bits must be zero.", EXPFILL } },
#if 0
{ &ei_dof_13_length_specified, { "dof.dnp.v1.length_specified", PI_UNDECODED, PI_ERROR, "DPS-13: Length must be specified on a connection.", EXPFILL } },
#endif
};
if (proto_2009_9_dnp_1 == -1)
{
proto_2009_9_dnp_1 = proto_register_protocol(DOF_NETWORK_PROTOCOL " V1", "DOF.DNP.V1", "dof.dnp.v1");
proto_register_field_array(proto_2009_9_dnp_1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dnp = expert_register_protocol(proto_2009_9_dnp_1);
expert_register_field_array(expert_dnp, ei, array_length(ei));
}
}
static void dof_reg_handoff_dnp_1(void)
{
dissector_handle_t dnp_handle, dnp_frame_handle;
dnp_handle = create_dissector_handle(dissect_dnp_1, proto_2009_9_dnp_1);
dnp_frame_handle = create_dissector_handle(determine_packet_length_1, proto_2009_9_dnp_1);
dissector_add_uint("dof.dnp", 1, dnp_handle);
dissector_add_uint("dof.dnp.frame", 1, dnp_frame_handle);
}
static void dof_dnp_handoff(void)
{
dof_reg_handoff_dnp_0();
dof_reg_handoff_dnp_1();
}
static void dof_dnp_register(void)
{
static hf_register_info hf[] =
{
{ &hf_2008_1_dnp_1_flag,
{ "Flag", "dof.2008_1.dnp_1.flag", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x80, NULL, HFILL }
},
{ &hf_2008_1_dnp_1_version,
{ "Version", "dof.2008_1.dnp_1.version", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }
},
};
static gint *ett[] =
{
&ett_2008_1_dnp,
&ett_2008_1_dnp_header,
};
proto_2008_1_dnp = proto_register_protocol(DOF_NETWORK_PROTOCOL, "DPS.DNP", "dof.dnp");
proto_register_field_array(proto_2008_1_dnp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dnp_dissectors = register_dissector_table("dof.dnp", "DOF DNP Version", proto_2008_1_dnp, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
dnp_framing_dissectors = register_dissector_table("dof.dnp.frame", "DOF DNP Framing", proto_2008_1_dnp, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
dof_register_dnp_0();
dof_register_dnp_1();
}
static void dof_dpp_reset(void)
{
dpp_reset_opid_support();
dpp_reset_sid_support();
}
static void dof_dpp_cleanup(void)
{
}
static void dof_register_dpp_0(void)
{
static hf_register_info hf[] =
{
{ &hf_2008_1_dpp_0_1_1_version,
{ "Version", "dof.dpp.v0.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
if (proto_2008_1_dpp_0 == -1)
{
proto_2008_1_dpp_0 = proto_register_protocol(DOF_PRESENTATION_PROTOCOL " V0", "DPS.DPP.V0", "dof.dpp.v0");
proto_register_field_array(proto_2008_1_dpp_0, hf, array_length(hf));
}
}
static void dof_reg_handoff_dpp_0(void)
{
dissector_handle_t dpp_handle;
dpp_handle = create_dissector_handle(dissect_dpp_0, proto_2008_1_dpp_0);
dissector_add_uint("dof.dpp", 0, dpp_handle);
}
static void dof_register_dpp_2(void)
{
expert_module_t *expert_dpp;
static hf_register_info hf[] =
{
{ &hf_2009_12_dpp_2_1_flags,
{ "Flags", "dof.dpp.v2.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_2009_12_dpp_2_1_flag_security,
{ "Secure", "dof.dpp.v2.flags.security", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_2009_12_dpp_2_1_flag_opid,
{ "Operation ID Type", "dof.dpp.v2.flags.opidtype", FT_UINT8, BASE_DEC, VALS(strings_2009_12_dpp_opid_types), 0x60, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_flag_cmdrsp,
{ "Command/Response", "dof.dpp.v2.flags.cmdrsp", FT_BOOLEAN, 8, TFS(&tfs_response_command), 0x10, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_flag_seq,
{ "Sequence", "dof.dpp.v2.flags.sequence", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x04, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_flag_retry,
{ "Retry", "dof.dpp.v2.flags.retry", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x02, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flags,
{ "Flags", "dof.dpp.v2.security.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flag_secure,
{ "Security Mode Header", "dof.dpp.v2.security.flags.securitymodeheader", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flag_rdid,
{ "Remote Domain ID", "dof.dpp.v2.security.flags.rdid", FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flag_partition,
{ "Partition Present", "dof.dpp.v2.security.flags.partition", FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flag_ssid,
{ "SSID Present", "dof.dpp.v2.security.flags.ssid", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_flag_as,
{ "AS Present", "dof.dpp.v2.security.flags.as", FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_ssid,
{ "Security State Identifier", "dof.dpp.v2.security.ssid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_rdid,
{ "Remote Domain Identifier", "dof.dpp.v2.security.rdid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_remote_partition,
{ "Remote Security Scope", "dof.dpp.v2.security.remote-scope", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_3_sec_partition,
{ "Security Scope", "dof.dpp.v2.security.scope", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_opcnt,
{ "Operation Count", "dof.dpp.v2.opcnt", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_seq,
{ "Sequence", "dof.dpp.v2.sequence", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_retry,
{ "Retry", "dof.dpp.v2.retry", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_2009_12_dpp_2_1_delay,
{ "Delay", "dof.dpp.v2.delay", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static hf_register_info shf[] =
{
{ &hf_2009_12_dpp_2_14_opcode,
{ "Opcode", "dof.dpp.v2s.opcode", FT_UINT8, BASE_DEC, VALS(strings_2009_12_dpp_common_opcodes), 0x0, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_2009_12_dpp_2_1_flags,
&ett_2009_12_dpp_2_opid,
&ett_2009_12_dpp_2_opid_history,
&ett_2009_12_dpp_2_3_security,
&ett_2009_12_dpp_2_3_sec_flags,
&ett_2009_12_dpp_2_3_sec_remote_partition,
&ett_2009_12_dpp_2_3_sec_partition,
};
static ei_register_info ei[] =
{
{ &ei_dpp2_dof_10_flags_zero, { "dof.dpp.v2.flags_zero", PI_UNDECODED, PI_ERROR, "DPS-10: Reserved flag bits must be zero.", EXPFILL } },
{ &ei_dpp_default_flags, { "dof.dpp.v2.flags_included", PI_COMMENTS_GROUP, PI_NOTE, "Default flag value is included explicitly.", EXPFILL } },
{ &ei_dpp_explicit_sender_sid_included, { "dof.dpp.v2.sender_sid_included", PI_COMMENT, PI_NOTE, "Explicit SID could be optimized, same as sender.", EXPFILL } },
{ &ei_dpp_explicit_receiver_sid_included, { "dof.dpp.v2.receiver_sid_included", PI_COMMENT, PI_NOTE, "Explicit SID could be optimized, same as receiver.", EXPFILL } },
#ifdef LIBGCRYPT_OK
{ &ei_dpp_no_security_context, { "dof.dpp.v2.no_context", PI_UNDECODED, PI_WARN, "No security context to enable packet decryption.", EXPFILL } },
#else
{ &ei_dpp_no_security_context, { "dof.dpp.v2.no_context", PI_UNDECODED, PI_WARN, "This version of wireshark was built without DOF decryption capability", EXPFILL } },
#endif
};
static gint *sett[] =
{
&ett_2009_12_dpp_common,
};
if (proto_2009_12_dpp == -1)
{
proto_2009_12_dpp = proto_register_protocol(DOF_PRESENTATION_PROTOCOL " V2", "DPS.DPP.V2", "dof.dpp.v2");
proto_register_field_array(proto_2009_12_dpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
if (proto_2009_12_dpp_common == -1)
{
proto_2009_12_dpp_common = proto_register_protocol(DOF_PRESENTATION_PROTOCOL " V2 Support", "DPS.DPP.V2S", "dof.dpp.v2s");
proto_register_field_array(proto_2009_12_dpp, shf, array_length(shf));
proto_register_subtree_array(sett, array_length(sett));
expert_dpp = expert_register_protocol(proto_2009_12_dpp);
expert_register_field_array(expert_dpp, ei, array_length(ei));
}
}
static void dof_reg_handoff_dpp_2(void)
{
dissector_handle_t dpp_handle;
dpp_handle = create_dissector_handle(dissect_dpp_2, proto_2009_12_dpp);
dissector_add_uint("dof.dpp", 2, dpp_handle);
}
static void dof_dpp_register(void)
{
static hf_register_info hf[] =
{
{ &hf_2008_1_dpp_sid_num,
{ "SID ID", "dof.dpp.v2.sid-id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_2008_1_dpp_sid_str,
{ "SID", "dof.dpp.v2.sid", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_2008_1_dpp_rid_num,
{ "RID ID", "dof.dpp.v2.rid-id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_2008_1_dpp_rid_str,
{ "RID", "dof.dpp.v2.rid", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_2008_1_dpp_first_command,
{ "First Operation", "dof.dpp.v2.first-operation", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2008_1_dpp_last_command,
{ "Last Operation", "dof.dpp.v2.last-operation", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2008_1_dpp_first_response,
{ "First Response", "dof.dpp.v2.first-response", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2008_1_dpp_last_response,
{ "Last Response", "dof.dpp.v2.last-response", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2008_1_dpp_related_frame,
{ "Related Frame", "dof.dpp.v2.related-frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_2008_1_dpp_1_flag,
{ "Flags", "dof.dpp.flag", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x80, NULL, HFILL }
},
{ &hf_2008_1_dpp_1_version,
{ "Version", "dof.dpp.version", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }
},
};
static gint *ett[] =
{
&ett_2008_1_dpp,
&ett_2008_1_dpp_1_header,
};
static ei_register_info ei[] =
{
{ &ei_dof_6_timeout, { "dof.dpp.timeout", PI_PROTOCOL, PI_ERROR, "DOF Violation: DPS.6: Negotiation not complete within 10 seconds.", EXPFILL } },
};
if (proto_2008_1_dpp == -1)
{
expert_module_t *expert_dpp;
proto_2008_1_dpp = proto_register_protocol(DOF_PRESENTATION_PROTOCOL, "DPS.DPP", "dof.dpp");
proto_register_field_array(proto_2008_1_dpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dof_dpp_dissectors = register_dissector_table("dof.dpp", "DOF DPP Version", proto_2008_1_dpp, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
expert_dpp = expert_register_protocol(proto_2008_1_dpp);
expert_register_field_array(expert_dpp, ei, array_length(ei));
}
dof_register_dpp_0();
dof_register_dpp_2();
}
static void dof_dpp_handoff(void)
{
dof_reg_handoff_dpp_0();
dof_reg_handoff_dpp_2();
}
static void app_reset(void)
{
}
static void app_cleanup(void)
{
}
static void app_register(void)
{
if (proto_2008_1_app == -1)
{
proto_2008_1_app = proto_register_protocol(DOF_APPLICATION_PROTOCOL, "DPS.APP", "dof.app");
app_dissectors = register_dissector_table("dof.app", "DOF APP Version", proto_2008_1_app, FT_UINT16, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
}
static void app_handoff(void)
{
}
static void dof_dsp_reset(void)
{
}
static void dof_dsp_cleanup(void)
{
}
static void dof_register_dsp_0(void)
{
static hf_register_info hf[] =
{
{ &hf_2008_1_app_version,
{ "APPID", "dof.app.v0.appid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_2008_1_dsp_12_opcode,
{ "Opcode", "dof.dsp.opcode", FT_UINT8, BASE_DEC, VALS(strings_2008_1_dsp_opcodes), 0x0, NULL, HFILL } },
{ &hf_2008_1_dsp_attribute_code,
{ "Attribute Code", "dof.dsp.avp.attribute-code", FT_UINT8, BASE_DEC, VALS(strings_2008_1_dsp_attribute_codes), 0x00, NULL, HFILL } },
{ &hf_2008_1_dsp_attribute_data,
{ "Attribute Data", "dof.dsp.avp.attribute-data", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_2008_1_dsp_value_length,
{ "Value Length", "dof.dsp.avp.value-length", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_2008_1_dsp_value_data,
{ "Value Data", "dof.dsp.avp.value-data", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_2008_1_dsp_12,
&ett_2008_1_dsp_12_options,
&ett_2008_1_dsp_12_option,
};
proto_2008_1_dsp = proto_register_protocol("DOF Session Protocol", "DOF.ESP", "dof.esp");
proto_register_field_array(proto_2008_1_dsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
static void dof_reg_handoff_dsp_0(void)
{
dissector_handle_t dsp_handle = create_dissector_handle(dissect_dsp, proto_2008_1_dsp);
dissector_add_uint("dof.app", 0, dsp_handle);
}
static void dof_dsp_register(void)
{
dof_register_dsp_0();
}
static void dof_dsp_handoff(void)
{
dof_reg_handoff_dsp_0();
}
static void dof_ccm_reset(void)
{
}
static void dof_ccm_cleanup(void)
{
}
static void dof_register_ccm_24577(void)
{
expert_module_t *expert_ccm;
static hf_register_info hfdsp[] =
{
{ &hf_ccm_dsp_option,
{ "CCM Security Mode", "dof.ccm.dsp_opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ccm_dsp_strength_count,
{ "CCM Strength Count", "dof.ccm.strength-count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_ccm_dsp_strength,
{ "CCM Strength", "dof.ccm.strength", FT_UINT8, BASE_DEC, VALS(ccm_strengths), 0x0, NULL, HFILL } },
{ &hf_ccm_dsp_e_flag,
{ "CCM Minimum Encrypt", "dof.ccm.encrypt.min", FT_BOOLEAN, 8, TFS(&tfs_encrypt_do_not_encrypt), 0x80, NULL, HFILL } },
{ &hf_ccm_dsp_m_flag,
{ "CCM Maximum Encrypt", "dof.ccm.encrypt.max", FT_BOOLEAN, 8, TFS(&tfs_encrypt_do_not_encrypt), 0x40, NULL, HFILL } },
{ &hf_ccm_dsp_tmax,
{ "CCM Maximum MAC", "dof.ccm.mac.max", FT_UINT8, BASE_DEC, NULL, 0x38, NULL, HFILL } },
{ &hf_ccm_dsp_tmin,
{ "CCM Minimum MAC", "dof.ccm.mac.min", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL } },
};
static hf_register_info hf[] =
{
{ &hf_ccm_opcode,
{ "Opcode", "dof.ccm.opcode", FT_UINT8, BASE_DEC, VALS(ccm_opcode_strings), 0x0, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_ccm_dsp_option,
&ett_ccm_dsp,
&ett_ccm,
};
static hf_register_info hfheader[] =
{
{ &hf_epp_v1_ccm_flags,
{ "Flags", "dof.epp.v1.ccm.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_epp_v1_ccm_flags_manager,
{ "Manager", "dof.epp.v1.ccm.flags.manager", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL } },
{ &hf_epp_v1_ccm_flags_period,
{ "Period", "dof.epp.v1.ccm.flags.period", FT_UINT8, BASE_DEC, NULL, 0x70, NULL, HFILL } },
{ &hf_epp_v1_ccm_flags_target,
{ "Target", "dof.epp.v1.ccm.flags.target", FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL } },
{ &hf_epp_v1_ccm_flags_next_nid,
{ "Next Node Identifier", "dof.epp.v1.ccm.flags.next-nid", FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL } },
{ &hf_epp_v1_ccm_flags_packet,
{ "Packet", "dof.epp.v1.ccm.flags.packet", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL } },
{ &hf_epp_v1_ccm_nid,
{ "Node ID", "dof.epp.v1.ccm.nodeid", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_epp_v1_ccm_slot,
{ "Slot", "dof.epp.v1.ccm.slot", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_epp_v1_ccm_pn,
{ "Packet", "dof.epp.v1.ccm.packet", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_epp_v1_ccm_tnid,
{ "Target Node ID", "dof.epp.v1.ccm.target", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_epp_v1_ccm_nnid,
{ "Next Node ID", "dof.epp.v1.ccm.nnid", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
};
static gint *ettheader[] =
{
&ett_epp_v1_ccm_flags,
&ett_header,
};
static ei_register_info ei[] =
{
{ &ei_decode_failure, { "dof.ccm.decode_failure", PI_UNDECODED, PI_WARN, "Failure to decrypt packet.", EXPFILL } },
};
proto_ccm_app = proto_register_protocol("DOF CCM Security Mode App", "DOF.CCM.APP", "dof.ccm.app");
proto_ccm = proto_register_protocol("DOF CCM Security Mode of Operation", "DOF.CCM", "dof.ccm");
proto_ccm_dsp = proto_register_protocol("DOF CCM Security Mode DSP Options", "DOF.CCM.DSP", "dof.ccm.dsp");
proto_register_field_array(proto_ccm_app, hf, array_length(hf));
proto_register_field_array(proto_ccm_dsp, hfdsp, array_length(hfdsp));
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_ccm, hfheader, array_length(hfheader));
proto_register_subtree_array(ettheader, array_length(ettheader));
expert_ccm = expert_register_protocol(proto_ccm);
expert_register_field_array(expert_ccm, ei, array_length(ei));
}
static void dof_reg_handoff_ccm_24577(void)
{
static dissector_handle_t ccm_app_handle;
static dissector_handle_t dsp_handle;
static dissector_handle_t ccm_handle;
ccm_app_handle = create_dissector_handle(dissect_ccm_app, proto_ccm_app);
dsp_handle = create_dissector_handle(dissect_ccm_dsp, proto_ccm_dsp);
ccm_handle = create_dissector_handle(dissect_ccm, proto_ccm);
dissector_add_uint("dof.app", DOF_PROTOCOL_CCM, ccm_app_handle);
dissector_add_uint("dof.dsp.options", DSP_CCM_FAMILY | DOF_PROTOCOL_CCM, dsp_handle);
dissector_add_uint("dof.secmode", DOF_PROTOCOL_CCM, ccm_handle);
}
static void dof_ccm_register(void)
{
dof_register_ccm_24577();
}
static void dof_ccm_handoff(void)
{
dof_reg_handoff_ccm_24577();
}
static void dof_oap_reset(void)
{
oap_1_alias_to_binding = g_hash_table_new_full(oap_1_alias_hash_func, oap_1_alias_equal_func, NULL, NULL);
}
static void dof_oap_cleanup(void)
{
g_hash_table_destroy(oap_1_alias_to_binding);
oap_1_alias_to_binding = NULL;
}
static void dof_register_oap_1(void)
{
expert_module_t *expert_oap;
static hf_register_info hfdsp[] =
{
{ &hf_oap_1_dsp_option,
{ "Object Access Protocol", "dof.oap.dsp_opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static hf_register_info hf[] =
{
{ &hf_oap_1_opcode,
{ "Opcode", "dof.oap.opcode", FT_UINT8, BASE_DEC, VALS(oap_opcode_strings), 0x1F, NULL, HFILL } },
{ &hf_oap_1_alias_size,
{ "Alias Length", "dof.oap.aliaslen", FT_UINT8, BASE_DEC, NULL, 0xC0, NULL, HFILL } },
{ &hf_oap_1_flags,
{ "Flags", "dof.oap.flags", FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL } },
{ &hf_oap_1_exception_internal_flag,
{ "Internal Exception", "dof.oap.exception.internal", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL } },
{ &hf_oap_1_exception_final_flag,
{ "Final Exception", "dof.oap.exception.final", FT_UINT8, BASE_DEC, NULL, 0x40, NULL, HFILL } },
{ &hf_oap_1_exception_provider_flag,
{ "Exception Provider", "dof.oap.exception.provider", FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol,
{ "Command Control", "dof.oap.cmdcontrol", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_cache_flag,
{ "Cache Delay Flag", "dof.oap.cmdcontrol.flag.cache", FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_cache,
{ "Cache Delay", "dof.oap.cmdcontrol.cache", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_verbosity_flag,
{ "Verbosity Flag", "dof.oap.cmdcontrol.flag.verbosity", FT_UINT8, BASE_HEX, NULL, 0x30, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_noexecute_flag,
{ "No Execute Flag", "dof.oap.cmdcontrol.flag.noexecute", FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_ack_flag,
{ "Ack List Flag", "dof.oap.cmdcontrol.flag.ack", FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_ackcnt,
{ "Ack List Count", "dof.oap.cmdcontrol.ackcnt", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_ack,
{ "Ack", "dof.oap.cmdcontrol.ack", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_delay_flag,
{ "Execution Delay Flag", "dof.oap.cmdcontrol.flag.delay", FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_heuristic_flag,
{ "Heuristic Flag", "dof.oap.cmdcontrol.flag.heuristic", FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL } },
{ &hf_oap_1_cmdcontrol_heuristic,
{ "Heuristic", "dof.oap.cmdcontrol.heuristic", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_oap_1_providerid,
{ "Provider ID", "dof.oap.provider-id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_objectid,
{ "Object ID", "dof.oap.object-id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_interfaceid,
{ "Interface ID", "dof.oap.interface-id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_itemid,
{ "Item ID", "dof.oap.item-id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_oap_1_distance,
{ "Distance", "dof.oap.distance", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_oap_1_alias,
{ "Alias", "dof.oap.alias", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_alias_frame,
{ "Alias Frame", "dof.oap.alias-frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_oap_1_opinfo_start_frame,
{ "Command Frame", "dof.oap.command-frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_opinfo_end_frame,
{ "Response Frame", "dof.oap.response-frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_opinfo_timeout,
{ "Operation Timeout", "dof.oap.opid.timeout", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_oap_1_subscription_delta,
{ "Minimum Delta", "dof.oap.subscription.min-delta", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_update_sequence,
{ "Sequence", "dof.oap.sequence", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oap_1_value_list,
{ "OAP Value List", "dof.oap.value_list", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_oap_1_dsp,
&ett_oap_1_dsp_options,
&ett_oap_1,
&ett_oap_1_opinfo,
&ett_oap_1_cmdcontrol,
&ett_oap_1_cmdcontrol_flags,
&ett_oap_1_cmdcontrol_ack,
&ett_oap_1_alias,
&ett_oap_1_objectid,
&ett_oap_1_1_providerid,
};
static ei_register_info ei[] =
{
{ &ei_oap_no_session, { "dof.oap.no_session", PI_PROTOCOL, PI_ERROR, "Session not found", EXPFILL } },
};
proto_oap_1 = proto_register_protocol("DOF Object Access Protocol", "DOF.OAP", "dof.oap");
proto_oap_1_dsp = proto_register_protocol("DOF Object Access Protocol DSP Options", "DOF.OAP.DSP", "dof.oap.dsp");
proto_register_field_array(proto_oap_1, hf, array_length(hf));
proto_register_field_array(proto_oap_1_dsp, hfdsp, array_length(hfdsp));
proto_register_subtree_array(ett, array_length(ett));
expert_oap = expert_register_protocol(proto_oap_1);
expert_register_field_array(expert_oap, ei, array_length(ei));
}
static void dof_reg_handoff_oap_1(void)
{
dissector_handle_t oap_handle = create_dissector_handle(dissect_oap, proto_oap_1);
dissector_handle_t dsp_handle = create_dissector_handle(dissect_oap_dsp, proto_oap_1_dsp);
dissector_add_uint("dof.app", DOF_PROTOCOL_OAP_1, oap_handle);
dissector_add_uint("dof.dsp.options", DSP_OAP_FAMILY | DOF_PROTOCOL_OAP_1, dsp_handle);
}
static void dof_oap_register(void)
{
dof_register_oap_1();
}
static void dof_oap_handoff(void)
{
dof_reg_handoff_oap_1();
}
static void dof_sgmp_reset(void)
{
}
static void dof_sgmp_cleanup(void)
{
}
void dof_register_sgmp_130(void)
{
static hf_register_info hf[] =
{
{ &hf_opcode,
{ "Opcode", "dof.sgmp.v1.opcode", FT_UINT8, BASE_DEC, VALS(sgmp_opcode_strings), 0x0, NULL, HFILL } },
{ &hf_sgmp_domain,
{ "Domain", "dof.sgmp.v1.domain", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_sgmp_epoch,
{ "Epoch", "dof.sgmp.v1.epoch", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_initiator_block,
{ "Initiator Block", "dof.sgmp.v1.initiator-block", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_sgmp_security_scope,
{ "Security Scope", "dof.sgmp.v1.security-scope", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_initial_state,
{ "Initial State", "dof.sgmp.v1.initial-state", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_latest_version,
{ "Latest SGMP Version", "dof.sgmp.v1.latest-sgmp-version", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_desire,
{ "Desire", "dof.sgmp.v1.desire", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_ticket,
{ "Ticket", "dof.sgmp.v1.ticket", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_sgmp_tmin,
{ "TMIN", "dof.sgmp.v1.tmin", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_tie_breaker,
{ "Tie Breaker", "dof.sgmp.v1.tie-breaker", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_delay,
{ "Delay", "dof.sgmp.v1.delay", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_key,
{ "Key", "dof.sgmp.v1.key", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_sgmp,
&ett_sgmp_domain,
&ett_initiator_block,
&ett_sgmp_security_scope,
&ett_initial_state,
&ett_ticket,
};
proto_sgmp = proto_register_protocol("DOF Secure Group Management Protocol", "DOF.SGMP", "dof.sgmp");
proto_register_field_array(proto_sgmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void dof_reg_handoff_sgmp_130(void)
{
dissector_handle_t sgmp_handle = create_dissector_handle(dissect_sgmp, proto_sgmp);
dissector_add_uint("dof.app", DOF_PROTOCOL_SGMP, sgmp_handle);
}
static void dof_sgmp_register(void)
{
dof_register_sgmp_130();
}
static void dof_sgmp_handoff(void)
{
dof_reg_handoff_sgmp_130();
}
static void dof_tep_reset(void)
{
}
static void dof_tep_cleanup(void)
{
}
static void dof_register_tep_128(void)
{
static hf_register_info hfdsp[] =
{
{ &hf_dsp_option,
{ "Ticket Exchange Protocol Version 1", "dof.tep1.dsp_opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static hf_register_info hf[] =
{
{ &hf_tep_operation,
{ "Operation", "dof.tep1.operation", FT_UINT8, BASE_DEC, VALS(tep_opcode_strings), 0x00, NULL, HFILL } },
{ &hf_tep_operation_type,
{ "Operation Type", "dof.tep1.operation_type", FT_BOOLEAN, 8, TFS(&tep_optype_vals), TEP_OPCODE_RSP, NULL, HFILL } },
{ &hf_tep_opcode,
{ "Opcode", "dof.tep1.opcode", FT_UINT8, BASE_DEC, VALS(tep_opcode_strings), 0x0F, NULL, HFILL } },
{ &hf_tep_k,
{ "K", "dof.tep1.k", FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL } },
{ &hf_tep_c,
{ "C", "dof.tep1.c", FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL } },
{ &hf_tep_reject_code,
{ "Code", "dof.tep1.reject.code", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_reject_data,
{ "Data", "dof.tep1.reject.data", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_1_domain,
{ "Domain", "dof.2008.4.tep1.2.1.domain", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_tep_2_1_initiator_block,
{ "Initiator Block", "dof.2008.4.tep1.2.1.initiator_block", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_1_ticket_confirmation,
{ "Ticket Confirmation", "dof.2008.4.tep1.2.1.ticket_confirmation", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_initiator_ticket,
{ "Initiator Ticket", "dof.2008.4.tep1.2.2.initiator_ticket", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_ticket_confirmation,
{ "Ticket Confirmation", "dof.2008.4.tep1.2.2.ticket_confirmation", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_responder_initialization,
{ "Responder Initialization", "dof.2008.4.tep1.2.2.responder_initialization", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_responder_block,
{ "Responder Block", "dof.2008.4.tep1.2.2.responder_block", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_authenticator_initialization,
{ "Authenticator Initialization", "dof.2008.4.tep1.2.2.authenticator_initialization", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_1_state_identifier,
{ "State Identifier", "dof.2008.4.tep1.2.2.1.state_identifier", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_2_2_1_initial_state,
{ "Initial State", "dof.2008.4.tep1.2.2.1.initial_state", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_tep_session_key,
{ "Session Key", "dof.session_key", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_tep_dsp,
&ett_tep_dsp_options,
&ett_tep,
&ett_tep_operation,
&ett_tep_2_1_domain,
&ett_tep_2_1_initiator_block,
&ett_tep_2_2_initiator_ticket,
&ett_tep_2_2_responder_initialization,
&ett_tep_2_2_responder_block,
&ett_tep_2_2_authenticator_initialization,
&ett_tep_2_2_1_initial_state,
};
proto_tep = proto_register_protocol("DOF Ticket Exchange Protocol Version 1", "DOF.TEP1", "dof.tep1");
proto_tep_dsp = proto_register_protocol("DOF Ticket Exchange Protocol DSP Options", "DOF.TEP1.DSP", "dof.tep1.dsp");
proto_register_field_array(proto_tep, hf, array_length(hf));
proto_register_field_array(proto_tep_dsp, hfdsp, array_length(hfdsp));
proto_register_subtree_array(ett, array_length(ett));
}
static void dof_reg_handoff_tep_128(void)
{
dissector_handle_t tep_handle = create_dissector_handle(dissect_tep, proto_tep);
dissector_handle_t dsp_handle = create_dissector_handle(dissect_tep_dsp, proto_tep_dsp);
dissector_add_uint("dof.app", DOF_PROTOCOL_TEP, tep_handle);
dissector_add_uint("dof.dsp.options", DSP_TEP_FAMILY | DOF_PROTOCOL_TEP, dsp_handle);
}
static void dof_tep_register(void)
{
dof_register_tep_128();
}
static void dof_tep_handoff(void)
{
dof_reg_handoff_tep_128();
}
static void dof_trp_reset(void)
{
}
static void dof_trp_cleanup(void)
{
}
static void dof_register_trp_129(void)
{
expert_module_t *expert_trp;
static hf_register_info hfdsp[] =
{
{ &hf_trp_dsp_option,
{ "Ticket Request Protocol", "dof.trp.dsp_opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static hf_register_info hf[] =
{
{ &hf_trp_opcode,
{ "Opcode", "dof.trp.opcode", FT_UINT8, BASE_DEC, VALS(trp_opcode_strings), 0x0, NULL, HFILL } },
{ &hf_domain,
{ "Domain", "dof.trp.domain", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_identity_resolution,
{ "Identity Resolution", "dof.trp.identity_resolution", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_initiator_request,
{ "Initiator Request", "dof.trp.initiator_request", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_responder_request,
{ "Responder Request", "dof.trp.responder_request", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_initiator_ticket,
{ "Initiator Ticket", "dof.trp.initiator_ticket", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_responder_ticket,
{ "Responder Ticket", "dof.trp.responder_ticket", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_authentication_block,
{ "Authentication Block", "dof.trp.authentication_block", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_group_identifier,
{ "Group Identifier", "dof.trp.group_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_node_identifier,
{ "Node Identifier", "dof.trp.node_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_thb,
{ "Thb", "dof.trp.thb", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_tmin,
{ "Tmin", "dof.trp.tmin", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_tmax,
{ "Tmax", "dof.trp.tmax", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_trp_epoch,
{ "Epoch", "dof.trp.epoch", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_sidg,
{ "SIDg", "dof.trp.sid_g", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_security_scope,
{ "Security Scope", "dof.trp.security_scope", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_security_mode,
{ "Security Mode", "dof.trp.security_mode", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ssid,
{ "SSID", "dof.trp.ssid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_initiator_pg,
{ "Initiator Permissions", "dof.trp.initiator_pg", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_initiator_validation,
{ "Initiator Validation", "dof.trp.initiator_validation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_responder_pg,
{ "Responder Permissions", "dof.trp.responder_pg", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_responder_validation,
{ "Responder Validation", "dof.trp.responder_validation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_errorcode,
{ "Error Code", "dof.trp.errorcode", FT_UINT8, BASE_DEC, VALS(trp_error_strings), 0x0, NULL, HFILL } },
{ &hf_trp_duration,
{ "Duration", "dof.trp.duration", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_trp_rnonce,
{ "Requestor Nonce", "dof.trp.rnonce", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_pnonce,
{ "Provider Nonce", "dof.trp.pnonce", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_reqid,
{ "Requestor ID", "dof.trp.reqid", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_provid,
{ "Provider ID", "dof.trp.provid", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_count,
{ "Permission Count", "dof.trp.perm.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_type,
{ "Permission Type", "dof.trp.perm.type", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_rflags,
{ "Requestor SRP Flags", "dof.trp.rflags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_rcache,
{ "Requestor SRP Cache", "dof.trp.rcache", FT_BOOLEAN, 8, NULL, 0x2, NULL, HFILL } },
{ &hf_trp_perm_rsrp,
{ "Requestor SRP", "dof.trp.rsrp", FT_BOOLEAN, 8, NULL, 0x1, NULL, HFILL } },
{ &hf_trp_perm_rsrp_a,
{ "Requestor SRP A", "dof.trp.rsrp.a", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_rsrp_u,
{ "Requestor SRP u", "dof.trp.rsrp.u", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_pflags,
{ "Provider SRP Flags", "dof.trp.pflags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_pcache,
{ "Provider SRP Cache", "dof.trp.pcache", FT_BOOLEAN, 8, NULL, 0x2, NULL, HFILL } },
{ &hf_trp_perm_psrp,
{ "Provider SRP", "dof.trp.psrp", FT_BOOLEAN, 8, NULL, 0x1, NULL, HFILL } },
{ &hf_trp_perm_psrp_a,
{ "Provider SRP A", "dof.trp.psrp.a", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_psrp_u,
{ "Provider SRP u", "dof.trp.psrp.u", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_psrp_b,
{ "Provider SRP B", "dof.trp.psrp.b", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_psrp_s,
{ "Provider SRP S", "dof.trp.psrp.s", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_confirmation,
{ "Confirmation", "dof.trp.confirmation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_pke,
{ "Provider Key Expression", "dof.trp.pke", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_trp_perm_pka,
{ "Provider Key Authenticator", "dof.trp.pka", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#endif
};
static gint *ett[] =
{
&ett_trp_dsp,
&ett_trp,
&ett_domain,
&ett_identity_resolution,
&ett_initiator_request,
&ett_initiator_ticket,
&ett_responder_request,
&ett_responder_ticket,
&ett_authentication_block,
&ett_group_identifier,
&ett_node_identifier,
&ett_sidg,
&ett_security_scope,
&ett_security_mode,
&ett_initiator_pg,
&ett_initiator_validation,
&ett_responder_pg,
&ett_responder_validation,
&ett_trp_permset,
&ett_srp_flags,
&ett_trp_ticket,
};
static ei_register_info ei[] =
{
{ &ei_trp_initiator_id_known, { "dof.trp.initiator_id_known", PI_PROTOCOL, PI_COMMENT, "Initiator identity known", EXPFILL } },
{ &ei_trp_kek_discovered, { "dof.trp.kek_discovered", PI_PROTOCOL, PI_COMMENT, "KEK discovered", EXPFILL } },
};
proto_trp = proto_register_protocol("DOF Ticket Request Protocol", "DOF.TRP", "dof.trp");
proto_trp_dsp = proto_register_protocol("DOF Ticket Request Protocol DSP Options", "DOF.TRP.DSP", "dof.trp.dsp");
proto_register_field_array(proto_trp, hf, array_length(hf));
proto_register_field_array(proto_trp_dsp, hfdsp, array_length(hfdsp));
proto_register_subtree_array(ett, array_length(ett));
expert_trp = expert_register_protocol(proto_trp);
expert_register_field_array(expert_trp, ei, array_length(ei));
}
static void dof_reg_handoff_trp_129(void)
{
dissector_handle_t trp_handle = create_dissector_handle(dissect_trp, proto_trp);
dissector_handle_t dsp_handle = create_dissector_handle(dissect_trp_dsp, proto_trp_dsp);
dissector_add_uint("dof.app", DOF_PROTOCOL_TRP, trp_handle);
dissector_add_uint("dof.dsp.options", DSP_TRP_FAMILY | DOF_PROTOCOL_TRP, dsp_handle);
}
static void dof_trp_register(void)
{
dof_register_trp_129();
}
static void dof_trp_handoff(void)
{
dof_reg_handoff_trp_129();
}
static void dof_reset_routine(void)
{
dof_tun_reset();
dof_reset();
oid_reset();
dof_dnp_reset();
dof_dpp_reset();
app_reset();
dof_dsp_reset();
dof_ccm_reset();
dof_oap_reset();
dof_sgmp_reset();
dof_tep_reset();
dof_trp_reset();
}
static void dof_cleanup_routine(void)
{
dof_tun_cleanup();
dof_cleanup();
oid_cleanup();
dof_dnp_cleanup();
dof_dpp_cleanup();
app_cleanup();
dof_dsp_cleanup();
dof_ccm_cleanup();
dof_oap_cleanup();
dof_sgmp_cleanup();
dof_tep_cleanup();
dof_trp_cleanup();
}
void proto_register_dof(void)
{
dof_tun_register();
dof_register();
oid_register();
dof_dnp_register();
dof_dpp_register();
app_register();
dof_dsp_register();
dof_ccm_register();
dof_oap_register();
dof_sgmp_register();
dof_tep_register();
dof_trp_register();
register_init_routine(&dof_reset_routine);
register_cleanup_routine(&dof_cleanup_routine);
}
void proto_reg_handoff_dof(void)
{
dof_tun_handoff();
dof_handoff();
oid_handoff();
dof_dnp_handoff();
dof_dpp_handoff();
app_handoff();
dof_dsp_handoff();
dof_ccm_handoff();
dof_oap_handoff();
dof_sgmp_handoff();
dof_tep_handoff();
dof_trp_handoff();
}
static gint p_compare(gconstpointer a, gconstpointer b)
{
const dof_proto_data *ap = (const dof_proto_data *)a;
const dof_proto_data *bp = (const dof_proto_data *)b;
if (ap->proto > bp->proto)
return 1;
else if (ap->proto == bp->proto)
return 0;
else
return -1;
}
static void dof_packet_add_proto_data(dof_packet_data *packet, int proto, void *proto_data)
{
dof_proto_data *p1 = wmem_new0(wmem_file_scope(), dof_proto_data);
p1->proto = proto;
p1->proto_data = proto_data;
packet->data_list = g_slist_insert_sorted(packet->data_list, (gpointer *)p1, p_compare);
}
static void *dof_packet_get_proto_data(dof_packet_data *packet, int proto)
{
dof_proto_data temp, *p1;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(packet->data_list, (gpointer *)&temp,
p_compare);
if (item != NULL)
{
p1 = (dof_proto_data *)item->data;
return p1->proto_data;
}
return NULL;
}
static gint dof_dissect_pdu_as_field(dissector_t dissector, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int item, int ett, void *result)
{
int block_length;
tvbuff_t *start = tvb_new_subset(tvb, offset, -1, -1);
proto_tree *my_tree;
proto_item *ti = proto_tree_add_item(tree, item, tvb, offset, -1, ENC_NA);
my_tree = proto_item_add_subtree(ti, ett);
block_length = dof_dissect_pdu(dissector, start, pinfo, my_tree, result);
return offset + block_length;
}
static gint dof_dissect_pdu(dissector_t dissector, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *result)
{
gint len = dissector(tvb, pinfo, tree, result);
proto_item_set_len(proto_tree_get_parent(tree), len);
return len;
}
static int dof_dissect_dnp_length(tvbuff_t *tvb, packet_info *pinfo, guint8 version, gint *offset)
{
dissector_handle_t dp;
dp = dissector_get_uint_handle(dnp_framing_dissectors, version);
if (!dp)
return -1;
return call_dissector_only(dp, tvb, pinfo, NULL, offset);
}
