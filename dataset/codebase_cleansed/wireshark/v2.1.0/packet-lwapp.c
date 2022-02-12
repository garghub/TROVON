static void
dissect_control(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
CNTL_Header header;
proto_tree *control_tree;
tvbuff_t *next_tvb;
proto_item *ti;
gint offset=0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LWAPP");
col_set_str(pinfo->cinfo, COL_INFO,
"CNTL ");
tvb_memcpy(tvb, (guint8*) &header, offset, sizeof(header));
header.length = g_ntohs(header.length);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(header.type, &control_msg_vals_ext, "Bad Type: 0x%02x"));
if (tree) {
ti = proto_tree_add_item(tree, proto_lwapp_control, tvb, offset,
-1, ENC_NA);
control_tree = proto_item_add_subtree(ti, ett_lwapp_control);
proto_tree_add_uint(control_tree, hf_lwapp_control_type,
tvb, offset, 1, header.type);
offset++;
proto_tree_add_uint(control_tree, hf_lwapp_control_seq_no,
tvb, offset, 1, header.seqNo);
offset++;
proto_tree_add_uint(control_tree, hf_lwapp_control_length,
tvb, offset, 2, header.length);
offset += 2;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
}
}
static int
dissect_lwapp_l3(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *lwapp_tree;
gint offset = 0;
tvbuff_t *next_client;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LWAPP-L3");
col_set_str(pinfo->cinfo, COL_INFO, "802.3 Packets over Layer 3");
ti = proto_tree_add_item(tree, proto_lwapp_l3, tvb, offset,
-1, ENC_NA);
lwapp_tree = proto_item_add_subtree(ti, ett_lwapp_l3);
next_client = tvb_new_subset_remaining(tvb, 0);
call_dissector(eth_withoutfcs_handle, next_client, pinfo, lwapp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_lwapp(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
LWAPP_Header header;
guint8 slotId;
guint8 version;
proto_tree *lwapp_tree;
tvbuff_t *next_client;
guint8 dest_mac[6];
guint8 have_destmac=0;
static const int * flags[] = {
&hf_lwapp_flags_type,
&hf_lwapp_flags_fragment,
&hf_lwapp_flags_fragment_type,
NULL
};
proto_item *ti;
gint offset=0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LWAPP");
col_set_str(pinfo->cinfo, COL_INFO,
"LWAPP IP or Layer 2");
if (pinfo->destport == 12223 ) {
tvb_memcpy(tvb, dest_mac, offset, 6);
have_destmac = 1;
tvb_memcpy(tvb, (guint8*) &header, offset + 6, sizeof(header));
} else {
tvb_memcpy(tvb, (guint8*) &header, offset, sizeof(header));
}
header.length = g_ntohs(header.length);
version = (header.flags & 0xc0) >> 6;
slotId = (header.flags & 0x38) >> 3;
if ((header.flags & LWAPP_FLAGS_T) != 0)
col_append_str(pinfo->cinfo, COL_INFO,
" Control Packet");
else
col_append_str(pinfo->cinfo, COL_INFO,
" 802.11 Packet");
if (tree) {
ti = proto_tree_add_item(tree, proto_lwapp, tvb, offset, -1, ENC_NA);
lwapp_tree = proto_item_add_subtree(ti, ett_lwapp);
if (have_destmac) {
proto_tree_add_ether(lwapp_tree, hf_lwapp_control_mac, tvb, offset,
6, dest_mac);
offset += 6;
}
proto_tree_add_uint(lwapp_tree, hf_lwapp_version,
tvb, offset, 1, version);
proto_tree_add_uint(lwapp_tree, hf_lwapp_slotid,
tvb, offset, 1, slotId);
proto_tree_add_bitmask(lwapp_tree, tvb, offset, hf_lwapp_flags, ett_lwapp_flags, flags, ENC_NA);
offset++;
proto_tree_add_uint(lwapp_tree, hf_lwapp_fragment_id,
tvb, offset, 1, header.fragmentId);
offset++;
proto_tree_add_uint(lwapp_tree, hf_lwapp_length,
tvb, offset, 2, header.length);
offset += 2;
proto_tree_add_uint(lwapp_tree, hf_lwapp_rssi,
tvb, offset, 1, header.rssi);
offset++;
proto_tree_add_uint(lwapp_tree, hf_lwapp_snr,
tvb, offset, 1, header.snr);
offset++;
}
next_client = tvb_new_subset_remaining(tvb, (have_destmac?6:0) + (int)sizeof(LWAPP_Header));
if ((header.flags & LWAPP_FLAGS_T) == 0) {
call_dissector(swap_frame_control ? wlan_bsfc_handle : wlan_handle,
next_client, pinfo, tree);
} else {
dissect_control(next_client, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_lwapp(void)
{
static hf_register_info hf[] = {
{ &hf_lwapp_version,
{ "Version", "lwapp.version", FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_lwapp_slotid,
{ "slotId","lwapp.slotId", FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_lwapp_flags,
{ "Flags", "lwapp.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lwapp_flags_type,
{ "Type", "lwapp.flags.type", FT_BOOLEAN, 8,
TFS(&lwapp_flags_type), LWAPP_FLAGS_T, NULL, HFILL }},
{ &hf_lwapp_flags_fragment,
{ "Fragment", "lwapp.flags.fragment", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), LWAPP_FLAGS_F,
NULL, HFILL }},
{ &hf_lwapp_flags_fragment_type,
{ "Fragment Type", "lwapp.flags.fragmentType", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), LWAPP_FLAGS_FT,
NULL, HFILL }},
{ &hf_lwapp_fragment_id,
{ "Fragment Id","lwapp.fragmentId", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lwapp_length,
{ "Length","lwapp.Length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lwapp_rssi,
{ "RSSI","lwapp.rssi", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lwapp_snr,
{ "SNR","lwapp.snr", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_lwapp_control,
{ "Control Data (not dissected yet)","lwapp.control", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_lwapp_control_mac,
{ "AP Identity", "lwapp.apid", FT_ETHER, BASE_NONE, NULL, 0x0,
"Access Point Identity", HFILL }},
{ &hf_lwapp_control_type,
{ "Control Type", "lwapp.control.type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &control_msg_vals_ext, 0x00,
NULL, HFILL }},
{ &hf_lwapp_control_seq_no,
{ "Control Sequence Number", "lwapp.control.seqno", FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_lwapp_control_length,
{ "Control Length","lwapp.control.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_lwapp_l3,
&ett_lwapp,
&ett_lwapp_control,
&ett_lwapp_flags
};
module_t *lwapp_module;
proto_lwapp = proto_register_protocol ("LWAPP Encapsulated Packet",
"LWAPP", "lwapp");
proto_lwapp_l3 = proto_register_protocol ("LWAPP Layer 3 Packet",
"LWAPP-L3", "lwapp-l3");
proto_lwapp_control = proto_register_protocol ("LWAPP Control Message",
"LWAPP-CNTL", "lwapp-cntl");
proto_register_field_array(proto_lwapp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lwapp_module = prefs_register_protocol(proto_lwapp, NULL);
prefs_register_bool_preference(lwapp_module,"swap_fc","Swap Frame Control",
"Swap frame control bytes (needed for some APs",
&swap_frame_control);
}
void
proto_reg_handoff_lwapp(void)
{
dissector_handle_t lwapp_l3_handle;
dissector_handle_t lwapp_handle;
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_lwapp);
wlan_handle = find_dissector_add_dependency("wlan_withoutfcs", proto_lwapp);
wlan_bsfc_handle = find_dissector_add_dependency("wlan_bsfc", proto_lwapp);
lwapp_l3_handle = create_dissector_handle(dissect_lwapp_l3, proto_lwapp_l3);
lwapp_handle = create_dissector_handle(dissect_lwapp, proto_lwapp);
dissector_add_uint("udp.port", 12220, lwapp_l3_handle);
dissector_add_uint("udp.port", 12222, lwapp_handle);
dissector_add_uint("udp.port", 12223, lwapp_handle);
dissector_add_uint("ethertype", 0x88bb, lwapp_handle);
dissector_add_uint("ethertype", 0xbbbb, lwapp_handle);
}
