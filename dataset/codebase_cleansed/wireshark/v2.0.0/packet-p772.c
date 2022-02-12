static int
dissect_p772_InformationObject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InformationObject_choice, hf_index, ett_p772_InformationObject,
NULL);
return offset;
}
static int
dissect_p772_Acp127NotificationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Acp127NotificationType_bits, hf_index, ett_p772_Acp127NotificationType,
NULL);
return offset;
}
static int
dissect_p772_AddressListType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_AddressListRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_AddressListDesignator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AddressListDesignator_set, hf_index, ett_p772_AddressListDesignator);
return offset;
}
static int
dissect_p772_AddressListIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AddressListIndicator_sequence_of, hf_index, ett_p772_AddressListIndicator);
return offset;
}
static int
dissect_p772_Acp127Recipient(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
1, ub_military_bigstring, hf_index, NULL);
return offset;
}
static int
dissect_p772_Acp127SuppInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
1, ub_military_bigstring, hf_index, NULL);
return offset;
}
static int
dissect_p772_Acp127NotificationResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Acp127NotificationResponse_set, hf_index, ett_p772_Acp127NotificationResponse);
return offset;
}
static int
dissect_p772_ExemptedAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_ExemptedAddressSeq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ExemptedAddressSeq_sequence_of, hf_index, ett_p772_ExemptedAddressSeq);
return offset;
}
static int
dissect_p772_ExtendedAuthorisationInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p772_Sic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
lb_military_sic, ub_military_sic, hf_index, NULL);
return offset;
}
static int
dissect_p772_SEQUENCE_SIZE_1_ub_military_number_of_sics_OF_Sic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_military_number_of_sics, SEQUENCE_SIZE_1_ub_military_number_of_sics_OF_Sic_sequence_of, hf_index, ett_p772_SEQUENCE_SIZE_1_ub_military_number_of_sics_OF_Sic);
return offset;
}
static int
dissect_p772_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p772_T_dist_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 100 "../../asn1/p772/p772.cnf"
offset = dissect_unknown_ber(actx->pinfo, tvb, offset, tree);
return offset;
}
static int
dissect_p772_DistributionExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DistributionExtensionField_sequence, hf_index, ett_p772_DistributionExtensionField);
return offset;
}
static int
dissect_p772_SEQUENCE_OF_DistributionExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_DistributionExtensionField_sequence_of, hf_index, ett_p772_SEQUENCE_OF_DistributionExtensionField);
return offset;
}
static int
dissect_p772_DistributionCodes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DistributionCodes_set, hf_index, ett_p772_DistributionCodes);
return offset;
}
static int
dissect_p772_MilitaryString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
1, ub_military_string, hf_index, NULL);
return offset;
}
static int
dissect_p772_HandlingInstructions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
HandlingInstructions_sequence_of, hf_index, ett_p772_HandlingInstructions);
return offset;
}
static int
dissect_p772_MessageInstructions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
MessageInstructions_sequence_of, hf_index, ett_p772_MessageInstructions);
return offset;
}
static int
dissect_p772_CodressMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_OriginatorReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p772_MilitaryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_MMHSPrecedence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_PrimaryPrecedence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 106 "../../asn1/p772/p772.cnf"
int precedence = -1;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&precedence);
if(precedence != -1)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (primary=%s)", val_to_str(precedence, p772_PrimaryPrecedence_vals, "precedence(%d)"));
return offset;
}
static int
dissect_p772_CopyPrecedence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 114 "../../asn1/p772/p772.cnf"
int precedence = -1;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&precedence);
if(precedence != -1)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (copy=%s)", val_to_str(precedence, p772_CopyPrecedence_vals, "precedence(%d)"));
return offset;
}
static int
dissect_p772_TypeMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_MessageIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p772_MilitaryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_MessageType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageType_set, hf_index, ett_p772_MessageType);
return offset;
}
static int
dissect_p772_AddressListDesignatorSeq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AddressListDesignatorSeq_sequence_of, hf_index, ett_p772_AddressListDesignatorSeq);
return offset;
}
static int
dissect_p772_OtherRecipientType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_OtherRecipientDesignator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OtherRecipientDesignator_set, hf_index, ett_p772_OtherRecipientDesignator);
return offset;
}
static int
dissect_p772_OtherRecipientDesignatorSeq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
OtherRecipientDesignatorSeq_sequence_of, hf_index, ett_p772_OtherRecipientDesignatorSeq);
return offset;
}
static int
dissect_p772_SEQUENCE_OF_ORDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ORDescriptor_sequence_of, hf_index, ett_p772_SEQUENCE_OF_ORDescriptor);
return offset;
}
static int
dissect_p772_SEQUENCE_OF_MilitaryString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_MilitaryString_sequence_of, hf_index, ett_p772_SEQUENCE_OF_MilitaryString);
return offset;
}
static int
dissect_p772_PilotInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PilotInformation_sequence, hf_index, ett_p772_PilotInformation);
return offset;
}
static int
dissect_p772_PilotInformationSeq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PilotInformationSeq_sequence_of, hf_index, ett_p772_PilotInformationSeq);
return offset;
}
static int
dissect_p772_Acp127MessageIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p772_MilitaryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_OriginatorPlad(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p772_MilitaryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_BodyPartSequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_BodyPartSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BodyPartSecurityLabel_set, hf_index, ett_p772_BodyPartSecurityLabel);
return offset;
}
static int
dissect_p772_SEQUENCE_OF_BodyPartSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_BodyPartSecurityLabel_sequence_of, hf_index, ett_p772_SEQUENCE_OF_BodyPartSecurityLabel);
return offset;
}
static int
dissect_p772_SecurityInformationLabels(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecurityInformationLabels_sequence, hf_index, ett_p772_SecurityInformationLabels);
return offset;
}
static int
dissect_p772_PriorityLevelQualifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_ADatP3Parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_T_setOriented(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_setOriented_sequence_of, hf_index, ett_p772_T_setOriented);
return offset;
}
static int
dissect_p772_ADatP3Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ADatP3Data_choice, hf_index, ett_p772_ADatP3Data,
NULL);
return offset;
}
static int
dissect_p772_CorrectionsParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_CorrectionsData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_ForwardedEncryptedParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ForwardedEncryptedParameters_set, hf_index, ett_p772_ForwardedEncryptedParameters);
return offset;
}
static int
dissect_p772_ForwardedEncryptedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_p772_MMMessageParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MMMessageParameters_set, hf_index, ett_p772_MMMessageParameters);
return offset;
}
static int
dissect_p772_MMMessageData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPM(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p772_ACP127DataParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p772_ACP127DataData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset,
1, ub_data_size, hf_index, NULL);
return offset;
}
static int dissect_InformationObject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_InformationObject(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_InformationObject_PDU);
return offset;
}
static int dissect_Acp127NotificationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_Acp127NotificationResponse(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_Acp127NotificationResponse_PDU);
return offset;
}
static int dissect_ExemptedAddressSeq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ExemptedAddressSeq(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ExemptedAddressSeq_PDU);
return offset;
}
static int dissect_ExtendedAuthorisationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ExtendedAuthorisationInfo(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ExtendedAuthorisationInfo_PDU);
return offset;
}
static int dissect_DistributionCodes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_DistributionCodes(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_DistributionCodes_PDU);
return offset;
}
static int dissect_HandlingInstructions_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_HandlingInstructions(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_HandlingInstructions_PDU);
return offset;
}
static int dissect_MessageInstructions_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_MessageInstructions(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_MessageInstructions_PDU);
return offset;
}
static int dissect_CodressMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_CodressMessage(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_CodressMessage_PDU);
return offset;
}
static int dissect_OriginatorReference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_OriginatorReference(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_OriginatorReference_PDU);
return offset;
}
static int dissect_PrimaryPrecedence_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_PrimaryPrecedence(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_PrimaryPrecedence_PDU);
return offset;
}
static int dissect_CopyPrecedence_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_CopyPrecedence(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_CopyPrecedence_PDU);
return offset;
}
static int dissect_MessageType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_MessageType(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_MessageType_PDU);
return offset;
}
static int dissect_AddressListDesignatorSeq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_AddressListDesignatorSeq(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_AddressListDesignatorSeq_PDU);
return offset;
}
static int dissect_OtherRecipientDesignatorSeq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_OtherRecipientDesignatorSeq(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_OtherRecipientDesignatorSeq_PDU);
return offset;
}
static int dissect_PilotInformationSeq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_PilotInformationSeq(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_PilotInformationSeq_PDU);
return offset;
}
static int dissect_Acp127MessageIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_Acp127MessageIdentifier(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_Acp127MessageIdentifier_PDU);
return offset;
}
static int dissect_OriginatorPlad_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_OriginatorPlad(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_OriginatorPlad_PDU);
return offset;
}
static int dissect_SecurityInformationLabels_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_SecurityInformationLabels(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_SecurityInformationLabels_PDU);
return offset;
}
static int dissect_PriorityLevelQualifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_PriorityLevelQualifier(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_PriorityLevelQualifier_PDU);
return offset;
}
static int dissect_ADatP3Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ADatP3Parameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ADatP3Parameters_PDU);
return offset;
}
static int dissect_ADatP3Data_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ADatP3Data(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ADatP3Data_PDU);
return offset;
}
static int dissect_CorrectionsParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_CorrectionsParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_CorrectionsParameters_PDU);
return offset;
}
static int dissect_CorrectionsData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_CorrectionsData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_CorrectionsData_PDU);
return offset;
}
static int dissect_ForwardedEncryptedParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ForwardedEncryptedParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ForwardedEncryptedParameters_PDU);
return offset;
}
static int dissect_ForwardedEncryptedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ForwardedEncryptedData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ForwardedEncryptedData_PDU);
return offset;
}
static int dissect_MMMessageParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_MMMessageParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_MMMessageParameters_PDU);
return offset;
}
static int dissect_MMMessageData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_MMMessageData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_MMMessageData_PDU);
return offset;
}
static int dissect_ACP127DataParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ACP127DataParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ACP127DataParameters_PDU);
return offset;
}
static int dissect_ACP127DataData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_ACP127DataData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_ACP127DataData_PDU);
return offset;
}
static int dissect_Acp127NotificationType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p772_Acp127NotificationType(FALSE, tvb, offset, &asn1_ctx, tree, hf_p772_Acp127NotificationType_PDU);
return offset;
}
static void
dissect_p772(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_p772, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p772);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P772");
col_set_str(pinfo->cinfo, COL_INFO, "Military");
dissect_p772_InformationObject(TRUE, tvb, offset, &asn1_ctx , tree, -1);
}
void proto_register_p772(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/p772/packet-p772-hfarr.c"
{ &hf_p772_InformationObject_PDU,
{ "InformationObject", "p772.InformationObject",
FT_UINT32, BASE_DEC, VALS(p22_InformationObject_vals), 0,
NULL, HFILL }},
{ &hf_p772_Acp127NotificationResponse_PDU,
{ "Acp127NotificationResponse", "p772.Acp127NotificationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ExemptedAddressSeq_PDU,
{ "ExemptedAddressSeq", "p772.ExemptedAddressSeq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ExtendedAuthorisationInfo_PDU,
{ "ExtendedAuthorisationInfo", "p772.ExtendedAuthorisationInfo",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_DistributionCodes_PDU,
{ "DistributionCodes", "p772.DistributionCodes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_HandlingInstructions_PDU,
{ "HandlingInstructions", "p772.HandlingInstructions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_MessageInstructions_PDU,
{ "MessageInstructions", "p772.MessageInstructions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_CodressMessage_PDU,
{ "CodressMessage", "p772.CodressMessage",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_OriginatorReference_PDU,
{ "OriginatorReference", "p772.OriginatorReference",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_PrimaryPrecedence_PDU,
{ "PrimaryPrecedence", "p772.PrimaryPrecedence",
FT_INT32, BASE_DEC, VALS(p772_PrimaryPrecedence_vals), 0,
NULL, HFILL }},
{ &hf_p772_CopyPrecedence_PDU,
{ "CopyPrecedence", "p772.CopyPrecedence",
FT_INT32, BASE_DEC, VALS(p772_CopyPrecedence_vals), 0,
NULL, HFILL }},
{ &hf_p772_MessageType_PDU,
{ "MessageType", "p772.MessageType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_AddressListDesignatorSeq_PDU,
{ "AddressListDesignatorSeq", "p772.AddressListDesignatorSeq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_OtherRecipientDesignatorSeq_PDU,
{ "OtherRecipientDesignatorSeq", "p772.OtherRecipientDesignatorSeq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_PilotInformationSeq_PDU,
{ "PilotInformationSeq", "p772.PilotInformationSeq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_Acp127MessageIdentifier_PDU,
{ "Acp127MessageIdentifier", "p772.Acp127MessageIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_OriginatorPlad_PDU,
{ "OriginatorPlad", "p772.OriginatorPlad",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_SecurityInformationLabels_PDU,
{ "SecurityInformationLabels", "p772.SecurityInformationLabels_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_PriorityLevelQualifier_PDU,
{ "PriorityLevelQualifier", "p772.PriorityLevelQualifier",
FT_UINT32, BASE_DEC, VALS(p772_PriorityLevelQualifier_vals), 0,
NULL, HFILL }},
{ &hf_p772_ADatP3Parameters_PDU,
{ "ADatP3Parameters", "p772.ADatP3Parameters",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ADatP3Data_PDU,
{ "ADatP3Data", "p772.ADatP3Data",
FT_UINT32, BASE_DEC, VALS(p772_ADatP3Data_vals), 0,
NULL, HFILL }},
{ &hf_p772_CorrectionsParameters_PDU,
{ "CorrectionsParameters", "p772.CorrectionsParameters",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_CorrectionsData_PDU,
{ "CorrectionsData", "p772.CorrectionsData",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ForwardedEncryptedParameters_PDU,
{ "ForwardedEncryptedParameters", "p772.ForwardedEncryptedParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ForwardedEncryptedData_PDU,
{ "ForwardedEncryptedData", "p772.ForwardedEncryptedData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_MMMessageParameters_PDU,
{ "MMMessageParameters", "p772.MMMessageParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_MMMessageData_PDU,
{ "MMMessageData", "p772.MMMessageData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ACP127DataParameters_PDU,
{ "ACP127DataParameters", "p772.ACP127DataParameters",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ACP127DataData_PDU,
{ "ACP127DataData", "p772.ACP127DataData",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_Acp127NotificationType_PDU,
{ "Acp127NotificationType", "p772.Acp127NotificationType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_mm,
{ "mm", "p772.mm_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPM", HFILL }},
{ &hf_p772_mn,
{ "mn", "p772.mn_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPN", HFILL }},
{ &hf_p772_acp127_notification_type,
{ "acp127-notification-type", "p772.acp127_notification_type",
FT_BYTES, BASE_NONE, NULL, 0,
"Acp127NotificationType", HFILL }},
{ &hf_p772_receipt_time,
{ "receipt-time", "p772.receipt_time",
FT_STRING, BASE_NONE, NULL, 0,
"ReceiptTimeField", HFILL }},
{ &hf_p772_addressListIndicator,
{ "addressListIndicator", "p772.addressListIndicator",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_acp127_recipient,
{ "acp127-recipient", "p772.acp127_recipient",
FT_STRING, BASE_NONE, NULL, 0,
"Acp127Recipient", HFILL }},
{ &hf_p772_acp127_supp_info,
{ "acp127-supp-info", "p772.acp127_supp_info",
FT_STRING, BASE_NONE, NULL, 0,
"Acp127SuppInfo", HFILL }},
{ &hf_p772_AddressListIndicator_item,
{ "AddressListDesignator", "p772.AddressListDesignator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_ExemptedAddressSeq_item,
{ "ExemptedAddress", "p772.ExemptedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_sics,
{ "sics", "p772.sics",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_military_number_of_sics_OF_Sic", HFILL }},
{ &hf_p772_sics_item,
{ "Sic", "p772.Sic",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_dist_Extensions,
{ "dist-Extensions", "p772.dist_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DistributionExtensionField", HFILL }},
{ &hf_p772_dist_Extensions_item,
{ "DistributionExtensionField", "p772.DistributionExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_dist_type,
{ "dist-type", "p772.dist_type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p772_dist_value,
{ "dist-value", "p772.dist_value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_dist_value", HFILL }},
{ &hf_p772_HandlingInstructions_item,
{ "MilitaryString", "p772.MilitaryString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_MessageInstructions_item,
{ "MilitaryString", "p772.MilitaryString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_message_type_type,
{ "type", "p772.type",
FT_INT32, BASE_DEC, VALS(p772_TypeMessage_vals), 0,
"TypeMessage", HFILL }},
{ &hf_p772_identifier,
{ "identifier", "p772.identifier",
FT_STRING, BASE_NONE, NULL, 0,
"MessageIdentifier", HFILL }},
{ &hf_p772_AddressListDesignatorSeq_item,
{ "AddressListDesignator", "p772.AddressListDesignator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_address_list_type,
{ "type", "p772.type",
FT_INT32, BASE_DEC, VALS(p772_AddressListType_vals), 0,
"AddressListType", HFILL }},
{ &hf_p772_listName,
{ "listName", "p772.listName_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORDescriptor", HFILL }},
{ &hf_p772_notificationRequest,
{ "notificationRequest", "p772.notificationRequest",
FT_INT32, BASE_DEC, VALS(p772_AddressListRequest_vals), 0,
"AddressListRequest", HFILL }},
{ &hf_p772_replyRequest,
{ "replyRequest", "p772.replyRequest",
FT_INT32, BASE_DEC, VALS(p772_AddressListRequest_vals), 0,
"AddressListRequest", HFILL }},
{ &hf_p772_OtherRecipientDesignatorSeq_item,
{ "OtherRecipientDesignator", "p772.OtherRecipientDesignator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_other_recipient_type,
{ "type", "p772.type",
FT_INT32, BASE_DEC, VALS(p772_OtherRecipientType_vals), 0,
"OtherRecipientType", HFILL }},
{ &hf_p772_designator,
{ "designator", "p772.designator",
FT_STRING, BASE_NONE, NULL, 0,
"MilitaryString", HFILL }},
{ &hf_p772_PilotInformationSeq_item,
{ "PilotInformation", "p772.PilotInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_pilotPrecedence,
{ "pilotPrecedence", "p772.pilotPrecedence",
FT_INT32, BASE_DEC, VALS(p772_MMHSPrecedence_vals), 0,
"MMHSPrecedence", HFILL }},
{ &hf_p772_pilotRecipient,
{ "pilotRecipient", "p772.pilotRecipient",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ORDescriptor", HFILL }},
{ &hf_p772_pilotRecipient_item,
{ "ORDescriptor", "p772.ORDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_pilotSecurity,
{ "pilotSecurity", "p772.pilotSecurity_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p772_pilotHandling,
{ "pilotHandling", "p772.pilotHandling",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_MilitaryString", HFILL }},
{ &hf_p772_pilotHandling_item,
{ "MilitaryString", "p772.MilitaryString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_content_security_label,
{ "content-security-label", "p772.content_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p772_heading_security_label,
{ "heading-security-label", "p772.heading_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p772_body_part_security_labels,
{ "body-part-security-labels", "p772.body_part_security_labels",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_BodyPartSecurityLabel", HFILL }},
{ &hf_p772_body_part_security_labels_item,
{ "BodyPartSecurityLabel", "p772.BodyPartSecurityLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p772_body_part_security_label,
{ "body-part-security-label", "p772.body_part_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p772_body_part_sequence_number,
{ "body-part-sequence-number", "p772.body_part_sequence_number",
FT_INT32, BASE_DEC, NULL, 0,
"BodyPartSequenceNumber", HFILL }},
{ &hf_p772_lineOriented,
{ "lineOriented", "p772.lineOriented",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_p772_setOriented,
{ "setOriented", "p772.setOriented",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p772_setOriented_item,
{ "setOriented item", "p772.setOriented_item",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_p772_delivery_time,
{ "delivery-time", "p772.delivery_time",
FT_STRING, BASE_NONE, NULL, 0,
"MessageDeliveryTime", HFILL }},
{ &hf_p772_delivery_envelope,
{ "delivery-envelope", "p772.delivery_envelope_element",
FT_NONE, BASE_NONE, NULL, 0,
"OtherMessageDeliveryFields", HFILL }},
{ &hf_p772_Acp127NotificationType_acp127_nn,
{ "acp127-nn", "p772.acp127-nn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p772_Acp127NotificationType_acp127_pn,
{ "acp127-pn", "p772.acp127-pn",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p772_Acp127NotificationType_acp127_tn,
{ "acp127-tn", "p772.acp127-tn",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 91 "../../asn1/p772/packet-p772-template.c"
};
static gint *ett[] = {
&ett_p772,
#line 1 "../../asn1/p772/packet-p772-ettarr.c"
&ett_p772_InformationObject,
&ett_p772_Acp127NotificationResponse,
&ett_p772_AddressListIndicator,
&ett_p772_ExemptedAddressSeq,
&ett_p772_DistributionCodes,
&ett_p772_SEQUENCE_SIZE_1_ub_military_number_of_sics_OF_Sic,
&ett_p772_SEQUENCE_OF_DistributionExtensionField,
&ett_p772_DistributionExtensionField,
&ett_p772_HandlingInstructions,
&ett_p772_MessageInstructions,
&ett_p772_MessageType,
&ett_p772_AddressListDesignatorSeq,
&ett_p772_AddressListDesignator,
&ett_p772_OtherRecipientDesignatorSeq,
&ett_p772_OtherRecipientDesignator,
&ett_p772_PilotInformationSeq,
&ett_p772_PilotInformation,
&ett_p772_SEQUENCE_OF_ORDescriptor,
&ett_p772_SEQUENCE_OF_MilitaryString,
&ett_p772_SecurityInformationLabels,
&ett_p772_SEQUENCE_OF_BodyPartSecurityLabel,
&ett_p772_BodyPartSecurityLabel,
&ett_p772_ADatP3Data,
&ett_p772_T_setOriented,
&ett_p772_ForwardedEncryptedParameters,
&ett_p772_MMMessageParameters,
&ett_p772_Acp127NotificationType,
#line 97 "../../asn1/p772/packet-p772-template.c"
};
proto_p772 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("p772", dissect_p772, proto_p772);
proto_register_field_array(proto_p772, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_ber_syntax_dissector("STANAG 4406", proto_p772, dissect_p772);
register_ber_oid_syntax(".p772", NULL, "STANAG 4406");
}
void proto_reg_handoff_p772(void) {
#line 1 "../../asn1/p772/packet-p772-dis-tab.c"
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.0", dissect_PrimaryPrecedence_PDU, proto_p772, "primary-precedence");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.1", dissect_CopyPrecedence_PDU, proto_p772, "copy-precedence");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.2", dissect_MessageType_PDU, proto_p772, "message-type");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.3", dissect_AddressListDesignatorSeq_PDU, proto_p772, "address-list-indicator");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.4", dissect_ExemptedAddressSeq_PDU, proto_p772, "exempted-address");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.5", dissect_ExtendedAuthorisationInfo_PDU, proto_p772, "extended-authorisation-info");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.6", dissect_DistributionCodes_PDU, proto_p772, "distribution-codes");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.7", dissect_HandlingInstructions_PDU, proto_p772, "handling-instructions");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.8", dissect_MessageInstructions_PDU, proto_p772, "message-instructions");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.9", dissect_CodressMessage_PDU, proto_p772, "codress-message");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.10", dissect_OriginatorReference_PDU, proto_p772, "originator-reference");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.11", dissect_OtherRecipientDesignatorSeq_PDU, proto_p772, "other-recipients-indicator");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.12", dissect_PilotInformationSeq_PDU, proto_p772, "pilot-forwarding-info");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.13", dissect_Acp127MessageIdentifier_PDU, proto_p772, "acp127-message-identifier");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.14", dissect_OriginatorPlad_PDU, proto_p772, "originator-plad");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.15", dissect_Acp127NotificationType_PDU, proto_p772, "acp127-notification-request");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.16", dissect_Acp127NotificationResponse_PDU, proto_p772, "acp127-notification-response");
new_register_ber_oid_dissector("1.3.26.0.4406.0.2.17", dissect_SecurityInformationLabels_PDU, proto_p772, "information-labels");
new_register_ber_oid_dissector("1.3.26.0.4406.0.8.0", dissect_PriorityLevelQualifier_PDU, proto_p772, "priority-level-qualifier");
new_register_ber_oid_dissector(id_nato_mmhs_et_adatp3, dissect_ADatP3Data_PDU, proto_p772, "adatp3");
new_register_ber_oid_dissector(id_nato_mmhs_et_adatp3_parameters, dissect_ADatP3Parameters_PDU, proto_p772, "adatp3-parameters");
new_register_ber_oid_dissector(id_nato_mmhs_et_corrections, dissect_CorrectionsData_PDU, proto_p772, "corrections");
new_register_ber_oid_dissector(id_nato_mmhs_et_corrections_parameters, dissect_CorrectionsParameters_PDU, proto_p772, "corrections-parameters");
new_register_ber_oid_dissector(id_nato_mmhs_et_forwarded_encrypted, dissect_ForwardedEncryptedData_PDU, proto_p772, "forwarded-encrypted");
new_register_ber_oid_dissector(id_nato_mmhs_et_forwarded_encrypted_parameters, dissect_ForwardedEncryptedParameters_PDU, proto_p772, "forwarded-encrypted-parameters");
new_register_ber_oid_dissector(id_nato_mmhs_et_mm_message, dissect_MMMessageData_PDU, proto_p772, "mm-message");
new_register_ber_oid_dissector(id_nato_mmhs_et_mm_message_parameters, dissect_MMMessageParameters_PDU, proto_p772, "mm-message-parameters");
new_register_ber_oid_dissector(id_nato_mmhs_et_mm_acp127data, dissect_ACP127DataData_PDU, proto_p772, "acp127-data");
new_register_ber_oid_dissector(id_nato_mmhs_et_mm_acp127data_parameters, dissect_ACP127DataParameters_PDU, proto_p772, "acp127-data-parameters");
new_register_ber_oid_dissector("2.6.1.4.17.1.3.26.0.4406.0.4.1", dissect_InformationObject_PDU, proto_p772, "id-et-content-p772");
#line 115 "../../asn1/p772/packet-p772-template.c"
register_ber_oid_dissector("1.3.26.0.4406.0.4.1", dissect_p772, proto_p772, "STANAG 4406");
}
