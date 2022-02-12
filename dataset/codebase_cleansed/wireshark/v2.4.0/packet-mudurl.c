static int
dissect_mudurl_MUDURLSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int dissect_MUDURLSyntax_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_mudurl_MUDURLSyntax(FALSE, tvb, offset, &asn1_ctx, tree, hf_mudurl_MUDURLSyntax_PDU);
return offset;
}
void proto_register_mudurl(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/mudurl/packet-mudurl-hfarr.c"
{ &hf_mudurl_MUDURLSyntax_PDU,
{ "MUDURLSyntax", "mudurl.MUDURLSyntax",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 59 "./asn1/mudurl/packet-mudurl-template.c"
};
proto_mudurl = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_mudurl, hf, array_length(hf));
}
void proto_reg_handoff_mudurl(void) {
#line 1 "./asn1/mudurl/packet-mudurl-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.1.25", dissect_MUDURLSyntax_PDU, proto_mudurl, "id-pe-mud-url");
#line 79 "./asn1/mudurl/packet-mudurl-template.c"
}
