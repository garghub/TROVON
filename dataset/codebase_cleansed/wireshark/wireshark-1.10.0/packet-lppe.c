static int
dissect_lppe_OMA_LPPe_LPPeCompatibilityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LPPeVersion(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LPPeVersion, OMA_LPPe_LPPeVersion_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LPPeMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_IP_Address_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_IP_Address_RequestCapabilities, OMA_LPPe_IP_Address_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_1024(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CharArray(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 31, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-", 64,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_NonStandard_VendorOrOperatorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_NonStandard_VendorOrOperatorID, OMA_LPPe_NonStandard_VendorOrOperatorID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_VendorOrOperatorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_VendorOrOperatorID, OMA_LPPe_VendorOrOperatorID_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_VendorOrOperatorIDList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_VendorOrOperatorIDList, OMA_LPPe_VendorOrOperatorIDList_sequence_of,
1, maxVendorOrOperatorIDList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerSupportReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerSupportReq, OMA_LPPe_AssistanceContainerSupportReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerSupportReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerSupportReq, OMA_LPPe_LocationInformationContainerSupportReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocationChange_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocationChange_RequestCapabilities, OMA_LPPe_RelativeLocationChange_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HighAccuracyFormatCapabilitiesReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HighAccuracyFormatCapabilitiesReq, OMA_LPPe_HighAccuracyFormatCapabilitiesReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedAssistanceData_ReqCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedAssistanceData_ReqCapabilities, OMA_LPPe_SegmentedAssistanceData_ReqCapabilities_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_VendorOrOperatorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_VendorOrOperatorID, SEQUENCE_SIZE_1_128_OF_OMA_LPPe_VendorOrOperatorID_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointCapabilitiesReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointCapabilitiesReq, OMA_LPPe_ReferencePointCapabilitiesReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ScheduledLocation_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ScheduledLocation_RequestCapabilities, OMA_LPPe_ScheduledLocation_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AccessCapabilitiesReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AccessCapabilitiesReq, OMA_LPPe_AccessCapabilitiesReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedLocationInformation_ReqCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedLocationInformation_ReqCapabilities, OMA_LPPe_SegmentedLocationInformation_ReqCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsRequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsRequestCapabilities, OMA_LPPe_CommonIEsRequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_RequestCapabilities, OMA_LPPe_AGNSS_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_RequestCapabilities, OMA_LPPe_OTDOA_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_RequestCapabilities, OMA_LPPe_EOTD_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestCapabilities, OMA_LPPe_OTDOA_UTRA_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_RequestCapabilities, OMA_LPPe_ECID_LTE_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_RequestCapabilities, OMA_LPPe_ECID_GSM_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_RequestCapabilities, OMA_LPPe_ECID_UTRA_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_RequestCapabilities, OMA_LPPe_WLAN_AP_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_RequestCapabilities, OMA_LPPe_ECID_WiMax_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_RequestCapabilities, OMA_LPPe_Sensor_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_srnTechnologies(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_Technologies(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_Technologies, OMA_LPPe_SRN_Technologies_sequence);
return offset;
}
static int
dissect_lppe_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_srnVendorInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_srnVendorInformation, T_srnVendorInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_Category(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_Category, OMA_LPPe_SRN_Category_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_RequestCapabilities, OMA_LPPe_SRN_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RequestCapabilities, OMA_LPPe_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_iP_Address_support(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_IP_Address_Capabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_IP_Address_Capabilities, OMA_LPPe_IP_Address_Capabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerID, OMA_LPPe_AssistanceContainerID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerList, OMA_LPPe_AssistanceContainerList_sequence_of,
1, maxAssistanceContainerList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_VendorOrOperatorAssistanceContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_VendorOrOperatorAssistanceContainerList, OMA_LPPe_VendorOrOperatorAssistanceContainerList_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerSupport, OMA_LPPe_AssistanceContainerSupport_sequence_of,
1, maxVendorOrOperatorIDList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerID, OMA_LPPe_LocationInformationContainerID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerList, OMA_LPPe_LocationInformationContainerList_sequence_of,
1, maxLocationInformationContainerList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_VendorOrOperatorLocationInformationContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_VendorOrOperatorLocationInformationContainerList, OMA_LPPe_VendorOrOperatorLocationInformationContainerList_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerSupport, OMA_LPPe_LocationInformationContainerSupport_sequence_of,
1, maxVendorOrOperatorIDList, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 5U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocationChange_Capabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocationChange_Capabilities, OMA_LPPe_RelativeLocationChange_Capabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HighAccuracyFormatCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_2_4096(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2U, 4096U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_5000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 5000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedAssistanceData_ProvideCapabs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedAssistanceData_ProvideCapabs, OMA_LPPe_SegmentedAssistanceData_ProvideCapabs_sequence);
return offset;
}
static int
dissect_lppe_T_relativeLocationReportingSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_mapDataSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mapDataSupport, T_mapDataSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointProviderSupportElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointProviderSupportElement, OMA_LPPe_ReferencePointProviderSupportElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_ReferencePointProviderSupportElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_ReferencePointProviderSupportElement, SEQUENCE_SIZE_1_128_OF_OMA_LPPe_ReferencePointProviderSupportElement_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointCapabilities, OMA_LPPe_ReferencePointCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_networkTimeReference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ScheduledLocation_Capabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ScheduledLocation_Capabilities, OMA_LPPe_ScheduledLocation_Capabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_FixedAccessTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WirelessAccessTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AccessCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AccessCapabilities, OMA_LPPe_AccessCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedLocationInformation_ProvideCapabs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedLocationInformation_ProvideCapabs, OMA_LPPe_SegmentedLocationInformation_ProvideCapabs_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsProvideCapabilities, OMA_LPPe_CommonIEsProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_ionoModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_IonosphericModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_IonosphericModelSupport, OMA_LPPe_AGNSS_IonosphericModelSupport_sequence);
return offset;
}
static int
dissect_lppe_T_tropoModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TroposphereModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TroposphereModelSupport, OMA_LPPe_AGNSS_TroposphereModelSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceSupport, OMA_LPPe_AGNSS_AltitudeAssistanceSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_SolarRadiationSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_SolarRadiationSupport, OMA_LPPe_AGNSS_SolarRadiationSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPsupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPsupport, OMA_LPPe_AGNSS_CCPsupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataSupport, OMA_LPPe_AGNSS_CommonAssistanceDataSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_MechanicsSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_MechanicsSupport, OMA_LPPe_AGNSS_MechanicsSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBsupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBsupport, OMA_LPPe_AGNSS_DCBsupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelAccuracyModelDegradationSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelAccuracyModelDegradationSupport, OMA_LPPe_AGNSS_NavModelAccuracyModelDegradationSupport_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_navModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_navModelSupport, T_navModelSupport_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelSupport, OMA_LPPe_AGNSS_NavModelSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistDataSupportElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataSupportElement, OMA_LPPe_AGNSS_GenericAssistDataSupportElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataSupport, OMA_LPPe_AGNSS_GenericAssistanceDataSupport_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AssistanceDataSupportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AssistanceDataSupportList, OMA_LPPe_AGNSS_AssistanceDataSupportList_sequence);
return offset;
}
static int
dissect_lppe_T_ionosphereMeasurementSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_EnvironmentObservationSupportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_EnvironmentObservationSupportList, OMA_LPPe_AGNSS_EnvironmentObservationSupportList_sequence);
return offset;
}
static int
dissect_lppe_T_modeSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_haGNSSantennaInformationSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport, OMA_LPPe_AGNSS_HAgnssPerGNSSsupport_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssSupport, OMA_LPPe_AGNSS_HAgnssSupport_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_ProvideCapabilities, OMA_LPPe_AGNSS_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_eNodeB_AD_sup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_eNodeB_AD_sup, T_eNodeB_AD_sup_sequence);
return offset;
}
static int
dissect_lppe_T_home_eNodeB_AD_sup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_home_eNodeB_AD_sup, T_home_eNodeB_AD_sup_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_ProvideCapabilities, OMA_LPPe_OTDOA_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_eotdSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_ProvideCapabilities, OMA_LPPe_EOTD_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideCapabilities, OMA_LPPe_OTDOA_UTRA_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_ecid_lte_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_ecid_lte_eNodeB_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_ecid_utra_HeNB_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_ProvideCapabilities, OMA_LPPe_ECID_LTE_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_ecid_gsm_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_ecid_gsm_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_ProvideCapabilities, OMA_LPPe_ECID_GSM_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_ecid_utra_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_ecid_utra_nodeB_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_ecid_utra_HNB_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_ProvideCapabilities, OMA_LPPe_ECID_UTRA_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_wlan_ecid_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Type_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_48(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
48, 48, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_ID, OMA_LPPe_WLAN_AP_ID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Capability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_Capability, OMA_LPPe_WLAN_AP_Capability_sequence);
return offset;
}
static int
dissect_lppe_T_wlan_ap_ADSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_ProvideCapabilities, OMA_LPPe_WLAN_AP_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_ecid_wimax_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_ProvideCapabilities, OMA_LPPe_ECID_WiMax_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_ProvideCapabilities, OMA_LPPe_Sensor_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_T_srnMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_MeasurementMask(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_MeasurementMask, OMA_LPPe_SRN_MeasurementMask_sequence);
return offset;
}
static int
dissect_lppe_T_supportedAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ProvideCapabilitiesElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ProvideCapabilitiesElement, OMA_LPPe_SRN_ProvideCapabilitiesElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ProvideCapabilitiesElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ProvideCapabilitiesElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ProvideCapabilitiesElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ProvideCapabilities, OMA_LPPe_SRN_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ProvideCapabilities, OMA_LPPe_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_VendorOrOperatorAssistanceDataIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_VendorOrOperatorAssistanceDataIdentifier, OMA_LPPe_VendorOrOperatorAssistanceDataIdentifier_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainer_DataSerialNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainer_DataSerialNumber, OMA_LPPe_AssistanceContainer_DataSerialNumber_sequence);
return offset;
}
static int
dissect_lppe_T_checkLatest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerCheckOrUpdateReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerCheckOrUpdateReq, OMA_LPPe_AssistanceContainerCheckOrUpdateReq_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_2881(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2881U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_2881(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 2881U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ValidityPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ValidityPeriod, OMA_LPPe_ValidityPeriod_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerRequest, OMA_LPPe_AssistanceContainerRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerRequestList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerRequestList, OMA_LPPe_AssistanceContainerRequestList_sequence_of,
1, maxAssistanceContainerList, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_TypeOfADRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RequestPeriodicADwithUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RequestPeriodicADwithUpdate, OMA_LPPe_RequestPeriodicADwithUpdate_sequence);
return offset;
}
static int
dissect_lppe_T_segmentedADpreference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Session_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Session_ID, OMA_LPPe_Session_ID_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_4096(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4096U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedADResume(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedADResume, OMA_LPPe_SegmentedADResume_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointAssistanceReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointAssistanceReqElement, OMA_LPPe_ReferencePointAssistanceReqElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_ReferencePointAssistanceReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_ReferencePointAssistanceReqElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_ReferencePointAssistanceReqElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointAssistanceReq, OMA_LPPe_ReferencePointAssistanceReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsRequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsRequestAssistanceData, OMA_LPPe_CommonIEsRequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_ionoreq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_1_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_89(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 89U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Duration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Duration, OMA_LPPe_Duration_sequence);
return offset;
}
static int
dissect_lppe_T_staticModels_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_staticModels_01, T_staticModels_01_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersRequest, OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersRequest_sequence);
return offset;
}
static int
dissect_lppe_T_periodicModels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_periodicModels, T_periodicModels_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_IonosphericModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_IonosphericModelReq, OMA_LPPe_AGNSS_IonosphericModelReq_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_troposphereModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TroposphereModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TroposphereModelReq, OMA_LPPe_AGNSS_TroposphereModelReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceReq, OMA_LPPe_AGNSS_AltitudeAssistanceReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_SolarRadiationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_SolarRadiationReq, OMA_LPPe_AGNSS_SolarRadiationReq_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M2147483648_2147483647(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
G_MININT32, 2147483647U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_99(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 99U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M64000_1280000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64000, 1280000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HighAccuracy3Dposition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HighAccuracy3Dposition, OMA_LPPe_HighAccuracy3Dposition_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_QoR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_posBasedReferenceStationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_posBasedReferenceStationRequest, T_posBasedReferenceStationRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPreferenceStationID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationID, OMA_LPPe_AGNSS_CCPreferenceStationID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_ReferenceStationIDlist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_ReferenceStationIDlist, OMA_LPPe_AGNSS_ReferenceStationIDlist_sequence_of,
1, maxReferenceStations, FALSE);
return offset;
}
static int
dissect_lppe_T_refStation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_refStation, T_refStation_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_ccpCommonRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_ccpCommonRequest, T_ccpCommonRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPrequestControlParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPrequestControlParameters, OMA_LPPe_AGNSS_CCPrequestControlParameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataReq, OMA_LPPe_AGNSS_CommonAssistanceDataReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WaIonoSurfaceRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WaIonoSurfaceRequest, OMA_LPPe_AGNSS_WaIonoSurfaceRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_MechanicsReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_MechanicsReq, OMA_LPPe_AGNSS_MechanicsReq_sequence);
return offset;
}
static int
dissect_lppe_T_pd_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_reference_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_reference_01, T_reference_01_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBreq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBreq, OMA_LPPe_AGNSS_DCBreq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelReq, OMA_LPPe_AGNSS_NavModelDegradationModelReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPassistGenericReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericReq, OMA_LPPe_AGNSS_CCPassistGenericReq_sequence);
return offset;
}
static int
dissect_lppe_T_navModelID_PrefList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_navModelID_PrefList, T_navModelID_PrefList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavigationModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavigationModelReq, OMA_LPPe_AGNSS_NavigationModelReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistDataReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataReqElement, OMA_LPPe_AGNSS_GenericAssistDataReqElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataReq, OMA_LPPe_AGNSS_GenericAssistanceDataReq_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_RequestAssistanceData, OMA_LPPe_AGNSS_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_503(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_lteCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_lteCell, T_lteCell_sequence);
return offset;
}
static int
dissect_lppe_T_requestedCells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_RequestAssistanceData, OMA_LPPe_OTDOA_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_eotdAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_RequestAssistanceData, OMA_LPPe_EOTD_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_otdoaUtraAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestAssistanceData, OMA_LPPe_OTDOA_UTRA_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_eNBrequestedAD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_heNBrequestedAD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_RequestAssistanceData, OMA_LPPe_ECID_LTE_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_requestedAD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_RequestAssistanceData, OMA_LPPe_ECID_GSM_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_nBrequestedAD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_hNBrequestedAD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_RequestAssistanceData, OMA_LPPe_ECID_UTRA_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_requestedAD_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_RequestAssistanceData, OMA_LPPe_WLAN_AP_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_RequestAssistanceData, OMA_LPPe_Sensor_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupUniqueID, OMA_LPPe_SRN_SRNgroupUniqueID_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_256_OF_OMA_LPPe_SRN_SRNgroupUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_256_OF_OMA_LPPe_SRN_SRNgroupUniqueID, SEQUENCE_SIZE_1_256_OF_OMA_LPPe_SRN_SRNgroupUniqueID_sequence_of,
1, 256, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNProvideList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNProvideList, OMA_LPPe_SRN_SRNProvideList_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupRequest, OMA_LPPe_SRN_SRNgroupRequest_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_nfc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_nfc, T_nfc_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
12, 12, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_1_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_1_18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 18, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_mobileCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mobileCode, T_mobileCode_sequence);
return offset;
}
static int
dissect_lppe_T_srn_id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_srn_id, T_srn_id_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNid, OMA_LPPe_SRN_SRNid_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNid, SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNid_sequence_of,
1, 1024, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequestElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequestElement, OMA_LPPe_SRN_SRNgroupUpdateRequestElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequest, OMA_LPPe_SRN_SRNgroupUpdateRequest_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_T_srnGroup_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_srnGroup_01, T_srnGroup_01_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_antennaPatternID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_antennaPatternID, T_antennaPatternID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_AntennaPatternRequestElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_AntennaPatternRequestElement, OMA_LPPe_SRN_AntennaPatternRequestElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_AntennaPatternRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_AntennaPatternRequest, OMA_LPPe_SRN_AntennaPatternRequest_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_RequestAssistanceData, OMA_LPPe_SRN_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RequestAssistanceData, OMA_LPPe_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_checkOrUpdateOrError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_5000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 5000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_2_9180(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2U, 9180U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_4589(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4589U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_9179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9179U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RleList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RleList, OMA_LPPe_RleList_sequence_of,
1, 65535, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ValidityArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ValidityArea, OMA_LPPe_ValidityArea_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerData, OMA_LPPe_AssistanceContainerData_sequence);
return offset;
}
static int
dissect_lppe_T_dataResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_dataResult, T_dataResult_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_serverError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerProvideError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerProvideError, OMA_LPPe_AssistanceContainerProvideError_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerProvide, OMA_LPPe_AssistanceContainerProvide_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AssistanceContainerProvideList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AssistanceContainerProvideList, OMA_LPPe_AssistanceContainerProvideList_sequence_of,
1, maxAssistanceContainerList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_TypeOfADProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ProvidePeriodicADwithUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ProvidePeriodicADwithUpdate, OMA_LPPe_ProvidePeriodicADwithUpdate_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedADTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedADTransfer, OMA_LPPe_SegmentedADTransfer_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointUniqueID, OMA_LPPe_ReferencePointUniqueID_sequence);
return offset;
}
static int
dissect_lppe_T_referencePointGeographicLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_referencePointGeographicLocation, T_referencePointGeographicLocation_choice,
NULL);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 256, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CivicAddressElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CivicAddressElement, OMA_LPPe_CivicAddressElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CivicAddressElementList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CivicAddressElementList, OMA_LPPe_CivicAddressElementList_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CivicLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CivicLocation, OMA_LPPe_CivicLocation_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M20_235(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-20, 235U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_units(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_arc_second_units(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_M524288_524287(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-524288, 524287U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M32768_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-32768, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_GeodeticUncertaintyAndConfidence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_GeodeticUncertaintyAndConfidence, OMA_LPPe_GeodeticUncertaintyAndConfidence_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_GeodeticRelativeAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_GeodeticRelativeAltitude, OMA_LPPe_GeodeticRelativeAltitude_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M255_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-255, 256U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CivicUncertaintyAndConfidence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CivicUncertaintyAndConfidence, OMA_LPPe_CivicUncertaintyAndConfidence_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CivicRelativeAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CivicRelativeAltitude, OMA_LPPe_CivicRelativeAltitude_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeAltitude, OMA_LPPe_RelativeAltitude_sequence);
return offset;
}
static int
dissect_lppe_T_ellipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_ellipse, T_ellipse_sequence);
return offset;
}
static int
dissect_lppe_T_uncShape(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_uncShape, T_uncShape_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HorizontalUncertaintyAndConfidence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HorizontalUncertaintyAndConfidence, OMA_LPPe_HorizontalUncertaintyAndConfidence_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocation, OMA_LPPe_RelativeLocation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePointRelationship(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePointRelationship, OMA_LPPe_ReferencePointRelationship_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointRelationship(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointRelationship, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointRelationship_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Uri(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:/?#[]@!$&'()*+,;=-._~", 84,
NULL);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 64, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_MapDataReference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_MapDataReference, OMA_LPPe_MapDataReference_sequence);
return offset;
}
static int
dissect_lppe_T_mapDataUrl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mapDataUrl, T_mapDataUrl_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_mapProvider(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mapProvider, T_mapProvider_choice,
NULL);
return offset;
}
static int
dissect_lppe_VisibleString_SIZE_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_VisibleString(tvb, offset, actx, tree, hf_index,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_T_mapAssociation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mapAssociation, T_mapAssociation_choice,
NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_359(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 359U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_MapDataReferenceElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_MapDataReferenceElement, OMA_LPPe_MapDataReferenceElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_MapDataInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_MapDataInformation, OMA_LPPe_MapDataInformation_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ReferencePoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ReferencePoint, OMA_LPPe_ReferencePoint_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsProvideAssistanceData, OMA_LPPe_CommonIEsProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M128_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-128, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalKlobucharModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModel, OMA_LPPe_AGNSS_LocalKlobucharModel_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalKlobucharModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalKlobucharModel, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalKlobucharModel_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelElement, OMA_LPPe_AGNSS_LocalKlobucharModelElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelList, OMA_LPPe_AGNSS_LocalKlobucharModelList_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NoaaScales(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_ionoIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_ionoIndex, T_ionoIndex_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_RleIonoElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_RleIonoElement, OMA_LPPe_AGNSS_RleIonoElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_RleListIono(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_RleListIono, OMA_LPPe_AGNSS_RleListIono_sequence_of,
1, 65535, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_StormElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_StormElement, OMA_LPPe_AGNSS_StormElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_StormList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_StormList, OMA_LPPe_AGNSS_StormList_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_IonoStormIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_IonoStormIndication, OMA_LPPe_AGNSS_IonoStormIndication_sequence);
return offset;
}
static int
dissect_lppe_T_staticModels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_staticModels, T_staticModels_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersProvide, OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersProvide_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceCommon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceCommon, OMA_LPPe_AGNSS_WideAreaIonoSurfaceCommon_sequence);
return offset;
}
static int
dissect_lppe_T_waIono(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_waIono, T_waIono_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_IonosphericModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_IonosphericModel, OMA_LPPe_AGNSS_IonosphericModel_choice,
NULL);
return offset;
}
static int
dissect_lppe_INTEGER_M1000_8192(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1000, 8192U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M8192_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8192, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_MappingFunctionParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_MappingFunctionParameters, OMA_LPPe_AGNSS_MappingFunctionParameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement, OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayAreaElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayAreaElement, OMA_LPPe_AGNSS_LocalTroposphereDelayAreaElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayList, OMA_LPPe_AGNSS_LocalTroposphereDelayList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M1024_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1024, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M64_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64, 63U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M16_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16, 16U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M8_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8, 7U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement, OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersAreaElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersAreaElement, OMA_LPPe_AGNSS_LocalSurfaceParametersAreaElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersList, OMA_LPPe_AGNSS_LocalSurfaceParametersList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TroposphereModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TroposphereModel, OMA_LPPe_AGNSS_TroposphereModel_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_PressureAssistanceElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_PressureAssistanceElement, OMA_LPPe_AGNSS_PressureAssistanceElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_PressureAssistanceElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_PressureAssistanceElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_PressureAssistanceElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceAreaElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceAreaElement, OMA_LPPe_AGNSS_AltitudeAssistanceAreaElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceList, OMA_LPPe_AGNSS_AltitudeAssistanceList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1000_2000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1000U, 2000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_SolarRadiation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_SolarRadiation, OMA_LPPe_AGNSS_SolarRadiation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPprovideCommonParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPprovideCommonParameters, OMA_LPPe_AGNSS_CCPprovideCommonParameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPsignalSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPsignalSupport, OMA_LPPe_AGNSS_CCPsignalSupport_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPsignalSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPsignalSupport, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPsignalSupport_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPsupportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPsupportArea, OMA_LPPe_AGNSS_CCPsupportArea_sequence);
return offset;
}
static int
dissect_lppe_T_antennaDescription(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_antennaDescription, T_antennaDescription_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_AntennaDescription(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_AntennaDescription, OMA_LPPe_AGNSS_AntennaDescription_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPreferenceStationElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationElement, OMA_LPPe_AGNSS_CCPreferenceStationElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPreferenceStationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationList, OMA_LPPe_AGNSS_CCPreferenceStationList_sequence_of,
0, maxReferenceStations, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPprovideControlParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPprovideControlParameters, OMA_LPPe_AGNSS_CCPprovideControlParameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPassistCommonProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPassistCommonProvide, OMA_LPPe_AGNSS_CCPassistCommonProvide_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CommonAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CommonAssistData, OMA_LPPe_AGNSS_CommonAssistData_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M4096_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4096, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVelement, OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVelement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist, OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M30000_30000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-30000, 30000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_PCOelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_PCOelement, OMA_LPPe_AGNSS_PCOelement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_SVtype(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_1000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_svInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_svInfo, T_svInfo_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_MechanicsElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_MechanicsElement, OMA_LPPe_AGNSS_MechanicsElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_MechanicsForAllSVs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_MechanicsForAllSVs, OMA_LPPe_AGNSS_MechanicsForAllSVs_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_T_pd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_reference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_reference, T_reference_sequence);
return offset;
}
static int
dissect_lppe_T_pd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBelement, OMA_LPPe_AGNSS_DCBelement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBlist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBlist, OMA_LPPe_AGNSS_DCBlist_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBlistElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBlistElement, OMA_LPPe_AGNSS_DCBlistElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_DCBsForAllSVs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_DCBsForAllSVs, OMA_LPPe_AGNSS_DCBsForAllSVs_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_ClockModelDegradationModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_ClockModelDegradationModel, OMA_LPPe_AGNSS_ClockModelDegradationModel_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_OrbitModelDegradationModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_OrbitModelDegradationModel, OMA_LPPe_AGNSS_OrbitModelDegradationModel_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelElement, OMA_LPPe_AGNSS_NavModelDegradationModelElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelList, OMA_LPPe_AGNSS_NavModelDegradationModelList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_14989622(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14989622U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CodePhaseError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CodePhaseError, OMA_LPPe_AGNSS_CodePhaseError_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPperSVelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPperSVelement, OMA_LPPe_AGNSS_CCPperSVelement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_CCPperSVelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_CCPperSVelement, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_CCPperSVelement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPperSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPperSignalElement, OMA_LPPe_AGNSS_CCPperSignalElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPperSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPperSignalElement, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPperSignalElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvideElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvideElement, OMA_LPPe_AGNSS_CCPassistGenericProvideElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvide, OMA_LPPe_AGNSS_CCPassistGenericProvide_sequence_of,
1, maxReferenceStations, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_30(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 30U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_fixedInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fixedInterval, T_fixedInterval_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M100000000_100000000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-100000000, 100000000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M1000000000_1000000000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1000000000, 1000000000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModel_BigNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModel_BigNumber, OMA_LPPe_AGNSS_NavModel_BigNumber_sequence);
return offset;
}
static int
dissect_lppe_T_bases(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_bases, T_bases_sequence);
return offset;
}
static int
dissect_lppe_T_referencedTo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_1000000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1000000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_10000000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10000000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModel_STDmatrix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModel_STDmatrix, OMA_LPPe_AGNSS_NavModel_STDmatrix_sequence);
return offset;
}
static int
dissect_lppe_T_rateRecord(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_rateRecord, T_rateRecord_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModel_PVTelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModel_PVTelement, OMA_LPPe_AGNSS_NavModel_PVTelement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_NavModel_PVTelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_NavModel_PVTelement, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_NavModel_PVTelement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement, OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_97_OF_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_97_OF_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement, SEQUENCE_SIZE_1_97_OF_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement_sequence_of,
1, 97, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBased(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBased, OMA_LPPe_AGNSS_NavModel_CoordinateBased_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_NavModelList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_NavModelList, OMA_LPPe_AGNSS_NavModelList_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistDataElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataElement, OMA_LPPe_AGNSS_GenericAssistDataElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_GenericAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_GenericAssistData, OMA_LPPe_AGNSS_GenericAssistData_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_T_waIonoErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_ccpErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocationServerErrorCauses, OMA_LPPe_AGNSS_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_highAccuracyErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_ionosphereMeasurementErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_environmentObservationErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_haGNSSerrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TargetDeviceErrorCauses, OMA_LPPe_AGNSS_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_Error, OMA_LPPe_AGNSS_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_ProvideAssistanceData, OMA_LPPe_AGNSS_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_resolution(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_RTDquality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_RTDquality, OMA_LPPe_OTDOA_RTDquality_sequence);
return offset;
}
static int
dissect_lppe_T_cellLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_cellLocation, T_cellLocation_sequence);
return offset;
}
static int
dissect_lppe_T_femtoCellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_femtoCellInfo, T_femtoCellInfo_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_PositionCalculationInfoRef(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_PositionCalculationInfoRef, OMA_LPPe_OTDOA_PositionCalculationInfoRef_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_ReferenceCellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_ReferenceCellInfo, OMA_LPPe_OTDOA_ReferenceCellInfo_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_10229(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10229U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_99999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 99999U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M100_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-100, 100U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_rtdInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_rtdInfo, T_rtdInfo_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_CellData, OMA_LPPe_OTDOA_CellData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_OTDOA_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_OTDOA_CellData, SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_OTDOA_CellData_sequence_of,
1, maxLTEMacroCells, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB, OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB, SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB_sequence_of,
1, maxLTEeNBs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB, OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB, SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB_sequence_of,
1, maxLTEHeNBs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_NeighbourFreqCellInfoList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_NeighbourFreqCellInfoList, OMA_LPPe_OTDOA_NeighbourFreqCellInfoList_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoList, OMA_LPPe_OTDOA_NeighbourCellInfoList_sequence_of,
1, maxFreqLayers, FALSE);
return offset;
}
static int
dissect_lppe_T_cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_LocationServerErrorCauses, OMA_LPPe_OTDOA_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_TargetDeviceErrorCauses, OMA_LPPe_OTDOA_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_Error, OMA_LPPe_OTDOA_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_ProvideAssistanceData, OMA_LPPe_OTDOA_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CellNonUniqueIDGERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CellNonUniqueIDGERAN, OMA_LPPe_CellNonUniqueIDGERAN_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_TimeSlotScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_btsPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_btsPosition, T_btsPosition_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ReferenceBTSForAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_ReferenceBTSForAssistance, OMA_LPPe_EOTD_ReferenceBTSForAssistance_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MultiFrameOffset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 51U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RoughRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1250U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_1250(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1250U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ExpectedOTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_ExpectedOTD, OMA_LPPe_EOTD_ExpectedOTD_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_FineRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RelDistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-200000, 200000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RelativeAlt(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4000, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_relativePos(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_relativePos, OMA_LPPe_EOTD_relativePos_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_CalcAssistanceBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_CalcAssistanceBTS, OMA_LPPe_EOTD_CalcAssistanceBTS_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MsrAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_MsrAssistBTS, OMA_LPPe_EOTD_MsrAssistBTS_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MsrAssistDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_MsrAssistDataList, OMA_LPPe_EOTD_MsrAssistDataList_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_AssistBTSData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_AssistBTSData, OMA_LPPe_EOTD_AssistBTSData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_SystemInfoAssistBTS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_SystemInfoAssistBTS, OMA_LPPe_EOTD_SystemInfoAssistBTS_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_SystemInfoAssistDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_SystemInfoAssistDataList, OMA_LPPe_EOTD_SystemInfoAssistDataList_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_LocationServerErrorCauses, OMA_LPPe_EOTD_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_TargetDeviceErrorCauses, OMA_LPPe_EOTD_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_Error, OMA_LPPe_EOTD_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_ProvideAssistanceData, OMA_LPPe_EOTD_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_PrimaryScramblingCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info, OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info_sequence);
return offset;
}
static int
dissect_lppe_T_fdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd, T_fdd_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_BurstType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_MidambleShiftLong(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_TimeSlotNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_CellParametersID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_CellAndChannelIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_CellAndChannelIdentity, OMA_LPPe_OTDOA_UTRA_CellAndChannelIdentity_sequence);
return offset;
}
static int
dissect_lppe_T_tdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd, T_tdd_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo, T_modeSpecificInfo_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_UTRA_FrequencyInfoFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_UTRA_FrequencyInfoFDD, OMA_LPPe_UTRA_FrequencyInfoFDD_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_UTRA_FrequencyInfoTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_UTRA_FrequencyInfoTDD, OMA_LPPe_UTRA_FrequencyInfoTDD_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_UTRA_ModeSpecificInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_UTRA_ModeSpecificInfo, OMA_LPPe_UTRA_ModeSpecificInfo_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_UTRA_FrequencyInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_UTRA_FrequencyInfo, OMA_LPPe_UTRA_FrequencyInfo_sequence);
return offset;
}
static int
dissect_lppe_T_cellPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_cellPosition, T_cellPosition_choice,
NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_327(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 327U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_70274(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 70274U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_RefPosAssist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_RefPosAssist, OMA_LPPe_OTDOA_UTRA_RefPosAssist_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_IP_Spacing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_IP_Length(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_9(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_10_25(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
10U, 25U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_BurstModeParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_BurstModeParameters, OMA_LPPe_OTDOA_UTRA_BurstModeParameters_sequence);
return offset;
}
static int
dissect_lppe_T_fdd_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_02, T_fdd_02_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_IP_Spacing_TDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_IP_PCCPCH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppe_T_tdd_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_02, T_tdd_02_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo_02, T_modeSpecificInfo_02_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_IPDL_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_IPDL_Parameters, OMA_LPPe_OTDOA_UTRA_IPDL_Parameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_ReferenceCellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_ReferenceCellInfo, OMA_LPPe_OTDOA_UTRA_ReferenceCellInfo_sequence);
return offset;
}
static int
dissect_lppe_T_fdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_01, T_fdd_01_sequence);
return offset;
}
static int
dissect_lppe_T_tdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_01, T_tdd_01_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo_01, T_modeSpecificInfo_01_choice,
NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_38399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 38399U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_RelTimeDifference1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_RelTimeDifference1, OMA_LPPe_OTDOA_UTRA_SFN_SFN_RelTimeDifference1_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_SFN_OffsetValidity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_Drift(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
29, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_SearchWindowSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_M20000_20000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-20000, 20000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M4000_4000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4000, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_fineSFN_SFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_PositioningAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_PositioningAssistance, OMA_LPPe_OTDOA_UTRA_PositioningAssistance_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellInfo, OMA_LPPe_OTDOA_UTRA_NeighborCellInfo_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellList, OMA_LPPe_OTDOA_UTRA_NeighborCellList_sequence_of,
1, utra_maxCellMeas, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_LocationServerErrorCauses, OMA_LPPe_OTDOA_UTRA_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_TargetDeviceErrorCauses, OMA_LPPe_OTDOA_UTRA_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_Error, OMA_LPPe_OTDOA_UTRA_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideAssistanceData, OMA_LPPe_OTDOA_UTRA_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_mcc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mcc, T_mcc_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_mnc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mnc, T_mnc_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_plmn_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_plmn_Identity, T_plmn_Identity_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_M127_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 128U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_antennaPortConfig(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_1_360(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 360U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_360(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 360U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_CellData, OMA_LPPe_ECID_LTE_CellData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_ECID_LTE_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_ECID_LTE_CellData, SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_ECID_LTE_CellData_sequence_of,
1, maxLTEMacroCells, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_eNodeBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_eNodeBData, OMA_LPPe_ECID_LTE_eNodeBData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_ECID_LTE_eNodeBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_ECID_LTE_eNodeBData, SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_ECID_LTE_eNodeBData_sequence_of,
1, maxLTEeNBs, FALSE);
return offset;
}
static int
dissect_lppe_T_areaType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_referenceLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_refPointAndArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_refPointAndArea, T_refPointAndArea_sequence);
return offset;
}
static int
dissect_lppe_T_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLANFemtoCoverageAreaElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLANFemtoCoverageAreaElement, OMA_LPPe_WLANFemtoCoverageAreaElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_WLANFemtoCoverageAreaElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_WLANFemtoCoverageAreaElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_WLANFemtoCoverageAreaElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLANFemtoCoverageArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLANFemtoCoverageArea, OMA_LPPe_WLANFemtoCoverageArea_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_HeNBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_HeNBData, OMA_LPPe_ECID_LTE_HeNBData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_ECID_LTE_HeNBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_ECID_LTE_HeNBData, SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_ECID_LTE_HeNBData_sequence_of,
1, maxLTEHeNBs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_NetworkData, OMA_LPPe_ECID_LTE_NetworkData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTENetworks_OF_OMA_LPPe_ECID_LTE_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTENetworks_OF_OMA_LPPe_ECID_LTE_NetworkData, SEQUENCE_SIZE_1_maxLTENetworks_OF_OMA_LPPe_ECID_LTE_NetworkData_sequence_of,
1, maxLTENetworks, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_LocationServerErrorCauses, OMA_LPPe_ECID_LTE_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_TargetDeviceErrorCauses, OMA_LPPe_ECID_LTE_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_Error, OMA_LPPe_ECID_LTE_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_ProvideAssistanceData, OMA_LPPe_ECID_LTE_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_mcc_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mcc_01, T_mcc_01_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_mnc_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mnc_01, T_mnc_01_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_plmn_Identity_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_plmn_Identity_01, T_plmn_Identity_01_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CellLocalIdGERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CellLocalIdGERAN, OMA_LPPe_CellLocalIdGERAN_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_CellData, OMA_LPPe_ECID_GSM_CellData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxGSMCells_OF_OMA_LPPe_ECID_GSM_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxGSMCells_OF_OMA_LPPe_ECID_GSM_CellData, SEQUENCE_SIZE_1_maxGSMCells_OF_OMA_LPPe_ECID_GSM_CellData_sequence_of,
1, maxGSMCells, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_BaseStationData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_BaseStationData, OMA_LPPe_ECID_GSM_BaseStationData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxGSMBaseStations_OF_OMA_LPPe_ECID_GSM_BaseStationData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxGSMBaseStations_OF_OMA_LPPe_ECID_GSM_BaseStationData, SEQUENCE_SIZE_1_maxGSMBaseStations_OF_OMA_LPPe_ECID_GSM_BaseStationData_sequence_of,
1, maxGSMBaseStations, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_NetworkData, OMA_LPPe_ECID_GSM_NetworkData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxGSMNetworks_OF_OMA_LPPe_ECID_GSM_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxGSMNetworks_OF_OMA_LPPe_ECID_GSM_NetworkData, SEQUENCE_SIZE_1_maxGSMNetworks_OF_OMA_LPPe_ECID_GSM_NetworkData_sequence_of,
1, maxGSMNetworks, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_08(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_LocationServerErrorCauses, OMA_LPPe_ECID_GSM_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_09(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_TargetDeviceErrorCauses, OMA_LPPe_ECID_GSM_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_Error, OMA_LPPe_ECID_GSM_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_ProvideAssistanceData, OMA_LPPe_ECID_GSM_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_mcc_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mcc_02, T_mcc_02_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_mnc_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mnc_02, T_mnc_02_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_plmn_Identity_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_plmn_Identity_02, T_plmn_Identity_02_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_fdd_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_05, T_fdd_05_sequence);
return offset;
}
static int
dissect_lppe_T_tdd_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_05, T_tdd_05_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo_04, T_modeSpecificInfo_04_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_CellData, OMA_LPPe_ECID_UTRA_CellData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxUTRAMacroCells_OF_OMA_LPPe_ECID_UTRA_CellData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxUTRAMacroCells_OF_OMA_LPPe_ECID_UTRA_CellData, SEQUENCE_SIZE_1_maxUTRAMacroCells_OF_OMA_LPPe_ECID_UTRA_CellData_sequence_of,
1, maxUTRAMacroCells, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_NodeBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_NodeBData, OMA_LPPe_ECID_UTRA_NodeBData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxUTRAnodeBs_OF_OMA_LPPe_ECID_UTRA_NodeBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxUTRAnodeBs_OF_OMA_LPPe_ECID_UTRA_NodeBData, SEQUENCE_SIZE_1_maxUTRAnodeBs_OF_OMA_LPPe_ECID_UTRA_NodeBData_sequence_of,
1, maxUTRAnodeBs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_HNBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_HNBData, OMA_LPPe_ECID_UTRA_HNBData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxUTRAHNBs_OF_OMA_LPPe_ECID_UTRA_HNBData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxUTRAHNBs_OF_OMA_LPPe_ECID_UTRA_HNBData, SEQUENCE_SIZE_1_maxUTRAHNBs_OF_OMA_LPPe_ECID_UTRA_HNBData_sequence_of,
1, maxUTRAHNBs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_NetworkData, OMA_LPPe_ECID_UTRA_NetworkData_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxUTRANetworks_OF_OMA_LPPe_ECID_UTRA_NetworkData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxUTRANetworks_OF_OMA_LPPe_ECID_UTRA_NetworkData, SEQUENCE_SIZE_1_maxUTRANetworks_OF_OMA_LPPe_ECID_UTRA_NetworkData_sequence_of,
1, maxUTRANetworks, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_LocationServerErrorCauses, OMA_LPPe_ECID_UTRA_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_TargetDeviceErrorCauses, OMA_LPPe_ECID_UTRA_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_Error, OMA_LPPe_ECID_UTRA_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_ProvideAssistanceData, OMA_LPPe_ECID_UTRA_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_T_mcc_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mcc_03, T_mcc_03_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_mnc_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_T_mnc_03, T_mnc_03_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lppe_T_plmn_Identity_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_plmn_Identity_03, T_plmn_Identity_03_sequence);
return offset;
}
static int
dissect_lppe_Supported_Channels_11a(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_Supported_Channels_11a, Supported_Channels_11a_sequence);
return offset;
}
static int
dissect_lppe_Supported_Channels_11bg(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_Supported_Channels_11bg, Supported_Channels_11bg_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Type_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_Type_Data, OMA_LPPe_WLAN_AP_Type_Data_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxWLANTypes_OF_OMA_LPPe_WLAN_AP_Type_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxWLANTypes_OF_OMA_LPPe_WLAN_AP_Type_Data, SEQUENCE_SIZE_1_maxWLANTypes_OF_OMA_LPPe_WLAN_AP_Type_Data_sequence_of,
1, maxWLANTypes, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_Data, OMA_LPPe_WLAN_AP_Data_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxWLANAPs_OF_OMA_LPPe_WLAN_AP_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxWLANAPs_OF_OMA_LPPe_WLAN_AP_Data, SEQUENCE_SIZE_1_maxWLANAPs_OF_OMA_LPPe_WLAN_AP_Data_sequence_of,
1, maxWLANAPs, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_DataSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_DataSet, OMA_LPPe_WLAN_DataSet_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxWLANDataSets_OF_OMA_LPPe_WLAN_DataSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxWLANDataSets_OF_OMA_LPPe_WLAN_DataSet, SEQUENCE_SIZE_1_maxWLANDataSets_OF_OMA_LPPe_WLAN_DataSet_sequence_of,
1, maxWLANDataSets, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_LocationServerErrorCauses, OMA_LPPe_WLAN_AP_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_TargetDeviceErrorCauses, OMA_LPPe_WLAN_AP_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_Error, OMA_LPPe_WLAN_AP_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_ProvideAssistanceData, OMA_LPPe_WLAN_AP_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_ProvideAssistanceData, OMA_LPPe_Sensor_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_M300_500(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-300, 500U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_srnAntennaInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_srnAntennaInfo, T_srnAntennaInfo_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNtype(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNtype, OMA_LPPe_SRN_SRNtype_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_180(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 180U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_eulerAngles(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_eulerAngles, T_eulerAngles_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Orientation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Orientation, OMA_LPPe_Orientation_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNinfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNinfo, OMA_LPPe_SRN_SRNinfo_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNinfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNinfo, SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNinfo_sequence_of,
1, 1024, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroup, OMA_LPPe_SRN_SRNgroup_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_SRNgroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_SRNgroup, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_SRNgroup_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupList, OMA_LPPe_SRN_SRNgroupList_sequence);
return offset;
}
static int
dissect_lppe_T_targetDataValidity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponseElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponseElement, OMA_LPPe_SRN_SRNgroupUpdateResponseElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponse, OMA_LPPe_SRN_SRNgroupUpdateResponse_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_T_srnGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_srnGroup, T_srnGroup_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_identification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_identification, T_identification_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_200(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 200U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_1_150(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 150U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_evenGrid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_evenGrid, T_evenGrid_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_1_maxChannels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, maxChannels, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_900(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 900U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_3599(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3599U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_M1800_1799(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1800, 1799U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ComplexNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ComplexNumber, OMA_LPPe_ComplexNumber_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ResponseInAzimuth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ResponseInAzimuth, OMA_LPPe_SRN_ResponseInAzimuth_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_18_3601_OF_OMA_LPPe_SRN_ResponseInAzimuth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_18_3601_OF_OMA_LPPe_SRN_ResponseInAzimuth, SEQUENCE_SIZE_18_3601_OF_OMA_LPPe_SRN_ResponseInAzimuth_sequence_of,
18, 3601, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ResponseInElevation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ResponseInElevation, OMA_LPPe_SRN_ResponseInElevation_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_7_901_OF_OMA_LPPe_SRN_ResponseInElevation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_7_901_OF_OMA_LPPe_SRN_ResponseInElevation, SEQUENCE_SIZE_7_901_OF_OMA_LPPe_SRN_ResponseInElevation_sequence_of,
7, 901, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ChannelResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ChannelResponse, OMA_LPPe_SRN_ChannelResponse_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxChannels_OF_OMA_LPPe_SRN_ChannelResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxChannels_OF_OMA_LPPe_SRN_ChannelResponse, SEQUENCE_SIZE_1_maxChannels_OF_OMA_LPPe_SRN_ChannelResponse_sequence_of,
1, maxChannels, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_AntennaPatternForChannels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_AntennaPatternForChannels, OMA_LPPe_SRN_AntennaPatternForChannels_sequence);
return offset;
}
static int
dissect_lppe_T_antennaData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_antennaData, T_antennaData_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_AntennaPatternElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_AntennaPatternElement, OMA_LPPe_SRN_AntennaPatternElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_AntennaPattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_AntennaPattern, OMA_LPPe_SRN_AntennaPattern_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_T_groupErrors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_groupUpdateErrors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_srnAntennaErrors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_LocationServerErrorCauses, OMA_LPPe_SRN_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_srnErrors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_TargetDeviceError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_TargetDeviceError, OMA_LPPe_SRN_TargetDeviceError_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_TargetDeviceError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_TargetDeviceError, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_TargetDeviceError_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_TargetDeviceErrorCauses, OMA_LPPe_SRN_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_Error, OMA_LPPe_SRN_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ProvideAssistanceData, OMA_LPPe_SRN_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ProvideAssistanceData, OMA_LPPe_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_IP_Address_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_IP_Address_Request, OMA_LPPe_IP_Address_Request_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerRequestItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerRequestItem, OMA_LPPe_LocationInformationContainerRequestItem_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerRequestList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerRequestList, OMA_LPPe_LocationInformationContainerRequestList_sequence_of,
1, maxLocationInformationContainerDataList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerRequest, OMA_LPPe_LocationInformationContainerRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_TypeOfLocInfoRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RequestPeriodicLocInfoWithUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RequestPeriodicLocInfoWithUpdate, OMA_LPPe_RequestPeriodicLocInfoWithUpdate_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocationChange_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocationChange_Request, OMA_LPPe_RelativeLocationChange_Request_sequence);
return offset;
}
static int
dissect_lppe_T_typeOfRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointUniqueID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointUniqueID, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointUniqueID_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocalPositionRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocalPositionRequest, OMA_LPPe_LocalPositionRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ScheduledLocation_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ScheduledLocation_Request, OMA_LPPe_ScheduledLocation_Request_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AccessTypeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AccessTypeRequest, OMA_LPPe_AccessTypeRequest_sequence);
return offset;
}
static int
dissect_lppe_T_segmentedLIpreference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedLIResume(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedLIResume, OMA_LPPe_SegmentedLIResume_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsRequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsRequestLocationInformation, OMA_LPPe_CommonIEsRequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_antennaInformationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssSignalReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssSignalReqElement, OMA_LPPe_AGNSS_HAgnssSignalReqElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssSignalReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssSignalReqElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssSignalReqElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssRequestControlParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssRequestControlParameters, OMA_LPPe_AGNSS_HAgnssRequestControlParameters_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_PositioningInstructions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_PositioningInstructions, OMA_LPPe_AGNSS_PositioningInstructions_sequence);
return offset;
}
static int
dissect_lppe_T_ionosphereMeasurementsReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurementReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurementReq, OMA_LPPe_AGNSS_LocalSurfaceMeasurementReq_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_RequestLocationInformation, OMA_LPPe_AGNSS_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_RequestLocationInformation, OMA_LPPe_OTDOA_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_RequestLocationInformation, OMA_LPPe_EOTD_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestLocationInformation, OMA_LPPe_OTDOA_UTRA_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_requestedMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_RequestLocationInformation, OMA_LPPe_ECID_LTE_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_requestedMeasurements_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_RequestLocationInformation, OMA_LPPe_ECID_GSM_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_requestedMeasurements_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_RequestLocationInformation, OMA_LPPe_ECID_UTRA_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_requestedMeasurements_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_RequestLocationInformation, OMA_LPPe_WLAN_AP_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_requestedMeasurements_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_RequestLocationInformation, OMA_LPPe_ECID_WiMax_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_MotionStateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_MotionStateRequest, OMA_LPPe_Sensor_MotionStateRequest_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_RequestLocationInformation, OMA_LPPe_Sensor_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_multipleMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ReqLocInfo_Category(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ReqLocInfo_Category, OMA_LPPe_SRN_ReqLocInfo_Category_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ReqLocInfo_Category(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ReqLocInfo_Category, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ReqLocInfo_Category_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_RequestLocationInformation, OMA_LPPe_SRN_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RequestLocationInformation, OMA_LPPe_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocalPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocalPosition, OMA_LPPe_LocalPosition_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HighAccuracy3Dvelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HighAccuracy3Dvelocity, OMA_LPPe_HighAccuracy3Dvelocity_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL);
return offset;
}
static int
dissect_lppe_T_local_IP_Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_local_IP_Address, T_local_IP_Address_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_IP_Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_IP_Address, OMA_LPPe_IP_Address_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_IP_Address_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_IP_Address_List, OMA_LPPe_IP_Address_List_sequence_of,
1, maxIPAddress, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerData, OMA_LPPe_LocationInformationContainerData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainerDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainerDataList, OMA_LPPe_LocationInformationContainerDataList_sequence_of,
1, maxLocationInformationContainerDataList, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_LocationInformationContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_LocationInformationContainer, OMA_LPPe_LocationInformationContainer_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_TypeOfLocInfoProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ProvidePeriodicLocInfowithUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ProvidePeriodicLocInfowithUpdate, OMA_LPPe_ProvidePeriodicLocInfowithUpdate_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocationChange(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocationChange, OMA_LPPe_RelativeLocationChange_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_RelativeLocationChangeList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_RelativeLocationChangeList, OMA_LPPe_RelativeLocationChangeList_sequence_of,
1, maxRelativeLocation, FALSE);
return offset;
}
static int
dissect_lppe_T_disposition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_M512_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-512, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_actualWindow(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_actualWindow, T_actualWindow_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ScheduledLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ScheduledLocation, OMA_LPPe_ScheduledLocation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AccessTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AccessTypes, OMA_LPPe_AccessTypes_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SegmentedLITransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SegmentedLITransfer, OMA_LPPe_SegmentedLITransfer_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_1024(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_TimeStamp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_TimeStamp, OMA_LPPe_TimeStamp_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsProvideLocationInformation, OMA_LPPe_CommonIEsProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_controlParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_controlParameters, T_controlParameters_sequence);
return offset;
}
static int
dissect_lppe_T_localPressure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_localPressure, T_localPressure_sequence);
return offset;
}
static int
dissect_lppe_T_multipathDetection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_536870911(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 536870911U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HAgnssPerSVelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HAgnssPerSVelement, OMA_LPPe_HAgnssPerSVelement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_HAgnssPerSVelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_HAgnssPerSVelement, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_HAgnssPerSVelement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_HAgnssPerSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_HAgnssPerSignalElement, OMA_LPPe_HAgnssPerSignalElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_HAgnssPerSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_HAgnssPerSignalElement, SEQUENCE_SIZE_1_8_OF_OMA_LPPe_HAgnssPerSignalElement_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssMeasurementElement, OMA_LPPe_AGNSS_HAgnssMeasurementElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssMeasurementElement, SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssMeasurementElement_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lppe_T_measurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_measurements, T_measurements_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_HAgnssProvide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_HAgnssProvide, OMA_LPPe_AGNSS_HAgnssProvide_choice,
NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_90(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 90U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TECPerSVElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TECPerSVElement, OMA_LPPe_AGNSS_TECPerSVElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TECPerSV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TECPerSV, OMA_LPPe_AGNSS_TECPerSV_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_TECAtZenith(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_TECAtZenith, OMA_LPPe_AGNSS_TECAtZenith_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_IonosphereMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_IonosphereMeasurements, OMA_LPPe_AGNSS_IonosphereMeasurements_sequence);
return offset;
}
static int
dissect_lppe_T_temperatureMeasurement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_temperatureMeasurement, T_temperatureMeasurement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurements, OMA_LPPe_AGNSS_LocalSurfaceMeasurements_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_ProvideLocationInformation, OMA_LPPe_AGNSS_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_LocationInformation, OMA_LPPe_OTDOA_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_ProvideLocationInformation, OMA_LPPe_OTDOA_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_INTEGER_0_42431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 42431U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ModuloTimeSlot(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
5, 5, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_TOA_MeasurementsOfRef(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_TOA_MeasurementsOfRef, OMA_LPPe_EOTD_TOA_MeasurementsOfRef_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_960(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 960U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_CellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_BCCHCarrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MultiFrameCarrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_MultiFrameCarrier, OMA_LPPe_EOTD_MultiFrameCarrier_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_RequestIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_SystemInfoIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_NeighborIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_NeighborIdentity, OMA_LPPe_EOTD_NeighborIdentity_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_EOTDQuality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_EOTDQuality, OMA_LPPe_EOTD_EOTDQuality_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_OTDValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 39999U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MeasurementWithID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_MeasurementWithID, OMA_LPPe_EOTD_MeasurementWithID_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_15_OF_OMA_LPPe_EOTD_MeasurementWithID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_15_OF_OMA_LPPe_EOTD_MeasurementWithID, SEQUENCE_SIZE_1_15_OF_OMA_LPPe_EOTD_MeasurementWithID_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_MsrElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_MsrElement, OMA_LPPe_EOTD_MsrElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_EOTD_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_EOTD_ProvideLocationInformation, OMA_LPPe_EOTD_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_TimeDifferenceType2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_Quality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_Quality, OMA_LPPe_OTDOA_UTRA_Quality_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_NeighborQuality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborQuality, OMA_LPPe_OTDOA_UTRA_NeighborQuality_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info, OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info_sequence);
return offset;
}
static int
dissect_lppe_T_fdd_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_03, T_fdd_03_sequence);
return offset;
}
static int
dissect_lppe_T_tdd_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_03, T_tdd_03_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfoMeas(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfoMeas, T_modeSpecificInfoMeas_choice,
NULL);
return offset;
}
static int
dissect_lppe_T_fdd_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_04, T_fdd_04_sequence);
return offset;
}
static int
dissect_lppe_T_tdd_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_04, T_tdd_04_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo_03, T_modeSpecificInfo_03_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_ObsTimeDifference2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_Neighbor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_Neighbor, OMA_LPPe_OTDOA_UTRA_Neighbor_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_NeighborList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborList, OMA_LPPe_OTDOA_UTRA_NeighborList_sequence_of,
1, utra_maxCellMeas, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_Measurement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_Measurement, OMA_LPPe_OTDOA_UTRA_Measurement_sequence);
return offset;
}
static int
dissect_lppe_T_nonUniqueCellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_nonUniqueCellID, T_nonUniqueCellID_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_TimeStampData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_TimeStampData, OMA_LPPe_OTDOA_UTRA_TimeStampData_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_OTDOA_UTRA_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideLocationInformation, OMA_LPPe_OTDOA_UTRA_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_LocationInformation, OMA_LPPe_ECID_LTE_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_LocationInformationList, OMA_LPPe_ECID_LTE_LocationInformationList_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxLTEECIDSize_OF_OMA_LPPe_ECID_LTE_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxLTEECIDSize_OF_OMA_LPPe_ECID_LTE_LocationInformationList, SEQUENCE_SIZE_1_maxLTEECIDSize_OF_OMA_LPPe_ECID_LTE_LocationInformationList_sequence_of,
1, maxLTEECIDSize, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_LTE_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_LTE_ProvideLocationInformation, OMA_LPPe_ECID_LTE_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_NMR_GERAN_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_NMR_GERAN_item, OMA_LPPe_NMR_GERAN_item_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_NMR_GERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_NMR_GERAN, OMA_LPPe_NMR_GERAN_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_LocationInformation, OMA_LPPe_ECID_GSM_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_LocationInformationList, OMA_LPPe_ECID_GSM_LocationInformationList_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxGSMECIDSize_OF_OMA_LPPe_ECID_GSM_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxGSMECIDSize_OF_OMA_LPPe_ECID_GSM_LocationInformationList, SEQUENCE_SIZE_1_maxGSMECIDSize_OF_OMA_LPPe_ECID_GSM_LocationInformationList_sequence_of,
1, maxGSMECIDSize, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_GSM_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_GSM_ProvideLocationInformation, OMA_LPPe_ECID_GSM_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CarrierRSSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CPICH_Ec_N0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CPICH_RSCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_Pathloss(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
46U, 173U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_fdd_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_fdd_06, T_fdd_06_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_PrimaryCCPCH_RSCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_T_tdd_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_tdd_06, T_tdd_06_sequence);
return offset;
}
static int
dissect_lppe_T_modeSpecificInfo_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_T_modeSpecificInfo_05, T_modeSpecificInfo_05_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResults(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResults, OMA_LPPe_ECID_UTRA_CellMeasuredResults_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResultsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResultsList, OMA_LPPe_ECID_UTRA_CellMeasuredResultsList_sequence_of,
1, utra_maxCellMeas, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_MeasuredResults(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_MeasuredResults, OMA_LPPe_ECID_UTRA_MeasuredResults_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_MeasuredResultsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_MeasuredResultsList, OMA_LPPe_ECID_UTRA_MeasuredResultsList_sequence_of,
1, maxFreq, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_TAResolution(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_ChipRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_UTRATimingAdvance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_UTRATimingAdvance, OMA_LPPe_ECID_UTRA_UTRATimingAdvance_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_LocationInformation, OMA_LPPe_ECID_UTRA_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_LocationInformationList, OMA_LPPe_ECID_UTRA_LocationInformationList_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxECIDUTRASize_OF_OMA_LPPe_ECID_UTRA_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxECIDUTRASize_OF_OMA_LPPe_ECID_UTRA_LocationInformationList, SEQUENCE_SIZE_1_maxECIDUTRASize_OF_OMA_LPPe_ECID_UTRA_LocationInformationList_sequence_of,
1, maxECIDUTRASize, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_UTRA_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_UTRA_ProvideLocationInformation, OMA_LPPe_ECID_UTRA_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OCTET_STRING_SIZE_1_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 32, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_PHY_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_INTEGER_0_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_INTEGER_0_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_RTDUnits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_RTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_RTD, OMA_LPPe_WLAN_RTD_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_34(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
34, 34, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_30(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
30, 30, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_LocationDataLCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_LocationDataLCI, OMA_LPPe_WLAN_LocationDataLCI_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_ReportedLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_ReportedLocation, OMA_LPPe_WLAN_ReportedLocation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_LocationInformation, OMA_LPPe_WLAN_AP_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_LocationInformationList, OMA_LPPe_WLAN_AP_LocationInformationList_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxWLANAPSize_OF_OMA_LPPe_WLAN_AP_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxWLANAPSize_OF_OMA_LPPe_WLAN_AP_LocationInformationList, SEQUENCE_SIZE_1_maxWLANAPSize_OF_OMA_LPPe_WLAN_AP_LocationInformationList_sequence_of,
1, maxWLANAPSize, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_WLAN_AP_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_WLAN_AP_ProvideLocationInformation, OMA_LPPe_WLAN_AP_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_BIT_STRING_SIZE_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_WimaxBsID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_WimaxBsID, OMA_LPPe_ECID_WiMax_WimaxBsID_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_WimaxRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_WimaxRTD, OMA_LPPe_ECID_WiMax_WimaxRTD_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_WimaxNMR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_WimaxNMR, OMA_LPPe_ECID_WiMax_WimaxNMR_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_WimaxNMRList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_WimaxNMRList, OMA_LPPe_ECID_WiMax_WimaxNMRList_sequence_of,
1, maxWimaxBSMeas, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_LocationInformation, OMA_LPPe_ECID_WiMax_LocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_LocationInformationList, OMA_LPPe_ECID_WiMax_LocationInformationList_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_maxWiMaxECIDSize_OF_OMA_LPPe_ECID_WiMax_LocationInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_maxWiMaxECIDSize_OF_OMA_LPPe_ECID_WiMax_LocationInformationList, SEQUENCE_SIZE_1_maxWiMaxECIDSize_OF_OMA_LPPe_ECID_WiMax_LocationInformationList_sequence_of,
1, maxWiMaxECIDSize, FALSE);
return offset;
}
static int
dissect_lppe_T_cause_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_LocationServerErrorCauses, OMA_LPPe_ECID_WiMax_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_T_cause_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_TargetDeviceErrorCauses, OMA_LPPe_ECID_WiMax_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_Error, OMA_LPPe_ECID_WiMax_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ECID_WiMax_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ECID_WiMax_ProvideLocationInformation, OMA_LPPe_ECID_WiMax_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_T_primaryMotionState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_secondaryMotionState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_MotionStateElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_MotionStateElement, OMA_LPPe_Sensor_MotionStateElement_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_MotionStateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_MotionStateList, OMA_LPPe_Sensor_MotionStateList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lppe_T_motionStateError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_secondaryMotionStateError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_TargetError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_TargetError, OMA_LPPe_Sensor_TargetError_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_Error, OMA_LPPe_Sensor_Error_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Sensor_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Sensor_ProvideLocationInformation, OMA_LPPe_Sensor_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_srnMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_srnMeasurementElement, OMA_LPPe_SRN_srnMeasurementElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_srnMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_srnMeasurementElement, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_srnMeasurementElement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_MeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_MeasurementElement, OMA_LPPe_SRN_MeasurementElement_sequence);
return offset;
}
static int
dissect_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_MeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_MeasurementElement, SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_MeasurementElement_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lppe_OMA_LPPe_SRN_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_SRN_ProvideLocationInformation, OMA_LPPe_SRN_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_ProvideLocationInformation, OMA_LPPe_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsError, OMA_LPPe_CommonIEsError_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Error, OMA_LPPe_Error_sequence);
return offset;
}
static int
dissect_lppe_T_abortCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_CommonIEsAbort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_CommonIEsAbort, OMA_LPPe_CommonIEsAbort_sequence);
return offset;
}
static int
dissect_lppe_T_ccpAbort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_waIonoAbort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppe_T_targetDeviceAbortCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_T_targetDeviceAbortCauses, T_targetDeviceAbortCauses_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_AGNSS_Abort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_AGNSS_Abort, OMA_LPPe_AGNSS_Abort_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_Abort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_Abort, OMA_LPPe_Abort_sequence);
return offset;
}
static int
dissect_lppe_OMA_LPPe_MessageExtensionBody(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_MessageExtensionBody, OMA_LPPe_MessageExtensionBody_choice,
NULL);
return offset;
}
static int
dissect_lppe_OMA_LPPe_MessageExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 18 "../../asn1/lppe/lppe.cnf"
proto_tree_add_item(tree, proto_lppe, tvb, 0, -1, ENC_NA);
col_append_sep_str(actx->pinfo->cinfo, COL_PROTOCOL, "/", "LPPe");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppe_OMA_LPPe_MessageExtension, OMA_LPPe_MessageExtension_sequence);
return offset;
}
static int dissect_OMA_LPPe_MessageExtension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lppe_OMA_LPPe_MessageExtension(tvb, offset, &asn1_ctx, tree, hf_lppe_OMA_LPPe_MessageExtension_PDU);
offset += 7; offset >>= 3;
return offset;
}
void proto_register_lppe(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/lppe/packet-lppe-hfarr.c"
{ &hf_lppe_OMA_LPPe_MessageExtension_PDU,
{ "OMA-LPPe-MessageExtension", "lppe.OMA_LPPe_MessageExtension",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_lppeCompatibilityLevel,
{ "lppeCompatibilityLevel", "lppe.lppeCompatibilityLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_LPPeCompatibilityLevel", HFILL }},
{ &hf_lppe_lppeVersion,
{ "lppeVersion", "lppe.lppeVersion",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LPPeVersion", HFILL }},
{ &hf_lppe_lppeMode,
{ "lppeMode", "lppe.lppeMode",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_LPPeMode_vals), 0,
"OMA_LPPe_LPPeMode", HFILL }},
{ &hf_lppe_messageExtensionBody,
{ "messageExtensionBody", "lppe.messageExtensionBody",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_MessageExtensionBody_vals), 0,
"OMA_LPPe_MessageExtensionBody", HFILL }},
{ &hf_lppe_majorVersion,
{ "majorVersion", "lppe.majorVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_minorVersion,
{ "minorVersion", "lppe.minorVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_requestCapabilities,
{ "requestCapabilities", "lppe.requestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RequestCapabilities", HFILL }},
{ &hf_lppe_provideCapabilities,
{ "provideCapabilities", "lppe.provideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ProvideCapabilities", HFILL }},
{ &hf_lppe_requestAssistanceData,
{ "requestAssistanceData", "lppe.requestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RequestAssistanceData", HFILL }},
{ &hf_lppe_provideAssistanceData,
{ "provideAssistanceData", "lppe.provideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ProvideAssistanceData", HFILL }},
{ &hf_lppe_requestLocationInformation,
{ "requestLocationInformation", "lppe.requestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RequestLocationInformation", HFILL }},
{ &hf_lppe_provideLocationInformation,
{ "provideLocationInformation", "lppe.provideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ProvideLocationInformation", HFILL }},
{ &hf_lppe_error,
{ "error", "lppe.error",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Error", HFILL }},
{ &hf_lppe_abort,
{ "abort", "lppe.abort",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Abort", HFILL }},
{ &hf_lppe_commonIEsRequestCapabilities,
{ "commonIEsRequestCapabilities", "lppe.commonIEsRequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsRequestCapabilities", HFILL }},
{ &hf_lppe_agnss_RequestCapabilities,
{ "agnss-RequestCapabilities", "lppe.agnss_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_RequestCapabilities", HFILL }},
{ &hf_lppe_otdoa_RequestCapabilities,
{ "otdoa-RequestCapabilities", "lppe.otdoa_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_RequestCapabilities", HFILL }},
{ &hf_lppe_eotd_RequestCapabilities,
{ "eotd-RequestCapabilities", "lppe.eotd_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_RequestCapabilities", HFILL }},
{ &hf_lppe_otdoa_utra_RequestCapabilities,
{ "otdoa-utra-RequestCapabilities", "lppe.otdoa_utra_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_RequestCapabilities", HFILL }},
{ &hf_lppe_ecid_lte_RequestCapabilities,
{ "ecid-lte-RequestCapabilities", "lppe.ecid_lte_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_RequestCapabilities", HFILL }},
{ &hf_lppe_ecid_gsm_RequestCapabilities,
{ "ecid-gsm-RequestCapabilities", "lppe.ecid_gsm_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_RequestCapabilities", HFILL }},
{ &hf_lppe_ecid_utra_RequestCapabilities,
{ "ecid-utra-RequestCapabilities", "lppe.ecid_utra_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_RequestCapabilities", HFILL }},
{ &hf_lppe_wlan_ap_RequestCapabilities,
{ "wlan-ap-RequestCapabilities", "lppe.wlan_ap_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_RequestCapabilities", HFILL }},
{ &hf_lppe_ecid_wimax_RequestCapabilities,
{ "ecid-wimax-RequestCapabilities", "lppe.ecid_wimax_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_RequestCapabilities", HFILL }},
{ &hf_lppe_sensor_RequestCapabilities,
{ "sensor-RequestCapabilities", "lppe.sensor_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_RequestCapabilities", HFILL }},
{ &hf_lppe_srn_RequestCapabilities,
{ "srn-RequestCapabilities", "lppe.srn_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_RequestCapabilities", HFILL }},
{ &hf_lppe_commonIEsProvideCapabilities,
{ "commonIEsProvideCapabilities", "lppe.commonIEsProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsProvideCapabilities", HFILL }},
{ &hf_lppe_agnss_ProvideCapabilities,
{ "agnss-ProvideCapabilities", "lppe.agnss_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_ProvideCapabilities", HFILL }},
{ &hf_lppe_otdoa_ProvideCapabilities,
{ "otdoa-ProvideCapabilities", "lppe.otdoa_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_ProvideCapabilities", HFILL }},
{ &hf_lppe_eotd_ProvideCapabilities,
{ "eotd-ProvideCapabilities", "lppe.eotd_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_ProvideCapabilities", HFILL }},
{ &hf_lppe_otdoa_utra_ProvideCapabilities,
{ "otdoa-utra-ProvideCapabilities", "lppe.otdoa_utra_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_ProvideCapabilities", HFILL }},
{ &hf_lppe_ecid_lte_ProvideCapabilities,
{ "ecid-lte-ProvideCapabilities", "lppe.ecid_lte_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_ProvideCapabilities", HFILL }},
{ &hf_lppe_ecid_gsm_ProvideCapabilities,
{ "ecid-gsm-ProvideCapabilities", "lppe.ecid_gsm_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_ProvideCapabilities", HFILL }},
{ &hf_lppe_ecid_utra_ProvideCapabilities,
{ "ecid-utra-ProvideCapabilities", "lppe.ecid_utra_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_ProvideCapabilities", HFILL }},
{ &hf_lppe_wlan_ap_ProvideCapabilities,
{ "wlan-ap-ProvideCapabilities", "lppe.wlan_ap_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_ProvideCapabilities", HFILL }},
{ &hf_lppe_ecid_wimax_ProvideCapabilities,
{ "ecid-wimax-ProvideCapabilities", "lppe.ecid_wimax_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_ProvideCapabilities", HFILL }},
{ &hf_lppe_sensor_ProvideCapabilities,
{ "sensor-ProvideCapabilities", "lppe.sensor_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_ProvideCapabilities", HFILL }},
{ &hf_lppe_srn_ProvideCapabilities,
{ "srn-ProvideCapabilities", "lppe.srn_ProvideCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_ProvideCapabilities", HFILL }},
{ &hf_lppe_commonIEsRequestAssistanceData,
{ "commonIEsRequestAssistanceData", "lppe.commonIEsRequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsRequestAssistanceData", HFILL }},
{ &hf_lppe_agnss_RequestAssistanceData,
{ "agnss-RequestAssistanceData", "lppe.agnss_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_RequestAssistanceData", HFILL }},
{ &hf_lppe_otdoa_RequestAssistanceData,
{ "otdoa-RequestAssistanceData", "lppe.otdoa_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_RequestAssistanceData", HFILL }},
{ &hf_lppe_eotd_RequestAssistanceData,
{ "eotd-RequestAssistanceData", "lppe.eotd_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_RequestAssistanceData", HFILL }},
{ &hf_lppe_otdoa_utra_RequestAssistanceData,
{ "otdoa-utra-RequestAssistanceData", "lppe.otdoa_utra_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_RequestAssistanceData", HFILL }},
{ &hf_lppe_ecid_lte_RequestAssistanceData,
{ "ecid-lte-RequestAssistanceData", "lppe.ecid_lte_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_RequestAssistanceData", HFILL }},
{ &hf_lppe_ecid_gsm_RequestAssistanceData,
{ "ecid-gsm-RequestAssistanceData", "lppe.ecid_gsm_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_RequestAssistanceData", HFILL }},
{ &hf_lppe_ecid_utra_RequestAssistanceData,
{ "ecid-utra-RequestAssistanceData", "lppe.ecid_utra_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_RequestAssistanceData", HFILL }},
{ &hf_lppe_wlan_ap_RequestAssistanceData,
{ "wlan-ap-RequestAssistanceData", "lppe.wlan_ap_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_RequestAssistanceData", HFILL }},
{ &hf_lppe_sensor_RequestAssistanceData,
{ "sensor-RequestAssistanceData", "lppe.sensor_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_RequestAssistanceData", HFILL }},
{ &hf_lppe_srn_RequestAssistanceData,
{ "srn-RequestAssistanceData", "lppe.srn_RequestAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_RequestAssistanceData", HFILL }},
{ &hf_lppe_commonIEsProvideAssistanceData,
{ "commonIEsProvideAssistanceData", "lppe.commonIEsProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsProvideAssistanceData", HFILL }},
{ &hf_lppe_agnss_ProvideAssistanceData,
{ "agnss-ProvideAssistanceData", "lppe.agnss_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_ProvideAssistanceData", HFILL }},
{ &hf_lppe_otdoa_ProvideAssistanceData,
{ "otdoa-ProvideAssistanceData", "lppe.otdoa_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_ProvideAssistanceData", HFILL }},
{ &hf_lppe_eotd_ProvideAssistanceData,
{ "eotd-ProvideAssistanceData", "lppe.eotd_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_ProvideAssistanceData", HFILL }},
{ &hf_lppe_otdoa_utra_ProvideAssistanceData,
{ "otdoa-utra-ProvideAssistanceData", "lppe.otdoa_utra_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_ProvideAssistanceData", HFILL }},
{ &hf_lppe_ecid_lte_ProvideAssistanceData,
{ "ecid-lte-ProvideAssistanceData", "lppe.ecid_lte_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_ProvideAssistanceData", HFILL }},
{ &hf_lppe_ecid_gsm_ProvideAssistanceData,
{ "ecid-gsm-ProvideAssistanceData", "lppe.ecid_gsm_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_ProvideAssistanceData", HFILL }},
{ &hf_lppe_ecid_utra_ProvideAssistanceData,
{ "ecid-utra-ProvideAssistanceData", "lppe.ecid_utra_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_ProvideAssistanceData", HFILL }},
{ &hf_lppe_wlan_ap_ProvideAssistanceData,
{ "wlan-ap-ProvideAssistanceData", "lppe.wlan_ap_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_ProvideAssistanceData", HFILL }},
{ &hf_lppe_sensor_ProvideAssistanceData,
{ "sensor-ProvideAssistanceData", "lppe.sensor_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_ProvideAssistanceData", HFILL }},
{ &hf_lppe_srn_ProvideAssistanceData,
{ "srn-ProvideAssistanceData", "lppe.srn_ProvideAssistanceData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_ProvideAssistanceData", HFILL }},
{ &hf_lppe_commonIEsRequestLocationInformation,
{ "commonIEsRequestLocationInformation", "lppe.commonIEsRequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsRequestLocationInformation", HFILL }},
{ &hf_lppe_agnss_RequestLocationInformation,
{ "agnss-RequestLocationInformation", "lppe.agnss_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_RequestLocationInformation", HFILL }},
{ &hf_lppe_otdoa_RequestLocationInformation,
{ "otdoa-RequestLocationInformation", "lppe.otdoa_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_RequestLocationInformation", HFILL }},
{ &hf_lppe_eotd_RequestLocationInformation,
{ "eotd-RequestLocationInformation", "lppe.eotd_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_RequestLocationInformation", HFILL }},
{ &hf_lppe_otdoa_utra_RequestLocationInformation,
{ "otdoa-utra-RequestLocationInformation", "lppe.otdoa_utra_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_RequestLocationInformation", HFILL }},
{ &hf_lppe_ecid_lte_RequestLocationInformation,
{ "ecid-lte-RequestLocationInformation", "lppe.ecid_lte_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_RequestLocationInformation", HFILL }},
{ &hf_lppe_ecid_gsm_RequestLocationInformation,
{ "ecid-gsm-RequestLocationInformation", "lppe.ecid_gsm_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_RequestLocationInformation", HFILL }},
{ &hf_lppe_ecid_utra_RequestLocationInformation,
{ "ecid-utra-RequestLocationInformation", "lppe.ecid_utra_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_RequestLocationInformation", HFILL }},
{ &hf_lppe_wlan_ap_RequestLocationInformation,
{ "wlan-ap-RequestLocationInformation", "lppe.wlan_ap_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_RequestLocationInformation", HFILL }},
{ &hf_lppe_ecid_wimax_RequestLocationInformation,
{ "ecid-wimax-RequestLocationInformation", "lppe.ecid_wimax_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_RequestLocationInformation", HFILL }},
{ &hf_lppe_sensor_RequestLocationInformation,
{ "sensor-RequestLocationInformation", "lppe.sensor_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_RequestLocationInformation", HFILL }},
{ &hf_lppe_srn_RequestLocationInformation,
{ "srn-RequestLocationInformation", "lppe.srn_RequestLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_RequestLocationInformation", HFILL }},
{ &hf_lppe_commonIEsProvideLocationInformation,
{ "commonIEsProvideLocationInformation", "lppe.commonIEsProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsProvideLocationInformation", HFILL }},
{ &hf_lppe_agnss_ProvideLocationInformation,
{ "agnss-ProvideLocationInformation", "lppe.agnss_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_ProvideLocationInformation", HFILL }},
{ &hf_lppe_otdoa_ProvideLocationInformation,
{ "otdoa-ProvideLocationInformation", "lppe.otdoa_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_ProvideLocationInformation", HFILL }},
{ &hf_lppe_eotd_ProvideLocationInformation,
{ "eotd-ProvideLocationInformation", "lppe.eotd_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_ProvideLocationInformation", HFILL }},
{ &hf_lppe_otdoa_utra_ProvideLocationInformation,
{ "otdoa-utra-ProvideLocationInformation", "lppe.otdoa_utra_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_ProvideLocationInformation", HFILL }},
{ &hf_lppe_ecid_lte_ProvideLocationInformation,
{ "ecid-lte-ProvideLocationInformation", "lppe.ecid_lte_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_ProvideLocationInformation", HFILL }},
{ &hf_lppe_ecid_gsm_ProvideLocationInformation,
{ "ecid-gsm-ProvideLocationInformation", "lppe.ecid_gsm_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_ProvideLocationInformation", HFILL }},
{ &hf_lppe_ecid_utra_ProvideLocationInformation,
{ "ecid-utra-ProvideLocationInformation", "lppe.ecid_utra_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_ProvideLocationInformation", HFILL }},
{ &hf_lppe_wlan_ap_ProvideLocationInformastion,
{ "wlan-ap-ProvideLocationInformastion", "lppe.wlan_ap_ProvideLocationInformastion",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_ProvideLocationInformation", HFILL }},
{ &hf_lppe_ecid_wimax_ProvideLocationInformastion,
{ "ecid-wimax-ProvideLocationInformastion", "lppe.ecid_wimax_ProvideLocationInformastion",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_ProvideLocationInformation", HFILL }},
{ &hf_lppe_sensor_ProvideLocationInformation,
{ "sensor-ProvideLocationInformation", "lppe.sensor_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_ProvideLocationInformation", HFILL }},
{ &hf_lppe_srn_ProvideLocationInformation,
{ "srn-ProvideLocationInformation", "lppe.srn_ProvideLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_ProvideLocationInformation", HFILL }},
{ &hf_lppe_commonIEsAbort,
{ "commonIEsAbort", "lppe.commonIEsAbort",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsAbort", HFILL }},
{ &hf_lppe_agnssAbort,
{ "agnssAbort", "lppe.agnssAbort",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_Abort", HFILL }},
{ &hf_lppe_commonIEsError,
{ "commonIEsError", "lppe.commonIEsError",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CommonIEsError", HFILL }},
{ &hf_lppe_dataSerialNumber,
{ "dataSerialNumber", "lppe.dataSerialNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lppe_containerID,
{ "containerID", "lppe.containerID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_OMA_LPPe_AssistanceContainerProvideList_item,
{ "OMA-LPPe-AssistanceContainerProvide", "lppe.OMA_LPPe_AssistanceContainerProvide",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_dataIdentifier,
{ "dataIdentifier", "lppe.dataIdentifier",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_VendorOrOperatorAssistanceDataIdentifier", HFILL }},
{ &hf_lppe_checkOrUpdateOrError,
{ "checkOrUpdateOrError", "lppe.checkOrUpdateOrError",
FT_UINT32, BASE_DEC, VALS(lppe_T_checkOrUpdateOrError_vals), 0,
NULL, HFILL }},
{ &hf_lppe_dataResult,
{ "dataResult", "lppe.dataResult",
FT_UINT32, BASE_DEC, VALS(lppe_T_dataResult_vals), 0,
NULL, HFILL }},
{ &hf_lppe_simulationResult,
{ "simulationResult", "lppe.simulationResult",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_5000", HFILL }},
{ &hf_lppe_data,
{ "data", "lppe.data",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerData", HFILL }},
{ &hf_lppe_errorCode,
{ "errorCode", "lppe.errorCode",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerProvideError", HFILL }},
{ &hf_lppe_dataSerialNumber_01,
{ "dataSerialNumber", "lppe.dataSerialNumber",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainer_DataSerialNumber", HFILL }},
{ &hf_lppe_data_01,
{ "data", "lppe.data",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_validityPeriod,
{ "validityPeriod", "lppe.validityPeriod",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ValidityPeriod", HFILL }},
{ &hf_lppe_validityArea,
{ "validityArea", "lppe.validityArea",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ValidityArea", HFILL }},
{ &hf_lppe_serverError,
{ "serverError", "lppe.serverError",
FT_UINT32, BASE_DEC, VALS(lppe_T_serverError_vals), 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_AssistanceContainerRequestList_item,
{ "OMA-LPPe-AssistanceContainerRequest", "lppe.OMA_LPPe_AssistanceContainerRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_simulatedReq,
{ "simulatedReq", "lppe.simulatedReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_checkOrUpdateReq,
{ "checkOrUpdateReq", "lppe.checkOrUpdateReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerCheckOrUpdateReq", HFILL }},
{ &hf_lppe_validityTimeRequest,
{ "validityTimeRequest", "lppe.validityTimeRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ValidityPeriod", HFILL }},
{ &hf_lppe_proprietaryRequestParameters,
{ "proprietaryRequestParameters", "lppe.proprietaryRequestParameters",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_checkLatest,
{ "checkLatest", "lppe.checkLatest",
FT_UINT32, BASE_DEC, VALS(lppe_T_checkLatest_vals), 0,
NULL, HFILL }},
{ &hf_lppe_locationAreaCode,
{ "locationAreaCode", "lppe.locationAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lppe_cellIdentity,
{ "cellIdentity", "lppe.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lppe_bsic,
{ "bsic", "lppe.bsic",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_bcch,
{ "bcch", "lppe.bcch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lppe_countryCode,
{ "countryCode", "lppe.countryCode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_lppe_civicAddressElementList,
{ "civicAddressElementList", "lppe.civicAddressElementList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_CivicAddressElementList", HFILL }},
{ &hf_lppe_OMA_LPPe_CivicAddressElementList_item,
{ "OMA-LPPe-CivicAddressElement", "lppe.OMA_LPPe_CivicAddressElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_caType,
{ "caType", "lppe.caType",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_caValue,
{ "caValue", "lppe.caValue",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_256", HFILL }},
{ &hf_lppe_duration,
{ "duration", "lppe.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_63", HFILL }},
{ &hf_lppe_durationLSB,
{ "durationLSB", "lppe.durationLSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_89", HFILL }},
{ &hf_lppe_latitude,
{ "latitude", "lppe.latitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lppe_longitude,
{ "longitude", "lppe.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lppe_cep,
{ "cep", "lppe.cep",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_uncertainty_semimajor,
{ "uncertainty-semimajor", "lppe.uncertainty_semimajor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_uncertainty_semiminor,
{ "uncertainty-semiminor", "lppe.uncertainty_semiminor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_offset_angle,
{ "offset-angle", "lppe.offset_angle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_lppe_confidenceHorizontal,
{ "confidenceHorizontal", "lppe.confidenceHorizontal",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_lppe_altitude,
{ "altitude", "lppe.altitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64000_1280000", HFILL }},
{ &hf_lppe_uncertainty_altitude,
{ "uncertainty-altitude", "lppe.uncertainty_altitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_confidenceVertical,
{ "confidenceVertical", "lppe.confidenceVertical",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_lppe_enu_origin,
{ "enu-origin", "lppe.enu_origin",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dposition", HFILL }},
{ &hf_lppe_east_component,
{ "east-component", "lppe.east_component",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_negative_sign_east,
{ "negative-sign-east", "lppe.negative_sign_east",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_north_component,
{ "north-component", "lppe.north_component",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_negative_sign_north,
{ "negative-sign-north", "lppe.negative_sign_north",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_up_component,
{ "up-component", "lppe.up_component",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_negative_sign_up,
{ "negative-sign-up", "lppe.negative_sign_up",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_uncertainty_up_component,
{ "uncertainty-up-component", "lppe.uncertainty_up_component",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_confidenceUp,
{ "confidenceUp", "lppe.confidenceUp",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_lppe_vendorOrOperatorID,
{ "vendorOrOperatorID", "lppe.vendorOrOperatorID",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_locationInformationContainerDataList,
{ "locationInformationContainerDataList", "lppe.locationInformationContainerDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_LocationInformationContainerDataList", HFILL }},
{ &hf_lppe_OMA_LPPe_LocationInformationContainerDataList_item,
{ "OMA-LPPe-LocationInformationContainerData", "lppe.OMA_LPPe_LocationInformationContainerData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_containerID_01,
{ "containerID", "lppe.containerID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocationInformationContainerID", HFILL }},
{ &hf_lppe_containerData,
{ "containerData", "lppe.containerData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_locationInformationContainerRequestList,
{ "locationInformationContainerRequestList", "lppe.locationInformationContainerRequestList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_LocationInformationContainerRequestList", HFILL }},
{ &hf_lppe_OMA_LPPe_LocationInformationContainerRequestList_item,
{ "OMA-LPPe-LocationInformationContainerRequestItem", "lppe.OMA_LPPe_LocationInformationContainerRequestItem",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_additionalInformation,
{ "additionalInformation", "lppe.additionalInformation",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_dataID,
{ "dataID", "lppe.dataID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerID", HFILL }},
{ &hf_lppe_mapReference,
{ "mapReference", "lppe.mapReference",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_64", HFILL }},
{ &hf_lppe_mapSize,
{ "mapSize", "lppe.mapSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_5000", HFILL }},
{ &hf_lppe_eulerAngles,
{ "eulerAngles", "lppe.eulerAngles",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_alpha,
{ "alpha", "lppe.alpha",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lppe_beta,
{ "beta", "lppe.beta",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_180", HFILL }},
{ &hf_lppe_gamma,
{ "gamma", "lppe.gamma",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lppe_referencePointUniqueID,
{ "referencePointUniqueID", "lppe.referencePointUniqueID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePointUniqueID", HFILL }},
{ &hf_lppe_referencePointGeographicLocation,
{ "referencePointGeographicLocation", "lppe.referencePointGeographicLocation",
FT_UINT32, BASE_DEC, VALS(lppe_T_referencePointGeographicLocation_vals), 0,
NULL, HFILL }},
{ &hf_lppe_location3D,
{ "location3D", "lppe.location3D",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitude", HFILL }},
{ &hf_lppe_location3DwithUncertainty,
{ "location3DwithUncertainty", "lppe.location3DwithUncertainty",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_lppe_locationwithhighaccuracy,
{ "locationwithhighaccuracy", "lppe.locationwithhighaccuracy",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dposition", HFILL }},
{ &hf_lppe_referencePointCivicLocation,
{ "referencePointCivicLocation", "lppe.referencePointCivicLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CivicLocation", HFILL }},
{ &hf_lppe_referencePointFloorLevel,
{ "referencePointFloorLevel", "lppe.referencePointFloorLevel",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20_235", HFILL }},
{ &hf_lppe_relatedReferencePoints,
{ "relatedReferencePoints", "lppe.relatedReferencePoints",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointRelationship", HFILL }},
{ &hf_lppe_relatedReferencePoints_item,
{ "OMA-LPPe-ReferencePointRelationship", "lppe.OMA_LPPe_ReferencePointRelationship",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mapDataInformation,
{ "mapDataInformation", "lppe.mapDataInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_MapDataInformation", HFILL }},
{ &hf_lppe_OMA_LPPe_MapDataInformation_item,
{ "OMA-LPPe-MapDataReferenceElement", "lppe.OMA_LPPe_MapDataReferenceElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mapDataUrl,
{ "mapDataUrl", "lppe.mapDataUrl",
FT_UINT32, BASE_DEC, VALS(lppe_T_mapDataUrl_vals), 0,
NULL, HFILL }},
{ &hf_lppe_mapDataUrl_01,
{ "mapDataUrl", "lppe.mapDataUrl",
FT_STRING, BASE_NONE, NULL, 0,
"OMA_LPPe_Uri", HFILL }},
{ &hf_lppe_mapDataRef,
{ "mapDataRef", "lppe.mapDataRef",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_MapDataReference", HFILL }},
{ &hf_lppe_mapProvider,
{ "mapProvider", "lppe.mapProvider",
FT_UINT32, BASE_DEC, VALS(lppe_T_mapProvider_vals), 0,
NULL, HFILL }},
{ &hf_lppe_sameAsRefPointProvider,
{ "sameAsRefPointProvider", "lppe.sameAsRefPointProvider",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_notSameAsRefPointProvider,
{ "notSameAsRefPointProvider", "lppe.notSameAsRefPointProvider",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_mapAssociation,
{ "mapAssociation", "lppe.mapAssociation",
FT_UINT32, BASE_DEC, VALS(lppe_T_mapAssociation_vals), 0,
NULL, HFILL }},
{ &hf_lppe_referencePointUniqueID_01,
{ "referencePointUniqueID", "lppe.referencePointUniqueID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_otherID,
{ "otherID", "lppe.otherID",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString_SIZE_1_64", HFILL }},
{ &hf_lppe_mapOffset,
{ "mapOffset", "lppe.mapOffset",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_origin,
{ "origin", "lppe.origin",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mapHorizontalOrientation,
{ "mapHorizontalOrientation", "lppe.mapHorizontalOrientation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lppe_relativeLocation,
{ "relativeLocation", "lppe.relativeLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_providerID,
{ "providerID", "lppe.providerID",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_providerAssignedID,
{ "providerAssignedID", "lppe.providerAssignedID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_version,
{ "version", "lppe.version",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_64", HFILL }},
{ &hf_lppe_units,
{ "units", "lppe.units",
FT_UINT32, BASE_DEC, VALS(lppe_T_units_vals), 0,
NULL, HFILL }},
{ &hf_lppe_arc_second_units,
{ "arc-second-units", "lppe.arc_second_units",
FT_UINT32, BASE_DEC, VALS(lppe_T_arc_second_units_vals), 0,
NULL, HFILL }},
{ &hf_lppe_relativeNorth,
{ "relativeNorth", "lppe.relativeNorth",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M524288_524287", HFILL }},
{ &hf_lppe_relativeEast,
{ "relativeEast", "lppe.relativeEast",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M524288_524287", HFILL }},
{ &hf_lppe_relativeAltitude,
{ "relativeAltitude", "lppe.relativeAltitude",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeAltitude", HFILL }},
{ &hf_lppe_horizontalUncertainty,
{ "horizontalUncertainty", "lppe.horizontalUncertainty",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HorizontalUncertaintyAndConfidence", HFILL }},
{ &hf_lppe_uncShape,
{ "uncShape", "lppe.uncShape",
FT_UINT32, BASE_DEC, VALS(lppe_T_uncShape_vals), 0,
NULL, HFILL }},
{ &hf_lppe_circle,
{ "circle", "lppe.circle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_ellipse,
{ "ellipse", "lppe.ellipse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_semimajor,
{ "semimajor", "lppe.semimajor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_semiminor,
{ "semiminor", "lppe.semiminor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_offsetAngle,
{ "offsetAngle", "lppe.offsetAngle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_lppe_confidence,
{ "confidence", "lppe.confidence",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_lppe_geodeticRelativeAltitude,
{ "geodeticRelativeAltitude", "lppe.geodeticRelativeAltitude",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_GeodeticRelativeAltitude", HFILL }},
{ &hf_lppe_civicRelativeAltitude,
{ "civicRelativeAltitude", "lppe.civicRelativeAltitude",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CivicRelativeAltitude", HFILL }},
{ &hf_lppe_geodetic_height_depth,
{ "geodetic-height-depth", "lppe.geodetic_height_depth",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lppe_geodetic_uncertainty_and_confidence,
{ "geodetic-uncertainty-and-confidence", "lppe.geodetic_uncertainty_and_confidence",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_GeodeticUncertaintyAndConfidence", HFILL }},
{ &hf_lppe_uncertainty,
{ "uncertainty", "lppe.uncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_civic_floors,
{ "civic-floors", "lppe.civic_floors",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M255_256", HFILL }},
{ &hf_lppe_civic_uncertainty_and_confidence,
{ "civic-uncertainty-and-confidence", "lppe.civic_uncertainty_and_confidence",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CivicUncertaintyAndConfidence", HFILL }},
{ &hf_lppe_provider_ID,
{ "provider-ID", "lppe.provider_ID",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_server_ID,
{ "server-ID", "lppe.server_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_lppe_session_ID,
{ "session-ID", "lppe.session_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_lppe_regionSizeInv,
{ "regionSizeInv", "lppe.regionSizeInv",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_lppe_areaWidth,
{ "areaWidth", "lppe.areaWidth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_9180", HFILL }},
{ &hf_lppe_codedLatOfNWCorner,
{ "codedLatOfNWCorner", "lppe.codedLatOfNWCorner",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4589", HFILL }},
{ &hf_lppe_codedLonOfNWCorner,
{ "codedLonOfNWCorner", "lppe.codedLonOfNWCorner",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9179", HFILL }},
{ &hf_lppe_rleList,
{ "rleList", "lppe.rleList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_RleList", HFILL }},
{ &hf_lppe_OMA_LPPe_RleList_item,
{ "OMA-LPPe-RleList item", "lppe.OMA_LPPe_RleList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_beginTime,
{ "beginTime", "lppe.beginTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_beginTimeAlt,
{ "beginTimeAlt", "lppe.beginTimeAlt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2881", HFILL }},
{ &hf_lppe_duration_01,
{ "duration", "lppe.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_2881", HFILL }},
{ &hf_lppe_assistanceDataID,
{ "assistanceDataID", "lppe.assistanceDataID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerID", HFILL }},
{ &hf_lppe_standard_VendorOrOperatorID,
{ "standard-VendorOrOperatorID", "lppe.standard_VendorOrOperatorID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_lppe_nonStandard_VendorOrOperatorID,
{ "nonStandard-VendorOrOperatorID", "lppe.nonStandard_VendorOrOperatorID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_NonStandard_VendorOrOperatorID", HFILL }},
{ &hf_lppe_encodedID,
{ "encodedID", "lppe.encodedID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_visibleIdentification,
{ "visibleIdentification", "lppe.visibleIdentification",
FT_STRING, BASE_NONE, NULL, 0,
"OMA_LPPe_CharArray", HFILL }},
{ &hf_lppe_apMacAddress,
{ "apMacAddress", "lppe.apMacAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_lppe_truncation,
{ "truncation", "lppe.truncation",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_areaType,
{ "areaType", "lppe.areaType",
FT_UINT32, BASE_DEC, VALS(lppe_T_areaType_vals), 0,
NULL, HFILL }},
{ &hf_lppe_componentList,
{ "componentList", "lppe.componentList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_WLANFemtoCoverageAreaElement", HFILL }},
{ &hf_lppe_componentList_item,
{ "OMA-LPPe-WLANFemtoCoverageAreaElement", "lppe.OMA_LPPe_WLANFemtoCoverageAreaElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_refPointAndArea,
{ "refPointAndArea", "lppe.refPointAndArea",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_referenceLocation,
{ "referenceLocation", "lppe.referenceLocation",
FT_UINT32, BASE_DEC, VALS(lppe_T_referenceLocation_vals), 0,
NULL, HFILL }},
{ &hf_lppe_referencePoint,
{ "referencePoint", "lppe.referencePoint",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePointUniqueID", HFILL }},
{ &hf_lppe_locationAndArea,
{ "locationAndArea", "lppe.locationAndArea",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_type,
{ "type", "lppe.type",
FT_UINT32, BASE_DEC, VALS(lppe_T_type_vals), 0,
NULL, HFILL }},
{ &hf_lppe_weight,
{ "weight", "lppe.weight",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_lppe_iP_Address_RequestCapabilities,
{ "iP-Address-RequestCapabilities", "lppe.iP_Address_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_IP_Address_RequestCapabilities", HFILL }},
{ &hf_lppe_assistanceContainerSupportReq,
{ "assistanceContainerSupportReq", "lppe.assistanceContainerSupportReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AssistanceContainerSupportReq", HFILL }},
{ &hf_lppe_locationInformationContainerSupportReq,
{ "locationInformationContainerSupportReq", "lppe.locationInformationContainerSupportReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocationInformationContainerSupportReq", HFILL }},
{ &hf_lppe_relativeLocationChange_RequestCapabilities,
{ "relativeLocationChange-RequestCapabilities", "lppe.relativeLocationChange_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocationChange_RequestCapabilities", HFILL }},
{ &hf_lppe_highAccuracyFormatCapabilitiesReq,
{ "highAccuracyFormatCapabilitiesReq", "lppe.highAccuracyFormatCapabilitiesReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracyFormatCapabilitiesReq", HFILL }},
{ &hf_lppe_segmentedAssistanceData_ReqCapabilities,
{ "segmentedAssistanceData-ReqCapabilities", "lppe.segmentedAssistanceData_ReqCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedAssistanceData_ReqCapabilities", HFILL }},
{ &hf_lppe_referencePointCapabilitiesReq,
{ "referencePointCapabilitiesReq", "lppe.referencePointCapabilitiesReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePointCapabilitiesReq", HFILL }},
{ &hf_lppe_scheduledLocation_RequestCapabilities,
{ "scheduledLocation-RequestCapabilities", "lppe.scheduledLocation_RequestCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ScheduledLocation_RequestCapabilities", HFILL }},
{ &hf_lppe_accessCapabilitiesReq,
{ "accessCapabilitiesReq", "lppe.accessCapabilitiesReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AccessCapabilitiesReq", HFILL }},
{ &hf_lppe_segmentedLocationInformation_ReqCapabilities,
{ "segmentedLocationInformation-ReqCapabilities", "lppe.segmentedLocationInformation_ReqCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedLocationInformation_ReqCapabilities", HFILL }},
{ &hf_lppe_vendorOrOperatorIDList,
{ "vendorOrOperatorIDList", "lppe.vendorOrOperatorIDList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_VendorOrOperatorIDList", HFILL }},
{ &hf_lppe_OMA_LPPe_VendorOrOperatorIDList_item,
{ "OMA-LPPe-VendorOrOperatorID", "lppe.OMA_LPPe_VendorOrOperatorID",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
NULL, HFILL }},
{ &hf_lppe_referencePointProviderSupportListReq,
{ "referencePointProviderSupportListReq", "lppe.referencePointProviderSupportListReq",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_128_OF_OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_referencePointProviderSupportListReq_item,
{ "OMA-LPPe-VendorOrOperatorID", "lppe.OMA_LPPe_VendorOrOperatorID",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
NULL, HFILL }},
{ &hf_lppe_iP_Address_Capabilities,
{ "iP-Address-Capabilities", "lppe.iP_Address_Capabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_IP_Address_Capabilities", HFILL }},
{ &hf_lppe_assistanceContainerSupport,
{ "assistanceContainerSupport", "lppe.assistanceContainerSupport",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AssistanceContainerSupport", HFILL }},
{ &hf_lppe_locationInformationContainerSupport,
{ "locationInformationContainerSupport", "lppe.locationInformationContainerSupport",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_LocationInformationContainerSupport", HFILL }},
{ &hf_lppe_relativeLocationChange_Capabilities,
{ "relativeLocationChange-Capabilities", "lppe.relativeLocationChange_Capabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocationChange_Capabilities", HFILL }},
{ &hf_lppe_highAccuracyFormatCapabilities,
{ "highAccuracyFormatCapabilities", "lppe.highAccuracyFormatCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracyFormatCapabilities", HFILL }},
{ &hf_lppe_segmentedAssistanceData_ProvideCapabs,
{ "segmentedAssistanceData-ProvideCapabs", "lppe.segmentedAssistanceData_ProvideCapabs",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedAssistanceData_ProvideCapabs", HFILL }},
{ &hf_lppe_referencePointCapabilities,
{ "referencePointCapabilities", "lppe.referencePointCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePointCapabilities", HFILL }},
{ &hf_lppe_scheduledLocation_Capabilities,
{ "scheduledLocation-Capabilities", "lppe.scheduledLocation_Capabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ScheduledLocation_Capabilities", HFILL }},
{ &hf_lppe_accessCapabilities,
{ "accessCapabilities", "lppe.accessCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AccessCapabilities", HFILL }},
{ &hf_lppe_segmentedLocationInformation_ProvideCapabs,
{ "segmentedLocationInformation-ProvideCapabs", "lppe.segmentedLocationInformation_ProvideCapabs",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedLocationInformation_ProvideCapabs", HFILL }},
{ &hf_lppe_iP_Address_support,
{ "iP-Address-support", "lppe.iP_Address_support",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_AssistanceContainerSupport_item,
{ "OMA-LPPe-VendorOrOperatorAssistanceContainerList", "lppe.OMA_LPPe_VendorOrOperatorAssistanceContainerList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_assistanceContainerList,
{ "assistanceContainerList", "lppe.assistanceContainerList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AssistanceContainerList", HFILL }},
{ &hf_lppe_OMA_LPPe_AssistanceContainerList_item,
{ "OMA-LPPe-AssistanceContainerID", "lppe.OMA_LPPe_AssistanceContainerID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_LocationInformationContainerSupport_item,
{ "OMA-LPPe-VendorOrOperatorLocationInformationContainerList", "lppe.OMA_LPPe_VendorOrOperatorLocationInformationContainerList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationInformationContainerList,
{ "locationInformationContainerList", "lppe.locationInformationContainerList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_LocationInformationContainerList", HFILL }},
{ &hf_lppe_OMA_LPPe_LocationInformationContainerList_item,
{ "OMA-LPPe-LocationInformationContainerID", "lppe.OMA_LPPe_LocationInformationContainerID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_numberOfChanges,
{ "numberOfChanges", "lppe.numberOfChanges",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_5", HFILL }},
{ &hf_lppe_maxSegments,
{ "maxSegments", "lppe.maxSegments",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_4096", HFILL }},
{ &hf_lppe_maxSize,
{ "maxSize", "lppe.maxSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_5000", HFILL }},
{ &hf_lppe_minSize,
{ "minSize", "lppe.minSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_5000", HFILL }},
{ &hf_lppe_resume,
{ "resume", "lppe.resume",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relativeLocationReportingSupport,
{ "relativeLocationReportingSupport", "lppe.relativeLocationReportingSupport",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_referencePointProviderSupportList,
{ "referencePointProviderSupportList", "lppe.referencePointProviderSupportList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_128_OF_OMA_LPPe_ReferencePointProviderSupportElement", HFILL }},
{ &hf_lppe_referencePointProviderSupportList_item,
{ "OMA-LPPe-ReferencePointProviderSupportElement", "lppe.OMA_LPPe_ReferencePointProviderSupportElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_referencePointProvider,
{ "referencePointProvider", "lppe.referencePointProvider",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_mapDataSupport,
{ "mapDataSupport", "lppe.mapDataSupport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mapDataFormat,
{ "mapDataFormat", "lppe.mapDataFormat",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_minimumWindow,
{ "minimumWindow", "lppe.minimumWindow",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_lppe_gnssTimeReference,
{ "gnssTimeReference", "lppe.gnssTimeReference",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID_Bitmap", HFILL }},
{ &hf_lppe_networkTimeReference,
{ "networkTimeReference", "lppe.networkTimeReference",
FT_UINT32, BASE_DEC, VALS(lppe_T_networkTimeReference_vals), 0,
NULL, HFILL }},
{ &hf_lppe_accessTypeUnknown,
{ "accessTypeUnknown", "lppe.accessTypeUnknown",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_fixedAccessTypes,
{ "fixedAccessTypes", "lppe.fixedAccessTypes",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_FixedAccessTypes", HFILL }},
{ &hf_lppe_wirelessAccessTypes,
{ "wirelessAccessTypes", "lppe.wirelessAccessTypes",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_WirelessAccessTypes", HFILL }},
{ &hf_lppe_approximate_location,
{ "approximate-location", "lppe.approximate_location",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_lppe_assistanceContainerRequestList,
{ "assistanceContainerRequestList", "lppe.assistanceContainerRequestList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AssistanceContainerRequestList", HFILL }},
{ &hf_lppe_requestPeriodicADwithUpdate,
{ "requestPeriodicADwithUpdate", "lppe.requestPeriodicADwithUpdate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RequestPeriodicADwithUpdate", HFILL }},
{ &hf_lppe_segmentedADpreference,
{ "segmentedADpreference", "lppe.segmentedADpreference",
FT_UINT32, BASE_DEC, VALS(lppe_T_segmentedADpreference_vals), 0,
NULL, HFILL }},
{ &hf_lppe_segmentedADResume,
{ "segmentedADResume", "lppe.segmentedADResume",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedADResume", HFILL }},
{ &hf_lppe_referencePointAssistanceReq,
{ "referencePointAssistanceReq", "lppe.referencePointAssistanceReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePointAssistanceReq", HFILL }},
{ &hf_lppe_periodicAD_session_ID,
{ "periodicAD-session-ID", "lppe.periodicAD_session_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_lppe_typeOfADRequest,
{ "typeOfADRequest", "lppe.typeOfADRequest",
FT_UINT32, BASE_DEC, VALS(lppe_TypeOfADRequest_vals), 0,
NULL, HFILL }},
{ &hf_lppe_segmentedAD_session_ID,
{ "segmentedAD-session-ID", "lppe.segmentedAD_session_ID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Session_ID", HFILL }},
{ &hf_lppe_next_segment_number,
{ "next-segment-number", "lppe.next_segment_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4096", HFILL }},
{ &hf_lppe_referencePointReq,
{ "referencePointReq", "lppe.referencePointReq",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_ReferencePointAssistanceReqElement", HFILL }},
{ &hf_lppe_referencePointReq_item,
{ "OMA-LPPe-ReferencePointAssistanceReqElement", "lppe.OMA_LPPe_ReferencePointAssistanceReqElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mapDataReq,
{ "mapDataReq", "lppe.mapDataReq",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_assistanceContainerList_01,
{ "assistanceContainerList", "lppe.assistanceContainerList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AssistanceContainerProvideList", HFILL }},
{ &hf_lppe_providePeriodicADwithUpdate,
{ "providePeriodicADwithUpdate", "lppe.providePeriodicADwithUpdate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ProvidePeriodicADwithUpdate", HFILL }},
{ &hf_lppe_segmentedADTransfer,
{ "segmentedADTransfer", "lppe.segmentedADTransfer",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedADTransfer", HFILL }},
{ &hf_lppe_default_reference_point,
{ "default-reference-point", "lppe.default_reference_point",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePoint", HFILL }},
{ &hf_lppe_typeOfADProvide,
{ "typeOfADProvide", "lppe.typeOfADProvide",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_TypeOfADProvide_vals), 0,
"OMA_LPPe_TypeOfADProvide", HFILL }},
{ &hf_lppe_segment_number,
{ "segment-number", "lppe.segment_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4096", HFILL }},
{ &hf_lppe_iP_Address_Request,
{ "iP-Address-Request", "lppe.iP_Address_Request",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_IP_Address_Request", HFILL }},
{ &hf_lppe_locationInformationContainerRequest,
{ "locationInformationContainerRequest", "lppe.locationInformationContainerRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocationInformationContainerRequest", HFILL }},
{ &hf_lppe_requestPeriodicLocInfoWithUpdate,
{ "requestPeriodicLocInfoWithUpdate", "lppe.requestPeriodicLocInfoWithUpdate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RequestPeriodicLocInfoWithUpdate", HFILL }},
{ &hf_lppe_relativeLocationChange_Request,
{ "relativeLocationChange-Request", "lppe.relativeLocationChange_Request",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocationChange_Request", HFILL }},
{ &hf_lppe_localPositionRequest,
{ "localPositionRequest", "lppe.localPositionRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocalPositionRequest", HFILL }},
{ &hf_lppe_scheduledLocation_Request,
{ "scheduledLocation-Request", "lppe.scheduledLocation_Request",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ScheduledLocation_Request", HFILL }},
{ &hf_lppe_accessTypeRequest,
{ "accessTypeRequest", "lppe.accessTypeRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AccessTypeRequest", HFILL }},
{ &hf_lppe_segmentedLIpreference,
{ "segmentedLIpreference", "lppe.segmentedLIpreference",
FT_UINT32, BASE_DEC, VALS(lppe_T_segmentedLIpreference_vals), 0,
NULL, HFILL }},
{ &hf_lppe_segmentedLIResume,
{ "segmentedLIResume", "lppe.segmentedLIResume",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedLIResume", HFILL }},
{ &hf_lppe_session_ID_01,
{ "session-ID", "lppe.session_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_lppe_typeOfLocInfoRequest,
{ "typeOfLocInfoRequest", "lppe.typeOfLocInfoRequest",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_TypeOfLocInfoRequest_vals), 0,
"OMA_LPPe_TypeOfLocInfoRequest", HFILL }},
{ &hf_lppe_typeOfRequest,
{ "typeOfRequest", "lppe.typeOfRequest",
FT_UINT32, BASE_DEC, VALS(lppe_T_typeOfRequest_vals), 0,
NULL, HFILL }},
{ &hf_lppe_referencePointReq_01,
{ "referencePointReq", "lppe.referencePointReq",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointUniqueID", HFILL }},
{ &hf_lppe_referencePointReq_item_01,
{ "OMA-LPPe-ReferencePointUniqueID", "lppe.OMA_LPPe_ReferencePointUniqueID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gnssTime,
{ "gnssTime", "lppe.gnssTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_networkTime,
{ "networkTime", "lppe.networkTime",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relativeTime,
{ "relativeTime", "lppe.relativeTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_lppe_windowSize,
{ "windowSize", "lppe.windowSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_lppe_segmentedLI_session_ID,
{ "segmentedLI-session-ID", "lppe.segmentedLI_session_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_lppe_highAccuracy3Dposition,
{ "highAccuracy3Dposition", "lppe.highAccuracy3Dposition",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dposition", HFILL }},
{ &hf_lppe_localPosition,
{ "localPosition", "lppe.localPosition",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocalPosition", HFILL }},
{ &hf_lppe_highAccuracy3Dvelocity,
{ "highAccuracy3Dvelocity", "lppe.highAccuracy3Dvelocity",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dvelocity", HFILL }},
{ &hf_lppe_iP_Address_List,
{ "iP-Address-List", "lppe.iP_Address_List",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_IP_Address_List", HFILL }},
{ &hf_lppe_locationInformationContainer,
{ "locationInformationContainer", "lppe.locationInformationContainer",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_LocationInformationContainer", HFILL }},
{ &hf_lppe_providePeriodicLocInfoWithUpdate,
{ "providePeriodicLocInfoWithUpdate", "lppe.providePeriodicLocInfoWithUpdate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ProvidePeriodicLocInfowithUpdate", HFILL }},
{ &hf_lppe_relativeLocationChangeList,
{ "relativeLocationChangeList", "lppe.relativeLocationChangeList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_RelativeLocationChangeList", HFILL }},
{ &hf_lppe_scheduledLocation,
{ "scheduledLocation", "lppe.scheduledLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ScheduledLocation", HFILL }},
{ &hf_lppe_accessTypes,
{ "accessTypes", "lppe.accessTypes",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AccessTypes", HFILL }},
{ &hf_lppe_segmentedLITransfer,
{ "segmentedLITransfer", "lppe.segmentedLITransfer",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SegmentedLITransfer", HFILL }},
{ &hf_lppe_locationInformationTimeStamp,
{ "locationInformationTimeStamp", "lppe.locationInformationTimeStamp",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_TimeStamp_vals), 0,
"OMA_LPPe_TimeStamp", HFILL }},
{ &hf_lppe_subjectLocation,
{ "subjectLocation", "lppe.subjectLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_OMA_LPPe_IP_Address_List_item,
{ "OMA-LPPe-IP-Address", "lppe.OMA_LPPe_IP_Address",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_local_IP_Address,
{ "local-IP-Address", "lppe.local_IP_Address",
FT_UINT32, BASE_DEC, VALS(lppe_T_local_IP_Address_vals), 0,
NULL, HFILL }},
{ &hf_lppe_iPv4,
{ "iPv4", "lppe.iPv4",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_lppe_iPv6,
{ "iPv6", "lppe.iPv6",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_lppe_bearer,
{ "bearer", "lppe.bearer",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_Bearer_vals), 0,
"OMA_LPPe_Bearer", HFILL }},
{ &hf_lppe_nat,
{ "nat", "lppe.nat",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_typeOfLocInfoProvide,
{ "typeOfLocInfoProvide", "lppe.typeOfLocInfoProvide",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_TypeOfLocInfoProvide_vals), 0,
"OMA_LPPe_TypeOfLocInfoProvide", HFILL }},
{ &hf_lppe_OMA_LPPe_RelativeLocationChangeList_item,
{ "OMA-LPPe-RelativeLocationChange", "lppe.OMA_LPPe_RelativeLocationChange",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relativeTime_01,
{ "relativeTime", "lppe.relativeTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_transactionID,
{ "transactionID", "lppe.transactionID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_disposition,
{ "disposition", "lppe.disposition",
FT_UINT32, BASE_DEC, VALS(lppe_T_disposition_vals), 0,
NULL, HFILL }},
{ &hf_lppe_actualWindow,
{ "actualWindow", "lppe.actualWindow",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_start,
{ "start", "lppe.start",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lppe_duration_02,
{ "duration", "lppe.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lppe_relativeTime_02,
{ "relativeTime", "lppe.relativeTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1024", HFILL }},
{ &hf_lppe_abortCause,
{ "abortCause", "lppe.abortCause",
FT_UINT32, BASE_DEC, VALS(lppe_T_abortCause_vals), 0,
NULL, HFILL }},
{ &hf_lppe_periodicSessionIDtoAbort,
{ "periodicSessionIDtoAbort", "lppe.periodicSessionIDtoAbort",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_lppe_commonAssistData,
{ "commonAssistData", "lppe.commonAssistData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CommonAssistData", HFILL }},
{ &hf_lppe_genericAssistData,
{ "genericAssistData", "lppe.genericAssistData",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_GenericAssistData", HFILL }},
{ &hf_lppe_error_01,
{ "error", "lppe.error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_Error_vals), 0,
"OMA_LPPe_AGNSS_Error", HFILL }},
{ &hf_lppe_ionosphericModel,
{ "ionosphericModel", "lppe.ionosphericModel",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_IonosphericModel_vals), 0,
"OMA_LPPe_AGNSS_IonosphericModel", HFILL }},
{ &hf_lppe_troposphereModel,
{ "troposphereModel", "lppe.troposphereModel",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_TroposphereModel", HFILL }},
{ &hf_lppe_altitudeAssistance,
{ "altitudeAssistance", "lppe.altitudeAssistance",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_AltitudeAssistanceList", HFILL }},
{ &hf_lppe_solarRadiation,
{ "solarRadiation", "lppe.solarRadiation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_SolarRadiation", HFILL }},
{ &hf_lppe_ccpAssistCommonProvide,
{ "ccpAssistCommonProvide", "lppe.ccpAssistCommonProvide",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_CCPassistCommonProvide_vals), 0,
"OMA_LPPe_AGNSS_CCPassistCommonProvide", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_GenericAssistData_item,
{ "OMA-LPPe-AGNSS-GenericAssistDataElement", "lppe.OMA_LPPe_AGNSS_GenericAssistDataElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gnss_ID,
{ "gnss-ID", "lppe.gnss_ID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wideAreaIonoSurfacePerSVlist,
{ "wideAreaIonoSurfacePerSVlist", "lppe.wideAreaIonoSurfacePerSVlist",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist", HFILL }},
{ &hf_lppe_mechanicsForAllSVs,
{ "mechanicsForAllSVs", "lppe.mechanicsForAllSVs",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_MechanicsForAllSVs", HFILL }},
{ &hf_lppe_dcbsForAllSVs,
{ "dcbsForAllSVs", "lppe.dcbsForAllSVs",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_DCBsForAllSVs", HFILL }},
{ &hf_lppe_navModelDegradationModel,
{ "navModelDegradationModel", "lppe.navModelDegradationModel",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_NavModelDegradationModelList", HFILL }},
{ &hf_lppe_ccpAssistProvide,
{ "ccpAssistProvide", "lppe.ccpAssistProvide",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_CCPassistGenericProvide", HFILL }},
{ &hf_lppe_navModelList,
{ "navModelList", "lppe.navModelList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModelList", HFILL }},
{ &hf_lppe_staticModels,
{ "staticModels", "lppe.staticModels",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_localKlobucharModelList,
{ "localKlobucharModelList", "lppe.localKlobucharModelList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_LocalKlobucharModelList", HFILL }},
{ &hf_lppe_ionoStormIndication,
{ "ionoStormIndication", "lppe.ionoStormIndication",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_IonoStormIndication", HFILL }},
{ &hf_lppe_waIono,
{ "waIono", "lppe.waIono",
FT_UINT32, BASE_DEC, VALS(lppe_T_waIono_vals), 0,
NULL, HFILL }},
{ &hf_lppe_controlParameters,
{ "controlParameters", "lppe.controlParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersProvide", HFILL }},
{ &hf_lppe_commonProvide,
{ "commonProvide", "lppe.commonProvide",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_WideAreaIonoSurfaceCommon", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelList_item,
{ "OMA-LPPe-AGNSS-LocalKlobucharModelElement", "lppe.OMA_LPPe_AGNSS_LocalKlobucharModelElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_klobucharModel,
{ "klobucharModel", "lppe.klobucharModel",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalKlobucharModel", HFILL }},
{ &hf_lppe_klobucharModel_item,
{ "OMA-LPPe-AGNSS-LocalKlobucharModel", "lppe.OMA_LPPe_AGNSS_LocalKlobucharModel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_alfa0,
{ "alfa0", "lppe.alfa0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_alfa1,
{ "alfa1", "lppe.alfa1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_alfa2,
{ "alfa2", "lppe.alfa2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_alfa3,
{ "alfa3", "lppe.alfa3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_beta0,
{ "beta0", "lppe.beta0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_beta1,
{ "beta1", "lppe.beta1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_beta2,
{ "beta2", "lppe.beta2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_beta3,
{ "beta3", "lppe.beta3",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_area,
{ "area", "lppe.area",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ValidityArea", HFILL }},
{ &hf_lppe_stormList,
{ "stormList", "lppe.stormList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_StormList", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_StormList_item,
{ "OMA-LPPe-AGNSS-StormElement", "lppe.OMA_LPPe_AGNSS_StormElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rleListIono,
{ "rleListIono", "lppe.rleListIono",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_RleListIono", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_RleListIono_item,
{ "OMA-LPPe-AGNSS-RleIonoElement", "lppe.OMA_LPPe_AGNSS_RleIonoElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_regionCount,
{ "regionCount", "lppe.regionCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_ionoIndex,
{ "ionoIndex", "lppe.ionoIndex",
FT_UINT32, BASE_DEC, VALS(lppe_T_ionoIndex_vals), 0,
NULL, HFILL }},
{ &hf_lppe_noaaScales,
{ "noaaScales", "lppe.noaaScales",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_NoaaScales_vals), 0,
"OMA_LPPe_AGNSS_NoaaScales", HFILL }},
{ &hf_lppe_duration_03,
{ "duration", "lppe.duration",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Duration", HFILL }},
{ &hf_lppe_rate,
{ "rate", "lppe.rate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_64", HFILL }},
{ &hf_lppe_referencePosition,
{ "referencePosition", "lppe.referencePosition",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_Point", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist_item,
{ "OMA-LPPe-AGNSS-WideAreaIonoSurfacePerSVelement", "lppe.OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVelement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_svID,
{ "svID", "lppe.svID",
FT_NONE, BASE_NONE, NULL, 0,
"SV_ID", HFILL }},
{ &hf_lppe_a0,
{ "a0", "lppe.a0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_lppe_e1,
{ "e1", "lppe.e1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_n1,
{ "n1", "lppe.n1",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_e2,
{ "e2", "lppe.e2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_n2,
{ "n2", "lppe.n2",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_en,
{ "en", "lppe.en",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_troposphereDelayList,
{ "troposphereDelayList", "lppe.troposphereDelayList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_LocalTroposphereDelayList", HFILL }},
{ &hf_lppe_surfaceParametersList,
{ "surfaceParametersList", "lppe.surfaceParametersList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_LocalSurfaceParametersList", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayList_item,
{ "OMA-LPPe-AGNSS-LocalTroposphereDelayAreaElement", "lppe.OMA_LPPe_AGNSS_LocalTroposphereDelayAreaElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_refAltitude,
{ "refAltitude", "lppe.refAltitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1000_8192", HFILL }},
{ &hf_lppe_gradientReferencePosition,
{ "gradientReferencePosition", "lppe.gradientReferencePosition",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_Point", HFILL }},
{ &hf_lppe_delayList,
{ "delayList", "lppe.delayList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement", HFILL }},
{ &hf_lppe_delayList_item,
{ "OMA-LPPe-AGNSS-LocalTroposphereDelayTimeElement", "lppe.OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_zh0,
{ "zh0", "lppe.zh0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_eh,
{ "eh", "lppe.eh",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_zw0,
{ "zw0", "lppe.zw0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_ew,
{ "ew", "lppe.ew",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_gN,
{ "gN", "lppe.gN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lppe_gE,
{ "gE", "lppe.gE",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lppe_mappingFunctionParameters,
{ "mappingFunctionParameters", "lppe.mappingFunctionParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_MappingFunctionParameters", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersList_item,
{ "OMA-LPPe-AGNSS-LocalSurfaceParametersAreaElement", "lppe.OMA_LPPe_AGNSS_LocalSurfaceParametersAreaElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_parameterList,
{ "parameterList", "lppe.parameterList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement", HFILL }},
{ &hf_lppe_parameterList_item,
{ "OMA-LPPe-AGNSS-LocalSurfaceParametersTimeElement", "lppe.OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_pressure,
{ "pressure", "lppe.pressure",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lppe_pressureRate,
{ "pressureRate", "lppe.pressureRate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_gN_pressure,
{ "gN-pressure", "lppe.gN_pressure",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_gE_pressure,
{ "gE-pressure", "lppe.gE_pressure",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_temperature,
{ "temperature", "lppe.temperature",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lppe_temperatureRate,
{ "temperatureRate", "lppe.temperatureRate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_16", HFILL }},
{ &hf_lppe_gN_temperature,
{ "gN-temperature", "lppe.gN_temperature",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8_7", HFILL }},
{ &hf_lppe_gE_temperature,
{ "gE-temperature", "lppe.gE_temperature",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8_7", HFILL }},
{ &hf_lppe_ah,
{ "ah", "lppe.ah",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_bh,
{ "bh", "lppe.bh",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_ch,
{ "ch", "lppe.ch",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_aw,
{ "aw", "lppe.aw",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_bw,
{ "bw", "lppe.bw",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_cw,
{ "cw", "lppe.cw",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceList_item,
{ "OMA-LPPe-AGNSS-AltitudeAssistanceAreaElement", "lppe.OMA_LPPe_AGNSS_AltitudeAssistanceAreaElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gradientReferencePosition_01,
{ "gradientReferencePosition", "lppe.gradientReferencePosition",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_lppe_pressureAssistanceList,
{ "pressureAssistanceList", "lppe.pressureAssistanceList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_PressureAssistanceElement", HFILL }},
{ &hf_lppe_pressureAssistanceList_item,
{ "OMA-LPPe-AGNSS-PressureAssistanceElement", "lppe.OMA_LPPe_AGNSS_PressureAssistanceElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gN_01,
{ "gN", "lppe.gN",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_gE_01,
{ "gE", "lppe.gE",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_solarRadiation_01,
{ "solarRadiation", "lppe.solarRadiation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1000_2000", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_MechanicsForAllSVs_item,
{ "OMA-LPPe-AGNSS-MechanicsElement", "lppe.OMA_LPPe_AGNSS_MechanicsElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_svid,
{ "svid", "lppe.svid",
FT_NONE, BASE_NONE, NULL, 0,
"SV_ID", HFILL }},
{ &hf_lppe_mass,
{ "mass", "lppe.mass",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4095", HFILL }},
{ &hf_lppe_effectiveReflectivityArea,
{ "effectiveReflectivityArea", "lppe.effectiveReflectivityArea",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_511", HFILL }},
{ &hf_lppe_pco,
{ "pco", "lppe.pco",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_PCOelement", HFILL }},
{ &hf_lppe_svInfo,
{ "svInfo", "lppe.svInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_svType,
{ "svType", "lppe.svType",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_SVtype_vals), 0,
"OMA_LPPe_AGNSS_SVtype", HFILL }},
{ &hf_lppe_svNumber,
{ "svNumber", "lppe.svNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_xOffsetSBF,
{ "xOffsetSBF", "lppe.xOffsetSBF",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M30000_30000", HFILL }},
{ &hf_lppe_yOffsetSBF,
{ "yOffsetSBF", "lppe.yOffsetSBF",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M30000_30000", HFILL }},
{ &hf_lppe_zOffsetSBF,
{ "zOffsetSBF", "lppe.zOffsetSBF",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M30000_30000", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_DCBsForAllSVs_item,
{ "OMA-LPPe-AGNSS-DCBlistElement", "lppe.OMA_LPPe_AGNSS_DCBlistElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_reference,
{ "reference", "lppe.reference",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_signal,
{ "signal", "lppe.signal",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalID", HFILL }},
{ &hf_lppe_pd,
{ "pd", "lppe.pd",
FT_UINT32, BASE_DEC, VALS(lppe_T_pd_vals), 0,
NULL, HFILL }},
{ &hf_lppe_dcbList,
{ "dcbList", "lppe.dcbList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_DCBlist", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_DCBlist_item,
{ "OMA-LPPe-AGNSS-DCBelement", "lppe.OMA_LPPe_AGNSS_DCBelement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_pd_01,
{ "pd", "lppe.pd",
FT_UINT32, BASE_DEC, VALS(lppe_T_pd_01_vals), 0,
"T_pd_01", HFILL }},
{ &hf_lppe_dcb,
{ "dcb", "lppe.dcb",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelList_item,
{ "OMA-LPPe-AGNSS-NavModelDegradationModelElement", "lppe.OMA_LPPe_AGNSS_NavModelDegradationModelElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_clockDegradationModel,
{ "clockDegradationModel", "lppe.clockDegradationModel",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_ClockModelDegradationModel", HFILL }},
{ &hf_lppe_orbitDegradationModel,
{ "orbitDegradationModel", "lppe.orbitDegradationModel",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_OrbitModelDegradationModel", HFILL }},
{ &hf_lppe_clockRMS0,
{ "clockRMS0", "lppe.clockRMS0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lppe_clockRMS1,
{ "clockRMS1", "lppe.clockRMS1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lppe_orbitRMS0,
{ "orbitRMS0", "lppe.orbitRMS0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lppe_orbitRMS1,
{ "orbitRMS1", "lppe.orbitRMS1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lppe_ccpProvideCommonParameters,
{ "ccpProvideCommonParameters", "lppe.ccpProvideCommonParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPprovideCommonParameters", HFILL }},
{ &hf_lppe_ccpProvideControlParameters,
{ "ccpProvideControlParameters", "lppe.ccpProvideControlParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPprovideControlParameters", HFILL }},
{ &hf_lppe_ccpReferenceTime,
{ "ccpReferenceTime", "lppe.ccpReferenceTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_ccpSupportArea,
{ "ccpSupportArea", "lppe.ccpSupportArea",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPsupportArea", HFILL }},
{ &hf_lppe_ccpNeighborList,
{ "ccpNeighborList", "lppe.ccpNeighborList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_CCPreferenceStationList", HFILL }},
{ &hf_lppe_ccpReferenceStationList,
{ "ccpReferenceStationList", "lppe.ccpReferenceStationList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_CCPreferenceStationList", HFILL }},
{ &hf_lppe_areaDescription,
{ "areaDescription", "lppe.areaDescription",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ValidityArea", HFILL }},
{ &hf_lppe_signalSupport,
{ "signalSupport", "lppe.signalSupport",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPsignalSupport", HFILL }},
{ &hf_lppe_signalSupport_item,
{ "OMA-LPPe-AGNSS-CCPsignalSupport", "lppe.OMA_LPPe_AGNSS_CCPsignalSupport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gnss,
{ "gnss", "lppe.gnss",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID", HFILL }},
{ &hf_lppe_signals,
{ "signals", "lppe.signals",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_CCPreferenceStationList_item,
{ "OMA-LPPe-AGNSS-CCPreferenceStationElement", "lppe.OMA_LPPe_AGNSS_CCPreferenceStationElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_referenceStationID,
{ "referenceStationID", "lppe.referenceStationID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPreferenceStationID", HFILL }},
{ &hf_lppe_referenceStationLocation,
{ "referenceStationLocation", "lppe.referenceStationLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dposition", HFILL }},
{ &hf_lppe_antennaDescription,
{ "antennaDescription", "lppe.antennaDescription",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_AntennaDescription", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvide_item,
{ "OMA-LPPe-AGNSS-CCPassistGenericProvideElement", "lppe.OMA_LPPe_AGNSS_CCPassistGenericProvideElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ccpPerSignalList,
{ "ccpPerSignalList", "lppe.ccpPerSignalList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPperSignalElement", HFILL }},
{ &hf_lppe_ccpPerSignalList_item,
{ "OMA-LPPe-AGNSS-CCPperSignalElement", "lppe.OMA_LPPe_AGNSS_CCPperSignalElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_signal_ID,
{ "signal-ID", "lppe.signal_ID",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalID", HFILL }},
{ &hf_lppe_ccpPerSVlist,
{ "ccpPerSVlist", "lppe.ccpPerSVlist",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_CCPperSVelement", HFILL }},
{ &hf_lppe_ccpPerSVlist_item,
{ "OMA-LPPe-AGNSS-CCPperSVelement", "lppe.OMA_LPPe_AGNSS_CCPperSVelement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_integerCodePhase,
{ "integerCodePhase", "lppe.integerCodePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_codePhase,
{ "codePhase", "lppe.codePhase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_14989622", HFILL }},
{ &hf_lppe_codePhaseError,
{ "codePhaseError", "lppe.codePhaseError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_CodePhaseError_vals), 0,
"OMA_LPPe_AGNSS_CodePhaseError", HFILL }},
{ &hf_lppe_phaseRangeDelta,
{ "phaseRangeDelta", "lppe.phaseRangeDelta",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M524288_524287", HFILL }},
{ &hf_lppe_phaseRangeRMSerror,
{ "phaseRangeRMSerror", "lppe.phaseRangeRMSerror",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_lockIndicator,
{ "lockIndicator", "lppe.lockIndicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_codePhaseRMSError,
{ "codePhaseRMSError", "lppe.codePhaseRMSError",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_cnr,
{ "cnr", "lppe.cnr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_coordinateBased,
{ "coordinateBased", "lppe.coordinateBased",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_CoordinateBased", HFILL }},
{ &hf_lppe_fixedInterval,
{ "fixedInterval", "lppe.fixedInterval",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_interval,
{ "interval", "lppe.interval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_30", HFILL }},
{ &hf_lppe_bases,
{ "bases", "lppe.bases",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_baseForPosVel,
{ "baseForPosVel", "lppe.baseForPosVel",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M100000000_100000000", HFILL }},
{ &hf_lppe_baseForCcRate,
{ "baseForCcRate", "lppe.baseForCcRate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_referencedTo,
{ "referencedTo", "lppe.referencedTo",
FT_UINT32, BASE_DEC, VALS(lppe_T_referencedTo_vals), 0,
NULL, HFILL }},
{ &hf_lppe_pointList,
{ "pointList", "lppe.pointList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_97_OF_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement", HFILL }},
{ &hf_lppe_pointList_item,
{ "OMA-LPPe-AGNSS-NavModel-CoordinateBasedElement", "lppe.OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_time_of_record,
{ "time-of-record", "lppe.time_of_record",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_svIdList,
{ "svIdList", "lppe.svIdList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_NavModel_PVTelement", HFILL }},
{ &hf_lppe_svIdList_item,
{ "OMA-LPPe-AGNSS-NavModel-PVTelement", "lppe.OMA_LPPe_AGNSS_NavModel_PVTelement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_svClockOffset,
{ "svClockOffset", "lppe.svClockOffset",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefPositionX,
{ "ecefPositionX", "lppe.ecefPositionX",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefPositionY,
{ "ecefPositionY", "lppe.ecefPositionY",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefPositionZ,
{ "ecefPositionZ", "lppe.ecefPositionZ",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_clockPosSTD,
{ "clockPosSTD", "lppe.clockPosSTD",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_STDmatrix", HFILL }},
{ &hf_lppe_rateRecord,
{ "rateRecord", "lppe.rateRecord",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_svClockRate,
{ "svClockRate", "lppe.svClockRate",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefVelocityX,
{ "ecefVelocityX", "lppe.ecefVelocityX",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefVelocityY,
{ "ecefVelocityY", "lppe.ecefVelocityY",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_ecefVelocityZ,
{ "ecefVelocityZ", "lppe.ecefVelocityZ",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_BigNumber", HFILL }},
{ &hf_lppe_clockRateVelSTD,
{ "clockRateVelSTD", "lppe.clockRateVelSTD",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModel_STDmatrix", HFILL }},
{ &hf_lppe_msb,
{ "msb", "lppe.msb",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1000000000_1000000000", HFILL }},
{ &hf_lppe_lsb,
{ "lsb", "lppe.lsb",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100", HFILL }},
{ &hf_lppe_e11,
{ "e11", "lppe.e11",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_e22,
{ "e22", "lppe.e22",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_e33,
{ "e33", "lppe.e33",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_e44,
{ "e44", "lppe.e44",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000000", HFILL }},
{ &hf_lppe_e12,
{ "e12", "lppe.e12",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_e13,
{ "e13", "lppe.e13",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_e14,
{ "e14", "lppe.e14",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_e23,
{ "e23", "lppe.e23",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_e24,
{ "e24", "lppe.e24",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_e34,
{ "e34", "lppe.e34",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10000000", HFILL }},
{ &hf_lppe_commonAssistDataReq,
{ "commonAssistDataReq", "lppe.commonAssistDataReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CommonAssistanceDataReq", HFILL }},
{ &hf_lppe_genericAssistDataReq,
{ "genericAssistDataReq", "lppe.genericAssistDataReq",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_GenericAssistanceDataReq", HFILL }},
{ &hf_lppe_ionosphericModelReq,
{ "ionosphericModelReq", "lppe.ionosphericModelReq",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_IonosphericModelReq_vals), 0,
"OMA_LPPe_AGNSS_IonosphericModelReq", HFILL }},
{ &hf_lppe_troposphereModelReq,
{ "troposphereModelReq", "lppe.troposphereModelReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_TroposphereModelReq", HFILL }},
{ &hf_lppe_altitudeAssistanceReq,
{ "altitudeAssistanceReq", "lppe.altitudeAssistanceReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_AltitudeAssistanceReq", HFILL }},
{ &hf_lppe_solarRadiationRequest,
{ "solarRadiationRequest", "lppe.solarRadiationRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_SolarRadiationReq", HFILL }},
{ &hf_lppe_ccpRequestControlParameters,
{ "ccpRequestControlParameters", "lppe.ccpRequestControlParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPrequestControlParameters", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataReq_item,
{ "OMA-LPPe-AGNSS-GenericAssistDataReqElement", "lppe.OMA_LPPe_AGNSS_GenericAssistDataReqElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_waIonoSurfaceReq,
{ "waIonoSurfaceReq", "lppe.waIonoSurfaceReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_WaIonoSurfaceRequest", HFILL }},
{ &hf_lppe_mechanicsReq,
{ "mechanicsReq", "lppe.mechanicsReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_MechanicsReq", HFILL }},
{ &hf_lppe_dcbReq,
{ "dcbReq", "lppe.dcbReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_DCBreq", HFILL }},
{ &hf_lppe_navModelDegradationModelReq,
{ "navModelDegradationModelReq", "lppe.navModelDegradationModelReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModelDegradationModelReq", HFILL }},
{ &hf_lppe_ccpAssistGenericReq,
{ "ccpAssistGenericReq", "lppe.ccpAssistGenericReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPassistGenericReq", HFILL }},
{ &hf_lppe_navigationModelReq,
{ "navigationModelReq", "lppe.navigationModelReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavigationModelReq", HFILL }},
{ &hf_lppe_staticModels_01,
{ "staticModels", "lppe.staticModels",
FT_NONE, BASE_NONE, NULL, 0,
"T_staticModels_01", HFILL }},
{ &hf_lppe_ionoreq,
{ "ionoreq", "lppe.ionoreq",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_requestBeginTime,
{ "requestBeginTime", "lppe.requestBeginTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_periodicModels,
{ "periodicModels", "lppe.periodicModels",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_waIonoSurface,
{ "waIonoSurface", "lppe.waIonoSurface",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersRequest", HFILL }},
{ &hf_lppe_troposphereModelReq_01,
{ "troposphereModelReq", "lppe.troposphereModelReq",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_supportForMultipleGridPoints,
{ "supportForMultipleGridPoints", "lppe.supportForMultipleGridPoints",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_reference_01,
{ "reference", "lppe.reference",
FT_NONE, BASE_NONE, NULL, 0,
"T_reference_01", HFILL }},
{ &hf_lppe_pd_02,
{ "pd", "lppe.pd",
FT_UINT32, BASE_DEC, VALS(lppe_T_pd_02_vals), 0,
"T_pd_02", HFILL }},
{ &hf_lppe_massRequest,
{ "massRequest", "lppe.massRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_effectiveReflectivityAreaRequest,
{ "effectiveReflectivityAreaRequest", "lppe.effectiveReflectivityAreaRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_pcoRequest,
{ "pcoRequest", "lppe.pcoRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_svInfoRequest,
{ "svInfoRequest", "lppe.svInfoRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ccpSupportAreaRequest,
{ "ccpSupportAreaRequest", "lppe.ccpSupportAreaRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ccpNeighborListRequest,
{ "ccpNeighborListRequest", "lppe.ccpNeighborListRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ccpCommonRequest,
{ "ccpCommonRequest", "lppe.ccpCommonRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_refStation,
{ "refStation", "lppe.refStation",
FT_UINT32, BASE_DEC, VALS(lppe_T_refStation_vals), 0,
NULL, HFILL }},
{ &hf_lppe_posBasedReferenceStationRequest,
{ "posBasedReferenceStationRequest", "lppe.posBasedReferenceStationRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_requestedReferenceStationLocation,
{ "requestedReferenceStationLocation", "lppe.requestedReferenceStationLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_HighAccuracy3Dposition", HFILL }},
{ &hf_lppe_qor,
{ "qor", "lppe.qor",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_QoR_vals), 0,
"OMA_LPPe_AGNSS_QoR", HFILL }},
{ &hf_lppe_idBasedReferenceStationRequest,
{ "idBasedReferenceStationRequest", "lppe.idBasedReferenceStationRequest",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_ReferenceStationIDlist", HFILL }},
{ &hf_lppe_referenceStationKillList,
{ "referenceStationKillList", "lppe.referenceStationKillList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_ReferenceStationIDlist", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_ReferenceStationIDlist_item,
{ "OMA-LPPe-AGNSS-CCPreferenceStationID", "lppe.OMA_LPPe_AGNSS_CCPreferenceStationID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ccpAssist_SignalsReq,
{ "ccpAssist-SignalsReq", "lppe.ccpAssist_SignalsReq",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lppe_navModelID_PrefList,
{ "navModelID-PrefList", "lppe.navModelID_PrefList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_navModelID_PrefList_item,
{ "navModelID-PrefList item", "lppe.navModelID_PrefList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lppe_highAccuracyReferenceTime,
{ "highAccuracyReferenceTime", "lppe.highAccuracyReferenceTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_highAccuracyMeasurements,
{ "highAccuracyMeasurements", "lppe.highAccuracyMeasurements",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_AGNSS_HAgnssProvide_vals), 0,
"OMA_LPPe_AGNSS_HAgnssProvide", HFILL }},
{ &hf_lppe_ionosphereMeasurements,
{ "ionosphereMeasurements", "lppe.ionosphereMeasurements",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_IonosphereMeasurements", HFILL }},
{ &hf_lppe_localSurfaceMeasurements,
{ "localSurfaceMeasurements", "lppe.localSurfaceMeasurements",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_LocalSurfaceMeasurements", HFILL }},
{ &hf_lppe_controlParameters_01,
{ "controlParameters", "lppe.controlParameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_measurements,
{ "measurements", "lppe.measurements",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_position,
{ "position", "lppe.position",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_lppe_referenceTime,
{ "referenceTime", "lppe.referenceTime",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SystemTime", HFILL }},
{ &hf_lppe_localPressure,
{ "localPressure", "lppe.localPressure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_pressureUncertainty,
{ "pressureUncertainty", "lppe.pressureUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_antennaOrientation,
{ "antennaOrientation", "lppe.antennaOrientation",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_Orientation_vals), 0,
"OMA_LPPe_Orientation", HFILL }},
{ &hf_lppe_signalMeasurements,
{ "signalMeasurements", "lppe.signalMeasurements",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssMeasurementElement", HFILL }},
{ &hf_lppe_signalMeasurements_item,
{ "OMA-LPPe-AGNSS-HAgnssMeasurementElement", "lppe.OMA_LPPe_AGNSS_HAgnssMeasurementElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSperSignalList,
{ "haGNSSperSignalList", "lppe.haGNSSperSignalList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_HAgnssPerSignalElement", HFILL }},
{ &hf_lppe_haGNSSperSignalList_item,
{ "OMA-LPPe-HAgnssPerSignalElement", "lppe.OMA_LPPe_HAgnssPerSignalElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSperSVlist,
{ "haGNSSperSVlist", "lppe.haGNSSperSVlist",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_HAgnssPerSVelement", HFILL }},
{ &hf_lppe_haGNSSperSVlist_item,
{ "OMA-LPPe-HAgnssPerSVelement", "lppe.OMA_LPPe_HAgnssPerSVelement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_multipathDetection,
{ "multipathDetection", "lppe.multipathDetection",
FT_UINT32, BASE_DEC, VALS(lppe_T_multipathDetection_vals), 0,
NULL, HFILL }},
{ &hf_lppe_adr,
{ "adr", "lppe.adr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_536870911", HFILL }},
{ &hf_lppe_adrRMSerror,
{ "adrRMSerror", "lppe.adrRMSerror",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_tecPerSV,
{ "tecPerSV", "lppe.tecPerSV",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_TECPerSV", HFILL }},
{ &hf_lppe_tecAtZenith,
{ "tecAtZenith", "lppe.tecAtZenith",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_TECAtZenith", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_TECPerSV_item,
{ "OMA-LPPe-AGNSS-TECPerSVElement", "lppe.OMA_LPPe_AGNSS_TECPerSVElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_azimuth,
{ "azimuth", "lppe.azimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lppe_elevation,
{ "elevation", "lppe.elevation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_90", HFILL }},
{ &hf_lppe_tecValue,
{ "tecValue", "lppe.tecValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_tecUncertainty,
{ "tecUncertainty", "lppe.tecUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_tecValueAtZenith,
{ "tecValueAtZenith", "lppe.tecValueAtZenith",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lppe_tecUncertaintyAtZenith,
{ "tecUncertaintyAtZenith", "lppe.tecUncertaintyAtZenith",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_temperatureMeasurement,
{ "temperatureMeasurement", "lppe.temperatureMeasurement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_temperatureUncertainty,
{ "temperatureUncertainty", "lppe.temperatureUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lppe_positioningInstructions,
{ "positioningInstructions", "lppe.positioningInstructions",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_PositioningInstructions", HFILL }},
{ &hf_lppe_ionosphereMeasurementsReq,
{ "ionosphereMeasurementsReq", "lppe.ionosphereMeasurementsReq",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_localSurfaceMeasurementReq,
{ "localSurfaceMeasurementReq", "lppe.localSurfaceMeasurementReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_LocalSurfaceMeasurementReq", HFILL }},
{ &hf_lppe_highAccuracyMethodRequested,
{ "highAccuracyMethodRequested", "lppe.highAccuracyMethodRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_haGNSSreq,
{ "haGNSSreq", "lppe.haGNSSreq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_HAgnssRequestControlParameters", HFILL }},
{ &hf_lppe_rate_01,
{ "rate", "lppe.rate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_63", HFILL }},
{ &hf_lppe_antennaInformationReq,
{ "antennaInformationReq", "lppe.antennaInformationReq",
FT_UINT32, BASE_DEC, VALS(lppe_T_antennaInformationReq_vals), 0,
NULL, HFILL }},
{ &hf_lppe_pressureInformationReq,
{ "pressureInformationReq", "lppe.pressureInformationReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_signalReqList,
{ "signalReqList", "lppe.signalReqList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssSignalReqElement", HFILL }},
{ &hf_lppe_signalReqList_item,
{ "OMA-LPPe-AGNSS-HAgnssSignalReqElement", "lppe.OMA_LPPe_AGNSS_HAgnssSignalReqElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_gnssID,
{ "gnssID", "lppe.gnssID",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID", HFILL }},
{ &hf_lppe_assistanceDataSupportList,
{ "assistanceDataSupportList", "lppe.assistanceDataSupportList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_AssistanceDataSupportList", HFILL }},
{ &hf_lppe_environmentObservationSupportList,
{ "environmentObservationSupportList", "lppe.environmentObservationSupportList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_EnvironmentObservationSupportList", HFILL }},
{ &hf_lppe_haGNSSsupport,
{ "haGNSSsupport", "lppe.haGNSSsupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_HAgnssSupport", HFILL }},
{ &hf_lppe_commonAssistanceDataSupport,
{ "commonAssistanceDataSupport", "lppe.commonAssistanceDataSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CommonAssistanceDataSupport", HFILL }},
{ &hf_lppe_genericAssistanceDataSupport,
{ "genericAssistanceDataSupport", "lppe.genericAssistanceDataSupport",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_AGNSS_GenericAssistanceDataSupport", HFILL }},
{ &hf_lppe_ionosphereMeasurementSupport,
{ "ionosphereMeasurementSupport", "lppe.ionosphereMeasurementSupport",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_pressureMeasurementSupported,
{ "pressureMeasurementSupported", "lppe.pressureMeasurementSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_temperatureMeasurementSupported,
{ "temperatureMeasurementSupported", "lppe.temperatureMeasurementSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ionosphericModelSupport,
{ "ionosphericModelSupport", "lppe.ionosphericModelSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_IonosphericModelSupport", HFILL }},
{ &hf_lppe_troposphereModelSupport,
{ "troposphereModelSupport", "lppe.troposphereModelSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_TroposphereModelSupport", HFILL }},
{ &hf_lppe_altitudeAssistanceSupport,
{ "altitudeAssistanceSupport", "lppe.altitudeAssistanceSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_AltitudeAssistanceSupport", HFILL }},
{ &hf_lppe_solarRadiationSupport,
{ "solarRadiationSupport", "lppe.solarRadiationSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_SolarRadiationSupport", HFILL }},
{ &hf_lppe_ccpSupport,
{ "ccpSupport", "lppe.ccpSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_CCPsupport", HFILL }},
{ &hf_lppe_ionoModel,
{ "ionoModel", "lppe.ionoModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_tropoModel,
{ "tropoModel", "lppe.tropoModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_supportAreaAssistanceSupported,
{ "supportAreaAssistanceSupported", "lppe.supportAreaAssistanceSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_multiReferenceStationSupported,
{ "multiReferenceStationSupported", "lppe.multiReferenceStationSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataSupport_item,
{ "OMA-LPPe-AGNSS-GenericAssistDataSupportElement", "lppe.OMA_LPPe_AGNSS_GenericAssistDataSupportElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mechnanicsSupport,
{ "mechnanicsSupport", "lppe.mechnanicsSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_MechanicsSupport", HFILL }},
{ &hf_lppe_dcbSupport,
{ "dcbSupport", "lppe.dcbSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_DCBsupport", HFILL }},
{ &hf_lppe_navModelAccuracyModelDegradationSupport,
{ "navModelAccuracyModelDegradationSupport", "lppe.navModelAccuracyModelDegradationSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModelAccuracyModelDegradationSupport", HFILL }},
{ &hf_lppe_ccpAssistanceSuppport,
{ "ccpAssistanceSuppport", "lppe.ccpAssistanceSuppport",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lppe_navModelSupport,
{ "navModelSupport", "lppe.navModelSupport",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_NavModelSupport", HFILL }},
{ &hf_lppe_navModelSupport_01,
{ "navModelSupport", "lppe.navModelSupport",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_navModelSupport_item,
{ "navModelSupport item", "lppe.navModelSupport_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lppe_modeSupport,
{ "modeSupport", "lppe.modeSupport",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSpressureInformationSupport,
{ "haGNSSpressureInformationSupport", "lppe.haGNSSpressureInformationSupport",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_haGNSSantennaInformationSupport,
{ "haGNSSantennaInformationSupport", "lppe.haGNSSantennaInformationSupport",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSperGNSSsupport,
{ "haGNSSperGNSSsupport", "lppe.haGNSSperGNSSsupport",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport", HFILL }},
{ &hf_lppe_haGNSSperGNSSsupport_item,
{ "OMA-LPPe-AGNSS-HAgnssPerGNSSsupport", "lppe.OMA_LPPe_AGNSS_HAgnssPerGNSSsupport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSsignalSupport,
{ "haGNSSsignalSupport", "lppe.haGNSSsignalSupport",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lppe_assistanceDataSupportListReq,
{ "assistanceDataSupportListReq", "lppe.assistanceDataSupportListReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_environmentObservationSupportListReq,
{ "environmentObservationSupportListReq", "lppe.environmentObservationSupportListReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSsupportReq,
{ "haGNSSsupportReq", "lppe.haGNSSsupportReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_agnss_locationServerErrorCauses,
{ "agnss-locationServerErrorCauses", "lppe.agnss_locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_agnss_targetDeviceErrorCauses,
{ "agnss-targetDeviceErrorCauses", "lppe.agnss_targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_AGNSS_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_waIonoErrorCauses,
{ "waIonoErrorCauses", "lppe.waIonoErrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_waIonoErrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_ccpErrorCauses,
{ "ccpErrorCauses", "lppe.ccpErrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_ccpErrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_highAccuracyErrorCauses,
{ "highAccuracyErrorCauses", "lppe.highAccuracyErrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_highAccuracyErrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_ionosphereMeasurementErrorCauses,
{ "ionosphereMeasurementErrorCauses", "lppe.ionosphereMeasurementErrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_ionosphereMeasurementErrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_environmentObservationErrorCauses,
{ "environmentObservationErrorCauses", "lppe.environmentObservationErrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_environmentObservationErrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_haGNSSerrorCauses,
{ "haGNSSerrorCauses", "lppe.haGNSSerrorCauses",
FT_UINT32, BASE_DEC, VALS(lppe_T_haGNSSerrorCauses_vals), 0,
NULL, HFILL }},
{ &hf_lppe_stationID,
{ "stationID", "lppe.stationID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_antennaDescription_01,
{ "antennaDescription", "lppe.antennaDescription",
FT_UINT32, BASE_DEC, VALS(lppe_T_antennaDescription_vals), 0,
NULL, HFILL }},
{ &hf_lppe_igsAntennaName,
{ "igsAntennaName", "lppe.igsAntennaName",
FT_STRING, BASE_NONE, NULL, 0,
"OMA_LPPe_CharArray", HFILL }},
{ &hf_lppe_proprietaryName,
{ "proprietaryName", "lppe.proprietaryName",
FT_STRING, BASE_NONE, NULL, 0,
"OMA_LPPe_CharArray", HFILL }},
{ &hf_lppe_antennaSetupID,
{ "antennaSetupID", "lppe.antennaSetupID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_antennaSerialNumber,
{ "antennaSerialNumber", "lppe.antennaSerialNumber",
FT_STRING, BASE_NONE, NULL, 0,
"OMA_LPPe_CharArray", HFILL }},
{ &hf_lppe_targetDeviceAbortCauses,
{ "targetDeviceAbortCauses", "lppe.targetDeviceAbortCauses",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ccpAbort,
{ "ccpAbort", "lppe.ccpAbort",
FT_UINT32, BASE_DEC, VALS(lppe_T_ccpAbort_vals), 0,
NULL, HFILL }},
{ &hf_lppe_waIonoAbort,
{ "waIonoAbort", "lppe.waIonoAbort",
FT_UINT32, BASE_DEC, VALS(lppe_T_waIonoAbort_vals), 0,
NULL, HFILL }},
{ &hf_lppe_otdoa_ReferenceCellInfo,
{ "otdoa-ReferenceCellInfo", "lppe.otdoa_ReferenceCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_ReferenceCellInfo", HFILL }},
{ &hf_lppe_otdoa_NeighbourCellInfo,
{ "otdoa-NeighbourCellInfo", "lppe.otdoa_NeighbourCellInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_NeighbourCellInfoList", HFILL }},
{ &hf_lppe_otdoa_Error,
{ "otdoa-Error", "lppe.otdoa_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_Error_vals), 0,
"OMA_LPPe_OTDOA_Error", HFILL }},
{ &hf_lppe_referenceCellInfo,
{ "referenceCellInfo", "lppe.referenceCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_ReferenceCellInfo", HFILL }},
{ &hf_lppe_positionCalculationInfoRef,
{ "positionCalculationInfoRef", "lppe.positionCalculationInfoRef",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_PositionCalculationInfoRef", HFILL }},
{ &hf_lppe_systemFrameNumber,
{ "systemFrameNumber", "lppe.systemFrameNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_10", HFILL }},
{ &hf_lppe_rtdReferenceStd,
{ "rtdReferenceStd", "lppe.rtdReferenceStd",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_RTDquality", HFILL }},
{ &hf_lppe_cellLocation,
{ "cellLocation", "lppe.cellLocation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_reference_point,
{ "reference-point", "lppe.reference_point",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePoint", HFILL }},
{ &hf_lppe_relative_location,
{ "relative-location", "lppe.relative_location",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_femtoCellInfo,
{ "femtoCellInfo", "lppe.femtoCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_location_reliability,
{ "location-reliability", "lppe.location_reliability",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100", HFILL }},
{ &hf_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoList_item,
{ "OMA-LPPe-OTDOA-NeighbourFreqCellInfoList", "lppe.OMA_LPPe_OTDOA_NeighbourFreqCellInfoList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_neighbourCellInfoList_eNB,
{ "neighbourCellInfoList-eNB", "lppe.neighbourCellInfoList_eNB",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB", HFILL }},
{ &hf_lppe_neighbourCellInfoList_eNB_item,
{ "OMA-LPPe-OTDOA-NeighbourCellInfoElement-eNB", "lppe.OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_neighbourCellInfoList_HeNB,
{ "neighbourCellInfoList-HeNB", "lppe.neighbourCellInfoList_HeNB",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB", HFILL }},
{ &hf_lppe_neighbourCellInfoList_HeNB_item,
{ "OMA-LPPe-OTDOA-NeighbourCellInfoElement-HeNB", "lppe.OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relative_Location,
{ "relative-Location", "lppe.relative_Location",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_otdoa_eNB_CellDataList,
{ "otdoa-eNB-CellDataList", "lppe.otdoa_eNB_CellDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_OTDOA_CellData", HFILL }},
{ &hf_lppe_otdoa_eNB_CellDataList_item,
{ "OMA-LPPe-OTDOA-CellData", "lppe.OMA_LPPe_OTDOA_CellData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_otdoa_HeNB_CellDataList,
{ "otdoa-HeNB-CellDataList", "lppe.otdoa_HeNB_CellDataList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_CellData", HFILL }},
{ &hf_lppe_otdoa_NeighbourCellInfoElement,
{ "otdoa-NeighbourCellInfoElement", "lppe.otdoa_NeighbourCellInfoElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rtdInfo,
{ "rtdInfo", "lppe.rtdInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_subframeOffset,
{ "subframeOffset", "lppe.subframeOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10229", HFILL }},
{ &hf_lppe_fineRTD,
{ "fineRTD", "lppe.fineRTD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99999", HFILL }},
{ &hf_lppe_fineRTDstd,
{ "fineRTDstd", "lppe.fineRTDstd",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_RTDquality", HFILL }},
{ &hf_lppe_fineRTDdriftRate,
{ "fineRTDdriftRate", "lppe.fineRTDdriftRate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M100_100", HFILL }},
{ &hf_lppe_resolution,
{ "resolution", "lppe.resolution",
FT_UINT32, BASE_DEC, VALS(lppe_T_resolution_vals), 0,
NULL, HFILL }},
{ &hf_lppe_quality,
{ "quality", "lppe.quality",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppe_lteCell,
{ "lteCell", "lppe.lteCell",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_physCellId,
{ "physCellId", "lppe.physCellId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_503", HFILL }},
{ &hf_lppe_eARFCN,
{ "eARFCN", "lppe.eARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lppe_ecgi,
{ "ecgi", "lppe.ecgi",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lppe_requestedCells,
{ "requestedCells", "lppe.requestedCells",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_otdoaLocationInformation,
{ "otdoaLocationInformation", "lppe.otdoaLocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_LocationInformation", HFILL }},
{ &hf_lppe_otdoaError,
{ "otdoaError", "lppe.otdoaError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_Error_vals), 0,
"OMA_LPPe_OTDOA_Error", HFILL }},
{ &hf_lppe_cellGlobalId,
{ "cellGlobalId", "lppe.cellGlobalId",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lppe_assistanceAvailability,
{ "assistanceAvailability", "lppe.assistanceAvailability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_eNodeB_AD_sup,
{ "eNodeB-AD-sup", "lppe.eNodeB_AD_sup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_home_eNodeB_AD_sup,
{ "home-eNodeB-AD-sup", "lppe.home_eNodeB_AD_sup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_vals), 0,
NULL, HFILL }},
{ &hf_lppe_cause_01,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_01_vals), 0,
"T_cause_01", HFILL }},
{ &hf_lppe_referenceBTS,
{ "referenceBTS", "lppe.referenceBTS",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_ReferenceBTSForAssistance", HFILL }},
{ &hf_lppe_msrAssistDataList,
{ "msrAssistDataList", "lppe.msrAssistDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_MsrAssistDataList", HFILL }},
{ &hf_lppe_systemInfoAssistDataList,
{ "systemInfoAssistDataList", "lppe.systemInfoAssistDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_SystemInfoAssistDataList", HFILL }},
{ &hf_lppe_eotdError,
{ "eotdError", "lppe.eotdError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_EOTD_Error_vals), 0,
"OMA_LPPe_EOTD_Error", HFILL }},
{ &hf_lppe_bsicAndCarrier,
{ "bsicAndCarrier", "lppe.bsicAndCarrier",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CellNonUniqueIDGERAN", HFILL }},
{ &hf_lppe_timeSlotScheme,
{ "timeSlotScheme", "lppe.timeSlotScheme",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_EOTD_TimeSlotScheme_vals), 0,
"OMA_LPPe_EOTD_TimeSlotScheme", HFILL }},
{ &hf_lppe_btsPosition,
{ "btsPosition", "lppe.btsPosition",
FT_UINT32, BASE_DEC, VALS(lppe_T_btsPosition_vals), 0,
NULL, HFILL }},
{ &hf_lppe_ellipsoidPoint,
{ "ellipsoidPoint", "lppe.ellipsoidPoint",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_Point", HFILL }},
{ &hf_lppe_ellipsoidPointWithAltitudeAndUncertaintyEllipsoid,
{ "ellipsoidPointWithAltitudeAndUncertaintyEllipsoid", "lppe.ellipsoidPointWithAltitudeAndUncertaintyEllipsoid",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_EOTD_MsrAssistDataList_item,
{ "OMA-LPPe-EOTD-MsrAssistBTS", "lppe.OMA_LPPe_EOTD_MsrAssistBTS",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_multiFrameOffset,
{ "multiFrameOffset", "lppe.multiFrameOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_MultiFrameOffset", HFILL }},
{ &hf_lppe_roughRTD,
{ "roughRTD", "lppe.roughRTD",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_RoughRTD", HFILL }},
{ &hf_lppe_expectedOTD,
{ "expectedOTD", "lppe.expectedOTD",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_ExpectedOTD", HFILL }},
{ &hf_lppe_calcAssistanceBTS,
{ "calcAssistanceBTS", "lppe.calcAssistanceBTS",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_CalcAssistanceBTS", HFILL }},
{ &hf_lppe_OMA_LPPe_EOTD_SystemInfoAssistDataList_item,
{ "OMA-LPPe-EOTD-SystemInfoAssistBTS", "lppe.OMA_LPPe_EOTD_SystemInfoAssistBTS",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_EOTD_SystemInfoAssistBTS_vals), 0,
NULL, HFILL }},
{ &hf_lppe_notPresent,
{ "notPresent", "lppe.notPresent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_present,
{ "present", "lppe.present",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_AssistBTSData", HFILL }},
{ &hf_lppe_fineRTD_01,
{ "fineRTD", "lppe.fineRTD",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_FineRTD", HFILL }},
{ &hf_lppe_relativePos,
{ "relativePos", "lppe.relativePos",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_relativePos", HFILL }},
{ &hf_lppe_relativeNorth_01,
{ "relativeNorth", "lppe.relativeNorth",
FT_INT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_RelDistance", HFILL }},
{ &hf_lppe_relativeEast_01,
{ "relativeEast", "lppe.relativeEast",
FT_INT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_RelDistance", HFILL }},
{ &hf_lppe_relativeAlt,
{ "relativeAlt", "lppe.relativeAlt",
FT_INT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_RelativeAlt", HFILL }},
{ &hf_lppe_eotdAssistanceReq,
{ "eotdAssistanceReq", "lppe.eotdAssistanceReq",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eotdMsrElement,
{ "eotdMsrElement", "lppe.eotdMsrElement",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_MsrElement", HFILL }},
{ &hf_lppe_refFrameNumber,
{ "refFrameNumber", "lppe.refFrameNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_42431", HFILL }},
{ &hf_lppe_referenceTimeSlot,
{ "referenceTimeSlot", "lppe.referenceTimeSlot",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_ModuloTimeSlot", HFILL }},
{ &hf_lppe_toaMeasurementsOfRef,
{ "toaMeasurementsOfRef", "lppe.toaMeasurementsOfRef",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_TOA_MeasurementsOfRef", HFILL }},
{ &hf_lppe_stdResolution,
{ "stdResolution", "lppe.stdResolution",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_lppe_taCorrection,
{ "taCorrection", "lppe.taCorrection",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_960", HFILL }},
{ &hf_lppe_otd_FirstSetMsrs,
{ "otd-FirstSetMsrs", "lppe.otd_FirstSetMsrs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_15_OF_OMA_LPPe_EOTD_MeasurementWithID", HFILL }},
{ &hf_lppe_otd_FirstSetMsrs_item,
{ "OMA-LPPe-EOTD-MeasurementWithID", "lppe.OMA_LPPe_EOTD_MeasurementWithID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_refQuality,
{ "refQuality", "lppe.refQuality",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_lppe_numOfMeasurements,
{ "numOfMeasurements", "lppe.numOfMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_3", HFILL }},
{ &hf_lppe_neighborIdentity,
{ "neighborIdentity", "lppe.neighborIdentity",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_EOTD_NeighborIdentity_vals), 0,
"OMA_LPPe_EOTD_NeighborIdentity", HFILL }},
{ &hf_lppe_nborTimeSlot,
{ "nborTimeSlot", "lppe.nborTimeSlot",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_ModuloTimeSlot", HFILL }},
{ &hf_lppe_eotdQuality,
{ "eotdQuality", "lppe.eotdQuality",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_EOTDQuality", HFILL }},
{ &hf_lppe_otdValue,
{ "otdValue", "lppe.otdValue",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_OTDValue", HFILL }},
{ &hf_lppe_ci,
{ "ci", "lppe.ci",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_CellID", HFILL }},
{ &hf_lppe_multiFrameCarrier,
{ "multiFrameCarrier", "lppe.multiFrameCarrier",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_MultiFrameCarrier", HFILL }},
{ &hf_lppe_requestIndex,
{ "requestIndex", "lppe.requestIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_RequestIndex", HFILL }},
{ &hf_lppe_systemInfoIndex,
{ "systemInfoIndex", "lppe.systemInfoIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_SystemInfoIndex", HFILL }},
{ &hf_lppe_ciAndLac,
{ "ciAndLac", "lppe.ciAndLac",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CellLocalIdGERAN", HFILL }},
{ &hf_lppe_nbrOfMeasurements,
{ "nbrOfMeasurements", "lppe.nbrOfMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_3", HFILL }},
{ &hf_lppe_stdOfEOTD,
{ "stdOfEOTD", "lppe.stdOfEOTD",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_lppe_bcchCarrier,
{ "bcchCarrier", "lppe.bcchCarrier",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_EOTD_BCCHCarrier", HFILL }},
{ &hf_lppe_eotdSupport,
{ "eotdSupport", "lppe.eotdSupport",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses_01,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_01,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_EOTD_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_02,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_02_vals), 0,
"T_cause_02", HFILL }},
{ &hf_lppe_cause_03,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_03_vals), 0,
"T_cause_03", HFILL }},
{ &hf_lppe_expectedOTD_01,
{ "expectedOTD", "lppe.expectedOTD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1250", HFILL }},
{ &hf_lppe_expOTDUncertainty,
{ "expOTDUncertainty", "lppe.expOTDUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lppe_referenceCellInfo_01,
{ "referenceCellInfo", "lppe.referenceCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_ReferenceCellInfo", HFILL }},
{ &hf_lppe_neigborCellList,
{ "neigborCellList", "lppe.neigborCellList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_NeighborCellList", HFILL }},
{ &hf_lppe_otdoaUtraError,
{ "otdoaUtraError", "lppe.otdoaUtraError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_Error_vals), 0,
"OMA_LPPe_OTDOA_UTRA_Error", HFILL }},
{ &hf_lppe_sfn,
{ "sfn", "lppe.sfn",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_modeSpecificInfo,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_vals), 0,
NULL, HFILL }},
{ &hf_lppe_fdd,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_primaryCPICH_info,
{ "primaryCPICH-info", "lppe.primaryCPICH_info",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info", HFILL }},
{ &hf_lppe_tdd,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellAndChannelIdentity,
{ "cellAndChannelIdentity", "lppe.cellAndChannelIdentity",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_CellAndChannelIdentity", HFILL }},
{ &hf_lppe_frequencyInfo,
{ "frequencyInfo", "lppe.frequencyInfo",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_UTRA_FrequencyInfo", HFILL }},
{ &hf_lppe_refPosAssist,
{ "refPosAssist", "lppe.refPosAssist",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_RefPosAssist", HFILL }},
{ &hf_lppe_ipdl_parameters,
{ "ipdl-parameters", "lppe.ipdl_parameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_IPDL_Parameters", HFILL }},
{ &hf_lppe_cellPosition,
{ "cellPosition", "lppe.cellPosition",
FT_UINT32, BASE_DEC, VALS(lppe_T_cellPosition_vals), 0,
NULL, HFILL }},
{ &hf_lppe_ellipsoidPointWithAltitude,
{ "ellipsoidPointWithAltitude", "lppe.ellipsoidPointWithAltitude",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_roundTripTime,
{ "roundTripTime", "lppe.roundTripTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_327", HFILL }},
{ &hf_lppe_roundTripTimeExtension,
{ "roundTripTimeExtension", "lppe.roundTripTimeExtension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_70274", HFILL }},
{ &hf_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellList_item,
{ "OMA-LPPe-OTDOA-UTRA-NeighborCellInfo", "lppe.OMA_LPPe_OTDOA_UTRA_NeighborCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_modeSpecificInfo_01,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_01_vals), 0,
"T_modeSpecificInfo_01", HFILL }},
{ &hf_lppe_fdd_01,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_01", HFILL }},
{ &hf_lppe_tdd_01,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_01", HFILL }},
{ &hf_lppe_sfn_SFN_relTimeDifference,
{ "sfn-SFN-relTimeDifference", "lppe.sfn_SFN_relTimeDifference",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_SFN_SFN_RelTimeDifference1", HFILL }},
{ &hf_lppe_sfn_offsetValidity,
{ "sfn-offsetValidity", "lppe.sfn_offsetValidity",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_SFN_OffsetValidity_vals), 0,
"OMA_LPPe_OTDOA_UTRA_SFN_OffsetValidity", HFILL }},
{ &hf_lppe_sfn_SFN_drift,
{ "sfn-SFN-drift", "lppe.sfn_SFN_drift",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_Drift_vals), 0,
"OMA_LPPe_OTDOA_UTRA_SFN_SFN_Drift", HFILL }},
{ &hf_lppe_searchWindowSize,
{ "searchWindowSize", "lppe.searchWindowSize",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_SearchWindowSize_vals), 0,
"OMA_LPPe_OTDOA_UTRA_SearchWindowSize", HFILL }},
{ &hf_lppe_positioningAssistance,
{ "positioningAssistance", "lppe.positioningAssistance",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PositioningAssistance", HFILL }},
{ &hf_lppe_sfn_offset,
{ "sfn-offset", "lppe.sfn_offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_sfn_sfn_relTimeDifference,
{ "sfn-sfn-relTimeDifference", "lppe.sfn_sfn_relTimeDifference",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_38399", HFILL }},
{ &hf_lppe_relativeNorth_02,
{ "relativeNorth", "lppe.relativeNorth",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20000_20000", HFILL }},
{ &hf_lppe_relativeEast_02,
{ "relativeEast", "lppe.relativeEast",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20000_20000", HFILL }},
{ &hf_lppe_relativeAltitude_01,
{ "relativeAltitude", "lppe.relativeAltitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M4000_4000", HFILL }},
{ &hf_lppe_fineSFN_SFN,
{ "fineSFN-SFN", "lppe.fineSFN_SFN",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_fineSFN_SFN", HFILL }},
{ &hf_lppe_modeSpecificInfo_02,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_02_vals), 0,
"T_modeSpecificInfo_02", HFILL }},
{ &hf_lppe_fdd_02,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_02", HFILL }},
{ &hf_lppe_ip_spacing,
{ "ip-spacing", "lppe.ip_spacing",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_IP_Spacing_vals), 0,
"OMA_LPPe_OTDOA_UTRA_IP_Spacing", HFILL }},
{ &hf_lppe_ip_length,
{ "ip-length", "lppe.ip_length",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_IP_Length_vals), 0,
"OMA_LPPe_OTDOA_UTRA_IP_Length", HFILL }},
{ &hf_lppe_ip_Offset,
{ "ip-Offset", "lppe.ip_Offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9", HFILL }},
{ &hf_lppe_seed,
{ "seed", "lppe.seed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_burstModeParameters,
{ "burstModeParameters", "lppe.burstModeParameters",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_BurstModeParameters", HFILL }},
{ &hf_lppe_tdd_02,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_02", HFILL }},
{ &hf_lppe_ip_spacing_tdd,
{ "ip-spacing-tdd", "lppe.ip_spacing_tdd",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_IP_Spacing_TDD_vals), 0,
"OMA_LPPe_OTDOA_UTRA_IP_Spacing_TDD", HFILL }},
{ &hf_lppe_ip_slot,
{ "ip-slot", "lppe.ip_slot",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_14", HFILL }},
{ &hf_lppe_ip_start,
{ "ip-start", "lppe.ip_start",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lppe_ip_PCCPCH,
{ "ip-PCCPCH", "lppe.ip_PCCPCH",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_IP_PCCPCH", HFILL }},
{ &hf_lppe_burstStart,
{ "burstStart", "lppe.burstStart",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lppe_burstLength,
{ "burstLength", "lppe.burstLength",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_25", HFILL }},
{ &hf_lppe_burstFreq,
{ "burstFreq", "lppe.burstFreq",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_16", HFILL }},
{ &hf_lppe_otdoaUtraAssistanceReq,
{ "otdoaUtraAssistanceReq", "lppe.otdoaUtraAssistanceReq",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_otdoaUtraMeasurement,
{ "otdoaUtraMeasurement", "lppe.otdoaUtraMeasurement",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_Measurement", HFILL }},
{ &hf_lppe_timeStampData,
{ "timeStampData", "lppe.timeStampData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_TimeStampData", HFILL }},
{ &hf_lppe_modeSpecificInfoMeas,
{ "modeSpecificInfoMeas", "lppe.modeSpecificInfoMeas",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfoMeas_vals), 0,
NULL, HFILL }},
{ &hf_lppe_fdd_03,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_03", HFILL }},
{ &hf_lppe_referenceCellIdentity,
{ "referenceCellIdentity", "lppe.referenceCellIdentity",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info", HFILL }},
{ &hf_lppe_ue_RX_TX_TimeDifferenceType2Info,
{ "ue-RX-TX-TimeDifferenceType2Info", "lppe.ue_RX_TX_TimeDifferenceType2Info",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info", HFILL }},
{ &hf_lppe_tdd_03,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_03", HFILL }},
{ &hf_lppe_neighborList,
{ "neighborList", "lppe.neighborList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_NeighborList", HFILL }},
{ &hf_lppe_ue_RX_TX_timeDifferenceType2,
{ "ue-RX-TX-timeDifferenceType2", "lppe.ue_RX_TX_timeDifferenceType2",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_TimeDifferenceType2", HFILL }},
{ &hf_lppe_neighborQuality,
{ "neighborQuality", "lppe.neighborQuality",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_NeighborQuality", HFILL }},
{ &hf_lppe_OMA_LPPe_OTDOA_UTRA_NeighborList_item,
{ "OMA-LPPe-OTDOA-UTRA-Neighbor", "lppe.OMA_LPPe_OTDOA_UTRA_Neighbor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_modeSpecificInfo_03,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_03_vals), 0,
"T_modeSpecificInfo_03", HFILL }},
{ &hf_lppe_fdd_04,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_04", HFILL }},
{ &hf_lppe_neighborIdentity_01,
{ "neighborIdentity", "lppe.neighborIdentity",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info", HFILL }},
{ &hf_lppe_ue_RX_TX_timeDifferenceType2Info,
{ "ue-RX-TX-timeDifferenceType2Info", "lppe.ue_RX_TX_timeDifferenceType2Info",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info", HFILL }},
{ &hf_lppe_tdd_04,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_04", HFILL }},
{ &hf_lppe_uarfcn,
{ "uarfcn", "lppe.uarfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_sfn_sfn_ObsTimeDifference2,
{ "sfn-sfn-ObsTimeDifference2", "lppe.sfn_sfn_ObsTimeDifference2",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_SFN_SFN_ObsTimeDifference2", HFILL }},
{ &hf_lppe_quality_01,
{ "quality", "lppe.quality",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_Quality", HFILL }},
{ &hf_lppe_numberOfOTDOA_Measurements,
{ "numberOfOTDOA-Measurements", "lppe.numberOfOTDOA_Measurements",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_3", HFILL }},
{ &hf_lppe_stdOfOTDOA_Measurements,
{ "stdOfOTDOA-Measurements", "lppe.stdOfOTDOA_Measurements",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_lppe_utraCellGlobalID,
{ "utraCellGlobalID", "lppe.utraCellGlobalID",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lppe_nonUniqueCellID,
{ "nonUniqueCellID", "lppe.nonUniqueCellID",
FT_UINT32, BASE_DEC, VALS(lppe_T_nonUniqueCellID_vals), 0,
NULL, HFILL }},
{ &hf_lppe_primaryScramblingCode,
{ "primaryScramblingCode", "lppe.primaryScramblingCode",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryScramblingCode", HFILL }},
{ &hf_lppe_cellParametersId,
{ "cellParametersId", "lppe.cellParametersId",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_CellParametersID", HFILL }},
{ &hf_lppe_ueBasedSupported,
{ "ueBasedSupported", "lppe.ueBasedSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ueAssistedSupported,
{ "ueAssistedSupported", "lppe.ueAssistedSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ipdlSupported,
{ "ipdlSupported", "lppe.ipdlSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_locationServerErrorCauses_02,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_02,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_04,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_04_vals), 0,
"T_cause_04", HFILL }},
{ &hf_lppe_cause_05,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_05_vals), 0,
"T_cause_05", HFILL }},
{ &hf_lppe_burstType,
{ "burstType", "lppe.burstType",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_OTDOA_UTRA_BurstType_vals), 0,
"OMA_LPPe_OTDOA_UTRA_BurstType", HFILL }},
{ &hf_lppe_midambleShift,
{ "midambleShift", "lppe.midambleShift",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_MidambleShiftLong", HFILL }},
{ &hf_lppe_timeslot,
{ "timeslot", "lppe.timeslot",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_TimeSlotNumber", HFILL }},
{ &hf_lppe_cellParametersID,
{ "cellParametersID", "lppe.cellParametersID",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_CellParametersID", HFILL }},
{ &hf_lppe_ecid_LTE_NetworkData,
{ "ecid-LTE-NetworkData", "lppe.ecid_LTE_NetworkData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTENetworks_OF_OMA_LPPe_ECID_LTE_NetworkData", HFILL }},
{ &hf_lppe_ecid_LTE_NetworkData_item,
{ "OMA-LPPe-ECID-LTE-NetworkData", "lppe.OMA_LPPe_ECID_LTE_NetworkData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_LTE_Error,
{ "ecid-LTE-Error", "lppe.ecid_LTE_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_LTE_Error_vals), 0,
"OMA_LPPe_ECID_LTE_Error", HFILL }},
{ &hf_lppe_plmn_Identity,
{ "plmn-Identity", "lppe.plmn_Identity",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mcc,
{ "mcc", "lppe.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mcc_item,
{ "mcc item", "lppe.mcc_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9", HFILL }},
{ &hf_lppe_mnc,
{ "mnc", "lppe.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mnc_item,
{ "mnc item", "lppe.mnc_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9", HFILL }},
{ &hf_lppe_multiple_PLMNs,
{ "multiple-PLMNs", "lppe.multiple_PLMNs",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_reference_location,
{ "reference-location", "lppe.reference_location",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePoint", HFILL }},
{ &hf_lppe_ecid_lte_eNodeB_list,
{ "ecid-lte-eNodeB-list", "lppe.ecid_lte_eNodeB_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_ECID_LTE_eNodeBData", HFILL }},
{ &hf_lppe_ecid_lte_eNodeB_list_item,
{ "OMA-LPPe-ECID-LTE-eNodeBData", "lppe.OMA_LPPe_ECID_LTE_eNodeBData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_lte_HeNB_list,
{ "ecid-lte-HeNB-list", "lppe.ecid_lte_HeNB_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_ECID_LTE_HeNBData", HFILL }},
{ &hf_lppe_ecid_lte_HeNB_list_item,
{ "OMA-LPPe-ECID-LTE-HeNBData", "lppe.OMA_LPPe_ECID_LTE_HeNBData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_lte_eNodeB_CellData,
{ "ecid-lte-eNodeB-CellData", "lppe.ecid_lte_eNodeB_CellData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_ECID_LTE_CellData", HFILL }},
{ &hf_lppe_ecid_lte_eNodeB_CellData_item,
{ "OMA-LPPe-ECID-LTE-CellData", "lppe.OMA_LPPe_ECID_LTE_CellData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_coverageArea,
{ "coverageArea", "lppe.coverageArea",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLANFemtoCoverageArea", HFILL }},
{ &hf_lppe_ecid_lte_HeNB_CellData,
{ "ecid-lte-HeNB-CellData", "lppe.ecid_lte_HeNB_CellData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_CellData", HFILL }},
{ &hf_lppe_cellIdentity_01,
{ "cellIdentity", "lppe.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_lppe_dl_CarrierFreq,
{ "dl-CarrierFreq", "lppe.dl_CarrierFreq",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lppe_rs_transmit_power,
{ "rs-transmit-power", "lppe.rs_transmit_power",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_antennaPortConfig,
{ "antennaPortConfig", "lppe.antennaPortConfig",
FT_UINT32, BASE_DEC, VALS(lppe_T_antennaPortConfig_vals), 0,
NULL, HFILL }},
{ &hf_lppe_antenna_gain,
{ "antenna-gain", "lppe.antenna_gain",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_beam_width,
{ "beam-width", "lppe.beam_width",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_360", HFILL }},
{ &hf_lppe_transmit_direction,
{ "transmit-direction", "lppe.transmit_direction",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_360", HFILL }},
{ &hf_lppe_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency_accuracy",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_lppe_eNBrequestedAD,
{ "eNBrequestedAD", "lppe.eNBrequestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBrequestedAD,
{ "heNBrequestedAD", "lppe.heNBrequestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_LTE_CombinedLocationInformation,
{ "ecid-LTE-CombinedLocationInformation", "lppe.ecid_LTE_CombinedLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxLTEECIDSize_OF_OMA_LPPe_ECID_LTE_LocationInformationList", HFILL }},
{ &hf_lppe_ecid_LTE_CombinedLocationInformation_item,
{ "OMA-LPPe-ECID-LTE-LocationInformationList", "lppe.OMA_LPPe_ECID_LTE_LocationInformationList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_LTE_LocationInformation,
{ "ecid-LTE-LocationInformation", "lppe.ecid_LTE_LocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_LocationInformation", HFILL }},
{ &hf_lppe_relativeTimeStamp,
{ "relativeTimeStamp", "lppe.relativeTimeStamp",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_servingFlag,
{ "servingFlag", "lppe.servingFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_lpp_ECID_SignalMeasurementInformation,
{ "lpp-ECID-SignalMeasurementInformation", "lppe.lpp_ECID_SignalMeasurementInformation",
FT_NONE, BASE_NONE, NULL, 0,
"ECID_SignalMeasurementInformation", HFILL }},
{ &hf_lppe_requestedMeasurements,
{ "requestedMeasurements", "lppe.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_lte_MeasSupported,
{ "ecid-lte-MeasSupported", "lppe.ecid_lte_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_lte_eNodeB_ADSupported,
{ "ecid-lte-eNodeB-ADSupported", "lppe.ecid_lte_eNodeB_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_HeNB_ADSupported,
{ "ecid-utra-HeNB-ADSupported", "lppe.ecid_utra_HeNB_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses_03,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_03,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_LTE_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_06,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_06_vals), 0,
"T_cause_06", HFILL }},
{ &hf_lppe_eNodeBMandatoryDataUnavailable,
{ "eNodeBMandatoryDataUnavailable", "lppe.eNodeBMandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBLocationsUnavailable,
{ "eNodeBLocationsUnavailable", "lppe.eNodeBLocationsUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcellTransmitPowerUnavailable,
{ "eNodeBcellTransmitPowerUnavailable", "lppe.eNodeBcellTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcellAntennaPortConfigUnavailable,
{ "eNodeBcellAntennaPortConfigUnavailable", "lppe.eNodeBcellAntennaPortConfigUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcallAntennaGainUnavailable,
{ "eNodeBcallAntennaGainUnavailable", "lppe.eNodeBcallAntennaGainUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcellBeamWidthUnavailable,
{ "eNodeBcellBeamWidthUnavailable", "lppe.eNodeBcellBeamWidthUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcellTransmitDirectionUnavailable,
{ "eNodeBcellTransmitDirectionUnavailable", "lppe.eNodeBcellTransmitDirectionUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBcellFrequencyAccuracyUnavailable,
{ "eNodeBcellFrequencyAccuracyUnavailable", "lppe.eNodeBcellFrequencyAccuracyUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_eNodeBnonservingADUnavailable,
{ "eNodeBnonservingADUnavailable", "lppe.eNodeBnonservingADUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBMandatoryDataUnavailable,
{ "heNBMandatoryDataUnavailable", "lppe.heNBMandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBLocationUnavailable,
{ "heNBLocationUnavailable", "lppe.heNBLocationUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBLocationReliabilityUnavailable,
{ "heNBLocationReliabilityUnavailable", "lppe.heNBLocationReliabilityUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBcellTransmitPowerUnavailable,
{ "heNBcellTransmitPowerUnavailable", "lppe.heNBcellTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBcellAntennaPortConfigUnavailable,
{ "heNBcellAntennaPortConfigUnavailable", "lppe.heNBcellAntennaPortConfigUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBcellFrequencyAccuracyUnavailable,
{ "heNBcellFrequencyAccuracyUnavailable", "lppe.heNBcellFrequencyAccuracyUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBCoverageAreaUnavailable,
{ "heNBCoverageAreaUnavailable", "lppe.heNBCoverageAreaUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_heNBnonservingADUnavailable,
{ "heNBnonservingADUnavailable", "lppe.heNBnonservingADUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cause_07,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_07_vals), 0,
"T_cause_07", HFILL }},
{ &hf_lppe_rsrpMeasurementNotPossible,
{ "rsrpMeasurementNotPossible", "lppe.rsrpMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rsrqMeasurementNotPossible,
{ "rsrqMeasurementNotPossible", "lppe.rsrqMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ueRxTxMeasurementNotPossible,
{ "ueRxTxMeasurementNotPossible", "lppe.ueRxTxMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_non_servingMeasurementsNotAvailable,
{ "non-servingMeasurementsNotAvailable", "lppe.non_servingMeasurementsNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_historicMeasurementsNotAvailable,
{ "historicMeasurementsNotAvailable", "lppe.historicMeasurementsNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_gsm_NetworkData,
{ "ecid-gsm-NetworkData", "lppe.ecid_gsm_NetworkData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxGSMNetworks_OF_OMA_LPPe_ECID_GSM_NetworkData", HFILL }},
{ &hf_lppe_ecid_gsm_NetworkData_item,
{ "OMA-LPPe-ECID-GSM-NetworkData", "lppe.OMA_LPPe_ECID_GSM_NetworkData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_gsm_Error,
{ "ecid-gsm-Error", "lppe.ecid_gsm_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_GSM_Error_vals), 0,
"OMA_LPPe_ECID_GSM_Error", HFILL }},
{ &hf_lppe_plmn_Identity_01,
{ "plmn-Identity", "lppe.plmn_Identity",
FT_NONE, BASE_NONE, NULL, 0,
"T_plmn_Identity_01", HFILL }},
{ &hf_lppe_mcc_01,
{ "mcc", "lppe.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mcc_01", HFILL }},
{ &hf_lppe_mnc_01,
{ "mnc", "lppe.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mnc_01", HFILL }},
{ &hf_lppe_base_station_list,
{ "base-station-list", "lppe.base_station_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxGSMBaseStations_OF_OMA_LPPe_ECID_GSM_BaseStationData", HFILL }},
{ &hf_lppe_base_station_list_item,
{ "OMA-LPPe-ECID-GSM-BaseStationData", "lppe.OMA_LPPe_ECID_GSM_BaseStationData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_gsm_CellData,
{ "ecid-gsm-CellData", "lppe.ecid_gsm_CellData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxGSMCells_OF_OMA_LPPe_ECID_GSM_CellData", HFILL }},
{ &hf_lppe_ecid_gsm_CellData_item,
{ "OMA-LPPe-ECID-GSM-CellData", "lppe.OMA_LPPe_ECID_GSM_CellData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellNonUniqueIDGERAN,
{ "cellNonUniqueIDGERAN", "lppe.cellNonUniqueIDGERAN",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CellNonUniqueIDGERAN", HFILL }},
{ &hf_lppe_cellLocalIDGERAN,
{ "cellLocalIDGERAN", "lppe.cellLocalIDGERAN",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_CellLocalIdGERAN", HFILL }},
{ &hf_lppe_transmit_power,
{ "transmit-power", "lppe.transmit_power",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_requestedAD,
{ "requestedAD", "lppe.requestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_GSM_CombinedLocationInformation,
{ "ecid-GSM-CombinedLocationInformation", "lppe.ecid_GSM_CombinedLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxGSMECIDSize_OF_OMA_LPPe_ECID_GSM_LocationInformationList", HFILL }},
{ &hf_lppe_ecid_GSM_CombinedLocationInformation_item,
{ "OMA-LPPe-ECID-GSM-LocationInformationList", "lppe.OMA_LPPe_ECID_GSM_LocationInformationList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_GSM_Error,
{ "ecid-GSM-Error", "lppe.ecid_GSM_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_GSM_Error_vals), 0,
"OMA_LPPe_ECID_GSM_Error", HFILL }},
{ &hf_lppe_ecid_GSM_LocationInformation,
{ "ecid-GSM-LocationInformation", "lppe.ecid_GSM_LocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_LocationInformation", HFILL }},
{ &hf_lppe_cellGlobalIdGERAN,
{ "cellGlobalIdGERAN", "lppe.cellGlobalIdGERAN",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rxLevel,
{ "rxLevel", "lppe.rxLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_tA,
{ "tA", "lppe.tA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_nMR_GERAN,
{ "nMR-GERAN", "lppe.nMR_GERAN",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_NMR_GERAN", HFILL }},
{ &hf_lppe_OMA_LPPe_NMR_GERAN_item,
{ "OMA-LPPe-NMR-GERAN item", "lppe.OMA_LPPe_NMR_GERAN_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_requestedMeasurements_01,
{ "requestedMeasurements", "lppe.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedMeasurements_01", HFILL }},
{ &hf_lppe_ecid_gsm_MeasSupported,
{ "ecid-gsm-MeasSupported", "lppe.ecid_gsm_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_gsm_ADSupported,
{ "ecid-gsm-ADSupported", "lppe.ecid_gsm_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses_04,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_04,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_GSM_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_08,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_08_vals), 0,
"T_cause_08", HFILL }},
{ &hf_lppe_mandatoryDataUnavailable,
{ "mandatoryDataUnavailable", "lppe.mandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_bsLocationsUnavailable,
{ "bsLocationsUnavailable", "lppe.bsLocationsUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellTransmitPowerUnavailable,
{ "cellTransmitPowerUnavailable", "lppe.cellTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_callAntennaGainUnavailable,
{ "callAntennaGainUnavailable", "lppe.callAntennaGainUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellBeamWidthUnavailable,
{ "cellBeamWidthUnavailable", "lppe.cellBeamWidthUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellTransmitDirectionUnavailable,
{ "cellTransmitDirectionUnavailable", "lppe.cellTransmitDirectionUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cellFrequencyAccuracyUnavailable,
{ "cellFrequencyAccuracyUnavailable", "lppe.cellFrequencyAccuracyUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nonservingADUnavailable,
{ "nonservingADUnavailable", "lppe.nonservingADUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cause_09,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_09_vals), 0,
"T_cause_09", HFILL }},
{ &hf_lppe_rxLevelMeasurementNotPossible,
{ "rxLevelMeasurementNotPossible", "lppe.rxLevelMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_taMeasurementNotPossible,
{ "taMeasurementNotPossible", "lppe.taMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRMeasurementNotPossible,
{ "nMRMeasurementNotPossible", "lppe.nMRMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_UTRA_NetworkData,
{ "ecid-UTRA-NetworkData", "lppe.ecid_UTRA_NetworkData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxUTRANetworks_OF_OMA_LPPe_ECID_UTRA_NetworkData", HFILL }},
{ &hf_lppe_ecid_UTRA_NetworkData_item,
{ "OMA-LPPe-ECID-UTRA-NetworkData", "lppe.OMA_LPPe_ECID_UTRA_NetworkData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_UTRA_Error,
{ "ecid-UTRA-Error", "lppe.ecid_UTRA_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_UTRA_Error_vals), 0,
"OMA_LPPe_ECID_UTRA_Error", HFILL }},
{ &hf_lppe_plmn_Identity_02,
{ "plmn-Identity", "lppe.plmn_Identity",
FT_NONE, BASE_NONE, NULL, 0,
"T_plmn_Identity_02", HFILL }},
{ &hf_lppe_mcc_02,
{ "mcc", "lppe.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mcc_02", HFILL }},
{ &hf_lppe_mnc_02,
{ "mnc", "lppe.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mnc_02", HFILL }},
{ &hf_lppe_ecid_utra_nodeB_list,
{ "ecid-utra-nodeB-list", "lppe.ecid_utra_nodeB_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxUTRAnodeBs_OF_OMA_LPPe_ECID_UTRA_NodeBData", HFILL }},
{ &hf_lppe_ecid_utra_nodeB_list_item,
{ "OMA-LPPe-ECID-UTRA-NodeBData", "lppe.OMA_LPPe_ECID_UTRA_NodeBData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_HNB_list,
{ "ecid-utra-HNB-list", "lppe.ecid_utra_HNB_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxUTRAHNBs_OF_OMA_LPPe_ECID_UTRA_HNBData", HFILL }},
{ &hf_lppe_ecid_utra_HNB_list_item,
{ "OMA-LPPe-ECID-UTRA-HNBData", "lppe.OMA_LPPe_ECID_UTRA_HNBData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_nodeB_CellData,
{ "ecid-utra-nodeB-CellData", "lppe.ecid_utra_nodeB_CellData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxUTRAMacroCells_OF_OMA_LPPe_ECID_UTRA_CellData", HFILL }},
{ &hf_lppe_ecid_utra_nodeB_CellData_item,
{ "OMA-LPPe-ECID-UTRA-CellData", "lppe.OMA_LPPe_ECID_UTRA_CellData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_HNB_CellData,
{ "ecid-utra-HNB-CellData", "lppe.ecid_utra_HNB_CellData",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_CellData", HFILL }},
{ &hf_lppe_cellIdentity_02,
{ "cellIdentity", "lppe.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_lppe_modeSpecificInfo_04,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_04_vals), 0,
"T_modeSpecificInfo_04", HFILL }},
{ &hf_lppe_fdd_05,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_05", HFILL }},
{ &hf_lppe_primaryCPICH_Scrambling_Code,
{ "primaryCPICH-Scrambling-Code", "lppe.primaryCPICH_Scrambling_Code",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryScramblingCode", HFILL }},
{ &hf_lppe_primaryCPICH_Tx_Power,
{ "primaryCPICH-Tx-Power", "lppe.primaryCPICH_Tx_Power",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_uarfcn_dl,
{ "uarfcn-dl", "lppe.uarfcn_dl",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_tdd_05,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_05", HFILL }},
{ &hf_lppe_primaryCCPCH_Tx_Power,
{ "primaryCCPCH-Tx-Power", "lppe.primaryCCPCH_Tx_Power",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_uarfcn_nt,
{ "uarfcn-nt", "lppe.uarfcn_nt",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_nBrequestedAD,
{ "nBrequestedAD", "lppe.nBrequestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBrequestedAD,
{ "hNBrequestedAD", "lppe.hNBrequestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_UTRA_CombinedLocationInformation,
{ "ecid-UTRA-CombinedLocationInformation", "lppe.ecid_UTRA_CombinedLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxECIDUTRASize_OF_OMA_LPPe_ECID_UTRA_LocationInformationList", HFILL }},
{ &hf_lppe_ecid_UTRA_CombinedLocationInformation_item,
{ "OMA-LPPe-ECID-UTRA-LocationInformationList", "lppe.OMA_LPPe_ECID_UTRA_LocationInformationList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_Error,
{ "ecid-Error", "lppe.ecid_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_UTRA_Error_vals), 0,
"OMA_LPPe_ECID_UTRA_Error", HFILL }},
{ &hf_lppe_ecid_utra_LocationInformation,
{ "ecid-utra-LocationInformation", "lppe.ecid_utra_LocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_LocationInformation", HFILL }},
{ &hf_lppe_cellGlobalIdUTRA,
{ "cellGlobalIdUTRA", "lppe.cellGlobalIdUTRA",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lppe_measuredResultsList,
{ "measuredResultsList", "lppe.measuredResultsList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_MeasuredResultsList", HFILL }},
{ &hf_lppe_utratimingAdvance,
{ "utratimingAdvance", "lppe.utratimingAdvance",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_UTRATimingAdvance", HFILL }},
{ &hf_lppe_tA_01,
{ "tA", "lppe.tA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_lppe_tAResolution,
{ "tAResolution", "lppe.tAResolution",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_UTRA_TAResolution_vals), 0,
"OMA_LPPe_ECID_UTRA_TAResolution", HFILL }},
{ &hf_lppe_chipRate,
{ "chipRate", "lppe.chipRate",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_UTRA_ChipRate_vals), 0,
"OMA_LPPe_ECID_UTRA_ChipRate", HFILL }},
{ &hf_lppe_modeSpecificInfo_05,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_UTRA_ModeSpecificInfo_vals), 0,
"OMA_LPPe_UTRA_ModeSpecificInfo", HFILL }},
{ &hf_lppe_fdd_06,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_UTRA_FrequencyInfoFDD", HFILL }},
{ &hf_lppe_tdd_06,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_UTRA_FrequencyInfoTDD", HFILL }},
{ &hf_lppe_uarfcn_UL,
{ "uarfcn-UL", "lppe.uarfcn_UL",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_uarfcn_DL,
{ "uarfcn-DL", "lppe.uarfcn_DL",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_uarfcn_Nt,
{ "uarfcn-Nt", "lppe.uarfcn_Nt",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lppe_OMA_LPPe_ECID_UTRA_MeasuredResultsList_item,
{ "OMA-LPPe-ECID-UTRA-MeasuredResults", "lppe.OMA_LPPe_ECID_UTRA_MeasuredResults",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_utra_CarrierRSSI,
{ "utra-CarrierRSSI", "lppe.utra_CarrierRSSI",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_CarrierRSSI", HFILL }},
{ &hf_lppe_cellMeasuredResultsList,
{ "cellMeasuredResultsList", "lppe.cellMeasuredResultsList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_CellMeasuredResultsList", HFILL }},
{ &hf_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResultsList_item,
{ "OMA-LPPe-ECID-UTRA-CellMeasuredResults", "lppe.OMA_LPPe_ECID_UTRA_CellMeasuredResults",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_modeSpecificInfo_06,
{ "modeSpecificInfo", "lppe.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(lppe_T_modeSpecificInfo_05_vals), 0,
"T_modeSpecificInfo_05", HFILL }},
{ &hf_lppe_fdd_07,
{ "fdd", "lppe.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_06", HFILL }},
{ &hf_lppe_primaryCPICH_Info,
{ "primaryCPICH-Info", "lppe.primaryCPICH_Info",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_OTDOA_UTRA_PrimaryScramblingCode", HFILL }},
{ &hf_lppe_cpich_Ec_N0,
{ "cpich-Ec-N0", "lppe.cpich_Ec_N0",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_CPICH_Ec_N0", HFILL }},
{ &hf_lppe_cpich_RSCP,
{ "cpich-RSCP", "lppe.cpich_RSCP",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_CPICH_RSCP", HFILL }},
{ &hf_lppe_pathloss,
{ "pathloss", "lppe.pathloss",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_Pathloss", HFILL }},
{ &hf_lppe_tdd_07,
{ "tdd", "lppe.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_06", HFILL }},
{ &hf_lppe_primaryCCPCH_RSCP,
{ "primaryCCPCH-RSCP", "lppe.primaryCCPCH_RSCP",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_UTRA_PrimaryCCPCH_RSCP", HFILL }},
{ &hf_lppe_requestedMeasurements_02,
{ "requestedMeasurements", "lppe.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedMeasurements_02", HFILL }},
{ &hf_lppe_ecid_utra_MeasSupported,
{ "ecid-utra-MeasSupported", "lppe.ecid_utra_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_nodeB_ADSupported,
{ "ecid-utra-nodeB-ADSupported", "lppe.ecid_utra_nodeB_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_utra_HNB_ADSupported,
{ "ecid-utra-HNB-ADSupported", "lppe.ecid_utra_HNB_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses_05,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_05,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_UTRA_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_10,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_10_vals), 0,
"T_cause_10", HFILL }},
{ &hf_lppe_nodeBMandatoryDataUnavailable,
{ "nodeBMandatoryDataUnavailable", "lppe.nodeBMandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBLocationUnavailable,
{ "nodeBLocationUnavailable", "lppe.nodeBLocationUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBcellTransmitPowerUnavailable,
{ "nodeBcellTransmitPowerUnavailable", "lppe.nodeBcellTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBcallAntennaGainUnavailable,
{ "nodeBcallAntennaGainUnavailable", "lppe.nodeBcallAntennaGainUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBcellBeamWidthUnavailable,
{ "nodeBcellBeamWidthUnavailable", "lppe.nodeBcellBeamWidthUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBcellTransmitDirectionUnavailable,
{ "nodeBcellTransmitDirectionUnavailable", "lppe.nodeBcellTransmitDirectionUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBcellFrequencyAccuracyUnavailable,
{ "nodeBcellFrequencyAccuracyUnavailable", "lppe.nodeBcellFrequencyAccuracyUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nodeBnonservingADUnavailable,
{ "nodeBnonservingADUnavailable", "lppe.nodeBnonservingADUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBMandatoryDataUnavailable,
{ "hNBMandatoryDataUnavailable", "lppe.hNBMandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBLocationUnavailable,
{ "hNBLocationUnavailable", "lppe.hNBLocationUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBLocationReliabilityUnavailable,
{ "hNBLocationReliabilityUnavailable", "lppe.hNBLocationReliabilityUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBcellTransmitPowerUnavailable,
{ "hNBcellTransmitPowerUnavailable", "lppe.hNBcellTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBcellFrequencyAccuracyUnavailable,
{ "hNBcellFrequencyAccuracyUnavailable", "lppe.hNBcellFrequencyAccuracyUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBCoverageAreaUnavailable,
{ "hNBCoverageAreaUnavailable", "lppe.hNBCoverageAreaUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_hNBnonservingADUnavailable,
{ "hNBnonservingADUnavailable", "lppe.hNBnonservingADUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cause_11,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_11_vals), 0,
"T_cause_11", HFILL }},
{ &hf_lppe_mRLMeasurementsNotPossible,
{ "mRLMeasurementsNotPossible", "lppe.mRLMeasurementsNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_tdd_timingAdvanceMeasurementNotPossible,
{ "tdd-timingAdvanceMeasurementNotPossible", "lppe.tdd_timingAdvanceMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_utra_CarrierRSSIMeasurementNotPossible,
{ "mRL-utra-CarrierRSSIMeasurementNotPossible", "lppe.mRL_utra_CarrierRSSIMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_FDD_cpich_Ec_N0MeasurementNotPossible,
{ "mRL-FDD-cpich-Ec-N0MeasurementNotPossible", "lppe.mRL_FDD_cpich_Ec_N0MeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_FDD_cpich_RSCPMeasurementNotPossible,
{ "mRL-FDD-cpich-RSCPMeasurementNotPossible", "lppe.mRL_FDD_cpich_RSCPMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_FDD_pathlossMeasurementNotPossible,
{ "mRL-FDD-pathlossMeasurementNotPossible", "lppe.mRL_FDD_pathlossMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_TDD_primaryCCPCH_RSCPMeasurementNotPossible,
{ "mRL-TDD-primaryCCPCH-RSCPMeasurementNotPossible", "lppe.mRL_TDD_primaryCCPCH_RSCPMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_mRL_TDD_pathlossMeasurementNotPossible,
{ "mRL-TDD-pathlossMeasurementNotPossible", "lppe.mRL_TDD_pathlossMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_DataSet,
{ "wlan-DataSet", "lppe.wlan_DataSet",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWLANDataSets_OF_OMA_LPPe_WLAN_DataSet", HFILL }},
{ &hf_lppe_wlan_DataSet_item,
{ "OMA-LPPe-WLAN-DataSet", "lppe.OMA_LPPe_WLAN_DataSet",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_AP_Error,
{ "wlan-AP-Error", "lppe.wlan_AP_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_WLAN_AP_Error_vals), 0,
"OMA_LPPe_WLAN_AP_Error", HFILL }},
{ &hf_lppe_plmn_Identity_03,
{ "plmn-Identity", "lppe.plmn_Identity",
FT_NONE, BASE_NONE, NULL, 0,
"T_plmn_Identity_03", HFILL }},
{ &hf_lppe_mcc_03,
{ "mcc", "lppe.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mcc_03", HFILL }},
{ &hf_lppe_mnc_03,
{ "mnc", "lppe.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mnc_03", HFILL }},
{ &hf_lppe_supported_channels_11a,
{ "supported-channels-11a", "lppe.supported_channels_11a",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_supported_channels_11bg,
{ "supported-channels-11bg", "lppe.supported_channels_11bg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_ap_list,
{ "wlan-ap-list", "lppe.wlan_ap_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWLANAPs_OF_OMA_LPPe_WLAN_AP_Data", HFILL }},
{ &hf_lppe_wlan_ap_list_item,
{ "OMA-LPPe-WLAN-AP-Data", "lppe.OMA_LPPe_WLAN_AP_Data",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ch34,
{ "ch34", "lppe.ch34",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch36,
{ "ch36", "lppe.ch36",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch38,
{ "ch38", "lppe.ch38",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch40,
{ "ch40", "lppe.ch40",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch42,
{ "ch42", "lppe.ch42",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch44,
{ "ch44", "lppe.ch44",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch46,
{ "ch46", "lppe.ch46",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch48,
{ "ch48", "lppe.ch48",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch52,
{ "ch52", "lppe.ch52",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch56,
{ "ch56", "lppe.ch56",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch60,
{ "ch60", "lppe.ch60",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch64,
{ "ch64", "lppe.ch64",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch149,
{ "ch149", "lppe.ch149",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch153,
{ "ch153", "lppe.ch153",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch157,
{ "ch157", "lppe.ch157",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch161,
{ "ch161", "lppe.ch161",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch1,
{ "ch1", "lppe.ch1",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch2,
{ "ch2", "lppe.ch2",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch3,
{ "ch3", "lppe.ch3",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch4,
{ "ch4", "lppe.ch4",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch5,
{ "ch5", "lppe.ch5",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch6,
{ "ch6", "lppe.ch6",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch7,
{ "ch7", "lppe.ch7",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch8,
{ "ch8", "lppe.ch8",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch9,
{ "ch9", "lppe.ch9",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch10,
{ "ch10", "lppe.ch10",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch11,
{ "ch11", "lppe.ch11",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch12,
{ "ch12", "lppe.ch12",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch13,
{ "ch13", "lppe.ch13",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_ch14,
{ "ch14", "lppe.ch14",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_wlan_ap_id,
{ "wlan-ap-id", "lppe.wlan_ap_id",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_ID", HFILL }},
{ &hf_lppe_wlan_ap_Type_Data,
{ "wlan-ap-Type-Data", "lppe.wlan_ap_Type_Data",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWLANTypes_OF_OMA_LPPe_WLAN_AP_Type_Data", HFILL }},
{ &hf_lppe_wlan_ap_Type_Data_item,
{ "OMA-LPPe-WLAN-AP-Type-Data", "lppe.OMA_LPPe_WLAN_AP_Type_Data",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_AP_Type,
{ "wlan-AP-Type", "lppe.wlan_AP_Type",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_WLAN_AP_Type_vals), 0,
"OMA_LPPe_WLAN_AP_Type", HFILL }},
{ &hf_lppe_requestedAD_01,
{ "requestedAD", "lppe.requestedAD",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedAD_01", HFILL }},
{ &hf_lppe_requestedAPTypes,
{ "requestedAPTypes", "lppe.requestedAPTypes",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_Type_List", HFILL }},
{ &hf_lppe_wlan_AP_CombinedLocationInformation,
{ "wlan-AP-CombinedLocationInformation", "lppe.wlan_AP_CombinedLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWLANAPSize_OF_OMA_LPPe_WLAN_AP_LocationInformationList", HFILL }},
{ &hf_lppe_wlan_AP_CombinedLocationInformation_item,
{ "OMA-LPPe-WLAN-AP-LocationInformationList", "lppe.OMA_LPPe_WLAN_AP_LocationInformationList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_AP_LocationInformation,
{ "wlan-AP-LocationInformation", "lppe.wlan_AP_LocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_LocationInformation", HFILL }},
{ &hf_lppe_apMACAddress,
{ "apMACAddress", "lppe.apMACAddress",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_ID", HFILL }},
{ &hf_lppe_apSSID,
{ "apSSID", "lppe.apSSID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_32", HFILL }},
{ &hf_lppe_apSignaltoNoise,
{ "apSignaltoNoise", "lppe.apSignaltoNoise",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_apDeviceType,
{ "apDeviceType", "lppe.apDeviceType",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_WLAN_AP_Type_vals), 0,
"OMA_LPPe_WLAN_AP_Type", HFILL }},
{ &hf_lppe_apPHYtype,
{ "apPHYtype", "lppe.apPHYtype",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_WLAN_AP_PHY_Type_vals), 0,
"OMA_LPPe_WLAN_AP_PHY_Type", HFILL }},
{ &hf_lppe_apSignalStrength,
{ "apSignalStrength", "lppe.apSignalStrength",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_apChannelFrequency,
{ "apChannelFrequency", "lppe.apChannelFrequency",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_256", HFILL }},
{ &hf_lppe_apRoundTripDelay,
{ "apRoundTripDelay", "lppe.apRoundTripDelay",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_RTD", HFILL }},
{ &hf_lppe_ueTransmitPower,
{ "ueTransmitPower", "lppe.ueTransmitPower",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_ueAntennaGain,
{ "ueAntennaGain", "lppe.ueAntennaGain",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lppe_apReportedLocation,
{ "apReportedLocation", "lppe.apReportedLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_ReportedLocation", HFILL }},
{ &hf_lppe_rTDValue,
{ "rTDValue", "lppe.rTDValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lppe_rTDUnits,
{ "rTDUnits", "lppe.rTDUnits",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_WLAN_RTDUnits_vals), 0,
"OMA_LPPe_WLAN_RTDUnits", HFILL }},
{ &hf_lppe_rTDAccuracy,
{ "rTDAccuracy", "lppe.rTDAccuracy",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_locationDataLCI,
{ "locationDataLCI", "lppe.locationDataLCI",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_LocationDataLCI", HFILL }},
{ &hf_lppe_latitudeResolution,
{ "latitudeResolution", "lppe.latitudeResolution",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_lppe_latitude_01,
{ "latitude", "lppe.latitude",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_34", HFILL }},
{ &hf_lppe_longitudeResolution,
{ "longitudeResolution", "lppe.longitudeResolution",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_lppe_longitude_01,
{ "longitude", "lppe.longitude",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_34", HFILL }},
{ &hf_lppe_altitudeType,
{ "altitudeType", "lppe.altitudeType",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_lppe_altitudeResolution,
{ "altitudeResolution", "lppe.altitudeResolution",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_lppe_altitude_01,
{ "altitude", "lppe.altitude",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_30", HFILL }},
{ &hf_lppe_datum,
{ "datum", "lppe.datum",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lppe_requestedMeasurements_03,
{ "requestedMeasurements", "lppe.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedMeasurements_03", HFILL }},
{ &hf_lppe_wlan_ecid_MeasSupported,
{ "wlan-ecid-MeasSupported", "lppe.wlan_ecid_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_wlan_types_Supported,
{ "wlan-types-Supported", "lppe.wlan_types_Supported",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_Type_List", HFILL }},
{ &hf_lppe_ap_Capability,
{ "ap-Capability", "lppe.ap_Capability",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_Capability", HFILL }},
{ &hf_lppe_wlan_ap_ADSupported,
{ "wlan-ap-ADSupported", "lppe.wlan_ap_ADSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apTypes,
{ "apTypes", "lppe.apTypes",
FT_BYTES, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_Type_List", HFILL }},
{ &hf_lppe_locationServerErrorCauses_06,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_06,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_AP_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_12,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_12_vals), 0,
"T_cause_12", HFILL }},
{ &hf_lppe_apMandatoryDataUnavailable,
{ "apMandatoryDataUnavailable", "lppe.apMandatoryDataUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apLocationsUnavailable,
{ "apLocationsUnavailable", "lppe.apLocationsUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apLocationReliabilityUnavailable,
{ "apLocationReliabilityUnavailable", "lppe.apLocationReliabilityUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apTransmitPowerUnavailable,
{ "apTransmitPowerUnavailable", "lppe.apTransmitPowerUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apAntennaGainUnavailable,
{ "apAntennaGainUnavailable", "lppe.apAntennaGainUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apCoverageAreaUnavailable,
{ "apCoverageAreaUnavailable", "lppe.apCoverageAreaUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_cause_13,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_13_vals), 0,
"T_cause_13", HFILL }},
{ &hf_lppe_apSSIDnotAvailable,
{ "apSSIDnotAvailable", "lppe.apSSIDnotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apSNMeasurementNotPossible,
{ "apSNMeasurementNotPossible", "lppe.apSNMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apDevTypeNotAvailable,
{ "apDevTypeNotAvailable", "lppe.apDevTypeNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apPhyTypeNotAvailable,
{ "apPhyTypeNotAvailable", "lppe.apPhyTypeNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apRSSIMeasurementNotPossible,
{ "apRSSIMeasurementNotPossible", "lppe.apRSSIMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apChanFreqNotAvailable,
{ "apChanFreqNotAvailable", "lppe.apChanFreqNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apRTDMeasurementNotPossible,
{ "apRTDMeasurementNotPossible", "lppe.apRTDMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ueTPNotAvailable,
{ "ueTPNotAvailable", "lppe.ueTPNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ueAGNotAvailable,
{ "ueAGNotAvailable", "lppe.ueAGNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_apRecLocNotAvailable,
{ "apRecLocNotAvailable", "lppe.apRecLocNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_wimax_CombinedLocationInformation,
{ "ecid-wimax-CombinedLocationInformation", "lppe.ecid_wimax_CombinedLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWiMaxECIDSize_OF_OMA_LPPe_ECID_WiMax_LocationInformationList", HFILL }},
{ &hf_lppe_ecid_wimax_CombinedLocationInformation_item,
{ "OMA-LPPe-ECID-WiMax-LocationInformationList", "lppe.OMA_LPPe_ECID_WiMax_LocationInformationList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_ecid_wimax_Error,
{ "ecid-wimax-Error", "lppe.ecid_wimax_Error",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_ECID_WiMax_Error_vals), 0,
"OMA_LPPe_ECID_WiMax_Error", HFILL }},
{ &hf_lppe_ecid_wimax_LocationInformation,
{ "ecid-wimax-LocationInformation", "lppe.ecid_wimax_LocationInformation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_LocationInformation", HFILL }},
{ &hf_lppe_wimaxBsID,
{ "wimaxBsID", "lppe.wimaxBsID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_WimaxBsID", HFILL }},
{ &hf_lppe_wimaxRTD,
{ "wimaxRTD", "lppe.wimaxRTD",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_WimaxRTD", HFILL }},
{ &hf_lppe_wimaxNMRList,
{ "wimaxNMRList", "lppe.wimaxNMRList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_ECID_WiMax_WimaxNMRList", HFILL }},
{ &hf_lppe_bsID_MSB,
{ "bsID-MSB", "lppe.bsID_MSB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_lppe_bsID_LSB,
{ "bsID-LSB", "lppe.bsID_LSB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_lppe_rTD,
{ "rTD", "lppe.rTD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_rTDstd,
{ "rTDstd", "lppe.rTDstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lppe_OMA_LPPe_ECID_WiMax_WimaxNMRList_item,
{ "OMA-LPPe-ECID-WiMax-WimaxNMR", "lppe.OMA_LPPe_ECID_WiMax_WimaxNMR",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relDelay,
{ "relDelay", "lppe.relDelay",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lppe_relDelaystd,
{ "relDelaystd", "lppe.relDelaystd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lppe_rSSI,
{ "rSSI", "lppe.rSSI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_rSSIstd,
{ "rSSIstd", "lppe.rSSIstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_bSTxPower,
{ "bSTxPower", "lppe.bSTxPower",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_cINR,
{ "cINR", "lppe.cINR",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lppe_cINRstd,
{ "cINRstd", "lppe.cINRstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lppe_bSLocation,
{ "bSLocation", "lppe.bSLocation",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_ReportedLocation", HFILL }},
{ &hf_lppe_requestedMeasurements_04,
{ "requestedMeasurements", "lppe.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedMeasurements_04", HFILL }},
{ &hf_lppe_ecid_wimax_MeasSupported,
{ "ecid-wimax-MeasSupported", "lppe.ecid_wimax_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_locationServerErrorCauses_07,
{ "locationServerErrorCauses", "lppe.locationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_targetDeviceErrorCauses_07,
{ "targetDeviceErrorCauses", "lppe.targetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ECID_WiMax_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_cause_14,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_14_vals), 0,
"T_cause_14", HFILL }},
{ &hf_lppe_cause_15,
{ "cause", "lppe.cause",
FT_UINT32, BASE_DEC, VALS(lppe_T_cause_15_vals), 0,
"T_cause_15", HFILL }},
{ &hf_lppe_rTDMeasurementNotPossible,
{ "rTDMeasurementNotPossible", "lppe.rTDMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rTDstdMeasurementNotPossible,
{ "rTDstdMeasurementNotPossible", "lppe.rTDstdMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRrelDelayMeasurementNotPossible,
{ "nMRrelDelayMeasurementNotPossible", "lppe.nMRrelDelayMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRrelDelaystdMeasurementNotPossible,
{ "nMRrelDelaystdMeasurementNotPossible", "lppe.nMRrelDelaystdMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRrSSIMeasurementNotPossible,
{ "nMRrSSIMeasurementNotPossible", "lppe.nMRrSSIMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRrSSIstdMeasurementNotPossible,
{ "nMRrSSIstdMeasurementNotPossible", "lppe.nMRrSSIstdMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRbSTxPowerMeasurementNotPossible,
{ "nMRbSTxPowerMeasurementNotPossible", "lppe.nMRbSTxPowerMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRcINRMeasurementNotPossible,
{ "nMRcINRMeasurementNotPossible", "lppe.nMRcINRMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRcINRstdMeasurementNotPossible,
{ "nMRcINRstdMeasurementNotPossible", "lppe.nMRcINRstdMeasurementNotPossible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_nMRbSLocationNotAvailable,
{ "nMRbSLocationNotAvailable", "lppe.nMRbSLocationNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_motionStateList,
{ "motionStateList", "lppe.motionStateList",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_Sensor_MotionStateList", HFILL }},
{ &hf_lppe_sensorError,
{ "sensorError", "lppe.sensorError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_Sensor_Error_vals), 0,
"OMA_LPPe_Sensor_Error", HFILL }},
{ &hf_lppe_OMA_LPPe_Sensor_MotionStateList_item,
{ "OMA-LPPe-Sensor-MotionStateElement", "lppe.OMA_LPPe_Sensor_MotionStateElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_primaryMotionState,
{ "primaryMotionState", "lppe.primaryMotionState",
FT_UINT32, BASE_DEC, VALS(lppe_T_primaryMotionState_vals), 0,
NULL, HFILL }},
{ &hf_lppe_secondaryMotionState,
{ "secondaryMotionState", "lppe.secondaryMotionState",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_motionStateReq,
{ "motionStateReq", "lppe.motionStateReq",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_MotionStateRequest", HFILL }},
{ &hf_lppe_secondaryMotionStateRequest,
{ "secondaryMotionStateRequest", "lppe.secondaryMotionStateRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_motionStateSupport,
{ "motionStateSupport", "lppe.motionStateSupport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_secondarySupport,
{ "secondarySupport", "lppe.secondarySupport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_targetError,
{ "targetError", "lppe.targetError",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_Sensor_TargetError", HFILL }},
{ &hf_lppe_motionStateError,
{ "motionStateError", "lppe.motionStateError",
FT_UINT32, BASE_DEC, VALS(lppe_T_motionStateError_vals), 0,
NULL, HFILL }},
{ &hf_lppe_secondaryMotionStateError,
{ "secondaryMotionStateError", "lppe.secondaryMotionStateError",
FT_UINT32, BASE_DEC, VALS(lppe_T_secondaryMotionStateError_vals), 0,
NULL, HFILL }},
{ &hf_lppe_srnGroup,
{ "srnGroup", "lppe.srnGroup",
FT_UINT32, BASE_DEC, VALS(lppe_T_srnGroup_vals), 0,
NULL, HFILL }},
{ &hf_lppe_srnGroupList,
{ "srnGroupList", "lppe.srnGroupList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNgroupList", HFILL }},
{ &hf_lppe_srnGroupUpdateResponse,
{ "srnGroupUpdateResponse", "lppe.srnGroupUpdateResponse",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_SRN_SRNgroupUpdateResponse", HFILL }},
{ &hf_lppe_antennaPattern,
{ "antennaPattern", "lppe.antennaPattern",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_SRN_AntennaPattern", HFILL }},
{ &hf_lppe_srnError,
{ "srnError", "lppe.srnError",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_SRN_Error_vals), 0,
"OMA_LPPe_SRN_Error", HFILL }},
{ &hf_lppe_incompleteFlag,
{ "incompleteFlag", "lppe.incompleteFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppe_defaultReferencePoint,
{ "defaultReferencePoint", "lppe.defaultReferencePoint",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePoint", HFILL }},
{ &hf_lppe_groupList,
{ "groupList", "lppe.groupList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_SRNgroup", HFILL }},
{ &hf_lppe_groupList_item,
{ "OMA-LPPe-SRN-SRNgroup", "lppe.OMA_LPPe_SRN_SRNgroup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnGroupID,
{ "srnGroupID", "lppe.srnGroupID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNgroupUniqueID", HFILL }},
{ &hf_lppe_defaultSRNtype,
{ "defaultSRNtype", "lppe.defaultSRNtype",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNtype", HFILL }},
{ &hf_lppe_referencePoint_01,
{ "referencePoint", "lppe.referencePoint",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ReferencePoint", HFILL }},
{ &hf_lppe_globalOrientation,
{ "globalOrientation", "lppe.globalOrientation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnsInGroupList,
{ "srnsInGroupList", "lppe.srnsInGroupList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNinfo", HFILL }},
{ &hf_lppe_srnsInGroupList_item,
{ "OMA-LPPe-SRN-SRNinfo", "lppe.OMA_LPPe_SRN_SRNinfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnID,
{ "srnID", "lppe.srnID",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNid", HFILL }},
{ &hf_lppe_srnType,
{ "srnType", "lppe.srnType",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNtype", HFILL }},
{ &hf_lppe_relativePosition,
{ "relativePosition", "lppe.relativePosition",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_RelativeLocation", HFILL }},
{ &hf_lppe_orientation,
{ "orientation", "lppe.orientation",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_Orientation_vals), 0,
"OMA_LPPe_Orientation", HFILL }},
{ &hf_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponse_item,
{ "OMA-LPPe-SRN-SRNgroupUpdateResponseElement", "lppe.OMA_LPPe_SRN_SRNgroupUpdateResponseElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_targetDataValidity,
{ "targetDataValidity", "lppe.targetDataValidity",
FT_UINT32, BASE_DEC, VALS(lppe_T_targetDataValidity_vals), 0,
NULL, HFILL }},
{ &hf_lppe_updatedSRNgroup,
{ "updatedSRNgroup", "lppe.updatedSRNgroup",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNgroup", HFILL }},
{ &hf_lppe_OMA_LPPe_SRN_AntennaPattern_item,
{ "OMA-LPPe-SRN-AntennaPatternElement", "lppe.OMA_LPPe_SRN_AntennaPatternElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_identification,
{ "identification", "lppe.identification",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_vendorOrOperator,
{ "vendorOrOperator", "lppe.vendorOrOperator",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_antennaPatternID,
{ "antennaPatternID", "lppe.antennaPatternID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_antennaData,
{ "antennaData", "lppe.antennaData",
FT_UINT32, BASE_DEC, VALS(lppe_T_antennaData_vals), 0,
NULL, HFILL }},
{ &hf_lppe_antennaPattern_01,
{ "antennaPattern", "lppe.antennaPattern",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_AntennaPatternForChannels", HFILL }},
{ &hf_lppe_antennaContainer,
{ "antennaContainer", "lppe.antennaContainer",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_evenGrid,
{ "evenGrid", "lppe.evenGrid",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_inAzimuth,
{ "inAzimuth", "lppe.inAzimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_200", HFILL }},
{ &hf_lppe_inElevation,
{ "inElevation", "lppe.inElevation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_150", HFILL }},
{ &hf_lppe_patternList,
{ "patternList", "lppe.patternList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxChannels_OF_OMA_LPPe_SRN_ChannelResponse", HFILL }},
{ &hf_lppe_patternList_item,
{ "OMA-LPPe-SRN-ChannelResponse", "lppe.OMA_LPPe_SRN_ChannelResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_channelNumber,
{ "channelNumber", "lppe.channelNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_maxChannels", HFILL }},
{ &hf_lppe_responseInElevation,
{ "responseInElevation", "lppe.responseInElevation",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_7_901_OF_OMA_LPPe_SRN_ResponseInElevation", HFILL }},
{ &hf_lppe_responseInElevation_item,
{ "OMA-LPPe-SRN-ResponseInElevation", "lppe.OMA_LPPe_SRN_ResponseInElevation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_elevation_01,
{ "elevation", "lppe.elevation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_900", HFILL }},
{ &hf_lppe_responseInAzimuth,
{ "responseInAzimuth", "lppe.responseInAzimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_18_3601_OF_OMA_LPPe_SRN_ResponseInAzimuth", HFILL }},
{ &hf_lppe_responseInAzimuth_item,
{ "OMA-LPPe-SRN-ResponseInAzimuth", "lppe.OMA_LPPe_SRN_ResponseInAzimuth",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_azimuth_01,
{ "azimuth", "lppe.azimuth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lppe_response,
{ "response", "lppe.response",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_ComplexNumber", HFILL }},
{ &hf_lppe_amplitude,
{ "amplitude", "lppe.amplitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_phase,
{ "phase", "lppe.phase",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M1800_1799", HFILL }},
{ &hf_lppe_srnGroup_01,
{ "srnGroup", "lppe.srnGroup",
FT_UINT32, BASE_DEC, VALS(lppe_T_srnGroup_01_vals), 0,
"T_srnGroup_01", HFILL }},
{ &hf_lppe_srnGroupRequest,
{ "srnGroupRequest", "lppe.srnGroupRequest",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNgroupRequest", HFILL }},
{ &hf_lppe_srnGroupUpdateRequest,
{ "srnGroupUpdateRequest", "lppe.srnGroupUpdateRequest",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_SRN_SRNgroupUpdateRequest", HFILL }},
{ &hf_lppe_antennaPatternRequest,
{ "antennaPatternRequest", "lppe.antennaPatternRequest",
FT_UINT32, BASE_DEC, NULL, 0,
"OMA_LPPe_SRN_AntennaPatternRequest", HFILL }},
{ &hf_lppe_doNotProvideList,
{ "doNotProvideList", "lppe.doNotProvideList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNProvideList", HFILL }},
{ &hf_lppe_doProvideList,
{ "doProvideList", "lppe.doProvideList",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_SRNProvideList", HFILL }},
{ &hf_lppe_groupList_01,
{ "groupList", "lppe.groupList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_256_OF_OMA_LPPe_SRN_SRNgroupUniqueID", HFILL }},
{ &hf_lppe_groupList_item_01,
{ "OMA-LPPe-SRN-SRNgroupUniqueID", "lppe.OMA_LPPe_SRN_SRNgroupUniqueID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_categoryList,
{ "categoryList", "lppe.categoryList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category", HFILL }},
{ &hf_lppe_categoryList_item,
{ "OMA-LPPe-SRN-Category", "lppe.OMA_LPPe_SRN_Category",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequest_item,
{ "OMA-LPPe-SRN-SRNgroupUpdateRequestElement", "lppe.OMA_LPPe_SRN_SRNgroupUpdateRequestElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_provideIndicationOnly,
{ "provideIndicationOnly", "lppe.provideIndicationOnly",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_inTheGroup,
{ "inTheGroup", "lppe.inTheGroup",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNid", HFILL }},
{ &hf_lppe_inTheGroup_item,
{ "OMA-LPPe-SRN-SRNid", "lppe.OMA_LPPe_SRN_SRNid",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_SRN_AntennaPatternRequest_item,
{ "OMA-LPPe-SRN-AntennaPatternRequestElement", "lppe.OMA_LPPe_SRN_AntennaPatternRequestElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_antennaPatternID_01,
{ "antennaPatternID", "lppe.antennaPatternID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnMeasurementList,
{ "srnMeasurementList", "lppe.srnMeasurementList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_MeasurementElement", HFILL }},
{ &hf_lppe_srnMeasurementList_item,
{ "OMA-LPPe-SRN-MeasurementElement", "lppe.OMA_LPPe_SRN_MeasurementElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnCategory,
{ "srnCategory", "lppe.srnCategory",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_Category", HFILL }},
{ &hf_lppe_measurementList,
{ "measurementList", "lppe.measurementList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_srnMeasurementElement", HFILL }},
{ &hf_lppe_measurementList_item,
{ "OMA-LPPe-SRN-srnMeasurementElement", "lppe.OMA_LPPe_SRN_srnMeasurementElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_relativeTimeStamp_01,
{ "relativeTimeStamp", "lppe.relativeTimeStamp",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1000", HFILL }},
{ &hf_lppe_rssi,
{ "rssi", "lppe.rssi",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lppe_rtd,
{ "rtd", "lppe.rtd",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_WLAN_RTD", HFILL }},
{ &hf_lppe_requestInfo,
{ "requestInfo", "lppe.requestInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ReqLocInfo_Category", HFILL }},
{ &hf_lppe_requestInfo_item,
{ "OMA-LPPe-SRN-ReqLocInfo-Category", "lppe.OMA_LPPe_SRN_ReqLocInfo_Category",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_category,
{ "category", "lppe.category",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_Category", HFILL }},
{ &hf_lppe_multipleMeasurements,
{ "multipleMeasurements", "lppe.multipleMeasurements",
FT_UINT32, BASE_DEC, VALS(lppe_T_multipleMeasurements_vals), 0,
NULL, HFILL }},
{ &hf_lppe_allowedMeasurements,
{ "allowedMeasurements", "lppe.allowedMeasurements",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_MeasurementMask", HFILL }},
{ &hf_lppe_historicMeasurementsRequested,
{ "historicMeasurementsRequested", "lppe.historicMeasurementsRequested",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_capabilitiesPerSRNCategory,
{ "capabilitiesPerSRNCategory", "lppe.capabilitiesPerSRNCategory",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ProvideCapabilitiesElement", HFILL }},
{ &hf_lppe_capabilitiesPerSRNCategory_item,
{ "OMA-LPPe-SRN-ProvideCapabilitiesElement", "lppe.OMA_LPPe_SRN_ProvideCapabilitiesElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_supportedMeasurements,
{ "supportedMeasurements", "lppe.supportedMeasurements",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_MeasurementMask", HFILL }},
{ &hf_lppe_supportedAssistanceData,
{ "supportedAssistanceData", "lppe.supportedAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_historicMeasurementsSupported,
{ "historicMeasurementsSupported", "lppe.historicMeasurementsSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_capabilitiesRequestedFor,
{ "capabilitiesRequestedFor", "lppe.capabilitiesRequestedFor",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category", HFILL }},
{ &hf_lppe_capabilitiesRequestedFor_item,
{ "OMA-LPPe-SRN-Category", "lppe.OMA_LPPe_SRN_Category",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnLocationServerErrorCauses,
{ "srnLocationServerErrorCauses", "lppe.srnLocationServerErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_LocationServerErrorCauses", HFILL }},
{ &hf_lppe_srnTargetDeviceErrorCauses,
{ "srnTargetDeviceErrorCauses", "lppe.srnTargetDeviceErrorCauses",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_TargetDeviceErrorCauses", HFILL }},
{ &hf_lppe_groupErrors,
{ "groupErrors", "lppe.groupErrors",
FT_UINT32, BASE_DEC, VALS(lppe_T_groupErrors_vals), 0,
NULL, HFILL }},
{ &hf_lppe_groupUpdateErrors,
{ "groupUpdateErrors", "lppe.groupUpdateErrors",
FT_UINT32, BASE_DEC, VALS(lppe_T_groupUpdateErrors_vals), 0,
NULL, HFILL }},
{ &hf_lppe_srnAntennaErrors,
{ "srnAntennaErrors", "lppe.srnAntennaErrors",
FT_UINT32, BASE_DEC, VALS(lppe_T_srnAntennaErrors_vals), 0,
NULL, HFILL }},
{ &hf_lppe_srnErrorsPerCategory,
{ "srnErrorsPerCategory", "lppe.srnErrorsPerCategory",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_TargetDeviceError", HFILL }},
{ &hf_lppe_srnErrorsPerCategory_item,
{ "OMA-LPPe-SRN-TargetDeviceError", "lppe.OMA_LPPe_SRN_TargetDeviceError",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnErrors,
{ "srnErrors", "lppe.srnErrors",
FT_UINT32, BASE_DEC, VALS(lppe_T_srnErrors_vals), 0,
NULL, HFILL }},
{ &hf_lppe_rssiNotAvailable,
{ "rssiNotAvailable", "lppe.rssiNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_rtdNotAvailable,
{ "rtdNotAvailable", "lppe.rtdNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_multipleSetsNotAvailable,
{ "multipleSetsNotAvailable", "lppe.multipleSetsNotAvailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_srnDataVersion,
{ "srnDataVersion", "lppe.srnDataVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lppe_srnERP,
{ "srnERP", "lppe.srnERP",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M300_500", HFILL }},
{ &hf_lppe_srnAntennaInfo,
{ "srnAntennaInfo", "lppe.srnAntennaInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_switchingPatternID,
{ "switchingPatternID", "lppe.switchingPatternID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lppe_srnTechnologyType,
{ "srnTechnologyType", "lppe.srnTechnologyType",
FT_NONE, BASE_NONE, NULL, 0,
"OMA_LPPe_SRN_Technologies", HFILL }},
{ &hf_lppe_srnVendorInformation,
{ "srnVendorInformation", "lppe.srnVendorInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_vendor,
{ "vendor", "lppe.vendor",
FT_UINT32, BASE_DEC, VALS(lppe_OMA_LPPe_VendorOrOperatorID_vals), 0,
"OMA_LPPe_VendorOrOperatorID", HFILL }},
{ &hf_lppe_vendorInfo,
{ "vendorInfo", "lppe.vendorInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_srn_id,
{ "srn-id", "lppe.srn_id",
FT_UINT32, BASE_DEC, VALS(lppe_T_srn_id_vals), 0,
NULL, HFILL }},
{ &hf_lppe_mac,
{ "mac", "lppe.mac",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_lppe_nfc,
{ "nfc", "lppe.nfc",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_manufacturer,
{ "manufacturer", "lppe.manufacturer",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lppe_uniqueNumber,
{ "uniqueNumber", "lppe.uniqueNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_lppe_mobileCode,
{ "mobileCode", "lppe.mobileCode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_registryID,
{ "registryID", "lppe.registryID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_12", HFILL }},
{ &hf_lppe_remainingPart,
{ "remainingPart", "lppe.remainingPart",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_1", HFILL }},
{ &hf_lppe_resolutionIdentifier,
{ "resolutionIdentifier", "lppe.resolutionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_18", HFILL }},
{ &hf_lppe_other,
{ "other", "lppe.other",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_lppe_srnTechnologies,
{ "srnTechnologies", "lppe.srnTechnologies",
FT_UINT32, BASE_DEC, VALS(lppe_T_srnTechnologies_vals), 0,
NULL, HFILL }},
{ &hf_lppe_srnMeasurements,
{ "srnMeasurements", "lppe.srnMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_FixedAccessTypes_cable,
{ "cable", "lppe.cable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_FixedAccessTypes_dsl,
{ "dsl", "lppe.dsl",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_FixedAccessTypes_lan,
{ "lan", "lppe.lan",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_FixedAccessTypes_pstn,
{ "pstn", "lppe.pstn",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_FixedAccessTypes_other,
{ "other", "lppe.other",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_gsm,
{ "gsm", "lppe.gsm",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_utra,
{ "utra", "lppe.utra",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_lte,
{ "lte", "lppe.lte",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_wimax,
{ "wimax", "lppe.wimax",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_wifi,
{ "wifi", "lppe.wifi",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WirelessAccessTypes_other,
{ "other", "lppe.other",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WLAN_AP_Type_List_ieee802_11a,
{ "ieee802-11a", "lppe.ieee802-11a",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WLAN_AP_Type_List_ieee802_11b,
{ "ieee802-11b", "lppe.ieee802-11b",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WLAN_AP_Type_List_ieee802_11g,
{ "ieee802-11g", "lppe.ieee802-11g",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_WLAN_AP_Type_List_ieee802_11n,
{ "ieee802-11n", "lppe.ieee802-11n",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_iP_Address_support_iPv4,
{ "iPv4", "lppe.iPv4",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_iP_Address_support_iPv6,
{ "iPv6", "lppe.iPv6",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_iP_Address_support_nat,
{ "nat", "lppe.nat",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_HighAccuracyFormatCapabilities_hAposition,
{ "hAposition", "lppe.hAposition",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_OMA_LPPe_HighAccuracyFormatCapabilities_hAvelocity,
{ "hAvelocity", "lppe.hAvelocity",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_relativeLocationReportingSupport_geo,
{ "geo", "lppe.geo",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_relativeLocationReportingSupport_civic,
{ "civic", "lppe.civic",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_relativeLocationReportingSupport_otherProviders,
{ "otherProviders", "lppe.otherProviders",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ionoreq_klobucharModel,
{ "klobucharModel", "lppe.klobucharModel",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ionoreq_ionoStormWarning,
{ "ionoStormWarning", "lppe.ionoStormWarning",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_troposphereModelReq_delay,
{ "delay", "lppe.delay",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_troposphereModelReq_surface,
{ "surface", "lppe.surface",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ionosphereMeasurementsReq_tecPerSV,
{ "tecPerSV", "lppe.tecPerSV",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ionosphereMeasurementsReq_zenithTEC,
{ "zenithTEC", "lppe.zenithTEC",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ionosphereMeasurementSupport_tecPerSVsupport,
{ "tecPerSVsupport", "lppe.tecPerSVsupport",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ionosphereMeasurementSupport_zenithTecSupport,
{ "zenithTecSupport", "lppe.zenithTecSupport",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ionoModel_localKlobuchar,
{ "localKlobuchar", "lppe.localKlobuchar",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ionoModel_ionoStormWarning,
{ "ionoStormWarning", "lppe.ionoStormWarning",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ionoModel_wideAreaIonoSurface,
{ "wideAreaIonoSurface", "lppe.wideAreaIonoSurface",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_tropoModel_localTroposphereDelay,
{ "localTroposphereDelay", "lppe.localTroposphereDelay",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_tropoModel_surfaceParameters,
{ "surfaceParameters", "lppe.surfaceParameters",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_modeSupport_ueBased,
{ "ueBased", "lppe.ueBased",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_modeSupport_ueAssisted,
{ "ueAssisted", "lppe.ueAssisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_haGNSSantennaInformationSupport_antennaDescriptionSupported,
{ "antennaDescriptionSupported", "lppe.antennaDescriptionSupported",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_haGNSSantennaInformationSupport_antennaOrientationSupported,
{ "antennaOrientationSupported", "lppe.antennaOrientationSupported",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedCells_eNBs,
{ "eNBs", "lppe.eNBs",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedCells_heNBs,
{ "heNBs", "lppe.heNBs",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_eotdAssistanceReq_ueAssisted,
{ "ueAssisted", "lppe.ueAssisted",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_eotdAssistanceReq_ueBased,
{ "ueBased", "lppe.ueBased",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_eotdSupport_ueBased,
{ "ueBased", "lppe.ueBased",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_eotdSupport_ueAssisted,
{ "ueAssisted", "lppe.ueAssisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_otdoaUtraAssistanceReq_ueAssisted,
{ "ueAssisted", "lppe.ueAssisted",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_otdoaUtraAssistanceReq_ueBased,
{ "ueBased", "lppe.ueBased",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_antennaPortConfig,
{ "antennaPortConfig", "lppe.antennaPortConfig",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_eNBrequestedAD_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_antennaPortConfig,
{ "antennaPortConfig", "lppe.antennaPortConfig",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_heNBrequestedAD_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_rsrp,
{ "rsrp", "lppe.rsrp",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_rsrq,
{ "rsrq", "lppe.rsrq",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_ueRxTx,
{ "ueRxTx", "lppe.ueRxTx",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_MeasSupported_rsrp,
{ "rsrp", "lppe.rsrp",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_MeasSupported_rsrq,
{ "rsrq", "lppe.rsrq",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_MeasSupported_ueRxTx,
{ "ueRxTx", "lppe.ueRxTx",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_MeasSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_MeasSupported_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_antennaPortConfig,
{ "antennaPortConfig", "lppe.antennaPortConfig",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_ecid_lte_eNodeB_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_antennaPortConfig,
{ "antennaPortConfig", "lppe.antennaPortConfig",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HeNB_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_01_rxLevel,
{ "rxLevel", "lppe.rxLevel",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_01_tA,
{ "tA", "lppe.tA",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_01_nMR_GERAN,
{ "nMR-GERAN", "lppe.nMR-GERAN",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_01_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_01_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_MeasSupported_rxLevel,
{ "rxLevel", "lppe.rxLevel",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_MeasSupported_tA,
{ "tA", "lppe.tA",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_MeasSupported_nMR_GERAN,
{ "nMR-GERAN", "lppe.nMR-GERAN",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_MeasSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_MeasSupported_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_gsm_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_nBrequestedAD_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_hNBrequestedAD_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_measuredResultsList,
{ "measuredResultsList", "lppe.measuredResultsList",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_tdd_timingAdvance,
{ "tdd-timingAdvance", "lppe.tdd-timingAdvance",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_utra_CarrierRSSI,
{ "mRL-utra-CarrierRSSI", "lppe.mRL-utra-CarrierRSSI",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_FDD_cpich_Ec_N0,
{ "mRL-FDD-cpich-Ec-N0", "lppe.mRL-FDD-cpich-Ec-N0",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_FDD_cpich_RSCP,
{ "mRL-FDD-cpich-RSCP", "lppe.mRL-FDD-cpich-RSCP",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_FDD_pathloss,
{ "mRL-FDD-pathloss", "lppe.mRL-FDD-pathloss",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_TDD_primaryCCPCH_RSCP,
{ "mRL-TDD-primaryCCPCH-RSCP", "lppe.mRL-TDD-primaryCCPCH-RSCP",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_mRL_TDD_pathloss,
{ "mRL-TDD-pathloss", "lppe.mRL-TDD-pathloss",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_02_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_measuredResultsList,
{ "measuredResultsList", "lppe.measuredResultsList",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_tdd_timingAdvance,
{ "tdd-timingAdvance", "lppe.tdd-timingAdvance",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_utra_CarrierRSSI,
{ "mRL-utra-CarrierRSSI", "lppe.mRL-utra-CarrierRSSI",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_FDD_cpich_Ec_N0,
{ "mRL-FDD-cpich-Ec-N0", "lppe.mRL-FDD-cpich-Ec-N0",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_FDD_cpich_RSCP,
{ "mRL-FDD-cpich-RSCP", "lppe.mRL-FDD-cpich-RSCP",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_FDD_pathloss,
{ "mRL-FDD-pathloss", "lppe.mRL-FDD-pathloss",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_TDD_primaryCCPCH_RSCP,
{ "mRL-TDD-primaryCCPCH-RSCP", "lppe.mRL-TDD-primaryCCPCH-RSCP",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_mRL_TDD_pathloss,
{ "mRL-TDD-pathloss", "lppe.mRL-TDD-pathloss",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_MeasSupported_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_beam_width,
{ "beam-width", "lppe.beam-width",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_transmit_direction,
{ "transmit-direction", "lppe.transmit-direction",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_nodeB_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_bslist,
{ "bslist", "lppe.bslist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_bslocation,
{ "bslocation", "lppe.bslocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_frequency_accuracy,
{ "frequency-accuracy", "lppe.frequency-accuracy",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_utra_HNB_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_aplist,
{ "aplist", "lppe.aplist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_aplocation,
{ "aplocation", "lppe.aplocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_requestedAD_01_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apSSID,
{ "apSSID", "lppe.apSSID",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apSN,
{ "apSN", "lppe.apSN",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apDevType,
{ "apDevType", "lppe.apDevType",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apPhyType,
{ "apPhyType", "lppe.apPhyType",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apRSSI,
{ "apRSSI", "lppe.apRSSI",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apChanFreq,
{ "apChanFreq", "lppe.apChanFreq",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apRTD,
{ "apRTD", "lppe.apRTD",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_ueTP,
{ "ueTP", "lppe.ueTP",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_ueAG,
{ "ueAG", "lppe.ueAG",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_apRepLoc,
{ "apRepLoc", "lppe.apRepLoc",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_03_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apSSID,
{ "apSSID", "lppe.apSSID",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apSN,
{ "apSN", "lppe.apSN",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apDevType,
{ "apDevType", "lppe.apDevType",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apPhyType,
{ "apPhyType", "lppe.apPhyType",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apRSSI,
{ "apRSSI", "lppe.apRSSI",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apChanFreq,
{ "apChanFreq", "lppe.apChanFreq",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apRTD,
{ "apRTD", "lppe.apRTD",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_ueTP,
{ "ueTP", "lppe.ueTP",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_ueAG,
{ "ueAG", "lppe.ueAG",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_apRepLoc,
{ "apRepLoc", "lppe.apRepLoc",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ecid_MeasSupported_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_aplist,
{ "aplist", "lppe.aplist",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_aplocation,
{ "aplocation", "lppe.aplocation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_locationreliability,
{ "locationreliability", "lppe.locationreliability",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_transmit_power,
{ "transmit-power", "lppe.transmit-power",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_antenna_gain,
{ "antenna-gain", "lppe.antenna-gain",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_coveragearea,
{ "coveragearea", "lppe.coveragearea",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_wlan_ap_ADSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_rTD,
{ "rTD", "lppe.rTD",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_rTDstd,
{ "rTDstd", "lppe.rTDstd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMR,
{ "nMR", "lppe.nMR",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRrelDelay,
{ "nMRrelDelay", "lppe.nMRrelDelay",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRrelDelaystd,
{ "nMRrelDelaystd", "lppe.nMRrelDelaystd",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRrSSI,
{ "nMRrSSI", "lppe.nMRrSSI",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRrSSIstd,
{ "nMRrSSIstd", "lppe.nMRrSSIstd",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRbSTxPower,
{ "nMRbSTxPower", "lppe.nMRbSTxPower",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRcINR,
{ "nMRcINR", "lppe.nMRcINR",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRcINRstd,
{ "nMRcINRstd", "lppe.nMRcINRstd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_nMRbSLocation,
{ "nMRbSLocation", "lppe.nMRbSLocation",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_requestedMeasurements_04_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_rTD,
{ "rTD", "lppe.rTD",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_rTDstd,
{ "rTDstd", "lppe.rTDstd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMR,
{ "nMR", "lppe.nMR",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRrelDelay,
{ "nMRrelDelay", "lppe.nMRrelDelay",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRrelDelaystd,
{ "nMRrelDelaystd", "lppe.nMRrelDelaystd",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRrSSI,
{ "nMRrSSI", "lppe.nMRrSSI",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRrSSIstd,
{ "nMRrSSIstd", "lppe.nMRrSSIstd",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRbSTxPower,
{ "nMRbSTxPower", "lppe.nMRbSTxPower",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRcINR,
{ "nMRcINR", "lppe.nMRcINR",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRcINRstd,
{ "nMRcINRstd", "lppe.nMRcINRstd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_nMRbSLocation,
{ "nMRbSLocation", "lppe.nMRbSLocation",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_non_serving,
{ "non-serving", "lppe.non-serving",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_ecid_wimax_MeasSupported_historic,
{ "historic", "lppe.historic",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_stationary,
{ "stationary", "lppe.stationary",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_pedestrian,
{ "pedestrian", "lppe.pedestrian",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_running,
{ "running", "lppe.running",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_cycling,
{ "cycling", "lppe.cycling",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_car,
{ "car", "lppe.car",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_train,
{ "train", "lppe.train",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_aeroplane,
{ "aeroplane", "lppe.aeroplane",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_boat,
{ "boat", "lppe.boat",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_lppe_T_secondaryMotionState_fidgeting,
{ "fidgeting", "lppe.fidgeting",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_supportedAssistanceData_srnGroup,
{ "srnGroup", "lppe.srnGroup",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_supportedAssistanceData_antennaPattern,
{ "antennaPattern", "lppe.antennaPattern",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lppe_T_srnMeasurements_rssi,
{ "rssi", "lppe.rssi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lppe_T_srnMeasurements_rtd,
{ "rtd", "lppe.rtd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 69 "../../asn1/lppe/packet-lppe-template.c"
};
static gint *ett[] = {
&ett_lppe,
#line 1 "../../asn1/lppe/packet-lppe-ettarr.c"
&ett_lppe_OMA_LPPe_MessageExtension,
&ett_lppe_OMA_LPPe_LPPeVersion,
&ett_lppe_OMA_LPPe_MessageExtensionBody,
&ett_lppe_OMA_LPPe_RequestCapabilities,
&ett_lppe_OMA_LPPe_ProvideCapabilities,
&ett_lppe_OMA_LPPe_RequestAssistanceData,
&ett_lppe_OMA_LPPe_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_RequestLocationInformation,
&ett_lppe_OMA_LPPe_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_Abort,
&ett_lppe_OMA_LPPe_Error,
&ett_lppe_OMA_LPPe_AssistanceContainer_DataSerialNumber,
&ett_lppe_OMA_LPPe_AssistanceContainerID,
&ett_lppe_OMA_LPPe_AssistanceContainerProvideList,
&ett_lppe_OMA_LPPe_AssistanceContainerProvide,
&ett_lppe_T_dataResult,
&ett_lppe_OMA_LPPe_AssistanceContainerData,
&ett_lppe_OMA_LPPe_AssistanceContainerProvideError,
&ett_lppe_OMA_LPPe_AssistanceContainerRequestList,
&ett_lppe_OMA_LPPe_AssistanceContainerRequest,
&ett_lppe_OMA_LPPe_AssistanceContainerCheckOrUpdateReq,
&ett_lppe_OMA_LPPe_CellLocalIdGERAN,
&ett_lppe_OMA_LPPe_CellNonUniqueIDGERAN,
&ett_lppe_OMA_LPPe_CivicLocation,
&ett_lppe_OMA_LPPe_CivicAddressElementList,
&ett_lppe_OMA_LPPe_CivicAddressElement,
&ett_lppe_OMA_LPPe_Duration,
&ett_lppe_OMA_LPPe_FixedAccessTypes,
&ett_lppe_OMA_LPPe_HighAccuracy3Dposition,
&ett_lppe_OMA_LPPe_HighAccuracy3Dvelocity,
&ett_lppe_OMA_LPPe_LocationInformationContainerID,
&ett_lppe_OMA_LPPe_LocationInformationContainer,
&ett_lppe_OMA_LPPe_LocationInformationContainerDataList,
&ett_lppe_OMA_LPPe_LocationInformationContainerData,
&ett_lppe_OMA_LPPe_LocationInformationContainerRequest,
&ett_lppe_OMA_LPPe_LocationInformationContainerRequestList,
&ett_lppe_OMA_LPPe_LocationInformationContainerRequestItem,
&ett_lppe_OMA_LPPe_MapDataReference,
&ett_lppe_OMA_LPPe_Orientation,
&ett_lppe_T_eulerAngles,
&ett_lppe_OMA_LPPe_ReferencePoint,
&ett_lppe_T_referencePointGeographicLocation,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointRelationship,
&ett_lppe_OMA_LPPe_MapDataInformation,
&ett_lppe_OMA_LPPe_MapDataReferenceElement,
&ett_lppe_T_mapDataUrl,
&ett_lppe_T_mapProvider,
&ett_lppe_T_mapAssociation,
&ett_lppe_OMA_LPPe_ReferencePointRelationship,
&ett_lppe_OMA_LPPe_ReferencePointUniqueID,
&ett_lppe_OMA_LPPe_RelativeLocation,
&ett_lppe_OMA_LPPe_HorizontalUncertaintyAndConfidence,
&ett_lppe_T_uncShape,
&ett_lppe_T_ellipse,
&ett_lppe_OMA_LPPe_RelativeAltitude,
&ett_lppe_OMA_LPPe_GeodeticRelativeAltitude,
&ett_lppe_OMA_LPPe_GeodeticUncertaintyAndConfidence,
&ett_lppe_OMA_LPPe_CivicRelativeAltitude,
&ett_lppe_OMA_LPPe_CivicUncertaintyAndConfidence,
&ett_lppe_OMA_LPPe_Session_ID,
&ett_lppe_OMA_LPPe_ValidityArea,
&ett_lppe_OMA_LPPe_RleList,
&ett_lppe_OMA_LPPe_ValidityPeriod,
&ett_lppe_OMA_LPPe_VendorOrOperatorAssistanceDataIdentifier,
&ett_lppe_OMA_LPPe_VendorOrOperatorID,
&ett_lppe_OMA_LPPe_NonStandard_VendorOrOperatorID,
&ett_lppe_OMA_LPPe_WirelessAccessTypes,
&ett_lppe_OMA_LPPe_WLAN_AP_ID,
&ett_lppe_OMA_LPPe_WLAN_AP_Type_List,
&ett_lppe_OMA_LPPe_WLANFemtoCoverageArea,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_WLANFemtoCoverageAreaElement,
&ett_lppe_OMA_LPPe_WLANFemtoCoverageAreaElement,
&ett_lppe_T_refPointAndArea,
&ett_lppe_OMA_LPPe_CommonIEsRequestCapabilities,
&ett_lppe_OMA_LPPe_IP_Address_RequestCapabilities,
&ett_lppe_OMA_LPPe_AssistanceContainerSupportReq,
&ett_lppe_OMA_LPPe_LocationInformationContainerSupportReq,
&ett_lppe_OMA_LPPe_VendorOrOperatorIDList,
&ett_lppe_OMA_LPPe_RelativeLocationChange_RequestCapabilities,
&ett_lppe_OMA_LPPe_HighAccuracyFormatCapabilitiesReq,
&ett_lppe_OMA_LPPe_SegmentedAssistanceData_ReqCapabilities,
&ett_lppe_OMA_LPPe_ReferencePointCapabilitiesReq,
&ett_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_VendorOrOperatorID,
&ett_lppe_OMA_LPPe_ScheduledLocation_RequestCapabilities,
&ett_lppe_OMA_LPPe_AccessCapabilitiesReq,
&ett_lppe_OMA_LPPe_SegmentedLocationInformation_ReqCapabilities,
&ett_lppe_OMA_LPPe_CommonIEsProvideCapabilities,
&ett_lppe_OMA_LPPe_IP_Address_Capabilities,
&ett_lppe_T_iP_Address_support,
&ett_lppe_OMA_LPPe_AssistanceContainerSupport,
&ett_lppe_OMA_LPPe_VendorOrOperatorAssistanceContainerList,
&ett_lppe_OMA_LPPe_AssistanceContainerList,
&ett_lppe_OMA_LPPe_LocationInformationContainerSupport,
&ett_lppe_OMA_LPPe_VendorOrOperatorLocationInformationContainerList,
&ett_lppe_OMA_LPPe_LocationInformationContainerList,
&ett_lppe_OMA_LPPe_RelativeLocationChange_Capabilities,
&ett_lppe_OMA_LPPe_HighAccuracyFormatCapabilities,
&ett_lppe_OMA_LPPe_SegmentedAssistanceData_ProvideCapabs,
&ett_lppe_OMA_LPPe_ReferencePointCapabilities,
&ett_lppe_T_relativeLocationReportingSupport,
&ett_lppe_SEQUENCE_SIZE_1_128_OF_OMA_LPPe_ReferencePointProviderSupportElement,
&ett_lppe_OMA_LPPe_ReferencePointProviderSupportElement,
&ett_lppe_T_mapDataSupport,
&ett_lppe_OMA_LPPe_ScheduledLocation_Capabilities,
&ett_lppe_OMA_LPPe_AccessCapabilities,
&ett_lppe_OMA_LPPe_SegmentedLocationInformation_ProvideCapabs,
&ett_lppe_OMA_LPPe_CommonIEsRequestAssistanceData,
&ett_lppe_OMA_LPPe_RequestPeriodicADwithUpdate,
&ett_lppe_OMA_LPPe_SegmentedADResume,
&ett_lppe_OMA_LPPe_ReferencePointAssistanceReq,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_ReferencePointAssistanceReqElement,
&ett_lppe_OMA_LPPe_ReferencePointAssistanceReqElement,
&ett_lppe_OMA_LPPe_CommonIEsProvideAssistanceData,
&ett_lppe_OMA_LPPe_ProvidePeriodicADwithUpdate,
&ett_lppe_OMA_LPPe_SegmentedADTransfer,
&ett_lppe_OMA_LPPe_CommonIEsRequestLocationInformation,
&ett_lppe_OMA_LPPe_IP_Address_Request,
&ett_lppe_OMA_LPPe_RequestPeriodicLocInfoWithUpdate,
&ett_lppe_OMA_LPPe_RelativeLocationChange_Request,
&ett_lppe_OMA_LPPe_LocalPositionRequest,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_ReferencePointUniqueID,
&ett_lppe_OMA_LPPe_ScheduledLocation_Request,
&ett_lppe_OMA_LPPe_AccessTypeRequest,
&ett_lppe_OMA_LPPe_SegmentedLIResume,
&ett_lppe_OMA_LPPe_CommonIEsProvideLocationInformation,
&ett_lppe_OMA_LPPe_LocalPosition,
&ett_lppe_OMA_LPPe_IP_Address_List,
&ett_lppe_OMA_LPPe_IP_Address,
&ett_lppe_T_local_IP_Address,
&ett_lppe_OMA_LPPe_ProvidePeriodicLocInfowithUpdate,
&ett_lppe_OMA_LPPe_RelativeLocationChangeList,
&ett_lppe_OMA_LPPe_RelativeLocationChange,
&ett_lppe_OMA_LPPe_ScheduledLocation,
&ett_lppe_T_actualWindow,
&ett_lppe_OMA_LPPe_AccessTypes,
&ett_lppe_OMA_LPPe_SegmentedLITransfer,
&ett_lppe_OMA_LPPe_TimeStamp,
&ett_lppe_OMA_LPPe_CommonIEsAbort,
&ett_lppe_OMA_LPPe_CommonIEsError,
&ett_lppe_OMA_LPPe_AGNSS_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_AGNSS_CommonAssistData,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistData,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataElement,
&ett_lppe_OMA_LPPe_AGNSS_IonosphericModel,
&ett_lppe_T_staticModels,
&ett_lppe_T_waIono,
&ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelList,
&ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModelElement,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalKlobucharModel,
&ett_lppe_OMA_LPPe_AGNSS_LocalKlobucharModel,
&ett_lppe_OMA_LPPe_AGNSS_IonoStormIndication,
&ett_lppe_OMA_LPPe_AGNSS_StormList,
&ett_lppe_OMA_LPPe_AGNSS_StormElement,
&ett_lppe_OMA_LPPe_AGNSS_RleListIono,
&ett_lppe_OMA_LPPe_AGNSS_RleIonoElement,
&ett_lppe_T_ionoIndex,
&ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersProvide,
&ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceCommon,
&ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVlist,
&ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfacePerSVelement,
&ett_lppe_OMA_LPPe_AGNSS_TroposphereModel,
&ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayList,
&ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayAreaElement,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement,
&ett_lppe_OMA_LPPe_AGNSS_LocalTroposphereDelayTimeElement,
&ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersList,
&ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersAreaElement,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement,
&ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceParametersTimeElement,
&ett_lppe_OMA_LPPe_AGNSS_MappingFunctionParameters,
&ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceList,
&ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceAreaElement,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_PressureAssistanceElement,
&ett_lppe_OMA_LPPe_AGNSS_PressureAssistanceElement,
&ett_lppe_OMA_LPPe_AGNSS_SolarRadiation,
&ett_lppe_OMA_LPPe_AGNSS_MechanicsForAllSVs,
&ett_lppe_OMA_LPPe_AGNSS_MechanicsElement,
&ett_lppe_T_svInfo,
&ett_lppe_OMA_LPPe_AGNSS_PCOelement,
&ett_lppe_OMA_LPPe_AGNSS_DCBsForAllSVs,
&ett_lppe_OMA_LPPe_AGNSS_DCBlistElement,
&ett_lppe_T_reference,
&ett_lppe_OMA_LPPe_AGNSS_DCBlist,
&ett_lppe_OMA_LPPe_AGNSS_DCBelement,
&ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelList,
&ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelElement,
&ett_lppe_OMA_LPPe_AGNSS_ClockModelDegradationModel,
&ett_lppe_OMA_LPPe_AGNSS_OrbitModelDegradationModel,
&ett_lppe_OMA_LPPe_AGNSS_CCPassistCommonProvide,
&ett_lppe_OMA_LPPe_AGNSS_CCPprovideCommonParameters,
&ett_lppe_OMA_LPPe_AGNSS_CCPprovideControlParameters,
&ett_lppe_OMA_LPPe_AGNSS_CCPsupportArea,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPsignalSupport,
&ett_lppe_OMA_LPPe_AGNSS_CCPsignalSupport,
&ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationList,
&ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationElement,
&ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvide,
&ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericProvideElement,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_CCPperSignalElement,
&ett_lppe_OMA_LPPe_AGNSS_CCPperSignalElement,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_CCPperSVelement,
&ett_lppe_OMA_LPPe_AGNSS_CCPperSVelement,
&ett_lppe_OMA_LPPe_AGNSS_CodePhaseError,
&ett_lppe_OMA_LPPe_AGNSS_NavModelList,
&ett_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBased,
&ett_lppe_T_fixedInterval,
&ett_lppe_T_bases,
&ett_lppe_SEQUENCE_SIZE_1_97_OF_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement,
&ett_lppe_OMA_LPPe_AGNSS_NavModel_CoordinateBasedElement,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_AGNSS_NavModel_PVTelement,
&ett_lppe_OMA_LPPe_AGNSS_NavModel_PVTelement,
&ett_lppe_T_rateRecord,
&ett_lppe_OMA_LPPe_AGNSS_NavModel_BigNumber,
&ett_lppe_OMA_LPPe_AGNSS_NavModel_STDmatrix,
&ett_lppe_OMA_LPPe_AGNSS_RequestAssistanceData,
&ett_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataReq,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataReq,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataReqElement,
&ett_lppe_OMA_LPPe_AGNSS_IonosphericModelReq,
&ett_lppe_T_staticModels_01,
&ett_lppe_T_ionoreq,
&ett_lppe_T_periodicModels,
&ett_lppe_OMA_LPPe_AGNSS_WideAreaIonoSurfaceControlParametersRequest,
&ett_lppe_OMA_LPPe_AGNSS_TroposphereModelReq,
&ett_lppe_T_troposphereModelReq,
&ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceReq,
&ett_lppe_OMA_LPPe_AGNSS_SolarRadiationReq,
&ett_lppe_OMA_LPPe_AGNSS_WaIonoSurfaceRequest,
&ett_lppe_OMA_LPPe_AGNSS_NavModelDegradationModelReq,
&ett_lppe_OMA_LPPe_AGNSS_DCBreq,
&ett_lppe_T_reference_01,
&ett_lppe_OMA_LPPe_AGNSS_MechanicsReq,
&ett_lppe_OMA_LPPe_AGNSS_CCPrequestControlParameters,
&ett_lppe_T_ccpCommonRequest,
&ett_lppe_T_refStation,
&ett_lppe_T_posBasedReferenceStationRequest,
&ett_lppe_OMA_LPPe_AGNSS_ReferenceStationIDlist,
&ett_lppe_OMA_LPPe_AGNSS_CCPassistGenericReq,
&ett_lppe_OMA_LPPe_AGNSS_NavigationModelReq,
&ett_lppe_T_navModelID_PrefList,
&ett_lppe_OMA_LPPe_AGNSS_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssProvide,
&ett_lppe_T_controlParameters,
&ett_lppe_T_measurements,
&ett_lppe_T_localPressure,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssMeasurementElement,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssMeasurementElement,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_HAgnssPerSignalElement,
&ett_lppe_OMA_LPPe_HAgnssPerSignalElement,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_HAgnssPerSVelement,
&ett_lppe_OMA_LPPe_HAgnssPerSVelement,
&ett_lppe_OMA_LPPe_AGNSS_IonosphereMeasurements,
&ett_lppe_OMA_LPPe_AGNSS_TECPerSV,
&ett_lppe_OMA_LPPe_AGNSS_TECPerSVElement,
&ett_lppe_OMA_LPPe_AGNSS_TECAtZenith,
&ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurements,
&ett_lppe_T_temperatureMeasurement,
&ett_lppe_OMA_LPPe_AGNSS_RequestLocationInformation,
&ett_lppe_T_ionosphereMeasurementsReq,
&ett_lppe_OMA_LPPe_AGNSS_PositioningInstructions,
&ett_lppe_OMA_LPPe_AGNSS_LocalSurfaceMeasurementReq,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssRequestControlParameters,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_AGNSS_HAgnssSignalReqElement,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssSignalReqElement,
&ett_lppe_OMA_LPPe_AGNSS_ProvideCapabilities,
&ett_lppe_OMA_LPPe_AGNSS_AssistanceDataSupportList,
&ett_lppe_OMA_LPPe_AGNSS_EnvironmentObservationSupportList,
&ett_lppe_T_ionosphereMeasurementSupport,
&ett_lppe_OMA_LPPe_AGNSS_CommonAssistanceDataSupport,
&ett_lppe_OMA_LPPe_AGNSS_IonosphericModelSupport,
&ett_lppe_T_ionoModel,
&ett_lppe_OMA_LPPe_AGNSS_TroposphereModelSupport,
&ett_lppe_T_tropoModel,
&ett_lppe_OMA_LPPe_AGNSS_AltitudeAssistanceSupport,
&ett_lppe_OMA_LPPe_AGNSS_SolarRadiationSupport,
&ett_lppe_OMA_LPPe_AGNSS_CCPsupport,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistanceDataSupport,
&ett_lppe_OMA_LPPe_AGNSS_GenericAssistDataSupportElement,
&ett_lppe_OMA_LPPe_AGNSS_MechanicsSupport,
&ett_lppe_OMA_LPPe_AGNSS_DCBsupport,
&ett_lppe_OMA_LPPe_AGNSS_NavModelAccuracyModelDegradationSupport,
&ett_lppe_OMA_LPPe_AGNSS_NavModelSupport,
&ett_lppe_T_navModelSupport,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssSupport,
&ett_lppe_T_modeSupport,
&ett_lppe_T_haGNSSantennaInformationSupport,
&ett_lppe_SEQUENCE_SIZE_1_8_OF_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport,
&ett_lppe_OMA_LPPe_AGNSS_HAgnssPerGNSSsupport,
&ett_lppe_OMA_LPPe_AGNSS_RequestCapabilities,
&ett_lppe_OMA_LPPe_AGNSS_Error,
&ett_lppe_OMA_LPPe_AGNSS_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_AGNSS_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_AGNSS_CCPreferenceStationID,
&ett_lppe_OMA_LPPe_AGNSS_AntennaDescription,
&ett_lppe_T_antennaDescription,
&ett_lppe_OMA_LPPe_AGNSS_Abort,
&ett_lppe_T_targetDeviceAbortCauses,
&ett_lppe_OMA_LPPe_OTDOA_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_OTDOA_ReferenceCellInfo,
&ett_lppe_OMA_LPPe_OTDOA_PositionCalculationInfoRef,
&ett_lppe_T_cellLocation,
&ett_lppe_T_femtoCellInfo,
&ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoList,
&ett_lppe_OMA_LPPe_OTDOA_NeighbourFreqCellInfoList,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB,
&ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_eNB,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_OTDOA_CellData,
&ett_lppe_OMA_LPPe_OTDOA_NeighbourCellInfoElement_HeNB,
&ett_lppe_OMA_LPPe_OTDOA_CellData,
&ett_lppe_T_rtdInfo,
&ett_lppe_OMA_LPPe_OTDOA_RTDquality,
&ett_lppe_OMA_LPPe_OTDOA_RequestAssistanceData,
&ett_lppe_T_lteCell,
&ett_lppe_T_requestedCells,
&ett_lppe_OMA_LPPe_OTDOA_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_OTDOA_LocationInformation,
&ett_lppe_OMA_LPPe_OTDOA_RequestLocationInformation,
&ett_lppe_OMA_LPPe_OTDOA_ProvideCapabilities,
&ett_lppe_T_eNodeB_AD_sup,
&ett_lppe_T_home_eNodeB_AD_sup,
&ett_lppe_OMA_LPPe_OTDOA_RequestCapabilities,
&ett_lppe_OMA_LPPe_OTDOA_Error,
&ett_lppe_OMA_LPPe_OTDOA_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_OTDOA_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_EOTD_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_EOTD_ReferenceBTSForAssistance,
&ett_lppe_T_btsPosition,
&ett_lppe_OMA_LPPe_EOTD_MsrAssistDataList,
&ett_lppe_OMA_LPPe_EOTD_MsrAssistBTS,
&ett_lppe_OMA_LPPe_EOTD_SystemInfoAssistDataList,
&ett_lppe_OMA_LPPe_EOTD_SystemInfoAssistBTS,
&ett_lppe_OMA_LPPe_EOTD_AssistBTSData,
&ett_lppe_OMA_LPPe_EOTD_CalcAssistanceBTS,
&ett_lppe_OMA_LPPe_EOTD_relativePos,
&ett_lppe_OMA_LPPe_EOTD_RequestAssistanceData,
&ett_lppe_T_eotdAssistanceReq,
&ett_lppe_OMA_LPPe_EOTD_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_EOTD_MsrElement,
&ett_lppe_SEQUENCE_SIZE_1_15_OF_OMA_LPPe_EOTD_MeasurementWithID,
&ett_lppe_OMA_LPPe_EOTD_TOA_MeasurementsOfRef,
&ett_lppe_OMA_LPPe_EOTD_MeasurementWithID,
&ett_lppe_OMA_LPPe_EOTD_NeighborIdentity,
&ett_lppe_OMA_LPPe_EOTD_EOTDQuality,
&ett_lppe_OMA_LPPe_EOTD_MultiFrameCarrier,
&ett_lppe_OMA_LPPe_EOTD_RequestLocationInformation,
&ett_lppe_OMA_LPPe_EOTD_ProvideCapabilities,
&ett_lppe_T_eotdSupport,
&ett_lppe_OMA_LPPe_EOTD_RequestCapabilities,
&ett_lppe_OMA_LPPe_EOTD_Error,
&ett_lppe_OMA_LPPe_EOTD_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_EOTD_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_EOTD_ExpectedOTD,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_ReferenceCellInfo,
&ett_lppe_T_modeSpecificInfo,
&ett_lppe_T_fdd,
&ett_lppe_T_tdd,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_RefPosAssist,
&ett_lppe_T_cellPosition,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellList,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborCellInfo,
&ett_lppe_T_modeSpecificInfo_01,
&ett_lppe_T_fdd_01,
&ett_lppe_T_tdd_01,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_SFN_SFN_RelTimeDifference1,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_PositioningAssistance,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_IPDL_Parameters,
&ett_lppe_T_modeSpecificInfo_02,
&ett_lppe_T_fdd_02,
&ett_lppe_T_tdd_02,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_BurstModeParameters,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestAssistanceData,
&ett_lppe_T_otdoaUtraAssistanceReq,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_Measurement,
&ett_lppe_T_modeSpecificInfoMeas,
&ett_lppe_T_fdd_03,
&ett_lppe_T_tdd_03,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_UE_RX_TX_TimeDifferenceType2Info,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborList,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_Neighbor,
&ett_lppe_T_modeSpecificInfo_03,
&ett_lppe_T_fdd_04,
&ett_lppe_T_tdd_04,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_NeighborQuality,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_Quality,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_TimeStampData,
&ett_lppe_T_nonUniqueCellID,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestLocationInformation,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_ProvideCapabilities,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_RequestCapabilities,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_Error,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_PrimaryCPICH_Info,
&ett_lppe_OMA_LPPe_OTDOA_UTRA_CellAndChannelIdentity,
&ett_lppe_OMA_LPPe_ECID_LTE_ProvideAssistanceData,
&ett_lppe_SEQUENCE_SIZE_1_maxLTENetworks_OF_OMA_LPPe_ECID_LTE_NetworkData,
&ett_lppe_OMA_LPPe_ECID_LTE_NetworkData,
&ett_lppe_T_plmn_Identity,
&ett_lppe_T_mcc,
&ett_lppe_T_mnc,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEeNBs_OF_OMA_LPPe_ECID_LTE_eNodeBData,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEHeNBs_OF_OMA_LPPe_ECID_LTE_HeNBData,
&ett_lppe_OMA_LPPe_ECID_LTE_eNodeBData,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEMacroCells_OF_OMA_LPPe_ECID_LTE_CellData,
&ett_lppe_OMA_LPPe_ECID_LTE_HeNBData,
&ett_lppe_OMA_LPPe_ECID_LTE_CellData,
&ett_lppe_OMA_LPPe_ECID_LTE_RequestAssistanceData,
&ett_lppe_T_eNBrequestedAD,
&ett_lppe_T_heNBrequestedAD,
&ett_lppe_OMA_LPPe_ECID_LTE_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_maxLTEECIDSize_OF_OMA_LPPe_ECID_LTE_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_LTE_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_LTE_LocationInformation,
&ett_lppe_OMA_LPPe_ECID_LTE_RequestLocationInformation,
&ett_lppe_T_requestedMeasurements,
&ett_lppe_OMA_LPPe_ECID_LTE_ProvideCapabilities,
&ett_lppe_T_ecid_lte_MeasSupported,
&ett_lppe_T_ecid_lte_eNodeB_ADSupported,
&ett_lppe_T_ecid_utra_HeNB_ADSupported,
&ett_lppe_OMA_LPPe_ECID_LTE_RequestCapabilities,
&ett_lppe_OMA_LPPe_ECID_LTE_Error,
&ett_lppe_OMA_LPPe_ECID_LTE_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_ECID_LTE_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_ECID_GSM_ProvideAssistanceData,
&ett_lppe_SEQUENCE_SIZE_1_maxGSMNetworks_OF_OMA_LPPe_ECID_GSM_NetworkData,
&ett_lppe_OMA_LPPe_ECID_GSM_NetworkData,
&ett_lppe_T_plmn_Identity_01,
&ett_lppe_T_mcc_01,
&ett_lppe_T_mnc_01,
&ett_lppe_SEQUENCE_SIZE_1_maxGSMBaseStations_OF_OMA_LPPe_ECID_GSM_BaseStationData,
&ett_lppe_OMA_LPPe_ECID_GSM_BaseStationData,
&ett_lppe_SEQUENCE_SIZE_1_maxGSMCells_OF_OMA_LPPe_ECID_GSM_CellData,
&ett_lppe_OMA_LPPe_ECID_GSM_CellData,
&ett_lppe_OMA_LPPe_ECID_GSM_RequestAssistanceData,
&ett_lppe_T_requestedAD,
&ett_lppe_OMA_LPPe_ECID_GSM_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_maxGSMECIDSize_OF_OMA_LPPe_ECID_GSM_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_GSM_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_GSM_LocationInformation,
&ett_lppe_OMA_LPPe_NMR_GERAN,
&ett_lppe_OMA_LPPe_NMR_GERAN_item,
&ett_lppe_OMA_LPPe_ECID_GSM_RequestLocationInformation,
&ett_lppe_T_requestedMeasurements_01,
&ett_lppe_OMA_LPPe_ECID_GSM_ProvideCapabilities,
&ett_lppe_T_ecid_gsm_MeasSupported,
&ett_lppe_T_ecid_gsm_ADSupported,
&ett_lppe_OMA_LPPe_ECID_GSM_RequestCapabilities,
&ett_lppe_OMA_LPPe_ECID_GSM_Error,
&ett_lppe_OMA_LPPe_ECID_GSM_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_ECID_GSM_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_ECID_UTRA_ProvideAssistanceData,
&ett_lppe_SEQUENCE_SIZE_1_maxUTRANetworks_OF_OMA_LPPe_ECID_UTRA_NetworkData,
&ett_lppe_OMA_LPPe_ECID_UTRA_NetworkData,
&ett_lppe_T_plmn_Identity_02,
&ett_lppe_T_mcc_02,
&ett_lppe_T_mnc_02,
&ett_lppe_SEQUENCE_SIZE_1_maxUTRAnodeBs_OF_OMA_LPPe_ECID_UTRA_NodeBData,
&ett_lppe_SEQUENCE_SIZE_1_maxUTRAHNBs_OF_OMA_LPPe_ECID_UTRA_HNBData,
&ett_lppe_OMA_LPPe_ECID_UTRA_NodeBData,
&ett_lppe_SEQUENCE_SIZE_1_maxUTRAMacroCells_OF_OMA_LPPe_ECID_UTRA_CellData,
&ett_lppe_OMA_LPPe_ECID_UTRA_HNBData,
&ett_lppe_OMA_LPPe_ECID_UTRA_CellData,
&ett_lppe_T_modeSpecificInfo_04,
&ett_lppe_T_fdd_05,
&ett_lppe_T_tdd_05,
&ett_lppe_OMA_LPPe_ECID_UTRA_RequestAssistanceData,
&ett_lppe_T_nBrequestedAD,
&ett_lppe_T_hNBrequestedAD,
&ett_lppe_OMA_LPPe_ECID_UTRA_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_maxECIDUTRASize_OF_OMA_LPPe_ECID_UTRA_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_UTRA_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_UTRA_LocationInformation,
&ett_lppe_OMA_LPPe_ECID_UTRA_UTRATimingAdvance,
&ett_lppe_OMA_LPPe_UTRA_FrequencyInfo,
&ett_lppe_OMA_LPPe_UTRA_ModeSpecificInfo,
&ett_lppe_OMA_LPPe_UTRA_FrequencyInfoFDD,
&ett_lppe_OMA_LPPe_UTRA_FrequencyInfoTDD,
&ett_lppe_OMA_LPPe_ECID_UTRA_MeasuredResultsList,
&ett_lppe_OMA_LPPe_ECID_UTRA_MeasuredResults,
&ett_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResultsList,
&ett_lppe_OMA_LPPe_ECID_UTRA_CellMeasuredResults,
&ett_lppe_T_modeSpecificInfo_05,
&ett_lppe_T_fdd_06,
&ett_lppe_T_tdd_06,
&ett_lppe_OMA_LPPe_ECID_UTRA_RequestLocationInformation,
&ett_lppe_T_requestedMeasurements_02,
&ett_lppe_OMA_LPPe_ECID_UTRA_ProvideCapabilities,
&ett_lppe_T_ecid_utra_MeasSupported,
&ett_lppe_T_ecid_utra_nodeB_ADSupported,
&ett_lppe_T_ecid_utra_HNB_ADSupported,
&ett_lppe_OMA_LPPe_ECID_UTRA_RequestCapabilities,
&ett_lppe_OMA_LPPe_ECID_UTRA_Error,
&ett_lppe_OMA_LPPe_ECID_UTRA_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_ECID_UTRA_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_WLAN_AP_ProvideAssistanceData,
&ett_lppe_SEQUENCE_SIZE_1_maxWLANDataSets_OF_OMA_LPPe_WLAN_DataSet,
&ett_lppe_OMA_LPPe_WLAN_DataSet,
&ett_lppe_T_plmn_Identity_03,
&ett_lppe_T_mcc_03,
&ett_lppe_T_mnc_03,
&ett_lppe_SEQUENCE_SIZE_1_maxWLANAPs_OF_OMA_LPPe_WLAN_AP_Data,
&ett_lppe_Supported_Channels_11a,
&ett_lppe_Supported_Channels_11bg,
&ett_lppe_OMA_LPPe_WLAN_AP_Data,
&ett_lppe_SEQUENCE_SIZE_1_maxWLANTypes_OF_OMA_LPPe_WLAN_AP_Type_Data,
&ett_lppe_OMA_LPPe_WLAN_AP_Type_Data,
&ett_lppe_OMA_LPPe_WLAN_AP_RequestAssistanceData,
&ett_lppe_T_requestedAD_01,
&ett_lppe_OMA_LPPe_WLAN_AP_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_maxWLANAPSize_OF_OMA_LPPe_WLAN_AP_LocationInformationList,
&ett_lppe_OMA_LPPe_WLAN_AP_LocationInformationList,
&ett_lppe_OMA_LPPe_WLAN_AP_LocationInformation,
&ett_lppe_OMA_LPPe_WLAN_RTD,
&ett_lppe_OMA_LPPe_WLAN_ReportedLocation,
&ett_lppe_OMA_LPPe_WLAN_LocationDataLCI,
&ett_lppe_OMA_LPPe_WLAN_AP_RequestLocationInformation,
&ett_lppe_T_requestedMeasurements_03,
&ett_lppe_OMA_LPPe_WLAN_AP_ProvideCapabilities,
&ett_lppe_T_wlan_ecid_MeasSupported,
&ett_lppe_T_wlan_ap_ADSupported,
&ett_lppe_OMA_LPPe_WLAN_AP_Capability,
&ett_lppe_OMA_LPPe_WLAN_AP_RequestCapabilities,
&ett_lppe_OMA_LPPe_WLAN_AP_Error,
&ett_lppe_OMA_LPPe_WLAN_AP_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_WLAN_AP_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_ECID_WiMax_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_maxWiMaxECIDSize_OF_OMA_LPPe_ECID_WiMax_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_WiMax_LocationInformationList,
&ett_lppe_OMA_LPPe_ECID_WiMax_LocationInformation,
&ett_lppe_OMA_LPPe_ECID_WiMax_WimaxBsID,
&ett_lppe_OMA_LPPe_ECID_WiMax_WimaxRTD,
&ett_lppe_OMA_LPPe_ECID_WiMax_WimaxNMRList,
&ett_lppe_OMA_LPPe_ECID_WiMax_WimaxNMR,
&ett_lppe_OMA_LPPe_ECID_WiMax_RequestLocationInformation,
&ett_lppe_T_requestedMeasurements_04,
&ett_lppe_OMA_LPPe_ECID_WiMax_ProvideCapabilities,
&ett_lppe_T_ecid_wimax_MeasSupported,
&ett_lppe_OMA_LPPe_ECID_WiMax_RequestCapabilities,
&ett_lppe_OMA_LPPe_ECID_WiMax_Error,
&ett_lppe_OMA_LPPe_ECID_WiMax_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_ECID_WiMax_TargetDeviceErrorCauses,
&ett_lppe_OMA_LPPe_Sensor_ProvideAssistanceData,
&ett_lppe_OMA_LPPe_Sensor_RequestAssistanceData,
&ett_lppe_OMA_LPPe_Sensor_ProvideLocationInformation,
&ett_lppe_OMA_LPPe_Sensor_MotionStateList,
&ett_lppe_OMA_LPPe_Sensor_MotionStateElement,
&ett_lppe_T_secondaryMotionState,
&ett_lppe_OMA_LPPe_Sensor_RequestLocationInformation,
&ett_lppe_OMA_LPPe_Sensor_MotionStateRequest,
&ett_lppe_OMA_LPPe_Sensor_ProvideCapabilities,
&ett_lppe_OMA_LPPe_Sensor_RequestCapabilities,
&ett_lppe_OMA_LPPe_Sensor_Error,
&ett_lppe_OMA_LPPe_Sensor_TargetError,
&ett_lppe_OMA_LPPe_SRN_ProvideAssistanceData,
&ett_lppe_T_srnGroup,
&ett_lppe_OMA_LPPe_SRN_SRNgroupList,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_SRNgroup,
&ett_lppe_OMA_LPPe_SRN_SRNgroup,
&ett_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNinfo,
&ett_lppe_OMA_LPPe_SRN_SRNinfo,
&ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponse,
&ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateResponseElement,
&ett_lppe_OMA_LPPe_SRN_AntennaPattern,
&ett_lppe_OMA_LPPe_SRN_AntennaPatternElement,
&ett_lppe_T_identification,
&ett_lppe_T_antennaData,
&ett_lppe_OMA_LPPe_SRN_AntennaPatternForChannels,
&ett_lppe_T_evenGrid,
&ett_lppe_SEQUENCE_SIZE_1_maxChannels_OF_OMA_LPPe_SRN_ChannelResponse,
&ett_lppe_OMA_LPPe_SRN_ChannelResponse,
&ett_lppe_SEQUENCE_SIZE_7_901_OF_OMA_LPPe_SRN_ResponseInElevation,
&ett_lppe_OMA_LPPe_SRN_ResponseInElevation,
&ett_lppe_SEQUENCE_SIZE_18_3601_OF_OMA_LPPe_SRN_ResponseInAzimuth,
&ett_lppe_OMA_LPPe_SRN_ResponseInAzimuth,
&ett_lppe_OMA_LPPe_ComplexNumber,
&ett_lppe_OMA_LPPe_SRN_RequestAssistanceData,
&ett_lppe_T_srnGroup_01,
&ett_lppe_OMA_LPPe_SRN_SRNgroupRequest,
&ett_lppe_OMA_LPPe_SRN_SRNProvideList,
&ett_lppe_SEQUENCE_SIZE_1_256_OF_OMA_LPPe_SRN_SRNgroupUniqueID,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_Category,
&ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequest,
&ett_lppe_OMA_LPPe_SRN_SRNgroupUpdateRequestElement,
&ett_lppe_SEQUENCE_SIZE_1_1024_OF_OMA_LPPe_SRN_SRNid,
&ett_lppe_OMA_LPPe_SRN_AntennaPatternRequest,
&ett_lppe_OMA_LPPe_SRN_AntennaPatternRequestElement,
&ett_lppe_T_antennaPatternID,
&ett_lppe_OMA_LPPe_SRN_ProvideLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_MeasurementElement,
&ett_lppe_OMA_LPPe_SRN_MeasurementElement,
&ett_lppe_SEQUENCE_SIZE_1_64_OF_OMA_LPPe_SRN_srnMeasurementElement,
&ett_lppe_OMA_LPPe_SRN_srnMeasurementElement,
&ett_lppe_OMA_LPPe_SRN_RequestLocationInformation,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ReqLocInfo_Category,
&ett_lppe_OMA_LPPe_SRN_ReqLocInfo_Category,
&ett_lppe_OMA_LPPe_SRN_ProvideCapabilities,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_ProvideCapabilitiesElement,
&ett_lppe_OMA_LPPe_SRN_ProvideCapabilitiesElement,
&ett_lppe_T_supportedAssistanceData,
&ett_lppe_OMA_LPPe_SRN_RequestCapabilities,
&ett_lppe_OMA_LPPe_SRN_Error,
&ett_lppe_OMA_LPPe_SRN_LocationServerErrorCauses,
&ett_lppe_OMA_LPPe_SRN_TargetDeviceErrorCauses,
&ett_lppe_SEQUENCE_SIZE_1_16_OF_OMA_LPPe_SRN_TargetDeviceError,
&ett_lppe_OMA_LPPe_SRN_TargetDeviceError,
&ett_lppe_OMA_LPPe_SRN_SRNgroupUniqueID,
&ett_lppe_OMA_LPPe_SRN_SRNtype,
&ett_lppe_T_srnAntennaInfo,
&ett_lppe_OMA_LPPe_SRN_Category,
&ett_lppe_T_srnVendorInformation,
&ett_lppe_OMA_LPPe_SRN_SRNid,
&ett_lppe_T_srn_id,
&ett_lppe_T_nfc,
&ett_lppe_T_mobileCode,
&ett_lppe_OMA_LPPe_SRN_Technologies,
&ett_lppe_OMA_LPPe_SRN_MeasurementMask,
&ett_lppe_T_srnMeasurements,
#line 75 "../../asn1/lppe/packet-lppe-template.c"
};
proto_lppe = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("lppe", dissect_OMA_LPPe_MessageExtension_PDU, proto_lppe);
proto_register_field_array(proto_lppe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lppe(void)
{
}
