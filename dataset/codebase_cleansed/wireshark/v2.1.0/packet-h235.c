static int
dissect_xxx_ToBeSigned(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
dissect_per_not_decoded_yet(tree, actx->pinfo, tvb, "ToBeSigned");
return offset;
}
static int
dissect_h235_ChallengeString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 128, FALSE, NULL);
return offset;
}
int
dissect_h235_TimeStamp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h235_RandomVal(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h235_Password(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h235_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h235_KeyMaterial(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 2048, FALSE, NULL, NULL);
return offset;
}
static int
dissect_h235_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h235_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h235_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_NonStandardParameter, NonStandardParameter_sequence);
return offset;
}
static int
dissect_h235_BIT_STRING_SIZE_0_2048(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
0, 2048, FALSE, NULL, NULL);
return offset;
}
static int
dissect_h235_DHset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_DHset, DHset_sequence);
return offset;
}
static int
dissect_h235_BIT_STRING_SIZE_0_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
0, 511, FALSE, NULL, NULL);
return offset;
}
static int
dissect_h235_ECpoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_ECpoint, ECpoint_sequence);
return offset;
}
static int
dissect_h235_T_eckasdhp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_eckasdhp, T_eckasdhp_sequence);
return offset;
}
static int
dissect_h235_T_eckasdh2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_eckasdh2, T_eckasdh2_sequence);
return offset;
}
static int
dissect_h235_ECKASDH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_ECKASDH, ECKASDH_choice,
NULL);
return offset;
}
static int
dissect_h235_TypedCertificate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_TypedCertificate, TypedCertificate_sequence);
return offset;
}
static int
dissect_h235_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h235_AuthenticationBES(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_AuthenticationBES, AuthenticationBES_choice,
NULL);
return offset;
}
int
dissect_h235_AuthenticationMechanism(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_AuthenticationMechanism, AuthenticationMechanism_choice,
NULL);
return offset;
}
static int
dissect_h235_INTEGER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h235_IV8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_h235_IV16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_h235_Params(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_Params, Params_sequence);
return offset;
}
int
dissect_h235_ENCRYPTED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 63 "./asn1/h235/h235.cnf"
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, proto_h235, tvb, offset>>3, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_ENCRYPTED, ENCRYPTED_sequence);
return offset;
}
static int
dissect_h235_BIT_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
int
dissect_h235_SIGNED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 58 "./asn1/h235/h235.cnf"
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, proto_h235, tvb, offset>>3, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_SIGNED, SIGNED_sequence);
return offset;
}
static int
dissect_h235_V3KeySyncMaterial(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_V3KeySyncMaterial, V3KeySyncMaterial_sequence);
return offset;
}
static int
dissect_h235_H235Key(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_H235Key, H235Key_choice,
NULL);
return offset;
}
static int
dissect_h235_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h235_BMPString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_h235_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h235_Element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_Element, Element_choice,
NULL);
return offset;
}
static int
dissect_h235_ProfileElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_ProfileElement, ProfileElement_sequence);
return offset;
}
static int
dissect_h235_SEQUENCE_OF_ProfileElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h235_SEQUENCE_OF_ProfileElement, SEQUENCE_OF_ProfileElement_sequence_of);
return offset;
}
int
dissect_h235_ClearToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 74 "./asn1/h235/h235.cnf"
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, proto_h235, tvb, offset>>3, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_ClearToken, ClearToken_sequence);
return offset;
}
int
dissect_h235_HASHED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 68 "./asn1/h235/h235.cnf"
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, proto_h235, tvb, offset>>3, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_HASHED, HASHED_sequence);
return offset;
}
static int
dissect_h235_T_cryptoEncryptedToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_cryptoEncryptedToken, T_cryptoEncryptedToken_sequence);
return offset;
}
static int
dissect_h235_T_cryptoSignedToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_cryptoSignedToken, T_cryptoSignedToken_sequence);
return offset;
}
static int
dissect_h235_T_cryptoHashedToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_cryptoHashedToken, T_cryptoHashedToken_sequence);
return offset;
}
int
dissect_h235_CryptoToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 80 "./asn1/h235/h235.cnf"
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, proto_h235, tvb, offset>>3, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_CryptoToken, CryptoToken_choice,
NULL);
return offset;
}
static int
dissect_h235_INTEGER_0_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 24U, NULL, FALSE);
return offset;
}
static int
dissect_h235_FecOrder(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_FecOrder, FecOrder_sequence);
return offset;
}
static int
dissect_h235_INTEGER_64_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
64U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h235_SEQUENCE_OF_GenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h235_SEQUENCE_OF_GenericData, SEQUENCE_OF_GenericData_sequence_of);
return offset;
}
static int
dissect_h235_SrtpSessionParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_SrtpSessionParameters, SrtpSessionParameters_sequence);
return offset;
}
static int
dissect_h235_SrtpCryptoInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_SrtpCryptoInfo, SrtpCryptoInfo_sequence);
return offset;
}
static int
dissect_h235_SrtpCryptoCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h235_SrtpCryptoCapability, SrtpCryptoCapability_sequence_of);
return offset;
}
static int
dissect_h235_T_lifetime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h235_T_lifetime, T_lifetime_choice,
NULL);
return offset;
}
static int
dissect_h235_INTEGER_1_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_h235_T_mki(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_T_mki, T_mki_sequence);
return offset;
}
static int
dissect_h235_SrtpKeyParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h235_SrtpKeyParameters, SrtpKeyParameters_sequence);
return offset;
}
int
dissect_h235_SrtpKeys(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h235_SrtpKeys, SrtpKeys_sequence_of);
return offset;
}
static int dissect_SrtpCryptoCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h235_SrtpCryptoCapability(tvb, offset, &asn1_ctx, tree, hf_h235_SrtpCryptoCapability_PDU);
offset += 7; offset >>= 3;
return offset;
}
void proto_register_h235(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/h235/packet-h235-hfarr.c"
{ &hf_h235_SrtpCryptoCapability_PDU,
{ "SrtpCryptoCapability", "h235.SrtpCryptoCapability",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h235_nonStandardIdentifier,
{ "nonStandardIdentifier", "h235.nonStandardIdentifier",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_data,
{ "data", "h235.data",
FT_UINT32, BASE_DEC, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_halfkey,
{ "halfkey", "h235.halfkey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_2048", HFILL }},
{ &hf_h235_modSize,
{ "modSize", "h235.modSize",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_2048", HFILL }},
{ &hf_h235_generator,
{ "generator", "h235.generator",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_2048", HFILL }},
{ &hf_h235_x,
{ "x", "h235.x",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_y,
{ "y", "h235.y",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_eckasdhp,
{ "eckasdhp", "h235.eckasdhp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_public_key,
{ "public-key", "h235.public_key_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECpoint", HFILL }},
{ &hf_h235_modulus,
{ "modulus", "h235.modulus",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_base,
{ "base", "h235.base_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECpoint", HFILL }},
{ &hf_h235_weierstrassA,
{ "weierstrassA", "h235.weierstrassA",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_weierstrassB,
{ "weierstrassB", "h235.weierstrassB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_eckasdh2,
{ "eckasdh2", "h235.eckasdh2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_fieldSize,
{ "fieldSize", "h235.fieldSize",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_511", HFILL }},
{ &hf_h235_type,
{ "type", "h235.type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_certificatedata,
{ "certificate", "h235.certificate",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_default,
{ "default", "h235.default_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_radius,
{ "radius", "h235.radius_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_dhExch,
{ "dhExch", "h235.dhExch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_pwdSymEnc,
{ "pwdSymEnc", "h235.pwdSymEnc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_pwdHash,
{ "pwdHash", "h235.pwdHash_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_certSign,
{ "certSign", "h235.certSign_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_ipsec,
{ "ipsec", "h235.ipsec_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_tls,
{ "tls", "h235.tls_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_nonStandard,
{ "nonStandard", "h235.nonStandard_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h235_authenticationBES,
{ "authenticationBES", "h235.authenticationBES",
FT_UINT32, BASE_DEC, VALS(h235_AuthenticationBES_vals), 0,
NULL, HFILL }},
{ &hf_h235_keyExch,
{ "keyExch", "h235.keyExch",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_tokenOID,
{ "tokenOID", "h235.tokenOID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_timeStamp,
{ "timeStamp", "h235.timeStamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }},
{ &hf_h235_password,
{ "password", "h235.password",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_dhkey,
{ "dhkey", "h235.dhkey_element",
FT_NONE, BASE_NONE, NULL, 0,
"DHset", HFILL }},
{ &hf_h235_challenge,
{ "challenge", "h235.challenge",
FT_BYTES, BASE_NONE, NULL, 0,
"ChallengeString", HFILL }},
{ &hf_h235_random,
{ "random", "h235.random",
FT_INT32, BASE_DEC, NULL, 0,
"RandomVal", HFILL }},
{ &hf_h235_certificate,
{ "certificate", "h235.certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
"TypedCertificate", HFILL }},
{ &hf_h235_generalID,
{ "generalID", "h235.generalID",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_h235_eckasdhkey,
{ "eckasdhkey", "h235.eckasdhkey",
FT_UINT32, BASE_DEC, VALS(h235_ECKASDH_vals), 0,
"ECKASDH", HFILL }},
{ &hf_h235_sendersID,
{ "sendersID", "h235.sendersID",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_h235_h235Key,
{ "h235Key", "h235.h235Key",
FT_UINT32, BASE_DEC, VALS(h235_H235Key_vals), 0,
NULL, HFILL }},
{ &hf_h235_profileInfo,
{ "profileInfo", "h235.profileInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ProfileElement", HFILL }},
{ &hf_h235_profileInfo_item,
{ "ProfileElement", "h235.ProfileElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_elementID,
{ "elementID", "h235.elementID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h235_paramS,
{ "paramS", "h235.paramS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_element,
{ "element", "h235.element",
FT_UINT32, BASE_DEC, VALS(h235_Element_vals), 0,
NULL, HFILL }},
{ &hf_h235_octets,
{ "octets", "h235.octets",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_integer,
{ "integer", "h235.integer",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h235_bits,
{ "bits", "h235.bits",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_h235_name,
{ "name", "h235.name",
FT_STRING, BASE_NONE, NULL, 0,
"BMPString", HFILL }},
{ &hf_h235_flag,
{ "flag", "h235.flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h235_toBeSigned,
{ "toBeSigned", "h235.toBeSigned_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_algorithmOID,
{ "algorithmOID", "h235.algorithmOID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_signaturedata,
{ "signature", "h235.signature",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_h235_encryptedData,
{ "encryptedData", "h235.encryptedData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_hash,
{ "hash", "h235.hash",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_h235_ranInt,
{ "ranInt", "h235.ranInt",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_h235_iv8,
{ "iv8", "h235.iv8",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_iv16,
{ "iv16", "h235.iv16",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_iv,
{ "iv", "h235.iv",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_clearSalt,
{ "clearSalt", "h235.clearSalt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_cryptoEncryptedToken,
{ "cryptoEncryptedToken", "h235.cryptoEncryptedToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_encryptedToken,
{ "token", "h235.token_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENCRYPTED", HFILL }},
{ &hf_h235_cryptoSignedToken,
{ "cryptoSignedToken", "h235.cryptoSignedToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_signedToken,
{ "token", "h235.token_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIGNED", HFILL }},
{ &hf_h235_cryptoHashedToken,
{ "cryptoHashedToken", "h235.cryptoHashedToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_hashedVals,
{ "hashedVals", "h235.hashedVals_element",
FT_NONE, BASE_NONE, NULL, 0,
"ClearToken", HFILL }},
{ &hf_h235_hashedToken,
{ "token", "h235.token_element",
FT_NONE, BASE_NONE, NULL, 0,
"HASHED", HFILL }},
{ &hf_h235_cryptoPwdEncr,
{ "cryptoPwdEncr", "h235.cryptoPwdEncr_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENCRYPTED", HFILL }},
{ &hf_h235_secureChannel,
{ "secureChannel", "h235.secureChannel",
FT_BYTES, BASE_NONE, NULL, 0,
"KeyMaterial", HFILL }},
{ &hf_h235_sharedSecret,
{ "sharedSecret", "h235.sharedSecret_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENCRYPTED", HFILL }},
{ &hf_h235_certProtectedKey,
{ "certProtectedKey", "h235.certProtectedKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"SIGNED", HFILL }},
{ &hf_h235_secureSharedSecret,
{ "secureSharedSecret", "h235.secureSharedSecret_element",
FT_NONE, BASE_NONE, NULL, 0,
"V3KeySyncMaterial", HFILL }},
{ &hf_h235_encryptedSessionKey,
{ "encryptedSessionKey", "h235.encryptedSessionKey",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_encryptedSaltingKey,
{ "encryptedSaltingKey", "h235.encryptedSaltingKey",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_clearSaltingKey,
{ "clearSaltingKey", "h235.clearSaltingKey",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_paramSsalt,
{ "paramSsalt", "h235.paramSsalt_element",
FT_NONE, BASE_NONE, NULL, 0,
"Params", HFILL }},
{ &hf_h235_keyDerivationOID,
{ "keyDerivationOID", "h235.keyDerivationOID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_genericKeyMaterial,
{ "genericKeyMaterial", "h235.genericKeyMaterial",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_SrtpCryptoCapability_item,
{ "SrtpCryptoInfo", "h235.SrtpCryptoInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_cryptoSuite,
{ "cryptoSuite", "h235.cryptoSuite",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h235_sessionParams,
{ "sessionParams", "h235.sessionParams_element",
FT_NONE, BASE_NONE, NULL, 0,
"SrtpSessionParameters", HFILL }},
{ &hf_h235_allowMKI,
{ "allowMKI", "h235.allowMKI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h235_SrtpKeys_item,
{ "SrtpKeyParameters", "h235.SrtpKeyParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_masterKey,
{ "masterKey", "h235.masterKey",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_masterSalt,
{ "masterSalt", "h235.masterSalt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_lifetime,
{ "lifetime", "h235.lifetime",
FT_UINT32, BASE_DEC, VALS(h235_T_lifetime_vals), 0,
NULL, HFILL }},
{ &hf_h235_powerOfTwo,
{ "powerOfTwo", "h235.powerOfTwo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_h235_specific,
{ "specific", "h235.specific",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_h235_mki,
{ "mki", "h235.mki_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_length,
{ "length", "h235.length",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_128", HFILL }},
{ &hf_h235_value,
{ "value", "h235.value",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h235_kdr,
{ "kdr", "h235.kdr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_24", HFILL }},
{ &hf_h235_unencryptedSrtp,
{ "unencryptedSrtp", "h235.unencryptedSrtp",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h235_unencryptedSrtcp,
{ "unencryptedSrtcp", "h235.unencryptedSrtcp",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h235_unauthenticatedSrtp,
{ "unauthenticatedSrtp", "h235.unauthenticatedSrtp",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h235_fecOrder,
{ "fecOrder", "h235.fecOrder_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_windowSizeHint,
{ "windowSizeHint", "h235.windowSizeHint",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_64_65535", HFILL }},
{ &hf_h235_newParameter,
{ "newParameter", "h235.newParameter",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GenericData", HFILL }},
{ &hf_h235_newParameter_item,
{ "GenericData", "h235.GenericData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_fecBeforeSrtp,
{ "fecBeforeSrtp", "h235.fecBeforeSrtp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h235_fecAfterSrtp,
{ "fecAfterSrtp", "h235.fecAfterSrtp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 72 "./asn1/h235/packet-h235-template.c"
};
static gint *ett[] = {
#line 1 "./asn1/h235/packet-h235-ettarr.c"
&ett_h235_NonStandardParameter,
&ett_h235_DHset,
&ett_h235_ECpoint,
&ett_h235_ECKASDH,
&ett_h235_T_eckasdhp,
&ett_h235_T_eckasdh2,
&ett_h235_TypedCertificate,
&ett_h235_AuthenticationBES,
&ett_h235_AuthenticationMechanism,
&ett_h235_ClearToken,
&ett_h235_SEQUENCE_OF_ProfileElement,
&ett_h235_ProfileElement,
&ett_h235_Element,
&ett_h235_SIGNED,
&ett_h235_ENCRYPTED,
&ett_h235_HASHED,
&ett_h235_Params,
&ett_h235_CryptoToken,
&ett_h235_T_cryptoEncryptedToken,
&ett_h235_T_cryptoSignedToken,
&ett_h235_T_cryptoHashedToken,
&ett_h235_H235Key,
&ett_h235_V3KeySyncMaterial,
&ett_h235_SrtpCryptoCapability,
&ett_h235_SrtpCryptoInfo,
&ett_h235_SrtpKeys,
&ett_h235_SrtpKeyParameters,
&ett_h235_T_lifetime,
&ett_h235_T_mki,
&ett_h235_SrtpSessionParameters,
&ett_h235_SEQUENCE_OF_GenericData,
&ett_h235_FecOrder,
#line 77 "./asn1/h235/packet-h235-template.c"
};
proto_h235 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h235, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
oid_add_from_string("all fields in RAS/CS","0.0.8.235.0.1.1");
oid_add_from_string("all fields in RAS/CS","0.0.8.235.0.2.1");
oid_add_from_string("ClearToken","0.0.8.235.0.1.5");
oid_add_from_string("ClearToken","0.0.8.235.0.2.5");
oid_add_from_string("HMAC-SHA1-96","0.0.8.235.0.1.6");
oid_add_from_string("HMAC-SHA1-96","0.0.8.235.0.2.6");
oid_add_from_string("MIKEY", OID_MIKEY);
oid_add_from_string("MIKEY-PS", OID_MIKEY_PS);
oid_add_from_string("MIKEY-DHHMAC", OID_MIKEY_DHHMAC);
oid_add_from_string("MIKEY-PK-SIGN", OID_MIKEY_PK_SIGN);
oid_add_from_string("MIKEY-DH-SIGN", OID_MIKEY_DH_SIGN);
oid_add_from_string("TG",OID_TG);
oid_add_from_string("SG",OID_SG);
oid_add_from_string("AES_CM_128_HMAC_SHA1_80","0.0.8.235.0.4.91");
oid_add_from_string("AES_CM_128_HMAC_SHA1_32","0.0.8.235.0.4.92");
oid_add_from_string("F8_128_HMAC_SHA1_80","0.0.8.235.0.4.93");
}
void proto_reg_handoff_h235(void) {
dissector_handle_t mikey_handle;
mikey_handle = find_dissector("mikey");
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PS "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DHHMAC "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PK_SIGN "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DH_SIGN "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/0", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/76", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/72", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/73", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/74", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/75", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY "/nonCollapsing/76", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PS "/nonCollapsing/72", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DHHMAC "/nonCollapsing/73", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PK_SIGN "/nonCollapsing/74", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DH_SIGN "/nonCollapsing/75", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/0.0.8.235.0.4.90/nonCollapsingRaw",
create_dissector_handle(dissect_SrtpCryptoCapability_PDU, proto_h235));
}
