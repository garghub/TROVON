static void
dissect_marker(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 raw_octet;
proto_tree *marker_tree;
proto_item *marker_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Marker");
col_set_str(pinfo->cinfo, COL_INFO, "Marker Protocol");
if (tree)
{
marker_item = proto_tree_add_protocol_format(tree, proto_marker, tvb,
0, -1, "Marker Protocol");
marker_tree = proto_item_add_subtree(marker_item, ett_marker);
proto_tree_add_item(marker_tree, hf_marker_version_number, tvb,
offset, 1, ENC_NA);
offset += 1;
while (1)
{
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == MARKERPDU_END_MARKER)
break;
proto_tree_add_uint(marker_tree, hf_marker_tlv_type, tvb,
offset, 1, raw_octet);
offset += 1;
proto_tree_add_item(marker_tree, hf_marker_tlv_length, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(marker_tree, hf_marker_req_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(marker_tree, hf_marker_req_system, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(marker_tree, hf_marker_req_trans_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset += 2;
}
}
}
void
proto_register_marker(void)
{
static hf_register_info hf[] = {
{ &hf_marker_version_number,
{ "Version Number", "marker.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Marker protocol version", HFILL }},
{ &hf_marker_tlv_type,
{ "TLV Type", "marker.tlvType",
FT_UINT8, BASE_HEX, VALS(marker_vals), 0x0,
NULL, HFILL }},
{ &hf_marker_tlv_length,
{ "TLV Length", "marker.tlvLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Length of the Actor TLV", HFILL }},
{ &hf_marker_req_port,
{ "Requester Port", "marker.requesterPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_marker_req_system,
{ "Requester System", "marker.requesterSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Requester System ID encoded as a MAC address", HFILL }},
{ &hf_marker_req_trans_id,
{ "Requester Transaction ID", "marker.requesterTransId",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_marker,
};
proto_marker = proto_register_protocol("Marker", "Link Aggregation Marker Protocol", "marker");
proto_register_field_array(proto_marker, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_marker(void)
{
dissector_handle_t marker_handle;
marker_handle = create_dissector_handle(dissect_marker, proto_marker);
dissector_add_uint("slow.subtype", MARKER_SUBTYPE, marker_handle);
}
