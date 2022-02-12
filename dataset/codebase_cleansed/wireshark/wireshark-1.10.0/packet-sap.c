static void
dissect_sap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int sap_version, is_ipv6, is_del, is_enc, is_comp, addr_len;
guint8 vers_flags;
guint8 auth_len;
guint16 tmp1;
guint8 auth_flags;
tvbuff_t *next_tvb;
proto_item *si, *sif;
proto_tree *sap_tree, *sap_flags_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAP");
col_clear(pinfo->cinfo, COL_INFO);
vers_flags = tvb_get_guint8(tvb, offset);
is_ipv6 = vers_flags&MCAST_SAP_BIT_A;
is_del = vers_flags&MCAST_SAP_BIT_T;
is_enc = vers_flags&MCAST_SAP_BIT_E;
is_comp = vers_flags&MCAST_SAP_BIT_C;
sap_version = (vers_flags&MCAST_SAP_VERSION_MASK)>>MCAST_SAP_VERSION_SHIFT;
addr_len = (is_ipv6) ? (int)sizeof(struct e_in6_addr) : 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (v%u)",
(is_del) ? "Deletion" : "Announcement", sap_version);
}
if (tree) {
si = proto_tree_add_item(tree, proto_sap, tvb, offset, -1, ENC_NA);
sap_tree = proto_item_add_subtree(si, ett_sap);
sif = proto_tree_add_uint(sap_tree, hf_sap_flags, tvb, offset, 1, vers_flags);
sap_flags_tree = proto_item_add_subtree(sif, ett_sap_flags);
proto_tree_add_uint(sap_flags_tree, hf_sap_flags_v, tvb, offset, 1, vers_flags);
proto_tree_add_boolean(sap_flags_tree, hf_sap_flags_a, tvb, offset, 1, vers_flags);
proto_tree_add_boolean(sap_flags_tree, hf_sap_flags_r, tvb, offset, 1, vers_flags);
proto_tree_add_boolean(sap_flags_tree, hf_sap_flags_t, tvb, offset, 1, vers_flags);
proto_tree_add_boolean(sap_flags_tree, hf_sap_flags_e, tvb, offset, 1, vers_flags);
proto_tree_add_boolean(sap_flags_tree, hf_sap_flags_c, tvb, offset, 1, vers_flags);
offset++;
auth_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sap_tree, tvb, offset, 1, "Authentication Length: %u", auth_len);
offset++;
tmp1 = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(sap_tree, tvb, offset, 2, "Message Identifier Hash: 0x%x", tmp1);
offset +=2;
proto_tree_add_text(sap_tree, tvb, offset, addr_len, "Originating Source: %s",
(is_ipv6) ? tvb_ip6_to_str(tvb, offset) : tvb_ip_to_str(tvb, offset));
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
sai = proto_tree_add_uint(sa_tree, hf_auth_flags, tvb, offset, 1, auth_flags);
saf_tree = proto_item_add_subtree(sai, ett_sap_authf);
proto_tree_add_uint(saf_tree, hf_auth_flags_v, tvb, offset, 1, auth_flags);
proto_tree_add_boolean(saf_tree, hf_auth_flags_p, tvb, offset, 1, auth_flags);
proto_tree_add_uint(saf_tree, hf_auth_flags_t, tvb, offset, 1, auth_flags);
has_pad = auth_flags&MCAST_SAP_AUTH_BIT_P;
if (has_pad)
pad_len = tvb_get_guint8(tvb, offset+auth_data_len-1);
if ((int) auth_data_len - pad_len - 1 < 0) {
proto_tree_add_text(sa_tree, tvb, 0, 0,
"Bogus authentication length (%d) or pad length (%d)",
auth_len, pad_len);
return;
}
proto_tree_add_text(sa_tree, tvb, offset+1, auth_data_len-pad_len-1,
"Authentication subheader: (%u byte%s)",
auth_data_len-1, plurality(auth_data_len-1, "", "s"));
if (has_pad) {
proto_tree_add_text(sa_tree, tvb, offset+auth_data_len-pad_len, pad_len,
"Authentication data padding: (%u byte%s)",
pad_len, plurality(pad_len, "", "s"));
proto_tree_add_text(sa_tree, tvb, offset+auth_data_len-1, 1,
"Authentication data pad count: %u byte%s",
pad_len, plurality(pad_len, "", "s"));
}
offset += auth_data_len;
}
if (is_enc || is_comp) {
const char *mangle;
if (is_enc && is_comp) mangle = "compressed and encrypted";
else if (is_enc) mangle = "encrypted";
else mangle = "compressed";
proto_tree_add_text(sap_tree, tvb, offset, -1,
"The rest of the packet is %s", mangle);
return;
}
if (tvb_strneql(tvb, offset, "v=", strlen("v="))) {
gint remaining_len;
guint32 pt_len;
int pt_string_len;
remaining_len = tvb_length_remaining(tvb, offset);
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
proto_tree_add_text(sap_tree, tvb, offset, pt_len,
"Payload type: %.*s", pt_string_len,
tvb_get_ephemeral_string(tvb, offset, pt_string_len));
offset += pt_len;
}
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(sdp_handle, next_tvb, pinfo, tree);
return;
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
"Encryption", HFILL }},
{ &hf_sap_flags_c,
{ "Compression Bit", "sap.flags.c",
FT_BOOLEAN, 8, TFS(&mcast_sap_comp_type), MCAST_SAP_BIT_C,
"Compression", HFILL }},
{ &hf_auth_data,
{ "Authentication data", "sap.auth",
FT_NONE, BASE_NONE, NULL, 0x0,
"Auth data", HFILL }},
{ &hf_auth_flags,
{ "Authentication data flags", "sap.auth.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Auth flags", HFILL }},
{ &hf_auth_flags_v,
{ "Version Number", "sap.auth.flags.v",
FT_UINT8, BASE_DEC, VALS(mcast_sap_auth_ver), MCAST_SAP_VERSION_MASK,
"Version", HFILL }},
{ &hf_auth_flags_p,
{ "Padding Bit", "sap.auth.flags.p",
FT_BOOLEAN, 8, TFS(&mcast_sap_auth_pad), MCAST_SAP_AUTH_BIT_P,
"Compression", HFILL }},
{ &hf_auth_flags_t,
{ "Authentication Type", "sap.auth.flags.t",
FT_UINT8, BASE_DEC, VALS(mcast_sap_auth_type), MCAST_SAP_AUTH_TYPE_MASK,
"Auth type", HFILL }}
};
static gint *ett[] = {
&ett_sap,
&ett_sap_flags,
&ett_sap_auth,
&ett_sap_authf,
};
proto_sap = proto_register_protocol("Session Announcement Protocol", "SAP",
"sap");
proto_register_field_array(proto_sap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sap(void)
{
dissector_handle_t sap_handle;
sap_handle = create_dissector_handle(dissect_sap, proto_sap);
dissector_add_uint("udp.port", UDP_PORT_SAP, sap_handle);
sdp_handle = find_dissector("sdp");
}
