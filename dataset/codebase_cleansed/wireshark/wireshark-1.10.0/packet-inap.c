int
dissect_inap_CriticalityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_local(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 165 "../../asn1/inap/inap.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
if (inap_opcode_type == INAP_OPCODE_RETURN_ERROR){
errorCode = opcode;
col_append_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(errorCode, inap_err_code_string_vals, "Unknown INAP error (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
}else{
col_append_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(opcode, inap_opr_code_strings, "Unknown INAP (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
}
return offset;
}
static int
dissect_inap_T_global(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &obj_id);
return offset;
}
static int
dissect_inap_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Code_choice, hf_index, ett_inap_Code,
NULL);
return offset;
}
static int
dissect_inap_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 223 "../../asn1/inap/inap.cnf"
proto_tree_add_text(tree, tvb, offset, -1, "Extension Data");
if (obj_id){
offset=call_ber_oid_callback(obj_id, tvb, offset, actx->pinfo, tree);
}else{
call_dissector(data_handle, tvb, actx->pinfo, tree);
offset = tvb_length_remaining(tvb,offset);
}
return offset;
}
static int
dissect_inap_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 218 "../../asn1/inap/inap.cnf"
obj_id = NULL;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtensionField_sequence, hf_index, ett_inap_ExtensionField);
return offset;
}
static int
dissect_inap_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Extensions_sequence_of, hf_index, ett_inap_Extensions);
return offset;
}
int
dissect_inap_Integer4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_InvokeID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_UnavailableNetworkResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AALParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_LocationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AccessCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_AChBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ActionIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ActionOnProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ActionPerformed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AdditionalATMCellRate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Digits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AdditionalCallingPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_AESACalledParty(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AESACallingParty(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AlertingPattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_IA5String_SIZE_1_512(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AlternativeIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AlternativeIdentity_choice, hf_index, ett_inap_AlternativeIdentity,
NULL);
return offset;
}
static int
dissect_inap_AlternativeIdentities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AlternativeIdentities_sequence_of, hf_index, ett_inap_AlternativeIdentities);
return offset;
}
static int
dissect_inap_AlternativeATMTrafficDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ApplicationTimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_AssistingSSPIPRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_ATMCellRate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_BackwardGVNS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_BackwardServiceInteractionInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BackwardServiceInteractionInd_sequence, hf_index, ett_inap_BackwardServiceInteractionInd);
return offset;
}
int
dissect_inap_ServiceKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Integer4(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_EventTypeBCSM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GapOnService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GapOnService_sequence, hf_index, ett_inap_GapOnService);
return offset;
}
static int
dissect_inap_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_inap_T_calledAddressAndService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_calledAddressAndService_sequence, hf_index, ett_inap_T_calledAddressAndService);
return offset;
}
static int
dissect_inap_T_callingAddressAndService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callingAddressAndService_sequence, hf_index, ett_inap_T_callingAddressAndService);
return offset;
}
static int
dissect_inap_BasicGapCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BasicGapCriteria_choice, hf_index, ett_inap_BasicGapCriteria,
NULL);
return offset;
}
static int
dissect_inap_MonitorMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_LegType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_inap_LegID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LegID_choice, hf_index, ett_inap_LegID,
NULL);
return offset;
}
static int
dissect_inap_NumberOfDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_MidCallInfoType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MidCallInfoType_sequence, hf_index, ett_inap_MidCallInfoType);
return offset;
}
static int
dissect_inap_T_midCallReportType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_MidCallControlInfo_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MidCallControlInfo_item_sequence, hf_index, ett_inap_MidCallControlInfo_item);
return offset;
}
static int
dissect_inap_MidCallControlInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
MidCallControlInfo_sequence_of, hf_index, ett_inap_MidCallControlInfo);
return offset;
}
static int
dissect_inap_T_numberOfDigitsTwo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_numberOfDigitsTwo_sequence, hf_index, ett_inap_T_numberOfDigitsTwo);
return offset;
}
static int
dissect_inap_DpSpecificCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DpSpecificCriteria_choice, hf_index, ett_inap_DpSpecificCriteria,
NULL);
return offset;
}
static int
dissect_inap_BCSMEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BCSMEvent_sequence, hf_index, ett_inap_BCSMEvent);
return offset;
}
static int
dissect_inap_T_bearerCap(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 255 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_q931_bearer_capability_ie(parameter_tvb, 0, tvb_length_remaining(parameter_tvb,0), tree);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_minBroadbandBearerCapabilityLength_maxBroadbandBearerCapabilityLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_BearerCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BearerCapability_choice, hf_index, ett_inap_BearerCapability,
NULL);
return offset;
}
static int
dissect_inap_CDVTDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CumulativeTransitDelay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_EndToEndTransitDelay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_MinAcceptableATMTrafficDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_BISDNParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BISDNParameters_sequence, hf_index, ett_inap_BISDNParameters);
return offset;
}
int
dissect_inap_BothwayThroughConnectionInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CalledDirectoryNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CalledPartyBusinessGroupID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CalledPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 234 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_called_party_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_inap_CalledPartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallingGeodeticLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallingPartyBusinessGroupID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallingPartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 244 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_calling_party_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_inap_CallingPartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_inap_CallingPartysCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallProcessingOperation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CallSegmentID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Carrier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Cause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CCSS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_inap_CGEncountered(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ChargeNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_EventTypeCharging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ChargingEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChargingEvent_sequence, hf_index, ett_inap_ChargingEvent);
return offset;
}
static int
dissect_inap_CNInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_1_118(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_EMBEDDED_PDV(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_EmbeddedPDV_Type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_inap_Component(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Component_choice, hf_index, ett_inap_Component,
NULL);
return offset;
}
static int
dissect_inap_ComponentCorrelationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ComponentType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ScfID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CompoundCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompoundCriteria_sequence, hf_index, ett_inap_CompoundCriteria);
return offset;
}
static int
dissect_inap_ConnectedNumberTreatmentInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ConnectionIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ControlType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CorrelationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Digits(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_CounterID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CounterAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CounterAndValue_sequence, hf_index, ett_inap_CounterAndValue);
return offset;
}
static int
dissect_inap_CountersValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CountersValue_sequence_of, hf_index, ett_inap_CountersValue);
return offset;
}
static int
dissect_inap_CreateOrRemoveIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CSAID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CUG_Interlock(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CUG_Index(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CutAndPaste(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_DateAndTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_action(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_IA5String_SIZE_b3__minMessageContentLength_b3__maxMessageContentLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_b3__minAttributesLength_b3__maxAttributesLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_text(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_text_sequence, hf_index, ett_inap_T_text);
return offset;
}
static int
dissect_inap_SEQUENCE_SIZE_1_b3__numOfMessageIDs_OF_Integer4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_b3__numOfMessageIDs_OF_Integer4_sequence_of, hf_index, ett_inap_SEQUENCE_SIZE_1_b3__numOfMessageIDs_OF_Integer4);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_3(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_VariablePart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
VariablePart_choice, hf_index, ett_inap_VariablePart,
NULL);
return offset;
}
static int
dissect_inap_SEQUENCE_SIZE_1_b3__maxVariableParts_OF_VariablePart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_b3__maxVariableParts_OF_VariablePart_sequence_of, hf_index, ett_inap_SEQUENCE_SIZE_1_b3__maxVariableParts_OF_VariablePart);
return offset;
}
static int
dissect_inap_T_variableMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_variableMessage_sequence, hf_index, ett_inap_T_variableMessage);
return offset;
}
static int
dissect_inap_MessageID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MessageID_choice, hf_index, ett_inap_MessageID,
NULL);
return offset;
}
static int
dissect_inap_INTEGER_1_127(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_INTEGER_0_32767(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Language(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_InbandInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InbandInfo_sequence, hf_index, ett_inap_InbandInfo);
return offset;
}
static int
dissect_inap_Tone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Tone_sequence, hf_index, ett_inap_Tone);
return offset;
}
static int
dissect_inap_DisplayInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_SDSSinformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_InformationToSend(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InformationToSend_choice, hf_index, ett_inap_InformationToSend,
NULL);
return offset;
}
static int
dissect_inap_T_both(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_both_sequence, hf_index, ett_inap_T_both);
return offset;
}
static int
dissect_inap_GapTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GapTreatment_choice, hf_index, ett_inap_GapTreatment,
NULL);
return offset;
}
static int
dissect_inap_DefaultFaultHandling(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefaultFaultHandling_sequence, hf_index, ett_inap_DefaultFaultHandling);
return offset;
}
static int
dissect_inap_DestinationIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_DestinationRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DestinationRoutingAddress_sequence_of, hf_index, ett_inap_DestinationRoutingAddress);
return offset;
}
static int
dissect_inap_T_messageType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_dpAssignment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_inap_MiscCallInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MiscCallInfo_sequence, hf_index, ett_inap_MiscCallInfo);
return offset;
}
static int
dissect_inap_TriggerType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ServiceAddressInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceAddressInformation_sequence, hf_index, ett_inap_ServiceAddressInformation);
return offset;
}
static int
dissect_inap_IPSSPCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_IPAvailable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ISDNAccessRelatedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ServiceProfileIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_TerminalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ServingAreaID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_ServiceInteractionIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_inap_Entry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Entry_choice, hf_index, ett_inap_Entry,
NULL);
return offset;
}
static int
dissect_inap_INServiceCompatibilityIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
INServiceCompatibilityIndication_sequence_of, hf_index, ett_inap_INServiceCompatibilityIndication);
return offset;
}
static int
dissect_inap_ForwardServiceInteractionInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ForwardServiceInteractionInd_sequence, hf_index, ett_inap_ForwardServiceInteractionInd);
return offset;
}
static int
dissect_inap_SuspendTimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_inap_RedirectReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_redirectServiceTreatmentInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_redirectServiceTreatmentInd_sequence, hf_index, ett_inap_T_redirectServiceTreatmentInd);
return offset;
}
static int
dissect_inap_ServiceInteractionIndicatorsTwo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceInteractionIndicatorsTwo_sequence, hf_index, ett_inap_ServiceInteractionIndicatorsTwo);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_minUSIServiceIndicatorLength_maxUSIServiceIndicatorLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_USIServiceIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
USIServiceIndicator_choice, hf_index, ett_inap_USIServiceIndicator,
NULL);
return offset;
}
static int
dissect_inap_USIInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ForwardGVNS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_IPRelatedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPRelatedInformation_sequence, hf_index, ett_inap_IPRelatedInformation);
return offset;
}
static int
dissect_inap_DpSpecificCommonParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DpSpecificCommonParameters_sequence, hf_index, ett_inap_DpSpecificCommonParameters);
return offset;
}
int
dissect_inap_Duration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_collectedInfoSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_collectedInfoSpecificInfo_sequence, hf_index, ett_inap_T_collectedInfoSpecificInfo);
return offset;
}
static int
dissect_inap_T_analysedInfoSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_analysedInfoSpecificInfo_sequence, hf_index, ett_inap_T_analysedInfoSpecificInfo);
return offset;
}
static int
dissect_inap_T_routeSelectFailureSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_routeSelectFailureSpecificInfo_sequence, hf_index, ett_inap_T_routeSelectFailureSpecificInfo);
return offset;
}
static int
dissect_inap_T_oCalledPartyBusySpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oCalledPartyBusySpecificInfo_sequence, hf_index, ett_inap_T_oCalledPartyBusySpecificInfo);
return offset;
}
static int
dissect_inap_T_oNoAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oNoAnswerSpecificInfo_sequence, hf_index, ett_inap_T_oNoAnswerSpecificInfo);
return offset;
}
static int
dissect_inap_T_oAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oAnswerSpecificInfo_sequence, hf_index, ett_inap_T_oAnswerSpecificInfo);
return offset;
}
static int
dissect_inap_MidCallInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MidCallInfo_sequence, hf_index, ett_inap_MidCallInfo);
return offset;
}
static int
dissect_inap_T_oMidCallSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oMidCallSpecificInfo_sequence, hf_index, ett_inap_T_oMidCallSpecificInfo);
return offset;
}
static int
dissect_inap_T_oDisconnectSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oDisconnectSpecificInfo_sequence, hf_index, ett_inap_T_oDisconnectSpecificInfo);
return offset;
}
static int
dissect_inap_T_tBusySpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tBusySpecificInfo_sequence, hf_index, ett_inap_T_tBusySpecificInfo);
return offset;
}
static int
dissect_inap_T_tNoAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tNoAnswerSpecificInfo_sequence, hf_index, ett_inap_T_tNoAnswerSpecificInfo);
return offset;
}
static int
dissect_inap_T_tAnswerSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tAnswerSpecificInfo_sequence, hf_index, ett_inap_T_tAnswerSpecificInfo);
return offset;
}
static int
dissect_inap_T_tMidCallSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tMidCallSpecificInfo_sequence, hf_index, ett_inap_T_tMidCallSpecificInfo);
return offset;
}
static int
dissect_inap_T_tDisconnectSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tDisconnectSpecificInfo_sequence, hf_index, ett_inap_T_tDisconnectSpecificInfo);
return offset;
}
static int
dissect_inap_T_oTermSeizedSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oTermSeizedSpecificInfo_sequence, hf_index, ett_inap_T_oTermSeizedSpecificInfo);
return offset;
}
static int
dissect_inap_T_oSuspend(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oSuspend_sequence, hf_index, ett_inap_T_oSuspend);
return offset;
}
static int
dissect_inap_T_tSuspend(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tSuspend_sequence, hf_index, ett_inap_T_tSuspend);
return offset;
}
static int
dissect_inap_T_origAttemptAuthorized(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_origAttemptAuthorized_sequence, hf_index, ett_inap_T_origAttemptAuthorized);
return offset;
}
static int
dissect_inap_T_oReAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oReAnswer_sequence, hf_index, ett_inap_T_oReAnswer);
return offset;
}
static int
dissect_inap_T_tReAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tReAnswer_sequence, hf_index, ett_inap_T_tReAnswer);
return offset;
}
static int
dissect_inap_T_facilitySelectedAndAvailable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_facilitySelectedAndAvailable_sequence, hf_index, ett_inap_T_facilitySelectedAndAvailable);
return offset;
}
static int
dissect_inap_T_callAccepted(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callAccepted_sequence, hf_index, ett_inap_T_callAccepted);
return offset;
}
static int
dissect_inap_T_oAbandon(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oAbandon_sequence, hf_index, ett_inap_T_oAbandon);
return offset;
}
static int
dissect_inap_T_tAbandon(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tAbandon_sequence, hf_index, ett_inap_T_tAbandon);
return offset;
}
static int
dissect_inap_T_authorizeRouteFailure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_authorizeRouteFailure_sequence, hf_index, ett_inap_T_authorizeRouteFailure);
return offset;
}
static int
dissect_inap_T_terminationAttemptAuthorized(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_terminationAttemptAuthorized_sequence, hf_index, ett_inap_T_terminationAttemptAuthorized);
return offset;
}
static int
dissect_inap_T_originationAttemptDenied(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_originationAttemptDenied_sequence, hf_index, ett_inap_T_originationAttemptDenied);
return offset;
}
static int
dissect_inap_T_terminationAttemptDenied(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_terminationAttemptDenied_sequence, hf_index, ett_inap_T_terminationAttemptDenied);
return offset;
}
static int
dissect_inap_T_oModifyRequestSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oModifyRequestSpecificInfo_sequence, hf_index, ett_inap_T_oModifyRequestSpecificInfo);
return offset;
}
static int
dissect_inap_ModifyResultType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_oModifyResultSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oModifyResultSpecificInfo_sequence, hf_index, ett_inap_T_oModifyResultSpecificInfo);
return offset;
}
static int
dissect_inap_T_tModifyRequestSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tModifyRequestSpecificInfo_sequence, hf_index, ett_inap_T_tModifyRequestSpecificInfo);
return offset;
}
static int
dissect_inap_T_tModifyResultSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_tModifyResultSpecificInfo_sequence, hf_index, ett_inap_T_tModifyResultSpecificInfo);
return offset;
}
static int
dissect_inap_EventSpecificInformationBCSM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventSpecificInformationBCSM_choice, hf_index, ett_inap_EventSpecificInformationBCSM,
NULL);
return offset;
}
static int
dissect_inap_EventSpecificInformationCharging(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_FacilityGroup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FacilityGroup_choice, hf_index, ett_inap_FacilityGroup,
NULL);
return offset;
}
static int
dissect_inap_FacilityGroupMember(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_FCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_FeatureCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_FeatureRequestIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_SFBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_MaximumNumberOfCounters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_FilteredCallTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FilteredCallTreatment_sequence, hf_index, ett_inap_FilteredCallTreatment);
return offset;
}
static int
dissect_inap_INTEGER_M1_32000(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_FilteringCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FilteringCharacteristics_choice, hf_index, ett_inap_FilteringCharacteristics,
NULL);
return offset;
}
static int
dissect_inap_T_addressAndService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_addressAndService_sequence, hf_index, ett_inap_T_addressAndService);
return offset;
}
static int
dissect_inap_FilteringCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FilteringCriteria_choice, hf_index, ett_inap_FilteringCriteria,
NULL);
return offset;
}
static int
dissect_inap_FilteringTimeOut(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FilteringTimeOut_choice, hf_index, ett_inap_FilteringTimeOut,
NULL);
return offset;
}
static int
dissect_inap_ForwardCallIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ForwardingCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GapCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GapCriteria_choice, hf_index, ett_inap_GapCriteria,
NULL);
return offset;
}
int
dissect_inap_Interval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GapIndicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GapIndicators_sequence, hf_index, ett_inap_GapIndicators);
return offset;
}
static int
dissect_inap_GenericIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GenericName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GenericNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_GenericNumbers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
GenericNumbers_set_of, hf_index, ett_inap_GenericNumbers);
return offset;
}
static int
dissect_inap_GlobalCallReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_inap_HighLayerCompatibility(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 297 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_inap_HighLayerCompatibility);
dissect_q931_high_layer_compat_ie(parameter_tvb, 0, tvb_length_remaining(parameter_tvb,0), subtree);
return offset;
}
static int
dissect_inap_HoldCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Trigger(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Trigger_sequence, hf_index, ett_inap_Trigger);
return offset;
}
static int
dissect_inap_Triggers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Triggers_sequence_of, hf_index, ett_inap_Triggers);
return offset;
}
static int
dissect_inap_TDPIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TDPIdentifier_choice, hf_index, ett_inap_TDPIdentifier,
NULL);
return offset;
}
static int
dissect_inap_INprofile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
INprofile_sequence, hf_index, ett_inap_INprofile);
return offset;
}
static int
dissect_inap_INServiceCompatibilityResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Entry(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_IPRoutingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_CalledPartyNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_MonitoringCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MonitoringCriteria_choice, hf_index, ett_inap_MonitoringCriteria,
NULL);
return offset;
}
static int
dissect_inap_MonitoringTimeOut(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MonitoringTimeOut_choice, hf_index, ett_inap_MonitoringTimeOut,
NULL);
return offset;
}
static int
dissect_inap_NumberingPlan(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_OriginalCalledPartyID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 277 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_original_called_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_inap_ProfileIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ProfileIdentifier_choice, hf_index, ett_inap_ProfileIdentifier,
NULL);
return offset;
}
static int
dissect_inap_QoSParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RedirectingPartyID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 287 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_redirecting_number_parameter(parameter_tvb, tree, NULL);
return offset;
}
int
dissect_inap_RedirectionInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 266 "../../asn1/inap/inap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_isup_redirection_information_parameter(parameter_tvb, tree, NULL);
return offset;
}
static int
dissect_inap_RegistratorIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ReportCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RequestedInformationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_INTEGER_0_255(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RequestedInformationValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestedInformationValue_choice, hf_index, ett_inap_RequestedInformationValue,
NULL);
return offset;
}
static int
dissect_inap_RequestedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestedInformation_sequence, hf_index, ett_inap_RequestedInformation);
return offset;
}
static int
dissect_inap_RequestedInformationList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestedInformationList_sequence_of, hf_index, ett_inap_RequestedInformationList);
return offset;
}
static int
dissect_inap_RequestedInformationTypeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestedInformationTypeList_sequence_of, hf_index, ett_inap_RequestedInformationTypeList);
return offset;
}
static int
dissect_inap_USIMonitorMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RequestedUTSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestedUTSI_sequence, hf_index, ett_inap_RequestedUTSI);
return offset;
}
static int
dissect_inap_RequestedUTSIList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestedUTSIList_sequence_of, hf_index, ett_inap_RequestedUTSIList);
return offset;
}
static int
dissect_inap_ResourceID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ResourceID_choice, hf_index, ett_inap_ResourceID,
NULL);
return offset;
}
static int
dissect_inap_ResourceStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ResponseCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Route(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RouteCountersAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RouteCountersAndValue_sequence, hf_index, ett_inap_RouteCountersAndValue);
return offset;
}
static int
dissect_inap_RouteCountersValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RouteCountersValue_sequence_of, hf_index, ett_inap_RouteCountersValue);
return offset;
}
static int
dissect_inap_RouteList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RouteList_sequence_of, hf_index, ett_inap_RouteList);
return offset;
}
static int
dissect_inap_RouteingNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_SCIBillingChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_TimerID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_TimerValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Integer4(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_TravellingClassMark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_LocationNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_T_triggerId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_triggerPar(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 204 "../../asn1/inap/inap.cnf"
return offset;
}
static int
dissect_inap_TriggerData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TriggerData_sequence, hf_index, ett_inap_TriggerData);
return offset;
}
static int
dissect_inap_TriggerDataIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TriggerDataIdentifier_sequence, hf_index, ett_inap_TriggerDataIdentifier);
return offset;
}
static int
dissect_inap_TriggerDPType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_TriggerResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TriggerResult_sequence, hf_index, ett_inap_TriggerResult);
return offset;
}
static int
dissect_inap_TriggerResults(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TriggerResults_sequence_of, hf_index, ett_inap_TriggerResults);
return offset;
}
static int
dissect_inap_TriggerStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_VPNIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_inap_ActivateServiceFilteringArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActivateServiceFilteringArg_sequence, hf_index, ett_inap_ActivateServiceFilteringArg);
return offset;
}
static int
dissect_inap_AnalysedInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AnalysedInformationArg_sequence, hf_index, ett_inap_AnalysedInformationArg);
return offset;
}
static int
dissect_inap_AnalyseInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AnalyseInformationArg_sequence, hf_index, ett_inap_AnalyseInformationArg);
return offset;
}
static int
dissect_inap_ApplyChargingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ApplyChargingArg_sequence, hf_index, ett_inap_ApplyChargingArg);
return offset;
}
static int
dissect_inap_ApplyChargingReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_CallResult(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_AssistRequestInstructionsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AssistRequestInstructionsArg_sequence, hf_index, ett_inap_AssistRequestInstructionsArg);
return offset;
}
static int
dissect_inap_AuthorizeTerminationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuthorizeTerminationArg_sequence, hf_index, ett_inap_AuthorizeTerminationArg);
return offset;
}
static int
dissect_inap_CallFilteringArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallFilteringArg_sequence, hf_index, ett_inap_CallFilteringArg);
return offset;
}
static int
dissect_inap_CallGapArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallGapArg_sequence, hf_index, ett_inap_CallGapArg);
return offset;
}
static int
dissect_inap_CallInformationReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallInformationReportArg_sequence, hf_index, ett_inap_CallInformationReportArg);
return offset;
}
static int
dissect_inap_CallInformationRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CallInformationRequestArg_sequence, hf_index, ett_inap_CallInformationRequestArg);
return offset;
}
static int
dissect_inap_T_callSegmentToCancel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callSegmentToCancel_sequence, hf_index, ett_inap_T_callSegmentToCancel);
return offset;
}
static int
dissect_inap_CancelArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CancelArg_choice, hf_index, ett_inap_CancelArg,
NULL);
return offset;
}
static int
dissect_inap_CancelStatusReportRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CancelStatusReportRequestArg_sequence, hf_index, ett_inap_CancelStatusReportRequestArg);
return offset;
}
static int
dissect_inap_CollectedInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CollectedInformationArg_sequence, hf_index, ett_inap_CollectedInformationArg);
return offset;
}
static int
dissect_inap_CollectInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CollectInformationArg_sequence, hf_index, ett_inap_CollectInformationArg);
return offset;
}
static int
dissect_inap_ConnectArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectArg_sequence, hf_index, ett_inap_ConnectArg);
return offset;
}
static int
dissect_inap_T_ipAddressAndLegID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_ipAddressAndLegID_sequence, hf_index, ett_inap_T_ipAddressAndLegID);
return offset;
}
static int
dissect_inap_T_ipAddressAndCallSegment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_ipAddressAndCallSegment_sequence, hf_index, ett_inap_T_ipAddressAndCallSegment);
return offset;
}
static int
dissect_inap_T_resourceAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_resourceAddress_choice, hf_index, ett_inap_T_resourceAddress,
NULL);
return offset;
}
static int
dissect_inap_ConnectToResourceArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectToResourceArg_sequence, hf_index, ett_inap_ConnectToResourceArg);
return offset;
}
static int
dissect_inap_T_legorCSID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_legorCSID_choice, hf_index, ett_inap_T_legorCSID,
NULL);
return offset;
}
static int
dissect_inap_ContinueWithArgumentArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContinueWithArgumentArg_sequence, hf_index, ett_inap_ContinueWithArgumentArg);
return offset;
}
static int
dissect_inap_CreateCallSegmentAssociationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateCallSegmentAssociationArg_sequence, hf_index, ett_inap_CreateCallSegmentAssociationArg);
return offset;
}
static int
dissect_inap_CreateCallSegmentAssociationResultArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateCallSegmentAssociationResultArg_sequence, hf_index, ett_inap_CreateCallSegmentAssociationResultArg);
return offset;
}
static int
dissect_inap_CreateOrRemoveTriggerDataArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateOrRemoveTriggerDataArg_sequence, hf_index, ett_inap_CreateOrRemoveTriggerDataArg);
return offset;
}
static int
dissect_inap_CreateOrRemoveTriggerDataResultArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateOrRemoveTriggerDataResultArg_sequence, hf_index, ett_inap_CreateOrRemoveTriggerDataResultArg);
return offset;
}
static int
dissect_inap_T_partyToDisconnect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_partyToDisconnect_choice, hf_index, ett_inap_T_partyToDisconnect,
NULL);
return offset;
}
static int
dissect_inap_DisconnectForwardConnectionWithArgumentArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DisconnectForwardConnectionWithArgumentArg_sequence, hf_index, ett_inap_DisconnectForwardConnectionWithArgumentArg);
return offset;
}
static int
dissect_inap_DisconnectLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DisconnectLegArg_sequence, hf_index, ett_inap_DisconnectLegArg);
return offset;
}
static int
dissect_inap_T_cSFailure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_cSFailure_sequence, hf_index, ett_inap_T_cSFailure);
return offset;
}
static int
dissect_inap_T_bCSMFailure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_bCSMFailure_sequence, hf_index, ett_inap_T_bCSMFailure);
return offset;
}
static int
dissect_inap_EntityReleasedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EntityReleasedArg_choice, hf_index, ett_inap_EntityReleasedArg,
NULL);
return offset;
}
static int
dissect_inap_T_partyToConnect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_partyToConnect_choice, hf_index, ett_inap_T_partyToConnect,
NULL);
return offset;
}
static int
dissect_inap_EstablishTemporaryConnectionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EstablishTemporaryConnectionArg_sequence, hf_index, ett_inap_EstablishTemporaryConnectionArg);
return offset;
}
static int
dissect_inap_EventNotificationChargingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventNotificationChargingArg_sequence, hf_index, ett_inap_EventNotificationChargingArg);
return offset;
}
static int
dissect_inap_EventReportBCSMArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventReportBCSMArg_sequence, hf_index, ett_inap_EventReportBCSMArg);
return offset;
}
static int
dissect_inap_EventReportFacilityArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventReportFacilityArg_sequence, hf_index, ett_inap_EventReportFacilityArg);
return offset;
}
static int
dissect_inap_FacilitySelectedAndAvailableArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FacilitySelectedAndAvailableArg_sequence, hf_index, ett_inap_FacilitySelectedAndAvailableArg);
return offset;
}
static int
dissect_inap_FurnishChargingInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_FCIBillingChargingCharacteristics(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_HoldCallInNetworkArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
HoldCallInNetworkArg_choice, hf_index, ett_inap_HoldCallInNetworkArg,
NULL);
return offset;
}
static int
dissect_inap_InitialDPArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitialDPArg_sequence, hf_index, ett_inap_InitialDPArg);
return offset;
}
static int
dissect_inap_InitiateCallAttemptArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitiateCallAttemptArg_sequence, hf_index, ett_inap_InitiateCallAttemptArg);
return offset;
}
static int
dissect_inap_T_triggerDataIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_triggerDataIdentifier_choice, hf_index, ett_inap_T_triggerDataIdentifier,
NULL);
return offset;
}
static int
dissect_inap_ManageTriggerDataArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ManageTriggerDataArg_sequence, hf_index, ett_inap_ManageTriggerDataArg);
return offset;
}
static int
dissect_inap_T_oneTriggerResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_oneTriggerResult_sequence, hf_index, ett_inap_T_oneTriggerResult);
return offset;
}
static int
dissect_inap_T_severalTriggerResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_severalTriggerResult_sequence, hf_index, ett_inap_T_severalTriggerResult);
return offset;
}
static int
dissect_inap_ManageTriggerDataResultArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ManageTriggerDataResultArg_choice, hf_index, ett_inap_ManageTriggerDataResultArg,
NULL);
return offset;
}
static int
dissect_inap_MergeCallSegmentsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MergeCallSegmentsArg_sequence, hf_index, ett_inap_MergeCallSegmentsArg);
return offset;
}
static int
dissect_inap_MonitorRouteReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MonitorRouteReportArg_sequence, hf_index, ett_inap_MonitorRouteReportArg);
return offset;
}
static int
dissect_inap_MonitorRouteRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MonitorRouteRequestArg_sequence, hf_index, ett_inap_MonitorRouteRequestArg);
return offset;
}
static int
dissect_inap_T_callSegments_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callSegments_item_sequence, hf_index, ett_inap_T_callSegments_item);
return offset;
}
static int
dissect_inap_T_callSegments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_callSegments_sequence_of, hf_index, ett_inap_T_callSegments);
return offset;
}
static int
dissect_inap_T_legs_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_legs_item_sequence, hf_index, ett_inap_T_legs_item);
return offset;
}
static int
dissect_inap_T_legs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_legs_sequence_of, hf_index, ett_inap_T_legs);
return offset;
}
static int
dissect_inap_MoveCallSegmentsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MoveCallSegmentsArg_sequence, hf_index, ett_inap_MoveCallSegmentsArg);
return offset;
}
static int
dissect_inap_MoveLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MoveLegArg_sequence, hf_index, ett_inap_MoveLegArg);
return offset;
}
static int
dissect_inap_OAbandonArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OAbandonArg_sequence, hf_index, ett_inap_OAbandonArg);
return offset;
}
static int
dissect_inap_OAnswerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OAnswerArg_sequence, hf_index, ett_inap_OAnswerArg);
return offset;
}
static int
dissect_inap_OCalledPartyBusyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OCalledPartyBusyArg_sequence, hf_index, ett_inap_OCalledPartyBusyArg);
return offset;
}
static int
dissect_inap_ODisconnectArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ODisconnectArg_sequence, hf_index, ett_inap_ODisconnectArg);
return offset;
}
static int
dissect_inap_MidCallArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MidCallArg_sequence, hf_index, ett_inap_MidCallArg);
return offset;
}
static int
dissect_inap_ONoAnswerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ONoAnswerArg_sequence, hf_index, ett_inap_ONoAnswerArg);
return offset;
}
static int
dissect_inap_OriginationAttemptArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OriginationAttemptArg_sequence, hf_index, ett_inap_OriginationAttemptArg);
return offset;
}
static int
dissect_inap_OriginationAttemptAuthorizedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OriginationAttemptAuthorizedArg_sequence, hf_index, ett_inap_OriginationAttemptAuthorizedArg);
return offset;
}
static int
dissect_inap_OSuspendedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OSuspendedArg_sequence, hf_index, ett_inap_OSuspendedArg);
return offset;
}
static int
dissect_inap_ReconnectArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReconnectArg_sequence, hf_index, ett_inap_ReconnectArg);
return offset;
}
static int
dissect_inap_INTEGER_1_numOfCSs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_callSegmentToRelease(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_callSegmentToRelease_sequence, hf_index, ett_inap_T_callSegmentToRelease);
return offset;
}
static int
dissect_inap_T_allCallSegments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_allCallSegments_sequence, hf_index, ett_inap_T_allCallSegments);
return offset;
}
static int
dissect_inap_ReleaseCallArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReleaseCallArg_choice, hf_index, ett_inap_ReleaseCallArg,
NULL);
return offset;
}
static int
dissect_inap_ReportUTSIArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportUTSIArg_sequence, hf_index, ett_inap_ReportUTSIArg);
return offset;
}
static int
dissect_inap_RequestCurrentStatusReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_ResourceID(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_RequestCurrentStatusReportResultArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestCurrentStatusReportResultArg_sequence, hf_index, ett_inap_RequestCurrentStatusReportResultArg);
return offset;
}
static int
dissect_inap_RequestEveryStatusChangeReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestEveryStatusChangeReportArg_sequence, hf_index, ett_inap_RequestEveryStatusChangeReportArg);
return offset;
}
static int
dissect_inap_RequestFirstStatusMatchReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestFirstStatusMatchReportArg_sequence, hf_index, ett_inap_RequestFirstStatusMatchReportArg);
return offset;
}
static int
dissect_inap_RequestNotificationChargingEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RequestNotificationChargingEventArg_sequence_of, hf_index, ett_inap_RequestNotificationChargingEventArg);
return offset;
}
static int
dissect_inap_SEQUENCE_SIZE_1_numOfBCSMEvents_OF_BCSMEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_numOfBCSMEvents_OF_BCSMEvent_sequence_of, hf_index, ett_inap_SEQUENCE_SIZE_1_numOfBCSMEvents_OF_BCSMEvent);
return offset;
}
static int
dissect_inap_RequestReportBCSMEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportBCSMEventArg_sequence, hf_index, ett_inap_RequestReportBCSMEventArg);
return offset;
}
static int
dissect_inap_SEQUENCE_SIZE_1_3_OF_ComponentType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_3_OF_ComponentType_sequence_of, hf_index, ett_inap_SEQUENCE_SIZE_1_3_OF_ComponentType);
return offset;
}
static int
dissect_inap_RequestReportFacilityEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportFacilityEventArg_sequence, hf_index, ett_inap_RequestReportFacilityEventArg);
return offset;
}
static int
dissect_inap_RequestReportUTSIArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestReportUTSIArg_sequence, hf_index, ett_inap_RequestReportUTSIArg);
return offset;
}
static int
dissect_inap_ResetTimerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ResetTimerArg_sequence, hf_index, ett_inap_ResetTimerArg);
return offset;
}
static int
dissect_inap_RouteSelectFailureArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RouteSelectFailureArg_sequence, hf_index, ett_inap_RouteSelectFailureArg);
return offset;
}
static int
dissect_inap_SelectFacilityArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SelectFacilityArg_sequence, hf_index, ett_inap_SelectFacilityArg);
return offset;
}
static int
dissect_inap_SelectRouteArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SelectRouteArg_sequence, hf_index, ett_inap_SelectRouteArg);
return offset;
}
static int
dissect_inap_SendChargingInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SendChargingInformationArg_sequence, hf_index, ett_inap_SendChargingInformationArg);
return offset;
}
static int
dissect_inap_SendFacilityInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SendFacilityInformationArg_sequence, hf_index, ett_inap_SendFacilityInformationArg);
return offset;
}
static int
dissect_inap_SendSTUIArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SendSTUIArg_sequence, hf_index, ett_inap_SendSTUIArg);
return offset;
}
static int
dissect_inap_ServiceFilteringResponseArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceFilteringResponseArg_sequence, hf_index, ett_inap_ServiceFilteringResponseArg);
return offset;
}
static int
dissect_inap_SEQUENCE_SIZE_1_numOfINProfile_OF_INprofile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_numOfINProfile_OF_INprofile_sequence_of, hf_index, ett_inap_SEQUENCE_SIZE_1_numOfINProfile_OF_INprofile);
return offset;
}
static int
dissect_inap_SetServiceProfileArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SetServiceProfileArg_sequence, hf_index, ett_inap_SetServiceProfileArg);
return offset;
}
static int
dissect_inap_INTEGER_2_numOfCSs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_SplitLegArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SplitLegArg_sequence, hf_index, ett_inap_SplitLegArg);
return offset;
}
static int
dissect_inap_StatusReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StatusReportArg_sequence, hf_index, ett_inap_StatusReportArg);
return offset;
}
static int
dissect_inap_TAnswerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TAnswerArg_sequence, hf_index, ett_inap_TAnswerArg);
return offset;
}
static int
dissect_inap_TBusyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TBusyArg_sequence, hf_index, ett_inap_TBusyArg);
return offset;
}
static int
dissect_inap_TDisconnectArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TDisconnectArg_sequence, hf_index, ett_inap_TDisconnectArg);
return offset;
}
static int
dissect_inap_TermAttemptAuthorizedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TermAttemptAuthorizedArg_sequence, hf_index, ett_inap_TermAttemptAuthorizedArg);
return offset;
}
static int
dissect_inap_TerminationAttemptArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminationAttemptArg_sequence, hf_index, ett_inap_TerminationAttemptArg);
return offset;
}
static int
dissect_inap_TNoAnswerArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TNoAnswerArg_sequence, hf_index, ett_inap_TNoAnswerArg);
return offset;
}
static int
dissect_inap_TSuspendedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TSuspendedArg_sequence, hf_index, ett_inap_TSuspendedArg);
return offset;
}
static int
dissect_inap_OCTET_STRING_SIZE_1_2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ErrorTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_CollectedDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CollectedDigits_sequence, hf_index, ett_inap_CollectedDigits);
return offset;
}
static int
dissect_inap_CollectedInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CollectedInfo_choice, hf_index, ett_inap_CollectedInfo,
NULL);
return offset;
}
static int
dissect_inap_ElementaryMessageID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Integer4(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_GapOnResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Code(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_INTEGER_1_3600(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_INTEGER_0_b3__maxRecordingTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_controlDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_controlDigits_sequence, hf_index, ett_inap_T_controlDigits);
return offset;
}
static int
dissect_inap_InformationToRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InformationToRecord_sequence, hf_index, ett_inap_InformationToRecord);
return offset;
}
static int
dissect_inap_MailBoxID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_Media(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ReceivedStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_RecordedMessageID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_Integer4(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_T_iPAddressAndresource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_iPAddressAndresource_sequence, hf_index, ett_inap_T_iPAddressAndresource);
return offset;
}
static int
dissect_inap_SRFGapCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SRFGapCriteria_choice, hf_index, ett_inap_SRFGapCriteria,
NULL);
return offset;
}
static int
dissect_inap_T_connectedParty(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_connectedParty_choice, hf_index, ett_inap_T_connectedParty,
NULL);
return offset;
}
static int
dissect_inap_PlayAnnouncementArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PlayAnnouncementArg_sequence, hf_index, ett_inap_PlayAnnouncementArg);
return offset;
}
static int
dissect_inap_PromptAndCollectUserInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PromptAndCollectUserInformationArg_sequence, hf_index, ett_inap_PromptAndCollectUserInformationArg);
return offset;
}
static int
dissect_inap_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ReceivedInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReceivedInformationArg_choice, hf_index, ett_inap_ReceivedInformationArg,
NULL);
return offset;
}
static int
dissect_inap_PromptAndReceiveMessageArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PromptAndReceiveMessageArg_sequence, hf_index, ett_inap_PromptAndReceiveMessageArg);
return offset;
}
static int
dissect_inap_INTEGER_1_b3__maxRecordedMessageUnits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_MessageReceivedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MessageReceivedArg_sequence, hf_index, ett_inap_MessageReceivedArg);
return offset;
}
static int
dissect_inap_T_uIScriptSpecificInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 210 "../../asn1/inap/inap.cnf"
return offset;
}
static int
dissect_inap_ScriptCloseArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScriptCloseArg_sequence, hf_index, ett_inap_ScriptCloseArg);
return offset;
}
static int
dissect_inap_T_uIScriptResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 207 "../../asn1/inap/inap.cnf"
return offset;
}
static int
dissect_inap_ScriptEventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScriptEventArg_sequence, hf_index, ett_inap_ScriptEventArg);
return offset;
}
static int
dissect_inap_T_uIScriptSpecificInfo_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 213 "../../asn1/inap/inap.cnf"
return offset;
}
static int
dissect_inap_ScriptInformationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScriptInformationArg_sequence, hf_index, ett_inap_ScriptInformationArg);
return offset;
}
static int
dissect_inap_T_uIScriptSpecificInfo_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 215 "../../asn1/inap/inap.cnf"
return offset;
}
static int
dissect_inap_ScriptRunArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScriptRunArg_sequence, hf_index, ett_inap_ScriptRunArg);
return offset;
}
static int
dissect_inap_SpecializedResourceReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_inap_SRFCallGapArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SRFCallGapArg_sequence, hf_index, ett_inap_SRFCallGapArg);
return offset;
}
static int
dissect_inap_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_PAR_cancelFailed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PAR_cancelFailed_sequence, hf_index, ett_inap_PAR_cancelFailed);
return offset;
}
static int
dissect_inap_PAR_requestedInfoError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ScfTaskRefusedParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScfTaskRefusedParameter_sequence, hf_index, ett_inap_ScfTaskRefusedParameter);
return offset;
}
static int
dissect_inap_ReferralParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReferralParameter_sequence, hf_index, ett_inap_ReferralParameter);
return offset;
}
static int
dissect_inap_PAR_taskRefused(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_InvokeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InvokeId_choice, hf_index, ett_inap_InvokeId,
NULL);
return offset;
}
static int
dissect_inap_InvokeId_present(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_linkedIdPresent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_inap_InvokeId_present(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_inap_T_linkedId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_linkedId_choice, hf_index, ett_inap_T_linkedId,
NULL);
return offset;
}
static int
dissect_inap_T_argument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 192 "../../asn1/inap/inap.cnf"
offset = dissect_invokeData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_inap_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 180 "../../asn1/inap/inap.cnf"
inap_opcode_type=INAP_OPCODE_INVOKE;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Invoke_sequence, hf_index, ett_inap_Invoke);
return offset;
}
static int
dissect_inap_ResultArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 195 "../../asn1/inap/inap.cnf"
offset = dissect_returnResultData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_inap_T_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_result_sequence, hf_index, ett_inap_T_result);
return offset;
}
static int
dissect_inap_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 183 "../../asn1/inap/inap.cnf"
inap_opcode_type=INAP_OPCODE_RETURN_RESULT;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnResult_sequence, hf_index, ett_inap_ReturnResult);
return offset;
}
static int
dissect_inap_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 198 "../../asn1/inap/inap.cnf"
offset = dissect_returnErrorData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_inap_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 186 "../../asn1/inap/inap.cnf"
inap_opcode_type=INAP_OPCODE_RETURN_ERROR;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnError_sequence, hf_index, ett_inap_ReturnError);
return offset;
}
static int
dissect_inap_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_inap_T_problem_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_problem_01_choice, hf_index, ett_inap_T_problem_01,
NULL);
return offset;
}
static int
dissect_inap_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 189 "../../asn1/inap/inap.cnf"
inap_opcode_type=INAP_OPCODE_REJECT;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reject_sequence, hf_index, ett_inap_Reject);
return offset;
}
static int
dissect_inap_ROS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ROS_choice, hf_index, ett_inap_ROS,
NULL);
return offset;
}
static int dissect_ActivateServiceFilteringArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ActivateServiceFilteringArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ActivateServiceFilteringArg_PDU);
return offset;
}
static int dissect_AnalysedInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_AnalysedInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_AnalysedInformationArg_PDU);
return offset;
}
static int dissect_AnalyseInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_AnalyseInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_AnalyseInformationArg_PDU);
return offset;
}
static int dissect_ApplyChargingArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ApplyChargingArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ApplyChargingArg_PDU);
return offset;
}
static int dissect_ApplyChargingReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ApplyChargingReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ApplyChargingReportArg_PDU);
return offset;
}
static int dissect_AssistRequestInstructionsArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_AssistRequestInstructionsArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_AssistRequestInstructionsArg_PDU);
return offset;
}
static int dissect_AuthorizeTerminationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_AuthorizeTerminationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_AuthorizeTerminationArg_PDU);
return offset;
}
static int dissect_CallFilteringArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CallFilteringArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CallFilteringArg_PDU);
return offset;
}
static int dissect_CallGapArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CallGapArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CallGapArg_PDU);
return offset;
}
static int dissect_CallInformationReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CallInformationReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CallInformationReportArg_PDU);
return offset;
}
static int dissect_CallInformationRequestArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CallInformationRequestArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CallInformationRequestArg_PDU);
return offset;
}
static int dissect_CancelArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CancelArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CancelArg_PDU);
return offset;
}
static int dissect_CancelStatusReportRequestArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CancelStatusReportRequestArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CancelStatusReportRequestArg_PDU);
return offset;
}
static int dissect_CollectedInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CollectedInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CollectedInformationArg_PDU);
return offset;
}
static int dissect_CollectInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CollectInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CollectInformationArg_PDU);
return offset;
}
static int dissect_ConnectArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ConnectArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ConnectArg_PDU);
return offset;
}
static int dissect_ConnectToResourceArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ConnectToResourceArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ConnectToResourceArg_PDU);
return offset;
}
static int dissect_ContinueWithArgumentArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ContinueWithArgumentArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ContinueWithArgumentArg_PDU);
return offset;
}
static int dissect_CreateCallSegmentAssociationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CreateCallSegmentAssociationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CreateCallSegmentAssociationArg_PDU);
return offset;
}
static int dissect_CreateCallSegmentAssociationResultArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CreateCallSegmentAssociationResultArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CreateCallSegmentAssociationResultArg_PDU);
return offset;
}
static int dissect_CreateOrRemoveTriggerDataArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CreateOrRemoveTriggerDataArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CreateOrRemoveTriggerDataArg_PDU);
return offset;
}
static int dissect_CreateOrRemoveTriggerDataResultArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_CreateOrRemoveTriggerDataResultArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_CreateOrRemoveTriggerDataResultArg_PDU);
return offset;
}
static int dissect_DisconnectForwardConnectionWithArgumentArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_DisconnectForwardConnectionWithArgumentArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_DisconnectForwardConnectionWithArgumentArg_PDU);
return offset;
}
static int dissect_DisconnectLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_DisconnectLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_DisconnectLegArg_PDU);
return offset;
}
static int dissect_EntityReleasedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_EntityReleasedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_EntityReleasedArg_PDU);
return offset;
}
static int dissect_EstablishTemporaryConnectionArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_EstablishTemporaryConnectionArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_EstablishTemporaryConnectionArg_PDU);
return offset;
}
static int dissect_EventNotificationChargingArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_EventNotificationChargingArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_EventNotificationChargingArg_PDU);
return offset;
}
static int dissect_EventReportBCSMArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_EventReportBCSMArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_EventReportBCSMArg_PDU);
return offset;
}
static int dissect_EventReportFacilityArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_EventReportFacilityArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_EventReportFacilityArg_PDU);
return offset;
}
static int dissect_FacilitySelectedAndAvailableArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_FacilitySelectedAndAvailableArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_FacilitySelectedAndAvailableArg_PDU);
return offset;
}
static int dissect_FurnishChargingInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_FurnishChargingInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_FurnishChargingInformationArg_PDU);
return offset;
}
static int dissect_HoldCallInNetworkArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_HoldCallInNetworkArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_HoldCallInNetworkArg_PDU);
return offset;
}
static int dissect_InitialDPArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_InitialDPArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_InitialDPArg_PDU);
return offset;
}
static int dissect_InitiateCallAttemptArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_InitiateCallAttemptArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_InitiateCallAttemptArg_PDU);
return offset;
}
static int dissect_ManageTriggerDataArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ManageTriggerDataArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ManageTriggerDataArg_PDU);
return offset;
}
static int dissect_ManageTriggerDataResultArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ManageTriggerDataResultArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ManageTriggerDataResultArg_PDU);
return offset;
}
static int dissect_MergeCallSegmentsArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MergeCallSegmentsArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MergeCallSegmentsArg_PDU);
return offset;
}
static int dissect_MonitorRouteReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MonitorRouteReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MonitorRouteReportArg_PDU);
return offset;
}
static int dissect_MonitorRouteRequestArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MonitorRouteRequestArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MonitorRouteRequestArg_PDU);
return offset;
}
static int dissect_MoveCallSegmentsArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MoveCallSegmentsArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MoveCallSegmentsArg_PDU);
return offset;
}
static int dissect_MoveLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MoveLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MoveLegArg_PDU);
return offset;
}
static int dissect_OAbandonArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OAbandonArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OAbandonArg_PDU);
return offset;
}
static int dissect_OAnswerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OAnswerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OAnswerArg_PDU);
return offset;
}
static int dissect_OCalledPartyBusyArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OCalledPartyBusyArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OCalledPartyBusyArg_PDU);
return offset;
}
static int dissect_ODisconnectArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ODisconnectArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ODisconnectArg_PDU);
return offset;
}
static int dissect_MidCallArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MidCallArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MidCallArg_PDU);
return offset;
}
static int dissect_ONoAnswerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ONoAnswerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ONoAnswerArg_PDU);
return offset;
}
static int dissect_OriginationAttemptArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OriginationAttemptArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OriginationAttemptArg_PDU);
return offset;
}
static int dissect_OriginationAttemptAuthorizedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OriginationAttemptAuthorizedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OriginationAttemptAuthorizedArg_PDU);
return offset;
}
static int dissect_OSuspendedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_OSuspendedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_OSuspendedArg_PDU);
return offset;
}
static int dissect_ReconnectArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ReconnectArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ReconnectArg_PDU);
return offset;
}
static int dissect_ReleaseCallArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ReleaseCallArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ReleaseCallArg_PDU);
return offset;
}
static int dissect_ReportUTSIArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ReportUTSIArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ReportUTSIArg_PDU);
return offset;
}
static int dissect_RequestCurrentStatusReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestCurrentStatusReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestCurrentStatusReportArg_PDU);
return offset;
}
static int dissect_RequestCurrentStatusReportResultArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestCurrentStatusReportResultArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestCurrentStatusReportResultArg_PDU);
return offset;
}
static int dissect_RequestEveryStatusChangeReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestEveryStatusChangeReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestEveryStatusChangeReportArg_PDU);
return offset;
}
static int dissect_RequestFirstStatusMatchReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestFirstStatusMatchReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestFirstStatusMatchReportArg_PDU);
return offset;
}
static int dissect_RequestNotificationChargingEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestNotificationChargingEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestNotificationChargingEventArg_PDU);
return offset;
}
static int dissect_RequestReportBCSMEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestReportBCSMEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestReportBCSMEventArg_PDU);
return offset;
}
static int dissect_RequestReportFacilityEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestReportFacilityEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestReportFacilityEventArg_PDU);
return offset;
}
static int dissect_RequestReportUTSIArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RequestReportUTSIArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RequestReportUTSIArg_PDU);
return offset;
}
static int dissect_ResetTimerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ResetTimerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ResetTimerArg_PDU);
return offset;
}
static int dissect_RouteSelectFailureArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_RouteSelectFailureArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_RouteSelectFailureArg_PDU);
return offset;
}
static int dissect_SelectFacilityArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SelectFacilityArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SelectFacilityArg_PDU);
return offset;
}
static int dissect_SelectRouteArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SelectRouteArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SelectRouteArg_PDU);
return offset;
}
static int dissect_SendChargingInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SendChargingInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SendChargingInformationArg_PDU);
return offset;
}
static int dissect_SendFacilityInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SendFacilityInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SendFacilityInformationArg_PDU);
return offset;
}
static int dissect_SendSTUIArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SendSTUIArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SendSTUIArg_PDU);
return offset;
}
static int dissect_ServiceFilteringResponseArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ServiceFilteringResponseArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ServiceFilteringResponseArg_PDU);
return offset;
}
static int dissect_SetServiceProfileArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SetServiceProfileArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SetServiceProfileArg_PDU);
return offset;
}
static int dissect_SplitLegArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SplitLegArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SplitLegArg_PDU);
return offset;
}
static int dissect_StatusReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_StatusReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_StatusReportArg_PDU);
return offset;
}
static int dissect_TAnswerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TAnswerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TAnswerArg_PDU);
return offset;
}
static int dissect_TBusyArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TBusyArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TBusyArg_PDU);
return offset;
}
static int dissect_TDisconnectArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TDisconnectArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TDisconnectArg_PDU);
return offset;
}
static int dissect_TermAttemptAuthorizedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TermAttemptAuthorizedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TermAttemptAuthorizedArg_PDU);
return offset;
}
static int dissect_TerminationAttemptArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TerminationAttemptArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TerminationAttemptArg_PDU);
return offset;
}
static int dissect_TNoAnswerArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TNoAnswerArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TNoAnswerArg_PDU);
return offset;
}
static int dissect_TSuspendedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_TSuspendedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_TSuspendedArg_PDU);
return offset;
}
static int dissect_PlayAnnouncementArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PlayAnnouncementArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PlayAnnouncementArg_PDU);
return offset;
}
static int dissect_PromptAndCollectUserInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PromptAndCollectUserInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PromptAndCollectUserInformationArg_PDU);
return offset;
}
static int dissect_ReceivedInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ReceivedInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ReceivedInformationArg_PDU);
return offset;
}
static int dissect_PromptAndReceiveMessageArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PromptAndReceiveMessageArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PromptAndReceiveMessageArg_PDU);
return offset;
}
static int dissect_MessageReceivedArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_MessageReceivedArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_MessageReceivedArg_PDU);
return offset;
}
static int dissect_ScriptCloseArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ScriptCloseArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ScriptCloseArg_PDU);
return offset;
}
static int dissect_ScriptEventArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ScriptEventArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ScriptEventArg_PDU);
return offset;
}
static int dissect_ScriptInformationArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ScriptInformationArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ScriptInformationArg_PDU);
return offset;
}
static int dissect_ScriptRunArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ScriptRunArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ScriptRunArg_PDU);
return offset;
}
static int dissect_SpecializedResourceReportArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SpecializedResourceReportArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SpecializedResourceReportArg_PDU);
return offset;
}
static int dissect_SRFCallGapArg_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_SRFCallGapArg(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_SRFCallGapArg_PDU);
return offset;
}
static int dissect_PAR_cancelFailed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PAR_cancelFailed(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PAR_cancelFailed_PDU);
return offset;
}
static int dissect_PAR_requestedInfoError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PAR_requestedInfoError(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PAR_requestedInfoError_PDU);
return offset;
}
static int dissect_ScfTaskRefusedParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ScfTaskRefusedParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ScfTaskRefusedParameter_PDU);
return offset;
}
static int dissect_ReferralParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_ReferralParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_ReferralParameter_PDU);
return offset;
}
static int dissect_UnavailableNetworkResource_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_UnavailableNetworkResource(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_UnavailableNetworkResource_PDU);
return offset;
}
static int dissect_PAR_taskRefused_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_inap_PAR_taskRefused(FALSE, tvb, offset, &asn1_ctx, tree, hf_inap_PAR_taskRefused_PDU);
return offset;
}
static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
proto_item *cause;
switch(opcode){
case opcode_activateServiceFiltering:
offset= dissect_ActivateServiceFilteringArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_analysedInformation:
offset= dissect_AnalysedInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_analyseInformation:
offset= dissect_AnalyseInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
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
case opcode_authorizeTermination:
offset= dissect_AuthorizeTerminationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_callFiltering:
offset= dissect_CallFilteringArg_PDU(tvb, actx->pinfo , tree , NULL);
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
case opcode_cancelStatusReportRequest:
offset= dissect_CancelStatusReportRequestArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_collectedInformation:
offset= dissect_CollectedInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
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
case opcode_createCallSegmentAssociation:
offset= dissect_CreateCallSegmentAssociationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_createOrRemoveTriggerData:
offset= dissect_CreateOrRemoveTriggerDataArg_PDU(tvb, actx->pinfo , tree , NULL);
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
case opcode_eventNotificationCharging:
offset= dissect_EventNotificationChargingArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_eventReportBCSM:
offset= dissect_EventReportBCSMArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_eventReportFacility:
offset= dissect_EventReportFacilityArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_facilitySelectedAndAvailable:
offset= dissect_FacilitySelectedAndAvailableArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_furnishChargingInformation:
offset= dissect_FurnishChargingInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_holdCallInNetwork:
offset= dissect_HoldCallInNetworkArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initialDP:
offset= dissect_InitialDPArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_initiateCallAttempt:
offset= dissect_InitiateCallAttemptArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_manageTriggerData:
offset= dissect_ManageTriggerDataArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_mergeCallSegments:
offset= dissect_MergeCallSegmentsArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_monitorRouteReport:
offset= dissect_MonitorRouteReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_monitorRouteRequest:
offset= dissect_MonitorRouteRequestArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_moveCallSegments:
offset= dissect_MoveCallSegmentsArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_moveLeg:
offset= dissect_MoveLegArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oAbandon:
offset= dissect_OAbandonArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oAnswer:
offset= dissect_OAnswerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oCalledPartyBusy:
offset= dissect_OCalledPartyBusyArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oDisconnect:
offset= dissect_ODisconnectArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oMidCall:
offset= dissect_MidCallArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oNoAnswer:
offset= dissect_ONoAnswerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_originationAttempt:
offset= dissect_OriginationAttemptArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_originationAttemptAuthorized:
offset= dissect_OriginationAttemptAuthorizedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_oSuspended:
offset= dissect_OSuspendedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_reconnect:
offset= dissect_ReconnectArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_releaseCall:
offset= dissect_ReleaseCallArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_reportUTSI:
offset= dissect_ReportUTSIArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestCurrentStatusReport:
offset= dissect_RequestCurrentStatusReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestEveryStatusChangeReport:
offset= dissect_RequestEveryStatusChangeReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestFirstStatusMatchReport:
offset= dissect_RequestFirstStatusMatchReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestNotificationChargingEvent:
offset= dissect_RequestNotificationChargingEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportBCSMEvent:
offset= dissect_RequestReportBCSMEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportFacilityEvent:
offset= dissect_RequestReportFacilityEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestReportUTSI:
offset= dissect_RequestReportUTSIArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_resetTimer:
offset= dissect_ResetTimerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_routeSelectFailure:
offset= dissect_RouteSelectFailureArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_selectFacility:
offset= dissect_SelectFacilityArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_selectRoute:
offset= dissect_SelectRouteArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_sendChargingInformation:
offset= dissect_SendChargingInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_sendFacilityInformation:
offset= dissect_SendFacilityInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_sendSTUI:
offset= dissect_SendSTUIArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_serviceFilteringResponse:
offset= dissect_ServiceFilteringResponseArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_setServiceProfile:
offset= dissect_SetServiceProfileArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_splitLeg:
offset= dissect_SplitLegArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_statusReport:
offset= dissect_StatusReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tAnswer:
offset= dissect_TAnswerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tBusy:
offset= dissect_TBusyArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tDisconnect:
offset= dissect_TDisconnectArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_termAttemptAuthorized:
offset= dissect_TermAttemptAuthorizedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_terminationAttempt:
offset= dissect_TerminationAttemptArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tMidCall:
offset= dissect_MidCallArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tNoAnswer:
offset= dissect_TNoAnswerArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_tSuspended:
offset= dissect_TSuspendedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_playAnnouncement:
offset= dissect_PlayAnnouncementArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_promptAndCollectUserInformation:
offset= dissect_PromptAndCollectUserInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_promptAndReceiveMessage:
offset= dissect_PromptAndReceiveMessageArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_scriptClose:
offset= dissect_ScriptCloseArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_scriptEvent:
offset= dissect_ScriptEventArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_scriptInformation:
offset= dissect_ScriptInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_scriptRun:
offset= dissect_ScriptRunArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_specializedResourceReport:
offset= dissect_SpecializedResourceReportArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_srfCallGap:
offset= dissect_SRFCallGapArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown invokeData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown invokeData %d",opcode);
break;
}
return offset;
}
static int dissect_returnResultData(proto_tree *tree, tvbuff_t *tvb, int offset,asn1_ctx_t *actx) {
proto_item *cause;
switch(opcode){
case opcode_createCallSegmentAssociation:
offset= dissect_CreateCallSegmentAssociationResultArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_createOrRemoveTriggerData:
offset= dissect_CreateOrRemoveTriggerDataResultArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_manageTriggerData:
offset= dissect_ManageTriggerDataResultArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_requestCurrentStatusReport:
offset= dissect_RequestCurrentStatusReportResultArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_promptAndCollectUserInformation:
offset= dissect_ReceivedInformationArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
case opcode_promptAndReceiveMessage:
offset= dissect_MessageReceivedArg_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown returnResultData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown returnResultData %d",opcode);
}
return offset;
}
static int dissect_returnErrorData(proto_tree *tree, tvbuff_t *tvb, int offset,asn1_ctx_t *actx) {
proto_item *cause;
switch(errorCode) {
case errcode_cancelFailed:
dissect_PAR_cancelFailed_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_requestedInfoError:
dissect_PAR_requestedInfoError_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_scfTaskRefused:
dissect_ScfTaskRefusedParameter_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_scfReferral:
dissect_ReferralParameter_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_systemFailure:
dissect_UnavailableNetworkResource_PDU(tvb, actx->pinfo , tree , NULL);
break;
case errcode_taskRefused:
dissect_PAR_taskRefused_PDU(tvb, actx->pinfo , tree , NULL);
break;
default:
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown returnErrorData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown returnErrorData %d",errorCode);
}
return offset;
}
static void
dissect_inap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "INAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_inap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_inap);
}
inap_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
inap_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
opcode = 0;
dissect_inap_ROS(TRUE, tvb, offset, &asn1_ctx, tree, -1);
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, inap_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, inap_handle);
}
}
void proto_reg_handoff_inap(void) {
static gboolean inap_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!inap_prefs_initialized) {
inap_prefs_initialized = TRUE;
inap_handle = find_dissector("inap");
data_handle = find_dissector("data");
oid_add_from_string("Core-INAP-CS1-Codes","0.4.0.1.1.0.3.0");
oid_add_from_string("iso(1) identified-organization(3) icd-ecma(12) member-company(2) 1107 oen(3) inap(3) extensions(2)","1.3.12.2.1107.3.3.2");
oid_add_from_string("alcatel(1006)","1.3.12.2.1006.64");
oid_add_from_string("Siemens (1107)","1.3.12.2.1107");
oid_add_from_string("iso(1) member-body(2) gb(826) national(0) ericsson(1249) inDomain(51) inNetwork(1) inNetworkcapabilitySet1plus(1) ","1.2.826.0.1249.51.1.1");
}
else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_inap(void) {
module_t *inap_module;
static hf_register_info hf[] = {
#line 1 "../../asn1/inap/packet-inap-hfarr.c"
{ &hf_inap_ActivateServiceFilteringArg_PDU,
{ "ActivateServiceFilteringArg", "inap.ActivateServiceFilteringArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_AnalysedInformationArg_PDU,
{ "AnalysedInformationArg", "inap.AnalysedInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_AnalyseInformationArg_PDU,
{ "AnalyseInformationArg", "inap.AnalyseInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ApplyChargingArg_PDU,
{ "ApplyChargingArg", "inap.ApplyChargingArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ApplyChargingReportArg_PDU,
{ "ApplyChargingReportArg", "inap.ApplyChargingReportArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_AssistRequestInstructionsArg_PDU,
{ "AssistRequestInstructionsArg", "inap.AssistRequestInstructionsArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_AuthorizeTerminationArg_PDU,
{ "AuthorizeTerminationArg", "inap.AuthorizeTerminationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CallFilteringArg_PDU,
{ "CallFilteringArg", "inap.CallFilteringArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CallGapArg_PDU,
{ "CallGapArg", "inap.CallGapArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CallInformationReportArg_PDU,
{ "CallInformationReportArg", "inap.CallInformationReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CallInformationRequestArg_PDU,
{ "CallInformationRequestArg", "inap.CallInformationRequestArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CancelArg_PDU,
{ "CancelArg", "inap.CancelArg",
FT_UINT32, BASE_DEC, VALS(inap_CancelArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_CancelStatusReportRequestArg_PDU,
{ "CancelStatusReportRequestArg", "inap.CancelStatusReportRequestArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CollectedInformationArg_PDU,
{ "CollectedInformationArg", "inap.CollectedInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CollectInformationArg_PDU,
{ "CollectInformationArg", "inap.CollectInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ConnectArg_PDU,
{ "ConnectArg", "inap.ConnectArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ConnectToResourceArg_PDU,
{ "ConnectToResourceArg", "inap.ConnectToResourceArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ContinueWithArgumentArg_PDU,
{ "ContinueWithArgumentArg", "inap.ContinueWithArgumentArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CreateCallSegmentAssociationArg_PDU,
{ "CreateCallSegmentAssociationArg", "inap.CreateCallSegmentAssociationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CreateCallSegmentAssociationResultArg_PDU,
{ "CreateCallSegmentAssociationResultArg", "inap.CreateCallSegmentAssociationResultArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CreateOrRemoveTriggerDataArg_PDU,
{ "CreateOrRemoveTriggerDataArg", "inap.CreateOrRemoveTriggerDataArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_CreateOrRemoveTriggerDataResultArg_PDU,
{ "CreateOrRemoveTriggerDataResultArg", "inap.CreateOrRemoveTriggerDataResultArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_DisconnectForwardConnectionWithArgumentArg_PDU,
{ "DisconnectForwardConnectionWithArgumentArg", "inap.DisconnectForwardConnectionWithArgumentArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_DisconnectLegArg_PDU,
{ "DisconnectLegArg", "inap.DisconnectLegArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_EntityReleasedArg_PDU,
{ "EntityReleasedArg", "inap.EntityReleasedArg",
FT_UINT32, BASE_DEC, VALS(inap_EntityReleasedArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_EstablishTemporaryConnectionArg_PDU,
{ "EstablishTemporaryConnectionArg", "inap.EstablishTemporaryConnectionArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_EventNotificationChargingArg_PDU,
{ "EventNotificationChargingArg", "inap.EventNotificationChargingArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_EventReportBCSMArg_PDU,
{ "EventReportBCSMArg", "inap.EventReportBCSMArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_EventReportFacilityArg_PDU,
{ "EventReportFacilityArg", "inap.EventReportFacilityArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_FacilitySelectedAndAvailableArg_PDU,
{ "FacilitySelectedAndAvailableArg", "inap.FacilitySelectedAndAvailableArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_FurnishChargingInformationArg_PDU,
{ "FurnishChargingInformationArg", "inap.FurnishChargingInformationArg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_HoldCallInNetworkArg_PDU,
{ "HoldCallInNetworkArg", "inap.HoldCallInNetworkArg",
FT_UINT32, BASE_DEC, VALS(inap_HoldCallInNetworkArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_InitialDPArg_PDU,
{ "InitialDPArg", "inap.InitialDPArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_InitiateCallAttemptArg_PDU,
{ "InitiateCallAttemptArg", "inap.InitiateCallAttemptArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ManageTriggerDataArg_PDU,
{ "ManageTriggerDataArg", "inap.ManageTriggerDataArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ManageTriggerDataResultArg_PDU,
{ "ManageTriggerDataResultArg", "inap.ManageTriggerDataResultArg",
FT_UINT32, BASE_DEC, VALS(inap_ManageTriggerDataResultArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_MergeCallSegmentsArg_PDU,
{ "MergeCallSegmentsArg", "inap.MergeCallSegmentsArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MonitorRouteReportArg_PDU,
{ "MonitorRouteReportArg", "inap.MonitorRouteReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MonitorRouteRequestArg_PDU,
{ "MonitorRouteRequestArg", "inap.MonitorRouteRequestArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MoveCallSegmentsArg_PDU,
{ "MoveCallSegmentsArg", "inap.MoveCallSegmentsArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MoveLegArg_PDU,
{ "MoveLegArg", "inap.MoveLegArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OAbandonArg_PDU,
{ "OAbandonArg", "inap.OAbandonArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OAnswerArg_PDU,
{ "OAnswerArg", "inap.OAnswerArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OCalledPartyBusyArg_PDU,
{ "OCalledPartyBusyArg", "inap.OCalledPartyBusyArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ODisconnectArg_PDU,
{ "ODisconnectArg", "inap.ODisconnectArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MidCallArg_PDU,
{ "MidCallArg", "inap.MidCallArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ONoAnswerArg_PDU,
{ "ONoAnswerArg", "inap.ONoAnswerArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OriginationAttemptArg_PDU,
{ "OriginationAttemptArg", "inap.OriginationAttemptArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OriginationAttemptAuthorizedArg_PDU,
{ "OriginationAttemptAuthorizedArg", "inap.OriginationAttemptAuthorizedArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_OSuspendedArg_PDU,
{ "OSuspendedArg", "inap.OSuspendedArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ReconnectArg_PDU,
{ "ReconnectArg", "inap.ReconnectArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ReleaseCallArg_PDU,
{ "ReleaseCallArg", "inap.ReleaseCallArg",
FT_UINT32, BASE_DEC, VALS(inap_ReleaseCallArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_ReportUTSIArg_PDU,
{ "ReportUTSIArg", "inap.ReportUTSIArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestCurrentStatusReportArg_PDU,
{ "RequestCurrentStatusReportArg", "inap.RequestCurrentStatusReportArg",
FT_UINT32, BASE_DEC, VALS(inap_ResourceID_vals), 0,
NULL, HFILL }},
{ &hf_inap_RequestCurrentStatusReportResultArg_PDU,
{ "RequestCurrentStatusReportResultArg", "inap.RequestCurrentStatusReportResultArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestEveryStatusChangeReportArg_PDU,
{ "RequestEveryStatusChangeReportArg", "inap.RequestEveryStatusChangeReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestFirstStatusMatchReportArg_PDU,
{ "RequestFirstStatusMatchReportArg", "inap.RequestFirstStatusMatchReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestNotificationChargingEventArg_PDU,
{ "RequestNotificationChargingEventArg", "inap.RequestNotificationChargingEventArg",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestReportBCSMEventArg_PDU,
{ "RequestReportBCSMEventArg", "inap.RequestReportBCSMEventArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestReportFacilityEventArg_PDU,
{ "RequestReportFacilityEventArg", "inap.RequestReportFacilityEventArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestReportUTSIArg_PDU,
{ "RequestReportUTSIArg", "inap.RequestReportUTSIArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ResetTimerArg_PDU,
{ "ResetTimerArg", "inap.ResetTimerArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RouteSelectFailureArg_PDU,
{ "RouteSelectFailureArg", "inap.RouteSelectFailureArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SelectFacilityArg_PDU,
{ "SelectFacilityArg", "inap.SelectFacilityArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SelectRouteArg_PDU,
{ "SelectRouteArg", "inap.SelectRouteArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SendChargingInformationArg_PDU,
{ "SendChargingInformationArg", "inap.SendChargingInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SendFacilityInformationArg_PDU,
{ "SendFacilityInformationArg", "inap.SendFacilityInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SendSTUIArg_PDU,
{ "SendSTUIArg", "inap.SendSTUIArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ServiceFilteringResponseArg_PDU,
{ "ServiceFilteringResponseArg", "inap.ServiceFilteringResponseArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SetServiceProfileArg_PDU,
{ "SetServiceProfileArg", "inap.SetServiceProfileArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SplitLegArg_PDU,
{ "SplitLegArg", "inap.SplitLegArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_StatusReportArg_PDU,
{ "StatusReportArg", "inap.StatusReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TAnswerArg_PDU,
{ "TAnswerArg", "inap.TAnswerArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TBusyArg_PDU,
{ "TBusyArg", "inap.TBusyArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TDisconnectArg_PDU,
{ "TDisconnectArg", "inap.TDisconnectArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TermAttemptAuthorizedArg_PDU,
{ "TermAttemptAuthorizedArg", "inap.TermAttemptAuthorizedArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TerminationAttemptArg_PDU,
{ "TerminationAttemptArg", "inap.TerminationAttemptArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TNoAnswerArg_PDU,
{ "TNoAnswerArg", "inap.TNoAnswerArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_TSuspendedArg_PDU,
{ "TSuspendedArg", "inap.TSuspendedArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_PlayAnnouncementArg_PDU,
{ "PlayAnnouncementArg", "inap.PlayAnnouncementArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_PromptAndCollectUserInformationArg_PDU,
{ "PromptAndCollectUserInformationArg", "inap.PromptAndCollectUserInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ReceivedInformationArg_PDU,
{ "ReceivedInformationArg", "inap.ReceivedInformationArg",
FT_UINT32, BASE_DEC, VALS(inap_ReceivedInformationArg_vals), 0,
NULL, HFILL }},
{ &hf_inap_PromptAndReceiveMessageArg_PDU,
{ "PromptAndReceiveMessageArg", "inap.PromptAndReceiveMessageArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_MessageReceivedArg_PDU,
{ "MessageReceivedArg", "inap.MessageReceivedArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ScriptCloseArg_PDU,
{ "ScriptCloseArg", "inap.ScriptCloseArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ScriptEventArg_PDU,
{ "ScriptEventArg", "inap.ScriptEventArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ScriptInformationArg_PDU,
{ "ScriptInformationArg", "inap.ScriptInformationArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ScriptRunArg_PDU,
{ "ScriptRunArg", "inap.ScriptRunArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SpecializedResourceReportArg_PDU,
{ "SpecializedResourceReportArg", "inap.SpecializedResourceReportArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_SRFCallGapArg_PDU,
{ "SRFCallGapArg", "inap.SRFCallGapArg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_PAR_cancelFailed_PDU,
{ "PAR-cancelFailed", "inap.PAR_cancelFailed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_PAR_requestedInfoError_PDU,
{ "PAR-requestedInfoError", "inap.PAR_requestedInfoError",
FT_UINT32, BASE_DEC, VALS(inap_PAR_requestedInfoError_vals), 0,
NULL, HFILL }},
{ &hf_inap_ScfTaskRefusedParameter_PDU,
{ "ScfTaskRefusedParameter", "inap.ScfTaskRefusedParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ReferralParameter_PDU,
{ "ReferralParameter", "inap.ReferralParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_UnavailableNetworkResource_PDU,
{ "UnavailableNetworkResource", "inap.UnavailableNetworkResource",
FT_UINT32, BASE_DEC, VALS(inap_UnavailableNetworkResource_vals), 0,
NULL, HFILL }},
{ &hf_inap_PAR_taskRefused_PDU,
{ "PAR-taskRefused", "inap.PAR_taskRefused",
FT_UINT32, BASE_DEC, VALS(inap_PAR_taskRefused_vals), 0,
NULL, HFILL }},
{ &hf_inap_Extensions_item,
{ "ExtensionField", "inap.ExtensionField",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_type,
{ "type", "inap.type",
FT_UINT32, BASE_DEC, VALS(inap_Code_vals), 0,
"Code", HFILL }},
{ &hf_inap_criticality,
{ "criticality", "inap.criticality",
FT_UINT32, BASE_DEC, VALS(inap_CriticalityType_vals), 0,
"CriticalityType", HFILL }},
{ &hf_inap_value,
{ "value", "inap.value",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_AlternativeIdentities_item,
{ "AlternativeIdentity", "inap.AlternativeIdentity",
FT_UINT32, BASE_DEC, VALS(inap_AlternativeIdentity_vals), 0,
NULL, HFILL }},
{ &hf_inap_url,
{ "url", "inap.url",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_512", HFILL }},
{ &hf_inap_conferenceTreatmentIndicator,
{ "conferenceTreatmentIndicator", "inap.conferenceTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_callCompletionTreatmentIndicator,
{ "callCompletionTreatmentIndicator", "inap.callCompletionTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_holdTreatmentIndicator,
{ "holdTreatmentIndicator", "inap.holdTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_ectTreatmentIndicator,
{ "ectTreatmentIndicator", "inap.ectTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_calledAddressValue,
{ "calledAddressValue", "inap.calledAddressValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_gapOnService,
{ "gapOnService", "inap.gapOnService",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_gapAllInTraffic,
{ "gapAllInTraffic", "inap.gapAllInTraffic",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_calledAddressAndService,
{ "calledAddressAndService", "inap.calledAddressAndService",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_serviceKey,
{ "serviceKey", "inap.serviceKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingAddressAndService,
{ "callingAddressAndService", "inap.callingAddressAndService",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingAddressValue,
{ "callingAddressValue", "inap.callingAddressValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_locationNumber,
{ "locationNumber", "inap.locationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_eventTypeBCSM,
{ "eventTypeBCSM", "inap.eventTypeBCSM",
FT_UINT32, BASE_DEC, VALS(inap_EventTypeBCSM_vals), 0,
NULL, HFILL }},
{ &hf_inap_monitorMode,
{ "monitorMode", "inap.monitorMode",
FT_UINT32, BASE_DEC, VALS(inap_MonitorMode_vals), 0,
NULL, HFILL }},
{ &hf_inap_legID,
{ "legID", "inap.legID",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
NULL, HFILL }},
{ &hf_inap_dpSpecificCriteria,
{ "dpSpecificCriteria", "inap.dpSpecificCriteria",
FT_UINT32, BASE_DEC, VALS(inap_DpSpecificCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_bearerCap,
{ "bearerCap", "inap.bearerCap",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tmr,
{ "tmr", "inap.tmr",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_broadbandBearerCap,
{ "broadbandBearerCap", "inap.broadbandBearerCap",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_minBroadbandBearerCapabilityLength_maxBroadbandBearerCapabilityLength", HFILL }},
{ &hf_inap_aALParameters,
{ "aALParameters", "inap.aALParameters",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_additionalATMCellRate,
{ "additionalATMCellRate", "inap.additionalATMCellRate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_aESACalledParty,
{ "aESACalledParty", "inap.aESACalledParty",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_aESACallingParty,
{ "aESACallingParty", "inap.aESACallingParty",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_alternativeATMTrafficDescriptor,
{ "alternativeATMTrafficDescriptor", "inap.alternativeATMTrafficDescriptor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_aTMCellRate,
{ "aTMCellRate", "inap.aTMCellRate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cDVTDescriptor,
{ "cDVTDescriptor", "inap.cDVTDescriptor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cumulativeTransitDelay,
{ "cumulativeTransitDelay", "inap.cumulativeTransitDelay",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_endToEndTransitDelay,
{ "endToEndTransitDelay", "inap.endToEndTransitDelay",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_minAcceptableATMTrafficDescriptor,
{ "minAcceptableATMTrafficDescriptor", "inap.minAcceptableATMTrafficDescriptor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_eventTypeCharging,
{ "eventTypeCharging", "inap.eventTypeCharging",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_componentInfo,
{ "componentInfo", "inap.componentInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_118", HFILL }},
{ &hf_inap_relayedComponent,
{ "relayedComponent", "inap.relayedComponent",
FT_NONE, BASE_NONE, NULL, 0,
"EMBEDDED_PDV", HFILL }},
{ &hf_inap_basicGapCriteria,
{ "basicGapCriteria", "inap.basicGapCriteria",
FT_UINT32, BASE_DEC, VALS(inap_BasicGapCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_scfID,
{ "scfID", "inap.scfID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_counterID,
{ "counterID", "inap.counterID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_counterValue,
{ "counterValue", "inap.counterValue",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_CountersValue_item,
{ "CounterAndValue", "inap.CounterAndValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_action,
{ "action", "inap.action",
FT_UINT32, BASE_DEC, VALS(inap_T_action_vals), 0,
NULL, HFILL }},
{ &hf_inap_treatment,
{ "treatment", "inap.treatment",
FT_UINT32, BASE_DEC, VALS(inap_GapTreatment_vals), 0,
"GapTreatment", HFILL }},
{ &hf_inap_DestinationRoutingAddress_item,
{ "CalledPartyNumber", "inap.CalledPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_serviceAddressInformation,
{ "serviceAddressInformation", "inap.serviceAddressInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bearerCapability,
{ "bearerCapability", "inap.bearerCapability",
FT_UINT32, BASE_DEC, VALS(inap_BearerCapability_vals), 0,
NULL, HFILL }},
{ &hf_inap_calledPartyNumber,
{ "calledPartyNumber", "inap.calledPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingPartyNumber,
{ "callingPartyNumber", "inap.callingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingPartysCategory,
{ "callingPartysCategory", "inap.callingPartysCategory",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &isup_calling_partys_category_value_ext, 0,
NULL, HFILL }},
{ &hf_inap_iPSSPCapabilities,
{ "iPSSPCapabilities", "inap.iPSSPCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_iPAvailable,
{ "iPAvailable", "inap.iPAvailable",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_iSDNAccessRelatedInformation,
{ "iSDNAccessRelatedInformation", "inap.iSDNAccessRelatedInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cGEncountered,
{ "cGEncountered", "inap.cGEncountered",
FT_UINT32, BASE_DEC, VALS(inap_CGEncountered_vals), 0,
NULL, HFILL }},
{ &hf_inap_serviceProfileIdentifier,
{ "serviceProfileIdentifier", "inap.serviceProfileIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_terminalType,
{ "terminalType", "inap.terminalType",
FT_UINT32, BASE_DEC, VALS(inap_TerminalType_vals), 0,
NULL, HFILL }},
{ &hf_inap_extensions,
{ "extensions", "inap.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_chargeNumber,
{ "chargeNumber", "inap.chargeNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_servingAreaID,
{ "servingAreaID", "inap.servingAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_serviceInteractionIndicators,
{ "serviceInteractionIndicators", "inap.serviceInteractionIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_iNServiceCompatibilityIndication,
{ "iNServiceCompatibilityIndication", "inap.iNServiceCompatibilityIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_serviceInteractionIndicatorsTwo,
{ "serviceInteractionIndicatorsTwo", "inap.serviceInteractionIndicatorsTwo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_uSIServiceIndicator,
{ "uSIServiceIndicator", "inap.uSIServiceIndicator",
FT_UINT32, BASE_DEC, VALS(inap_USIServiceIndicator_vals), 0,
NULL, HFILL }},
{ &hf_inap_uSIInformation,
{ "uSIInformation", "inap.uSIInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_forwardGVNS,
{ "forwardGVNS", "inap.forwardGVNS",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_createdCallSegmentAssociation,
{ "createdCallSegmentAssociation", "inap.createdCallSegmentAssociation",
FT_UINT32, BASE_DEC, NULL, 0,
"CSAID", HFILL }},
{ &hf_inap_ipRelatedInformation,
{ "ipRelatedInformation", "inap.ipRelatedInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_numberOfDigits,
{ "numberOfDigits", "inap.numberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_applicationTimer,
{ "applicationTimer", "inap.applicationTimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_midCallControlInfo,
{ "midCallControlInfo", "inap.midCallControlInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_numberOfDigitsTwo,
{ "numberOfDigitsTwo", "inap.numberOfDigitsTwo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_requestedNumberOfDigits,
{ "requestedNumberOfDigits", "inap.requestedNumberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"NumberOfDigits", HFILL }},
{ &hf_inap_minNumberOfDigits,
{ "minNumberOfDigits", "inap.minNumberOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"NumberOfDigits", HFILL }},
{ &hf_inap_agreements,
{ "agreements", "inap.agreements",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_inap_networkSpecific,
{ "networkSpecific", "inap.networkSpecific",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_collectedInfoSpecificInfo,
{ "collectedInfoSpecificInfo", "inap.collectedInfoSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_calledPartynumber,
{ "calledPartynumber", "inap.calledPartynumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_analysedInfoSpecificInfo,
{ "analysedInfoSpecificInfo", "inap.analysedInfoSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_routeSelectFailureSpecificInfo,
{ "routeSelectFailureSpecificInfo", "inap.routeSelectFailureSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_failureCause,
{ "failureCause", "inap.failureCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_oCalledPartyBusySpecificInfo,
{ "oCalledPartyBusySpecificInfo", "inap.oCalledPartyBusySpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_busyCause,
{ "busyCause", "inap.busyCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_oNoAnswerSpecificInfo,
{ "oNoAnswerSpecificInfo", "inap.oNoAnswerSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cause,
{ "cause", "inap.cause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oAnswerSpecificInfo,
{ "oAnswerSpecificInfo", "inap.oAnswerSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_backwardGVNS,
{ "backwardGVNS", "inap.backwardGVNS",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oMidCallSpecificInfo,
{ "oMidCallSpecificInfo", "inap.oMidCallSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_connectTime,
{ "connectTime", "inap.connectTime",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_oMidCallInfo,
{ "oMidCallInfo", "inap.oMidCallInfo",
FT_NONE, BASE_NONE, NULL, 0,
"MidCallInfo", HFILL }},
{ &hf_inap_oDisconnectSpecificInfo,
{ "oDisconnectSpecificInfo", "inap.oDisconnectSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_releaseCause,
{ "releaseCause", "inap.releaseCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_tBusySpecificInfo,
{ "tBusySpecificInfo", "inap.tBusySpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tNoAnswerSpecificInfo,
{ "tNoAnswerSpecificInfo", "inap.tNoAnswerSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tAnswerSpecificInfo,
{ "tAnswerSpecificInfo", "inap.tAnswerSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tMidCallSpecificInfo,
{ "tMidCallSpecificInfo", "inap.tMidCallSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tMidCallInfo,
{ "tMidCallInfo", "inap.tMidCallInfo",
FT_NONE, BASE_NONE, NULL, 0,
"MidCallInfo", HFILL }},
{ &hf_inap_tDisconnectSpecificInfo,
{ "tDisconnectSpecificInfo", "inap.tDisconnectSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oTermSeizedSpecificInfo,
{ "oTermSeizedSpecificInfo", "inap.oTermSeizedSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oSuspend,
{ "oSuspend", "inap.oSuspend",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tSuspend,
{ "tSuspend", "inap.tSuspend",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_origAttemptAuthorized,
{ "origAttemptAuthorized", "inap.origAttemptAuthorized",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oReAnswer,
{ "oReAnswer", "inap.oReAnswer",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tReAnswer,
{ "tReAnswer", "inap.tReAnswer",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_facilitySelectedAndAvailable,
{ "facilitySelectedAndAvailable", "inap.facilitySelectedAndAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callAccepted,
{ "callAccepted", "inap.callAccepted",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oAbandon,
{ "oAbandon", "inap.oAbandon",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_abandonCause,
{ "abandonCause", "inap.abandonCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_tAbandon,
{ "tAbandon", "inap.tAbandon",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_authorizeRouteFailure,
{ "authorizeRouteFailure", "inap.authorizeRouteFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_authoriseRouteFailureCause,
{ "authoriseRouteFailureCause", "inap.authoriseRouteFailureCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_terminationAttemptAuthorized,
{ "terminationAttemptAuthorized", "inap.terminationAttemptAuthorized",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_originationAttemptDenied,
{ "originationAttemptDenied", "inap.originationAttemptDenied",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_originationDeniedCause,
{ "originationDeniedCause", "inap.originationDeniedCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_terminationAttemptDenied,
{ "terminationAttemptDenied", "inap.terminationAttemptDenied",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_terminationDeniedCause,
{ "terminationDeniedCause", "inap.terminationDeniedCause",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_oModifyRequestSpecificInfo,
{ "oModifyRequestSpecificInfo", "inap.oModifyRequestSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oModifyResultSpecificInfo,
{ "oModifyResultSpecificInfo", "inap.oModifyResultSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_modifyResultType,
{ "modifyResultType", "inap.modifyResultType",
FT_UINT32, BASE_DEC, VALS(inap_ModifyResultType_vals), 0,
NULL, HFILL }},
{ &hf_inap_tModifyRequestSpecificInfo,
{ "tModifyRequestSpecificInfo", "inap.tModifyRequestSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tModifyResultSpecificInfo,
{ "tModifyResultSpecificInfo", "inap.tModifyResultSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_trunkGroupID,
{ "trunkGroupID", "inap.trunkGroupID",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_privateFacilityID,
{ "privateFacilityID", "inap.privateFacilityID",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_huntGroup,
{ "huntGroup", "inap.huntGroup",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_inap_routeIndex,
{ "routeIndex", "inap.routeIndex",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_inap_sFBillingChargingCharacteristics,
{ "sFBillingChargingCharacteristics", "inap.sFBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_informationToSend,
{ "informationToSend", "inap.informationToSend",
FT_UINT32, BASE_DEC, VALS(inap_InformationToSend_vals), 0,
NULL, HFILL }},
{ &hf_inap_maximumNumberOfCounters,
{ "maximumNumberOfCounters", "inap.maximumNumberOfCounters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_interval,
{ "interval", "inap.interval",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1_32000", HFILL }},
{ &hf_inap_numberOfCalls,
{ "numberOfCalls", "inap.numberOfCalls",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_dialledNumber,
{ "dialledNumber", "inap.dialledNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_callingLineID,
{ "callingLineID", "inap.callingLineID",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_addressAndService,
{ "addressAndService", "inap.addressAndService",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_duration,
{ "duration", "inap.duration",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_stopTime,
{ "stopTime", "inap.stopTime",
FT_BYTES, BASE_NONE, NULL, 0,
"DateAndTime", HFILL }},
{ &hf_inap_callDiversionTreatmentIndicator,
{ "callDiversionTreatmentIndicator", "inap.callDiversionTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_callOfferingTreatmentIndicator,
{ "callOfferingTreatmentIndicator", "inap.callOfferingTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_callWaitingTreatmentIndicator,
{ "callWaitingTreatmentIndicator", "inap.callWaitingTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_inap_compoundCapCriteria,
{ "compoundCapCriteria", "inap.compoundCapCriteria",
FT_NONE, BASE_NONE, NULL, 0,
"CompoundCriteria", HFILL }},
{ &hf_inap_dpCriteria,
{ "dpCriteria", "inap.dpCriteria",
FT_UINT32, BASE_DEC, VALS(inap_EventTypeBCSM_vals), 0,
"EventTypeBCSM", HFILL }},
{ &hf_inap_gapInterval,
{ "gapInterval", "inap.gapInterval",
FT_INT32, BASE_DEC, NULL, 0,
"Interval", HFILL }},
{ &hf_inap_both,
{ "both", "inap.both",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_GenericNumbers_item,
{ "GenericNumber", "inap.GenericNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_actionOnProfile,
{ "actionOnProfile", "inap.actionOnProfile",
FT_UINT32, BASE_DEC, VALS(inap_ActionOnProfile_vals), 0,
NULL, HFILL }},
{ &hf_inap_tDPIdentifier,
{ "tDPIdentifier", "inap.tDPIdentifier",
FT_UINT32, BASE_DEC, VALS(inap_TDPIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_inap_dPName,
{ "dPName", "inap.dPName",
FT_UINT32, BASE_DEC, VALS(inap_EventTypeBCSM_vals), 0,
"EventTypeBCSM", HFILL }},
{ &hf_inap_INServiceCompatibilityIndication_item,
{ "Entry", "inap.Entry",
FT_UINT32, BASE_DEC, VALS(inap_Entry_vals), 0,
NULL, HFILL }},
{ &hf_inap_alternativeCalledPartyIds,
{ "alternativeCalledPartyIds", "inap.alternativeCalledPartyIds",
FT_UINT32, BASE_DEC, NULL, 0,
"AlternativeIdentities", HFILL }},
{ &hf_inap_alternativeOriginatingPartyIds,
{ "alternativeOriginatingPartyIds", "inap.alternativeOriginatingPartyIds",
FT_UINT32, BASE_DEC, NULL, 0,
"AlternativeIdentities", HFILL }},
{ &hf_inap_alternativeOriginalCalledPartyIds,
{ "alternativeOriginalCalledPartyIds", "inap.alternativeOriginalCalledPartyIds",
FT_UINT32, BASE_DEC, NULL, 0,
"AlternativeIdentities", HFILL }},
{ &hf_inap_alternativeRedirectingPartyIds,
{ "alternativeRedirectingPartyIds", "inap.alternativeRedirectingPartyIds",
FT_UINT32, BASE_DEC, NULL, 0,
"AlternativeIdentities", HFILL }},
{ &hf_inap_sendingSideID,
{ "sendingSideID", "inap.sendingSideID",
FT_BYTES, BASE_NONE, NULL, 0,
"LegType", HFILL }},
{ &hf_inap_receivingSideID,
{ "receivingSideID", "inap.receivingSideID",
FT_BYTES, BASE_NONE, NULL, 0,
"LegType", HFILL }},
{ &hf_inap_MidCallControlInfo_item,
{ "MidCallControlInfo item", "inap.MidCallControlInfo_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_midCallInfoType,
{ "midCallInfoType", "inap.midCallInfoType",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_midCallReportType,
{ "midCallReportType", "inap.midCallReportType",
FT_UINT32, BASE_DEC, VALS(inap_T_midCallReportType_vals), 0,
NULL, HFILL }},
{ &hf_inap_iNServiceControlCode,
{ "iNServiceControlCode", "inap.iNServiceControlCode",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_iNServiceControlCodeLow,
{ "iNServiceControlCodeLow", "inap.iNServiceControlCodeLow",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_iNServiceControlCodeHigh,
{ "iNServiceControlCodeHigh", "inap.iNServiceControlCodeHigh",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_messageType,
{ "messageType", "inap.messageType",
FT_UINT32, BASE_DEC, VALS(inap_T_messageType_vals), 0,
NULL, HFILL }},
{ &hf_inap_dpAssignment,
{ "dpAssignment", "inap.dpAssignment",
FT_UINT32, BASE_DEC, VALS(inap_T_dpAssignment_vals), 0,
NULL, HFILL }},
{ &hf_inap_threshold,
{ "threshold", "inap.threshold",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_interval_01,
{ "interval", "inap.interval",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_access,
{ "access", "inap.access",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyNumber", HFILL }},
{ &hf_inap_group,
{ "group", "inap.group",
FT_UINT32, BASE_DEC, VALS(inap_FacilityGroup_vals), 0,
"FacilityGroup", HFILL }},
{ &hf_inap_RequestedInformationList_item,
{ "RequestedInformation", "inap.RequestedInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RequestedInformationTypeList_item,
{ "RequestedInformationType", "inap.RequestedInformationType",
FT_UINT32, BASE_DEC, VALS(inap_RequestedInformationType_vals), 0,
NULL, HFILL }},
{ &hf_inap_requestedInformationType,
{ "requestedInformationType", "inap.requestedInformationType",
FT_UINT32, BASE_DEC, VALS(inap_RequestedInformationType_vals), 0,
NULL, HFILL }},
{ &hf_inap_requestedInformationValue,
{ "requestedInformationValue", "inap.requestedInformationValue",
FT_UINT32, BASE_DEC, VALS(inap_RequestedInformationValue_vals), 0,
NULL, HFILL }},
{ &hf_inap_callAttemptElapsedTimeValue,
{ "callAttemptElapsedTimeValue", "inap.callAttemptElapsedTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_inap_callStopTimeValue,
{ "callStopTimeValue", "inap.callStopTimeValue",
FT_BYTES, BASE_NONE, NULL, 0,
"DateAndTime", HFILL }},
{ &hf_inap_callConnectedElapsedTimeValue,
{ "callConnectedElapsedTimeValue", "inap.callConnectedElapsedTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_releaseCauseValue,
{ "releaseCauseValue", "inap.releaseCauseValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_uSImonitorMode,
{ "uSImonitorMode", "inap.uSImonitorMode",
FT_UINT32, BASE_DEC, VALS(inap_USIMonitorMode_vals), 0,
NULL, HFILL }},
{ &hf_inap_RequestedUTSIList_item,
{ "RequestedUTSI", "inap.RequestedUTSI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_lineID,
{ "lineID", "inap.lineID",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_facilityGroupID,
{ "facilityGroupID", "inap.facilityGroupID",
FT_UINT32, BASE_DEC, VALS(inap_FacilityGroup_vals), 0,
"FacilityGroup", HFILL }},
{ &hf_inap_facilityGroupMemberID,
{ "facilityGroupMemberID", "inap.facilityGroupMemberID",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_RouteCountersValue_item,
{ "RouteCountersAndValue", "inap.RouteCountersAndValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_route,
{ "route", "inap.route",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_RouteList_item,
{ "Route", "inap.Route",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_miscCallInfo,
{ "miscCallInfo", "inap.miscCallInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_triggerType,
{ "triggerType", "inap.triggerType",
FT_UINT32, BASE_DEC, VALS(inap_TriggerType_vals), 0,
NULL, HFILL }},
{ &hf_inap_forwardServiceInteractionInd,
{ "forwardServiceInteractionInd", "inap.forwardServiceInteractionInd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_backwardServiceInteractionInd,
{ "backwardServiceInteractionInd", "inap.backwardServiceInteractionInd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bothwayThroughConnectionInd,
{ "bothwayThroughConnectionInd", "inap.bothwayThroughConnectionInd",
FT_UINT32, BASE_DEC, VALS(inap_BothwayThroughConnectionInd_vals), 0,
NULL, HFILL }},
{ &hf_inap_suspendTimer,
{ "suspendTimer", "inap.suspendTimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_connectedNumberTreatmentInd,
{ "connectedNumberTreatmentInd", "inap.connectedNumberTreatmentInd",
FT_UINT32, BASE_DEC, VALS(inap_ConnectedNumberTreatmentInd_vals), 0,
NULL, HFILL }},
{ &hf_inap_suppressCallDiversionNotification,
{ "suppressCallDiversionNotification", "inap.suppressCallDiversionNotification",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_suppressCallTransferNotification,
{ "suppressCallTransferNotification", "inap.suppressCallTransferNotification",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_allowCdINNoPresentationInd,
{ "allowCdINNoPresentationInd", "inap.allowCdINNoPresentationInd",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_userDialogueDurationInd,
{ "userDialogueDurationInd", "inap.userDialogueDurationInd",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_overrideLineRestrictions,
{ "overrideLineRestrictions", "inap.overrideLineRestrictions",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_suppressVPNAPP,
{ "suppressVPNAPP", "inap.suppressVPNAPP",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_calledINNumberOverriding,
{ "calledINNumberOverriding", "inap.calledINNumberOverriding",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_redirectServiceTreatmentInd,
{ "redirectServiceTreatmentInd", "inap.redirectServiceTreatmentInd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_redirectReason,
{ "redirectReason", "inap.redirectReason",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_nonCUGCall,
{ "nonCUGCall", "inap.nonCUGCall",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_oneTrigger,
{ "oneTrigger", "inap.oneTrigger",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_triggers,
{ "triggers", "inap.triggers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_triggerId,
{ "triggerId", "inap.triggerId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_triggerPar,
{ "triggerPar", "inap.triggerPar",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_triggerID,
{ "triggerID", "inap.triggerID",
FT_UINT32, BASE_DEC, VALS(inap_EventTypeBCSM_vals), 0,
"EventTypeBCSM", HFILL }},
{ &hf_inap_profile,
{ "profile", "inap.profile",
FT_UINT32, BASE_DEC, VALS(inap_ProfileIdentifier_vals), 0,
"ProfileIdentifier", HFILL }},
{ &hf_inap_TriggerResults_item,
{ "TriggerResult", "inap.TriggerResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tDPIdentifer,
{ "tDPIdentifer", "inap.tDPIdentifer",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_actionPerformed,
{ "actionPerformed", "inap.actionPerformed",
FT_UINT32, BASE_DEC, VALS(inap_ActionPerformed_vals), 0,
NULL, HFILL }},
{ &hf_inap_Triggers_item,
{ "Trigger", "inap.Trigger",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tDPIdentifier_01,
{ "tDPIdentifier", "inap.tDPIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_dpName,
{ "dpName", "inap.dpName",
FT_UINT32, BASE_DEC, VALS(inap_EventTypeBCSM_vals), 0,
"EventTypeBCSM", HFILL }},
{ &hf_inap_global,
{ "global", "inap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_inap_local,
{ "local", "inap.local",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_minUSIServiceIndicatorLength_maxUSIServiceIndicatorLength", HFILL }},
{ &hf_inap_filteredCallTreatment,
{ "filteredCallTreatment", "inap.filteredCallTreatment",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_filteringCharacteristics,
{ "filteringCharacteristics", "inap.filteringCharacteristics",
FT_UINT32, BASE_DEC, VALS(inap_FilteringCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_inap_filteringTimeOut,
{ "filteringTimeOut", "inap.filteringTimeOut",
FT_UINT32, BASE_DEC, VALS(inap_FilteringTimeOut_vals), 0,
NULL, HFILL }},
{ &hf_inap_filteringCriteria,
{ "filteringCriteria", "inap.filteringCriteria",
FT_UINT32, BASE_DEC, VALS(inap_FilteringCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_startTime,
{ "startTime", "inap.startTime",
FT_BYTES, BASE_NONE, NULL, 0,
"DateAndTime", HFILL }},
{ &hf_inap_dpSpecificCommonParameters,
{ "dpSpecificCommonParameters", "inap.dpSpecificCommonParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_dialledDigits,
{ "dialledDigits", "inap.dialledDigits",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyNumber", HFILL }},
{ &hf_inap_callingPartyBusinessGroupID,
{ "callingPartyBusinessGroupID", "inap.callingPartyBusinessGroupID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingPartySubaddress,
{ "callingPartySubaddress", "inap.callingPartySubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingFacilityGroup,
{ "callingFacilityGroup", "inap.callingFacilityGroup",
FT_UINT32, BASE_DEC, VALS(inap_FacilityGroup_vals), 0,
"FacilityGroup", HFILL }},
{ &hf_inap_callingFacilityGroupMember,
{ "callingFacilityGroupMember", "inap.callingFacilityGroupMember",
FT_INT32, BASE_DEC, NULL, 0,
"FacilityGroupMember", HFILL }},
{ &hf_inap_originalCalledPartyID,
{ "originalCalledPartyID", "inap.originalCalledPartyID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_prefix,
{ "prefix", "inap.prefix",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_redirectingPartyID,
{ "redirectingPartyID", "inap.redirectingPartyID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_redirectionInformation,
{ "redirectionInformation", "inap.redirectionInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_routeList,
{ "routeList", "inap.routeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_travellingClassMark,
{ "travellingClassMark", "inap.travellingClassMark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_featureCode,
{ "featureCode", "inap.featureCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_accessCode,
{ "accessCode", "inap.accessCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_carrier,
{ "carrier", "inap.carrier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_componentType,
{ "componentType", "inap.componentType",
FT_UINT32, BASE_DEC, VALS(inap_ComponentType_vals), 0,
NULL, HFILL }},
{ &hf_inap_component,
{ "component", "inap.component",
FT_UINT32, BASE_DEC, VALS(inap_Component_vals), 0,
NULL, HFILL }},
{ &hf_inap_componentCorrelationID,
{ "componentCorrelationID", "inap.componentCorrelationID",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_destinationRoutingAddress,
{ "destinationRoutingAddress", "inap.destinationRoutingAddress",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_alertingPattern,
{ "alertingPattern", "inap.alertingPattern",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_iNServiceCompatibilityResponse,
{ "iNServiceCompatibilityResponse", "inap.iNServiceCompatibilityResponse",
FT_UINT32, BASE_DEC, VALS(inap_Entry_vals), 0,
NULL, HFILL }},
{ &hf_inap_correlationID,
{ "correlationID", "inap.correlationID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callSegmentID,
{ "callSegmentID", "inap.callSegmentID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_legToBeCreated,
{ "legToBeCreated", "inap.legToBeCreated",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_aChBillingChargingCharacteristics,
{ "aChBillingChargingCharacteristics", "inap.aChBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_partyToCharge,
{ "partyToCharge", "inap.partyToCharge",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_releaseIndication,
{ "releaseIndication", "inap.releaseIndication",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_destinationNumberRoutingAddress,
{ "destinationNumberRoutingAddress", "inap.destinationNumberRoutingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"CalledPartyNumber", HFILL }},
{ &hf_inap_displayInformation,
{ "displayInformation", "inap.displayInformation",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_destinationIndex,
{ "destinationIndex", "inap.destinationIndex",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_gapIndicators,
{ "gapIndicators", "inap.gapIndicators",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_registratorIdentifier,
{ "registratorIdentifier", "inap.registratorIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_gapCriteria,
{ "gapCriteria", "inap.gapCriteria",
FT_UINT32, BASE_DEC, VALS(inap_GapCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_controlType,
{ "controlType", "inap.controlType",
FT_UINT32, BASE_DEC, VALS(inap_ControlType_vals), 0,
NULL, HFILL }},
{ &hf_inap_gapTreatment,
{ "gapTreatment", "inap.gapTreatment",
FT_UINT32, BASE_DEC, VALS(inap_GapTreatment_vals), 0,
NULL, HFILL }},
{ &hf_inap_requestedInformationList,
{ "requestedInformationList", "inap.requestedInformationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_lastEventIndicator,
{ "lastEventIndicator", "inap.lastEventIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_requestedInformationTypeList,
{ "requestedInformationTypeList", "inap.requestedInformationTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_invokeID,
{ "invokeID", "inap.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_allRequests,
{ "allRequests", "inap.allRequests",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callSegmentToCancel,
{ "callSegmentToCancel", "inap.callSegmentToCancel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_allRequestsForCallSegment,
{ "allRequestsForCallSegment", "inap.allRequestsForCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_inap_resourceID,
{ "resourceID", "inap.resourceID",
FT_UINT32, BASE_DEC, VALS(inap_ResourceID_vals), 0,
NULL, HFILL }},
{ &hf_inap_numberingPlan,
{ "numberingPlan", "inap.numberingPlan",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cutAndPaste,
{ "cutAndPaste", "inap.cutAndPaste",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_forwardingCondition,
{ "forwardingCondition", "inap.forwardingCondition",
FT_UINT32, BASE_DEC, VALS(inap_ForwardingCondition_vals), 0,
NULL, HFILL }},
{ &hf_inap_forwardCallIndicators,
{ "forwardCallIndicators", "inap.forwardCallIndicators",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_genericNumbers,
{ "genericNumbers", "inap.genericNumbers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_sDSSinformation,
{ "sDSSinformation", "inap.sDSSinformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_calledDirectoryNumber,
{ "calledDirectoryNumber", "inap.calledDirectoryNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_calledPartySubaddress,
{ "calledPartySubaddress", "inap.calledPartySubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_connectionIdentifier,
{ "connectionIdentifier", "inap.connectionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_genericIdentifier,
{ "genericIdentifier", "inap.genericIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_qOSParameter,
{ "qOSParameter", "inap.qOSParameter",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bISDNParameters,
{ "bISDNParameters", "inap.bISDNParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cug_Interlock,
{ "cug-Interlock", "inap.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cug_OutgoingAccess,
{ "cug-OutgoingAccess", "inap.cug_OutgoingAccess",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_resourceAddress,
{ "resourceAddress", "inap.resourceAddress",
FT_UINT32, BASE_DEC, VALS(inap_T_resourceAddress_vals), 0,
NULL, HFILL }},
{ &hf_inap_ipRoutingAddress,
{ "ipRoutingAddress", "inap.ipRoutingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ipAddressAndLegID,
{ "ipAddressAndLegID", "inap.ipAddressAndLegID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_none,
{ "none", "inap.none",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ipAddressAndCallSegment,
{ "ipAddressAndCallSegment", "inap.ipAddressAndCallSegment",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_legorCSID,
{ "legorCSID", "inap.legorCSID",
FT_UINT32, BASE_DEC, VALS(inap_T_legorCSID_vals), 0,
NULL, HFILL }},
{ &hf_inap_csID,
{ "csID", "inap.csID",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_inap_genericName,
{ "genericName", "inap.genericName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_ipRelationInformation,
{ "ipRelationInformation", "inap.ipRelationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"IPRelatedInformation", HFILL }},
{ &hf_inap_newCallSegmentAssociation,
{ "newCallSegmentAssociation", "inap.newCallSegmentAssociation",
FT_UINT32, BASE_DEC, NULL, 0,
"CSAID", HFILL }},
{ &hf_inap_createOrRemove,
{ "createOrRemove", "inap.createOrRemove",
FT_UINT32, BASE_DEC, VALS(inap_CreateOrRemoveIndicator_vals), 0,
"CreateOrRemoveIndicator", HFILL }},
{ &hf_inap_triggerDPType,
{ "triggerDPType", "inap.triggerDPType",
FT_UINT32, BASE_DEC, VALS(inap_TriggerDPType_vals), 0,
NULL, HFILL }},
{ &hf_inap_triggerData,
{ "triggerData", "inap.triggerData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_defaultFaultHandling,
{ "defaultFaultHandling", "inap.defaultFaultHandling",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_triggerStatus,
{ "triggerStatus", "inap.triggerStatus",
FT_UINT32, BASE_DEC, VALS(inap_TriggerStatus_vals), 0,
NULL, HFILL }},
{ &hf_inap_partyToDisconnect,
{ "partyToDisconnect", "inap.partyToDisconnect",
FT_UINT32, BASE_DEC, VALS(inap_T_partyToDisconnect_vals), 0,
NULL, HFILL }},
{ &hf_inap_legToBeReleased,
{ "legToBeReleased", "inap.legToBeReleased",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_cSFailure,
{ "cSFailure", "inap.cSFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_reason,
{ "reason", "inap.reason",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bCSMFailure,
{ "bCSMFailure", "inap.bCSMFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_assistingSSPIPRoutingAddress,
{ "assistingSSPIPRoutingAddress", "inap.assistingSSPIPRoutingAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_partyToConnect,
{ "partyToConnect", "inap.partyToConnect",
FT_UINT32, BASE_DEC, VALS(inap_T_partyToConnect_vals), 0,
NULL, HFILL }},
{ &hf_inap_eventSpecificInformationCharging,
{ "eventSpecificInformationCharging", "inap.eventSpecificInformationCharging",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bcsmEventCorrelationID,
{ "bcsmEventCorrelationID", "inap.bcsmEventCorrelationID",
FT_BYTES, BASE_NONE, NULL, 0,
"CorrelationID", HFILL }},
{ &hf_inap_eventSpecificInformationBCSM,
{ "eventSpecificInformationBCSM", "inap.eventSpecificInformationBCSM",
FT_UINT32, BASE_DEC, VALS(inap_EventSpecificInformationBCSM_vals), 0,
NULL, HFILL }},
{ &hf_inap_calledPartyBusinessGroupID,
{ "calledPartyBusinessGroupID", "inap.calledPartyBusinessGroupID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_holdcause,
{ "holdcause", "inap.holdcause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_empty,
{ "empty", "inap.empty",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_highLayerCompatibility,
{ "highLayerCompatibility", "inap.highLayerCompatibility",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_additionalCallingPartyNumber,
{ "additionalCallingPartyNumber", "inap.additionalCallingPartyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cCSS,
{ "cCSS", "inap.cCSS",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_vPNIndicator,
{ "vPNIndicator", "inap.vPNIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cNInfo,
{ "cNInfo", "inap.cNInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callReference,
{ "callReference", "inap.callReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_routeingNumber,
{ "routeingNumber", "inap.routeingNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callingGeodeticLocation,
{ "callingGeodeticLocation", "inap.callingGeodeticLocation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_globalCallReference,
{ "globalCallReference", "inap.globalCallReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_cug_Index,
{ "cug-Index", "inap.cug_Index",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_newCallSegment,
{ "newCallSegment", "inap.newCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_inap_incomingSignallingBufferCopy,
{ "incomingSignallingBufferCopy", "inap.incomingSignallingBufferCopy",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_actionIndicator,
{ "actionIndicator", "inap.actionIndicator",
FT_UINT32, BASE_DEC, VALS(inap_ActionIndicator_vals), 0,
NULL, HFILL }},
{ &hf_inap_triggerDataIdentifier,
{ "triggerDataIdentifier", "inap.triggerDataIdentifier",
FT_UINT32, BASE_DEC, VALS(inap_T_triggerDataIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_inap_profileAndDP,
{ "profileAndDP", "inap.profileAndDP",
FT_NONE, BASE_NONE, NULL, 0,
"TriggerDataIdentifier", HFILL }},
{ &hf_inap_oneTriggerResult,
{ "oneTriggerResult", "inap.oneTriggerResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_severalTriggerResult,
{ "severalTriggerResult", "inap.severalTriggerResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_results,
{ "results", "inap.results",
FT_UINT32, BASE_DEC, NULL, 0,
"TriggerResults", HFILL }},
{ &hf_inap_sourceCallSegment,
{ "sourceCallSegment", "inap.sourceCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_inap_targetCallSegment,
{ "targetCallSegment", "inap.targetCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"CallSegmentID", HFILL }},
{ &hf_inap_mergeSignallingPaths,
{ "mergeSignallingPaths", "inap.mergeSignallingPaths",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_routeCounters,
{ "routeCounters", "inap.routeCounters",
FT_UINT32, BASE_DEC, NULL, 0,
"RouteCountersValue", HFILL }},
{ &hf_inap_monitoringCriteria,
{ "monitoringCriteria", "inap.monitoringCriteria",
FT_UINT32, BASE_DEC, VALS(inap_MonitoringCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_monitoringTimeout,
{ "monitoringTimeout", "inap.monitoringTimeout",
FT_UINT32, BASE_DEC, VALS(inap_MonitoringTimeOut_vals), 0,
NULL, HFILL }},
{ &hf_inap_targetCallSegmentAssociation,
{ "targetCallSegmentAssociation", "inap.targetCallSegmentAssociation",
FT_UINT32, BASE_DEC, NULL, 0,
"CSAID", HFILL }},
{ &hf_inap_callSegments,
{ "callSegments", "inap.callSegments",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callSegments_item,
{ "callSegments item", "inap.callSegments_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_legs,
{ "legs", "inap.legs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_legs_item,
{ "legs item", "inap.legs_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_sourceLeg,
{ "sourceLeg", "inap.sourceLeg",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_newLeg,
{ "newLeg", "inap.newLeg",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_legIDToMove,
{ "legIDToMove", "inap.legIDToMove",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_detachSignallingPath,
{ "detachSignallingPath", "inap.detachSignallingPath",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_exportSignallingPath,
{ "exportSignallingPath", "inap.exportSignallingPath",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_featureRequestIndicator,
{ "featureRequestIndicator", "inap.featureRequestIndicator",
FT_UINT32, BASE_DEC, VALS(inap_FeatureRequestIndicator_vals), 0,
NULL, HFILL }},
{ &hf_inap_componenttCorrelationID,
{ "componenttCorrelationID", "inap.componenttCorrelationID",
FT_INT32, BASE_DEC, NULL, 0,
"ComponentCorrelationID", HFILL }},
{ &hf_inap_notificationDuration,
{ "notificationDuration", "inap.notificationDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"ApplicationTimer", HFILL }},
{ &hf_inap_initialCallSegment,
{ "initialCallSegment", "inap.initialCallSegment",
FT_BYTES, BASE_NONE, NULL, 0,
"Cause", HFILL }},
{ &hf_inap_callSegmentToRelease,
{ "callSegmentToRelease", "inap.callSegmentToRelease",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_callSegment,
{ "callSegment", "inap.callSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_numOfCSs", HFILL }},
{ &hf_inap_forcedRelease,
{ "forcedRelease", "inap.forcedRelease",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_allCallSegments,
{ "allCallSegments", "inap.allCallSegments",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_timeToRelease,
{ "timeToRelease", "inap.timeToRelease",
FT_UINT32, BASE_DEC, NULL, 0,
"TimerValue", HFILL }},
{ &hf_inap_resourceStatus,
{ "resourceStatus", "inap.resourceStatus",
FT_UINT32, BASE_DEC, VALS(inap_ResourceStatus_vals), 0,
NULL, HFILL }},
{ &hf_inap_monitorDuration,
{ "monitorDuration", "inap.monitorDuration",
FT_INT32, BASE_DEC, NULL, 0,
"Duration", HFILL }},
{ &hf_inap_RequestNotificationChargingEventArg_item,
{ "ChargingEvent", "inap.ChargingEvent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_bcsmEvents,
{ "bcsmEvents", "inap.bcsmEvents",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_numOfBCSMEvents_OF_BCSMEvent", HFILL }},
{ &hf_inap_bcsmEvents_item,
{ "BCSMEvent", "inap.BCSMEvent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_componentTypes,
{ "componentTypes", "inap.componentTypes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_3_OF_ComponentType", HFILL }},
{ &hf_inap_componentTypes_item,
{ "ComponentType", "inap.ComponentType",
FT_UINT32, BASE_DEC, VALS(inap_ComponentType_vals), 0,
NULL, HFILL }},
{ &hf_inap_requestedUTSIList,
{ "requestedUTSIList", "inap.requestedUTSIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_timerID,
{ "timerID", "inap.timerID",
FT_UINT32, BASE_DEC, VALS(inap_TimerID_vals), 0,
NULL, HFILL }},
{ &hf_inap_timervalue,
{ "timervalue", "inap.timervalue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_calledFacilityGroup,
{ "calledFacilityGroup", "inap.calledFacilityGroup",
FT_UINT32, BASE_DEC, VALS(inap_FacilityGroup_vals), 0,
"FacilityGroup", HFILL }},
{ &hf_inap_calledFacilityGroupMember,
{ "calledFacilityGroupMember", "inap.calledFacilityGroupMember",
FT_INT32, BASE_DEC, NULL, 0,
"FacilityGroupMember", HFILL }},
{ &hf_inap_sCIBillingChargingCharacteristics,
{ "sCIBillingChargingCharacteristics", "inap.sCIBillingChargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_nocharge,
{ "nocharge", "inap.nocharge",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_callProcessingOperation,
{ "callProcessingOperation", "inap.callProcessingOperation",
FT_UINT32, BASE_DEC, VALS(inap_CallProcessingOperation_vals), 0,
NULL, HFILL }},
{ &hf_inap_countersValue,
{ "countersValue", "inap.countersValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_responseCondition,
{ "responseCondition", "inap.responseCondition",
FT_UINT32, BASE_DEC, VALS(inap_ResponseCondition_vals), 0,
NULL, HFILL }},
{ &hf_inap_iNprofiles,
{ "iNprofiles", "inap.iNprofiles",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_numOfINProfile_OF_INprofile", HFILL }},
{ &hf_inap_iNprofiles_item,
{ "INprofile", "inap.INprofile",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_legToBeSplit,
{ "legToBeSplit", "inap.legToBeSplit",
FT_UINT32, BASE_DEC, VALS(inap_LegID_vals), 0,
"LegID", HFILL }},
{ &hf_inap_newCallSegment_01,
{ "newCallSegment", "inap.newCallSegment",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_numOfCSs", HFILL }},
{ &hf_inap_reportCondition,
{ "reportCondition", "inap.reportCondition",
FT_UINT32, BASE_DEC, VALS(inap_ReportCondition_vals), 0,
NULL, HFILL }},
{ &hf_inap_minimumNbOfDigits,
{ "minimumNbOfDigits", "inap.minimumNbOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_inap_maximumNbOfDigits,
{ "maximumNbOfDigits", "inap.maximumNbOfDigits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_inap_endOfReplyDigit,
{ "endOfReplyDigit", "inap.endOfReplyDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_cancelDigit,
{ "cancelDigit", "inap.cancelDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_startDigit,
{ "startDigit", "inap.startDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_firstDigitTimeOut,
{ "firstDigitTimeOut", "inap.firstDigitTimeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_inap_interDigitTimeOut,
{ "interDigitTimeOut", "inap.interDigitTimeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_inap_errorTreatment,
{ "errorTreatment", "inap.errorTreatment",
FT_UINT32, BASE_DEC, VALS(inap_ErrorTreatment_vals), 0,
NULL, HFILL }},
{ &hf_inap_interruptableAnnInd,
{ "interruptableAnnInd", "inap.interruptableAnnInd",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_voiceInformation,
{ "voiceInformation", "inap.voiceInformation",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_voiceBack,
{ "voiceBack", "inap.voiceBack",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_detectModem,
{ "detectModem", "inap.detectModem",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_collectedDigits,
{ "collectedDigits", "inap.collectedDigits",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_iA5Information,
{ "iA5Information", "inap.iA5Information",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_messageID,
{ "messageID", "inap.messageID",
FT_UINT32, BASE_DEC, VALS(inap_MessageID_vals), 0,
NULL, HFILL }},
{ &hf_inap_numberOfRepetitions,
{ "numberOfRepetitions", "inap.numberOfRepetitions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_inap_duration_01,
{ "duration", "inap.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_inap_interval_02,
{ "interval", "inap.interval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_inap_preferredLanguage,
{ "preferredLanguage", "inap.preferredLanguage",
FT_STRING, BASE_NONE, NULL, 0,
"Language", HFILL }},
{ &hf_inap_messageID_01,
{ "messageID", "inap.messageID",
FT_UINT32, BASE_DEC, NULL, 0,
"ElementaryMessageID", HFILL }},
{ &hf_inap_messageDeletionTimeOut,
{ "messageDeletionTimeOut", "inap.messageDeletionTimeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_3600", HFILL }},
{ &hf_inap_timeToRecord,
{ "timeToRecord", "inap.timeToRecord",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_b3__maxRecordingTime", HFILL }},
{ &hf_inap_controlDigits,
{ "controlDigits", "inap.controlDigits",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_endOfRecordingDigit,
{ "endOfRecordingDigit", "inap.endOfRecordingDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_replayDigit,
{ "replayDigit", "inap.replayDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_restartRecordingDigit,
{ "restartRecordingDigit", "inap.restartRecordingDigit",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_2", HFILL }},
{ &hf_inap_restartAllowed,
{ "restartAllowed", "inap.restartAllowed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_replayAllowed,
{ "replayAllowed", "inap.replayAllowed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_inbandInfo,
{ "inbandInfo", "inap.inbandInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tone,
{ "tone", "inap.tone",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_elementaryMessageID,
{ "elementaryMessageID", "inap.elementaryMessageID",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_text,
{ "text", "inap.text",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_messageContent,
{ "messageContent", "inap.messageContent",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_b3__minMessageContentLength_b3__maxMessageContentLength", HFILL }},
{ &hf_inap_attributes,
{ "attributes", "inap.attributes",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_b3__minAttributesLength_b3__maxAttributesLength", HFILL }},
{ &hf_inap_elementaryMessageIDs,
{ "elementaryMessageIDs", "inap.elementaryMessageIDs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_b3__numOfMessageIDs_OF_Integer4", HFILL }},
{ &hf_inap_elementaryMessageIDs_item,
{ "Integer4", "inap.Integer4",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_variableMessage,
{ "variableMessage", "inap.variableMessage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_variableParts,
{ "variableParts", "inap.variableParts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_b3__maxVariableParts_OF_VariablePart", HFILL }},
{ &hf_inap_variableParts_item,
{ "VariablePart", "inap.VariablePart",
FT_UINT32, BASE_DEC, VALS(inap_VariablePart_vals), 0,
NULL, HFILL }},
{ &hf_inap_iPAddressValue,
{ "iPAddressValue", "inap.iPAddressValue",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_gapOnResource,
{ "gapOnResource", "inap.gapOnResource",
FT_UINT32, BASE_DEC, VALS(inap_Code_vals), 0,
NULL, HFILL }},
{ &hf_inap_iPAddressAndresource,
{ "iPAddressAndresource", "inap.iPAddressAndresource",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_toneID,
{ "toneID", "inap.toneID",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_duration_02,
{ "duration", "inap.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_integer,
{ "integer", "inap.integer",
FT_UINT32, BASE_DEC, NULL, 0,
"Integer4", HFILL }},
{ &hf_inap_number,
{ "number", "inap.number",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_time,
{ "time", "inap.time",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_inap_date,
{ "date", "inap.date",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_inap_price,
{ "price", "inap.price",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_inap_disconnectFromIPForbidden,
{ "disconnectFromIPForbidden", "inap.disconnectFromIPForbidden",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_requestAnnouncementComplete,
{ "requestAnnouncementComplete", "inap.requestAnnouncementComplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_connectedParty,
{ "connectedParty", "inap.connectedParty",
FT_UINT32, BASE_DEC, VALS(inap_T_connectedParty_vals), 0,
NULL, HFILL }},
{ &hf_inap_collectedInfo,
{ "collectedInfo", "inap.collectedInfo",
FT_UINT32, BASE_DEC, VALS(inap_CollectedInfo_vals), 0,
NULL, HFILL }},
{ &hf_inap_digitsResponse,
{ "digitsResponse", "inap.digitsResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_inap_iA5Response,
{ "iA5Response", "inap.iA5Response",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_inap_modemdetected,
{ "modemdetected", "inap.modemdetected",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_inap_subscriberID,
{ "subscriberID", "inap.subscriberID",
FT_BYTES, BASE_NONE, NULL, 0,
"GenericNumber", HFILL }},
{ &hf_inap_mailBoxID,
{ "mailBoxID", "inap.mailBoxID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_informationToRecord,
{ "informationToRecord", "inap.informationToRecord",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_media,
{ "media", "inap.media",
FT_UINT32, BASE_DEC, VALS(inap_Media_vals), 0,
NULL, HFILL }},
{ &hf_inap_receivedStatus,
{ "receivedStatus", "inap.receivedStatus",
FT_UINT32, BASE_DEC, VALS(inap_ReceivedStatus_vals), 0,
NULL, HFILL }},
{ &hf_inap_recordedMessageID,
{ "recordedMessageID", "inap.recordedMessageID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_recordedMessageUnits,
{ "recordedMessageUnits", "inap.recordedMessageUnits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_b3__maxRecordedMessageUnits", HFILL }},
{ &hf_inap_uIScriptId,
{ "uIScriptId", "inap.uIScriptId",
FT_UINT32, BASE_DEC, VALS(inap_Code_vals), 0,
"Code", HFILL }},
{ &hf_inap_uIScriptSpecificInfo,
{ "uIScriptSpecificInfo", "inap.uIScriptSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_uIScriptResult,
{ "uIScriptResult", "inap.uIScriptResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_uIScriptSpecificInfo_01,
{ "uIScriptSpecificInfo", "inap.uIScriptSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
"T_uIScriptSpecificInfo_01", HFILL }},
{ &hf_inap_uIScriptSpecificInfo_02,
{ "uIScriptSpecificInfo", "inap.uIScriptSpecificInfo",
FT_NONE, BASE_NONE, NULL, 0,
"T_uIScriptSpecificInfo_02", HFILL }},
{ &hf_inap_sRFgapCriteria,
{ "sRFgapCriteria", "inap.sRFgapCriteria",
FT_UINT32, BASE_DEC, VALS(inap_SRFGapCriteria_vals), 0,
NULL, HFILL }},
{ &hf_inap_problem,
{ "problem", "inap.problem",
FT_UINT32, BASE_DEC, VALS(inap_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_inap_operation,
{ "operation", "inap.operation",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeID", HFILL }},
{ &hf_inap_reason_01,
{ "reason", "inap.reason",
FT_UINT32, BASE_DEC, VALS(inap_T_reason_vals), 0,
NULL, HFILL }},
{ &hf_inap_securityParameters,
{ "securityParameters", "inap.securityParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_tryhere,
{ "tryhere", "inap.tryhere",
FT_NONE, BASE_NONE, NULL, 0,
"AccessPointInformation", HFILL }},
{ &hf_inap_local_01,
{ "local", "inap.local",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_inap_global_01,
{ "global", "inap.global",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_invoke,
{ "invoke", "inap.invoke",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_returnResult,
{ "returnResult", "inap.returnResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_returnError,
{ "returnError", "inap.returnError",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_reject,
{ "reject", "inap.reject",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_invokeId,
{ "invokeId", "inap.invokeId",
FT_UINT32, BASE_DEC, VALS(inap_InvokeId_vals), 0,
NULL, HFILL }},
{ &hf_inap_linkedId,
{ "linkedId", "inap.linkedId",
FT_UINT32, BASE_DEC, VALS(inap_T_linkedId_vals), 0,
NULL, HFILL }},
{ &hf_inap_linkedIdPresent,
{ "present", "inap.present",
FT_INT32, BASE_DEC, NULL, 0,
"T_linkedIdPresent", HFILL }},
{ &hf_inap_absent,
{ "absent", "inap.absent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_opcode,
{ "opcode", "inap.opcode",
FT_UINT32, BASE_DEC, VALS(inap_Code_vals), 0,
"Code", HFILL }},
{ &hf_inap_argument,
{ "argument", "inap.argument",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_result,
{ "result", "inap.result",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_resultArgument,
{ "result", "inap.result",
FT_NONE, BASE_NONE, NULL, 0,
"ResultArgument", HFILL }},
{ &hf_inap_errcode,
{ "errcode", "inap.errcode",
FT_UINT32, BASE_DEC, VALS(inap_Code_vals), 0,
"Code", HFILL }},
{ &hf_inap_parameter,
{ "parameter", "inap.parameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_inap_problem_01,
{ "problem", "inap.problem",
FT_UINT32, BASE_DEC, VALS(inap_T_problem_01_vals), 0,
"T_problem_01", HFILL }},
{ &hf_inap_general,
{ "general", "inap.general",
FT_INT32, BASE_DEC, VALS(inap_GeneralProblem_vals), 0,
"GeneralProblem", HFILL }},
{ &hf_inap_invokeProblem,
{ "invoke", "inap.invoke",
FT_INT32, BASE_DEC, VALS(inap_InvokeProblem_vals), 0,
"InvokeProblem", HFILL }},
{ &hf_inap_problemReturnResult,
{ "returnResult", "inap.returnResult",
FT_INT32, BASE_DEC, VALS(inap_ReturnResultProblem_vals), 0,
"ReturnResultProblem", HFILL }},
{ &hf_inap_returnErrorProblem,
{ "returnError", "inap.returnError",
FT_INT32, BASE_DEC, VALS(inap_ReturnErrorProblem_vals), 0,
"ReturnErrorProblem", HFILL }},
{ &hf_inap_present,
{ "present", "inap.present",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_inap_InvokeId_present,
{ "InvokeId.present", "inap.InvokeId_present",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeId_present", HFILL }},
#line 198 "../../asn1/inap/packet-inap-template.c"
};
static gint *ett[] = {
&ett_inap,
&ett_inapisup_parameter,
&ett_inap_HighLayerCompatibility,
#line 1 "../../asn1/inap/packet-inap-ettarr.c"
&ett_inap_Extensions,
&ett_inap_ExtensionField,
&ett_inap_AlternativeIdentities,
&ett_inap_AlternativeIdentity,
&ett_inap_BackwardServiceInteractionInd,
&ett_inap_BasicGapCriteria,
&ett_inap_T_calledAddressAndService,
&ett_inap_T_callingAddressAndService,
&ett_inap_BCSMEvent,
&ett_inap_BearerCapability,
&ett_inap_BISDNParameters,
&ett_inap_ChargingEvent,
&ett_inap_Component,
&ett_inap_CompoundCriteria,
&ett_inap_CounterAndValue,
&ett_inap_CountersValue,
&ett_inap_DefaultFaultHandling,
&ett_inap_DestinationRoutingAddress,
&ett_inap_DpSpecificCommonParameters,
&ett_inap_DpSpecificCriteria,
&ett_inap_T_numberOfDigitsTwo,
&ett_inap_Entry,
&ett_inap_EventSpecificInformationBCSM,
&ett_inap_T_collectedInfoSpecificInfo,
&ett_inap_T_analysedInfoSpecificInfo,
&ett_inap_T_routeSelectFailureSpecificInfo,
&ett_inap_T_oCalledPartyBusySpecificInfo,
&ett_inap_T_oNoAnswerSpecificInfo,
&ett_inap_T_oAnswerSpecificInfo,
&ett_inap_T_oMidCallSpecificInfo,
&ett_inap_T_oDisconnectSpecificInfo,
&ett_inap_T_tBusySpecificInfo,
&ett_inap_T_tNoAnswerSpecificInfo,
&ett_inap_T_tAnswerSpecificInfo,
&ett_inap_T_tMidCallSpecificInfo,
&ett_inap_T_tDisconnectSpecificInfo,
&ett_inap_T_oTermSeizedSpecificInfo,
&ett_inap_T_oSuspend,
&ett_inap_T_tSuspend,
&ett_inap_T_origAttemptAuthorized,
&ett_inap_T_oReAnswer,
&ett_inap_T_tReAnswer,
&ett_inap_T_facilitySelectedAndAvailable,
&ett_inap_T_callAccepted,
&ett_inap_T_oAbandon,
&ett_inap_T_tAbandon,
&ett_inap_T_authorizeRouteFailure,
&ett_inap_T_terminationAttemptAuthorized,
&ett_inap_T_originationAttemptDenied,
&ett_inap_T_terminationAttemptDenied,
&ett_inap_T_oModifyRequestSpecificInfo,
&ett_inap_T_oModifyResultSpecificInfo,
&ett_inap_T_tModifyRequestSpecificInfo,
&ett_inap_T_tModifyResultSpecificInfo,
&ett_inap_FacilityGroup,
&ett_inap_FilteredCallTreatment,
&ett_inap_FilteringCharacteristics,
&ett_inap_FilteringCriteria,
&ett_inap_T_addressAndService,
&ett_inap_FilteringTimeOut,
&ett_inap_ForwardServiceInteractionInd,
&ett_inap_GapCriteria,
&ett_inap_GapOnService,
&ett_inap_GapIndicators,
&ett_inap_GapTreatment,
&ett_inap_T_both,
&ett_inap_GenericNumbers,
&ett_inap_INprofile,
&ett_inap_INServiceCompatibilityIndication,
&ett_inap_IPRelatedInformation,
&ett_inap_LegID,
&ett_inap_MidCallControlInfo,
&ett_inap_MidCallControlInfo_item,
&ett_inap_MidCallInfo,
&ett_inap_MidCallInfoType,
&ett_inap_MiscCallInfo,
&ett_inap_MonitoringCriteria,
&ett_inap_MonitoringTimeOut,
&ett_inap_ProfileIdentifier,
&ett_inap_RequestedInformationList,
&ett_inap_RequestedInformationTypeList,
&ett_inap_RequestedInformation,
&ett_inap_RequestedInformationValue,
&ett_inap_RequestedUTSI,
&ett_inap_RequestedUTSIList,
&ett_inap_ResourceID,
&ett_inap_RouteCountersValue,
&ett_inap_RouteCountersAndValue,
&ett_inap_RouteList,
&ett_inap_ServiceAddressInformation,
&ett_inap_ServiceInteractionIndicatorsTwo,
&ett_inap_T_redirectServiceTreatmentInd,
&ett_inap_TDPIdentifier,
&ett_inap_TriggerData,
&ett_inap_TriggerDataIdentifier,
&ett_inap_TriggerResults,
&ett_inap_TriggerResult,
&ett_inap_Triggers,
&ett_inap_Trigger,
&ett_inap_USIServiceIndicator,
&ett_inap_ActivateServiceFilteringArg,
&ett_inap_AnalysedInformationArg,
&ett_inap_AnalyseInformationArg,
&ett_inap_ApplyChargingArg,
&ett_inap_AssistRequestInstructionsArg,
&ett_inap_AuthorizeTerminationArg,
&ett_inap_CallFilteringArg,
&ett_inap_CallGapArg,
&ett_inap_CallInformationReportArg,
&ett_inap_CallInformationRequestArg,
&ett_inap_CancelArg,
&ett_inap_T_callSegmentToCancel,
&ett_inap_CancelStatusReportRequestArg,
&ett_inap_CollectedInformationArg,
&ett_inap_CollectInformationArg,
&ett_inap_ConnectArg,
&ett_inap_ConnectToResourceArg,
&ett_inap_T_resourceAddress,
&ett_inap_T_ipAddressAndLegID,
&ett_inap_T_ipAddressAndCallSegment,
&ett_inap_ContinueWithArgumentArg,
&ett_inap_T_legorCSID,
&ett_inap_CreateCallSegmentAssociationArg,
&ett_inap_CreateCallSegmentAssociationResultArg,
&ett_inap_CreateOrRemoveTriggerDataArg,
&ett_inap_CreateOrRemoveTriggerDataResultArg,
&ett_inap_DisconnectForwardConnectionWithArgumentArg,
&ett_inap_T_partyToDisconnect,
&ett_inap_DisconnectLegArg,
&ett_inap_EntityReleasedArg,
&ett_inap_T_cSFailure,
&ett_inap_T_bCSMFailure,
&ett_inap_EstablishTemporaryConnectionArg,
&ett_inap_T_partyToConnect,
&ett_inap_EventNotificationChargingArg,
&ett_inap_EventReportBCSMArg,
&ett_inap_EventReportFacilityArg,
&ett_inap_FacilitySelectedAndAvailableArg,
&ett_inap_HoldCallInNetworkArg,
&ett_inap_InitialDPArg,
&ett_inap_InitiateCallAttemptArg,
&ett_inap_ManageTriggerDataArg,
&ett_inap_T_triggerDataIdentifier,
&ett_inap_ManageTriggerDataResultArg,
&ett_inap_T_oneTriggerResult,
&ett_inap_T_severalTriggerResult,
&ett_inap_MergeCallSegmentsArg,
&ett_inap_MonitorRouteReportArg,
&ett_inap_MonitorRouteRequestArg,
&ett_inap_MoveCallSegmentsArg,
&ett_inap_T_callSegments,
&ett_inap_T_callSegments_item,
&ett_inap_T_legs,
&ett_inap_T_legs_item,
&ett_inap_MoveLegArg,
&ett_inap_OAbandonArg,
&ett_inap_OAnswerArg,
&ett_inap_OCalledPartyBusyArg,
&ett_inap_ODisconnectArg,
&ett_inap_MidCallArg,
&ett_inap_ONoAnswerArg,
&ett_inap_OriginationAttemptArg,
&ett_inap_OriginationAttemptAuthorizedArg,
&ett_inap_OSuspendedArg,
&ett_inap_ReconnectArg,
&ett_inap_ReleaseCallArg,
&ett_inap_T_callSegmentToRelease,
&ett_inap_T_allCallSegments,
&ett_inap_ReportUTSIArg,
&ett_inap_RequestCurrentStatusReportResultArg,
&ett_inap_RequestEveryStatusChangeReportArg,
&ett_inap_RequestFirstStatusMatchReportArg,
&ett_inap_RequestNotificationChargingEventArg,
&ett_inap_RequestReportBCSMEventArg,
&ett_inap_SEQUENCE_SIZE_1_numOfBCSMEvents_OF_BCSMEvent,
&ett_inap_RequestReportFacilityEventArg,
&ett_inap_SEQUENCE_SIZE_1_3_OF_ComponentType,
&ett_inap_RequestReportUTSIArg,
&ett_inap_ResetTimerArg,
&ett_inap_RouteSelectFailureArg,
&ett_inap_SelectFacilityArg,
&ett_inap_SelectRouteArg,
&ett_inap_SendChargingInformationArg,
&ett_inap_SendFacilityInformationArg,
&ett_inap_SendSTUIArg,
&ett_inap_ServiceFilteringResponseArg,
&ett_inap_SetServiceProfileArg,
&ett_inap_SEQUENCE_SIZE_1_numOfINProfile_OF_INprofile,
&ett_inap_SplitLegArg,
&ett_inap_StatusReportArg,
&ett_inap_TAnswerArg,
&ett_inap_TBusyArg,
&ett_inap_TDisconnectArg,
&ett_inap_TermAttemptAuthorizedArg,
&ett_inap_TerminationAttemptArg,
&ett_inap_TNoAnswerArg,
&ett_inap_TSuspendedArg,
&ett_inap_CollectedDigits,
&ett_inap_CollectedInfo,
&ett_inap_InbandInfo,
&ett_inap_InformationToRecord,
&ett_inap_T_controlDigits,
&ett_inap_InformationToSend,
&ett_inap_MessageID,
&ett_inap_T_text,
&ett_inap_SEQUENCE_SIZE_1_b3__numOfMessageIDs_OF_Integer4,
&ett_inap_T_variableMessage,
&ett_inap_SEQUENCE_SIZE_1_b3__maxVariableParts_OF_VariablePart,
&ett_inap_SRFGapCriteria,
&ett_inap_T_iPAddressAndresource,
&ett_inap_Tone,
&ett_inap_VariablePart,
&ett_inap_PlayAnnouncementArg,
&ett_inap_T_connectedParty,
&ett_inap_PromptAndCollectUserInformationArg,
&ett_inap_ReceivedInformationArg,
&ett_inap_PromptAndReceiveMessageArg,
&ett_inap_MessageReceivedArg,
&ett_inap_ScriptCloseArg,
&ett_inap_ScriptEventArg,
&ett_inap_ScriptInformationArg,
&ett_inap_ScriptRunArg,
&ett_inap_SRFCallGapArg,
&ett_inap_PAR_cancelFailed,
&ett_inap_ScfTaskRefusedParameter,
&ett_inap_ReferralParameter,
&ett_inap_Code,
&ett_inap_ROS,
&ett_inap_Invoke,
&ett_inap_T_linkedId,
&ett_inap_ReturnResult,
&ett_inap_T_result,
&ett_inap_ReturnError,
&ett_inap_Reject,
&ett_inap_T_problem_01,
&ett_inap_InvokeId,
#line 211 "../../asn1/inap/packet-inap-template.c"
};
proto_inap = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("inap", dissect_inap, proto_inap);
proto_register_field_array(proto_inap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
range_convert_str(&global_ssn_range, "106,241", MAX_SSN);
inap_module = prefs_register_protocol(proto_inap, proto_reg_handoff_inap);
prefs_register_obsolete_preference(inap_module, "tcap.itu_ssn");
prefs_register_obsolete_preference(inap_module, "tcap.itu_ssn1");
prefs_register_range_preference(inap_module, "ssn", "TCAP SSNs",
"TCAP Subsystem numbers used for INAP",
&global_ssn_range, MAX_SSN);
}
