static gint
dissect_ancp_tlv(tvbuff_t *tvb, proto_tree *tlv_tree, gint offset)
{
guint16 tlen, ttype;
gint16 num_stlvs;
proto_item *tti;
proto_tree_add_item(tlv_tree, hf_ancp_ext_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
ttype = tvb_get_ntohs(tvb, offset);
offset += 2;
tti = proto_tree_add_item(tlv_tree, hf_ancp_ext_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
tlen = tvb_get_ntohs(tvb, offset);
offset += 2;
switch (ttype) {
case TLV_DSL_LINE_ATTRIBUTES:
{
proto_tree *dsl_tree;
guint16 stlvtype, stlvlen;
gint val;
dsl_tree = proto_item_add_subtree(tti, ett_ancp_ext_tlv_type);
num_stlvs = tlen / 8;
for ( ;num_stlvs; num_stlvs--) {
proto_tree_add_item(dsl_tree,
hf_ancp_dsl_line_stlv_type, tvb, offset,
2, ENC_BIG_ENDIAN);
stlvtype = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(dsl_tree,
hf_ancp_dsl_line_stlv_len, tvb, offset,
2, ENC_BIG_ENDIAN);
stlvlen = tvb_get_ntohs(tvb, offset);
offset += 2;
tti = proto_tree_add_item(dsl_tree,
hf_ancp_dsl_line_stlv_value, tvb, offset,
stlvlen, ENC_BIG_ENDIAN);
val = tvb_get_ntohl(tvb, offset);
offset += stlvlen;
switch (stlvtype) {
case TLV_DSL_LINE_STATE:
proto_item_append_text(tti, " (%s)",
val_to_str(val, dsl_line_state_names,
"Unknown (0x%02x)"));
break;
case TLV_DSL_TYPE:
proto_item_append_text(tti, " (%s)",
val_to_str(val, dsl_line_type_names,
"Unknown (0x%02x)"));
break;
default:
proto_item_append_text(tti, " %s",
val_to_str(stlvtype,
dsl_line_attr_units,
"Unknown (0x%02x)"));
break;
}
SKIPPADDING(offset, stlvlen);
}
break;
}
case TLV_PING_OPAQUE_DATA:
proto_tree_add_item(tlv_tree, hf_ancp_oam_opaque,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tlv_tree, hf_ancp_oam_opaque,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case TLV_PING_PARAMS:
proto_tree_add_item(tlv_tree,
hf_ancp_oam_loopb_cnt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tlv_tree,
hf_ancp_oam_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 2;
break;
default:
proto_tree_add_item(tlv_tree, hf_ancp_ext_tlv_value_str,
tvb, offset, tlen, ENC_ASCII|ENC_NA);
offset += tlen;
SKIPPADDING(offset, tlen);
break;
}
return offset;
}
static void
dissect_ancp_port_up_dn_mgmt(tvbuff_t *tvb, proto_tree *ancp_tree, gint offset, guint8 mtype)
{
guint8 tech_type;
gint16 num_tlvs;
proto_item *sti;
if (mtype == ANCP_MTYPE_PORT_MGMT) {
proto_tree_add_item(ancp_tree, hf_ancp_pudm_unused, tvb, offset, 14, ENC_NA);
offset += 14;
proto_tree_add_item(ancp_tree, hf_ancp_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_x_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_pudm_unused, tvb, offset, 4, ENC_NA);
offset += 4;
} else {
proto_tree_add_item(ancp_tree, hf_ancp_pudm_unused, tvb, offset, 20, ENC_NA);
offset += 20;
}
proto_tree_add_item(ancp_tree, hf_ancp_ext_flags_res, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_mtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (mtype == ANCP_MTYPE_PORT_MGMT) {
proto_tree_add_item(ancp_tree, hf_ancp_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
tech_type = 0;
} else {
proto_tree_add_item(ancp_tree, hf_ancp_tech_type, tvb, offset, 1, ENC_BIG_ENDIAN);
tech_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
}
proto_tree_add_item(ancp_tree, hf_ancp_num_ext_tlvs, tvb, offset, 2, ENC_BIG_ENDIAN);
num_tlvs = tvb_get_ntohs(tvb, offset);
offset += 2;
sti = proto_tree_add_item(ancp_tree, hf_ancp_blk_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tech_type == TECH_TYPE_DSL || tech_type == TECH_TYPE_PON) {
proto_tree *tlv_tree;
tlv_tree = proto_item_add_subtree(sti, ett_ancp_len);
for( ;num_tlvs; num_tlvs--) {
offset = dissect_ancp_tlv(tvb, tlv_tree, offset);
}
}
}
static void
dissect_ancp_adj_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ancp_tree,
gint offset, struct ancp_tap_t *ancp_info
)
{
proto_item *sti;
proto_tree *ancp_cap_tree;
guint8 byte, numcaps, adjcode;
guint16 tlv_len;
sti = proto_tree_add_item(ancp_tree, hf_ancp_timer, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_item_append_text(sti, " msec");
sti = proto_tree_add_item(ancp_tree, hf_ancp_adj_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
byte = tvb_get_guint8(tvb, offset);
offset += 1;
adjcode = byte & ADJ_CODE_MASK;
ancp_info->ancp_adjcode = adjcode;
proto_item_append_text(sti, " (%s, M Flag %s)",
val_to_str(adjcode, adj_code_names, "Unknown (0x%02x)"),
(byte >> 7) ? "Set" : "Unset");
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str(adjcode, adj_code_names, "Unknown (0x%02x)"));
proto_tree_add_item(ancp_tree, hf_ancp_sender_name, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(ancp_tree, hf_ancp_receiver_name, tvb,offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(ancp_tree, hf_ancp_sender_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ancp_tree, hf_ancp_receiver_port, tvb,offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sti = proto_tree_add_item(ancp_tree, hf_ancp_p_info, tvb,
offset, 1, ENC_BIG_ENDIAN);
byte = tvb_get_guint8(tvb, offset);
offset += 1;
proto_item_append_text(sti, " (Type = %d, Flag = %d)",
byte >> 4, byte & 0x0F);
proto_tree_add_item(ancp_tree, hf_ancp_sender_instance, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(ancp_tree, hf_ancp_p_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_receiver_instance, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(ancp_tree, hf_ancp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
sti = proto_tree_add_item(ancp_tree, hf_ancp_num_tlvs, tvb, offset, 1, ENC_BIG_ENDIAN);
numcaps = tvb_get_guint8(tvb, offset);
offset += 1;
ancp_cap_tree = proto_item_add_subtree(sti, ett_ancp_tot_len);
proto_tree_add_item(ancp_cap_tree, hf_ancp_tot_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for ( ;numcaps; numcaps--) {
sti = proto_tree_add_item(ancp_cap_tree, hf_ancp_cap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tlv_len = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_item_append_text(sti, " (%d bytes)", tlv_len);
}
}
static void
ancp_stats_tree_init(stats_tree *st)
{
st_node_packets = stats_tree_create_node(st, st_str_packets, 0, TRUE);
st_node_packet_types = stats_tree_create_pivot(st, st_str_packet_types,
st_node_packets);
st_node_adj_pack_types = stats_tree_create_node(st, st_str_adj_pack_types,
st_node_packets, TRUE);
}
static int
ancp_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_,
epan_dissect_t* edt _U_ , const void* p)
{
const struct ancp_tap_t *pi = (const struct ancp_tap_t *) p;
tick_stat_node(st, st_str_packets, 0, FALSE);
stats_tree_tick_pivot(st, st_node_packet_types,
val_to_str(pi->ancp_mtype, mtype_names,
"Unknown packet type (%d)"));
if (pi->ancp_mtype == ANCP_MTYPE_ADJ)
stats_tree_tick_pivot(st, st_node_adj_pack_types,
val_to_str(pi->ancp_adjcode, adj_code_names,
"Unknown Adjacency packet (%d)"));
return 1;
}
static int
dissect_ancp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset;
guint8 mtype;
struct ancp_tap_t *ancp_info;
proto_item *ti;
proto_item *sti;
proto_item *tti;
proto_tree *ancp_tree;
proto_tree *tlv_tree;
guint8 byte;
guint16 len;
offset = 0;
if (tvb_get_ntohs(tvb, offset) != ANCP_GSMP_ETHER_TYPE)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ANCP");
col_clear(pinfo->cinfo, COL_INFO);
ancp_info = wmem_new(wmem_packet_scope(), struct ancp_tap_t);
ancp_info->ancp_mtype = 0;
ancp_info->ancp_adjcode = 0;
ti = proto_tree_add_item(tree, proto_ancp, tvb, 0, -1, ENC_NA);
ancp_tree = proto_item_add_subtree(ti, ett_ancp_len);
offset = 2;
proto_tree_add_item(ancp_tree, hf_ancp_len, tvb, offset, 2, ENC_BIG_ENDIAN);
len = tvb_get_ntohs(tvb, offset);
offset += 2;
sti = proto_tree_add_item(ancp_tree, hf_ancp_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
byte = tvb_get_guint8(tvb, offset);
offset += 1;
proto_item_append_text(sti, " (%d.%d)", byte >> 4, byte & 0x0F);
sti = proto_tree_add_item(ancp_tree, hf_ancp_mtype, tvb, offset, 1, ENC_BIG_ENDIAN);
mtype = tvb_get_guint8(tvb, offset);
ancp_info->ancp_mtype = mtype;
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Message",
val_to_str(mtype, mtype_names, "Unknown (0x%02x)"));
if (mtype != ANCP_MTYPE_ADJ) {
proto_tree_add_item(ancp_tree, hf_ancp_result, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ancp_tree, hf_ancp_code, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ancp_tree, hf_ancp_p_id, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ancp_tree, hf_ancp_trans_id, tvb,
offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(ancp_tree, hf_ancp_i_flag, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ancp_tree, hf_ancp_submsg_num, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tti = proto_tree_add_item(ancp_tree, hf_ancp_len2, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
}
switch(mtype) {
case ANCP_MTYPE_ADJ:
dissect_ancp_adj_msg(tvb, pinfo, ancp_tree, offset, ancp_info);
break;
case ANCP_MTYPE_PORT_DN:
case ANCP_MTYPE_PORT_MGMT:
case ANCP_MTYPE_PORT_UP:
dissect_ancp_port_up_dn_mgmt(tvb, ancp_tree, offset, mtype);
break;
case ANCP_MTYPE_PROV:
case ANCP_MTYPE_GEN_RSP:
tlv_tree = proto_item_add_subtree(tti, ett_ancp_len);
while( offset < len + 4) {
offset = dissect_ancp_tlv(tvb, tlv_tree, offset);
}
break;
case ANCP_MTYPE_ADJ_UPD:
break;
default:
proto_item_append_text(sti, " (Unknown Message %d)", mtype);
break;
}
tap_queue_packet(ancp_tap, pinfo, ancp_info);
return tvb_reported_length(tvb);
}
static guint
get_ancp_msg_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return (guint)tvb_get_ntohs(tvb, offset + 2) + 4;
}
static int
dissect_ancp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, ANCP_MIN_HDR,
get_ancp_msg_len, dissect_ancp_message, data);
return tvb_reported_length(tvb);
}
void
proto_register_ancp(void)
{
static hf_register_info hf[] = {
{ &hf_ancp_len,
{ "Length", "ancp.len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_len2,
{ "Length", "ancp.len2",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_ver,
{ "Version", "ancp.ver",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_mtype,
{ "Message Type", "ancp.mtype",
FT_UINT8, BASE_DEC,
VALS(mtype_names), 0x0,
NULL, HFILL }
},
{ &hf_ancp_timer,
{ "Timer", "ancp.timer",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING,
&units_milliseconds, 0x0,
NULL, HFILL }
},
{ &hf_ancp_adj_code,
{ "Code", "ancp.adjcode",
FT_UINT8, BASE_DEC,
NULL, ADJ_CODE_MASK,
NULL, HFILL }
},
{ &hf_ancp_sender_name,
{ "Sender Name", "ancp.sender_name",
FT_ETHER, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_receiver_name,
{ "Receiver Name", "ancp.receiver_name",
FT_ETHER, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_sender_port,
{ "Sender Port", "ancp.sender_port",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_receiver_port,
{ "Receiver Port", "ancp.receiver_port",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_p_info,
{ "Partition Info", "ancp.partition_info",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_sender_instance,
{ "Sender Instance", "ancp.sender_instance",
FT_UINT24, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_p_id,
{ "Partition ID", "ancp.partition_id",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_receiver_instance,
{ "Receiver Instance", "ancp.receiver_instance",
FT_UINT24, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_tech_type,
{ "Tech Type", "ancp.tech_type",
FT_UINT8, BASE_DEC,
VALS(techtype_str), 0x0,
NULL, HFILL }
},
{ &hf_ancp_num_tlvs,
{ "Num TLVs", "ancp.num_tlvs",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_tot_len,
{ "Length", "ancp.tot_len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_cap,
{ "Capability", "ancp.capability",
FT_UINT16, BASE_DEC,
VALS(captype_names), 0x0,
NULL, HFILL }
},
{ &hf_ancp_result,
{ "Result", "ancp.result",
FT_UINT8, BASE_DEC,
VALS(resulttype_names), ANCP_RESULT_MASK,
NULL, HFILL }
},
{ &hf_ancp_code,
{ "Code", "ancp.code",
FT_UINT16, BASE_HEX,
VALS(codetype_names), ANCP_CODE_MASK,
NULL, HFILL }
},
{ &hf_ancp_trans_id,
{ "Transaction ID", "ancp.transaction_id",
FT_UINT24, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_i_flag,
{ "I Flag", "ancp.i_flag",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), ANCP_I_FLAG_MASK,
NULL, HFILL }
},
{ &hf_ancp_submsg_num,
{ "SubMessage Number", "ancp.submessage_number",
FT_UINT16, BASE_DEC,
NULL, ANCP_SUBMSG_MASK,
NULL, HFILL }
},
{ &hf_ancp_pudm_unused,
{ "Unused Bytes", "ancp.unused",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_function,
{ "Function", "ancp.function",
FT_UINT8, BASE_DEC,
VALS(function_names), 0x0,
NULL, HFILL }
},
{ &hf_ancp_x_function,
{ "X-Function", "ancp.x_function",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_ext_flags_res,
{ "Extension Flags Reserved", "ancp.ext_flags",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_port,
{ "Port", "ancp.port",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_port_sess_num,
{ "Port Session Number", "ancp.port_sess_num",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_evt_seq_num,
{ "Event Sequence Number", "ancp.evt_seq_num",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_label,
{ "Label", "ancp.label",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_reserved,
{ "Reserved", "ancp.reserved",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_blk_len,
{ "Block Length", "ancp.blk_len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_num_ext_tlvs,
{ "Num TLVs", "ancp.ext_tlvs.count",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_ext_tlv_type,
{ "TLV Type", "ancp.ext_tlv.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&ext_tlv_types_ext, 0x0,
NULL, HFILL }
},
{ &hf_ancp_ext_tlv_len,
{ "TLV Length", "ancp.ext_tlv.len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_dsl_line_stlv_type,
{ "Sub-TLV", "ancp.sub_tlv_type",
FT_UINT16, BASE_HEX,
VALS(dsl_line_attrs), 0x0,
NULL, HFILL }
},
{ &hf_ancp_dsl_line_stlv_len,
{ "Sub-TLV Length", "ancp.sub_tlv_len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_dsl_line_stlv_value,
{ "Value", "ancp.dsl_line_param",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_ext_tlv_value_str,
{ "Value", "ancp.ext_tlv.value",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_oam_opaque,
{ "Opaque", "ancp.oam.opaque",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_oam_loopb_cnt,
{ "OAM Loopback Count", "ancp.oam.loopback_count",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ancp_oam_timeout,
{ "OAM Timeout", "ancp.oam.timeout",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ancp_len,
&ett_ancp_ver,
&ett_ancp_mtype,
&ett_ancp_timer,
&ett_ancp_adj_code,
&ett_ancp_sender_name,
&ett_ancp_receiver_name,
&ett_ancp_sender_port,
&ett_ancp_receiver_port,
&ett_ancp_p_info,
&ett_ancp_sender_instance,
&ett_ancp_p_id,
&ett_ancp_receiver_instance,
&ett_ancp_tech_type,
&ett_ancp_num_tlvs,
&ett_ancp_tot_len,
&ett_ancp_cap,
&ett_ancp_result,
&ett_ancp_code,
&ett_ancp_trans_id,
&ett_ancp_i_flag,
&ett_ancp_submsg_num,
&ett_ancp_port,
&ett_ancp_port_sess_num,
&ett_ancp_evt_seq_num,
&ett_ancp_label,
&ett_ancp_reserved,
&ett_ancp_blk_len,
&ett_ancp_num_ext_tlvs,
&ett_ancp_ext_tlv_type,
&ett_ancp_dsl_line_stlv_type,
&ett_ancp_dsl_line_stlv_val,
&ett_ancp_ext_tlv_value_str,
&ett_ancp_oam_opaque,
&ett_ancp_oam_loopb_cnt,
&ett_ancp_oam_timeout,
};
proto_ancp = proto_register_protocol (
"Access Node Control Protocol",
"ANCP",
"ancp"
);
proto_register_field_array(proto_ancp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ancp_tap = register_tap("ancp");
}
void
proto_reg_handoff_ancp(void)
{
dissector_handle_t ancp_handle;
ancp_handle = create_dissector_handle(dissect_ancp, proto_ancp);
dissector_add_uint_with_preference("tcp.port", ANCP_PORT, ancp_handle);
stats_tree_register("ancp", "ancp", "ANCP", 0,
ancp_stats_tree_packet, ancp_stats_tree_init, NULL);
}
