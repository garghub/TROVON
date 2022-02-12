static int
dissect_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pitem = NULL;
guint control_type;
guint8 unknown_control_type;
guint8 uuid_size;
guint16 uuid_dst;
guint16 uuid_src;
guint16 response_message;
guint list_length;
guint i_item;
proto_tree_add_item(tree, hf_btbnep_control_type, tvb, offset, 1, ENC_BIG_ENDIAN);
control_type = tvb_get_guint8(tvb, offset);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(control_type, control_type_vals, "Unknown type"));
switch(control_type) {
case 0x00:
proto_tree_add_item(tree, hf_btbnep_unknown_control_type, tvb, offset, 1, ENC_BIG_ENDIAN);
unknown_control_type = tvb_get_guint8(tvb, offset);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " - Unknown(%s)", val_to_str_const(unknown_control_type, control_type_vals, "Unknown type"));
break;
case 0x01:
proto_tree_add_item(tree, hf_btbnep_uuid_size, tvb, offset, 1, ENC_BIG_ENDIAN);
uuid_size = tvb_get_guint8(tvb, offset);
offset += 1;
pitem = proto_tree_add_item(tree, hf_btbnep_destination_service_uuid, tvb, offset, uuid_size, ENC_NA);
uuid_dst = tvb_get_ntohs(tvb, offset);
proto_item_append_text(pitem, " (%s)", val_to_str_ext(uuid_dst, &vs_service_classes_ext, "Unknown uuid"));
offset += uuid_size;
pitem = proto_tree_add_item(tree, hf_btbnep_source_service_uuid, tvb, offset, uuid_size, ENC_NA);
uuid_src = tvb_get_ntohs(tvb, offset);
proto_item_append_text(pitem, " (%s)", val_to_str_ext(uuid_src, &vs_service_classes_ext, "Unknown uuid"));
offset += uuid_size;
col_append_fstr(pinfo->cinfo, COL_INFO, " - dst: <%s>, src: <%s>",
val_to_str_ext(uuid_dst, &vs_service_classes_ext, "Unknown uuid"),
val_to_str_ext(uuid_src, &vs_service_classes_ext, "Unknown uuid"));
break;
case 0x02:
proto_tree_add_item(tree, hf_btbnep_setup_connection_response_message, tvb, offset, 2, ENC_BIG_ENDIAN);
response_message = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s",
val_to_str_const(response_message, setup_connection_response_message_vals, "Unknown response message"));
break;
case 0x03:
proto_tree_add_item(tree, hf_btbnep_list_length, tvb, offset, 2, ENC_BIG_ENDIAN);
list_length = tvb_get_ntohs(tvb, offset);
offset += 2;
for (i_item = 0; i_item < list_length; i_item += 4) {
proto_tree_add_item(tree, hf_btbnep_network_type_start, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_btbnep_network_type_end, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case 0x04:
proto_tree_add_item(tree, hf_btbnep_filter_net_type_response_message, tvb, offset, 2, ENC_BIG_ENDIAN);
response_message = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s",
val_to_str_const(response_message, filter_net_type_response_message_vals, "Unknown response message"));
break;
case 0x05:
proto_tree_add_item(tree, hf_btbnep_list_length, tvb, offset, 2, ENC_BIG_ENDIAN);
list_length = tvb_get_ntohs(tvb, offset);
offset += 2;
for (i_item = 0; i_item < list_length; i_item += 12) {
proto_tree_add_item(tree, hf_btbnep_multicast_address_start, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_btbnep_multicast_address_end, tvb, offset, 6, ENC_NA);
offset += 6;
}
break;
case 0x06:
proto_tree_add_item(tree, hf_btbnep_filter_multi_addr_response_message, tvb, offset, 2, ENC_BIG_ENDIAN);
response_message = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s",
val_to_str_const(response_message, filter_multi_addr_response_message_vals, "Unknown response message"));
break;
};
return offset;
}
static int
dissect_extension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 extension_flag;
guint8 extension_type;
guint16 extension_length;
guint8 type;
proto_tree_add_item(tree, hf_btbnep_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btbnep_extension_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
extension_flag = type & 0x01;
extension_type = type >> 1;
offset += 1;
proto_tree_add_item(tree, hf_btbnep_extension_length, tvb, offset, 1, ENC_BIG_ENDIAN);
extension_length = tvb_get_ntohs(tvb, offset);
offset += 2;
if (extension_type == 0x00) {
offset = dissect_control(tvb, pinfo, tree, offset);
} else {
offset += extension_length;
}
if (extension_flag) offset = dissect_extension(tvb, pinfo, tree, offset);
return offset;
}
static void
dissect_btbnep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
proto_tree *btbnep_tree;
gint offset = 0;
guint bnep_type;
guint extension_flag;
guint type = 0;
proto_item *addr_item;
proto_tree *addr_tree = NULL;
const guint8 *src_addr;
const guint8 *dst_addr;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BNEP");
col_clear(pinfo->cinfo, COL_INFO);
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
pi = proto_tree_add_item(tree, proto_btbnep, tvb, offset, -1, ENC_NA);
btbnep_tree = proto_item_add_subtree(pi, ett_btbnep);
proto_tree_add_item(btbnep_tree, hf_btbnep_extension_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(btbnep_tree, hf_btbnep_bnep_type, tvb, offset, 1, ENC_BIG_ENDIAN);
bnep_type = tvb_get_guint8(tvb, offset);
extension_flag = bnep_type & 0x80;
bnep_type = bnep_type & 0x7F;
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_const(bnep_type, bnep_type_vals, "Unknown type"));
if (extension_flag) col_append_fstr(pinfo->cinfo, COL_INFO, "+E");
if (bnep_type == BNEP_TYPE_GENERAL_ETHERNET || bnep_type == BNEP_TYPE_COMPRESSED_ETHERNET_DESTINATION_ONLY) {
dst_addr = tvb_get_ptr(tvb, offset, 6);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, dst_addr);
SET_ADDRESS(&pinfo->dst, AT_ETHER, 6, dst_addr);
addr_item = proto_tree_add_ether(btbnep_tree, hf_btbnep_dst, tvb, offset, 6, dst_addr);
if (addr_item) addr_tree = proto_item_add_subtree(addr_item, ett_addr);
proto_tree_add_ether(addr_tree, hf_btbnep_addr, tvb, offset, 6, dst_addr);
proto_tree_add_item(addr_tree, hf_btbnep_lg, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_btbnep_ig, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 6;
}
if (bnep_type == BNEP_TYPE_GENERAL_ETHERNET || bnep_type == BNEP_TYPE_COMPRESSED_ETHERNET_SOURCE_ONLY) {
src_addr = tvb_get_ptr(tvb, offset, 6);
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, src_addr);
SET_ADDRESS(&pinfo->src, AT_ETHER, 6, src_addr);
addr_item = proto_tree_add_ether(btbnep_tree, hf_btbnep_src, tvb, offset, 6, src_addr);
if (addr_item) {
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
if (tvb_get_guint8(tvb, offset) & 0x01) {
expert_add_info_format(pinfo, addr_item, PI_PROTOCOL, PI_WARN,
"Source MAC must not be a group address: IEEE 802.3-2002, Section 3.2.3(b)");
}
}
proto_tree_add_ether(addr_tree, hf_btbnep_addr, tvb, offset, 6, src_addr);
proto_tree_add_item(addr_tree, hf_btbnep_lg, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_btbnep_ig, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 6;
}
if (bnep_type != BNEP_TYPE_CONTROL) {
type = tvb_get_ntohs(tvb, offset);
if (!top_dissect) {
proto_tree_add_item(btbnep_tree, hf_btbnep_type, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Type: %s", val_to_str_const(type, etype_vals, "unknown"));
}
offset += 2;
} else {
offset = dissect_control(tvb, pinfo, btbnep_tree, offset);
}
if (extension_flag) {
offset = dissect_extension(tvb, pinfo, btbnep_tree, offset);
}
if (bnep_type != BNEP_TYPE_CONTROL) {
if (top_dissect) {
ethertype(type, tvb, offset, pinfo, tree, btbnep_tree,
hf_btbnep_type, 0, 0);
} else {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
}
void
proto_register_btbnep(void)
{
module_t *module;
static hf_register_info hf[] = {
{ &hf_btbnep_bnep_type,
{ "BNEP Type", "btbnep.bnep_type",
FT_UINT8, BASE_HEX, VALS(bnep_type_vals), 0x7F,
NULL, HFILL }
},
{ &hf_btbnep_extension_flag,
{ "Extension Flag", "btbnep.extension_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btbnep_control_type,
{ "Control Type", "btbnep.control_type",
FT_UINT8, BASE_HEX, VALS(control_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_extension_type,
{ "Extension Type", "btbnep.extension_type",
FT_UINT8, BASE_HEX, VALS(extension_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_extension_length,
{ "Extension Length", "btbnep.extension_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_unknown_control_type,
{ "Unknown Control Type", "btbnep.uknown_control_type",
FT_UINT8, BASE_HEX, VALS(control_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_uuid_size,
{ "UIDD Size", "btbnep.uuid_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_destination_service_uuid,
{ "Destination Service UUID", "btbnep.destination_service_uuid",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_source_service_uuid,
{ "Source Service UUID", "btbnep.source_service_uuid",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_setup_connection_response_message,
{ "Response Message", "btbnep.setup_connection_response_message",
FT_UINT16, BASE_HEX, VALS(setup_connection_response_message_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_filter_net_type_response_message,
{ "Response Message", "btbnep.filter_net_type_response_message",
FT_UINT16, BASE_HEX, VALS(filter_net_type_response_message_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_filter_multi_addr_response_message,
{ "Response Message", "btbnep.filter_multi_addr_response_message",
FT_UINT16, BASE_HEX, VALS(filter_multi_addr_response_message_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_list_length,
{ "List Length", "btbnep.list_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_network_type_start,
{ "Network Protocol Type Range Start", "btbnep.network_type_start",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_network_type_end,
{ "Network Protocol Type Range End", "btbnep.network_type_end",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x00,
NULL, HFILL }
},
{ &hf_btbnep_multicast_address_start,
{ "Multicast Address Start", "btbnep.multicast_address_start",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_multicast_address_end,
{ "Multicast Address End", "btbnep.multicast_address_end",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btbnep_dst,
{ "Destination", "btbnep.dst",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination Hardware Address", HFILL }
},
{ &hf_btbnep_src,
{ "Source", "btbnep.src",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Source Hardware Address", HFILL }
},
{ &hf_btbnep_type,
{ "Type", "btbnep.type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_btbnep_addr,
{ "Address", "btbnep.addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Source or Destination Hardware Address", HFILL }
},
{ &hf_btbnep_lg,
{ "LG bit", "btbnep.lg",
FT_BOOLEAN, 24, TFS(&lg_tfs), 0x020000,
"Specifies if this is a locally administered or globally unique (IEEE assigned) address", HFILL }
},
{ &hf_btbnep_ig,
{ "IG bit", "btbnep.ig",
FT_BOOLEAN, 24, TFS(&ig_tfs), 0x010000,
"Specifies if this is an individual (unicast) or group (broadcast/multicast) address", HFILL }
}
};
static gint *ett[] = {
&ett_btbnep,
&ett_addr
};
proto_btbnep = proto_register_protocol("Bluetooth BNEP Protocol", "BT BNEP", "btbnep");
register_dissector("btbnep", dissect_btbnep, proto_btbnep);
proto_register_field_array(proto_btbnep, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
module = prefs_register_protocol(proto_btbnep, NULL);
prefs_register_static_text_preference(module, "bnep.version",
"Bluetooth Protocol BNEP version: 1.0",
"Version of protocol supported by this dissector.");
prefs_register_bool_preference(module, "bnep.top_dissect",
"Dissecting the top protocols", "Dissecting the top protocols",
&top_dissect);
}
void
proto_reg_handoff_btbnep(void)
{
dissector_handle_t btbnep_handle;
btbnep_handle = find_dissector("btbnep");
eth_handle = find_dissector("eth");
data_handle = find_dissector("data");
dissector_add_uint("btl2cap.service", BTSDP_PAN_GN_SERVICE_UUID, btbnep_handle);
dissector_add_uint("btl2cap.service", BTSDP_PAN_NAP_SERVICE_UUID, btbnep_handle);
dissector_add_uint("btl2cap.service", BTSDP_PAN_GN_SERVICE_UUID, btbnep_handle);
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_BNEP, btbnep_handle);
dissector_add_handle("btl2cap.cid", btbnep_handle);
}
