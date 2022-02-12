static int
dissect_isdn_sup_NumberDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PublicTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PublicPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PublicPartyNumber_sequence, hf_index, ett_isdn_sup_PublicPartyNumber);
return offset;
}
static int
dissect_isdn_sup_NsapEncodedNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PrivateTypeOfNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PrivatePartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PrivatePartyNumber_sequence, hf_index, ett_isdn_sup_PrivatePartyNumber);
return offset;
}
static int
dissect_isdn_sup_PartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PartyNumber_choice, hf_index, ett_isdn_sup_PartyNumber,
NULL);
return offset;
}
static int
dissect_isdn_sup_ScreeningIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_SubaddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_isdn_sup_UserSpecifiedSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserSpecifiedSubaddress_sequence, hf_index, ett_isdn_sup_UserSpecifiedSubaddress);
return offset;
}
static int
dissect_isdn_sup_NSAPSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PartySubaddress_choice, hf_index, ett_isdn_sup_PartySubaddress,
NULL);
return offset;
}
static int
dissect_isdn_sup_AddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddressScreened_sequence, hf_index, ett_isdn_sup_AddressScreened);
return offset;
}
static int
dissect_isdn_sup_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_isdn_sup_PresentedAddressScreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedAddressScreened_choice, hf_index, ett_isdn_sup_PresentedAddressScreened,
NULL);
return offset;
}
static int
dissect_isdn_sup_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Address_sequence, hf_index, ett_isdn_sup_Address);
return offset;
}
static int
dissect_isdn_sup_PresentedNumberUnscreened(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PresentedNumberUnscreened_choice, hf_index, ett_isdn_sup_PresentedNumberUnscreened,
NULL);
return offset;
}
static int
dissect_isdn_sup_PresentationAllowedIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_isdn_sup_BasicService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Q931InformationElement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 0, TRUE, dissect_isdn_sup_OCTET_STRING);
return offset;
}
static int
dissect_isdn_sup_ChargingCase(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_ChargingRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_ChargingCase(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_ChargedItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Currency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_CurrencyAmount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Multiplier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Amount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Amount_sequence, hf_index, ett_isdn_sup_Amount);
return offset;
}
static int
dissect_isdn_sup_ChargingType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_LengthOfTimeUnit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Scale(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Time_sequence, hf_index, ett_isdn_sup_Time);
return offset;
}
static int
dissect_isdn_sup_DurationCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DurationCurrency_sequence, hf_index, ett_isdn_sup_DurationCurrency);
return offset;
}
static int
dissect_isdn_sup_FlatRateCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FlatRateCurrency_sequence, hf_index, ett_isdn_sup_FlatRateCurrency);
return offset;
}
static int
dissect_isdn_sup_VolumeUnit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_VolumeRateCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
VolumeRateCurrency_sequence, hf_index, ett_isdn_sup_VolumeRateCurrency);
return offset;
}
static int
dissect_isdn_sup_T_specificCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_specificCurrency_choice, hf_index, ett_isdn_sup_T_specificCurrency,
NULL);
return offset;
}
static int
dissect_isdn_sup_SpecialChargingCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_T_chargingtype(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_chargingtype_choice, hf_index, ett_isdn_sup_T_chargingtype,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCSCurrencyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCSCurrencyInfo_sequence, hf_index, ett_isdn_sup_AOCSCurrencyInfo);
return offset;
}
static int
dissect_isdn_sup_AOCSCurrencyInfoList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AOCSCurrencyInfoList_sequence_of, hf_index, ett_isdn_sup_AOCSCurrencyInfoList);
return offset;
}
static int
dissect_isdn_sup_AOCSSpecialArrInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_ChargingRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingRequestRes_choice, hf_index, ett_isdn_sup_ChargingRequestRes,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCSCurrencyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCSCurrencyArg_choice, hf_index, ett_isdn_sup_AOCSCurrencyArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCSSpecialArrArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCSSpecialArrArg_choice, hf_index, ett_isdn_sup_AOCSSpecialArrArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_RecordedCurrency(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RecordedCurrency_sequence, hf_index, ett_isdn_sup_RecordedCurrency);
return offset;
}
static int
dissect_isdn_sup_TypeOfChargingInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCDBillingId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_T_specificCurrency_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_specificCurrency_01_sequence, hf_index, ett_isdn_sup_T_specificCurrency_01);
return offset;
}
static int
dissect_isdn_sup_AOCDCurrencyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCDCurrencyInfo_choice, hf_index, ett_isdn_sup_AOCDCurrencyInfo,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCDCurrencyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCDCurrencyArg_choice, hf_index, ett_isdn_sup_AOCDCurrencyArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_NumberOfUnits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_T_cc(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_cc_choice, hf_index, ett_isdn_sup_T_cc,
NULL);
return offset;
}
static int
dissect_isdn_sup_TypeOfUnit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_RecordedUnits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RecordedUnits_sequence, hf_index, ett_isdn_sup_RecordedUnits);
return offset;
}
static int
dissect_isdn_sup_RecordedUnitsList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RecordedUnitsList_sequence_of, hf_index, ett_isdn_sup_RecordedUnitsList);
return offset;
}
static int
dissect_isdn_sup_T_specificChargingUnits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_specificChargingUnits_sequence, hf_index, ett_isdn_sup_T_specificChargingUnits);
return offset;
}
static int
dissect_isdn_sup_AOCDChargingUnitInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCDChargingUnitInfo_choice, hf_index, ett_isdn_sup_AOCDChargingUnitInfo,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCDChargingUnitArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCDChargingUnitArg_choice, hf_index, ett_isdn_sup_AOCDChargingUnitArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCEBillingId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_T_specificCurrency_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_specificCurrency_02_sequence, hf_index, ett_isdn_sup_T_specificCurrency_02);
return offset;
}
static int
dissect_isdn_sup_T_cc_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_cc_01_choice, hf_index, ett_isdn_sup_T_cc_01,
NULL);
return offset;
}
static int
dissect_isdn_sup_ChargeIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_ChargingAssociation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingAssociation_choice, hf_index, ett_isdn_sup_ChargingAssociation,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCECurrencyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCECurrencyInfo_sequence, hf_index, ett_isdn_sup_AOCECurrencyInfo);
return offset;
}
static int
dissect_isdn_sup_AOCECurrencyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCECurrencyArg_choice, hf_index, ett_isdn_sup_AOCECurrencyArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_T_specificChargingUnits_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_specificChargingUnits_01_sequence, hf_index, ett_isdn_sup_T_specificChargingUnits_01);
return offset;
}
static int
dissect_isdn_sup_T_cc_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_cc_02_choice, hf_index, ett_isdn_sup_T_cc_02,
NULL);
return offset;
}
static int
dissect_isdn_sup_AOCEChargingUnitInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCEChargingUnitInfo_sequence, hf_index, ett_isdn_sup_AOCEChargingUnitInfo);
return offset;
}
static int
dissect_isdn_sup_AOCEChargingUnitArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AOCEChargingUnitArg_choice, hf_index, ett_isdn_sup_AOCEChargingUnitArg,
NULL);
return offset;
}
static int
dissect_isdn_sup_OARequested(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 1, TRUE, dissect_isdn_sup_BOOLEAN);
return offset;
}
static int
dissect_isdn_sup_INTEGER_0_32767(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_CUGIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 2, TRUE, dissect_isdn_sup_INTEGER_0_32767);
return offset;
}
static int
dissect_isdn_sup_CUGcallArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CUGcallArg_sequence, hf_index, ett_isdn_sup_CUGcallArg);
return offset;
}
static int
dissect_isdn_sup_ConfSize(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_BeginCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_ConfSize(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_ConferenceId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_PartyId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_BeginCONFRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BeginCONFRes_sequence, hf_index, ett_isdn_sup_BeginCONFRes);
return offset;
}
static int
dissect_isdn_sup_AddCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_ConferenceId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_AddCONFRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_SplitCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SplitCONFArg_sequence, hf_index, ett_isdn_sup_SplitCONFArg);
return offset;
}
static int
dissect_isdn_sup_DropCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_IsolateCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_ReattachCONFArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_PartyDISCArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_Procedure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_ServedUserNr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ServedUserNr_choice, hf_index, ett_isdn_sup_ServedUserNr,
NULL);
return offset;
}
static int
dissect_isdn_sup_NoReplyTimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_ActivationDiversionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActivationDiversionArg_sequence, hf_index, ett_isdn_sup_ActivationDiversionArg);
return offset;
}
static int
dissect_isdn_sup_DeactivationDiversionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeactivationDiversionArg_sequence, hf_index, ett_isdn_sup_DeactivationDiversionArg);
return offset;
}
static int
dissect_isdn_sup_ActivationStatusNotificationDivArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActivationStatusNotificationDivArg_sequence, hf_index, ett_isdn_sup_ActivationStatusNotificationDivArg);
return offset;
}
static int
dissect_isdn_sup_DeactivationStatusNotificationDivArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeactivationStatusNotificationDivArg_sequence, hf_index, ett_isdn_sup_DeactivationStatusNotificationDivArg);
return offset;
}
static int
dissect_isdn_sup_InterrogationDiversionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InterrogationDiversionArg_sequence, hf_index, ett_isdn_sup_InterrogationDiversionArg);
return offset;
}
static int
dissect_isdn_sup_IntResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IntResult_sequence, hf_index, ett_isdn_sup_IntResult);
return offset;
}
static int
dissect_isdn_sup_IntResultList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
IntResultList_set_of, hf_index, ett_isdn_sup_IntResultList);
return offset;
}
static int
dissect_isdn_sup_InterrogationDiversionRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_IntResultList(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_ServedUserNumberList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ServedUserNumberList_set_of, hf_index, ett_isdn_sup_ServedUserNumberList);
return offset;
}
static int
dissect_isdn_sup_InterrogateServedUserNumbersRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_ServedUserNumberList(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_DiversionReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_DiversionInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DiversionInformationArg_sequence, hf_index, ett_isdn_sup_DiversionInformationArg);
return offset;
}
static int
dissect_isdn_sup_CallDeflectionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallDeflectionArg_sequence, hf_index, ett_isdn_sup_CallDeflectionArg);
return offset;
}
static int
dissect_isdn_sup_DiversionCounter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_SubscriptionOption(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_CallRerouteingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallRerouteingArg_sequence, hf_index, ett_isdn_sup_CallRerouteingArg);
return offset;
}
static int
dissect_isdn_sup_DivertingLegInformation1Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DivertingLegInformation1Arg_sequence, hf_index, ett_isdn_sup_DivertingLegInformation1Arg);
return offset;
}
static int
dissect_isdn_sup_DivertingLegInformation2Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DivertingLegInformation2Arg_sequence, hf_index, ett_isdn_sup_DivertingLegInformation2Arg);
return offset;
}
static int
dissect_isdn_sup_DivertingLegInformation3Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PresentationAllowedIndicator(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_Service(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Preferred(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_isdn_sup_UserUserServiceArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserUserServiceArg_sequence, hf_index, ett_isdn_sup_UserUserServiceArg);
return offset;
}
static int
dissect_isdn_sup_CalledFreephoneNr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_PartyNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_CalledFreephoneNrArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_isdn_sup_CalledFreephoneNr(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_isdn_sup_QueueIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Monitor_T_FPHArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Monitor_T_FPHArg_sequence, hf_index, ett_isdn_sup_Monitor_T_FPHArg);
return offset;
}
static int
dissect_isdn_sup_FPHReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_isdn_sup_Free_T_FPHArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Free_T_FPHArg_sequence, hf_index, ett_isdn_sup_Free_T_FPHArg);
return offset;
}
static int
dissect_isdn_sup_Call_T_FPHArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Call_T_FPHArg_sequence, hf_index, ett_isdn_sup_Call_T_FPHArg);
return offset;
}
static int dissect_ChargingRequestArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_ChargingRequestArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_ChargingRequestArg_PDU);
return offset;
}
static int dissect_ChargingRequestRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_ChargingRequestRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_ChargingRequestRes_PDU);
return offset;
}
static int dissect_AOCSCurrencyArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCSCurrencyArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCSCurrencyArg_PDU);
return offset;
}
static int dissect_AOCSSpecialArrArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCSSpecialArrArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCSSpecialArrArg_PDU);
return offset;
}
static int dissect_AOCDCurrencyArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCDCurrencyArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCDCurrencyArg_PDU);
return offset;
}
static int dissect_AOCDChargingUnitArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCDChargingUnitArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCDChargingUnitArg_PDU);
return offset;
}
static int dissect_AOCECurrencyArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCECurrencyArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCECurrencyArg_PDU);
return offset;
}
static int dissect_AOCEChargingUnitArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AOCEChargingUnitArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AOCEChargingUnitArg_PDU);
return offset;
}
static int dissect_CUGcallArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_CUGcallArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_CUGcallArg_PDU);
return offset;
}
static int dissect_BeginCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_BeginCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_BeginCONFArg_PDU);
return offset;
}
static int dissect_BeginCONFRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_BeginCONFRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_BeginCONFRes_PDU);
return offset;
}
static int dissect_AddCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AddCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AddCONFArg_PDU);
return offset;
}
static int dissect_AddCONFRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_AddCONFRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_AddCONFRes_PDU);
return offset;
}
static int dissect_SplitCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_SplitCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_SplitCONFArg_PDU);
return offset;
}
static int dissect_DropCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DropCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DropCONFArg_PDU);
return offset;
}
static int dissect_IsolateCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_IsolateCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_IsolateCONFArg_PDU);
return offset;
}
static int dissect_ReattachCONFArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_ReattachCONFArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_ReattachCONFArg_PDU);
return offset;
}
static int dissect_PartyDISCArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_PartyDISCArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_PartyDISCArg_PDU);
return offset;
}
static int dissect_ActivationDiversionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_ActivationDiversionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_ActivationDiversionArg_PDU);
return offset;
}
static int dissect_DeactivationDiversionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DeactivationDiversionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DeactivationDiversionArg_PDU);
return offset;
}
static int dissect_ActivationStatusNotificationDivArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_ActivationStatusNotificationDivArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_ActivationStatusNotificationDivArg_PDU);
return offset;
}
static int dissect_DeactivationStatusNotificationDivArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DeactivationStatusNotificationDivArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DeactivationStatusNotificationDivArg_PDU);
return offset;
}
static int dissect_InterrogationDiversionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_InterrogationDiversionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_InterrogationDiversionArg_PDU);
return offset;
}
static int dissect_InterrogationDiversionRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_InterrogationDiversionRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_InterrogationDiversionRes_PDU);
return offset;
}
static int dissect_InterrogateServedUserNumbersRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_InterrogateServedUserNumbersRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_InterrogateServedUserNumbersRes_PDU);
return offset;
}
static int dissect_DiversionInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DiversionInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DiversionInformationArg_PDU);
return offset;
}
static int dissect_CallDeflectionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_CallDeflectionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_CallDeflectionArg_PDU);
return offset;
}
static int dissect_CallRerouteingArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_CallRerouteingArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_CallRerouteingArg_PDU);
return offset;
}
static int dissect_DivertingLegInformation1Arg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DivertingLegInformation1Arg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DivertingLegInformation1Arg_PDU);
return offset;
}
static int dissect_DivertingLegInformation2Arg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DivertingLegInformation2Arg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DivertingLegInformation2Arg_PDU);
return offset;
}
static int dissect_DivertingLegInformation3Arg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_DivertingLegInformation3Arg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_DivertingLegInformation3Arg_PDU);
return offset;
}
static int dissect_UserUserServiceArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_UserUserServiceArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_UserUserServiceArg_PDU);
return offset;
}
static int dissect_CalledFreephoneNrArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_CalledFreephoneNrArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_CalledFreephoneNrArg_PDU);
return offset;
}
static int dissect_Monitor_T_FPHArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_Monitor_T_FPHArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_Monitor_T_FPHArg_PDU);
return offset;
}
static int dissect_Free_T_FPHArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_Free_T_FPHArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_Free_T_FPHArg_PDU);
return offset;
}
static int dissect_Call_T_FPHArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_isdn_sup_Call_T_FPHArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_isdn_sup_Call_T_FPHArg_PDU);
return offset;
}
static const isdn_sup_op_t *get_op(gint32 opcode) {
int i;
for (i = array_length(isdn_sup_op_tab) - 1; i >= 0; i--)
if (isdn_sup_op_tab[i].opcode == opcode)
return &isdn_sup_op_tab[i];
return NULL;
}
static const isdn_sup_err_t *get_err(gint32 errcode) {
int i;
for (i = array_length(isdn_sup_err_tab) - 1; i >= 0; i--)
if (isdn_sup_err_tab[i].errcode == errcode)
return &isdn_sup_err_tab[i];
return NULL;
}
static int
dissect_isdn_sup_arg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset;
rose_ctx_t *rctx;
gint32 opcode = 0;
const gchar *p;
const isdn_sup_op_t *op_ptr;
proto_item *ti;
proto_tree *isdn_sup_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 1)
return offset;
if (rctx->d.code == 0) {
opcode = rctx->d.code_local;
} else {
return offset;
}
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, tvb_length(tvb), ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(isdn_sup_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->arg_pdu)
offset = op_ptr->arg_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(isdn_sup_tree, tvb, offset, -1, "UNSUPPORTED ARGUMENT TYPE (ETSI Sup)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_isdn_sup_res(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
gint offset;
rose_ctx_t *rctx;
gint32 opcode = 0;
const gchar *p;
const isdn_sup_op_t *op_ptr;
proto_item *ti;
proto_tree *isdn_sup_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 2)
return offset;
if (rctx->d.code != 0)
return offset;
opcode = rctx->d.code_local;
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, tvb_length(tvb), ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(isdn_sup_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->res_pdu)
offset = op_ptr->res_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(isdn_sup_tree, tvb, offset, -1, "UNSUPPORTED RESULT TYPE (ETSI sup)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_isdn_sup_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset;
rose_ctx_t *rctx;
gint32 errcode;
const isdn_sup_err_t *err_ptr;
const gchar *p;
proto_item *ti;
proto_tree *isdn_sup_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 3)
return offset;
if (rctx->d.code != 0)
return offset;
errcode = rctx->d.code_local;
err_ptr = get_err(errcode);
if (!err_ptr)
return offset;
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, tvb_length(tvb), ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_error, tvb, 0, 0, errcode);
p = try_val_to_str(errcode, VALS(isdn_sup_str_error));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (err_ptr->err_pdu)
offset = err_ptr->err_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(isdn_sup_tree, tvb, offset, -1, "UNSUPPORTED ERROR TYPE (ETSI sup)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
void proto_reg_handoff_isdn_sup(void) {
int i;
#if 0
dissector_handle_t q931_handle;
#endif
dissector_handle_t isdn_sup_arg_handle;
dissector_handle_t isdn_sup_res_handle;
dissector_handle_t isdn_sup_err_handle;
#if 0
q931_handle = find_dissector("q931");
#endif
isdn_sup_arg_handle = new_create_dissector_handle(dissect_isdn_sup_arg, proto_isdn_sup);
isdn_sup_res_handle = new_create_dissector_handle(dissect_isdn_sup_res, proto_isdn_sup);
for (i=0; i<(int)array_length(isdn_sup_op_tab); i++) {
dissector_add_uint("q932.ros.etsi.local.arg", isdn_sup_op_tab[i].opcode, isdn_sup_arg_handle);
dissector_add_uint("q932.ros.etsi.local.res", isdn_sup_op_tab[i].opcode, isdn_sup_res_handle);
}
for (i=0; i<(int)array_length(isdn_sup_global_op_tab); i++) {
if(isdn_sup_global_op_tab->arg_pdu)
dissector_add_string("q932.ros.global.arg", isdn_sup_global_op_tab[i].oid, new_create_dissector_handle(isdn_sup_global_op_tab[i].arg_pdu, proto_isdn_sup));
if(isdn_sup_global_op_tab->res_pdu)
dissector_add_string("q932.ros.global.res", isdn_sup_global_op_tab[i].oid, new_create_dissector_handle(isdn_sup_global_op_tab[i].res_pdu, proto_isdn_sup));
}
isdn_sup_err_handle = new_create_dissector_handle(dissect_isdn_sup_err, proto_isdn_sup);
for (i=0; i<(int)array_length(isdn_sup_err_tab); i++) {
dissector_add_uint("q932.ros.etsi.local.err", isdn_sup_err_tab[i].errcode, isdn_sup_err_handle);
}
}
void proto_register_isdn_sup(void) {
static hf_register_info hf[] = {
{ &hf_isdn_sup,
{ "isdn_sup", "isdn_sup.1",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isdn_sup_operation,
{ "Operation", "isdn_sup.operation",
FT_UINT8, BASE_DEC, VALS(isdn_sup_str_operation), 0x0,
NULL, HFILL }
},
{ &hf_isdn_sup_error,
{ "Error", "isdn_sup.error",
FT_UINT8, BASE_DEC, VALS(isdn_sup_str_error), 0x0,
NULL, HFILL }
},
#line 1 "../../asn1/isdn-sup/packet-isdn-sup-hfarr.c"
{ &hf_isdn_sup_ChargingRequestArg_PDU,
{ "ChargingRequestArg", "isdn-sup.ChargingRequestArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ChargingCase_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_ChargingRequestRes_PDU,
{ "ChargingRequestRes", "isdn-sup.ChargingRequestRes",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ChargingRequestRes_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCSCurrencyArg_PDU,
{ "AOCSCurrencyArg", "isdn-sup.AOCSCurrencyArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCSCurrencyArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCSSpecialArrArg_PDU,
{ "AOCSSpecialArrArg", "isdn-sup.AOCSSpecialArrArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCSSpecialArrArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCDCurrencyArg_PDU,
{ "AOCDCurrencyArg", "isdn-sup.AOCDCurrencyArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCDCurrencyArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCDChargingUnitArg_PDU,
{ "AOCDChargingUnitArg", "isdn-sup.AOCDChargingUnitArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCDChargingUnitArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCECurrencyArg_PDU,
{ "AOCECurrencyArg", "isdn-sup.AOCECurrencyArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCECurrencyArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCEChargingUnitArg_PDU,
{ "AOCEChargingUnitArg", "isdn-sup.AOCEChargingUnitArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCEChargingUnitArg_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_CUGcallArg_PDU,
{ "CUGcallArg", "isdn-sup.CUGcallArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_BeginCONFArg_PDU,
{ "BeginCONFArg", "isdn-sup.BeginCONFArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_BeginCONFRes_PDU,
{ "BeginCONFRes", "isdn-sup.BeginCONFRes",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_AddCONFArg_PDU,
{ "AddCONFArg", "isdn-sup.AddCONFArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_AddCONFRes_PDU,
{ "AddCONFRes", "isdn-sup.AddCONFRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_SplitCONFArg_PDU,
{ "SplitCONFArg", "isdn-sup.SplitCONFArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DropCONFArg_PDU,
{ "DropCONFArg", "isdn-sup.DropCONFArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_IsolateCONFArg_PDU,
{ "IsolateCONFArg", "isdn-sup.IsolateCONFArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_ReattachCONFArg_PDU,
{ "ReattachCONFArg", "isdn-sup.ReattachCONFArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_PartyDISCArg_PDU,
{ "PartyDISCArg", "isdn-sup.PartyDISCArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_ActivationDiversionArg_PDU,
{ "ActivationDiversionArg", "isdn-sup.ActivationDiversionArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DeactivationDiversionArg_PDU,
{ "DeactivationDiversionArg", "isdn-sup.DeactivationDiversionArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_ActivationStatusNotificationDivArg_PDU,
{ "ActivationStatusNotificationDivArg", "isdn-sup.ActivationStatusNotificationDivArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DeactivationStatusNotificationDivArg_PDU,
{ "DeactivationStatusNotificationDivArg", "isdn-sup.DeactivationStatusNotificationDivArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_InterrogationDiversionArg_PDU,
{ "InterrogationDiversionArg", "isdn-sup.InterrogationDiversionArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_InterrogationDiversionRes_PDU,
{ "InterrogationDiversionRes", "isdn-sup.InterrogationDiversionRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_InterrogateServedUserNumbersRes_PDU,
{ "InterrogateServedUserNumbersRes", "isdn-sup.InterrogateServedUserNumbersRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DiversionInformationArg_PDU,
{ "DiversionInformationArg", "isdn-sup.DiversionInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_CallDeflectionArg_PDU,
{ "CallDeflectionArg", "isdn-sup.CallDeflectionArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_CallRerouteingArg_PDU,
{ "CallRerouteingArg", "isdn-sup.CallRerouteingArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DivertingLegInformation1Arg_PDU,
{ "DivertingLegInformation1Arg", "isdn-sup.DivertingLegInformation1Arg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DivertingLegInformation2Arg_PDU,
{ "DivertingLegInformation2Arg", "isdn-sup.DivertingLegInformation2Arg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_DivertingLegInformation3Arg_PDU,
{ "DivertingLegInformation3Arg", "isdn-sup.DivertingLegInformation3Arg",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_UserUserServiceArg_PDU,
{ "UserUserServiceArg", "isdn-sup.UserUserServiceArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_CalledFreephoneNrArg_PDU,
{ "CalledFreephoneNrArg", "isdn-sup.CalledFreephoneNrArg",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_Monitor_T_FPHArg_PDU,
{ "Monitor-T-FPHArg", "isdn-sup.Monitor_T_FPHArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_Free_T_FPHArg_PDU,
{ "Free-T-FPHArg", "isdn-sup.Free_T_FPHArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_Call_T_FPHArg_PDU,
{ "Call-T-FPHArg", "isdn-sup.Call_T_FPHArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_presentationAllowedAddress,
{ "presentationAllowedAddress", "isdn-sup.presentationAllowedAddress",
FT_NONE, BASE_NONE, NULL, 0,
"AddressScreened", HFILL }},
{ &hf_isdn_sup_presentationRestricted,
{ "presentationRestricted", "isdn-sup.presentationRestricted",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_numberNotAvailableDueToInterworking,
{ "numberNotAvailableDueToInterworking", "isdn-sup.numberNotAvailableDueToInterworking",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_presentationRestrictedAddress,
{ "presentationRestrictedAddress", "isdn-sup.presentationRestrictedAddress",
FT_NONE, BASE_NONE, NULL, 0,
"AddressScreened", HFILL }},
{ &hf_isdn_sup_presentationAllowedAddress_01,
{ "presentationAllowedAddress", "isdn-sup.presentationAllowedAddress",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_presentationRestrictedAddress_01,
{ "presentationRestrictedAddress", "isdn-sup.presentationRestrictedAddress",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_presentationAllowedNumber,
{ "presentationAllowedNumber", "isdn-sup.presentationAllowedNumber",
FT_NONE, BASE_NONE, NULL, 0,
"NumberScreened", HFILL }},
{ &hf_isdn_sup_presentationRestrictedNumber,
{ "presentationRestrictedNumber", "isdn-sup.presentationRestrictedNumber",
FT_NONE, BASE_NONE, NULL, 0,
"NumberScreened", HFILL }},
{ &hf_isdn_sup_presentationAllowedNumber_01,
{ "presentationAllowedNumber", "isdn-sup.presentationAllowedNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_isdn_sup_presentationRestrictedNumber_01,
{ "presentationRestrictedNumber", "isdn-sup.presentationRestrictedNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_isdn_sup_partyNumber,
{ "partyNumber", "isdn-sup.partyNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_screeningIndicator,
{ "screeningIndicator", "isdn-sup.screeningIndicator",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ScreeningIndicator_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_partySubaddress,
{ "partySubaddress", "isdn-sup.partySubaddress",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartySubaddress_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_unknownPartyNumber,
{ "unknownPartyNumber", "isdn-sup.unknownPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_publicPartyNumber,
{ "publicPartyNumber", "isdn-sup.publicPartyNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_nsapEncodedNumber,
{ "nsapEncodedNumber", "isdn-sup.nsapEncodedNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_dataPartyNumber,
{ "dataPartyNumber", "isdn-sup.dataPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_telexPartyNumber,
{ "telexPartyNumber", "isdn-sup.telexPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_privatePartyNumber,
{ "privatePartyNumber", "isdn-sup.privatePartyNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_nationalStandardPartyNumber,
{ "nationalStandardPartyNumber", "isdn-sup.nationalStandardPartyNumber",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_publicTypeOfNumber,
{ "publicTypeOfNumber", "isdn-sup.publicTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PublicTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_publicNumberDigits,
{ "publicNumberDigits", "isdn-sup.publicNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_privateTypeOfNumber,
{ "privateTypeOfNumber", "isdn-sup.privateTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PrivateTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_privateNumberDigits,
{ "privateNumberDigits", "isdn-sup.privateNumberDigits",
FT_STRING, BASE_NONE, NULL, 0,
"NumberDigits", HFILL }},
{ &hf_isdn_sup_userSpecifiedSubaddress,
{ "userSpecifiedSubaddress", "isdn-sup.userSpecifiedSubaddress",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_nSAPSubaddress,
{ "nSAPSubaddress", "isdn-sup.nSAPSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_subaddressInformation,
{ "subaddressInformation", "isdn-sup.subaddressInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_oddCountIndicator,
{ "oddCountIndicator", "isdn-sup.oddCountIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_isdn_sup_aOCSCurrencyInfoList,
{ "aOCSCurrencyInfoList", "isdn-sup.aOCSCurrencyInfoList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCSSpecialArrInfo,
{ "aOCSSpecialArrInfo", "isdn-sup.aOCSSpecialArrInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargingInfoFollows,
{ "chargingInfoFollows", "isdn-sup.chargingInfoFollows",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargeNotAvailable,
{ "chargeNotAvailable", "isdn-sup.chargeNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCDCurrencyInfo,
{ "aOCDCurrencyInfo", "isdn-sup.aOCDCurrencyInfo",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCDCurrencyInfo_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCDChargingUnitInfo,
{ "aOCDChargingUnitInfo", "isdn-sup.aOCDChargingUnitInfo",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCDChargingUnitInfo_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCECurrencyInfo,
{ "aOCECurrencyInfo", "isdn-sup.aOCECurrencyInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCEChargingUnitInfo,
{ "aOCEChargingUnitInfo", "isdn-sup.aOCEChargingUnitInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_AOCSCurrencyInfoList_item,
{ "AOCSCurrencyInfo", "isdn-sup.AOCSCurrencyInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargedItem,
{ "chargedItem", "isdn-sup.chargedItem",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ChargedItem_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargingtype,
{ "chargingtype", "isdn-sup.chargingtype",
FT_UINT32, BASE_DEC, VALS(isdn_sup_T_chargingtype_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_specificCurrency,
{ "specificCurrency", "isdn-sup.specificCurrency",
FT_UINT32, BASE_DEC, VALS(isdn_sup_T_specificCurrency_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_durationCurrency,
{ "durationCurrency", "isdn-sup.durationCurrency",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_flatRateCurrency,
{ "flatRateCurrency", "isdn-sup.flatRateCurrency",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_volumeRateCurrency,
{ "volumeRateCurrency", "isdn-sup.volumeRateCurrency",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_specialChargingCode,
{ "specialChargingCode", "isdn-sup.specialChargingCode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_freeOfCharge,
{ "freeOfCharge", "isdn-sup.freeOfCharge",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_currencyInfoNotAvailable,
{ "currencyInfoNotAvailable", "isdn-sup.currencyInfoNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_dCurrency,
{ "dCurrency", "isdn-sup.dCurrency",
FT_STRING, BASE_NONE, NULL, 0,
"Currency", HFILL }},
{ &hf_isdn_sup_dAmount,
{ "dAmount", "isdn-sup.dAmount",
FT_NONE, BASE_NONE, NULL, 0,
"Amount", HFILL }},
{ &hf_isdn_sup_dChargingType,
{ "dChargingType", "isdn-sup.dChargingType",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ChargingType_vals), 0,
"ChargingType", HFILL }},
{ &hf_isdn_sup_dTime,
{ "dTime", "isdn-sup.dTime",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_isdn_sup_dGranularity,
{ "dGranularity", "isdn-sup.dGranularity",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_isdn_sup_fRCurrency,
{ "fRCurrency", "isdn-sup.fRCurrency",
FT_STRING, BASE_NONE, NULL, 0,
"Currency", HFILL }},
{ &hf_isdn_sup_fRAmount,
{ "fRAmount", "isdn-sup.fRAmount",
FT_NONE, BASE_NONE, NULL, 0,
"Amount", HFILL }},
{ &hf_isdn_sup_vRCurrency,
{ "vRCurrency", "isdn-sup.vRCurrency",
FT_STRING, BASE_NONE, NULL, 0,
"Currency", HFILL }},
{ &hf_isdn_sup_vRAmount,
{ "vRAmount", "isdn-sup.vRAmount",
FT_NONE, BASE_NONE, NULL, 0,
"Amount", HFILL }},
{ &hf_isdn_sup_vRVolumeUnit,
{ "vRVolumeUnit", "isdn-sup.vRVolumeUnit",
FT_UINT32, BASE_DEC, VALS(isdn_sup_VolumeUnit_vals), 0,
"VolumeUnit", HFILL }},
{ &hf_isdn_sup_specificCurrency_01,
{ "specificCurrency", "isdn-sup.specificCurrency",
FT_NONE, BASE_NONE, NULL, 0,
"T_specificCurrency_01", HFILL }},
{ &hf_isdn_sup_recordedCurrency,
{ "recordedCurrency", "isdn-sup.recordedCurrency",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_typeOfChargingInfo,
{ "typeOfChargingInfo", "isdn-sup.typeOfChargingInfo",
FT_UINT32, BASE_DEC, VALS(isdn_sup_TypeOfChargingInfo_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_aOCDBillingId,
{ "aOCDBillingId", "isdn-sup.aOCDBillingId",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCDBillingId_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_specificChargingUnits,
{ "specificChargingUnits", "isdn-sup.specificChargingUnits",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_recordedUnitsList,
{ "recordedUnitsList", "isdn-sup.recordedUnitsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_rCurrency,
{ "rCurrency", "isdn-sup.rCurrency",
FT_STRING, BASE_NONE, NULL, 0,
"Currency", HFILL }},
{ &hf_isdn_sup_rAmount,
{ "rAmount", "isdn-sup.rAmount",
FT_NONE, BASE_NONE, NULL, 0,
"Amount", HFILL }},
{ &hf_isdn_sup_RecordedUnitsList_item,
{ "RecordedUnits", "isdn-sup.RecordedUnits",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_cc,
{ "cc", "isdn-sup.cc",
FT_UINT32, BASE_DEC, VALS(isdn_sup_T_cc_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_recordedNumberOfUnits,
{ "recordedNumberOfUnits", "isdn-sup.recordedNumberOfUnits",
FT_UINT32, BASE_DEC, NULL, 0,
"NumberOfUnits", HFILL }},
{ &hf_isdn_sup_notAvailable,
{ "notAvailable", "isdn-sup.notAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_recordedTypeOfUnits,
{ "recordedTypeOfUnits", "isdn-sup.recordedTypeOfUnits",
FT_UINT32, BASE_DEC, NULL, 0,
"TypeOfUnit", HFILL }},
{ &hf_isdn_sup_cc_01,
{ "cc", "isdn-sup.cc",
FT_UINT32, BASE_DEC, VALS(isdn_sup_T_cc_01_vals), 0,
"T_cc_01", HFILL }},
{ &hf_isdn_sup_specificCurrency_02,
{ "specificCurrency", "isdn-sup.specificCurrency",
FT_NONE, BASE_NONE, NULL, 0,
"T_specificCurrency_02", HFILL }},
{ &hf_isdn_sup_aOCEBillingId,
{ "aOCEBillingId", "isdn-sup.aOCEBillingId",
FT_UINT32, BASE_DEC, VALS(isdn_sup_AOCEBillingId_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargingAssociation,
{ "chargingAssociation", "isdn-sup.chargingAssociation",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ChargingAssociation_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_cc_02,
{ "cc", "isdn-sup.cc",
FT_UINT32, BASE_DEC, VALS(isdn_sup_T_cc_02_vals), 0,
"T_cc_02", HFILL }},
{ &hf_isdn_sup_specificChargingUnits_01,
{ "specificChargingUnits", "isdn-sup.specificChargingUnits",
FT_NONE, BASE_NONE, NULL, 0,
"T_specificChargingUnits_01", HFILL }},
{ &hf_isdn_sup_currencyAmount,
{ "currencyAmount", "isdn-sup.currencyAmount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_multiplier,
{ "multiplier", "isdn-sup.multiplier",
FT_UINT32, BASE_DEC, VALS(isdn_sup_Multiplier_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_lengthOfTimeUnit,
{ "lengthOfTimeUnit", "isdn-sup.lengthOfTimeUnit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_scale,
{ "scale", "isdn-sup.scale",
FT_UINT32, BASE_DEC, VALS(isdn_sup_Scale_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_chargeNumber,
{ "chargeNumber", "isdn-sup.chargeNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_isdn_sup_chargeIdentifier,
{ "chargeIdentifier", "isdn-sup.chargeIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_oARequested,
{ "oARequested", "isdn-sup.oARequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_cUGIndex,
{ "cUGIndex", "isdn-sup.cUGIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_conferenceId,
{ "conferenceId", "isdn-sup.conferenceId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_partyId,
{ "partyId", "isdn-sup.partyId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_procedure,
{ "procedure", "isdn-sup.procedure",
FT_UINT32, BASE_DEC, VALS(isdn_sup_Procedure_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_basicService,
{ "basicService", "isdn-sup.basicService",
FT_UINT32, BASE_DEC, VALS(isdn_sup_BasicService_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_forwardedToAddress,
{ "forwardedToAddress", "isdn-sup.forwardedToAddress",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_servedUserNr,
{ "servedUserNr", "isdn-sup.servedUserNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_ServedUserNr_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_noReplyTimer,
{ "noReplyTimer", "isdn-sup.noReplyTimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_forwardedToAddresss,
{ "forwardedToAddresss", "isdn-sup.forwardedToAddresss",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_diversionReason,
{ "diversionReason", "isdn-sup.diversionReason",
FT_UINT32, BASE_DEC, VALS(isdn_sup_DiversionReason_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_servedUserSubaddress,
{ "servedUserSubaddress", "isdn-sup.servedUserSubaddress",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartySubaddress_vals), 0,
"PartySubaddress", HFILL }},
{ &hf_isdn_sup_callingAddress,
{ "callingAddress", "isdn-sup.callingAddress",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedAddressScreened_vals), 0,
"PresentedAddressScreened", HFILL }},
{ &hf_isdn_sup_originalCalledNr,
{ "originalCalledNr", "isdn-sup.originalCalledNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedNumberUnscreened_vals), 0,
"PresentedNumberUnscreened", HFILL }},
{ &hf_isdn_sup_lastDivertingNr,
{ "lastDivertingNr", "isdn-sup.lastDivertingNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedNumberUnscreened_vals), 0,
"PresentedNumberUnscreened", HFILL }},
{ &hf_isdn_sup_lastDivertingReason,
{ "lastDivertingReason", "isdn-sup.lastDivertingReason",
FT_UINT32, BASE_DEC, VALS(isdn_sup_DiversionReason_vals), 0,
"DiversionReason", HFILL }},
{ &hf_isdn_sup_userInfo,
{ "userInfo", "isdn-sup.userInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"Q931InformationElement", HFILL }},
{ &hf_isdn_sup_deflectionAddress,
{ "deflectionAddress", "isdn-sup.deflectionAddress",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_presentationAllowedDivertedToUser,
{ "presentationAllowedDivertedToUser", "isdn-sup.presentationAllowedDivertedToUser",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"PresentationAllowedIndicator", HFILL }},
{ &hf_isdn_sup_rerouteingReason,
{ "rerouteingReason", "isdn-sup.rerouteingReason",
FT_UINT32, BASE_DEC, VALS(isdn_sup_DiversionReason_vals), 0,
"DiversionReason", HFILL }},
{ &hf_isdn_sup_calledAddress,
{ "calledAddress", "isdn-sup.calledAddress",
FT_NONE, BASE_NONE, NULL, 0,
"Address", HFILL }},
{ &hf_isdn_sup_rerouteingCounter,
{ "rerouteingCounter", "isdn-sup.rerouteingCounter",
FT_UINT32, BASE_DEC, NULL, 0,
"DiversionCounter", HFILL }},
{ &hf_isdn_sup_q931InfoElement,
{ "q931InfoElement", "isdn-sup.q931InfoElement",
FT_BYTES, BASE_NONE, NULL, 0,
"Q931InformationElement", HFILL }},
{ &hf_isdn_sup_lastRerouteingNr,
{ "lastRerouteingNr", "isdn-sup.lastRerouteingNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedNumberUnscreened_vals), 0,
"PresentedNumberUnscreened", HFILL }},
{ &hf_isdn_sup_subscriptionOption,
{ "subscriptionOption", "isdn-sup.subscriptionOption",
FT_UINT32, BASE_DEC, VALS(isdn_sup_SubscriptionOption_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_callingPartySubaddress,
{ "callingPartySubaddress", "isdn-sup.callingPartySubaddress",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartySubaddress_vals), 0,
"PartySubaddress", HFILL }},
{ &hf_isdn_sup_divertedToNumber,
{ "divertedToNumber", "isdn-sup.divertedToNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedNumberUnscreened_vals), 0,
"PresentedNumberUnscreened", HFILL }},
{ &hf_isdn_sup_diversionCounter,
{ "diversionCounter", "isdn-sup.diversionCounter",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_divertingNr,
{ "divertingNr", "isdn-sup.divertingNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PresentedNumberUnscreened_vals), 0,
"PresentedNumberUnscreened", HFILL }},
{ &hf_isdn_sup_IntResultList_item,
{ "IntResult", "isdn-sup.IntResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_individualNumber,
{ "individualNumber", "isdn-sup.individualNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_isdn_sup_allNumbers,
{ "allNumbers", "isdn-sup.allNumbers",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_ServedUserNumberList_item,
{ "PartyNumber", "isdn-sup.PartyNumber",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_service,
{ "service", "isdn-sup.service",
FT_UINT32, BASE_DEC, VALS(isdn_sup_Service_vals), 0,
NULL, HFILL }},
{ &hf_isdn_sup_preferred,
{ "preferred", "isdn-sup.preferred",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_servedUserDestination,
{ "servedUserDestination", "isdn-sup.servedUserDestination",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_isdn_sup_queueIdentity,
{ "queueIdentity", "isdn-sup.queueIdentity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_fPHReference,
{ "fPHReference", "isdn-sup.fPHReference",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_isdn_sup_calledFreephoneNr,
{ "calledFreephoneNr", "isdn-sup.calledFreephoneNr",
FT_UINT32, BASE_DEC, VALS(isdn_sup_PartyNumber_vals), 0,
NULL, HFILL }},
#line 336 "../../asn1/isdn-sup/packet-isdn-sup-template.c"
};
static gint *ett[] = {
&ett_isdn_sup,
#line 1 "../../asn1/isdn-sup/packet-isdn-sup-ettarr.c"
&ett_isdn_sup_PresentedAddressScreened,
&ett_isdn_sup_PresentedAddressUnscreened,
&ett_isdn_sup_PresentedNumberScreened,
&ett_isdn_sup_PresentedNumberUnscreened,
&ett_isdn_sup_AddressScreened,
&ett_isdn_sup_NumberScreened,
&ett_isdn_sup_Address,
&ett_isdn_sup_PartyNumber,
&ett_isdn_sup_PublicPartyNumber,
&ett_isdn_sup_PrivatePartyNumber,
&ett_isdn_sup_PartySubaddress,
&ett_isdn_sup_UserSpecifiedSubaddress,
&ett_isdn_sup_ChargingRequestRes,
&ett_isdn_sup_AOCSCurrencyArg,
&ett_isdn_sup_AOCSSpecialArrArg,
&ett_isdn_sup_AOCDCurrencyArg,
&ett_isdn_sup_AOCDChargingUnitArg,
&ett_isdn_sup_AOCECurrencyArg,
&ett_isdn_sup_AOCEChargingUnitArg,
&ett_isdn_sup_AOCSCurrencyInfoList,
&ett_isdn_sup_AOCSCurrencyInfo,
&ett_isdn_sup_T_chargingtype,
&ett_isdn_sup_T_specificCurrency,
&ett_isdn_sup_DurationCurrency,
&ett_isdn_sup_FlatRateCurrency,
&ett_isdn_sup_VolumeRateCurrency,
&ett_isdn_sup_AOCDCurrencyInfo,
&ett_isdn_sup_T_specificCurrency_01,
&ett_isdn_sup_AOCDChargingUnitInfo,
&ett_isdn_sup_T_specificChargingUnits,
&ett_isdn_sup_RecordedCurrency,
&ett_isdn_sup_RecordedUnitsList,
&ett_isdn_sup_RecordedUnits,
&ett_isdn_sup_T_cc,
&ett_isdn_sup_AOCECurrencyInfo,
&ett_isdn_sup_T_cc_01,
&ett_isdn_sup_T_specificCurrency_02,
&ett_isdn_sup_AOCEChargingUnitInfo,
&ett_isdn_sup_T_cc_02,
&ett_isdn_sup_T_specificChargingUnits_01,
&ett_isdn_sup_Amount,
&ett_isdn_sup_Time,
&ett_isdn_sup_ChargingAssociation,
&ett_isdn_sup_CUGcallArg,
&ett_isdn_sup_BeginCONFRes,
&ett_isdn_sup_SplitCONFArg,
&ett_isdn_sup_ActivationDiversionArg,
&ett_isdn_sup_DeactivationDiversionArg,
&ett_isdn_sup_ActivationStatusNotificationDivArg,
&ett_isdn_sup_DeactivationStatusNotificationDivArg,
&ett_isdn_sup_InterrogationDiversionArg,
&ett_isdn_sup_DiversionInformationArg,
&ett_isdn_sup_CallDeflectionArg,
&ett_isdn_sup_CallRerouteingArg,
&ett_isdn_sup_DivertingLegInformation1Arg,
&ett_isdn_sup_DivertingLegInformation2Arg,
&ett_isdn_sup_IntResultList,
&ett_isdn_sup_IntResult,
&ett_isdn_sup_ServedUserNr,
&ett_isdn_sup_ServedUserNumberList,
&ett_isdn_sup_UserUserServiceArg,
&ett_isdn_sup_Monitor_T_FPHArg,
&ett_isdn_sup_Free_T_FPHArg,
&ett_isdn_sup_Call_T_FPHArg,
#line 343 "../../asn1/isdn-sup/packet-isdn-sup-template.c"
};
proto_register_field_array(proto_isdn_sup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_isdn_sup = proto_register_protocol(PNAME, PSNAME, PFNAME);
}
