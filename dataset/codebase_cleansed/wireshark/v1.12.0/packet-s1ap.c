static int
dissect_s1ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_s1ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 106 "../../asn1/s1ap/s1ap.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s",
val_to_str_ext(ProcedureCode, &s1ap_ProcedureCode_vals_ext,
"unknown message"));
return offset;
}
static int
dissect_s1ap_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolExtensionID, FALSE);
return offset;
}
static int
dissect_s1ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolIE_ID, FALSE);
#line 89 "../../asn1/s1ap/s1ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(ProtocolIE_ID, &s1ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_s1ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_s1ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_s1ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_s1ap_ProtocolIE_SingleContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_ProtocolIE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "../../asn1/s1ap/s1ap.cnf"
static const asn1_par_def_t ProtocolIE_ContainerList_pars[] = {
{ "lowerBound", ASN1_PAR_INTEGER },
{ "upperBound", ASN1_PAR_INTEGER },
{ NULL, (asn1_par_type)0 }
};
asn1_stack_frame_check(actx, "ProtocolIE-ContainerList", ProtocolIE_ContainerList_pars);
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_ContainerList, ProtocolIE_ContainerList_sequence_of,
asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);
return offset;
}
static int
dissect_s1ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_s1ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_s1ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_s1ap_T_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_s1ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_s1ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_s1ap_PLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 193 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if(tvb_length(tvb)==0)
return offset;
if (!parameter_tvb)
return offset;
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, FALSE);
return offset;
}
static int
dissect_s1ap_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_EUTRAN_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRAN_CGI, EUTRAN_CGI_sequence);
return offset;
}
static int
dissect_s1ap_CellIdListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellIdListforMDT, CellIdListforMDT_sequence_of,
1, maxnoofCellIDforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_CellBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellBasedMDT, CellBasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_TAListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAListforMDT, TAListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_TABasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TABasedMDT, TABasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_TAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI, TAI_sequence);
return offset;
}
static int
dissect_s1ap_TAIListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIListforMDT, TAIListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_TAIBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIBasedMDT, TAIBasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_AreaScopeOfMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_AreaScopeOfMDT, AreaScopeOfMDT_choice,
NULL);
return offset;
}
static int
dissect_s1ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_s1ap_Bearers_SubjectToStatusTransferList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_Bearers_SubjectToStatusTransferList, Bearers_SubjectToStatusTransferList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_PDCP_SN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_HFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_COUNTvalue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_COUNTvalue, COUNTvalue_sequence);
return offset;
}
static int
dissect_s1ap_ReceiveStatusofULPDCPSDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4096, 4096, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Bearers_SubjectToStatusTransfer_Item, Bearers_SubjectToStatusTransfer_Item_sequence);
return offset;
}
static int
dissect_s1ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(10000000000), NULL, FALSE);
return offset;
}
static int
dissect_s1ap_BPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_BPLMNs, BPLMNs_sequence_of,
1, maxnoofBPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_NumberOfBroadcasts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_CellID_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Cancelled_Item, CellID_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellID_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Cancelled, CellID_Cancelled_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_CancelledCellinTAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinTAI_Item, CancelledCellinTAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CancelledCellinTAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinTAI, CancelledCellinTAI_sequence_of,
1, maxnoofCellinTAI, FALSE);
return offset;
}
static int
dissect_s1ap_TAI_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Cancelled_Item, TAI_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_TAI_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Cancelled, TAI_Cancelled_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CancelledCellinEAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinEAI_Item, CancelledCellinEAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CancelledCellinEAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinEAI, CancelledCellinEAI_sequence_of,
1, maxnoofCellinEAI, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Cancelled_Item, EmergencyAreaID_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Cancelled, EmergencyAreaID_Cancelled_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_BroadcastCancelledAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_BroadcastCancelledAreaList, BroadcastCancelledAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellID_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Broadcast_Item, CellID_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellID_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Broadcast, CellID_Broadcast_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_CompletedCellinTAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinTAI_Item, CompletedCellinTAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CompletedCellinTAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinTAI, CompletedCellinTAI_sequence_of,
1, maxnoofCellinTAI, FALSE);
return offset;
}
static int
dissect_s1ap_TAI_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Broadcast_Item, TAI_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_TAI_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Broadcast, TAI_Broadcast_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_CompletedCellinEAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinEAI_Item, CompletedCellinEAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CompletedCellinEAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinEAI, CompletedCellinEAI_sequence_of,
1, maxnoofCellinEAI, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Broadcast_Item, EmergencyAreaID_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Broadcast, EmergencyAreaID_Broadcast_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_BroadcastCompletedAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_BroadcastCompletedAreaList, BroadcastCompletedAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1125 "../../asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
36, &value, TRUE, 3, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [RadioNetwork-cause=%s]", val_to_str_const(value, s1ap_CauseRadioNetwork_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1130 "../../asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Transport-cause=%s]", val_to_str_const(value, s1ap_CauseTransport_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseNas(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1135 "../../asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, &value, TRUE, 1, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [NAS-cause=%s]", val_to_str_const(value, s1ap_CauseNas_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1140 "../../asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Protocol-cause=%s]", val_to_str_const(value, s1ap_CauseProtocol_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1145 "../../asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Misc-cause=%s]", val_to_str_const(value, s1ap_CauseMisc_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellAccessMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000RATType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000SectorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000HOStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000HORequiredIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXMEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXPilot(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXSRVCCInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Cdma2000OneXSRVCCInfo, Cdma2000OneXSRVCCInfo_sequence);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXRAND(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cell_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellType, CellType_sequence);
return offset;
}
static int
dissect_s1ap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_RAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CGI, CGI_sequence);
return offset;
}
static int
dissect_s1ap_CNDomain(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ConcurrentWarningMessageIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Correlation_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CSFallbackIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_CSG_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_CSG_IdList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CSG_IdList_Item, CSG_IdList_Item_sequence);
return offset;
}
static int
dissect_s1ap_CSG_IdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CSG_IdList, CSG_IdList_sequence_of,
1, maxnoofCSGs, FALSE);
return offset;
}
static int
dissect_s1ap_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PDCP_SNExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_HFNModified(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_COUNTValueExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_COUNTValueExtended, COUNTValueExtended_sequence);
return offset;
}
static int
dissect_s1ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics_IE_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics_IE_Item, CriticalityDiagnostics_IE_Item_sequence);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxnoofErrors, FALSE);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_s1ap_DataCodingScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_DL_Forwarding(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Direct_Forwarding_Path_Availability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Data_Forwarding_Not_Possible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ECGIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ECGIList, ECGIList_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaIDList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaIDList, EmergencyAreaIDList_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LAI, LAI_sequence);
return offset;
}
static int
dissect_s1ap_GERAN_Cell_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GERAN_Cell_ID, GERAN_Cell_ID_sequence);
return offset;
}
int
dissect_s1ap_Global_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Global_ENB_ID, Global_ENB_ID_sequence);
return offset;
}
static int
dissect_s1ap_MME_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_MME_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_GUMMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GUMMEI, GUMMEI_sequence);
return offset;
}
static int
dissect_s1ap_GUMMEIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_GUMMEIList, GUMMEIList_sequence_of,
1, maxnoofMMECs, FALSE);
return offset;
}
static int
dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENB_StatusTransfer_TransparentContainer, ENB_StatusTransfer_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_ENB_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ENBname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 206 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
int length;
int p_offset;
gboolean is_ascii;
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
if (!parameter_tvb)
return offset;
length = tvb_length(parameter_tvb);
is_ascii = TRUE;
for (p_offset=0; p_offset < length; p_offset++){
if(!isalpha(tvb_get_guint8(parameter_tvb, p_offset ))){
is_ascii = FALSE;
break;
}
}
if (is_ascii)
proto_item_append_text(actx->created_item,"(%s)",tvb_format_text(parameter_tvb, 0, length));
return offset;
}
static int
dissect_s1ap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 250 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
gint tvb_len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_TransportLayerAddress);
if (tvb_len==4){
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv4, parameter_tvb, 0, tvb_len, ENC_BIG_ENDIAN);
}
if (tvb_len==16){
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv6, parameter_tvb, 0, tvb_len, ENC_NA);
}
return offset;
}
static int
dissect_s1ap_ENBX2TLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2TLAs, ENBX2TLAs_sequence_of,
1, maxnoofeNBX2TLAs, FALSE);
return offset;
}
static int
dissect_s1ap_EncryptionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_EPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EPLMNs, EPLMNs_sequence_of,
1, maxnoofEPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_EventType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_E_RABInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABInformationList, E_RABInformationList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABInformationListItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABInformationListItem, E_RABInformationListItem_sequence);
return offset;
}
static int
dissect_s1ap_E_RABList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABList, E_RABList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABItem, E_RABItem_sequence);
return offset;
}
static int
dissect_s1ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_s1ap_E_RABLevelQoSParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABLevelQoSParameters, E_RABLevelQoSParameters_sequence);
return offset;
}
static int
dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ExtendedRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ExtendedRepetitionPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenInterRATs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_s1ap_ForbiddenTACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTACs, ForbiddenTACs_sequence_of,
1, maxnoofForbTACs, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTAs_Item, ForbiddenTAs_Item_sequence);
return offset;
}
static int
dissect_s1ap_ForbiddenTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTAs, ForbiddenTAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenLACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLACs, ForbiddenLACs_sequence_of,
1, maxnoofForbLACs, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenLAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLAs_Item, ForbiddenLAs_Item_sequence);
return offset;
}
static int
dissect_s1ap_ForbiddenLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLAs, ForbiddenLAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_s1ap_GTP_TEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_GUMMEIType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_GWContextReleaseIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HandoverRestrictionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRestrictionList, HandoverRestrictionList_sequence);
return offset;
}
static int
dissect_s1ap_HandoverType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 285 "../../asn1/s1ap/s1ap.cnf"
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, &handover_type_value, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MeasurementsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_M1ReportingTrigger(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_Threshold_RSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_Threshold_RSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_MeasurementThresholdA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MeasurementThresholdA2, MeasurementThresholdA2_choice,
NULL);
return offset;
}
static int
dissect_s1ap_M1ThresholdEventA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M1ThresholdEventA2, M1ThresholdEventA2_sequence);
return offset;
}
static int
dissect_s1ap_ReportIntervalMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ReportAmountMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M1PeriodicReporting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M1PeriodicReporting, M1PeriodicReporting_sequence);
return offset;
}
static int
dissect_s1ap_ImmediateMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ImmediateMDT, ImmediateMDT_sequence);
return offset;
}
static int
dissect_s1ap_IMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 8, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_IntegrityProtectionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_InterfacesToTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_Time_UE_StayedInCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_LastVisitedEUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedEUTRANCellInformation, LastVisitedEUTRANCellInformation_sequence);
return offset;
}
static int
dissect_s1ap_LastVisitedUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_LastVisitedGERANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedGERANCellInformation, LastVisitedGERANCellInformation_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LastVisitedCell_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedCell_Item, LastVisitedCell_Item_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LPPa_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 241 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((tvb_length(parameter_tvb)>0)&&(lppa_handle))
call_dissector(lppa_handle, parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_s1ap_Links_to_log(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_LoggingInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_LoggingDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_LoggedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LoggedMDT, LoggedMDT_sequence);
return offset;
}
static int
dissect_s1ap_M3period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M3Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M3Configuration, M3Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M4period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M4Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M4Configuration, M4Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M5period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M5Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M5Configuration, M5Configuration_sequence);
return offset;
}
static int
dissect_s1ap_MDT_Activation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MDT_Location_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_MDTMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDTMode, MDTMode_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MDT_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDT_Configuration, MDT_Configuration_sequence);
return offset;
}
static int
dissect_s1ap_ManagementBasedMDTAllowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MDTPLMNList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDTPLMNList, MDTPLMNList_sequence_of,
1, maxnoofMDTPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_PrivacyIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MessageIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_MobilityInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_MMEname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
return offset;
}
static int
dissect_s1ap_MMERelaySupportIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MME_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_M_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_MSClassmark2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_MSClassmark3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_NAS_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 232 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((tvb_length(parameter_tvb)>0)&&(nas_eps_handle))
call_dissector(nas_eps_handle,parameter_tvb,actx->pinfo, tree);
return offset;
}
static int
dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_NumberofBroadcastRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_OverloadAction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_s1ap_OverloadResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadResponse, OverloadResponse_choice,
NULL);
return offset;
}
static int
dissect_s1ap_PagingDRX(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PagingPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Port_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_PS_ServiceNotAvailable(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16384, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_RelativeMMECapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_RelayNode_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ReportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_RequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RequestType, RequestType_sequence);
return offset;
}
static int
dissect_s1ap_RIMInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 490 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_RIMInformation);
if ((tvb_length(parameter_tvb)>0)&&(bssgp_handle)){
col_set_fence(actx->pinfo->cinfo, COL_INFO);
call_dissector(bssgp_handle,parameter_tvb,actx->pinfo, subtree);
}
return offset;
}
static int
dissect_s1ap_RNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_TargetRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargetRNC_ID, TargetRNC_ID_sequence);
return offset;
}
static int
dissect_s1ap_RIMRoutingAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_RIMRoutingAddress, RIMRoutingAddress_choice,
NULL);
return offset;
}
static int
dissect_s1ap_RIMTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RIMTransfer, RIMTransfer_sequence);
return offset;
}
static int
dissect_s1ap_RepetitionPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_RRC_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 415 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_RRCContainer);
switch(message_type){
case INITIATING_MESSAGE:
dissect_lte_rrc_HandoverPreparationInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case SUCCESSFUL_OUTCOME:
dissect_lte_rrc_HandoverCommand_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
default:
break;
}
}
return offset;
}
static int
dissect_s1ap_RRC_Establishment_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_Routing_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_SecurityKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_SecurityContext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SecurityContext, SecurityContext_sequence);
return offset;
}
static int
dissect_s1ap_SerialNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_SONInformationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_X2TNLConfigurationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_X2TNLConfigurationInfo, X2TNLConfigurationInfo_sequence);
return offset;
}
static int
dissect_s1ap_SONInformationReply(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONInformationReply, SONInformationReply_sequence);
return offset;
}
static int
dissect_s1ap_SONInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONInformation, SONInformation_choice,
NULL);
return offset;
}
static int
dissect_s1ap_TargeteNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargeteNB_ID, TargeteNB_ID_sequence);
return offset;
}
static int
dissect_s1ap_SourceeNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SourceeNB_ID, SourceeNB_ID_sequence);
return offset;
}
static int
dissect_s1ap_SONConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONConfigurationTransfer, SONConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_Source_ToTarget_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 304 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_ToTargetTransparentContainer);
switch(handover_type_value){
case 0:
dissect_SourceeNB_ToTargeteNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 1:
dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 2:
de_bssgp_source_BSS_to_target_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_length(parameter_tvb), NULL, 0);
break;
case 3:
break;
case 4:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
return offset;
}
static int
dissect_s1ap_SRVCCOperationPossible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SRVCCHOIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SubscriberProfileIDforRFP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_UE_HistoryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_HistoryInformation, UE_HistoryInformation_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SourceeNB_ToTargeteNB_TransparentContainer, SourceeNB_ToTargeteNB_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_ServedPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedPLMNs, ServedPLMNs_sequence_of,
1, maxnoofPLMNsPerMME, FALSE);
return offset;
}
static int
dissect_s1ap_ServedGroupIDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGroupIDs, ServedGroupIDs_sequence_of,
1, maxnoofGroupIDs, FALSE);
return offset;
}
static int
dissect_s1ap_ServedMMECs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedMMECs, ServedMMECs_sequence_of,
1, maxnoofMMECs, FALSE);
return offset;
}
static int
dissect_s1ap_ServedGUMMEIsItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGUMMEIsItem, ServedGUMMEIsItem_sequence);
return offset;
}
static int
dissect_s1ap_ServedGUMMEIs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGUMMEIs, ServedGUMMEIs_sequence_of,
1, maxnoofRATs, FALSE);
return offset;
}
static int
dissect_s1ap_SupportedTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SupportedTAs_Item, SupportedTAs_Item_sequence);
return offset;
}
static int
dissect_s1ap_SupportedTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_SupportedTAs, SupportedTAs_sequence_of,
1, maxnoofTACs, FALSE);
return offset;
}
static int
dissect_s1ap_StratumLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_SynchronizationStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_TimeSynchronizationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TimeSynchronizationInfo, TimeSynchronizationInfo_sequence);
return offset;
}
static int
dissect_s1ap_S_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S_TMSI, S_TMSI_sequence);
return offset;
}
static int
dissect_s1ap_TAIListforWarning(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIListforWarning, TAIListforWarning_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_TargetID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargetID, TargetID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargeteNB_ToSourceeNB_TransparentContainer, TargeteNB_ToSourceeNB_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_Target_ToSource_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 357 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_ToSourceTransparentContainer);
switch(handover_type_value){
case 0:
dissect_TargeteNB_ToSourceeNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 1:
dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 2:
de_bssgp_target_BSS_to_source_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_length(parameter_tvb), NULL, 0);
break;
case 3:
break;
case 4:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
return offset;
}
static int
dissect_s1ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 40950U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_E_UTRAN_Trace_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_TraceDepth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_TraceActivation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceActivation, TraceActivation_sequence);
return offset;
}
static int
dissect_s1ap_TrafficLoadReductionIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 99U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_TunnelInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TunnelInformation, TunnelInformation_sequence);
return offset;
}
static int
dissect_s1ap_UEAggregateMaximumBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEAggregateMaximumBitrate, UEAggregateMaximumBitrate_sequence);
return offset;
}
static int
dissect_s1ap_UE_S1AP_ID_pair(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_S1AP_ID_pair, UE_S1AP_ID_pair_sequence);
return offset;
}
static int
dissect_s1ap_UE_S1AP_IDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_S1AP_IDs, UE_S1AP_IDs_choice,
NULL);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionItem, UE_associatedLogicalS1_ConnectionItem_sequence);
return offset;
}
static int
dissect_s1ap_UEIdentityIndexValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_UEPagingID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEPagingID, UEPagingID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_UERadioCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 475 "../../asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UERadioCapability);
dissect_lte_rrc_UERadioAccessCapabilityInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_UESecurityCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UESecurityCapabilities, UESecurityCapabilities_sequence);
return offset;
}
static int
dissect_s1ap_VoiceSupportMatchIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_WarningAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_WarningAreaList, WarningAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_WarningType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_WarningSecurityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
50, 50, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_WarningMessageContents(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 9600, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_ENBX2GTPTLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2GTPTLAs, ENBX2GTPTLAs_sequence_of,
1, maxnoofeNBX2GTPTLAs, FALSE);
return offset;
}
static int
dissect_s1ap_ENBX2ExtTLA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2ExtTLA, ENBX2ExtTLA_sequence);
return offset;
}
static int
dissect_s1ap_ENBX2ExtTLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2ExtTLAs, ENBX2ExtTLAs_sequence_of,
1, maxnoofeNBX2ExtTLAs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RAB_IE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 158 "../../asn1/s1ap/s1ap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxnoofE_RABs);
offset = dissect_s1ap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");
return offset;
}
static int
dissect_s1ap_HandoverRequired(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 290 "../../asn1/s1ap/s1ap.cnf"
handover_type_value = 0;
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverRequired ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequired, HandoverRequired_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 292 "../../asn1/s1ap/s1ap.cnf"
handover_type_value = 0;
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCommand, HandoverCommand_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSubjecttoDataForwardingList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABDataForwardingItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABDataForwardingItem, E_RABDataForwardingItem_sequence);
return offset;
}
static int
dissect_s1ap_HandoverPreparationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1066 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverPreparationFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverPreparationFailure, HandoverPreparationFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 294 "../../asn1/s1ap/s1ap.cnf"
handover_type_value = 0;
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequest, HandoverRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListHOReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemHOReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemHOReq, E_RABToBeSetupItemHOReq_sequence);
return offset;
}
static int
dissect_s1ap_HandoverRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1070 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverRequestAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequestAcknowledge, HandoverRequestAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABAdmittedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABAdmittedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABAdmittedItem, E_RABAdmittedItem_sequence);
return offset;
}
static int
dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABFailedToSetupItemHOReqAck, E_RABFailedToSetupItemHOReqAck_sequence);
return offset;
}
static int
dissect_s1ap_HandoverFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1072 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverFailure, HandoverFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverNotify(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1074 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverNotify ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverNotify, HandoverNotify_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1076 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", PathSwitchRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequest, PathSwitchRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedDLList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedDLItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSwitchedDLItem, E_RABToBeSwitchedDLItem_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1078 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", PathSwitchRequestAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequestAcknowledge, PathSwitchRequestAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedULList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedULItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSwitchedULItem, E_RABToBeSwitchedULItem_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequestFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1080 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", PathSwitchRequestFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequestFailure, PathSwitchRequestFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1082 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverCancel ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCancel, HandoverCancel_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCancelAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1084 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", HandoverCancelAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCancelAcknowledge, HandoverCancelAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1028 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABSetupRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupRequest, E_RABSetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupListBearerSUReq, E_RABToBeSetupListBearerSUReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemBearerSUReq, E_RABToBeSetupItemBearerSUReq_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1030 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABSetupResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupResponse, E_RABSetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupListBearerSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupListBearerSURes, E_RABSetupListBearerSURes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABSetupItemBearerSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupItemBearerSURes, E_RABSetupItemBearerSURes_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1032 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABModifyRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyRequest, E_RABModifyRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeModifiedListBearerModReq, E_RABToBeModifiedListBearerModReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeModifiedItemBearerModReq, E_RABToBeModifiedItemBearerModReq_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1034 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABModifyResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyResponse, E_RABModifyResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyListBearerModRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyListBearerModRes, E_RABModifyListBearerModRes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABModifyItemBearerModRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyItemBearerModRes, E_RABModifyItemBearerModRes_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1036 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABReleaseCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseCommand, E_RABReleaseCommand_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1038 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABReleaseResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseResponse, E_RABReleaseResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseListBearerRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseListBearerRelComp, E_RABReleaseListBearerRelComp_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABReleaseItemBearerRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseItemBearerRelComp, E_RABReleaseItemBearerRelComp_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1040 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", E_RABReleaseIndication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseIndication, E_RABReleaseIndication_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1043 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", InitialContextSetupRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupRequest, InitialContextSetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupListCtxtSUReq, E_RABToBeSetupListCtxtSUReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemCtxtSUReq, E_RABToBeSetupItemCtxtSUReq_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1045 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", InitialContextSetupResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupResponse, InitialContextSetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupListCtxtSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupListCtxtSURes, E_RABSetupListCtxtSURes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABSetupItemCtxtSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupItemCtxtSURes, E_RABSetupItemCtxtSURes_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1047 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", InitialContextSetupFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupFailure, InitialContextSetupFailure_sequence);
return offset;
}
static int
dissect_s1ap_Paging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Paging, Paging_sequence);
return offset;
}
static int
dissect_s1ap_TAIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIList, TAIList_sequence_of,
1, maxnoofTAIs, FALSE);
return offset;
}
static int
dissect_s1ap_TAIItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIItem, TAIItem_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1049 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextReleaseRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseRequest, UEContextReleaseRequest_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1051 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextReleaseCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseCommand, UEContextReleaseCommand_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1053 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextReleaseComplete ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseComplete, UEContextReleaseComplete_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1055 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextModificationRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationRequest, UEContextModificationRequest_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1057 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextModificationResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationResponse, UEContextModificationResponse_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1059 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", UEContextModificationFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationFailure, UEContextModificationFailure_sequence);
return offset;
}
static int
dissect_s1ap_UERadioCapabilityMatchRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UERadioCapabilityMatchRequest, UERadioCapabilityMatchRequest_sequence);
return offset;
}
static int
dissect_s1ap_UERadioCapabilityMatchResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UERadioCapabilityMatchResponse, UERadioCapabilityMatchResponse_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkNASTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 277 "../../asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_DL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkNASTransport, DownlinkNASTransport_sequence);
return offset;
}
static int
dissect_s1ap_InitialUEMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 273 "../../asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_UL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialUEMessage, InitialUEMessage_sequence);
return offset;
}
static int
dissect_s1ap_UplinkNASTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 281 "../../asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_UL;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkNASTransport, UplinkNASTransport_sequence);
return offset;
}
static int
dissect_s1ap_NASNonDeliveryIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_NASNonDeliveryIndication, NASNonDeliveryIndication_sequence);
return offset;
}
static int
dissect_s1ap_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1088 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", Reset ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Reset, Reset_sequence);
return offset;
}
static int
dissect_s1ap_ResetAll(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionListRes, UE_associatedLogicalS1_ConnectionListRes_sequence_of,
1, maxnoofIndividualS1ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_s1ap_ResetType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_ResetType, ResetType_choice,
NULL);
return offset;
}
static int
dissect_s1ap_ResetAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1090 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", ResetAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ResetAcknowledge, ResetAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionListResAck, UE_associatedLogicalS1_ConnectionListResAck_sequence_of,
1, maxnoofIndividualS1ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_s1ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1094 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", S1SetupRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupRequest, S1SetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1096 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", S1SetupResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupResponse, S1SetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1098 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", S1SetupFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupFailure, S1SetupFailure_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1100 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", ENBConfigurationUpdate ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1102 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", ENBConfigurationUpdateAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1104 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", ENBConfigurationUpdateFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1106 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", MMEConfigurationUpdate ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdate, MMEConfigurationUpdate_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1108 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", MMEConfigurationUpdateAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdateAcknowledge, MMEConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1110 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", MMEConfigurationUpdateFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdateFailure, MMEConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkS1cdma2000tunneling(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkS1cdma2000tunneling, DownlinkS1cdma2000tunneling_sequence);
return offset;
}
static int
dissect_s1ap_UplinkS1cdma2000tunneling(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkS1cdma2000tunneling, UplinkS1cdma2000tunneling_sequence);
return offset;
}
static int
dissect_s1ap_UECapabilityInfoIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UECapabilityInfoIndication, UECapabilityInfoIndication_sequence);
return offset;
}
static int
dissect_s1ap_ENBStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBStatusTransfer, ENBStatusTransfer_sequence);
return offset;
}
static int
dissect_s1ap_MMEStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEStatusTransfer, MMEStatusTransfer_sequence);
return offset;
}
static int
dissect_s1ap_TraceStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceStart, TraceStart_sequence);
return offset;
}
static int
dissect_s1ap_TraceFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceFailureIndication, TraceFailureIndication_sequence);
return offset;
}
static int
dissect_s1ap_DeactivateTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DeactivateTrace, DeactivateTrace_sequence);
return offset;
}
static int
dissect_s1ap_CellTrafficTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellTrafficTrace, CellTrafficTrace_sequence);
return offset;
}
static int
dissect_s1ap_LocationReportingControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReportingControl, LocationReportingControl_sequence);
return offset;
}
static int
dissect_s1ap_LocationReportingFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReportingFailureIndication, LocationReportingFailureIndication_sequence);
return offset;
}
static int
dissect_s1ap_LocationReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReport, LocationReport_sequence);
return offset;
}
static int
dissect_s1ap_OverloadStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadStart, OverloadStart_sequence);
return offset;
}
static int
dissect_s1ap_OverloadStop(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadStop, OverloadStop_sequence);
return offset;
}
static int
dissect_s1ap_WriteReplaceWarningRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1113 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", WriteReplaceWarningRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_WriteReplaceWarningRequest, WriteReplaceWarningRequest_sequence);
return offset;
}
static int
dissect_s1ap_WriteReplaceWarningResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1115 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", WriteReplaceWarningResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_WriteReplaceWarningResponse, WriteReplaceWarningResponse_sequence);
return offset;
}
static int
dissect_s1ap_ENBDirectInformationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBDirectInformationTransfer, ENBDirectInformationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_Inter_SystemInformationTransferType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_Inter_SystemInformationTransferType, Inter_SystemInformationTransferType_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MMEDirectInformationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEDirectInformationTransfer, MMEDirectInformationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationTransfer, ENBConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationTransfer, MMEConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_s1ap_KillRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1117 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", KillRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_KillRequest, KillRequest_sequence);
return offset;
}
static int
dissect_s1ap_KillResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1119 "../../asn1/s1ap/s1ap.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, ", KillResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_KillResponse, KillResponse_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkUEAssociatedLPPaTransport, DownlinkUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkUEAssociatedLPPaTransport, UplinkUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkNonUEAssociatedLPPaTransport, DownlinkNonUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkNonUEAssociatedLPPaTransport, UplinkNonUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 113 "../../asn1/s1ap/s1ap.cnf"
message_type = INITIATING_MESSAGE;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_s1ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_s1ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 116 "../../asn1/s1ap/s1ap.cnf"
message_type = SUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_s1ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_s1ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 119 "../../asn1/s1ap/s1ap.cnf"
message_type = UNSUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_s1ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_s1ap_S1AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1AP_PDU, S1AP_PDU_choice,
NULL);
return offset;
}
static int
dissect_s1ap_SONtransferApplicationIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 6, NULL);
return offset;
}
static int
dissect_s1ap_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_IRAT_Cell_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_IRAT_Cell_ID, IRAT_Cell_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_RequestedCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_RequestedCellList, RequestedCellList_sequence_of,
1, maxnoofIRATReportingCells, FALSE);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingRequest, MultiCellLoadReportingRequest_sequence);
return offset;
}
static int
dissect_s1ap_NumberOfMeasurementReportingLevels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_EventTriggeredCellLoadReportingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EventTriggeredCellLoadReportingRequest, EventTriggeredCellLoadReportingRequest_sequence);
return offset;
}
static int
dissect_s1ap_HoType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HoReportType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_CandidateCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CandidateCellList, CandidateCellList_sequence_of,
1, maxnoofcandidateCells, FALSE);
return offset;
}
static int
dissect_s1ap_HOReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HOReport, HOReport_sequence);
return offset;
}
static int
dissect_s1ap_CellsToActivateList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellsToActivateList_Item, CellsToActivateList_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellsToActivateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellsToActivateList, CellsToActivateList_sequence_of,
1, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_INTEGER_1_60(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 60U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_CellActivationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellActivationRequest, CellActivationRequest_sequence);
return offset;
}
static int
dissect_s1ap_NotifyFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_NotificationCellList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_NotificationCellList_Item, NotificationCellList_Item_sequence);
return offset;
}
static int
dissect_s1ap_NotificationCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_NotificationCellList, NotificationCellList_sequence_of,
1, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_CellStateIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellStateIndication, CellStateIndication_sequence);
return offset;
}
static int
dissect_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN, TooEarlyInterRATHOReportReportFromEUTRAN_sequence);
return offset;
}
static int
dissect_s1ap_FailureEventReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_FailureEventReport, FailureEventReport_choice,
NULL);
return offset;
}
int
dissect_s1ap_SONtransferRequestContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferRequestContainer, SONtransferRequestContainer_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CompositeAvailableCapacityGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_EUTRANcellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRANcellLoadReportingResponse, EUTRANcellLoadReportingResponse_sequence);
return offset;
}
static int
dissect_s1ap_CellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellLoadReportingResponse, CellLoadReportingResponse_choice,
NULL);
return offset;
}
static int
dissect_s1ap_EUTRANResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRANResponse, EUTRANResponse_sequence);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingResponse_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingResponse_Item, MultiCellLoadReportingResponse_Item_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingResponse, MultiCellLoadReportingResponse_sequence_of,
1, maxnoofIRATReportingCells, FALSE);
return offset;
}
static int
dissect_s1ap_OverloadFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_EventTriggeredCellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EventTriggeredCellLoadReportingResponse, EventTriggeredCellLoadReportingResponse_sequence);
return offset;
}
static int
dissect_s1ap_ActivatedCellsList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ActivatedCellsList_Item, ActivatedCellsList_Item_sequence);
return offset;
}
static int
dissect_s1ap_ActivatedCellsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ActivatedCellsList, ActivatedCellsList_sequence_of,
0, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_CellActivationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellActivationResponse, CellActivationResponse_sequence);
return offset;
}
int
dissect_s1ap_SONtransferResponseContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferResponseContainer, SONtransferResponseContainer_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellLoadReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HOReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellActivationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellStateIndicationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_FailureEventReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SONtransferCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferCause, SONtransferCause_choice,
NULL);
return offset;
}
static int dissect_Bearers_SubjectToStatusTransfer_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_s1ap_Bearers_SubjectToStatusTransfer_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BroadcastCancelledAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_BroadcastCancelledAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCancelledAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BroadcastCompletedAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_BroadcastCompletedAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCompletedAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellAccessMode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CellAccessMode(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellAccessMode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000RATType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000RATType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000RATType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000SectorID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000SectorID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000SectorID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000HOStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000HOStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HOStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000HORequiredIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000HORequiredIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HORequiredIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000OneXSRVCCInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000OneXSRVCCInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXSRVCCInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000OneXRAND_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000OneXRAND(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXRAND_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CNDomain_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CNDomain(tvb, offset, &asn1_ctx, tree, hf_s1ap_CNDomain_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ConcurrentWarningMessageIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ConcurrentWarningMessageIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConcurrentWarningMessageIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Correlation_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Correlation_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSFallbackIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSFallbackIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSFallbackIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_IdList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSG_IdList(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_IdList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_COUNTValueExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_COUNTValueExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_COUNTValueExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_s1ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DataCodingScheme_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DataCodingScheme(tvb, offset, &asn1_ctx, tree, hf_s1ap_DataCodingScheme_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Direct_Forwarding_Path_Availability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Direct_Forwarding_Path_Availability(tvb, offset, &asn1_ctx, tree, hf_s1ap_Direct_Forwarding_Path_Availability_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Data_Forwarding_Not_Possible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Data_Forwarding_Not_Possible(tvb, offset, &asn1_ctx, tree, hf_s1ap_Data_Forwarding_Not_Possible_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_Global_ENB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Global_ENB_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_Global_ENB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEIList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIList_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_ENB_StatusTransfer_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_UE_S1AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENB_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENB_UE_S1AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBname(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABInformationListItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABInformationListItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABInformationListItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EUTRAN_CGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_EUTRAN_CGI(tvb, offset, &asn1_ctx, tree, hf_s1ap_EUTRAN_CGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EUTRANRoundTripDelayEstimationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_EUTRANRoundTripDelayEstimationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExtendedRepetitionPeriod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ExtendedRepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExtendedRepetitionPeriod_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEI(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEIType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEIType(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GWContextReleaseIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GWContextReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_GWContextReleaseIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRestrictionList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRestrictionList(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRestrictionList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverType(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_LAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LPPa_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LPPa_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_LPPa_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M3Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M3Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M4Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M4Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M4Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M5Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M5Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M5Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Location_Info_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDT_Location_Info(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Location_Info_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ManagementBasedMDTAllowed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ManagementBasedMDTAllowed(tvb, offset, &asn1_ctx, tree, hf_s1ap_ManagementBasedMDTAllowed_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDTPLMNList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDTPLMNList(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDTPLMNList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivacyIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PrivacyIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivacyIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MessageIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MessageIdentifier(tvb, offset, &asn1_ctx, tree, hf_s1ap_MessageIdentifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MobilityInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_MobilityInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEname(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMERelaySupportIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMERelaySupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMERelaySupportIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MME_UE_S1AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MME_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_MME_UE_S1AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MSClassmark2_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MSClassmark2(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark2_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MSClassmark3_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MSClassmark3(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark3_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NAS_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NAS_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_NAS_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASSecurityParametersfromE_UTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParametersfromE_UTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASSecurityParameterstoE_UTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParameterstoE_UTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NumberofBroadcastRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NumberofBroadcastRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_NumberofBroadcastRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingDRX_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingDRX_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingPriority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PagingPriority(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingPriority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PS_ServiceNotAvailable_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PS_ServiceNotAvailable(tvb, offset, &asn1_ctx, tree, hf_s1ap_PS_ServiceNotAvailable_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_ReceiveStatusOfULPDCPSDUsExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelativeMMECapacity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RelativeMMECapacity(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelativeMMECapacity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelayNode_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RelayNode_Indicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelayNode_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RequestType(tvb, offset, &asn1_ctx, tree, hf_s1ap_RequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RepetitionPeriod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_RepetitionPeriod_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRC_Establishment_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RRC_Establishment_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_RRC_Establishment_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Routing_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Routing_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Routing_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SecurityKey(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityKey_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityContext_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SecurityContext(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityContext_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SerialNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SerialNumber(tvb, offset, &asn1_ctx, tree, hf_s1ap_SerialNumber_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SONConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_SONConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Source_ToTarget_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Source_ToTarget_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Source_ToTarget_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCOperationPossible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SRVCCOperationPossible(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCOperationPossible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCHOIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SRVCCHOIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCHOIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SourceeNB_ToTargeteNB_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedGUMMEIs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ServedGUMMEIs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedGUMMEIs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedPLMNs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ServedPLMNs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedPLMNs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SubscriberProfileIDforRFP_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SubscriberProfileIDforRFP(tvb, offset, &asn1_ctx, tree, hf_s1ap_SubscriberProfileIDforRFP_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SupportedTAs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SupportedTAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_SupportedTAs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeSynchronizationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TimeSynchronizationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeSynchronizationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S_TMSI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S_TMSI(tvb, offset, &asn1_ctx, tree, hf_s1ap_S_TMSI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargetID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TargetID(tvb, offset, &asn1_ctx, tree, hf_s1ap_TargetID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargeteNB_ToSourceeNB_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Target_ToSource_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Target_ToSource_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Target_ToSource_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvb, offset, &asn1_ctx, tree, hf_s1ap_Time_UE_StayedInCell_EnhancedGranularity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportLayerAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TransportLayerAddress(tvb, offset, &asn1_ctx, tree, hf_s1ap_TransportLayerAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceActivation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceActivation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceActivation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TrafficLoadReductionIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TrafficLoadReductionIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TrafficLoadReductionIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TunnelInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TunnelInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TunnelInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEAggregateMaximumBitrate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEAggregateMaximumBitrate(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEAggregateMaximumBitrate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_S1AP_IDs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_S1AP_IDs(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_S1AP_IDs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEIdentityIndexValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEIdentityIndexValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEPagingID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEPagingID(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEPagingID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapability(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapability_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UESecurityCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UESecurityCapabilities(tvb, offset, &asn1_ctx, tree, hf_s1ap_UESecurityCapabilities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_VoiceSupportMatchIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_VoiceSupportMatchIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_VoiceSupportMatchIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningType(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningSecurityInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningSecurityInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningSecurityInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningMessageContents_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningMessageContents(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningMessageContents_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2TNLConfigurationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_X2TNLConfigurationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_X2TNLConfigurationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBX2ExtTLAs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBX2ExtTLAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBX2ExtTLAs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequired_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequired(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequired_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSubjecttoDataForwardingList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSubjecttoDataForwardingList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSubjecttoDataForwardingList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABDataForwardingItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABDataForwardingItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABDataForwardingItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverPreparationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverPreparationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListHOReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListHOReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemHOReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemHOReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABAdmittedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABAdmittedList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABAdmittedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABAdmittedItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedtoSetupListHOReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedtoSetupListHOReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToSetupItemHOReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToSetupItemHOReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverNotify_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverNotify(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverNotify_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedDLList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedDLList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedDLItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedDLItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedULList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedULList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedULItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedULItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequestFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequestFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCancel(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancel_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancelAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCancelAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancelAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListBearerSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListBearerSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemBearerSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemBearerSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupListBearerSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupListBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListBearerSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupItemBearerSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupItemBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemBearerSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedListBearerModReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedListBearerModReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedItemBearerModReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedItemBearerModReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyListBearerModRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyListBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyListBearerModRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyItemBearerModRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyItemBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyItemBearerModRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseListBearerRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseListBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseListBearerRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseItemBearerRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseItemBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseItemBearerRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListCtxtSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListCtxtSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemCtxtSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemCtxtSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupListCtxtSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupListCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListCtxtSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupItemCtxtSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupItemCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemCtxtSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Paging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Paging(tvb, offset, &asn1_ctx, tree, hf_s1ap_Paging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAIList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAIItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAIItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseComplete(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapabilityMatchRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapabilityMatchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapabilityMatchResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapabilityMatchResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkNASTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNASTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialUEMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialUEMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialUEMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkNASTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNASTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASNonDeliveryIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASNonDeliveryIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASNonDeliveryIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Reset(tvb, offset, &asn1_ctx, tree, hf_s1ap_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ResetType(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionListResAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkS1cdma2000tunneling_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkS1cdma2000tunneling(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkS1cdma2000tunneling_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkS1cdma2000tunneling_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkS1cdma2000tunneling(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkS1cdma2000tunneling_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UECapabilityInfoIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UECapabilityInfoIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_UECapabilityInfoIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceStart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceStart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DeactivateTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DeactivateTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_DeactivateTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellTrafficTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CellTrafficTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellTrafficTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReportingControl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReportingControl(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingControl_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReportingFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReportingFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadStart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadStop_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadStop(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStop_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WriteReplaceWarningRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WriteReplaceWarningRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WriteReplaceWarningResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WriteReplaceWarningResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBDirectInformationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBDirectInformationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Inter_SystemInformationTransferType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Inter_SystemInformationTransferType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Inter_SystemInformationTransferType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEDirectInformationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEDirectInformationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KillRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_KillRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KillResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_KillResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNonUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNonUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1AP_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferApplicationIdentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferApplicationIdentity(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferApplicationIdentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferRequestContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferRequestContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferRequestContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferResponseContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferResponseContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferResponseContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferCause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferCause(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferCause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(s1ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(s1ap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(s1ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(s1ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(s1ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_s1ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *s1ap_item = NULL;
proto_tree *s1ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S1AP");
s1ap_item = proto_tree_add_item(tree, proto_s1ap, tvb, 0, -1, ENC_NA);
s1ap_tree = proto_item_add_subtree(s1ap_item, ett_s1ap);
dissect_S1AP_PDU_PDU(tvb, pinfo, s1ap_tree, NULL);
}
void
proto_reg_handoff_s1ap(void)
{
static gboolean Initialized=FALSE;
static dissector_handle_t s1ap_handle;
static guint SctpPort;
s1ap_handle = find_dissector("s1ap");
if (!Initialized) {
nas_eps_handle = find_dissector("nas-eps");
lppa_handle = find_dissector("lppa");
bssgp_handle = find_dissector("bssgp");
dissector_add_handle("sctp.port", s1ap_handle);
dissector_add_uint("sctp.ppi", S1AP_PAYLOAD_PROTOCOL_ID, s1ap_handle);
Initialized=TRUE;
#line 1 "../../asn1/s1ap/packet-s1ap-dis-tab.c"
dissector_add_uint("s1ap.ies", id_MME_UE_S1AP_ID, new_create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_HandoverType, new_create_dissector_handle(dissect_HandoverType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TargetID, new_create_dissector_handle(dissect_TargetID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNB_UE_S1AP_ID, new_create_dissector_handle(dissect_ENB_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSubjecttoDataForwardingList, new_create_dissector_handle(dissect_E_RABSubjecttoDataForwardingList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABtoReleaseListHOCmd, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABDataForwardingItem, new_create_dissector_handle(dissect_E_RABDataForwardingItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleaseItemBearerRelComp, new_create_dissector_handle(dissect_E_RABReleaseItemBearerRelComp_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListBearerSUReq, new_create_dissector_handle(dissect_E_RABToBeSetupListBearerSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemBearerSUReq, new_create_dissector_handle(dissect_E_RABToBeSetupItemBearerSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABAdmittedList, new_create_dissector_handle(dissect_E_RABAdmittedList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListHOReqAck, new_create_dissector_handle(dissect_E_RABFailedtoSetupListHOReqAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABAdmittedItem, new_create_dissector_handle(dissect_E_RABAdmittedItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedtoSetupItemHOReqAck, new_create_dissector_handle(dissect_E_RABFailedToSetupItemHOReqAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedDLList, new_create_dissector_handle(dissect_E_RABToBeSwitchedDLList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedDLItem, new_create_dissector_handle(dissect_E_RABToBeSwitchedDLItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListCtxtSUReq, new_create_dissector_handle(dissect_E_RABToBeSetupListCtxtSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TraceActivation, new_create_dissector_handle(dissect_TraceActivation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NAS_PDU, new_create_dissector_handle(dissect_NAS_PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemHOReq, new_create_dissector_handle(dissect_E_RABToBeSetupItemHOReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupListBearerSURes, new_create_dissector_handle(dissect_E_RABSetupListBearerSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListBearerSURes, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedListBearerModReq, new_create_dissector_handle(dissect_E_RABToBeModifiedListBearerModReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyListBearerModRes, new_create_dissector_handle(dissect_E_RABModifyListBearerModRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToModifyList, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeReleasedList, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToReleaseList, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABItem, new_create_dissector_handle(dissect_E_RABItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedItemBearerModReq, new_create_dissector_handle(dissect_E_RABToBeModifiedItemBearerModReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyItemBearerModRes, new_create_dissector_handle(dissect_E_RABModifyItemBearerModRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupItemBearerSURes, new_create_dissector_handle(dissect_E_RABSetupItemBearerSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SecurityContext, new_create_dissector_handle(dissect_SecurityContext_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_HandoverRestrictionList, new_create_dissector_handle(dissect_HandoverRestrictionList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UEPagingID, new_create_dissector_handle(dissect_UEPagingID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_pagingDRX, new_create_dissector_handle(dissect_PagingDRX_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAIList, new_create_dissector_handle(dissect_TAIList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAIItem, new_create_dissector_handle(dissect_TAIItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListCtxtSURes, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupItemCtxtSURes, new_create_dissector_handle(dissect_E_RABSetupItemCtxtSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupListCtxtSURes, new_create_dissector_handle(dissect_E_RABSetupListCtxtSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemCtxtSUReq, new_create_dissector_handle(dissect_E_RABToBeSetupItemCtxtSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListHOReq, new_create_dissector_handle(dissect_E_RABToBeSetupListHOReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CriticalityDiagnostics, new_create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Global_ENB_ID, new_create_dissector_handle(dissect_s1ap_Global_ENB_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNBname, new_create_dissector_handle(dissect_ENBname_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MMEname, new_create_dissector_handle(dissect_MMEname_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ServedPLMNs, new_create_dissector_handle(dissect_ServedPLMNs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SupportedTAs, new_create_dissector_handle(dissect_SupportedTAs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TimeToWait, new_create_dissector_handle(dissect_TimeToWait_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_uEaggregateMaximumBitrate, new_create_dissector_handle(dissect_UEAggregateMaximumBitrate_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAI, new_create_dissector_handle(dissect_TAI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleaseListBearerRelComp, new_create_dissector_handle(dissect_E_RABReleaseListBearerRelComp_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000PDU, new_create_dissector_handle(dissect_Cdma2000PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000RATType, new_create_dissector_handle(dissect_Cdma2000RATType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000SectorID, new_create_dissector_handle(dissect_Cdma2000SectorID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SecurityKey, new_create_dissector_handle(dissect_SecurityKey_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UERadioCapability, new_create_dissector_handle(dissect_UERadioCapability_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEI_ID, new_create_dissector_handle(dissect_GUMMEI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABInformationListItem, new_create_dissector_handle(dissect_E_RABInformationListItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Direct_Forwarding_Path_Availability, new_create_dissector_handle(dissect_Direct_Forwarding_Path_Availability_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UEIdentityIndexValue, new_create_dissector_handle(dissect_UEIdentityIndexValue_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000HOStatus, new_create_dissector_handle(dissect_Cdma2000HOStatus_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000HORequiredIndication, new_create_dissector_handle(dissect_Cdma2000HORequiredIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RelativeMMECapacity, new_create_dissector_handle(dissect_RelativeMMECapacity_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SourceMME_UE_S1AP_ID, new_create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Bearers_SubjectToStatusTransfer_Item, new_create_dissector_handle(dissect_Bearers_SubjectToStatusTransfer_Item_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNB_StatusTransfer_TransparentContainer, new_create_dissector_handle(dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_associatedLogicalS1_ConnectionItem, new_create_dissector_handle(dissect_UE_associatedLogicalS1_ConnectionItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ResetType, new_create_dissector_handle(dissect_ResetType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_associatedLogicalS1_ConnectionListResAck, new_create_dissector_handle(dissect_UE_associatedLogicalS1_ConnectionListResAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedULItem, new_create_dissector_handle(dissect_E_RABToBeSwitchedULItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedULList, new_create_dissector_handle(dissect_E_RABToBeSwitchedULList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_S_TMSI, new_create_dissector_handle(dissect_S_TMSI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000OneXRAND, new_create_dissector_handle(dissect_Cdma2000OneXRAND_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RequestType, new_create_dissector_handle(dissect_RequestType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_S1AP_IDs, new_create_dissector_handle(dissect_UE_S1AP_IDs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_EUTRAN_CGI, new_create_dissector_handle(dissect_EUTRAN_CGI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_OverloadResponse, new_create_dissector_handle(dissect_OverloadResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000OneXSRVCCInfo, new_create_dissector_handle(dissect_Cdma2000OneXSRVCCInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Source_ToTarget_TransparentContainer, new_create_dissector_handle(dissect_Source_ToTarget_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ServedGUMMEIs, new_create_dissector_handle(dissect_ServedGUMMEIs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SubscriberProfileIDforRFP, new_create_dissector_handle(dissect_SubscriberProfileIDforRFP_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UESecurityCapabilities, new_create_dissector_handle(dissect_UESecurityCapabilities_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSFallbackIndicator, new_create_dissector_handle(dissect_CSFallbackIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CNDomain, new_create_dissector_handle(dissect_CNDomain_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleasedList, new_create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MessageIdentifier, new_create_dissector_handle(dissect_MessageIdentifier_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SerialNumber, new_create_dissector_handle(dissect_SerialNumber_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningAreaList, new_create_dissector_handle(dissect_WarningAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RepetitionPeriod, new_create_dissector_handle(dissect_RepetitionPeriod_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NumberofBroadcastRequest, new_create_dissector_handle(dissect_NumberofBroadcastRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningType, new_create_dissector_handle(dissect_WarningType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningSecurityInfo, new_create_dissector_handle(dissect_WarningSecurityInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_DataCodingScheme, new_create_dissector_handle(dissect_DataCodingScheme_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningMessageContents, new_create_dissector_handle(dissect_WarningMessageContents_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_BroadcastCompletedAreaList, new_create_dissector_handle(dissect_BroadcastCompletedAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Inter_SystemInformationTransferTypeEDT, new_create_dissector_handle(dissect_Inter_SystemInformationTransferType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Inter_SystemInformationTransferTypeMDT, new_create_dissector_handle(dissect_Inter_SystemInformationTransferType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Target_ToSource_TransparentContainer, new_create_dissector_handle(dissect_Target_ToSource_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SRVCCOperationPossible, new_create_dissector_handle(dissect_SRVCCOperationPossible_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SRVCCHOIndication, new_create_dissector_handle(dissect_SRVCCHOIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSG_Id, new_create_dissector_handle(dissect_CSG_Id_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSG_IdList, new_create_dissector_handle(dissect_CSG_IdList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SONConfigurationTransferECT, new_create_dissector_handle(dissect_SONConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SONConfigurationTransferMCT, new_create_dissector_handle(dissect_SONConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TraceCollectionEntityIPAddress, new_create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MSClassmark2, new_create_dissector_handle(dissect_MSClassmark2_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MSClassmark3, new_create_dissector_handle(dissect_MSClassmark3_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RRC_Establishment_Cause, new_create_dissector_handle(dissect_RRC_Establishment_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NASSecurityParametersfromE_UTRAN, new_create_dissector_handle(dissect_NASSecurityParametersfromE_UTRAN_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NASSecurityParameterstoE_UTRAN, new_create_dissector_handle(dissect_NASSecurityParameterstoE_UTRAN_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_DefaultPagingDRX, new_create_dissector_handle(dissect_PagingDRX_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Source_ToTarget_TransparentContainer_Secondary, new_create_dissector_handle(dissect_Source_ToTarget_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Target_ToSource_TransparentContainer_Secondary, new_create_dissector_handle(dissect_Target_ToSource_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_EUTRANRoundTripDelayEstimationInfo, new_create_dissector_handle(dissect_EUTRANRoundTripDelayEstimationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_BroadcastCancelledAreaList, new_create_dissector_handle(dissect_BroadcastCancelledAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ConcurrentWarningMessageIndicator, new_create_dissector_handle(dissect_ConcurrentWarningMessageIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ExtendedRepetitionPeriod, new_create_dissector_handle(dissect_ExtendedRepetitionPeriod_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CellAccessMode, new_create_dissector_handle(dissect_CellAccessMode_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSGMembershipStatus, new_create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_LPPa_PDU, new_create_dissector_handle(dissect_LPPa_PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Routing_ID, new_create_dissector_handle(dissect_Routing_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PS_ServiceNotAvailable, new_create_dissector_handle(dissect_PS_ServiceNotAvailable_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PagingPriority, new_create_dissector_handle(dissect_PagingPriority_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEIList, new_create_dissector_handle(dissect_GUMMEIList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GW_TransportLayerAddress, new_create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SourceMME_GUMMEI, new_create_dissector_handle(dissect_GUMMEI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MME_UE_S1AP_ID_2, new_create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RegisteredLAI, new_create_dissector_handle(dissect_LAI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RelayNode_Indicator, new_create_dissector_handle(dissect_RelayNode_Indicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TrafficLoadReductionIndication, new_create_dissector_handle(dissect_TrafficLoadReductionIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MMERelaySupportIndicator, new_create_dissector_handle(dissect_MMERelaySupportIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GWContextReleaseIndication, new_create_dissector_handle(dissect_GWContextReleaseIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ManagementBasedMDTAllowed, new_create_dissector_handle(dissect_ManagementBasedMDTAllowed_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PrivacyIndicator, new_create_dissector_handle(dissect_PrivacyIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_VoiceSupportMatchIndicator, new_create_dissector_handle(dissect_VoiceSupportMatchIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEIType, new_create_dissector_handle(dissect_GUMMEIType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Tunnel_Information_for_BBF, new_create_dissector_handle(dissect_TunnelInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ManagementBasedMDTPLMNList, new_create_dissector_handle(dissect_MDTPLMNList_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Data_Forwarding_Not_Possible, new_create_dissector_handle(dissect_Data_Forwarding_Not_Possible_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Time_Synchronization_Info, new_create_dissector_handle(dissect_TimeSynchronizationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_x2TNLConfigurationInfo, new_create_dissector_handle(dissect_X2TNLConfigurationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_eNBX2ExtendedTransportLayerAddresses, new_create_dissector_handle(dissect_ENBX2ExtTLAs_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Correlation_ID, new_create_dissector_handle(dissect_Correlation_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MDTConfiguration, new_create_dissector_handle(dissect_MDT_Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Time_UE_StayedInCell_EnhancedGranularity, new_create_dissector_handle(dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_HO_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M3Configuration, new_create_dissector_handle(dissect_M3Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M4Configuration, new_create_dissector_handle(dissect_M4Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M5Configuration, new_create_dissector_handle(dissect_M5Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MDT_Location_Info, new_create_dissector_handle(dissect_MDT_Location_Info_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MobilityInformation, new_create_dissector_handle(dissect_MobilityInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_SignallingBasedMDTPLMNList, new_create_dissector_handle(dissect_MDTPLMNList_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ULCOUNTValueExtended, new_create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_DLCOUNTValueExtended, new_create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ReceiveStatusOfULPDCPSDUsExtended, new_create_dissector_handle(dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverPreparation, new_create_dissector_handle(dissect_HandoverRequired_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverPreparation, new_create_dissector_handle(dissect_HandoverCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_HandoverPreparation, new_create_dissector_handle(dissect_HandoverPreparationFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverResourceAllocation, new_create_dissector_handle(dissect_HandoverRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverResourceAllocation, new_create_dissector_handle(dissect_HandoverRequestAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_HandoverResourceAllocation, new_create_dissector_handle(dissect_HandoverFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverNotification, new_create_dissector_handle(dissect_HandoverNotify_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PathSwitchRequest, new_create_dissector_handle(dissect_PathSwitchRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_PathSwitchRequest, new_create_dissector_handle(dissect_PathSwitchRequestAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_PathSwitchRequest, new_create_dissector_handle(dissect_PathSwitchRequestFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABSetup, new_create_dissector_handle(dissect_E_RABSetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABSetup, new_create_dissector_handle(dissect_E_RABSetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABModify, new_create_dissector_handle(dissect_E_RABModifyRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABModify, new_create_dissector_handle(dissect_E_RABModifyResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABRelease, new_create_dissector_handle(dissect_E_RABReleaseCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABRelease, new_create_dissector_handle(dissect_E_RABReleaseResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABReleaseIndication, new_create_dissector_handle(dissect_E_RABReleaseIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_InitialContextSetup, new_create_dissector_handle(dissect_InitialContextSetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_InitialContextSetup, new_create_dissector_handle(dissect_InitialContextSetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_InitialContextSetup, new_create_dissector_handle(dissect_InitialContextSetupFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextReleaseRequest, new_create_dissector_handle(dissect_UEContextReleaseRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Paging, new_create_dissector_handle(dissect_Paging_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkNASTransport, new_create_dissector_handle(dissect_DownlinkNASTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_initialUEMessage, new_create_dissector_handle(dissect_InitialUEMessage_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkNASTransport, new_create_dissector_handle(dissect_UplinkNASTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_NASNonDeliveryIndication, new_create_dissector_handle(dissect_NASNonDeliveryIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverCancel, new_create_dissector_handle(dissect_HandoverCancel_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverCancel, new_create_dissector_handle(dissect_HandoverCancelAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Reset, new_create_dissector_handle(dissect_Reset_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_Reset, new_create_dissector_handle(dissect_ResetAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_ErrorIndication, new_create_dissector_handle(dissect_ErrorIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_S1Setup, new_create_dissector_handle(dissect_S1SetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_S1Setup, new_create_dissector_handle(dissect_S1SetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_S1Setup, new_create_dissector_handle(dissect_S1SetupFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_DownlinkS1cdma2000tunneling, new_create_dissector_handle(dissect_DownlinkS1cdma2000tunneling_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_ENBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdate_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_ENBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdateAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_ENBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdateFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEConfigurationUpdate, new_create_dissector_handle(dissect_MMEConfigurationUpdate_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_MMEConfigurationUpdate, new_create_dissector_handle(dissect_MMEConfigurationUpdateAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_MMEConfigurationUpdate, new_create_dissector_handle(dissect_MMEConfigurationUpdateFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UplinkS1cdma2000tunneling, new_create_dissector_handle(dissect_UplinkS1cdma2000tunneling_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextModification, new_create_dissector_handle(dissect_UEContextModificationRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextModification, new_create_dissector_handle(dissect_UEContextModificationResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_UEContextModification, new_create_dissector_handle(dissect_UEContextModificationFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UECapabilityInfoIndication, new_create_dissector_handle(dissect_UECapabilityInfoIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextRelease, new_create_dissector_handle(dissect_UEContextReleaseCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextRelease, new_create_dissector_handle(dissect_UEContextReleaseComplete_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBStatusTransfer, new_create_dissector_handle(dissect_ENBStatusTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEStatusTransfer, new_create_dissector_handle(dissect_MMEStatusTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_DeactivateTrace, new_create_dissector_handle(dissect_DeactivateTrace_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_TraceStart, new_create_dissector_handle(dissect_TraceStart_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_TraceFailureIndication, new_create_dissector_handle(dissect_TraceFailureIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReportingControl, new_create_dissector_handle(dissect_LocationReportingControl_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReportingFailureIndication, new_create_dissector_handle(dissect_LocationReportingFailureIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReport, new_create_dissector_handle(dissect_LocationReport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_OverloadStart, new_create_dissector_handle(dissect_OverloadStart_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_OverloadStop, new_create_dissector_handle(dissect_OverloadStop_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_WriteReplaceWarning, new_create_dissector_handle(dissect_WriteReplaceWarningRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_WriteReplaceWarning, new_create_dissector_handle(dissect_WriteReplaceWarningResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBDirectInformationTransfer, new_create_dissector_handle(dissect_ENBDirectInformationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEDirectInformationTransfer, new_create_dissector_handle(dissect_MMEDirectInformationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PrivateMessage, new_create_dissector_handle(dissect_PrivateMessage_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBConfigurationTransfer, new_create_dissector_handle(dissect_ENBConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEConfigurationTransfer, new_create_dissector_handle(dissect_MMEConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_CellTrafficTrace, new_create_dissector_handle(dissect_CellTrafficTrace_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Kill, new_create_dissector_handle(dissect_KillRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_Kill, new_create_dissector_handle(dissect_KillResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkUEAssociatedLPPaTransport, new_create_dissector_handle(dissect_DownlinkUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkUEAssociatedLPPaTransport, new_create_dissector_handle(dissect_UplinkUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkNonUEAssociatedLPPaTransport, new_create_dissector_handle(dissect_DownlinkNonUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkNonUEAssociatedLPPaTransport, new_create_dissector_handle(dissect_UplinkNonUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UERadioCapabilityMatch, new_create_dissector_handle(dissect_UERadioCapabilityMatchRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UERadioCapabilityMatch, new_create_dissector_handle(dissect_UERadioCapabilityMatchResponse_PDU, proto_s1ap));
#line 203 "../../asn1/s1ap/packet-s1ap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, s1ap_handle);
}
}
SctpPort=gbl_s1apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, s1ap_handle);
}
}
void proto_register_s1ap(void) {
static hf_register_info hf[] = {
{ &hf_s1ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "s1ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "s1ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "../../asn1/s1ap/packet-s1ap-hfarr.c"
{ &hf_s1ap_Bearers_SubjectToStatusTransfer_Item_PDU,
{ "Bearers-SubjectToStatusTransfer-Item", "s1ap.Bearers_SubjectToStatusTransfer_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_BroadcastCancelledAreaList_PDU,
{ "BroadcastCancelledAreaList", "s1ap.BroadcastCancelledAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_BroadcastCancelledAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_BroadcastCompletedAreaList_PDU,
{ "BroadcastCompletedAreaList", "s1ap.BroadcastCompletedAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_BroadcastCompletedAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cause_PDU,
{ "Cause", "s1ap.Cause",
FT_UINT32, BASE_DEC, VALS(s1ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CellAccessMode_PDU,
{ "CellAccessMode", "s1ap.CellAccessMode",
FT_UINT32, BASE_DEC, VALS(s1ap_CellAccessMode_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000PDU_PDU,
{ "Cdma2000PDU", "s1ap.Cdma2000PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000RATType_PDU,
{ "Cdma2000RATType", "s1ap.Cdma2000RATType",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000RATType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000SectorID_PDU,
{ "Cdma2000SectorID", "s1ap.Cdma2000SectorID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000HOStatus_PDU,
{ "Cdma2000HOStatus", "s1ap.Cdma2000HOStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000HOStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000HORequiredIndication_PDU,
{ "Cdma2000HORequiredIndication", "s1ap.Cdma2000HORequiredIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000HORequiredIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000OneXSRVCCInfo_PDU,
{ "Cdma2000OneXSRVCCInfo", "s1ap.Cdma2000OneXSRVCCInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000OneXRAND_PDU,
{ "Cdma2000OneXRAND", "s1ap.Cdma2000OneXRAND",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CNDomain_PDU,
{ "CNDomain", "s1ap.CNDomain",
FT_UINT32, BASE_DEC, VALS(s1ap_CNDomain_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ConcurrentWarningMessageIndicator_PDU,
{ "ConcurrentWarningMessageIndicator", "s1ap.ConcurrentWarningMessageIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_ConcurrentWarningMessageIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Correlation_ID_PDU,
{ "Correlation-ID", "s1ap.Correlation_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSFallbackIndicator_PDU,
{ "CSFallbackIndicator", "s1ap.CSFallbackIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_CSFallbackIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_Id_PDU,
{ "CSG-Id", "s1ap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_IdList_PDU,
{ "CSG-IdList", "s1ap.CSG_IdList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "s1ap.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_COUNTValueExtended_PDU,
{ "COUNTValueExtended", "s1ap.COUNTValueExtended_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "s1ap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DataCodingScheme_PDU,
{ "DataCodingScheme", "s1ap.DataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Direct_Forwarding_Path_Availability_PDU,
{ "Direct-Forwarding-Path-Availability", "s1ap.Direct_Forwarding_Path_Availability",
FT_UINT32, BASE_DEC, VALS(s1ap_Direct_Forwarding_Path_Availability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Data_Forwarding_Not_Possible_PDU,
{ "Data-Forwarding-Not-Possible", "s1ap.Data_Forwarding_Not_Possible",
FT_UINT32, BASE_DEC, VALS(s1ap_Data_Forwarding_Not_Possible_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_Global_ENB_ID_PDU,
{ "Global-ENB-ID", "s1ap.Global_ENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIList_PDU,
{ "GUMMEIList", "s1ap.GUMMEIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_ENB_StatusTransfer_TransparentContainer_PDU,
{ "ENB-StatusTransfer-TransparentContainer", "s1ap.ENB_StatusTransfer_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENB_UE_S1AP_ID_PDU,
{ "ENB-UE-S1AP-ID", "s1ap.ENB_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBname_PDU,
{ "ENBname", "s1ap.ENBname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABInformationListItem_PDU,
{ "E-RABInformationListItem", "s1ap.E_RABInformationListItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABList_PDU,
{ "E-RABList", "s1ap.E_RABList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABItem_PDU,
{ "E-RABItem", "s1ap.E_RABItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EUTRAN_CGI_PDU,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EUTRANRoundTripDelayEstimationInfo_PDU,
{ "EUTRANRoundTripDelayEstimationInfo", "s1ap.EUTRANRoundTripDelayEstimationInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ExtendedRepetitionPeriod_PDU,
{ "ExtendedRepetitionPeriod", "s1ap.ExtendedRepetitionPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEI_PDU,
{ "GUMMEI", "s1ap.GUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIType_PDU,
{ "GUMMEIType", "s1ap.GUMMEIType",
FT_UINT32, BASE_DEC, VALS(s1ap_GUMMEIType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_GWContextReleaseIndication_PDU,
{ "GWContextReleaseIndication", "s1ap.GWContextReleaseIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_GWContextReleaseIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRestrictionList_PDU,
{ "HandoverRestrictionList", "s1ap.HandoverRestrictionList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverType_PDU,
{ "HandoverType", "s1ap.HandoverType",
FT_UINT32, BASE_DEC, VALS(s1ap_HandoverType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_LAI_PDU,
{ "LAI", "s1ap.LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LPPa_PDU_PDU,
{ "LPPa-PDU", "s1ap.LPPa_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M3Configuration_PDU,
{ "M3Configuration", "s1ap.M3Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M4Configuration_PDU,
{ "M4Configuration", "s1ap.M4Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M5Configuration_PDU,
{ "M5Configuration", "s1ap.M5Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_PDU,
{ "MDT-Location-Info", "s1ap.MDT_Location_Info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MDT_Configuration_PDU,
{ "MDT-Configuration", "s1ap.MDT_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ManagementBasedMDTAllowed_PDU,
{ "ManagementBasedMDTAllowed", "s1ap.ManagementBasedMDTAllowed",
FT_UINT32, BASE_DEC, VALS(s1ap_ManagementBasedMDTAllowed_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MDTPLMNList_PDU,
{ "MDTPLMNList", "s1ap.MDTPLMNList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivacyIndicator_PDU,
{ "PrivacyIndicator", "s1ap.PrivacyIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_PrivacyIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MessageIdentifier_PDU,
{ "MessageIdentifier", "s1ap.MessageIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MobilityInformation_PDU,
{ "MobilityInformation", "s1ap.MobilityInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEname_PDU,
{ "MMEname", "s1ap.MMEname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMERelaySupportIndicator_PDU,
{ "MMERelaySupportIndicator", "s1ap.MMERelaySupportIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_MMERelaySupportIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MME_UE_S1AP_ID_PDU,
{ "MME-UE-S1AP-ID", "s1ap.MME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MSClassmark2_PDU,
{ "MSClassmark2", "s1ap.MSClassmark2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MSClassmark3_PDU,
{ "MSClassmark3", "s1ap.MSClassmark3",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NAS_PDU_PDU,
{ "NAS-PDU", "s1ap.NAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASSecurityParametersfromE_UTRAN_PDU,
{ "NASSecurityParametersfromE-UTRAN", "s1ap.NASSecurityParametersfromE_UTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASSecurityParameterstoE_UTRAN_PDU,
{ "NASSecurityParameterstoE-UTRAN", "s1ap.NASSecurityParameterstoE_UTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NumberofBroadcastRequest_PDU,
{ "NumberofBroadcastRequest", "s1ap.NumberofBroadcastRequest",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadResponse_PDU,
{ "OverloadResponse", "s1ap.OverloadResponse",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadResponse_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PagingDRX_PDU,
{ "PagingDRX", "s1ap.PagingDRX",
FT_UINT32, BASE_DEC, VALS(s1ap_PagingDRX_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PagingPriority_PDU,
{ "PagingPriority", "s1ap.PagingPriority",
FT_UINT32, BASE_DEC, VALS(s1ap_PagingPriority_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PS_ServiceNotAvailable_PDU,
{ "PS-ServiceNotAvailable", "s1ap.PS_ServiceNotAvailable",
FT_UINT32, BASE_DEC, VALS(s1ap_PS_ServiceNotAvailable_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ReceiveStatusOfULPDCPSDUsExtended_PDU,
{ "ReceiveStatusOfULPDCPSDUsExtended", "s1ap.ReceiveStatusOfULPDCPSDUsExtended",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RelativeMMECapacity_PDU,
{ "RelativeMMECapacity", "s1ap.RelativeMMECapacity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RelayNode_Indicator_PDU,
{ "RelayNode-Indicator", "s1ap.RelayNode_Indicator",
FT_UINT32, BASE_DEC, VALS(s1ap_RelayNode_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_RequestType_PDU,
{ "RequestType", "s1ap.RequestType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RepetitionPeriod_PDU,
{ "RepetitionPeriod", "s1ap.RepetitionPeriod",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RRC_Establishment_Cause_PDU,
{ "RRC-Establishment-Cause", "s1ap.RRC_Establishment_Cause",
FT_UINT32, BASE_DEC, VALS(s1ap_RRC_Establishment_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Routing_ID_PDU,
{ "Routing-ID", "s1ap.Routing_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SecurityKey_PDU,
{ "SecurityKey", "s1ap.SecurityKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SecurityContext_PDU,
{ "SecurityContext", "s1ap.SecurityContext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_PDU,
{ "SerialNumber", "s1ap.SerialNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SONConfigurationTransfer_PDU,
{ "SONConfigurationTransfer", "s1ap.SONConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Source_ToTarget_TransparentContainer_PDU,
{ "Source-ToTarget-TransparentContainer", "s1ap.Source_ToTarget_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SRVCCOperationPossible_PDU,
{ "SRVCCOperationPossible", "s1ap.SRVCCOperationPossible",
FT_UINT32, BASE_DEC, VALS(s1ap_SRVCCOperationPossible_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SRVCCHOIndication_PDU,
{ "SRVCCHOIndication", "s1ap.SRVCCHOIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_SRVCCHOIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU,
{ "SourceeNB-ToTargeteNB-TransparentContainer", "s1ap.SourceeNB_ToTargeteNB_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGUMMEIs_PDU,
{ "ServedGUMMEIs", "s1ap.ServedGUMMEIs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedPLMNs_PDU,
{ "ServedPLMNs", "s1ap.ServedPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SubscriberProfileIDforRFP_PDU,
{ "SubscriberProfileIDforRFP", "s1ap.SubscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SupportedTAs_PDU,
{ "SupportedTAs", "s1ap.SupportedTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TimeSynchronizationInfo_PDU,
{ "TimeSynchronizationInfo", "s1ap.TimeSynchronizationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S_TMSI_PDU,
{ "S-TMSI", "s1ap.S_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_PDU,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TargetID_PDU,
{ "TargetID", "s1ap.TargetID",
FT_UINT32, BASE_DEC, VALS(s1ap_TargetID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU,
{ "TargeteNB-ToSourceeNB-TransparentContainer", "s1ap.TargeteNB_ToSourceeNB_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Target_ToSource_TransparentContainer_PDU,
{ "Target-ToSource-TransparentContainer", "s1ap.Target_ToSource_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TimeToWait_PDU,
{ "TimeToWait", "s1ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(s1ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Time_UE_StayedInCell_EnhancedGranularity_PDU,
{ "Time-UE-StayedInCell-EnhancedGranularity", "s1ap.Time_UE_StayedInCell_EnhancedGranularity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TransportLayerAddress_PDU,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceActivation_PDU,
{ "TraceActivation", "s1ap.TraceActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TrafficLoadReductionIndication_PDU,
{ "TrafficLoadReductionIndication", "s1ap.TrafficLoadReductionIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TunnelInformation_PDU,
{ "TunnelInformation", "s1ap.TunnelInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEAggregateMaximumBitrate_PDU,
{ "UEAggregateMaximumBitrate", "s1ap.UEAggregateMaximumBitrate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_S1AP_IDs_PDU,
{ "UE-S1AP-IDs", "s1ap.UE_S1AP_IDs",
FT_UINT32, BASE_DEC, VALS(s1ap_UE_S1AP_IDs_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionItem_PDU,
{ "UE-associatedLogicalS1-ConnectionItem", "s1ap.UE_associatedLogicalS1_ConnectionItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEIdentityIndexValue_PDU,
{ "UEIdentityIndexValue", "s1ap.UEIdentityIndexValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEPagingID_PDU,
{ "UEPagingID", "s1ap.UEPagingID",
FT_UINT32, BASE_DEC, VALS(s1ap_UEPagingID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapability_PDU,
{ "UERadioCapability", "s1ap.UERadioCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UESecurityCapabilities_PDU,
{ "UESecurityCapabilities", "s1ap.UESecurityCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_VoiceSupportMatchIndicator_PDU,
{ "VoiceSupportMatchIndicator", "s1ap.VoiceSupportMatchIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_VoiceSupportMatchIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_WarningAreaList_PDU,
{ "WarningAreaList", "s1ap.WarningAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_WarningAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_WarningType_PDU,
{ "WarningType", "s1ap.WarningType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningSecurityInfo_PDU,
{ "WarningSecurityInfo", "s1ap.WarningSecurityInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_PDU,
{ "WarningMessageContents", "s1ap.WarningMessageContents",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_X2TNLConfigurationInfo_PDU,
{ "X2TNLConfigurationInfo", "s1ap.X2TNLConfigurationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBX2ExtTLAs_PDU,
{ "ENBX2ExtTLAs", "s1ap.ENBX2ExtTLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequired_PDU,
{ "HandoverRequired", "s1ap.HandoverRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCommand_PDU,
{ "HandoverCommand", "s1ap.HandoverCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSubjecttoDataForwardingList_PDU,
{ "E-RABSubjecttoDataForwardingList", "s1ap.E_RABSubjecttoDataForwardingList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABDataForwardingItem_PDU,
{ "E-RABDataForwardingItem", "s1ap.E_RABDataForwardingItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverPreparationFailure_PDU,
{ "HandoverPreparationFailure", "s1ap.HandoverPreparationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequest_PDU,
{ "HandoverRequest", "s1ap.HandoverRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListHOReq_PDU,
{ "E-RABToBeSetupListHOReq", "s1ap.E_RABToBeSetupListHOReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemHOReq_PDU,
{ "E-RABToBeSetupItemHOReq", "s1ap.E_RABToBeSetupItemHOReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequestAcknowledge_PDU,
{ "HandoverRequestAcknowledge", "s1ap.HandoverRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABAdmittedList_PDU,
{ "E-RABAdmittedList", "s1ap.E_RABAdmittedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABAdmittedItem_PDU,
{ "E-RABAdmittedItem", "s1ap.E_RABAdmittedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedtoSetupListHOReqAck_PDU,
{ "E-RABFailedtoSetupListHOReqAck", "s1ap.E_RABFailedtoSetupListHOReqAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToSetupItemHOReqAck_PDU,
{ "E-RABFailedToSetupItemHOReqAck", "s1ap.E_RABFailedToSetupItemHOReqAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverFailure_PDU,
{ "HandoverFailure", "s1ap.HandoverFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverNotify_PDU,
{ "HandoverNotify", "s1ap.HandoverNotify_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequest_PDU,
{ "PathSwitchRequest", "s1ap.PathSwitchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedDLList_PDU,
{ "E-RABToBeSwitchedDLList", "s1ap.E_RABToBeSwitchedDLList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedDLItem_PDU,
{ "E-RABToBeSwitchedDLItem", "s1ap.E_RABToBeSwitchedDLItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequestAcknowledge_PDU,
{ "PathSwitchRequestAcknowledge", "s1ap.PathSwitchRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedULList_PDU,
{ "E-RABToBeSwitchedULList", "s1ap.E_RABToBeSwitchedULList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedULItem_PDU,
{ "E-RABToBeSwitchedULItem", "s1ap.E_RABToBeSwitchedULItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequestFailure_PDU,
{ "PathSwitchRequestFailure", "s1ap.PathSwitchRequestFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCancel_PDU,
{ "HandoverCancel", "s1ap.HandoverCancel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCancelAcknowledge_PDU,
{ "HandoverCancelAcknowledge", "s1ap.HandoverCancelAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupRequest_PDU,
{ "E-RABSetupRequest", "s1ap.E_RABSetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListBearerSUReq_PDU,
{ "E-RABToBeSetupListBearerSUReq", "s1ap.E_RABToBeSetupListBearerSUReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemBearerSUReq_PDU,
{ "E-RABToBeSetupItemBearerSUReq", "s1ap.E_RABToBeSetupItemBearerSUReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupResponse_PDU,
{ "E-RABSetupResponse", "s1ap.E_RABSetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListBearerSURes_PDU,
{ "E-RABSetupListBearerSURes", "s1ap.E_RABSetupListBearerSURes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupItemBearerSURes_PDU,
{ "E-RABSetupItemBearerSURes", "s1ap.E_RABSetupItemBearerSURes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyRequest_PDU,
{ "E-RABModifyRequest", "s1ap.E_RABModifyRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedListBearerModReq_PDU,
{ "E-RABToBeModifiedListBearerModReq", "s1ap.E_RABToBeModifiedListBearerModReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedItemBearerModReq_PDU,
{ "E-RABToBeModifiedItemBearerModReq", "s1ap.E_RABToBeModifiedItemBearerModReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyResponse_PDU,
{ "E-RABModifyResponse", "s1ap.E_RABModifyResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModRes_PDU,
{ "E-RABModifyListBearerModRes", "s1ap.E_RABModifyListBearerModRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyItemBearerModRes_PDU,
{ "E-RABModifyItemBearerModRes", "s1ap.E_RABModifyItemBearerModRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseCommand_PDU,
{ "E-RABReleaseCommand", "s1ap.E_RABReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseResponse_PDU,
{ "E-RABReleaseResponse", "s1ap.E_RABReleaseResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseListBearerRelComp_PDU,
{ "E-RABReleaseListBearerRelComp", "s1ap.E_RABReleaseListBearerRelComp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseItemBearerRelComp_PDU,
{ "E-RABReleaseItemBearerRelComp", "s1ap.E_RABReleaseItemBearerRelComp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseIndication_PDU,
{ "E-RABReleaseIndication", "s1ap.E_RABReleaseIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupRequest_PDU,
{ "InitialContextSetupRequest", "s1ap.InitialContextSetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListCtxtSUReq_PDU,
{ "E-RABToBeSetupListCtxtSUReq", "s1ap.E_RABToBeSetupListCtxtSUReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemCtxtSUReq_PDU,
{ "E-RABToBeSetupItemCtxtSUReq", "s1ap.E_RABToBeSetupItemCtxtSUReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupResponse_PDU,
{ "InitialContextSetupResponse", "s1ap.InitialContextSetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListCtxtSURes_PDU,
{ "E-RABSetupListCtxtSURes", "s1ap.E_RABSetupListCtxtSURes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupItemCtxtSURes_PDU,
{ "E-RABSetupItemCtxtSURes", "s1ap.E_RABSetupItemCtxtSURes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupFailure_PDU,
{ "InitialContextSetupFailure", "s1ap.InitialContextSetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Paging_PDU,
{ "Paging", "s1ap.Paging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIList_PDU,
{ "TAIList", "s1ap.TAIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIItem_PDU,
{ "TAIItem", "s1ap.TAIItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseRequest_PDU,
{ "UEContextReleaseRequest", "s1ap.UEContextReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseCommand_PDU,
{ "UEContextReleaseCommand", "s1ap.UEContextReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseComplete_PDU,
{ "UEContextReleaseComplete", "s1ap.UEContextReleaseComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationRequest_PDU,
{ "UEContextModificationRequest", "s1ap.UEContextModificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationResponse_PDU,
{ "UEContextModificationResponse", "s1ap.UEContextModificationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationFailure_PDU,
{ "UEContextModificationFailure", "s1ap.UEContextModificationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapabilityMatchRequest_PDU,
{ "UERadioCapabilityMatchRequest", "s1ap.UERadioCapabilityMatchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapabilityMatchResponse_PDU,
{ "UERadioCapabilityMatchResponse", "s1ap.UERadioCapabilityMatchResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkNASTransport_PDU,
{ "DownlinkNASTransport", "s1ap.DownlinkNASTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialUEMessage_PDU,
{ "InitialUEMessage", "s1ap.InitialUEMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkNASTransport_PDU,
{ "UplinkNASTransport", "s1ap.UplinkNASTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASNonDeliveryIndication_PDU,
{ "NASNonDeliveryIndication", "s1ap.NASNonDeliveryIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Reset_PDU,
{ "Reset", "s1ap.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ResetType_PDU,
{ "ResetType", "s1ap.ResetType",
FT_UINT32, BASE_DEC, VALS(s1ap_ResetType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ResetAcknowledge_PDU,
{ "ResetAcknowledge", "s1ap.ResetAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_PDU,
{ "UE-associatedLogicalS1-ConnectionListResAck", "s1ap.UE_associatedLogicalS1_ConnectionListResAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ErrorIndication_PDU,
{ "ErrorIndication", "s1ap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupRequest_PDU,
{ "S1SetupRequest", "s1ap.S1SetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupResponse_PDU,
{ "S1SetupResponse", "s1ap.S1SetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupFailure_PDU,
{ "S1SetupFailure", "s1ap.S1SetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdate_PDU,
{ "ENBConfigurationUpdate", "s1ap.ENBConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdateAcknowledge_PDU,
{ "ENBConfigurationUpdateAcknowledge", "s1ap.ENBConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdateFailure_PDU,
{ "ENBConfigurationUpdateFailure", "s1ap.ENBConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdate_PDU,
{ "MMEConfigurationUpdate", "s1ap.MMEConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdateAcknowledge_PDU,
{ "MMEConfigurationUpdateAcknowledge", "s1ap.MMEConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdateFailure_PDU,
{ "MMEConfigurationUpdateFailure", "s1ap.MMEConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkS1cdma2000tunneling_PDU,
{ "DownlinkS1cdma2000tunneling", "s1ap.DownlinkS1cdma2000tunneling_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkS1cdma2000tunneling_PDU,
{ "UplinkS1cdma2000tunneling", "s1ap.UplinkS1cdma2000tunneling_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UECapabilityInfoIndication_PDU,
{ "UECapabilityInfoIndication", "s1ap.UECapabilityInfoIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBStatusTransfer_PDU,
{ "ENBStatusTransfer", "s1ap.ENBStatusTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEStatusTransfer_PDU,
{ "MMEStatusTransfer", "s1ap.MMEStatusTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceStart_PDU,
{ "TraceStart", "s1ap.TraceStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceFailureIndication_PDU,
{ "TraceFailureIndication", "s1ap.TraceFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DeactivateTrace_PDU,
{ "DeactivateTrace", "s1ap.DeactivateTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellTrafficTrace_PDU,
{ "CellTrafficTrace", "s1ap.CellTrafficTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReportingControl_PDU,
{ "LocationReportingControl", "s1ap.LocationReportingControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReportingFailureIndication_PDU,
{ "LocationReportingFailureIndication", "s1ap.LocationReportingFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReport_PDU,
{ "LocationReport", "s1ap.LocationReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadStart_PDU,
{ "OverloadStart", "s1ap.OverloadStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadStop_PDU,
{ "OverloadStop", "s1ap.OverloadStop_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WriteReplaceWarningRequest_PDU,
{ "WriteReplaceWarningRequest", "s1ap.WriteReplaceWarningRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WriteReplaceWarningResponse_PDU,
{ "WriteReplaceWarningResponse", "s1ap.WriteReplaceWarningResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBDirectInformationTransfer_PDU,
{ "ENBDirectInformationTransfer", "s1ap.ENBDirectInformationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Inter_SystemInformationTransferType_PDU,
{ "Inter-SystemInformationTransferType", "s1ap.Inter_SystemInformationTransferType",
FT_UINT32, BASE_DEC, VALS(s1ap_Inter_SystemInformationTransferType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MMEDirectInformationTransfer_PDU,
{ "MMEDirectInformationTransfer", "s1ap.MMEDirectInformationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationTransfer_PDU,
{ "ENBConfigurationTransfer", "s1ap.ENBConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationTransfer_PDU,
{ "MMEConfigurationTransfer", "s1ap.MMEConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivateMessage_PDU,
{ "PrivateMessage", "s1ap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_KillRequest_PDU,
{ "KillRequest", "s1ap.KillRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_KillResponse_PDU,
{ "KillResponse", "s1ap.KillResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkUEAssociatedLPPaTransport_PDU,
{ "DownlinkUEAssociatedLPPaTransport", "s1ap.DownlinkUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkUEAssociatedLPPaTransport_PDU,
{ "UplinkUEAssociatedLPPaTransport", "s1ap.UplinkUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkNonUEAssociatedLPPaTransport_PDU,
{ "DownlinkNonUEAssociatedLPPaTransport", "s1ap.DownlinkNonUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkNonUEAssociatedLPPaTransport_PDU,
{ "UplinkNonUEAssociatedLPPaTransport", "s1ap.UplinkNonUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1AP_PDU_PDU,
{ "S1AP-PDU", "s1ap.S1AP_PDU",
FT_UINT32, BASE_DEC, VALS(s1ap_S1AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferApplicationIdentity_PDU,
{ "SONtransferApplicationIdentity", "s1ap.SONtransferApplicationIdentity",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferApplicationIdentity_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferRequestContainer_PDU,
{ "SONtransferRequestContainer", "s1ap.SONtransferRequestContainer",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferRequestContainer_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferResponseContainer_PDU,
{ "SONtransferResponseContainer", "s1ap.SONtransferResponseContainer",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferResponseContainer_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferCause_PDU,
{ "SONtransferCause", "s1ap.SONtransferCause",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferCause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_local,
{ "local", "s1ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_s1ap_global,
{ "global", "s1ap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_s1ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "s1ap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_id,
{ "id", "s1ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_s1ap_criticality,
{ "criticality", "s1ap.criticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ie_field_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_s1ap_ProtocolIE_ContainerList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "s1ap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ext_id,
{ "id", "s1ap.id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolExtensionID", HFILL }},
{ &hf_s1ap_extensionValue,
{ "extensionValue", "s1ap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "s1ap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_private_id,
{ "id", "s1ap.id",
FT_UINT32, BASE_DEC, VALS(s1ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_s1ap_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellBased,
{ "cellBased", "s1ap.cellBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellBasedMDT", HFILL }},
{ &hf_s1ap_tABased,
{ "tABased", "s1ap.tABased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TABasedMDT", HFILL }},
{ &hf_s1ap_pLMNWide,
{ "pLMNWide", "s1ap.pLMNWide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAIBased,
{ "tAIBased", "s1ap.tAIBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAIBasedMDT", HFILL }},
{ &hf_s1ap_priorityLevel,
{ "priorityLevel", "s1ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(s1ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pre_emptionCapability,
{ "pre-emptionCapability", "s1ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(s1ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "s1ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(s1ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_iE_Extensions,
{ "iE-Extensions", "s1ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_s1ap_Bearers_SubjectToStatusTransferList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RAB_ID,
{ "e-RAB-ID", "s1ap.e_RAB_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uL_COUNTvalue,
{ "uL-COUNTvalue", "s1ap.uL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_s1ap_dL_COUNTvalue,
{ "dL-COUNTvalue", "s1ap.dL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_s1ap_receiveStatusofULPDCPSDUs,
{ "receiveStatusofULPDCPSDUs", "s1ap.receiveStatusofULPDCPSDUs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_BPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellID_Cancelled,
{ "cellID-Cancelled", "s1ap.cellID_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI_Cancelled,
{ "tAI-Cancelled", "s1ap.tAI_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID_Cancelled,
{ "emergencyAreaID-Cancelled", "s1ap.emergencyAreaID_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellID_Broadcast,
{ "cellID-Broadcast", "s1ap.cellID_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI_Broadcast,
{ "tAI-Broadcast", "s1ap.tAI_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID_Broadcast,
{ "emergencyAreaID-Broadcast", "s1ap.emergencyAreaID_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CancelledCellinEAI_item,
{ "CancelledCellinEAI-Item", "s1ap.CancelledCellinEAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eCGI,
{ "eCGI", "s1ap.eCGI_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_numberOfBroadcasts,
{ "numberOfBroadcasts", "s1ap.numberOfBroadcasts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CancelledCellinTAI_item,
{ "CancelledCellinTAI-Item", "s1ap.CancelledCellinTAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_radioNetwork,
{ "radioNetwork", "s1ap.radioNetwork",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_CauseRadioNetwork_vals_ext, 0,
"CauseRadioNetwork", HFILL }},
{ &hf_s1ap_transport,
{ "transport", "s1ap.transport",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_s1ap_nas,
{ "nas", "s1ap.nas",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseNas_vals), 0,
"CauseNas", HFILL }},
{ &hf_s1ap_protocol,
{ "protocol", "s1ap.protocol",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_s1ap_misc,
{ "misc", "s1ap.misc",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_s1ap_CellID_Broadcast_item,
{ "CellID-Broadcast-Item", "s1ap.CellID_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellID_Cancelled_item,
{ "CellID-Cancelled-Item", "s1ap.CellID_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellIdListforMDT,
{ "cellIdListforMDT", "s1ap.cellIdListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellIdListforMDT_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXMEID,
{ "cdma2000OneXMEID", "s1ap.cdma2000OneXMEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXMSI,
{ "cdma2000OneXMSI", "s1ap.cdma2000OneXMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXPilot,
{ "cdma2000OneXPilot", "s1ap.cdma2000OneXPilot",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_Size,
{ "cell-Size", "s1ap.cell_Size",
FT_UINT32, BASE_DEC, VALS(s1ap_Cell_Size_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pLMNidentity,
{ "pLMNidentity", "s1ap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_lAC,
{ "lAC", "s1ap.lAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cI,
{ "cI", "s1ap.cI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rAC,
{ "rAC", "s1ap.rAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_IdList_item,
{ "CSG-IdList-Item", "s1ap.CSG_IdList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cSG_Id,
{ "cSG-Id", "s1ap.cSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pDCP_SN,
{ "pDCP-SN", "s1ap.pDCP_SN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_hFN,
{ "hFN", "s1ap.hFN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pDCP_SNExtended,
{ "pDCP-SNExtended", "s1ap.pDCP_SNExtended",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_hFNModified,
{ "hFNModified", "s1ap.hFNModified",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_procedureCode,
{ "procedureCode", "s1ap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_s1ap_triggeringMessage,
{ "triggeringMessage", "s1ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(s1ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_procedureCriticality,
{ "procedureCriticality", "s1ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_s1ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "s1ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_s1ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-Item", "s1ap.CriticalityDiagnostics_IE_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iECriticality,
{ "iECriticality", "s1ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_s1ap_iE_ID,
{ "iE-ID", "s1ap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_s1ap_typeOfError,
{ "typeOfError", "s1ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(s1ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ECGIList_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaIDList_item,
{ "EmergencyAreaID", "s1ap.EmergencyAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaID_Broadcast_item,
{ "EmergencyAreaID-Broadcast-Item", "s1ap.EmergencyAreaID_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID,
{ "emergencyAreaID", "s1ap.emergencyAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_completedCellinEAI,
{ "completedCellinEAI", "s1ap.completedCellinEAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaID_Cancelled_item,
{ "EmergencyAreaID-Cancelled-Item", "s1ap.EmergencyAreaID_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cancelledCellinEAI,
{ "cancelledCellinEAI", "s1ap.cancelledCellinEAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CompletedCellinEAI_item,
{ "CompletedCellinEAI-Item", "s1ap.CompletedCellinEAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_macroENB_ID,
{ "macroENB-ID", "s1ap.macroENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_s1ap_homeENB_ID,
{ "homeENB-ID", "s1ap.homeENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_s1ap_lAI,
{ "lAI", "s1ap.lAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNB_ID,
{ "eNB-ID", "s1ap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIList_item,
{ "GUMMEI", "s1ap.GUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_bearers_SubjectToStatusTransferList,
{ "bearers-SubjectToStatusTransferList", "s1ap.bearers_SubjectToStatusTransferList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBX2TLAs_item,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABInformationList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_dL_Forwarding,
{ "dL-Forwarding", "s1ap.dL_Forwarding",
FT_UINT32, BASE_DEC, VALS(s1ap_DL_Forwarding_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cause,
{ "cause", "s1ap.cause",
FT_UINT32, BASE_DEC, VALS(s1ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_qCI,
{ "qCI", "s1ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_allocationRetentionPriority,
{ "allocationRetentionPriority", "s1ap.allocationRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
"AllocationAndRetentionPriority", HFILL }},
{ &hf_s1ap_gbrQosInformation,
{ "gbrQosInformation", "s1ap.gbrQosInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_s1ap_cell_ID,
{ "cell-ID", "s1ap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdentity", HFILL }},
{ &hf_s1ap_ForbiddenTAs_item,
{ "ForbiddenTAs-Item", "s1ap.ForbiddenTAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pLMN_Identity,
{ "pLMN-Identity", "s1ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMNidentity", HFILL }},
{ &hf_s1ap_forbiddenTACs,
{ "forbiddenTACs", "s1ap.forbiddenTACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenTACs_item,
{ "TAC", "s1ap.TAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenLAs_item,
{ "ForbiddenLAs-Item", "s1ap.ForbiddenLAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenLACs,
{ "forbiddenLACs", "s1ap.forbiddenLACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenLACs_item,
{ "LAC", "s1ap.LAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RAB_MaximumBitrateDL,
{ "e-RAB-MaximumBitrateDL", "s1ap.e_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_MaximumBitrateUL,
{ "e-RAB-MaximumBitrateUL", "s1ap.e_RAB_MaximumBitrateUL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_GuaranteedBitrateDL,
{ "e-RAB-GuaranteedBitrateDL", "s1ap.e_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_GuaranteedBitrateUL,
{ "e-RAB-GuaranteedBitrateUL", "s1ap.e_RAB_GuaranteedBitrateUL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_mME_Group_ID,
{ "mME-Group-ID", "s1ap.mME_Group_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mME_Code,
{ "mME-Code", "s1ap.mME_Code",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servingPLMN,
{ "servingPLMN", "s1ap.servingPLMN",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMNidentity", HFILL }},
{ &hf_s1ap_equivalentPLMNs,
{ "equivalentPLMNs", "s1ap.equivalentPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"EPLMNs", HFILL }},
{ &hf_s1ap_forbiddenTAs,
{ "forbiddenTAs", "s1ap.forbiddenTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenLAs,
{ "forbiddenLAs", "s1ap.forbiddenLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenInterRATs,
{ "forbiddenInterRATs", "s1ap.forbiddenInterRATs",
FT_UINT32, BASE_DEC, VALS(s1ap_ForbiddenInterRATs_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate,
{ "measurementsToActivate", "s1ap.measurementsToActivate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m1reportingTrigger,
{ "m1reportingTrigger", "s1ap.m1reportingTrigger",
FT_UINT32, BASE_DEC, VALS(s1ap_M1ReportingTrigger_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m1thresholdeventA2,
{ "m1thresholdeventA2", "s1ap.m1thresholdeventA2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m1periodicReporting,
{ "m1periodicReporting", "s1ap.m1periodicReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_UTRAN_Cell,
{ "e-UTRAN-Cell", "s1ap.e_UTRAN_Cell_element",
FT_NONE, BASE_NONE, NULL, 0,
"LastVisitedEUTRANCellInformation", HFILL }},
{ &hf_s1ap_uTRAN_Cell,
{ "uTRAN-Cell", "s1ap.uTRAN_Cell",
FT_BYTES, BASE_NONE, NULL, 0,
"LastVisitedUTRANCellInformation", HFILL }},
{ &hf_s1ap_gERAN_Cell,
{ "gERAN-Cell", "s1ap.gERAN_Cell",
FT_UINT32, BASE_DEC, VALS(s1ap_LastVisitedGERANCellInformation_vals), 0,
"LastVisitedGERANCellInformation", HFILL }},
{ &hf_s1ap_global_Cell_ID,
{ "global-Cell-ID", "s1ap.global_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_cellType,
{ "cellType", "s1ap.cellType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_time_UE_StayedInCell,
{ "time-UE-StayedInCell", "s1ap.time_UE_StayedInCell",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_undefined,
{ "undefined", "s1ap.undefined_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_loggingInterval,
{ "loggingInterval", "s1ap.loggingInterval",
FT_UINT32, BASE_DEC, VALS(s1ap_LoggingInterval_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_loggingDuration,
{ "loggingDuration", "s1ap.loggingDuration",
FT_UINT32, BASE_DEC, VALS(s1ap_LoggingDuration_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m3period,
{ "m3period", "s1ap.m3period",
FT_UINT32, BASE_DEC, VALS(s1ap_M3period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m4period,
{ "m4period", "s1ap.m4period",
FT_UINT32, BASE_DEC, VALS(s1ap_M4period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m4_links_to_log,
{ "m4-links-to-log", "s1ap.m4_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_m5period,
{ "m5period", "s1ap.m5period",
FT_UINT32, BASE_DEC, VALS(s1ap_M5period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m5_links_to_log,
{ "m5-links-to-log", "s1ap.m5_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_mdt_Activation,
{ "mdt-Activation", "s1ap.mdt_Activation",
FT_UINT32, BASE_DEC, VALS(s1ap_MDT_Activation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_areaScopeOfMDT,
{ "areaScopeOfMDT", "s1ap.areaScopeOfMDT",
FT_UINT32, BASE_DEC, VALS(s1ap_AreaScopeOfMDT_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_mDTMode,
{ "mDTMode", "s1ap.mDTMode",
FT_UINT32, BASE_DEC, VALS(s1ap_MDTMode_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MDTPLMNList_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_immediateMDT,
{ "immediateMDT", "s1ap.immediateMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_loggedMDT,
{ "loggedMDT", "s1ap.loggedMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_threshold_RSRP,
{ "threshold-RSRP", "s1ap.threshold_RSRP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_threshold_RSRQ,
{ "threshold-RSRQ", "s1ap.threshold_RSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_overloadAction,
{ "overloadAction", "s1ap.overloadAction",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadAction_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_reportInterval,
{ "reportInterval", "s1ap.reportInterval",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportIntervalMDT_vals), 0,
"ReportIntervalMDT", HFILL }},
{ &hf_s1ap_reportAmount,
{ "reportAmount", "s1ap.reportAmount",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportAmountMDT_vals), 0,
"ReportAmountMDT", HFILL }},
{ &hf_s1ap_eventType,
{ "eventType", "s1ap.eventType",
FT_UINT32, BASE_DEC, VALS(s1ap_EventType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_reportArea,
{ "reportArea", "s1ap.reportArea",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportArea_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_rIMInformation,
{ "rIMInformation", "s1ap.rIMInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rIMRoutingAddress,
{ "rIMRoutingAddress", "s1ap.rIMRoutingAddress",
FT_UINT32, BASE_DEC, VALS(s1ap_RIMRoutingAddress_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_gERAN_Cell_ID,
{ "gERAN-Cell-ID", "s1ap.gERAN_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targetRNC_ID,
{ "targetRNC-ID", "s1ap.targetRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_nextHopChainingCount,
{ "nextHopChainingCount", "s1ap.nextHopChainingCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_s1ap_nextHopParameter,
{ "nextHopParameter", "s1ap.nextHopParameter",
FT_BYTES, BASE_NONE, NULL, 0,
"SecurityKey", HFILL }},
{ &hf_s1ap_sONInformationRequest,
{ "sONInformationRequest", "s1ap.sONInformationRequest",
FT_UINT32, BASE_DEC, VALS(s1ap_SONInformationRequest_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_sONInformationReply,
{ "sONInformationReply", "s1ap.sONInformationReply_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_x2TNLConfigurationInfo,
{ "x2TNLConfigurationInfo", "s1ap.x2TNLConfigurationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targeteNB_ID,
{ "targeteNB-ID", "s1ap.targeteNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_sourceeNB_ID,
{ "sourceeNB-ID", "s1ap.sourceeNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_sONInformation,
{ "sONInformation", "s1ap.sONInformation",
FT_UINT32, BASE_DEC, VALS(s1ap_SONInformation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_global_ENB_ID,
{ "global-ENB-ID", "s1ap.global_ENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_selected_TAI,
{ "selected-TAI", "s1ap.selected_TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAI", HFILL }},
{ &hf_s1ap_rRC_Container,
{ "rRC-Container", "s1ap.rRC_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABInformationList,
{ "e-RABInformationList", "s1ap.e_RABInformationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targetCell_ID,
{ "targetCell-ID", "s1ap.targetCell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_subscriberProfileIDforRFP,
{ "subscriberProfileIDforRFP", "s1ap.subscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uE_HistoryInformation,
{ "uE-HistoryInformation", "s1ap.uE_HistoryInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGUMMEIs_item,
{ "ServedGUMMEIsItem", "s1ap.ServedGUMMEIsItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedPLMNs,
{ "servedPLMNs", "s1ap.servedPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedGroupIDs,
{ "servedGroupIDs", "s1ap.servedGroupIDs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedMMECs,
{ "servedMMECs", "s1ap.servedMMECs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGroupIDs_item,
{ "MME-Group-ID", "s1ap.MME_Group_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedMMECs_item,
{ "MME-Code", "s1ap.MME_Code",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SupportedTAs_item,
{ "SupportedTAs-Item", "s1ap.SupportedTAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAC,
{ "tAC", "s1ap.tAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_broadcastPLMNs,
{ "broadcastPLMNs", "s1ap.broadcastPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"BPLMNs", HFILL }},
{ &hf_s1ap_stratumLevel,
{ "stratumLevel", "s1ap.stratumLevel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_synchronizationStatus,
{ "synchronizationStatus", "s1ap.synchronizationStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_SynchronizationStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_mMEC,
{ "mMEC", "s1ap.mMEC",
FT_BYTES, BASE_NONE, NULL, 0,
"MME_Code", HFILL }},
{ &hf_s1ap_m_TMSI,
{ "m-TMSI", "s1ap.m_TMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAIListforMDT,
{ "tAIListforMDT", "s1ap.tAIListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIListforMDT_item,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIListforWarning_item,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_Broadcast_item,
{ "TAI-Broadcast-Item", "s1ap.TAI_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI,
{ "tAI", "s1ap.tAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_completedCellinTAI,
{ "completedCellinTAI", "s1ap.completedCellinTAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_Cancelled_item,
{ "TAI-Cancelled-Item", "s1ap.TAI_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cancelledCellinTAI,
{ "cancelledCellinTAI", "s1ap.cancelledCellinTAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAListforMDT,
{ "tAListforMDT", "s1ap.tAListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAListforMDT_item,
{ "TAC", "s1ap.TAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CompletedCellinTAI_item,
{ "CompletedCellinTAI-Item", "s1ap.CompletedCellinTAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cGI,
{ "cGI", "s1ap.cGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rNC_ID,
{ "rNC-ID", "s1ap.rNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_extendedRNC_ID,
{ "extendedRNC-ID", "s1ap.extendedRNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_measurementThreshold,
{ "measurementThreshold", "s1ap.measurementThreshold",
FT_UINT32, BASE_DEC, VALS(s1ap_MeasurementThresholdA2_vals), 0,
"MeasurementThresholdA2", HFILL }},
{ &hf_s1ap_e_UTRAN_Trace_ID,
{ "e-UTRAN-Trace-ID", "s1ap.e_UTRAN_Trace_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace,
{ "interfacesToTrace", "s1ap.interfacesToTrace",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_traceDepth,
{ "traceDepth", "s1ap.traceDepth",
FT_UINT32, BASE_DEC, VALS(s1ap_TraceDepth_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_traceCollectionEntityIPAddress,
{ "traceCollectionEntityIPAddress", "s1ap.traceCollectionEntityIPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_transportLayerAddress,
{ "transportLayerAddress", "s1ap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uDP_Port_Number,
{ "uDP-Port-Number", "s1ap.uDP_Port_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"Port_Number", HFILL }},
{ &hf_s1ap_uEaggregateMaximumBitRateDL,
{ "uEaggregateMaximumBitRateDL", "s1ap.uEaggregateMaximumBitRateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_uEaggregateMaximumBitRateUL,
{ "uEaggregateMaximumBitRateUL", "s1ap.uEaggregateMaximumBitRateUL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_s1ap_uE_S1AP_ID_pair,
{ "uE-S1AP-ID-pair", "s1ap.uE_S1AP_ID_pair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mME_UE_S1AP_ID,
{ "mME-UE-S1AP-ID", "s1ap.mME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNB_UE_S1AP_ID,
{ "eNB-UE-S1AP-ID", "s1ap.eNB_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_HistoryInformation_item,
{ "LastVisitedCell-Item", "s1ap.LastVisitedCell_Item",
FT_UINT32, BASE_DEC, VALS(s1ap_LastVisitedCell_Item_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s_TMSI,
{ "s-TMSI", "s1ap.s_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iMSI,
{ "iMSI", "s1ap.iMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms,
{ "encryptionAlgorithms", "s1ap.encryptionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms,
{ "integrityProtectionAlgorithms", "s1ap.integrityProtectionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellIDList,
{ "cellIDList", "s1ap.cellIDList",
FT_UINT32, BASE_DEC, NULL, 0,
"ECGIList", HFILL }},
{ &hf_s1ap_trackingAreaListforWarning,
{ "trackingAreaListforWarning", "s1ap.trackingAreaListforWarning",
FT_UINT32, BASE_DEC, NULL, 0,
"TAIListforWarning", HFILL }},
{ &hf_s1ap_emergencyAreaIDList,
{ "emergencyAreaIDList", "s1ap.emergencyAreaIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNBX2TransportLayerAddresses,
{ "eNBX2TransportLayerAddresses", "s1ap.eNBX2TransportLayerAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
"ENBX2TLAs", HFILL }},
{ &hf_s1ap_ENBX2ExtTLAs_item,
{ "ENBX2ExtTLA", "s1ap.ENBX2ExtTLA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iPsecTLA,
{ "iPsecTLA", "s1ap.iPsecTLA",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_gTPTLAa,
{ "gTPTLAa", "s1ap.gTPTLAa",
FT_UINT32, BASE_DEC, NULL, 0,
"ENBX2GTPTLAs", HFILL }},
{ &hf_s1ap_ENBX2GTPTLAs_item,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_protocolIEs,
{ "protocolIEs", "s1ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_s1ap_dL_transportLayerAddress,
{ "dL-transportLayerAddress", "s1ap.dL_transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_dL_gTP_TEID,
{ "dL-gTP-TEID", "s1ap.dL_gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_s1ap_uL_TransportLayerAddress,
{ "uL-TransportLayerAddress", "s1ap.uL_TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_uL_GTP_TEID,
{ "uL-GTP-TEID", "s1ap.uL_GTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_s1ap_gTP_TEID,
{ "gTP-TEID", "s1ap.gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABlevelQosParameters,
{ "e-RABlevelQosParameters", "s1ap.e_RABlevelQosParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListBearerSUReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABlevelQoSParameters,
{ "e-RABlevelQoSParameters", "s1ap.e_RABlevelQoSParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_nAS_PDU,
{ "nAS-PDU", "s1ap.nAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListBearerSURes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedListBearerModReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABLevelQoSParameters,
{ "e-RABLevelQoSParameters", "s1ap.e_RABLevelQoSParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModRes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseListBearerRelComp_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListCtxtSUReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListCtxtSURes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1_Interface,
{ "s1-Interface", "s1ap.s1_Interface",
FT_UINT32, BASE_DEC, VALS(s1ap_ResetAll_vals), 0,
"ResetAll", HFILL }},
{ &hf_s1ap_partOfS1_Interface,
{ "partOfS1-Interface", "s1ap.partOfS1_Interface",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_associatedLogicalS1_ConnectionListRes", HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListRes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rIMTransfer,
{ "rIMTransfer", "s1ap.rIMTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_privateIEs,
{ "privateIEs", "s1ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_s1ap_initiatingMessage,
{ "initiatingMessage", "s1ap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_successfulOutcome,
{ "successfulOutcome", "s1ap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "s1ap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_initiatingMessagevalue,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_s1ap_successfulOutcome_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_s1ap_unsuccessfulOutcome_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
{ &hf_s1ap_cellLoadReporting,
{ "cellLoadReporting", "s1ap.cellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_multiCellLoadReporting,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"MultiCellLoadReportingRequest", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"EventTriggeredCellLoadReportingRequest", HFILL }},
{ &hf_s1ap_hOReporting,
{ "hOReporting", "s1ap.hOReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"HOReport", HFILL }},
{ &hf_s1ap_eutranCellActivation,
{ "eutranCellActivation", "s1ap.eutranCellActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellActivationRequest", HFILL }},
{ &hf_s1ap_energySavingsIndication,
{ "energySavingsIndication", "s1ap.energySavingsIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellStateIndication", HFILL }},
{ &hf_s1ap_failureEventReporting,
{ "failureEventReporting", "s1ap.failureEventReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_FailureEventReport_vals), 0,
"FailureEventReport", HFILL }},
{ &hf_s1ap_cellLoadReporting_01,
{ "cellLoadReporting", "s1ap.cellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingResponse_vals), 0,
"CellLoadReportingResponse", HFILL }},
{ &hf_s1ap_multiCellLoadReporting_01,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting",
FT_UINT32, BASE_DEC, NULL, 0,
"MultiCellLoadReportingResponse", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting_01,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"EventTriggeredCellLoadReportingResponse", HFILL }},
{ &hf_s1ap_hOReporting_01,
{ "hOReporting", "s1ap.hOReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eutranCellActivation_01,
{ "eutranCellActivation", "s1ap.eutranCellActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellActivationResponse", HFILL }},
{ &hf_s1ap_energySavingsIndication_01,
{ "energySavingsIndication", "s1ap.energySavingsIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_failureEventReporting_01,
{ "failureEventReporting", "s1ap.failureEventReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellLoadReporting_02,
{ "cellLoadReporting", "s1ap.cellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_multiCellLoadReporting_02,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting_02,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_hOReporting_02,
{ "hOReporting", "s1ap.hOReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_HOReportingCause_vals), 0,
"HOReportingCause", HFILL }},
{ &hf_s1ap_eutranCellActivation_02,
{ "eutranCellActivation", "s1ap.eutranCellActivation",
FT_UINT32, BASE_DEC, VALS(s1ap_CellActivationCause_vals), 0,
"CellActivationCause", HFILL }},
{ &hf_s1ap_energySavingsIndication_02,
{ "energySavingsIndication", "s1ap.energySavingsIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_CellStateIndicationCause_vals), 0,
"CellStateIndicationCause", HFILL }},
{ &hf_s1ap_failureEventReporting_02,
{ "failureEventReporting", "s1ap.failureEventReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_FailureEventReportingCause_vals), 0,
"FailureEventReportingCause", HFILL }},
{ &hf_s1ap_eUTRAN,
{ "eUTRAN", "s1ap.eUTRAN_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRANcellLoadReportingResponse", HFILL }},
{ &hf_s1ap_uTRAN,
{ "uTRAN", "s1ap.uTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_gERAN,
{ "gERAN", "s1ap.gERAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_compositeAvailableCapacityGroup,
{ "compositeAvailableCapacityGroup", "s1ap.compositeAvailableCapacityGroup",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_ID_01,
{ "cell-ID", "s1ap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_eUTRANcellLoadReportingResponse,
{ "eUTRANcellLoadReportingResponse", "s1ap.eUTRANcellLoadReportingResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eUTRAN_01,
{ "eUTRAN", "s1ap.eUTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_RequestedCellList_item,
{ "IRAT-Cell-ID", "s1ap.IRAT_Cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_requestedCellList,
{ "requestedCellList", "s1ap.requestedCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_ID_02,
{ "cell-ID", "s1ap.cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_ReportingCellList_item,
{ "ReportingCellList-Item", "s1ap.ReportingCellList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MultiCellLoadReportingResponse_item,
{ "MultiCellLoadReportingResponse-Item", "s1ap.MultiCellLoadReportingResponse_Item",
FT_UINT32, BASE_DEC, VALS(s1ap_MultiCellLoadReportingResponse_Item_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_eUTRANResponse,
{ "eUTRANResponse", "s1ap.eUTRANResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uTRANResponse,
{ "uTRANResponse", "s1ap.uTRANResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_gERANResponse,
{ "gERANResponse", "s1ap.gERANResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_numberOfMeasurementReportingLevels,
{ "numberOfMeasurementReportingLevels", "s1ap.numberOfMeasurementReportingLevels",
FT_UINT32, BASE_DEC, VALS(s1ap_NumberOfMeasurementReportingLevels_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_cellLoadReportingResponse,
{ "cellLoadReportingResponse", "s1ap.cellLoadReportingResponse",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingResponse_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_overloadFlag,
{ "overloadFlag", "s1ap.overloadFlag",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadFlag_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hoType,
{ "hoType", "s1ap.hoType",
FT_UINT32, BASE_DEC, VALS(s1ap_HoType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hoReportType,
{ "hoReportType", "s1ap.hoReportType",
FT_UINT32, BASE_DEC, VALS(s1ap_HoReportType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hosourceID,
{ "hosourceID", "s1ap.hosourceID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_hoTargetID,
{ "hoTargetID", "s1ap.hoTargetID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_candidateCellList,
{ "candidateCellList", "s1ap.candidateCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CandidateCellList_item,
{ "IRAT-Cell-ID", "s1ap.IRAT_Cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_cellsToActivateList,
{ "cellsToActivateList", "s1ap.cellsToActivateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_minimumActivationTime,
{ "minimumActivationTime", "s1ap.minimumActivationTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_60", HFILL }},
{ &hf_s1ap_CellsToActivateList_item,
{ "CellsToActivateList-Item", "s1ap.CellsToActivateList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_activatedCellsList,
{ "activatedCellsList", "s1ap.activatedCellsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ActivatedCellsList_item,
{ "ActivatedCellsList-Item", "s1ap.ActivatedCellsList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_notificationCellList,
{ "notificationCellList", "s1ap.notificationCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NotificationCellList_item,
{ "NotificationCellList-Item", "s1ap.NotificationCellList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_notifyFlag,
{ "notifyFlag", "s1ap.notifyFlag",
FT_UINT32, BASE_DEC, VALS(s1ap_NotifyFlag_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_tooEarlyInterRATHOReportFromEUTRAN,
{ "tooEarlyInterRATHOReportFromEUTRAN", "s1ap.tooEarlyInterRATHOReportFromEUTRAN_element",
FT_NONE, BASE_NONE, NULL, 0,
"TooEarlyInterRATHOReportReportFromEUTRAN", HFILL }},
{ &hf_s1ap_uERLFReportContainer,
{ "uERLFReportContainer", "s1ap.uERLFReportContainer",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_mobilityInformation,
{ "mobilityInformation", "s1ap.mobilityInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 231 "../../asn1/s1ap/packet-s1ap-template.c"
};
static gint *ett[] = {
&ett_s1ap,
&ett_s1ap_TransportLayerAddress,
&ett_s1ap_ToTargetTransparentContainer,
&ett_s1ap_ToSourceTransparentContainer,
&ett_s1ap_RRCContainer,
&ett_s1ap_UERadioCapability,
&ett_s1ap_RIMInformation,
#line 1 "../../asn1/s1ap/packet-s1ap-ettarr.c"
&ett_s1ap_PrivateIE_ID,
&ett_s1ap_ProtocolIE_Container,
&ett_s1ap_ProtocolIE_Field,
&ett_s1ap_ProtocolIE_ContainerList,
&ett_s1ap_ProtocolExtensionContainer,
&ett_s1ap_ProtocolExtensionField,
&ett_s1ap_PrivateIE_Container,
&ett_s1ap_PrivateIE_Field,
&ett_s1ap_AreaScopeOfMDT,
&ett_s1ap_AllocationAndRetentionPriority,
&ett_s1ap_Bearers_SubjectToStatusTransferList,
&ett_s1ap_Bearers_SubjectToStatusTransfer_Item,
&ett_s1ap_BPLMNs,
&ett_s1ap_BroadcastCancelledAreaList,
&ett_s1ap_BroadcastCompletedAreaList,
&ett_s1ap_CancelledCellinEAI,
&ett_s1ap_CancelledCellinEAI_Item,
&ett_s1ap_CancelledCellinTAI,
&ett_s1ap_CancelledCellinTAI_Item,
&ett_s1ap_Cause,
&ett_s1ap_CellID_Broadcast,
&ett_s1ap_CellID_Broadcast_Item,
&ett_s1ap_CellID_Cancelled,
&ett_s1ap_CellID_Cancelled_Item,
&ett_s1ap_CellBasedMDT,
&ett_s1ap_CellIdListforMDT,
&ett_s1ap_Cdma2000OneXSRVCCInfo,
&ett_s1ap_CellType,
&ett_s1ap_CGI,
&ett_s1ap_CSG_IdList,
&ett_s1ap_CSG_IdList_Item,
&ett_s1ap_COUNTvalue,
&ett_s1ap_COUNTValueExtended,
&ett_s1ap_CriticalityDiagnostics,
&ett_s1ap_CriticalityDiagnostics_IE_List,
&ett_s1ap_CriticalityDiagnostics_IE_Item,
&ett_s1ap_ECGIList,
&ett_s1ap_EmergencyAreaIDList,
&ett_s1ap_EmergencyAreaID_Broadcast,
&ett_s1ap_EmergencyAreaID_Broadcast_Item,
&ett_s1ap_EmergencyAreaID_Cancelled,
&ett_s1ap_EmergencyAreaID_Cancelled_Item,
&ett_s1ap_CompletedCellinEAI,
&ett_s1ap_CompletedCellinEAI_Item,
&ett_s1ap_ENB_ID,
&ett_s1ap_GERAN_Cell_ID,
&ett_s1ap_Global_ENB_ID,
&ett_s1ap_GUMMEIList,
&ett_s1ap_ENB_StatusTransfer_TransparentContainer,
&ett_s1ap_ENBX2TLAs,
&ett_s1ap_EPLMNs,
&ett_s1ap_E_RABInformationList,
&ett_s1ap_E_RABInformationListItem,
&ett_s1ap_E_RABList,
&ett_s1ap_E_RABItem,
&ett_s1ap_E_RABLevelQoSParameters,
&ett_s1ap_EUTRAN_CGI,
&ett_s1ap_ForbiddenTAs,
&ett_s1ap_ForbiddenTAs_Item,
&ett_s1ap_ForbiddenTACs,
&ett_s1ap_ForbiddenLAs,
&ett_s1ap_ForbiddenLAs_Item,
&ett_s1ap_ForbiddenLACs,
&ett_s1ap_GBR_QosInformation,
&ett_s1ap_GUMMEI,
&ett_s1ap_HandoverRestrictionList,
&ett_s1ap_ImmediateMDT,
&ett_s1ap_LAI,
&ett_s1ap_LastVisitedCell_Item,
&ett_s1ap_LastVisitedEUTRANCellInformation,
&ett_s1ap_LastVisitedGERANCellInformation,
&ett_s1ap_LoggedMDT,
&ett_s1ap_M3Configuration,
&ett_s1ap_M4Configuration,
&ett_s1ap_M5Configuration,
&ett_s1ap_MDT_Configuration,
&ett_s1ap_MDTPLMNList,
&ett_s1ap_MDTMode,
&ett_s1ap_MeasurementThresholdA2,
&ett_s1ap_OverloadResponse,
&ett_s1ap_M1PeriodicReporting,
&ett_s1ap_RequestType,
&ett_s1ap_RIMTransfer,
&ett_s1ap_RIMRoutingAddress,
&ett_s1ap_SecurityContext,
&ett_s1ap_SONInformation,
&ett_s1ap_SONInformationReply,
&ett_s1ap_SONConfigurationTransfer,
&ett_s1ap_SourceeNB_ID,
&ett_s1ap_SourceeNB_ToTargeteNB_TransparentContainer,
&ett_s1ap_ServedGUMMEIs,
&ett_s1ap_ServedGUMMEIsItem,
&ett_s1ap_ServedGroupIDs,
&ett_s1ap_ServedMMECs,
&ett_s1ap_ServedPLMNs,
&ett_s1ap_SupportedTAs,
&ett_s1ap_SupportedTAs_Item,
&ett_s1ap_TimeSynchronizationInfo,
&ett_s1ap_S_TMSI,
&ett_s1ap_TAIBasedMDT,
&ett_s1ap_TAIListforMDT,
&ett_s1ap_TAIListforWarning,
&ett_s1ap_TAI,
&ett_s1ap_TAI_Broadcast,
&ett_s1ap_TAI_Broadcast_Item,
&ett_s1ap_TAI_Cancelled,
&ett_s1ap_TAI_Cancelled_Item,
&ett_s1ap_TABasedMDT,
&ett_s1ap_TAListforMDT,
&ett_s1ap_CompletedCellinTAI,
&ett_s1ap_CompletedCellinTAI_Item,
&ett_s1ap_TargetID,
&ett_s1ap_TargeteNB_ID,
&ett_s1ap_TargetRNC_ID,
&ett_s1ap_TargeteNB_ToSourceeNB_TransparentContainer,
&ett_s1ap_M1ThresholdEventA2,
&ett_s1ap_TraceActivation,
&ett_s1ap_TunnelInformation,
&ett_s1ap_UEAggregateMaximumBitrate,
&ett_s1ap_UE_S1AP_IDs,
&ett_s1ap_UE_S1AP_ID_pair,
&ett_s1ap_UE_associatedLogicalS1_ConnectionItem,
&ett_s1ap_UE_HistoryInformation,
&ett_s1ap_UEPagingID,
&ett_s1ap_UESecurityCapabilities,
&ett_s1ap_WarningAreaList,
&ett_s1ap_X2TNLConfigurationInfo,
&ett_s1ap_ENBX2ExtTLAs,
&ett_s1ap_ENBX2ExtTLA,
&ett_s1ap_ENBX2GTPTLAs,
&ett_s1ap_HandoverRequired,
&ett_s1ap_HandoverCommand,
&ett_s1ap_E_RABDataForwardingItem,
&ett_s1ap_HandoverPreparationFailure,
&ett_s1ap_HandoverRequest,
&ett_s1ap_E_RABToBeSetupItemHOReq,
&ett_s1ap_HandoverRequestAcknowledge,
&ett_s1ap_E_RABAdmittedItem,
&ett_s1ap_E_RABFailedToSetupItemHOReqAck,
&ett_s1ap_HandoverFailure,
&ett_s1ap_HandoverNotify,
&ett_s1ap_PathSwitchRequest,
&ett_s1ap_E_RABToBeSwitchedDLItem,
&ett_s1ap_PathSwitchRequestAcknowledge,
&ett_s1ap_E_RABToBeSwitchedULItem,
&ett_s1ap_PathSwitchRequestFailure,
&ett_s1ap_HandoverCancel,
&ett_s1ap_HandoverCancelAcknowledge,
&ett_s1ap_E_RABSetupRequest,
&ett_s1ap_E_RABToBeSetupListBearerSUReq,
&ett_s1ap_E_RABToBeSetupItemBearerSUReq,
&ett_s1ap_E_RABSetupResponse,
&ett_s1ap_E_RABSetupListBearerSURes,
&ett_s1ap_E_RABSetupItemBearerSURes,
&ett_s1ap_E_RABModifyRequest,
&ett_s1ap_E_RABToBeModifiedListBearerModReq,
&ett_s1ap_E_RABToBeModifiedItemBearerModReq,
&ett_s1ap_E_RABModifyResponse,
&ett_s1ap_E_RABModifyListBearerModRes,
&ett_s1ap_E_RABModifyItemBearerModRes,
&ett_s1ap_E_RABReleaseCommand,
&ett_s1ap_E_RABReleaseResponse,
&ett_s1ap_E_RABReleaseListBearerRelComp,
&ett_s1ap_E_RABReleaseItemBearerRelComp,
&ett_s1ap_E_RABReleaseIndication,
&ett_s1ap_InitialContextSetupRequest,
&ett_s1ap_E_RABToBeSetupListCtxtSUReq,
&ett_s1ap_E_RABToBeSetupItemCtxtSUReq,
&ett_s1ap_InitialContextSetupResponse,
&ett_s1ap_E_RABSetupListCtxtSURes,
&ett_s1ap_E_RABSetupItemCtxtSURes,
&ett_s1ap_InitialContextSetupFailure,
&ett_s1ap_Paging,
&ett_s1ap_TAIList,
&ett_s1ap_TAIItem,
&ett_s1ap_UEContextReleaseRequest,
&ett_s1ap_UEContextReleaseCommand,
&ett_s1ap_UEContextReleaseComplete,
&ett_s1ap_UEContextModificationRequest,
&ett_s1ap_UEContextModificationResponse,
&ett_s1ap_UEContextModificationFailure,
&ett_s1ap_UERadioCapabilityMatchRequest,
&ett_s1ap_UERadioCapabilityMatchResponse,
&ett_s1ap_DownlinkNASTransport,
&ett_s1ap_InitialUEMessage,
&ett_s1ap_UplinkNASTransport,
&ett_s1ap_NASNonDeliveryIndication,
&ett_s1ap_Reset,
&ett_s1ap_ResetType,
&ett_s1ap_UE_associatedLogicalS1_ConnectionListRes,
&ett_s1ap_ResetAcknowledge,
&ett_s1ap_UE_associatedLogicalS1_ConnectionListResAck,
&ett_s1ap_ErrorIndication,
&ett_s1ap_S1SetupRequest,
&ett_s1ap_S1SetupResponse,
&ett_s1ap_S1SetupFailure,
&ett_s1ap_ENBConfigurationUpdate,
&ett_s1ap_ENBConfigurationUpdateAcknowledge,
&ett_s1ap_ENBConfigurationUpdateFailure,
&ett_s1ap_MMEConfigurationUpdate,
&ett_s1ap_MMEConfigurationUpdateAcknowledge,
&ett_s1ap_MMEConfigurationUpdateFailure,
&ett_s1ap_DownlinkS1cdma2000tunneling,
&ett_s1ap_UplinkS1cdma2000tunneling,
&ett_s1ap_UECapabilityInfoIndication,
&ett_s1ap_ENBStatusTransfer,
&ett_s1ap_MMEStatusTransfer,
&ett_s1ap_TraceStart,
&ett_s1ap_TraceFailureIndication,
&ett_s1ap_DeactivateTrace,
&ett_s1ap_CellTrafficTrace,
&ett_s1ap_LocationReportingControl,
&ett_s1ap_LocationReportingFailureIndication,
&ett_s1ap_LocationReport,
&ett_s1ap_OverloadStart,
&ett_s1ap_OverloadStop,
&ett_s1ap_WriteReplaceWarningRequest,
&ett_s1ap_WriteReplaceWarningResponse,
&ett_s1ap_ENBDirectInformationTransfer,
&ett_s1ap_Inter_SystemInformationTransferType,
&ett_s1ap_MMEDirectInformationTransfer,
&ett_s1ap_ENBConfigurationTransfer,
&ett_s1ap_MMEConfigurationTransfer,
&ett_s1ap_PrivateMessage,
&ett_s1ap_KillRequest,
&ett_s1ap_KillResponse,
&ett_s1ap_DownlinkUEAssociatedLPPaTransport,
&ett_s1ap_UplinkUEAssociatedLPPaTransport,
&ett_s1ap_DownlinkNonUEAssociatedLPPaTransport,
&ett_s1ap_UplinkNonUEAssociatedLPPaTransport,
&ett_s1ap_S1AP_PDU,
&ett_s1ap_InitiatingMessage,
&ett_s1ap_SuccessfulOutcome,
&ett_s1ap_UnsuccessfulOutcome,
&ett_s1ap_SONtransferRequestContainer,
&ett_s1ap_SONtransferResponseContainer,
&ett_s1ap_SONtransferCause,
&ett_s1ap_CellLoadReportingResponse,
&ett_s1ap_EUTRANcellLoadReportingResponse,
&ett_s1ap_EUTRANResponse,
&ett_s1ap_IRAT_Cell_ID,
&ett_s1ap_RequestedCellList,
&ett_s1ap_MultiCellLoadReportingRequest,
&ett_s1ap_ReportingCellList_Item,
&ett_s1ap_ReportingCellList,
&ett_s1ap_MultiCellLoadReportingResponse,
&ett_s1ap_MultiCellLoadReportingResponse_Item,
&ett_s1ap_EventTriggeredCellLoadReportingRequest,
&ett_s1ap_EventTriggeredCellLoadReportingResponse,
&ett_s1ap_HOReport,
&ett_s1ap_CandidateCellList,
&ett_s1ap_CellActivationRequest,
&ett_s1ap_CellsToActivateList,
&ett_s1ap_CellsToActivateList_Item,
&ett_s1ap_CellActivationResponse,
&ett_s1ap_ActivatedCellsList,
&ett_s1ap_ActivatedCellsList_Item,
&ett_s1ap_CellStateIndication,
&ett_s1ap_NotificationCellList,
&ett_s1ap_NotificationCellList_Item,
&ett_s1ap_FailureEventReport,
&ett_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN,
#line 243 "../../asn1/s1ap/packet-s1ap-template.c"
};
module_t *s1ap_module;
proto_s1ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_s1ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("s1ap", dissect_s1ap, proto_s1ap);
s1ap_ies_dissector_table = register_dissector_table("s1ap.ies", "S1AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
s1ap_ies_p1_dissector_table = register_dissector_table("s1ap.ies.pair.first", "S1AP-PROTOCOL-IES-PAIR FirstValue", FT_UINT32, BASE_DEC);
s1ap_ies_p2_dissector_table = register_dissector_table("s1ap.ies.pair.second", "S1AP-PROTOCOL-IES-PAIR SecondValue", FT_UINT32, BASE_DEC);
s1ap_extension_dissector_table = register_dissector_table("s1ap.extension", "S1AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
s1ap_proc_imsg_dissector_table = register_dissector_table("s1ap.proc.imsg", "S1AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
s1ap_proc_sout_dissector_table = register_dissector_table("s1ap.proc.sout", "S1AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
s1ap_proc_uout_dissector_table = register_dissector_table("s1ap.proc.uout", "S1AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
s1ap_module = prefs_register_protocol(proto_s1ap, proto_reg_handoff_s1ap);
prefs_register_uint_preference(s1ap_module, "sctp.port",
"S1AP SCTP Port",
"Set the SCTP port for S1AP messages",
10,
&gbl_s1apSctpPort);
prefs_register_bool_preference(s1ap_module, "dissect_container", "Dissect TransparentContainer", "Dissect TransparentContainers that are opaque to S1AP", &g_s1ap_dissect_container);
}
