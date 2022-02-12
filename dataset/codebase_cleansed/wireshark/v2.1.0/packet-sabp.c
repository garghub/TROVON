static int
dissect_sabp_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sabp_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 57 "./asn1/sabp/sabp.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext(ProcedureCode, &sabp_ProcedureCode_vals_ext,
"unknown message"));
return offset;
}
static int
dissect_sabp_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolExtensionID, FALSE);
return offset;
}
static int
dissect_sabp_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolIE_ID, FALSE);
#line 44 "./asn1/sabp/sabp.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(ProtocolIE_ID, &sabp_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_sabp_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sabp_ProtocolIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_sabp_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_sabp_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_sabp_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_sabp_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_sabp_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_sabp_Available_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 20480U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_Broadcast_Message_Content(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 210 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 9968, FALSE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
dissect_sabp_cb_data(parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_sabp_Broadcast_Message_Content_Validity_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sabp_Category(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sabp_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_RepetitionNumber0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_sabp_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_sabp_Criticality_Diagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Criticality_Diagnostics, Criticality_Diagnostics_sequence);
return offset;
}
static int
dissect_sabp_RepetitionNumber1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_MessageStructure_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_MessageStructure_item, MessageStructure_item_sequence);
return offset;
}
static int
dissect_sabp_MessageStructure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_MessageStructure, MessageStructure_sequence_of,
1, maxNrOfLevels, FALSE);
return offset;
}
static int
dissect_sabp_Data_Coding_Scheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 171 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_sabp_cbs_data_coding);
sms_encoding = dissect_cbs_data_coding_scheme(parameter_tvb, actx->pinfo, subtree, 0);
return offset;
}
static int
dissect_sabp_T_pLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 159 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_sabp_e212);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
return offset;
}
static int
dissect_sabp_OCTET_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_sabp_Service_Area_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Service_Area_Identifier, Service_Area_Identifier_sequence);
return offset;
}
static int
dissect_sabp_Failure_List_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Failure_List_Item, Failure_List_Item_sequence);
return offset;
}
static int
dissect_sabp_Failure_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_Failure_List, Failure_List_sequence_of,
1, maxnoofSAI, FALSE);
return offset;
}
static int
dissect_sabp_Message_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 182 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
dissect_cbs_message_identifier(parameter_tvb, tree, 0);
return offset;
}
static int
dissect_sabp_Serial_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 190 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_sabp_cbs_serial_number);
dissect_cbs_serial_number(parameter_tvb, subtree, 0);
return offset;
}
static int
dissect_sabp_New_Serial_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 200 "./asn1/sabp/sabp.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
offset = dissect_sabp_Serial_Number(tvb, offset, actx, tree, hf_index);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_sabp_cbs_new_serial_number);
dissect_cbs_serial_number(parameter_tvb, subtree, 0);
return offset;
}
static int
dissect_sabp_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_Number_Of_Broadcasts_Completed_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sabp_Number_of_Broadcasts_Completed_List_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Number_of_Broadcasts_Completed_List_Item, Number_of_Broadcasts_Completed_List_Item_sequence);
return offset;
}
static int
dissect_sabp_Number_of_Broadcasts_Completed_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_Number_of_Broadcasts_Completed_List, Number_of_Broadcasts_Completed_List_sequence_of,
1, maxnoofSAI, FALSE);
return offset;
}
static int
dissect_sabp_Number_of_Broadcasts_Requested(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_Old_Serial_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_sabp_Serial_Number(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_sabp_Paging_ETWS_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sabp_Radio_Resource_Loading_List_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Radio_Resource_Loading_List_Item, Radio_Resource_Loading_List_Item_sequence);
return offset;
}
static int
dissect_sabp_Radio_Resource_Loading_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_Radio_Resource_Loading_List, Radio_Resource_Loading_List_sequence_of,
1, maxnoofSAI, FALSE);
return offset;
}
static int
dissect_sabp_Recovery_Indication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sabp_Repetition_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4096U, NULL, FALSE);
return offset;
}
static int
dissect_sabp_Service_Areas_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sabp_Service_Areas_List, Service_Areas_List_sequence_of,
1, maxnoofSAI, FALSE);
return offset;
}
static int
dissect_sabp_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sabp_WarningSecurityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
50, 50, FALSE, NULL);
return offset;
}
static int
dissect_sabp_Warning_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_sabp_Write_Replace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Write_Replace, Write_Replace_sequence);
return offset;
}
static int
dissect_sabp_Write_Replace_Complete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Write_Replace_Complete, Write_Replace_Complete_sequence);
return offset;
}
static int
dissect_sabp_Write_Replace_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Write_Replace_Failure, Write_Replace_Failure_sequence);
return offset;
}
static int
dissect_sabp_Kill(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Kill, Kill_sequence);
return offset;
}
static int
dissect_sabp_Kill_Complete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Kill_Complete, Kill_Complete_sequence);
return offset;
}
static int
dissect_sabp_Kill_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Kill_Failure, Kill_Failure_sequence);
return offset;
}
static int
dissect_sabp_Load_Query(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Load_Query, Load_Query_sequence);
return offset;
}
static int
dissect_sabp_Load_Query_Complete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Load_Query_Complete, Load_Query_Complete_sequence);
return offset;
}
static int
dissect_sabp_Load_Query_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Load_Query_Failure, Load_Query_Failure_sequence);
return offset;
}
static int
dissect_sabp_Message_Status_Query(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Message_Status_Query, Message_Status_Query_sequence);
return offset;
}
static int
dissect_sabp_Message_Status_Query_Complete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Message_Status_Query_Complete, Message_Status_Query_Complete_sequence);
return offset;
}
static int
dissect_sabp_Message_Status_Query_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Message_Status_Query_Failure, Message_Status_Query_Failure_sequence);
return offset;
}
static int
dissect_sabp_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Reset, Reset_sequence);
return offset;
}
static int
dissect_sabp_Reset_Complete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Reset_Complete, Reset_Complete_sequence);
return offset;
}
static int
dissect_sabp_Reset_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Reset_Failure, Reset_Failure_sequence);
return offset;
}
static int
dissect_sabp_Restart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Restart, Restart_sequence);
return offset;
}
static int
dissect_sabp_Failure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Failure, Failure_sequence);
return offset;
}
static int
dissect_sabp_Error_Indication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_Error_Indication, Error_Indication_sequence);
return offset;
}
static int
dissect_sabp_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_sabp_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_sabp_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_sabp_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_sabp_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_sabp_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sabp_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_sabp_SABP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_sabp_SABP_PDU, SABP_PDU_choice,
NULL);
return offset;
}
static int dissect_Broadcast_Message_Content_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Broadcast_Message_Content(tvb, offset, &asn1_ctx, tree, hf_sabp_Broadcast_Message_Content_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Broadcast_Message_Content_Validity_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Broadcast_Message_Content_Validity_Indicator(tvb, offset, &asn1_ctx, tree, hf_sabp_Broadcast_Message_Content_Validity_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Category_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Category(tvb, offset, &asn1_ctx, tree, hf_sabp_Category_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Cause(tvb, offset, &asn1_ctx, tree, hf_sabp_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Criticality_Diagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Criticality_Diagnostics(tvb, offset, &asn1_ctx, tree, hf_sabp_Criticality_Diagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MessageStructure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_MessageStructure(tvb, offset, &asn1_ctx, tree, hf_sabp_MessageStructure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Data_Coding_Scheme_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Data_Coding_Scheme(tvb, offset, &asn1_ctx, tree, hf_sabp_Data_Coding_Scheme_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Failure_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Failure_List(tvb, offset, &asn1_ctx, tree, hf_sabp_Failure_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Message_Identifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Message_Identifier(tvb, offset, &asn1_ctx, tree, hf_sabp_Message_Identifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_New_Serial_Number_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_New_Serial_Number(tvb, offset, &asn1_ctx, tree, hf_sabp_New_Serial_Number_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Number_of_Broadcasts_Completed_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Number_of_Broadcasts_Completed_List(tvb, offset, &asn1_ctx, tree, hf_sabp_Number_of_Broadcasts_Completed_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Number_of_Broadcasts_Requested_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Number_of_Broadcasts_Requested(tvb, offset, &asn1_ctx, tree, hf_sabp_Number_of_Broadcasts_Requested_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Old_Serial_Number_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Old_Serial_Number(tvb, offset, &asn1_ctx, tree, hf_sabp_Old_Serial_Number_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Paging_ETWS_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Paging_ETWS_Indicator(tvb, offset, &asn1_ctx, tree, hf_sabp_Paging_ETWS_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Radio_Resource_Loading_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Radio_Resource_Loading_List(tvb, offset, &asn1_ctx, tree, hf_sabp_Radio_Resource_Loading_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Recovery_Indication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Recovery_Indication(tvb, offset, &asn1_ctx, tree, hf_sabp_Recovery_Indication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Repetition_Period_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Repetition_Period(tvb, offset, &asn1_ctx, tree, hf_sabp_Repetition_Period_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Serial_Number_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Serial_Number(tvb, offset, &asn1_ctx, tree, hf_sabp_Serial_Number_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Service_Areas_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Service_Areas_List(tvb, offset, &asn1_ctx, tree, hf_sabp_Service_Areas_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TypeOfError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_TypeOfError(tvb, offset, &asn1_ctx, tree, hf_sabp_TypeOfError_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningSecurityInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_WarningSecurityInfo(tvb, offset, &asn1_ctx, tree, hf_sabp_WarningSecurityInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Warning_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Warning_Type(tvb, offset, &asn1_ctx, tree, hf_sabp_Warning_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Write_Replace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Write_Replace(tvb, offset, &asn1_ctx, tree, hf_sabp_Write_Replace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Write_Replace_Complete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Write_Replace_Complete(tvb, offset, &asn1_ctx, tree, hf_sabp_Write_Replace_Complete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Write_Replace_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Write_Replace_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Write_Replace_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Kill_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Kill(tvb, offset, &asn1_ctx, tree, hf_sabp_Kill_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Kill_Complete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Kill_Complete(tvb, offset, &asn1_ctx, tree, hf_sabp_Kill_Complete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Kill_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Kill_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Kill_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Load_Query_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Load_Query(tvb, offset, &asn1_ctx, tree, hf_sabp_Load_Query_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Load_Query_Complete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Load_Query_Complete(tvb, offset, &asn1_ctx, tree, hf_sabp_Load_Query_Complete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Load_Query_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Load_Query_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Load_Query_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Message_Status_Query_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Message_Status_Query(tvb, offset, &asn1_ctx, tree, hf_sabp_Message_Status_Query_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Message_Status_Query_Complete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Message_Status_Query_Complete(tvb, offset, &asn1_ctx, tree, hf_sabp_Message_Status_Query_Complete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Message_Status_Query_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Message_Status_Query_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Message_Status_Query_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Reset(tvb, offset, &asn1_ctx, tree, hf_sabp_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_Complete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Reset_Complete(tvb, offset, &asn1_ctx, tree, hf_sabp_Reset_Complete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Reset_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Reset_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Restart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Restart(tvb, offset, &asn1_ctx, tree, hf_sabp_Restart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Failure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Failure(tvb, offset, &asn1_ctx, tree, hf_sabp_Failure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Error_Indication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_Error_Indication(tvb, offset, &asn1_ctx, tree, hf_sabp_Error_Indication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SABP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sabp_SABP_PDU(tvb, offset, &asn1_ctx, tree, hf_sabp_SABP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static void
dissect_sabp_cb_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *cbs_page_item;
proto_tree *subtree;
tvbuff_t *page_tvb, *unpacked_tvb;
int offset = 0;
int n;
guint8 nr_pages, len, cb_inf_msg_len;
nr_pages = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_sabp_no_of_pages, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(nr_pages > 15){
return;
}
for (n = 0; n < nr_pages; n++) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 83, ett_sabp_cbs_page, NULL,
"CB page %u data", n+1);
cbs_page_item = proto_tree_add_item(subtree, hf_sabp_cb_msg_inf_page, tvb, offset, 82, ENC_NA);
cb_inf_msg_len = tvb_get_guint8(tvb,offset+82);
page_tvb = tvb_new_subset_length(tvb, offset, cb_inf_msg_len);
unpacked_tvb = dissect_cbs_data(sms_encoding, page_tvb, subtree, pinfo, 0);
len = tvb_captured_length(unpacked_tvb);
if (unpacked_tvb != NULL){
if (tree != NULL){
proto_tree *cbs_page_subtree = proto_item_add_subtree(cbs_page_item, ett_sabp_cbs_page_content);
proto_tree_add_item(cbs_page_subtree, hf_sabp_cbs_page_content, unpacked_tvb, 0, len, ENC_UTF_8|ENC_NA);
}
}
offset = offset+82;
proto_tree_add_item(subtree, hf_sabp_cb_inf_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
static guint
get_sabp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint32 type_length;
int bit_offset;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = offset + 3;
bit_offset = offset<<3;
dissect_per_length_determinant(tvb, bit_offset, &asn1_ctx, NULL, -1, &type_length);
if (type_length < 128)
return type_length+4;
return type_length+5;
}
static int
dissect_sabp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *sabp_item = NULL;
proto_tree *sabp_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
sabp_item = proto_tree_add_item(tree, proto_sabp, tvb, 0, -1, ENC_NA);
sabp_tree = proto_item_add_subtree(sabp_item, ett_sabp);
dissect_SABP_PDU_PDU(tvb, pinfo, sabp_tree, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_sabp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, gbl_sabp_desegment, 5,
get_sabp_pdu_len, dissect_sabp, data);
return tvb_captured_length(tvb);
}
void proto_register_sabp(void) {
static hf_register_info hf[] = {
{ &hf_sabp_no_of_pages,
{ "Number-of-Pages", "sabp.no_of_pages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cb_msg_inf_page,
{ "CBS-Message-Information-Page", "sabp.cb_msg_inf_page",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cbs_page_content,
{ "CBS Page Content", "sabp.cb_page_content",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cb_inf_len,
{ "CBS-Message-Information-Length", "sabp.cb_inf_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
#line 1 "./asn1/sabp/packet-sabp-hfarr.c"
{ &hf_sabp_Broadcast_Message_Content_PDU,
{ "Broadcast-Message-Content", "sabp.Broadcast_Message_Content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Broadcast_Message_Content_Validity_Indicator_PDU,
{ "Broadcast-Message-Content-Validity-Indicator", "sabp.Broadcast_Message_Content_Validity_Indicator",
FT_UINT32, BASE_DEC, VALS(sabp_Broadcast_Message_Content_Validity_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Category_PDU,
{ "Category", "sabp.Category",
FT_UINT32, BASE_DEC, VALS(sabp_Category_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Cause_PDU,
{ "Cause", "sabp.Cause",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sabp_Cause_vals_ext, 0,
NULL, HFILL }},
{ &hf_sabp_Criticality_Diagnostics_PDU,
{ "Criticality-Diagnostics", "sabp.Criticality_Diagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_MessageStructure_PDU,
{ "MessageStructure", "sabp.MessageStructure",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Data_Coding_Scheme_PDU,
{ "Data-Coding-Scheme", "sabp.Data_Coding_Scheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Failure_List_PDU,
{ "Failure-List", "sabp.Failure_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Message_Identifier_PDU,
{ "Message-Identifier", "sabp.Message_Identifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_New_Serial_Number_PDU,
{ "New-Serial-Number", "sabp.New_Serial_Number",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Number_of_Broadcasts_Completed_List_PDU,
{ "Number-of-Broadcasts-Completed-List", "sabp.Number_of_Broadcasts_Completed_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Number_of_Broadcasts_Requested_PDU,
{ "Number-of-Broadcasts-Requested", "sabp.Number_of_Broadcasts_Requested",
FT_UINT32, BASE_DEC, VALS(sabp_Number_of_Broadcasts_Requested_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Old_Serial_Number_PDU,
{ "Old-Serial-Number", "sabp.Old_Serial_Number",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Paging_ETWS_Indicator_PDU,
{ "Paging-ETWS-Indicator", "sabp.Paging_ETWS_Indicator",
FT_UINT32, BASE_DEC, VALS(sabp_Paging_ETWS_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Radio_Resource_Loading_List_PDU,
{ "Radio-Resource-Loading-List", "sabp.Radio_Resource_Loading_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Recovery_Indication_PDU,
{ "Recovery-Indication", "sabp.Recovery_Indication",
FT_UINT32, BASE_DEC, VALS(sabp_Recovery_Indication_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Repetition_Period_PDU,
{ "Repetition-Period", "sabp.Repetition_Period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Serial_Number_PDU,
{ "Serial-Number", "sabp.Serial_Number",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Service_Areas_List_PDU,
{ "Service-Areas-List", "sabp.Service_Areas_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_TypeOfError_PDU,
{ "TypeOfError", "sabp.TypeOfError",
FT_UINT32, BASE_DEC, VALS(sabp_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_sabp_WarningSecurityInfo_PDU,
{ "WarningSecurityInfo", "sabp.WarningSecurityInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Warning_Type_PDU,
{ "Warning-Type", "sabp.Warning_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Write_Replace_PDU,
{ "Write-Replace", "sabp.Write_Replace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Write_Replace_Complete_PDU,
{ "Write-Replace-Complete", "sabp.Write_Replace_Complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Write_Replace_Failure_PDU,
{ "Write-Replace-Failure", "sabp.Write_Replace_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Kill_PDU,
{ "Kill", "sabp.Kill_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Kill_Complete_PDU,
{ "Kill-Complete", "sabp.Kill_Complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Kill_Failure_PDU,
{ "Kill-Failure", "sabp.Kill_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Load_Query_PDU,
{ "Load-Query", "sabp.Load_Query_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Load_Query_Complete_PDU,
{ "Load-Query-Complete", "sabp.Load_Query_Complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Load_Query_Failure_PDU,
{ "Load-Query-Failure", "sabp.Load_Query_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Message_Status_Query_PDU,
{ "Message-Status-Query", "sabp.Message_Status_Query_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Message_Status_Query_Complete_PDU,
{ "Message-Status-Query-Complete", "sabp.Message_Status_Query_Complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Message_Status_Query_Failure_PDU,
{ "Message-Status-Query-Failure", "sabp.Message_Status_Query_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Reset_PDU,
{ "Reset", "sabp.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Reset_Complete_PDU,
{ "Reset-Complete", "sabp.Reset_Complete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Reset_Failure_PDU,
{ "Reset-Failure", "sabp.Reset_Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Restart_PDU,
{ "Restart", "sabp.Restart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Failure_PDU,
{ "Failure", "sabp.Failure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_Error_Indication_PDU,
{ "Error-Indication", "sabp.Error_Indication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_SABP_PDU_PDU,
{ "SABP-PDU", "sabp.SABP_PDU",
FT_UINT32, BASE_DEC, VALS(sabp_SABP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_sabp_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "sabp.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_id,
{ "id", "sabp.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sabp_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_sabp_criticality,
{ "criticality", "sabp.criticality",
FT_UINT32, BASE_DEC, VALS(sabp_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_sabp_protocolIE_Field_value,
{ "value", "sabp.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtocolIE_Field_value", HFILL }},
{ &hf_sabp_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "sabp.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_ext_id,
{ "id", "sabp.id",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionID", HFILL }},
{ &hf_sabp_extensionValue,
{ "extensionValue", "sabp.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_procedureCode,
{ "procedureCode", "sabp.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sabp_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_sabp_triggeringMessage,
{ "triggeringMessage", "sabp.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(sabp_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_sabp_procedureCriticality,
{ "procedureCriticality", "sabp.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(sabp_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_sabp_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "sabp.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_sabp_iE_Extensions,
{ "iE-Extensions", "sabp.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_sabp_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "sabp.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_iECriticality,
{ "iECriticality", "sabp.iECriticality",
FT_UINT32, BASE_DEC, VALS(sabp_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_sabp_iE_ID,
{ "iE-ID", "sabp.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sabp_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_sabp_repetitionNumber,
{ "repetitionNumber", "sabp.repetitionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"RepetitionNumber0", HFILL }},
{ &hf_sabp_MessageStructure_item,
{ "MessageStructure item", "sabp.MessageStructure_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_repetitionNumber1,
{ "repetitionNumber", "sabp.repetitionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"RepetitionNumber1", HFILL }},
{ &hf_sabp_Failure_List_item,
{ "Failure-List-Item", "sabp.Failure_List_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_service_area_identifier,
{ "service-area-identifier", "sabp.service_area_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cause,
{ "cause", "sabp.cause",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sabp_Cause_vals_ext, 0,
NULL, HFILL }},
{ &hf_sabp_Number_of_Broadcasts_Completed_List_item,
{ "Number-of-Broadcasts-Completed-List-Item", "sabp.Number_of_Broadcasts_Completed_List_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_number_of_broadcasts_completed,
{ "number-of-broadcasts-completed", "sabp.number_of_broadcasts_completed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_sabp_number_of_broadcasts_completed_info,
{ "number-of-broadcasts-completed-info", "sabp.number_of_broadcasts_completed_info",
FT_UINT32, BASE_DEC, VALS(sabp_Number_Of_Broadcasts_Completed_Info_vals), 0,
NULL, HFILL }},
{ &hf_sabp_Radio_Resource_Loading_List_item,
{ "Radio-Resource-Loading-List-Item", "sabp.Radio_Resource_Loading_List_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_available_bandwidth,
{ "available-bandwidth", "sabp.available_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_pLMNidentity,
{ "pLMNidentity", "sabp.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_lac,
{ "lac", "sabp.lac",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_sabp_sac,
{ "sac", "sabp.sac",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_2", HFILL }},
{ &hf_sabp_Service_Areas_List_item,
{ "Service-Area-Identifier", "sabp.Service_Area_Identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_protocolIEs,
{ "protocolIEs", "sabp.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_sabp_protocolExtensions,
{ "protocolExtensions", "sabp.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_sabp_initiatingMessage,
{ "initiatingMessage", "sabp.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_successfulOutcome,
{ "successfulOutcome", "sabp.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "sabp.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_initiatingMessage_value,
{ "value", "sabp.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_sabp_successfulOutcome_value,
{ "value", "sabp.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_sabp_unsuccessfulOutcome_value,
{ "value", "sabp.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 247 "./asn1/sabp/packet-sabp-template.c"
};
static gint *ett[] = {
&ett_sabp,
&ett_sabp_e212,
&ett_sabp_cbs_data_coding,
&ett_sabp_bcast_msg,
&ett_sabp_cbs_serial_number,
&ett_sabp_cbs_new_serial_number,
&ett_sabp_cbs_page,
&ett_sabp_cbs_page_content,
#line 1 "./asn1/sabp/packet-sabp-ettarr.c"
&ett_sabp_ProtocolIE_Container,
&ett_sabp_ProtocolIE_Field,
&ett_sabp_ProtocolExtensionContainer,
&ett_sabp_ProtocolExtensionField,
&ett_sabp_Criticality_Diagnostics,
&ett_sabp_CriticalityDiagnostics_IE_List,
&ett_sabp_CriticalityDiagnostics_IE_List_item,
&ett_sabp_MessageStructure,
&ett_sabp_MessageStructure_item,
&ett_sabp_Failure_List,
&ett_sabp_Failure_List_Item,
&ett_sabp_Number_of_Broadcasts_Completed_List,
&ett_sabp_Number_of_Broadcasts_Completed_List_Item,
&ett_sabp_Radio_Resource_Loading_List,
&ett_sabp_Radio_Resource_Loading_List_Item,
&ett_sabp_Service_Area_Identifier,
&ett_sabp_Service_Areas_List,
&ett_sabp_Write_Replace,
&ett_sabp_Write_Replace_Complete,
&ett_sabp_Write_Replace_Failure,
&ett_sabp_Kill,
&ett_sabp_Kill_Complete,
&ett_sabp_Kill_Failure,
&ett_sabp_Load_Query,
&ett_sabp_Load_Query_Complete,
&ett_sabp_Load_Query_Failure,
&ett_sabp_Message_Status_Query,
&ett_sabp_Message_Status_Query_Complete,
&ett_sabp_Message_Status_Query_Failure,
&ett_sabp_Reset,
&ett_sabp_Reset_Complete,
&ett_sabp_Reset_Failure,
&ett_sabp_Restart,
&ett_sabp_Failure,
&ett_sabp_Error_Indication,
&ett_sabp_SABP_PDU,
&ett_sabp_InitiatingMessage,
&ett_sabp_SuccessfulOutcome,
&ett_sabp_UnsuccessfulOutcome,
#line 260 "./asn1/sabp/packet-sabp-template.c"
};
proto_sabp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_sabp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sabp", dissect_sabp, proto_sabp);
register_dissector("sabp.tcp", dissect_sabp_tcp, proto_sabp);
sabp_ies_dissector_table = register_dissector_table("sabp.ies", "SABP-PROTOCOL-IES", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_extension_dissector_table = register_dissector_table("sabp.extension", "SABP-PROTOCOL-EXTENSION", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_imsg_dissector_table = register_dissector_table("sabp.proc.imsg", "SABP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_sout_dissector_table = register_dissector_table("sabp.proc.sout", "SABP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_uout_dissector_table = register_dissector_table("sabp.proc.uout", "SABP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_sabp(void)
{
dissector_handle_t sabp_handle;
dissector_handle_t sabp_tcp_handle;
sabp_handle = find_dissector("sabp");
sabp_tcp_handle = find_dissector("sabp.tcp");
dissector_add_uint("udp.port", 3452, sabp_handle);
dissector_add_uint("tcp.port", 3452, sabp_tcp_handle);
dissector_add_uint("sctp.ppi", SABP_PAYLOAD_PROTOCOL_ID, sabp_handle);
#line 1 "./asn1/sabp/packet-sabp-dis-tab.c"
dissector_add_uint("sabp.ies", id_Message_Identifier, create_dissector_handle(dissect_Message_Identifier_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_New_Serial_Number, create_dissector_handle(dissect_New_Serial_Number_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Old_Serial_Number, create_dissector_handle(dissect_Old_Serial_Number_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Service_Areas_List, create_dissector_handle(dissect_Service_Areas_List_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Category, create_dissector_handle(dissect_Category_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Repetition_Period, create_dissector_handle(dissect_Repetition_Period_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Number_of_Broadcasts_Requested, create_dissector_handle(dissect_Number_of_Broadcasts_Requested_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Data_Coding_Scheme, create_dissector_handle(dissect_Data_Coding_Scheme_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Broadcast_Message_Content, create_dissector_handle(dissect_Broadcast_Message_Content_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Number_of_Broadcasts_Completed_List, create_dissector_handle(dissect_Number_of_Broadcasts_Completed_List_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Criticality_Diagnostics, create_dissector_handle(dissect_Criticality_Diagnostics_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Failure_List, create_dissector_handle(dissect_Failure_List_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Radio_Resource_Loading_List, create_dissector_handle(dissect_Radio_Resource_Loading_List_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Recovery_Indication, create_dissector_handle(dissect_Recovery_Indication_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Serial_Number, create_dissector_handle(dissect_Serial_Number_PDU, proto_sabp));
dissector_add_uint("sabp.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_MessageStructure, create_dissector_handle(dissect_MessageStructure_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_TypeOfError, create_dissector_handle(dissect_TypeOfError_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_Paging_ETWS_Indicator, create_dissector_handle(dissect_Paging_ETWS_Indicator_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_Warning_Type, create_dissector_handle(dissect_Warning_Type_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_WarningSecurityInfo, create_dissector_handle(dissect_WarningSecurityInfo_PDU, proto_sabp));
dissector_add_uint("sabp.extension", id_Broadcast_Message_Content_Validity_Indicator, create_dissector_handle(dissect_Broadcast_Message_Content_Validity_Indicator_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Write_Replace, create_dissector_handle(dissect_Write_Replace_PDU, proto_sabp));
dissector_add_uint("sabp.proc.sout", id_Write_Replace, create_dissector_handle(dissect_Write_Replace_Complete_PDU, proto_sabp));
dissector_add_uint("sabp.proc.uout", id_Write_Replace, create_dissector_handle(dissect_Write_Replace_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Kill, create_dissector_handle(dissect_Kill_PDU, proto_sabp));
dissector_add_uint("sabp.proc.sout", id_Kill, create_dissector_handle(dissect_Kill_Complete_PDU, proto_sabp));
dissector_add_uint("sabp.proc.uout", id_Kill, create_dissector_handle(dissect_Kill_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Load_Status_Enquiry, create_dissector_handle(dissect_Load_Query_PDU, proto_sabp));
dissector_add_uint("sabp.proc.sout", id_Load_Status_Enquiry, create_dissector_handle(dissect_Load_Query_Complete_PDU, proto_sabp));
dissector_add_uint("sabp.proc.uout", id_Load_Status_Enquiry, create_dissector_handle(dissect_Load_Query_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Message_Status_Query, create_dissector_handle(dissect_Message_Status_Query_PDU, proto_sabp));
dissector_add_uint("sabp.proc.sout", id_Message_Status_Query, create_dissector_handle(dissect_Message_Status_Query_Complete_PDU, proto_sabp));
dissector_add_uint("sabp.proc.uout", id_Message_Status_Query, create_dissector_handle(dissect_Message_Status_Query_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Reset, create_dissector_handle(dissect_Reset_PDU, proto_sabp));
dissector_add_uint("sabp.proc.sout", id_Reset, create_dissector_handle(dissect_Reset_Complete_PDU, proto_sabp));
dissector_add_uint("sabp.proc.uout", id_Reset, create_dissector_handle(dissect_Reset_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Restart_Indication, create_dissector_handle(dissect_Restart_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Failure_Indication, create_dissector_handle(dissect_Failure_PDU, proto_sabp));
dissector_add_uint("sabp.proc.imsg", id_Error_Indication, create_dissector_handle(dissect_Error_Indication_PDU, proto_sabp));
#line 296 "./asn1/sabp/packet-sabp-template.c"
}
