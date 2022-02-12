static int
dissect_lppa_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_LPPATransactionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_maxPrivateIEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxPrivateIEs, NULL, FALSE);
return offset;
}
static int
dissect_lppa_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppa_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_lppa_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 44 "./asn1/lppa/lppa.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str(ProcedureCode, lppa_ProcedureCode_vals,
"unknown message"));
return offset;
}
static int
dissect_lppa_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 37 "./asn1/lppa/lppa.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(lppa_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_lppa_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_lppa_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_lppa_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_lppa_ProtocolIE_Single_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_lppa_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_lppa_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppa_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_lppa_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_lppa_T_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppa_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_lppa_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_lppa_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_lppa_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_lppa_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_lppa_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_lppa_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_lppa_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_lppa_LPPA_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 58 "./asn1/lppa/lppa.cnf"
proto_tree_add_item(tree, proto_lppa, tvb, 0, -1, ENC_NA);
col_append_sep_str(actx->pinfo->cinfo, COL_PROTOCOL, "/", "LPPa");
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_LPPA_PDU, LPPA_PDU_choice,
NULL);
return offset;
}
static int
dissect_lppa_BCCH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_lppa_Cell_Portion_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_CPLength(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_lppa_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_lppa_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_lppa_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_lppa_EUTRANCellIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_ECGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ECGI, ECGI_sequence);
return offset;
}
static int
dissect_lppa_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_lppa_T_latitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_T_directionOfAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_E_UTRANAccessPointPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_UTRANAccessPointPosition, E_UTRANAccessPointPosition_sequence);
return offset;
}
static int
dissect_lppa_INTEGER_0_719(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 719U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_7690(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7690U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_PCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_EARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_ValueRSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_ResultRSRP_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultRSRP_Item, ResultRSRP_Item_sequence);
return offset;
}
static int
dissect_lppa_ResultRSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultRSRP, ResultRSRP_sequence_of,
1, maxCellReport, FALSE);
return offset;
}
static int
dissect_lppa_ValueRSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_ResultRSRQ_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultRSRQ_Item, ResultRSRQ_Item_sequence);
return offset;
}
static int
dissect_lppa_ResultRSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultRSRQ, ResultRSRQ_sequence_of,
1, maxCellReport, FALSE);
return offset;
}
static int
dissect_lppa_MeasuredResultsValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_MeasuredResultsValue, MeasuredResultsValue_choice,
NULL);
return offset;
}
static int
dissect_lppa_MeasuredResults(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_MeasuredResults, MeasuredResults_sequence_of,
1, maxNoMeas, FALSE);
return offset;
}
static int
dissect_lppa_E_CID_MeasurementResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CID_MeasurementResult, E_CID_MeasurementResult_sequence);
return offset;
}
static int
dissect_lppa_InterRATMeasurementQuantities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_InterRATMeasurementQuantities, InterRATMeasurementQuantities_sequence_of,
0, maxNoMeas, FALSE);
return offset;
}
static int
dissect_lppa_InterRATMeasurementQuantitiesValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_InterRATMeasurementQuantities_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_InterRATMeasurementQuantities_Item, InterRATMeasurementQuantities_Item_sequence);
return offset;
}
static int
dissect_lppa_PhysCellIDGERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_RSSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_ResultGERAN_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultGERAN_Item, ResultGERAN_Item_sequence);
return offset;
}
static int
dissect_lppa_ResultGERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultGERAN, ResultGERAN_sequence_of,
1, maxGERANMeas, FALSE);
return offset;
}
static int
dissect_lppa_UARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_PhysCellIDUTRA_FDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_PhysCellIDUTRA_TDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_T_physCellIDUTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_T_physCellIDUTRAN, T_physCellIDUTRAN_choice,
NULL);
return offset;
}
static int
dissect_lppa_UTRA_RSCP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-5, 91U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_UTRA_EcN0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 49U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_ResultUTRAN_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultUTRAN_Item, ResultUTRAN_Item_sequence);
return offset;
}
static int
dissect_lppa_ResultUTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_ResultUTRAN, ResultUTRAN_sequence_of,
1, maxUTRANMeas, FALSE);
return offset;
}
static int
dissect_lppa_InterRATMeasuredResultsValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_InterRATMeasuredResultsValue, InterRATMeasuredResultsValue_choice,
NULL);
return offset;
}
static int
dissect_lppa_InterRATMeasurementResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_InterRATMeasurementResult, InterRATMeasurementResult_sequence_of,
1, maxNoMeas, FALSE);
return offset;
}
static int
dissect_lppa_Measurement_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_MeasurementPeriodicity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_MeasurementQuantities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_MeasurementQuantities, MeasurementQuantities_sequence_of,
1, maxNoMeas, FALSE);
return offset;
}
static int
dissect_lppa_MeasurementQuantitiesValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_MeasurementQuantities_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_MeasurementQuantities_Item, MeasurementQuantities_Item_sequence);
return offset;
}
static int
dissect_lppa_NumberOfAntennaPorts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_NumberOfDlFrames(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_PRS_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_PRS_Configuration_Index(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_SFNInitialisationTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_BIT_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_BIT_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_BIT_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_BIT_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lppa_PRSMutingConfiguration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_PRSMutingConfiguration, PRSMutingConfiguration_choice,
NULL);
return offset;
}
static int
dissect_lppa_OTDOACell_Information_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOACell_Information_Item, OTDOACell_Information_Item_choice,
NULL);
return offset;
}
static int
dissect_lppa_OTDOACell_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOACell_Information, OTDOACell_Information_sequence_of,
1, maxnoOTDOAtypes, FALSE);
return offset;
}
static int
dissect_lppa_OTDOACells_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOACells_item, OTDOACells_item_sequence);
return offset;
}
static int
dissect_lppa_OTDOACells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOACells, OTDOACells_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_lppa_OTDOA_Information_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_lppa_ReportCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_500_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 500U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_INTEGER_1_100_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, TRUE);
return offset;
}
static int
dissect_lppa_RequestedSRSTransmissionCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_RequestedSRSTransmissionCharacteristics, RequestedSRSTransmissionCharacteristics_sequence);
return offset;
}
static int
dissect_lppa_T_ul_bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_srs_BandwidthConfig(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_srs_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_srs_AntennaPort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_srs_HoppingBandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_T_srs_cyclicShift(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_T_maxUpPts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_INTEGER_0_23(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 23U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lppa_INTEGER_0_29(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 29U, NULL, FALSE);
return offset;
}
static int
dissect_lppa_SRSConfigurationForOneCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_SRSConfigurationForOneCell, SRSConfigurationForOneCell_sequence);
return offset;
}
static int
dissect_lppa_SRSConfigurationForAllCells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_SRSConfigurationForAllCells, SRSConfigurationForAllCells_sequence_of,
1, maxServCell, FALSE);
return offset;
}
static int
dissect_lppa_ULConfiguration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ULConfiguration, ULConfiguration_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementInitiationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementInitiationRequest, E_CIDMeasurementInitiationRequest_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementInitiationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementInitiationResponse, E_CIDMeasurementInitiationResponse_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementInitiationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementInitiationFailure, E_CIDMeasurementInitiationFailure_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementFailureIndication, E_CIDMeasurementFailureIndication_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementReport, E_CIDMeasurementReport_sequence);
return offset;
}
static int
dissect_lppa_E_CIDMeasurementTerminationCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_E_CIDMeasurementTerminationCommand, E_CIDMeasurementTerminationCommand_sequence);
return offset;
}
static int
dissect_lppa_OTDOAInformationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOAInformationRequest, OTDOAInformationRequest_sequence);
return offset;
}
static int
dissect_lppa_OTDOA_Information_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOA_Information_Type, OTDOA_Information_Type_sequence_of,
1, maxnoOTDOAtypes, FALSE);
return offset;
}
static int
dissect_lppa_OTDOA_Information_Type_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOA_Information_Type_Item, OTDOA_Information_Type_Item_sequence);
return offset;
}
static int
dissect_lppa_OTDOAInformationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOAInformationResponse, OTDOAInformationResponse_sequence);
return offset;
}
static int
dissect_lppa_OTDOAInformationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_OTDOAInformationFailure, OTDOAInformationFailure_sequence);
return offset;
}
static int
dissect_lppa_UTDOAInformationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_UTDOAInformationRequest, UTDOAInformationRequest_sequence);
return offset;
}
static int
dissect_lppa_UTDOAInformationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_UTDOAInformationResponse, UTDOAInformationResponse_sequence);
return offset;
}
static int
dissect_lppa_UTDOAInformationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_UTDOAInformationFailure, UTDOAInformationFailure_sequence);
return offset;
}
static int
dissect_lppa_UTDOAInformationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_UTDOAInformationUpdate, UTDOAInformationUpdate_sequence);
return offset;
}
static int
dissect_lppa_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_lppa_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lppa_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int dissect_LPPA_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_LPPA_PDU(tvb, offset, &asn1_ctx, tree, hf_lppa_LPPA_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_Cause(tvb, offset, &asn1_ctx, tree, hf_lppa_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cell_Portion_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_Cell_Portion_ID(tvb, offset, &asn1_ctx, tree, hf_lppa_Cell_Portion_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_lppa_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CID_MeasurementResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CID_MeasurementResult(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CID_MeasurementResult_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InterRATMeasurementQuantities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_InterRATMeasurementQuantities(tvb, offset, &asn1_ctx, tree, hf_lppa_InterRATMeasurementQuantities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InterRATMeasurementQuantities_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_InterRATMeasurementQuantities_Item(tvb, offset, &asn1_ctx, tree, hf_lppa_InterRATMeasurementQuantities_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InterRATMeasurementResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_InterRATMeasurementResult(tvb, offset, &asn1_ctx, tree, hf_lppa_InterRATMeasurementResult_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Measurement_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_Measurement_ID(tvb, offset, &asn1_ctx, tree, hf_lppa_Measurement_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementPeriodicity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_MeasurementPeriodicity(tvb, offset, &asn1_ctx, tree, hf_lppa_MeasurementPeriodicity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementQuantities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_MeasurementQuantities(tvb, offset, &asn1_ctx, tree, hf_lppa_MeasurementQuantities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementQuantities_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_MeasurementQuantities_Item(tvb, offset, &asn1_ctx, tree, hf_lppa_MeasurementQuantities_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOACells_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOACells(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOACells_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportCharacteristics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_ReportCharacteristics(tvb, offset, &asn1_ctx, tree, hf_lppa_ReportCharacteristics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RequestedSRSTransmissionCharacteristics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_RequestedSRSTransmissionCharacteristics(tvb, offset, &asn1_ctx, tree, hf_lppa_RequestedSRSTransmissionCharacteristics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ULConfiguration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_ULConfiguration(tvb, offset, &asn1_ctx, tree, hf_lppa_ULConfiguration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementInitiationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementInitiationRequest(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementInitiationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementInitiationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementInitiationResponse(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementInitiationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementInitiationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementInitiationFailure(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementInitiationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementFailureIndication(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementReport(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CIDMeasurementTerminationCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_E_CIDMeasurementTerminationCommand(tvb, offset, &asn1_ctx, tree, hf_lppa_E_CIDMeasurementTerminationCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOAInformationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOAInformationRequest(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOAInformationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOA_Information_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOA_Information_Type(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOA_Information_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOA_Information_Type_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOA_Information_Type_Item(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOA_Information_Type_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOAInformationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOAInformationResponse(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOAInformationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OTDOAInformationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_OTDOAInformationFailure(tvb, offset, &asn1_ctx, tree, hf_lppa_OTDOAInformationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UTDOAInformationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_UTDOAInformationRequest(tvb, offset, &asn1_ctx, tree, hf_lppa_UTDOAInformationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UTDOAInformationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_UTDOAInformationResponse(tvb, offset, &asn1_ctx, tree, hf_lppa_UTDOAInformationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UTDOAInformationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_UTDOAInformationFailure(tvb, offset, &asn1_ctx, tree, hf_lppa_UTDOAInformationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UTDOAInformationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_UTDOAInformationUpdate(tvb, offset, &asn1_ctx, tree, hf_lppa_UTDOAInformationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_lppa_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lppa_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_lppa_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lppa_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lppa_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lppa_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lppa_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
void proto_register_lppa(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/lppa/packet-lppa-hfarr.c"
{ &hf_lppa_LPPA_PDU_PDU,
{ "LPPA-PDU", "lppa.LPPA_PDU",
FT_UINT32, BASE_DEC, VALS(lppa_LPPA_PDU_vals), 0,
NULL, HFILL }},
{ &hf_lppa_Cause_PDU,
{ "Cause", "lppa.Cause",
FT_UINT32, BASE_DEC, VALS(lppa_Cause_vals), 0,
NULL, HFILL }},
{ &hf_lppa_Cell_Portion_ID_PDU,
{ "Cell-Portion-ID", "lppa.Cell_Portion_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "lppa.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CID_MeasurementResult_PDU,
{ "E-CID-MeasurementResult", "lppa.E_CID_MeasurementResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_InterRATMeasurementQuantities_PDU,
{ "InterRATMeasurementQuantities", "lppa.InterRATMeasurementQuantities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_InterRATMeasurementQuantities_Item_PDU,
{ "InterRATMeasurementQuantities-Item", "lppa.InterRATMeasurementQuantities_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_InterRATMeasurementResult_PDU,
{ "InterRATMeasurementResult", "lppa.InterRATMeasurementResult",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_Measurement_ID_PDU,
{ "Measurement-ID", "lppa.Measurement_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_MeasurementPeriodicity_PDU,
{ "MeasurementPeriodicity", "lppa.MeasurementPeriodicity",
FT_UINT32, BASE_DEC, VALS(lppa_MeasurementPeriodicity_vals), 0,
NULL, HFILL }},
{ &hf_lppa_MeasurementQuantities_PDU,
{ "MeasurementQuantities", "lppa.MeasurementQuantities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_MeasurementQuantities_Item_PDU,
{ "MeasurementQuantities-Item", "lppa.MeasurementQuantities_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOACells_PDU,
{ "OTDOACells", "lppa.OTDOACells",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ReportCharacteristics_PDU,
{ "ReportCharacteristics", "lppa.ReportCharacteristics",
FT_UINT32, BASE_DEC, VALS(lppa_ReportCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_lppa_RequestedSRSTransmissionCharacteristics_PDU,
{ "RequestedSRSTransmissionCharacteristics", "lppa.RequestedSRSTransmissionCharacteristics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ULConfiguration_PDU,
{ "ULConfiguration", "lppa.ULConfiguration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementInitiationRequest_PDU,
{ "E-CIDMeasurementInitiationRequest", "lppa.E_CIDMeasurementInitiationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementInitiationResponse_PDU,
{ "E-CIDMeasurementInitiationResponse", "lppa.E_CIDMeasurementInitiationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementInitiationFailure_PDU,
{ "E-CIDMeasurementInitiationFailure", "lppa.E_CIDMeasurementInitiationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementFailureIndication_PDU,
{ "E-CIDMeasurementFailureIndication", "lppa.E_CIDMeasurementFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementReport_PDU,
{ "E-CIDMeasurementReport", "lppa.E_CIDMeasurementReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_E_CIDMeasurementTerminationCommand_PDU,
{ "E-CIDMeasurementTerminationCommand", "lppa.E_CIDMeasurementTerminationCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOAInformationRequest_PDU,
{ "OTDOAInformationRequest", "lppa.OTDOAInformationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOA_Information_Type_PDU,
{ "OTDOA-Information-Type", "lppa.OTDOA_Information_Type",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOA_Information_Type_Item_PDU,
{ "OTDOA-Information-Type-Item", "lppa.OTDOA_Information_Type_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOAInformationResponse_PDU,
{ "OTDOAInformationResponse", "lppa.OTDOAInformationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOAInformationFailure_PDU,
{ "OTDOAInformationFailure", "lppa.OTDOAInformationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_UTDOAInformationRequest_PDU,
{ "UTDOAInformationRequest", "lppa.UTDOAInformationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_UTDOAInformationResponse_PDU,
{ "UTDOAInformationResponse", "lppa.UTDOAInformationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_UTDOAInformationFailure_PDU,
{ "UTDOAInformationFailure", "lppa.UTDOAInformationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_UTDOAInformationUpdate_PDU,
{ "UTDOAInformationUpdate", "lppa.UTDOAInformationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ErrorIndication_PDU,
{ "ErrorIndication", "lppa.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_PrivateMessage_PDU,
{ "PrivateMessage", "lppa.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_local,
{ "local", "lppa.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxPrivateIEs", HFILL }},
{ &hf_lppa_global,
{ "global", "lppa.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_lppa_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "lppa.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_id,
{ "id", "lppa.id",
FT_UINT32, BASE_DEC, VALS(lppa_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_lppa_criticality,
{ "criticality", "lppa.criticality",
FT_UINT32, BASE_DEC, VALS(lppa_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_lppa_ie_field_value,
{ "value", "lppa.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_lppa_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "lppa.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_extensionValue,
{ "extensionValue", "lppa.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_PrivateIE_Container_item,
{ "PrivateIE-Field", "lppa.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_id_01,
{ "id", "lppa.id",
FT_UINT32, BASE_DEC, VALS(lppa_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_lppa_value,
{ "value", "lppa.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_initiatingMessage,
{ "initiatingMessage", "lppa.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_successfulOutcome,
{ "successfulOutcome", "lppa.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "lppa.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_procedureCode,
{ "procedureCode", "lppa.procedureCode",
FT_UINT32, BASE_DEC, VALS(lppa_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_lppa_lppatransactionID,
{ "lppatransactionID", "lppa.lppatransactionID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_initiatingMessagevalue,
{ "value", "lppa.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_lppa_successfulOutcome_value,
{ "value", "lppa.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_lppa_unsuccessfulOutcome_value,
{ "value", "lppa.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
{ &hf_lppa_radioNetwork,
{ "radioNetwork", "lppa.radioNetwork",
FT_UINT32, BASE_DEC, VALS(lppa_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_lppa_protocol,
{ "protocol", "lppa.protocol",
FT_UINT32, BASE_DEC, VALS(lppa_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_lppa_misc,
{ "misc", "lppa.misc",
FT_UINT32, BASE_DEC, VALS(lppa_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_lppa_triggeringMessage,
{ "triggeringMessage", "lppa.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(lppa_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_lppa_procedureCriticality,
{ "procedureCriticality", "lppa.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(lppa_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_lppa_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "lppa.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_lppa_iE_Extensions,
{ "iE-Extensions", "lppa.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_lppa_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "lppa.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_iECriticality,
{ "iECriticality", "lppa.iECriticality",
FT_UINT32, BASE_DEC, VALS(lppa_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_lppa_iE_ID,
{ "iE-ID", "lppa.iE_ID",
FT_UINT32, BASE_DEC, VALS(lppa_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_lppa_typeOfError,
{ "typeOfError", "lppa.typeOfError",
FT_UINT32, BASE_DEC, VALS(lppa_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_lppa_servingCell_ID,
{ "servingCell-ID", "lppa.servingCell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lppa_servingCellTAC,
{ "servingCellTAC", "lppa.servingCellTAC",
FT_BYTES, BASE_NONE, NULL, 0,
"TAC", HFILL }},
{ &hf_lppa_e_UTRANAccessPointPosition,
{ "e-UTRANAccessPointPosition", "lppa.e_UTRANAccessPointPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_measuredResults,
{ "measuredResults", "lppa.measuredResults",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_pLMN_Identity,
{ "pLMN-Identity", "lppa.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_eUTRANcellIdentifier,
{ "eUTRANcellIdentifier", "lppa.eUTRANcellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_latitudeSign,
{ "latitudeSign", "lppa.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lppa_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_lppa_latitude,
{ "latitude", "lppa.latitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_lppa_longitude,
{ "longitude", "lppa.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lppa_directionOfAltitude,
{ "directionOfAltitude", "lppa.directionOfAltitude",
FT_UINT32, BASE_DEC, VALS(lppa_T_directionOfAltitude_vals), 0,
NULL, HFILL }},
{ &hf_lppa_altitude,
{ "altitude", "lppa.altitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_lppa_uncertaintySemi_major,
{ "uncertaintySemi-major", "lppa.uncertaintySemi_major",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppa_uncertaintySemi_minor,
{ "uncertaintySemi-minor", "lppa.uncertaintySemi_minor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppa_orientationOfMajorAxis,
{ "orientationOfMajorAxis", "lppa.orientationOfMajorAxis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_lppa_uncertaintyAltitude,
{ "uncertaintyAltitude", "lppa.uncertaintyAltitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lppa_confidence,
{ "confidence", "lppa.confidence",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_100", HFILL }},
{ &hf_lppa_InterRATMeasurementQuantities_item,
{ "ProtocolIE-Single-Container", "lppa.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_interRATMeasurementQuantitiesValue,
{ "interRATMeasurementQuantitiesValue", "lppa.interRATMeasurementQuantitiesValue",
FT_UINT32, BASE_DEC, VALS(lppa_InterRATMeasurementQuantitiesValue_vals), 0,
NULL, HFILL }},
{ &hf_lppa_InterRATMeasurementResult_item,
{ "InterRATMeasuredResultsValue", "lppa.InterRATMeasuredResultsValue",
FT_UINT32, BASE_DEC, VALS(lppa_InterRATMeasuredResultsValue_vals), 0,
NULL, HFILL }},
{ &hf_lppa_resultGERAN,
{ "resultGERAN", "lppa.resultGERAN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_resultUTRAN,
{ "resultUTRAN", "lppa.resultUTRAN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_MeasurementQuantities_item,
{ "ProtocolIE-Single-Container", "lppa.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_measurementQuantitiesValue,
{ "measurementQuantitiesValue", "lppa.measurementQuantitiesValue",
FT_UINT32, BASE_DEC, VALS(lppa_MeasurementQuantitiesValue_vals), 0,
NULL, HFILL }},
{ &hf_lppa_MeasuredResults_item,
{ "MeasuredResultsValue", "lppa.MeasuredResultsValue",
FT_UINT32, BASE_DEC, VALS(lppa_MeasuredResultsValue_vals), 0,
NULL, HFILL }},
{ &hf_lppa_valueAngleOfArrival,
{ "valueAngleOfArrival", "lppa.valueAngleOfArrival",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_719", HFILL }},
{ &hf_lppa_valueTimingAdvanceType1,
{ "valueTimingAdvanceType1", "lppa.valueTimingAdvanceType1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7690", HFILL }},
{ &hf_lppa_valueTimingAdvanceType2,
{ "valueTimingAdvanceType2", "lppa.valueTimingAdvanceType2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7690", HFILL }},
{ &hf_lppa_resultRSRP,
{ "resultRSRP", "lppa.resultRSRP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_resultRSRQ,
{ "resultRSRQ", "lppa.resultRSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_OTDOACells_item,
{ "OTDOACells item", "lppa.OTDOACells_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_oTDOACellInfo,
{ "oTDOACellInfo", "lppa.oTDOACellInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"OTDOACell_Information", HFILL }},
{ &hf_lppa_OTDOACell_Information_item,
{ "OTDOACell-Information-Item", "lppa.OTDOACell_Information_Item",
FT_UINT32, BASE_DEC, VALS(lppa_OTDOACell_Information_Item_vals), 0,
NULL, HFILL }},
{ &hf_lppa_pCI,
{ "pCI", "lppa.pCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_cellId,
{ "cellId", "lppa.cellId_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lppa_tAC,
{ "tAC", "lppa.tAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_eARFCN,
{ "eARFCN", "lppa.eARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_pRS_Bandwidth,
{ "pRS-Bandwidth", "lppa.pRS_Bandwidth",
FT_UINT32, BASE_DEC, VALS(lppa_PRS_Bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_lppa_pRS_ConfigurationIndex,
{ "pRS-ConfigurationIndex", "lppa.pRS_ConfigurationIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"PRS_Configuration_Index", HFILL }},
{ &hf_lppa_cPLength,
{ "cPLength", "lppa.cPLength",
FT_UINT32, BASE_DEC, VALS(lppa_CPLength_vals), 0,
NULL, HFILL }},
{ &hf_lppa_numberOfDlFrames,
{ "numberOfDlFrames", "lppa.numberOfDlFrames",
FT_UINT32, BASE_DEC, VALS(lppa_NumberOfDlFrames_vals), 0,
NULL, HFILL }},
{ &hf_lppa_numberOfAntennaPorts,
{ "numberOfAntennaPorts", "lppa.numberOfAntennaPorts",
FT_UINT32, BASE_DEC, VALS(lppa_NumberOfAntennaPorts_vals), 0,
NULL, HFILL }},
{ &hf_lppa_sFNInitialisationTime,
{ "sFNInitialisationTime", "lppa.sFNInitialisationTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_pRSMutingConfiguration,
{ "pRSMutingConfiguration", "lppa.pRSMutingConfiguration",
FT_UINT32, BASE_DEC, VALS(lppa_PRSMutingConfiguration_vals), 0,
NULL, HFILL }},
{ &hf_lppa_two,
{ "two", "lppa.two",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_lppa_four,
{ "four", "lppa.four",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_lppa_eight,
{ "eight", "lppa.eight",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lppa_sixteen,
{ "sixteen", "lppa.sixteen",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lppa_numberOfTransmissions,
{ "numberOfTransmissions", "lppa.numberOfTransmissions",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_500_", HFILL }},
{ &hf_lppa_bandwidth,
{ "bandwidth", "lppa.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100_", HFILL }},
{ &hf_lppa_ResultRSRP_item,
{ "ResultRSRP-Item", "lppa.ResultRSRP_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_eCGI,
{ "eCGI", "lppa.eCGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_valueRSRP,
{ "valueRSRP", "lppa.valueRSRP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ResultRSRQ_item,
{ "ResultRSRQ-Item", "lppa.ResultRSRQ_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_valueRSRQ,
{ "valueRSRQ", "lppa.valueRSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ResultGERAN_item,
{ "ResultGERAN-Item", "lppa.ResultGERAN_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_bCCH,
{ "bCCH", "lppa.bCCH",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_physCellIDGERAN,
{ "physCellIDGERAN", "lppa.physCellIDGERAN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_rSSI,
{ "rSSI", "lppa.rSSI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ResultUTRAN_item,
{ "ResultUTRAN-Item", "lppa.ResultUTRAN_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_uARFCN,
{ "uARFCN", "lppa.uARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_physCellIDUTRAN,
{ "physCellIDUTRAN", "lppa.physCellIDUTRAN",
FT_UINT32, BASE_DEC, VALS(lppa_T_physCellIDUTRAN_vals), 0,
NULL, HFILL }},
{ &hf_lppa_physCellIDUTRA_FDD,
{ "physCellIDUTRA-FDD", "lppa.physCellIDUTRA_FDD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_physCellIDUTRA_TDD,
{ "physCellIDUTRA-TDD", "lppa.physCellIDUTRA_TDD",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_uTRA_RSCP,
{ "uTRA-RSCP", "lppa.uTRA_RSCP",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_uTRA_EcN0,
{ "uTRA-EcN0", "lppa.uTRA_EcN0",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_SRSConfigurationForAllCells_item,
{ "SRSConfigurationForOneCell", "lppa.SRSConfigurationForOneCell_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_pci,
{ "pci", "lppa.pci",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_ul_earfcn,
{ "ul-earfcn", "lppa.ul_earfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_lppa_ul_bandwidth,
{ "ul-bandwidth", "lppa.ul_bandwidth",
FT_UINT32, BASE_DEC, VALS(lppa_T_ul_bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_lppa_ul_cyclicPrefixLength,
{ "ul-cyclicPrefixLength", "lppa.ul_cyclicPrefixLength",
FT_UINT32, BASE_DEC, VALS(lppa_CPLength_vals), 0,
"CPLength", HFILL }},
{ &hf_lppa_srs_BandwidthConfig,
{ "srs-BandwidthConfig", "lppa.srs_BandwidthConfig",
FT_UINT32, BASE_DEC, VALS(lppa_T_srs_BandwidthConfig_vals), 0,
NULL, HFILL }},
{ &hf_lppa_srs_Bandwidth,
{ "srs-Bandwidth", "lppa.srs_Bandwidth",
FT_UINT32, BASE_DEC, VALS(lppa_T_srs_Bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_lppa_srs_AntennaPort,
{ "srs-AntennaPort", "lppa.srs_AntennaPort",
FT_UINT32, BASE_DEC, VALS(lppa_T_srs_AntennaPort_vals), 0,
NULL, HFILL }},
{ &hf_lppa_srs_HoppingBandwidth,
{ "srs-HoppingBandwidth", "lppa.srs_HoppingBandwidth",
FT_UINT32, BASE_DEC, VALS(lppa_T_srs_HoppingBandwidth_vals), 0,
NULL, HFILL }},
{ &hf_lppa_srs_cyclicShift,
{ "srs-cyclicShift", "lppa.srs_cyclicShift",
FT_UINT32, BASE_DEC, VALS(lppa_T_srs_cyclicShift_vals), 0,
NULL, HFILL }},
{ &hf_lppa_srs_ConfigIndex,
{ "srs-ConfigIndex", "lppa.srs_ConfigIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lppa_maxUpPts,
{ "maxUpPts", "lppa.maxUpPts",
FT_UINT32, BASE_DEC, VALS(lppa_T_maxUpPts_vals), 0,
NULL, HFILL }},
{ &hf_lppa_transmissionComb,
{ "transmissionComb", "lppa.transmissionComb",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lppa_freqDomainPosition,
{ "freqDomainPosition", "lppa.freqDomainPosition",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_23", HFILL }},
{ &hf_lppa_groupHoppingEnabled,
{ "groupHoppingEnabled", "lppa.groupHoppingEnabled",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lppa_deltaSS,
{ "deltaSS", "lppa.deltaSS",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_29", HFILL }},
{ &hf_lppa_sfnInitialisationTime,
{ "sfnInitialisationTime", "lppa.sfnInitialisationTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_timingAdvanceType1,
{ "timingAdvanceType1", "lppa.timingAdvanceType1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7690", HFILL }},
{ &hf_lppa_timingAdvanceType2,
{ "timingAdvanceType2", "lppa.timingAdvanceType2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7690", HFILL }},
{ &hf_lppa_srsConfiguration,
{ "srsConfiguration", "lppa.srsConfiguration",
FT_UINT32, BASE_DEC, NULL, 0,
"SRSConfigurationForAllCells", HFILL }},
{ &hf_lppa_protocolIEs,
{ "protocolIEs", "lppa.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_lppa_OTDOA_Information_Type_item,
{ "ProtocolIE-Single-Container", "lppa.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lppa_oTDOA_Information_Type_Item,
{ "oTDOA-Information-Type-Item", "lppa.oTDOA_Information_Type_Item",
FT_UINT32, BASE_DEC, VALS(lppa_OTDOA_Information_Item_vals), 0,
"OTDOA_Information_Item", HFILL }},
{ &hf_lppa_privateIEs,
{ "privateIEs", "lppa.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
#line 97 "./asn1/lppa/packet-lppa-template.c"
};
static gint *ett[] = {
&ett_lppa,
#line 1 "./asn1/lppa/packet-lppa-ettarr.c"
&ett_lppa_PrivateIE_ID,
&ett_lppa_ProtocolIE_Container,
&ett_lppa_ProtocolIE_Field,
&ett_lppa_ProtocolExtensionContainer,
&ett_lppa_ProtocolExtensionField,
&ett_lppa_PrivateIE_Container,
&ett_lppa_PrivateIE_Field,
&ett_lppa_LPPA_PDU,
&ett_lppa_InitiatingMessage,
&ett_lppa_SuccessfulOutcome,
&ett_lppa_UnsuccessfulOutcome,
&ett_lppa_Cause,
&ett_lppa_CriticalityDiagnostics,
&ett_lppa_CriticalityDiagnostics_IE_List,
&ett_lppa_CriticalityDiagnostics_IE_List_item,
&ett_lppa_E_CID_MeasurementResult,
&ett_lppa_ECGI,
&ett_lppa_E_UTRANAccessPointPosition,
&ett_lppa_InterRATMeasurementQuantities,
&ett_lppa_InterRATMeasurementQuantities_Item,
&ett_lppa_InterRATMeasurementResult,
&ett_lppa_InterRATMeasuredResultsValue,
&ett_lppa_MeasurementQuantities,
&ett_lppa_MeasurementQuantities_Item,
&ett_lppa_MeasuredResults,
&ett_lppa_MeasuredResultsValue,
&ett_lppa_OTDOACells,
&ett_lppa_OTDOACells_item,
&ett_lppa_OTDOACell_Information,
&ett_lppa_OTDOACell_Information_Item,
&ett_lppa_PRSMutingConfiguration,
&ett_lppa_RequestedSRSTransmissionCharacteristics,
&ett_lppa_ResultRSRP,
&ett_lppa_ResultRSRP_Item,
&ett_lppa_ResultRSRQ,
&ett_lppa_ResultRSRQ_Item,
&ett_lppa_ResultGERAN,
&ett_lppa_ResultGERAN_Item,
&ett_lppa_ResultUTRAN,
&ett_lppa_ResultUTRAN_Item,
&ett_lppa_T_physCellIDUTRAN,
&ett_lppa_SRSConfigurationForAllCells,
&ett_lppa_SRSConfigurationForOneCell,
&ett_lppa_ULConfiguration,
&ett_lppa_E_CIDMeasurementInitiationRequest,
&ett_lppa_E_CIDMeasurementInitiationResponse,
&ett_lppa_E_CIDMeasurementInitiationFailure,
&ett_lppa_E_CIDMeasurementFailureIndication,
&ett_lppa_E_CIDMeasurementReport,
&ett_lppa_E_CIDMeasurementTerminationCommand,
&ett_lppa_OTDOAInformationRequest,
&ett_lppa_OTDOA_Information_Type,
&ett_lppa_OTDOA_Information_Type_Item,
&ett_lppa_OTDOAInformationResponse,
&ett_lppa_OTDOAInformationFailure,
&ett_lppa_UTDOAInformationRequest,
&ett_lppa_UTDOAInformationResponse,
&ett_lppa_UTDOAInformationFailure,
&ett_lppa_UTDOAInformationUpdate,
&ett_lppa_ErrorIndication,
&ett_lppa_PrivateMessage,
#line 103 "./asn1/lppa/packet-lppa-template.c"
};
proto_lppa = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("lppa", dissect_LPPA_PDU_PDU, proto_lppa);
proto_register_field_array(proto_lppa, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lppa_ies_dissector_table = register_dissector_table("lppa.ies", "LPPA-PROTOCOL-IES", proto_lppa, FT_UINT32, BASE_DEC);
lppa_proc_imsg_dissector_table = register_dissector_table("lppa.proc.imsg", "LPPA-ELEMENTARY-PROCEDURE InitiatingMessage", proto_lppa, FT_UINT32, BASE_DEC);
lppa_proc_sout_dissector_table = register_dissector_table("lppa.proc.sout", "LPPA-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_lppa, FT_UINT32, BASE_DEC);
lppa_proc_uout_dissector_table = register_dissector_table("lppa.proc.uout", "LPPA-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_lppa, FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_lppa(void)
{
#line 1 "./asn1/lppa/packet-lppa-dis-tab.c"
dissector_add_uint("lppa.ies", id_MeasurementQuantities_Item, create_dissector_handle(dissect_MeasurementQuantities_Item_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_ReportCharacteristics, create_dissector_handle(dissect_ReportCharacteristics_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_MeasurementPeriodicity, create_dissector_handle(dissect_MeasurementPeriodicity_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_MeasurementQuantities, create_dissector_handle(dissect_MeasurementQuantities_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_E_CID_MeasurementResult, create_dissector_handle(dissect_E_CID_MeasurementResult_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_OTDOA_Information_Type_Group, create_dissector_handle(dissect_OTDOA_Information_Type_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_OTDOA_Information_Type_Item, create_dissector_handle(dissect_OTDOA_Information_Type_Item_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_OTDOACells, create_dissector_handle(dissect_OTDOACells_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_E_SMLC_UE_Measurement_ID, create_dissector_handle(dissect_Measurement_ID_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_eNB_UE_Measurement_ID, create_dissector_handle(dissect_Measurement_ID_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_RequestedSRSTransmissionCharacteristics, create_dissector_handle(dissect_RequestedSRSTransmissionCharacteristics_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_ULConfiguration, create_dissector_handle(dissect_ULConfiguration_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_InterRATMeasurementQuantities, create_dissector_handle(dissect_InterRATMeasurementQuantities_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_Cell_Portion_ID, create_dissector_handle(dissect_Cell_Portion_ID_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_InterRATMeasurementResult, create_dissector_handle(dissect_InterRATMeasurementResult_PDU, proto_lppa));
dissector_add_uint("lppa.ies", id_InterRATMeasurementQuantities_Item, create_dissector_handle(dissect_InterRATMeasurementQuantities_Item_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_e_CIDMeasurementInitiation, create_dissector_handle(dissect_E_CIDMeasurementInitiationRequest_PDU, proto_lppa));
dissector_add_uint("lppa.proc.sout", id_e_CIDMeasurementInitiation, create_dissector_handle(dissect_E_CIDMeasurementInitiationResponse_PDU, proto_lppa));
dissector_add_uint("lppa.proc.uout", id_e_CIDMeasurementInitiation, create_dissector_handle(dissect_E_CIDMeasurementInitiationFailure_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_e_CIDMeasurementFailureIndication, create_dissector_handle(dissect_E_CIDMeasurementFailureIndication_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_e_CIDMeasurementReport, create_dissector_handle(dissect_E_CIDMeasurementReport_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_e_CIDMeasurementTermination, create_dissector_handle(dissect_E_CIDMeasurementTerminationCommand_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_oTDOAInformationExchange, create_dissector_handle(dissect_OTDOAInformationRequest_PDU, proto_lppa));
dissector_add_uint("lppa.proc.sout", id_oTDOAInformationExchange, create_dissector_handle(dissect_OTDOAInformationResponse_PDU, proto_lppa));
dissector_add_uint("lppa.proc.uout", id_oTDOAInformationExchange, create_dissector_handle(dissect_OTDOAInformationFailure_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_errorIndication, create_dissector_handle(dissect_ErrorIndication_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_privateMessage, create_dissector_handle(dissect_PrivateMessage_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_uTDOAInformationExchange, create_dissector_handle(dissect_UTDOAInformationRequest_PDU, proto_lppa));
dissector_add_uint("lppa.proc.sout", id_uTDOAInformationExchange, create_dissector_handle(dissect_UTDOAInformationResponse_PDU, proto_lppa));
dissector_add_uint("lppa.proc.uout", id_uTDOAInformationExchange, create_dissector_handle(dissect_UTDOAInformationFailure_PDU, proto_lppa));
dissector_add_uint("lppa.proc.imsg", id_uTDOAInformationUpdate, create_dissector_handle(dissect_UTDOAInformationUpdate_PDU, proto_lppa));
#line 125 "./asn1/lppa/packet-lppa-template.c"
}
