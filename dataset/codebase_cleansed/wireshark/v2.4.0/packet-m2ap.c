static int
dissect_m2ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_INTEGER_0_maxPrivateIEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxPrivateIEs, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_m2ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_m2ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
return offset;
}
static int
dissect_m2ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 47 "./asn1/m2ap/m2ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(ProtocolIE_ID, &m2ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_m2ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_m2ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_m2ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_m2ap_ProtocolIE_Single_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_m2ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_m2ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_m2ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_m2ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_m2ap_T_private_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_m2ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_m2ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_m2ap_AllocatedSubframesEnd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1535U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_m2ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(10000000000), NULL, FALSE);
return offset;
}
static int
dissect_m2ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_m2ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_CauseNAS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_m2ap_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 70 "./asn1/m2ap/m2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_m2ap_PLMN_Identity);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
}
return offset;
}
static int
dissect_m2ap_EUTRANCellIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_m2ap_ECGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ECGI, ECGI_sequence);
return offset;
}
static int
dissect_m2ap_T_cellReservationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_Cell_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_Cell_Information, Cell_Information_sequence);
return offset;
}
static int
dissect_m2ap_Cell_Information_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_Cell_Information_List, Cell_Information_List_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_m2ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_m2ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxnooferrors, FALSE);
return offset;
}
static int
dissect_m2ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_m2ap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_m2ap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_m2ap_MBSFN_SynchronisationArea_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Service_Area(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_m2ap_MBMS_Service_Area_ID_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Service_Area_ID_List, MBMS_Service_Area_ID_List_sequence_of,
1, maxnoofMBMSServiceAreasPerCell, FALSE);
return offset;
}
static int
dissect_m2ap_ENB_MBMS_Configuration_data_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENB_MBMS_Configuration_data_Item, ENB_MBMS_Configuration_data_Item_sequence);
return offset;
}
static int
dissect_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item, ENB_MBMS_Configuration_data_ConfigUpdate_Item_choice,
NULL);
return offset;
}
static int
dissect_m2ap_ENB_MBMS_M2AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_ENBname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
return offset;
}
static int
dissect_m2ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_m2ap_GlobalENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_GlobalENB_ID, GlobalENB_ID_sequence);
return offset;
}
static int
dissect_m2ap_MCE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_m2ap_GlobalMCE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_GlobalMCE_ID, GlobalMCE_ID_sequence);
return offset;
}
static int
dissect_m2ap_GTP_TEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_m2ap_IPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 79 "./asn1/m2ap/m2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 16, FALSE, &parameter_tvb);
if (parameter_tvb) {
gint tvb_len = tvb_reported_length(parameter_tvb);
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_m2ap_IPAddress);
switch (tvb_len) {
case 4:
proto_tree_add_item(subtree, hf_m2ap_IPAddress_v4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
break;
case 16:
proto_tree_add_item(subtree, hf_m2ap_IPAddress_v6, parameter_tvb, 0, 16, ENC_NA);
break;
default:
proto_tree_add_expert(subtree, actx->pinfo, &ei_m2ap_invalid_ip_address_len, parameter_tvb, 0, tvb_len);
break;
}
}
return offset;
}
static int
dissect_m2ap_LCID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 28U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Cell_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Cell_List, MBMS_Cell_List_sequence_of,
1, maxnoofCellsforMBMS, FALSE);
return offset;
}
static int
dissect_m2ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_E_RAB_QoS_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_E_RAB_QoS_Parameters, MBMS_E_RAB_QoS_Parameters_sequence);
return offset;
}
static int
dissect_m2ap_MCE_MBMS_M2AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem, MBMS_Service_associatedLogicalM2_ConnectionItem_sequence);
return offset;
}
static int
dissect_m2ap_MBMS_Session_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_m2ap_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_m2ap_TMGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_TMGI, TMGI_sequence);
return offset;
}
static int
dissect_m2ap_MBMSsessionListPerPMCH_Item_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMSsessionListPerPMCH_Item_item, MBMSsessionListPerPMCH_Item_item_sequence);
return offset;
}
static int
dissect_m2ap_MBMSsessionListPerPMCH_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMSsessionListPerPMCH_Item, MBMSsessionListPerPMCH_Item_sequence_of,
1, maxnoofSessionsPerPMCH, FALSE);
return offset;
}
static int
dissect_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item_item, MBMSsessionsToBeSuspendedListPerPMCH_Item_item_sequence);
return offset;
}
static int
dissect_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item, MBMSsessionsToBeSuspendedListPerPMCH_Item_sequence_of,
1, maxnoofSessionsPerPMCH, FALSE);
return offset;
}
static int
dissect_m2ap_MBSFN_Area_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_T_radioframeAllocationPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_BIT_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL, NULL);
return offset;
}
static int
dissect_m2ap_BIT_STRING_SIZE_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_m2ap_T_subframeAllocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_T_subframeAllocation, T_subframeAllocation_choice,
NULL);
return offset;
}
static int
dissect_m2ap_MBSFN_Subframe_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBSFN_Subframe_Configuration, MBSFN_Subframe_Configuration_sequence);
return offset;
}
static int
dissect_m2ap_MCCH_Update_Time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_T_pdcchLength(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_T_repetitionPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_INTEGER_0_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_T_modificationPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_T_modulationAndCodingScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item, MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_sequence);
return offset;
}
static int
dissect_m2ap_MCEname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
return offset;
}
static int
dissect_m2ap_MCH_Scheduling_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_MCH_Scheduling_PeriodExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_Modulation_Coding_Scheme2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 27U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_INTEGER_0_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 28U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_PMCH_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_PMCH_Configuration, PMCH_Configuration_sequence);
return offset;
}
static int
dissect_m2ap_Common_Subframe_Allocation_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m2ap_SC_PTM_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SC_PTM_Information, SC_PTM_Information_sequence);
return offset;
}
static int
dissect_m2ap_SFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_TNL_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_TNL_Information, TNL_Information_sequence);
return offset;
}
static int
dissect_m2ap_SessionStartRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 103 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Start Request");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionStartRequest, SessionStartRequest_sequence);
return offset;
}
static int
dissect_m2ap_SessionStartResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 105 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Start Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionStartResponse, SessionStartResponse_sequence);
return offset;
}
static int
dissect_m2ap_SessionStartFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 107 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Start Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionStartFailure, SessionStartFailure_sequence);
return offset;
}
static int
dissect_m2ap_SessionStopRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 109 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Stop Request");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionStopRequest, SessionStopRequest_sequence);
return offset;
}
static int
dissect_m2ap_SessionStopResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 111 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Stop Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionStopResponse, SessionStopResponse_sequence);
return offset;
}
static int
dissect_m2ap_SessionUpdateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 113 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Update Request");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionUpdateRequest, SessionUpdateRequest_sequence);
return offset;
}
static int
dissect_m2ap_SessionUpdateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 115 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Update Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionUpdateResponse, SessionUpdateResponse_sequence);
return offset;
}
static int
dissect_m2ap_SessionUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 117 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Session Update Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SessionUpdateFailure, SessionUpdateFailure_sequence);
return offset;
}
static int
dissect_m2ap_MbmsSchedulingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 119 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Scheduling Information");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsSchedulingInformation, MbmsSchedulingInformation_sequence);
return offset;
}
static int
dissect_m2ap_MBSFN_Area_Configuration_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBSFN_Area_Configuration_List, MBSFN_Area_Configuration_List_sequence_of,
1, maxnoofMBSFNareas, FALSE);
return offset;
}
static int
dissect_m2ap_PMCH_Configuration_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_PMCH_Configuration_List, PMCH_Configuration_List_sequence_of,
0, maxnoofPMCHsperMBSFNarea, FALSE);
return offset;
}
static int
dissect_m2ap_PMCH_Configuration_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_PMCH_Configuration_Item, PMCH_Configuration_Item_sequence);
return offset;
}
static int
dissect_m2ap_MBSFN_Subframe_ConfigurationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBSFN_Subframe_ConfigurationList, MBSFN_Subframe_ConfigurationList_sequence_of,
1, maxnoofMBSFN_Allocations, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Suspension_Notification_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Suspension_Notification_List, MBMS_Suspension_Notification_List_sequence_of,
1, maxnoofPMCHsperMBSFNarea, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Suspension_Notification_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Suspension_Notification_Item, MBMS_Suspension_Notification_Item_sequence);
return offset;
}
static int
dissect_m2ap_MbmsSchedulingInformationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 121 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Scheduling Information Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsSchedulingInformationResponse, MbmsSchedulingInformationResponse_sequence);
return offset;
}
static int
dissect_m2ap_M2SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "M2 Setup Request");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_M2SetupRequest, M2SetupRequest_sequence);
return offset;
}
static int
dissect_m2ap_ENB_MBMS_Configuration_data_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENB_MBMS_Configuration_data_List, ENB_MBMS_Configuration_data_List_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_m2ap_M2SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 125 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "M2 Setup Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_M2SetupResponse, M2SetupResponse_sequence);
return offset;
}
static int
dissect_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea, MCCHrelatedBCCH_ConfigPerMBSFNArea_sequence_of,
1, maxnoofMBSFNareas, FALSE);
return offset;
}
static int
dissect_m2ap_M2SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 127 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "M2 Setup Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_M2SetupFailure, M2SetupFailure_sequence);
return offset;
}
static int
dissect_m2ap_ENBConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 129 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "eNB Configuration Update");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);
return offset;
}
static int
dissect_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate, ENB_MBMS_Configuration_data_List_ConfigUpdate_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_m2ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "eNB Configuration Update Acknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_m2ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 133 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "eNB Configuration Update Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_m2ap_MCEConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 135 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MCE Configuration Update");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MCEConfigurationUpdate, MCEConfigurationUpdate_sequence);
return offset;
}
static int
dissect_m2ap_MCEConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 137 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MCE Configuration Update Acknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MCEConfigurationUpdateAcknowledge, MCEConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_m2ap_MCEConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 139 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MCE Configuration Update Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MCEConfigurationUpdateFailure, MCEConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_m2ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 141 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "Error Indication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_m2ap_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 143 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "Reset");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_Reset, Reset_sequence);
return offset;
}
static int
dissect_m2ap_ResetAll(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListRes, MBMS_Service_associatedLogicalM2_ConnectionListRes_sequence_of,
1, maxNrOfIndividualM2ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_m2ap_ResetType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_ResetType, ResetType_choice,
NULL);
return offset;
}
static int
dissect_m2ap_ResetAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 145 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "Reset Acknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_ResetAcknowledge, ResetAcknowledge_sequence);
return offset;
}
static int
dissect_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck, MBMS_Service_associatedLogicalM2_ConnectionListResAck_sequence_of,
1, maxNrOfIndividualM2ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_m2ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 147 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "Private Message");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_m2ap_MbmsServiceCountingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 149 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Service Counting Request");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsServiceCountingRequest, MbmsServiceCountingRequest_sequence);
return offset;
}
static int
dissect_m2ap_MBMS_Counting_Request_Session(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Counting_Request_Session, MBMS_Counting_Request_Session_sequence_of,
1, maxnoofCountingService, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Counting_Request_SessionIE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Counting_Request_SessionIE, MBMS_Counting_Request_SessionIE_sequence);
return offset;
}
static int
dissect_m2ap_MbmsServiceCountingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 151 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Service Counting Response");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsServiceCountingResponse, MbmsServiceCountingResponse_sequence);
return offset;
}
static int
dissect_m2ap_MbmsServiceCountingFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 153 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Service Counting Failure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsServiceCountingFailure, MbmsServiceCountingFailure_sequence);
return offset;
}
static int
dissect_m2ap_MbmsServiceCountingResultsReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 155 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Service Counting Results Report");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsServiceCountingResultsReport, MbmsServiceCountingResultsReport_sequence);
return offset;
}
static int
dissect_m2ap_MBMS_Counting_Result_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Counting_Result_List, MBMS_Counting_Result_List_sequence_of,
1, maxnoofCountingService, FALSE);
return offset;
}
static int
dissect_m2ap_CountingResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_m2ap_MBMS_Counting_Result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MBMS_Counting_Result, MBMS_Counting_Result_sequence);
return offset;
}
static int
dissect_m2ap_MbmsOverloadNotification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 157 "./asn1/m2ap/m2ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO, "MBMS Overload Notification");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_MbmsOverloadNotification, MbmsOverloadNotification_sequence);
return offset;
}
static int
dissect_m2ap_Overload_Status_Per_PMCH_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_Overload_Status_Per_PMCH_List, Overload_Status_Per_PMCH_List_sequence_of,
1, maxnoofPMCHsperMBSFNarea, FALSE);
return offset;
}
static int
dissect_m2ap_PMCH_Overload_Status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m2ap_Active_MBMS_Session_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m2ap_Active_MBMS_Session_List, Active_MBMS_Session_List_sequence_of,
1, maxnoofSessionsPerPMCH, FALSE);
return offset;
}
static int
dissect_m2ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 59 "./asn1/m2ap/m2ap.cnf"
message_type = INITIATING_MESSAGE;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_m2ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_m2ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 63 "./asn1/m2ap/m2ap.cnf"
message_type = SUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_m2ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_m2ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 67 "./asn1/m2ap/m2ap.cnf"
message_type = UNSUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_m2ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m2ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_m2ap_M2AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m2ap_M2AP_PDU, M2AP_PDU_choice,
NULL);
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Cause(tvb, offset, &asn1_ctx, tree, hf_m2ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_m2ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_MBMS_Configuration_data_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENB_MBMS_Configuration_data_Item(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENB_MBMS_Configuration_data_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_MBMS_Configuration_data_ConfigUpdate_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_MBMS_M2AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENB_MBMS_M2AP_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENB_MBMS_M2AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENBname(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENBname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalENB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_GlobalENB_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_GlobalENB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalMCE_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_GlobalMCE_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_GlobalMCE_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_associatedLogicalM2_ConnectionItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_Area_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Service_Area(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Service_Area_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Session_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Session_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Session_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Area_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBSFN_Area_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBSFN_Area_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Subframe_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBSFN_Subframe_Configuration(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBSFN_Subframe_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCCH_Update_Time_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCCH_Update_Time(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCCH_Update_Time_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCE_MBMS_M2AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCE_MBMS_M2AP_ID(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCE_MBMS_M2AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCEname(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCEname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCH_Scheduling_PeriodExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCH_Scheduling_PeriodExtended(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCH_Scheduling_PeriodExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Modulation_Coding_Scheme2_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Modulation_Coding_Scheme2(tvb, offset, &asn1_ctx, tree, hf_m2ap_Modulation_Coding_Scheme2_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Common_Subframe_Allocation_Period_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Common_Subframe_Allocation_Period(tvb, offset, &asn1_ctx, tree, hf_m2ap_Common_Subframe_Allocation_Period_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SC_PTM_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SC_PTM_Information(tvb, offset, &asn1_ctx, tree, hf_m2ap_SC_PTM_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_m2ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TMGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_TMGI(tvb, offset, &asn1_ctx, tree, hf_m2ap_TMGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TNL_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_TNL_Information(tvb, offset, &asn1_ctx, tree, hf_m2ap_TNL_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionStartRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionStartRequest(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionStartRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionStartResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionStartResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionStartResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionStartFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionStartFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionStartFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionStopRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionStopRequest(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionStopRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionStopResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionStopResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionStopResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionUpdateRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionUpdateRequest(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionUpdateRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionUpdateResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionUpdateResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionUpdateResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_SessionUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_SessionUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsSchedulingInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsSchedulingInformation(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsSchedulingInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Area_Configuration_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBSFN_Area_Configuration_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBSFN_Area_Configuration_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PMCH_Configuration_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_PMCH_Configuration_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_PMCH_Configuration_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PMCH_Configuration_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_PMCH_Configuration_Item(tvb, offset, &asn1_ctx, tree, hf_m2ap_PMCH_Configuration_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Subframe_ConfigurationList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBSFN_Subframe_ConfigurationList(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBSFN_Subframe_ConfigurationList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Suspension_Notification_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Suspension_Notification_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Suspension_Notification_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Suspension_Notification_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Suspension_Notification_Item(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Suspension_Notification_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsSchedulingInformationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsSchedulingInformationResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsSchedulingInformationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M2SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_M2SetupRequest(tvb, offset, &asn1_ctx, tree, hf_m2ap_M2SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_MBMS_Configuration_data_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENB_MBMS_Configuration_data_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENB_MBMS_Configuration_data_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M2SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_M2SetupResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_M2SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCCHrelatedBCCH_ConfigPerMBSFNArea_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M2SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_M2SetupFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_M2SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENBConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_MBMS_Configuration_data_List_ConfigUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENBConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_ENBConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCEConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCEConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCEConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCEConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MCEConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_MCEConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_m2ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Reset(tvb, offset, &asn1_ctx, tree, hf_m2ap_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ResetType(tvb, offset, &asn1_ctx, tree, hf_m2ap_ResetType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_m2ap_ResetAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_associatedLogicalM2_ConnectionListResAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_m2ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsServiceCountingRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsServiceCountingRequest(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsServiceCountingRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Counting_Request_Session_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Counting_Request_Session(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Counting_Request_Session_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Counting_Request_SessionIE_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Counting_Request_SessionIE(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Counting_Request_SessionIE_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsServiceCountingResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsServiceCountingResponse(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsServiceCountingResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsServiceCountingFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsServiceCountingFailure(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsServiceCountingFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsServiceCountingResultsReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsServiceCountingResultsReport(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsServiceCountingResultsReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Counting_Result_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Counting_Result_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Counting_Result_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Counting_Result_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MBMS_Counting_Result(tvb, offset, &asn1_ctx, tree, hf_m2ap_MBMS_Counting_Result_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MbmsOverloadNotification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_MbmsOverloadNotification(tvb, offset, &asn1_ctx, tree, hf_m2ap_MbmsOverloadNotification_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Overload_Status_Per_PMCH_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Overload_Status_Per_PMCH_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_Overload_Status_Per_PMCH_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PMCH_Overload_Status_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_PMCH_Overload_Status(tvb, offset, &asn1_ctx, tree, hf_m2ap_PMCH_Overload_Status_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Active_MBMS_Session_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_Active_MBMS_Session_List(tvb, offset, &asn1_ctx, tree, hf_m2ap_Active_MBMS_Session_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M2AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m2ap_M2AP_PDU(tvb, offset, &asn1_ctx, tree, hf_m2ap_M2AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_m2ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *m2ap_item = NULL;
proto_tree *m2ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear_fence(pinfo->cinfo, COL_INFO);
col_clear(pinfo->cinfo, COL_INFO);
m2ap_item = proto_tree_add_item(tree, proto_m2ap, tvb, 0, -1, ENC_NA);
m2ap_tree = proto_item_add_subtree(m2ap_item, ett_m2ap);
dissect_M2AP_PDU_PDU(tvb, pinfo, m2ap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_register_m2ap(void) {
static hf_register_info hf[] = {
{ &hf_m2ap_IPAddress_v4,
{ "IPAddress", "m2ap.IPAddress_v4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_m2ap_IPAddress_v6,
{ "IPAddress", "m2ap.IPAddress_v6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#line 1 "./asn1/m2ap/packet-m2ap-hfarr.c"
{ &hf_m2ap_Cause_PDU,
{ "Cause", "m2ap.Cause",
FT_UINT32, BASE_DEC, VALS(m2ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "m2ap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_Item_PDU,
{ "ENB-MBMS-Configuration-data-Item", "m2ap.ENB_MBMS_Configuration_data_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item_PDU,
{ "ENB-MBMS-Configuration-data-ConfigUpdate-Item", "m2ap.ENB_MBMS_Configuration_data_ConfigUpdate_Item",
FT_UINT32, BASE_DEC, VALS(m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_M2AP_ID_PDU,
{ "ENB-MBMS-M2AP-ID", "m2ap.ENB_MBMS_M2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENBname_PDU,
{ "ENBname", "m2ap.ENBname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_GlobalENB_ID_PDU,
{ "GlobalENB-ID", "m2ap.GlobalENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_GlobalMCE_ID_PDU,
{ "GlobalMCE-ID", "m2ap.GlobalMCE_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem_PDU,
{ "MBMS-Service-associatedLogicalM2-ConnectionItem", "m2ap.MBMS_Service_associatedLogicalM2_ConnectionItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Service_Area_PDU,
{ "MBMS-Service-Area", "m2ap.MBMS_Service_Area",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Session_ID_PDU,
{ "MBMS-Session-ID", "m2ap.MBMS_Session_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBSFN_Area_ID_PDU,
{ "MBSFN-Area-ID", "m2ap.MBSFN_Area_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBSFN_Subframe_Configuration_PDU,
{ "MBSFN-Subframe-Configuration", "m2ap.MBSFN_Subframe_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCCH_Update_Time_PDU,
{ "MCCH-Update-Time", "m2ap.MCCH_Update_Time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_PDU,
{ "MCCHrelatedBCCH-ConfigPerMBSFNArea-Item", "m2ap.MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCE_MBMS_M2AP_ID_PDU,
{ "MCE-MBMS-M2AP-ID", "m2ap.MCE_MBMS_M2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCEname_PDU,
{ "MCEname", "m2ap.MCEname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCH_Scheduling_PeriodExtended_PDU,
{ "MCH-Scheduling-PeriodExtended", "m2ap.MCH_Scheduling_PeriodExtended",
FT_UINT32, BASE_DEC, VALS(m2ap_MCH_Scheduling_PeriodExtended_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_Modulation_Coding_Scheme2_PDU,
{ "Modulation-Coding-Scheme2", "m2ap.Modulation_Coding_Scheme2",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_Common_Subframe_Allocation_Period_PDU,
{ "Common-Subframe-Allocation-Period", "m2ap.Common_Subframe_Allocation_Period",
FT_UINT32, BASE_DEC, VALS(m2ap_Common_Subframe_Allocation_Period_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_SC_PTM_Information_PDU,
{ "SC-PTM-Information", "m2ap.SC_PTM_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_TimeToWait_PDU,
{ "TimeToWait", "m2ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(m2ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_TMGI_PDU,
{ "TMGI", "m2ap.TMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_TNL_Information_PDU,
{ "TNL-Information", "m2ap.TNL_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionStartRequest_PDU,
{ "SessionStartRequest", "m2ap.SessionStartRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionStartResponse_PDU,
{ "SessionStartResponse", "m2ap.SessionStartResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionStartFailure_PDU,
{ "SessionStartFailure", "m2ap.SessionStartFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionStopRequest_PDU,
{ "SessionStopRequest", "m2ap.SessionStopRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionStopResponse_PDU,
{ "SessionStopResponse", "m2ap.SessionStopResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionUpdateRequest_PDU,
{ "SessionUpdateRequest", "m2ap.SessionUpdateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionUpdateResponse_PDU,
{ "SessionUpdateResponse", "m2ap.SessionUpdateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_SessionUpdateFailure_PDU,
{ "SessionUpdateFailure", "m2ap.SessionUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsSchedulingInformation_PDU,
{ "MbmsSchedulingInformation", "m2ap.MbmsSchedulingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBSFN_Area_Configuration_List_PDU,
{ "MBSFN-Area-Configuration-List", "m2ap.MBSFN_Area_Configuration_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PMCH_Configuration_List_PDU,
{ "PMCH-Configuration-List", "m2ap.PMCH_Configuration_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PMCH_Configuration_Item_PDU,
{ "PMCH-Configuration-Item", "m2ap.PMCH_Configuration_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBSFN_Subframe_ConfigurationList_PDU,
{ "MBSFN-Subframe-ConfigurationList", "m2ap.MBSFN_Subframe_ConfigurationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Suspension_Notification_List_PDU,
{ "MBMS-Suspension-Notification-List", "m2ap.MBMS_Suspension_Notification_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Suspension_Notification_Item_PDU,
{ "MBMS-Suspension-Notification-Item", "m2ap.MBMS_Suspension_Notification_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsSchedulingInformationResponse_PDU,
{ "MbmsSchedulingInformationResponse", "m2ap.MbmsSchedulingInformationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_M2SetupRequest_PDU,
{ "M2SetupRequest", "m2ap.M2SetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_List_PDU,
{ "ENB-MBMS-Configuration-data-List", "m2ap.ENB_MBMS_Configuration_data_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_M2SetupResponse_PDU,
{ "M2SetupResponse", "m2ap.M2SetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_PDU,
{ "MCCHrelatedBCCH-ConfigPerMBSFNArea", "m2ap.MCCHrelatedBCCH_ConfigPerMBSFNArea",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_M2SetupFailure_PDU,
{ "M2SetupFailure", "m2ap.M2SetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENBConfigurationUpdate_PDU,
{ "ENBConfigurationUpdate", "m2ap.ENBConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate_PDU,
{ "ENB-MBMS-Configuration-data-List-ConfigUpdate", "m2ap.ENB_MBMS_Configuration_data_List_ConfigUpdate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENBConfigurationUpdateAcknowledge_PDU,
{ "ENBConfigurationUpdateAcknowledge", "m2ap.ENBConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENBConfigurationUpdateFailure_PDU,
{ "ENBConfigurationUpdateFailure", "m2ap.ENBConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCEConfigurationUpdate_PDU,
{ "MCEConfigurationUpdate", "m2ap.MCEConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCEConfigurationUpdateAcknowledge_PDU,
{ "MCEConfigurationUpdateAcknowledge", "m2ap.MCEConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCEConfigurationUpdateFailure_PDU,
{ "MCEConfigurationUpdateFailure", "m2ap.MCEConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ErrorIndication_PDU,
{ "ErrorIndication", "m2ap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_Reset_PDU,
{ "Reset", "m2ap.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ResetType_PDU,
{ "ResetType", "m2ap.ResetType",
FT_UINT32, BASE_DEC, VALS(m2ap_ResetType_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_ResetAcknowledge_PDU,
{ "ResetAcknowledge", "m2ap.ResetAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck_PDU,
{ "MBMS-Service-associatedLogicalM2-ConnectionListResAck", "m2ap.MBMS_Service_associatedLogicalM2_ConnectionListResAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PrivateMessage_PDU,
{ "PrivateMessage", "m2ap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsServiceCountingRequest_PDU,
{ "MbmsServiceCountingRequest", "m2ap.MbmsServiceCountingRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Counting_Request_Session_PDU,
{ "MBMS-Counting-Request-Session", "m2ap.MBMS_Counting_Request_Session",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Counting_Request_SessionIE_PDU,
{ "MBMS-Counting-Request-SessionIE", "m2ap.MBMS_Counting_Request_SessionIE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsServiceCountingResponse_PDU,
{ "MbmsServiceCountingResponse", "m2ap.MbmsServiceCountingResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsServiceCountingFailure_PDU,
{ "MbmsServiceCountingFailure", "m2ap.MbmsServiceCountingFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsServiceCountingResultsReport_PDU,
{ "MbmsServiceCountingResultsReport", "m2ap.MbmsServiceCountingResultsReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Counting_Result_List_PDU,
{ "MBMS-Counting-Result-List", "m2ap.MBMS_Counting_Result_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Counting_Result_PDU,
{ "MBMS-Counting-Result", "m2ap.MBMS_Counting_Result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MbmsOverloadNotification_PDU,
{ "MbmsOverloadNotification", "m2ap.MbmsOverloadNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_Overload_Status_Per_PMCH_List_PDU,
{ "Overload-Status-Per-PMCH-List", "m2ap.Overload_Status_Per_PMCH_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PMCH_Overload_Status_PDU,
{ "PMCH-Overload-Status", "m2ap.PMCH_Overload_Status",
FT_UINT32, BASE_DEC, VALS(m2ap_PMCH_Overload_Status_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_Active_MBMS_Session_List_PDU,
{ "Active-MBMS-Session-List", "m2ap.Active_MBMS_Session_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_M2AP_PDU_PDU,
{ "M2AP-PDU", "m2ap.M2AP_PDU",
FT_UINT32, BASE_DEC, VALS(m2ap_M2AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_local,
{ "local", "m2ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxPrivateIEs", HFILL }},
{ &hf_m2ap_global,
{ "global", "m2ap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_m2ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "m2ap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_id,
{ "id", "m2ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m2ap_criticality,
{ "criticality", "m2ap.criticality",
FT_UINT32, BASE_DEC, VALS(m2ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_ie_field_value,
{ "value", "m2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_m2ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "m2ap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ext_id,
{ "id", "m2ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m2ap_extensionValue,
{ "extensionValue", "m2ap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "m2ap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_private_id,
{ "id", "m2ap.id",
FT_UINT32, BASE_DEC, VALS(m2ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_m2ap_private_value,
{ "value", "m2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_private_value", HFILL }},
{ &hf_m2ap_priorityLevel,
{ "priorityLevel", "m2ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(m2ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_pre_emptionCapability,
{ "pre-emptionCapability", "m2ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(m2ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "m2ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(m2ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_iE_Extensions,
{ "iE-Extensions", "m2ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_m2ap_radioNetwork,
{ "radioNetwork", "m2ap.radioNetwork",
FT_UINT32, BASE_DEC, VALS(m2ap_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_m2ap_transport,
{ "transport", "m2ap.transport",
FT_UINT32, BASE_DEC, VALS(m2ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_m2ap_nAS,
{ "nAS", "m2ap.nAS",
FT_UINT32, BASE_DEC, VALS(m2ap_CauseNAS_vals), 0,
"CauseNAS", HFILL }},
{ &hf_m2ap_protocol,
{ "protocol", "m2ap.protocol",
FT_UINT32, BASE_DEC, VALS(m2ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_m2ap_misc,
{ "misc", "m2ap.misc",
FT_UINT32, BASE_DEC, VALS(m2ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_m2ap_eCGI,
{ "eCGI", "m2ap.eCGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_cellReservationInfo,
{ "cellReservationInfo", "m2ap.cellReservationInfo",
FT_UINT32, BASE_DEC, VALS(m2ap_T_cellReservationInfo_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_Cell_Information_List_item,
{ "Cell-Information", "m2ap.Cell_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_procedureCode,
{ "procedureCode", "m2ap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m2ap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_m2ap_triggeringMessage,
{ "triggeringMessage", "m2ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(m2ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_procedureCriticality,
{ "procedureCriticality", "m2ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(m2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_m2ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "m2ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_m2ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "m2ap.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_iECriticality,
{ "iECriticality", "m2ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(m2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_m2ap_iE_ID,
{ "iE-ID", "m2ap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m2ap_typeOfError,
{ "typeOfError", "m2ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(m2ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_pLMN_Identity,
{ "pLMN-Identity", "m2ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_eUTRANcellIdentifier,
{ "eUTRANcellIdentifier", "m2ap.eUTRANcellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_macro_eNB_ID,
{ "macro-eNB-ID", "m2ap.macro_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_m2ap_mbsfnSynchronisationArea,
{ "mbsfnSynchronisationArea", "m2ap.mbsfnSynchronisationArea",
FT_UINT32, BASE_DEC, NULL, 0,
"MBSFN_SynchronisationArea_ID", HFILL }},
{ &hf_m2ap_mbmsServiceAreaList,
{ "mbmsServiceAreaList", "m2ap.mbmsServiceAreaList",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMS_Service_Area_ID_List", HFILL }},
{ &hf_m2ap_mBMSConfigData,
{ "mBMSConfigData", "m2ap.mBMSConfigData_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENB_MBMS_Configuration_data_Item", HFILL }},
{ &hf_m2ap_mBMS_E_RAB_MaximumBitrateDL,
{ "mBMS-E-RAB-MaximumBitrateDL", "m2ap.mBMS_E_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_m2ap_mBMS_E_RAB_GuaranteedBitrateDL,
{ "mBMS-E-RAB-GuaranteedBitrateDL", "m2ap.mBMS_E_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_m2ap_eNB_ID,
{ "eNB-ID", "m2ap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(m2ap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_mCE_ID,
{ "mCE-ID", "m2ap.mCE_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Cell_List_item,
{ "ECGI", "m2ap.ECGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_qCI,
{ "qCI", "m2ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_gbrQosInformation,
{ "gbrQosInformation", "m2ap.gbrQosInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_m2ap_allocationAndRetentionPriority,
{ "allocationAndRetentionPriority", "m2ap.allocationAndRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_eNB_MBMS_M2AP_ID,
{ "eNB-MBMS-M2AP-ID", "m2ap.eNB_MBMS_M2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_mCE_MBMS_M2AP_ID,
{ "mCE-MBMS-M2AP-ID", "m2ap.mCE_MBMS_M2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Service_Area_ID_List_item,
{ "MBMS-Service-Area", "m2ap.MBMS_Service_Area",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMSsessionListPerPMCH_Item_item,
{ "MBMSsessionListPerPMCH-Item item", "m2ap.MBMSsessionListPerPMCH_Item_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_tmgi,
{ "tmgi", "m2ap.tmgi_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_lcid,
{ "lcid", "m2ap.lcid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item_item,
{ "MBMSsessionsToBeSuspendedListPerPMCH-Item item", "m2ap.MBMSsessionsToBeSuspendedListPerPMCH_Item_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_radioframeAllocationPeriod,
{ "radioframeAllocationPeriod", "m2ap.radioframeAllocationPeriod",
FT_UINT32, BASE_DEC, VALS(m2ap_T_radioframeAllocationPeriod_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_radioframeAllocationOffset,
{ "radioframeAllocationOffset", "m2ap.radioframeAllocationOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_m2ap_subframeAllocation,
{ "subframeAllocation", "m2ap.subframeAllocation",
FT_UINT32, BASE_DEC, VALS(m2ap_T_subframeAllocation_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_oneFrame,
{ "oneFrame", "m2ap.oneFrame",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_m2ap_fourFrames,
{ "fourFrames", "m2ap.fourFrames",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_m2ap_mbsfnArea,
{ "mbsfnArea", "m2ap.mbsfnArea",
FT_UINT32, BASE_DEC, NULL, 0,
"MBSFN_Area_ID", HFILL }},
{ &hf_m2ap_pdcchLength,
{ "pdcchLength", "m2ap.pdcchLength",
FT_UINT32, BASE_DEC, VALS(m2ap_T_pdcchLength_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_repetitionPeriod,
{ "repetitionPeriod", "m2ap.repetitionPeriod",
FT_UINT32, BASE_DEC, VALS(m2ap_T_repetitionPeriod_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_offset,
{ "offset", "m2ap.offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10", HFILL }},
{ &hf_m2ap_modificationPeriod,
{ "modificationPeriod", "m2ap.modificationPeriod",
FT_UINT32, BASE_DEC, VALS(m2ap_T_modificationPeriod_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_subframeAllocationInfo,
{ "subframeAllocationInfo", "m2ap.subframeAllocationInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6", HFILL }},
{ &hf_m2ap_modulationAndCodingScheme,
{ "modulationAndCodingScheme", "m2ap.modulationAndCodingScheme",
FT_UINT32, BASE_DEC, VALS(m2ap_T_modulationAndCodingScheme_vals), 0,
NULL, HFILL }},
{ &hf_m2ap_cellInformationList,
{ "cellInformationList", "m2ap.cellInformationList",
FT_UINT32, BASE_DEC, NULL, 0,
"Cell_Information_List", HFILL }},
{ &hf_m2ap_allocatedSubframesEnd,
{ "allocatedSubframesEnd", "m2ap.allocatedSubframesEnd",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_dataMCS,
{ "dataMCS", "m2ap.dataMCS",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_28", HFILL }},
{ &hf_m2ap_mchSchedulingPeriod,
{ "mchSchedulingPeriod", "m2ap.mchSchedulingPeriod",
FT_UINT32, BASE_DEC, VALS(m2ap_MCH_Scheduling_Period_vals), 0,
"MCH_Scheduling_Period", HFILL }},
{ &hf_m2ap_mbmsCellList,
{ "mbmsCellList", "m2ap.mbmsCellList",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMS_Cell_List", HFILL }},
{ &hf_m2ap_mbms_E_RAB_QoS_Parameters,
{ "mbms-E-RAB-QoS-Parameters", "m2ap.mbms_E_RAB_QoS_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_pLMNidentity,
{ "pLMNidentity", "m2ap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Identity", HFILL }},
{ &hf_m2ap_serviceID,
{ "serviceID", "m2ap.serviceID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_m2ap_iPMCAddress,
{ "iPMCAddress", "m2ap.iPMCAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_m2ap_iPSourceAddress,
{ "iPSourceAddress", "m2ap.iPSourceAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_m2ap_gTP_TEID,
{ "gTP-TEID", "m2ap.gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_protocolIEs,
{ "protocolIEs", "m2ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_m2ap_MBSFN_Area_Configuration_List_item,
{ "ProtocolIE-Container", "m2ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_PMCH_Configuration_List_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_pmch_Configuration,
{ "pmch-Configuration", "m2ap.pmch_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_mbms_Session_List,
{ "mbms-Session-List", "m2ap.mbms_Session_List",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMSsessionListPerPMCH_Item", HFILL }},
{ &hf_m2ap_MBSFN_Subframe_ConfigurationList_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Suspension_Notification_List_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_sfn,
{ "sfn", "m2ap.sfn",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_mbms_Sessions_To_Be_Suspended_List,
{ "mbms-Sessions-To-Be-Suspended-List", "m2ap.mbms_Sessions_To_Be_Suspended_List",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMSsessionsToBeSuspendedListPerPMCH_Item", HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_List_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_m2_Interface,
{ "m2-Interface", "m2ap.m2_Interface",
FT_UINT32, BASE_DEC, VALS(m2ap_ResetAll_vals), 0,
"ResetAll", HFILL }},
{ &hf_m2ap_partOfM2_Interface,
{ "partOfM2-Interface", "m2ap.partOfM2_Interface",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMS_Service_associatedLogicalM2_ConnectionListRes", HFILL }},
{ &hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListRes_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck_item,
{ "ProtocolIE-Single-Container", "m2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_privateIEs,
{ "privateIEs", "m2ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_m2ap_MBMS_Counting_Request_Session_item,
{ "ProtocolIE-Container", "m2ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_MBMS_Counting_Result_List_item,
{ "ProtocolIE-Container", "m2ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_countingResult,
{ "countingResult", "m2ap.countingResult",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_Overload_Status_Per_PMCH_List_item,
{ "ProtocolIE-Container", "m2ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_Active_MBMS_Session_List_item,
{ "ProtocolIE-Container", "m2ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_initiatingMessage,
{ "initiatingMessage", "m2ap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_successfulOutcome,
{ "successfulOutcome", "m2ap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "m2ap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m2ap_initiatingMessage_value,
{ "value", "m2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_m2ap_successfulOutcome_value,
{ "value", "m2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_m2ap_unsuccessfulOutcome_value,
{ "value", "m2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 156 "./asn1/m2ap/packet-m2ap-template.c"
};
static gint *ett[] = {
&ett_m2ap,
&ett_m2ap_PLMN_Identity,
&ett_m2ap_IPAddress,
#line 1 "./asn1/m2ap/packet-m2ap-ettarr.c"
&ett_m2ap_PrivateIE_ID,
&ett_m2ap_ProtocolIE_Container,
&ett_m2ap_ProtocolIE_Field,
&ett_m2ap_ProtocolExtensionContainer,
&ett_m2ap_ProtocolExtensionField,
&ett_m2ap_PrivateIE_Container,
&ett_m2ap_PrivateIE_Field,
&ett_m2ap_AllocationAndRetentionPriority,
&ett_m2ap_Cause,
&ett_m2ap_Cell_Information,
&ett_m2ap_Cell_Information_List,
&ett_m2ap_CriticalityDiagnostics,
&ett_m2ap_CriticalityDiagnostics_IE_List,
&ett_m2ap_CriticalityDiagnostics_IE_List_item,
&ett_m2ap_ECGI,
&ett_m2ap_ENB_ID,
&ett_m2ap_ENB_MBMS_Configuration_data_Item,
&ett_m2ap_ENB_MBMS_Configuration_data_ConfigUpdate_Item,
&ett_m2ap_GBR_QosInformation,
&ett_m2ap_GlobalENB_ID,
&ett_m2ap_GlobalMCE_ID,
&ett_m2ap_MBMS_Cell_List,
&ett_m2ap_MBMS_E_RAB_QoS_Parameters,
&ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionItem,
&ett_m2ap_MBMS_Service_Area_ID_List,
&ett_m2ap_MBMSsessionListPerPMCH_Item,
&ett_m2ap_MBMSsessionListPerPMCH_Item_item,
&ett_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item,
&ett_m2ap_MBMSsessionsToBeSuspendedListPerPMCH_Item_item,
&ett_m2ap_MBSFN_Subframe_Configuration,
&ett_m2ap_T_subframeAllocation,
&ett_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item,
&ett_m2ap_PMCH_Configuration,
&ett_m2ap_SC_PTM_Information,
&ett_m2ap_TMGI,
&ett_m2ap_TNL_Information,
&ett_m2ap_SessionStartRequest,
&ett_m2ap_SessionStartResponse,
&ett_m2ap_SessionStartFailure,
&ett_m2ap_SessionStopRequest,
&ett_m2ap_SessionStopResponse,
&ett_m2ap_SessionUpdateRequest,
&ett_m2ap_SessionUpdateResponse,
&ett_m2ap_SessionUpdateFailure,
&ett_m2ap_MbmsSchedulingInformation,
&ett_m2ap_MBSFN_Area_Configuration_List,
&ett_m2ap_PMCH_Configuration_List,
&ett_m2ap_PMCH_Configuration_Item,
&ett_m2ap_MBSFN_Subframe_ConfigurationList,
&ett_m2ap_MBMS_Suspension_Notification_List,
&ett_m2ap_MBMS_Suspension_Notification_Item,
&ett_m2ap_MbmsSchedulingInformationResponse,
&ett_m2ap_M2SetupRequest,
&ett_m2ap_ENB_MBMS_Configuration_data_List,
&ett_m2ap_M2SetupResponse,
&ett_m2ap_MCCHrelatedBCCH_ConfigPerMBSFNArea,
&ett_m2ap_M2SetupFailure,
&ett_m2ap_ENBConfigurationUpdate,
&ett_m2ap_ENB_MBMS_Configuration_data_List_ConfigUpdate,
&ett_m2ap_ENBConfigurationUpdateAcknowledge,
&ett_m2ap_ENBConfigurationUpdateFailure,
&ett_m2ap_MCEConfigurationUpdate,
&ett_m2ap_MCEConfigurationUpdateAcknowledge,
&ett_m2ap_MCEConfigurationUpdateFailure,
&ett_m2ap_ErrorIndication,
&ett_m2ap_Reset,
&ett_m2ap_ResetType,
&ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListRes,
&ett_m2ap_ResetAcknowledge,
&ett_m2ap_MBMS_Service_associatedLogicalM2_ConnectionListResAck,
&ett_m2ap_PrivateMessage,
&ett_m2ap_MbmsServiceCountingRequest,
&ett_m2ap_MBMS_Counting_Request_Session,
&ett_m2ap_MBMS_Counting_Request_SessionIE,
&ett_m2ap_MbmsServiceCountingResponse,
&ett_m2ap_MbmsServiceCountingFailure,
&ett_m2ap_MbmsServiceCountingResultsReport,
&ett_m2ap_MBMS_Counting_Result_List,
&ett_m2ap_MBMS_Counting_Result,
&ett_m2ap_MbmsOverloadNotification,
&ett_m2ap_Overload_Status_Per_PMCH_List,
&ett_m2ap_Active_MBMS_Session_List,
&ett_m2ap_M2AP_PDU,
&ett_m2ap_InitiatingMessage,
&ett_m2ap_SuccessfulOutcome,
&ett_m2ap_UnsuccessfulOutcome,
#line 164 "./asn1/m2ap/packet-m2ap-template.c"
};
expert_module_t* expert_m2ap;
static ei_register_info ei[] = {
{ &ei_m2ap_invalid_ip_address_len, { "m2ap.invalid_ip_address_len", PI_MALFORMED, PI_ERROR, "Invalid IP address length", EXPFILL }}
};
proto_m2ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_m2ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_m2ap = expert_register_protocol(proto_m2ap);
expert_register_field_array(expert_m2ap, ei, array_length(ei));
m2ap_handle = register_dissector(PFNAME, dissect_m2ap, proto_m2ap);
m2ap_ies_dissector_table = register_dissector_table("m2ap.ies", "M2AP-PROTOCOL-IES", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_extension_dissector_table = register_dissector_table("m2ap.extension", "M2AP-PROTOCOL-EXTENSION", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_imsg_dissector_table = register_dissector_table("m2ap.proc.imsg", "M2AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_sout_dissector_table = register_dissector_table("m2ap.proc.sout", "M2AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_uout_dissector_table = register_dissector_table("m2ap.proc.uout", "M2AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_m2ap, FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_m2ap(void)
{
dissector_add_uint("sctp.ppi", PROTO_3GPP_M2AP_PROTOCOL_ID, m2ap_handle);
dissector_add_uint("sctp.port", M2AP_PORT, m2ap_handle);
#line 1 "./asn1/m2ap/packet-m2ap-dis-tab.c"
dissector_add_uint("m2ap.ies", id_MCE_MBMS_M2AP_ID, create_dissector_handle(dissect_MCE_MBMS_M2AP_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENB_MBMS_M2AP_ID, create_dissector_handle(dissect_ENB_MBMS_M2AP_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_TMGI, create_dissector_handle(dissect_TMGI_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Session_ID, create_dissector_handle(dissect_MBMS_Session_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Service_Area, create_dissector_handle(dissect_MBMS_Service_Area_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_TNL_Information, create_dissector_handle(dissect_TNL_Information_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBSFN_Area_Configuration_List, create_dissector_handle(dissect_MBSFN_Area_Configuration_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_PMCH_Configuration_List, create_dissector_handle(dissect_PMCH_Configuration_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_PMCH_Configuration_Item, create_dissector_handle(dissect_PMCH_Configuration_Item_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_GlobalENB_ID, create_dissector_handle(dissect_GlobalENB_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENBname, create_dissector_handle(dissect_ENBname_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENB_MBMS_Configuration_data_List, create_dissector_handle(dissect_ENB_MBMS_Configuration_data_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENB_MBMS_Configuration_data_Item, create_dissector_handle(dissect_ENB_MBMS_Configuration_data_Item_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_GlobalMCE_ID, create_dissector_handle(dissect_GlobalMCE_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MCEname, create_dissector_handle(dissect_MCEname_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MCCHrelatedBCCH_ConfigPerMBSFNArea, create_dissector_handle(dissect_MCCHrelatedBCCH_ConfigPerMBSFNArea_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item, create_dissector_handle(dissect_MCCHrelatedBCCH_ConfigPerMBSFNArea_Item_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_TimeToWait, create_dissector_handle(dissect_TimeToWait_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBSFN_Subframe_Configuration_List, create_dissector_handle(dissect_MBSFN_Subframe_ConfigurationList_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBSFN_Subframe_Configuration_Item, create_dissector_handle(dissect_MBSFN_Subframe_Configuration_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_Common_Subframe_Allocation_Period, create_dissector_handle(dissect_Common_Subframe_Allocation_Period_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MCCH_Update_Time, create_dissector_handle(dissect_MCCH_Update_Time_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENB_MBMS_Configuration_data_List_ConfigUpdate, create_dissector_handle(dissect_ENB_MBMS_Configuration_data_List_ConfigUpdate_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ENB_MBMS_Configuration_data_ConfigUpdate_Item, create_dissector_handle(dissect_ENB_MBMS_Configuration_data_ConfigUpdate_Item_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Service_associatedLogicalM2_ConnectionItem, create_dissector_handle(dissect_MBMS_Service_associatedLogicalM2_ConnectionItem_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBSFN_Area_ID, create_dissector_handle(dissect_MBSFN_Area_ID_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_ResetType, create_dissector_handle(dissect_ResetType_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Service_associatedLogicalM2_ConnectionListResAck, create_dissector_handle(dissect_MBMS_Service_associatedLogicalM2_ConnectionListResAck_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Counting_Request_Session, create_dissector_handle(dissect_MBMS_Counting_Request_Session_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Counting_Request_Session_Item, create_dissector_handle(dissect_MBMS_Counting_Request_SessionIE_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Counting_Result_List, create_dissector_handle(dissect_MBMS_Counting_Result_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Counting_Result_Item, create_dissector_handle(dissect_MBMS_Counting_Result_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_Alternative_TNL_Information, create_dissector_handle(dissect_TNL_Information_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_Overload_Status_Per_PMCH_List, create_dissector_handle(dissect_Overload_Status_Per_PMCH_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_PMCH_Overload_Status, create_dissector_handle(dissect_PMCH_Overload_Status_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_Active_MBMS_Session_List, create_dissector_handle(dissect_Active_MBMS_Session_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Suspension_Notification_List, create_dissector_handle(dissect_MBMS_Suspension_Notification_List_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_MBMS_Suspension_Notification_Item, create_dissector_handle(dissect_MBMS_Suspension_Notification_Item_PDU, proto_m2ap));
dissector_add_uint("m2ap.ies", id_SC_PTM_Information, create_dissector_handle(dissect_SC_PTM_Information_PDU, proto_m2ap));
dissector_add_uint("m2ap.extension", id_Modulation_Coding_Scheme2, create_dissector_handle(dissect_Modulation_Coding_Scheme2_PDU, proto_m2ap));
dissector_add_uint("m2ap.extension", id_MCH_Scheduling_PeriodExtended, create_dissector_handle(dissect_MCH_Scheduling_PeriodExtended_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_sessionStart, create_dissector_handle(dissect_SessionStartRequest_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_sessionStart, create_dissector_handle(dissect_SessionStartResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_sessionStart, create_dissector_handle(dissect_SessionStartFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_sessionStop, create_dissector_handle(dissect_SessionStopRequest_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_sessionStop, create_dissector_handle(dissect_SessionStopResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_sessionUpdate, create_dissector_handle(dissect_SessionUpdateRequest_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_sessionUpdate, create_dissector_handle(dissect_SessionUpdateResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_sessionUpdate, create_dissector_handle(dissect_SessionUpdateFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_mbmsSchedulingInformation, create_dissector_handle(dissect_MbmsSchedulingInformation_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_mbmsSchedulingInformation, create_dissector_handle(dissect_MbmsSchedulingInformationResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_m2Setup, create_dissector_handle(dissect_M2SetupRequest_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_m2Setup, create_dissector_handle(dissect_M2SetupResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_m2Setup, create_dissector_handle(dissect_M2SetupFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdate_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateAcknowledge_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_mCEConfigurationUpdate, create_dissector_handle(dissect_MCEConfigurationUpdate_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_mCEConfigurationUpdate, create_dissector_handle(dissect_MCEConfigurationUpdateAcknowledge_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_mCEConfigurationUpdate, create_dissector_handle(dissect_MCEConfigurationUpdateFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_errorIndication, create_dissector_handle(dissect_ErrorIndication_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_reset, create_dissector_handle(dissect_Reset_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_reset, create_dissector_handle(dissect_ResetAcknowledge_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_privateMessage, create_dissector_handle(dissect_PrivateMessage_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_mbmsServiceCounting, create_dissector_handle(dissect_MbmsServiceCountingRequest_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.sout", id_mbmsServiceCounting, create_dissector_handle(dissect_MbmsServiceCountingResponse_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.uout", id_mbmsServiceCounting, create_dissector_handle(dissect_MbmsServiceCountingFailure_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_mbmsServiceCountingResultsReport, create_dissector_handle(dissect_MbmsServiceCountingResultsReport_PDU, proto_m2ap));
dissector_add_uint("m2ap.proc.imsg", id_mbmsOverloadNotification, create_dissector_handle(dissect_MbmsOverloadNotification_PDU, proto_m2ap));
#line 196 "./asn1/m2ap/packet-m2ap-template.c"
}
