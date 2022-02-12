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
#include "packet-x509af-hfarr.c"
};
static gint *ett[] = {
&ett_pkix_crl,
#include "packet-x509af-ettarr.c"
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
#include "packet-x509af-dis-tab.c"
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
