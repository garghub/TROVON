int
dissect_pkix1implicit_ReasonFlags(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_x509ce_ReasonFlags(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1implicit_GeneralName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_x509ce_GeneralName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1implicit_KeyIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_Dummy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_pkix1implicit_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkix1implicit_AccessDescription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AccessDescription_sequence, hf_index, ett_pkix1implicit_AccessDescription);
return offset;
}
int
dissect_pkix1implicit_AuthorityInfoAccessSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AuthorityInfoAccessSyntax_sequence_of, hf_index, ett_pkix1implicit_AuthorityInfoAccessSyntax);
return offset;
}
static int
dissect_pkix1implicit_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_VisibleString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_BMPString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_BMPString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_DisplayText(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DisplayText_choice, hf_index, ett_pkix1implicit_DisplayText,
NULL);
return offset;
}
static int
dissect_pkix1implicit_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1implicit_T_noticeNumbers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_noticeNumbers_sequence_of, hf_index, ett_pkix1implicit_T_noticeNumbers);
return offset;
}
static int
dissect_pkix1implicit_NoticeReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NoticeReference_sequence, hf_index, ett_pkix1implicit_NoticeReference);
return offset;
}
int
dissect_pkix1implicit_UserNotice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserNotice_sequence, hf_index, ett_pkix1implicit_UserNotice);
return offset;
}
static int dissect_Dummy_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkix1implicit_Dummy(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkix1implicit_Dummy_PDU);
return offset;
}
static int dissect_AuthorityInfoAccessSyntax_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkix1implicit_AuthorityInfoAccessSyntax(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkix1implicit_AuthorityInfoAccessSyntax_PDU);
return offset;
}
static int dissect_UserNotice_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkix1implicit_UserNotice(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkix1implicit_UserNotice_PDU);
return offset;
}
void proto_register_pkix1implicit(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/pkix1implicit/packet-pkix1implicit-hfarr.c"
{ &hf_pkix1implicit_Dummy_PDU,
{ "Dummy", "pkix1implicit.Dummy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_AuthorityInfoAccessSyntax_PDU,
{ "AuthorityInfoAccessSyntax", "pkix1implicit.AuthorityInfoAccessSyntax",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_UserNotice_PDU,
{ "UserNotice", "pkix1implicit.UserNotice_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_AuthorityInfoAccessSyntax_item,
{ "AccessDescription", "pkix1implicit.AccessDescription_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_accessMethod,
{ "accessMethod", "pkix1implicit.accessMethod",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkix1implicit_accessLocation,
{ "accessLocation", "pkix1implicit.accessLocation",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkix1implicit_noticeRef,
{ "noticeRef", "pkix1implicit.noticeRef_element",
FT_NONE, BASE_NONE, NULL, 0,
"NoticeReference", HFILL }},
{ &hf_pkix1implicit_explicitText,
{ "explicitText", "pkix1implicit.explicitText",
FT_UINT32, BASE_DEC, VALS(pkix1implicit_DisplayText_vals), 0,
"DisplayText", HFILL }},
{ &hf_pkix1implicit_organization,
{ "organization", "pkix1implicit.organization",
FT_UINT32, BASE_DEC, VALS(pkix1implicit_DisplayText_vals), 0,
"DisplayText", HFILL }},
{ &hf_pkix1implicit_noticeNumbers,
{ "noticeNumbers", "pkix1implicit.noticeNumbers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_noticeNumbers_item,
{ "noticeNumbers item", "pkix1implicit.noticeNumbers_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1implicit_ia5String,
{ "ia5String", "pkix1implicit.ia5String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_visibleString,
{ "visibleString", "pkix1implicit.visibleString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_bmpString,
{ "bmpString", "pkix1implicit.bmpString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1implicit_utf8String,
{ "utf8String", "pkix1implicit.utf8String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 70 "../../asn1/pkix1implicit/packet-pkix1implicit-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/pkix1implicit/packet-pkix1implicit-ettarr.c"
&ett_pkix1implicit_AuthorityInfoAccessSyntax,
&ett_pkix1implicit_AccessDescription,
&ett_pkix1implicit_UserNotice,
&ett_pkix1implicit_NoticeReference,
&ett_pkix1implicit_T_noticeNumbers,
&ett_pkix1implicit_DisplayText,
#line 75 "../../asn1/pkix1implicit/packet-pkix1implicit-template.c"
};
proto_pkix1implicit = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkix1implicit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkix1implicit(void) {
#line 1 "../../asn1/pkix1implicit/packet-pkix1implicit-dis-tab.c"
new_register_ber_oid_dissector("1.3.6.1.5.5.7.1.1", dissect_AuthorityInfoAccessSyntax_PDU, proto_pkix1implicit, "id-pe-authorityInfoAccessSyntax");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-serverAuth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.2", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-clientAuth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.3", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-codeSigning");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.4", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-emailProtection");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.5", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-ip-kp-ipsecEndSystem");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.6", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-ipsecTunnel");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.7", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-ipsecUser");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.8", dissect_Dummy_PDU, proto_pkix1implicit, "id-kp-timeStamping");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.3.9", dissect_Dummy_PDU, proto_pkix1implicit, "OCSPSigning");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.12.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-any-application-policy");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-ctl-usage-signing");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.2", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-time-stamp-signing");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.4", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-efs");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.4.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-efs-recovery");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.5", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-whql-crypto");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.6", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-nt5-crypto");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.7", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-oem-whql-crypto");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.8", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-embedded-nt-crypto");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.9", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-root-list-signer");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.10", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-qualified-subordination");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.11", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-key-recovery");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.12", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-document-signing");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.3.13", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-lifetime-signing");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.5.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-drm");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.6.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-licenses");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.10.6.2", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-license-server");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.20.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-auto-enroll-ctl-usage");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.20.2.1", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-enrollment-agent");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.20.2.2", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-smartcard-logon");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.5", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-ca-exchange");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.6", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-kp-key-recovery-agent");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.19", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-ds-email-replication");
new_register_ber_oid_dissector("1.3.6.1.5.5.8.2.2", dissect_Dummy_PDU, proto_pkix1implicit, "id-ms-ipsec-kp-ike-intermediate");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.2.2", dissect_UserNotice_PDU, proto_pkix1implicit, "id-qt-unotice");
#line 90 "../../asn1/pkix1implicit/packet-pkix1implicit-template.c"
}
