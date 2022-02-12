static void
dissect_ndp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const char *hello_type;
proto_tree *ndp_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NDP");
if (check_col(pinfo->cinfo, COL_INFO)) {
hello_type = "";
if (pinfo->dl_dst.type == AT_ETHER) {
const guint8 *dstmac = pinfo->dl_dst.data;
switch (dstmac[5]) {
case 0:
hello_type = "Segment ";
break;
case 1:
hello_type = "FlatNet ";
break;
}
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%sHello",
hello_type);
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ndp, tvb, 0, 11,
"Nortel Discovery Protocol");
ndp_tree = proto_item_add_subtree(ti, ett_ndp);
proto_tree_add_item(ndp_tree, hf_ndp_ip_address, tvb,
NDP_IP_ADDRESS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ndp_tree, hf_ndp_segment_identifier, tvb,
NDP_SEGMENT_IDENTIFIER, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ndp_tree, hf_ndp_chassis_type, tvb,
NDP_CHASSIS_TYPE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ndp_tree, hf_ndp_backplane_type, tvb,
NDP_BACKPLANE_TYPE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ndp_tree, hf_ndp_state, tvb,
NDP_STATE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ndp_tree, hf_ndp_number_of_links, tvb,
NDP_NUMBER_OF_LINKS, 1, ENC_BIG_ENDIAN);
}
}
void
proto_register_ndp(void)
{
static hf_register_info hf[] = {
{ &hf_ndp_ip_address,
{ "IP address", "ndp.ipaddress", FT_IPv4, BASE_NONE, NULL, 0x0,
"IP address of the Network Management Module (NMM))", HFILL }},
{ &hf_ndp_segment_identifier,
{ "Segment Identifier", "ndp.segmentident", FT_UINT24, BASE_HEX, NULL, 0x0,
"Segment id of the segment from which the agent is sending the topology message", HFILL }},
{ &hf_ndp_chassis_type,
{ "Chassis type", "ndp.chassis", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&ndp_chassis_val_ext, 0x0,
"Chassis type of the agent sending the topology message", HFILL }},
{ &hf_ndp_backplane_type,
{ "Backplane type", "ndp.backplane", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&ndp_backplane_val_ext, 0x0,
"Backplane type of the agent sending the topology message", HFILL }},
{ &hf_ndp_state,
{ "State", "ndp.state", FT_UINT8, BASE_DEC,
VALS(ndp_state_val), 0x0,
"Current state of this Network Management Module (NMM)", HFILL }},
{ &hf_ndp_number_of_links,
{ "Number of links", "ndp.numberoflinks", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of interconnect ports", HFILL }},
};
static gint *ett[] = {
&ett_ndp,
};
proto_ndp = proto_register_protocol("Nortel Discovery Protocol", "NDP", "ndp");
proto_register_field_array(proto_ndp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ndp", dissect_ndp, proto_ndp);
}
void
proto_reg_handoff_ndp(void)
{
dissector_handle_t ndp_handle;
ndp_handle = find_dissector("ndp");
dissector_add_uint("llc.nortel_pid", 0x01a1, ndp_handle);
dissector_add_uint("llc.nortel_pid", 0x01a2, ndp_handle);
}
