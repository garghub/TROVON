static conversation_t *_find_or_create_conversation(packet_info * pinfo)
{
conversation_t *conv = NULL;
conv =
find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, 0, 0, 0);
if (conv == NULL) {
conv =
conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, 0, 0, 0);
}
return conv;
}
static void
dissect_mip_extensions(tvbuff_t * tvb, int offset, proto_tree * tree)
{
guint8 type;
guint8 length;
guint16 flags;
proto_item *ti;
proto_tree *mip_tree = NULL;
proto_tree *flags_tree = NULL;
gint numCOAs;
gint i;
if (!tree)
return;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
type = tvb_get_guint8(tvb, offset + 0);
if (type) {
length = tvb_get_guint8(tvb, offset + 1);
} else {
length = 0;
}
ti = proto_tree_add_text(tree, tvb, offset,
type ? (length + 2) : 1,
"Ext: %s", val_to_str(type,
mip_extensions,
"Unknown ext %u"));
mip_tree = proto_item_add_subtree(ti, ett_icmp_mip);
switch (type) {
case ICMP_MIP_EXTENSION_PAD:
proto_tree_add_item(mip_tree, hf_icmp_mip_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
break;
case ICMP_MIP_MOB_AGENT_ADV:
proto_tree_add_item(mip_tree, hf_icmp_mip_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_icmp_mip_length,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_icmp_mip_seq, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip_tree, hf_icmp_mip_life,
tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
flags = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_uint(mip_tree,
hf_icmp_mip_flags, tvb,
offset, 2, flags);
flags_tree =
proto_item_add_subtree(ti, ett_icmp_mip_flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_r,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_b,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_h,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_f,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_m,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_g,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_v,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_rt,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_u,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_icmp_mip_x,
tvb, offset, 2, flags);
proto_tree_add_uint(flags_tree,
hf_icmp_mip_reserved, tvb,
offset, 2, flags);
offset += 2;
numCOAs = (length - 6) / 4;
for (i = 0; i < numCOAs; i++) {
proto_tree_add_item(mip_tree,
hf_icmp_mip_coa, tvb,
offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
break;
case ICMP_MIP_PREFIX_LENGTHS:
proto_tree_add_item(mip_tree, hf_icmp_mip_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_icmp_mip_length,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
for (i = 0; i < length; i++) {
proto_tree_add_item(mip_tree,
hf_icmp_mip_prefix_length,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
}
break;
case ICMP_MIP_CHALLENGE:
proto_tree_add_item(mip_tree, hf_icmp_mip_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_icmp_mip_length,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree,
hf_icmp_mip_challenge, tvb,
offset, length, ENC_NA);
offset += length;
break;
default:
proto_tree_add_item(mip_tree, hf_icmp_mip_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_icmp_mip_length,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
if (length != 0) {
proto_tree_add_text(mip_tree, tvb, offset,
length, "Contents");
offset += length;
}
break;
}
}
}
static gboolean
dissect_mpls_extended_payload_object(tvbuff_t * tvb, gint offset,
proto_tree * ext_object_tree,
proto_item * tf_object)
{
guint16 obj_length, obj_trunc_length;
gboolean unknown_object;
guint8 c_type;
unknown_object = FALSE;
obj_length = tvb_get_ntohs(tvb, offset);
obj_trunc_length =
MIN(obj_length, tvb_reported_length_remaining(tvb, offset));
c_type = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_uint(ext_object_tree, hf_icmp_ext_c_type, tvb,
offset + 3, 1, c_type);
offset += 4;
switch (c_type) {
case MPLS_EXTENDED_PAYLOAD_C_TYPE:
proto_item_set_text(tf_object, "Extended Payload");
if (obj_trunc_length > 4) {
proto_tree_add_text(ext_object_tree, tvb,
offset, obj_trunc_length - 4,
"Data (%d bytes)",
obj_trunc_length - 4);
}
break;
default:
unknown_object = TRUE;
}
return unknown_object;
}
static gboolean
dissect_mpls_stack_entry_object(tvbuff_t * tvb, gint offset,
proto_tree * ext_object_tree,
proto_item * tf_object)
{
proto_item *tf_entry;
proto_tree *mpls_stack_object_tree;
guint16 obj_length, obj_trunc_length;
gint obj_end_offset;
guint label;
guint8 ttl;
guint8 tmp;
gboolean unknown_object;
guint8 c_type;
unknown_object = FALSE;
obj_length = tvb_get_ntohs(tvb, offset);
obj_trunc_length =
MIN(obj_length, tvb_reported_length_remaining(tvb, offset));
obj_end_offset = offset + obj_trunc_length;
c_type = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_uint(ext_object_tree, hf_icmp_ext_c_type, tvb,
offset + 3, 1, c_type);
offset += 4;
switch (c_type) {
case MPLS_STACK_ENTRY_C_TYPE:
proto_item_set_text(tf_object, "MPLS Stack Entry");
while (offset + 4 <= obj_end_offset) {
if (tvb_reported_length_remaining(tvb, offset) < 4) {
break;
}
tf_entry = proto_tree_add_text(ext_object_tree,
tvb, offset, 4,
" ");
mpls_stack_object_tree =
proto_item_add_subtree(tf_entry,
ett_icmp_mpls_stack_object);
label = (guint) tvb_get_ntohs(tvb, offset);
tmp = tvb_get_guint8(tvb, offset + 2);
label = (label << 4) + (tmp >> 4);
proto_tree_add_uint(mpls_stack_object_tree,
hf_icmp_mpls_label, tvb,
offset, 3, label << 4);
proto_item_set_text(tf_entry, "Label: %u", label);
proto_tree_add_uint(mpls_stack_object_tree,
hf_icmp_mpls_exp, tvb,
offset + 2, 1, tmp);
proto_item_append_text(tf_entry, ", Exp: %u",
(tmp >> 1) & 0x07);
proto_tree_add_boolean(mpls_stack_object_tree,
hf_icmp_mpls_s, tvb,
offset + 2, 1, tmp);
proto_item_append_text(tf_entry, ", S: %u",
tmp & 0x01);
ttl = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_item(mpls_stack_object_tree,
hf_icmp_mpls_ttl, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tf_entry, ", TTL: %u", ttl);
offset += 4;
}
if (offset < obj_end_offset) {
proto_tree_add_text(ext_object_tree, tvb, offset,
obj_end_offset - offset,
"%d junk bytes",
obj_end_offset - offset);
}
break;
default:
unknown_object = TRUE;
break;
}
return unknown_object;
}
static gboolean
dissect_interface_information_object(tvbuff_t * tvb, gint offset,
proto_tree * ext_object_tree,
proto_item * tf_object)
{
proto_item *ti;
proto_tree *int_name_object_tree = NULL;
proto_tree *int_ipaddr_object_tree;
guint16 obj_length, obj_trunc_length;
gint obj_end_offset;
guint8 c_type;
gboolean unknown_object;
guint8 if_index_flag;
guint8 ipaddr_flag;
guint8 name_flag;
guint32 if_index;
guint16 afi;
struct e_in6_addr ipaddr_v6;
guint8 int_name_length = 0;
unknown_object = FALSE;
obj_length = tvb_get_ntohs(tvb, offset);
obj_trunc_length =
MIN(obj_length, tvb_reported_length_remaining(tvb, offset));
obj_end_offset = offset + obj_trunc_length;
c_type = tvb_get_guint8(tvb, offset + 3);
proto_item_set_text(tf_object, "Interface Information Object");
if (tvb_reported_length_remaining(tvb, offset) < 4) {
return TRUE;
}
if_index_flag = (c_type & INT_INFO_IFINDEX) >> 3;
ipaddr_flag = (c_type & INT_INFO_IPADDR) >> 2;
name_flag = (c_type & INT_INFO_NAME) >> 1;
{
static const gint *c_type_fields[] = {
&hf_icmp_int_info_role,
&hf_icmp_int_info_reserved,
&hf_icmp_int_info_ifindex,
&hf_icmp_int_info_ipaddr,
&hf_icmp_int_info_name,
&hf_icmp_int_info_mtu,
NULL
};
proto_tree_add_bitmask(ext_object_tree, tvb, offset + 3,
hf_icmp_ext_c_type,
ett_icmp_interface_info_object,
c_type_fields, ENC_BIG_ENDIAN);
}
offset += 4;
if (if_index_flag) {
if (obj_end_offset >= offset + 4) {
if_index = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(ext_object_tree,
tvb, offset, 4,
"Interface Index: %u",
if_index);
offset += 4;
} else {
proto_tree_add_text(ext_object_tree,
tvb, offset, 4,
"Interface Index:(truncated)");
return FALSE;
}
}
if (ipaddr_flag && (obj_end_offset >= offset + 2)) {
afi = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_text(ext_object_tree, tvb, offset,
afi == 1 ? 8 : 10,
"IP Address Sub-Object");
int_ipaddr_object_tree =
proto_item_add_subtree(ti, ett_icmp_interface_ipaddr);
proto_tree_add_uint(int_ipaddr_object_tree,
hf_icmp_int_info_afi, tvb, offset, 2,
afi);
offset += 4;
if (afi == 1 && (obj_end_offset >= offset + 4)) {
proto_tree_add_ipv4(int_ipaddr_object_tree,
hf_icmp_int_info_ipv4, tvb,
offset, 4, tvb_get_ntohl(tvb,
offset));
offset += 4;
} else if (afi == 2
&& (obj_end_offset >= offset + INET6_ADDRLEN)) {
tvb_get_ipv6(tvb, offset, &ipaddr_v6);
proto_tree_add_ipv6(int_ipaddr_object_tree,
hf_icmp_int_info_ipv6, tvb,
offset, INET6_ADDRLEN,
(guint8 *) & ipaddr_v6);
offset += INET6_ADDRLEN;
} else {
proto_tree_add_text(int_ipaddr_object_tree, tvb,
offset,
offset - obj_end_offset,
"Bad IP Address");
return FALSE;
}
}
if (name_flag) {
if (obj_end_offset >= offset + 1) {
int_name_length = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(ext_object_tree, tvb,
offset, int_name_length,
"Interface Name Sub-Object");
int_name_object_tree =
proto_item_add_subtree(ti,
ett_icmp_interface_name);
proto_tree_add_text(int_name_object_tree, tvb,
offset, 1, "Length: %u",
int_name_length);
}
if (obj_end_offset >= offset + 1 + int_name_length) {
proto_tree_add_text(int_name_object_tree, tvb,
offset + 1, int_name_length,
"Interface Name: %s",
tvb_format_text(tvb, offset + 1, int_name_length));
}
}
return unknown_object;
}
static void
dissect_extensions(tvbuff_t * tvb, gint offset, proto_tree * tree)
{
guint8 version;
guint8 class_num;
guint8 c_type;
guint16 cksum, computed_cksum;
guint16 obj_length, obj_trunc_length;
proto_item *ti, *tf_object, *hidden_item;
proto_tree *ext_tree, *ext_object_tree;
gint obj_end_offset;
guint reported_length;
gboolean unknown_object;
guint8 int_info_obj_count;
if (!tree)
return;
ext_tree = NULL;
int_info_obj_count = 0;
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length < 4 ) {
proto_tree_add_text(tree, tvb, offset,
reported_length,
"ICMP Multi-Part Extensions (truncated)");
return;
}
ti = proto_tree_add_none_format(tree, hf_icmp_ext, tvb,
offset, reported_length,
"ICMP Multi-Part Extensions");
ext_tree = proto_item_add_subtree(ti, ett_icmp_ext);
version = hi_nibble(tvb_get_guint8(tvb, offset));
proto_tree_add_uint(ext_tree, hf_icmp_ext_version, tvb, offset, 1,
version);
proto_tree_add_item(ext_tree, hf_icmp_ext_reserved,
tvb, offset, 2, ENC_BIG_ENDIAN);
cksum = tvb_get_ntohs(tvb, offset + 2);
computed_cksum =
ip_checksum(tvb_get_ptr(tvb, offset, reported_length),
reported_length);
if (computed_cksum == 0) {
proto_tree_add_uint_format_value(ext_tree, hf_icmp_ext_checksum,
tvb, offset + 2, 2, cksum,
"0x%04x [correct]",
cksum);
hidden_item =
proto_tree_add_boolean(ext_tree,
hf_icmp_ext_checksum_bad, tvb,
offset + 2, 2, FALSE);
} else {
proto_tree_add_uint_format_value(ext_tree, hf_icmp_ext_checksum,
tvb, offset + 2, 2, cksum,
"0x%04x [incorrect, should be 0x%04x]",
cksum, in_cksum_shouldbe(cksum,
computed_cksum));
hidden_item =
proto_tree_add_boolean(ext_tree,
hf_icmp_ext_checksum_bad, tvb,
offset + 2, 2, TRUE);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (version != 1 && version != 2) {
proto_item_append_text(ti, " (unsupported version)");
return;
}
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) >=
4 ) {
obj_length = tvb_get_ntohs(tvb, offset);
obj_trunc_length =
MIN(obj_length,
tvb_reported_length_remaining(tvb, offset));
obj_end_offset = offset + obj_trunc_length;
tf_object = proto_tree_add_text(ext_tree, tvb, offset,
MAX(obj_trunc_length, 4),
"Unknown object");
ext_object_tree =
proto_item_add_subtree(tf_object, ett_icmp_ext_object);
proto_tree_add_uint(ext_object_tree, hf_icmp_ext_length,
tvb, offset, 2, obj_length);
class_num = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_uint(ext_object_tree, hf_icmp_ext_class,
tvb, offset + 2, 1, class_num);
c_type = tvb_get_guint8(tvb, offset + 3);
if (obj_length < 4 ) {
proto_item_set_text(tf_object,
"Object with bad length");
break;
}
switch (class_num) {
case MPLS_STACK_ENTRY_OBJECT_CLASS:
unknown_object =
dissect_mpls_stack_entry_object(tvb, offset,
ext_object_tree,
tf_object);
break;
case INTERFACE_INFORMATION_OBJECT_CLASS:
unknown_object =
dissect_interface_information_object(tvb,
offset,
ext_object_tree,
tf_object);
int_info_obj_count++;
if (int_info_obj_count > 4) {
proto_item_set_text(tf_object,
"More than 4 Interface Information Objects");
}
break;
case MPLS_EXTENDED_PAYLOAD_OBJECT_CLASS:
unknown_object =
dissect_mpls_extended_payload_object(tvb,
offset,
ext_object_tree,
tf_object);
break;
default:
unknown_object = TRUE;
break;
}
offset += 4;
if (unknown_object == TRUE) {
proto_item_set_text(tf_object,
"Unknown object (%d/%d)",
class_num, c_type);
if (obj_trunc_length > 4) {
proto_tree_add_text(ext_object_tree, tvb,
offset,
obj_trunc_length - 4,
"Data (%d bytes)",
obj_trunc_length - 4);
}
}
if (obj_trunc_length < obj_length) {
proto_item_append_text(tf_object, " (truncated)");
}
offset = obj_end_offset;
}
}
static icmp_transaction_t *transaction_start(packet_info * pinfo,
proto_tree * tree,
guint32 * key)
{
conversation_t *conversation;
icmp_conv_info_t *icmp_info;
icmp_transaction_t *icmp_trans;
wmem_tree_key_t icmp_key[3];
proto_item *it;
conversation = _find_or_create_conversation(pinfo);
icmp_info = (icmp_conv_info_t *)conversation_get_proto_data(conversation, proto_icmp);
if (icmp_info == NULL) {
icmp_info = wmem_new(wmem_file_scope(), icmp_conv_info_t);
icmp_info->unmatched_pdus = wmem_tree_new(wmem_file_scope());
icmp_info->matched_pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_icmp,
icmp_info);
}
if (!PINFO_FD_VISITED(pinfo)) {
icmp_key[0].length = 2;
icmp_key[0].key = key;
icmp_key[1].length = 0;
icmp_key[1].key = NULL;
icmp_trans = wmem_new(wmem_file_scope(), icmp_transaction_t);
icmp_trans->rqst_frame = PINFO_FD_NUM(pinfo);
icmp_trans->resp_frame = 0;
icmp_trans->rqst_time = pinfo->fd->abs_ts;
nstime_set_zero(&icmp_trans->resp_time);
wmem_tree_insert32_array(icmp_info->unmatched_pdus, icmp_key,
(void *) icmp_trans);
} else {
guint32 frame_num = pinfo->fd->num;
icmp_key[0].length = 2;
icmp_key[0].key = key;
icmp_key[1].length = 1;
icmp_key[1].key = &frame_num;
icmp_key[2].length = 0;
icmp_key[2].key = NULL;
icmp_trans =
(icmp_transaction_t *)wmem_tree_lookup32_array(icmp_info->matched_pdus,
icmp_key);
}
if (icmp_trans == NULL) {
if (PINFO_FD_VISITED(pinfo)) {
it = proto_tree_add_item(tree, hf_icmp_no_resp, NULL, 0, 0,
ENC_NA);
PROTO_ITEM_SET_GENERATED(it);
col_append_fstr(pinfo->cinfo, COL_INFO, " (no response found!)");
expert_add_info_format(pinfo, it, &ei_icmp_resp_not_found,
"No response seen to ICMP request in frame %u",
pinfo->fd->num);
}
return NULL;
}
if (icmp_trans->resp_frame) {
it = proto_tree_add_uint(tree, hf_icmp_resp_in, NULL, 0, 0,
icmp_trans->resp_frame);
PROTO_ITEM_SET_GENERATED(it);
col_append_fstr(pinfo->cinfo, COL_INFO, " (reply in %d)",
icmp_trans->resp_frame);
}
return icmp_trans;
}
static icmp_transaction_t *transaction_end(packet_info * pinfo,
proto_tree * tree,
guint32 * key)
{
conversation_t *conversation;
icmp_conv_info_t *icmp_info;
icmp_transaction_t *icmp_trans;
wmem_tree_key_t icmp_key[3];
proto_item *it;
nstime_t ns;
double resp_time;
conversation =
find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, 0, 0, 0);
if (conversation == NULL) {
return NULL;
}
icmp_info = (icmp_conv_info_t *)conversation_get_proto_data(conversation, proto_icmp);
if (icmp_info == NULL) {
return NULL;
}
if (!PINFO_FD_VISITED(pinfo)) {
guint32 frame_num;
icmp_key[0].length = 2;
icmp_key[0].key = key;
icmp_key[1].length = 0;
icmp_key[1].key = NULL;
icmp_trans =
(icmp_transaction_t *)wmem_tree_lookup32_array(icmp_info->unmatched_pdus,
icmp_key);
if (icmp_trans == NULL) {
return NULL;
}
if (icmp_trans->resp_frame != 0) {
return NULL;
}
icmp_trans->resp_frame = PINFO_FD_NUM(pinfo);
icmp_key[0].length = 2;
icmp_key[0].key = key;
icmp_key[1].length = 1;
icmp_key[1].key = &frame_num;
icmp_key[2].length = 0;
icmp_key[2].key = NULL;
frame_num = icmp_trans->rqst_frame;
wmem_tree_insert32_array(icmp_info->matched_pdus, icmp_key,
(void *) icmp_trans);
frame_num = icmp_trans->resp_frame;
wmem_tree_insert32_array(icmp_info->matched_pdus, icmp_key,
(void *) icmp_trans);
} else {
guint32 frame_num = pinfo->fd->num;
icmp_key[0].length = 2;
icmp_key[0].key = key;
icmp_key[1].length = 1;
icmp_key[1].key = &frame_num;
icmp_key[2].length = 0;
icmp_key[2].key = NULL;
icmp_trans =
(icmp_transaction_t *)wmem_tree_lookup32_array(icmp_info->matched_pdus,
icmp_key);
if (icmp_trans == NULL) {
return NULL;
}
}
it = proto_tree_add_uint(tree, hf_icmp_resp_to, NULL, 0, 0,
icmp_trans->rqst_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &icmp_trans->rqst_time);
icmp_trans->resp_time = ns;
resp_time = nstime_to_msec(&ns);
it = proto_tree_add_double_format_value(tree, hf_icmp_resptime,
NULL, 0, 0, resp_time,
"%.3f ms", resp_time);
PROTO_ITEM_SET_GENERATED(it);
col_append_fstr(pinfo->cinfo, COL_INFO, " (request in %d)",
icmp_trans->rqst_frame);
return icmp_trans;
}
static guint32
get_best_guess_mstimeofday(tvbuff_t * tvb, gint offset, guint32 comp_ts)
{
guint32 be_ts, le_ts;
be_ts = tvb_get_ntohl(tvb, offset) & 0x7fffffff;
le_ts = tvb_get_letohl(tvb, offset) & 0x7fffffff;
if (be_ts < MSPERDAY && le_ts >= MSPERDAY) {
return be_ts;
}
if (le_ts < MSPERDAY && be_ts >= MSPERDAY) {
return le_ts;
}
if (be_ts < MSPERDAY && le_ts < MSPERDAY) {
guint32 saved_be_ts = be_ts;
guint32 saved_le_ts = le_ts;
if (be_ts < comp_ts && be_ts <= (MSPERDAY / 4)
&& comp_ts >= (MSPERDAY - (MSPERDAY / 4)))
be_ts += MSPERDAY;
if (le_ts < comp_ts && le_ts <= (MSPERDAY / 4)
&& comp_ts >= (MSPERDAY - (MSPERDAY / 4)))
le_ts += MSPERDAY;
if ((be_ts - comp_ts) < (le_ts - comp_ts))
return saved_be_ts;
return saved_le_ts;
}
if ((be_ts - comp_ts) < (le_ts - comp_ts)) {
return be_ts;
}
return le_ts;
}
static int
dissect_icmp(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data)
{
proto_tree *icmp_tree = NULL;
proto_item *ti;
guint8 icmp_type;
guint8 icmp_code;
guint8 icmp_original_dgram_length;
guint length, reported_length;
guint16 cksum, computed_cksum;
const gchar *type_str, *code_str;
guint8 num_addrs = 0;
guint8 addr_entry_size = 0;
int i;
gboolean save_in_error_pkt;
tvbuff_t *next_tvb;
proto_item *item;
guint32 conv_key[2];
icmp_transaction_t *trans = NULL;
nstime_t ts, time_relative;
ws_ip *iph = (ws_ip*)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICMP");
col_clear(pinfo->cinfo, COL_INFO);
icmp_type = tvb_get_guint8(tvb, 0);
icmp_code = tvb_get_guint8(tvb, 1);
cksum = tvb_get_ntohs(tvb, 2);
icmp_original_dgram_length = tvb_get_guint8(tvb, 5);
type_str =
val_to_str_const(icmp_type, icmp_type_str,
"Unknown ICMP (obsolete or malformed?)");
switch (icmp_type) {
case ICMP_UNREACH:
code_str =
val_to_str(icmp_code, unreach_code_str,
"Unknown code: %u");
break;
case ICMP_REDIRECT:
code_str =
val_to_str(icmp_code, redir_code_str,
"Unknown code: %u");
break;
case ICMP_ALTHOST:
code_str =
val_to_str(icmp_code, alt_host_code_str,
"Unknown code: %u");
break;
case ICMP_RTRADVERT:
switch (icmp_code) {
case 0:
case 16:
type_str = "Mobile IP Advertisement";
break;
}
code_str =
val_to_str(icmp_code, rtradvert_code_str,
"Unknown code: %u");
break;
case ICMP_TIMXCEED:
code_str =
val_to_str(icmp_code, ttl_code_str,
"Unknown code: %u");
break;
case ICMP_PARAMPROB:
code_str =
val_to_str(icmp_code, par_code_str,
"Unknown code: %u");
break;
case ICMP_PHOTURIS:
code_str =
val_to_str(icmp_code, photuris_code_str,
"Unknown code: %u");
break;
default:
code_str = NULL;
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%-20s", type_str);
if (code_str) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", code_str);
}
length = tvb_length(tvb);
reported_length = tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_icmp, tvb, 0, length, ENC_NA);
icmp_tree = proto_item_add_subtree(ti, ett_icmp);
ti = proto_tree_add_item(icmp_tree, hf_icmp_type, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", type_str);
ti = proto_tree_add_item(icmp_tree, hf_icmp_code, tvb, 1, 1,
ENC_BIG_ENDIAN);
if (code_str) {
proto_item_append_text(ti, " (%s)", code_str);
}
if (!pinfo->fragmented && length >= reported_length
&& !pinfo->flags.in_error_pkt) {
computed_cksum =
ip_checksum(tvb_get_ptr(tvb, 0, reported_length),
reported_length);
if (computed_cksum == 0) {
proto_tree_add_uint_format_value(icmp_tree,
hf_icmp_checksum, tvb,
2, 2, cksum,
"0x%04x [correct]",
cksum);
item =
proto_tree_add_boolean(icmp_tree,
hf_icmp_checksum_bad,
tvb, 2, 2, FALSE);
PROTO_ITEM_SET_HIDDEN(item);
} else {
proto_tree_add_uint_format_value(icmp_tree,
hf_icmp_checksum, tvb,
2, 2, cksum,
"0x%04x [incorrect, should be 0x%04x]",
cksum,
in_cksum_shouldbe(cksum,
computed_cksum));
item =
proto_tree_add_boolean(icmp_tree,
hf_icmp_checksum_bad,
tvb, 2, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(item);
}
} else {
proto_tree_add_uint(icmp_tree, hf_icmp_checksum, tvb, 2, 2,
cksum);
}
switch (icmp_type) {
case ICMP_ECHOREPLY:
case ICMP_ECHO:
case ICMP_TSTAMP:
case ICMP_TSTAMPREPLY:
case ICMP_IREQ:
case ICMP_IREQREPLY:
case ICMP_MASKREQ:
case ICMP_MASKREPLY:
proto_tree_add_item(icmp_tree, hf_icmp_ident, tvb, 4, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(icmp_tree, hf_icmp_ident_le, tvb, 4, 2,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(icmp_tree, hf_icmp_seq_num, tvb, 6, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(icmp_tree, hf_icmp_seq_num_le, tvb, 6,
2, ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO,
" id=0x%04x, seq=%u/%u, ttl=%u",
tvb_get_ntohs(tvb, 4), tvb_get_ntohs(tvb,
6),
tvb_get_letohs(tvb, 6), (iph != NULL) ? iph->ip_ttl : 0);
break;
case ICMP_UNREACH:
if (icmp_original_dgram_length > 0) {
ti = proto_tree_add_item(icmp_tree, hf_icmp_length,
tvb, 5, 1,
ENC_BIG_ENDIAN);
proto_item_append_text(ti,
"Length of original datagram: %u",
icmp_original_dgram_length *
4);
}
switch (icmp_code) {
case ICMP_FRAG_NEEDED:
proto_tree_add_item(icmp_tree, hf_icmp_mtu, tvb, 6,
2, ENC_BIG_ENDIAN);
break;
}
break;
case ICMP_RTRADVERT:
num_addrs = tvb_get_guint8(tvb, 4);
proto_tree_add_text(icmp_tree, tvb, 4, 1,
"Number of addresses: %u", num_addrs);
addr_entry_size = tvb_get_guint8(tvb, 5);
proto_tree_add_text(icmp_tree, tvb, 5, 1,
"Address entry size: %u",
addr_entry_size);
proto_tree_add_text(icmp_tree, tvb, 6, 2, "Lifetime: %s",
time_secs_to_ep_str(tvb_get_ntohs
(tvb, 6)));
break;
case ICMP_PARAMPROB:
proto_tree_add_text(icmp_tree, tvb, 4, 1, "Pointer: %u",
tvb_get_guint8(tvb, 4));
if (icmp_original_dgram_length > 0) {
ti = proto_tree_add_item(icmp_tree, hf_icmp_length,
tvb, 5, 1,
ENC_BIG_ENDIAN);
proto_item_append_text(ti,
" Length of original datagram: %u",
icmp_original_dgram_length *
4);
}
break;
case ICMP_REDIRECT:
proto_tree_add_item(icmp_tree, hf_icmp_redir_gw, tvb, 4, 4,
ENC_BIG_ENDIAN);
break;
case ICMP_TIMXCEED:
if (icmp_original_dgram_length > 0) {
ti = proto_tree_add_item(icmp_tree, hf_icmp_length,
tvb, 5, 1,
ENC_BIG_ENDIAN);
proto_item_append_text(ti,
" Length of original datagram: %u",
icmp_original_dgram_length *
4);
}
}
switch (icmp_type) {
case ICMP_UNREACH:
case ICMP_TIMXCEED:
case ICMP_PARAMPROB:
case ICMP_SOURCEQUENCH:
case ICMP_REDIRECT:
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
next_tvb = tvb_new_subset_remaining(tvb, 8);
if (icmp_original_dgram_length
&& (tvb_reported_length(tvb) >
(guint) (8 + icmp_original_dgram_length * 4))
&& (tvb_get_ntohs(tvb, 8 + 2) >
(guint) icmp_original_dgram_length * 4)) {
set_actual_length(next_tvb,
icmp_original_dgram_length * 4);
} else {
if ((tvb_reported_length(tvb) > 8 + 128) &&
favor_icmp_mpls_ext
&& (tvb_get_ntohs(tvb, 8 + 2) > 128)) {
set_actual_length(next_tvb, 128);
}
}
call_dissector(ip_handle, next_tvb, pinfo, icmp_tree);
pinfo->flags.in_error_pkt = save_in_error_pkt;
if ((tvb_reported_length(tvb) > 8 + 128)
&& (tvb_get_ntohs(tvb, 8 + 2) <= 128
|| favor_icmp_mpls_ext)) {
dissect_extensions(tvb, 8 + 128, icmp_tree);
}
break;
case ICMP_ECHOREPLY:
case ICMP_ECHO:
if (icmp_type == ICMP_ECHOREPLY) {
if (!pinfo->flags.in_error_pkt) {
conv_key[0] =
(guint32) tvb_get_ntohs(tvb, 2);
if (pinfo->flags.in_gre_pkt)
conv_key[0] |= 0x00010000;
conv_key[1] =
(guint32) ((tvb_get_ntohs(tvb, 4) <<
16) | tvb_get_ntohs(tvb,
6));
trans =
transaction_end(pinfo, icmp_tree,
conv_key);
}
} else {
if (!pinfo->flags.in_error_pkt) {
guint16 tmp[2];
tmp[0] = ~tvb_get_ntohs(tvb, 2);
tmp[1] = ~0x0800;
conv_key[0] =
ip_checksum((guint8 *) & tmp,
sizeof(tmp));
if (conv_key[0] == 0) {
conv_key[0] = 0xffff;
}
if (pinfo->flags.in_gre_pkt) {
conv_key[0] |= 0x00010000;
}
conv_key[1] =
(guint32) ((tvb_get_ntohs(tvb, 4) <<
16) | tvb_get_ntohs(tvb,
6));
trans =
transaction_start(pinfo, icmp_tree,
conv_key);
}
}
if (tvb_length_remaining(tvb, 8) < 8) {
if (tvb_length_remaining(tvb, 8) > 0) {
call_dissector(data_handle,
tvb_new_subset_remaining
(tvb, 8), pinfo, icmp_tree);
}
break;
}
ts.secs = tvb_get_ntohl(tvb, 8);
ts.nsecs = tvb_get_ntohl(tvb, 8 + 4);
if ((guint32) (ts.secs - pinfo->fd->abs_ts.secs) >=
3600 * 24 || ts.nsecs >= 1000000) {
ts.secs = tvb_get_letohl(tvb, 8);
ts.nsecs = tvb_get_letohl(tvb, 8 + 4);
}
if ((guint32) (ts.secs - pinfo->fd->abs_ts.secs) <
3600 * 24 && ts.nsecs < 1000000) {
ts.nsecs *= 1000;
proto_tree_add_time(icmp_tree, hf_icmp_data_time,
tvb, 8, 8, &ts);
nstime_delta(&time_relative, &pinfo->fd->abs_ts,
&ts);
ti = proto_tree_add_time(icmp_tree,
hf_icmp_data_time_relative,
tvb, 8, 8,
&time_relative);
PROTO_ITEM_SET_GENERATED(ti);
call_dissector(data_handle,
tvb_new_subset_remaining(tvb,
8 + 8),
pinfo, icmp_tree);
} else {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 8),
pinfo, icmp_tree);
}
break;
case ICMP_RTRADVERT:
if (addr_entry_size == 2) {
for (i = 0; i < num_addrs; i++) {
proto_tree_add_text(icmp_tree, tvb,
8 + (i * 8), 4,
"Router address: %s",
tvb_ip_to_str(tvb,
8 +
(i *
8)));
proto_tree_add_text(icmp_tree, tvb,
12 + (i * 8), 4,
"Preference level: %d",
tvb_get_ntohl(tvb,
12 +
(i *
8)));
}
if ((icmp_code == 0) || (icmp_code == 16)) {
dissect_mip_extensions(tvb, 8 + i * 8,
icmp_tree);
}
} else {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 8),
pinfo, icmp_tree);
}
break;
case ICMP_TSTAMP:
case ICMP_TSTAMPREPLY:
{
guint32 frame_ts, orig_ts;
frame_ts = (guint32)(((pinfo->fd->abs_ts.secs * 1000) +
(pinfo->fd->abs_ts.nsecs / 1000000)) %
86400000);
orig_ts =
get_best_guess_mstimeofday(tvb, 8, frame_ts);
proto_tree_add_text(icmp_tree, tvb, 8, 4,
"Originate timestamp: %s after midnight UTC",
time_msecs_to_ep_str(orig_ts));
proto_tree_add_text(icmp_tree, tvb, 12, 4,
"Receive timestamp: %s after midnight UTC",
time_msecs_to_ep_str
(get_best_guess_mstimeofday
(tvb, 12, orig_ts)));
proto_tree_add_text(icmp_tree, tvb, 16, 4,
"Transmit timestamp: %s after midnight UTC",
time_msecs_to_ep_str
(get_best_guess_mstimeofday
(tvb, 16, orig_ts)));
}
break;
case ICMP_MASKREQ:
case ICMP_MASKREPLY:
proto_tree_add_text(icmp_tree, tvb, 8, 4,
"Address mask: %s (0x%08x)",
tvb_ip_to_str(tvb, 8),
tvb_get_ntohl(tvb, 8));
break;
}
if (trans) {
tap_queue_packet(icmp_tap, pinfo, trans);
}
return tvb_length(tvb);
}
void proto_register_icmp(void)
{
static hf_register_info hf[] = {
{&hf_icmp_type,
{"Type", "icmp.type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_code,
{"Code", "icmp.code", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_checksum,
{"Checksum", "icmp.checksum", FT_UINT16, BASE_HEX, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_checksum_bad,
{"Bad Checksum", "icmp.checksum_bad", FT_BOOLEAN,
BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_ident,
{"Identifier (BE)", "icmp.ident", FT_UINT16, BASE_DEC_HEX,
NULL, 0x0,
"Identifier (big endian representation)", HFILL}},
{&hf_icmp_ident_le,
{"Identifier (LE)", "icmp.ident", FT_UINT16, BASE_DEC_HEX,
NULL, 0x0,
"Identifier (little endian representation)", HFILL}},
{&hf_icmp_seq_num,
{"Sequence number (BE)", "icmp.seq", FT_UINT16,
BASE_DEC_HEX, NULL, 0x0,
"Sequence number (big endian representation)", HFILL}},
{&hf_icmp_seq_num_le,
{"Sequence number (LE)", "icmp.seq_le", FT_UINT16,
BASE_DEC_HEX, NULL,
0x0, "Sequence number (little endian representation)",
HFILL}},
{&hf_icmp_mtu,
{"MTU of next hop", "icmp.mtu", FT_UINT16, BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_redir_gw,
{"Gateway address", "icmp.redir_gw", FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_mip_type,
{"Extension Type", "icmp.mip.type", FT_UINT8, BASE_DEC,
VALS(mip_extensions), 0x0, NULL, HFILL}},
{&hf_icmp_mip_length,
{"Length", "icmp.mip.length", FT_UINT8, BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_mip_prefix_length,
{"Prefix Length", "icmp.mip.prefixlength", FT_UINT8,
BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_mip_seq,
{"Sequence Number", "icmp.mip.seq", FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_mip_life,
{"Registration Lifetime", "icmp.mip.life", FT_UINT16,
BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_mip_flags,
{"Flags", "icmp.mip.flags", FT_UINT16, BASE_HEX, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_mip_r,
{"Registration Required", "icmp.mip.r", FT_BOOLEAN, 16,
NULL, 0x8000,
"Registration with this FA is required", HFILL}},
{&hf_icmp_mip_b,
{"Busy", "icmp.mip.b", FT_BOOLEAN, 16, NULL, 0x4000,
"This FA will not accept requests at this time", HFILL}},
{&hf_icmp_mip_h,
{"Home Agent", "icmp.mip.h", FT_BOOLEAN, 16, NULL, 0x2000,
"Home Agent Services Offered", HFILL}},
{&hf_icmp_mip_f,
{"Foreign Agent", "icmp.mip.f", FT_BOOLEAN, 16, NULL,
0x1000,
"Foreign Agent Services Offered", HFILL}},
{&hf_icmp_mip_m,
{"Minimal Encapsulation", "icmp.mip.m", FT_BOOLEAN, 16,
NULL, 0x0800,
"Minimal encapsulation tunneled datagram support",
HFILL}},
{&hf_icmp_mip_g,
{"GRE", "icmp.mip.g", FT_BOOLEAN, 16, NULL, 0x0400,
"GRE encapsulated tunneled datagram support", HFILL}},
{&hf_icmp_mip_v,
{"VJ Comp", "icmp.mip.v", FT_BOOLEAN, 16, NULL, 0x0200,
"Van Jacobson Header Compression Support", HFILL}},
{&hf_icmp_mip_rt,
{"Reverse tunneling", "icmp.mip.rt", FT_BOOLEAN, 16, NULL,
0x0100,
"Reverse tunneling support", HFILL}},
{&hf_icmp_mip_u,
{"UDP tunneling", "icmp.mip.u", FT_BOOLEAN, 16, NULL,
0x0080,
"UDP tunneling support", HFILL}},
{&hf_icmp_mip_x,
{"Revocation support", "icmp.mip.x", FT_BOOLEAN, 16, NULL,
0x0040,
"Registration revocation support", HFILL}},
{&hf_icmp_mip_reserved,
{"Reserved", "icmp.mip.reserved", FT_UINT16, BASE_HEX,
NULL, 0x003f,
NULL, HFILL}},
{&hf_icmp_mip_coa,
{"Care-Of-Address", "icmp.mip.coa", FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_mip_challenge,
{"Challenge", "icmp.mip.challenge", FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_ext,
{"ICMP Extensions", "icmp.ext", FT_NONE, BASE_NONE, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_ext_version,
{"Version", "icmp.ext.version", FT_UINT8, BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_ext_reserved,
{"Reserved", "icmp.ext.res", FT_UINT16, BASE_HEX, NULL,
0x0fff,
NULL, HFILL}},
{&hf_icmp_ext_checksum,
{"Checksum", "icmp.ext.checksum", FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_ext_checksum_bad,
{"Bad Checksum", "icmp.ext.checksum_bad", FT_BOOLEAN,
BASE_NONE, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_ext_length,
{"Length", "icmp.ext.length", FT_UINT16, BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_ext_class,
{"Class", "icmp.ext.class", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_ext_c_type,
{"C-Type", "icmp.ext.ctype", FT_UINT8, BASE_DEC, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_mpls_label,
{"Label", "icmp.mpls.label", FT_UINT24, BASE_DEC, NULL,
0x00fffff0,
NULL, HFILL}},
{&hf_icmp_mpls_exp,
{"Experimental", "icmp.mpls.exp", FT_UINT24, BASE_DEC,
NULL, 0x0e,
NULL, HFILL}},
{&hf_icmp_mpls_s,
{"Stack bit", "icmp.mpls.s", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), 0x01,
NULL, HFILL}},
{&hf_icmp_mpls_ttl,
{"Time to live", "icmp.mpls.ttl", FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL}},
{&hf_icmp_resp_in,
{"Response frame", "icmp.resp_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0,
"The frame number of the corresponding response",
HFILL}},
{&hf_icmp_no_resp,
{"No response seen", "icmp.no_resp", FT_NONE, BASE_NONE,
NULL, 0x0,
"No corresponding response frame was seen",
HFILL}},
{&hf_icmp_resp_to,
{"Request frame", "icmp.resp_to", FT_FRAMENUM, BASE_NONE,
NULL, 0x0,
"The frame number of the corresponding request", HFILL}},
{&hf_icmp_resptime,
{"Response time", "icmp.resptime", FT_DOUBLE, BASE_NONE,
NULL, 0x0,
"The time between the request and the response, in ms.",
HFILL}},
{&hf_icmp_data_time,
{"Timestamp from icmp data", "icmp.data_time",
FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"The timestamp in the first 8 bytes of the icmp data",
HFILL}},
{&hf_icmp_data_time_relative,
{"Timestamp from icmp data (relative)",
"icmp.data_time_relative",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The timestamp of the packet, relative to the timestamp in the first 8 bytes of the icmp data",
HFILL}},
{&hf_icmp_length,
{"Length of original datagram", "icmp.length", FT_UINT8,
BASE_DEC, NULL,
0x0,
"The length of the original datagram", HFILL}},
{&hf_icmp_int_info_role,
{"Interface Role", "icmp.int_info.role",
FT_UINT8, BASE_DEC, VALS(interface_role_str),
INT_INFO_INTERFACE_ROLE,
NULL, HFILL}},
{&hf_icmp_int_info_reserved,
{"Reserved", "icmp.int_info.reserved",
FT_UINT8, BASE_DEC, NULL, INT_INFO_RESERVED,
NULL, HFILL}},
{&hf_icmp_int_info_ifindex,
{"ifIndex", "icmp.int_info.ifindex", FT_BOOLEAN, 8, NULL,
INT_INFO_IFINDEX,
"True: ifIndex of the interface included; False: ifIndex of the interface not included ",
HFILL}},
{&hf_icmp_int_info_ipaddr,
{"IP Address", "icmp.int_info.ipaddr", FT_BOOLEAN, 8,
NULL,
INT_INFO_IPADDR,
"True: IP Address Sub-Object present; False: IP Address Sub-Object not present",
HFILL}},
{&hf_icmp_int_info_name,
{"Interface Name", "icmp.int_info.name", FT_BOOLEAN, 8,
NULL,
INT_INFO_NAME,
"True: Interface Name Sub-Object present; False: Interface Name Sub-Object not present",
HFILL}},
{&hf_icmp_int_info_mtu,
{"MTU", "icmp.int_info.mtu", FT_BOOLEAN, 8, NULL,
INT_INFO_MTU,
"True: MTU present; False: MTU not present", HFILL}},
{&hf_icmp_int_info_afi,
{"Address Family Identifier", "icmp.int_info.afi",
FT_UINT16, BASE_DEC,
NULL, 0x0,
"Address Family of the interface address", HFILL}},
{&hf_icmp_int_info_ipv4,
{"Source", "icmp.int_info.ipv4", FT_IPv4, BASE_NONE, NULL,
0x0,
NULL, HFILL}},
{&hf_icmp_int_info_ipv6,
{"Source", "icmp.int_info.ipv6", FT_IPv6, BASE_NONE, NULL,
0x0,
NULL, HFILL}}
};
static gint *ett[] = {
&ett_icmp,
&ett_icmp_mip,
&ett_icmp_mip_flags,
&ett_icmp_ext,
&ett_icmp_ext_object,
&ett_icmp_mpls_stack_object,
&ett_icmp_interface_info_object,
&ett_icmp_interface_ipaddr,
&ett_icmp_interface_name
};
static ei_register_info ei[] = {
{ &ei_icmp_resp_not_found, { "icmp.resp_not_found", PI_SEQUENCE, PI_WARN, "Response not found", EXPFILL }},
};
module_t *icmp_module;
expert_module_t* expert_icmp;
proto_icmp =
proto_register_protocol("Internet Control Message Protocol",
"ICMP", "icmp");
proto_register_field_array(proto_icmp, hf, array_length(hf));
expert_icmp = expert_register_protocol(proto_icmp);
expert_register_field_array(expert_icmp, ei, array_length(ei));
proto_register_subtree_array(ett, array_length(ett));
icmp_module = prefs_register_protocol(proto_icmp, NULL);
prefs_register_bool_preference(icmp_module, "favor_icmp_mpls",
"Favor ICMP extensions for MPLS",
"Whether the 128th and following bytes of the ICMP payload should be decoded as MPLS extensions or as a portion of the original packet",
&favor_icmp_mpls_ext);
new_register_dissector("icmp", dissect_icmp, proto_icmp);
icmp_tap = register_tap("icmp");
}
void proto_reg_handoff_icmp(void)
{
dissector_handle_t icmp_handle;
ip_handle = find_dissector("ip");
icmp_handle = find_dissector("icmp");
data_handle = find_dissector("data");
dissector_add_uint("ip.proto", IP_PROTO_ICMP, icmp_handle);
}
