static int
dissect_pkcs1_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_pkcs1_RSAPublicKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RSAPublicKey_sequence, hf_index, ett_pkcs1_RSAPublicKey);
return offset;
}
static int
dissect_pkcs1_DigestAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkcs1_Digest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_pkcs1_DigestInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DigestInfo_sequence, hf_index, ett_pkcs1_DigestInfo);
return offset;
}
static int
dissect_pkcs1_DSA_Params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DSA_Params_sequence, hf_index, ett_pkcs1_DSA_Params);
return offset;
}
static int
dissect_pkcs1_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_pkcs1_ValidationParams(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ValidationParams_sequence, hf_index, ett_pkcs1_ValidationParams);
return offset;
}
static int
dissect_pkcs1_DomainParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DomainParameters_sequence, hf_index, ett_pkcs1_DomainParameters);
return offset;
}
static int
dissect_pkcs1_KEA_Params_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkcs1_HashAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkcs1_MaskGenAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkcs1_RSASSA_PSS_params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RSASSA_PSS_params_sequence, hf_index, ett_pkcs1_RSASSA_PSS_params);
return offset;
}
static int
dissect_pkcs1_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkcs1_ECParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ECParameters_choice, hf_index, ett_pkcs1_ECParameters,
NULL);
return offset;
}
static int dissect_DSA_Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_DSA_Params(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_DSA_Params_PDU);
return offset;
}
static int dissect_DomainParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_DomainParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_DomainParameters_PDU);
return offset;
}
static int dissect_KEA_Params_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_KEA_Params_Id(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_KEA_Params_Id_PDU);
return offset;
}
static int dissect_HashAlgorithm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_HashAlgorithm(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_HashAlgorithm_PDU);
return offset;
}
static int dissect_RSASSA_PSS_params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_RSASSA_PSS_params(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_RSASSA_PSS_params_PDU);
return offset;
}
static int dissect_ECParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs1_ECParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs1_ECParameters_PDU);
return offset;
}
void proto_register_pkcs1(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/pkcs1/packet-pkcs1-hfarr.c"
{ &hf_pkcs1_DSA_Params_PDU,
{ "DSA-Params", "pkcs1.DSA_Params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_DomainParameters_PDU,
{ "DomainParameters", "pkcs1.DomainParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_KEA_Params_Id_PDU,
{ "KEA-Params-Id", "pkcs1.KEA_Params_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_HashAlgorithm_PDU,
{ "HashAlgorithm", "pkcs1.HashAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_RSASSA_PSS_params_PDU,
{ "RSASSA-PSS-params", "pkcs1.RSASSA_PSS_params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_ECParameters_PDU,
{ "ECParameters", "pkcs1.ECParameters",
FT_UINT32, BASE_DEC, VALS(pkcs1_ECParameters_vals), 0,
NULL, HFILL }},
{ &hf_pkcs1_modulus,
{ "modulus", "pkcs1.modulus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_publicExponent,
{ "publicExponent", "pkcs1.publicExponent",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_digestAlgorithm,
{ "digestAlgorithm", "pkcs1.digestAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"DigestAlgorithmIdentifier", HFILL }},
{ &hf_pkcs1_digest,
{ "digest", "pkcs1.digest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_p,
{ "p", "pkcs1.p",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_q,
{ "q", "pkcs1.q",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_g,
{ "g", "pkcs1.g",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_j,
{ "j", "pkcs1.j",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_validationParams,
{ "validationParams", "pkcs1.validationParams_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_seed,
{ "seed", "pkcs1.seed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_pkcs1_pgenCounter,
{ "pgenCounter", "pkcs1.pgenCounter",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_hashAlgorithm,
{ "hashAlgorithm", "pkcs1.hashAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_maskGenAlgorithm,
{ "maskGenAlgorithm", "pkcs1.maskGenAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs1_saltLength,
{ "saltLength", "pkcs1.saltLength",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_trailerField,
{ "trailerField", "pkcs1.trailerField",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_namedCurve,
{ "namedCurve", "pkcs1.namedCurve",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkcs1_r,
{ "r", "pkcs1.r",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs1_s,
{ "s", "pkcs1.s",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
#line 56 "../../asn1/pkcs1/packet-pkcs1-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/pkcs1/packet-pkcs1-ettarr.c"
&ett_pkcs1_RSAPublicKey,
&ett_pkcs1_DigestInfo,
&ett_pkcs1_DSA_Params,
&ett_pkcs1_DomainParameters,
&ett_pkcs1_ValidationParams,
&ett_pkcs1_RSASSA_PSS_params,
&ett_pkcs1_ECParameters,
&ett_pkcs1_DSA_Sig_Value,
&ett_pkcs1_ECDSA_Sig_Value,
#line 61 "../../asn1/pkcs1/packet-pkcs1-template.c"
};
proto_pkcs1 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkcs1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkcs1(void) {
#line 1 "../../asn1/pkcs1/packet-pkcs1-dis-tab.c"
new_register_ber_oid_dissector("1.2.840.10040.4.1", dissect_DSA_Params_PDU, proto_pkcs1, "id-dsa");
new_register_ber_oid_dissector("1.2.840.10046.2.1", dissect_DomainParameters_PDU, proto_pkcs1, "dhpublicnumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.1.1.22", dissect_KEA_Params_Id_PDU, proto_pkcs1, "id-keyExchangeAlgorithm");
new_register_ber_oid_dissector("1.2.840.10045.2.1", dissect_ECParameters_PDU, proto_pkcs1, "id-ecPublicKey");
new_register_ber_oid_dissector("1.3.132.1.12", dissect_ECParameters_PDU, proto_pkcs1, "id-ecDH");
new_register_ber_oid_dissector("1.2.840.10045.2.13", dissect_ECParameters_PDU, proto_pkcs1, "id-ecMQV");
new_register_ber_oid_dissector("1.2.840.113549.1.1.10", dissect_RSASSA_PSS_params_PDU, proto_pkcs1, "id-RSASSA-PSS");
new_register_ber_oid_dissector("1.2.840.113549.1.1.8", dissect_HashAlgorithm_PDU, proto_pkcs1, "id-mgf1");
#line 76 "../../asn1/pkcs1/packet-pkcs1-template.c"
register_ber_oid_dissector("1.2.840.113549.2.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2");
register_ber_oid_dissector("1.2.840.113549.2.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4");
register_ber_oid_dissector("1.2.840.113549.2.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5");
register_ber_oid_dissector("1.2.840.113549.1.1.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.3", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha1WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.6", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaOAEPEncryptionSET");
register_ber_oid_dissector("1.2.840.113549.1.1.11", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha256WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.12", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha384WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.13", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha512WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.14", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha224WithRSAEncryption");
oid_add_from_string("secp192r1","1.2.840.10045.3.1.1");
oid_add_from_string("sect163k1","1.3.132.0.1");
oid_add_from_string("sect163r2","1.3.132.0.15");
oid_add_from_string("secp224r1","1.3.132.0.33");
oid_add_from_string("sect233k1","1.3.132.0.26");
oid_add_from_string("sect233r1","1.3.132.0.27");
oid_add_from_string("secp256r1","1.2.840.10045.3.1.7");
oid_add_from_string("sect283k1","1.3.132.0.16");
oid_add_from_string("sect283r1","1.3.132.0.17");
oid_add_from_string("secp384r1","1.3.132.0.34");
oid_add_from_string("sect409k1","1.3.132.0.36");
oid_add_from_string("sect409r1","1.3.132.0.37");
oid_add_from_string("secp521r1","1.3.132.0.35");
oid_add_from_string("sect571k1","1.3.132.0.38");
oid_add_from_string("sect571r1","1.3.132.0.39");
oid_add_from_string("sha256", "2.16.840.1.101.3.4.2.1");
oid_add_from_string("sha384", "2.16.840.1.101.3.4.2.2");
oid_add_from_string("sha512", "2.16.840.1.101.3.4.2.3");
oid_add_from_string("sha224", "2.16.840.1.101.3.4.2.4");
}
