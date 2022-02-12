static int
dissect_exported_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *item;
proto_tree *exported_pdu_tree, *tag_tree;
tvbuff_t * payload_tvb = NULL;
int offset = 0;
guint16 tag;
int tag_len;
int next_proto_type = -1;
const guint8 *proto_name = NULL;
const guint8 *dissector_table = NULL;
const guint8 *col_proto_str = NULL;
dissector_handle_t proto_handle;
mtp3_addr_pc_t *mtp3_addr;
guint8 dvb_ci_dir;
guint32 dissector_table_val=0;
dissector_table_t dis_tbl;
void* dissector_data = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Exported PDU");
ti = proto_tree_add_item(tree, proto_exported_pdu, tvb, offset, -1, ENC_NA);
exported_pdu_tree = proto_item_add_subtree(ti, ett_exported_pdu);
do {
tag = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(exported_pdu_tree, hf_exported_pdu_tag, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
tag_tree = proto_item_add_subtree(ti, ett_exported_pdu_tag);
proto_tree_add_item(tag_tree, hf_exported_pdu_tag_len, tvb, offset, 2, ENC_BIG_ENDIAN);
tag_len = tvb_get_ntohs(tvb, offset);
offset+=2;
switch(tag) {
case EXP_PDU_TAG_PROTO_NAME:
next_proto_type = EXPORTED_PDU_NEXT_PROTO_STR;
proto_tree_add_item_ret_string(tag_tree, hf_exported_pdu_prot_name, tvb, offset, tag_len, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &proto_name);
break;
case EXP_PDU_TAG_HEUR_PROTO_NAME:
next_proto_type = EXPORTED_PDU_NEXT_HEUR_PROTO_STR;
proto_tree_add_item_ret_string(tag_tree, hf_exported_pdu_heur_prot_name, tvb, offset, tag_len, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &proto_name);
break;
case EXP_PDU_TAG_DISSECTOR_TABLE_NAME:
next_proto_type = EXPORTED_PDU_NEXT_DIS_TABLE_STR;
proto_tree_add_item_ret_string(tag_tree, hf_exported_pdu_dis_table_name, tvb, offset, tag_len, ENC_UTF_8 | ENC_NA, wmem_packet_scope(), &dissector_table);
break;
case EXP_PDU_TAG_IPV4_SRC:
proto_tree_add_item(tag_tree, hf_exported_pdu_ipv4_src, tvb, offset, 4, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tag_tree, hf_ip_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(tag_tree, hf_ip_src, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
set_address_tvb(&pinfo->net_src, AT_IPv4, 4, tvb, offset);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
break;
case EXP_PDU_TAG_IPV4_DST:
proto_tree_add_item(tag_tree, hf_exported_pdu_ipv4_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tag_tree, hf_ip_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(tag_tree, hf_ip_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
set_address_tvb(&pinfo->net_dst, AT_IPv4, 4, tvb, offset);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
break;
case EXP_PDU_TAG_IPV6_SRC:
proto_tree_add_item(tag_tree, hf_exported_pdu_ipv6_src, tvb, offset, 16, ENC_NA);
item = proto_tree_add_item(tag_tree, hf_ipv6_addr, tvb, offset, 16, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(tag_tree, hf_ipv6_src, tvb, offset, 16, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
set_address_tvb(&pinfo->net_src, AT_IPv6, 16, tvb, offset);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
break;
case EXP_PDU_TAG_IPV6_DST:
proto_tree_add_item(tag_tree, hf_exported_pdu_ipv6_dst, tvb, offset, 16, ENC_NA);
item = proto_tree_add_item(tag_tree, hf_ipv6_addr, tvb, offset, 16, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(tag_tree, hf_ipv6_dst, tvb, offset, 16, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
set_address_tvb(&pinfo->net_dst, AT_IPv6, 16, tvb, offset);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
break;
case EXP_PDU_TAG_PORT_TYPE:
pinfo->ptype = (port_type)tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tag_tree, hf_exported_pdu_port_type, tvb, offset, 4, pinfo->ptype,
"%s (%u)", port_type_to_str(pinfo->ptype), pinfo->ptype);
break;
case EXP_PDU_TAG_SRC_PORT:
proto_tree_add_item(tag_tree, hf_exported_pdu_src_port, tvb, offset, 4, ENC_BIG_ENDIAN);
pinfo->srcport = tvb_get_ntohl(tvb, offset);
break;
case EXP_PDU_TAG_DST_PORT:
proto_tree_add_item(tag_tree, hf_exported_pdu_dst_port, tvb, offset, 4, ENC_BIG_ENDIAN);
pinfo->destport = tvb_get_ntohl(tvb, offset);
break;
case EXP_PDU_TAG_SS7_OPC:
proto_tree_add_item(tag_tree, hf_exported_pdu_ss7_opc, tvb, offset, 4, ENC_BIG_ENDIAN);
mtp3_addr = (mtp3_addr_pc_t *)wmem_alloc0(pinfo->pool, sizeof(mtp3_addr_pc_t));
mtp3_addr->pc = tvb_get_ntohl(tvb, offset);
mtp3_addr->type = (Standard_Type)tvb_get_ntohs(tvb, offset+4);
mtp3_addr->ni = tvb_get_guint8(tvb, offset+6);
set_address(&pinfo->src, ss7pc_address_type, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr);
break;
case EXP_PDU_TAG_SS7_DPC:
proto_tree_add_item(tag_tree, hf_exported_pdu_ss7_dpc, tvb, offset, 4, ENC_BIG_ENDIAN);
mtp3_addr = (mtp3_addr_pc_t *)wmem_alloc0(pinfo->pool, sizeof(mtp3_addr_pc_t));
mtp3_addr->pc = tvb_get_ntohl(tvb, offset);
mtp3_addr->type = (Standard_Type)tvb_get_ntohs(tvb, offset+4);
mtp3_addr->ni = tvb_get_guint8(tvb, offset+6);
set_address(&pinfo->dst, ss7pc_address_type, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr);
break;
case EXP_PDU_TAG_ORIG_FNO:
proto_tree_add_item(tag_tree, hf_exported_pdu_orig_fno, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case EXP_PDU_TAG_DVBCI_EVT:
dvb_ci_dir = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tag_tree, hf_exported_pdu_dvbci_evt,
tvb, offset, 1, ENC_BIG_ENDIAN);
dvbci_set_addrs(dvb_ci_dir, pinfo);
break;
case EXP_PDU_TAG_DISSECTOR_TABLE_NAME_NUM_VAL:
dissector_table_val = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tag_tree, hf_exported_pdu_dis_table_val, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case EXP_PDU_TAG_COL_PROT_TEXT:
proto_tree_add_item_ret_string(tag_tree, hf_exported_pdu_col_proto_str, tvb, offset, tag_len, ENC_UTF_8 | ENC_NA, wmem_packet_scope(), &col_proto_str);
break;
case EXP_PDU_TAG_TCP_INFO_DATA:
{
struct tcpinfo* tcpdata = wmem_new0(wmem_packet_scope(), struct tcpinfo);
guint16 version;
proto_tree_add_item(tag_tree, hf_exported_pdu_dissector_data, tvb, offset, tag_len, ENC_NA);
version = tvb_get_ntohs(tvb, offset);
DISSECTOR_ASSERT(version == 1);
tcpdata->seq = tvb_get_ntohl(tvb, offset+2);
tcpdata->nxtseq = tvb_get_ntohl(tvb, offset+6);
tcpdata->lastackseq = tvb_get_ntohl(tvb, offset+10);
tcpdata->is_reassembled = tvb_get_guint8(tvb, offset+14);
tcpdata->flags = tvb_get_ntohs(tvb, offset+15);
tcpdata->urgent_pointer = tvb_get_ntohs(tvb, offset+17);
dissector_data = tcpdata;
}
break;
case EXP_PDU_TAG_END_OF_OPT:
break;
default:
proto_tree_add_item(tag_tree, hf_exported_pdu_unknown_tag_val, tvb, offset, tag_len, ENC_NA);
break;
}
offset = offset + tag_len;
} while(tag != 0);
payload_tvb = tvb_new_subset_remaining(tvb, offset);
proto_tree_add_item(exported_pdu_tree, hf_exported_pdu_exported_pdu, payload_tvb, 0, -1, ENC_NA);
switch(next_proto_type) {
case EXPORTED_PDU_NEXT_PROTO_STR:
proto_handle = find_dissector(proto_name);
if (proto_handle) {
col_clear(pinfo->cinfo, COL_PROTOCOL);
call_dissector_with_data(proto_handle, payload_tvb, pinfo, tree, dissector_data);
}
break;
case EXPORTED_PDU_NEXT_HEUR_PROTO_STR:
{
heur_dtbl_entry_t *heur_diss = find_heur_dissector_by_unique_short_name(proto_name);
if (heur_diss) {
col_clear(pinfo->cinfo, COL_PROTOCOL);
call_heur_dissector_direct(heur_diss, payload_tvb, pinfo, tree, dissector_data);
}
break;
}
case EXPORTED_PDU_NEXT_DIS_TABLE_STR:
{
dis_tbl = find_dissector_table(dissector_table);
if (dis_tbl) {
col_clear(pinfo->cinfo, COL_PROTOCOL);
if (col_proto_str) {
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "%s",col_proto_str);
}
dissector_try_uint_new(dis_tbl, dissector_table_val, payload_tvb, pinfo, tree, FALSE, dissector_data);
}
}
default:
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_exported_pdu(void)
{
static hf_register_info hf[] = {
{ &hf_exported_pdu_tag,
{ "Tag", "exported_pdu.tag",
FT_UINT16, BASE_DEC, VALS(exported_pdu_tag_vals), 0,
NULL, HFILL }
},
{ &hf_exported_pdu_tag_len,
{ "Length", "exported_pdu.tag_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_unknown_tag_val,
{ "Unknown tags value", "exported_pdu.unknown_tag.val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_prot_name,
{ "Protocol Name", "exported_pdu.prot_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_heur_prot_name,
{ "Heuristic Protocol Name", "exported_pdu.heur_prot_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_dis_table_name,
{ "Dissector Table Name", "exported_pdu.dis_table_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_dissector_data,
{ "Dissector Data", "exported_pdu.dissector_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ipv4_src,
{ "IPv4 Src", "exported_pdu.ipv4_src",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ipv4_dst,
{ "IPv4 Dst", "exported_pdu.ipv4_dst",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ipv6_src,
{ "IPv6 Src", "exported_pdu.ipv6_src",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ipv6_dst,
{ "IPv6 Dst", "exported_pdu.ipv6_dst",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_port_type,
{ "Port Type", "exported_pdu.port_type",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_src_port,
{ "Src Port", "exported_pdu.src_port",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_dst_port,
{ "Dst Port", "exported_pdu.dst_port",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ss7_opc,
{ "SS7 OPC", "exported_pdu.ss7_opc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_ss7_dpc,
{ "SS7 DPC", "exported_pdu.ss7_dpc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_orig_fno,
{ "Original Frame Number", "exported_pdu.orig_fno",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_dvbci_evt,
{ "DVB-CI event", "exported_pdu.dvb-ci.event",
FT_UINT8, BASE_HEX, VALS(dvbci_event), 0,
NULL, HFILL }
},
{ &hf_exported_pdu_exported_pdu,
{ "Exported PDU", "exported_pdu.exported_pdu",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_dis_table_val,
{ "Value to use when calling dissector table", "exported_pdu.dis_table_val",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_exported_pdu_col_proto_str,
{ "Column protocol string", "exported_pdu.col_proto_str",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_exported_pdu,
&ett_exported_pdu_tag
};
proto_exported_pdu = proto_register_protocol("EXPORTED_PDU",
"exported_pdu", "exported_pdu");
exported_pdu_handle = register_dissector("exported_pdu", dissect_exported_pdu, proto_exported_pdu);
proto_register_field_array(proto_exported_pdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_export_pdu_tap(EXPORT_PDU_TAP_NAME_LAYER_3);
register_export_pdu_tap(EXPORT_PDU_TAP_NAME_LAYER_4);
register_export_pdu_tap(EXPORT_PDU_TAP_NAME_LAYER_7);
}
void
proto_reg_handoff_exported_pdu(void)
{
static gboolean initialized = FALSE;
if (!initialized) {
dissector_add_uint("wtap_encap", WTAP_ENCAP_WIRESHARK_UPPER_PDU, exported_pdu_handle);
initialized = TRUE;
}
ss7pc_address_type = address_type_get_by_name("AT_SS7PC");
hf_ip_addr = proto_registrar_get_id_byname("ip.addr");
hf_ip_dst = proto_registrar_get_id_byname("ip.dst");
hf_ip_src = proto_registrar_get_id_byname("ip.src");
hf_ipv6_addr = proto_registrar_get_id_byname("ipv6.src");
hf_ipv6_dst = proto_registrar_get_id_byname("ipv6.dst");
hf_ipv6_src = proto_registrar_get_id_byname("ipv6.src");
}
