static int
dissect_rrlp_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rrlp_T_extType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rrlp_PrivateExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PrivateExtension, PrivateExtension_sequence);
return offset;
}
static int
dissect_rrlp_PrivateExtensionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_PrivateExtensionList, PrivateExtensionList_sequence_of,
1, maxNumOfPrivateExtensions, FALSE);
return offset;
}
static int
dissect_rrlp_PCS_Extensions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PCS_Extensions, PCS_Extensions_sequence);
return offset;
}
static int
dissect_rrlp_ExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ExtensionContainer, ExtensionContainer_sequence);
return offset;
}
static int
dissect_rrlp_Ext_GeographicalInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 33 "./asn1/rrlp/rrlp.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxExt_GeographicalInformation, FALSE, &parameter_tvb);
if(parameter_tvb)
dissect_geographical_description(parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_rrlp_VelocityEstimate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 7, FALSE, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Accuracy(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AccuracyOpt(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AccuracyOpt, AccuracyOpt_sequence);
return offset;
}
static int
dissect_rrlp_MethodType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_MethodType, MethodType_choice,
NULL);
return offset;
}
static int
dissect_rrlp_PositionMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_MeasureResponseTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_UseMultipleSets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_EnvironmentCharacter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rrlp_PositionInstruct(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PositionInstruct, PositionInstruct_sequence);
return offset;
}
static int
dissect_rrlp_BCCHCarrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_BSIC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TimeSlotScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_BTSPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_rrlp_Ext_GeographicalInformation(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_rrlp_ReferenceAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceAssistData, ReferenceAssistData_sequence);
return offset;
}
static int
dissect_rrlp_MultiFrameOffset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 51U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_RoughRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1250U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_FineRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_RelDistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-200000, 200000U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_RelativeAlt(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4000, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_ReferenceWGS84(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceWGS84, ReferenceWGS84_sequence);
return offset;
}
static int
dissect_rrlp_CalcAssistanceBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_CalcAssistanceBTS, CalcAssistanceBTS_sequence);
return offset;
}
static int
dissect_rrlp_MsrAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrAssistBTS, MsrAssistBTS_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfMsrAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfMsrAssistBTS, SeqOfMsrAssistBTS_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_rrlp_MsrAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrAssistData, MsrAssistData_sequence);
return offset;
}
static int
dissect_rrlp_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_rrlp_AssistBTSData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AssistBTSData, AssistBTSData_sequence);
return offset;
}
static int
dissect_rrlp_SystemInfoAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_SystemInfoAssistBTS, SystemInfoAssistBTS_choice,
NULL);
return offset;
}
static int
dissect_rrlp_SeqOfSystemInfoAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfSystemInfoAssistBTS, SeqOfSystemInfoAssistBTS_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_SystemInfoAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_SystemInfoAssistData, SystemInfoAssistData_sequence);
return offset;
}
static int
dissect_rrlp_GPSTOW23b(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7559999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GPSWeek(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GPSTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSTime, GPSTime_sequence);
return offset;
}
static int
dissect_rrlp_FrameNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2097151U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TimeSlot(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_BitNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 156U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GSMTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GSMTime, GSMTime_sequence);
return offset;
}
static int
dissect_rrlp_SatelliteID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TLMWord(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AntiSpoofFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AlertFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TLMReservedBits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GPSTOWAssistElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSTOWAssistElement, GPSTOWAssistElement_sequence);
return offset;
}
static int
dissect_rrlp_GPSTOWAssist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSTOWAssist, GPSTOWAssist_sequence_of,
1, 12, FALSE);
return offset;
}
static int
dissect_rrlp_ReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceTime, ReferenceTime_sequence);
return offset;
}
static int
dissect_rrlp_RefLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_RefLocation, RefLocation_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_604799(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 604799U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_239(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 239U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M2047_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2047, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M127_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M7_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-7, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_SatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_SatElement, SatElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfSatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfSatElement, SeqOfSatElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_DGPSCorrections(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGPSCorrections, DGPSCorrections_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_EphemerisSubframe1Reserved(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_EphemerisSubframe1Reserved, EphemerisSubframe1Reserved_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M128_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-128, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_37799(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 37799U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M32768_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-32768, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M2097152_2097151(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2097152, 2097151U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M2147483648_2147483647(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
G_MININT32, 2147483647U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M8192_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8192, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_UncompressedEphemeris(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_UncompressedEphemeris, UncompressedEphemeris_sequence);
return offset;
}
static int
dissect_rrlp_SatStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_SatStatus, SatStatus_choice,
NULL);
return offset;
}
static int
dissect_rrlp_NavModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModelElement, NavModelElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfNavModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfNavModelElement, SeqOfNavModelElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_NavigationModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavigationModel, NavigationModel_sequence);
return offset;
}
static int
dissect_rrlp_IonosphericModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_IonosphericModel, IonosphericModel_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_UTCModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_UTCModel, UTCModel_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M1024_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1024, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AlmanacElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AlmanacElement, AlmanacElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfAlmanacElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfAlmanacElement, SeqOfAlmanacElement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac, Almanac_sequence);
return offset;
}
static int
dissect_rrlp_TimeRelation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_TimeRelation, TimeRelation_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M2048_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2048, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AddionalDopplerFields(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AddionalDopplerFields, AddionalDopplerFields_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_1022(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1022U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_19(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 19U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AddionalAngleFields(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AddionalAngleFields, AddionalAngleFields_sequence);
return offset;
}
static int
dissect_rrlp_AcquisElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AcquisElement, AcquisElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfAcquisElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfAcquisElement, SeqOfAcquisElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_AcquisAssist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AcquisAssist, AcquisAssist_sequence);
return offset;
}
static int
dissect_rrlp_SeqOf_BadSatelliteSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOf_BadSatelliteSet, SeqOf_BadSatelliteSet_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_ControlHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ControlHeader, ControlHeader_sequence);
return offset;
}
static int
dissect_rrlp_GPS_AssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPS_AssistData, GPS_AssistData_sequence);
return offset;
}
static int
dissect_rrlp_ExpectedOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1250U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_ExpOTDUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_MsrAssistBTS_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrAssistBTS_R98_ExpOTD, MsrAssistBTS_R98_ExpOTD_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfMsrAssistBTS_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfMsrAssistBTS_R98_ExpOTD, SeqOfMsrAssistBTS_R98_ExpOTD_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_rrlp_MsrAssistData_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrAssistData_R98_ExpOTD, MsrAssistData_R98_ExpOTD_sequence);
return offset;
}
static int
dissect_rrlp_AssistBTSData_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AssistBTSData_R98_ExpOTD, AssistBTSData_R98_ExpOTD_sequence);
return offset;
}
static int
dissect_rrlp_SystemInfoAssistBTS_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_SystemInfoAssistBTS_R98_ExpOTD, SystemInfoAssistBTS_R98_ExpOTD_choice,
NULL);
return offset;
}
static int
dissect_rrlp_SeqOfSystemInfoAssistBTS_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfSystemInfoAssistBTS_R98_ExpOTD, SeqOfSystemInfoAssistBTS_R98_ExpOTD_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_SystemInfoAssistData_R98_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_SystemInfoAssistData_R98_ExpOTD, SystemInfoAssistData_R98_ExpOTD_sequence);
return offset;
}
static int
dissect_rrlp_Rel98_Ext_ExpOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel98_Ext_ExpOTD, Rel98_Ext_ExpOTD_sequence);
return offset;
}
static int
dissect_rrlp_GPSReferenceTimeUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Rel98_MsrPosition_Req_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel98_MsrPosition_Req_Extension, Rel98_MsrPosition_Req_Extension_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_262143(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 262143U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Extended_reference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Extended_reference, Extended_reference_sequence);
return offset;
}
static int
dissect_rrlp_Rel5_MsrPosition_Req_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel5_MsrPosition_Req_Extension, Rel5_MsrPosition_Req_Extension_sequence);
return offset;
}
static int
dissect_rrlp_GANSSPositioningMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_0_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSTOD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 86399U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSTODUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSRefTimeInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefTimeInfo, GANSSRefTimeInfo_sequence);
return offset;
}
static int
dissect_rrlp_FrameDrift(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSTOD_GSMTimeAssociation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSTOD_GSMTimeAssociation, GANSSTOD_GSMTimeAssociation_sequence);
return offset;
}
static int
dissect_rrlp_GANSSReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSReferenceTime, GANSSReferenceTime_sequence);
return offset;
}
static int
dissect_rrlp_GANSSRefLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefLocation, GANSSRefLocation_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSIonosphereModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSIonosphereModel, GANSSIonosphereModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSIonoStormFlags(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSIonoStormFlags, GANSSIonoStormFlags_sequence);
return offset;
}
static int
dissect_rrlp_GANSSIonosphericModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSIonosphericModel, GANSSIonosphericModel_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSAddIonosphericModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAddIonosphericModel, GANSSAddIonosphericModel_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M1048576_1048575(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1048576, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M16384_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16384, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M1073741824_1073741823(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1073741824, 1073741823U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M262144_262143(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-262144, 262143U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSEarthOrientParam(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEarthOrientParam, GANSSEarthOrientParam_sequence);
return offset;
}
static int
dissect_rrlp_GANSSReferenceTime_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSReferenceTime_R10_Ext, GANSSReferenceTime_R10_Ext_sequence);
return offset;
}
static int
dissect_rrlp_GANSSCommonAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSCommonAssistData, GANSSCommonAssistData_sequence);
return offset;
}
static int
dissect_rrlp_TA0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
G_MININT32, 2147483647U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TA1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSTimeModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSTimeModelElement, GANSSTimeModelElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSTimeModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSTimeModel, SeqOfGANSSTimeModel_sequence_of,
1, 7, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_119(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 119U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSSignalID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_SVID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_DGANSSSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGANSSSgnElement, DGANSSSgnElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfDGANSSSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfDGANSSSgnElement, SeqOfDGANSSSgnElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_SgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_SgnTypeElement, SgnTypeElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfSgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfSgnTypeElement, SeqOfSgnTypeElement_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSDiffCorrections(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDiffCorrections, GANSSDiffCorrections_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
5, 5, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_0_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M131072_131071(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-131072, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M134217728_134217727(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-134217728, 134217727U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M512_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-512, 511U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_StandardClockModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_StandardClockModelElement, StandardClockModelElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfStandardClockModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfStandardClockModelElement, SeqOfStandardClockModelElement_sequence_of,
1, 2, FALSE);
return offset;
}
static int
dissect_rrlp_NAVclockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NAVclockModel, NAVclockModel_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_2015(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2015U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M16_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16, 15U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M524288_524287(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-524288, 524287U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M33554432_33554431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-33554432, 33554431U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M4096_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4096, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_CNAVclockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_CNAVclockModel, CNAVclockModel_sequence);
return offset;
}
static int
dissect_rrlp_GLONASSclockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GLONASSclockModel, GLONASSclockModel_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_5399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 5399U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_SBASclockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_SBASclockModel, SBASclockModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSClockModel, GANSSClockModel_choice,
NULL);
return offset;
}
static int
dissect_rrlp_NavModel_KeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModel_KeplerianSet, NavModel_KeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_NavModel_NAVKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModel_NAVKeplerianSet, NavModel_NAVKeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M16777216_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16777216, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M65536_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-65536, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M4194304_4194303(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4194304, 4194303U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M4294967296_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
G_GINT64_CONSTANT(-4294967296), 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_8589934591(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(8589934591), NULL, FALSE);
return offset;
}
static int
dissect_rrlp_NavModel_CNAVKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModel_CNAVKeplerianSet, NavModel_CNAVKeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_M67108864_67108863(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-67108864, 67108863U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_NavModel_GLONASSecef(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModel_GLONASSecef, NavModel_GLONASSecef_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_M536870912_536870911(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-536870912, 536870911U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_NavModel_SBASecef(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_NavModel_SBASecef, NavModel_SBASecef_sequence);
return offset;
}
static int
dissect_rrlp_GANSSOrbitModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSOrbitModel, GANSSOrbitModel_choice,
NULL);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSSatelliteElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSSatelliteElement, GANSSSatelliteElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSSatelliteElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSSatelliteElement, SeqOfGANSSSatelliteElement_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSNavModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSNavModel, GANSSNavModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSSignals(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_BadSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_BadSignalElement, BadSignalElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfBadSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfBadSignalElement, SeqOfBadSignalElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSRealTimeIntegrity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRealTimeIntegrity, GANSSRealTimeIntegrity_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_59(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSDataBit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_SeqOf_GANSSDataBits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOf_GANSSDataBits, SeqOf_GANSSDataBits_sequence_of,
1, 1024, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSDataBitsSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDataBitsSgnElement, GANSSDataBitsSgnElement_sequence);
return offset;
}
static int
dissect_rrlp_Seq_OfGANSSDataBitsSgn(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_Seq_OfGANSSDataBitsSgn, Seq_OfGANSSDataBitsSgn_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_rrlp_GanssDataBitsElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GanssDataBitsElement, GanssDataBitsElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGanssDataBitsElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGanssDataBitsElement, SeqOfGanssDataBitsElement_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSDataBitAssist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDataBitAssist, GANSSDataBitAssist_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_AdditionalDopplerFields(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AdditionalDopplerFields, AdditionalDopplerFields_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSRefMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefMeasurementElement, GANSSRefMeasurementElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSRefMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSRefMeasurementElement, SeqOfGANSSRefMeasurementElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSRefMeasurementAssist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefMeasurementAssist, GANSSRefMeasurementAssist_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac_KeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_KeplerianSet, Almanac_KeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_Almanac_NAVKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_NAVKeplerianSet, Almanac_NAVKeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_M64_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64, 63U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac_ReducedKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_ReducedKeplerianSet, Almanac_ReducedKeplerianSet_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_131071(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac_MidiAlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_MidiAlmanacSet, Almanac_MidiAlmanacSet_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_1_1461(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1461U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 24U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_2097151(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2097151U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac_GlonassAlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_GlonassAlmanacSet, Almanac_GlonassAlmanacSet_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_INTEGER_M256_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-256, 255U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M4_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M8_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_Almanac_ECEFsbasAlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Almanac_ECEFsbasAlmanacSet, Almanac_ECEFsbasAlmanacSet_sequence);
return offset;
}
static int
dissect_rrlp_GANSSAlmanacElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAlmanacElement, GANSSAlmanacElement_choice,
NULL);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSAlmanacElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSAlmanacElement, SeqOfGANSSAlmanacElement_sequence_of,
1, 36, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSAlmanacModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAlmanacModel, GANSSAlmanacModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSUTCModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSUTCModel, GANSSUTCModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisExtensionTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisExtensionTime, GANSSEphemerisExtensionTime_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_1_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_512(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 512U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisExtensionHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisExtensionHeader, GANSSEphemerisExtensionHeader_sequence);
return offset;
}
static int
dissect_rrlp_ReferenceNavModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceNavModel, ReferenceNavModel_sequence);
return offset;
}
static int
dissect_rrlp_GANSSReferenceOrbit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSReferenceOrbit, GANSSReferenceOrbit_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSRefOrbit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSRefOrbit, SeqOfGANSSRefOrbit_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 14U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 10U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisDeltaBitSizes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisDeltaBitSizes, GANSSEphemerisDeltaBitSizes_sequence);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisDeltaScales(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisDeltaScales, GANSSEphemerisDeltaScales_sequence);
return offset;
}
static int
dissect_rrlp_GANSSDeltaEpochHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDeltaEpochHeader, GANSSDeltaEpochHeader_sequence);
return offset;
}
static int
dissect_rrlp_OCTET_STRING_SIZE_1_49(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 49, FALSE, NULL);
return offset;
}
static int
dissect_rrlp_GANSSDeltaElementList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDeltaElementList, GANSSDeltaElementList_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisDeltaEpoch(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisDeltaEpoch, GANSSEphemerisDeltaEpoch_sequence);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisDeltaMatrix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisDeltaMatrix, GANSSEphemerisDeltaMatrix_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisExtension, GANSSEphemerisExtension_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSSatEventsInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSSatEventsInfo, GANSSSatEventsInfo_sequence);
return offset;
}
static int
dissect_rrlp_GANSSEphemerisExtensionCheck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSEphemerisExtensionCheck, GANSSEphemerisExtensionCheck_sequence);
return offset;
}
static int
dissect_rrlp_UTCmodelSet2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_UTCmodelSet2, UTCmodelSet2_sequence);
return offset;
}
static int
dissect_rrlp_UTCmodelSet3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_UTCmodelSet3, UTCmodelSet3_sequence);
return offset;
}
static int
dissect_rrlp_UTCmodelSet4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_UTCmodelSet4, UTCmodelSet4_sequence);
return offset;
}
static int
dissect_rrlp_GANSSAddUTCModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAddUTCModel, GANSSAddUTCModel_choice,
NULL);
return offset;
}
static int
dissect_rrlp_GANSS_ID1_element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_ID1_element, GANSS_ID1_element_sequence);
return offset;
}
static int
dissect_rrlp_GANSS_ID1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_ID1, GANSS_ID1_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_M7_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-7, 13U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_ID3_element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_ID3_element, GANSS_ID3_element_sequence);
return offset;
}
static int
dissect_rrlp_GANSS_ID3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_ID3, GANSS_ID3_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSAuxiliaryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAuxiliaryInformation, GANSSAuxiliaryInformation_choice,
NULL);
return offset;
}
static int
dissect_rrlp_DGANSSExtensionSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGANSSExtensionSgnElement, DGANSSExtensionSgnElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfDGANSSExtensionSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfDGANSSExtensionSgnElement, SeqOfDGANSSExtensionSgnElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_DGANSSExtensionSgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGANSSExtensionSgnTypeElement, DGANSSExtensionSgnTypeElement_sequence);
return offset;
}
static int
dissect_rrlp_GANSSDiffCorrectionsValidityPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSDiffCorrectionsValidityPeriod, GANSSDiffCorrectionsValidityPeriod_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSTimeModelElement_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSTimeModelElement_R10_Ext, GANSSTimeModelElement_R10_Ext_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSTimeModel_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSTimeModel_R10_Ext, SeqOfGANSSTimeModel_R10_Ext_sequence_of,
1, 7, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSRefMeasurement_R10_Ext_Element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefMeasurement_R10_Ext_Element, GANSSRefMeasurement_R10_Ext_Element_sequence);
return offset;
}
static int
dissect_rrlp_GANSSRefMeasurementAssist_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSRefMeasurementAssist_R10_Ext, GANSSRefMeasurementAssist_R10_Ext_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSAlmanacModel_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAlmanacModel_R10_Ext, GANSSAlmanacModel_R10_Ext_sequence);
return offset;
}
static int
dissect_rrlp_GANSSGenericAssistDataElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSGenericAssistDataElement, GANSSGenericAssistDataElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSSGenericAssistDataElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSSGenericAssistDataElement, SeqOfGANSSGenericAssistDataElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_ControlHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_ControlHeader, GANSS_ControlHeader_sequence);
return offset;
}
static int
dissect_rrlp_GANSS_AssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_AssistData, GANSS_AssistData_sequence);
return offset;
}
static int
dissect_rrlp_RequiredResponseTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GPSEphemerisExtensionTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisExtensionTime, GPSEphemerisExtensionTime_sequence);
return offset;
}
static int
dissect_rrlp_GPSEphemerisExtensionHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisExtensionHeader, GPSEphemerisExtensionHeader_sequence);
return offset;
}
static int
dissect_rrlp_GPSClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSClockModel, GPSClockModel_sequence);
return offset;
}
static int
dissect_rrlp_GPSReferenceOrbit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSReferenceOrbit, GPSReferenceOrbit_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGPSRefOrbit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGPSRefOrbit, SeqOfGPSRefOrbit_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_GPSEphemerisDeltaBitSizes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisDeltaBitSizes, GPSEphemerisDeltaBitSizes_sequence);
return offset;
}
static int
dissect_rrlp_GPSEphemerisDeltaScales(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisDeltaScales, GPSEphemerisDeltaScales_sequence);
return offset;
}
static int
dissect_rrlp_GPSDeltaEpochHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSDeltaEpochHeader, GPSDeltaEpochHeader_sequence);
return offset;
}
static int
dissect_rrlp_OCTET_STRING_SIZE_1_47(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 47, FALSE, NULL);
return offset;
}
static int
dissect_rrlp_GPSDeltaElementList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSDeltaElementList, GPSDeltaElementList_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_rrlp_GPSEphemerisDeltaEpoch(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisDeltaEpoch, GPSEphemerisDeltaEpoch_sequence);
return offset;
}
static int
dissect_rrlp_GPSEphemerisDeltaMatrix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisDeltaMatrix, GPSEphemerisDeltaMatrix_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_rrlp_GPSEphemerisExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisExtension, GPSEphemerisExtension_sequence);
return offset;
}
static int
dissect_rrlp_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GPSSatEventsInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSSatEventsInfo, GPSSatEventsInfo_sequence);
return offset;
}
static int
dissect_rrlp_GPSEphemerisExtensionCheck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSEphemerisExtensionCheck, GPSEphemerisExtensionCheck_sequence);
return offset;
}
static int
dissect_rrlp_DGPSExtensionSatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGPSExtensionSatElement, DGPSExtensionSatElement_sequence);
return offset;
}
static int
dissect_rrlp_DGPSCorrectionsValidityPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_DGPSCorrectionsValidityPeriod, DGPSCorrectionsValidityPeriod_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GPSReferenceTime_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSReferenceTime_R10_Ext, GPSReferenceTime_R10_Ext_sequence);
return offset;
}
static int
dissect_rrlp_GPSAcquisAssist_R10_Ext_Element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSAcquisAssist_R10_Ext_Element, GPSAcquisAssist_R10_Ext_Element_sequence);
return offset;
}
static int
dissect_rrlp_GPSAcquisAssist_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSAcquisAssist_R10_Ext, GPSAcquisAssist_R10_Ext_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GPSAlmanac_R10_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSAlmanac_R10_Ext, GPSAlmanac_R10_Ext_sequence);
return offset;
}
static int
dissect_rrlp_Add_GPS_ControlHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Add_GPS_ControlHeader, Add_GPS_ControlHeader_sequence);
return offset;
}
static int
dissect_rrlp_Add_GPS_AssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Add_GPS_AssistData, Add_GPS_AssistData_sequence);
return offset;
}
static int
dissect_rrlp_Rel7_MsrPosition_Req_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel7_MsrPosition_Req_Extension, Rel7_MsrPosition_Req_Extension_sequence);
return offset;
}
static int
dissect_rrlp_MsrPosition_Req(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrPosition_Req, MsrPosition_Req_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_2_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_1_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_ReferenceRelation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_MultipleSets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MultipleSets, MultipleSets_sequence);
return offset;
}
static int
dissect_rrlp_BSICAndCarrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_BSICAndCarrier, BSICAndCarrier_sequence);
return offset;
}
static int
dissect_rrlp_CellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_RequestIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_SystemInfoIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_CellIDAndLAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_CellIDAndLAC, CellIDAndLAC_sequence);
return offset;
}
static int
dissect_rrlp_ReferenceIdentityType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceIdentityType, ReferenceIdentityType_choice,
NULL);
return offset;
}
static int
dissect_rrlp_SeqOfReferenceIdentityType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfReferenceIdentityType, SeqOfReferenceIdentityType_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_rrlp_ReferenceIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceIdentity, ReferenceIdentity_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_42431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 42431U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_ModuloTimeSlot(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_RefQuality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_NumOfMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_TOA_MeasurementsOfRef(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_TOA_MeasurementsOfRef, TOA_MeasurementsOfRef_sequence);
return offset;
}
static int
dissect_rrlp_StdResolution(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_960(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 960U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_MultiFrameCarrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MultiFrameCarrier, MultiFrameCarrier_sequence);
return offset;
}
static int
dissect_rrlp_NeighborIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_NeighborIdentity, NeighborIdentity_choice,
NULL);
return offset;
}
static int
dissect_rrlp_EOTDQuality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_EOTDQuality, EOTDQuality_sequence);
return offset;
}
static int
dissect_rrlp_OTDValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 39999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_OTD_MeasurementWithID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MeasurementWithID, OTD_MeasurementWithID_sequence);
return offset;
}
static int
dissect_rrlp_OTD_FirstSetMsrs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_rrlp_OTD_MeasurementWithID(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_rrlp_SeqOfOTD_FirstSetMsrs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfOTD_FirstSetMsrs, SeqOfOTD_FirstSetMsrs_sequence_of,
1, 10, FALSE);
return offset;
}
static int
dissect_rrlp_OTD_MsrElementFirst(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MsrElementFirst, OTD_MsrElementFirst_sequence);
return offset;
}
static int
dissect_rrlp_OTD_Measurement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_Measurement, OTD_Measurement_sequence);
return offset;
}
static int
dissect_rrlp_OTD_MsrsOfOtherSets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MsrsOfOtherSets, OTD_MsrsOfOtherSets_choice,
NULL);
return offset;
}
static int
dissect_rrlp_SeqOfOTD_MsrsOfOtherSets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfOTD_MsrsOfOtherSets, SeqOfOTD_MsrsOfOtherSets_sequence_of,
1, 10, FALSE);
return offset;
}
static int
dissect_rrlp_OTD_MsrElementRest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MsrElementRest, OTD_MsrElementRest_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfOTD_MsrElementRest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfOTD_MsrElementRest, SeqOfOTD_MsrElementRest_sequence_of,
1, 2, FALSE);
return offset;
}
static int
dissect_rrlp_OTD_MeasureInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MeasureInfo, OTD_MeasureInfo_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_14399999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14399999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_FixType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_LocationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_LocationInfo, LocationInfo_sequence);
return offset;
}
static int
dissect_rrlp_GPSTOW24b(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14399999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_1024(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_MpathIndic(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_GPS_MsrElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPS_MsrElement, GPS_MsrElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGPS_MsrElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGPS_MsrElement, SeqOfGPS_MsrElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GPS_MsrSetElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPS_MsrSetElement, GPS_MsrSetElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGPS_MsrSetElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGPS_MsrSetElement, SeqOfGPS_MsrSetElement_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_rrlp_GPS_MeasureInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPS_MeasureInfo, GPS_MeasureInfo_sequence);
return offset;
}
static int
dissect_rrlp_LocErrorReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
11, NULL, TRUE, 3, NULL);
return offset;
}
static int
dissect_rrlp_GPSAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxGPSAssistanceData, FALSE, NULL);
return offset;
}
static int
dissect_rrlp_GANSSAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxGANSSAssistanceData, FALSE, NULL);
return offset;
}
static int
dissect_rrlp_AdditionalAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AdditionalAssistanceData, AdditionalAssistanceData_sequence);
return offset;
}
static int
dissect_rrlp_LocationError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_LocationError, LocationError_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfOTD_FirstSetMsrs_R98_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfOTD_FirstSetMsrs_R98_Ext, SeqOfOTD_FirstSetMsrs_R98_Ext_sequence_of,
1, 5, FALSE);
return offset;
}
static int
dissect_rrlp_OTD_MsrElementFirst_R98_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MsrElementFirst_R98_Ext, OTD_MsrElementFirst_R98_Ext_sequence);
return offset;
}
static int
dissect_rrlp_OTD_MeasureInfo_R98_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_OTD_MeasureInfo_R98_Ext, OTD_MeasureInfo_R98_Ext_sequence);
return offset;
}
static int
dissect_rrlp_T_rel_98_Ext_MeasureInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_T_rel_98_Ext_MeasureInfo, T_rel_98_Ext_MeasureInfo_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_9999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GPSTimeAssistanceMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GPSTimeAssistanceMeasurements, GPSTimeAssistanceMeasurements_sequence);
return offset;
}
static int
dissect_rrlp_Rel_98_MsrPosition_Rsp_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel_98_MsrPosition_Rsp_Extension, Rel_98_MsrPosition_Rsp_Extension_sequence);
return offset;
}
static int
dissect_rrlp_OTD_MeasureInfo_5_Ext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_rrlp_SeqOfOTD_MsrElementRest(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_rrlp_UlPseudoSegInd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_Rel_5_MsrPosition_Rsp_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel_5_MsrPosition_Rsp_Extension, Rel_5_MsrPosition_Rsp_Extension_sequence);
return offset;
}
static int
dissect_rrlp_ReferenceFrame(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ReferenceFrame, ReferenceFrame_sequence);
return offset;
}
static int
dissect_rrlp_GANSSTODm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3599999U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_INTEGER_0_16384(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16384U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_PositionData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
3, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSLocationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSLocationInfo, GANSSLocationInfo_sequence);
return offset;
}
static int
dissect_rrlp_INTEGER_0_33554431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 33554431U, NULL, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_SgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_SgnElement, GANSS_SgnElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSS_SgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSS_SgnElement, SeqOfGANSS_SgnElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_SgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_SgnTypeElement, GANSS_SgnTypeElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSS_SgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSS_SgnTypeElement, SeqOfGANSS_SgnTypeElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_MsrElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_MsrElement, GANSS_MsrElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSS_MsrElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSS_MsrElement, SeqOfGANSS_MsrElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_rrlp_GANSS_MsrSetElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSS_MsrSetElement, GANSS_MsrSetElement_sequence);
return offset;
}
static int
dissect_rrlp_SeqOfGANSS_MsrSetElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SeqOfGANSS_MsrSetElement, SeqOfGANSS_MsrSetElement_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSMeasureInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSMeasureInfo, GANSSMeasureInfo_sequence);
return offset;
}
static int
dissect_rrlp_Rel_7_MsrPosition_Rsp_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel_7_MsrPosition_Rsp_Extension, Rel_7_MsrPosition_Rsp_Extension_sequence);
return offset;
}
static int
dissect_rrlp_MsrPosition_Rsp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_MsrPosition_Rsp, MsrPosition_Rsp_sequence);
return offset;
}
static int
dissect_rrlp_MoreAssDataToBeSent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rrlp_Rel98_AssistanceData_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel98_AssistanceData_Extension, Rel98_AssistanceData_Extension_sequence);
return offset;
}
static int
dissect_rrlp_Rel5_AssistanceData_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel5_AssistanceData_Extension, Rel5_AssistanceData_Extension_sequence);
return offset;
}
static int
dissect_rrlp_Rel7_AssistanceData_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel7_AssistanceData_Extension, Rel7_AssistanceData_Extension_sequence);
return offset;
}
static int
dissect_rrlp_AssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AssistanceData, AssistanceData_sequence);
return offset;
}
static int
dissect_rrlp_ErrorCodes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rrlp_Rel_5_ProtocolError_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_Rel_5_ProtocolError_Extension, Rel_5_ProtocolError_Extension_sequence);
return offset;
}
static int
dissect_rrlp_ProtocolError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_ProtocolError, ProtocolError_sequence);
return offset;
}
static int
dissect_rrlp_GANSSPositioningMethodTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_SBASID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSPositionMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSPositionMethod, GANSSPositionMethod_sequence);
return offset;
}
static int
dissect_rrlp_GANSSPositionMethods(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSPositionMethods, GANSSPositionMethods_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_PosCapability_Req(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PosCapability_Req, PosCapability_Req_sequence);
return offset;
}
static int
dissect_rrlp_NonGANSSPositionMethods(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_MultipleMeasurementSets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_PosCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PosCapabilities, PosCapabilities_sequence);
return offset;
}
static int
dissect_rrlp_GPSAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_CommonGANSSAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSAssistanceForOneGANSS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAssistanceForOneGANSS, GANSSAssistanceForOneGANSS_sequence);
return offset;
}
static int
dissect_rrlp_SpecificGANSSAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_SpecificGANSSAssistance, SpecificGANSSAssistance_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_GANSSAssistanceSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAssistanceSet, GANSSAssistanceSet_sequence);
return offset;
}
static int
dissect_rrlp_GANSSModelID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_rrlp_GANSSAdditionalAssistanceChoicesForOneGANSS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAdditionalAssistanceChoicesForOneGANSS, GANSSAdditionalAssistanceChoicesForOneGANSS_sequence);
return offset;
}
static int
dissect_rrlp_GANSSAdditionalAssistanceChoices(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rrlp_GANSSAdditionalAssistanceChoices, GANSSAdditionalAssistanceChoices_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_rrlp_AssistanceSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AssistanceSupported, AssistanceSupported_sequence);
return offset;
}
static int
dissect_rrlp_AssistanceNeeded(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_AssistanceNeeded, AssistanceNeeded_sequence);
return offset;
}
static int
dissect_rrlp_PosCapability_Rsp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PosCapability_Rsp, PosCapability_Rsp_sequence);
return offset;
}
static int
dissect_rrlp_RRLP_Component(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rrlp_RRLP_Component, RRLP_Component_choice,
NULL);
return offset;
}
static int
dissect_rrlp_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 25 "./asn1/rrlp/rrlp.cnf"
proto_tree_add_item(tree, proto_rrlp, tvb, 0, -1, ENC_NA);
col_append_sep_str(actx->pinfo->cinfo, COL_PROTOCOL, "/", "RRLP");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rrlp_PDU, PDU_sequence);
return offset;
}
static int dissect_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_rrlp_PDU(tvb, offset, &asn1_ctx, tree, hf_rrlp_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
void proto_register_rrlp(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/rrlp/packet-rrlp-hfarr.c"
{ &hf_rrlp_PDU_PDU,
{ "PDU", "rrlp.PDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_privateExtensionList,
{ "privateExtensionList", "rrlp.privateExtensionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_pcs_Extensions,
{ "pcs-Extensions", "rrlp.pcs_Extensions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_PrivateExtensionList_item,
{ "PrivateExtension", "rrlp.PrivateExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_extId,
{ "extId", "rrlp.extId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_rrlp_extType,
{ "extType", "rrlp.extType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceNumber,
{ "referenceNumber", "rrlp.referenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_component,
{ "component", "rrlp.component",
FT_UINT32, BASE_DEC, VALS(rrlp_RRLP_Component_vals), 0,
"RRLP_Component", HFILL }},
{ &hf_rrlp_msrPositionReq,
{ "msrPositionReq", "rrlp.msrPositionReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"MsrPosition_Req", HFILL }},
{ &hf_rrlp_msrPositionRsp,
{ "msrPositionRsp", "rrlp.msrPositionRsp_element",
FT_NONE, BASE_NONE, NULL, 0,
"MsrPosition_Rsp", HFILL }},
{ &hf_rrlp_assistanceData,
{ "assistanceData", "rrlp.assistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_assistanceDataAck,
{ "assistanceDataAck", "rrlp.assistanceDataAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_protocolError,
{ "protocolError", "rrlp.protocolError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_posCapabilityReq,
{ "posCapabilityReq", "rrlp.posCapabilityReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"PosCapability_Req", HFILL }},
{ &hf_rrlp_posCapabilityRsp,
{ "posCapabilityRsp", "rrlp.posCapabilityRsp_element",
FT_NONE, BASE_NONE, NULL, 0,
"PosCapability_Rsp", HFILL }},
{ &hf_rrlp_positionInstruct,
{ "positionInstruct", "rrlp.positionInstruct_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceAssistData,
{ "referenceAssistData", "rrlp.referenceAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_msrAssistData,
{ "msrAssistData", "rrlp.msrAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_systemInfoAssistData,
{ "systemInfoAssistData", "rrlp.systemInfoAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gps_AssistData,
{ "gps-AssistData", "rrlp.gps_AssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_extensionContainer,
{ "extensionContainer", "rrlp.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel98_MsrPosition_Req_extension,
{ "rel98-MsrPosition-Req-extension", "rrlp.rel98_MsrPosition_Req_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel5_MsrPosition_Req_extension,
{ "rel5-MsrPosition-Req-extension", "rrlp.rel5_MsrPosition_Req_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel7_MsrPosition_Req_extension,
{ "rel7-MsrPosition-Req-extension", "rrlp.rel7_MsrPosition_Req_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_multipleSets,
{ "multipleSets", "rrlp.multipleSets_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceIdentity,
{ "referenceIdentity", "rrlp.referenceIdentity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_otd_MeasureInfo,
{ "otd-MeasureInfo", "rrlp.otd_MeasureInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_locationInfo,
{ "locationInfo", "rrlp.locationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gps_MeasureInfo,
{ "gps-MeasureInfo", "rrlp.gps_MeasureInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_locationError,
{ "locationError", "rrlp.locationError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel_98_MsrPosition_Rsp_Extension,
{ "rel-98-MsrPosition-Rsp-Extension", "rrlp.rel_98_MsrPosition_Rsp_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel_5_MsrPosition_Rsp_Extension,
{ "rel-5-MsrPosition-Rsp-Extension", "rrlp.rel_5_MsrPosition_Rsp_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel_7_MsrPosition_Rsp_Extension,
{ "rel-7-MsrPosition-Rsp-Extension", "rrlp.rel_7_MsrPosition_Rsp_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_moreAssDataToBeSent,
{ "moreAssDataToBeSent", "rrlp.moreAssDataToBeSent",
FT_UINT32, BASE_DEC, VALS(rrlp_MoreAssDataToBeSent_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_rel98_AssistanceData_Extension,
{ "rel98-AssistanceData-Extension", "rrlp.rel98_AssistanceData_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel5_AssistanceData_Extension,
{ "rel5-AssistanceData-Extension", "rrlp.rel5_AssistanceData_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel7_AssistanceData_Extension,
{ "rel7-AssistanceData-Extension", "rrlp.rel7_AssistanceData_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_errorCause,
{ "errorCause", "rrlp.errorCause",
FT_UINT32, BASE_DEC, VALS(rrlp_ErrorCodes_vals), 0,
"ErrorCodes", HFILL }},
{ &hf_rrlp_rel_5_ProtocolError_Extension,
{ "rel-5-ProtocolError-Extension", "rrlp.rel_5_ProtocolError_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_extended_reference,
{ "extended-reference", "rrlp.extended_reference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSPositionMethods,
{ "gANSSPositionMethods", "rrlp.gANSSPositionMethods",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_posCapabilities,
{ "posCapabilities", "rrlp.posCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_assistanceSupported,
{ "assistanceSupported", "rrlp.assistanceSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_assistanceNeeded,
{ "assistanceNeeded", "rrlp.assistanceNeeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_methodType,
{ "methodType", "rrlp.methodType",
FT_UINT32, BASE_DEC, VALS(rrlp_MethodType_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_positionMethod,
{ "positionMethod", "rrlp.positionMethod",
FT_UINT32, BASE_DEC, VALS(rrlp_PositionMethod_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_measureResponseTime,
{ "measureResponseTime", "rrlp.measureResponseTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_useMultipleSets,
{ "useMultipleSets", "rrlp.useMultipleSets",
FT_UINT32, BASE_DEC, VALS(rrlp_UseMultipleSets_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_environmentCharacter,
{ "environmentCharacter", "rrlp.environmentCharacter",
FT_UINT32, BASE_DEC, VALS(rrlp_EnvironmentCharacter_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_msAssisted,
{ "msAssisted", "rrlp.msAssisted_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccuracyOpt", HFILL }},
{ &hf_rrlp_msBased,
{ "msBased", "rrlp.msBased",
FT_UINT32, BASE_DEC, NULL, 0,
"Accuracy", HFILL }},
{ &hf_rrlp_msBasedPref,
{ "msBasedPref", "rrlp.msBasedPref",
FT_UINT32, BASE_DEC, NULL, 0,
"Accuracy", HFILL }},
{ &hf_rrlp_msAssistedPref,
{ "msAssistedPref", "rrlp.msAssistedPref",
FT_UINT32, BASE_DEC, NULL, 0,
"Accuracy", HFILL }},
{ &hf_rrlp_accuracy,
{ "accuracy", "rrlp.accuracy",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_bcchCarrier,
{ "bcchCarrier", "rrlp.bcchCarrier",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_bsic,
{ "bsic", "rrlp.bsic",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_timeSlotScheme,
{ "timeSlotScheme", "rrlp.timeSlotScheme",
FT_UINT32, BASE_DEC, VALS(rrlp_TimeSlotScheme_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_btsPosition,
{ "btsPosition", "rrlp.btsPosition",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_msrAssistList,
{ "msrAssistList", "rrlp.msrAssistList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfMsrAssistBTS", HFILL }},
{ &hf_rrlp_SeqOfMsrAssistBTS_item,
{ "MsrAssistBTS", "rrlp.MsrAssistBTS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_multiFrameOffset,
{ "multiFrameOffset", "rrlp.multiFrameOffset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_roughRTD,
{ "roughRTD", "rrlp.roughRTD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_calcAssistanceBTS,
{ "calcAssistanceBTS", "rrlp.calcAssistanceBTS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_systemInfoAssistList,
{ "systemInfoAssistList", "rrlp.systemInfoAssistList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfSystemInfoAssistBTS", HFILL }},
{ &hf_rrlp_SeqOfSystemInfoAssistBTS_item,
{ "SystemInfoAssistBTS", "rrlp.SystemInfoAssistBTS",
FT_UINT32, BASE_DEC, VALS(rrlp_SystemInfoAssistBTS_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_notPresent,
{ "notPresent", "rrlp.notPresent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_present,
{ "present", "rrlp.present_element",
FT_NONE, BASE_NONE, NULL, 0,
"AssistBTSData", HFILL }},
{ &hf_rrlp_fineRTD,
{ "fineRTD", "rrlp.fineRTD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceWGS84,
{ "referenceWGS84", "rrlp.referenceWGS84_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_relativeNorth,
{ "relativeNorth", "rrlp.relativeNorth",
FT_INT32, BASE_DEC, NULL, 0,
"RelDistance", HFILL }},
{ &hf_rrlp_relativeEast,
{ "relativeEast", "rrlp.relativeEast",
FT_INT32, BASE_DEC, NULL, 0,
"RelDistance", HFILL }},
{ &hf_rrlp_relativeAlt,
{ "relativeAlt", "rrlp.relativeAlt",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_nbrOfSets,
{ "nbrOfSets", "rrlp.nbrOfSets",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_3", HFILL }},
{ &hf_rrlp_nbrOfReferenceBTSs,
{ "nbrOfReferenceBTSs", "rrlp.nbrOfReferenceBTSs",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_3", HFILL }},
{ &hf_rrlp_referenceRelation,
{ "referenceRelation", "rrlp.referenceRelation",
FT_UINT32, BASE_DEC, VALS(rrlp_ReferenceRelation_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_refBTSList,
{ "refBTSList", "rrlp.refBTSList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfReferenceIdentityType", HFILL }},
{ &hf_rrlp_SeqOfReferenceIdentityType_item,
{ "ReferenceIdentityType", "rrlp.ReferenceIdentityType",
FT_UINT32, BASE_DEC, VALS(rrlp_ReferenceIdentityType_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_bsicAndCarrier,
{ "bsicAndCarrier", "rrlp.bsicAndCarrier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ci,
{ "ci", "rrlp.ci",
FT_UINT32, BASE_DEC, NULL, 0,
"CellID", HFILL }},
{ &hf_rrlp_requestIndex,
{ "requestIndex", "rrlp.requestIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_systemInfoIndex,
{ "systemInfoIndex", "rrlp.systemInfoIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ciAndLAC,
{ "ciAndLAC", "rrlp.ciAndLAC_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellIDAndLAC", HFILL }},
{ &hf_rrlp_carrier,
{ "carrier", "rrlp.carrier",
FT_UINT32, BASE_DEC, NULL, 0,
"BCCHCarrier", HFILL }},
{ &hf_rrlp_referenceLAC,
{ "referenceLAC", "rrlp.referenceLAC",
FT_UINT32, BASE_DEC, NULL, 0,
"LAC", HFILL }},
{ &hf_rrlp_referenceCI,
{ "referenceCI", "rrlp.referenceCI",
FT_UINT32, BASE_DEC, NULL, 0,
"CellID", HFILL }},
{ &hf_rrlp_otdMsrFirstSets,
{ "otdMsrFirstSets", "rrlp.otdMsrFirstSets_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTD_MsrElementFirst", HFILL }},
{ &hf_rrlp_otdMsrRestSets,
{ "otdMsrRestSets", "rrlp.otdMsrRestSets",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfOTD_MsrElementRest", HFILL }},
{ &hf_rrlp_SeqOfOTD_MsrElementRest_item,
{ "OTD-MsrElementRest", "rrlp.OTD_MsrElementRest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_refFrameNumber,
{ "refFrameNumber", "rrlp.refFrameNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_42431", HFILL }},
{ &hf_rrlp_referenceTimeSlot,
{ "referenceTimeSlot", "rrlp.referenceTimeSlot",
FT_UINT32, BASE_DEC, NULL, 0,
"ModuloTimeSlot", HFILL }},
{ &hf_rrlp_toaMeasurementsOfRef,
{ "toaMeasurementsOfRef", "rrlp.toaMeasurementsOfRef_element",
FT_NONE, BASE_NONE, NULL, 0,
"TOA_MeasurementsOfRef", HFILL }},
{ &hf_rrlp_stdResolution,
{ "stdResolution", "rrlp.stdResolution",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_taCorrection,
{ "taCorrection", "rrlp.taCorrection",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_960", HFILL }},
{ &hf_rrlp_otd_FirstSetMsrs,
{ "otd-FirstSetMsrs", "rrlp.otd_FirstSetMsrs",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfOTD_FirstSetMsrs", HFILL }},
{ &hf_rrlp_SeqOfOTD_FirstSetMsrs_item,
{ "OTD-FirstSetMsrs", "rrlp.OTD_FirstSetMsrs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_otd_MsrsOfOtherSets,
{ "otd-MsrsOfOtherSets", "rrlp.otd_MsrsOfOtherSets",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfOTD_MsrsOfOtherSets", HFILL }},
{ &hf_rrlp_SeqOfOTD_MsrsOfOtherSets_item,
{ "OTD-MsrsOfOtherSets", "rrlp.OTD_MsrsOfOtherSets",
FT_UINT32, BASE_DEC, VALS(rrlp_OTD_MsrsOfOtherSets_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_refQuality,
{ "refQuality", "rrlp.refQuality",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_numOfMeasurements,
{ "numOfMeasurements", "rrlp.numOfMeasurements",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_identityNotPresent,
{ "identityNotPresent", "rrlp.identityNotPresent_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTD_Measurement", HFILL }},
{ &hf_rrlp_identityPresent,
{ "identityPresent", "rrlp.identityPresent_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTD_MeasurementWithID", HFILL }},
{ &hf_rrlp_nborTimeSlot,
{ "nborTimeSlot", "rrlp.nborTimeSlot",
FT_UINT32, BASE_DEC, NULL, 0,
"ModuloTimeSlot", HFILL }},
{ &hf_rrlp_eotdQuality,
{ "eotdQuality", "rrlp.eotdQuality_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_otdValue,
{ "otdValue", "rrlp.otdValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_neighborIdentity,
{ "neighborIdentity", "rrlp.neighborIdentity",
FT_UINT32, BASE_DEC, VALS(rrlp_NeighborIdentity_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_nbrOfMeasurements,
{ "nbrOfMeasurements", "rrlp.nbrOfMeasurements",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_stdOfEOTD,
{ "stdOfEOTD", "rrlp.stdOfEOTD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_multiFrameCarrier,
{ "multiFrameCarrier", "rrlp.multiFrameCarrier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_refFrame,
{ "refFrame", "rrlp.refFrame",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_gpsTOW,
{ "gpsTOW", "rrlp.gpsTOW",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_14399999", HFILL }},
{ &hf_rrlp_fixType,
{ "fixType", "rrlp.fixType",
FT_UINT32, BASE_DEC, VALS(rrlp_FixType_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_posEstimate,
{ "posEstimate", "rrlp.posEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_GeographicalInformation", HFILL }},
{ &hf_rrlp_gpsMsrSetList,
{ "gpsMsrSetList", "rrlp.gpsMsrSetList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGPS_MsrSetElement", HFILL }},
{ &hf_rrlp_SeqOfGPS_MsrSetElement_item,
{ "GPS-MsrSetElement", "rrlp.GPS_MsrSetElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsTOW_01,
{ "gpsTOW", "rrlp.gpsTOW",
FT_UINT32, BASE_DEC, NULL, 0,
"GPSTOW24b", HFILL }},
{ &hf_rrlp_gps_msrList,
{ "gps-msrList", "rrlp.gps_msrList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGPS_MsrElement", HFILL }},
{ &hf_rrlp_SeqOfGPS_MsrElement_item,
{ "GPS-MsrElement", "rrlp.GPS_MsrElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_satelliteID,
{ "satelliteID", "rrlp.satelliteID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_cNo,
{ "cNo", "rrlp.cNo",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_doppler,
{ "doppler", "rrlp.doppler",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_wholeChips,
{ "wholeChips", "rrlp.wholeChips",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1022", HFILL }},
{ &hf_rrlp_fracChips,
{ "fracChips", "rrlp.fracChips",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1024", HFILL }},
{ &hf_rrlp_mpathIndic,
{ "mpathIndic", "rrlp.mpathIndic",
FT_UINT32, BASE_DEC, VALS(rrlp_MpathIndic_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_pseuRangeRMSErr,
{ "pseuRangeRMSErr", "rrlp.pseuRangeRMSErr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_locErrorReason,
{ "locErrorReason", "rrlp.locErrorReason",
FT_UINT32, BASE_DEC, VALS(rrlp_LocErrorReason_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_additionalAssistanceData,
{ "additionalAssistanceData", "rrlp.additionalAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsAssistanceData,
{ "gpsAssistanceData", "rrlp.gpsAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssAssistanceData,
{ "ganssAssistanceData", "rrlp.ganssAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_controlHeader,
{ "controlHeader", "rrlp.controlHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceTime,
{ "referenceTime", "rrlp.referenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_refLocation,
{ "refLocation", "rrlp.refLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_dgpsCorrections,
{ "dgpsCorrections", "rrlp.dgpsCorrections_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_navigationModel,
{ "navigationModel", "rrlp.navigationModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ionosphericModel,
{ "ionosphericModel", "rrlp.ionosphericModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_utcModel,
{ "utcModel", "rrlp.utcModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_almanac,
{ "almanac", "rrlp.almanac_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_acquisAssist,
{ "acquisAssist", "rrlp.acquisAssist_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_realTimeIntegrity,
{ "realTimeIntegrity", "rrlp.realTimeIntegrity",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOf_BadSatelliteSet", HFILL }},
{ &hf_rrlp_gpsTime,
{ "gpsTime", "rrlp.gpsTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gsmTime,
{ "gsmTime", "rrlp.gsmTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsTowAssist,
{ "gpsTowAssist", "rrlp.gpsTowAssist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsTOW23b,
{ "gpsTOW23b", "rrlp.gpsTOW23b",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsWeek,
{ "gpsWeek", "rrlp.gpsWeek",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_GPSTOWAssist_item,
{ "GPSTOWAssistElement", "rrlp.GPSTOWAssistElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_tlmWord,
{ "tlmWord", "rrlp.tlmWord",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_antiSpoof,
{ "antiSpoof", "rrlp.antiSpoof",
FT_UINT32, BASE_DEC, NULL, 0,
"AntiSpoofFlag", HFILL }},
{ &hf_rrlp_alert,
{ "alert", "rrlp.alert",
FT_UINT32, BASE_DEC, NULL, 0,
"AlertFlag", HFILL }},
{ &hf_rrlp_tlmRsvdBits,
{ "tlmRsvdBits", "rrlp.tlmRsvdBits",
FT_UINT32, BASE_DEC, NULL, 0,
"TLMReservedBits", HFILL }},
{ &hf_rrlp_frameNumber,
{ "frameNumber", "rrlp.frameNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_timeSlot,
{ "timeSlot", "rrlp.timeSlot",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_bitNumber,
{ "bitNumber", "rrlp.bitNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_threeDLocation,
{ "threeDLocation", "rrlp.threeDLocation",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_GeographicalInformation", HFILL }},
{ &hf_rrlp_gpsTOW_02,
{ "gpsTOW", "rrlp.gpsTOW",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_604799", HFILL }},
{ &hf_rrlp_status,
{ "status", "rrlp.status",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_satList,
{ "satList", "rrlp.satList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfSatElement", HFILL }},
{ &hf_rrlp_SeqOfSatElement_item,
{ "SatElement", "rrlp.SatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_iode,
{ "iode", "rrlp.iode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_239", HFILL }},
{ &hf_rrlp_udre,
{ "udre", "rrlp.udre",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_pseudoRangeCor,
{ "pseudoRangeCor", "rrlp.pseudoRangeCor",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2047_2047", HFILL }},
{ &hf_rrlp_rangeRateCor,
{ "rangeRateCor", "rrlp.rangeRateCor",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_127", HFILL }},
{ &hf_rrlp_deltaPseudoRangeCor2,
{ "deltaPseudoRangeCor2", "rrlp.deltaPseudoRangeCor2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_127", HFILL }},
{ &hf_rrlp_deltaRangeRateCor2,
{ "deltaRangeRateCor2", "rrlp.deltaRangeRateCor2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M7_7", HFILL }},
{ &hf_rrlp_deltaPseudoRangeCor3,
{ "deltaPseudoRangeCor3", "rrlp.deltaPseudoRangeCor3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_127", HFILL }},
{ &hf_rrlp_deltaRangeRateCor3,
{ "deltaRangeRateCor3", "rrlp.deltaRangeRateCor3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M7_7", HFILL }},
{ &hf_rrlp_navModelList,
{ "navModelList", "rrlp.navModelList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfNavModelElement", HFILL }},
{ &hf_rrlp_SeqOfNavModelElement_item,
{ "NavModelElement", "rrlp.NavModelElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_satStatus,
{ "satStatus", "rrlp.satStatus",
FT_UINT32, BASE_DEC, VALS(rrlp_SatStatus_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_newSatelliteAndModelUC,
{ "newSatelliteAndModelUC", "rrlp.newSatelliteAndModelUC_element",
FT_NONE, BASE_NONE, NULL, 0,
"UncompressedEphemeris", HFILL }},
{ &hf_rrlp_oldSatelliteAndModel,
{ "oldSatelliteAndModel", "rrlp.oldSatelliteAndModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_newNaviModelUC,
{ "newNaviModelUC", "rrlp.newNaviModelUC_element",
FT_NONE, BASE_NONE, NULL, 0,
"UncompressedEphemeris", HFILL }},
{ &hf_rrlp_ephemCodeOnL2,
{ "ephemCodeOnL2", "rrlp.ephemCodeOnL2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_ephemURA,
{ "ephemURA", "rrlp.ephemURA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_ephemSVhealth,
{ "ephemSVhealth", "rrlp.ephemSVhealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_ephemIODC,
{ "ephemIODC", "rrlp.ephemIODC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_rrlp_ephemL2Pflag,
{ "ephemL2Pflag", "rrlp.ephemL2Pflag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ephemSF1Rsvd,
{ "ephemSF1Rsvd", "rrlp.ephemSF1Rsvd_element",
FT_NONE, BASE_NONE, NULL, 0,
"EphemerisSubframe1Reserved", HFILL }},
{ &hf_rrlp_ephemTgd,
{ "ephemTgd", "rrlp.ephemTgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ephemToc,
{ "ephemToc", "rrlp.ephemToc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_37799", HFILL }},
{ &hf_rrlp_ephemAF2,
{ "ephemAF2", "rrlp.ephemAF2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ephemAF1,
{ "ephemAF1", "rrlp.ephemAF1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemAF0,
{ "ephemAF0", "rrlp.ephemAF0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_rrlp_ephemCrs,
{ "ephemCrs", "rrlp.ephemCrs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemDeltaN,
{ "ephemDeltaN", "rrlp.ephemDeltaN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemM0,
{ "ephemM0", "rrlp.ephemM0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_ephemCuc,
{ "ephemCuc", "rrlp.ephemCuc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemE,
{ "ephemE", "rrlp.ephemE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_ephemCus,
{ "ephemCus", "rrlp.ephemCus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemAPowerHalf,
{ "ephemAPowerHalf", "rrlp.ephemAPowerHalf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_ephemToe,
{ "ephemToe", "rrlp.ephemToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_37799", HFILL }},
{ &hf_rrlp_ephemFitFlag,
{ "ephemFitFlag", "rrlp.ephemFitFlag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ephemAODA,
{ "ephemAODA", "rrlp.ephemAODA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_ephemCic,
{ "ephemCic", "rrlp.ephemCic",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemOmegaA0,
{ "ephemOmegaA0", "rrlp.ephemOmegaA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_ephemCis,
{ "ephemCis", "rrlp.ephemCis",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemI0,
{ "ephemI0", "rrlp.ephemI0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_ephemCrc,
{ "ephemCrc", "rrlp.ephemCrc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_ephemW,
{ "ephemW", "rrlp.ephemW",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_ephemOmegaADot,
{ "ephemOmegaADot", "rrlp.ephemOmegaADot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_ephemIDot,
{ "ephemIDot", "rrlp.ephemIDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_rrlp_reserved1,
{ "reserved1", "rrlp.reserved1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_rrlp_reserved2,
{ "reserved2", "rrlp.reserved2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_rrlp_reserved3,
{ "reserved3", "rrlp.reserved3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_rrlp_reserved4,
{ "reserved4", "rrlp.reserved4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_alfa0,
{ "alfa0", "rrlp.alfa0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_alfa1,
{ "alfa1", "rrlp.alfa1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_alfa2,
{ "alfa2", "rrlp.alfa2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_alfa3,
{ "alfa3", "rrlp.alfa3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_beta0,
{ "beta0", "rrlp.beta0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_beta1,
{ "beta1", "rrlp.beta1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_beta2,
{ "beta2", "rrlp.beta2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_beta3,
{ "beta3", "rrlp.beta3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_utcA1,
{ "utcA1", "rrlp.utcA1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_utcA0,
{ "utcA0", "rrlp.utcA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_utcTot,
{ "utcTot", "rrlp.utcTot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_utcWNt,
{ "utcWNt", "rrlp.utcWNt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_utcDeltaTls,
{ "utcDeltaTls", "rrlp.utcDeltaTls",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_utcWNlsf,
{ "utcWNlsf", "rrlp.utcWNlsf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_utcDN,
{ "utcDN", "rrlp.utcDN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_utcDeltaTlsf,
{ "utcDeltaTlsf", "rrlp.utcDeltaTlsf",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_alamanacWNa,
{ "alamanacWNa", "rrlp.alamanacWNa",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_almanacList,
{ "almanacList", "rrlp.almanacList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfAlmanacElement", HFILL }},
{ &hf_rrlp_SeqOfAlmanacElement_item,
{ "AlmanacElement", "rrlp.AlmanacElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_almanacE,
{ "almanacE", "rrlp.almanacE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_alamanacToa,
{ "alamanacToa", "rrlp.alamanacToa",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_almanacKsii,
{ "almanacKsii", "rrlp.almanacKsii",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_almanacOmegaDot,
{ "almanacOmegaDot", "rrlp.almanacOmegaDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_almanacSVhealth,
{ "almanacSVhealth", "rrlp.almanacSVhealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_almanacAPowerHalf,
{ "almanacAPowerHalf", "rrlp.almanacAPowerHalf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_rrlp_almanacOmega0,
{ "almanacOmega0", "rrlp.almanacOmega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_almanacW,
{ "almanacW", "rrlp.almanacW",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_almanacM0,
{ "almanacM0", "rrlp.almanacM0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_almanacAF0,
{ "almanacAF0", "rrlp.almanacAF0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_almanacAF1,
{ "almanacAF1", "rrlp.almanacAF1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_timeRelation,
{ "timeRelation", "rrlp.timeRelation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_acquisList,
{ "acquisList", "rrlp.acquisList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfAcquisElement", HFILL }},
{ &hf_rrlp_SeqOfAcquisElement_item,
{ "AcquisElement", "rrlp.AcquisElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsTOW_03,
{ "gpsTOW", "rrlp.gpsTOW",
FT_UINT32, BASE_DEC, NULL, 0,
"GPSTOW23b", HFILL }},
{ &hf_rrlp_svid,
{ "svid", "rrlp.svid",
FT_UINT32, BASE_DEC, NULL, 0,
"SatelliteID", HFILL }},
{ &hf_rrlp_doppler0,
{ "doppler0", "rrlp.doppler0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2048_2047", HFILL }},
{ &hf_rrlp_addionalDoppler,
{ "addionalDoppler", "rrlp.addionalDoppler_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddionalDopplerFields", HFILL }},
{ &hf_rrlp_codePhase,
{ "codePhase", "rrlp.codePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1022", HFILL }},
{ &hf_rrlp_intCodePhase,
{ "intCodePhase", "rrlp.intCodePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_19", HFILL }},
{ &hf_rrlp_gpsBitNumber,
{ "gpsBitNumber", "rrlp.gpsBitNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_codePhaseSearchWindow,
{ "codePhaseSearchWindow", "rrlp.codePhaseSearchWindow",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_addionalAngle,
{ "addionalAngle", "rrlp.addionalAngle_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddionalAngleFields", HFILL }},
{ &hf_rrlp_doppler1,
{ "doppler1", "rrlp.doppler1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_dopplerUncertainty,
{ "dopplerUncertainty", "rrlp.dopplerUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_azimuth,
{ "azimuth", "rrlp.azimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_elevation,
{ "elevation", "rrlp.elevation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_SeqOf_BadSatelliteSet_item,
{ "SatelliteID", "rrlp.SatelliteID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_rel98_Ext_ExpOTD,
{ "rel98-Ext-ExpOTD", "rrlp.rel98_Ext_ExpOTD_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsTimeAssistanceMeasurementRequest,
{ "gpsTimeAssistanceMeasurementRequest", "rrlp.gpsTimeAssistanceMeasurementRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsReferenceTimeUncertainty,
{ "gpsReferenceTimeUncertainty", "rrlp.gpsReferenceTimeUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_msrAssistData_R98_ExpOTD,
{ "msrAssistData-R98-ExpOTD", "rrlp.msrAssistData_R98_ExpOTD_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_systemInfoAssistData_R98_ExpOTD,
{ "systemInfoAssistData-R98-ExpOTD", "rrlp.systemInfoAssistData_R98_ExpOTD_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_msrAssistList_R98_ExpOTD,
{ "msrAssistList-R98-ExpOTD", "rrlp.msrAssistList_R98_ExpOTD",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfMsrAssistBTS_R98_ExpOTD", HFILL }},
{ &hf_rrlp_SeqOfMsrAssistBTS_R98_ExpOTD_item,
{ "MsrAssistBTS-R98-ExpOTD", "rrlp.MsrAssistBTS_R98_ExpOTD_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_expectedOTD,
{ "expectedOTD", "rrlp.expectedOTD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_expOTDUncertainty,
{ "expOTDUncertainty", "rrlp.expOTDUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_systemInfoAssistListR98_ExpOTD,
{ "systemInfoAssistListR98-ExpOTD", "rrlp.systemInfoAssistListR98_ExpOTD",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfSystemInfoAssistBTS_R98_ExpOTD", HFILL }},
{ &hf_rrlp_SeqOfSystemInfoAssistBTS_R98_ExpOTD_item,
{ "SystemInfoAssistBTS-R98-ExpOTD", "rrlp.SystemInfoAssistBTS_R98_ExpOTD",
FT_UINT32, BASE_DEC, VALS(rrlp_SystemInfoAssistBTS_R98_ExpOTD_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_present_01,
{ "present", "rrlp.present_element",
FT_NONE, BASE_NONE, NULL, 0,
"AssistBTSData_R98_ExpOTD", HFILL }},
{ &hf_rrlp_expOTDuncertainty,
{ "expOTDuncertainty", "rrlp.expOTDuncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceFrameMSB,
{ "referenceFrameMSB", "rrlp.referenceFrameMSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_gpsTowSubms,
{ "gpsTowSubms", "rrlp.gpsTowSubms",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9999", HFILL }},
{ &hf_rrlp_deltaTow,
{ "deltaTow", "rrlp.deltaTow",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_rrlp_rel_98_Ext_MeasureInfo,
{ "rel-98-Ext-MeasureInfo", "rrlp.rel_98_Ext_MeasureInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_rel_98_Ext_MeasureInfo", HFILL }},
{ &hf_rrlp_otd_MeasureInfo_R98_Ext,
{ "otd-MeasureInfo-R98-Ext", "rrlp.otd_MeasureInfo_R98_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_timeAssistanceMeasurements,
{ "timeAssistanceMeasurements", "rrlp.timeAssistanceMeasurements_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSTimeAssistanceMeasurements", HFILL }},
{ &hf_rrlp_otdMsrFirstSets_R98_Ext,
{ "otdMsrFirstSets-R98-Ext", "rrlp.otdMsrFirstSets_R98_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTD_MsrElementFirst_R98_Ext", HFILL }},
{ &hf_rrlp_otd_FirstSetMsrs_R98_Ext,
{ "otd-FirstSetMsrs-R98-Ext", "rrlp.otd_FirstSetMsrs_R98_Ext",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfOTD_FirstSetMsrs_R98_Ext", HFILL }},
{ &hf_rrlp_SeqOfOTD_FirstSetMsrs_R98_Ext_item,
{ "OTD-FirstSetMsrs", "rrlp.OTD_FirstSetMsrs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_otd_MeasureInfo_5_Ext,
{ "otd-MeasureInfo-5-Ext", "rrlp.otd_MeasureInfo_5_Ext",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ulPseudoSegInd,
{ "ulPseudoSegInd", "rrlp.ulPseudoSegInd",
FT_UINT32, BASE_DEC, VALS(rrlp_UlPseudoSegInd_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_smlc_code,
{ "smlc-code", "rrlp.smlc_code",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_transaction_ID,
{ "transaction-ID", "rrlp.transaction_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_262143", HFILL }},
{ &hf_rrlp_velocityRequested,
{ "velocityRequested", "rrlp.velocityRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssPositionMethod,
{ "ganssPositionMethod", "rrlp.ganssPositionMethod",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSPositioningMethod", HFILL }},
{ &hf_rrlp_ganss_AssistData,
{ "ganss-AssistData", "rrlp.ganss_AssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssCarrierPhaseMeasurementRequest,
{ "ganssCarrierPhaseMeasurementRequest", "rrlp.ganssCarrierPhaseMeasurementRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTODGSMTimeAssociationMeasurementRequest,
{ "ganssTODGSMTimeAssociationMeasurementRequest", "rrlp.ganssTODGSMTimeAssociationMeasurementRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_requiredResponseTime,
{ "requiredResponseTime", "rrlp.requiredResponseTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_add_GPS_AssistData,
{ "add-GPS-AssistData", "rrlp.add_GPS_AssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssMultiFreqMeasurementRequest,
{ "ganssMultiFreqMeasurementRequest", "rrlp.ganssMultiFreqMeasurementRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganss_controlHeader,
{ "ganss-controlHeader", "rrlp.ganss_controlHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssCommonAssistData,
{ "ganssCommonAssistData", "rrlp.ganssCommonAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssGenericAssistDataList,
{ "ganssGenericAssistDataList", "rrlp.ganssGenericAssistDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSGenericAssistDataElement", HFILL }},
{ &hf_rrlp_ganssReferenceTime,
{ "ganssReferenceTime", "rrlp.ganssReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssRefLocation,
{ "ganssRefLocation", "rrlp.ganssRefLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssIonosphericModel,
{ "ganssIonosphericModel", "rrlp.ganssIonosphericModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssAddIonosphericModel,
{ "ganssAddIonosphericModel", "rrlp.ganssAddIonosphericModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssEarthOrientParam,
{ "ganssEarthOrientParam", "rrlp.ganssEarthOrientParam_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssReferenceTime_R10_Ext,
{ "ganssReferenceTime-R10-Ext", "rrlp.ganssReferenceTime_R10_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_SeqOfGANSSGenericAssistDataElement_item,
{ "GANSSGenericAssistDataElement", "rrlp.GANSSGenericAssistDataElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssID,
{ "ganssID", "rrlp.ganssID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_ganssTimeModel,
{ "ganssTimeModel", "rrlp.ganssTimeModel",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSTimeModel", HFILL }},
{ &hf_rrlp_ganssDiffCorrections,
{ "ganssDiffCorrections", "rrlp.ganssDiffCorrections_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssNavigationModel,
{ "ganssNavigationModel", "rrlp.ganssNavigationModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSNavModel", HFILL }},
{ &hf_rrlp_ganssRealTimeIntegrity,
{ "ganssRealTimeIntegrity", "rrlp.ganssRealTimeIntegrity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssDataBitAssist,
{ "ganssDataBitAssist", "rrlp.ganssDataBitAssist_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssRefMeasurementAssist,
{ "ganssRefMeasurementAssist", "rrlp.ganssRefMeasurementAssist_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssAlmanacModel,
{ "ganssAlmanacModel", "rrlp.ganssAlmanacModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssUTCModel,
{ "ganssUTCModel", "rrlp.ganssUTCModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssEphemerisExtension,
{ "ganssEphemerisExtension", "rrlp.ganssEphemerisExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssEphemerisExtCheck,
{ "ganssEphemerisExtCheck", "rrlp.ganssEphemerisExtCheck_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisExtensionCheck", HFILL }},
{ &hf_rrlp_sbasID,
{ "sbasID", "rrlp.sbasID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_ganssAddUTCModel,
{ "ganssAddUTCModel", "rrlp.ganssAddUTCModel",
FT_UINT32, BASE_DEC, VALS(rrlp_GANSSAddUTCModel_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_ganssAuxiliaryInfo,
{ "ganssAuxiliaryInfo", "rrlp.ganssAuxiliaryInfo",
FT_UINT32, BASE_DEC, VALS(rrlp_GANSSAuxiliaryInformation_vals), 0,
"GANSSAuxiliaryInformation", HFILL }},
{ &hf_rrlp_ganssDiffCorrectionsValidityPeriod,
{ "ganssDiffCorrectionsValidityPeriod", "rrlp.ganssDiffCorrectionsValidityPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTimeModel_R10_Ext,
{ "ganssTimeModel-R10-Ext", "rrlp.ganssTimeModel_R10_Ext",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSTimeModel_R10_Ext", HFILL }},
{ &hf_rrlp_ganssRefMeasurementAssist_R10_Ext,
{ "ganssRefMeasurementAssist-R10-Ext", "rrlp.ganssRefMeasurementAssist_R10_Ext",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssAlmanacModel_R10_Ext,
{ "ganssAlmanacModel-R10-Ext", "rrlp.ganssAlmanacModel_R10_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssRefTimeInfo,
{ "ganssRefTimeInfo", "rrlp.ganssRefTimeInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTOD_GSMTimeAssociation,
{ "ganssTOD-GSMTimeAssociation", "rrlp.ganssTOD_GSMTimeAssociation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssDay,
{ "ganssDay", "rrlp.ganssDay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_rrlp_ganssTOD,
{ "ganssTOD", "rrlp.ganssTOD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTODUncertainty,
{ "ganssTODUncertainty", "rrlp.ganssTODUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTimeID,
{ "ganssTimeID", "rrlp.ganssTimeID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_ganssDayCycleNumber,
{ "ganssDayCycleNumber", "rrlp.ganssDayCycleNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_frameDrift,
{ "frameDrift", "rrlp.frameDrift",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssIonoModel,
{ "ganssIonoModel", "rrlp.ganssIonoModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSIonosphereModel", HFILL }},
{ &hf_rrlp_ganssIonoStormFlags,
{ "ganssIonoStormFlags", "rrlp.ganssIonoStormFlags_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ai0,
{ "ai0", "rrlp.ai0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_rrlp_ai1,
{ "ai1", "rrlp.ai1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_rrlp_ai2,
{ "ai2", "rrlp.ai2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_rrlp_ionoStormFlag1,
{ "ionoStormFlag1", "rrlp.ionoStormFlag1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ionoStormFlag2,
{ "ionoStormFlag2", "rrlp.ionoStormFlag2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ionoStormFlag3,
{ "ionoStormFlag3", "rrlp.ionoStormFlag3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ionoStormFlag4,
{ "ionoStormFlag4", "rrlp.ionoStormFlag4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ionoStormFlag5,
{ "ionoStormFlag5", "rrlp.ionoStormFlag5",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_dataID,
{ "dataID", "rrlp.dataID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_rrlp_ionoModel,
{ "ionoModel", "rrlp.ionoModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"IonosphericModel", HFILL }},
{ &hf_rrlp_teop,
{ "teop", "rrlp.teop",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_pmX,
{ "pmX", "rrlp.pmX",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_rrlp_pmXdot,
{ "pmXdot", "rrlp.pmXdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_rrlp_pmY,
{ "pmY", "rrlp.pmY",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_rrlp_pmYdot,
{ "pmYdot", "rrlp.pmYdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_rrlp_deltaUT1,
{ "deltaUT1", "rrlp.deltaUT1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1073741824_1073741823", HFILL }},
{ &hf_rrlp_deltaUT1dot,
{ "deltaUT1dot", "rrlp.deltaUT1dot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M262144_262143", HFILL }},
{ &hf_rrlp_SeqOfGANSSTimeModel_item,
{ "GANSSTimeModelElement", "rrlp.GANSSTimeModelElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTimeModelRefTime,
{ "ganssTimeModelRefTime", "rrlp.ganssTimeModelRefTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_tA0,
{ "tA0", "rrlp.tA0",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_tA1,
{ "tA1", "rrlp.tA1",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_tA2,
{ "tA2", "rrlp.tA2",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gnssTOID,
{ "gnssTOID", "rrlp.gnssTOID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_weekNumber,
{ "weekNumber", "rrlp.weekNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_rrlp_SeqOfGANSSTimeModel_R10_Ext_item,
{ "GANSSTimeModelElement-R10-Ext", "rrlp.GANSSTimeModelElement_R10_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_deltaT,
{ "deltaT", "rrlp.deltaT",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_dganssRefTime,
{ "dganssRefTime", "rrlp.dganssRefTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_119", HFILL }},
{ &hf_rrlp_sgnTypeList,
{ "sgnTypeList", "rrlp.sgnTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfSgnTypeElement", HFILL }},
{ &hf_rrlp_SeqOfSgnTypeElement_item,
{ "SgnTypeElement", "rrlp.SgnTypeElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssSignalID,
{ "ganssSignalID", "rrlp.ganssSignalID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssStatusHealth,
{ "ganssStatusHealth", "rrlp.ganssStatusHealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_dganssSgnList,
{ "dganssSgnList", "rrlp.dganssSgnList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfDGANSSSgnElement", HFILL }},
{ &hf_rrlp_SeqOfDGANSSSgnElement_item,
{ "DGANSSSgnElement", "rrlp.DGANSSSgnElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_svID,
{ "svID", "rrlp.svID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_iod,
{ "iod", "rrlp.iod",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_rrlp_nonBroadcastIndFlag,
{ "nonBroadcastIndFlag", "rrlp.nonBroadcastIndFlag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_ganssSatelliteList,
{ "ganssSatelliteList", "rrlp.ganssSatelliteList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSSatelliteElement", HFILL }},
{ &hf_rrlp_SeqOfGANSSSatelliteElement_item,
{ "GANSSSatelliteElement", "rrlp.GANSSSatelliteElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_svHealth,
{ "svHealth", "rrlp.svHealth",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_rrlp_ganssClockModel,
{ "ganssClockModel", "rrlp.ganssClockModel",
FT_UINT32, BASE_DEC, VALS(rrlp_GANSSClockModel_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_ganssOrbitModel,
{ "ganssOrbitModel", "rrlp.ganssOrbitModel",
FT_UINT32, BASE_DEC, VALS(rrlp_GANSSOrbitModel_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_svHealthMSB,
{ "svHealthMSB", "rrlp.svHealthMSB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1", HFILL }},
{ &hf_rrlp_iodMSB,
{ "iodMSB", "rrlp.iodMSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_keplerianSet,
{ "keplerianSet", "rrlp.keplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_KeplerianSet", HFILL }},
{ &hf_rrlp_navKeplerianSet,
{ "navKeplerianSet", "rrlp.navKeplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_NAVKeplerianSet", HFILL }},
{ &hf_rrlp_cnavKeplerianSet,
{ "cnavKeplerianSet", "rrlp.cnavKeplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_CNAVKeplerianSet", HFILL }},
{ &hf_rrlp_glonassECEF,
{ "glonassECEF", "rrlp.glonassECEF_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_GLONASSecef", HFILL }},
{ &hf_rrlp_sbasECEF,
{ "sbasECEF", "rrlp.sbasECEF_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_SBASecef", HFILL }},
{ &hf_rrlp_keplerToe,
{ "keplerToe", "rrlp.keplerToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_rrlp_keplerW,
{ "keplerW", "rrlp.keplerW",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_keplerDeltaN,
{ "keplerDeltaN", "rrlp.keplerDeltaN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerM0,
{ "keplerM0", "rrlp.keplerM0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_keplerOmegaDot,
{ "keplerOmegaDot", "rrlp.keplerOmegaDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_keplerE,
{ "keplerE", "rrlp.keplerE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_keplerIDot,
{ "keplerIDot", "rrlp.keplerIDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_rrlp_keplerAPowerHalf,
{ "keplerAPowerHalf", "rrlp.keplerAPowerHalf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_keplerI0,
{ "keplerI0", "rrlp.keplerI0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_keplerOmega0,
{ "keplerOmega0", "rrlp.keplerOmega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_keplerCrs,
{ "keplerCrs", "rrlp.keplerCrs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerCis,
{ "keplerCis", "rrlp.keplerCis",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerCus,
{ "keplerCus", "rrlp.keplerCus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerCrc,
{ "keplerCrc", "rrlp.keplerCrc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerCic,
{ "keplerCic", "rrlp.keplerCic",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_keplerCuc,
{ "keplerCuc", "rrlp.keplerCuc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navURA,
{ "navURA", "rrlp.navURA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_navFitFlag,
{ "navFitFlag", "rrlp.navFitFlag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_navToe,
{ "navToe", "rrlp.navToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_37799", HFILL }},
{ &hf_rrlp_navOmega,
{ "navOmega", "rrlp.navOmega",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_navDeltaN,
{ "navDeltaN", "rrlp.navDeltaN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navM0,
{ "navM0", "rrlp.navM0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_navOmegaADot,
{ "navOmegaADot", "rrlp.navOmegaADot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_navE,
{ "navE", "rrlp.navE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_navIDot,
{ "navIDot", "rrlp.navIDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_rrlp_navAPowerHalf,
{ "navAPowerHalf", "rrlp.navAPowerHalf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_rrlp_navI0,
{ "navI0", "rrlp.navI0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_navOmegaA0,
{ "navOmegaA0", "rrlp.navOmegaA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_navCrs,
{ "navCrs", "rrlp.navCrs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navCis,
{ "navCis", "rrlp.navCis",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navCus,
{ "navCus", "rrlp.navCus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navCrc,
{ "navCrc", "rrlp.navCrc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navCic,
{ "navCic", "rrlp.navCic",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navCuc,
{ "navCuc", "rrlp.navCuc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_cnavTop,
{ "cnavTop", "rrlp.cnavTop",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2015", HFILL }},
{ &hf_rrlp_cnavURAindex,
{ "cnavURAindex", "rrlp.cnavURAindex",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_cnavDeltaA,
{ "cnavDeltaA", "rrlp.cnavDeltaA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M33554432_33554431", HFILL }},
{ &hf_rrlp_cnavAdot,
{ "cnavAdot", "rrlp.cnavAdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16777216_16777215", HFILL }},
{ &hf_rrlp_cnavDeltaNo,
{ "cnavDeltaNo", "rrlp.cnavDeltaNo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_rrlp_cnavDeltaNoDot,
{ "cnavDeltaNoDot", "rrlp.cnavDeltaNoDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4194304_4194303", HFILL }},
{ &hf_rrlp_cnavMo,
{ "cnavMo", "rrlp.cnavMo",
FT_INT64, BASE_DEC, NULL, 0,
"INTEGER_M4294967296_4294967295", HFILL }},
{ &hf_rrlp_cnavE,
{ "cnavE", "rrlp.cnavE",
FT_UINT64, BASE_DEC, NULL, 0,
"INTEGER_0_8589934591", HFILL }},
{ &hf_rrlp_cnavOmega,
{ "cnavOmega", "rrlp.cnavOmega",
FT_INT64, BASE_DEC, NULL, 0,
"INTEGER_M4294967296_4294967295", HFILL }},
{ &hf_rrlp_cnavOMEGA0,
{ "cnavOMEGA0", "rrlp.cnavOMEGA0",
FT_INT64, BASE_DEC, NULL, 0,
"INTEGER_M4294967296_4294967295", HFILL }},
{ &hf_rrlp_cnavDeltaOmegaDot,
{ "cnavDeltaOmegaDot", "rrlp.cnavDeltaOmegaDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_rrlp_cnavIo,
{ "cnavIo", "rrlp.cnavIo",
FT_INT64, BASE_DEC, NULL, 0,
"INTEGER_M4294967296_4294967295", HFILL }},
{ &hf_rrlp_cnavIoDot,
{ "cnavIoDot", "rrlp.cnavIoDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_rrlp_cnavCis,
{ "cnavCis", "rrlp.cnavCis",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_cnavCic,
{ "cnavCic", "rrlp.cnavCic",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_cnavCrs,
{ "cnavCrs", "rrlp.cnavCrs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_cnavCrc,
{ "cnavCrc", "rrlp.cnavCrc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_cnavCus,
{ "cnavCus", "rrlp.cnavCus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_rrlp_cnavCuc,
{ "cnavCuc", "rrlp.cnavCuc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_rrlp_gloEn,
{ "gloEn", "rrlp.gloEn",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_gloP1,
{ "gloP1", "rrlp.gloP1",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_rrlp_gloP2,
{ "gloP2", "rrlp.gloP2",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_gloM,
{ "gloM", "rrlp.gloM",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_gloX,
{ "gloX", "rrlp.gloX",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_rrlp_gloXdot,
{ "gloXdot", "rrlp.gloXdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_gloXdotdot,
{ "gloXdotdot", "rrlp.gloXdotdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_gloY,
{ "gloY", "rrlp.gloY",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_rrlp_gloYdot,
{ "gloYdot", "rrlp.gloYdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_gloYdotdot,
{ "gloYdotdot", "rrlp.gloYdotdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_gloZ,
{ "gloZ", "rrlp.gloZ",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_rrlp_gloZdot,
{ "gloZdot", "rrlp.gloZdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_gloZdotdot,
{ "gloZdotdot", "rrlp.gloZdotdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_sbasTo,
{ "sbasTo", "rrlp.sbasTo",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_5399", HFILL }},
{ &hf_rrlp_sbasAccuracy,
{ "sbasAccuracy", "rrlp.sbasAccuracy",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_rrlp_sbasXg,
{ "sbasXg", "rrlp.sbasXg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M536870912_536870911", HFILL }},
{ &hf_rrlp_sbasYg,
{ "sbasYg", "rrlp.sbasYg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M536870912_536870911", HFILL }},
{ &hf_rrlp_sbasZg,
{ "sbasZg", "rrlp.sbasZg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16777216_16777215", HFILL }},
{ &hf_rrlp_sbasXgDot,
{ "sbasXgDot", "rrlp.sbasXgDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_rrlp_sbasYgDot,
{ "sbasYgDot", "rrlp.sbasYgDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_rrlp_sbasZgDot,
{ "sbasZgDot", "rrlp.sbasZgDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_rrlp_sbasXgDotDot,
{ "sbasXgDotDot", "rrlp.sbasXgDotDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_sbagYgDotDot,
{ "sbagYgDotDot", "rrlp.sbagYgDotDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_sbasZgDotDot,
{ "sbasZgDotDot", "rrlp.sbasZgDotDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_standardClockModelList,
{ "standardClockModelList", "rrlp.standardClockModelList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfStandardClockModelElement", HFILL }},
{ &hf_rrlp_navClockModel,
{ "navClockModel", "rrlp.navClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_cnavClockModel,
{ "cnavClockModel", "rrlp.cnavClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_glonassClockModel,
{ "glonassClockModel", "rrlp.glonassClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_sbasClockModel,
{ "sbasClockModel", "rrlp.sbasClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_SeqOfStandardClockModelElement_item,
{ "StandardClockModelElement", "rrlp.StandardClockModelElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_stanClockToc,
{ "stanClockToc", "rrlp.stanClockToc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_rrlp_stanClockAF2,
{ "stanClockAF2", "rrlp.stanClockAF2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2048_2047", HFILL }},
{ &hf_rrlp_stanClockAF1,
{ "stanClockAF1", "rrlp.stanClockAF1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_rrlp_stanClockAF0,
{ "stanClockAF0", "rrlp.stanClockAF0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M134217728_134217727", HFILL }},
{ &hf_rrlp_stanClockTgd,
{ "stanClockTgd", "rrlp.stanClockTgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_stanModelID,
{ "stanModelID", "rrlp.stanModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_navToc,
{ "navToc", "rrlp.navToc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_37799", HFILL }},
{ &hf_rrlp_navaf2,
{ "navaf2", "rrlp.navaf2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_navaf1,
{ "navaf1", "rrlp.navaf1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navaf0,
{ "navaf0", "rrlp.navaf0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_rrlp_navTgd,
{ "navTgd", "rrlp.navTgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_cnavToc,
{ "cnavToc", "rrlp.cnavToc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2015", HFILL }},
{ &hf_rrlp_cnavURA0,
{ "cnavURA0", "rrlp.cnavURA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_cnavURA1,
{ "cnavURA1", "rrlp.cnavURA1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_cnavURA2,
{ "cnavURA2", "rrlp.cnavURA2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_cnavAf2,
{ "cnavAf2", "rrlp.cnavAf2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_cnavAf1,
{ "cnavAf1", "rrlp.cnavAf1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M524288_524287", HFILL }},
{ &hf_rrlp_cnavAf0,
{ "cnavAf0", "rrlp.cnavAf0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M33554432_33554431", HFILL }},
{ &hf_rrlp_cnavTgd,
{ "cnavTgd", "rrlp.cnavTgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl1cp,
{ "cnavISCl1cp", "rrlp.cnavISCl1cp",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl1cd,
{ "cnavISCl1cd", "rrlp.cnavISCl1cd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl1ca,
{ "cnavISCl1ca", "rrlp.cnavISCl1ca",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl2c,
{ "cnavISCl2c", "rrlp.cnavISCl2c",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl5i5,
{ "cnavISCl5i5", "rrlp.cnavISCl5i5",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_cnavISCl5q5,
{ "cnavISCl5q5", "rrlp.cnavISCl5q5",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_gloTau,
{ "gloTau", "rrlp.gloTau",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_rrlp_gloGamma,
{ "gloGamma", "rrlp.gloGamma",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_gloDeltaTau,
{ "gloDeltaTau", "rrlp.gloDeltaTau",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_sbasAgfo,
{ "sbasAgfo", "rrlp.sbasAgfo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2048_2047", HFILL }},
{ &hf_rrlp_sbasAgf1,
{ "sbasAgf1", "rrlp.sbasAgf1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ganssBadSignalList,
{ "ganssBadSignalList", "rrlp.ganssBadSignalList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfBadSignalElement", HFILL }},
{ &hf_rrlp_SeqOfBadSignalElement_item,
{ "BadSignalElement", "rrlp.BadSignalElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_badSVID,
{ "badSVID", "rrlp.badSVID",
FT_UINT32, BASE_DEC, NULL, 0,
"SVID", HFILL }},
{ &hf_rrlp_badSignalID,
{ "badSignalID", "rrlp.badSignalID",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSSignals", HFILL }},
{ &hf_rrlp_ganssTOD_01,
{ "ganssTOD", "rrlp.ganssTOD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_59", HFILL }},
{ &hf_rrlp_ganssDataBitsSatList,
{ "ganssDataBitsSatList", "rrlp.ganssDataBitsSatList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGanssDataBitsElement", HFILL }},
{ &hf_rrlp_SeqOfGanssDataBitsElement_item,
{ "GanssDataBitsElement", "rrlp.GanssDataBitsElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssDataBitsSgnList,
{ "ganssDataBitsSgnList", "rrlp.ganssDataBitsSgnList",
FT_UINT32, BASE_DEC, NULL, 0,
"Seq_OfGANSSDataBitsSgn", HFILL }},
{ &hf_rrlp_Seq_OfGANSSDataBitsSgn_item,
{ "GANSSDataBitsSgnElement", "rrlp.GANSSDataBitsSgnElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssSignalType,
{ "ganssSignalType", "rrlp.ganssSignalType",
FT_UINT32, BASE_DEC, NULL, 0,
"GANSSSignalID", HFILL }},
{ &hf_rrlp_ganssDataBits,
{ "ganssDataBits", "rrlp.ganssDataBits",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOf_GANSSDataBits", HFILL }},
{ &hf_rrlp_SeqOf_GANSSDataBits_item,
{ "GANSSDataBit", "rrlp.GANSSDataBit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssRefMeasAssistList,
{ "ganssRefMeasAssistList", "rrlp.ganssRefMeasAssistList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSRefMeasurementElement", HFILL }},
{ &hf_rrlp_SeqOfGANSSRefMeasurementElement_item,
{ "GANSSRefMeasurementElement", "rrlp.GANSSRefMeasurementElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_additionalDoppler,
{ "additionalDoppler", "rrlp.additionalDoppler_element",
FT_NONE, BASE_NONE, NULL, 0,
"AdditionalDopplerFields", HFILL }},
{ &hf_rrlp_intCodePhase_01,
{ "intCodePhase", "rrlp.intCodePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_rrlp_codePhaseSearchWindow_01,
{ "codePhaseSearchWindow", "rrlp.codePhaseSearchWindow",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_additionalAngle,
{ "additionalAngle", "rrlp.additionalAngle_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddionalAngleFields", HFILL }},
{ &hf_rrlp_dopplerUncertainty_01,
{ "dopplerUncertainty", "rrlp.dopplerUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4", HFILL }},
{ &hf_rrlp_GANSSRefMeasurementAssist_R10_Ext_item,
{ "GANSSRefMeasurement-R10-Ext-Element", "rrlp.GANSSRefMeasurement_R10_Ext_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_azimuthLSB,
{ "azimuthLSB", "rrlp.azimuthLSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_elevationLSB,
{ "elevationLSB", "rrlp.elevationLSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_weekNumber_01,
{ "weekNumber", "rrlp.weekNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_toa,
{ "toa", "rrlp.toa",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_ioda,
{ "ioda", "rrlp.ioda",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_ganssAlmanacList,
{ "ganssAlmanacList", "rrlp.ganssAlmanacList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSAlmanacElement", HFILL }},
{ &hf_rrlp_SeqOfGANSSAlmanacElement_item,
{ "GANSSAlmanacElement", "rrlp.GANSSAlmanacElement",
FT_UINT32, BASE_DEC, VALS(rrlp_GANSSAlmanacElement_vals), 0,
NULL, HFILL }},
{ &hf_rrlp_keplerianAlmanacSet,
{ "keplerianAlmanacSet", "rrlp.keplerianAlmanacSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_KeplerianSet", HFILL }},
{ &hf_rrlp_keplerianNAVAlmanac,
{ "keplerianNAVAlmanac", "rrlp.keplerianNAVAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_NAVKeplerianSet", HFILL }},
{ &hf_rrlp_keplerianReducedAlmanac,
{ "keplerianReducedAlmanac", "rrlp.keplerianReducedAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_ReducedKeplerianSet", HFILL }},
{ &hf_rrlp_keplerianMidiAlmanac,
{ "keplerianMidiAlmanac", "rrlp.keplerianMidiAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_MidiAlmanacSet", HFILL }},
{ &hf_rrlp_keplerianGLONASS,
{ "keplerianGLONASS", "rrlp.keplerianGLONASS_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_GlonassAlmanacSet", HFILL }},
{ &hf_rrlp_ecefSBASAlmanac,
{ "ecefSBASAlmanac", "rrlp.ecefSBASAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"Almanac_ECEFsbasAlmanacSet", HFILL }},
{ &hf_rrlp_kepAlmanacE,
{ "kepAlmanacE", "rrlp.kepAlmanacE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_rrlp_kepAlmanacDeltaI,
{ "kepAlmanacDeltaI", "rrlp.kepAlmanacDeltaI",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_kepAlmanacOmegaDot,
{ "kepAlmanacOmegaDot", "rrlp.kepAlmanacOmegaDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_kepSVHealth,
{ "kepSVHealth", "rrlp.kepSVHealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_rrlp_kepAlmanacAPowerHalf,
{ "kepAlmanacAPowerHalf", "rrlp.kepAlmanacAPowerHalf",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_rrlp_kepAlmanacOmega0,
{ "kepAlmanacOmega0", "rrlp.kepAlmanacOmega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_kepAlmanacW,
{ "kepAlmanacW", "rrlp.kepAlmanacW",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_kepAlmanacM0,
{ "kepAlmanacM0", "rrlp.kepAlmanacM0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_kepAlmanacAF0,
{ "kepAlmanacAF0", "rrlp.kepAlmanacAF0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_rrlp_kepAlmanacAF1,
{ "kepAlmanacAF1", "rrlp.kepAlmanacAF1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_navAlmE,
{ "navAlmE", "rrlp.navAlmE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_navAlmDeltaI,
{ "navAlmDeltaI", "rrlp.navAlmDeltaI",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navAlmOMEGADOT,
{ "navAlmOMEGADOT", "rrlp.navAlmOMEGADOT",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_navAlmSVHealth,
{ "navAlmSVHealth", "rrlp.navAlmSVHealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_navAlmSqrtA,
{ "navAlmSqrtA", "rrlp.navAlmSqrtA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_rrlp_navAlmOMEGAo,
{ "navAlmOMEGAo", "rrlp.navAlmOMEGAo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_navAlmOmega,
{ "navAlmOmega", "rrlp.navAlmOmega",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_navAlmMo,
{ "navAlmMo", "rrlp.navAlmMo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_navAlmaf0,
{ "navAlmaf0", "rrlp.navAlmaf0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_navAlmaf1,
{ "navAlmaf1", "rrlp.navAlmaf1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_redAlmDeltaA,
{ "redAlmDeltaA", "rrlp.redAlmDeltaA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_redAlmOmega0,
{ "redAlmOmega0", "rrlp.redAlmOmega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_rrlp_redAlmPhi0,
{ "redAlmPhi0", "rrlp.redAlmPhi0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_rrlp_redAlmL1Health,
{ "redAlmL1Health", "rrlp.redAlmL1Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_redAlmL2Health,
{ "redAlmL2Health", "rrlp.redAlmL2Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_redAlmL5Health,
{ "redAlmL5Health", "rrlp.redAlmL5Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_midiAlmE,
{ "midiAlmE", "rrlp.midiAlmE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_rrlp_midiAlmDeltaI,
{ "midiAlmDeltaI", "rrlp.midiAlmDeltaI",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_midiAlmOmegaDot,
{ "midiAlmOmegaDot", "rrlp.midiAlmOmegaDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_midiAlmSqrtA,
{ "midiAlmSqrtA", "rrlp.midiAlmSqrtA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_131071", HFILL }},
{ &hf_rrlp_midiAlmOmega0,
{ "midiAlmOmega0", "rrlp.midiAlmOmega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_midiAlmOmega,
{ "midiAlmOmega", "rrlp.midiAlmOmega",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_midiAlmMo,
{ "midiAlmMo", "rrlp.midiAlmMo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_midiAlmaf0,
{ "midiAlmaf0", "rrlp.midiAlmaf0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_midiAlmaf1,
{ "midiAlmaf1", "rrlp.midiAlmaf1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_midiAlmL1Health,
{ "midiAlmL1Health", "rrlp.midiAlmL1Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_midiAlmL2Health,
{ "midiAlmL2Health", "rrlp.midiAlmL2Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_midiAlmL5Health,
{ "midiAlmL5Health", "rrlp.midiAlmL5Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_gloAlmNA,
{ "gloAlmNA", "rrlp.gloAlmNA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1461", HFILL }},
{ &hf_rrlp_gloAlmnA,
{ "gloAlmnA", "rrlp.gloAlmnA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_24", HFILL }},
{ &hf_rrlp_gloAlmHA,
{ "gloAlmHA", "rrlp.gloAlmHA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_rrlp_gloAlmLambdaA,
{ "gloAlmLambdaA", "rrlp.gloAlmLambdaA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_rrlp_gloAlmtlambdaA,
{ "gloAlmtlambdaA", "rrlp.gloAlmtlambdaA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2097151", HFILL }},
{ &hf_rrlp_gloAlmDeltaIa,
{ "gloAlmDeltaIa", "rrlp.gloAlmDeltaIa",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_rrlp_gloAlmDeltaTA,
{ "gloAlmDeltaTA", "rrlp.gloAlmDeltaTA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_rrlp_gloAlmDeltaTdotA,
{ "gloAlmDeltaTdotA", "rrlp.gloAlmDeltaTdotA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_rrlp_gloAlmEpsilonA,
{ "gloAlmEpsilonA", "rrlp.gloAlmEpsilonA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_rrlp_gloAlmOmegaA,
{ "gloAlmOmegaA", "rrlp.gloAlmOmegaA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_gloAlmTauA,
{ "gloAlmTauA", "rrlp.gloAlmTauA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_gloAlmCA,
{ "gloAlmCA", "rrlp.gloAlmCA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_gloAlmMA,
{ "gloAlmMA", "rrlp.gloAlmMA",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_rrlp_sbasAlmDataID,
{ "sbasAlmDataID", "rrlp.sbasAlmDataID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_sbasAlmHealth,
{ "sbasAlmHealth", "rrlp.sbasAlmHealth",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_rrlp_sbasAlmXg,
{ "sbasAlmXg", "rrlp.sbasAlmXg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_rrlp_sbasAlmYg,
{ "sbasAlmYg", "rrlp.sbasAlmYg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_rrlp_sbasAlmZg,
{ "sbasAlmZg", "rrlp.sbasAlmZg",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M256_255", HFILL }},
{ &hf_rrlp_sbasAlmXgdot,
{ "sbasAlmXgdot", "rrlp.sbasAlmXgdot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4_3", HFILL }},
{ &hf_rrlp_sbasAlmYgDot,
{ "sbasAlmYgDot", "rrlp.sbasAlmYgDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4_3", HFILL }},
{ &hf_rrlp_sbasAlmZgDot,
{ "sbasAlmZgDot", "rrlp.sbasAlmZgDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8_7", HFILL }},
{ &hf_rrlp_sbasAlmTo,
{ "sbasAlmTo", "rrlp.sbasAlmTo",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_rrlp_completeAlmanacProvided,
{ "completeAlmanacProvided", "rrlp.completeAlmanacProvided",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rrlp_ganssUtcA1,
{ "ganssUtcA1", "rrlp.ganssUtcA1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_ganssUtcA0,
{ "ganssUtcA0", "rrlp.ganssUtcA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_ganssUtcTot,
{ "ganssUtcTot", "rrlp.ganssUtcTot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_ganssUtcWNt,
{ "ganssUtcWNt", "rrlp.ganssUtcWNt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_ganssUtcDeltaTls,
{ "ganssUtcDeltaTls", "rrlp.ganssUtcDeltaTls",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ganssUtcWNlsf,
{ "ganssUtcWNlsf", "rrlp.ganssUtcWNlsf",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_rrlp_ganssUtcDN,
{ "ganssUtcDN", "rrlp.ganssUtcDN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ganssUtcDeltaTlsf,
{ "ganssUtcDeltaTlsf", "rrlp.ganssUtcDeltaTlsf",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_ganssEphemerisHeader,
{ "ganssEphemerisHeader", "rrlp.ganssEphemerisHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisExtensionHeader", HFILL }},
{ &hf_rrlp_ganssReferenceSet,
{ "ganssReferenceSet", "rrlp.ganssReferenceSet",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSSRefOrbit", HFILL }},
{ &hf_rrlp_ganssephemerisDeltasMatrix,
{ "ganssephemerisDeltasMatrix", "rrlp.ganssephemerisDeltasMatrix",
FT_UINT32, BASE_DEC, NULL, 0,
"GANSSEphemerisDeltaMatrix", HFILL }},
{ &hf_rrlp_timeAtEstimation,
{ "timeAtEstimation", "rrlp.timeAtEstimation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_validityPeriod,
{ "validityPeriod", "rrlp.validityPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_rrlp_ephemerisExtensionDuration,
{ "ephemerisExtensionDuration", "rrlp.ephemerisExtensionDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_512", HFILL }},
{ &hf_rrlp_ganssEphExtDay,
{ "ganssEphExtDay", "rrlp.ganssEphExtDay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_rrlp_ganssEphExtTOD,
{ "ganssEphExtTOD", "rrlp.ganssEphExtTOD",
FT_UINT32, BASE_DEC, NULL, 0,
"GANSSTOD", HFILL }},
{ &hf_rrlp_keplerToe_01,
{ "keplerToe", "rrlp.keplerToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_37799", HFILL }},
{ &hf_rrlp_SeqOfGANSSRefOrbit_item,
{ "GANSSReferenceOrbit", "rrlp.GANSSReferenceOrbit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssOrbitModel_01,
{ "ganssOrbitModel", "rrlp.ganssOrbitModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReferenceNavModel", HFILL }},
{ &hf_rrlp_GANSSEphemerisDeltaMatrix_item,
{ "GANSSEphemerisDeltaEpoch", "rrlp.GANSSEphemerisDeltaEpoch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssDeltaEpochHeader,
{ "ganssDeltaEpochHeader", "rrlp.ganssDeltaEpochHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssDeltaElementList,
{ "ganssDeltaElementList", "rrlp.ganssDeltaElementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ephemerisDeltaSizes,
{ "ephemerisDeltaSizes", "rrlp.ephemerisDeltaSizes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisDeltaBitSizes", HFILL }},
{ &hf_rrlp_ephemerisDeltaScales,
{ "ephemerisDeltaScales", "rrlp.ephemerisDeltaScales_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisDeltaScales", HFILL }},
{ &hf_rrlp_GANSSDeltaElementList_item,
{ "GANSSDeltaElementList item", "rrlp.GANSSDeltaElementList_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_49", HFILL }},
{ &hf_rrlp_bitsize_delta_omega,
{ "bitsize-delta-omega", "rrlp.bitsize_delta_omega",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_deltaN,
{ "bitsize-delta-deltaN", "rrlp.bitsize_delta_deltaN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_m0,
{ "bitsize-delta-m0", "rrlp.bitsize_delta_m0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_omegadot,
{ "bitsize-delta-omegadot", "rrlp.bitsize_delta_omegadot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_24", HFILL }},
{ &hf_rrlp_bitsize_delta_e,
{ "bitsize-delta-e", "rrlp.bitsize_delta_e",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_idot,
{ "bitsize-delta-idot", "rrlp.bitsize_delta_idot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_14", HFILL }},
{ &hf_rrlp_bitsize_delta_sqrtA,
{ "bitsize-delta-sqrtA", "rrlp.bitsize_delta_sqrtA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_i0,
{ "bitsize-delta-i0", "rrlp.bitsize_delta_i0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_omega0,
{ "bitsize-delta-omega0", "rrlp.bitsize_delta_omega0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_rrlp_bitsize_delta_crs,
{ "bitsize-delta-crs", "rrlp.bitsize_delta_crs",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_cis,
{ "bitsize-delta-cis", "rrlp.bitsize_delta_cis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_cus,
{ "bitsize-delta-cus", "rrlp.bitsize_delta_cus",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_crc,
{ "bitsize-delta-crc", "rrlp.bitsize_delta_crc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_cic,
{ "bitsize-delta-cic", "rrlp.bitsize_delta_cic",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_cuc,
{ "bitsize-delta-cuc", "rrlp.bitsize_delta_cuc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_rrlp_bitsize_delta_tgd1,
{ "bitsize-delta-tgd1", "rrlp.bitsize_delta_tgd1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_10", HFILL }},
{ &hf_rrlp_bitsize_delta_tgd2,
{ "bitsize-delta-tgd2", "rrlp.bitsize_delta_tgd2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_10", HFILL }},
{ &hf_rrlp_scale_delta_omega,
{ "scale-delta-omega", "rrlp.scale_delta_omega",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_deltaN,
{ "scale-delta-deltaN", "rrlp.scale_delta_deltaN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_m0,
{ "scale-delta-m0", "rrlp.scale_delta_m0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_omegadot,
{ "scale-delta-omegadot", "rrlp.scale_delta_omegadot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_e,
{ "scale-delta-e", "rrlp.scale_delta_e",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_idot,
{ "scale-delta-idot", "rrlp.scale_delta_idot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_sqrtA,
{ "scale-delta-sqrtA", "rrlp.scale_delta_sqrtA",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_i0,
{ "scale-delta-i0", "rrlp.scale_delta_i0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_omega0,
{ "scale-delta-omega0", "rrlp.scale_delta_omega0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_crs,
{ "scale-delta-crs", "rrlp.scale_delta_crs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_cis,
{ "scale-delta-cis", "rrlp.scale_delta_cis",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_cus,
{ "scale-delta-cus", "rrlp.scale_delta_cus",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_crc,
{ "scale-delta-crc", "rrlp.scale_delta_crc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_cic,
{ "scale-delta-cic", "rrlp.scale_delta_cic",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_cuc,
{ "scale-delta-cuc", "rrlp.scale_delta_cuc",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_tgd1,
{ "scale-delta-tgd1", "rrlp.scale_delta_tgd1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_scale_delta_tgd2,
{ "scale-delta-tgd2", "rrlp.scale_delta_tgd2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_ganssBeginTime,
{ "ganssBeginTime", "rrlp.ganssBeginTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_ganssEndTime,
{ "ganssEndTime", "rrlp.ganssEndTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_ganssSatEventsInfo,
{ "ganssSatEventsInfo", "rrlp.ganssSatEventsInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_eventOccured,
{ "eventOccured", "rrlp.eventOccured",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_64", HFILL }},
{ &hf_rrlp_futureEventNoted,
{ "futureEventNoted", "rrlp.futureEventNoted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_64", HFILL }},
{ &hf_rrlp_utcModel2,
{ "utcModel2", "rrlp.utcModel2_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTCmodelSet2", HFILL }},
{ &hf_rrlp_utcModel3,
{ "utcModel3", "rrlp.utcModel3_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTCmodelSet3", HFILL }},
{ &hf_rrlp_utcModel4,
{ "utcModel4", "rrlp.utcModel4_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTCmodelSet4", HFILL }},
{ &hf_rrlp_utcA0_01,
{ "utcA0", "rrlp.utcA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_utcA1_01,
{ "utcA1", "rrlp.utcA1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_rrlp_utcA2,
{ "utcA2", "rrlp.utcA2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_rrlp_utcTot_01,
{ "utcTot", "rrlp.utcTot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_utcWNot,
{ "utcWNot", "rrlp.utcWNot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_rrlp_utcDN_01,
{ "utcDN", "rrlp.utcDN",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_rrlp_nA,
{ "nA", "rrlp.nA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1461", HFILL }},
{ &hf_rrlp_tauC,
{ "tauC", "rrlp.tauC",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_b1,
{ "b1", "rrlp.b1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_rrlp_b2,
{ "b2", "rrlp.b2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_rrlp_kp,
{ "kp", "rrlp.kp",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_rrlp_utcA1wnt,
{ "utcA1wnt", "rrlp.utcA1wnt",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_rrlp_utcA0wnt,
{ "utcA0wnt", "rrlp.utcA0wnt",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_rrlp_utcStandardID,
{ "utcStandardID", "rrlp.utcStandardID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_ganssID1,
{ "ganssID1", "rrlp.ganssID1",
FT_UINT32, BASE_DEC, NULL, 0,
"GANSS_ID1", HFILL }},
{ &hf_rrlp_ganssID3,
{ "ganssID3", "rrlp.ganssID3",
FT_UINT32, BASE_DEC, NULL, 0,
"GANSS_ID3", HFILL }},
{ &hf_rrlp_GANSS_ID1_item,
{ "GANSS-ID1-element", "rrlp.GANSS_ID1_element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_signalsAvailable,
{ "signalsAvailable", "rrlp.signalsAvailable",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSSignals", HFILL }},
{ &hf_rrlp_GANSS_ID3_item,
{ "GANSS-ID3-element", "rrlp.GANSS_ID3_element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_channelNumber,
{ "channelNumber", "rrlp.channelNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M7_13", HFILL }},
{ &hf_rrlp_GANSSDiffCorrectionsValidityPeriod_item,
{ "DGANSSExtensionSgnTypeElement", "rrlp.DGANSSExtensionSgnTypeElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_dganssExtensionSgnList,
{ "dganssExtensionSgnList", "rrlp.dganssExtensionSgnList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfDGANSSExtensionSgnElement", HFILL }},
{ &hf_rrlp_SeqOfDGANSSExtensionSgnElement_item,
{ "DGANSSExtensionSgnElement", "rrlp.DGANSSExtensionSgnElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_udreGrowthRate,
{ "udreGrowthRate", "rrlp.udreGrowthRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_udreValidityTime,
{ "udreValidityTime", "rrlp.udreValidityTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_add_GPS_controlHeader,
{ "add-GPS-controlHeader", "rrlp.add_GPS_controlHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsEphemerisExtension,
{ "gpsEphemerisExtension", "rrlp.gpsEphemerisExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsEphemerisExtensionCheck,
{ "gpsEphemerisExtensionCheck", "rrlp.gpsEphemerisExtensionCheck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_dgpsCorrectionsValidityPeriod,
{ "dgpsCorrectionsValidityPeriod", "rrlp.dgpsCorrectionsValidityPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsReferenceTime_R10_Ext,
{ "gpsReferenceTime-R10-Ext", "rrlp.gpsReferenceTime_R10_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsAcquisAssist_R10_Ext,
{ "gpsAcquisAssist-R10-Ext", "rrlp.gpsAcquisAssist_R10_Ext",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsAlmanac_R10_Ext,
{ "gpsAlmanac-R10-Ext", "rrlp.gpsAlmanac_R10_Ext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_af2,
{ "af2", "rrlp.af2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_af1,
{ "af1", "rrlp.af1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_rrlp_af0,
{ "af0", "rrlp.af0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_rrlp_tgd,
{ "tgd", "rrlp.tgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_rrlp_gpsEphemerisHeader,
{ "gpsEphemerisHeader", "rrlp.gpsEphemerisHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisExtensionHeader", HFILL }},
{ &hf_rrlp_gpsReferenceSet,
{ "gpsReferenceSet", "rrlp.gpsReferenceSet",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGPSRefOrbit", HFILL }},
{ &hf_rrlp_gpsephemerisDeltaMatrix,
{ "gpsephemerisDeltaMatrix", "rrlp.gpsephemerisDeltaMatrix",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_timeofEstimation,
{ "timeofEstimation", "rrlp.timeofEstimation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_SeqOfGPSRefOrbit_item,
{ "GPSReferenceOrbit", "rrlp.GPSReferenceOrbit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsOrbitModel,
{ "gpsOrbitModel", "rrlp.gpsOrbitModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReferenceNavModel", HFILL }},
{ &hf_rrlp_gpsClockModel,
{ "gpsClockModel", "rrlp.gpsClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_GPSEphemerisDeltaMatrix_item,
{ "GPSEphemerisDeltaEpoch", "rrlp.GPSEphemerisDeltaEpoch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsDeltaEpochHeader,
{ "gpsDeltaEpochHeader", "rrlp.gpsDeltaEpochHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsDeltaElementList,
{ "gpsDeltaElementList", "rrlp.gpsDeltaElementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ephemerisDeltaSizes_01,
{ "ephemerisDeltaSizes", "rrlp.ephemerisDeltaSizes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisDeltaBitSizes", HFILL }},
{ &hf_rrlp_ephemerisDeltaScales_01,
{ "ephemerisDeltaScales", "rrlp.ephemerisDeltaScales_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisDeltaScales", HFILL }},
{ &hf_rrlp_GPSDeltaElementList_item,
{ "GPSDeltaElementList item", "rrlp.GPSDeltaElementList_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_47", HFILL }},
{ &hf_rrlp_bitsize_delta_tgd,
{ "bitsize-delta-tgd", "rrlp.bitsize_delta_tgd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_10", HFILL }},
{ &hf_rrlp_scale_delta_tgd,
{ "scale-delta-tgd", "rrlp.scale_delta_tgd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_rrlp_gpsBeginTime,
{ "gpsBeginTime", "rrlp.gpsBeginTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_gpsEndTime,
{ "gpsEndTime", "rrlp.gpsEndTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSEphemerisExtensionTime", HFILL }},
{ &hf_rrlp_gpsSatEventsInfo,
{ "gpsSatEventsInfo", "rrlp.gpsSatEventsInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_eventOccured_01,
{ "eventOccured", "rrlp.eventOccured",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_rrlp_futureEventNoted_01,
{ "futureEventNoted", "rrlp.futureEventNoted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_rrlp_DGPSCorrectionsValidityPeriod_item,
{ "DGPSExtensionSatElement", "rrlp.DGPSExtensionSatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsWeekCycleNumber,
{ "gpsWeekCycleNumber", "rrlp.gpsWeekCycleNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_rrlp_GPSAcquisAssist_R10_Ext_item,
{ "GPSAcquisAssist-R10-Ext-Element", "rrlp.GPSAcquisAssist_R10_Ext_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_velEstimate,
{ "velEstimate", "rrlp.velEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"VelocityEstimate", HFILL }},
{ &hf_rrlp_ganssLocationInfo,
{ "ganssLocationInfo", "rrlp.ganssLocationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssMeasureInfo,
{ "ganssMeasureInfo", "rrlp.ganssMeasureInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_referenceFrame,
{ "referenceFrame", "rrlp.referenceFrame_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTODm,
{ "ganssTODm", "rrlp.ganssTODm",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssTODFrac,
{ "ganssTODFrac", "rrlp.ganssTODFrac",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16384", HFILL }},
{ &hf_rrlp_posData,
{ "posData", "rrlp.posData",
FT_BYTES, BASE_NONE, NULL, 0,
"PositionData", HFILL }},
{ &hf_rrlp_stationaryIndication,
{ "stationaryIndication", "rrlp.stationaryIndication",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_rrlp_referenceFN,
{ "referenceFN", "rrlp.referenceFN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rrlp_referenceFNMSB,
{ "referenceFNMSB", "rrlp.referenceFNMSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_ganssMsrSetList,
{ "ganssMsrSetList", "rrlp.ganssMsrSetList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSS_MsrSetElement", HFILL }},
{ &hf_rrlp_SeqOfGANSS_MsrSetElement_item,
{ "GANSS-MsrSetElement", "rrlp.GANSS_MsrSetElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_deltaGANSSTOD,
{ "deltaGANSSTOD", "rrlp.deltaGANSSTOD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_rrlp_ganss_MsrElementList,
{ "ganss-MsrElementList", "rrlp.ganss_MsrElementList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSS_MsrElement", HFILL }},
{ &hf_rrlp_SeqOfGANSS_MsrElement_item,
{ "GANSS-MsrElement", "rrlp.GANSS_MsrElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganss_SgnTypeList,
{ "ganss-SgnTypeList", "rrlp.ganss_SgnTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSS_SgnTypeElement", HFILL }},
{ &hf_rrlp_SeqOfGANSS_SgnTypeElement_item,
{ "GANSS-SgnTypeElement", "rrlp.GANSS_SgnTypeElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssCodePhaseAmbiguity,
{ "ganssCodePhaseAmbiguity", "rrlp.ganssCodePhaseAmbiguity",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_rrlp_ganss_SgnList,
{ "ganss-SgnList", "rrlp.ganss_SgnList",
FT_UINT32, BASE_DEC, NULL, 0,
"SeqOfGANSS_SgnElement", HFILL }},
{ &hf_rrlp_SeqOfGANSS_SgnElement_item,
{ "GANSS-SgnElement", "rrlp.GANSS_SgnElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_mpathDet,
{ "mpathDet", "rrlp.mpathDet",
FT_UINT32, BASE_DEC, VALS(rrlp_MpathIndic_vals), 0,
"MpathIndic", HFILL }},
{ &hf_rrlp_carrierQualityInd,
{ "carrierQualityInd", "rrlp.carrierQualityInd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_rrlp_codePhase_01,
{ "codePhase", "rrlp.codePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2097151", HFILL }},
{ &hf_rrlp_integerCodePhase,
{ "integerCodePhase", "rrlp.integerCodePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_rrlp_codePhaseRMSError,
{ "codePhaseRMSError", "rrlp.codePhaseRMSError",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_rrlp_adr,
{ "adr", "rrlp.adr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_33554431", HFILL }},
{ &hf_rrlp_nonGANSSpositionMethods,
{ "nonGANSSpositionMethods", "rrlp.nonGANSSpositionMethods",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_multipleMeasurementSets,
{ "multipleMeasurementSets", "rrlp.multipleMeasurementSets",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositionMethods_item,
{ "GANSSPositionMethod", "rrlp.GANSSPositionMethod_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSPositioningMethodTypes,
{ "gANSSPositioningMethodTypes", "rrlp.gANSSPositioningMethodTypes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSSignals,
{ "gANSSSignals", "rrlp.gANSSSignals",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_sbasID_01,
{ "sbasID", "rrlp.sbasID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gpsAssistance,
{ "gpsAssistance", "rrlp.gpsAssistance",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSAssistanceSet,
{ "gANSSAssistanceSet", "rrlp.gANSSAssistanceSet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSAdditionalAssistanceChoices,
{ "gANSSAdditionalAssistanceChoices", "rrlp.gANSSAdditionalAssistanceChoices",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_commonGANSSAssistance,
{ "commonGANSSAssistance", "rrlp.commonGANSSAssistance",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_specificGANSSAssistance,
{ "specificGANSSAssistance", "rrlp.specificGANSSAssistance",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_SpecificGANSSAssistance_item,
{ "GANSSAssistanceForOneGANSS", "rrlp.GANSSAssistanceForOneGANSS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_gANSSAssistance,
{ "gANSSAssistance", "rrlp.gANSSAssistance",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_GANSSAdditionalAssistanceChoices_item,
{ "GANSSAdditionalAssistanceChoicesForOneGANSS", "rrlp.GANSSAdditionalAssistanceChoicesForOneGANSS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rrlp_ganssClockModelChoice,
{ "ganssClockModelChoice", "rrlp.ganssClockModelChoice",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSModelID", HFILL }},
{ &hf_rrlp_gannsOrbitModelChoice,
{ "gannsOrbitModelChoice", "rrlp.gannsOrbitModelChoice",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSModelID", HFILL }},
{ &hf_rrlp_ganssAlmanacModelChoice,
{ "ganssAlmanacModelChoice", "rrlp.ganssAlmanacModelChoice",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSModelID", HFILL }},
{ &hf_rrlp_ganssAdditionalUTCModelChoice,
{ "ganssAdditionalUTCModelChoice", "rrlp.ganssAdditionalUTCModelChoice",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSModelID", HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_gps,
{ "gps", "rrlp.gps",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_galileo,
{ "galileo", "rrlp.galileo",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_sbas,
{ "sbas", "rrlp.sbas",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_modernizedGPS,
{ "modernizedGPS", "rrlp.modernizedGPS",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_qzss,
{ "qzss", "rrlp.qzss",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethod_glonass,
{ "glonass", "rrlp.glonass",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_PositionData_e_otd,
{ "e-otd", "rrlp.e-otd",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_PositionData_gps,
{ "gps", "rrlp.gps",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_PositionData_galileo,
{ "galileo", "rrlp.galileo",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_PositionData_sbas,
{ "sbas", "rrlp.sbas",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_PositionData_modernizedGPS,
{ "modernizedGPS", "rrlp.modernizedGPS",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_PositionData_qzss,
{ "qzss", "rrlp.qzss",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_PositionData_glonass,
{ "glonass", "rrlp.glonass",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_rrlp_NonGANSSPositionMethods_msAssistedEOTD,
{ "msAssistedEOTD", "rrlp.msAssistedEOTD",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_NonGANSSPositionMethods_msBasedEOTD,
{ "msBasedEOTD", "rrlp.msBasedEOTD",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_NonGANSSPositionMethods_msAssistedGPS,
{ "msAssistedGPS", "rrlp.msAssistedGPS",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_NonGANSSPositionMethods_msBasedGPS,
{ "msBasedGPS", "rrlp.msBasedGPS",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_NonGANSSPositionMethods_standaloneGPS,
{ "standaloneGPS", "rrlp.standaloneGPS",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethodTypes_msAssisted,
{ "msAssisted", "rrlp.msAssisted",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethodTypes_msBased,
{ "msBased", "rrlp.msBased",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSPositioningMethodTypes_standalone,
{ "standalone", "rrlp.standalone",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal1,
{ "signal1", "rrlp.signal1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal2,
{ "signal2", "rrlp.signal2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal3,
{ "signal3", "rrlp.signal3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal4,
{ "signal4", "rrlp.signal4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal5,
{ "signal5", "rrlp.signal5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal6,
{ "signal6", "rrlp.signal6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal7,
{ "signal7", "rrlp.signal7",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_rrlp_GANSSSignals_signal8,
{ "signal8", "rrlp.signal8",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_rrlp_SBASID_waas,
{ "waas", "rrlp.waas",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_SBASID_egnos,
{ "egnos", "rrlp.egnos",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_SBASID_masas,
{ "masas", "rrlp.masas",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_SBASID_gagan,
{ "gagan", "rrlp.gagan",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_MultipleMeasurementSets_eotd,
{ "eotd", "rrlp.eotd",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_MultipleMeasurementSets_gps,
{ "gps", "rrlp.gps",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_MultipleMeasurementSets_ganss,
{ "ganss", "rrlp.ganss",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_almanac,
{ "almanac", "rrlp.almanac",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_uTCmodel,
{ "uTCmodel", "rrlp.uTCmodel",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_ionosphericModel,
{ "ionosphericModel", "rrlp.ionosphericModel",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_navigationmodel,
{ "navigationmodel", "rrlp.navigationmodel",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_dGPScorrections,
{ "dGPScorrections", "rrlp.dGPScorrections",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_referenceLocation,
{ "referenceLocation", "rrlp.referenceLocation",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_referenceTime,
{ "referenceTime", "rrlp.referenceTime",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_acquisitionAssistance,
{ "acquisitionAssistance", "rrlp.acquisitionAssistance",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_realTimeIntegrity,
{ "realTimeIntegrity", "rrlp.realTimeIntegrity",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_ephemerisExtension,
{ "ephemerisExtension", "rrlp.ephemerisExtension",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GPSAssistance_ephemerisExtensionCheck,
{ "ephemerisExtensionCheck", "rrlp.ephemerisExtensionCheck",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_CommonGANSSAssistance_referenceTime,
{ "referenceTime", "rrlp.referenceTime",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_CommonGANSSAssistance_referenceLocation,
{ "referenceLocation", "rrlp.referenceLocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_CommonGANSSAssistance_ionosphericModel,
{ "ionosphericModel", "rrlp.ionosphericModel",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_CommonGANSSAssistance_addIonosphericModel,
{ "addIonosphericModel", "rrlp.addIonosphericModel",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_CommonGANSSAssistance_earthOrientationParam,
{ "earthOrientationParam", "rrlp.earthOrientationParam",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_realTimeIntegrity,
{ "realTimeIntegrity", "rrlp.realTimeIntegrity",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_differentialCorrections,
{ "differentialCorrections", "rrlp.differentialCorrections",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_almanac,
{ "almanac", "rrlp.almanac",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_referenceMeasurementInformation,
{ "referenceMeasurementInformation", "rrlp.referenceMeasurementInformation",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_navigationModel,
{ "navigationModel", "rrlp.navigationModel",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_timeModelGNSS_UTC,
{ "timeModelGNSS-UTC", "rrlp.timeModelGNSS-UTC",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_timeModelGNSS_GNSS,
{ "timeModelGNSS-GNSS", "rrlp.timeModelGNSS-GNSS",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_databitassistance,
{ "databitassistance", "rrlp.databitassistance",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_ephemerisExtension,
{ "ephemerisExtension", "rrlp.ephemerisExtension",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_ephemerisExtensionCheck,
{ "ephemerisExtensionCheck", "rrlp.ephemerisExtensionCheck",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_addUTCmodel,
{ "addUTCmodel", "rrlp.addUTCmodel",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSAssistance_auxiliaryInformation,
{ "auxiliaryInformation", "rrlp.auxiliaryInformation",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model1,
{ "model1", "rrlp.model1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model2,
{ "model2", "rrlp.model2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model3,
{ "model3", "rrlp.model3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model4,
{ "model4", "rrlp.model4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model5,
{ "model5", "rrlp.model5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model6,
{ "model6", "rrlp.model6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model7,
{ "model7", "rrlp.model7",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_rrlp_GANSSModelID_model8,
{ "model8", "rrlp.model8",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
#line 74 "./asn1/rrlp/packet-rrlp-template.c"
};
static gint *ett[] = {
&ett_rrlp,
#line 1 "./asn1/rrlp/packet-rrlp-ettarr.c"
&ett_rrlp_ExtensionContainer,
&ett_rrlp_PrivateExtensionList,
&ett_rrlp_PrivateExtension,
&ett_rrlp_PCS_Extensions,
&ett_rrlp_PDU,
&ett_rrlp_RRLP_Component,
&ett_rrlp_MsrPosition_Req,
&ett_rrlp_MsrPosition_Rsp,
&ett_rrlp_AssistanceData,
&ett_rrlp_ProtocolError,
&ett_rrlp_PosCapability_Req,
&ett_rrlp_PosCapability_Rsp,
&ett_rrlp_PositionInstruct,
&ett_rrlp_MethodType,
&ett_rrlp_AccuracyOpt,
&ett_rrlp_ReferenceAssistData,
&ett_rrlp_MsrAssistData,
&ett_rrlp_SeqOfMsrAssistBTS,
&ett_rrlp_MsrAssistBTS,
&ett_rrlp_SystemInfoAssistData,
&ett_rrlp_SeqOfSystemInfoAssistBTS,
&ett_rrlp_SystemInfoAssistBTS,
&ett_rrlp_AssistBTSData,
&ett_rrlp_CalcAssistanceBTS,
&ett_rrlp_ReferenceWGS84,
&ett_rrlp_MultipleSets,
&ett_rrlp_ReferenceIdentity,
&ett_rrlp_SeqOfReferenceIdentityType,
&ett_rrlp_ReferenceIdentityType,
&ett_rrlp_BSICAndCarrier,
&ett_rrlp_CellIDAndLAC,
&ett_rrlp_OTD_MeasureInfo,
&ett_rrlp_SeqOfOTD_MsrElementRest,
&ett_rrlp_OTD_MsrElementFirst,
&ett_rrlp_SeqOfOTD_FirstSetMsrs,
&ett_rrlp_OTD_MsrElementRest,
&ett_rrlp_SeqOfOTD_MsrsOfOtherSets,
&ett_rrlp_TOA_MeasurementsOfRef,
&ett_rrlp_OTD_MsrsOfOtherSets,
&ett_rrlp_OTD_Measurement,
&ett_rrlp_OTD_MeasurementWithID,
&ett_rrlp_EOTDQuality,
&ett_rrlp_NeighborIdentity,
&ett_rrlp_MultiFrameCarrier,
&ett_rrlp_LocationInfo,
&ett_rrlp_GPS_MeasureInfo,
&ett_rrlp_SeqOfGPS_MsrSetElement,
&ett_rrlp_GPS_MsrSetElement,
&ett_rrlp_SeqOfGPS_MsrElement,
&ett_rrlp_GPS_MsrElement,
&ett_rrlp_LocationError,
&ett_rrlp_AdditionalAssistanceData,
&ett_rrlp_GPS_AssistData,
&ett_rrlp_ControlHeader,
&ett_rrlp_ReferenceTime,
&ett_rrlp_GPSTime,
&ett_rrlp_GPSTOWAssist,
&ett_rrlp_GPSTOWAssistElement,
&ett_rrlp_GSMTime,
&ett_rrlp_RefLocation,
&ett_rrlp_DGPSCorrections,
&ett_rrlp_SeqOfSatElement,
&ett_rrlp_SatElement,
&ett_rrlp_NavigationModel,
&ett_rrlp_SeqOfNavModelElement,
&ett_rrlp_NavModelElement,
&ett_rrlp_SatStatus,
&ett_rrlp_UncompressedEphemeris,
&ett_rrlp_EphemerisSubframe1Reserved,
&ett_rrlp_IonosphericModel,
&ett_rrlp_UTCModel,
&ett_rrlp_Almanac,
&ett_rrlp_SeqOfAlmanacElement,
&ett_rrlp_AlmanacElement,
&ett_rrlp_AcquisAssist,
&ett_rrlp_SeqOfAcquisElement,
&ett_rrlp_TimeRelation,
&ett_rrlp_AcquisElement,
&ett_rrlp_AddionalDopplerFields,
&ett_rrlp_AddionalAngleFields,
&ett_rrlp_SeqOf_BadSatelliteSet,
&ett_rrlp_Rel98_MsrPosition_Req_Extension,
&ett_rrlp_Rel98_AssistanceData_Extension,
&ett_rrlp_Rel98_Ext_ExpOTD,
&ett_rrlp_MsrAssistData_R98_ExpOTD,
&ett_rrlp_SeqOfMsrAssistBTS_R98_ExpOTD,
&ett_rrlp_MsrAssistBTS_R98_ExpOTD,
&ett_rrlp_SystemInfoAssistData_R98_ExpOTD,
&ett_rrlp_SeqOfSystemInfoAssistBTS_R98_ExpOTD,
&ett_rrlp_SystemInfoAssistBTS_R98_ExpOTD,
&ett_rrlp_AssistBTSData_R98_ExpOTD,
&ett_rrlp_GPSTimeAssistanceMeasurements,
&ett_rrlp_Rel_98_MsrPosition_Rsp_Extension,
&ett_rrlp_T_rel_98_Ext_MeasureInfo,
&ett_rrlp_OTD_MeasureInfo_R98_Ext,
&ett_rrlp_OTD_MsrElementFirst_R98_Ext,
&ett_rrlp_SeqOfOTD_FirstSetMsrs_R98_Ext,
&ett_rrlp_Rel_5_MsrPosition_Rsp_Extension,
&ett_rrlp_Extended_reference,
&ett_rrlp_Rel5_MsrPosition_Req_Extension,
&ett_rrlp_Rel5_AssistanceData_Extension,
&ett_rrlp_Rel_5_ProtocolError_Extension,
&ett_rrlp_Rel7_MsrPosition_Req_Extension,
&ett_rrlp_GANSSPositioningMethod,
&ett_rrlp_GANSS_AssistData,
&ett_rrlp_GANSS_ControlHeader,
&ett_rrlp_GANSSCommonAssistData,
&ett_rrlp_SeqOfGANSSGenericAssistDataElement,
&ett_rrlp_GANSSGenericAssistDataElement,
&ett_rrlp_GANSSReferenceTime,
&ett_rrlp_GANSSRefTimeInfo,
&ett_rrlp_GANSSReferenceTime_R10_Ext,
&ett_rrlp_GANSSTOD_GSMTimeAssociation,
&ett_rrlp_GANSSRefLocation,
&ett_rrlp_GANSSIonosphericModel,
&ett_rrlp_GANSSIonosphereModel,
&ett_rrlp_GANSSIonoStormFlags,
&ett_rrlp_GANSSAddIonosphericModel,
&ett_rrlp_GANSSEarthOrientParam,
&ett_rrlp_SeqOfGANSSTimeModel,
&ett_rrlp_GANSSTimeModelElement,
&ett_rrlp_SeqOfGANSSTimeModel_R10_Ext,
&ett_rrlp_GANSSTimeModelElement_R10_Ext,
&ett_rrlp_GANSSDiffCorrections,
&ett_rrlp_SeqOfSgnTypeElement,
&ett_rrlp_SgnTypeElement,
&ett_rrlp_SeqOfDGANSSSgnElement,
&ett_rrlp_DGANSSSgnElement,
&ett_rrlp_GANSSNavModel,
&ett_rrlp_SeqOfGANSSSatelliteElement,
&ett_rrlp_GANSSSatelliteElement,
&ett_rrlp_GANSSOrbitModel,
&ett_rrlp_NavModel_KeplerianSet,
&ett_rrlp_NavModel_NAVKeplerianSet,
&ett_rrlp_NavModel_CNAVKeplerianSet,
&ett_rrlp_NavModel_GLONASSecef,
&ett_rrlp_NavModel_SBASecef,
&ett_rrlp_GANSSClockModel,
&ett_rrlp_SeqOfStandardClockModelElement,
&ett_rrlp_StandardClockModelElement,
&ett_rrlp_NAVclockModel,
&ett_rrlp_CNAVclockModel,
&ett_rrlp_GLONASSclockModel,
&ett_rrlp_SBASclockModel,
&ett_rrlp_GANSSRealTimeIntegrity,
&ett_rrlp_SeqOfBadSignalElement,
&ett_rrlp_BadSignalElement,
&ett_rrlp_GANSSDataBitAssist,
&ett_rrlp_SeqOfGanssDataBitsElement,
&ett_rrlp_GanssDataBitsElement,
&ett_rrlp_Seq_OfGANSSDataBitsSgn,
&ett_rrlp_GANSSDataBitsSgnElement,
&ett_rrlp_SeqOf_GANSSDataBits,
&ett_rrlp_GANSSRefMeasurementAssist,
&ett_rrlp_SeqOfGANSSRefMeasurementElement,
&ett_rrlp_GANSSRefMeasurementElement,
&ett_rrlp_AdditionalDopplerFields,
&ett_rrlp_GANSSRefMeasurementAssist_R10_Ext,
&ett_rrlp_GANSSRefMeasurement_R10_Ext_Element,
&ett_rrlp_GANSSAlmanacModel,
&ett_rrlp_SeqOfGANSSAlmanacElement,
&ett_rrlp_GANSSAlmanacElement,
&ett_rrlp_Almanac_KeplerianSet,
&ett_rrlp_Almanac_NAVKeplerianSet,
&ett_rrlp_Almanac_ReducedKeplerianSet,
&ett_rrlp_Almanac_MidiAlmanacSet,
&ett_rrlp_Almanac_GlonassAlmanacSet,
&ett_rrlp_Almanac_ECEFsbasAlmanacSet,
&ett_rrlp_GANSSAlmanacModel_R10_Ext,
&ett_rrlp_GANSSUTCModel,
&ett_rrlp_GANSSEphemerisExtension,
&ett_rrlp_GANSSEphemerisExtensionHeader,
&ett_rrlp_GANSSEphemerisExtensionTime,
&ett_rrlp_ReferenceNavModel,
&ett_rrlp_SeqOfGANSSRefOrbit,
&ett_rrlp_GANSSReferenceOrbit,
&ett_rrlp_GANSSEphemerisDeltaMatrix,
&ett_rrlp_GANSSEphemerisDeltaEpoch,
&ett_rrlp_GANSSDeltaEpochHeader,
&ett_rrlp_GANSSDeltaElementList,
&ett_rrlp_GANSSEphemerisDeltaBitSizes,
&ett_rrlp_GANSSEphemerisDeltaScales,
&ett_rrlp_GANSSEphemerisExtensionCheck,
&ett_rrlp_GANSSSatEventsInfo,
&ett_rrlp_GANSSAddUTCModel,
&ett_rrlp_UTCmodelSet2,
&ett_rrlp_UTCmodelSet3,
&ett_rrlp_UTCmodelSet4,
&ett_rrlp_GANSSAuxiliaryInformation,
&ett_rrlp_GANSS_ID1,
&ett_rrlp_GANSS_ID1_element,
&ett_rrlp_GANSS_ID3,
&ett_rrlp_GANSS_ID3_element,
&ett_rrlp_GANSSDiffCorrectionsValidityPeriod,
&ett_rrlp_DGANSSExtensionSgnTypeElement,
&ett_rrlp_SeqOfDGANSSExtensionSgnElement,
&ett_rrlp_DGANSSExtensionSgnElement,
&ett_rrlp_Add_GPS_AssistData,
&ett_rrlp_Add_GPS_ControlHeader,
&ett_rrlp_GPSClockModel,
&ett_rrlp_GPSEphemerisExtension,
&ett_rrlp_GPSEphemerisExtensionHeader,
&ett_rrlp_GPSEphemerisExtensionTime,
&ett_rrlp_SeqOfGPSRefOrbit,
&ett_rrlp_GPSReferenceOrbit,
&ett_rrlp_GPSEphemerisDeltaMatrix,
&ett_rrlp_GPSEphemerisDeltaEpoch,
&ett_rrlp_GPSDeltaEpochHeader,
&ett_rrlp_GPSDeltaElementList,
&ett_rrlp_GPSEphemerisDeltaBitSizes,
&ett_rrlp_GPSEphemerisDeltaScales,
&ett_rrlp_GPSEphemerisExtensionCheck,
&ett_rrlp_GPSSatEventsInfo,
&ett_rrlp_DGPSCorrectionsValidityPeriod,
&ett_rrlp_DGPSExtensionSatElement,
&ett_rrlp_GPSReferenceTime_R10_Ext,
&ett_rrlp_GPSAcquisAssist_R10_Ext,
&ett_rrlp_GPSAcquisAssist_R10_Ext_Element,
&ett_rrlp_GPSAlmanac_R10_Ext,
&ett_rrlp_Rel_7_MsrPosition_Rsp_Extension,
&ett_rrlp_GANSSLocationInfo,
&ett_rrlp_PositionData,
&ett_rrlp_ReferenceFrame,
&ett_rrlp_GANSSMeasureInfo,
&ett_rrlp_SeqOfGANSS_MsrSetElement,
&ett_rrlp_GANSS_MsrSetElement,
&ett_rrlp_SeqOfGANSS_MsrElement,
&ett_rrlp_GANSS_MsrElement,
&ett_rrlp_SeqOfGANSS_SgnTypeElement,
&ett_rrlp_GANSS_SgnTypeElement,
&ett_rrlp_SeqOfGANSS_SgnElement,
&ett_rrlp_GANSS_SgnElement,
&ett_rrlp_Rel7_AssistanceData_Extension,
&ett_rrlp_PosCapabilities,
&ett_rrlp_NonGANSSPositionMethods,
&ett_rrlp_GANSSPositionMethods,
&ett_rrlp_GANSSPositionMethod,
&ett_rrlp_GANSSPositioningMethodTypes,
&ett_rrlp_GANSSSignals,
&ett_rrlp_SBASID,
&ett_rrlp_MultipleMeasurementSets,
&ett_rrlp_AssistanceSupported,
&ett_rrlp_GPSAssistance,
&ett_rrlp_GANSSAssistanceSet,
&ett_rrlp_CommonGANSSAssistance,
&ett_rrlp_SpecificGANSSAssistance,
&ett_rrlp_GANSSAssistanceForOneGANSS,
&ett_rrlp_GANSSAssistance,
&ett_rrlp_GANSSAdditionalAssistanceChoices,
&ett_rrlp_GANSSAdditionalAssistanceChoicesForOneGANSS,
&ett_rrlp_GANSSModelID,
&ett_rrlp_AssistanceNeeded,
#line 80 "./asn1/rrlp/packet-rrlp-template.c"
};
proto_rrlp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("rrlp", dissect_PDU_PDU, proto_rrlp);
proto_register_field_array(proto_rrlp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rrlp(void)
{
}
