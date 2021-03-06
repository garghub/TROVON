static int
dissect_aruba_iap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ti;
proto_tree *aruba_iap_tree;
guint16 magic;
guint8 type;
int offset = 0;
magic = tvb_get_ntohs(tvb, offset);
if(magic != MAGIC_IAP)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IAP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_aruba_iap, tvb, 0, -1, ENC_NA);
aruba_iap_tree = proto_item_add_subtree(ti, ett_aruba_iap);
proto_tree_add_item(aruba_iap_tree, hf_iap_magic, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(aruba_iap_tree, hf_iap_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "Aruba Instant AP");
proto_tree_add_item(aruba_iap_tree, hf_iap_type, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(aruba_iap_tree, hf_iap_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(aruba_iap_tree, hf_iap_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if(type == 3 || type == 4 || type == 5 || type == 7){
proto_tree_add_item(aruba_iap_tree, hf_iap_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(aruba_iap_tree, hf_iap_uptime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(aruba_iap_tree, hf_iap_vc_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " VC IP: %s", tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_item(aruba_iap_tree, hf_iap_unknown_uint, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(aruba_iap_tree, hf_iap_pvid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(aruba_iap_tree, hf_iap_unknown_uint, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(aruba_iap_tree, hf_iap_unknown_bytes, tvb, offset, -1, ENC_NA);
} else {
proto_tree_add_item(aruba_iap_tree, hf_iap_unknown_bytes, tvb, offset, -1, ENC_NA);
}
return tvb_reported_length(tvb);
}
void
proto_register_aruba_iap(void)
{
static hf_register_info hf[] = {
{ &hf_iap_magic,
{ "Magic", "aruba_iap.magic", FT_UINT16, BASE_HEX, NULL,0x0,
"Magic Number of IAP trafic (Always 0x8ffd)", HFILL}},
{ &hf_iap_version,
{ "Version", "aruba_iap.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_iap_type,
{ "Type", "aruba_iap.type", FT_UINT8, BASE_DEC, NULL, 0x0,
"Type of message", HFILL}},
{ &hf_iap_length,
{ "Length", "aruba_iap.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_iap_id,
{ "Id", "aruba_iap.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_iap_status,
{ "Status", "aruba_iap.status", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_iap_uptime,
{ "Uptime", "aruba_iap.uptime", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_iap_vc_ip,
{ "VC IP", "aruba_iap.vc_ip", FT_IPv4, BASE_NONE, NULL, 0x0,
"Address IP of Virtual Controller", HFILL}},
{ &hf_iap_pvid,
{ "PVID (Port Vlan ID)", "aruba_iap.pvid", FT_UINT16, BASE_DEC, NULL, 0x0,
"Vlan ID (of Uplink)", HFILL}},
{ &hf_iap_unknown_bytes,
{ "Unknown", "aruba_iap.unknown.bytes", FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown Data...", HFILL}},
{ &hf_iap_unknown_uint,
{ "Unknown", "aruba_iap.unknown.uint", FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
"Unknown (UINT) Data...", HFILL}},
};
static gint *ett[] = {
&ett_aruba_iap,
};
proto_aruba_iap = proto_register_protocol("Aruba Instant AP Protocol",
"aruba_iap", "aruba_iap");
proto_register_field_array(proto_aruba_iap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aruba_iap(void)
{
dissector_handle_t iap_handle;
iap_handle = create_dissector_handle(dissect_aruba_iap, proto_aruba_iap);
dissector_add_uint("ethertype", ETHERTYPE_IAP, iap_handle);
}
