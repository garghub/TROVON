static int
dissect_ns_cert_exts_BaseUrl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_RevocationUrl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_CaRevocationUrl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_CaPolicyUrl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_Comment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_SslServerName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_CertRenewalUrl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ns_cert_exts_CertType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
CertType_bits, hf_index, ett_ns_cert_exts_CertType,
NULL);
return offset;
}
static void dissect_BaseUrl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_BaseUrl(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_BaseUrl_PDU);
}
static void dissect_RevocationUrl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_RevocationUrl(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_RevocationUrl_PDU);
}
static void dissect_CaRevocationUrl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_CaRevocationUrl(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_CaRevocationUrl_PDU);
}
static void dissect_CaPolicyUrl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_CaPolicyUrl(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_CaPolicyUrl_PDU);
}
static void dissect_Comment_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_Comment(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_Comment_PDU);
}
static void dissect_SslServerName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_SslServerName(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_SslServerName_PDU);
}
static void dissect_CertRenewalUrl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_CertRenewalUrl(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_CertRenewalUrl_PDU);
}
static void dissect_CertType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ns_cert_exts_CertType(FALSE, tvb, 0, &asn1_ctx, tree, hf_ns_cert_exts_CertType_PDU);
}
void proto_register_ns_cert_exts(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/ns_cert_exts/packet-ns_cert_exts-hfarr.c"
{ &hf_ns_cert_exts_BaseUrl_PDU,
{ "BaseUrl", "ns_cert_exts.BaseUrl",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_RevocationUrl_PDU,
{ "RevocationUrl", "ns_cert_exts.RevocationUrl",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_CaRevocationUrl_PDU,
{ "CaRevocationUrl", "ns_cert_exts.CaRevocationUrl",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_CaPolicyUrl_PDU,
{ "CaPolicyUrl", "ns_cert_exts.CaPolicyUrl",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_Comment_PDU,
{ "Comment", "ns_cert_exts.Comment",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_SslServerName_PDU,
{ "SslServerName", "ns_cert_exts.SslServerName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertRenewalUrl_PDU,
{ "CertRenewalUrl", "ns_cert_exts.CertRenewalUrl",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_PDU,
{ "CertType", "ns_cert_exts.CertType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_ssl_client,
{ "ssl-client", "ns_cert_exts.ssl-client",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_ssl_server,
{ "ssl-server", "ns_cert_exts.ssl-server",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_smime,
{ "smime", "ns_cert_exts.smime",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_object_signing,
{ "object-signing", "ns_cert_exts.object-signing",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_reserved_for_future_use,
{ "reserved-for-future-use", "ns_cert_exts.reserved-for-future-use",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_ssl_ca,
{ "ssl-ca", "ns_cert_exts.ssl-ca",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_smime_ca,
{ "smime-ca", "ns_cert_exts.smime-ca",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ns_cert_exts_CertType_object_signing_ca,
{ "object-signing-ca", "ns_cert_exts.object-signing-ca",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
#line 53 "../../asn1/ns_cert_exts/packet-ns_cert_exts-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/ns_cert_exts/packet-ns_cert_exts-ettarr.c"
&ett_ns_cert_exts_CertType,
#line 58 "../../asn1/ns_cert_exts/packet-ns_cert_exts-template.c"
};
proto_ns_cert_exts = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ns_cert_exts, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ns_cert_exts(void) {
#line 1 "../../asn1/ns_cert_exts/packet-ns_cert_exts-dis-tab.c"
register_ber_oid_dissector("2.16.840.1.113730.1.1", dissect_CertType_PDU, proto_ns_cert_exts, "ns_cert_exts.cert_type");
register_ber_oid_dissector("2.16.840.1.113730.1.2", dissect_BaseUrl_PDU, proto_ns_cert_exts, "ns_cert_exts.base_url");
register_ber_oid_dissector("2.16.840.1.113730.1.3", dissect_RevocationUrl_PDU, proto_ns_cert_exts, "ns_cert_exts.revocation-url");
register_ber_oid_dissector("2.16.840.1.113730.1.4", dissect_CaRevocationUrl_PDU, proto_ns_cert_exts, "ns_cert_exts.ca-revocation-url");
register_ber_oid_dissector("2.16.840.1.113730.1.7", dissect_CertRenewalUrl_PDU, proto_ns_cert_exts, "ns_cert_exts.cert-renewal-url");
register_ber_oid_dissector("2.16.840.1.113730.1.8", dissect_CaPolicyUrl_PDU, proto_ns_cert_exts, "ns_cert_exts.ca-policy-url");
register_ber_oid_dissector("2.16.840.1.113730.1.12", dissect_SslServerName_PDU, proto_ns_cert_exts, "ns_cert_exts.ssl-server-name");
register_ber_oid_dissector("2.16.840.1.113730.1.13", dissect_Comment_PDU, proto_ns_cert_exts, "ns_cert_exts.comment");
#line 73 "../../asn1/ns_cert_exts/packet-ns_cert_exts-template.c"
}
