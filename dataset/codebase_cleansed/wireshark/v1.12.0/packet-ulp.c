static int
dissect_ulp_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_Version(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Version, Version_sequence);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_34(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
34, 34, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_IA5String_SIZE_1_1000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 1000, FALSE);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_ulp_IPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_IPAddress, IPAddress_choice,
NULL);
return offset;
}
static int
dissect_ulp_SETId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_SETId, SETId_choice,
NULL);
return offset;
}
static int
dissect_ulp_SetSessionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SetSessionID, SetSessionID_sequence);
return offset;
}
static int
dissect_ulp_FQDN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-", 64,
NULL);
return offset;
}
static int
dissect_ulp_SLPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_SLPAddress, SLPAddress_choice,
NULL);
return offset;
}
static int
dissect_ulp_SlpSessionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SlpSessionID, SlpSessionID_sequence);
return offset;
}
static int
dissect_ulp_SessionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SessionID, SessionID_sequence);
return offset;
}
static int
dissect_ulp_PosMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 7, NULL);
return offset;
}
static int
dissect_ulp_NotificationType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_EncodingType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_1_maxReqLength(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxReqLength, FALSE, NULL);
return offset;
}
static int
dissect_ulp_FormatIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_1_maxClientLength(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxClientLength, FALSE, NULL);
return offset;
}
static int
dissect_ulp_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ulp_Ver2_Notification_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_Notification_extension, Ver2_Notification_extension_sequence);
return offset;
}
static int
dissect_ulp_Notification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Notification, Notification_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_QoP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_QoP, QoP_sequence);
return offset;
}
static int
dissect_ulp_SLPMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_MAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_KeyIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_NotificationMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_ulp_SupportedWLANInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWLANInfo, SupportedWLANInfo_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_48(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
48, 48, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_T_apDevType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_SupportedWLANApData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWLANApData, SupportedWLANApData_sequence);
return offset;
}
static int
dissect_ulp_SEQUENCE_SIZE_1_maxWLANApDataSize_OF_SupportedWLANApData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_SEQUENCE_SIZE_1_maxWLANApDataSize_OF_SupportedWLANApData, SEQUENCE_SIZE_1_maxWLANApDataSize_OF_SupportedWLANApData_sequence_of,
1, maxWLANApDataSize, FALSE);
return offset;
}
static int
dissect_ulp_SupportedWLANApsChannel11a(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWLANApsChannel11a, SupportedWLANApsChannel11a_sequence);
return offset;
}
static int
dissect_ulp_SupportedWLANApsChannel11bg(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWLANApsChannel11bg, SupportedWLANApsChannel11bg_sequence);
return offset;
}
static int
dissect_ulp_SupportedWLANApsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWLANApsList, SupportedWLANApsList_sequence);
return offset;
}
static int
dissect_ulp_SupportedWCDMAInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedWCDMAInfo, SupportedWCDMAInfo_sequence);
return offset;
}
static int
dissect_ulp_SupportedNetworkInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedNetworkInformation, SupportedNetworkInformation_sequence);
return offset;
}
static int
dissect_ulp_TriggerType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_AllowedReportingType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_M525600_M1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-525600, -1, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_M525599_0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-525599, 0U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TimeWindow(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_TimeWindow, TimeWindow_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_65536(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65536U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_1_86400(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 86400U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_ReportingCriteria(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportingCriteria, ReportingCriteria_sequence);
return offset;
}
static int
dissect_ulp_HistoricReporting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_HistoricReporting, HistoricReporting_sequence);
return offset;
}
static int
dissect_ulp_ProtLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_BasicProtectionParams(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_BasicProtectionParams, BasicProtectionParams_sequence);
return offset;
}
static int
dissect_ulp_ProtectionLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ProtectionLevel, ProtectionLevel_sequence);
return offset;
}
static int
dissect_ulp_GNSSPosTechnology(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GNSSPosTechnology, GNSSPosTechnology_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_INIT_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_INIT_extension, Ver2_SUPL_INIT_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLINIT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLINIT, SUPLINIT_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_GANSSPositioningMethodTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSPositioningMethodTypes, GANSSPositioningMethodTypes_sequence);
return offset;
}
static int
dissect_ulp_GANSSSignals(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_GANSSPositionMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSPositionMethod, GANSSPositionMethod_sequence);
return offset;
}
static int
dissect_ulp_GANSSPositionMethods(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSPositionMethods, GANSSPositionMethods_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_ulp_Ver2_PosTechnology_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_PosTechnology_extension, Ver2_PosTechnology_extension_sequence);
return offset;
}
static int
dissect_ulp_PosTechnology(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PosTechnology, PosTechnology_sequence);
return offset;
}
static int
dissect_ulp_PrefMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_PosProtocolVersion3GPP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PosProtocolVersion3GPP, PosProtocolVersion3GPP_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_Supported3GPP2PosProtocolVersion(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Supported3GPP2PosProtocolVersion, Supported3GPP2PosProtocolVersion_sequence);
return offset;
}
static int
dissect_ulp_PosProtocolVersion3GPP2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_PosProtocolVersion3GPP2, PosProtocolVersion3GPP2_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_ulp_Ver2_PosProtocol_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_PosProtocol_extension, Ver2_PosProtocol_extension_sequence);
return offset;
}
static int
dissect_ulp_PosProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PosProtocol, PosProtocol_sequence);
return offset;
}
static int
dissect_ulp_ServicesSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ServicesSupported, ServicesSupported_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_3600(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 3600U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_1_1440(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1440U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_RepMode_cap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_RepMode_cap, RepMode_cap_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_1024(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_BatchRepCap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_BatchRepCap, BatchRepCap_sequence);
return offset;
}
static int
dissect_ulp_ReportingCap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportingCap, ReportingCap_sequence);
return offset;
}
static int
dissect_ulp_GeoAreaShapesSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GeoAreaShapesSupported, GeoAreaShapesSupported_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_maxNumGeoArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxNumGeoArea, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_maxAreaIdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxAreaIdList, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_maxAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxAreaId, NULL, FALSE);
return offset;
}
static int
dissect_ulp_EventTriggerCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_EventTriggerCapabilities, EventTriggerCapabilities_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_1_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_SessionCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SessionCapabilities, SessionCapabilities_sequence);
return offset;
}
static int
dissect_ulp_ServiceCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ServiceCapabilities, ServiceCapabilities_sequence);
return offset;
}
static int
dissect_ulp_SupportedBearers(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SupportedBearers, SupportedBearers_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SETCapabilities_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SETCapabilities_extension, Ver2_SETCapabilities_extension_sequence);
return offset;
}
static int
dissect_ulp_SETCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SETCapabilities, SETCapabilities_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 999U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_NMRelement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_NMRelement, NMRelement_sequence);
return offset;
}
static int
dissect_ulp_NMR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_NMR, NMR_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_ulp_GsmCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GsmCellInformation, GsmCellInformation_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_268435455(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 268435455U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_UARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_FrequencyInfoFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_FrequencyInfoFDD, FrequencyInfoFDD_sequence);
return offset;
}
static int
dissect_ulp_FrequencyInfoTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_FrequencyInfoTDD, FrequencyInfoTDD_sequence);
return offset;
}
static int
dissect_ulp_FrequencySpecificInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_FrequencySpecificInfo, FrequencySpecificInfo_choice,
NULL);
return offset;
}
static int
dissect_ulp_FrequencyInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_FrequencyInfo, FrequencyInfo_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_UTRA_CarrierRSSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_PrimaryCPICH_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PrimaryCPICH_Info, PrimaryCPICH_Info_sequence);
return offset;
}
static int
dissect_ulp_CPICH_Ec_N0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_CPICH_RSCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_Pathloss(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
46U, 173U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_fdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_fdd, T_fdd_sequence);
return offset;
}
static int
dissect_ulp_CellParametersID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TGSN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_PrimaryCCPCH_RSCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TimeslotISCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TimeslotISCP_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_TimeslotISCP_List, TimeslotISCP_List_sequence_of,
1, maxTS, FALSE);
return offset;
}
static int
dissect_ulp_T_tdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tdd, T_tdd_sequence);
return offset;
}
static int
dissect_ulp_T_modeSpecificInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_T_modeSpecificInfo, T_modeSpecificInfo_choice,
NULL);
return offset;
}
static int
dissect_ulp_CellMeasuredResults(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_CellMeasuredResults, CellMeasuredResults_sequence);
return offset;
}
static int
dissect_ulp_CellMeasuredResultsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_CellMeasuredResultsList, CellMeasuredResultsList_sequence_of,
1, maxCellMeas, FALSE);
return offset;
}
static int
dissect_ulp_MeasuredResults(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_MeasuredResults, MeasuredResults_sequence);
return offset;
}
static int
dissect_ulp_MeasuredResultsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_MeasuredResultsList, MeasuredResultsList_sequence_of,
1, maxFreq, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TAResolution(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_ChipRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_TimingAdvance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_TimingAdvance, TimingAdvance_sequence);
return offset;
}
static int
dissect_ulp_WcdmaCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WcdmaCellInformation, WcdmaCellInformation_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_4194303(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4194303U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_CdmaCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_CdmaCellInformation, CdmaCellInformation_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_HrpdCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_HrpdCellInformation, HrpdCellInformation_sequence);
return offset;
}
static int
dissect_ulp_UmbCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UmbCellInformation, UmbCellInformation_sequence);
return offset;
}
static int
dissect_ulp_MCC_MNC_Digit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_MCC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_MCC, MCC_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_ulp_MNC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_MNC, MNC_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_ulp_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PLMN_Identity, PLMN_Identity_sequence);
return offset;
}
static int
dissect_ulp_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_CellGlobalIdEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_CellGlobalIdEUTRA, CellGlobalIdEUTRA_sequence);
return offset;
}
static int
dissect_ulp_PhysCellId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TrackingAreaCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_RSRP_Range(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_RSRQ_Range(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_1282(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1282U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_cgi_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_cgi_Info, T_cgi_Info_sequence);
return offset;
}
static int
dissect_ulp_T_measResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_measResult, T_measResult_sequence);
return offset;
}
static int
dissect_ulp_MeasResultEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_MeasResultEUTRA, MeasResultEUTRA_sequence);
return offset;
}
static int
dissect_ulp_MeasResultListEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_MeasResultListEUTRA, MeasResultListEUTRA_sequence_of,
1, maxCellReport, FALSE);
return offset;
}
static int
dissect_ulp_LteCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_LteCellInformation, LteCellInformation_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_M127_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 128U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_apDeviceType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_0_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_16777216(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777216U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_RTDUnits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_RTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_RTD, RTD_sequence);
return offset;
}
static int
dissect_ulp_LocationEncodingDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_1_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, NULL);
return offset;
}
static int
dissect_ulp_LocationData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_LocationData, LocationData_sequence);
return offset;
}
static int
dissect_ulp_ReportedLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportedLocation, ReportedLocation_sequence);
return offset;
}
static int
dissect_ulp_WlanAPInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WlanAPInformation, WlanAPInformation_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_WimaxBsID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxBsID, WimaxBsID_sequence);
return offset;
}
static int
dissect_ulp_WimaxRTD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxRTD, WimaxRTD_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_M32768_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-32768, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_WimaxNMR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxNMR, WimaxNMR_sequence);
return offset;
}
static int
dissect_ulp_WimaxNMRList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxNMRList, WimaxNMRList_sequence_of,
1, maxWimaxBSMeas, FALSE);
return offset;
}
static int
dissect_ulp_WimaxBSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxBSInformation, WimaxBSInformation_sequence);
return offset;
}
static int
dissect_ulp_Ver2_CellInfo_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_CellInfo_extension, Ver2_CellInfo_extension_choice,
NULL);
return offset;
}
static int
dissect_ulp_CellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_CellInfo, CellInfo_choice,
NULL);
return offset;
}
static int
dissect_ulp_Status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_LocationId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_LocationId, LocationId_sequence);
return offset;
}
static int
dissect_ulp_RelativeTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_LocationIdData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_LocationIdData, LocationIdData_sequence);
return offset;
}
static int
dissect_ulp_MultipleLocationIds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_MultipleLocationIds, MultipleLocationIds_sequence_of,
1, maxLidSize, FALSE);
return offset;
}
static int
dissect_ulp_T_sip_uri(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 72 "../../asn1/ulp/ulp.cnf"
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:./-_~%#@?", 72,
NULL);
return offset;
}
static int
dissect_ulp_T_ims_public_identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 77 "../../asn1/ulp/ulp.cnf"
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:./-_~%#@?", 72,
NULL);
return offset;
}
static int
dissect_ulp_T_uri(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 82 "../../asn1/ulp/ulp.cnf"
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./-_~%#", 69,
NULL);
return offset;
}
static int
dissect_ulp_ThirdPartyID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_ThirdPartyID, ThirdPartyID_choice,
NULL);
return offset;
}
static int
dissect_ulp_ThirdParty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_ThirdParty, ThirdParty_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_ulp_IA5String_SIZE_1_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 24, FALSE);
return offset;
}
static int
dissect_ulp_IA5String_SIZE_1_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 32, FALSE);
return offset;
}
static int
dissect_ulp_IA5String_SIZE_1_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 8, FALSE);
return offset;
}
static int
dissect_ulp_ApplicationID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ApplicationID, ApplicationID_sequence);
return offset;
}
static int
dissect_ulp_UTCTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_VisibleString(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_ulp_T_latitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_180(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 180U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_uncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_uncertainty, T_uncertainty_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_altitudeDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_AltitudeInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_AltitudeInfo, AltitudeInfo_sequence);
return offset;
}
static int
dissect_ulp_PositionEstimate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PositionEstimate, PositionEstimate_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_9(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
9, 9, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_Horvel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Horvel, Horvel_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_Horandvervel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Horandvervel, Horandvervel_sequence);
return offset;
}
static int
dissect_ulp_Horveluncert(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Horveluncert, Horveluncert_sequence);
return offset;
}
static int
dissect_ulp_Horandveruncert(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Horandveruncert, Horandveruncert_sequence);
return offset;
}
static int
dissect_ulp_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_Velocity, Velocity_choice,
NULL);
return offset;
}
static int
dissect_ulp_Position(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Position, Position_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_START_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_START_extension, Ver2_SUPL_START_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLSTART(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLSTART, SUPLSTART_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_SETAuthKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_SETAuthKey, SETAuthKey_choice,
NULL);
return offset;
}
static int
dissect_ulp_KeyIdentity4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_SPCSETKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_SPCTID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SPCTID, SPCTID_sequence);
return offset;
}
static int
dissect_ulp_SPCSETKeylifetime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 24U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_RESPONSE_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_RESPONSE_extension, Ver2_SUPL_RESPONSE_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLRESPONSE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLRESPONSE, SUPLRESPONSE_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_167(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 167U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_SatelliteInfoElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SatelliteInfoElement, SatelliteInfoElement_sequence);
return offset;
}
static int
dissect_ulp_SatelliteInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_SatelliteInfo, SatelliteInfo_sequence_of,
1, 31, FALSE);
return offset;
}
static int
dissect_ulp_NavigationModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_NavigationModel, NavigationModel_sequence);
return offset;
}
static int
dissect_ulp_GanssRequestedCommonAssistanceDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssRequestedCommonAssistanceDataList, GanssRequestedCommonAssistanceDataList_sequence);
return offset;
}
static int
dissect_ulp_DGANSS_Sig_Id_Req(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_SatellitesListRelatedData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SatellitesListRelatedData, SatellitesListRelatedData_sequence);
return offset;
}
static int
dissect_ulp_SatellitesListRelatedDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_SatellitesListRelatedDataList, SatellitesListRelatedDataList_sequence_of,
0, maxGANSSSat, FALSE);
return offset;
}
static int
dissect_ulp_GanssNavigationModelData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssNavigationModelData, GanssNavigationModelData_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_59(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_ganssDataBitSatList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_T_ganssDataBitSatList, T_ganssDataBitSatList_sequence_of,
1, maxGANSSSat, FALSE);
return offset;
}
static int
dissect_ulp_ReqDataBitAssistanceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReqDataBitAssistanceList, ReqDataBitAssistanceList_sequence);
return offset;
}
static int
dissect_ulp_GanssDataBits(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssDataBits, GanssDataBits_sequence);
return offset;
}
static int
dissect_ulp_GanssAdditionalDataChoices(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssAdditionalDataChoices, GanssAdditionalDataChoices_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_ExtendedEphemeris(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ExtendedEphemeris, ExtendedEphemeris_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_23(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 23U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_GANSSextEphTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSextEphTime, GANSSextEphTime_sequence);
return offset;
}
static int
dissect_ulp_GanssExtendedEphCheck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssExtendedEphCheck, GanssExtendedEphCheck_sequence);
return offset;
}
static int
dissect_ulp_GanssReqGenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssReqGenericData, GanssReqGenericData_sequence);
return offset;
}
static int
dissect_ulp_GanssRequestedGenericAssistanceDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_GanssRequestedGenericAssistanceDataList, GanssRequestedGenericAssistanceDataList_sequence_of,
1, maxGANSS, FALSE);
return offset;
}
static int
dissect_ulp_GPSTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GPSTime, GPSTime_sequence);
return offset;
}
static int
dissect_ulp_ExtendedEphCheck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ExtendedEphCheck, ExtendedEphCheck_sequence);
return offset;
}
static int
dissect_ulp_Ver2_RequestedAssistData_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_RequestedAssistData_extension, Ver2_RequestedAssistData_extension_sequence);
return offset;
}
static int
dissect_ulp_RequestedAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_RequestedAssistData, RequestedAssistData_sequence);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_1_8192(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 8192, FALSE, NULL);
return offset;
}
static int
dissect_ulp_T_rrlpPayload(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 53 "../../asn1/ulp/ulp.cnf"
tvbuff_t *rrlp_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 8192, FALSE, &rrlp_tvb);
if (rrlp_tvb && rrlp_handle) {
call_dissector(rrlp_handle, rrlp_tvb, actx->pinfo, tree);
}
return offset;
}
static int
dissect_ulp_T_lPPPayload_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 62 "../../asn1/ulp/ulp.cnf"
tvbuff_t *lpp_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 60000, FALSE, &lpp_tvb);
if (lpp_tvb && lpp_handle) {
call_dissector(lpp_handle, lpp_tvb, actx->pinfo, tree);
}
return offset;
}
static int
dissect_ulp_T_lPPPayload(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_T_lPPPayload, T_lPPPayload_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_ulp_OCTET_STRING_SIZE_1_60000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 60000, FALSE, NULL);
return offset;
}
static int
dissect_ulp_T_tIA801Payload(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tIA801Payload, T_tIA801Payload_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_ulp_Ver2_PosPayLoad_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_PosPayLoad_extension, Ver2_PosPayLoad_extension_sequence);
return offset;
}
static int
dissect_ulp_PosPayLoad(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_PosPayLoad, PosPayLoad_choice,
NULL);
return offset;
}
static int
dissect_ulp_T_utran_GPSTimingOfCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_utran_GPSTimingOfCell, T_utran_GPSTimingOfCell_sequence);
return offset;
}
static int
dissect_ulp_T_fdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_fdd_01, T_fdd_01_sequence);
return offset;
}
static int
dissect_ulp_T_tdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tdd_01, T_tdd_01_sequence);
return offset;
}
static int
dissect_ulp_T_modeSpecificInfo_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_T_modeSpecificInfo_01, T_modeSpecificInfo_01_choice,
NULL);
return offset;
}
static int
dissect_ulp_UTRAN_GPSReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GPSReferenceTime, UTRAN_GPSReferenceTime_sequence);
return offset;
}
static int
dissect_ulp_UTRANGPSDriftRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
15, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_UTRAN_GPSReferenceTimeAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GPSReferenceTimeAssistance, UTRAN_GPSReferenceTimeAssistance_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_set_GPSTimingOfCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_set_GPSTimingOfCell, T_set_GPSTimingOfCell_sequence);
return offset;
}
static int
dissect_ulp_T_fdd_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_fdd_02, T_fdd_02_sequence);
return offset;
}
static int
dissect_ulp_T_tdd_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tdd_02, T_tdd_02_sequence);
return offset;
}
static int
dissect_ulp_T_modeSpecificInfo_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_T_modeSpecificInfo_02, T_modeSpecificInfo_02_choice,
NULL);
return offset;
}
static int
dissect_ulp_UTRAN_GPSReferenceTimeResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GPSReferenceTimeResult, UTRAN_GPSReferenceTimeResult_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_86399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 86399U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_3999999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3999999U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_fdd_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_fdd_03, T_fdd_03_sequence);
return offset;
}
static int
dissect_ulp_T_tdd_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tdd_03, T_tdd_03_sequence);
return offset;
}
static int
dissect_ulp_T_modeSpecificInfo_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_T_modeSpecificInfo_03, T_modeSpecificInfo_03_choice,
NULL);
return offset;
}
static int
dissect_ulp_UTRAN_GANSSReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GANSSReferenceTime, UTRAN_GANSSReferenceTime_sequence);
return offset;
}
static int
dissect_ulp_UTRANGANSSDriftRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
15, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_UTRAN_GANSSReferenceTimeAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GANSSReferenceTimeAssistance, UTRAN_GANSSReferenceTimeAssistance_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_80(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 80U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_set_GANSSTimingOfCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_set_GANSSTimingOfCell, T_set_GANSSTimingOfCell_sequence);
return offset;
}
static int
dissect_ulp_T_fdd_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_fdd_04, T_fdd_04_sequence);
return offset;
}
static int
dissect_ulp_T_tdd_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_T_tdd_04, T_tdd_04_sequence);
return offset;
}
static int
dissect_ulp_T_modeSpecificInfo_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_T_modeSpecificInfo_04, T_modeSpecificInfo_04_choice,
NULL);
return offset;
}
static int
dissect_ulp_SET_GANSSReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SET_GANSSReferenceTime, SET_GANSSReferenceTime_sequence);
return offset;
}
static int
dissect_ulp_UTRAN_GANSSReferenceTimeResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UTRAN_GANSSReferenceTimeResult, UTRAN_GANSSReferenceTimeResult_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_POS_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_POS_extension, Ver2_SUPL_POS_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLPOS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLPOS, SUPLPOS_sequence);
return offset;
}
static int
dissect_ulp_Ver(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_POS_INIT_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_POS_INIT_extension, Ver2_SUPL_POS_INIT_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLPOSINIT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLPOSINIT, SUPLPOSINIT_sequence);
return offset;
}
static int
dissect_ulp_StatusCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
20, NULL, TRUE, 6, StatusCode_value_map);
return offset;
}
static int
dissect_ulp_Ver2_SUPL_END_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPL_END_extension, Ver2_SUPL_END_extension_sequence);
return offset;
}
static int
dissect_ulp_SUPLEND(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLEND, SUPLEND_sequence);
return offset;
}
static int
dissect_ulp_SUPLAUTHREQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLAUTHREQ, SUPLAUTHREQ_sequence);
return offset;
}
static int
dissect_ulp_SUPLAUTHRESP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SUPLAUTHRESP, SUPLAUTHRESP_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_8639999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8639999U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_0_2678400(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2678400U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_PeriodicParams(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PeriodicParams, PeriodicParams_sequence);
return offset;
}
static int
dissect_ulp_AreaEventType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_INTEGER_1_604800(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 604800U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_RepeatedReportingParams(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_RepeatedReportingParams, RepeatedReportingParams_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_11318399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 11318399U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_T_latitudeSign_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ulp_Coordinate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Coordinate, Coordinate_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_1_1000000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1000000U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_1_1500000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1500000U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_CircularArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_CircularArea, CircularArea_sequence);
return offset;
}
static int
dissect_ulp_INTEGER_0_179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_EllipticalArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_EllipticalArea, EllipticalArea_sequence);
return offset;
}
static int
dissect_ulp_PolygonDescription(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_PolygonDescription, PolygonDescription_sequence_of,
3, 15, FALSE);
return offset;
}
static int
dissect_ulp_INTEGER_1_100000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100000U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_PolygonArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PolygonArea, PolygonArea_sequence);
return offset;
}
static int
dissect_ulp_GeographicTargetArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_GeographicTargetArea, GeographicTargetArea_choice,
NULL);
return offset;
}
static int
dissect_ulp_GeographicTargetAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_GeographicTargetAreaList, GeographicTargetAreaList_sequence_of,
1, maxNumGeoArea, FALSE);
return offset;
}
static int
dissect_ulp_GSMAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GSMAreaId, GSMAreaId_sequence);
return offset;
}
static int
dissect_ulp_WCDMAAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WCDMAAreaId, WCDMAAreaId_sequence);
return offset;
}
static int
dissect_ulp_CDMAAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_CDMAAreaId, CDMAAreaId_sequence);
return offset;
}
static int
dissect_ulp_HRPDAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_HRPDAreaId, HRPDAreaId_sequence);
return offset;
}
static int
dissect_ulp_UMBAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_UMBAreaId, UMBAreaId_sequence);
return offset;
}
static int
dissect_ulp_BIT_STRING_SIZE_29(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
29, 29, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ulp_LTEAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_LTEAreaId, LTEAreaId_sequence);
return offset;
}
static int
dissect_ulp_WLANAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WLANAreaId, WLANAreaId_sequence);
return offset;
}
static int
dissect_ulp_WimaxAreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_WimaxAreaId, WimaxAreaId_sequence);
return offset;
}
static int
dissect_ulp_AreaId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_AreaId, AreaId_choice,
NULL);
return offset;
}
static int
dissect_ulp_AreaIdSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_AreaIdSet, AreaIdSet_sequence_of,
1, maxAreaId, FALSE);
return offset;
}
static int
dissect_ulp_AreaIdSetType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_GeoAreaIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, maxNumGeoArea, NULL, FALSE);
return offset;
}
static int
dissect_ulp_GeoAreaMappingList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_GeoAreaMappingList, GeoAreaMappingList_sequence_of,
1, maxNumGeoArea, FALSE);
return offset;
}
static int
dissect_ulp_AreaIdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_AreaIdList, AreaIdList_sequence);
return offset;
}
static int
dissect_ulp_SEQUENCE_SIZE_1_maxAreaIdList_OF_AreaIdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_SEQUENCE_SIZE_1_maxAreaIdList_OF_AreaIdList, SEQUENCE_SIZE_1_maxAreaIdList_OF_AreaIdList_sequence_of,
1, maxAreaIdList, FALSE);
return offset;
}
static int
dissect_ulp_AreaEventParams(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_AreaEventParams, AreaEventParams_sequence);
return offset;
}
static int
dissect_ulp_TriggerParams(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_TriggerParams, TriggerParams_choice,
NULL);
return offset;
}
static int
dissect_ulp_CauseCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_Ver2_SUPLTRIGGEREDSTART(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLTRIGGEREDSTART, Ver2_SUPLTRIGGEREDSTART_sequence);
return offset;
}
static int
dissect_ulp_RepMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, RepMode_value_map);
return offset;
}
static int
dissect_ulp_INTEGER_1_2048(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 2048U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_BatchRepConditions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_BatchRepConditions, BatchRepConditions_choice,
NULL);
return offset;
}
static int
dissect_ulp_BatchRepType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_BatchRepType, BatchRepType_sequence);
return offset;
}
static int
dissect_ulp_ReportingMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportingMode, ReportingMode_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPLTRIGGEREDRESPONSE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLTRIGGEREDRESPONSE, Ver2_SUPLTRIGGEREDRESPONSE_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPLTRIGGEREDSTOP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLTRIGGEREDSTOP, Ver2_SUPLTRIGGEREDSTOP_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPLNOTIFY(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLNOTIFY, Ver2_SUPLNOTIFY_sequence);
return offset;
}
static int
dissect_ulp_NotificationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ulp_Ver2_SUPLNOTIFYRESPONSE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLNOTIFYRESPONSE, Ver2_SUPLNOTIFYRESPONSE_sequence);
return offset;
}
static int
dissect_ulp_Ver2_SUPLSETINIT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLSETINIT, Ver2_SUPLSETINIT_sequence);
return offset;
}
static int
dissect_ulp_SessionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_SessionInformation, SessionInformation_sequence);
return offset;
}
static int
dissect_ulp_SessionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_SessionList, SessionList_sequence_of,
1, maxnumSessions, FALSE);
return offset;
}
static int
dissect_ulp_GANSSSignalsDescription(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSSignalsDescription, GANSSSignalsDescription_sequence);
return offset;
}
static int
dissect_ulp_GANSSsignalsInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_GANSSsignalsInfo, GANSSsignalsInfo_sequence_of,
1, maxGANSS, FALSE);
return offset;
}
static int
dissect_ulp_PositionData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_PositionData, PositionData_sequence);
return offset;
}
static int
dissect_ulp_ResultCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, ResultCode_value_map);
return offset;
}
static int
dissect_ulp_INTEGER_0_31536000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31536000U, NULL, FALSE);
return offset;
}
static int
dissect_ulp_TimeStamp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_TimeStamp, TimeStamp_choice,
NULL);
return offset;
}
static int
dissect_ulp_ReportData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportData, ReportData_sequence);
return offset;
}
static int
dissect_ulp_ReportDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ulp_ReportDataList, ReportDataList_sequence_of,
1, 1024, FALSE);
return offset;
}
static int
dissect_ulp_Ver2_SUPLREPORT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ulp_Ver2_SUPLREPORT, Ver2_SUPLREPORT_sequence);
return offset;
}
static int
dissect_ulp_UlpMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 43 "../../asn1/ulp/ulp.cnf"
guint32 UlpMessage;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ulp_UlpMessage, UlpMessage_choice,
&UlpMessage);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", val_to_str(UlpMessage,ulp_UlpMessage_vals,"Unknown"));
return offset;
}
static int
dissect_ulp_ULP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 28 "../../asn1/ulp/ulp.cnf"
proto_item *it;
proto_tree *ulp_tree;
it = proto_tree_add_item(tree, proto_ulp, tvb, 0, -1, ENC_NA);
ulp_tree = proto_item_add_subtree(it, ett_ulp);
col_set_str(actx->pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(actx->pinfo->cinfo, COL_INFO);
#line 39 "../../asn1/ulp/ulp.cnf"
offset = dissect_per_sequence(tvb, offset, actx, ulp_tree, hf_index,
ett_ulp_ULP_PDU, ULP_PDU_sequence);
return offset;
}
static int dissect_ULP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_ulp_ULP_PDU(tvb, offset, &asn1_ctx, tree, hf_ulp_ULP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static guint
get_ulp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb,offset);
}
static int
dissect_ulp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, ulp_desegment, ULP_HEADER_SIZE,
get_ulp_pdu_len, dissect_ULP_PDU_PDU, data);
return tvb_length(tvb);
}
void proto_register_ulp(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/ulp/packet-ulp-hfarr.c"
{ &hf_ulp_ULP_PDU_PDU,
{ "ULP-PDU", "ulp.ULP_PDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_length,
{ "length", "ulp.length",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_version,
{ "version", "ulp.version_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sessionID,
{ "sessionID", "ulp.sessionID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_message,
{ "message", "ulp.message",
FT_UINT32, BASE_DEC, VALS(ulp_UlpMessage_vals), 0,
"UlpMessage", HFILL }},
{ &hf_ulp_msSUPLINIT,
{ "msSUPLINIT", "ulp.msSUPLINIT_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLINIT", HFILL }},
{ &hf_ulp_msSUPLSTART,
{ "msSUPLSTART", "ulp.msSUPLSTART_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLSTART", HFILL }},
{ &hf_ulp_msSUPLRESPONSE,
{ "msSUPLRESPONSE", "ulp.msSUPLRESPONSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLRESPONSE", HFILL }},
{ &hf_ulp_msSUPLPOSINIT,
{ "msSUPLPOSINIT", "ulp.msSUPLPOSINIT_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLPOSINIT", HFILL }},
{ &hf_ulp_msSUPLPOS,
{ "msSUPLPOS", "ulp.msSUPLPOS_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLPOS", HFILL }},
{ &hf_ulp_msSUPLEND,
{ "msSUPLEND", "ulp.msSUPLEND_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLEND", HFILL }},
{ &hf_ulp_msSUPLAUTHREQ,
{ "msSUPLAUTHREQ", "ulp.msSUPLAUTHREQ_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLAUTHREQ", HFILL }},
{ &hf_ulp_msSUPLAUTHRESP,
{ "msSUPLAUTHRESP", "ulp.msSUPLAUTHRESP_element",
FT_NONE, BASE_NONE, NULL, 0,
"SUPLAUTHRESP", HFILL }},
{ &hf_ulp_msSUPLTRIGGEREDSTART,
{ "msSUPLTRIGGEREDSTART", "ulp.msSUPLTRIGGEREDSTART_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLTRIGGEREDSTART", HFILL }},
{ &hf_ulp_msSUPLTRIGGEREDRESPONSE,
{ "msSUPLTRIGGEREDRESPONSE", "ulp.msSUPLTRIGGEREDRESPONSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLTRIGGEREDRESPONSE", HFILL }},
{ &hf_ulp_msSUPLTRIGGEREDSTOP,
{ "msSUPLTRIGGEREDSTOP", "ulp.msSUPLTRIGGEREDSTOP_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLTRIGGEREDSTOP", HFILL }},
{ &hf_ulp_msSUPLNOTIFY,
{ "msSUPLNOTIFY", "ulp.msSUPLNOTIFY_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLNOTIFY", HFILL }},
{ &hf_ulp_msSUPLNOTIFYRESPONSE,
{ "msSUPLNOTIFYRESPONSE", "ulp.msSUPLNOTIFYRESPONSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLNOTIFYRESPONSE", HFILL }},
{ &hf_ulp_msSUPLSETINIT,
{ "msSUPLSETINIT", "ulp.msSUPLSETINIT_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLSETINIT", HFILL }},
{ &hf_ulp_msSUPLREPORT,
{ "msSUPLREPORT", "ulp.msSUPLREPORT_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ver2_SUPLREPORT", HFILL }},
{ &hf_ulp_posMethod,
{ "posMethod", "ulp.posMethod",
FT_UINT32, BASE_DEC, VALS(ulp_PosMethod_vals), 0,
NULL, HFILL }},
{ &hf_ulp_notification,
{ "notification", "ulp.notification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sLPAddress,
{ "sLPAddress", "ulp.sLPAddress",
FT_UINT32, BASE_DEC, VALS(ulp_SLPAddress_vals), 0,
NULL, HFILL }},
{ &hf_ulp_qoP,
{ "qoP", "ulp.qoP_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sLPMode,
{ "sLPMode", "ulp.sLPMode",
FT_UINT32, BASE_DEC, VALS(ulp_SLPMode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_mAC,
{ "mAC", "ulp.mAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_keyIdentity,
{ "keyIdentity", "ulp.keyIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_INIT_extension,
{ "ver2-SUPL-INIT-extension", "ulp.ver2_SUPL_INIT_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_notificationType,
{ "notificationType", "ulp.notificationType",
FT_UINT32, BASE_DEC, VALS(ulp_NotificationType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_encodingType,
{ "encodingType", "ulp.encodingType",
FT_UINT32, BASE_DEC, VALS(ulp_EncodingType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_requestorId,
{ "requestorId", "ulp.requestorId",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_maxReqLength", HFILL }},
{ &hf_ulp_requestorIdType,
{ "requestorIdType", "ulp.requestorIdType",
FT_UINT32, BASE_DEC, VALS(ulp_FormatIndicator_vals), 0,
"FormatIndicator", HFILL }},
{ &hf_ulp_clientName,
{ "clientName", "ulp.clientName",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_maxClientLength", HFILL }},
{ &hf_ulp_clientNameType,
{ "clientNameType", "ulp.clientNameType",
FT_UINT32, BASE_DEC, VALS(ulp_FormatIndicator_vals), 0,
"FormatIndicator", HFILL }},
{ &hf_ulp_ver2_Notification_extension,
{ "ver2-Notification-extension", "ulp.ver2_Notification_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sETCapabilities,
{ "sETCapabilities", "ulp.sETCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_locationId,
{ "locationId", "ulp.locationId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_START_extension,
{ "ver2-SUPL-START-extension", "ulp.ver2_SUPL_START_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_posTechnology,
{ "posTechnology", "ulp.posTechnology_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_prefMethod,
{ "prefMethod", "ulp.prefMethod",
FT_UINT32, BASE_DEC, VALS(ulp_PrefMethod_vals), 0,
NULL, HFILL }},
{ &hf_ulp_posProtocol,
{ "posProtocol", "ulp.posProtocol_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SETCapabilities_extension,
{ "ver2-SETCapabilities-extension", "ulp.ver2_SETCapabilities_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_agpsSETassisted,
{ "agpsSETassisted", "ulp.agpsSETassisted",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_agpsSETBased,
{ "agpsSETBased", "ulp.agpsSETBased",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_autonomousGPS,
{ "autonomousGPS", "ulp.autonomousGPS",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_aFLT,
{ "aFLT", "ulp.aFLT",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_eCID,
{ "eCID", "ulp.eCID",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_eOTD,
{ "eOTD", "ulp.eOTD",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_oTDOA,
{ "oTDOA", "ulp.oTDOA",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ver2_PosTechnology_extension,
{ "ver2-PosTechnology-extension", "ulp.ver2_PosTechnology_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tia801,
{ "tia801", "ulp.tia801",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_rrlp,
{ "rrlp", "ulp.rrlp",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_rrc,
{ "rrc", "ulp.rrc",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ver2_PosProtocol_extension,
{ "ver2-PosProtocol-extension", "ulp.ver2_PosProtocol_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sETAuthKey,
{ "sETAuthKey", "ulp.sETAuthKey",
FT_UINT32, BASE_DEC, VALS(ulp_SETAuthKey_vals), 0,
NULL, HFILL }},
{ &hf_ulp_keyIdentity4,
{ "keyIdentity4", "ulp.keyIdentity4",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_RESPONSE_extension,
{ "ver2-SUPL-RESPONSE-extension", "ulp.ver2_SUPL_RESPONSE_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_shortKey,
{ "shortKey", "ulp.shortKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_ulp_longKey,
{ "longKey", "ulp.longKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_256", HFILL }},
{ &hf_ulp_requestedAssistData,
{ "requestedAssistData", "ulp.requestedAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_position,
{ "position", "ulp.position_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sUPLPOS,
{ "sUPLPOS", "ulp.sUPLPOS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver,
{ "ver", "ulp.ver",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_POS_INIT_extension,
{ "ver2-SUPL-POS-INIT-extension", "ulp.ver2_SUPL_POS_INIT_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_almanacRequested,
{ "almanacRequested", "ulp.almanacRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_utcModelRequested,
{ "utcModelRequested", "ulp.utcModelRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ionosphericModelRequested,
{ "ionosphericModelRequested", "ulp.ionosphericModelRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_dgpsCorrectionsRequested,
{ "dgpsCorrectionsRequested", "ulp.dgpsCorrectionsRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_referenceLocationRequested,
{ "referenceLocationRequested", "ulp.referenceLocationRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_referenceTimeRequested,
{ "referenceTimeRequested", "ulp.referenceTimeRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_acquisitionAssistanceRequested,
{ "acquisitionAssistanceRequested", "ulp.acquisitionAssistanceRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_realTimeIntegrityRequested,
{ "realTimeIntegrityRequested", "ulp.realTimeIntegrityRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_navigationModelRequested,
{ "navigationModelRequested", "ulp.navigationModelRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_navigationModelData,
{ "navigationModelData", "ulp.navigationModelData_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavigationModel", HFILL }},
{ &hf_ulp_ver2_RequestedAssistData_extension,
{ "ver2-RequestedAssistData-extension", "ulp.ver2_RequestedAssistData_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_gpsWeek,
{ "gpsWeek", "ulp.gpsWeek",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_gpsToe,
{ "gpsToe", "ulp.gpsToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_167", HFILL }},
{ &hf_ulp_nSAT,
{ "nSAT", "ulp.nSAT",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_ulp_toeLimit,
{ "toeLimit", "ulp.toeLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10", HFILL }},
{ &hf_ulp_satInfo,
{ "satInfo", "ulp.satInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SatelliteInfo", HFILL }},
{ &hf_ulp_SatelliteInfo_item,
{ "SatelliteInfoElement", "ulp.SatelliteInfoElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_satId,
{ "satId", "ulp.satId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_iODE,
{ "iODE", "ulp.iODE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_posPayLoad,
{ "posPayLoad", "ulp.posPayLoad",
FT_UINT32, BASE_DEC, VALS(ulp_PosPayLoad_vals), 0,
NULL, HFILL }},
{ &hf_ulp_velocity,
{ "velocity", "ulp.velocity",
FT_UINT32, BASE_DEC, VALS(ulp_Velocity_vals), 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_POS_extension,
{ "ver2-SUPL-POS-extension", "ulp.ver2_SUPL_POS_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tia801payload,
{ "tia801payload", "ulp.tia801payload",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_8192", HFILL }},
{ &hf_ulp_rrcPayload,
{ "rrcPayload", "ulp.rrcPayload",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_8192", HFILL }},
{ &hf_ulp_rrlpPayload,
{ "rrlpPayload", "ulp.rrlpPayload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ver2_PosPayLoad_extension,
{ "ver2-PosPayLoad-extension", "ulp.ver2_PosPayLoad_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_statusCode,
{ "statusCode", "ulp.statusCode",
FT_UINT32, BASE_DEC, VALS(ulp_StatusCode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_ver2_SUPL_END_extension,
{ "ver2-SUPL-END-extension", "ulp.ver2_SUPL_END_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sPCSETKey,
{ "sPCSETKey", "ulp.sPCSETKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sPCTID,
{ "sPCTID", "ulp.sPCTID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sPCSETKeylifetime,
{ "sPCSETKeylifetime", "ulp.sPCSETKeylifetime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_notificationResponse,
{ "notificationResponse", "ulp.notificationResponse",
FT_UINT32, BASE_DEC, VALS(ulp_NotificationResponse_vals), 0,
NULL, HFILL }},
{ &hf_ulp_targetSETID,
{ "targetSETID", "ulp.targetSETID",
FT_UINT32, BASE_DEC, VALS(ulp_SETId_vals), 0,
"SETId", HFILL }},
{ &hf_ulp_applicationID,
{ "applicationID", "ulp.applicationID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_multipleLocationIds,
{ "multipleLocationIds", "ulp.multipleLocationIds",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_thirdParty,
{ "thirdParty", "ulp.thirdParty",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_triggerType,
{ "triggerType", "ulp.triggerType",
FT_UINT32, BASE_DEC, VALS(ulp_TriggerType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_triggerParams,
{ "triggerParams", "ulp.triggerParams",
FT_UINT32, BASE_DEC, VALS(ulp_TriggerParams_vals), 0,
NULL, HFILL }},
{ &hf_ulp_reportingCap,
{ "reportingCap", "ulp.reportingCap_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_causeCode,
{ "causeCode", "ulp.causeCode",
FT_UINT32, BASE_DEC, VALS(ulp_CauseCode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_periodicParams,
{ "periodicParams", "ulp.periodicParams_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_areaEventParams,
{ "areaEventParams", "ulp.areaEventParams_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_numberOfFixes,
{ "numberOfFixes", "ulp.numberOfFixes",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8639999", HFILL }},
{ &hf_ulp_intervalBetweenFixes,
{ "intervalBetweenFixes", "ulp.intervalBetweenFixes",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8639999", HFILL }},
{ &hf_ulp_startTime,
{ "startTime", "ulp.startTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2678400", HFILL }},
{ &hf_ulp_areaEventType,
{ "areaEventType", "ulp.areaEventType",
FT_UINT32, BASE_DEC, VALS(ulp_AreaEventType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_locationEstimate,
{ "locationEstimate", "ulp.locationEstimate",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_repeatedReportingParams,
{ "repeatedReportingParams", "ulp.repeatedReportingParams_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_stopTime,
{ "stopTime", "ulp.stopTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_11318399", HFILL }},
{ &hf_ulp_geographicTargetAreaList,
{ "geographicTargetAreaList", "ulp.geographicTargetAreaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_areaIdLists,
{ "areaIdLists", "ulp.areaIdLists",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxAreaIdList_OF_AreaIdList", HFILL }},
{ &hf_ulp_areaIdLists_item,
{ "AreaIdList", "ulp.AreaIdList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_minimumIntervalTime,
{ "minimumIntervalTime", "ulp.minimumIntervalTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_604800", HFILL }},
{ &hf_ulp_maximumNumberOfReports,
{ "maximumNumberOfReports", "ulp.maximumNumberOfReports",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_ulp_GeographicTargetAreaList_item,
{ "GeographicTargetArea", "ulp.GeographicTargetArea",
FT_UINT32, BASE_DEC, VALS(ulp_GeographicTargetArea_vals), 0,
NULL, HFILL }},
{ &hf_ulp_circularArea,
{ "circularArea", "ulp.circularArea_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ellipticalArea,
{ "ellipticalArea", "ulp.ellipticalArea_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_polygonArea,
{ "polygonArea", "ulp.polygonArea_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_areaIdSet,
{ "areaIdSet", "ulp.areaIdSet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_areaIdSetType,
{ "areaIdSetType", "ulp.areaIdSetType",
FT_UINT32, BASE_DEC, VALS(ulp_AreaIdSetType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_geoAreaMappingList,
{ "geoAreaMappingList", "ulp.geoAreaMappingList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_AreaIdSet_item,
{ "AreaId", "ulp.AreaId",
FT_UINT32, BASE_DEC, VALS(ulp_AreaId_vals), 0,
NULL, HFILL }},
{ &hf_ulp_gSMAreaId,
{ "gSMAreaId", "ulp.gSMAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_wCDMAAreaId,
{ "wCDMAAreaId", "ulp.wCDMAAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cDMAAreaId,
{ "cDMAAreaId", "ulp.cDMAAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_hRPDAreaId,
{ "hRPDAreaId", "ulp.hRPDAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_uMBAreaId,
{ "uMBAreaId", "ulp.uMBAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_lTEAreaId,
{ "lTEAreaId", "ulp.lTEAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_wLANAreaId,
{ "wLANAreaId", "ulp.wLANAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_wiMAXAreaId,
{ "wiMAXAreaId", "ulp.wiMAXAreaId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_refMCC,
{ "refMCC", "ulp.refMCC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_999", HFILL }},
{ &hf_ulp_refMNC,
{ "refMNC", "ulp.refMNC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_999", HFILL }},
{ &hf_ulp_refLAC,
{ "refLAC", "ulp.refLAC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refCI,
{ "refCI", "ulp.refCI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refUC,
{ "refUC", "ulp.refUC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_268435455", HFILL }},
{ &hf_ulp_refSID,
{ "refSID", "ulp.refSID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refNID,
{ "refNID", "ulp.refNID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_ulp_refBASEID,
{ "refBASEID", "ulp.refBASEID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refSECTORID,
{ "refSECTORID", "ulp.refSECTORID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_ulp_refCI_01,
{ "refCI", "ulp.refCI",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_29", HFILL }},
{ &hf_ulp_apMACAddress,
{ "apMACAddress", "ulp.apMACAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_ulp_bsID_MSB,
{ "bsID-MSB", "ulp.bsID_MSB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_ulp_bsID_LSB,
{ "bsID-LSB", "ulp.bsID_LSB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_ulp_GeoAreaMappingList_item,
{ "GeoAreaIndex", "ulp.GeoAreaIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_supportedNetworkInformation,
{ "supportedNetworkInformation", "ulp.supportedNetworkInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_reportingMode,
{ "reportingMode", "ulp.reportingMode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_gnssPosTechnology,
{ "gnssPosTechnology", "ulp.gnssPosTechnology_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_repMode,
{ "repMode", "ulp.repMode",
FT_UINT32, BASE_DEC, VALS(ulp_RepMode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_batchRepConditions,
{ "batchRepConditions", "ulp.batchRepConditions",
FT_UINT32, BASE_DEC, VALS(ulp_BatchRepConditions_vals), 0,
NULL, HFILL }},
{ &hf_ulp_batchRepType,
{ "batchRepType", "ulp.batchRepType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_num_interval,
{ "num-interval", "ulp.num_interval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_ulp_num_minutes,
{ "num-minutes", "ulp.num_minutes",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_2048", HFILL }},
{ &hf_ulp_endofsession,
{ "endofsession", "ulp.endofsession_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_reportPosition,
{ "reportPosition", "ulp.reportPosition",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_reportMeasurements,
{ "reportMeasurements", "ulp.reportMeasurements",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_intermediateReports,
{ "intermediateReports", "ulp.intermediateReports",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_discardOldest,
{ "discardOldest", "ulp.discardOldest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_sessionList,
{ "sessionList", "ulp.sessionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_reportDataList,
{ "reportDataList", "ulp.reportDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_moreComponents,
{ "moreComponents", "ulp.moreComponents_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_SessionList_item,
{ "SessionInformation", "ulp.SessionInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ReportDataList_item,
{ "ReportData", "ulp.ReportData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_positionData,
{ "positionData", "ulp.positionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_resultCode,
{ "resultCode", "ulp.resultCode",
FT_UINT32, BASE_DEC, VALS(ulp_ResultCode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_timestamp,
{ "timestamp", "ulp.timestamp",
FT_UINT32, BASE_DEC, VALS(ulp_TimeStamp_vals), 0,
NULL, HFILL }},
{ &hf_ulp_ganssSignalsInfo,
{ "ganssSignalsInfo", "ulp.ganssSignalsInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_GANSSsignalsInfo_item,
{ "GANSSSignalsDescription", "ulp.GANSSSignalsDescription_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssId,
{ "ganssId", "ulp.ganssId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_ulp_gANSSSignals,
{ "gANSSSignals", "ulp.gANSSSignals",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_absoluteTime,
{ "absoluteTime", "ulp.absoluteTime",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_ulp_relativeTime,
{ "relativeTime", "ulp.relativeTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31536000", HFILL }},
{ &hf_ulp_notificationMode,
{ "notificationMode", "ulp.notificationMode",
FT_UINT32, BASE_DEC, VALS(ulp_NotificationMode_vals), 0,
NULL, HFILL }},
{ &hf_ulp_e_SLPAddress,
{ "e-SLPAddress", "ulp.e_SLPAddress",
FT_UINT32, BASE_DEC, VALS(ulp_SLPAddress_vals), 0,
"SLPAddress", HFILL }},
{ &hf_ulp_historicReporting,
{ "historicReporting", "ulp.historicReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_protectionLevel,
{ "protectionLevel", "ulp.protectionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_minimumMajorVersion,
{ "minimumMajorVersion", "ulp.minimumMajorVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_allowedReportingType,
{ "allowedReportingType", "ulp.allowedReportingType",
FT_UINT32, BASE_DEC, VALS(ulp_AllowedReportingType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_reportingCriteria,
{ "reportingCriteria", "ulp.reportingCriteria_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_timeWindow,
{ "timeWindow", "ulp.timeWindow_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_maxNumberofReports,
{ "maxNumberofReports", "ulp.maxNumberofReports",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65536", HFILL }},
{ &hf_ulp_minTimeInterval,
{ "minTimeInterval", "ulp.minTimeInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_86400", HFILL }},
{ &hf_ulp_startTime_01,
{ "startTime", "ulp.startTime",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M525600_M1", HFILL }},
{ &hf_ulp_stopTime_01,
{ "stopTime", "ulp.stopTime",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M525599_0", HFILL }},
{ &hf_ulp_protlevel,
{ "protlevel", "ulp.protlevel",
FT_UINT32, BASE_DEC, VALS(ulp_ProtLevel_vals), 0,
NULL, HFILL }},
{ &hf_ulp_basicProtectionParams,
{ "basicProtectionParams", "ulp.basicProtectionParams_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_keyIdentifier,
{ "keyIdentifier", "ulp.keyIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_ulp_basicReplayCounter,
{ "basicReplayCounter", "ulp.basicReplayCounter",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_basicMAC,
{ "basicMAC", "ulp.basicMAC",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_ulp_initialApproximateposition,
{ "initialApproximateposition", "ulp.initialApproximateposition_element",
FT_NONE, BASE_NONE, NULL, 0,
"Position", HFILL }},
{ &hf_ulp_utran_GPSReferenceTimeResult,
{ "utran-GPSReferenceTimeResult", "ulp.utran_GPSReferenceTimeResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_utran_GANSSReferenceTimeResult,
{ "utran-GANSSReferenceTimeResult", "ulp.utran_GANSSReferenceTimeResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_utran_GPSReferenceTimeAssistance,
{ "utran-GPSReferenceTimeAssistance", "ulp.utran_GPSReferenceTimeAssistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_utran_GANSSReferenceTimeAssistance,
{ "utran-GANSSReferenceTimeAssistance", "ulp.utran_GANSSReferenceTimeAssistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_emergencyCallLocation,
{ "emergencyCallLocation", "ulp.emergencyCallLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_serviceCapabilities,
{ "serviceCapabilities", "ulp.serviceCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_supportedBearers,
{ "supportedBearers", "ulp.supportedBearers_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_servicesSupported,
{ "servicesSupported", "ulp.servicesSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_reportingCapabilities,
{ "reportingCapabilities", "ulp.reportingCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportingCap", HFILL }},
{ &hf_ulp_eventTriggerCapabilities,
{ "eventTriggerCapabilities", "ulp.eventTriggerCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sessionCapabilities,
{ "sessionCapabilities", "ulp.sessionCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_periodicTrigger,
{ "periodicTrigger", "ulp.periodicTrigger",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_areaEventTrigger,
{ "areaEventTrigger", "ulp.areaEventTrigger",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_geoAreaShapesSupported,
{ "geoAreaShapesSupported", "ulp.geoAreaShapesSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_maxNumGeoAreaSupported,
{ "maxNumGeoAreaSupported", "ulp.maxNumGeoAreaSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxNumGeoArea", HFILL }},
{ &hf_ulp_maxAreaIdListSupported,
{ "maxAreaIdListSupported", "ulp.maxAreaIdListSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxAreaIdList", HFILL }},
{ &hf_ulp_maxAreaIdSupportedPerList,
{ "maxAreaIdSupportedPerList", "ulp.maxAreaIdSupportedPerList",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxAreaId", HFILL }},
{ &hf_ulp_ellipticalArea_01,
{ "ellipticalArea", "ulp.ellipticalArea",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_polygonArea_01,
{ "polygonArea", "ulp.polygonArea",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_maxNumberTotalSessions,
{ "maxNumberTotalSessions", "ulp.maxNumberTotalSessions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_128", HFILL }},
{ &hf_ulp_maxNumberPeriodicSessions,
{ "maxNumberPeriodicSessions", "ulp.maxNumberPeriodicSessions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_ulp_maxNumberTriggeredSessions,
{ "maxNumberTriggeredSessions", "ulp.maxNumberTriggeredSessions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_32", HFILL }},
{ &hf_ulp_gsm,
{ "gsm", "ulp.gsm",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wcdma,
{ "wcdma", "ulp.wcdma",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_lte,
{ "lte", "ulp.lte",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_cdma,
{ "cdma", "ulp.cdma",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_hprd,
{ "hprd", "ulp.hprd",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_umb,
{ "umb", "ulp.umb",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wlan,
{ "wlan", "ulp.wlan",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wiMAX,
{ "wiMAX", "ulp.wiMAX",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_lpp,
{ "lpp", "ulp.lpp",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_posProtocolVersionRRLP,
{ "posProtocolVersionRRLP", "ulp.posProtocolVersionRRLP_element",
FT_NONE, BASE_NONE, NULL, 0,
"PosProtocolVersion3GPP", HFILL }},
{ &hf_ulp_posProtocolVersionRRC,
{ "posProtocolVersionRRC", "ulp.posProtocolVersionRRC_element",
FT_NONE, BASE_NONE, NULL, 0,
"PosProtocolVersion3GPP", HFILL }},
{ &hf_ulp_posProtocolVersionTIA801,
{ "posProtocolVersionTIA801", "ulp.posProtocolVersionTIA801",
FT_UINT32, BASE_DEC, NULL, 0,
"PosProtocolVersion3GPP2", HFILL }},
{ &hf_ulp_posProtocolVersionLPP,
{ "posProtocolVersionLPP", "ulp.posProtocolVersionLPP_element",
FT_NONE, BASE_NONE, NULL, 0,
"PosProtocolVersion3GPP", HFILL }},
{ &hf_ulp_majorVersionField,
{ "majorVersionField", "ulp.majorVersionField",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_technicalVersionField,
{ "technicalVersionField", "ulp.technicalVersionField",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_editorialVersionField,
{ "editorialVersionField", "ulp.editorialVersionField",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_PosProtocolVersion3GPP2_item,
{ "Supported3GPP2PosProtocolVersion", "ulp.Supported3GPP2PosProtocolVersion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_revisionNumber,
{ "revisionNumber", "ulp.revisionNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_ulp_pointReleaseNumber,
{ "pointReleaseNumber", "ulp.pointReleaseNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_internalEditLevel,
{ "internalEditLevel", "ulp.internalEditLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_gANSSPositionMethods,
{ "gANSSPositionMethods", "ulp.gANSSPositionMethods",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_GANSSPositionMethods_item,
{ "GANSSPositionMethod", "ulp.GANSSPositionMethod_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssSBASid,
{ "ganssSBASid", "ulp.ganssSBASid",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_3", HFILL }},
{ &hf_ulp_gANSSPositioningMethodTypes,
{ "gANSSPositioningMethodTypes", "ulp.gANSSPositioningMethodTypes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_setAssisted,
{ "setAssisted", "ulp.setAssisted",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_setBased,
{ "setBased", "ulp.setBased",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_autonomous,
{ "autonomous", "ulp.autonomous",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssRequestedCommonAssistanceDataList,
{ "ganssRequestedCommonAssistanceDataList", "ulp.ganssRequestedCommonAssistanceDataList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssRequestedGenericAssistanceDataList,
{ "ganssRequestedGenericAssistanceDataList", "ulp.ganssRequestedGenericAssistanceDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_extendedEphemeris,
{ "extendedEphemeris", "ulp.extendedEphemeris_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_extendedEphemerisCheck,
{ "extendedEphemerisCheck", "ulp.extendedEphemerisCheck_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtendedEphCheck", HFILL }},
{ &hf_ulp_ganssReferenceTime,
{ "ganssReferenceTime", "ulp.ganssReferenceTime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssIonosphericModel,
{ "ganssIonosphericModel", "ulp.ganssIonosphericModel",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssAdditionalIonosphericModelForDataID00,
{ "ganssAdditionalIonosphericModelForDataID00", "ulp.ganssAdditionalIonosphericModelForDataID00",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssAdditionalIonosphericModelForDataID11,
{ "ganssAdditionalIonosphericModelForDataID11", "ulp.ganssAdditionalIonosphericModelForDataID11",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssEarthOrientationParameters,
{ "ganssEarthOrientationParameters", "ulp.ganssEarthOrientationParameters",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_GanssRequestedGenericAssistanceDataList_item,
{ "GanssReqGenericData", "ulp.GanssReqGenericData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssRealTimeIntegrity,
{ "ganssRealTimeIntegrity", "ulp.ganssRealTimeIntegrity",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssDifferentialCorrection,
{ "ganssDifferentialCorrection", "ulp.ganssDifferentialCorrection",
FT_BYTES, BASE_NONE, NULL, 0,
"DGANSS_Sig_Id_Req", HFILL }},
{ &hf_ulp_ganssAlmanac,
{ "ganssAlmanac", "ulp.ganssAlmanac",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssNavigationModelData,
{ "ganssNavigationModelData", "ulp.ganssNavigationModelData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssTimeModels,
{ "ganssTimeModels", "ulp.ganssTimeModels",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_ulp_ganssReferenceMeasurementInfo,
{ "ganssReferenceMeasurementInfo", "ulp.ganssReferenceMeasurementInfo",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssDataBits,
{ "ganssDataBits", "ulp.ganssDataBits_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssUTCModel,
{ "ganssUTCModel", "ulp.ganssUTCModel",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssAdditionalDataChoices,
{ "ganssAdditionalDataChoices", "ulp.ganssAdditionalDataChoices_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssAuxiliaryInformation,
{ "ganssAuxiliaryInformation", "ulp.ganssAuxiliaryInformation",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ganssExtendedEphemeris,
{ "ganssExtendedEphemeris", "ulp.ganssExtendedEphemeris_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtendedEphemeris", HFILL }},
{ &hf_ulp_ganssExtendedEphemerisCheck,
{ "ganssExtendedEphemerisCheck", "ulp.ganssExtendedEphemerisCheck_element",
FT_NONE, BASE_NONE, NULL, 0,
"GanssExtendedEphCheck", HFILL }},
{ &hf_ulp_ganssWeek,
{ "ganssWeek", "ulp.ganssWeek",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_ulp_ganssToe,
{ "ganssToe", "ulp.ganssToe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_167", HFILL }},
{ &hf_ulp_t_toeLimit,
{ "t-toeLimit", "ulp.t_toeLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_ulp_satellitesListRelatedDataList,
{ "satellitesListRelatedDataList", "ulp.satellitesListRelatedDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_SatellitesListRelatedDataList_item,
{ "SatellitesListRelatedData", "ulp.SatellitesListRelatedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_iod,
{ "iod", "ulp.iod",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_ganssTODmin,
{ "ganssTODmin", "ulp.ganssTODmin",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_59", HFILL }},
{ &hf_ulp_reqDataBitAssistanceList,
{ "reqDataBitAssistanceList", "ulp.reqDataBitAssistanceList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_gnssSignals,
{ "gnssSignals", "ulp.gnssSignals",
FT_BYTES, BASE_NONE, NULL, 0,
"GANSSSignals", HFILL }},
{ &hf_ulp_ganssDataBitInterval,
{ "ganssDataBitInterval", "ulp.ganssDataBitInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_ulp_ganssDataBitSatList,
{ "ganssDataBitSatList", "ulp.ganssDataBitSatList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ganssDataBitSatList_item,
{ "ganssDataBitSatList item", "ulp.ganssDataBitSatList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_orbitModelID,
{ "orbitModelID", "ulp.orbitModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_ulp_clockModelID,
{ "clockModelID", "ulp.clockModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_ulp_utcModelID,
{ "utcModelID", "ulp.utcModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_ulp_almanacModelID,
{ "almanacModelID", "ulp.almanacModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_ulp_validity,
{ "validity", "ulp.validity",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_256", HFILL }},
{ &hf_ulp_beginTime,
{ "beginTime", "ulp.beginTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSTime", HFILL }},
{ &hf_ulp_endTime,
{ "endTime", "ulp.endTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPSTime", HFILL }},
{ &hf_ulp_beginTime_01,
{ "beginTime", "ulp.beginTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSextEphTime", HFILL }},
{ &hf_ulp_endTime_01,
{ "endTime", "ulp.endTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GANSSextEphTime", HFILL }},
{ &hf_ulp_gPSWeek,
{ "gPSWeek", "ulp.gPSWeek",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_gPSTOWhour,
{ "gPSTOWhour", "ulp.gPSTOWhour",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_167", HFILL }},
{ &hf_ulp_gANSSday,
{ "gANSSday", "ulp.gANSSday",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_ulp_gANSSTODhour,
{ "gANSSTODhour", "ulp.gANSSTODhour",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_23", HFILL }},
{ &hf_ulp_lPPPayload,
{ "lPPPayload", "ulp.lPPPayload",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_lPPPayload_item,
{ "lPPPayload item", "ulp.lPPPayload_item",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tIA801Payload,
{ "tIA801Payload", "ulp.tIA801Payload",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tIA801Payload_item,
{ "tIA801Payload item", "ulp.tIA801Payload_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_60000", HFILL }},
{ &hf_ulp_maj,
{ "maj", "ulp.maj",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_min,
{ "min", "ulp.min",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_servind,
{ "servind", "ulp.servind",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_setSessionID,
{ "setSessionID", "ulp.setSessionID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_slpSessionID,
{ "slpSessionID", "ulp.slpSessionID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_sessionId,
{ "sessionId", "ulp.sessionId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_setId,
{ "setId", "ulp.setId",
FT_UINT32, BASE_DEC, VALS(ulp_SETId_vals), 0,
NULL, HFILL }},
{ &hf_ulp_msisdn,
{ "msisdn", "ulp.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_ulp_mdn,
{ "mdn", "ulp.mdn",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_ulp_minsi,
{ "min", "ulp.min",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_34", HFILL }},
{ &hf_ulp_imsi,
{ "imsi", "ulp.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_ulp_nai,
{ "nai", "ulp.nai",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_1000", HFILL }},
{ &hf_ulp_iPAddress,
{ "iPAddress", "ulp.iPAddress",
FT_UINT32, BASE_DEC, VALS(ulp_IPAddress_vals), 0,
NULL, HFILL }},
{ &hf_ulp_sessionSlpID,
{ "sessionID", "ulp.sessionID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_ulp_slpId,
{ "slpId", "ulp.slpId",
FT_UINT32, BASE_DEC, VALS(ulp_SLPAddress_vals), 0,
"SLPAddress", HFILL }},
{ &hf_ulp_ipv4Address,
{ "ipv4Address", "ulp.ipv4Address",
FT_IPv4, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_ulp_ipv6Address,
{ "ipv6Address", "ulp.ipv6Address",
FT_IPv6, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_ulp_fQDN,
{ "fQDN", "ulp.fQDN",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellInfo,
{ "cellInfo", "ulp.cellInfo",
FT_UINT32, BASE_DEC, VALS(ulp_CellInfo_vals), 0,
NULL, HFILL }},
{ &hf_ulp_status,
{ "status", "ulp.status",
FT_UINT32, BASE_DEC, VALS(ulp_Status_vals), 0,
NULL, HFILL }},
{ &hf_ulp_gsmCell,
{ "gsmCell", "ulp.gsmCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"GsmCellInformation", HFILL }},
{ &hf_ulp_wcdmaCell,
{ "wcdmaCell", "ulp.wcdmaCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"WcdmaCellInformation", HFILL }},
{ &hf_ulp_cdmaCell,
{ "cdmaCell", "ulp.cdmaCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"CdmaCellInformation", HFILL }},
{ &hf_ulp_ver2_CellInfo_extension,
{ "ver2-CellInfo-extension", "ulp.ver2_CellInfo_extension",
FT_UINT32, BASE_DEC, VALS(ulp_Ver2_CellInfo_extension_vals), 0,
NULL, HFILL }},
{ &hf_ulp_timestamp_01,
{ "timestamp", "ulp.timestamp",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_ulp_positionEstimate,
{ "positionEstimate", "ulp.positionEstimate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_latitudeSign,
{ "latitudeSign", "ulp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(ulp_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_ulp_latitude,
{ "latitude", "ulp.latitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_ulp_longitude,
{ "longitude", "ulp.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_ulp_uncertainty,
{ "uncertainty", "ulp.uncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_uncertaintySemiMajor,
{ "uncertaintySemiMajor", "ulp.uncertaintySemiMajor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_uncertaintySemiMinor,
{ "uncertaintySemiMinor", "ulp.uncertaintySemiMinor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_orientationMajorAxis,
{ "orientationMajorAxis", "ulp.orientationMajorAxis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_180", HFILL }},
{ &hf_ulp_confidence,
{ "confidence", "ulp.confidence",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_ulp_altitudeInfo,
{ "altitudeInfo", "ulp.altitudeInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_altitudeDirection,
{ "altitudeDirection", "ulp.altitudeDirection",
FT_UINT32, BASE_DEC, VALS(ulp_T_altitudeDirection_vals), 0,
NULL, HFILL }},
{ &hf_ulp_altitude,
{ "altitude", "ulp.altitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_ulp_altUncertainty,
{ "altUncertainty", "ulp.altUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_refNID_01,
{ "refNID", "ulp.refNID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refSID_01,
{ "refSID", "ulp.refSID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_ulp_refBASELAT,
{ "refBASELAT", "ulp.refBASELAT",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4194303", HFILL }},
{ &hf_ulp_reBASELONG,
{ "reBASELONG", "ulp.reBASELONG",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_ulp_refREFPN,
{ "refREFPN", "ulp.refREFPN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_ulp_refWeekNumber,
{ "refWeekNumber", "ulp.refWeekNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_refSeconds,
{ "refSeconds", "ulp.refSeconds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4194303", HFILL }},
{ &hf_ulp_nMR,
{ "nMR", "ulp.nMR",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tA,
{ "tA", "ulp.tA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_frequencyInfo,
{ "frequencyInfo", "ulp.frequencyInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_primaryScramblingCode,
{ "primaryScramblingCode", "ulp.primaryScramblingCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_ulp_measuredResultsList,
{ "measuredResultsList", "ulp.measuredResultsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellParametersId,
{ "cellParametersId", "ulp.cellParametersId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_timingAdvance,
{ "timingAdvance", "ulp.timingAdvance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tA_01,
{ "tA", "ulp.tA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_ulp_tAResolution,
{ "tAResolution", "ulp.tAResolution",
FT_UINT32, BASE_DEC, VALS(ulp_TAResolution_vals), 0,
NULL, HFILL }},
{ &hf_ulp_chipRate,
{ "chipRate", "ulp.chipRate",
FT_UINT32, BASE_DEC, VALS(ulp_ChipRate_vals), 0,
NULL, HFILL }},
{ &hf_ulp_modeSpecificFrequencyInfo,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_FrequencySpecificInfo_vals), 0,
"FrequencySpecificInfo", HFILL }},
{ &hf_ulp_fdd_fr,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"FrequencyInfoFDD", HFILL }},
{ &hf_ulp_tdd_fr,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"FrequencyInfoTDD", HFILL }},
{ &hf_ulp_uarfcn_UL,
{ "uarfcn-UL", "ulp.uarfcn_UL",
FT_UINT32, BASE_DEC, NULL, 0,
"UARFCN", HFILL }},
{ &hf_ulp_uarfcn_DL,
{ "uarfcn-DL", "ulp.uarfcn_DL",
FT_UINT32, BASE_DEC, NULL, 0,
"UARFCN", HFILL }},
{ &hf_ulp_uarfcn_Nt,
{ "uarfcn-Nt", "ulp.uarfcn_Nt",
FT_UINT32, BASE_DEC, NULL, 0,
"UARFCN", HFILL }},
{ &hf_ulp_NMR_item,
{ "NMRelement", "ulp.NMRelement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_aRFCN,
{ "aRFCN", "ulp.aRFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_bSIC,
{ "bSIC", "ulp.bSIC",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_rxLev,
{ "rxLev", "ulp.rxLev",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_MeasuredResultsList_item,
{ "MeasuredResults", "ulp.MeasuredResults_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_utra_CarrierRSSI,
{ "utra-CarrierRSSI", "ulp.utra_CarrierRSSI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellMeasuredResultsList,
{ "cellMeasuredResultsList", "ulp.cellMeasuredResultsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_CellMeasuredResultsList_item,
{ "CellMeasuredResults", "ulp.CellMeasuredResults_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellIdentity,
{ "cellIdentity", "ulp.cellIdentity",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_268435455", HFILL }},
{ &hf_ulp_modeSpecificInfo,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_T_modeSpecificInfo_vals), 0,
NULL, HFILL }},
{ &hf_ulp_fdd,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_primaryCPICH_Info,
{ "primaryCPICH-Info", "ulp.primaryCPICH_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cpich_Ec_N0,
{ "cpich-Ec-N0", "ulp.cpich_Ec_N0",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cpich_RSCP,
{ "cpich-RSCP", "ulp.cpich_RSCP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_pathloss,
{ "pathloss", "ulp.pathloss",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_tdd,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellParametersID,
{ "cellParametersID", "ulp.cellParametersID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_proposedTGSN,
{ "proposedTGSN", "ulp.proposedTGSN",
FT_UINT32, BASE_DEC, NULL, 0,
"TGSN", HFILL }},
{ &hf_ulp_primaryCCPCH_RSCP,
{ "primaryCCPCH-RSCP", "ulp.primaryCCPCH_RSCP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_timeslotISCP_List,
{ "timeslotISCP-List", "ulp.timeslotISCP_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_TimeslotISCP_List_item,
{ "TimeslotISCP", "ulp.TimeslotISCP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_horacc,
{ "horacc", "ulp.horacc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_veracc,
{ "veracc", "ulp.veracc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_maxLocAge,
{ "maxLocAge", "ulp.maxLocAge",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_delay,
{ "delay", "ulp.delay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_ulp_horvel,
{ "horvel", "ulp.horvel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_horandvervel,
{ "horandvervel", "ulp.horandvervel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_horveluncert,
{ "horveluncert", "ulp.horveluncert_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_horandveruncert,
{ "horandveruncert", "ulp.horandveruncert_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_bearing,
{ "bearing", "ulp.bearing",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_9", HFILL }},
{ &hf_ulp_horspeed,
{ "horspeed", "ulp.horspeed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_ulp_verdirect,
{ "verdirect", "ulp.verdirect",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1", HFILL }},
{ &hf_ulp_verspeed,
{ "verspeed", "ulp.verspeed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_ulp_uncertspeed,
{ "uncertspeed", "ulp.uncertspeed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_ulp_horuncertspeed,
{ "horuncertspeed", "ulp.horuncertspeed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_ulp_veruncertspeed,
{ "veruncertspeed", "ulp.veruncertspeed",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_ulp_MultipleLocationIds_item,
{ "LocationIdData", "ulp.LocationIdData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_relativetimestamp,
{ "relativetimestamp", "ulp.relativetimestamp",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeTime", HFILL }},
{ &hf_ulp_servingFlag,
{ "servingFlag", "ulp.servingFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wLAN,
{ "wLAN", "ulp.wLAN",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_supportedWLANInfo,
{ "supportedWLANInfo", "ulp.supportedWLANInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_supportedWLANApsList,
{ "supportedWLANApsList", "ulp.supportedWLANApsList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_gSM,
{ "gSM", "ulp.gSM",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wCDMA,
{ "wCDMA", "ulp.wCDMA",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_supportedWCDMAInfo,
{ "supportedWCDMAInfo", "ulp.supportedWCDMAInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cDMA,
{ "cDMA", "ulp.cDMA",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_hRDP,
{ "hRDP", "ulp.hRDP",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_uMB,
{ "uMB", "ulp.uMB",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_lTE,
{ "lTE", "ulp.lTE",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_wIMAX,
{ "wIMAX", "ulp.wIMAX",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_historic,
{ "historic", "ulp.historic",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_nonServing,
{ "nonServing", "ulp.nonServing",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_uTRANGPSReferenceTime,
{ "uTRANGPSReferenceTime", "ulp.uTRANGPSReferenceTime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_uTRANGANSSReferenceTime,
{ "uTRANGANSSReferenceTime", "ulp.uTRANGANSSReferenceTime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apTP,
{ "apTP", "ulp.apTP",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apAG,
{ "apAG", "ulp.apAG",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apSN,
{ "apSN", "ulp.apSN",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apDevType,
{ "apDevType", "ulp.apDevType",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apRSSI,
{ "apRSSI", "ulp.apRSSI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apChanFreq,
{ "apChanFreq", "ulp.apChanFreq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apRTD,
{ "apRTD", "ulp.apRTD",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_setTP,
{ "setTP", "ulp.setTP",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_setAG,
{ "setAG", "ulp.setAG",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_setSN,
{ "setSN", "ulp.setSN",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_setRSSI,
{ "setRSSI", "ulp.setRSSI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apRepLoc,
{ "apRepLoc", "ulp.apRepLoc",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_supportedWLANApDataList,
{ "supportedWLANApDataList", "ulp.supportedWLANApDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxWLANApDataSize_OF_SupportedWLANApData", HFILL }},
{ &hf_ulp_supportedWLANApDataList_item,
{ "SupportedWLANApData", "ulp.SupportedWLANApData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_supportedWLANapsChannel11a,
{ "supportedWLANapsChannel11a", "ulp.supportedWLANapsChannel11a_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_supportedWLANapsChannel11bg,
{ "supportedWLANapsChannel11bg", "ulp.supportedWLANapsChannel11bg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ch34,
{ "ch34", "ulp.ch34",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch36,
{ "ch36", "ulp.ch36",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch38,
{ "ch38", "ulp.ch38",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch40,
{ "ch40", "ulp.ch40",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch42,
{ "ch42", "ulp.ch42",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch44,
{ "ch44", "ulp.ch44",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch46,
{ "ch46", "ulp.ch46",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch48,
{ "ch48", "ulp.ch48",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch52,
{ "ch52", "ulp.ch52",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch56,
{ "ch56", "ulp.ch56",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch60,
{ "ch60", "ulp.ch60",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch64,
{ "ch64", "ulp.ch64",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch149,
{ "ch149", "ulp.ch149",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch153,
{ "ch153", "ulp.ch153",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch157,
{ "ch157", "ulp.ch157",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch161,
{ "ch161", "ulp.ch161",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch1,
{ "ch1", "ulp.ch1",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch2,
{ "ch2", "ulp.ch2",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch3,
{ "ch3", "ulp.ch3",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch4,
{ "ch4", "ulp.ch4",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch5,
{ "ch5", "ulp.ch5",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch6,
{ "ch6", "ulp.ch6",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch7,
{ "ch7", "ulp.ch7",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch8,
{ "ch8", "ulp.ch8",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch9,
{ "ch9", "ulp.ch9",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch10,
{ "ch10", "ulp.ch10",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch11,
{ "ch11", "ulp.ch11",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch12,
{ "ch12", "ulp.ch12",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch13,
{ "ch13", "ulp.ch13",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_ch14,
{ "ch14", "ulp.ch14",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_apDevType_01,
{ "apDevType", "ulp.apDevType",
FT_UINT32, BASE_DEC, VALS(ulp_T_apDevType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_mRL,
{ "mRL", "ulp.mRL",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_hrpdCell,
{ "hrpdCell", "ulp.hrpdCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"HrpdCellInformation", HFILL }},
{ &hf_ulp_umbCell,
{ "umbCell", "ulp.umbCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"UmbCellInformation", HFILL }},
{ &hf_ulp_lteCell,
{ "lteCell", "ulp.lteCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"LteCellInformation", HFILL }},
{ &hf_ulp_wlanAP,
{ "wlanAP", "ulp.wlanAP_element",
FT_NONE, BASE_NONE, NULL, 0,
"WlanAPInformation", HFILL }},
{ &hf_ulp_wimaxBS,
{ "wimaxBS", "ulp.wimaxBS_element",
FT_NONE, BASE_NONE, NULL, 0,
"WimaxBSInformation", HFILL }},
{ &hf_ulp_cellGlobalIdEUTRA,
{ "cellGlobalIdEUTRA", "ulp.cellGlobalIdEUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_physCellId,
{ "physCellId", "ulp.physCellId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_trackingAreaCode,
{ "trackingAreaCode", "ulp.trackingAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_rsrpResult,
{ "rsrpResult", "ulp.rsrpResult",
FT_UINT32, BASE_DEC, NULL, 0,
"RSRP_Range", HFILL }},
{ &hf_ulp_rsrqResult,
{ "rsrqResult", "ulp.rsrqResult",
FT_UINT32, BASE_DEC, NULL, 0,
"RSRQ_Range", HFILL }},
{ &hf_ulp_tA_02,
{ "tA", "ulp.tA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1282", HFILL }},
{ &hf_ulp_measResultListEUTRA,
{ "measResultListEUTRA", "ulp.measResultListEUTRA",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_earfcn,
{ "earfcn", "ulp.earfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_MeasResultListEUTRA_item,
{ "MeasResultEUTRA", "ulp.MeasResultEUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cgi_Info,
{ "cgi-Info", "ulp.cgi_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellGlobalId,
{ "cellGlobalId", "ulp.cellGlobalId_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA", HFILL }},
{ &hf_ulp_measResult,
{ "measResult", "ulp.measResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_plmn_Identity,
{ "plmn-Identity", "ulp.plmn_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_cellIdentity_01,
{ "cellIdentity", "ulp.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_mcc,
{ "mcc", "ulp.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_mnc,
{ "mnc", "ulp.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_MCC_item,
{ "MCC-MNC-Digit", "ulp.MCC_MNC_Digit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_MNC_item,
{ "MCC-MNC-Digit", "ulp.MCC_MNC_Digit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_apTransmitPower,
{ "apTransmitPower", "ulp.apTransmitPower",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_apAntennaGain,
{ "apAntennaGain", "ulp.apAntennaGain",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_apSignaltoNoise,
{ "apSignaltoNoise", "ulp.apSignaltoNoise",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_apDeviceType,
{ "apDeviceType", "ulp.apDeviceType",
FT_UINT32, BASE_DEC, VALS(ulp_T_apDeviceType_vals), 0,
NULL, HFILL }},
{ &hf_ulp_apSignalStrength,
{ "apSignalStrength", "ulp.apSignalStrength",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_apChannelFrequency,
{ "apChannelFrequency", "ulp.apChannelFrequency",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_256", HFILL }},
{ &hf_ulp_apRoundTripDelay,
{ "apRoundTripDelay", "ulp.apRoundTripDelay_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTD", HFILL }},
{ &hf_ulp_setTransmitPower,
{ "setTransmitPower", "ulp.setTransmitPower",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_setAntennaGain,
{ "setAntennaGain", "ulp.setAntennaGain",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_setSignaltoNoise,
{ "setSignaltoNoise", "ulp.setSignaltoNoise",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_setSignalStrength,
{ "setSignalStrength", "ulp.setSignalStrength",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_ulp_apReportedLocation,
{ "apReportedLocation", "ulp.apReportedLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportedLocation", HFILL }},
{ &hf_ulp_rTDValue,
{ "rTDValue", "ulp.rTDValue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777216", HFILL }},
{ &hf_ulp_rTDUnits,
{ "rTDUnits", "ulp.rTDUnits",
FT_UINT32, BASE_DEC, VALS(ulp_RTDUnits_vals), 0,
NULL, HFILL }},
{ &hf_ulp_rTDAccuracy,
{ "rTDAccuracy", "ulp.rTDAccuracy",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_locationEncodingDescriptor,
{ "locationEncodingDescriptor", "ulp.locationEncodingDescriptor",
FT_UINT32, BASE_DEC, VALS(ulp_LocationEncodingDescriptor_vals), 0,
NULL, HFILL }},
{ &hf_ulp_locationData,
{ "locationData", "ulp.locationData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_locationAccuracy,
{ "locationAccuracy", "ulp.locationAccuracy",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_ulp_locationValue,
{ "locationValue", "ulp.locationValue",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_128", HFILL }},
{ &hf_ulp_wimaxBsID,
{ "wimaxBsID", "ulp.wimaxBsID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_wimaxRTD,
{ "wimaxRTD", "ulp.wimaxRTD_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_wimaxNMRList,
{ "wimaxNMRList", "ulp.wimaxNMRList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_rTD,
{ "rTD", "ulp.rTD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ulp_rTDstd,
{ "rTDstd", "ulp.rTDstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_WimaxNMRList_item,
{ "WimaxNMR", "ulp.WimaxNMR_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_relDelay,
{ "relDelay", "ulp.relDelay",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_ulp_relDelaystd,
{ "relDelaystd", "ulp.relDelaystd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_rSSI,
{ "rSSI", "ulp.rSSI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_rSSIstd,
{ "rSSIstd", "ulp.rSSIstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_bSTxPower,
{ "bSTxPower", "ulp.bSTxPower",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_cINR,
{ "cINR", "ulp.cINR",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ulp_cINRstd,
{ "cINRstd", "ulp.cINRstd",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_ulp_bSLocation,
{ "bSLocation", "ulp.bSLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportedLocation", HFILL }},
{ &hf_ulp_utran_GPSReferenceTime,
{ "utran-GPSReferenceTime", "ulp.utran_GPSReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_gpsReferenceTimeUncertainty,
{ "gpsReferenceTimeUncertainty", "ulp.gpsReferenceTimeUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_utranGPSDriftRate,
{ "utranGPSDriftRate", "ulp.utranGPSDriftRate",
FT_UINT32, BASE_DEC, VALS(ulp_UTRANGPSDriftRate_vals), 0,
NULL, HFILL }},
{ &hf_ulp_utran_GPSTimingOfCell,
{ "utran-GPSTimingOfCell", "ulp.utran_GPSTimingOfCell_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ms_part,
{ "ms-part", "ulp.ms_part",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_ulp_ls_part,
{ "ls-part", "ulp.ls_part",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_ulp_modeSpecificInfo_01,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_T_modeSpecificInfo_01_vals), 0,
"T_modeSpecificInfo_01", HFILL }},
{ &hf_ulp_fdd_01,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_01", HFILL }},
{ &hf_ulp_referenceIdentity,
{ "referenceIdentity", "ulp.referenceIdentity_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrimaryCPICH_Info", HFILL }},
{ &hf_ulp_tdd_01,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_01", HFILL }},
{ &hf_ulp_referenceIdentity_01,
{ "referenceIdentity", "ulp.referenceIdentity",
FT_UINT32, BASE_DEC, NULL, 0,
"CellParametersID", HFILL }},
{ &hf_ulp_sfn,
{ "sfn", "ulp.sfn",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_ulp_set_GPSTimingOfCell,
{ "set-GPSTimingOfCell", "ulp.set_GPSTimingOfCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_set_GPSTimingOfCell", HFILL }},
{ &hf_ulp_ms_part_01,
{ "ms-part", "ulp.ms_part",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_ulp_modeSpecificInfo_02,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_T_modeSpecificInfo_02_vals), 0,
"T_modeSpecificInfo_02", HFILL }},
{ &hf_ulp_fdd_02,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_02", HFILL }},
{ &hf_ulp_tdd_02,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_02", HFILL }},
{ &hf_ulp_ganssDay,
{ "ganssDay", "ulp.ganssDay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_ulp_ganssTimeID,
{ "ganssTimeID", "ulp.ganssTimeID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_ulp_utran_GANSSReferenceTime,
{ "utran-GANSSReferenceTime", "ulp.utran_GANSSReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_utranGANSSDriftRate,
{ "utranGANSSDriftRate", "ulp.utranGANSSDriftRate",
FT_UINT32, BASE_DEC, VALS(ulp_UTRANGANSSDriftRate_vals), 0,
NULL, HFILL }},
{ &hf_ulp_ganssTOD,
{ "ganssTOD", "ulp.ganssTOD",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_86399", HFILL }},
{ &hf_ulp_utran_GANSSTimingOfCell,
{ "utran-GANSSTimingOfCell", "ulp.utran_GANSSTimingOfCell",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3999999", HFILL }},
{ &hf_ulp_modeSpecificInfo_03,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_T_modeSpecificInfo_03_vals), 0,
"T_modeSpecificInfo_03", HFILL }},
{ &hf_ulp_fdd_03,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_03", HFILL }},
{ &hf_ulp_tdd_03,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_03", HFILL }},
{ &hf_ulp_ganss_TODUncertainty,
{ "ganss-TODUncertainty", "ulp.ganss_TODUncertainty",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ulp_set_GANSSReferenceTime,
{ "set-GANSSReferenceTime", "ulp.set_GANSSReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_set_GANSSTimingOfCell,
{ "set-GANSSTimingOfCell", "ulp.set_GANSSTimingOfCell_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_set_GANSSTimingOfCell", HFILL }},
{ &hf_ulp_ms_part_02,
{ "ms-part", "ulp.ms_part",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_80", HFILL }},
{ &hf_ulp_modeSpecificInfo_04,
{ "modeSpecificInfo", "ulp.modeSpecificInfo",
FT_UINT32, BASE_DEC, VALS(ulp_T_modeSpecificInfo_04_vals), 0,
"T_modeSpecificInfo_04", HFILL }},
{ &hf_ulp_fdd_04,
{ "fdd", "ulp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_04", HFILL }},
{ &hf_ulp_tdd_04,
{ "tdd", "ulp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_04", HFILL }},
{ &hf_ulp_gps,
{ "gps", "ulp.gps",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_galileo,
{ "galileo", "ulp.galileo",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_sbas,
{ "sbas", "ulp.sbas",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_modernized_gps,
{ "modernized-gps", "ulp.modernized_gps",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_qzss,
{ "qzss", "ulp.qzss",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_glonass,
{ "glonass", "ulp.glonass",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_rAND,
{ "rAND", "ulp.rAND",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_ulp_slpFQDN,
{ "slpFQDN", "ulp.slpFQDN",
FT_STRING, BASE_NONE, NULL, 0,
"FQDN", HFILL }},
{ &hf_ulp_ThirdParty_item,
{ "ThirdPartyID", "ulp.ThirdPartyID",
FT_UINT32, BASE_DEC, VALS(ulp_ThirdPartyID_vals), 0,
NULL, HFILL }},
{ &hf_ulp_logicalName,
{ "logicalName", "ulp.logicalName",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_1000", HFILL }},
{ &hf_ulp_emailaddr,
{ "emailaddr", "ulp.emailaddr",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_1000", HFILL }},
{ &hf_ulp_sip_uri,
{ "sip-uri", "ulp.sip_uri",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_ims_public_identity,
{ "ims-public-identity", "ulp.ims_public_identity",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_min_01,
{ "min", "ulp.min",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_34", HFILL }},
{ &hf_ulp_uri,
{ "uri", "ulp.uri",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_appProvider,
{ "appProvider", "ulp.appProvider",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_24", HFILL }},
{ &hf_ulp_appName,
{ "appName", "ulp.appName",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_32", HFILL }},
{ &hf_ulp_appVersion,
{ "appVersion", "ulp.appVersion",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_8", HFILL }},
{ &hf_ulp_minInt,
{ "minInt", "ulp.minInt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_3600", HFILL }},
{ &hf_ulp_maxInt,
{ "maxInt", "ulp.maxInt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1440", HFILL }},
{ &hf_ulp_repMode_01,
{ "repMode", "ulp.repMode_element",
FT_NONE, BASE_NONE, NULL, 0,
"RepMode_cap", HFILL }},
{ &hf_ulp_batchRepCap,
{ "batchRepCap", "ulp.batchRepCap_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_realtime,
{ "realtime", "ulp.realtime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_quasirealtime,
{ "quasirealtime", "ulp.quasirealtime",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_batch,
{ "batch", "ulp.batch",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_report_position,
{ "report-position", "ulp.report_position",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_report_measurements,
{ "report-measurements", "ulp.report_measurements",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ulp_max_num_positions,
{ "max-num-positions", "ulp.max_num_positions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_ulp_max_num_measurements,
{ "max-num-measurements", "ulp.max_num_measurements",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1024", HFILL }},
{ &hf_ulp_latitudeSign_01,
{ "latitudeSign", "ulp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(ulp_T_latitudeSign_01_vals), 0,
"T_latitudeSign_01", HFILL }},
{ &hf_ulp_coordinate,
{ "coordinate", "ulp.coordinate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_radius,
{ "radius", "ulp.radius",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_radius_min,
{ "radius-min", "ulp.radius_min",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_radius_max,
{ "radius-max", "ulp.radius_max",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1500000", HFILL }},
{ &hf_ulp_semiMajor,
{ "semiMajor", "ulp.semiMajor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_semiMajor_min,
{ "semiMajor-min", "ulp.semiMajor_min",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_semiMajor_max,
{ "semiMajor-max", "ulp.semiMajor_max",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1500000", HFILL }},
{ &hf_ulp_semiMinor,
{ "semiMinor", "ulp.semiMinor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_semiMinor_min,
{ "semiMinor-min", "ulp.semiMinor_min",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1000000", HFILL }},
{ &hf_ulp_semiMinor_max,
{ "semiMinor-max", "ulp.semiMinor_max",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_1500000", HFILL }},
{ &hf_ulp_angle,
{ "angle", "ulp.angle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_ulp_polygonDescription,
{ "polygonDescription", "ulp.polygonDescription",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_polygonHysteresis,
{ "polygonHysteresis", "ulp.polygonHysteresis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100000", HFILL }},
{ &hf_ulp_PolygonDescription_item,
{ "Coordinate", "ulp.Coordinate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal1,
{ "signal1", "ulp.signal1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal2,
{ "signal2", "ulp.signal2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal3,
{ "signal3", "ulp.signal3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal4,
{ "signal4", "ulp.signal4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal5,
{ "signal5", "ulp.signal5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal6,
{ "signal6", "ulp.signal6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal7,
{ "signal7", "ulp.signal7",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_ulp_GANSSSignals_signal8,
{ "signal8", "ulp.signal8",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
#line 99 "../../asn1/ulp/packet-ulp-template.c"
};
static gint *ett[] = {
&ett_ulp,
#line 1 "../../asn1/ulp/packet-ulp-ettarr.c"
&ett_ulp_ULP_PDU,
&ett_ulp_UlpMessage,
&ett_ulp_SUPLINIT,
&ett_ulp_Notification,
&ett_ulp_SUPLSTART,
&ett_ulp_SETCapabilities,
&ett_ulp_PosTechnology,
&ett_ulp_PosProtocol,
&ett_ulp_SUPLRESPONSE,
&ett_ulp_SETAuthKey,
&ett_ulp_SUPLPOSINIT,
&ett_ulp_RequestedAssistData,
&ett_ulp_NavigationModel,
&ett_ulp_SatelliteInfo,
&ett_ulp_SatelliteInfoElement,
&ett_ulp_SUPLPOS,
&ett_ulp_PosPayLoad,
&ett_ulp_SUPLEND,
&ett_ulp_SUPLAUTHREQ,
&ett_ulp_SUPLAUTHRESP,
&ett_ulp_Ver2_SUPLNOTIFY,
&ett_ulp_Ver2_SUPLNOTIFYRESPONSE,
&ett_ulp_Ver2_SUPLSETINIT,
&ett_ulp_Ver2_SUPLTRIGGEREDSTART,
&ett_ulp_TriggerParams,
&ett_ulp_PeriodicParams,
&ett_ulp_AreaEventParams,
&ett_ulp_SEQUENCE_SIZE_1_maxAreaIdList_OF_AreaIdList,
&ett_ulp_RepeatedReportingParams,
&ett_ulp_GeographicTargetAreaList,
&ett_ulp_GeographicTargetArea,
&ett_ulp_AreaIdList,
&ett_ulp_AreaIdSet,
&ett_ulp_AreaId,
&ett_ulp_GSMAreaId,
&ett_ulp_WCDMAAreaId,
&ett_ulp_CDMAAreaId,
&ett_ulp_HRPDAreaId,
&ett_ulp_UMBAreaId,
&ett_ulp_LTEAreaId,
&ett_ulp_WLANAreaId,
&ett_ulp_WimaxAreaId,
&ett_ulp_GeoAreaMappingList,
&ett_ulp_Ver2_SUPLTRIGGEREDRESPONSE,
&ett_ulp_ReportingMode,
&ett_ulp_BatchRepConditions,
&ett_ulp_BatchRepType,
&ett_ulp_Ver2_SUPLREPORT,
&ett_ulp_SessionList,
&ett_ulp_SessionInformation,
&ett_ulp_ReportDataList,
&ett_ulp_ReportData,
&ett_ulp_PositionData,
&ett_ulp_GANSSsignalsInfo,
&ett_ulp_GANSSSignalsDescription,
&ett_ulp_TimeStamp,
&ett_ulp_Ver2_SUPLTRIGGEREDSTOP,
&ett_ulp_Ver2_SUPL_INIT_extension,
&ett_ulp_HistoricReporting,
&ett_ulp_ReportingCriteria,
&ett_ulp_TimeWindow,
&ett_ulp_ProtectionLevel,
&ett_ulp_BasicProtectionParams,
&ett_ulp_Ver2_SUPL_START_extension,
&ett_ulp_Ver2_SUPL_RESPONSE_extension,
&ett_ulp_Ver2_SUPL_POS_INIT_extension,
&ett_ulp_Ver2_SUPL_POS_extension,
&ett_ulp_Ver2_SUPL_END_extension,
&ett_ulp_Ver2_Notification_extension,
&ett_ulp_Ver2_SETCapabilities_extension,
&ett_ulp_ServiceCapabilities,
&ett_ulp_ServicesSupported,
&ett_ulp_EventTriggerCapabilities,
&ett_ulp_GeoAreaShapesSupported,
&ett_ulp_SessionCapabilities,
&ett_ulp_SupportedBearers,
&ett_ulp_Ver2_PosProtocol_extension,
&ett_ulp_PosProtocolVersion3GPP,
&ett_ulp_PosProtocolVersion3GPP2,
&ett_ulp_Supported3GPP2PosProtocolVersion,
&ett_ulp_Ver2_PosTechnology_extension,
&ett_ulp_GANSSPositionMethods,
&ett_ulp_GANSSPositionMethod,
&ett_ulp_GANSSPositioningMethodTypes,
&ett_ulp_Ver2_RequestedAssistData_extension,
&ett_ulp_GanssRequestedCommonAssistanceDataList,
&ett_ulp_GanssRequestedGenericAssistanceDataList,
&ett_ulp_GanssReqGenericData,
&ett_ulp_GanssNavigationModelData,
&ett_ulp_SatellitesListRelatedDataList,
&ett_ulp_SatellitesListRelatedData,
&ett_ulp_GanssDataBits,
&ett_ulp_ReqDataBitAssistanceList,
&ett_ulp_T_ganssDataBitSatList,
&ett_ulp_GanssAdditionalDataChoices,
&ett_ulp_ExtendedEphemeris,
&ett_ulp_ExtendedEphCheck,
&ett_ulp_GanssExtendedEphCheck,
&ett_ulp_GPSTime,
&ett_ulp_GANSSextEphTime,
&ett_ulp_Ver2_PosPayLoad_extension,
&ett_ulp_T_lPPPayload,
&ett_ulp_T_tIA801Payload,
&ett_ulp_Version,
&ett_ulp_SessionID,
&ett_ulp_SetSessionID,
&ett_ulp_SETId,
&ett_ulp_SlpSessionID,
&ett_ulp_IPAddress,
&ett_ulp_SLPAddress,
&ett_ulp_LocationId,
&ett_ulp_CellInfo,
&ett_ulp_Position,
&ett_ulp_PositionEstimate,
&ett_ulp_T_uncertainty,
&ett_ulp_AltitudeInfo,
&ett_ulp_CdmaCellInformation,
&ett_ulp_GsmCellInformation,
&ett_ulp_WcdmaCellInformation,
&ett_ulp_TimingAdvance,
&ett_ulp_FrequencyInfo,
&ett_ulp_FrequencySpecificInfo,
&ett_ulp_FrequencyInfoFDD,
&ett_ulp_FrequencyInfoTDD,
&ett_ulp_NMR,
&ett_ulp_NMRelement,
&ett_ulp_MeasuredResultsList,
&ett_ulp_MeasuredResults,
&ett_ulp_CellMeasuredResultsList,
&ett_ulp_CellMeasuredResults,
&ett_ulp_T_modeSpecificInfo,
&ett_ulp_T_fdd,
&ett_ulp_T_tdd,
&ett_ulp_TimeslotISCP_List,
&ett_ulp_PrimaryCPICH_Info,
&ett_ulp_QoP,
&ett_ulp_Velocity,
&ett_ulp_Horvel,
&ett_ulp_Horandvervel,
&ett_ulp_Horveluncert,
&ett_ulp_Horandveruncert,
&ett_ulp_MultipleLocationIds,
&ett_ulp_LocationIdData,
&ett_ulp_SupportedNetworkInformation,
&ett_ulp_SupportedWLANInfo,
&ett_ulp_SupportedWLANApsList,
&ett_ulp_SEQUENCE_SIZE_1_maxWLANApDataSize_OF_SupportedWLANApData,
&ett_ulp_SupportedWLANApsChannel11a,
&ett_ulp_SupportedWLANApsChannel11bg,
&ett_ulp_SupportedWLANApData,
&ett_ulp_SupportedWCDMAInfo,
&ett_ulp_Ver2_CellInfo_extension,
&ett_ulp_HrpdCellInformation,
&ett_ulp_UmbCellInformation,
&ett_ulp_LteCellInformation,
&ett_ulp_MeasResultListEUTRA,
&ett_ulp_MeasResultEUTRA,
&ett_ulp_T_cgi_Info,
&ett_ulp_T_measResult,
&ett_ulp_CellGlobalIdEUTRA,
&ett_ulp_PLMN_Identity,
&ett_ulp_MCC,
&ett_ulp_MNC,
&ett_ulp_WlanAPInformation,
&ett_ulp_RTD,
&ett_ulp_ReportedLocation,
&ett_ulp_LocationData,
&ett_ulp_WimaxBSInformation,
&ett_ulp_WimaxBsID,
&ett_ulp_WimaxRTD,
&ett_ulp_WimaxNMRList,
&ett_ulp_WimaxNMR,
&ett_ulp_UTRAN_GPSReferenceTimeAssistance,
&ett_ulp_UTRAN_GPSReferenceTime,
&ett_ulp_T_utran_GPSTimingOfCell,
&ett_ulp_T_modeSpecificInfo_01,
&ett_ulp_T_fdd_01,
&ett_ulp_T_tdd_01,
&ett_ulp_UTRAN_GPSReferenceTimeResult,
&ett_ulp_T_set_GPSTimingOfCell,
&ett_ulp_T_modeSpecificInfo_02,
&ett_ulp_T_fdd_02,
&ett_ulp_T_tdd_02,
&ett_ulp_UTRAN_GANSSReferenceTimeAssistance,
&ett_ulp_UTRAN_GANSSReferenceTime,
&ett_ulp_T_modeSpecificInfo_03,
&ett_ulp_T_fdd_03,
&ett_ulp_T_tdd_03,
&ett_ulp_UTRAN_GANSSReferenceTimeResult,
&ett_ulp_SET_GANSSReferenceTime,
&ett_ulp_T_set_GANSSTimingOfCell,
&ett_ulp_T_modeSpecificInfo_04,
&ett_ulp_T_fdd_04,
&ett_ulp_T_tdd_04,
&ett_ulp_GNSSPosTechnology,
&ett_ulp_GANSSSignals,
&ett_ulp_SPCTID,
&ett_ulp_ThirdParty,
&ett_ulp_ThirdPartyID,
&ett_ulp_ApplicationID,
&ett_ulp_ReportingCap,
&ett_ulp_RepMode_cap,
&ett_ulp_BatchRepCap,
&ett_ulp_Coordinate,
&ett_ulp_CircularArea,
&ett_ulp_EllipticalArea,
&ett_ulp_PolygonArea,
&ett_ulp_PolygonDescription,
#line 105 "../../asn1/ulp/packet-ulp-template.c"
};
module_t *ulp_module;
proto_ulp = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("ulp", dissect_ulp_tcp, proto_ulp);
proto_register_field_array(proto_ulp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ulp_module = prefs_register_protocol(proto_ulp,proto_reg_handoff_ulp);
prefs_register_bool_preference(ulp_module, "desegment_ulp_messages",
"Reassemble ULP messages spanning multiple TCP segments",
"Whether the ULP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ulp_desegment);
prefs_register_uint_preference(ulp_module, "tcp.port",
"ULP TCP Port",
"Set the TCP port for ULP messages (IANA registered port is 7275)",
10,
&gbl_ulp_tcp_port);
prefs_register_uint_preference(ulp_module, "udp.port",
"ULP UDP Port",
"Set the UDP port for ULP messages (IANA registered port is 7275)",
10,
&gbl_ulp_udp_port);
}
void
proto_reg_handoff_ulp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t ulp_tcp_handle, ulp_udp_handle;
static guint local_ulp_tcp_port, local_ulp_udp_port;
if (!initialized) {
ulp_tcp_handle = find_dissector("ulp");
dissector_add_string("media_type","application/oma-supl-ulp", ulp_tcp_handle);
ulp_udp_handle = new_create_dissector_handle(dissect_ULP_PDU_PDU, proto_ulp);
rrlp_handle = find_dissector("rrlp");
lpp_handle = find_dissector("lpp");
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", local_ulp_tcp_port, ulp_tcp_handle);
dissector_delete_uint("udp.port", local_ulp_udp_port, ulp_udp_handle);
}
local_ulp_tcp_port = gbl_ulp_tcp_port;
dissector_add_uint("tcp.port", gbl_ulp_tcp_port, ulp_tcp_handle);
local_ulp_udp_port = gbl_ulp_udp_port;
dissector_add_uint("udp.port", gbl_ulp_udp_port, ulp_udp_handle);
}
