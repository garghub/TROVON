static gint ospf_msg_type_to_filter (guint8 msg_type)
{
if (msg_type >= OSPF_HELLO &&
msg_type <= OSPF_LS_ACK)
return msg_type + OSPFF_MSG_MIN;
return -1;
}
static gint ospf_ls_type_to_filter (guint8 ls_type)
{
if (ls_type >= OSPF_LSTYPE_ROUTER &&
ls_type <= OSPF_LSTYPE_EXTATTR)
return OSPFF_LS_MIN + ls_type;
else if (ls_type >= OSPF_LSTYPE_OP_LINKLOCAL &&
ls_type <= OSPF_LSTYPE_OP_ASWIDE)
return OSPFF_LS_OPAQUE;
else
return -1;
}
static gint ospf_v3_ls_type_to_filter (guint16 ls_type)
{
guint16 function_code;
function_code = ls_type & 0x1fff;
if (function_code >= OSPF_V3_LSA_FUNCTION_CODE_ROUTER &&
function_code <= OSPF_V3_LSA_FUNCTION_CODE_INTRA_AREA_PREFIX)
return OSPFF_V3_LS_MIN + function_code;
else if (function_code == OSPF_V3_LSA_FUNCTION_CODE_OPAQUE_RI)
return OSPFF_V3_LS_OPAQUE_RI;
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
hfindex = hf_ospf_filter[bfinfo->hfindex];
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
idx = hf_ospf_filter[bfinfo->idx[i]];
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
static void
dissect_ospf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ospf_tree = NULL;
proto_item *ti, *hidden_item;
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
char auth_data[8+1];
int crypto_len = 0;
unsigned int ospf_header_length;
guint8 instance_ID;
guint8 reserved;
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
if (tree) {
ospflen = tvb_get_ntohs(tvb, 2);
ti = proto_tree_add_item(tree, proto_ospf, tvb, 0, -1, ENC_NA);
ospf_tree = proto_item_add_subtree(ti, ett_ospf);
ti = proto_tree_add_text(ospf_tree, tvb, 0, ospf_header_length,
"OSPF Header");
ospf_header_tree = proto_item_add_subtree(ti, ett_ospf_hdr);
proto_tree_add_text(ospf_header_tree, tvb, 0, 1, "OSPF Version: %u",
version);
proto_tree_add_item(ospf_header_tree, hf_ospf_filter[OSPFF_MSG_TYPE],
tvb, 1, 1, ENC_BIG_ENDIAN);
if (ospf_msg_type_to_filter(packet_type) != -1) {
hidden_item = proto_tree_add_item(ospf_header_tree,
hf_ospf_filter[ospf_msg_type_to_filter(packet_type)],
tvb, 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_text(ospf_header_tree, tvb, 2, 2, "Packet Length: %u",
ospflen);
proto_tree_add_item(ospf_header_tree, hf_ospf_filter[OSPFF_SRC_ROUTER],
tvb, 4, 4, ENC_BIG_ENDIAN);
areaid=tvb_get_ntohl(tvb,8);
proto_tree_add_text(ospf_header_tree, tvb, 8, 4, "Area ID: %s%s",
tvb_ip_to_str(tvb, 8), areaid == 0 ? " (Backbone)" : "");
switch (version) {
case OSPF_VERSION_2:
case OSPF_VERSION_3:
break;
default:
cksum = tvb_get_ntohs(tvb, 12);
if (cksum == 0) {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x (none)", cksum);
} else {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x", cksum);
}
proto_tree_add_text(ospf_tree, tvb, 14, -1,
"Unknown OSPF version %u", version);
return;
}
cksum = tvb_get_ntohs(tvb, 12);
length = tvb_length(tvb);
reported_length = tvb_reported_length(tvb);
if (cksum == 0) {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x (none)", cksum);
} else if (!pinfo->fragmented && length >= reported_length
&& length >= ospf_header_length) {
switch (version) {
case OSPF_VERSION_2:
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, 16);
cksum_vec[0].len = 16;
if (length > ospf_header_length) {
reported_length -= ospf_header_length;
cksum_vec[1].ptr = tvb_get_ptr(tvb, ospf_header_length, reported_length);
cksum_vec[1].len = reported_length;
cksum_vec_len = 2;
} else {
cksum_vec_len = 1;
}
break;
case OSPF_VERSION_3:
cksum_vec[0].ptr = (guint8 *)pinfo->src.data;
cksum_vec[0].len = pinfo->src.len;
cksum_vec[1].ptr = (guint8 *)pinfo->dst.data;
cksum_vec[1].len = pinfo->dst.len;
cksum_vec[2].ptr = (const guint8 *)&phdr;
phdr[0] = g_htonl(ospflen);
phdr[1] = g_htonl(IP_PROTO_OSPF);
cksum_vec[2].len = 8;
cksum_vec[3].ptr = tvb_get_ptr(tvb, 0, reported_length);
cksum_vec[3].len = reported_length;
cksum_vec_len = 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
cksum_vec_len = 0;
break;
}
computed_cksum = in_cksum(cksum_vec, cksum_vec_len);
if (computed_cksum == 0) {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x [correct]", cksum);
} else {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x [incorrect, should be 0x%04x]",
cksum, in_cksum_shouldbe(cksum, computed_cksum));
}
} else {
proto_tree_add_text(ospf_header_tree, tvb, 12, 2,
"Packet Checksum: 0x%04x", cksum);
}
switch (version) {
case OSPF_VERSION_2:
auth_type = tvb_get_ntohs(tvb, 14);
proto_tree_add_text(ospf_header_tree, tvb, 14, 2, "Auth Type: %s",
val_to_str(auth_type, auth_vals, "Unknown (%u)"));
switch (auth_type) {
case OSPF_AUTH_NONE:
proto_tree_add_text(ospf_header_tree, tvb, 16, 8, "Auth Data (none)");
break;
case OSPF_AUTH_SIMPLE:
tvb_get_nstringz0(tvb, 16, 8+1, auth_data);
proto_tree_add_text(ospf_header_tree, tvb, 16, 8, "Auth Data: %s", auth_data);
break;
case OSPF_AUTH_CRYPT:
proto_tree_add_text(ospf_header_tree, tvb, 18, 1, "Auth Key ID: %u",
tvb_get_guint8(tvb, 18));
crypto_len = tvb_get_guint8(tvb, 19);
proto_tree_add_text(ospf_header_tree, tvb, 19, 1, "Auth Data Length: %u",
crypto_len);
proto_tree_add_text(ospf_header_tree, tvb, 20, 4, "Auth Crypto Sequence Number: 0x%x",
tvb_get_ntohl(tvb, 20));
if (tvb_bytes_exist(tvb, ospflen, crypto_len)) {
proto_tree_add_text(ospf_header_tree, tvb, ospflen, crypto_len,
"Auth Data: %s",
tvb_bytes_to_str(tvb, ospflen, crypto_len));
proto_tree_set_appendix(ospf_header_tree, tvb, ospflen, crypto_len);
}
break;
default:
proto_tree_add_text(ospf_header_tree, tvb, 16, 8, "Auth Data (unknown)");
break;
}
break;
case OSPF_VERSION_3:
instance_ID = tvb_get_guint8(tvb, 14);
ti = proto_tree_add_text(ospf_header_tree, tvb, 14, 1, "Instance ID: %u",
instance_ID);
if (instance_ID < 32) {
proto_item_append_text(ti, " (IPv6 unicast AF)");
address_family = OSPF_AF_6;
} else if (instance_ID < 64) {
proto_item_append_text(ti, " (IPv6 multicast AF)");
address_family = OSPF_AF_6;
} else if (instance_ID < 96) {
proto_item_append_text(ti, " (IPv4 unicast AF)");
address_family = OSPF_AF_4;
} else if (instance_ID < 128) {
proto_item_append_text(ti, " (IPv4 multicast AF)");
address_family = OSPF_AF_4;
} else {
proto_item_append_text(ti, " (Reserved)");
address_family = OSPF_AF_6;
}
reserved = tvb_get_guint8(tvb, 15);
proto_tree_add_text(ospf_header_tree, tvb, 15, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),
reserved);
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
dissect_ospf_db_desc(tvb, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
case OSPF_LS_REQ:
dissect_ospf_ls_req(tvb, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length));
break;
case OSPF_LS_UPD:
dissect_ospf_ls_upd(tvb, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
case OSPF_LS_ACK:
dissect_ospf_ls_ack(tvb, (int)ospf_header_length, ospf_tree, version,
(guint16)(ospflen - ospf_header_length),
address_family);
break;
default:
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, ospf_header_length), pinfo, tree);
break;
}
if (ospf_has_lls_block(tvb, ospf_header_length, packet_type, version)) {
dissect_ospf_lls_data_block(tvb, ospflen + crypto_len, ospf_tree,
version);
}
}
}
static int
dissect_ospfv2_lls_tlv(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *ospf_lls_tlv_tree;
guint16 type;
guint16 length;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, length + 4, "%s",
val_to_str_const(type, lls_tlv_type_vals, "Unknown TLV"));
ospf_lls_tlv_tree = proto_item_add_subtree(ti, ett_ospf_lls_tlv);
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 2,
"Type: %d", type);
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset + 2, 2,
"Length: %d", length);
switch(type) {
case 1:
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 4, &bfinfo_lls_ext_options);
break;
case 2:
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset + 4, 4,
"Sequence number 0x%08x",
tvb_get_ntohl(tvb, offset + 4));
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset + 8, length - 4,
"Auth Data: %s",
tvb_bytes_to_str(tvb, offset + 8, length - 4));
break;
}
return offset + length + 4;
}
static int
dissect_ospfv3_lls_tlv(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *ospf_lls_tlv_tree;
guint16 type;
guint16 length;
guint8 relays_added;
int orig_offset;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
switch(type) {
case LLS_V3_EXT_OPT:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_EXT_OPTIONS_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_STATE_CHECK:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_STATE_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_NBR_DROP:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_DROP_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_RELAYS:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_RELAY_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_WILLING:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_WILLINGNESS_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_RQST_FROM:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_RF_TLV], tvb,
offset, length + 4, ENC_NA);
break;
case LLS_V3_FULL_STATE:
ti = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V3_LLS_FSF_TLV], tvb,
offset, length + 4, ENC_NA);
break;
default:
ti = proto_tree_add_text(tree, tvb, offset, length + 4, "%s",
val_to_str_const(type, lls_v3_tlv_type_vals, "Unknown TLV"));
}
ospf_lls_tlv_tree = proto_item_add_subtree(ti, ett_ospf_lls_tlv);
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 2,
"Type: %d", type);
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset + 2, 2,
"Length: %d", length);
orig_offset = offset;
switch (type) {
case LLS_V3_EXT_OPT:
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset + 4, 4,
"Extended Options: 0x%08x",
tvb_get_ntohl(tvb, offset + 4));
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 4, &bfinfo_v3_lls_ext_options);
break;
case LLS_V3_STATE_CHECK:
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_filter[OSPFF_V3_LLS_STATE_SCS],
tvb, offset+4, 2, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 6,
&bfinfo_v3_lls_state_options);
break;
case LLS_V3_NBR_DROP:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 4,
"Dropped Neighbor: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
offset = orig_offset;
break;
case LLS_V3_RELAYS:
relays_added = tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_filter[OSPFF_V3_LLS_RELAY_ADDED],
tvb, offset+4, 1, ENC_BIG_ENDIAN);
dissect_ospf_bitfield(ospf_lls_tlv_tree, tvb, offset + 5,
&bfinfo_v3_lls_relay_options);
offset += 8;
while (orig_offset + length >= offset) {
ti = proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 4,
"Neighbor: %s",
tvb_ip_to_str(tvb, offset));
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
proto_tree_add_item(ospf_lls_tlv_tree, hf_ospf_filter[OSPFF_V3_LLS_WILLINGNESS],
tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
case LLS_V3_RQST_FROM:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 4,
"Request From: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
offset = orig_offset;
break;
case LLS_V3_FULL_STATE:
offset += 4;
while (orig_offset + length >= offset) {
proto_tree_add_text(ospf_lls_tlv_tree, tvb, offset, 4,
"Full State For: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
offset = orig_offset;
break;
}
return offset + length + 4;
}
static void
dissect_ospf_lls_data_block(tvbuff_t *tvb, int offset, proto_tree *tree,
guint8 version)
{
proto_tree *ospf_lls_data_block_tree;
proto_item *ti;
guint16 ospf_lls_len;
int orig_offset = offset;
ospf_lls_len = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, -1, "OSPF LLS Data Block");
ospf_lls_data_block_tree = proto_item_add_subtree(ti,
ett_ospf_lls_data_block);
proto_tree_add_text(ospf_lls_data_block_tree, tvb, offset, 2,
"Checksum: 0x%04x", tvb_get_ntohs(tvb, offset));
proto_tree_add_text(ospf_lls_data_block_tree, tvb, offset + 2, 2,
"LLS Data Length: %d bytes", ospf_lls_len * 4);
offset += 4;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + ospf_lls_len * 4 > offset) {
if (version == OSPF_VERSION_2)
offset = dissect_ospfv2_lls_tlv (tvb, offset, ospf_lls_data_block_tree);
else
offset = dissect_ospfv3_lls_tlv (tvb, offset, ospf_lls_data_block_tree);
}
}
static void
dissect_ospf_hello(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 version,
guint16 length)
{
proto_tree *ospf_hello_tree;
proto_item *ti;
int orig_offset = offset;
ti = proto_tree_add_text(tree, tvb, offset, length, "OSPF Hello Packet");
ospf_hello_tree = proto_item_add_subtree(ti, ett_ospf_hello);
switch (version ) {
case OSPF_VERSION_2:
proto_tree_add_text(ospf_hello_tree, tvb, offset, 4, "Network Mask: %s",
tvb_ip_to_str(tvb, offset));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 4, 2,
"Hello Interval: %u seconds",
tvb_get_ntohs(tvb, offset + 4));
dissect_ospf_bitfield(ospf_hello_tree, tvb, offset + 6, &bfinfo_v2_options);
proto_tree_add_text(ospf_hello_tree, tvb, offset + 7, 1, "Router Priority: %u",
tvb_get_guint8(tvb, offset + 7));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 8, 4, "Router Dead Interval: %u seconds",
tvb_get_ntohl(tvb, offset + 8));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 12, 4, "Designated Router: %s",
tvb_ip_to_str(tvb, offset + 12));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 16, 4, "Backup Designated Router: %s",
tvb_ip_to_str(tvb, offset + 16));
offset += 20;
while (orig_offset + length > offset) {
proto_tree_add_text(ospf_hello_tree, tvb, offset, 4,
"Active Neighbor: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
break;
case OSPF_VERSION_3:
proto_tree_add_text(ospf_hello_tree, tvb, offset + 0, 4, "Interface ID: %u",
tvb_get_ntohl(tvb, offset + 0));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 4, 1, "Router Priority: %u",
tvb_get_guint8(tvb, offset + 4));
dissect_ospf_bitfield(ospf_hello_tree, tvb, offset + 5, &bfinfo_v3_options);
proto_tree_add_text(ospf_hello_tree, tvb, offset + 8, 2,
"Hello Interval: %u seconds",
tvb_get_ntohs(tvb, offset + 8));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 10, 2, "Router Dead Interval: %u seconds",
tvb_get_ntohs(tvb, offset + 10));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 12, 4, "Designated Router: %s",
tvb_ip_to_str(tvb, offset + 12));
proto_tree_add_text(ospf_hello_tree, tvb, offset + 16, 4, "Backup Designated Router: %s",
tvb_ip_to_str(tvb, offset + 16));
offset += 20;
while (orig_offset + length > offset) {
proto_tree_add_text(ospf_hello_tree, tvb, offset, 4,
"Active Neighbor: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
break;
}
}
static void
dissect_ospf_db_desc(tvbuff_t *tvb, int offset, proto_tree *tree,
guint8 version, guint16 length, guint8 address_family)
{
proto_tree *ospf_db_desc_tree=NULL;
proto_item *ti;
guint8 reserved;
int orig_offset = offset;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, length, "OSPF DB Description");
ospf_db_desc_tree = proto_item_add_subtree(ti, ett_ospf_desc);
switch (version ) {
case OSPF_VERSION_2:
proto_tree_add_text(ospf_db_desc_tree, tvb, offset, 2, "Interface MTU: %u",
tvb_get_ntohs(tvb, offset));
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 2, &bfinfo_v2_options);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 3, &bfinfo_dbd);
proto_tree_add_text(ospf_db_desc_tree, tvb, offset + 4, 4, "DD Sequence: %u",
tvb_get_ntohl(tvb, offset + 4));
offset += 8;
break;
case OSPF_VERSION_3:
reserved = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_db_desc_tree, tvb, offset, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),
reserved);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 1, &bfinfo_v3_options);
proto_tree_add_text(ospf_db_desc_tree, tvb, offset + 4, 2, "Interface MTU: %u",
tvb_get_ntohs(tvb, offset+4));
reserved = tvb_get_guint8(tvb, offset + 6);
proto_tree_add_text(ospf_db_desc_tree, tvb, offset + 6, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),
reserved);
dissect_ospf_bitfield(ospf_db_desc_tree, tvb, offset + 7, &bfinfo_dbd);
proto_tree_add_text(ospf_db_desc_tree, tvb, offset + 8, 4, "DD Sequence: %u",
tvb_get_ntohl(tvb, offset + 8));
offset += 12;
break;
}
}
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + length > offset) {
if ( version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, offset, tree, FALSE);
else
offset = dissect_ospf_v3_lsa(tvb, offset, tree, FALSE, address_family);
}
}
static void
dissect_ospf_ls_req(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 version,
guint16 length)
{
proto_tree *ospf_lsr_tree;
proto_item *ti;
guint16 reserved;
int orig_offset = offset;
while (orig_offset + length > offset) {
ti = proto_tree_add_text(tree, tvb, offset, OSPF_LS_REQ_LENGTH,
"Link State Request");
ospf_lsr_tree = proto_item_add_subtree(ti, ett_ospf_lsr);
switch ( version ) {
case OSPF_VERSION_2:
proto_tree_add_item(ospf_lsr_tree, hf_ospf_filter[OSPFF_LS_TYPE],
tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case OSPF_VERSION_3:
reserved = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(ospf_lsr_tree, tvb, offset, 2,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"), reserved);
proto_tree_add_item(ospf_lsr_tree, hf_ospf_filter[OSPFF_V3_LS_TYPE],
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_text(ospf_lsr_tree, tvb, offset + 4, 4, "Link State ID: %s",
tvb_ip_to_str(tvb, offset + 4));
proto_tree_add_item(ospf_lsr_tree, hf_ospf_filter[OSPFF_ADV_ROUTER],
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
offset += 12;
}
}
static void
dissect_ospf_ls_upd(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 version,
guint16 length, guint8 address_family)
{
proto_tree *ospf_lsa_upd_tree=NULL;
proto_item *ti;
guint32 lsa_nr;
guint32 lsa_counter;
ti = proto_tree_add_text(tree, tvb, offset, length, "LS Update Packet");
ospf_lsa_upd_tree = proto_item_add_subtree(ti, ett_ospf_lsa_upd);
lsa_nr = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(ospf_lsa_upd_tree, tvb, offset, 4, "Number of LSAs: %u", lsa_nr);
offset += 4;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
lsa_counter = 0;
while (lsa_counter < lsa_nr) {
if (version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, offset, ospf_lsa_upd_tree, TRUE);
else
offset = dissect_ospf_v3_lsa(tvb, offset, ospf_lsa_upd_tree, TRUE,
address_family);
lsa_counter += 1;
}
}
static void
dissect_ospf_ls_ack(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 version,
guint16 length, guint8 address_family)
{
int orig_offset = offset;
DISSECTOR_ASSERT((version == OSPF_VERSION_2) || (version == OSPF_VERSION_3));
while (orig_offset + length > offset) {
if (version == OSPF_VERSION_2)
offset = dissect_ospf_v2_lsa(tvb, offset, tree, FALSE);
else
offset = dissect_ospf_v3_lsa(tvb, offset, tree, FALSE, address_family);
}
}
static int
is_opaque(int lsa_type)
{
return (lsa_type >= OSPF_LSTYPE_OP_LINKLOCAL &&
lsa_type <= OSPF_LSTYPE_OP_ASWIDE);
}
static void
dissect_ospf_lsa_mpls(tvbuff_t *tvb, int offset, proto_tree *tree,
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
const guint8 allzero[] = { 0x00, 0x00, 0x00 };
guint num_bcs = 0;
ti = proto_tree_add_text(tree, tvb, offset, length,
"MPLS Traffic Engineering LSA");
hidden_item = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_LS_MPLS],
tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
mpls_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls);
while (length != 0) {
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_end_offset = offset + tlv_length + 4;
switch (tlv_type) {
case MPLS_TLV_ROUTER:
ti = proto_tree_add_text(mpls_tree, tvb, offset, tlv_length+4,
"Router Address: %s",
tvb_ip_to_str(tvb, offset+4));
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_router);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: 1 - Router Address");
proto_tree_add_text(tlv_tree, tvb, offset+2, 2, "TLV Length: %u",
tlv_length);
proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_LS_MPLS_ROUTERID],
tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case MPLS_TLV_LINK:
ti = proto_tree_add_text(mpls_tree, tvb, offset, tlv_length+4,
"Link Information");
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: 2 - Link Information");
proto_tree_add_text(tlv_tree, tvb, offset+2, 2, "TLV Length: %u",
tlv_length);
stlv_offset = offset + 4;
while (stlv_offset < tlv_end_offset) {
stlv_type = tvb_get_ntohs(tvb, stlv_offset);
stlv_len = tvb_get_ntohs(tvb, stlv_offset + 2);
stlv_name = val_to_str_const(stlv_type, mpls_link_stlv_str, "Unknown sub-TLV");
switch (stlv_type) {
case MPLS_LINK_TYPE:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %u - %s", stlv_name,
tvb_get_guint8(tvb, stlv_offset + 4),
val_to_str_const(tvb_get_guint8(tvb, stlv_offset + 4),
mpls_link_stlv_ltype_str, "Unknown Link Type"));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree, hf_ospf_filter[OSPFF_LS_MPLS_LINKTYPE],
tvb, stlv_offset+4, 1,ENC_BIG_ENDIAN);
break;
case MPLS_LINK_ID:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree, hf_ospf_filter[OSPFF_LS_MPLS_LINKID],
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_LOCAL_IF:
case MPLS_LINK_REMOTE_IF:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %s", stlv_name, tvb_ip_to_str(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
for (i=0; i < stlv_len; i+=4)
proto_tree_add_item(stlv_tree,
stlv_type==MPLS_LINK_LOCAL_IF ?
hf_ospf_filter[OSPFF_LS_MPLS_LOCAL_ADDR] :
hf_ospf_filter[OSPFF_LS_MPLS_REMOTE_ADDR],
tvb, stlv_offset+4+i, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_TE_METRIC:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %u", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 4, "%s: %u", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
break;
case MPLS_LINK_COLOR:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: 0x%08x", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
stlv_admingrp = tvb_get_ntohl(tvb, stlv_offset + 4);
mask = 1;
ti = proto_tree_add_item(stlv_tree, hf_ospf_filter[OSPFF_LS_MPLS_LINKCOLOR],
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
stlv_admingrp_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv_admingrp);
if (stlv_admingrp_tree == NULL)
return;
for (i = 0 ; i < 32 ; i++) {
if ((stlv_admingrp & mask) != 0) {
proto_tree_add_text(stlv_admingrp_tree, tvb, stlv_offset+4,
4, "Group %d", i);
}
mask <<= 1;
}
break;
case MPLS_LINK_MAX_BW:
case MPLS_LINK_MAX_RES_BW:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %.10g bytes/s (%.0f bits/s)", stlv_name,
tvb_get_ntohieee_float(tvb, stlv_offset + 4),
tvb_get_ntohieee_float(tvb, stlv_offset + 4) * 8.0);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 4, "%s: %.10g bytes/s (%.0f bits/s)", stlv_name,
tvb_get_ntohieee_float(tvb, stlv_offset + 4),
tvb_get_ntohieee_float(tvb, stlv_offset + 4) * 8.0);
break;
case MPLS_LINK_UNRES_BW:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
for (i = 0; i < 8; i++) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4+(i*4), 4,
"Pri (or TE-Class) %d: %.10g bytes/s (%.0f bits/s)", i,
tvb_get_ntohieee_float(tvb, stlv_offset + 4 + i*4),
tvb_get_ntohieee_float(tvb, stlv_offset + 4 + i*4) * 8.0);
}
break;
case MPLS_LINK_BANDWIDTH_CONSTRAINT:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree, hf_ospf_filter[OSPFF_LS_MPLS_BC_MODEL_ID],
tvb, stlv_offset+4, 1, ENC_BIG_ENDIAN);
if(tvb_memeql(tvb, stlv_offset+5, allzero, 3) == -1) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+5, 3,
"Warning: these bytes are reserved and must be 0x00");
}
if(((stlv_len % 4)!=0)) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: Length must be N x 4 octets");
break;
}
num_bcs = (stlv_len - 4)/4;
if(num_bcs>8) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: too many BC (%u)", num_bcs);
break;
}
if(num_bcs==0) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, stlv_len,
"Malformed Packet: Bandwidth Constraints sub-TLV with no BC?");
break;
}
for(i = 0; i < (int) num_bcs; i++) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8+(i*4), 4,
"BC %d: %.10g bytes/s (%.0f bits/s)", i,
tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4),
tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4) * 8.0);
}
break;
case MPLS_LINK_LOCAL_REMOTE_ID:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %d (0x%x) - %d (0x%x)", stlv_name,
tvb_get_ntohl(tvb, stlv_offset + 4),
tvb_get_ntohl(tvb, stlv_offset + 4),
tvb_get_ntohl(tvb, stlv_offset + 8),
tvb_get_ntohl(tvb, stlv_offset + 8));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree,
hf_ospf_filter[OSPFF_LS_MPLS_LOCAL_IFID],
tvb, stlv_offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stlv_tree,
hf_ospf_filter[OSPFF_LS_MPLS_REMOTE_IFID],
tvb, stlv_offset+8, 4, ENC_BIG_ENDIAN);
break;
case MPLS_LINK_IF_SWITCHING_DESC:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
switch_cap = tvb_get_guint8 (tvb, stlv_offset+4);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Switching Type: %s",
rval_to_str(tvb_get_guint8(tvb,stlv_offset+4),
gmpls_switching_type_rvals, "Unknown (%d)"));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+5, 1, "Encoding: %s",
rval_to_str(tvb_get_guint8(tvb,stlv_offset+5),
gmpls_lsp_enc_rvals, "Unknown (%d)"));
for (i = 0; i < 8; i++) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8+(i*4), 4,
"Pri %d: %.10g bytes/s (%.0f bits/s)", i,
tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4),
tvb_get_ntohieee_float(tvb, stlv_offset + 8 + i*4) * 8.0);
}
if (switch_cap >=1 && switch_cap <=4) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+40, 4,
"Minimum LSP bandwidth: %.10g bytes/s (%.0f bits/s)",
tvb_get_ntohieee_float(tvb, stlv_offset + 40),
tvb_get_ntohieee_float(tvb, stlv_offset + 40) * 8.0);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+44, 2,
"Interface MTU: %d", tvb_get_ntohs(tvb, stlv_offset+44));
}
if (switch_cap == 100) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+40, 4,
"Minimum LSP bandwidth: %.10g bytes/s (%.0f bits/s)",
tvb_get_ntohieee_float(tvb, stlv_offset + 40),
tvb_get_ntohieee_float(tvb, stlv_offset + 40) * 8.0);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+44, 2,
"SONET/SDH: %s",
tvb_get_guint8(tvb, stlv_offset+44) ?
"Arbitrary" : "Standard");
}
break;
case MPLS_LINK_PROTECTION:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Protection Capability: %s (0x%x)",
val_to_str(tvb_get_guint8(tvb,stlv_offset+4),
gmpls_protection_cap_str,
"Unknown (%d)"),
tvb_get_guint8(tvb,stlv_offset+4));
break;
case MPLS_LINK_SHARED_RISK_GROUP:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
for (i=0; i < stlv_len; i+=4)
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4+i, 4, "Shared Risk Link Group: %u",
tvb_get_ntohl(tvb,stlv_offset+4+i));
break;
case OIF_LOCAL_NODE_ID:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree,
hf_ospf_filter[OSPFF_LS_OIF_LOCAL_NODE_ID],
tvb, stlv_offset + 4, 4, ENC_BIG_ENDIAN);
break;
case OIF_REMOTE_NODE_ID:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_item(stlv_tree,
hf_ospf_filter[OSPFF_LS_OIF_REMOTE_NODE_ID],
tvb, stlv_offset + 4, 4, ENC_BIG_ENDIAN);
break;
case OIF_SONET_SDH_SWITCHING_CAPABILITY:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4, "%s", stlv_name);
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Switching Cap: %s",
rval_to_str(tvb_get_guint8 (tvb, stlv_offset+4),
gmpls_switching_type_rvals, "Unknown (%d)"));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+5, 1, "Encoding: %s",
rval_to_str(tvb_get_guint8(tvb,stlv_offset+5),
gmpls_lsp_enc_rvals, "Unknown (%d)"));
for (i = 0; i < (stlv_len - 4) / 4; i++) {
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8+(i*4), 4,
"%s: %d free timeslots",
val_to_str_ext(tvb_get_guint8(tvb, stlv_offset+8+(i*4)),
&gmpls_sonet_signal_type_str_ext,
"Unknown Signal Type (%d)"),
tvb_get_ntoh24(tvb, stlv_offset + 9 + i*4));
}
break;
default:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"Unknown Link sub-TLV: %u %s", stlv_type,
rval_to_str(stlv_type, mpls_te_sub_tlv_rvals, "Unknown"));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s %s", stlv_type, stlv_name,
rval_to_str(stlv_type, mpls_te_sub_tlv_rvals, "Unknown"));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, stlv_len,
"TLV Value");
break;
}
stlv_offset += ((stlv_len+4+3)/4)*4;
}
break;
case OIF_TLV_TNA:
ti = proto_tree_add_text(mpls_tree, tvb, offset, tlv_length+4,
"TNA Information");
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_oif_tna);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: 32768 - TNA Information");
proto_tree_add_text(tlv_tree, tvb, offset+2, 2, "TLV Length: %u",
tlv_length);
stlv_offset = offset + 4;
while (stlv_offset < tlv_end_offset) {
stlv_type = tvb_get_ntohs(tvb, stlv_offset);
stlv_len = tvb_get_ntohs(tvb, stlv_offset + 2);
stlv_name = val_to_str_const(stlv_type, oif_stlv_str, "Unknown sub-TLV");
switch (stlv_type) {
case OIF_NODE_ID:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_oif_tna_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u",
stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 4, "%s: %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 4));
break;
case OIF_TNA_IPv4_ADDRESS:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s (IPv4): %s", stlv_name,
tvb_ip_to_str(tvb, stlv_offset + 8));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_oif_tna_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s (IPv4)", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u", stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Addr Length: %u",
tvb_get_guint8 (tvb, stlv_offset+4));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8, stlv_len - 4, "TNA Addr: %s",
tvb_ip_to_str(tvb, stlv_offset + 8));
break;
case OIF_TNA_IPv6_ADDRESS:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s (IPv6): %s", stlv_name,
tvb_ip6_to_str(tvb, stlv_offset + 8));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_oif_tna_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s (IPv6)", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u", stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Addr Length: %u",
tvb_get_guint8 (tvb, stlv_offset+4));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8, stlv_len - 4, "TNA Addr: %s",
tvb_ip6_to_str(tvb, stlv_offset + 8));
break;
case OIF_TNA_NSAP_ADDRESS:
ti = proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"%s (NSAP): %s", stlv_name,
tvb_bytes_to_str (tvb, stlv_offset + 8, stlv_len - 4));
stlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_oif_tna_stlv);
proto_tree_add_text(stlv_tree, tvb, stlv_offset, 2,
"TLV Type: %u: %s (NSAP)", stlv_type, stlv_name);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+2, 2, "TLV Length: %u", stlv_len);
proto_tree_add_text(stlv_tree, tvb, stlv_offset+4, 1, "Addr Length: %u",
tvb_get_guint8 (tvb, stlv_offset+4));
proto_tree_add_text(stlv_tree, tvb, stlv_offset+8, stlv_len - 4, "TNA Addr: %s",
tvb_bytes_to_str(tvb, stlv_offset+8, stlv_len - 4));
break;
default:
proto_tree_add_text(tlv_tree, tvb, stlv_offset, stlv_len+4,
"Unknown Link sub-TLV: %u", stlv_type);
break;
}
stlv_offset += ((stlv_len+4+3)/4)*4;
}
break;
default:
ti = proto_tree_add_text(mpls_tree, tvb, offset, tlv_length+4,
"Unknown LSA: %u %s", tlv_type,
rval_to_str(tlv_type, mpls_te_tlv_rvals, "Unknown"));
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_mpls_link);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: %u - Unknown %s",
tlv_type, rval_to_str(tlv_type, mpls_te_tlv_rvals, "Unknown"));
proto_tree_add_text(tlv_tree, tvb, offset+2, 2, "TLV Length: %u",
tlv_length);
proto_tree_add_text(tlv_tree, tvb, offset+4, tlv_length, "TLV Data");
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
guint32 restart_ip;
proto_tree *tlv_tree;
proto_item *tree_item;
proto_item *grace_tree_item;
if (!tree) { return; }
while (length > 0)
{
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_length_with_pad = tlv_length + 4 + ((4 - (tlv_length % 4)) % 4);
tree_item = proto_tree_add_item(tree, hf_ospf_filter[OSPFF_V2_GRACE_TLV], tvb, offset,
tlv_length_with_pad, ENC_NA);
tlv_tree = proto_item_add_subtree(tree_item, ett_ospf_lsa_grace_tlv);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "Type: %s (%u)",
val_to_str_const(tlv_type, grace_tlv_type_vals, "Unknown grace-LSA TLV"), tlv_type);
proto_tree_add_text(tlv_tree, tvb, offset + 2, 2, "Length: %u", tlv_length);
switch (tlv_type) {
case GRACE_TLV_PERIOD:
grace_period = tvb_get_ntohl(tvb, offset + 4);
grace_tree_item = proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_V2_GRACE_PERIOD], tvb,
offset + 4, tlv_length, ENC_BIG_ENDIAN);
proto_item_append_text(grace_tree_item, " seconds");
proto_item_set_text(tree_item, "Grace Period: %u seconds", grace_period);
break;
case GRACE_TLV_REASON:
restart_reason = tvb_get_guint8(tvb, offset + 4);
proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_V2_GRACE_REASON], tvb, offset + 4,
tlv_length, ENC_BIG_ENDIAN);
proto_item_set_text(tree_item, "Restart Reason: %s (%u)",
val_to_str_const(restart_reason, restart_reason_vals, "Unknown Restart Reason"),
restart_reason);
break;
case GRACE_TLV_IP:
restart_ip = tvb_get_ipv4(tvb, offset + 4);
proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_V2_GRACE_IP], tvb, offset + 4,
tlv_length, ENC_BIG_ENDIAN);
proto_item_set_text(tree_item, "Restart IP: %s (%s)",
get_hostname(restart_ip), ip_to_str((guint8 *)&restart_ip));
break;
default:
proto_item_set_text(tree_item, "Unknown grace-LSA TLV");
break;
}
if (4 + tlv_length < tlv_length_with_pad) {
proto_tree_add_text(tlv_tree, tvb, offset + 4 + tlv_length,
tlv_length_with_pad - (4 + tlv_length), "Pad Bytes (%u)",
tlv_length_with_pad - (4 + tlv_length) );
}
offset += tlv_length_with_pad;
length -= tlv_length_with_pad;
}
}
static void
dissect_ospf_lsa_opaque_ri(tvbuff_t *tvb, int offset, proto_tree *tree,
guint32 length)
{
proto_item *ti;
proto_tree *ri_tree;
proto_tree *tlv_tree;
int tlv_type;
int tlv_length;
ti = proto_tree_add_text(tree, tvb, offset, length,
"Opaque Router Information LSA");
ri_tree = proto_item_add_subtree(ti, ett_ospf_lsa_opaque_ri);
while (length > 0) {
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
switch(tlv_type) {
case OPT_RI_TLV:
ti = proto_tree_add_text(ri_tree, tvb, offset, tlv_length+4,
"RI TLV");
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_ri_tlv);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: %s (%u)",
"Router Informational Capabilities TLV", tlv_type);
proto_tree_add_text(tlv_tree, tvb, offset + 2, 2, "TLV Length: %u", tlv_length);
dissect_ospf_bitfield(tlv_tree, tvb, offset + 4, &bfinfo_ri_options);
break;
case DYN_HOSTNAME_TLV:
ti = proto_tree_add_text(ri_tree, tvb, offset, tlv_length+4,
"Dynamic Hostname TLV");
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_dyn_hostname_tlv);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: %s (%u)",
"Dynamic Hostname TLV", tlv_type);
proto_tree_add_text(tlv_tree, tvb, offset + 2, 2, "TLV Length: %u", tlv_length);
proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_DYN_HOSTNAME], tvb, offset+4, tlv_length, ENC_ASCII|ENC_NA);
break;
default:
ti = proto_tree_add_text(ri_tree, tvb, offset, tlv_length+4,
"Unknown Opaque RI LSA TLV");
tlv_tree = proto_item_add_subtree(ti, ett_ospf_lsa_unknown_tlv);
proto_tree_add_text(tlv_tree, tvb, offset, 2, "TLV Type: %s (%u)",
"Unknown TLV", tlv_type);
proto_tree_add_text(tlv_tree, tvb, offset + 2, 2, "TLV Length: %u", tlv_length);
proto_tree_add_item(tlv_tree, hf_ospf_filter[OSPFF_UNKNOWN_TLV_TXT], tvb, offset+4, tlv_length, ENC_ASCII|ENC_NA);
break;
}
offset += tlv_length + 4;
length -= tlv_length + 4;
}
}
static void
dissect_ospf_lsa_opaque(tvbuff_t *tvb, int offset, proto_tree *tree,
guint8 ls_id_type, guint32 length)
{
switch (ls_id_type) {
case OSPF_LSA_MPLS_TE:
dissect_ospf_lsa_mpls(tvb, offset, tree, length);
break;
case OSPF_LSA_OPAQUE_RI:
dissect_ospf_lsa_opaque_ri(tvb, offset, tree, length);
break;
case OSPF_LSA_GRACE:
dissect_ospf_lsa_grace_tlv(tvb, offset, tree, length);
break;
default:
proto_tree_add_text(tree, tvb, offset, length,
"Unknown LSA Type %u", ls_id_type);
break;
}
}
static int
dissect_ospf_v2_lsa(tvbuff_t *tvb, int offset, proto_tree *tree,
gboolean disassemble_body)
{
proto_tree *ospf_lsa_tree;
proto_item *ti, *hidden_item;
guint8 ls_type;
guint16 ls_length;
int end_offset;
guint16 nr_links;
guint16 nr_metric;
guint8 link_type;
guint16 link_counter;
guint16 metric_counter;
const char *link_type_str;
const char *link_type_short_str;
const char *link_id;
const char *metric_type_str;
guint8 options;
guint8 ls_id_type;
guint8 ls_ri_opaque_field;
ls_type = tvb_get_guint8(tvb, offset + 3);
ls_length = tvb_get_ntohs(tvb, offset + 18);
end_offset = offset + ls_length;
if (disassemble_body) {
ti = proto_tree_add_text(tree, tvb, offset, ls_length,
"LS Type: %s",
val_to_str(ls_type, ls_type_vals, "Unknown (%d)"));
} else {
ti = proto_tree_add_text(tree, tvb, offset, OSPF_LSA_HEADER_LENGTH,
"LSA Header");
}
ospf_lsa_tree = proto_item_add_subtree(ti, ett_ospf_lsa);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 2, "LS Age: %u seconds",
tvb_get_ntohs(tvb, offset) & ~OSPF_DNA_LSA);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 2, "Do Not Age: %s",
(tvb_get_ntohs(tvb, offset) & OSPF_DNA_LSA) ? "True" : "False");
options = tvb_get_guint8 (tvb, offset + 2);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 2, &bfinfo_v2_options);
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_LS_TYPE], tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
if (ospf_ls_type_to_filter(ls_type) != -1) {
hidden_item = proto_tree_add_item(ospf_lsa_tree,
hf_ospf_filter[ospf_ls_type_to_filter(ls_type)], tvb,
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
proto_tree_add_uint(ospf_lsa_tree, hf_ospf_filter[OSPFF_LS_OPAQUE_TYPE],
tvb, offset + 4, 1, ls_id_type);
switch (ls_id_type) {
case OSPF_LSA_MPLS_TE:
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 5, 1, "Link State ID TE-LSA Reserved: %u",
tvb_get_guint8(tvb, offset + 5));
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_LS_MPLS_TE_INSTANCE],
tvb, offset + 6, 2, ENC_BIG_ENDIAN);
break;
case OSPF_LSA_OPAQUE_RI:
ls_ri_opaque_field = tvb_get_guint8(tvb, offset + 5);
if ( ls_ri_opaque_field != 0 )
ls_id_type = OSPF_LSA_UNKNOWN;
else
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_OPAQUE_LSA_MBZ],
tvb, offset + 5, 3, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 5, 3, "Link State ID Opaque ID: %u",
tvb_get_ntoh24(tvb, offset + 5));
break;
}
} else {
ls_id_type = 0;
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 4, "Link State ID: %s",
tvb_ip_to_str(tvb, offset + 4));
}
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_ADV_ROUTER],
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 12, 4, "LS Sequence Number: 0x%08x",
tvb_get_ntohl(tvb, offset + 12));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 16, 2, "LS Checksum: 0x%04x",
tvb_get_ntohs(tvb, offset + 16));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 18, 2, "Length: %u",
ls_length);
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
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 2, 2, "Number of Links: %u",
nr_links);
offset += 4;
for (link_counter = 0; link_counter < nr_links; link_counter++) {
proto_tree *ospf_lsa_router_link_tree;
proto_item *ti_local;
link_type = tvb_get_guint8(tvb, offset + 8);
switch (link_type) {
case OSPF_LINK_PTP:
link_type_str="Point-to-point connection to another router";
link_type_short_str="PTP";
link_id="Neighboring router's Router ID";
break;
case OSPF_LINK_TRANSIT:
link_type_str="Connection to a transit network";
link_type_short_str="Transit";
link_id="IP address of Designated Router";
break;
case OSPF_LINK_STUB:
link_type_str="Connection to a stub network";
link_type_short_str="Stub";
link_id="IP network/subnet number";
break;
case OSPF_LINK_VIRTUAL:
link_type_str="Virtual link";
link_type_short_str="Virtual";
link_id="Neighboring router's Router ID";
break;
default:
link_type_str="Unknown link type";
link_type_short_str="Unknown";
link_id="Unknown link ID";
break;
}
nr_metric = tvb_get_guint8(tvb, offset + 9);
ti_local = proto_tree_add_text(ospf_lsa_tree, tvb, offset, 12 + 4 * nr_metric,
"Type: %-8s ID: %-15s Data: %-15s Metric: %d",
link_type_short_str,
tvb_ip_to_str(tvb, offset),
tvb_ip_to_str(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 10));
ospf_lsa_router_link_tree = proto_item_add_subtree(ti_local, ett_ospf_lsa_router_link);
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset, 4, "%s: %s", link_id,
tvb_ip_to_str(tvb, offset));
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset + 4, 4, "Link Data: %s",
tvb_ip_to_str(tvb, offset + 4));
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset + 8, 1, "Link Type: %u - %s",
link_type, link_type_str);
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset + 9, 1, "Number of %s metrics: %u",
metric_type_str, nr_metric);
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset + 10, 2, "%s 0 metric: %u",
metric_type_str, tvb_get_ntohs(tvb, offset + 10));
offset += 12;
for (metric_counter = 0; metric_counter < nr_metric; metric_counter++) {
proto_tree_add_text(ospf_lsa_router_link_tree, tvb, offset, 4, "%s: %u, Metric: %u",
metric_type_str,
tvb_get_guint8(tvb, offset),
tvb_get_ntohs(tvb, offset + 2));
offset += 4;
}
}
break;
case OSPF_LSTYPE_NETWORK:
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Netmask: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
while (offset < end_offset) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Attached Router: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
}
break;
case OSPF_LSTYPE_SUMMERY:
case OSPF_LSTYPE_ASBR:
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Netmask: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Metric: %u",
tvb_get_ntoh24(tvb, offset + 1));
offset += 4;
while (offset < end_offset) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "%s: %u, Metric: %u",
metric_type_str,
tvb_get_guint8(tvb, offset),
tvb_get_ntoh24(tvb, offset + 1));
offset += 4;
}
break;
case OSPF_LSTYPE_ASEXT:
case OSPF_LSTYPE_ASEXT7:
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Netmask: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
options = tvb_get_guint8(tvb, offset);
if (options & 0x80) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
"External Type: Type 2 (metric is larger than any other link state path)");
} else {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
"External Type: Type 1 (metric is specified in the same units as interface cost)");
}
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 1, 3, "Metric: %u",
tvb_get_ntoh24(tvb, offset + 1));
offset += 4;
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Forwarding Address: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "External Route Tag: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
while (offset < end_offset) {
options = tvb_get_guint8(tvb, offset);
if (options & 0x80) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
"External Type: Type 2 (metric is larger than any other link state path)");
} else {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
"External Type: Type 1 (metric is specified in the same units as interface cost)");
}
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "%s: %u, Metric: %u",
metric_type_str, options & 0x7F,
tvb_get_ntoh24(tvb, offset + 1));
offset += 4;
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Forwarding Address: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "External Route Tag: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
}
break;
case OSPF_LSTYPE_OP_LINKLOCAL:
case OSPF_LSTYPE_OP_AREALOCAL:
case OSPF_LSTYPE_OP_ASWIDE:
dissect_ospf_lsa_opaque(tvb, offset, ospf_lsa_tree, ls_id_type,
ls_length);
offset += ls_length;
break;
default:
proto_tree_add_text(ospf_lsa_tree, tvb, offset, ls_length,
"Unknown LSA Type");
offset += ls_length;
break;
}
return offset;
}
static int
dissect_ospf_v3_lsa(tvbuff_t *tvb, int offset, proto_tree *tree,
gboolean disassemble_body, guint8 address_family)
{
proto_tree *ospf_lsa_tree;
proto_item *ti, *hidden_item;
guint16 ls_type;
guint16 ls_length;
int end_offset;
guint8 reserved;
guint8 link_type;
const char *link_type_str;
guint32 metric;
guint8 router_priority;
guint32 number_prefixes;
guint8 prefix_length;
guint16 reserved16;
guint16 referenced_ls_type;
guint8 flags;
guint32 external_route_tag;
ls_type = tvb_get_ntohs(tvb, offset + 2);
ls_length = tvb_get_ntohs(tvb, offset + 18);
end_offset = offset + ls_length;
if (disassemble_body) {
ti = proto_tree_add_text(tree, tvb, offset, ls_length,
"%s (Type: 0x%04x)", val_to_str_const(ls_type, v3_ls_type_vals,"Unknown"), ls_type);
} else {
ti = proto_tree_add_text(tree, tvb, offset, OSPF_LSA_HEADER_LENGTH,
"LSA Header");
}
ospf_lsa_tree = proto_item_add_subtree(ti, ett_ospf_lsa);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 2, "LS Age: %u seconds",
tvb_get_ntohs(tvb, offset) & ~OSPF_DNA_LSA);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 2, "Do Not Age: %s",
(tvb_get_ntohs(tvb, offset) & OSPF_DNA_LSA) ? "True" : "False");
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_V3_LS_TYPE], tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
if (ospf_v3_ls_type_to_filter(ls_type) != -1) {
hidden_item = proto_tree_add_item(ospf_lsa_tree,
hf_ospf_filter[ospf_v3_ls_type_to_filter(ls_type)], tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 4, "Link State ID: %s",
tvb_ip_to_str(tvb, offset + 4));
proto_tree_add_item(ospf_lsa_tree, hf_ospf_filter[OSPFF_ADV_ROUTER],
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 12, 4, "LS Sequence Number: 0x%08x",
tvb_get_ntohl(tvb, offset + 12));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 16, 2, "LS Checksum: 0x%04x",
tvb_get_ntohs(tvb, offset + 16));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 18, 2, "Length: %u",
ls_length);
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
proto_tree_add_text(ospf_lsa_tree, tvb, offset, ls_length,
"Router Interfaces:");
while (ls_length > 0 ) {
link_type = tvb_get_guint8(tvb, offset);
switch (link_type) {
case OSPF_V3_LINK_PTP:
link_type_str="Point-to-point connection to another router";
break;
case OSPF_V3_LINK_TRANSIT:
link_type_str="Connection to a transit network";
break;
case OSPF_V3_LINK_RESERVED:
link_type_str="Connection to a stub network";
break;
case OSPF_V3_LINK_VIRTUAL:
link_type_str="Virtual link";
break;
default:
link_type_str="Unknown link type";
break;
}
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1, "Type: %u (%s)", link_type,link_type_str);
reserved = tvb_get_guint8(tvb, offset+1);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+1, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved);
metric=tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 2, 2,"Metric: %u",metric);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 4, "Interface ID: %u",
tvb_get_ntohl(tvb, offset + 4));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 8, 4, "Neighbor Interface ID: %u",
tvb_get_ntohl(tvb, offset + 8));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 12, 4, "Neighbor Router ID: %s",
tvb_ip_to_str(tvb, offset + 12));
offset+=16;
ls_length-=16;
}
break;
case OSPF_V3_LSTYPE_NETWORK:
reserved = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
offset += 4;
ls_length-=4;
while (ls_length > 0 ) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Attached Router: %s",
tvb_ip_to_str(tvb, offset));
ls_length-=4;
offset += 4;
}
break;
case OSPF_V3_LSTYPE_INTER_AREA_PREFIX:
reserved = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved);
metric=tvb_get_ntoh24(tvb, offset+1);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 1, 3,"Metric: %u",metric);
prefix_length=tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+4, 1, "PrefixLength: %u",prefix_length);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+5, &bfinfo_v3_prefix_options);
reserved16=tvb_get_ntohs(tvb, offset+6);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+6, 2,
(reserved16 == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved16);
offset+=8;
dissect_ospf_v3_address_prefix(tvb, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
break;
case OSPF_V3_LSTYPE_INTER_AREA_ROUTER:
reserved = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
reserved = tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+4, 1,
(reserved == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved);
metric=tvb_get_ntoh24(tvb, offset+5);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 5, 3,"Metric: %u",metric);
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 8, 4, "Destination Router ID: %s",
tvb_ip_to_str(tvb, offset + 8));
offset+=12;
break;
case OSPF_V3_LSTYPE_NSSA:
case OSPF_V3_LSTYPE_AS_EXTERNAL:
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset, &bfinfo_v3_as_external_flags);
flags=tvb_get_guint8(tvb, offset);
metric=tvb_get_ntoh24(tvb, offset+1);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+1, 3,
"Metric: %u", metric);
prefix_length=tvb_get_guint8(tvb, offset+4);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+4, 1, "PrefixLength: %u",prefix_length);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+5, &bfinfo_v3_prefix_options);
referenced_ls_type=tvb_get_ntohs(tvb, offset+6);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+6, 2,"Referenced LS type 0x%04x (%s)",
referenced_ls_type, val_to_str_const(referenced_ls_type, v3_ls_type_vals, "Unknown"));
offset+=8;
dissect_ospf_v3_address_prefix(tvb, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
if ( (offset < end_offset) && (flags & OSPF_V3_AS_EXTERNAL_FLAG_F) ) {
if (address_family == OSPF_AF_6) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 16,"Forwarding Address: %s",
tvb_ip6_to_str(tvb, offset));
} else {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 16,"Forwarding Address: %s",
tvb_ip_to_str(tvb, offset));
}
offset+=16;
}
if ( (offset < end_offset) && (flags & OSPF_V3_AS_EXTERNAL_FLAG_T) ) {
external_route_tag=tvb_get_ntohl(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4,"External Route Tag: %u",
external_route_tag);
offset+=4;
}
if ( (offset < end_offset) && (referenced_ls_type != 0) ) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 4, "Referenced Link State ID: %s",
tvb_ip_to_str(tvb, offset));
offset+=4;
}
break;
case OSPF_V3_LSTYPE_LINK:
router_priority=tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1, "Router Priority: %u", router_priority);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset + 1, &bfinfo_v3_options);
if (address_family == OSPF_AF_6) {
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 16, "Link-local Interface Address: %s",
tvb_ip6_to_str(tvb, offset + 4));
} else {
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 16, "Link-local Interface Address: %s",
tvb_ip_to_str(tvb, offset + 4));
}
number_prefixes=tvb_get_ntohl(tvb, offset + 20);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+20, 4, "# prefixes: %d",number_prefixes);
offset+=24;
while (number_prefixes > 0) {
prefix_length=tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1, "PrefixLength: %u",prefix_length);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+1, &bfinfo_v3_prefix_options);
reserved16=tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+2, 2,
(reserved16 == 0 ? "Reserved: %u" : "Reserved: %u [incorrect, should be 0]"),reserved16);
offset+=4;
dissect_ospf_v3_address_prefix(tvb, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
number_prefixes--;
}
break;
case OSPF_V3_LSTYPE_INTRA_AREA_PREFIX:
number_prefixes=tvb_get_ntohs(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 2,"# prefixes: %u",number_prefixes);
referenced_ls_type=tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+2, 2,"Referenced LS type 0x%04x (%s)",
referenced_ls_type, val_to_str_const(referenced_ls_type, v3_ls_type_vals, "Unknown"));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 4, 4, "Referenced Link State ID: %s",
tvb_ip_to_str(tvb, offset + 4));
proto_tree_add_text(ospf_lsa_tree, tvb, offset + 8, 4, "Referenced Advertising Router: %s",
tvb_ip_to_str(tvb, offset + 8));
offset+=12;
while (number_prefixes > 0) {
prefix_length=tvb_get_guint8(tvb, offset);
proto_tree_add_text(ospf_lsa_tree, tvb, offset, 1, "PrefixLength: %u",prefix_length);
dissect_ospf_bitfield(ospf_lsa_tree, tvb, offset+1, &bfinfo_v3_prefix_options);
metric=tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(ospf_lsa_tree, tvb, offset+2, 2,
"Metric: %u", metric);
offset+=4;
dissect_ospf_v3_address_prefix(tvb, offset, prefix_length, ospf_lsa_tree, address_family);
offset+=(prefix_length+31)/32*4;
number_prefixes--;
}
break;
case OSPF_V3_LSTYPE_OPAQUE_RI:
dissect_ospf_lsa_opaque_ri(tvb, offset, ospf_lsa_tree, ls_length);
break;
default:
proto_tree_add_text(ospf_lsa_tree, tvb, offset, ls_length,
"Unknown LSA Type 0x%04x",ls_type);
offset += ls_length;
break;
}
return offset;
}
static void dissect_ospf_v3_address_prefix(tvbuff_t *tvb, int offset, int prefix_length, proto_tree *tree,
guint8 address_family)
{
int bytes_to_process;
struct e_in6_addr prefix;
bytes_to_process=((prefix_length+31)/32)*4;
if (prefix_length > 128) {
proto_tree_add_text(tree, tvb, offset, bytes_to_process,
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
proto_tree_add_text(tree, tvb, offset, bytes_to_process,
"Address Prefix: %s", ip6_to_str(&prefix));
} else {
proto_tree_add_text(tree, tvb, offset, bytes_to_process,
"Address Prefix: %s", tvb_ip_to_str(tvb, offset));
}
}
void
proto_register_ospf(void)
{
static hf_register_info ospff_info[] = {
{&hf_ospf_filter[OSPFF_MSG_TYPE],
{ "Message Type", "ospf.msg", FT_UINT8, BASE_DEC, VALS(pt_vals), 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_MSG_HELLO],
{ "Hello", "ospf.msg.hello", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_MSG_DB_DESC],
{ "Database Description", "ospf.msg.dbdesc", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_MSG_LS_REQ],
{ "Link State Adv Request", "ospf.msg.lsreq", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_MSG_LS_UPD],
{ "Link State Adv Update", "ospf.msg.lsupdate", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_MSG_LS_ACK],
{ "Link State Adv Acknowledgement", "ospf.msg.lsack", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_TYPE],
{ "LS Type", "ospf.lsa", FT_UINT8, BASE_DEC,
VALS(ls_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_OPAQUE_TYPE],
{ "Link State ID Opaque Type", "ospf.lsid_opaque_type", FT_UINT8, BASE_DEC,
VALS(ls_opaque_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_TE_INSTANCE],
{ "Link State ID TE-LSA Instance", "ospf.lsid_te_lsa.instance", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_ROUTER],
{ "Router LSA", "ospf.lsa.router", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_NETWORK],
{ "Network LSA", "ospf.lsa.network", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_SUMMARY],
{ "Summary LSA (IP Network)", "ospf.lsa.summary", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_ASBR],
{ "Summary LSA (ASBR)", "ospf.lsa.asbr", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_ASEXT],
{ "AS-External LSA (ASBR)", "ospf.lsa.asext", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_GRPMEMBER],
{ "Group Membership LSA", "ospf.lsa.member", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_ASEXT7],
{ "NSSA AS-External LSA", "ospf.lsa.nssa", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_EXTATTR],
{ "External Attributes LSA", "ospf.lsa.attr", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_OPAQUE],
{ "Opaque LSA", "ospf.lsa.opaque", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_TYPE],
{ "LS Type", "ospf.v3.lsa", FT_UINT16, BASE_HEX,
VALS(v3_ls_type_vals), 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_ROUTER],
{ "Router-LSA", "ospf.v3.lsa.router", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_NETWORK],
{ "Network-LSA", "ospf.v3.lsa.network", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_INTER_AREA_PREFIX],
{ "Inter-Area-Prefix-LSA", "ospf.v3.lsa.interprefix", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_INTER_AREA_ROUTER],
{ "Inter-Area-Router-LSA", "ospf.v3.lsa.interrouter", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_AS_EXTERNAL],
{ "AS-External-LSA", "ospf.v3.lsa.asext", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_GROUP_MEMBERSHIP],
{ "Group-Membership-LSA", "ospf.v3.lsa.member", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_NSSA],
{ "NSSA-LSA", "ospf.v3.lsa.nssa", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_LINK],
{ "Link-LSA", "ospf.v3.lsa.link", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_INTRA_AREA_PREFIX],
{ "Intra-Area-Prefix-LSA", "ospf.v3.lsa.intraprefix", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LS_OPAQUE_RI],
{ "Router Information Opaque-LSA", "ospf.v3.lsa.opaque", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_SRC_ROUTER],
{ "Source OSPF Router", "ospf.srcrouter", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_ADV_ROUTER],
{ "Advertising Router", "ospf.advrouter", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS],
{ "MPLS Traffic Engineering LSA", "ospf.lsa.mpls", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_ROUTERID],
{ "MPLS/TE Router ID", "ospf.mpls.routerid", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_LINKTYPE],
{ "MPLS/TE Link Type", "ospf.mpls.linktype", FT_UINT8, BASE_DEC,
VALS(mpls_link_stlv_ltype_str), 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_LINKID],
{ "MPLS/TE Link ID", "ospf.mpls.linkid", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_LOCAL_ADDR],
{ "MPLS/TE Local Interface Address", "ospf.mpls.local_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_REMOTE_ADDR],
{ "MPLS/TE Remote Interface Address", "ospf.mpls.remote_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_LOCAL_IFID],
{ "MPLS/TE Local Interface Index", "ospf.mpls.local_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_REMOTE_IFID],
{ "MPLS/TE Remote Interface Index", "ospf.mpls.remote_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_LINKCOLOR],
{ "MPLS/TE Link Resource Class/Color", "ospf.mpls.linkcolor", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_MPLS_BC_MODEL_ID],
{ "MPLS/DSTE Bandwidth Constraints Model Id", "ospf.mpls.bc", FT_UINT8,
BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_link_stlv_bcmodel_rvals), 0x0,
NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_OIF_LOCAL_NODE_ID],
{ "Local Node ID", "ospf.oif.local_node_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LS_OIF_REMOTE_NODE_ID],
{ "Remote Node ID", "ospf.oif.remote_node_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS],
{ "Options", "ospf.v2.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_MT],
{ "MT", "ospf.v2.options.mt", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_mt), OSPF_V2_OPTIONS_MT, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_E],
{ "E", "ospf.v2.options.e", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_e), OSPF_V2_OPTIONS_E, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_MC],
{ "MC", "ospf.v2.options.mc", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_mc), OSPF_V2_OPTIONS_MC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_NP],
{ "NP", "ospf.v2.options.np", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_np), OSPF_V2_OPTIONS_NP, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_L],
{ "L", "ospf.v2.options.l", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_l), OSPF_V2_OPTIONS_L, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_DC],
{ "DC", "ospf.v2.options.dc", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_dc), OSPF_V2_OPTIONS_DC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_O],
{ "O", "ospf.v2.options.o", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_o), OSPF_V2_OPTIONS_O, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_OPTIONS_DN],
{ "DN", "ospf.v2.options.dn", FT_BOOLEAN, 8,
TFS(&tfs_v2_options_dn), OSPF_V2_OPTIONS_DN, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS],
{ "RI Options", "ospf.ri.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_GRC],
{ "GRC", "ospf.ri.options.grc", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_grc), OSPF_RI_OPTIONS_GRC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_GRH],
{ "GRH", "ospf.ri.options.grh", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_grh), OSPF_RI_OPTIONS_GRH, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_SRS],
{ "SRS", "ospf.ri.options.srs", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_srs), OSPF_RI_OPTIONS_SRS, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_TES],
{ "TES", "ospf.ri.options.tes", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_tes), OSPF_RI_OPTIONS_TES, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_P2PLAN],
{ "P2PLAN", "ospf.ri.options.p2plan", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_p2plan), OSPF_RI_OPTIONS_P2PLAN, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_RI_OPTIONS_ETE],
{ "ETE", "ospf.ri.options.ete", FT_BOOLEAN, 8,
TFS(&tfs_ri_options_ete), OSPF_RI_OPTIONS_ETE, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_OPAQUE_LSA_MBZ],
{ "MBZ", "ospf.ri.mbz", FT_UINT16, BASE_HEX,
NULL, 0x0, "OSPF Opaque RI LSA - 24 bits of Type Field Must be Zero", HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS],
{ "Options", "ospf.v3.options", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_V6],
{ "V6", "ospf.v3.options.v6", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_v6), OSPF_V3_OPTIONS_V6, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_E],
{ "E", "ospf.v3.options.e", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_e), OSPF_V3_OPTIONS_E, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_MC],
{ "MC", "ospf.v3.options.mc", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_mc), OSPF_V3_OPTIONS_MC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_N],
{ "N", "ospf.v3.options.n", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_n), OSPF_V3_OPTIONS_N, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_R],
{ "R", "ospf.v3.options.r", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_r), OSPF_V3_OPTIONS_R, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_DC],
{ "DC", "ospf.v3.options.dc", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_dc), OSPF_V3_OPTIONS_DC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_AF],
{ "AF", "ospf.v3.options.af", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_af), OSPF_V3_OPTIONS_AF, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_L],
{ "L", "ospf.v3.options.l", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_l), OSPF_V3_OPTIONS_L, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_I],
{ "I", "ospf.v3.options.i", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_i), OSPF_V3_OPTIONS_I, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_OPTIONS_F],
{ "F", "ospf.v3.options.f", FT_BOOLEAN, 24,
TFS(&tfs_v3_options_f), OSPF_V3_OPTIONS_F, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DBD],
{ "DB Description", "ospf.dbd", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DBD_R],
{ "R", "ospf.dbd.r", FT_BOOLEAN, 8,
TFS(&tfs_dbd_r), OSPF_DBD_FLAG_R, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DBD_I],
{ "I", "ospf.dbd.i", FT_BOOLEAN, 8,
TFS(&tfs_dbd_i), OSPF_DBD_FLAG_I, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DBD_M],
{ "M", "ospf.dbd.m", FT_BOOLEAN, 8,
TFS(&tfs_dbd_m), OSPF_DBD_FLAG_M, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DBD_MS],
{ "MS", "ospf.dbd.ms", FT_BOOLEAN, 8,
TFS(&tfs_dbd_ms), OSPF_DBD_FLAG_MS, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LLS_EXT_OPTIONS],
{ "Options", "ospf.lls.ext.options", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LLS_EXT_OPTIONS_LR],
{ "LR", "ospf.lls.ext.options.lr", FT_BOOLEAN, 32,
TFS(&tfs_lls_ext_options_lr), OSPF_LLS_EXT_OPTIONS_LR, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_LLS_EXT_OPTIONS_RS],
{ "RS", "ospf.lls.ext.options.rs", FT_BOOLEAN, 32,
TFS(&tfs_lls_ext_options_rs), OSPF_LLS_EXT_OPTIONS_RS, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG],
{ "Flags", "ospf.v2.router.lsa.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG_B],
{ "B", "ospf.v2.router.lsa.flags.b", FT_BOOLEAN, 8,
TFS(&tfs_v2_router_lsa_flags_b), OSPF_V2_ROUTER_LSA_FLAG_B, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG_E],
{ "E", "ospf.v2.router.lsa.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_v2_router_lsa_flags_e), OSPF_V2_ROUTER_LSA_FLAG_E, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG_V],
{ "V", "ospf.v2.router.lsa.flags.v", FT_BOOLEAN, 8,
TFS(&tfs_v2_router_lsa_flags_v), OSPF_V2_ROUTER_LSA_FLAG_V, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG_W],
{ "W", "ospf.v2.router.lsa.flags.w", FT_BOOLEAN, 8,
TFS(&tfs_v2_router_lsa_flags_w), OSPF_V2_ROUTER_LSA_FLAG_W, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_ROUTER_LSA_FLAG_N],
{ "N", "ospf.v2.router.lsa.flags.n", FT_BOOLEAN, 8,
TFS(&tfs_v2_router_lsa_flags_n), OSPF_V2_ROUTER_LSA_FLAG_N, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_ROUTER_LSA_FLAG],
{ "Flags", "ospf.v3.router.lsa.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_ROUTER_LSA_FLAG_B],
{ "B", "ospf.v3.router.lsa.flags.b", FT_BOOLEAN, 8,
TFS(&tfs_v3_router_lsa_flags_b), OSPF_V3_ROUTER_LSA_FLAG_B, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_ROUTER_LSA_FLAG_E],
{ "E", "ospf.v3.router.lsa.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_v3_router_lsa_flags_e), OSPF_V3_ROUTER_LSA_FLAG_E, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_ROUTER_LSA_FLAG_V],
{ "V", "ospf.v3.router.lsa.flags.v", FT_BOOLEAN, 8,
TFS(&tfs_v3_router_lsa_flags_v), OSPF_V3_ROUTER_LSA_FLAG_V, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_ROUTER_LSA_FLAG_W],
{ "W", "ospf.v3.router.lsa.flags.w", FT_BOOLEAN, 8,
TFS(&tfs_v3_router_lsa_flags_w), OSPF_V3_ROUTER_LSA_FLAG_W, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_AS_EXTERNAL_FLAG],
{ "Flags", "ospf.v3.as.external.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_AS_EXTERNAL_FLAG_T],
{ "T", "ospf.v3.as.external.flags.t", FT_BOOLEAN, 8,
TFS(&tfs_v3_as_external_flags_t), OSPF_V3_AS_EXTERNAL_FLAG_T, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_AS_EXTERNAL_FLAG_F],
{ "F", "ospf.v3.as.external.flags.f", FT_BOOLEAN, 8,
TFS(&tfs_v3_as_external_flags_f), OSPF_V3_AS_EXTERNAL_FLAG_F, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_AS_EXTERNAL_FLAG_E],
{ "E", "ospf.v3.as.external.flags.e", FT_BOOLEAN, 8,
TFS(&tfs_v3_as_external_flags_e), OSPF_V3_AS_EXTERNAL_FLAG_E, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_PREFIX_OPTION],
{ "PrefixOptions", "ospf.v3.prefix.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_PREFIX_OPTION_NU],
{ "NU", "ospf.v3.prefix.options.nu", FT_BOOLEAN, 8,
TFS(&tfs_v3_prefix_options_nu), OSPF_V3_PREFIX_OPTION_NU, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_PREFIX_OPTION_LA],
{ "LA", "ospf.v3.prefix.options.la", FT_BOOLEAN, 8,
TFS(&tfs_v3_prefix_options_la), OSPF_V3_PREFIX_OPTION_LA, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_PREFIX_OPTION_MC],
{ "MC", "ospf.v3.prefix.options.mc", FT_BOOLEAN, 8,
TFS(&tfs_v3_prefix_options_mc), OSPF_V3_PREFIX_OPTION_MC, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_PREFIX_OPTION_P],
{ "P", "ospf.v3.prefix.options.p", FT_BOOLEAN, 8,
TFS(&tfs_v3_prefix_options_p), OSPF_V3_PREFIX_OPTION_P, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_DYN_HOSTNAME],
{ "Dynamic Hostname", "ospf.dynhostname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_UNKNOWN_TLV_TXT],
{ "Text in the Unknown TLV", "ospf.unknown_text", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V2_GRACE_TLV],
{ "Grace TLV", "ospf.v2.grace", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_ospf_filter[OSPFF_V2_GRACE_PERIOD],
{ "Grace Period", "ospf.v2.grace.period", FT_UINT32, BASE_DEC,
NULL, 0x0,
"The number of seconds neighbors should advertise the router as fully adjacent",
HFILL }},
{&hf_ospf_filter[OSPFF_V2_GRACE_REASON],
{ "Restart Reason", "ospf.v2.grace.reason", FT_UINT8, BASE_DEC,
VALS(restart_reason_vals), 0x0, "The reason the router is restarting", HFILL }},
{&hf_ospf_filter[OSPFF_V2_GRACE_IP],
{ "Restart IP", "ospf.v2.grace.ip", FT_IPv4, BASE_NONE,
NULL, 0x0, "The IP address of the interface originating this LSA", HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_EXT_OPTIONS_TLV],
{ "Extended Options TLV", "ospf.v3.lls.ext.options.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_EXT_OPTIONS],
{ "Options", "ospf.v3.lls.ext.options", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_EXT_OPTIONS_LR],
{ "LR", "ospf.v3.lls.ext.options.lr", FT_BOOLEAN, 32,
TFS(&tfs_v3_lls_ext_options_lr), OSPF_V3_LLS_EXT_OPTIONS_LR, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_EXT_OPTIONS_RS],
{ "RS", "ospf.v3.lls.ext.options.rs", FT_BOOLEAN, 32,
TFS(&tfs_v3_lls_ext_options_rs), OSPF_V3_LLS_EXT_OPTIONS_RS, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_TLV],
{ "State Check Sequence TLV", "ospf.v3.lls.state.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_SCS],
{ "SCS Number", "ospf.v3.lls.state.scs", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_OPTIONS],
{ "Options", "ospf.v3.lls.state.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_OPTIONS_R],
{ "R", "ospf.v3.lls.state.options.r", FT_BOOLEAN, 8,
TFS(&tfs_v3_lls_state_options_r), OSPF_V3_LLS_STATE_OPTIONS_R, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_OPTIONS_A],
{ "A", "ospf.v3.lls.state.options.a", FT_BOOLEAN, 8,
TFS(&tfs_v3_lls_state_options_a), OSPF_V3_LLS_STATE_OPTIONS_A , NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_STATE_OPTIONS_N],
{ "N", "ospf.v3.lls.state.options.n", FT_BOOLEAN, 8,
TFS(&tfs_v3_lls_state_options_n), OSPF_V3_LLS_STATE_OPTIONS_N ,NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_DROP_TLV],
{ "Neighbor Drop TLV", "ospf.v3.lls.drop.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RELAY_TLV],
{ "Active Overlapping Relays TLV", "ospf.v3.lls.relay.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RELAY_ADDED],
{ "Relays Added", "ospf.v3.lls.relay.added", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RELAY_OPTIONS],
{ "Options", "ospf.v3.lls.relay.options", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RELAY_OPTIONS_A],
{ "A", "ospf.v3.lls.relay.options.a", FT_BOOLEAN, 8,
TFS(&tfs_v3_lls_relay_options_a), OSPF_V3_LLS_RELAY_OPTIONS_A , NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RELAY_OPTIONS_N],
{ "N", "ospf.v3.lls.relay.options.n", FT_BOOLEAN, 8,
TFS(&tfs_v3_lls_relay_options_n), OSPF_V3_LLS_RELAY_OPTIONS_N ,NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_WILLINGNESS_TLV],
{ "Willingness TLV", "ospf.v3.lls.willingness.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_WILLINGNESS],
{ "Willingness", "ospf.v3.lls.willingness", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_RF_TLV],
{ "Request From TLV", "ospf.v3.lls.rf.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&hf_ospf_filter[OSPFF_V3_LLS_FSF_TLV],
{ "Full State For TLV", "ospf.v3.lls.fsf.tlv", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ospf,
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
&ett_ospf_lsa_dyn_hostname_tlv,
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
proto_ospf = proto_register_protocol("Open Shortest Path First",
"OSPF", "ospf");
proto_register_field_array(proto_ospf, ospff_info, array_length(ospff_info));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ospf(void)
{
dissector_handle_t ospf_handle;
ospf_handle = create_dissector_handle(dissect_ospf, proto_ospf);
dissector_add_uint("ip.proto", IP_PROTO_OSPF, ospf_handle);
data_handle = find_dissector("data");
}
