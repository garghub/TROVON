static int
dissect_disp_DSAShadowBindArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_DSAShadowBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_DSAShadowBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindError(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_EstablishParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_disp_SET_OF_SupplierAndConsumers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SupplierAndConsumers_set_of, hf_index, ett_disp_SET_OF_SupplierAndConsumers);
return offset;
}
static int
dissect_disp_ModificationParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModificationParameter_sequence, hf_index, ett_disp_ModificationParameter);
return offset;
}
int
dissect_disp_AgreementID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dop_OperationalBindingID(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_AreaSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AreaSpecification_sequence, hf_index, ett_disp_AreaSpecification);
return offset;
}
static int
dissect_disp_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_disp_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_disp_AttributeTypes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
AttributeTypes_set_of, hf_index, ett_disp_AttributeTypes);
return offset;
}
static int
dissect_disp_ClassAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ClassAttributes_choice, hf_index, ett_disp_ClassAttributes,
NULL);
return offset;
}
static int
dissect_disp_ClassAttributeSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ClassAttributeSelection_sequence, hf_index, ett_disp_ClassAttributeSelection);
return offset;
}
static int
dissect_disp_AttributeSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
AttributeSelection_set_of, hf_index, ett_disp_AttributeSelection);
return offset;
}
static int
dissect_disp_T_knowledgeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_disp_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_disp_Knowledge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Knowledge_sequence, hf_index, ett_disp_Knowledge);
return offset;
}
static int
dissect_disp_T_selectedContexts(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_selectedContexts_set_of, hf_index, ett_disp_T_selectedContexts);
return offset;
}
static int
dissect_disp_T_supplyContexts(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_supplyContexts_choice, hf_index, ett_disp_T_supplyContexts,
NULL);
return offset;
}
static int
dissect_disp_UnitOfReplication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UnitOfReplication_sequence, hf_index, ett_disp_UnitOfReplication);
return offset;
}
static int
dissect_disp_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_disp_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_disp_PeriodicStrategy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PeriodicStrategy_sequence, hf_index, ett_disp_PeriodicStrategy);
return offset;
}
static int
dissect_disp_SchedulingParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SchedulingParameters_sequence, hf_index, ett_disp_SchedulingParameters);
return offset;
}
static int
dissect_disp_SupplierUpdateMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SupplierUpdateMode_choice, hf_index, ett_disp_SupplierUpdateMode,
NULL);
return offset;
}
static int
dissect_disp_ConsumerUpdateMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_disp_SchedulingParameters(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_UpdateMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UpdateMode_choice, hf_index, ett_disp_UpdateMode,
NULL);
return offset;
}
static int
dissect_disp_ShadowingAgreementInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ShadowingAgreementInfo_sequence, hf_index, ett_disp_ShadowingAgreementInfo);
return offset;
}
static int
dissect_disp_StandardUpdate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 63 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_StandardUpdate_vals, "unknown(%d)"));
return offset;
}
static int
dissect_disp_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_disp_T_updateStrategy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_updateStrategy_choice, hf_index, ett_disp_T_updateStrategy,
NULL);
return offset;
}
static int
dissect_disp_CoordinateShadowUpdateArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CoordinateShadowUpdateArgumentData_sequence, hf_index, ett_disp_CoordinateShadowUpdateArgumentData);
return offset;
}
static int
dissect_disp_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_disp_T_signedCoordinateShadowUpdateArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedCoordinateShadowUpdateArgument_sequence, hf_index, ett_disp_T_signedCoordinateShadowUpdateArgument);
return offset;
}
static int
dissect_disp_CoordinateShadowUpdateArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CoordinateShadowUpdateArgument_choice, hf_index, ett_disp_CoordinateShadowUpdateArgument,
NULL);
return offset;
}
static int
dissect_disp_SEQUENCE_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Attribute_sequence_of, hf_index, ett_disp_SEQUENCE_OF_Attribute);
return offset;
}
static int
dissect_disp_InformationData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InformationData_sequence, hf_index, ett_disp_InformationData);
return offset;
}
static int
dissect_disp_T_signedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedInformation_sequence, hf_index, ett_disp_T_signedInformation);
return offset;
}
static int
dissect_disp_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Information_choice, hf_index, ett_disp_Information,
NULL);
return offset;
}
static int
dissect_disp_CoordinateShadowUpdateResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 73 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_choice(actx, tree, tvb, offset,
CoordinateShadowUpdateResult_choice, hf_index, ett_disp_CoordinateShadowUpdateResult,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_CoordinateShadowUpdateResult_vals, "unknown(%d)"));
return offset;
}
static int
dissect_disp_T_standard(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 43 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_T_standard_vals, "standard(%d"));
return offset;
}
static int
dissect_disp_T_requestedStrategy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_requestedStrategy_choice, hf_index, ett_disp_T_requestedStrategy,
NULL);
return offset;
}
static int
dissect_disp_RequestShadowUpdateArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestShadowUpdateArgumentData_sequence, hf_index, ett_disp_RequestShadowUpdateArgumentData);
return offset;
}
static int
dissect_disp_T_signedRequestShadowUpdateArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedRequestShadowUpdateArgument_sequence, hf_index, ett_disp_T_signedRequestShadowUpdateArgument);
return offset;
}
static int
dissect_disp_RequestShadowUpdateArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestShadowUpdateArgument_choice, hf_index, ett_disp_RequestShadowUpdateArgument,
NULL);
return offset;
}
static int
dissect_disp_RequestShadowUpdateResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 83 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestShadowUpdateResult_choice, hf_index, ett_disp_RequestShadowUpdateResult,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_RequestShadowUpdateResult_vals, "unknown(%d)"));
return offset;
}
static int
dissect_disp_UpdateWindow(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UpdateWindow_sequence, hf_index, ett_disp_UpdateWindow);
return offset;
}
static int
dissect_disp_SDSEType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dop_DSEType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_disp_SET_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Attribute_set_of, hf_index, ett_disp_SET_OF_Attribute);
return offset;
}
static int
dissect_disp_SET_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeType_set_of, hf_index, ett_disp_SET_OF_AttributeType);
return offset;
}
static int
dissect_disp_SDSEContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SDSEContent_sequence, hf_index, ett_disp_SDSEContent);
return offset;
}
static int
dissect_disp_SET_OF_Subtree(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Subtree_set_of, hf_index, ett_disp_SET_OF_Subtree);
return offset;
}
static int
dissect_disp_Subtree(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Subtree_sequence, hf_index, ett_disp_Subtree);
return offset;
}
static int
dissect_disp_TotalRefresh(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TotalRefresh_sequence, hf_index, ett_disp_TotalRefresh);
return offset;
}
static int
dissect_disp_T_rename(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_rename_choice, hf_index, ett_disp_T_rename,
NULL);
return offset;
}
static int
dissect_disp_SEQUENCE_OF_EntryModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_EntryModification_sequence_of, hf_index, ett_disp_SEQUENCE_OF_EntryModification);
return offset;
}
static int
dissect_disp_T_attributeChanges(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_attributeChanges_choice, hf_index, ett_disp_T_attributeChanges,
NULL);
return offset;
}
static int
dissect_disp_ContentChange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContentChange_sequence, hf_index, ett_disp_ContentChange);
return offset;
}
static int
dissect_disp_T_sDSEChanges(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_sDSEChanges_choice, hf_index, ett_disp_T_sDSEChanges,
NULL);
return offset;
}
static int
dissect_disp_SubordinateChanges(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubordinateChanges_sequence, hf_index, ett_disp_SubordinateChanges);
return offset;
}
static int
dissect_disp_SEQUENCE_OF_SubordinateChanges(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_SubordinateChanges_sequence_of, hf_index, ett_disp_SEQUENCE_OF_SubordinateChanges);
return offset;
}
static int
dissect_disp_IncrementalStepRefresh(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IncrementalStepRefresh_sequence, hf_index, ett_disp_IncrementalStepRefresh);
return offset;
}
static int
dissect_disp_IncrementalRefresh(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
IncrementalRefresh_sequence_of, hf_index, ett_disp_IncrementalRefresh);
return offset;
}
static int
dissect_disp_RefreshInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 53 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_choice(actx, tree, tvb, offset,
RefreshInformation_choice, hf_index, ett_disp_RefreshInformation,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_RefreshInformation_vals, "unknown(%d)"));
return offset;
}
static int
dissect_disp_UpdateShadowArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UpdateShadowArgumentData_sequence, hf_index, ett_disp_UpdateShadowArgumentData);
return offset;
}
static int
dissect_disp_T_signedUpdateShadowArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedUpdateShadowArgument_sequence, hf_index, ett_disp_T_signedUpdateShadowArgument);
return offset;
}
static int
dissect_disp_UpdateShadowArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UpdateShadowArgument_choice, hf_index, ett_disp_UpdateShadowArgument,
NULL);
return offset;
}
static int
dissect_disp_UpdateShadowResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 93 "./asn1/disp/disp.cnf"
guint32 update;
offset = dissect_ber_choice(actx, tree, tvb, offset,
UpdateShadowResult_choice, hf_index, ett_disp_UpdateShadowResult,
&update);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(update, disp_UpdateShadowResult_vals, "unknown(%d)"));
return offset;
}
static int
dissect_disp_ShadowProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 103 "./asn1/disp/disp.cnf"
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, disp_ShadowProblem_vals, "ShadowProblem(%d)"));
return offset;
}
static int
dissect_disp_ShadowErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ShadowErrorData_sequence, hf_index, ett_disp_ShadowErrorData);
return offset;
}
static int
dissect_disp_T_signedShadowError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedShadowError_sequence, hf_index, ett_disp_T_signedShadowError);
return offset;
}
static int
dissect_disp_ShadowError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ShadowError_choice, hf_index, ett_disp_ShadowError,
NULL);
return offset;
}
static int dissect_EstablishParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_disp_EstablishParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_disp_EstablishParameter_PDU);
return offset;
}
static int dissect_ModificationParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_disp_ModificationParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_disp_ModificationParameter_PDU);
return offset;
}
static int dissect_ShadowingAgreementInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_disp_ShadowingAgreementInfo(FALSE, tvb, offset, &asn1_ctx, tree, hf_disp_ShadowingAgreementInfo_PDU);
return offset;
}
static int
dissect_disp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
int offset = 0;
int old_offset;
proto_item *item;
proto_tree *tree;
struct SESSION_DATA_STRUCTURE* session;
int (*disp_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) = NULL;
const char *disp_op_name;
asn1_ctx_t asn1_ctx;
if (data == NULL)
return 0;
session = (struct SESSION_DATA_STRUCTURE*)data;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
asn1_ctx.private_data = session;
item = proto_tree_add_item(parent_tree, proto_disp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_disp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DISP");
col_clear(pinfo->cinfo, COL_INFO);
switch(session->ros_op & ROS_OP_MASK) {
case (ROS_OP_BIND | ROS_OP_ARGUMENT):
disp_dissector = dissect_disp_DSAShadowBindArgument;
disp_op_name = "Shadow-Bind-Argument";
break;
case (ROS_OP_BIND | ROS_OP_RESULT):
disp_dissector = dissect_disp_DSAShadowBindResult;
disp_op_name = "Shadow-Bind-Result";
break;
case (ROS_OP_BIND | ROS_OP_ERROR):
disp_dissector = dissect_disp_DSAShadowBindError;
disp_op_name = "Shadow-Bind-Error";
break;
case (ROS_OP_INVOKE | ROS_OP_ARGUMENT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
disp_dissector = dissect_disp_RequestShadowUpdateArgument;
disp_op_name = "Request-Shadow-Update-Argument";
break;
case 2:
disp_dissector = dissect_disp_UpdateShadowArgument;
disp_op_name = "Update-Shadow-Argument";
break;
case 3:
disp_dissector = dissect_disp_CoordinateShadowUpdateArgument;
disp_op_name = "Coordinate-Shadow-Update-Argument";
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_disp_unsupported_opcode, tvb, offset, -1,
"Unsupported DISP opcode (%d)", session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_RESULT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
disp_dissector = dissect_disp_RequestShadowUpdateResult;
disp_op_name = "Request-Shadow-Result";
break;
case 2:
disp_dissector = dissect_disp_UpdateShadowResult;
disp_op_name = "Update-Shadow-Result";
break;
case 3:
disp_dissector = dissect_disp_CoordinateShadowUpdateResult;
disp_op_name = "Coordinate-Shadow-Update-Result";
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_disp_unsupported_opcode, tvb, offset, -1,
"Unsupported DISP opcode (%d)", session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_ERROR):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
disp_dissector = dissect_disp_ShadowError;
disp_op_name = "Shadow-Error";
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_disp_unsupported_errcode, tvb, offset, -1,
"Unsupported DISP errcode (%d)", session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_disp_unsupported_pdu, tvb, offset, -1);
return tvb_captured_length(tvb);
}
if(disp_dissector) {
col_set_str(pinfo->cinfo, COL_INFO, disp_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*disp_dissector)(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_expert(tree, pinfo, &ei_disp_zero_pdu, tvb, offset, -1);
break;
}
}
}
return tvb_captured_length(tvb);
}
void proto_register_disp(void) {
static hf_register_info hf[] =
{
#line 1 "./asn1/disp/packet-disp-hfarr.c"
{ &hf_disp_EstablishParameter_PDU,
{ "EstablishParameter", "disp.EstablishParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_ModificationParameter_PDU,
{ "ModificationParameter", "disp.ModificationParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_ShadowingAgreementInfo_PDU,
{ "ShadowingAgreementInfo", "disp.ShadowingAgreementInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_modifiedSecondaryShadows,
{ "secondaryShadows", "disp.secondaryShadows",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SupplierAndConsumers", HFILL }},
{ &hf_disp_modifiedSecondaryShadows_item,
{ "SupplierAndConsumers", "disp.SupplierAndConsumers_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_shadowSubject,
{ "shadowSubject", "disp.shadowSubject_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnitOfReplication", HFILL }},
{ &hf_disp_updateMode,
{ "updateMode", "disp.updateMode",
FT_UINT32, BASE_DEC, VALS(disp_UpdateMode_vals), 0,
NULL, HFILL }},
{ &hf_disp_master,
{ "master", "disp.master_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessPoint", HFILL }},
{ &hf_disp_secondaryShadows,
{ "secondaryShadows", "disp.secondaryShadows",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_area,
{ "area", "disp.area_element",
FT_NONE, BASE_NONE, NULL, 0,
"AreaSpecification", HFILL }},
{ &hf_disp_replication_attributes,
{ "attributes", "disp.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeSelection", HFILL }},
{ &hf_disp_knowledge,
{ "knowledge", "disp.knowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_subordinates,
{ "subordinates", "disp.subordinates",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_contextSelection,
{ "contextSelection", "disp.contextSelection",
FT_UINT32, BASE_DEC, VALS(dap_ContextSelection_vals), 0,
NULL, HFILL }},
{ &hf_disp_supplyContexts,
{ "supplyContexts", "disp.supplyContexts",
FT_UINT32, BASE_DEC, VALS(disp_T_supplyContexts_vals), 0,
NULL, HFILL }},
{ &hf_disp_allContexts,
{ "allContexts", "disp.allContexts_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_selectedContexts,
{ "selectedContexts", "disp.selectedContexts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_disp_selectedContexts_item,
{ "selectedContexts item", "disp.selectedContexts_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_disp_contextPrefix,
{ "contextPrefix", "disp.contextPrefix",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_disp_replicationArea,
{ "replicationArea", "disp.replicationArea_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubtreeSpecification", HFILL }},
{ &hf_disp_knowledgeType,
{ "knowledgeType", "disp.knowledgeType",
FT_UINT32, BASE_DEC, VALS(disp_T_knowledgeType_vals), 0,
NULL, HFILL }},
{ &hf_disp_extendedKnowledge,
{ "extendedKnowledge", "disp.extendedKnowledge",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_AttributeSelection_item,
{ "ClassAttributeSelection", "disp.ClassAttributeSelection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_class,
{ "class", "disp.class",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_disp_classAttributes,
{ "classAttributes", "disp.classAttributes",
FT_UINT32, BASE_DEC, VALS(disp_ClassAttributes_vals), 0,
NULL, HFILL }},
{ &hf_disp_allAttributes,
{ "allAttributes", "disp.allAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_include,
{ "include", "disp.include",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeTypes", HFILL }},
{ &hf_disp_exclude,
{ "exclude", "disp.exclude",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeTypes", HFILL }},
{ &hf_disp_AttributeTypes_item,
{ "AttributeType", "disp.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_supplierInitiated,
{ "supplierInitiated", "disp.supplierInitiated",
FT_UINT32, BASE_DEC, VALS(disp_SupplierUpdateMode_vals), 0,
"SupplierUpdateMode", HFILL }},
{ &hf_disp_consumerInitiated,
{ "consumerInitiated", "disp.consumerInitiated_element",
FT_NONE, BASE_NONE, NULL, 0,
"ConsumerUpdateMode", HFILL }},
{ &hf_disp_onChange,
{ "onChange", "disp.onChange",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_scheduled,
{ "scheduled", "disp.scheduled_element",
FT_NONE, BASE_NONE, NULL, 0,
"SchedulingParameters", HFILL }},
{ &hf_disp_periodic,
{ "periodic", "disp.periodic_element",
FT_NONE, BASE_NONE, NULL, 0,
"PeriodicStrategy", HFILL }},
{ &hf_disp_othertimes,
{ "othertimes", "disp.othertimes",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_beginTime,
{ "beginTime", "disp.beginTime",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_disp_windowSize,
{ "windowSize", "disp.windowSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_disp_updateInterval,
{ "updateInterval", "disp.updateInterval",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_disp_agreementID,
{ "agreementID", "disp.agreementID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_lastUpdate,
{ "lastUpdate", "disp.lastUpdate",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_disp_updateStrategy,
{ "updateStrategy", "disp.updateStrategy",
FT_UINT32, BASE_DEC, VALS(disp_T_updateStrategy_vals), 0,
NULL, HFILL }},
{ &hf_disp_standardUpdate,
{ "standard", "disp.standard",
FT_UINT32, BASE_DEC, VALS(disp_StandardUpdate_vals), 0,
"StandardUpdate", HFILL }},
{ &hf_disp_other,
{ "other", "disp.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_disp_securityParameters,
{ "securityParameters", "disp.securityParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_unsignedCoordinateShadowUpdateArgument,
{ "unsignedCoordinateShadowUpdateArgument", "disp.unsignedCoordinateShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"CoordinateShadowUpdateArgumentData", HFILL }},
{ &hf_disp_signedCoordinateShadowUpdateArgument,
{ "signedCoordinateShadowUpdateArgument", "disp.signedCoordinateShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_coordinateShadowUpdateArgument,
{ "coordinateShadowUpdateArgument", "disp.coordinateShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"CoordinateShadowUpdateArgumentData", HFILL }},
{ &hf_disp_algorithmIdentifier,
{ "algorithmIdentifier", "disp.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_encrypted,
{ "encrypted", "disp.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_disp_null,
{ "null", "disp.null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_information,
{ "information", "disp.information",
FT_UINT32, BASE_DEC, VALS(disp_Information_vals), 0,
NULL, HFILL }},
{ &hf_disp_performer,
{ "performer", "disp.performer",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_disp_aliasDereferenced,
{ "aliasDereferenced", "disp.aliasDereferenced",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_notification,
{ "notification", "disp.notification",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Attribute", HFILL }},
{ &hf_disp_notification_item,
{ "Attribute", "disp.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_unsignedInformation,
{ "unsignedInformation", "disp.unsignedInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"InformationData", HFILL }},
{ &hf_disp_signedInformation,
{ "signedInformation", "disp.signedInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_information_data,
{ "information", "disp.information_element",
FT_NONE, BASE_NONE, NULL, 0,
"InformationData", HFILL }},
{ &hf_disp_requestedStrategy,
{ "requestedStrategy", "disp.requestedStrategy",
FT_UINT32, BASE_DEC, VALS(disp_T_requestedStrategy_vals), 0,
NULL, HFILL }},
{ &hf_disp_standard,
{ "standard", "disp.standard",
FT_UINT32, BASE_DEC, VALS(disp_T_standard_vals), 0,
NULL, HFILL }},
{ &hf_disp_unsignedRequestShadowUpdateArgument,
{ "unsignedRequestShadowUpdateArgument", "disp.unsignedRequestShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestShadowUpdateArgumentData", HFILL }},
{ &hf_disp_signedRequestShadowUpdateArgument,
{ "signedRequestShadowUpdateArgument", "disp.signedRequestShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_requestShadowUpdateArgument,
{ "requestShadowUpdateArgument", "disp.requestShadowUpdateArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestShadowUpdateArgumentData", HFILL }},
{ &hf_disp_updateTime,
{ "updateTime", "disp.updateTime",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_disp_updateWindow,
{ "updateWindow", "disp.updateWindow_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_updatedInfo,
{ "updatedInfo", "disp.updatedInfo",
FT_UINT32, BASE_DEC, VALS(disp_RefreshInformation_vals), 0,
"RefreshInformation", HFILL }},
{ &hf_disp_unsignedUpdateShadowArgument,
{ "unsignedUpdateShadowArgument", "disp.unsignedUpdateShadowArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"UpdateShadowArgumentData", HFILL }},
{ &hf_disp_signedUpdateShadowArgument,
{ "signedUpdateShadowArgument", "disp.signedUpdateShadowArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_updateShadowArgument,
{ "updateShadowArgument", "disp.updateShadowArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"UpdateShadowArgumentData", HFILL }},
{ &hf_disp_start,
{ "start", "disp.start",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_disp_stop,
{ "stop", "disp.stop",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_disp_noRefresh,
{ "noRefresh", "disp.noRefresh_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_total,
{ "total", "disp.total_element",
FT_NONE, BASE_NONE, NULL, 0,
"TotalRefresh", HFILL }},
{ &hf_disp_incremental,
{ "incremental", "disp.incremental",
FT_UINT32, BASE_DEC, NULL, 0,
"IncrementalRefresh", HFILL }},
{ &hf_disp_otherStrategy,
{ "otherStrategy", "disp.otherStrategy_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_disp_sDSE,
{ "sDSE", "disp.sDSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"SDSEContent", HFILL }},
{ &hf_disp_subtree,
{ "subtree", "disp.subtree",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Subtree", HFILL }},
{ &hf_disp_subtree_item,
{ "Subtree", "disp.Subtree_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_sDSEType,
{ "sDSEType", "disp.sDSEType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_subComplete,
{ "subComplete", "disp.subComplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_attComplete,
{ "attComplete", "disp.attComplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_disp_attributes,
{ "attributes", "disp.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_disp_attributes_item,
{ "Attribute", "disp.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_attValIncomplete,
{ "attValIncomplete", "disp.attValIncomplete",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_disp_attValIncomplete_item,
{ "AttributeType", "disp.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_rdn,
{ "rdn", "disp.rdn",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_disp_IncrementalRefresh_item,
{ "IncrementalStepRefresh", "disp.IncrementalStepRefresh_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_sDSEChanges,
{ "sDSEChanges", "disp.sDSEChanges",
FT_UINT32, BASE_DEC, VALS(disp_T_sDSEChanges_vals), 0,
NULL, HFILL }},
{ &hf_disp_add,
{ "add", "disp.add_element",
FT_NONE, BASE_NONE, NULL, 0,
"SDSEContent", HFILL }},
{ &hf_disp_remove,
{ "remove", "disp.remove_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_modify,
{ "modify", "disp.modify_element",
FT_NONE, BASE_NONE, NULL, 0,
"ContentChange", HFILL }},
{ &hf_disp_subordinateUpdates,
{ "subordinateUpdates", "disp.subordinateUpdates",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SubordinateChanges", HFILL }},
{ &hf_disp_subordinateUpdates_item,
{ "SubordinateChanges", "disp.SubordinateChanges_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_rename,
{ "rename", "disp.rename",
FT_UINT32, BASE_DEC, VALS(disp_T_rename_vals), 0,
NULL, HFILL }},
{ &hf_disp_newRDN,
{ "newRDN", "disp.newRDN",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_disp_newDN,
{ "newDN", "disp.newDN",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_disp_attributeChanges,
{ "attributeChanges", "disp.attributeChanges",
FT_UINT32, BASE_DEC, VALS(disp_T_attributeChanges_vals), 0,
NULL, HFILL }},
{ &hf_disp_replace,
{ "replace", "disp.replace",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_disp_replace_item,
{ "Attribute", "disp.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_changes,
{ "changes", "disp.changes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EntryModification", HFILL }},
{ &hf_disp_changes_item,
{ "EntryModification", "disp.EntryModification",
FT_UINT32, BASE_DEC, VALS(dap_EntryModification_vals), 0,
NULL, HFILL }},
{ &hf_disp_subordinate,
{ "subordinate", "disp.subordinate",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_disp_subordinate_changes,
{ "changes", "disp.changes_element",
FT_NONE, BASE_NONE, NULL, 0,
"IncrementalStepRefresh", HFILL }},
{ &hf_disp_problem,
{ "problem", "disp.problem",
FT_INT32, BASE_DEC, VALS(disp_ShadowProblem_vals), 0,
"ShadowProblem", HFILL }},
{ &hf_disp_unsignedShadowError,
{ "unsignedShadowError", "disp.unsignedShadowError_element",
FT_NONE, BASE_NONE, NULL, 0,
"ShadowErrorData", HFILL }},
{ &hf_disp_signedShadowError,
{ "signedShadowError", "disp.signedShadowError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_disp_shadowError,
{ "shadowError", "disp.shadowError_element",
FT_NONE, BASE_NONE, NULL, 0,
"ShadowErrorData", HFILL }},
#line 204 "./asn1/disp/packet-disp-template.c"
};
static gint *ett[] = {
&ett_disp,
#line 1 "./asn1/disp/packet-disp-ettarr.c"
&ett_disp_ModificationParameter,
&ett_disp_SET_OF_SupplierAndConsumers,
&ett_disp_ShadowingAgreementInfo,
&ett_disp_UnitOfReplication,
&ett_disp_T_supplyContexts,
&ett_disp_T_selectedContexts,
&ett_disp_AreaSpecification,
&ett_disp_Knowledge,
&ett_disp_AttributeSelection,
&ett_disp_ClassAttributeSelection,
&ett_disp_ClassAttributes,
&ett_disp_AttributeTypes,
&ett_disp_UpdateMode,
&ett_disp_SupplierUpdateMode,
&ett_disp_SchedulingParameters,
&ett_disp_PeriodicStrategy,
&ett_disp_CoordinateShadowUpdateArgumentData,
&ett_disp_T_updateStrategy,
&ett_disp_CoordinateShadowUpdateArgument,
&ett_disp_T_signedCoordinateShadowUpdateArgument,
&ett_disp_CoordinateShadowUpdateResult,
&ett_disp_InformationData,
&ett_disp_SEQUENCE_OF_Attribute,
&ett_disp_Information,
&ett_disp_T_signedInformation,
&ett_disp_RequestShadowUpdateArgumentData,
&ett_disp_T_requestedStrategy,
&ett_disp_RequestShadowUpdateArgument,
&ett_disp_T_signedRequestShadowUpdateArgument,
&ett_disp_RequestShadowUpdateResult,
&ett_disp_UpdateShadowArgumentData,
&ett_disp_UpdateShadowArgument,
&ett_disp_T_signedUpdateShadowArgument,
&ett_disp_UpdateShadowResult,
&ett_disp_UpdateWindow,
&ett_disp_RefreshInformation,
&ett_disp_TotalRefresh,
&ett_disp_SET_OF_Subtree,
&ett_disp_SDSEContent,
&ett_disp_SET_OF_Attribute,
&ett_disp_SET_OF_AttributeType,
&ett_disp_Subtree,
&ett_disp_IncrementalRefresh,
&ett_disp_IncrementalStepRefresh,
&ett_disp_T_sDSEChanges,
&ett_disp_SEQUENCE_OF_SubordinateChanges,
&ett_disp_ContentChange,
&ett_disp_T_rename,
&ett_disp_T_attributeChanges,
&ett_disp_SEQUENCE_OF_EntryModification,
&ett_disp_SubordinateChanges,
&ett_disp_ShadowErrorData,
&ett_disp_ShadowError,
&ett_disp_T_signedShadowError,
#line 210 "./asn1/disp/packet-disp-template.c"
};
static ei_register_info ei[] = {
{ &ei_disp_unsupported_opcode, { "disp.unsupported_opcode", PI_UNDECODED, PI_WARN, "Unsupported DISP opcode", EXPFILL }},
{ &ei_disp_unsupported_errcode, { "disp.unsupported_errcode", PI_UNDECODED, PI_WARN, "Unsupported DISP errcode", EXPFILL }},
{ &ei_disp_unsupported_pdu, { "disp.unsupported_pdu", PI_UNDECODED, PI_WARN, "Unsupported DISP PDU", EXPFILL }},
{ &ei_disp_zero_pdu, { "disp.zero_pdu", PI_PROTOCOL, PI_ERROR, "Internal error, zero-byte DISP PDU", EXPFILL }},
};
module_t *disp_module;
expert_module_t* expert_disp;
proto_disp = proto_register_protocol(PNAME, PSNAME, PFNAME);
disp_handle = register_dissector("disp", dissect_disp, proto_disp);
proto_register_field_array(proto_disp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_disp = expert_register_protocol(proto_disp);
expert_register_field_array(expert_disp, ei, array_length(ei));
disp_module = prefs_register_protocol_subtree("OSI/X.500", proto_disp, prefs_register_disp);
prefs_register_uint_preference(disp_module, "tcp.port", "DISP TCP Port",
"Set the port for DISP operations (if other"
" than the default of 102)",
10, &global_disp_tcp_port);
}
void proto_reg_handoff_disp(void) {
#line 1 "./asn1/disp/packet-disp-dis-tab.c"
dissector_add_string("dop.oid", "agreement.2.5.19.1", create_dissector_handle(dissect_ShadowingAgreementInfo_PDU, proto_disp));
dissector_add_string("dop.oid", "establish.rolea.2.5.19.1", create_dissector_handle(dissect_EstablishParameter_PDU, proto_disp));
dissector_add_string("dop.oid", "establish.roleb.2.5.19.1", create_dissector_handle(dissect_EstablishParameter_PDU, proto_disp));
dissector_add_string("dop.oid", "modify.rolea.2.5.19.1", create_dissector_handle(dissect_ModificationParameter_PDU, proto_disp));
dissector_add_string("dop.oid", "modify.roleb.2.5.19.1", create_dissector_handle(dissect_ModificationParameter_PDU, proto_disp));
#line 247 "./asn1/disp/packet-disp-template.c"
oid_add_from_string("id-ac-shadow-consumer-initiated","2.5.3.4");
oid_add_from_string("id-ac-shadow-supplier-initiated","2.5.3.5");
oid_add_from_string("id-ac-reliable-shadow-consumer-initiated","2.5.3.6");
oid_add_from_string("id-ac-reliable-shadow-supplier-initiated","2.5.3.7");
register_ros_oid_dissector_handle("2.5.9.3", disp_handle, 0, "id-as-directory-shadow", FALSE);
register_rtse_oid_dissector_handle("2.5.9.5", disp_handle, 0, "id-as-directory-reliable-shadow", FALSE);
register_rtse_oid_dissector_handle("2.5.9.6", disp_handle, 0, "id-as-directory-reliable-binding", FALSE);
oid_add_from_string("id-op-binding-shadow","2.5.1.0.5.1");
tpkt_handle = find_dissector("tpkt");
x509if_register_fmt(hf_disp_contextPrefix, "cp=");
}
static void
prefs_register_disp(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_disp_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", global_disp_tcp_port, tpkt_handle);
}
