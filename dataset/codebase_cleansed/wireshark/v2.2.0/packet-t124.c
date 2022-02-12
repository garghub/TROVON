static int
dissect_t124_DynamicChannelID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1001U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_t124_UserID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_DynamicChannelID(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_H221NonStandardIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 217 "./asn1/t124/t124.cnf"
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 255, FALSE, (tvbuff_t**)&actx->private_data);
return offset;
}
static int
dissect_t124_T_object(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &actx->external.direct_reference);
return offset;
}
static int
dissect_t124_Key(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_Key, Key_choice,
NULL);
return offset;
}
static int
dissect_t124_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_t124_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_NonStandardParameter, NonStandardParameter_sequence);
return offset;
}
static int
dissect_t124_TextString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
0, 255, FALSE);
return offset;
}
static int
dissect_t124_SimpleTextString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
0, 255, FALSE);
return offset;
}
static int
dissect_t124_SimpleNumericString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_t124_DiallingString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_t124_SubAddressString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,
1, 40, FALSE, "0123456789", 10,
NULL);
return offset;
}
static int
dissect_t124_ExtraDiallingString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_size_constrained_type(tvb, offset, actx, tree, hf_index, dissect_t124_TextString,
"TextString", 1, 255, FALSE);
return offset;
}
static int
dissect_t124_T_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 149 "./asn1/t124/t124.cnf"
tvbuff_t *next_tvb = NULL;
tvbuff_t *t124NSIdentifier = (tvbuff_t*)actx->private_data;
guint8 *ns = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if(next_tvb && t124NSIdentifier) {
ns = tvb_get_string_enc(wmem_packet_scope(), t124NSIdentifier, 0, tvb_reported_length(t124NSIdentifier), ENC_ASCII|ENC_NA);
if(ns != NULL) {
dissector_try_string(t124_ns_dissector_table, ns, next_tvb, actx->pinfo, top_tree, NULL);
}
}
return offset;
}
static int
dissect_t124_UserData_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_UserData_item, UserData_item_sequence);
return offset;
}
static int
dissect_t124_UserData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_UserData, UserData_set_of);
return offset;
}
static int
dissect_t124_Password(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_Password, Password_sequence);
return offset;
}
static int
dissect_t124_PasswordSelector(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_PasswordSelector, PasswordSelector_choice,
NULL);
return offset;
}
static int
dissect_t124_ChallengeResponseItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ChallengeResponseItem, ChallengeResponseItem_choice,
NULL);
return offset;
}
static int
dissect_t124_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_ChallengeResponseAlgorithm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ChallengeResponseAlgorithm, ChallengeResponseAlgorithm_choice,
NULL);
return offset;
}
static int
dissect_t124_ChallengeItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChallengeItem, ChallengeItem_sequence);
return offset;
}
static int
dissect_t124_INTEGER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_t124_SET_OF_ChallengeItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_ChallengeItem, SET_OF_ChallengeItem_set_of);
return offset;
}
static int
dissect_t124_ChallengeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChallengeRequest, ChallengeRequest_sequence);
return offset;
}
static int
dissect_t124_ChallengeResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChallengeResponse, ChallengeResponse_sequence);
return offset;
}
static int
dissect_t124_T_challengeRequestResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_challengeRequestResponse, T_challengeRequestResponse_sequence);
return offset;
}
static int
dissect_t124_PasswordChallengeRequestResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_PasswordChallengeRequestResponse, PasswordChallengeRequestResponse_choice,
NULL);
return offset;
}
static int
dissect_t124_ConferenceName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceName, ConferenceName_sequence);
return offset;
}
static int
dissect_t124_ConferenceNameSelector(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceNameSelector, ConferenceNameSelector_choice,
NULL);
return offset;
}
static int
dissect_t124_ConferenceNameModifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_SimpleNumericString(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_Privilege(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_TerminationMethod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_ConferencePriorityScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ConferencePriorityScheme, ConferencePriorityScheme_choice,
NULL);
return offset;
}
static int
dissect_t124_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_t124_ConferencePriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferencePriority, ConferencePriority_sequence);
return offset;
}
static int
dissect_t124_NodeCategory(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_NodeCategory, NodeCategory_choice,
NULL);
return offset;
}
static int
dissect_t124_ConferenceMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceMode, ConferenceMode_choice,
NULL);
return offset;
}
static int
dissect_t124_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_t124_T_transferModes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_transferModes, T_transferModes_sequence);
return offset;
}
static int
dissect_t124_T_highLayerCompatibility(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_highLayerCompatibility, T_highLayerCompatibility_sequence);
return offset;
}
static int
dissect_t124_T_aggregatedChannel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_aggregatedChannel, T_aggregatedChannel_sequence);
return offset;
}
static int
dissect_t124_OCTET_STRING_SIZE_1_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 20, FALSE, NULL);
return offset;
}
static int
dissect_t124_T_transportConnection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_transportConnection, T_transportConnection_sequence);
return offset;
}
static int
dissect_t124_NetworkAddress_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_NetworkAddress_item, NetworkAddress_item_choice,
NULL);
return offset;
}
static int
dissect_t124_NetworkAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_t124_NetworkAddress, NetworkAddress_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_t124_NodeType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_t124_AsymmetryIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_AsymmetryIndicator, AsymmetryIndicator_choice,
NULL);
return offset;
}
static int
dissect_t124_ConferenceDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceDescriptor, ConferenceDescriptor_sequence);
return offset;
}
static int
dissect_t124_SET_OF_Privilege(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_Privilege, SET_OF_Privilege_set_of);
return offset;
}
static int
dissect_t124_ConferenceCreateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceCreateRequest, ConferenceCreateRequest_sequence);
return offset;
}
static int
dissect_t124_T_result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_ConferenceCreateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceCreateResponse, ConferenceCreateResponse_sequence);
return offset;
}
static int
dissect_t124_ConferenceQueryRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceQueryRequest, ConferenceQueryRequest_sequence);
return offset;
}
static int
dissect_t124_SET_OF_ConferenceDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_ConferenceDescriptor, SET_OF_ConferenceDescriptor_set_of);
return offset;
}
static int
dissect_t124_QueryResponseResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_ConferenceQueryResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceQueryResponse, ConferenceQueryResponse_sequence);
return offset;
}
static int
dissect_t124_ConferenceJoinRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceJoinRequest, ConferenceJoinRequest_sequence);
return offset;
}
static int
dissect_t124_JoinResponseResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_ConferenceJoinResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceJoinResponse, ConferenceJoinResponse_sequence);
return offset;
}
static int
dissect_t124_ConferenceInviteRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceInviteRequest, ConferenceInviteRequest_sequence);
return offset;
}
static int
dissect_t124_InviteResponseResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_t124_ConferenceInviteResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConferenceInviteResponse, ConferenceInviteResponse_sequence);
return offset;
}
static int
dissect_t124_T_connectPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "./asn1/t124/t124.cnf"
tvbuff_t *next_tvb = NULL;
proto_tree *next_tree = NULL;
int old_offset = 0;
old_offset = offset;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if(next_tvb) {
if(tvb_reported_length(next_tvb) == 42) {
next_tvb = tvb_new_subset_remaining(tvb, (old_offset>>3)+1);
}
next_tree = proto_item_add_subtree(actx->created_item, ett_t124_connectGCCPDU);
dissect_t124_ConnectGCCPDU(next_tvb, 0, actx, next_tree, hf_t124_connectGCCPDU);
}
return offset;
}
int
dissect_t124_ConnectData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ConnectData, ConnectData_sequence);
return offset;
}
int
dissect_t124_ConnectGCCPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ConnectGCCPDU, ConnectGCCPDU_choice,
NULL);
return offset;
}
static int
dissect_t124_ChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 222 "./asn1/t124/t124.cnf"
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &channelId, FALSE);
if(hf_index == hf_t124_channelId_03)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%d", channelId);
return offset;
}
static int
dissect_t124_StaticChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_ChannelId(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_DynamicChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_ChannelId(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_UserId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_DynamicChannelId(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_PrivateChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_DynamicChannelId(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_AssignedChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_t124_DynamicChannelId(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_t124_TokenId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_t124_TokenStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_t124_DataPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_t124_Segmentation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL, NULL);
return offset;
}
static int
dissect_t124_INTEGER_0_MAX(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, NO_BOUND, NULL, FALSE);
return offset;
}
static int
dissect_t124_PlumbDomainIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_PlumbDomainIndication, PlumbDomainIndication_sequence);
return offset;
}
static int
dissect_t124_ErectDomainRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ErectDomainRequest, ErectDomainRequest_sequence);
return offset;
}
static int
dissect_t124_T_static(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_static, T_static_sequence);
return offset;
}
static int
dissect_t124_T_userId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_userId, T_userId_sequence);
return offset;
}
static int
dissect_t124_SET_OF_UserId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_UserId, SET_OF_UserId_set_of);
return offset;
}
static int
dissect_t124_T_private(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_private, T_private_sequence);
return offset;
}
static int
dissect_t124_T_assigned(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_assigned, T_assigned_sequence);
return offset;
}
static int
dissect_t124_ChannelAttributes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelAttributes, ChannelAttributes_choice,
NULL);
return offset;
}
static int
dissect_t124_SET_OF_ChannelAttributes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_ChannelAttributes, SET_OF_ChannelAttributes_set_of);
return offset;
}
static int
dissect_t124_SET_OF_ChannelId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_ChannelId, SET_OF_ChannelId_set_of);
return offset;
}
static int
dissect_t124_MergeChannelsRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_MergeChannelsRequest, MergeChannelsRequest_sequence);
return offset;
}
static int
dissect_t124_MergeChannelsConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_MergeChannelsConfirm, MergeChannelsConfirm_sequence);
return offset;
}
static int
dissect_t124_PurgeChannelsIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_PurgeChannelsIndication, PurgeChannelsIndication_sequence);
return offset;
}
static int
dissect_t124_T_grabbed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_grabbed, T_grabbed_sequence);
return offset;
}
static int
dissect_t124_T_inhibited(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_inhibited, T_inhibited_sequence);
return offset;
}
static int
dissect_t124_T_giving(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_giving, T_giving_sequence);
return offset;
}
static int
dissect_t124_T_ungivable(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_ungivable, T_ungivable_sequence);
return offset;
}
static int
dissect_t124_T_given(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_T_given, T_given_sequence);
return offset;
}
static int
dissect_t124_TokenAttributes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_TokenAttributes, TokenAttributes_choice,
NULL);
return offset;
}
static int
dissect_t124_SET_OF_TokenAttributes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_TokenAttributes, SET_OF_TokenAttributes_set_of);
return offset;
}
static int
dissect_t124_SET_OF_TokenId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_t124_SET_OF_TokenId, SET_OF_TokenId_set_of);
return offset;
}
static int
dissect_t124_MergeTokensRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_MergeTokensRequest, MergeTokensRequest_sequence);
return offset;
}
static int
dissect_t124_MergeTokensConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_MergeTokensConfirm, MergeTokensConfirm_sequence);
return offset;
}
static int
dissect_t124_PurgeTokensIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_PurgeTokensIndication, PurgeTokensIndication_sequence);
return offset;
}
static int
dissect_t124_Reason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_t124_DisconnectProviderUltimatum(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_DisconnectProviderUltimatum, DisconnectProviderUltimatum_sequence);
return offset;
}
static int
dissect_t124_Diagnostic(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
14, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_t124_RejectMCSPDUUltimatum(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_RejectMCSPDUUltimatum, RejectMCSPDUUltimatum_sequence);
return offset;
}
static int
dissect_t124_AttachUserRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_AttachUserRequest, AttachUserRequest_sequence);
return offset;
}
static int
dissect_t124_Result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_t124_AttachUserConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_AttachUserConfirm, AttachUserConfirm_sequence);
return offset;
}
static int
dissect_t124_DetachUserRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_DetachUserRequest, DetachUserRequest_sequence);
return offset;
}
static int
dissect_t124_DetachUserIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_DetachUserIndication, DetachUserIndication_sequence);
return offset;
}
static int
dissect_t124_ChannelJoinRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelJoinRequest, ChannelJoinRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelJoinConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelJoinConfirm, ChannelJoinConfirm_sequence);
return offset;
}
static int
dissect_t124_ChannelLeaveRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelLeaveRequest, ChannelLeaveRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelConveneRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelConveneRequest, ChannelConveneRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelConveneConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelConveneConfirm, ChannelConveneConfirm_sequence);
return offset;
}
static int
dissect_t124_ChannelDisbandRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelDisbandRequest, ChannelDisbandRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelDisbandIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelDisbandIndication, ChannelDisbandIndication_sequence);
return offset;
}
static int
dissect_t124_ChannelAdmitRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelAdmitRequest, ChannelAdmitRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelAdmitIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelAdmitIndication, ChannelAdmitIndication_sequence);
return offset;
}
static int
dissect_t124_ChannelExpelRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelExpelRequest, ChannelExpelRequest_sequence);
return offset;
}
static int
dissect_t124_ChannelExpelIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_ChannelExpelIndication, ChannelExpelIndication_sequence);
return offset;
}
static int
dissect_t124_T_userData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 166 "./asn1/t124/t124.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if(next_tvb) {
dissector_try_uint(t124_sd_dissector_table, channelId, next_tvb, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_t124_SendDataRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_SendDataRequest, SendDataRequest_sequence);
return offset;
}
static int
dissect_t124_T_userData_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 179 "./asn1/t124/t124.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if(next_tvb) {
dissector_try_uint(t124_sd_dissector_table, channelId, next_tvb, actx->pinfo, top_tree);
}
return offset;
}
static int
dissect_t124_SendDataIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_SendDataIndication, SendDataIndication_sequence);
return offset;
}
static int
dissect_t124_UniformSendDataRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_UniformSendDataRequest, UniformSendDataRequest_sequence);
return offset;
}
static int
dissect_t124_UniformSendDataIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_UniformSendDataIndication, UniformSendDataIndication_sequence);
return offset;
}
static int
dissect_t124_TokenGrabRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGrabRequest, TokenGrabRequest_sequence);
return offset;
}
static int
dissect_t124_TokenGrabConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGrabConfirm, TokenGrabConfirm_sequence);
return offset;
}
static int
dissect_t124_TokenInhibitRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenInhibitRequest, TokenInhibitRequest_sequence);
return offset;
}
static int
dissect_t124_TokenInhibitConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenInhibitConfirm, TokenInhibitConfirm_sequence);
return offset;
}
static int
dissect_t124_TokenGiveRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGiveRequest, TokenGiveRequest_sequence);
return offset;
}
static int
dissect_t124_TokenGiveIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGiveIndication, TokenGiveIndication_sequence);
return offset;
}
static int
dissect_t124_TokenGiveResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGiveResponse, TokenGiveResponse_sequence);
return offset;
}
static int
dissect_t124_TokenGiveConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenGiveConfirm, TokenGiveConfirm_sequence);
return offset;
}
static int
dissect_t124_TokenPleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenPleaseRequest, TokenPleaseRequest_sequence);
return offset;
}
static int
dissect_t124_TokenPleaseIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenPleaseIndication, TokenPleaseIndication_sequence);
return offset;
}
static int
dissect_t124_TokenReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenReleaseRequest, TokenReleaseRequest_sequence);
return offset;
}
static int
dissect_t124_TokenReleaseConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenReleaseConfirm, TokenReleaseConfirm_sequence);
return offset;
}
static int
dissect_t124_TokenTestRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenTestRequest, TokenTestRequest_sequence);
return offset;
}
static int
dissect_t124_TokenTestConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t124_TokenTestConfirm, TokenTestConfirm_sequence);
return offset;
}
static int
dissect_t124_DomainMCSPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 193 "./asn1/t124/t124.cnf"
gint domainmcs_value;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t124_DomainMCSPDU, DomainMCSPDU_choice,
&domainmcs_value);
switch(domainmcs_value) {
case 25:
case 26:
case 27:
case 28:
break;
default:
col_prepend_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", val_to_str(domainmcs_value, t124_DomainMCSPDU_vals, "Unknown"));
break;
}
return offset;
}
void
register_t124_ns_dissector(const char *nsKey, dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissector, proto);
dissector_add_string("t124.ns", nsKey, dissector_handle);
}
void register_t124_sd_dissector(packet_info *pinfo _U_, guint32 channelId_param, dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissector, proto);
dissector_add_uint("t124.sd", channelId_param, dissector_handle);
}
guint32 t124_get_last_channelId(void)
{
return channelId;
}
void t124_set_top_tree(proto_tree *tree)
{
top_tree = tree;
}
int dissect_DomainMCSPDU_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_t124_DomainMCSPDU(tvb, offset, &asn1_ctx, tree, hf_t124_DomainMCSPDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_t124(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
asn1_ctx_t asn1_ctx;
top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.124");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_t124, tvb, 0, tvb_captured_length(tvb), ENC_NA);
tree = proto_item_add_subtree(item, ett_t124);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_t124_ConnectData(tvb, 0, &asn1_ctx, tree, hf_t124_ConnectData);
return tvb_captured_length(tvb);
}
static gboolean
dissect_t124_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
asn1_ctx_t asn1_ctx;
volatile gboolean failed = FALSE;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
TRY {
(void) dissect_per_sequence(tvb, 0, &asn1_ctx, NULL, hf_t124_connectGCCPDU, -1, t124Heur_sequence);
} CATCH_BOUNDS_ERRORS {
failed = TRUE;
} ENDTRY;
if (!failed && ((asn1_ctx.external.direct_reference != NULL) &&
(strcmp(asn1_ctx.external.direct_reference, "0.0.20.124.0.1") == 0))) {
dissect_t124(tvb, pinfo, parent_tree, data);
return TRUE;
}
return FALSE;
}
void proto_register_t124(void) {
static hf_register_info hf[] = {
{ &hf_t124_ConnectData,
{ "ConnectData", "t124.ConnectData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_connectGCCPDU,
{ "connectGCCPDU", "t124.connectGCCPDU",
FT_UINT32, BASE_DEC, VALS(t124_ConnectGCCPDU_vals), 0,
NULL, HFILL }},
{ &hf_t124_DomainMCSPDU_PDU,
{ "DomainMCSPDU", "t124.DomainMCSPDU",
FT_UINT32, BASE_DEC, VALS(t124_DomainMCSPDU_vals), 0,
NULL, HFILL }},
#line 1 "./asn1/t124/packet-t124-hfarr.c"
{ &hf_t124_object,
{ "object", "t124.object",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_h221NonStandard,
{ "h221NonStandard", "t124.h221NonStandard",
FT_BYTES, BASE_NONE, NULL, 0,
"H221NonStandardIdentifier", HFILL }},
{ &hf_t124_key,
{ "key", "t124.key",
FT_UINT32, BASE_DEC, VALS(t124_Key_vals), 0,
NULL, HFILL }},
{ &hf_t124_data,
{ "data", "t124.data",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t124_UserData_item,
{ "UserData item", "t124.UserData_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_value,
{ "value", "t124.value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_numeric,
{ "numeric", "t124.numeric",
FT_STRING, BASE_NONE, NULL, 0,
"SimpleNumericString", HFILL }},
{ &hf_t124_text,
{ "text", "t124.text",
FT_STRING, BASE_NONE, NULL, 0,
"SimpleTextString", HFILL }},
{ &hf_t124_unicodeText,
{ "unicodeText", "t124.unicodeText",
FT_STRING, BASE_NONE, NULL, 0,
"TextString", HFILL }},
{ &hf_t124_passwordString,
{ "passwordString", "t124.passwordString",
FT_UINT32, BASE_DEC, VALS(t124_PasswordSelector_vals), 0,
"PasswordSelector", HFILL }},
{ &hf_t124_responseData,
{ "responseData", "t124.responseData",
FT_UINT32, BASE_DEC, NULL, 0,
"UserData", HFILL }},
{ &hf_t124_passwordInTheClear,
{ "passwordInTheClear", "t124.passwordInTheClear_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_nonStandardAlgorithm,
{ "nonStandardAlgorithm", "t124.nonStandardAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_t124_responseAlgorithm,
{ "responseAlgorithm", "t124.responseAlgorithm",
FT_UINT32, BASE_DEC, VALS(t124_ChallengeResponseAlgorithm_vals), 0,
"ChallengeResponseAlgorithm", HFILL }},
{ &hf_t124_challengeData,
{ "challengeData", "t124.challengeData",
FT_UINT32, BASE_DEC, NULL, 0,
"UserData", HFILL }},
{ &hf_t124_challengeTag,
{ "challengeTag", "t124.challengeTag",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_t124_challengeSet,
{ "challengeSet", "t124.challengeSet",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ChallengeItem", HFILL }},
{ &hf_t124_challengeSet_item,
{ "ChallengeItem", "t124.ChallengeItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_responseItem,
{ "responseItem", "t124.responseItem",
FT_UINT32, BASE_DEC, VALS(t124_ChallengeResponseItem_vals), 0,
"ChallengeResponseItem", HFILL }},
{ &hf_t124_passwordInTheClear_01,
{ "passwordInTheClear", "t124.passwordInTheClear",
FT_UINT32, BASE_DEC, VALS(t124_PasswordSelector_vals), 0,
"PasswordSelector", HFILL }},
{ &hf_t124_challengeRequestResponse,
{ "challengeRequestResponse", "t124.challengeRequestResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_challengeRequest,
{ "challengeRequest", "t124.challengeRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_challengeResponse,
{ "challengeResponse", "t124.challengeResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_nonStandardScheme,
{ "nonStandardScheme", "t124.nonStandardScheme_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_t124_priority,
{ "priority", "t124.priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_t124_scheme,
{ "scheme", "t124.scheme",
FT_UINT32, BASE_DEC, VALS(t124_ConferencePriorityScheme_vals), 0,
"ConferencePriorityScheme", HFILL }},
{ &hf_t124_conventional,
{ "conventional", "t124.conventional_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_counted,
{ "counted", "t124.counted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_anonymous,
{ "anonymous", "t124.anonymous_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_nonStandardCategory,
{ "nonStandardCategory", "t124.nonStandardCategory_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_t124_conventional_only,
{ "conventional-only", "t124.conventional_only_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_counted_only,
{ "counted-only", "t124.counted_only_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_anonymous_only,
{ "anonymous-only", "t124.anonymous_only_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conventional_control,
{ "conventional-control", "t124.conventional_control_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_unrestricted_mode,
{ "unrestricted-mode", "t124.unrestricted_mode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_non_standard_mode,
{ "non-standard-mode", "t124.non_standard_mode_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_t124_NetworkAddress_item,
{ "NetworkAddress item", "t124.NetworkAddress_item",
FT_UINT32, BASE_DEC, VALS(t124_NetworkAddress_item_vals), 0,
NULL, HFILL }},
{ &hf_t124_aggregatedChannel,
{ "aggregatedChannel", "t124.aggregatedChannel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_transferModes,
{ "transferModes", "t124.transferModes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_speech,
{ "speech", "t124.speech",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_voice_band,
{ "voice-band", "t124.voice_band",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_56k,
{ "digital-56k", "t124.digital_56k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_64k,
{ "digital-64k", "t124.digital_64k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_128k,
{ "digital-128k", "t124.digital_128k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_192k,
{ "digital-192k", "t124.digital_192k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_256k,
{ "digital-256k", "t124.digital_256k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_320k,
{ "digital-320k", "t124.digital_320k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_384k,
{ "digital-384k", "t124.digital_384k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_512k,
{ "digital-512k", "t124.digital_512k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_768k,
{ "digital-768k", "t124.digital_768k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_1152k,
{ "digital-1152k", "t124.digital_1152k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_1472k,
{ "digital-1472k", "t124.digital_1472k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_1536k,
{ "digital-1536k", "t124.digital_1536k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_digital_1920k,
{ "digital-1920k", "t124.digital_1920k",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_packet_mode,
{ "packet-mode", "t124.packet_mode",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_frame_mode,
{ "frame-mode", "t124.frame_mode",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_atm,
{ "atm", "t124.atm",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_internationalNumber,
{ "internationalNumber", "t124.internationalNumber",
FT_STRING, BASE_NONE, NULL, 0,
"DiallingString", HFILL }},
{ &hf_t124_subAddress,
{ "subAddress", "t124.subAddress",
FT_STRING, BASE_NONE, NULL, 0,
"SubAddressString", HFILL }},
{ &hf_t124_extraDialling,
{ "extraDialling", "t124.extraDialling",
FT_STRING, BASE_NONE, NULL, 0,
"ExtraDiallingString", HFILL }},
{ &hf_t124_highLayerCompatibility,
{ "highLayerCompatibility", "t124.highLayerCompatibility_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_telephony3kHz,
{ "telephony3kHz", "t124.telephony3kHz",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_telephony7kHz,
{ "telephony7kHz", "t124.telephony7kHz",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_videotelephony,
{ "videotelephony", "t124.videotelephony",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_videoconference,
{ "videoconference", "t124.videoconference",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_audiographic,
{ "audiographic", "t124.audiographic",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_audiovisual,
{ "audiovisual", "t124.audiovisual",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_multimedia,
{ "multimedia", "t124.multimedia",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_transportConnection,
{ "transportConnection", "t124.transportConnection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_nsapAddress,
{ "nsapAddress", "t124.nsapAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_20", HFILL }},
{ &hf_t124_transportSelector,
{ "transportSelector", "t124.transportSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t124_nonStandard,
{ "nonStandard", "t124.nonStandard_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_t124_callingNode,
{ "callingNode", "t124.callingNode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_calledNode,
{ "calledNode", "t124.calledNode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_unknown,
{ "unknown", "t124.unknown",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_t124_conferenceName,
{ "conferenceName", "t124.conferenceName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceNameModifier,
{ "conferenceNameModifier", "t124.conferenceNameModifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceDescription,
{ "conferenceDescription", "t124.conferenceDescription",
FT_STRING, BASE_NONE, NULL, 0,
"TextString", HFILL }},
{ &hf_t124_lockedConference,
{ "lockedConference", "t124.lockedConference",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_passwordInTheClearRequired,
{ "passwordInTheClearRequired", "t124.passwordInTheClearRequired",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_networkAddress,
{ "networkAddress", "t124.networkAddress",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_defaultConferenceFlag,
{ "defaultConferenceFlag", "t124.defaultConferenceFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_conferenceMode,
{ "conferenceMode", "t124.conferenceMode",
FT_UINT32, BASE_DEC, VALS(t124_ConferenceMode_vals), 0,
NULL, HFILL }},
{ &hf_t124_convenerPassword,
{ "convenerPassword", "t124.convenerPassword_element",
FT_NONE, BASE_NONE, NULL, 0,
"Password", HFILL }},
{ &hf_t124_password,
{ "password", "t124.password_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_listedConference,
{ "listedConference", "t124.listedConference",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_conductibleConference,
{ "conductibleConference", "t124.conductibleConference",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_terminationMethod,
{ "terminationMethod", "t124.terminationMethod",
FT_UINT32, BASE_DEC, VALS(t124_TerminationMethod_vals), 0,
NULL, HFILL }},
{ &hf_t124_conductorPrivileges,
{ "conductorPrivileges", "t124.conductorPrivileges",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Privilege", HFILL }},
{ &hf_t124_conductorPrivileges_item,
{ "Privilege", "t124.Privilege",
FT_UINT32, BASE_DEC, VALS(t124_Privilege_vals), 0,
NULL, HFILL }},
{ &hf_t124_conductedPrivileges,
{ "conductedPrivileges", "t124.conductedPrivileges",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Privilege", HFILL }},
{ &hf_t124_conductedPrivileges_item,
{ "Privilege", "t124.Privilege",
FT_UINT32, BASE_DEC, VALS(t124_Privilege_vals), 0,
NULL, HFILL }},
{ &hf_t124_nonConductedPrivileges,
{ "nonConductedPrivileges", "t124.nonConductedPrivileges",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Privilege", HFILL }},
{ &hf_t124_nonConductedPrivileges_item,
{ "Privilege", "t124.Privilege",
FT_UINT32, BASE_DEC, VALS(t124_Privilege_vals), 0,
NULL, HFILL }},
{ &hf_t124_callerIdentifier,
{ "callerIdentifier", "t124.callerIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
"TextString", HFILL }},
{ &hf_t124_userData,
{ "userData", "t124.userData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferencePriority,
{ "conferencePriority", "t124.conferencePriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_nodeID,
{ "nodeID", "t124.nodeID",
FT_UINT32, BASE_DEC, NULL, 0,
"UserID", HFILL }},
{ &hf_t124_tag,
{ "tag", "t124.tag",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_t124_result,
{ "result", "t124.result",
FT_UINT32, BASE_DEC, VALS(t124_T_result_vals), 0,
NULL, HFILL }},
{ &hf_t124_nodeType,
{ "nodeType", "t124.nodeType",
FT_UINT32, BASE_DEC, VALS(t124_NodeType_vals), 0,
NULL, HFILL }},
{ &hf_t124_asymmetryIndicator,
{ "asymmetryIndicator", "t124.asymmetryIndicator",
FT_UINT32, BASE_DEC, VALS(t124_AsymmetryIndicator_vals), 0,
NULL, HFILL }},
{ &hf_t124_conferenceList,
{ "conferenceList", "t124.conferenceList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ConferenceDescriptor", HFILL }},
{ &hf_t124_conferenceList_item,
{ "ConferenceDescriptor", "t124.ConferenceDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_queryResponseResult,
{ "result", "t124.result",
FT_UINT32, BASE_DEC, VALS(t124_QueryResponseResult_vals), 0,
"QueryResponseResult", HFILL }},
{ &hf_t124_waitForInvitationFlag,
{ "waitForInvitationFlag", "t124.waitForInvitationFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_noUnlistedConferenceFlag,
{ "noUnlistedConferenceFlag", "t124.noUnlistedConferenceFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_conferenceName_01,
{ "conferenceName", "t124.conferenceName",
FT_UINT32, BASE_DEC, VALS(t124_ConferenceNameSelector_vals), 0,
"ConferenceNameSelector", HFILL }},
{ &hf_t124_password_01,
{ "password", "t124.password",
FT_UINT32, BASE_DEC, VALS(t124_PasswordChallengeRequestResponse_vals), 0,
"PasswordChallengeRequestResponse", HFILL }},
{ &hf_t124_convenerPassword_01,
{ "convenerPassword", "t124.convenerPassword",
FT_UINT32, BASE_DEC, VALS(t124_PasswordSelector_vals), 0,
"PasswordSelector", HFILL }},
{ &hf_t124_nodeCategory,
{ "nodeCategory", "t124.nodeCategory",
FT_UINT32, BASE_DEC, VALS(t124_NodeCategory_vals), 0,
NULL, HFILL }},
{ &hf_t124_topNodeID,
{ "topNodeID", "t124.topNodeID",
FT_UINT32, BASE_DEC, NULL, 0,
"UserID", HFILL }},
{ &hf_t124_conferenceNameAlias,
{ "conferenceNameAlias", "t124.conferenceNameAlias",
FT_UINT32, BASE_DEC, VALS(t124_ConferenceNameSelector_vals), 0,
"ConferenceNameSelector", HFILL }},
{ &hf_t124_joinResponseResult,
{ "result", "t124.result",
FT_UINT32, BASE_DEC, VALS(t124_JoinResponseResult_vals), 0,
"JoinResponseResult", HFILL }},
{ &hf_t124_inviteResponseResult,
{ "result", "t124.result",
FT_UINT32, BASE_DEC, VALS(t124_InviteResponseResult_vals), 0,
"InviteResponseResult", HFILL }},
{ &hf_t124_t124Identifier,
{ "t124Identifier", "t124.t124Identifier",
FT_UINT32, BASE_DEC, VALS(t124_Key_vals), 0,
"Key", HFILL }},
{ &hf_t124_connectPDU,
{ "connectPDU", "t124.connectPDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceCreateRequest,
{ "conferenceCreateRequest", "t124.conferenceCreateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceCreateResponse,
{ "conferenceCreateResponse", "t124.conferenceCreateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceQueryRequest,
{ "conferenceQueryRequest", "t124.conferenceQueryRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceQueryResponse,
{ "conferenceQueryResponse", "t124.conferenceQueryResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceJoinRequest,
{ "conferenceJoinRequest", "t124.conferenceJoinRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceJoinResponse,
{ "conferenceJoinResponse", "t124.conferenceJoinResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceInviteRequest,
{ "conferenceInviteRequest", "t124.conferenceInviteRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_conferenceInviteResponse,
{ "conferenceInviteResponse", "t124.conferenceInviteResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_heightLimit,
{ "heightLimit", "t124.heightLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t124_subHeight,
{ "subHeight", "t124.subHeight",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t124_subInterval,
{ "subInterval", "t124.subInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t124_static,
{ "static", "t124.static_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelId,
{ "channelId", "t124.channelId",
FT_UINT32, BASE_DEC, NULL, 0,
"StaticChannelId", HFILL }},
{ &hf_t124_userId,
{ "userId", "t124.userId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_joined,
{ "joined", "t124.joined",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t124_userId_01,
{ "userId", "t124.userId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_private,
{ "private", "t124.private_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelId_01,
{ "channelId", "t124.channelId",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateChannelId", HFILL }},
{ &hf_t124_manager,
{ "manager", "t124.manager",
FT_UINT32, BASE_DEC, NULL, 0,
"UserId", HFILL }},
{ &hf_t124_admitted,
{ "admitted", "t124.admitted",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_UserId", HFILL }},
{ &hf_t124_admitted_item,
{ "UserId", "t124.UserId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_assigned,
{ "assigned", "t124.assigned_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelId_02,
{ "channelId", "t124.channelId",
FT_UINT32, BASE_DEC, NULL, 0,
"AssignedChannelId", HFILL }},
{ &hf_t124_mergeChannels,
{ "mergeChannels", "t124.mergeChannels",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ChannelAttributes", HFILL }},
{ &hf_t124_mergeChannels_item,
{ "ChannelAttributes", "t124.ChannelAttributes",
FT_UINT32, BASE_DEC, VALS(t124_ChannelAttributes_vals), 0,
NULL, HFILL }},
{ &hf_t124_purgeChannelIds,
{ "purgeChannelIds", "t124.purgeChannelIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ChannelId", HFILL }},
{ &hf_t124_purgeChannelIds_item,
{ "ChannelId", "t124.ChannelId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_detachUserIds,
{ "detachUserIds", "t124.detachUserIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_UserId", HFILL }},
{ &hf_t124_detachUserIds_item,
{ "UserId", "t124.UserId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_grabbed,
{ "grabbed", "t124.grabbed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenId,
{ "tokenId", "t124.tokenId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_grabber,
{ "grabber", "t124.grabber",
FT_UINT32, BASE_DEC, NULL, 0,
"UserId", HFILL }},
{ &hf_t124_inhibited,
{ "inhibited", "t124.inhibited_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_inhibitors,
{ "inhibitors", "t124.inhibitors",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_UserId", HFILL }},
{ &hf_t124_inhibitors_item,
{ "UserId", "t124.UserId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_giving,
{ "giving", "t124.giving_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_recipient,
{ "recipient", "t124.recipient",
FT_UINT32, BASE_DEC, NULL, 0,
"UserId", HFILL }},
{ &hf_t124_ungivable,
{ "ungivable", "t124.ungivable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_given,
{ "given", "t124.given_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_mergeTokens,
{ "mergeTokens", "t124.mergeTokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_TokenAttributes", HFILL }},
{ &hf_t124_mergeTokens_item,
{ "TokenAttributes", "t124.TokenAttributes",
FT_UINT32, BASE_DEC, VALS(t124_TokenAttributes_vals), 0,
NULL, HFILL }},
{ &hf_t124_purgeTokenIds,
{ "purgeTokenIds", "t124.purgeTokenIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_TokenId", HFILL }},
{ &hf_t124_purgeTokenIds_item,
{ "TokenId", "t124.TokenId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_reason,
{ "reason", "t124.reason",
FT_UINT32, BASE_DEC, VALS(t124_Reason_vals), 0,
NULL, HFILL }},
{ &hf_t124_diagnostic,
{ "diagnostic", "t124.diagnostic",
FT_UINT32, BASE_DEC, VALS(t124_Diagnostic_vals), 0,
NULL, HFILL }},
{ &hf_t124_initialOctets,
{ "initialOctets", "t124.initialOctets",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t124_result_01,
{ "result", "t124.result",
FT_UINT32, BASE_DEC, VALS(t124_Result_vals), 0,
NULL, HFILL }},
{ &hf_t124_initiator,
{ "initiator", "t124.initiator",
FT_UINT32, BASE_DEC, NULL, 0,
"UserId", HFILL }},
{ &hf_t124_userIds,
{ "userIds", "t124.userIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_UserId", HFILL }},
{ &hf_t124_userIds_item,
{ "UserId", "t124.UserId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelId_03,
{ "channelId", "t124.channelId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_requested,
{ "requested", "t124.requested",
FT_UINT32, BASE_DEC, NULL, 0,
"ChannelId", HFILL }},
{ &hf_t124_channelIds,
{ "channelIds", "t124.channelIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ChannelId", HFILL }},
{ &hf_t124_channelIds_item,
{ "ChannelId", "t124.ChannelId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t124_dataPriority,
{ "dataPriority", "t124.dataPriority",
FT_UINT32, BASE_DEC, VALS(t124_DataPriority_vals), 0,
NULL, HFILL }},
{ &hf_t124_segmentation,
{ "segmentation", "t124.segmentation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_userData_01,
{ "userData", "t124.userData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_userData_02,
{ "userData", "t124.userData",
FT_BYTES, BASE_NONE, NULL, 0,
"T_userData_01", HFILL }},
{ &hf_t124_userData_03,
{ "userData", "t124.userData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t124_tokenStatus,
{ "tokenStatus", "t124.tokenStatus",
FT_UINT32, BASE_DEC, VALS(t124_TokenStatus_vals), 0,
NULL, HFILL }},
{ &hf_t124_plumbDomainIndication,
{ "plumbDomainIndication", "t124.plumbDomainIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_erectDomainRequest,
{ "erectDomainRequest", "t124.erectDomainRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_mergeChannelsRequest,
{ "mergeChannelsRequest", "t124.mergeChannelsRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_mergeChannelsConfirm,
{ "mergeChannelsConfirm", "t124.mergeChannelsConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_purgeChannelsIndication,
{ "purgeChannelsIndication", "t124.purgeChannelsIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_mergeTokensRequest,
{ "mergeTokensRequest", "t124.mergeTokensRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_mergeTokensConfirm,
{ "mergeTokensConfirm", "t124.mergeTokensConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_purgeTokensIndication,
{ "purgeTokensIndication", "t124.purgeTokensIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_disconnectProviderUltimatum,
{ "disconnectProviderUltimatum", "t124.disconnectProviderUltimatum_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_rejectMCSPDUUltimatum,
{ "rejectMCSPDUUltimatum", "t124.rejectMCSPDUUltimatum_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_attachUserRequest,
{ "attachUserRequest", "t124.attachUserRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_attachUserConfirm,
{ "attachUserConfirm", "t124.attachUserConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_detachUserRequest,
{ "detachUserRequest", "t124.detachUserRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_detachUserIndication,
{ "detachUserIndication", "t124.detachUserIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelJoinRequest,
{ "channelJoinRequest", "t124.channelJoinRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelJoinConfirm,
{ "channelJoinConfirm", "t124.channelJoinConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelLeaveRequest,
{ "channelLeaveRequest", "t124.channelLeaveRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelConveneRequest,
{ "channelConveneRequest", "t124.channelConveneRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelConveneConfirm,
{ "channelConveneConfirm", "t124.channelConveneConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelDisbandRequest,
{ "channelDisbandRequest", "t124.channelDisbandRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelDisbandIndication,
{ "channelDisbandIndication", "t124.channelDisbandIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelAdmitRequest,
{ "channelAdmitRequest", "t124.channelAdmitRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelAdmitIndication,
{ "channelAdmitIndication", "t124.channelAdmitIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelExpelRequest,
{ "channelExpelRequest", "t124.channelExpelRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_channelExpelIndication,
{ "channelExpelIndication", "t124.channelExpelIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_sendDataRequest,
{ "sendDataRequest", "t124.sendDataRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_sendDataIndication,
{ "sendDataIndication", "t124.sendDataIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_uniformSendDataRequest,
{ "uniformSendDataRequest", "t124.uniformSendDataRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_uniformSendDataIndication,
{ "uniformSendDataIndication", "t124.uniformSendDataIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGrabRequest,
{ "tokenGrabRequest", "t124.tokenGrabRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGrabConfirm,
{ "tokenGrabConfirm", "t124.tokenGrabConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenInhibitRequest,
{ "tokenInhibitRequest", "t124.tokenInhibitRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenInhibitConfirm,
{ "tokenInhibitConfirm", "t124.tokenInhibitConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGiveRequest,
{ "tokenGiveRequest", "t124.tokenGiveRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGiveIndication,
{ "tokenGiveIndication", "t124.tokenGiveIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGiveResponse,
{ "tokenGiveResponse", "t124.tokenGiveResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenGiveConfirm,
{ "tokenGiveConfirm", "t124.tokenGiveConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenPleaseRequest,
{ "tokenPleaseRequest", "t124.tokenPleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenPleaseIndication,
{ "tokenPleaseIndication", "t124.tokenPleaseIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenReleaseRequest,
{ "tokenReleaseRequest", "t124.tokenReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenReleaseConfirm,
{ "tokenReleaseConfirm", "t124.tokenReleaseConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenTestRequest,
{ "tokenTestRequest", "t124.tokenTestRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_tokenTestConfirm,
{ "tokenTestConfirm", "t124.tokenTestConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_Segmentation_begin,
{ "begin", "t124.begin",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_t124_Segmentation_end,
{ "end", "t124.end",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 191 "./asn1/t124/packet-t124-template.c"
};
static gint *ett[] = {
&ett_t124,
&ett_t124_connectGCCPDU,
#line 1 "./asn1/t124/packet-t124-ettarr.c"
&ett_t124_Key,
&ett_t124_NonStandardParameter,
&ett_t124_UserData,
&ett_t124_UserData_item,
&ett_t124_Password,
&ett_t124_PasswordSelector,
&ett_t124_ChallengeResponseItem,
&ett_t124_ChallengeResponseAlgorithm,
&ett_t124_ChallengeItem,
&ett_t124_ChallengeRequest,
&ett_t124_SET_OF_ChallengeItem,
&ett_t124_ChallengeResponse,
&ett_t124_PasswordChallengeRequestResponse,
&ett_t124_T_challengeRequestResponse,
&ett_t124_ConferenceName,
&ett_t124_ConferenceNameSelector,
&ett_t124_ConferencePriorityScheme,
&ett_t124_ConferencePriority,
&ett_t124_NodeCategory,
&ett_t124_ConferenceMode,
&ett_t124_NetworkAddress,
&ett_t124_NetworkAddress_item,
&ett_t124_T_aggregatedChannel,
&ett_t124_T_transferModes,
&ett_t124_T_highLayerCompatibility,
&ett_t124_T_transportConnection,
&ett_t124_AsymmetryIndicator,
&ett_t124_ConferenceDescriptor,
&ett_t124_ConferenceCreateRequest,
&ett_t124_SET_OF_Privilege,
&ett_t124_ConferenceCreateResponse,
&ett_t124_ConferenceQueryRequest,
&ett_t124_ConferenceQueryResponse,
&ett_t124_SET_OF_ConferenceDescriptor,
&ett_t124_ConferenceJoinRequest,
&ett_t124_ConferenceJoinResponse,
&ett_t124_ConferenceInviteRequest,
&ett_t124_ConferenceInviteResponse,
&ett_t124_ConnectData,
&ett_t124_ConnectGCCPDU,
&ett_t124_Segmentation,
&ett_t124_PlumbDomainIndication,
&ett_t124_ErectDomainRequest,
&ett_t124_ChannelAttributes,
&ett_t124_T_static,
&ett_t124_T_userId,
&ett_t124_T_private,
&ett_t124_SET_OF_UserId,
&ett_t124_T_assigned,
&ett_t124_MergeChannelsRequest,
&ett_t124_SET_OF_ChannelAttributes,
&ett_t124_SET_OF_ChannelId,
&ett_t124_MergeChannelsConfirm,
&ett_t124_PurgeChannelsIndication,
&ett_t124_TokenAttributes,
&ett_t124_T_grabbed,
&ett_t124_T_inhibited,
&ett_t124_T_giving,
&ett_t124_T_ungivable,
&ett_t124_T_given,
&ett_t124_MergeTokensRequest,
&ett_t124_SET_OF_TokenAttributes,
&ett_t124_SET_OF_TokenId,
&ett_t124_MergeTokensConfirm,
&ett_t124_PurgeTokensIndication,
&ett_t124_DisconnectProviderUltimatum,
&ett_t124_RejectMCSPDUUltimatum,
&ett_t124_AttachUserRequest,
&ett_t124_AttachUserConfirm,
&ett_t124_DetachUserRequest,
&ett_t124_DetachUserIndication,
&ett_t124_ChannelJoinRequest,
&ett_t124_ChannelJoinConfirm,
&ett_t124_ChannelLeaveRequest,
&ett_t124_ChannelConveneRequest,
&ett_t124_ChannelConveneConfirm,
&ett_t124_ChannelDisbandRequest,
&ett_t124_ChannelDisbandIndication,
&ett_t124_ChannelAdmitRequest,
&ett_t124_ChannelAdmitIndication,
&ett_t124_ChannelExpelRequest,
&ett_t124_ChannelExpelIndication,
&ett_t124_SendDataRequest,
&ett_t124_SendDataIndication,
&ett_t124_UniformSendDataRequest,
&ett_t124_UniformSendDataIndication,
&ett_t124_TokenGrabRequest,
&ett_t124_TokenGrabConfirm,
&ett_t124_TokenInhibitRequest,
&ett_t124_TokenInhibitConfirm,
&ett_t124_TokenGiveRequest,
&ett_t124_TokenGiveIndication,
&ett_t124_TokenGiveResponse,
&ett_t124_TokenGiveConfirm,
&ett_t124_TokenPleaseRequest,
&ett_t124_TokenPleaseIndication,
&ett_t124_TokenReleaseRequest,
&ett_t124_TokenReleaseConfirm,
&ett_t124_TokenTestRequest,
&ett_t124_TokenTestConfirm,
&ett_t124_DomainMCSPDU,
#line 198 "./asn1/t124/packet-t124-template.c"
};
proto_t124 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_t124, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
t124_ns_dissector_table = register_dissector_table("t124.ns", "T.124 H.221 Non Standard Dissectors", proto_t124, FT_STRING, BASE_NONE);
t124_sd_dissector_table = register_dissector_table("t124.sd", "T.124 H.221 Send Data Dissectors", proto_t124, FT_UINT32, BASE_HEX);
register_dissector("t124", dissect_t124, proto_t124);
}
void
proto_reg_handoff_t124(void) {
register_ber_oid_dissector("0.0.20.124.0.1", dissect_t124, proto_t124, "Generic Conference Control");
heur_dissector_add("t125", dissect_t124_heur, "T.124 over T.125", "t124_t125", proto_t124, HEURISTIC_ENABLE);
}
