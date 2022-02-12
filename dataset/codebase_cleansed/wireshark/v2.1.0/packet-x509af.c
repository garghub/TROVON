int
dissect_x509af_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509af_CertificateSerialNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer64(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509af_T_algorithmId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "./asn1/x509af/x509af.cnf"
const char *name;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509af_algorithm_id, &actx->external.direct_reference);
if (algorithm_id) {
wmem_free(wmem_file_scope(), (void*)algorithm_id);
}
if(actx->external.direct_reference) {
algorithm_id = (const char *)wmem_strdup(wmem_file_scope(), actx->external.direct_reference);
name = oid_resolved_from_string(wmem_packet_scope(), actx->external.direct_reference);
proto_item_append_text(tree, " (%s)", name ? name : actx->external.direct_reference);
} else {
algorithm_id = NULL;
}
return offset;
}
static int
dissect_x509af_T_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 88 "./asn1/x509af/x509af.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_x509af_AlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlgorithmIdentifier_sequence, hf_index, ett_x509af_AlgorithmIdentifier);
return offset;
}
static int
dissect_x509af_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509af_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_x509af_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_x509af_Time,
NULL);
return offset;
}
int
dissect_x509af_Validity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Validity_sequence, hf_index, ett_x509af_Validity);
return offset;
}
static int
dissect_x509af_SubjectName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 147 "./asn1/x509af/x509af.cnf"
const char* str;
offset = dissect_ber_choice(actx, tree, tvb, offset,
SubjectName_choice, hf_index, ett_x509af_SubjectName,
NULL);
str = x509if_get_last_dn();
proto_item_append_text(proto_item_get_parent(tree), " (%s)", str?str:"");
return offset;
}
static int
dissect_x509af_T_subjectPublicKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 97 "./asn1/x509af/x509af.cnf"
tvbuff_t *bs_tvb = NULL;
dissect_ber_bitstring(FALSE, actx, NULL, tvb, offset,
NULL, -1, -1, &bs_tvb);
if (bs_tvb && !g_strcmp0(algorithm_id, "1.2.840.113549.1.1.1")) {
offset += dissect_pkcs1_RSAPublicKey(FALSE, bs_tvb, 0, actx, tree, hf_index);
} else {
offset = dissect_ber_bitstring(FALSE, actx, tree, tvb, offset,
NULL, hf_index, -1, NULL);
}
return offset;
}
int
dissect_x509af_SubjectPublicKeyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 91 "./asn1/x509af/x509af.cnf"
int orig_offset = offset;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubjectPublicKeyInfo_sequence, hf_index, ett_x509af_SubjectPublicKeyInfo);
#line 93 "./asn1/x509af/x509af.cnf"
x509af_export_publickey(tvb, actx, orig_offset, offset - orig_offset);
return offset;
}
static int
dissect_x509af_T_extnId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 126 "./asn1/x509af/x509af.cnf"
const char *name;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509af_extension_id, &actx->external.direct_reference);
if(actx->external.direct_reference) {
name = oid_resolved_from_string(wmem_packet_scope(), actx->external.direct_reference);
proto_item_append_text(tree, " (%s)", name ? name : actx->external.direct_reference);
}
return offset;
}
static int
dissect_x509af_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_x509af_T_extnValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 137 "./asn1/x509af/x509af.cnf"
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_x509af_Extension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Extension_sequence, hf_index, ett_x509af_Extension);
return offset;
}
int
dissect_x509af_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Extensions_sequence_of, hf_index, ett_x509af_Extensions);
return offset;
}
static int
dissect_x509af_T_signedCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedCertificate_sequence, hf_index, ett_x509af_T_signedCertificate);
return offset;
}
static int
dissect_x509af_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_x509af_Certificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Certificate_sequence, hf_index, ett_x509af_Certificate);
return offset;
}
int
dissect_x509af_CrossCertificates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
CrossCertificates_set_of, hf_index, ett_x509af_CrossCertificates);
return offset;
}
int
dissect_x509af_ForwardCertificationPath(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ForwardCertificationPath_sequence_of, hf_index, ett_x509af_ForwardCertificationPath);
return offset;
}
int
dissect_x509af_Certificates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Certificates_sequence, hf_index, ett_x509af_Certificates);
return offset;
}
int
dissect_x509af_CertificatePair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertificatePair_sequence, hf_index, ett_x509af_CertificatePair);
return offset;
}
static int
dissect_x509af_SEQUENCE_OF_CertificatePair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CertificatePair_sequence_of, hf_index, ett_x509af_SEQUENCE_OF_CertificatePair);
return offset;
}
int
dissect_x509af_CertificationPath(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertificationPath_sequence, hf_index, ett_x509af_CertificationPath);
return offset;
}
static int
dissect_x509af_T_revokedCertificates_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_revokedCertificates_item_sequence, hf_index, ett_x509af_T_revokedCertificates_item);
return offset;
}
static int
dissect_x509af_T_revokedCertificates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_revokedCertificates_sequence_of, hf_index, ett_x509af_T_revokedCertificates);
return offset;
}
static int
dissect_x509af_T_signedCertificateList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedCertificateList_sequence, hf_index, ett_x509af_T_signedCertificateList);
return offset;
}
int
dissect_x509af_CertificateList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertificateList_sequence, hf_index, ett_x509af_CertificateList);
return offset;
}
int
dissect_x509af_IssuerSerial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IssuerSerial_sequence, hf_index, ett_x509af_IssuerSerial);
return offset;
}
static int
dissect_x509af_InfoSubject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InfoSubject_choice, hf_index, ett_x509af_InfoSubject,
NULL);
return offset;
}
int
dissect_x509af_AttCertValidityPeriod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttCertValidityPeriod_sequence, hf_index, ett_x509af_AttCertValidityPeriod);
return offset;
}
static int
dissect_x509af_SEQUENCE_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Attribute_sequence_of, hf_index, ett_x509af_SEQUENCE_OF_Attribute);
return offset;
}
int
dissect_x509af_AttributeCertificateInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificateInfo_sequence, hf_index, ett_x509af_AttributeCertificateInfo);
return offset;
}
int
dissect_x509af_AttributeCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificate_sequence, hf_index, ett_x509af_AttributeCertificate);
return offset;
}
int
dissect_x509af_ACPathData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ACPathData_sequence, hf_index, ett_x509af_ACPathData);
return offset;
}
static int
dissect_x509af_SEQUENCE_OF_ACPathData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ACPathData_sequence_of, hf_index, ett_x509af_SEQUENCE_OF_ACPathData);
return offset;
}
int
dissect_x509af_AttributeCertificationPath(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificationPath_sequence, hf_index, ett_x509af_AttributeCertificationPath);
return offset;
}
static int
dissect_x509af_AssertionSubject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AssertionSubject_choice, hf_index, ett_x509af_AssertionSubject,
NULL);
return offset;
}
static int
dissect_x509af_SET_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeType_set_of, hf_index, ett_x509af_SET_OF_AttributeType);
return offset;
}
int
dissect_x509af_AttributeCertificateAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificateAssertion_sequence, hf_index, ett_x509af_AttributeCertificateAssertion);
return offset;
}
static int
dissect_x509af_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509af_DSS_Params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DSS_Params_sequence, hf_index, ett_x509af_DSS_Params);
return offset;
}
int dissect_x509af_Certificate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509af_x509af_Certificate_PDU);
return offset;
}
static int dissect_CertificatePair_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_CertificatePair(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509af_CertificatePair_PDU);
return offset;
}
static int dissect_CertificateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_CertificateList(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509af_CertificateList_PDU);
return offset;
}
static int dissect_AttributeCertificate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_AttributeCertificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509af_AttributeCertificate_PDU);
return offset;
}
static int dissect_DSS_Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_DSS_Params(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509af_DSS_Params_PDU);
return offset;
}
static void
x509af_export_publickey(tvbuff_t *tvb _U_, asn1_ctx_t *actx _U_, int offset _U_, int len _U_)
{
#if defined(HAVE_LIBGNUTLS)
gnutls_datum_t *subjectPublicKeyInfo = (gnutls_datum_t *)actx->private_data;
if (subjectPublicKeyInfo) {
subjectPublicKeyInfo->data = (guchar *) tvb_get_ptr(tvb, offset, len);
subjectPublicKeyInfo->size = len;
actx->private_data = NULL;
}
#endif
}
const char *x509af_get_last_algorithm_id(void) {
return algorithm_id;
}
static int
dissect_pkix_crl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKIX-CRL");
col_set_str(pinfo->cinfo, COL_INFO, "Certificate Revocation List");
tree=proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_pkix_crl, NULL, "Certificate Revocation List");
return dissect_x509af_CertificateList(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void
x509af_cleanup_protocol(void)
{
algorithm_id = NULL;
}
void proto_register_x509af(void) {
static hf_register_info hf[] = {
{ &hf_x509af_algorithm_id,
{ "Algorithm Id", "x509af.algorithm.id",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_extension_id,
{ "Extension Id", "x509af.extension.id",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "./asn1/x509af/packet-x509af-hfarr.c"
{ &hf_x509af_x509af_Certificate_PDU,
{ "Certificate", "x509af.Certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_CertificatePair_PDU,
{ "CertificatePair", "x509af.CertificatePair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_CertificateList_PDU,
{ "CertificateList", "x509af.CertificateList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_AttributeCertificate_PDU,
{ "AttributeCertificate", "x509af.AttributeCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_DSS_Params_PDU,
{ "DSS-Params", "x509af.DSS_Params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_signedCertificate,
{ "signedCertificate", "x509af.signedCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_version,
{ "version", "x509af.version",
FT_INT32, BASE_DEC, VALS(x509af_Version_vals), 0,
NULL, HFILL }},
{ &hf_x509af_serialNumber,
{ "serialNumber", "x509af.serialNumber",
FT_INT64, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
{ &hf_x509af_signature,
{ "signature", "x509af.signature_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_x509af_issuer,
{ "issuer", "x509af.issuer",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_x509af_validity,
{ "validity", "x509af.validity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_subject,
{ "subject", "x509af.subject",
FT_UINT32, BASE_DEC, VALS(x509af_SubjectName_vals), 0,
"SubjectName", HFILL }},
{ &hf_x509af_subjectPublicKeyInfo,
{ "subjectPublicKeyInfo", "x509af.subjectPublicKeyInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_issuerUniqueIdentifier,
{ "issuerUniqueIdentifier", "x509af.issuerUniqueIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_x509af_subjectUniqueIdentifier,
{ "subjectUniqueIdentifier", "x509af.subjectUniqueIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_x509af_extensions,
{ "extensions", "x509af.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_algorithmIdentifier,
{ "algorithmIdentifier", "x509af.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_encrypted,
{ "encrypted", "x509af.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_x509af_rdnSequence,
{ "rdnSequence", "x509af.rdnSequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_algorithmId,
{ "algorithmId", "x509af.algorithmId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_parameters,
{ "parameters", "x509af.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_notBefore,
{ "notBefore", "x509af.notBefore",
FT_UINT32, BASE_DEC, VALS(x509af_Time_vals), 0,
"Time", HFILL }},
{ &hf_x509af_notAfter,
{ "notAfter", "x509af.notAfter",
FT_UINT32, BASE_DEC, VALS(x509af_Time_vals), 0,
"Time", HFILL }},
{ &hf_x509af_algorithm,
{ "algorithm", "x509af.algorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_x509af_subjectPublicKey,
{ "subjectPublicKey", "x509af.subjectPublicKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_utcTime,
{ "utcTime", "x509af.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_generalizedTime,
{ "generalizedTime", "x509af.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_Extensions_item,
{ "Extension", "x509af.Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_extnId,
{ "extnId", "x509af.extnId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_critical,
{ "critical", "x509af.critical",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509af_extnValue,
{ "extnValue", "x509af.extnValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_userCertificate,
{ "userCertificate", "x509af.userCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
"Certificate", HFILL }},
{ &hf_x509af_certificationPath,
{ "certificationPath", "x509af.certificationPath",
FT_UINT32, BASE_DEC, NULL, 0,
"ForwardCertificationPath", HFILL }},
{ &hf_x509af_ForwardCertificationPath_item,
{ "CrossCertificates", "x509af.CrossCertificates",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_CrossCertificates_item,
{ "Certificate", "x509af.Certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_theCACertificates,
{ "theCACertificates", "x509af.theCACertificates",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CertificatePair", HFILL }},
{ &hf_x509af_theCACertificates_item,
{ "CertificatePair", "x509af.CertificatePair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_issuedByThisCA,
{ "issuedByThisCA", "x509af.issuedByThisCA_element",
FT_NONE, BASE_NONE, NULL, 0,
"Certificate", HFILL }},
{ &hf_x509af_issuedToThisCA,
{ "issuedToThisCA", "x509af.issuedToThisCA_element",
FT_NONE, BASE_NONE, NULL, 0,
"Certificate", HFILL }},
{ &hf_x509af_signedCertificateList,
{ "signedCertificateList", "x509af.signedCertificateList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_thisUpdate,
{ "thisUpdate", "x509af.thisUpdate",
FT_UINT32, BASE_DEC, VALS(x509af_Time_vals), 0,
"Time", HFILL }},
{ &hf_x509af_nextUpdate,
{ "nextUpdate", "x509af.nextUpdate",
FT_UINT32, BASE_DEC, VALS(x509af_Time_vals), 0,
"Time", HFILL }},
{ &hf_x509af_revokedCertificates,
{ "revokedCertificates", "x509af.revokedCertificates",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_revokedCertificates_item,
{ "revokedCertificates item", "x509af.revokedCertificates_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_revokedUserCertificate,
{ "userCertificate", "x509af.userCertificate",
FT_INT64, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
{ &hf_x509af_revocationDate,
{ "revocationDate", "x509af.revocationDate",
FT_UINT32, BASE_DEC, VALS(x509af_Time_vals), 0,
"Time", HFILL }},
{ &hf_x509af_crlEntryExtensions,
{ "crlEntryExtensions", "x509af.crlEntryExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"Extensions", HFILL }},
{ &hf_x509af_crlExtensions,
{ "crlExtensions", "x509af.crlExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"Extensions", HFILL }},
{ &hf_x509af_attributeCertificate,
{ "attributeCertificate", "x509af.attributeCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_acPath,
{ "acPath", "x509af.acPath",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ACPathData", HFILL }},
{ &hf_x509af_acPath_item,
{ "ACPathData", "x509af.ACPathData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_certificate,
{ "certificate", "x509af.certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_signedAttributeCertificateInfo,
{ "signedAttributeCertificateInfo", "x509af.signedAttributeCertificateInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeCertificateInfo", HFILL }},
{ &hf_x509af_info_subject,
{ "subject", "x509af.subject",
FT_UINT32, BASE_DEC, VALS(x509af_InfoSubject_vals), 0,
"InfoSubject", HFILL }},
{ &hf_x509af_baseCertificateID,
{ "baseCertificateID", "x509af.baseCertificateID_element",
FT_NONE, BASE_NONE, NULL, 0,
"IssuerSerial", HFILL }},
{ &hf_x509af_infoSubjectName,
{ "subjectName", "x509af.subjectName",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_x509af_issuerName,
{ "issuer", "x509af.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_x509af_attCertValidityPeriod,
{ "attCertValidityPeriod", "x509af.attCertValidityPeriod_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_attributes,
{ "attributes", "x509af.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Attribute", HFILL }},
{ &hf_x509af_attributes_item,
{ "Attribute", "x509af.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_issuerUniqueID,
{ "issuerUniqueID", "x509af.issuerUniqueID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_x509af_serial,
{ "serial", "x509af.serial",
FT_INT64, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
{ &hf_x509af_issuerUID,
{ "issuerUID", "x509af.issuerUID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_x509af_notBeforeTime,
{ "notBeforeTime", "x509af.notBeforeTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509af_notAfterTime,
{ "notAfterTime", "x509af.notAfterTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509af_assertion_subject,
{ "subject", "x509af.subject",
FT_UINT32, BASE_DEC, VALS(x509af_AssertionSubject_vals), 0,
"AssertionSubject", HFILL }},
{ &hf_x509af_assertionSubjectName,
{ "subjectName", "x509af.subjectName",
FT_UINT32, BASE_DEC, VALS(x509af_SubjectName_vals), 0,
NULL, HFILL }},
{ &hf_x509af_assertionIssuer,
{ "issuer", "x509af.issuer",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_x509af_attCertValidity,
{ "attCertValidity", "x509af.attCertValidity",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509af_attType,
{ "attType", "x509af.attType",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_x509af_attType_item,
{ "AttributeType", "x509af.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509af_p,
{ "p", "x509af.p",
FT_BYTES, BASE_NONE, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509af_q,
{ "q", "x509af.q",
FT_BYTES, BASE_NONE, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509af_g,
{ "g", "x509af.g",
FT_BYTES, BASE_NONE, NULL, 0,
"INTEGER", HFILL }},
#line 120 "./asn1/x509af/packet-x509af-template.c"
};
static gint *ett[] = {
&ett_pkix_crl,
#line 1 "./asn1/x509af/packet-x509af-ettarr.c"
&ett_x509af_Certificate,
&ett_x509af_T_signedCertificate,
&ett_x509af_SubjectName,
&ett_x509af_AlgorithmIdentifier,
&ett_x509af_Validity,
&ett_x509af_SubjectPublicKeyInfo,
&ett_x509af_Time,
&ett_x509af_Extensions,
&ett_x509af_Extension,
&ett_x509af_Certificates,
&ett_x509af_ForwardCertificationPath,
&ett_x509af_CrossCertificates,
&ett_x509af_CertificationPath,
&ett_x509af_SEQUENCE_OF_CertificatePair,
&ett_x509af_CertificatePair,
&ett_x509af_CertificateList,
&ett_x509af_T_signedCertificateList,
&ett_x509af_T_revokedCertificates,
&ett_x509af_T_revokedCertificates_item,
&ett_x509af_AttributeCertificationPath,
&ett_x509af_SEQUENCE_OF_ACPathData,
&ett_x509af_ACPathData,
&ett_x509af_AttributeCertificate,
&ett_x509af_AttributeCertificateInfo,
&ett_x509af_InfoSubject,
&ett_x509af_SEQUENCE_OF_Attribute,
&ett_x509af_IssuerSerial,
&ett_x509af_AttCertValidityPeriod,
&ett_x509af_AttributeCertificateAssertion,
&ett_x509af_AssertionSubject,
&ett_x509af_SET_OF_AttributeType,
&ett_x509af_DSS_Params,
#line 126 "./asn1/x509af/packet-x509af-template.c"
};
proto_x509af = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509af, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_cleanup_routine(&x509af_cleanup_protocol);
register_ber_syntax_dissector("Certificate", proto_x509af, dissect_x509af_Certificate_PDU);
register_ber_syntax_dissector("CertificateList", proto_x509af, dissect_CertificateList_PDU);
register_ber_syntax_dissector("CrossCertificatePair", proto_x509af, dissect_CertificatePair_PDU);
register_ber_oid_syntax(".cer", NULL, "Certificate");
register_ber_oid_syntax(".crt", NULL, "Certificate");
register_ber_oid_syntax(".crl", NULL, "CertificateList");
}
void proto_reg_handoff_x509af(void) {
dissector_handle_t pkix_crl_handle;
pkix_crl_handle = create_dissector_handle(dissect_pkix_crl, proto_x509af);
dissector_add_string("media_type", "application/pkix-crl", pkix_crl_handle);
#line 1 "./asn1/x509af/packet-x509af-dis-tab.c"
register_ber_oid_dissector("2.5.4.36", dissect_x509af_Certificate_PDU, proto_x509af, "id-at-userCertificate");
register_ber_oid_dissector("2.5.4.37", dissect_x509af_Certificate_PDU, proto_x509af, "id-at-cAcertificate");
register_ber_oid_dissector("2.5.4.38", dissect_CertificateList_PDU, proto_x509af, "id-at-authorityRevocationList");
register_ber_oid_dissector("2.5.4.39", dissect_CertificateList_PDU, proto_x509af, "id-at-certificateRevocationList");
register_ber_oid_dissector("2.5.4.40", dissect_CertificatePair_PDU, proto_x509af, "id-at-crossCertificatePair");
register_ber_oid_dissector("2.5.4.53", dissect_CertificateList_PDU, proto_x509af, "id-at-deltaRevocationList");
register_ber_oid_dissector("2.5.4.58", dissect_AttributeCertificate_PDU, proto_x509af, "id-at-attributeCertificate");
register_ber_oid_dissector("2.5.4.59", dissect_CertificateList_PDU, proto_x509af, "id-at-attributeCertificateRevocationList");
register_ber_oid_dissector("1.2.840.10040.4.1", dissect_DSS_Params_PDU, proto_x509af, "id-dsa");
#line 155 "./asn1/x509af/packet-x509af-template.c"
register_ber_oid_dissector("1.3.14.3.2.2", dissect_ber_oid_NULL_callback, proto_x509af, "md4WithRSA");
register_ber_oid_dissector("1.3.14.3.2.3", dissect_ber_oid_NULL_callback, proto_x509af, "md5WithRSA");
register_ber_oid_dissector("1.3.14.3.2.4", dissect_ber_oid_NULL_callback, proto_x509af, "md4WithRSAEncryption");
register_ber_oid_dissector("1.3.14.3.2.6", dissect_ber_oid_NULL_callback, proto_x509af, "desECB");
register_ber_oid_dissector("1.3.14.3.2.11", dissect_ber_oid_NULL_callback, proto_x509af, "rsaSignature");
register_ber_oid_dissector("1.3.14.3.2.14", dissect_ber_oid_NULL_callback, proto_x509af, "mdc2WithRSASignature");
register_ber_oid_dissector("1.3.14.3.2.15", dissect_ber_oid_NULL_callback, proto_x509af, "shaWithRSASignature");
register_ber_oid_dissector("1.3.14.3.2.16", dissect_ber_oid_NULL_callback, proto_x509af, "dhWithCommonModulus");
register_ber_oid_dissector("1.3.14.3.2.17", dissect_ber_oid_NULL_callback, proto_x509af, "desEDE");
register_ber_oid_dissector("1.3.14.3.2.18", dissect_ber_oid_NULL_callback, proto_x509af, "sha");
register_ber_oid_dissector("1.3.14.3.2.19", dissect_ber_oid_NULL_callback, proto_x509af, "mdc-2");
register_ber_oid_dissector("1.3.14.3.2.20", dissect_ber_oid_NULL_callback, proto_x509af, "dsaCommon");
register_ber_oid_dissector("1.3.14.3.2.21", dissect_ber_oid_NULL_callback, proto_x509af, "dsaCommonWithSHA");
register_ber_oid_dissector("1.3.14.3.2.22", dissect_ber_oid_NULL_callback, proto_x509af, "rsaKeyTransport");
register_ber_oid_dissector("1.3.14.3.2.23", dissect_ber_oid_NULL_callback, proto_x509af, "keyed-hash-seal");
register_ber_oid_dissector("1.3.14.3.2.24", dissect_ber_oid_NULL_callback, proto_x509af, "md2WithRSASignature");
register_ber_oid_dissector("1.3.14.3.2.25", dissect_ber_oid_NULL_callback, proto_x509af, "md5WithRSASignature");
register_ber_oid_dissector("1.3.14.3.2.26", dissect_ber_oid_NULL_callback, proto_x509af, "SHA-1");
register_ber_oid_dissector("1.3.14.3.2.27", dissect_ber_oid_NULL_callback, proto_x509af, "dsaWithSHA1");
register_ber_oid_dissector("1.3.14.3.2.28", dissect_ber_oid_NULL_callback, proto_x509af, "dsaWithCommonSHA1");
register_ber_oid_dissector("1.3.14.3.2.29", dissect_ber_oid_NULL_callback, proto_x509af, "sha-1WithRSAEncryption");
dissector_add_string("ldap.name", "cACertificate", create_dissector_handle(dissect_x509af_Certificate_PDU, proto_x509af));
dissector_add_string("ldap.name", "userCertificate", create_dissector_handle(dissect_x509af_Certificate_PDU, proto_x509af));
dissector_add_string("ldap.name", "certificateRevocationList", create_dissector_handle(dissect_CertificateList_PDU, proto_x509af));
dissector_add_string("ldap.name", "crl", create_dissector_handle(dissect_CertificateList_PDU, proto_x509af));
dissector_add_string("ldap.name", "authorityRevocationList", create_dissector_handle(dissect_CertificateList_PDU, proto_x509af));
dissector_add_string("ldap.name", "arl", create_dissector_handle(dissect_CertificateList_PDU, proto_x509af));
dissector_add_string("ldap.name", "crossCertificatePair", create_dissector_handle(dissect_CertificatePair_PDU, proto_x509af));
}
