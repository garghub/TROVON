static void
dissect_hci_h4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 type;
tvbuff_t *next_tvb;
proto_item *ti = NULL;
proto_tree *hci_h4_tree = NULL;
void *pd_save;
hci_data_t *hci_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI H4");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_fstr(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_fstr(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
type = tvb_get_guint8(tvb, 0);
if (tree) {
ti = proto_tree_add_item(tree, proto_hci_h4, tvb, 0, 1, ENC_NA);
hci_h4_tree = proto_item_add_subtree(ti, ett_hci_h4);
}
pd_save = pinfo->private_data;
hci_data = (hci_data_t *) wmem_new(wmem_packet_scope(), hci_data_t);
hci_data->interface_id = HCI_INTERFACE_H4;
hci_data->adapter_id = HCI_ADAPTER_DEFAULT;
hci_data->chandle_to_bdaddr_table = chandle_to_bdaddr_table;
hci_data->bdaddr_to_name_table = bdaddr_to_name_table;
hci_data->localhost_bdaddr = localhost_bdaddr;
hci_data->localhost_name = localhost_name;
pinfo->private_data = hci_data;
ti = proto_tree_add_uint(hci_h4_tree, hf_hci_h4_direction, tvb, 0, 0, pinfo->p2p_dir);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(hci_h4_tree, hf_hci_h4_type,
tvb, 0, 1, ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(type, hci_h4_type_vals, "Unknown HCI packet type 0x%02x"));
next_tvb = tvb_new_subset_remaining(tvb, 1);
if (!dissector_try_uint(hci_h4_table, type, next_tvb, pinfo, tree)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
pinfo->private_data = pd_save;
}
void
proto_register_hci_h4(void)
{
static hf_register_info hf[] = {
{ &hf_hci_h4_type,
{ "HCI Packet Type", "hci_h4.type",
FT_UINT8, BASE_HEX, VALS(hci_h4_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_hci_h4_direction,
{ "Direction", "hci_h4.direction",
FT_UINT8, BASE_HEX, VALS(hci_h4_direction_vals), 0x0,
"HCI Packet Direction Sent/Rcvd", HFILL }
}
};
static gint *ett[] = {
&ett_hci_h4,
};
proto_hci_h4 = proto_register_protocol("Bluetooth HCI H4",
"HCI_H4", "hci_h4");
register_dissector("hci_h4", dissect_hci_h4, proto_hci_h4);
proto_register_field_array(proto_hci_h4, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
hci_h4_table = register_dissector_table("hci_h4.type",
"HCI H4 pdu type", FT_UINT8, BASE_HEX);
chandle_to_bdaddr_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
bdaddr_to_name_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_bdaddr = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_name = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void
proto_reg_handoff_hci_h4(void)
{
dissector_handle_t hci_h4_handle;
data_handle = find_dissector("data");
hci_h4_handle = find_dissector("hci_h4");
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_H4, hci_h4_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR, hci_h4_handle);
}
