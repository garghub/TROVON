int
dissect_pkix1explicit_Certificate(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509af_Certificate(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1explicit_CertificateList(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509af_CertificateList(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1explicit_GeneralName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509ce_GeneralName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1explicit_Name(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509if_Name(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1explicit_AlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1explicit_SubjectPublicKeyInfo(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
offset = dissect_x509af_SubjectPublicKeyInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
void proto_register_pkix1explicit(void) {
static hf_register_info hf[] = {
{ &hf_pkix1explicit_object_identifier_id,
{ "Id", "pkix1explicit.id", FT_STRING, BASE_NONE, NULL, 0,
"Object identifier Id", HFILL }},
{ &hf_pkix1explicit_addressFamily_afn,
{ "Address family(AFN)", "pkix1explicit.addressfamily", FT_UINT16, BASE_DEC, VALS(afn_vals), 0,
NULL, HFILL }},
{ &hf_pkix1explicit_addressFamily_safi,
{ "Subsequent Address Family Identifiers (SAFI)", "pkix1explicit.addressfamily.safi", FT_UINT16, BASE_DEC, NULL, 0,
"Subsequent Address Family Identifiers (SAFI) RFC4760", HFILL }},
#include "packet-pkix1explicit-hfarr.c"
};
static gint *ett[] = {
&ett_pkix1explicit_addressFamily,
#include "packet-pkix1explicit-ettarr.c"
};
proto_pkix1explicit = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkix1explicit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkix1explicit(void) {
oid_add_from_string("id-pkix","1.3.6.1.5.5.7");
oid_add_from_string("id-dsa-with-sha1","1.2.840.10040.4.3");
#include "packet-pkix1explicit-dis-tab.c"
}
