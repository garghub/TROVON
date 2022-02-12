static int
dissect_HI2Operations_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_HI2Operations_T_iRIversion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_LawfulInterceptionIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_5(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_25(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_iP_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_4_16(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_IA5String_SIZE_7_45(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_IP_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IP_value_choice, hf_index, ett_HI2Operations_IP_value,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_iP_assignment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_IPAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPAddress_sequence, hf_index, ett_HI2Operations_IPAddress);
return offset;
}
static int
dissect_HI2Operations_Network_Element_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Network_Element_Identifier_choice, hf_index, ett_HI2Operations_Network_Element_Identifier,
NULL);
return offset;
}
static int
dissect_HI2Operations_Network_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Network_Identifier_sequence, hf_index, ett_HI2Operations_Network_Identifier);
return offset;
}
static int
dissect_HI2Operations_CommunicationIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CommunicationIdentifier_sequence, hf_index, ett_HI2Operations_CommunicationIdentifier);
return offset;
}
static int
dissect_HI2Operations_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_HI2Operations_T_winterSummerIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_LocalTimeStamp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LocalTimeStamp_sequence, hf_index, ett_HI2Operations_LocalTimeStamp);
return offset;
}
static int
dissect_HI2Operations_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_HI2Operations_TimeStamp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TimeStamp_choice, hf_index, ett_HI2Operations_TimeStamp,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_intercepted_Call_Direct(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_Intercepted_Call_State(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_3(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_5_7(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_1023(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_16383(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_65535(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_ms_Loc(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_ms_Loc_sequence, hf_index, ett_HI2Operations_T_ms_Loc);
return offset;
}
static int
dissect_HI2Operations_TetraLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TetraLocation_choice, hf_index, ett_HI2Operations_TetraLocation,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_6(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_7_10(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_8_11(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_MapDatum(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_359(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_geoCoordinates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_geoCoordinates_sequence, hf_index, ett_HI2Operations_T_geoCoordinates);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_10(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_7(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_utmCoordinates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_utmCoordinates_sequence, hf_index, ett_HI2Operations_T_utmCoordinates);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_13(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_utmRefCoordinates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_utmRefCoordinates_sequence, hf_index, ett_HI2Operations_T_utmRefCoordinates);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GSMLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GSMLocation_choice, hf_index, ett_HI2Operations_GSMLocation,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_latitudeSign(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_8388607(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_INTEGER_M8388608_8388607(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GeographicalCoordinates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GeographicalCoordinates_sequence, hf_index, ett_HI2Operations_GeographicalCoordinates);
return offset;
}
static int
dissect_HI2Operations_GA_Point(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GA_Point_sequence, hf_index, ett_HI2Operations_GA_Point);
return offset;
}
static int
dissect_HI2Operations_INTEGER_0_127(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GA_PointWithUnCertainty(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GA_PointWithUnCertainty_sequence, hf_index, ett_HI2Operations_GA_PointWithUnCertainty);
return offset;
}
static int
dissect_HI2Operations_GA_Polygon_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GA_Polygon_item_sequence, hf_index, ett_HI2Operations_GA_Polygon_item);
return offset;
}
static int
dissect_HI2Operations_GA_Polygon(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
GA_Polygon_sequence_of, hf_index, ett_HI2Operations_GA_Polygon);
return offset;
}
static int
dissect_HI2Operations_UMTSLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UMTSLocation_choice, hf_index, ett_HI2Operations_UMTSLocation,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_7(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_Location(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Location_sequence, hf_index, ett_HI2Operations_Location);
return offset;
}
static int
dissect_HI2Operations_T_party_Qualifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_15(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_3_8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CallingPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CallingPartyNumber_choice, hf_index, ett_HI2Operations_CallingPartyNumber,
NULL);
return offset;
}
static int
dissect_HI2Operations_CalledPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CalledPartyNumber_choice, hf_index, ett_HI2Operations_CalledPartyNumber,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_9(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_partyIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_partyIdentity_sequence, hf_index, ett_HI2Operations_T_partyIdentity);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_256(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_ISUP_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ISUP_parameters_set_of, hf_index, ett_HI2Operations_ISUP_parameters);
return offset;
}
static int
dissect_HI2Operations_DSS1_parameters_codeset_0(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_parameters_codeset_0_set_of, hf_index, ett_HI2Operations_DSS1_parameters_codeset_0);
return offset;
}
static int
dissect_HI2Operations_MAP_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
MAP_parameters_set_of, hf_index, ett_HI2Operations_MAP_parameters);
return offset;
}
static int
dissect_HI2Operations_Services_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Services_Information_sequence, hf_index, ett_HI2Operations_Services_Information);
return offset;
}
static int
dissect_HI2Operations_ISUP_SS_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ISUP_SS_parameters_set_of, hf_index, ett_HI2Operations_ISUP_SS_parameters);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_parameters_codeset_0(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_parameters_codeset_0_set_of, hf_index, ett_HI2Operations_DSS1_SS_parameters_codeset_0);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_parameters_codeset_4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_parameters_codeset_4_set_of, hf_index, ett_HI2Operations_DSS1_SS_parameters_codeset_4);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_parameters_codeset_5(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_parameters_codeset_5_set_of, hf_index, ett_HI2Operations_DSS1_SS_parameters_codeset_5);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_parameters_codeset_6(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_parameters_codeset_6_set_of, hf_index, ett_HI2Operations_DSS1_SS_parameters_codeset_6);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_parameters_codeset_7(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_parameters_codeset_7_set_of, hf_index, ett_HI2Operations_DSS1_SS_parameters_codeset_7);
return offset;
}
static int
dissect_HI2Operations_DSS1_SS_Invoke_Components(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DSS1_SS_Invoke_Components_set_of, hf_index, ett_HI2Operations_DSS1_SS_Invoke_Components);
return offset;
}
static int
dissect_HI2Operations_MAP_SS_Parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
MAP_SS_Parameters_set_of, hf_index, ett_HI2Operations_MAP_SS_Parameters);
return offset;
}
static int
dissect_HI2Operations_MAP_SS_Invoke_Components(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
MAP_SS_Invoke_Components_set_of, hf_index, ett_HI2Operations_MAP_SS_Invoke_Components);
return offset;
}
static int
dissect_HI2Operations_Standard_Supplementary_Services(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Standard_Supplementary_Services_sequence, hf_index, ett_HI2Operations_Standard_Supplementary_Services);
return offset;
}
static int
dissect_HI2Operations_SimpleIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_SciDataMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_Non_Standard_Supplementary_Services_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Non_Standard_Supplementary_Services_item_choice, hf_index, ett_HI2Operations_Non_Standard_Supplementary_Services_item,
NULL);
return offset;
}
static int
dissect_HI2Operations_Non_Standard_Supplementary_Services(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Non_Standard_Supplementary_Services_set_of, hf_index, ett_HI2Operations_Non_Standard_Supplementary_Services);
return offset;
}
static int
dissect_HI2Operations_Other_Services(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Other_Services_set_of, hf_index, ett_HI2Operations_Other_Services);
return offset;
}
static int
dissect_HI2Operations_Supplementary_Services(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Supplementary_Services_sequence, hf_index, ett_HI2Operations_Supplementary_Services);
return offset;
}
static int
dissect_HI2Operations_X25Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_DataNodeAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DataNodeAddress_choice, hf_index, ett_HI2Operations_DataNodeAddress,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_100(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GPRS_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GPRS_parameters_sequence, hf_index, ett_HI2Operations_GPRS_parameters);
return offset;
}
static int
dissect_HI2Operations_Services_Data_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Services_Data_Information_sequence, hf_index, ett_HI2Operations_Services_Data_Information);
return offset;
}
static int
dissect_HI2Operations_PartyInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PartyInformation_sequence, hf_index, ett_HI2Operations_PartyInformation);
return offset;
}
static int
dissect_HI2Operations_SET_SIZE_1_10_OF_PartyInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_10_OF_PartyInformation_set_of, hf_index, ett_HI2Operations_SET_SIZE_1_10_OF_PartyInformation);
return offset;
}
static int
dissect_HI2Operations_CCLink_State(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CallContentLinkCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallContentLinkCharacteristics_sequence, hf_index, ett_HI2Operations_CallContentLinkCharacteristics);
return offset;
}
static int
dissect_HI2Operations_T_callContentLinkInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callContentLinkInformation_sequence, hf_index, ett_HI2Operations_T_callContentLinkInformation);
return offset;
}
static int
dissect_HI2Operations_T_nature_Of_The_intercepted_call(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_initiator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_transfer_status(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_other_message(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_270(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_sMS_Contents(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_sMS_Contents_sequence, hf_index, ett_HI2Operations_T_sMS_Contents);
return offset;
}
static int
dissect_HI2Operations_SMS_report(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SMS_report_sequence, hf_index, ett_HI2Operations_SMS_report);
return offset;
}
static int
dissect_HI2Operations_CC_Link_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_National_Parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
National_Parameters_set_of, hf_index, ett_HI2Operations_National_Parameters);
return offset;
}
static int
dissect_HI2Operations_GPRSCorrelationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GPRSEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_GPRSOperationErrorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_UmtsQos(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UmtsQos_choice, hf_index, ett_HI2Operations_UmtsQos,
NULL);
return offset;
}
static int
dissect_HI2Operations_IMSevent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_1_20(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_OCTET_STRING_SIZE_5_17(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_LIIDType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_1_100(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_LocationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LocationType_choice, hf_index, ett_HI2Operations_LocationType,
NULL);
return offset;
}
static int
dissect_HI2Operations_DirectionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_IRITransactionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_ProtocolVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CaseId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_AccessingElementId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_EventTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_25_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_15_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CallId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallId_sequence, hf_index, ett_HI2Operations_CallId);
return offset;
}
static int
dissect_HI2Operations_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_32_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_48_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_PartyId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PartyId_sequence, hf_index, ett_HI2Operations_PartyId);
return offset;
}
static int
dissect_HI2Operations_Answer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Answer_sequence, hf_index, ett_HI2Operations_Answer);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_20_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_sepCCCpair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_sepCCCpair_sequence, hf_index, ett_HI2Operations_T_sepCCCpair);
return offset;
}
static int
dissect_HI2Operations_CCCId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CCCId_choice, hf_index, ett_HI2Operations_CCCId,
NULL);
return offset;
}
static int
dissect_HI2Operations_FlowDirection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CCClose(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CCClose_sequence, hf_index, ett_HI2Operations_CCClose);
return offset;
}
static int
dissect_HI2Operations_SEQUENCE_OF_CallId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CallId_sequence_of, hf_index, ett_HI2Operations_SEQUENCE_OF_CallId);
return offset;
}
static int
dissect_HI2Operations_T_ccOpenOption(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_ccOpenOption_choice, hf_index, ett_HI2Operations_T_ccOpenOption,
NULL);
return offset;
}
static int
dissect_HI2Operations_SDP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CCOpen(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CCOpen_sequence, hf_index, ett_HI2Operations_CCOpen);
return offset;
}
static int
dissect_HI2Operations_T_input(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_input_choice, hf_index, ett_HI2Operations_T_input,
NULL);
return offset;
}
static int
dissect_HI2Operations_TransitCarrierId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_Origination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Origination_sequence, hf_index, ett_HI2Operations_Origination);
return offset;
}
static int
dissect_HI2Operations_Redirection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Redirection_sequence, hf_index, ett_HI2Operations_Redirection);
return offset;
}
static int
dissect_HI2Operations_Release(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Release_sequence, hf_index, ett_HI2Operations_Release);
return offset;
}
static int
dissect_HI2Operations_INTEGER_1_100_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_RedirectedFromInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RedirectedFromInfo_sequence, hf_index, ett_HI2Operations_RedirectedFromInfo);
return offset;
}
static int
dissect_HI2Operations_TerminationAttempt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminationAttempt_sequence, hf_index, ett_HI2Operations_TerminationAttempt);
return offset;
}
static int
dissect_HI2Operations_ResourceState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_CCChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CCChange_sequence, hf_index, ett_HI2Operations_CCChange);
return offset;
}
static int
dissect_HI2Operations_AlertingSignal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_AudibleSignal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_80_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_40_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_TerminalDisplayInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminalDisplayInfo_sequence, hf_index, ett_HI2Operations_TerminalDisplayInfo);
return offset;
}
static int
dissect_HI2Operations_VisibleString_SIZE_1_128_(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_NetworkSignal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NetworkSignal_sequence, hf_index, ett_HI2Operations_NetworkSignal);
return offset;
}
static int
dissect_HI2Operations_T_signal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signal_sequence, hf_index, ett_HI2Operations_T_signal);
return offset;
}
static int
dissect_HI2Operations_SubjectSignal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubjectSignal_sequence, hf_index, ett_HI2Operations_SubjectSignal);
return offset;
}
static int
dissect_HI2Operations_MediaReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MediaReport_sequence, hf_index, ett_HI2Operations_MediaReport);
return offset;
}
static int
dissect_HI2Operations_ServiceInstance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceInstance_sequence, hf_index, ett_HI2Operations_ServiceInstance);
return offset;
}
static int
dissect_HI2Operations_Message(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Message_choice, hf_index, ett_HI2Operations_Message,
NULL);
return offset;
}
static int
dissect_HI2Operations_CdcPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CdcPdu_sequence, hf_index, ett_HI2Operations_CdcPdu);
return offset;
}
static int
dissect_HI2Operations_UserSignalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UserSignalType_choice, hf_index, ett_HI2Operations_UserSignalType,
NULL);
return offset;
}
static int
dissect_HI2Operations_TARGETACTIVITYMONITOR_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TARGETACTIVITYMONITOR_1_sequence, hf_index, ett_HI2Operations_TARGETACTIVITYMONITOR_1);
return offset;
}
static int
dissect_HI2Operations_LDIevent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_cc(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_cc_set_of, hf_index, ett_HI2Operations_T_cc);
return offset;
}
static int
dissect_HI2Operations_IRI_to_CC_Correlation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IRI_to_CC_Correlation_sequence, hf_index, ett_HI2Operations_IRI_to_CC_Correlation);
return offset;
}
static int
dissect_HI2Operations_IRI_to_IRI_Correlation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_both_IRI_CC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_both_IRI_CC_sequence, hf_index, ett_HI2Operations_T_both_IRI_CC);
return offset;
}
static int
dissect_HI2Operations_CorrelationValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CorrelationValues_choice, hf_index, ett_HI2Operations_CorrelationValues,
NULL);
return offset;
}
static int
dissect_HI2Operations_TLIIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_MCCType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_MNCType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_LocationAreaType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_CellIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_TETRACGIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TETRACGIType_sequence, hf_index, ett_HI2Operations_TETRACGIType);
return offset;
}
static int
dissect_HI2Operations_SSIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_TSIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TSIType_sequence, hf_index, ett_HI2Operations_TSIType);
return offset;
}
static int
dissect_HI2Operations_NumericString_SIZE_20(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_BIT_STRING_SIZE_32(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_BIT_STRING_SIZE_128(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_TEIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_HI2Operations_TETRAAddressType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TETRAAddressType_choice, hf_index, ett_HI2Operations_TETRAAddressType,
NULL);
return offset;
}
static int
dissect_HI2Operations_LocationType_en301040(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LocationType_en301040_choice, hf_index, ett_HI2Operations_LocationType_en301040,
NULL);
return offset;
}
static int
dissect_HI2Operations_ActivityClassType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_callRelation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_direction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_T_scope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_SSType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_ActivityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActivityType_sequence, hf_index, ett_HI2Operations_ActivityType);
return offset;
}
static int
dissect_HI2Operations_SEQUENCE_OF_TETRAAddressType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_TETRAAddressType_sequence_of, hf_index, ett_HI2Operations_SEQUENCE_OF_TETRAAddressType);
return offset;
}
static int
dissect_HI2Operations_AddressType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddressType_sequence, hf_index, ett_HI2Operations_AddressType);
return offset;
}
static int
dissect_HI2Operations_SEQUENCE_OF_AddressType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AddressType_sequence_of, hf_index, ett_HI2Operations_SEQUENCE_OF_AddressType);
return offset;
}
static int
dissect_HI2Operations_SEQUENCE_OF_LocationType_en301040(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_LocationType_en301040_sequence_of, hf_index, ett_HI2Operations_SEQUENCE_OF_LocationType_en301040);
return offset;
}
static int
dissect_HI2Operations_TARGETACTIVITYMONITORind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TARGETACTIVITYMONITORind_sequence, hf_index, ett_HI2Operations_TARGETACTIVITYMONITORind);
return offset;
}
static int
dissect_HI2Operations_CircuitIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_SEQUENCE_OF_CircuitIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CircuitIdType_sequence_of, hf_index, ett_HI2Operations_SEQUENCE_OF_CircuitIdType);
return offset;
}
static int
dissect_HI2Operations_TARGETCOMMSMONITORind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TARGETCOMMSMONITORind_sequence, hf_index, ett_HI2Operations_TARGETCOMMSMONITORind);
return offset;
}
static int
dissect_HI2Operations_TTRAFFICind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TTRAFFICind_sequence, hf_index, ett_HI2Operations_TTRAFFICind);
return offset;
}
static int
dissect_HI2Operations_CTTRAFFICind(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CTTRAFFICind_sequence, hf_index, ett_HI2Operations_CTTRAFFICind);
return offset;
}
static int
dissect_HI2Operations_PrintableString_SIZE_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_HI2Operations_National_HI2_ASN1parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
National_HI2_ASN1parameters_sequence, hf_index, ett_HI2Operations_National_HI2_ASN1parameters);
return offset;
}
static int
dissect_HI2Operations_IRI_Parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IRI_Parameters_sequence, hf_index, ett_HI2Operations_IRI_Parameters);
return offset;
}
static int
dissect_HI2Operations_IRIContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IRIContent_choice, hf_index, ett_HI2Operations_IRIContent,
NULL);
return offset;
}
static int
dissect_HI2Operations_IRISequence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
IRISequence_sequence_of, hf_index, ett_HI2Operations_IRISequence);
return offset;
}
static int
dissect_HI2Operations_IRIsContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IRIsContent_choice, hf_index, ett_HI2Operations_IRIsContent,
NULL);
return offset;
}
static int dissect_IRIsContent_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_HI2Operations_IRIsContent(FALSE, tvb, offset, &asn1_ctx, tree, hf_HI2Operations_IRIsContent_PDU);
return offset;
}
void proto_register_HI2Operations(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/HI2Operations/packet-HI2Operations-hfarr.c"
{ &hf_HI2Operations_IRIsContent_PDU,
{ "IRIsContent", "HI2Operations.IRIsContent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IRIsContent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iRIContent,
{ "iRIContent", "HI2Operations.iRIContent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IRIContent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iRISequence,
{ "iRISequence", "HI2Operations.iRISequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_IRISequence_item,
{ "IRIContent", "HI2Operations.IRIContent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IRIContent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iRI_Begin_record,
{ "iRI-Begin-record", "HI2Operations.iRI_Begin_record_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_Parameters", HFILL }},
{ &hf_HI2Operations_iRI_End_record,
{ "iRI-End-record", "HI2Operations.iRI_End_record_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_Parameters", HFILL }},
{ &hf_HI2Operations_iRI_Continue_record,
{ "iRI-Continue-record", "HI2Operations.iRI_Continue_record_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_Parameters", HFILL }},
{ &hf_HI2Operations_iRI_Report_record,
{ "iRI-Report-record", "HI2Operations.iRI_Report_record_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_Parameters", HFILL }},
{ &hf_HI2Operations_domainID,
{ "domainID", "HI2Operations.domainID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_HI2Operations_iRIversion,
{ "iRIversion", "HI2Operations.iRIversion",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_iRIversion_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_lawfulInterceptionIdentifier,
{ "lawfulInterceptionIdentifier", "HI2Operations.lawfulInterceptionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_communicationIdentifier,
{ "communicationIdentifier", "HI2Operations.communicationIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_timeStamp,
{ "timeStamp", "HI2Operations.timeStamp",
FT_UINT32, BASE_DEC, VALS(HI2Operations_TimeStamp_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_intercepted_Call_Direct,
{ "intercepted-Call-Direct", "HI2Operations.intercepted_Call_Direct",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_intercepted_Call_Direct_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_intercepted_Call_State,
{ "intercepted-Call-State", "HI2Operations.intercepted_Call_State",
FT_UINT32, BASE_DEC, VALS(HI2Operations_Intercepted_Call_State_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_ringingDuration,
{ "ringingDuration", "HI2Operations.ringingDuration",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_HI2Operations_conversationDuration,
{ "conversationDuration", "HI2Operations.conversationDuration",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_HI2Operations_locationOfTheTarget,
{ "locationOfTheTarget", "HI2Operations.locationOfTheTarget_element",
FT_NONE, BASE_NONE, NULL, 0,
"Location", HFILL }},
{ &hf_HI2Operations_partyInformation,
{ "partyInformation", "HI2Operations.partyInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_10_OF_PartyInformation", HFILL }},
{ &hf_HI2Operations_partyInformation_item,
{ "PartyInformation", "HI2Operations.PartyInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_callContentLinkInformation,
{ "callContentLinkInformation", "HI2Operations.callContentLinkInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_cCLink1Characteristics,
{ "cCLink1Characteristics", "HI2Operations.cCLink1Characteristics_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallContentLinkCharacteristics", HFILL }},
{ &hf_HI2Operations_cCLink2Characteristics,
{ "cCLink2Characteristics", "HI2Operations.cCLink2Characteristics_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallContentLinkCharacteristics", HFILL }},
{ &hf_HI2Operations_release_Reason_Of_Intercepted_Call,
{ "release-Reason-Of-Intercepted-Call", "HI2Operations.release_Reason_Of_Intercepted_Call",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_HI2Operations_nature_Of_The_intercepted_call,
{ "nature-Of-The-intercepted-call", "HI2Operations.nature_Of_The_intercepted_call",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_nature_Of_The_intercepted_call_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_serverCenterAddress,
{ "serverCenterAddress", "HI2Operations.serverCenterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyInformation", HFILL }},
{ &hf_HI2Operations_sMS,
{ "sMS", "HI2Operations.sMS_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMS_report", HFILL }},
{ &hf_HI2Operations_cC_Link_Identifier,
{ "cC-Link-Identifier", "HI2Operations.cC_Link_Identifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_national_Parameters,
{ "national-Parameters", "HI2Operations.national_Parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_gPRSCorrelationNumber,
{ "gPRSCorrelationNumber", "HI2Operations.gPRSCorrelationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_gPRSevent,
{ "gPRSevent", "HI2Operations.gPRSevent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_GPRSEvent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_sgsnAddress,
{ "sgsnAddress", "HI2Operations.sgsnAddress",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DataNodeAddress_vals), 0,
"DataNodeAddress", HFILL }},
{ &hf_HI2Operations_gPRSOperationErrorCode,
{ "gPRSOperationErrorCode", "HI2Operations.gPRSOperationErrorCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ggsnAddress,
{ "ggsnAddress", "HI2Operations.ggsnAddress",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DataNodeAddress_vals), 0,
"DataNodeAddress", HFILL }},
{ &hf_HI2Operations_qOS,
{ "qOS", "HI2Operations.qOS",
FT_UINT32, BASE_DEC, VALS(HI2Operations_UmtsQos_vals), 0,
"UmtsQos", HFILL }},
{ &hf_HI2Operations_networkIdentifier,
{ "networkIdentifier", "HI2Operations.networkIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"Network_Identifier", HFILL }},
{ &hf_HI2Operations_sMSOriginatingAddress,
{ "sMSOriginatingAddress", "HI2Operations.sMSOriginatingAddress",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DataNodeAddress_vals), 0,
"DataNodeAddress", HFILL }},
{ &hf_HI2Operations_sMSTerminatingAddress,
{ "sMSTerminatingAddress", "HI2Operations.sMSTerminatingAddress",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DataNodeAddress_vals), 0,
"DataNodeAddress", HFILL }},
{ &hf_HI2Operations_iMSevent,
{ "iMSevent", "HI2Operations.iMSevent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IMSevent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_sIPMessage,
{ "sIPMessage", "HI2Operations.sIPMessage",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_servingSGSN_number,
{ "servingSGSN-number", "HI2Operations.servingSGSN_number",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_20", HFILL }},
{ &hf_HI2Operations_servingSGSN_address,
{ "servingSGSN-address", "HI2Operations.servingSGSN_address",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_5_17", HFILL }},
{ &hf_HI2Operations_tARGETACTIVITYMONITOR,
{ "tARGETACTIVITYMONITOR", "HI2Operations.tARGETACTIVITYMONITOR_element",
FT_NONE, BASE_NONE, NULL, 0,
"TARGETACTIVITYMONITOR_1", HFILL }},
{ &hf_HI2Operations_ldiEvent,
{ "ldiEvent", "HI2Operations.ldiEvent",
FT_UINT32, BASE_DEC, VALS(HI2Operations_LDIevent_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_correlation,
{ "correlation", "HI2Operations.correlation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CorrelationValues_vals), 0,
"CorrelationValues", HFILL }},
{ &hf_HI2Operations_tARGETACTIVITYMONITORind,
{ "tARGETACTIVITYMONITORind", "HI2Operations.tARGETACTIVITYMONITORind_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_tARGETCOMMSMONITORind,
{ "tARGETCOMMSMONITORind", "HI2Operations.tARGETCOMMSMONITORind_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_tTRAFFICind,
{ "tTRAFFICind", "HI2Operations.tTRAFFICind_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_cTTRAFFICind,
{ "cTTRAFFICind", "HI2Operations.cTTRAFFICind_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_national_HI2_ASN1parameters,
{ "national-HI2-ASN1parameters", "HI2Operations.national_HI2_ASN1parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_communication_Identity_Number,
{ "communication-Identity-Number", "HI2Operations.communication_Identity_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_8", HFILL }},
{ &hf_HI2Operations_network_Identifier,
{ "network-Identifier", "HI2Operations.network_Identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_operator_Identifier,
{ "operator-Identifier", "HI2Operations.operator_Identifier",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_5", HFILL }},
{ &hf_HI2Operations_network_Element_Identifier,
{ "network-Element-Identifier", "HI2Operations.network_Element_Identifier",
FT_UINT32, BASE_DEC, VALS(HI2Operations_Network_Element_Identifier_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_e164_Format,
{ "e164-Format", "HI2Operations.e164_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_x25_Format,
{ "x25-Format", "HI2Operations.x25_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_iP_Format,
{ "iP-Format", "HI2Operations.iP_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_dNS_Format,
{ "dNS-Format", "HI2Operations.dNS_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_iP_Address,
{ "iP-Address", "HI2Operations.iP_Address_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_HI2Operations_localTime,
{ "localTime", "HI2Operations.localTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LocalTimeStamp", HFILL }},
{ &hf_HI2Operations_utcTime,
{ "utcTime", "HI2Operations.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_generalizedTime,
{ "generalizedTime", "HI2Operations.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_winterSummerIndication,
{ "winterSummerIndication", "HI2Operations.winterSummerIndication",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_winterSummerIndication_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_party_Qualifier,
{ "party-Qualifier", "HI2Operations.party_Qualifier",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_party_Qualifier_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_partyIdentity,
{ "partyIdentity", "HI2Operations.partyIdentity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_imei,
{ "imei", "HI2Operations.imei",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_HI2Operations_tei,
{ "tei", "HI2Operations.tei",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_15", HFILL }},
{ &hf_HI2Operations_imsi,
{ "imsi", "HI2Operations.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3_8", HFILL }},
{ &hf_HI2Operations_callingPartyNumber,
{ "callingPartyNumber", "HI2Operations.callingPartyNumber",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CallingPartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_calledPartyNumber,
{ "calledPartyNumber", "HI2Operations.calledPartyNumber",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CalledPartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_msISDN,
{ "msISDN", "HI2Operations.msISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_9", HFILL }},
{ &hf_HI2Operations_sip_uri,
{ "sip-uri", "HI2Operations.sip_uri",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_tel_url,
{ "tel-url", "HI2Operations.tel_url",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_services_Information,
{ "services-Information", "HI2Operations.services_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_supplementary_Services_Information,
{ "supplementary-Services-Information", "HI2Operations.supplementary_Services_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
"Supplementary_Services", HFILL }},
{ &hf_HI2Operations_services_Data_Information,
{ "services-Data-Information", "HI2Operations.services_Data_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_iSUP_Format,
{ "iSUP-Format", "HI2Operations.iSUP_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_dSS1_Format,
{ "dSS1-Format", "HI2Operations.dSS1_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_mAP_Format,
{ "mAP-Format", "HI2Operations.mAP_Format",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_e164_Number,
{ "e164-Number", "HI2Operations.e164_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_25", HFILL }},
{ &hf_HI2Operations_globalCellID,
{ "globalCellID", "HI2Operations.globalCellID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_5_7", HFILL }},
{ &hf_HI2Operations_tetraLocation,
{ "tetraLocation", "HI2Operations.tetraLocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_TetraLocation_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_rAI,
{ "rAI", "HI2Operations.rAI",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_6", HFILL }},
{ &hf_HI2Operations_gsmLocation,
{ "gsmLocation", "HI2Operations.gsmLocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_GSMLocation_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_umtsLocation,
{ "umtsLocation", "HI2Operations.umtsLocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_UMTSLocation_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_sAI,
{ "sAI", "HI2Operations.sAI",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_7", HFILL }},
{ &hf_HI2Operations_oldRAI,
{ "oldRAI", "HI2Operations.oldRAI",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_6", HFILL }},
{ &hf_HI2Operations_ms_Loc,
{ "ms-Loc", "HI2Operations.ms_Loc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_mcc,
{ "mcc", "HI2Operations.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_HI2Operations_mnc,
{ "mnc", "HI2Operations.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_HI2Operations_lai,
{ "lai", "HI2Operations.lai",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_HI2Operations_ci,
{ "ci", "HI2Operations.ci",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_HI2Operations_ls_Loc,
{ "ls-Loc", "HI2Operations.ls_Loc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_HI2Operations_geoCoordinates,
{ "geoCoordinates", "HI2Operations.geoCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_latitude,
{ "latitude", "HI2Operations.latitude",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_7_10", HFILL }},
{ &hf_HI2Operations_longitude,
{ "longitude", "HI2Operations.longitude",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_8_11", HFILL }},
{ &hf_HI2Operations_mapDatum,
{ "mapDatum", "HI2Operations.mapDatum",
FT_UINT32, BASE_DEC, VALS(HI2Operations_MapDatum_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_azimuth,
{ "azimuth", "HI2Operations.azimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_HI2Operations_utmCoordinates,
{ "utmCoordinates", "HI2Operations.utmCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_utm_East,
{ "utm-East", "HI2Operations.utm_East",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_10", HFILL }},
{ &hf_HI2Operations_utm_North,
{ "utm-North", "HI2Operations.utm_North",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_7", HFILL }},
{ &hf_HI2Operations_utmRefCoordinates,
{ "utmRefCoordinates", "HI2Operations.utmRefCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_utmref_string,
{ "utmref-string", "HI2Operations.utmref_string",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_13", HFILL }},
{ &hf_HI2Operations_wGS84Coordinates,
{ "wGS84Coordinates", "HI2Operations.wGS84Coordinates",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_point,
{ "point", "HI2Operations.point_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_Point", HFILL }},
{ &hf_HI2Operations_pointWithUnCertainty,
{ "pointWithUnCertainty", "HI2Operations.pointWithUnCertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_PointWithUnCertainty", HFILL }},
{ &hf_HI2Operations_polygon,
{ "polygon", "HI2Operations.polygon",
FT_UINT32, BASE_DEC, NULL, 0,
"GA_Polygon", HFILL }},
{ &hf_HI2Operations_latitudeSign,
{ "latitudeSign", "HI2Operations.latitudeSign",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_latitude_01,
{ "latitude", "HI2Operations.latitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_HI2Operations_longitude_01,
{ "longitude", "HI2Operations.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_HI2Operations_geographicalCoordinates,
{ "geographicalCoordinates", "HI2Operations.geographicalCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_uncertaintyCode,
{ "uncertaintyCode", "HI2Operations.uncertaintyCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_HI2Operations_GA_Polygon_item,
{ "GA-Polygon item", "HI2Operations.GA_Polygon_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_cCLink_State,
{ "cCLink-State", "HI2Operations.cCLink_State",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CCLink_State_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_release_Time,
{ "release-Time", "HI2Operations.release_Time",
FT_UINT32, BASE_DEC, VALS(HI2Operations_TimeStamp_vals), 0,
"TimeStamp", HFILL }},
{ &hf_HI2Operations_release_Reason,
{ "release-Reason", "HI2Operations.release_Reason",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_HI2Operations_lEMF_Address,
{ "lEMF-Address", "HI2Operations.lEMF_Address",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CalledPartyNumber_vals), 0,
"CalledPartyNumber", HFILL }},
{ &hf_HI2Operations_iSUP_parameters,
{ "iSUP-parameters", "HI2Operations.iSUP_parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_parameters_codeset_0,
{ "dSS1-parameters-codeset-0", "HI2Operations.dSS1_parameters_codeset_0",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_mAP_parameters,
{ "mAP-parameters", "HI2Operations.mAP_parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ISUP_parameters_item,
{ "ISUP-parameters item", "HI2Operations.ISUP_parameters_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_parameters_codeset_0_item,
{ "DSS1-parameters-codeset-0 item", "HI2Operations.DSS1_parameters_codeset_0_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_MAP_parameters_item,
{ "MAP-parameters item", "HI2Operations.MAP_parameters_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_standard_Supplementary_Services,
{ "standard-Supplementary-Services", "HI2Operations.standard_Supplementary_Services_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_non_Standard_Supplementary_Services,
{ "non-Standard-Supplementary-Services", "HI2Operations.non_Standard_Supplementary_Services",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_other_Services,
{ "other-Services", "HI2Operations.other_Services",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_iSUP_SS_parameters,
{ "iSUP-SS-parameters", "HI2Operations.iSUP_SS_parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_parameters_codeset_0,
{ "dSS1-SS-parameters-codeset-0", "HI2Operations.dSS1_SS_parameters_codeset_0",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_parameters_codeset_4,
{ "dSS1-SS-parameters-codeset-4", "HI2Operations.dSS1_SS_parameters_codeset_4",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_parameters_codeset_5,
{ "dSS1-SS-parameters-codeset-5", "HI2Operations.dSS1_SS_parameters_codeset_5",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_parameters_codeset_6,
{ "dSS1-SS-parameters-codeset-6", "HI2Operations.dSS1_SS_parameters_codeset_6",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_parameters_codeset_7,
{ "dSS1-SS-parameters-codeset-7", "HI2Operations.dSS1_SS_parameters_codeset_7",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_dSS1_SS_Invoke_components,
{ "dSS1-SS-Invoke-components", "HI2Operations.dSS1_SS_Invoke_components",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_mAP_SS_Parameters,
{ "mAP-SS-Parameters", "HI2Operations.mAP_SS_Parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_mAP_SS_Invoke_Components,
{ "mAP-SS-Invoke-Components", "HI2Operations.mAP_SS_Invoke_Components",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_Non_Standard_Supplementary_Services_item,
{ "Non-Standard-Supplementary-Services item", "HI2Operations.Non_Standard_Supplementary_Services_item",
FT_UINT32, BASE_DEC, VALS(HI2Operations_Non_Standard_Supplementary_Services_item_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_simpleIndication,
{ "simpleIndication", "HI2Operations.simpleIndication",
FT_UINT32, BASE_DEC, VALS(HI2Operations_SimpleIndication_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_sciData,
{ "sciData", "HI2Operations.sciData",
FT_BYTES, BASE_NONE, NULL, 0,
"SciDataMode", HFILL }},
{ &hf_HI2Operations_Other_Services_item,
{ "Other-Services item", "HI2Operations.Other_Services_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_ISUP_SS_parameters_item,
{ "ISUP-SS-parameters item", "HI2Operations.ISUP_SS_parameters_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_parameters_codeset_0_item,
{ "DSS1-SS-parameters-codeset-0 item", "HI2Operations.DSS1_SS_parameters_codeset_0_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_parameters_codeset_4_item,
{ "DSS1-SS-parameters-codeset-4 item", "HI2Operations.DSS1_SS_parameters_codeset_4_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_parameters_codeset_5_item,
{ "DSS1-SS-parameters-codeset-5 item", "HI2Operations.DSS1_SS_parameters_codeset_5_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_parameters_codeset_6_item,
{ "DSS1-SS-parameters-codeset-6 item", "HI2Operations.DSS1_SS_parameters_codeset_6_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_parameters_codeset_7_item,
{ "DSS1-SS-parameters-codeset-7 item", "HI2Operations.DSS1_SS_parameters_codeset_7_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_DSS1_SS_Invoke_Components_item,
{ "DSS1-SS-Invoke-Components item", "HI2Operations.DSS1_SS_Invoke_Components_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_MAP_SS_Invoke_Components_item,
{ "MAP-SS-Invoke-Components item", "HI2Operations.MAP_SS_Invoke_Components_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_MAP_SS_Parameters_item,
{ "MAP-SS-Parameters item", "HI2Operations.MAP_SS_Parameters_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_sMS_Contents,
{ "sMS-Contents", "HI2Operations.sMS_Contents_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_initiator,
{ "initiator", "HI2Operations.initiator",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_initiator_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_transfer_status,
{ "transfer-status", "HI2Operations.transfer_status",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_transfer_status_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_other_message,
{ "other-message", "HI2Operations.other_message",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_other_message_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_content,
{ "content", "HI2Operations.content",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_270", HFILL }},
{ &hf_HI2Operations_National_Parameters_item,
{ "National-Parameters item", "HI2Operations.National_Parameters_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_HI2Operations_gPRS_parameters,
{ "gPRS-parameters", "HI2Operations.gPRS_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_pDP_address_allocated_to_the_target,
{ "pDP-address-allocated-to-the-target", "HI2Operations.pDP_address_allocated_to_the_target",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DataNodeAddress_vals), 0,
"DataNodeAddress", HFILL }},
{ &hf_HI2Operations_aPN,
{ "aPN", "HI2Operations.aPN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_100", HFILL }},
{ &hf_HI2Operations_pDP_type,
{ "pDP-type", "HI2Operations.pDP_type",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_HI2Operations_ipAddress,
{ "ipAddress", "HI2Operations.ipAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_x25Address,
{ "x25Address", "HI2Operations.x25Address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_iP_type,
{ "iP-type", "HI2Operations.iP_type",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_iP_type_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iP_value,
{ "iP-value", "HI2Operations.iP_value",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IP_value_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iP_assignment,
{ "iP-assignment", "HI2Operations.iP_assignment",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_iP_assignment_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_iPBinaryAddress,
{ "iPBinaryAddress", "HI2Operations.iPBinaryAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4_16", HFILL }},
{ &hf_HI2Operations_iPTextAddress,
{ "iPTextAddress", "HI2Operations.iPTextAddress",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_7_45", HFILL }},
{ &hf_HI2Operations_countryCode,
{ "countryCode", "HI2Operations.countryCode",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_2", HFILL }},
{ &hf_HI2Operations_qosMobileRadio,
{ "qosMobileRadio", "HI2Operations.qosMobileRadio",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_qosGn,
{ "qosGn", "HI2Operations.qosGn",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_iri_to_CC,
{ "iri-to-CC", "HI2Operations.iri_to_CC_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_to_CC_Correlation", HFILL }},
{ &hf_HI2Operations_iri_to_iri,
{ "iri-to-iri", "HI2Operations.iri_to_iri",
FT_BYTES, BASE_NONE, NULL, 0,
"IRI_to_IRI_Correlation", HFILL }},
{ &hf_HI2Operations_both_IRI_CC,
{ "both-IRI-CC", "HI2Operations.both_IRI_CC_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_iri_CC,
{ "iri-CC", "HI2Operations.iri_CC_element",
FT_NONE, BASE_NONE, NULL, 0,
"IRI_to_CC_Correlation", HFILL }},
{ &hf_HI2Operations_iri_IRI,
{ "iri-IRI", "HI2Operations.iri_IRI",
FT_BYTES, BASE_NONE, NULL, 0,
"IRI_to_IRI_Correlation", HFILL }},
{ &hf_HI2Operations_cc,
{ "cc", "HI2Operations.cc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_cc_item,
{ "cc item", "HI2Operations.cc_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_iri,
{ "iri", "HI2Operations.iri",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_HI2Operations_version,
{ "version", "HI2Operations.version",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_HI2Operations_lIInstanceid,
{ "lIInstanceid", "HI2Operations.lIInstanceid",
FT_UINT32, BASE_DEC, NULL, 0,
"LIIDType", HFILL }},
{ &hf_HI2Operations_timestamp,
{ "timestamp", "HI2Operations.timestamp",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_HI2Operations_targetLocation,
{ "targetLocation", "HI2Operations.targetLocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_LocationType_vals), 0,
"LocationType", HFILL }},
{ &hf_HI2Operations_direction,
{ "direction", "HI2Operations.direction",
FT_UINT32, BASE_DEC, VALS(HI2Operations_DirectionType_vals), 0,
"DirectionType", HFILL }},
{ &hf_HI2Operations_iRITransaction,
{ "iRITransaction", "HI2Operations.iRITransaction",
FT_UINT32, BASE_DEC, VALS(HI2Operations_IRITransactionType_vals), 0,
"IRITransactionType", HFILL }},
{ &hf_HI2Operations_iRITransactionNumber,
{ "iRITransactionNumber", "HI2Operations.iRITransactionNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_HI2Operations_userSignal,
{ "userSignal", "HI2Operations.userSignal",
FT_UINT32, BASE_DEC, VALS(HI2Operations_UserSignalType_vals), 0,
"UserSignalType", HFILL }},
{ &hf_HI2Operations_cryptoCheckSum,
{ "cryptoCheckSum", "HI2Operations.cryptoCheckSum",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_HI2Operations_copySignal,
{ "copySignal", "HI2Operations.copySignal",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_HI2Operations_interpretedSignal,
{ "interpretedSignal", "HI2Operations.interpretedSignal",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_HI2Operations_cdcPdu,
{ "cdcPdu", "HI2Operations.cdcPdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_geodeticData,
{ "geodeticData", "HI2Operations.geodeticData",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_HI2Operations_nameAddress,
{ "nameAddress", "HI2Operations.nameAddress",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_1_100", HFILL }},
{ &hf_HI2Operations_protocolVersion,
{ "protocolVersion", "HI2Operations.protocolVersion",
FT_UINT32, BASE_DEC, VALS(HI2Operations_ProtocolVersion_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_message,
{ "message", "HI2Operations.message",
FT_UINT32, BASE_DEC, VALS(HI2Operations_Message_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_answer,
{ "answer", "HI2Operations.answer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ccclose,
{ "ccclose", "HI2Operations.ccclose_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ccopen,
{ "ccopen", "HI2Operations.ccopen_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved0,
{ "reserved0", "HI2Operations.reserved0_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_origination,
{ "origination", "HI2Operations.origination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved1,
{ "reserved1", "HI2Operations.reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_redirection,
{ "redirection", "HI2Operations.redirection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_release,
{ "release", "HI2Operations.release_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved2,
{ "reserved2", "HI2Operations.reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_terminationattempt,
{ "terminationattempt", "HI2Operations.terminationattempt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved,
{ "reserved", "HI2Operations.reserved_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ccchange,
{ "ccchange", "HI2Operations.ccchange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved3,
{ "reserved3", "HI2Operations.reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved4,
{ "reserved4", "HI2Operations.reserved4_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved5,
{ "reserved5", "HI2Operations.reserved5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_networksignal,
{ "networksignal", "HI2Operations.networksignal_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_subjectsignal,
{ "subjectsignal", "HI2Operations.subjectsignal_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_mediareport,
{ "mediareport", "HI2Operations.mediareport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_serviceinstance,
{ "serviceinstance", "HI2Operations.serviceinstance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_caseId,
{ "caseId", "HI2Operations.caseId",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_accessingElementId,
{ "accessingElementId", "HI2Operations.accessingElementId",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_eventTime,
{ "eventTime", "HI2Operations.eventTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_callId,
{ "callId", "HI2Operations.callId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_answering,
{ "answering", "HI2Operations.answering_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_cCCId,
{ "cCCId", "HI2Operations.cCCId",
FT_UINT32, BASE_DEC, VALS(HI2Operations_CCCId_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_subject,
{ "subject", "HI2Operations.subject",
FT_STRING, BASE_NONE, NULL, 0,
"SDP", HFILL }},
{ &hf_HI2Operations_associate,
{ "associate", "HI2Operations.associate",
FT_STRING, BASE_NONE, NULL, 0,
"SDP", HFILL }},
{ &hf_HI2Operations_flowDirection,
{ "flowDirection", "HI2Operations.flowDirection",
FT_UINT32, BASE_DEC, VALS(HI2Operations_FlowDirection_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_resourceState,
{ "resourceState", "HI2Operations.resourceState",
FT_UINT32, BASE_DEC, VALS(HI2Operations_ResourceState_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_ccOpenOption,
{ "ccOpenOption", "HI2Operations.ccOpenOption",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_ccOpenOption_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_ccOpenTime,
{ "ccOpenTime", "HI2Operations.ccOpenTime",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CallId", HFILL }},
{ &hf_HI2Operations_ccOpenTime_item,
{ "CallId", "HI2Operations.CallId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_alertingSignal,
{ "alertingSignal", "HI2Operations.alertingSignal",
FT_UINT32, BASE_DEC, VALS(HI2Operations_AlertingSignal_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_subjectAudibleSignal,
{ "subjectAudibleSignal", "HI2Operations.subjectAudibleSignal",
FT_UINT32, BASE_DEC, VALS(HI2Operations_AudibleSignal_vals), 0,
"AudibleSignal", HFILL }},
{ &hf_HI2Operations_terminalDisplayInfo,
{ "terminalDisplayInfo", "HI2Operations.terminalDisplayInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_other,
{ "other", "HI2Operations.other",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_calling,
{ "calling", "HI2Operations.calling_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_called,
{ "called", "HI2Operations.called_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_input,
{ "input", "HI2Operations.input",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_input_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_userinput,
{ "userinput", "HI2Operations.userinput",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_translationinput,
{ "translationinput", "HI2Operations.translationinput",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_transitCarrierId,
{ "transitCarrierId", "HI2Operations.transitCarrierId",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_old,
{ "old", "HI2Operations.old_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallId", HFILL }},
{ &hf_HI2Operations_redirectedto,
{ "redirectedto", "HI2Operations.redirectedto_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_new,
{ "new", "HI2Operations.new_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallId", HFILL }},
{ &hf_HI2Operations_redirectedfrom,
{ "redirectedfrom", "HI2Operations.redirectedfrom_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_relatedCallId,
{ "relatedCallId", "HI2Operations.relatedCallId_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallId", HFILL }},
{ &hf_HI2Operations_serviceName,
{ "serviceName", "HI2Operations.serviceName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_firstCallCalling,
{ "firstCallCalling", "HI2Operations.firstCallCalling_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_secondCallCalling,
{ "secondCallCalling", "HI2Operations.secondCallCalling_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_signal,
{ "signal", "HI2Operations.signal_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_switchhookFlash,
{ "switchhookFlash", "HI2Operations.switchhookFlash",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_dialedDigits,
{ "dialedDigits", "HI2Operations.dialedDigits",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_featureKey,
{ "featureKey", "HI2Operations.featureKey",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_otherSignalingInformation,
{ "otherSignalingInformation", "HI2Operations.otherSignalingInformation",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_128_", HFILL }},
{ &hf_HI2Operations_redirectedFromInfo,
{ "redirectedFromInfo", "HI2Operations.redirectedFromInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_sequencenumber,
{ "sequencenumber", "HI2Operations.sequencenumber",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_25_", HFILL }},
{ &hf_HI2Operations_systemidentity,
{ "systemidentity", "HI2Operations.systemidentity",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_15_", HFILL }},
{ &hf_HI2Operations_combCCC,
{ "combCCC", "HI2Operations.combCCC",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_20_", HFILL }},
{ &hf_HI2Operations_sepCCCpair,
{ "sepCCCpair", "HI2Operations.sepCCCpair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_sepXmitCCC,
{ "sepXmitCCC", "HI2Operations.sepXmitCCC",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_20_", HFILL }},
{ &hf_HI2Operations_sepRecvCCC,
{ "sepRecvCCC", "HI2Operations.sepRecvCCC",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_20_", HFILL }},
{ &hf_HI2Operations_dn,
{ "dn", "HI2Operations.dn",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_15_", HFILL }},
{ &hf_HI2Operations_userProvided,
{ "userProvided", "HI2Operations.userProvided",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_15_", HFILL }},
{ &hf_HI2Operations_reserved6,
{ "reserved6", "HI2Operations.reserved6_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_reserved7,
{ "reserved7", "HI2Operations.reserved7_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_ipAddress_01,
{ "ipAddress", "HI2Operations.ipAddress",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_reserved8,
{ "reserved8", "HI2Operations.reserved8_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_trunkId,
{ "trunkId", "HI2Operations.trunkId",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_reserved9,
{ "reserved9", "HI2Operations.reserved9_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_genericAddress,
{ "genericAddress", "HI2Operations.genericAddress",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_genericDigits,
{ "genericDigits", "HI2Operations.genericDigits",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_genericName,
{ "genericName", "HI2Operations.genericName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_48_", HFILL }},
{ &hf_HI2Operations_port,
{ "port", "HI2Operations.port",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_context,
{ "context", "HI2Operations.context",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_32_", HFILL }},
{ &hf_HI2Operations_lastRedirecting,
{ "lastRedirecting", "HI2Operations.lastRedirecting_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_originalCalled,
{ "originalCalled", "HI2Operations.originalCalled_element",
FT_NONE, BASE_NONE, NULL, 0,
"PartyId", HFILL }},
{ &hf_HI2Operations_numRedirections,
{ "numRedirections", "HI2Operations.numRedirections",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100_", HFILL }},
{ &hf_HI2Operations_generalDisplay,
{ "generalDisplay", "HI2Operations.generalDisplay",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_80_", HFILL }},
{ &hf_HI2Operations_calledNumber,
{ "calledNumber", "HI2Operations.calledNumber",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_callingNumber,
{ "callingNumber", "HI2Operations.callingNumber",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_callingName,
{ "callingName", "HI2Operations.callingName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_originalCalledNumber,
{ "originalCalledNumber", "HI2Operations.originalCalledNumber",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_lastRedirectingNumber,
{ "lastRedirectingNumber", "HI2Operations.lastRedirectingNumber",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_redirectingName,
{ "redirectingName", "HI2Operations.redirectingName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_redirectingReason,
{ "redirectingReason", "HI2Operations.redirectingReason",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_messageWaitingNotif,
{ "messageWaitingNotif", "HI2Operations.messageWaitingNotif",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_40_", HFILL }},
{ &hf_HI2Operations_tLIInstanceid,
{ "tLIInstanceid", "HI2Operations.tLIInstanceid",
FT_BYTES, BASE_NONE, NULL, 0,
"TLIIdType", HFILL }},
{ &hf_HI2Operations_targetLocation_01,
{ "targetLocation", "HI2Operations.targetLocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_LocationType_en301040_vals), 0,
"LocationType_en301040", HFILL }},
{ &hf_HI2Operations_targetAction,
{ "targetAction", "HI2Operations.targetAction_element",
FT_NONE, BASE_NONE, NULL, 0,
"ActivityType", HFILL }},
{ &hf_HI2Operations_supplementaryTargetaddress,
{ "supplementaryTargetaddress", "HI2Operations.supplementaryTargetaddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddressType", HFILL }},
{ &hf_HI2Operations_cotargetaddress,
{ "cotargetaddress", "HI2Operations.cotargetaddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AddressType", HFILL }},
{ &hf_HI2Operations_cotargetaddress_item,
{ "AddressType", "HI2Operations.AddressType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_cotargetlocation,
{ "cotargetlocation", "HI2Operations.cotargetlocation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_LocationType_en301040", HFILL }},
{ &hf_HI2Operations_cotargetlocation_item,
{ "LocationType-en301040", "HI2Operations.LocationType_en301040",
FT_UINT32, BASE_DEC, VALS(HI2Operations_LocationType_en301040_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_targetlocation,
{ "targetlocation", "HI2Operations.targetlocation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_LocationType_en301040_vals), 0,
"LocationType_en301040", HFILL }},
{ &hf_HI2Operations_targetcommsid,
{ "targetcommsid", "HI2Operations.targetcommsid",
FT_STRING, BASE_NONE, NULL, 0,
"CircuitIdType", HFILL }},
{ &hf_HI2Operations_cotargetcommsid,
{ "cotargetcommsid", "HI2Operations.cotargetcommsid",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CircuitIdType", HFILL }},
{ &hf_HI2Operations_cotargetcommsid_item,
{ "CircuitIdType", "HI2Operations.CircuitIdType",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_HI2Operations_trafficPacket,
{ "trafficPacket", "HI2Operations.trafficPacket",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_HI2Operations_cctivity,
{ "cctivity", "HI2Operations.cctivity",
FT_UINT32, BASE_DEC, VALS(HI2Operations_ActivityClassType_vals), 0,
"ActivityClassType", HFILL }},
{ &hf_HI2Operations_callRelation,
{ "callRelation", "HI2Operations.callRelation",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_callRelation_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_direction_01,
{ "direction", "HI2Operations.direction",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_direction_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_scope,
{ "scope", "HI2Operations.scope",
FT_UINT32, BASE_DEC, VALS(HI2Operations_T_scope_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_cPlaneData,
{ "cPlaneData", "HI2Operations.cPlaneData",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_HI2Operations_sStype,
{ "sStype", "HI2Operations.sStype",
FT_UINT32, BASE_DEC, VALS(HI2Operations_SSType_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_tSI,
{ "tSI", "HI2Operations.tSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"TSIType", HFILL }},
{ &hf_HI2Operations_supplementaryAddress,
{ "supplementaryAddress", "HI2Operations.supplementaryAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TETRAAddressType", HFILL }},
{ &hf_HI2Operations_supplementaryAddress_item,
{ "TETRAAddressType", "HI2Operations.TETRAAddressType",
FT_UINT32, BASE_DEC, VALS(HI2Operations_TETRAAddressType_vals), 0,
NULL, HFILL }},
{ &hf_HI2Operations_tETRAaddress,
{ "tETRAaddress", "HI2Operations.tETRAaddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"TSIType", HFILL }},
{ &hf_HI2Operations_pISNaddress,
{ "pISNaddress", "HI2Operations.pISNaddress",
FT_STRING, BASE_NONE, NULL, 0,
"NumericString_SIZE_20", HFILL }},
{ &hf_HI2Operations_iP4address,
{ "iP4address", "HI2Operations.iP4address",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_HI2Operations_iP6address,
{ "iP6address", "HI2Operations.iP6address",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_HI2Operations_e164address,
{ "e164address", "HI2Operations.e164address",
FT_STRING, BASE_NONE, NULL, 0,
"NumericString_SIZE_20", HFILL }},
{ &hf_HI2Operations_tEI,
{ "tEI", "HI2Operations.tEI",
FT_BYTES, BASE_NONE, NULL, 0,
"TEIType", HFILL }},
{ &hf_HI2Operations_mSLoc,
{ "mSLoc", "HI2Operations.mSLoc_element",
FT_NONE, BASE_NONE, NULL, 0,
"TETRACGIType", HFILL }},
{ &hf_HI2Operations_lSLoc,
{ "lSLoc", "HI2Operations.lSLoc",
FT_UINT32, BASE_DEC, VALS(HI2Operations_TETRAAddressType_vals), 0,
"TETRAAddressType", HFILL }},
{ &hf_HI2Operations_mcc_01,
{ "mcc", "HI2Operations.mcc",
FT_BYTES, BASE_NONE, NULL, 0,
"MCCType", HFILL }},
{ &hf_HI2Operations_mnc_01,
{ "mnc", "HI2Operations.mnc",
FT_BYTES, BASE_NONE, NULL, 0,
"MNCType", HFILL }},
{ &hf_HI2Operations_lai_01,
{ "lai", "HI2Operations.lai",
FT_BYTES, BASE_NONE, NULL, 0,
"LocationAreaType", HFILL }},
{ &hf_HI2Operations_cI,
{ "cI", "HI2Operations.cI",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdType", HFILL }},
{ &hf_HI2Operations_ssi,
{ "ssi", "HI2Operations.ssi",
FT_BYTES, BASE_NONE, NULL, 0,
"SSIType", HFILL }},
#line 56 "./asn1/HI2Operations/packet-HI2Operations-template.c"
};
static gint *ett[] = {
#line 1 "./asn1/HI2Operations/packet-HI2Operations-ettarr.c"
&ett_HI2Operations_IRIsContent,
&ett_HI2Operations_IRISequence,
&ett_HI2Operations_IRIContent,
&ett_HI2Operations_IRI_Parameters,
&ett_HI2Operations_SET_SIZE_1_10_OF_PartyInformation,
&ett_HI2Operations_T_callContentLinkInformation,
&ett_HI2Operations_CommunicationIdentifier,
&ett_HI2Operations_Network_Identifier,
&ett_HI2Operations_Network_Element_Identifier,
&ett_HI2Operations_TimeStamp,
&ett_HI2Operations_LocalTimeStamp,
&ett_HI2Operations_PartyInformation,
&ett_HI2Operations_T_partyIdentity,
&ett_HI2Operations_CallingPartyNumber,
&ett_HI2Operations_CalledPartyNumber,
&ett_HI2Operations_Location,
&ett_HI2Operations_TetraLocation,
&ett_HI2Operations_T_ms_Loc,
&ett_HI2Operations_GSMLocation,
&ett_HI2Operations_T_geoCoordinates,
&ett_HI2Operations_T_utmCoordinates,
&ett_HI2Operations_T_utmRefCoordinates,
&ett_HI2Operations_UMTSLocation,
&ett_HI2Operations_GeographicalCoordinates,
&ett_HI2Operations_GA_Point,
&ett_HI2Operations_GA_PointWithUnCertainty,
&ett_HI2Operations_GA_Polygon,
&ett_HI2Operations_GA_Polygon_item,
&ett_HI2Operations_CallContentLinkCharacteristics,
&ett_HI2Operations_Services_Information,
&ett_HI2Operations_ISUP_parameters,
&ett_HI2Operations_DSS1_parameters_codeset_0,
&ett_HI2Operations_MAP_parameters,
&ett_HI2Operations_Supplementary_Services,
&ett_HI2Operations_Standard_Supplementary_Services,
&ett_HI2Operations_Non_Standard_Supplementary_Services,
&ett_HI2Operations_Non_Standard_Supplementary_Services_item,
&ett_HI2Operations_Other_Services,
&ett_HI2Operations_ISUP_SS_parameters,
&ett_HI2Operations_DSS1_SS_parameters_codeset_0,
&ett_HI2Operations_DSS1_SS_parameters_codeset_4,
&ett_HI2Operations_DSS1_SS_parameters_codeset_5,
&ett_HI2Operations_DSS1_SS_parameters_codeset_6,
&ett_HI2Operations_DSS1_SS_parameters_codeset_7,
&ett_HI2Operations_DSS1_SS_Invoke_Components,
&ett_HI2Operations_MAP_SS_Invoke_Components,
&ett_HI2Operations_MAP_SS_Parameters,
&ett_HI2Operations_SMS_report,
&ett_HI2Operations_T_sMS_Contents,
&ett_HI2Operations_National_Parameters,
&ett_HI2Operations_Services_Data_Information,
&ett_HI2Operations_GPRS_parameters,
&ett_HI2Operations_DataNodeAddress,
&ett_HI2Operations_IPAddress,
&ett_HI2Operations_IP_value,
&ett_HI2Operations_National_HI2_ASN1parameters,
&ett_HI2Operations_UmtsQos,
&ett_HI2Operations_CorrelationValues,
&ett_HI2Operations_T_both_IRI_CC,
&ett_HI2Operations_IRI_to_CC_Correlation,
&ett_HI2Operations_T_cc,
&ett_HI2Operations_TARGETACTIVITYMONITOR_1,
&ett_HI2Operations_UserSignalType,
&ett_HI2Operations_LocationType,
&ett_HI2Operations_CdcPdu,
&ett_HI2Operations_Message,
&ett_HI2Operations_Answer,
&ett_HI2Operations_CCChange,
&ett_HI2Operations_CCClose,
&ett_HI2Operations_CCOpen,
&ett_HI2Operations_T_ccOpenOption,
&ett_HI2Operations_SEQUENCE_OF_CallId,
&ett_HI2Operations_MediaReport,
&ett_HI2Operations_NetworkSignal,
&ett_HI2Operations_Origination,
&ett_HI2Operations_T_input,
&ett_HI2Operations_Redirection,
&ett_HI2Operations_Release,
&ett_HI2Operations_ServiceInstance,
&ett_HI2Operations_SubjectSignal,
&ett_HI2Operations_T_signal,
&ett_HI2Operations_TerminationAttempt,
&ett_HI2Operations_CallId,
&ett_HI2Operations_CCCId,
&ett_HI2Operations_T_sepCCCpair,
&ett_HI2Operations_PartyId,
&ett_HI2Operations_RedirectedFromInfo,
&ett_HI2Operations_TerminalDisplayInfo,
&ett_HI2Operations_TARGETACTIVITYMONITORind,
&ett_HI2Operations_SEQUENCE_OF_AddressType,
&ett_HI2Operations_SEQUENCE_OF_LocationType_en301040,
&ett_HI2Operations_TARGETCOMMSMONITORind,
&ett_HI2Operations_SEQUENCE_OF_CircuitIdType,
&ett_HI2Operations_TTRAFFICind,
&ett_HI2Operations_CTTRAFFICind,
&ett_HI2Operations_ActivityType,
&ett_HI2Operations_AddressType,
&ett_HI2Operations_SEQUENCE_OF_TETRAAddressType,
&ett_HI2Operations_TETRAAddressType,
&ett_HI2Operations_LocationType_en301040,
&ett_HI2Operations_TETRACGIType,
&ett_HI2Operations_TSIType,
#line 61 "./asn1/HI2Operations/packet-HI2Operations-template.c"
};
proto_HI2Operations = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_HI2Operations, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("HI2Operations", dissect_IRIsContent_PDU, proto_HI2Operations);
}
void proto_reg_handoff_HI2Operations(void) {
}
