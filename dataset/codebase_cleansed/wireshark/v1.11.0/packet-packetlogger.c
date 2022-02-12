static void dissect_packetlogger (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *packetlogger_tree = NULL;
tvbuff_t *next_tvb;
proto_item *ti = NULL;
guint8 pl_type;
gint len;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear (pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item (tree, proto_packetlogger, tvb, 0, -1, ENC_NA);
packetlogger_tree = proto_item_add_subtree (ti, ett_packetlogger);
pl_type = tvb_get_guint8 (tvb, 0);
proto_tree_add_item (packetlogger_tree, hf_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_append_text (ti, " %s", val_to_str (pl_type, type_vals, "Unknown 0x%02x"));
len = tvb_length_remaining (tvb, 1);
next_tvb = tvb_new_subset (tvb, 1, len, len);
if (pl_type <= PKT_RECV_ACL_DATA) {
switch (pl_type) {
case PKT_HCI_COMMAND:
pinfo->pseudo_header->bthci.channel = BTHCI_CHANNEL_COMMAND;
pinfo->pseudo_header->bthci.sent = P2P_DIR_SENT;
pinfo->p2p_dir = P2P_DIR_SENT;
break;
case PKT_HCI_EVENT:
pinfo->pseudo_header->bthci.channel = BTHCI_CHANNEL_EVENT;
pinfo->pseudo_header->bthci.sent = P2P_DIR_RECV;
pinfo->p2p_dir = P2P_DIR_RECV;
break;
case PKT_SENT_ACL_DATA:
pinfo->pseudo_header->bthci.channel = BTHCI_CHANNEL_ACL;
pinfo->pseudo_header->bthci.sent = P2P_DIR_SENT;
pinfo->p2p_dir = P2P_DIR_SENT;
break;
case PKT_RECV_ACL_DATA:
pinfo->pseudo_header->bthci.channel = BTHCI_CHANNEL_ACL;
pinfo->pseudo_header->bthci.sent = P2P_DIR_RECV;
pinfo->p2p_dir = P2P_DIR_RECV;
break;
default:
pinfo->pseudo_header->bthci.channel = pl_type;
pinfo->pseudo_header->bthci.sent = P2P_DIR_UNKNOWN;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
break;
}
proto_item_set_len (ti, 1);
col_add_fstr (pinfo->cinfo, COL_INFO, "%s", val_to_str(pl_type, type_vals, "Unknown 0x%02x"));
if (!dissector_try_uint (hci_h1_table, pinfo->pseudo_header->bthci.channel, next_tvb, pinfo, tree)) {
call_dissector (data_handle, next_tvb, pinfo, tree);
}
} else {
switch (pl_type) {
case PKT_POWER:
case PKT_NOTE:
case PKT_NEW_CONTROLLER:
proto_tree_add_item (packetlogger_tree, hf_info, next_tvb, 0, len, ENC_ASCII|ENC_NA);
col_add_fstr (pinfo->cinfo, COL_INFO, "%s", tvb_format_stringzpad_wsp (next_tvb, 0, len));
break;
default:
call_dissector (data_handle, next_tvb, pinfo, tree);
col_add_fstr (pinfo->cinfo, COL_INFO, "Unknown 0x%02x", pl_type);
break;
}
}
}
void proto_register_packetlogger (void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "packetlogger.type", FT_UINT8, BASE_HEX, VALS(type_vals), 0x0, NULL, HFILL } },
{ &hf_info,
{ "Info", "packetlogger.info", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_packetlogger
};
proto_packetlogger = proto_register_protocol (PNAME, PSNAME, PFNAME);
packetlogger_handle = register_dissector (PFNAME, dissect_packetlogger, proto_packetlogger);
proto_register_field_array (proto_packetlogger, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void proto_reg_handoff_packetlogger (void)
{
hci_h1_table = find_dissector_table("hci_h1.type");
data_handle = find_dissector("data");
dissector_add_uint ("wtap_encap", WTAP_ENCAP_PACKETLOGGER, packetlogger_handle);
}
