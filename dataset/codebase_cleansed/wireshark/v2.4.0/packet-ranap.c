static int
dissect_ranap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_ranap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_ranap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 91 "./asn1/ranap/ranap.cnf"
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext_const(ProcedureCode, &ranap_ProcedureCode_vals_ext,
"unknown message"));
return offset;
}
static int
dissect_ranap_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolExtensionID, FALSE);
return offset;
}
static int
dissect_ranap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolIE_ID, FALSE);
#line 75 "./asn1/ranap/ranap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(ProtocolIE_ID, &ranap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_ranap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_ranap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_ranap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_ranap_T_firstValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldPairFirstValue);
return offset;
}
static int
dissect_ranap_T_secondValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldPairSecondValue);
return offset;
}
static int
dissect_ranap_ProtocolIE_FieldPair(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_FieldPair, ProtocolIE_FieldPair_sequence);
return offset;
}
static int
dissect_ranap_ProtocolIE_ContainerPair(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_ContainerPair, ProtocolIE_ContainerPair_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_ranap_ProtocolIE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 115 "./asn1/ranap/ranap.cnf"
static const asn1_par_def_t ProtocolIE_ContainerList_pars[] = {
{ "lowerBound", ASN1_PAR_INTEGER },
{ "upperBound", ASN1_PAR_INTEGER },
{ NULL, (asn1_par_type)0 }
};
asn1_stack_frame_check(actx, "ProtocolIE-ContainerList", ProtocolIE_ContainerList_pars);
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_ContainerList, ProtocolIE_ContainerList_sequence_of,
asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);
return offset;
}
static int
dissect_ranap_ProtocolIE_ContainerPairList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "./asn1/ranap/ranap.cnf"
static const asn1_par_def_t ProtocolIE_ContainerPairList_pars[] = {
{ "lowerBound", ASN1_PAR_INTEGER },
{ "upperBound", ASN1_PAR_INTEGER },
{ NULL, (asn1_par_type)0 }
};
asn1_stack_frame_check(actx, "ProtocolIE-ContainerPairList", ProtocolIE_ContainerPairList_pars);
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolIE_ContainerPairList, ProtocolIE_ContainerPairList_sequence_of,
asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);
return offset;
}
static int
dissect_ranap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_ranap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_ranap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_ranap_T_private_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_ranap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_ranap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_ranap_AccuracyFulfilmentIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_PLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 287 "./asn1/ranap/ranap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, E212_NONE, FALSE);
return offset;
}
static int
dissect_ranap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_LAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LAI, LAI_sequence);
return offset;
}
static int
dissect_ranap_RAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_Additional_CSPS_coordination_information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Additional_CSPS_coordination_information, Additional_CSPS_coordination_information_sequence);
return offset;
}
static int
dissect_ranap_Additional_PositioningMethodAndUsage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Additional_PositioningDataSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Additional_PositioningDataSet, Additional_PositioningDataSet_sequence_of,
1, maxAddPosSet, FALSE);
return offset;
}
static int
dissect_ranap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_QueuingAllowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_AllocationOrRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_AllocationOrRetentionPriority, AllocationOrRetentionPriority_sequence);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_MaxBitrateType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MaxBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_MaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_MaxBitrateList, Alt_RAB_Parameter_MaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_MaxBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_MaxBitrates, Alt_RAB_Parameter_MaxBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_MaxBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_MaxBitrateInf, Alt_RAB_Parameter_MaxBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_GuaranteedBitrateType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_GuaranteedBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_GuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_GuaranteedBitrateList, Alt_RAB_Parameter_GuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_GuaranteedBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_GuaranteedBitrates, Alt_RAB_Parameter_GuaranteedBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_GuaranteedBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_GuaranteedBitrateInf, Alt_RAB_Parameter_GuaranteedBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameters, Alt_RAB_Parameters_sequence);
return offset;
}
static int
dissect_ranap_ExtendedGuaranteedBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
16000001U, 256000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateList, Alt_RAB_Parameter_ExtendedGuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrates, Alt_RAB_Parameter_ExtendedGuaranteedBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf, Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_SupportedBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1000000000U, NULL, TRUE);
return offset;
}
static int
dissect_ranap_SupportedRAB_ParameterBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_SupportedRAB_ParameterBitrateList, SupportedRAB_ParameterBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrates, Alt_RAB_Parameter_SupportedGuaranteedBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf, Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_ExtendedMaxBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
16000001U, 256000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateList, Alt_RAB_Parameter_ExtendedMaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedMaxBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrates, Alt_RAB_Parameter_ExtendedMaxBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf, Alt_RAB_Parameter_ExtendedMaxBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_SupportedMaxBitrates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_SupportedMaxBitrates, Alt_RAB_Parameter_SupportedMaxBitrates_sequence_of,
1, maxNrOfAltValues, FALSE);
return offset;
}
static int
dissect_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf, Alt_RAB_Parameter_SupportedMaxBitrateInf_sequence);
return offset;
}
static int
dissect_ranap_AlternativeRABConfigurationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_OCTET_STRING_SIZE_1_1000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1000, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Cell_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 268435455U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CellIdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_CellIdList, CellIdList_sequence_of,
1, maxNrOfCellIds, FALSE);
return offset;
}
static int
dissect_ranap_CellBased(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CellBased, CellBased_sequence);
return offset;
}
static int
dissect_ranap_LAI_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_LAI_List, LAI_List_sequence_of,
1, maxNrOfLAIs, FALSE);
return offset;
}
static int
dissect_ranap_LABased(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LABased, LABased_sequence);
return offset;
}
static int
dissect_ranap_RAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAI, RAI_sequence);
return offset;
}
static int
dissect_ranap_RAI_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAI_List, RAI_List_sequence_of,
1, maxNrOfRAIs, FALSE);
return offset;
}
static int
dissect_ranap_RABased(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RABased, RABased_sequence);
return offset;
}
static int
dissect_ranap_PLMNList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PLMNList, PLMNList_sequence_of,
1, maxnoofPLMNs, FALSE);
return offset;
}
static int
dissect_ranap_PLMNBased(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PLMNBased, PLMNBased_sequence);
return offset;
}
static int
dissect_ranap_AreaScopeForUEApplicationLayerMeasurementConfiguration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_AreaScopeForUEApplicationLayerMeasurementConfiguration, AreaScopeForUEApplicationLayerMeasurementConfiguration_choice,
NULL);
return offset;
}
static int
dissect_ranap_UE_Application_Layer_Measurement_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_Application_Layer_Measurement_Configuration, UE_Application_Layer_Measurement_Configuration_sequence);
return offset;
}
static int
dissect_ranap_TraceReference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 3, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TraceRecordingSessionReference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_TraceDepth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_T_interface(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_InterfacesToTraceItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InterfacesToTraceItem, InterfacesToTraceItem_sequence);
return offset;
}
static int
dissect_ranap_ListOfInterfacesToTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ListOfInterfacesToTrace, ListOfInterfacesToTrace_sequence_of,
1, maxNrOfInterfaces, FALSE);
return offset;
}
static int
dissect_ranap_TracePropagationParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TracePropagationParameters, TracePropagationParameters_sequence);
return offset;
}
static int
dissect_ranap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 310 "./asn1/ranap/ranap.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_item *item;
proto_tree *subtree, *nsap_tree;
gint tvb_len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
tvb_len = tvb_reported_length(parameter_tvb);
subtree = proto_item_add_subtree(actx->created_item, ett_ranap_TransportLayerAddress);
if (tvb_len==4){
proto_tree_add_item(subtree, hf_ranap_transportLayerAddress_ipv4, parameter_tvb, 0, tvb_len, ENC_BIG_ENDIAN);
}
if (tvb_len==16){
proto_tree_add_item(subtree, hf_ranap_transportLayerAddress_ipv6, parameter_tvb, 0, tvb_len, ENC_NA);
}
if ((tvb_len==20) || (tvb_len==25)) {
item = proto_tree_add_item(subtree, hf_ranap_transportLayerAddress_nsap, parameter_tvb, 0, 20, ENC_NA);
nsap_tree = proto_item_add_subtree(item, ett_ranap_TransportLayerAddress_nsap);
dissect_nsap(parameter_tvb, 0, tvb_len, nsap_tree);
}
return offset;
}
static int
dissect_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation, UE_Application_Layer_Measurement_Configuration_For_Relocation_sequence);
return offset;
}
static int
dissect_ranap_APN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, NULL);
return offset;
}
static int
dissect_ranap_SAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_SAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SAI, SAI_sequence);
return offset;
}
static int
dissect_ranap_T_latitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_GeographicalCoordinates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GeographicalCoordinates, GeographicalCoordinates_sequence);
return offset;
}
static int
dissect_ranap_GA_Point(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_Point, GA_Point_sequence);
return offset;
}
static int
dissect_ranap_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_GA_PointWithUnCertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_PointWithUnCertainty, GA_PointWithUnCertainty_sequence);
return offset;
}
static int
dissect_ranap_GA_Polygon_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_Polygon_item, GA_Polygon_item_sequence);
return offset;
}
static int
dissect_ranap_GA_Polygon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_Polygon, GA_Polygon_sequence_of,
1, maxNrOfPoints, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_0_179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_GA_UncertaintyEllipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_UncertaintyEllipse, GA_UncertaintyEllipse_sequence);
return offset;
}
static int
dissect_ranap_GA_PointWithUnCertaintyEllipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_PointWithUnCertaintyEllipse, GA_PointWithUnCertaintyEllipse_sequence);
return offset;
}
static int
dissect_ranap_T_directionOfAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_GA_AltitudeAndDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_AltitudeAndDirection, GA_AltitudeAndDirection_sequence);
return offset;
}
static int
dissect_ranap_GA_PointWithAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_PointWithAltitude, GA_PointWithAltitude_sequence);
return offset;
}
static int
dissect_ranap_GA_PointWithAltitudeAndUncertaintyEllipsoid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_PointWithAltitudeAndUncertaintyEllipsoid, GA_PointWithAltitudeAndUncertaintyEllipsoid_sequence);
return offset;
}
static int
dissect_ranap_GA_EllipsoidArc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GA_EllipsoidArc, GA_EllipsoidArc_sequence);
return offset;
}
static int
dissect_ranap_GeographicalArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_GeographicalArea, GeographicalArea_choice,
NULL);
return offset;
}
static int
dissect_ranap_AreaIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_AreaIdentity, AreaIdentity_choice,
NULL);
return offset;
}
static int
dissect_ranap_Ass_RAB_Parameter_MaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Ass_RAB_Parameter_MaxBitrateList, Ass_RAB_Parameter_MaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Ass_RAB_Parameter_GuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Ass_RAB_Parameter_GuaranteedBitrateList, Ass_RAB_Parameter_GuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Ass_RAB_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Ass_RAB_Parameters, Ass_RAB_Parameters_sequence);
return offset;
}
static int
dissect_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList, Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList, Ass_RAB_Parameter_ExtendedMaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_SNAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_AuthorisedSNAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_AuthorisedSNAs, AuthorisedSNAs_sequence_of,
1, maxNrOfSNAs, FALSE);
return offset;
}
static int
dissect_ranap_AuthorisedPLMNs_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_AuthorisedPLMNs_item, AuthorisedPLMNs_item_sequence);
return offset;
}
static int
dissect_ranap_AuthorisedPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_AuthorisedPLMNs, AuthorisedPLMNs_sequence_of,
1, maxNrOfPLMNsSN, FALSE);
return offset;
}
static int
dissect_ranap_BarometricPressure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
30000U, 115000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_BindingID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 389 "./asn1/ranap/ranap.cnf"
tvbuff_t *value_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, &value_tvb);
if (tvb_get_ntohs(value_tvb, 2) == 0) {
guint16 port_number = tvb_get_ntohs(value_tvb, 0);
proto_item_append_text(actx->created_item, " (%u)", port_number);
}
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_56(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
56, 56, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_BroadcastAssistanceDataDecipheringKeys(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_BroadcastAssistanceDataDecipheringKeys, BroadcastAssistanceDataDecipheringKeys_sequence);
return offset;
}
static int
dissect_ranap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseTransmissionNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
65U, 80U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseNAS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
81U, 96U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
97U, 112U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
113U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseNon_Standard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
129U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CauseRadioNetworkExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
257U, 512U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_ranap_Cell_Access_Mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_Cell_Capacity_Class_Value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, TRUE);
return offset;
}
static int
dissect_ranap_LoadValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_RTLoadValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_NRTLoadInformationValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CellLoadInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CellLoadInformation, CellLoadInformation_sequence);
return offset;
}
static int
dissect_ranap_TargetCellId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 268435455U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SourceUTRANCellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SourceUTRANCellID, SourceUTRANCellID_sequence);
return offset;
}
static int
dissect_ranap_CI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CGI, CGI_sequence);
return offset;
}
static int
dissect_ranap_SourceCellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_SourceCellID, SourceCellID_choice,
NULL);
return offset;
}
static int
dissect_ranap_CellLoadInformationGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CellLoadInformationGroup, CellLoadInformationGroup_sequence);
return offset;
}
static int
dissect_ranap_CellType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_CivicAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_ClientType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RepetitionNumber0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_ranap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_ranap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_ranap_RepetitionNumber1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_MessageStructure_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MessageStructure_item, MessageStructure_item_sequence);
return offset;
}
static int
dissect_ranap_MessageStructure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_MessageStructure, MessageStructure_sequence_of,
1, maxNrOfLevels, FALSE);
return offset;
}
static int
dissect_ranap_EncryptionAlgorithm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_ChosenEncryptionAlgorithm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_EncryptionAlgorithm(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_IntegrityProtectionAlgorithm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_ChosenIntegrityProtectionAlgorithm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_IntegrityProtectionAlgorithm(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_ClassmarkInformation2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_ClassmarkInformation3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_CN_DomainIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_CN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Correlation_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_ranap_CSFB_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_CSG_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_CSG_Id_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_CSG_Id_List, CSG_Id_List_sequence_of,
1, maxNrOfCSGs, FALSE);
return offset;
}
static int
dissect_ranap_CSG_Membership_Status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_DataPDUType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_DataVolumeReference(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DataVolumeReportingIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_DCH_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DCN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DeliveryOfErroneousSDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_DeliveryOrder(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_NewRAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_NewRAListofIdleModeUEs, NewRAListofIdleModeUEs_sequence_of,
1, maxMBMSRA, FALSE);
return offset;
}
static int
dissect_ranap_RAListwithNoIdleModeUEsAnyMore(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAListwithNoIdleModeUEsAnyMore, RAListwithNoIdleModeUEsAnyMore_sequence_of,
1, maxMBMSRA, FALSE);
return offset;
}
static int
dissect_ranap_DeltaRAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DeltaRAListofIdleModeUEs, DeltaRAListofIdleModeUEs_sequence);
return offset;
}
static int
dissect_ranap_DL_GTP_PDU_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DL_N_PDU_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_D_RNTI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DRX_CycleLengthCoefficient(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
6U, 9U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_DSCH_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_EARFCN_Extended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
65536U, 262143U, NULL, TRUE);
return offset;
}
static int
dissect_ranap_E_DCH_MAC_d_Flow_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxNrOfEDCHMACdFlows_1, NULL, FALSE);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
18, 18, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_21(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
21, 21, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_ranap_PermittedEncryptionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PermittedEncryptionAlgorithms, PermittedEncryptionAlgorithms_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_ranap_EncryptionKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
int
dissect_ranap_EncryptionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EncryptionInformation, EncryptionInformation_sequence);
return offset;
}
static int
dissect_ranap_End_Of_CSFB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_IMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_ranap_IMEIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_IMEIList, IMEIList_sequence_of,
1, maxNrOfUEsToBeTraced, FALSE);
return offset;
}
static int
dissect_ranap_IMEISV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_ranap_IMEISVList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_IMEISVList, IMEISVList_sequence_of,
1, maxNrOfUEsToBeTraced, FALSE);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
7, 7, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_IMEIGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_IMEIGroup, IMEIGroup_sequence);
return offset;
}
static int
dissect_ranap_IMEISVGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_IMEISVGroup, IMEISVGroup_sequence);
return offset;
}
static int
dissect_ranap_EquipmentsToBeTraced(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_EquipmentsToBeTraced, EquipmentsToBeTraced_choice,
NULL);
return offset;
}
static int
dissect_ranap_E_UTRAN_Service_Handover(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_Event(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 3, NULL);
return offset;
}
static int
dissect_ranap_MeasurementQuantity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_M120_165(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-120, 165U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Event1F_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Event1F_Parameters, Event1F_Parameters_sequence);
return offset;
}
static int
dissect_ranap_INTEGER_M120_M25(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-120, -25, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Event1I_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Event1I_Parameters, Event1I_Parameters_sequence);
return offset;
}
static int
dissect_ranap_ExtendedRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_FrameSequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_FrequenceLayerConvergenceFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_GANSS_PositioningMethodAndUsage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_GANSS_PositioningDataSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_GANSS_PositioningDataSet, GANSS_PositioningDataSet_sequence_of,
1, maxGANSSSet, FALSE);
return offset;
}
static int
dissect_ranap_GERAN_BSC_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_GERAN_Cell_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GERAN_Cell_ID, GERAN_Cell_ID_sequence);
return offset;
}
static int
dissect_ranap_GERAN_Classmark(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_GlobalCN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GlobalCN_ID, GlobalCN_ID_sequence);
return offset;
}
static int
dissect_ranap_RNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_GlobalRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GlobalRNC_ID, GlobalRNC_ID_sequence);
return offset;
}
static int
dissect_ranap_GTP_TEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 339 "./asn1/ranap/ranap.cnf"
tvbuff_t *parameter_tvb=NULL;
int saved_hf;
saved_hf = hf_index;
hf_index = -1;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
proto_tree_add_item(tree, saved_hf, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_ranap_HigherBitratesThan16MbpsFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_HS_DSCH_MAC_d_Flow_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxNrOfHSDSCHMACdFlows_1, NULL, FALSE);
return offset;
}
static int
dissect_ranap_MeasurementsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_ReportInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_ranap_ReportAmount(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MDT_Report_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MDT_Report_Parameters, MDT_Report_Parameters_sequence);
return offset;
}
static int
dissect_ranap_M1Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_M1Report, M1Report_choice,
NULL);
return offset;
}
static int
dissect_ranap_M2Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_M2Report, M2Report_choice,
NULL);
return offset;
}
static int
dissect_ranap_ImmediateMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ImmediateMDT, ImmediateMDT_sequence);
return offset;
}
static int
dissect_ranap_IMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 188 "./asn1/ranap/ranap.cnf"
tvbuff_t* imsi_tvb;
const char *digit_str;
sccp_msg_info_t *sccp_info;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 8, FALSE, &imsi_tvb);
if(!imsi_tvb)
return offset;
PROTO_ITEM_SET_HIDDEN(actx->created_item);
digit_str = dissect_e212_imsi(imsi_tvb, actx->pinfo, tree, 0, tvb_reported_length(imsi_tvb), FALSE);
sccp_info = (sccp_msg_info_t *)p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_ranap, actx->pinfo->curr_layer_num);
if ( sccp_info && sccp_info->data.co.assoc && ! sccp_info->data.co.assoc->calling_party ) {
sccp_info->data.co.assoc->calling_party =
wmem_strdup_printf(wmem_file_scope(), "IMSI: %s", digit_str );
}
return offset;
}
static int
dissect_ranap_IncludeVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_InformationExchangeID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_InformationExchangeType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TMGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TMGI, TMGI_sequence);
return offset;
}
static int
dissect_ranap_IPMulticastAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 16, FALSE, NULL);
return offset;
}
static int
dissect_ranap_MBMSIPMulticastAddressandAPNlist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSIPMulticastAddressandAPNlist, MBMSIPMulticastAddressandAPNlist_sequence);
return offset;
}
static int
dissect_ranap_RequestedMBMSIPMulticastAddressandAPNRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RequestedMBMSIPMulticastAddressandAPNRequest, RequestedMBMSIPMulticastAddressandAPNRequest_sequence_of,
1, maxnoofMulticastServicesPerRNC, FALSE);
return offset;
}
static int
dissect_ranap_RequestedMulticastServiceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RequestedMulticastServiceList, RequestedMulticastServiceList_sequence_of,
1, maxnoofMulticastServicesPerUE, FALSE);
return offset;
}
static int
dissect_ranap_InformationRequested(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationRequested, InformationRequested_choice,
NULL);
return offset;
}
static int
dissect_ranap_MBMSIPMulticastAddressandAPNRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSIPMulticastAddressandAPNRequest, MBMSIPMulticastAddressandAPNRequest_sequence_of,
1, maxnoofMulticastServicesPerRNC, FALSE);
return offset;
}
static int
dissect_ranap_PermanentNAS_UE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_PermanentNAS_UE_ID, PermanentNAS_UE_ID_choice,
NULL);
return offset;
}
static int
dissect_ranap_InformationRequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationRequestType, InformationRequestType_choice,
NULL);
return offset;
}
static int
dissect_ranap_InformationTransferID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_T_traceActivationIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_RNCTraceInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RNCTraceInformation, RNCTraceInformation_sequence);
return offset;
}
static int
dissect_ranap_InformationTransferType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationTransferType, InformationTransferType_choice,
NULL);
return offset;
}
static int
dissect_ranap_PermittedIntegrityProtectionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PermittedIntegrityProtectionAlgorithms, PermittedIntegrityProtectionAlgorithms_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_ranap_IntegrityProtectionKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
int
dissect_ranap_IntegrityProtectionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_IntegrityProtectionInformation, IntegrityProtectionInformation_sequence);
return offset;
}
static int
dissect_ranap_RIMInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 407 "./asn1/ranap/ranap.cnf"
tvbuff_t *value_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &value_tvb);
if (value_tvb){
call_dissector_only(bssgp_handle, value_tvb, actx->pinfo, tree, NULL);
}
return offset;
}
int
dissect_ranap_TargetRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TargetRNC_ID, TargetRNC_ID_sequence);
return offset;
}
static int
dissect_ranap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TAI, TAI_sequence);
return offset;
}
static int
dissect_ranap_TargetENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TargetENB_ID, TargetENB_ID_sequence);
return offset;
}
static int
dissect_ranap_RIMRoutingAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_RIMRoutingAddress, RIMRoutingAddress_choice,
NULL);
return offset;
}
static int
dissect_ranap_RIM_Transfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RIM_Transfer, RIM_Transfer_sequence);
return offset;
}
static int
dissect_ranap_InterSystemInformationTransferType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_InterSystemInformationTransferType, InterSystemInformationTransferType_choice,
NULL);
return offset;
}
static int
dissect_ranap_InterSystemInformation_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InterSystemInformation_TransparentContainer, InterSystemInformation_TransparentContainer_sequence);
return offset;
}
static int
dissect_ranap_IuSignallingConnectionIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_IuTransportAssociation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_IuTransportAssociation, IuTransportAssociation_choice,
NULL);
return offset;
}
static int
dissect_ranap_KeyStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_ListOF_SNAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_ListOF_SNAs, ListOF_SNAs_sequence_of,
1, maxNrOfSNAs, FALSE);
return offset;
}
static int
dissect_ranap_LA_LIST_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LA_LIST_item, LA_LIST_item_sequence);
return offset;
}
static int
dissect_ranap_LA_LIST(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_LA_LIST, LA_LIST_sequence_of,
1, maxNrOfLAs, FALSE);
return offset;
}
static int
dissect_ranap_LastKnownServiceArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LastKnownServiceArea, LastKnownServiceArea_sequence);
return offset;
}
static int
dissect_ranap_UTRAN_CellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UTRAN_CellID, UTRAN_CellID_sequence);
return offset;
}
static int
dissect_ranap_Time_UE_StayedInCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_LastVisitedUTRANCell_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LastVisitedUTRANCell_Item, LastVisitedUTRANCell_Item_sequence);
return offset;
}
static int
dissect_ranap_LHN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
32, 256, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Links_to_log(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RequestedLocationRelatedDataType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 4, NULL);
return offset;
}
static int
dissect_ranap_RequestedGPSAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 38, FALSE, NULL);
return offset;
}
static int
dissect_ranap_LocationRelatedDataRequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationRelatedDataRequestType, LocationRelatedDataRequestType_sequence);
return offset;
}
static int
dissect_ranap_LocationRelatedDataRequestTypeSpecificToGERANIuMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_ReportChangeOfSAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_PeriodicReportingIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_DirectReportingIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_VerticalAccuracyCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_PositioningPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_ResponseTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_1_8639999_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8639999U, NULL, TRUE);
return offset;
}
static int
dissect_ranap_PeriodicLocationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PeriodicLocationInfo, PeriodicLocationInfo_sequence);
return offset;
}
static int
dissect_ranap_LocationReportingTransferInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationReportingTransferInformation, LocationReportingTransferInformation_sequence);
return offset;
}
static int
dissect_ranap_L3_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 275 "./asn1/ranap/ranap.cnf"
tvbuff_t *l3_info_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &l3_info_tvb);
if (l3_info_tvb)
dissector_try_uint(nas_pdu_dissector_table, 0x1, l3_info_tvb, actx->pinfo, proto_tree_get_root(tree));
return offset;
}
static int
dissect_ranap_M4_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_M4_Threshold(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_M4_Collection_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_M4_Collection_Parameters, M4_Collection_Parameters_sequence);
return offset;
}
static int
dissect_ranap_M4Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_M4Report, M4Report_choice,
NULL);
return offset;
}
static int
dissect_ranap_M5_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_M5Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_M5Report, M5Report_choice,
NULL);
return offset;
}
static int
dissect_ranap_M6_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_M6Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_M6Report, M6Report_sequence);
return offset;
}
static int
dissect_ranap_M7_Period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_M7Report(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_M7Report, M7Report_sequence);
return offset;
}
static int
dissect_ranap_Management_Based_MDT_Allowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MaxSDU_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32768U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_MBMS_PTP_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_MBMSBearerServiceType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSCNDe_Registration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSCountingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSHCIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSLinkingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSRegistrationRequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MBMSServiceArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_MBMSSessionDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_ranap_MBMSSessionIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_MBMSSessionRepetitionNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_MDT_Activation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_MDTAreaScope(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_MDTAreaScope, MDTAreaScope_choice,
NULL);
return offset;
}
static int
dissect_ranap_LoggingInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_LoggingDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_LoggedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LoggedMDT, LoggedMDT_sequence);
return offset;
}
static int
dissect_ranap_MDTMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_MDTMode, MDTMode_choice,
NULL);
return offset;
}
static int
dissect_ranap_MDT_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MDT_Configuration, MDT_Configuration_sequence);
return offset;
}
static int
dissect_ranap_MDT_PLMN_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_MDT_PLMN_List, MDT_PLMN_List_sequence_of,
1, maxnoofMDTPLMNs, FALSE);
return offset;
}
static int
dissect_ranap_MSISDN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 9, FALSE, NULL);
return offset;
}
static int
dissect_ranap_NAS_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 211 "./asn1/ranap/ranap.cnf"
tvbuff_t *nas_pdu_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &nas_pdu_tvb);
if (nas_pdu_tvb)
dissector_try_uint(nas_pdu_dissector_table, 0x1, nas_pdu_tvb, actx->pinfo, proto_tree_get_root(tree));
return offset;
}
static int
dissect_ranap_NAS_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_NAS_SynchronisationIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_NewBSS_To_OldBSS_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 267 "./asn1/ranap/ranap.cnf"
tvbuff_t *bss_info_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &bss_info_tvb);
if (bss_info_tvb)
bssmap_new_bss_to_old_bss_info(bss_info_tvb, tree, actx->pinfo);
return offset;
}
static int
dissect_ranap_NonSearchingIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_Null_NRI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_NumberOfIuInstances(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 2U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_NumberOfSteps(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Offload_RAB_Parameters_APN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Offload_RAB_Parameters_ChargingCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Offload_RAB_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Offload_RAB_Parameters, Offload_RAB_Parameters_sequence);
return offset;
}
static int
dissect_ranap_OldBSS_ToNewBSS_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 259 "./asn1/ranap/ranap.cnf"
tvbuff_t *bss_info_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &bss_info_tvb);
if (bss_info_tvb)
bssmap_old_bss_to_new_bss_info(bss_info_tvb, tree, actx->pinfo);
return offset;
}
static int
dissect_ranap_OMC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 22, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Out_Of_UTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_PagingAreaID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_PagingAreaID, PagingAreaID_choice,
NULL);
return offset;
}
static int
dissect_ranap_PagingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_ranap_PDP_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_PDP_TypeInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PDP_TypeInformation, PDP_TypeInformation_sequence_of,
1, maxNrOfPDPDirections, FALSE);
return offset;
}
static int
dissect_ranap_PDP_Type_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_PDP_TypeInformation_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PDP_TypeInformation_extension, PDP_TypeInformation_extension_sequence_of,
1, maxNrOfPDPDirections, FALSE);
return offset;
}
static int
dissect_ranap_PDUType14FrameSequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_PLMNs_in_shared_network_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PLMNs_in_shared_network_item, PLMNs_in_shared_network_item_sequence);
return offset;
}
static int
dissect_ranap_PLMNs_in_shared_network(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PLMNs_in_shared_network, PLMNs_in_shared_network_sequence_of,
1, maxNrOfPLMNsSN, FALSE);
return offset;
}
static int
dissect_ranap_Port_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_PositioningDataDiscriminator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_PositioningMethodAndUsage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_PositioningDataSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_PositioningDataSet, PositioningDataSet_sequence_of,
1, maxSet, FALSE);
return offset;
}
static int
dissect_ranap_PositionData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PositionData, PositionData_sequence);
return offset;
}
static int
dissect_ranap_PositionDataSpecificToGERANIuMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Priority_Class_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_Shared_Network_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Shared_Network_Information, Shared_Network_Information_sequence);
return offset;
}
static int
dissect_ranap_ProvidedData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_ProvidedData, ProvidedData_choice,
NULL);
return offset;
}
static int
dissect_ranap_PowerSavingIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_P_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_ranap_RAB_AsymmetryIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_UnsuccessfullyTransmittedDataVolume(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_RABDataVolumeReport_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RABDataVolumeReport_item, RABDataVolumeReport_item_sequence);
return offset;
}
static int
dissect_ranap_RABDataVolumeReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RABDataVolumeReport, RABDataVolumeReport_sequence_of,
1, maxNrOfVol, FALSE);
return offset;
}
static int
dissect_ranap_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList, RAB_Parameter_ExtendedGuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_RAB_Parameter_ExtendedMaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_Parameter_ExtendedMaxBitrateList, RAB_Parameter_ExtendedMaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_RAB_Parameter_GuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_Parameter_GuaranteedBitrateList, RAB_Parameter_GuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_RAB_Parameter_MaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_Parameter_MaxBitrateList, RAB_Parameter_MaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_TrafficClass(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_1_9(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 9U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_1_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 6U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SDU_ErrorRatio(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SDU_ErrorRatio, SDU_ErrorRatio_sequence);
return offset;
}
static int
dissect_ranap_INTEGER_1_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_ResidualBitErrorRatio(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResidualBitErrorRatio, ResidualBitErrorRatio_sequence);
return offset;
}
static int
dissect_ranap_SubflowSDU_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_RAB_SubflowCombinationBitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SDU_FormatInformationParameters_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SDU_FormatInformationParameters_item, SDU_FormatInformationParameters_item_sequence);
return offset;
}
static int
dissect_ranap_SDU_FormatInformationParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_SDU_FormatInformationParameters, SDU_FormatInformationParameters_sequence_of,
1, maxRAB_SubflowCombination, FALSE);
return offset;
}
static int
dissect_ranap_SDU_Parameters_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SDU_Parameters_item, SDU_Parameters_item_sequence);
return offset;
}
static int
dissect_ranap_SDU_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_SDU_Parameters, SDU_Parameters_sequence_of,
1, maxRAB_Subflows, FALSE);
return offset;
}
static int
dissect_ranap_TransferDelay(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_TrafficHandlingPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SourceStatisticsDescriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RelocationRequirement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_ranap_RAB_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_Parameters, RAB_Parameters_sequence);
return offset;
}
static int
dissect_ranap_UPInitialisationFrame(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_UPInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UPInformation, UPInformation_sequence);
return offset;
}
static int
dissect_ranap_RABParametersList_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RABParametersList_item, RABParametersList_item_sequence);
return offset;
}
static int
dissect_ranap_RABParametersList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RABParametersList, RABParametersList_sequence_of,
1, maxNrOfRABs, FALSE);
return offset;
}
static int
dissect_ranap_USCH_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_TrCH_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TrCH_ID, TrCH_ID_sequence);
return offset;
}
static int
dissect_ranap_TrCH_ID_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_TrCH_ID_List, TrCH_ID_List_sequence_of,
1, maxRAB_Subflows, FALSE);
return offset;
}
static int
dissect_ranap_RAB_TrCH_MappingItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_TrCH_MappingItem, RAB_TrCH_MappingItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_TrCH_Mapping(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_TrCH_Mapping, RAB_TrCH_Mapping_sequence_of,
1, maxNrOfRABs, FALSE);
return offset;
}
static int
dissect_ranap_RAofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_RAofIdleModeUEs, RAofIdleModeUEs_sequence_of,
1, maxMBMSRA, FALSE);
return offset;
}
static int
dissect_ranap_NotEmptyRAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_NotEmptyRAListofIdleModeUEs, NotEmptyRAListofIdleModeUEs_sequence);
return offset;
}
static int
dissect_ranap_T_emptyFullRAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_RAListofIdleModeUEs, RAListofIdleModeUEs_choice,
NULL);
return offset;
}
static int
dissect_ranap_LAListofIdleModeUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_LAListofIdleModeUEs, LAListofIdleModeUEs_sequence_of,
1, maxMBMSRA, FALSE);
return offset;
}
static int
dissect_ranap_RAT_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RedirectAttemptFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RedirectionCompleted(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RejectCauseValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_ranap_RelocationType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_ReportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RequestedGANSSAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 201, FALSE, NULL);
return offset;
}
static int
dissect_ranap_Requested_RAB_Parameter_MaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Requested_RAB_Parameter_MaxBitrateList, Requested_RAB_Parameter_MaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Requested_RAB_Parameter_GuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Requested_RAB_Parameter_GuaranteedBitrateList, Requested_RAB_Parameter_GuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Requested_RAB_Parameter_Values(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Requested_RAB_Parameter_Values, Requested_RAB_Parameter_Values_sequence);
return offset;
}
static int
dissect_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList, Requested_RAB_Parameter_ExtendedMaxBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList, Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_sequence_of,
1, maxNrOfSeparateTrafficDirections, FALSE);
return offset;
}
static int
dissect_ranap_RequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RequestType, RequestType_sequence);
return offset;
}
static int
dissect_ranap_UE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_ID, UE_ID_choice,
NULL);
return offset;
}
static int
dissect_ranap_TraceInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TraceInformation, TraceInformation_sequence);
return offset;
}
static int
dissect_ranap_RNSAPRelocationParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RNSAPRelocationParameters, RNSAPRelocationParameters_sequence);
return offset;
}
static int
dissect_ranap_RRC_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 220 "./asn1/ranap/ranap.cnf"
tvbuff_t *rrc_message_tvb=NULL;
guint8 container_choice=0;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &rrc_message_tvb);
if ((rrc_message_tvb)&&(tvb_reported_length(rrc_message_tvb)!=0)&&(glbl_dissect_container)){
switch(ProtocolIE_ID){
case id_Source_ToTarget_TransparentContainer:
call_dissector(rrc_s_to_trnc_handle,rrc_message_tvb,actx->pinfo, proto_tree_get_root(tree));
break;
case id_Target_ToSource_TransparentContainer:
container_choice = tvb_get_guint8(rrc_message_tvb, 0) >> 5;
if (container_choice < 7) {
call_dissector(rrc_t_to_srnc_handle,rrc_message_tvb,actx->pinfo, proto_tree_get_root(tree));
} else {
call_dissector(rrc_ho_to_utran_cmd,rrc_message_tvb,actx->pinfo, proto_tree_get_root(tree));
}
break;
default:
break;
}
}
return offset;
}
static int
dissect_ranap_RSRVCC_HO_Indication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_BIT_STRING_SIZE_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
128, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_OCTET_STRING_SIZE_1_maxSizeOfIMSInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, maxSizeOfIMSInfo, FALSE, NULL);
return offset;
}
static int
dissect_ranap_RSRVCC_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RSRVCC_Information, RSRVCC_Information_sequence);
return offset;
}
static int
dissect_ranap_RSRVCC_Operation_Possible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_SAPI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_SessionUpdateID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_Session_Re_establishment_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_SignallingIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_SGSN_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_ranap_SGSN_Group_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_SGSN_Group_Identity, SGSN_Group_Identity_choice,
NULL);
return offset;
}
static int
dissect_ranap_SNA_Access_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SNA_Access_Information, SNA_Access_Information_sequence);
return offset;
}
int
dissect_ranap_Service_Handover(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_Source_ToTarget_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 374 "./asn1/ranap/ranap.cnf"
dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer(tvb , offset, actx ,tree , hf_ranap_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU );
return offset;
}
static int
dissect_ranap_SourceBSS_ToTargetBSS_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_SourceRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SourceRNC_ID, SourceRNC_ID_sequence);
return offset;
}
static int
dissect_ranap_SourceID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_SourceID, SourceID_choice,
NULL);
return offset;
}
static int
dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 351 "./asn1/ranap/ranap.cnf"
ProtocolIE_ID = id_Source_ToTarget_TransparentContainer;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SourceRNC_ToTargetRNC_TransparentContainer, SourceRNC_ToTargetRNC_TransparentContainer_sequence);
return offset;
}
static int
dissect_ranap_INTEGER_0_97(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_0_34(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_1_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_MeasBand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_EUTRANFrequencies_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EUTRANFrequencies_item, EUTRANFrequencies_item_sequence);
return offset;
}
static int
dissect_ranap_EUTRANFrequencies(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_EUTRANFrequencies, EUTRANFrequencies_sequence_of,
1, maxNrOfEUTRAFreqs, FALSE);
return offset;
}
static int
dissect_ranap_IRATmeasurementParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_IRATmeasurementParameters, IRATmeasurementParameters_sequence);
return offset;
}
static int
dissect_ranap_IRAT_Measurement_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_IRAT_Measurement_Configuration, IRAT_Measurement_Configuration_sequence);
return offset;
}
static int
dissect_ranap_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_ranap_RSRQ_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RSRQ_Type, RSRQ_Type_sequence);
return offset;
}
static int
dissect_ranap_RSRQ_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-30, 46U, NULL, TRUE);
return offset;
}
static int
dissect_ranap_SubscriberProfileIDforRFP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SRB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_SRB_TrCH_MappingItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRB_TrCH_MappingItem, SRB_TrCH_MappingItem_sequence);
return offset;
}
static int
dissect_ranap_SRB_TrCH_Mapping(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_SRB_TrCH_Mapping, SRB_TrCH_Mapping_sequence_of,
1, maxNrOfSRBs, FALSE);
return offset;
}
static int
dissect_ranap_SRVCC_HO_Indication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_SRVCC_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRVCC_Information, SRVCC_Information_sequence);
return offset;
}
static int
dissect_ranap_SRVCC_Operation_Possible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_Target_ToSource_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 384 "./asn1/ranap/ranap.cnf"
dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer(tvb , offset, actx ,tree , hf_ranap_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU );
return offset;
}
static int
dissect_ranap_TargetBSS_ToSourceBSS_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TargetID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_TargetID, TargetID_choice,
NULL);
return offset;
}
static int
dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 360 "./asn1/ranap/ranap.cnf"
ProtocolIE_ID = id_Target_ToSource_TransparentContainer;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TargetRNC_ToSourceRNC_TransparentContainer, TargetRNC_ToSourceRNC_TransparentContainer_sequence);
return offset;
}
static int
dissect_ranap_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TemporaryUE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_TemporaryUE_ID, TemporaryUE_ID_choice,
NULL);
return offset;
}
static int
dissect_ranap_Time_UE_StayedInCell_EnhancedGranularity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 40950U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_TimeToMBMSDataTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TimingDifferenceULDL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TraceRecordingSessionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TraceRecordingSessionInformation, TraceRecordingSessionInformation_sequence);
return offset;
}
static int
dissect_ranap_TraceType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TriggerID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 22, FALSE, NULL);
return offset;
}
static int
dissect_ranap_TunnelInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TunnelInformation, TunnelInformation_sequence);
return offset;
}
static int
dissect_ranap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_UE_AggregateMaximumBitRateDownlink(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1000000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_UE_AggregateMaximumBitRateUplink(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1000000000U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_UE_AggregateMaximumBitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_AggregateMaximumBitRate, UE_AggregateMaximumBitRate_sequence);
return offset;
}
static int
dissect_ranap_UE_History_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 399 "./asn1/ranap/ranap.cnf"
tvbuff_t *value_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &value_tvb);
if (value_tvb)
dissect_s1ap_UE_HistoryInformation_PDU(value_tvb, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_ranap_UE_IsNotServed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_IsNotServed, UE_IsNotServed_sequence);
return offset;
}
static int
dissect_ranap_UE_IsServed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UE_IsServed, UE_IsServed_sequence);
return offset;
}
static int
dissect_ranap_UE_Usage_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_UERegistrationQueryResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_UERegistrationQueryResult, UERegistrationQueryResult_choice,
NULL);
return offset;
}
static int
dissect_ranap_UESBI_IuA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_UESBI_IuB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 128, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_UESBI_Iu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UESBI_Iu, UESBI_Iu_sequence);
return offset;
}
static int
dissect_ranap_UL_GTP_PDU_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_UL_N_PDU_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_UP_ModeVersions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_ranap_UserPlaneMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_INTEGER_0_359(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 359U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_HorizontalSpeedAndBearing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_HorizontalSpeedAndBearing, HorizontalSpeedAndBearing_sequence);
return offset;
}
static int
dissect_ranap_HorizontalVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_HorizontalVelocity, HorizontalVelocity_sequence);
return offset;
}
static int
dissect_ranap_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_ranap_VerticalSpeedDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_ranap_VerticalVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_VerticalVelocity, VerticalVelocity_sequence);
return offset;
}
static int
dissect_ranap_HorizontalWithVerticalVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_HorizontalWithVerticalVelocity, HorizontalWithVerticalVelocity_sequence);
return offset;
}
static int
dissect_ranap_HorizontalVelocityWithUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_HorizontalVelocityWithUncertainty, HorizontalVelocityWithUncertainty_sequence);
return offset;
}
static int
dissect_ranap_HorizontalWithVerticalVelocityAndUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_HorizontalWithVerticalVelocityAndUncertainty, HorizontalWithVerticalVelocityAndUncertainty_sequence);
return offset;
}
static int
dissect_ranap_VelocityEstimate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_VelocityEstimate, VelocityEstimate_choice,
NULL);
return offset;
}
static int
dissect_ranap_VoiceSupportMatchIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_ranap_RAB_IE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 141 "./asn1/ranap/ranap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxNrOfRABs);
offset = dissect_ranap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");
return offset;
}
static int
dissect_ranap_RAB_IE_ContainerPairList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 149 "./asn1/ranap/ranap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerPairList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxNrOfRABs);
offset = dissect_ranap_ProtocolIE_ContainerPairList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerPairList");
return offset;
}
static int
dissect_ranap_IuSigConId_IE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 166 "./asn1/ranap/ranap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxNrOfIuSigConIds);
offset = dissect_ranap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");
return offset;
}
static int
dissect_ranap_DirectTransfer_IE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 174 "./asn1/ranap/ranap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxNrOfDTs);
offset = dissect_ranap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");
return offset;
}
static int
dissect_ranap_Iu_ReleaseCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 417 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Iu-ReleaseCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Iu_ReleaseCommand, Iu_ReleaseCommand_sequence);
return offset;
}
static int
dissect_ranap_Iu_ReleaseComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 421 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Iu-ReleaseComplete ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Iu_ReleaseComplete, Iu_ReleaseComplete_sequence);
return offset;
}
static int
dissect_ranap_RAB_DataVolumeReportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_DataVolumeList_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DataVolumeList_item, DataVolumeList_item_sequence);
return offset;
}
static int
dissect_ranap_DataVolumeList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_DataVolumeList, DataVolumeList_sequence_of,
1, maxNrOfVol, FALSE);
return offset;
}
static int
dissect_ranap_RAB_DataVolumeReportItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_DataVolumeReportItem, RAB_DataVolumeReportItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_ReleasedList_IuRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ReleasedItem_IuRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ReleasedItem_IuRelComp, RAB_ReleasedItem_IuRelComp_sequence);
return offset;
}
static int
dissect_ranap_RelocationRequired(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 425 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationRequired ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationRequired, RelocationRequired_sequence);
return offset;
}
static int
dissect_ranap_RelocationCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 429 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationCommand, RelocationCommand_sequence);
return offset;
}
static int
dissect_ranap_RAB_RelocationReleaseList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_RelocationReleaseItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_RelocationReleaseItem, RAB_RelocationReleaseItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_DataForwardingList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_DataForwardingItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_DataForwardingItem, RAB_DataForwardingItem_sequence);
return offset;
}
static int
dissect_ranap_RelocationPreparationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 433 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationPreparationFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationPreparationFailure, RelocationPreparationFailure_sequence);
return offset;
}
static int
dissect_ranap_RelocationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 437 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationRequest, RelocationRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_RelocReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_UserPlaneInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UserPlaneInformation, UserPlaneInformation_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_RelocReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_RelocReq, RAB_SetupItem_RelocReq_sequence);
return offset;
}
static int
dissect_ranap_JoinedMBMSBearerService_IEs_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_JoinedMBMSBearerService_IEs_item, JoinedMBMSBearerService_IEs_item_sequence);
return offset;
}
static int
dissect_ranap_JoinedMBMSBearerService_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_JoinedMBMSBearerService_IEs, JoinedMBMSBearerService_IEs_sequence_of,
1, maxnoofMulticastServicesPerUE, FALSE);
return offset;
}
static int
dissect_ranap_CNMBMSLinkingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CNMBMSLinkingInformation, CNMBMSLinkingInformation_sequence);
return offset;
}
static int
dissect_ranap_RelocationRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 441 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationRequestAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationRequestAcknowledge, RelocationRequestAcknowledge_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_RelocReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_RelocReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_RelocReqAck, RAB_SetupItem_RelocReqAck_sequence);
return offset;
}
static int
dissect_ranap_RAB_FailedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_FailedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_FailedItem, RAB_FailedItem_sequence);
return offset;
}
static int
dissect_ranap_RelocationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 445 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationFailure, RelocationFailure_sequence);
return offset;
}
static int
dissect_ranap_RelocationCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 449 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationCancel ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationCancel, RelocationCancel_sequence);
return offset;
}
static int
dissect_ranap_RelocationCancelAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 453 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationCancelAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationCancelAcknowledge, RelocationCancelAcknowledge_sequence);
return offset;
}
static int
dissect_ranap_SRNS_ContextRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 457 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SRNS-ContextRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRNS_ContextRequest, SRNS_ContextRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_DataForwardingList_SRNS_CtxReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_DataForwardingItem_SRNS_CtxReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_DataForwardingItem_SRNS_CtxReq, RAB_DataForwardingItem_SRNS_CtxReq_sequence);
return offset;
}
static int
dissect_ranap_SRNS_ContextResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 461 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SRNS-ContextResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRNS_ContextResponse, SRNS_ContextResponse_sequence);
return offset;
}
static int
dissect_ranap_RAB_ContextList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ContextItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ContextItem, RAB_ContextItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_ContextFailedtoTransferList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RABs_ContextFailedtoTransferItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RABs_ContextFailedtoTransferItem, RABs_ContextFailedtoTransferItem_sequence);
return offset;
}
static int
dissect_ranap_SecurityModeCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 465 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SecurityModeCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SecurityModeCommand, SecurityModeCommand_sequence);
return offset;
}
static int
dissect_ranap_SecurityModeComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 469 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SecurityModeComplete ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SecurityModeComplete, SecurityModeComplete_sequence);
return offset;
}
static int
dissect_ranap_SecurityModeReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 473 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SecurityModeReject ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SecurityModeReject, SecurityModeReject_sequence);
return offset;
}
static int
dissect_ranap_DataVolumeReportRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 477 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"DataVolumeReportRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DataVolumeReportRequest, DataVolumeReportRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_DataVolumeReportRequestList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_DataVolumeReportRequestItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_DataVolumeReportRequestItem, RAB_DataVolumeReportRequestItem_sequence);
return offset;
}
static int
dissect_ranap_DataVolumeReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 481 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"DataVolumeReport ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DataVolumeReport, DataVolumeReport_sequence);
return offset;
}
static int
dissect_ranap_RAB_FailedtoReportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RABs_failed_to_reportItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RABs_failed_to_reportItem, RABs_failed_to_reportItem_sequence);
return offset;
}
static int
dissect_ranap_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 485 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Reset ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Reset, Reset_sequence);
return offset;
}
static int
dissect_ranap_ResetAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 489 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"ResetAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResetAcknowledge, ResetAcknowledge_sequence);
return offset;
}
static int
dissect_ranap_ResetResource(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 569 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"ResetResource ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResetResource, ResetResource_sequence);
return offset;
}
static int
dissect_ranap_ResetResourceList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_IuSigConId_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_ResetResourceItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResetResourceItem, ResetResourceItem_sequence);
return offset;
}
static int
dissect_ranap_ResetResourceAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 573 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"ResetResourceAcknowledge ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResetResourceAcknowledge, ResetResourceAcknowledge_sequence);
return offset;
}
static int
dissect_ranap_ResetResourceAckList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_IuSigConId_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_ResetResourceAckItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ResetResourceAckItem, ResetResourceAckItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_ReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 493 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RAB-ReleaseRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ReleaseRequest, RAB_ReleaseRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_ReleaseList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ReleaseItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ReleaseItem, RAB_ReleaseItem_sequence);
return offset;
}
static int
dissect_ranap_Iu_ReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 497 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Iu-ReleaseRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Iu_ReleaseRequest, Iu_ReleaseRequest_sequence);
return offset;
}
static int
dissect_ranap_RelocationDetect(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 501 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationDetect ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationDetect, RelocationDetect_sequence);
return offset;
}
static int
dissect_ranap_RelocationComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 505 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RelocationComplete ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RelocationComplete, RelocationComplete_sequence);
return offset;
}
static int
dissect_ranap_EnhancedRelocationCompleteRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 705 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"EnhancedRelocationCompleteRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EnhancedRelocationCompleteRequest, EnhancedRelocationCompleteRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_EnhancedRelocCompleteReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_EnhancedRelocCompleteReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_EnhancedRelocCompleteReq, RAB_SetupItem_EnhancedRelocCompleteReq_sequence);
return offset;
}
static int
dissect_ranap_EnhancedRelocationCompleteResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 709 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"EnhancedRelocationCompleteResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EnhancedRelocationCompleteResponse, EnhancedRelocationCompleteResponse_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_EnhancedRelocCompleteRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ToBeReleasedList_EnhancedRelocCompleteRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_EnhancedRelocCompleteRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_EnhancedRelocCompleteRes, RAB_SetupItem_EnhancedRelocCompleteRes_sequence);
return offset;
}
static int
dissect_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes, RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_sequence);
return offset;
}
static int
dissect_ranap_EnhancedRelocationCompleteFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 713 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"EnhancedRelocationCompleteFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EnhancedRelocationCompleteFailure, EnhancedRelocationCompleteFailure_sequence);
return offset;
}
static int
dissect_ranap_EnhancedRelocationCompleteConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 717 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"EnhancedRelocationCompleteConfirm ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_EnhancedRelocationCompleteConfirm, EnhancedRelocationCompleteConfirm_sequence);
return offset;
}
static int
dissect_ranap_Paging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 509 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Paging ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Paging, Paging_sequence);
return offset;
}
static int
dissect_ranap_CommonID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 513 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"CommonID ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CommonID, CommonID_sequence);
return offset;
}
static int
dissect_ranap_CN_InvokeTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 517 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"CN-InvokeTrace ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CN_InvokeTrace, CN_InvokeTrace_sequence);
return offset;
}
static int
dissect_ranap_CN_DeactivateTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 521 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"CN-DeactivateTrace ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_CN_DeactivateTrace, CN_DeactivateTrace_sequence);
return offset;
}
static int
dissect_ranap_LocationReportingControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 525 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"LocationReportingControl ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationReportingControl, LocationReportingControl_sequence);
return offset;
}
static int
dissect_ranap_LocationReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 529 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"LocationReport ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationReport, LocationReport_sequence);
return offset;
}
static int
dissect_ranap_InitialUE_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 533 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"InitialUE-Message ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InitialUE_Message, InitialUE_Message_sequence);
return offset;
}
static int
dissect_ranap_DirectTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 537 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"DirectTransfer ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DirectTransfer, DirectTransfer_sequence);
return offset;
}
static int
dissect_ranap_RedirectionIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_ProtocolIE_Container(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_Overload(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 541 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"Overload ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Overload, Overload_sequence);
return offset;
}
static int
dissect_ranap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 545 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"ErrorIndication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_ranap_SRNS_DataForwardCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 549 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SRNS-DataForwardCommand ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRNS_DataForwardCommand, SRNS_DataForwardCommand_sequence);
return offset;
}
static int
dissect_ranap_ForwardSRNS_Context(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 553 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"ForwardSRNS-Context ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_ForwardSRNS_Context, ForwardSRNS_Context_sequence);
return offset;
}
static int
dissect_ranap_RAB_AssignmentRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 557 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RAB-AssignmentRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_AssignmentRequest, RAB_AssignmentRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupOrModifyList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerPairList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_TransportLayerInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TransportLayerInformation, TransportLayerInformation_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupOrModifyItemFirst(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupOrModifyItemFirst, RAB_SetupOrModifyItemFirst_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupOrModifyItemSecond(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupOrModifyItemSecond, RAB_SetupOrModifyItemSecond_sequence);
return offset;
}
static int
dissect_ranap_RAB_AssignmentResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 561 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RAB-AssignmentResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_AssignmentResponse, RAB_AssignmentResponse_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupOrModifiedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_SetupOrModifiedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupOrModifiedItem, RAB_SetupOrModifiedItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_ReleasedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ReleasedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ReleasedItem, RAB_ReleasedItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_QueuedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_QueuedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_QueuedItem, RAB_QueuedItem_sequence);
return offset;
}
static int
dissect_ranap_RAB_ReleaseFailedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_FailedList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_GERAN_Iumode_RAB_FailedList_RABAssgntResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item, GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_sequence);
return offset;
}
static int
dissect_ranap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 565 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"PrivateMessage ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_ranap_RANAP_RelocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 577 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RANAP-RelocationInformation ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RANAP_RelocationInformation, RANAP_RelocationInformation_sequence);
return offset;
}
static int
dissect_ranap_DirectTransferInformationList_RANAP_RelocInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_DirectTransfer_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_DirectTransferInformationItem_RANAP_RelocInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DirectTransferInformationItem_RANAP_RelocInf, DirectTransferInformationItem_RANAP_RelocInf_sequence);
return offset;
}
static int
dissect_ranap_RAB_ContextList_RANAP_RelocInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ContextItem_RANAP_RelocInf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ContextItem_RANAP_RelocInf, RAB_ContextItem_RANAP_RelocInf_sequence);
return offset;
}
static int
dissect_ranap_RANAP_EnhancedRelocationInformationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 721 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RANAP-EnhancedRelocationInformationRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RANAP_EnhancedRelocationInformationRequest, RANAP_EnhancedRelocationInformationRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_EnhRelocInfoReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_TNLInformationEnhRelInfoReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TNLInformationEnhRelInfoReq, TNLInformationEnhRelInfoReq_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_EnhRelocInfoReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_EnhRelocInfoReq, RAB_SetupItem_EnhRelocInfoReq_sequence);
return offset;
}
static int
dissect_ranap_RANAP_EnhancedRelocationInformationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 725 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RANAP-EnhancedRelocationInformationResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RANAP_EnhancedRelocationInformationResponse, RANAP_EnhancedRelocationInformationResponse_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupList_EnhRelocInfoRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_TNLInformationEnhRelInfoRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_TNLInformationEnhRelInfoRes, TNLInformationEnhRelInfoRes_sequence);
return offset;
}
static int
dissect_ranap_RAB_SetupItem_EnhRelocInfoRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_SetupItem_EnhRelocInfoRes, RAB_SetupItem_EnhRelocInfoRes_sequence);
return offset;
}
static int
dissect_ranap_RAB_FailedList_EnhRelocInfoRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_FailedItem_EnhRelocInfoRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_FailedItem_EnhRelocInfoRes, RAB_FailedItem_EnhRelocInfoRes_sequence);
return offset;
}
static int
dissect_ranap_RAB_ModifyRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 581 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RAB-ModifyRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ModifyRequest, RAB_ModifyRequest_sequence);
return offset;
}
static int
dissect_ranap_RAB_ModifyList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ranap_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ranap_RAB_ModifyItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RAB_ModifyItem, RAB_ModifyItem_sequence);
return offset;
}
static int
dissect_ranap_LocationRelatedDataRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 585 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"LocationRelatedDataRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationRelatedDataRequest, LocationRelatedDataRequest_sequence);
return offset;
}
static int
dissect_ranap_LocationRelatedDataResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 589 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"LocationRelatedDataResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationRelatedDataResponse, LocationRelatedDataResponse_sequence);
return offset;
}
static int
dissect_ranap_LocationRelatedDataFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 593 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"LocationRelatedDataFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LocationRelatedDataFailure, LocationRelatedDataFailure_sequence);
return offset;
}
static int
dissect_ranap_InformationTransferIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 597 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"InformationTransferIndication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationTransferIndication, InformationTransferIndication_sequence);
return offset;
}
static int
dissect_ranap_InformationTransferConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 601 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"InformationTransferConfirmation ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationTransferConfirmation, InformationTransferConfirmation_sequence);
return offset;
}
static int
dissect_ranap_InformationTransferFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 605 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"InformationTransferFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InformationTransferFailure, InformationTransferFailure_sequence);
return offset;
}
static int
dissect_ranap_UESpecificInformationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 609 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UESpecificInformationIndication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UESpecificInformationIndication, UESpecificInformationIndication_sequence);
return offset;
}
static int
dissect_ranap_DirectInformationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 613 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"DirectInformationTransfer ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_DirectInformationTransfer, DirectInformationTransfer_sequence);
return offset;
}
static int
dissect_ranap_UplinkInformationExchangeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 617 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UplinkInformationExchangeRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UplinkInformationExchangeRequest, UplinkInformationExchangeRequest_sequence);
return offset;
}
static int
dissect_ranap_UplinkInformationExchangeResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 621 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UplinkInformationExchangeResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UplinkInformationExchangeResponse, UplinkInformationExchangeResponse_sequence);
return offset;
}
static int
dissect_ranap_UplinkInformationExchangeFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 625 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UplinkInformationExchangeFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UplinkInformationExchangeFailure, UplinkInformationExchangeFailure_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 629 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionStart ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionStart, MBMSSessionStart_sequence);
return offset;
}
static int
dissect_ranap_MBMSSynchronisationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSynchronisationInformation, MBMSSynchronisationInformation_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionStartResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 633 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionStartResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionStartResponse, MBMSSessionStartResponse_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionStartFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 637 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionStartFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionStartFailure, MBMSSessionStartFailure_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 641 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionUpdate ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionUpdate, MBMSSessionUpdate_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionUpdateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 645 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionUpdateResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionUpdateResponse, MBMSSessionUpdateResponse_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 649 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionUpdateFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionUpdateFailure, MBMSSessionUpdateFailure_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionStop(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 653 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionStop ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionStop, MBMSSessionStop_sequence);
return offset;
}
static int
dissect_ranap_MBMSSessionStopResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 657 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSSessionStopResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSSessionStopResponse, MBMSSessionStopResponse_sequence);
return offset;
}
static int
dissect_ranap_MBMSUELinkingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 661 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSUELinkingRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSUELinkingRequest, MBMSUELinkingRequest_sequence);
return offset;
}
static int
dissect_ranap_LeftMBMSBearerService_IEs_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_LeftMBMSBearerService_IEs_item, LeftMBMSBearerService_IEs_item_sequence);
return offset;
}
static int
dissect_ranap_LeftMBMSBearerService_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_LeftMBMSBearerService_IEs, LeftMBMSBearerService_IEs_sequence_of,
1, maxnoofMulticastServicesPerUE, FALSE);
return offset;
}
static int
dissect_ranap_MBMSUELinkingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 665 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSUELinkingResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSUELinkingResponse, MBMSUELinkingResponse_sequence);
return offset;
}
static int
dissect_ranap_UnsuccessfulLinking_IEs_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UnsuccessfulLinking_IEs_item, UnsuccessfulLinking_IEs_item_sequence);
return offset;
}
static int
dissect_ranap_UnsuccessfulLinking_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_ranap_UnsuccessfulLinking_IEs, UnsuccessfulLinking_IEs_sequence_of,
1, maxnoofMulticastServicesPerUE, FALSE);
return offset;
}
static int
dissect_ranap_MBMSRegistrationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 669 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRegistrationRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRegistrationRequest, MBMSRegistrationRequest_sequence);
return offset;
}
static int
dissect_ranap_MBMSRegistrationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 673 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRegistrationResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRegistrationResponse, MBMSRegistrationResponse_sequence);
return offset;
}
static int
dissect_ranap_MBMSRegistrationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 677 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRegistrationFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRegistrationFailure, MBMSRegistrationFailure_sequence);
return offset;
}
static int
dissect_ranap_MBMSCNDe_RegistrationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 681 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSCNDe-RegistrationRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSCNDe_RegistrationRequest, MBMSCNDe_RegistrationRequest_sequence);
return offset;
}
static int
dissect_ranap_MBMSCNDe_RegistrationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 685 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSCNDe-RegistrationResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSCNDe_RegistrationResponse, MBMSCNDe_RegistrationResponse_sequence);
return offset;
}
static int
dissect_ranap_MBMSRABEstablishmentIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 689 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRABEstablishmentIndication ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRABEstablishmentIndication, MBMSRABEstablishmentIndication_sequence);
return offset;
}
static int
dissect_ranap_MBMSRABReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 693 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRABReleaseRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRABReleaseRequest, MBMSRABReleaseRequest_sequence);
return offset;
}
static int
dissect_ranap_MBMSRABRelease(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 697 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRABRelease ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRABRelease, MBMSRABRelease_sequence);
return offset;
}
static int
dissect_ranap_MBMSRABReleaseFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 701 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"MBMSRABReleaseFailure ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_MBMSRABReleaseFailure, MBMSRABReleaseFailure_sequence);
return offset;
}
static int
dissect_ranap_SRVCC_CSKeysRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 729 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SRVCC-CSKeysRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRVCC_CSKeysRequest, SRVCC_CSKeysRequest_sequence);
return offset;
}
static int
dissect_ranap_SRVCC_CSKeysResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 733 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"SRVCC-CSKeysResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SRVCC_CSKeysResponse, SRVCC_CSKeysResponse_sequence);
return offset;
}
static int
dissect_ranap_UeRadioCapabilityMatchRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 737 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UeRadioCapabilityMatchRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UeRadioCapabilityMatchRequest, UeRadioCapabilityMatchRequest_sequence);
return offset;
}
static int
dissect_ranap_UeRadioCapabilityMatchResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 741 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UeRadioCapabilityMatchResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UeRadioCapabilityMatchResponse, UeRadioCapabilityMatchResponse_sequence);
return offset;
}
static int
dissect_ranap_UeRegistrationQueryRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 745 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UeRegistrationQueryRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UeRegistrationQueryRequest, UeRegistrationQueryRequest_sequence);
return offset;
}
static int
dissect_ranap_UeRegistrationQueryResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 749 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"UeRegistrationQueryResponse ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UeRegistrationQueryResponse, UeRegistrationQueryResponse_sequence);
return offset;
}
static int
dissect_ranap_RerouteNASRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 753 "./asn1/ranap/ranap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,"RerouteNASRequest ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_RerouteNASRequest, RerouteNASRequest_sequence);
return offset;
}
static int
dissect_ranap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_ranap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_ranap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_ranap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_ranap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_ranap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_ranap_T_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_OutcomeValue);
return offset;
}
static int
dissect_ranap_Outcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_ranap_Outcome, Outcome_sequence);
return offset;
}
static int
dissect_ranap_RANAP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_ranap_RANAP_PDU, RANAP_PDU_choice,
NULL);
return offset;
}
static int dissect_AccuracyFulfilmentIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_AccuracyFulfilmentIndicator(tvb, offset, &asn1_ctx, tree, hf_ranap_AccuracyFulfilmentIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Additional_CSPS_coordination_information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Additional_CSPS_coordination_information(tvb, offset, &asn1_ctx, tree, hf_ranap_Additional_CSPS_coordination_information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Additional_PositioningDataSet_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Additional_PositioningDataSet(tvb, offset, &asn1_ctx, tree, hf_ranap_Additional_PositioningDataSet_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Alt_RAB_Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Alt_RAB_Parameters(tvb, offset, &asn1_ctx, tree, hf_ranap_Alt_RAB_Parameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf(tvb, offset, &asn1_ctx, tree, hf_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf(tvb, offset, &asn1_ctx, tree, hf_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Alt_RAB_Parameter_ExtendedMaxBitrateInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf(tvb, offset, &asn1_ctx, tree, hf_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Alt_RAB_Parameter_SupportedMaxBitrateInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf(tvb, offset, &asn1_ctx, tree, hf_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AlternativeRABConfigurationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_AlternativeRABConfigurationRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_AlternativeRABConfigurationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Application_Layer_Measurement_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_Application_Layer_Measurement_Configuration(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_Application_Layer_Measurement_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Application_Layer_Measurement_Configuration_For_Relocation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_APN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_APN(tvb, offset, &asn1_ctx, tree, hf_ranap_APN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AreaIdentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_AreaIdentity(tvb, offset, &asn1_ctx, tree, hf_ranap_AreaIdentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Ass_RAB_Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Ass_RAB_Parameters(tvb, offset, &asn1_ctx, tree, hf_ranap_Ass_RAB_Parameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Ass_RAB_Parameter_ExtendedMaxBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BarometricPressure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_BarometricPressure(tvb, offset, &asn1_ctx, tree, hf_ranap_BarometricPressure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BroadcastAssistanceDataDecipheringKeys_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_BroadcastAssistanceDataDecipheringKeys(tvb, offset, &asn1_ctx, tree, hf_ranap_BroadcastAssistanceDataDecipheringKeys_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Cause(tvb, offset, &asn1_ctx, tree, hf_ranap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cell_Access_Mode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Cell_Access_Mode(tvb, offset, &asn1_ctx, tree, hf_ranap_Cell_Access_Mode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellLoadInformationGroup_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CellLoadInformationGroup(tvb, offset, &asn1_ctx, tree, hf_ranap_CellLoadInformationGroup_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CivicAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CivicAddress(tvb, offset, &asn1_ctx, tree, hf_ranap_CivicAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ClientType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ClientType(tvb, offset, &asn1_ctx, tree, hf_ranap_ClientType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_ranap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MessageStructure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MessageStructure(tvb, offset, &asn1_ctx, tree, hf_ranap_MessageStructure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ChosenEncryptionAlgorithm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ChosenEncryptionAlgorithm(tvb, offset, &asn1_ctx, tree, hf_ranap_ChosenEncryptionAlgorithm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ChosenIntegrityProtectionAlgorithm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ChosenIntegrityProtectionAlgorithm(tvb, offset, &asn1_ctx, tree, hf_ranap_ChosenIntegrityProtectionAlgorithm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ClassmarkInformation2_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ClassmarkInformation2(tvb, offset, &asn1_ctx, tree, hf_ranap_ClassmarkInformation2_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ClassmarkInformation3_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ClassmarkInformation3(tvb, offset, &asn1_ctx, tree, hf_ranap_ClassmarkInformation3_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CN_DomainIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CN_DomainIndicator(tvb, offset, &asn1_ctx, tree, hf_ranap_CN_DomainIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Correlation_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_Correlation_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSFB_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CSFB_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_CSFB_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_ranap_CSG_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CSG_Id_List(tvb, offset, &asn1_ctx, tree, hf_ranap_CSG_Id_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Membership_Status_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CSG_Membership_Status(tvb, offset, &asn1_ctx, tree, hf_ranap_CSG_Membership_Status_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DCN_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DCN_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_DCN_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DeltaRAListofIdleModeUEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DeltaRAListofIdleModeUEs(tvb, offset, &asn1_ctx, tree, hf_ranap_DeltaRAListofIdleModeUEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DRX_CycleLengthCoefficient_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DRX_CycleLengthCoefficient(tvb, offset, &asn1_ctx, tree, hf_ranap_DRX_CycleLengthCoefficient_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EARFCN_Extended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EARFCN_Extended(tvb, offset, &asn1_ctx, tree, hf_ranap_EARFCN_Extended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_DCH_MAC_d_Flow_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_E_DCH_MAC_d_Flow_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_E_DCH_MAC_d_Flow_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EncryptionInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EncryptionInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_EncryptionInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EncryptionKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EncryptionKey(tvb, offset, &asn1_ctx, tree, hf_ranap_EncryptionKey_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_End_Of_CSFB_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_End_Of_CSFB(tvb, offset, &asn1_ctx, tree, hf_ranap_End_Of_CSFB_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_UTRAN_Service_Handover_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_E_UTRAN_Service_Handover(tvb, offset, &asn1_ctx, tree, hf_ranap_E_UTRAN_Service_Handover_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExtendedRNC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ExtendedRNC_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_ExtendedRNC_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_FrequenceLayerConvergenceFlag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_FrequenceLayerConvergenceFlag(tvb, offset, &asn1_ctx, tree, hf_ranap_FrequenceLayerConvergenceFlag_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GANSS_PositioningDataSet_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GANSS_PositioningDataSet(tvb, offset, &asn1_ctx, tree, hf_ranap_GANSS_PositioningDataSet_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GERAN_BSC_Container_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GERAN_BSC_Container(tvb, offset, &asn1_ctx, tree, hf_ranap_GERAN_BSC_Container_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GERAN_Classmark_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GERAN_Classmark(tvb, offset, &asn1_ctx, tree, hf_ranap_GERAN_Classmark_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalCN_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GlobalCN_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_GlobalCN_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalRNC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GlobalRNC_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_GlobalRNC_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HigherBitratesThan16MbpsFlag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_HigherBitratesThan16MbpsFlag(tvb, offset, &asn1_ctx, tree, hf_ranap_HigherBitratesThan16MbpsFlag_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HS_DSCH_MAC_d_Flow_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_HS_DSCH_MAC_d_Flow_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_HS_DSCH_MAC_d_Flow_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IMSI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IMSI(tvb, offset, &asn1_ctx, tree, hf_ranap_IMSI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IncludeVelocity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IncludeVelocity(tvb, offset, &asn1_ctx, tree, hf_ranap_IncludeVelocity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationExchangeID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationExchangeID(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationExchangeID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationExchangeType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationExchangeType(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationExchangeType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationRequested_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationRequested(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationRequested_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationRequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationRequestType(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationRequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationTransferID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationTransferID(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationTransferID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationTransferType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationTransferType(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationTransferType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IntegrityProtectionInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IntegrityProtectionInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_IntegrityProtectionInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IntegrityProtectionKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IntegrityProtectionKey(tvb, offset, &asn1_ctx, tree, hf_ranap_IntegrityProtectionKey_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InterSystemInformationTransferType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InterSystemInformationTransferType(tvb, offset, &asn1_ctx, tree, hf_ranap_InterSystemInformationTransferType_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_InterSystemInformation_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InterSystemInformation_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_InterSystemInformation_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IPMulticastAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IPMulticastAddress(tvb, offset, &asn1_ctx, tree, hf_ranap_IPMulticastAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IuSignallingConnectionIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IuSignallingConnectionIdentifier(tvb, offset, &asn1_ctx, tree, hf_ranap_IuSignallingConnectionIdentifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IuTransportAssociation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IuTransportAssociation(tvb, offset, &asn1_ctx, tree, hf_ranap_IuTransportAssociation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KeyStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_KeyStatus(tvb, offset, &asn1_ctx, tree, hf_ranap_KeyStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LAI(tvb, offset, &asn1_ctx, tree, hf_ranap_LAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LastKnownServiceArea_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LastKnownServiceArea(tvb, offset, &asn1_ctx, tree, hf_ranap_LastKnownServiceArea_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_LastVisitedUTRANCell_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LastVisitedUTRANCell_Item(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_LastVisitedUTRANCell_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LHN_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LHN_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_LHN_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationRelatedDataRequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationRelatedDataRequestType(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationRelatedDataRequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationRelatedDataRequestTypeSpecificToGERANIuMode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationRelatedDataRequestTypeSpecificToGERANIuMode(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationRelatedDataRequestTypeSpecificToGERANIuMode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_L3_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_L3_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_L3_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M4Report_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_M4Report(tvb, offset, &asn1_ctx, tree, hf_ranap_M4Report_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M5Report_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_M5Report(tvb, offset, &asn1_ctx, tree, hf_ranap_M5Report_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M6Report_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_M6Report(tvb, offset, &asn1_ctx, tree, hf_ranap_M6Report_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M7Report_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_M7Report(tvb, offset, &asn1_ctx, tree, hf_ranap_M7Report_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Management_Based_MDT_Allowed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Management_Based_MDT_Allowed(tvb, offset, &asn1_ctx, tree, hf_ranap_Management_Based_MDT_Allowed_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSBearerServiceType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSBearerServiceType(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSBearerServiceType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSCNDe_Registration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSCNDe_Registration(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSCNDe_Registration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSCountingInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSCountingInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSCountingInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSLinkingInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSLinkingInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSLinkingInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRegistrationRequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRegistrationRequestType(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRegistrationRequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSServiceArea_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSServiceArea(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSServiceArea_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionDuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionDuration(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionDuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionIdentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionIdentity(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionIdentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionRepetitionNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionRepetitionNumber(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionRepetitionNumber_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_ranap_MDT_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_PLMN_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MDT_PLMN_List(tvb, offset, &asn1_ctx, tree, hf_ranap_MDT_PLMN_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MSISDN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MSISDN(tvb, offset, &asn1_ctx, tree, hf_ranap_MSISDN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NAS_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_NAS_PDU(tvb, offset, &asn1_ctx, tree, hf_ranap_NAS_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NAS_SequenceNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_NAS_SequenceNumber(tvb, offset, &asn1_ctx, tree, hf_ranap_NAS_SequenceNumber_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NewBSS_To_OldBSS_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_NewBSS_To_OldBSS_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_NewBSS_To_OldBSS_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NonSearchingIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_NonSearchingIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_NonSearchingIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NumberOfSteps_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_NumberOfSteps(tvb, offset, &asn1_ctx, tree, hf_ranap_NumberOfSteps_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Offload_RAB_Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Offload_RAB_Parameters(tvb, offset, &asn1_ctx, tree, hf_ranap_Offload_RAB_Parameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OldBSS_ToNewBSS_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_OldBSS_ToNewBSS_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_OldBSS_ToNewBSS_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OMC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_OMC_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_OMC_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Out_Of_UTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Out_Of_UTRAN(tvb, offset, &asn1_ctx, tree, hf_ranap_Out_Of_UTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingAreaID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PagingAreaID(tvb, offset, &asn1_ctx, tree, hf_ranap_PagingAreaID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingCause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PagingCause(tvb, offset, &asn1_ctx, tree, hf_ranap_PagingCause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PDP_TypeInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PDP_TypeInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_PDP_TypeInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PDP_TypeInformation_extension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PDP_TypeInformation_extension(tvb, offset, &asn1_ctx, tree, hf_ranap_PDP_TypeInformation_extension_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PeriodicLocationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PeriodicLocationInfo(tvb, offset, &asn1_ctx, tree, hf_ranap_PeriodicLocationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PermanentNAS_UE_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PermanentNAS_UE_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_PermanentNAS_UE_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PLMNidentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PLMNidentity(tvb, offset, &asn1_ctx, tree, hf_ranap_PLMNidentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PositioningPriority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PositioningPriority(tvb, offset, &asn1_ctx, tree, hf_ranap_PositioningPriority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PositionData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PositionData(tvb, offset, &asn1_ctx, tree, hf_ranap_PositionData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PositionDataSpecificToGERANIuMode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PositionDataSpecificToGERANIuMode(tvb, offset, &asn1_ctx, tree, hf_ranap_PositionDataSpecificToGERANIuMode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Priority_Class_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Priority_Class_Indicator(tvb, offset, &asn1_ctx, tree, hf_ranap_Priority_Class_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProvidedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ProvidedData(tvb, offset, &asn1_ctx, tree, hf_ranap_ProvidedData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PowerSavingIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PowerSavingIndicator(tvb, offset, &asn1_ctx, tree, hf_ranap_PowerSavingIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_P_TMSI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_P_TMSI(tvb, offset, &asn1_ctx, tree, hf_ranap_P_TMSI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_Parameter_ExtendedMaxBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_Parameter_ExtendedMaxBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_Parameter_ExtendedMaxBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_Parameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_Parameters(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_Parameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RABParametersList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RABParametersList(tvb, offset, &asn1_ctx, tree, hf_ranap_RABParametersList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAC(tvb, offset, &asn1_ctx, tree, hf_ranap_RAC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAListofIdleModeUEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAListofIdleModeUEs(tvb, offset, &asn1_ctx, tree, hf_ranap_RAListofIdleModeUEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LAListofIdleModeUEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LAListofIdleModeUEs(tvb, offset, &asn1_ctx, tree, hf_ranap_LAListofIdleModeUEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAT_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAT_Type(tvb, offset, &asn1_ctx, tree, hf_ranap_RAT_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RedirectAttemptFlag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RedirectAttemptFlag(tvb, offset, &asn1_ctx, tree, hf_ranap_RedirectAttemptFlag_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RedirectionCompleted_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RedirectionCompleted(tvb, offset, &asn1_ctx, tree, hf_ranap_RedirectionCompleted_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RejectCauseValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RejectCauseValue(tvb, offset, &asn1_ctx, tree, hf_ranap_RejectCauseValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationType(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RequestedGANSSAssistanceData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RequestedGANSSAssistanceData(tvb, offset, &asn1_ctx, tree, hf_ranap_RequestedGANSSAssistanceData_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Requested_RAB_Parameter_ExtendedMaxBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RequestType(tvb, offset, &asn1_ctx, tree, hf_ranap_RequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResponseTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResponseTime(tvb, offset, &asn1_ctx, tree, hf_ranap_ResponseTime_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RNSAPRelocationParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RNSAPRelocationParameters(tvb, offset, &asn1_ctx, tree, hf_ranap_RNSAPRelocationParameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRC_Container_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RRC_Container(tvb, offset, &asn1_ctx, tree, hf_ranap_RRC_Container_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRVCC_HO_Indication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RSRVCC_HO_Indication(tvb, offset, &asn1_ctx, tree, hf_ranap_RSRVCC_HO_Indication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRVCC_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RSRVCC_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_RSRVCC_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRVCC_Operation_Possible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RSRVCC_Operation_Possible(tvb, offset, &asn1_ctx, tree, hf_ranap_RSRVCC_Operation_Possible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SAI(tvb, offset, &asn1_ctx, tree, hf_ranap_SAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SAPI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SAPI(tvb, offset, &asn1_ctx, tree, hf_ranap_SAPI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SessionUpdateID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SessionUpdateID(tvb, offset, &asn1_ctx, tree, hf_ranap_SessionUpdateID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Session_Re_establishment_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Session_Re_establishment_Indicator(tvb, offset, &asn1_ctx, tree, hf_ranap_Session_Re_establishment_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SignallingIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SignallingIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_SignallingIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SGSN_Group_Identity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SGSN_Group_Identity(tvb, offset, &asn1_ctx, tree, hf_ranap_SGSN_Group_Identity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SNA_Access_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SNA_Access_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_SNA_Access_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_Source_ToTarget_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Source_ToTarget_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_Source_ToTarget_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_SourceCellID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SourceCellID(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_SourceCellID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SourceBSS_ToTargetBSS_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SourceBSS_ToTargetBSS_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_SourceBSS_ToTargetBSS_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SourceID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SourceID(tvb, offset, &asn1_ctx, tree, hf_ranap_SourceID_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IRAT_Measurement_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_IRAT_Measurement_Configuration(tvb, offset, &asn1_ctx, tree, hf_ranap_IRAT_Measurement_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRQ_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RSRQ_Type(tvb, offset, &asn1_ctx, tree, hf_ranap_RSRQ_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRQ_Extension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RSRQ_Extension(tvb, offset, &asn1_ctx, tree, hf_ranap_RSRQ_Extension_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SubscriberProfileIDforRFP_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SubscriberProfileIDforRFP(tvb, offset, &asn1_ctx, tree, hf_ranap_SubscriberProfileIDforRFP_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SupportedRAB_ParameterBitrateList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SupportedRAB_ParameterBitrateList(tvb, offset, &asn1_ctx, tree, hf_ranap_SupportedRAB_ParameterBitrateList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRB_TrCH_Mapping_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRB_TrCH_Mapping(tvb, offset, &asn1_ctx, tree, hf_ranap_SRB_TrCH_Mapping_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCC_HO_Indication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRVCC_HO_Indication(tvb, offset, &asn1_ctx, tree, hf_ranap_SRVCC_HO_Indication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCC_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRVCC_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_SRVCC_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCC_Operation_Possible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRVCC_Operation_Possible(tvb, offset, &asn1_ctx, tree, hf_ranap_SRVCC_Operation_Possible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Target_ToSource_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Target_ToSource_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_Target_ToSource_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargetBSS_ToSourceBSS_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TargetBSS_ToSourceBSS_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_TargetBSS_ToSourceBSS_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargetID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TargetID(tvb, offset, &asn1_ctx, tree, hf_ranap_TargetID_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_TargetRNC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TargetRNC_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_TargetRNC_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_ranap_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TemporaryUE_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TemporaryUE_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_TemporaryUE_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Time_UE_StayedInCell_EnhancedGranularity(tvb, offset, &asn1_ctx, tree, hf_ranap_Time_UE_StayedInCell_EnhancedGranularity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToMBMSDataTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TimeToMBMSDataTransfer(tvb, offset, &asn1_ctx, tree, hf_ranap_TimeToMBMSDataTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimingDifferenceULDL_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TimingDifferenceULDL(tvb, offset, &asn1_ctx, tree, hf_ranap_TimingDifferenceULDL_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TMGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TMGI(tvb, offset, &asn1_ctx, tree, hf_ranap_TMGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TracePropagationParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TracePropagationParameters(tvb, offset, &asn1_ctx, tree, hf_ranap_TracePropagationParameters_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceRecordingSessionInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TraceRecordingSessionInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_TraceRecordingSessionInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceRecordingSessionReference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TraceRecordingSessionReference(tvb, offset, &asn1_ctx, tree, hf_ranap_TraceRecordingSessionReference_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceReference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TraceReference(tvb, offset, &asn1_ctx, tree, hf_ranap_TraceReference_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TraceType(tvb, offset, &asn1_ctx, tree, hf_ranap_TraceType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportLayerAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TransportLayerAddress(tvb, offset, &asn1_ctx, tree, hf_ranap_TransportLayerAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TriggerID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TriggerID(tvb, offset, &asn1_ctx, tree, hf_ranap_TriggerID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TunnelInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TunnelInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_TunnelInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TypeOfError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TypeOfError(tvb, offset, &asn1_ctx, tree, hf_ranap_TypeOfError_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_AggregateMaximumBitRate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_AggregateMaximumBitRate(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_AggregateMaximumBitRate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_History_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_History_Information(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_History_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_ID(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Usage_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UE_Usage_Type(tvb, offset, &asn1_ctx, tree, hf_ranap_UE_Usage_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERegistrationQueryResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UERegistrationQueryResult(tvb, offset, &asn1_ctx, tree, hf_ranap_UERegistrationQueryResult_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UESBI_Iu_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UESBI_Iu(tvb, offset, &asn1_ctx, tree, hf_ranap_UESBI_Iu_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UTRAN_CellID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UTRAN_CellID(tvb, offset, &asn1_ctx, tree, hf_ranap_UTRAN_CellID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_VelocityEstimate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_VelocityEstimate(tvb, offset, &asn1_ctx, tree, hf_ranap_VelocityEstimate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_VerticalAccuracyCode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_VerticalAccuracyCode(tvb, offset, &asn1_ctx, tree, hf_ranap_VerticalAccuracyCode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_VoiceSupportMatchIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_VoiceSupportMatchIndicator(tvb, offset, &asn1_ctx, tree, hf_ranap_VoiceSupportMatchIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Iu_ReleaseCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Iu_ReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_ranap_Iu_ReleaseCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Iu_ReleaseComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Iu_ReleaseComplete(tvb, offset, &asn1_ctx, tree, hf_ranap_Iu_ReleaseComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataVolumeReportList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataVolumeReportList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataVolumeReportList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataVolumeReportItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataVolumeReportItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataVolumeReportItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleasedList_IuRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleasedList_IuRelComp(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleasedList_IuRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleasedItem_IuRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleasedItem_IuRelComp(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleasedItem_IuRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationRequired_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationRequired(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationRequired_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationCommand(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_RelocationReleaseList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_RelocationReleaseList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_RelocationReleaseList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_RelocationReleaseItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_RelocationReleaseItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_RelocationReleaseItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataForwardingList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataForwardingList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataForwardingList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataForwardingItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataForwardingItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataForwardingItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationPreparationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationPreparationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_RelocReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_RelocReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_RelocReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_RelocReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_RelocReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_RelocReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CNMBMSLinkingInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CNMBMSLinkingInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_CNMBMSLinkingInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_JoinedMBMSBearerService_IEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_JoinedMBMSBearerService_IEs(tvb, offset, &asn1_ctx, tree, hf_ranap_JoinedMBMSBearerService_IEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_RelocReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_RelocReqAck(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_RelocReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_RelocReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_RelocReqAck(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_RelocReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_FailedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_FailedList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_FailedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_FailedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_FailedItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_FailedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationCancel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationCancel(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationCancel_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationCancelAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationCancelAcknowledge(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationCancelAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRNS_ContextRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRNS_ContextRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_SRNS_ContextRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataForwardingList_SRNS_CtxReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataForwardingList_SRNS_CtxReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataForwardingList_SRNS_CtxReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataForwardingItem_SRNS_CtxReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataForwardingItem_SRNS_CtxReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataForwardingItem_SRNS_CtxReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRNS_ContextResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRNS_ContextResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_SRNS_ContextResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ContextList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ContextList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ContextList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ContextItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ContextItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ContextItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ContextFailedtoTransferList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ContextFailedtoTransferList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ContextFailedtoTransferList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RABs_ContextFailedtoTransferItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RABs_ContextFailedtoTransferItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RABs_ContextFailedtoTransferItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityModeCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SecurityModeCommand(tvb, offset, &asn1_ctx, tree, hf_ranap_SecurityModeCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityModeComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SecurityModeComplete(tvb, offset, &asn1_ctx, tree, hf_ranap_SecurityModeComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityModeReject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SecurityModeReject(tvb, offset, &asn1_ctx, tree, hf_ranap_SecurityModeReject_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DataVolumeReportRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DataVolumeReportRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_DataVolumeReportRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataVolumeReportRequestList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataVolumeReportRequestList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataVolumeReportRequestList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_DataVolumeReportRequestItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_DataVolumeReportRequestItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_DataVolumeReportRequestItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DataVolumeReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DataVolumeReport(tvb, offset, &asn1_ctx, tree, hf_ranap_DataVolumeReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_FailedtoReportList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_FailedtoReportList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_FailedtoReportList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RABs_failed_to_reportItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RABs_failed_to_reportItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RABs_failed_to_reportItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Reset(tvb, offset, &asn1_ctx, tree, hf_ranap_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResource_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResource(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResource_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResourceList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResourceList(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResourceList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResourceItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResourceItem(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResourceItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResourceAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResourceAcknowledge(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResourceAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResourceAckList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResourceAckList(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResourceAckList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResourceAckItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ResetResourceAckItem(tvb, offset, &asn1_ctx, tree, hf_ranap_ResetResourceAckItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleaseList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleaseList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleaseList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleaseItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleaseItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleaseItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Iu_ReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Iu_ReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_Iu_ReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationDetect_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationDetect(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationDetect_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RelocationComplete(tvb, offset, &asn1_ctx, tree, hf_ranap_RelocationComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EnhancedRelocationCompleteRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EnhancedRelocationCompleteRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_EnhancedRelocationCompleteRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_EnhancedRelocCompleteReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_EnhancedRelocCompleteReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_EnhancedRelocCompleteReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_EnhancedRelocCompleteReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_EnhancedRelocCompleteReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_EnhancedRelocCompleteReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EnhancedRelocationCompleteResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EnhancedRelocationCompleteResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_EnhancedRelocationCompleteResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_EnhancedRelocCompleteRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_EnhancedRelocCompleteRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_EnhancedRelocCompleteRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_EnhancedRelocCompleteRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_EnhancedRelocCompleteRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_EnhancedRelocCompleteRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ToBeReleasedList_EnhancedRelocCompleteRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ToBeReleasedList_EnhancedRelocCompleteRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ToBeReleasedList_EnhancedRelocCompleteRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EnhancedRelocationCompleteFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EnhancedRelocationCompleteFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_EnhancedRelocationCompleteFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EnhancedRelocationCompleteConfirm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_EnhancedRelocationCompleteConfirm(tvb, offset, &asn1_ctx, tree, hf_ranap_EnhancedRelocationCompleteConfirm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Paging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Paging(tvb, offset, &asn1_ctx, tree, hf_ranap_Paging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CommonID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CommonID(tvb, offset, &asn1_ctx, tree, hf_ranap_CommonID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CN_InvokeTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CN_InvokeTrace(tvb, offset, &asn1_ctx, tree, hf_ranap_CN_InvokeTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CN_DeactivateTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_CN_DeactivateTrace(tvb, offset, &asn1_ctx, tree, hf_ranap_CN_DeactivateTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReportingControl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationReportingControl(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationReportingControl_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationReport(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialUE_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InitialUE_Message(tvb, offset, &asn1_ctx, tree, hf_ranap_InitialUE_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DirectTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DirectTransfer(tvb, offset, &asn1_ctx, tree, hf_ranap_DirectTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RedirectionIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RedirectionIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_RedirectionIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Overload_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_Overload(tvb, offset, &asn1_ctx, tree, hf_ranap_Overload_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRNS_DataForwardCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRNS_DataForwardCommand(tvb, offset, &asn1_ctx, tree, hf_ranap_SRNS_DataForwardCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ForwardSRNS_Context_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_ForwardSRNS_Context(tvb, offset, &asn1_ctx, tree, hf_ranap_ForwardSRNS_Context_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_AssignmentRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_AssignmentRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_AssignmentRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupOrModifyList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupOrModifyList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupOrModifyList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupOrModifyItemFirst_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupOrModifyItemFirst(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupOrModifyItemFirst_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportLayerInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_TransportLayerInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_TransportLayerInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupOrModifyItemSecond_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupOrModifyItemSecond(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupOrModifyItemSecond_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_AssignmentResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_AssignmentResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_AssignmentResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupOrModifiedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupOrModifiedList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupOrModifiedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupOrModifiedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupOrModifiedItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupOrModifiedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleasedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleasedList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleasedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleasedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleasedItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleasedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_QueuedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_QueuedList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_QueuedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_QueuedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_QueuedItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_QueuedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ReleaseFailedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ReleaseFailedList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ReleaseFailedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GERAN_Iumode_RAB_FailedList_RABAssgntResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GERAN_Iumode_RAB_FailedList_RABAssgntResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_GERAN_Iumode_RAB_FailedList_RABAssgntResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item(tvb, offset, &asn1_ctx, tree, hf_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_ranap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RANAP_RelocationInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RANAP_RelocationInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_RANAP_RelocationInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DirectTransferInformationList_RANAP_RelocInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DirectTransferInformationList_RANAP_RelocInf(tvb, offset, &asn1_ctx, tree, hf_ranap_DirectTransferInformationList_RANAP_RelocInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DirectTransferInformationItem_RANAP_RelocInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DirectTransferInformationItem_RANAP_RelocInf(tvb, offset, &asn1_ctx, tree, hf_ranap_DirectTransferInformationItem_RANAP_RelocInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ContextList_RANAP_RelocInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ContextList_RANAP_RelocInf(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ContextList_RANAP_RelocInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ContextItem_RANAP_RelocInf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ContextItem_RANAP_RelocInf(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ContextItem_RANAP_RelocInf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RANAP_EnhancedRelocationInformationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RANAP_EnhancedRelocationInformationRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RANAP_EnhancedRelocationInformationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_EnhRelocInfoReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_EnhRelocInfoReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_EnhRelocInfoReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_EnhRelocInfoReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_EnhRelocInfoReq(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_EnhRelocInfoReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RANAP_EnhancedRelocationInformationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RANAP_EnhancedRelocationInformationResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_RANAP_EnhancedRelocationInformationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupList_EnhRelocInfoRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupList_EnhRelocInfoRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupList_EnhRelocInfoRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_SetupItem_EnhRelocInfoRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_SetupItem_EnhRelocInfoRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_SetupItem_EnhRelocInfoRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_FailedList_EnhRelocInfoRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_FailedList_EnhRelocInfoRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_FailedList_EnhRelocInfoRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_FailedItem_EnhRelocInfoRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_FailedItem_EnhRelocInfoRes(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_FailedItem_EnhRelocInfoRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ModifyRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ModifyRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ModifyRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ModifyList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ModifyList(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ModifyList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAB_ModifyItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RAB_ModifyItem(tvb, offset, &asn1_ctx, tree, hf_ranap_RAB_ModifyItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationRelatedDataRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationRelatedDataRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationRelatedDataRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationRelatedDataResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationRelatedDataResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationRelatedDataResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationRelatedDataFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LocationRelatedDataFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_LocationRelatedDataFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationTransferIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationTransferIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationTransferIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationTransferConfirmation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationTransferConfirmation(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationTransferConfirmation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationTransferFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_InformationTransferFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_InformationTransferFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UESpecificInformationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UESpecificInformationIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_UESpecificInformationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DirectInformationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_DirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_ranap_DirectInformationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkInformationExchangeRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UplinkInformationExchangeRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_UplinkInformationExchangeRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkInformationExchangeResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UplinkInformationExchangeResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_UplinkInformationExchangeResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkInformationExchangeFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UplinkInformationExchangeFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_UplinkInformationExchangeFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionStart(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionStart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSynchronisationInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSynchronisationInformation(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSynchronisationInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStartResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionStartResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionStartResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStartFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionStartFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionStartFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionUpdate(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdateResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionUpdateResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionUpdateResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStop_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionStop(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionStop_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSSessionStopResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSSessionStopResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSSessionStopResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSUELinkingRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSUELinkingRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSUELinkingRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LeftMBMSBearerService_IEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_LeftMBMSBearerService_IEs(tvb, offset, &asn1_ctx, tree, hf_ranap_LeftMBMSBearerService_IEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSUELinkingResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSUELinkingResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSUELinkingResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UnsuccessfulLinking_IEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UnsuccessfulLinking_IEs(tvb, offset, &asn1_ctx, tree, hf_ranap_UnsuccessfulLinking_IEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRegistrationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRegistrationRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRegistrationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRegistrationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRegistrationResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRegistrationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRegistrationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRegistrationFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRegistrationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSCNDe_RegistrationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSCNDe_RegistrationRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSCNDe_RegistrationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSCNDe_RegistrationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSCNDe_RegistrationResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSCNDe_RegistrationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRABEstablishmentIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRABEstablishmentIndication(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRABEstablishmentIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRABReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRABReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRABReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRABRelease_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRABRelease(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRABRelease_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMSRABReleaseFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_MBMSRABReleaseFailure(tvb, offset, &asn1_ctx, tree, hf_ranap_MBMSRABReleaseFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCC_CSKeysRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRVCC_CSKeysRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_SRVCC_CSKeysRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCC_CSKeysResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_SRVCC_CSKeysResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_SRVCC_CSKeysResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UeRadioCapabilityMatchRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UeRadioCapabilityMatchRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_UeRadioCapabilityMatchRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UeRadioCapabilityMatchResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UeRadioCapabilityMatchResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_UeRadioCapabilityMatchResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UeRegistrationQueryRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UeRegistrationQueryRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_UeRegistrationQueryRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UeRegistrationQueryResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_UeRegistrationQueryResponse(tvb, offset, &asn1_ctx, tree, hf_ranap_UeRegistrationQueryResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RerouteNASRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RerouteNASRequest(tvb, offset, &asn1_ctx, tree, hf_ranap_RerouteNASRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RANAP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_ranap_RANAP_PDU(tvb, offset, &asn1_ctx, tree, hf_ranap_RANAP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int ret = 0;
int key;
switch(ProcedureCode){
case id_RelocationPreparation:
if((ProtocolIE_ID == id_Source_ToTarget_TransparentContainer)||(ProtocolIE_ID == id_Target_ToSource_TransparentContainer)){
key = SPECIAL | ProtocolIE_ID;
ret = (dissector_try_uint_new(ranap_ies_dissector_table, key, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
break;
}
default:
ret = (dissector_try_uint_new(ranap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
if (ret == 0) {
key = pdu_type | ProtocolIE_ID;
ret = (dissector_try_uint_new(ranap_ies_dissector_table, key, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
break;
}
return ret;
}
static int
dissect_ProtocolIEFieldPairFirstValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_ies_p1_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolIEFieldPairSecondValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_ies_p2_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean ret;
pdu_type = IMSG;
ret = dissector_try_uint_new(ranap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL);
pdu_type = 0;
return ret ? tvb_captured_length(tvb) : 0;
}
static int
dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean ret;
pdu_type = SOUT;
ret = dissector_try_uint_new(ranap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL);
pdu_type = 0;
return ret ? tvb_captured_length(tvb) : 0;
}
static int
dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_OutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_proc_out_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ranap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ranap_item = NULL;
proto_tree *ranap_tree = NULL;
sccp_msg_info_t *sccp_msg_lcl = (sccp_msg_info_t *)data;
pdu_type = 0;
ProtocolIE_ID = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RANAP");
ranap_item = proto_tree_add_item(tree, proto_ranap, tvb, 0, -1, ENC_NA);
ranap_tree = proto_item_add_subtree(ranap_item, ett_ranap);
p_add_proto_data(pinfo->pool, pinfo, proto_ranap, pinfo->curr_layer_num, data);
dissect_RANAP_PDU_PDU(tvb, pinfo, ranap_tree, NULL);
if (sccp_msg_lcl) {
if (sccp_msg_lcl->data.co.assoc)
sccp_msg_lcl->data.co.assoc->payload = SCCP_PLOAD_RANAP;
if (! sccp_msg_lcl->data.co.label && ProcedureCode != 0xFFFFFFFF) {
const gchar* str = val_to_str(ProcedureCode, ranap_ProcedureCode_vals,"Unknown RANAP");
sccp_msg_lcl->data.co.label = wmem_strdup(wmem_file_scope(), str);
}
}
return tvb_reported_length(tvb);
}
static gboolean
dissect_sccp_ranap_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint8 temp;
guint16 word;
guint length;
int offset;
#define LENGTH_OFFSET 3
#define CRIT_OFFSET 2
#define MSG_TYPE_OFFSET 1
if (tvb_captured_length(tvb) < RANAP_MSG_MIN_LENGTH) { return FALSE; }
temp = tvb_get_guint8(tvb, 0) & 0x7f;
if (temp != 0x00 && temp != 0x20 &&temp != 0x40 && temp != 0x60) {
return FALSE;
}
temp = tvb_get_guint8(tvb, CRIT_OFFSET);
if (temp != 0x00 && temp != 0x40 && temp != 0x80) {
return FALSE;
}
offset = LENGTH_OFFSET;
length = tvb_get_guint8(tvb, offset);
offset += 1;
if ((length & 0x80) == 0x80) {
if ((length & 0xc0) == 0x80) {
length &= 0x3f;
length <<= 8;
length += tvb_get_guint8(tvb, offset);
offset += 1;
} else {
length = 0;
}
}
if (length!= (tvb_reported_length(tvb) - offset)){
return FALSE;
}
temp = tvb_get_guint8(tvb, MSG_TYPE_OFFSET);
if (temp > RANAP_MAX_PC) { return FALSE; }
word = tvb_get_ntohs(tvb, offset + 1);
if (word > 0x1ff){
return FALSE;
}
dissect_ranap(tvb, pinfo, tree, data);
return TRUE;
}
void proto_register_ranap(void) {
module_t *ranap_module;
static hf_register_info hf[] = {
{ &hf_ranap_transportLayerAddress_ipv4,
{ "transportLayerAddress IPv4", "ranap.transportLayerAddress_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddress_ipv6,
{ "transportLayerAddress IPv6", "ranap.transportLayerAddress_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddress_nsap,
{ "transportLayerAddress NSAP", "ranap.transportLayerAddress_NSAP",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "./asn1/ranap/packet-ranap-hfarr.c"
{ &hf_ranap_AccuracyFulfilmentIndicator_PDU,
{ "AccuracyFulfilmentIndicator", "ranap.AccuracyFulfilmentIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_AccuracyFulfilmentIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Additional_CSPS_coordination_information_PDU,
{ "Additional-CSPS-coordination-information", "ranap.Additional_CSPS_coordination_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Additional_PositioningDataSet_PDU,
{ "Additional-PositioningDataSet", "ranap.Additional_PositioningDataSet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameters_PDU,
{ "Alt-RAB-Parameters", "ranap.Alt_RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_PDU,
{ "Alt-RAB-Parameter-ExtendedGuaranteedBitrateInf", "ranap.Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_PDU,
{ "Alt-RAB-Parameter-SupportedGuaranteedBitrateInf", "ranap.Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf_PDU,
{ "Alt-RAB-Parameter-ExtendedMaxBitrateInf", "ranap.Alt_RAB_Parameter_ExtendedMaxBitrateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf_PDU,
{ "Alt-RAB-Parameter-SupportedMaxBitrateInf", "ranap.Alt_RAB_Parameter_SupportedMaxBitrateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_AlternativeRABConfigurationRequest_PDU,
{ "AlternativeRABConfigurationRequest", "ranap.AlternativeRABConfigurationRequest",
FT_UINT32, BASE_DEC, VALS(ranap_AlternativeRABConfigurationRequest_vals), 0,
NULL, HFILL }},
{ &hf_ranap_UE_Application_Layer_Measurement_Configuration_PDU,
{ "UE-Application-Layer-Measurement-Configuration", "ranap.UE_Application_Layer_Measurement_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation_PDU,
{ "UE-Application-Layer-Measurement-Configuration-For-Relocation", "ranap.UE_Application_Layer_Measurement_Configuration_For_Relocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_APN_PDU,
{ "APN", "ranap.APN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_AreaIdentity_PDU,
{ "AreaIdentity", "ranap.AreaIdentity",
FT_UINT32, BASE_DEC, VALS(ranap_AreaIdentity_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameters_PDU,
{ "Ass-RAB-Parameters", "ranap.Ass_RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU,
{ "Ass-RAB-Parameter-ExtendedGuaranteedBitrateList", "ranap.Ass_RAB_Parameter_ExtendedGuaranteedBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList_PDU,
{ "Ass-RAB-Parameter-ExtendedMaxBitrateList", "ranap.Ass_RAB_Parameter_ExtendedMaxBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_BarometricPressure_PDU,
{ "BarometricPressure", "ranap.BarometricPressure",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_BroadcastAssistanceDataDecipheringKeys_PDU,
{ "BroadcastAssistanceDataDecipheringKeys", "ranap.BroadcastAssistanceDataDecipheringKeys_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Cause_PDU,
{ "Cause", "ranap.Cause",
FT_UINT32, BASE_DEC, VALS(ranap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Cell_Access_Mode_PDU,
{ "Cell-Access-Mode", "ranap.Cell_Access_Mode",
FT_UINT32, BASE_DEC, VALS(ranap_Cell_Access_Mode_vals), 0,
NULL, HFILL }},
{ &hf_ranap_CellLoadInformationGroup_PDU,
{ "CellLoadInformationGroup", "ranap.CellLoadInformationGroup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CivicAddress_PDU,
{ "CivicAddress", "ranap.CivicAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ClientType_PDU,
{ "ClientType", "ranap.ClientType",
FT_UINT32, BASE_DEC, VALS(ranap_ClientType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "ranap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MessageStructure_PDU,
{ "MessageStructure", "ranap.MessageStructure",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ChosenEncryptionAlgorithm_PDU,
{ "ChosenEncryptionAlgorithm", "ranap.ChosenEncryptionAlgorithm",
FT_UINT32, BASE_DEC, VALS(ranap_EncryptionAlgorithm_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ChosenIntegrityProtectionAlgorithm_PDU,
{ "ChosenIntegrityProtectionAlgorithm", "ranap.ChosenIntegrityProtectionAlgorithm",
FT_UINT32, BASE_DEC, VALS(ranap_IntegrityProtectionAlgorithm_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ClassmarkInformation2_PDU,
{ "ClassmarkInformation2", "ranap.ClassmarkInformation2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ClassmarkInformation3_PDU,
{ "ClassmarkInformation3", "ranap.ClassmarkInformation3",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CN_DomainIndicator_PDU,
{ "CN-DomainIndicator", "ranap.CN_DomainIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_CN_DomainIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Correlation_ID_PDU,
{ "Correlation-ID", "ranap.Correlation_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CSFB_Information_PDU,
{ "CSFB-Information", "ranap.CSFB_Information",
FT_UINT32, BASE_DEC, VALS(ranap_CSFB_Information_vals), 0,
NULL, HFILL }},
{ &hf_ranap_CSG_Id_PDU,
{ "CSG-Id", "ranap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CSG_Id_List_PDU,
{ "CSG-Id-List", "ranap.CSG_Id_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CSG_Membership_Status_PDU,
{ "CSG-Membership-Status", "ranap.CSG_Membership_Status",
FT_UINT32, BASE_DEC, VALS(ranap_CSG_Membership_Status_vals), 0,
NULL, HFILL }},
{ &hf_ranap_DCN_ID_PDU,
{ "DCN-ID", "ranap.DCN_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DeltaRAListofIdleModeUEs_PDU,
{ "DeltaRAListofIdleModeUEs", "ranap.DeltaRAListofIdleModeUEs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DRX_CycleLengthCoefficient_PDU,
{ "DRX-CycleLengthCoefficient", "ranap.DRX_CycleLengthCoefficient",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EARFCN_Extended_PDU,
{ "EARFCN-Extended", "ranap.EARFCN_Extended",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_E_DCH_MAC_d_Flow_ID_PDU,
{ "E-DCH-MAC-d-Flow-ID", "ranap.E_DCH_MAC_d_Flow_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EncryptionInformation_PDU,
{ "EncryptionInformation", "ranap.EncryptionInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EncryptionKey_PDU,
{ "EncryptionKey", "ranap.EncryptionKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_End_Of_CSFB_PDU,
{ "End-Of-CSFB", "ranap.End_Of_CSFB",
FT_UINT32, BASE_DEC, VALS(ranap_End_Of_CSFB_vals), 0,
NULL, HFILL }},
{ &hf_ranap_E_UTRAN_Service_Handover_PDU,
{ "E-UTRAN-Service-Handover", "ranap.E_UTRAN_Service_Handover",
FT_UINT32, BASE_DEC, VALS(ranap_E_UTRAN_Service_Handover_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ExtendedRNC_ID_PDU,
{ "ExtendedRNC-ID", "ranap.ExtendedRNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_FrequenceLayerConvergenceFlag_PDU,
{ "FrequenceLayerConvergenceFlag", "ranap.FrequenceLayerConvergenceFlag",
FT_UINT32, BASE_DEC, VALS(ranap_FrequenceLayerConvergenceFlag_vals), 0,
NULL, HFILL }},
{ &hf_ranap_GANSS_PositioningDataSet_PDU,
{ "GANSS-PositioningDataSet", "ranap.GANSS_PositioningDataSet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GERAN_BSC_Container_PDU,
{ "GERAN-BSC-Container", "ranap.GERAN_BSC_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GERAN_Classmark_PDU,
{ "GERAN-Classmark", "ranap.GERAN_Classmark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GlobalCN_ID_PDU,
{ "GlobalCN-ID", "ranap.GlobalCN_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GlobalRNC_ID_PDU,
{ "GlobalRNC-ID", "ranap.GlobalRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_HigherBitratesThan16MbpsFlag_PDU,
{ "HigherBitratesThan16MbpsFlag", "ranap.HigherBitratesThan16MbpsFlag",
FT_UINT32, BASE_DEC, VALS(ranap_HigherBitratesThan16MbpsFlag_vals), 0,
NULL, HFILL }},
{ &hf_ranap_HS_DSCH_MAC_d_Flow_ID_PDU,
{ "HS-DSCH-MAC-d-Flow-ID", "ranap.HS_DSCH_MAC_d_Flow_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IMSI_PDU,
{ "IMSI", "ranap.IMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IncludeVelocity_PDU,
{ "IncludeVelocity", "ranap.IncludeVelocity",
FT_UINT32, BASE_DEC, VALS(ranap_IncludeVelocity_vals), 0,
NULL, HFILL }},
{ &hf_ranap_InformationExchangeID_PDU,
{ "InformationExchangeID", "ranap.InformationExchangeID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InformationExchangeType_PDU,
{ "InformationExchangeType", "ranap.InformationExchangeType",
FT_UINT32, BASE_DEC, VALS(ranap_InformationExchangeType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_InformationRequested_PDU,
{ "InformationRequested", "ranap.InformationRequested",
FT_UINT32, BASE_DEC, VALS(ranap_InformationRequested_vals), 0,
NULL, HFILL }},
{ &hf_ranap_InformationRequestType_PDU,
{ "InformationRequestType", "ranap.InformationRequestType",
FT_UINT32, BASE_DEC, VALS(ranap_InformationRequestType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_InformationTransferID_PDU,
{ "InformationTransferID", "ranap.InformationTransferID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InformationTransferType_PDU,
{ "InformationTransferType", "ranap.InformationTransferType",
FT_UINT32, BASE_DEC, VALS(ranap_InformationTransferType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_IntegrityProtectionInformation_PDU,
{ "IntegrityProtectionInformation", "ranap.IntegrityProtectionInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IntegrityProtectionKey_PDU,
{ "IntegrityProtectionKey", "ranap.IntegrityProtectionKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InterSystemInformationTransferType_PDU,
{ "InterSystemInformationTransferType", "ranap.InterSystemInformationTransferType",
FT_UINT32, BASE_DEC, VALS(ranap_InterSystemInformationTransferType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ranap_InterSystemInformation_TransparentContainer_PDU,
{ "InterSystemInformation-TransparentContainer", "ranap.InterSystemInformation_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IPMulticastAddress_PDU,
{ "IPMulticastAddress", "ranap.IPMulticastAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IuSignallingConnectionIdentifier_PDU,
{ "IuSignallingConnectionIdentifier", "ranap.IuSignallingConnectionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IuTransportAssociation_PDU,
{ "IuTransportAssociation", "ranap.IuTransportAssociation",
FT_UINT32, BASE_DEC, VALS(ranap_IuTransportAssociation_vals), 0,
NULL, HFILL }},
{ &hf_ranap_KeyStatus_PDU,
{ "KeyStatus", "ranap.KeyStatus",
FT_UINT32, BASE_DEC, VALS(ranap_KeyStatus_vals), 0,
NULL, HFILL }},
{ &hf_ranap_LAI_PDU,
{ "LAI", "ranap.LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LastKnownServiceArea_PDU,
{ "LastKnownServiceArea", "ranap.LastKnownServiceArea_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ranap_LastVisitedUTRANCell_Item_PDU,
{ "LastVisitedUTRANCell-Item", "ranap.LastVisitedUTRANCell_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LHN_ID_PDU,
{ "LHN-ID", "ranap.LHN_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationRelatedDataRequestType_PDU,
{ "LocationRelatedDataRequestType", "ranap.LocationRelatedDataRequestType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationRelatedDataRequestTypeSpecificToGERANIuMode_PDU,
{ "LocationRelatedDataRequestTypeSpecificToGERANIuMode", "ranap.LocationRelatedDataRequestTypeSpecificToGERANIuMode",
FT_UINT32, BASE_DEC, VALS(ranap_LocationRelatedDataRequestTypeSpecificToGERANIuMode_vals), 0,
NULL, HFILL }},
{ &hf_ranap_L3_Information_PDU,
{ "L3-Information", "ranap.L3_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_M4Report_PDU,
{ "M4Report", "ranap.M4Report",
FT_UINT32, BASE_DEC, VALS(ranap_M4Report_vals), 0,
NULL, HFILL }},
{ &hf_ranap_M5Report_PDU,
{ "M5Report", "ranap.M5Report",
FT_UINT32, BASE_DEC, VALS(ranap_M5Report_vals), 0,
NULL, HFILL }},
{ &hf_ranap_M6Report_PDU,
{ "M6Report", "ranap.M6Report_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_M7Report_PDU,
{ "M7Report", "ranap.M7Report_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Management_Based_MDT_Allowed_PDU,
{ "Management-Based-MDT-Allowed", "ranap.Management_Based_MDT_Allowed",
FT_UINT32, BASE_DEC, VALS(ranap_Management_Based_MDT_Allowed_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSBearerServiceType_PDU,
{ "MBMSBearerServiceType", "ranap.MBMSBearerServiceType",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSBearerServiceType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSCNDe_Registration_PDU,
{ "MBMSCNDe-Registration", "ranap.MBMSCNDe_Registration",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSCNDe_Registration_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSCountingInformation_PDU,
{ "MBMSCountingInformation", "ranap.MBMSCountingInformation",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSCountingInformation_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSLinkingInformation_PDU,
{ "MBMSLinkingInformation", "ranap.MBMSLinkingInformation",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSLinkingInformation_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRegistrationRequestType_PDU,
{ "MBMSRegistrationRequestType", "ranap.MBMSRegistrationRequestType",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSRegistrationRequestType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_MBMSServiceArea_PDU,
{ "MBMSServiceArea", "ranap.MBMSServiceArea",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionDuration_PDU,
{ "MBMSSessionDuration", "ranap.MBMSSessionDuration",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionIdentity_PDU,
{ "MBMSSessionIdentity", "ranap.MBMSSessionIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionRepetitionNumber_PDU,
{ "MBMSSessionRepetitionNumber", "ranap.MBMSSessionRepetitionNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MDT_Configuration_PDU,
{ "MDT-Configuration", "ranap.MDT_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MDT_PLMN_List_PDU,
{ "MDT-PLMN-List", "ranap.MDT_PLMN_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MSISDN_PDU,
{ "MSISDN", "ranap.MSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_NAS_PDU_PDU,
{ "NAS-PDU", "ranap.NAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_NAS_SequenceNumber_PDU,
{ "NAS-SequenceNumber", "ranap.NAS_SequenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_NewBSS_To_OldBSS_Information_PDU,
{ "NewBSS-To-OldBSS-Information", "ranap.NewBSS_To_OldBSS_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_NonSearchingIndication_PDU,
{ "NonSearchingIndication", "ranap.NonSearchingIndication",
FT_UINT32, BASE_DEC, VALS(ranap_NonSearchingIndication_vals), 0,
NULL, HFILL }},
{ &hf_ranap_NumberOfSteps_PDU,
{ "NumberOfSteps", "ranap.NumberOfSteps",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Offload_RAB_Parameters_PDU,
{ "Offload-RAB-Parameters", "ranap.Offload_RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_OldBSS_ToNewBSS_Information_PDU,
{ "OldBSS-ToNewBSS-Information", "ranap.OldBSS_ToNewBSS_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_OMC_ID_PDU,
{ "OMC-ID", "ranap.OMC_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Out_Of_UTRAN_PDU,
{ "Out-Of-UTRAN", "ranap.Out_Of_UTRAN",
FT_UINT32, BASE_DEC, VALS(ranap_Out_Of_UTRAN_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PagingAreaID_PDU,
{ "PagingAreaID", "ranap.PagingAreaID",
FT_UINT32, BASE_DEC, VALS(ranap_PagingAreaID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PagingCause_PDU,
{ "PagingCause", "ranap.PagingCause",
FT_UINT32, BASE_DEC, VALS(ranap_PagingCause_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PDP_TypeInformation_PDU,
{ "PDP-TypeInformation", "ranap.PDP_TypeInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PDP_TypeInformation_extension_PDU,
{ "PDP-TypeInformation-extension", "ranap.PDP_TypeInformation_extension",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PeriodicLocationInfo_PDU,
{ "PeriodicLocationInfo", "ranap.PeriodicLocationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PermanentNAS_UE_ID_PDU,
{ "PermanentNAS-UE-ID", "ranap.PermanentNAS_UE_ID",
FT_UINT32, BASE_DEC, VALS(ranap_PermanentNAS_UE_ID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PLMNidentity_PDU,
{ "PLMNidentity", "ranap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PositioningPriority_PDU,
{ "PositioningPriority", "ranap.PositioningPriority",
FT_UINT32, BASE_DEC, VALS(ranap_PositioningPriority_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PositionData_PDU,
{ "PositionData", "ranap.PositionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PositionDataSpecificToGERANIuMode_PDU,
{ "PositionDataSpecificToGERANIuMode", "ranap.PositionDataSpecificToGERANIuMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Priority_Class_Indicator_PDU,
{ "Priority-Class-Indicator", "ranap.Priority_Class_Indicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ProvidedData_PDU,
{ "ProvidedData", "ranap.ProvidedData",
FT_UINT32, BASE_DEC, VALS(ranap_ProvidedData_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PowerSavingIndicator_PDU,
{ "PowerSavingIndicator", "ranap.PowerSavingIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_PowerSavingIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_P_TMSI_PDU,
{ "P-TMSI", "ranap.P_TMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ID_PDU,
{ "RAB-ID", "ranap.RAB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU,
{ "RAB-Parameter-ExtendedGuaranteedBitrateList", "ranap.RAB_Parameter_ExtendedGuaranteedBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_ExtendedMaxBitrateList_PDU,
{ "RAB-Parameter-ExtendedMaxBitrateList", "ranap.RAB_Parameter_ExtendedMaxBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameters_PDU,
{ "RAB-Parameters", "ranap.RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RABParametersList_PDU,
{ "RABParametersList", "ranap.RABParametersList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAC_PDU,
{ "RAC", "ranap.RAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAListofIdleModeUEs_PDU,
{ "RAListofIdleModeUEs", "ranap.RAListofIdleModeUEs",
FT_UINT32, BASE_DEC, VALS(ranap_RAListofIdleModeUEs_vals), 0,
NULL, HFILL }},
{ &hf_ranap_LAListofIdleModeUEs_PDU,
{ "LAListofIdleModeUEs", "ranap.LAListofIdleModeUEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAT_Type_PDU,
{ "RAT-Type", "ranap.RAT_Type",
FT_UINT32, BASE_DEC, VALS(ranap_RAT_Type_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RedirectAttemptFlag_PDU,
{ "RedirectAttemptFlag", "ranap.RedirectAttemptFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RedirectionCompleted_PDU,
{ "RedirectionCompleted", "ranap.RedirectionCompleted",
FT_UINT32, BASE_DEC, VALS(ranap_RedirectionCompleted_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RejectCauseValue_PDU,
{ "RejectCauseValue", "ranap.RejectCauseValue",
FT_UINT32, BASE_DEC, VALS(ranap_RejectCauseValue_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RelocationType_PDU,
{ "RelocationType", "ranap.RelocationType",
FT_UINT32, BASE_DEC, VALS(ranap_RelocationType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RequestedGANSSAssistanceData_PDU,
{ "RequestedGANSSAssistanceData", "ranap.RequestedGANSSAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList_PDU,
{ "Requested-RAB-Parameter-ExtendedMaxBitrateList", "ranap.Requested_RAB_Parameter_ExtendedMaxBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU,
{ "Requested-RAB-Parameter-ExtendedGuaranteedBitrateList", "ranap.Requested_RAB_Parameter_ExtendedGuaranteedBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RequestType_PDU,
{ "RequestType", "ranap.RequestType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResponseTime_PDU,
{ "ResponseTime", "ranap.ResponseTime",
FT_UINT32, BASE_DEC, VALS(ranap_ResponseTime_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RNSAPRelocationParameters_PDU,
{ "RNSAPRelocationParameters", "ranap.RNSAPRelocationParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RRC_Container_PDU,
{ "RRC-Container", "ranap.RRC_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RSRVCC_HO_Indication_PDU,
{ "RSRVCC-HO-Indication", "ranap.RSRVCC_HO_Indication",
FT_UINT32, BASE_DEC, VALS(ranap_RSRVCC_HO_Indication_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RSRVCC_Information_PDU,
{ "RSRVCC-Information", "ranap.RSRVCC_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RSRVCC_Operation_Possible_PDU,
{ "RSRVCC-Operation-Possible", "ranap.RSRVCC_Operation_Possible",
FT_UINT32, BASE_DEC, VALS(ranap_RSRVCC_Operation_Possible_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SAI_PDU,
{ "SAI", "ranap.SAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SAPI_PDU,
{ "SAPI", "ranap.SAPI",
FT_UINT32, BASE_DEC, VALS(ranap_SAPI_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SessionUpdateID_PDU,
{ "SessionUpdateID", "ranap.SessionUpdateID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Session_Re_establishment_Indicator_PDU,
{ "Session-Re-establishment-Indicator", "ranap.Session_Re_establishment_Indicator",
FT_UINT32, BASE_DEC, VALS(ranap_Session_Re_establishment_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SignallingIndication_PDU,
{ "SignallingIndication", "ranap.SignallingIndication",
FT_UINT32, BASE_DEC, VALS(ranap_SignallingIndication_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SGSN_Group_Identity_PDU,
{ "SGSN-Group-Identity", "ranap.SGSN_Group_Identity",
FT_UINT32, BASE_DEC, VALS(ranap_SGSN_Group_Identity_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SNA_Access_Information_PDU,
{ "SNA-Access-Information", "ranap.SNA_Access_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ranap_Source_ToTarget_TransparentContainer_PDU,
{ "Source-ToTarget-TransparentContainer", "ranap.Source_ToTarget_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ranap_SourceCellID_PDU,
{ "SourceCellID", "ranap.SourceCellID",
FT_UINT32, BASE_DEC, VALS(ranap_SourceCellID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SourceBSS_ToTargetBSS_TransparentContainer_PDU,
{ "SourceBSS-ToTargetBSS-TransparentContainer", "ranap.SourceBSS_ToTargetBSS_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SourceID_PDU,
{ "SourceID", "ranap.SourceID",
FT_UINT32, BASE_DEC, VALS(ranap_SourceID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU,
{ "SourceRNC-ToTargetRNC-TransparentContainer", "ranap.SourceRNC_ToTargetRNC_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_IRAT_Measurement_Configuration_PDU,
{ "IRAT-Measurement-Configuration", "ranap.IRAT_Measurement_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RSRQ_Type_PDU,
{ "RSRQ-Type", "ranap.RSRQ_Type_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RSRQ_Extension_PDU,
{ "RSRQ-Extension", "ranap.RSRQ_Extension",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SubscriberProfileIDforRFP_PDU,
{ "SubscriberProfileIDforRFP", "ranap.SubscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SupportedRAB_ParameterBitrateList_PDU,
{ "SupportedRAB-ParameterBitrateList", "ranap.SupportedRAB_ParameterBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRB_TrCH_Mapping_PDU,
{ "SRB-TrCH-Mapping", "ranap.SRB_TrCH_Mapping",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRVCC_HO_Indication_PDU,
{ "SRVCC-HO-Indication", "ranap.SRVCC_HO_Indication",
FT_UINT32, BASE_DEC, VALS(ranap_SRVCC_HO_Indication_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SRVCC_Information_PDU,
{ "SRVCC-Information", "ranap.SRVCC_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRVCC_Operation_Possible_PDU,
{ "SRVCC-Operation-Possible", "ranap.SRVCC_Operation_Possible",
FT_UINT32, BASE_DEC, VALS(ranap_SRVCC_Operation_Possible_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Target_ToSource_TransparentContainer_PDU,
{ "Target-ToSource-TransparentContainer", "ranap.Target_ToSource_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TargetBSS_ToSourceBSS_TransparentContainer_PDU,
{ "TargetBSS-ToSourceBSS-TransparentContainer", "ranap.TargetBSS_ToSourceBSS_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TargetID_PDU,
{ "TargetID", "ranap.TargetID",
FT_UINT32, BASE_DEC, VALS(ranap_TargetID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ranap_TargetRNC_ID_PDU,
{ "TargetRNC-ID", "ranap.TargetRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU,
{ "TargetRNC-ToSourceRNC-TransparentContainer", "ranap.TargetRNC_ToSourceRNC_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TemporaryUE_ID_PDU,
{ "TemporaryUE-ID", "ranap.TemporaryUE_ID",
FT_UINT32, BASE_DEC, VALS(ranap_TemporaryUE_ID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Time_UE_StayedInCell_EnhancedGranularity_PDU,
{ "Time-UE-StayedInCell-EnhancedGranularity", "ranap.Time_UE_StayedInCell_EnhancedGranularity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TimeToMBMSDataTransfer_PDU,
{ "TimeToMBMSDataTransfer", "ranap.TimeToMBMSDataTransfer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TimingDifferenceULDL_PDU,
{ "TimingDifferenceULDL", "ranap.TimingDifferenceULDL",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TMGI_PDU,
{ "TMGI", "ranap.TMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TracePropagationParameters_PDU,
{ "TracePropagationParameters", "ranap.TracePropagationParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TraceRecordingSessionInformation_PDU,
{ "TraceRecordingSessionInformation", "ranap.TraceRecordingSessionInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TraceRecordingSessionReference_PDU,
{ "TraceRecordingSessionReference", "ranap.TraceRecordingSessionReference",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TraceReference_PDU,
{ "TraceReference", "ranap.TraceReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TraceType_PDU,
{ "TraceType", "ranap.TraceType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TransportLayerAddress_PDU,
{ "TransportLayerAddress", "ranap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TriggerID_PDU,
{ "TriggerID", "ranap.TriggerID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TunnelInformation_PDU,
{ "TunnelInformation", "ranap.TunnelInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TypeOfError_PDU,
{ "TypeOfError", "ranap.TypeOfError",
FT_UINT32, BASE_DEC, VALS(ranap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_ranap_UE_AggregateMaximumBitRate_PDU,
{ "UE-AggregateMaximumBitRate", "ranap.UE_AggregateMaximumBitRate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UE_History_Information_PDU,
{ "UE-History-Information", "ranap.UE_History_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UE_ID_PDU,
{ "UE-ID", "ranap.UE_ID",
FT_UINT32, BASE_DEC, VALS(ranap_UE_ID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_UE_Usage_Type_PDU,
{ "UE-Usage-Type", "ranap.UE_Usage_Type",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UERegistrationQueryResult_PDU,
{ "UERegistrationQueryResult", "ranap.UERegistrationQueryResult",
FT_UINT32, BASE_DEC, VALS(ranap_UERegistrationQueryResult_vals), 0,
NULL, HFILL }},
{ &hf_ranap_UESBI_Iu_PDU,
{ "UESBI-Iu", "ranap.UESBI_Iu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UTRAN_CellID_PDU,
{ "UTRAN-CellID", "ranap.UTRAN_CellID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_VelocityEstimate_PDU,
{ "VelocityEstimate", "ranap.VelocityEstimate",
FT_UINT32, BASE_DEC, VALS(ranap_VelocityEstimate_vals), 0,
NULL, HFILL }},
{ &hf_ranap_VerticalAccuracyCode_PDU,
{ "VerticalAccuracyCode", "ranap.VerticalAccuracyCode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_VoiceSupportMatchIndicator_PDU,
{ "VoiceSupportMatchIndicator", "ranap.VoiceSupportMatchIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_VoiceSupportMatchIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_Iu_ReleaseCommand_PDU,
{ "Iu-ReleaseCommand", "ranap.Iu_ReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Iu_ReleaseComplete_PDU,
{ "Iu-ReleaseComplete", "ranap.Iu_ReleaseComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataVolumeReportList_PDU,
{ "RAB-DataVolumeReportList", "ranap.RAB_DataVolumeReportList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataVolumeReportItem_PDU,
{ "RAB-DataVolumeReportItem", "ranap.RAB_DataVolumeReportItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleasedList_IuRelComp_PDU,
{ "RAB-ReleasedList-IuRelComp", "ranap.RAB_ReleasedList_IuRelComp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleasedItem_IuRelComp_PDU,
{ "RAB-ReleasedItem-IuRelComp", "ranap.RAB_ReleasedItem_IuRelComp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationRequired_PDU,
{ "RelocationRequired", "ranap.RelocationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationCommand_PDU,
{ "RelocationCommand", "ranap.RelocationCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_RelocationReleaseList_PDU,
{ "RAB-RelocationReleaseList", "ranap.RAB_RelocationReleaseList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_RelocationReleaseItem_PDU,
{ "RAB-RelocationReleaseItem", "ranap.RAB_RelocationReleaseItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataForwardingList_PDU,
{ "RAB-DataForwardingList", "ranap.RAB_DataForwardingList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataForwardingItem_PDU,
{ "RAB-DataForwardingItem", "ranap.RAB_DataForwardingItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationPreparationFailure_PDU,
{ "RelocationPreparationFailure", "ranap.RelocationPreparationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationRequest_PDU,
{ "RelocationRequest", "ranap.RelocationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_RelocReq_PDU,
{ "RAB-SetupList-RelocReq", "ranap.RAB_SetupList_RelocReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_RelocReq_PDU,
{ "RAB-SetupItem-RelocReq", "ranap.RAB_SetupItem_RelocReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CNMBMSLinkingInformation_PDU,
{ "CNMBMSLinkingInformation", "ranap.CNMBMSLinkingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_JoinedMBMSBearerService_IEs_PDU,
{ "JoinedMBMSBearerService-IEs", "ranap.JoinedMBMSBearerService_IEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationRequestAcknowledge_PDU,
{ "RelocationRequestAcknowledge", "ranap.RelocationRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_RelocReqAck_PDU,
{ "RAB-SetupList-RelocReqAck", "ranap.RAB_SetupList_RelocReqAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_RelocReqAck_PDU,
{ "RAB-SetupItem-RelocReqAck", "ranap.RAB_SetupItem_RelocReqAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_FailedList_PDU,
{ "RAB-FailedList", "ranap.RAB_FailedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_FailedItem_PDU,
{ "RAB-FailedItem", "ranap.RAB_FailedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationFailure_PDU,
{ "RelocationFailure", "ranap.RelocationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationCancel_PDU,
{ "RelocationCancel", "ranap.RelocationCancel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationCancelAcknowledge_PDU,
{ "RelocationCancelAcknowledge", "ranap.RelocationCancelAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRNS_ContextRequest_PDU,
{ "SRNS-ContextRequest", "ranap.SRNS_ContextRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataForwardingList_SRNS_CtxReq_PDU,
{ "RAB-DataForwardingList-SRNS-CtxReq", "ranap.RAB_DataForwardingList_SRNS_CtxReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataForwardingItem_SRNS_CtxReq_PDU,
{ "RAB-DataForwardingItem-SRNS-CtxReq", "ranap.RAB_DataForwardingItem_SRNS_CtxReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRNS_ContextResponse_PDU,
{ "SRNS-ContextResponse", "ranap.SRNS_ContextResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ContextList_PDU,
{ "RAB-ContextList", "ranap.RAB_ContextList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ContextItem_PDU,
{ "RAB-ContextItem", "ranap.RAB_ContextItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ContextFailedtoTransferList_PDU,
{ "RAB-ContextFailedtoTransferList", "ranap.RAB_ContextFailedtoTransferList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RABs_ContextFailedtoTransferItem_PDU,
{ "RABs-ContextFailedtoTransferItem", "ranap.RABs_ContextFailedtoTransferItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SecurityModeCommand_PDU,
{ "SecurityModeCommand", "ranap.SecurityModeCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SecurityModeComplete_PDU,
{ "SecurityModeComplete", "ranap.SecurityModeComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SecurityModeReject_PDU,
{ "SecurityModeReject", "ranap.SecurityModeReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DataVolumeReportRequest_PDU,
{ "DataVolumeReportRequest", "ranap.DataVolumeReportRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataVolumeReportRequestList_PDU,
{ "RAB-DataVolumeReportRequestList", "ranap.RAB_DataVolumeReportRequestList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_DataVolumeReportRequestItem_PDU,
{ "RAB-DataVolumeReportRequestItem", "ranap.RAB_DataVolumeReportRequestItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DataVolumeReport_PDU,
{ "DataVolumeReport", "ranap.DataVolumeReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_FailedtoReportList_PDU,
{ "RAB-FailedtoReportList", "ranap.RAB_FailedtoReportList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RABs_failed_to_reportItem_PDU,
{ "RABs-failed-to-reportItem", "ranap.RABs_failed_to_reportItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Reset_PDU,
{ "Reset", "ranap.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetAcknowledge_PDU,
{ "ResetAcknowledge", "ranap.ResetAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResource_PDU,
{ "ResetResource", "ranap.ResetResource_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResourceList_PDU,
{ "ResetResourceList", "ranap.ResetResourceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResourceItem_PDU,
{ "ResetResourceItem", "ranap.ResetResourceItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResourceAcknowledge_PDU,
{ "ResetResourceAcknowledge", "ranap.ResetResourceAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResourceAckList_PDU,
{ "ResetResourceAckList", "ranap.ResetResourceAckList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ResetResourceAckItem_PDU,
{ "ResetResourceAckItem", "ranap.ResetResourceAckItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleaseRequest_PDU,
{ "RAB-ReleaseRequest", "ranap.RAB_ReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleaseList_PDU,
{ "RAB-ReleaseList", "ranap.RAB_ReleaseList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleaseItem_PDU,
{ "RAB-ReleaseItem", "ranap.RAB_ReleaseItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Iu_ReleaseRequest_PDU,
{ "Iu-ReleaseRequest", "ranap.Iu_ReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationDetect_PDU,
{ "RelocationDetect", "ranap.RelocationDetect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RelocationComplete_PDU,
{ "RelocationComplete", "ranap.RelocationComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EnhancedRelocationCompleteRequest_PDU,
{ "EnhancedRelocationCompleteRequest", "ranap.EnhancedRelocationCompleteRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_EnhancedRelocCompleteReq_PDU,
{ "RAB-SetupList-EnhancedRelocCompleteReq", "ranap.RAB_SetupList_EnhancedRelocCompleteReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_EnhancedRelocCompleteReq_PDU,
{ "RAB-SetupItem-EnhancedRelocCompleteReq", "ranap.RAB_SetupItem_EnhancedRelocCompleteReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EnhancedRelocationCompleteResponse_PDU,
{ "EnhancedRelocationCompleteResponse", "ranap.EnhancedRelocationCompleteResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_EnhancedRelocCompleteRes_PDU,
{ "RAB-SetupList-EnhancedRelocCompleteRes", "ranap.RAB_SetupList_EnhancedRelocCompleteRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_EnhancedRelocCompleteRes_PDU,
{ "RAB-SetupItem-EnhancedRelocCompleteRes", "ranap.RAB_SetupItem_EnhancedRelocCompleteRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ToBeReleasedList_EnhancedRelocCompleteRes_PDU,
{ "RAB-ToBeReleasedList-EnhancedRelocCompleteRes", "ranap.RAB_ToBeReleasedList_EnhancedRelocCompleteRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_PDU,
{ "RAB-ToBeReleasedItem-EnhancedRelocCompleteRes", "ranap.RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EnhancedRelocationCompleteFailure_PDU,
{ "EnhancedRelocationCompleteFailure", "ranap.EnhancedRelocationCompleteFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_EnhancedRelocationCompleteConfirm_PDU,
{ "EnhancedRelocationCompleteConfirm", "ranap.EnhancedRelocationCompleteConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Paging_PDU,
{ "Paging", "ranap.Paging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CommonID_PDU,
{ "CommonID", "ranap.CommonID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CN_InvokeTrace_PDU,
{ "CN-InvokeTrace", "ranap.CN_InvokeTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CN_DeactivateTrace_PDU,
{ "CN-DeactivateTrace", "ranap.CN_DeactivateTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationReportingControl_PDU,
{ "LocationReportingControl", "ranap.LocationReportingControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationReport_PDU,
{ "LocationReport", "ranap.LocationReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InitialUE_Message_PDU,
{ "InitialUE-Message", "ranap.InitialUE_Message_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DirectTransfer_PDU,
{ "DirectTransfer", "ranap.DirectTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RedirectionIndication_PDU,
{ "RedirectionIndication", "ranap.RedirectionIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Overload_PDU,
{ "Overload", "ranap.Overload_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ErrorIndication_PDU,
{ "ErrorIndication", "ranap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRNS_DataForwardCommand_PDU,
{ "SRNS-DataForwardCommand", "ranap.SRNS_DataForwardCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ForwardSRNS_Context_PDU,
{ "ForwardSRNS-Context", "ranap.ForwardSRNS_Context_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_AssignmentRequest_PDU,
{ "RAB-AssignmentRequest", "ranap.RAB_AssignmentRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupOrModifyList_PDU,
{ "RAB-SetupOrModifyList", "ranap.RAB_SetupOrModifyList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupOrModifyItemFirst_PDU,
{ "RAB-SetupOrModifyItemFirst", "ranap.RAB_SetupOrModifyItemFirst_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TransportLayerInformation_PDU,
{ "TransportLayerInformation", "ranap.TransportLayerInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupOrModifyItemSecond_PDU,
{ "RAB-SetupOrModifyItemSecond", "ranap.RAB_SetupOrModifyItemSecond_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_AssignmentResponse_PDU,
{ "RAB-AssignmentResponse", "ranap.RAB_AssignmentResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupOrModifiedList_PDU,
{ "RAB-SetupOrModifiedList", "ranap.RAB_SetupOrModifiedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupOrModifiedItem_PDU,
{ "RAB-SetupOrModifiedItem", "ranap.RAB_SetupOrModifiedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleasedList_PDU,
{ "RAB-ReleasedList", "ranap.RAB_ReleasedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleasedItem_PDU,
{ "RAB-ReleasedItem", "ranap.RAB_ReleasedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_QueuedList_PDU,
{ "RAB-QueuedList", "ranap.RAB_QueuedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_QueuedItem_PDU,
{ "RAB-QueuedItem", "ranap.RAB_QueuedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ReleaseFailedList_PDU,
{ "RAB-ReleaseFailedList", "ranap.RAB_ReleaseFailedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GERAN_Iumode_RAB_FailedList_RABAssgntResponse_PDU,
{ "GERAN-Iumode-RAB-FailedList-RABAssgntResponse", "ranap.GERAN_Iumode_RAB_FailedList_RABAssgntResponse",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_PDU,
{ "GERAN-Iumode-RAB-Failed-RABAssgntResponse-Item", "ranap.GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PrivateMessage_PDU,
{ "PrivateMessage", "ranap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RANAP_RelocationInformation_PDU,
{ "RANAP-RelocationInformation", "ranap.RANAP_RelocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DirectTransferInformationList_RANAP_RelocInf_PDU,
{ "DirectTransferInformationList-RANAP-RelocInf", "ranap.DirectTransferInformationList_RANAP_RelocInf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DirectTransferInformationItem_RANAP_RelocInf_PDU,
{ "DirectTransferInformationItem-RANAP-RelocInf", "ranap.DirectTransferInformationItem_RANAP_RelocInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ContextList_RANAP_RelocInf_PDU,
{ "RAB-ContextList-RANAP-RelocInf", "ranap.RAB_ContextList_RANAP_RelocInf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ContextItem_RANAP_RelocInf_PDU,
{ "RAB-ContextItem-RANAP-RelocInf", "ranap.RAB_ContextItem_RANAP_RelocInf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RANAP_EnhancedRelocationInformationRequest_PDU,
{ "RANAP-EnhancedRelocationInformationRequest", "ranap.RANAP_EnhancedRelocationInformationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_EnhRelocInfoReq_PDU,
{ "RAB-SetupList-EnhRelocInfoReq", "ranap.RAB_SetupList_EnhRelocInfoReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_EnhRelocInfoReq_PDU,
{ "RAB-SetupItem-EnhRelocInfoReq", "ranap.RAB_SetupItem_EnhRelocInfoReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RANAP_EnhancedRelocationInformationResponse_PDU,
{ "RANAP-EnhancedRelocationInformationResponse", "ranap.RANAP_EnhancedRelocationInformationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupList_EnhRelocInfoRes_PDU,
{ "RAB-SetupList-EnhRelocInfoRes", "ranap.RAB_SetupList_EnhRelocInfoRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_SetupItem_EnhRelocInfoRes_PDU,
{ "RAB-SetupItem-EnhRelocInfoRes", "ranap.RAB_SetupItem_EnhRelocInfoRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_FailedList_EnhRelocInfoRes_PDU,
{ "RAB-FailedList-EnhRelocInfoRes", "ranap.RAB_FailedList_EnhRelocInfoRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_FailedItem_EnhRelocInfoRes_PDU,
{ "RAB-FailedItem-EnhRelocInfoRes", "ranap.RAB_FailedItem_EnhRelocInfoRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ModifyRequest_PDU,
{ "RAB-ModifyRequest", "ranap.RAB_ModifyRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ModifyList_PDU,
{ "RAB-ModifyList", "ranap.RAB_ModifyList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_ModifyItem_PDU,
{ "RAB-ModifyItem", "ranap.RAB_ModifyItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationRelatedDataRequest_PDU,
{ "LocationRelatedDataRequest", "ranap.LocationRelatedDataRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationRelatedDataResponse_PDU,
{ "LocationRelatedDataResponse", "ranap.LocationRelatedDataResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LocationRelatedDataFailure_PDU,
{ "LocationRelatedDataFailure", "ranap.LocationRelatedDataFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InformationTransferIndication_PDU,
{ "InformationTransferIndication", "ranap.InformationTransferIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InformationTransferConfirmation_PDU,
{ "InformationTransferConfirmation", "ranap.InformationTransferConfirmation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_InformationTransferFailure_PDU,
{ "InformationTransferFailure", "ranap.InformationTransferFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UESpecificInformationIndication_PDU,
{ "UESpecificInformationIndication", "ranap.UESpecificInformationIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_DirectInformationTransfer_PDU,
{ "DirectInformationTransfer", "ranap.DirectInformationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UplinkInformationExchangeRequest_PDU,
{ "UplinkInformationExchangeRequest", "ranap.UplinkInformationExchangeRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UplinkInformationExchangeResponse_PDU,
{ "UplinkInformationExchangeResponse", "ranap.UplinkInformationExchangeResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UplinkInformationExchangeFailure_PDU,
{ "UplinkInformationExchangeFailure", "ranap.UplinkInformationExchangeFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionStart_PDU,
{ "MBMSSessionStart", "ranap.MBMSSessionStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSynchronisationInformation_PDU,
{ "MBMSSynchronisationInformation", "ranap.MBMSSynchronisationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionStartResponse_PDU,
{ "MBMSSessionStartResponse", "ranap.MBMSSessionStartResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionStartFailure_PDU,
{ "MBMSSessionStartFailure", "ranap.MBMSSessionStartFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionUpdate_PDU,
{ "MBMSSessionUpdate", "ranap.MBMSSessionUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionUpdateResponse_PDU,
{ "MBMSSessionUpdateResponse", "ranap.MBMSSessionUpdateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionUpdateFailure_PDU,
{ "MBMSSessionUpdateFailure", "ranap.MBMSSessionUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionStop_PDU,
{ "MBMSSessionStop", "ranap.MBMSSessionStop_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSSessionStopResponse_PDU,
{ "MBMSSessionStopResponse", "ranap.MBMSSessionStopResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSUELinkingRequest_PDU,
{ "MBMSUELinkingRequest", "ranap.MBMSUELinkingRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LeftMBMSBearerService_IEs_PDU,
{ "LeftMBMSBearerService-IEs", "ranap.LeftMBMSBearerService_IEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSUELinkingResponse_PDU,
{ "MBMSUELinkingResponse", "ranap.MBMSUELinkingResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UnsuccessfulLinking_IEs_PDU,
{ "UnsuccessfulLinking-IEs", "ranap.UnsuccessfulLinking_IEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRegistrationRequest_PDU,
{ "MBMSRegistrationRequest", "ranap.MBMSRegistrationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRegistrationResponse_PDU,
{ "MBMSRegistrationResponse", "ranap.MBMSRegistrationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRegistrationFailure_PDU,
{ "MBMSRegistrationFailure", "ranap.MBMSRegistrationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSCNDe_RegistrationRequest_PDU,
{ "MBMSCNDe-RegistrationRequest", "ranap.MBMSCNDe_RegistrationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSCNDe_RegistrationResponse_PDU,
{ "MBMSCNDe-RegistrationResponse", "ranap.MBMSCNDe_RegistrationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRABEstablishmentIndication_PDU,
{ "MBMSRABEstablishmentIndication", "ranap.MBMSRABEstablishmentIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRABReleaseRequest_PDU,
{ "MBMSRABReleaseRequest", "ranap.MBMSRABReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRABRelease_PDU,
{ "MBMSRABRelease", "ranap.MBMSRABRelease_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MBMSRABReleaseFailure_PDU,
{ "MBMSRABReleaseFailure", "ranap.MBMSRABReleaseFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRVCC_CSKeysRequest_PDU,
{ "SRVCC-CSKeysRequest", "ranap.SRVCC_CSKeysRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SRVCC_CSKeysResponse_PDU,
{ "SRVCC-CSKeysResponse", "ranap.SRVCC_CSKeysResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UeRadioCapabilityMatchRequest_PDU,
{ "UeRadioCapabilityMatchRequest", "ranap.UeRadioCapabilityMatchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UeRadioCapabilityMatchResponse_PDU,
{ "UeRadioCapabilityMatchResponse", "ranap.UeRadioCapabilityMatchResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UeRegistrationQueryRequest_PDU,
{ "UeRegistrationQueryRequest", "ranap.UeRegistrationQueryRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UeRegistrationQueryResponse_PDU,
{ "UeRegistrationQueryResponse", "ranap.UeRegistrationQueryResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RerouteNASRequest_PDU,
{ "RerouteNASRequest", "ranap.RerouteNASRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RANAP_PDU_PDU,
{ "RANAP-PDU", "ranap.RANAP_PDU",
FT_UINT32, BASE_DEC, VALS(ranap_RANAP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_ranap_local,
{ "local", "ranap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ranap_global,
{ "global", "ranap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_ranap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "ranap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_id,
{ "id", "ranap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ranap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_ranap_criticality,
{ "criticality", "ranap.criticality",
FT_UINT32, BASE_DEC, VALS(ranap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_ranap_ie_field_value,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_ranap_ProtocolIE_ContainerPair_item,
{ "ProtocolIE-FieldPair", "ranap.ProtocolIE_FieldPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_firstCriticality,
{ "firstCriticality", "ranap.firstCriticality",
FT_UINT32, BASE_DEC, VALS(ranap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_ranap_firstValue,
{ "firstValue", "ranap.firstValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_secondCriticality,
{ "secondCriticality", "ranap.secondCriticality",
FT_UINT32, BASE_DEC, VALS(ranap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_ranap_secondValue,
{ "secondValue", "ranap.secondValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ProtocolIE_ContainerList_item,
{ "ProtocolIE-Container", "ranap.ProtocolIE_Container",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ProtocolIE_ContainerPairList_item,
{ "ProtocolIE-ContainerPair", "ranap.ProtocolIE_ContainerPair",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "ranap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ext_id,
{ "id", "ranap.id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ranap_ProtocolIE_ID_vals_ext, 0,
"ProtocolExtensionID", HFILL }},
{ &hf_ranap_extensionValue,
{ "extensionValue", "ranap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PrivateIE_Container_item,
{ "PrivateIE-Field", "ranap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_private_id,
{ "id", "ranap.id",
FT_UINT32, BASE_DEC, VALS(ranap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_ranap_private_value,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_private_value", HFILL }},
{ &hf_ranap_old_LAI,
{ "old-LAI", "ranap.old_LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"LAI", HFILL }},
{ &hf_ranap_old_RAC,
{ "old-RAC", "ranap.old_RAC",
FT_BYTES, BASE_NONE, NULL, 0,
"RAC", HFILL }},
{ &hf_ranap_nRI,
{ "nRI", "ranap.nRI",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_10", HFILL }},
{ &hf_ranap_uE_is_Attaching,
{ "uE-is-Attaching", "ranap.uE_is_Attaching_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iE_Extensions,
{ "iE-Extensions", "ranap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_ranap_Additional_PositioningDataSet_item,
{ "Additional-PositioningMethodAndUsage", "ranap.Additional_PositioningMethodAndUsage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_priorityLevel,
{ "priorityLevel", "ranap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(ranap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_ranap_pre_emptionCapability,
{ "pre-emptionCapability", "ranap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(ranap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_ranap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "ranap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(ranap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_ranap_queuingAllowed,
{ "queuingAllowed", "ranap.queuingAllowed",
FT_UINT32, BASE_DEC, VALS(ranap_QueuingAllowed_vals), 0,
NULL, HFILL }},
{ &hf_ranap_altMaxBitrateInf,
{ "altMaxBitrateInf", "ranap.altMaxBitrateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
"Alt_RAB_Parameter_MaxBitrateInf", HFILL }},
{ &hf_ranap_altGuaranteedBitRateInf,
{ "altGuaranteedBitRateInf", "ranap.altGuaranteedBitRateInf_element",
FT_NONE, BASE_NONE, NULL, 0,
"Alt_RAB_Parameter_GuaranteedBitrateInf", HFILL }},
{ &hf_ranap_altExtendedGuaranteedBitrateType,
{ "altExtendedGuaranteedBitrateType", "ranap.altExtendedGuaranteedBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_GuaranteedBitrateType_vals), 0,
"Alt_RAB_Parameter_GuaranteedBitrateType", HFILL }},
{ &hf_ranap_altExtendedGuaranteedBitrates,
{ "altExtendedGuaranteedBitrates", "ranap.altExtendedGuaranteedBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_ExtendedGuaranteedBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrates_item,
{ "Alt-RAB-Parameter-ExtendedGuaranteedBitrateList", "ranap.Alt_RAB_Parameter_ExtendedGuaranteedBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateList_item,
{ "ExtendedGuaranteedBitrate", "ranap.ExtendedGuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_altGuaranteedBitrateType,
{ "altGuaranteedBitrateType", "ranap.altGuaranteedBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_GuaranteedBitrateType_vals), 0,
"Alt_RAB_Parameter_GuaranteedBitrateType", HFILL }},
{ &hf_ranap_altGuaranteedBitrates,
{ "altGuaranteedBitrates", "ranap.altGuaranteedBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_GuaranteedBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_GuaranteedBitrates_item,
{ "Alt-RAB-Parameter-GuaranteedBitrateList", "ranap.Alt_RAB_Parameter_GuaranteedBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_GuaranteedBitrateList_item,
{ "GuaranteedBitrate", "ranap.GuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_altSupportedGuaranteedBitrateType,
{ "altSupportedGuaranteedBitrateType", "ranap.altSupportedGuaranteedBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_GuaranteedBitrateType_vals), 0,
"Alt_RAB_Parameter_GuaranteedBitrateType", HFILL }},
{ &hf_ranap_altSupportedGuaranteedBitrates,
{ "altSupportedGuaranteedBitrates", "ranap.altSupportedGuaranteedBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_SupportedGuaranteedBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrates_item,
{ "SupportedRAB-ParameterBitrateList", "ranap.SupportedRAB_ParameterBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_altExtendedMaxBitrateType,
{ "altExtendedMaxBitrateType", "ranap.altExtendedMaxBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_MaxBitrateType_vals), 0,
"Alt_RAB_Parameter_MaxBitrateType", HFILL }},
{ &hf_ranap_altExtendedMaxBitrates,
{ "altExtendedMaxBitrates", "ranap.altExtendedMaxBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_ExtendedMaxBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedMaxBitrates_item,
{ "Alt-RAB-Parameter-ExtendedMaxBitrateList", "ranap.Alt_RAB_Parameter_ExtendedMaxBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateList_item,
{ "ExtendedMaxBitrate", "ranap.ExtendedMaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_altMaxBitrateType,
{ "altMaxBitrateType", "ranap.altMaxBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_MaxBitrateType_vals), 0,
"Alt_RAB_Parameter_MaxBitrateType", HFILL }},
{ &hf_ranap_altMaxBitrates,
{ "altMaxBitrates", "ranap.altMaxBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_MaxBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_MaxBitrates_item,
{ "Alt-RAB-Parameter-MaxBitrateList", "ranap.Alt_RAB_Parameter_MaxBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_MaxBitrateList_item,
{ "MaxBitrate", "ranap.MaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_altSupportedMaxBitrateType,
{ "altSupportedMaxBitrateType", "ranap.altSupportedMaxBitrateType",
FT_UINT32, BASE_DEC, VALS(ranap_Alt_RAB_Parameter_MaxBitrateType_vals), 0,
"Alt_RAB_Parameter_MaxBitrateType", HFILL }},
{ &hf_ranap_altSupportedMaxBitrates,
{ "altSupportedMaxBitrates", "ranap.altSupportedMaxBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Alt_RAB_Parameter_SupportedMaxBitrates", HFILL }},
{ &hf_ranap_Alt_RAB_Parameter_SupportedMaxBitrates_item,
{ "SupportedRAB-ParameterBitrateList", "ranap.SupportedRAB_ParameterBitrateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_applicationLayerContainerForMeasurementConfiguration,
{ "applicationLayerContainerForMeasurementConfiguration", "ranap.applicationLayerContainerForMeasurementConfiguration",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_1000", HFILL }},
{ &hf_ranap_areaScopeForUEApplicationLayerMeasurementConfiguration,
{ "areaScopeForUEApplicationLayerMeasurementConfiguration", "ranap.areaScopeForUEApplicationLayerMeasurementConfiguration",
FT_UINT32, BASE_DEC, VALS(ranap_AreaScopeForUEApplicationLayerMeasurementConfiguration_vals), 0,
NULL, HFILL }},
{ &hf_ranap_traceReference,
{ "traceReference", "ranap.traceReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_tracePropagationParameters,
{ "tracePropagationParameters", "ranap.tracePropagationParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_traceCollectionEntityIPAddress,
{ "traceCollectionEntityIPAddress", "ranap.traceCollectionEntityIPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_ranap_cellbased,
{ "cellbased", "ranap.cellbased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_labased,
{ "labased", "ranap.labased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rabased,
{ "rabased", "ranap.rabased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_plmn_area_based,
{ "plmn-area-based", "ranap.plmn_area_based_element",
FT_NONE, BASE_NONE, NULL, 0,
"PLMNBased", HFILL }},
{ &hf_ranap_sAI,
{ "sAI", "ranap.sAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_geographicalArea,
{ "geographicalArea", "ranap.geographicalArea",
FT_UINT32, BASE_DEC, VALS(ranap_GeographicalArea_vals), 0,
NULL, HFILL }},
{ &hf_ranap_assMaxBitrateInf,
{ "assMaxBitrateInf", "ranap.assMaxBitrateInf",
FT_UINT32, BASE_DEC, NULL, 0,
"Ass_RAB_Parameter_MaxBitrateList", HFILL }},
{ &hf_ranap_assGuaranteedBitRateInf,
{ "assGuaranteedBitRateInf", "ranap.assGuaranteedBitRateInf",
FT_UINT32, BASE_DEC, NULL, 0,
"Ass_RAB_Parameter_GuaranteedBitrateList", HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_item,
{ "ExtendedGuaranteedBitrate", "ranap.ExtendedGuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList_item,
{ "ExtendedMaxBitrate", "ranap.ExtendedMaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_GuaranteedBitrateList_item,
{ "GuaranteedBitrate", "ranap.GuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Ass_RAB_Parameter_MaxBitrateList_item,
{ "MaxBitrate", "ranap.MaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_AuthorisedPLMNs_item,
{ "AuthorisedPLMNs item", "ranap.AuthorisedPLMNs_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_pLMNidentity,
{ "pLMNidentity", "ranap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_authorisedSNAsList,
{ "authorisedSNAsList", "ranap.authorisedSNAsList",
FT_UINT32, BASE_DEC, NULL, 0,
"AuthorisedSNAs", HFILL }},
{ &hf_ranap_AuthorisedSNAs_item,
{ "SNAC", "ranap.SNAC",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cipheringKeyFlag,
{ "cipheringKeyFlag", "ranap.cipheringKeyFlag",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1", HFILL }},
{ &hf_ranap_currentDecipheringKey,
{ "currentDecipheringKey", "ranap.currentDecipheringKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_56", HFILL }},
{ &hf_ranap_nextDecipheringKey,
{ "nextDecipheringKey", "ranap.nextDecipheringKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_56", HFILL }},
{ &hf_ranap_radioNetwork,
{ "radioNetwork", "ranap.radioNetwork",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ranap_CauseRadioNetwork_vals_ext, 0,
"CauseRadioNetwork", HFILL }},
{ &hf_ranap_transmissionNetwork,
{ "transmissionNetwork", "ranap.transmissionNetwork",
FT_UINT32, BASE_DEC, VALS(ranap_CauseTransmissionNetwork_vals), 0,
"CauseTransmissionNetwork", HFILL }},
{ &hf_ranap_nAS,
{ "nAS", "ranap.nAS",
FT_UINT32, BASE_DEC, VALS(ranap_CauseNAS_vals), 0,
"CauseNAS", HFILL }},
{ &hf_ranap_protocol,
{ "protocol", "ranap.protocol",
FT_UINT32, BASE_DEC, VALS(ranap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_ranap_misc,
{ "misc", "ranap.misc",
FT_UINT32, BASE_DEC, VALS(ranap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_ranap_non_Standard,
{ "non-Standard", "ranap.non_Standard",
FT_UINT32, BASE_DEC, NULL, 0,
"CauseNon_Standard", HFILL }},
{ &hf_ranap_radioNetworkExtension,
{ "radioNetworkExtension", "ranap.radioNetworkExtension",
FT_UINT32, BASE_DEC, VALS(ranap_CauseRadioNetworkExtension_vals), 0,
"CauseRadioNetworkExtension", HFILL }},
{ &hf_ranap_cellIdList,
{ "cellIdList", "ranap.cellIdList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CellIdList_item,
{ "Cell-Id", "ranap.Cell_Id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cell_Capacity_Class_Value,
{ "cell-Capacity-Class-Value", "ranap.cell_Capacity_Class_Value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_loadValue,
{ "loadValue", "ranap.loadValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rTLoadValue,
{ "rTLoadValue", "ranap.rTLoadValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_nRTLoadInformationValue,
{ "nRTLoadInformationValue", "ranap.nRTLoadInformationValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sourceCellID,
{ "sourceCellID", "ranap.sourceCellID",
FT_UINT32, BASE_DEC, VALS(ranap_SourceCellID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_uplinkCellLoadInformation,
{ "uplinkCellLoadInformation", "ranap.uplinkCellLoadInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellLoadInformation", HFILL }},
{ &hf_ranap_downlinkCellLoadInformation,
{ "downlinkCellLoadInformation", "ranap.downlinkCellLoadInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellLoadInformation", HFILL }},
{ &hf_ranap_procedureCode,
{ "procedureCode", "ranap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ranap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_ranap_triggeringMessage,
{ "triggeringMessage", "ranap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(ranap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_ranap_procedureCriticality,
{ "procedureCriticality", "ranap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(ranap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_ranap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "ranap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_ranap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "ranap.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iECriticality,
{ "iECriticality", "ranap.iECriticality",
FT_UINT32, BASE_DEC, VALS(ranap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_ranap_iE_ID,
{ "iE-ID", "ranap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ranap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_ranap_repetitionNumber,
{ "repetitionNumber", "ranap.repetitionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"RepetitionNumber0", HFILL }},
{ &hf_ranap_MessageStructure_item,
{ "MessageStructure item", "ranap.MessageStructure_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_item_repetitionNumber,
{ "repetitionNumber", "ranap.repetitionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"RepetitionNumber1", HFILL }},
{ &hf_ranap_lAC,
{ "lAC", "ranap.lAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cI,
{ "cI", "ranap.cI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_CSG_Id_List_item,
{ "CSG-Id", "ranap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_newRAListofIdleModeUEs,
{ "newRAListofIdleModeUEs", "ranap.newRAListofIdleModeUEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAListwithNoIdleModeUEsAnyMore,
{ "rAListwithNoIdleModeUEsAnyMore", "ranap.rAListwithNoIdleModeUEsAnyMore",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_NewRAListofIdleModeUEs_item,
{ "RAC", "ranap.RAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAListwithNoIdleModeUEsAnyMore_item,
{ "RAC", "ranap.RAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_macroENB_ID,
{ "macroENB-ID", "ranap.macroENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_ranap_homeENB_ID,
{ "homeENB-ID", "ranap.homeENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_ranap_short_macroENB_ID,
{ "short-macroENB-ID", "ranap.short_macroENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_18", HFILL }},
{ &hf_ranap_long_macroENB_ID,
{ "long-macroENB-ID", "ranap.long_macroENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_21", HFILL }},
{ &hf_ranap_permittedAlgorithms,
{ "permittedAlgorithms", "ranap.permittedAlgorithms",
FT_UINT32, BASE_DEC, NULL, 0,
"PermittedEncryptionAlgorithms", HFILL }},
{ &hf_ranap_key,
{ "key", "ranap.key",
FT_BYTES, BASE_NONE, NULL, 0,
"EncryptionKey", HFILL }},
{ &hf_ranap_iMEIlist,
{ "iMEIlist", "ranap.iMEIlist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEISVlist,
{ "iMEISVlist", "ranap.iMEISVlist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEIgroup,
{ "iMEIgroup", "ranap.iMEIgroup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEISVgroup,
{ "iMEISVgroup", "ranap.iMEISVgroup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_measurementQuantity,
{ "measurementQuantity", "ranap.measurementQuantity",
FT_UINT32, BASE_DEC, VALS(ranap_MeasurementQuantity_vals), 0,
NULL, HFILL }},
{ &hf_ranap_threshold,
{ "threshold", "ranap.threshold",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M120_165", HFILL }},
{ &hf_ranap_threshold_01,
{ "threshold", "ranap.threshold",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M120_M25", HFILL }},
{ &hf_ranap_GANSS_PositioningDataSet_item,
{ "GANSS-PositioningMethodAndUsage", "ranap.GANSS_PositioningMethodAndUsage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_point,
{ "point", "ranap.point_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_Point", HFILL }},
{ &hf_ranap_pointWithUnCertainty,
{ "pointWithUnCertainty", "ranap.pointWithUnCertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_PointWithUnCertainty", HFILL }},
{ &hf_ranap_polygon,
{ "polygon", "ranap.polygon",
FT_UINT32, BASE_DEC, NULL, 0,
"GA_Polygon", HFILL }},
{ &hf_ranap_pointWithUncertaintyEllipse,
{ "pointWithUncertaintyEllipse", "ranap.pointWithUncertaintyEllipse_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_PointWithUnCertaintyEllipse", HFILL }},
{ &hf_ranap_pointWithAltitude,
{ "pointWithAltitude", "ranap.pointWithAltitude_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_PointWithAltitude", HFILL }},
{ &hf_ranap_pointWithAltitudeAndUncertaintyEllipsoid,
{ "pointWithAltitudeAndUncertaintyEllipsoid", "ranap.pointWithAltitudeAndUncertaintyEllipsoid_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_PointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_ranap_ellipsoidArc,
{ "ellipsoidArc", "ranap.ellipsoidArc_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_EllipsoidArc", HFILL }},
{ &hf_ranap_latitudeSign,
{ "latitudeSign", "ranap.latitudeSign",
FT_UINT32, BASE_DEC, VALS(ranap_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_ranap_latitude,
{ "latitude", "ranap.latitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_ranap_longitude,
{ "longitude", "ranap.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_ranap_directionOfAltitude,
{ "directionOfAltitude", "ranap.directionOfAltitude",
FT_UINT32, BASE_DEC, VALS(ranap_T_directionOfAltitude_vals), 0,
NULL, HFILL }},
{ &hf_ranap_altitude,
{ "altitude", "ranap.altitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_ranap_geographicalCoordinates,
{ "geographicalCoordinates", "ranap.geographicalCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_innerRadius,
{ "innerRadius", "ranap.innerRadius",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ranap_uncertaintyRadius,
{ "uncertaintyRadius", "ranap.uncertaintyRadius",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_offsetAngle,
{ "offsetAngle", "ranap.offsetAngle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_ranap_includedAngle,
{ "includedAngle", "ranap.includedAngle",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_ranap_confidence,
{ "confidence", "ranap.confidence",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_altitudeAndDirection,
{ "altitudeAndDirection", "ranap.altitudeAndDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_AltitudeAndDirection", HFILL }},
{ &hf_ranap_uncertaintyEllipse,
{ "uncertaintyEllipse", "ranap.uncertaintyEllipse_element",
FT_NONE, BASE_NONE, NULL, 0,
"GA_UncertaintyEllipse", HFILL }},
{ &hf_ranap_uncertaintyAltitude,
{ "uncertaintyAltitude", "ranap.uncertaintyAltitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_uncertaintyCode,
{ "uncertaintyCode", "ranap.uncertaintyCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_GA_Polygon_item,
{ "GA-Polygon item", "ranap.GA_Polygon_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uncertaintySemi_major,
{ "uncertaintySemi-major", "ranap.uncertaintySemi_major",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_uncertaintySemi_minor,
{ "uncertaintySemi-minor", "ranap.uncertaintySemi_minor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_orientationOfMajorAxis,
{ "orientationOfMajorAxis", "ranap.orientationOfMajorAxis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_179", HFILL }},
{ &hf_ranap_lAI,
{ "lAI", "ranap.lAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAC,
{ "rAC", "ranap.rAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cN_ID,
{ "cN-ID", "ranap.cN_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rNC_ID,
{ "rNC-ID", "ranap.rNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEI,
{ "iMEI", "ranap.iMEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEIMask,
{ "iMEIMask", "ranap.iMEIMask",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_7", HFILL }},
{ &hf_ranap_IMEIList_item,
{ "IMEI", "ranap.IMEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEISV,
{ "iMEISV", "ranap.iMEISV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iMEISVMask,
{ "iMEISVMask", "ranap.iMEISVMask",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_7", HFILL }},
{ &hf_ranap_IMEISVList_item,
{ "IMEISV", "ranap.IMEISV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_measurementsToActivate,
{ "measurementsToActivate", "ranap.measurementsToActivate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_m1report,
{ "m1report", "ranap.m1report",
FT_UINT32, BASE_DEC, VALS(ranap_M1Report_vals), 0,
NULL, HFILL }},
{ &hf_ranap_m2report,
{ "m2report", "ranap.m2report",
FT_UINT32, BASE_DEC, VALS(ranap_M2Report_vals), 0,
NULL, HFILL }},
{ &hf_ranap_requestedMBMSIPMulticastAddressandAPNRequest,
{ "requestedMBMSIPMulticastAddressandAPNRequest", "ranap.requestedMBMSIPMulticastAddressandAPNRequest",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_requestedMulticastServiceList,
{ "requestedMulticastServiceList", "ranap.requestedMulticastServiceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_mBMSIPMulticastAddressandAPNRequest,
{ "mBMSIPMulticastAddressandAPNRequest", "ranap.mBMSIPMulticastAddressandAPNRequest",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_permanentNAS_UE_ID,
{ "permanentNAS-UE-ID", "ranap.permanentNAS_UE_ID",
FT_UINT32, BASE_DEC, VALS(ranap_PermanentNAS_UE_ID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_rNCTraceInformation,
{ "rNCTraceInformation", "ranap.rNCTraceInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_permittedAlgorithms_01,
{ "permittedAlgorithms", "ranap.permittedAlgorithms",
FT_UINT32, BASE_DEC, NULL, 0,
"PermittedIntegrityProtectionAlgorithms", HFILL }},
{ &hf_ranap_key_01,
{ "key", "ranap.key",
FT_BYTES, BASE_NONE, NULL, 0,
"IntegrityProtectionKey", HFILL }},
{ &hf_ranap_rIM_Transfer,
{ "rIM-Transfer", "ranap.rIM_Transfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_gTP_TEI,
{ "gTP-TEI", "ranap.gTP_TEI",
FT_UINT32, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_bindingID,
{ "bindingID", "ranap.bindingID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LA_LIST_item,
{ "LA-LIST item", "ranap.LA_LIST_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_listOF_SNAs,
{ "listOF-SNAs", "ranap.listOF_SNAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ageOfSAI,
{ "ageOfSAI", "ranap.ageOfSAI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_ranap_uTRAN_CellID,
{ "uTRAN-CellID", "ranap.uTRAN_CellID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cellType,
{ "cellType", "ranap.cellType",
FT_UINT32, BASE_DEC, VALS(ranap_CellType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_time_UE_StayedInCell,
{ "time-UE-StayedInCell", "ranap.time_UE_StayedInCell",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ListOF_SNAs_item,
{ "SNAC", "ranap.SNAC",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ListOfInterfacesToTrace_item,
{ "InterfacesToTraceItem", "ranap.InterfacesToTraceItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_interface,
{ "interface", "ranap.interface",
FT_UINT32, BASE_DEC, VALS(ranap_T_interface_vals), 0,
NULL, HFILL }},
{ &hf_ranap_requestedLocationRelatedDataType,
{ "requestedLocationRelatedDataType", "ranap.requestedLocationRelatedDataType",
FT_UINT32, BASE_DEC, VALS(ranap_RequestedLocationRelatedDataType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_requestedGPSAssistanceData,
{ "requestedGPSAssistanceData", "ranap.requestedGPSAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_reportChangeOfSAI,
{ "reportChangeOfSAI", "ranap.reportChangeOfSAI",
FT_UINT32, BASE_DEC, VALS(ranap_ReportChangeOfSAI_vals), 0,
NULL, HFILL }},
{ &hf_ranap_periodicReportingIndicator,
{ "periodicReportingIndicator", "ranap.periodicReportingIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_PeriodicReportingIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_directReportingIndicator,
{ "directReportingIndicator", "ranap.directReportingIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_DirectReportingIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_verticalAccuracyCode,
{ "verticalAccuracyCode", "ranap.verticalAccuracyCode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_positioningPriorityChangeSAI,
{ "positioningPriorityChangeSAI", "ranap.positioningPriorityChangeSAI",
FT_UINT32, BASE_DEC, VALS(ranap_PositioningPriority_vals), 0,
"PositioningPriority", HFILL }},
{ &hf_ranap_positioningPriorityDirect,
{ "positioningPriorityDirect", "ranap.positioningPriorityDirect",
FT_UINT32, BASE_DEC, VALS(ranap_PositioningPriority_vals), 0,
"PositioningPriority", HFILL }},
{ &hf_ranap_clientTypePeriodic,
{ "clientTypePeriodic", "ranap.clientTypePeriodic",
FT_UINT32, BASE_DEC, VALS(ranap_ClientType_vals), 0,
"ClientType", HFILL }},
{ &hf_ranap_clientTypeDirect,
{ "clientTypeDirect", "ranap.clientTypeDirect",
FT_UINT32, BASE_DEC, VALS(ranap_ClientType_vals), 0,
"ClientType", HFILL }},
{ &hf_ranap_responseTime,
{ "responseTime", "ranap.responseTime",
FT_UINT32, BASE_DEC, VALS(ranap_ResponseTime_vals), 0,
NULL, HFILL }},
{ &hf_ranap_includeVelocity,
{ "includeVelocity", "ranap.includeVelocity",
FT_UINT32, BASE_DEC, VALS(ranap_IncludeVelocity_vals), 0,
NULL, HFILL }},
{ &hf_ranap_periodicLocationInfo,
{ "periodicLocationInfo", "ranap.periodicLocationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_periodic,
{ "periodic", "ranap.periodic_element",
FT_NONE, BASE_NONE, NULL, 0,
"MDT_Report_Parameters", HFILL }},
{ &hf_ranap_event1F,
{ "event1F", "ranap.event1F_element",
FT_NONE, BASE_NONE, NULL, 0,
"Event1F_Parameters", HFILL }},
{ &hf_ranap_event1I,
{ "event1I", "ranap.event1I_element",
FT_NONE, BASE_NONE, NULL, 0,
"Event1I_Parameters", HFILL }},
{ &hf_ranap_all,
{ "all", "ranap.all_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_m4_collection_parameters,
{ "m4-collection-parameters", "ranap.m4_collection_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_m4_period,
{ "m4-period", "ranap.m4_period",
FT_UINT32, BASE_DEC, VALS(ranap_M4_Period_vals), 0,
NULL, HFILL }},
{ &hf_ranap_m4_threshold,
{ "m4-threshold", "ranap.m4_threshold",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_when_available,
{ "when-available", "ranap.when_available_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_m5_period,
{ "m5-period", "ranap.m5_period",
FT_UINT32, BASE_DEC, VALS(ranap_M5_Period_vals), 0,
NULL, HFILL }},
{ &hf_ranap_m6_period,
{ "m6-period", "ranap.m6_period",
FT_UINT32, BASE_DEC, VALS(ranap_M6_Period_vals), 0,
NULL, HFILL }},
{ &hf_ranap_m6_links_to_log,
{ "m6-links-to-log", "ranap.m6_links_to_log",
FT_UINT32, BASE_DEC, VALS(ranap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_ranap_m7_period,
{ "m7-period", "ranap.m7_period",
FT_UINT32, BASE_DEC, VALS(ranap_M7_Period_vals), 0,
NULL, HFILL }},
{ &hf_ranap_m7_links_to_log,
{ "m7-links-to-log", "ranap.m7_links_to_log",
FT_UINT32, BASE_DEC, VALS(ranap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_ranap_MBMSIPMulticastAddressandAPNRequest_item,
{ "TMGI", "ranap.TMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_plmn_area_based_01,
{ "plmn-area-based", "ranap.plmn_area_based_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_mdtActivation,
{ "mdtActivation", "ranap.mdtActivation",
FT_UINT32, BASE_DEC, VALS(ranap_MDT_Activation_vals), 0,
"MDT_Activation", HFILL }},
{ &hf_ranap_mdtAreaScope,
{ "mdtAreaScope", "ranap.mdtAreaScope",
FT_UINT32, BASE_DEC, VALS(ranap_MDTAreaScope_vals), 0,
NULL, HFILL }},
{ &hf_ranap_mdtMode,
{ "mdtMode", "ranap.mdtMode",
FT_UINT32, BASE_DEC, VALS(ranap_MDTMode_vals), 0,
NULL, HFILL }},
{ &hf_ranap_immediateMDT,
{ "immediateMDT", "ranap.immediateMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_loggedMDT,
{ "loggedMDT", "ranap.loggedMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_MDT_PLMN_List_item,
{ "PLMNidentity", "ranap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_reportInterval,
{ "reportInterval", "ranap.reportInterval",
FT_UINT32, BASE_DEC, VALS(ranap_ReportInterval_vals), 0,
NULL, HFILL }},
{ &hf_ranap_reportAmount,
{ "reportAmount", "ranap.reportAmount",
FT_UINT32, BASE_DEC, VALS(ranap_ReportAmount_vals), 0,
NULL, HFILL }},
{ &hf_ranap_accessPointName,
{ "accessPointName", "ranap.accessPointName",
FT_BYTES, BASE_NONE, NULL, 0,
"Offload_RAB_Parameters_APN", HFILL }},
{ &hf_ranap_chargingCharacteristics,
{ "chargingCharacteristics", "ranap.chargingCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
"Offload_RAB_Parameters_ChargingCharacteristics", HFILL }},
{ &hf_ranap_rAI,
{ "rAI", "ranap.rAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PDP_TypeInformation_item,
{ "PDP-Type", "ranap.PDP_Type",
FT_UINT32, BASE_DEC, VALS(ranap_PDP_Type_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PDP_TypeInformation_extension_item,
{ "PDP-Type-extension", "ranap.PDP_Type_extension",
FT_UINT32, BASE_DEC, VALS(ranap_PDP_Type_extension_vals), 0,
NULL, HFILL }},
{ &hf_ranap_reportingAmount,
{ "reportingAmount", "ranap.reportingAmount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8639999_", HFILL }},
{ &hf_ranap_reportingInterval,
{ "reportingInterval", "ranap.reportingInterval",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8639999_", HFILL }},
{ &hf_ranap_iMSI,
{ "iMSI", "ranap.iMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PermittedEncryptionAlgorithms_item,
{ "EncryptionAlgorithm", "ranap.EncryptionAlgorithm",
FT_UINT32, BASE_DEC, VALS(ranap_EncryptionAlgorithm_vals), 0,
NULL, HFILL }},
{ &hf_ranap_PermittedIntegrityProtectionAlgorithms_item,
{ "IntegrityProtectionAlgorithm", "ranap.IntegrityProtectionAlgorithm",
FT_UINT32, BASE_DEC, VALS(ranap_IntegrityProtectionAlgorithm_vals), 0,
NULL, HFILL }},
{ &hf_ranap_laiList,
{ "laiList", "ranap.laiList",
FT_UINT32, BASE_DEC, NULL, 0,
"LAI_List", HFILL }},
{ &hf_ranap_LAI_List_item,
{ "LAI", "ranap.LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_loggingInterval,
{ "loggingInterval", "ranap.loggingInterval",
FT_UINT32, BASE_DEC, VALS(ranap_LoggingInterval_vals), 0,
NULL, HFILL }},
{ &hf_ranap_loggingDuration,
{ "loggingDuration", "ranap.loggingDuration",
FT_UINT32, BASE_DEC, VALS(ranap_LoggingDuration_vals), 0,
NULL, HFILL }},
{ &hf_ranap_plmnList,
{ "plmnList", "ranap.plmnList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PLMNList_item,
{ "PLMNidentity", "ranap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PLMNs_in_shared_network_item,
{ "PLMNs-in-shared-network item", "ranap.PLMNs_in_shared_network_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_lA_LIST,
{ "lA-LIST", "ranap.lA_LIST",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_PositioningDataSet_item,
{ "PositioningMethodAndUsage", "ranap.PositioningMethodAndUsage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_positioningDataDiscriminator,
{ "positioningDataDiscriminator", "ranap.positioningDataDiscriminator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_positioningDataSet,
{ "positioningDataSet", "ranap.positioningDataSet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_shared_network_information,
{ "shared-network-information", "ranap.shared_network_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_raiList,
{ "raiList", "ranap.raiList",
FT_UINT32, BASE_DEC, NULL, 0,
"RAI_List", HFILL }},
{ &hf_ranap_RAI_List_item,
{ "RAI", "ranap.RAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RABDataVolumeReport_item,
{ "RABDataVolumeReport item", "ranap.RABDataVolumeReport_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dl_UnsuccessfullyTransmittedDataVolume,
{ "dl-UnsuccessfullyTransmittedDataVolume", "ranap.dl_UnsuccessfullyTransmittedDataVolume",
FT_UINT32, BASE_DEC, NULL, 0,
"UnsuccessfullyTransmittedDataVolume", HFILL }},
{ &hf_ranap_dataVolumeReference,
{ "dataVolumeReference", "ranap.dataVolumeReference",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList_item,
{ "ExtendedGuaranteedBitrate", "ranap.ExtendedGuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_ExtendedMaxBitrateList_item,
{ "ExtendedMaxBitrate", "ranap.ExtendedMaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_GuaranteedBitrateList_item,
{ "GuaranteedBitrate", "ranap.GuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_Parameter_MaxBitrateList_item,
{ "MaxBitrate", "ranap.MaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_trafficClass,
{ "trafficClass", "ranap.trafficClass",
FT_UINT32, BASE_DEC, VALS(ranap_TrafficClass_vals), 0,
NULL, HFILL }},
{ &hf_ranap_rAB_AsymmetryIndicator,
{ "rAB-AsymmetryIndicator", "ranap.rAB_AsymmetryIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_RAB_AsymmetryIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_maxBitrate,
{ "maxBitrate", "ranap.maxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
"RAB_Parameter_MaxBitrateList", HFILL }},
{ &hf_ranap_guaranteedBitRate,
{ "guaranteedBitRate", "ranap.guaranteedBitRate",
FT_UINT32, BASE_DEC, NULL, 0,
"RAB_Parameter_GuaranteedBitrateList", HFILL }},
{ &hf_ranap_deliveryOrder,
{ "deliveryOrder", "ranap.deliveryOrder",
FT_UINT32, BASE_DEC, VALS(ranap_DeliveryOrder_vals), 0,
NULL, HFILL }},
{ &hf_ranap_maxSDU_Size,
{ "maxSDU-Size", "ranap.maxSDU_Size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sDU_Parameters,
{ "sDU-Parameters", "ranap.sDU_Parameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transferDelay,
{ "transferDelay", "ranap.transferDelay",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_trafficHandlingPriority,
{ "trafficHandlingPriority", "ranap.trafficHandlingPriority",
FT_UINT32, BASE_DEC, VALS(ranap_TrafficHandlingPriority_vals), 0,
NULL, HFILL }},
{ &hf_ranap_allocationOrRetentionPriority,
{ "allocationOrRetentionPriority", "ranap.allocationOrRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sourceStatisticsDescriptor,
{ "sourceStatisticsDescriptor", "ranap.sourceStatisticsDescriptor",
FT_UINT32, BASE_DEC, VALS(ranap_SourceStatisticsDescriptor_vals), 0,
NULL, HFILL }},
{ &hf_ranap_relocationRequirement,
{ "relocationRequirement", "ranap.relocationRequirement",
FT_UINT32, BASE_DEC, VALS(ranap_RelocationRequirement_vals), 0,
NULL, HFILL }},
{ &hf_ranap_RABParametersList_item,
{ "RABParametersList item", "ranap.RABParametersList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rab_Id,
{ "rab-Id", "ranap.rab_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cn_domain,
{ "cn-domain", "ranap.cn_domain",
FT_UINT32, BASE_DEC, VALS(ranap_CN_DomainIndicator_vals), 0,
"CN_DomainIndicator", HFILL }},
{ &hf_ranap_rabDataVolumeReport,
{ "rabDataVolumeReport", "ranap.rabDataVolumeReport",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_upInformation,
{ "upInformation", "ranap.upInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAB_TrCH_Mapping_item,
{ "RAB-TrCH-MappingItem", "ranap.RAB_TrCH_MappingItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAB_ID,
{ "rAB-ID", "ranap.rAB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_trCH_ID_List,
{ "trCH-ID-List", "ranap.trCH_ID_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_notEmptyRAListofIdleModeUEs,
{ "notEmptyRAListofIdleModeUEs", "ranap.notEmptyRAListofIdleModeUEs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_emptyFullRAListofIdleModeUEs,
{ "emptyFullRAListofIdleModeUEs", "ranap.emptyFullRAListofIdleModeUEs",
FT_UINT32, BASE_DEC, VALS(ranap_T_emptyFullRAListofIdleModeUEs_vals), 0,
NULL, HFILL }},
{ &hf_ranap_rAofIdleModeUEs,
{ "rAofIdleModeUEs", "ranap.rAofIdleModeUEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RAofIdleModeUEs_item,
{ "RAC", "ranap.RAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_LAListofIdleModeUEs_item,
{ "LAI", "ranap.LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RequestedMBMSIPMulticastAddressandAPNRequest_item,
{ "MBMSIPMulticastAddressandAPNlist", "ranap.MBMSIPMulticastAddressandAPNlist_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_tMGI,
{ "tMGI", "ranap.tMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iPMulticastAddress,
{ "iPMulticastAddress", "ranap.iPMulticastAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_aPN,
{ "aPN", "ranap.aPN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_RequestedMulticastServiceList_item,
{ "TMGI", "ranap.TMGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_requestedMaxBitrates,
{ "requestedMaxBitrates", "ranap.requestedMaxBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Requested_RAB_Parameter_MaxBitrateList", HFILL }},
{ &hf_ranap_requestedGuaranteedBitrates,
{ "requestedGuaranteedBitrates", "ranap.requestedGuaranteedBitrates",
FT_UINT32, BASE_DEC, NULL, 0,
"Requested_RAB_Parameter_GuaranteedBitrateList", HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList_item,
{ "ExtendedMaxBitrate", "ranap.ExtendedMaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_item,
{ "ExtendedGuaranteedBitrate", "ranap.ExtendedGuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_MaxBitrateList_item,
{ "MaxBitrate", "ranap.MaxBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_Requested_RAB_Parameter_GuaranteedBitrateList_item,
{ "GuaranteedBitrate", "ranap.GuaranteedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_event,
{ "event", "ranap.event",
FT_UINT32, BASE_DEC, VALS(ranap_Event_vals), 0,
NULL, HFILL }},
{ &hf_ranap_reportArea,
{ "reportArea", "ranap.reportArea",
FT_UINT32, BASE_DEC, VALS(ranap_ReportArea_vals), 0,
NULL, HFILL }},
{ &hf_ranap_accuracyCode,
{ "accuracyCode", "ranap.accuracyCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_ranap_mantissa,
{ "mantissa", "ranap.mantissa",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_9", HFILL }},
{ &hf_ranap_exponent,
{ "exponent", "ranap.exponent",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_ranap_rIMInformation,
{ "rIMInformation", "ranap.rIMInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rIMRoutingAddress,
{ "rIMRoutingAddress", "ranap.rIMRoutingAddress",
FT_UINT32, BASE_DEC, VALS(ranap_RIMRoutingAddress_vals), 0,
NULL, HFILL }},
{ &hf_ranap_targetRNC_ID,
{ "targetRNC-ID", "ranap.targetRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_gERAN_Cell_ID,
{ "gERAN-Cell-ID", "ranap.gERAN_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_targeteNB_ID,
{ "targeteNB-ID", "ranap.targeteNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_traceActivationIndicator,
{ "traceActivationIndicator", "ranap.traceActivationIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_T_traceActivationIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_equipmentsToBeTraced,
{ "equipmentsToBeTraced", "ranap.equipmentsToBeTraced",
FT_UINT32, BASE_DEC, VALS(ranap_EquipmentsToBeTraced_vals), 0,
NULL, HFILL }},
{ &hf_ranap_rabParmetersList,
{ "rabParmetersList", "ranap.rabParmetersList",
FT_UINT32, BASE_DEC, NULL, 0,
"RABParametersList", HFILL }},
{ &hf_ranap_locationReporting,
{ "locationReporting", "ranap.locationReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"LocationReportingTransferInformation", HFILL }},
{ &hf_ranap_traceInformation,
{ "traceInformation", "ranap.traceInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sourceSAI,
{ "sourceSAI", "ranap.sourceSAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"SAI", HFILL }},
{ &hf_ranap_nonce,
{ "nonce", "ranap.nonce",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_128", HFILL }},
{ &hf_ranap_iMSInformation,
{ "iMSInformation", "ranap.iMSInformation",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1_maxSizeOfIMSInfo", HFILL }},
{ &hf_ranap_sAC,
{ "sAC", "ranap.sAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_pLMNs_in_shared_network,
{ "pLMNs-in-shared-network", "ranap.pLMNs_in_shared_network",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_exponent_1_8,
{ "exponent", "ranap.exponent",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_6", HFILL }},
{ &hf_ranap_SDU_FormatInformationParameters_item,
{ "SDU-FormatInformationParameters item", "ranap.SDU_FormatInformationParameters_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_subflowSDU_Size,
{ "subflowSDU-Size", "ranap.subflowSDU_Size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAB_SubflowCombinationBitRate,
{ "rAB-SubflowCombinationBitRate", "ranap.rAB_SubflowCombinationBitRate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_SDU_Parameters_item,
{ "SDU-Parameters item", "ranap.SDU_Parameters_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sDU_ErrorRatio,
{ "sDU-ErrorRatio", "ranap.sDU_ErrorRatio_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_residualBitErrorRatio,
{ "residualBitErrorRatio", "ranap.residualBitErrorRatio_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_deliveryOfErroneousSDU,
{ "deliveryOfErroneousSDU", "ranap.deliveryOfErroneousSDU",
FT_UINT32, BASE_DEC, VALS(ranap_DeliveryOfErroneousSDU_vals), 0,
NULL, HFILL }},
{ &hf_ranap_sDU_FormatInformationParameters,
{ "sDU-FormatInformationParameters", "ranap.sDU_FormatInformationParameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_null_NRI,
{ "null-NRI", "ranap.null_NRI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sGSN_Group_ID,
{ "sGSN-Group-ID", "ranap.sGSN_Group_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_authorisedPLMNs,
{ "authorisedPLMNs", "ranap.authorisedPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sourceUTRANCellID,
{ "sourceUTRANCellID", "ranap.sourceUTRANCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sourceGERANCellID,
{ "sourceGERANCellID", "ranap.sourceGERANCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
"CGI", HFILL }},
{ &hf_ranap_sourceRNC_ID,
{ "sourceRNC-ID", "ranap.sourceRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rRC_Container,
{ "rRC-Container", "ranap.rRC_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_numberOfIuInstances,
{ "numberOfIuInstances", "ranap.numberOfIuInstances",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_relocationType,
{ "relocationType", "ranap.relocationType",
FT_UINT32, BASE_DEC, VALS(ranap_RelocationType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_chosenIntegrityProtectionAlgorithm,
{ "chosenIntegrityProtectionAlgorithm", "ranap.chosenIntegrityProtectionAlgorithm",
FT_UINT32, BASE_DEC, VALS(ranap_IntegrityProtectionAlgorithm_vals), 0,
NULL, HFILL }},
{ &hf_ranap_integrityProtectionKey,
{ "integrityProtectionKey", "ranap.integrityProtectionKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_chosenEncryptionAlgorithForSignalling,
{ "chosenEncryptionAlgorithForSignalling", "ranap.chosenEncryptionAlgorithForSignalling",
FT_UINT32, BASE_DEC, VALS(ranap_EncryptionAlgorithm_vals), 0,
"ChosenEncryptionAlgorithm", HFILL }},
{ &hf_ranap_cipheringKey,
{ "cipheringKey", "ranap.cipheringKey",
FT_BYTES, BASE_NONE, NULL, 0,
"EncryptionKey", HFILL }},
{ &hf_ranap_chosenEncryptionAlgorithForCS,
{ "chosenEncryptionAlgorithForCS", "ranap.chosenEncryptionAlgorithForCS",
FT_UINT32, BASE_DEC, VALS(ranap_EncryptionAlgorithm_vals), 0,
"ChosenEncryptionAlgorithm", HFILL }},
{ &hf_ranap_chosenEncryptionAlgorithForPS,
{ "chosenEncryptionAlgorithForPS", "ranap.chosenEncryptionAlgorithForPS",
FT_UINT32, BASE_DEC, VALS(ranap_EncryptionAlgorithm_vals), 0,
"ChosenEncryptionAlgorithm", HFILL }},
{ &hf_ranap_d_RNTI,
{ "d-RNTI", "ranap.d_RNTI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_targetCellId,
{ "targetCellId", "ranap.targetCellId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAB_TrCH_Mapping,
{ "rAB-TrCH-Mapping", "ranap.rAB_TrCH_Mapping",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rSRP,
{ "rSRP", "ranap.rSRP",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_97", HFILL }},
{ &hf_ranap_rSRQ,
{ "rSRQ", "ranap.rSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_34", HFILL }},
{ &hf_ranap_iRATmeasurementParameters,
{ "iRATmeasurementParameters", "ranap.iRATmeasurementParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_measurementDuration,
{ "measurementDuration", "ranap.measurementDuration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_100", HFILL }},
{ &hf_ranap_eUTRANFrequencies,
{ "eUTRANFrequencies", "ranap.eUTRANFrequencies",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_allSymbols,
{ "allSymbols", "ranap.allSymbols",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ranap_wideBand,
{ "wideBand", "ranap.wideBand",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ranap_EUTRANFrequencies_item,
{ "EUTRANFrequencies item", "ranap.EUTRANFrequencies_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_earfcn,
{ "earfcn", "ranap.earfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_ranap_measBand,
{ "measBand", "ranap.measBand",
FT_UINT32, BASE_DEC, VALS(ranap_MeasBand_vals), 0,
NULL, HFILL }},
{ &hf_ranap_SupportedRAB_ParameterBitrateList_item,
{ "SupportedBitrate", "ranap.SupportedBitrate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uTRANcellID,
{ "uTRANcellID", "ranap.uTRANcellID",
FT_UINT32, BASE_DEC, NULL, 0,
"TargetCellId", HFILL }},
{ &hf_ranap_SRB_TrCH_Mapping_item,
{ "SRB-TrCH-MappingItem", "ranap.SRB_TrCH_MappingItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sRB_ID,
{ "sRB-ID", "ranap.sRB_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_trCH_ID,
{ "trCH-ID", "ranap.trCH_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_tAC,
{ "tAC", "ranap.tAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cGI,
{ "cGI", "ranap.cGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_eNB_ID,
{ "eNB-ID", "ranap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(ranap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_ranap_selectedTAI,
{ "selectedTAI", "ranap.selectedTAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAI", HFILL }},
{ &hf_ranap_tMSI,
{ "tMSI", "ranap.tMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_p_TMSI,
{ "p-TMSI", "ranap.p_TMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_serviceID,
{ "serviceID", "ranap.serviceID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_ranap_ue_identity,
{ "ue-identity", "ranap.ue_identity",
FT_UINT32, BASE_DEC, VALS(ranap_UE_ID_vals), 0,
"UE_ID", HFILL }},
{ &hf_ranap_traceRecordingSessionReference,
{ "traceRecordingSessionReference", "ranap.traceRecordingSessionReference",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_traceDepth,
{ "traceDepth", "ranap.traceDepth",
FT_UINT32, BASE_DEC, VALS(ranap_TraceDepth_vals), 0,
NULL, HFILL }},
{ &hf_ranap_listOfInterfacesToTrace,
{ "listOfInterfacesToTrace", "ranap.listOfInterfacesToTrace",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dCH_ID,
{ "dCH-ID", "ranap.dCH_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dSCH_ID,
{ "dSCH-ID", "ranap.dSCH_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uSCH_ID,
{ "uSCH-ID", "ranap.uSCH_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_TrCH_ID_List_item,
{ "TrCH-ID", "ranap.TrCH_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddress,
{ "transportLayerAddress", "ranap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uDP_Port_Number,
{ "uDP-Port-Number", "ranap.uDP_Port_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"Port_Number", HFILL }},
{ &hf_ranap_uE_AggregateMaximumBitRateDownlink,
{ "uE-AggregateMaximumBitRateDownlink", "ranap.uE_AggregateMaximumBitRateDownlink",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uE_AggregateMaximumBitRateUplink,
{ "uE-AggregateMaximumBitRateUplink", "ranap.uE_AggregateMaximumBitRateUplink",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_imsi,
{ "imsi", "ranap.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_imei,
{ "imei", "ranap.imei",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_imeisv,
{ "imeisv", "ranap.imeisv",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uE_IsServed,
{ "uE-IsServed", "ranap.uE_IsServed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uE_IsNotServed,
{ "uE-IsNotServed", "ranap.uE_IsNotServed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uESBI_IuA,
{ "uESBI-IuA", "ranap.uESBI_IuA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uESBI_IuB,
{ "uESBI-IuB", "ranap.uESBI_IuB",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_frameSeqNoUL,
{ "frameSeqNoUL", "ranap.frameSeqNoUL",
FT_UINT32, BASE_DEC, NULL, 0,
"FrameSequenceNumber", HFILL }},
{ &hf_ranap_frameSeqNoDL,
{ "frameSeqNoDL", "ranap.frameSeqNoDL",
FT_UINT32, BASE_DEC, NULL, 0,
"FrameSequenceNumber", HFILL }},
{ &hf_ranap_pdu14FrameSeqNoUL,
{ "pdu14FrameSeqNoUL", "ranap.pdu14FrameSeqNoUL",
FT_UINT32, BASE_DEC, NULL, 0,
"PDUType14FrameSequenceNumber", HFILL }},
{ &hf_ranap_pdu14FrameSeqNoDL,
{ "pdu14FrameSeqNoDL", "ranap.pdu14FrameSeqNoDL",
FT_UINT32, BASE_DEC, NULL, 0,
"PDUType14FrameSequenceNumber", HFILL }},
{ &hf_ranap_dataPDUType,
{ "dataPDUType", "ranap.dataPDUType",
FT_UINT32, BASE_DEC, VALS(ranap_DataPDUType_vals), 0,
NULL, HFILL }},
{ &hf_ranap_upinitialisationFrame,
{ "upinitialisationFrame", "ranap.upinitialisationFrame",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cellID,
{ "cellID", "ranap.cellID",
FT_UINT32, BASE_DEC, NULL, 0,
"TargetCellId", HFILL }},
{ &hf_ranap_horizontalVelocity,
{ "horizontalVelocity", "ranap.horizontalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_horizontalWithVerticalVelocity,
{ "horizontalWithVerticalVelocity", "ranap.horizontalWithVerticalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_horizontalVelocityWithUncertainty,
{ "horizontalVelocityWithUncertainty", "ranap.horizontalVelocityWithUncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_horizontalWithVeritcalVelocityAndUncertainty,
{ "horizontalWithVeritcalVelocityAndUncertainty", "ranap.horizontalWithVeritcalVelocityAndUncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
"HorizontalWithVerticalVelocityAndUncertainty", HFILL }},
{ &hf_ranap_horizontalSpeedAndBearing,
{ "horizontalSpeedAndBearing", "ranap.horizontalSpeedAndBearing_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_veritcalVelocity,
{ "veritcalVelocity", "ranap.veritcalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
"VerticalVelocity", HFILL }},
{ &hf_ranap_uncertaintySpeed,
{ "uncertaintySpeed", "ranap.uncertaintySpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ranap_horizontalUncertaintySpeed,
{ "horizontalUncertaintySpeed", "ranap.horizontalUncertaintySpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ranap_verticalUncertaintySpeed,
{ "verticalUncertaintySpeed", "ranap.verticalUncertaintySpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ranap_bearing,
{ "bearing", "ranap.bearing",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_ranap_horizontalSpeed,
{ "horizontalSpeed", "ranap.horizontalSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_ranap_veritcalSpeed,
{ "veritcalSpeed", "ranap.veritcalSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_ranap_veritcalSpeedDirection,
{ "veritcalSpeedDirection", "ranap.veritcalSpeedDirection",
FT_UINT32, BASE_DEC, VALS(ranap_VerticalSpeedDirection_vals), 0,
"VerticalSpeedDirection", HFILL }},
{ &hf_ranap_protocolIEs,
{ "protocolIEs", "ranap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_ranap_protocolExtensions,
{ "protocolExtensions", "ranap.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_ranap_rab_dl_UnsuccessfullyTransmittedDataVolume,
{ "dl-UnsuccessfullyTransmittedDataVolume", "ranap.dl_UnsuccessfullyTransmittedDataVolume",
FT_UINT32, BASE_DEC, NULL, 0,
"DataVolumeList", HFILL }},
{ &hf_ranap_dL_GTP_PDU_SequenceNumber,
{ "dL-GTP-PDU-SequenceNumber", "ranap.dL_GTP_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_uL_GTP_PDU_SequenceNumber,
{ "uL-GTP-PDU-SequenceNumber", "ranap.uL_GTP_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iuTransportAssociation,
{ "iuTransportAssociation", "ranap.iuTransportAssociation",
FT_UINT32, BASE_DEC, VALS(ranap_IuTransportAssociation_vals), 0,
NULL, HFILL }},
{ &hf_ranap_nAS_SynchronisationIndicator,
{ "nAS-SynchronisationIndicator", "ranap.nAS_SynchronisationIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_rAB_Parameters,
{ "rAB-Parameters", "ranap.rAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dataVolumeReportingIndication,
{ "dataVolumeReportingIndication", "ranap.dataVolumeReportingIndication",
FT_UINT32, BASE_DEC, VALS(ranap_DataVolumeReportingIndication_vals), 0,
NULL, HFILL }},
{ &hf_ranap_pDP_TypeInformation,
{ "pDP-TypeInformation", "ranap.pDP_TypeInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_userPlaneInformation,
{ "userPlaneInformation", "ranap.userPlaneInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_service_Handover,
{ "service-Handover", "ranap.service_Handover",
FT_UINT32, BASE_DEC, VALS(ranap_Service_Handover_vals), 0,
NULL, HFILL }},
{ &hf_ranap_userPlaneMode,
{ "userPlaneMode", "ranap.userPlaneMode",
FT_UINT32, BASE_DEC, VALS(ranap_UserPlaneMode_vals), 0,
NULL, HFILL }},
{ &hf_ranap_uP_ModeVersions,
{ "uP-ModeVersions", "ranap.uP_ModeVersions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_joinedMBMSBearerService_IEs,
{ "joinedMBMSBearerService-IEs", "ranap.joinedMBMSBearerService_IEs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_JoinedMBMSBearerService_IEs_item,
{ "JoinedMBMSBearerService-IEs item", "ranap.JoinedMBMSBearerService_IEs_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_mBMS_PTP_RAB_ID,
{ "mBMS-PTP-RAB-ID", "ranap.mBMS_PTP_RAB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_cause,
{ "cause", "ranap.cause",
FT_UINT32, BASE_DEC, VALS(ranap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_ranap_dl_GTP_PDU_SequenceNumber,
{ "dl-GTP-PDU-SequenceNumber", "ranap.dl_GTP_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ul_GTP_PDU_SequenceNumber,
{ "ul-GTP-PDU-SequenceNumber", "ranap.ul_GTP_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dl_N_PDU_SequenceNumber,
{ "dl-N-PDU-SequenceNumber", "ranap.dl_N_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_ul_N_PDU_SequenceNumber,
{ "ul-N-PDU-SequenceNumber", "ranap.ul_N_PDU_SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_iuSigConId,
{ "iuSigConId", "ranap.iuSigConId",
FT_BYTES, BASE_NONE, NULL, 0,
"IuSignallingConnectionIdentifier", HFILL }},
{ &hf_ranap_transportLayerAddressReq1,
{ "transportLayerAddressReq1", "ranap.transportLayerAddressReq1",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_ranap_iuTransportAssociationReq1,
{ "iuTransportAssociationReq1", "ranap.iuTransportAssociationReq1",
FT_UINT32, BASE_DEC, VALS(ranap_IuTransportAssociation_vals), 0,
"IuTransportAssociation", HFILL }},
{ &hf_ranap_ass_RAB_Parameters,
{ "ass-RAB-Parameters", "ranap.ass_RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddressRes1,
{ "transportLayerAddressRes1", "ranap.transportLayerAddressRes1",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_ranap_iuTransportAssociationRes1,
{ "iuTransportAssociationRes1", "ranap.iuTransportAssociationRes1",
FT_UINT32, BASE_DEC, VALS(ranap_IuTransportAssociation_vals), 0,
"IuTransportAssociation", HFILL }},
{ &hf_ranap_rab2beReleasedList,
{ "rab2beReleasedList", "ranap.rab2beReleasedList",
FT_UINT32, BASE_DEC, NULL, 0,
"RAB_ToBeReleasedList_EnhancedRelocCompleteRes", HFILL }},
{ &hf_ranap_transportLayerInformation,
{ "transportLayerInformation", "ranap.transportLayerInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dl_dataVolumes,
{ "dl-dataVolumes", "ranap.dl_dataVolumes",
FT_UINT32, BASE_DEC, NULL, 0,
"DataVolumeList", HFILL }},
{ &hf_ranap_DataVolumeList_item,
{ "DataVolumeList item", "ranap.DataVolumeList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_gERAN_Classmark,
{ "gERAN-Classmark", "ranap.gERAN_Classmark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_privateIEs,
{ "privateIEs", "ranap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_ranap_nAS_PDU,
{ "nAS-PDU", "ranap.nAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_sAPI,
{ "sAPI", "ranap.sAPI",
FT_UINT32, BASE_DEC, VALS(ranap_SAPI_vals), 0,
NULL, HFILL }},
{ &hf_ranap_cN_DomainIndicator,
{ "cN-DomainIndicator", "ranap.cN_DomainIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_CN_DomainIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_dataForwardingInformation,
{ "dataForwardingInformation", "ranap.dataForwardingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"TNLInformationEnhRelInfoReq", HFILL }},
{ &hf_ranap_sourceSideIuULTNLInfo,
{ "sourceSideIuULTNLInfo", "ranap.sourceSideIuULTNLInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"TNLInformationEnhRelInfoReq", HFILL }},
{ &hf_ranap_alt_RAB_Parameters,
{ "alt-RAB-Parameters", "ranap.alt_RAB_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_dataForwardingInformation_01,
{ "dataForwardingInformation", "ranap.dataForwardingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"TNLInformationEnhRelInfoRes", HFILL }},
{ &hf_ranap_dl_forwardingTransportLayerAddress,
{ "dl-forwardingTransportLayerAddress", "ranap.dl_forwardingTransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_ranap_dl_forwardingTransportAssociation,
{ "dl-forwardingTransportAssociation", "ranap.dl_forwardingTransportAssociation",
FT_UINT32, BASE_DEC, VALS(ranap_IuTransportAssociation_vals), 0,
"IuTransportAssociation", HFILL }},
{ &hf_ranap_requested_RAB_Parameter_Values,
{ "requested-RAB-Parameter-Values", "ranap.requested_RAB_Parameter_Values_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_mBMSHCIndicator,
{ "mBMSHCIndicator", "ranap.mBMSHCIndicator",
FT_UINT32, BASE_DEC, VALS(ranap_MBMSHCIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ranap_gTPDLTEID,
{ "gTPDLTEID", "ranap.gTPDLTEID",
FT_UINT32, BASE_HEX_DEC, NULL, 0,
"GTP_TEI", HFILL }},
{ &hf_ranap_LeftMBMSBearerService_IEs_item,
{ "LeftMBMSBearerService-IEs item", "ranap.LeftMBMSBearerService_IEs_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_UnsuccessfulLinking_IEs_item,
{ "UnsuccessfulLinking-IEs item", "ranap.UnsuccessfulLinking_IEs_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_initiatingMessage,
{ "initiatingMessage", "ranap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_successfulOutcome,
{ "successfulOutcome", "ranap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "ranap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_outcome,
{ "outcome", "ranap.outcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_initiatingMessagevalue,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_ranap_successfulOutcome_value,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_ranap_unsuccessfulOutcome_value,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
{ &hf_ranap_value,
{ "value", "ranap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 358 "./asn1/ranap/packet-ranap-template.c"
};
static gint *ett[] = {
&ett_ranap,
&ett_ranap_TransportLayerAddress,
&ett_ranap_TransportLayerAddress_nsap,
#line 1 "./asn1/ranap/packet-ranap-ettarr.c"
&ett_ranap_PrivateIE_ID,
&ett_ranap_ProtocolIE_Container,
&ett_ranap_ProtocolIE_Field,
&ett_ranap_ProtocolIE_ContainerPair,
&ett_ranap_ProtocolIE_FieldPair,
&ett_ranap_ProtocolIE_ContainerList,
&ett_ranap_ProtocolIE_ContainerPairList,
&ett_ranap_ProtocolExtensionContainer,
&ett_ranap_ProtocolExtensionField,
&ett_ranap_PrivateIE_Container,
&ett_ranap_PrivateIE_Field,
&ett_ranap_Additional_CSPS_coordination_information,
&ett_ranap_Additional_PositioningDataSet,
&ett_ranap_AllocationOrRetentionPriority,
&ett_ranap_Alt_RAB_Parameters,
&ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf,
&ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrates,
&ett_ranap_Alt_RAB_Parameter_ExtendedGuaranteedBitrateList,
&ett_ranap_Alt_RAB_Parameter_GuaranteedBitrateInf,
&ett_ranap_Alt_RAB_Parameter_GuaranteedBitrates,
&ett_ranap_Alt_RAB_Parameter_GuaranteedBitrateList,
&ett_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf,
&ett_ranap_Alt_RAB_Parameter_SupportedGuaranteedBitrates,
&ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateInf,
&ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrates,
&ett_ranap_Alt_RAB_Parameter_ExtendedMaxBitrateList,
&ett_ranap_Alt_RAB_Parameter_MaxBitrateInf,
&ett_ranap_Alt_RAB_Parameter_MaxBitrates,
&ett_ranap_Alt_RAB_Parameter_MaxBitrateList,
&ett_ranap_Alt_RAB_Parameter_SupportedMaxBitrateInf,
&ett_ranap_Alt_RAB_Parameter_SupportedMaxBitrates,
&ett_ranap_UE_Application_Layer_Measurement_Configuration,
&ett_ranap_UE_Application_Layer_Measurement_Configuration_For_Relocation,
&ett_ranap_AreaScopeForUEApplicationLayerMeasurementConfiguration,
&ett_ranap_AreaIdentity,
&ett_ranap_Ass_RAB_Parameters,
&ett_ranap_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList,
&ett_ranap_Ass_RAB_Parameter_ExtendedMaxBitrateList,
&ett_ranap_Ass_RAB_Parameter_GuaranteedBitrateList,
&ett_ranap_Ass_RAB_Parameter_MaxBitrateList,
&ett_ranap_AuthorisedPLMNs,
&ett_ranap_AuthorisedPLMNs_item,
&ett_ranap_AuthorisedSNAs,
&ett_ranap_BroadcastAssistanceDataDecipheringKeys,
&ett_ranap_Cause,
&ett_ranap_CellBased,
&ett_ranap_CellIdList,
&ett_ranap_CellLoadInformation,
&ett_ranap_CellLoadInformationGroup,
&ett_ranap_CriticalityDiagnostics,
&ett_ranap_CriticalityDiagnostics_IE_List,
&ett_ranap_CriticalityDiagnostics_IE_List_item,
&ett_ranap_MessageStructure,
&ett_ranap_MessageStructure_item,
&ett_ranap_CGI,
&ett_ranap_CSG_Id_List,
&ett_ranap_DeltaRAListofIdleModeUEs,
&ett_ranap_NewRAListofIdleModeUEs,
&ett_ranap_RAListwithNoIdleModeUEsAnyMore,
&ett_ranap_ENB_ID,
&ett_ranap_EncryptionInformation,
&ett_ranap_EquipmentsToBeTraced,
&ett_ranap_Event1F_Parameters,
&ett_ranap_Event1I_Parameters,
&ett_ranap_GANSS_PositioningDataSet,
&ett_ranap_GeographicalArea,
&ett_ranap_GeographicalCoordinates,
&ett_ranap_GA_AltitudeAndDirection,
&ett_ranap_GA_EllipsoidArc,
&ett_ranap_GA_Point,
&ett_ranap_GA_PointWithAltitude,
&ett_ranap_GA_PointWithAltitudeAndUncertaintyEllipsoid,
&ett_ranap_GA_PointWithUnCertainty,
&ett_ranap_GA_PointWithUnCertaintyEllipse,
&ett_ranap_GA_Polygon,
&ett_ranap_GA_Polygon_item,
&ett_ranap_GA_UncertaintyEllipse,
&ett_ranap_GERAN_Cell_ID,
&ett_ranap_GlobalCN_ID,
&ett_ranap_GlobalRNC_ID,
&ett_ranap_IMEIGroup,
&ett_ranap_IMEIList,
&ett_ranap_IMEISVGroup,
&ett_ranap_IMEISVList,
&ett_ranap_ImmediateMDT,
&ett_ranap_InformationRequested,
&ett_ranap_InformationRequestType,
&ett_ranap_InformationTransferType,
&ett_ranap_IntegrityProtectionInformation,
&ett_ranap_InterSystemInformationTransferType,
&ett_ranap_InterSystemInformation_TransparentContainer,
&ett_ranap_IuTransportAssociation,
&ett_ranap_LA_LIST,
&ett_ranap_LA_LIST_item,
&ett_ranap_LAI,
&ett_ranap_LastKnownServiceArea,
&ett_ranap_LastVisitedUTRANCell_Item,
&ett_ranap_ListOF_SNAs,
&ett_ranap_ListOfInterfacesToTrace,
&ett_ranap_InterfacesToTraceItem,
&ett_ranap_LocationRelatedDataRequestType,
&ett_ranap_LocationReportingTransferInformation,
&ett_ranap_M1Report,
&ett_ranap_M2Report,
&ett_ranap_M4Report,
&ett_ranap_M4_Collection_Parameters,
&ett_ranap_M5Report,
&ett_ranap_M6Report,
&ett_ranap_M7Report,
&ett_ranap_MBMSIPMulticastAddressandAPNRequest,
&ett_ranap_MDTAreaScope,
&ett_ranap_MDT_Configuration,
&ett_ranap_MDTMode,
&ett_ranap_MDT_PLMN_List,
&ett_ranap_MDT_Report_Parameters,
&ett_ranap_Offload_RAB_Parameters,
&ett_ranap_PagingAreaID,
&ett_ranap_PDP_TypeInformation,
&ett_ranap_PDP_TypeInformation_extension,
&ett_ranap_PeriodicLocationInfo,
&ett_ranap_PermanentNAS_UE_ID,
&ett_ranap_PermittedEncryptionAlgorithms,
&ett_ranap_PermittedIntegrityProtectionAlgorithms,
&ett_ranap_LABased,
&ett_ranap_LAI_List,
&ett_ranap_LoggedMDT,
&ett_ranap_PLMNBased,
&ett_ranap_PLMNList,
&ett_ranap_PLMNs_in_shared_network,
&ett_ranap_PLMNs_in_shared_network_item,
&ett_ranap_PositioningDataSet,
&ett_ranap_PositionData,
&ett_ranap_ProvidedData,
&ett_ranap_RABased,
&ett_ranap_RAI_List,
&ett_ranap_RABDataVolumeReport,
&ett_ranap_RABDataVolumeReport_item,
&ett_ranap_RAB_Parameter_ExtendedGuaranteedBitrateList,
&ett_ranap_RAB_Parameter_ExtendedMaxBitrateList,
&ett_ranap_RAB_Parameter_GuaranteedBitrateList,
&ett_ranap_RAB_Parameter_MaxBitrateList,
&ett_ranap_RAB_Parameters,
&ett_ranap_RABParametersList,
&ett_ranap_RABParametersList_item,
&ett_ranap_RAB_TrCH_Mapping,
&ett_ranap_RAB_TrCH_MappingItem,
&ett_ranap_RAI,
&ett_ranap_RAListofIdleModeUEs,
&ett_ranap_NotEmptyRAListofIdleModeUEs,
&ett_ranap_RAofIdleModeUEs,
&ett_ranap_LAListofIdleModeUEs,
&ett_ranap_RequestedMBMSIPMulticastAddressandAPNRequest,
&ett_ranap_MBMSIPMulticastAddressandAPNlist,
&ett_ranap_RequestedMulticastServiceList,
&ett_ranap_Requested_RAB_Parameter_Values,
&ett_ranap_Requested_RAB_Parameter_ExtendedMaxBitrateList,
&ett_ranap_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList,
&ett_ranap_Requested_RAB_Parameter_MaxBitrateList,
&ett_ranap_Requested_RAB_Parameter_GuaranteedBitrateList,
&ett_ranap_RequestType,
&ett_ranap_ResidualBitErrorRatio,
&ett_ranap_RIM_Transfer,
&ett_ranap_RIMRoutingAddress,
&ett_ranap_RNCTraceInformation,
&ett_ranap_RNSAPRelocationParameters,
&ett_ranap_RSRVCC_Information,
&ett_ranap_SAI,
&ett_ranap_Shared_Network_Information,
&ett_ranap_SDU_ErrorRatio,
&ett_ranap_SDU_FormatInformationParameters,
&ett_ranap_SDU_FormatInformationParameters_item,
&ett_ranap_SDU_Parameters,
&ett_ranap_SDU_Parameters_item,
&ett_ranap_SGSN_Group_Identity,
&ett_ranap_SNA_Access_Information,
&ett_ranap_SourceCellID,
&ett_ranap_SourceID,
&ett_ranap_SourceRNC_ID,
&ett_ranap_SourceRNC_ToTargetRNC_TransparentContainer,
&ett_ranap_IRAT_Measurement_Configuration,
&ett_ranap_IRATmeasurementParameters,
&ett_ranap_RSRQ_Type,
&ett_ranap_EUTRANFrequencies,
&ett_ranap_EUTRANFrequencies_item,
&ett_ranap_SupportedRAB_ParameterBitrateList,
&ett_ranap_SourceUTRANCellID,
&ett_ranap_SRB_TrCH_Mapping,
&ett_ranap_SRB_TrCH_MappingItem,
&ett_ranap_SRVCC_Information,
&ett_ranap_TAI,
&ett_ranap_TargetID,
&ett_ranap_TargetENB_ID,
&ett_ranap_TargetRNC_ID,
&ett_ranap_TargetRNC_ToSourceRNC_TransparentContainer,
&ett_ranap_TemporaryUE_ID,
&ett_ranap_TMGI,
&ett_ranap_TraceInformation,
&ett_ranap_TracePropagationParameters,
&ett_ranap_TraceRecordingSessionInformation,
&ett_ranap_TrCH_ID,
&ett_ranap_TrCH_ID_List,
&ett_ranap_TunnelInformation,
&ett_ranap_UE_AggregateMaximumBitRate,
&ett_ranap_UE_ID,
&ett_ranap_UE_IsNotServed,
&ett_ranap_UE_IsServed,
&ett_ranap_UERegistrationQueryResult,
&ett_ranap_UESBI_Iu,
&ett_ranap_UPInformation,
&ett_ranap_UTRAN_CellID,
&ett_ranap_VelocityEstimate,
&ett_ranap_HorizontalVelocity,
&ett_ranap_HorizontalWithVerticalVelocity,
&ett_ranap_HorizontalVelocityWithUncertainty,
&ett_ranap_HorizontalWithVerticalVelocityAndUncertainty,
&ett_ranap_HorizontalSpeedAndBearing,
&ett_ranap_VerticalVelocity,
&ett_ranap_Iu_ReleaseCommand,
&ett_ranap_Iu_ReleaseComplete,
&ett_ranap_RAB_DataVolumeReportItem,
&ett_ranap_RAB_ReleasedItem_IuRelComp,
&ett_ranap_RelocationRequired,
&ett_ranap_RelocationCommand,
&ett_ranap_RAB_RelocationReleaseItem,
&ett_ranap_RAB_DataForwardingItem,
&ett_ranap_RelocationPreparationFailure,
&ett_ranap_RelocationRequest,
&ett_ranap_RAB_SetupItem_RelocReq,
&ett_ranap_UserPlaneInformation,
&ett_ranap_CNMBMSLinkingInformation,
&ett_ranap_JoinedMBMSBearerService_IEs,
&ett_ranap_JoinedMBMSBearerService_IEs_item,
&ett_ranap_RelocationRequestAcknowledge,
&ett_ranap_RAB_SetupItem_RelocReqAck,
&ett_ranap_RAB_FailedItem,
&ett_ranap_RelocationFailure,
&ett_ranap_RelocationCancel,
&ett_ranap_RelocationCancelAcknowledge,
&ett_ranap_SRNS_ContextRequest,
&ett_ranap_RAB_DataForwardingItem_SRNS_CtxReq,
&ett_ranap_SRNS_ContextResponse,
&ett_ranap_RAB_ContextItem,
&ett_ranap_RABs_ContextFailedtoTransferItem,
&ett_ranap_SecurityModeCommand,
&ett_ranap_SecurityModeComplete,
&ett_ranap_SecurityModeReject,
&ett_ranap_DataVolumeReportRequest,
&ett_ranap_RAB_DataVolumeReportRequestItem,
&ett_ranap_DataVolumeReport,
&ett_ranap_RABs_failed_to_reportItem,
&ett_ranap_Reset,
&ett_ranap_ResetAcknowledge,
&ett_ranap_ResetResource,
&ett_ranap_ResetResourceItem,
&ett_ranap_ResetResourceAcknowledge,
&ett_ranap_ResetResourceAckItem,
&ett_ranap_RAB_ReleaseRequest,
&ett_ranap_RAB_ReleaseItem,
&ett_ranap_Iu_ReleaseRequest,
&ett_ranap_RelocationDetect,
&ett_ranap_RelocationComplete,
&ett_ranap_EnhancedRelocationCompleteRequest,
&ett_ranap_RAB_SetupItem_EnhancedRelocCompleteReq,
&ett_ranap_EnhancedRelocationCompleteResponse,
&ett_ranap_RAB_SetupItem_EnhancedRelocCompleteRes,
&ett_ranap_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes,
&ett_ranap_EnhancedRelocationCompleteFailure,
&ett_ranap_EnhancedRelocationCompleteConfirm,
&ett_ranap_Paging,
&ett_ranap_CommonID,
&ett_ranap_CN_InvokeTrace,
&ett_ranap_CN_DeactivateTrace,
&ett_ranap_LocationReportingControl,
&ett_ranap_LocationReport,
&ett_ranap_InitialUE_Message,
&ett_ranap_DirectTransfer,
&ett_ranap_Overload,
&ett_ranap_ErrorIndication,
&ett_ranap_SRNS_DataForwardCommand,
&ett_ranap_ForwardSRNS_Context,
&ett_ranap_RAB_AssignmentRequest,
&ett_ranap_RAB_SetupOrModifyItemFirst,
&ett_ranap_TransportLayerInformation,
&ett_ranap_RAB_SetupOrModifyItemSecond,
&ett_ranap_RAB_AssignmentResponse,
&ett_ranap_RAB_SetupOrModifiedItem,
&ett_ranap_RAB_ReleasedItem,
&ett_ranap_DataVolumeList,
&ett_ranap_DataVolumeList_item,
&ett_ranap_RAB_QueuedItem,
&ett_ranap_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item,
&ett_ranap_PrivateMessage,
&ett_ranap_RANAP_RelocationInformation,
&ett_ranap_DirectTransferInformationItem_RANAP_RelocInf,
&ett_ranap_RAB_ContextItem_RANAP_RelocInf,
&ett_ranap_RANAP_EnhancedRelocationInformationRequest,
&ett_ranap_RAB_SetupItem_EnhRelocInfoReq,
&ett_ranap_TNLInformationEnhRelInfoReq,
&ett_ranap_RANAP_EnhancedRelocationInformationResponse,
&ett_ranap_RAB_SetupItem_EnhRelocInfoRes,
&ett_ranap_RAB_FailedItem_EnhRelocInfoRes,
&ett_ranap_TNLInformationEnhRelInfoRes,
&ett_ranap_RAB_ModifyRequest,
&ett_ranap_RAB_ModifyItem,
&ett_ranap_LocationRelatedDataRequest,
&ett_ranap_LocationRelatedDataResponse,
&ett_ranap_LocationRelatedDataFailure,
&ett_ranap_InformationTransferIndication,
&ett_ranap_InformationTransferConfirmation,
&ett_ranap_InformationTransferFailure,
&ett_ranap_UESpecificInformationIndication,
&ett_ranap_DirectInformationTransfer,
&ett_ranap_UplinkInformationExchangeRequest,
&ett_ranap_UplinkInformationExchangeResponse,
&ett_ranap_UplinkInformationExchangeFailure,
&ett_ranap_MBMSSessionStart,
&ett_ranap_MBMSSynchronisationInformation,
&ett_ranap_MBMSSessionStartResponse,
&ett_ranap_MBMSSessionStartFailure,
&ett_ranap_MBMSSessionUpdate,
&ett_ranap_MBMSSessionUpdateResponse,
&ett_ranap_MBMSSessionUpdateFailure,
&ett_ranap_MBMSSessionStop,
&ett_ranap_MBMSSessionStopResponse,
&ett_ranap_MBMSUELinkingRequest,
&ett_ranap_LeftMBMSBearerService_IEs,
&ett_ranap_LeftMBMSBearerService_IEs_item,
&ett_ranap_MBMSUELinkingResponse,
&ett_ranap_UnsuccessfulLinking_IEs,
&ett_ranap_UnsuccessfulLinking_IEs_item,
&ett_ranap_MBMSRegistrationRequest,
&ett_ranap_MBMSRegistrationResponse,
&ett_ranap_MBMSRegistrationFailure,
&ett_ranap_MBMSCNDe_RegistrationRequest,
&ett_ranap_MBMSCNDe_RegistrationResponse,
&ett_ranap_MBMSRABEstablishmentIndication,
&ett_ranap_MBMSRABReleaseRequest,
&ett_ranap_MBMSRABRelease,
&ett_ranap_MBMSRABReleaseFailure,
&ett_ranap_SRVCC_CSKeysRequest,
&ett_ranap_SRVCC_CSKeysResponse,
&ett_ranap_UeRadioCapabilityMatchRequest,
&ett_ranap_UeRadioCapabilityMatchResponse,
&ett_ranap_UeRegistrationQueryRequest,
&ett_ranap_UeRegistrationQueryResponse,
&ett_ranap_RerouteNASRequest,
&ett_ranap_RANAP_PDU,
&ett_ranap_InitiatingMessage,
&ett_ranap_SuccessfulOutcome,
&ett_ranap_UnsuccessfulOutcome,
&ett_ranap_Outcome,
#line 366 "./asn1/ranap/packet-ranap-template.c"
};
proto_ranap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ranap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ranap_handle = register_dissector("ranap", dissect_ranap, proto_ranap);
ranap_ies_dissector_table = register_dissector_table("ranap.ies", "RANAP-PROTOCOL-IES", proto_ranap, FT_UINT32, BASE_DEC);
ranap_ies_p1_dissector_table = register_dissector_table("ranap.ies.pair.first", "RANAP-PROTOCOL-IES-PAIR FirstValue", proto_ranap, FT_UINT32, BASE_DEC);
ranap_ies_p2_dissector_table = register_dissector_table("ranap.ies.pair.second", "RANAP-PROTOCOL-IES-PAIR SecondValue", proto_ranap, FT_UINT32, BASE_DEC);
ranap_extension_dissector_table = register_dissector_table("ranap.extension", "RANAP-PROTOCOL-EXTENSION", proto_ranap, FT_UINT32, BASE_DEC);
ranap_proc_imsg_dissector_table = register_dissector_table("ranap.proc.imsg", "RANAP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_ranap, FT_UINT32, BASE_DEC);
ranap_proc_sout_dissector_table = register_dissector_table("ranap.proc.sout", "RANAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_ranap, FT_UINT32, BASE_DEC);
ranap_proc_uout_dissector_table = register_dissector_table("ranap.proc.uout", "RANAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_ranap, FT_UINT32, BASE_DEC);
ranap_proc_out_dissector_table = register_dissector_table("ranap.proc.out", "RANAP-ELEMENTARY-PROCEDURE Outcome", proto_ranap, FT_UINT32, BASE_DEC);
nas_pdu_dissector_table = register_dissector_table("ranap.nas_pdu", "RANAP NAS PDU", proto_ranap, FT_UINT8, BASE_DEC);
ranap_module = prefs_register_protocol(proto_ranap, proto_reg_handoff_ranap);
prefs_register_uint_preference(ranap_module, "sccp_ssn", "SCCP SSN for RANAP",
"The SCCP SubSystem Number for RANAP (default 142)", 10,
&global_ranap_sccp_ssn);
prefs_register_bool_preference(ranap_module, "dissect_rrc_container",
"Attempt to dissect RRC-Container",
"Attempt to dissect RRC message embedded in RRC-Container IE",
&glbl_dissect_container);
}
void
proto_reg_handoff_ranap(void)
{
static gboolean initialized = FALSE;
static gint local_ranap_sccp_ssn;
if (!initialized) {
rrc_s_to_trnc_handle = find_dissector_add_dependency("rrc.s_to_trnc_cont", proto_ranap);
rrc_t_to_srnc_handle = find_dissector_add_dependency("rrc.t_to_srnc_cont", proto_ranap);
rrc_ho_to_utran_cmd = find_dissector_add_dependency("rrc.irat.ho_to_utran_cmd", proto_ranap);
bssgp_handle = find_dissector("bssgp");
initialized = TRUE;
#line 1 "./asn1/ranap/packet-ranap-dis-tab.c"
dissector_add_uint("ranap.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataVolumeReportList, create_dissector_handle(dissect_RAB_DataVolumeReportList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleasedList_IuRelComp, create_dissector_handle(dissect_RAB_ReleasedList_IuRelComp_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataVolumeReportItem, create_dissector_handle(dissect_RAB_DataVolumeReportItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleasedItem_IuRelComp, create_dissector_handle(dissect_RAB_ReleasedItem_IuRelComp_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RelocationType, create_dissector_handle(dissect_RelocationType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SourceID, create_dissector_handle(dissect_SourceID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Source_ToTarget_TransparentContainer, create_dissector_handle(dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.ies", SPECIAL|id_Source_ToTarget_TransparentContainer, create_dissector_handle(dissect_ranap_Source_ToTarget_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TargetID, create_dissector_handle(dissect_TargetID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Target_ToSource_TransparentContainer, create_dissector_handle(dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.ies", SPECIAL|id_Target_ToSource_TransparentContainer, create_dissector_handle(dissect_Target_ToSource_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_ClassmarkInformation2, create_dissector_handle(dissect_ClassmarkInformation2_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_ClassmarkInformation3, create_dissector_handle(dissect_ClassmarkInformation3_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_OldBSS_ToNewBSS_Information, create_dissector_handle(dissect_OldBSS_ToNewBSS_Information_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_L3_Information, create_dissector_handle(dissect_L3_Information_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_RelocationReleaseList, create_dissector_handle(dissect_RAB_RelocationReleaseList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataForwardingList, create_dissector_handle(dissect_RAB_DataForwardingList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_RelocationReleaseItem, create_dissector_handle(dissect_RAB_RelocationReleaseItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataForwardingItem, create_dissector_handle(dissect_RAB_DataForwardingItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_PermanentNAS_UE_ID, create_dissector_handle(dissect_PermanentNAS_UE_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_CN_DomainIndicator, create_dissector_handle(dissect_CN_DomainIndicator_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_RelocReq, create_dissector_handle(dissect_RAB_SetupList_RelocReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_IntegrityProtectionInformation, create_dissector_handle(dissect_IntegrityProtectionInformation_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_EncryptionInformation, create_dissector_handle(dissect_EncryptionInformation_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_IuSigConId, create_dissector_handle(dissect_IuSignallingConnectionIdentifier_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_DirectTransferInformationList_RANAP_RelocInf, create_dissector_handle(dissect_DirectTransferInformationList_RANAP_RelocInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_DirectTransferInformationItem_RANAP_RelocInf, create_dissector_handle(dissect_DirectTransferInformationItem_RANAP_RelocInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_RelocReq, create_dissector_handle(dissect_RAB_SetupItem_RelocReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_RelocReqAck, create_dissector_handle(dissect_RAB_SetupList_RelocReqAck_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedList, create_dissector_handle(dissect_RAB_FailedList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_ChosenIntegrityProtectionAlgorithm, create_dissector_handle(dissect_ChosenIntegrityProtectionAlgorithm_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_ChosenEncryptionAlgorithm, create_dissector_handle(dissect_ChosenEncryptionAlgorithm_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_RelocReqAck, create_dissector_handle(dissect_RAB_SetupItem_RelocReqAck_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedItem, create_dissector_handle(dissect_RAB_FailedItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataForwardingList_SRNS_CtxReq, create_dissector_handle(dissect_RAB_DataForwardingList_SRNS_CtxReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataForwardingItem_SRNS_CtxReq, create_dissector_handle(dissect_RAB_DataForwardingItem_SRNS_CtxReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextList, create_dissector_handle(dissect_RAB_ContextList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextFailedtoTransferList, create_dissector_handle(dissect_RAB_ContextFailedtoTransferList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextItem, create_dissector_handle(dissect_RAB_ContextItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextFailedtoTransferItem, create_dissector_handle(dissect_RABs_ContextFailedtoTransferItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_KeyStatus, create_dissector_handle(dissect_KeyStatus_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataVolumeReportRequestList, create_dissector_handle(dissect_RAB_DataVolumeReportRequestList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_DataVolumeReportRequestItem, create_dissector_handle(dissect_RAB_DataVolumeReportRequestItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedtoReportList, create_dissector_handle(dissect_RAB_FailedtoReportList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedtoReportItem, create_dissector_handle(dissect_RABs_failed_to_reportItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_GlobalRNC_ID, create_dissector_handle(dissect_GlobalRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", IMSG|id_IuSigConIdList, create_dissector_handle(dissect_ResetResourceList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", IMSG|id_IuSigConIdItem, create_dissector_handle(dissect_ResetResourceItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", SOUT|id_IuSigConIdList, create_dissector_handle(dissect_ResetResourceAckList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", SOUT|id_IuSigConIdItem, create_dissector_handle(dissect_ResetResourceAckItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleaseList, create_dissector_handle(dissect_RAB_ReleaseList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleaseItem, create_dissector_handle(dissect_RAB_ReleaseItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TemporaryUE_ID, create_dissector_handle(dissect_TemporaryUE_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_PagingAreaID, create_dissector_handle(dissect_PagingAreaID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_PagingCause, create_dissector_handle(dissect_PagingCause_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_NonSearchingIndication, create_dissector_handle(dissect_NonSearchingIndication_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_DRX_CycleLengthCoefficient, create_dissector_handle(dissect_DRX_CycleLengthCoefficient_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TraceType, create_dissector_handle(dissect_TraceType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TraceReference, create_dissector_handle(dissect_TraceReference_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TriggerID, create_dissector_handle(dissect_TriggerID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_UE_ID, create_dissector_handle(dissect_UE_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_OMC_ID, create_dissector_handle(dissect_OMC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RequestType, create_dissector_handle(dissect_RequestType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_AreaIdentity, create_dissector_handle(dissect_AreaIdentity_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_LAI, create_dissector_handle(dissect_LAI_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAC, create_dissector_handle(dissect_RAC_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SAI, create_dissector_handle(dissect_SAI_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_NAS_PDU, create_dissector_handle(dissect_NAS_PDU_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SAPI, create_dissector_handle(dissect_SAPI_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RejectCauseValue, create_dissector_handle(dissect_RejectCauseValue_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_NAS_SequenceNumber, create_dissector_handle(dissect_NAS_SequenceNumber_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_NumberOfSteps, create_dissector_handle(dissect_NumberOfSteps_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupOrModifyList, create_dissector_handle(dissect_RAB_SetupOrModifyList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupOrModifiedList, create_dissector_handle(dissect_RAB_SetupOrModifiedList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleasedList, create_dissector_handle(dissect_RAB_ReleasedList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_QueuedList, create_dissector_handle(dissect_RAB_QueuedList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleaseFailedList, create_dissector_handle(dissect_RAB_ReleaseFailedList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupOrModifiedItem, create_dissector_handle(dissect_RAB_SetupOrModifiedItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ReleasedItem, create_dissector_handle(dissect_RAB_ReleasedItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_QueuedItem, create_dissector_handle(dissect_RAB_QueuedItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item, create_dissector_handle(dissect_GERAN_Iumode_RAB_Failed_RABAssgntResponse_Item_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextList_RANAP_RelocInf, create_dissector_handle(dissect_RAB_ContextList_RANAP_RelocInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ContextItem_RANAP_RelocInf, create_dissector_handle(dissect_RAB_ContextItem_RANAP_RelocInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ModifyList, create_dissector_handle(dissect_RAB_ModifyList_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ModifyItem, create_dissector_handle(dissect_RAB_ModifyItem_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_LocationRelatedDataRequestType, create_dissector_handle(dissect_LocationRelatedDataRequestType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_BroadcastAssistanceDataDecipheringKeys, create_dissector_handle(dissect_BroadcastAssistanceDataDecipheringKeys_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationTransferID, create_dissector_handle(dissect_InformationTransferID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_ProvidedData, create_dissector_handle(dissect_ProvidedData_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_GlobalCN_ID, create_dissector_handle(dissect_GlobalCN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_UESBI_Iu, create_dissector_handle(dissect_UESBI_Iu_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InterSystemInformationTransferType, create_dissector_handle(dissect_InterSystemInformationTransferType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationExchangeID, create_dissector_handle(dissect_InformationExchangeID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationExchangeType, create_dissector_handle(dissect_InformationExchangeType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationTransferType, create_dissector_handle(dissect_InformationTransferType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationRequestType, create_dissector_handle(dissect_InformationRequestType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_InformationRequested, create_dissector_handle(dissect_InformationRequested_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TMGI, create_dissector_handle(dissect_TMGI_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSSessionIdentity, create_dissector_handle(dissect_MBMSSessionIdentity_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSBearerServiceType, create_dissector_handle(dissect_MBMSBearerServiceType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_Parameters, create_dissector_handle(dissect_RAB_Parameters_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_PDP_TypeInformation, create_dissector_handle(dissect_PDP_TypeInformation_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSSessionDuration, create_dissector_handle(dissect_MBMSSessionDuration_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSServiceArea, create_dissector_handle(dissect_MBMSServiceArea_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_FrequenceLayerConvergenceFlag, create_dissector_handle(dissect_FrequenceLayerConvergenceFlag_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAListofIdleModeUEs, create_dissector_handle(dissect_RAListofIdleModeUEs_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSSessionRepetitionNumber, create_dissector_handle(dissect_MBMSSessionRepetitionNumber_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TimeToMBMSDataTransfer, create_dissector_handle(dissect_TimeToMBMSDataTransfer_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_TransportLayerInformation, create_dissector_handle(dissect_TransportLayerInformation_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SessionUpdateID, create_dissector_handle(dissect_SessionUpdateID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_DeltaRAListofIdleModeUEs, create_dissector_handle(dissect_DeltaRAListofIdleModeUEs_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSCNDe_Registration, create_dissector_handle(dissect_MBMSCNDe_Registration_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_JoinedMBMSBearerServicesList, create_dissector_handle(dissect_JoinedMBMSBearerService_IEs_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_LeftMBMSBearerServicesList, create_dissector_handle(dissect_LeftMBMSBearerService_IEs_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_UnsuccessfulLinkingList, create_dissector_handle(dissect_UnsuccessfulLinking_IEs_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_MBMSRegistrationRequestType, create_dissector_handle(dissect_MBMSRegistrationRequestType_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_IPMulticastAddress, create_dissector_handle(dissect_IPMulticastAddress_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_APN, create_dissector_handle(dissect_APN_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_EnhancedRelocCompleteReq, create_dissector_handle(dissect_RAB_SetupList_EnhancedRelocCompleteReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_EnhancedRelocCompleteReq, create_dissector_handle(dissect_RAB_SetupItem_EnhancedRelocCompleteReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_EnhancedRelocCompleteRes, create_dissector_handle(dissect_RAB_SetupList_EnhancedRelocCompleteRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_EnhancedRelocCompleteRes, create_dissector_handle(dissect_RAB_SetupItem_EnhancedRelocCompleteRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_EnhRelocInfoReq, create_dissector_handle(dissect_RAB_SetupList_EnhRelocInfoReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_EnhRelocInfoReq, create_dissector_handle(dissect_RAB_SetupItem_EnhRelocInfoReq_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupList_EnhRelocInfoRes, create_dissector_handle(dissect_RAB_SetupList_EnhRelocInfoRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_SetupItem_EnhRelocInfoRes, create_dissector_handle(dissect_RAB_SetupItem_EnhRelocInfoRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_OldIuSigConId, create_dissector_handle(dissect_IuSignallingConnectionIdentifier_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedList_EnhRelocInfoRes, create_dissector_handle(dissect_RAB_FailedList_EnhRelocInfoRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_FailedItem_EnhRelocInfoRes, create_dissector_handle(dissect_RAB_FailedItem_EnhRelocInfoRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_OldIuSigConIdCS, create_dissector_handle(dissect_IuSignallingConnectionIdentifier_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_OldIuSigConIdPS, create_dissector_handle(dissect_IuSignallingConnectionIdentifier_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_GlobalCN_IDCS, create_dissector_handle(dissect_GlobalCN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes, create_dissector_handle(dissect_RAB_ToBeReleasedItem_EnhancedRelocCompleteRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_RAB_ToBeReleasedList_EnhancedRelocCompleteRes, create_dissector_handle(dissect_RAB_ToBeReleasedList_EnhancedRelocCompleteRes_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Relocation_TargetRNC_ID, create_dissector_handle(dissect_GlobalRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Relocation_TargetExtendedRNC_ID, create_dissector_handle(dissect_ExtendedRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf, create_dissector_handle(dissect_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Alt_RAB_Parameter_SupportedMaxBitrateInf, create_dissector_handle(dissect_Alt_RAB_Parameter_SupportedMaxBitrateInf_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Relocation_SourceRNC_ID, create_dissector_handle(dissect_GlobalRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_Relocation_SourceExtendedRNC_ID, create_dissector_handle(dissect_ExtendedRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_EncryptionKey, create_dissector_handle(dissect_EncryptionKey_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_IntegrityProtectionKey, create_dissector_handle(dissect_IntegrityProtectionKey_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SRVCC_Information, create_dissector_handle(dissect_SRVCC_Information_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_GlobalCN_IDPS, create_dissector_handle(dissect_GlobalCN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_VoiceSupportMatchIndicator, create_dissector_handle(dissect_VoiceSupportMatchIndicator_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_SGSN_Group_Identity, create_dissector_handle(dissect_SGSN_Group_Identity_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_P_TMSI, create_dissector_handle(dissect_P_TMSI_PDU, proto_ranap));
dissector_add_uint("ranap.ies", id_UE_Usage_Type, create_dissector_handle(dissect_UE_Usage_Type_PDU, proto_ranap));
dissector_add_uint("ranap.ies.pair.first", id_RAB_SetupOrModifyItem, create_dissector_handle(dissect_RAB_SetupOrModifyItemFirst_PDU, proto_ranap));
dissector_add_uint("ranap.ies.pair.second", id_RAB_SetupOrModifyItem, create_dissector_handle(dissect_RAB_SetupOrModifyItemSecond_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_AlternativeRABConfiguration, create_dissector_handle(dissect_RAB_Parameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf, create_dissector_handle(dissect_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Alt_RAB_Parameter_ExtendedMaxBitrateInf, create_dissector_handle(dissect_Alt_RAB_Parameter_ExtendedMaxBitrateInf_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList, create_dissector_handle(dissect_Ass_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Ass_RAB_Parameter_ExtendedMaxBitrateList, create_dissector_handle(dissect_Ass_RAB_Parameter_ExtendedMaxBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MessageStructure, create_dissector_handle(dissect_MessageStructure_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TypeOfError, create_dissector_handle(dissect_TypeOfError_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAC, create_dissector_handle(dissect_RAC_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_newLAListofIdleModeUEs, create_dissector_handle(dissect_LAListofIdleModeUEs_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LAListwithNoIdleModeUEsAnyMore, create_dissector_handle(dissect_LAListofIdleModeUEs_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_GANSS_PositioningDataSet, create_dissector_handle(dissect_GANSS_PositioningDataSet_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SignallingIndication, create_dissector_handle(dissect_SignallingIndication_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAB_Parameter_ExtendedGuaranteedBitrateList, create_dissector_handle(dissect_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAB_Parameter_ExtendedMaxBitrateList, create_dissector_handle(dissect_RAB_Parameter_ExtendedMaxBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CN_DomainIndicator, create_dissector_handle(dissect_CN_DomainIndicator_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LAofIdleModeUEs, create_dissector_handle(dissect_LAListofIdleModeUEs_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_AlternativeRABConfigurationRequest, create_dissector_handle(dissect_AlternativeRABConfigurationRequest_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Requested_RAB_Parameter_ExtendedMaxBitrateList, create_dissector_handle(dissect_Requested_RAB_Parameter_ExtendedMaxBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList, create_dissector_handle(dissect_Requested_RAB_Parameter_ExtendedGuaranteedBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_ExtendedRNC_ID, create_dissector_handle(dissect_ExtendedRNC_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SRB_TrCH_Mapping, create_dissector_handle(dissect_SRB_TrCH_Mapping_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CellLoadInformationGroup, create_dissector_handle(dissect_CellLoadInformationGroup_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TraceRecordingSessionInformation, create_dissector_handle(dissect_TraceRecordingSessionInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MBMSLinkingInformation, create_dissector_handle(dissect_MBMSLinkingInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_hS_DSCH_MAC_d_Flow_ID, create_dissector_handle(dissect_HS_DSCH_MAC_d_Flow_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_E_DCH_MAC_d_Flow_ID, create_dissector_handle(dissect_E_DCH_MAC_d_Flow_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_GERAN_Classmark, create_dissector_handle(dissect_GERAN_Classmark_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SourceBSS_ToTargetBSS_TransparentContainer, create_dissector_handle(dissect_SourceBSS_ToTargetBSS_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IuTransportAssociation, create_dissector_handle(dissect_IuTransportAssociation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_InterSystemInformation_TransparentContainer, create_dissector_handle(dissect_ranap_InterSystemInformation_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TargetBSS_ToSourceBSS_TransparentContainer, create_dissector_handle(dissect_TargetBSS_ToSourceBSS_TransparentContainer_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Alt_RAB_Parameters, create_dissector_handle(dissect_Alt_RAB_Parameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_GERAN_BSC_Container, create_dissector_handle(dissect_GERAN_BSC_Container_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_GlobalCN_ID, create_dissector_handle(dissect_GlobalCN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SNA_Access_Information, create_dissector_handle(dissect_SNA_Access_Information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UESBI_Iu, create_dissector_handle(dissect_UESBI_Iu_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SelectedPLMN_ID, create_dissector_handle(dissect_PLMNidentity_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CNMBMSLinkingInformation, create_dissector_handle(dissect_CNMBMSLinkingInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Ass_RAB_Parameters, create_dissector_handle(dissect_Ass_RAB_Parameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_NewBSS_To_OldBSS_Information, create_dissector_handle(dissect_NewBSS_To_OldBSS_Information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAT_Type, create_dissector_handle(dissect_RAT_Type_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TracePropagationParameters, create_dissector_handle(dissect_TracePropagationParameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_VerticalAccuracyCode, create_dissector_handle(dissect_VerticalAccuracyCode_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_ResponseTime, create_dissector_handle(dissect_ResponseTime_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PositioningPriority, create_dissector_handle(dissect_PositioningPriority_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_ClientType, create_dissector_handle(dissect_ClientType_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IncludeVelocity, create_dissector_handle(dissect_IncludeVelocity_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PeriodicLocationInfo, create_dissector_handle(dissect_PeriodicLocationInfo_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LastKnownServiceArea, create_dissector_handle(dissect_LastKnownServiceArea_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PositionData, create_dissector_handle(dissect_PositionData_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PositionDataSpecificToGERANIuMode, create_dissector_handle(dissect_PositionDataSpecificToGERANIuMode_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_AccuracyFulfilmentIndicator, create_dissector_handle(dissect_AccuracyFulfilmentIndicator_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_VelocityEstimate, create_dissector_handle(dissect_VelocityEstimate_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PermanentNAS_UE_ID, create_dissector_handle(dissect_PermanentNAS_UE_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_NAS_SequenceNumber, create_dissector_handle(dissect_NAS_SequenceNumber_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RedirectAttemptFlag, create_dissector_handle(dissect_RedirectAttemptFlag_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RedirectionIndication, create_dissector_handle(dissect_RedirectionIndication_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RedirectionCompleted, create_dissector_handle(dissect_RedirectionCompleted_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SourceRNC_PDCP_context_info, create_dissector_handle(dissect_RRC_Container_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_GERAN_Iumode_RAB_FailedList_RABAssgntResponse, create_dissector_handle(dissect_GERAN_Iumode_RAB_FailedList_RABAssgntResponse_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LocationRelatedDataRequestTypeSpecificToGERANIuMode, create_dissector_handle(dissect_LocationRelatedDataRequestTypeSpecificToGERANIuMode_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RequestedGANSSAssistanceData, create_dissector_handle(dissect_RequestedGANSSAssistanceData_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MBMSCountingInformation, create_dissector_handle(dissect_MBMSCountingInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UE_History_Information, create_dissector_handle(dissect_UE_History_Information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MBMSSynchronisationInformation, create_dissector_handle(dissect_MBMSSynchronisationInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SubscriberProfileIDforRFP, create_dissector_handle(dissect_SubscriberProfileIDforRFP_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CSG_Id, create_dissector_handle(dissect_CSG_Id_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Ass_RAB_Parameter_SupportedGuaranteedBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Ass_RAB_Parameter_SupportedMaxBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAB_Parameter_SupportedGuaranteedBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RAB_Parameter_SupportedMaxBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Requested_RAB_Parameter_SupportedMaxBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Requested_RAB_Parameter_SupportedGuaranteedBitrateList, create_dissector_handle(dissect_SupportedRAB_ParameterBitrateList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SRVCC_HO_Indication, create_dissector_handle(dissect_SRVCC_HO_Indication_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SRVCC_Operation_Possible, create_dissector_handle(dissect_SRVCC_Operation_Possible_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CSG_Id_List, create_dissector_handle(dissect_CSG_Id_List_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PSRABtobeReplaced, create_dissector_handle(dissect_RAB_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_E_UTRAN_Service_Handover, create_dissector_handle(dissect_E_UTRAN_Service_Handover_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UE_AggregateMaximumBitRate, create_dissector_handle(dissect_UE_AggregateMaximumBitRate_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CSG_Membership_Status, create_dissector_handle(dissect_CSG_Membership_Status_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Cell_Access_Mode, create_dissector_handle(dissect_Cell_Access_Mode_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IP_Source_Address, create_dissector_handle(dissect_IPMulticastAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CSFB_Information, create_dissector_handle(dissect_CSFB_Information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PDP_TypeInformation_extension, create_dissector_handle(dissect_PDP_TypeInformation_extension_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MSISDN, create_dissector_handle(dissect_MSISDN_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Offload_RAB_Parameters, create_dissector_handle(dissect_Offload_RAB_Parameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LGW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IRAT_Measurement_Configuration, create_dissector_handle(dissect_IRAT_Measurement_Configuration_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_MDT_Configuration, create_dissector_handle(dissect_MDT_Configuration_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Priority_Class_Indicator, create_dissector_handle(dissect_Priority_Class_Indicator_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RNSAPRelocationParameters, create_dissector_handle(dissect_RNSAPRelocationParameters_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RABParametersList, create_dissector_handle(dissect_RABParametersList_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Management_Based_MDT_Allowed, create_dissector_handle(dissect_Management_Based_MDT_Allowed_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_HigherBitratesThan16MbpsFlag, create_dissector_handle(dissect_HigherBitratesThan16MbpsFlag_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Trace_Collection_Entity_IP_Addess, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_End_Of_CSFB, create_dissector_handle(dissect_End_Of_CSFB_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Time_UE_StayedInCell_EnhancedGranularity, create_dissector_handle(dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Out_Of_UTRAN, create_dissector_handle(dissect_Out_Of_UTRAN_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TraceRecordingSessionReference, create_dissector_handle(dissect_TraceRecordingSessionReference_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IMSI, create_dissector_handle(dissect_IMSI_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_HO_Cause, create_dissector_handle(dissect_Cause_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RSRVCC_HO_Indication, create_dissector_handle(dissect_RSRVCC_HO_Indication_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RSRVCC_Information, create_dissector_handle(dissect_RSRVCC_Information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_AnchorPLMN_ID, create_dissector_handle(dissect_PLMNidentity_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Tunnel_Information_for_BBF, create_dissector_handle(dissect_TunnelInformation_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Management_Based_MDT_PLMN_List, create_dissector_handle(dissect_MDT_PLMN_List_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SignallingBasedMDTPLMNList, create_dissector_handle(dissect_MDT_PLMN_List_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_M4Report, create_dissector_handle(dissect_M4Report_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_M5Report, create_dissector_handle(dissect_M5Report_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_M6Report, create_dissector_handle(dissect_M6Report_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_M7Report, create_dissector_handle(dissect_M7Report_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_TimingDifferenceULDL, create_dissector_handle(dissect_TimingDifferenceULDL_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Serving_Cell_Identifier, create_dissector_handle(dissect_UTRAN_CellID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_EARFCN_Extended, create_dissector_handle(dissect_EARFCN_Extended_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RSRVCC_Operation_Possible, create_dissector_handle(dissect_RSRVCC_Operation_Possible_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SIPTO_LGW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_SIPTO_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LHN_ID, create_dissector_handle(dissect_LHN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Session_Re_establishment_Indicator, create_dissector_handle(dissect_Session_Re_establishment_Indicator_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_LastE_UTRANPLMNIdentity, create_dissector_handle(dissect_PLMNidentity_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RSRQ_Type, create_dissector_handle(dissect_RSRQ_Type_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_RSRQ_Extension, create_dissector_handle(dissect_RSRQ_Extension_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Additional_CSPS_coordination_information, create_dissector_handle(dissect_Additional_CSPS_coordination_information_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UERegistrationQueryResult, create_dissector_handle(dissect_UERegistrationQueryResult_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_IuSigConIdRangeEnd, create_dissector_handle(dissect_IuSignallingConnectionIdentifier_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_BarometricPressure, create_dissector_handle(dissect_BarometricPressure_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_Additional_PositioningDataSet, create_dissector_handle(dissect_Additional_PositioningDataSet_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_CivicAddress, create_dissector_handle(dissect_CivicAddress_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_PowerSavingIndicator, create_dissector_handle(dissect_PowerSavingIndicator_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_DCN_ID, create_dissector_handle(dissect_DCN_ID_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UE_Application_Layer_Measurement_Configuration, create_dissector_handle(dissect_UE_Application_Layer_Measurement_Configuration_PDU, proto_ranap));
dissector_add_uint("ranap.extension", id_UE_Application_Layer_Measurement_Configuration_For_Relocation, create_dissector_handle(dissect_UE_Application_Layer_Measurement_Configuration_For_Relocation_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_Iu_Release, create_dissector_handle(dissect_Iu_ReleaseCommand_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_Iu_Release, create_dissector_handle(dissect_Iu_ReleaseComplete_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RelocationPreparation, create_dissector_handle(dissect_RelocationRequired_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_RelocationPreparation, create_dissector_handle(dissect_RelocationCommand_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_RelocationPreparation, create_dissector_handle(dissect_RelocationPreparationFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RelocationResourceAllocation, create_dissector_handle(dissect_RelocationRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_RelocationResourceAllocation, create_dissector_handle(dissect_RelocationRequestAcknowledge_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_RelocationResourceAllocation, create_dissector_handle(dissect_RelocationFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RelocationCancel, create_dissector_handle(dissect_RelocationCancel_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_RelocationCancel, create_dissector_handle(dissect_RelocationCancelAcknowledge_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_SRNS_ContextTransfer, create_dissector_handle(dissect_SRNS_ContextRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_SRNS_ContextTransfer, create_dissector_handle(dissect_SRNS_ContextResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_SecurityModeControl, create_dissector_handle(dissect_SecurityModeCommand_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_SecurityModeControl, create_dissector_handle(dissect_SecurityModeComplete_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_SecurityModeControl, create_dissector_handle(dissect_SecurityModeReject_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_DataVolumeReport, create_dissector_handle(dissect_DataVolumeReportRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_DataVolumeReport, create_dissector_handle(dissect_DataVolumeReport_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_Reset, create_dissector_handle(dissect_Reset_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_Reset, create_dissector_handle(dissect_ResetAcknowledge_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RAB_ReleaseRequest, create_dissector_handle(dissect_RAB_ReleaseRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_Iu_ReleaseRequest, create_dissector_handle(dissect_Iu_ReleaseRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RelocationDetect, create_dissector_handle(dissect_RelocationDetect_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RelocationComplete, create_dissector_handle(dissect_RelocationComplete_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_Paging, create_dissector_handle(dissect_Paging_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_CommonID, create_dissector_handle(dissect_CommonID_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_CN_InvokeTrace, create_dissector_handle(dissect_CN_InvokeTrace_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_CN_DeactivateTrace, create_dissector_handle(dissect_CN_DeactivateTrace_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_LocationReportingControl, create_dissector_handle(dissect_LocationReportingControl_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_LocationReport, create_dissector_handle(dissect_LocationReport_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_InitialUE_Message, create_dissector_handle(dissect_InitialUE_Message_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_DirectTransfer, create_dissector_handle(dissect_DirectTransfer_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_OverloadControl, create_dissector_handle(dissect_Overload_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_ErrorIndication, create_dissector_handle(dissect_ErrorIndication_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_SRNS_DataForward, create_dissector_handle(dissect_SRNS_DataForwardCommand_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_ForwardSRNS_Context, create_dissector_handle(dissect_ForwardSRNS_Context_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RAB_Assignment, create_dissector_handle(dissect_RAB_AssignmentRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.out", id_RAB_Assignment, create_dissector_handle(dissect_RAB_AssignmentResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_privateMessage, create_dissector_handle(dissect_PrivateMessage_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_ResetResource, create_dissector_handle(dissect_ResetResource_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_ResetResource, create_dissector_handle(dissect_ResetResourceAcknowledge_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RANAP_Relocation, create_dissector_handle(dissect_RANAP_RelocationInformation_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RAB_ModifyRequest, create_dissector_handle(dissect_RAB_ModifyRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_LocationRelatedData, create_dissector_handle(dissect_LocationRelatedDataRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_LocationRelatedData, create_dissector_handle(dissect_LocationRelatedDataResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_LocationRelatedData, create_dissector_handle(dissect_LocationRelatedDataFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_InformationTransfer, create_dissector_handle(dissect_InformationTransferIndication_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_InformationTransfer, create_dissector_handle(dissect_InformationTransferConfirmation_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_InformationTransfer, create_dissector_handle(dissect_InformationTransferFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_UESpecificInformation, create_dissector_handle(dissect_UESpecificInformationIndication_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_DirectInformationTransfer, create_dissector_handle(dissect_DirectInformationTransfer_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_UplinkInformationExchange, create_dissector_handle(dissect_UplinkInformationExchangeRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_UplinkInformationExchange, create_dissector_handle(dissect_UplinkInformationExchangeResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_UplinkInformationExchange, create_dissector_handle(dissect_UplinkInformationExchangeFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSSessionStart, create_dissector_handle(dissect_MBMSSessionStart_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSSessionStart, create_dissector_handle(dissect_MBMSSessionStartResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_MBMSSessionStart, create_dissector_handle(dissect_MBMSSessionStartFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSSessionUpdate, create_dissector_handle(dissect_MBMSSessionUpdate_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSSessionUpdate, create_dissector_handle(dissect_MBMSSessionUpdateResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_MBMSSessionUpdate, create_dissector_handle(dissect_MBMSSessionUpdateFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSSessionStop, create_dissector_handle(dissect_MBMSSessionStop_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSSessionStop, create_dissector_handle(dissect_MBMSSessionStopResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSUELinking, create_dissector_handle(dissect_MBMSUELinkingRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.out", id_MBMSUELinking, create_dissector_handle(dissect_MBMSUELinkingResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSRegistration, create_dissector_handle(dissect_MBMSRegistrationRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSRegistration, create_dissector_handle(dissect_MBMSRegistrationResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_MBMSRegistration, create_dissector_handle(dissect_MBMSRegistrationFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSCNDe_Registration_Procedure, create_dissector_handle(dissect_MBMSCNDe_RegistrationRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSCNDe_Registration_Procedure, create_dissector_handle(dissect_MBMSCNDe_RegistrationResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSRABEstablishmentIndication, create_dissector_handle(dissect_MBMSRABEstablishmentIndication_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_MBMSRABRelease, create_dissector_handle(dissect_MBMSRABReleaseRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_MBMSRABRelease, create_dissector_handle(dissect_MBMSRABRelease_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_MBMSRABRelease, create_dissector_handle(dissect_MBMSRABReleaseFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_enhancedRelocationComplete, create_dissector_handle(dissect_EnhancedRelocationCompleteRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_enhancedRelocationComplete, create_dissector_handle(dissect_EnhancedRelocationCompleteResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.uout", id_enhancedRelocationComplete, create_dissector_handle(dissect_EnhancedRelocationCompleteFailure_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_enhancedRelocationCompleteConfirm, create_dissector_handle(dissect_EnhancedRelocationCompleteConfirm_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RANAPenhancedRelocation, create_dissector_handle(dissect_RANAP_EnhancedRelocationInformationRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.sout", id_RANAPenhancedRelocation, create_dissector_handle(dissect_RANAP_EnhancedRelocationInformationResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_SRVCCPreparation, create_dissector_handle(dissect_SRVCC_CSKeysRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.out", id_SRVCCPreparation, create_dissector_handle(dissect_SRVCC_CSKeysResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_UeRadioCapabilityMatch, create_dissector_handle(dissect_UeRadioCapabilityMatchRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.out", id_UeRadioCapabilityMatch, create_dissector_handle(dissect_UeRadioCapabilityMatchResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_UeRegistrationQuery, create_dissector_handle(dissect_UeRegistrationQueryRequest_PDU, proto_ranap));
dissector_add_uint("ranap.proc.out", id_UeRegistrationQuery, create_dissector_handle(dissect_UeRegistrationQueryResponse_PDU, proto_ranap));
dissector_add_uint("ranap.proc.imsg", id_RerouteNASRequest, create_dissector_handle(dissect_RerouteNASRequest_PDU, proto_ranap));
#line 415 "./asn1/ranap/packet-ranap-template.c"
} else {
dissector_delete_uint("sccp.ssn", local_ranap_sccp_ssn, ranap_handle);
}
dissector_add_uint("sccp.ssn", global_ranap_sccp_ssn, ranap_handle);
local_ranap_sccp_ssn = global_ranap_sccp_ssn;
heur_dissector_add("sccp", dissect_sccp_ranap_heur, "RANAP over SCCP", "ranap_sccp", proto_ranap, HEURISTIC_ENABLE);
heur_dissector_add("sua", dissect_sccp_ranap_heur, "RANAP over SUA", "ranap_sua", proto_ranap, HEURISTIC_ENABLE);
}
