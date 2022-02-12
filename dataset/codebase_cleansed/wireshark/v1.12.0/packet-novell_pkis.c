static int
dissect_novell_pkis_OCTET_STRING_SIZE_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_novell_pkis_T_securityTM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_INTEGER_0_255(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_CompusecQualityPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompusecQualityPair_sequence, hf_index, ett_novell_pkis_CompusecQualityPair);
return offset;
}
static int
dissect_novell_pkis_CompusecQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CompusecQuality_sequence_of, hf_index, ett_novell_pkis_CompusecQuality);
return offset;
}
static int
dissect_novell_pkis_CryptoQualityPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CryptoQualityPair_sequence, hf_index, ett_novell_pkis_CryptoQualityPair);
return offset;
}
static int
dissect_novell_pkis_CryptoQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CryptoQuality_sequence_of, hf_index, ett_novell_pkis_CryptoQuality);
return offset;
}
static int
dissect_novell_pkis_Quality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Quality_sequence, hf_index, ett_novell_pkis_Quality);
return offset;
}
static int
dissect_novell_pkis_KeyQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_novell_pkis_Quality(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_novell_pkis_CryptoProcessQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_novell_pkis_Quality(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_novell_pkis_CertificateClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertificateClass_sequence, hf_index, ett_novell_pkis_CertificateClass);
return offset;
}
static int
dissect_novell_pkis_BIT_STRING_SIZE_96(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_novell_pkis_BIT_STRING_SIZE_64(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_novell_pkis_INTEGER_0_9223372036854775807(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_SingletonRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SingletonRange_sequence, hf_index, ett_novell_pkis_SingletonRange);
return offset;
}
static int
dissect_novell_pkis_SingletonChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SingletonChoice_choice, hf_index, ett_novell_pkis_SingletonChoice,
NULL);
return offset;
}
static int
dissect_novell_pkis_Singletons(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Singletons_sequence_of, hf_index, ett_novell_pkis_Singletons);
return offset;
}
static int
dissect_novell_pkis_SecurityLabelType1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecurityLabelType1_sequence, hf_index, ett_novell_pkis_SecurityLabelType1);
return offset;
}
static int
dissect_novell_pkis_SEQUENCE_SIZE_1_1_OF_SecurityLabelType1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_1_OF_SecurityLabelType1_sequence_of, hf_index, ett_novell_pkis_SEQUENCE_SIZE_1_1_OF_SecurityLabelType1);
return offset;
}
static int
dissect_novell_pkis_EnterpriseId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EnterpriseId_sequence, hf_index, ett_novell_pkis_EnterpriseId);
return offset;
}
static int
dissect_novell_pkis_GLBExtensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GLBExtensions_sequence, hf_index, ett_novell_pkis_GLBExtensions);
return offset;
}
static int
dissect_novell_pkis_SecurityAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecurityAttributes_sequence, hf_index, ett_novell_pkis_SecurityAttributes);
return offset;
}
static int
dissect_novell_pkis_Currency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_novell_pkis_MonetaryValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MonetaryValue_sequence, hf_index, ett_novell_pkis_MonetaryValue);
return offset;
}
static int
dissect_novell_pkis_RelianceLimits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RelianceLimits_sequence, hf_index, ett_novell_pkis_RelianceLimits);
return offset;
}
static void dissect_SecurityAttributes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_novell_pkis_SecurityAttributes(FALSE, tvb, 0, &asn1_ctx, tree, hf_novell_pkis_SecurityAttributes_PDU);
}
static void dissect_RelianceLimits_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_novell_pkis_RelianceLimits(FALSE, tvb, 0, &asn1_ctx, tree, hf_novell_pkis_RelianceLimits_PDU);
}
void proto_reg_handoff_novell_pkis(void)
{
#line 1 "../../asn1/novell_pkis/packet-novell_pkis-dis-tab.c"
register_ber_oid_dissector("2.16.840.1.113719.1.9.4.1", dissect_SecurityAttributes_PDU, proto_novell_pkis, "pa-sa");
register_ber_oid_dissector("2.16.840.1.113719.1.9.4.2", dissect_RelianceLimits_PDU, proto_novell_pkis, "pa-rl");
#line 50 "../../asn1/novell_pkis/packet-novell_pkis-template.c"
}
void proto_register_novell_pkis (void)
{
static hf_register_info hf[] = {
#line 1 "../../asn1/novell_pkis/packet-novell_pkis-hfarr.c"
{ &hf_novell_pkis_SecurityAttributes_PDU,
{ "SecurityAttributes", "novell_pkis.SecurityAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_RelianceLimits_PDU,
{ "RelianceLimits", "novell_pkis.RelianceLimits_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_versionNumber,
{ "versionNumber", "novell_pkis.versionNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_novell_pkis_nSI,
{ "nSI", "novell_pkis.nSI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_novell_pkis_securityTM,
{ "securityTM", "novell_pkis.securityTM",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_uriReference,
{ "uriReference", "novell_pkis.uriReference",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_novell_pkis_gLBExtensions,
{ "gLBExtensions", "novell_pkis.gLBExtensions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_keyQuality,
{ "keyQuality", "novell_pkis.keyQuality_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_cryptoProcessQuality,
{ "cryptoProcessQuality", "novell_pkis.cryptoProcessQuality_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_certificateClass,
{ "certificateClass", "novell_pkis.certificateClass_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_enterpriseId,
{ "enterpriseId", "novell_pkis.enterpriseId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_enforceQuality,
{ "enforceQuality", "novell_pkis.enforceQuality",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_novell_pkis_compusecQuality,
{ "compusecQuality", "novell_pkis.compusecQuality",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_cryptoQuality,
{ "cryptoQuality", "novell_pkis.cryptoQuality",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_keyStorageQuality,
{ "keyStorageQuality", "novell_pkis.keyStorageQuality",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_CompusecQuality_item,
{ "CompusecQualityPair", "novell_pkis.CompusecQualityPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_compusecCriteria,
{ "compusecCriteria", "novell_pkis.compusecCriteria",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_compusecRating,
{ "compusecRating", "novell_pkis.compusecRating",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_CryptoQuality_item,
{ "CryptoQualityPair", "novell_pkis.CryptoQualityPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_cryptoModuleCriteria,
{ "cryptoModuleCriteria", "novell_pkis.cryptoModuleCriteria",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_cryptoModuleRating,
{ "cryptoModuleRating", "novell_pkis.cryptoModuleRating",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_classValue,
{ "classValue", "novell_pkis.classValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_certificateValid,
{ "certificateValid", "novell_pkis.certificateValid",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_novell_pkis_rootLabel,
{ "rootLabel", "novell_pkis.rootLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabelType1", HFILL }},
{ &hf_novell_pkis_registryLabel,
{ "registryLabel", "novell_pkis.registryLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabelType1", HFILL }},
{ &hf_novell_pkis_enterpriseLabel,
{ "enterpriseLabel", "novell_pkis.enterpriseLabel",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_1_OF_SecurityLabelType1", HFILL }},
{ &hf_novell_pkis_enterpriseLabel_item,
{ "SecurityLabelType1", "novell_pkis.SecurityLabelType1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_labelType1,
{ "labelType1", "novell_pkis.labelType1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_secrecyLevel1,
{ "secrecyLevel1", "novell_pkis.secrecyLevel1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_integrityLevel1,
{ "integrityLevel1", "novell_pkis.integrityLevel1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_novell_pkis_secrecyCategories1,
{ "secrecyCategories1", "novell_pkis.secrecyCategories1",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_96", HFILL }},
{ &hf_novell_pkis_integrityCategories1,
{ "integrityCategories1", "novell_pkis.integrityCategories1",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_64", HFILL }},
{ &hf_novell_pkis_secrecySingletons1,
{ "secrecySingletons1", "novell_pkis.secrecySingletons1",
FT_UINT32, BASE_DEC, NULL, 0,
"Singletons", HFILL }},
{ &hf_novell_pkis_integritySingletons1,
{ "integritySingletons1", "novell_pkis.integritySingletons1",
FT_UINT32, BASE_DEC, NULL, 0,
"Singletons", HFILL }},
{ &hf_novell_pkis_Singletons_item,
{ "SingletonChoice", "novell_pkis.SingletonChoice",
FT_UINT32, BASE_DEC, VALS(novell_pkis_SingletonChoice_vals), 0,
NULL, HFILL }},
{ &hf_novell_pkis_uniqueSingleton,
{ "uniqueSingleton", "novell_pkis.uniqueSingleton",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9223372036854775807", HFILL }},
{ &hf_novell_pkis_singletonRange,
{ "singletonRange", "novell_pkis.singletonRange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_singletonLowerBound,
{ "singletonLowerBound", "novell_pkis.singletonLowerBound",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9223372036854775807", HFILL }},
{ &hf_novell_pkis_singletonUpperBound,
{ "singletonUpperBound", "novell_pkis.singletonUpperBound",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9223372036854775807", HFILL }},
{ &hf_novell_pkis_singletonValue,
{ "singletonValue", "novell_pkis.singletonValue",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_novell_pkis_perTransactionLimit,
{ "perTransactionLimit", "novell_pkis.perTransactionLimit_element",
FT_NONE, BASE_NONE, NULL, 0,
"MonetaryValue", HFILL }},
{ &hf_novell_pkis_perCertificateLimit,
{ "perCertificateLimit", "novell_pkis.perCertificateLimit_element",
FT_NONE, BASE_NONE, NULL, 0,
"MonetaryValue", HFILL }},
{ &hf_novell_pkis_currency,
{ "currency", "novell_pkis.currency",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_novell_pkis_amount,
{ "amount", "novell_pkis.amount",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_novell_pkis_amtExp10,
{ "amtExp10", "novell_pkis.amtExp10",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
#line 56 "../../asn1/novell_pkis/packet-novell_pkis-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/novell_pkis/packet-novell_pkis-ettarr.c"
&ett_novell_pkis_SecurityAttributes,
&ett_novell_pkis_GLBExtensions,
&ett_novell_pkis_Quality,
&ett_novell_pkis_CompusecQuality,
&ett_novell_pkis_CompusecQualityPair,
&ett_novell_pkis_CryptoQuality,
&ett_novell_pkis_CryptoQualityPair,
&ett_novell_pkis_CertificateClass,
&ett_novell_pkis_EnterpriseId,
&ett_novell_pkis_SEQUENCE_SIZE_1_1_OF_SecurityLabelType1,
&ett_novell_pkis_SecurityLabelType1,
&ett_novell_pkis_Singletons,
&ett_novell_pkis_SingletonChoice,
&ett_novell_pkis_SingletonRange,
&ett_novell_pkis_RelianceLimits,
&ett_novell_pkis_MonetaryValue,
#line 59 "../../asn1/novell_pkis/packet-novell_pkis-template.c"
};
if (proto_novell_pkis != -1) return;
proto_novell_pkis = proto_register_protocol("Novell PKIS ASN.1 type", "novell_pkis", "novell_pkis");
proto_register_field_array (proto_novell_pkis, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
