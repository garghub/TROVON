static int
dissect_hci_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ttree = NULL;
proto_tree *titem = NULL;
proto_item *pitem = NULL;
gint offset = 0;
usb_data_t *usb_data;
tvbuff_t *next_tvb = NULL;
void *pd_save;
hci_data_t *hci_data;
gint p2p_dir_save;
guint32 session_id;
fragment_head *reassembled;
if (tvb_length_remaining(tvb, offset) <= 0)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_USB");
col_clear(pinfo->cinfo, COL_INFO);
usb_data = (usb_data_t *) pinfo->private_data;
p2p_dir_save = pinfo->p2p_dir;
pinfo->p2p_dir = usb_data->direction;
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_str(pinfo->cinfo, COL_INFO, "Sent");
break;
case P2P_DIR_RECV:
col_add_str(pinfo->cinfo, COL_INFO, "Rcvd");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction");
break;
}
titem = proto_tree_add_item(tree, proto_hci_usb, tvb, offset, -1, ENC_NA);
ttree = proto_item_add_subtree(titem, ett_hci_usb);
pd_save = pinfo->private_data;
session_id = usb_data->bus_id << 16 | usb_data->device_address << 8 | ((pinfo->p2p_dir == P2P_DIR_RECV) ? 1 : 0 ) << 7 | usb_data->endpoint;
hci_data = (hci_data_t *) wmem_new(wmem_packet_scope(), hci_data_t);
hci_data->interface_id = HCI_INTERFACE_USB;
hci_data->adapter_id = usb_data->bus_id << 8 | usb_data->device_address;
hci_data->chandle_to_bdaddr_table = chandle_to_bdaddr_table;
hci_data->bdaddr_to_name_table = bdaddr_to_name_table;
hci_data->localhost_bdaddr = localhost_bdaddr;
hci_data->localhost_name = localhost_name;
pinfo->private_data = hci_data;
pinfo->ptype = PT_BLUETOOTH;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!pinfo->fd->flags.visited && usb_data->endpoint <= 0x02) {
fragment_info_t *fragment_info;
fragment_info = (fragment_info_t *) wmem_tree_lookup32(fragment_info_table, session_id);
if (fragment_info == NULL) {
fragment_info = (fragment_info_t *) wmem_new(wmem_file_scope(), fragment_info_t);
fragment_info->fragment_id = 0;
fragment_info->remaining_length = 0;
wmem_tree_insert32(fragment_info_table, session_id, fragment_info);
}
if (fragment_info->fragment_id == 0) {
if (usb_data->endpoint == 0x00) {
fragment_info->remaining_length = tvb_get_guint8(tvb, offset + 2) + 3;
} else if (usb_data->endpoint == 0x01) {
fragment_info->remaining_length = tvb_get_guint8(tvb, offset + 1) + 2;
} else if (usb_data->endpoint == 0x02) {
fragment_info->remaining_length = tvb_get_letohs(tvb, offset + 2) + 4;
}
}
fragment_info->remaining_length -= tvb_ensure_length_remaining(tvb, offset);
fragment_add_seq_check(&hci_usb_reassembly_table,
tvb, offset, pinfo, session_id, NULL,
fragment_info->fragment_id, tvb_length_remaining(tvb, offset), (fragment_info->remaining_length == 0) ? FALSE : TRUE);
if (fragment_info->remaining_length > 0)
fragment_info->fragment_id += 1;
else
fragment_info->fragment_id = 0;
}
reassembled = fragment_get_reassembled_id(&hci_usb_reassembly_table, pinfo, session_id);
if (reassembled && pinfo->fd->num < reassembled->reassembled_in) {
pitem = proto_tree_add_text(ttree, tvb, offset, -1, "Fragment");
PROTO_ITEM_SET_GENERATED(pitem);
col_append_fstr(pinfo->cinfo, COL_INFO, " Fragment");
} else if (reassembled && pinfo->fd->num == reassembled->reassembled_in) {
pitem = proto_tree_add_text(ttree, tvb, offset, -1, "Complete");
PROTO_ITEM_SET_GENERATED(pitem);
if (reassembled->len > tvb_ensure_length_remaining(tvb, offset)) {
next_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled HCI_USB",
reassembled, &hci_usb_msg_frag_items,
NULL, ttree);
}
if (usb_data->endpoint == 0x00) {
call_dissector(find_dissector("bthci_cmd"), next_tvb, pinfo, tree);
} else if (usb_data->endpoint == 0x01) {
call_dissector(find_dissector("bthci_evt"), next_tvb, pinfo, tree);
} else if (usb_data->endpoint == 0x02) {
call_dissector(find_dissector("bthci_acl"), next_tvb, pinfo, tree);
}
} else {
pitem = proto_tree_add_text(ttree, tvb, offset, -1, "Unknown Fragment");
PROTO_ITEM_SET_GENERATED(pitem);
}
if (usb_data->endpoint == 0x03) {
call_dissector(find_dissector("bthci_sco"), next_tvb, pinfo, tree);
} else if (usb_data->endpoint > 0x03) {
proto_tree_add_item(ttree, hf_bthci_usb_data, tvb, offset, -1, ENC_NA);
}
offset += tvb_length_remaining(tvb, offset);
pinfo->p2p_dir = p2p_dir_save;
pinfo->private_data = pd_save;
return offset;
}
void
proto_register_hci_usb(void)
{
module_t *module;
static hf_register_info hf[] = {
{ &hf_msg_fragments,
{ "Message fragments", "hci_usb.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment,
{ "Message fragment", "hci_usb.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_overlap,
{ "Message fragment overlap", "hci_usb.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "hci_usb.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments", "hci_usb.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_too_long_fragment,
{ "Message fragment too long", "hci_usb.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_error,
{ "Message defragmentation error", "hci_usb.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_count,
{ "Message fragment count", "hci_usb.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_reassembled_in,
{ "Reassembled in", "hci_usb.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_reassembled_length,
{ "Reassembled MP2T length", "hci_usb.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthci_usb_data,
{ "Unknown Data", "hci_usb.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_hci_usb,
&ett_hci_usb_msg_fragment,
&ett_hci_usb_msg_fragments,
};
reassembly_table_init(&hci_usb_reassembly_table,
&addresses_reassembly_table_functions);
fragment_info_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
chandle_to_bdaddr_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
bdaddr_to_name_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_bdaddr = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_name = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
proto_hci_usb = proto_register_protocol("Bluetooth HCI USB Transport", "HCI_USB", "hci_usb");
proto_register_field_array(proto_hci_usb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("hci_usb", dissect_hci_usb, proto_hci_usb);
module = prefs_register_protocol(proto_hci_usb, NULL);
prefs_register_static_text_preference(module, "bthci_usb.version",
"Bluetooth HCI USB Transport from Core 4.0",
"Version of protocol supported by this dissector.");
}
void
proto_reg_handoff_hci_usb(void)
{
dissector_handle_t hci_usb_handle;
hci_usb_handle = find_dissector("hci_usb");
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x21e8, hci_usb_handle);
dissector_add_uint("usb.product", (0x1131 << 16) | 0x1001, hci_usb_handle);
dissector_add_uint("usb.product", (0x050d << 16) | 0x0081, hci_usb_handle);
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x2198, hci_usb_handle);
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x21e8, hci_usb_handle);
dissector_add_uint("usb.product", (0x04bf << 16) | 0x0320, hci_usb_handle);
dissector_add_uint("usb.product", (0x13d3 << 16) | 0x3375, hci_usb_handle);
dissector_add_uint("usb.protocol", 0xE00101, hci_usb_handle);
dissector_add_handle("usb.device", hci_usb_handle);
}
