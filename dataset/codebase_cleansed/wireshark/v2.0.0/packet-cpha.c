static int
dissect_cpha(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_item * ti;
proto_item * nti;
proto_tree * cpha_tree = NULL;
proto_tree * ntree = NULL;
guint16 opcode;
guint16 magic_number;
guint16 ha_version;
if (tvb_reported_length(tvb) < 4) {
return 0;
}
magic_number = tvb_get_ntohs(tvb, 0);
ha_version = tvb_get_ntohs(tvb, 2);
if (magic_number != CPHA_MAGIC) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CPHA");
col_clear(pinfo->cinfo, COL_INFO);
opcode = tvb_get_ntohs(tvb, 6);
col_add_fstr(pinfo->cinfo, COL_INFO, "CPHAv%d: %s",
ha_version, val_to_str(opcode, opcode_type_vals, "Unknown %d"));
if (tree) {
ti = proto_tree_add_item(tree, proto_cphap, tvb, offset, -1, ENC_NA);
cpha_tree = proto_item_add_subtree(ti, ett_cphap);
}
if (tree) {
proto_tree_add_item(cpha_tree, hf_magic_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_cpha_protocol_ver, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_cluster_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_opcode, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_src_if_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_random_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_src_machine_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_dst_machine_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if(ha_version != 1) {
proto_tree_add_item(cpha_tree, hf_policy_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cpha_tree, hf_filler, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
nti = proto_tree_add_item(cpha_tree, hf_payload, tvb, offset, -1, ENC_NA);
proto_item_append_text(nti, " - %s", val_to_str(opcode, opcode_type_vals, "Unknown %d"));
ntree = proto_item_add_subtree(nti, ett_cphap);
switch(opcode) {
case 1: dissect_my_state(tvb, offset, ntree);
break;
case 2: break;
case 3:
case 4: dissect_probe(tvb, offset, ntree);
break;
case 5: break;
case 6: dissect_conf_reply(tvb, offset, ntree);
break;
case 7: dissect_lb_conf(tvb, offset, ntree);
break;
case 9: dissect_policy_change(tvb, offset, ntree);
break;
default: proto_tree_add_item(ntree, hf_unknown_data, tvb, offset, -1, ENC_NA);
break;
}
}
return tvb_reported_length(tvb);
}
static int dissect_my_state(tvbuff_t * tvb, int offset, proto_tree * tree) {
int i;
proto_item * nti = NULL;
proto_tree * ntree = NULL;
guint16 report_code, id_num;
proto_tree_add_item(tree, hf_id_num, tvb, offset, 2, ENC_BIG_ENDIAN);
id_num = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_report_code, tvb, offset, 2, ENC_BIG_ENDIAN);
report_code = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_ha_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ha_time_unit, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (report_code & 1) {
nti = proto_tree_add_item(tree, hf_machine_states, tvb, offset, id_num, ENC_NA);
ntree = proto_item_add_subtree(nti, ett_cphap);
for(i=0; i < id_num; i++) {
nti = proto_tree_add_item(ntree, hf_state_node, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(nti, " (Nodes %d)", i);
offset += 1;
}
}
if (report_code & 2) {
nti = proto_tree_add_item(tree, hf_interface_states, tvb, offset, 4, ENC_NA);
ntree = proto_item_add_subtree(nti, ett_cphap);
proto_tree_add_item(ntree, hf_in_up_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ntree, hf_in_assumed_up_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ntree, hf_out_up_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ntree, hf_out_assumed_up_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for(i=0; i < id_num; i++) {
proto_tree_add_item(tree, hf_cluster_last_packet, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(nti, " (Cluster %d)", i);
offset += 1;
}
}
return offset;
}
static int dissect_lb_conf(tvbuff_t * tvb, int offset, proto_tree * tree) {
proto_tree_add_item(tree, hf_slot_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_machine_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_seed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_hash_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_policy_change(tvbuff_t * tvb, int offset, proto_tree * tree) {
proto_tree_add_item(tree, hf_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_probe(tvbuff_t * tvb, int offset, proto_tree * tree) {
proto_tree_add_item(tree, hf_ifn, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_conf_reply(tvbuff_t * tvb, int offset, proto_tree * tree) {
proto_tree_add_item(tree, hf_num_reported_ifs, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ethernet_add, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_is_if_trusted, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ip, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
void
proto_register_cpha(void)
{
static hf_register_info hf[] = {
{ &hf_magic_number,
{ "Magic Number", "cpha.magic_number", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_cpha_protocol_ver,
{ "Protocol Version", "cpha.version", FT_UINT16, BASE_DEC|BASE_EXT_STRING, &ha_version_vals_ext, 0x0, "CPHAP Version", HFILL}},
{ &hf_cluster_number,
{ "Cluster Number", "cpha.cluster_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_opcode,
{ "HA OpCode", "cpha.opcode", FT_UINT16, BASE_DEC, VALS(opcode_type_vals), 0x0, NULL, HFILL}},
{ &hf_payload,
{ "Payload", "cpha.payload", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_src_if_num,
{ "Source Interface", "cpha.src_if", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_random_id,
{ "Random ID", "cpha.random_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_src_machine_id,
{ "Source Machine ID", "cpha.src_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_dst_machine_id,
{ "Destination Machine ID", "cpha.dst_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_policy_id,
{ "Policy ID", "cpha.policy_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_filler,
{ "Filler", "cpha.filler", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_unknown_data,
{ "Data", "cpha.unknown_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_id_num,
{ "Number of IDs reported", "cpha.id_num", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_report_code,
{ "Report code", "cpha.report_code", FT_UINT16, BASE_DEC, VALS(report_code_vals), 0x0, NULL, HFILL}},
{ &hf_ha_mode,
{ "HA mode", "cpha.ha_mode", FT_UINT16, BASE_DEC, VALS(ha_mode_vals), 0x0, NULL, HFILL}},
{ &hf_ha_time_unit,
{ "HA Time unit", "cpha.ha_time_unit", FT_UINT16, BASE_DEC, NULL, 0x0, "HA Time unit (ms)", HFILL}},
{ &hf_machine_states,
{ "Machines States", "cpha.machine_states", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_state_node,
{ "State node", "cpha.state_node", FT_UINT8, BASE_DEC, VALS(state_vals), 0x0, NULL, HFILL}},
{ &hf_interface_states,
{ "Interface States", "cpha.interface_states", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_num_reported_ifs,
{ "Reported Interfaces", "cpha.reported_ifs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ethernet_add,
{ "Ethernet Address", "cpha.ethernet_addr", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_is_if_trusted,
{ "Interface Trusted", "cpha.if_trusted", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_ip,
{ "IP Address", "cpha.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_slot_num,
{ "Slot Number", "cpha.slot_num", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_machine_num,
{ "Machine Number", "cpha.machine_num", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_seed,
{ "Seed", "cpha.seed", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_hash_len,
{ "Hash list length", "cpha.hash_len", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_in_up_num,
{ "Interfaces up in the Inbound", "cpha.in_up", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_in_assumed_up_num,
{ "Interfaces assumed up in the Inbound", "cpha.in_assume_up", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_out_up_num,
{ "Interfaces up in the Outbound", "cpha.out_up", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_out_assumed_up_num,
{ "Interfaces assumed up in the Outbound", "cpha.out_assume_up", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_cluster_last_packet,
{ "Last packet seen", "cpha.cluster_last_packet", FT_INT8, BASE_DEC, NULL, 0x0, "Time units ago", HFILL}},
{ &hf_status,
{ "Status", "cpha.status", FT_UINT32, BASE_DEC, VALS(status_vals), 0x0, NULL, HFILL}},
{ &hf_ifn,
{ "Interface Number", "cpha.ifn", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_cphap,
};
proto_cphap = proto_register_protocol("Check Point High Availability Protocol",
"CPHA", "cpha");
proto_register_field_array(proto_cphap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cpha(void)
{
dissector_handle_t cpha_handle;
cpha_handle = new_create_dissector_handle(dissect_cpha, proto_cphap);
dissector_add_uint("udp.port", UDP_PORT_CPHA, cpha_handle);
}
