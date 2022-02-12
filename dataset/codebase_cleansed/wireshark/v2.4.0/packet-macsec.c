static int dissect_macsec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
unsigned sectag_length, data_length, icv_length;
unsigned data_offset, icv_offset;
guint8 tci_an_field;
proto_item *macsec_item;
proto_tree *macsec_tree;
tvbuff_t *next_tvb;
tci_an_field = tvb_get_guint8(tvb, 0);
if ((tci_an_field & TCI_V_MASK) != 0) {
return 0;
}
icv_length = 16;
if (tci_an_field & TCI_SC_MASK) {
sectag_length = 14;
} else {
sectag_length = 6;
}
if (tvb_captured_length(tvb) <= (sectag_length + icv_length)) {
return 0;
}
data_offset = sectag_length;
data_length = tvb_captured_length(tvb) - sectag_length - icv_length;
icv_offset = data_length + data_offset;
next_tvb = tvb_new_subset_length(tvb, data_offset, data_length);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MACSEC");
col_set_str(pinfo->cinfo, COL_INFO, "MACsec frame");
if (tree) {
macsec_item = proto_tree_add_item(tree,
proto_macsec, tvb, 0, sectag_length, ENC_NA);
macsec_tree = proto_item_add_subtree(macsec_item, ett_macsec);
static const int * flags[] = {
&hf_macsec_TCI_V,
&hf_macsec_TCI_ES,
&hf_macsec_TCI_SC,
&hf_macsec_TCI_SCB,
&hf_macsec_TCI_E,
&hf_macsec_TCI_C,
NULL
};
proto_tree_add_bitmask_with_flags(macsec_tree, tvb, 0,
hf_macsec_TCI, ett_macsec_tci, flags, ENC_NA, BMT_NO_TFS);
proto_tree_add_item(macsec_tree, hf_macsec_AN, tvb, 0, 1, ENC_NA);
proto_tree_add_item(macsec_tree, hf_macsec_SL, tvb, 1, 1, ENC_NA);
proto_tree_add_item(macsec_tree, hf_macsec_PN, tvb, 2, 4, ENC_BIG_ENDIAN);
if (sectag_length == 14) {
proto_tree_add_item(macsec_tree, hf_macsec_SCI_system_identifier,
tvb, 6, 6, ENC_NA);
proto_tree_add_item(macsec_tree, hf_macsec_SCI_port_identifier, tvb,
12, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(macsec_tree, hf_macsec_ICV, tvb, icv_offset,
icv_length, ENC_NA);
}
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_macsec(void)
{
static hf_register_info hf[] = {
{ &hf_macsec_TCI,
{ "TCI", "macsec.TCI", FT_UINT8, BASE_HEX,
NULL, TCI_MASK, "TAG Control Information", HFILL }
},
{ &hf_macsec_TCI_V,
{ "VER", "macsec.TCI.V", FT_UINT8, BASE_HEX,
NULL, TCI_V_MASK, "Version", HFILL }
},
{ &hf_macsec_TCI_ES,
{ "ES", "macsec.TCI.ES", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), TCI_ES_MASK, "End Station", HFILL }
},
{ &hf_macsec_TCI_SC,
{ "SC", "macsec.TCI.SC", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), TCI_SC_MASK, "Secure Channel", HFILL }
},
{ &hf_macsec_TCI_SCB,
{ "SCB", "macsec.TCI.SCB", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), TCI_SCB_MASK, "Single Copy Broadcast", HFILL }
},
{ &hf_macsec_TCI_E,
{ "E", "macsec.TCI.E", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), TCI_E_MASK, "Encryption", HFILL }
},
{ &hf_macsec_TCI_C,
{ "C", "macsec.TCI.C", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), TCI_C_MASK, "Changed Text", HFILL }
},
{ &hf_macsec_AN,
{ "AN", "macsec.AN", FT_UINT8, BASE_HEX,
NULL, AN_MASK, "Association Number", HFILL }
},
{ &hf_macsec_SL,
{ "Short length", "macsec.SL", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_macsec_PN,
{ "Packet number", "macsec.PN", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_macsec_SCI_system_identifier,
{ "System Identifier", "macsec.SCI.system_identifier", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_macsec_SCI_port_identifier,
{ "Port Identifier", "macsec.SCI.port_identifier", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_macsec_ICV,
{ "ICV", "macsec.ICV", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_macsec,
&ett_macsec_tci
};
proto_macsec = proto_register_protocol("802.1AE Security tag", "MACsec", "macsec");
proto_register_field_array(proto_macsec, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_macsec(void)
{
dissector_handle_t macsec_handle;
macsec_handle = create_dissector_handle(dissect_macsec, proto_macsec);
dissector_add_uint("ethertype", ETHERTYPE_MACSEC, macsec_handle);
}
