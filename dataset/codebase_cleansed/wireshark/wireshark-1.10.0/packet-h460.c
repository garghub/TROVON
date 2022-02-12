static int
dissect_h460_2_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_2_NumberPortabilityRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_2_NumberPortabilityRejectReason, h460_2_NumberPortabilityRejectReason_choice,
NULL);
return offset;
}
static int
dissect_h460_2_PortabilityTypeOfNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_2_PortabilityTypeOfNumber, h460_2_PortabilityTypeOfNumber_choice,
NULL);
return offset;
}
static int
dissect_h460_2_NumberPortabilityTypeOfNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_2_NumberPortabilityTypeOfNumber, h460_2_NumberPortabilityTypeOfNumber_choice,
NULL);
return offset;
}
static int
dissect_h460_2_PortabilityAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_2_PortabilityAddress, h460_2_PortabilityAddress_sequence);
return offset;
}
static int
dissect_h460_2_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_2_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_2_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h460_2_RegionalParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_2_RegionalParameters, h460_2_RegionalParameters_sequence);
return offset;
}
static int
dissect_h460_2_T_nUMBERPORTABILITYDATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_2_T_nUMBERPORTABILITYDATA, h460_2_T_nUMBERPORTABILITYDATA_sequence);
return offset;
}
static int
dissect_h460_2_NumberPortabilityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_2_NumberPortabilityInfo, h460_2_NumberPortabilityInfo_choice,
NULL);
return offset;
}
static int dissect_h460_2_NumberPortabilityInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_2_NumberPortabilityInfo(tvb, offset, &asn1_ctx, tree, hf_h460_2_h460_2_NumberPortabilityInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_3_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_3_CircuitStatusType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_3_CircuitStatusType, h460_3_CircuitStatusType_choice,
NULL);
return offset;
}
static int
dissect_h460_3_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_h460_3_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h460_3_CircuitStatusMap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_3_CircuitStatusMap, h460_3_CircuitStatusMap_sequence);
return offset;
}
static int
dissect_h460_3_SEQUENCE_OF_CircuitStatusMap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_3_SEQUENCE_OF_CircuitStatusMap, h460_3_SEQUENCE_OF_CircuitStatusMap_sequence_of);
return offset;
}
static int
dissect_h460_3_CircuitStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_3_CircuitStatus, h460_3_CircuitStatus_sequence);
return offset;
}
static int dissect_h460_3_CircuitStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_3_CircuitStatus(tvb, offset, &asn1_ctx, tree, hf_h460_3_h460_3_CircuitStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_4_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_4_T_priorityValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_4_T_priorityValue, h460_4_T_priorityValue_choice,
NULL);
return offset;
}
static int
dissect_h460_4_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_4_SEQUENCE_OF_ClearToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_4_SEQUENCE_OF_ClearToken, h460_4_SEQUENCE_OF_ClearToken_sequence_of);
return offset;
}
static int
dissect_h460_4_SEQUENCE_OF_CryptoToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_4_SEQUENCE_OF_CryptoToken, h460_4_SEQUENCE_OF_CryptoToken_sequence_of);
return offset;
}
static int
dissect_h460_4_T_rejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_4_T_rejectReason, h460_4_T_rejectReason_choice,
NULL);
return offset;
}
static int
dissect_h460_4_CallPriorityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_4_CallPriorityInfo, h460_4_CallPriorityInfo_sequence);
return offset;
}
static int
dissect_h460_4_X121CountryCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_h460_4_T_x121(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_4_T_x121, h460_4_T_x121_sequence);
return offset;
}
static int
dissect_h460_4_E164CountryCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_h460_4_T_identificationCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 4, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_h460_4_T_e164(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_4_T_e164, h460_4_T_e164_sequence);
return offset;
}
static int
dissect_h460_4_T_numberingPlan(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_4_T_numberingPlan, h460_4_T_numberingPlan_choice,
NULL);
return offset;
}
static int
dissect_h460_4_CountryInternationalNetworkCallOriginationIdentification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_4_CountryInternationalNetworkCallOriginationIdentification, h460_4_CountryInternationalNetworkCallOriginationIdentification_sequence);
return offset;
}
static int dissect_h460_4_CallPriorityInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_4_CallPriorityInfo(tvb, offset, &asn1_ctx, tree, hf_h460_4_h460_4_CallPriorityInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_h460_4_CountryInternationalNetworkCallOriginationIdentification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_4_CountryInternationalNetworkCallOriginationIdentification(tvb, offset, &asn1_ctx, tree, hf_h460_4_h460_4_CountryInternationalNetworkCallOriginationIdentification_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_9_EstimatedEnd2EndDelay(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_CalculatedJitter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h460_9_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_Extension, h460_9_Extension_sequence);
return offset;
}
static int
dissect_h460_9_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_T_mediaSenderMeasures(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_T_mediaSenderMeasures, h460_9_T_mediaSenderMeasures_sequence);
return offset;
}
static int
dissect_h460_9_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_T_mediaReceiverMeasures(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_T_mediaReceiverMeasures, h460_9_T_mediaReceiverMeasures_sequence);
return offset;
}
static int
dissect_h460_9_SEQUENCE_OF_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_9_SEQUENCE_OF_Extension, h460_9_SEQUENCE_OF_Extension_sequence_of);
return offset;
}
static int
dissect_h460_9_RTCPMeasures(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_RTCPMeasures, h460_9_RTCPMeasures_sequence);
return offset;
}
static int
dissect_h460_9_SEQUENCE_OF_RTCPMeasures(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_9_SEQUENCE_OF_RTCPMeasures, h460_9_SEQUENCE_OF_RTCPMeasures_sequence_of);
return offset;
}
static int
dissect_h460_9_PerCallQoSReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_PerCallQoSReport, h460_9_PerCallQoSReport_sequence);
return offset;
}
static int
dissect_h460_9_SEQUENCE_OF_PerCallQoSReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_9_SEQUENCE_OF_PerCallQoSReport, h460_9_SEQUENCE_OF_PerCallQoSReport_sequence_of);
return offset;
}
static int
dissect_h460_9_PeriodicQoSMonReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_PeriodicQoSMonReport, h460_9_PeriodicQoSMonReport_sequence);
return offset;
}
static int
dissect_h460_9_FinalQosMonReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_FinalQosMonReport, h460_9_FinalQosMonReport_sequence);
return offset;
}
static int
dissect_h460_9_InterGKQosMonReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_InterGKQosMonReport, h460_9_InterGKQosMonReport_sequence);
return offset;
}
static int
dissect_h460_9_QosMonitoringReportData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_9_QosMonitoringReportData, h460_9_QosMonitoringReportData_choice,
NULL);
return offset;
}
static int
dissect_h460_9_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_BurstMetrics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_BurstMetrics, h460_9_BurstMetrics_sequence);
return offset;
}
static int
dissect_h460_9_INTEGER_M127_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 10U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_INTEGER_M127_0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 0U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_INTEGER_0_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_INTEGER_10_50(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
10U, 50U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_9_PLCtypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_9_PLCtypes, h460_9_PLCtypes_choice,
NULL);
return offset;
}
static int
dissect_h460_9_JitterBufferTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_9_JitterBufferTypes, h460_9_JitterBufferTypes_choice,
NULL);
return offset;
}
static int
dissect_h460_9_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_h460_9_JitterBufferParms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_JitterBufferParms, h460_9_JitterBufferParms_sequence);
return offset;
}
static int
dissect_h460_9_ExtendedRTPMetrics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_9_ExtendedRTPMetrics, h460_9_ExtendedRTPMetrics_sequence);
return offset;
}
static int dissect_h460_9_QosMonitoringReportData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_9_QosMonitoringReportData(tvb, offset, &asn1_ctx, tree, hf_h460_9_h460_9_QosMonitoringReportData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_h460_9_ExtendedRTPMetrics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_9_ExtendedRTPMetrics(tvb, offset, &asn1_ctx, tree, hf_h460_9_h460_9_ExtendedRTPMetrics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_10_CallPartyCategory(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_10_OriginatingLineInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_10_CallPartyCategoryInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_10_CallPartyCategoryInfo, h460_10_CallPartyCategoryInfo_sequence);
return offset;
}
static int dissect_h460_10_CallPartyCategoryInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_10_CallPartyCategoryInfo(tvb, offset, &asn1_ctx, tree, hf_h460_10_h460_10_CallPartyCategoryInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_14_MlppPrecedence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_h460_14_MlppReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, h460_14_MlppReason_value_map);
return offset;
}
static int
dissect_h460_14_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_14_MlppNotification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_14_MlppNotification, h460_14_MlppNotification_choice,
NULL);
return offset;
}
static int
dissect_h460_14_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h460_14_AlternateParty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_14_AlternateParty, h460_14_AlternateParty_sequence);
return offset;
}
static int
dissect_h460_14_ReleaseCall(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_14_ReleaseCall, h460_14_ReleaseCall_sequence);
return offset;
}
static int
dissect_h460_14_MLPPInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_14_MLPPInfo, h460_14_MLPPInfo_sequence);
return offset;
}
static int dissect_h460_14_MLPPInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_14_MLPPInfo(tvb, offset, &asn1_ctx, tree, hf_h460_14_h460_14_MLPPInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_15_SEQUENCE_OF_TransportAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_15_SEQUENCE_OF_TransportAddress, h460_15_SEQUENCE_OF_TransportAddress_sequence_of);
return offset;
}
static int
dissect_h460_15_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h460_15_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h460_15_ChannelSuspendRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelSuspendRequest, h460_15_ChannelSuspendRequest_sequence);
return offset;
}
static int
dissect_h460_15_ChannelSuspendResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelSuspendResponse, h460_15_ChannelSuspendResponse_sequence);
return offset;
}
static int
dissect_h460_15_ChannelSuspendConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelSuspendConfirm, h460_15_ChannelSuspendConfirm_sequence);
return offset;
}
static int
dissect_h460_15_ChannelSuspendCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelSuspendCancel, h460_15_ChannelSuspendCancel_sequence);
return offset;
}
static int
dissect_h460_15_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h460_15_ChannelResumeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelResumeRequest, h460_15_ChannelResumeRequest_sequence);
return offset;
}
static int
dissect_h460_15_ChannelResumeResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_ChannelResumeResponse, h460_15_ChannelResumeResponse_sequence);
return offset;
}
static int
dissect_h460_15_T_signallingChannelData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h460_15_T_signallingChannelData, h460_15_T_signallingChannelData_choice,
NULL);
return offset;
}
static int
dissect_h460_15_SignallingChannelData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_15_SignallingChannelData, h460_15_SignallingChannelData_sequence);
return offset;
}
static int dissect_h460_15_SignallingChannelData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_15_SignallingChannelData(tvb, offset, &asn1_ctx, tree, hf_h460_15_h460_15_SignallingChannelData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_18_IncomingCallIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_18_IncomingCallIndication, h460_18_IncomingCallIndication_sequence);
return offset;
}
static int
dissect_h460_18_LRQKeepAliveData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_18_LRQKeepAliveData, h460_18_LRQKeepAliveData_sequence);
return offset;
}
static int dissect_h460_18_IncomingCallIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_18_IncomingCallIndication(tvb, offset, &asn1_ctx, tree, hf_h460_18_h460_18_IncomingCallIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_h460_18_LRQKeepAliveData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_18_LRQKeepAliveData(tvb, offset, &asn1_ctx, tree, hf_h460_18_h460_18_LRQKeepAliveData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_19_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h460_19_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h460_19_TraversalParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_19_TraversalParameters, h460_19_TraversalParameters_sequence);
return offset;
}
static int dissect_h460_19_TraversalParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_19_TraversalParameters(tvb, offset, &asn1_ctx, tree, hf_h460_19_h460_19_TraversalParameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h460_21_SEQUENCE_SIZE_1_256_OF_Capability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_21_SEQUENCE_SIZE_1_256_OF_Capability, h460_21_SEQUENCE_SIZE_1_256_OF_Capability_sequence_of,
1, 256, FALSE);
return offset;
}
static int
dissect_h460_21_INTEGER_1_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h460_21_ReceiveCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_21_ReceiveCapabilities, h460_21_ReceiveCapabilities_sequence);
return offset;
}
static int
dissect_h460_21_GloballyUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_h460_21_TransmitCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_21_TransmitCapabilities, h460_21_TransmitCapabilities_sequence);
return offset;
}
static int
dissect_h460_21_SEQUENCE_SIZE_1_256_OF_TransmitCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h460_21_SEQUENCE_SIZE_1_256_OF_TransmitCapabilities, h460_21_SEQUENCE_SIZE_1_256_OF_TransmitCapabilities_sequence_of,
1, 256, FALSE);
return offset;
}
static int
dissect_h460_21_CapabilityAdvertisement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h460_21_CapabilityAdvertisement, h460_21_CapabilityAdvertisement_sequence);
return offset;
}
static int dissect_h460_21_CapabilityAdvertisement_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h460_21_CapabilityAdvertisement(tvb, offset, &asn1_ctx, tree, hf_h460_21_h460_21_CapabilityAdvertisement_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_ies(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
if (q931_ie_handle) {
call_dissector(q931_ie_handle, tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_ras(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
if (h225_ras_handle) {
call_dissector(h225_ras_handle, tvb, pinfo, tree);
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static h460_feature_t *find_ftr(const gchar *key) {
h460_feature_t *ftr = NULL;
h460_feature_t *f;
for (f=h460_feature_tab; f->id; f++) {
if (f->key_gd && !strcmp(key, f->key_gd)) { ftr = f; break; }
if (f->key_fd && !strcmp(key, f->key_fd)) { ftr = f; break; }
if (f->key_gm && !strcmp(key, f->key_gm)) { ftr = f; break; }
if (f->key_gi && !strcmp(key, f->key_gi)) { ftr = f; break; }
}
return ftr;
}
static int
dissect_h460_name(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
asn1_ctx_t *actx;
h460_feature_t *ftr;
actx = get_asn1_ctx(pinfo->private_data);
DISSECTOR_ASSERT(actx);
if (tree) {
ftr = find_ftr(pinfo->match_string);
if (ftr) {
proto_item_append_text(actx->created_item, " - %s", ftr->name);
proto_item_append_text(proto_item_get_parent(proto_tree_get_parent(tree)), ": %s", ftr->name);
} else {
proto_item_append_text(actx->created_item, " - unknown(%s)", pinfo->match_string);
}
}
return offset;
}
void proto_register_h460(void) {
h460_feature_t *ftr;
static hf_register_info hf[] = {
#line 1 "../../asn1/h460/packet-h460-hfarr.c"
{ &hf_h460_2_h460_2_NumberPortabilityInfo_PDU,
{ "NumberPortabilityInfo", "h460.2.NumberPortabilityInfo",
FT_UINT32, BASE_DEC, VALS(h460_2_NumberPortabilityInfo_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_numberPortabilityRejectReason,
{ "numberPortabilityRejectReason", "h460.2.numberPortabilityRejectReason",
FT_UINT32, BASE_DEC, VALS(h460_2_NumberPortabilityRejectReason_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_nUMBERPORTABILITYDATA,
{ "nUMBERPORTABILITYDATA", "h460.2.nUMBERPORTABILITYDATA",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_addressTranslated,
{ "addressTranslated", "h460.2.addressTranslated",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_portedAddress,
{ "portedAddress", "h460.2.portedAddress",
FT_NONE, BASE_NONE, NULL, 0,
"PortabilityAddress", HFILL }},
{ &hf_h460_2_routingAddress,
{ "routingAddress", "h460.2.routingAddress",
FT_NONE, BASE_NONE, NULL, 0,
"PortabilityAddress", HFILL }},
{ &hf_h460_2_regionalParams,
{ "regionalParams", "h460.2.regionalParams",
FT_NONE, BASE_NONE, NULL, 0,
"RegionalParameters", HFILL }},
{ &hf_h460_2_unspecified,
{ "unspecified", "h460.2.unspecified",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_qorPortedNumber,
{ "qorPortedNumber", "h460.2.qorPortedNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_aliasAddress,
{ "aliasAddress", "h460.2.aliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_typeOfAddress,
{ "typeOfAddress", "h460.2.typeOfAddress",
FT_UINT32, BASE_DEC, VALS(h460_2_NumberPortabilityTypeOfNumber_vals), 0,
"NumberPortabilityTypeOfNumber", HFILL }},
{ &hf_h460_2_publicTypeOfNumber,
{ "publicTypeOfNumber", "h460.2.publicTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(h225_PublicTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_privateTypeOfNumber,
{ "privateTypeOfNumber", "h460.2.privateTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(h225_PrivateTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_portabilityTypeOfNumber,
{ "portabilityTypeOfNumber", "h460.2.portabilityTypeOfNumber",
FT_UINT32, BASE_DEC, VALS(h460_2_PortabilityTypeOfNumber_vals), 0,
NULL, HFILL }},
{ &hf_h460_2_portedNumber,
{ "portedNumber", "h460.2.portedNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_routingNumber,
{ "routingNumber", "h460.2.routingNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_concatenatedNumber,
{ "concatenatedNumber", "h460.2.concatenatedNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_2_t35CountryCode,
{ "t35CountryCode", "h460.2.t35CountryCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_2_t35Extension,
{ "t35Extension", "h460.2.t35Extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_2_variantIdentifier,
{ "variantIdentifier", "h460.2.variantIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h460_2_regionalData,
{ "regionalData", "h460.2.regionalData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h460_3_h460_3_CircuitStatus_PDU,
{ "CircuitStatus", "h460.3.CircuitStatus",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_3_circuitStatusMap,
{ "circuitStatusMap", "h460.3.circuitStatusMap",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CircuitStatusMap", HFILL }},
{ &hf_h460_3_circuitStatusMap_item,
{ "CircuitStatusMap", "h460.3.CircuitStatusMap",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_3_statusType,
{ "statusType", "h460.3.statusType",
FT_UINT32, BASE_DEC, VALS(h460_3_CircuitStatusType_vals), 0,
"CircuitStatusType", HFILL }},
{ &hf_h460_3_baseCircuitID,
{ "baseCircuitID", "h460.3.baseCircuitID",
FT_NONE, BASE_NONE, NULL, 0,
"CircuitIdentifier", HFILL }},
{ &hf_h460_3_range,
{ "range", "h460.3.range",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_h460_3_status,
{ "status", "h460.3.status",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h460_3_serviceStatus,
{ "serviceStatus", "h460.3.serviceStatus",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_3_busyStatus,
{ "busyStatus", "h460.3.busyStatus",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_h460_4_CallPriorityInfo_PDU,
{ "CallPriorityInfo", "h460.4.CallPriorityInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_h460_4_CountryInternationalNetworkCallOriginationIdentification_PDU,
{ "CountryInternationalNetworkCallOriginationIdentification", "h460.4.CountryInternationalNetworkCallOriginationIdentification",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_priorityValue,
{ "priorityValue", "h460.4.priorityValue",
FT_UINT32, BASE_DEC, VALS(h460_4_T_priorityValue_vals), 0,
NULL, HFILL }},
{ &hf_h460_4_emergencyAuthorized,
{ "emergencyAuthorized", "h460.4.emergencyAuthorized",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_emergencyPublic,
{ "emergencyPublic", "h460.4.emergencyPublic",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_high,
{ "high", "h460.4.high",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_normal,
{ "normal", "h460.4.normal",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_priorityExtension,
{ "priorityExtension", "h460.4.priorityExtension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_4_tokens,
{ "tokens", "h460.4.tokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ClearToken", HFILL }},
{ &hf_h460_4_tokens_item,
{ "ClearToken", "h460.4.ClearToken",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_cryptoTokens,
{ "cryptoTokens", "h460.4.cryptoTokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CryptoToken", HFILL }},
{ &hf_h460_4_cryptoTokens_item,
{ "CryptoToken", "h460.4.CryptoToken",
FT_UINT32, BASE_DEC, VALS(h235_CryptoToken_vals), 0,
NULL, HFILL }},
{ &hf_h460_4_rejectReason,
{ "rejectReason", "h460.4.rejectReason",
FT_UINT32, BASE_DEC, VALS(h460_4_T_rejectReason_vals), 0,
NULL, HFILL }},
{ &hf_h460_4_priorityUnavailable,
{ "priorityUnavailable", "h460.4.priorityUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_priorityUnauthorized,
{ "priorityUnauthorized", "h460.4.priorityUnauthorized",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_priorityValueUnknown,
{ "priorityValueUnknown", "h460.4.priorityValueUnknown",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_numberingPlan,
{ "numberingPlan", "h460.4.numberingPlan",
FT_UINT32, BASE_DEC, VALS(h460_4_T_numberingPlan_vals), 0,
NULL, HFILL }},
{ &hf_h460_4_x121,
{ "x121", "h460.4.x121",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_x121CountryCode,
{ "countryCode", "h460.4.countryCode",
FT_STRING, BASE_NONE, NULL, 0,
"X121CountryCode", HFILL }},
{ &hf_h460_4_e164,
{ "e164", "h460.4.e164",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_4_e164CountryCode,
{ "countryCode", "h460.4.countryCode",
FT_STRING, BASE_NONE, NULL, 0,
"E164CountryCode", HFILL }},
{ &hf_h460_4_identificationCode,
{ "identificationCode", "h460.4.identificationCode",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_h460_9_QosMonitoringReportData_PDU,
{ "QosMonitoringReportData", "h460.9.QosMonitoringReportData",
FT_UINT32, BASE_DEC, VALS(h460_9_QosMonitoringReportData_vals), 0,
NULL, HFILL }},
{ &hf_h460_9_h460_9_ExtendedRTPMetrics_PDU,
{ "ExtendedRTPMetrics", "h460.9.ExtendedRTPMetrics",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_extensionId,
{ "extensionId", "h460.9.extensionId",
FT_UINT32, BASE_DEC, VALS(h225_GenericIdentifier_vals), 0,
"GenericIdentifier", HFILL }},
{ &hf_h460_9_extensionContent,
{ "extensionContent", "h460.9.extensionContent",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h460_9_rtpAddress,
{ "rtpAddress", "h460.9.rtpAddress",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h460_9_rtcpAddress,
{ "rtcpAddress", "h460.9.rtcpAddress",
FT_NONE, BASE_NONE, NULL, 0,
"TransportChannelInfo", HFILL }},
{ &hf_h460_9_sessionId,
{ "sessionId", "h460.9.sessionId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h460_9_nonStandardData,
{ "nonStandardData", "h460.9.nonStandardData",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h460_9_mediaSenderMeasures,
{ "mediaSenderMeasures", "h460.9.mediaSenderMeasures",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_worstEstimatedEnd2EndDelay,
{ "worstEstimatedEnd2EndDelay", "h460.9.worstEstimatedEnd2EndDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"EstimatedEnd2EndDelay", HFILL }},
{ &hf_h460_9_meanEstimatedEnd2EndDelay,
{ "meanEstimatedEnd2EndDelay", "h460.9.meanEstimatedEnd2EndDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"EstimatedEnd2EndDelay", HFILL }},
{ &hf_h460_9_mediaReceiverMeasures,
{ "mediaReceiverMeasures", "h460.9.mediaReceiverMeasures",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_cumulativeNumberOfPacketsLost,
{ "cumulativeNumberOfPacketsLost", "h460.9.cumulativeNumberOfPacketsLost",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h460_9_packetLostRate,
{ "packetLostRate", "h460.9.packetLostRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_worstJitter,
{ "worstJitter", "h460.9.worstJitter",
FT_UINT32, BASE_DEC, NULL, 0,
"CalculatedJitter", HFILL }},
{ &hf_h460_9_estimatedThroughput,
{ "estimatedThroughput", "h460.9.estimatedThroughput",
FT_UINT32, BASE_DEC, NULL, 0,
"BandWidth", HFILL }},
{ &hf_h460_9_fractionLostRate,
{ "fractionLostRate", "h460.9.fractionLostRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_meanJitter,
{ "meanJitter", "h460.9.meanJitter",
FT_UINT32, BASE_DEC, NULL, 0,
"CalculatedJitter", HFILL }},
{ &hf_h460_9_extensions,
{ "extensions", "h460.9.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Extension", HFILL }},
{ &hf_h460_9_extensions_item,
{ "Extension", "h460.9.Extension",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_callReferenceValue,
{ "callReferenceValue", "h460.9.callReferenceValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_conferenceID,
{ "conferenceID", "h460.9.conferenceID",
FT_GUID, BASE_NONE, NULL, 0,
"ConferenceIdentifier", HFILL }},
{ &hf_h460_9_callIdentifier,
{ "callIdentifier", "h460.9.callIdentifier",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_mediaChannelsQoS,
{ "mediaChannelsQoS", "h460.9.mediaChannelsQoS",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RTCPMeasures", HFILL }},
{ &hf_h460_9_mediaChannelsQoS_item,
{ "RTCPMeasures", "h460.9.RTCPMeasures",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_periodic,
{ "periodic", "h460.9.periodic",
FT_NONE, BASE_NONE, NULL, 0,
"PeriodicQoSMonReport", HFILL }},
{ &hf_h460_9_final,
{ "final", "h460.9.final",
FT_NONE, BASE_NONE, NULL, 0,
"FinalQosMonReport", HFILL }},
{ &hf_h460_9_interGK,
{ "interGK", "h460.9.interGK",
FT_NONE, BASE_NONE, NULL, 0,
"InterGKQosMonReport", HFILL }},
{ &hf_h460_9_perCallInfo,
{ "perCallInfo", "h460.9.perCallInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PerCallQoSReport", HFILL }},
{ &hf_h460_9_perCallInfo_item,
{ "PerCallQoSReport", "h460.9.PerCallQoSReport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_mediaInfo,
{ "mediaInfo", "h460.9.mediaInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RTCPMeasures", HFILL }},
{ &hf_h460_9_mediaInfo_item,
{ "RTCPMeasures", "h460.9.RTCPMeasures",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_networkPacketLossRate,
{ "networkPacketLossRate", "h460.9.networkPacketLossRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_9_jitterBufferDiscardRate,
{ "jitterBufferDiscardRate", "h460.9.jitterBufferDiscardRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_9_burstMetrics,
{ "burstMetrics", "h460.9.burstMetrics",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_rtcpRoundTripDelay,
{ "rtcpRoundTripDelay", "h460.9.rtcpRoundTripDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_endSystemDelay,
{ "endSystemDelay", "h460.9.endSystemDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_signalLevel,
{ "signalLevel", "h460.9.signalLevel",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_10", HFILL }},
{ &hf_h460_9_noiseLevel,
{ "noiseLevel", "h460.9.noiseLevel",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_0", HFILL }},
{ &hf_h460_9_residualEchoReturnLoss,
{ "residualEchoReturnLoss", "h460.9.residualEchoReturnLoss",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_h460_9_rFactor,
{ "rFactor", "h460.9.rFactor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_h460_9_extRFactor,
{ "extRFactor", "h460.9.extRFactor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_h460_9_estimatedMOSLQ,
{ "estimatedMOSLQ", "h460.9.estimatedMOSLQ",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_50", HFILL }},
{ &hf_h460_9_estimatedMOSCQ,
{ "estimatedMOSCQ", "h460.9.estimatedMOSCQ",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_50", HFILL }},
{ &hf_h460_9_plcType,
{ "plcType", "h460.9.plcType",
FT_UINT32, BASE_DEC, VALS(h460_9_PLCtypes_vals), 0,
"PLCtypes", HFILL }},
{ &hf_h460_9_jitterBufferParms,
{ "jitterBufferParms", "h460.9.jitterBufferParms",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_gmin,
{ "gmin", "h460.9.gmin",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_9_burstLossDensity,
{ "burstLossDensity", "h460.9.burstLossDensity",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_9_gapLossDensity,
{ "gapLossDensity", "h460.9.gapLossDensity",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_9_burstDuration,
{ "burstDuration", "h460.9.burstDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_gapDuration,
{ "gapDuration", "h460.9.gapDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_unspecified,
{ "unspecified", "h460.9.unspecified",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_disabled,
{ "disabled", "h460.9.disabled",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_enhanced,
{ "enhanced", "h460.9.enhanced",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_standard,
{ "standard", "h460.9.standard",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_jitterBufferType,
{ "jitterBufferType", "h460.9.jitterBufferType",
FT_UINT32, BASE_DEC, VALS(h460_9_JitterBufferTypes_vals), 0,
"JitterBufferTypes", HFILL }},
{ &hf_h460_9_jitterBufferAdaptRate,
{ "jitterBufferAdaptRate", "h460.9.jitterBufferAdaptRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_h460_9_jitterBufferNominalSize,
{ "jitterBufferNominalSize", "h460.9.jitterBufferNominalSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_jitterBufferMaxSize,
{ "jitterBufferMaxSize", "h460.9.jitterBufferMaxSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_jitterBufferAbsoluteMax,
{ "jitterBufferAbsoluteMax", "h460.9.jitterBufferAbsoluteMax",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h460_9_unknown,
{ "unknown", "h460.9.unknown",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_reserved,
{ "reserved", "h460.9.reserved",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_nonadaptive,
{ "nonadaptive", "h460.9.nonadaptive",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_9_adaptive,
{ "adaptive", "h460.9.adaptive",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_10_h460_10_CallPartyCategoryInfo_PDU,
{ "CallPartyCategoryInfo", "h460.10.CallPartyCategoryInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_10_callPartyCategory,
{ "callPartyCategory", "h460.10.callPartyCategory",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h460_10_originatingLineInfo,
{ "originatingLineInfo", "h460.10.originatingLineInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_h460_14_MLPPInfo_PDU,
{ "MLPPInfo", "h460.14.MLPPInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_precedence,
{ "precedence", "h460.14.precedence",
FT_UINT32, BASE_DEC, VALS(h460_14_MlppPrecedence_vals), 0,
"MlppPrecedence", HFILL }},
{ &hf_h460_14_mlppReason,
{ "mlppReason", "h460.14.mlppReason",
FT_UINT32, BASE_DEC, VALS(h460_14_MlppReason_vals), 0,
NULL, HFILL }},
{ &hf_h460_14_mlppNotification,
{ "mlppNotification", "h460.14.mlppNotification",
FT_UINT32, BASE_DEC, VALS(h460_14_MlppNotification_vals), 0,
NULL, HFILL }},
{ &hf_h460_14_alternateParty,
{ "alternateParty", "h460.14.alternateParty",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_releaseCall,
{ "releaseCall", "h460.14.releaseCall",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_preemptionPending,
{ "preemptionPending", "h460.14.preemptionPending",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_preemptionInProgress,
{ "preemptionInProgress", "h460.14.preemptionInProgress",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_preemptionEnd,
{ "preemptionEnd", "h460.14.preemptionEnd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_preemptionComplete,
{ "preemptionComplete", "h460.14.preemptionComplete",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_14_altID,
{ "altID", "h460.14.altID",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h460_14_altTimer,
{ "altTimer", "h460.14.altTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_14_preemptCallID,
{ "preemptCallID", "h460.14.preemptCallID",
FT_NONE, BASE_NONE, NULL, 0,
"CallIdentifier", HFILL }},
{ &hf_h460_14_releaseReason,
{ "releaseReason", "h460.14.releaseReason",
FT_UINT32, BASE_DEC, VALS(h460_14_MlppReason_vals), 0,
"MlppReason", HFILL }},
{ &hf_h460_14_releaseDelay,
{ "releaseDelay", "h460.14.releaseDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h460_15_h460_15_SignallingChannelData_PDU,
{ "SignallingChannelData", "h460.15.SignallingChannelData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_signallingChannelData,
{ "signallingChannelData", "h460.15.signallingChannelData",
FT_UINT32, BASE_DEC, VALS(h460_15_T_signallingChannelData_vals), 0,
NULL, HFILL }},
{ &hf_h460_15_channelSuspendRequest,
{ "channelSuspendRequest", "h460.15.channelSuspendRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelSuspendResponse,
{ "channelSuspendResponse", "h460.15.channelSuspendResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelSuspendConfirm,
{ "channelSuspendConfirm", "h460.15.channelSuspendConfirm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelSuspendCancel,
{ "channelSuspendCancel", "h460.15.channelSuspendCancel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelResumeRequest,
{ "channelResumeRequest", "h460.15.channelResumeRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelResumeResponse,
{ "channelResumeResponse", "h460.15.channelResumeResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_channelResumeAddress,
{ "channelResumeAddress", "h460.15.channelResumeAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h460_15_channelResumeAddress_item,
{ "TransportAddress", "h460.15.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h460_15_immediateResume,
{ "immediateResume", "h460.15.immediateResume",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h460_15_resetH245,
{ "resetH245", "h460.15.resetH245",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_15_okToSuspend,
{ "okToSuspend", "h460.15.okToSuspend",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h460_15_randomNumber,
{ "randomNumber", "h460.15.randomNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h460_18_h460_18_IncomingCallIndication_PDU,
{ "IncomingCallIndication", "h460.18.IncomingCallIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_18_h460_18_LRQKeepAliveData_PDU,
{ "LRQKeepAliveData", "h460.18.LRQKeepAliveData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_18_callSignallingAddress,
{ "callSignallingAddress", "h460.18.callSignallingAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h460_18_callID,
{ "callID", "h460.18.callID",
FT_NONE, BASE_NONE, NULL, 0,
"CallIdentifier", HFILL }},
{ &hf_h460_18_lrqKeepAliveInterval,
{ "lrqKeepAliveInterval", "h460.18.lrqKeepAliveInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeToLive", HFILL }},
{ &hf_h460_19_h460_19_TraversalParameters_PDU,
{ "TraversalParameters", "h460.19.TraversalParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_19_multiplexedMediaChannel,
{ "multiplexedMediaChannel", "h460.19.multiplexedMediaChannel",
FT_UINT32, BASE_DEC, VALS(h245_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h460_19_multiplexedMediaControlChannel,
{ "multiplexedMediaControlChannel", "h460.19.multiplexedMediaControlChannel",
FT_UINT32, BASE_DEC, VALS(h245_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h460_19_multiplexID,
{ "multiplexID", "h460.19.multiplexID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h460_19_keepAliveChannel,
{ "keepAliveChannel", "h460.19.keepAliveChannel",
FT_UINT32, BASE_DEC, VALS(h245_TransportAddress_vals), 0,
"TransportAddress", HFILL }},
{ &hf_h460_19_keepAlivePayloadType,
{ "keepAlivePayloadType", "h460.19.keepAlivePayloadType",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_h460_19_keepAliveInterval,
{ "keepAliveInterval", "h460.19.keepAliveInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeToLive", HFILL }},
{ &hf_h460_21_h460_21_CapabilityAdvertisement_PDU,
{ "CapabilityAdvertisement", "h460.21.CapabilityAdvertisement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_21_receiveCapabilities,
{ "receiveCapabilities", "h460.21.receiveCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_21_transmitCapabilities,
{ "transmitCapabilities", "h460.21.transmitCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_TransmitCapabilities", HFILL }},
{ &hf_h460_21_transmitCapabilities_item,
{ "TransmitCapabilities", "h460.21.TransmitCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h460_21_capabilities,
{ "capabilities", "h460.21.capabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_Capability", HFILL }},
{ &hf_h460_21_capabilities_item,
{ "Capability", "h460.21.Capability",
FT_UINT32, BASE_DEC, VALS(h245_Capability_vals), 0,
NULL, HFILL }},
{ &hf_h460_21_maxGroups,
{ "maxGroups", "h460.21.maxGroups",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h460_21_groupIdentifer,
{ "groupIdentifer", "h460.21.groupIdentifer",
FT_BYTES, BASE_NONE, NULL, 0,
"GloballyUniqueID", HFILL }},
{ &hf_h460_21_capability,
{ "capability", "h460.21.capability",
FT_UINT32, BASE_DEC, VALS(h245_Capability_vals), 0,
NULL, HFILL }},
{ &hf_h460_21_sourceAddress,
{ "sourceAddress", "h460.21.sourceAddress",
FT_UINT32, BASE_DEC, VALS(h245_UnicastAddress_vals), 0,
"UnicastAddress", HFILL }},
#line 248 "../../asn1/h460/packet-h460-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/h460/packet-h460-ettarr.c"
&ett_h460_2_NumberPortabilityInfo,
&ett_h460_2_T_nUMBERPORTABILITYDATA,
&ett_h460_2_NumberPortabilityRejectReason,
&ett_h460_2_PortabilityAddress,
&ett_h460_2_NumberPortabilityTypeOfNumber,
&ett_h460_2_PortabilityTypeOfNumber,
&ett_h460_2_RegionalParameters,
&ett_h460_3_CircuitStatus,
&ett_h460_3_SEQUENCE_OF_CircuitStatusMap,
&ett_h460_3_CircuitStatusMap,
&ett_h460_3_CircuitStatusType,
&ett_h460_4_CallPriorityInfo,
&ett_h460_4_T_priorityValue,
&ett_h460_4_SEQUENCE_OF_ClearToken,
&ett_h460_4_SEQUENCE_OF_CryptoToken,
&ett_h460_4_T_rejectReason,
&ett_h460_4_CountryInternationalNetworkCallOriginationIdentification,
&ett_h460_4_T_numberingPlan,
&ett_h460_4_T_x121,
&ett_h460_4_T_e164,
&ett_h460_9_Extension,
&ett_h460_9_RTCPMeasures,
&ett_h460_9_T_mediaSenderMeasures,
&ett_h460_9_T_mediaReceiverMeasures,
&ett_h460_9_SEQUENCE_OF_Extension,
&ett_h460_9_PerCallQoSReport,
&ett_h460_9_SEQUENCE_OF_RTCPMeasures,
&ett_h460_9_QosMonitoringReportData,
&ett_h460_9_PeriodicQoSMonReport,
&ett_h460_9_SEQUENCE_OF_PerCallQoSReport,
&ett_h460_9_FinalQosMonReport,
&ett_h460_9_InterGKQosMonReport,
&ett_h460_9_ExtendedRTPMetrics,
&ett_h460_9_BurstMetrics,
&ett_h460_9_PLCtypes,
&ett_h460_9_JitterBufferParms,
&ett_h460_9_JitterBufferTypes,
&ett_h460_10_CallPartyCategoryInfo,
&ett_h460_14_MLPPInfo,
&ett_h460_14_MlppNotification,
&ett_h460_14_AlternateParty,
&ett_h460_14_ReleaseCall,
&ett_h460_15_SignallingChannelData,
&ett_h460_15_T_signallingChannelData,
&ett_h460_15_ChannelSuspendRequest,
&ett_h460_15_SEQUENCE_OF_TransportAddress,
&ett_h460_15_ChannelSuspendResponse,
&ett_h460_15_ChannelSuspendConfirm,
&ett_h460_15_ChannelSuspendCancel,
&ett_h460_15_ChannelResumeRequest,
&ett_h460_15_ChannelResumeResponse,
&ett_h460_18_IncomingCallIndication,
&ett_h460_18_LRQKeepAliveData,
&ett_h460_19_TraversalParameters,
&ett_h460_21_CapabilityAdvertisement,
&ett_h460_21_SEQUENCE_SIZE_1_256_OF_TransmitCapabilities,
&ett_h460_21_ReceiveCapabilities,
&ett_h460_21_SEQUENCE_SIZE_1_256_OF_Capability,
&ett_h460_21_TransmitCapabilities,
#line 253 "../../asn1/h460/packet-h460-template.c"
};
proto_h460 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h460, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
for (ftr=h460_feature_tab; ftr->id; ftr++) {
if (ftr->opt & GD) ftr->key_gd = g_strdup_printf("GenericData/%s", ftr->id);
if (ftr->opt & FD) ftr->key_fd = g_strdup_printf("FeatureDescriptor/%s", ftr->id);
if (ftr->opt & GM) ftr->key_gm = g_strdup_printf("GenericMessage/%s", ftr->id);
if (ftr->opt & GI) ftr->key_gi = g_strdup_printf("GenericInformation/%s", ftr->id);
if (ftr->content_pdu) ftr->content_hnd = new_create_dissector_handle(ftr->content_pdu, proto_h460);
}
}
void proto_reg_handoff_h460(void)
{
h460_feature_t *ftr;
dissector_handle_t h460_name_handle;
q931_ie_handle = find_dissector("q931.ie");
h225_ras_handle = find_dissector("h225.ras");
h460_name_handle = new_create_dissector_handle(dissect_h460_name, proto_h460);
for (ftr=h460_feature_tab; ftr->id; ftr++) {
if (ftr->key_gd) dissector_add_string("h225.gef.name", ftr->key_gd, h460_name_handle);
if (ftr->key_fd) dissector_add_string("h225.gef.name", ftr->key_fd, h460_name_handle);
if (ftr->key_gm) dissector_add_string("h245.gef.name", ftr->key_gm, h460_name_handle);
if (ftr->key_gi) dissector_add_string("h245.gef.name", ftr->key_gi, h460_name_handle);
if (ftr->content_hnd) {
if (ftr->key_gd) dissector_add_string("h225.gef.content", ftr->key_gd, ftr->content_hnd);
if (ftr->key_fd) dissector_add_string("h225.gef.content", ftr->key_fd, ftr->content_hnd);
if (ftr->key_gm) dissector_add_string("h245.gef.content", ftr->key_gm, ftr->content_hnd);
if (ftr->key_gi) dissector_add_string("h245.gef.content", ftr->key_gi, ftr->content_hnd);
}
}
}
