static void
dissect_dec_bpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 bpdu_type;
guint8 flags;
proto_tree *bpdu_tree;
proto_tree *flags_tree;
proto_item *ti;
const char *sep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DEC_STP");
col_clear(pinfo->cinfo, COL_INFO);
bpdu_type = tvb_get_guint8(tvb, BPDU_TYPE);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(bpdu_type, bpdu_type_vals,
"Unknown BPDU type (%u)"));
set_actual_length(tvb, DEC_BPDU_SIZE);
if (tree) {
ti = proto_tree_add_item(tree, proto_dec_bpdu, tvb, 0, DEC_BPDU_SIZE,
ENC_NA);
bpdu_tree = proto_item_add_subtree(ti, ett_dec_bpdu);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_proto_id, tvb,
BPDU_DEC_CODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(bpdu_tree, hf_dec_bpdu_type, tvb,
BPDU_TYPE, 1, bpdu_type);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_version_id, tvb,
BPDU_VERSION, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, BPDU_FLAGS);
ti = proto_tree_add_uint(bpdu_tree, hf_dec_bpdu_flags, tvb,
BPDU_FLAGS, 1, flags);
flags_tree = proto_item_add_subtree(ti, ett_dec_bpdu_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_SHORT_TIMERS, ti,
"%sUse short timers");
proto_tree_add_boolean(flags_tree, hf_dec_bpdu_flags_short_timers, tvb,
BPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TCACK, ti,
"%sTopology Change Acknowledgment");
proto_tree_add_boolean(flags_tree, hf_dec_bpdu_flags_tcack, tvb,
BPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TC, ti,
"%sTopology Change");
proto_tree_add_boolean(flags_tree, hf_dec_bpdu_flags_tc, tvb,
BPDU_FLAGS, 1, flags);
if (sep != initial_sep) {
proto_item_append_text(ti, ")");
}
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_root_pri, tvb,
BPDU_ROOT_PRI, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_root_mac, tvb,
BPDU_ROOT_MAC, 6, ENC_NA);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_root_cost, tvb,
BPDU_ROOT_PATH_COST, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_bridge_pri, tvb,
BPDU_BRIDGE_PRI, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_bridge_mac, tvb,
BPDU_BRIDGE_MAC, 6, ENC_NA);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_port_id, tvb,
BPDU_PORT_IDENTIFIER, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_msg_age, tvb,
BPDU_MESSAGE_AGE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_hello_time, tvb,
BPDU_HELLO_TIME, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_max_age, tvb,
BPDU_MAX_AGE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bpdu_tree, hf_dec_bpdu_forward_delay, tvb,
BPDU_FORWARD_DELAY, 1, ENC_BIG_ENDIAN);
}
}
void
proto_register_dec_bpdu(void)
{
static hf_register_info hf[] = {
{ &hf_dec_bpdu_proto_id,
{ "Protocol Identifier", "dec_stp.protocol",
FT_UINT8, BASE_HEX, VALS(protocol_id_vals), 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_type,
{ "BPDU Type", "dec_stp.type",
FT_UINT8, BASE_DEC, VALS(bpdu_type_vals), 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_version_id,
{ "BPDU Version", "dec_stp.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_flags,
{ "BPDU flags", "dec_stp.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_flags_short_timers,
{ "Use short timers", "dec_stp.flags.short_timers",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_SHORT_TIMERS,
NULL, HFILL }},
{ &hf_dec_bpdu_flags_tcack,
{ "Topology Change Acknowledgment", "dec_stp.flags.tcack",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_TCACK,
NULL, HFILL }},
{ &hf_dec_bpdu_flags_tc,
{ "Topology Change", "dec_stp.flags.tc",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_TC,
NULL, HFILL }},
{ &hf_dec_bpdu_root_pri,
{ "Root Priority", "dec_stp.root.pri",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_root_mac,
{ "Root MAC", "dec_stp.root.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_root_cost,
{ "Root Path Cost", "dec_stp.root.cost",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_bridge_pri,
{ "Bridge Priority", "dec_stp.bridge.pri",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_bridge_mac,
{ "Bridge MAC", "dec_stp.bridge.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_port_id,
{ "Port identifier", "dec_stp.port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_msg_age,
{ "Message Age", "dec_stp.msg_age",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_hello_time,
{ "Hello Time", "dec_stp.hello",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_max_age,
{ "Max Age", "dec_stp.max_age",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dec_bpdu_forward_delay,
{ "Forward Delay", "dec_stp.forward",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_dec_bpdu,
&ett_dec_bpdu_flags,
};
proto_dec_bpdu = proto_register_protocol("DEC Spanning Tree Protocol",
"DEC_STP", "dec_stp");
proto_register_field_array(proto_dec_bpdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dec_bpdu(void)
{
dissector_handle_t dec_bpdu_handle;
dec_bpdu_handle = create_dissector_handle(dissect_dec_bpdu,
proto_dec_bpdu);
dissector_add_uint("ethertype", ETHERTYPE_DEC_LB, dec_bpdu_handle);
dissector_add_uint("chdlctype", ETHERTYPE_DEC_LB, dec_bpdu_handle);
dissector_add_uint("ppp.protocol", PPP_DEC_LB, dec_bpdu_handle);
}
