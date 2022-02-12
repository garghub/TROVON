static int
dissect_m3ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m3ap_INTEGER_0_maxPrivateIEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxPrivateIEs, NULL, FALSE);
return offset;
}
static int
dissect_m3ap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_m3ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m3ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_m3ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 66 "../../asn1/m3ap/m3ap.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s",
val_to_str_ext(ProcedureCode, &m3ap_ProcedureCode_vals_ext,
"unknown message"));
return offset;
}
static int
dissect_m3ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 51 "../../asn1/m3ap/m3ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(ProtocolIE_ID, &m3ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_m3ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m3ap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_m3ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_m3ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_m3ap_ProtocolIE_Single_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_m3ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_m3ap_ProtocolIE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 91 "../../asn1/m3ap/m3ap.cnf"
static const asn1_par_def_t ProtocolIE_ContainerList_pars[] = {
{ "lowerBound", ASN1_PAR_INTEGER },
{ "upperBound", ASN1_PAR_INTEGER },
{ NULL, (asn1_par_type)0 }
};
asn1_stack_frame_check(actx, "ProtocolIE-ContainerList", ProtocolIE_ContainerList_pars);
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_ProtocolIE_ContainerList, ProtocolIE_ContainerList_sequence_of,
asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);
return offset;
}
static int
dissect_m3ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_m3ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_m3ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_m3ap_T_private_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_m3ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_m3ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_m3ap_Absolute_Time_ofMBMS_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 146 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
const gchar *time_str;
gint tvb_len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
time_str = tvb_ntp_fmt_ts(parameter_tvb, 0);
proto_tree_add_string(tree, hf_m3ap_Absolute_Time_ofMBMS_Data_value, parameter_tvb, 0, tvb_len, time_str);
return offset;
}
static int
dissect_m3ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_m3ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m3ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_m3ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_m3ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GINT64_CONSTANT(10000000000U), NULL, FALSE);
return offset;
}
static int
dissect_m3ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_CauseNAS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m3ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_m3ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_m3ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxnooferrors, FALSE);
return offset;
}
static int
dissect_m3ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_m3ap_ExtendedMCE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 122 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, FALSE);
return offset;
}
static int
dissect_m3ap_MCE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_Global_MCE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_Global_MCE_ID, Global_MCE_ID_sequence);
return offset;
}
static int
dissect_m3ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_m3ap_GTP_TEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_IPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 133 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
gint tvb_len;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 16, TRUE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
proto_tree_add_item(tree, hf_m3ap_IPAddress, parameter_tvb, 0, tvb_len, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_m3ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_m3ap_MBMS_E_RAB_QoS_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMS_E_RAB_QoS_Parameters, MBMS_E_RAB_QoS_Parameters_sequence);
return offset;
}
static int
dissect_m3ap_MME_MBMS_M3AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_m3ap_MCE_MBMS_M3AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem, MBMS_Service_associatedLogicalM3_ConnectionItem_sequence);
return offset;
}
static int
dissect_m3ap_MBMSServiceArea1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_MBMS_Service_Area(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 162 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
guint16 tvb_len;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
dissect_gtpv2_mbms_service_area(parameter_tvb, actx->pinfo, tree, actx->created_item, tvb_len, 0, 0);
return offset;
}
static int
dissect_m3ap_MBMS_Session_Duration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 176 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
guint16 tvb_len;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
proto_item_append_text(actx->created_item, " ");
dissect_gtpv2_mbms_session_duration(parameter_tvb, actx->pinfo, tree, actx->created_item, tvb_len, 0, 0);
return offset;
}
static int
dissect_m3ap_MBMS_Session_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_MCEname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
return offset;
}
static int
dissect_m3ap_MinimumTimeToMBMSDataTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 192 "../../asn1/m3ap/m3ap.cnf"
tvbuff_t *parameter_tvb=NULL;
guint16 tvb_len;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
tvb_len = tvb_length(parameter_tvb);
dissect_gtpv2_mbms_time_to_data_xfer(parameter_tvb, actx->pinfo, tree, actx->created_item, tvb_len, 0, 0);
return offset;
}
static int
dissect_m3ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_m3ap_TMGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_TMGI, TMGI_sequence);
return offset;
}
static int
dissect_m3ap_TNL_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_TNL_Information, TNL_Information_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionStartRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 206 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Start Request ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionStartRequest, MBMSSessionStartRequest_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionStartResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 208 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Start Response ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionStartResponse, MBMSSessionStartResponse_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionStartFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 210 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Start Failure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionStartFailure, MBMSSessionStartFailure_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionStopRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 212 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Stop Request ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionStopRequest, MBMSSessionStopRequest_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionStopResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 214 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Stop Response ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionStopResponse, MBMSSessionStopResponse_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionUpdateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 216 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Update Request ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionUpdateRequest, MBMSSessionUpdateRequest_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionUpdateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 218 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Update Response ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionUpdateResponse, MBMSSessionUpdateResponse_sequence);
return offset;
}
static int
dissect_m3ap_MBMSSessionUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 220 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMS Session Update Failure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSSessionUpdateFailure, MBMSSessionUpdateFailure_sequence);
return offset;
}
static int
dissect_m3ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 222 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Error Indication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_m3ap_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 224 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Reset ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_Reset, Reset_sequence);
return offset;
}
static int
dissect_m3ap_ResetAll(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListRes, MBMS_Service_associatedLogicalM3_ConnectionListRes_sequence_of,
1, maxNrOfIndividualM3ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_m3ap_ResetType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m3ap_ResetType, ResetType_choice,
NULL);
return offset;
}
static int
dissect_m3ap_ResetAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 226 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Reset Acknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_ResetAcknowledge, ResetAcknowledge_sequence);
return offset;
}
static int
dissect_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck, MBMS_Service_associatedLogicalM3_ConnectionListResAck_sequence_of,
1, maxNrOfIndividualM3ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_m3ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 228 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Private Message ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_m3ap_M3SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 236 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"M3 Setup Request ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_M3SetupRequest, M3SetupRequest_sequence);
return offset;
}
static int
dissect_m3ap_MBMSServiceAreaListItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_m3ap_MBMSServiceAreaListItem, MBMSServiceAreaListItem_sequence_of,
1, maxnoofMBMSServiceAreaIdentitiesPerMCE, FALSE);
return offset;
}
static int
dissect_m3ap_M3SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 238 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"M3 Setup Response ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_M3SetupResponse, M3SetupResponse_sequence);
return offset;
}
static int
dissect_m3ap_M3SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 240 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"M3 Setup Failure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_M3SetupFailure, M3SetupFailure_sequence);
return offset;
}
static int
dissect_m3ap_MCEConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 230 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MCE Configuration Update ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MCEConfigurationUpdate, MCEConfigurationUpdate_sequence);
return offset;
}
static int
dissect_m3ap_MCEConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 232 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MCE Configuration Update Acknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MCEConfigurationUpdateAcknowledge, MCEConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_m3ap_MCEConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 234 "../../asn1/m3ap/m3ap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MCE Configuration Update Failure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_MCEConfigurationUpdateFailure, MCEConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_m3ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 73 "../../asn1/m3ap/m3ap.cnf"
message_type = INITIATING_MESSAGE;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_m3ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_m3ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 76 "../../asn1/m3ap/m3ap.cnf"
message_type = SUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_m3ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_m3ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 79 "../../asn1/m3ap/m3ap.cnf"
message_type = UNSUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_m3ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_m3ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_m3ap_M3AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_m3ap_M3AP_PDU, M3AP_PDU_choice,
NULL);
return offset;
}
static int dissect_Absolute_Time_ofMBMS_Data_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_Absolute_Time_ofMBMS_Data(tvb, offset, &asn1_ctx, tree, hf_m3ap_Absolute_Time_ofMBMS_Data_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AllocationAndRetentionPriority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_AllocationAndRetentionPriority(tvb, offset, &asn1_ctx, tree, hf_m3ap_AllocationAndRetentionPriority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_Cause(tvb, offset, &asn1_ctx, tree, hf_m3ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_m3ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Global_MCE_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_Global_MCE_ID(tvb, offset, &asn1_ctx, tree, hf_m3ap_Global_MCE_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_E_RAB_QoS_Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_E_RAB_QoS_Parameters(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_E_RAB_QoS_Parameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_associatedLogicalM3_ConnectionItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_Area_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_Service_Area(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_Service_Area_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Session_Duration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_Session_Duration(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_Session_Duration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Session_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_Session_ID(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_Session_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCE_MBMS_M3AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MCE_MBMS_M3AP_ID(tvb, offset, &asn1_ctx, tree, hf_m3ap_MCE_MBMS_M3AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MCEname(tvb, offset, &asn1_ctx, tree, hf_m3ap_MCEname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MinimumTimeToMBMSDataTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MinimumTimeToMBMSDataTransfer(tvb, offset, &asn1_ctx, tree, hf_m3ap_MinimumTimeToMBMSDataTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MME_MBMS_M3AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MME_MBMS_M3AP_ID(tvb, offset, &asn1_ctx, tree, hf_m3ap_MME_MBMS_M3AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_m3ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TMGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_TMGI(tvb, offset, &asn1_ctx, tree, hf_m3ap_TMGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TNL_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_TNL_Information(tvb, offset, &asn1_ctx, tree, hf_m3ap_TNL_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStartRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionStartRequest(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionStartRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStartResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionStartResponse(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionStartResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStartFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionStartFailure(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionStartFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStopRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionStopRequest(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionStopRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStopResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionStopResponse(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionStopResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdateRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionUpdateRequest(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionUpdateRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdateResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionUpdateResponse(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionUpdateResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSSessionUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSSessionUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_m3ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_Reset(tvb, offset, &asn1_ctx, tree, hf_m3ap_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_ResetType(tvb, offset, &asn1_ctx, tree, hf_m3ap_ResetType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_m3ap_ResetAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_associatedLogicalM3_ConnectionListResAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_m3ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_M3SetupRequest(tvb, offset, &asn1_ctx, tree, hf_m3ap_M3SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSServiceAreaListItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MBMSServiceAreaListItem(tvb, offset, &asn1_ctx, tree, hf_m3ap_MBMSServiceAreaListItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_M3SetupResponse(tvb, offset, &asn1_ctx, tree, hf_m3ap_M3SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_M3SetupFailure(tvb, offset, &asn1_ctx, tree, hf_m3ap_M3SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MCEConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_m3ap_MCEConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MCEConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_m3ap_MCEConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MCEConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_MCEConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_m3ap_MCEConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_m3ap_M3AP_PDU(tvb, offset, &asn1_ctx, tree, hf_m3ap_M3AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m3ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m3ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m3ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m3ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m3ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_m3ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *m3ap_item = NULL;
proto_tree *m3ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
if (tree) {
m3ap_item = proto_tree_add_item(tree, proto_m3ap, tvb, 0, -1, ENC_NA);
m3ap_tree = proto_item_add_subtree(m3ap_item, ett_m3ap);
dissect_M3AP_PDU_PDU(tvb, pinfo, m3ap_tree, NULL);
}
}
void proto_register_m3ap(void) {
static hf_register_info hf[] = {
{ &hf_m3ap_Absolute_Time_ofMBMS_Data_value,
{ "Absolute-Time-ofMBMS-Data-value", "m3ap.Absolute_Time_ofMBMS_Data_value",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_m3ap_IPAddress,
{ "IPAddress", "m3ap.IPAddress",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#line 1 "../../asn1/m3ap/packet-m3ap-hfarr.c"
{ &hf_m3ap_Absolute_Time_ofMBMS_Data_PDU,
{ "Absolute-Time-ofMBMS-Data", "m3ap.Absolute_Time_ofMBMS_Data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_AllocationAndRetentionPriority_PDU,
{ "AllocationAndRetentionPriority", "m3ap.AllocationAndRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_Cause_PDU,
{ "Cause", "m3ap.Cause",
FT_UINT32, BASE_DEC, VALS(m3ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "m3ap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_Global_MCE_ID_PDU,
{ "Global-MCE-ID", "m3ap.Global_MCE_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_E_RAB_QoS_Parameters_PDU,
{ "MBMS-E-RAB-QoS-Parameters", "m3ap.MBMS_E_RAB_QoS_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem_PDU,
{ "MBMS-Service-associatedLogicalM3-ConnectionItem", "m3ap.MBMS_Service_associatedLogicalM3_ConnectionItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Service_Area_PDU,
{ "MBMS-Service-Area", "m3ap.MBMS_Service_Area",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Session_Duration_PDU,
{ "MBMS-Session-Duration", "m3ap.MBMS_Session_Duration",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Session_ID_PDU,
{ "MBMS-Session-ID", "m3ap.MBMS_Session_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MCE_MBMS_M3AP_ID_PDU,
{ "MCE-MBMS-M3AP-ID", "m3ap.MCE_MBMS_M3AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MCEname_PDU,
{ "MCEname", "m3ap.MCEname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MinimumTimeToMBMSDataTransfer_PDU,
{ "MinimumTimeToMBMSDataTransfer", "m3ap.MinimumTimeToMBMSDataTransfer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MME_MBMS_M3AP_ID_PDU,
{ "MME-MBMS-M3AP-ID", "m3ap.MME_MBMS_M3AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_TimeToWait_PDU,
{ "TimeToWait", "m3ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(m3ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_TMGI_PDU,
{ "TMGI", "m3ap.TMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_TNL_Information_PDU,
{ "TNL-Information", "m3ap.TNL_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionStartRequest_PDU,
{ "MBMSSessionStartRequest", "m3ap.MBMSSessionStartRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionStartResponse_PDU,
{ "MBMSSessionStartResponse", "m3ap.MBMSSessionStartResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionStartFailure_PDU,
{ "MBMSSessionStartFailure", "m3ap.MBMSSessionStartFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionStopRequest_PDU,
{ "MBMSSessionStopRequest", "m3ap.MBMSSessionStopRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionStopResponse_PDU,
{ "MBMSSessionStopResponse", "m3ap.MBMSSessionStopResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionUpdateRequest_PDU,
{ "MBMSSessionUpdateRequest", "m3ap.MBMSSessionUpdateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionUpdateResponse_PDU,
{ "MBMSSessionUpdateResponse", "m3ap.MBMSSessionUpdateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSSessionUpdateFailure_PDU,
{ "MBMSSessionUpdateFailure", "m3ap.MBMSSessionUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_ErrorIndication_PDU,
{ "ErrorIndication", "m3ap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_Reset_PDU,
{ "Reset", "m3ap.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_ResetType_PDU,
{ "ResetType", "m3ap.ResetType",
FT_UINT32, BASE_DEC, VALS(m3ap_ResetType_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_ResetAcknowledge_PDU,
{ "ResetAcknowledge", "m3ap.ResetAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck_PDU,
{ "MBMS-Service-associatedLogicalM3-ConnectionListResAck", "m3ap.MBMS_Service_associatedLogicalM3_ConnectionListResAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_PrivateMessage_PDU,
{ "PrivateMessage", "m3ap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_M3SetupRequest_PDU,
{ "M3SetupRequest", "m3ap.M3SetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMSServiceAreaListItem_PDU,
{ "MBMSServiceAreaListItem", "m3ap.MBMSServiceAreaListItem",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_M3SetupResponse_PDU,
{ "M3SetupResponse", "m3ap.M3SetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_M3SetupFailure_PDU,
{ "M3SetupFailure", "m3ap.M3SetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MCEConfigurationUpdate_PDU,
{ "MCEConfigurationUpdate", "m3ap.MCEConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MCEConfigurationUpdateAcknowledge_PDU,
{ "MCEConfigurationUpdateAcknowledge", "m3ap.MCEConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MCEConfigurationUpdateFailure_PDU,
{ "MCEConfigurationUpdateFailure", "m3ap.MCEConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_M3AP_PDU_PDU,
{ "M3AP-PDU", "m3ap.M3AP_PDU",
FT_UINT32, BASE_DEC, VALS(m3ap_M3AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_local,
{ "local", "m3ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxPrivateIEs", HFILL }},
{ &hf_m3ap_global,
{ "global", "m3ap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_m3ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "m3ap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_id,
{ "id", "m3ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m3ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m3ap_criticality,
{ "criticality", "m3ap.criticality",
FT_UINT32, BASE_DEC, VALS(m3ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_ie_field_value,
{ "value", "m3ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_m3ap_ProtocolIE_ContainerList_item,
{ "ProtocolIE-Container", "m3ap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "m3ap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_ext_id,
{ "id", "m3ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m3ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m3ap_extensionValue,
{ "extensionValue", "m3ap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "m3ap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_private_id,
{ "id", "m3ap.id",
FT_UINT32, BASE_DEC, VALS(m3ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_m3ap_private_value,
{ "value", "m3ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_private_value", HFILL }},
{ &hf_m3ap_priorityLevel,
{ "priorityLevel", "m3ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(m3ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_pre_emptionCapability,
{ "pre-emptionCapability", "m3ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(m3ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "m3ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(m3ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_iE_Extensions,
{ "iE-Extensions", "m3ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_m3ap_radioNetwork,
{ "radioNetwork", "m3ap.radioNetwork",
FT_UINT32, BASE_DEC, VALS(m3ap_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_m3ap_transport,
{ "transport", "m3ap.transport",
FT_UINT32, BASE_DEC, VALS(m3ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_m3ap_nAS,
{ "nAS", "m3ap.nAS",
FT_UINT32, BASE_DEC, VALS(m3ap_CauseNAS_vals), 0,
"CauseNAS", HFILL }},
{ &hf_m3ap_protocol,
{ "protocol", "m3ap.protocol",
FT_UINT32, BASE_DEC, VALS(m3ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_m3ap_misc,
{ "misc", "m3ap.misc",
FT_UINT32, BASE_DEC, VALS(m3ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_m3ap_procedureCode,
{ "procedureCode", "m3ap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m3ap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_m3ap_triggeringMessage,
{ "triggeringMessage", "m3ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(m3ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_procedureCriticality,
{ "procedureCriticality", "m3ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(m3ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_m3ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "m3ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_m3ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "m3ap.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_iECriticality,
{ "iECriticality", "m3ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(m3ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_m3ap_iE_ID,
{ "iE-ID", "m3ap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &m3ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_m3ap_typeOfError,
{ "typeOfError", "m3ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(m3ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_m3ap_pLMN_Identity,
{ "pLMN-Identity", "m3ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_mCE_ID,
{ "mCE-ID", "m3ap.mCE_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_extendedMCE_ID,
{ "extendedMCE-ID", "m3ap.extendedMCE_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_mBMS_E_RAB_MaximumBitrateDL,
{ "mBMS-E-RAB-MaximumBitrateDL", "m3ap.mBMS_E_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_m3ap_mBMS_E_RAB_GuaranteedBitrateDL,
{ "mBMS-E-RAB-GuaranteedBitrateDL", "m3ap.mBMS_E_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC, NULL, 0,
"BitRate", HFILL }},
{ &hf_m3ap_qCI,
{ "qCI", "m3ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_gbrQosInformation,
{ "gbrQosInformation", "m3ap.gbrQosInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_m3ap_mME_MBMS_M3AP_ID,
{ "mME-MBMS-M3AP-ID", "m3ap.mME_MBMS_M3AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_mCE_MBMS_M3AP_ID,
{ "mCE-MBMS-M3AP-ID", "m3ap.mCE_MBMS_M3AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_pLMNidentity,
{ "pLMNidentity", "m3ap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Identity", HFILL }},
{ &hf_m3ap_serviceID,
{ "serviceID", "m3ap.serviceID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_m3ap_iPMCAddress,
{ "iPMCAddress", "m3ap.iPMCAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_m3ap_iPSourceAddress,
{ "iPSourceAddress", "m3ap.iPSourceAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"IPAddress", HFILL }},
{ &hf_m3ap_gTP_DLTEID,
{ "gTP-DLTEID", "m3ap.gTP_DLTEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_m3ap_protocolIEs,
{ "protocolIEs", "m3ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_m3ap_m3_Interface,
{ "m3-Interface", "m3ap.m3_Interface",
FT_UINT32, BASE_DEC, VALS(m3ap_ResetAll_vals), 0,
"ResetAll", HFILL }},
{ &hf_m3ap_partOfM3_Interface,
{ "partOfM3-Interface", "m3ap.partOfM3_Interface",
FT_UINT32, BASE_DEC, NULL, 0,
"MBMS_Service_associatedLogicalM3_ConnectionListRes", HFILL }},
{ &hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListRes_item,
{ "ProtocolIE-Single-Container", "m3ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck_item,
{ "ProtocolIE-Single-Container", "m3ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_privateIEs,
{ "privateIEs", "m3ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_m3ap_MBMSServiceAreaListItem_item,
{ "MBMSServiceArea1", "m3ap.MBMSServiceArea1",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_initiatingMessage,
{ "initiatingMessage", "m3ap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_successfulOutcome,
{ "successfulOutcome", "m3ap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "m3ap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_m3ap_initiatingMessagevalue,
{ "value", "m3ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_m3ap_successfulOutcome_value,
{ "value", "m3ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_m3ap_unsuccessfulOutcome_value,
{ "value", "m3ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 156 "../../asn1/m3ap/packet-m3ap-template.c"
};
static gint *ett[] = {
&ett_m3ap,
#line 1 "../../asn1/m3ap/packet-m3ap-ettarr.c"
&ett_m3ap_PrivateIE_ID,
&ett_m3ap_ProtocolIE_Container,
&ett_m3ap_ProtocolIE_Field,
&ett_m3ap_ProtocolIE_ContainerList,
&ett_m3ap_ProtocolExtensionContainer,
&ett_m3ap_ProtocolExtensionField,
&ett_m3ap_PrivateIE_Container,
&ett_m3ap_PrivateIE_Field,
&ett_m3ap_AllocationAndRetentionPriority,
&ett_m3ap_Cause,
&ett_m3ap_CriticalityDiagnostics,
&ett_m3ap_CriticalityDiagnostics_IE_List,
&ett_m3ap_CriticalityDiagnostics_IE_List_item,
&ett_m3ap_Global_MCE_ID,
&ett_m3ap_GBR_QosInformation,
&ett_m3ap_MBMS_E_RAB_QoS_Parameters,
&ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionItem,
&ett_m3ap_TMGI,
&ett_m3ap_TNL_Information,
&ett_m3ap_MBMSSessionStartRequest,
&ett_m3ap_MBMSSessionStartResponse,
&ett_m3ap_MBMSSessionStartFailure,
&ett_m3ap_MBMSSessionStopRequest,
&ett_m3ap_MBMSSessionStopResponse,
&ett_m3ap_MBMSSessionUpdateRequest,
&ett_m3ap_MBMSSessionUpdateResponse,
&ett_m3ap_MBMSSessionUpdateFailure,
&ett_m3ap_ErrorIndication,
&ett_m3ap_Reset,
&ett_m3ap_ResetType,
&ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListRes,
&ett_m3ap_ResetAcknowledge,
&ett_m3ap_MBMS_Service_associatedLogicalM3_ConnectionListResAck,
&ett_m3ap_PrivateMessage,
&ett_m3ap_M3SetupRequest,
&ett_m3ap_MBMSServiceAreaListItem,
&ett_m3ap_M3SetupResponse,
&ett_m3ap_M3SetupFailure,
&ett_m3ap_MCEConfigurationUpdate,
&ett_m3ap_MCEConfigurationUpdateAcknowledge,
&ett_m3ap_MCEConfigurationUpdateFailure,
&ett_m3ap_M3AP_PDU,
&ett_m3ap_InitiatingMessage,
&ett_m3ap_SuccessfulOutcome,
&ett_m3ap_UnsuccessfulOutcome,
#line 162 "../../asn1/m3ap/packet-m3ap-template.c"
};
proto_m3ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_m3ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
m3ap_ies_dissector_table = register_dissector_table("m3ap.ies", "M3AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
m3ap_extension_dissector_table = register_dissector_table("m3ap.extension", "M3AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
m3ap_proc_imsg_dissector_table = register_dissector_table("m3ap.proc.imsg", "M3AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
m3ap_proc_sout_dissector_table = register_dissector_table("m3ap.proc.sout", "M3AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
m3ap_proc_uout_dissector_table = register_dissector_table("m3ap.proc.uout", "M3AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_m3ap(void)
{
static gboolean inited = FALSE;
static guint SctpPort;
if( !inited ) {
m3ap_handle = create_dissector_handle(dissect_m3ap, proto_m3ap);
dissector_add_uint("sctp.ppi", PROTO_3GPP_M3AP_PROTOCOL_ID, m3ap_handle);
inited = TRUE;
#line 1 "../../asn1/m3ap/packet-m3ap-dis-tab.c"
dissector_add_uint("m3ap.ies", id_MME_MBMS_M3AP_ID, new_create_dissector_handle(dissect_MME_MBMS_M3AP_ID_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MCE_MBMS_M3AP_ID, new_create_dissector_handle(dissect_MCE_MBMS_M3AP_ID_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_TMGI, new_create_dissector_handle(dissect_TMGI_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_Session_ID, new_create_dissector_handle(dissect_MBMS_Session_ID_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_E_RAB_QoS_Parameters, new_create_dissector_handle(dissect_MBMS_E_RAB_QoS_Parameters_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_Session_Duration, new_create_dissector_handle(dissect_MBMS_Session_Duration_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_Service_Area, new_create_dissector_handle(dissect_MBMS_Service_Area_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_TNL_Information, new_create_dissector_handle(dissect_TNL_Information_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_CriticalityDiagnostics, new_create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_TimeToWait, new_create_dissector_handle(dissect_TimeToWait_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_ResetType, new_create_dissector_handle(dissect_ResetType_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_Service_associatedLogicalM3_ConnectionItem, new_create_dissector_handle(dissect_MBMS_Service_associatedLogicalM3_ConnectionItem_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMS_Service_associatedLogicalM3_ConnectionListResAck, new_create_dissector_handle(dissect_MBMS_Service_associatedLogicalM3_ConnectionListResAck_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MinimumTimeToMBMSDataTransfer, new_create_dissector_handle(dissect_MinimumTimeToMBMSDataTransfer_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_AllocationAndRetentionPriority, new_create_dissector_handle(dissect_AllocationAndRetentionPriority_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_Global_MCE_ID, new_create_dissector_handle(dissect_Global_MCE_ID_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MCEname, new_create_dissector_handle(dissect_MCEname_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_MBMSServiceAreaList, new_create_dissector_handle(dissect_MBMSServiceAreaListItem_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_Time_ofMBMS_DataTransfer, new_create_dissector_handle(dissect_Absolute_Time_ofMBMS_Data_PDU, proto_m3ap));
dissector_add_uint("m3ap.ies", id_Time_ofMBMS_DataStop, new_create_dissector_handle(dissect_Absolute_Time_ofMBMS_Data_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_mBMSsessionStart, new_create_dissector_handle(dissect_MBMSSessionStartRequest_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_mBMSsessionStart, new_create_dissector_handle(dissect_MBMSSessionStartResponse_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.uout", id_mBMSsessionStart, new_create_dissector_handle(dissect_MBMSSessionStartFailure_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_mBMSsessionStop, new_create_dissector_handle(dissect_MBMSSessionStopRequest_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_mBMSsessionStop, new_create_dissector_handle(dissect_MBMSSessionStopResponse_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_mBMSsessionUpdate, new_create_dissector_handle(dissect_MBMSSessionUpdateRequest_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_mBMSsessionUpdate, new_create_dissector_handle(dissect_MBMSSessionUpdateResponse_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.uout", id_mBMSsessionUpdate, new_create_dissector_handle(dissect_MBMSSessionUpdateFailure_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_errorIndication, new_create_dissector_handle(dissect_ErrorIndication_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_Reset, new_create_dissector_handle(dissect_Reset_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_Reset, new_create_dissector_handle(dissect_ResetAcknowledge_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_privateMessage, new_create_dissector_handle(dissect_PrivateMessage_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_mCEConfigurationUpdate, new_create_dissector_handle(dissect_MCEConfigurationUpdate_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_mCEConfigurationUpdate, new_create_dissector_handle(dissect_MCEConfigurationUpdateAcknowledge_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.uout", id_mCEConfigurationUpdate, new_create_dissector_handle(dissect_MCEConfigurationUpdateFailure_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.imsg", id_m3Setup, new_create_dissector_handle(dissect_M3SetupRequest_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.sout", id_m3Setup, new_create_dissector_handle(dissect_M3SetupResponse_PDU, proto_m3ap));
dissector_add_uint("m3ap.proc.uout", id_m3Setup, new_create_dissector_handle(dissect_M3SetupFailure_PDU, proto_m3ap));
#line 192 "../../asn1/m3ap/packet-m3ap-template.c"
dissector_add_uint("m3ap.extension", 17, new_create_dissector_handle(dissect_AllocationAndRetentionPriority_PDU, proto_m3ap));
}
else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, m3ap_handle);
}
}
SctpPort = global_m3ap_port;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, m3ap_handle);
}
}
