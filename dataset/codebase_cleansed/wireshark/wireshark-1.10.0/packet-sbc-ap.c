static int
dissect_sbc_ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sbc_ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 64 "../../asn1/sbc-ap/sbc-ap.cnf"
if (check_col(actx->pinfo->cinfo, COL_INFO))
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str(ProcedureCode, sbc_ap_ProcedureCode_vals,
"unknown message"));
return offset;
}
static int
dissect_sbc_ap_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolExtensionID, FALSE);
return offset;
}
static int
dissect_sbc_ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolIE_ID, FALSE);
#line 47 "../../asn1/sbc-ap/sbc-ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(sbc_ap_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_sbc_ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sbc_ap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_sbc_ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_sbc_ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_sbc_ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_sbc_ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_sbc_ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_sbc_ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_sbc_ap_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Concurrent_Warning_Message_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_sbc_ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_sbc_ap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_sbc_ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_sbc_ap_Criticality_Diagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Criticality_Diagnostics, Criticality_Diagnostics_sequence);
return offset;
}
static int
dissect_sbc_ap_Data_Coding_Scheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_PLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 102 "../../asn1/sbc-ap/sbc-ap.cnf"
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
dissect_sbc_ap_EUTRAN_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_EUTRAN_CGI, EUTRAN_CGI_sequence);
return offset;
}
static int
dissect_sbc_ap_ECGIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_ECGIList, ECGIList_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_sbc_ap_Emergency_Area_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Emergency_Area_ID_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Emergency_Area_ID_List, Emergency_Area_ID_List_sequence_of,
1, maxnoofEmerAreaIDs, FALSE);
return offset;
}
static int
dissect_sbc_ap_Extended_Repetition_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_sbc_ap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_TAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_TAI, TAI_sequence);
return offset;
}
static int
dissect_sbc_ap_List_of_TAIs_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_List_of_TAIs_item, List_of_TAIs_item_sequence);
return offset;
}
static int
dissect_sbc_ap_List_of_TAIs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_List_of_TAIs, List_of_TAIs_sequence_of,
1, maxNrOfTAIs, FALSE);
return offset;
}
static int
dissect_sbc_ap_Message_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Number_of_Broadcasts_Requested(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_sbc_ap_Omc_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 20, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Repetition_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4096U, NULL, FALSE);
return offset;
}
static int
dissect_sbc_ap_Serial_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_TAI_List_for_Warning(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_TAI_List_for_Warning, TAI_List_for_Warning_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_sbc_ap_Warning_Area_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Warning_Area_List, Warning_Area_List_choice,
NULL);
return offset;
}
static int
dissect_sbc_ap_Warning_Message_Content(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 9600, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Warning_Security_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
50, 50, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Warning_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_sbc_ap_Write_Replace_Warning_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Write_Replace_Warning_Request, Write_Replace_Warning_Request_sequence);
return offset;
}
static int
dissect_sbc_ap_Write_Replace_Warning_Response(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Write_Replace_Warning_Response, Write_Replace_Warning_Response_sequence);
return offset;
}
static int
dissect_sbc_ap_Stop_Warning_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Stop_Warning_Request, Stop_Warning_Request_sequence);
return offset;
}
static int
dissect_sbc_ap_Stop_Warning_Response(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_Stop_Warning_Response, Stop_Warning_Response_sequence);
return offset;
}
static int
dissect_sbc_ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_sbc_ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_sbc_ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_sbc_ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_sbc_ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_sbc_ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_sbc_ap_SBC_AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_sbc_ap_SBC_AP_PDU, SBC_AP_PDU_choice,
NULL);
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Cause(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Concurrent_Warning_Message_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Concurrent_Warning_Message_Indicator(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Concurrent_Warning_Message_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Criticality_Diagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Criticality_Diagnostics(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Criticality_Diagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Data_Coding_Scheme_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Data_Coding_Scheme(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Data_Coding_Scheme_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Extended_Repetition_Period_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Extended_Repetition_Period(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Extended_Repetition_Period_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_List_of_TAIs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_List_of_TAIs(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_List_of_TAIs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Message_Identifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Message_Identifier(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Message_Identifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Number_of_Broadcasts_Requested_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Number_of_Broadcasts_Requested(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Number_of_Broadcasts_Requested_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Omc_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Omc_Id(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Omc_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Repetition_Period_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Repetition_Period(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Repetition_Period_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Serial_Number_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Serial_Number(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Serial_Number_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Warning_Area_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Warning_Area_List(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Warning_Area_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Warning_Message_Content_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Warning_Message_Content(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Warning_Message_Content_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Warning_Security_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Warning_Security_Information(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Warning_Security_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Warning_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Warning_Type(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Warning_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Write_Replace_Warning_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Write_Replace_Warning_Request(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Write_Replace_Warning_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Write_Replace_Warning_Response_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Write_Replace_Warning_Response(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Write_Replace_Warning_Response_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Stop_Warning_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Stop_Warning_Request(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Stop_Warning_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Stop_Warning_Response_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_Stop_Warning_Response(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_Stop_Warning_Response_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SBC_AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_sbc_ap_SBC_AP_PDU(tvb, offset, &asn1_ctx, tree, hf_sbc_ap_SBC_AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_sbc_ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sbc_ap_item = NULL;
proto_tree *sbc_ap_tree = NULL;
if (check_col(pinfo->cinfo, COL_PROTOCOL))
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
if (tree) {
sbc_ap_item = proto_tree_add_item(tree, proto_sbc_ap, tvb, 0, -1, ENC_NA);
sbc_ap_tree = proto_item_add_subtree(sbc_ap_item, ett_sbc_ap);
dissect_SBC_AP_PDU_PDU(tvb, pinfo, sbc_ap_tree, NULL);
}
}
void proto_register_sbc_ap(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/sbc-ap/packet-sbc-ap-hfarr.c"
{ &hf_sbc_ap_Cause_PDU,
{ "Cause", "sbc-ap.Cause",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_Concurrent_Warning_Message_Indicator_PDU,
{ "Concurrent-Warning-Message-Indicator", "sbc-ap.Concurrent_Warning_Message_Indicator",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Concurrent_Warning_Message_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_Criticality_Diagnostics_PDU,
{ "Criticality-Diagnostics", "sbc-ap.Criticality_Diagnostics",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Data_Coding_Scheme_PDU,
{ "Data-Coding-Scheme", "sbc-ap.Data_Coding_Scheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Extended_Repetition_Period_PDU,
{ "Extended-Repetition-Period", "sbc-ap.Extended_Repetition_Period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_List_of_TAIs_PDU,
{ "List-of-TAIs", "sbc-ap.List_of_TAIs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Message_Identifier_PDU,
{ "Message-Identifier", "sbc-ap.Message_Identifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Number_of_Broadcasts_Requested_PDU,
{ "Number-of-Broadcasts-Requested", "sbc-ap.Number_of_Broadcasts_Requested",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Omc_Id_PDU,
{ "Omc-Id", "sbc-ap.Omc_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Repetition_Period_PDU,
{ "Repetition-Period", "sbc-ap.Repetition_Period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Serial_Number_PDU,
{ "Serial-Number", "sbc-ap.Serial_Number",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Warning_Area_List_PDU,
{ "Warning-Area-List", "sbc-ap.Warning_Area_List",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Warning_Area_List_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_Warning_Message_Content_PDU,
{ "Warning-Message-Content", "sbc-ap.Warning_Message_Content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Warning_Security_Information_PDU,
{ "Warning-Security-Information", "sbc-ap.Warning_Security_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Warning_Type_PDU,
{ "Warning-Type", "sbc-ap.Warning_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Write_Replace_Warning_Request_PDU,
{ "Write-Replace-Warning-Request", "sbc-ap.Write_Replace_Warning_Request",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Write_Replace_Warning_Response_PDU,
{ "Write-Replace-Warning-Response", "sbc-ap.Write_Replace_Warning_Response",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Stop_Warning_Request_PDU,
{ "Stop-Warning-Request", "sbc-ap.Stop_Warning_Request",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Stop_Warning_Response_PDU,
{ "Stop-Warning-Response", "sbc-ap.Stop_Warning_Response",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_SBC_AP_PDU_PDU,
{ "SBC-AP-PDU", "sbc-ap.SBC_AP_PDU",
FT_UINT32, BASE_DEC, VALS(sbc_ap_SBC_AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "sbc-ap.ProtocolIE_Field",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_id,
{ "id", "sbc-ap.id",
FT_UINT32, BASE_DEC, VALS(sbc_ap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_sbc_ap_criticality,
{ "criticality", "sbc-ap.criticality",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_ie_field_value,
{ "value", "sbc-ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_sbc_ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "sbc-ap.ProtocolExtensionField",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_ext_id,
{ "id", "sbc-ap.id",
FT_UINT8, BASE_DEC, VALS(sbc_ap_ProtocolIE_ID_vals), 0,
"ProtocolExtensionID", HFILL }},
{ &hf_sbc_ap_extensionValue,
{ "extensionValue", "sbc-ap.extensionValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_procedureCode,
{ "procedureCode", "sbc-ap.procedureCode",
FT_UINT32, BASE_DEC, VALS(sbc_ap_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_triggeringMessage,
{ "triggeringMessage", "sbc-ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(sbc_ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_procedureCriticality,
{ "procedureCriticality", "sbc-ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_sbc_ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "sbc-ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_sbc_ap_iE_Extensions,
{ "iE-Extensions", "sbc-ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_sbc_ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "sbc-ap.CriticalityDiagnostics_IE_List_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_iECriticality,
{ "iECriticality", "sbc-ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(sbc_ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_sbc_ap_iE_ID,
{ "iE-ID", "sbc-ap.iE_ID",
FT_UINT32, BASE_DEC, VALS(sbc_ap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_sbc_ap_typeOfError,
{ "typeOfError", "sbc-ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(sbc_ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_sbc_ap_ECGIList_item,
{ "EUTRAN-CGI", "sbc-ap.EUTRAN_CGI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_Emergency_Area_ID_List_item,
{ "Emergency-Area-ID", "sbc-ap.Emergency_Area_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_pLMNidentity,
{ "pLMNidentity", "sbc-ap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_cell_ID,
{ "cell-ID", "sbc-ap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdentity", HFILL }},
{ &hf_sbc_ap_List_of_TAIs_item,
{ "List-of-TAIs item", "sbc-ap.List_of_TAIs_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_tai,
{ "tai", "sbc-ap.tai",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_TAI_List_for_Warning_item,
{ "TAI", "sbc-ap.TAI",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_tAC,
{ "tAC", "sbc-ap.tAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_cell_ID_List,
{ "cell-ID-List", "sbc-ap.cell_ID_List",
FT_UINT32, BASE_DEC, NULL, 0,
"ECGIList", HFILL }},
{ &hf_sbc_ap_tracking_Area_List_for_Warning,
{ "tracking-Area-List-for-Warning", "sbc-ap.tracking_Area_List_for_Warning",
FT_UINT32, BASE_DEC, NULL, 0,
"TAI_List_for_Warning", HFILL }},
{ &hf_sbc_ap_emergency_Area_ID_List,
{ "emergency-Area-ID-List", "sbc-ap.emergency_Area_ID_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_protocolIEs,
{ "protocolIEs", "sbc-ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_sbc_ap_protocolExtensions,
{ "protocolExtensions", "sbc-ap.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_sbc_ap_initiatingMessage,
{ "initiatingMessage", "sbc-ap.initiatingMessage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_successfulOutcome,
{ "successfulOutcome", "sbc-ap.successfulOutcome",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "sbc-ap.unsuccessfulOutcome",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sbc_ap_initiatingMessagevalue,
{ "value", "sbc-ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_sbc_ap_successfulOutcome_value,
{ "value", "sbc-ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_sbc_ap_unsuccessfulOutcome_value,
{ "value", "sbc-ap.value",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 155 "../../asn1/sbc-ap/packet-sbc-ap-template.c"
};
static gint *ett[] = {
&ett_sbc_ap,
#line 1 "../../asn1/sbc-ap/packet-sbc-ap-ettarr.c"
&ett_sbc_ap_ProtocolIE_Container,
&ett_sbc_ap_ProtocolIE_Field,
&ett_sbc_ap_ProtocolExtensionContainer,
&ett_sbc_ap_ProtocolExtensionField,
&ett_sbc_ap_Criticality_Diagnostics,
&ett_sbc_ap_CriticalityDiagnostics_IE_List,
&ett_sbc_ap_CriticalityDiagnostics_IE_List_item,
&ett_sbc_ap_ECGIList,
&ett_sbc_ap_Emergency_Area_ID_List,
&ett_sbc_ap_EUTRAN_CGI,
&ett_sbc_ap_List_of_TAIs,
&ett_sbc_ap_List_of_TAIs_item,
&ett_sbc_ap_TAI_List_for_Warning,
&ett_sbc_ap_TAI,
&ett_sbc_ap_Warning_Area_List,
&ett_sbc_ap_Write_Replace_Warning_Request,
&ett_sbc_ap_Write_Replace_Warning_Response,
&ett_sbc_ap_Stop_Warning_Request,
&ett_sbc_ap_Stop_Warning_Response,
&ett_sbc_ap_SBC_AP_PDU,
&ett_sbc_ap_InitiatingMessage,
&ett_sbc_ap_SuccessfulOutcome,
&ett_sbc_ap_UnsuccessfulOutcome,
#line 161 "../../asn1/sbc-ap/packet-sbc-ap-template.c"
};
proto_sbc_ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_sbc_ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sbc_ap_ies_dissector_table = register_dissector_table("sbc_ap.ies", "SBC-AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
sbc_ap_extension_dissector_table = register_dissector_table("sbc_ap.extension", "SBC-AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
sbc_ap_proc_imsg_dissector_table = register_dissector_table("sbc_ap.proc.imsg", "SBC-AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
sbc_ap_proc_sout_dissector_table = register_dissector_table("sbc_ap.proc.sout", "SBC-AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
sbc_ap_proc_uout_dissector_table = register_dissector_table("sbc_ap.proc.uout", "SBC-AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_sbc_ap(void)
{
static gboolean inited = FALSE;
static guint SctpPort;
if( !inited ) {
sbc_ap_handle = create_dissector_handle(dissect_sbc_ap, proto_sbc_ap);
dissector_add_uint("sctp.ppi", SBC_AP_PAYLOAD_PROTOCOL_ID, sbc_ap_handle);
inited = TRUE;
#line 1 "../../asn1/sbc-ap/packet-sbc-ap-dis-tab.c"
dissector_add_uint("sbc_ap.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Criticality_Diagnostics, new_create_dissector_handle(dissect_Criticality_Diagnostics_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Data_Coding_Scheme, new_create_dissector_handle(dissect_Data_Coding_Scheme_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Message_Identifier, new_create_dissector_handle(dissect_Message_Identifier_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Number_of_Broadcasts_Requested, new_create_dissector_handle(dissect_Number_of_Broadcasts_Requested_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Repetition_Period, new_create_dissector_handle(dissect_Repetition_Period_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Serial_Number, new_create_dissector_handle(dissect_Serial_Number_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_List_of_TAIs, new_create_dissector_handle(dissect_List_of_TAIs_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Warning_Area_List, new_create_dissector_handle(dissect_Warning_Area_List_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Warning_Message_Content, new_create_dissector_handle(dissect_Warning_Message_Content_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Warning_Security_Information, new_create_dissector_handle(dissect_Warning_Security_Information_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Warning_Type, new_create_dissector_handle(dissect_Warning_Type_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Omc_Id, new_create_dissector_handle(dissect_Omc_Id_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Concurrent_Warning_Message_Indicator, new_create_dissector_handle(dissect_Concurrent_Warning_Message_Indicator_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.ies", id_Extended_Repetition_Period, new_create_dissector_handle(dissect_Extended_Repetition_Period_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.proc.imsg", id_Write_Replace_Warning, new_create_dissector_handle(dissect_Write_Replace_Warning_Request_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.proc.sout", id_Write_Replace_Warning, new_create_dissector_handle(dissect_Write_Replace_Warning_Response_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.proc.imsg", id_Stop_Warning, new_create_dissector_handle(dissect_Stop_Warning_Request_PDU, proto_sbc_ap));
dissector_add_uint("sbc_ap.proc.sout", id_Stop_Warning, new_create_dissector_handle(dissect_Stop_Warning_Response_PDU, proto_sbc_ap));
#line 194 "../../asn1/sbc-ap/packet-sbc-ap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, sbc_ap_handle);
}
}
SctpPort = global_sbc_ap_port;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, sbc_ap_handle);
}
}
