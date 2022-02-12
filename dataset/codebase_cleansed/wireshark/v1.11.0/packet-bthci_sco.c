static void
dissect_bthci_sco(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
proto_tree *bthci_sco_tree;
int offset = 0;
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
ti = proto_tree_add_item(tree, proto_bthci_sco, tvb, offset, -1, ENC_NA);
bthci_sco_tree = proto_item_add_subtree(ti, ett_bthci_sco);
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_chandle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_data, tvb, offset, -1, ENC_NA);
}
void
proto_register_bthci_sco(void)
{
static hf_register_info hf[] = {
{ &hf_bthci_sco_chandle,
{ "Connection Handle", "bthci_sco.chandle",
FT_UINT16, BASE_HEX, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_bthci_sco_length,
{ "Data Total Length", "bthci_sco.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_sco_data,
{ "Data", "bthci_sco.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bthci_sco
};
proto_bthci_sco = proto_register_protocol("Bluetooth HCI SCO Packet", "HCI_SCO", "bthci_sco");
register_dissector("bthci_sco", dissect_bthci_sco, proto_bthci_sco);
proto_register_field_array(proto_bthci_sco, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bthci_sco(void)
{
dissector_handle_t bthci_sco_handle;
bthci_sco_handle = find_dissector("bthci_sco");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_SCO, bthci_sco_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_SCO, bthci_sco_handle);
}
