static int
dissect_pkixqualified_Generalizedtime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_pkixqualified_Directorystring(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509sat_DirectoryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkixqualified_Printablestring(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixqualified_PredefinedBiometricType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixqualified_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixqualified_TypeOfBiometricData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TypeOfBiometricData_choice, hf_index, ett_pkixqualified_TypeOfBiometricData,
NULL);
return offset;
}
static int
dissect_pkixqualified_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixqualified_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixqualified_BiometricData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BiometricData_sequence, hf_index, ett_pkixqualified_BiometricData);
return offset;
}
static int
dissect_pkixqualified_BiometricSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
BiometricSyntax_sequence_of, hf_index, ett_pkixqualified_BiometricSyntax);
return offset;
}
static int
dissect_pkixqualified_T_statementId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_pkixqualified_statementId, &object_identifier_id);
return offset;
}
static int
dissect_pkixqualified_T_statementInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 32 "../../asn1/pkixqualified/pkixqualified.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkixqualified_QCStatement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
QCStatement_sequence, hf_index, ett_pkixqualified_QCStatement);
return offset;
}
static int
dissect_pkixqualified_QCStatements(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
QCStatements_sequence_of, hf_index, ett_pkixqualified_QCStatements);
return offset;
}
static int
dissect_pkixqualified_NameRegistrationAuthorities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NameRegistrationAuthorities_sequence_of, hf_index, ett_pkixqualified_NameRegistrationAuthorities);
return offset;
}
static int
dissect_pkixqualified_SemanticsInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SemanticsInformation_sequence, hf_index, ett_pkixqualified_SemanticsInformation);
return offset;
}
static int
dissect_pkixqualified_XmppAddr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int dissect_Generalizedtime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_Generalizedtime(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_Generalizedtime_PDU);
return offset;
}
static int dissect_Directorystring_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_Directorystring(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_Directorystring_PDU);
return offset;
}
static int dissect_Printablestring_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_Printablestring(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_Printablestring_PDU);
return offset;
}
static int dissect_BiometricSyntax_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_BiometricSyntax(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_BiometricSyntax_PDU);
return offset;
}
static int dissect_QCStatements_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_QCStatements(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_QCStatements_PDU);
return offset;
}
static int dissect_SemanticsInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_SemanticsInformation(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_SemanticsInformation_PDU);
return offset;
}
static int dissect_XmppAddr_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixqualified_XmppAddr(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixqualified_XmppAddr_PDU);
return offset;
}
void proto_register_pkixqualified(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/pkixqualified/packet-pkixqualified-hfarr.c"
{ &hf_pkixqualified_Generalizedtime_PDU,
{ "Generalizedtime", "pkixqualified.Generalizedtime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_Directorystring_PDU,
{ "Directorystring", "pkixqualified.Directorystring",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_pkixqualified_Printablestring_PDU,
{ "Printablestring", "pkixqualified.Printablestring",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_BiometricSyntax_PDU,
{ "BiometricSyntax", "pkixqualified.BiometricSyntax",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_QCStatements_PDU,
{ "QCStatements", "pkixqualified.QCStatements",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_SemanticsInformation_PDU,
{ "SemanticsInformation", "pkixqualified.SemanticsInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_XmppAddr_PDU,
{ "XmppAddr", "pkixqualified.XmppAddr",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_BiometricSyntax_item,
{ "BiometricData", "pkixqualified.BiometricData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_typeOfBiometricData,
{ "typeOfBiometricData", "pkixqualified.typeOfBiometricData",
FT_UINT32, BASE_DEC, VALS(pkixqualified_TypeOfBiometricData_vals), 0,
NULL, HFILL }},
{ &hf_pkixqualified_hashAlgorithm,
{ "hashAlgorithm", "pkixqualified.hashAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkixqualified_biometricDataHash,
{ "biometricDataHash", "pkixqualified.biometricDataHash",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkixqualified_sourceDataUri,
{ "sourceDataUri", "pkixqualified.sourceDataUri",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_pkixqualified_predefinedBiometricType,
{ "predefinedBiometricType", "pkixqualified.predefinedBiometricType",
FT_INT32, BASE_DEC, VALS(pkixqualified_PredefinedBiometricType_vals), 0,
NULL, HFILL }},
{ &hf_pkixqualified_biometricDataOid,
{ "biometricDataOid", "pkixqualified.biometricDataOid",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixqualified_QCStatements_item,
{ "QCStatement", "pkixqualified.QCStatement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_statementId,
{ "statementId", "pkixqualified.statementId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_statementInfo,
{ "statementInfo", "pkixqualified.statementInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_semanticsIdentifier,
{ "semanticsIdentifier", "pkixqualified.semanticsIdentifier",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkixqualified_nameRegistrationAuthorities,
{ "nameRegistrationAuthorities", "pkixqualified.nameRegistrationAuthorities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixqualified_NameRegistrationAuthorities_item,
{ "GeneralName", "pkixqualified.GeneralName",
FT_UINT32, BASE_DEC, VALS(x509ce_GeneralName_vals), 0,
NULL, HFILL }},
#line 61 "../../asn1/pkixqualified/packet-pkixqualified-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/pkixqualified/packet-pkixqualified-ettarr.c"
&ett_pkixqualified_BiometricSyntax,
&ett_pkixqualified_BiometricData,
&ett_pkixqualified_TypeOfBiometricData,
&ett_pkixqualified_QCStatements,
&ett_pkixqualified_QCStatement,
&ett_pkixqualified_SemanticsInformation,
&ett_pkixqualified_NameRegistrationAuthorities,
#line 66 "../../asn1/pkixqualified/packet-pkixqualified-template.c"
};
proto_pkixqualified = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixqualified, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixqualified(void) {
#line 1 "../../asn1/pkixqualified/packet-pkixqualified-dis-tab.c"
new_register_ber_oid_dissector("1.3.6.1.5.5.7.1.2", dissect_BiometricSyntax_PDU, proto_pkixqualified, "id-pe-biometricInfo");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.1.3", dissect_QCStatements_PDU, proto_pkixqualified, "id-pe-qcStatements");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.11.1", dissect_SemanticsInformation_PDU, proto_pkixqualified, "id-qcs-pkixQCSyntax-v1");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.11.2", dissect_SemanticsInformation_PDU, proto_pkixqualified, "id-qcs-pkixQCSyntax-v2");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.8.5", dissect_XmppAddr_PDU, proto_pkixqualified, "id-on-xmppAddr");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.1", dissect_Generalizedtime_PDU, proto_pkixqualified, "id-pda-dateOfBirth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.2", dissect_Directorystring_PDU, proto_pkixqualified, "id-pda-placeOfBirth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.3", dissect_Printablestring_PDU, proto_pkixqualified, "id-pda-gender");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.4", dissect_Printablestring_PDU, proto_pkixqualified, "id-pda-countryOfCitizenship");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.5", dissect_Printablestring_PDU, proto_pkixqualified, "id-pda-countryOfResidence");
#line 81 "../../asn1/pkixqualified/packet-pkixqualified-template.c"
}
