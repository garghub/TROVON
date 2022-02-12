static void
dissect_cert(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *subtree = NULL;
proto_item *ti;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(application/pkix-cert)");
if (tree) {
ti = proto_tree_add_item(tree, proto_cert, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_cert);
}
dissect_x509af_Certificate(FALSE, tvb, 0, &asn1_ctx, subtree, hf_cert);
return;
}
void
proto_register_cert(void)
{
static hf_register_info hf[] = {
{ &hf_cert,
{ "Certificate", "cert", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}},
};
static gint *ett[] = {
&ett_cert,
};
proto_cert = proto_register_protocol(
"PKIX CERT File Format",
"PKIX Certificate",
"pkix-cert"
);
proto_register_field_array(proto_cert, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("application/pkix-cert", dissect_cert, proto_cert);
}
void
proto_reg_handoff_cert(void)
{
dissector_handle_t cert_handle;
cert_handle = create_dissector_handle(dissect_cert, proto_cert);
dissector_add_string("media_type", "application/pkix-cert", cert_handle);
}
