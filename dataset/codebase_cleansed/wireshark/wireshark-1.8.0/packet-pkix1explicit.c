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
int
dissect_pkix1explicit_UniqueIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_pkix1explicit_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_pkix1explicit_CertificateSerialNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1explicit_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_pkix1explicit_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_pkix1explicit_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_pkix1explicit_Time,
NULL);
return offset;
}
static int
dissect_pkix1explicit_T_extnId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_pkix1explicit_object_identifier_id, &object_identifier_id);
return offset;
}
static int
dissect_pkix1explicit_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkix1explicit_T_extnValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 56 "../../asn1/pkix1explicit/pkix1explicit.cnf"
gint8 class;
gboolean pc, ind;
gint32 tag;
guint32 len;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree);
return offset;
}
int
dissect_pkix1explicit_Extension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Extension_sequence, hf_index, ett_pkix1explicit_Extension);
return offset;
}
int
dissect_pkix1explicit_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Extensions_sequence_of, hf_index, ett_pkix1explicit_Extensions);
return offset;
}
static int
dissect_pkix1explicit_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1explicit_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_pkix1explicit_ValidationParms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ValidationParms_sequence, hf_index, ett_pkix1explicit_ValidationParms);
return offset;
}
static int
dissect_pkix1explicit_DomainParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DomainParameters_sequence, hf_index, ett_pkix1explicit_DomainParameters);
return offset;
}
static int
dissect_pkix1explicit_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkix1explicit_T_values_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 44 "../../asn1/pkix1explicit/pkix1explicit.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree);
return offset;
}
static int
dissect_pkix1explicit_T_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_values_set_of, hf_pkix1explicit_object_identifier_id, ett_pkix1explicit_T_values);
return offset;
}
int
dissect_pkix1explicit_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_sequence, hf_index, ett_pkix1explicit_Attribute);
return offset;
}
static int
dissect_pkix1explicit_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 50 "../../asn1/pkix1explicit/pkix1explicit.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree);
return offset;
}
int
dissect_pkix1explicit_AttributeTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeTypeAndValue_sequence, hf_index, ett_pkix1explicit_AttributeTypeAndValue);
return offset;
}
int
dissect_pkix1explicit_RelativeDistinguishedName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RelativeDistinguishedName_set_of, hf_index, ett_pkix1explicit_RelativeDistinguishedName);
return offset;
}
int
dissect_pkix1explicit_RDNSequence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RDNSequence_sequence_of, hf_index, ett_pkix1explicit_RDNSequence);
return offset;
}
int
dissect_pkix1explicit_DirectoryString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 38 "../../asn1/pkix1explicit/pkix1explicit.cnf"
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_pkix1explicit_TerminalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1explicit_TeletexString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_pkix1explicit_TeletexDomainDefinedAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TeletexDomainDefinedAttribute_sequence, hf_index, ett_pkix1explicit_TeletexDomainDefinedAttribute);
return offset;
}
static int
dissect_pkix1explicit_T_addressFamily(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 68 "../../asn1/pkix1explicit/pkix1explicit.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_pkix1explicit_addressFamily);
proto_tree_add_item(subtree, hf_pkix1explicit_addressFamily_afn, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
if(tvb_length(parameter_tvb)>2)
proto_tree_add_item(subtree, hf_pkix1explicit_addressFamily_safi, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_pkix1explicit_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_pkix1explicit_IPAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_pkix1explicit_IPAddressRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPAddressRange_sequence, hf_index, ett_pkix1explicit_IPAddressRange);
return offset;
}
static int
dissect_pkix1explicit_IPAddressOrRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPAddressOrRange_choice, hf_index, ett_pkix1explicit_IPAddressOrRange,
NULL);
return offset;
}
static int
dissect_pkix1explicit_SEQUENCE_OF_IPAddressOrRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_IPAddressOrRange_sequence_of, hf_index, ett_pkix1explicit_SEQUENCE_OF_IPAddressOrRange);
return offset;
}
static int
dissect_pkix1explicit_IPAddressChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPAddressChoice_choice, hf_index, ett_pkix1explicit_IPAddressChoice,
NULL);
return offset;
}
static int
dissect_pkix1explicit_IPAddressFamily(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPAddressFamily_sequence, hf_index, ett_pkix1explicit_IPAddressFamily);
return offset;
}
static int
dissect_pkix1explicit_IPAddrBlocks(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
IPAddrBlocks_sequence_of, hf_index, ett_pkix1explicit_IPAddrBlocks);
return offset;
}
static int
dissect_pkix1explicit_ASId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkix1explicit_ASRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ASRange_sequence, hf_index, ett_pkix1explicit_ASRange);
return offset;
}
static int
dissect_pkix1explicit_ASIdOrRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ASIdOrRange_choice, hf_index, ett_pkix1explicit_ASIdOrRange,
NULL);
return offset;
}
static int
dissect_pkix1explicit_SEQUENCE_OF_ASIdOrRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ASIdOrRange_sequence_of, hf_index, ett_pkix1explicit_SEQUENCE_OF_ASIdOrRange);
return offset;
}
static int
dissect_pkix1explicit_ASIdentifierChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ASIdentifierChoice_choice, hf_index, ett_pkix1explicit_ASIdentifierChoice,
NULL);
return offset;
}
static int
dissect_pkix1explicit_ASIdentifiers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ASIdentifiers_sequence, hf_index, ett_pkix1explicit_ASIdentifiers);
return offset;
}
static void dissect_DomainParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkix1explicit_DomainParameters(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkix1explicit_DomainParameters_PDU);
}
static void dissect_DirectoryString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkix1explicit_DirectoryString(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkix1explicit_DirectoryString_PDU);
}
static void dissect_IPAddrBlocks_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkix1explicit_IPAddrBlocks(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkix1explicit_IPAddrBlocks_PDU);
}
static void dissect_ASIdentifiers_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pkix1explicit_ASIdentifiers(FALSE, tvb, 0, &asn1_ctx, tree, hf_pkix1explicit_ASIdentifiers_PDU);
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
#line 1 "../../asn1/pkix1explicit/packet-pkix1explicit-hfarr.c"
{ &hf_pkix1explicit_DomainParameters_PDU,
{ "DomainParameters", "pkix1explicit.DomainParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_DirectoryString_PDU,
{ "DirectoryString", "pkix1explicit.DirectoryString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_IPAddrBlocks_PDU,
{ "IPAddrBlocks", "pkix1explicit.IPAddrBlocks",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_ASIdentifiers_PDU,
{ "ASIdentifiers", "pkix1explicit.ASIdentifiers",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_utcTime,
{ "utcTime", "pkix1explicit.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_generalTime,
{ "generalTime", "pkix1explicit.generalTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_pkix1explicit_Extensions_item,
{ "Extension", "pkix1explicit.Extension",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_extnId,
{ "extnId", "pkix1explicit.extnId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_critical,
{ "critical", "pkix1explicit.critical",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_pkix1explicit_extnValue,
{ "extnValue", "pkix1explicit.extnValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_p,
{ "p", "pkix1explicit.p",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1explicit_g,
{ "g", "pkix1explicit.g",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1explicit_q,
{ "q", "pkix1explicit.q",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1explicit_j,
{ "j", "pkix1explicit.j",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1explicit_validationParms,
{ "validationParms", "pkix1explicit.validationParms",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_seed,
{ "seed", "pkix1explicit.seed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_pkix1explicit_pgenCounter,
{ "pgenCounter", "pkix1explicit.pgenCounter",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkix1explicit_type,
{ "type", "pkix1explicit.type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_pkix1explicit_values,
{ "values", "pkix1explicit.values",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_values_item,
{ "values item", "pkix1explicit.values_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_value,
{ "value", "pkix1explicit.value",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_RDNSequence_item,
{ "RelativeDistinguishedName", "pkix1explicit.RelativeDistinguishedName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_RelativeDistinguishedName_item,
{ "AttributeTypeAndValue", "pkix1explicit.AttributeTypeAndValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_type_01,
{ "type", "pkix1explicit.type",
FT_STRING, BASE_NONE, NULL, 0,
"TeletexString", HFILL }},
{ &hf_pkix1explicit_value_01,
{ "value", "pkix1explicit.value",
FT_STRING, BASE_NONE, NULL, 0,
"TeletexString", HFILL }},
{ &hf_pkix1explicit_IPAddrBlocks_item,
{ "IPAddressFamily", "pkix1explicit.IPAddressFamily",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_addressFamily,
{ "addressFamily", "pkix1explicit.addressFamily",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_ipAddressChoice,
{ "ipAddressChoice", "pkix1explicit.ipAddressChoice",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_IPAddressChoice_vals), 0,
NULL, HFILL }},
{ &hf_pkix1explicit_inherit,
{ "inherit", "pkix1explicit.inherit",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkix1explicit_addressesOrRanges,
{ "addressesOrRanges", "pkix1explicit.addressesOrRanges",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IPAddressOrRange", HFILL }},
{ &hf_pkix1explicit_addressesOrRanges_item,
{ "IPAddressOrRange", "pkix1explicit.IPAddressOrRange",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_IPAddressOrRange_vals), 0,
NULL, HFILL }},
{ &hf_pkix1explicit_addressPrefix,
{ "addressPrefix", "pkix1explicit.addressPrefix",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_pkix1explicit_addressRange,
{ "addressRange", "pkix1explicit.addressRange",
FT_NONE, BASE_NONE, NULL, 0,
"IPAddressRange", HFILL }},
{ &hf_pkix1explicit_min,
{ "min", "pkix1explicit.min",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_pkix1explicit_max,
{ "max", "pkix1explicit.max",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_pkix1explicit_asnum,
{ "asnum", "pkix1explicit.asnum",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_ASIdentifierChoice_vals), 0,
"ASIdentifierChoice", HFILL }},
{ &hf_pkix1explicit_rdi,
{ "rdi", "pkix1explicit.rdi",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_ASIdentifierChoice_vals), 0,
"ASIdentifierChoice", HFILL }},
{ &hf_pkix1explicit_asIdsOrRanges,
{ "asIdsOrRanges", "pkix1explicit.asIdsOrRanges",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ASIdOrRange", HFILL }},
{ &hf_pkix1explicit_asIdsOrRanges_item,
{ "ASIdOrRange", "pkix1explicit.ASIdOrRange",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_ASIdOrRange_vals), 0,
NULL, HFILL }},
{ &hf_pkix1explicit_id,
{ "id", "pkix1explicit.id",
FT_INT32, BASE_DEC, NULL, 0,
"ASId", HFILL }},
{ &hf_pkix1explicit_range,
{ "range", "pkix1explicit.range",
FT_NONE, BASE_NONE, NULL, 0,
"ASRange", HFILL }},
{ &hf_pkix1explicit_min_01,
{ "min", "pkix1explicit.min",
FT_INT32, BASE_DEC, NULL, 0,
"ASId", HFILL }},
{ &hf_pkix1explicit_max_01,
{ "max", "pkix1explicit.max",
FT_INT32, BASE_DEC, NULL, 0,
"ASId", HFILL }},
#line 122 "../../asn1/pkix1explicit/packet-pkix1explicit-template.c"
};
static gint *ett[] = {
&ett_pkix1explicit_addressFamily,
#line 1 "../../asn1/pkix1explicit/packet-pkix1explicit-ettarr.c"
&ett_pkix1explicit_Time,
&ett_pkix1explicit_Extensions,
&ett_pkix1explicit_Extension,
&ett_pkix1explicit_DomainParameters,
&ett_pkix1explicit_ValidationParms,
&ett_pkix1explicit_Attribute,
&ett_pkix1explicit_T_values,
&ett_pkix1explicit_AttributeTypeAndValue,
&ett_pkix1explicit_RDNSequence,
&ett_pkix1explicit_RelativeDistinguishedName,
&ett_pkix1explicit_TeletexDomainDefinedAttribute,
&ett_pkix1explicit_IPAddrBlocks,
&ett_pkix1explicit_IPAddressFamily,
&ett_pkix1explicit_IPAddressChoice,
&ett_pkix1explicit_SEQUENCE_OF_IPAddressOrRange,
&ett_pkix1explicit_IPAddressOrRange,
&ett_pkix1explicit_IPAddressRange,
&ett_pkix1explicit_ASIdentifiers,
&ett_pkix1explicit_ASIdentifierChoice,
&ett_pkix1explicit_SEQUENCE_OF_ASIdOrRange,
&ett_pkix1explicit_ASIdOrRange,
&ett_pkix1explicit_ASRange,
#line 128 "../../asn1/pkix1explicit/packet-pkix1explicit-template.c"
};
proto_pkix1explicit = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkix1explicit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkix1explicit(void) {
oid_add_from_string("id-pkix","1.3.6.1.5.5.7");
oid_add_from_string("id-dsa-with-sha1","1.2.840.10040.4.3");
#line 1 "../../asn1/pkix1explicit/packet-pkix1explicit-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.2.1", dissect_DirectoryString_PDU, proto_pkix1explicit, "id-qt-cps");
register_ber_oid_dissector("1.2.840.10046.2.1", dissect_DomainParameters_PDU, proto_pkix1explicit, "dhpublicnumber");
register_ber_oid_dissector("1.3.6.1.5.5.7.1.7", dissect_IPAddrBlocks_PDU, proto_pkix1explicit, "id-pe-ipAddrBlocks");
register_ber_oid_dissector("1.3.6.1.5.5.7.1.8", dissect_ASIdentifiers_PDU, proto_pkix1explicit, "id-pe-autonomousSysIds");
#line 145 "../../asn1/pkix1explicit/packet-pkix1explicit-template.c"
}
