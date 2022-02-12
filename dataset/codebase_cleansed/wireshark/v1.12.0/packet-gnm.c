static int
dissect_gnm_CharacteristicInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gnm_PayloadLevel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gnm_CharacteristicInformation(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gnm_MappingList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
MappingList_sequence_of, hf_index, ett_gnm_MappingList);
return offset;
}
static int
dissect_gnm_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gnm_SignalRate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SignalRate_choice, hf_index, ett_gnm_SignalRate,
NULL);
return offset;
}
static int
dissect_gnm_SupportedTOClasses(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SupportedTOClasses_set_of, hf_index, ett_gnm_SupportedTOClasses);
return offset;
}
static int
dissect_gnm_PrintableString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_AcceptableCircuitPackTypeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
AcceptableCircuitPackTypeList_set_of, hf_index, ett_gnm_AcceptableCircuitPackTypeList);
return offset;
}
static int
dissect_gnm_SEQUENCE_OF_ObjectInstance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ObjectInstance_sequence_of, hf_index, ett_gnm_SEQUENCE_OF_ObjectInstance);
return offset;
}
static int
dissect_gnm_ExplicitTP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ExplicitTP_choice, hf_index, ett_gnm_ExplicitTP,
NULL);
return offset;
}
static int
dissect_gnm_ToTermSpecifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ToTermSpecifier_choice, hf_index, ett_gnm_ToTermSpecifier,
NULL);
return offset;
}
static int
dissect_gnm_SET_OF_ToTermSpecifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ToTermSpecifier_set_of, hf_index, ett_gnm_SET_OF_ToTermSpecifier);
return offset;
}
static int
dissect_gnm_AddLeg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddLeg_sequence, hf_index, ett_gnm_AddLeg);
return offset;
}
static int
dissect_gnm_AlarmSeverityCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_AlarmSeverityAssignment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlarmSeverityAssignment_sequence, hf_index, ett_gnm_AlarmSeverityAssignment);
return offset;
}
static int
dissect_gnm_AlarmSeverityAssignmentList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
AlarmSeverityAssignmentList_set_of, hf_index, ett_gnm_AlarmSeverityAssignmentList);
return offset;
}
static int
dissect_gnm_AlarmStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_Boolean(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gnm_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_Bundle(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Bundle_sequence, hf_index, ett_gnm_Bundle);
return offset;
}
static int
dissect_gnm_ChannelNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_CircuitDirectionality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_CircuitPackType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_PointToPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PointToPoint_sequence, hf_index, ett_gnm_PointToPoint);
return offset;
}
static int
dissect_gnm_T_toTps_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_toTps_item_sequence, hf_index, ett_gnm_T_toTps_item);
return offset;
}
static int
dissect_gnm_T_toTps(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_toTps_set_of, hf_index, ett_gnm_T_toTps);
return offset;
}
static int
dissect_gnm_PointToMultipoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PointToMultipoint_sequence, hf_index, ett_gnm_PointToMultipoint);
return offset;
}
static int
dissect_gnm_Connected(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Connected_choice, hf_index, ett_gnm_Connected,
NULL);
return offset;
}
static int
dissect_gnm_ExplicitPtoP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExplicitPtoP_sequence, hf_index, ett_gnm_ExplicitPtoP);
return offset;
}
static int
dissect_gnm_PtoTPPool(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PtoTPPool_sequence, hf_index, ett_gnm_PtoTPPool);
return offset;
}
static int
dissect_gnm_SET_OF_ExplicitTP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ExplicitTP_set_of, hf_index, ett_gnm_SET_OF_ExplicitTP);
return offset;
}
static int
dissect_gnm_ExplicitPtoMP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExplicitPtoMP_sequence, hf_index, ett_gnm_ExplicitPtoMP);
return offset;
}
static int
dissect_gnm_ToTPPools_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ToTPPools_item_sequence, hf_index, ett_gnm_ToTPPools_item);
return offset;
}
static int
dissect_gnm_ToTPPools(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ToTPPools_set_of, hf_index, ett_gnm_ToTPPools);
return offset;
}
static int
dissect_gnm_PtoMPools(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PtoMPools_sequence, hf_index, ett_gnm_PtoMPools);
return offset;
}
static int
dissect_gnm_ConnectionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConnectionType_choice, hf_index, ett_gnm_ConnectionType,
NULL);
return offset;
}
static int
dissect_gnm_ConnectionTypeBi(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConnectionTypeBi_choice, hf_index, ett_gnm_ConnectionTypeBi,
NULL);
return offset;
}
static int
dissect_gnm_T_itemType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_itemType_choice, hf_index, ett_gnm_T_itemType,
NULL);
return offset;
}
static int
dissect_gnm_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gnm_CrossConnectionName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_NamedCrossConnection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NamedCrossConnection_sequence, hf_index, ett_gnm_NamedCrossConnection);
return offset;
}
static int
dissect_gnm_UserLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_ConnectInformation_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ConnectInformation_item_sequence, hf_index, ett_gnm_ConnectInformation_item);
return offset;
}
static int
dissect_gnm_ConnectInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ConnectInformation_sequence_of, hf_index, ett_gnm_ConnectInformation);
return offset;
}
static int
dissect_gnm_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gnm_ConnectivityPointer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConnectivityPointer_choice, hf_index, ett_gnm_ConnectivityPointer,
NULL);
return offset;
}
static int
dissect_gnm_Count(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_MultipleConnections_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MultipleConnections_item_choice, hf_index, ett_gnm_MultipleConnections_item,
NULL);
return offset;
}
static int
dissect_gnm_MultipleConnections(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
MultipleConnections_set_of, hf_index, ett_gnm_MultipleConnections);
return offset;
}
static int
dissect_gnm_CrossConnectionObjectPointer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CrossConnectionObjectPointer_choice, hf_index, ett_gnm_CrossConnectionObjectPointer,
NULL);
return offset;
}
static int
dissect_gnm_CurrentProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CurrentProblem_sequence, hf_index, ett_gnm_CurrentProblem);
return offset;
}
static int
dissect_gnm_CurrentProblemList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
CurrentProblemList_set_of, hf_index, ett_gnm_CurrentProblemList);
return offset;
}
static int
dissect_gnm_Directionality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_ProblemCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ProblemCause_choice, hf_index, ett_gnm_ProblemCause,
NULL);
return offset;
}
static int
dissect_gnm_SET_OF_ObjectInstance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ObjectInstance_set_of, hf_index, ett_gnm_SET_OF_ObjectInstance);
return offset;
}
static int
dissect_gnm_LogicalProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogicalProblem_sequence, hf_index, ett_gnm_LogicalProblem);
return offset;
}
static int
dissect_gnm_ResourceProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ResourceProblem_choice, hf_index, ett_gnm_ResourceProblem,
NULL);
return offset;
}
static int
dissect_gnm_Failed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Failed_choice, hf_index, ett_gnm_Failed,
NULL);
return offset;
}
static int
dissect_gnm_DisconnectResult_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DisconnectResult_item_choice, hf_index, ett_gnm_DisconnectResult_item,
NULL);
return offset;
}
static int
dissect_gnm_DisconnectResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DisconnectResult_sequence_of, hf_index, ett_gnm_DisconnectResult);
return offset;
}
static int
dissect_gnm_T_broadcastConcatenated(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_broadcastConcatenated_set_of, hf_index, ett_gnm_T_broadcastConcatenated);
return offset;
}
static int
dissect_gnm_DownstreamConnectivityPointer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DownstreamConnectivityPointer_choice, hf_index, ett_gnm_DownstreamConnectivityPointer,
NULL);
return offset;
}
static int
dissect_gnm_ExternalTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gnm_EquipmentHolderAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
EquipmentHolderAddress_sequence_of, hf_index, ett_gnm_EquipmentHolderAddress);
return offset;
}
static int
dissect_gnm_EquipmentHolderType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_HolderStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
HolderStatus_choice, hf_index, ett_gnm_HolderStatus,
NULL);
return offset;
}
static int
dissect_gnm_InformationTransferCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_ListOfCharacteristicInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ListOfCharacteristicInformation_set_of, hf_index, ett_gnm_ListOfCharacteristicInformation);
return offset;
}
static int
dissect_gnm_GraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_NameType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NameType_choice, hf_index, ett_gnm_NameType,
NULL);
return offset;
}
static int
dissect_gnm_NumberOfCircuits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_ObjectList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ObjectList_set_of, hf_index, ett_gnm_ObjectList);
return offset;
}
static int
dissect_gnm_WaveLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_SignalRateAndMappingList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SignalRateAndMappingList_item_sequence, hf_index, ett_gnm_SignalRateAndMappingList_item);
return offset;
}
static int
dissect_gnm_SignalRateAndMappingList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SignalRateAndMappingList_set_of, hf_index, ett_gnm_SignalRateAndMappingList);
return offset;
}
static int
dissect_gnm_T_diverse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_diverse_sequence, hf_index, ett_gnm_T_diverse);
return offset;
}
static int
dissect_gnm_PhysicalPortSignalRateAndMappingList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PhysicalPortSignalRateAndMappingList_choice, hf_index, ett_gnm_PhysicalPortSignalRateAndMappingList,
NULL);
return offset;
}
static int
dissect_gnm_Pointer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmip_ObjectInstance(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gnm_PointerOrNull(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PointerOrNull_choice, hf_index, ett_gnm_PointerOrNull,
NULL);
return offset;
}
static int
dissect_gnm_RelatedObjectInstance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RelatedObjectInstance_choice, hf_index, ett_gnm_RelatedObjectInstance,
NULL);
return offset;
}
static int
dissect_gnm_Replaceable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_SequenceOfObjectInstance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SequenceOfObjectInstance_sequence_of, hf_index, ett_gnm_SequenceOfObjectInstance);
return offset;
}
static int
dissect_gnm_SerialNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_SignallingCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_SEQUENCE_OF_Bundle(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Bundle_sequence_of, hf_index, ett_gnm_SEQUENCE_OF_Bundle);
return offset;
}
static int
dissect_gnm_SignalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SignalType_choice, hf_index, ett_gnm_SignalType,
NULL);
return offset;
}
static int
dissect_gnm_T_softwareIdentifiers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_softwareIdentifiers_sequence_of, hf_index, ett_gnm_T_softwareIdentifiers);
return offset;
}
static int
dissect_gnm_SubordinateCircuitPackSoftwareLoad(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SubordinateCircuitPackSoftwareLoad_choice, hf_index, ett_gnm_SubordinateCircuitPackSoftwareLoad,
NULL);
return offset;
}
static int
dissect_gnm_SupportableClientList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SupportableClientList_set_of, hf_index, ett_gnm_SupportableClientList);
return offset;
}
static int
dissect_gnm_T_sourceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_SystemTiming(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SystemTiming_sequence, hf_index, ett_gnm_SystemTiming);
return offset;
}
static int
dissect_gnm_SystemTimingSource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SystemTimingSource_sequence, hf_index, ett_gnm_SystemTimingSource);
return offset;
}
static int
dissect_gnm_TpsInGtpList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TpsInGtpList_sequence_of, hf_index, ett_gnm_TpsInGtpList);
return offset;
}
static int
dissect_gnm_TransmissionCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
TransmissionCharacteristics_bits, hf_index, ett_gnm_TransmissionCharacteristics,
NULL);
return offset;
}
static int
dissect_gnm_VendorName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gnm_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static void dissect_SupportedTOClasses_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SupportedTOClasses(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SupportedTOClasses_PDU);
}
static void dissect_AcceptableCircuitPackTypeList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_AcceptableCircuitPackTypeList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_AcceptableCircuitPackTypeList_PDU);
}
static void dissect_AlarmSeverityAssignmentList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_AlarmSeverityAssignmentList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_AlarmSeverityAssignmentList_PDU);
}
static void dissect_AlarmStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_AlarmStatus(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_AlarmStatus_PDU);
}
static void dissect_Boolean_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Boolean(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Boolean_PDU);
}
static void dissect_ChannelNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ChannelNumber(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ChannelNumber_PDU);
}
static void dissect_CharacteristicInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CharacteristicInformation(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CharacteristicInformation_PDU);
}
static void dissect_CircuitDirectionality_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CircuitDirectionality(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CircuitDirectionality_PDU);
}
static void dissect_CircuitPackType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CircuitPackType(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CircuitPackType_PDU);
}
static void dissect_ConnectInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ConnectInformation(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ConnectInformation_PDU);
}
static void dissect_ConnectivityPointer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ConnectivityPointer(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ConnectivityPointer_PDU);
}
static void dissect_Count_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Count(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Count_PDU);
}
static void dissect_CrossConnectionName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CrossConnectionName(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CrossConnectionName_PDU);
}
static void dissect_CrossConnectionObjectPointer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CrossConnectionObjectPointer(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CrossConnectionObjectPointer_PDU);
}
static void dissect_CurrentProblemList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_CurrentProblemList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_CurrentProblemList_PDU);
}
static void dissect_Directionality_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Directionality(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Directionality_PDU);
}
static void dissect_DisconnectResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_DisconnectResult(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_DisconnectResult_PDU);
}
static void dissect_DownstreamConnectivityPointer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_DownstreamConnectivityPointer(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_DownstreamConnectivityPointer_PDU);
}
static void dissect_ExternalTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ExternalTime(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ExternalTime_PDU);
}
static void dissect_EquipmentHolderAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_EquipmentHolderAddress(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_EquipmentHolderAddress_PDU);
}
static void dissect_EquipmentHolderType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_EquipmentHolderType(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_EquipmentHolderType_PDU);
}
static void dissect_HolderStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_HolderStatus(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_HolderStatus_PDU);
}
static void dissect_InformationTransferCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_InformationTransferCapabilities(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_InformationTransferCapabilities_PDU);
}
static void dissect_ListOfCharacteristicInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ListOfCharacteristicInformation(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ListOfCharacteristicInformation_PDU);
}
static void dissect_NameType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_NameType(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_NameType_PDU);
}
static void dissect_NumberOfCircuits_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_NumberOfCircuits(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_NumberOfCircuits_PDU);
}
static void dissect_ObjectList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_ObjectList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_ObjectList_PDU);
}
static void dissect_Pointer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Pointer(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Pointer_PDU);
}
static void dissect_PointerOrNull_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_PointerOrNull(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_PointerOrNull_PDU);
}
static void dissect_RelatedObjectInstance_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_RelatedObjectInstance(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_RelatedObjectInstance_PDU);
}
static void dissect_Replaceable_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Replaceable(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Replaceable_PDU);
}
static void dissect_SequenceOfObjectInstance_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SequenceOfObjectInstance(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SequenceOfObjectInstance_PDU);
}
static void dissect_SerialNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SerialNumber(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SerialNumber_PDU);
}
static void dissect_SignallingCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SignallingCapabilities(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SignallingCapabilities_PDU);
}
static void dissect_SignalType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SignalType(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SignalType_PDU);
}
static void dissect_SubordinateCircuitPackSoftwareLoad_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SubordinateCircuitPackSoftwareLoad(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SubordinateCircuitPackSoftwareLoad_PDU);
}
static void dissect_SupportableClientList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SupportableClientList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SupportableClientList_PDU);
}
static void dissect_SystemTimingSource_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_SystemTimingSource(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_SystemTimingSource_PDU);
}
static void dissect_TpsInGtpList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_TpsInGtpList(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_TpsInGtpList_PDU);
}
static void dissect_TransmissionCharacteristics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_TransmissionCharacteristics(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_TransmissionCharacteristics_PDU);
}
static void dissect_UserLabel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_UserLabel(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_UserLabel_PDU);
}
static void dissect_VendorName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_VendorName(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_VendorName_PDU);
}
static void dissect_Version_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_gnm_Version(FALSE, tvb, 0, &asn1_ctx, tree, hf_gnm_Version_PDU);
}
static void
dissect_gnm_attribute_ObjectInstance(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cmip_ObjectInstance(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void
dissect_gnm(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_)
{
}
void proto_register_gnm(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/gnm/packet-gnm-hfarr.c"
{ &hf_gnm_SupportedTOClasses_PDU,
{ "SupportedTOClasses", "gnm.SupportedTOClasses",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_AcceptableCircuitPackTypeList_PDU,
{ "AcceptableCircuitPackTypeList", "gnm.AcceptableCircuitPackTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_AlarmSeverityAssignmentList_PDU,
{ "AlarmSeverityAssignmentList", "gnm.AlarmSeverityAssignmentList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_AlarmStatus_PDU,
{ "AlarmStatus", "gnm.AlarmStatus",
FT_UINT32, BASE_DEC, VALS(gnm_AlarmStatus_vals), 0,
NULL, HFILL }},
{ &hf_gnm_Boolean_PDU,
{ "Boolean", "gnm.Boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ChannelNumber_PDU,
{ "ChannelNumber", "gnm.ChannelNumber",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_CharacteristicInformation_PDU,
{ "CharacteristicInformation", "gnm.CharacteristicInformation",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_CircuitDirectionality_PDU,
{ "CircuitDirectionality", "gnm.CircuitDirectionality",
FT_UINT32, BASE_DEC, VALS(gnm_CircuitDirectionality_vals), 0,
NULL, HFILL }},
{ &hf_gnm_CircuitPackType_PDU,
{ "CircuitPackType", "gnm.CircuitPackType",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ConnectInformation_PDU,
{ "ConnectInformation", "gnm.ConnectInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ConnectivityPointer_PDU,
{ "ConnectivityPointer", "gnm.ConnectivityPointer",
FT_UINT32, BASE_DEC, VALS(gnm_ConnectivityPointer_vals), 0,
NULL, HFILL }},
{ &hf_gnm_Count_PDU,
{ "Count", "gnm.Count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_CrossConnectionName_PDU,
{ "CrossConnectionName", "gnm.CrossConnectionName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_CrossConnectionObjectPointer_PDU,
{ "CrossConnectionObjectPointer", "gnm.CrossConnectionObjectPointer",
FT_UINT32, BASE_DEC, VALS(gnm_CrossConnectionObjectPointer_vals), 0,
NULL, HFILL }},
{ &hf_gnm_CurrentProblemList_PDU,
{ "CurrentProblemList", "gnm.CurrentProblemList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_Directionality_PDU,
{ "Directionality", "gnm.Directionality",
FT_UINT32, BASE_DEC, VALS(gnm_Directionality_vals), 0,
NULL, HFILL }},
{ &hf_gnm_DisconnectResult_PDU,
{ "DisconnectResult", "gnm.DisconnectResult",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_DownstreamConnectivityPointer_PDU,
{ "DownstreamConnectivityPointer", "gnm.DownstreamConnectivityPointer",
FT_UINT32, BASE_DEC, VALS(gnm_DownstreamConnectivityPointer_vals), 0,
NULL, HFILL }},
{ &hf_gnm_ExternalTime_PDU,
{ "ExternalTime", "gnm.ExternalTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_EquipmentHolderAddress_PDU,
{ "EquipmentHolderAddress", "gnm.EquipmentHolderAddress",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_EquipmentHolderType_PDU,
{ "EquipmentHolderType", "gnm.EquipmentHolderType",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_HolderStatus_PDU,
{ "HolderStatus", "gnm.HolderStatus",
FT_UINT32, BASE_DEC, VALS(gnm_HolderStatus_vals), 0,
NULL, HFILL }},
{ &hf_gnm_InformationTransferCapabilities_PDU,
{ "InformationTransferCapabilities", "gnm.InformationTransferCapabilities",
FT_UINT32, BASE_DEC, VALS(gnm_InformationTransferCapabilities_vals), 0,
NULL, HFILL }},
{ &hf_gnm_ListOfCharacteristicInformation_PDU,
{ "ListOfCharacteristicInformation", "gnm.ListOfCharacteristicInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_NameType_PDU,
{ "NameType", "gnm.NameType",
FT_UINT32, BASE_DEC, VALS(gnm_NameType_vals), 0,
NULL, HFILL }},
{ &hf_gnm_NumberOfCircuits_PDU,
{ "NumberOfCircuits", "gnm.NumberOfCircuits",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ObjectList_PDU,
{ "ObjectList", "gnm.ObjectList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_Pointer_PDU,
{ "Pointer", "gnm.Pointer",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_PointerOrNull_PDU,
{ "PointerOrNull", "gnm.PointerOrNull",
FT_UINT32, BASE_DEC, VALS(gnm_PointerOrNull_vals), 0,
NULL, HFILL }},
{ &hf_gnm_RelatedObjectInstance_PDU,
{ "RelatedObjectInstance", "gnm.RelatedObjectInstance",
FT_UINT32, BASE_DEC, VALS(gnm_RelatedObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_Replaceable_PDU,
{ "Replaceable", "gnm.Replaceable",
FT_UINT32, BASE_DEC, VALS(gnm_Replaceable_vals), 0,
NULL, HFILL }},
{ &hf_gnm_SequenceOfObjectInstance_PDU,
{ "SequenceOfObjectInstance", "gnm.SequenceOfObjectInstance",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_SerialNumber_PDU,
{ "SerialNumber", "gnm.SerialNumber",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_SignallingCapabilities_PDU,
{ "SignallingCapabilities", "gnm.SignallingCapabilities",
FT_UINT32, BASE_DEC, VALS(gnm_SignallingCapabilities_vals), 0,
NULL, HFILL }},
{ &hf_gnm_SignalType_PDU,
{ "SignalType", "gnm.SignalType",
FT_UINT32, BASE_DEC, VALS(gnm_SignalType_vals), 0,
NULL, HFILL }},
{ &hf_gnm_SubordinateCircuitPackSoftwareLoad_PDU,
{ "SubordinateCircuitPackSoftwareLoad", "gnm.SubordinateCircuitPackSoftwareLoad",
FT_UINT32, BASE_DEC, VALS(gnm_SubordinateCircuitPackSoftwareLoad_vals), 0,
NULL, HFILL }},
{ &hf_gnm_SupportableClientList_PDU,
{ "SupportableClientList", "gnm.SupportableClientList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_SystemTimingSource_PDU,
{ "SystemTimingSource", "gnm.SystemTimingSource_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_TpsInGtpList_PDU,
{ "TpsInGtpList", "gnm.TpsInGtpList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_TransmissionCharacteristics_PDU,
{ "TransmissionCharacteristics", "gnm.TransmissionCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_UserLabel_PDU,
{ "UserLabel", "gnm.UserLabel",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_VendorName_PDU,
{ "VendorName", "gnm.VendorName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_Version_PDU,
{ "Version", "gnm.Version",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_MappingList_item,
{ "PayloadLevel", "gnm.PayloadLevel",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_objectClass,
{ "objectClass", "gnm.objectClass",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_gnm_characteristicInformation,
{ "characteristicInformation", "gnm.characteristicInformation",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_SupportedTOClasses_item,
{ "SupportedTOClasses item", "gnm.SupportedTOClasses_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_gnm_AcceptableCircuitPackTypeList_item,
{ "AcceptableCircuitPackTypeList item", "gnm.AcceptableCircuitPackTypeList_item",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_gnm_mpCrossConnection,
{ "mpCrossConnection", "gnm.mpCrossConnection",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_legs,
{ "legs", "gnm.legs",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ToTermSpecifier", HFILL }},
{ &hf_gnm_legs_item,
{ "ToTermSpecifier", "gnm.ToTermSpecifier",
FT_UINT32, BASE_DEC, VALS(gnm_ToTermSpecifier_vals), 0,
NULL, HFILL }},
{ &hf_gnm_problem,
{ "problem", "gnm.problem",
FT_UINT32, BASE_DEC, VALS(cmip_ProbableCause_vals), 0,
"ProbableCause", HFILL }},
{ &hf_gnm_severityAssignedServiceAffecting,
{ "severityAssignedServiceAffecting", "gnm.severityAssignedServiceAffecting",
FT_UINT32, BASE_DEC, VALS(gnm_AlarmSeverityCode_vals), 0,
"AlarmSeverityCode", HFILL }},
{ &hf_gnm_severityAssignedNonServiceAffecting,
{ "severityAssignedNonServiceAffecting", "gnm.severityAssignedNonServiceAffecting",
FT_UINT32, BASE_DEC, VALS(gnm_AlarmSeverityCode_vals), 0,
"AlarmSeverityCode", HFILL }},
{ &hf_gnm_severityAssignedServiceIndependent,
{ "severityAssignedServiceIndependent", "gnm.severityAssignedServiceIndependent",
FT_UINT32, BASE_DEC, VALS(gnm_AlarmSeverityCode_vals), 0,
"AlarmSeverityCode", HFILL }},
{ &hf_gnm_AlarmSeverityAssignmentList_item,
{ "AlarmSeverityAssignment", "gnm.AlarmSeverityAssignment_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_characteristicInfoType,
{ "characteristicInfoType", "gnm.characteristicInfoType",
FT_OID, BASE_NONE, NULL, 0,
"CharacteristicInformation", HFILL }},
{ &hf_gnm_bundlingFactor,
{ "bundlingFactor", "gnm.bundlingFactor",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gnm_pointToPoint,
{ "pointToPoint", "gnm.pointToPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_pointToMultipoint,
{ "pointToMultipoint", "gnm.pointToMultipoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ConnectInformation_item,
{ "ConnectInformation item", "gnm.ConnectInformation_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_itemType,
{ "itemType", "gnm.itemType",
FT_UINT32, BASE_DEC, VALS(gnm_T_itemType_vals), 0,
NULL, HFILL }},
{ &hf_gnm_unidirectional,
{ "unidirectional", "gnm.unidirectional",
FT_UINT32, BASE_DEC, VALS(gnm_ConnectionType_vals), 0,
"ConnectionType", HFILL }},
{ &hf_gnm_bidirectional,
{ "bidirectional", "gnm.bidirectional",
FT_UINT32, BASE_DEC, VALS(gnm_ConnectionTypeBi_vals), 0,
"ConnectionTypeBi", HFILL }},
{ &hf_gnm_addleg,
{ "addleg", "gnm.addleg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_administrativeState,
{ "administrativeState", "gnm.administrativeState",
FT_UINT32, BASE_DEC, VALS(cmip_AdministrativeState_vals), 0,
NULL, HFILL }},
{ &hf_gnm_namedCrossConnection,
{ "namedCrossConnection", "gnm.namedCrossConnection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_userLabel,
{ "userLabel", "gnm.userLabel",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_redline,
{ "redline", "gnm.redline",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"Boolean", HFILL }},
{ &hf_gnm_additionalInfo,
{ "additionalInfo", "gnm.additionalInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"AdditionalInformation", HFILL }},
{ &hf_gnm_none,
{ "none", "gnm.none_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_single,
{ "single", "gnm.single",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_concatenated,
{ "concatenated", "gnm.concatenated",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectInstance", HFILL }},
{ &hf_gnm_concatenated_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_explicitPToP,
{ "explicitPToP", "gnm.explicitPToP_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ptoTpPool,
{ "ptoTpPool", "gnm.ptoTpPool_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_explicitPtoMP,
{ "explicitPtoMP", "gnm.explicitPtoMP_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ptoMPools,
{ "ptoMPools", "gnm.ptoMPools_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_notConnected,
{ "notConnected", "gnm.notConnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_connected,
{ "connected", "gnm.connected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_multipleConnections,
{ "multipleConnections", "gnm.multipleConnections",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_alarmStatus,
{ "alarmStatus", "gnm.alarmStatus",
FT_UINT32, BASE_DEC, VALS(gnm_AlarmStatus_vals), 0,
NULL, HFILL }},
{ &hf_gnm_CurrentProblemList_item,
{ "CurrentProblem", "gnm.CurrentProblem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_DisconnectResult_item,
{ "DisconnectResult item", "gnm.DisconnectResult_item",
FT_UINT32, BASE_DEC, VALS(gnm_DisconnectResult_item_vals), 0,
NULL, HFILL }},
{ &hf_gnm_failed,
{ "failed", "gnm.failed",
FT_UINT32, BASE_DEC, VALS(gnm_Failed_vals), 0,
NULL, HFILL }},
{ &hf_gnm_disconnected,
{ "disconnected", "gnm.disconnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_broadcast,
{ "broadcast", "gnm.broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ObjectInstance", HFILL }},
{ &hf_gnm_broadcast_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_broadcastConcatenated,
{ "broadcastConcatenated", "gnm.broadcastConcatenated",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_broadcastConcatenated_item,
{ "broadcastConcatenated item", "gnm.broadcastConcatenated_item",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectInstance", HFILL }},
{ &hf_gnm__item_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_fromTp,
{ "fromTp", "gnm.fromTp",
FT_UINT32, BASE_DEC, VALS(gnm_ExplicitTP_vals), 0,
"ExplicitTP", HFILL }},
{ &hf_gnm_toTPs,
{ "toTPs", "gnm.toTPs",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ExplicitTP", HFILL }},
{ &hf_gnm_toTPs_item,
{ "ExplicitTP", "gnm.ExplicitTP",
FT_UINT32, BASE_DEC, VALS(gnm_ExplicitTP_vals), 0,
NULL, HFILL }},
{ &hf_gnm_toTp,
{ "toTp", "gnm.toTp",
FT_UINT32, BASE_DEC, VALS(gnm_ExplicitTP_vals), 0,
"ExplicitTP", HFILL }},
{ &hf_gnm_oneTPorGTP,
{ "oneTPorGTP", "gnm.oneTPorGTP",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_listofTPs,
{ "listofTPs", "gnm.listofTPs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectInstance", HFILL }},
{ &hf_gnm_listofTPs_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_EquipmentHolderAddress_item,
{ "EquipmentHolderAddress item", "gnm.EquipmentHolderAddress_item",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_gnm_logicalProblem,
{ "logicalProblem", "gnm.logicalProblem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_resourceProblem,
{ "resourceProblem", "gnm.resourceProblem",
FT_UINT32, BASE_DEC, VALS(gnm_ResourceProblem_vals), 0,
NULL, HFILL }},
{ &hf_gnm_holderEmpty,
{ "holderEmpty", "gnm.holderEmpty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_inTheAcceptableList,
{ "inTheAcceptableList", "gnm.inTheAcceptableList",
FT_STRING, BASE_NONE, NULL, 0,
"CircuitPackType", HFILL }},
{ &hf_gnm_notInTheAcceptableList,
{ "notInTheAcceptableList", "gnm.notInTheAcceptableList",
FT_STRING, BASE_NONE, NULL, 0,
"CircuitPackType", HFILL }},
{ &hf_gnm_unknownType,
{ "unknownType", "gnm.unknownType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_ListOfCharacteristicInformation_item,
{ "CharacteristicInformation", "gnm.CharacteristicInformation",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_problemCause,
{ "problemCause", "gnm.problemCause",
FT_UINT32, BASE_DEC, VALS(gnm_ProblemCause_vals), 0,
NULL, HFILL }},
{ &hf_gnm_incorrectInstances,
{ "incorrectInstances", "gnm.incorrectInstances",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ObjectInstance", HFILL }},
{ &hf_gnm_incorrectInstances_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_MultipleConnections_item,
{ "MultipleConnections item", "gnm.MultipleConnections_item",
FT_UINT32, BASE_DEC, VALS(gnm_MultipleConnections_item_vals), 0,
NULL, HFILL }},
{ &hf_gnm_downstreamNotConnected,
{ "downstreamNotConnected", "gnm.downstreamNotConnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_downstreamConnected,
{ "downstreamConnected", "gnm.downstreamConnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_upstreamNotConnected,
{ "upstreamNotConnected", "gnm.upstreamNotConnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_upstreamConnected,
{ "upstreamConnected", "gnm.upstreamConnected",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_redline_01,
{ "redline", "gnm.redline",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gnm_name,
{ "name", "gnm.name",
FT_STRING, BASE_NONE, NULL, 0,
"CrossConnectionName", HFILL }},
{ &hf_gnm_numericName,
{ "numericName", "gnm.numericName",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gnm_pString,
{ "pString", "gnm.pString",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_gnm_ObjectList_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_diverse,
{ "diverse", "gnm.diverse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_downstream,
{ "downstream", "gnm.downstream",
FT_UINT32, BASE_DEC, NULL, 0,
"SignalRateAndMappingList", HFILL }},
{ &hf_gnm_upStream,
{ "upStream", "gnm.upStream",
FT_UINT32, BASE_DEC, NULL, 0,
"SignalRateAndMappingList", HFILL }},
{ &hf_gnm_uniform,
{ "uniform", "gnm.uniform",
FT_UINT32, BASE_DEC, NULL, 0,
"SignalRateAndMappingList", HFILL }},
{ &hf_gnm_pointer,
{ "pointer", "gnm.pointer",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_null,
{ "null", "gnm.null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_fromTp_01,
{ "fromTp", "gnm.fromTp",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_toTp_01,
{ "toTp", "gnm.toTp",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_xCon,
{ "xCon", "gnm.xCon",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_toTps,
{ "toTps", "gnm.toTps",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_toTps_item,
{ "toTps item", "gnm.toTps_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_tp,
{ "tp", "gnm.tp",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_xConnection,
{ "xConnection", "gnm.xConnection",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_mpXCon,
{ "mpXCon", "gnm.mpXCon",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_unknown,
{ "unknown", "gnm.unknown_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_integerValue,
{ "integerValue", "gnm.integerValue",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gnm_toTPPools,
{ "toTPPools", "gnm.toTPPools",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_toTpPool,
{ "toTpPool", "gnm.toTpPool",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_notAvailable,
{ "notAvailable", "gnm.notAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_relatedObject,
{ "relatedObject", "gnm.relatedObject",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_SequenceOfObjectInstance_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_SignalRateAndMappingList_item,
{ "SignalRateAndMappingList item", "gnm.SignalRateAndMappingList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_signalRate,
{ "signalRate", "gnm.signalRate",
FT_UINT32, BASE_DEC, VALS(gnm_SignalRate_vals), 0,
NULL, HFILL }},
{ &hf_gnm_mappingList,
{ "mappingList", "gnm.mappingList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_wavelength,
{ "wavelength", "gnm.wavelength",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_simple,
{ "simple", "gnm.simple",
FT_OID, BASE_NONE, NULL, 0,
"CharacteristicInformation", HFILL }},
{ &hf_gnm_bundle,
{ "bundle", "gnm.bundle_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_complex,
{ "complex", "gnm.complex",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Bundle", HFILL }},
{ &hf_gnm_complex_item,
{ "Bundle", "gnm.Bundle_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_notApplicable,
{ "notApplicable", "gnm.notApplicable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_softwareInstances,
{ "softwareInstances", "gnm.softwareInstances",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectInstance", HFILL }},
{ &hf_gnm_softwareInstances_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_softwareIdentifiers,
{ "softwareIdentifiers", "gnm.softwareIdentifiers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_softwareIdentifiers_item,
{ "softwareIdentifiers item", "gnm.softwareIdentifiers_item",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_gnm_SupportableClientList_item,
{ "ObjectClass", "gnm.ObjectClass",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectClass_vals), 0,
NULL, HFILL }},
{ &hf_gnm_sourceType,
{ "sourceType", "gnm.sourceType",
FT_UINT32, BASE_DEC, VALS(gnm_T_sourceType_vals), 0,
NULL, HFILL }},
{ &hf_gnm_sourceID,
{ "sourceID", "gnm.sourceID",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_primaryTimingSource,
{ "primaryTimingSource", "gnm.primaryTimingSource_element",
FT_NONE, BASE_NONE, NULL, 0,
"SystemTiming", HFILL }},
{ &hf_gnm_secondaryTimingSource,
{ "secondaryTimingSource", "gnm.secondaryTimingSource_element",
FT_NONE, BASE_NONE, NULL, 0,
"SystemTiming", HFILL }},
{ &hf_gnm_toTpOrGTP,
{ "toTpOrGTP", "gnm.toTpOrGTP",
FT_UINT32, BASE_DEC, VALS(gnm_ExplicitTP_vals), 0,
"ExplicitTP", HFILL }},
{ &hf_gnm_toPool,
{ "toPool", "gnm.toPool",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_ToTPPools_item,
{ "ToTPPools item", "gnm.ToTPPools_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gnm_tpPoolId,
{ "tpPoolId", "gnm.tpPoolId",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
"ObjectInstance", HFILL }},
{ &hf_gnm_numberOfTPs,
{ "numberOfTPs", "gnm.numberOfTPs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gnm_TpsInGtpList_item,
{ "ObjectInstance", "gnm.ObjectInstance",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectInstance_vals), 0,
NULL, HFILL }},
{ &hf_gnm_TransmissionCharacteristics_satellite,
{ "satellite", "gnm.satellite",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gnm_TransmissionCharacteristics_dCME,
{ "dCME", "gnm.dCME",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gnm_TransmissionCharacteristics_echoControl,
{ "echoControl", "gnm.echoControl",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 83 "../../asn1/gnm/packet-gnm-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/gnm/packet-gnm-ettarr.c"
&ett_gnm_MappingList,
&ett_gnm_SignalRate,
&ett_gnm_SupportedTOClasses,
&ett_gnm_AcceptableCircuitPackTypeList,
&ett_gnm_AddLeg,
&ett_gnm_SET_OF_ToTermSpecifier,
&ett_gnm_AlarmSeverityAssignment,
&ett_gnm_AlarmSeverityAssignmentList,
&ett_gnm_Bundle,
&ett_gnm_Connected,
&ett_gnm_ConnectInformation,
&ett_gnm_ConnectInformation_item,
&ett_gnm_T_itemType,
&ett_gnm_ConnectivityPointer,
&ett_gnm_SEQUENCE_OF_ObjectInstance,
&ett_gnm_ConnectionType,
&ett_gnm_ConnectionTypeBi,
&ett_gnm_CrossConnectionObjectPointer,
&ett_gnm_CurrentProblem,
&ett_gnm_CurrentProblemList,
&ett_gnm_DisconnectResult,
&ett_gnm_DisconnectResult_item,
&ett_gnm_DownstreamConnectivityPointer,
&ett_gnm_SET_OF_ObjectInstance,
&ett_gnm_T_broadcastConcatenated,
&ett_gnm_ExplicitPtoMP,
&ett_gnm_SET_OF_ExplicitTP,
&ett_gnm_ExplicitPtoP,
&ett_gnm_ExplicitTP,
&ett_gnm_EquipmentHolderAddress,
&ett_gnm_Failed,
&ett_gnm_HolderStatus,
&ett_gnm_ListOfCharacteristicInformation,
&ett_gnm_LogicalProblem,
&ett_gnm_MultipleConnections,
&ett_gnm_MultipleConnections_item,
&ett_gnm_NamedCrossConnection,
&ett_gnm_NameType,
&ett_gnm_ObjectList,
&ett_gnm_PhysicalPortSignalRateAndMappingList,
&ett_gnm_T_diverse,
&ett_gnm_PointerOrNull,
&ett_gnm_PointToPoint,
&ett_gnm_PointToMultipoint,
&ett_gnm_T_toTps,
&ett_gnm_T_toTps_item,
&ett_gnm_ProblemCause,
&ett_gnm_PtoMPools,
&ett_gnm_PtoTPPool,
&ett_gnm_RelatedObjectInstance,
&ett_gnm_ResourceProblem,
&ett_gnm_SequenceOfObjectInstance,
&ett_gnm_SignalRateAndMappingList,
&ett_gnm_SignalRateAndMappingList_item,
&ett_gnm_SignalType,
&ett_gnm_SEQUENCE_OF_Bundle,
&ett_gnm_SubordinateCircuitPackSoftwareLoad,
&ett_gnm_T_softwareIdentifiers,
&ett_gnm_SupportableClientList,
&ett_gnm_SystemTiming,
&ett_gnm_SystemTimingSource,
&ett_gnm_ToTermSpecifier,
&ett_gnm_ToTPPools,
&ett_gnm_ToTPPools_item,
&ett_gnm_TpsInGtpList,
&ett_gnm_TransmissionCharacteristics,
#line 88 "../../asn1/gnm/packet-gnm-template.c"
};
proto_gnm = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("gnm", dissect_gnm, proto_gnm);
proto_register_field_array(proto_gnm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_gnm(void) {
#line 1 "../../asn1/gnm/packet-gnm-dis-tab.c"
register_ber_oid_dissector("0.0.13.3100.0.7.1", dissect_RelatedObjectInstance_PDU, proto_gnm, "a-TPInstance(1)");
register_ber_oid_dissector("0.0.13.3100.0.7.2", dissect_ObjectList_PDU, proto_gnm, "affectedObjectList(2)");
register_ber_oid_dissector("0.0.13.3100.0.7.3", dissect_AlarmSeverityAssignmentList_PDU, proto_gnm, "alarmSeverityAssignmentList(3)");
register_ber_oid_dissector("0.0.13.3100.0.7.4", dissect_NameType_PDU, proto_gnm, "alarmSeverityAssignmentProfileId(4)");
register_ber_oid_dissector("0.0.13.3100.0.7.5", dissect_PointerOrNull_PDU, proto_gnm, "alarmSeverityAssignmentProfilePointer(5)");
register_ber_oid_dissector("0.0.13.3100.0.7.6", dissect_AlarmStatus_PDU, proto_gnm, "alarmStatus(6)");
register_ber_oid_dissector("0.0.13.3100.0.7.7", dissect_ChannelNumber_PDU, proto_gnm, "channelNumber(7)");
register_ber_oid_dissector("0.0.13.3100.0.7.8", dissect_CharacteristicInformation_PDU, proto_gnm, "characteristicInformation(8)");
register_ber_oid_dissector("0.0.13.3100.0.7.11", dissect_Count_PDU, proto_gnm, "connectedTpCount(11)");
register_ber_oid_dissector("0.0.13.3100.0.7.12", dissect_NameType_PDU, proto_gnm, "connectionId(12)");
register_ber_oid_dissector("0.0.13.3100.0.7.13", dissect_NameType_PDU, proto_gnm, "cTPId(13)");
register_ber_oid_dissector("0.0.13.3100.0.7.14", dissect_NameType_PDU, proto_gnm, "crossConnectionId(14)");
register_ber_oid_dissector("0.0.13.3100.0.7.15", dissect_CrossConnectionName_PDU, proto_gnm, "crossConnectionName(15)");
register_ber_oid_dissector("0.0.13.3100.0.7.16", dissect_CrossConnectionObjectPointer_PDU, proto_gnm, "crossConnectionObjectPointer(16)");
register_ber_oid_dissector("0.0.13.3100.0.7.17", dissect_CurrentProblemList_PDU, proto_gnm, "currentProblemList(17)");
register_ber_oid_dissector("0.0.13.3100.0.7.18", dissect_Directionality_PDU, proto_gnm, "directionality(18)");
register_ber_oid_dissector("0.0.13.3100.0.7.19", dissect_DownstreamConnectivityPointer_PDU, proto_gnm, "downstreamConnectivityPointer(19)");
register_ber_oid_dissector("0.0.13.3100.0.7.20", dissect_NameType_PDU, proto_gnm, "equipmentId(20)");
register_ber_oid_dissector("0.0.13.3100.0.7.21", dissect_ExternalTime_PDU, proto_gnm, "externalTime(21)");
register_ber_oid_dissector("0.0.13.3100.0.7.22", dissect_NameType_PDU, proto_gnm, "fabricId(22)");
register_ber_oid_dissector("0.0.13.3100.0.7.23", dissect_PointerOrNull_PDU, proto_gnm, "fromTermination(23)");
register_ber_oid_dissector("0.0.13.3100.0.7.24", dissect_NameType_PDU, proto_gnm, "gtpId(24)");
register_ber_oid_dissector("0.0.13.3100.0.7.25", dissect_Count_PDU, proto_gnm, "idleTpCount(25)");
register_ber_oid_dissector("0.0.13.3100.0.7.26", dissect_ListOfCharacteristicInformation_PDU, proto_gnm, "listOfCharacteristicInfo(26)");
register_ber_oid_dissector("0.0.13.3100.0.7.27", dissect_Replaceable_PDU, proto_gnm, "locationName(27)");
register_ber_oid_dissector("0.0.13.3100.0.7.28", dissect_NameType_PDU, proto_gnm, "managedElementId(28)");
register_ber_oid_dissector("0.0.13.3100.0.7.29", dissect_NameType_PDU, proto_gnm, "mpCrossConnectionId(29)");
register_ber_oid_dissector("0.0.13.3100.0.7.30", dissect_NameType_PDU, proto_gnm, "networkId(30)");
register_ber_oid_dissector("0.0.13.3100.0.7.32", dissect_Boolean_PDU, proto_gnm, "protected(32)");
register_ber_oid_dissector("0.0.13.3100.0.7.33", dissect_Boolean_PDU, proto_gnm, "redline(33)");
register_ber_oid_dissector("0.0.13.3100.0.7.34", dissect_Replaceable_PDU, proto_gnm, "replaceable(34)");
register_ber_oid_dissector("0.0.13.3100.0.7.35", dissect_SequenceOfObjectInstance_PDU, proto_gnm, "serverConnectionList(35)");
register_ber_oid_dissector("0.0.13.3100.0.7.36", dissect_ObjectList_PDU, proto_gnm, "serverTrailList(36)");
register_ber_oid_dissector("0.0.13.3100.0.7.37", dissect_SignalType_PDU, proto_gnm, "signalType(37)");
register_ber_oid_dissector("0.0.13.3100.0.7.38", dissect_NameType_PDU, proto_gnm, "softwareId(38)");
register_ber_oid_dissector("0.0.13.3100.0.7.39", dissect_SupportableClientList_PDU, proto_gnm, "supportableClientList(39)");
register_ber_oid_dissector("0.0.13.3100.0.7.40", dissect_ObjectList_PDU, proto_gnm, "supportedByObjectList(40)");
register_ber_oid_dissector("0.0.13.3100.0.7.41", dissect_SystemTimingSource_PDU, proto_gnm, "systemTimingSource(41)");
register_ber_oid_dissector("0.0.13.3100.0.7.42", dissect_Count_PDU, proto_gnm, "totalTpCount(42)");
register_ber_oid_dissector("0.0.13.3100.0.7.43", dissect_Pointer_PDU, proto_gnm, "toTermination(43)");
register_ber_oid_dissector("0.0.13.3100.0.7.44", dissect_NameType_PDU, proto_gnm, "tpPoolId(44)");
register_ber_oid_dissector("0.0.13.3100.0.7.45", dissect_TpsInGtpList_PDU, proto_gnm, "tpsInGtpList(45)");
register_ber_oid_dissector("0.0.13.3100.0.7.47", dissect_NameType_PDU, proto_gnm, "trailId(47)");
register_ber_oid_dissector("0.0.13.3100.0.7.48", dissect_NameType_PDU, proto_gnm, "tTPId(48)");
register_ber_oid_dissector("0.0.13.3100.0.7.49", dissect_ConnectivityPointer_PDU, proto_gnm, "upstreamConnectivityPointer(49)");
register_ber_oid_dissector("0.0.13.3100.0.7.50", dissect_UserLabel_PDU, proto_gnm, "userLabel(50)");
register_ber_oid_dissector("0.0.13.3100.0.7.51", dissect_VendorName_PDU, proto_gnm, "vendorName(51)");
register_ber_oid_dissector("0.0.13.3100.0.7.52", dissect_Version_PDU, proto_gnm, "version(52)");
register_ber_oid_dissector("0.0.13.3100.0.7.53", dissect_ObjectList_PDU, proto_gnm, "clientConnectionList(53)");
register_ber_oid_dissector("0.0.13.3100.0.7.54", dissect_CircuitPackType_PDU, proto_gnm, "circuitPackType(54)");
register_ber_oid_dissector("0.0.13.3100.0.7.55", dissect_RelatedObjectInstance_PDU, proto_gnm, "z-TPInstance(55)");
register_ber_oid_dissector("0.0.13.3100.0.7.56", dissect_EquipmentHolderAddress_PDU, proto_gnm, "equipmentHolderAddress(56)");
register_ber_oid_dissector("0.0.13.3100.0.7.57", dissect_EquipmentHolderType_PDU, proto_gnm, "equipmentHolderType(57)");
register_ber_oid_dissector("0.0.13.3100.0.7.58", dissect_AcceptableCircuitPackTypeList_PDU, proto_gnm, "acceptableCircuitPackTypeList(58)");
register_ber_oid_dissector("0.0.13.3100.0.7.59", dissect_HolderStatus_PDU, proto_gnm, "holderStatus(59)");
register_ber_oid_dissector("0.0.13.3100.0.7.60", dissect_SubordinateCircuitPackSoftwareLoad_PDU, proto_gnm, "subordinateCircuitPackSoftwareLoad(60)");
register_ber_oid_dissector("0.0.13.3100.0.7.61", dissect_NameType_PDU, proto_gnm, "circuitEndPointSubgroupId(61)");
register_ber_oid_dissector("0.0.13.3100.0.7.62", dissect_NumberOfCircuits_PDU, proto_gnm, "numberOfCircuits(62)");
register_ber_oid_dissector("0.0.13.3100.0.7.63", dissect_UserLabel_PDU, proto_gnm, "labelOfFarEndExchange(63)");
register_ber_oid_dissector("0.0.13.3100.0.7.64", dissect_SignallingCapabilities_PDU, proto_gnm, "signallingCapabilities(64)");
register_ber_oid_dissector("0.0.13.3100.0.7.65", dissect_InformationTransferCapabilities_PDU, proto_gnm, "informationTransferCapabilities(65)");
register_ber_oid_dissector("0.0.13.3100.0.7.66", dissect_CircuitDirectionality_PDU, proto_gnm, "circuitDirectionality(66)");
register_ber_oid_dissector("0.0.13.3100.0.7.67", dissect_TransmissionCharacteristics_PDU, proto_gnm, "transmissionCharacteristics(67)");
register_ber_oid_dissector("0.0.13.3100.0.7.68", dissect_NameType_PDU, proto_gnm, "managedElementComplexId(68)");
register_ber_oid_dissector("0.0.13.3100.0.7.69", dissect_SerialNumber_PDU, proto_gnm, "serialNumber(69)");
register_ber_oid_dissector("0.0.13.3100.0.9.4", dissect_ConnectInformation_PDU, proto_gnm, "connect(4)");
register_ber_oid_dissector("0.0.13.3100.0.9.5", dissect_DisconnectResult_PDU, proto_gnm, "disconnect(5)");
register_ber_oid_dissector("2.9.2.12.7.7", dissect_SupportedTOClasses_PDU, proto_gnm, "supportedTOClasses(7)");
#line 103 "../../asn1/gnm/packet-gnm-template.c"
register_ber_oid_dissector("0.0.13.3100.0.7.9", dissect_gnm_attribute_ObjectInstance, proto_gnm, "clientConnection(9)");
register_ber_oid_dissector("0.0.13.3100.0.7.10", dissect_gnm_attribute_ObjectInstance, proto_gnm, "clientTrail(10)");
register_ber_oid_dissector("0.0.13.3100.0.7.31", dissect_gnm_attribute_ObjectInstance, proto_gnm, "networkLevelPointer(31)");
register_ber_oid_dissector("0.0.13.3100.0.7.46", dissect_gnm_attribute_ObjectInstance, proto_gnm, "networkLevelPointer(31)");
}
