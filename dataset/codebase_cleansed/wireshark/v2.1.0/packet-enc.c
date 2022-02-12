static gboolean
capture_enc(const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
guint32 af;
if (!BYTES_ARE_IN_FRAME(0, len, BSD_ENC_HDRLEN))
return FALSE;
af = pntoh32(pd);
return try_capture_dissector("enc", af, pd, BSD_ENC_HDRLEN, len, cpinfo, pseudo_header);
}
static int
dissect_enc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
struct enchdr ench;
tvbuff_t *next_tvb;
proto_tree *enc_tree;
proto_item *ti;
static const int *flags[] = {
&hf_enc_flags_payload_enc,
&hf_enc_flags_payload_auth,
&hf_enc_flags_payload_compress,
&hf_enc_flags_header_auth,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ENC");
ench.af = tvb_get_ntohl(tvb, 0);
ench.spi = tvb_get_ntohl(tvb, 4);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_enc, tvb, 0,
BSD_ENC_HDRLEN,
"Enc %s, SPI 0x%8.8x",
val_to_str(ench.af, af_vals, "unknown (%u)"),
ench.spi);
enc_tree = proto_item_add_subtree(ti, ett_enc);
proto_tree_add_item(enc_tree, hf_enc_af, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(enc_tree, hf_enc_spi, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(enc_tree, tvb, 8, hf_enc_flags, ett_enc_flag, flags, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, BSD_ENC_HDRLEN);
if (!dissector_try_uint(enc_dissector_table, ench.af, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_enc(void)
{
static hf_register_info hf[] = {
{ &hf_enc_af,
{ "Address Family", "enc.af", FT_UINT32, BASE_DEC, VALS(af_vals), 0x0,
"Protocol (IPv4 vs IPv6)", HFILL }},
{ &hf_enc_spi,
{ "SPI", "enc.spi", FT_UINT32, BASE_HEX, NULL, 0x0,
"Security Parameter Index", HFILL }},
{ &hf_enc_flags,
{ "Flags", "enc.flags", FT_UINT32, BASE_HEX, NULL, 0x0,
"ENC flags", HFILL }},
{ &hf_enc_flags_payload_enc,
{ "Payload encrypted", "enc.flags.payload_enc", FT_BOOLEAN, 32, NULL, BSD_ENC_M_CONF,
NULL, HFILL }},
{ &hf_enc_flags_payload_auth,
{ "Payload encrypted", "enc.flags.payload_auth", FT_BOOLEAN, 32, NULL, BSD_ENC_M_AUTH,
NULL, HFILL }},
{ &hf_enc_flags_payload_compress,
{ "Payload encrypted", "enc.flags.payload_compress", FT_BOOLEAN, 32, NULL, BSD_ENC_M_COMP,
NULL, HFILL }},
{ &hf_enc_flags_header_auth,
{ "Payload encrypted", "enc.flags.header_auth", FT_BOOLEAN, 32, NULL, BSD_ENC_M_AUTH_AH,
NULL, HFILL }},
};
static gint *ett[] =
{
&ett_enc,
&ett_enc_flag
};
proto_enc = proto_register_protocol("OpenBSD Encapsulating device",
"ENC", "enc");
proto_register_field_array(proto_enc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
enc_dissector_table = register_dissector_table("enc", "OpenBSD Encapsulating device", proto_enc, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_capture_dissector_table("enc", "ENC");
}
void
proto_reg_handoff_enc(void)
{
dissector_handle_t enc_handle;
enc_handle = create_dissector_handle(dissect_enc, proto_enc);
dissector_add_uint("wtap_encap", WTAP_ENCAP_ENC, enc_handle);
register_capture_dissector("wtap_encap", WTAP_ENCAP_ENC, capture_enc, proto_enc);
}
