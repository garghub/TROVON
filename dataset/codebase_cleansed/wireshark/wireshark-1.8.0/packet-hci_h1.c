static void
dissect_hci_h1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 type;
tvbuff_t *next_tvb;
proto_item *ti=NULL;
proto_tree *hci_h1_tree=NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI");
col_clear(pinfo->cinfo, COL_INFO);
type = pinfo->pseudo_header->bthci.channel;
if(tree){
ti = proto_tree_add_item(tree, proto_hci_h1, tvb, 0, 0, ENC_NA);
hci_h1_tree = proto_item_add_subtree(ti, ett_hci_h1);
if(pinfo->p2p_dir == P2P_DIR_SENT ||
pinfo->p2p_dir == P2P_DIR_RECV)
proto_item_append_text(hci_h1_tree, " %s %s",
val_to_str(pinfo->p2p_dir,
hci_h1_direction_vals, "Unknown: %d"),
val_to_str(type,
hci_h1_type_vals,
"Unknown 0x%02x"));
else
proto_item_append_text(hci_h1_tree, " %s",
val_to_str(type,
hci_h1_type_vals,
"Unknown 0x%02x"));
}
if(check_col(pinfo->cinfo, COL_INFO)){
if(pinfo->p2p_dir == P2P_DIR_SENT ||
pinfo->p2p_dir == P2P_DIR_RECV)
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(pinfo->p2p_dir,
hci_h1_direction_vals, "Unknown: %d"),
val_to_str(type, hci_h1_type_vals,
"Unknown 0x%02x"));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(type, hci_h1_type_vals,
"Unknown 0x%02x"));
}
ti=proto_tree_add_int(hci_h1_tree, hf_hci_h1_direction, tvb, 0, 0, pinfo->p2p_dir);
PROTO_ITEM_SET_GENERATED(ti);
next_tvb = tvb_new_subset_remaining(tvb, 0);
if(!dissector_try_uint(hci_h1_table, type, next_tvb, pinfo, tree)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
void
proto_register_hci_h1(void)
{
static hf_register_info hf[] = {
{ &hf_hci_h1_type,
{ "HCI Packet Type", "hci_h1.type",
FT_UINT8, BASE_HEX, VALS(hci_h1_type_vals), 0x0,
NULL, HFILL }},
{ &hf_hci_h1_direction,
{ "Direction", "hci_h1.direction",
FT_INT8, BASE_DEC, VALS(hci_h1_direction_vals), 0x0,
"HCI Packet Direction Sent/Rcvd/Unknown", HFILL }},
};
static gint *ett[] = {
&ett_hci_h1,
};
proto_hci_h1 = proto_register_protocol("Bluetooth HCI",
"HCI_H1", "hci_h1");
register_dissector("hci_h1", dissect_hci_h1, proto_hci_h1);
proto_register_field_array(proto_hci_h1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
hci_h1_table = register_dissector_table("hci_h1.type",
"HCI h1 pdu type", FT_UINT8, BASE_HEX);
}
void
proto_reg_handoff_hci_h1(void)
{
dissector_handle_t hci_h1_handle;
data_handle = find_dissector("data");
hci_h1_handle = find_dissector("hci_h1");
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_HCI, hci_h1_handle);
}
