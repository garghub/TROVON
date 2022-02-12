static int
dissect_p7_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
return offset;
}
static int
dissect_p7_AttributeItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_AttributeValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_attribute_values, AttributeValues_sequence_of, hf_index, ett_p7_AttributeValues);
return offset;
}
static int
dissect_p7_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_sequence, hf_index, ett_p7_Attribute);
return offset;
}
static int
dissect_p7_AutoActionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_per_auto_action(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_per_auto_action, hf_index, NULL);
return offset;
}
static int
dissect_p7_T_registration_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_AutoActionRegistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AutoActionRegistration_sequence, hf_index, ett_p7_AutoActionRegistration);
return offset;
}
static int
dissect_p7_T_error_code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ros_Code(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p7_T_error_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_AutoActionError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AutoActionError_set, hf_index, ett_p7_AutoActionError);
return offset;
}
static int
dissect_p7_MSExtensionItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_p7_MSExtensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_extensions, MSExtensions_sequence_of, hf_index, ett_p7_MSExtensions);
return offset;
}
static int
dissect_p7_EntryClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_entry_classes, hf_index, NULL);
return offset;
}
static int
dissect_p7_EntryType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_p7_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_messages, hf_index, &seqno);
return offset;
}
static int
dissect_p7_RetrievalStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_GroupNamePart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset,
1, ub_group_part_length, hf_index, NULL);
return offset;
}
static int
dissect_p7_MessageGroupName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_group_depth, MessageGroupName_sequence_of, hf_index, ett_p7_MessageGroupName);
return offset;
}
static int
dissect_p7_T_initiator_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
const char *ora = NULL;
offset = dissect_p1_ORAddressAndOrDirectoryName(implicit_tag, tvb, offset, actx, tree, hf_index);
if ((ora = p1_get_last_oraddress(actx))) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (initiator=%s)", ora);
}
return offset;
}
static int
dissect_p7_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p7_T_allowed_content_types(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_content_types, T_allowed_content_types_set_of, hf_index, ett_p7_T_allowed_content_types);
return offset;
}
static int
dissect_p7_MS_EIT(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p7_MS_EITs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_encoded_information_types, MS_EITs_set_of, hf_index, ett_p7_MS_EITs);
return offset;
}
static int
dissect_p7_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_Restrictions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Restrictions_set, hf_index, ett_p7_Restrictions);
return offset;
}
static int
dissect_p7_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p7_RegistrationIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
1, ub_ua_registration_identifier_length, hf_index, NULL);
return offset;
}
static int
dissect_p7_MSBindArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSBindArgument_set, hf_index, ett_p7_MSBindArgument);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_auto_actions_OF_AutoActionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_auto_actions, SET_SIZE_1_ub_auto_actions_OF_AutoActionType_set_of, hf_index, ett_p7_SET_SIZE_1_ub_auto_actions_OF_AutoActionType);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_attributes_supported_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_attributes_supported, SET_SIZE_1_ub_attributes_supported_OF_AttributeType_set_of, hf_index, ett_p7_SET_SIZE_1_ub_attributes_supported_OF_AttributeType);
return offset;
}
static int
dissect_p7_T_content_types_supported(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_content_types, T_content_types_supported_set_of, hf_index, ett_p7_T_content_types_supported);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_entry_classes_OF_EntryClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_entry_classes, SET_SIZE_1_ub_entry_classes_OF_EntryClass_set_of, hf_index, ett_p7_SET_SIZE_1_ub_entry_classes_OF_EntryClass);
return offset;
}
static int
dissect_p7_T_matching_rules_supported(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_matching_rules, T_matching_rules_supported_set_of, hf_index, ett_p7_T_matching_rules_supported);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_group_depth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_group_depth, hf_index, NULL);
return offset;
}
static int
dissect_p7_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_AutoActionErrorIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AutoActionErrorIndication_choice, hf_index, ett_p7_AutoActionErrorIndication,
NULL);
return offset;
}
static int
dissect_p7_T_unsupported_extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_extensions, T_unsupported_extensions_set_of, hf_index, ett_p7_T_unsupported_extensions);
return offset;
}
static int
dissect_p7_GeneralString_SIZE_1_ub_service_information_length(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset,
1, ub_service_information_length, hf_index, NULL);
return offset;
}
static int
dissect_p7_MSBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSBindResult_set, hf_index, ett_p7_MSBindResult);
return offset;
}
static int
dissect_p7_ChangeCredentialsAlgorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ChangeCredentialsAlgorithms_set_of, hf_index, ett_p7_ChangeCredentialsAlgorithms);
return offset;
}
static int
dissect_p7_BindProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_GeneralString_SIZE_1_ub_supplementary_info_length(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset,
1, ub_supplementary_info_length, hf_index, NULL);
return offset;
}
static int
dissect_p7_T_bind_extension_errors(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_extensions, T_bind_extension_errors_set_of, hf_index, ett_p7_T_bind_extension_errors);
return offset;
}
static int
dissect_p7_T_qualified_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_qualified_error_set, hf_index, ett_p7_T_qualified_error);
return offset;
}
static int
dissect_p7_PAR_ms_bind_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PAR_ms_bind_error_choice, hf_index, ett_p7_PAR_ms_bind_error,
NULL);
return offset;
}
static int
dissect_p7_T_from_number(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p7_SequenceNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " from %d", seqno);
return offset;
}
static int
dissect_p7_T_to_number(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p7_SequenceNumber(implicit_tag, tvb, offset, actx, tree, hf_index);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " to %d", seqno);
return offset;
}
static int
dissect_p7_NumberRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
col_append_str(actx->pinfo->cinfo, COL_INFO, " (range=");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NumberRange_sequence, hf_index, ett_p7_NumberRange);
col_append_str(actx->pinfo->cinfo, COL_INFO, ")");
return offset;
}
static int
dissect_p7_CreationTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_TimeRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeRange_sequence, hf_index, ett_p7_TimeRange);
return offset;
}
static int
dissect_p7_Range(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Range_choice, hf_index, ett_p7_Range,
NULL);
return offset;
}
static int
dissect_p7_T_attribute_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_AttributeValueAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeValueAssertion_sequence, hf_index, ett_p7_AttributeValueAssertion);
return offset;
}
static int
dissect_p7_T_initial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_T_any(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_T_final(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_T_strings_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_strings_item_choice, hf_index, ett_p7_T_strings_item,
NULL);
return offset;
}
static int
dissect_p7_T_strings(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_strings_sequence_of, hf_index, ett_p7_T_strings);
return offset;
}
static int
dissect_p7_T_substrings(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_substrings_sequence, hf_index, ett_p7_T_substrings);
return offset;
}
static int
dissect_p7_T_match_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_MatchingRuleAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MatchingRuleAssertion_sequence, hf_index, ett_p7_MatchingRuleAssertion);
return offset;
}
static int
dissect_p7_FilterItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FilterItem_choice, hf_index, ett_p7_FilterItem,
NULL);
return offset;
}
static int
dissect_p7_SET_OF_Filter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Filter_set_of, hf_index, ett_p7_SET_OF_Filter);
return offset;
}
static int
dissect_p7_Filter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Filter_choice, hf_index, ett_p7_Filter,
NULL);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_messages(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_messages, hf_index, NULL);
return offset;
}
static int
dissect_p7_OverrideRestrictions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_bitstring(implicit_tag, actx, tree, tvb, offset,
1, ub_ua_restrictions, OverrideRestrictions_bits, hf_index, ett_p7_OverrideRestrictions,
NULL);
return offset;
}
static int
dissect_p7_Selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Selector_set, hf_index, ett_p7_Selector);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_attribute_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_attribute_values, hf_index, NULL);
return offset;
}
static int
dissect_p7_INTEGER_0_ub_attribute_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_attribute_values, hf_index, NULL);
return offset;
}
static int
dissect_p7_AttributeSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AttributeSelection_set, hf_index, ett_p7_AttributeSelection);
return offset;
}
static int
dissect_p7_EntryInformationSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
0, ub_per_entry, EntryInformationSelection_set_of, hf_index, ett_p7_EntryInformationSelection);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_per_entry_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_per_entry, SET_SIZE_1_ub_per_entry_OF_Attribute_set_of, hf_index, ett_p7_SET_SIZE_1_ub_per_entry_OF_Attribute);
return offset;
}
static int
dissect_p7_AttributeValueCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeValueCount_sequence, hf_index, ett_p7_AttributeValueCount);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_per_entry_OF_AttributeValueCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_per_entry, SET_SIZE_1_ub_per_entry_OF_AttributeValueCount_set_of, hf_index, ett_p7_SET_SIZE_1_ub_per_entry_OF_AttributeValueCount);
return offset;
}
static int
dissect_p7_EntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
p1_initialize_content_globals (actx, NULL, FALSE);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EntryInformation_sequence, hf_index, ett_p7_EntryInformation);
p1_initialize_content_globals (actx, NULL, FALSE);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_message_groups, SET_SIZE_1_ub_message_groups_OF_MessageGroupName_set_of, hf_index, ett_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupName);
return offset;
}
static int
dissect_p7_MSSubmissionOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSSubmissionOptions_set, hf_index, ett_p7_MSSubmissionOptions);
return offset;
}
static int
dissect_p7_OriginatorToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_MessageToken(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p7_CommonSubmissionResults(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CommonSubmissionResults_set, hf_index, ett_p7_CommonSubmissionResults);
return offset;
}
static int
dissect_p7_SEQUENCE_SIZE_1_ub_summaries_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_summaries, SEQUENCE_SIZE_1_ub_summaries_OF_AttributeType_sequence_of, hf_index, ett_p7_SEQUENCE_SIZE_1_ub_summaries_OF_AttributeType);
return offset;
}
static int
dissect_p7_SummarizeArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SummarizeArgument_set, hf_index, ett_p7_SummarizeArgument);
return offset;
}
static int
dissect_p7_T_count(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
int count = 0;
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_messages, hf_index, &count);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (count=%d)", count);
return offset;
}
static int
dissect_p7_Span(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Span_sequence, hf_index, ett_p7_Span);
return offset;
}
static int
dissect_p7_SummaryPresentItemValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_T_summary_present_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_summary_present_item_sequence, hf_index, ett_p7_T_summary_present_item);
return offset;
}
static int
dissect_p7_T_summary_present(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_attribute_values, T_summary_present_set_of, hf_index, ett_p7_T_summary_present);
return offset;
}
static int
dissect_p7_Summary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Summary_set, hf_index, ett_p7_Summary);
return offset;
}
static int
dissect_p7_SEQUENCE_SIZE_1_ub_summaries_OF_Summary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_summaries, SEQUENCE_SIZE_1_ub_summaries_OF_Summary_sequence_of, hf_index, ett_p7_SEQUENCE_SIZE_1_ub_summaries_OF_Summary);
return offset;
}
static int
dissect_p7_SummarizeResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SummarizeResult_set, hf_index, ett_p7_SummarizeResult);
return offset;
}
static int
dissect_p7_ListArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ListArgument_set, hf_index, ett_p7_ListArgument);
return offset;
}
static int
dissect_p7_SEQUENCE_SIZE_1_ub_messages_OF_EntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_messages, SEQUENCE_SIZE_1_ub_messages_OF_EntryInformation_sequence_of, hf_index, ett_p7_SEQUENCE_SIZE_1_ub_messages_OF_EntryInformation);
return offset;
}
static int
dissect_p7_ListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ListResult_set, hf_index, ett_p7_ListResult);
return offset;
}
static int
dissect_p7_T_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_item_choice, hf_index, ett_p7_T_item,
NULL);
return offset;
}
static int
dissect_p7_FetchArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FetchArgument_set, hf_index, ett_p7_FetchArgument);
return offset;
}
static int
dissect_p7_SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_messages, SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber_sequence_of, hf_index, ett_p7_SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber);
return offset;
}
static int
dissect_p7_FetchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FetchResult_set, hf_index, ett_p7_FetchResult);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_messages_OF_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_messages, SET_SIZE_1_ub_messages_OF_SequenceNumber_set_of, hf_index, ett_p7_SET_SIZE_1_ub_messages_OF_SequenceNumber);
return offset;
}
static int
dissect_p7_T_items(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_items_choice, hf_index, ett_p7_T_items,
NULL);
return offset;
}
static int
dissect_p7_DeleteArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DeleteArgument_set, hf_index, ett_p7_DeleteArgument);
return offset;
}
static int
dissect_p7_T_delete_result_94(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_delete_result_94_set, hf_index, ett_p7_T_delete_result_94);
return offset;
}
static int
dissect_p7_DeleteResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DeleteResult_choice, hf_index, ett_p7_DeleteResult,
NULL);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionRegistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_auto_registrations, SET_SIZE_1_ub_auto_registrations_OF_AutoActionRegistration_set_of, hf_index, ett_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionRegistration);
return offset;
}
static int
dissect_p7_AutoActionDeregistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AutoActionDeregistration_sequence, hf_index, ett_p7_AutoActionDeregistration);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionDeregistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_auto_registrations, SET_SIZE_1_ub_auto_registrations_OF_AutoActionDeregistration_set_of, hf_index, ett_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionDeregistration);
return offset;
}
static int
dissect_p7_SET_SIZE_0_ub_default_registrations_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
0, ub_default_registrations, SET_SIZE_0_ub_default_registrations_OF_AttributeType_set_of, hf_index, ett_p7_SET_SIZE_0_ub_default_registrations_OF_AttributeType);
return offset;
}
static int
dissect_p7_T_change_credentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_change_credentials_sequence, hf_index, ett_p7_T_change_credentials);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_labels_and_redirections_OF_SecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_labels_and_redirections, SET_SIZE_1_ub_labels_and_redirections_OF_SecurityLabel_set_of, hf_index, ett_p7_SET_SIZE_1_ub_labels_and_redirections_OF_SecurityLabel);
return offset;
}
static int
dissect_p7_UARegistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UARegistration_set, hf_index, ett_p7_UARegistration);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_ua_registrations_OF_UARegistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_ua_registrations, SET_SIZE_1_ub_ua_registrations_OF_UARegistration_set_of, hf_index, ett_p7_SET_SIZE_1_ub_ua_registrations_OF_UARegistration);
return offset;
}
static int
dissect_p7_GeneralString_SIZE_1_ub_group_descriptor_length(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset,
1, ub_group_descriptor_length, hf_index, NULL);
return offset;
}
static int
dissect_p7_MessageGroupNameAndDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageGroupNameAndDescriptor_set, hf_index, ett_p7_MessageGroupNameAndDescriptor);
return offset;
}
static int
dissect_p7_MessageGroupRegistrations_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MessageGroupRegistrations_item_choice, hf_index, ett_p7_MessageGroupRegistrations_item,
NULL);
return offset;
}
static int
dissect_p7_MessageGroupRegistrations(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_default_registrations, MessageGroupRegistrations_sequence_of, hf_index, ett_p7_MessageGroupRegistrations);
return offset;
}
static int
dissect_p7_T_registrations(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_registrations_bits, hf_index, ett_p7_T_registrations,
NULL);
return offset;
}
static int
dissect_p7_T_extended_registrations_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
return offset;
}
static int
dissect_p7_T_extended_registrations(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_extended_registrations_set_of, hf_index, ett_p7_T_extended_registrations);
return offset;
}
static int
dissect_p7_MessageGroupsRestriction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageGroupsRestriction_set, hf_index, ett_p7_MessageGroupsRestriction);
return offset;
}
static int
dissect_p7_RegistrationTypes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RegistrationTypes_set, hf_index, ett_p7_RegistrationTypes);
return offset;
}
static int
dissect_p7_Register_MSArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Register_MSArgument_set, hf_index, ett_p7_Register_MSArgument);
return offset;
}
static int
dissect_p7_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_p7_ProtectedChangeCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtectedChangeCredentials_sequence, hf_index, ett_p7_ProtectedChangeCredentials);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_default_registrations_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_default_registrations, SET_SIZE_1_ub_default_registrations_OF_AttributeType_set_of, hf_index, ett_p7_SET_SIZE_1_ub_default_registrations_OF_AttributeType);
return offset;
}
static int
dissect_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupNameAndDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_message_groups, SET_SIZE_1_ub_message_groups_OF_MessageGroupNameAndDescriptor_set_of, hf_index, ett_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupNameAndDescriptor);
return offset;
}
static int
dissect_p7_T_registered_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_registered_information_set, hf_index, ett_p7_T_registered_information);
return offset;
}
static int
dissect_p7_Register_MSResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Register_MSResult_choice, hf_index, ett_p7_Register_MSResult,
NULL);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_auto_actions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_auto_actions, hf_index, NULL);
return offset;
}
static int
dissect_p7_AlertArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AlertArgument_set, hf_index, ett_p7_AlertArgument);
return offset;
}
static int
dissect_p7_AlertResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_T_entries(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_entries_choice, hf_index, ett_p7_T_entries,
NULL);
return offset;
}
static int
dissect_p7_OrderedAttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_OrderedAttributeItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OrderedAttributeItem_sequence, hf_index, ett_p7_OrderedAttributeItem);
return offset;
}
static int
dissect_p7_OrderedAttributeValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_attribute_values, OrderedAttributeValues_sequence_of, hf_index, ett_p7_OrderedAttributeValues);
return offset;
}
static int
dissect_p7_OrderedAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OrderedAttribute_sequence, hf_index, ett_p7_OrderedAttribute);
return offset;
}
static int
dissect_p7_T_modification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_modification_choice, hf_index, ett_p7_T_modification,
NULL);
return offset;
}
static int
dissect_p7_EntryModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
p1_initialize_content_globals (actx, NULL, FALSE);
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EntryModification_set, hf_index, ett_p7_EntryModification);
p1_initialize_content_globals (actx, NULL, FALSE);
return offset;
}
static int
dissect_p7_SEQUENCE_SIZE_1_ub_modifications_OF_EntryModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_modifications, SEQUENCE_SIZE_1_ub_modifications_OF_EntryModification_sequence_of, hf_index, ett_p7_SEQUENCE_SIZE_1_ub_modifications_OF_EntryModification);
return offset;
}
static int
dissect_p7_ModifyArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyArgument_set, hf_index, ett_p7_ModifyArgument);
return offset;
}
static int
dissect_p7_ModifyResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyResult_set, hf_index, ett_p7_ModifyResult);
return offset;
}
static int
dissect_p7_MSMessageSubmissionArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
p1_initialize_content_globals (actx, tree, TRUE);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MSMessageSubmissionArgument_sequence, hf_index, ett_p7_MSMessageSubmissionArgument);
p1_initialize_content_globals (actx, NULL, FALSE);
return offset;
}
static int
dissect_p7_SET_OF_ExtensionField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ExtensionField_set_of, hf_index, ett_p7_SET_OF_ExtensionField);
return offset;
}
static int
dissect_p7_T_mts_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_mts_result_set, hf_index, ett_p7_T_mts_result);
return offset;
}
static int
dissect_p7_MSMessageSubmissionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MSMessageSubmissionResult_choice, hf_index, ett_p7_MSMessageSubmissionResult,
NULL);
return offset;
}
static int
dissect_p7_SEQUENCE_OF_PerRecipientProbeSubmissionFields(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PerRecipientProbeSubmissionFields_sequence_of, hf_index, ett_p7_SEQUENCE_OF_PerRecipientProbeSubmissionFields);
return offset;
}
static int
dissect_p7_MSProbeSubmissionArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSProbeSubmissionArgument_set, hf_index, ett_p7_MSProbeSubmissionArgument);
return offset;
}
static int
dissect_p7_MSProbeSubmissionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSProbeSubmissionResult_set, hf_index, ett_p7_MSProbeSubmissionResult);
return offset;
}
static int
dissect_p7_AttributeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_T_attr_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
if(actx->external.direct_reference)
call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p7_AttributeProblemItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AttributeProblemItem_set, hf_index, ett_p7_AttributeProblemItem);
return offset;
}
static int
dissect_p7_AttributeProblems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_per_entry, AttributeProblems_set_of, hf_index, ett_p7_AttributeProblems);
return offset;
}
static int
dissect_p7_PAR_attribute_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_attribute_error_set, hf_index, ett_p7_PAR_attribute_error);
return offset;
}
static int
dissect_p7_AutoActionRequestProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_AutoActionRequestProblemItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AutoActionRequestProblemItem_set, hf_index, ett_p7_AutoActionRequestProblemItem);
return offset;
}
static int
dissect_p7_AutoActionRequestProblems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_auto_registrations, AutoActionRequestProblems_set_of, hf_index, ett_p7_AutoActionRequestProblems);
return offset;
}
static int
dissect_p7_PAR_auto_action_request_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_auto_action_request_error_set, hf_index, ett_p7_PAR_auto_action_request_error);
return offset;
}
static int
dissect_p7_DeleteProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_DeleteProblemItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DeleteProblemItem_set, hf_index, ett_p7_DeleteProblemItem);
return offset;
}
static int
dissect_p7_DeleteProblems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_messages, DeleteProblems_set_of, hf_index, ett_p7_DeleteProblems);
return offset;
}
static int
dissect_p7_PAR_delete_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_delete_error_set, hf_index, ett_p7_PAR_delete_error);
return offset;
}
static int
dissect_p7_FetchRestrictionProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_T_restriction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_restriction_choice, hf_index, ett_p7_T_restriction,
NULL);
return offset;
}
static int
dissect_p7_FetchRestrictionProblemItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FetchRestrictionProblemItem_set, hf_index, ett_p7_FetchRestrictionProblemItem);
return offset;
}
static int
dissect_p7_FetchRestrictionProblems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_default_registrations, FetchRestrictionProblems_set_of, hf_index, ett_p7_FetchRestrictionProblems);
return offset;
}
static int
dissect_p7_PAR_fetch_restriction_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_fetch_restriction_error_set, hf_index, ett_p7_PAR_fetch_restriction_error);
return offset;
}
static int
dissect_p7_PAR_invalid_parameters_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_RangeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_PAR_range_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_range_error_set, hf_index, ett_p7_PAR_range_error);
return offset;
}
static int
dissect_p7_SequenceNumberProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_SequenceNumberProblemItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SequenceNumberProblemItem_set, hf_index, ett_p7_SequenceNumberProblemItem);
return offset;
}
static int
dissect_p7_SequenceNumberProblems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_messages, SequenceNumberProblems_set_of, hf_index, ett_p7_SequenceNumberProblems);
return offset;
}
static int
dissect_p7_PAR_sequence_number_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_sequence_number_error_set, hf_index, ett_p7_PAR_sequence_number_error);
return offset;
}
static int
dissect_p7_ServiceProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_ServiceErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ServiceErrorParameter_set, hf_index, ett_p7_ServiceErrorParameter);
return offset;
}
static int
dissect_p7_MessageGroupProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_MessageGroupErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageGroupErrorParameter_set, hf_index, ett_p7_MessageGroupErrorParameter);
return offset;
}
static int
dissect_p7_MSExtensionErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MSExtensionErrorParameter_choice, hf_index, ett_p7_MSExtensionErrorParameter,
NULL);
return offset;
}
static int
dissect_p7_RegistrationProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_PAR_register_ms_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PAR_register_ms_error_set, hf_index, ett_p7_PAR_register_ms_error);
return offset;
}
static int
dissect_p7_ModifyProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_error_reasons, hf_index, NULL);
return offset;
}
static int
dissect_p7_ModifyErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyErrorParameter_set, hf_index, ett_p7_ModifyErrorParameter);
return offset;
}
static int
dissect_p7_T_entry_class_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_entry_class_problem_bits, hf_index, ett_p7_T_entry_class_problem,
NULL);
return offset;
}
static int
dissect_p7_EntryClassErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EntryClassErrorParameter_set, hf_index, ett_p7_EntryClassErrorParameter);
return offset;
}
static int
dissect_p7_INTEGER_1_ub_recipients(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, ub_recipients, hf_index, NULL);
return offset;
}
static int
dissect_p7_PerRecipientReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PerRecipientReport_sequence, hf_index, ett_p7_PerRecipientReport);
return offset;
}
static int
dissect_p7_SEQUENCE_OF_PerRecipientReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PerRecipientReport_sequence_of, hf_index, ett_p7_SEQUENCE_OF_PerRecipientReport);
return offset;
}
static int
dissect_p7_ReportLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReportLocation_choice, hf_index, ett_p7_ReportLocation,
NULL);
return offset;
}
static int
dissect_p7_ReportSummary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_DeferredDeliveryCancellationTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_DeletionTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_SubmissionError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SubmissionError_choice, hf_index, ett_p7_SubmissionError,
NULL);
return offset;
}
int
dissect_p7_SignatureStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_SignatureVerificationStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SignatureVerificationStatus_set, hf_index, ett_p7_SignatureVerificationStatus);
return offset;
}
static int
dissect_p7_StoragePeriod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_StorageTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p7_RTTPapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_RTTRapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_AbortReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p7_T_userdataAB(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_unknown_ber(actx->pinfo, tvb, offset, tree);
return offset;
}
static int
dissect_p7_RTABapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RTABapdu_set, hf_index, ett_p7_RTABapdu);
return offset;
}
static int
dissect_p7_RTSE_apdus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RTSE_apdus_choice, hf_index, ett_p7_RTSE_apdus,
NULL);
return offset;
}
static int dissect_AutoActionType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_AutoActionType(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_AutoActionType_PDU);
return offset;
}
static int dissect_AutoActionError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_AutoActionError(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_AutoActionError_PDU);
return offset;
}
static int dissect_EntryType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_EntryType(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_EntryType_PDU);
return offset;
}
static int dissect_SequenceNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_SequenceNumber(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_SequenceNumber_PDU);
return offset;
}
static int dissect_RetrievalStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_RetrievalStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_RetrievalStatus_PDU);
return offset;
}
static int dissect_MessageGroupName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MessageGroupName(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MessageGroupName_PDU);
return offset;
}
static int dissect_MSBindArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSBindArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSBindArgument_PDU);
return offset;
}
static int dissect_MSBindResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSBindResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSBindResult_PDU);
return offset;
}
static int dissect_MS_EIT_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MS_EIT(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MS_EIT_PDU);
return offset;
}
static int dissect_ChangeCredentialsAlgorithms_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ChangeCredentialsAlgorithms(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ChangeCredentialsAlgorithms_PDU);
return offset;
}
static int dissect_PAR_ms_bind_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_ms_bind_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_ms_bind_error_PDU);
return offset;
}
static int dissect_CreationTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_CreationTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_CreationTime_PDU);
return offset;
}
static int dissect_OriginatorToken_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_OriginatorToken(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_OriginatorToken_PDU);
return offset;
}
static int dissect_SummarizeArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_SummarizeArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_SummarizeArgument_PDU);
return offset;
}
static int dissect_SummarizeResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_SummarizeResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_SummarizeResult_PDU);
return offset;
}
static int dissect_ListArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ListArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ListArgument_PDU);
return offset;
}
static int dissect_ListResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ListResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ListResult_PDU);
return offset;
}
static int dissect_FetchArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_FetchArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_FetchArgument_PDU);
return offset;
}
static int dissect_FetchResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_FetchResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_FetchResult_PDU);
return offset;
}
static int dissect_DeleteArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_DeleteArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_DeleteArgument_PDU);
return offset;
}
static int dissect_DeleteResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_DeleteResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_DeleteResult_PDU);
return offset;
}
static int dissect_Register_MSArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_Register_MSArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_Register_MSArgument_PDU);
return offset;
}
static int dissect_Register_MSResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_Register_MSResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_Register_MSResult_PDU);
return offset;
}
static int dissect_ProtectedChangeCredentials_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ProtectedChangeCredentials(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ProtectedChangeCredentials_PDU);
return offset;
}
static int dissect_AlertArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_AlertArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_AlertArgument_PDU);
return offset;
}
static int dissect_AlertResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_AlertResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_AlertResult_PDU);
return offset;
}
static int dissect_ModifyArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ModifyArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ModifyArgument_PDU);
return offset;
}
static int dissect_ModifyResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ModifyResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ModifyResult_PDU);
return offset;
}
static int dissect_MSMessageSubmissionArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSMessageSubmissionArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSMessageSubmissionArgument_PDU);
return offset;
}
static int dissect_MSMessageSubmissionResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSMessageSubmissionResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSMessageSubmissionResult_PDU);
return offset;
}
static int dissect_MSProbeSubmissionArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSProbeSubmissionArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSProbeSubmissionArgument_PDU);
return offset;
}
static int dissect_MSProbeSubmissionResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSProbeSubmissionResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSProbeSubmissionResult_PDU);
return offset;
}
static int dissect_PAR_attribute_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_attribute_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_attribute_error_PDU);
return offset;
}
static int dissect_PAR_auto_action_request_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_auto_action_request_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_auto_action_request_error_PDU);
return offset;
}
static int dissect_PAR_delete_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_delete_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_delete_error_PDU);
return offset;
}
static int dissect_PAR_fetch_restriction_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_fetch_restriction_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_fetch_restriction_error_PDU);
return offset;
}
static int dissect_PAR_invalid_parameters_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_invalid_parameters_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_invalid_parameters_error_PDU);
return offset;
}
static int dissect_PAR_range_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_range_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_range_error_PDU);
return offset;
}
static int dissect_PAR_sequence_number_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_sequence_number_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_sequence_number_error_PDU);
return offset;
}
static int dissect_ServiceErrorParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ServiceErrorParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ServiceErrorParameter_PDU);
return offset;
}
static int dissect_MessageGroupErrorParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MessageGroupErrorParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MessageGroupErrorParameter_PDU);
return offset;
}
static int dissect_MSExtensionErrorParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_MSExtensionErrorParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_MSExtensionErrorParameter_PDU);
return offset;
}
static int dissect_PAR_register_ms_error_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PAR_register_ms_error(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PAR_register_ms_error_PDU);
return offset;
}
static int dissect_ModifyErrorParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ModifyErrorParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ModifyErrorParameter_PDU);
return offset;
}
static int dissect_EntryClassErrorParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_EntryClassErrorParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_EntryClassErrorParameter_PDU);
return offset;
}
static int dissect_ReportLocation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ReportLocation(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ReportLocation_PDU);
return offset;
}
static int dissect_PerRecipientReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_PerRecipientReport(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_PerRecipientReport_PDU);
return offset;
}
static int dissect_ReportSummary_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_ReportSummary(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_ReportSummary_PDU);
return offset;
}
static int dissect_DeferredDeliveryCancellationTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_DeferredDeliveryCancellationTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_DeferredDeliveryCancellationTime_PDU);
return offset;
}
static int dissect_DeletionTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_DeletionTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_DeletionTime_PDU);
return offset;
}
static int dissect_SubmissionError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_SubmissionError(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_SubmissionError_PDU);
return offset;
}
static int dissect_SignatureVerificationStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_SignatureVerificationStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_SignatureVerificationStatus_PDU);
return offset;
}
static int dissect_StoragePeriod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_StoragePeriod(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_StoragePeriod_PDU);
return offset;
}
static int dissect_StorageTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_StorageTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_StorageTime_PDU);
return offset;
}
static int dissect_RTSE_apdus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p7_RTSE_apdus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p7_RTSE_apdus_PDU);
return offset;
}
void proto_register_p7(void) {
static hf_register_info hf[] =
{
#line 1 "./asn1/p7/packet-p7-hfarr.c"
{ &hf_p7_AutoActionType_PDU,
{ "AutoActionType", "p7.AutoActionType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_AutoActionError_PDU,
{ "AutoActionError", "p7.AutoActionError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_EntryType_PDU,
{ "EntryType", "p7.EntryType",
FT_INT32, BASE_DEC, VALS(p7_EntryType_vals), 0,
NULL, HFILL }},
{ &hf_p7_SequenceNumber_PDU,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_RetrievalStatus_PDU,
{ "RetrievalStatus", "p7.RetrievalStatus",
FT_INT32, BASE_DEC, VALS(p7_RetrievalStatus_vals), 0,
NULL, HFILL }},
{ &hf_p7_MessageGroupName_PDU,
{ "MessageGroupName", "p7.MessageGroupName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSBindArgument_PDU,
{ "MSBindArgument", "p7.MSBindArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSBindResult_PDU,
{ "MSBindResult", "p7.MSBindResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MS_EIT_PDU,
{ "MS-EIT", "p7.MS_EIT",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ChangeCredentialsAlgorithms_PDU,
{ "ChangeCredentialsAlgorithms", "p7.ChangeCredentialsAlgorithms",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_ms_bind_error_PDU,
{ "PAR-ms-bind-error", "p7.PAR_ms_bind_error",
FT_UINT32, BASE_DEC, VALS(p7_PAR_ms_bind_error_vals), 0,
NULL, HFILL }},
{ &hf_p7_CreationTime_PDU,
{ "CreationTime", "p7.CreationTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_OriginatorToken_PDU,
{ "OriginatorToken", "p7.OriginatorToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_SummarizeArgument_PDU,
{ "SummarizeArgument", "p7.SummarizeArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_SummarizeResult_PDU,
{ "SummarizeResult", "p7.SummarizeResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ListArgument_PDU,
{ "ListArgument", "p7.ListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ListResult_PDU,
{ "ListResult", "p7.ListResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_FetchArgument_PDU,
{ "FetchArgument", "p7.FetchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_FetchResult_PDU,
{ "FetchResult", "p7.FetchResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_DeleteArgument_PDU,
{ "DeleteArgument", "p7.DeleteArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_DeleteResult_PDU,
{ "DeleteResult", "p7.DeleteResult",
FT_UINT32, BASE_DEC, VALS(p7_DeleteResult_vals), 0,
NULL, HFILL }},
{ &hf_p7_Register_MSArgument_PDU,
{ "Register-MSArgument", "p7.Register_MSArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_Register_MSResult_PDU,
{ "Register-MSResult", "p7.Register_MSResult",
FT_UINT32, BASE_DEC, VALS(p7_Register_MSResult_vals), 0,
NULL, HFILL }},
{ &hf_p7_ProtectedChangeCredentials_PDU,
{ "ProtectedChangeCredentials", "p7.ProtectedChangeCredentials_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_AlertArgument_PDU,
{ "AlertArgument", "p7.AlertArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_AlertResult_PDU,
{ "AlertResult", "p7.AlertResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ModifyArgument_PDU,
{ "ModifyArgument", "p7.ModifyArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ModifyResult_PDU,
{ "ModifyResult", "p7.ModifyResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSMessageSubmissionArgument_PDU,
{ "MSMessageSubmissionArgument", "p7.MSMessageSubmissionArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSMessageSubmissionResult_PDU,
{ "MSMessageSubmissionResult", "p7.MSMessageSubmissionResult",
FT_UINT32, BASE_DEC, VALS(p7_MSMessageSubmissionResult_vals), 0,
NULL, HFILL }},
{ &hf_p7_MSProbeSubmissionArgument_PDU,
{ "MSProbeSubmissionArgument", "p7.MSProbeSubmissionArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSProbeSubmissionResult_PDU,
{ "MSProbeSubmissionResult", "p7.MSProbeSubmissionResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_attribute_error_PDU,
{ "PAR-attribute-error", "p7.PAR_attribute_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_auto_action_request_error_PDU,
{ "PAR-auto-action-request-error", "p7.PAR_auto_action_request_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_delete_error_PDU,
{ "PAR-delete-error", "p7.PAR_delete_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_fetch_restriction_error_PDU,
{ "PAR-fetch-restriction-error", "p7.PAR_fetch_restriction_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_invalid_parameters_error_PDU,
{ "PAR-invalid-parameters-error", "p7.PAR_invalid_parameters_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_range_error_PDU,
{ "PAR-range-error", "p7.PAR_range_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_PAR_sequence_number_error_PDU,
{ "PAR-sequence-number-error", "p7.PAR_sequence_number_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ServiceErrorParameter_PDU,
{ "ServiceErrorParameter", "p7.ServiceErrorParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MessageGroupErrorParameter_PDU,
{ "MessageGroupErrorParameter", "p7.MessageGroupErrorParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSExtensionErrorParameter_PDU,
{ "MSExtensionErrorParameter", "p7.MSExtensionErrorParameter",
FT_UINT32, BASE_DEC, VALS(p7_MSExtensionErrorParameter_vals), 0,
NULL, HFILL }},
{ &hf_p7_PAR_register_ms_error_PDU,
{ "PAR-register-ms-error", "p7.PAR_register_ms_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ModifyErrorParameter_PDU,
{ "ModifyErrorParameter", "p7.ModifyErrorParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_EntryClassErrorParameter_PDU,
{ "EntryClassErrorParameter", "p7.EntryClassErrorParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ReportLocation_PDU,
{ "ReportLocation", "p7.ReportLocation",
FT_UINT32, BASE_DEC, VALS(p7_ReportLocation_vals), 0,
NULL, HFILL }},
{ &hf_p7_PerRecipientReport_PDU,
{ "PerRecipientReport", "p7.PerRecipientReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ReportSummary_PDU,
{ "ReportSummary", "p7.ReportSummary",
FT_UINT32, BASE_DEC, VALS(p7_ReportSummary_vals), 0,
NULL, HFILL }},
{ &hf_p7_DeferredDeliveryCancellationTime_PDU,
{ "DeferredDeliveryCancellationTime", "p7.DeferredDeliveryCancellationTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_DeletionTime_PDU,
{ "DeletionTime", "p7.DeletionTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_SubmissionError_PDU,
{ "SubmissionError", "p7.SubmissionError",
FT_UINT32, BASE_DEC, VALS(p7_SubmissionError_vals), 0,
NULL, HFILL }},
{ &hf_p7_SignatureVerificationStatus_PDU,
{ "SignatureVerificationStatus", "p7.SignatureVerificationStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_StoragePeriod_PDU,
{ "StoragePeriod", "p7.StoragePeriod",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_StorageTime_PDU,
{ "StorageTime", "p7.StorageTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_RTSE_apdus_PDU,
{ "RTSE-apdus", "p7.RTSE_apdus",
FT_UINT32, BASE_DEC, VALS(p7_RTSE_apdus_vals), 0,
NULL, HFILL }},
{ &hf_p7_attribute_type,
{ "attribute-type", "p7.attribute_type",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_p7_attribute_values,
{ "attribute-values", "p7.attribute_values",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeValues", HFILL }},
{ &hf_p7_attribute_values_item,
{ "attribute-values item", "p7.attribute_values_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeItem", HFILL }},
{ &hf_p7_auto_action_type,
{ "auto-action-type", "p7.auto_action_type",
FT_OID, BASE_NONE, NULL, 0,
"AutoActionType", HFILL }},
{ &hf_p7_registration_identifier,
{ "registration-identifier", "p7.registration_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_per_auto_action", HFILL }},
{ &hf_p7_registration_parameter,
{ "registration-parameter", "p7.registration_parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_error_code,
{ "error-code", "p7.error_code_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_error_parameter,
{ "error-parameter", "p7.error_parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MSExtensions_item,
{ "MSExtensionItem", "p7.MSExtensionItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_MessageGroupName_item,
{ "GroupNamePart", "p7.GroupNamePart",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_initiator_name,
{ "initiator-name", "p7.initiator_name_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_initiator_credentials,
{ "initiator-credentials", "p7.initiator_credentials",
FT_UINT32, BASE_DEC, VALS(p1_Credentials_vals), 0,
"InitiatorCredentials", HFILL }},
{ &hf_p7_security_context,
{ "security-context", "p7.security_context",
FT_UINT32, BASE_DEC, NULL, 0,
"SecurityContext", HFILL }},
{ &hf_p7_fetch_restrictions,
{ "fetch-restrictions", "p7.fetch_restrictions_element",
FT_NONE, BASE_NONE, NULL, 0,
"Restrictions", HFILL }},
{ &hf_p7_ms_configuration_request,
{ "ms-configuration-request", "p7.ms_configuration_request",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_ua_registration_identifier,
{ "ua-registration-identifier", "p7.ua_registration_identifier",
FT_STRING, BASE_NONE, NULL, 0,
"RegistrationIdentifier", HFILL }},
{ &hf_p7_bind_extensions,
{ "bind-extensions", "p7.bind_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_allowed_content_types,
{ "allowed-content-types", "p7.allowed_content_types",
FT_UINT32, BASE_DEC, NULL, 0,
"T_allowed_content_types", HFILL }},
{ &hf_p7_allowed_content_types_item,
{ "allowed-content-types item", "p7.allowed_content_types_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_allowed_EITs,
{ "allowed-EITs", "p7.allowed_EITs",
FT_UINT32, BASE_DEC, NULL, 0,
"MS_EITs", HFILL }},
{ &hf_p7_maximum_attribute_length,
{ "maximum-attribute-length", "p7.maximum_attribute_length",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p7_MS_EITs_item,
{ "MS-EIT", "p7.MS_EIT",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_responder_credentials,
{ "responder-credentials", "p7.responder_credentials",
FT_UINT32, BASE_DEC, VALS(p1_Credentials_vals), 0,
"ResponderCredentials", HFILL }},
{ &hf_p7_available_auto_actions,
{ "available-auto-actions", "p7.available_auto_actions",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_auto_actions_OF_AutoActionType", HFILL }},
{ &hf_p7_available_auto_actions_item,
{ "AutoActionType", "p7.AutoActionType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_available_attribute_types,
{ "available-attribute-types", "p7.available_attribute_types",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_attributes_supported_OF_AttributeType", HFILL }},
{ &hf_p7_available_attribute_types_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_alert_indication,
{ "alert-indication", "p7.alert_indication",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_content_types_supported,
{ "content-types-supported", "p7.content_types_supported",
FT_UINT32, BASE_DEC, NULL, 0,
"T_content_types_supported", HFILL }},
{ &hf_p7_content_types_supported_item,
{ "content-types-supported item", "p7.content_types_supported_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_entry_classes_supported,
{ "entry-classes-supported", "p7.entry_classes_supported",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_entry_classes_OF_EntryClass", HFILL }},
{ &hf_p7_entry_classes_supported_item,
{ "EntryClass", "p7.EntryClass",
FT_UINT32, BASE_DEC, VALS(p7_EntryClass_vals), 0,
NULL, HFILL }},
{ &hf_p7_matching_rules_supported,
{ "matching-rules-supported", "p7.matching_rules_supported",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_matching_rules_supported_item,
{ "matching-rules-supported item", "p7.matching_rules_supported_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_bind_result_extensions,
{ "bind-result-extensions", "p7.bind_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_message_group_depth,
{ "message-group-depth", "p7.message_group_depth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_group_depth", HFILL }},
{ &hf_p7_auto_action_error_indication,
{ "auto-action-error-indication", "p7.auto_action_error_indication",
FT_UINT32, BASE_DEC, VALS(p7_AutoActionErrorIndication_vals), 0,
"AutoActionErrorIndication", HFILL }},
{ &hf_p7_unsupported_extensions,
{ "unsupported-extensions", "p7.unsupported_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_unsupported_extensions_item,
{ "unsupported-extensions item", "p7.unsupported_extensions_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_ua_registration_id_unknown,
{ "ua-registration-id-unknown", "p7.ua_registration_id_unknown",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_service_information,
{ "service-information", "p7.service_information",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralString_SIZE_1_ub_service_information_length", HFILL }},
{ &hf_p7_ChangeCredentialsAlgorithms_item,
{ "ChangeCredentialsAlgorithms item", "p7.ChangeCredentialsAlgorithms_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_indication_only,
{ "indication-only", "p7.indication_only_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_auto_action_log_entry,
{ "auto-action-log-entry", "p7.auto_action_log_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_unqualified_error,
{ "unqualified-error", "p7.unqualified_error",
FT_UINT32, BASE_DEC, VALS(p7_BindProblem_vals), 0,
"BindProblem", HFILL }},
{ &hf_p7_qualified_error,
{ "qualified-error", "p7.qualified_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_bind_problem,
{ "bind-problem", "p7.bind_problem",
FT_UINT32, BASE_DEC, VALS(p7_BindProblem_vals), 0,
"BindProblem", HFILL }},
{ &hf_p7_supplementary_information,
{ "supplementary-information", "p7.supplementary_information",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralString_SIZE_1_ub_supplementary_info_length", HFILL }},
{ &hf_p7_bind_extension_errors,
{ "bind-extension-errors", "p7.bind_extension_errors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_bind_extension_errors_item,
{ "bind-extension-errors item", "p7.bind_extension_errors_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_sequence_number_range,
{ "sequence-number-range", "p7.sequence_number_range_element",
FT_NONE, BASE_NONE, NULL, 0,
"NumberRange", HFILL }},
{ &hf_p7_creation_time_range,
{ "creation-time-range", "p7.creation_time_range_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeRange", HFILL }},
{ &hf_p7_from_number,
{ "from", "p7.from",
FT_UINT32, BASE_DEC, NULL, 0,
"T_from_number", HFILL }},
{ &hf_p7_to_number,
{ "to", "p7.to",
FT_UINT32, BASE_DEC, NULL, 0,
"T_to_number", HFILL }},
{ &hf_p7_from_time,
{ "from", "p7.from",
FT_STRING, BASE_NONE, NULL, 0,
"CreationTime", HFILL }},
{ &hf_p7_to_time,
{ "to", "p7.to",
FT_STRING, BASE_NONE, NULL, 0,
"CreationTime", HFILL }},
{ &hf_p7_filter_item,
{ "item", "p7.item",
FT_UINT32, BASE_DEC, VALS(p7_FilterItem_vals), 0,
"FilterItem", HFILL }},
{ &hf_p7_and,
{ "and", "p7.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Filter", HFILL }},
{ &hf_p7_and_item,
{ "Filter", "p7.Filter",
FT_UINT32, BASE_DEC, VALS(p7_Filter_vals), 0,
NULL, HFILL }},
{ &hf_p7_or,
{ "or", "p7.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Filter", HFILL }},
{ &hf_p7_or_item,
{ "Filter", "p7.Filter",
FT_UINT32, BASE_DEC, VALS(p7_Filter_vals), 0,
NULL, HFILL }},
{ &hf_p7_not,
{ "not", "p7.not",
FT_UINT32, BASE_DEC, VALS(p7_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_p7_equality,
{ "equality", "p7.equality_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_p7_substrings,
{ "substrings", "p7.substrings_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_type,
{ "type", "p7.type",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_p7_strings,
{ "strings", "p7.strings",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_strings_item,
{ "strings item", "p7.strings_item",
FT_UINT32, BASE_DEC, VALS(p7_T_strings_item_vals), 0,
NULL, HFILL }},
{ &hf_p7_initial,
{ "initial", "p7.initial_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_any,
{ "any", "p7.any_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_final,
{ "final", "p7.final_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_greater_or_equal,
{ "greater-or-equal", "p7.greater_or_equal_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_p7_less_or_equal,
{ "less-or-equal", "p7.less_or_equal_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_p7_present,
{ "present", "p7.present",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_p7_approximate_match,
{ "approximate-match", "p7.approximate_match_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_p7_other_match,
{ "other-match", "p7.other_match_element",
FT_NONE, BASE_NONE, NULL, 0,
"MatchingRuleAssertion", HFILL }},
{ &hf_p7_matching_rule,
{ "matching-rule", "p7.matching_rule",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_match_value,
{ "match-value", "p7.match_value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_attribute_value,
{ "attribute-value", "p7.attribute_value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_child_entries,
{ "child-entries", "p7.child_entries",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_range,
{ "range", "p7.range",
FT_UINT32, BASE_DEC, VALS(p7_Range_vals), 0,
NULL, HFILL }},
{ &hf_p7_filter,
{ "filter", "p7.filter",
FT_UINT32, BASE_DEC, VALS(p7_Filter_vals), 0,
NULL, HFILL }},
{ &hf_p7_limit,
{ "limit", "p7.limit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_messages", HFILL }},
{ &hf_p7_override,
{ "override", "p7.override",
FT_BYTES, BASE_NONE, NULL, 0,
"OverrideRestrictions", HFILL }},
{ &hf_p7_EntryInformationSelection_item,
{ "AttributeSelection", "p7.AttributeSelection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_from,
{ "from", "p7.from",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_attribute_values", HFILL }},
{ &hf_p7_selection_count,
{ "count", "p7.count",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_ub_attribute_values", HFILL }},
{ &hf_p7_sequence_number,
{ "sequence-number", "p7.sequence_number",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_attributes,
{ "attributes", "p7.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_per_entry_OF_Attribute", HFILL }},
{ &hf_p7_attributes_item,
{ "Attribute", "p7.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_value_count_exceeded,
{ "value-count-exceeded", "p7.value_count_exceeded",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_per_entry_OF_AttributeValueCount", HFILL }},
{ &hf_p7_value_count_exceeded_item,
{ "AttributeValueCount", "p7.AttributeValueCount_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_total,
{ "total", "p7.total",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p7_object_entry_class,
{ "object-entry-class", "p7.object_entry_class",
FT_UINT32, BASE_DEC, VALS(p7_EntryClass_vals), 0,
"EntryClass", HFILL }},
{ &hf_p7_disable_auto_modify,
{ "disable-auto-modify", "p7.disable_auto_modify",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_add_message_group_names,
{ "add-message-group-names", "p7.add_message_group_names",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_message_groups_OF_MessageGroupName", HFILL }},
{ &hf_p7_add_message_group_names_item,
{ "MessageGroupName", "p7.MessageGroupName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ms_submission_extensions,
{ "ms-submission-extensions", "p7.ms_submission_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_created_entry,
{ "created-entry", "p7.created_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_ms_submission_result_extensions,
{ "ms-submission-result-extensions", "p7.ms_submission_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_entry_class,
{ "entry-class", "p7.entry_class",
FT_UINT32, BASE_DEC, VALS(p7_EntryClass_vals), 0,
"EntryClass", HFILL }},
{ &hf_p7_selector,
{ "selector", "p7.selector_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_summary_requests,
{ "summary-requests", "p7.summary_requests",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_summaries_OF_AttributeType", HFILL }},
{ &hf_p7_summary_requests_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_summarize_extensions,
{ "summarize-extensions", "p7.summarize_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_next,
{ "next", "p7.next",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_count,
{ "count", "p7.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_span,
{ "span", "p7.span_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_summaries,
{ "summaries", "p7.summaries",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_summaries_OF_Summary", HFILL }},
{ &hf_p7_summaries_item,
{ "Summary", "p7.Summary_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_summarize_result_extensions,
{ "summarize-result-extensions", "p7.summarize_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_lowest,
{ "lowest", "p7.lowest",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_highest,
{ "highest", "p7.highest",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_absent,
{ "absent", "p7.absent",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_messages", HFILL }},
{ &hf_p7_summary_present,
{ "present", "p7.present",
FT_UINT32, BASE_DEC, NULL, 0,
"T_summary_present", HFILL }},
{ &hf_p7_summary_present_item,
{ "present item", "p7.present_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_summary_present_item", HFILL }},
{ &hf_p7_value,
{ "value", "p7.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SummaryPresentItemValue", HFILL }},
{ &hf_p7_summary_count,
{ "count", "p7.count",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_messages", HFILL }},
{ &hf_p7_requested_attributes,
{ "requested-attributes", "p7.requested_attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"EntryInformationSelection", HFILL }},
{ &hf_p7_list_extensions,
{ "list-extensions", "p7.list_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_requested,
{ "requested", "p7.requested",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_messages_OF_EntryInformation", HFILL }},
{ &hf_p7_requested_item,
{ "EntryInformation", "p7.EntryInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_list_result_extensions,
{ "list-result-extensions", "p7.list_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_item,
{ "item", "p7.item",
FT_UINT32, BASE_DEC, VALS(p7_T_item_vals), 0,
NULL, HFILL }},
{ &hf_p7_search,
{ "search", "p7.search_element",
FT_NONE, BASE_NONE, NULL, 0,
"Selector", HFILL }},
{ &hf_p7_precise,
{ "precise", "p7.precise",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_fetch_extensions,
{ "fetch-extensions", "p7.fetch_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_entry_information,
{ "entry-information", "p7.entry_information_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryInformation", HFILL }},
{ &hf_p7_list,
{ "list", "p7.list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_list_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_fetch_result_extensions,
{ "fetch-result-extensions", "p7.fetch_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_items,
{ "items", "p7.items",
FT_UINT32, BASE_DEC, VALS(p7_T_items_vals), 0,
NULL, HFILL }},
{ &hf_p7_sequence_numbers,
{ "sequence-numbers", "p7.sequence_numbers",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_sequence_numbers_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_delete_extensions,
{ "delete-extensions", "p7.delete_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_delete_result_88,
{ "delete-result-88", "p7.delete_result_88_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_delete_result_94,
{ "delete-result-94", "p7.delete_result_94_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_delete_result_94", HFILL }},
{ &hf_p7_entries_deleted_94,
{ "entries-deleted", "p7.entries_deleted",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_entries_deleted_94_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_delete_result_extensions,
{ "delete-result-extensions", "p7.delete_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_auto_action_registrations,
{ "auto-action-registrations", "p7.auto_action_registrations",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_auto_registrations_OF_AutoActionRegistration", HFILL }},
{ &hf_p7_auto_action_registrations_item,
{ "AutoActionRegistration", "p7.AutoActionRegistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_auto_action_deregistrations,
{ "auto-action-deregistrations", "p7.auto_action_deregistrations",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_auto_registrations_OF_AutoActionDeregistration", HFILL }},
{ &hf_p7_auto_action_deregistrations_item,
{ "AutoActionDeregistration", "p7.AutoActionDeregistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_list_attribute_defaults,
{ "list-attribute-defaults", "p7.list_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_list_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_fetch_attribute_defaults,
{ "fetch-attribute-defaults", "p7.fetch_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_fetch_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_change_credentials,
{ "change-credentials", "p7.change_credentials_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_register_old_credentials,
{ "old-credentials", "p7.old_credentials",
FT_UINT32, BASE_DEC, VALS(p1_Credentials_vals), 0,
"Credentials", HFILL }},
{ &hf_p7_new_credentials,
{ "new-credentials", "p7.new_credentials",
FT_UINT32, BASE_DEC, VALS(p1_Credentials_vals), 0,
"Credentials", HFILL }},
{ &hf_p7_user_security_labels,
{ "user-security-labels", "p7.user_security_labels",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_labels_and_redirections_OF_SecurityLabel", HFILL }},
{ &hf_p7_user_security_labels_item,
{ "SecurityLabel", "p7.SecurityLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ua_registrations,
{ "ua-registrations", "p7.ua_registrations",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_ua_registrations_OF_UARegistration", HFILL }},
{ &hf_p7_ua_registrations_item,
{ "UARegistration", "p7.UARegistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_submission_defaults,
{ "submission-defaults", "p7.submission_defaults_element",
FT_NONE, BASE_NONE, NULL, 0,
"MSSubmissionOptions", HFILL }},
{ &hf_p7_message_group_registrations,
{ "message-group-registrations", "p7.message_group_registrations",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageGroupRegistrations", HFILL }},
{ &hf_p7_registration_status_request,
{ "registration-status-request", "p7.registration_status_request_element",
FT_NONE, BASE_NONE, NULL, 0,
"RegistrationTypes", HFILL }},
{ &hf_p7_register_ms_extensions,
{ "register-ms-extensions", "p7.register_ms_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_ua_list_attribute_defaults,
{ "ua-list-attribute-defaults", "p7.ua_list_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_ua_list_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ua_fetch_attribute_defaults,
{ "ua-fetch-attribute-defaults", "p7.ua_fetch_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_ua_fetch_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ua_submission_defaults,
{ "ua-submission-defaults", "p7.ua_submission_defaults_element",
FT_NONE, BASE_NONE, NULL, 0,
"MSSubmissionOptions", HFILL }},
{ &hf_p7_content_specific_defaults,
{ "content-specific-defaults", "p7.content_specific_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_MessageGroupRegistrations_item,
{ "MessageGroupRegistrations item", "p7.MessageGroupRegistrations_item",
FT_UINT32, BASE_DEC, VALS(p7_MessageGroupRegistrations_item_vals), 0,
NULL, HFILL }},
{ &hf_p7_register_group,
{ "register-group", "p7.register_group_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageGroupNameAndDescriptor", HFILL }},
{ &hf_p7_deregister_group,
{ "deregister-group", "p7.deregister_group",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageGroupName", HFILL }},
{ &hf_p7_change_descriptors,
{ "change-descriptors", "p7.change_descriptors_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageGroupNameAndDescriptor", HFILL }},
{ &hf_p7_message_group_name,
{ "message-group-name", "p7.message_group_name",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageGroupName", HFILL }},
{ &hf_p7_message_group_descriptor,
{ "message-group-descriptor", "p7.message_group_descriptor",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralString_SIZE_1_ub_group_descriptor_length", HFILL }},
{ &hf_p7_registrations,
{ "registrations", "p7.registrations",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_extended_registrations,
{ "extended-registrations", "p7.extended_registrations",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_extended_registrations_item,
{ "extended-registrations item", "p7.extended_registrations_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_restrict_message_groups,
{ "restrict-message-groups", "p7.restrict_message_groups_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageGroupsRestriction", HFILL }},
{ &hf_p7_parent_group,
{ "parent-group", "p7.parent_group",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageGroupName", HFILL }},
{ &hf_p7_immediate_descendants_only,
{ "immediate-descendants-only", "p7.immediate_descendants_only",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_omit_descriptors,
{ "omit-descriptors", "p7.omit_descriptors",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_algorithm_identifier,
{ "algorithm-identifier", "p7.algorithm_identifier",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_old_credentials,
{ "old-credentials", "p7.old_credentials",
FT_UINT32, BASE_DEC, VALS(p1_Credentials_vals), 0,
"InitiatorCredentials", HFILL }},
{ &hf_p7_password_delta,
{ "password-delta", "p7.password_delta",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_p7_no_status_information,
{ "no-status-information", "p7.no_status_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_registered_information,
{ "registered-information", "p7.registered_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_registered_list_attribute_defaults,
{ "list-attribute-defaults", "p7.list_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_registered_list_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_registered_fetch_attribute_defaults,
{ "fetch-attribute-defaults", "p7.fetch_attribute_defaults",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_default_registrations_OF_AttributeType", HFILL }},
{ &hf_p7_registered_fetch_attribute_defaults_item,
{ "AttributeType", "p7.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_registered_message_group_registrations,
{ "message-group-registrations", "p7.message_group_registrations",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_message_groups_OF_MessageGroupNameAndDescriptor", HFILL }},
{ &hf_p7_registered_message_group_registrations_item,
{ "MessageGroupNameAndDescriptor", "p7.MessageGroupNameAndDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_register_ms_result_extensions,
{ "register-ms-result-extensions", "p7.register_ms_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_alert_registration_identifier,
{ "alert-registration-identifier", "p7.alert_registration_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_auto_actions", HFILL }},
{ &hf_p7_new_entry,
{ "new-entry", "p7.new_entry_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryInformation", HFILL }},
{ &hf_p7_entries,
{ "entries", "p7.entries",
FT_UINT32, BASE_DEC, VALS(p7_T_entries_vals), 0,
NULL, HFILL }},
{ &hf_p7_specific_entries,
{ "specific-entries", "p7.specific_entries",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_specific_entries_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_modifications,
{ "modifications", "p7.modifications",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_modifications_OF_EntryModification", HFILL }},
{ &hf_p7_modifications_item,
{ "EntryModification", "p7.EntryModification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_modify_extensions,
{ "modify-extensions", "p7.modify_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_strict,
{ "strict", "p7.strict",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p7_modification,
{ "modification", "p7.modification",
FT_UINT32, BASE_DEC, VALS(p7_T_modification_vals), 0,
NULL, HFILL }},
{ &hf_p7_add_attribute,
{ "add-attribute", "p7.add_attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_p7_remove_attribute,
{ "remove-attribute", "p7.remove_attribute",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_p7_add_values,
{ "add-values", "p7.add_values_element",
FT_NONE, BASE_NONE, NULL, 0,
"OrderedAttribute", HFILL }},
{ &hf_p7_remove_values,
{ "remove-values", "p7.remove_values_element",
FT_NONE, BASE_NONE, NULL, 0,
"OrderedAttribute", HFILL }},
{ &hf_p7_ordered_attribute_values,
{ "attribute-values", "p7.attribute_values",
FT_UINT32, BASE_DEC, NULL, 0,
"OrderedAttributeValues", HFILL }},
{ &hf_p7_ordered_attribute_values_item,
{ "attribute-values item", "p7.attribute_values_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"OrderedAttributeItem", HFILL }},
{ &hf_p7_ordered_attribute_value,
{ "value", "p7.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"OrderedAttributeValue", HFILL }},
{ &hf_p7_ordered_position,
{ "position", "p7.position",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_attribute_values", HFILL }},
{ &hf_p7_entries_modified,
{ "entries-modified", "p7.entries_modified",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_entries_modified_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_modify_result_extensions,
{ "modify-result-extensions", "p7.modify_result_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"MSExtensions", HFILL }},
{ &hf_p7_envelope,
{ "envelope", "p7.envelope_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageSubmissionEnvelope", HFILL }},
{ &hf_p7_content,
{ "content", "p7.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_submission_options,
{ "submission-options", "p7.submission_options_element",
FT_NONE, BASE_NONE, NULL, 0,
"MSSubmissionOptions", HFILL }},
{ &hf_p7_mts_result,
{ "mts-result", "p7.mts_result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_message_submission_identifier,
{ "message-submission-identifier", "p7.message_submission_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageSubmissionIdentifier", HFILL }},
{ &hf_p7_message_submission_time,
{ "message-submission-time", "p7.message_submission_time",
FT_STRING, BASE_NONE, NULL, 0,
"MessageSubmissionTime", HFILL }},
{ &hf_p7_content_identifier,
{ "content-identifier", "p7.content_identifier",
FT_STRING, BASE_NONE, NULL, 0,
"ContentIdentifier", HFILL }},
{ &hf_p7_extensions,
{ "extensions", "p7.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ExtensionField", HFILL }},
{ &hf_p7_extensions_item,
{ "ExtensionField", "p7.ExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_ms_message_result,
{ "ms-message-result", "p7.ms_message_result_element",
FT_NONE, BASE_NONE, NULL, 0,
"CommonSubmissionResults", HFILL }},
{ &hf_p7_store_draft_result,
{ "store-draft-result", "p7.store_draft_result_element",
FT_NONE, BASE_NONE, NULL, 0,
"CommonSubmissionResults", HFILL }},
{ &hf_p7_originator_name,
{ "originator-name", "p7.originator_name_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginatorName", HFILL }},
{ &hf_p7_original_encoded_information_types,
{ "original-encoded-information-types", "p7.original_encoded_information_types_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginalEncodedInformationTypes", HFILL }},
{ &hf_p7_content_type,
{ "content-type", "p7.content_type",
FT_UINT32, BASE_DEC, VALS(p1_ContentType_vals), 0,
"ContentType", HFILL }},
{ &hf_p7_content_length,
{ "content-length", "p7.content_length",
FT_UINT32, BASE_DEC, NULL, 0,
"ContentLength", HFILL }},
{ &hf_p7_per_message_indicators,
{ "per-message-indicators", "p7.per_message_indicators",
FT_BYTES, BASE_NONE, NULL, 0,
"PerMessageIndicators", HFILL }},
{ &hf_p7_per_recipient_fields,
{ "per-recipient-fields", "p7.per_recipient_fields",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PerRecipientProbeSubmissionFields", HFILL }},
{ &hf_p7_per_recipient_fields_item,
{ "PerRecipientProbeSubmissionFields", "p7.PerRecipientProbeSubmissionFields_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_probe_submission_identifier,
{ "probe-submission-identifier", "p7.probe_submission_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProbeSubmissionIdentifier", HFILL }},
{ &hf_p7_probe_submission_time,
{ "probe-submission-time", "p7.probe_submission_time",
FT_STRING, BASE_NONE, NULL, 0,
"ProbeSubmissionTime", HFILL }},
{ &hf_p7_ms_probe_result,
{ "ms-probe-result", "p7.ms_probe_result_element",
FT_NONE, BASE_NONE, NULL, 0,
"CommonSubmissionResults", HFILL }},
{ &hf_p7_attribute_problems,
{ "problems", "p7.problems",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeProblems", HFILL }},
{ &hf_p7_attribute_problem_item,
{ "problems item", "p7.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeProblemItem", HFILL }},
{ &hf_p7_attribute_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_AttributeProblem_vals), 0,
"AttributeProblem", HFILL }},
{ &hf_p7_attr_value,
{ "value", "p7.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_attr_value", HFILL }},
{ &hf_p7_auto_action_request_problems,
{ "problems", "p7.problems",
FT_UINT32, BASE_DEC, NULL, 0,
"AutoActionRequestProblems", HFILL }},
{ &hf_p7_auto_action_request_problem_item,
{ "problems item", "p7.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"AutoActionRequestProblemItem", HFILL }},
{ &hf_p7_auto_action_request_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_AutoActionRequestProblem_vals), 0,
"AutoActionRequestProblem", HFILL }},
{ &hf_p7_delete_problems,
{ "problems", "p7.problems",
FT_UINT32, BASE_DEC, NULL, 0,
"DeleteProblems", HFILL }},
{ &hf_p7_delete_problem_item,
{ "problems item", "p7.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteProblemItem", HFILL }},
{ &hf_p7_delete_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_DeleteProblem_vals), 0,
"DeleteProblem", HFILL }},
{ &hf_p7_entries_deleted,
{ "entries-deleted", "p7.entries_deleted",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_ub_messages_OF_SequenceNumber", HFILL }},
{ &hf_p7_entries_deleted_item,
{ "SequenceNumber", "p7.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p7_fetch_restriction_problems,
{ "problems", "p7.problems",
FT_UINT32, BASE_DEC, NULL, 0,
"FetchRestrictionProblems", HFILL }},
{ &hf_p7_fetch_restriction_problem_item,
{ "problems item", "p7.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"FetchRestrictionProblemItem", HFILL }},
{ &hf_p7_fetch_restriction_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_FetchRestrictionProblem_vals), 0,
"FetchRestrictionProblem", HFILL }},
{ &hf_p7_restriction,
{ "restriction", "p7.restriction",
FT_UINT32, BASE_DEC, VALS(p7_T_restriction_vals), 0,
NULL, HFILL }},
{ &hf_p7_extended_content_type,
{ "content-type", "p7.content_type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_eit,
{ "eit", "p7.eit",
FT_UINT32, BASE_DEC, NULL, 0,
"MS_EITs", HFILL }},
{ &hf_p7_attribute_length,
{ "attribute-length", "p7.attribute_length",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p7_range_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_RangeProblem_vals), 0,
"RangeProblem", HFILL }},
{ &hf_p7_sequence_number_problems,
{ "problems", "p7.problems",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumberProblems", HFILL }},
{ &hf_p7_sequence_number_problem_item,
{ "problems item", "p7.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"SequenceNumberProblemItem", HFILL }},
{ &hf_p7_sequence_number_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_SequenceNumberProblem_vals), 0,
"SequenceNumberProblem", HFILL }},
{ &hf_p7_service_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_ServiceProblem_vals), 0,
"ServiceProblem", HFILL }},
{ &hf_p7_message_group_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_MessageGroupProblem_vals), 0,
"MessageGroupProblem", HFILL }},
{ &hf_p7_name,
{ "name", "p7.name",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageGroupName", HFILL }},
{ &hf_p7_ms_extension_problem,
{ "ms-extension-problem", "p7.ms_extension_problem_element",
FT_NONE, BASE_NONE, NULL, 0,
"MSExtensionItem", HFILL }},
{ &hf_p7_unknown_ms_extension,
{ "unknown-ms-extension", "p7.unknown_ms_extension",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p7_register_ms_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_RegistrationProblem_vals), 0,
"RegistrationProblem", HFILL }},
{ &hf_p7_registration_type,
{ "registration-type", "p7.registration_type_element",
FT_NONE, BASE_NONE, NULL, 0,
"RegistrationTypes", HFILL }},
{ &hf_p7_failing_entry,
{ "failing-entry", "p7.failing_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_modification_number,
{ "modification-number", "p7.modification_number",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p7_modify_problem,
{ "problem", "p7.problem",
FT_UINT32, BASE_DEC, VALS(p7_ModifyProblem_vals), 0,
"ModifyProblem", HFILL }},
{ &hf_p7_entry_class_problem,
{ "problem", "p7.problem",
FT_BYTES, BASE_NONE, NULL, 0,
"T_entry_class_problem", HFILL }},
{ &hf_p7_no_correlated_reports,
{ "no-correlated-reports", "p7.no_correlated_reports_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_location,
{ "location", "p7.location",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PerRecipientReport", HFILL }},
{ &hf_p7_location_item,
{ "PerRecipientReport", "p7.PerRecipientReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_report_entry,
{ "report-entry", "p7.report_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p7_position,
{ "position", "p7.position",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_ub_recipients", HFILL }},
{ &hf_p7_submission_control_violated,
{ "submission-control-violated", "p7.submission_control_violated_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_originator_invalid,
{ "originator-invalid", "p7.originator_invalid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_recipient_improperly_specified,
{ "recipient-improperly-specified", "p7.recipient_improperly_specified",
FT_UINT32, BASE_DEC, NULL, 0,
"ImproperlySpecifiedRecipients", HFILL }},
{ &hf_p7_element_of_service_not_subscribed,
{ "element-of-service-not-subscribed", "p7.element_of_service_not_subscribed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_inconsistent_request,
{ "inconsistent-request", "p7.inconsistent_request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_security_error,
{ "security-error", "p7.security_error",
FT_UINT32, BASE_DEC, VALS(p1_SecurityProblem_vals), 0,
"SecurityProblem", HFILL }},
{ &hf_p7_unsupported_critical_function,
{ "unsupported-critical-function", "p7.unsupported_critical_function_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_remote_bind_error,
{ "remote-bind-error", "p7.remote_bind_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_service_error,
{ "service-error", "p7.service_error_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceErrorParameter", HFILL }},
{ &hf_p7_message_group_error,
{ "message-group-error", "p7.message_group_error_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageGroupErrorParameter", HFILL }},
{ &hf_p7_ms_extension_error,
{ "ms-extension-error", "p7.ms_extension_error",
FT_UINT32, BASE_DEC, VALS(p7_MSExtensionErrorParameter_vals), 0,
"MSExtensionErrorParameter", HFILL }},
{ &hf_p7_entry_class_error,
{ "entry-class-error", "p7.entry_class_error_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryClassErrorParameter", HFILL }},
{ &hf_p7_content_integrity_check,
{ "content-integrity-check", "p7.content_integrity_check",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_message_origin_authentication_check,
{ "message-origin-authentication-check", "p7.message_origin_authentication_check",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_message_token,
{ "message-token", "p7.message_token",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_report_origin_authentication_check,
{ "report-origin-authentication-check", "p7.report_origin_authentication_check",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_proof_of_delivery,
{ "proof-of-delivery", "p7.proof_of_delivery",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_proof_of_submission,
{ "proof-of-submission", "p7.proof_of_submission",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p7_rtorq_apdu,
{ "rtorq-apdu", "p7.rtorq_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORQapdu", HFILL }},
{ &hf_p7_rtoac_apdu,
{ "rtoac-apdu", "p7.rtoac_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTOACapdu", HFILL }},
{ &hf_p7_rtorj_apdu,
{ "rtorj-apdu", "p7.rtorj_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORJapdu", HFILL }},
{ &hf_p7_rttp_apdu,
{ "rttp-apdu", "p7.rttp_apdu",
FT_INT32, BASE_DEC, NULL, 0,
"RTTPapdu", HFILL }},
{ &hf_p7_rttr_apdu,
{ "rttr-apdu", "p7.rttr_apdu",
FT_BYTES, BASE_NONE, NULL, 0,
"RTTRapdu", HFILL }},
{ &hf_p7_rtab_apdu,
{ "rtab-apdu", "p7.rtab_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTABapdu", HFILL }},
{ &hf_p7_abortReason,
{ "abortReason", "p7.abortReason",
FT_INT32, BASE_DEC, VALS(p7_AbortReason_vals), 0,
NULL, HFILL }},
{ &hf_p7_reflectedParameter,
{ "reflectedParameter", "p7.reflectedParameter",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_p7_userdataAB,
{ "userdataAB", "p7.userdataAB_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p7_OverrideRestrictions_override_content_types_restriction,
{ "override-content-types-restriction", "p7.override-content-types-restriction",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p7_OverrideRestrictions_override_EITs_restriction,
{ "override-EITs-restriction", "p7.override-EITs-restriction",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p7_OverrideRestrictions_override_attribute_length_restriction,
{ "override-attribute-length-restriction", "p7.override-attribute-length-restriction",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_p7_T_registrations_auto_action_registrations,
{ "auto-action-registrations", "p7.auto-action-registrations",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p7_T_registrations_list_attribute_defaults,
{ "list-attribute-defaults", "p7.list-attribute-defaults",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p7_T_registrations_fetch_attribute_defaults,
{ "fetch-attribute-defaults", "p7.fetch-attribute-defaults",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_p7_T_registrations_ua_registrations,
{ "ua-registrations", "p7.ua-registrations",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_p7_T_registrations_submission_defaults,
{ "submission-defaults", "p7.submission-defaults",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_p7_T_registrations_message_group_registrations,
{ "message-group-registrations", "p7.message-group-registrations",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_p7_T_entry_class_problem_unsupported_entry_class,
{ "unsupported-entry-class", "p7.unsupported-entry-class",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p7_T_entry_class_problem_entry_class_not_subscribed,
{ "entry-class-not-subscribed", "p7.entry-class-not-subscribed",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p7_T_entry_class_problem_inappropriate_entry_class,
{ "inappropriate-entry-class", "p7.inappropriate-entry-class",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 85 "./asn1/p7/packet-p7-template.c"
};
static gint *ett[] = {
&ett_p7,
#line 1 "./asn1/p7/packet-p7-ettarr.c"
&ett_p7_Attribute,
&ett_p7_AttributeValues,
&ett_p7_AutoActionRegistration,
&ett_p7_AutoActionError,
&ett_p7_MSExtensions,
&ett_p7_MessageGroupName,
&ett_p7_MSBindArgument,
&ett_p7_Restrictions,
&ett_p7_T_allowed_content_types,
&ett_p7_MS_EITs,
&ett_p7_MSBindResult,
&ett_p7_SET_SIZE_1_ub_auto_actions_OF_AutoActionType,
&ett_p7_SET_SIZE_1_ub_attributes_supported_OF_AttributeType,
&ett_p7_T_content_types_supported,
&ett_p7_SET_SIZE_1_ub_entry_classes_OF_EntryClass,
&ett_p7_T_matching_rules_supported,
&ett_p7_T_unsupported_extensions,
&ett_p7_ChangeCredentialsAlgorithms,
&ett_p7_AutoActionErrorIndication,
&ett_p7_PAR_ms_bind_error,
&ett_p7_T_qualified_error,
&ett_p7_T_bind_extension_errors,
&ett_p7_Range,
&ett_p7_NumberRange,
&ett_p7_TimeRange,
&ett_p7_Filter,
&ett_p7_SET_OF_Filter,
&ett_p7_FilterItem,
&ett_p7_T_substrings,
&ett_p7_T_strings,
&ett_p7_T_strings_item,
&ett_p7_MatchingRuleAssertion,
&ett_p7_AttributeValueAssertion,
&ett_p7_Selector,
&ett_p7_OverrideRestrictions,
&ett_p7_EntryInformationSelection,
&ett_p7_AttributeSelection,
&ett_p7_EntryInformation,
&ett_p7_SET_SIZE_1_ub_per_entry_OF_Attribute,
&ett_p7_SET_SIZE_1_ub_per_entry_OF_AttributeValueCount,
&ett_p7_AttributeValueCount,
&ett_p7_MSSubmissionOptions,
&ett_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupName,
&ett_p7_CommonSubmissionResults,
&ett_p7_SummarizeArgument,
&ett_p7_SEQUENCE_SIZE_1_ub_summaries_OF_AttributeType,
&ett_p7_SummarizeResult,
&ett_p7_SEQUENCE_SIZE_1_ub_summaries_OF_Summary,
&ett_p7_Span,
&ett_p7_Summary,
&ett_p7_T_summary_present,
&ett_p7_T_summary_present_item,
&ett_p7_ListArgument,
&ett_p7_ListResult,
&ett_p7_SEQUENCE_SIZE_1_ub_messages_OF_EntryInformation,
&ett_p7_FetchArgument,
&ett_p7_T_item,
&ett_p7_FetchResult,
&ett_p7_SEQUENCE_SIZE_1_ub_messages_OF_SequenceNumber,
&ett_p7_DeleteArgument,
&ett_p7_T_items,
&ett_p7_SET_SIZE_1_ub_messages_OF_SequenceNumber,
&ett_p7_DeleteResult,
&ett_p7_T_delete_result_94,
&ett_p7_Register_MSArgument,
&ett_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionRegistration,
&ett_p7_SET_SIZE_1_ub_auto_registrations_OF_AutoActionDeregistration,
&ett_p7_SET_SIZE_0_ub_default_registrations_OF_AttributeType,
&ett_p7_T_change_credentials,
&ett_p7_SET_SIZE_1_ub_labels_and_redirections_OF_SecurityLabel,
&ett_p7_SET_SIZE_1_ub_ua_registrations_OF_UARegistration,
&ett_p7_AutoActionDeregistration,
&ett_p7_UARegistration,
&ett_p7_MessageGroupRegistrations,
&ett_p7_MessageGroupRegistrations_item,
&ett_p7_MessageGroupNameAndDescriptor,
&ett_p7_RegistrationTypes,
&ett_p7_T_registrations,
&ett_p7_T_extended_registrations,
&ett_p7_MessageGroupsRestriction,
&ett_p7_ProtectedChangeCredentials,
&ett_p7_Register_MSResult,
&ett_p7_T_registered_information,
&ett_p7_SET_SIZE_1_ub_default_registrations_OF_AttributeType,
&ett_p7_SET_SIZE_1_ub_message_groups_OF_MessageGroupNameAndDescriptor,
&ett_p7_AlertArgument,
&ett_p7_ModifyArgument,
&ett_p7_T_entries,
&ett_p7_SEQUENCE_SIZE_1_ub_modifications_OF_EntryModification,
&ett_p7_EntryModification,
&ett_p7_T_modification,
&ett_p7_OrderedAttribute,
&ett_p7_OrderedAttributeValues,
&ett_p7_OrderedAttributeItem,
&ett_p7_ModifyResult,
&ett_p7_MSMessageSubmissionArgument,
&ett_p7_MSMessageSubmissionResult,
&ett_p7_T_mts_result,
&ett_p7_SET_OF_ExtensionField,
&ett_p7_MSProbeSubmissionArgument,
&ett_p7_SEQUENCE_OF_PerRecipientProbeSubmissionFields,
&ett_p7_MSProbeSubmissionResult,
&ett_p7_PAR_attribute_error,
&ett_p7_AttributeProblems,
&ett_p7_AttributeProblemItem,
&ett_p7_PAR_auto_action_request_error,
&ett_p7_AutoActionRequestProblems,
&ett_p7_AutoActionRequestProblemItem,
&ett_p7_PAR_delete_error,
&ett_p7_DeleteProblems,
&ett_p7_DeleteProblemItem,
&ett_p7_PAR_fetch_restriction_error,
&ett_p7_FetchRestrictionProblems,
&ett_p7_FetchRestrictionProblemItem,
&ett_p7_T_restriction,
&ett_p7_PAR_range_error,
&ett_p7_PAR_sequence_number_error,
&ett_p7_SequenceNumberProblems,
&ett_p7_SequenceNumberProblemItem,
&ett_p7_ServiceErrorParameter,
&ett_p7_MessageGroupErrorParameter,
&ett_p7_MSExtensionErrorParameter,
&ett_p7_PAR_register_ms_error,
&ett_p7_ModifyErrorParameter,
&ett_p7_EntryClassErrorParameter,
&ett_p7_T_entry_class_problem,
&ett_p7_ReportLocation,
&ett_p7_SEQUENCE_OF_PerRecipientReport,
&ett_p7_PerRecipientReport,
&ett_p7_SubmissionError,
&ett_p7_SignatureVerificationStatus,
&ett_p7_RTSE_apdus,
&ett_p7_RTABapdu,
#line 91 "./asn1/p7/packet-p7-template.c"
};
module_t *p7_module;
proto_p7 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_p7, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
p7_module = prefs_register_protocol_subtree("OSI/X.400", proto_p7, NULL);
prefs_register_obsolete_preference(p7_module, "tcp.port");
prefs_register_static_text_preference(p7_module, "tcp_port_info",
"The TCP ports used by the P7 protocol should be added to the TPKT preference \"TPKT TCP ports\", or by selecting \"TPKT\" as the \"Transport\" protocol in the \"Decode As\" dialog.",
"P7 TCP Port preference moved information");
}
void proto_reg_handoff_p7(void) {
#line 1 "./asn1/p7/packet-p7-dis-tab.c"
register_ber_oid_dissector("2.6.4.3.42", dissect_ReportLocation_PDU, proto_p7, "id-att-ac-correlated-report-list");
register_ber_oid_dissector("2.6.4.3.76", dissect_SequenceNumber_PDU, proto_p7, "id-att-ac-report-subject-entry");
register_ber_oid_dissector("2.6.4.3.43", dissect_ReportSummary_PDU, proto_p7, "id-att-ac-report-summary");
register_ber_oid_dissector("2.6.4.3.44", dissect_PerRecipientReport_PDU, proto_p7, "id-att-ac-uncorrelated-report-list");
register_ber_oid_dissector("2.6.4.3.46", dissect_AutoActionError_PDU, proto_p7, "id-att-auto-action-error");
register_ber_oid_dissector("2.6.4.3.48", dissect_SequenceNumber_PDU, proto_p7, "id-att-auto-action-subject-entry");
register_ber_oid_dissector("2.6.4.3.49", dissect_AutoActionType_PDU, proto_p7, "id-att-auto-action-type");
register_ber_oid_dissector("2.6.4.3.0", dissect_SequenceNumber_PDU, proto_p7, "id-att-child-sequence-numbers");
register_ber_oid_dissector("2.6.4.3.10", dissect_MS_EIT_PDU, proto_p7, "id-att-converted-EITs");
register_ber_oid_dissector("2.6.4.3.11", dissect_CreationTime_PDU, proto_p7, "id-att-creation-time");
register_ber_oid_dissector("2.6.4.3.50", dissect_DeferredDeliveryCancellationTime_PDU, proto_p7, "id-att-deferred-delivery-cancellation-time");
register_ber_oid_dissector("2.6.4.3.52", dissect_DeletionTime_PDU, proto_p7, "id-att-deletion-time");
register_ber_oid_dissector("2.6.4.3.12", dissect_MS_EIT_PDU, proto_p7, "id-att-delivered-EITs");
register_ber_oid_dissector("2.6.4.3.16", dissect_EntryType_PDU, proto_p7, "id-att-entry-type");
register_ber_oid_dissector("2.6.4.3.57", dissect_MessageGroupName_PDU, proto_p7, "id-att-message-group-name");
register_ber_oid_dissector("2.6.4.3.61", dissect_SubmissionError_PDU, proto_p7, "id-att-ms-submission-error");
register_ber_oid_dissector("2.6.4.3.25", dissect_MS_EIT_PDU, proto_p7, "id-att-original-EITs");
register_ber_oid_dissector("2.6.4.3.29", dissect_SequenceNumber_PDU, proto_p7, "id-att-parent-sequence-number");
register_ber_oid_dissector("2.6.4.3.15", dissect_RetrievalStatus_PDU, proto_p7, "id-att-retrieval-status");
register_ber_oid_dissector("2.6.4.3.39", dissect_SequenceNumber_PDU, proto_p7, "id-att-sequence-number");
register_ber_oid_dissector("2.6.4.3.79", dissect_SignatureVerificationStatus_PDU, proto_p7, "id-att-signature-verification-status");
register_ber_oid_dissector("2.6.4.3.73", dissect_StoragePeriod_PDU, proto_p7, "id-att-storage-period");
register_ber_oid_dissector("2.6.4.3.74", dissect_StorageTime_PDU, proto_p7, "id-att-storage-time");
register_ber_oid_dissector("2.6.4.9.5", dissect_ChangeCredentialsAlgorithms_PDU, proto_p7, "id-ext-protected-change-credentials-capability");
register_ber_oid_dissector("2.6.4.9.3", dissect_OriginatorToken_PDU, proto_p7, "id-ext-originator-token");
register_ber_oid_dissector("2.6.4.9.4", dissect_ProtectedChangeCredentials_PDU, proto_p7, "id-ext-protected-change-credentials");
register_ber_oid_dissector("2.6.0.2.10""id-as-ms-rtse", dissect_RTSE_apdus_PDU, proto_p7, "");
#line 117 "./asn1/p7/packet-p7-template.c"
oid_add_from_string("id-ac-ms-access","2.6.0.1.11");
oid_add_from_string("id-ac-ms-reliable-access","2.6.0.1.12");
register_ros_protocol_info("2.6.0.2.9", &p7_ros_info, 0, "id-as-ms", FALSE);
register_ros_protocol_info("2.6.0.2.5", &p7_ros_info, 0, "id-as-mrse", FALSE);
register_ros_protocol_info("2.6.0.2.1", &p7_ros_info, 0, "id-as-msse", FALSE);
}
