static void append_oid(packet_info *pinfo, const char *oid)
{
const char *name = NULL;
name = oid_resolved_from_string(oid);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name ? name : oid);
}
int
dissect_dop_DSEType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
DSEType_bits, hf_index, ett_dop_DSEType,
NULL);
return offset;
}
static int
dissect_dop_SET_OF_ProtocolInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ProtocolInformation_set_of, hf_index, ett_dop_SET_OF_ProtocolInformation);
return offset;
}
static int
dissect_dop_T_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 174 "../../asn1/dop/dop.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " id=%d", value);
return offset;
}
static int
dissect_dop_T_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 183 "../../asn1/dop/dop.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, ",%d", value);
return offset;
}
int
dissect_dop_OperationalBindingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OperationalBindingID_sequence, hf_index, ett_dop_OperationalBindingID);
return offset;
}
static int
dissect_dop_SupplierOrConsumer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SupplierOrConsumer_set, hf_index, ett_dop_SupplierOrConsumer);
return offset;
}
static int
dissect_dop_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_dop_SupplierInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SupplierInformation_set, hf_index, ett_dop_SupplierInformation);
return offset;
}
static int
dissect_dop_ConsumerInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dop_SupplierOrConsumer(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dop_SET_OF_AccessPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AccessPoint_set_of, hf_index, ett_dop_SET_OF_AccessPoint);
return offset;
}
int
dissect_dop_SupplierAndConsumers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SupplierAndConsumers_set, hf_index, ett_dop_SupplierAndConsumers);
return offset;
}
static int
dissect_dop_DSAOperationalManagementBindArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dop_DSAOperationalManagementBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dop_DSAOperationalManagementBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindError(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dop_BindingType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &binding_type);
#line 105 "../../asn1/dop/dop.cnf"
append_oid(actx->pinfo, binding_type);
return offset;
}
static int
dissect_dop_EstablishSymmetric(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 109 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.symmetric", tvb, offset, actx->pinfo, tree, "symmetric");
return offset;
}
static int
dissect_dop_EstablishRoleAInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 113 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.rolea", tvb, offset, actx->pinfo, tree, "roleA");
return offset;
}
static int
dissect_dop_EstablishRoleBInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 117 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.roleb", tvb, offset, actx->pinfo, tree, "roleB");
return offset;
}
static int
dissect_dop_EstablishArgumentInitiator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EstablishArgumentInitiator_choice, hf_index, ett_dop_EstablishArgumentInitiator,
NULL);
return offset;
}
static int
dissect_dop_T_agreement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 145 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("agreement", tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_dop_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dop_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dop_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dop_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_dop_Time,
NULL);
return offset;
}
static int
dissect_dop_T_validFrom(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_validFrom_choice, hf_index, ett_dop_T_validFrom,
NULL);
return offset;
}
static int
dissect_dop_T_validUntil(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_validUntil_choice, hf_index, ett_dop_T_validUntil,
NULL);
return offset;
}
static int
dissect_dop_Validity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Validity_sequence, hf_index, ett_dop_Validity);
return offset;
}
static int
dissect_dop_EstablishOperationalBindingArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EstablishOperationalBindingArgumentData_sequence, hf_index, ett_dop_EstablishOperationalBindingArgumentData);
return offset;
}
static int
dissect_dop_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_dop_T_signedEstablishOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedEstablishOperationalBindingArgument_sequence, hf_index, ett_dop_T_signedEstablishOperationalBindingArgument);
return offset;
}
static int
dissect_dop_EstablishOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EstablishOperationalBindingArgument_choice, hf_index, ett_dop_EstablishOperationalBindingArgument,
NULL);
return offset;
}
static int
dissect_dop_T_symmetric(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 149 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.symmetric", tvb, offset, actx->pinfo, tree, "symmetric");
return offset;
}
static int
dissect_dop_T_roleA_replies(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 153 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.rolea", tvb, offset, actx->pinfo, tree, "roleA");
return offset;
}
static int
dissect_dop_T_roleB_replies(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 157 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("establish.roleb", tvb, offset, actx->pinfo, tree, "roleB");
return offset;
}
static int
dissect_dop_T_initiator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_initiator_choice, hf_index, ett_dop_T_initiator,
NULL);
return offset;
}
static int
dissect_dop_SEQUENCE_SIZE_1_MAX_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_Attribute_sequence_of, hf_index, ett_dop_SEQUENCE_SIZE_1_MAX_OF_Attribute);
return offset;
}
static int
dissect_dop_EstablishOperationalBindingResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EstablishOperationalBindingResult_sequence, hf_index, ett_dop_EstablishOperationalBindingResult);
return offset;
}
static int
dissect_dop_ModifySymmetric(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 121 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("modify.symmetric", tvb, offset, actx->pinfo, tree, "symmetric");
return offset;
}
static int
dissect_dop_ModifyRoleAInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 125 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("modify.rolea", tvb, offset, actx->pinfo, tree, "roleA");
return offset;
}
static int
dissect_dop_ModifyRoleBInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 129 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("modify.roleb", tvb, offset, actx->pinfo, tree, "roleB");
return offset;
}
static int
dissect_dop_ModifyArgumentInitiator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyArgumentInitiator_choice, hf_index, ett_dop_ModifyArgumentInitiator,
NULL);
return offset;
}
static int
dissect_dop_ArgumentNewAgreement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 169 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("agreement", tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_dop_ModifyOperationalBindingArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyOperationalBindingArgumentData_sequence, hf_index, ett_dop_ModifyOperationalBindingArgumentData);
return offset;
}
static int
dissect_dop_T_signedModifyOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedModifyOperationalBindingArgument_sequence, hf_index, ett_dop_T_signedModifyOperationalBindingArgument);
return offset;
}
static int
dissect_dop_ModifyOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyOperationalBindingArgument_choice, hf_index, ett_dop_ModifyOperationalBindingArgument,
NULL);
return offset;
}
static int
dissect_dop_ResultNewAgreement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 165 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("agreement", tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_dop_ModifyOperationalBindingResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyOperationalBindingResultData_sequence, hf_index, ett_dop_ModifyOperationalBindingResultData);
return offset;
}
static int
dissect_dop_ProtectedModifyResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtectedModifyResult_sequence, hf_index, ett_dop_ProtectedModifyResult);
return offset;
}
static int
dissect_dop_ModifyOperationalBindingResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyOperationalBindingResult_choice, hf_index, ett_dop_ModifyOperationalBindingResult,
NULL);
return offset;
}
static int
dissect_dop_TerminateSymmetric(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 133 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("terminate.symmetric", tvb, offset, actx->pinfo, tree, "symmetric");
return offset;
}
static int
dissect_dop_TerminateRoleAInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 137 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("terminate.rolea", tvb, offset, actx->pinfo, tree, "roleA");
return offset;
}
static int
dissect_dop_TerminateRoleBInitiates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 141 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("terminate.roleb", tvb, offset, actx->pinfo, tree, "roleB");
return offset;
}
static int
dissect_dop_TerminateArgumentInitiator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TerminateArgumentInitiator_choice, hf_index, ett_dop_TerminateArgumentInitiator,
NULL);
return offset;
}
static int
dissect_dop_TerminateOperationalBindingArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminateOperationalBindingArgumentData_sequence, hf_index, ett_dop_TerminateOperationalBindingArgumentData);
return offset;
}
static int
dissect_dop_T_signedTerminateOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedTerminateOperationalBindingArgument_sequence, hf_index, ett_dop_T_signedTerminateOperationalBindingArgument);
return offset;
}
static int
dissect_dop_TerminateOperationalBindingArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TerminateOperationalBindingArgument_choice, hf_index, ett_dop_TerminateOperationalBindingArgument,
NULL);
return offset;
}
static int
dissect_dop_TerminateOperationalBindingResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminateOperationalBindingResultData_sequence, hf_index, ett_dop_TerminateOperationalBindingResultData);
return offset;
}
static int
dissect_dop_ProtectedTerminateResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtectedTerminateResult_sequence, hf_index, ett_dop_ProtectedTerminateResult);
return offset;
}
static int
dissect_dop_TerminateOperationalBindingResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TerminateOperationalBindingResult_choice, hf_index, ett_dop_TerminateOperationalBindingResult,
NULL);
return offset;
}
static int
dissect_dop_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dop_T_agreementProposal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 161 "../../asn1/dop/dop.cnf"
offset = call_dop_oid_callback("agreement", tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_dop_OpBindingErrorParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OpBindingErrorParam_sequence, hf_index, ett_dop_OpBindingErrorParam);
return offset;
}
static int
dissect_dop_HierarchicalAgreement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
HierarchicalAgreement_sequence, hf_index, ett_dop_HierarchicalAgreement);
return offset;
}
static int
dissect_dop_SET_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Attribute_set_of, hf_index, ett_dop_SET_OF_Attribute);
return offset;
}
static int
dissect_dop_SubentryInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubentryInfo_sequence, hf_index, ett_dop_SubentryInfo);
return offset;
}
static int
dissect_dop_SET_OF_SubentryInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SubentryInfo_set_of, hf_index, ett_dop_SET_OF_SubentryInfo);
return offset;
}
static int
dissect_dop_Vertex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Vertex_sequence, hf_index, ett_dop_Vertex);
return offset;
}
static int
dissect_dop_DITcontext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DITcontext_sequence_of, hf_index, ett_dop_DITcontext);
return offset;
}
static int
dissect_dop_SuperiorToSubordinate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SuperiorToSubordinate_sequence, hf_index, ett_dop_SuperiorToSubordinate);
return offset;
}
static int
dissect_dop_SubordinateToSuperior(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubordinateToSuperior_sequence, hf_index, ett_dop_SubordinateToSuperior);
return offset;
}
static int
dissect_dop_SuperiorToSubordinateModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SuperiorToSubordinateModification_sequence, hf_index, ett_dop_SuperiorToSubordinateModification);
return offset;
}
static int
dissect_dop_NonSpecificHierarchicalAgreement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NonSpecificHierarchicalAgreement_sequence, hf_index, ett_dop_NonSpecificHierarchicalAgreement);
return offset;
}
static int
dissect_dop_NHOBSuperiorToSubordinate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NHOBSuperiorToSubordinate_sequence, hf_index, ett_dop_NHOBSuperiorToSubordinate);
return offset;
}
static int
dissect_dop_NHOBSubordinateToSuperior(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NHOBSubordinateToSuperior_sequence, hf_index, ett_dop_NHOBSubordinateToSuperior);
return offset;
}
static int
dissect_dop_Precedence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 192 "../../asn1/dop/dop.cnf"
guint32 precedence = 0;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&precedence);
proto_item_append_text(tree, " precedence=%d", precedence);
return offset;
}
static int
dissect_dop_T_level(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dop_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dop_T_basicLevels(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_basicLevels_sequence, hf_index, ett_dop_T_basicLevels);
return offset;
}
static int
dissect_dop_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_dop_AuthenticationLevel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuthenticationLevel_choice, hf_index, ett_dop_AuthenticationLevel,
NULL);
return offset;
}
static int
dissect_dop_SET_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeType_set_of, hf_index, ett_dop_SET_OF_AttributeType);
return offset;
}
static int
dissect_dop_SET_OF_AttributeTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeTypeAndValue_set_of, hf_index, ett_dop_SET_OF_AttributeTypeAndValue);
return offset;
}
static int
dissect_dop_MaxValueCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MaxValueCount_sequence, hf_index, ett_dop_MaxValueCount);
return offset;
}
static int
dissect_dop_SET_OF_MaxValueCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_MaxValueCount_set_of, hf_index, ett_dop_SET_OF_MaxValueCount);
return offset;
}
static int
dissect_dop_RestrictedValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RestrictedValue_sequence, hf_index, ett_dop_RestrictedValue);
return offset;
}
static int
dissect_dop_SET_OF_RestrictedValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_RestrictedValue_set_of, hf_index, ett_dop_SET_OF_RestrictedValue);
return offset;
}
static int
dissect_dop_SET_OF_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ContextAssertion_set_of, hf_index, ett_dop_SET_OF_ContextAssertion);
return offset;
}
static int
dissect_dop_ProtectedItems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtectedItems_sequence, hf_index, ett_dop_ProtectedItems);
return offset;
}
static int
dissect_dop_SET_OF_NameAndOptionalUID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_NameAndOptionalUID_set_of, hf_index, ett_dop_SET_OF_NameAndOptionalUID);
return offset;
}
static int
dissect_dop_SET_OF_SubtreeSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SubtreeSpecification_set_of, hf_index, ett_dop_SET_OF_SubtreeSpecification);
return offset;
}
static int
dissect_dop_UserClasses(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserClasses_sequence, hf_index, ett_dop_UserClasses);
return offset;
}
static int
dissect_dop_GrantsAndDenials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
GrantsAndDenials_bits, hf_index, ett_dop_GrantsAndDenials,
NULL);
return offset;
}
static int
dissect_dop_ItemPermission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ItemPermission_sequence, hf_index, ett_dop_ItemPermission);
return offset;
}
static int
dissect_dop_SET_OF_ItemPermission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ItemPermission_set_of, hf_index, ett_dop_SET_OF_ItemPermission);
return offset;
}
static int
dissect_dop_T_itemFirst(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_itemFirst_sequence, hf_index, ett_dop_T_itemFirst);
return offset;
}
static int
dissect_dop_UserPermission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UserPermission_sequence, hf_index, ett_dop_UserPermission);
return offset;
}
static int
dissect_dop_SET_OF_UserPermission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_UserPermission_set_of, hf_index, ett_dop_SET_OF_UserPermission);
return offset;
}
static int
dissect_dop_T_userFirst(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_userFirst_sequence, hf_index, ett_dop_T_userFirst);
return offset;
}
static int
dissect_dop_T_itemOrUserFirst(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_itemOrUserFirst_choice, hf_index, ett_dop_T_itemOrUserFirst,
NULL);
return offset;
}
static int
dissect_dop_ACIItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ACIItem_sequence, hf_index, ett_dop_ACIItem);
return offset;
}
static void dissect_DSEType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_DSEType(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_DSEType_PDU);
}
static void dissect_SupplierInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_SupplierInformation(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_SupplierInformation_PDU);
}
static void dissect_ConsumerInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_ConsumerInformation(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_ConsumerInformation_PDU);
}
static void dissect_SupplierAndConsumers_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_SupplierAndConsumers(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_SupplierAndConsumers_PDU);
}
static void dissect_HierarchicalAgreement_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_HierarchicalAgreement(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_HierarchicalAgreement_PDU);
}
static void dissect_SuperiorToSubordinate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_SuperiorToSubordinate(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_SuperiorToSubordinate_PDU);
}
static void dissect_SubordinateToSuperior_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_SubordinateToSuperior(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_SubordinateToSuperior_PDU);
}
static void dissect_SuperiorToSubordinateModification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_SuperiorToSubordinateModification(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_SuperiorToSubordinateModification_PDU);
}
static void dissect_NonSpecificHierarchicalAgreement_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_NonSpecificHierarchicalAgreement(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_NonSpecificHierarchicalAgreement_PDU);
}
static void dissect_NHOBSuperiorToSubordinate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_NHOBSuperiorToSubordinate(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_NHOBSuperiorToSubordinate_PDU);
}
static void dissect_NHOBSubordinateToSuperior_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_NHOBSubordinateToSuperior(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_NHOBSubordinateToSuperior_PDU);
}
static void dissect_ACIItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dop_ACIItem(FALSE, tvb, 0, &asn1_ctx, tree, hf_dop_ACIItem_PDU);
}
static int
call_dop_oid_callback(const char *base_string, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, const char *col_info)
{
char* binding_param;
binding_param = wmem_strdup_printf(wmem_packet_scope(), "%s.%s", base_string, binding_type ? binding_type : "");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", col_info);
if (dissector_try_string(dop_dissector_table, binding_param, tvb, pinfo, tree)) {
offset = tvb_reported_length (tvb);
} else {
proto_item *item=NULL;
proto_tree *next_tree=NULL;
item = proto_tree_add_text(tree, tvb, 0, tvb_length_remaining(tvb, offset), "Dissector for parameter %s OID:%s not implemented. Contact Wireshark developers if you want this supported", base_string, binding_type ? binding_type : "<empty>");
if (item) {
next_tree = proto_item_add_subtree(item, ett_dop_unknown);
}
offset = dissect_unknown_ber(pinfo, tvb, offset, next_tree);
expert_add_info(pinfo, item, &ei_dop_unknown_binding_parameter);
}
return offset;
}
static void
dissect_dop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
int (*dop_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) = NULL;
const char *dop_op_name;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if( !pinfo->private_data ){
if(parent_tree){
proto_tree_add_text(parent_tree, tvb, offset, -1,
"Internal error: can't get operation information from ROS dissector.");
}
return ;
} else {
session = ( (struct SESSION_DATA_STRUCTURE*)(pinfo->private_data) );
}
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_dop, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dop);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DOP");
col_clear(pinfo->cinfo, COL_INFO);
switch(session->ros_op & ROS_OP_MASK) {
case (ROS_OP_BIND | ROS_OP_ARGUMENT):
dop_dissector = dissect_dop_DSAOperationalManagementBindArgument;
dop_op_name = "DSA-Operational-Bind-Argument";
break;
case (ROS_OP_BIND | ROS_OP_RESULT):
dop_dissector = dissect_dop_DSAOperationalManagementBindResult;
dop_op_name = "DSA-Operational-Bind-Result";
break;
case (ROS_OP_BIND | ROS_OP_ERROR):
dop_dissector = dissect_dop_DSAOperationalManagementBindError;
dop_op_name = "DSA-Operational-Management-Bind-Error";
break;
case (ROS_OP_INVOKE | ROS_OP_ARGUMENT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 100:
dop_dissector = dissect_dop_EstablishOperationalBindingArgument;
dop_op_name = "Establish-Operational-Binding-Argument";
break;
case 101:
dop_dissector = dissect_dop_TerminateOperationalBindingArgument;
dop_op_name = "Terminate-Operational-Binding-Argument";
break;
case 102:
dop_dissector = dissect_dop_ModifyOperationalBindingArgument;
dop_op_name = "Modify-Operational-Binding-Argument";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DOP Argument opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_RESULT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 100:
dop_dissector = dissect_dop_EstablishOperationalBindingResult;
dop_op_name = "Establish-Operational-Binding-Result";
break;
case 101:
dop_dissector = dissect_dop_TerminateOperationalBindingResult;
dop_op_name = "Terminate-Operational-Binding-Result";
break;
case 102:
dop_dissector = dissect_dop_ModifyOperationalBindingResult;
dop_op_name = "Modify-Operational-Binding-Result";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DOP Result opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_ERROR):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 100:
dop_dissector = dissect_dop_OpBindingErrorParam;
dop_op_name = "Operational-Binding-Error";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DOP Error opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DOP PDU");
return;
}
if(dop_dissector) {
col_set_str(pinfo->cinfo, COL_INFO, dop_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*dop_dissector)(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte DOP PDU");
break;
}
}
}
}
void proto_register_dop(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/dop/packet-dop-hfarr.c"
{ &hf_dop_DSEType_PDU,
{ "DSEType", "dop.DSEType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_SupplierInformation_PDU,
{ "SupplierInformation", "dop.SupplierInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_ConsumerInformation_PDU,
{ "ConsumerInformation", "dop.ConsumerInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_SupplierAndConsumers_PDU,
{ "SupplierAndConsumers", "dop.SupplierAndConsumers_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_HierarchicalAgreement_PDU,
{ "HierarchicalAgreement", "dop.HierarchicalAgreement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_SuperiorToSubordinate_PDU,
{ "SuperiorToSubordinate", "dop.SuperiorToSubordinate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_SubordinateToSuperior_PDU,
{ "SubordinateToSuperior", "dop.SubordinateToSuperior_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_SuperiorToSubordinateModification_PDU,
{ "SuperiorToSubordinateModification", "dop.SuperiorToSubordinateModification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_NonSpecificHierarchicalAgreement_PDU,
{ "NonSpecificHierarchicalAgreement", "dop.NonSpecificHierarchicalAgreement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_NHOBSuperiorToSubordinate_PDU,
{ "NHOBSuperiorToSubordinate", "dop.NHOBSuperiorToSubordinate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_NHOBSubordinateToSuperior_PDU,
{ "NHOBSubordinateToSuperior", "dop.NHOBSubordinateToSuperior_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_ACIItem_PDU,
{ "ACIItem", "dop.ACIItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_ae_title,
{ "ae-title", "dop.ae_title",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dop_address,
{ "address", "dop.address_element",
FT_NONE, BASE_NONE, NULL, 0,
"PresentationAddress", HFILL }},
{ &hf_dop_protocolInformation,
{ "protocolInformation", "dop.protocolInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ProtocolInformation", HFILL }},
{ &hf_dop_protocolInformation_item,
{ "ProtocolInformation", "dop.ProtocolInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_agreementID,
{ "agreementID", "dop.agreementID_element",
FT_NONE, BASE_NONE, NULL, 0,
"OperationalBindingID", HFILL }},
{ &hf_dop_supplier_is_master,
{ "supplier-is-master", "dop.supplier_is_master",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dop_non_supplying_master,
{ "non-supplying-master", "dop.non_supplying_master_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessPoint", HFILL }},
{ &hf_dop_consumers,
{ "consumers", "dop.consumers",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AccessPoint", HFILL }},
{ &hf_dop_consumers_item,
{ "AccessPoint", "dop.AccessPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_bindingType,
{ "bindingType", "dop.bindingType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_bindingID,
{ "bindingID", "dop.bindingID_element",
FT_NONE, BASE_NONE, NULL, 0,
"OperationalBindingID", HFILL }},
{ &hf_dop_accessPoint,
{ "accessPoint", "dop.accessPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_establishInitiator,
{ "initiator", "dop.initiator",
FT_UINT32, BASE_DEC, VALS(dop_EstablishArgumentInitiator_vals), 0,
"EstablishArgumentInitiator", HFILL }},
{ &hf_dop_establishSymmetric,
{ "symmetric", "dop.symmetric_element",
FT_NONE, BASE_NONE, NULL, 0,
"EstablishSymmetric", HFILL }},
{ &hf_dop_establishRoleAInitiates,
{ "roleA-initiates", "dop.roleA_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"EstablishRoleAInitiates", HFILL }},
{ &hf_dop_establishRoleBInitiates,
{ "roleB-initiates", "dop.roleB_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"EstablishRoleBInitiates", HFILL }},
{ &hf_dop_agreement,
{ "agreement", "dop.agreement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_valid,
{ "valid", "dop.valid_element",
FT_NONE, BASE_NONE, NULL, 0,
"Validity", HFILL }},
{ &hf_dop_securityParameters,
{ "securityParameters", "dop.securityParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_unsignedEstablishOperationalBindingArgument,
{ "unsignedEstablishOperationalBindingArgument", "dop.unsignedEstablishOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"EstablishOperationalBindingArgumentData", HFILL }},
{ &hf_dop_signedEstablishOperationalBindingArgument,
{ "signedEstablishOperationalBindingArgument", "dop.signedEstablishOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_establishOperationalBindingArgument,
{ "establishOperationalBindingArgument", "dop.establishOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"EstablishOperationalBindingArgumentData", HFILL }},
{ &hf_dop_algorithmIdentifier,
{ "algorithmIdentifier", "dop.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_encrypted,
{ "encrypted", "dop.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dop_identifier,
{ "identifier", "dop.identifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dop_version,
{ "version", "dop.version",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dop_validFrom,
{ "validFrom", "dop.validFrom",
FT_UINT32, BASE_DEC, VALS(dop_T_validFrom_vals), 0,
NULL, HFILL }},
{ &hf_dop_now,
{ "now", "dop.now_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_time,
{ "time", "dop.time",
FT_UINT32, BASE_DEC, VALS(dop_Time_vals), 0,
NULL, HFILL }},
{ &hf_dop_validUntil,
{ "validUntil", "dop.validUntil",
FT_UINT32, BASE_DEC, VALS(dop_T_validUntil_vals), 0,
NULL, HFILL }},
{ &hf_dop_explicitTermination,
{ "explicitTermination", "dop.explicitTermination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_utcTime,
{ "utcTime", "dop.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_generalizedTime,
{ "generalizedTime", "dop.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_initiator,
{ "initiator", "dop.initiator",
FT_UINT32, BASE_DEC, VALS(dop_T_initiator_vals), 0,
NULL, HFILL }},
{ &hf_dop_symmetric,
{ "symmetric", "dop.symmetric_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_roleA_replies,
{ "roleA-replies", "dop.roleA_replies_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_roleB_replies,
{ "roleB-replies", "dop.roleB_replies_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_performer,
{ "performer", "dop.performer",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dop_aliasDereferenced,
{ "aliasDereferenced", "dop.aliasDereferenced",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dop_notification,
{ "notification", "dop.notification",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_Attribute", HFILL }},
{ &hf_dop_notification_item,
{ "Attribute", "dop.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_modifyInitiator,
{ "initiator", "dop.initiator",
FT_UINT32, BASE_DEC, VALS(dop_ModifyArgumentInitiator_vals), 0,
"ModifyArgumentInitiator", HFILL }},
{ &hf_dop_modifySymmetric,
{ "symmetric", "dop.symmetric_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifySymmetric", HFILL }},
{ &hf_dop_modifyRoleAInitiates,
{ "roleA-initiates", "dop.roleA_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyRoleAInitiates", HFILL }},
{ &hf_dop_modifyRoleBInitiates,
{ "roleB-initiates", "dop.roleB_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyRoleBInitiates", HFILL }},
{ &hf_dop_newBindingID,
{ "newBindingID", "dop.newBindingID_element",
FT_NONE, BASE_NONE, NULL, 0,
"OperationalBindingID", HFILL }},
{ &hf_dop_argumentNewAgreement,
{ "newAgreement", "dop.newAgreement_element",
FT_NONE, BASE_NONE, NULL, 0,
"ArgumentNewAgreement", HFILL }},
{ &hf_dop_unsignedModifyOperationalBindingArgument,
{ "unsignedModifyOperationalBindingArgument", "dop.unsignedModifyOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyOperationalBindingArgumentData", HFILL }},
{ &hf_dop_signedModifyOperationalBindingArgument,
{ "signedModifyOperationalBindingArgument", "dop.signedModifyOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_modifyOperationalBindingArgument,
{ "modifyOperationalBindingArgument", "dop.modifyOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyOperationalBindingArgumentData", HFILL }},
{ &hf_dop_null,
{ "null", "dop.null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_protectedModifyResult,
{ "protected", "dop.protected_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedModifyResult", HFILL }},
{ &hf_dop_modifyOperationalBindingResultData,
{ "modifyOperationalBindingResultData", "dop.modifyOperationalBindingResultData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_resultNewAgreement,
{ "newAgreement", "dop.newAgreement_element",
FT_NONE, BASE_NONE, NULL, 0,
"ResultNewAgreement", HFILL }},
{ &hf_dop_terminateInitiator,
{ "initiator", "dop.initiator",
FT_UINT32, BASE_DEC, VALS(dop_TerminateArgumentInitiator_vals), 0,
"TerminateArgumentInitiator", HFILL }},
{ &hf_dop_terminateSymmetric,
{ "symmetric", "dop.symmetric_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateSymmetric", HFILL }},
{ &hf_dop_terminateRoleAInitiates,
{ "roleA-initiates", "dop.roleA_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateRoleAInitiates", HFILL }},
{ &hf_dop_terminateRoleBInitiates,
{ "roleB-initiates", "dop.roleB_initiates_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateRoleBInitiates", HFILL }},
{ &hf_dop_terminateAtTime,
{ "terminateAt", "dop.terminateAt",
FT_UINT32, BASE_DEC, VALS(dop_Time_vals), 0,
"Time", HFILL }},
{ &hf_dop_unsignedTerminateOperationalBindingArgument,
{ "unsignedTerminateOperationalBindingArgument", "dop.unsignedTerminateOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateOperationalBindingArgumentData", HFILL }},
{ &hf_dop_signedTerminateOperationalBindingArgument,
{ "signedTerminateOperationalBindingArgument", "dop.signedTerminateOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_terminateOperationalBindingArgument,
{ "terminateOperationalBindingArgument", "dop.terminateOperationalBindingArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateOperationalBindingArgumentData", HFILL }},
{ &hf_dop_protectedTerminateResult,
{ "protected", "dop.protected_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedTerminateResult", HFILL }},
{ &hf_dop_terminateOperationalBindingResultData,
{ "terminateOperationalBindingResultData", "dop.terminateOperationalBindingResultData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_terminateAtGeneralizedTime,
{ "terminateAt", "dop.terminateAt",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_dop_problem,
{ "problem", "dop.problem",
FT_UINT32, BASE_DEC, VALS(dop_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_dop_agreementProposal,
{ "agreementProposal", "dop.agreementProposal_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_retryAt,
{ "retryAt", "dop.retryAt",
FT_UINT32, BASE_DEC, VALS(dop_Time_vals), 0,
"Time", HFILL }},
{ &hf_dop_rdn,
{ "rdn", "dop.rdn",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_dop_immediateSuperior,
{ "immediateSuperior", "dop.immediateSuperior",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dop_contextPrefixInfo,
{ "contextPrefixInfo", "dop.contextPrefixInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"DITcontext", HFILL }},
{ &hf_dop_entryInfo,
{ "entryInfo", "dop.entryInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_dop_entryInfo_item,
{ "Attribute", "dop.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_immediateSuperiorInfo,
{ "immediateSuperiorInfo", "dop.immediateSuperiorInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_dop_immediateSuperiorInfo_item,
{ "Attribute", "dop.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_DITcontext_item,
{ "Vertex", "dop.Vertex_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_admPointInfo,
{ "admPointInfo", "dop.admPointInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_dop_admPointInfo_item,
{ "Attribute", "dop.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_subentries,
{ "subentries", "dop.subentries",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SubentryInfo", HFILL }},
{ &hf_dop_subentries_item,
{ "SubentryInfo", "dop.SubentryInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_accessPoints,
{ "accessPoints", "dop.accessPoints",
FT_UINT32, BASE_DEC, NULL, 0,
"MasterAndShadowAccessPoints", HFILL }},
{ &hf_dop_info,
{ "info", "dop.info",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_dop_info_item,
{ "Attribute", "dop.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_alias,
{ "alias", "dop.alias",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dop_identificationTag,
{ "identificationTag", "dop.identificationTag",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_dop_precedence,
{ "precedence", "dop.precedence",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dop_authenticationLevel,
{ "authenticationLevel", "dop.authenticationLevel",
FT_UINT32, BASE_DEC, VALS(dop_AuthenticationLevel_vals), 0,
NULL, HFILL }},
{ &hf_dop_itemOrUserFirst,
{ "itemOrUserFirst", "dop.itemOrUserFirst",
FT_UINT32, BASE_DEC, VALS(dop_T_itemOrUserFirst_vals), 0,
NULL, HFILL }},
{ &hf_dop_itemFirst,
{ "itemFirst", "dop.itemFirst_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_protectedItems,
{ "protectedItems", "dop.protectedItems_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_itemPermissions,
{ "itemPermissions", "dop.itemPermissions",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ItemPermission", HFILL }},
{ &hf_dop_itemPermissions_item,
{ "ItemPermission", "dop.ItemPermission_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_userFirst,
{ "userFirst", "dop.userFirst_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_userClasses,
{ "userClasses", "dop.userClasses_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_userPermissions,
{ "userPermissions", "dop.userPermissions",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_UserPermission", HFILL }},
{ &hf_dop_userPermissions_item,
{ "UserPermission", "dop.UserPermission_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_entry,
{ "entry", "dop.entry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_allUserAttributeTypes,
{ "allUserAttributeTypes", "dop.allUserAttributeTypes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_attributeType,
{ "attributeType", "dop.attributeType",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_dop_attributeType_item,
{ "AttributeType", "dop.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_allAttributeValues,
{ "allAttributeValues", "dop.allAttributeValues",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_dop_allAttributeValues_item,
{ "AttributeType", "dop.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_allUserAttributeTypesAndValues,
{ "allUserAttributeTypesAndValues", "dop.allUserAttributeTypesAndValues_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_attributeValue,
{ "attributeValue", "dop.attributeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeTypeAndValue", HFILL }},
{ &hf_dop_attributeValue_item,
{ "AttributeTypeAndValue", "dop.AttributeTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_selfValue,
{ "selfValue", "dop.selfValue",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_dop_selfValue_item,
{ "AttributeType", "dop.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_rangeOfValues,
{ "rangeOfValues", "dop.rangeOfValues",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_dop_maxValueCount,
{ "maxValueCount", "dop.maxValueCount",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_MaxValueCount", HFILL }},
{ &hf_dop_maxValueCount_item,
{ "MaxValueCount", "dop.MaxValueCount_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_maxImmSub,
{ "maxImmSub", "dop.maxImmSub",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dop_restrictedBy,
{ "restrictedBy", "dop.restrictedBy",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_RestrictedValue", HFILL }},
{ &hf_dop_restrictedBy_item,
{ "RestrictedValue", "dop.RestrictedValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_contexts,
{ "contexts", "dop.contexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ContextAssertion", HFILL }},
{ &hf_dop_contexts_item,
{ "ContextAssertion", "dop.ContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_classes,
{ "classes", "dop.classes",
FT_UINT32, BASE_DEC, VALS(x509if_Refinement_vals), 0,
"Refinement", HFILL }},
{ &hf_dop_type,
{ "type", "dop.type",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dop_maxCount,
{ "maxCount", "dop.maxCount",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dop_valuesIn,
{ "valuesIn", "dop.valuesIn",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dop_allUsers,
{ "allUsers", "dop.allUsers_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_thisEntry,
{ "thisEntry", "dop.thisEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_name,
{ "name", "dop.name",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_NameAndOptionalUID", HFILL }},
{ &hf_dop_name_item,
{ "NameAndOptionalUID", "dop.NameAndOptionalUID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_userGroup,
{ "userGroup", "dop.userGroup",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_NameAndOptionalUID", HFILL }},
{ &hf_dop_userGroup_item,
{ "NameAndOptionalUID", "dop.NameAndOptionalUID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_subtree,
{ "subtree", "dop.subtree",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SubtreeSpecification", HFILL }},
{ &hf_dop_subtree_item,
{ "SubtreeSpecification", "dop.SubtreeSpecification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_grantsAndDenials,
{ "grantsAndDenials", "dop.grantsAndDenials",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_basicLevels,
{ "basicLevels", "dop.basicLevels_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dop_level,
{ "level", "dop.level",
FT_UINT32, BASE_DEC, VALS(dop_T_level_vals), 0,
NULL, HFILL }},
{ &hf_dop_localQualifier,
{ "localQualifier", "dop.localQualifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dop_signed,
{ "signed", "dop.signed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dop_other,
{ "other", "dop.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_dop_DSEType_root,
{ "root", "dop.root",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_DSEType_glue,
{ "glue", "dop.glue",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_DSEType_cp,
{ "cp", "dop.cp",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_DSEType_entry,
{ "entry", "dop.entry",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_DSEType_alias,
{ "alias", "dop.alias",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dop_DSEType_subr,
{ "subr", "dop.subr",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dop_DSEType_nssr,
{ "nssr", "dop.nssr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dop_DSEType_supr,
{ "supr", "dop.supr",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dop_DSEType_xr,
{ "xr", "dop.xr",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_DSEType_admPoint,
{ "admPoint", "dop.admPoint",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_DSEType_subentry,
{ "subentry", "dop.subentry",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_DSEType_shadow,
{ "shadow", "dop.shadow",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_DSEType_immSupr,
{ "immSupr", "dop.immSupr",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dop_DSEType_rhob,
{ "rhob", "dop.rhob",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dop_DSEType_sa,
{ "sa", "dop.sa",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dop_DSEType_dsSubentry,
{ "dsSubentry", "dop.dsSubentry",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_DSEType_familyMember,
{ "familyMember", "dop.familyMember",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_DSEType_ditBridge,
{ "ditBridge", "dop.ditBridge",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_DSEType_writeableCopy,
{ "writeableCopy", "dop.writeableCopy",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantAdd,
{ "grantAdd", "dop.grantAdd",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyAdd,
{ "denyAdd", "dop.denyAdd",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantDiscloseOnError,
{ "grantDiscloseOnError", "dop.grantDiscloseOnError",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyDiscloseOnError,
{ "denyDiscloseOnError", "dop.denyDiscloseOnError",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantRead,
{ "grantRead", "dop.grantRead",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyRead,
{ "denyRead", "dop.denyRead",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantRemove,
{ "grantRemove", "dop.grantRemove",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyRemove,
{ "denyRemove", "dop.denyRemove",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantBrowse,
{ "grantBrowse", "dop.grantBrowse",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyBrowse,
{ "denyBrowse", "dop.denyBrowse",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantExport,
{ "grantExport", "dop.grantExport",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyExport,
{ "denyExport", "dop.denyExport",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantImport,
{ "grantImport", "dop.grantImport",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyImport,
{ "denyImport", "dop.denyImport",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantModify,
{ "grantModify", "dop.grantModify",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyModify,
{ "denyModify", "dop.denyModify",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantRename,
{ "grantRename", "dop.grantRename",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyRename,
{ "denyRename", "dop.denyRename",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantReturnDN,
{ "grantReturnDN", "dop.grantReturnDN",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyReturnDN,
{ "denyReturnDN", "dop.denyReturnDN",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantCompare,
{ "grantCompare", "dop.grantCompare",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyCompare,
{ "denyCompare", "dop.denyCompare",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantFilterMatch,
{ "grantFilterMatch", "dop.grantFilterMatch",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyFilterMatch,
{ "denyFilterMatch", "dop.denyFilterMatch",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_grantInvoke,
{ "grantInvoke", "dop.grantInvoke",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dop_GrantsAndDenials_denyInvoke,
{ "denyInvoke", "dop.denyInvoke",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 242 "../../asn1/dop/packet-dop-template.c"
};
static gint *ett[] = {
&ett_dop,
&ett_dop_unknown,
#line 1 "../../asn1/dop/packet-dop-ettarr.c"
&ett_dop_DSEType,
&ett_dop_SupplierOrConsumer,
&ett_dop_SET_OF_ProtocolInformation,
&ett_dop_SupplierInformation,
&ett_dop_SupplierAndConsumers,
&ett_dop_SET_OF_AccessPoint,
&ett_dop_EstablishOperationalBindingArgumentData,
&ett_dop_EstablishArgumentInitiator,
&ett_dop_EstablishOperationalBindingArgument,
&ett_dop_T_signedEstablishOperationalBindingArgument,
&ett_dop_OperationalBindingID,
&ett_dop_Validity,
&ett_dop_T_validFrom,
&ett_dop_T_validUntil,
&ett_dop_Time,
&ett_dop_EstablishOperationalBindingResult,
&ett_dop_T_initiator,
&ett_dop_SEQUENCE_SIZE_1_MAX_OF_Attribute,
&ett_dop_ModifyOperationalBindingArgumentData,
&ett_dop_ModifyArgumentInitiator,
&ett_dop_ModifyOperationalBindingArgument,
&ett_dop_T_signedModifyOperationalBindingArgument,
&ett_dop_ModifyOperationalBindingResult,
&ett_dop_ProtectedModifyResult,
&ett_dop_ModifyOperationalBindingResultData,
&ett_dop_TerminateOperationalBindingArgumentData,
&ett_dop_TerminateArgumentInitiator,
&ett_dop_TerminateOperationalBindingArgument,
&ett_dop_T_signedTerminateOperationalBindingArgument,
&ett_dop_TerminateOperationalBindingResult,
&ett_dop_ProtectedTerminateResult,
&ett_dop_TerminateOperationalBindingResultData,
&ett_dop_OpBindingErrorParam,
&ett_dop_HierarchicalAgreement,
&ett_dop_SuperiorToSubordinate,
&ett_dop_SET_OF_Attribute,
&ett_dop_DITcontext,
&ett_dop_Vertex,
&ett_dop_SET_OF_SubentryInfo,
&ett_dop_SubentryInfo,
&ett_dop_SubordinateToSuperior,
&ett_dop_SuperiorToSubordinateModification,
&ett_dop_NonSpecificHierarchicalAgreement,
&ett_dop_NHOBSuperiorToSubordinate,
&ett_dop_NHOBSubordinateToSuperior,
&ett_dop_ACIItem,
&ett_dop_T_itemOrUserFirst,
&ett_dop_T_itemFirst,
&ett_dop_SET_OF_ItemPermission,
&ett_dop_T_userFirst,
&ett_dop_SET_OF_UserPermission,
&ett_dop_ProtectedItems,
&ett_dop_SET_OF_AttributeType,
&ett_dop_SET_OF_AttributeTypeAndValue,
&ett_dop_SET_OF_MaxValueCount,
&ett_dop_SET_OF_RestrictedValue,
&ett_dop_SET_OF_ContextAssertion,
&ett_dop_MaxValueCount,
&ett_dop_RestrictedValue,
&ett_dop_UserClasses,
&ett_dop_SET_OF_NameAndOptionalUID,
&ett_dop_SET_OF_SubtreeSpecification,
&ett_dop_ItemPermission,
&ett_dop_UserPermission,
&ett_dop_AuthenticationLevel,
&ett_dop_T_basicLevels,
&ett_dop_GrantsAndDenials,
#line 249 "../../asn1/dop/packet-dop-template.c"
};
static ei_register_info ei[] = {
{ &ei_dop_unknown_binding_parameter, { "dop.unknown_binding_parameter", PI_UNDECODED, PI_WARN, "Unknown binding-parameter", EXPFILL }},
};
expert_module_t* expert_dop;
module_t *dop_module;
proto_dop = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("dop", dissect_dop, proto_dop);
dop_dissector_table = register_dissector_table("dop.oid", "DOP OID Dissectors", FT_STRING, BASE_NONE);
proto_register_field_array(proto_dop, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dop = expert_register_protocol(proto_dop);
expert_register_field_array(expert_dop, ei, array_length(ei));
dop_module = prefs_register_protocol_subtree("OSI/X.500", proto_dop, prefs_register_dop);
prefs_register_uint_preference(dop_module, "tcp.port", "DOP TCP Port",
"Set the port for DOP operations (if other"
" than the default of 102)",
10, &global_dop_tcp_port);
}
void proto_reg_handoff_dop(void) {
dissector_handle_t dop_handle;
#line 1 "../../asn1/dop/packet-dop-dis-tab.c"
register_ber_oid_dissector("2.5.12.0", dissect_DSEType_PDU, proto_dop, "id-doa-dseType");
register_ber_oid_dissector("2.5.12.5", dissect_SupplierInformation_PDU, proto_dop, "id-doa-supplierKnowledge");
register_ber_oid_dissector("2.5.12.6", dissect_ConsumerInformation_PDU, proto_dop, "id-doa-consumerKnowledge");
register_ber_oid_dissector("2.5.12.7", dissect_SupplierAndConsumers_PDU, proto_dop, "id-doa-secondaryShadows");
dissector_add_string("dop.oid", "agreement.2.5.19.2", create_dissector_handle(dissect_HierarchicalAgreement_PDU, proto_dop));
dissector_add_string("dop.oid", "establish.rolea.2.5.19.2", create_dissector_handle(dissect_SuperiorToSubordinate_PDU, proto_dop));
dissector_add_string("dop.oid", "modify.rolea.2.5.19.2", create_dissector_handle(dissect_SuperiorToSubordinateModification_PDU, proto_dop));
dissector_add_string("dop.oid", "establish.roleb.2.5.19.2", create_dissector_handle(dissect_SubordinateToSuperior_PDU, proto_dop));
dissector_add_string("dop.oid", "modify.roleb.2.5.19.2", create_dissector_handle(dissect_SubordinateToSuperior_PDU, proto_dop));
dissector_add_string("dop.oid", "agreement.2.5.19.3", create_dissector_handle(dissect_NonSpecificHierarchicalAgreement_PDU, proto_dop));
dissector_add_string("dop.oid", "establish.rolea.2.5.19.3", create_dissector_handle(dissect_NHOBSuperiorToSubordinate_PDU, proto_dop));
dissector_add_string("dop.oid", "modify.rolea.2.5.19.3", create_dissector_handle(dissect_NHOBSuperiorToSubordinate_PDU, proto_dop));
dissector_add_string("dop.oid", "establish.roleb.2.5.19.3", create_dissector_handle(dissect_NHOBSubordinateToSuperior_PDU, proto_dop));
dissector_add_string("dop.oid", "modify.roleb.2.5.19.3", create_dissector_handle(dissect_NHOBSubordinateToSuperior_PDU, proto_dop));
register_ber_oid_dissector("2.5.24.4", dissect_ACIItem_PDU, proto_dop, "id-aca-prescriptiveACI");
register_ber_oid_dissector("2.5.24.5", dissect_ACIItem_PDU, proto_dop, "id-aca-entryACI");
register_ber_oid_dissector("2.5.24.6", dissect_ACIItem_PDU, proto_dop, "id-aca-subentryACI");
#line 289 "../../asn1/dop/packet-dop-template.c"
oid_add_from_string("id-ac-directory-operational-binding-management","2.5.3.3");
dop_handle = find_dissector("dop");
register_ros_oid_dissector_handle("2.5.9.4", dop_handle, 0, "id-as-directory-operational-binding-management", FALSE);
oid_add_from_string("shadow-agreement","2.5.19.1");
oid_add_from_string("hierarchical-agreement","2.5.19.2");
oid_add_from_string("non-specific-hierarchical-agreement","2.5.19.3");
oid_add_from_string("basic-ACS","2.5.28.1");
oid_add_from_string("simplified-ACS","2.5.28.2");
oid_add_from_string("ruleBased-ACS","2.5.28.3");
oid_add_from_string("ruleAndBasic-ACS","2.5.28.4");
oid_add_from_string("ruleAndSimple-ACS","2.5.28.5");
oid_add_from_string("id-ar-autonomousArea","2.5.23.1");
oid_add_from_string("id-ar-accessControlSpecificArea","2.5.23.2");
oid_add_from_string("id-ar-accessControlInnerArea","2.5.23.3");
oid_add_from_string("id-ar-subschemaAdminSpecificArea","2.5.23.4");
oid_add_from_string("id-ar-collectiveAttributeSpecificArea","2.5.23.5");
oid_add_from_string("id-ar-collectiveAttributeInnerArea","2.5.23.6");
oid_add_from_string("id-ar-contextDefaultSpecificArea","2.5.23.7");
oid_add_from_string("id-ar-serviceSpecificArea","2.5.23.8");
tpkt_handle = find_dissector("tpkt");
}
static void
prefs_register_dop(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_dop_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", tcp_port, tpkt_handle);
}
