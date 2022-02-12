static void dbg(guint level, char *fmt, ...) {
va_list ap;
if (level > debug_level) return;
va_start(ap,fmt);
vfprintf(stderr, fmt, ap);
va_end(ap);
}
static char camel_number_to_char(int number)
{
if (number < 10)
return (char) (number + 48 );
else
return (char) (number + 55 );
}
static guint8
dissect_RP_cause_ie(tvbuff_t *tvb, guint32 offset, _U_ guint len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value)
{
guint8 oct;
guint32 curr_offset;
static char a_bigbuf[1024];
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
*cause_value = oct & 0x7f;
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, *cause_value,
"%s : %s",
a_bigbuf,
val_to_str(*cause_value, camel_RP_Cause_values,
"Unknown Cause (%u), treated as (41) \"Temporary failure\" for MO-SMS or (111) \"Protocol error,unspecified\" for MT-SMS"));
curr_offset++;
if ((oct & 0x80)) {
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, oct,
"Diagnostic : %u", oct);
curr_offset++;
}
return(curr_offset - offset);
}
static int
dissect_camel_AccessPointName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_AccessPointName);
de_sm_apn(parameter_tvb, subtree, actx->pinfo, 0, tvb_length(parameter_tvb), NULL, 0);
return offset;
}
static int
dissect_camel_AChBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_AChBillingChargingCharacteristics);
if((camel_ver == 2)||(camel_ver == 1)){
return dissect_camel_CAMEL_AChBillingChargingCharacteristicsV2(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_AChBillingChargingCharacteristics);
}
dissect_camel_CAMEL_AChBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_AChBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_CallSegmentID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_AChChargingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AChChargingAddress_choice, hf_index, ett_camel_AChChargingAddress,
NULL);
return offset;
}
static int
dissect_camel_Digits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_AdditionalCallingPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_AlertingPattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_8191(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CAI_GSM0224(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAI_GSM0224_sequence, hf_index, ett_camel_CAI_GSM0224);
return offset;
}
static int
dissect_camel_INTEGER_1_86400(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_AOCSubsequent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCSubsequent_sequence, hf_index, ett_camel_AOCSubsequent);
return offset;
}
static int
dissect_camel_AOCBeforeAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCBeforeAnswer_sequence, hf_index, ett_camel_AOCBeforeAnswer);
return offset;
}
static int
dissect_camel_AOCGPRS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AOCGPRS_sequence, hf_index, ett_camel_AOCGPRS);
return offset;
}
static int
dissect_camel_AppendFreeFormatData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ApplicationTimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_AssistingSSPIPRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_camel_INTEGER_1_1200(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_1_3(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_1_20(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_Burst(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Burst_sequence, hf_index, ett_camel_Burst);
return offset;
}
static int
dissect_camel_BurstList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BurstList_sequence, hf_index, ett_camel_BurstList);
return offset;
}
static int
dissect_camel_AudibleIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AudibleIndicator_choice, hf_index, ett_camel_AudibleIndicator,
NULL);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_BackwardServiceInteractionInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BackwardServiceInteractionInd_sequence, hf_index, ett_camel_BackwardServiceInteractionInd);
return offset;
}
static int
dissect_camel_GapOnService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GapOnService_sequence, hf_index, ett_camel_GapOnService);
return offset;
}
static int
dissect_camel_T_calledAddressAndService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_calledAddressAndService_sequence, hf_index, ett_camel_T_calledAddressAndService);
return offset;
}
static int
dissect_camel_T_callingAddressAndService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callingAddressAndService_sequence, hf_index, ett_camel_T_callingAddressAndService);
return offset;
}
static int
dissect_camel_BasicGapCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BasicGapCriteria_choice, hf_index, ett_camel_BasicGapCriteria,
NULL);
return offset;
}
static int
dissect_camel_EventTypeBCSM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_MonitorMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_1_30(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_1_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_1_127(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_MidCallControlInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MidCallControlInfo_sequence, hf_index, ett_camel_MidCallControlInfo);
return offset;
}
static int
dissect_camel_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_camel_ChangeOfLocationAlt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfLocationAlt_sequence, hf_index, ett_camel_ChangeOfLocationAlt);
return offset;
}
static int
dissect_camel_ChangeOfLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChangeOfLocation_choice, hf_index, ett_camel_ChangeOfLocation,
NULL);
return offset;
}
static int
dissect_camel_ChangeOfPositionControlInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ChangeOfPositionControlInfo_sequence_of, hf_index, ett_camel_ChangeOfPositionControlInfo);
return offset;
}
static int
dissect_camel_NumberOfDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_DpSpecificCriteriaAlt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DpSpecificCriteriaAlt_sequence, hf_index, ett_camel_DpSpecificCriteriaAlt);
return offset;
}
static int
dissect_camel_DpSpecificCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DpSpecificCriteria_choice, hf_index, ett_camel_DpSpecificCriteria,
NULL);
return offset;
}
static int
dissect_camel_BCSMEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BCSMEvent_sequence, hf_index, ett_camel_BCSMEvent);
return offset;
}
static int
dissect_camel_Cause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
guint8 Cause_value;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_cause);
dissect_q931_cause_ie(parameter_tvb, 0, tvb_length_remaining(parameter_tvb,0), subtree, hf_camel_cause_indicator, &Cause_value, isup_parameter_type_value);
return offset;
}
static int
dissect_camel_BCSM_Failure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BCSM_Failure_sequence, hf_index, ett_camel_BCSM_Failure);
return offset;
}
static int
dissect_camel_T_bearerCap(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_q931_bearer_capability_ie(parameter_tvb, 0, tvb_length_remaining(parameter_tvb,0), tree);
return offset;
}
static int
dissect_camel_BearerCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BearerCapability_choice, hf_index, ett_camel_BearerCapability,
NULL);
return offset;
}
static int
dissect_camel_CalledPartyBCDNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_calledpartybcdnumber);
de_cld_party_bcd_num(parameter_tvb, subtree, actx->pinfo, 0, tvb_length(parameter_tvb), NULL, 0);
return offset;
}
static int
dissect_camel_CalledPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_calledpartybcdnumber);
dissect_isup_called_party_number_parameter(parameter_tvb, subtree, NULL);
return offset;
}
static int
dissect_camel_CallingPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_callingpartynumber);
dissect_isup_calling_party_number_parameter(parameter_tvb, subtree, NULL);
return offset;
}
static int
dissect_camel_CallResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_CallResult);
dissect_camel_CAMEL_CallResult(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_CallResult);
return offset;
}
static int
dissect_camel_CallSegmentFailure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallSegmentFailure_sequence, hf_index, ett_camel_CallSegmentFailure);
return offset;
}
static int
dissect_camel_InvokeID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CallSegmentToCancel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallSegmentToCancel_sequence, hf_index, ett_camel_CallSegmentToCancel);
return offset;
}
static int
dissect_camel_INTEGER_1_864000(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_audibleIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if (tvb_length_remaining(tvb,offset) < 2)
offset = dissect_camel_BOOLEAN(TRUE, tvb, offset, actx , tree, hf_camel_audibleIndicatorTone);
else
offset = dissect_camel_AudibleIndicator(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_T_local(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if (is_ExtensionField){
hf_index = hf_camel_extension_code_local;
}else if (camel_opcode_type == CAMEL_OPCODE_RETURN_ERROR){
hf_index = hf_camel_error_code_local;
}
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
if (is_ExtensionField == FALSE){
if (camel_opcode_type == CAMEL_OPCODE_RETURN_ERROR){
errorCode = opcode;
col_append_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(errorCode, camel_err_code_string_vals, "Unknown CAMEL error (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
}else{
col_append_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(opcode, camel_opr_code_strings, "Unknown CAMEL (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
}
gp_camelsrt_info->opcode=opcode;
}
return offset;
}
static int
dissect_camel_T_global(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &camel_obj_id);
return offset;
}
static int
dissect_camel_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Code_choice, hf_index, ett_camel_Code,
NULL);
return offset;
}
static int
dissect_camel_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(camel_obj_id){
offset=call_ber_oid_callback(camel_obj_id, tvb, offset, actx->pinfo, tree, NULL);
}
is_ExtensionField = FALSE;
return offset;
}
static int
dissect_camel_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
camel_obj_id = NULL;
is_ExtensionField =TRUE;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtensionField_sequence, hf_index, ett_camel_ExtensionField);
return offset;
}
static int
dissect_camel_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Extensions_sequence_of, hf_index, ett_camel_Extensions);
return offset;
}
static int
dissect_camel_T_timeDurationCharging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_timeDurationCharging_sequence, hf_index, ett_camel_T_timeDurationCharging);
return offset;
}
static int
dissect_camel_CAMEL_AChBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_AChBillingChargingCharacteristics_choice, hf_index, ett_camel_CAMEL_AChBillingChargingCharacteristics,
NULL);
return offset;
}
static int
dissect_camel_LegType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ReceivingSideID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReceivingSideID_choice, hf_index, ett_camel_ReceivingSideID,
NULL);
return offset;
}
static int
dissect_camel_TimeIfNoTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_864000(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_TimeIfTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeIfTariffSwitch_sequence, hf_index, ett_camel_TimeIfTariffSwitch);
return offset;
}
static int
dissect_camel_TimeInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TimeInformation_choice, hf_index, ett_camel_TimeInformation,
NULL);
return offset;
}
static int
dissect_camel_T_timeDurationChargingResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_timeDurationChargingResult_sequence, hf_index, ett_camel_T_timeDurationChargingResult);
return offset;
}
static int
dissect_camel_CAMEL_CallResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_CallResult_choice, hf_index, ett_camel_CAMEL_CallResult,
NULL);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_bound__minFCIBillingChargingDataLength_bound__maxFCIBillingChargingDataLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_SendingSideID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SendingSideID_choice, hf_index, ett_camel_SendingSideID,
NULL);
return offset;
}
static int
dissect_camel_T_fci_fCIBCCCAMELsequence1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_fci_fCIBCCCAMELsequence1_sequence, hf_index, ett_camel_T_fci_fCIBCCCAMELsequence1);
return offset;
}
static int
dissect_camel_CAMEL_FCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_FCIBillingChargingCharacteristics_choice, hf_index, ett_camel_CAMEL_FCIBillingChargingCharacteristics,
NULL);
return offset;
}
static int
dissect_camel_PDPID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_fciGPRS_fCIBCCCAMELsequence1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_fciGPRS_fCIBCCCAMELsequence1_sequence, hf_index, ett_camel_T_fciGPRS_fCIBCCCAMELsequence1);
return offset;
}
static int
dissect_camel_CAMEL_FCIGPRSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAMEL_FCIGPRSBillingChargingCharacteristics_sequence, hf_index, ett_camel_CAMEL_FCIGPRSBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_T_fciSMS_fCIBCCCAMELsequence1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_fciSMS_fCIBCCCAMELsequence1_sequence, hf_index, ett_camel_T_fciSMS_fCIBCCCAMELsequence1);
return offset;
}
static int
dissect_camel_CAMEL_FCISMSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_FCISMSBillingChargingCharacteristics_choice, hf_index, ett_camel_CAMEL_FCISMSBillingChargingCharacteristics,
NULL);
return offset;
}
static int
dissect_camel_CAMEL_SCIBillingChargingCharacteristicsAlt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAMEL_SCIBillingChargingCharacteristicsAlt_sequence, hf_index, ett_camel_CAMEL_SCIBillingChargingCharacteristicsAlt);
return offset;
}
static int
dissect_camel_CAMEL_SCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_SCIBillingChargingCharacteristics_choice, hf_index, ett_camel_CAMEL_SCIBillingChargingCharacteristics,
NULL);
return offset;
}
static int
dissect_camel_CAMEL_SCIGPRSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAMEL_SCIGPRSBillingChargingCharacteristics_sequence, hf_index, ett_camel_CAMEL_SCIGPRSBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_Carrier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CGEncountered(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ChargeIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_LocationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_locationnumber);
dissect_isup_location_number_parameter(parameter_tvb, subtree, NULL);
return offset;
}
static int
dissect_camel_ChargeNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_INTEGER_1_4294967295(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingCharacteristics_choice, hf_index, ett_camel_ChargingCharacteristics,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_4294967295(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_volumeIfTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_volumeIfTariffSwitch_sequence, hf_index, ett_camel_T_volumeIfTariffSwitch);
return offset;
}
static int
dissect_camel_TransferredVolume(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TransferredVolume_choice, hf_index, ett_camel_TransferredVolume,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_86400(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_timeGPRSIfTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_timeGPRSIfTariffSwitch_sequence, hf_index, ett_camel_T_timeGPRSIfTariffSwitch);
return offset;
}
static int
dissect_camel_ElapsedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ElapsedTime_choice, hf_index, ett_camel_ElapsedTime,
NULL);
return offset;
}
static int
dissect_camel_ChargingResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingResult_choice, hf_index, ett_camel_ChargingResult,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_255(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_rO_VolumeIfTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_rO_VolumeIfTariffSwitch_sequence, hf_index, ett_camel_T_rO_VolumeIfTariffSwitch);
return offset;
}
static int
dissect_camel_TransferredVolumeRollOver(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TransferredVolumeRollOver_choice, hf_index, ett_camel_TransferredVolumeRollOver,
NULL);
return offset;
}
static int
dissect_camel_T_rO_TimeGPRSIfTariffSwitch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_rO_TimeGPRSIfTariffSwitch_sequence, hf_index, ett_camel_T_rO_TimeGPRSIfTariffSwitch);
return offset;
}
static int
dissect_camel_ElapsedTimeRollOver(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ElapsedTimeRollOver_choice, hf_index, ett_camel_ElapsedTimeRollOver,
NULL);
return offset;
}
static int
dissect_camel_ChargingRollOver(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChargingRollOver_choice, hf_index, ett_camel_ChargingRollOver,
NULL);
return offset;
}
static int
dissect_camel_ErrorTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CollectedDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CollectedDigits_sequence, hf_index, ett_camel_CollectedDigits);
return offset;
}
static int
dissect_camel_CollectedInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CollectedInfo_choice, hf_index, ett_camel_CollectedInfo,
NULL);
return offset;
}
static int
dissect_camel_ConnectedNumberTreatmentInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ControlType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ScfID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CompoundCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompoundCriteria_sequence, hf_index, ett_camel_CompoundCriteria);
return offset;
}
static int
dissect_camel_CorrelationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_DateAndTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint8 digit_pair;
guint8 i = 0, curr_offset;
char camel_time[CAMEL_DATE_AND_TIME_LEN];
char c[CAMEL_DATE_AND_TIME_LEN];
for (curr_offset = 0; curr_offset < 7 ; curr_offset++)
{
digit_pair = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(tree,
hf_digit,
tvb,
curr_offset,
1,
digit_pair & 0x0F);
proto_tree_add_uint(tree,
hf_digit,
tvb,
curr_offset,
1,
digit_pair >>4);
c[i] = camel_number_to_char( digit_pair & 0x0F);
i++;
c[i] = camel_number_to_char( digit_pair >>4);
i++;
}
camel_time[0] = c[8];
camel_time[1] = c[9];
camel_time[2] = ':';
camel_time[3] = c[10];
camel_time[4] = c[11];
camel_time[5] = ':';
camel_time[6] = c[12];
camel_time[7] = c[13];
camel_time[8] = ';';
if ( EUROPEAN_DATE == date_format)
{
camel_time[9] = c[6];
camel_time[10] = c[7];
camel_time[11] = '/';
camel_time[12] = c[4];
camel_time[13] = c[5];
}
else
{
camel_time[9] = c[4];
camel_time[10] = c[5];
camel_time[11] = '/';
camel_time[12] = c[6];
camel_time[13] = c[7];
}
camel_time[14] = '/';
camel_time[15] = c[0];
camel_time[16] = c[1];
camel_time[17] = c[2];
camel_time[18] = c[3];
camel_time[CAMEL_DATE_AND_TIME_LEN - 1] = '\0';
proto_tree_add_string(tree,
hf_index,
tvb,
0,
7,
camel_time);
return 7;
return offset;
}
static int
dissect_camel_DestinationRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DestinationRoutingAddress_sequence_of, hf_index, ett_camel_DestinationRoutingAddress);
return offset;
}
static int
dissect_camel_InitiatorOfServiceChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_NatureOfServiceChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_oServiceChangeSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oServiceChangeSpecificInfo_sequence, hf_index, ett_camel_T_oServiceChangeSpecificInfo);
return offset;
}
static int
dissect_camel_T_tServiceChangeSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tServiceChangeSpecificInfo_sequence, hf_index, ett_camel_T_tServiceChangeSpecificInfo);
return offset;
}
static int
dissect_camel_T_collectedInfoSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_collectedInfoSpecificInfo_sequence, hf_index, ett_camel_T_collectedInfoSpecificInfo);
return offset;
}
static int
dissect_camel_DpSpecificInfoAlt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DpSpecificInfoAlt_sequence, hf_index, ett_camel_DpSpecificInfoAlt);
return offset;
}
static int
dissect_camel_T_pDPTypeOrganization(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
PDPTypeOrganization = (tvb_get_guint8(parameter_tvb,0) &0x0f);
return offset;
}
static int
dissect_camel_T_pDPTypeNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
PDPTypeNumber = tvb_get_guint8(parameter_tvb,0);
subtree = proto_item_add_subtree(actx->created_item, ett_camel_pdptypenumber);
switch (PDPTypeOrganization){
case 0:
proto_tree_add_item(subtree, hf_camel_PDPTypeNumber_etsi, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(subtree, hf_camel_PDPTypeNumber_ietf, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
return offset;
}
static int
dissect_camel_T_pDPAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_pdptypenumber);
switch (PDPTypeOrganization){
case 0:
break;
case 1:
switch(PDPTypeNumber){
case 0x21:
proto_tree_add_item(subtree, hf_camel_PDPAddress_IPv4, parameter_tvb, 0, tvb_length(parameter_tvb), ENC_BIG_ENDIAN);
break;
case 0x57:
proto_tree_add_item(subtree, hf_camel_PDPAddress_IPv6, parameter_tvb, 0, tvb_length(parameter_tvb), ENC_NA);
break;
default:
break;
}
default:
break;
}
return offset;
}
static int
dissect_camel_EndUserAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EndUserAddress_sequence, hf_index, ett_camel_EndUserAddress);
return offset;
}
static int
dissect_camel_T_routeSelectFailureSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_routeSelectFailureSpecificInfo_sequence, hf_index, ett_camel_T_routeSelectFailureSpecificInfo);
return offset;
}
static int
dissect_camel_T_oCalledPartyBusySpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oCalledPartyBusySpecificInfo_sequence, hf_index, ett_camel_T_oCalledPartyBusySpecificInfo);
return offset;
}
static int
dissect_camel_T_oNoAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oNoAnswerSpecificInfo_sequence, hf_index, ett_camel_T_oNoAnswerSpecificInfo);
return offset;
}
static int
dissect_camel_T_oAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oAnswerSpecificInfo_sequence, hf_index, ett_camel_T_oAnswerSpecificInfo);
return offset;
}
static int
dissect_camel_T_omidCallEvents(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_omidCallEvents_choice, hf_index, ett_camel_T_omidCallEvents,
NULL);
return offset;
}
static int
dissect_camel_T_oMidCallSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oMidCallSpecificInfo_sequence, hf_index, ett_camel_T_oMidCallSpecificInfo);
return offset;
}
static int
dissect_camel_T_oDisconnectSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oDisconnectSpecificInfo_sequence, hf_index, ett_camel_T_oDisconnectSpecificInfo);
return offset;
}
static int
dissect_camel_T_tBusySpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tBusySpecificInfo_sequence, hf_index, ett_camel_T_tBusySpecificInfo);
return offset;
}
static int
dissect_camel_T_tNoAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tNoAnswerSpecificInfo_sequence, hf_index, ett_camel_T_tNoAnswerSpecificInfo);
return offset;
}
static int
dissect_camel_T_tAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tAnswerSpecificInfo_sequence, hf_index, ett_camel_T_tAnswerSpecificInfo);
return offset;
}
static int
dissect_camel_T_tmidCallEvents(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_tmidCallEvents_choice, hf_index, ett_camel_T_tmidCallEvents,
NULL);
return offset;
}
static int
dissect_camel_T_tMidCallSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tMidCallSpecificInfo_sequence, hf_index, ett_camel_T_tMidCallSpecificInfo);
return offset;
}
static int
dissect_camel_T_tDisconnectSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tDisconnectSpecificInfo_sequence, hf_index, ett_camel_T_tDisconnectSpecificInfo);
return offset;
}
static int
dissect_camel_T_oTermSeizedSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oTermSeizedSpecificInfo_sequence, hf_index, ett_camel_T_oTermSeizedSpecificInfo);
return offset;
}
static int
dissect_camel_T_callAcceptedSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callAcceptedSpecificInfo_sequence, hf_index, ett_camel_T_callAcceptedSpecificInfo);
return offset;
}
static int
dissect_camel_T_oAbandonSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oAbandonSpecificInfo_sequence, hf_index, ett_camel_T_oAbandonSpecificInfo);
return offset;
}
static int
dissect_camel_MetDPCriterionAlt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MetDPCriterionAlt_sequence, hf_index, ett_camel_MetDPCriterionAlt);
return offset;
}
static int
dissect_camel_MetDPCriterion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MetDPCriterion_choice, hf_index, ett_camel_MetDPCriterion,
NULL);
return offset;
}
static int
dissect_camel_MetDPCriteriaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
MetDPCriteriaList_sequence_of, hf_index, ett_camel_MetDPCriteriaList);
return offset;
}
static int
dissect_camel_T_oChangeOfPositionSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oChangeOfPositionSpecificInfo_sequence, hf_index, ett_camel_T_oChangeOfPositionSpecificInfo);
return offset;
}
static int
dissect_camel_T_tChangeOfPositionSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tChangeOfPositionSpecificInfo_sequence, hf_index, ett_camel_T_tChangeOfPositionSpecificInfo);
return offset;
}
static int
dissect_camel_EventSpecificInformationBCSM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventSpecificInformationBCSM_choice, hf_index, ett_camel_EventSpecificInformationBCSM,
NULL);
return offset;
}
static int
dissect_camel_MO_SMSCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_o_smsFailureSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_o_smsFailureSpecificInfo_sequence, hf_index, ett_camel_T_o_smsFailureSpecificInfo);
return offset;
}
static int
dissect_camel_T_o_smsSubmissionSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_o_smsSubmissionSpecificInfo_sequence, hf_index, ett_camel_T_o_smsSubmissionSpecificInfo);
return offset;
}
static int
dissect_camel_MT_SMSCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_t_smsFailureSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_t_smsFailureSpecificInfo_sequence, hf_index, ett_camel_T_t_smsFailureSpecificInfo);
return offset;
}
static int
dissect_camel_T_t_smsDeliverySpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_t_smsDeliverySpecificInfo_sequence, hf_index, ett_camel_T_t_smsDeliverySpecificInfo);
return offset;
}
static int
dissect_camel_EventSpecificInformationSMS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventSpecificInformationSMS_choice, hf_index, ett_camel_EventSpecificInformationSMS,
NULL);
return offset;
}
static int
dissect_camel_EventTypeSMS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_FCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_FCIBillingChargingCharacteristics);
dissect_camel_CAMEL_FCIBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_FCIBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_FCIGPRSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_FCIGPRSBillingChargingCharacteristics);
dissect_camel_CAMEL_FCIGPRSBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_FCIGPRSBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_FCISMSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_FCISMSBillingChargingCharacteristics);
dissect_camel_CAMEL_FCISMSBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_FCISMSBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_ForwardServiceInteractionInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ForwardServiceInteractionInd_sequence, hf_index, ett_camel_ForwardServiceInteractionInd);
return offset;
}
static int
dissect_camel_GapCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GapCriteria_choice, hf_index, ett_camel_GapCriteria,
NULL);
return offset;
}
static int
dissect_camel_GapIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GapIndicators_sequence, hf_index, ett_camel_GapIndicators);
return offset;
}
static int
dissect_camel_IA5String_SIZE_bound__minMessageContentLength_bound__maxMessageContentLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_bound__minAttributesLength_bound__maxAttributesLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_text(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_text_sequence, hf_index, ett_camel_T_text);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_bound__numOfMessageIDs_OF_Integer4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_bound__numOfMessageIDs_OF_Integer4_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_bound__numOfMessageIDs_OF_Integer4);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_OCTET_STRING_SIZE_4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_VariablePart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
VariablePart_choice, hf_index, ett_camel_VariablePart,
NULL);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_5_OF_VariablePart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_5_OF_VariablePart_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_5_OF_VariablePart);
return offset;
}
static int
dissect_camel_T_variableMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_variableMessage_sequence, hf_index, ett_camel_T_variableMessage);
return offset;
}
static int
dissect_camel_MessageID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MessageID_choice, hf_index, ett_camel_MessageID,
NULL);
return offset;
}
static int
dissect_camel_INTEGER_0_32767(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_InbandInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InbandInfo_sequence, hf_index, ett_camel_InbandInfo);
return offset;
}
static int
dissect_camel_Tone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Tone_sequence, hf_index, ett_camel_Tone);
return offset;
}
static int
dissect_camel_InformationToSend(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InformationToSend_choice, hf_index, ett_camel_InformationToSend,
NULL);
return offset;
}
static int
dissect_camel_GapTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GapTreatment_choice, hf_index, ett_camel_GapTreatment,
NULL);
return offset;
}
static int
dissect_camel_GenericNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_generic_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_camel_GenericNumbers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
GenericNumbers_set_of, hf_index, ett_camel_GenericNumbers);
return offset;
}
static int
dissect_camel_GPRS_QoS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GPRS_QoS_choice, hf_index, ett_camel_GPRS_QoS,
NULL);
return offset;
}
static int
dissect_camel_GPRS_QoS_Extension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GPRS_QoS_Extension_sequence, hf_index, ett_camel_GPRS_QoS_Extension);
return offset;
}
static int
dissect_camel_GPRSCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_GPRSEventType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_GPRSEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GPRSEvent_sequence, hf_index, ett_camel_GPRSEvent);
return offset;
}
static int
dissect_camel_T_cellGlobalIdOrServiceAreaIdOrLAI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
proto_tree *subtree;
int start_offset;
start_offset = offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
subtree = proto_item_add_subtree(actx->created_item, ett_camel_pdptypenumber);
if (tvb_reported_length_remaining(tvb,start_offset) == 7){
dissect_gsm_map_CellGlobalIdOrServiceAreaIdFixedLength(TRUE, tvb, start_offset, actx, subtree, hf_camel_cellGlobalIdOrServiceAreaIdFixedLength);
}else{
dissect_gsm_map_LAIFixedLength(TRUE, tvb, start_offset, actx, subtree, hf_camel_locationAreaId);
}
return offset;
}
static int
dissect_camel_UserCSGInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_LocationInformationGPRS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LocationInformationGPRS_sequence, hf_index, ett_camel_LocationInformationGPRS);
return offset;
}
static int
dissect_camel_T_attachChangeOfPositionSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_attachChangeOfPositionSpecificInformation_sequence, hf_index, ett_camel_T_attachChangeOfPositionSpecificInformation);
return offset;
}
static int
dissect_camel_QualityOfService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
QualityOfService_sequence, hf_index, ett_camel_QualityOfService);
return offset;
}
static int
dissect_camel_TimeAndTimezone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_pdp_ContextchangeOfPositionSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_pdp_ContextchangeOfPositionSpecificInformation_sequence, hf_index, ett_camel_T_pdp_ContextchangeOfPositionSpecificInformation);
return offset;
}
static int
dissect_camel_InitiatingEntity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_detachSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_detachSpecificInformation_sequence, hf_index, ett_camel_T_detachSpecificInformation);
return offset;
}
static int
dissect_camel_T_disconnectSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_disconnectSpecificInformation_sequence, hf_index, ett_camel_T_disconnectSpecificInformation);
return offset;
}
static int
dissect_camel_PDPInitiationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_pDPContextEstablishmentSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_pDPContextEstablishmentSpecificInformation_sequence, hf_index, ett_camel_T_pDPContextEstablishmentSpecificInformation);
return offset;
}
static int
dissect_camel_T_pDPContextEstablishmentAcknowledgementSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_pDPContextEstablishmentAcknowledgementSpecificInformation_sequence, hf_index, ett_camel_T_pDPContextEstablishmentAcknowledgementSpecificInformation);
return offset;
}
static int
dissect_camel_GPRSEventSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GPRSEventSpecificInformation_choice, hf_index, ett_camel_GPRSEventSpecificInformation,
NULL);
return offset;
}
static int
dissect_camel_IPRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_CalledPartyNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_IPSSPCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_LegOrCallSegment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LegOrCallSegment_choice, hf_index, ett_camel_LegOrCallSegment,
NULL);
return offset;
}
static int
dissect_camel_LowLayerCompatibility(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_NAOliInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_OCSIApplicable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_camel_OriginalCalledPartyID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_original_called_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_camel_RedirectingPartyID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_redirecting_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_camel_RequestedInformationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_RequestedInformationValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestedInformationValue_choice, hf_index, ett_camel_RequestedInformationValue,
NULL);
return offset;
}
static int
dissect_camel_RequestedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestedInformation_sequence, hf_index, ett_camel_RequestedInformation);
return offset;
}
static int
dissect_camel_RequestedInformationList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestedInformationList_sequence_of, hf_index, ett_camel_RequestedInformationList);
return offset;
}
static int
dissect_camel_RequestedInformationTypeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestedInformationTypeList_sequence_of, hf_index, ett_camel_RequestedInformationTypeList);
return offset;
}
static int
dissect_camel_RPCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
guint8 Cause_value;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_RPcause);
dissect_RP_cause_ie(parameter_tvb, 0, tvb_length_remaining(parameter_tvb,0), subtree, hf_camel_RP_Cause, &Cause_value);
return offset;
}
static int
dissect_camel_SCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_SCIBillingChargingCharacteristics);
dissect_camel_CAMEL_SCIBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_SCIBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_SCIGPRSBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_camel_CAMEL_SCIGPRSBillingChargingCharacteristics);
dissect_camel_CAMEL_SCIGPRSBillingChargingCharacteristics(FALSE, parameter_tvb, 0, actx, subtree, hf_camel_CAMEL_SCIGPRSBillingChargingCharacteristics);
return offset;
}
static int
dissect_camel_ServiceInteractionIndicatorsTwo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceInteractionIndicatorsTwo_sequence, hf_index, ett_camel_ServiceInteractionIndicatorsTwo);
return offset;
}
static int
dissect_camel_SGSNCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_SMS_AddressString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_SMSEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SMSEvent_sequence, hf_index, ett_camel_SMSEvent);
return offset;
}
static int
dissect_camel_TimerID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_TimerValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Integer4(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_TPDataCodingScheme(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_TPProtocolIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_TPShortMessageSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_TPValidityPeriod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_UnavailableNetworkResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_par_cancelFailedProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_PAR_cancelFailed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PAR_cancelFailed_sequence, hf_index, ett_camel_PAR_cancelFailed);
return offset;
}
static int
dissect_camel_PAR_requestedInfoError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_PAR_taskRefused(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_CAP_GPRS_ReferenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAP_GPRS_ReferenceNumber_sequence, hf_index, ett_camel_CAP_GPRS_ReferenceNumber);
return offset;
}
static int
dissect_camel_PlayAnnouncementArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PlayAnnouncementArg_sequence, hf_index, ett_camel_PlayAnnouncementArg);
return offset;
}
static int
dissect_camel_PromptAndCollectUserInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PromptAndCollectUserInformationArg_sequence, hf_index, ett_camel_PromptAndCollectUserInformationArg);
return offset;
}
static int
dissect_camel_ReceivedInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReceivedInformationArg_choice, hf_index, ett_camel_ReceivedInformationArg,
NULL);
return offset;
}
static int
dissect_camel_SpecializedResourceReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SpecializedResourceReportArg_choice, hf_index, ett_camel_SpecializedResourceReportArg,
NULL);
return offset;
}
static int
dissect_camel_ApplyChargingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ApplyChargingArg_sequence, hf_index, ett_camel_ApplyChargingArg);
return offset;
}
static int
dissect_camel_ApplyChargingReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_CallResult(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_AssistRequestInstructionsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AssistRequestInstructionsArg_sequence, hf_index, ett_camel_AssistRequestInstructionsArg);
return offset;
}
static int
dissect_camel_CallGapArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallGapArg_sequence, hf_index, ett_camel_CallGapArg);
return offset;
}
static int
dissect_camel_CallInformationReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallInformationReportArg_sequence, hf_index, ett_camel_CallInformationReportArg);
return offset;
}
static int
dissect_camel_CallInformationRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallInformationRequestArg_sequence, hf_index, ett_camel_CallInformationRequestArg);
return offset;
}
static int
dissect_camel_CancelArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CancelArg_choice, hf_index, ett_camel_CancelArg,
NULL);
return offset;
}
static int
dissect_camel_CollectInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CollectInformationArg_sequence, hf_index, ett_camel_CollectInformationArg);
return offset;
}
static int
dissect_camel_ConnectArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectArg_sequence, hf_index, ett_camel_ConnectArg);
return offset;
}
static int
dissect_camel_T_resourceAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_resourceAddress_choice, hf_index, ett_camel_T_resourceAddress,
NULL);
return offset;
}
static int
dissect_camel_ConnectToResourceArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectToResourceArg_sequence, hf_index, ett_camel_ConnectToResourceArg);
return offset;
}
static int
dissect_camel_ContinueWithArgumentArgExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContinueWithArgumentArgExtension_sequence, hf_index, ett_camel_ContinueWithArgumentArgExtension);
return offset;
}
static int
dissect_camel_ContinueWithArgumentArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContinueWithArgumentArg_sequence, hf_index, ett_camel_ContinueWithArgumentArg);
return offset;
}
static int
dissect_camel_DisconnectForwardConnectionWithArgumentArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DisconnectForwardConnectionWithArgumentArg_sequence, hf_index, ett_camel_DisconnectForwardConnectionWithArgumentArg);
return offset;
}
static int
dissect_camel_DisconnectLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DisconnectLegArg_sequence, hf_index, ett_camel_DisconnectLegArg);
return offset;
}
static int
dissect_camel_EntityReleasedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EntityReleasedArg_choice, hf_index, ett_camel_EntityReleasedArg,
NULL);
return offset;
}
static int
dissect_camel_EstablishTemporaryConnectionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EstablishTemporaryConnectionArg_sequence, hf_index, ett_camel_EstablishTemporaryConnectionArg);
return offset;
}
static int
dissect_camel_EventReportBCSMArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventReportBCSMArg_sequence, hf_index, ett_camel_EventReportBCSMArg);
return offset;
}
static int
dissect_camel_FurnishChargingInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_FCIBillingChargingCharacteristics(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_InitialDPArgExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if((camel_ver == 2)||(camel_ver == 1)){
return dissect_camel_InitialDPArgExtensionV2(implicit_tag, tvb, offset, actx, tree, hf_index);
}
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPArgExtension_sequence, hf_index, ett_camel_InitialDPArgExtension);
return offset;
}
static int
dissect_camel_InitialDPArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPArg_sequence, hf_index, ett_camel_InitialDPArg);
return offset;
}
static int
dissect_camel_InitiateCallAttemptArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitiateCallAttemptArg_sequence, hf_index, ett_camel_InitiateCallAttemptArg);
return offset;
}
static int
dissect_camel_InitiateCallAttemptRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitiateCallAttemptRes_sequence, hf_index, ett_camel_InitiateCallAttemptRes);
return offset;
}
static int
dissect_camel_MoveLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MoveLegArg_sequence, hf_index, ett_camel_MoveLegArg);
return offset;
}
static int
dissect_camel_PlayToneArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PlayToneArg_sequence, hf_index, ett_camel_PlayToneArg);
return offset;
}
static int
dissect_camel_AllCallSegments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_Cause(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_AllCallSegmentsWithExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AllCallSegmentsWithExtension_sequence, hf_index, ett_camel_AllCallSegmentsWithExtension);
return offset;
}
static int
dissect_camel_ReleaseCallArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReleaseCallArg_choice, hf_index, ett_camel_ReleaseCallArg,
NULL);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_bound__numOfBCSMEvents_OF_BCSMEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_bound__numOfBCSMEvents_OF_BCSMEvent_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_bound__numOfBCSMEvents_OF_BCSMEvent);
return offset;
}
static int
dissect_camel_RequestReportBCSMEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportBCSMEventArg_sequence, hf_index, ett_camel_RequestReportBCSMEventArg);
return offset;
}
static int
dissect_camel_ResetTimerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ResetTimerArg_sequence, hf_index, ett_camel_ResetTimerArg);
return offset;
}
static int
dissect_camel_SendChargingInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SendChargingInformationArg_sequence, hf_index, ett_camel_SendChargingInformationArg);
return offset;
}
static int
dissect_camel_SplitLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SplitLegArg_sequence, hf_index, ett_camel_SplitLegArg);
return offset;
}
static int
dissect_camel_ApplyChargingGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ApplyChargingGPRSArg_sequence, hf_index, ett_camel_ApplyChargingGPRSArg);
return offset;
}
static int
dissect_camel_ApplyChargingReportGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ApplyChargingReportGPRSArg_sequence, hf_index, ett_camel_ApplyChargingReportGPRSArg);
return offset;
}
static int
dissect_camel_CancelGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CancelGPRSArg_sequence, hf_index, ett_camel_CancelGPRSArg);
return offset;
}
static int
dissect_camel_ConnectGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectGPRSArg_sequence, hf_index, ett_camel_ConnectGPRSArg);
return offset;
}
static int
dissect_camel_ContinueGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContinueGPRSArg_sequence, hf_index, ett_camel_ContinueGPRSArg);
return offset;
}
static int
dissect_camel_EntityReleasedGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EntityReleasedGPRSArg_sequence, hf_index, ett_camel_EntityReleasedGPRSArg);
return offset;
}
static int
dissect_camel_EventReportGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventReportGPRSArg_sequence, hf_index, ett_camel_EventReportGPRSArg);
return offset;
}
static int
dissect_camel_FurnishChargingInformationGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_FCIGPRSBillingChargingCharacteristics(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_InitialDPGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPGPRSArg_sequence, hf_index, ett_camel_InitialDPGPRSArg);
return offset;
}
static int
dissect_camel_ReleaseGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReleaseGPRSArg_sequence, hf_index, ett_camel_ReleaseGPRSArg);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_bound__numOfGPRSEvents_OF_GPRSEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_bound__numOfGPRSEvents_OF_GPRSEvent_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_bound__numOfGPRSEvents_OF_GPRSEvent);
return offset;
}
static int
dissect_camel_RequestReportGPRSEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportGPRSEventArg_sequence, hf_index, ett_camel_RequestReportGPRSEventArg);
return offset;
}
static int
dissect_camel_ResetTimerGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ResetTimerGPRSArg_sequence, hf_index, ett_camel_ResetTimerGPRSArg);
return offset;
}
static int
dissect_camel_SendChargingInformationGPRSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SendChargingInformationGPRSArg_sequence, hf_index, ett_camel_SendChargingInformationGPRSArg);
return offset;
}
static int
dissect_camel_ConnectSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectSMSArg_sequence, hf_index, ett_camel_ConnectSMSArg);
return offset;
}
static int
dissect_camel_EventReportSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventReportSMSArg_sequence, hf_index, ett_camel_EventReportSMSArg);
return offset;
}
static int
dissect_camel_FurnishChargingInformationSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_FCISMSBillingChargingCharacteristics(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_InitialDPSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPSMSArg_sequence, hf_index, ett_camel_InitialDPSMSArg);
return offset;
}
static int
dissect_camel_ReleaseSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_RPCause(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_bound__numOfSMSEvents_OF_SMSEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_bound__numOfSMSEvents_OF_SMSEvent_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_bound__numOfSMSEvents_OF_SMSEvent);
return offset;
}
static int
dissect_camel_RequestReportSMSEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportSMSEventArg_sequence, hf_index, ett_camel_RequestReportSMSEventArg);
return offset;
}
static int
dissect_camel_ResetTimerSMSArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ResetTimerSMSArg_sequence, hf_index, ett_camel_ResetTimerSMSArg);
return offset;
}
static int
dissect_camel_CAP_U_ABORT_REASON(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_NACarrierSelectionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_NACarrierInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NACarrierInformation_sequence, hf_index, ett_camel_NACarrierInformation);
return offset;
}
static int
dissect_camel_InitialDPArgExtensionV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPArgExtensionV2_sequence, hf_index, ett_camel_InitialDPArgExtensionV2);
return offset;
}
static int
dissect_camel_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField_sequence_of, hf_index, ett_camel_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField);
return offset;
}
static int
dissect_camel_ReleaseIfDurationExceeded(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReleaseIfDurationExceeded_sequence, hf_index, ett_camel_ReleaseIfDurationExceeded);
return offset;
}
static int
dissect_camel_T_timeDurationCharging_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_timeDurationCharging_01_sequence, hf_index, ett_camel_T_timeDurationCharging_01);
return offset;
}
static int
dissect_camel_CAMEL_AChBillingChargingCharacteristicsV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CAMEL_AChBillingChargingCharacteristicsV2_choice, hf_index, ett_camel_CAMEL_AChBillingChargingCharacteristicsV2,
NULL);
return offset;
}
static int
dissect_camel_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_InvokeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InvokeId_choice, hf_index, ett_camel_InvokeId,
NULL);
return offset;
}
static int
dissect_camel_InvokeId_present(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_linkedIdPresent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_camel_InvokeId_present(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_T_linkedId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_linkedId_choice, hf_index, ett_camel_T_linkedId,
NULL);
return offset;
}
static int
dissect_camel_T_argument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_invokeData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_camel_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
camel_opcode_type=CAMEL_OPCODE_INVOKE;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Invoke_sequence, hf_index, ett_camel_Invoke);
return offset;
}
static int
dissect_camel_ResultArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_returnResultData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_camel_T_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_result_sequence, hf_index, ett_camel_T_result);
return offset;
}
static int
dissect_camel_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
camel_opcode_type=CAMEL_OPCODE_RETURN_RESULT;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnResult_sequence, hf_index, ett_camel_ReturnResult);
return offset;
}
static int
dissect_camel_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_returnErrorData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_camel_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
camel_opcode_type=CAMEL_OPCODE_RETURN_ERROR;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnError_sequence, hf_index, ett_camel_ReturnError);
return offset;
}
static int
dissect_camel_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_camel_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_problem_choice, hf_index, ett_camel_T_problem,
NULL);
return offset;
}
static int
dissect_camel_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
camel_opcode_type=CAMEL_OPCODE_REJECT;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reject_sequence, hf_index, ett_camel_Reject);
return offset;
}
static int
dissect_camel_ROS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ROS_choice, hf_index, ett_camel_ROS,
NULL);
return offset;
}
static int dissect_PAR_cancelFailed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PAR_cancelFailed(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PAR_cancelFailed_PDU);
return offset;
}
static int dissect_PAR_requestedInfoError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PAR_requestedInfoError(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PAR_requestedInfoError_PDU);
return offset;
}
static int dissect_UnavailableNetworkResource_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_UnavailableNetworkResource(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_UnavailableNetworkResource_PDU);
return offset;
}
static int dissect_PAR_taskRefused_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PAR_taskRefused(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PAR_taskRefused_PDU);
return offset;
}
static void dissect_CAP_GPRS_ReferenceNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_camel_CAP_GPRS_ReferenceNumber(FALSE, tvb, 0, &asn1_ctx, tree, hf_camel_CAP_GPRS_ReferenceNumber_PDU);
}
static int dissect_PlayAnnouncementArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PlayAnnouncementArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PlayAnnouncementArg_PDU);
return offset;
}
static int dissect_PromptAndCollectUserInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PromptAndCollectUserInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PromptAndCollectUserInformationArg_PDU);
return offset;
}
static int dissect_ReceivedInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ReceivedInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ReceivedInformationArg_PDU);
return offset;
}
static int dissect_SpecializedResourceReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_SpecializedResourceReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_SpecializedResourceReportArg_PDU);
return offset;
}
static int dissect_ApplyChargingArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ApplyChargingArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ApplyChargingArg_PDU);
return offset;
}
static int dissect_ApplyChargingReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ApplyChargingReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ApplyChargingReportArg_PDU);
return offset;
}
static int dissect_AssistRequestInstructionsArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_AssistRequestInstructionsArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_AssistRequestInstructionsArg_PDU);
return offset;
}
static int dissect_CallGapArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CallGapArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CallGapArg_PDU);
return offset;
}
static int dissect_CallInformationReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CallInformationReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CallInformationReportArg_PDU);
return offset;
}
static int dissect_CallInformationRequestArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CallInformationRequestArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CallInformationRequestArg_PDU);
return offset;
}
static int dissect_CancelArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CancelArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CancelArg_PDU);
return offset;
}
static int dissect_CollectInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CollectInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CollectInformationArg_PDU);
return offset;
}
static int dissect_ConnectArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ConnectArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ConnectArg_PDU);
return offset;
}
static int dissect_ConnectToResourceArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ConnectToResourceArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ConnectToResourceArg_PDU);
return offset;
}
static int dissect_ContinueWithArgumentArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ContinueWithArgumentArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ContinueWithArgumentArg_PDU);
return offset;
}
static int dissect_DisconnectForwardConnectionWithArgumentArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_DisconnectForwardConnectionWithArgumentArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_DisconnectForwardConnectionWithArgumentArg_PDU);
return offset;
}
static int dissect_DisconnectLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_DisconnectLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_DisconnectLegArg_PDU);
return offset;
}
static int dissect_EntityReleasedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EntityReleasedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EntityReleasedArg_PDU);
return offset;
}
static int dissect_EstablishTemporaryConnectionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EstablishTemporaryConnectionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EstablishTemporaryConnectionArg_PDU);
return offset;
}
static int dissect_EventReportBCSMArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EventReportBCSMArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EventReportBCSMArg_PDU);
return offset;
}
static int dissect_FurnishChargingInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_FurnishChargingInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_FurnishChargingInformationArg_PDU);
return offset;
}
static int dissect_InitialDPArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_InitialDPArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_InitialDPArg_PDU);
return offset;
}
static int dissect_InitiateCallAttemptArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_InitiateCallAttemptArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_InitiateCallAttemptArg_PDU);
return offset;
}
static int dissect_InitiateCallAttemptRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_InitiateCallAttemptRes(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_InitiateCallAttemptRes_PDU);
return offset;
}
static int dissect_MoveLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_MoveLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_MoveLegArg_PDU);
return offset;
}
static int dissect_PlayToneArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_PlayToneArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_PlayToneArg_PDU);
return offset;
}
static int dissect_ReleaseCallArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ReleaseCallArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ReleaseCallArg_PDU);
return offset;
}
static int dissect_RequestReportBCSMEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_RequestReportBCSMEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_RequestReportBCSMEventArg_PDU);
return offset;
}
static int dissect_ResetTimerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ResetTimerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ResetTimerArg_PDU);
return offset;
}
static int dissect_SendChargingInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_SendChargingInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_SendChargingInformationArg_PDU);
return offset;
}
static int dissect_SplitLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_SplitLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_SplitLegArg_PDU);
return offset;
}
static int dissect_ApplyChargingGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ApplyChargingGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ApplyChargingGPRSArg_PDU);
return offset;
}
static int dissect_ApplyChargingReportGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ApplyChargingReportGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ApplyChargingReportGPRSArg_PDU);
return offset;
}
static int dissect_CancelGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_CancelGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_CancelGPRSArg_PDU);
return offset;
}
static int dissect_ConnectGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ConnectGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ConnectGPRSArg_PDU);
return offset;
}
static int dissect_ContinueGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ContinueGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ContinueGPRSArg_PDU);
return offset;
}
static int dissect_EntityReleasedGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EntityReleasedGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EntityReleasedGPRSArg_PDU);
return offset;
}
static int dissect_EventReportGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EventReportGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EventReportGPRSArg_PDU);
return offset;
}
static int dissect_FurnishChargingInformationGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_FurnishChargingInformationGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_FurnishChargingInformationGPRSArg_PDU);
return offset;
}
static int dissect_InitialDPGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_InitialDPGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_InitialDPGPRSArg_PDU);
return offset;
}
static int dissect_ReleaseGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ReleaseGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ReleaseGPRSArg_PDU);
return offset;
}
static int dissect_RequestReportGPRSEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_RequestReportGPRSEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_RequestReportGPRSEventArg_PDU);
return offset;
}
static int dissect_ResetTimerGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ResetTimerGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ResetTimerGPRSArg_PDU);
return offset;
}
static int dissect_SendChargingInformationGPRSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_SendChargingInformationGPRSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_SendChargingInformationGPRSArg_PDU);
return offset;
}
static int dissect_ConnectSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ConnectSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ConnectSMSArg_PDU);
return offset;
}
static int dissect_EventReportSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_EventReportSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_EventReportSMSArg_PDU);
return offset;
}
static int dissect_FurnishChargingInformationSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_FurnishChargingInformationSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_FurnishChargingInformationSMSArg_PDU);
return offset;
}
static int dissect_InitialDPSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_InitialDPSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_InitialDPSMSArg_PDU);
return offset;
}
static int dissect_ReleaseSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ReleaseSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ReleaseSMSArg_PDU);
return offset;
}
static int dissect_RequestReportSMSEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_RequestReportSMSEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_RequestReportSMSEventArg_PDU);
return offset;
}
static int dissect_ResetTimerSMSArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_camel_ResetTimerSMSArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_camel_ResetTimerSMSArg_PDU);
return offset;
}
static void dissect_CAP_U_ABORT_REASON_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_camel_CAP_U_ABORT_REASON(FALSE, tvb, 0, &asn1_ctx, tree, hf_camel_CAP_U_ABORT_REASON_PDU);
}
static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
switch(opcode){
case opcode_playAnnouncement:
offset= dissect_PlayAnnouncementArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_promptAndCollectUserInformation:
offset= dissect_PromptAndCollectUserInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_specializedResourceReport:
offset= dissect_SpecializedResourceReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_applyCharging:
offset= dissect_ApplyChargingArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_applyChargingReport:
offset= dissect_ApplyChargingReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_assistRequestInstructions:
offset= dissect_AssistRequestInstructionsArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_callGap:
offset= dissect_CallGapArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_callInformationReport:
offset= dissect_CallInformationReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_callInformationRequest:
offset= dissect_CallInformationRequestArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_cancel:
offset= dissect_CancelArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_collectInformation:
offset= dissect_CollectInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_connect:
offset= dissect_ConnectArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_connectToResource:
offset= dissect_ConnectToResourceArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_continueWithArgument:
offset= dissect_ContinueWithArgumentArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_dFCWithArgument:
offset= dissect_DisconnectForwardConnectionWithArgumentArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_disconnectLeg:
offset= dissect_DisconnectLegArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_entityReleased:
offset= dissect_EntityReleasedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_establishTemporaryConnection:
offset= dissect_EstablishTemporaryConnectionArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_eventReportBCSM:
offset= dissect_EventReportBCSMArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_furnishChargingInformation:
offset= dissect_FurnishChargingInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initialDP:
offset= dissect_InitialDPArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initiateCallAttempt:
offset= dissect_InitiateCallAttemptArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_moveLeg:
offset= dissect_MoveLegArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_playTone:
offset= dissect_PlayToneArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_releaseCall:
offset= dissect_ReleaseCallArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportBCSMEvent:
offset= dissect_RequestReportBCSMEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_resetTimer:
offset= dissect_ResetTimerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_sendChargingInformation:
offset= dissect_SendChargingInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_splitLeg:
offset= dissect_SplitLegArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_applyChargingGPRS:
offset= dissect_ApplyChargingGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_applyChargingReportGPRS:
offset= dissect_ApplyChargingReportGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_cancelGPRS:
offset= dissect_CancelGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_connectGPRS:
offset= dissect_ConnectGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_continueGPRS:
offset= dissect_ContinueGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_entityReleasedGPRS:
offset= dissect_EntityReleasedGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_eventReportGPRS:
offset= dissect_EventReportGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_furnishChargingInformationGPRS:
offset= dissect_FurnishChargingInformationGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initialDPGPRS:
offset= dissect_InitialDPGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_releaseGPRS:
offset= dissect_ReleaseGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportGPRSEvent:
offset= dissect_RequestReportGPRSEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_resetTimerGPRS:
offset= dissect_ResetTimerGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_sendChargingInformationGPRS:
offset= dissect_SendChargingInformationGPRSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_connectSMS:
offset= dissect_ConnectSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_eventReportSMS:
offset= dissect_EventReportSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_furnishChargingInformationSMS:
offset= dissect_FurnishChargingInformationSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initialDPSMS:
offset= dissect_InitialDPSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_releaseSMS:
offset= dissect_ReleaseSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportSMSEvent:
offset= dissect_RequestReportSMSEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_resetTimerSMS:
offset= dissect_ResetTimerSMSArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_camel_unknown_invokeData,
tvb, offset, -1, "Unknown invokeData %d", opcode);
break;
}
return offset;
}
static int dissect_returnResultData(proto_tree *tree, tvbuff_t *tvb, int offset,asn1_ctx_t *actx) {
switch(opcode){
case opcode_promptAndCollectUserInformation:
offset= dissect_ReceivedInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initiateCallAttempt:
offset= dissect_InitiateCallAttemptRes_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_camel_unknown_returnResultData,
tvb, offset, -1, "Unknown returnResultData %d",opcode);
}
return offset;
}
static int dissect_returnErrorData(proto_tree *tree, tvbuff_t *tvb, int offset,asn1_ctx_t *actx) {
switch(errorCode) {
case errcode_cancelFailed:
dissect_PAR_cancelFailed_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_requestedInfoError:
dissect_PAR_requestedInfoError_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_systemFailure:
dissect_UnavailableNetworkResource_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_taskRefused:
dissect_PAR_taskRefused_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_camel_unknown_returnErrorData,
tvb, offset, -1, "Unknown returnErrorData %d",errorCode);
}
return offset;
}
static gint
camelsrt_call_equal(gconstpointer k1, gconstpointer k2)
{
const struct camelsrt_call_info_key_t *key1 = (const struct camelsrt_call_info_key_t *) k1;
const struct camelsrt_call_info_key_t *key2 = (const struct camelsrt_call_info_key_t *) k2;
return (key1->SessionIdKey == key2->SessionIdKey) ;
}
static guint
camelsrt_call_hash(gconstpointer k)
{
const struct camelsrt_call_info_key_t *key = (const struct camelsrt_call_info_key_t *) k;
return key->SessionIdKey;
}
static struct camelsrt_call_t *
find_camelsrt_call(struct camelsrt_call_info_key_t *p_camelsrt_call_key)
{
struct camelsrt_call_t *p_camelsrt_call = NULL;
p_camelsrt_call = (struct camelsrt_call_t *)g_hash_table_lookup(srt_calls, p_camelsrt_call_key);
#ifdef DEBUG_CAMELSRT
if(p_camelsrt_call) {
dbg(10,"D%d ", p_camelsrt_call->session_id);
} else {
dbg(23,"Not in hash ");
}
#endif
return p_camelsrt_call;
}
static void
raz_camelsrt_call (struct camelsrt_call_t *p_camelsrt_call)
{
memset(p_camelsrt_call,0,sizeof(struct camelsrt_call_t));
}
static struct camelsrt_call_t *
new_camelsrt_call(struct camelsrt_call_info_key_t *p_camelsrt_call_key)
{
struct camelsrt_call_info_key_t *p_new_camelsrt_call_key;
struct camelsrt_call_t *p_new_camelsrt_call = NULL;
p_new_camelsrt_call_key = se_new(struct camelsrt_call_info_key_t);
p_new_camelsrt_call_key->SessionIdKey = p_camelsrt_call_key->SessionIdKey;
p_new_camelsrt_call = se_new(struct camelsrt_call_t);
raz_camelsrt_call(p_new_camelsrt_call);
p_new_camelsrt_call->session_id = camelsrt_global_SessionId++;
#ifdef DEBUG_CAMELSRT
dbg(10,"D%d ", p_new_camelsrt_call->session_id);
#endif
g_hash_table_insert(srt_calls, p_new_camelsrt_call_key, p_new_camelsrt_call);
return p_new_camelsrt_call;
}
void
camelsrt_init_routine(void)
{
if (srt_calls != NULL) {
#ifdef DEBUG_CAMELSRT
dbg(16,"Destroy hash ");
#endif
g_hash_table_destroy(srt_calls);
}
srt_calls = g_hash_table_new(camelsrt_call_hash, camelsrt_call_equal);
#ifdef DEBUG_CAMELSRT
dbg(16,"Create hash ");
#endif
camelsrt_global_SessionId=1;
gcamel_DisplaySRT=gcamel_PersistentSRT || gcamel_HandleSRT&gcamel_StatSRT;
}
static void
update_camelsrt_call(struct camelsrt_call_t *p_camelsrt_call, packet_info *pinfo,
guint msg_category)
{
p_camelsrt_call->category[msg_category].req_num = pinfo->fd->num;
p_camelsrt_call->category[msg_category].rsp_num = 0;
p_camelsrt_call->category[msg_category].responded = FALSE;
p_camelsrt_call->category[msg_category].req_time = pinfo->fd->abs_ts;
}
static void
camelsrt_close_call_matching(packet_info *pinfo,
struct camelsrt_info_t *p_camelsrt_info)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
nstime_t delta;
p_camelsrt_info->bool_msginfo[CAMELSRT_SESSION]=TRUE;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n Session end #%u\n", pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found ");
#endif
nstime_delta(&delta, &pinfo->fd->abs_ts, &p_camelsrt_call->category[CAMELSRT_SESSION].req_time);
p_camelsrt_call->category[CAMELSRT_SESSION].responded = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].request_available = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].is_delta_time = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].delta_time = delta;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].req_time = p_camelsrt_call->category[CAMELSRT_SESSION].req_time;
if ( !gcamel_PersistentSRT ) {
g_hash_table_remove(srt_calls, &camelsrt_call_key);
#ifdef DEBUG_CAMELSRT
dbg(20,"remove hash ");
#endif
} else {
#ifdef DEBUG_CAMELSRT
dbg(20,"keep hash ");
#endif
}
}
}
static void
camelsrt_tcap_matching(tvbuff_t *tvb _U_, packet_info *pinfo,
proto_tree *tree _U_,
struct tcaphash_context_t *p_tcap_context)
{
struct camelsrt_info_t *p_camelsrt_info;
#ifdef DEBUG_CAMELSRT
dbg(11,"Camel_CallBack ");
#endif
p_camelsrt_info=camelsrt_razinfo();
p_camelsrt_info->tcap_context=p_tcap_context;
if (p_tcap_context) {
#ifdef DEBUG_CAMELSRT
dbg(11,"Close TCAP ");
#endif
p_camelsrt_info->tcap_session_id = p_tcap_context->session_id;
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, p_camelsrt_info);
}
}
static void
camelsrt_begin_call_matching(packet_info *pinfo,
struct camelsrt_info_t *p_camelsrt_info)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
p_camelsrt_info->bool_msginfo[CAMELSRT_SESSION]=TRUE;
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n Session begin #%u\n", pinfo->fd->num);
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = (struct camelsrt_call_t *)g_hash_table_lookup(srt_calls, &camelsrt_call_key);
if (p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(22,"Already seen ");
#endif
} else {
#ifdef DEBUG_CAMELSRT
dbg(10,"New key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = new_camelsrt_call(&camelsrt_call_key);
p_camelsrt_call->tcap_context=(struct tcaphash_context_t *)p_camelsrt_info->tcap_context;
update_camelsrt_call(p_camelsrt_call, pinfo,CAMELSRT_SESSION);
#ifdef DEBUG_CAMELSRT
dbg(11,"Update Callback ");
#endif
p_camelsrt_call->tcap_context->callback=camelsrt_tcap_matching;
}
}
static void
camelsrt_request_call_matching(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info,
guint srt_type )
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
proto_item *ti, *hidden_item;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n %s #%u\n", val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ", camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found ");
#endif
if (gcamel_DisplaySRT)
proto_tree_add_uint(tree, hf_camelsrt_SessionId, tvb, 0,0, p_camelsrt_call->session_id);
if (srt_type==CAMELSRT_VOICE_ACR1) {
if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num == 0) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num == 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num < pinfo->fd->num) ) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if ( (p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num == 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num != 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num < pinfo->fd->num) ) {
srt_type=CAMELSRT_VOICE_ACR3;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR3;
}
#ifdef DEBUG_CAMELSRT
dbg(70,"Request ACR %u ",srt_type);
dbg(70,"ACR1 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num);
dbg(70,"ACR2 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num);
dbg(70,"ACR3 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].rsp_num);
#endif
}
p_camelsrt_info->bool_msginfo[srt_type]=TRUE;
if (p_camelsrt_call->category[srt_type].req_num == 0) {
#ifdef DEBUG_CAMELSRT
dbg(5,"Set reqlink #%u ", pinfo->fd->num);
#endif
update_camelsrt_call(p_camelsrt_call, pinfo, srt_type);
} else {
if (p_camelsrt_call->category[srt_type].req_num != pinfo->fd->num) {
if (srt_type!=CAMELSRT_VOICE_DISC) {
#ifdef DEBUG_CAMELSRT
dbg(21,"Display_duplicate with req %d ", p_camelsrt_call->category[srt_type].req_num);
#endif
p_camelsrt_info->msginfo[srt_type].is_duplicate = TRUE;
if (gcamel_DisplaySRT){
hidden_item = proto_tree_add_uint(tree, hf_camelsrt_Duplicate, tvb, 0,0, 77);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
} else {
if (pinfo->fd->num > p_camelsrt_call->category[srt_type].req_num) {
p_camelsrt_call->category[srt_type].req_num = pinfo->fd->num;
#ifdef DEBUG_CAMELSRT
dbg(5,"DISC Set reqlink #%u ", pinfo->fd->num);
#endif
update_camelsrt_call(p_camelsrt_call, pinfo, srt_type);
}
}
}
}
if ( gcamel_DisplaySRT &&
(p_camelsrt_call->category[srt_type].rsp_num != 0) &&
(p_camelsrt_call->category[srt_type].req_num != 0) &&
(p_camelsrt_call->category[srt_type].req_num == pinfo->fd->num) ) {
#ifdef DEBUG_CAMELSRT
dbg(20,"Display_framersplink %d ",p_camelsrt_call->category[srt_type].rsp_num);
#endif
ti = proto_tree_add_uint_format(tree, hf_camelsrt_RequestFrame, tvb, 0, 0,
p_camelsrt_call->category[srt_type].rsp_num,
"Linked response %s in frame %u",
val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),
p_camelsrt_call->category[srt_type].rsp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
static void
camelsrt_display_DeltaTime(proto_tree *tree, tvbuff_t *tvb, nstime_t *value_ptr,
guint category)
{
proto_item *ti;
if ( gcamel_DisplaySRT ) {
switch(category) {
case CAMELSRT_VOICE_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime31, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_VOICE_ACR1:
case CAMELSRT_VOICE_ACR2:
case CAMELSRT_VOICE_ACR3:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime22, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_VOICE_DISC:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime35, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_GPRS_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime75, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_GPRS_REPORT:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime80, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_SMS_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime65, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
default:
break;
}
}
}
static void
camelsrt_report_call_matching(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info,
guint srt_type)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
nstime_t delta;
proto_item *ti, *hidden_item;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n %s #%u\n", val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found, req=%d ",p_camelsrt_call->category[srt_type].req_num);
#endif
if ( gcamel_DisplaySRT )
proto_tree_add_uint(tree, hf_camelsrt_SessionId, tvb, 0,0, p_camelsrt_call->session_id);
if (srt_type==CAMELSRT_VOICE_ACR1) {
if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
}
#ifdef DEBUG_CAMELSRT
dbg(70,"Report ACR %u ",srt_type);
#endif
}
p_camelsrt_info->bool_msginfo[srt_type]=TRUE;
if (p_camelsrt_call->category[srt_type].rsp_num == 0) {
if ( (p_camelsrt_call->category[srt_type].req_num != 0)
&& (pinfo->fd->num > p_camelsrt_call->category[srt_type].req_num) ){
#ifdef DEBUG_CAMELSRT
dbg(14,"Set reslink #%d req %u ",pinfo->fd->num, p_camelsrt_call->category[srt_type].req_num);
#endif
p_camelsrt_call->category[srt_type].rsp_num = pinfo->fd->num;
} else {
#ifdef DEBUG_CAMELSRT
dbg(2,"badreslink #%u req %u ",pinfo->fd->num, p_camelsrt_call->category[srt_type].req_num);
#endif
}
} else {
if (p_camelsrt_call->category[srt_type].rsp_num != pinfo->fd->num) {
#ifdef DEBUG_CAMELSRT
dbg(21,"Display_duplicate rsp=%d ", p_camelsrt_call->category[srt_type].rsp_num);
#endif
p_camelsrt_info->msginfo[srt_type].is_duplicate = TRUE;
if ( gcamel_DisplaySRT ){
hidden_item = proto_tree_add_uint(tree, hf_camelsrt_Duplicate, tvb, 0,0, 77);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
if ( (p_camelsrt_call->category[srt_type].req_num != 0) &&
(p_camelsrt_call->category[srt_type].rsp_num != 0) &&
(p_camelsrt_call->category[srt_type].rsp_num == pinfo->fd->num) ) {
p_camelsrt_call->category[srt_type].responded = TRUE;
p_camelsrt_info->msginfo[srt_type].request_available = TRUE;
#ifdef DEBUG_CAMELSRT
dbg(20,"Display_frameReqlink %d ",p_camelsrt_call->category[srt_type].req_num);
#endif
if ( gcamel_DisplaySRT ) {
ti = proto_tree_add_uint_format(tree, hf_camelsrt_ResponseFrame, tvb, 0, 0,
p_camelsrt_call->category[srt_type].req_num,
"Linked request %s in frame %u",
val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),
p_camelsrt_call->category[srt_type].req_num);
PROTO_ITEM_SET_GENERATED(ti);
}
nstime_delta(&delta, &pinfo->fd->abs_ts, &p_camelsrt_call->category[srt_type].req_time);
p_camelsrt_info->msginfo[srt_type].is_delta_time = TRUE;
p_camelsrt_info->msginfo[srt_type].delta_time = delta;
p_camelsrt_info->msginfo[srt_type].req_time = p_camelsrt_call->category[srt_type].req_time;
camelsrt_display_DeltaTime(tree, tvb, &delta, srt_type);
}
}
}
void
camelsrt_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info)
{
#ifdef DEBUG_CAMELSRT
dbg(10,"tcap_session #%d ", p_camelsrt_info->tcap_session_id);
#endif
switch (p_camelsrt_info->opcode) {
case 0:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_INITIALDP);
break;
case 60:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_SMS_INITIALDP);
break;
case 78:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_INITIALDP);
break;
case 23:
break;
case 63:
break;
case 81:
break;
case 24:
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_DISC );
break;
case 64:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tcapsrt_close((struct tcaphash_context_t *)p_camelsrt_info->tcap_context, pinfo);
break;
case 80:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_REPORT);
break;
case 35:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_ACR1 );
break;
case 71:
break;
case 36:
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_ACR1 );
break;
case 72:
break;
case 31:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_INITIALDP);
break;
case 65:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_SMS_INITIALDP);
break;
case 75:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_INITIALDP);
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_REPORT);
break;
case 22:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_DISC);
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
break;
case 66:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tcapsrt_close((struct tcaphash_context_t *)p_camelsrt_info->tcap_context,pinfo);
break;
case 79:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
break;
}
}
struct camelsrt_info_t *
camelsrt_razinfo(void)
{
struct camelsrt_info_t *p_camelsrt_info ;
camelsrt_global_current++;
if(camelsrt_global_current==MAX_CAMEL_INSTANCE){
camelsrt_global_current=0;
}
p_camelsrt_info=&camelsrt_global_info[camelsrt_global_current];
memset(p_camelsrt_info,0,sizeof(struct camelsrt_info_t));
p_camelsrt_info->opcode=255;
return p_camelsrt_info;
}
static int
dissect_camel_camelPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_,proto_tree *tree,
int hf_index, struct tcap_private_t * p_private_tcap) {
char *version_ptr;
opcode = 0;
application_context_version = 0;
if (p_private_tcap != NULL){
if (p_private_tcap->acv==TRUE ){
version_ptr = strrchr((const char *)p_private_tcap->oid,'.');
if (version_ptr)
application_context_version = atoi(version_ptr+1);
}
gp_camelsrt_info->tcap_context=p_private_tcap->context;
if (p_private_tcap->context)
gp_camelsrt_info->tcap_session_id = ( (struct tcaphash_context_t *) (p_private_tcap->context))->session_id;
}
camel_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
camel_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
col_add_str(actx->pinfo->cinfo, COL_INFO, val_to_str(camel_pdu_type, camel_Component_vals, "Unknown Camel (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
is_ExtensionField =FALSE;
offset = dissect_camel_ROS(TRUE, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item;
proto_tree *tree = NULL, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v1");
camel_ver = 1;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_camel_stat, NULL, "Stat");
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_captured_length(tvb);
}
static int
dissect_camel_v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item;
proto_tree *tree = NULL, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v2");
camel_ver = 2;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_camel_stat, NULL, "Stat");
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_captured_length(tvb);
}
static int
dissect_camel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item;
proto_tree *tree, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel");
camel_ver = 0;
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_camel_stat, NULL, "Stat");
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_captured_length(tvb);
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, camel_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, camel_handle);
}
}
void proto_reg_handoff_camel(void) {
static gboolean camel_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!camel_prefs_initialized) {
camel_prefs_initialized = TRUE;
camel_handle = find_dissector("camel");
camel_v1_handle = find_dissector("camel-v1");
camel_v2_handle = find_dissector("camel-v2");
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.0",camel_v1_handle, proto_camel, "CAP-v1-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.51.1",camel_v2_handle, proto_camel, "CAP-v2-assist-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.52.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSRF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.50",camel_handle, proto_camel, "cap3-gprssf-scfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.51",camel_handle, proto_camel, "cap3-gsmscf-gprsssfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.61",camel_handle, proto_camel, "cap3-sms-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.4",camel_handle, proto_camel, "capssf-scfGenericAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.61",camel_handle, proto_camel, "cap4-sms-AC" );
#line 1 "../../asn1/camel/packet-camel-dis-tab.c"
register_ber_oid_dissector("0.4.0.0.1.1.5.2", dissect_CAP_GPRS_ReferenceNumber_PDU, proto_camel, "id-CAP-GPRS-ReferenceNumber");
register_ber_oid_dissector("0.4.0.0.1.1.2.2", dissect_CAP_U_ABORT_REASON_PDU, proto_camel, "id-CAP-U-ABORT-Reason");
#line 1221 "../../asn1/camel/packet-camel-template.c"
} else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_camel(void) {
module_t *camel_module;
static hf_register_info hf[] = {
{ &hf_camel_extension_code_local,
{ "local", "camel.extension_code_local",
FT_INT32, BASE_DEC, NULL, 0,
"Extension local code", HFILL }},
{ &hf_camel_error_code_local,
{ "local", "camel.error_code_local",
FT_INT32, BASE_DEC, VALS(camel_err_code_string_vals), 0,
"ERROR code", HFILL }},
{ &hf_camel_cause_indicator,
{ "Cause indicator", "camel.cause_indicator",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q850_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_digit,
{ "Digit Value", "camel.digit_value",
FT_UINT8, BASE_DEC, VALS(digit_value), 0, NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_etsi,
{ "ETSI defined PDP Type Value", "camel.PDPTypeNumber_etsi",
FT_UINT8, BASE_HEX, VALS(gsm_map_etsi_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_ietf,
{ "IETF defined PDP Type Value", "camel.PDPTypeNumber_ietf",
FT_UINT8, BASE_HEX, VALS(gsm_map_ietf_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPAddress_IPv4,
{ "PDPAddress IPv4", "camel.PDPAddress_IPv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPAddress IPv4", HFILL }},
{ &hf_camel_PDPAddress_IPv6,
{ "PDPAddress IPv6", "camel.PDPAddress_IPv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPAddress IPv6", HFILL }},
{ &hf_camel_cellGlobalIdOrServiceAreaIdFixedLength,
{ "CellGlobalIdOrServiceAreaIdFixedLength", "camel.CellGlobalIdOrServiceAreaIdFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
"LocationInformationGPRS/CellGlobalIdOrServiceAreaIdOrLAI", HFILL }},
{ &hf_camel_RP_Cause,
{ "RP Cause", "camel.RP_Cause",
FT_UINT8, BASE_DEC, NULL, 0,
"RP Cause Value", HFILL }},
{ &hf_camel_CAMEL_AChBillingChargingCharacteristics,
{ "CAMEL-AChBillingChargingCharacteristics", "camel.CAMEL_AChBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_AChBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIBillingChargingCharacteristics,
{ "CAMEL-FCIBillingChargingCharacteristics", "camel.CAMEL_FCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIGPRSBillingChargingCharacteristics,
{ "CAMEL-FCIGPRSBillingChargingCharacteristics", "camel.CAMEL_FCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCISMSBillingChargingCharacteristics,
{ "CAMEL-FCISMSBillingChargingCharacteristics", "camel.CAMEL_FCISMSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCISMSBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIBillingChargingCharacteristics,
{ "CAMEL-SCIBillingChargingCharacteristics", "camel.CAMEL_SCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_SCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIGPRSBillingChargingCharacteristics,
{ "CAMEL-SCIGPRSBillingChargingCharacteristics", "camel.CAMEL_SCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
"CAMEL-FSCIGPRSBillingChargingCharacteristics", HFILL }},
{ &hf_camel_CAMEL_CallResult,
{ "CAMEL-CAMEL_CallResult", "camel.CAMEL_CallResult",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_CallResult_vals), 0,
"CAMEL-CallResult", HFILL }},
{ &hf_camelsrt_SessionId,
{ "Session Id",
"camel.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestNumber,
{ "Request Number",
"camel.srt.request_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_Duplicate,
{ "Request Duplicate",
"camel.srt.duplicate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestFrame,
{ "Requested Frame",
"camel.srt.reqframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Request Frame", HFILL }
},
{ &hf_camelsrt_ResponseFrame,
{ "Response Frame",
"camel.srt.rspframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Response Frame", HFILL }
},
{ &hf_camelsrt_DeltaTime,
{ "Service Response Time",
"camel.srt.deltatime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between Request and Response", HFILL }
},
{ &hf_camelsrt_SessionTime,
{ "Session duration",
"camel.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_camelsrt_DeltaTime31,
{ "Service Response Time",
"camel.srt.deltatime31",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDP and Continue", HFILL }
},
{ &hf_camelsrt_DeltaTime65,
{ "Service Response Time",
"camel.srt.deltatime65",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPSMS and ContinueSMS", HFILL }
},
{ &hf_camelsrt_DeltaTime75,
{ "Service Response Time",
"camel.srt.deltatime75",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPGPRS and ContinueGPRS", HFILL }
},
{ &hf_camelsrt_DeltaTime35,
{ "Service Response Time",
"camel.srt.deltatime35",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between ApplyCharginReport and ApplyCharging", HFILL }
},
{ &hf_camelsrt_DeltaTime22,
{ "Service Response Time",
"camel.srt.deltatime22",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReport(Disconnect) and Release Call", HFILL }
},
{ &hf_camelsrt_DeltaTime80,
{ "Service Response Time",
"camel.srt.deltatime80",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReportGPRS and ContinueGPRS", HFILL }
},
#ifdef REMOVED
#endif
#line 1 "../../asn1/camel/packet-camel-hfarr.c"
{ &hf_camel_PAR_cancelFailed_PDU,
{ "PAR-cancelFailed", "camel.PAR_cancelFailed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_PAR_requestedInfoError_PDU,
{ "PAR-requestedInfoError", "camel.PAR_requestedInfoError",
FT_UINT32, BASE_DEC, VALS(camel_PAR_requestedInfoError_vals), 0,
NULL, HFILL }},
{ &hf_camel_UnavailableNetworkResource_PDU,
{ "UnavailableNetworkResource", "camel.UnavailableNetworkResource",
FT_UINT32, BASE_DEC, VALS(camel_UnavailableNetworkResource_vals), 0,
NULL, HFILL }},
{ &hf_camel_PAR_taskRefused_PDU,
{ "PAR-taskRefused", "camel.PAR_taskRefused",
FT_UINT32, BASE_DEC, VALS(camel_PAR_taskRefused_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAP_GPRS_ReferenceNumber_PDU,
{ "CAP-GPRS-ReferenceNumber", "camel.CAP_GPRS_ReferenceNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_PlayAnnouncementArg_PDU,
{ "PlayAnnouncementArg", "camel.PlayAnnouncementArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_PromptAndCollectUserInformationArg_PDU,
{ "PromptAndCollectUserInformationArg", "camel.PromptAndCollectUserInformationArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ReceivedInformationArg_PDU,
{ "ReceivedInformationArg", "camel.ReceivedInformationArg",
FT_UINT32, BASE_DEC, VALS(camel_ReceivedInformationArg_vals), 0,
NULL, HFILL }},
{ &hf_camel_SpecializedResourceReportArg_PDU,
{ "SpecializedResourceReportArg", "camel.SpecializedResourceReportArg",
FT_UINT32, BASE_DEC, VALS(camel_SpecializedResourceReportArg_vals), 0,
NULL, HFILL }},
{ &hf_camel_ApplyChargingArg_PDU,
{ "ApplyChargingArg", "camel.ApplyChargingArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ApplyChargingReportArg_PDU,
{ "ApplyChargingReportArg", "camel.ApplyChargingReportArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_AssistRequestInstructionsArg_PDU,
{ "AssistRequestInstructionsArg", "camel.AssistRequestInstructionsArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CallGapArg_PDU,
{ "CallGapArg", "camel.CallGapArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CallInformationReportArg_PDU,
{ "CallInformationReportArg", "camel.CallInformationReportArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CallInformationRequestArg_PDU,
{ "CallInformationRequestArg", "camel.CallInformationRequestArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CancelArg_PDU,
{ "CancelArg", "camel.CancelArg",
FT_UINT32, BASE_DEC, VALS(camel_CancelArg_vals), 0,
NULL, HFILL }},
{ &hf_camel_CollectInformationArg_PDU,
{ "CollectInformationArg", "camel.CollectInformationArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ConnectArg_PDU,
{ "ConnectArg", "camel.ConnectArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ConnectToResourceArg_PDU,
{ "ConnectToResourceArg", "camel.ConnectToResourceArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ContinueWithArgumentArg_PDU,
{ "ContinueWithArgumentArg", "camel.ContinueWithArgumentArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_DisconnectForwardConnectionWithArgumentArg_PDU,
{ "DisconnectForwardConnectionWithArgumentArg", "camel.DisconnectForwardConnectionWithArgumentArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_DisconnectLegArg_PDU,
{ "DisconnectLegArg", "camel.DisconnectLegArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_EntityReleasedArg_PDU,
{ "EntityReleasedArg", "camel.EntityReleasedArg",
FT_UINT32, BASE_DEC, VALS(camel_EntityReleasedArg_vals), 0,
NULL, HFILL }},
{ &hf_camel_EstablishTemporaryConnectionArg_PDU,
{ "EstablishTemporaryConnectionArg", "camel.EstablishTemporaryConnectionArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_EventReportBCSMArg_PDU,
{ "EventReportBCSMArg", "camel.EventReportBCSMArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_FurnishChargingInformationArg_PDU,
{ "FurnishChargingInformationArg", "camel.FurnishChargingInformationArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_InitialDPArg_PDU,
{ "InitialDPArg", "camel.InitialDPArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_InitiateCallAttemptArg_PDU,
{ "InitiateCallAttemptArg", "camel.InitiateCallAttemptArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_InitiateCallAttemptRes_PDU,
{ "InitiateCallAttemptRes", "camel.InitiateCallAttemptRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_MoveLegArg_PDU,
{ "MoveLegArg", "camel.MoveLegArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_PlayToneArg_PDU,
{ "PlayToneArg", "camel.PlayToneArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ReleaseCallArg_PDU,
{ "ReleaseCallArg", "camel.ReleaseCallArg",
FT_UINT32, BASE_DEC, VALS(camel_ReleaseCallArg_vals), 0,
NULL, HFILL }},
{ &hf_camel_RequestReportBCSMEventArg_PDU,
{ "RequestReportBCSMEventArg", "camel.RequestReportBCSMEventArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ResetTimerArg_PDU,
{ "ResetTimerArg", "camel.ResetTimerArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_SendChargingInformationArg_PDU,
{ "SendChargingInformationArg", "camel.SendChargingInformationArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_SplitLegArg_PDU,
{ "SplitLegArg", "camel.SplitLegArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ApplyChargingGPRSArg_PDU,
{ "ApplyChargingGPRSArg", "camel.ApplyChargingGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ApplyChargingReportGPRSArg_PDU,
{ "ApplyChargingReportGPRSArg", "camel.ApplyChargingReportGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CancelGPRSArg_PDU,
{ "CancelGPRSArg", "camel.CancelGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ConnectGPRSArg_PDU,
{ "ConnectGPRSArg", "camel.ConnectGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ContinueGPRSArg_PDU,
{ "ContinueGPRSArg", "camel.ContinueGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_EntityReleasedGPRSArg_PDU,
{ "EntityReleasedGPRSArg", "camel.EntityReleasedGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_EventReportGPRSArg_PDU,
{ "EventReportGPRSArg", "camel.EventReportGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_FurnishChargingInformationGPRSArg_PDU,
{ "FurnishChargingInformationGPRSArg", "camel.FurnishChargingInformationGPRSArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_InitialDPGPRSArg_PDU,
{ "InitialDPGPRSArg", "camel.InitialDPGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ReleaseGPRSArg_PDU,
{ "ReleaseGPRSArg", "camel.ReleaseGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_RequestReportGPRSEventArg_PDU,
{ "RequestReportGPRSEventArg", "camel.RequestReportGPRSEventArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ResetTimerGPRSArg_PDU,
{ "ResetTimerGPRSArg", "camel.ResetTimerGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_SendChargingInformationGPRSArg_PDU,
{ "SendChargingInformationGPRSArg", "camel.SendChargingInformationGPRSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ConnectSMSArg_PDU,
{ "ConnectSMSArg", "camel.ConnectSMSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_EventReportSMSArg_PDU,
{ "EventReportSMSArg", "camel.EventReportSMSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_FurnishChargingInformationSMSArg_PDU,
{ "FurnishChargingInformationSMSArg", "camel.FurnishChargingInformationSMSArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_InitialDPSMSArg_PDU,
{ "InitialDPSMSArg", "camel.InitialDPSMSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ReleaseSMSArg_PDU,
{ "ReleaseSMSArg", "camel.ReleaseSMSArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_RequestReportSMSEventArg_PDU,
{ "RequestReportSMSEventArg", "camel.RequestReportSMSEventArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ResetTimerSMSArg_PDU,
{ "ResetTimerSMSArg", "camel.ResetTimerSMSArg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CAP_U_ABORT_REASON_PDU,
{ "CAP-U-ABORT-REASON", "camel.CAP_U_ABORT_REASON",
FT_UINT32, BASE_DEC, VALS(camel_CAP_U_ABORT_REASON_vals), 0,
NULL, HFILL }},
{ &hf_camel_legID,
{ "legID", "camel.legID",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
NULL, HFILL }},
{ &hf_camel_srfConnection,
{ "srfConnection", "camel.srfConnection",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_camel_aOCInitial,
{ "aOCInitial", "camel.aOCInitial_element",
FT_NONE, BASE_NONE, NULL, 0,
"CAI_GSM0224", HFILL }},
{ &hf_camel_aOCSubsequent,
{ "aOCSubsequent", "camel.aOCSubsequent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_cAI_GSM0224,
{ "cAI-GSM0224", "camel.cAI_GSM0224_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_aocSubsequent_tariffSwitchInterval,
{ "tariffSwitchInterval", "camel.tariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_camel_audibleIndicatorTone,
{ "tone", "camel.tone",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_burstList,
{ "burstList", "camel.burstList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_conferenceTreatmentIndicator,
{ "conferenceTreatmentIndicator", "camel.conferenceTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_callCompletionTreatmentIndicator,
{ "callCompletionTreatmentIndicator", "camel.callCompletionTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_calledAddressValue,
{ "calledAddressValue", "camel.calledAddressValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_gapOnService,
{ "gapOnService", "camel.gapOnService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_calledAddressAndService,
{ "calledAddressAndService", "camel.calledAddressAndService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_serviceKey,
{ "serviceKey", "camel.serviceKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callingAddressAndService,
{ "callingAddressAndService", "camel.callingAddressAndService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callingAddressValue,
{ "callingAddressValue", "camel.callingAddressValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_eventTypeBCSM,
{ "eventTypeBCSM", "camel.eventTypeBCSM",
FT_UINT32, BASE_DEC, VALS(camel_EventTypeBCSM_vals), 0,
NULL, HFILL }},
{ &hf_camel_monitorMode,
{ "monitorMode", "camel.monitorMode",
FT_UINT32, BASE_DEC, VALS(camel_MonitorMode_vals), 0,
NULL, HFILL }},
{ &hf_camel_dpSpecificCriteria,
{ "dpSpecificCriteria", "camel.dpSpecificCriteria",
FT_UINT32, BASE_DEC, VALS(camel_DpSpecificCriteria_vals), 0,
NULL, HFILL }},
{ &hf_camel_automaticRearm,
{ "automaticRearm", "camel.automaticRearm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_cause,
{ "cause", "camel.cause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bearerCap,
{ "bearerCap", "camel.bearerCap",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_numberOfBursts,
{ "numberOfBursts", "camel.numberOfBursts",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_3", HFILL }},
{ &hf_camel_burstInterval,
{ "burstInterval", "camel.burstInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1200", HFILL }},
{ &hf_camel_numberOfTonesInBurst,
{ "numberOfTonesInBurst", "camel.numberOfTonesInBurst",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_3", HFILL }},
{ &hf_camel_burstToneDuration,
{ "toneDuration", "camel.toneDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_20", HFILL }},
{ &hf_camel_toneInterval,
{ "toneInterval", "camel.toneInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_20", HFILL }},
{ &hf_camel_warningPeriod,
{ "warningPeriod", "camel.warningPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1200", HFILL }},
{ &hf_camel_bursts,
{ "bursts", "camel.bursts_element",
FT_NONE, BASE_NONE, NULL, 0,
"Burst", HFILL }},
{ &hf_camel_e1,
{ "e1", "camel.e1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e2,
{ "e2", "camel.e2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e3,
{ "e3", "camel.e3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e4,
{ "e4", "camel.e4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e5,
{ "e5", "camel.e5",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e6,
{ "e6", "camel.e6",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_e7,
{ "e7", "camel.e7",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_camel_callSegmentID,
{ "callSegmentID", "camel.callSegmentID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_invokeID,
{ "invokeID", "camel.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeDurationCharging,
{ "timeDurationCharging", "camel.timeDurationCharging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_maxCallPeriodDuration,
{ "maxCallPeriodDuration", "camel.maxCallPeriodDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_864000", HFILL }},
{ &hf_camel_releaseIfdurationExceeded,
{ "releaseIfdurationExceeded", "camel.releaseIfdurationExceeded",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_timeDurationCharging_tariffSwitchInterval,
{ "tariffSwitchInterval", "camel.tariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_camel_audibleIndicator,
{ "audibleIndicator", "camel.audibleIndicator",
FT_UINT32, BASE_DEC, VALS(camel_AudibleIndicator_vals), 0,
NULL, HFILL }},
{ &hf_camel_extensions,
{ "extensions", "camel.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeDurationChargingResult,
{ "timeDurationChargingResult", "camel.timeDurationChargingResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeDurationChargingResultpartyToCharge,
{ "partyToCharge", "camel.partyToCharge",
FT_UINT32, BASE_DEC, VALS(camel_ReceivingSideID_vals), 0,
"ReceivingSideID", HFILL }},
{ &hf_camel_timeInformation,
{ "timeInformation", "camel.timeInformation",
FT_UINT32, BASE_DEC, VALS(camel_TimeInformation_vals), 0,
NULL, HFILL }},
{ &hf_camel_legActive,
{ "legActive", "camel.legActive",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_callLegReleasedAtTcpExpiry,
{ "callLegReleasedAtTcpExpiry", "camel.callLegReleasedAtTcpExpiry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_aChChargingAddress,
{ "aChChargingAddress", "camel.aChChargingAddress",
FT_UINT32, BASE_DEC, VALS(camel_AChChargingAddress_vals), 0,
NULL, HFILL }},
{ &hf_camel_fci_fCIBCCCAMELsequence1,
{ "fCIBCCCAMELsequence1", "camel.fCIBCCCAMELsequence1_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fci_fCIBCCCAMELsequence1", HFILL }},
{ &hf_camel_freeFormatData,
{ "freeFormatData", "camel.freeFormatData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_bound__minFCIBillingChargingDataLength_bound__maxFCIBillingChargingDataLength", HFILL }},
{ &hf_camel_fCIBCCCAMELsequence1partyToCharge,
{ "partyToCharge", "camel.partyToCharge",
FT_UINT32, BASE_DEC, VALS(camel_SendingSideID_vals), 0,
"SendingSideID", HFILL }},
{ &hf_camel_appendFreeFormatData,
{ "appendFreeFormatData", "camel.appendFreeFormatData",
FT_UINT32, BASE_DEC, VALS(camel_AppendFreeFormatData_vals), 0,
NULL, HFILL }},
{ &hf_camel_fciGPRS_fCIBCCCAMELsequence1,
{ "fCIBCCCAMELsequence1", "camel.fCIBCCCAMELsequence1_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fciGPRS_fCIBCCCAMELsequence1", HFILL }},
{ &hf_camel_pDPID,
{ "pDPID", "camel.pDPID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_fciSMS_fCIBCCCAMELsequence1,
{ "fCIBCCCAMELsequence1", "camel.fCIBCCCAMELsequence1_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fciSMS_fCIBCCCAMELsequence1", HFILL }},
{ &hf_camel_aOCBeforeAnswer,
{ "aOCBeforeAnswer", "camel.aOCBeforeAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_aOCAfterAnswer,
{ "aOCAfterAnswer", "camel.aOCAfterAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
"AOCSubsequent", HFILL }},
{ &hf_camel_aOC_extension,
{ "aOC-extension", "camel.aOC_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
"CAMEL_SCIBillingChargingCharacteristicsAlt", HFILL }},
{ &hf_camel_aOCGPRS,
{ "aOCGPRS", "camel.aOCGPRS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ChangeOfPositionControlInfo_item,
{ "ChangeOfLocation", "camel.ChangeOfLocation",
FT_UINT32, BASE_DEC, VALS(camel_ChangeOfLocation_vals), 0,
NULL, HFILL }},
{ &hf_camel_cellGlobalId,
{ "cellGlobalId", "camel.cellGlobalId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_serviceAreaId,
{ "serviceAreaId", "camel.serviceAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_locationAreaId,
{ "locationAreaId", "camel.locationAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"LAIFixedLength", HFILL }},
{ &hf_camel_inter_SystemHandOver,
{ "inter-SystemHandOver", "camel.inter_SystemHandOver_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_inter_PLMNHandOver,
{ "inter-PLMNHandOver", "camel.inter_PLMNHandOver_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_inter_MSCHandOver,
{ "inter-MSCHandOver", "camel.inter_MSCHandOver_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_changeOfLocationAlt,
{ "changeOfLocationAlt", "camel.changeOfLocationAlt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_maxTransferredVolume,
{ "maxTransferredVolume", "camel.maxTransferredVolume",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4294967295", HFILL }},
{ &hf_camel_maxElapsedTime,
{ "maxElapsedTime", "camel.maxElapsedTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_camel_transferredVolume,
{ "transferredVolume", "camel.transferredVolume",
FT_UINT32, BASE_DEC, VALS(camel_TransferredVolume_vals), 0,
NULL, HFILL }},
{ &hf_camel_elapsedTime,
{ "elapsedTime", "camel.elapsedTime",
FT_UINT32, BASE_DEC, VALS(camel_ElapsedTime_vals), 0,
NULL, HFILL }},
{ &hf_camel_transferredVolumeRollOver,
{ "transferredVolumeRollOver", "camel.transferredVolumeRollOver",
FT_UINT32, BASE_DEC, VALS(camel_TransferredVolumeRollOver_vals), 0,
NULL, HFILL }},
{ &hf_camel_elapsedTimeRollOver,
{ "elapsedTimeRollOver", "camel.elapsedTimeRollOver",
FT_UINT32, BASE_DEC, VALS(camel_ElapsedTimeRollOver_vals), 0,
NULL, HFILL }},
{ &hf_camel_minimumNbOfDigits,
{ "minimumNbOfDigits", "camel.minimumNbOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_30", HFILL }},
{ &hf_camel_maximumNbOfDigits,
{ "maximumNbOfDigits", "camel.maximumNbOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_30", HFILL }},
{ &hf_camel_endOfReplyDigit,
{ "endOfReplyDigit", "camel.endOfReplyDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_camel_cancelDigit,
{ "cancelDigit", "camel.cancelDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_camel_startDigit,
{ "startDigit", "camel.startDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_camel_firstDigitTimeOut,
{ "firstDigitTimeOut", "camel.firstDigitTimeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_camel_interDigitTimeOut,
{ "interDigitTimeOut", "camel.interDigitTimeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_camel_errorTreatment,
{ "errorTreatment", "camel.errorTreatment",
FT_UINT32, BASE_DEC, VALS(camel_ErrorTreatment_vals), 0,
NULL, HFILL }},
{ &hf_camel_interruptableAnnInd,
{ "interruptableAnnInd", "camel.interruptableAnnInd",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_voiceInformation,
{ "voiceInformation", "camel.voiceInformation",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_voiceBack,
{ "voiceBack", "camel.voiceBack",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_collectedDigits,
{ "collectedDigits", "camel.collectedDigits_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_basicGapCriteria,
{ "basicGapCriteria", "camel.basicGapCriteria",
FT_UINT32, BASE_DEC, VALS(camel_BasicGapCriteria_vals), 0,
NULL, HFILL }},
{ &hf_camel_scfID,
{ "scfID", "camel.scfID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_DestinationRoutingAddress_item,
{ "CalledPartyNumber", "camel.CalledPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_applicationTimer,
{ "applicationTimer", "camel.applicationTimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_midCallControlInfo,
{ "midCallControlInfo", "camel.midCallControlInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_dpSpecificCriteriaAlt,
{ "dpSpecificCriteriaAlt", "camel.dpSpecificCriteriaAlt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_changeOfPositionControlInfo,
{ "changeOfPositionControlInfo", "camel.changeOfPositionControlInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_numberOfDigits,
{ "numberOfDigits", "camel.numberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_interDigitTimeout,
{ "interDigitTimeout", "camel.interDigitTimeout",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_camel_oServiceChangeSpecificInfo,
{ "oServiceChangeSpecificInfo", "camel.oServiceChangeSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ext_basicServiceCode,
{ "ext-basicServiceCode", "camel.ext_basicServiceCode",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_camel_initiatorOfServiceChange,
{ "initiatorOfServiceChange", "camel.initiatorOfServiceChange",
FT_UINT32, BASE_DEC, VALS(camel_InitiatorOfServiceChange_vals), 0,
NULL, HFILL }},
{ &hf_camel_natureOfServiceChange,
{ "natureOfServiceChange", "camel.natureOfServiceChange",
FT_UINT32, BASE_DEC, VALS(camel_NatureOfServiceChange_vals), 0,
NULL, HFILL }},
{ &hf_camel_tServiceChangeSpecificInfo,
{ "tServiceChangeSpecificInfo", "camel.tServiceChangeSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_collectedInfoSpecificInfo,
{ "collectedInfoSpecificInfo", "camel.collectedInfoSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_calledPartyNumber,
{ "calledPartyNumber", "camel.calledPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeGPRSIfNoTariffSwitch,
{ "timeGPRSIfNoTariffSwitch", "camel.timeGPRSIfNoTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_86400", HFILL }},
{ &hf_camel_timeGPRSIfTariffSwitch,
{ "timeGPRSIfTariffSwitch", "camel.timeGPRSIfTariffSwitch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeGPRSSinceLastTariffSwitch,
{ "timeGPRSSinceLastTariffSwitch", "camel.timeGPRSSinceLastTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_86400", HFILL }},
{ &hf_camel_timeGPRSTariffSwitchInterval,
{ "timeGPRSTariffSwitchInterval", "camel.timeGPRSTariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_86400", HFILL }},
{ &hf_camel_rO_TimeGPRSIfNoTariffSwitch,
{ "rO-TimeGPRSIfNoTariffSwitch", "camel.rO_TimeGPRSIfNoTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_rO_TimeGPRSIfTariffSwitch,
{ "rO-TimeGPRSIfTariffSwitch", "camel.rO_TimeGPRSIfTariffSwitch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_rO_TimeGPRSSinceLastTariffSwitch,
{ "rO-TimeGPRSSinceLastTariffSwitch", "camel.rO_TimeGPRSSinceLastTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_rO_TimeGPRSTariffSwitchInterval,
{ "rO-TimeGPRSTariffSwitchInterval", "camel.rO_TimeGPRSTariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_pDPTypeOrganization,
{ "pDPTypeOrganization", "camel.pDPTypeOrganization",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pDPTypeNumber,
{ "pDPTypeNumber", "camel.pDPTypeNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pDPAddress,
{ "pDPAddress", "camel.pDPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_routeSelectFailureSpecificInfo,
{ "routeSelectFailureSpecificInfo", "camel.routeSelectFailureSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_routeSelectfailureCause,
{ "failureCause", "camel.failureCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_camel_oCalledPartyBusySpecificInfo,
{ "oCalledPartyBusySpecificInfo", "camel.oCalledPartyBusySpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_busyCause,
{ "busyCause", "camel.busyCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_camel_oNoAnswerSpecificInfo,
{ "oNoAnswerSpecificInfo", "camel.oNoAnswerSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_oAnswerSpecificInfo,
{ "oAnswerSpecificInfo", "camel.oAnswerSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_destinationAddress,
{ "destinationAddress", "camel.destinationAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyNumber", HFILL }},
{ &hf_camel_or_Call,
{ "or-Call", "camel.or_Call_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_forwardedCall,
{ "forwardedCall", "camel.forwardedCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_chargeIndicator,
{ "chargeIndicator", "camel.chargeIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_ext_basicServiceCode2,
{ "ext-basicServiceCode2", "camel.ext_basicServiceCode2",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_camel_oMidCallSpecificInfo,
{ "oMidCallSpecificInfo", "camel.oMidCallSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_omidCallEvents,
{ "midCallEvents", "camel.midCallEvents",
FT_UINT32, BASE_DEC, VALS(camel_T_omidCallEvents_vals), 0,
"T_omidCallEvents", HFILL }},
{ &hf_camel_dTMFDigitsCompleted,
{ "dTMFDigitsCompleted", "camel.dTMFDigitsCompleted",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_dTMFDigitsTimeOut,
{ "dTMFDigitsTimeOut", "camel.dTMFDigitsTimeOut",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_oDisconnectSpecificInfo,
{ "oDisconnectSpecificInfo", "camel.oDisconnectSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_releaseCause,
{ "releaseCause", "camel.releaseCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_camel_tBusySpecificInfo,
{ "tBusySpecificInfo", "camel.tBusySpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callForwarded,
{ "callForwarded", "camel.callForwarded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_routeNotPermitted,
{ "routeNotPermitted", "camel.routeNotPermitted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_forwardingDestinationNumber,
{ "forwardingDestinationNumber", "camel.forwardingDestinationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyNumber", HFILL }},
{ &hf_camel_tNoAnswerSpecificInfo,
{ "tNoAnswerSpecificInfo", "camel.tNoAnswerSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tAnswerSpecificInfo,
{ "tAnswerSpecificInfo", "camel.tAnswerSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tMidCallSpecificInfo,
{ "tMidCallSpecificInfo", "camel.tMidCallSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tmidCallEvents,
{ "midCallEvents", "camel.midCallEvents",
FT_UINT32, BASE_DEC, VALS(camel_T_tmidCallEvents_vals), 0,
"T_tmidCallEvents", HFILL }},
{ &hf_camel_tDisconnectSpecificInfo,
{ "tDisconnectSpecificInfo", "camel.tDisconnectSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_oTermSeizedSpecificInfo,
{ "oTermSeizedSpecificInfo", "camel.oTermSeizedSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_locationInformation,
{ "locationInformation", "camel.locationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callAcceptedSpecificInfo,
{ "callAcceptedSpecificInfo", "camel.callAcceptedSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_oAbandonSpecificInfo,
{ "oAbandonSpecificInfo", "camel.oAbandonSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_oChangeOfPositionSpecificInfo,
{ "oChangeOfPositionSpecificInfo", "camel.oChangeOfPositionSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_metDPCriteriaList,
{ "metDPCriteriaList", "camel.metDPCriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tChangeOfPositionSpecificInfo,
{ "tChangeOfPositionSpecificInfo", "camel.tChangeOfPositionSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_dpSpecificInfoAlt,
{ "dpSpecificInfoAlt", "camel.dpSpecificInfoAlt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_o_smsFailureSpecificInfo,
{ "o-smsFailureSpecificInfo", "camel.o_smsFailureSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_smsfailureCause,
{ "failureCause", "camel.failureCause",
FT_UINT32, BASE_DEC, VALS(camel_MO_SMSCause_vals), 0,
"MO_SMSCause", HFILL }},
{ &hf_camel_o_smsSubmissionSpecificInfo,
{ "o-smsSubmissionSpecificInfo", "camel.o_smsSubmissionSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_t_smsFailureSpecificInfo,
{ "t-smsFailureSpecificInfo", "camel.t_smsFailureSpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_t_smsFailureSpecificInfo", HFILL }},
{ &hf_camel_t_smsfailureCause,
{ "failureCause", "camel.failureCause",
FT_BYTES, BASE_NONE, NULL, 0,
"MT_SMSCause", HFILL }},
{ &hf_camel_t_smsDeliverySpecificInfo,
{ "t-smsDeliverySpecificInfo", "camel.t_smsDeliverySpecificInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_t_smsDeliverySpecificInfo", HFILL }},
{ &hf_camel_Extensions_item,
{ "ExtensionField", "camel.ExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_type,
{ "type", "camel.type",
FT_UINT32, BASE_DEC, VALS(camel_Code_vals), 0,
"Code", HFILL }},
{ &hf_camel_criticality,
{ "criticality", "camel.criticality",
FT_UINT32, BASE_DEC, VALS(inap_CriticalityType_vals), 0,
"CriticalityType", HFILL }},
{ &hf_camel_value,
{ "value", "camel.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callDiversionTreatmentIndicator,
{ "callDiversionTreatmentIndicator", "camel.callDiversionTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_callingPartyRestrictionIndicator,
{ "callingPartyRestrictionIndicator", "camel.callingPartyRestrictionIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_compoundGapCriteria,
{ "compoundGapCriteria", "camel.compoundGapCriteria_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompoundCriteria", HFILL }},
{ &hf_camel_gapIndicatorsDuration,
{ "duration", "camel.duration",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gapInterval,
{ "gapInterval", "camel.gapInterval",
FT_INT32, BASE_DEC, NULL, 0,
"Interval", HFILL }},
{ &hf_camel_informationToSend,
{ "informationToSend", "camel.informationToSend",
FT_UINT32, BASE_DEC, VALS(camel_InformationToSend_vals), 0,
NULL, HFILL }},
{ &hf_camel_GenericNumbers_item,
{ "GenericNumber", "camel.GenericNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_short_QoS_format,
{ "short-QoS-format", "camel.short_QoS_format",
FT_BYTES, BASE_NONE, NULL, 0,
"QoS_Subscribed", HFILL }},
{ &hf_camel_long_QoS_format,
{ "long-QoS-format", "camel.long_QoS_format",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_QoS_Subscribed", HFILL }},
{ &hf_camel_supplement_to_long_QoS_format,
{ "supplement-to-long-QoS-format", "camel.supplement_to_long_QoS_format",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext2_QoS_Subscribed", HFILL }},
{ &hf_camel_additionalSupplement,
{ "additionalSupplement", "camel.additionalSupplement",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext3_QoS_Subscribed", HFILL }},
{ &hf_camel_gPRSEventType,
{ "gPRSEventType", "camel.gPRSEventType",
FT_UINT32, BASE_DEC, VALS(camel_GPRSEventType_vals), 0,
NULL, HFILL }},
{ &hf_camel_attachChangeOfPositionSpecificInformation,
{ "attachChangeOfPositionSpecificInformation", "camel.attachChangeOfPositionSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_locationInformationGPRS,
{ "locationInformationGPRS", "camel.locationInformationGPRS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pdp_ContextchangeOfPositionSpecificInformation,
{ "pdp-ContextchangeOfPositionSpecificInformation", "camel.pdp_ContextchangeOfPositionSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_accessPointName,
{ "accessPointName", "camel.accessPointName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_chargingID,
{ "chargingID", "camel.chargingID",
FT_BYTES, BASE_NONE, NULL, 0,
"GPRSChargingID", HFILL }},
{ &hf_camel_endUserAddress,
{ "endUserAddress", "camel.endUserAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_qualityOfService,
{ "qualityOfService", "camel.qualityOfService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeAndTimeZone,
{ "timeAndTimeZone", "camel.timeAndTimeZone",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gGSNAddress,
{ "gGSNAddress", "camel.gGSNAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_camel_detachSpecificInformation,
{ "detachSpecificInformation", "camel.detachSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_initiatingEntity,
{ "initiatingEntity", "camel.initiatingEntity",
FT_UINT32, BASE_DEC, VALS(camel_InitiatingEntity_vals), 0,
NULL, HFILL }},
{ &hf_camel_routeingAreaUpdate,
{ "routeingAreaUpdate", "camel.routeingAreaUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_disconnectSpecificInformation,
{ "disconnectSpecificInformation", "camel.disconnectSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pDPContextEstablishmentSpecificInformation,
{ "pDPContextEstablishmentSpecificInformation", "camel.pDPContextEstablishmentSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pDPInitiationType,
{ "pDPInitiationType", "camel.pDPInitiationType",
FT_UINT32, BASE_DEC, VALS(camel_PDPInitiationType_vals), 0,
NULL, HFILL }},
{ &hf_camel_secondaryPDP_context,
{ "secondaryPDP-context", "camel.secondaryPDP_context_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_pDPContextEstablishmentAcknowledgementSpecificInformation,
{ "pDPContextEstablishmentAcknowledgementSpecificInformation", "camel.pDPContextEstablishmentAcknowledgementSpecificInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_messageID,
{ "messageID", "camel.messageID",
FT_UINT32, BASE_DEC, VALS(camel_MessageID_vals), 0,
NULL, HFILL }},
{ &hf_camel_numberOfRepetitions,
{ "numberOfRepetitions", "camel.numberOfRepetitions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_camel_inbandInfoDuration,
{ "duration", "camel.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_camel_interval,
{ "interval", "camel.interval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_camel_inbandInfo,
{ "inbandInfo", "camel.inbandInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tone,
{ "tone", "camel.tone_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_cellGlobalIdOrServiceAreaIdOrLAI,
{ "cellGlobalIdOrServiceAreaIdOrLAI", "camel.cellGlobalIdOrServiceAreaIdOrLAI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_routeingAreaIdentity,
{ "routeingAreaIdentity", "camel.routeingAreaIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"RAIdentity", HFILL }},
{ &hf_camel_geographicalInformation,
{ "geographicalInformation", "camel.geographicalInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_sgsn_Number,
{ "sgsn-Number", "camel.sgsn_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_selectedLSAIdentity,
{ "selectedLSAIdentity", "camel.selectedLSAIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"LSAIdentity", HFILL }},
{ &hf_camel_extensionContainer,
{ "extensionContainer", "camel.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_sai_Present,
{ "sai-Present", "camel.sai_Present_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_userCSGInformation,
{ "userCSGInformation", "camel.userCSGInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_elementaryMessageID,
{ "elementaryMessageID", "camel.elementaryMessageID",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_text,
{ "text", "camel.text_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_messageContent,
{ "messageContent", "camel.messageContent",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_bound__minMessageContentLength_bound__maxMessageContentLength", HFILL }},
{ &hf_camel_attributes,
{ "attributes", "camel.attributes",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_bound__minAttributesLength_bound__maxAttributesLength", HFILL }},
{ &hf_camel_elementaryMessageIDs,
{ "elementaryMessageIDs", "camel.elementaryMessageIDs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_bound__numOfMessageIDs_OF_Integer4", HFILL }},
{ &hf_camel_elementaryMessageIDs_item,
{ "Integer4", "camel.Integer4",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_variableMessage,
{ "variableMessage", "camel.variableMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_variableParts,
{ "variableParts", "camel.variableParts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_5_OF_VariablePart", HFILL }},
{ &hf_camel_variableParts_item,
{ "VariablePart", "camel.VariablePart",
FT_UINT32, BASE_DEC, VALS(camel_VariablePart_vals), 0,
NULL, HFILL }},
{ &hf_camel_MetDPCriteriaList_item,
{ "MetDPCriterion", "camel.MetDPCriterion",
FT_UINT32, BASE_DEC, VALS(camel_MetDPCriterion_vals), 0,
NULL, HFILL }},
{ &hf_camel_enteringCellGlobalId,
{ "enteringCellGlobalId", "camel.enteringCellGlobalId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_leavingCellGlobalId,
{ "leavingCellGlobalId", "camel.leavingCellGlobalId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_enteringServiceAreaId,
{ "enteringServiceAreaId", "camel.enteringServiceAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_leavingServiceAreaId,
{ "leavingServiceAreaId", "camel.leavingServiceAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_camel_enteringLocationAreaId,
{ "enteringLocationAreaId", "camel.enteringLocationAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"LAIFixedLength", HFILL }},
{ &hf_camel_leavingLocationAreaId,
{ "leavingLocationAreaId", "camel.leavingLocationAreaId",
FT_BYTES, BASE_NONE, NULL, 0,
"LAIFixedLength", HFILL }},
{ &hf_camel_inter_SystemHandOverToUMTS,
{ "inter-SystemHandOverToUMTS", "camel.inter_SystemHandOverToUMTS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_inter_SystemHandOverToGSM,
{ "inter-SystemHandOverToGSM", "camel.inter_SystemHandOverToGSM_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_metDPCriterionAlt,
{ "metDPCriterionAlt", "camel.metDPCriterionAlt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_minimumNumberOfDigits,
{ "minimumNumberOfDigits", "camel.minimumNumberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_30", HFILL }},
{ &hf_camel_maximumNumberOfDigits,
{ "maximumNumberOfDigits", "camel.maximumNumberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_30", HFILL }},
{ &hf_camel_requested_QoS,
{ "requested-QoS", "camel.requested_QoS",
FT_UINT32, BASE_DEC, VALS(camel_GPRS_QoS_vals), 0,
"GPRS_QoS", HFILL }},
{ &hf_camel_subscribed_QoS,
{ "subscribed-QoS", "camel.subscribed_QoS",
FT_UINT32, BASE_DEC, VALS(camel_GPRS_QoS_vals), 0,
"GPRS_QoS", HFILL }},
{ &hf_camel_negotiated_QoS,
{ "negotiated-QoS", "camel.negotiated_QoS",
FT_UINT32, BASE_DEC, VALS(camel_GPRS_QoS_vals), 0,
"GPRS_QoS", HFILL }},
{ &hf_camel_requested_QoS_Extension,
{ "requested-QoS-Extension", "camel.requested_QoS_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPRS_QoS_Extension", HFILL }},
{ &hf_camel_subscribed_QoS_Extension,
{ "subscribed-QoS-Extension", "camel.subscribed_QoS_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPRS_QoS_Extension", HFILL }},
{ &hf_camel_negotiated_QoS_Extension,
{ "negotiated-QoS-Extension", "camel.negotiated_QoS_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPRS_QoS_Extension", HFILL }},
{ &hf_camel_receivingSideID,
{ "receivingSideID", "camel.receivingSideID",
FT_BYTES, BASE_NONE, NULL, 0,
"LegType", HFILL }},
{ &hf_camel_RequestedInformationList_item,
{ "RequestedInformation", "camel.RequestedInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_RequestedInformationTypeList_item,
{ "RequestedInformationType", "camel.RequestedInformationType",
FT_UINT32, BASE_DEC, VALS(camel_RequestedInformationType_vals), 0,
NULL, HFILL }},
{ &hf_camel_requestedInformationType,
{ "requestedInformationType", "camel.requestedInformationType",
FT_UINT32, BASE_DEC, VALS(camel_RequestedInformationType_vals), 0,
NULL, HFILL }},
{ &hf_camel_requestedInformationValue,
{ "requestedInformationValue", "camel.requestedInformationValue",
FT_UINT32, BASE_DEC, VALS(camel_RequestedInformationValue_vals), 0,
NULL, HFILL }},
{ &hf_camel_callAttemptElapsedTimeValue,
{ "callAttemptElapsedTimeValue", "camel.callAttemptElapsedTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_callStopTimeValue,
{ "callStopTimeValue", "camel.callStopTimeValue",
FT_STRING, BASE_NONE, NULL, 0,
"DateAndTime", HFILL }},
{ &hf_camel_callConnectedElapsedTimeValue,
{ "callConnectedElapsedTimeValue", "camel.callConnectedElapsedTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_releaseCauseValue,
{ "releaseCauseValue", "camel.releaseCauseValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_camel_sendingSideID,
{ "sendingSideID", "camel.sendingSideID",
FT_BYTES, BASE_NONE, NULL, 0,
"LegType", HFILL }},
{ &hf_camel_forwardServiceInteractionInd,
{ "forwardServiceInteractionInd", "camel.forwardServiceInteractionInd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_backwardServiceInteractionInd,
{ "backwardServiceInteractionInd", "camel.backwardServiceInteractionInd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bothwayThroughConnectionInd,
{ "bothwayThroughConnectionInd", "camel.bothwayThroughConnectionInd",
FT_UINT32, BASE_DEC, VALS(inap_BothwayThroughConnectionInd_vals), 0,
NULL, HFILL }},
{ &hf_camel_connectedNumberTreatmentInd,
{ "connectedNumberTreatmentInd", "camel.connectedNumberTreatmentInd",
FT_UINT32, BASE_DEC, VALS(camel_ConnectedNumberTreatmentInd_vals), 0,
NULL, HFILL }},
{ &hf_camel_nonCUGCall,
{ "nonCUGCall", "camel.nonCUGCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_holdTreatmentIndicator,
{ "holdTreatmentIndicator", "camel.holdTreatmentIndicator",
FT_INT32, BASE_DEC, VALS(camel_holdTreatmentIndicator_values), 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_cwTreatmentIndicator,
{ "cwTreatmentIndicator", "camel.cwTreatmentIndicator",
FT_INT32, BASE_DEC, VALS(camel_cwTreatmentIndicator_values), 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_ectTreatmentIndicator,
{ "ectTreatmentIndicator", "camel.ectTreatmentIndicator",
FT_INT32, BASE_DEC, VALS(camel_ectTreatmentIndicator_values), 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_camel_eventTypeSMS,
{ "eventTypeSMS", "camel.eventTypeSMS",
FT_UINT32, BASE_DEC, VALS(camel_EventTypeSMS_vals), 0,
NULL, HFILL }},
{ &hf_camel_timeSinceTariffSwitch,
{ "timeSinceTariffSwitch", "camel.timeSinceTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_864000", HFILL }},
{ &hf_camel_timeIfTariffSwitch_tariffSwitchInterval,
{ "tariffSwitchInterval", "camel.tariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_864000", HFILL }},
{ &hf_camel_timeIfNoTariffSwitch,
{ "timeIfNoTariffSwitch", "camel.timeIfNoTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeIfTariffSwitch,
{ "timeIfTariffSwitch", "camel.timeIfTariffSwitch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_toneID,
{ "toneID", "camel.toneID",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_toneDuration,
{ "duration", "camel.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_volumeIfNoTariffSwitch,
{ "volumeIfNoTariffSwitch", "camel.volumeIfNoTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_camel_volumeIfTariffSwitch,
{ "volumeIfTariffSwitch", "camel.volumeIfTariffSwitch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_volumeSinceLastTariffSwitch,
{ "volumeSinceLastTariffSwitch", "camel.volumeSinceLastTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_camel_volumeTariffSwitchInterval,
{ "volumeTariffSwitchInterval", "camel.volumeTariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_camel_rO_VolumeIfNoTariffSwitch,
{ "rO-VolumeIfNoTariffSwitch", "camel.rO_VolumeIfNoTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_rO_VolumeIfTariffSwitch,
{ "rO-VolumeIfTariffSwitch", "camel.rO_VolumeIfTariffSwitch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_rO_VolumeSinceLastTariffSwitch,
{ "rO-VolumeSinceLastTariffSwitch", "camel.rO_VolumeSinceLastTariffSwitch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_rO_VolumeTariffSwitchInterval,
{ "rO-VolumeTariffSwitchInterval", "camel.rO_VolumeTariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_camel_integer,
{ "integer", "camel.integer",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_number,
{ "number", "camel.number",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_time,
{ "time", "camel.time",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_camel_date,
{ "date", "camel.date",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_camel_price,
{ "price", "camel.price",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_camel_par_cancelFailedProblem,
{ "problem", "camel.problem",
FT_UINT32, BASE_DEC, VALS(camel_T_par_cancelFailedProblem_vals), 0,
"T_par_cancelFailedProblem", HFILL }},
{ &hf_camel_operation,
{ "operation", "camel.operation",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeID", HFILL }},
{ &hf_camel_destinationReference,
{ "destinationReference", "camel.destinationReference",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_originationReference,
{ "originationReference", "camel.originationReference",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_camel_disconnectFromIPForbidden,
{ "disconnectFromIPForbidden", "camel.disconnectFromIPForbidden",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_requestAnnouncementCompleteNotification,
{ "requestAnnouncementCompleteNotification", "camel.requestAnnouncementCompleteNotification",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_requestAnnouncementStartedNotification,
{ "requestAnnouncementStartedNotification", "camel.requestAnnouncementStartedNotification",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_collectedInfo,
{ "collectedInfo", "camel.collectedInfo",
FT_UINT32, BASE_DEC, VALS(camel_CollectedInfo_vals), 0,
NULL, HFILL }},
{ &hf_camel_digitsResponse,
{ "digitsResponse", "camel.digitsResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_camel_allAnnouncementsComplete,
{ "allAnnouncementsComplete", "camel.allAnnouncementsComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_firstAnnouncementStarted,
{ "firstAnnouncementStarted", "camel.firstAnnouncementStarted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_aChBillingChargingCharacteristics,
{ "aChBillingChargingCharacteristics", "camel.aChBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_partyToCharge,
{ "partyToCharge", "camel.partyToCharge",
FT_UINT32, BASE_DEC, VALS(camel_SendingSideID_vals), 0,
"SendingSideID", HFILL }},
{ &hf_camel_iTXcharging,
{ "iTXcharging", "camel.iTXcharging",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_correlationID,
{ "correlationID", "camel.correlationID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_iPSSPCapabilities,
{ "iPSSPCapabilities", "camel.iPSSPCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gapCriteria,
{ "gapCriteria", "camel.gapCriteria",
FT_UINT32, BASE_DEC, VALS(camel_GapCriteria_vals), 0,
NULL, HFILL }},
{ &hf_camel_gapIndicators,
{ "gapIndicators", "camel.gapIndicators_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_controlType,
{ "controlType", "camel.controlType",
FT_UINT32, BASE_DEC, VALS(camel_ControlType_vals), 0,
NULL, HFILL }},
{ &hf_camel_gapTreatment,
{ "gapTreatment", "camel.gapTreatment",
FT_UINT32, BASE_DEC, VALS(camel_GapTreatment_vals), 0,
NULL, HFILL }},
{ &hf_camel_requestedInformationList,
{ "requestedInformationList", "camel.requestedInformationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legID_01,
{ "legID", "camel.legID",
FT_UINT32, BASE_DEC, VALS(camel_ReceivingSideID_vals), 0,
"ReceivingSideID", HFILL }},
{ &hf_camel_requestedInformationTypeList,
{ "requestedInformationTypeList", "camel.requestedInformationTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legID_02,
{ "legID", "camel.legID",
FT_UINT32, BASE_DEC, VALS(camel_SendingSideID_vals), 0,
"SendingSideID", HFILL }},
{ &hf_camel_allRequests,
{ "allRequests", "camel.allRequests_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callSegmentToCancel,
{ "callSegmentToCancel", "camel.callSegmentToCancel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_destinationRoutingAddress,
{ "destinationRoutingAddress", "camel.destinationRoutingAddress",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_alertingPattern,
{ "alertingPattern", "camel.alertingPattern",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_originalCalledPartyID,
{ "originalCalledPartyID", "camel.originalCalledPartyID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_carrier,
{ "carrier", "camel.carrier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callingPartysCategory,
{ "callingPartysCategory", "camel.callingPartysCategory",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &isup_calling_partys_category_value_ext, 0,
NULL, HFILL }},
{ &hf_camel_redirectingPartyID,
{ "redirectingPartyID", "camel.redirectingPartyID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_redirectionInformation,
{ "redirectionInformation", "camel.redirectionInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_genericNumbers,
{ "genericNumbers", "camel.genericNumbers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_serviceInteractionIndicatorsTwo,
{ "serviceInteractionIndicatorsTwo", "camel.serviceInteractionIndicatorsTwo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_chargeNumber,
{ "chargeNumber", "camel.chargeNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legToBeConnected,
{ "legToBeConnected", "camel.legToBeConnected",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_camel_cug_Interlock,
{ "cug-Interlock", "camel.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_cug_OutgoingAccess,
{ "cug-OutgoingAccess", "camel.cug_OutgoingAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_suppressionOfAnnouncement,
{ "suppressionOfAnnouncement", "camel.suppressionOfAnnouncement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_oCSIApplicable,
{ "oCSIApplicable", "camel.oCSIApplicable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_naOliInfo,
{ "naOliInfo", "camel.naOliInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bor_InterrogationRequested,
{ "bor-InterrogationRequested", "camel.bor_InterrogationRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_suppress_N_CSI,
{ "suppress-N-CSI", "camel.suppress_N_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_resourceAddress,
{ "resourceAddress", "camel.resourceAddress",
FT_UINT32, BASE_DEC, VALS(camel_T_resourceAddress_vals), 0,
NULL, HFILL }},
{ &hf_camel_ipRoutingAddress,
{ "ipRoutingAddress", "camel.ipRoutingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_none,
{ "none", "camel.none_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_suppress_O_CSI,
{ "suppress-O-CSI", "camel.suppress_O_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_continueWithArgumentArgExtension,
{ "continueWithArgumentArgExtension", "camel.continueWithArgumentArgExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_suppress_D_CSI,
{ "suppress-D-CSI", "camel.suppress_D_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_suppressOutgoingCallBarring,
{ "suppressOutgoingCallBarring", "camel.suppressOutgoingCallBarring_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legOrCallSegment,
{ "legOrCallSegment", "camel.legOrCallSegment",
FT_UINT32, BASE_DEC, VALS(camel_LegOrCallSegment_vals), 0,
NULL, HFILL }},
{ &hf_camel_legToBeReleased,
{ "legToBeReleased", "camel.legToBeReleased",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_camel_callSegmentFailure,
{ "callSegmentFailure", "camel.callSegmentFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bCSM_Failure,
{ "bCSM-Failure", "camel.bCSM_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_assistingSSPIPRoutingAddress,
{ "assistingSSPIPRoutingAddress", "camel.assistingSSPIPRoutingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callingPartyNumber,
{ "callingPartyNumber", "camel.callingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_eventSpecificInformationBCSM,
{ "eventSpecificInformationBCSM", "camel.eventSpecificInformationBCSM",
FT_UINT32, BASE_DEC, VALS(camel_EventSpecificInformationBCSM_vals), 0,
NULL, HFILL }},
{ &hf_camel_miscCallInfo,
{ "miscCallInfo", "camel.miscCallInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_cGEncountered,
{ "cGEncountered", "camel.cGEncountered",
FT_UINT32, BASE_DEC, VALS(camel_CGEncountered_vals), 0,
NULL, HFILL }},
{ &hf_camel_locationNumber,
{ "locationNumber", "camel.locationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_highLayerCompatibility,
{ "highLayerCompatibility", "camel.highLayerCompatibility",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_additionalCallingPartyNumber,
{ "additionalCallingPartyNumber", "camel.additionalCallingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bearerCapability,
{ "bearerCapability", "camel.bearerCapability",
FT_UINT32, BASE_DEC, VALS(camel_BearerCapability_vals), 0,
NULL, HFILL }},
{ &hf_camel_cug_Index,
{ "cug-Index", "camel.cug_Index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_iMSI,
{ "iMSI", "camel.iMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_subscriberState,
{ "subscriberState", "camel.subscriberState",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SubscriberState_vals), 0,
NULL, HFILL }},
{ &hf_camel_callReferenceNumber,
{ "callReferenceNumber", "camel.callReferenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_mscAddress,
{ "mscAddress", "camel.mscAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_calledPartyBCDNumber,
{ "calledPartyBCDNumber", "camel.calledPartyBCDNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timeAndTimezone,
{ "timeAndTimezone", "camel.timeAndTimezone",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callForwardingSS_Pending,
{ "callForwardingSS-Pending", "camel.callForwardingSS_Pending_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_initialDPArgExtension,
{ "initialDPArgExtension", "camel.initialDPArgExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gmscAddress,
{ "gmscAddress", "camel.gmscAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_ms_Classmark2,
{ "ms-Classmark2", "camel.ms_Classmark2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_iMEI,
{ "iMEI", "camel.iMEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_supportedCamelPhases,
{ "supportedCamelPhases", "camel.supportedCamelPhases",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_offeredCamel4Functionalities,
{ "offeredCamel4Functionalities", "camel.offeredCamel4Functionalities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bearerCapability2,
{ "bearerCapability2", "camel.bearerCapability2",
FT_UINT32, BASE_DEC, VALS(camel_BearerCapability_vals), 0,
"BearerCapability", HFILL }},
{ &hf_camel_highLayerCompatibility2,
{ "highLayerCompatibility2", "camel.highLayerCompatibility2",
FT_BYTES, BASE_NONE, NULL, 0,
"HighLayerCompatibility", HFILL }},
{ &hf_camel_lowLayerCompatibility,
{ "lowLayerCompatibility", "camel.lowLayerCompatibility",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_lowLayerCompatibility2,
{ "lowLayerCompatibility2", "camel.lowLayerCompatibility2",
FT_BYTES, BASE_NONE, NULL, 0,
"LowLayerCompatibility", HFILL }},
{ &hf_camel_enhancedDialledServicesAllowed,
{ "enhancedDialledServicesAllowed", "camel.enhancedDialledServicesAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_uu_Data,
{ "uu-Data", "camel.uu_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_collectInformationAllowed,
{ "collectInformationAllowed", "camel.collectInformationAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_releaseCallArgExtensionAllowed,
{ "releaseCallArgExtensionAllowed", "camel.releaseCallArgExtensionAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legToBeCreated,
{ "legToBeCreated", "camel.legToBeCreated",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_camel_newCallSegment,
{ "newCallSegment", "camel.newCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_camel_gsmSCFAddress,
{ "gsmSCFAddress", "camel.gsmSCFAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_suppress_T_CSI,
{ "suppress-T-CSI", "camel.suppress_T_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legIDToMove,
{ "legIDToMove", "camel.legIDToMove",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_camel_allCallSegments,
{ "allCallSegments", "camel.allCallSegments",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_allCallSegmentsWithExtension,
{ "allCallSegmentsWithExtension", "camel.allCallSegmentsWithExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_bcsmEvents,
{ "bcsmEvents", "camel.bcsmEvents",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_bound__numOfBCSMEvents_OF_BCSMEvent", HFILL }},
{ &hf_camel_bcsmEvents_item,
{ "BCSMEvent", "camel.BCSMEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_timerID,
{ "timerID", "camel.timerID",
FT_UINT32, BASE_DEC, VALS(camel_TimerID_vals), 0,
NULL, HFILL }},
{ &hf_camel_timervalue,
{ "timervalue", "camel.timervalue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_sCIBillingChargingCharacteristics,
{ "sCIBillingChargingCharacteristics", "camel.sCIBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_legToBeSplit,
{ "legToBeSplit", "camel.legToBeSplit",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_camel_chargingCharacteristics,
{ "chargingCharacteristics", "camel.chargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_ChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_applyChargingGPRS_tariffSwitchInterval,
{ "tariffSwitchInterval", "camel.tariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_camel_chargingResult,
{ "chargingResult", "camel.chargingResult",
FT_UINT32, BASE_DEC, VALS(camel_ChargingResult_vals), 0,
NULL, HFILL }},
{ &hf_camel_active,
{ "active", "camel.active",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_chargingRollOver,
{ "chargingRollOver", "camel.chargingRollOver",
FT_UINT32, BASE_DEC, VALS(camel_ChargingRollOver_vals), 0,
NULL, HFILL }},
{ &hf_camel_pdpID,
{ "pdpID", "camel.pdpID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gPRSCause,
{ "gPRSCause", "camel.gPRSCause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_miscGPRSInfo,
{ "miscGPRSInfo", "camel.miscGPRSInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"MiscCallInfo", HFILL }},
{ &hf_camel_gPRSEventSpecificInformation,
{ "gPRSEventSpecificInformation", "camel.gPRSEventSpecificInformation",
FT_UINT32, BASE_DEC, VALS(camel_GPRSEventSpecificInformation_vals), 0,
NULL, HFILL }},
{ &hf_camel_mSISDN,
{ "mSISDN", "camel.mSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_gPRSMSClass,
{ "gPRSMSClass", "camel.gPRSMSClass_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_sGSNCapabilities,
{ "sGSNCapabilities", "camel.sGSNCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gprsCause,
{ "gprsCause", "camel.gprsCause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_gPRSEvent,
{ "gPRSEvent", "camel.gPRSEvent",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_bound__numOfGPRSEvents_OF_GPRSEvent", HFILL }},
{ &hf_camel_gPRSEvent_item,
{ "GPRSEvent", "camel.GPRSEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_sCIGPRSBillingChargingCharacteristics,
{ "sCIGPRSBillingChargingCharacteristics", "camel.sCIGPRSBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_callingPartysNumber,
{ "callingPartysNumber", "camel.callingPartysNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"SMS_AddressString", HFILL }},
{ &hf_camel_destinationSubscriberNumber,
{ "destinationSubscriberNumber", "camel.destinationSubscriberNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyBCDNumber", HFILL }},
{ &hf_camel_sMSCAddress,
{ "sMSCAddress", "camel.sMSCAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_eventSpecificInformationSMS,
{ "eventSpecificInformationSMS", "camel.eventSpecificInformationSMS",
FT_UINT32, BASE_DEC, VALS(camel_EventSpecificInformationSMS_vals), 0,
NULL, HFILL }},
{ &hf_camel_callingPartyNumber_01,
{ "callingPartyNumber", "camel.callingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"SMS_AddressString", HFILL }},
{ &hf_camel_locationInformationMSC,
{ "locationInformationMSC", "camel.locationInformationMSC_element",
FT_NONE, BASE_NONE, NULL, 0,
"LocationInformation", HFILL }},
{ &hf_camel_tPShortMessageSpecificInfo,
{ "tPShortMessageSpecificInfo", "camel.tPShortMessageSpecificInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tPProtocolIdentifier,
{ "tPProtocolIdentifier", "camel.tPProtocolIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tPDataCodingScheme,
{ "tPDataCodingScheme", "camel.tPDataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tPValidityPeriod,
{ "tPValidityPeriod", "camel.tPValidityPeriod",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_smsReferenceNumber,
{ "smsReferenceNumber", "camel.smsReferenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"CallReferenceNumber", HFILL }},
{ &hf_camel_calledPartyNumber_01,
{ "calledPartyNumber", "camel.calledPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_camel_sMSEvents,
{ "sMSEvents", "camel.sMSEvents",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_bound__numOfSMSEvents_OF_SMSEvent", HFILL }},
{ &hf_camel_sMSEvents_item,
{ "SMSEvent", "camel.SMSEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_naCarrierInformation,
{ "naCarrierInformation", "camel.naCarrierInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_naCarrierId,
{ "naCarrierId", "camel.naCarrierId",
FT_BYTES, BASE_NONE, NULL, 0,
"NAEA_CIC", HFILL }},
{ &hf_camel_naCICSelectionType,
{ "naCICSelectionType", "camel.naCICSelectionType",
FT_BYTES, BASE_NONE, NULL, 0,
"NACarrierSelectionInfo", HFILL }},
{ &hf_camel_timeDurationCharging_01,
{ "timeDurationCharging", "camel.timeDurationCharging_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_timeDurationCharging_01", HFILL }},
{ &hf_camel_releaseIfdurationExceeded_01,
{ "releaseIfdurationExceeded", "camel.releaseIfdurationExceeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_tariffSwitchInterval,
{ "tariffSwitchInterval", "camel.tariffSwitchInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_camel_tone_01,
{ "tone", "camel.tone",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_camel_extensions_01,
{ "extensions", "camel.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField", HFILL }},
{ &hf_camel_extensions_item,
{ "ExtensionField", "camel.ExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_local,
{ "local", "camel.local",
FT_INT32, BASE_DEC, VALS(camel_opr_code_strings), 0,
NULL, HFILL }},
{ &hf_camel_global,
{ "global", "camel.global",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_invoke,
{ "invoke", "camel.invoke_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_returnResult,
{ "returnResult", "camel.returnResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_returnError,
{ "returnError", "camel.returnError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_reject,
{ "reject", "camel.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_invokeId,
{ "invokeId", "camel.invokeId",
FT_UINT32, BASE_DEC, VALS(camel_InvokeId_vals), 0,
NULL, HFILL }},
{ &hf_camel_linkedId,
{ "linkedId", "camel.linkedId",
FT_UINT32, BASE_DEC, VALS(camel_T_linkedId_vals), 0,
NULL, HFILL }},
{ &hf_camel_linkedIdPresent,
{ "present", "camel.present",
FT_INT32, BASE_DEC, NULL, 0,
"T_linkedIdPresent", HFILL }},
{ &hf_camel_absent,
{ "absent", "camel.absent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_opcode,
{ "opcode", "camel.opcode",
FT_UINT32, BASE_DEC, VALS(camel_Code_vals), 0,
"Code", HFILL }},
{ &hf_camel_argument,
{ "argument", "camel.argument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_result,
{ "result", "camel.result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_resultArgument,
{ "result", "camel.result_element",
FT_NONE, BASE_NONE, NULL, 0,
"ResultArgument", HFILL }},
{ &hf_camel_errcode,
{ "errcode", "camel.errcode",
FT_UINT32, BASE_DEC, VALS(camel_Code_vals), 0,
"Code", HFILL }},
{ &hf_camel_parameter,
{ "parameter", "camel.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_camel_problem,
{ "problem", "camel.problem",
FT_UINT32, BASE_DEC, VALS(camel_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_camel_general,
{ "general", "camel.general",
FT_INT32, BASE_DEC, VALS(camel_GeneralProblem_vals), 0,
"GeneralProblem", HFILL }},
{ &hf_camel_invokeProblem,
{ "invoke", "camel.invoke",
FT_INT32, BASE_DEC, VALS(camel_InvokeProblem_vals), 0,
"InvokeProblem", HFILL }},
{ &hf_camel_problemReturnResult,
{ "returnResult", "camel.returnResult",
FT_INT32, BASE_DEC, VALS(camel_ReturnResultProblem_vals), 0,
"ReturnResultProblem", HFILL }},
{ &hf_camel_returnErrorProblem,
{ "returnError", "camel.returnError",
FT_INT32, BASE_DEC, VALS(camel_ReturnErrorProblem_vals), 0,
"ReturnErrorProblem", HFILL }},
{ &hf_camel_present,
{ "present", "camel.present",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_camel_InvokeId_present,
{ "InvokeId.present", "camel.InvokeId_present",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeId_present", HFILL }},
#line 1394 "../../asn1/camel/packet-camel-template.c"
};
static gint *ett[] = {
&ett_camel,
&ett_camelisup_parameter,
&ett_camel_AccessPointName,
&ett_camel_pdptypenumber,
&ett_camel_cause,
&ett_camel_RPcause,
&ett_camel_stat,
&ett_camel_calledpartybcdnumber,
&ett_camel_callingpartynumber,
&ett_camel_locationnumber,
#line 1 "../../asn1/camel/packet-camel-ettarr.c"
&ett_camel_AChChargingAddress,
&ett_camel_AOCBeforeAnswer,
&ett_camel_AOCGPRS,
&ett_camel_AOCSubsequent,
&ett_camel_AudibleIndicator,
&ett_camel_BackwardServiceInteractionInd,
&ett_camel_BasicGapCriteria,
&ett_camel_T_calledAddressAndService,
&ett_camel_T_callingAddressAndService,
&ett_camel_BCSMEvent,
&ett_camel_BCSM_Failure,
&ett_camel_BearerCapability,
&ett_camel_Burst,
&ett_camel_BurstList,
&ett_camel_CAI_GSM0224,
&ett_camel_CallSegmentFailure,
&ett_camel_CallSegmentToCancel,
&ett_camel_CAMEL_AChBillingChargingCharacteristics,
&ett_camel_T_timeDurationCharging,
&ett_camel_CAMEL_CallResult,
&ett_camel_T_timeDurationChargingResult,
&ett_camel_CAMEL_FCIBillingChargingCharacteristics,
&ett_camel_T_fci_fCIBCCCAMELsequence1,
&ett_camel_CAMEL_FCIGPRSBillingChargingCharacteristics,
&ett_camel_T_fciGPRS_fCIBCCCAMELsequence1,
&ett_camel_CAMEL_FCISMSBillingChargingCharacteristics,
&ett_camel_T_fciSMS_fCIBCCCAMELsequence1,
&ett_camel_CAMEL_SCIBillingChargingCharacteristics,
&ett_camel_CAMEL_SCIBillingChargingCharacteristicsAlt,
&ett_camel_CAMEL_SCIGPRSBillingChargingCharacteristics,
&ett_camel_ChangeOfPositionControlInfo,
&ett_camel_ChangeOfLocation,
&ett_camel_ChangeOfLocationAlt,
&ett_camel_ChargingCharacteristics,
&ett_camel_ChargingResult,
&ett_camel_ChargingRollOver,
&ett_camel_CollectedDigits,
&ett_camel_CollectedInfo,
&ett_camel_CompoundCriteria,
&ett_camel_DestinationRoutingAddress,
&ett_camel_DpSpecificCriteria,
&ett_camel_DpSpecificCriteriaAlt,
&ett_camel_DpSpecificInfoAlt,
&ett_camel_T_oServiceChangeSpecificInfo,
&ett_camel_T_tServiceChangeSpecificInfo,
&ett_camel_T_collectedInfoSpecificInfo,
&ett_camel_ElapsedTime,
&ett_camel_T_timeGPRSIfTariffSwitch,
&ett_camel_ElapsedTimeRollOver,
&ett_camel_T_rO_TimeGPRSIfTariffSwitch,
&ett_camel_EndUserAddress,
&ett_camel_EventSpecificInformationBCSM,
&ett_camel_T_routeSelectFailureSpecificInfo,
&ett_camel_T_oCalledPartyBusySpecificInfo,
&ett_camel_T_oNoAnswerSpecificInfo,
&ett_camel_T_oAnswerSpecificInfo,
&ett_camel_T_oMidCallSpecificInfo,
&ett_camel_T_omidCallEvents,
&ett_camel_T_oDisconnectSpecificInfo,
&ett_camel_T_tBusySpecificInfo,
&ett_camel_T_tNoAnswerSpecificInfo,
&ett_camel_T_tAnswerSpecificInfo,
&ett_camel_T_tMidCallSpecificInfo,
&ett_camel_T_tmidCallEvents,
&ett_camel_T_tDisconnectSpecificInfo,
&ett_camel_T_oTermSeizedSpecificInfo,
&ett_camel_T_callAcceptedSpecificInfo,
&ett_camel_T_oAbandonSpecificInfo,
&ett_camel_T_oChangeOfPositionSpecificInfo,
&ett_camel_T_tChangeOfPositionSpecificInfo,
&ett_camel_EventSpecificInformationSMS,
&ett_camel_T_o_smsFailureSpecificInfo,
&ett_camel_T_o_smsSubmissionSpecificInfo,
&ett_camel_T_t_smsFailureSpecificInfo,
&ett_camel_T_t_smsDeliverySpecificInfo,
&ett_camel_Extensions,
&ett_camel_ExtensionField,
&ett_camel_ForwardServiceInteractionInd,
&ett_camel_GapCriteria,
&ett_camel_GapIndicators,
&ett_camel_GapOnService,
&ett_camel_GapTreatment,
&ett_camel_GenericNumbers,
&ett_camel_GPRS_QoS,
&ett_camel_GPRS_QoS_Extension,
&ett_camel_GPRSEvent,
&ett_camel_GPRSEventSpecificInformation,
&ett_camel_T_attachChangeOfPositionSpecificInformation,
&ett_camel_T_pdp_ContextchangeOfPositionSpecificInformation,
&ett_camel_T_detachSpecificInformation,
&ett_camel_T_disconnectSpecificInformation,
&ett_camel_T_pDPContextEstablishmentSpecificInformation,
&ett_camel_T_pDPContextEstablishmentAcknowledgementSpecificInformation,
&ett_camel_InbandInfo,
&ett_camel_InformationToSend,
&ett_camel_LegOrCallSegment,
&ett_camel_LocationInformationGPRS,
&ett_camel_MessageID,
&ett_camel_T_text,
&ett_camel_SEQUENCE_SIZE_1_bound__numOfMessageIDs_OF_Integer4,
&ett_camel_T_variableMessage,
&ett_camel_SEQUENCE_SIZE_1_5_OF_VariablePart,
&ett_camel_MetDPCriteriaList,
&ett_camel_MetDPCriterion,
&ett_camel_MetDPCriterionAlt,
&ett_camel_MidCallControlInfo,
&ett_camel_QualityOfService,
&ett_camel_ReceivingSideID,
&ett_camel_RequestedInformationList,
&ett_camel_RequestedInformationTypeList,
&ett_camel_RequestedInformation,
&ett_camel_RequestedInformationValue,
&ett_camel_SendingSideID,
&ett_camel_ServiceInteractionIndicatorsTwo,
&ett_camel_SMSEvent,
&ett_camel_TimeIfTariffSwitch,
&ett_camel_TimeInformation,
&ett_camel_Tone,
&ett_camel_TransferredVolume,
&ett_camel_T_volumeIfTariffSwitch,
&ett_camel_TransferredVolumeRollOver,
&ett_camel_T_rO_VolumeIfTariffSwitch,
&ett_camel_VariablePart,
&ett_camel_PAR_cancelFailed,
&ett_camel_CAP_GPRS_ReferenceNumber,
&ett_camel_PlayAnnouncementArg,
&ett_camel_PromptAndCollectUserInformationArg,
&ett_camel_ReceivedInformationArg,
&ett_camel_SpecializedResourceReportArg,
&ett_camel_ApplyChargingArg,
&ett_camel_AssistRequestInstructionsArg,
&ett_camel_CallGapArg,
&ett_camel_CallInformationReportArg,
&ett_camel_CallInformationRequestArg,
&ett_camel_CancelArg,
&ett_camel_CollectInformationArg,
&ett_camel_ConnectArg,
&ett_camel_ConnectToResourceArg,
&ett_camel_T_resourceAddress,
&ett_camel_ContinueWithArgumentArg,
&ett_camel_ContinueWithArgumentArgExtension,
&ett_camel_DisconnectForwardConnectionWithArgumentArg,
&ett_camel_DisconnectLegArg,
&ett_camel_EntityReleasedArg,
&ett_camel_EstablishTemporaryConnectionArg,
&ett_camel_EventReportBCSMArg,
&ett_camel_InitialDPArg,
&ett_camel_InitialDPArgExtension,
&ett_camel_InitiateCallAttemptArg,
&ett_camel_InitiateCallAttemptRes,
&ett_camel_MoveLegArg,
&ett_camel_PlayToneArg,
&ett_camel_ReleaseCallArg,
&ett_camel_AllCallSegmentsWithExtension,
&ett_camel_RequestReportBCSMEventArg,
&ett_camel_SEQUENCE_SIZE_1_bound__numOfBCSMEvents_OF_BCSMEvent,
&ett_camel_ResetTimerArg,
&ett_camel_SendChargingInformationArg,
&ett_camel_SplitLegArg,
&ett_camel_ApplyChargingGPRSArg,
&ett_camel_ApplyChargingReportGPRSArg,
&ett_camel_CancelGPRSArg,
&ett_camel_ConnectGPRSArg,
&ett_camel_ContinueGPRSArg,
&ett_camel_EntityReleasedGPRSArg,
&ett_camel_EventReportGPRSArg,
&ett_camel_InitialDPGPRSArg,
&ett_camel_ReleaseGPRSArg,
&ett_camel_RequestReportGPRSEventArg,
&ett_camel_SEQUENCE_SIZE_1_bound__numOfGPRSEvents_OF_GPRSEvent,
&ett_camel_ResetTimerGPRSArg,
&ett_camel_SendChargingInformationGPRSArg,
&ett_camel_ConnectSMSArg,
&ett_camel_EventReportSMSArg,
&ett_camel_InitialDPSMSArg,
&ett_camel_RequestReportSMSEventArg,
&ett_camel_SEQUENCE_SIZE_1_bound__numOfSMSEvents_OF_SMSEvent,
&ett_camel_ResetTimerSMSArg,
&ett_camel_InitialDPArgExtensionV2,
&ett_camel_NACarrierInformation,
&ett_camel_CAMEL_AChBillingChargingCharacteristicsV2,
&ett_camel_T_timeDurationCharging_01,
&ett_camel_ReleaseIfDurationExceeded,
&ett_camel_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField,
&ett_camel_Code,
&ett_camel_ROS,
&ett_camel_Invoke,
&ett_camel_T_linkedId,
&ett_camel_ReturnResult,
&ett_camel_T_result,
&ett_camel_ReturnError,
&ett_camel_Reject,
&ett_camel_T_problem,
&ett_camel_InvokeId,
#line 1410 "../../asn1/camel/packet-camel-template.c"
};
static ei_register_info ei[] = {
{ &ei_camel_unknown_invokeData, { "camel.unknown.invokeData", PI_MALFORMED, PI_WARN, "Unknown invokeData", EXPFILL }},
{ &ei_camel_unknown_returnResultData, { "camel.unknown.returnResultData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
{ &ei_camel_unknown_returnErrorData, { "camel.unknown.returnErrorData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
};
expert_module_t* expert_camel;
proto_camel = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("camel", dissect_camel, proto_camel);
new_register_dissector("camel-v1", dissect_camel_v1, proto_camel);
new_register_dissector("camel-v2", dissect_camel_v2, proto_camel);
proto_register_field_array(proto_camel, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_camel = expert_register_protocol(proto_camel);
expert_register_field_array(expert_camel, ei, array_length(ei));
rose_ctx_init(&camel_rose_ctx);
camel_rose_ctx.arg_local_dissector_table = register_dissector_table("camel.ros.local.arg",
"CAMEL Operation Argument (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.res_local_dissector_table = register_dissector_table("camel.ros.local.res",
"CAMEL Operation Result (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.err_local_dissector_table = register_dissector_table("camel.ros.local.err",
"CAMEL Error (local opcode)",
FT_UINT32, BASE_HEX);
range_convert_str(&global_ssn_range, "146", MAX_SSN);
camel_module = prefs_register_protocol(proto_camel, proto_reg_handoff_camel);
prefs_register_enum_preference(camel_module, "date.format", "Date Format",
"The date format: (DD/MM) or (MM/DD)",
&date_format, date_options, FALSE);
prefs_register_range_preference(camel_module, "tcap.ssn",
"TCAP SSNs",
"TCAP Subsystem numbers used for Camel",
&global_ssn_range, MAX_SSN);
prefs_register_bool_preference(camel_module, "srt",
"Service Response Time Analyse",
"Activate the analyse for Response Time",
&gcamel_HandleSRT);
prefs_register_bool_preference(camel_module, "persistentsrt",
"Persistent stats for SRT",
"Statistics for Response Time",
&gcamel_PersistentSRT);
register_init_routine(&camelsrt_init_routine);
camel_tap=register_tap(PSNAME);
}
