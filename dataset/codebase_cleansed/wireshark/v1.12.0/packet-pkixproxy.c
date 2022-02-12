static int
dissect_pkixproxy_ProxyCertPathLengthConstraint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixproxy_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixproxy_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixproxy_ProxyPolicy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProxyPolicy_sequence, hf_index, ett_pkixproxy_ProxyPolicy);
return offset;
}
static int
dissect_pkixproxy_ProxyCertInfoExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProxyCertInfoExtension_sequence, hf_index, ett_pkixproxy_ProxyCertInfoExtension);
return offset;
}
static void dissect_ProxyCertInfoExtension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixproxy_ProxyCertInfoExtension(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixproxy_ProxyCertInfoExtension_PDU);
}
void proto_register_pkixproxy(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/pkixproxy/packet-pkixproxy-hfarr.c"
{ &hf_pkixproxy_ProxyCertInfoExtension_PDU,
{ "ProxyCertInfoExtension", "pkixproxy.ProxyCertInfoExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixproxy_pCPathLenConstraint,
{ "pCPathLenConstraint", "pkixproxy.pCPathLenConstraint",
FT_INT32, BASE_DEC, NULL, 0,
"ProxyCertPathLengthConstraint", HFILL }},
{ &hf_pkixproxy_proxyPolicy,
{ "proxyPolicy", "pkixproxy.proxyPolicy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixproxy_policyLanguage,
{ "policyLanguage", "pkixproxy.policyLanguage",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixproxy_policy,
{ "policy", "pkixproxy.policy",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
#line 57 "../../asn1/pkixproxy/packet-pkixproxy-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/pkixproxy/packet-pkixproxy-ettarr.c"
&ett_pkixproxy_ProxyCertInfoExtension,
&ett_pkixproxy_ProxyPolicy,
#line 62 "../../asn1/pkixproxy/packet-pkixproxy-template.c"
};
proto_pkixproxy = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixproxy, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixproxy(void) {
#line 1 "../../asn1/pkixproxy/packet-pkixproxy-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.1.14", dissect_ProxyCertInfoExtension_PDU, proto_pkixproxy, "id-pe-proxyCertInfo");
#line 77 "../../asn1/pkixproxy/packet-pkixproxy-template.c"
oid_add_from_string("id-ppl-anyLanguage","1.3.6.1.5.5.7.21.0");
oid_add_from_string("id-ppl-inheritAll","1.3.6.1.5.5.7.21.1");
oid_add_from_string("id-ppl-independent","1.3.6.1.5.5.7.21.2");
}
