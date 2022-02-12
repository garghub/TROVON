static gint ospf_msg_type_to_filter (guint8 msg_type)
{
if (msg_type >= OSPF_HELLO &&
msg_type <= OSPF_LS_ACK)
return msg_type - OSPF_LS_BASE;
return -1;
}
static gint ospf_ls_type_to_filter (guint8 ls_type)
{
if (ls_type >= OSPF_LSTYPE_ROUTER &&
ls_type <= OSPF_LSTYPE_EXTATTR)
return ls_type - OSPF_LSTYPE_BASE;
else if (ls_type >= OSPF_LSTYPE_OP_LINKLOCAL &&
ls_type <= OSPF_LSTYPE_OP_ASWIDE)
return OSPF_LSTYPE_OP_BASE;
else
return -1;
}
static gint ospf_v3_ls_type_to_filter (guint16 ls_type)
{
guint16 function_code;
function_code = ls_type & 0x1fff;
if (function_code >= OSPF_V3_LSA_FUNCTION_CODE_ROUTER &&
function_code <= OSPF_V3_LSA_FUNCTION_CODE_INTRA_AREA_PREFIX)
return function_code - OSPF_V3_LSA_FUNCTION_CODE_BASE;
else if (function_code == OSPF_V3_LSA_FUNCTION_CODE_OPAQUE_RI)
return OSPF_V3_LSA_FUNCTION_CODE_OPAQUE_RI_BASE;
else
return -1;
}
static void
dissect_ospf_bitfield (proto_tree *parent_tree, tvbuff_t *tvb, int offset,
bitfield_info *bfinfo)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
char *str;
gint length, pos;
gint i;
header_field_info *hfinfo;
int hfindex, idx;
gint returned_length;
hfindex = *(bfinfo->hfindex);
hfinfo = proto_registrar_get_nth(hfindex);
switch (hfinfo->type) {
case FT_UINT8:
flags = tvb_get_guint8(tvb, offset);
length = 1;
break;
case FT_UINT16:
flags = tvb_get_ntohs(tvb, offset);
length = 2;
break;
case FT_UINT24:
flags = tvb_get_ntoh24(tvb, offset);
length = 3;
break;
case FT_UINT32:
flags = tvb_get_ntohl(tvb, offset);
length = 4;
break;
default:
return;
}
if (parent_tree) {
item = proto_tree_add_uint(parent_tree, hfindex, tvb, offset, length, flags);
tree = proto_item_add_subtree(item, *bfinfo->ett);
str = (char *)wmem_alloc(wmem_packet_scope(), MAX_OPTIONS_LEN);
str[0] = 0;
for (i = 0, pos = 0; i < bfinfo->num; i++) {
idx = *(bfinfo->idx[i]);
hfinfo = proto_registrar_get_nth(idx);
if (flags & hfinfo->bitmask) {
returned_length = g_snprintf(&str[pos], MAX_OPTIONS_LEN-pos, "%s%s",
pos ? ", " : "",
hfinfo->name);
pos += MIN(returned_length, MAX_OPTIONS_LEN-pos);
}
proto_tree_add_boolean(tree, idx, tvb, offset, length, flags);
}
if (str[0]) {
proto_item_append_text(item, " (%s)", str);
}
}
}
static int
ospf_has_lls_block(tvbuff_t *tvb, int offset, guint8 packet_type, guint8 version)
{
guint8 flags;
guint32 v3flags;
switch (packet_type) {
case OSPF_HELLO:
switch (version) {
case OSPF_VERSION_2:
flags = tvb_get_guint8 (tvb, offset + 6);
return flags & OSPF_V2_OPTIONS_L;
case OSPF_VERSION_3:
v3flags = tvb_get_ntohl(tvb, offset + 5);
v3flags = v3flags >> 8;
return v3flags & OSPF_V3_OPTIONS_L;
}
break;
case OSPF_DB_DESC:
switch (version) {
case OSPF_VERSION_2:
flags = tvb_get_guint8 (tvb, offset + 2);
return flags & OSPF_V2_OPTIONS_L;
case OSPF_VERSION_3:
v3flags = tvb_get_ntohl(tvb, offset + 1);
v3flags = v3flags >> 8;
return v3flags & OSPF_V3_OPTIONS_L;
}
break;
}
return 0;
}
static int
ospf_has_at_block(tvbuff_t *tvb, int offset, guint8 packet_type, guint8 version)
{
guint32 v3flags;
switch (packet_type) {
case OSPF_HELLO:
switch (version) {
case OSPF_VERSION_3:
v3flags = tvb_get_ntohl(tvb, offset + 5);
v3flags = v3flags >> 8;
return v3flags & OSPF_V3_OPTIONS_AT;
}
}
return 0;
}
static gboolean
capture_ospf(const guchar *pd _U_, int offset _U_, int len _U_, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
capture_dissector_increment_count(cpinfo, proto_ospf);
return TRUE;
}
static int
dissect_ospf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ospf_tree = NULL;
proto_item *ti, *ti_sum, *hidden_item;
proto_tree *ospf_header_tree;
guint8 version;
guint8 packet_type;
guint16 ospflen;
vec_t cksum_vec[4];
int cksum_vec_len;
guint32 phdr[2];
guint16 cksum, computed_cksum;
guint length, reported_length;
guint16 auth_type;
int crypto_len = 0;
unsigned int ospf_header_length;
guint8 instance_id;
guint32 areaid;
guint8 address_family = OSPF_AF_6;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OSPF");
col_clear(pinfo->cinfo, COL_INFO);
version = tvb_get_guint8(tvb, 0);
switch (version) {
case OSPF_VERSION_2:
ospf_header_length = OSPF_VERSION_2_HEADER_LENGTH;
break;
case OSPF_VERSION_3:
ospf_header_length = OSPF_VERSION_3_HEADER_LENGTH;
break;
default:
ospf_header_length = 14;
break;
}
packet_type = tvb_get_guint8(tvb, 1);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, pt_vals, "Unknown (%u)"));
ospflen = tvb_get_ntohs(tvb, 2);
ti = proto_tree_add_item(tree, proto_ospf, tvb, 0, -1, ENC_NA);
ospf_tree = proto_item_add_subtree(ti, ett_ospf);
ti = proto_tree_add_item(ospf_tree, hf_ospf_header, tvb, 0, ospf_header_length, ENC_NA);
ospf_header_tree = proto_item_add_subtree(ti, ett_ospf_hdr);
proto_tree_add_item(ospf_header_tree, hf_ospf_header_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_header_tree, hf_ospf_header_msg_type, tvb, 1, 1, ENC_BIG_ENDIAN);
if (ospf_msg_type_to_filter(packet_type) != -1) {
hidden_item = proto_tree_add_item(ospf_header_tree,
*hf_ospf_msg_type_array[ospf_msg_type_to_filter(packet_type)],
tvb, 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_item(ospf_header_tree, hf_ospf_header_packet_length, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_header_tree, hf_ospf_header_src_router, tvb, 4, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(ospf_header_tree, hf_ospf_header_area_id, tvb, 8, 4, ENC_BIG_ENDIAN);
areaid = tvb_get_ntohl(tvb,8);
if(areaid == 0){
proto_item_append_text(ti, " (Backbone)");
}
ti_sum = proto_tree_add_item(ospf_header_tree, hf_ospf_header_checksum, tvb, 12, 2, ENC_BIG_ENDIAN);
cksum = tvb_get_ntohs(tvb, 12);
if(cksum == 0){
proto_item_append_text(ti_sum, " (None)");
}
if(version != OSPF_VERSION_2 && version != OSPF_VERSION_3) {
return 12;
}
length = tvb_captured_length(tvb);
reported_length = tvb_reported_length(tvb);
if (cksum !=0 && !pinfo->fragmented && length >= reported_length
&& length >= ospf_header_length) {
switch (version) {
case OSPF_VERSION_2:
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, 16);
if (length > ospf_header_length) {
reported_length -= ospf_header_length;
SET_CKSUM_VEC_TVB(cksum_vec[1], tvb, ospf_header_length, reported_length);
cksum_vec_len = 2;
} else {
cksum_vec_len = 1;
}
break;
case OSPF_VERSION_3:
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
phdr[0] = g_htonl(ospflen);
phdr[1] = g_htonl(IP_PROTO_OSPF);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 8);
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, reported_length);
cksum_vec_len = 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
computed_cksum = in_cksum(cksum_vec, cksum_vec_len);
if (computed_cksum == 0) {
proto_item_append_text(ti_sum, " [correct]");
} else {
proto_item_append_text(ti_sum, " [incorrect, should be 0x%04x]", in_cksum_shouldbe(cksum, computed_cksum));
}
}
switch (version) {
case OSPF_VERSION_2:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_type, tvb, 14, 2, ENC_BIG_ENDIAN);
auth_type = tvb_get_ntohs(tvb, 14);
switch (auth_type) {
case OSPF_AUTH_NONE:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_data_none, tvb, 16, 8, ENC_NA);
break;
case OSPF_AUTH_SIMPLE:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_data_simple, tvb, 16, 8, ENC_ASCII|ENC_NA);
break;
case OSPF_AUTH_CRYPT:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_crypt_key_id, tvb, 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_crypt_data_length, tvb, 19, 1, ENC_BIG_ENDIAN);
crypto_len = tvb_get_guint8(tvb, 19);
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_crypt_seq_nbr, tvb, 20, 4, ENC_BIG_ENDIAN);
if (tvb_bytes_exist(tvb, ospflen, crypto_len)) {
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_crypt_data, tvb, ospflen, crypto_len, ENC_NA);
proto_tree_set_appendix(ospf_header_tree, tvb, ospflen, crypto_len);
}
break;
default:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_auth_data_unknown, tvb, 16, 8, ENC_NA);
break;
}
break;
case OSPF_VERSION_3:
proto_tree_add_item(ospf_header_tree, hf_ospf_header_instance_id, tvb, 14, 1, ENC_BIG_ENDIAN);
instance_id = tvb_get_guint8(tvb, 14);
address_family = OSPF_AF_6;
if(instance_id > 65 && instance_id < 128) {
address_family = OSPF_AF_4;
}
ti = proto_tree_add_item(ospf_header_tree, hf_ospf_header_reserved, tvb, 15, 1, ENC_NA);
if(tvb_get_guint8(tvb, 15)){
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
switch (packet_type){
case OSPF_HELLO:
dissect_ospf_hello(tvb, ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length));
break;
case OSPF_DB_DESC:
dissect_ospf_db_desc(tvb, pinfo, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
case OSPF_LS_REQ:
dissect_ospf_ls_req(tvb, pinfo, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length));
break;
case OSPF_LS_UPD:
dissect_ospf_ls_upd(tvb, pinfo, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
case OSPF_LS_ACK:
dissect_ospf_ls_ack(tvb, pinfo, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
default:
call_data_dissector(tvb_new_subset_remaining(tvb, ospf_header_length), pinfo, tree);
break;
}
if (ospf_has_lls_block(tvb, ospf_header_length, packet_type, version)) {
dissect_ospf_lls_data_block(tvb, pinfo, ospflen + crypto_len, ospf_tree,
version);
}
if (ospf_has_at_block(tvb, ospf_header_length, packet_type, version)) {
dissect_ospf_authentication_trailer(tvb, ospflen + crypto_len, ospf_tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_ospfv2_lls_tlv(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree *ospf_lls_tlv_tree;
guint16 type;
guint16 length;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
ospf_lls_tlv_tree = proto_tree_add_subtree(tree, tvb, offset, length + 4, ett_ospf_lls_tlv,
NULL, val_to_str_const(type, lls_tlv_type_vals, "Unknown LLS TLV"));
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_tlv_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch(type) {
case 1:
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 4, &bfinfo_lls_ext_options);
break;
case 2:
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v2_lls_sequence_number, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v2_lls_auth_data, tvb, offset + 8, length - 4, ENC_NA);
break;
}
return offset + length + 4;
}
static int
dissect_ospfv3_lls_tlv(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *ospf_lls_tlv_tree = NULL;
guint16 type;
guint16 length;
guint8 relays_added;
int orig_offset;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
switch(type) {
case LLS_V3_EXT_OPT:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_ext_options_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_STATE_CHECK:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_state_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_NBR_DROP:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_drop_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_RELAYS:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_relay_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_WILLING:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_willingness_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_RQST_FROM:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_rf_tlv, tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_FULL_STATE:
ti = proto_tree_add_item(tree, hf_ospf_v3_lls_fsf_tlv, tvb,
offset, length + 4, ENC_NA);
break;
default:
ospf_lls_tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, length + 4, ett_ospf_lls_tlv, NULL,
"%s", val_to_str_const(type, lls_v3_tlv_type_vals, "Unknown LLS TLV"));
}
if (ti != NULL)
ospf_lls_tlv_tree = proto_item_add_subtree(ti, ett_ospf_lls_tlv);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_tlv_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
orig_offset = offset;
switch (type) {
case LLS_V3_EXT_OPT:
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_extended_options, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 4, &bfinfo_v3_lls_ext_options);
break;
case LLS_V3_STATE_CHECK:
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_state_scs,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 6,
&bfinfo_v3_lls_state_options);
break;
case LLS_V3_NBR_DROP:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_dropped_neighbor, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
offset = orig_offset;
break;
case LLS_V3_RELAYS:
relays_added = tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_relay_added,
tvb, offset+4, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 5,
&bfinfo_v3_lls_relay_options);
offset += 8;
while (orig_offset + length >= offset) {
ti = proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_neighbor, tvb, offset, 4, ENC_BIG_ENDIAN);
if (relays_added > 0) {
proto_item_append_text(ti, " Added");
} else {
proto_item_append_text(ti, " Deleted");
}
relays_added--;
offset += 4;
}
break;
case LLS_V3_WILLING:
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_willingness,
tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
case LLS_V3_RQST_FROM:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_request_from, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
offset = orig_offset;
break;
case LLS_V3_FULL_STATE:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_v3_lls_full_state_for, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
offset = orig_offset;
break;
}
return offset + length + 4;
}
static void
dissect_ospf_lls_data_block(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
guint8 version)
{
proto_tree *ospf_lls_data_block_tree;
int ospf_lls_len;
int orig_offset = offset;
guint length_remaining;
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (length_remaining < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_ospf_lsa_bad_length,
tvb, offset, length_remaining, "LLS option bit set but data block missing");
return;
}
ospf_lls_len = tvb_get_ntohs(tvb, offset + 2) * 4;
ospf_lls_data_block_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_ospf_lls_data_block, NULL, "OSPF LLS Data Block");
proto_tree_add_checksum(ospf_lls_data_block_tree, tvb, offset, hf_ospf_lls_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
proto_tree_add_uint(ospf_lls_data_block_tree, hf_ospf_lls_data_length, tvb, offset + 2, 2, ospf_lls_len);
offset += 4;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + ospf_lls_len > offset) {
if (version == OSPF_VERSION_2)
offset = dissect_ospfv2_lls_tlv (tvb, offset, ospf_lls_data_block_tree);
else
offset = dissect_ospfv3_lls_tlv (tvb, offset, ospf_lls_data_block_tree);
}
}
static int
dissect_ospf_authentication_trailer(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree *ospf_at_tree;
proto_item *ti;
guint32 auth_data_len;
ti = proto_tree_add_item(tree, hf_ospf_at, tvb, offset, -1, ENC_NA);
ospf_at_tree = proto_item_add_subtree(ti, ett_ospf_at);
proto_tree_add_item(ospf_at_tree, hf_ospf_at_auth_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item_ret_uint(ospf_at_tree, hf_ospf_at_auth_data_len, tvb, offset, 2, ENC_BIG_ENDIAN, &auth_data_len);
offset += 2;
if (auth_data_len < (2 + 2 + 2 + 8)) {
proto_item_set_len(ti, 4);
return offset;
}
proto_item_set_len(ti, auth_data_len);
proto_tree_add_item(ospf_at_tree, hf_ospf_at_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ospf_at_tree, hf_ospf_at_sa_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ospf_at_tree, hf_ospf_at_crypto_seq_nbr, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ospf_at_tree, hf_ospf_at_auth_data, tvb, offset, auth_data_len - ( 2 + 2 + 2 + 2 + 8), ENC_NA);
offset = auth_data_len;
return offset;
}
static void
dissect_ospf_hello(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 version,
guint16 length)
{
proto_tree *ospf_hello_tree;
proto_item *ti;
int orig_offset = offset;
ti = proto_tree_add_item(tree, hf_ospf_hello, tvb, offset, length, ENC_NA);
ospf_hello_tree = proto_item_add_subtree(ti, ett_ospf_hello);
switch (version) {
case OSPF_VERSION_2:
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_network_mask, tvb, offset, 4, ENC_NA);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_hello_interval, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_hello_tree, tvb, offset + 6, &bfinfo_v2_options);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_router_priority, tvb, offset + 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_router_dead_interval, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_designated_router, tvb, offset + 12, 4, ENC_NA);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_backup_designated_router, tvb, offset + 16, 4, ENC_NA);
offset += 20;
while (orig_offset + length > offset) {
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_active_neighbor, tvb, offset, 4, ENC_NA);
offset += 4;
}
break;
case OSPF_VERSION_3:
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_interface_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_router_priority, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_hello_tree, tvb, offset + 5, &bfinfo_v3_options);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_hello_interval, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_router_dead_interval, tvb, offset + 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_designated_router, tvb, offset + 12, 4, ENC_NA);
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_backup_designated_router, tvb, offset + 16, 4, ENC_NA);
offset += 20;
while (orig_offset + length > offset) {
proto_tree_add_item(ospf_hello_tree, hf_ospf_hello_active_neighbor, tvb, offset, 4, ENC_NA);
offset += 4;
}
break;
}
}
static void
dissect_ospf_db_desc(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
guint8 version, guint16 length, guint8 address_family)
{
proto_tree *ospf_db_desc_tree;
proto_item *ti;
guint8 reserved;
int orig_offset = offset;
if (tree) {
ospf_db_desc_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_ospf_desc, NULL, "OSPF DB Description");
switch (version ) {
case OSPF_VERSION_2:
proto_tree_add_item(ospf_db_desc_tree, hf_ospf_db_interface_mtu, tvb, offset, 2, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 2, &bfinfo_v2_options);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 3, &bfinfo_dbd);
proto_tree_add_item(ospf_db_desc_tree, hf_ospf_db_dd_sequence, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case OSPF_VERSION_3:
reserved = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(ospf_db_desc_tree, hf_ospf_header_reserved, tvb, offset, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 1, &bfinfo_v3_options);
proto_tree_add_item(ospf_db_desc_tree, hf_ospf_db_interface_mtu, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
reserved = tvb_get_guint8(tvb, offset + 6);
ti = proto_tree_add_item(ospf_db_desc_tree, hf_ospf_header_reserved, tvb, offset + 6, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 7, &bfinfo_dbd);
proto_tree_add_item(ospf_db_desc_tree, hf_ospf_db_dd_sequence, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
break;
}
}
switch (version ) {
case OSPF_VERSION_2:
offset += 8;
break;
case OSPF_VERSION_3:
offset += 12;
break;
}
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + length > offset) {
if ( version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, pinfo, offset, tree, FALSE);
else
offset = dissect_ospf_v3_lsa(tvb, pinfo, offset, tree, FALSE, address_family);
}
}
static void
dissect_ospf_ls_req(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, guint8 version,
guint16 length)
{
proto_item *ti;
proto_tree *ospf_lsr_tree;
guint16 reserved;
int orig_offset = offset;
while (orig_offset + length > offset) {
ospf_lsr_tree = proto_tree_add_subtree(tree, tvb, offset, OSPF_LS_REQ_LENGTH,
ett_ospf_lsr, NULL, "Link State Request");
switch ( version ) {
case OSPF_VERSION_2:
proto_tree_add_item(ospf_lsr_tree, hf_ospf_ls_type,
tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case OSPF_VERSION_3:
reserved = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(ospf_lsr_tree, hf_ospf_header_reserved, tvb, offset, 2, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
proto_tree_add_item(ospf_lsr_tree, hf_ospf_v3_ls_type,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(ospf_lsr_tree, hf_ospf_link_state_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsr_tree, hf_ospf_adv_router,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
offset += 12;
}
}
static void
dissect_ospf_ls_upd(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, guint8 version,
guint16 length, guint8 address_family)
{
proto_tree *ospf_lsa_upd_tree;
guint32 lsa_nr;
guint32 lsa_counter;
ospf_lsa_upd_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_ospf_lsa_upd, NULL, "LS Update Packet");
lsa_nr = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(ospf_lsa_upd_tree, hf_ospf_ls_number_of_lsas, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
lsa_counter = 0;
while (lsa_counter < lsa_nr) {
if (version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, pinfo, offset, ospf_lsa_upd_tree, TRUE);
else
offset = dissect_ospf_v3_lsa(tvb, pinfo, offset, ospf_lsa_upd_tree, TRUE,
address_family);
lsa_counter += 1;
}
}
static void
dissect_ospf_ls_ack(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, guint8 version,
guint16 length, guint8 address_family)
{
int orig_offset = offset;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + length > offset) {
if (version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, pinfo, offset, tree, FALSE);
else
offset = dissect_ospf_v3_lsa(tvb, pinfo, offset, tree, FALSE, address_family);
}
}
static int
is_opaque(int lsa_type)
{
return (lsa_type >= OSPF_LSTYPE_OP_LINKLOCAL &&
lsa_type <= OSPF_LSTYPE_OP_ASWIDE);
}
static void
dissect_ospf_lsa_mpls(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
guint32 length)
{
proto_item *ti, *hidden_item;
proto_tree *mpls_tree;
proto_tree *tlv_tree;
proto_tree *stlv_tree;
proto_tree *stlv_admingrp_tree = NULL;
int tlv_type;
int tlv_length;
int tlv_end_offset;
int stlv_type, stlv_len, stlv_offset;
const char *stlv_name;
guint32 stlv_admingrp, mask;
int i;
guint8 switch_cap;
float tmp_float;
const guint8 allzero[] = { 0x00, 0x00, 0x00 };
guint num_bcs = 0;
mpls_tree = proto_tree_add_subtree(tree, tvb, offset, length,
ett_ospf_lsa_mpls, NULL, "MPLS Traffic Engineering LSA");
hidden_item = proto_tree_add_item(tree, hf_ospf_ls_mpls,
tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
while (length != 0) {
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_end_offset = offset + tlv_length + 4;
switch (tlv_type) {
case MPLS_TLV_ROUTER:
tlv_tree = proto_tree_add_subtree_format(mpls_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_mpls_router, NULL, "Router Address: %s",
tvb_ip_to_str(tvb, offset+4));
proto_tree_add_uint_format_value(tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, tlv_type, "1 - Router Address");
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_ls_mpls_routerid,
tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case MPLS_TLV_LINK:
tlv_tree = proto_tree_add_subtree(mpls_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_mpls_link, NULL, "Link Information");
proto_tree_add_uint_format_value(tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, tlv_type, "2 - Link Information");
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
stlv_offset = offset + 4;
while (stlv_offset < tlv_end_offset) {
stlv_type = tvb_get_ntohs(tvb, stlv_offset);
stlv_len = tvb_get_ntohs(tvb, stlv_offset + 2);
stlv_name = val_to_str_const(stlv_type, mpls_link_stlv_str, "Unknown sub-TLV");
switch (stlv_type) {
case MPLS_LINK_TYPE:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %u - %s", stlv_name,
tvb_get_guint8(tvb, stlv_offset + 4),
val_to_str_const(tvb_get_guint8(tvb, stlv_offset + 4),
mpls_link_stlv_ltype_str, "Unknown Link Type"));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_ls_mpls_linktype,
tvb, stlv_offset+4, 1,ENC_BIG_ENDIAN);
break;
case MPLS_LINK_ID:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_ls_mpls_linkid,
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_LOCAL_IF:
case MPLS_LINK_REMOTE_IF:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
for (i=0; i < stlv_len; i+=4)
proto_tree_add_item(stlv_tree,
stlv_type==MPLS_LINK_LOCAL_IF ?
hf_ospf_ls_mpls_local_addr :
hf_ospf_ls_mpls_remote_addr,
tvb, stlv_offset+4+i, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_TE_METRIC:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %u", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(stlv_tree, hf_ospf_ls_mpls_te_metric, tvb, stlv_offset+4, 4,
tvb_get_ntohl(tvb, stlv_offset + 4), "%s: %u", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
break;
case MPLS_LINK_COLOR:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: 0x%08x", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
stlv_admingrp = tvb_get_ntohl(tvb, stlv_offset + 4);
mask = 1;
ti = proto_tree_add_item(stlv_tree, hf_ospf_ls_mpls_linkcolor,
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
stlv_admingrp_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv_admingrp);
if (stlv_admingrp_tree == NULL)
return;
for (i = 0 ; i < 32 ; i++) {
if ((stlv_admingrp & mask) != 0) {
proto_tree_add_uint_format(stlv_admingrp_tree, hf_ospf_ls_mpls_group, tvb, stlv_offset+4,
4, 1 << i, "Group %d", i);
}
mask <<= 1;
}
break;
case MPLS_LINK_MAX_BW:
case MPLS_LINK_MAX_RES_BW:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %.10g bytes/s (%.0f bits/s)", stlv_name,
tvb_get_ntohieee_float(tvb, stlv_offset + 4),
tvb_get_ntohieee_float(tvb, stlv_offset + 4) * 8.0);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_float_format(stlv_tree, hf_ospf_ls_mpls_link_max_bw, tvb, stlv_offset+4, 4,
tvb_get_ntohieee_float(tvb, stlv_offset + 4), "%s: %.10g bytes/s (%.0f bits/s)", stlv_name,
tvb_get_ntohieee_float(tvb, stlv_offset + 4),
tvb_get_ntohieee_float(tvb, stlv_offset + 4) * 8.0);
break;
case MPLS_LINK_UNRES_BW:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
for (i = 0; i < 8; i++) {
tmp_float = tvb_get_ntohieee_float(tvb, stlv_offset + 4 + i*4);
proto_tree_add_float_format(stlv_tree, hf_ospf_ls_mpls_pri, tvb, stlv_offset+4+(i*4), 4,
tmp_float, "Pri (or TE-Class) %d: %.10g bytes/s (%.0f bits/s)", i,
tmp_float, tmp_float * 8.0);
}
break;
case MPLS_LINK_BANDWIDTH_CONSTRAINT:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_ls_mpls_bc_model_id,
tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
if(tvb_memeql(tvb, stlv_offset+5, allzero, 3) == -1) {
proto_tree_add_expert_format(stlv_tree, pinfo, &ei_ospf_header_reserved,
tvb, stlv_offset+5, 3,
"These bytes are reserved and must be 0x00");
}
if(((stlv_len % 4)!=0)) {
proto_tree_add_expert_format(stlv_tree, pinfo, &ei_ospf_lsa_bad_length, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: Length must be N x 4 octets");
break;
}
num_bcs = (stlv_len - 4)/4;
if(num_bcs>8) {
proto_tree_add_expert_format(stlv_tree, pinfo, &ei_ospf_lsa_bc_error, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: too many BC (%u)", num_bcs);
break;
}
if(num_bcs==0) {
proto_tree_add_expert_format(stlv_tree, pinfo, &ei_ospf_lsa_bc_error, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: Bandwidth Constraints sub-TLV with no BC?");
break;
}
for(i = 0; i < (int) num_bcs; i++) {
tmp_float = tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4);
proto_tree_add_float_format(stlv_tree, hf_ospf_ls_mpls_bc, tvb, stlv_offset+8+(i*4), 4,
tmp_float, "BC %d: %.10g bytes/s (%.0f bits/s)", i,
tmp_float, tmp_float * 8.0);
}
break;
case MPLS_LINK_LOCAL_REMOTE_ID:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %d (0x%x) - %d (0x%x)", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4),
tvb_get_ntohl(tvb, stlv_offset + 4),
tvb_get_ntohl(tvb, stlv_offset + 8),
tvb_get_ntohl(tvb, stlv_offset + 8));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree,
hf_ospf_ls_mpls_local_ifid,
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree,
hf_ospf_ls_mpls_remote_ifid,
tvb, stlv_offset+8, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_IF_SWITCHING_DESC:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
switch_cap = tvb_get_guint8 (tvb, stlv_offset+4);
proto_tree_add_item(stlv_tree, hf_ospf_mpls_switching_type, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_mpls_encoding, tvb, stlv_offset+5, 1, ENC_BIG_ENDIAN);
for (i = 0; i < 8; i++) {
tmp_float = tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4);
proto_tree_add_float_format(stlv_tree, hf_ospf_ls_mpls_pri, tvb, stlv_offset+8+(i*4), 4,
tmp_float, "Pri %d: %.10g bytes/s (%.0f bits/s)", i,
tmp_float, tmp_float * 8.0);
}
if (switch_cap >=1 && switch_cap <=4) {
tmp_float = tvb_get_ntohieee_float(tvb, stlv_offset + 40);
proto_tree_add_float_format_value(stlv_tree, hf_ospf_mpls_minimum_lsp_bandwidth, tvb, stlv_offset+40, 4,
tmp_float, "%.10g bytes/s (%.0f bits/s)",
tmp_float, tmp_float * 8.0);
proto_tree_add_item(stlv_tree, hf_ospf_mpls_interface_mtu, tvb, stlv_offset+44, 2, ENC_BIG_ENDIAN);
}
if (switch_cap == 100) {
tmp_float = tvb_get_ntohieee_float(tvb, stlv_offset + 40);
proto_tree_add_float_format_value(stlv_tree, hf_ospf_mpls_minimum_lsp_bandwidth, tvb, stlv_offset+40, 4,
tmp_float, "%.10g bytes/s (%.0f bits/s)",
tmp_float, tmp_float * 8.0);
proto_tree_add_item(stlv_tree, hf_ospf_mpls_sonet_sdh, tvb, stlv_offset+44, 1, ENC_NA);
}
break;
case MPLS_LINK_PROTECTION:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_mpls_protection_capability, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_SHARED_RISK_GROUP:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
for (i=0; i < stlv_len; i+=4)
proto_tree_add_item(stlv_tree, hf_ospf_mpls_shared_risk_link_group, tvb, stlv_offset+4+i, 4, ENC_BIG_ENDIAN);
break;
case OIF_LOCAL_NODE_ID:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree,
hf_ospf_ls_oif_local_node_id,
tvb, stlv_offset + 4, 4, ENC_BIG_ENDIAN);
break;
case OIF_REMOTE_NODE_ID:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree,
hf_ospf_ls_oif_remote_node_id,
tvb, stlv_offset + 4, 4, ENC_BIG_ENDIAN);
break;
case OIF_SONET_SDH_SWITCHING_CAPABILITY:
stlv_tree = proto_tree_add_subtree(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, stlv_name);
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_switching_cap, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_encoding, tvb, stlv_offset+5, 1, ENC_BIG_ENDIAN);
for (i = 0; i < (stlv_len - 4) / 4; i++) {
proto_tree_add_uint_format(stlv_tree, hf_ospf_oif_signal_type, tvb, stlv_offset+8+(i*4), 4,
tvb_get_guint8(tvb, stlv_offset+8+(i*4)), "%s: %d free timeslots",
val_to_str_ext(tvb_get_guint8(tvb, stlv_offset+8+(i*4)),
&gmpls_sonet_signal_type_str_ext,
"Unknown Signal Type (%d)"),
tvb_get_ntoh24(tvb, stlv_offset + 9 + i*4));
}
break;
default:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_mpls_link_stlv, NULL, "Unknown Link sub-TLV: %u %s", stlv_type,
rval_to_str(stlv_type, mpls_te_sub_tlv_rvals, "Unknown"));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s %s", stlv_type, stlv_name,
rval_to_str(stlv_type, mpls_te_sub_tlv_rvals, "Unknown"));
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_value, tvb, stlv_offset+4, stlv_len, ENC_NA);
break;
}
stlv_offset += ((stlv_len+4+3)/4)*4;
}
break;
case OIF_TLV_TNA:
tlv_tree = proto_tree_add_subtree(mpls_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_oif_tna, NULL, "TNA Information");
proto_tree_add_uint_format_value(tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, 32768, "32768 - TNA Information");
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
stlv_offset = offset + 4;
while (stlv_offset < tlv_end_offset) {
stlv_type = tvb_get_ntohs(tvb, stlv_offset);
stlv_len = tvb_get_ntohs(tvb, stlv_offset + 2);
stlv_name = val_to_str_const(stlv_type, oif_stlv_str, "Unknown sub-TLV");
switch (stlv_type) {
case OIF_NODE_ID:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_oif_tna_stlv, NULL, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_ipv4_format(stlv_tree, hf_ospf_oif_node_id, tvb, stlv_offset+4, 4,
tvb_get_ntohl(tvb, stlv_offset + 4), "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
break;
case OIF_TNA_IPv4_ADDRESS:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_oif_tna_stlv, NULL, "%s (IPv4): %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 8));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s (IPv4)", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_tna_addr_length, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_tna_addr_ipv4, tvb, stlv_offset+8, stlv_len - 4, ENC_BIG_ENDIAN);
break;
case OIF_TNA_IPv6_ADDRESS:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_oif_tna_stlv, NULL, "%s (IPv6): %s", stlv_name,
tvb_ip6_to_str(tvb, stlv_offset + 8));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s (IPv6)", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_tna_addr_length, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_tna_addr_ipv6, tvb, stlv_offset+8, stlv_len - 4, ENC_NA);
break;
case OIF_TNA_NSAP_ADDRESS:
stlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, stlv_offset, stlv_len+4,
ett_ospf_lsa_oif_tna_stlv, NULL, "%s (NSAP): %s", stlv_name,
tvb_bytes_to_str(wmem_packet_scope(), tvb, stlv_offset + 8, stlv_len - 4));
proto_tree_add_uint_format_value(stlv_tree, hf_ospf_tlv_type, tvb, stlv_offset, 2,
stlv_type, "%u: %s (NSAP)", stlv_type, stlv_name);
proto_tree_add_item(stlv_tree, hf_ospf_tlv_length, tvb, stlv_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_oif_tna_addr_length, tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree, hf_ospf_tna_addr, tvb, stlv_offset+8, stlv_len - 4, ENC_NA);
break;
default:
proto_tree_add_expert_format(tlv_tree, pinfo, &ei_ospf_unknown_link_subtype, tvb, stlv_offset, stlv_len+4,
"Unknown Link sub-TLV: %u", stlv_type);
break;
}
stlv_offset += ((stlv_len+4+3)/4)*4;
}
break;
default:
tlv_tree = proto_tree_add_subtree_format(mpls_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_mpls_link, NULL, "Unknown LSA: %u %s", tlv_type,
rval_to_str(tlv_type, mpls_te_tlv_rvals, "Unknown"));
proto_tree_add_uint_format_value(tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, tlv_type, "%u - Unknown %s",
tlv_type, rval_to_str(tlv_type, mpls_te_tlv_rvals, "Unknown"));
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_value, tvb, offset+4, tlv_length, ENC_NA);
break;
}
offset += tlv_length + 4;
length -= tlv_length + 4;
}
}
static void dissect_ospf_lsa_grace_tlv (tvbuff_t *tvb, int offset,
proto_tree *tree, guint32 length)
{
guint16 tlv_type;
guint16 tlv_length;
int tlv_length_with_pad;
guint32 grace_period;
guint8 restart_reason;
proto_tree *tlv_tree;
proto_item *tree_item;
proto_item *grace_tree_item;
if (!tree) { return; }
while (length > 0)
{
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_length_with_pad = tlv_length + 4 + ((4 - (tlv_length % 4)) % 4);
tree_item = proto_tree_add_item(tree, hf_ospf_v2_grace_tlv, tvb, offset,
tlv_length_with_pad, ENC_NA);
tlv_tree = proto_item_add_subtree(tree_item, ett_ospf_lsa_grace_tlv);
proto_tree_add_uint_format_value(tlv_tree, hf_ospf_tlv_type, tvb, offset, 2, tlv_type, "%s (%u)",
val_to_str_const(tlv_type, grace_tlv_type_vals, "Unknown grace-LSA TLV"), tlv_type);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch (tlv_type) {
case GRACE_TLV_PERIOD:
grace_period = tvb_get_ntohl(tvb, offset + 4);
grace_tree_item = proto_tree_add_item(tlv_tree, hf_ospf_v2_grace_period, tvb,
offset + 4, tlv_length, ENC_BIG_ENDIAN);
proto_item_append_text(grace_tree_item, " seconds");
proto_item_set_text(tree_item, "Grace Period: %u seconds", grace_period);
break;
case GRACE_TLV_REASON:
restart_reason = tvb_get_guint8(tvb, offset + 4);
proto_tree_add_item(tlv_tree, hf_ospf_v2_grace_reason, tvb, offset + 4,
tlv_length, ENC_BIG_ENDIAN);
proto_item_set_text(tree_item, "Restart Reason: %s (%u)",
val_to_str_const(restart_reason, restart_reason_vals, "Unknown Restart Reason"),
restart_reason);
break;
case GRACE_TLV_IP:
proto_tree_add_item(tlv_tree, hf_ospf_v2_grace_ip, tvb, offset + 4,
tlv_length, ENC_BIG_ENDIAN);
proto_item_set_text(tree_item, "Restart IP: %s",
tvb_address_with_resolution_to_str(wmem_packet_scope(), tvb, AT_IPv4, offset + 4));
break;
default:
proto_item_set_text(tree_item, "Unknown grace-LSA TLV");
break;
}
if (4 + tlv_length < tlv_length_with_pad) {
proto_tree_add_item(tlv_tree, hf_ospf_pad_bytes, tvb, offset + 4 + tlv_length, tlv_length_with_pad - (4 + tlv_length), ENC_NA);
}
offset += tlv_length_with_pad;
length -= tlv_length_with_pad;
}
}
static void
dissect_ospf_lsa_opaque_ri(tvbuff_t *tvb, int offset, proto_tree *tree,
guint32 length)
{
proto_tree *ri_tree;
proto_tree *tlv_tree;
int tlv_type;
int tlv_length;
ri_tree = proto_tree_add_subtree(tree, tvb, offset, length,
ett_ospf_lsa_opaque_ri, NULL, "Opaque Router Information LSA");
while (length > 0) {
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
switch(tlv_type) {
case OPAQUE_TLV_RI:
tlv_tree = proto_tree_add_subtree_format(ri_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_ri_tlv, NULL, "%s", val_to_str_const(tlv_type, ri_tlv_type_vals, "Unknown Opaque RI LSA TLV"));
proto_tree_add_item(tlv_tree, hf_ospf_tlv_type_opaque, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(tlv_tree, tvb, offset + 4, &bfinfo_ri_options);
break;
case OPAQUE_TLV_DH:
tlv_tree = proto_tree_add_subtree_format(ri_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_dh_tlv, NULL, "%s", val_to_str_const(tlv_type, ri_tlv_type_vals, "Unknown Opaque RI LSA TLV"));
proto_tree_add_item(tlv_tree, hf_ospf_tlv_type_opaque, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_dyn_hostname, tvb, offset+4, tlv_length, ENC_ASCII|ENC_NA);
break;
case OPAQUE_TLV_SA:{
int sa_number;
tlv_tree = proto_tree_add_subtree_format(ri_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_sa_tlv, NULL, "%s", val_to_str_const(tlv_type, ri_tlv_type_vals, "Unknown Opaque RI LSA TLV"));
proto_tree_add_item(tlv_tree, hf_ospf_tlv_type_opaque, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
for(sa_number = 0; sa_number < tlv_length; sa_number++){
proto_tree_add_item(tlv_tree, hf_ospf_lsa_sa, tvb, offset+sa_number+4, 1, ENC_ASCII|ENC_NA);
}
break;
}
default:
tlv_tree = proto_tree_add_subtree_format(ri_tree, tvb, offset, tlv_length+4,
ett_ospf_lsa_unknown_tlv, NULL, "%s", val_to_str_const(tlv_type, ri_tlv_type_vals, "Unknown Opaque RI LSA TLV"));
proto_tree_add_item(tlv_tree, hf_ospf_tlv_type_opaque, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_tlv_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ospf_unknown_tlv, tvb, offset+4, tlv_length, ENC_NA);
break;
}
offset += tlv_length + 4;
length -= tlv_length + 4;
}
}
static void
dissect_ospf_lsa_opaque(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
guint8 ls_id_type, guint32 length)
{
switch (ls_id_type) {
case OSPF_LSA_MPLS_TE:
dissect_ospf_lsa_mpls(tvb, pinfo, offset, tree, length);
break;
case OSPF_LSA_OPAQUE_RI:
dissect_ospf_lsa_opaque_ri(tvb, offset, tree, length);
break;
case OSPF_LSA_GRACE:
dissect_ospf_lsa_grace_tlv(tvb, offset, tree, length);
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_ospf_lsa_unknown_type, tvb, offset, length,
"Unknown LSA Type %u", ls_id_type);
break;
}
}
static int
dissect_ospf_v2_lsa(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
gboolean disassemble_body)
{
proto_tree *ospf_lsa_tree;
proto_item *ti, *lsa_ti, *hidden_item;
guint8 ls_type;
guint16 ls_length;
int end_offset;
guint16 nr_links;
guint16 nr_metric;
guint8 link_type;
guint16 link_counter;
guint16 metric_counter;
const char *metric_type_str;
guint8 options;
guint8 ls_id_type;
guint8 ls_length_constraints[] = { 0, 24, 28, 28, 28, 36, 20, 36, 20, 20, 20, 20 };
ls_type = tvb_get_guint8(tvb, offset + 3);
ls_length = tvb_get_ntohs(tvb, offset + 18);
end_offset = offset + ls_length;
ospf_lsa_tree = proto_tree_add_subtree_format(tree, tvb, offset,
disassemble_body?ls_length:OSPF_LSA_HEADER_LENGTH,
ett_ospf_lsa, &lsa_ti, "LSA-type %d (%s), len %d",
ls_type, val_to_str_const(ls_type, ls_type_vals, "Unknown"),
ls_length);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_age, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_donotage, tvb,
offset, 2, ENC_BIG_ENDIAN);
options = tvb_get_guint8 (tvb, offset + 2);
if (ls_type != 7)
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 2, &bfinfo_v2_options);
else
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 2, &bfinfo_v2_options_lsa7);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_type, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
if (ospf_ls_type_to_filter(ls_type) != -1) {
hidden_item = proto_tree_add_item(ospf_lsa_tree,
*hf_ospf_ls_type_array[ospf_ls_type_to_filter(ls_type)], tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (options & OSPF_V2_OPTIONS_MT) {
metric_type_str = "MT-ID";
} else {
metric_type_str = "TOS";
}
if (is_opaque(ls_type)) {
ls_id_type = tvb_get_guint8(tvb, offset + 4);
proto_tree_add_uint(ospf_lsa_tree, hf_ospf_ls_opaque_type,
tvb, offset + 4, 1, ls_id_type);
switch (ls_id_type) {
case OSPF_LSA_MPLS_TE:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_id_te_lsa_reserved, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_mpls_te_instance,
tvb, offset + 6, 2, ENC_BIG_ENDIAN);
break;
case OSPF_LSA_OPAQUE_RI:
default:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_id_opaque_id, tvb, offset + 5, 3, ENC_BIG_ENDIAN);
break;
}
} else {
ls_id_type = 0;
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_id, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ospf_lsa_tree, hf_ospf_adv_router,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_seqnum, tvb,
offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_chksum, tvb,
offset + 16, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_length, tvb,
offset + 18, 2, ENC_BIG_ENDIAN);
if(ls_type && ls_type <= OSPF_LSTYPE_OP_ASWIDE) {
if(ls_length < ls_length_constraints[ls_type]) {
expert_add_info_format(pinfo, ti, &ei_ospf_lsa_bad_length, "Invalid LSA length (%u) for type %s, expected >= (%u)",
ls_length, val_to_str_const(ls_type, ls_type_vals, "Unknown"), ls_length_constraints[ls_type]);
return -1;
}
} else if(ls_length < 20) {
expert_add_info_format(pinfo, ti, &ei_ospf_lsa_bad_length, "Invalid LSA length (%u) for unknown LSA type (%u), expected minimum of (20)", ls_length, ls_type);
return -1;
}
offset += OSPF_LSA_HEADER_LENGTH;
if (ls_length <= OSPF_LSA_HEADER_LENGTH)
return offset;
ls_length -= OSPF_LSA_HEADER_LENGTH;
if (!disassemble_body)
return offset;
switch (ls_type){
case OSPF_LSTYPE_ROUTER:
if (options & OSPF_V2_OPTIONS_MT) {
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset, &bfinfo_v2_router_lsa_mt_flags);
} else {
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset, &bfinfo_v2_router_lsa_flags);
}
nr_links = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_lsa_number_of_links, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
offset += 4;
for (link_counter = 0; link_counter < nr_links; link_counter++) {
proto_tree *ospf_lsa_router_link_tree;
proto_item *ti_item;
link_type = tvb_get_guint8(tvb, offset + 8);
nr_metric = tvb_get_guint8(tvb, offset + 9);
ospf_lsa_router_link_tree = proto_tree_add_subtree_format(ospf_lsa_tree, tvb, offset, 12 + 4 * nr_metric,
ett_ospf_lsa_router_link, NULL, "Type: %-8s ID: %-15s Data: %-15s Metric: %d",
val_to_str_const(link_type, ospf_v3_lsa_type_short_vals, "Unknown"),
tvb_ip_to_str(tvb, offset),
tvb_ip_to_str(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 10));
ti_item = proto_tree_add_item(ospf_lsa_router_link_tree, hf_ospf_ls_router_linkid,
tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_item, " - %s", val_to_str_const(link_type, ospf_v3_lsa_link_id_vals, "Unknown link ID"));
proto_tree_add_item(ospf_lsa_router_link_tree, hf_ospf_ls_router_linkdata,
tvb, offset +4, 4, ENC_BIG_ENDIAN);
ti_item = proto_tree_add_item(ospf_lsa_router_link_tree, hf_ospf_ls_router_linktype,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_item, " - %s", val_to_str_const(link_type, ospf_v3_lsa_type_vals, "Unknown link type"));
ti_item = proto_tree_add_item(ospf_lsa_router_link_tree, hf_ospf_ls_router_nummetrics,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_item, " - %s", metric_type_str);
proto_tree_add_item(ospf_lsa_router_link_tree, hf_ospf_ls_router_metric0,
tvb, offset + 10, 2, ENC_BIG_ENDIAN);
offset += 12;
for (metric_counter = 0; metric_counter < nr_metric; metric_counter++) {
proto_tree_add_uint_format(ospf_lsa_router_link_tree, hf_ospf_ls_metric, tvb, offset, 4,
tvb_get_ntohs(tvb, offset + 2), "%s: %u, Metric: %u",
metric_type_str,
tvb_get_guint8(tvb, offset),
tvb_get_ntohs(tvb, offset + 2));
offset += 4;
}
}
break;
case OSPF_LSTYPE_NETWORK:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_network_netmask,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (offset == end_offset)
proto_tree_add_expert_format(ospf_lsa_tree, pinfo, &ei_ospf_lsa_constraint_missing, tvb, offset - 4, 4, "1 or more router-IDs required");
while (offset < end_offset) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_network_attachrtr,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case OSPF_LSTYPE_SUMMARY:
case OSPF_LSTYPE_ASBR:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_asbr_netmask,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if ((offset+4) > end_offset)
expert_add_info_format(pinfo, lsa_ti, &ei_ospf_lsa_constraint_missing, "1 or more TOS metrics required");
while (offset < end_offset) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_lsa_tos, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset, 3,
ENC_BIG_ENDIAN);
offset += 3;
}
break;
case OSPF_LSTYPE_ASEXT:
case OSPF_LSTYPE_ASEXT7:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_asext_netmask,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if ((offset+12) > end_offset)
expert_add_info_format(pinfo, lsa_ti, &ei_ospf_lsa_constraint_missing, "1 or more TOS forwarding blocks required");
while (offset < end_offset) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_lsa_external_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_lsa_external_tos, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_asext_fwdaddr,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_asext_extrtrtag,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case OSPF_LSTYPE_OP_LINKLOCAL:
case OSPF_LSTYPE_OP_AREALOCAL:
case OSPF_LSTYPE_OP_ASWIDE:
dissect_ospf_lsa_opaque(tvb, pinfo, offset, ospf_lsa_tree, ls_id_type,
ls_length);
offset += ls_length;
break;
default:
expert_add_info(pinfo, ti, &ei_ospf_lsa_unknown_type);
offset += ls_length;
break;
}
return offset;
}
static int
dissect_ospf_v3_lsa(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
gboolean disassemble_body, guint8 address_family)
{
proto_tree *ospf_lsa_tree, *router_tree = NULL, *router_entry_tree;
proto_item *ti, *hidden_item, *type_item;
guint16 ls_type;
guint16 ls_length;
int end_offset;
guint8 reserved;
guint32 number_prefixes;
guint8 prefix_length;
guint16 reserved16;
guint16 referenced_ls_type;
guint16 entry_count = 0;
guint8 flags;
ls_type = tvb_get_ntohs(tvb, offset + 2) & 0x1FFF;
ls_length = tvb_get_ntohs(tvb, offset + 18);
end_offset = offset + ls_length;
ospf_lsa_tree = proto_tree_add_subtree_format(tree, tvb, offset,
disassemble_body?ls_length:OSPF_LSA_HEADER_LENGTH,
ett_ospf_lsa, &type_item, "LSA-type %d (%s), len %d",
ls_type, val_to_str_const(ls_type, v3_ls_type_vals, "Unknown"),
ls_length);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_age, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_do_not_age, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_ls_type_u, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_ls_type_s12, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_ls_type, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (ospf_v3_ls_type_to_filter(ls_type) != -1) {
hidden_item = proto_tree_add_item(ospf_lsa_tree,
*hf_ospf_v3_ls_type_array[ospf_v3_ls_type_to_filter(ls_type)], tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_item(ospf_lsa_tree, hf_ospf_link_state_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_adv_router,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_seqnum, tvb,
offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_chksum, tvb,
offset + 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_ls_length, tvb,
offset + 18, 2, ENC_BIG_ENDIAN);
offset += OSPF_LSA_HEADER_LENGTH;
ls_length -= OSPF_LSA_HEADER_LENGTH;
if (!disassemble_body)
return offset;
switch (ls_type){
case OSPF_V3_LSTYPE_ROUTER:
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset, &bfinfo_v3_router_lsa_flags);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
offset+=4;
ls_length-=4;
if (ls_length > 0)
router_tree = proto_tree_add_subtree(ospf_lsa_tree, tvb, offset, ls_length,
ett_ospf_v3_router_interface, NULL, "Router Interfaces");
while (ls_length > 0 ) {
entry_count++;
router_entry_tree = proto_tree_add_subtree_format(router_tree, tvb, offset, 16,
ett_ospf_v3_router_interface_entry, NULL, "Entry #%d", entry_count);
proto_tree_add_item(router_entry_tree, hf_ospf_v3_lsa_type, tvb, offset, 1, ENC_BIG_ENDIAN);
reserved = tvb_get_guint8(tvb, offset+1);
ti = proto_tree_add_item(router_entry_tree, hf_ospf_header_reserved, tvb, offset+1, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
proto_tree_add_item(router_entry_tree, hf_ospf_metric, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(router_entry_tree, hf_ospf_v3_lsa_interface_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(router_entry_tree, hf_ospf_v3_lsa_neighbor_interface_id, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(router_entry_tree, hf_ospf_v3_lsa_neighbor_router_id, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
offset+=16;
ls_length-=16;
}
break;
case OSPF_V3_LSTYPE_NETWORK:
reserved = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
offset += 4;
ls_length-=4;
while (ls_length > 0 ) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_attached_router, tvb, offset, 4, ENC_BIG_ENDIAN);
ls_length-=4;
offset += 4;
}
break;
case OSPF_V3_LSTYPE_INTER_AREA_PREFIX:
reserved = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset + 1, 3, ENC_BIG_ENDIAN);
prefix_length=tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_prefix_length, tvb, offset+4, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+5, &bfinfo_v3_prefix_options);
reserved16=tvb_get_ntohs(tvb, offset+6);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset+6, 2, ENC_NA);
if (reserved16 != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
offset+=8;
dissect_ospf_v3_address_prefix(tvb, pinfo, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
break;
case OSPF_V3_LSTYPE_INTER_AREA_ROUTER:
reserved = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
reserved = tvb_get_guint8(tvb, offset+4);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset+4, 1, ENC_NA);
if (reserved != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset + 5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_destination_router_id, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
offset+=12;
break;
case OSPF_V3_LSTYPE_NSSA:
case OSPF_V3_LSTYPE_AS_EXTERNAL:
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset, &bfinfo_v3_as_external_flags);
flags=tvb_get_guint8(tvb, offset);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset+1, 3, ENC_BIG_ENDIAN);
prefix_length=tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_prefix_length, tvb, offset+4, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+5, &bfinfo_v3_prefix_options);
referenced_ls_type=tvb_get_ntohs(tvb, offset+6);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_referenced_ls_type, tvb, offset+6, 2, ENC_BIG_ENDIAN);
offset+=8;
dissect_ospf_v3_address_prefix(tvb, pinfo, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
if ( (offset < end_offset) && (flags & OSPF_V3_AS_EXTERNAL_FLAG_F) ) {
if (address_family == OSPF_AF_6) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_forwarding_address_ipv6, tvb, offset, 16, ENC_NA);
} else {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_forwarding_address_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset+=16;
}
if ( (offset < end_offset) && (flags & OSPF_V3_AS_EXTERNAL_FLAG_T) ) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_external_route_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
if ( (offset < end_offset) && (referenced_ls_type != 0) ) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_referenced_link_state_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
break;
case OSPF_V3_LSTYPE_LINK:
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_router_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
if (address_family == OSPF_AF_6) {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_link_local_interface_address, tvb, offset + 4, 16, ENC_NA);
} else {
proto_tree_add_item(ospf_lsa_tree, hf_ospf_link_local_interface_address_ipv4, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item_ret_uint(ospf_lsa_tree, hf_ospf_v3_lsa_num_prefixes, tvb, offset+20, 4, ENC_BIG_ENDIAN, &number_prefixes);
offset+=24;
while (number_prefixes > 0) {
prefix_length=tvb_get_guint8(tvb, offset);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+1, &bfinfo_v3_prefix_options);
reserved16=tvb_get_ntohs(tvb, offset+2);
ti = proto_tree_add_item(ospf_lsa_tree, hf_ospf_header_reserved, tvb, offset+2, 2, ENC_NA);
if (reserved16 != 0)
expert_add_info(pinfo, ti, &ei_ospf_header_reserved);
offset+=4;
dissect_ospf_v3_address_prefix(tvb, pinfo, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
number_prefixes--;
}
break;
case OSPF_V3_LSTYPE_INTRA_AREA_PREFIX:
proto_tree_add_item_ret_uint(ospf_lsa_tree, hf_ospf_v3_lsa_num_prefixes, tvb, offset, 2, ENC_BIG_ENDIAN, &number_prefixes);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_referenced_ls_type, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_v3_lsa_referenced_link_state_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_referenced_advertising_router, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
offset+=12;
while (number_prefixes > 0) {
prefix_length=tvb_get_guint8(tvb, offset);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+1, &bfinfo_v3_prefix_options);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_metric, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset+=4;
dissect_ospf_v3_address_prefix(tvb, pinfo, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
number_prefixes--;
}
break;
case OSPF_V3_LSTYPE_OPAQUE_RI:
dissect_ospf_lsa_opaque_ri(tvb, offset, ospf_lsa_tree, ls_length);
break;
default:
expert_add_info_format(pinfo, type_item, &ei_ospf_lsa_unknown_type,
"Unknown LSA Type %u",ls_type);
offset += ls_length;
break;
}
return offset;
}
static void dissect_ospf_v3_address_prefix(tvbuff_t *tvb, packet_info *pinfo, int offset, int prefix_length, proto_tree *tree,
guint8 address_family)
{
int bytes_to_process;
struct e_in6_addr prefix;
bytes_to_process=((prefix_length+31)/32)*4;
if (prefix_length > 128) {
proto_tree_add_expert_format(tree, pinfo, &ei_ospf_lsa_bad_length, tvb, offset, bytes_to_process,
"Address Prefix: length is invalid (%d, should be <= 128)",
prefix_length);
return;
}
memset(prefix.bytes, 0, sizeof prefix.bytes);
if (bytes_to_process != 0) {
tvb_memcpy(tvb, prefix.bytes, offset, bytes_to_process);
if (prefix_length % 8) {
prefix.bytes[bytes_to_process - 1] &=
((0xff00 >> (prefix_length % 8)) & 0xff);
}
}
if (address_family == OSPF_AF_6) {
proto_tree_add_ipv6(tree, hf_ospf_v3_address_prefix_ipv6, tvb, offset, bytes_to_process,
&prefix);
} else {
proto_tree_add_item(tree, hf_ospf_v3_address_prefix_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
void
proto_register_ospf(void)
{
static hf_register_info ospff_info[] = {
{&hf_ospf_header,
{ "OSPF Header", "ospf.header", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_version,
{ "Version", "ospf.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_msg_type,
{ "Message Type", "ospf.msg", FT_UINT8, BASE_DEC, VALS(pt_vals), 0x0,
NULL, HFILL }},
{&hf_ospf_header_packet_length,
{ "Packet Length", "ospf.packet_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_src_router,
{ "Source OSPF Router", "ospf.srcrouter", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_area_id,
{ "Area ID", "ospf.area_id", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_checksum,
{ "Checksum", "ospf.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_tlv_type,
{ "TLV Type", "ospf.tlv_type", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_tlv_length,
{ "TLV Length", "ospf.tlv_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_type,
{ "Auth Type", "ospf.auth.type", FT_UINT16, BASE_DEC, VALS(auth_vals), 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_data_none,
{ "Auth Data (none)", "ospf.auth.none", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_data_simple,
{ "Auth Data (Simple)", "ospf.auth.simple", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_crypt_key_id,
{ "Auth Crypt Key id", "ospf.auth.crypt.key_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_crypt_data_length,
{ "Auth Crypt Data Length", "ospf.auth.crypt.data_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_crypt_seq_nbr,
{ "Auth Crypt Sequence Number", "ospf.auth.crypt.seq_nbr", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_crypt_data,
{ "Auth Crypt Data", "ospf.auth.crypt.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_auth_data_unknown,
{ "Auth Unknown", "ospf.auth.unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_header_instance_id,
{ "Instance ID", "ospf.instance_id", FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(ospf_instance_id_rvals), 0x0,
NULL, HFILL }},
{&hf_ospf_header_reserved,
{ "Reserved", "ospf.reserved", FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }},
{&hf_ospf_msg_hello,
{ "Hello", "ospf.msg.hello", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_msg_db_desc,
{ "Database Description", "ospf.msg.dbdesc", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_msg_ls_req,
{ "Link State Adv Request", "ospf.msg.lsreq", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_msg_ls_upd,
{ "Link State Adv Update", "ospf.msg.lsupdate", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_msg_ls_ack,
{ "Link State Adv Acknowledgement", "ospf.msg.lsack", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello,
{ "OSPF Hello Packet", "ospf.hello", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_network_mask,
{ "Network Mask", "ospf.hello.network_mask", FT_IPv4,
BASE_NETMASK, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_interface_id,
{ "Interface ID", "ospf.hello.interface_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_hello_interval,
{ "Hello Interval [sec]", "ospf.hello.hello_interval", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_router_priority,
{ "Router Priority", "ospf.hello.router_priority", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_router_dead_interval,
{ "Router Dead Interval [sec]", "ospf.hello.router_dead_interval", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_designated_router,
{ "Designated Router", "ospf.hello.designated_router", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_backup_designated_router,
{ "Backup Designated Router", "ospf.hello.backup_designated_router", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_hello_active_neighbor,
{ "Active Neighbor", "ospf.hello.active_neighbor", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_at,
{ "OSPF Authentication Trailer", "ospf.at", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_at_auth_type,
{ "Authentication Type", "ospf.at.auth_type", FT_UINT16,
BASE_DEC, VALS(ospf_at_authentication_type_vals), 0x0, "Identifying the type of authentication", HFILL }},
{&hf_ospf_at_auth_data_len,
{ "Authentication Data Length", "ospf.at.auth_data_len", FT_UINT16,
BASE_DEC, NULL, 0x0, "The length in octets of the Authentication Trailer (AT) including both the 16-octet fixed header and the variable length message digest", HFILL }},
{&hf_ospf_at_reserved,
{ "Reserved", "ospf.at.reserved", FT_UINT16,
BASE_HEX, NULL, 0x0, "It SHOULD be set to 0", HFILL }},
{&hf_ospf_at_sa_id,
{ "Security Association Identifier (SA ID)", "ospf.at.sa_id", FT_UINT16,
BASE_HEX, NULL, 0x0, "That maps to the authentication algorithm and the secret key used to create the message digest", HFILL }},
{&hf_ospf_at_crypto_seq_nbr,
{ "Cryptographic Sequence Number", "ospf.at.cryto_seq_nbr", FT_UINT64,
BASE_DEC, NULL, 0x0, "Increasing sequence number that is used to guard against replay attacks", HFILL }},
{&hf_ospf_at_auth_data,
{ "Authentication Data", "ospf.at.auth_data", FT_BYTES,
BASE_NONE, NULL, 0x0, "Variable data that is carrying the digest for the protocol packet and optional LLS data block", HFILL }},
{&hf_ospf_ls_type,
{ "LS Type", "ospf.lsa", FT_UINT8, BASE_DEC,
VALS(ls_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_ls_age,
{"LS Age (seconds)", "ospf.lsa.age", FT_UINT16,
BASE_DEC, NULL, ~OSPF_DNA_LSA, NULL, HFILL }},
{&hf_ospf_ls_donotage,
{"Do Not Age Flag", "ospf.lsa.donotage", FT_UINT16,
BASE_DEC, NULL, OSPF_DNA_LSA, NULL, HFILL }},
{&hf_ospf_ls_id,
{"Link State ID", "ospf.lsa.id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_seqnum,
{"Sequence Number", "ospf.lsa.seqnum", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_chksum,
{"Checksum", "ospf.lsa.chksum", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_length,
{"Length", "ospf.lsa.length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_opaque_type,
{ "Link State ID Opaque Type", "ospf.lsid_opaque_type", FT_UINT8, BASE_DEC,
VALS(ls_opaque_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_te_instance,
{ "Link State ID TE-LSA Instance", "ospf.lsid_te_lsa.instance", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_router,
{ "Router LSA", "ospf.lsa.router", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_router_linktype,
{ "Link Type", "ospf.lsa.router.linktype", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_router_linkid,
{ "Link ID", "ospf.lsa.router.linkid", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_router_linkdata,
{ "Link Data", "ospf.lsa.router.linkdata", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_router_nummetrics,
{ "Number of Metrics", "ospf.lsa.router.nummetrics", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_router_metric0,
{ "0 Metric", "ospf.lsa.router.metric0", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_network,
{ "Network LSA", "ospf.lsa.network", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_network_netmask,
{ "Netmask", "ospf.lsa.network.netmask", FT_IPv4, BASE_NETMASK, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_network_attachrtr,
{ "Attached Router", "ospf.lsa.network.attchrtr", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_summary,
{ "Summary LSA (IP Network)", "ospf.lsa.summary", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_asbr,
{ "Summary LSA (ASBR)", "ospf.lsa.asbr", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asbr_netmask,
{ "Netmask", "ospf.lsa.asbr.netmask", FT_IPv4, BASE_NETMASK, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asext,
{ "AS-External LSA (ASBR)", "ospf.lsa.asext", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asext_netmask,
{ "Netmask", "ospf.lsa.asext.netmask", FT_IPv4, BASE_NETMASK, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asext_fwdaddr,
{ "Forwarding Address", "ospf.lsa.asext.fwdaddr", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asext_extrtrtag,
{ "External Route Tag", "ospf.lsa.asext.extrttag", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_grpmember,
{ "Group Membership LSA", "ospf.lsa.member", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_asext7,
{ "NSSA AS-External LSA", "ospf.lsa.nssa", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_extattr,
{ "External Attributes LSA", "ospf.lsa.attr", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_opaque,
{ "Opaque LSA", "ospf.lsa.opaque", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_type,
{ "LS Type", "ospf.v3.lsa", FT_UINT16, BASE_DEC, VALS(v3_ls_type_vals),0x1FFF,
NULL, HFILL }},
{&hf_ospf_v3_ls_type_u,
{ "LSA Handling", "ospf.v3.lsa.u", FT_BOOLEAN, 16, TFS(&tfs_v3_ls_type_u),0x8000,
NULL, HFILL }},
{&hf_ospf_v3_ls_type_s12,
{ "Flooding Scope", "ospf.v3.lsa.s12", FT_UINT16, BASE_HEX, VALS(v3_ls_type_s12_vals),0x6000,
NULL, HFILL }},
{&hf_ospf_v3_ls_router,
{ "Router-LSA", "ospf.v3.lsa.router", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_network,
{ "Network-LSA", "ospf.v3.lsa.network", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_inter_area_prefix,
{ "Inter-Area-Prefix-LSA", "ospf.v3.lsa.interprefix", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_ls_inter_area_router,
{ "Inter-Area-Router-LSA", "ospf.v3.lsa.interrouter", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_ls_as_external,
{ "AS-External-LSA", "ospf.v3.lsa.asext", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_group_membership,
{ "Group-Membership-LSA", "ospf.v3.lsa.member", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_nssa,
{ "NSSA-LSA", "ospf.v3.lsa.nssa", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_link,
{ "Link-LSA", "ospf.v3.lsa.link", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_v3_ls_intra_area_prefix,
{ "Intra-Area-Prefix-LSA", "ospf.v3.lsa.intraprefix", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_ls_opaque_ri,
{ "Router Information Opaque-LSA", "ospf.v3.lsa.opaque", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_adv_router,
{ "Advertising Router", "ospf.advrouter", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_mpls,
{ "MPLS Traffic Engineering LSA", "ospf.lsa.mpls", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_routerid,
{ "MPLS/TE Router ID", "ospf.mpls.routerid", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_mpls_linktype,
{ "MPLS/TE Link Type", "ospf.mpls.linktype", FT_UINT8, BASE_DEC,
VALS(mpls_link_stlv_ltype_str), 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_linkid,
{ "MPLS/TE Link ID", "ospf.mpls.linkid", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_ls_mpls_local_addr,
{ "MPLS/TE Local Interface Address", "ospf.mpls.local_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_remote_addr,
{ "MPLS/TE Remote Interface Address", "ospf.mpls.remote_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_te_metric,
{ "MPLS/TE Metric", "ospf.mpls.te_metric", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_local_ifid,
{ "MPLS/TE Local Interface Index", "ospf.mpls.local_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_remote_ifid,
{ "MPLS/TE Remote Interface Index", "ospf.mpls.remote_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_linkcolor,
{ "MPLS/TE Link Resource Class/Color", "ospf.mpls.linkcolor", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_group,
{ "MPLS/TE Group", "ospf.mpls.group", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_link_max_bw,
{ "Link Max BW", "ospf.mpls.link_max_bw", FT_FLOAT,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_mpls_bc_model_id,
{ "MPLS/DSTE Bandwidth Constraints Model Id", "ospf.mpls.bc.model_id", FT_UINT8,
BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_link_stlv_bcmodel_rvals), 0x0,
NULL, HFILL }},
{&hf_ospf_ls_oif_local_node_id,
{ "Local Node ID", "ospf.oif.local_node_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ls_oif_remote_node_id,
{ "Remote Node ID", "ospf.oif.remote_node_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v2_options,
{ "Options", "ospf.v2.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v2_options_mt,
{ "(MT) Multi-Topology Routing", "ospf.v2.options.mt", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_OPTIONS_MT, NULL, HFILL }},
{&hf_ospf_v2_options_e,
{ "(E) External Routing", "ospf.v2.options.e", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), OSPF_V2_OPTIONS_E, NULL, HFILL }},
{&hf_ospf_v2_options_mc,
{ "(MC) Multicast", "ospf.v2.options.mc", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), OSPF_V2_OPTIONS_MC, NULL, HFILL }},
{&hf_ospf_v2_options_n,
{ "(N) NSSA", "ospf.v2.options.n", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), OSPF_V2_OPTIONS_NP, NULL, HFILL }},
{&hf_ospf_v2_options_p,
{ "(P) Propagate", "ospf.v2.options.p", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V2_OPTIONS_NP, NULL, HFILL }},
{&hf_ospf_v2_options_l,
{ "(L) LLS Data block", "ospf.v2.options.l", FT_BOOLEAN, 8,
TFS(&tfs_present_not_present), OSPF_V2_OPTIONS_L, NULL, HFILL }},
{&hf_ospf_v2_options_dc,
{ "(DC) Demand Circuits", "ospf.v2.options.dc", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), OSPF_V2_OPTIONS_DC, NULL, HFILL }},
{&hf_ospf_v2_options_o,
{ "O", "ospf.v2.options.o", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V2_OPTIONS_O, NULL, HFILL }},
{&hf_ospf_v2_options_dn,
{ "DN", "ospf.v2.options.dn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V2_OPTIONS_DN, NULL, HFILL }},
{&hf_ospf_ri_options,
{ "RI Options", "ospf.ri.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_ri_options_grc,
{ "(GRC) Graceful Restart", "ospf.ri.options.grc", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), OSPF_RI_OPTIONS_GRC, NULL, HFILL }},
{&hf_ospf_ri_options_grh,
{ "(GRH) Graceful Restart Helper", "ospf.ri.options.grh", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), OSPF_RI_OPTIONS_GRH, NULL, HFILL }},
{&hf_ospf_ri_options_srs,
{ "Stub Router Support", "ospf.ri.options.srs", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_RI_OPTIONS_SRS, NULL, HFILL }},
{&hf_ospf_ri_options_tes,
{ "(TES) Traffic Engineering", "ospf.ri.options.tes", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), OSPF_RI_OPTIONS_TES, NULL, HFILL }},
{&hf_ospf_ri_options_p2plan,
{ "(P2PLAN) Point-to-point over LAN", "ospf.ri.options.p2plan", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), OSPF_RI_OPTIONS_P2PLAN, NULL, HFILL }},
{&hf_ospf_ri_options_ete,
{ "(ETE) Experimental TE", "ospf.ri.options.ete", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), OSPF_RI_OPTIONS_ETE, NULL, HFILL }},
{&hf_ospf_tlv_type_opaque,
{ "TLV Type", "ospf.tlv_type.opaque", FT_UINT16, BASE_DEC, VALS(ri_tlv_type_vals), 0x0,
NULL, HFILL }},
{&hf_ospf_v3_options,
{ "Options", "ospf.v3.options", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_options_v6,
{ "V6", "ospf.v3.options.v6", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_V6, NULL, HFILL }},
{&hf_ospf_v3_options_e,
{ "E", "ospf.v3.options.e", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_E, NULL, HFILL }},
{&hf_ospf_v3_options_mc,
{ "MC", "ospf.v3.options.mc", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_MC, NULL, HFILL }},
{&hf_ospf_v3_options_n,
{ "N", "ospf.v3.options.n", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_N, NULL, HFILL }},
{&hf_ospf_v3_options_r,
{ "R", "ospf.v3.options.r", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_R, NULL, HFILL }},
{&hf_ospf_v3_options_dc,
{ "DC", "ospf.v3.options.dc", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_DC, NULL, HFILL }},
{&hf_ospf_v3_options_af,
{ "AF", "ospf.v3.options.af", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_AF, NULL, HFILL }},
{&hf_ospf_v3_options_l,
{ "L", "ospf.v3.options.l", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_L, NULL, HFILL }},
{&hf_ospf_v3_options_at,
{ "AT", "ospf.v3.options.at", FT_BOOLEAN, 24,
TFS(&tfs_set_notset), OSPF_V3_OPTIONS_AT, NULL, HFILL }},
{&hf_ospf_dbd,
{ "DB Description", "ospf.dbd", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_dbd_r,
{ "(R) OOBResync", "ospf.dbd.r", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_DBD_FLAG_R, NULL, HFILL }},
{&hf_ospf_dbd_i,
{ "(I) Init", "ospf.dbd.i", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_DBD_FLAG_I, NULL, HFILL }},
{&hf_ospf_dbd_m,
{ "(M) More", "ospf.dbd.m", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_DBD_FLAG_M, NULL, HFILL }},
{&hf_ospf_dbd_ms,
{ "(MS) Master", "ospf.dbd.ms", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_DBD_FLAG_MS, NULL, HFILL }},
{&hf_ospf_lls_ext_options,
{ "Options", "ospf.lls.ext.options", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_lls_ext_options_lr,
{ "(LR) LSDB Resynchronization", "ospf.lls.ext.options.lr", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), OSPF_LLS_EXT_OPTIONS_LR, NULL, HFILL }},
{&hf_ospf_lls_ext_options_rs,
{ "(RS) Restart Signal", "ospf.lls.ext.options.rs", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), OSPF_LLS_EXT_OPTIONS_RS, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag,
{ "Flags", "ospf.v2.router.lsa.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag_b,
{ "(B) Area border router", "ospf.v2.router.lsa.flags.b", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_ROUTER_LSA_FLAG_B, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag_e,
{ "(E) AS boundary router", "ospf.v2.router.lsa.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_ROUTER_LSA_FLAG_E, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag_v,
{ "(V) Virtual link endpoint", "ospf.v2.router.lsa.flags.v", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_ROUTER_LSA_FLAG_V, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag_w,
{ "(W) Wild-card multicast receiver", "ospf.v2.router.lsa.flags.w", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_ROUTER_LSA_FLAG_W, NULL, HFILL }},
{&hf_ospf_v2_router_lsa_flag_n,
{ "(N) flag", "ospf.v2.router.lsa.flags.n", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V2_ROUTER_LSA_FLAG_N, NULL, HFILL }},
{&hf_ospf_v3_router_lsa_flag,
{ "Flags", "ospf.v3.router.lsa.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_router_lsa_flag_b,
{ "(B) Area border router", "ospf.v3.router.lsa.flags.b", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V3_ROUTER_LSA_FLAG_B, NULL, HFILL }},
{&hf_ospf_v3_router_lsa_flag_e,
{ "(E) AS boundary router", "ospf.v3.router.lsa.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V3_ROUTER_LSA_FLAG_E, NULL, HFILL }},
{&hf_ospf_v3_router_lsa_flag_v,
{ "(V) Virtual link endpoint", "ospf.v3.router.lsa.flags.v", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V3_ROUTER_LSA_FLAG_V, NULL, HFILL }},
{&hf_ospf_v3_router_lsa_flag_w,
{ "(W) Wild-card multicast receiver", "ospf.v3.router.lsa.flags.w", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), OSPF_V3_ROUTER_LSA_FLAG_W, NULL, HFILL }},
{&hf_ospf_v3_as_external_flag,
{ "Flags", "ospf.v3.as.external.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_as_external_flag_t,
{ "(T) External Route Tag", "ospf.v3.as.external.flags.t", FT_BOOLEAN, 8,
TFS(&tfs_present_not_present), OSPF_V3_AS_EXTERNAL_FLAG_T, NULL, HFILL }},
{&hf_ospf_v3_as_external_flag_f,
{ "(F) Forwarding Address", "ospf.v3.as.external.flags.f", FT_BOOLEAN, 8,
TFS(&tfs_present_absent), OSPF_V3_AS_EXTERNAL_FLAG_F, NULL, HFILL }},
{&hf_ospf_v3_as_external_flag_e,
{ "(E) External Metric", "ospf.v3.as.external.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_v3_as_external_flags_e), OSPF_V3_AS_EXTERNAL_FLAG_E, NULL, HFILL }},
{&hf_ospf_v3_prefix_option,
{ "PrefixOptions", "ospf.v3.prefix.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_prefix_option_nu,
{ "(NU) NoUnicast", "ospf.v3.prefix.options.nu", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_PREFIX_OPTION_NU, NULL, HFILL }},
{&hf_ospf_v3_prefix_option_la,
{ "(LA) Local Address", "ospf.v3.prefix.options.la", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_PREFIX_OPTION_LA, NULL, HFILL }},
{&hf_ospf_v3_prefix_option_mc,
{ "(MC) Multicast", "ospf.v3.prefix.options.mc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_PREFIX_OPTION_MC, NULL, HFILL }},
{&hf_ospf_v3_prefix_option_p,
{ "(P) Propagate", "ospf.v3.prefix.options.p", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_PREFIX_OPTION_P, NULL, HFILL }},
{&hf_ospf_dyn_hostname,
{ "Dynamic Hostname", "ospf.dynhostname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_lsa_sa,
{ "SR-Algorithm", "ospf.lsa_sa", FT_UINT8, BASE_DEC, VALS(ri_lsa_sa_tlv_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_unknown_tlv,
{ "Unknown TLV", "ospf.tlv.unknown", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v2_grace_tlv,
{ "Grace TLV", "ospf.v2.grace", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_ospf_v2_grace_period,
{ "Grace Period", "ospf.v2.grace.period", FT_UINT32, BASE_DEC,
NULL, 0x0,
"The number of seconds neighbors should advertise the router as fully adjacent",
HFILL }},
{&hf_ospf_v2_grace_reason,
{ "Restart Reason", "ospf.v2.grace.reason", FT_UINT8, BASE_DEC,
VALS(restart_reason_vals), 0x0, "The reason the router is restarting", HFILL }},
{&hf_ospf_v2_grace_ip,
{ "Restart IP", "ospf.v2.grace.ip", FT_IPv4, BASE_NONE,
NULL, 0x0, "The IP address of the interface originating this LSA", HFILL }},
{&hf_ospf_v3_lls_ext_options_tlv,
{ "Extended Options TLV", "ospf.v3.lls.ext.options.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_ext_options,
{ "Options", "ospf.v3.lls.ext.options", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_ext_options_lr,
{ "(LR) LSDB Resynchronization", "ospf.v3.lls.ext.options.lr", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), OSPF_V3_LLS_EXT_OPTIONS_LR, NULL, HFILL }},
{&hf_ospf_v3_lls_ext_options_rs,
{ "(RS) Restart Signal", "ospf.v3.lls.ext.options.rs", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), OSPF_V3_LLS_EXT_OPTIONS_RS, NULL, HFILL }},
{&hf_ospf_v3_lls_state_tlv,
{ "State Check Sequence TLV", "ospf.v3.lls.state.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_state_scs,
{ "SCS Number", "ospf.v3.lls.state.scs", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_state_options,
{ "Options", "ospf.v3.lls.state.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_state_options_r,
{ "(R) Resuest", "ospf.v3.lls.state.options.r", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_LLS_STATE_OPTIONS_R, NULL, HFILL }},
{&hf_ospf_v3_lls_state_options_a,
{ "(A) Answer", "ospf.v3.lls.state.options.a", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_LLS_STATE_OPTIONS_A , NULL, HFILL }},
{&hf_ospf_v3_lls_state_options_n,
{ "(N) Incomplete", "ospf.v3.lls.state.options.n", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_LLS_STATE_OPTIONS_N ,NULL, HFILL }},
{&hf_ospf_v3_lls_drop_tlv,
{ "Neighbor Drop TLV", "ospf.v3.lls.drop.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_relay_tlv,
{ "Active Overlapping Relays TLV", "ospf.v3.lls.relay.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_relay_added,
{ "Relays Added", "ospf.v3.lls.relay.added", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_relay_options,
{ "Options", "ospf.v3.lls.relay.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_relay_options_a,
{ "(A) Always", "ospf.v3.lls.relay.options.a", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_LLS_RELAY_OPTIONS_A, NULL, HFILL }},
{&hf_ospf_v3_lls_relay_options_n,
{ "(N) Never", "ospf.v3.lls.relay.options.n", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), OSPF_V3_LLS_RELAY_OPTIONS_N, NULL, HFILL }},
{&hf_ospf_v3_lls_willingness_tlv,
{ "Willingness TLV", "ospf.v3.lls.willingness.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_willingness,
{ "Willingness", "ospf.v3.lls.willingness", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_rf_tlv,
{ "Request From TLV", "ospf.v3.lls.rf.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_v3_lls_fsf_tlv,
{ "Full State For TLV", "ospf.v3.lls.fsf.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v2_lls_sequence_number, { "Sequence number", "ospf.v2.lls.sequence_number", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v2_lls_auth_data, { "Auth Data", "ospf.v2.lls.auth_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lls_extended_options, { "Extended Options", "ospf.v3.lls.extended_options", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lls_dropped_neighbor, { "Dropped Neighbor", "ospf.v3.lls.dropped_neighbor", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lls_neighbor, { "Neighbor", "ospf.v3.lls.neighbor", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lls_request_from, { "Request From", "ospf.v3.lls.request_from", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lls_full_state_for, { "Full State For", "ospf.v3.lls.full_state_for", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_lls_checksum, { "Checksum", "ospf.lls.checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_lls_data_length, { "LLS Data Length", "ospf.lls.data_length", FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0, NULL, HFILL }},
{ &hf_ospf_db_interface_mtu, { "Interface MTU", "ospf.db.interface_mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_db_dd_sequence, { "DD Sequence", "ospf.db.dd_sequence", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_link_state_id, { "Link State ID", "ospf.link_state_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_ls_number_of_lsas, { "Number of LSAs", "ospf.ls.number_of_lsas", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_switching_type, { "Switching Type", "ospf.mpls.switching_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_switching_type_rvals), 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_encoding, { "Encoding", "ospf.mpls.encoding", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_lsp_enc_rvals), 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_interface_mtu, { "Interface MTU", "ospf.mpls.interface_mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_protection_capability, { "Protection Capability", "ospf.mpls.protection_capability", FT_UINT8, BASE_HEX, VALS(gmpls_protection_cap_str), 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_shared_risk_link_group, { "Shared Risk Link Group", "ospf.mpls.shared_risk_link_group", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_oif_switching_cap, { "Switching Cap", "ospf.oif.switching_cap", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_switching_type_rvals), 0x0, NULL, HFILL }},
{ &hf_ospf_oif_encoding, { "Encoding", "ospf.oif.encoding", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_lsp_enc_rvals), 0x0, NULL, HFILL }},
{ &hf_ospf_oif_tna_addr_length, { "Addr Length", "ospf.oif.tna_addr_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_oif_tna_addr_ipv4, { "TNA Addr", "ospf.oif.tna_addr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_tna_addr_ipv6, { "TNA Addr", "ospf.oif.tna_addr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_tna_addr, { "TNA Addr", "ospf.oif.tna_addr", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_ls_id_te_lsa_reserved, { "Link State ID TE-LSA Reserved", "ospf.lsid_te_lsa.reserved", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_ls_id_opaque_id, { "Link State ID Opaque ID", "ospf.lsid.opaque_id", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_lsa_number_of_links, { "Number of Links", "ospf.lsa.number_of_links", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_do_not_age, { "Do Not Age", "ospf.v3.lsa.do_not_age", FT_BOOLEAN, 16, TFS(&tfs_true_false), OSPF_DNA_LSA, NULL, HFILL }},
{ &hf_ospf_v3_lsa_interface_id, { "Interface ID", "ospf.v3.lsa.interface_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_neighbor_interface_id, { "Neighbor Interface ID", "ospf.v3.lsa.neighbor_interface_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_neighbor_router_id, { "Neighbor Router ID", "ospf.v3.lsa.neighbor_router_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_attached_router, { "Attached Router", "ospf.v3.lsa.attached_router", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_destination_router_id, { "Destination Router ID", "ospf.v3.lsa.destination_router_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_referenced_ls_type, { "Referenced LS type", "ospf.v3.lsa.referenced_ls_type", FT_UINT16, BASE_HEX, VALS(v3_ls_type_vals), 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_forwarding_address_ipv6, { "Forwarding Address", "ospf.v3.lsa.forwarding_address.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_external_route_tag, { "External Route Tag", "ospf.v3.lsa.external_route_tag", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_referenced_link_state_id, { "Referenced Link State ID", "ospf.v3.lsa.referenced_link_state_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_router_priority, { "Router Priority", "ospf.v3.lsa.router_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_link_local_interface_address, { "Link-local Interface Address", "ospf.v3.lsa.link_local_interface_address.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_referenced_advertising_router, { "Referenced Advertising Router", "ospf.v3.lsa.referenced_advertising_router", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_lsa_external_type, { "External Type", "ospf.lsa.asext.type", FT_BOOLEAN, 8, TFS(&tfs_lsa_external_type), 0x80, NULL, HFILL }},
{ &hf_ospf_lsa_tos, { "TOS", "ospf.lsa.tos", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_lsa_external_tos, { "TOS", "ospf.lsa.tos", FT_UINT8, BASE_DEC, NULL, 0x7f, NULL, HFILL }},
{ &hf_ospf_v3_lsa_type, { "Type", "ospf.v3.lsa.type", FT_UINT8, BASE_DEC, VALS(ospf_v3_lsa_type_vals), 0, NULL, HFILL }},
{ &hf_ospf_metric, { "Metric", "ospf.metric", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ospf_prefix_length, { "PrefixLength", "ospf.prefix_length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ospf_ls_mpls_pri, { "Pri (or TE-Class)", "ospf.mpls.pri", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_ls_mpls_bc, { "BC", "ospf.mpls.bc", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_minimum_lsp_bandwidth, { "Minimum LSP bandwidth", "ospf.mpls.minimum_lsp_bandwidth", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_mpls_sonet_sdh, { "SONET/SDH", "ospf.mpls.sonet.sdh", FT_BOOLEAN, 8, TFS(&tfs_arbitrary_standard), 0x0, NULL, HFILL }},
{ &hf_ospf_oif_signal_type, { "Signal Type", "ospf.oif.signal_type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_tlv_value, { "TLV Value", "ospf.tlv_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_oif_node_id, { "Node ID", "ospf.oif.node_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_pad_bytes, { "Pad Bytes", "ospf.pad_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_ls_metric, { "Metric", "ospf.ls.metric", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_forwarding_address_ipv4, { "Forwarding Address", "ospf.v3.lsa.forwarding_address.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_link_local_interface_address_ipv4, { "Link-local Interface Address", "ospf.v3.lsa.link_local_interface_address.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_lsa_num_prefixes, { "# prefixes", "ospf.v3.lsa.num_prefixes", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_address_prefix_ipv6, { "Address Prefix", "ospf.v3.address_prefix.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ospf_v3_address_prefix_ipv4, { "Address Prefix", "ospf.v3.address_prefix.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ospf,
&ett_ospf_at,
&ett_ospf_hdr,
&ett_ospf_hello,
&ett_ospf_desc,
&ett_ospf_lsr,
&ett_ospf_lsa,
&ett_ospf_lsa_router_link,
&ett_ospf_lsa_upd,
&ett_ospf_lsa_mpls,
&ett_ospf_lsa_mpls_router,
&ett_ospf_lsa_mpls_link,
&ett_ospf_lsa_mpls_link_stlv,
&ett_ospf_lsa_mpls_link_stlv_admingrp,
&ett_ospf_lsa_opaque_ri,
&ett_ospf_lsa_ri_tlv,
&ett_ospf_lsa_dh_tlv,
&ett_ospf_lsa_sa_tlv,
&ett_ospf_lsa_unknown_tlv,
&ett_ospf_lsa_oif_tna,
&ett_ospf_lsa_oif_tna_stlv,
&ett_ospf_lsa_grace_tlv,
&ett_ospf_v2_options,
&ett_ospf_ri_options,
&ett_ospf_v3_options,
&ett_ospf_dbd,
&ett_ospf_lls_data_block,
&ett_ospf_lls_tlv,
&ett_ospf_lls_ext_options,
&ett_ospf_v3_router_interface,
&ett_ospf_v3_router_interface_entry,
&ett_ospf_v3_lls_ext_options_tlv,
&ett_ospf_v3_lls_ext_options,
&ett_ospf_v3_lls_state_tlv,
&ett_ospf_v3_lls_state_scs,
&ett_ospf_v3_lls_state_options,
&ett_ospf_v3_lls_drop_tlv,
&ett_ospf_v3_lls_relay_tlv,
&ett_ospf_v3_lls_relay_added,
&ett_ospf_v3_lls_relay_options,
&ett_ospf_v3_lls_willingness_tlv,
&ett_ospf_v3_lls_willingness,
&ett_ospf_v3_lls_rf_tlv,
&ett_ospf_v3_lls_fsf_tlv,
&ett_ospf_v2_router_lsa_flags,
&ett_ospf_v3_router_lsa_flags,
&ett_ospf_v3_as_external_flags,
&ett_ospf_v3_prefix_options
};
static ei_register_info ei[] = {
{ &ei_ospf_header_reserved, { "ospf.reserved.not_zero", PI_PROTOCOL, PI_WARN, "incorrect, should be 0", EXPFILL }},
{ &ei_ospf_lsa_bad_length, { "ospf.lsa.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_ospf_lsa_constraint_missing, { "ospf.lsa.tos_missing", PI_MALFORMED, PI_WARN, "Blocks missing", EXPFILL }},
{ &ei_ospf_lsa_bc_error, { "ospf.lsa.bc_error", PI_PROTOCOL, PI_WARN, "BC error", EXPFILL }},
{ &ei_ospf_lsa_unknown_type, { "ospf.lsa.unknown_type", PI_PROTOCOL, PI_WARN, "Unknown LSA Type", EXPFILL }},
{ &ei_ospf_unknown_link_subtype, { "ospf.unknown_link_subtype", PI_PROTOCOL, PI_WARN, "Unknown Link sub-TLV", EXPFILL }},
};
expert_module_t* expert_ospf;
proto_ospf = proto_register_protocol("Open Shortest Path First",
"OSPF", "ospf");
proto_register_field_array(proto_ospf, ospff_info, array_length(ospff_info));
proto_register_subtree_array(ett, array_length(ett));
expert_ospf = expert_register_protocol(proto_ospf);
expert_register_field_array(expert_ospf, ei, array_length(ei));
}
void
proto_reg_handoff_ospf(void)
{
dissector_handle_t ospf_handle;
capture_dissector_handle_t ospf_cap_handle;
ospf_handle = create_dissector_handle(dissect_ospf, proto_ospf);
dissector_add_uint("ip.proto", IP_PROTO_OSPF, ospf_handle);
ospf_cap_handle = create_capture_dissector_handle(capture_ospf, proto_ospf);
capture_dissector_add_uint("ip.proto", IP_PROTO_OSPF, ospf_cap_handle);
}
