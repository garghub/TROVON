static void
dissect_sap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int sap_version, is_ipv6, is_del, is_enc, is_comp, addr_len;
guint8 vers_flags;
guint8 auth_len;
guint8 auth_flags;
tvbuff_t *next_tvb;
proto_item *si, *sif;
proto_tree *sap_tree = NULL, *sap_flags_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAP");
col_clear(pinfo->cinfo, COL_INFO);
vers_flags = tvb_get_guint8(tvb, offset);
is_ipv6 = vers_flags&MCAST_SAP_BIT_A;
is_del = vers_flags&MCAST_SAP_BIT_T;
is_enc = vers_flags&MCAST_SAP_BIT_E;
is_comp = vers_flags&MCAST_SAP_BIT_C;
sap_version = (vers_flags&MCAST_SAP_VERSION_MASK)>>MCAST_SAP_VERSION_SHIFT;
addr_len = (is_ipv6) ? (int)sizeof(struct e_in6_addr) : 4;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (v%u)",
(is_del) ? "Deletion" : "Announcement", sap_version);
if (tree) {
si = proto_tree_add_item(tree, proto_sap, tvb, offset, -1, ENC_NA);
sap_tree = proto_item_add_subtree(si, ett_sap);
sif = proto_tree_add_item(sap_tree, hf_sap_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
sap_flags_tree = proto_item_add_subtree(sif, ett_sap_flags);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_v, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_a, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_r, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_t, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_e, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sap_flags_tree, hf_sap_flags_c, tvb, offset, 1, ENC_NA);
}
offset++;
auth_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sap_tree, hf_sap_auth_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sap_tree, hf_sap_message_identifier_hash, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
if (is_ipv6)
proto_tree_add_item(sap_tree, hf_sap_originating_source_ipv6, tvb, offset, addr_len, ENC_NA);
else
proto_tree_add_item(sap_tree, hf_sap_originating_source_ipv4, tvb, offset, addr_len, ENC_BIG_ENDIAN);
offset += addr_len;
if (auth_len > 0) {
guint32 auth_data_len;
proto_item *sdi, *sai;
proto_tree *sa_tree, *saf_tree;
int has_pad;
guint8 pad_len = 0;
auth_data_len = (guint32)(auth_len * sizeof(guint32));
sdi = proto_tree_add_item(sap_tree, hf_auth_data, tvb, offset, auth_data_len, ENC_NA);
sa_tree = proto_item_add_subtree(sdi, ett_sap_auth);
auth_flags = tvb_get_guint8(tvb, offset);
sai = proto_tree_add_item(sa_tree, hf_auth_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
saf_tree = proto_item_add_subtree(sai, ett_sap_authf);
proto_tree_add_item(saf_tree, hf_auth_flags_v, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(saf_tree, hf_auth_flags_p, tvb, offset, 1, ENC_NA);
proto_tree_add_item(saf_tree, hf_auth_flags_t, tvb, offset, 1, ENC_BIG_ENDIAN);
has_pad = auth_flags&MCAST_SAP_AUTH_BIT_P;
if (has_pad) {
pad_len = tvb_get_guint8(tvb, offset+auth_data_len-1);
}
if ((int) auth_data_len - pad_len - 1 < 0) {
expert_add_info_format(pinfo, sai, &ei_sap_bogus_authentication_or_pad_length,
"Bogus authentication length (%d) or pad length (%d)", auth_len, pad_len);
return;
}
proto_tree_add_item(sa_tree, hf_sap_auth_subheader, tvb, offset+1, auth_data_len-pad_len-1, ENC_NA);
if (has_pad) {
proto_tree_add_item(sa_tree, hf_sap_auth_data_padding_len, tvb, offset+auth_data_len-1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sa_tree, hf_sap_auth_data_padding, tvb, offset+auth_data_len-pad_len, pad_len, ENC_NA);
}
offset += auth_data_len;
}
if (is_enc || is_comp) {
expert_field *mangle;
if (is_enc && is_comp)
mangle = &ei_sap_compressed_and_encrypted;
else if (is_enc)
mangle = &ei_sap_encrypted;
else
mangle = &ei_sap_compressed;
proto_tree_add_expert(sap_tree, pinfo, mangle, tvb, offset, -1);
return;
}
if (tree) {
if (tvb_strneql(tvb, offset, "v=", strlen("v="))) {
gint remaining_len;
guint32 pt_len;
int pt_string_len;
guint8* pt_str;
remaining_len = tvb_captured_length_remaining(tvb, offset);
if (remaining_len == 0) {
remaining_len = 1;
}
pt_string_len = tvb_strnlen(tvb, offset, remaining_len);
if (pt_string_len == -1) {
pt_string_len = remaining_len;
pt_len = pt_string_len;
} else {
pt_len = pt_string_len + 1;
}
pt_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, pt_string_len, ENC_ASCII);
proto_tree_add_string_format_value(sap_tree, hf_sap_payload_type, tvb, offset, pt_len,
pt_str, "%.*s", pt_string_len, pt_str);
offset += pt_len;
}
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(sdp_handle, next_tvb, pinfo, tree);
}
void proto_register_sap(void)
{
static hf_register_info hf[] = {
{ &hf_sap_flags,
{ "Flags", "sap.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits in the beginning of the SAP header", HFILL }},
{ &hf_sap_flags_v,
{ "Version Number", "sap.flags.v",
FT_UINT8, BASE_DEC, VALS(mcast_sap_ver), MCAST_SAP_VERSION_MASK,
"3 bit version field in the SAP header", HFILL }},
{ &hf_sap_flags_a,
{ "Address Type", "sap.flags.a",
FT_BOOLEAN, 8, TFS(&mcast_sap_address_type), MCAST_SAP_BIT_A,
"Originating source address type", HFILL }},
{ &hf_sap_flags_r,
{ "Reserved", "sap.flags.r",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MCAST_SAP_BIT_R,
NULL, HFILL }},
{ &hf_sap_flags_t,
{ "Message Type", "sap.flags.t",
FT_BOOLEAN, 8, TFS(&mcast_sap_message_type), MCAST_SAP_BIT_T,
"Announcement type", HFILL }},
{ &hf_sap_flags_e,
{ "Encryption Bit", "sap.flags.e",
FT_BOOLEAN, 8, TFS(&mcast_sap_crypt_type), MCAST_SAP_BIT_E,
NULL, HFILL }},
{ &hf_sap_flags_c,
{ "Compression Bit", "sap.flags.c",
FT_BOOLEAN, 8, TFS(&mcast_sap_comp_type), MCAST_SAP_BIT_C,
NULL, HFILL }},
{ &hf_auth_data,
{ "Authentication data", "sap.auth",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_auth_flags,
{ "Authentication data flags", "sap.auth.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_auth_flags_v,
{ "Version Number", "sap.auth.flags.v",
FT_UINT8, BASE_DEC, VALS(mcast_sap_auth_ver), MCAST_SAP_VERSION_MASK,
NULL, HFILL }},
{ &hf_auth_flags_p,
{ "Padding Bit", "sap.auth.flags.p",
FT_BOOLEAN, 8, TFS(&mcast_sap_auth_pad), MCAST_SAP_AUTH_BIT_P,
NULL, HFILL }},
{ &hf_auth_flags_t,
{ "Authentication Type", "sap.auth.flags.t",
FT_UINT8, BASE_DEC, VALS(mcast_sap_auth_type), MCAST_SAP_AUTH_TYPE_MASK,
NULL, HFILL }},
{ &hf_sap_auth_len, { "Authentication Length", "sap.auth.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_message_identifier_hash, { "Message Identifier Hash", "sap.message_identifier_hash", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_originating_source_ipv4, { "Originating Source", "sap.originating_source", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_originating_source_ipv6, { "Originating Source", "sap.originating_source", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_auth_subheader, { "Authentication subheader", "sap.auth.subheader", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_auth_data_padding, { "Authentication data padding", "sap.auth.data_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_auth_data_padding_len, { "Authentication data pad count (bytes)", "sap.auth.data_padding.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_payload_type, { "Payload type", "sap.payload_type", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_sap,
&ett_sap_flags,
&ett_sap_auth,
&ett_sap_authf,
};
static ei_register_info ei[] = {
{ &ei_sap_compressed_and_encrypted, { "sap.compressed_and_encrypted", PI_UNDECODED, PI_WARN, "The rest of the packet is compressed and encrypted", EXPFILL }},
{ &ei_sap_encrypted, { "sap.encrypted", PI_UNDECODED, PI_WARN, "The rest of the packet is encrypted", EXPFILL }},
{ &ei_sap_compressed, { "sap.compressed", PI_UNDECODED, PI_WARN, "The rest of the packet is compressed", EXPFILL }},
{ &ei_sap_bogus_authentication_or_pad_length, { "sap.bogus_authentication_or_pad_length", PI_PROTOCOL, PI_WARN, "Bogus authentication length", EXPFILL }},
};
expert_module_t* expert_sap;
proto_sap = proto_register_protocol("Session Announcement Protocol", "SAP", "sap");
proto_register_field_array(proto_sap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sap = expert_register_protocol(proto_sap);
expert_register_field_array(expert_sap, ei, array_length(ei));
}
void
proto_reg_handoff_sap(void)
{
dissector_handle_t sap_handle;
sap_handle = create_dissector_handle(dissect_sap, proto_sap);
dissector_add_uint("udp.port", UDP_PORT_SAP, sap_handle);
sdp_handle = find_dissector("sdp");
}
