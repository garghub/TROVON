static int
dissect_rua_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rua_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 53 "../../asn1/rua/rua.cnf"
if (strcmp(val_to_str(ProcedureCode, rua_ProcedureCode_vals, "Unknown"), "Unknown") == 0) {
col_set_str(actx->pinfo->cinfo, COL_INFO,
"Unknown Message ");
}
return offset;
}
static int
dissect_rua_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_rua_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rua_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_rua_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 42 "../../asn1/rua/rua.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(rua_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_rua_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rua_ProtocolIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_rua_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_rua_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rua_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_rua_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_rua_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_rua_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rua_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_rua_PrivateIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rua_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_rua_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rua_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_rua_CN_DomainIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_rua_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_Establishment_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_Context_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL);
return offset;
}
static int
dissect_rua_RoutingParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL);
return offset;
}
static int
dissect_rua_T_localPTMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_localPTMSI, T_localPTMSI_sequence);
return offset;
}
static int
dissect_rua_T_tMSIofsamePLMN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_tMSIofsamePLMN, T_tMSIofsamePLMN_sequence);
return offset;
}
static int
dissect_rua_T_tMSIofdifferentPLMN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_tMSIofdifferentPLMN, T_tMSIofdifferentPLMN_sequence);
return offset;
}
static int
dissect_rua_T_iMSIresponsetopaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_iMSIresponsetopaging, T_iMSIresponsetopaging_sequence);
return offset;
}
static int
dissect_rua_T_iMSIcauseUEinitiatedEvent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_iMSIcauseUEinitiatedEvent, T_iMSIcauseUEinitiatedEvent_sequence);
return offset;
}
static int
dissect_rua_T_iMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_iMEI, T_iMEI_sequence);
return offset;
}
static int
dissect_rua_T_spare2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_spare2, T_spare2_sequence);
return offset;
}
static int
dissect_rua_T_spare1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_spare1, T_spare1_sequence);
return offset;
}
static int
dissect_rua_T_routingbasis(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_T_routingbasis, T_routingbasis_choice,
NULL);
return offset;
}
static int
dissect_rua_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_rua_Gsm_map_IDNNS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_Gsm_map_IDNNS, Gsm_map_IDNNS_sequence);
return offset;
}
static int
dissect_rua_Ansi_41_IDNNS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
14, 14, FALSE, NULL);
return offset;
}
static int
dissect_rua_T_cn_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_T_cn_Type, T_cn_Type_choice,
NULL);
return offset;
}
static int
dissect_rua_T_release99(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_release99, T_release99_sequence);
return offset;
}
static int
dissect_rua_BIT_STRING_SIZE_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
15, 15, FALSE, NULL);
return offset;
}
static int
dissect_rua_T_later(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_T_later, T_later_sequence);
return offset;
}
static int
dissect_rua_T_version(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_T_version, T_version_choice,
NULL);
return offset;
}
static int
dissect_rua_IntraDomainNasNodeSelector(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_IntraDomainNasNodeSelector, IntraDomainNasNodeSelector_sequence);
return offset;
}
static int
dissect_rua_RANAP_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 96 "../../asn1/rua/rua.cnf"
tvbuff_t *ranap_message_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &ranap_message_tvb);
if ((tvb_length(ranap_message_tvb)>0)&&(ranap_handle)) {
col_set_str(actx->pinfo->cinfo, COL_INFO,
"(RUA) ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
call_dissector(ranap_handle,ranap_message_tvb,actx->pinfo, proto_tree_get_root(tree));
}
return offset;
}
static int
dissect_rua_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_rua_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_rua_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_rua_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_rua_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_rua_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_rua_Connect(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 65 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"CONNECT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_Connect, Connect_sequence);
return offset;
}
static int
dissect_rua_DirectTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 70 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"DIRECT_TRANSFER ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_DirectTransfer, DirectTransfer_sequence);
return offset;
}
static int
dissect_rua_Disconnect(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 75 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"DISCONNECT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_Disconnect, Disconnect_sequence);
return offset;
}
static int
dissect_rua_ConnectionlessTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 80 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"CONNECTIONLESS_TRANSFER ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_ConnectionlessTransfer, ConnectionlessTransfer_sequence);
return offset;
}
static int
dissect_rua_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 85 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"ERROR_INDICATION ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_rua_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 91 "../../asn1/rua/rua.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"PRIVATE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_rua_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_rua_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_rua_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_rua_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_rua_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_rua_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_rua_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_rua_RUA_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_rua_RUA_PDU, RUA_PDU_choice,
NULL);
return offset;
}
static int dissect_CN_DomainIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_CN_DomainIndicator(tvb, offset, &asn1_ctx, tree, hf_rua_CN_DomainIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_rua_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Establishment_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_Establishment_Cause(tvb, offset, &asn1_ctx, tree, hf_rua_Establishment_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Context_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_Context_ID(tvb, offset, &asn1_ctx, tree, hf_rua_Context_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IntraDomainNasNodeSelector_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_IntraDomainNasNodeSelector(tvb, offset, &asn1_ctx, tree, hf_rua_IntraDomainNasNodeSelector_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RANAP_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_RANAP_Message(tvb, offset, &asn1_ctx, tree, hf_rua_RANAP_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_Cause(tvb, offset, &asn1_ctx, tree, hf_rua_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_rua_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Connect_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_Connect(tvb, offset, &asn1_ctx, tree, hf_rua_Connect_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DirectTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_DirectTransfer(tvb, offset, &asn1_ctx, tree, hf_rua_DirectTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Disconnect_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_Disconnect(tvb, offset, &asn1_ctx, tree, hf_rua_Disconnect_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ConnectionlessTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_ConnectionlessTransfer(tvb, offset, &asn1_ctx, tree, hf_rua_ConnectionlessTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_rua_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_rua_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_rua_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static void dissect_RUA_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_rua_RUA_PDU(tvb, 0, &asn1_ctx, tree, hf_rua_RUA_PDU_PDU);
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static void
dissect_rua(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *rua_item = NULL;
proto_tree *rua_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RUA");
rua_item = proto_tree_add_item(tree, proto_rua, tvb, 0, -1, ENC_NA);
rua_tree = proto_item_add_subtree(rua_item, ett_rua);
dissect_RUA_PDU_PDU(tvb, pinfo, rua_tree);
}
void proto_register_rua(void) {
module_t *rua_module;
static hf_register_info hf[] = {
#line 1 "../../asn1/rua/packet-rua-hfarr.c"
{ &hf_rua_CN_DomainIndicator_PDU,
{ "CN-DomainIndicator", "rua.CN_DomainIndicator",
FT_UINT32, BASE_DEC, VALS(rua_CN_DomainIndicator_vals), 0,
NULL, HFILL }},
{ &hf_rua_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "rua.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(rua_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_rua_Establishment_Cause_PDU,
{ "Establishment-Cause", "rua.Establishment_Cause",
FT_UINT32, BASE_DEC, VALS(rua_Establishment_Cause_vals), 0,
NULL, HFILL }},
{ &hf_rua_Context_ID_PDU,
{ "Context-ID", "rua.Context_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_IntraDomainNasNodeSelector_PDU,
{ "IntraDomainNasNodeSelector", "rua.IntraDomainNasNodeSelector_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_RANAP_Message_PDU,
{ "RANAP-Message", "rua.RANAP_Message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_Cause_PDU,
{ "Cause", "rua.Cause",
FT_UINT32, BASE_DEC, VALS(rua_Cause_vals), 0,
NULL, HFILL }},
{ &hf_rua_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "rua.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_Connect_PDU,
{ "Connect", "rua.Connect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_DirectTransfer_PDU,
{ "DirectTransfer", "rua.DirectTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_Disconnect_PDU,
{ "Disconnect", "rua.Disconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_ConnectionlessTransfer_PDU,
{ "ConnectionlessTransfer", "rua.ConnectionlessTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_ErrorIndication_PDU,
{ "ErrorIndication", "rua.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_PrivateMessage_PDU,
{ "PrivateMessage", "rua.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_RUA_PDU_PDU,
{ "RUA-PDU", "rua.RUA_PDU",
FT_UINT32, BASE_DEC, VALS(rua_RUA_PDU_vals), 0,
NULL, HFILL }},
{ &hf_rua_local,
{ "local", "rua.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_rua_global,
{ "global", "rua.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_rua_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "rua.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_protocol_ie_field_id,
{ "id", "rua.id",
FT_UINT32, BASE_DEC, VALS(rua_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_rua_criticality,
{ "criticality", "rua.criticality",
FT_UINT32, BASE_DEC, VALS(rua_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_rua_ie_field_value,
{ "value", "rua.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtocolIE_Field_value", HFILL }},
{ &hf_rua_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "rua.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_id,
{ "id", "rua.id",
FT_UINT32, BASE_DEC, VALS(rua_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_rua_extensionValue,
{ "extensionValue", "rua.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_PrivateIE_Container_item,
{ "PrivateIE-Field", "rua.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_private_ie_field_id,
{ "id", "rua.id",
FT_UINT32, BASE_DEC, VALS(rua_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_rua_private_value,
{ "value", "rua.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrivateIE_Field_value", HFILL }},
{ &hf_rua_version,
{ "version", "rua.version",
FT_UINT32, BASE_DEC, VALS(rua_T_version_vals), 0,
NULL, HFILL }},
{ &hf_rua_release99,
{ "release99", "rua.release99_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_cn_Type,
{ "cn-Type", "rua.cn_Type",
FT_UINT32, BASE_DEC, VALS(rua_T_cn_Type_vals), 0,
NULL, HFILL }},
{ &hf_rua_gsm_Map_IDNNS,
{ "gsm-Map-IDNNS", "rua.gsm_Map_IDNNS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_ansi_41_IDNNS,
{ "ansi-41-IDNNS", "rua.ansi_41_IDNNS",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_later,
{ "later", "rua.later_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_futurecoding,
{ "futurecoding", "rua.futurecoding",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_15", HFILL }},
{ &hf_rua_routingbasis,
{ "routingbasis", "rua.routingbasis",
FT_UINT32, BASE_DEC, VALS(rua_T_routingbasis_vals), 0,
NULL, HFILL }},
{ &hf_rua_localPTMSI,
{ "localPTMSI", "rua.localPTMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_routingparameter,
{ "routingparameter", "rua.routingparameter",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_tMSIofsamePLMN,
{ "tMSIofsamePLMN", "rua.tMSIofsamePLMN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_tMSIofdifferentPLMN,
{ "tMSIofdifferentPLMN", "rua.tMSIofdifferentPLMN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_iMSIresponsetopaging,
{ "iMSIresponsetopaging", "rua.iMSIresponsetopaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_iMSIcauseUEinitiatedEvent,
{ "iMSIcauseUEinitiatedEvent", "rua.iMSIcauseUEinitiatedEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_iMEI,
{ "iMEI", "rua.iMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_spare2,
{ "spare2", "rua.spare2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_spare1,
{ "spare1", "rua.spare1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_dummy,
{ "dummy", "rua.dummy",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_rua_radioNetwork,
{ "radioNetwork", "rua.radioNetwork",
FT_UINT32, BASE_DEC, VALS(rua_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_rua_transport,
{ "transport", "rua.transport",
FT_UINT32, BASE_DEC, VALS(rua_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_rua_protocol,
{ "protocol", "rua.protocol",
FT_UINT32, BASE_DEC, VALS(rua_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_rua_misc,
{ "misc", "rua.misc",
FT_UINT32, BASE_DEC, VALS(rua_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_rua_procedureCode,
{ "procedureCode", "rua.procedureCode",
FT_UINT32, BASE_DEC, VALS(rua_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_rua_triggeringMessage,
{ "triggeringMessage", "rua.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(rua_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_rua_procedureCriticality,
{ "procedureCriticality", "rua.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(rua_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_rua_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "rua.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_rua_iE_Extensions,
{ "iE-Extensions", "rua.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_rua_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "rua.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_iECriticality,
{ "iECriticality", "rua.iECriticality",
FT_UINT32, BASE_DEC, VALS(rua_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_rua_iE_ID,
{ "iE-ID", "rua.iE_ID",
FT_UINT32, BASE_DEC, VALS(rua_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_rua_typeOfError,
{ "typeOfError", "rua.typeOfError",
FT_UINT32, BASE_DEC, VALS(rua_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_rua_protocolIEs,
{ "protocolIEs", "rua.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_rua_protocolExtensions,
{ "protocolExtensions", "rua.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_rua_privateIEs,
{ "privateIEs", "rua.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_rua_initiatingMessage,
{ "initiatingMessage", "rua.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_successfulOutcome,
{ "successfulOutcome", "rua.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "rua.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rua_initiatingMessagevalue,
{ "value", "rua.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_rua_successfulOutcome_value,
{ "value", "rua.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_rua_unsuccessfulOutcome_value,
{ "value", "rua.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 140 "../../asn1/rua/packet-rua-template.c"
};
static gint *ett[] = {
&ett_rua,
#line 1 "../../asn1/rua/packet-rua-ettarr.c"
&ett_rua_PrivateIE_ID,
&ett_rua_ProtocolIE_Container,
&ett_rua_ProtocolIE_Field,
&ett_rua_ProtocolExtensionContainer,
&ett_rua_ProtocolExtensionField,
&ett_rua_PrivateIE_Container,
&ett_rua_PrivateIE_Field,
&ett_rua_IntraDomainNasNodeSelector,
&ett_rua_T_version,
&ett_rua_T_release99,
&ett_rua_T_cn_Type,
&ett_rua_T_later,
&ett_rua_Gsm_map_IDNNS,
&ett_rua_T_routingbasis,
&ett_rua_T_localPTMSI,
&ett_rua_T_tMSIofsamePLMN,
&ett_rua_T_tMSIofdifferentPLMN,
&ett_rua_T_iMSIresponsetopaging,
&ett_rua_T_iMSIcauseUEinitiatedEvent,
&ett_rua_T_iMEI,
&ett_rua_T_spare2,
&ett_rua_T_spare1,
&ett_rua_Cause,
&ett_rua_CriticalityDiagnostics,
&ett_rua_CriticalityDiagnostics_IE_List,
&ett_rua_CriticalityDiagnostics_IE_List_item,
&ett_rua_Connect,
&ett_rua_DirectTransfer,
&ett_rua_Disconnect,
&ett_rua_ConnectionlessTransfer,
&ett_rua_ErrorIndication,
&ett_rua_PrivateMessage,
&ett_rua_RUA_PDU,
&ett_rua_InitiatingMessage,
&ett_rua_SuccessfulOutcome,
&ett_rua_UnsuccessfulOutcome,
#line 146 "../../asn1/rua/packet-rua-template.c"
};
proto_rua = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_rua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rua", dissect_rua, proto_rua);
rua_ies_dissector_table = register_dissector_table("rua.ies", "RUA-PROTOCOL-IES", FT_UINT32, BASE_DEC);
rua_extension_dissector_table = register_dissector_table("rua.extension", "RUA-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
rua_proc_imsg_dissector_table = register_dissector_table("rua.proc.imsg", "RUA-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
rua_proc_sout_dissector_table = register_dissector_table("rua.proc.sout", "RUA-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
rua_proc_uout_dissector_table = register_dissector_table("rua.proc.uout", "RUA-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
rua_module = prefs_register_protocol(proto_rua, proto_reg_handoff_rua);
prefs_register_uint_preference(rua_module, "port", "RUA SCTP Port", "Set the port for RUA messages (Default of 29169)", 10, &global_sctp_port);
}
void
proto_reg_handoff_rua(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t rua_handle;
static guint sctp_port;
if (!initialized) {
rua_handle = find_dissector("rua");
ranap_handle = find_dissector("ranap");
dissector_add_uint("sctp.ppi", RUA_PAYLOAD_PROTOCOL_ID, rua_handle);
initialized = TRUE;
#line 1 "../../asn1/rua/packet-rua-dis-tab.c"
dissector_add_uint("rua.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_rua));
dissector_add_uint("rua.ies", id_CriticalityDiagnostics, new_create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_rua));
dissector_add_uint("rua.ies", id_Context_ID, new_create_dissector_handle(dissect_Context_ID_PDU, proto_rua));
dissector_add_uint("rua.ies", id_RANAP_Message, new_create_dissector_handle(dissect_RANAP_Message_PDU, proto_rua));
dissector_add_uint("rua.ies", id_IntraDomainNasNodeSelector, new_create_dissector_handle(dissect_IntraDomainNasNodeSelector_PDU, proto_rua));
dissector_add_uint("rua.ies", id_Establishment_Cause, new_create_dissector_handle(dissect_Establishment_Cause_PDU, proto_rua));
dissector_add_uint("rua.ies", id_CN_DomainIndicator, new_create_dissector_handle(dissect_CN_DomainIndicator_PDU, proto_rua));
dissector_add_uint("rua.extension", id_CSGMembershipStatus, new_create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_Connect, new_create_dissector_handle(dissect_Connect_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_DirectTransfer, new_create_dissector_handle(dissect_DirectTransfer_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_Disconnect, new_create_dissector_handle(dissect_Disconnect_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_ConnectionlessTransfer, new_create_dissector_handle(dissect_ConnectionlessTransfer_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_ErrorIndication, new_create_dissector_handle(dissect_ErrorIndication_PDU, proto_rua));
dissector_add_uint("rua.proc.imsg", id_privateMessage, new_create_dissector_handle(dissect_PrivateMessage_PDU, proto_rua));
#line 185 "../../asn1/rua/packet-rua-template.c"
} else {
dissector_delete_uint("sctp.port", sctp_port, rua_handle);
}
sctp_port = global_sctp_port;
dissector_add_uint("sctp.port", sctp_port, rua_handle);
}
