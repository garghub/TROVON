static int
dissect_epon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *epon_tree;
proto_item *ti;
proto_item *item;
proto_tree *sec_tree;
tvbuff_t *next_tvb;
guint checksum;
guint sent_checksum;
guint offset = 0;
guint dpoe_sec_byte;
gboolean dpoe_encrypted = FALSE;
if (tvb_get_ntoh24(tvb, 0) == 0x55D555) {
offset += 1;
} else if (tvb_get_ntohs(tvb, 0) == 0xD555) {
offset += 0;
} else {
item = proto_tree_add_item(tree, proto_epon, tvb, offset, 0, ENC_NA);
expert_add_info(pinfo, item, &ei_epon_sld_bad);
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EPON");
col_set_str(pinfo->cinfo, COL_INFO, "EPON Preamble");
ti = proto_tree_add_item(tree, proto_epon, tvb, 0+offset, 6, ENC_NA);
epon_tree = proto_item_add_subtree(ti, ett_epon);
dpoe_sec_byte = tvb_get_guint8(tvb, 2+offset);
if (dpoe_sec_byte != 0x55) {
guint dpoe_keyid;
guint dpoe_reserved;
item = proto_tree_add_item(epon_tree, hf_epon_dpoe_security,
tvb, 2+offset, 1, ENC_BIG_ENDIAN);
sec_tree = proto_item_add_subtree(item, ett_epon_sec);
dpoe_reserved = dpoe_sec_byte & 0xFC;
dpoe_encrypted = dpoe_sec_byte & 0x02;
dpoe_keyid = dpoe_sec_byte & 0x01;
proto_item_append_text(item, " (Encrypted: ");
if (dpoe_encrypted) {
proto_item_append_text(item, "True, Key ID: %x", dpoe_keyid);
} else {
proto_item_append_text(item, "False");
}
proto_item_append_text(item, ")");
if (dpoe_reserved != 0x54) {
proto_tree_add_item(sec_tree, hf_epon_dpoe_reserved, tvb, 2+offset, 1,
ENC_BIG_ENDIAN);
expert_add_info(pinfo, sec_tree, &ei_epon_dpoe_reserved_bad);
}
proto_tree_add_item(sec_tree, hf_epon_dpoe_encrypted, tvb, 2+offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(sec_tree, hf_epon_dpoe_keyid, tvb, 2+offset, 1,
ENC_BIG_ENDIAN);
if (!dpoe_encrypted && (dpoe_keyid == 0)) {
expert_add_info(pinfo, sec_tree, &ei_epon_dpoe_bad);
}
}
proto_tree_add_item(epon_tree, hf_epon_mode, tvb, 3+offset, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(epon_tree, hf_epon_llid, tvb, 3+offset, 2,
ENC_BIG_ENDIAN);
sent_checksum = tvb_get_guint8(tvb, 5+offset);
checksum = get_crc8_ieee8023_epon(tvb, 5, 0+offset);
proto_tree_add_checksum(epon_tree, tvb, 5+offset, hf_epon_checksum, -1, &ei_epon_checksum_bad, pinfo, checksum, ENC_NA, PROTO_CHECKSUM_VERIFY);
if (sent_checksum != checksum) {
col_append_str(pinfo->cinfo, COL_INFO, " [EPON PREAMBLE CHECKSUM INCORRECT]");
}
if (dpoe_encrypted) {
item = proto_tree_add_item(tree, hf_epon_dpoe_encrypted_data, tvb,
6+offset, -1, ENC_NA);
expert_add_info(pinfo, item, &ei_epon_dpoe_encrypted_data);
col_append_str(pinfo->cinfo, COL_INFO, " [ENCRYPTED]");
} else {
next_tvb = tvb_new_subset_remaining(tvb, 6+offset);
call_dissector(eth_maybefcs_handle, next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_epon(void)
{
expert_module_t *expert_epon;
static hf_register_info hf[] = {
{ &hf_epon_dpoe_security,
{ "DPoE security", "epon.dpoe.sec", FT_UINT8, BASE_HEX, NULL, 0x0,
"DPoE security octet", HFILL }
},
{ &hf_epon_dpoe_reserved,
{ "Reserved", "epon.dpoe.reserved", FT_UINT8, BASE_DEC, NULL, 0xFC,
"Reserved in 1G mode", HFILL }
},
{ &hf_epon_dpoe_encrypted,
{ "Encryption enabled", "epon.dpoe.encrypted", FT_BOOLEAN, 8, NULL, 0x02,
"Specifies if this is an encrypted frame", HFILL }
},
{ &hf_epon_dpoe_keyid,
{ "Key ID", "epon.dpoe.keyid", FT_UINT8, BASE_HEX, NULL, 0x01,
"Identification number of the key used to encrypt this frame",
HFILL }
},
{ &hf_epon_dpoe_encrypted_data,
{ "Encrypted data", "epon.dpoe.encrypted.data", FT_BYTES, BASE_NONE,
NULL, 0x0, "DPoE encrypted data", HFILL }
},
{ &hf_epon_mode,
{ "Mode", "epon.mode", FT_BOOLEAN, 16, TFS(&epon_mode_tfs), 0x8000,
"Broadcast/multicast if true, unicast if false", HFILL }
},
{ &hf_epon_llid,
{ "LLID", "epon.llid", FT_UINT16, BASE_DEC_HEX, NULL, 0x7FFF,
"Logical Link ID", HFILL }
},
{ &hf_epon_checksum,
{ "Frame check sequence", "epon.checksum", FT_UINT8, BASE_HEX, NULL,
0x0, "EPON preamble checksum", HFILL }
},
};
static gint *ett[] = {
&ett_epon,
&ett_epon_sec,
&ett_epon_checksum
};
static ei_register_info ei[] = {
{ &ei_epon_checksum_bad,
{ "epon.checksum_bad.expert", PI_CHECKSUM, PI_ERROR,
"Bad checksum", EXPFILL }
},
{ &ei_epon_sld_bad,
{ "epon.sld_bad.expert", PI_MALFORMED, PI_ERROR,
"Unable to locate SLD or invalid byte sequence: preamble must start with 0xD555", EXPFILL }
},
{ &ei_epon_dpoe_reserved_bad,
{ "epon.dpoe.encrypted.expert", PI_MALFORMED, PI_ERROR,
"Bits 7-2 of DPoE security byte must be 010101 in 1G mode.", EXPFILL }
},
{ &ei_epon_dpoe_bad,
{ "epon.dpoe.expert", PI_MALFORMED, PI_ERROR,
"DPoE security byte must be 0x55 if encryption is disabled.", EXPFILL }
},
{ &ei_epon_dpoe_encrypted_data,
{ "epon.dpoe.encrypted.expert", PI_UNDECODED, PI_NOTE,
"Remaining data is encrypted and will not decode.", EXPFILL }
}
};
proto_epon = proto_register_protocol("IEEE 802.3 EPON Preamble",
"EPON", "epon");
proto_register_field_array(proto_epon, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_epon = expert_register_protocol(proto_epon);
expert_register_field_array(expert_epon, ei, array_length(ei));
}
void
proto_reg_handoff_epon(void)
{
dissector_handle_t epon_handle;
epon_handle = create_dissector_handle(dissect_epon, proto_epon);
dissector_add_uint("wtap_encap", WTAP_ENCAP_EPON, epon_handle);
eth_maybefcs_handle = find_dissector_add_dependency("eth_maybefcs", proto_epon);
}
