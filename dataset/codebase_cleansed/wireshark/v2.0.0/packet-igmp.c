void igmp_checksum(proto_tree *tree, tvbuff_t *tvb, int hf_index,
int hf_index_bad, packet_info *pinfo, guint len)
{
guint16 cksum, hdrcksum;
vec_t cksum_vec[1];
proto_item *hidden_item;
if (len == 0) {
len = tvb_reported_length(tvb);
}
hdrcksum = tvb_get_ntohs(tvb, 2);
if (!pinfo->fragmented && tvb_captured_length(tvb) >= len) {
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, len);
cksum = in_cksum(&cksum_vec[0],1);
if (cksum == 0) {
proto_tree_add_uint_format(tree, hf_index, tvb, 2, 2, hdrcksum,
"Header checksum: 0x%04x [correct]", hdrcksum);
} else {
hidden_item = proto_tree_add_boolean(tree, hf_index_bad,
tvb, 2, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint_format(tree, hf_index, tvb, 2, 2, hdrcksum,
"Header checksum: 0x%04x [incorrect, should be 0x%04x]",
hdrcksum, in_cksum_shouldbe(hdrcksum,cksum));
}
} else
proto_tree_add_uint(tree, hf_index, tvb, 2, 2, hdrcksum);
return;
}
static proto_tree*
dissect_igmp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int* offset, unsigned char* type, int version)
{
proto_item* ti;
proto_tree* igmp_tree;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "IGMPv%d", version);
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_igmp, tvb, 0, -1, ENC_NA);
igmp_tree = proto_item_add_subtree(ti, ett_igmp);
*type = tvb_get_guint8(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(*type, commands, "Unknown Type:0x%02x"));
ti = proto_tree_add_uint(igmp_tree, hf_version, tvb, 0, 0, version);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(igmp_tree, hf_type, tvb, 0, 1, ENC_BIG_ENDIAN);
*offset = 1;
return igmp_tree;
}
static int
dissect_igmp_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item* ti;
proto_tree* tree;
int len;
int offset = 0;
unsigned char type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IGMP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(parent_tree, proto_igmp, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_igmp);
type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, commands, "Unknown Type:0x%02x"));
proto_tree_add_uint(tree, hf_type, tvb, offset, 1, type);
offset += 1;
len = tvb_captured_length_remaining(tvb, offset);
proto_tree_add_item(tree, hf_data, tvb, offset, -1, ENC_NA);
offset += len;
return offset;
}
static int
dissect_v3_max_resp(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
proto_tree *tree;
proto_item *item;
guint8 bits;
guint32 tsecs;
bits = tvb_get_guint8(tvb, offset);
if (bits&0x80) {
tsecs = ((bits&IGMP_MAX_RESP_MANT)|0x10);
tsecs = tsecs << ( ((bits&IGMP_MAX_RESP_EXP)>>4) + 3);
} else {
tsecs = bits;
}
item = proto_tree_add_uint_format_value(parent_tree, hf_max_resp, tvb,
offset, 1, tsecs, "%.1f sec (0x%02x)",tsecs*0.1,bits);
if (bits&0x80) {
tree = proto_item_add_subtree(item, ett_max_resp);
proto_tree_add_uint(tree, hf_max_resp_exp, tvb, offset, 1,
bits);
proto_tree_add_uint(tree, hf_max_resp_mant, tvb, offset, 1,
bits);
}
offset += 1;
return offset;
}
static int
dissect_v3_sqrv_bits(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
static const int * bits[] = {
&hf_suppress,
&hf_qrv,
NULL
};
proto_tree_add_bitmask_list(parent_tree, tvb, offset, 1, bits, ENC_NA);
offset += 1;
return offset;
}
static int
dissect_v3_group_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
proto_tree *tree;
proto_item *item;
int old_offset = offset;
guint8 adl;
guint16 num;
const gchar *maddr_str;
guint8 record_type;
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, -1,
ett_group_record, &item, "Group Record : %s %s",
tvb_ip_to_str(tvb, offset+4),
val_to_str_const(tvb_get_guint8(tvb, offset), vs_record_type,"")
);
record_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_record_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
adl = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_aux_data_len, tvb, offset, 1, adl);
offset += 1;
num = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_num_src, tvb, offset, 2, num);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
maddr_str = tvb_ip_to_str(tvb, offset);
offset += 4;
if (num == 0) {
switch(record_type) {
case IGMP_V3_MODE_IS_INCLUDE:
case IGMP_V3_CHANGE_TO_INCLUDE_MODE:
col_append_fstr(pinfo->cinfo, COL_INFO, " / Leave group %s", maddr_str);
break;
case IGMP_V3_MODE_IS_EXCLUDE:
case IGMP_V3_CHANGE_TO_EXCLUDE_MODE:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Join group %s for any sources", maddr_str);
break;
case IGMP_V3_ALLOW_NEW_SOURCES:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, ALLOW_NEW_SOURCES but no source specified (?)",
maddr_str);
break;
case IGMP_V3_BLOCK_OLD_SOURCES:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, BLOCK_OLD_SOURCES but no source specified (?)",
maddr_str);
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, unknown record type (?)", maddr_str);
break;
}
} else {
switch(record_type) {
case IGMP_V3_MODE_IS_INCLUDE:
case IGMP_V3_CHANGE_TO_INCLUDE_MODE:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Join group %s for source%s {",
maddr_str, (num>1) ? "s in" : "");
break;
case IGMP_V3_MODE_IS_EXCLUDE:
case IGMP_V3_CHANGE_TO_EXCLUDE_MODE:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Join group %s, for source%s {",
maddr_str, (num>1) ? "s not in" : " not");
break;
case IGMP_V3_ALLOW_NEW_SOURCES:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, new source%s {",
maddr_str, (num>1) ? "s" : "");
break;
case IGMP_V3_BLOCK_OLD_SOURCES:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, block source%s {",
maddr_str, (num>1) ? "s" : "");
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO,
" / Group %s, unknown record type (?), sources {",
maddr_str);
break;
}
}
while(num--){
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
tvb_ip_to_str(tvb, offset), (num?", ":"}"));
proto_tree_add_item(tree, hf_saddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if(adl){
proto_tree_add_item(tree, hf_aux_data, tvb, offset, adl*4, ENC_NA);
offset += adl*4;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_igmp_v3_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
guint16 num;
int offset;
unsigned char type;
tree = dissect_igmp_common(tvb, pinfo, parent_tree, &offset, &type, 3);
proto_tree_add_item(tree, hf_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
proto_tree_add_item(tree, hf_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
num = tvb_get_ntohs(tvb, offset);
if (!num)
col_append_str(pinfo->cinfo, COL_INFO, " - General query");
proto_tree_add_uint(tree, hf_num_grp_recs, tvb, offset, 2, num);
offset += 2;
while (num--)
offset = dissect_v3_group_record(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_igmp_v3_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
guint16 num;
int offset;
unsigned char type;
tree = dissect_igmp_common(tvb, pinfo, parent_tree, &offset, &type, 3);
num = tvb_get_ntohs(tvb, offset+9);
offset = dissect_v3_max_resp(tvb, tree, offset);
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
if (!tvb_get_ipv4(tvb, offset)) {
col_append_str(pinfo->cinfo, COL_INFO, ", general");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", specific for group %s",
tvb_ip_to_str(tvb, offset));
}
offset +=4;
offset = dissect_v3_sqrv_bits(tvb, tree, offset);
proto_tree_add_item(tree, hf_qqic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(tree, hf_num_src, tvb, offset, 2, num);
if (num) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", source%s {", (num>1)?"s":"");
}
offset += 2;
while(num--){
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s", tvb_ip_to_str(tvb, offset), (num?", ":"}"));
proto_tree_add_item(tree, hf_saddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
dissect_igmp_v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
guint8 tsecs;
int offset;
unsigned char type;
tree = dissect_igmp_common(tvb, pinfo, parent_tree, &offset, &type, 2);
tsecs = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_max_resp, tvb,
offset, 1, tsecs, "%.1f sec (0x%02x)", tsecs*0.1,tsecs);
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 8);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
if (! tvb_get_ipv4(tvb, offset)) {
col_append_str(pinfo->cinfo, COL_INFO, ", general");
} else {
switch(type)
{
case IGMP_V2_LEAVE_GROUP:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", tvb_ip_to_str(tvb, offset));
break;
case IGMP_V1_HOST_MEMBERSHIP_QUERY:
col_append_fstr(pinfo->cinfo, COL_INFO, ", specific for group %s", tvb_ip_to_str(tvb, offset));
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO, " group %s", tvb_ip_to_str(tvb, offset));
break;
}
}
offset +=4;
return offset;
}
static int
dissect_igmp_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
int offset;
unsigned char type;
tree = dissect_igmp_common(tvb, pinfo, parent_tree, &offset, &type, 1);
proto_tree_add_item(tree, hf_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 8);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
return offset;
}
static int
dissect_igmp_v0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
unsigned char code;
int offset;
unsigned char type;
tree = dissect_igmp_common(tvb, pinfo, parent_tree, &offset, &type, 0);
code = tvb_get_guint8(tvb, offset);
if (type==IGMP_V0_CREATE_GROUP_REQUEST) {
proto_tree_add_uint(tree, hf_group_type, tvb, offset, 1, code);
} else if (!(type&0x01)) {
if (code <5) {
proto_tree_add_uint(tree, hf_reply_code, tvb, offset, 1, code);
} else {
proto_tree_add_uint(tree, hf_reply_pending, tvb, offset, 1, code);
}
}
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 20);
offset += 2;
proto_tree_add_item(tree, hf_identifier, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_access_key, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int
dissect_igmp_mquery(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
if ( tvb_reported_length(tvb)>=12 ) {
return dissect_igmp_v3_query(tvb, pinfo, parent_tree, data);
}
if (tvb_get_guint8(tvb, 1)) {
return dissect_igmp_v2(tvb, pinfo, parent_tree, data);
}
return dissect_igmp_v1(tvb, pinfo, parent_tree, data);
}
static int
dissect_igmp_mtrace(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree* tree;
proto_item* ti;
int offset = 0;
unsigned char type;
const char *typestr, *blocks = NULL;
char buf[20];
ti = proto_tree_add_item(parent_tree, proto_igmp, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_igmp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IGMP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, offset);
if (type == IGMP_TRACEROUTE_RESPONSE) {
int i = (tvb_reported_length_remaining(tvb, offset) - IGMP_TRACEROUTE_HDR_LEN) / IGMP_TRACEROUTE_RSP_LEN;
g_snprintf(buf, sizeof buf, ", %d block%s", i, plurality(i, "", "s"));
typestr = "Traceroute Response";
blocks = buf;
} else if (tvb_reported_length_remaining(tvb, offset) == IGMP_TRACEROUTE_HDR_LEN)
typestr = "Traceroute Query";
else
typestr = "Traceroute Request";
col_set_str(pinfo->cinfo, COL_INFO, typestr);
if (blocks)
col_append_str(pinfo->cinfo, COL_INFO, blocks);
proto_tree_add_uint_format_value(tree, hf_type, tvb, offset, 1, type,
"%s (0x%02x)", typestr, type);
offset += 1;
proto_tree_add_item(tree, hf_mtrace_max_hops, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mtrace_saddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mtrace_raddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mtrace_rspaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mtrace_resp_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mtrace_q_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if (tvb_reported_length_remaining(tvb, offset) == 0)
return offset;
while (tvb_reported_length_remaining(tvb, offset) >= IGMP_TRACEROUTE_RSP_LEN) {
proto_tree *block_tree;
block_tree = proto_tree_add_subtree_format(tree, tvb, offset, IGMP_TRACEROUTE_RSP_LEN,
ett_mtrace_block, NULL, "Response data block: %s -> %s, Proto: %s, Forwarding Code: %s",
tvb_ip_to_str(tvb, offset + 4),
tvb_ip_to_str(tvb, offset + 8),
val_to_str_const(tvb_get_guint8(tvb, offset + 28), mtrace_rtg_vals, "Unknown"),
val_to_str_const(tvb_get_guint8(tvb, offset + 31), mtrace_fwd_code_vals, "Unknown"));
proto_tree_add_item(block_tree, hf_mtrace_q_arrival, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_inaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_outaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_prevrtr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_inpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_outpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_total, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mtrace_q_rtg_proto, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(block_tree, hf_mtrace_q_fwd_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(block_tree, hf_mtrace_q_mbz, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(block_tree, hf_mtrace_q_s, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(block_tree, hf_mtrace_q_src_mask, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(block_tree, hf_mtrace_q_fwd_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
return offset;
}
static void
dissect_igmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
unsigned char type;
type = tvb_get_guint8(tvb, offset);
if (!dissector_try_uint(subdissector_table, type, tvb, pinfo, parent_tree))
{
dissect_igmp_unknown(tvb, pinfo, parent_tree);
}
}
void
proto_register_igmp(void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "igmp.type", FT_UINT8, BASE_HEX,
VALS(commands), 0, "IGMP Packet Type", HFILL }},
{ &hf_reserved,
{ "Reserved", "igmp.reserved", FT_BYTES, BASE_NONE,
NULL, 0, "IGMP Reserved", HFILL }},
{ &hf_version,
{ "IGMP Version", "igmp.version", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_group_type,
{ "Type Of Group", "igmp.group_type", FT_UINT8, BASE_DEC,
VALS(vs_group_type), 0, "IGMP V0 Type Of Group", HFILL }},
{ &hf_reply_code,
{ "Reply", "igmp.reply", FT_UINT8, BASE_DEC,
VALS(vs_reply_code), 0, "IGMP V0 Reply", HFILL }},
{ &hf_reply_pending,
{ "Reply Pending", "igmp.reply.pending", FT_UINT8, BASE_DEC,
NULL, 0, "IGMP V0 Reply Pending, Retry in this many seconds", HFILL }},
{ &hf_checksum,
{ "Checksum", "igmp.checksum", FT_UINT16, BASE_HEX,
NULL, 0, "IGMP Checksum", HFILL }},
{ &hf_checksum_bad,
{ "Bad Checksum", "igmp.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Bad IGMP Checksum", HFILL }},
{ &hf_identifier,
{ "Identifier", "igmp.identifier", FT_UINT32, BASE_DEC,
NULL, 0, "IGMP V0 Identifier", HFILL }},
{ &hf_access_key,
{ "Access Key", "igmp.access_key", FT_BYTES, BASE_NONE,
NULL, 0, "IGMP V0 Access Key", HFILL }},
{ &hf_max_resp,
{ "Max Resp Time", "igmp.max_resp", FT_UINT8, BASE_DEC,
NULL, 0, "Max Response Time", HFILL }},
{ &hf_suppress,
{ "S", "igmp.s", FT_BOOLEAN, 8,
TFS(&tfs_s), IGMP_V3_S, "Suppress Router Side Processing", HFILL }},
{ &hf_qrv,
{ "QRV", "igmp.qrv", FT_UINT8, BASE_DEC,
NULL, IGMP_V3_QRV_MASK, "Querier's Robustness Value", HFILL }},
{ &hf_qqic,
{ "QQIC", "igmp.qqic", FT_UINT8, BASE_DEC,
NULL, 0, "Querier's Query Interval Code", HFILL }},
{ &hf_num_src,
{ "Num Src", "igmp.num_src", FT_UINT16, BASE_DEC,
NULL, 0, "Number Of Sources", HFILL }},
{ &hf_saddr,
{ "Source Address", "igmp.saddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_num_grp_recs,
{ "Num Group Records", "igmp.num_grp_recs", FT_UINT16, BASE_DEC,
NULL, 0, "Number Of Group Records", HFILL }},
{ &hf_record_type,
{ "Record Type", "igmp.record_type", FT_UINT8, BASE_DEC,
VALS(vs_record_type), 0, NULL, HFILL }},
{ &hf_aux_data_len,
{ "Aux Data Len", "igmp.aux_data_len", FT_UINT8, BASE_DEC,
NULL, 0, "Aux Data Len, In units of 32bit words", HFILL }},
{ &hf_maddr,
{ "Multicast Address", "igmp.maddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_aux_data,
{ "Aux Data", "igmp.aux_data", FT_BYTES, BASE_NONE,
NULL, 0, "IGMP V3 Auxiliary Data", HFILL }},
{ &hf_data,
{ "Data", "igmp.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_max_resp_exp,
{ "Exponent", "igmp.max_resp.exp", FT_UINT8, BASE_HEX,
NULL, IGMP_MAX_RESP_EXP, "Maximum Response Time, Exponent", HFILL }},
{ &hf_max_resp_mant,
{ "Mantissa", "igmp.max_resp.mant", FT_UINT8, BASE_HEX,
NULL, IGMP_MAX_RESP_MANT, "Maximum Response Time, Mantissa", HFILL }},
{ &hf_mtrace_max_hops,
{ "# hops", "igmp.mtrace.max_hops", FT_UINT8, BASE_DEC,
NULL, 0, "Maximum Number of Hops to Trace", HFILL }},
{ &hf_mtrace_saddr,
{ "Source Address", "igmp.mtrace.saddr", FT_IPv4, BASE_NONE,
NULL, 0, "Multicast Source for the Path Being Traced", HFILL }},
{ &hf_mtrace_raddr,
{ "Receiver Address", "igmp.mtrace.raddr", FT_IPv4, BASE_NONE,
NULL, 0, "Multicast Receiver for the Path Being Traced", HFILL }},
{ &hf_mtrace_rspaddr,
{ "Response Address", "igmp.mtrace.rspaddr", FT_IPv4, BASE_NONE,
NULL, 0, "Destination of Completed Traceroute Response", HFILL }},
{ &hf_mtrace_resp_ttl,
{ "Response TTL", "igmp.mtrace.resp_ttl", FT_UINT8, BASE_DEC,
NULL, 0, "TTL for Multicasted Responses", HFILL }},
{ &hf_mtrace_q_id,
{ "Query ID", "igmp.mtrace.q_id", FT_UINT24, BASE_DEC,
NULL, 0, "Identifier for this Traceroute Request", HFILL }},
{ &hf_mtrace_q_arrival,
{ "Query Arrival", "igmp.mtrace.q_arrival", FT_UINT32, BASE_DEC,
NULL, 0, "Query Arrival Time", HFILL }},
{ &hf_mtrace_q_inaddr,
{ "In itf addr", "igmp.mtrace.q_inaddr", FT_IPv4, BASE_NONE,
NULL, 0, "Incoming Interface Address", HFILL }},
{ &hf_mtrace_q_outaddr,
{ "Out itf addr", "igmp.mtrace.q_outaddr", FT_IPv4, BASE_NONE,
NULL, 0, "Outgoing Interface Address", HFILL }},
{ &hf_mtrace_q_prevrtr,
{ "Previous rtr addr", "igmp.mtrace.q_prevrtr", FT_IPv4, BASE_NONE,
NULL, 0, "Previous-Hop Router Address", HFILL }},
{ &hf_mtrace_q_inpkt,
{ "In pkts", "igmp.mtrace.q_inpkt", FT_UINT32, BASE_DEC,
NULL, 0, "Input packet count on incoming interface", HFILL }},
{ &hf_mtrace_q_outpkt,
{ "Out pkts", "igmp.mtrace.q_outpkt", FT_UINT32, BASE_DEC,
NULL, 0, "Output packet count on outgoing interface", HFILL }},
{ &hf_mtrace_q_total,
{ "S,G pkt count", "igmp.mtrace.q_total", FT_UINT32, BASE_DEC,
NULL, 0, "Total number of packets for this source-group pair", HFILL }},
{ &hf_mtrace_q_rtg_proto,
{ "Rtg Protocol", "igmp.mtrace.q_rtg_proto", FT_UINT8, BASE_DEC,
VALS(mtrace_rtg_vals), 0, "Routing protocol between this and previous hop rtr", HFILL }},
{ &hf_mtrace_q_fwd_ttl,
{ "FwdTTL", "igmp.mtrace.q_fwd_ttl", FT_UINT8, BASE_DEC,
NULL, 0, "TTL required for forwarding", HFILL }},
{ &hf_mtrace_q_mbz,
{ "MBZ", "igmp.mtrace.q_mbz", FT_UINT8, BASE_HEX,
NULL, 0x80, "Must be zeroed on transmission and ignored on reception", HFILL }},
{ &hf_mtrace_q_s,
{ "S", "igmp.mtrace.q_s", FT_UINT8, BASE_HEX,
NULL, 0x40, "Set if S,G packet count is for source network", HFILL }},
{ &hf_mtrace_q_src_mask,
{ "Src Mask", "igmp.mtrace.q_src_mask", FT_UINT8, BASE_HEX,
NULL, 0x3F, "Source mask length. 63 when forwarding on group state", HFILL }},
{ &hf_mtrace_q_fwd_code,
{ "Forwarding Code", "igmp.mtrace.q_fwd_code", FT_UINT8, BASE_HEX,
VALS(mtrace_fwd_code_vals), 0, "Forwarding information/error code", HFILL }},
};
static gint *ett[] = {
&ett_igmp,
&ett_group_record,
&ett_max_resp,
&ett_mtrace_block,
};
proto_igmp = proto_register_protocol("Internet Group Management Protocol",
"IGMP", "igmp");
proto_register_field_array(proto_igmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
subdissector_table = register_dissector_table("igmp.type", "IGMP commands", FT_UINT32, BASE_HEX);
}
void
proto_reg_handoff_igmp(void)
{
dissector_handle_t igmp_handle, igmpv0_handle, igmpv1_handle, igmpv2_handle,
igmp_mquery_handle, igmp_mtrace_handle, igmp_report_handle;
range_t *igmpv0_range = NULL;
igmp_handle = create_dissector_handle(dissect_igmp, proto_igmp);
dissector_add_uint("ip.proto", IP_PROTO_IGMP, igmp_handle);
range_convert_str(&igmpv0_range, "0-15", 15);
igmpv0_handle = new_create_dissector_handle(dissect_igmp_v0, proto_igmp);
dissector_add_uint_range("igmp.type", igmpv0_range, igmpv0_handle);
g_free(igmpv0_range);
igmpv1_handle = new_create_dissector_handle(dissect_igmp_v1, proto_igmp);
dissector_add_uint("igmp.type", IGMP_V1_HOST_MEMBERSHIP_REPORT, igmpv1_handle);
igmpv2_handle = new_create_dissector_handle(dissect_igmp_v2, proto_igmp);
dissector_add_uint("igmp.type", IGMP_V2_MEMBERSHIP_REPORT, igmpv2_handle);
dissector_add_uint("igmp.type", IGMP_V2_LEAVE_GROUP, igmpv2_handle);
igmp_mquery_handle = new_create_dissector_handle(dissect_igmp_mquery, proto_igmp);
dissector_add_uint("igmp.type", IGMP_V1_HOST_MEMBERSHIP_QUERY, igmp_mquery_handle);
igmp_report_handle = new_create_dissector_handle(dissect_igmp_v3_report, proto_igmp);
dissector_add_uint("igmp.type", IGMP_V3_MEMBERSHIP_REPORT, igmp_report_handle);
igmp_mtrace_handle = new_create_dissector_handle(dissect_igmp_mtrace, proto_igmp);
dissector_add_uint("igmp.type", IGMP_TRACEROUTE_RESPONSE, igmp_mtrace_handle);
dissector_add_uint("igmp.type", IGMP_TRACEROUTE_QUERY_REQ, igmp_mtrace_handle);
}
