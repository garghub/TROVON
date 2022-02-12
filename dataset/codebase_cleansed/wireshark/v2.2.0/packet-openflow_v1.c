static int
dissect_openflow_ofp_match_v1(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_openflow_wildcards, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_in_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_eth_src, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_openflow_eth_dst, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_openflow_dl_vlan, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_dl_vlan_pcp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_ofp_match_pad, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_openflow_match_dl_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_ofp_match_tos, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_openflow_ofp_match_nw_proto, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_openflow_ofp_match_pad, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_openflow_ofp_source_addr, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_openflow_ofp_dest_addr, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_openflow_ofp_source_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_ofp_dest_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_openflow_flow_stats_request_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
offset = dissect_openflow_ofp_match_v1(tvb, pinfo, tree, offset);
proto_tree_add_item(tree, hf_openflow_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v1_flow_stats_request_pad, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_out_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_openflow_action_header(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint16 action_type, action_len;
proto_item* ti;
action_type = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(tree, hf_openflow_action_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
action_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_action_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch(action_type){
case OFPAT_OUTPUT:
proto_tree_add_item(tree, hf_openflow_output_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_max_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
default:
expert_add_info(pinfo, ti, &ei_openflow_action_type);
offset+=(action_len-4);
break;
}
return offset;
}
static void
dissect_openflow_phy_port(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *port_cnf_tree, *port_state_tree, *port_cf_tree;
proto_tree_add_item(tree, hf_openflow_port_no, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_hw_addr, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_openflow_port_name, tvb, offset, OFP_MAX_PORT_NAME_LEN, ENC_ASCII|ENC_NA);
offset+=OFP_MAX_PORT_NAME_LEN;
ti = proto_tree_add_item(tree, hf_openflow_port_config, tvb, offset, 4, ENC_BIG_ENDIAN);
port_cnf_tree = proto_item_add_subtree(ti, ett_openflow_port_cnf);
proto_tree_add_item(port_cnf_tree, hf_openflow_port_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_stp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_recv, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_recv_stp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_flood, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_fwd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cnf_tree, hf_openflow_no_packet_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_port_state, tvb, offset, 4, ENC_BIG_ENDIAN);
port_state_tree = proto_item_add_subtree(ti, ett_openflow_port_state);
proto_tree_add_item(port_state_tree, hf_openflow_link_down, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_port_curr, tvb, offset, 4, ENC_BIG_ENDIAN);
port_cf_tree = proto_item_add_subtree(ti, ett_openflow_port_cf);
proto_tree_add_item(port_cf_tree, hf_openflow_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(port_cf_tree, hf_openflow_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_port_advertised, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_port_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_port_peer, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_features_reply_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *path_id_tree, *cap_tree, *act_tree;
guint16 length_remaining;
ti = proto_tree_add_item(tree, hf_openflow_datapath_id, tvb, offset, 8, ENC_BIG_ENDIAN);
path_id_tree = proto_item_add_subtree(ti, ett_openflow_path_id);
proto_tree_add_item(path_id_tree, hf_openflow_datapath_mac, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(path_id_tree, hf_openflow_datapath_impl, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_n_buffers, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_n_tables, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_features_reply_pad, tvb, offset, 3, ENC_NA);
offset+=3;
ti = proto_tree_add_item(tree, hf_openflow_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
cap_tree = proto_item_add_subtree(ti, ett_openflow_cap);
proto_tree_add_item(cap_tree, hf_openflow_cap_flow_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_table_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_port_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_group_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_ip_reasm, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_queue_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_port_blocked, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_actions, tvb, offset, 4, ENC_BIG_ENDIAN);
act_tree = proto_item_add_subtree(ti, ett_openflow_act);
proto_tree_add_item(act_tree, hf_openflow_output, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_vlan_vid, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_vlan_pcp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_strip_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_dl_src, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_dl_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_nw_src, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_nw_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_nw_tos, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_tp_src, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_set_tp_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(act_tree, hf_openflow_enqueue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
length_remaining = length-32;
if(length_remaining > 0){
guint16 num_ports = length_remaining/48;
int i;
if((length_remaining&0x003f) != 0){
}
for(i=0; i<num_ports ;i++){
proto_tree *port_tree;
port_tree = proto_tree_add_subtree_format(tree, tvb, offset, 48, ett_openflow_port, NULL, "Port data %u",i+1);
dissect_openflow_phy_port(tvb, pinfo, port_tree, offset);
offset+=48;
}
}
}
static void
dissect_openflow_switch_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_config_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_miss_send_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_pkt_in(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
tvbuff_t *next_tvb;
proto_tree_add_item(tree, hf_openflow_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_total_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_in_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_pkt_in_pad, tvb, offset, 1, ENC_NA);
offset+=1;
next_tvb = tvb_new_subset_length(tvb, offset, length-offset);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
static void
dissect_openflow_pkt_out(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
tvbuff_t *next_tvb;
gint32 buffer_id;
buffer_id = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_openflow_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_in_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_actions_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_openflow_action_header(tvb, pinfo, tree, offset);
if(buffer_id == -1){
next_tvb = tvb_new_subset_length(tvb, offset, length-offset);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
}
static void
dissect_openflow_flow_mod(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length _U_)
{
offset = dissect_openflow_ofp_match_v1(tvb, pinfo, tree, offset);
proto_tree_add_item(tree, hf_openflow_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_openflow_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_idle_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_hard_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_openflow_out_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_openflow_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static int
dissect_openflow_stats_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *type_item;
guint32 type;
type_item = proto_tree_add_item_ret_uint(tree, hf_openflow_v1_stats_type, tvb, offset, 2, ENC_BIG_ENDIAN, &type);
offset += 2;
proto_tree_add_item(tree, hf_openflow_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (type) {
case OFPST_DESC:
break;
case OFPST_FLOW:
dissect_openflow_flow_stats_request_v1(tvb, pinfo, tree, offset);
break;
default:
expert_add_info(pinfo, type_item, &ei_openflow_1_0_type);
break;
}
return offset;
}
static int
dissect_openflow_stats_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length)
{
proto_item *type_item;
guint32 type;
type_item = proto_tree_add_item_ret_uint(tree, hf_openflow_v1_stats_type, tvb, offset, 2, ENC_BIG_ENDIAN, &type);
offset += 2;
proto_tree_add_item(tree, hf_openflow_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (length == 12 ) {
return offset;
}
switch (type) {
case OFPST_DESC:
break;
case OFPST_FLOW:
default:
expert_add_info(pinfo, type_item, &ei_openflow_1_0_type);
break;
}
return offset;
}
static int
dissect_openflow_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *type_item;
proto_tree *openflow_tree;
guint offset = 0;
guint8 type;
guint16 length;
type = tvb_get_guint8(tvb, 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: %s",
val_to_str_ext_const(type, &openflow_1_0_type_values_ext, "Unknown message type"));
if((type == OFPT_1_0_PACKET_IN) || (type == OFPT_1_0_PACKET_OUT)){
col_set_writable(pinfo->cinfo, -1, FALSE);
}
ti = proto_tree_add_item(tree, proto_openflow_v1, tvb, 0, -1, ENC_NA);
openflow_tree = proto_item_add_subtree(ti, ett_openflow);
proto_tree_add_item(openflow_tree, hf_openflow_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
type_item = proto_tree_add_item(openflow_tree, hf_openflow_1_0_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(openflow_tree, hf_openflow_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(openflow_tree, hf_openflow_xid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(type){
case OFPT_1_0_HELLO:
break;
case OFPT_1_0_FEATURES_REQUEST:
break;
case OFPT_1_0_FEATURES_REPLY:
dissect_openflow_features_reply_v1(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_GET_CONFIG_REQUEST:
break;
case OFPT_1_0_GET_CONFIG_REPLY:
case OFPT_1_0_SET_CONFIG:
dissect_openflow_switch_config(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_PACKET_IN:
dissect_openflow_pkt_in(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_PACKET_OUT:
dissect_openflow_pkt_out(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_FLOW_MOD:
dissect_openflow_flow_mod(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_STATS_REQUEST:
dissect_openflow_stats_req(tvb, pinfo, openflow_tree, offset, length);
break;
case OFPT_1_0_STATS_REPLY:
dissect_openflow_stats_resp(tvb, pinfo, openflow_tree, offset, length);
break;
default:
if(length>8){
expert_add_info(pinfo, type_item, &ei_openflow_1_0_type);
}
break;
}
return tvb_reported_length(tvb);
}
void
proto_register_openflow_v1(void)
{
static hf_register_info hf[] = {
{ &hf_openflow_version,
{ "Version", "openflow.version",
FT_UINT8, BASE_HEX, VALS(openflow_version_values), 0x7f,
NULL, HFILL }
},
{ &hf_openflow_1_0_type,
{ "Type", "openflow_1_0.type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &openflow_1_0_type_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_openflow_xid,
{ "Transaction ID", "openflow.xid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_length,
{ "Length", "openflow.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_datapath_id,
{ "Datapath unique ID", "openflow.datapath_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_datapath_mac,
{ "MAC addr", "openflow.datapath_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_datapath_impl,
{ "Implementers part", "openflow.datapath_imp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_n_buffers,
{ "n_buffers", "openflow.n_buffers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_n_tables,
{ "n_tables", "openflow.n_tables",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_openflow_auxiliary_id,
{ "auxiliary_id", "openflow.auxiliary_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_openflow_capabilities,
{ "capabilities", "openflow.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_actions,
{ "actions", "openflow.actions",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_openflow_reserved32,
{ "Reserved", "openflow.reserved32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_openflow_cap_flow_stats,
{ "Flow statistics", "openflow.flow_stats",
FT_BOOLEAN, 32, NULL, OFPC_FLOW_STATS,
NULL, HFILL }
},
{ &hf_openflow_table_stats,
{ "Table statistics", "openflow.table_stats",
FT_BOOLEAN, 32, NULL, OFPC_TABLE_STATS,
NULL, HFILL }
},
{ &hf_openflow_port_stats,
{ "Port statistics", "openflow.port_stats",
FT_BOOLEAN, 32, NULL, OFPC_PORT_STATS,
NULL, HFILL }
},
{ &hf_openflow_group_stats,
{ "Group statistics", "openflow.group_stats",
FT_BOOLEAN, 32, NULL, OFPC_GROUP_STATS,
NULL, HFILL }
},
{ &hf_openflow_ip_reasm,
{ "Can reassemble IP fragments", "openflow.ip_reasm",
FT_BOOLEAN, 32, NULL, OFPC_IP_REASM,
NULL, HFILL }
},
{ &hf_openflow_queue_stats,
{ "Queue statistics", "openflow.queue_stats",
FT_BOOLEAN, 32, NULL, OFPC_QUEUE_STATS,
NULL, HFILL }
},
{ &hf_openflow_port_blocked,
{ "Switch will block looping ports", "openflow.port_blocked",
FT_BOOLEAN, 32, NULL, OFPC_PORT_BLOCKED,
NULL, HFILL }
},
{ &hf_openflow_output,
{ "Output to switch port", "openflow.output",
FT_BOOLEAN, 32, NULL, OFPAT_OUTPUT_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_vlan_vid,
{ "Set the 802.1q VLAN id", "openflow.set_vlan_vid",
FT_BOOLEAN, 32, NULL, OFPAT_SET_VLAN_VID_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_vlan_pcp,
{ "Set the 802.1q priority", "openflow.set_vlan_pcp",
FT_BOOLEAN, 32, NULL, OFPAT_SET_VLAN_PCP_MASK,
NULL, HFILL }
},
{ &hf_openflow_strip_vlan,
{ "Strip the 802.1q header", "openflow.strip_vlan",
FT_BOOLEAN, 32, NULL, OFPAT_STRIP_VLAN_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_dl_src,
{ "Ethernet source address", "openflow.set_dl_src",
FT_BOOLEAN, 32, NULL, OFPAT_SET_DL_SRC_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_dl_dst,
{ "Ethernet destination address", "openflow.set_dl_ds",
FT_BOOLEAN, 32, NULL, OFPAT_SET_DL_DST_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_nw_src,
{ "IP source address", "openflow.set_nw_src",
FT_BOOLEAN, 32, NULL, OFPAT_SET_NW_SRC_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_nw_dst,
{ "IP destination address", "openflow.set_nw_ds",
FT_BOOLEAN, 32, NULL, OFPAT_SET_NW_DST_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_nw_tos,
{ "IP ToS (DSCP field, 6 bits)", "openflow.set_nw_tos",
FT_BOOLEAN, 32, NULL, OFPAT_SET_NW_TOS_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_tp_src,
{ "TCP/UDP source port", "openflow.set_tp_src",
FT_BOOLEAN, 32, NULL, OFPAT_SET_TP_SRC_MASK,
NULL, HFILL }
},
{ &hf_openflow_set_tp_dst,
{ "TCP/UDP destination port", "openflow.set_tp_dst",
FT_BOOLEAN, 32, NULL, OFPAT_SET_TP_DST_MASK,
NULL, HFILL }
},
{ &hf_openflow_enqueue,
{ "Output to queue", "openflow.enqueue",
FT_BOOLEAN, 32, NULL, OFPAT_ENQUEUE_MASK,
NULL, HFILL }
},
{ &hf_openflow_port_no,
{ "Port number", "openflow.port_no",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_hw_addr,
{ "HW Address", "openflow.hw_add",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_name,
{ "Port Name", "openflow.port_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_config,
{ "Config flags", "openflow.port_config",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_state,
{ "State flags", "openflow.port_state",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_curr,
{ "Current features", "openflow.port_curr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_advertised,
{ "Advertised features", "openflow.port_advertised",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_supported,
{ "Features supported", "openflow.port_supported",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_peer,
{ "Features advertised by peer", "openflow.port_peer",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_port_down,
{ "Port is administratively down", "openflow.port_down",
FT_BOOLEAN, 32, NULL, OFPPC_PORT_DOWN,
NULL, HFILL }
},
{ &hf_openflow_no_stp,
{ "Disable 802.1D spanning tree on port", "openflow.no_stp",
FT_BOOLEAN, 32, NULL, OFPPC_NO_STP,
NULL, HFILL }
},
{ &hf_openflow_no_recv,
{ "Drop all packets except 802.1D spanning tree packets", "openflow.no_recv",
FT_BOOLEAN, 32, NULL, OFPPC_NO_RECV,
NULL, HFILL }
},
{ &hf_openflow_no_recv_stp,
{ "Drop received 802.1D STP packets", "openflow.no_recv_stp",
FT_BOOLEAN, 32, NULL, OFPPC_NO_RECV_STP,
NULL, HFILL }
},
{ &hf_openflow_no_flood,
{ "Do not include this port when flooding", "openflow.no_flood",
FT_BOOLEAN, 32, NULL, OFPPC_NO_FLOOD,
NULL, HFILL }
},
{ &hf_openflow_no_fwd,
{ "Drop packets forwarded to port", "openflow.no_fwd",
FT_BOOLEAN, 32, NULL, OFPPC_NO_FWD,
NULL, HFILL }
},
{ &hf_openflow_no_packet_in,
{ "Do not send packet-in msgs for port", "openflow.no_packet_in",
FT_BOOLEAN, 32, NULL, OFPPC_NO_PACKET_IN,
NULL, HFILL }
},
{ &hf_openflow_link_down,
{ "No physical link present", "openflow.link_down",
FT_BOOLEAN, 32, NULL, OFPPS_LINK_DOWN,
NULL, HFILL }
},
{ &hf_openflow_10mb_hd,
{ "10 Mb half-duplex rate support", "openflow.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_10mb_fd,
{ "10 Mb full-duplex rate support", "openflow.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_100mb_hd,
{ "100 Mb half-duplex rate support", "openflow.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_100mb_fd,
{ "100 Mb full-duplex rate support", "openflow.100mb_0fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_1gb_hd,
{ "1 Gb half-duplex rate support", "openflow.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_1gb_fd,
{ "1 Gb full-duplex rate support", "openflow.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_10gb_fd,
{ "10 Gb full-duplex rate support", "openflow.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_copper,
{ "Copper medium", "openflow.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_fiber,
{ "Fiber medium", "openflow.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_autoneg,
{ "Auto-negotiation", "openflow.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_pause,
{ "Pause", "openflow.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_pause_asym,
{ "Asymmetric pause", "openflow.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_config_flags,
{ "Config flags", "openflow.config_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_miss_send_len,
{ "Max bytes of packet", "openflow.miss_send_len",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_buffer_id,
{ "Buffer Id", "openflow.buffer_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_total_len,
{ "Total length", "openflow.total_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_in_port,
{ "In port", "openflow.in_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_reason,
{ "Reason", "openflow.reason",
FT_UINT8, BASE_DEC, VALS(openflow_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_pkt_in_pad,
{ "Pad", "openflow.pkt_in.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_table_id,
{ "Table Id", "openflow.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_cookie,
{ "Cookie", "openflow.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_openflow_cookie_mask,
{ "Cookie mask", "openflow.cookie_mask",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_openflow_features_reply_pad,
{ "Pad", "openflow.features_reply.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_actions_len,
{ "Actions length", "openflow.actions_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_action_type,
{ "Actions type", "openflow.action_typ",
FT_UINT16, BASE_DEC, VALS(openflow_action_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_action_len,
{ "Action length", "openflow.action_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_output_port,
{ "Output port", "openflow.output_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_max_len,
{ "Max length", "openflow.max_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_wildcards,
{ "Wildcards", "openflow.wildcards",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_command,
{ "Command", "openflow.command",
FT_UINT16, BASE_DEC, VALS(openflow_command_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_eth_src,
{ "Ethernet source address", "openflow.eth_src",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_eth_dst,
{ "Ethernet destination address", "openflow.eth_dst",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_dl_vlan,
{ "Input VLAN id", "openflow.dl_vlan",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_dl_vlan_pcp,
{ "Input VLAN priority", "openflow.dl_vlan_pcp",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_match_pad,
{ "Pad", "openflow.ofp_match.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_match_dl_type,
{ "Dl type", "openflow.ofp_match.dl_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_match_tos,
{ "IP ToS", "openflow.ofp_match.tos",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_match_nw_proto,
{ "IP protocol", "openflow.ofp_match.nw_proto",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_source_addr,
{ "Source Address", "openflow.ofp_match.source_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_dest_addr,
{ "Destination Address", "openflow.ofp_match.dest_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_source_port,
{ "Source Port", "openflow.ofp_match.source_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_ofp_dest_port,
{ "Destination Port", "openflow.ofp_match.dest_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_idle_timeout,
{ "Idle time-out", "openflow.idle_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_hard_timeout,
{ "hard time-out", "openflow.hard_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_priority,
{ "Priority", "openflow.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_out_port,
{ "Out port", "openflow.out_port",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_openflow_out_group,
{ "Out group", "openflow.out_group",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_openflow_flags,
{ "Flags", "openflow.flags",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v1_stats_type,
{ "Type", "openflow.stats.type",
FT_UINT16, BASE_DEC, VALS(openflow_stats_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v1_flow_stats_request_pad,
{ "Pad", "openflow.stats.request_pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_openflow,
&ett_openflow_path_id,
&ett_openflow_cap,
&ett_openflow_act,
&ett_openflow_port,
&ett_openflow_port_cnf,
&ett_openflow_port_state,
&ett_openflow_port_cf
};
static ei_register_info ei[] = {
#if 0
{ &ei_openflow_undecoded_data, { "openflow.undecoded_data", PI_UNDECODED, PI_WARN, "Data not dissected yet", EXPFILL }},
#endif
{ &ei_openflow_action_type, { "openflow.action_typ.undecoded", PI_UNDECODED, PI_WARN, "Action not dissected yet", EXPFILL }},
{ &ei_openflow_1_0_type, { "openflow_1_0.type.undecoded", PI_UNDECODED, PI_WARN, "Message data not dissected yet", EXPFILL }},
};
expert_module_t* expert_openflow_v1;
proto_openflow_v1 = proto_register_protocol("OpenFlow 1.0",
"openflow_v1", "openflow_v1");
register_dissector("openflow_v1", dissect_openflow_v1, proto_openflow_v1);
proto_register_field_array(proto_openflow_v1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_openflow_v1 = expert_register_protocol(proto_openflow_v1);
expert_register_field_array(expert_openflow_v1, ei, array_length(ei));
}
void
proto_reg_handoff_openflow_v1(void)
{
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_openflow_v1);
}
