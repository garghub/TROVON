static int
dissect_x509sat_TeletexString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_PrintableString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_UniversalString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UniversalString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_BMPString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_BMPString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_DirectoryString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DirectoryString_choice, hf_index, ett_x509sat_DirectoryString,
NULL);
return offset;
}
int
dissect_x509sat_UniqueIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_x509sat_CountryName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_x509sat_CriteriaItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CriteriaItem_choice, hf_index, ett_x509sat_CriteriaItem,
NULL);
return offset;
}
static int
dissect_x509sat_SET_OF_Criteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Criteria_set_of, hf_index, ett_x509sat_SET_OF_Criteria);
return offset;
}
int
dissect_x509sat_Criteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Criteria_choice, hf_index, ett_x509sat_Criteria,
NULL);
return offset;
}
static int
dissect_x509sat_Guide(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Guide_set, hf_index, ett_x509sat_Guide);
return offset;
}
static int
dissect_x509sat_T_subset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_EnhancedGuide(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EnhancedGuide_sequence, hf_index, ett_x509sat_EnhancedGuide);
return offset;
}
int
dissect_x509sat_PostalAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PostalAddress_sequence_of, hf_index, ett_x509sat_PostalAddress);
return offset;
}
static int
dissect_x509sat_TelephoneNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_TelexNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TelexNumber_sequence, hf_index, ett_x509sat_TelexNumber);
return offset;
}
int
dissect_x509sat_FacsimileTelephoneNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FacsimileTelephoneNumber_sequence, hf_index, ett_x509sat_FacsimileTelephoneNumber);
return offset;
}
int
dissect_x509sat_X121Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_InternationalISDNNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_DestinationIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_PreferredDeliveryMethod_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_PreferredDeliveryMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PreferredDeliveryMethod_sequence_of, hf_index, ett_x509sat_PreferredDeliveryMethod);
return offset;
}
static int
dissect_x509sat_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_T_nAddresses(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_nAddresses_set_of, hf_index, ett_x509sat_T_nAddresses);
return offset;
}
int
dissect_x509sat_PresentationAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PresentationAddress_sequence, hf_index, ett_x509sat_PresentationAddress);
return offset;
}
static int
dissect_x509sat_T_profiles(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_profiles_set_of, hf_index, ett_x509sat_T_profiles);
return offset;
}
int
dissect_x509sat_ProtocolInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtocolInformation_sequence, hf_index, ett_x509sat_ProtocolInformation);
return offset;
}
int
dissect_x509sat_NameAndOptionalUID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NameAndOptionalUID_sequence, hf_index, ett_x509sat_NameAndOptionalUID);
return offset;
}
static int
dissect_x509sat_SEQUENCE_OF_AttributeValueAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AttributeValueAssertion_sequence_of, hf_index, ett_x509sat_SEQUENCE_OF_AttributeValueAssertion);
return offset;
}
int
dissect_x509sat_MultipleMatchingLocalities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MultipleMatchingLocalities_sequence, hf_index, ett_x509sat_MultipleMatchingLocalities);
return offset;
}
static int
dissect_x509sat_SubstringAssertion_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SubstringAssertion_item_choice, hf_index, ett_x509sat_SubstringAssertion_item,
NULL);
return offset;
}
int
dissect_x509sat_SubstringAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SubstringAssertion_sequence_of, hf_index, ett_x509sat_SubstringAssertion);
return offset;
}
int
dissect_x509sat_CaseIgnoreListMatch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CaseIgnoreListMatch_sequence_of, hf_index, ett_x509sat_CaseIgnoreListMatch);
return offset;
}
static int
dissect_x509sat_OctetSubstringAssertion_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
OctetSubstringAssertion_item_choice, hf_index, ett_x509sat_OctetSubstringAssertion_item,
NULL);
return offset;
}
int
dissect_x509sat_OctetSubstringAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
OctetSubstringAssertion_sequence_of, hf_index, ett_x509sat_OctetSubstringAssertion);
return offset;
}
int
dissect_x509sat_ZonalSelect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ZonalSelect_sequence_of, hf_index, ett_x509sat_ZonalSelect);
return offset;
}
int
dissect_x509sat_ZonalResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_LanguageContextSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509sat_T_absolute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_absolute_sequence, hf_index, ett_x509sat_T_absolute);
return offset;
}
static int
dissect_x509sat_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_DayTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DayTime_sequence, hf_index, ett_x509sat_DayTime);
return offset;
}
int
dissect_x509sat_DayTimeBand(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DayTimeBand_sequence, hf_index, ett_x509sat_DayTimeBand);
return offset;
}
static int
dissect_x509sat_SET_OF_DayTimeBand(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_DayTimeBand_set_of, hf_index, ett_x509sat_SET_OF_DayTimeBand);
return offset;
}
static int
dissect_x509sat_T_intDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_intDay_set_of, hf_index, ett_x509sat_T_intDay);
return offset;
}
static int
dissect_x509sat_T_bitDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_bitDay_bits, hf_index, ett_x509sat_T_bitDay,
NULL);
return offset;
}
static int
dissect_x509sat_T_intNamedDays(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_T_bitNamedDays(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_bitNamedDays_bits, hf_index, ett_x509sat_T_bitNamedDays,
NULL);
return offset;
}
int
dissect_x509sat_NamedDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NamedDay_choice, hf_index, ett_x509sat_NamedDay,
NULL);
return offset;
}
int
dissect_x509sat_XDayOf(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
XDayOf_choice, hf_index, ett_x509sat_XDayOf,
NULL);
return offset;
}
static int
dissect_x509sat_T_days(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_days_choice, hf_index, ett_x509sat_T_days,
NULL);
return offset;
}
static int
dissect_x509sat_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509sat_T_intWeek(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_intWeek_set_of, hf_index, ett_x509sat_T_intWeek);
return offset;
}
static int
dissect_x509sat_T_bitWeek(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_bitWeek_bits, hf_index, ett_x509sat_T_bitWeek,
NULL);
return offset;
}
static int
dissect_x509sat_T_weeks(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_weeks_choice, hf_index, ett_x509sat_T_weeks,
NULL);
return offset;
}
static int
dissect_x509sat_T_intMonth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_intMonth_set_of, hf_index, ett_x509sat_T_intMonth);
return offset;
}
static int
dissect_x509sat_T_bitMonth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_bitMonth_bits, hf_index, ett_x509sat_T_bitMonth,
NULL);
return offset;
}
static int
dissect_x509sat_T_months(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_months_choice, hf_index, ett_x509sat_T_months,
NULL);
return offset;
}
static int
dissect_x509sat_T_years(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_years_set_of, hf_index, ett_x509sat_T_years);
return offset;
}
int
dissect_x509sat_Period(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Period_sequence, hf_index, ett_x509sat_Period);
return offset;
}
static int
dissect_x509sat_SET_OF_Period(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Period_set_of, hf_index, ett_x509sat_SET_OF_Period);
return offset;
}
static int
dissect_x509sat_T_time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_time_choice, hf_index, ett_x509sat_T_time,
NULL);
return offset;
}
static int
dissect_x509sat_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_x509sat_TimeZone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509sat_TimeSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeSpecification_sequence, hf_index, ett_x509sat_TimeSpecification);
return offset;
}
static int
dissect_x509sat_T_between(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_between_sequence, hf_index, ett_x509sat_T_between);
return offset;
}
int
dissect_x509sat_TimeAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TimeAssertion_choice, hf_index, ett_x509sat_TimeAssertion,
NULL);
return offset;
}
int
dissect_x509sat_LocaleContextSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LocaleContextSyntax_choice, hf_index, ett_x509sat_LocaleContextSyntax,
NULL);
return offset;
}
static int
dissect_x509sat_ObjectIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_x509sat_OctetString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_BitString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_x509sat_Integer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_Boolean(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_x509sat_SyntaxGeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509sat_SyntaxUTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509sat_SyntaxNumericString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxPrintableString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxIA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxBMPString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_BMPString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxUniversalString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UniversalString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxUTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxTeletexString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxT61String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxVideotexString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VideotexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxGraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxISO646String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxVisibleString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_SyntaxGeneralString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509sat_GUID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 378 "../../asn1/x509sat/x509sat.cnf"
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
e_guid_t uuid;
if(!implicit_tag){
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
} else {
gint32 remaining=tvb_reported_length_remaining(tvb, offset);
len=remaining>0 ? remaining : 0;
}
tvb_get_ntohguid (tvb, offset, &uuid);
actx->created_item = proto_tree_add_guid(tree, hf_index, tvb, offset, len, &uuid);
return offset;
}
static int dissect_DirectoryString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_DirectoryString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_DirectoryString_PDU);
return offset;
}
static int dissect_UniqueIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_UniqueIdentifier(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_UniqueIdentifier_PDU);
return offset;
}
static int dissect_CountryName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_CountryName(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_CountryName_PDU);
return offset;
}
static int dissect_Guide_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_Guide(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_Guide_PDU);
return offset;
}
static int dissect_EnhancedGuide_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_EnhancedGuide(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_EnhancedGuide_PDU);
return offset;
}
static int dissect_PostalAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_PostalAddress(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_PostalAddress_PDU);
return offset;
}
static int dissect_TelephoneNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_TelephoneNumber(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_TelephoneNumber_PDU);
return offset;
}
static int dissect_TelexNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_TelexNumber(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_TelexNumber_PDU);
return offset;
}
static int dissect_FacsimileTelephoneNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_FacsimileTelephoneNumber(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_FacsimileTelephoneNumber_PDU);
return offset;
}
static int dissect_X121Address_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_X121Address(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_X121Address_PDU);
return offset;
}
static int dissect_InternationalISDNNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_InternationalISDNNumber(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_InternationalISDNNumber_PDU);
return offset;
}
static int dissect_DestinationIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_DestinationIndicator(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_DestinationIndicator_PDU);
return offset;
}
static int dissect_PreferredDeliveryMethod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_PreferredDeliveryMethod(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_PreferredDeliveryMethod_PDU);
return offset;
}
static int dissect_PresentationAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_PresentationAddress(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_PresentationAddress_PDU);
return offset;
}
static int dissect_ProtocolInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_ProtocolInformation(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_ProtocolInformation_PDU);
return offset;
}
static int dissect_NameAndOptionalUID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_NameAndOptionalUID(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_NameAndOptionalUID_PDU);
return offset;
}
static int dissect_CaseIgnoreListMatch_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_CaseIgnoreListMatch(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_CaseIgnoreListMatch_PDU);
return offset;
}
static int dissect_ObjectIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_ObjectIdentifier(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_ObjectIdentifier_PDU);
return offset;
}
static int dissect_OctetString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_OctetString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_OctetString_PDU);
return offset;
}
static int dissect_BitString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_BitString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_BitString_PDU);
return offset;
}
static int dissect_Integer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_Integer(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_Integer_PDU);
return offset;
}
static int dissect_Boolean_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_Boolean(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_Boolean_PDU);
return offset;
}
static int dissect_SyntaxGeneralizedTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxGeneralizedTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxGeneralizedTime_PDU);
return offset;
}
static int dissect_SyntaxUTCTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxUTCTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxUTCTime_PDU);
return offset;
}
static int dissect_SyntaxNumericString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxNumericString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxNumericString_PDU);
return offset;
}
static int dissect_SyntaxPrintableString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxPrintableString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxPrintableString_PDU);
return offset;
}
static int dissect_SyntaxIA5String_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxIA5String(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxIA5String_PDU);
return offset;
}
static int dissect_SyntaxBMPString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxBMPString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxBMPString_PDU);
return offset;
}
static int dissect_SyntaxUniversalString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxUniversalString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxUniversalString_PDU);
return offset;
}
static int dissect_SyntaxUTF8String_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxUTF8String(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxUTF8String_PDU);
return offset;
}
static int dissect_SyntaxTeletexString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxTeletexString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxTeletexString_PDU);
return offset;
}
static int dissect_SyntaxT61String_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxT61String(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxT61String_PDU);
return offset;
}
static int dissect_SyntaxVideotexString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxVideotexString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxVideotexString_PDU);
return offset;
}
static int dissect_SyntaxGraphicString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxGraphicString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxGraphicString_PDU);
return offset;
}
static int dissect_SyntaxISO646String_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxISO646String(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxISO646String_PDU);
return offset;
}
static int dissect_SyntaxVisibleString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxVisibleString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxVisibleString_PDU);
return offset;
}
static int dissect_SyntaxGeneralString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_SyntaxGeneralString(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_SyntaxGeneralString_PDU);
return offset;
}
static int dissect_GUID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509sat_GUID(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509sat_GUID_PDU);
return offset;
}
void proto_register_x509sat(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/x509sat/packet-x509sat-hfarr.c"
{ &hf_x509sat_DirectoryString_PDU,
{ "DirectoryString", "x509sat.DirectoryString",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_UniqueIdentifier_PDU,
{ "UniqueIdentifier", "x509sat.UniqueIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_CountryName_PDU,
{ "CountryName", "x509sat.CountryName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_Guide_PDU,
{ "Guide", "x509sat.Guide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_EnhancedGuide_PDU,
{ "EnhancedGuide", "x509sat.EnhancedGuide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_PostalAddress_PDU,
{ "PostalAddress", "x509sat.PostalAddress",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_TelephoneNumber_PDU,
{ "TelephoneNumber", "x509sat.TelephoneNumber",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_TelexNumber_PDU,
{ "TelexNumber", "x509sat.TelexNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_FacsimileTelephoneNumber_PDU,
{ "FacsimileTelephoneNumber", "x509sat.FacsimileTelephoneNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_X121Address_PDU,
{ "X121Address", "x509sat.X121Address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_InternationalISDNNumber_PDU,
{ "InternationalISDNNumber", "x509sat.InternationalISDNNumber",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_DestinationIndicator_PDU,
{ "DestinationIndicator", "x509sat.DestinationIndicator",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_PreferredDeliveryMethod_PDU,
{ "PreferredDeliveryMethod", "x509sat.PreferredDeliveryMethod",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_PresentationAddress_PDU,
{ "PresentationAddress", "x509sat.PresentationAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_ProtocolInformation_PDU,
{ "ProtocolInformation", "x509sat.ProtocolInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_NameAndOptionalUID_PDU,
{ "NameAndOptionalUID", "x509sat.NameAndOptionalUID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_CaseIgnoreListMatch_PDU,
{ "CaseIgnoreListMatch", "x509sat.CaseIgnoreListMatch",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_ObjectIdentifier_PDU,
{ "ObjectIdentifier", "x509sat.ObjectIdentifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_OctetString_PDU,
{ "OctetString", "x509sat.OctetString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_BitString_PDU,
{ "BitString", "x509sat.BitString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_Integer_PDU,
{ "Integer", "x509sat.Integer",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_Boolean_PDU,
{ "Boolean", "x509sat.Boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxGeneralizedTime_PDU,
{ "GeneralizedTime", "x509sat.GeneralizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxUTCTime_PDU,
{ "UTCTime", "x509sat.UTCTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxNumericString_PDU,
{ "NumericString", "x509sat.NumericString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxPrintableString_PDU,
{ "PrintableString", "x509sat.PrintableString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxIA5String_PDU,
{ "IA5String", "x509sat.IA5String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxBMPString_PDU,
{ "BMPString", "x509sat.BMPString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxUniversalString_PDU,
{ "UniversalString", "x509sat.UniversalString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxUTF8String_PDU,
{ "UTF8String", "x509sat.UTF8String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxTeletexString_PDU,
{ "TeletexString", "x509sat.TeletexString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxT61String_PDU,
{ "T61String", "x509sat.T61String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxVideotexString_PDU,
{ "VideotexString", "x509sat.VideotexString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxGraphicString_PDU,
{ "GraphicString", "x509sat.GraphicString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxISO646String_PDU,
{ "ISO646String", "x509sat.ISO646String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxVisibleString_PDU,
{ "VisibleString", "x509sat.VisibleString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SyntaxGeneralString_PDU,
{ "GeneralString", "x509sat.GeneralString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_GUID_PDU,
{ "GUID", "x509sat.GUID",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_teletexString,
{ "teletexString", "x509sat.teletexString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_printableString,
{ "printableString", "x509sat.printableString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_universalString,
{ "universalString", "x509sat.universalString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_bmpString,
{ "bmpString", "x509sat.bmpString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_uTF8String,
{ "uTF8String", "x509sat.uTF8String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_objectClass,
{ "objectClass", "x509sat.objectClass",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509sat_criteria,
{ "criteria", "x509sat.criteria",
FT_UINT32, BASE_DEC, VALS(x509sat_Criteria_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_type,
{ "type", "x509sat.type",
FT_UINT32, BASE_DEC, VALS(x509sat_CriteriaItem_vals), 0,
"CriteriaItem", HFILL }},
{ &hf_x509sat_and,
{ "and", "x509sat.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Criteria", HFILL }},
{ &hf_x509sat_and_item,
{ "Criteria", "x509sat.Criteria",
FT_UINT32, BASE_DEC, VALS(x509sat_Criteria_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_or,
{ "or", "x509sat.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Criteria", HFILL }},
{ &hf_x509sat_or_item,
{ "Criteria", "x509sat.Criteria",
FT_UINT32, BASE_DEC, VALS(x509sat_Criteria_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_not,
{ "not", "x509sat.not",
FT_UINT32, BASE_DEC, VALS(x509sat_Criteria_vals), 0,
"Criteria", HFILL }},
{ &hf_x509sat_equality,
{ "equality", "x509sat.equality",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509sat_substrings,
{ "substrings", "x509sat.substrings",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509sat_greaterOrEqual,
{ "greaterOrEqual", "x509sat.greaterOrEqual",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509sat_lessOrEqual,
{ "lessOrEqual", "x509sat.lessOrEqual",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509sat_approximateMatch,
{ "approximateMatch", "x509sat.approximateMatch",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509sat_subset,
{ "subset", "x509sat.subset",
FT_INT32, BASE_DEC, VALS(x509sat_T_subset_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_PostalAddress_item,
{ "DirectoryString", "x509sat.DirectoryString",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_telexNumber,
{ "telexNumber", "x509sat.telexNumber",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_x509sat_countryCode,
{ "countryCode", "x509sat.countryCode",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_x509sat_answerback,
{ "answerback", "x509sat.answerback",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_x509sat_telephoneNumber,
{ "telephoneNumber", "x509sat.telephoneNumber",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_parameters,
{ "parameters", "x509sat.parameters",
FT_BYTES, BASE_NONE, NULL, 0,
"G3FacsimileNonBasicParameters", HFILL }},
{ &hf_x509sat_PreferredDeliveryMethod_item,
{ "PreferredDeliveryMethod item", "x509sat.PreferredDeliveryMethod_item",
FT_INT32, BASE_DEC, VALS(x509sat_PreferredDeliveryMethod_item_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_pSelector,
{ "pSelector", "x509sat.pSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_sSelector,
{ "sSelector", "x509sat.sSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_tSelector,
{ "tSelector", "x509sat.tSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_nAddresses,
{ "nAddresses", "x509sat.nAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_nAddresses_item,
{ "nAddresses item", "x509sat.nAddresses_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_nAddress,
{ "nAddress", "x509sat.nAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_profiles,
{ "profiles", "x509sat.profiles",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_profiles_item,
{ "profiles item", "x509sat.profiles_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509sat_dn,
{ "dn", "x509sat.dn",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_x509sat_uid,
{ "uid", "x509sat.uid",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_x509sat_matchingRuleUsed,
{ "matchingRuleUsed", "x509sat.matchingRuleUsed",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509sat_attributeList,
{ "attributeList", "x509sat.attributeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AttributeValueAssertion", HFILL }},
{ &hf_x509sat_attributeList_item,
{ "AttributeValueAssertion", "x509sat.AttributeValueAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_SubstringAssertion_item,
{ "SubstringAssertion item", "x509sat.SubstringAssertion_item",
FT_UINT32, BASE_DEC, VALS(x509sat_SubstringAssertion_item_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_initial,
{ "initial", "x509sat.initial",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_x509sat_any,
{ "any", "x509sat.any",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_x509sat_final,
{ "final", "x509sat.final",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_x509sat_control,
{ "control", "x509sat.control_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_x509sat_CaseIgnoreListMatch_item,
{ "DirectoryString", "x509sat.DirectoryString",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_OctetSubstringAssertion_item,
{ "OctetSubstringAssertion item", "x509sat.OctetSubstringAssertion_item",
FT_UINT32, BASE_DEC, VALS(x509sat_OctetSubstringAssertion_item_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_initial_substring,
{ "initial", "x509sat.initial",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_any_substring,
{ "any", "x509sat.any",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_finall_substring,
{ "final", "x509sat.final",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_x509sat_ZonalSelect_item,
{ "AttributeType", "x509sat.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_time,
{ "time", "x509sat.time",
FT_UINT32, BASE_DEC, VALS(x509sat_T_time_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_absolute,
{ "absolute", "x509sat.absolute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_startTime,
{ "startTime", "x509sat.startTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509sat_endTime,
{ "endTime", "x509sat.endTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509sat_periodic,
{ "periodic", "x509sat.periodic",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Period", HFILL }},
{ &hf_x509sat_periodic_item,
{ "Period", "x509sat.Period_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_notThisTime,
{ "notThisTime", "x509sat.notThisTime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509sat_timeZone,
{ "timeZone", "x509sat.timeZone",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_timesOfDay,
{ "timesOfDay", "x509sat.timesOfDay",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_DayTimeBand", HFILL }},
{ &hf_x509sat_timesOfDay_item,
{ "DayTimeBand", "x509sat.DayTimeBand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_days,
{ "days", "x509sat.days",
FT_UINT32, BASE_DEC, VALS(x509sat_T_days_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_intDay,
{ "intDay", "x509sat.intDay",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_intDay_item,
{ "intDay item", "x509sat.intDay_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_bitDay,
{ "bitDay", "x509sat.bitDay",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_dayOf,
{ "dayOf", "x509sat.dayOf",
FT_UINT32, BASE_DEC, VALS(x509sat_XDayOf_vals), 0,
"XDayOf", HFILL }},
{ &hf_x509sat_weeks,
{ "weeks", "x509sat.weeks",
FT_UINT32, BASE_DEC, VALS(x509sat_T_weeks_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_allWeeks,
{ "allWeeks", "x509sat.allWeeks_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_intWeek,
{ "intWeek", "x509sat.intWeek",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_intWeek_item,
{ "intWeek item", "x509sat.intWeek_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_bitWeek,
{ "bitWeek", "x509sat.bitWeek",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_months,
{ "months", "x509sat.months",
FT_UINT32, BASE_DEC, VALS(x509sat_T_months_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_allMonths,
{ "allMonths", "x509sat.allMonths_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_intMonth,
{ "intMonth", "x509sat.intMonth",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_intMonth_item,
{ "intMonth item", "x509sat.intMonth_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_bitMonth,
{ "bitMonth", "x509sat.bitMonth",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_years,
{ "years", "x509sat.years",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_years_item,
{ "years item", "x509sat.years_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_first_dayof,
{ "first", "x509sat.first",
FT_UINT32, BASE_DEC, VALS(x509sat_NamedDay_vals), 0,
"NamedDay", HFILL }},
{ &hf_x509sat_second_dayof,
{ "second", "x509sat.second",
FT_UINT32, BASE_DEC, VALS(x509sat_NamedDay_vals), 0,
"NamedDay", HFILL }},
{ &hf_x509sat_third_dayof,
{ "third", "x509sat.third",
FT_UINT32, BASE_DEC, VALS(x509sat_NamedDay_vals), 0,
"NamedDay", HFILL }},
{ &hf_x509sat_fourth_dayof,
{ "fourth", "x509sat.fourth",
FT_UINT32, BASE_DEC, VALS(x509sat_NamedDay_vals), 0,
"NamedDay", HFILL }},
{ &hf_x509sat_fifth_dayof,
{ "fifth", "x509sat.fifth",
FT_UINT32, BASE_DEC, VALS(x509sat_NamedDay_vals), 0,
"NamedDay", HFILL }},
{ &hf_x509sat_intNamedDays,
{ "intNamedDays", "x509sat.intNamedDays",
FT_UINT32, BASE_DEC, VALS(x509sat_T_intNamedDays_vals), 0,
NULL, HFILL }},
{ &hf_x509sat_bitNamedDays,
{ "bitNamedDays", "x509sat.bitNamedDays",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_startDayTime,
{ "startDayTime", "x509sat.startDayTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"DayTime", HFILL }},
{ &hf_x509sat_endDayTime,
{ "endDayTime", "x509sat.endDayTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"DayTime", HFILL }},
{ &hf_x509sat_hour,
{ "hour", "x509sat.hour",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_minute,
{ "minute", "x509sat.minute",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_second,
{ "second", "x509sat.second",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509sat_now,
{ "now", "x509sat.now_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_at,
{ "at", "x509sat.at",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_x509sat_between,
{ "between", "x509sat.between_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509sat_entirely,
{ "entirely", "x509sat.entirely",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509sat_localeID1,
{ "localeID1", "x509sat.localeID1",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509sat_localeID2,
{ "localeID2", "x509sat.localeID2",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_x509sat_T_bitDay_sunday,
{ "sunday", "x509sat.sunday",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_monday,
{ "monday", "x509sat.monday",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_tuesday,
{ "tuesday", "x509sat.tuesday",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_wednesday,
{ "wednesday", "x509sat.wednesday",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_thursday,
{ "thursday", "x509sat.thursday",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_friday,
{ "friday", "x509sat.friday",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_x509sat_T_bitDay_saturday,
{ "saturday", "x509sat.saturday",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_x509sat_T_bitWeek_week1,
{ "week1", "x509sat.week1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509sat_T_bitWeek_week2,
{ "week2", "x509sat.week2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509sat_T_bitWeek_week3,
{ "week3", "x509sat.week3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_x509sat_T_bitWeek_week4,
{ "week4", "x509sat.week4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_x509sat_T_bitWeek_week5,
{ "week5", "x509sat.week5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_january,
{ "january", "x509sat.january",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_february,
{ "february", "x509sat.february",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_march,
{ "march", "x509sat.march",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_april,
{ "april", "x509sat.april",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_may,
{ "may", "x509sat.may",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_june,
{ "june", "x509sat.june",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_july,
{ "july", "x509sat.july",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_august,
{ "august", "x509sat.august",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_september,
{ "september", "x509sat.september",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_october,
{ "october", "x509sat.october",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_november,
{ "november", "x509sat.november",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_x509sat_T_bitMonth_december,
{ "december", "x509sat.december",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_sunday,
{ "sunday", "x509sat.sunday",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_monday,
{ "monday", "x509sat.monday",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_tuesday,
{ "tuesday", "x509sat.tuesday",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_wednesday,
{ "wednesday", "x509sat.wednesday",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_thursday,
{ "thursday", "x509sat.thursday",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_friday,
{ "friday", "x509sat.friday",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_x509sat_T_bitNamedDays_saturday,
{ "saturday", "x509sat.saturday",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
#line 58 "../../asn1/x509sat/packet-x509sat-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/x509sat/packet-x509sat-ettarr.c"
&ett_x509sat_DirectoryString,
&ett_x509sat_Guide,
&ett_x509sat_Criteria,
&ett_x509sat_SET_OF_Criteria,
&ett_x509sat_CriteriaItem,
&ett_x509sat_EnhancedGuide,
&ett_x509sat_PostalAddress,
&ett_x509sat_TelexNumber,
&ett_x509sat_FacsimileTelephoneNumber,
&ett_x509sat_PreferredDeliveryMethod,
&ett_x509sat_PresentationAddress,
&ett_x509sat_T_nAddresses,
&ett_x509sat_ProtocolInformation,
&ett_x509sat_T_profiles,
&ett_x509sat_NameAndOptionalUID,
&ett_x509sat_MultipleMatchingLocalities,
&ett_x509sat_SEQUENCE_OF_AttributeValueAssertion,
&ett_x509sat_SubstringAssertion,
&ett_x509sat_SubstringAssertion_item,
&ett_x509sat_CaseIgnoreListMatch,
&ett_x509sat_OctetSubstringAssertion,
&ett_x509sat_OctetSubstringAssertion_item,
&ett_x509sat_ZonalSelect,
&ett_x509sat_TimeSpecification,
&ett_x509sat_T_time,
&ett_x509sat_T_absolute,
&ett_x509sat_SET_OF_Period,
&ett_x509sat_Period,
&ett_x509sat_SET_OF_DayTimeBand,
&ett_x509sat_T_days,
&ett_x509sat_T_intDay,
&ett_x509sat_T_bitDay,
&ett_x509sat_T_weeks,
&ett_x509sat_T_intWeek,
&ett_x509sat_T_bitWeek,
&ett_x509sat_T_months,
&ett_x509sat_T_intMonth,
&ett_x509sat_T_bitMonth,
&ett_x509sat_T_years,
&ett_x509sat_XDayOf,
&ett_x509sat_NamedDay,
&ett_x509sat_T_bitNamedDays,
&ett_x509sat_DayTimeBand,
&ett_x509sat_DayTime,
&ett_x509sat_TimeAssertion,
&ett_x509sat_T_between,
&ett_x509sat_LocaleContextSyntax,
#line 63 "../../asn1/x509sat/packet-x509sat-template.c"
};
proto_x509sat = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509sat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#line 1 "../../asn1/x509sat/packet-x509sat-syn-reg.c"
new_register_ber_syntax_dissector("BitString", proto_x509sat, dissect_BitString_PDU);
new_register_ber_syntax_dissector("Boolean", proto_x509sat, dissect_Boolean_PDU);
new_register_ber_syntax_dissector("CaseIgnoreListMatch", proto_x509sat, dissect_CaseIgnoreListMatch_PDU);
new_register_ber_syntax_dissector("CountryName", proto_x509sat, dissect_CountryName_PDU);
new_register_ber_syntax_dissector("DestinationIndicator", proto_x509sat, dissect_DestinationIndicator_PDU);
new_register_ber_syntax_dissector("DirectoryString", proto_x509sat, dissect_DirectoryString_PDU);
new_register_ber_syntax_dissector("EnhancedGuide", proto_x509sat, dissect_EnhancedGuide_PDU);
new_register_ber_syntax_dissector("FacsimileTelephoneNumber", proto_x509sat, dissect_FacsimileTelephoneNumber_PDU);
new_register_ber_syntax_dissector("GUID", proto_x509sat, dissect_GUID_PDU);
new_register_ber_syntax_dissector("Guide", proto_x509sat, dissect_Guide_PDU);
new_register_ber_syntax_dissector("InternationalISDNNumber", proto_x509sat, dissect_InternationalISDNNumber_PDU);
new_register_ber_syntax_dissector("Integer", proto_x509sat, dissect_Integer_PDU);
new_register_ber_syntax_dissector("NameAndOptionalUID", proto_x509sat, dissect_NameAndOptionalUID_PDU);
new_register_ber_syntax_dissector("ObjectIdentifier", proto_x509sat, dissect_ObjectIdentifier_PDU);
new_register_ber_syntax_dissector("OctetString", proto_x509sat, dissect_OctetString_PDU);
new_register_ber_syntax_dissector("PostalAddress", proto_x509sat, dissect_PostalAddress_PDU);
new_register_ber_syntax_dissector("PreferredDeliveryMethod", proto_x509sat, dissect_PreferredDeliveryMethod_PDU);
new_register_ber_syntax_dissector("PresentationAddress", proto_x509sat, dissect_PresentationAddress_PDU);
new_register_ber_syntax_dissector("BMPString", proto_x509sat, dissect_SyntaxBMPString_PDU);
new_register_ber_syntax_dissector("GeneralizedTime", proto_x509sat, dissect_SyntaxGeneralizedTime_PDU);
new_register_ber_syntax_dissector("GeneralString", proto_x509sat, dissect_SyntaxGeneralString_PDU);
new_register_ber_syntax_dissector("GraphicString", proto_x509sat, dissect_SyntaxGraphicString_PDU);
new_register_ber_syntax_dissector("IA5String", proto_x509sat, dissect_SyntaxIA5String_PDU);
new_register_ber_syntax_dissector("ISO646String", proto_x509sat, dissect_SyntaxISO646String_PDU);
new_register_ber_syntax_dissector("NumericString", proto_x509sat, dissect_SyntaxNumericString_PDU);
new_register_ber_syntax_dissector("PrintableString", proto_x509sat, dissect_SyntaxPrintableString_PDU);
new_register_ber_syntax_dissector("T61String", proto_x509sat, dissect_SyntaxT61String_PDU);
new_register_ber_syntax_dissector("TeletexString", proto_x509sat, dissect_SyntaxTeletexString_PDU);
new_register_ber_syntax_dissector("UniversalString", proto_x509sat, dissect_SyntaxUniversalString_PDU);
new_register_ber_syntax_dissector("UTF8String", proto_x509sat, dissect_SyntaxUTF8String_PDU);
new_register_ber_syntax_dissector("UTCTime", proto_x509sat, dissect_SyntaxUTCTime_PDU);
new_register_ber_syntax_dissector("VideotexString", proto_x509sat, dissect_SyntaxVideotexString_PDU);
new_register_ber_syntax_dissector("VisibleString", proto_x509sat, dissect_SyntaxVisibleString_PDU);
new_register_ber_syntax_dissector("TelephoneNumber", proto_x509sat, dissect_TelephoneNumber_PDU);
new_register_ber_syntax_dissector("TelexNumber", proto_x509sat, dissect_TelexNumber_PDU);
new_register_ber_syntax_dissector("UniqueIdentifier", proto_x509sat, dissect_UniqueIdentifier_PDU);
new_register_ber_syntax_dissector("X121Address", proto_x509sat, dissect_X121Address_PDU);
#line 73 "../../asn1/x509sat/packet-x509sat-template.c"
}
void proto_reg_handoff_x509sat(void) {
#line 1 "../../asn1/x509sat/packet-x509sat-dis-tab.c"
new_register_ber_oid_dissector("2.5.4.0", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-objectClass");
new_register_ber_oid_dissector("2.5.4.2", dissect_DirectoryString_PDU, proto_x509sat, "id-at-knowledgeInformation");
new_register_ber_oid_dissector("2.5.4.3", dissect_DirectoryString_PDU, proto_x509sat, "id-at-commonName");
new_register_ber_oid_dissector("2.5.4.4", dissect_DirectoryString_PDU, proto_x509sat, "id-at-surname");
new_register_ber_oid_dissector("2.5.4.5", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-serialNumber");
new_register_ber_oid_dissector("2.5.4.6", dissect_CountryName_PDU, proto_x509sat, "id-at-countryName");
new_register_ber_oid_dissector("2.5.4.7", dissect_DirectoryString_PDU, proto_x509sat, "id-at-localityName");
new_register_ber_oid_dissector("2.5.4.7.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectiveLocalityName");
new_register_ber_oid_dissector("2.5.4.8", dissect_DirectoryString_PDU, proto_x509sat, "id-at-stateOrProvinceName");
new_register_ber_oid_dissector("2.5.4.8.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectiveStateOrProvinceName");
new_register_ber_oid_dissector("2.5.4.9", dissect_DirectoryString_PDU, proto_x509sat, "id-at-streetAddress");
new_register_ber_oid_dissector("2.5.4.9.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectiveStreetAddress");
new_register_ber_oid_dissector("2.5.4.10.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectiveOrganizationName");
new_register_ber_oid_dissector("2.5.4.10", dissect_DirectoryString_PDU, proto_x509sat, "id-at-organizationName");
new_register_ber_oid_dissector("2.5.4.11", dissect_DirectoryString_PDU, proto_x509sat, "id-at-organizationalUnitName");
new_register_ber_oid_dissector("2.5.4.11.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectiveOrganizationalUnitName");
new_register_ber_oid_dissector("2.5.4.12", dissect_DirectoryString_PDU, proto_x509sat, "id-at-title");
new_register_ber_oid_dissector("2.5.4.13", dissect_DirectoryString_PDU, proto_x509sat, "id-at-description");
new_register_ber_oid_dissector("2.5.4.14", dissect_Guide_PDU, proto_x509sat, "id-at-searchGuide");
new_register_ber_oid_dissector("2.5.4.15", dissect_DirectoryString_PDU, proto_x509sat, "id-at-businessCategory");
new_register_ber_oid_dissector("2.5.4.16", dissect_PostalAddress_PDU, proto_x509sat, "id-at-postalAddress");
new_register_ber_oid_dissector("2.5.4.17", dissect_DirectoryString_PDU, proto_x509sat, "id-at-postalCode");
new_register_ber_oid_dissector("2.5.4.17.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectivePostalCode");
new_register_ber_oid_dissector("2.5.4.18", dissect_DirectoryString_PDU, proto_x509sat, "id-at-postOfficeBox");
new_register_ber_oid_dissector("2.5.4.18.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectivePostOfficeBox");
new_register_ber_oid_dissector("2.5.4.19", dissect_DirectoryString_PDU, proto_x509sat, "id-at-physicalDeliveryOfficeName");
new_register_ber_oid_dissector("2.5.4.19.1", dissect_DirectoryString_PDU, proto_x509sat, "id-at-collectivePhysicalDeliveryOfficeName");
new_register_ber_oid_dissector("2.5.4.20", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-telephoneNumber");
new_register_ber_oid_dissector("2.5.4.20.1", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-collectiveTelephoneNumber");
new_register_ber_oid_dissector("2.5.4.21", dissect_TelexNumber_PDU, proto_x509sat, "id-at-telexNumber");
new_register_ber_oid_dissector("2.5.4.21.1", dissect_TelexNumber_PDU, proto_x509sat, "id-at-collectiveTelexNumber");
new_register_ber_oid_dissector("2.5.4.23", dissect_FacsimileTelephoneNumber_PDU, proto_x509sat, "id-at-facsimileTelephoneNumber");
new_register_ber_oid_dissector("2.5.4.23.1", dissect_FacsimileTelephoneNumber_PDU, proto_x509sat, "id-at-collectiveFacsimileTelephoneNumber");
new_register_ber_oid_dissector("2.5.4.24", dissect_X121Address_PDU, proto_x509sat, "id-at-x121Address");
new_register_ber_oid_dissector("2.5.4.25", dissect_InternationalISDNNumber_PDU, proto_x509sat, "id-at-internationalISDNNumber");
new_register_ber_oid_dissector("2.5.4.25.1", dissect_InternationalISDNNumber_PDU, proto_x509sat, "id-at-collectiveInternationalISDNNumber");
new_register_ber_oid_dissector("2.5.4.26", dissect_PostalAddress_PDU, proto_x509sat, "id-at-registeredAddress");
new_register_ber_oid_dissector("2.5.4.27", dissect_DestinationIndicator_PDU, proto_x509sat, "id-at-destinationIndicator");
new_register_ber_oid_dissector("2.5.4.28", dissect_PreferredDeliveryMethod_PDU, proto_x509sat, "id-at-preferredDeliveryMethod");
new_register_ber_oid_dissector("2.5.4.29", dissect_PresentationAddress_PDU, proto_x509sat, "id-at-presentationAddress");
new_register_ber_oid_dissector("2.5.4.30", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-supportedApplicationContext");
new_register_ber_oid_dissector("2.5.4.35", dissect_OctetString_PDU, proto_x509sat, "id-at-userPassword");
new_register_ber_oid_dissector("2.5.4.41", dissect_DirectoryString_PDU, proto_x509sat, "id-at-name");
new_register_ber_oid_dissector("2.5.4.42", dissect_DirectoryString_PDU, proto_x509sat, "id-at-givenName");
new_register_ber_oid_dissector("2.5.4.43", dissect_DirectoryString_PDU, proto_x509sat, "id-at-initials");
new_register_ber_oid_dissector("2.5.4.44", dissect_DirectoryString_PDU, proto_x509sat, "id-at-generationQualifier");
new_register_ber_oid_dissector("2.5.4.45", dissect_UniqueIdentifier_PDU, proto_x509sat, "id-at-uniqueIdedntifier");
new_register_ber_oid_dissector("2.5.4.46", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-dnQualifier");
new_register_ber_oid_dissector("2.5.4.47", dissect_EnhancedGuide_PDU, proto_x509sat, "id-at-enhancedSearchGuide");
new_register_ber_oid_dissector("2.5.4.48", dissect_ProtocolInformation_PDU, proto_x509sat, "id-at-protocolInformation");
new_register_ber_oid_dissector("2.5.4.50", dissect_NameAndOptionalUID_PDU, proto_x509sat, "id-at-uniqueMember");
new_register_ber_oid_dissector("2.5.4.51", dissect_DirectoryString_PDU, proto_x509sat, "id-at-houseIdentifier");
new_register_ber_oid_dissector("2.5.4.52", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-supportedAlgorithms");
new_register_ber_oid_dissector("2.5.4.54", dissect_DirectoryString_PDU, proto_x509sat, "id-at-dmdName");
new_register_ber_oid_dissector("2.5.4.56", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-defaultDirQop");
new_register_ber_oid_dissector("2.5.4.65", dissect_DirectoryString_PDU, proto_x509sat, "id-at-pseudonym");
new_register_ber_oid_dissector("2.5.4.66", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-communuicationsService");
new_register_ber_oid_dissector("2.5.4.67", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-communuicationsNetwork");
new_register_ber_oid_dissector("2.5.13.8", dissect_SyntaxNumericString_PDU, proto_x509sat, "id-mr-numericStringMatch");
new_register_ber_oid_dissector("2.5.13.11", dissect_CaseIgnoreListMatch_PDU, proto_x509sat, "id-mr-caseIgnoreListMatch");
new_register_ber_oid_dissector("2.5.13.16", dissect_BitString_PDU, proto_x509sat, "id-mr-bitStringMatch");
new_register_ber_oid_dissector("2.5.13.26", dissect_SyntaxUTCTime_PDU, proto_x509sat, "id-mr-uTCTimeOrderingMatch");
new_register_ber_oid_dissector("2.5.18.1", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-oa-createTimeStamp");
new_register_ber_oid_dissector("2.5.18.2", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-oa-modifyTimeStamp");
new_register_ber_oid_dissector("2.5.18.5", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-oa-administrativeRole");
new_register_ber_oid_dissector("2.5.18.7", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-oa-collectiveExclusions");
new_register_ber_oid_dissector("2.5.18.8", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-oa-subschemaTimeStamp");
new_register_ber_oid_dissector("2.5.18.9", dissect_Boolean_PDU, proto_x509sat, "id-oa-hasSubordinates");
new_register_ber_oid_dissector("2.5.24.1", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-aca-accessControlScheme");
new_register_ber_oid_dissector("2.6.5.2.8", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-mhs-supported-automatic-actions");
new_register_ber_oid_dissector("2.6.5.2.10", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-mhs-supported-attributes");
new_register_ber_oid_dissector("2.6.5.2.11", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-mhs-supported-matching-rules");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.45", dissect_DirectoryString_PDU, proto_x509sat, "id-at-releaseAuthorityName");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.51", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-cognizantAuthority");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.53", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-accountingCode");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.54", dissect_Boolean_PDU, proto_x509sat, "id-at-dualRoute");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.55", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-effectiveDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.57", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-expirationDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.58", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-hostOrgACP127");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.60", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-lastRecapDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.62", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-lmf");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.63", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-longTitle");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.64", dissect_Boolean_PDU, proto_x509sat, "id-at-minimize");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.65", dissect_Boolean_PDU, proto_x509sat, "id-at-minimizeOverride");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.68", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-nationality");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.68.1", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-collectiveNationality");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.69", dissect_Boolean_PDU, proto_x509sat, "id-at-transferStation");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.70", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-plaNameACP127");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.72", dissect_Boolean_PDU, proto_x509sat, "id-at-plaReplace");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.73", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-primarySpellingACP127");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.74", dissect_Boolean_PDU, proto_x509sat, "id-at-publish");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.75", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-recapDueDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.77", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-rI");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.81", dissect_Boolean_PDU, proto_x509sat, "id-at-section");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.82", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-serviceOrAgency");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.83", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-sHD");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.84", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-shortTitle");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.85", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-sigad");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.86", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-spot");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.87", dissect_Boolean_PDU, proto_x509sat, "id-at-tARE");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.94", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-aCPMobileTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.95", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-aCPPagerTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.96", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-tCC");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.97", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-tRC");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.106", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-accessCodes");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.107", dissect_SyntaxGraphicString_PDU, proto_x509sat, "id-at-accessSchema");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.109", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-aCPTelephoneFaxNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.115", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-gatewayType");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.116", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-ghpType");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.118", dissect_DirectoryString_PDU, proto_x509sat, "id-at-mailDomains");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.119", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-militaryFacsimileNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.119.1", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-collectiveMilitaryFacsimileNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.120", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-militaryTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.120.1", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-collectiveMilitaryTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.122", dissect_SyntaxGraphicString_PDU, proto_x509sat, "id-at-networkSchema");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.124", dissect_DirectoryString_PDU, proto_x509sat, "id-at-operationName");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.125", dissect_DirectoryString_PDU, proto_x509sat, "id-at-positionNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.126", dissect_DirectoryString_PDU, proto_x509sat, "id-at-proprietaryMailboxes");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.127", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-secureFacsimileNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.127.1", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-collectiveSecureFacsimileNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.128", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-secureTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.128.1", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-collectiveSecureTelephoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.129", dissect_DirectoryString_PDU, proto_x509sat, "id-at-serviceNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.133", dissect_DirectoryString_PDU, proto_x509sat, "id-at-rank");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.143", dissect_DirectoryString_PDU, proto_x509sat, "id-at-adminConversion");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.144", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-tCCG");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.145", dissect_DirectoryString_PDU, proto_x509sat, "id-at-usdConversion");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.158", dissect_DirectoryString_PDU, proto_x509sat, "id-at-aCPRoleInformation");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.159", dissect_DirectoryString_PDU, proto_x509sat, "id-at-coalitionGrade");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.160", dissect_TelephoneNumber_PDU, proto_x509sat, "id-at-militaryIPPhoneNumber");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.161", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-fileTypeInfoCapability");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.172", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPFunctionalDescription");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.173", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-alternatePLAName");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.174", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-aCPEntryCreationDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.175", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "id-at-aCPEntryModificationDate");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.176", dissect_ObjectIdentifier_PDU, proto_x509sat, "id-at-aCPEntryType");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.177", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPEntryUniqueId");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.178", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPCitizenship");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.179", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPEID");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.180", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPCOI");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.181", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPPublishTo");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.182", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPSvcApps");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.183", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPDirectionsTo");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.185", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPLatitude");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.186", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPLocationMap");
new_register_ber_oid_dissector("2.16.840.1.101.2.2.1.187", dissect_SyntaxPrintableString_PDU, proto_x509sat, "id-at-aCPLongitude");
new_register_ber_oid_dissector("1.2.840.113549.1.9.1", dissect_SyntaxIA5String_PDU, proto_x509sat, "pkcs-9-at-emailAddress");
new_register_ber_oid_dissector("1.2.840.113549.1.9.7", dissect_DirectoryString_PDU, proto_x509sat, "pkcs-9-at-challengePassword");
new_register_ber_oid_dissector("1.2.840.113549.1.9.8", dissect_DirectoryString_PDU, proto_x509sat, "pkcs-9-at-unstructuredAddress");
new_register_ber_oid_dissector("1.2.840.113549.1.9.13", dissect_DirectoryString_PDU, proto_x509sat, "pkcs-9-at-signingDescription");
new_register_ber_oid_dissector("1.2.840.113549.1.9.20", dissect_SyntaxBMPString_PDU, proto_x509sat, "pkcs-9-at-friendlyName");
new_register_ber_oid_dissector("1.2.840.113549.1.9.21", dissect_OctetString_PDU, proto_x509sat, "pkcs-9-at-localKeyId");
new_register_ber_oid_dissector("1.2.840.113549.1.9.25.3", dissect_OctetString_PDU, proto_x509sat, "pkcs-9-at-randomNonce");
new_register_ber_oid_dissector("1.2.840.113549.1.9.25.4", dissect_Integer_PDU, proto_x509sat, "pkcs-9-at-sequenceNumber");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.1", dissect_SyntaxGeneralizedTime_PDU, proto_x509sat, "pkcs-9-at-dateOfBirth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.2", dissect_DirectoryString_PDU, proto_x509sat, "pkcs-9-at-placeOfBirth");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.3", dissect_SyntaxPrintableString_PDU, proto_x509sat, "pkcs-9-at-gender");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.4", dissect_SyntaxPrintableString_PDU, proto_x509sat, "pkcs-9-at-countryOfCitizenship");
new_register_ber_oid_dissector("1.3.6.1.5.5.7.9.5", dissect_SyntaxPrintableString_PDU, proto_x509sat, "pkcs-9-at-countryOfResidence");
new_register_ber_oid_dissector("0.9.2342.19200300.100.1.25", dissect_SyntaxIA5String_PDU, proto_x509sat, "dc");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.1", dissect_DirectoryString_PDU, proto_x509sat, "carLicense");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.2", dissect_DirectoryString_PDU, proto_x509sat, "departmentNumber");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.3", dissect_DirectoryString_PDU, proto_x509sat, "employeeNumber");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.4", dissect_DirectoryString_PDU, proto_x509sat, "employeeType");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.39", dissect_DirectoryString_PDU, proto_x509sat, "preferredLanguage");
new_register_ber_oid_dissector("2.16.840.1.113730.3.1.241", dissect_DirectoryString_PDU, proto_x509sat, "displayName");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.20.2", dissect_SyntaxBMPString_PDU, proto_x509sat, "id-ms-certificate-template-name");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.20.2.3", dissect_SyntaxUTF8String_PDU, proto_x509sat, "id-ms-user-principal-name");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.17.1", dissect_SyntaxBMPString_PDU, proto_x509sat, "id-ms-local-machine-keyset");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.1", dissect_Integer_PDU, proto_x509sat, "id-ms-ca-version");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.2", dissect_OctetString_PDU, proto_x509sat, "id-ms-previous-cert-hash");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.3", dissect_Integer_PDU, proto_x509sat, "id-ms-virtual-base");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.21.4", dissect_SyntaxUTCTime_PDU, proto_x509sat, "id-ms-next-publish");
new_register_ber_oid_dissector("1.2.826.0.1063.7.0.0.0", dissect_Integer_PDU, proto_x509sat, "unknown-UK-organisation-defined-extension");
new_register_ber_oid_dissector("1.2.826.0.1004.10.1.1", dissect_SyntaxIA5String_PDU, proto_x509sat, "nexor-originating-ua");
new_register_ber_oid_dissector("2.6.1.6.3", dissect_Boolean_PDU, proto_x509sat, "id-sat-ipm-auto-discarded");
new_register_ber_oid_dissector("1.3.6.1.1.16.4", dissect_GUID_PDU, proto_x509sat, "entryUUID");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.60.2.1.1", dissect_DirectoryString_PDU, proto_x509sat, "jurisdictionOfIncorporationLocalityName");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.60.2.1.2", dissect_DirectoryString_PDU, proto_x509sat, "jurisdictionOfIncorporationStateOrProvinceName");
new_register_ber_oid_dissector("1.3.6.1.4.1.311.60.2.1.3", dissect_CountryName_PDU, proto_x509sat, "jurisdictionOfIncorporationCountryName");
#line 80 "../../asn1/x509sat/packet-x509sat-template.c"
oid_add_from_string("top","2.5.6.0");
oid_add_from_string("alias","2.5.6.1");
oid_add_from_string("country","2.5.6.2");
oid_add_from_string("locality","2.5.6.3");
oid_add_from_string("organization","2.5.6.4");
oid_add_from_string("organizationalUnit","2.5.6.5");
oid_add_from_string("person","2.5.6.6");
oid_add_from_string("organizationalPerson","2.5.6.7");
oid_add_from_string("organizationalRole","2.5.6.8");
oid_add_from_string("groupOfNames","2.5.6.9");
oid_add_from_string("residentialPerson","2.5.6.10");
oid_add_from_string("applicationProcess","2.5.6.11");
oid_add_from_string("applicationEntity","2.5.6.12");
oid_add_from_string("dSA","2.5.6.13");
oid_add_from_string("device","2.5.6.14");
oid_add_from_string("strongAuthenticationUser","2.5.6.15");
oid_add_from_string("certificationAuthority","2.5.6.16");
oid_add_from_string("certificationAuthorityV2","2.5.6.16.2");
oid_add_from_string("groupOfUniqueNames","2.5.6.17");
oid_add_from_string("userSecurityInformation","2.5.6.18");
oid_add_from_string("cRLDistributionPoint","2.5.6.19");
oid_add_from_string("dmd","2.5.6.20");
oid_add_from_string("pkiUser","2.5.6.21");
oid_add_from_string("pkiCA","2.5.6.22");
oid_add_from_string("parent","2.5.6.28");
oid_add_from_string("child","2.5.6.29");
oid_add_from_string("dcObject","1.3.6.1.4.1.1446.344");
oid_add_from_string("domain","0.9.2342.19200300.100.4.13");
oid_add_from_string("inetOrgPerson","2.16.840.1.113730.3.2.2");
}
