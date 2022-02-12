static int
dissect_x2ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_maxPrivateIEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxPrivateIEs, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 67 "../../asn1/x2ap/x2ap.cnf"
ProcedureCode = 0xFFFF;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 61 "../../asn1/x2ap/x2ap.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str(ProcedureCode, x2ap_ProcedureCode_vals,
"unknown message"));
return offset;
}
static int
dissect_x2ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 50 "../../asn1/x2ap/x2ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(x2ap_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_x2ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Single_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x2ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_x2ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_x2ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_x2ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_x2ap_PrivateIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_x2ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_40(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
40, 40, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ABSInformationFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformationFDD, ABSInformationFDD_sequence);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_1_70_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 70, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ABSInformationTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformationTDD, ABSInformationTDD_sequence);
return offset;
}
static int
dissect_x2ap_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_x2ap_ABSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformation, ABSInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_DL_ABS_status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UsableABSInformationFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformationFDD, UsableABSInformationFDD_sequence);
return offset;
}
static int
dissect_x2ap_UsableABSInformationTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformationTDD, UsableABSInformationTDD_sequence);
return offset;
}
static int
dissect_x2ap_UsableABSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformation, UsableABSInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ABS_Status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABS_Status, ABS_Status_sequence);
return offset;
}
static int
dissect_x2ap_Key_eNodeB_Star(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_NextHopChainingCount(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_AS_SecurityInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_AS_SecurityInformation, AS_SecurityInformation_sequence);
return offset;
}
static int
dissect_x2ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_x2ap_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 78 "../../asn1/x2ap/x2ap.cnf"
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
dissect_x2ap_EUTRANCellIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_ECGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ECGI, ECGI_sequence);
return offset;
}
static int
dissect_x2ap_CellIdListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellIdListforMDT, CellIdListforMDT_sequence_of,
1, maxnoofCellIDforMDT, FALSE);
return offset;
}
static int
dissect_x2ap_CellBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellBasedMDT, CellBasedMDT_sequence);
return offset;
}
static int
dissect_x2ap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_TAListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_TAListforMDT, TAListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_x2ap_TABasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TABasedMDT, TABasedMDT_sequence);
return offset;
}
static int
dissect_x2ap_AreaScopeOfMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_AreaScopeOfMDT, AreaScopeOfMDT_choice,
NULL);
return offset;
}
static int
dissect_x2ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GINT64_CONSTANT(10000000000U), NULL, FALSE);
return offset;
}
static int
dissect_x2ap_BroadcastPLMNs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_BroadcastPLMNs_Item, BroadcastPLMNs_Item_sequence_of,
1, maxnoofBPLMNs, FALSE);
return offset;
}
static int
dissect_x2ap_CapacityValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_CellCapacityClassValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
22, NULL, TRUE, 7, NULL);
return offset;
}
static int
dissect_x2ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_x2ap_Cell_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CellType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellType, CellType_sequence);
return offset;
}
static int
dissect_x2ap_CompositeAvailableCapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompositeAvailableCapacity, CompositeAvailableCapacity_sequence);
return offset;
}
static int
dissect_x2ap_CompositeAvailableCapacityGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompositeAvailableCapacityGroup, CompositeAvailableCapacityGroup_sequence);
return offset;
}
static int
dissect_x2ap_PDCP_SN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_HFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_COUNTvalue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_COUNTvalue, COUNTvalue_sequence);
return offset;
}
static int
dissect_x2ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_x2ap_CRNTI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CSG_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_CyclicPrefixDL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CyclicPrefixUL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_DeactivationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_DL_Forwarding(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_DL_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_DL_non_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_DL_Total_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_EARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxEARFCN, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_Transmission_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_FDD_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_FDD_Info, FDD_Info_sequence);
return offset;
}
static int
dissect_x2ap_SubframeAssignment(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SpecialSubframePatterns(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SpecialSubframe_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SpecialSubframe_Info, SpecialSubframe_Info_sequence);
return offset;
}
static int
dissect_x2ap_TDD_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TDD_Info, TDD_Info_sequence);
return offset;
}
static int
dissect_x2ap_EUTRA_Mode_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_EUTRA_Mode_Info, EUTRA_Mode_Info_choice,
NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_x2ap_EncryptionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_EPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_EPLMNs, EPLMNs_sequence_of,
1, maxnoofEPLMNs, FALSE);
return offset;
}
static int
dissect_x2ap_E_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_x2ap_E_RAB_Level_QoS_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_Level_QoS_Parameters, E_RAB_Level_QoS_Parameters_sequence);
return offset;
}
static int
dissect_x2ap_E_RAB_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_List, E_RAB_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RAB_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_Item, E_RAB_Item_sequence);
return offset;
}
static int
dissect_x2ap_EUTRANTraceID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_EventType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ForbiddenInterRATs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_x2ap_ForbiddenTACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTACs, ForbiddenTACs_sequence_of,
1, maxnoofForbTACs, FALSE);
return offset;
}
static int
dissect_x2ap_ForbiddenTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTAs_Item, ForbiddenTAs_Item_sequence);
return offset;
}
static int
dissect_x2ap_ForbiddenTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTAs, ForbiddenTAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_x2ap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_ForbiddenLACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLACs, ForbiddenLACs_sequence_of,
1, maxnoofForbLACs, FALSE);
return offset;
}
static int
dissect_x2ap_ForbiddenLAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLAs_Item, ForbiddenLAs_Item_sequence);
return offset;
}
static int
dissect_x2ap_ForbiddenLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLAs, ForbiddenLAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_x2ap_Fourframes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_GlobalENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GlobalENB_ID, GlobalENB_ID_sequence);
return offset;
}
static int
dissect_x2ap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 111 "../../asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
gint tvb_len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_TransportLayerAddress);
if (tvb_len==4){
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv4, parameter_tvb, 0, tvb_len, ENC_BIG_ENDIAN);
}
if (tvb_len==16){
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv6, parameter_tvb, 0, tvb_len, ENC_NA);
}
return offset;
}
static int
dissect_x2ap_GTP_TEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_GTPtunnelEndpoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GTPtunnelEndpoint, GTPtunnelEndpoint_sequence);
return offset;
}
static int
dissect_x2ap_MME_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_GU_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GU_Group_ID, GU_Group_ID_sequence);
return offset;
}
static int
dissect_x2ap_GUGroupIDList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_GUGroupIDList, GUGroupIDList_sequence_of,
1, maxPools, FALSE);
return offset;
}
static int
dissect_x2ap_MME_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_GUMMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GUMMEI, GUMMEI_sequence);
return offset;
}
static int
dissect_x2ap_HandoverReportType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_HandoverRestrictionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRestrictionList, HandoverRestrictionList_sequence);
return offset;
}
static int
dissect_x2ap_LoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_HWLoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HWLoadIndicator, HWLoadIndicator_sequence);
return offset;
}
static int
dissect_x2ap_InvokeIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_IntegrityProtectionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_InterfacesToTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_Time_UE_StayedInCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_LastVisitedEUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedEUTRANCellInformation, LastVisitedEUTRANCellInformation_sequence);
return offset;
}
static int
dissect_x2ap_LastVisitedUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_LastVisitedGERANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedGERANCellInformation, LastVisitedGERANCellInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_LastVisitedCell_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedCell_Item, LastVisitedCell_Item_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ReportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_LocationReportingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LocationReportingInformation, LocationReportingInformation_sequence);
return offset;
}
static int
dissect_x2ap_MDT_Activation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_MeasurementsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_ReportingTriggerMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Threshold_RSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_Threshold_RSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementThresholdA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementThresholdA2, MeasurementThresholdA2_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ThresholdEventA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ThresholdEventA2, ThresholdEventA2_sequence);
return offset;
}
static int
dissect_x2ap_ReportIntervalMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ReportAmountMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_PeriodicReportingMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PeriodicReportingMDT, PeriodicReportingMDT_sequence);
return offset;
}
static int
dissect_x2ap_MDT_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MDT_Configuration, MDT_Configuration_sequence);
return offset;
}
static int
dissect_x2ap_Measurement_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4095U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_RadioframeAllocationPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_RadioframeAllocationOffset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_Oneframe(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_SubframeAllocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubframeAllocation, SubframeAllocation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_MBSFN_Subframe_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MBSFN_Subframe_Info, MBSFN_Subframe_Info_sequence);
return offset;
}
static int
dissect_x2ap_MBSFN_Subframe_Infolist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MBSFN_Subframe_Infolist, MBSFN_Subframe_Infolist_sequence_of,
1, maxnoofMBSFN, FALSE);
return offset;
}
static int
dissect_x2ap_ManagementBasedMDTallowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_M20_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-20, 20U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_MobilityParametersModificationRange(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityParametersModificationRange, MobilityParametersModificationRange_sequence);
return offset;
}
static int
dissect_x2ap_MobilityParametersInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityParametersInformation, MobilityParametersInformation_sequence);
return offset;
}
static int
dissect_x2ap_PCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_Neighbour_Information_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_Neighbour_Information_item, Neighbour_Information_item_sequence);
return offset;
}
static int
dissect_x2ap_Neighbour_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_Neighbour_Information, Neighbour_Information_sequence_of,
0, maxnoofNeighbours, FALSE);
return offset;
}
static int
dissect_x2ap_Number_of_Antennaports(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_837(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 837U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_94(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 94U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_PRACH_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PRACH_Configuration, PRACH_Configuration_sequence);
return offset;
}
static int
dissect_x2ap_UL_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UL_non_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UL_Total_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_RadioResourceStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RadioResourceStatus, RadioResourceStatus_sequence);
return offset;
}
static int
dissect_x2ap_ReceiveStatusofULPDCPSDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4096, 4096, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_Registration_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_6_110_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 110, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_RNTP_Threshold(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_3_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_4_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_RelativeNarrowbandTxPower(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RelativeNarrowbandTxPower, RelativeNarrowbandTxPower_sequence);
return offset;
}
static int
dissect_x2ap_ReportCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_RRC_Context(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 135 "../../asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_lte_rrc_HandoverPreparationInformation_PDU(parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_x2ap_RRCConnSetupIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_S1TNLLoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_S1TNLLoadIndicator, S1TNLLoadIndicator_sequence);
return offset;
}
static int
dissect_x2ap_ServedCell_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCell_Information, ServedCell_Information_sequence);
return offset;
}
static int
dissect_x2ap_ServedCells_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCells_item, ServedCells_item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCells, ServedCells_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_ShortMAC_I(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_SRVCCOperationPossible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SubscriberProfileIDforRFP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_TargeteNBtoSource_eNBTransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 91 "../../asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_lte_rrc_HandoverCommand_PDU(parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_x2ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_TraceDepth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_TraceCollectionEntityIPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_TraceActivation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TraceActivation, TraceActivation_sequence);
return offset;
}
static int
dissect_x2ap_UE_HistoryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_HistoryInformation, UE_HistoryInformation_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_x2ap_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UE_X2AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UEAggregateMaximumBitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UEAggregateMaximumBitRate, UEAggregateMaximumBitRate_sequence);
return offset;
}
static int
dissect_x2ap_UESecurityCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UESecurityCapabilities, UESecurityCapabilities_sequence);
return offset;
}
static int
dissect_x2ap_UL_InterferenceOverloadIndication_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_UL_InterferenceOverloadIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_InterferenceOverloadIndication, UL_InterferenceOverloadIndication_sequence_of,
1, maxnoofPRBs, FALSE);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 110, TRUE, NULL);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndicationInfo_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_HighInterferenceIndicationInfo_Item, UL_HighInterferenceIndicationInfo_Item_sequence);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndicationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_HighInterferenceIndicationInfo, UL_HighInterferenceIndicationInfo_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_UE_RLF_Report_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_HandoverRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRequest, HandoverRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetup_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetup_List, E_RABs_ToBeSetup_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_UE_ContextInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_ContextInformation, UE_ContextInformation_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetup_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetup_Item, E_RABs_ToBeSetup_Item_sequence);
return offset;
}
static int
dissect_x2ap_HandoverRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRequestAcknowledge, HandoverRequestAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_List, E_RABs_Admitted_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_Item, E_RABs_Admitted_Item_sequence);
return offset;
}
static int
dissect_x2ap_HandoverPreparationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverPreparationFailure, HandoverPreparationFailure_sequence);
return offset;
}
static int
dissect_x2ap_HandoverReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverReport, HandoverReport_sequence);
return offset;
}
static int
dissect_x2ap_SNStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SNStatusTransfer, SNStatusTransfer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToStatusTransfer_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToStatusTransfer_List, E_RABs_SubjectToStatusTransfer_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToStatusTransfer_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToStatusTransfer_Item, E_RABs_SubjectToStatusTransfer_Item_sequence);
return offset;
}
static int
dissect_x2ap_UEContextRelease(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UEContextRelease, UEContextRelease_sequence);
return offset;
}
static int
dissect_x2ap_HandoverCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverCancel, HandoverCancel_sequence);
return offset;
}
static int
dissect_x2ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_x2ap_ResetRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResetRequest, ResetRequest_sequence);
return offset;
}
static int
dissect_x2ap_ResetResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResetResponse, ResetResponse_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupRequest, X2SetupRequest_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupResponse, X2SetupResponse_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupFailure, X2SetupFailure_sequence);
return offset;
}
static int
dissect_x2ap_LoadInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LoadInformation, LoadInformation_sequence);
return offset;
}
static int
dissect_x2ap_CellInformation_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellInformation_List, CellInformation_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellInformation_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellInformation_Item, CellInformation_Item_sequence);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToModify_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToModify_Item, ServedCellsToModify_Item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToModify(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToModify, ServedCellsToModify_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_Old_ECGIs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_Old_ECGIs, Old_ECGIs_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusRequest, ResourceStatusRequest_sequence);
return offset;
}
static int
dissect_x2ap_CellToReport_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellToReport_List, CellToReport_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellToReport_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellToReport_Item, CellToReport_Item_sequence);
return offset;
}
static int
dissect_x2ap_ReportingPeriodicity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_PartialSuccessIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ResourceStatusResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusResponse, ResourceStatusResponse_sequence);
return offset;
}
static int
dissect_x2ap_MeasurementInitiationResult_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementInitiationResult_List, MeasurementInitiationResult_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementFailureCause_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementFailureCause_List, MeasurementFailureCause_List_sequence_of,
1, maxFailedMeasObjects, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementInitiationResult_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementInitiationResult_Item, MeasurementInitiationResult_Item_sequence);
return offset;
}
static int
dissect_x2ap_MeasurementFailureCause_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementFailureCause_Item, MeasurementFailureCause_Item_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusFailure, ResourceStatusFailure_sequence);
return offset;
}
static int
dissect_x2ap_CompleteFailureCauseInformation_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompleteFailureCauseInformation_List, CompleteFailureCauseInformation_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CompleteFailureCauseInformation_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompleteFailureCauseInformation_Item, CompleteFailureCauseInformation_Item_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusUpdate, ResourceStatusUpdate_sequence);
return offset;
}
static int
dissect_x2ap_CellMeasurementResult_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellMeasurementResult_List, CellMeasurementResult_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellMeasurementResult_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellMeasurementResult_Item, CellMeasurementResult_Item_sequence);
return offset;
}
static int
dissect_x2ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeRequest, MobilityChangeRequest_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeAcknowledge, MobilityChangeAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeFailure, MobilityChangeFailure_sequence);
return offset;
}
static int
dissect_x2ap_RLFIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RLFIndication, RLFIndication_sequence);
return offset;
}
static int
dissect_x2ap_CellActivationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationRequest, CellActivationRequest_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToActivate_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToActivate_Item, ServedCellsToActivate_Item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToActivate, ServedCellsToActivate_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellActivationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationResponse, CellActivationResponse_sequence);
return offset;
}
static int
dissect_x2ap_ActivatedCellList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ActivatedCellList_Item, ActivatedCellList_Item_sequence);
return offset;
}
static int
dissect_x2ap_ActivatedCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ActivatedCellList, ActivatedCellList_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellActivationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationFailure, CellActivationFailure_sequence);
return offset;
}
static int
dissect_x2ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_x2ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_x2ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_x2ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_x2ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_x2ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_x2ap_X2AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2AP_PDU, X2AP_PDU_choice,
NULL);
return offset;
}
static int dissect_ABSInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ABSInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_ABSInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ABS_Status_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ABS_Status(tvb, offset, &asn1_ctx, tree, hf_x2ap_ABS_Status_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Cause(tvb, offset, &asn1_ctx, tree, hf_x2ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompositeAvailableCapacityGroup_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompositeAvailableCapacityGroup(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompositeAvailableCapacityGroup_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_x2ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CRNTI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CRNTI(tvb, offset, &asn1_ctx, tree, hf_x2ap_CRNTI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_x2ap_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_x2ap_CSG_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DeactivationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_DeactivationIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_DeactivationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ECGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ECGI(tvb, offset, &asn1_ctx, tree, hf_x2ap_ECGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RAB_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RAB_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RAB_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RAB_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RAB_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RAB_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalENB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GlobalENB_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_GlobalENB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUGroupIDList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GUGroupIDList(tvb, offset, &asn1_ctx, tree, hf_x2ap_GUGroupIDList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GUMMEI(tvb, offset, &asn1_ctx, tree, hf_x2ap_GUMMEI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverReportType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverReportType(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverReportType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InvokeIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_InvokeIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_InvokeIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_MDT_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Measurement_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Measurement_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_Measurement_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Subframe_Infolist_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MBSFN_Subframe_Infolist(tvb, offset, &asn1_ctx, tree, hf_x2ap_MBSFN_Subframe_Infolist_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ManagementBasedMDTallowed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ManagementBasedMDTallowed(tvb, offset, &asn1_ctx, tree, hf_x2ap_ManagementBasedMDTallowed_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityParametersModificationRange_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityParametersModificationRange(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityParametersModificationRange_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityParametersInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityParametersInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityParametersInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Number_of_Antennaports_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Number_of_Antennaports(tvb, offset, &asn1_ctx, tree, hf_x2ap_Number_of_Antennaports_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PCI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PCI(tvb, offset, &asn1_ctx, tree, hf_x2ap_PCI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PRACH_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PRACH_Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_PRACH_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Registration_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Registration_Request(tvb, offset, &asn1_ctx, tree, hf_x2ap_Registration_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportCharacteristics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportCharacteristics(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportCharacteristics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRCConnSetupIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RRCConnSetupIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_RRCConnSetupIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCells_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCells(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCells_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ShortMAC_I_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ShortMAC_I(tvb, offset, &asn1_ctx, tree, hf_x2ap_ShortMAC_I_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCOperationPossible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SRVCCOperationPossible(tvb, offset, &asn1_ctx, tree, hf_x2ap_SRVCCOperationPossible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargeteNBtoSource_eNBTransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TargeteNBtoSource_eNBTransparentContainer(tvb, offset, &asn1_ctx, tree, hf_x2ap_TargeteNBtoSource_eNBTransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_x2ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceActivation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TraceActivation(tvb, offset, &asn1_ctx, tree, hf_x2ap_TraceActivation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_HistoryInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_HistoryInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_HistoryInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_X2AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_X2AP_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_X2AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_RLF_Report_Container_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_RLF_Report_Container(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_RLF_Report_Container_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeSetup_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeSetup_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeSetup_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverPreparationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverPreparationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverReport(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SNStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SNStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_x2ap_SNStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToStatusTransfer_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToStatusTransfer_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToStatusTransfer_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToStatusTransfer_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToStatusTransfer_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextRelease_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UEContextRelease(tvb, offset, &asn1_ctx, tree, hf_x2ap_UEContextRelease_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverCancel(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverCancel_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResetRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResetRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResetResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResetResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LoadInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_LoadInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_LoadInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellInformation_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellInformation_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellInformation_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellInformation_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellInformation_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellInformation_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCellsToModify_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCellsToModify(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCellsToModify_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Old_ECGIs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Old_ECGIs(tvb, offset, &asn1_ctx, tree, hf_x2ap_Old_ECGIs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellToReport_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellToReport_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellToReport_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellToReport_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellToReport_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellToReport_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportingPeriodicity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportingPeriodicity(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportingPeriodicity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PartialSuccessIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PartialSuccessIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_PartialSuccessIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementInitiationResult_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementInitiationResult_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementInitiationResult_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementInitiationResult_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementInitiationResult_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementInitiationResult_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementFailureCause_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementFailureCause_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementFailureCause_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompleteFailureCauseInformation_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompleteFailureCauseInformation_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompleteFailureCauseInformation_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompleteFailureCauseInformation_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompleteFailureCauseInformation_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompleteFailureCauseInformation_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusUpdate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellMeasurementResult_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellMeasurementResult_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellMeasurementResult_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellMeasurementResult_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellMeasurementResult_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellMeasurementResult_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_x2ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RLFIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RLFIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_RLFIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCellsToActivate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCellsToActivate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCellsToActivate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ActivatedCellList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ActivatedCellList(tvb, offset, &asn1_ctx, tree, hf_x2ap_ActivatedCellList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static void dissect_X2AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_x2ap_X2AP_PDU(tvb, 0, &asn1_ctx, tree, hf_x2ap_X2AP_PDU_PDU);
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(x2ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(x2ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(x2ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(x2ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(x2ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_x2ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *x2ap_item = NULL;
proto_tree *x2ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X2AP");
x2ap_item = proto_tree_add_item(tree, proto_x2ap, tvb, 0, -1, ENC_NA);
x2ap_tree = proto_item_add_subtree(x2ap_item, ett_x2ap);
dissect_X2AP_PDU_PDU(tvb, pinfo, x2ap_tree);
}
void proto_register_x2ap(void) {
static hf_register_info hf[] = {
{ &hf_x2ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "x2ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "x2ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "../../asn1/x2ap/packet-x2ap-hfarr.c"
{ &hf_x2ap_ABSInformation_PDU,
{ "ABSInformation", "x2ap.ABSInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_ABSInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ABS_Status_PDU,
{ "ABS-Status", "x2ap.ABS_Status",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Cause_PDU,
{ "Cause", "x2ap.Cause",
FT_UINT32, BASE_DEC, VALS(x2ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CompositeAvailableCapacityGroup_PDU,
{ "CompositeAvailableCapacityGroup", "x2ap.CompositeAvailableCapacityGroup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "x2ap.CriticalityDiagnostics",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CRNTI_PDU,
{ "CRNTI", "x2ap.CRNTI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "x2ap.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(x2ap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CSG_Id_PDU,
{ "CSG-Id", "x2ap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_DeactivationIndication_PDU,
{ "DeactivationIndication", "x2ap.DeactivationIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_DeactivationIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ECGI_PDU,
{ "ECGI", "x2ap.ECGI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RAB_List_PDU,
{ "E-RAB-List", "x2ap.E_RAB_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RAB_Item_PDU,
{ "E-RAB-Item", "x2ap.E_RAB_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_GlobalENB_ID_PDU,
{ "GlobalENB-ID", "x2ap.GlobalENB_ID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_GUGroupIDList_PDU,
{ "GUGroupIDList", "x2ap.GUGroupIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_GUMMEI_PDU,
{ "GUMMEI", "x2ap.GUMMEI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverReportType_PDU,
{ "HandoverReportType", "x2ap.HandoverReportType",
FT_UINT32, BASE_DEC, VALS(x2ap_HandoverReportType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_InvokeIndication_PDU,
{ "InvokeIndication", "x2ap.InvokeIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_InvokeIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_MDT_Configuration_PDU,
{ "MDT-Configuration", "x2ap.MDT_Configuration",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Measurement_ID_PDU,
{ "Measurement-ID", "x2ap.Measurement_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MBSFN_Subframe_Infolist_PDU,
{ "MBSFN-Subframe-Infolist", "x2ap.MBSFN_Subframe_Infolist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ManagementBasedMDTallowed_PDU,
{ "ManagementBasedMDTallowed", "x2ap.ManagementBasedMDTallowed",
FT_UINT32, BASE_DEC, VALS(x2ap_ManagementBasedMDTallowed_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityParametersModificationRange_PDU,
{ "MobilityParametersModificationRange", "x2ap.MobilityParametersModificationRange",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityParametersInformation_PDU,
{ "MobilityParametersInformation", "x2ap.MobilityParametersInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Number_of_Antennaports_PDU,
{ "Number-of-Antennaports", "x2ap.Number_of_Antennaports",
FT_UINT32, BASE_DEC, VALS(x2ap_Number_of_Antennaports_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_PCI_PDU,
{ "PCI", "x2ap.PCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PRACH_Configuration_PDU,
{ "PRACH-Configuration", "x2ap.PRACH_Configuration",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Registration_Request_PDU,
{ "Registration-Request", "x2ap.Registration_Request",
FT_UINT32, BASE_DEC, VALS(x2ap_Registration_Request_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_PDU,
{ "ReportCharacteristics", "x2ap.ReportCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RRCConnSetupIndicator_PDU,
{ "RRCConnSetupIndicator", "x2ap.RRCConnSetupIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_RRCConnSetupIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCells_PDU,
{ "ServedCells", "x2ap.ServedCells",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ShortMAC_I_PDU,
{ "ShortMAC-I", "x2ap.ShortMAC_I",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SRVCCOperationPossible_PDU,
{ "SRVCCOperationPossible", "x2ap.SRVCCOperationPossible",
FT_UINT32, BASE_DEC, VALS(x2ap_SRVCCOperationPossible_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_TargeteNBtoSource_eNBTransparentContainer_PDU,
{ "TargeteNBtoSource-eNBTransparentContainer", "x2ap.TargeteNBtoSource_eNBTransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TimeToWait_PDU,
{ "TimeToWait", "x2ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(x2ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_TraceActivation_PDU,
{ "TraceActivation", "x2ap.TraceActivation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_HistoryInformation_PDU,
{ "UE-HistoryInformation", "x2ap.UE_HistoryInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_X2AP_ID_PDU,
{ "UE-X2AP-ID", "x2ap.UE_X2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_RLF_Report_Container_PDU,
{ "UE-RLF-Report-Container", "x2ap.UE_RLF_Report_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverRequest_PDU,
{ "HandoverRequest", "x2ap.HandoverRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextInformation_PDU,
{ "UE-ContextInformation", "x2ap.UE_ContextInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetup_Item_PDU,
{ "E-RABs-ToBeSetup-Item", "x2ap.E_RABs_ToBeSetup_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverRequestAcknowledge_PDU,
{ "HandoverRequestAcknowledge", "x2ap.HandoverRequestAcknowledge",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_List_PDU,
{ "E-RABs-Admitted-List", "x2ap.E_RABs_Admitted_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_Item_PDU,
{ "E-RABs-Admitted-Item", "x2ap.E_RABs_Admitted_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverPreparationFailure_PDU,
{ "HandoverPreparationFailure", "x2ap.HandoverPreparationFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverReport_PDU,
{ "HandoverReport", "x2ap.HandoverReport",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SNStatusTransfer_PDU,
{ "SNStatusTransfer", "x2ap.SNStatusTransfer",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_List_PDU,
{ "E-RABs-SubjectToStatusTransfer-List", "x2ap.E_RABs_SubjectToStatusTransfer_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_Item_PDU,
{ "E-RABs-SubjectToStatusTransfer-Item", "x2ap.E_RABs_SubjectToStatusTransfer_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UEContextRelease_PDU,
{ "UEContextRelease", "x2ap.UEContextRelease",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverCancel_PDU,
{ "HandoverCancel", "x2ap.HandoverCancel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ErrorIndication_PDU,
{ "ErrorIndication", "x2ap.ErrorIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResetRequest_PDU,
{ "ResetRequest", "x2ap.ResetRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResetResponse_PDU,
{ "ResetResponse", "x2ap.ResetResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupRequest_PDU,
{ "X2SetupRequest", "x2ap.X2SetupRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupResponse_PDU,
{ "X2SetupResponse", "x2ap.X2SetupResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupFailure_PDU,
{ "X2SetupFailure", "x2ap.X2SetupFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_LoadInformation_PDU,
{ "LoadInformation", "x2ap.LoadInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellInformation_List_PDU,
{ "CellInformation-List", "x2ap.CellInformation_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellInformation_Item_PDU,
{ "CellInformation-Item", "x2ap.CellInformation_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdate_PDU,
{ "ENBConfigurationUpdate", "x2ap.ENBConfigurationUpdate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToModify_PDU,
{ "ServedCellsToModify", "x2ap.ServedCellsToModify",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Old_ECGIs_PDU,
{ "Old-ECGIs", "x2ap.Old_ECGIs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdateAcknowledge_PDU,
{ "ENBConfigurationUpdateAcknowledge", "x2ap.ENBConfigurationUpdateAcknowledge",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdateFailure_PDU,
{ "ENBConfigurationUpdateFailure", "x2ap.ENBConfigurationUpdateFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusRequest_PDU,
{ "ResourceStatusRequest", "x2ap.ResourceStatusRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_List_PDU,
{ "CellToReport-List", "x2ap.CellToReport_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_Item_PDU,
{ "CellToReport-Item", "x2ap.CellToReport_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ReportingPeriodicity_PDU,
{ "ReportingPeriodicity", "x2ap.ReportingPeriodicity",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportingPeriodicity_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_PartialSuccessIndicator_PDU,
{ "PartialSuccessIndicator", "x2ap.PartialSuccessIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_PartialSuccessIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusResponse_PDU,
{ "ResourceStatusResponse", "x2ap.ResourceStatusResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_List_PDU,
{ "MeasurementInitiationResult-List", "x2ap.MeasurementInitiationResult_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_Item_PDU,
{ "MeasurementInitiationResult-Item", "x2ap.MeasurementInitiationResult_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementFailureCause_Item_PDU,
{ "MeasurementFailureCause-Item", "x2ap.MeasurementFailureCause_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusFailure_PDU,
{ "ResourceStatusFailure", "x2ap.ResourceStatusFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_List_PDU,
{ "CompleteFailureCauseInformation-List", "x2ap.CompleteFailureCauseInformation_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_Item_PDU,
{ "CompleteFailureCauseInformation-Item", "x2ap.CompleteFailureCauseInformation_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusUpdate_PDU,
{ "ResourceStatusUpdate", "x2ap.ResourceStatusUpdate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_List_PDU,
{ "CellMeasurementResult-List", "x2ap.CellMeasurementResult_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_Item_PDU,
{ "CellMeasurementResult-Item", "x2ap.CellMeasurementResult_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PrivateMessage_PDU,
{ "PrivateMessage", "x2ap.PrivateMessage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeRequest_PDU,
{ "MobilityChangeRequest", "x2ap.MobilityChangeRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeAcknowledge_PDU,
{ "MobilityChangeAcknowledge", "x2ap.MobilityChangeAcknowledge",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeFailure_PDU,
{ "MobilityChangeFailure", "x2ap.MobilityChangeFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RLFIndication_PDU,
{ "RLFIndication", "x2ap.RLFIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationRequest_PDU,
{ "CellActivationRequest", "x2ap.CellActivationRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToActivate_PDU,
{ "ServedCellsToActivate", "x2ap.ServedCellsToActivate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationResponse_PDU,
{ "CellActivationResponse", "x2ap.CellActivationResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ActivatedCellList_PDU,
{ "ActivatedCellList", "x2ap.ActivatedCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationFailure_PDU,
{ "CellActivationFailure", "x2ap.CellActivationFailure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2AP_PDU_PDU,
{ "X2AP-PDU", "x2ap.X2AP_PDU",
FT_UINT32, BASE_DEC, VALS(x2ap_X2AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_local,
{ "local", "x2ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxPrivateIEs", HFILL }},
{ &hf_x2ap_global,
{ "global", "x2ap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x2ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "x2ap.ProtocolIE_Field",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC, VALS(x2ap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_criticality,
{ "criticality", "x2ap.criticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_protocolIE_Field_value,
{ "value", "x2ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"ProtocolIE_Field_value", HFILL }},
{ &hf_x2ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "x2ap.ProtocolExtensionField",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_extension_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC, VALS(x2ap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_extensionValue,
{ "extensionValue", "x2ap.extensionValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "x2ap.PrivateIE_Field",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_private_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC, VALS(x2ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_x2ap_privateIE_Field_value,
{ "value", "x2ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"PrivateIE_Field_value", HFILL }},
{ &hf_x2ap_fdd,
{ "fdd", "x2ap.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"ABSInformationFDD", HFILL }},
{ &hf_x2ap_tdd,
{ "tdd", "x2ap.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"ABSInformationTDD", HFILL }},
{ &hf_x2ap_abs_inactive,
{ "abs-inactive", "x2ap.abs_inactive",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_abs_pattern_info,
{ "abs-pattern-info", "x2ap.abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_measurement_subset,
{ "measurement-subset", "x2ap.measurement_subset",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_iE_Extensions,
{ "iE-Extensions", "x2ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_x2ap_abs_pattern_info_01,
{ "abs-pattern-info", "x2ap.abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts_01,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_01_vals), 0,
"T_numberOfCellSpecificAntennaPorts_01", HFILL }},
{ &hf_x2ap_measurement_subset_01,
{ "measurement-subset", "x2ap.measurement_subset",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_dL_ABS_status,
{ "dL-ABS-status", "x2ap.dL_ABS_status",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_usableABSInformation,
{ "usableABSInformation", "x2ap.usableABSInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_UsableABSInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_key_eNodeB_star,
{ "key-eNodeB-star", "x2ap.key_eNodeB_star",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_nextHopChainingCount,
{ "nextHopChainingCount", "x2ap.nextHopChainingCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_priorityLevel,
{ "priorityLevel", "x2ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(x2ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_pre_emptionCapability,
{ "pre-emptionCapability", "x2ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(x2ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "x2ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(x2ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cellBased,
{ "cellBased", "x2ap.cellBased",
FT_NONE, BASE_NONE, NULL, 0,
"CellBasedMDT", HFILL }},
{ &hf_x2ap_tABased,
{ "tABased", "x2ap.tABased",
FT_NONE, BASE_NONE, NULL, 0,
"TABasedMDT", HFILL }},
{ &hf_x2ap_pLMNWide,
{ "pLMNWide", "x2ap.pLMNWide",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_BroadcastPLMNs_Item_item,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioNetwork,
{ "radioNetwork", "x2ap.radioNetwork",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_x2ap_transport,
{ "transport", "x2ap.transport",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_x2ap_protocol,
{ "protocol", "x2ap.protocol",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_x2ap_misc,
{ "misc", "x2ap.misc",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_x2ap_cellIdListforMDT,
{ "cellIdListforMDT", "x2ap.cellIdListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellIdListforMDT_item,
{ "ECGI", "x2ap.ECGI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cell_Size,
{ "cell-Size", "x2ap.cell_Size",
FT_UINT32, BASE_DEC, VALS(x2ap_Cell_Size_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_dL_CompositeAvailableCapacity,
{ "dL-CompositeAvailableCapacity", "x2ap.dL_CompositeAvailableCapacity",
FT_NONE, BASE_NONE, NULL, 0,
"CompositeAvailableCapacity", HFILL }},
{ &hf_x2ap_uL_CompositeAvailableCapacity,
{ "uL-CompositeAvailableCapacity", "x2ap.uL_CompositeAvailableCapacity",
FT_NONE, BASE_NONE, NULL, 0,
"CompositeAvailableCapacity", HFILL }},
{ &hf_x2ap_cellCapacityClassValue,
{ "cellCapacityClassValue", "x2ap.cellCapacityClassValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_capacityValue,
{ "capacityValue", "x2ap.capacityValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pDCP_SN,
{ "pDCP-SN", "x2ap.pDCP_SN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hFN,
{ "hFN", "x2ap.hFN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_procedureCode,
{ "procedureCode", "x2ap.procedureCode",
FT_UINT32, BASE_DEC, VALS(x2ap_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_triggeringMessage,
{ "triggeringMessage", "x2ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(x2ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_procedureCriticality,
{ "procedureCriticality", "x2ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_x2ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "x2ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_x2ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "x2ap.CriticalityDiagnostics_IE_List_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_iECriticality,
{ "iECriticality", "x2ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_x2ap_iE_ID,
{ "iE-ID", "x2ap.iE_ID",
FT_UINT32, BASE_DEC, VALS(x2ap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_typeOfError,
{ "typeOfError", "x2ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(x2ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_uL_EARFCN,
{ "uL-EARFCN", "x2ap.uL_EARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_x2ap_dL_EARFCN,
{ "dL-EARFCN", "x2ap.dL_EARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_x2ap_uL_Transmission_Bandwidth,
{ "uL-Transmission-Bandwidth", "x2ap.uL_Transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
"Transmission_Bandwidth", HFILL }},
{ &hf_x2ap_dL_Transmission_Bandwidth,
{ "dL-Transmission-Bandwidth", "x2ap.dL_Transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
"Transmission_Bandwidth", HFILL }},
{ &hf_x2ap_eARFCN,
{ "eARFCN", "x2ap.eARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transmission_Bandwidth,
{ "transmission-Bandwidth", "x2ap.transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_subframeAssignment,
{ "subframeAssignment", "x2ap.subframeAssignment",
FT_UINT32, BASE_DEC, VALS(x2ap_SubframeAssignment_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_specialSubframe_Info,
{ "specialSubframe-Info", "x2ap.specialSubframe_Info",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_fDD,
{ "fDD", "x2ap.fDD",
FT_NONE, BASE_NONE, NULL, 0,
"FDD_Info", HFILL }},
{ &hf_x2ap_tDD,
{ "tDD", "x2ap.tDD",
FT_NONE, BASE_NONE, NULL, 0,
"TDD_Info", HFILL }},
{ &hf_x2ap_pLMN_Identity,
{ "pLMN-Identity", "x2ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eUTRANcellIdentifier,
{ "eUTRANcellIdentifier", "x2ap.eUTRANcellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_macro_eNB_ID,
{ "macro-eNB-ID", "x2ap.macro_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_x2ap_home_eNB_ID,
{ "home-eNB-ID", "x2ap.home_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_x2ap_EPLMNs_item,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_qCI,
{ "qCI", "x2ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_allocationAndRetentionPriority,
{ "allocationAndRetentionPriority", "x2ap.allocationAndRetentionPriority",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gbrQosInformation,
{ "gbrQosInformation", "x2ap.gbrQosInformation",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_x2ap_E_RAB_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_ID,
{ "e-RAB-ID", "x2ap.e_RAB_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cause,
{ "cause", "x2ap.cause",
FT_UINT32, BASE_DEC, VALS(x2ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenTAs_item,
{ "ForbiddenTAs-Item", "x2ap.ForbiddenTAs_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenTACs,
{ "forbiddenTACs", "x2ap.forbiddenTACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenTACs_item,
{ "TAC", "x2ap.TAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenLAs_item,
{ "ForbiddenLAs-Item", "x2ap.ForbiddenLAs_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenLACs,
{ "forbiddenLACs", "x2ap.forbiddenLACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenLACs_item,
{ "LAC", "x2ap.LAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_MaximumBitrateDL,
{ "e-RAB-MaximumBitrateDL", "x2ap.e_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_MaximumBitrateUL,
{ "e-RAB-MaximumBitrateUL", "x2ap.e_RAB_MaximumBitrateUL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_GuaranteedBitrateDL,
{ "e-RAB-GuaranteedBitrateDL", "x2ap.e_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_GuaranteedBitrateUL,
{ "e-RAB-GuaranteedBitrateUL", "x2ap.e_RAB_GuaranteedBitrateUL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_eNB_ID,
{ "eNB-ID", "x2ap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(x2ap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_transportLayerAddress,
{ "transportLayerAddress", "x2ap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gTP_TEID,
{ "gTP-TEID", "x2ap.gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEI", HFILL }},
{ &hf_x2ap_GUGroupIDList_item,
{ "GU-Group-ID", "x2ap.GU_Group_ID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_mME_Group_ID,
{ "mME-Group-ID", "x2ap.mME_Group_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gU_Group_ID,
{ "gU-Group-ID", "x2ap.gU_Group_ID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_mME_Code,
{ "mME-Code", "x2ap.mME_Code",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_servingPLMN,
{ "servingPLMN", "x2ap.servingPLMN",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Identity", HFILL }},
{ &hf_x2ap_equivalentPLMNs,
{ "equivalentPLMNs", "x2ap.equivalentPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"EPLMNs", HFILL }},
{ &hf_x2ap_forbiddenTAs,
{ "forbiddenTAs", "x2ap.forbiddenTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenLAs,
{ "forbiddenLAs", "x2ap.forbiddenLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenInterRATs,
{ "forbiddenInterRATs", "x2ap.forbiddenInterRATs",
FT_UINT32, BASE_DEC, VALS(x2ap_ForbiddenInterRATs_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_dLHWLoadIndicator,
{ "dLHWLoadIndicator", "x2ap.dLHWLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_uLHWLoadIndicator,
{ "uLHWLoadIndicator", "x2ap.uLHWLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_e_UTRAN_Cell,
{ "e-UTRAN-Cell", "x2ap.e_UTRAN_Cell",
FT_NONE, BASE_NONE, NULL, 0,
"LastVisitedEUTRANCellInformation", HFILL }},
{ &hf_x2ap_uTRAN_Cell,
{ "uTRAN-Cell", "x2ap.uTRAN_Cell",
FT_BYTES, BASE_NONE, NULL, 0,
"LastVisitedUTRANCellInformation", HFILL }},
{ &hf_x2ap_gERAN_Cell,
{ "gERAN-Cell", "x2ap.gERAN_Cell",
FT_UINT32, BASE_DEC, VALS(x2ap_LastVisitedGERANCellInformation_vals), 0,
"LastVisitedGERANCellInformation", HFILL }},
{ &hf_x2ap_global_Cell_ID,
{ "global-Cell-ID", "x2ap.global_Cell_ID",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_cellType,
{ "cellType", "x2ap.cellType",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_time_UE_StayedInCell,
{ "time-UE-StayedInCell", "x2ap.time_UE_StayedInCell",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_undefined,
{ "undefined", "x2ap.undefined",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eventType,
{ "eventType", "x2ap.eventType",
FT_UINT32, BASE_DEC, VALS(x2ap_EventType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_reportArea,
{ "reportArea", "x2ap.reportArea",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportArea_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_mdt_Activation,
{ "mdt-Activation", "x2ap.mdt_Activation",
FT_UINT32, BASE_DEC, VALS(x2ap_MDT_Activation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_areaScopeOfMDT,
{ "areaScopeOfMDT", "x2ap.areaScopeOfMDT",
FT_UINT32, BASE_DEC, VALS(x2ap_AreaScopeOfMDT_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate,
{ "measurementsToActivate", "x2ap.measurementsToActivate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_reportingTriggerMDT,
{ "reportingTriggerMDT", "x2ap.reportingTriggerMDT",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportingTriggerMDT_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_thresholdeventA2,
{ "thresholdeventA2", "x2ap.thresholdeventA2",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_periodicReportingMDT,
{ "periodicReportingMDT", "x2ap.periodicReportingMDT",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_threshold_RSRP,
{ "threshold-RSRP", "x2ap.threshold_RSRP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_threshold_RSRQ,
{ "threshold-RSRQ", "x2ap.threshold_RSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MBSFN_Subframe_Infolist_item,
{ "MBSFN-Subframe-Info", "x2ap.MBSFN_Subframe_Info",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioframeAllocationPeriod,
{ "radioframeAllocationPeriod", "x2ap.radioframeAllocationPeriod",
FT_UINT32, BASE_DEC, VALS(x2ap_RadioframeAllocationPeriod_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_radioframeAllocationOffset,
{ "radioframeAllocationOffset", "x2ap.radioframeAllocationOffset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subframeAllocation,
{ "subframeAllocation", "x2ap.subframeAllocation",
FT_UINT32, BASE_DEC, VALS(x2ap_SubframeAllocation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_handoverTriggerChangeLowerLimit,
{ "handoverTriggerChangeLowerLimit", "x2ap.handoverTriggerChangeLowerLimit",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_handoverTriggerChangeUpperLimit,
{ "handoverTriggerChangeUpperLimit", "x2ap.handoverTriggerChangeUpperLimit",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_handoverTriggerChange,
{ "handoverTriggerChange", "x2ap.handoverTriggerChange",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_Neighbour_Information_item,
{ "Neighbour-Information item", "x2ap.Neighbour_Information_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eCGI,
{ "eCGI", "x2ap.eCGI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pCI,
{ "pCI", "x2ap.pCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_reportInterval,
{ "reportInterval", "x2ap.reportInterval",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportIntervalMDT_vals), 0,
"ReportIntervalMDT", HFILL }},
{ &hf_x2ap_reportAmount,
{ "reportAmount", "x2ap.reportAmount",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportAmountMDT_vals), 0,
"ReportAmountMDT", HFILL }},
{ &hf_x2ap_rootSequenceIndex,
{ "rootSequenceIndex", "x2ap.rootSequenceIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_837", HFILL }},
{ &hf_x2ap_zeroCorrelationIndex,
{ "zeroCorrelationIndex", "x2ap.zeroCorrelationIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_x2ap_highSpeedFlag,
{ "highSpeedFlag", "x2ap.highSpeedFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x2ap_prach_FreqOffset,
{ "prach-FreqOffset", "x2ap.prach_FreqOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_94", HFILL }},
{ &hf_x2ap_prach_ConfigIndex,
{ "prach-ConfigIndex", "x2ap.prach_ConfigIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_x2ap_dL_GBR_PRB_usage,
{ "dL-GBR-PRB-usage", "x2ap.dL_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GBR_PRB_usage,
{ "uL-GBR-PRB-usage", "x2ap.uL_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_non_GBR_PRB_usage,
{ "dL-non-GBR-PRB-usage", "x2ap.dL_non_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_non_GBR_PRB_usage,
{ "uL-non-GBR-PRB-usage", "x2ap.uL_non_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_Total_PRB_usage,
{ "dL-Total-PRB-usage", "x2ap.dL_Total_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_Total_PRB_usage,
{ "uL-Total-PRB-usage", "x2ap.uL_Total_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rNTP_PerPRB,
{ "rNTP-PerPRB", "x2ap.rNTP_PerPRB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6_110_", HFILL }},
{ &hf_x2ap_rNTP_Threshold,
{ "rNTP-Threshold", "x2ap.rNTP_Threshold",
FT_UINT32, BASE_DEC, VALS(x2ap_RNTP_Threshold_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts_02,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_02_vals), 0,
"T_numberOfCellSpecificAntennaPorts_02", HFILL }},
{ &hf_x2ap_p_B,
{ "p-B", "x2ap.p_B",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3_", HFILL }},
{ &hf_x2ap_pDCCH_InterferenceImpact,
{ "pDCCH-InterferenceImpact", "x2ap.pDCCH_InterferenceImpact",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4_", HFILL }},
{ &hf_x2ap_dLS1TNLLoadIndicator,
{ "dLS1TNLLoadIndicator", "x2ap.dLS1TNLLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_uLS1TNLLoadIndicator,
{ "uLS1TNLLoadIndicator", "x2ap.uLS1TNLLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_ServedCells_item,
{ "ServedCells item", "x2ap.ServedCells_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_servedCellInfo,
{ "servedCellInfo", "x2ap.servedCellInfo",
FT_NONE, BASE_NONE, NULL, 0,
"ServedCell_Information", HFILL }},
{ &hf_x2ap_neighbour_Info,
{ "neighbour-Info", "x2ap.neighbour_Info",
FT_UINT32, BASE_DEC, NULL, 0,
"Neighbour_Information", HFILL }},
{ &hf_x2ap_cellId,
{ "cellId", "x2ap.cellId",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_tAC,
{ "tAC", "x2ap.tAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_broadcastPLMNs,
{ "broadcastPLMNs", "x2ap.broadcastPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"BroadcastPLMNs_Item", HFILL }},
{ &hf_x2ap_eUTRA_Mode_Info,
{ "eUTRA-Mode-Info", "x2ap.eUTRA_Mode_Info",
FT_UINT32, BASE_DEC, VALS(x2ap_EUTRA_Mode_Info_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_specialSubframePatterns,
{ "specialSubframePatterns", "x2ap.specialSubframePatterns",
FT_UINT32, BASE_DEC, VALS(x2ap_SpecialSubframePatterns_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cyclicPrefixDL,
{ "cyclicPrefixDL", "x2ap.cyclicPrefixDL",
FT_UINT32, BASE_DEC, VALS(x2ap_CyclicPrefixDL_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cyclicPrefixUL,
{ "cyclicPrefixUL", "x2ap.cyclicPrefixUL",
FT_UINT32, BASE_DEC, VALS(x2ap_CyclicPrefixUL_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_oneframe,
{ "oneframe", "x2ap.oneframe",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_fourframes,
{ "fourframes", "x2ap.fourframes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_tAListforMDT,
{ "tAListforMDT", "x2ap.tAListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TAListforMDT_item,
{ "TAC", "x2ap.TAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_measurementThreshold,
{ "measurementThreshold", "x2ap.measurementThreshold",
FT_UINT32, BASE_DEC, VALS(x2ap_MeasurementThresholdA2_vals), 0,
"MeasurementThresholdA2", HFILL }},
{ &hf_x2ap_eUTRANTraceID,
{ "eUTRANTraceID", "x2ap.eUTRANTraceID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace,
{ "interfacesToTrace", "x2ap.interfacesToTrace",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_traceDepth,
{ "traceDepth", "x2ap.traceDepth",
FT_UINT32, BASE_DEC, VALS(x2ap_TraceDepth_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_traceCollectionEntityIPAddress,
{ "traceCollectionEntityIPAddress", "x2ap.traceCollectionEntityIPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_HistoryInformation_item,
{ "LastVisitedCell-Item", "x2ap.LastVisitedCell_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_LastVisitedCell_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRateDownlink,
{ "uEaggregateMaximumBitRateDownlink", "x2ap.uEaggregateMaximumBitRateDownlink",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRateUplink,
{ "uEaggregateMaximumBitRateUplink", "x2ap.uEaggregateMaximumBitRateUplink",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_x2ap_encryptionAlgorithms,
{ "encryptionAlgorithms", "x2ap.encryptionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms,
{ "integrityProtectionAlgorithms", "x2ap.integrityProtectionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UL_InterferenceOverloadIndication_item,
{ "UL-InterferenceOverloadIndication-Item", "x2ap.UL_InterferenceOverloadIndication_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_UL_InterferenceOverloadIndication_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_UL_HighInterferenceIndicationInfo_item,
{ "UL-HighInterferenceIndicationInfo-Item", "x2ap.UL_HighInterferenceIndicationInfo_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_target_Cell_ID,
{ "target-Cell-ID", "x2ap.target_Cell_ID",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_ul_interferenceindication,
{ "ul-interferenceindication", "x2ap.ul_interferenceindication",
FT_BYTES, BASE_NONE, NULL, 0,
"UL_HighInterferenceIndication", HFILL }},
{ &hf_x2ap_fdd_01,
{ "fdd", "x2ap.fdd",
FT_NONE, BASE_NONE, NULL, 0,
"UsableABSInformationFDD", HFILL }},
{ &hf_x2ap_tdd_01,
{ "tdd", "x2ap.tdd",
FT_NONE, BASE_NONE, NULL, 0,
"UsableABSInformationTDD", HFILL }},
{ &hf_x2ap_usable_abs_pattern_info,
{ "usable-abs-pattern-info", "x2ap.usable_abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_usaable_abs_pattern_info,
{ "usaable-abs-pattern-info", "x2ap.usaable_abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_protocolIEs,
{ "protocolIEs", "x2ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_x2ap_mME_UE_S1AP_ID,
{ "mME-UE-S1AP-ID", "x2ap.mME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_S1AP_ID", HFILL }},
{ &hf_x2ap_uESecurityCapabilities,
{ "uESecurityCapabilities", "x2ap.uESecurityCapabilities",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_aS_SecurityInformation,
{ "aS-SecurityInformation", "x2ap.aS_SecurityInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRate,
{ "uEaggregateMaximumBitRate", "x2ap.uEaggregateMaximumBitRate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subscriberProfileIDforRFP,
{ "subscriberProfileIDforRFP", "x2ap.subscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RABs_ToBeSetup_List,
{ "e-RABs-ToBeSetup-List", "x2ap.e_RABs_ToBeSetup_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rRC_Context,
{ "rRC-Context", "x2ap.rRC_Context",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_handoverRestrictionList,
{ "handoverRestrictionList", "x2ap.handoverRestrictionList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_locationReportingInformation,
{ "locationReportingInformation", "x2ap.locationReportingInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetup_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_Level_QoS_Parameters,
{ "e-RAB-Level-QoS-Parameters", "x2ap.e_RAB_Level_QoS_Parameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_Forwarding,
{ "dL-Forwarding", "x2ap.dL_Forwarding",
FT_UINT32, BASE_DEC, VALS(x2ap_DL_Forwarding_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GTPtunnelEndpoint,
{ "uL-GTPtunnelEndpoint", "x2ap.uL_GTPtunnelEndpoint",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GTP_TunnelEndpoint,
{ "uL-GTP-TunnelEndpoint", "x2ap.uL_GTP_TunnelEndpoint",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_dL_GTP_TunnelEndpoint,
{ "dL-GTP-TunnelEndpoint", "x2ap.dL_GTP_TunnelEndpoint",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_receiveStatusofULPDCPSDUs,
{ "receiveStatusofULPDCPSDUs", "x2ap.receiveStatusofULPDCPSDUs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_COUNTvalue,
{ "uL-COUNTvalue", "x2ap.uL_COUNTvalue",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_x2ap_dL_COUNTvalue,
{ "dL-COUNTvalue", "x2ap.dL_COUNTvalue",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_x2ap_CellInformation_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cell_ID,
{ "cell-ID", "x2ap.cell_ID",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_ul_InterferenceOverloadIndication,
{ "ul-InterferenceOverloadIndication", "x2ap.ul_InterferenceOverloadIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ul_HighInterferenceIndicationInfo,
{ "ul-HighInterferenceIndicationInfo", "x2ap.ul_HighInterferenceIndicationInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_relativeNarrowbandTxPower,
{ "relativeNarrowbandTxPower", "x2ap.relativeNarrowbandTxPower",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToModify_item,
{ "ServedCellsToModify-Item", "x2ap.ServedCellsToModify_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_old_ecgi,
{ "old-ecgi", "x2ap.old_ecgi",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_Old_ECGIs_item,
{ "ECGI", "x2ap.ECGI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_measurementFailureCause_List,
{ "measurementFailureCause-List", "x2ap.measurementFailureCause_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementFailureCause_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics,
{ "measurementFailedReportCharacteristics", "x2ap.measurementFailedReportCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
"ReportCharacteristics", HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hWLoadIndicator,
{ "hWLoadIndicator", "x2ap.hWLoadIndicator",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_s1TNLLoadIndicator,
{ "s1TNLLoadIndicator", "x2ap.s1TNLLoadIndicator",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioResourceStatus,
{ "radioResourceStatus", "x2ap.radioResourceStatus",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_privateIEs,
{ "privateIEs", "x2ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_x2ap_ServedCellsToActivate_item,
{ "ServedCellsToActivate-Item", "x2ap.ServedCellsToActivate_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ecgi,
{ "ecgi", "x2ap.ecgi",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ActivatedCellList_item,
{ "ActivatedCellList-Item", "x2ap.ActivatedCellList_Item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_initiatingMessage,
{ "initiatingMessage", "x2ap.initiatingMessage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_successfulOutcome,
{ "successfulOutcome", "x2ap.successfulOutcome",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "x2ap.unsuccessfulOutcome",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_initiatingMessage_value,
{ "value", "x2ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_x2ap_successfulOutcome_value,
{ "value", "x2ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_x2ap_value,
{ "value", "x2ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 150 "../../asn1/x2ap/packet-x2ap-template.c"
};
static gint *ett[] = {
&ett_x2ap,
&ett_x2ap_TransportLayerAddress,
#line 1 "../../asn1/x2ap/packet-x2ap-ettarr.c"
&ett_x2ap_PrivateIE_ID,
&ett_x2ap_ProtocolIE_Container,
&ett_x2ap_ProtocolIE_Field,
&ett_x2ap_ProtocolExtensionContainer,
&ett_x2ap_ProtocolExtensionField,
&ett_x2ap_PrivateIE_Container,
&ett_x2ap_PrivateIE_Field,
&ett_x2ap_ABSInformation,
&ett_x2ap_ABSInformationFDD,
&ett_x2ap_ABSInformationTDD,
&ett_x2ap_ABS_Status,
&ett_x2ap_AS_SecurityInformation,
&ett_x2ap_AllocationAndRetentionPriority,
&ett_x2ap_AreaScopeOfMDT,
&ett_x2ap_BroadcastPLMNs_Item,
&ett_x2ap_Cause,
&ett_x2ap_CellBasedMDT,
&ett_x2ap_CellIdListforMDT,
&ett_x2ap_CellType,
&ett_x2ap_CompositeAvailableCapacityGroup,
&ett_x2ap_CompositeAvailableCapacity,
&ett_x2ap_COUNTvalue,
&ett_x2ap_CriticalityDiagnostics,
&ett_x2ap_CriticalityDiagnostics_IE_List,
&ett_x2ap_CriticalityDiagnostics_IE_List_item,
&ett_x2ap_FDD_Info,
&ett_x2ap_TDD_Info,
&ett_x2ap_EUTRA_Mode_Info,
&ett_x2ap_ECGI,
&ett_x2ap_ENB_ID,
&ett_x2ap_EPLMNs,
&ett_x2ap_E_RAB_Level_QoS_Parameters,
&ett_x2ap_E_RAB_List,
&ett_x2ap_E_RAB_Item,
&ett_x2ap_ForbiddenTAs,
&ett_x2ap_ForbiddenTAs_Item,
&ett_x2ap_ForbiddenTACs,
&ett_x2ap_ForbiddenLAs,
&ett_x2ap_ForbiddenLAs_Item,
&ett_x2ap_ForbiddenLACs,
&ett_x2ap_GBR_QosInformation,
&ett_x2ap_GlobalENB_ID,
&ett_x2ap_GTPtunnelEndpoint,
&ett_x2ap_GUGroupIDList,
&ett_x2ap_GU_Group_ID,
&ett_x2ap_GUMMEI,
&ett_x2ap_HandoverRestrictionList,
&ett_x2ap_HWLoadIndicator,
&ett_x2ap_LastVisitedCell_Item,
&ett_x2ap_LastVisitedEUTRANCellInformation,
&ett_x2ap_LastVisitedGERANCellInformation,
&ett_x2ap_LocationReportingInformation,
&ett_x2ap_MDT_Configuration,
&ett_x2ap_MeasurementThresholdA2,
&ett_x2ap_MBSFN_Subframe_Infolist,
&ett_x2ap_MBSFN_Subframe_Info,
&ett_x2ap_MobilityParametersModificationRange,
&ett_x2ap_MobilityParametersInformation,
&ett_x2ap_Neighbour_Information,
&ett_x2ap_Neighbour_Information_item,
&ett_x2ap_PeriodicReportingMDT,
&ett_x2ap_PRACH_Configuration,
&ett_x2ap_RadioResourceStatus,
&ett_x2ap_RelativeNarrowbandTxPower,
&ett_x2ap_S1TNLLoadIndicator,
&ett_x2ap_ServedCells,
&ett_x2ap_ServedCells_item,
&ett_x2ap_ServedCell_Information,
&ett_x2ap_SpecialSubframe_Info,
&ett_x2ap_SubframeAllocation,
&ett_x2ap_TABasedMDT,
&ett_x2ap_TAListforMDT,
&ett_x2ap_ThresholdEventA2,
&ett_x2ap_TraceActivation,
&ett_x2ap_UE_HistoryInformation,
&ett_x2ap_UEAggregateMaximumBitRate,
&ett_x2ap_UESecurityCapabilities,
&ett_x2ap_UL_InterferenceOverloadIndication,
&ett_x2ap_UL_HighInterferenceIndicationInfo,
&ett_x2ap_UL_HighInterferenceIndicationInfo_Item,
&ett_x2ap_UsableABSInformation,
&ett_x2ap_UsableABSInformationFDD,
&ett_x2ap_UsableABSInformationTDD,
&ett_x2ap_HandoverRequest,
&ett_x2ap_UE_ContextInformation,
&ett_x2ap_E_RABs_ToBeSetup_List,
&ett_x2ap_E_RABs_ToBeSetup_Item,
&ett_x2ap_HandoverRequestAcknowledge,
&ett_x2ap_E_RABs_Admitted_List,
&ett_x2ap_E_RABs_Admitted_Item,
&ett_x2ap_HandoverPreparationFailure,
&ett_x2ap_HandoverReport,
&ett_x2ap_SNStatusTransfer,
&ett_x2ap_E_RABs_SubjectToStatusTransfer_List,
&ett_x2ap_E_RABs_SubjectToStatusTransfer_Item,
&ett_x2ap_UEContextRelease,
&ett_x2ap_HandoverCancel,
&ett_x2ap_ErrorIndication,
&ett_x2ap_ResetRequest,
&ett_x2ap_ResetResponse,
&ett_x2ap_X2SetupRequest,
&ett_x2ap_X2SetupResponse,
&ett_x2ap_X2SetupFailure,
&ett_x2ap_LoadInformation,
&ett_x2ap_CellInformation_List,
&ett_x2ap_CellInformation_Item,
&ett_x2ap_ENBConfigurationUpdate,
&ett_x2ap_ServedCellsToModify,
&ett_x2ap_ServedCellsToModify_Item,
&ett_x2ap_Old_ECGIs,
&ett_x2ap_ENBConfigurationUpdateAcknowledge,
&ett_x2ap_ENBConfigurationUpdateFailure,
&ett_x2ap_ResourceStatusRequest,
&ett_x2ap_CellToReport_List,
&ett_x2ap_CellToReport_Item,
&ett_x2ap_ResourceStatusResponse,
&ett_x2ap_MeasurementInitiationResult_List,
&ett_x2ap_MeasurementInitiationResult_Item,
&ett_x2ap_MeasurementFailureCause_List,
&ett_x2ap_MeasurementFailureCause_Item,
&ett_x2ap_ResourceStatusFailure,
&ett_x2ap_CompleteFailureCauseInformation_List,
&ett_x2ap_CompleteFailureCauseInformation_Item,
&ett_x2ap_ResourceStatusUpdate,
&ett_x2ap_CellMeasurementResult_List,
&ett_x2ap_CellMeasurementResult_Item,
&ett_x2ap_PrivateMessage,
&ett_x2ap_MobilityChangeRequest,
&ett_x2ap_MobilityChangeAcknowledge,
&ett_x2ap_MobilityChangeFailure,
&ett_x2ap_RLFIndication,
&ett_x2ap_CellActivationRequest,
&ett_x2ap_ServedCellsToActivate,
&ett_x2ap_ServedCellsToActivate_Item,
&ett_x2ap_CellActivationResponse,
&ett_x2ap_ActivatedCellList,
&ett_x2ap_ActivatedCellList_Item,
&ett_x2ap_CellActivationFailure,
&ett_x2ap_X2AP_PDU,
&ett_x2ap_InitiatingMessage,
&ett_x2ap_SuccessfulOutcome,
&ett_x2ap_UnsuccessfulOutcome,
#line 157 "../../asn1/x2ap/packet-x2ap-template.c"
};
module_t *x2ap_module;
proto_x2ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x2ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("x2ap", dissect_x2ap, proto_x2ap);
x2ap_ies_dissector_table = register_dissector_table("x2ap.ies", "X2AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
x2ap_extension_dissector_table = register_dissector_table("x2ap.extension", "X2AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
x2ap_proc_imsg_dissector_table = register_dissector_table("x2ap.proc.imsg", "X2AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
x2ap_proc_sout_dissector_table = register_dissector_table("x2ap.proc.sout", "X2AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
x2ap_proc_uout_dissector_table = register_dissector_table("x2ap.proc.uout", "X2AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
x2ap_module = prefs_register_protocol(proto_x2ap, proto_reg_handoff_x2ap);
prefs_register_uint_preference(x2ap_module, "sctp.port",
"X2AP SCTP Port",
"Set the SCTP port for X2AP messages",
10,
&gbl_x2apSctpPort);
}
void
proto_reg_handoff_x2ap(void)
{
dissector_handle_t x2ap_handle;
static gboolean Initialized=FALSE;
static guint SctpPort;
x2ap_handle = find_dissector("x2ap");
if (!Initialized) {
dissector_add_handle("sctp.port", x2ap_handle);
dissector_add_uint("sctp.ppi", X2AP_PAYLOAD_PROTOCOL_ID, x2ap_handle);
Initialized=TRUE;
#line 1 "../../asn1/x2ap/packet-x2ap-dis-tab.c"
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_Item, new_create_dissector_handle(dissect_E_RABs_Admitted_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_List, new_create_dissector_handle(dissect_E_RABs_Admitted_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RAB_Item, new_create_dissector_handle(dissect_E_RAB_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_NotAdmitted_List, new_create_dissector_handle(dissect_E_RAB_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeSetup_Item, new_create_dissector_handle(dissect_E_RABs_ToBeSetup_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellInformation, new_create_dissector_handle(dissect_CellInformation_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellInformation_Item, new_create_dissector_handle(dissect_CellInformation_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_New_eNB_UE_X2AP_ID, new_create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Old_eNB_UE_X2AP_ID, new_create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TargetCell_ID, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TargeteNBtoSource_eNBTransparentContainer, new_create_dissector_handle(dissect_TargeteNBtoSource_eNBTransparentContainer_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TraceActivation, new_create_dissector_handle(dissect_TraceActivation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextInformation, new_create_dissector_handle(dissect_UE_ContextInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_HistoryInformation, new_create_dissector_handle(dissect_UE_HistoryInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_X2AP_ID, new_create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CriticalityDiagnostics, new_create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToStatusTransfer_List, new_create_dissector_handle(dissect_E_RABs_SubjectToStatusTransfer_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToStatusTransfer_Item, new_create_dissector_handle(dissect_E_RABs_SubjectToStatusTransfer_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCells, new_create_dissector_handle(dissect_ServedCells_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GlobalENB_ID, new_create_dissector_handle(dissect_GlobalENB_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TimeToWait, new_create_dissector_handle(dissect_TimeToWait_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUMMEI_ID, new_create_dissector_handle(dissect_GUMMEI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDList, new_create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToAdd, new_create_dissector_handle(dissect_ServedCells_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToModify, new_create_dissector_handle(dissect_ServedCellsToModify_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToDelete, new_create_dissector_handle(dissect_Old_ECGIs_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Registration_Request, new_create_dissector_handle(dissect_Registration_Request_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellToReport, new_create_dissector_handle(dissect_CellToReport_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportingPeriodicity, new_create_dissector_handle(dissect_ReportingPeriodicity_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellToReport_Item, new_create_dissector_handle(dissect_CellToReport_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellMeasurementResult, new_create_dissector_handle(dissect_CellMeasurementResult_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellMeasurementResult_Item, new_create_dissector_handle(dissect_CellMeasurementResult_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDToAddList, new_create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDToDeleteList, new_create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SRVCCOperationPossible, new_create_dissector_handle(dissect_SRVCCOperationPossible_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportCharacteristics, new_create_dissector_handle(dissect_ReportCharacteristics_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Measurement_ID, new_create_dissector_handle(dissect_Measurement_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Measurement_ID, new_create_dissector_handle(dissect_Measurement_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Cell_ID, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Cell_ID, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Proposed_Mobility_Parameters, new_create_dissector_handle(dissect_MobilityParametersInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Mobility_Parameters, new_create_dissector_handle(dissect_MobilityParametersInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Mobility_Parameters_Modification_Range, new_create_dissector_handle(dissect_MobilityParametersModificationRange_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellPCI, new_create_dissector_handle(dissect_PCI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Re_establishmentCellECGI, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellCRNTI, new_create_dissector_handle(dissect_CRNTI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ShortMAC_I, new_create_dissector_handle(dissect_ShortMAC_I_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SourceCellECGI, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellECGI, new_create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_HandoverReportType, new_create_dissector_handle(dissect_HandoverReportType_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_RLF_Report_Container, new_create_dissector_handle(dissect_UE_RLF_Report_Container_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToActivate, new_create_dissector_handle(dissect_ServedCellsToActivate_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ActivatedCellList, new_create_dissector_handle(dissect_ActivatedCellList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_PartialSuccessIndicator, new_create_dissector_handle(dissect_PartialSuccessIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementInitiationResult_List, new_create_dissector_handle(dissect_MeasurementInitiationResult_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementInitiationResult_Item, new_create_dissector_handle(dissect_MeasurementInitiationResult_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementFailureCause_Item, new_create_dissector_handle(dissect_MeasurementFailureCause_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CompleteFailureCauseInformation_List, new_create_dissector_handle(dissect_CompleteFailureCauseInformation_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CompleteFailureCauseInformation_Item, new_create_dissector_handle(dissect_CompleteFailureCauseInformation_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CSGMembershipStatus, new_create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_RRCConnSetupIndicator, new_create_dissector_handle(dissect_RRCConnSetupIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_Number_of_Antennaports, new_create_dissector_handle(dissect_Number_of_Antennaports_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CompositeAvailableCapacityGroup, new_create_dissector_handle(dissect_CompositeAvailableCapacityGroup_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_PRACH_Configuration, new_create_dissector_handle(dissect_PRACH_Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MBSFN_Subframe_Info, new_create_dissector_handle(dissect_MBSFN_Subframe_Infolist_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DeactivationIndication, new_create_dissector_handle(dissect_DeactivationIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ABSInformation, new_create_dissector_handle(dissect_ABSInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_InvokeIndication, new_create_dissector_handle(dissect_InvokeIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ABS_Status, new_create_dissector_handle(dissect_ABS_Status_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CSG_Id, new_create_dissector_handle(dissect_CSG_Id_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MDTConfiguration, new_create_dissector_handle(dissect_MDT_Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ManagementBasedMDTallowed, new_create_dissector_handle(dissect_ManagementBasedMDTallowed_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverPreparation, new_create_dissector_handle(dissect_HandoverRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_handoverPreparation, new_create_dissector_handle(dissect_HandoverRequestAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_handoverPreparation, new_create_dissector_handle(dissect_HandoverPreparationFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_snStatusTransfer, new_create_dissector_handle(dissect_SNStatusTransfer_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_uEContextRelease, new_create_dissector_handle(dissect_UEContextRelease_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverCancel, new_create_dissector_handle(dissect_HandoverCancel_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_errorIndication, new_create_dissector_handle(dissect_ErrorIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_reset, new_create_dissector_handle(dissect_ResetRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_reset, new_create_dissector_handle(dissect_ResetResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_x2Setup, new_create_dissector_handle(dissect_X2SetupRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_x2Setup, new_create_dissector_handle(dissect_X2SetupResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_x2Setup, new_create_dissector_handle(dissect_X2SetupFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_loadIndication, new_create_dissector_handle(dissect_LoadInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_eNBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdate_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_eNBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdateAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_eNBConfigurationUpdate, new_create_dissector_handle(dissect_ENBConfigurationUpdateFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_resourceStatusReportingInitiation, new_create_dissector_handle(dissect_ResourceStatusRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_resourceStatusReportingInitiation, new_create_dissector_handle(dissect_ResourceStatusResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_resourceStatusReportingInitiation, new_create_dissector_handle(dissect_ResourceStatusFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_resourceStatusReporting, new_create_dissector_handle(dissect_ResourceStatusUpdate_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_privateMessage, new_create_dissector_handle(dissect_PrivateMessage_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverReport, new_create_dissector_handle(dissect_HandoverReport_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_rLFIndication, new_create_dissector_handle(dissect_RLFIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_mobilitySettingsChange, new_create_dissector_handle(dissect_MobilityChangeRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_mobilitySettingsChange, new_create_dissector_handle(dissect_MobilityChangeAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_mobilitySettingsChange, new_create_dissector_handle(dissect_MobilityChangeFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_cellActivation, new_create_dissector_handle(dissect_CellActivationRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_cellActivation, new_create_dissector_handle(dissect_CellActivationResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_cellActivation, new_create_dissector_handle(dissect_CellActivationFailure_PDU, proto_x2ap));
#line 203 "../../asn1/x2ap/packet-x2ap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, x2ap_handle);
}
}
SctpPort=gbl_x2apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, x2ap_handle);
}
}
