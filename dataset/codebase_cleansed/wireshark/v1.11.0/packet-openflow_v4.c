static void
dissect_openflow_features_reply_v4(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *path_id_tree, *cap_tree;
ti = proto_tree_add_item(tree, hf_openflow_v4_datapath_id, tvb, offset, 8, ENC_BIG_ENDIAN);
path_id_tree = proto_item_add_subtree(ti, ett_openflow_v4_path_id);
proto_tree_add_item(path_id_tree, hf_openflow_datapath_v4_mac, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(path_id_tree, hf_openflow_v4_datapath_impl, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v4_n_buffers, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v4_n_tables, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v4_auxiliary_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v4_padd16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v4_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
cap_tree = proto_item_add_subtree(ti, ett_openflow_v4_cap);
proto_tree_add_item(cap_tree, hf_openflow_v4_cap_flow_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v4_table_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v4_port_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v4_group_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow__v4_ip_reasm, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v4_queue_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v4_port_blocked, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v4_padd32, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_multipart_request_v4(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
guint16 type;
type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v4_multipart_type , tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v4_multipart_request_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v4_padd32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(type){
case OFPMP_DESC:
break;
case OFPMP_FLOW:
proto_tree_add_text(tree, tvb, offset, -1, "struct ofp_flow_stats_request - not dissected yet");
break;
default:
if(length>16)
proto_tree_add_text(tree, tvb, offset, -1, "Type - not dissected yet");
break;
}
}
static void
dissect_openflow_multipart_reply_v4(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
guint16 type;
type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v4_multipart_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v4_multipart_reply_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v4_padd32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(type){
case OFPMP_DESC:
proto_tree_add_text(tree, tvb, offset, -1, "struct ofp_desc - not dissected yet");
break;
case OFPMP_FLOW:
proto_tree_add_text(tree, tvb, offset, -1, "struct ofp_flow_stats - not dissected yet");
break;
default:
if(length>16)
proto_tree_add_text(tree, tvb, offset, -1, "Type - not dissected yet");
break;
}
}
static int
dissect_openflow_v4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *openflow_tree;
guint offset = 0;
guint8 type;
guint16 length;
type = tvb_get_guint8(tvb, 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: %s",
val_to_str_const(type, openflow_v4_type_values, "Unknown Messagetype"));
if((type == OFPT_V4_PACKET_IN) || (type == OFPT_V4_PACKET_OUT)){
col_set_writable(pinfo->cinfo, FALSE);
}
ti = proto_tree_add_item(tree, proto_openflow_v4, tvb, 0, -1, ENC_NA);
openflow_tree = proto_item_add_subtree(ti, ett_openflow_v4);
proto_tree_add_item(openflow_tree, hf_openflow_v4_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(openflow_tree, hf_openflow_v4_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(openflow_tree, hf_openflow_v4_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(openflow_tree, hf_openflow_v4_xid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(type){
case OFPT_V4_HELLO:
break;
case OFPT_V4_FEATURES_REQUEST:
break;
case OFPT_V4_FEATURES_REPLY:
dissect_openflow_features_reply_v4(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_V4_MULTIPART_REQUEST:
dissect_openflow_multipart_request_v4(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_V4_MULTIPART_REPLY:
dissect_openflow_multipart_reply_v4(tvb, pinfo, openflow_tree, offset, length);
break;
default:
if(length>8){
proto_tree_add_text(tree, tvb, offset, -1, "Message data not dissected yet");
}
break;
}
return tvb_length(tvb);
}
void
proto_register_openflow_v4(void)
{
static hf_register_info hf[] = {
{ &hf_openflow_v4_version,
{ "Version", "openflow_v4.version",
FT_UINT8, BASE_HEX, VALS(openflow_v4_version_values), 0x7f,
NULL, HFILL }
},
{ &hf_openflow_v4_type,
{ "Type", "openflow_v4.type",
FT_UINT8, BASE_DEC, VALS(openflow_v4_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_xid,
{ "Transaction ID", "openflow_v4.xid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_length,
{ "Length", "openflow_v4.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_datapath_id,
{ "Datapath unique ID", "openflow_v4.datapath_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_datapath_v4_mac,
{ "MAC addr", "openflow_v4.datapath_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_datapath_impl,
{ "Implementers part", "openflow_v4.datapath_imp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_n_buffers,
{ "n_buffers", "openflow_v4.n_buffers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_n_tables,
{ "n_tables", "openflow_v4.n_tables",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_auxiliary_id,
{ "auxiliary_id", "openflow_v4.auxiliary_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_padd16,
{ "Padding", "openflow_v4.padding16",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_pad3,
{ "Padding", "openflow_v4.pad3",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_padd32,
{ "Padding", "openflow_v4.padding32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_capabilities,
{ "capabilities", "openflow_v4.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_cap_flow_stats,
{ "Flow statistics", "openflow_v4.flow_stats",
FT_BOOLEAN, 32, NULL, OFPC_V4_FLOW_STATS,
NULL, HFILL }
},
{ &hf_openflow_v4_table_stats,
{ "Table statistics", "openflow_v4.table_stats",
FT_BOOLEAN, 32, NULL, OFPC_V4_TABLE_STATS,
NULL, HFILL }
},
{ &hf_openflow_v4_port_stats,
{ "Port statistics", "openflow_v4.port_stats",
FT_BOOLEAN, 32, NULL, OFPC_V4_PORT_STATS,
NULL, HFILL }
},
{ &hf_openflow_v4_group_stats,
{ "Group statistics", "openflow_v4.group_stats",
FT_BOOLEAN, 32, NULL, OFPC_V4_GROUP_STATS,
NULL, HFILL }
},
{ &hf_openflow__v4_ip_reasm,
{ "Can reassemble IP fragments", "openflow_v4.ip_reasm",
FT_BOOLEAN, 32, NULL, OFPC_V4_IP_REASM,
NULL, HFILL }
},
{ &hf_openflow_v4_queue_stats,
{ "Queue statistics", "openflow_v4.queue_stats",
FT_BOOLEAN, 32, NULL, OFPC_V4_QUEUE_STATS,
NULL, HFILL }
},
{ &hf_openflow_v4_port_blocked,
{ "Switch will block looping ports", "openflow_v4.port_blocked",
FT_BOOLEAN, 32, NULL, OFPC_V4_PORT_BLOCKED,
NULL, HFILL }
},
{ &hf_openflow_v4_multipart_type,
{ "Type", "openflow_v4.multipart_type",
FT_UINT16, BASE_DEC, VALS(openflow_v4_multipart_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_multipart_request_flags,
{ "Flags", "openflow_v4.multipart_request_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v4_multipart_reply_flags,
{ "Flags", "openflow_v4.multipart_request_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_openflow_v4,
&ett_openflow_v4_path_id,
&ett_openflow_v4_cap,
};
proto_openflow_v4 = proto_register_protocol("OpenFlow_V4",
"openflow_v4", "openflow_v4");
new_register_dissector("openflow_v4", dissect_openflow_v4, proto_openflow_v4);
proto_register_field_array(proto_openflow_v4, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
