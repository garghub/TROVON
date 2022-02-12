static void
dissect_btsco(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
proto_tree *btsco_tree;
int offset = 0;
ti = proto_tree_add_item(tree, proto_btsco, tvb, offset, -1, ENC_NA);
btsco_tree = proto_item_add_subtree(ti, ett_btsco);
proto_tree_add_item(btsco_tree, hf_btsco_chandle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(btsco_tree, hf_btsco_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(btsco_tree, hf_btsco_data, tvb, offset, -1, ENC_NA);
}
void
proto_register_btsco(void)
{
static hf_register_info hf[] = {
{ &hf_btsco_chandle,
{ "Connection Handle", "bthci_sco.chandle",
FT_UINT16, BASE_HEX, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_btsco_length,
{ "Data Total Length", "bthci_sco.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btsco_data,
{ "Data", "bthci_sco.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btsco,
};
proto_btsco = proto_register_protocol("Bluetooth HCI SCO Packet", "HCI_SCO", "bthci_sco");
register_dissector("bthci_sco", dissect_btsco, proto_btsco);
proto_register_field_array(proto_btsco, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btsco(void)
{
dissector_handle_t bthci_sco_handle;
bthci_sco_handle = find_dissector("bthci_sco");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_SCO, bthci_sco_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_SCO, bthci_sco_handle);
}
