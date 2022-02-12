static int
dissect_pkixac_T_digestedObjectType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixac_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixac_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_pkixac_ObjectDigestInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ObjectDigestInfo_sequence, hf_index, ett_pkixac_ObjectDigestInfo);
return offset;
}
static int
dissect_pkixac_IssuerSerial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IssuerSerial_sequence, hf_index, ett_pkixac_IssuerSerial);
return offset;
}
static int
dissect_pkixac_TargetCert(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TargetCert_sequence, hf_index, ett_pkixac_TargetCert);
return offset;
}
static int
dissect_pkixac_Target(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Target_choice, hf_index, ett_pkixac_Target,
NULL);
return offset;
}
static int
dissect_pkixac_Targets(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Targets_sequence_of, hf_index, ett_pkixac_Targets);
return offset;
}
static int
dissect_pkixac_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixac_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixac_T_values_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_values_item_choice, hf_index, ett_pkixac_T_values_item,
NULL);
return offset;
}
static int
dissect_pkixac_T_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_values_sequence_of, hf_index, ett_pkixac_T_values);
return offset;
}
static int
dissect_pkixac_IetfAttrSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IetfAttrSyntax_sequence, hf_index, ett_pkixac_IetfAttrSyntax);
return offset;
}
static int
dissect_pkixac_SvceAuthInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SvceAuthInfo_sequence, hf_index, ett_pkixac_SvceAuthInfo);
return offset;
}
static int
dissect_pkixac_RoleSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RoleSyntax_sequence, hf_index, ett_pkixac_RoleSyntax);
return offset;
}
static int
dissect_pkixac_ClassList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ClassList_bits, hf_index, ett_pkixac_ClassList,
NULL);
return offset;
}
static int
dissect_pkixac_T_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_pkixac_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 61 "../../asn1/pkixac/pkixac.cnf"
if (object_identifier_id)
offset = call_ber_oid_callback (object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkixac_SecurityCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 54 "../../asn1/pkixac/pkixac.cnf"
object_identifier_id = NULL;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecurityCategory_sequence, hf_index, ett_pkixac_SecurityCategory);
return offset;
}
static int
dissect_pkixac_SET_OF_SecurityCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SecurityCategory_set_of, hf_index, ett_pkixac_SET_OF_SecurityCategory);
return offset;
}
static int
dissect_pkixac_Clearance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Clearance_sequence, hf_index, ett_pkixac_Clearance);
return offset;
}
static int
dissect_pkixac_RFC3281Clearance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RFC3281Clearance_sequence, hf_index, ett_pkixac_RFC3281Clearance);
return offset;
}
static int
dissect_pkixac_INTEGER_0_MAX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixac_AttrSpec(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AttrSpec_sequence_of, hf_index, ett_pkixac_AttrSpec);
return offset;
}
static int
dissect_pkixac_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixac_AAControls(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AAControls_sequence, hf_index, ett_pkixac_AAControls);
return offset;
}
static int
dissect_pkixac_ProxyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ProxyInfo_sequence_of, hf_index, ett_pkixac_ProxyInfo);
return offset;
}
static void dissect_Targets_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_Targets(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_Targets_PDU);
}
static void dissect_IetfAttrSyntax_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_IetfAttrSyntax(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_IetfAttrSyntax_PDU);
}
static void dissect_SvceAuthInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_SvceAuthInfo(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_SvceAuthInfo_PDU);
}
static void dissect_RoleSyntax_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_RoleSyntax(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_RoleSyntax_PDU);
}
static void dissect_Clearance_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_Clearance(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_Clearance_PDU);
}
static void dissect_RFC3281Clearance_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_RFC3281Clearance(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_RFC3281Clearance_PDU);
}
static void dissect_AAControls_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_AAControls(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_AAControls_PDU);
}
static void dissect_ProxyInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkixac_ProxyInfo(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkixac_ProxyInfo_PDU);
}
void proto_register_pkixac(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/pkixac/packet-pkixac-hfarr.c"
{ &hf_pkixac_Targets_PDU,
{ "Targets", "pkixac.Targets",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_IetfAttrSyntax_PDU,
{ "IetfAttrSyntax", "pkixac.IetfAttrSyntax_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_SvceAuthInfo_PDU,
{ "SvceAuthInfo", "pkixac.SvceAuthInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_RoleSyntax_PDU,
{ "RoleSyntax", "pkixac.RoleSyntax_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_Clearance_PDU,
{ "Clearance", "pkixac.Clearance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_RFC3281Clearance_PDU,
{ "RFC3281Clearance", "pkixac.RFC3281Clearance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_AAControls_PDU,
{ "AAControls", "pkixac.AAControls_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_ProxyInfo_PDU,
{ "ProxyInfo", "pkixac.ProxyInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_digestedObjectType,
{ "digestedObjectType", "pkixac.digestedObjectType",
FT_UINT32, BASE_DEC, VALS(pkixac_T_digestedObjectType_vals), 0,
NULL, HFILL }},
{ &hf_pkixac_otherObjectTypeID,
{ "otherObjectTypeID", "pkixac.otherObjectTypeID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixac_digestAlgorithm,
{ "digestAlgorithm", "pkixac.digestAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkixac_objectDigest,
{ "objectDigest", "pkixac.objectDigest",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_pkixac_issuer,
{ "issuer", "pkixac.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_pkixac_serial,
{ "serial", "pkixac.serial",
FT_INT32, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
{ &hf_pkixac_issuerUID,
{ "issuerUID", "pkixac.issuerUID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_pkixac_Targets_item,
{ "Target", "pkixac.Target",
FT_UINT32, BASE_DEC, VALS(pkixac_Target_vals), 0,
NULL, HFILL }},
{ &hf_pkixac_targetName,
{ "targetName", "pkixac.targetName",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixac_targetGroup,
{ "targetGroup", "pkixac.targetGroup",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixac_targetCert,
{ "targetCert", "pkixac.targetCert_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_targetCertificate,
{ "targetCertificate", "pkixac.targetCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
"IssuerSerial", HFILL }},
{ &hf_pkixac_certDigestInfo,
{ "certDigestInfo", "pkixac.certDigestInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ObjectDigestInfo", HFILL }},
{ &hf_pkixac_policyAuthority,
{ "policyAuthority", "pkixac.policyAuthority",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_pkixac_values,
{ "values", "pkixac.values",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_values_item,
{ "values item", "pkixac.values_item",
FT_UINT32, BASE_DEC, VALS(pkixac_T_values_item_vals), 0,
NULL, HFILL }},
{ &hf_pkixac_octets,
{ "octets", "pkixac.octets",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkixac_oid,
{ "oid", "pkixac.oid",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixac_string,
{ "string", "pkixac.string",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String", HFILL }},
{ &hf_pkixac_service,
{ "service", "pkixac.service",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixac_ident,
{ "ident", "pkixac.ident",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixac_authInfo,
{ "authInfo", "pkixac.authInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkixac_roleAuthority,
{ "roleAuthority", "pkixac.roleAuthority",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_pkixac_roleName,
{ "roleName", "pkixac.roleName",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixac_policyId,
{ "policyId", "pkixac.policyId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixac_classList,
{ "classList", "pkixac.classList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_securityCategories,
{ "securityCategories", "pkixac.securityCategories",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SecurityCategory", HFILL }},
{ &hf_pkixac_securityCategories_item,
{ "SecurityCategory", "pkixac.SecurityCategory_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_type,
{ "type", "pkixac.type",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_value,
{ "value", "pkixac.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_pathLenConstraint,
{ "pathLenConstraint", "pkixac.pathLenConstraint",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_pkixac_permittedAttrs,
{ "permittedAttrs", "pkixac.permittedAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"AttrSpec", HFILL }},
{ &hf_pkixac_excludedAttrs,
{ "excludedAttrs", "pkixac.excludedAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"AttrSpec", HFILL }},
{ &hf_pkixac_permitUnSpecified,
{ "permitUnSpecified", "pkixac.permitUnSpecified",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_pkixac_AttrSpec_item,
{ "AttrSpec item", "pkixac.AttrSpec_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixac_ProxyInfo_item,
{ "Targets", "pkixac.Targets",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixac_ClassList_unmarked,
{ "unmarked", "pkixac.unmarked",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pkixac_ClassList_unclassified,
{ "unclassified", "pkixac.unclassified",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pkixac_ClassList_restricted,
{ "restricted", "pkixac.restricted",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_pkixac_ClassList_confidential,
{ "confidential", "pkixac.confidential",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_pkixac_ClassList_secret,
{ "secret", "pkixac.secret",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_pkixac_ClassList_topSecret,
{ "topSecret", "pkixac.topSecret",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
#line 63 "../../asn1/pkixac/packet-pkixac-template.c"
};
static gint *ett[] = {
&ett_pkixac,
#line 1 "../../asn1/pkixac/packet-pkixac-ettarr.c"
&ett_pkixac_ObjectDigestInfo,
&ett_pkixac_IssuerSerial,
&ett_pkixac_Targets,
&ett_pkixac_Target,
&ett_pkixac_TargetCert,
&ett_pkixac_IetfAttrSyntax,
&ett_pkixac_T_values,
&ett_pkixac_T_values_item,
&ett_pkixac_SvceAuthInfo,
&ett_pkixac_RoleSyntax,
&ett_pkixac_Clearance,
&ett_pkixac_SET_OF_SecurityCategory,
&ett_pkixac_RFC3281Clearance,
&ett_pkixac_ClassList,
&ett_pkixac_SecurityCategory,
&ett_pkixac_AAControls,
&ett_pkixac_AttrSpec,
&ett_pkixac_ProxyInfo,
#line 69 "../../asn1/pkixac/packet-pkixac-template.c"
};
proto_pkixac = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixac, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#line 1 "../../asn1/pkixac/packet-pkixac-syn-reg.c"
register_ber_syntax_dissector("Clearance", proto_pkixac, dissect_Clearance_PDU);
register_ber_syntax_dissector("RFC3281Clearance", proto_pkixac, dissect_RFC3281Clearance_PDU);
#line 79 "../../asn1/pkixac/packet-pkixac-template.c"
}
void proto_reg_handoff_pkixac(void) {
#line 1 "../../asn1/pkixac/packet-pkixac-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.1.6", dissect_AAControls_PDU, proto_pkixac, "id-pe-aaControls");
register_ber_oid_dissector("1.3.6.1.5.5.7.1.10", dissect_ProxyInfo_PDU, proto_pkixac, "id-pe-ac-proxying");
register_ber_oid_dissector("1.3.6.1.5.5.7.10.1", dissect_SvceAuthInfo_PDU, proto_pkixac, "id-aca-authenticationInfo");
register_ber_oid_dissector("1.3.6.1.5.5.7.10.2", dissect_SvceAuthInfo_PDU, proto_pkixac, "id-aca-accessIdentity");
register_ber_oid_dissector("1.3.6.1.5.5.7.10.3", dissect_IetfAttrSyntax_PDU, proto_pkixac, "id-aca-chargingIdentity");
register_ber_oid_dissector("1.3.6.1.5.5.7.10.4", dissect_IetfAttrSyntax_PDU, proto_pkixac, "id-aca-group");
register_ber_oid_dissector("2.5.1.5.55", dissect_Clearance_PDU, proto_pkixac, "id-at-clearance");
register_ber_oid_dissector("2.5.4.55", dissect_Clearance_PDU, proto_pkixac, "id-at-clearance");
register_ber_oid_dissector("2.5.4.72", dissect_RoleSyntax_PDU, proto_pkixac, "id-at-role");
register_ber_oid_dissector("2.5.29.55", dissect_Targets_PDU, proto_pkixac, "id-ce-targetInformation");
#line 86 "../../asn1/pkixac/packet-pkixac-template.c"
}
